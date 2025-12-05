static const Float:position_spawn_car_army_1[][] =
{
	{1740.0013,1759.3966,15.6929,180.6064},
	{1725.9142,1760.4291,15.6923,181.9134}

};


static const Float:position_spawn_car_army_2[][] =
{
	{1834.5922,1688.2843,15.6162,359.3441},
	{1826.9447,1688.2666,15.6149,359.3342},
	{1819.3196,1688.2773,15.6167,359.6175},
	{1804.0990,1688.3042,15.6163,359.9258}

};

static const Float:position_spawn_car_army_3[][] =
{
	{1794.3492,1711.2717,15.2862,181.5419},
	{1791.1213,1710.9246,15.2862,179.5781},
	{1787.5151,1710.9811,15.2862,178.7904},
	{1783.8364,1711.0470,15.2863,180.1379},
	{1798.2563,1687.9376,15.2863,359.3246},
	{1794.6359,1687.8949,15.2863,358.9999},
	{1791.1589,1687.8779,15.2862,0.0927},
	{1787.4619,1687.8784,15.2862,0.2501},
	{1783.8151,1687.8845,15.2862,359.8761},
	{1839.0222,1710.9762,15.2862,178.9822},
	{1835.3167,1710.9043,15.2862,182.2138},
	{1822.8833,1710.9102,15.2862,180.6118},
	{1819.1221,1710.9722,15.2863,179.0879},
	{1814.7939,1710.7339,15.2862,179.1819},
	{1810.1108,1710.6912,15.2862,183.7071},
	{1807.0270,1710.8126,15.2862,182.6785}
};

new army_car_models[] =
{
	478, 440, 433 
};


stock create_army_other_element()
{

	pickup_spawn_car_army_2 = create_circle_pickup(1804.9043,1711.9701,15.5142, TRIGGER_LRED); // Легковые

	CreateDynamic3DTextLabel(""cWH"Автопарк Армии\n\
		"cLRED"[Встаньте на пикап]", -1, 1804.9043,1711.9701,15.5142, 5.0,INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);

	arArmyKitchen = CreateDynamicSphere(-1827.9926,-1975.2216,-0.5234,1.0);

	CreateDynamic3DTextLabel(""cWH"Склад Армии\n\
		"cLRED"[Встаньте на пикап]", -1, -1585.0941,466.7470,43.3883, 5.0,INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);

	arArmyMakegun = create_circle_pickup(-1585.0941,466.7470,43.3883, TRIGGER_LRED);

	return true;
}


stock spawn_army_1_vehicle(playerid)
{
	format(String512, sizeof(String512), "\
    "cGREY"Транспорт\t"cGREY"Действие\n\
    "cBLUE"1. "cWH"%s\t"cGR"Взять\n\
    "cBLUE"2. "cWH"%s\t"cGR"Взять\n\
    "cBLUE"3. "cWH"%s\t"cGR"Взять\n\
    \t\n\
    "cWH"Доступно всего: \t"cBLUE"%d"cWH" автомобилей", 
    transport_config[army_car_models[0]-400][transport_name],
    transport_config[army_car_models[1]-400][transport_name],
    transport_config[army_car_models[2]-400][transport_name],
    count_army_vert_active
    );
 	SPD(playerid, DIALOG_SELECT_CAR_ARMY_1, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Выбор вертолета", String512, !"Выбрать", !"Закрыть"); 

 	return true;
}

stock spawn_army_2_vehicle(playerid)
{
	format(String512, sizeof(String512), "\
    "cGREY"Автомобиль\t"cGREY"Действие\n\
    "cBLUE"1. "cWH"%s\t"cGR"Взять\n\
    "cBLUE"2. "cWH"%s\t"cGR"Взять\n\
    "cBLUE"3. "cWH"%s\t"cGR"Взять\n\
    \t\n\
    "cWH"Доступно всего: \t"cBLUE"%d"cWH" автомобилей", 
    transport_config[army_car_models[0]-400][transport_name],
    transport_config[army_car_models[1]-400][transport_name],
    transport_config[army_car_models[2]-400][transport_name],

    count_army_vehicle
    );
 	SPD(playerid, DIALOG_SELECT_CAR_ARMY_2, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Выбор автомобиля", String512, !"Выбрать", !"Закрыть"); 

 	return true;
}

stock spawn_army_3_vehicle(playerid)
{
	format(String512, sizeof(String512), "\
    "cGREY"Автомобиль\t"cGREY"Действие\n\
    "cBLUE"1. "cWH"%s\t"cGR"Взять\n\
    "cBLUE"2. "cWH"%s\t"cGR"Взять\n\
    "cBLUE"3. "cWH"%s\t"cGR"Взять\n\
    \t\n\
    "cWH"Доступно всего: \t"cBLUE"%d"cWH" автомобилей", 
    transport_config[army_car_models[0]-400][transport_name],
    transport_config[army_car_models[1]-400][transport_name],
    transport_config[army_car_models[2]-400][transport_name],
    count_army_vehicle
    );
 	SPD(playerid, DIALOG_SELECT_CAR_ARMY_3, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Выбор автомобиля", String512, !"Выбрать", !"Закрыть"); 

 	return true;
}


stock spawn_army_1_veh_start(playerid, type_car)
{
	switch(type_car)
	{
		case 0:
		{
			if(count_army_vert_active == 0)
			{
				spawn_army_1_vehicle(playerid);
				return SendErr(playerid, "Недостаточно вертолетов у Армии!");
			}

			if(pData[playerid][pFraction] != 8 && pData[playerid][pRank] < 5)
			{
				SendErr(playerid, "Доступно только сотрудникам Армии!");
				return true;
			}	

			create_vehicle_army_1(playerid, 0);
		}
		case 1:
		{
			if(count_army_vert_active == 0)
			{
				spawn_army_1_vehicle(playerid);
				return SendErr(playerid, "Недостаточно вертолетов у Армии!");
			}

			if(pData[playerid][pFraction] != 8 && pData[playerid][pRank] < 5)
			{
				SendErr(playerid, "Доступно только сотрудникам Армии!");
				return true;
			}	

			create_vehicle_army_1(playerid, 1);
		}
		case 2:
		{
			if(count_army_vert_active == 0)
			{
				spawn_army_1_vehicle(playerid);
				return SendErr(playerid, "Недостаточно вертолетов у Армии!");
			}

			if(pData[playerid][pFraction] != 8 && pData[playerid][pRank] < 5)
			{
				SendErr(playerid, "Доступно только сотрудникам Армии!");
				return true;
			}	

			create_vehicle_army_1(playerid, 2);
		}
	}

	return true;
}

stock spawn_army_2_veh_start(playerid, type_car)
{
	switch(type_car)
	{
		case 0:
		{
			if(count_army_vehicle == 0)
			{
				spawn_army_2_vehicle(playerid);
				return SendErr(playerid, "Недостаточно госсударственных автомобилей!");
			}

			if(pData[playerid][pFraction] != 8)
			{
				SendErr(playerid, "Доступно только сотрудникам Армии!");
				return true;
			}	

			create_vehicle_army_2(playerid, 0);
		}
		case 1:
		{
			if(count_army_vehicle == 0)
			{
				spawn_army_2_vehicle(playerid);
				return SendErr(playerid, "Недостаточно госсударственных автомобилей!");
			}

			if(pData[playerid][pFraction] != 8)
			{
				SendErr(playerid, "Доступно только сотрудникам Армии!");
				return true;
			}	

			create_vehicle_army_2(playerid, 1);
		}
		case 2:
		{
			if(count_army_vehicle == 0)
			{
				spawn_army_2_vehicle(playerid);
				return SendErr(playerid, "Недостаточно госсударственных автомобилей!");
			}

			if(pData[playerid][pFraction] != 8)
			{
				SendErr(playerid, "Доступно только сотрудникам Армии!");
				return true;
			}	

			create_vehicle_army_2(playerid, 2);
		}
	}

	return true;
}

stock spawn_army_3_veh_start(playerid, type_car)
{
	switch(type_car)
	{
		case 0:
		{
			if(count_army_vehicle == 0)
			{
				spawn_army_2_vehicle(playerid);
				return SendErr(playerid, "Недостаточно госсударственных автомобилей!");
			}

			if(pData[playerid][pFraction] != 8)
			{
				SendErr(playerid, "Доступно только сотрудникам Армии!");
				return true;
			}	

			create_vehicle_army_3(playerid, 0);
		}
		case 1:
		{
			if(count_army_vehicle == 0)
			{
				spawn_army_2_vehicle(playerid);
				return SendErr(playerid, "Недостаточно госсударственных автомобилей!");
			}

			if(pData[playerid][pFraction] != 8)
			{
				SendErr(playerid, "Доступно только сотрудникам Армии!");
				return true;
			}	

			create_vehicle_army_3(playerid, 1);
		}
		case 2:
		{
			if(count_army_vehicle == 0)
			{
				spawn_army_2_vehicle(playerid);
				return SendErr(playerid, "Недостаточно госсударственных автомобилей!");
			}

			if(pData[playerid][pFraction] != 8)
			{
				SendErr(playerid, "Доступно только сотрудникам Армии!");
				return true;
			}	

			create_vehicle_army_3(playerid, 2);
		}
	}

	return true;
}

stock create_vehicle_army_1(playerid, veh_type)
{
	new 
		random_pos = random(1);

	new 
		c1 = 226,
		c2 = 226;	

	new 
		vehicle_army_1 = CreateVehicle(army_car_models[veh_type], position_spawn_car_army_1[random_pos][0], position_spawn_car_army_1[random_pos][1], position_spawn_car_army_1[random_pos][2], position_spawn_car_army_1[random_pos][3], c1, c2, 600);	

	PutPlayerInVehicleEx(playerid, vehicle_army_1, 0);
	vehicle[vehicle_army_1][cFuel] = transport_config[GetVehicleModel(vehicle_army_1)-400][transport_tank];
	vehicle[vehicle_army_1][cHealth] = 1000.0;
	vehicle[vehicle_army_1][cIsCreated] = true;
	vehicle[vehicle_army_1][consumables_oil] = 1000.0;

	vehicle[vehicle_army_1][cOwnTo] = VEHICLE_ARMY_VERT;
	vehicle[vehicle_army_1][cLock] = 2;

	vehicle_lock_status(vehicle_army_1, true);

	count_army_vert_active--;

	return true;
}

stock create_vehicle_army_2(playerid, veh_type)
{
	new 
		random_pos = random(3);

	new 
		c1 = 226,
		c2 = 226;	

	new 
		vehicle_army_2 = CreateVehicle(army_car_models[veh_type], position_spawn_car_army_2[random_pos][0], position_spawn_car_army_2[random_pos][1], position_spawn_car_army_2[random_pos][2], position_spawn_car_army_2[random_pos][3], c1, c2, 600);	

	format(vehicle[vehicle_army_2][cPlate], 20, "Армия");
	SetVehicleNumberPlate(vehicle_army_2, vehicle[vehicle_army_2][cPlate]);

	PutPlayerInVehicleEx(playerid, vehicle_army_2, 0);

	vehicle[vehicle_army_2][cFuel] = transport_config[GetVehicleModel(vehicle_army_2)-400][transport_tank];
	vehicle[vehicle_army_2][cHealth] = 1000.0;
	vehicle[vehicle_army_2][cIsCreated] = true;
	vehicle[vehicle_army_2][consumables_oil] = 1000.0;

	vehicle[vehicle_army_2][cOwnTo] = VEHICLE_ARMY_1;

	vehicle[vehicle_army_2][cLock] = 2;

	vehicle_lock_status(vehicle_army_2, true);

	count_army_vehicle--;

	return true;
}

stock create_vehicle_army_3(playerid, veh_type)
{
	new 
		random_pos = random(14);

	new 
		c1 = 226,
		c2 = 226;	

	new 
		vehicle_army_3 = CreateVehicle(army_car_models[veh_type], position_spawn_car_army_3[random_pos][0], position_spawn_car_army_3[random_pos][1], position_spawn_car_army_3[random_pos][2], position_spawn_car_army_3[random_pos][3], c1, c2, 600);	

	format(vehicle[vehicle_army_3][cPlate], 20, "Армия");
	SetVehicleNumberPlate(vehicle_army_3, vehicle[vehicle_army_3][cPlate]);

	PutPlayerInVehicleEx(playerid, vehicle_army_3, 0);

	vehicle[vehicle_army_3][cFuel] = transport_config[GetVehicleModel(vehicle_army_3)-400][transport_tank];
	vehicle[vehicle_army_3][cHealth] = 1000.0;
	vehicle[vehicle_army_3][cIsCreated] = true;
	vehicle[vehicle_army_3][consumables_oil] = 1000.0;

	vehicle[vehicle_army_3][cOwnTo] = VEHICLE_ARMY_1;

	vehicle[vehicle_army_3][cLock] = 2;

	vehicle_lock_status(vehicle_army_3, true);

	count_army_vehicle--;

	return true;
}

stock dialog_all_army(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
	    case DIALOG_SELECT_CAR_ARMY_1: 
	    {
	    	if(!response)
	    		return true;

	    	switch(listitem)
	    	{
		    	case 0: return spawn_army_1_veh_start(playerid, 0);
		    	case 1: return spawn_army_1_veh_start(playerid, 1);
		    	case 2: return spawn_army_1_veh_start(playerid, 2);
		    	case 3: return spawn_army_1_vehicle(playerid);
		    	case 4: return spawn_army_1_vehicle(playerid);
		    }
	    }
	    case DIALOG_SELECT_CAR_ARMY_2: 
	    {
	    	if(!response)
	    		return true;
	    	
	    	switch(listitem)
	    	{
		    	case 0: return spawn_army_2_veh_start(playerid, 0);
		    	case 1: return spawn_army_2_veh_start(playerid, 1);
		    	case 2: return spawn_army_2_veh_start(playerid, 2);
		    	case 3: return spawn_army_2_vehicle(playerid);
		    	case 4: return spawn_army_2_vehicle(playerid);
		    }
	    }
	    case DIALOG_SELECT_CAR_ARMY_3: 
	    {
	    	if(!response)
	    		return true;
	    	
	    	switch(listitem)
	    	{
		    	case 0: return spawn_army_3_veh_start(playerid, 0);
		    	case 1: return spawn_army_3_veh_start(playerid, 1);
		    	case 2: return spawn_army_3_veh_start(playerid, 2);
		    	case 3: return spawn_army_3_vehicle(playerid);
		    	case 4: return spawn_army_3_vehicle(playerid);
		    }
	    }
	}



	return true;
}




stock load_army_wh_pickups()// OnGameModeInit
{
	army_so_3dtext[0] = CreateDynamic3DTextLabel("_", -1, 2527.7766,311.8531,29.5243, 10.0, INVALID_PLAYER_ID,INVALID_PLAYER_ID,0,0,0,-1,100.0);
	army_so_area[0] = CreateDynamicSphere(2527.7766,311.8531,29.5243, 2.0, 0, 0);

	army_so_3dtext[1] = CreateDynamic3DTextLabel("_", -1, 2447.6926,258.7819,29.5243, 10.0, INVALID_PLAYER_ID,INVALID_PLAYER_ID,0,0,0,-1,100.0);
	army_so_area[1] = CreateDynamicSphere(2447.6926,258.7819,29.5243, 2.0, 0, 0);

	army_so_3dtext[2] = CreateDynamic3DTextLabel("_", -1, 2409.5459,256.9124,29.5243, 10.0, INVALID_PLAYER_ID,INVALID_PLAYER_ID,0,0,0,-1,100.0);
	army_so_area[2] = CreateDynamicSphere(2409.5459,256.9124,29.5243, 2.0, 0, 0);

	army_so_3dtext[3] = CreateDynamic3DTextLabel("_", -1, 2328.7617,311.9908,29.5243, 10.0, INVALID_PLAYER_ID,INVALID_PLAYER_ID,0,0,0,-1,100.0);
	army_so_area[3] = CreateDynamicSphere(2328.7617,311.9908,29.5243, 2.0, 0, 0);

	CreateDynamicPickup(1239, 23, 2527.7766,311.8531,29.5243);
	CreateDynamicPickup(1239, 23, 2447.6926,258.7819,29.5243);
	CreateDynamicPickup(1239, 23, 2409.5459,256.9124,29.5243);

	army_3dtext = CreateDynamic3DTextLabel("_", -1, -1582.2522,461.3610,43.3883, 10.0, INVALID_PLAYER_ID,INVALID_PLAYER_ID,0,3,0,-1,100.0);
	army_area = CreateDynamicSphere(-1582.2522,461.3610,43.3883, 2.0, 3, 0);

	CreateDynamicPickup(1239, 23, -1582.2522,461.3610,43.3883);
	return true;
}
callback:: load_army_warehouse()
{
	new
		query[256];
	format(query, sizeof(query), "SELECT `so_patrons`, `so_guns`, `army_patrons`, `army_guns` FROM `army_warehouse`");
	new Result:r = sql_queryEx(zConn, query, QUERY_CACHED);
	if(!sql_num_rows(r)) 
		return print("Произошла ошибка загрузки базы армии");

	army_info[so_patrons] = sql_get_field_int(r, 0);
	army_info[so_guns] = sql_get_field_int(r, 1);
	army_info[army_patrons] = sql_get_field_int(r, 2);
	army_info[army_guns] = sql_get_field_int(r, 3);

	sql_free_result(r);
	print("Склады армии загружены");

	update_text_army();
	return true;
}

stock update_text_army()
{
	new
		string_mes[256];

	format(string_mes, sizeof(string_mes), ""cBLUE"Патроны: "cWH"%i\n\
	"cBLUE"Ед. оружия: "cWH"%i", army_info[so_patrons], army_info[so_guns]);

	for(new i; i < 4; i++)
		UpdateDynamic3DTextLabelText(army_so_3dtext[i], -1, string_mes);

	format(string_mes, sizeof(string_mes), ""cBLUE"Военный склад\n\
	"cBLUE"Патроны: "cWH"%i\n\
	"cBLUE"Ед. оружия: "cWH"%i", army_info[army_patrons], army_info[army_guns]);

	UpdateDynamic3DTextLabelText(army_3dtext, -1, string_mes);
}

stock save_army_warehouse()
{
	new
		query[560];
		
	format(query,sizeof(query),"UPDATE `army_warehouse` SET `so_patrons` = '%d', `so_guns` = '%d',\
	`army_patrons` = '%d', `army_guns` = '%d'",
	army_info[so_patrons], army_info[so_guns], army_info[army_patrons], army_info[army_guns]);
	sql_queryEx(zConn, query);
	return true;
}

CMD:giveskladarmy(playerid)
{
    if(pData[playerid][pAdmin] < 7)
    	return NoCMD(playerid);	

	army_info[so_patrons] += 50000;
	army_info[so_guns] += 50000;

	save_army_warehouse();
	return true;
}

callback:: delay_carry(playerid)
{
	ApplyAnimation(playerid,"CARRY","crry_prtial",4.0,1,1,1,1,1,1);
}

stock key_take_army_box(playerid, newkeys)
{
	for(new i; i < 4; i++)
	{
		if(newkeys == KEY_WALK && IsPlayerInDynamicArea(playerid, army_so_area[i]))
		{
			if(pData[playerid][pFraction] != 8 && !IsAMafia(playerid))
				return 1;

			if(army_info[so_patrons] < 500 || army_info[so_guns] < 500)
				return SendErr(playerid, "На складе недостаточно боеприпасов");

			if(GetPVarIntNew(playerid, "take_army_box"))
				return SendErr(playerid, "У Вас уже имеется ящик с боеприпасами");

			ApplyAnimation(playerid,"CARRY","liftup",1.0,0,1,1,0,0,1);
			SetTimerEx("delay_carry",1000,false,"i",playerid);
			SetPVarIntNew(playerid,"take_army_box", 1);
			SetPlayerAttachedObject(playerid, 0, 3014, 6, -0.076000, 0.070000, -0.192999, -105.200119, 0.100001, -8.799991, 0.521999, 1.00, 0.468999);

			SendSucc(playerid, "Вы взяли ящик с боеприпасами");

			army_info[so_patrons] -= 500;
			army_info[so_guns] -= 500;

			update_text_army();
			save_army_warehouse();
		}
	}
	if(newkeys & KEY_JUMP && GetPVarIntNew(playerid, "take_army_box") || newkeys & KEY_FIRE && GetPVarIntNew(playerid, "take_army_box"))
	{
		ClearAnimations(playerid);
		ApplyAnimation(playerid, !"CARRY", !"crry_prtial", 4.0, 1, 1, 1, 1, 1, 1);
	}
	return 1;
}

stock area_army_load(playerid, areaid)
{
	return 1;
}


stock take_army_patrons(playerid)
{

	if(!IsPlayerInDynamicArea(playerid, army_area))
		return 1;
	
	if(pTemp[playerid][pAFK] > 3)
		return 1;
	new 
		patrons = RandomEx(3,10);
		
	if(pData[playerid][pAmmo] + patrons > 1000) 
	{
		patrons = 1000 - pData[playerid][pAmmo];
	}

	new 
		guns = RandomEx(3,10);

	if(pData[playerid][pGunAmount] + guns > 1000) 
	{
		guns = 1000 - pData[playerid][pGunAmount];
	}

	if(pData[playerid][pAmmo] == 1000 && pData[playerid][pGunAmount] == 1000) 
		return SendErr(playerid, "Вы не можете унести больше патрон и единиц оружия");

	if(army_info[army_patrons] < patrons || army_info[army_guns] < guns) 
		return SendErr(playerid, "На складе армии отсутствуют боеприпасы");

	army_info[army_patrons] -= patrons;
	army_info[army_guns] -= guns;

	save_army_warehouse();
	update_text_army();

	new string[100];
	format(string, sizeof(string), "~y~PATRONS: +%d~n~~b~GUNS: +%d", patrons, guns);
	GameTextForPlayer(playerid, string, 1500, 6);

	pData[playerid][pAmmo] += patrons;
	UpdatePlayerData(playerid,"ammo",pData[playerid][pAmmo]);
	pData[playerid][pGunAmount] += guns;
	UpdatePlayerData(playerid,"gunamount",pData[playerid][pGunAmount]);

	SetTimerEx("army_take", 1500, false, "i", playerid);
	return 1;
}

callback:: army_take(playerid)
{
	take_army_patrons(playerid);
	return 1;
}

stock delete_vehicle_load_info(vehicleid)
{
	if(vehicle_load[vehicleid] > 0)
	{
		DestroyDynamicPickup(vehicle_load_pickup[vehicleid]);
		DestroyDynamicArea(vehicle_load_sphere[vehicleid]);
		DestroyDynamic3DTextLabel(vehicle_load_text[vehicleid]);
	}
	vehicle_load[vehicleid] = 0;
	vehicle_load_count[vehicleid] = 0;
	return 1;
}

stock load_army_cancel(playerid, newstate)
{
	if(newstate == PLAYER_STATE_DRIVER)
	{
		new 
			vehicleid = GetPlayerVehicleID(playerid);

		if(vehicle_load[vehicleid] > 0)
		{
			new 
				string[250];
			format(string, sizeof(string), "\n"cWH"Вы действительно хотите остановить %s?", vehicle_load[vehicleid] == 1 ? ("загрузку") : ("разгрузку"));
			SPD(playerid, DIALOG_CANCEL_ARMY_LOAD, 0, !""cBLUE"Армия", string, !"Принять", !"Отменить");
			return 1;
		}
	}	
	return 1;	
}

stock dialog_army_cancel(playerid, dialogid, response)
{
	switch(dialogid)
	{
		case DIALOG_CANCEL_ARMY_LOAD:
		{
			if(!response)
				return RemovePlayerFromVehicleEx(playerid);

			new 
				vehicleid = GetPlayerVehicleID(playerid);

			if(vehicleid == INVALID_VEHICLE_ID)
				return 1;

			if(vehicle_load[vehicleid] > 0)
			{
				DestroyDynamicPickup(vehicle_load_pickup[vehicleid]);
				DestroyDynamicArea(vehicle_load_sphere[vehicleid]);
				DestroyDynamic3DTextLabel(vehicle_load_text[vehicleid]);
			}
			vehicle_load[vehicleid] = 0;
			SendSucc(playerid, "Разгрузка/загрузка завершена");
			return 1;
		}
	}
	return 1;
}

CMD:loadgun(playerid)
{
	if(pData[playerid][pFraction] != 8 && !IsAMafia(playerid))
		return SendErr(playerid, "Данная команда доступна только военным и ОПГ");

	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
			return SendErr(playerid, "Вы должны быть за рулем автомобиля");

	new
		carid = GetPlayerVehicleID(playerid);

	if(GetVehicleModel(carid) != 433 && GetVehicleModel(carid) != 412 && GetVehicleModel(carid) != 529 && GetVehicleModel(carid) != 543)
		return SendErr(playerid, "Данный автомобиль не подходит для загрузки");

	if(vehicle_load[carid] > 0)
		return SendErr(playerid, "Автомобиль уже находится на загрузке/разгрузке");

	vehicle_load[carid] = 1;

	RemovePlayerFromVehicleEx(playerid);

	new
		Float:x, Float:y, Float:z, Float:a;

	GetVehiclePos(carid, x, y, z);
	GetVehicleZAngle(carid, a);
	if(GetVehicleModel(carid) == 433)
	{
		x = x - (-6.0*floatsin(a, degrees));
		y = y -6.0*floatcos(a, degrees);
	}
	else if(GetVehicleModel(carid) == 412 || GetVehicleModel(carid) == 529 || GetVehicleModel(carid) == 543)
	{
		x = x - (-3.0*floatsin(a, degrees));
		y = y -3.0*floatcos(a, degrees);
	}
	

	vehicle_load_pickup[carid] = CreateDynamicPickup(13719, 1, x, y, z-0.5);
	vehicle_load_sphere[carid] = CreateDynamicSphere(x, y, z-0.5, 1.0);

	new
		string[40];


	format(string, sizeof(string), ""cBLUE"Ящиков загружено\n"cWH"%d/%d", vehicle_load_count[carid], GetVehicleGuns(carid));
	vehicle_load_text[carid] = CreateDynamic3DTextLabel(string, -1, x, y, z+0.5, 10.0);

	SendSucc(playerid, "Загрузка началась");
	return true;
}

CMD:unloadgun(playerid)
{
	if(pData[playerid][pFraction] != 8 && !IsAMafia(playerid))
		return SendErr(playerid, "Данная команда доступна только военным и ОПГ");

	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
			return SendErr(playerid, "Вы должны быть за рулем автомобиля");

	new
		carid = GetPlayerVehicleID(playerid);

	if(GetVehicleModel(carid) != 433 && GetVehicleModel(carid) != 412 && GetVehicleModel(carid) != 529 && GetVehicleModel(carid) != 543)
		return SendErr(playerid, "Данный автомобиль не подходит для разгрузки");

	if(vehicle_load[carid] > 0)
		return SendErr(playerid, "Автомобиль уже находится на загрузке/разгрузке");

	vehicle_load[carid] = 2;

	RemovePlayerFromVehicleEx(playerid);

	new
		Float:x, Float:y, Float:z, Float:a;

	GetVehiclePos(carid, x, y, z);
	GetVehicleZAngle(carid, a);
	if(GetVehicleModel(carid) == 433)
	{
		x = x - (-6.0*floatsin(a, degrees));
		y = y -6.0*floatcos(a, degrees);
	}
	else if(GetVehicleModel(carid) == 412 || GetVehicleModel(carid) == 529 || GetVehicleModel(carid) == 543)
	{
		x = x - (-3.0*floatsin(a, degrees));
		y = y -3.0*floatcos(a, degrees);
	}

	vehicle_load_pickup[carid] = CreateDynamicPickup(13719, 1, x, y, z-0.5);
	vehicle_load_sphere[carid] = CreateDynamicSphere(x, y, z-0.5, 1.0);

	new
		string[40];

	format(string, sizeof(string), ""cBLUE"Ящиков загружено\n"cWH"%d/%d", vehicle_load_count[carid], GetVehicleGuns(GetVehicleModel(carid)));
	vehicle_load_text[carid] = CreateDynamic3DTextLabel(string, -1, x, y, z+0.5, 10.0);

	SendSucc(playerid, "Разгрузка началась");
	return true;
}

stock GetVehicleGuns(vehicle)
{ 
	new 
		count;

	switch(vehicle)
	{
		case 433: count = 15;
		case 412: count = 5;
		case 529: count = 5;
		case 543: count = 5;
	}
	return count;
}
stock ShowArmyKitchenDialog(playerid, dialogid, response, listitem) // OnDialogResponse
{
	switch(dialogid)
	{
		case DIALOG_ARMY_KITCHEN:
		{
			if(!response)
				return true;

			switch(listitem)
			{
				case 0:
				{
					SendSucc(playerid, "Вы съели перловую кашу");
			        if(pData[playerid][hungry]+8 < 100)
			        {
			    		pData[playerid][hungry] += 8;
			    		show_hud_hungry(playerid);
			        }					
				}
				case 1:
				{
					SendSucc(playerid, "Вы съели овсяную кашу");
			        if(pData[playerid][hungry]+8 < 100)
			        {
			    		pData[playerid][hungry] += 8;
			    		show_hud_hungry(playerid);
			        }					
				}
				case 2:
				{
					SendSucc(playerid, "Вы съели суп");
			        if(pData[playerid][hungry]+8 < 100)
			        {
			    		pData[playerid][hungry] += 8;
			    		show_hud_hungry(playerid);
			        }					
				}
				case 3:
				{
					SendSucc(playerid, "Вы съели борщ");
			        if(pData[playerid][hungry]+8 < 100)
			        {
			    		pData[playerid][hungry] += 8;
			    		show_hud_hungry(playerid);
			        }					
				}
				case 4:
				{
					SendSucc(playerid, "Вы съели картофельное пюре с котлетой");
			        if(pData[playerid][hungry]+8 < 100)
			        {
			    		pData[playerid][hungry] += 8;
			    		show_hud_hungry(playerid);
			        }					
				}
				case 5:
				{
					SendSucc(playerid, "Вы съели макароны с сосиской");
			        if(pData[playerid][hungry]+8 < 100)
			        {
			    		pData[playerid][hungry] += 8;
			    		show_hud_hungry(playerid);
			        }					
				}
				case 6:
				{
					SendSucc(playerid, "Вы выпили компот из сухофруктов");
			        if(pData[playerid][hungry]+8 < 100)
			        {
			    		pData[playerid][hungry] += 8;
			    		show_hud_hungry(playerid);
			        }					
				}
			}
			return 1;
		}
	}
	return 1;
}


stock ShowArmyGunDialog(playerid, dialogid, response, listitem) // OnDialogResponse
{
	switch(dialogid)
	{
		case DIALOG_ARMY_SELECT_GUN:
		{
			if(!response)
				return 1;

			if(pData[playerid][pFraction] != 8)// Проверка на армию
						return SendErr(playerid, "Сборка оружия доступна только военнослужающим");

			switch(listitem)
			{
				case 0:
				{
					if(GetPVarIntNew(playerid,"take_deagle") > gettime())
				   		return SendErr(playerid, "Брать оружие можно раз в минуту");

					if(army_info[army_patrons] < 50 || army_info[army_guns] < 180) 
						return SendErr(playerid, "На складе армии отсутствуют боеприпасы");

				   	SetPVarIntNew(playerid, "take_deagle", gettime()+60);

				   	GivePlayerWeaponEx(playerid, 24, 50);

					
					army_info[army_patrons] -= 50; 
					army_info[army_guns] -= 180;
					save_army_warehouse();
					update_text_army();

					SendSucc(playerid, "Вы взяли Desert Eagle с 50 патронами");
				}
				case 1:
				{
					if(GetPVarIntNew(playerid,"take_mp5") > gettime())
				   		return SendErr(playerid, "Брать оружие можно раз в минуту");

					if(army_info[army_patrons] < 150 || army_info[army_guns] < 200) 
						return SendErr(playerid, "На складе армии отсутствуют боеприпасы");

				   	SetPVarIntNew(playerid, "take_mp5", gettime()+60);

				   	GivePlayerWeaponEx(playerid, 29, 150);

					army_info[army_patrons] -= 150; 
					army_info[army_guns] -= 200;
					save_army_warehouse();
					update_text_army();


					SendSucc(playerid, "Вы взяли MP5 с 150 патронами");
				}
				case 2:
				{
					if(GetPVarIntNew(playerid,"take_shotgun") > gettime())
				   		return SendErr(playerid, "Брать оружие можно раз в минуту");

					if(army_info[army_patrons] < 50 || army_info[army_guns] < 280) 
						return SendErr(playerid, "На складе армии отсутствуют боеприпасы");

				   	SetPVarIntNew(playerid, "take_shotgun", gettime()+60);

				   	GivePlayerWeaponEx(playerid, 25, 50);

					army_info[army_patrons] -= 50; 
					army_info[army_guns] -= 280;
					save_army_warehouse();
					update_text_army();


					SendSucc(playerid, "Вы взяли ShotGun с 50 патронами");
				}
				case 3:
				{
					if(GetPVarIntNew(playerid,"take_rifle") > gettime())
				   		return SendErr(playerid, "Брать оружие можно раз в минуту");

					if(army_info[army_patrons] < 50 || army_info[army_guns] < 380) 
						return SendErr(playerid, "На складе армии отсутствуют боеприпасы");

				   	SetPVarIntNew(playerid, "take_rifle", gettime()+60);

				   	GivePlayerWeaponEx(playerid, 33, 50);

					army_info[army_patrons] -= 50; 
					army_info[army_guns] -= 380;
					save_army_warehouse();
					update_text_army();

					SendSucc(playerid, "Вы взяли Rifle с 50 патронами");
				}
				case 4:
				{
					if(GetPVarIntNew(playerid,"take_assaultrifle") > gettime())
				   		return SendErr(playerid, "Брать оружие можно раз в минуту");

					if(army_info[army_patrons] < 150 || army_info[army_guns] < 300) 
						return SendErr(playerid, "На складе армии отсутствуют боеприпасы");

				   	SetPVarIntNew(playerid, "take_assaultrifle", gettime()+60);

				   	GivePlayerWeaponEx(playerid, 30, 150);

					army_info[army_patrons] -= 150; 
					army_info[army_guns] -= 300;
					save_army_warehouse();
					update_text_army();

					SendSucc(playerid, "Вы взяли AK-47 с 150 патронами");
				}
				case 5:
				{
					if(GetPVarIntNew(playerid,"take_assault_rifle") > gettime())
				   		return SendErr(playerid, "Брать оружие можно раз в минуту");

					if(army_info[army_patrons] < 150 || army_info[army_guns] < 300) 
						return SendErr(playerid, "На складе армии отсутствуют боеприпасы");

				   	SetPVarIntNew(playerid, "take_assault_rifle", gettime()+60);

				   	GivePlayerWeaponEx(playerid, 31, 150);

					army_info[army_patrons] -= 150; 
					army_info[army_guns] -= 300;
					save_army_warehouse();
					update_text_army();

					SendSucc(playerid, "Вы взяли M4 с 150 патронами");
				}
			}
			return 1;
		}
	}
	return 1;
}