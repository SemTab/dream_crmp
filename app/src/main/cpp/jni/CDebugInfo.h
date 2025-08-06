#pragma once

#include <stdint.h>
#include "game/common.h"

#define DEBUG_INFO_ENABLED

class CDebugInfo
{
	static uint32_t m_uiDrawDebug;
	static uint32_t m_dwSpeedMode;
	static uint32_t m_uiDrawFPS;

	static uint32_t m_dwSpeedStart;

	// Для статистики FPS
	static float m_fMinFPS;
	static float m_fMaxFPS;
	static float m_fFPSTotal;
	static uint32_t m_uiFPSSamples;

public:
	static uint32_t uiStreamedPeds;
	static uint32_t uiStreamedVehicles;
	
	static void ToggleDebugDraw();

	static void SetDrawFPS(uint32_t bDraw);

	static void Draw();
	static void ApplyDebugPatches();

	static void ToggleSpeedMode();
	static void ProcessSpeedMode(VECTOR* pVecSpeed);
};

