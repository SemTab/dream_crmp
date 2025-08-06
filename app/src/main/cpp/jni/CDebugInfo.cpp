#include "CDebugInfo.h"

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
#include <sys/sysinfo.h>
#include <unistd.h>
#include "game/vehicle.h"

extern CGUI* pGUI;
extern CGame* pGame;
extern CChatWindow* pChatWindow;
extern CSettings* pSettings;
extern CNetGame* pNetGame;

uint32_t CDebugInfo::uiStreamedPeds = 0;
uint32_t CDebugInfo::uiStreamedVehicles = 0;
uint32_t CDebugInfo::m_uiDrawDebug = 0;
uint32_t CDebugInfo::m_uiDrawFPS = 0;
uint32_t CDebugInfo::m_dwSpeedMode = 0;
uint32_t CDebugInfo::m_dwSpeedStart = 0;

// Для статистики FPS
float CDebugInfo::m_fMinFPS = 9999.0f;
float CDebugInfo::m_fMaxFPS = 0.0f;
float CDebugInfo::m_fFPSTotal = 0.0f;
uint32_t CDebugInfo::m_uiFPSSamples = 0;

void CDebugInfo::ToggleDebugDraw()
{
	m_uiDrawDebug ^= 1;
    
    // Сбросить статистику FPS при активации отладки
    if(m_uiDrawDebug) {
        m_fMinFPS = 9999.0f;
        m_fMaxFPS = 0.0f;
        m_fFPSTotal = 0.0f;
        m_uiFPSSamples = 0;
    }
}

void CDebugInfo::SetDrawFPS(uint32_t bDraw)
{
	m_uiDrawFPS = bDraw;
}

// Функция для получения информации о системной памяти
void GetMemoryInfo(unsigned long* totalRam, unsigned long* freeRam, unsigned long* usedRam)
{
    struct sysinfo memInfo;
    sysinfo(&memInfo);
    
    *totalRam = memInfo.totalram / (1024 * 1024); // В мегабайтах
    *freeRam = memInfo.freeram / (1024 * 1024);   // В мегабайтах
    *usedRam = *totalRam - *freeRam;              // В мегабайтах
}

void CDebugInfo::Draw()
{
	char szStr[256];
	ImVec2 pos;
    char szStrPos[256];
    ImGuiIO& io = ImGui::GetIO();

	if (pSettings->GetReadOnly().iFPSCounter)
	{
		float* pFPS = (float*)(g_libGTASA + 0x608E00);
		snprintf(&szStr[0], 30, "%.1f", *pFPS);
		pos = ImVec2(pGUI->ScaleX(10.0f), pGUI->ScaleY(10.0f));

		pGUI->RenderText(pos, (ImU32)0xFFFFFFFF, true, &szStr[0]);
	}

	if (!m_uiDrawDebug)
	{
		return;
	}
	
	// Размещаем дебаг-информацию внизу экрана
	float screenHeight = io.DisplaySize.y;
	float screenWidth = io.DisplaySize.x;
	
	// Значительно увеличиваем размер отступов и шрифта
	float lineHeight = pGUI->ScaleY(20.0f);  // Увеличиваем высоту строки
	float startX = pGUI->ScaleX(20.0f);      // Больший отступ слева
	float bottomMargin = pGUI->ScaleY(40.0f); // Отступ от нижнего края экрана
	
	// Определяем количество строк для резервирования места
	int totalLines = 0;
	bool hasVehicleInfo = (pGame && pGame->FindPlayerPed() && pGame->FindPlayerPed()->IsInVehicle());
	
	// Базовая информация (позиция, здоровье, fps, архитектура и память)
	totalLines += 7;
	
	// Информация о сервере
	if (pNetGame) totalLines += 2;
	
	// Информация о транспорте
	if (hasVehicleInfo) totalLines += 4;
	
	// Определяем базовую Y-координату для первой строки (начиная снизу вверх)
	float baseY = screenHeight - bottomMargin - (totalLines * lineHeight);
	int line = 0;
	
	// --- SECTION 1: Базовая системная информация (снизу вверх) ---
	
	// --- Информация об архитектуре процессора и памяти ---
	// Память
	struct sysinfo memInfo;
	sysinfo(&memInfo);
	
	long totalVirtualMem = memInfo.totalram;
	totalVirtualMem += memInfo.totalswap;
	totalVirtualMem *= memInfo.mem_unit;
	
	long virtualMemUsed = memInfo.totalram - memInfo.freeram;
	virtualMemUsed += memInfo.totalswap - memInfo.freeswap;
	virtualMemUsed *= memInfo.mem_unit;
	
	snprintf(&szStr[0], 256, "Memory:     %ld MB / %ld MB (%.1f%%)", 
		virtualMemUsed/(1024*1024), totalVirtualMem/(1024*1024), 
		(float)virtualMemUsed*100.0f/(float)totalVirtualMem);
	pos = ImVec2(startX, baseY + lineHeight * line++);
	pGUI->RenderText(pos, (ImU32)0xFFFFFFFF, true, &szStr[0]);
	
	// Архитектура
	#if defined(__arm__)
		#if defined(__ARM_ARCH_7A__)
			snprintf(&szStr[0], 256, "Arch:       ARMv7-A (ARM32)");
		#elif defined(__ARM_ARCH_8A__)
			snprintf(&szStr[0], 256, "Arch:       ARMv8-A (ARM64)");
		#else
			snprintf(&szStr[0], 256, "Arch:       ARM32");
		#endif
	#else
		snprintf(&szStr[0], 256, "Arch:       Unknown");
	#endif
	pos = ImVec2(startX, baseY + lineHeight * line++);
	pGUI->RenderText(pos, (ImU32)0xFFFFFFFF, true, &szStr[0]);
	
	// --- Информация об FPS с отступами ---
	float* pFPS = (float*)(g_libGTASA + 0x608E00);
	float currentFPS = *pFPS;
	
	// Обновляем статистику FPS
	if(currentFPS > 0) {
		m_fMinFPS = (currentFPS < m_fMinFPS) ? currentFPS : m_fMinFPS;
		m_fMaxFPS = (currentFPS > m_fMaxFPS) ? currentFPS : m_fMaxFPS;
		m_fFPSTotal += currentFPS;
		m_uiFPSSamples++;
	}
	
	float avgFPS = (m_uiFPSSamples > 0) ? (m_fFPSTotal / m_uiFPSSamples) : 0;
	
	snprintf(&szStr[0], 256, "FPS:        %.1f   |   Avg: %.1f   |   Min: %.1f   |   Max: %.1f", 
		currentFPS, avgFPS, m_fMinFPS, m_fMaxFPS);
	pos = ImVec2(startX, baseY + lineHeight * line++);
	pGUI->RenderText(pos, (ImU32)0xFFFFFFFF, true, &szStr[0]);
	
	line++; // Пустая строка для разделения
	
	// --- SECTION 2: Информация о сервере ---
	if(pNetGame) {
		// Количество игроков
		int playersCount = 0;
		if(pNetGame->GetPlayerPool()) {
			for(int i = 0; i < MAX_PLAYERS; i++) {
				if(pNetGame->GetPlayerPool()->GetSlotState(i)) {
					playersCount++;
				}
			}
		}
		
		snprintf(&szStr[0], 256, "Players:    %d", playersCount);
		pos = ImVec2(startX, baseY + lineHeight * line++);
		pGUI->RenderText(pos, (ImU32)0xFFFFFFFF, true, &szStr[0]);
		
		line++; // Пустая строка для разделения
	}
	
	// --- SECTION 3: Информация о транспорте ---
	if(pGame && pGame->FindPlayerPed() && pGame->FindPlayerPed()->IsInVehicle()) {
		CVehicle* pVehicle = nullptr;
		CVehiclePool* pVehiclePool = pNetGame->GetVehiclePool();
		CPlayerPed* pPlayerPed = pGame->FindPlayerPed();
		
		VEHICLEID vehicleID = pVehiclePool->FindIDFromGtaPtr(pPlayerPed->GetGtaVehicle());
		if(vehicleID != INVALID_VEHICLE_ID) {
			pVehicle = pVehiclePool->GetAt(vehicleID);
			if(pVehicle) {
				// ID и модель транспорта
				snprintf(&szStr[0], 256, "Vehicle:    ID %d   |   Model: %d", 
					vehicleID, pVehicle->GetModelIndex());
				pos = ImVec2(startX, baseY + lineHeight * line++);
				pGUI->RenderText(pos, (ImU32)0xFFFFFFFF, true, &szStr[0]);
				
				// Скорость
				VECTOR vecMoveSpeed;
				pVehicle->GetMoveSpeedVector(&vecMoveSpeed);
				float speed = sqrt((vecMoveSpeed.X * vecMoveSpeed.X) + 
					(vecMoveSpeed.Y * vecMoveSpeed.Y) + 
					(vecMoveSpeed.Z * vecMoveSpeed.Z)) * 180.0f;
				
				snprintf(&szStr[0], 256, "Speed:      %.1f km/h", speed);
				pos = ImVec2(startX, baseY + lineHeight * line++);
				pGUI->RenderText(pos, (ImU32)0xFFFFFFFF, true, &szStr[0]);
				
				// Топливо, если информация доступна
				if(pGUI->m_fuel > 0) {
					snprintf(&szStr[0], 256, "Fuel:       %d   |   Mileage: %d", 
						pGUI->m_fuel, pGUI->bMeliage);
					pos = ImVec2(startX, baseY + lineHeight * line++);
					pGUI->RenderText(pos, (ImU32)0xFFFFFFFF, true, &szStr[0]);
				}
			}
		}
		
		line++; // Пустая строка для разделения
	}
	
	// --- SECTION 4: Основная информация о позиции (внизу) ---
	if (pGame && pGame->FindPlayerPed() && pGame->FindPlayerPed()->m_pPed) 
	{
		MATRIX4X4 matFromPlayer;
		CPlayerPed *pLocalPlayerPed = pGame->FindPlayerPed();
		pLocalPlayerPed->GetMatrix(&matFromPlayer);

		// Координаты игрока
		snprintf(&szStrPos[0], 256, "Position:   %.2f, %.2f, %.2f", 
			matFromPlayer.pos.X, matFromPlayer.pos.Y, matFromPlayer.pos.Z);
		pos = ImVec2(startX, baseY + lineHeight * line++);
		pGUI->RenderText(pos, (ImU32)0xFFFFFFFF, true, &szStrPos[0]);
		
		// HP и Armor - с отступами для выравнивания
		snprintf(&szStr[0], 256, "Health:     %.1f   |   Armor: %.1f", 
			pLocalPlayerPed->GetHealth(), pLocalPlayerPed->GetArmour());
		pos = ImVec2(startX, baseY + lineHeight * line++);
		pGUI->RenderText(pos, (ImU32)0xFFFFFFFF, true, &szStr[0]);
	}
}

void CDebugInfo::ApplyDebugPatches()
{
#ifdef DEBUG_INFO_ENABLED

	UnFuck(g_libGTASA + 0x008B8018);
	*(uint8_t*)(g_libGTASA + 0x008B8018) = 1;
	NOP(g_libGTASA + 0x00399EDA, 2);
	NOP(g_libGTASA + 0x00399F46, 2);
	NOP(g_libGTASA + 0x00399F92, 2);

#endif
}

void CDebugInfo::ToggleSpeedMode()
{
	m_dwSpeedMode ^= 1;
	if (m_dwSpeedMode)
	{
		pChatWindow->AddDebugMessage("Speed mode enabled");
	}
	else
	{
		pChatWindow->AddDebugMessage("Speed mode disabled");
	}
}

void CDebugInfo::ProcessSpeedMode(VECTOR* pVecSpeed)
{
	if (!m_dwSpeedMode)
	{
		return;
	}
	static uint32_t m_dwState = 0;
	float speed = sqrt((pVecSpeed->X * pVecSpeed->X) + (pVecSpeed->Y * pVecSpeed->Y) + (pVecSpeed->Z * pVecSpeed->Z)) * 2.0f * 100.0f;
	if (speed >= 1.0f)
	{
		if (!m_dwSpeedStart)
		{
			m_dwSpeedStart = GetTickCount();
			m_dwState = 0;
			pChatWindow->AddDebugMessage("Start");
		}
		if ((speed >= 119.0f) && (speed <= 121.0f) && (m_dwState == 0))
		{
			pChatWindow->AddDebugMessage("1 to 100: %d", GetTickCount() - m_dwSpeedStart);
			m_dwSpeedStart = GetTickCount();
			m_dwState = 1;
		}
		if ((speed >= 230.0f) && (speed <= 235.0f) && (m_dwState == 1))
		{
			pChatWindow->AddDebugMessage("100 to 200: %d", GetTickCount() - m_dwSpeedStart);
			m_dwSpeedStart = 0;
			m_dwState = 0;
		}
		// process for 100 and 200
	}
	else
	{
		if (m_dwSpeedStart)
		{
			m_dwSpeedStart = 0;
			m_dwState = 0;
			pChatWindow->AddDebugMessage("Reseted");
			return;
		}
	}
}
