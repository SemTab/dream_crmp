#include <jni.h>
#include <android/log.h>
#include <ucontext.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/mman.h>
#include <assert.h>
#include <dlfcn.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "main.h"
#include "game/game.h"
#include "game/RW/RenderWare.h"
#include "net/netgame.h"
#include "gui/gui.h"
#include "CChatWindow.h"
#include "playertags.h"
#include "CDialog.h"
#include "CKeyboard.h"
#include "CSettings.h"
#include "CClientInfo.h"
#include "scoreboard.h"

#include "util/armhook.h"
#include <CrashHandler.h>

#include "CCheckFileHash.h"
#include "str_obfuscator_no_template.hpp"

#include "voice/CVoiceChatClient.h"
#include "util/crashlytics.h"

uintptr_t g_libGTASA = 0;
const char* g_pszStorage = nullptr;

#include "CServerManager.h"
#include "CLocalisation.h"
#include "CAudioStream.h"

const cryptor::string_encryptor encLib = cryptor::create("libsamp.so", 11);
void CrashLog(const char* fmt, ...);
CGame *pGame = nullptr;
CNetGame *pNetGame = nullptr;
CChatWindow *pChatWindow = nullptr; 
CPlayerTags *pPlayerTags = nullptr;
CDialogWindow *pDialogWindow = nullptr;
CVoiceChatClient* pVoice = nullptr;
CSnapShotHelper* pSnapShotHelper = nullptr;
CScoreBoard* pScoreBoard = nullptr;
CAudioStream* pAudioStream = nullptr;

CGUI *pGUI = nullptr;
CKeyBoard *pKeyBoard = nullptr;
CSettings *pSettings = nullptr;

void InitHookStuff();
void InstallSpecialHooks();
void InitRenderWareFunctions();
void ApplyInGamePatches();
void ApplyPatches_level0();
void MainLoop();

#ifdef GAME_EDITION_CR
extern uint16_t g_usLastProcessedModelIndexAutomobile;
extern int g_iLastProcessedModelIndexAutoEnt;
#endif

extern int g_iLastProcessedSkinCollision;
extern int g_iLastProcessedEntityCollision;
extern int g_iLastRenderedObject;

extern char g_bufRenderQueueCommand[200];
extern uintptr_t g_dwRenderQueueOffset;

#include <sstream>
#include "CClientInfo.h"
#include "vendor/bass/bass.h"
#include "gui/CFontRenderer.h"
#include "CJavaWrapper.h"
#include "cryptors/INITSAMP_result.h"
#include "CDebugInfo.h"

void InitSAMP(JNIEnv* pEnv, jobject thiz);
extern "C"
{
	JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_initSAMP(JNIEnv* pEnv, jobject thiz)
	{
		InitSAMP(pEnv, thiz);
	}
    JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_hideCaptcha(JNIEnv *env, jobject thiz)
	{
        pJava->m_bCaptcha = false;
		pJava->ShowHud();

		if(pGame)
			pGame->FindPlayerPed()->TogglePlayerControllable(true);
	}
    JNIEXPORT bool JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_getCaptcha(JNIEnv *env, jobject thiz)
	{
        return pJava->m_bCaptcha;
	}
}

void InitBASSFuncs(const char* package);
void InitSAMP(JNIEnv* pEnv, jobject thiz)
{
	PROTECT_CODE_INITSAMP;

	Log("Initializing SAMP...");

	InitBASSFuncs(pEnv->GetStringUTFChars(GetPackageName(pEnv, GetGlobalActivity(pEnv)), NULL));
	BASS_Init(-1, 44100, BASS_DEVICE_3D, 0, NULL);

	g_pszStorage = "/storage/emulated/0/Dream/";
	if(!g_pszStorage)
	{
		Log("InitSAMP | Error: storage path not found");
		std::terminate();
		return;
	}

    Log("InitSAMP | Info: %s(storage)", g_pszStorage);
    Log("InitSAMP | Info: %s(package)", pEnv->GetStringUTFChars(GetPackageName(pEnv, GetGlobalActivity(pEnv)), NULL));

	Log(weikton("Powered by Weikton"));
	pSettings = new CSettings();

	CWeaponsOutFit::SetEnabled(pSettings->GetReadOnly().iOutfitGuns);
	CRadarRect::SetEnabled(pSettings->GetReadOnly().iRadarRect);
	CGame::SetEnabledPCMoney(pSettings->GetReadOnly().iPCMoney);
	CDebugInfo::SetDrawFPS(pSettings->GetReadOnly().iFPSCounter);
	CInfoBarText::SetEnabled(pSettings->GetReadOnly().iHPArmourText);
	CSnow::SetCurrentSnow(pSettings->GetReadOnly().iSnow);

	pJava = new CJavaWrapper(pEnv, thiz);
	pJava->SetUseFullScreen(pSettings->GetReadOnly().iCutout);

	CLocalisation::Initialise("ru.lc");

	firebase::crashlytics::SetUserId(pSettings->GetReadOnly().szNickName);

	CWeaponsOutFit::ParseDatFile();

	if(!CCheckFileHash::IsFilesValid())
	{
		CClientInfo::bSAMPModified = false;
		return;
	}
}

// todo: 001bdd93 (TextureDatabaseRuntime::LoadFullTexture(unsigned int)+206)
void PrintBuildCrashInfo()
{
    char cOS[0xFF];
    GetAndroidVersion(cOS);
    char cBrand[0xFF];
    GetBrand(cBrand);
    char cModel[0xFF];
	GetModel(cModel);
    char cArm[0xFF];
	GetArm(cArm);

    CrashLog("\n>> CrashHandler start: ");
    CrashLog("---------- Client Info ----------");
	CrashLog("- SA:MP Version: %s", SAMP_VERSION);
    CrashLog("- Client Version: %s", CLIENT_VERSION);
    CrashLog("- Build Time: %s %s", __TIME__, __DATE__);
    CrashLog("- Path: %s", g_pszStorage);
    CrashLog("- Client Package: %s", pJava->GetEnv()->GetStringUTFChars(GetPackageName(pJava->GetEnv(), GetGlobalActivity(pJava->GetEnv())), NULL));

	CrashLog("---------- User Info ----------");
	CrashLog("- Brand: %s", cBrand);
    CrashLog("- Model: %s", cModel);
    CrashLog("- Android Version: %s", cOS);
    CrashLog("- Arm: %s", cArm);
    CrashLog("- Nickname: %s", pSettings->GetReadOnly().szNickName);
    CrashLog("- SkyBox: %s", (pSettings->GetReadOnly().iSkyBox? "On" : "Off"));

    CrashLog("---------- Game Info ----------");
	CrashLog("Last processed auto and entity: %d %d", g_usLastProcessedModelIndexAutomobile, g_iLastProcessedModelIndexAutoEnt);
	CrashLog("Last processed skin and entity: %d %d", g_iLastProcessedSkinCollision, g_iLastProcessedEntityCollision);
    CrashLog("Last rendered object: %d\n", g_iLastRenderedObject);

    // toasty(pJava->GetEnv(), "CLIENT VERSION: %s (%s, %s)", 3500, CLIENT_VERSION, __TIME__, __DATE__);
}

extern CSnapShotHelper* pSnapShotHelper;
void ProcessCheckForKeyboard();
void InitInMenu()
{
	pGame = new CGame();
	pGame->InitInMenu();

	pGUI = new CGUI();
	pKeyBoard = new CKeyBoard(); // Этот класс теперь реализован как пустышка
	pChatWindow = new CChatWindow();
	pPlayerTags = new CPlayerTags();
	pDialogWindow = new CDialogWindow();
	pScoreBoard = new CScoreBoard();
	pSnapShotHelper = new CSnapShotHelper();
    pAudioStream = new CAudioStream();

	// Безопасный вызов функции клавиатуры
	try {
		if (pKeyBoard && pSettings) {
			ProcessCheckForKeyboard();
		}
	} catch (...) {
		Log("Error in ProcessCheckForKeyboard");
	}

	CFontRenderer::Initialise();
}

bool unique_library_handler(const char* library)
{
	Dl_info info;
	if (dladdr(__builtin_return_address(0), &info) != 0)
	{
		void* current_library_addr = dlopen(info.dli_fname, RTLD_NOW);
		if (!current_library_addr)
			return false;

		if (dlopen(library, RTLD_NOW) != current_library_addr)
			return false;
	}
	return true;
}

void ProcessCheckForKeyboard()
{
	// Отключено для предотвращения сбоев
	if (pKeyBoard && pSettings)
	{
		if (pSettings->GetReadOnly().iAndroidKeyboard)
		{
			pKeyBoard->EnableNewKeyboard();
		}
		else
		{
			pKeyBoard->EnableOldKeyboard();
		}
	}
}

bool isWNHere(const char* package);
void exitCase()
{
	if(!isWNHere(pJava->GetEnv()->GetStringUTFChars(GetPackageName(pJava->GetEnv(), GetGlobalActivity(pJava->GetEnv())), NULL)))
    {
        Log(weikton(">> Other lib here, exit..."));
        std::terminate();
    }
    Log(weikton(">> Weikton here, continue..."));
}

#include "net/CUDPSocket.h"
void InitInGame()
{
	static bool bGameInited = false;
	static bool bNetworkInited = false;

	if (!bGameInited)
	{
		if (!unique_library_handler(libName))
		{
			exitCase();
		}

		pGame->InitInGame();
		pGame->SetMaxStats();

        pJava->UpdateLoading(3);
        bGameInited = true;
		return;
	}

	if (!bNetworkInited)
	{
        pJava->UpdateLoading(0);

        // Создаем сетевой интерфейс без параметров
        pNetGame = new CNetGame("", 0, pSettings->GetReadOnly().szNickName, pSettings->GetReadOnly().szPassword);
        
        // Сразу показываем окно выбора серверов
        if (pNetGame) {
            pNetGame->ShowServerSelector();
        }

        bNetworkInited = true;
		return;
	}
}

// extern "C" {
//     JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_setServer(JNIEnv* pEnv, jobject thiz, jstring ip, jint port) {
//         // const char *IPnew = pEnv->GetStringUTFChars(ip, 0);
//         // pNetGame = new CNetGame(IPnew, port, pSettings->GetReadOnly().szNickName, pSettings->GetReadOnly().szPassword);
//         Log(weikton("already used"));
// 	}
// }

void (*CTimer__StartUserPause)();
void CTimer__StartUserPause_hook()
{
	if (pJava)
	{
		// Безопасный вызов функций клавиатуры
		try {
			if (pKeyBoard)
			{
				if (pKeyBoard->IsNewKeyboard())
				{
					pKeyBoard->Close();
				}
			}
		} catch (...) {
			Log("Error in keyboard handling during pause");
		}
		pJava->SetPauseState(true);
	}

	*(uint8_t*)(g_libGTASA + 0x008C9BA3) = 1;
}

void (*CTimer__EndUserPause)();
void CTimer__EndUserPause_hook()
{
	if (pJava)
	{
		pJava->SetPauseState(false);
	}

	*(uint8_t*)(g_libGTASA + 0x008C9BA3) = 0;
}

#include "CDebugInfo.h"
void MainLoop()
{
	InitInGame();

	if(pNetGame) pNetGame->Process();

	if (pNetGame)
	{
		if (pNetGame->GetPlayerPool())
		{
			if (pNetGame->GetPlayerPool()->GetLocalPlayer())
			{
				CVehicle* pVeh = pNetGame->GetVehiclePool()->GetAt(pNetGame->GetPlayerPool()->GetLocalPlayer()->m_CurrentVehicle);
				if (pVeh)
				{
					VECTOR vec;
					pVeh->GetMoveSpeedVector(&vec);
					CDebugInfo::ProcessSpeedMode(&vec);
				}
			}
		}
	}
}

extern "C"
{
	JavaVM* javaVM = NULL;
	JavaVM* alcGetJavaVM(void) {
		return javaVM;
	}
}
extern "C" AL_API jint AL_APIENTRY JNI_OnLoad_alc(JavaVM* vm, void* reserved);

void (*RQ_Command_rqSetAlphaTest)(char**);
void RQ_Command_rqSetAlphaTest_hook(char** a1)
{
	return;
}

#include "CFPSFix.h"
CFPSFix g_fps;

void (*ANDRunThread)(void* a1);
void ANDRunThread_hook(void* a1)
{
	g_fps.PushThread(gettid());

	ANDRunThread(a1);
}

jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
	JNI_OnLoad_alc(vm, reserved);
	javaVM = vm;

	Log("SAMP library loaded! Build time: " __DATE__ " " __TIME__);

	g_libGTASA = FindLibrary("libGTASA.so");
	if(g_libGTASA == 0)
	{
		Log("ERROR: libGTASA.so address not found!");
		return 0;
	}
	Log("libGTASA.so image base address: 0x%X", g_libGTASA);

	firebase::crashlytics::Initialize();

	uintptr_t libgtasa = FindLibrary("libGTASA.so");
	uintptr_t libsamp = FindLibrary("libsamp.so");
	uintptr_t libc = FindLibrary("libc.so");

	Log("libGTASA.so: 0x%x", libgtasa);
	Log("libsamp.so: 0x%x", libsamp);
	Log("libc.so: 0x%x", libc);

	char str[100];

	sprintf(str, "0x%x", libgtasa);
	firebase::crashlytics::SetCustomKey("libGTASA.so", str);
	
	sprintf(str, "0x%x", libsamp);
	firebase::crashlytics::SetCustomKey("libsamp.so", str);

	sprintf(str, "0x%x", libc);
	firebase::crashlytics::SetCustomKey("libc.so", str);

	srand(time(0));

	InitHookStuff();

	InitRenderWareFunctions();
	InstallSpecialHooks();

	// increase render memory buffer
	SetUpHook(g_libGTASA + 0x003BF784, (uintptr_t)CTimer__StartUserPause_hook, (uintptr_t*)& CTimer__StartUserPause);
	SetUpHook(g_libGTASA + 0x003BF7A0, (uintptr_t)CTimer__EndUserPause_hook, (uintptr_t*)& CTimer__EndUserPause);

	NOP(g_libGTASA + 0x0039844E, 2);
	NOP(g_libGTASA + 0x0039845E, 2);
	NOP(g_libGTASA + 0x0039840A, 2);

	NOP(g_libGTASA + 0x002E1EDC, 2);
	NOP(g_libGTASA + 0x00398972, 2);

	ApplyPatches_level0();

    CrashHandler::Initialise();

	return JNI_VERSION_1_4;
}

void Log(const char *fmt, ...)
{
	char buffer[0xFF];
	static FILE* flLog = nullptr;

	if(flLog == nullptr && g_pszStorage != nullptr)
	{
		sprintf(buffer, "%sSAMP/%s", g_pszStorage, logName);
		flLog = fopen(buffer, "a");
	}
	memset(buffer, 0, sizeof(buffer));

	va_list arg;
	va_start(arg, fmt);
	vsnprintf(buffer, sizeof(buffer), fmt, arg);
	va_end(arg);

	firebase::crashlytics::Log(buffer);

	if(flLog == nullptr) return;
	fprintf(flLog, "%s\n", buffer);
	fflush(flLog);

	__android_log_write(ANDROID_LOG_INFO, "AXL", buffer);

	return;
}

void CrashLog(const char* fmt, ...)
{
    char buffer[2048+1] = { '\0' };
	static FILE* flLog = nullptr;

	if (flLog == nullptr && g_pszStorage != nullptr)
	{
		sprintf(buffer, weikton("%sSAMP/%s"), g_pszStorage, crashLogName);
		flLog = fopen(buffer, weikton("a"));
	}

	memset(buffer, 0, sizeof(buffer));

	va_list arg;
	va_start(arg, fmt);
	vsnprintf(buffer, sizeof(buffer), fmt, arg);
	va_end(arg);

	__android_log_write(ANDROID_LOG_INFO, weikton("crashdump"), buffer);

	firebase::crashlytics::Log(buffer);

	if (flLog == nullptr) return;
	fprintf(flLog, weikton("%s\n"), buffer);
	fflush(flLog);

	fclose(flLog);
	flLog = nullptr;
}

uint32_t GetTickCount()
{
	struct timeval tv;
	gettimeofday(&tv, nullptr);

	return (tv.tv_sec*1000+tv.tv_usec/1000);
}
