#define ATTACHED_TRAILER 	0
#define DEATTACHED_TRAILER 	1

forward OnPlayerAttachTrailer(playerid, vehicleid, trailerid, status);

new opat_PlayerVehicleID[MAX_PLAYERS],
	opat_PlayerState[MAX_PLAYERS],
	opat_VehicleInfoTrailer[MAX_VEHICLES];

stock opat_OnPlayerUpdate(playerid) {
	if(opat_PlayerVehicleID[playerid] != -1 && opat_PlayerState[playerid] == PLAYER_STATE_DRIVER) {
		if(opat_VehicleInfoTrailer[ opat_PlayerVehicleID[playerid] ] == 0) {
			if(GetVehicleTrailer(opat_PlayerVehicleID[playerid]) != 0) {
				opat_VehicleInfoTrailer[ opat_PlayerVehicleID[playerid] ] = GetVehicleTrailer(opat_PlayerVehicleID[playerid]);
				CallRemoteFunction("OnPlayerAttachTrailer", "iiii", playerid, opat_PlayerVehicleID[playerid], opat_VehicleInfoTrailer[ opat_PlayerVehicleID[playerid] ], ATTACHED_TRAILER);
			}
		} else {
			if(GetVehicleTrailer(opat_PlayerVehicleID[playerid]) == 0) {
				CallRemoteFunction("OnPlayerAttachTrailer", "iiii", playerid, opat_PlayerVehicleID[playerid], opat_VehicleInfoTrailer[ opat_PlayerVehicleID[playerid] ], DEATTACHED_TRAILER);
				opat_VehicleInfoTrailer[ opat_PlayerVehicleID[playerid] ] = 0;
			}
		}
	}
	return 1;
}

stock opat_OnPlayerStateChange(playerid, newstate, oldstate) {
	opat_PlayerState[playerid] = newstate;
	if(newstate == PLAYER_STATE_DRIVER || newstate == PLAYER_STATE_PASSENGER) {
		if(oldstate == PLAYER_STATE_ONFOOT) {
			opat_PlayerVehicleID[playerid] = GetPlayerVehicleID(playerid);
			opat_VehicleInfoTrailer[ opat_PlayerVehicleID[playerid] ] = GetVehicleTrailer(opat_PlayerVehicleID[playerid]);
		}
	}

	if(newstate == PLAYER_STATE_ONFOOT) {
		if(oldstate == PLAYER_STATE_DRIVER || oldstate == PLAYER_STATE_PASSENGER) {
			opat_PlayerVehicleID[playerid] = -1;
		}
	}
	return 1;
}

stock opat_OnPlayerConnect(playerid) {
	opat_PlayerVehicleID[playerid] = -1;
	return 1;
}