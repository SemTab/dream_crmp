#include "CCustomPlateManager.h"

#include <exception>
#include "../main.h"
#include "../util/armhook.h"
#include "RW/RenderWare.h"
#include "game.h"
#include "..//net/netgame.h"
#include "..//CChatWindow.h"

extern CChatWindow* pChatWindow;
extern CNetGame* pNetGame;

CRenderTarget* CCustomPlateManager::m_pRenderTarget = nullptr;
std::list<SCustomPlate> CCustomPlateManager::m_Plates;

struct CSprite2d* CCustomPlateManager::m_pRuSprite = nullptr;
struct CSprite2d* CCustomPlateManager::m_pUaSprite = nullptr;
struct CSprite2d* CCustomPlateManager::m_pBuSprite = nullptr;
struct CSprite2d* CCustomPlateManager::m_pKzSprite = nullptr;
struct CSprite2d* CCustomPlateManager::m_pRuPoliceSprite = nullptr;
struct CSprite2d* CCustomPlateManager::m_pTaxiSprite = nullptr;
struct CSprite2d* CCustomPlateManager::m_pRuGosSprite = nullptr;
struct CSprite2d* CCustomPlateManager::m_pNoPlateSprite = nullptr;

CFontInstance* CCustomPlateManager::m_pRUFont = nullptr;
CFontInstance* CCustomPlateManager::m_pKZFont = nullptr;
CFontInstance* CCustomPlateManager::m_pUAFont = nullptr;

uint8_t* CCustomPlateManager::m_pBitmap = nullptr;

RwTexture* CCustomPlateManager::ProcessUaPlate(SCustomPlate& plate)
{
	if (!m_pUaSprite)
	{
		return nullptr;
	}
	if (!m_pUaSprite->m_pRwTexture)
	{
		return nullptr;
	}

	memset(m_pBitmap, 0, PLATE_BITMAP_HEIGHT * PLATE_BITMAP_WIDTH);

	int x_max, y_max;
	CFontRenderer::RenderText(plate.szNumber, m_pUAFont, m_pBitmap, PLATE_BITMAP_WIDTH, x_max, y_max);

	for (int i = 0; i < PLATE_BITMAP_WIDTH * PLATE_BITMAP_HEIGHT; i++)
	{
		m_pBitmap[i] = 255 - m_pBitmap[i];
	}

	RwRaster* pTextRaster = GetRWRasterFromBitmap(m_pBitmap + (PLATE_BITMAP_WIDTH * 0), PLATE_BITMAP_WIDTH, 256, 64);

	if (!pTextRaster)
	{
		return nullptr;
	}

	CSprite2d* pText = new CSprite2d();

	if (!pText)
	{
		RwRasterDestroy(pTextRaster);
		return nullptr;
	}

	pText->m_pRwTexture = ((struct RwTexture* (*)(struct RwRaster*))(g_libGTASA + 0x1B1B4C + 1))(pTextRaster); // RwTextureCreate

	CRGBA white;
	white.A = 255;
	white.R = 255;
	white.G = 255;
	white.B = 255;

	m_pRenderTarget->Begin();
	m_pUaSprite->Draw(0.0f, 0.0f, 256.0f, 64.0f, white);
	pText->Draw(36.0f, 8.0f, 210.0f, 42.0f, white);
	RwTexture* pTexture = m_pRenderTarget->End();

	delete pText;

	return pTexture;
}

RwTexture* CCustomPlateManager::ProcessTaxiPlate(SCustomPlate& plate)
{
	if (!m_pTaxiSprite)
	{
		return nullptr;
	}
	if (!m_pTaxiSprite->m_pRwTexture)
	{
		return nullptr;
	}

	// process text
	memset(m_pBitmap, 0, PLATE_BITMAP_HEIGHT * PLATE_BITMAP_WIDTH);

	int x_max, y_max;
	CFontRenderer::RenderText(plate.szNumber, m_pRUFont, m_pBitmap, PLATE_BITMAP_WIDTH, x_max, y_max);

	RwRaster* pTextRaster = GetRWRasterFromBitmapPalette(m_pBitmap + (PLATE_BITMAP_WIDTH * 30), PLATE_BITMAP_WIDTH, 256, 64, 255, 224, 47, 0);

	// process region code
	memset(m_pBitmap, 0, PLATE_BITMAP_HEIGHT * PLATE_BITMAP_WIDTH);
	CFontRenderer::RenderText(plate.szRegion, m_pRUFont, m_pBitmap, PLATE_BITMAP_WIDTH, x_max, y_max);

	RwRaster* pRegionRaster = GetRWRasterFromBitmapPalette(m_pBitmap + (PLATE_BITMAP_WIDTH * 30), PLATE_BITMAP_WIDTH, 128, 64, 255, 224, 47, 0);

	if (!pRegionRaster || !pTextRaster)
	{
		if (pRegionRaster)
		{
			RwRasterDestroy(pRegionRaster);
		}
		if (pTextRaster)
		{
			RwRasterDestroy(pTextRaster);
		}
		return nullptr;
	}

	CSprite2d* pText = new CSprite2d();
	CSprite2d* pRegion = new CSprite2d();

	if (!pText || !pRegion)
	{
		if (pText)
		{
			delete pText;
		}
		if (pRegion)
		{
			delete pRegion;
		}

		RwRasterDestroy(pRegionRaster);
		RwRasterDestroy(pTextRaster);
		return nullptr;
	}

	pText->m_pRwTexture = ((struct RwTexture* (*)(struct RwRaster*))(g_libGTASA + 0x1B1B4C + 1))(pTextRaster); // RwTextureCreate
	pRegion->m_pRwTexture = ((struct RwTexture* (*)(struct RwRaster*))(g_libGTASA + 0x1B1B4C + 1))(pRegionRaster); // RwTextureCreate

	CRGBA white;
	white.A = 255;
	white.R = 255;
	white.G = 255;
	white.B = 255;

	m_pRenderTarget->Begin();
	m_pTaxiSprite->Draw(0.0f, 0.0f, 256.0f, 64.0f, white);
	pText->Draw(22.0f, 10.0f, 160.0f, 40.0f, white);
	pRegion->Draw(206.0f, 14.0f, 38.0f, 20.0f, white);
	RwTexture* pTexture = m_pRenderTarget->End();

	delete pText;
	delete pRegion;

	return pTexture;
}

RwTexture* CCustomPlateManager::ProcessBuPlate(SCustomPlate& plate)
{
	if (!m_pBuSprite)
	{
		return nullptr;
	}
	if (!m_pBuSprite->m_pRwTexture)
	{
		return nullptr;
	}

	memset(m_pBitmap, 0, PLATE_BITMAP_HEIGHT * PLATE_BITMAP_WIDTH);

	int x_max, y_max;
	CFontRenderer::RenderText(plate.szNumber, m_pUAFont, m_pBitmap, PLATE_BITMAP_WIDTH, x_max, y_max);

	for (int i = 0; i < PLATE_BITMAP_WIDTH * PLATE_BITMAP_HEIGHT; i++)
	{
		m_pBitmap[i] = 255 - m_pBitmap[i];
	}

	RwRaster* pTextRaster = GetRWRasterFromBitmap(m_pBitmap + (PLATE_BITMAP_WIDTH * 0), PLATE_BITMAP_WIDTH, 256, 64);

	if (!pTextRaster)
	{
		return nullptr;
	}

	CSprite2d* pText = new CSprite2d();

	if (!pText)
	{
		RwRasterDestroy(pTextRaster);
		return nullptr;
	}

	pText->m_pRwTexture = ((struct RwTexture* (*)(struct RwRaster*))(g_libGTASA + 0x1B1B4C + 1))(pTextRaster); // RwTextureCreate

	CRGBA white;
	white.A = 255;
	white.R = 255;
	white.G = 255;
	white.B = 255;

	m_pRenderTarget->Begin();
	m_pBuSprite->Draw(0.0f, 0.0f, 256.0f, 64.0f, white);
	pText->Draw(41.0f, 8.0f, 210.0f, 42.0f, white);
	RwTexture* pTexture = m_pRenderTarget->End();

	delete pText;

	return pTexture;
}

RwTexture* CCustomPlateManager::ProcessKzPlate(SCustomPlate& plate)
{
	if (!m_pKzSprite)
	{
		return nullptr;
	}
	if (!m_pKzSprite->m_pRwTexture)
	{
		return nullptr;
	}

	// process text
	memset(m_pBitmap, 0, PLATE_BITMAP_HEIGHT * PLATE_BITMAP_WIDTH);

	int x_max, y_max;
	CFontRenderer::RenderText(plate.szNumber, m_pKZFont, m_pBitmap, PLATE_BITMAP_WIDTH, x_max, y_max);

	for (int i = 0; i < PLATE_BITMAP_WIDTH * PLATE_BITMAP_HEIGHT; i++)
	{
		m_pBitmap[i] = 255 - m_pBitmap[i];
	}

	RwRaster* pTextRaster = GetRWRasterFromBitmap(m_pBitmap + (PLATE_BITMAP_WIDTH * 30), PLATE_BITMAP_WIDTH, 256, 64);

	// process region code
	memset(m_pBitmap, 0, PLATE_BITMAP_HEIGHT * PLATE_BITMAP_WIDTH);
	CFontRenderer::RenderText(plate.szRegion, m_pRUFont, m_pBitmap, PLATE_BITMAP_WIDTH, x_max, y_max);
	for (int i = 0; i < PLATE_BITMAP_WIDTH * PLATE_BITMAP_HEIGHT; i++)
	{
		m_pBitmap[i] = 255 - m_pBitmap[i];
	}

	RwRaster* pRegionRaster = GetRWRasterFromBitmap(m_pBitmap + (PLATE_BITMAP_WIDTH * 30), PLATE_BITMAP_WIDTH, 128, 64);

	if (!pRegionRaster || !pTextRaster)
	{
		if (pRegionRaster)
		{
			RwRasterDestroy(pRegionRaster);
		}
		if (pTextRaster)
		{
			RwRasterDestroy(pTextRaster);
		}
		return nullptr;
	}

	CSprite2d* pText = new CSprite2d();
	CSprite2d* pRegion = new CSprite2d();

	if (!pText || !pRegion)
	{
		if (pText)
		{
			delete pText;
		}
		if (pRegion)
		{
			delete pRegion;
		}

		RwRasterDestroy(pRegionRaster);
		RwRasterDestroy(pTextRaster);
		return nullptr;
	}

	pText->m_pRwTexture = ((struct RwTexture* (*)(struct RwRaster*))(g_libGTASA + 0x1B1B4C + 1))(pTextRaster); // RwTextureCreate
	pRegion->m_pRwTexture = ((struct RwTexture* (*)(struct RwRaster*))(g_libGTASA + 0x1B1B4C + 1))(pRegionRaster); // RwTextureCreate

	CRGBA white;
	white.A = 255;
	white.R = 255;
	white.G = 255;
	white.B = 255;

	m_pRenderTarget->Begin();
	m_pKzSprite->Draw(0.0f, 0.0f, 256.0f, 64.0f, white);
	pText->Draw(34.0f, 10.0f, 160.0f, 36.0f, white);
	pRegion->Draw(210.0f, 14.0f, 42.0f, 30.0f, white);
	RwTexture* pTexture = m_pRenderTarget->End();

	delete pText;
	delete pRegion;

	return pTexture;
}

RwTexture* CCustomPlateManager::ProcessRuPolicePlate(SCustomPlate& plate)
{
	if (!m_pRuPoliceSprite)
	{
		return nullptr;
	}
	if (!m_pRuPoliceSprite->m_pRwTexture)
	{
		return nullptr;
	}

	// process text
	memset(m_pBitmap, 0, PLATE_BITMAP_HEIGHT * PLATE_BITMAP_WIDTH);

	int x_max, y_max;
	CFontRenderer::RenderText(plate.szNumber, m_pRUFont, m_pBitmap, PLATE_BITMAP_WIDTH, x_max, y_max);

	RwRaster* pTextRaster = GetRWRasterFromBitmapPalette(m_pBitmap + (PLATE_BITMAP_WIDTH * 30), PLATE_BITMAP_WIDTH, 256, 64, 0, 85, 185, 0);

	// process region code
	memset(m_pBitmap, 0, PLATE_BITMAP_HEIGHT * PLATE_BITMAP_WIDTH);
	CFontRenderer::RenderText(plate.szRegion, m_pRUFont, m_pBitmap, PLATE_BITMAP_WIDTH, x_max, y_max);

	RwRaster* pRegionRaster = GetRWRasterFromBitmapPalette(m_pBitmap + (PLATE_BITMAP_WIDTH * 30), PLATE_BITMAP_WIDTH, 128, 64, 0, 85, 185, 0);

	if (!pRegionRaster || !pTextRaster)
	{
		if (pRegionRaster)
		{
			RwRasterDestroy(pRegionRaster);
		}
		if (pTextRaster)
		{
			RwRasterDestroy(pTextRaster);
		}
		return nullptr;
	}

	CSprite2d* pText = new CSprite2d();
	CSprite2d* pRegion = new CSprite2d();

	if (!pText || !pRegion)
	{
		if (pText)
		{
			delete pText;
		}
		if (pRegion)
		{
			delete pRegion;
		}

		RwRasterDestroy(pRegionRaster);
		RwRasterDestroy(pTextRaster);
		return nullptr;
	}

	pText->m_pRwTexture = ((struct RwTexture* (*)(struct RwRaster*))(g_libGTASA + 0x1B1B4C + 1))(pTextRaster); // RwTextureCreate
	pRegion->m_pRwTexture = ((struct RwTexture* (*)(struct RwRaster*))(g_libGTASA + 0x1B1B4C + 1))(pRegionRaster); // RwTextureCreate

	CRGBA white;
	white.A = 255;
	white.R = 255;
	white.G = 255;
	white.B = 255;

	m_pRenderTarget->Begin();
	m_pRuPoliceSprite->Draw(0.0f, 0.0f, 256.0f, 64.0f, white);
	pText->Draw(22.0f, 10.0f, 160.0f, 40.0f, white);
	pRegion->Draw(206.0f, 14.0f, 38.0f, 20.0f, white);
	RwTexture* pTexture = m_pRenderTarget->End();

	delete pText;
	delete pRegion;

	return pTexture;
}

RwTexture* CCustomPlateManager::ProcessRuPlate(SCustomPlate& plate)
{
	if (!m_pRuSprite)
	{
		return nullptr;
	}
	if (!m_pRuSprite->m_pRwTexture)
	{
		return nullptr;
	}

	// process text
	memset(m_pBitmap, 0, PLATE_BITMAP_HEIGHT * PLATE_BITMAP_WIDTH);

	int x_max, y_max;
	CFontRenderer::RenderText(plate.szNumber, m_pRUFont, m_pBitmap, PLATE_BITMAP_WIDTH, x_max, y_max);

	for (int i = 0; i < PLATE_BITMAP_WIDTH * PLATE_BITMAP_HEIGHT; i++)
	{
		m_pBitmap[i] = 255 - m_pBitmap[i];
	}

	RwRaster* pTextRaster = GetRWRasterFromBitmap(m_pBitmap + (PLATE_BITMAP_WIDTH * 30), PLATE_BITMAP_WIDTH, 256, 64);

	// process region code
	memset(m_pBitmap, 0, PLATE_BITMAP_HEIGHT * PLATE_BITMAP_WIDTH);
	CFontRenderer::RenderText(plate.szRegion, m_pRUFont, m_pBitmap, PLATE_BITMAP_WIDTH, x_max, y_max);
	for (int i = 0; i < PLATE_BITMAP_WIDTH * PLATE_BITMAP_HEIGHT; i++)
	{
		m_pBitmap[i] = 255 - m_pBitmap[i];
	}

	RwRaster* pRegionRaster = GetRWRasterFromBitmap(m_pBitmap + (PLATE_BITMAP_WIDTH * 30), PLATE_BITMAP_WIDTH, 128, 64);

	if (!pRegionRaster || !pTextRaster)
	{
		if (pRegionRaster)
		{
			RwRasterDestroy(pRegionRaster);
		}
		if (pTextRaster)
		{
			RwRasterDestroy(pTextRaster);
		}
		return nullptr;
	}

	CSprite2d* pText = new CSprite2d();
	CSprite2d* pRegion = new CSprite2d();

	if (!pText || !pRegion)
	{
		if (pText)
		{
			delete pText;
		}
		if (pRegion)
		{
			delete pRegion;
		}

		RwRasterDestroy(pRegionRaster);
		RwRasterDestroy(pTextRaster);
		return nullptr;
	}

	pText->m_pRwTexture = ((struct RwTexture* (*)(struct RwRaster*))(g_libGTASA + 0x1B1B4C + 1))(pTextRaster); // RwTextureCreate
	pRegion->m_pRwTexture = ((struct RwTexture* (*)(struct RwRaster*))(g_libGTASA + 0x1B1B4C + 1))(pRegionRaster); // RwTextureCreate

	CRGBA white;
	white.A = 255;
	white.R = 255;
	white.G = 255;
	white.B = 255;

	m_pRenderTarget->Begin();
	m_pRuSprite->Draw(0.0f, 0.0f, 256.0f, 64.0f, white);
	pText->Draw(22.0f, 10.0f, 160.0f, 40.0f, white); // x y width height �����
	pRegion->Draw(206.0f, 14.0f, 38.0f, 20.0f, white); // x y width height ������
	RwTexture* pTexture = m_pRenderTarget->End();

	delete pText;
	delete pRegion;

	return pTexture;
}

RwTexture* CCustomPlateManager::ProcessNoPlatePlate(SCustomPlate& plate)
{
	// Защита от некорректных данных на входе
	if (!m_pNoPlateSprite || !m_pNoPlateSprite->m_pRwTexture || !m_pBitmap || !m_pRUFont)
	{
		return nullptr;
	}

	try {
	// process text
	memset(m_pBitmap, 0, PLATE_BITMAP_HEIGHT * PLATE_BITMAP_WIDTH);

	int x_max, y_max;
		
		// Проверяем, что строка номера не пустая
		if (plate.szNumber && plate.szNumber[0] != '\0') {
	CFontRenderer::RenderText(plate.szNumber, m_pRUFont, m_pBitmap, PLATE_BITMAP_WIDTH, x_max, y_max);

	for (int i = 0; i < PLATE_BITMAP_WIDTH * PLATE_BITMAP_HEIGHT; i++)
	{
		m_pBitmap[i] = 255 - m_pBitmap[i];
			}
	}

	RwRaster* pTextRaster = GetRWRasterFromBitmapPalette(m_pBitmap + (PLATE_BITMAP_WIDTH * 30), PLATE_BITMAP_WIDTH, 256, 64, 0, 0, 0, 0);

	// process region code
	memset(m_pBitmap, 0, PLATE_BITMAP_HEIGHT * PLATE_BITMAP_WIDTH);
		
		// Проверяем, что строка региона не пустая
		if (plate.szRegion && plate.szRegion[0] != '\0') {
	CFontRenderer::RenderText(plate.szRegion, m_pRUFont, m_pBitmap, PLATE_BITMAP_WIDTH, x_max, y_max);
	for (int i = 0; i < PLATE_BITMAP_WIDTH * PLATE_BITMAP_HEIGHT; i++)
	{
		m_pBitmap[i] = 255 - m_pBitmap[i];
			}
	}

	RwRaster* pRegionRaster = GetRWRasterFromBitmapPalette(m_pBitmap + (PLATE_BITMAP_WIDTH * 30), PLATE_BITMAP_WIDTH, 128, 64, 0, 0, 0, 0);


	if (!pRegionRaster || !pTextRaster)
	{
		if (pRegionRaster)
		{
			RwRasterDestroy(pRegionRaster);
		}
		if (pTextRaster)
		{
			RwRasterDestroy(pTextRaster);
		}
		return nullptr;
	}

	CSprite2d* pText = new CSprite2d();
	CSprite2d* pRegion = new CSprite2d();

	if (!pText || !pRegion)
	{
		if (pText)
		{
			delete pText;
		}
		if (pRegion)
		{
			delete pRegion;
		}

		RwRasterDestroy(pRegionRaster);
		RwRasterDestroy(pTextRaster);
		return nullptr;
	}

		// Защита от возможного segfault при получении текстуры
		RwTexture* pTextTexture = nullptr;
		RwTexture* pRegionTexture = nullptr;
		
		try {
			pTextTexture = ((struct RwTexture* (*)(struct RwRaster*))(g_libGTASA + 0x1B1B4C + 1))(pTextRaster);
			pText->m_pRwTexture = pTextTexture;
			
			pRegionTexture = ((struct RwTexture* (*)(struct RwRaster*))(g_libGTASA + 0x1B1B4C + 1))(pRegionRaster);
			pRegion->m_pRwTexture = pRegionTexture;
			
			if (!pText->m_pRwTexture || !pRegion->m_pRwTexture) {
				throw std::exception();
			}
		} catch (...) {
			// Если произошла ошибка, очищаем ресурсы
			if (pText) delete pText;
			if (pRegion) delete pRegion;
			
			if (pTextRaster) RwRasterDestroy(pTextRaster);
			if (pRegionRaster) RwRasterDestroy(pRegionRaster);
			
			return nullptr;
		}

	CRGBA white;
	white.A = 255;
	white.R = 255;
	white.G = 255;
	white.B = 255;

		// Защищаем вызов рендера
		RwTexture* pTexture = nullptr;
		
		try {
			if (m_pRenderTarget) {
	m_pRenderTarget->Begin();
				
				// Проверяем, что все спрайты корректны перед отрисовкой
				if (m_pNoPlateSprite && m_pNoPlateSprite->m_pRwTexture) {
	m_pNoPlateSprite->Draw(0.0f, 0.0f, 256.0f, 64.0f, white);
				}
				
				if (pText && pText->m_pRwTexture) {
					pText->Draw(22.0f, 10.0f, 160.0f, 40.0f, white);
				}
				
				if (pRegion && pRegion->m_pRwTexture) {
					pRegion->Draw(206.0f, 14.0f, 38.0f, 20.0f, white);
				}
				
				pTexture = m_pRenderTarget->End();
			}
		} catch (...) {
			pTexture = nullptr;
		}

		// Очищаем ресурсы
		if (pText) delete pText;
		if (pRegion) delete pRegion;

	return pTexture;
	} catch (...) {
		// Общий перехватчик исключений для предотвращения краша
		return nullptr;
	}
}


RwTexture* CCustomPlateManager::ProcessRuGosPlate(SCustomPlate& plate)
{
	if (!m_pRuGosSprite)
	{
		return nullptr;
	}
	if (!m_pRuGosSprite->m_pRwTexture)
	{
		return nullptr;
	}

	// process text
	memset(m_pBitmap, 0, PLATE_BITMAP_HEIGHT * PLATE_BITMAP_WIDTH);

	int x_max, y_max;
	CFontRenderer::RenderText(plate.szNumber, m_pRUFont, m_pBitmap, PLATE_BITMAP_WIDTH, x_max, y_max);

	RwRaster* pTextRaster = GetRWRasterFromBitmapPalette(m_pBitmap + (PLATE_BITMAP_WIDTH * 30), PLATE_BITMAP_WIDTH, 256, 64, 151, 44, 21, 0);

	// process region code
	memset(m_pBitmap, 0, PLATE_BITMAP_HEIGHT * PLATE_BITMAP_WIDTH);
	CFontRenderer::RenderText(plate.szRegion, m_pRUFont, m_pBitmap, PLATE_BITMAP_WIDTH, x_max, y_max);

	RwRaster* pRegionRaster = GetRWRasterFromBitmapPalette(m_pBitmap + (PLATE_BITMAP_WIDTH * 30), PLATE_BITMAP_WIDTH, 128, 64, 151, 44, 21, 0);

	if (!pRegionRaster || !pTextRaster)
	{
		if (pRegionRaster)
		{
			RwRasterDestroy(pRegionRaster);
		}
		if (pTextRaster)
		{
			RwRasterDestroy(pTextRaster);
		}
		return nullptr;
	}

	CSprite2d* pText = new CSprite2d();
	CSprite2d* pRegion = new CSprite2d();

	if (!pText || !pRegion)
	{
		if (pText)
		{
			delete pText;
		}
		if (pRegion)
		{
			delete pRegion;
		}

		RwRasterDestroy(pRegionRaster);
		RwRasterDestroy(pTextRaster);
		return nullptr;
	}

	pText->m_pRwTexture = ((struct RwTexture* (*)(struct RwRaster*))(g_libGTASA + 0x1B1B4C + 1))(pTextRaster); // RwTextureCreate
	pRegion->m_pRwTexture = ((struct RwTexture* (*)(struct RwRaster*))(g_libGTASA + 0x1B1B4C + 1))(pRegionRaster); // RwTextureCreate

	CRGBA white;
	white.A = 255;
	white.R = 255;
	white.G = 255;
	white.B = 255;

	m_pRenderTarget->Begin();
	m_pRuGosSprite->Draw(0.0f, 0.0f, 256.0f, 64.0f, white);
	pText->Draw(22.0f, 10.0f, 160.0f, 40.0f, white);
	pRegion->Draw(206.0f, 14.0f, 38.0f, 20.0f, white);
	RwTexture* pTexture = m_pRenderTarget->End();

	delete pText;
	delete pRegion;

	return pTexture;
}

void CCustomPlateManager::Initialise()
{
	try {
	char path[0xFF];
	sprintf(path, "%sSAMP/plates/ru_font.ttf", g_pszStorage);

		// Проверяем существование файла перед загрузкой
		FILE* fontFile = fopen(path, "rb");
		if (fontFile) {
			fclose(fontFile);
	m_pRUFont = CFontRenderer::AddFont(path, 128);
	m_pKZFont = CFontRenderer::AddFont(path, 132);
		}
		else {
			m_pRUFont = nullptr;
			m_pKZFont = nullptr;
		}

	sprintf(path, "%sSAMP/plates/ua_font.ttf", g_pszStorage);
		fontFile = fopen(path, "rb");
		if (fontFile) {
			fclose(fontFile);
	m_pUAFont = CFontRenderer::AddFont(path, 68);
		}
		else {
			m_pUAFont = nullptr;
		}

	m_Plates.clear();

	m_pRenderTarget = new CRenderTarget(256, 64, true);

	m_pUaSprite = new CSprite2d();
	m_pRuSprite = new CSprite2d();
	m_pBuSprite = new CSprite2d();
	m_pKzSprite = new CSprite2d();
	m_pRuPoliceSprite = new CSprite2d();
	m_pTaxiSprite = new CSprite2d();
	m_pRuGosSprite = new CSprite2d();
	m_pNoPlateSprite = new CSprite2d();

		// Устанавливаем нулевые указатели на случай неудачной загрузки
		m_pUaSprite->m_pRwTexture = nullptr;
		m_pRuSprite->m_pRwTexture = nullptr;
		m_pBuSprite->m_pRwTexture = nullptr;
		m_pKzSprite->m_pRwTexture = nullptr;
		m_pRuPoliceSprite->m_pRwTexture = nullptr;
		m_pTaxiSprite->m_pRwTexture = nullptr;
		m_pRuGosSprite->m_pRwTexture = nullptr;
		m_pNoPlateSprite->m_pRwTexture = nullptr;
		
		// Загружаем текстуры с проверками
		RwTexture* temp = nullptr;
		
		temp = (RwTexture*)LoadTextureFromDB("samp", "plate_ua");
		if (temp) m_pUaSprite->m_pRwTexture = temp;
		
		temp = (RwTexture*)LoadTextureFromDB("samp", "plate_ru");
		if (temp) m_pRuSprite->m_pRwTexture = temp;
		
		temp = (RwTexture*)LoadTextureFromDB("samp", "plate_bu");
		if (temp) m_pBuSprite->m_pRwTexture = temp;
		
		temp = (RwTexture*)LoadTextureFromDB("samp", "plate_kz");
		if (temp) m_pKzSprite->m_pRwTexture = temp;
		
		temp = (RwTexture*)LoadTextureFromDB("samp", "plate_ru_police");
		if (temp) m_pRuPoliceSprite->m_pRwTexture = temp;
		
		temp = (RwTexture*)LoadTextureFromDB("samp", "plate_taxi");
		if (temp) m_pTaxiSprite->m_pRwTexture = temp;
		
		temp = (RwTexture*)LoadTextureFromDB("samp", "plate_gos");
		if (temp) m_pRuGosSprite->m_pRwTexture = temp;
		
		temp = (RwTexture*)LoadTextureFromDB("txd", "plate_outside");
		if (temp) m_pNoPlateSprite->m_pRwTexture = temp;

		// Выделяем память для битмапа
		try {
	m_pBitmap = new uint8_t[PLATE_BITMAP_HEIGHT * PLATE_BITMAP_WIDTH];
			memset(m_pBitmap, 0, PLATE_BITMAP_HEIGHT * PLATE_BITMAP_WIDTH);
		}
		catch (...) {
			m_pBitmap = nullptr;
		}
	}
	catch (...) {
		// В случае любой ошибки, делаем полную очистку
		Shutdown();
	}
}

void CCustomPlateManager::Shutdown()
{
	if (m_pRenderTarget)
	{
		delete m_pRenderTarget;
		m_pRenderTarget = nullptr;
	}

	if (m_pRuSprite)
	{
		delete m_pRuSprite;
		m_pRuSprite = nullptr;
	}

	if (m_pUaSprite)
	{
		delete m_pUaSprite;
		m_pUaSprite = nullptr;
	}

	if (m_pBuSprite)
	{
		delete m_pBuSprite;
		m_pBuSprite = nullptr;
	}

	if (m_pKzSprite)
	{
		delete m_pKzSprite;
		m_pKzSprite = nullptr;
	}

	if (m_pRuPoliceSprite)
	{
		delete m_pRuPoliceSprite;
		m_pRuPoliceSprite = nullptr;
	}

	if (m_pTaxiSprite)
	{
		delete m_pTaxiSprite;
		m_pTaxiSprite = nullptr;
	}

	if(m_pRuGosSprite)
	{
		delete m_pRuGosSprite;
		m_pRuGosSprite = nullptr;
	}

	if(m_pNoPlateSprite)
	{
		delete m_pNoPlateSprite;
		m_pNoPlateSprite = nullptr;
	}


	if (m_pBitmap)
	{
		delete[] m_pBitmap;
		m_pBitmap = nullptr;
	}

	//  todo: CFont
}

void CCustomPlateManager::PushPlate(uint16_t vehicleId, uint32_t dwType, char* szNumber, char* szRegion)
{
	SCustomPlate plate;
	plate.vehicleId = vehicleId;
	plate.dwType = dwType;
	strncpy(plate.szNumber, szNumber, sizeof(SCustomPlate::szNumber));
	if (szRegion)
	{
		strncpy(plate.szRegion, szRegion, sizeof(SCustomPlate::szRegion));
	}

	m_Plates.push_back(plate);
}

void CCustomPlateManager::Process()
{
	if (!m_pRUFont || !m_pBitmap || !m_pUAFont || !m_pKZFont)
	{
		return;
	}
	if (!m_pRenderTarget)
	{
		return;
	}

	// Ограничиваем количество номеров для обработки за один раз
	const size_t MAX_PLATES_PER_UPDATE = 5;
	size_t processedCount = 0;
	
	// Создаем копию списка для предотвращения проблем с итерацией
	std::list<SCustomPlate> tempPlates;
	
	try {
		// Обрабатываем ограниченное количество номеров
		auto it = m_Plates.begin();
		while (it != m_Plates.end() && processedCount < MAX_PLATES_PER_UPDATE) {
			tempPlates.push_back(*it);
			it = m_Plates.erase(it);
			processedCount++;
		}
		
		for (auto& i : tempPlates)
	{
			// Проверяем корректность типа номера
			if (i.dwType < 1 || i.dwType > 8) {
				continue;
			}
			
			// Проверяем наличие номера
			if (!i.szNumber || i.szNumber[0] == '\0') {
				continue;
			}
			
		RwTexture* pPlate = nullptr;
			try {
		if (i.dwType == 1)
		{
			pPlate = ProcessRuPlate(i);
		}
		else if (i.dwType == 2)
		{
			pPlate = ProcessUaPlate(i);
		}
		else if (i.dwType == 3)
		{
			pPlate = ProcessBuPlate(i);
		}
		else if (i.dwType == 4)
		{
			pPlate = ProcessKzPlate(i);
		}
		else if (i.dwType == 5)
		{
			pPlate = ProcessRuPolicePlate(i);
		}
		else if (i.dwType == 6)
		{
			pPlate = ProcessTaxiPlate(i);
		}	
		else if (i.dwType == 7)
		{
			pPlate = ProcessRuGosPlate(i);
		}
		else if (i.dwType == 8)
		{
			pPlate = ProcessNoPlatePlate(i);
		}	
				
		if (pPlate)
		{
					if (pNetGame && pNetGame->GetVehiclePool())
			{
				if (pNetGame->GetVehiclePool()->GetAt(i.vehicleId))
				{
					pNetGame->GetVehiclePool()->GetAt(i.vehicleId)->ApplyTexture("remap_plate", pPlate);
				}
			}
		}
			} catch (...) {
				// Перехватываем любое исключение при обработке номера
				continue;
	}
		}
		
		// Если остались необработанные номера, сохраняем их на следующую итерацию
		if (m_Plates.size() > MAX_PLATES_PER_UPDATE * 3) {
			// Если очередь слишком большая, очищаем её
	m_Plates.clear();
		}
	} catch (...) {
		// Перехватываем любые исключения и очищаем список номеров
		m_Plates.clear();
	}
}
