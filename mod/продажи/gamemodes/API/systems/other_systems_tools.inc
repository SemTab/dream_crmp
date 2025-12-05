stock spawn_player_house_all(playerid)
{

	if(pData[playerid][pHouse] != -1 &&  pData[playerid][pFlate] == -1 && pData[playerid][pFlateRent] == -1 && pData[playerid][pHotelRoom] == -1)
	{
		new 
			id_house = pData[playerid][pHouse];

		new 
			class = House[id_house][house_class];

		if(pData[playerid][pFraction]) SetPlayerColor(playerid,gFractionColor[pData[playerid][pFraction] - 1]);

		set_player_skin(playerid,pData[playerid][pSkin]);

		SetPlayerPosEx(playerid, house_int_spawn_coord[class][0], house_int_spawn_coord[class][1], house_int_spawn_coord[class][2], house_int_spawn_coord[class][3]);

		SetPVarIntNew(playerid, "house_id_enter_p", id_house);

		SetPlayerVirtualWorld(playerid, id_house);
			
		TogglePlayerControllable(playerid,0);
		SetTimerEx("Unfreez",1000,false,"i",playerid);
		SetCameraBehindPlayer(playerid);

		hide_select_spawn(playerid);

	}


	else if(pData[playerid][pHouse] == -1 && pData[playerid][pHouseRent] && pData[playerid][pFlate] == -1 && pData[playerid][pFlateRent] == -1 && pData[playerid][pHotelRoom] == -1)
	{
		new 
			id_house = pData[playerid][pHouseRent];

		new 
			class = House[id_house][house_class];

		if(pData[playerid][pFraction]) SetPlayerColor(playerid,gFractionColor[pData[playerid][pFraction] - 1]);

		
		SetPlayerPosEx(playerid, house_int_spawn_coord[class][0], house_int_spawn_coord[class][1], house_int_spawn_coord[class][2], house_int_spawn_coord[class][3]);

		SetPVarIntNew(playerid, "house_id_enter_p", id_house);

		SetPlayerVirtualWorld(playerid, id_house);
			
		TogglePlayerControllable(playerid,0);
		SetTimerEx("Unfreez",1000,false,"i",playerid);
		SetCameraBehindPlayer(playerid);
		SetPlayerInterior(playerid,0);

		hide_select_spawn(playerid);

	}
	else if(pData[playerid][pFlate] == -1 && pData[playerid][pFlateRent] && pData[playerid][pHouse] == -1 && pData[playerid][pHouseRent] == -1 && pData[playerid][pHotelRoom] == -1)
	{
		new 
			id_house = pData[playerid][pFlateRent];

		new 
			class = flate[id_house][flate_class];

		new 
			vw = flate[id_house][flate_id_in_entrance]+playerid;

		SetPVarIntNew(playerid, "flate_id_enter", flate[id_house][flate_entrance_id]+1);

		SetPVarIntNew(playerid, "flate_id_active", flate[id_house][flate_id_in_entrance]-1);

		SetPVarIntNew(playerid, "entrance_enter_id_vw", flate[id_house][flate_entrance_id]);

		if(pData[playerid][pFraction]) SetPlayerColor(playerid,gFractionColor[pData[playerid][pFraction] - 1]);

		
set_player_skin(playerid,pData[playerid][pSkin]);

		SetPlayerPosEx(playerid, flate_int_spawn_coord[class][0], flate_int_spawn_coord[class][1], flate_int_spawn_coord[class][2], flate_int_spawn_coord[class][3]);


		SetPlayerVirtualWorld(playerid, pData[playerid][pFlateRent]);
			
		TogglePlayerControllable(playerid,0);
		SetTimerEx("Unfreez",1000,false,"i",playerid);
		SetCameraBehindPlayer(playerid);
		SetPlayerInterior(playerid,0);

		hide_select_spawn(playerid);

	}


	else if(pData[playerid][pFlate] != -1 && pData[playerid][pHouse] == -1 && pData[playerid][pHouseRent] == -1 && pData[playerid][pHotelRoom] == -1)
	{
		new 
			id_house = pData[playerid][pFlate];

		new 
			class = flate[id_house][flate_class];

		new 
			vw = flate[id_house][flate_id_in_entrance]+playerid;

		SetPVarIntNew(playerid, "flate_id_enter", flate[id_house][flate_entrance_id]+1);

		SetPVarIntNew(playerid, "flate_id_active", flate[id_house][flate_id_in_entrance]-1);

		SetPVarIntNew(playerid, "entrance_enter_id_vw", flate[id_house][flate_entrance_id]);

		if(pData[playerid][pFraction]) SetPlayerColor(playerid,gFractionColor[pData[playerid][pFraction] - 1]);

		set_player_skin(playerid,pData[playerid][pSkin]);

		SetPlayerPosEx(playerid, flate_int_spawn_coord[class][0], flate_int_spawn_coord[class][1], flate_int_spawn_coord[class][2], flate_int_spawn_coord[class][3]);


		SetPlayerVirtualWorld(playerid, pData[playerid][pFlate]);
			
		TogglePlayerControllable(playerid,0);
		SetTimerEx("Unfreez",1000,false,"i",playerid);
		SetCameraBehindPlayer(playerid);
		SetPlayerInterior(playerid,0);

		hide_select_spawn(playerid);

	}

	else if(pData[playerid][pHotelRoom] != -1 && pData[playerid][pFlate] == -1  && pData[playerid][pFlateRent] == -1 &&  pData[playerid][pHouse] == -1 && pData[playerid][pHouseRent] == -1)
	{
		new 
			id_hotel_room = pData[playerid][pHotelRoom];

		new 
			class = hotel_room[id_hotel_room][hotel_room_class];

		new 
			vw = id_hotel_room+playerid;

		SetPVarIntNew(playerid, "hotel_room_id_enter", vw);

		SetPVarIntNew(playerid, "number_hotel_id", id_hotel_room);

		SetPVarIntNew(playerid, "hotel_number_vw", pData[playerid][pHotel]); 

		if(pData[playerid][pFraction]) SetPlayerColor(playerid,gFractionColor[pData[playerid][pFraction] - 1]);

		set_player_skin(playerid,pData[playerid][pSkin]);

		SetPlayerPosEx(playerid, hotel_int_spawn_coord[class][0], hotel_int_spawn_coord[class][1], hotel_int_spawn_coord[class][2], hotel_int_spawn_coord[class][3]);


		SetPlayerVirtualWorld(playerid, vw);
			
		TogglePlayerControllable(playerid,0);
		SetTimerEx("Unfreez",1000,false,"i",playerid);
		SetCameraBehindPlayer(playerid);
		SetPlayerInterior(playerid,0);

		hide_select_spawn(playerid);
	}



	else
	{
		new 
			family_ids = pData[playerid][pFamily];

		if(get_family_house(family_ids) != -1)
		{
			return spawn_player_house_family(playerid);
		}

		SendErr(playerid, "У вас отсутствует жильё!");
		show_select_spawn(playerid);
	}
	return true;
}

stock spawn_player_house_family(playerid)
{
	new 
		family_ids = pData[playerid][pFamily];
		

	new 
		id_house = get_family_house(family_ids);

	new 
		class = House[id_house][house_class];

	if(pData[playerid][pFraction]) SetPlayerColor(playerid,gFractionColor[pData[playerid][pFraction] - 1]);

	set_player_skin(playerid,pData[playerid][pSkin]);

	SetPlayerPosEx(playerid, house_int_spawn_coord[class][0], house_int_spawn_coord[class][1], house_int_spawn_coord[class][2], house_int_spawn_coord[class][3]);

	SetPVarIntNew(playerid, "house_id_enter_p", id_house);

	SetPlayerVirtualWorld(playerid, id_house);
		
	TogglePlayerControllable(playerid,0);
	SetTimerEx("Unfreez",1000,false,"i",playerid);
	SetCameraBehindPlayer(playerid);
	SetPlayerInterior(playerid,0);

	hide_select_spawn(playerid);

	return true;
}