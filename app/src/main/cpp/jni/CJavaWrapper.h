#pragma once

#include "main.h"
#include "../CAndroidUtils.h"

#include <jni.h>
#include <string>
#include <android/log.h>

#define LOG_TAG "GRCRA"
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))
#define LOGE(...) ((void)__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__))
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__))

#define EXCEPTION_CHECK(env) \
	if ((env)->ExceptionCheck()) \ 
	{ \
		(env)->ExceptionDescribe(); \
		(env)->ExceptionClear(); \
		return; \
	}

class CJavaWrapper
{
	jobject activity;

	jmethodID s_GetClipboardText;
	jmethodID s_CallLauncherActivity;

	jmethodID s_ShowInputLayout;
	jmethodID s_HideInputLayout;

	jmethodID s_ShowClientSettings;
	jmethodID s_SetUseFullScreen;
	jmethodID s_MakeDialog;

	jmethodID s_showHud;
	jmethodID s_hideHud;
	jmethodID s_updateHudInfo;
	jmethodID s_showNotification;

	jmethodID s_updateLoading;
	jmethodID s_showTabWindow;
	jmethodID s_setTabStat;

	jmethodID s_showSpeed;
	jmethodID s_hideSpeed;
	jmethodID s_updateSpeedInfo;

	jmethodID s_showHudButtonG;
	jmethodID s_hideHudButtonG;

	jmethodID s_setPauseState;

	jmethodID s_ShowAZS;
	jmethodID s_ShowSpawnSelector;
	jmethodID s_ShowCaptcha;
	jmethodID s_ShowNumbers;
	jmethodID s_GenerateNumber;
	jmethodID s_BuyNumber;
	
	jmethodID s_ShowIngameServerSelector;
	jmethodID s_HideIngameServerSelector;
	jmethodID s_UpdateServersList;

	jmethodID s_ShowBoombox;

	jmethodID s_ShowActionsMenu;
	jmethodID s_HideActionsMenu;

	// Методы для работы с чатом
	jmethodID s_showChat;
	jmethodID s_hideChat;
	jmethodID s_addChatMessage;
	jmethodID s_setChatStatus;

	// Методы для работы с клавиатурой
	jmethodID s_showKeyboard;
	jmethodID s_hideKeyboard;

public:
	JNIEnv* GetEnv();

	std::string GetClipboardString();
	void CallLauncherActivity(int type);

	void ShowInputLayout();
	void HideInputLayout();

	void ShowClientSettings();

	void SetUseFullScreen(int b);

	void UpdateHudInfo(int health, int armour, int hunger, int weaponid, int ammo, int ammoinclip, int playerid, int money, int wanted, int level = 1);
	void ShowHud();
	void HideHud();

	void UpdateLoading(int status);

	void UpdateSpeedInfo(int speed, int fuel, int hp, int mileage, int engine, int light, int belt, int lock);
	void ShowSpeed();
	void HideSpeed();

	void MakeDialog(int dialogId, int dialogTypeId, char* caption, char* content, char* leftBtnText, char* rightBtnText);

	void ShowTabWindow();
	void SetTabStat(int id, char* name, int score, int ping);

	void ShowG();
	void HideG();

	void SetPauseState(bool a1);

	CJavaWrapper(JNIEnv* env, jobject activity);
	~CJavaWrapper();

	void ShowNotification(int type, char *text, int duration, char *actionforBtn, char *textBtn);
	void ShowAZS(int fuelId, int maxFuel, float currentFuel, int price, int balance);
	void ShowSpawnSelector(bool isHouse, bool isFraction);
	void ShowCaptcha();
	bool m_bCaptcha;
	void ShowNumbers(int balance);
	void GenerateNumber(bool status);
	void BuyNumber(bool status);
	
	void ShowIngameServerSelector();
	void HideIngameServerSelector();
	void UpdateServersList();
	
	void ShowBoombox();

	void ShowActionsMenu();
	void HideActionsMenu();

	// Методы для работы с чатом
	void ShowChat();
	void HideChat();
	void AddChatMessage(char* message);
	void SetChatStatus(int status);
	
	// Методы для работы с клавиатурой
	void ShowKeyboard();
	void HideKeyboard();

	bool m_bGPS = false, m_bGreenZone = false;
};

extern CJavaWrapper* pJava;