#include "CNumbers.h"

#include "main.h"
#include "gui/gui.h"
#include "game/game.h"
#include "net/netgame.h"
#include "game/RW/RenderWare.h"
#include "CChatWindow.h"
#include "playertags.h"
#include "CDialog.h"
#include "CKeyboard.h"
#include "CSettings.h"
#include "util/armhook.h"
#include "CJavaWrapper.h"

extern CGUI* pGUI;
extern CGame* pGame;
extern CNetGame* pNetGame;
extern CSettings* pSettings;
extern CChatWindow* pChatWindow;

extern "C"
{
    JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_sendCheckGenerateNumber(JNIEnv* pEnv, jobject thiz)
	{
        // pChatWindow->AddDebugMessage(weikton(">> RPC 0x52 -> 0x3 -> SEND"));

        RakNet::BitStream bsSend;
        bsSend.Write((uint8_t)52);
        bsSend.Write((uint8_t)3);

        pNetGame->GetRakClient()->Send(&bsSend, SYSTEM_PRIORITY, RELIABLE_SEQUENCED, 0);
	}
    JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_sendGenerateNumber(JNIEnv* pEnv, jobject thiz)
	{
        // pChatWindow->AddDebugMessage(weikton(">> RPC 0x52 -> 0x4 -> SEND"));

        RakNet::BitStream bsSend;
        bsSend.Write((uint8_t)52);
        bsSend.Write((uint8_t)4);

        pNetGame->GetRakClient()->Send(&bsSend, SYSTEM_PRIORITY, RELIABLE_SEQUENCED, 0);
	}
    JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_sendCheckNumber(JNIEnv *env, jobject thiz, jint type, jstring number, jstring region)
    {
        const char *uNumber = env->GetStringUTFChars(number, nullptr);
        const char *uRegion = env->GetStringUTFChars(region, nullptr);

        RakNet::BitStream bsSend;
        bsSend.Write((uint8_t)52);
        bsSend.Write((uint8_t)5);
        bsSend.Write((uint32_t)type);
        bsSend.Write((uint8_t)strlen(uNumber));
        bsSend.Write(uNumber,strlen(uNumber));
        bsSend.Write((uint8_t)strlen(uRegion));
        bsSend.Write(uRegion,strlen(uRegion));

        pNetGame->GetRakClient()->Send(&bsSend, HIGH_PRIORITY, RELIABLE, 0);

        env->ReleaseStringUTFChars(number, uNumber);
        env->ReleaseStringUTFChars(region, uRegion);
    }
    JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_sendBuyNumber(JNIEnv *env, jobject thiz, jint type, jstring number, jstring region)
    {
        const char *uNumber = env->GetStringUTFChars(number, nullptr);
        const char *uRegion = env->GetStringUTFChars(region, nullptr);

        RakNet::BitStream bsSend;
        bsSend.Write((uint8_t)52);
        bsSend.Write((uint8_t)6);
        bsSend.Write((uint32_t)type);
        bsSend.Write((uint8_t)strlen(uNumber));
        bsSend.Write(uNumber,strlen(uNumber));
        bsSend.Write((uint8_t)strlen(uRegion));
        bsSend.Write(uRegion,strlen(uRegion));

        pNetGame->GetRakClient()->Send(&bsSend, HIGH_PRIORITY, RELIABLE, 0);

        env->ReleaseStringUTFChars(number, uNumber);
        env->ReleaseStringUTFChars(region, uRegion);
    }
}

void CNumbers::Show(int balance)
{
    Log(weikton(">> Called CNumbers::Show(int)"));

    pJava->ShowNumbers(balance);
}

void CNumbers::GenerateNumber(bool status)
{
    Log(weikton(">> Called CNumbers::GenerateNumber(bool)"));

    pJava->GenerateNumber(status);
}

void CNumbers::BuyNumber(bool status)
{
    Log(weikton(">> Called CNumbers::BuyNumber(bool)"));

    pJava->BuyNumber(status);
}



