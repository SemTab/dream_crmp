#include "CAZS.h"

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
	JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_refuelTheCar(JNIEnv* pEnv, jobject thiz, jint fuel, jint price)
	{
        // pChatWindow->AddDebugMessage(weikton(">> RPC 0x52 -> 0x1 -> SEND (Fuel: %d, Price: %d)"), fuel, price);

        RakNet::BitStream bsSend;
        bsSend.Write((uint8_t)52);
        bsSend.Write((uint8_t)1);
        bsSend.Write((uint32_t)fuel);
        bsSend.Write((uint32_t)price);

        pNetGame->GetRakClient()->Send(&bsSend, SYSTEM_PRIORITY, RELIABLE_SEQUENCED, 0);
	}
}

void CAZS::Show(int fuelId, int maxFuel, float currentFuel, int price, int balance)
{
    Log(weikton(">> Called CAZS::Show(int,int,int,int,int)"));

    if(fuelId <= 5)
	    pJava->ShowAZS(fuelId, maxFuel, currentFuel, price, balance);
    else
        Log(weikton(">> Called CAZS::Show terminated with reason: incorrect type of fuel"));
}



