stock load_trucker(playerid, type, time)
{
	new 
		vehicleid = GetPlayerVehicleID(playerid);

	if(GetVehicleModel(vehicleid) != TRUCKER_VEH_ID_1 && 
		GetVehicleModel(vehicleid) != TRUCKER_VEH_ID_2 && GetVehicleModel(vehicleid) != 456)
		return SendErr(playerid, "Вы должны находиться в тягаче!");

	if(GetVehicleModel(vehicleid) != 456)
	{
		truck_vehicle[playerid] = vehicleid;

		if(truck_trailer[playerid] != INVALID_VEHICLE_ID)
		{
			DestroyVehicle(truck_trailer[playerid]);
			truck_trailer[playerid] = INVALID_VEHICLE_ID;
		}

		new 
			trailer;

		switch(type)
		{
			case 1: trailer = TRUCKER_TRAILER_ID_3;
			case 3: trailer = TRUCKER_TRAILER_ID_4;
			case 4:	trailer = TRUCKER_TRAILER_ID_2;
			default: trailer = TRUCKER_TRAILER_ID_1;
		}

		SetPVarIntNew(playerid, "type_load_trucker", type+1);

		truck_trailer[playerid] = CreateVehicle(trailer, 803.91, 765.45, 1202.99, 0.0, 1, 1, 5000);
		SetVehicleVirtualWorld(truck_trailer[playerid], playerid+1);

		if(truck_text[playerid] != Text3D:INVALID_3DTEXT_ID) 
			DestroyDynamic3DTextLabelEx(truck_text[playerid]);

		new 
			trans_text[32];

		switch(pData[playerid][pTrucker])// НА ТК ПРОВЕРКА
		{
			case 0: trans_text = "Деловые Линии";
			case 1: trans_text = "ЭйрТрансс";
			case 2: trans_text = "EMS Почта России";
		}

		format(String144,sizeof(String144),""cBLUE"Груз\n\
			"cGREY"Водитель: "cBLUE"%s\n\
			"cGREY"Компания: "cBLUE"%s", pData[playerid][pNickname], trans_text);

		truck_text[playerid] = CreateDynamic3DTextLabel(String144,CWHITE,0.0,0.0,2.0,10.0,INVALID_PLAYER_ID,truck_trailer[playerid]);
	}

	SetPVarIntNew(playerid, "type_load_trucker", type+1);
	
	truck_vehicle[playerid] = vehicleid;

	SetVehiclePos(vehicleid,803.71, 773.74, 1202.08);
	SetVehicleZAngle(vehicleid, 0.0);
	SetVehicleVirtualWorld(vehicleid, playerid+1);
	SetPlayerVirtualWorld(playerid, playerid+1);

	SetPlayerInterior(playerid, 0);
	LinkVehicleToInterior(vehicleid, 0);

	InterpolateCameraPos(playerid, 803.355651, 763.453552, 1210.369018, 803.369873, 796.450805, 1204.884277, 4000);

	InterpolateCameraLookAt(playerid, 803.360900, 768.189025, 1208.764282, 803.451538, 791.508728, 1204.130004, 4000);

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_work_15", 5000);

	RemovePlayerFromVehicle(playerid);

	GameTextForPlayer(playerid,"~y~3a™pyџka",5000,1);
	TogglePlayerControllable(playerid, 0);

	SetTimerEx("load_trucker_final", time, false, "i", playerid);
	SetTimerEx("AttachTrailerToVehicleEx",3000,false,"ii",truck_trailer[playerid],vehicleid);

	return true;
}

callback:: load_trucker_final(playerid)
{
	end_load_trucker(playerid);
	return true;
}

stock end_load_trucker(playerid)
{
	new 
		 vehicleid = truck_vehicle[playerid];

	final_load_gruz_trucker_2(playerid);
	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_RIGHT, "brilliantother:info_gui_trucker_load", 4500);
	visual_trucker_load_gruz_final(playerid);

	PutPlayerInVehicleEx(playerid, vehicleid, 0);
	TogglePlayerControllable(playerid, 1);

	SetVehicleVirtualWorld(vehicleid, 0);
	SetPlayerVirtualWorld(playerid, 0);
	SetVehicleVirtualWorld(truck_trailer[playerid], 0);

	new 
		type = GetPVarIntNew(playerid, "type_load_trucker")-1,
		rand = random(3);
 
	DeletePVarNew(playerid, "type_load_trucker");

	SetVehiclePos(vehicleid, trucker_end_load_pos[type][rand][0], trucker_end_load_pos[type][rand][1], trucker_end_load_pos[type][rand][2]);
	SetVehicleZAngle(vehicleid, trucker_end_load_pos[type][rand][3]);

	if(GetVehicleModel(vehicleid) != 456)
	{
		SetVehiclePos(truck_trailer[playerid], trailer_end_load_pos[type][rand][0],  trailer_end_load_pos[type][rand][1],  trailer_end_load_pos[type][rand][2]);
		SetVehicleZAngle(truck_trailer[playerid], trailer_end_load_pos[type][rand][3]);

		AttachTrailerToVehicle(truck_trailer[playerid], vehicleid);
	}

	GameTextForPlayer(playerid,"~y~3a™pyџka~n~\
		~w~3aўepҐe®a",5000,1);
	return true;
}

stock unload_trucker(playerid)
{
	new vehicleid = GetPlayerVehicleID(playerid);

	if(GetVehicleModel(vehicleid) != 456)
	{
		if(!IsTrailerAttachedToVehicle(vehicleid))
		{
			DeletePVarNew(playerid, "type_job_trucker");
			DeletePVarNew(playerid, "trucker_load_miner");
			DeletePVarNew(playerid, "trucker_load_zavod");
			DeletePVarNew(playerid, "trucker_load_shop");
			DeletePVarNew(playerid, "trucker_load_fill_1");
			DeletePVarNew(playerid, "trucker_load_fill_2");
			DeletePVarNew(playerid, "trucker_load_samwill");
			DeletePVarNew(playerid, "player_load_trucker");

			destroy_truck_trailer(playerid);
			truck_vehicle[playerid] = INVALID_VEHICLE_ID;
			return SendErr(playerid, "Вы не привезли груз. Работа аннулирована");
		}

		new trailerid = GetVehicleTrailer(vehicleid);
		if(truck_trailer[playerid] != trailerid)
		{
			DeletePVarNew(playerid, "type_job_trucker");
			DeletePVarNew(playerid, "trucker_load_miner");
			DeletePVarNew(playerid, "trucker_load_zavod");
			DeletePVarNew(playerid, "trucker_load_shop");
			DeletePVarNew(playerid, "trucker_load_fill_1");
			DeletePVarNew(playerid, "trucker_load_fill_2");
			DeletePVarNew(playerid, "trucker_load_samwill");
			DeletePVarNew(playerid, "player_load_trucker");

			destroy_truck_trailer(playerid);
			truck_vehicle[playerid] = INVALID_VEHICLE_ID;
			return SendErr(playerid, "Вы не привезли груз. Работа аннулирована");
		}

		destroy_truck_trailer(playerid);
		truck_vehicle[playerid] = INVALID_VEHICLE_ID;
	}
	SendSucc(playerid, "Вы разгрузили груз");
	GameTextForPlayer(playerid,"~y~Paџ™pyџka~n~\
		~w~3aўepҐe®a",5000,1);
	return true;
}

stock destroy_truck_trailer(playerid)
{
	if(truck_trailer[playerid] != INVALID_VEHICLE_ID)
	{
		DestroyVehicle(truck_trailer[playerid]);
		truck_trailer[playerid] = INVALID_VEHICLE_ID;

		if(truck_text[playerid] != Text3D:INVALID_3DTEXT_ID) 
			DestroyDynamic3DTextLabelEx(truck_text[playerid]);

		truck_text[playerid] = Text3D:INVALID_3DTEXT_ID;
	}
	return true;
}

stock check_truck_work_trailer(playerid)
{
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
  		new vehicleid = GetPlayerVehicleID(playerid);
		if(GetPVarIntNew(playerid, "trucker_job") == 1 && IsTrailerAttachedToVehicle(vehicleid))// НА ТК ПРОВЕРКА
		{
			new trailerid = GetVehicleTrailer(vehicleid);
			if(truck_trailer[playerid] != trailerid)
			{
				DetachTrailerFromVehicle(vehicleid);
				new Float:x, Float:y, Float:z;
				GetVehiclePos(vehicleid,x,y,z);
				y -= 1.0;
				SetVehiclePos(vehicleid,x,y,z);
			}
		}
	}
	return true;
}


callback:: AttachTrailerToVehicleEx(trailerid,vehicleid)
{
	AttachTrailerToVehicle(trailerid,vehicleid);
	return true;
}