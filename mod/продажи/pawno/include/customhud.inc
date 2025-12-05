#define CUSTOM_RPC_TOGGLE_HUD_ELEMENT   0x1
#define PACKET_CUSTOMRPC    			251
			
#define HUD_ELEMENT_HIDE				0
#define HUD_ELEMENT_SHOW				1
			
#define HUD_ELEMENT_CHAT    			0
#define HUD_ELEMENT_MAP     			1
#define HUD_ELEMENT_TAGS    			2
#define HUD_ELEMENT_BUTTONS 			3 // ВСЕ АБСОЛЮТНО КНОПКИ
#define HUD_ELEMENT_HUD     			4
#define HUD_ELEMENT_VOICE				5
#define HUD_ELEMENT_TEXTLABELS			6

#define MAX_STREAM_SOURCES				1000
			
#define RPC_STREAM_CREATE				0x2
#define RPC_STREAM_POS					0x3
#define RPC_STREAM_DESTROY				0x4
#define RPC_STREAM_INDIVIDUAL			0x5
#define RPC_STREAM_VOLUME				0x6
#define RPC_STREAM_ISENABLED			0x7
#define RPC_OPEN_LINK					0x8
#define RPC_TIMEOUT_CHAT 				0x9
#define RPC_OPEN_SETTINGS				0x15
#define RPC_CUSTOM_SET_LEVEL 			0x26

enum E_STREAM_SOURCE
{
	eStreamID,
	eStreamIsFree,
	Float:eStreamPos[3],
	eStreamInt,
	eStreamVirtualWorld,
	Float:eStreamDistance,
	szUrl[255]
};

static g_aStreamSources[MAX_STREAM_SOURCES][E_STREAM_SOURCE];

stock InitStreamSources()
{
	for(new i = 0; i < MAX_STREAM_SOURCES; i++)
	{
		g_aStreamSources[i][eStreamID] = -1;
		g_aStreamSources[i][eStreamIsFree] = 1;
	}
	print("[STREAM SOURCES] Initialized...");
	return true;
}

stock PlayerPlayStream(playerid, url[])
{
	new BitStream:bitstream = BS_New();
	BS_WriteValue(bitstream, PR_UINT8, PACKET_CUSTOMRPC);
	BS_WriteValue(bitstream, PR_UINT32, RPC_STREAM_INDIVIDUAL);
	
	BS_WriteValue(bitstream, PR_UINT8, strlen(url));
	BS_WriteValue(bitstream, PR_STRING, url);
	
	BS_Send(bitstream, playerid);

	BS_Delete(bitstream);
	return true;
}

stock CreateAllStreamSourcesForPlayer(playerid)
{
	for(new i = 0; i < MAX_STREAM_SOURCES; i++)
	{
		if(!g_aStreamSources[i][eStreamIsFree])
		{
			new BitStream:bitstream = BS_New();
			BS_WriteValue(bitstream, PR_UINT8, PACKET_CUSTOMRPC);
			BS_WriteValue(bitstream, PR_UINT32, RPC_STREAM_CREATE);
			
			BS_WriteValue(bitstream, PR_UINT16, g_aStreamSources[i][eStreamID]);
			BS_WriteValue(bitstream, PR_FLOAT, g_aStreamSources[i][eStreamPos][0]);
			BS_WriteValue(bitstream, PR_FLOAT, g_aStreamSources[i][eStreamPos][1]);
			BS_WriteValue(bitstream, PR_FLOAT, g_aStreamSources[i][eStreamPos][2]);
			BS_WriteValue(bitstream, PR_FLOAT, g_aStreamSources[i][eStreamDistance]);
			BS_WriteValue(bitstream, PR_UINT16, g_aStreamSources[i][eStreamInt]);
			BS_WriteValue(bitstream, PR_UINT16, g_aStreamSources[i][eStreamVirtualWorld]);
			BS_WriteValue(bitstream, PR_UINT8, strlen(g_aStreamSources[i][szUrl]));
			BS_WriteValue(bitstream, PR_STRING, g_aStreamSources[i][szUrl]);

			BS_Send(bitstream, playerid, PR_HIGH_PRIORITY, PR_RELIABLE);

			BS_Delete(bitstream);
		}
	}
	return true;
}

stock CreateStreamSourcesForPlayer(playerid)
{
	for(new i = 0; i < MAX_STREAM_SOURCES; i++)
	{
		if(!g_aStreamSources[i][eStreamIsFree])
		{
			new BitStream:bitstream = BS_New();
			BS_WriteValue(bitstream, PR_UINT8, PACKET_CUSTOMRPC);
			BS_WriteValue(bitstream, PR_UINT32, RPC_STREAM_CREATE);
			
			BS_WriteValue(bitstream, PR_UINT16, g_aStreamSources[i][eStreamID]);
			BS_WriteValue(bitstream, PR_FLOAT, g_aStreamSources[i][eStreamPos][0]);
			BS_WriteValue(bitstream, PR_FLOAT, g_aStreamSources[i][eStreamPos][1]);
			BS_WriteValue(bitstream, PR_FLOAT, g_aStreamSources[i][eStreamPos][2]);
			BS_WriteValue(bitstream, PR_FLOAT, g_aStreamSources[i][eStreamDistance]);

			BS_Send(bitstream, playerid, PR_HIGH_PRIORITY, PR_RELIABLE);

			BS_Delete(bitstream);
		}
	}
	return true;
}


stock update_sound_stream(playerid, stream_id)
{
	new BitStream:bitstream = BS_New();
	BS_WriteValue(bitstream, PR_UINT8, PACKET_CUSTOMRPC);
	BS_WriteValue(bitstream, PR_UINT32, RPC_STREAM_CREATE);
	
	BS_WriteValue(bitstream, PR_UINT16, g_aStreamSources[stream_id][eStreamID]);
	BS_WriteValue(bitstream, PR_FLOAT, g_aStreamSources[stream_id][eStreamPos][0]);
	BS_WriteValue(bitstream, PR_FLOAT, g_aStreamSources[stream_id][eStreamPos][1]);
	BS_WriteValue(bitstream, PR_FLOAT, g_aStreamSources[stream_id][eStreamPos][2]);

	BS_Send(bitstream, playerid, PR_HIGH_PRIORITY, PR_RELIABLE);

	BS_Delete(bitstream);

	return true;
}

stock CreateStreamSource(Float:fPosX, Float:fPosY, Float:fPosZ, Float:fDistance, iInt, iVirtualWorld, url[])
{
	for(new i = 0; i < MAX_STREAM_SOURCES; i++)
	{
		if(g_aStreamSources[i][eStreamIsFree])
		{
			g_aStreamSources[i][eStreamID] = i;
			g_aStreamSources[i][eStreamIsFree] = 0;
			
			g_aStreamSources[i][eStreamPos][0] = fPosX;
			g_aStreamSources[i][eStreamPos][1] = fPosY;
			g_aStreamSources[i][eStreamPos][2] = fPosZ;
			
			g_aStreamSources[i][eStreamDistance] = fDistance;
			
			g_aStreamSources[i][eStreamInt] = iInt;
			g_aStreamSources[i][eStreamVirtualWorld] = iVirtualWorld;
			
			format(g_aStreamSources[i][szUrl], 255, "%s", url);
			
			new BitStream:bitstream = BS_New();
			BS_WriteValue(bitstream, PR_UINT8, PACKET_CUSTOMRPC);
			BS_WriteValue(bitstream, PR_UINT32, RPC_STREAM_CREATE);
			
			BS_WriteValue(bitstream, PR_UINT16, i);
			BS_WriteValue(bitstream, PR_FLOAT, fPosX);
			BS_WriteValue(bitstream, PR_FLOAT, fPosY);
			BS_WriteValue(bitstream, PR_FLOAT, fPosZ);
			BS_WriteValue(bitstream, PR_FLOAT, fDistance);
			BS_WriteValue(bitstream, PR_UINT16, iInt);
			BS_WriteValue(bitstream, PR_UINT16, iVirtualWorld);
			BS_WriteValue(bitstream, PR_UINT8, strlen(url));
			BS_WriteValue(bitstream, PR_STRING, url);

			BS_Send(bitstream, -1, PR_HIGH_PRIORITY, PR_RELIABLE);

			BS_Delete(bitstream);

			printf("AUDIO_STREAM_ID: %d | URL: %s | DIST: %f", i, url, fDistance);
			
			return i;
		}
	}
	return -1;
}

stock SetStreamPos(iID, Float:fPosX, Float:fPosY, Float:fPosZ)
{
	new BitStream:bitstream = BS_New();
	BS_WriteValue(bitstream, PR_UINT8, PACKET_CUSTOMRPC);
	BS_WriteValue(bitstream, PR_UINT32, RPC_STREAM_POS);

	g_aStreamSources[iID][eStreamPos][0] = fPosX;
	g_aStreamSources[iID][eStreamPos][1] = fPosY;
	g_aStreamSources[iID][eStreamPos][2] = fPosZ;
	
	BS_WriteValue(bitstream, PR_UINT16, iID);
	BS_WriteValue(bitstream, PR_FLOAT, fPosX);
	BS_WriteValue(bitstream, PR_FLOAT, fPosY);
	BS_WriteValue(bitstream, PR_FLOAT, fPosZ);

	BS_Send(bitstream, -1, PR_HIGH_PRIORITY, PR_RELIABLE);

	BS_Delete(bitstream);

	return true;
}

stock DestroyStreamSource(iID)
{
	g_aStreamSources[iID][eStreamIsFree] = 1;
	SendCustomRPC(-1, RPC_STREAM_DESTROY, iID);
}

stock SetStreamSourceVolume(iID, Float:fVolume)
{
	new BitStream:bitstream = BS_New();
	BS_WriteValue(bitstream, PR_UINT8, PACKET_CUSTOMRPC);
	BS_WriteValue(bitstream, PR_UINT32, RPC_STREAM_VOLUME);
	
	BS_WriteValue(bitstream, PR_UINT16, iID);
	BS_WriteValue(bitstream, PR_FLOAT, fVolume);

	BS_Send(bitstream, -1, PR_HIGH_PRIORITY, PR_RELIABLE);

	BS_Delete(bitstream);
}

stock SetStreamEnabledForPlayer(playerid, isEnabled)
{
	SendCustomRPC(playerid, RPC_STREAM_ISENABLED, isEnabled);
}

stock SetTimeoutChatDissappearTime(playerid, startTime, endTime)
{
	if(pData[playerid][pSettings][12] == 1)
	{
		SendCustomRPC(playerid, RPC_TIMEOUT_CHAT, startTime, endTime);
	}
}

stock ShowPlayerClientSettings(playerid)
{
	SendCustomRPC(playerid, RPC_OPEN_SETTINGS);

	return true;
}

stock OpenLinkForPlayer(playerid, const szLink[])
{
    new BitStream:bitstream = BS_New();
    BS_WriteValue(bitstream, PR_UINT8, PACKET_CUSTOMRPC);
    BS_WriteValue(bitstream, PR_UINT32, RPC_OPEN_LINK);
            
    BS_WriteValue(bitstream, PR_UINT16, strlen(szLink));
    BS_WriteValue(bitstream, PR_STRING, szLink);

    BS_Send(bitstream, playerid);

    BS_Delete(bitstream);
}

stock SendCustomRPC(playerid, rpcid, ...)
{
    new BitStream:bitstream = BS_New();
    BS_WriteValue(bitstream, PR_UINT8, PACKET_CUSTOMRPC);
	BS_WriteValue(bitstream, PR_UINT32, rpcid);
    for (new i = 0; i < numargs()-2; ++i)
    {
        BS_WriteValue(bitstream, PR_UINT32, getarg(i+2));
    }

    BS_Send(bitstream, playerid, PR_HIGH_PRIORITY, PR_RELIABLE);

	BS_Delete(bitstream);
}

stock SendCustomRPC_Float(playerid, rpcid, ...)
{
    new BitStream:bitstream = BS_New();
    BS_WriteValue(bitstream, PR_UINT8, PACKET_CUSTOMRPC);
	BS_WriteValue(bitstream, PR_UINT32, rpcid);
    for (new i = 0; i < numargs()-2; ++i)
    {
        BS_WriteValue(bitstream, PR_FLOAT, getarg(i+2));
    }

    BS_Send(bitstream, playerid, PR_HIGH_PRIORITY, PR_RELIABLE);

	BS_Delete(bitstream);
}

stock TogglePlayerHudElement(playerid, hudid, value)
{
    SendCustomRPC(playerid, CUSTOM_RPC_TOGGLE_HUD_ELEMENT, hudid, value);
}

stock TogglePlayerAllHudElements(playerid, value)
{
	for(new i = 0; i < 7; i++)
	{
		SendCustomRPC(playerid, CUSTOM_RPC_TOGGLE_HUD_ELEMENT, i, value);
	}
}

stock SetLevelProgresss(playerid, current, max)
{
	new BitStream:bitstream = BS_New();
	BS_WriteValue(bitstream, PR_UINT8, PACKET_CUSTOMRPC);
	BS_WriteValue(bitstream, PR_UINT32, RPC_CUSTOM_SET_LEVEL);
 
	BS_WriteValue(bitstream, PR_UINT8, current);
	BS_WriteValue(bitstream, PR_UINT8, max);
 
	BS_Send(bitstream, playerid, PR_HIGH_PRIORITY, PR_RELIABLE);
 
	BS_Delete(bitstream);
 
	return 1;
}