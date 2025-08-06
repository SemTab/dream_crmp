#include "CJavaWrapper.h"
#include "../main.h"

extern "C" JavaVM* javaVM;

#include "..//CKeyboard.h"
#include "..//CChatWindow.h"
#include "..//CSettings.h"
#include "../net/netgame.h"
#include "../game/game.h"

extern CKeyBoard* pKeyBoard;
extern CChatWindow* pChatWindow;
extern CSettings* pSettings;
extern CNetGame* pNetGame;
extern CGame* pGame;

JNIEnv* CJavaWrapper::GetEnv()
{
	JNIEnv* env = nullptr;
	int getEnvStat = javaVM->GetEnv((void**)& env, JNI_VERSION_1_4);

	if (getEnvStat == JNI_EDETACHED)
	{
		Log("GetEnv: not attached");
		if (javaVM->AttachCurrentThread(&env, NULL) != 0)
		{
			Log("Failed to attach");
			return nullptr;
		}
	}
	if (getEnvStat == JNI_EVERSION)
	{
		Log("GetEnv: version not supported");
		return nullptr;
	}

	if (getEnvStat == JNI_ERR)
	{
		Log("GetEnv: JNI_ERR");
		return nullptr;
	}

	return env;
}

std::string CJavaWrapper::GetClipboardString()
{
	JNIEnv* env = GetEnv();

	if (!env)
	{
		Log("No env");
		return std::string("");
	}

	jbyteArray retn = (jbyteArray)env->CallObjectMethod(activity, s_GetClipboardText);

	if ((env)->ExceptionCheck())
	{
		(env)->ExceptionDescribe();
		(env)->ExceptionClear();
		return std::string("");
	}

	if (!retn)
	{
		return std::string("");
	}

	jboolean isCopy = true;

	jbyte* pText = env->GetByteArrayElements(retn, &isCopy);
	jsize length = env->GetArrayLength(retn);

	std::string str((char*)pText, length);

	env->ReleaseByteArrayElements(retn, pText, JNI_ABORT);
	
	return str;
}

void CJavaWrapper::CallLauncherActivity(int type)
{
	JNIEnv* env = GetEnv();

	if (!env)
	{
		Log("No env");
		return;
	}

	env->CallVoidMethod(activity, s_CallLauncherActivity, type);

	EXCEPTION_CHECK(env);
}

void CJavaWrapper::ShowInputLayout()
{
	JNIEnv* env = GetEnv();

	if (!env)
	{
		Log("No env");
		return;
	}

	env->CallVoidMethod(activity, s_ShowInputLayout);

	EXCEPTION_CHECK(env);
}

void CJavaWrapper::HideInputLayout()
{
	JNIEnv* env = GetEnv();

	if (!env)
	{
		Log("No env");
		return;
	}

	env->CallVoidMethod(activity, s_HideInputLayout);

	EXCEPTION_CHECK(env);
}

void CJavaWrapper::ShowClientSettings()
{
	JNIEnv* env = GetEnv();

	if (!env)
	{
		Log("No env");
		return;
	}

	env->CallVoidMethod(activity, s_ShowClientSettings);

	EXCEPTION_CHECK(env);
}

void CJavaWrapper::SetUseFullScreen(int b)
{
	JNIEnv* env = GetEnv();

	if (!env)
	{
		Log("No env");
		return;
	}

	env->CallVoidMethod(activity, s_SetUseFullScreen, b);

	EXCEPTION_CHECK(env);
}

void CJavaWrapper::MakeDialog(int dialogId, int dialogTypeId, char* caption, char* content, char* leftBtnText, char* rightBtnText)
{
    JNIEnv* env = GetEnv();
    if (!env)
    {
	Log("No env");
	return;
    }
    jclass strClass = env->FindClass("java/lang/String");
    jmethodID ctorID = env->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");
    jstring encoding = env->NewStringUTF("UTF-8");
    jbyteArray bytes = env->NewByteArray(strlen(caption));
    env->SetByteArrayRegion(bytes, 0, strlen(caption), (jbyte*)caption);
    jstring str1 = (jstring)env->NewObject(strClass, ctorID, bytes, encoding);
    //
    jclass strClass1 = env->FindClass("java/lang/String");
    jmethodID ctorID1 = env->GetMethodID(strClass1, "<init>", "([BLjava/lang/String;)V");
    jstring encoding1 = env->NewStringUTF("UTF-8");
    jbyteArray bytes1 = env->NewByteArray(strlen(content));
    env->SetByteArrayRegion(bytes1, 0, strlen(content), (jbyte*)content);
    jstring str2 = (jstring)env->NewObject(strClass1, ctorID1, bytes1, encoding1);
    //
    jclass strClass2 = env->FindClass("java/lang/String");
    jmethodID ctorID2 = env->GetMethodID(strClass2, "<init>", "([BLjava/lang/String;)V");
    jstring encoding2 = env->NewStringUTF("UTF-8");
    jbyteArray bytes2 = env->NewByteArray(strlen(leftBtnText));
    env->SetByteArrayRegion(bytes2, 0, strlen(leftBtnText), (jbyte*)leftBtnText);
    jstring str3 = (jstring)env->NewObject(strClass2, ctorID2, bytes2, encoding2);
    //
    jclass strClass3 = env->FindClass("java/lang/String");
    jmethodID ctorID3 = env->GetMethodID(strClass3, "<init>", "([BLjava/lang/String;)V");
    jstring encoding3 = env->NewStringUTF("UTF-8");
    jbyteArray bytes3 = env->NewByteArray(strlen(rightBtnText));
    env->SetByteArrayRegion(bytes3, 0, strlen(rightBtnText), (jbyte*)rightBtnText);
    jstring str4 = (jstring)env->NewObject(strClass3, ctorID3, bytes3, encoding3);

    env->CallVoidMethod(activity, s_MakeDialog, dialogId, dialogTypeId, str1, str2, str3, str4);

    EXCEPTION_CHECK(env);
}

void CJavaWrapper::ShowHud()
{
    JNIEnv* env = GetEnv();

	if (!env)
	{
		Log("No env");
		return;
	}
    env->CallVoidMethod(this->activity, this->s_showHud);
}

void CJavaWrapper::HideHud()
{
    JNIEnv* env = GetEnv();

	if (!env)
	{
		Log("No env");
		return;
	}
    env->CallVoidMethod(this->activity, this->s_hideHud);
}

void CJavaWrapper::UpdateHudInfo(int health, int armour, int hunger, int weaponid, int ammo, int ammoinclip, int playerid, int money, int wanted, int level)
{
	JNIEnv* env = GetEnv();
	
	if (!env)
	{
		Log("No env");
		return;
	}

	env->CallVoidMethod(this->activity, this->s_updateHudInfo, health, armour, hunger, weaponid, ammo, ammoinclip, playerid, money, wanted, level);
}

void CJavaWrapper::UpdateLoading(int status)
{
	JNIEnv* env = GetEnv();

	if (!env)
	{
		Log("No env");
		return;
	}

	env->CallVoidMethod(this->activity, this->s_updateLoading, status);
}

void CJavaWrapper::ShowSpeed()
{
    JNIEnv* env = GetEnv();

	if (!env)
	{
		Log("No env");
		return;
	}
    env->CallVoidMethod(this->activity, this->s_showSpeed);
}

void CJavaWrapper::HideSpeed()
{
    JNIEnv* env = GetEnv();

	if (!env)
	{
		Log("No env");
		return;
	}
    env->CallVoidMethod(this->activity, this->s_hideSpeed);
}

void CJavaWrapper::UpdateSpeedInfo(int speed, int fuel, int hp, int mileage, int engine, int light, int belt, int lock)
{
	JNIEnv* env = GetEnv();

	if (!env)
	{
		Log("No env");
		return;
	}

	env->CallVoidMethod(this->activity, this->s_updateSpeedInfo, speed, fuel, hp, mileage, engine, light, belt, lock);
}

void CJavaWrapper::ShowG()
{
	JNIEnv* env = GetEnv();

	if (!env)
	{
		Log("No env");
		return;
	}

	env->CallVoidMethod(this->activity, this->s_showHudButtonG);
}

void CJavaWrapper::HideG()
{
	JNIEnv* env = GetEnv();

	if (!env)
	{
		Log("No env");
		return;
	}

	env->CallVoidMethod(this->activity, this->s_hideHudButtonG);
}

void CJavaWrapper::ShowTabWindow()
{
	JNIEnv* env = GetEnv();

	if (!env)
	{
		Log("No env");
		return;
	}

	env->CallVoidMethod(activity, s_showTabWindow);
	EXCEPTION_CHECK(env);
}

void CJavaWrapper::SetTabStat(int id, char* name, int score, int ping) {

	JNIEnv* env = GetEnv();

	if (!env)
	{
		Log("No env");
		return;
	}

	jclass strClass = env->FindClass("java/lang/String");
                  jmethodID ctorID = env->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");
                  jstring encoding = env->NewStringUTF("UTF-8");

                  jbyteArray bytes = env->NewByteArray(strlen(name));
                  env->SetByteArrayRegion(bytes, 0, strlen(name), (jbyte*)name);
                  jstring jname = (jstring) env->NewObject(strClass, ctorID, bytes, encoding);

	env->CallVoidMethod(this->activity, this->s_setTabStat, id, jname, score, ping);
}

void CJavaWrapper::SetPauseState(bool a1)
{
    JNIEnv* env = GetEnv();

	if (!env)
	{
		Log("No env");
		return;
	}
    env->CallVoidMethod(this->activity, this->s_setPauseState, a1);
}

extern int g_iStatusDriftChanged;
#include "..//CDebugInfo.h"
extern "C"
{
	JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_onInputEnd(JNIEnv* pEnv, jobject thiz, jbyteArray str)
	{
		if (pKeyBoard)
		{
			pKeyBoard->OnNewKeyboardInput(pEnv, thiz, str);
		}
	}
	JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_onEventBackPressed(JNIEnv* pEnv, jobject thiz)
	{
		if (pKeyBoard)
		{
			if (pKeyBoard->IsOpen())
			{
				Log("Closing keyboard");
				pKeyBoard->Close();
			}
		}
	}

	JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_onNativeHeightChanged(JNIEnv* pEnv, jobject thiz, jint orientation, jint height)
	{
		if (pChatWindow)
		{
			pChatWindow->SetLowerBound(height);
		}
	}

	JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_sendDialogResponse(JNIEnv* pEnv, jobject thiz, jint i3, jint i, jint i2, jbyteArray str)
	{
		jboolean isCopy = true;

		jbyte* pMsg = pEnv->GetByteArrayElements(str, &isCopy);
		jsize length = pEnv->GetArrayLength(str);

		std::string szStr((char*)pMsg, length);

		if(pNetGame) {
			pNetGame->SendDialogResponse(i, i3, i2, (char*)szStr.c_str());
			pGame->FindPlayerPed()->TogglePlayerControllable(true);
		}

		pEnv->ReleaseByteArrayElements(str, pMsg, JNI_ABORT);
	}

	JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_setNativeHud(JNIEnv* pEnv, jobject thiz, jboolean b)
	{
		if (pSettings)
		{
			pSettings->GetWrite().iHud = b;
			if(!b)
			{
				*(uint8_t*)(g_libGTASA+0x7165E8) = 1;
				pJava->HideHud();
			}
			else
			{
				*(uint8_t*)(g_libGTASA+0x7165E8) = 0;
				pJava->ShowHud();
			}
		}
	}

	JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_setNativeCutoutSettings(JNIEnv* pEnv, jobject thiz, jboolean b)
	{
		if (pSettings)
		{
			pSettings->GetWrite().iCutout = b;
		}
	}

	JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_setNativeKeyboardSettings(JNIEnv* pEnv, jobject thiz, jboolean b)
	{
		if (pSettings)
		{
			pSettings->GetWrite().iAndroidKeyboard = b;
		}

		if (pKeyBoard && b)
		{
			pKeyBoard->EnableNewKeyboard();
		}
		else if(pKeyBoard)
		{
			pKeyBoard->EnableOldKeyboard();
		}
	}

	JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_setNativeFpsCounterSettings(JNIEnv* pEnv, jobject thiz, jboolean b)
	{
		if (pSettings)
		{
			pSettings->GetWrite().iFPSCounter = b;
		}

		// CDebugInfo::ToggleDebugDraw();
	}

	JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_setNativeHpArmourText(JNIEnv* pEnv, jobject thiz, jboolean b)
	{
		if (pSettings)
		{
			if (!pSettings->GetWrite().iHPArmourText && b)
			{
				if (CAdjustableHudColors::IsUsingHudColor(HUD_HP_TEXT) == false)
				{
					CAdjustableHudColors::SetHudColorFromRGBA(HUD_HP_TEXT, 255, 0, 0, 255);
				}
				if (CAdjustableHudPosition::GetElementPosition(HUD_HP_TEXT).X == -1 || CAdjustableHudPosition::GetElementPosition(HUD_HP_TEXT).Y == -1)
				{
					CAdjustableHudPosition::SetElementPosition(HUD_HP_TEXT, 500, 500);
				}
				if (CAdjustableHudScale::GetElementScale(HUD_HP_TEXT).X == -1 || CAdjustableHudScale::GetElementScale(HUD_HP_TEXT).Y == -1)
				{
					CAdjustableHudScale::SetElementScale(HUD_HP_TEXT, 400, 400);
				}

				if (CAdjustableHudColors::IsUsingHudColor(HUD_ARMOR_TEXT) == false)
				{
					CAdjustableHudColors::SetHudColorFromRGBA(HUD_ARMOR_TEXT, 255, 0, 0, 255);
				}
				if (CAdjustableHudPosition::GetElementPosition(HUD_ARMOR_TEXT).X == -1 || CAdjustableHudPosition::GetElementPosition(HUD_ARMOR_TEXT).Y == -1)
				{
					CAdjustableHudPosition::SetElementPosition(HUD_ARMOR_TEXT, 300, 500);
				}
				if (CAdjustableHudScale::GetElementScale(HUD_ARMOR_TEXT).X == -1 || CAdjustableHudScale::GetElementScale(HUD_ARMOR_TEXT).Y == -1)
				{
					CAdjustableHudScale::SetElementScale(HUD_ARMOR_TEXT, 400, 400);
				}
			}

			pSettings->GetWrite().iHPArmourText = b;
		}

		CInfoBarText::SetEnabled(b);
	}

	JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_setNativeOutfitGunsSettings(JNIEnv* pEnv, jobject thiz, jboolean b)
	{
		if (pSettings)
		{
			pSettings->GetWrite().iOutfitGuns = b;

			CWeaponsOutFit::SetEnabled(b);
		}
	}

	JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_setNativePcMoney(JNIEnv* pEnv, jobject thiz, jboolean b)
	{
		if (pSettings)
		{
			pSettings->GetWrite().iPCMoney = b;
		}

		CGame::SetEnabledPCMoney(b);
	}

	JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_setNativeRadarrect(JNIEnv* pEnv, jobject thiz, jboolean b)
	{
		if (pSettings)
		{
			pSettings->GetWrite().iRadarRect = b;

			CRadarRect::SetEnabled(b);
		}
	}

	JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_setNativeSkyBox(JNIEnv* pEnv, jobject thiz, jboolean b)
	{
		if (pSettings)
		{
			pSettings->GetWrite().iSkyBox = b;
			g_iStatusDriftChanged = 1;
		}
	}

	JNIEXPORT jboolean JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_getNativeHud(JNIEnv* pEnv, jobject thiz)
	{
		if (pSettings)
		{
			return pSettings->GetReadOnly().iHud;
		}
		return 0;
	}

	JNIEXPORT jboolean JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_getNativeCutoutSettings(JNIEnv* pEnv, jobject thiz)
	{
		if (pSettings)
		{
			return pSettings->GetReadOnly().iCutout;
		}
		return 0;
	}

	JNIEXPORT jboolean JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_getNativeKeyboardSettings(JNIEnv* pEnv, jobject thiz)
	{
		if (pSettings)
		{
			return pSettings->GetReadOnly().iAndroidKeyboard;
		}
		return 0;
	}

	JNIEXPORT jboolean JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_getNativeFpsCounterSettings(JNIEnv* pEnv, jobject thiz)
	{
		if (pSettings)
		{
			return pSettings->GetReadOnly().iFPSCounter;
		}
		return 0;
	}

	JNIEXPORT jboolean JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_getNativeHpArmourText(JNIEnv* pEnv, jobject thiz)
	{
		if (pSettings)
		{
			return pSettings->GetReadOnly().iHPArmourText;
		}
		return 0;
	}

	JNIEXPORT jboolean JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_getNativeOutfitGunsSettings(JNIEnv* pEnv, jobject thiz)
	{
		if (pSettings)
		{
			return pSettings->GetReadOnly().iOutfitGuns;
		}
		return 0;
	}

	JNIEXPORT jboolean JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_getNativePcMoney(JNIEnv* pEnv, jobject thiz)
	{
		if (pSettings)
		{
			return pSettings->GetReadOnly().iPCMoney;
		}
		return 0;
	}

	JNIEXPORT jboolean JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_getNativeRadarrect(JNIEnv* pEnv, jobject thiz)
	{
		if (pSettings)
		{
			return pSettings->GetReadOnly().iRadarRect;
		}
		return 0;
	}

	JNIEXPORT jboolean JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_getNativeSkyBox(JNIEnv* pEnv, jobject thiz)
	{
		if (pSettings)
		{
			return pSettings->GetReadOnly().iSkyBox;
		}
		return 0;
	}

	JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_onSettingsWindowSave(JNIEnv* pEnv, jobject thiz)
	{
		if (pSettings)
		{
			pSettings->Save();
		}
	}

	JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_onSettingsWindowDefaults(JNIEnv* pEnv, jobject thiz, jint category)
	{
		if (pSettings)
		{
			pSettings->ToDefaults(category);
			if (pChatWindow)
			{
				pChatWindow->m_bPendingReInit = true;
			}
		}
	}

	JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_setNativeHudElementColor(JNIEnv* pEnv, jobject thiz, jint id, jint a, jint r, jint g, jint b)
	{
		CAdjustableHudColors::SetHudColorFromRGBA((E_HUD_ELEMENT)id, r, g, b, a);
	}

	JNIEXPORT jbyteArray JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_getNativeHudElementColor(JNIEnv* pEnv, jobject thiz, jint id)
	{
		char pTemp[9];
		jbyteArray color = pEnv->NewByteArray(sizeof(pTemp));

		if (!color)
		{
			return nullptr;
		}

		pEnv->SetByteArrayRegion(color, 0, sizeof(pTemp), (const jbyte*)CAdjustableHudColors::GetHudColorString((E_HUD_ELEMENT)id).c_str());

		return color;
	}

	JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_setNativeHudElementPosition(JNIEnv* pEnv, jobject thiz, jint id, jint x, jint y)
	{
		if (id == 7)
		{
			if (pSettings)
			{
				pSettings->GetWrite().fChatPosX = x;
				pSettings->GetWrite().fChatPosY = y;
				if (pChatWindow)
				{
					pChatWindow->m_bPendingReInit = true;
				}
				return;
			}
			return;
		}
		if (id == HUD_SNOW)
		{
			if (pSettings)
			{
				pSettings->GetWrite().iSnow = x;
			}
			CSnow::SetCurrentSnow(pSettings->GetReadOnly().iSnow);
			return;
		}
		CAdjustableHudPosition::SetElementPosition((E_HUD_ELEMENT)id, x, y);

		if (id >= HUD_WEAPONSPOS && id <= HUD_WEAPONSROT)
		{
			CWeaponsOutFit::OnUpdateOffsets();
		}
	}

	JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_setNativeHudElementScale(JNIEnv* pEnv, jobject thiz, jint id, jint x, jint y)
	{
		CAdjustableHudScale::SetElementScale((E_HUD_ELEMENT)id, x, y);

		if (id >= HUD_WEAPONSPOS && id <= HUD_WEAPONSROT)
		{
			CWeaponsOutFit::OnUpdateOffsets();
		}
	}

	JNIEXPORT jintArray JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_getNativeHudElementScale(JNIEnv* pEnv, jobject thiz, jint id)
	{
		jintArray color = pEnv->NewIntArray(2);

		if (!color)
		{
			return nullptr;
		}
		int arr[2];
		arr[0] = CAdjustableHudScale::GetElementScale((E_HUD_ELEMENT)id).X;
		arr[1] = CAdjustableHudScale::GetElementScale((E_HUD_ELEMENT)id).Y;
		pEnv->SetIntArrayRegion(color, 0, 2, (const jint*)& arr[0]);

		return color;
	}

	JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_setNativeWidgetPositionAndScale(JNIEnv* pEnv, jobject thiz, jint id, jint x, jint y, jint scale)
	{
		if (id == 0)
		{
			if (pSettings)
			{
				pSettings->GetWrite().fButtonMicrophoneX = x;
				pSettings->GetWrite().fButtonMicrophoneY = y;
				pSettings->GetWrite().fButtonMicrophoneSize = scale;
			}

			if (g_pWidgetManager)
			{
				if (g_pWidgetManager->GetSlotState(WIDGET_MICROPHONE))
				{
					g_pWidgetManager->GetWidget(WIDGET_MICROPHONE)->SetPos(x, y);
					g_pWidgetManager->GetWidget(WIDGET_MICROPHONE)->SetHeight(scale);
					g_pWidgetManager->GetWidget(WIDGET_MICROPHONE)->SetWidth(scale);
				}
			}
		}
		

		if (id == 2)
		{
			if (pSettings)
			{
				pSettings->GetWrite().fButtonCameraCycleX = x;
				pSettings->GetWrite().fButtonCameraCycleY = y;
				pSettings->GetWrite().fButtonCameraCycleSize = scale;
			}

			if (g_pWidgetManager)
			{
				if (g_pWidgetManager->GetSlotState(WIDGET_CAMERA_CYCLE))
				{
					g_pWidgetManager->GetWidget(WIDGET_CAMERA_CYCLE)->SetPos(x, y);
					g_pWidgetManager->GetWidget(WIDGET_CAMERA_CYCLE)->SetHeight(scale);
					g_pWidgetManager->GetWidget(WIDGET_CAMERA_CYCLE)->SetWidth(scale);
				}
			}
		}
	}

	JNIEXPORT jintArray JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_getNativeHudElementPosition(JNIEnv* pEnv, jobject thiz, jint id)
	{
		jintArray color = pEnv->NewIntArray(2);

		if (!color)
		{
			return nullptr;
		}
		int arr[2];

		if (id == 7 && pSettings)
		{
			arr[0] = pSettings->GetReadOnly().fChatPosX;
			arr[1] = pSettings->GetReadOnly().fChatPosY;
		}
		else if (id == HUD_SNOW && pSettings)
		{
			arr[0] = CSnow::GetCurrentSnow();
			arr[1] = CSnow::GetCurrentSnow();
		}
		else
		{
			arr[0] = CAdjustableHudPosition::GetElementPosition((E_HUD_ELEMENT)id).X;
			arr[1] = CAdjustableHudPosition::GetElementPosition((E_HUD_ELEMENT)id).Y;
		}

		pEnv->SetIntArrayRegion(color, 0, 2, (const jint*)&arr[0]);

		return color;
	}

	JNIEXPORT jintArray JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_getNativeWidgetPositionAndScale(JNIEnv* pEnv, jobject thiz, jint id)
	{
		jintArray color = pEnv->NewIntArray(3);

		if (!color)
		{
			return nullptr;
		}
		int arr[3] = { -1, -1, -1 };
		

		if (pSettings)
		{
			if (id == 0)
			{
				arr[0] = pSettings->GetWrite().fButtonMicrophoneX;
				arr[1] = pSettings->GetWrite().fButtonMicrophoneY;
				arr[2] = pSettings->GetWrite().fButtonMicrophoneSize;
			}
			if (id == 1)
			{
				arr[0] = pSettings->GetWrite().fButtonEnterPassengerX;
				arr[1] = pSettings->GetWrite().fButtonEnterPassengerY;
				arr[2] = pSettings->GetWrite().fButtonEnterPassengerSize;
			}
			if (id == 2)
			{
				arr[0] = pSettings->GetWrite().fButtonCameraCycleX;
				arr[1] = pSettings->GetWrite().fButtonCameraCycleY;
				arr[2] = pSettings->GetWrite().fButtonCameraCycleSize;
			}
		}
		

		pEnv->SetIntArrayRegion(color, 0, 3, (const jint*)& arr[0]);

		return color;
	}
}

/// NEW
void CJavaWrapper::ShowSpawnSelector(bool isHouse, bool isFraction)
{
	JNIEnv* env = GetEnv();

	if (!env)
	{
		Log("No env");
		return;
	}

	env->CallVoidMethod(activity, s_ShowSpawnSelector, isHouse, isFraction);

	EXCEPTION_CHECK(env);
}
void CJavaWrapper::ShowAZS(int fuelId, int maxFuel, float currentFuel, int price, int balance)
{
	JNIEnv* env = GetEnv();

	if (!env)
	{
		Log("No env");
		return;
	}

	env->CallVoidMethod(activity, s_ShowAZS, fuelId, maxFuel, currentFuel, price, balance);

	EXCEPTION_CHECK(env);
}
void CJavaWrapper::ShowCaptcha()
{
	JNIEnv* env = GetEnv();

	if (!env)
	{
		Log("No env");
		return;
	}

	env->CallVoidMethod(activity, s_ShowCaptcha);

	EXCEPTION_CHECK(env);
}
void CJavaWrapper::ShowNumbers(int balance)
{
	JNIEnv* env = GetEnv();

	if (!env)
	{
		Log("No env");
		return;
	}

	env->CallVoidMethod(activity, s_ShowNumbers, balance);

	EXCEPTION_CHECK(env);
}
void CJavaWrapper::GenerateNumber(bool status)
{
	JNIEnv* env = GetEnv();

	if (!env)
	{
		Log("No env");
		return;
	}

	env->CallVoidMethod(activity, s_GenerateNumber, status);

	EXCEPTION_CHECK(env);
}
void CJavaWrapper::BuyNumber(bool status)
{
	JNIEnv* env = GetEnv();

	if (!env)
	{
		Log("No env");
		return;
	}

	env->CallVoidMethod(activity, s_BuyNumber, status);

	EXCEPTION_CHECK(env);
}
///

CJavaWrapper::CJavaWrapper(JNIEnv* env, jobject activity)
{
	this->activity = env->NewGlobalRef(activity);

	jclass actCls = env->GetObjectClass(activity);

	s_GetClipboardText = env->GetMethodID(actCls, "getClipboardText", "()[B");
	s_CallLauncherActivity = env->GetMethodID(actCls, "callLauncherActivity", "(I)V");

	s_ShowInputLayout = env->GetMethodID(actCls, "showInputLayout", "()V");
	s_HideInputLayout = env->GetMethodID(actCls, "hideInputLayout", "()V");

	s_showHud = env->GetMethodID(actCls, "showHud", "()V");
	s_hideHud = env->GetMethodID(actCls, "hideHud", "()V");
	s_updateHudInfo = env->GetMethodID(actCls, "updateHudInfo", "(IIIIIIIIII)V");

	// Инициализация методов для работы с чатом
	s_showChat = env->GetMethodID(actCls, "showChat", "()V");
	s_hideChat = env->GetMethodID(actCls, "hideChat", "()V");
	s_addChatMessage = env->GetMethodID(actCls, "addChatMessage", "(Ljava/lang/String;)V");
	s_setChatStatus = env->GetMethodID(actCls, "setChatStatus", "(I)V");

    s_showTabWindow = env->GetMethodID(actCls, "showTabWindow", "()V");
	s_setTabStat = env->GetMethodID(actCls, "setTabStat", "(ILjava/lang/String;II)V");

	s_showSpeed = env->GetMethodID(actCls, "showSpeed", "()V");
	s_hideSpeed = env->GetMethodID(actCls, "hideSpeed", "()V");
	s_updateSpeedInfo = env->GetMethodID(actCls, "updateSpeedInfo", "(IIIIIIII)V");

	s_ShowClientSettings = env->GetMethodID(actCls, "showClientSettings", "()V");
	s_SetUseFullScreen = env->GetMethodID(actCls, "setUseFullscreen", "(I)V");
    s_MakeDialog = env->GetMethodID(actCls, "showDialog", "(IILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");

	s_showHudButtonG = env->GetMethodID(actCls, "showHudButtonG", "()V");
	s_hideHudButtonG = env->GetMethodID(actCls, "hideHudButtonG", "()V");
	s_setPauseState = env->GetMethodID(actCls, "setPauseState", "(Z)V");

	s_updateLoading = env->GetMethodID(actCls, "updateLoading", "(I)V");
    s_showNotification = env->GetMethodID(actCls, "showNotification", "(ILjava/lang/String;ILjava/lang/String;Ljava/lang/String;)V");

    s_ShowAZS = env->GetMethodID(actCls, "showAZS", "(IIFII)V");
    s_ShowSpawnSelector = env->GetMethodID(actCls, "showSpawnSelector", "(ZZ)V");
    s_ShowCaptcha = env->GetMethodID(actCls, "showCaptcha", "()V");
    s_ShowNumbers = env->GetMethodID(actCls, "showNumbers", "(I)V");
    s_GenerateNumber = env->GetMethodID(actCls, "generateNumber", "(Z)V");
    s_BuyNumber = env->GetMethodID(actCls, "buyNumber", "(Z)V");
    
    // Добавляем методы для работы с выбором серверов
    s_ShowIngameServerSelector = env->GetMethodID(actCls, "showIngameServerSelector", "()V");
    s_HideIngameServerSelector = env->GetMethodID(actCls, "hideIngameServerSelector", "()V");
    s_UpdateServersList = env->GetMethodID(actCls, "updateServersList", "()V");
    
    // Boombox
    s_ShowBoombox = env->GetMethodID(actCls, "showBoombox", "()V");
    
    // Меню действий
    s_ShowActionsMenu = env->GetMethodID(actCls, "showActionsMenu", "()V");
    s_HideActionsMenu = env->GetMethodID(actCls, "hideActionsMenu", "()V");

    m_bCaptcha = false;

    // Инициализация методов для работы с клавиатурой
    s_showKeyboard = env->GetMethodID(actCls, "showKeyboard", "()V");
    s_hideKeyboard = env->GetMethodID(actCls, "hideKeyboard", "()V");

    env->DeleteLocalRef(actCls);
}

CJavaWrapper::~CJavaWrapper()
{
	JNIEnv* pEnv = GetEnv();
	if (pEnv)
	{
		pEnv->DeleteGlobalRef(this->activity);
	}
}

CJavaWrapper* pJava = nullptr;

extern "C"
JNIEXPORT void JNICALL
Java_com_nvidia_devtech_NvEventQueueActivity_sendClick(JNIEnv *env, jobject thiz, jbyteArray str) {
    // TODO: implement sendClick()
    jboolean isCopy = true;

    jbyte* pMsg = env->GetByteArrayElements(str, &isCopy);
    jsize length = env->GetArrayLength(str);

    std::string szStr((char*)pMsg, length);

    // Обработка команды /actions
    if (szStr == "/actions") {
        if (pJava) {
            pJava->ShowActionsMenu();
        }
    } else if (szStr == "/actions hide") {
        if (pJava) {
            pJava->HideActionsMenu();
        }
    } else if(pNetGame) {
        pNetGame->SendChatCommand((char*)szStr.c_str());
    }

    env->ReleaseByteArrayElements(str, pMsg, JNI_ABORT);
}

void CJavaWrapper::ShowNotification(int type, char* text, int duration, char* actionforBtn, char* textBtn)
{
    JNIEnv* env = GetEnv();

    if (!env)
    {
        Log("No env");
        return;
    }

    jclass strClass = env->FindClass("java/lang/String");
    jmethodID ctorID = env->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");
    jstring encoding = env->NewStringUTF("UTF-8");

    jbyteArray bytes = env->NewByteArray(strlen(text));
    env->SetByteArrayRegion(bytes, 0, strlen(text), (jbyte*)text);
    jstring jtext = (jstring) env->NewObject(strClass, ctorID, bytes, encoding);

    bytes = env->NewByteArray(strlen(actionforBtn));
    env->SetByteArrayRegion(bytes, 0, strlen(actionforBtn), (jbyte*)actionforBtn);
    jstring jactionforBtn = (jstring) env->NewObject(strClass, ctorID, bytes, encoding);

    bytes = env->NewByteArray(strlen(textBtn));
    env->SetByteArrayRegion(bytes, 0, strlen(textBtn), (jbyte*)textBtn);
    jstring jtextBtn = (jstring) env->NewObject(strClass, ctorID, bytes, encoding);

    env->CallVoidMethod(this->activity, this->s_showNotification, type, jtext, duration, jactionforBtn, jtextBtn);
}

// Добавляем реализацию методов для работы с выбором серверов
void CJavaWrapper::ShowIngameServerSelector()
{
    JNIEnv* env = GetEnv();
    if (!env)
    {
        Log("No env");
        return;
    }

    env->CallVoidMethod(activity, s_ShowIngameServerSelector);
    EXCEPTION_CHECK(env);
}

void CJavaWrapper::HideIngameServerSelector()
{
    JNIEnv* env = GetEnv();
    if (!env)
    {
        Log("No env");
        return;
    }

    env->CallVoidMethod(activity, s_HideIngameServerSelector);
    EXCEPTION_CHECK(env);
}

void CJavaWrapper::UpdateServersList()
{
    JNIEnv* env = GetEnv();
    if (!env)
    {
        Log("No env");
        return;
    }

    env->CallVoidMethod(activity, s_UpdateServersList);
    EXCEPTION_CHECK(env);
}

// Добавляем нативный метод для обработки выбора сервера
extern "C"
{
    JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_sendServerSelected(JNIEnv* pEnv, jobject thiz, jstring ip, jint port, jint x2)
    {
        if (!pNetGame) return;
        
        const char* serverIP = pEnv->GetStringUTFChars(ip, NULL);
        if (serverIP)
        {
            Log("Сервер выбран: %s:%d (x2: %d)", serverIP, port, x2);
            
            if (pNetGame && pNetGame->GetGameState() == GAMESTATE_CONNECTED)
            {
                // Если уже подключены, отключаемся
                pNetGame->Disconnect();
            }
            
            // Устанавливаем новый сервер
            pNetGame->SetGameHost(serverIP, port);
            
            // Освобождаем строку
            pEnv->ReleaseStringUTFChars(ip, serverIP);
            
            // Запускаем подключение
            pNetGame->ConnectToServer();
        }
    }
}

void CJavaWrapper::ShowBoombox()
{
    JNIEnv* env = GetEnv();
    if (!env)
    {
        Log("No env");
        return;
    }

    env->CallVoidMethod(activity, s_ShowBoombox);
    EXCEPTION_CHECK(env);
}

void CJavaWrapper::ShowActionsMenu()
{
    JNIEnv* env = GetEnv();
    if (!env)
    {
        Log("No env");
        return;
    }

    env->CallVoidMethod(activity, s_ShowActionsMenu);
    EXCEPTION_CHECK(env);
}

void CJavaWrapper::HideActionsMenu()
{
    JNIEnv* env = GetEnv();
    if (!env)
    {
        Log("No env");
        return;
    }

    env->CallVoidMethod(activity, s_HideActionsMenu);
    EXCEPTION_CHECK(env);
}

// Реализация методов для работы с чатом
void CJavaWrapper::ShowChat()
{
    JNIEnv* env = GetEnv();
    if (!env)
    {
        Log("No env");
        return;
    }

    env->CallVoidMethod(activity, s_showChat);
    EXCEPTION_CHECK(env);
}

void CJavaWrapper::HideChat()
{
    JNIEnv* env = GetEnv();
    if (!env)
    {
        Log("No env");
        return;
    }

    env->CallVoidMethod(activity, s_hideChat);
    EXCEPTION_CHECK(env);
}

void CJavaWrapper::AddChatMessage(char* message)
{
    JNIEnv* env = GetEnv();
    if (!env)
    {
        Log("No env");
        return;
    }

    // Преобразуем сообщение из windows-1251 в UTF-8
    char utf8Message[1024];
    cp1251_to_utf8(utf8Message, message);

    jclass strClass = env->FindClass("java/lang/String");
    jmethodID ctorID = env->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");
    jstring encoding = env->NewStringUTF("UTF-8");

    jbyteArray bytes = env->NewByteArray(strlen(utf8Message));
    env->SetByteArrayRegion(bytes, 0, strlen(utf8Message), (jbyte*)utf8Message);
    jstring jmessage = (jstring)env->NewObject(strClass, ctorID, bytes, encoding);

    env->CallVoidMethod(activity, s_addChatMessage, jmessage);
    
    env->DeleteLocalRef(bytes);
    env->DeleteLocalRef(jmessage);
    env->DeleteLocalRef(encoding);
    env->DeleteLocalRef(strClass);
    
    EXCEPTION_CHECK(env);
}

void CJavaWrapper::SetChatStatus(int status)
{
    JNIEnv* env = GetEnv();
    if (!env)
    {
        Log("No env");
        return;
    }

    env->CallVoidMethod(activity, s_setChatStatus, status);
    EXCEPTION_CHECK(env);
}

// Нативный метод для отправки сообщений чата
extern "C"
JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_sendChatMessage(JNIEnv* pEnv, jobject thiz, jbyteArray message)
{
    if(!pNetGame) return;
    
    jboolean isCopy = true;
    jbyte* pMsg = pEnv->GetByteArrayElements(message, &isCopy);
    jsize length = pEnv->GetArrayLength(message);

    std::string szMessage((char*)pMsg, length);
    
    if (szMessage.length() > 0) {
        // Обрабатываем команды так же, как в ProcessVoiceCommands
        if (strstr(szMessage.c_str(), "/boombox"))
        {
            pChatWindow->AddDebugMessage("{FFFF00}[BOOMBOX]{FFFFFF}: Добро пожаловать в первую версию бумбокса. Она доступна для всех БЕСПЛАТНО!");
            if (pJava)
                pJava->ShowBoombox();
        }
        else if (strstr(szMessage.c_str(), "/hudeditor"))
        {
            pJava->ShowClientSettings();
        }
        else if (strstr(szMessage.c_str(), "/debug") || strstr(szMessage.c_str(), "/dl"))
        {
            CDebugInfo::ToggleDebugDraw();
            pChatWindow->AddDebugMessage("{FFFFFF}Debug mode has been toggled");
        }
        else if (szMessage == "/tab") {
            if (pJava) {
                pJava->ShowTabWindow();
            }
        }
        else if (szMessage[0] == '/') {
            pNetGame->SendChatCommand((char*)szMessage.c_str());
        } else {
            pNetGame->SendChatMessage((char*)szMessage.c_str());
        }
    }

    pEnv->ReleaseByteArrayElements(message, pMsg, JNI_ABORT);
}

// Нативный метод для отправки сообщений из ChatManager
extern "C"
JNIEXPORT void JNICALL Java_com_dmob_cr_gui_chatedgar_ChatManager_sendChatMessages(JNIEnv* pEnv, jobject thiz, jbyteArray message)
{
    if(!pNetGame) return;
    
    jboolean isCopy = true;
    jbyte* pMsg = pEnv->GetByteArrayElements(message, &isCopy);
    jsize length = pEnv->GetArrayLength(message);

    std::string szMessage((char*)pMsg, length);
    
    if (szMessage.length() > 0) {
        if (szMessage[0] == '/') {
            pNetGame->SendChatCommand((char*)szMessage.c_str());
        } else {
            pNetGame->SendChatMessage((char*)szMessage.c_str());
        }
    }

    pEnv->ReleaseByteArrayElements(message, pMsg, JNI_ABORT);
}

// Реализация методов для работы с клавиатурой
void CJavaWrapper::ShowKeyboard()
{
    JNIEnv* env = GetEnv();
    if (!env)
    {
        Log("No env");
        return;
    }

    env->CallVoidMethod(activity, s_showKeyboard);
    EXCEPTION_CHECK(env);
}

void CJavaWrapper::HideKeyboard()
{
    JNIEnv* env = GetEnv();
    if (!env)
    {
        Log("No env");
        return;
    }

    env->CallVoidMethod(activity, s_hideKeyboard);
    EXCEPTION_CHECK(env);
}
