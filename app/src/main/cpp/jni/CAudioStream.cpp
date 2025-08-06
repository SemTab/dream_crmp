#include "main.h"
#include "game/game.h"

#include <pthread.h>
#include <mutex>
#include <chrono>
#include <thread>

#include "vendor/bass/bass.h"
#include "CAudioStream.h"

extern CGame* pGame;

CAudioStream::CAudioStream()
{
	m_strAudioStreamURL.clear();

	m_fAudioStreamRadius = -1;
	m_bassStreamSample = NULL;

	m_bUsePosition = false;
	m_bPlaying = false;
	m_bPaused = false;

    memset(&m_vecAudioStreamPosition, 0, sizeof(m_vecAudioStreamPosition));
}

CAudioStream::~CAudioStream()
{
	if (m_bPlaying) Stop();
	m_strAudioStreamURL.clear();
}

// Функция для проверки и исправления URL
std::string CAudioStream::NormalizeURL(const char* url)
{
    std::string result = url;
    
    // Проверяем, есть ли протокол в URL
    if (result.find("://") == std::string::npos)
    {
        // Если нет протокола, добавляем http://
        result = "http://" + result;
        Log("URL normalized: %s", result.c_str());
    }
    
    // Заменяем пробелы на %20
    size_t pos = 0;
    while ((pos = result.find(" ", pos)) != std::string::npos)
    {
        result.replace(pos, 1, "%20");
        pos += 3; // Длина "%20"
    }
    
    return result;
}

bool CAudioStream::PlayByURL(const char* url, float fX, float fY, float fZ, float fRadius, bool bUsePosition)
{
	if (m_bPlaying && m_bassStreamSample)
	{
		if (!Stop())
			return false;
	}

	// Нормализуем URL
	m_strAudioStreamURL = NormalizeURL(url);
	Log("Playing audio stream: %s", m_strAudioStreamURL.c_str());

	m_vecAudioStreamPosition.X = fX;
	m_vecAudioStreamPosition.Y = fY;
	m_vecAudioStreamPosition.Z = fZ;

	m_fAudioStreamRadius = fRadius;
	m_bUsePosition = bUsePosition;

	m_bPaused = false;

	// Создаем поток с флагами BASS_STREAM_AUTOFREE и BASS_STREAM_STATUS
	// BASS_STREAM_AUTOFREE - автоматически освобождает поток при остановке
	// BASS_STREAM_STATUS - получает информацию о статусе сервера
	m_bassStreamSample = BASS_StreamCreateURL(m_strAudioStreamURL.c_str(), 0, 
		BASS_STREAM_AUTOFREE | BASS_STREAM_STATUS, 
		nullptr, nullptr);
	
	if (!m_bassStreamSample)
	{
		// Проверяем ошибку и логируем её
		int errorCode = BASS_ErrorGetCode();
		Log("BASS Error: %d when trying to play URL: %s", errorCode, m_strAudioStreamURL.c_str());
		
		// Пробуем другой метод создания потока без дополнительных флагов
		m_bassStreamSample = BASS_StreamCreateURL(m_strAudioStreamURL.c_str(), 0, 0, nullptr, nullptr);
		if (!m_bassStreamSample)
		{
			errorCode = BASS_ErrorGetCode();
			Log("BASS Second attempt failed: %d", errorCode);
			return false;
		}
	}
	
	// Устанавливаем громкость на максимум
	BASS_ChannelSetAttribute(m_bassStreamSample, BASS_ATTRIB_VOL, 1.0f);
	
	// Начинаем воспроизведение
	if (BASS_ChannelPlay(m_bassStreamSample, true))
	{
		m_bPlaying = true;
		Log("Audio stream started: %s", m_strAudioStreamURL.c_str());
		return true;
	}
	else
	{
		int errorCode = BASS_ErrorGetCode();
		Log("BASS Play failed: %d", errorCode);
		BASS_StreamFree(m_bassStreamSample);
		m_bassStreamSample = NULL;
		return false;
	}
}

bool CAudioStream::Stop()
{
	if (m_bPlaying && m_bassStreamSample)
	{
		// Сначала останавливаем воспроизведение
		BASS_ChannelStop(m_bassStreamSample);
		
		// Затем освобождаем ресурсы
		BASS_StreamFree(m_bassStreamSample);
		m_bassStreamSample = NULL;
		m_bPlaying = false;
		m_bPaused = false;
		
		Log("Audio stream stopped: %s", m_strAudioStreamURL.c_str());
	}
	return true;
}

void CAudioStream::Process()
{
	if (!m_bPlaying || !m_bassStreamSample) return;

	// Проверяем, что поток все еще активен
	if (BASS_ChannelIsActive(m_bassStreamSample) == BASS_ACTIVE_STOPPED)
	{
		// Если поток остановился, пытаемся перезапустить его
		Log("Audio stream stopped unexpectedly, trying to restart: %s", m_strAudioStreamURL.c_str());
		
		// Освобождаем старый поток
		BASS_StreamFree(m_bassStreamSample);
		
		// Создаем новый поток
		m_bassStreamSample = BASS_StreamCreateURL(m_strAudioStreamURL.c_str(), 0, 
			BASS_STREAM_AUTOFREE | BASS_STREAM_STATUS, 
			nullptr, nullptr);
			
		if (m_bassStreamSample)
		{
			// Устанавливаем громкость на максимум
			BASS_ChannelSetAttribute(m_bassStreamSample, BASS_ATTRIB_VOL, 1.0f);
			
			// Начинаем воспроизведение
			if (BASS_ChannelPlay(m_bassStreamSample, false))
			{
				Log("Audio stream restarted successfully");
				m_bPaused = false;
				return;
			}
			else
			{
				int errorCode = BASS_ErrorGetCode();
				Log("Failed to restart audio stream: %d", errorCode);
				m_bassStreamSample = NULL;
				m_bPlaying = false;
				return;
			}
		}
		else
		{
			int errorCode = BASS_ErrorGetCode();
			Log("Failed to recreate audio stream: %d", errorCode);
			m_bassStreamSample = NULL;
			m_bPlaying = false;
			return;
		}
	}

	if (!m_bPaused)
	{
		if (pGame->IsGamePaused())
		{
			if (m_bassStreamSample)
			{
				BASS_ChannelPause(m_bassStreamSample);
				m_bPaused = true;
			}
		}
		else if (m_bUsePosition && (m_fAudioStreamRadius != -1))
		{
			CPlayerPed* pPlayerPed = pGame->FindPlayerPed();
			if (pPlayerPed)
			{
				MATRIX4X4 playerMatrix;
				pPlayerPed->GetMatrix(&playerMatrix);

				if (GetDistanceBetween3DPoints(&m_vecAudioStreamPosition, &playerMatrix.pos) > m_fAudioStreamRadius)
				{
					if (m_bassStreamSample)
					{
						BASS_ChannelPause(m_bassStreamSample);
						m_bPaused = true;
					}
				}
			}
		}
	}
	else
	{
		if (!pGame->IsGamePaused())
		{
			if (m_bassStreamSample)
			{
				BASS_ChannelPlay(m_bassStreamSample, false);
				m_bPaused = false;
			}
		}
		else if (m_bUsePosition && (m_fAudioStreamRadius != -1))
		{
			CPlayerPed* pPlayerPed = pGame->FindPlayerPed();
			if (pPlayerPed)
			{
				MATRIX4X4 playerMatrix;
				pPlayerPed->GetMatrix(&playerMatrix);

				if (GetDistanceBetween3DPoints(&m_vecAudioStreamPosition, &playerMatrix.pos) <= m_fAudioStreamRadius)
				{
					if (m_bassStreamSample)
					{
						BASS_ChannelPlay(m_bassStreamSample, false);
						m_bPaused = false;
					}
				}
			}
		}
	}
}