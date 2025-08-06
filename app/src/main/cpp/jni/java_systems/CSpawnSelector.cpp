#include "CSpawnSelector.h"

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
    JNIEXPORT void JNICALL Java_com_nvidia_devtech_NvEventQueueActivity_spawnPlayer(JNIEnv* pEnv, jobject thiz, jint spawnId)
	{
        // pChatWindow->AddDebugMessage(weikton(">> RPC 0x52 -> 0x2 -> SEND (item: %d)"), spawnId);

        RakNet::BitStream bsSend;
        bsSend.Write((uint8_t)52);
        bsSend.Write((uint8_t)2);
        bsSend.Write((uint32_t) spawnId);

        pNetGame->GetRakClient()->Send(&bsSend, SYSTEM_PRIORITY, RELIABLE_SEQUENCED, 0);
	}
}

void CSpawnSelector::Show(int home, int fraction)
{
    Log(weikton(">> Called CSpawnSelector::Show(int,int)"));

    pJava->ShowSpawnSelector(home, fraction);
}



