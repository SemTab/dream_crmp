#include "../main.h"
#include "gui.h"
#include "../game/game.h"
#include "../net/netgame.h"
#include "../game/RW/RenderWare.h"
#include "../CChatWindow.h"
#include "../playertags.h"
#include "../CDialog.h"
#include "../CKeyboard.h"
#include "../CSettings.h"
#include "..//scoreboard.h"
#include "../CJavaWrapper.h"
#include "../util/util.h"
#include "../game/vehicle.h"

extern CScoreBoard* pScoreBoard;
extern CChatWindow *pChatWindow;
extern CPlayerTags *pPlayerTags;
extern CDialogWindow *pDialogWindow;
extern CSettings *pSettings;
extern CKeyBoard *pKeyBoard;
extern CNetGame *pNetGame;
extern CJavaWrapper *pJava;

/* imgui_impl_renderware.h */
void ImGui_ImplRenderWare_RenderDrawData(ImDrawData* draw_data);
bool ImGui_ImplRenderWare_Init();
void ImGui_ImplRenderWare_NewFrame();
void ImGui_ImplRenderWare_ShutDown();

/*
	Все координаты GUI-элементов задаются
	относительно разрешения 1920x1080
*/
#define MULT_X	0.00052083333f	// 1/1920
#define MULT_Y	0.00092592592f 	// 1/1080

CGUI::CGUI()
{
	Log("Initializing GUI..");

	m_bMouseDown = 0;
	m_vTouchPos = ImVec2(-1, -1);
	m_bNextClear = false;
	m_bNeedClearMousePos = false;

	// setup ImGUI
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO &io = ImGui::GetIO();

	ImGui_ImplRenderWare_Init();

	// scale
	m_vecScale.x = io.DisplaySize.x * MULT_X;
	m_vecScale.y = io.DisplaySize.y * MULT_Y;
	// font Size
	m_fFontSize = ScaleY( pSettings->GetReadOnly().fFontSize );

	Log("GUI | Scale factor: %f, %f Font size: %f", m_vecScale.x, m_vecScale.y, m_fFontSize);

	// setup style
	ImGuiStyle& style = ImGui::GetStyle();
	style.FrameRounding = 3.0f;
	style.ScrollbarSize = ScaleY(55.0f);
	style.WindowBorderSize = 0.0f;
	style.FrameBorderSize = 2.0f;
	ImGui::StyleColorsDark();

	// load fonts
	char path[0xFF];
	sprintf(path, "%sSAMP/fonts/%s", g_pszStorage, pSettings->GetReadOnly().szFont);
	// cp1251 ranges
	static const ImWchar ranges[] = 
	{
		0x0020, 0x0080,
		0x00A0, 0x00C0,
		0x0400, 0x0460,
		0x0490, 0x04A0,
		0x2010, 0x2040,
		0x20A0, 0x20B0,
		0x2110, 0x2130,
		0
	};
	Log("GUI | Loading font: %s", pSettings->GetReadOnly().szFont);
	m_pFont = io.Fonts->AddFontFromFileTTF(path, m_fFontSize, nullptr, ranges);
	// Log("GUI | ImFont pointer = 0x%X", m_pFont);
	
	fontmoney = io.Fonts->AddFontFromFileTTF(path, m_fFontSize, nullptr, ranges);

	style.WindowRounding = 0.0f;

	m_pSplashTexture = nullptr;

	m_pSplashTexture = (RwTexture*)LoadTextureFromDB("txd", "splash_icon");

	CRadarRect::LoadTextures();


	m_bKeysStatus = false;
}

CGUI::~CGUI()
{
	ImGui_ImplRenderWare_ShutDown();
	ImGui::DestroyContext();
}
#include "..//CServerManager.h"
bool g_IsVoiceServer()
{
	return false;
}

extern float g_fMicrophoneButtonPosX;
extern float g_fMicrophoneButtonPosY;
extern uint32_t g_uiLastTickVoice;
#include "..//voice/CVoiceChatClient.h"
extern CVoiceChatClient* pVoice;

void CGUI::PreProcessInput()
{
	ImGuiIO& io = ImGui::GetIO();

	io.MousePos = m_vTouchPos;
	io.MouseDown[0] = m_bMouseDown;
	if (!m_bNeedClearMousePos && m_bNextClear)
	{
		m_bNextClear = false;
	}
	if (m_bNeedClearMousePos && m_bNextClear)
	{
		io.MousePos = ImVec2(-1, -1);
		m_bNextClear = true;
	}
}

void CGUI::PostProcessInput()
{
	ImGuiIO& io = ImGui::GetIO();

	if (m_bNeedClearMousePos && io.MouseDown[0])
	{
		return;
	}

	if (m_bNeedClearMousePos && !io.MouseDown[0])
	{
		io.MousePos = ImVec2(-1, -1);
		m_bNextClear = true;
	}
}
#include "..//CDebugInfo.h"
extern CGame* pGame;

extern "C"
{
	JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_sendALT(JNIEnv* pEnv, jobject thiz)
	{
        CPlayerPool* pPlayerPool = pNetGame->GetPlayerPool();
        if (pPlayerPool)
        {
            CLocalPlayer* pLocalPlayer;
            if (!pPlayerPool->GetLocalPlayer()->GetPlayerPed()->IsInVehicle() && !pPlayerPool->GetLocalPlayer()->GetPlayerPed()->IsAPassenger())
                LocalPlayerKeys.bKeys[ePadKeys::KEY_WALK] = true;
            else
                LocalPlayerKeys.bKeys[ePadKeys::KEY_FIRE] = true;
        }
	}
	JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_sendCTRL(JNIEnv* pEnv, jobject thiz)
	{
        LocalPlayerKeys.bKeys[ePadKeys::KEY_ACTION] = true;
	}
	JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_sendY(JNIEnv* pEnv, jobject thiz)
	{
        LocalPlayerKeys.bKeys[ePadKeys::KEY_YES] = true;
	}
	JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_sendN(JNIEnv* pEnv, jobject thiz)
	{
        LocalPlayerKeys.bKeys[ePadKeys::KEY_NO] = true;
	}
	JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_sendH(JNIEnv* pEnv, jobject thiz)
	{
        LocalPlayerKeys.bKeys[ePadKeys::KEY_CTRL_BACK] = true;
	}
	JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_sendG(JNIEnv* pEnv, jobject thiz)
	{
        CVehiclePool* pVehiclePool = pNetGame->GetVehiclePool();
        CPlayerPed *pPlayerPed = pGame->FindPlayerPed();
        if (pVehiclePool)
        {
            VEHICLEID ClosetVehicleID = pVehiclePool->FindNearestToLocalPlayerPed();
            if (ClosetVehicleID < MAX_VEHICLES && pVehiclePool->GetSlotState(ClosetVehicleID))
            {
                CVehicle* pVehicle = pVehiclePool->GetAt(ClosetVehicleID);
                if (pVehicle)
                {
                    CPlayerPool* pPlayerPool = pNetGame->GetPlayerPool();
                    if (pPlayerPool)
                    {
                        CLocalPlayer* pLocalPlayer;
                        pPlayerPed->EnterVehicle(pVehicle->m_dwGTAId, true);
                        pLocalPlayer->SendEnterVehicleNotification(ClosetVehicleID, true);
                    }
                }
            }
        }
	}
}

void CGUI::Render()
{
	PreProcessInput();

	ProcessPushedTextdraws();
	if (pChatWindow)
	{
		pChatWindow->ProcessPushedCommands();
	}

	ImGui_ImplRenderWare_NewFrame();
	ImGui::NewFrame();
	if (pKeyBoard)
	{
		pKeyBoard->ProcessInputCommands();
	}

	if (pPlayerTags) pPlayerTags->Render();
	
	if(pNetGame && pNetGame->GetLabelPool())
	{
		pNetGame->GetLabelPool()->Draw();
	}

	if (pChatWindow) pChatWindow->Render();
	if (pGame) CGUI::ShowSpeed();
	if (pScoreBoard) pScoreBoard->Draw();
	if (pKeyBoard) pKeyBoard->Render();
	if (pDialogWindow) pDialogWindow->Render();

    if(pNetGame && !pGame->IsGamePaused() && !pKeyBoard->IsOpen() && !pJava->m_bCaptcha)
	{
        if(pJava->m_bGPS)
            pJava->CallLauncherActivity(1);
        else
            pJava->CallLauncherActivity(2);

        if(pJava->m_bGreenZone)
            pJava->CallLauncherActivity(3);
        else
            pJava->CallLauncherActivity(4);
    } else {
        pJava->CallLauncherActivity(6);
    }

    // Отрисовка кнопок интерфейса
    if (pNetGame && !pDialogWindow->m_bIsActive && pGame->IsToggledHUDElement(HUD_ELEMENT_BUTTONS))
	{
        ImGuiIO& io = ImGui::GetIO();
        ImVec2 vecButSize = ImVec2(ImGui::GetFontSize() * 3.5, ImGui::GetFontSize() * 2.5);
        ImGui::SetNextWindowPos(ImVec2(2.0f, io.DisplaySize.y / 2.6 - vecButSize.x / 2));
        ImGui::Begin("###keys", nullptr,
            ImGuiWindowFlags_NoTitleBar |
            ImGuiWindowFlags_NoResize |
            ImGuiWindowFlags_NoScrollbar |
            ImGuiWindowFlags_NoSavedSettings |
            ImGuiWindowFlags_AlwaysAutoResize);

      /*  if (ImGui::Button(m_bKeysStatus ? "<<" : ">>", vecButSize))
        {
            if (m_bKeysStatus)
                m_bKeysStatus = false;
            else
                m_bKeysStatus = true;
        }

        ImGui::SameLine();
        /*
        if (ImGui::Button("ALT", vecButSize))
        {
            CPlayerPool* pPlayerPool = pNetGame->GetPlayerPool();
            if (pPlayerPool)
            {
                CLocalPlayer* pLocalPlayer = pPlayerPool->GetLocalPlayer();

                if(pLocalPlayer) {
                    if(!pLocalPlayer->GetPlayerPed()->IsInVehicle()) {
                        LocalPlayerKeys.bKeys[ePadKeys::KEY_WALK] = true;
                    } else {
                        LocalPlayerKeys.bKeys[ePadKeys::KEY_FIRE] = true;
                    }
                }
            }
        }
        */
        ImGui::SameLine();

        CVehiclePool* pVehiclePool = pNetGame->GetVehiclePool();
        if (pVehiclePool)
        {
            VEHICLEID ClosetVehicleID = pVehiclePool->FindNearestToLocalPlayerPed();
            if (ClosetVehicleID < MAX_VEHICLES && pVehiclePool->GetSlotState(ClosetVehicleID))
            {
                CVehicle* pVehicle = pVehiclePool->GetAt(ClosetVehicleID);
                if (pVehicle)
                {
                    if (pVehicle->GetDistanceFromLocalPlayerPed() < 5.0f)
                    {
                        CPlayerPool* pPlayerPool = pNetGame->GetPlayerPool();
                        if (pPlayerPool)
                        {
                            CLocalPlayer* pLocalPlayer;
                            if (pPlayerPool->GetLocalPlayer()->GetPlayerPed()->IsInVehicle() && !pPlayerPool->GetLocalPlayer()->GetPlayerPed()->IsAPassenger())
                            {
                                /*
                                if (ImGui::Button("CTRL", vecButSize))
                                    LocalPlayerKeys.bKeys[ePadKeys::KEY_ACTION] = true;
                                */
                            }
                            ImGui::SameLine();
                        }
                    }
                }
            }
        }

        if (m_bKeysStatus)
        {
            ImGui::SameLine();
            /*
            if (ImGui::Button("Y", vecButSize)) {
                LocalPlayerKeys.bKeys[ePadKeys::KEY_YES] = true;
            }

            ImGui::SameLine();
            if (ImGui::Button("N", vecButSize)) {
                LocalPlayerKeys.bKeys[ePadKeys::KEY_NO] = true;
            }

            ImGui::SameLine();
            if (ImGui::Button("H", vecButSize)) {
                LocalPlayerKeys.bKeys[ePadKeys::KEY_CTRL_BACK] = true;
            }
            */
        }
        ImGui::End();
    }

    if(pNetGame && !pDialogWindow->m_bIsActive && !pKeyBoard->m_bEnable && !pJava->m_bCaptcha)
	{
		CVehiclePool* pVehiclePool = pNetGame->GetVehiclePool();
		if (pVehiclePool)
		{
			VEHICLEID ClosetVehicleID = pVehiclePool->FindNearestToLocalPlayerPed();
			if (ClosetVehicleID < MAX_VEHICLES && pVehiclePool->GetSlotState(ClosetVehicleID))
			{
				CVehicle* pVehicle = pVehiclePool->GetAt(ClosetVehicleID);
				if (pVehicle)
				{
					if (pVehicle->GetDistanceFromLocalPlayerPed() < 5.0f && !pKeyBoard->IsOpen())
					{
						CPlayerPool* pPlayerPool = pNetGame->GetPlayerPool();
						if (pPlayerPool)
						{
							CLocalPlayer* pLocalPlayer;
							if (!pPlayerPool->GetLocalPlayer()->GetPlayerPed()->IsInVehicle() && !pPlayerPool->GetLocalPlayer()->GetPlayerPed()->IsAPassenger())
							{
                              	pJava->ShowG();
							} else pJava->HideG();
						}
					} else pJava->HideG();
				}
			}
		}
	} else pJava->HideG();

    if (pNetGame)
	{
		if (pVoice && g_IsVoiceServer())
		{
			ImVec2 centre(ScaleX(1880.0f), ScaleY(35.0f));
			if (pVoice->IsDisconnected())
				ImGui::GetBackgroundDrawList()->AddCircleFilled(centre, 10.0f, ImColor(0.8f, 0.0f, 0.0f));

			if (pVoice->GetNetworkState() == VOICECHAT_CONNECTING || pVoice->GetNetworkState() == VOICECHAT_WAIT_CONNECT)
				ImGui::GetBackgroundDrawList()->AddCircleFilled(centre, 10.0f, ImColor(1.0f, 1.0f, 0.0f));

			if (pVoice->GetNetworkState() == VOICECHAT_CONNECTED)
				ImGui::GetBackgroundDrawList()->AddCircleFilled(centre, 10.0f, ImColor(0.0f, 0.8f, 0.0f));
		}
	}

    CDebugInfo::Draw();
    
    RenderVersion();

	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplRenderWare_RenderDrawData(ImGui::GetDrawData());

	PostProcessInput();
}

bool CGUI::OnTouchEvent(int type, bool multi, int x, int y)
{
	if(!pKeyBoard->OnTouchEvent(type, multi, x, y)) return false;

	if (!pScoreBoard->OnTouchEvent(type, multi, x, y)) return false;

	bool bFalse = true;
	if (pNetGame)
	{
		if (pNetGame->GetTextDrawPool()->OnTouchEvent(type, multi, x, y))
		{
			if (!pChatWindow->OnTouchEvent(type, multi, x, y)) return false;
		}
		else
		{
			bFalse = false;
		}
	}

	switch(type)
	{
		case TOUCH_PUSH:
		{
			m_vTouchPos = ImVec2(x, y);
			m_bMouseDown = true;
			m_bNeedClearMousePos = false;
			break;
		}

		case TOUCH_POP:
		{
			m_bMouseDown = false;
			m_bNeedClearMousePos = true;
			break;
		}

		case TOUCH_MOVE:
		{
			m_bNeedClearMousePos = false;
			m_vTouchPos = ImVec2(x, y);
			break;
		}
	}
	if (!bFalse)
	{
		return false;
	}
	return true;
}

void CGUI::RenderVersion()
{
	ImGuiIO& io = ImGui::GetIO();
	float size_font = 30.0f;
	ImVec2 _ImVec2 = ImVec2(2.0f, io.DisplaySize.y - size_font);

	// Генерация кода билда на основе даты и времени компиляции
	unsigned int date_hash = 0;
	unsigned int time_hash = 0;
	const char* date_str = __DATE__;  // формат: "Mmm DD YYYY"
	const char* time_str = __TIME__;  // формат: "HH:MM:SS"
	
	// Простая хэш-функция для создания уникального кода
	for (int i = 0; date_str[i] != '\0'; i++) {
		date_hash = ((date_hash << 5) + date_hash) + date_str[i];
	}
	
	for (int i = 0; time_str[i] != '\0'; i++) {
		time_hash = ((time_hash << 5) + time_hash) + time_str[i];
	}
	
	char build_code[32];
	sprintf(build_code, "%07X-%08X", date_hash & 0xFFFFFFF, time_hash & 0xFFFFFFFF);

	char text[256];
	sprintf(text, "Last build: %s | by BD", __DATE__);
	ImVec2 posCur = _ImVec2;
	float iOffset = 1.0f;
	char* text_begin = text;
	char* text_end = nullptr;

	posCur.x -= iOffset;
	ImGui::GetBackgroundDrawList()->AddText(fontmoney, size_font, posCur, ImColor(IM_COL32_BLACK), text_begin, text_end);
	posCur.x += iOffset;
	// right 
	posCur.x += iOffset;
	ImGui::GetBackgroundDrawList()->AddText(fontmoney, size_font, posCur, ImColor(IM_COL32_BLACK), text_begin, text_end);
	posCur.x -= iOffset;
	// above
	posCur.y -= iOffset;
	ImGui::GetBackgroundDrawList()->AddText(fontmoney, size_font, posCur, ImColor(IM_COL32_BLACK), text_begin, text_end);
	posCur.y += iOffset;
	// below
	posCur.y += iOffset;
	ImGui::GetBackgroundDrawList()->AddText(fontmoney, size_font, posCur, ImColor(IM_COL32_BLACK), text_begin, text_end);
	posCur.y -= iOffset;
	ImGui::GetBackgroundDrawList()->AddText(fontmoney, size_font, posCur, ImColor(255, 255, 255, 255), text_begin, text_end);
	// RenderText(_ImVec2, ImColor(255, 255, 255, 255), true, text, nullptr);
}

void CGUI::ProcessPushedTextdraws()
{
	BUFFERED_COMMAND_TEXTDRAW* pCmd = nullptr;
	while (pCmd = m_BufferedCommandTextdraws.ReadLock())
	{
		RakNet::BitStream bs;
		bs.Write(pCmd->textdrawId);
		pNetGame->GetRakClient()->RPC(&RPC_ClickTextDraw, &bs, HIGH_PRIORITY, RELIABLE_SEQUENCED, 0, false, UNASSIGNED_NETWORK_ID, 0);
		m_BufferedCommandTextdraws.ReadUnlock();
	}
}

void CGUI::RenderRakNetStatistics()
{
		//StatisticsToString(rss, message, 0);

		/*ImGui::GetOverlayDrawList()->AddText(
			ImVec2(ScaleX(10), ScaleY(400)),
			ImColor(IM_COL32_BLACK), message);*/
}

extern uint32_t g_uiBorderedText;
void CGUI::RenderTextForChatWindow(ImVec2& posCur, ImU32 col, bool bOutline, const char* text_begin, const char* text_end)
{
	int iOffset = pSettings->GetReadOnly().iFontOutline;

	ImColor colOutline = ImColor(IM_COL32_BLACK);
	ImColor colDef = ImColor(col);
	colOutline.Value.w = colDef.Value.w;

	if (bOutline)
	{
		if (g_uiBorderedText)
		{
			posCur.x -= iOffset;
			ImGui::GetBackgroundDrawList()->AddText(posCur, colOutline, text_begin, text_end);
			posCur.x += iOffset;
			// right 
			posCur.x += iOffset;
			ImGui::GetBackgroundDrawList()->AddText(posCur, colOutline, text_begin, text_end);
			posCur.x -= iOffset;
			// above
			posCur.y -= iOffset;
			ImGui::GetBackgroundDrawList()->AddText(posCur, colOutline, text_begin, text_end);
			posCur.y += iOffset;
			// below
			posCur.y += iOffset;
			ImGui::GetBackgroundDrawList()->AddText(posCur, colOutline, text_begin, text_end);
			posCur.y -= iOffset;
		}
		else
		{
			ImColor co(0.0f, 0.0f, 0.0f, 0.4f);
			if (colOutline.Value.w <= 0.4)
			{
				co.Value.w = colOutline.Value.w;
			}
			ImVec2 b(posCur.x + ImGui::CalcTextSize(text_begin, text_end).x, posCur.y + GetFontSize());
			ImGui::GetBackgroundDrawList()->AddRectFilled(posCur, b, co);
		}
	}

	ImGui::GetBackgroundDrawList()->AddText(posCur, col, text_begin, text_end);
}

void CGUI::PushToBufferedQueueTextDrawPressed(uint16_t textdrawId)
{
	BUFFERED_COMMAND_TEXTDRAW* pCmd = m_BufferedCommandTextdraws.WriteLock();

	pCmd->textdrawId = textdrawId;

	m_BufferedCommandTextdraws.WriteUnlock();
}

void CGUI::RenderText(ImVec2& posCur, ImU32 col, bool bOutline, const char* text_begin, const char* text_end)
{
	int iOffset = pSettings->GetReadOnly().iFontOutline;

	if (bOutline)
	{
		if (g_uiBorderedText)
		{
			posCur.x -= iOffset;
			ImGui::GetBackgroundDrawList()->AddText(posCur, ImColor(IM_COL32_BLACK), text_begin, text_end);
			posCur.x += iOffset;
			// right 
			posCur.x += iOffset;
			ImGui::GetBackgroundDrawList()->AddText(posCur, ImColor(IM_COL32_BLACK), text_begin, text_end);
			posCur.x -= iOffset;
			// above
			posCur.y -= iOffset;
			ImGui::GetBackgroundDrawList()->AddText(posCur, ImColor(IM_COL32_BLACK), text_begin, text_end);
			posCur.y += iOffset;
			// below
			posCur.y += iOffset;
			ImGui::GetBackgroundDrawList()->AddText(posCur, ImColor(IM_COL32_BLACK), text_begin, text_end);
			posCur.y -= iOffset;
		}
		else
		{
			ImVec2 b(posCur.x + ImGui::CalcTextSize(text_begin, text_end).x, posCur.y + GetFontSize());
			if (m_pSplashTexture)
			{
				ImColor co(1.0f, 1.0f, 1.0f, 0.4f);
				ImGui::GetBackgroundDrawList()->AddImage((ImTextureID)m_pSplashTexture->raster, posCur, b, ImVec2(0, 0), ImVec2(1, 1), co);
			}
			else
			{
				ImColor co(0.0f, 0.0f, 0.0f, 0.4f);
				ImGui::GetBackgroundDrawList()->AddRectFilled(posCur, b, co);
			}
		}
	}

	ImGui::GetBackgroundDrawList()->AddText(posCur, col, text_begin, text_end);
}

void CGUI::SetHealth(float fhpcar)
{
   bHealth = static_cast<int>(fhpcar);
}

int CGUI::GetHealth()
{
	return 1; // static_cast<int>(pVehicle->GetHealth());
}

void CGUI::SetDoor(int door)
{
	bDoor = door;
}

void CGUI::SetEngine(int engine)
{
	bEngine = engine;
}

void CGUI::SetLights(int lights)
{
	bLights = lights;
}

void CGUI::SetMeliage(float meliage)
{
	bMeliage = static_cast<int>(meliage);
}

void CGUI::SetEat(float eate)
{
	eat = static_cast<int>(eate);
}

int CGUI::GetEat()
{
	return eat;
}

void CGUI::SetFuel(float fuel)
{
   m_fuel = static_cast<int>(fuel);
}

void CGUI::ShowSpeed() {
	if (!pGame || !pNetGame || !pGame->FindPlayerPed()->IsInVehicle())
    {
		pJava->HideSpeed();
		return;
	}
	if (pGame->FindPlayerPed()->IsAPassenger())
    {
		pJava->HideSpeed();
		return;
	}
	if (pKeyBoard->IsOpen())
    {
		pJava->HideSpeed();
		return;
	}

	int i_speed = 0;
	float fHealth = 0;
	CVehicle *pVehicle = nullptr;
	CVehiclePool *pVehiclePool = pNetGame->GetVehiclePool();
	CPlayerPed *pPlayerPed = pGame->FindPlayerPed();
    VEHICLEID id = pVehiclePool->FindIDFromGtaPtr(pPlayerPed->GetGtaVehicle());
    pVehicle = pVehiclePool->GetAt(id);

    if(pPlayerPed)
    {
        if(pVehicle)
        {
            VECTOR vecMoveSpeed;
            pVehicle->GetMoveSpeedVector(&vecMoveSpeed);
            i_speed = sqrt((vecMoveSpeed.X * vecMoveSpeed.X) + (vecMoveSpeed.Y * vecMoveSpeed.Y) + (vecMoveSpeed.Z * vecMoveSpeed.Z)) * 180;
            bHealth = pVehicle->GetHealth()/10;
        }
    }
	pJava->ShowSpeed();
	pJava->UpdateSpeedInfo(i_speed, m_fuel, bHealth, bMeliage, bEngine, bLights, 0, bDoor);
}