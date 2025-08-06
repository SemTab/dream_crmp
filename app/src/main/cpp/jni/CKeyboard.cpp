#include "main.h"

#include "keyboardhistory.h"
#include "CJavaWrapper.h"
#include "gui/gui.h"
#include "CLocalisation.h"
#include "game/game.h"
#include "CKeyboard.h"
#include "scrollbar.h"

extern CGUI* pGUI;

CKeyBoard::CKeyBoard()
{
    Log("Initializing KeyBoard stub...");
    m_bEnable = false;
    m_iCase = LOWER_CASE;
    m_iPushedKey = -1;
    m_utf8Input[0] = '\0';
    m_iInputOffset = 0;
    m_bNewKeyboard = false;
    m_pkHistory = nullptr;
    Log("KeyBoard stub initialized");
}

CKeyBoard::~CKeyBoard()
{
    if (m_pkHistory) {
        delete m_pkHistory;
        m_pkHistory = nullptr;
    }
}

void CKeyBoard::Render()
{
    // Пустая реализация
}

void CKeyBoard::Open(keyboard_callback* handler, bool bHiden)
{
    // Пустая реализация
}

void CKeyBoard::Close()
{
    // Пустая реализация
}

bool CKeyBoard::OnTouchEvent(int type, bool multi, int x, int y)
{
    return true;
}

void CKeyBoard::AddCharToInput(char sym)
{
    // Пустая реализация
}

void CKeyBoard::Flush()
{
    // Пустая реализация
}

kbKey* CKeyBoard::GetKeyFromPos(int x, int y)
{
    return nullptr;
}

void CKeyBoard::HandleInput(kbKey &key)
{
    // Пустая реализация
}

void CKeyBoard::DeleteCharFromInput()
{
    // Пустая реализация
}

void CKeyBoard::Send()
{
    // Пустая реализация
}

void CKeyBoard::EnableNewKeyboard()
{
    m_bNewKeyboard = true;
}

void CKeyBoard::EnableOldKeyboard()
{
    m_bNewKeyboard = false;
}

bool CKeyBoard::IsNewKeyboard()
{
    return m_bNewKeyboard;
}

void CKeyBoard::ProcessInputCommands()
{
    // Пустая реализация
}

void CKeyBoard::OnNewKeyboardInput(JNIEnv* pEnv, jobject thiz, jbyteArray str)
{
    // Пустая реализация
}

void CKeyBoard::InitENG()
{
    // Пустая реализация
}

void CKeyBoard::InitRU()
{
    // Пустая реализация
}

void CKeyBoard::InitNUM()
{
    // Пустая реализация
}
