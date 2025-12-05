#define CUSTOM_AUTH_VERSION			1

#define CUSTOM_AUTH_TEXTDRAW		9999
#define CUSTOM_AUTH_TEXTDRAWVER2	10000

native EncryptAuthCode(code[], lenCode, key[], lenKey);
native DecryptAuthCode(code[], lenCode, key[], lenKey);

/*
stock OnValidPlayerConnected(playerid, szSerial[], szLibraries[])
stock OnInvalidPlayerConnected(playerid)
stock OnInvalidDataIncoming(playerid, system, value, value1)
stock OnValidDataIncoming(playerid, system , value, value1)
*/

#if !defined OnValidPlayerConnected
	#error "Define OnValidPlayerConnected"
#endif

#if !defined OnInvalidPlayerConnected
	#error "Define OnInvalidPlayerConnected"
#endif

#if !defined OnInvalidDataIncoming
	#error "Define OnInvalidDataIncoming"
#endif

#if !defined OnValidDataIncoming
	#error "Define OnValidDataIncoming"
#endif

#define CUSTOM_SYSTEM_PICKUP	0

static const RPC_PickedUpPickup = 131;
static const RPC_ClickTextDraw = 83;
static const RPC_ScrSetSpawnInfo = 68;

static g_bResponseStatus[MAX_PLAYERS];
static g_bResponseTries[MAX_PLAYERS];
static g_bResponseTimer[MAX_PLAYERS];
static g_bSentResponse[MAX_PLAYERS];
static g_iSentCode[MAX_PLAYERS];

new g_iSentCodeVer2[MAX_PLAYERS][8];
new g_iSentKeyVer2[MAX_PLAYERS][4];

new g_iRejectReason[MAX_PLAYERS];
new g_iOldVersion[MAX_PLAYERS];

new auth__debug = false;
new auth__reject_old = true;

forward OnSerialResponseTimeout(playerid, timeout, code);

static CheckRandomValueForValid(value, value1)
{
	if(value == 0 && value1 == 0)
	{
		return false;
	}

	new result = (value & value1);

	if(result != 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

IRPC:RPC_PickedUpPickup(playerid, BitStream:bs)
{
	new index;
	new value = 0x100;
	new value1 = 0x1000;
	BS_ReadValue(bs,
		PR_UINT32, index,
		PR_UINT32, value,
		PR_UINT32, value1);

	if(auth__debug)
	{
		printf("[Custom auth] RPC_PickedUpPickup(%d) %d %d %d", playerid, value, value1, value & value1);
	}

	if(!CheckRandomValueForValid(value, value1))
	{
		OnInvalidDataIncoming(playerid, CUSTOM_SYSTEM_PICKUP, value, value1);
		return true;
	}
	else
	{
		OnValidDataIncoming(playerid, CUSTOM_SYSTEM_PICKUP, value, value1);
		return true;
	}
}

static CheckResponseFromClient(playerid, response, const serial[], codeVer2[])
{
	new codeVer2local[8];
	for(new i = 0; i < 8; i++)
	{
		codeVer2local[i] = codeVer2[i];
	}
	DecryptAuthCode(codeVer2local, 8, g_iSentKeyVer2[playerid], 4);

	for(new i = 0; i < 8; i++)
	{
		if(codeVer2local[i] != g_iSentCodeVer2[playerid][i])
		{
			g_iRejectReason[playerid] = 29283;
			return false;
		}
	}

	new value = 0;
	
	value += serial[0];
	value += serial[1];
	value += serial[2];
	value += serial[3];
	
	if((value % 2) == 0)
	{
		value /= 2;
	}
	else
	{
		value += serial[4];
	}
	
	if(auth__debug)
	{
		printf("[Custom auth] CheckResponseFromClient(%d, %s) %d", response, serial, value);
	}
	
	if(value != response)
	{
		g_iRejectReason[playerid] = 200;
		return false;
	}
	else
	{
		return true;
	}
}

stock ParseSpecialTextDrawRPC(playerid, BitStream:bs, codeVer2[], &response, &code, szSerial[], iSerialSize, szLibs[], iLibsSize)
{
	new length;

    BS_ReadValue(bs,
		PR_UINT32, response,
		PR_UINT32, code);
		
	for(new i = 0; i < 8; i++)
	{
		BS_ReadValue(bs, PR_UINT8, codeVer2[i]);
	}
		
	BS_ReadValue(bs, PR_UINT32, length);

    if(length >= (iSerialSize - 1))
	{
		g_iRejectReason[playerid] = 101;
		
		if(auth__debug)
		{
			printf("[Custom auth] ParseSpecialTextDrawRPC return 1 %d", playerid);
		}
		
		return false;
	}
	
	BS_ReadValue(bs,
		PR_STRING, szSerial, length);
		
 	BS_ReadValue(bs,
		PR_UINT32, length);

    if(length >= (iLibsSize - 1))
	{
		g_iRejectReason[playerid] = 102;
		
		if(auth__debug)
		{
			printf("[Custom auth] ParseSpecialTextDrawRPC return 333");
		}
		
		return false;
	}

	BS_ReadValue(bs,
		PR_STRING, szLibs, length);

	return true;
}

stock ProcessSpecialTextDrawRPC(playerid, BitStream:bs, bnew = 0)
{
    if(auth__debug)
	{
		printf("[Custom auth] ProcessSpecialTextDrawRPC value %d %d %d", playerid, g_bResponseStatus[playerid], g_bSentResponse[playerid]);
	}

    if(g_bResponseStatus[playerid])
	{
	    g_bSentResponse[playerid] = false;
		g_iRejectReason[playerid] = 4;
		
		if(auth__debug)
		{
			printf("[Custom auth] ProcessSpecialTextDrawRPC return 1");
		}
		
		return;
	}

	if(!g_bSentResponse[playerid])
	{
		g_iRejectReason[playerid] = 1;
		
		if(auth__debug)
		{
			printf("[Custom auth] ProcessSpecialTextDrawRPC return 33");
		}
		
	    return;
	}

	if(bnew == 0)
	{
		if(auth__reject_old)
		{
			g_iOldVersion[playerid] = 4;
			return;
		}
		g_iOldVersion[playerid] = 2;
		g_bResponseStatus[playerid] = true;
		g_iRejectReason[playerid] = 228;
		if(auth__debug)
		{
			printf("[Custom auth] %d CALL VALID ON OLD VERSION!!!!!!", playerid);
		}
		OnValidPlayerConnected(playerid, "old version", "old version");
		return;
	}
	else if(bnew == 1)
	{
		g_iOldVersion[playerid] = 0;
	}

	new response;
	new code;
	new szSerial[65];
	new szLibs[256];
	new codeVer2[8];
	if(!ParseSpecialTextDrawRPC(playerid, bs, codeVer2, response, code, szSerial, sizeof(szSerial), szLibs, sizeof(szLibs)))
	{
		g_bResponseStatus[playerid] = false;
		g_iRejectReason[playerid] = 2;
		
		if(auth__debug)
		{
			printf("[Custom auth] ParseSpecialTextDrawRPC false %d", playerid);
		}
		
		return;
	}

	if(code != g_iSentCode[playerid])
	{
		g_bResponseStatus[playerid] = false;
		g_iRejectReason[playerid] = 1200;
		
		if(auth__debug)
		{
			printf("[Custom auth] PReject invalid code %d", playerid);
		}
		
		return;
	}

    if(auth__debug)
	{
		printf("[Custom auth] ProcessSpecialTextDrawRPC code %d %d %d", playerid, code, g_iSentCode[playerid]);
	}

    g_bSentResponse[playerid] = false;

	if(CheckResponseFromClient(playerid, response, szSerial, codeVer2))
	{
		g_bResponseStatus[playerid] = true;
		g_iRejectReason[playerid] = 228;
		if(auth__debug)
		{
			printf("[Custom auth] %d CALL VALID", playerid);
		}
		OnValidPlayerConnected(playerid, szSerial, szLibs);
	}
	else
	{
		if(auth__debug)
		{
			printf("[Custom auth] %d NO CALL VALID", playerid);
		}
		g_iRejectReason[playerid] = 3;
		g_bResponseStatus[playerid] = false;
	}

	if(auth__debug)
	{
		printf("[Custom auth] RPC_ClickTextDraw %d response", g_bResponseStatus[playerid]);
	}
}

IRPC:RPC_ClickTextDraw(playerid, BitStream:bs)
{
	new textdrawId;
	BS_ReadValue(bs, 
		PR_UINT16, textdrawId);
	
	if(auth__debug)
	{
		printf("[Custom auth] RPC_ClickTextDraw(%d, %d) %d", playerid, textdrawId, g_bResponseStatus[playerid]);
	}
	
	if(textdrawId == CUSTOM_AUTH_TEXTDRAW)
	{
		ProcessSpecialTextDrawRPC(playerid, bs);
		return false;
	}
	else if(textdrawId == CUSTOM_AUTH_TEXTDRAWVER2)
	{
		ProcessSpecialTextDrawRPC(playerid, bs, 1);
		return false;
	}
	else
	{
		return true;
	}
}

public OnSerialResponseTimeout(playerid, timeout, code)
{
	if(auth__debug)
	{
		printf("[Custom auth] OnSerialResponseTimeout(%d) %d %d %d %d", playerid, g_bResponseTimer[playerid], g_bResponseTries[playerid], g_bResponseStatus[playerid], timeout);
	}

	g_bResponseTimer[playerid] = -1;
    g_bSentResponse[playerid] = false;

	if(g_iSentCode[playerid] != code)
	{
		if(auth__debug)
		{
			printf("[Custom auth] %d reject timeout 1", playerid);
		}
		return;
	}

    if(!IsPlayerConnected(playerid))
	{
		if(auth__debug)
		{
			printf("[Custom auth] %d reject timeout 23", playerid);
		}
		return;
	}

	if(g_bResponseStatus[playerid])
	{
		if(auth__debug)
		{
			printf("[Custom auth] %d reject timeout 32", playerid);
		}
		return;
	}
	
	if(g_bResponseTries[playerid] > 3)
	{
		if(auth__debug)
		{
			printf("[Custom auth] %d CALL INVALID timeout 1", playerid);
		}
		OnInvalidPlayerConnected(playerid);
		return;
	}
	
	SendValidCheckPlayer(playerid, timeout + 400);
}

static SendValidCheckPlayer(playerid, timeout)
{
    g_iSentCode[playerid] = random(timeout);

	new BitStream:bs = BS_New();

	BS_WriteValue(bs,
		PR_UINT8, 0,
		PR_UINT32, 15,
		PR_UINT8, 0,
		PR_FLOAT, 0.0,
		PR_FLOAT, 0.0,
		PR_FLOAT, 8.0,
		PR_FLOAT, 0.0,
		PR_UINT32, 0,
		PR_UINT32, 0,
		PR_UINT32, 0,
		PR_UINT32, 0,
		PR_UINT32, 0,
		PR_UINT32, 0,
		PR_UINT32, g_iSentCode[playerid]);


	for(new i = 0; i < 8; i++)
	{
		g_iSentCodeVer2[playerid][i] = random(250);
		BS_WriteValue(bs, PR_UINT8, g_iSentCodeVer2[playerid][i]);
	}
	for(new i = 0; i < 4; i++)
	{
		g_iSentKeyVer2[playerid][i] = random(timeout);
		BS_WriteValue(bs, PR_UINT32, g_iSentKeyVer2[playerid][i]);
	}

	/*printf("SENT %d %d %d %d %d %d %d %d key %d %d %d %d", g_iSentCodeVer2[playerid][0], g_iSentCodeVer2[playerid][1], g_iSentCodeVer2[playerid][2], g_iSentCodeVer2[playerid][3],
	g_iSentCodeVer2[playerid][4], g_iSentCodeVer2[playerid][5], g_iSentCodeVer2[playerid][6], g_iSentCodeVer2[playerid][7], g_iSentKeyVer2[playerid][0], g_iSentKeyVer2[playerid][1],
	g_iSentKeyVer2[playerid][2], g_iSentKeyVer2[playerid][3]);*/

	BS_RPC(bs, playerid, RPC_ScrSetSpawnInfo, PR_SYSTEM_PRIORITY, PR_RELIABLE_ORDERED);

	BS_Delete(bs);
	
	g_bResponseTimer[playerid] = SetTimerEx("OnSerialResponseTimeout", timeout, false, "ddd", playerid, timeout, g_iSentCode[playerid]);
	g_bResponseTries[playerid]++;
	g_bSentResponse[playerid] = true;
	
	if(auth__debug)
	{
		printf("[Custom auth] SendValidCheckPlayer(%d) %d %d", playerid, g_bResponseTimer[playerid], g_bResponseTries[playerid]);
	}
}

stock InitialiseClientCheck(playerid)
{
	if(auth__debug)
	{
		printf("[Custom auth] InitialiseClientCheck(%d) ", playerid);
	}
	
	SendValidCheckPlayer(playerid, 400);
}

public OnPlayerConnect(playerid)
{
	g_iRejectReason[playerid] = 1000;
	g_bResponseStatus[playerid] = false;
	g_bResponseTries[playerid] = 0;
	g_bResponseTimer[playerid] = -1;
	g_bSentResponse[playerid] = false;
	g_iSentCode[playerid] = 0;
	g_iOldVersion[playerid] = 228;

	if(auth__debug)
	{
		printf("[Custom auth] OnPlayerConnect(%d) %d %d %d", playerid, g_bResponseStatus[playerid], g_bResponseTries[playerid], g_bResponseTimer[playerid]);
	}

	#if	defined	cauth__OnPlayerConnect
	cauth__OnPlayerConnect(playerid);
	#endif

    return true;
}

#if defined _ALS_OnPlayerConnect
	#undef	OnPlayerConnect
#else
	#define	_ALS_OnPlayerConnect
#endif
#if	defined	cauth__OnPlayerConnect
forward cauth__OnPlayerConnect(playerid);
#endif
#define	OnPlayerConnect	cauth__OnPlayerConnect

public OnPlayerDisconnect(playerid, reason)
{
	g_iRejectReason[playerid] = 1000;
    if(g_bResponseTimer[playerid] != -1)
	{
		KillTimer(g_bResponseTimer[playerid]);
	}

	g_bResponseTimer[playerid] = -1;
	g_bResponseStatus[playerid] = false;
	g_bResponseTries[playerid] = 0;
	g_bSentResponse[playerid] = false;
	g_iSentCode[playerid] = 0;

	if(auth__debug)
	{
		printf("[Custom auth] OnPlayerDisconnect(%d) %d %d %d", playerid, g_bResponseStatus[playerid], g_bResponseTries[playerid], g_bResponseTimer[playerid]);
	}
	
#if	defined	cauth__OnPlayerDisconnect
	cauth__OnPlayerDisconnect(playerid, reason);
#endif

	return true;
}

#if defined _ALS_OnPlayerDisconnect
	#undef	OnPlayerDisconnect
#else
	#define	_ALS_OnPlayerDisconnect
#endif
#if	defined	cauth__OnPlayerDisconnect
forward cauth__OnPlayerDisconnect(playerid, reason);
#endif
#define	OnPlayerDisconnect	cauth__OnPlayerDisconnect
