#define PARKING_ENTER_POSITION_CAR	212.0076,697.7402,1204.7170,0.5238

#define PARKING_EXIT_DYNAMIC_AREA	212.0076,697.7402,1204.7170



stock create_parking_other_element()
{

	create_dynamic_area(2214.7146,-1967.1420,18.5226, -1, 1, PARKING_ENTER);
	create_dynamic_area(-429.4702,673.4578,11.8583, -1, 2, PARKING_ENTER);

	create_dynamic_area(PARKING_EXIT_DYNAMIC_AREA, VIRTUAL_WORLD_PARKING_1, 1, PARKING_EXIT);
	create_dynamic_area(PARKING_EXIT_DYNAMIC_AREA, VIRTUAL_WORLD_PARKING_2, 2, PARKING_EXIT);

	CreateDynamic3DTextLabel("\
		"cBLUE"Паркинг\n\n\
		"cWH"Для того, чтобы выйти используйте "cBLUE"'ALT'\n\
		"cWH"Для того, чтобы выехать используйте "cBLUE"'гудок'\n\n\
		"cWH"Парковочное место в паркинге позволяет иметь личный транспорт без имущества\n\
		Если парковочное место слетает - воспользоваться транспортов будет невозможно", 
		-1, PARKING_EXIT_DYNAMIC_AREA+1.5, 10.0);

	CreateDynamic3DTextLabel("\
		"cBLUE"Паркинг\n\n\
		"cWH"Для того, чтобы выйти используйте "cBLUE"'ALT'\n\
		"cWH"Для того, чтобы выехать используйте "cBLUE"'гудок'", 
		-1, 2214.7146,-1967.1420,18.5226+1.5, 10.0);
	CreateDynamic3DTextLabel("\
		"cBLUE"Паркинг\n\n\
		"cWH"Для того, чтобы выйти используйте "cBLUE"'ALT'\n\
		"cWH"Для того, чтобы выехать используйте "cBLUE"'гудок'", 
		-1, -429.4702,673.4578,11.8583+1.5, 10.0);


	create_circle_pickup_o(2214.7146,-1967.1420,18.5226, TRIGGER_LRED);
	create_circle_pickup_o(-429.4702,673.4578,11.8583, TRIGGER_LRED);

	create_circle_pickup_o(PARKING_EXIT_DYNAMIC_AREA, TRIGGER_LRED);

	return true;
} 

stock enter_parking(playerid, parking_id)
{
	switch(parking_id)
	{
		case 1: parking_id = VIRTUAL_WORLD_PARKING_1;
		case 2: parking_id = VIRTUAL_WORLD_PARKING_2;
	}

	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		new 
			vehicleid = GetPlayerVehicleID(playerid);

		for(new i; i < MAX_PLAYERS_VEHICLE_SL; i++)
		{
			if(GetPlayerVehicleID(playerid) == vehicle_player_max[playerid][i])
			{	
				SetVehicleVirtualWorld(vehicleid, parking_id);
				SetPlayerVirtualWorld(playerid, parking_id);
				LinkVehicleToInterior(vehicleid, 0);
				SetVehiclePosEx(vehicleid, PARKING_ENTER_POSITION_CAR);

				SetPVarIntNew(playerid, "player_in_parking", parking_id);
			}
			else
			{
				return SendErr(playerid, "Вы должны находиться в личном транспорте!");
			}
		}	
	}
	else
	{
		SetPlayerPosEx(playerid, PARKING_ENTER_POSITION_CAR);
		SetPlayerVirtualWorld(playerid, parking_id);
	}
	return true;
}

stock exit_parking(playerid, parking_id)
{

	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		new 
			vehicleid = GetPlayerVehicleID(playerid);

		SetVehicleVirtualWorld(vehicleid, 0);
		SetPlayerVirtualWorld(playerid, 0);
		LinkVehicleToInterior(vehicleid, 0);

		switch(parking_id)
		{
			case VIRTUAL_WORLD_PARKING_1:
			{
				DeletePVarNew(playerid, "player_in_parking");
				SetVehiclePosEx(vehicleid, 2214.7146,-1967.1420,18.5226,186.9494);	
			}
			case VIRTUAL_WORLD_PARKING_2:
			{
				DeletePVarNew(playerid, "player_in_parking");
				SetVehiclePosEx(vehicleid, -429.4702,673.4578,11.8583,188.0657);	
			}
		}
	}
	else
	{
		switch(parking_id)
		{
			case VIRTUAL_WORLD_PARKING_1:
			{
				SetPlayerVirtualWorld(playerid, 0);
				SetPlayerPosEx(playerid, 2214.7146,-1967.1420,18.5226,186.9494);	
			}
			case VIRTUAL_WORLD_PARKING_2:
			{
				SetPlayerVirtualWorld(playerid, 0);
				SetPlayerPosEx(playerid, -429.4702,673.4578,11.8583,188.0657);	
			}
		}
	}
	return true;
}


stock gen_random_position_parking(playerid)
{
	return random(50);
}

stock gen_random_position_parnew(playerid)
{
	switch(random(100))
	{
		case 0..49:
		{
			pData[playerid][pParkingVehicle] = 1;
			UpdatePlayerData(playerid, "pParkingVehicle", pData[playerid][pParkingVehicle]);
		}
		case 50..99:
		{
			pData[playerid][pParkingVehicle] = 2;
			UpdatePlayerData(playerid, "pParkingVehicle", pData[playerid][pParkingVehicle]);
		}
	}

	return true;
}