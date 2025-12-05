#define PACKET_CUSTOMRPC  251
			
#define RPC_AZS  0x35
#define RPC_SPAWN_SELECT  0x36
#define RPC_GREENZONE_VIEW  0x37
#define RPC_GPS_VIEW  0x38
#define RPC_CAPTCHA	 0x39

stock WN_showAZS(playerid, fuelId, maxFuel, currentFuel, price, balance)
{
	// tYPES: 
	// 0 - 92
    // 1 - 95 
	// 2 - 98
	// 3 - DT \ Electro

    SendCustomRPC(playerid, RPC_AZS, fuelId, maxFuel, currentFuel, price, balance);
}

stock WN_showSelectSpawn(playerid, isHome, isFraction)
{
    SendCustomRPC(playerid, RPC_SPAWN_SELECT, isHome, isFraction);
}

stock WN_showGreenZone(playerid, value)
{
	// 1 - SHOW
    // 2 - HIDE

    SendCustomRPC(playerid, RPC_GREENZONE_VIEW, value);
}
stock WN_showGPS(playerid, value)
{
	// 1 - SHOW
    // 2 - HIDE

    if(value == 1)
        handleGPS(playerid);

    SendCustomRPC(playerid, RPC_GPS_VIEW, value);
}

stock WN_showCaptcha(playerid)
{
    SendCustomRPC(playerid, RPC_CAPTCHA);
}