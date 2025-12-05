

CMD:car(playerid)
{

	if(GetPVarIntNew(playerid, "snow_work") == 1)
		return SendErr(playerid, "Невозможно использовать во время работы!");

	if(GetPVarIntNew(playerid, "bus_job_cp") == 1)
		return SendErr(playerid, "Невозможно использовать во время работы!");

	if(GetPVarIntNew(playerid, "active_player_house_newyear") == 1)
		return SendErr(playerid, "Невозможно использовать во время работы!");

	if(GetPVarIntNew(playerid, "trucker_job") == 1)
		return SendErr(playerid, "Невозможно использовать во время работы!");

	if(GetPVarIntNew(playerid, "active_player_gruz_taxi") == 1)
		return SendErr(playerid, "Невозможно использовать во время работы!");

	if(GetPVarIntNew(playerid, "active_player_gruz_taxi_p") == 1)
		return SendErr(playerid, "Невозможно использовать во время работы!");

	show_player_cars(playerid);

	return true;
}

CMD:park(playerid, params[])
{

	if(!get_player_in_p_car(playerid))
		return SendErr(playerid, "Вы должны сидеть в личном транспорте!");

	if(GetPVarIntNew(playerid, "active_player_gruz_taxi") == 1)
		return SendErr(playerid, "Невозможно использовать во время работы!");

	if(GetPVarIntNew(playerid, "active_player_gruz_taxi_p") == 1)
		return SendErr(playerid, "Невозможно использовать во время работы!");


	if(pGreenZone[playerid] == 1 && !GetPVarIntNew(playerid, "player_in_garage_house"))
		return SendErr(playerid, "Запрещено парковать личный транспорт в Зелёной Зоне!");

	if(GetPVarIntNew(playerid, "cooldown_park_car") > gettime())
		return SendErr(playerid, "Парковать транспортное средство можно раз в 1 минуту!");

	if(pData[playerid][pHouse] || pData[playerid][pFlate] || pData[playerid][pGarage] || pData[playerid][pHotelRoom])
	{	
		for(new i; i < MAX_PLAYERS_VEHICLE_SL; i++)
		{
			if(GetPlayerVehicleID(playerid) == vehicle_player_max[playerid][i])
			{
				new 
					Float:x, Float:y, Float:z, Float:r;

				GetVehiclePos(vehicle_player_max[playerid][i],x,y,z);
				GetVehicleZAngle(vehicle_player_max[playerid][i],r);

				new 
					car_vw = GetVehicleVirtualWorld(vehicle_player_max[playerid][i]);

			    format(String256, sizeof(String256), "UPDATE `player_vehicles` SET \
			    	parking_x = '%.4f',\
			    	parking_y = '%.4f',\
			    	parking_z = '%.4f',\
			    	parking_a = '%.4f',\
			    	parking_vw = '%d'\
			    	WHERE id = '%i' AND owner = '%s'",
					x,
					y,
					z,
					r,
					car_vw,

			    	vehicle_player_max_sql[playerid][i], GetNameEx(playerid));

				sql_queryEx(zConn, String256, QUERY_THREADED);

				new
					Float:ac_health;

				GetVehicleHealth(vehicle_player_max[playerid][i], ac_health);


			    format(String2048, sizeof(String2048), "UPDATE `player_vehicles` SET \
			    	number = '%s',\
			    	lock_status = '%d',\
			    	parking_garage = '%d',\
			    	parking_hotel = '%d',\
			    	shtraf_car = '%d',\
			    	parking_police = '%d',\
			    	energy_car = '%f',\
			    	mileage = '%f',\
			    	fuel = '%f',\
			    	health = '%f',\
			    	consumables_candles = '%f',\
			    	consumables_oil = '%f',\
			    	consumables_brake = '%f',\
			    	consumables_belt = '%f',\
			    	consumables_starter = '%f',\
			    	consumables_generator = '%f',\
			    	consumables_forsunki = '%f',\
			    	consumables_fuel = '%f',\
			    	generator_energy = '%f',\
			    	battery_energy = '%f',\
			    	number_region = '%s',\
			    	number_type = '%d'\
			    	WHERE id = '%d' AND owner = '%s'",

			    	vehicle[vehicle_player_max[playerid][i]][cPlate],
					vehicle[vehicle_player_max[playerid][i]][cLock],
					vehicle[vehicle_player_max[playerid][i]][parking_garage],
					vehicle[vehicle_player_max[playerid][i]][parking_hotel],
					vehicle[vehicle_player_max[playerid][i]][shtraf_car],
					vehicle[vehicle_player_max[playerid][i]][parking_police],
					vehicle[vehicle_player_max[playerid][i]][cEnergy],
					vehicle[vehicle_player_max[playerid][i]][cMileage],
					vehicle[vehicle_player_max[playerid][i]][cFuel],
					ac_health,
					vehicle[vehicle_player_max[playerid][i]][consumables_candles],
					vehicle[vehicle_player_max[playerid][i]][consumables_oil],
					vehicle[vehicle_player_max[playerid][i]][consumables_brake],
					vehicle[vehicle_player_max[playerid][i]][consumables_belt],
					vehicle[vehicle_player_max[playerid][i]][consumables_starter],
					vehicle[vehicle_player_max[playerid][i]][consumables_generator],
					vehicle[vehicle_player_max[playerid][i]][consumables_forsunki],
					vehicle[vehicle_player_max[playerid][i]][consumables_fuel],


					vehicle[vehicle_player_max[playerid][i]][cGeneratorEnergy],
					vehicle[vehicle_player_max[playerid][i]][cBatteryEnergy],

					vehicle[vehicle_player_max[playerid][i]][cPlateRegion],
					vehicle[vehicle_player_max[playerid][i]][cPlateType],

			    	vehicle_player_max_sql[playerid][i], GetNameEx(playerid));

				sql_queryEx(zConn, String2048, QUERY_THREADED);

				SendSucc(playerid, "Вы перепарковали личное транспортное средство");
				break;
			}
		}
	}
	else
	{
		if(!GetPVarIntNew(playerid, "player_in_parking"))
			return SendErr(playerid, "Так как у Вас нет имущества, припарковать автомобиль можно только на паркинге!");

		for(new i; i < MAX_PLAYERS_VEHICLE_SL; i++)
		{
			if(GetPlayerVehicleID(playerid) == vehicle_player_max[playerid][i])
			{
				new 
					Float:x, Float:y, Float:z, Float:r;

				GetVehiclePos(vehicle_player_max[playerid][i],x,y,z);
				GetVehicleZAngle(vehicle_player_max[playerid][i],r);

				new 
					car_vw = GetVehicleVirtualWorld(vehicle_player_max[playerid][i]);

			    format(String256, sizeof(String256), "UPDATE `player_vehicles` SET \
			    	parking_x = '%.4f',\
			    	parking_y = '%.4f',\
			    	parking_z = '%.4f',\
			    	parking_a = '%.4f',\
			    	parking_vw = '%d'\
			    	WHERE id = '%i' AND owner = '%s'",
					x,
					y,
					z,
					r,
					car_vw,

			    	vehicle_player_max_sql[playerid][i], GetNameEx(playerid));

				sql_queryEx(zConn, String256, QUERY_THREADED);

				new
					Float:ac_health;

				GetVehicleHealth(vehicle_player_max[playerid][i], ac_health);


			    format(String2048, sizeof(String2048), "UPDATE `player_vehicles` SET \
			    	number = '%s',\
			    	lock_status = '%d',\
			    	parking_garage = '%d',\
			    	parking_hotel = '%d',\
			    	shtraf_car = '%d',\
			    	parking_police = '%d',\
			    	energy_car = '%f',\
			    	mileage = '%f',\
			    	fuel = '%f',\
			    	health = '%f',\
			    	consumables_candles = '%f',\
			    	consumables_oil = '%f',\
			    	consumables_brake = '%f',\
			    	consumables_belt = '%f',\
			    	consumables_starter = '%f',\
			    	consumables_generator = '%f',\
			    	consumables_forsunki = '%f',\
			    	consumables_fuel = '%f',\
			    	generator_energy = '%f',\
			    	battery_energy = '%f',\
			    	number_region = '%s',\
			    	number_type = '%d'\
			    	WHERE id = '%i' AND owner = '%s'",

			    	vehicle[vehicle_player_max[playerid][i]][cPlate],
					vehicle[vehicle_player_max[playerid][i]][cLock],
					vehicle[vehicle_player_max[playerid][i]][parking_garage],
					vehicle[vehicle_player_max[playerid][i]][parking_hotel],
					vehicle[vehicle_player_max[playerid][i]][shtraf_car],
					vehicle[vehicle_player_max[playerid][i]][parking_police],
					vehicle[vehicle_player_max[playerid][i]][cEnergy],
					vehicle[vehicle_player_max[playerid][i]][cMileage],
					vehicle[vehicle_player_max[playerid][i]][cFuel],
					ac_health,
					vehicle[vehicle_player_max[playerid][i]][consumables_candles],
					vehicle[vehicle_player_max[playerid][i]][consumables_oil],
					vehicle[vehicle_player_max[playerid][i]][consumables_brake],
					vehicle[vehicle_player_max[playerid][i]][consumables_belt],
					vehicle[vehicle_player_max[playerid][i]][consumables_starter],
					vehicle[vehicle_player_max[playerid][i]][consumables_generator],
					vehicle[vehicle_player_max[playerid][i]][consumables_forsunki],
					vehicle[vehicle_player_max[playerid][i]][consumables_fuel],


					vehicle[vehicle_player_max[playerid][i]][cGeneratorEnergy],
					vehicle[vehicle_player_max[playerid][i]][cBatteryEnergy],

					vehicle[vehicle_player_max[playerid][i]][cPlateRegion],
					vehicle[vehicle_player_max[playerid][i]][cPlateType],

			    	vehicle_player_max_sql[playerid][i], GetNameEx(playerid));

				sql_queryEx(zConn, String2048, QUERY_THREADED);

				SendSucc(playerid, "Вы перепарковали личное транспортное средство");
				break;
			}
		}		
	}

	SendInf(playerid, "Вы успешно припарковали своё транспортное средство!");
	SendInf(playerid, "Теперь при входе оно будет появляться в данном месте!");	

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_RIGHT, "brilliantother:info_gui_vehicle_park", 3000);

	SetPVarIntNew(playerid, "cooldown_park_car", gettime()+60);

	return true;
}

stock show_player_cars(playerid)
{
	new 
		fam_id = pData[playerid][pFamily];

	format(String512, sizeof(String512), "SELECT * FROM player_vehicles WHERE owner = '%s'", GetNameEx(playerid));
	new Result:player_m_all_vehicle = sql_queryEx(zConn, String512, QUERY_CACHED);

	new all_veh = sql_num_rows(player_m_all_vehicle);

	if(!all_veh)
		return SendErr(playerid, "Транспорт не найден");

	new 
		string[1024],	
		sql_id, 
		modelid;

	format(string, sizeof(string), ""cGREY"№. Транспорт\t"cGREY"Состояние\n");

 	for(new i; i < all_veh; i++)
	{
		sql_id = sql_get_field_assoc_int_ex(player_m_all_vehicle, i, "id");
		modelid = sql_get_field_assoc_int_ex(player_m_all_vehicle, i, "model"); 

		format(string, sizeof(string), "%s"cBLUE"%i. "cWH"%s\t"cGREY"%s\n", string, i+1, transport_config[modelid-400][transport_name], get_player_veh_status(sql_id) == 1 ? (""cGR"[Загружена]") : (""cLRED"[Не загружена]"));
	}

	SPD(playerid, DIALOG_PLAYER_VEHICLE_LIST, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Личный транспорт", string, !"Выбрать", !"Закрыть");

	sql_next_row(player_m_all_vehicle);	

	return true;
}

stock get_player_veh_status(id)
{
	for(new i; i < MAX_VEHICLES; i++)
	{
		if(vehicle[i][v_vehicle] == id)
			return true;
	}
	return false;
}

stock get_player_in_p_car(playerid)
{
	if(!IsPlayerInAnyVehicle(playerid)) 
		return false;

	for(new i; i < MAX_PLAYERS_VEHICLE_SL; i++)
	{
		if(GetPlayerVehicleID(playerid) == vehicle_player_max[playerid][i])
			return true;
	}
	return false;
}


stock get_player_vehicle_pos(playerid, sql_id)
{
	for(new i; i < MAX_PLAYERS_VEHICLE_SL; i++)
	{
		if(vehicle_player_max_sql[playerid][i] == sql_id)
		{

			new Float:x, Float:y, Float:z;

			GetVehiclePos(vehicle_player_max[playerid][i], x, y, z);
			
			SetPlayerCheckpoint(playerid, x, y, z, 4.0);

			pTemp[playerid][pGPS] = true;

			SendSucc(playerid, "Вы отметили транспортное средство на карте");
			break;
		}
	}
	return true;
}

stock check_parking_vehicle_p(playerid, sql_id)
{
	new 
		vehicle_id;

	for(new i; i < MAX_PLAYERS_VEHICLE_SL; i++)
	{
		if(vehicle_player_max_sql[playerid][i] == sql_id)
		{	
			vehicle_id = vehicle_player_max[playerid][i];

			new Float:x, Float:y, Float:z;

			if(vehicle[vehicle_id][vehicle_world] == VIRTUAL_WORLD_PARKING_1)
			{
			
				SetPlayerCheckpoint(playerid, 2214.7146,-1967.1420,18.5226, 4.0);

				pTemp[playerid][pGPS] = true;

				SendSucc(playerid, "Паркинг, где находится автомобиль отмечен на карте!");
			}
			else if(vehicle[vehicle_id][vehicle_world] == VIRTUAL_WORLD_PARKING_2)
			{
				SetPlayerCheckpoint(playerid, -429.4702,673.4578,11.8583, 4.0);

				pTemp[playerid][pGPS] = true;

				SendSucc(playerid, "Паркинг, где находится автомобиль отмечен на карте!");
			}
			break;
		}
	}

	return true;
}

stock show_player_vehicle_menu(playerid, sql_id)
{
	SetPVarIntNew(playerid, "player_vehicle_select_sql", sql_id);

	new 
		vehicle_id;

	for(new i; i < MAX_PLAYERS_VEHICLE_SL; i++)
	{
		if(vehicle_player_max_sql[playerid][i] == sql_id)
		{	
			vehicle_id = vehicle_player_max[playerid][i];
		}
	}

	new str[556],
		string[556];

	if(vehicle[vehicle_id][vehicle_world] == VIRTUAL_WORLD_PARKING_1 || vehicle[vehicle_id][vehicle_world] == VIRTUAL_WORLD_PARKING_2)
	{
	    format(string, sizeof(string), "\
	    "cGREY"Пункт\t"cGREY"Действие\n\
	    "cBLUE"- "cWH"Действия с автомобилем\t"cBLUE"%s[%d]\n\
	    \t\n\
	    "cBLUE"1. "cWH"Информация о транспорте\t"cBLUE"Изучить\n\
	    "cBLUE"2. "cWH"Отметить транспорт на GPS\t"cBLUE"Найти\n\
	    "cBLUE"3. "cWH"Буксировка транспорта на парковку\t"cGR"%d рублей\n\
	    "cBLUE"4. "cWH"Состояние автомобиля\t"cGR"Изучить\n\
	    "cBLUE"5. "cWH"Продажа в гос.стоимость\t"cGR"Продать\n\
	    "cBLUE"6. "cWH"Отметить паркинг автомобиля\t"cGR"Найти\n\
		"cBLUE"7. "cWH"Разгрузить автомобиль с сервера\t"cGR"Разгрузить", transport_config[GetVehicleModel(vehicle_id)-400][transport_name], GetPVarIntNew(playerid, "player_vehicle_select_sql"), 
	    1500);
	    SPD(playerid, DIALOG_CAR_CHANGE_PANEL, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Личный транспорт", string, !"Выбрать", !"Закрыть"); 
	}
	else
	{
	    format(str, sizeof(str), "\
	    "cGREY"Пункт\t"cGREY"Действие\n\
	    "cBLUE"- "cWH"Действия с автомобилем\t"cBLUE"%s[%d]\n\
	    \t\n\
	    "cBLUE"1. "cWH"Информация о транспорте\t"cBLUE"Изучить\n\
	    "cBLUE"2. "cWH"Отметить транспорт на GPS\t"cBLUE"Найти\n\
	    "cBLUE"3. "cWH"Буксировка транспорта на парковку\t"cGR"%d рублей\n\
	    "cBLUE"4. "cWH"Состояние автомобиля\t"cGR"Изучить\n\
	    "cBLUE"5. "cWH"Продажа в гос.стоимость\t"cGR"Продать\n\
		"cBLUE"6. "cWH"Отметить паркинг автомобиля\t"cGR"Найти\n\
		"cBLUE"7. "cWH"Разгрузить автомобиль с сервера\t"cGR"Разгрузить", transport_config[GetVehicleModel(vehicle_id)-400][transport_name], GetPVarIntNew(playerid, "player_vehicle_select_sql"), 
	    1500);
	    SPD(playerid, DIALOG_CAR_CHANGE_PANEL, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Личный транспорт", str, !"Выбрать", !"Закрыть"); 		
	}
	return true;
}


callback:: spawn_player_vehicle(playerid, sql_id)
{
	format(String512, sizeof(String512), "SELECT * FROM `player_vehicles` WHERE `id` = '%i'", sql_id);
	new Result:carfind = sql_query(zConn, String512, QUERY_CACHED);

	new all_veh = sql_num_rows(carfind);

	if(!all_veh)
		return true;

	new
		Float:x, Float:y, Float:z, Float:a, Float:ac_health,
		model,
		color1,
		color2,
		vw,
		veh_id;

	model = sql_get_field_assoc_int_ex(carfind, 0, "model");

	color1  = sql_get_field_assoc_int_ex(carfind, 0, "color_1"); 
	color2  = sql_get_field_assoc_int_ex(carfind, 0, "color_2"); 

    vw = sql_get_field_assoc_int_ex(carfind, 0, "parking_vw");

	x = sql_get_field_assoc_float_ex(carfind, 0, "parking_x");
	y = sql_get_field_assoc_float_ex(carfind, 0, "parking_y");
	z = sql_get_field_assoc_float_ex(carfind, 0, "parking_z");
	a = sql_get_field_assoc_float_ex(carfind, 0, "parking_a");

	for(new i; i < MAX_PLAYERS_VEHICLE_SL; i++)
	{
		if(vehicle_player_max[playerid][i] == 0)
		{
			veh_id = CreateVehicle(model, x, y, z, a, color1,color2, -1);
			vehicle_player_max_sql[playerid][i] = sql_id;
			vehicle_player_max[playerid][i] = veh_id;

			vehicle[vehicle_player_max[playerid][i]][cOwnTo] = sql_id;

			SetVehicleVirtualWorld(veh_id, vw);
			LinkVehicleToInterior(veh_id, 0);
			break;
		}
	}

	vehicle[veh_id][parking_garage] = sql_get_field_assoc_int_ex(carfind, 0, "parking_garage");

	vehicle[veh_id][vehicle_prize] = sql_get_field_assoc_int_ex(carfind, 0, "vehicle_prize");

	vehicle[veh_id][vehicle_world] = vw;

	if(vehicle[veh_id][parking_garage] == 1)
	{
		SetVehicleVirtualWorld(veh_id, vw);
		LinkVehicleToInterior(veh_id, 0);
	}


	sql_get_field_assoc_ex(carfind, 0, "number", vehicle[veh_id][cPlate], 24);
	sql_get_field_assoc_ex(carfind, 0, "number_region", vehicle[veh_id][cPlateRegion], 24);

	vehicle[veh_id][cPlateType] = sql_get_field_assoc_int_ex(carfind, 0, "number_type");

	vehicle[veh_id][v_vehicle] = sql_get_field_assoc_int_ex(carfind, 0, "id");

	sql_get_field_assoc_ex(carfind, 0, "buy_date_car", vehicle[veh_id][buy_date_car], 24); 


	if(vehicle[veh_id][cPlateType] == NUMBER_REGION_RU)
	{
		format(vehicle[veh_id][cPlate], 12, vehicle[veh_id][cPlate]);
		format(vehicle[veh_id][cPlateRegion], 12, vehicle[veh_id][cPlateRegion]);

		SetVehicleRuNumberPlate(veh_id, vehicle[veh_id][cPlate], vehicle[veh_id][cPlateRegion]);
	}
	else if(vehicle[veh_id][cPlateType] == NUMBER_REGION_KZ)
	{
		format(vehicle[veh_id][cPlate], 12, vehicle[veh_id][cPlate]);
		format(vehicle[veh_id][cPlateRegion], 12, vehicle[veh_id][cPlateRegion]);

		SetVehicleKzNumberPlate(veh_id, vehicle[veh_id][cPlate], vehicle[veh_id][cPlateRegion]);
	}
	else if(vehicle[veh_id][cPlateType] == NUMBER_REGION_BY)
	{
		format(vehicle[veh_id][cPlate], 12, vehicle[veh_id][cPlate]);
		format(vehicle[veh_id][cPlateRegion], 12, vehicle[veh_id][cPlateRegion]);

		SetVehicleBuNumberPlate(veh_id, vehicle[veh_id][cPlate]);
	}
	else if(vehicle[veh_id][cPlateType] == NUMBER_REGION_UA)
	{
		format(vehicle[veh_id][cPlate], 12, vehicle[veh_id][cPlate]);
		format(vehicle[veh_id][cPlateRegion], 12, vehicle[veh_id][cPlateRegion]);

		SetVehicleUaNumberPlate(veh_id, vehicle[veh_id][cPlate]);
	}
	else if(vehicle[veh_id][cPlateType] == 0)
	{
		format(vehicle[veh_id][cPlate], 12, "");
		format(vehicle[veh_id][cPlateRegion], 12, "");				
		SetVehicleNoPlateNumberPlate(veh_id, "-----", "---");
	}



    vehicle[veh_id][parking_x] = x;
    vehicle[veh_id][parking_y] = y;
    vehicle[veh_id][parking_z] = z;
    vehicle[veh_id][parking_a] = a;

	GetVehiclePos(veh_id, x, y, z);

	//SetPlayerRaceCheckpoint(playerid, 0, x, y, z, x, y, z, 5.0);
	status_navigator_player(playerid, TEXTDRAW_SHOW);

	vehicle[veh_id][cLock] = sql_get_field_assoc_int_ex(carfind, 0, "lock_status");

	vehicle[veh_id][parking_hotel] = sql_get_field_assoc_int_ex(carfind, 0, "parking_hotel");
	vehicle[veh_id][shtraf_car] = sql_get_field_assoc_int_ex(carfind, 0, "shtraf_car");
	vehicle[veh_id][parking_police] = sql_get_field_assoc_int_ex(carfind, 0, "parking_police");

    vehicle[veh_id][cMileage] = sql_get_field_assoc_float_ex(carfind, 0, "mileage");
    vehicle[veh_id][cFuel] = sql_get_field_assoc_float_ex(carfind, 0, "fuel");
    ac_health = sql_get_field_assoc_float_ex(carfind, 0, "health");

    vehicle[veh_id][cHealth] = ac_health;

    vehicle[veh_id][consumables_candles] = sql_get_field_assoc_float_ex(carfind, 0, "consumables_candles");
    vehicle[veh_id][consumables_oil] = sql_get_field_assoc_float_ex(carfind, 0, "consumables_oil");
    vehicle[veh_id][consumables_brake] = sql_get_field_assoc_float_ex(carfind, 0, "consumables_brake");
    vehicle[veh_id][consumables_belt] = sql_get_field_assoc_float_ex(carfind, 0, "consumables_belt");
    vehicle[veh_id][consumables_starter] = sql_get_field_assoc_float_ex(carfind, 0, "consumables_starter");
    vehicle[veh_id][consumables_generator] = sql_get_field_assoc_float_ex(carfind, 0, "consumables_generator");
    vehicle[veh_id][consumables_forsunki] = sql_get_field_assoc_float_ex(carfind, 0, "consumables_forsunki");
    vehicle[veh_id][consumables_fuel] = sql_get_field_assoc_float_ex(carfind, 0, "consumables_fuel");

    vehicle[veh_id][cEnergy] = sql_get_field_assoc_float_ex(carfind, 0, "energy_car");
    vehicle[veh_id][cGeneratorEnergy] = sql_get_field_assoc_float_ex(carfind, 0, "generator_energy");
    vehicle[veh_id][cBatteryEnergy] = sql_get_field_assoc_float_ex(carfind, 0, "battery_energy");


    sql_get_field_assoc_ex(carfind, 0, "consumables_candles_date", vehicle[veh_id][consumables_candles_date], 32);
    sql_get_field_assoc_ex(carfind, 0, "consumables_oil_date", vehicle[veh_id][consumables_oil_date], 32);
    sql_get_field_assoc_ex(carfind, 0, "consumables_brake_date", vehicle[veh_id][consumables_brake_date], 32);
    sql_get_field_assoc_ex(carfind, 0, "consumables_belt_date", vehicle[veh_id][consumables_belt_date], 32);
    sql_get_field_assoc_ex(carfind, 0, "consumables_starter_date", vehicle[veh_id][consumables_starter_date], 32);
    sql_get_field_assoc_ex(carfind, 0, "consumables_generator_date", vehicle[veh_id][consumables_generator_date], 32);
    sql_get_field_assoc_ex(carfind, 0, "consumables_forsunki_date", vehicle[veh_id][consumables_forsunki_date], 32);
    sql_get_field_assoc_ex(carfind, 0, "consumables_fuel_date", vehicle[veh_id][consumables_fuel_date], 32);


	SetVehicleHealth(veh_id, ac_health);

	RepairVehicle(veh_id);
	vehicle_lock_status(veh_id, vehicle[veh_id][cLock]);

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:info_gui_vehicle_unpark", 3000);

	sql_free_result(carfind);
	
	pData[playerid][car_id] = veh_id;
	return true;
}

stock dialog_all_player_vehicle(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
		case DIALOG_PLAYER_VEHICLE_LIST:
		{
			if(!response)
				return true;

			new
				car_num = listitem;

			if(car_num > 0 && vehicle_player_max_user[playerid] == 1 || car_num > 1 && vehicle_player_max_user[playerid] == 2 || car_num > 3 && vehicle_player_max_user[playerid] == 4 || car_num > 7 && vehicle_player_max_user[playerid] == 8)
			{
				SendErr(playerid, "Вам недоступен для загрузки остальной транспорт!");
				SendErr(playerid, "Для использования нескольких видов транспорта требуется гараж!");
				return show_player_cars(playerid);
			}


			if(GetPVarIntNew(playerid, "snow_work") == 1)
				return SendErr(playerid, "Невозможно использовать во время работы!");

			if(GetPVarIntNew(playerid, "bus_job_cp") == 1)
				return SendErr(playerid, "Невозможно использовать во время работы!");

			if(GetPVarIntNew(playerid, "active_player_house_newyear") == 1)
				return SendErr(playerid, "Невозможно использовать во время работы!");

			if(GetPVarIntNew(playerid, "trucker_job") == 1)
				return SendErr(playerid, "Невозможно использовать во время работы!");



			format(String512, sizeof(String512), "SELECT * FROM `player_vehicles` WHERE `owner` = '%s'", GetNameEx(playerid));
			new Result:result = sql_queryEx(zConn, String512, QUERY_CACHED);

			new all_veh = sql_num_rows(result);

			if(!all_veh)
				return SendErr(playerid, "Транспорт не найден");

			new 	
				sql_id = sql_get_field_assoc_int_ex(result, car_num, "id"),
				models = sql_get_field_assoc_int_ex(result, car_num, "model");


			if(get_player_veh_status(sql_id) == 1)
			{
				SetPVarIntNew(playerid, "vehicle_preload_models", models);
				return show_player_vehicle_menu(playerid, sql_id);
			}

			SendSucc(playerid, "Вы загрузили личное транспортное средство");

			vehicle_player_count_car_load[playerid]++;

			spawn_player_vehicle(playerid, sql_id);
			sql_free_result(result);
		}
	    case DIALOG_CAR_CHANGE_PANEL:
	    {
	    	if(!response)
	    		return true;

	    	new 
	    		sql_id = GetPVarIntNew(playerid, "player_vehicle_select_sql");

	    	switch(listitem)
	    	{

	    		case 0: return show_player_vehicle_menu(playerid, sql_id);
	    		case 1: return show_player_vehicle_menu(playerid, sql_id);
	    		case 2: return show_vehicle_info(playerid, sql_id);
	    		case 3:
	    		{
	    			get_player_vehicle_pos(playerid, sql_id);
	    			return show_player_vehicle_menu(playerid, sql_id);
	    		}
	    		case 4:
	    		{
	    			if(GetPlayerMoneyEx(playerid) < 1500)
	    			{
	    				show_player_vehicle_menu(playerid, sql_id);
	    				return SendErr(playerid, "У Вас недостаточно денег для буксировки транспортного средства!");
	    			}

	    			destroy_player_vehicle_id(playerid, sql_id);
	    			spawn_player_vehicle(playerid, sql_id);

	    			give_money(playerid, -1500, "Спавн транспорта");

	    			return SendSucc(playerid, "Вы зареспавнили личное транспортное средство!");
	    		}
	    		case 5:
	    		{
	    			return show_engine_car_cmd(playerid, sql_id);
	    		}
	    		case 6:
	    		{
	    			return dialog_accept_sell_car_gos(playerid);
	    		}
	    		case 7:
	    		{
	    			check_parking_vehicle_p(playerid, sql_id);
	    			return show_player_vehicle_menu(playerid, sql_id);
	    		}
				case 8:
				{
					remove_player_vehicle_server(playerid);
					
					SendInf(playerid, "Вы успешно выгрузили автомобиль с сервера!");
				}
	    	}
	    }
	    case DIALOG_ACCEPT_CAR_FINAL:
	    {
	    	new 
	    		sql_id = GetPVarIntNew(playerid, "player_vehicle_select_sql");

	    	if(!response)
	    		return show_player_vehicle_menu(playerid, sql_id);

	    	sell_car_gos_final(playerid);
	    }
	}
	return true;
}

callback:: remove_player_vehicle_server(playerid)
{

	for(new i; i < MAX_PLAYERS_VEHICLE_SL; i++)
	{
		if(vehicle_player_max[playerid][i] != 0)
		{

			if(CMarketInfo[playerid][mID] == vehicle_player_max[playerid][i])
			{
				stop_sell_car_player(playerid);
			}

			new
				Float:ac_health;

			GetVehicleHealth(vehicle_player_max[playerid][i], ac_health);


		    format(String2048, sizeof(String2048), "UPDATE `player_vehicles` SET \
		    	number = '%s',\
		    	lock_status = '%d',\
		    	parking_garage = '%d',\
		    	parking_hotel = '%d',\
		    	shtraf_car = '%d',\
		    	parking_police = '%d',\
		    	energy_car = '%f',\
		    	mileage = '%f',\
		    	fuel = '%f',\
		    	health = '%f',\
		    	consumables_candles = '%f',\
		    	consumables_oil = '%f',\
		    	consumables_brake = '%f',\
		    	consumables_belt = '%f',\
		    	consumables_starter = '%f',\
		    	consumables_generator = '%f',\
		    	consumables_forsunki = '%f',\
		    	consumables_fuel = '%f',\
		    	generator_energy = '%f',\
		    	battery_energy = '%f',\
		    	number_region = '%s',\
		    	number_type = '%d'\
		    	WHERE id = '%d' AND `owner` = '%s'",

		    	vehicle[vehicle_player_max[playerid][i]][cPlate],
				vehicle[vehicle_player_max[playerid][i]][cLock],
				vehicle[vehicle_player_max[playerid][i]][parking_garage],
				vehicle[vehicle_player_max[playerid][i]][parking_hotel],
				vehicle[vehicle_player_max[playerid][i]][shtraf_car],
				vehicle[vehicle_player_max[playerid][i]][parking_police],
				vehicle[vehicle_player_max[playerid][i]][cEnergy],
				vehicle[vehicle_player_max[playerid][i]][cMileage],
				vehicle[vehicle_player_max[playerid][i]][cFuel],
				ac_health,
				vehicle[vehicle_player_max[playerid][i]][consumables_candles],
				vehicle[vehicle_player_max[playerid][i]][consumables_oil],
				vehicle[vehicle_player_max[playerid][i]][consumables_brake],
				vehicle[vehicle_player_max[playerid][i]][consumables_belt],
				vehicle[vehicle_player_max[playerid][i]][consumables_starter],
				vehicle[vehicle_player_max[playerid][i]][consumables_generator],
				vehicle[vehicle_player_max[playerid][i]][consumables_forsunki],
				vehicle[vehicle_player_max[playerid][i]][consumables_fuel],


				vehicle[vehicle_player_max[playerid][i]][cGeneratorEnergy],
				vehicle[vehicle_player_max[playerid][i]][cBatteryEnergy],

				vehicle[vehicle_player_max[playerid][i]][cPlateRegion],
				vehicle[vehicle_player_max[playerid][i]][cPlateType],

		    	vehicle_player_max_sql[playerid][i], GetNameEx(playerid));

			sql_queryEx(zConn, String2048, QUERY_THREADED);

			DestroyVehicle(vehicle_player_max[playerid][i]);

			printf("Выгружен автомобиль с сервера! ID: %d | SQL ID: %d | №%d", vehicle_player_max[playerid][i], vehicle_player_max_sql[playerid][i], i);

			vehicle_player_max[playerid][i] = 0;
			vehicle_player_max_sql[playerid][i] = 0;

			vehicle_player_count_car_load[playerid] = 0;
		}
	}

	return true;
}

callback:: destroy_player_vehicle_id(playerid, sql_id)
{
	format(String512, sizeof(String512), "SELECT * FROM `player_vehicles` WHERE `id` = '%i'", sql_id);
	new Result:result = sql_queryEx(zConn, String512, QUERY_CACHED);

	new all_veh = sql_num_rows(result);

	if(!all_veh)
		return true;

	new 
		vehicle_id;

	for(new i; i < MAX_PLAYERS_VEHICLE_SL; i++)
	{

		if(vehicle_player_max_sql[playerid][i] == sql_id)
		{	
			vehicle_id = vehicle_player_max[playerid][i];

			if(CMarketInfo[playerid][mID] == vehicle_id)
			{
				stop_sell_car_player(playerid);
			}

			new
				Float:ac_health;

			GetVehicleHealth(vehicle_player_max[playerid][i], ac_health);


		    format(String2048, sizeof(String2048), "UPDATE `player_vehicles` SET \
		    	number = '%s',\
		    	lock_status = '%d',\
		    	parking_garage = '%d',\
		    	parking_hotel = '%d',\
		    	shtraf_car = '%d',\
		    	parking_police = '%d',\
		    	energy_car = '%f',\
		    	mileage = '%f',\
		    	fuel = '%f',\
		    	health = '%f',\
		    	consumables_candles = '%f',\
		    	consumables_oil = '%f',\
		    	consumables_brake = '%f',\
		    	consumables_belt = '%f',\
		    	consumables_starter = '%f',\
		    	consumables_generator = '%f',\
		    	consumables_forsunki = '%f',\
		    	consumables_fuel = '%f',\
		    	generator_energy = '%f',\
		    	battery_energy = '%f',\
		    	number_region = '%s',\
		    	number_type = '%d'\
		    	WHERE id = '%d' AND owner = '%s'",
		    	
		    	vehicle[vehicle_player_max[playerid][i]][cPlate],
				vehicle[vehicle_player_max[playerid][i]][cLock],
				vehicle[vehicle_player_max[playerid][i]][parking_garage],
				vehicle[vehicle_player_max[playerid][i]][parking_hotel],
				vehicle[vehicle_player_max[playerid][i]][shtraf_car],
				vehicle[vehicle_player_max[playerid][i]][parking_police],
				vehicle[vehicle_player_max[playerid][i]][cEnergy],
				vehicle[vehicle_player_max[playerid][i]][cMileage],
				vehicle[vehicle_player_max[playerid][i]][cFuel],
				ac_health,
				vehicle[vehicle_player_max[playerid][i]][consumables_candles],
				vehicle[vehicle_player_max[playerid][i]][consumables_oil],
				vehicle[vehicle_player_max[playerid][i]][consumables_brake],
				vehicle[vehicle_player_max[playerid][i]][consumables_belt],
				vehicle[vehicle_player_max[playerid][i]][consumables_starter],
				vehicle[vehicle_player_max[playerid][i]][consumables_generator],
				vehicle[vehicle_player_max[playerid][i]][consumables_forsunki],
				vehicle[vehicle_player_max[playerid][i]][consumables_fuel],


				vehicle[vehicle_player_max[playerid][i]][cGeneratorEnergy],
				vehicle[vehicle_player_max[playerid][i]][cBatteryEnergy],

				vehicle[vehicle_player_max[playerid][i]][cPlateRegion],
				vehicle[vehicle_player_max[playerid][i]][cPlateType],

		    	vehicle_player_max_sql[playerid][i], GetNameEx(playerid));

			sql_queryEx(zConn, String2048, QUERY_THREADED);
			DestroyVehicle(vehicle_id);

			vehicle_player_max[playerid][i] = 0;
			vehicle_player_max_sql[playerid][i] = 0;

			break;
		}
	}
	return true;
}

callback:: destroy_player_vehicle_death(playerid, vehicleid)
{
	if(vehicle_player_count_car_load[playerid] == 0)
		return true;

	if(vehicleid == 0 || vehicleid == INVALID_VEHICLE_ID)
		return true;


	new 
		sql_id = vehicle[vehicleid][cOwnTo];


	for(new i; i < MAX_PLAYERS_VEHICLE_SL; i++)
	{

		if(vehicle_player_max_sql[playerid][i] == sql_id)
		{
		
			if(CMarketInfo[playerid][mID] == vehicleid)
			{
				stop_sell_car_player(playerid);
			}
			new
				Float:ac_health;

			GetVehicleHealth(vehicle_player_max[playerid][i], ac_health);

		    format(String2048, sizeof(String2048), "UPDATE `player_vehicles` SET \
		    	number = '%s',\
		    	lock_status = '%d',\
		    	parking_garage = '%d',\
		    	parking_hotel = '%d',\
		    	shtraf_car = '%d',\
		    	parking_police = '%d',\
		    	energy_car = '%f',\
		    	mileage = '%f',\
		    	fuel = '%f',\
		    	health = '%f',\
		    	consumables_candles = '%f',\
		    	consumables_oil = '%f',\
		    	consumables_brake = '%f',\
		    	consumables_belt = '%f',\
		    	consumables_starter = '%f',\
		    	consumables_generator = '%f',\
		    	consumables_forsunki = '%f',\
		    	consumables_fuel = '%f',\
		    	generator_energy = '%f',\
		    	battery_energy = '%f',\
		    	number_region = '%s',\
		    	number_type = '%d'\
		    	WHERE id = '%d' AND owner = '%s'",
		    	
		    	vehicle[vehicle_player_max[playerid][i]][cPlate],
				vehicle[vehicle_player_max[playerid][i]][cLock],
				vehicle[vehicle_player_max[playerid][i]][parking_garage],
				vehicle[vehicle_player_max[playerid][i]][parking_hotel],
				vehicle[vehicle_player_max[playerid][i]][shtraf_car],
				vehicle[vehicle_player_max[playerid][i]][parking_police],
				vehicle[vehicle_player_max[playerid][i]][cEnergy],
				vehicle[vehicle_player_max[playerid][i]][cMileage],
				vehicle[vehicle_player_max[playerid][i]][cFuel],
				ac_health,
				vehicle[vehicle_player_max[playerid][i]][consumables_candles],
				vehicle[vehicle_player_max[playerid][i]][consumables_oil],
				vehicle[vehicle_player_max[playerid][i]][consumables_brake],
				vehicle[vehicle_player_max[playerid][i]][consumables_belt],
				vehicle[vehicle_player_max[playerid][i]][consumables_starter],
				vehicle[vehicle_player_max[playerid][i]][consumables_generator],
				vehicle[vehicle_player_max[playerid][i]][consumables_forsunki],
				vehicle[vehicle_player_max[playerid][i]][consumables_fuel],


				vehicle[vehicle_player_max[playerid][i]][cGeneratorEnergy],
				vehicle[vehicle_player_max[playerid][i]][cBatteryEnergy],

				vehicle[vehicle_player_max[playerid][i]][cPlateRegion],
				vehicle[vehicle_player_max[playerid][i]][cPlateType],

		    	vehicle_player_max_sql[playerid][i], GetNameEx(playerid));

			sql_queryEx(zConn, String2048, QUERY_THREADED);

			vehicle_player_max[playerid][i] = 0;
			vehicle_player_max_sql[playerid][i] = 0;


			DestroyVehicle(vehicleid);

			break;
		}
	}
	return true;
}


stock dialog_accept_sell_car_gos(playerid)
{

	SPD(playerid, DIALOG_ACCEPT_CAR_FINAL, DIALOG_STYLE_MSGBOX, !""cBLUE"Продажа авто в гос.стоимость", !"\
	"cWH"Вы уверены, что хотите продать автомобиль в гос.стоимость?\n\n\
	Вам будет возвращено 80% от стоимости!", !"Да", !"Нет");
	return true;
}

stock sell_car_gos_final(playerid)
{
	new 
		sql_id = GetPVarIntNew(playerid, "player_vehicle_select_sql");

	new 
		vehicle_id, vehicle_i_pos;

	for(new i; i < MAX_PLAYERS_VEHICLE_SL; i++)
	{
		if(vehicle_player_max_sql[playerid][i] == sql_id)
		{	
			vehicle_id = vehicle_player_max[playerid][i];
			vehicle_i_pos = i;
			break;
		}
	}

	new 
		final_money;

	if(vehicle[vehicle_id][vehicle_prize] == -1)
	{
		final_money = floatround(transport_config[GetVehicleModel(vehicle_id)-400][transport_price]*0.8);

		give_money(playerid, final_money, "Продажа личного транспорта");
	}

	new 
		query[256];

    format(query, sizeof(query), "DELETE FROM `player_vehicles` WHERE `id` = '%i'", sql_id);
    sql_queryEx(zConn, query);	

    if(vehicle[vehicle_id][vehicle_prize] == -1)
    {
	    SendSucc(playerid, "Вы успешно продали личный транспорт в гос.стоимость!");
	    format(String144, sizeof(String144), "Вы получили с продажи автомобиля в гос.стоимость "cGR"%d"cWH" рублей", final_money);
	    SendSucc(playerid, String144);

	    format(String144, sizeof(String144), "Продажа автомобиля SQL ID: %d | SERVER ID: %d | Марка: %s в гос.стоимость %d рублей", sql_id, vehicle_id, transport_config[GetVehicleModel(vehicle_id)-400][transport_name], final_money);
	    logs_vehicle(playerid, pData[playerid][pMysqlID], String144);
	}
	else
	{
	    SendSucc(playerid, "Вы успешно продали личный транспорт в гос.стоимость!");
	    format(String256, sizeof(String256), "Вы получили с продажи автомобиля в гос.стоимость "cGR"%d"cWH" рублей, так как это акционный транспорт!", 0);
	    SendSucc(playerid, String256);

	    format(String256, sizeof(String256), "Продажа акционного автомобиля SQL ID: %d | SERVER ID: %d | Марка: %s в гос.стоимость %d рублей", sql_id, vehicle_id, transport_config[GetVehicleModel(vehicle_id)-400][transport_name], 0);
	    logs_vehicle(playerid, pData[playerid][pMysqlID], String256);		
	}

    DestroyVehicle(vehicle_id);

	vehicle_player_max_sql[playerid][vehicle_i_pos] = 0;
	vehicle_player_max[playerid][vehicle_i_pos] = 0;

	vehicle_player_count_car_load[playerid]--;

	return true;
}

stock show_vehicle_info(playerid, sql_id)
{

	new 
		vehicle_id;

	for(new i; i < MAX_PLAYERS_VEHICLE_SL; i++)
	{
		if(vehicle_player_max_sql[playerid][i] == sql_id)
		{	
			vehicle_id = vehicle_player_max[playerid][i];

			break;
		}
	}

	new 
		model_car = GetVehicleModel(vehicle_id)-400;

    format(String2048, sizeof(String2048), "\
        "cGREY"Пункт\t"cGREY"Информация\n\
        "cBLUE"- "cWH"Наименование модели\t"cBLUE"%s\n\
        "cBLUE"- "cWH"Гос.цена автомобиля\t"cGR"%d рублей\n\
        "cBLUE"- "cWH"Объем бензобака автомобиля\t"cGR"%d литров\n\
        "cBLUE"- "cWH"Класс автомобиля\t"cBLUE"%s\n\
        "cBLUE"- "cWH"Возможность продажи\t"cBLUE"%s\n\
        "cBLUE"- "cWH"Возможность таксовать\t"cBLUE"%s\n\
        "cBLUE"- "cWH"Тип топлива\t"cBLUE"%s\n\
        "cBLUE"- "cWH"Максимальная скорость\t"cBLUE"%d KM/Ч", 
        transport_config[model_car][transport_name],
        transport_config[model_car][transport_price],
        transport_config[model_car][transport_tank],
        get_class_veh(model_car),
        (transport_config[model_car][transport_sell_active] == 1) ? (""cGR"Доступна") : (""cLRED"Отсутствует"),
        (transport_config[model_car][transport_taxi_active] == 1) ? (""cGR"Доступна") : (""cLRED"Отсутствует"),
       	get_fuel_type_veh(model_car),
       	transport_config[model_car][transport_max_speed]);
    return SPD(playerid, 0, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Информация об автомобиле", String2048, !"Выбрать", !"Закрыть"); 
}

stock show_engine_car_cmd(playerid, sql_id)
{
	new 
		vehicle_id;

	for(new i; i < MAX_PLAYERS_VEHICLE_SL; i++)
	{
		if(vehicle_player_max_sql[playerid][i] == sql_id)
		{	
			vehicle_id = vehicle_player_max[playerid][i];

			break;
		}
	}

	if(GetVehicleModel(vehicle_id) == TYPE_TESLA_1)
		return show_electrocar_engine_cmd(playerid, sql_id);

    format(String1024, sizeof(String1024), "\
        "cGREY"Запчасть\t"cGREY"Состояние\t"cGREY"Дата замены\n\
        "cBLUE"- "cWH"Количество масла\t"cGR"%d%%\t"cWH"%s\n\
        "cBLUE"- "cWH"Состояние свечей\t"cGR"%d%%\t"cWH"%s\n\
        "cBLUE"- "cWH"Состояние тормозов\t"cGR"%d%%\t"cWH"%s\n\
        "cBLUE"- "cWH"Состояние ремней\t"cGR"%d%%\t"cWH"%s\n\
        "cBLUE"- "cWH"Состояние стартера\t"cGR"%d%%\t"cWH"%s\n\
        "cBLUE"- "cWH"Состояние генератора\t"cGR"%d%%\t"cWH"%s\n\
        "cBLUE"- "cWH"Состояние форсунок\t"cGR"%d%%\t"cWH"%s\n\
        "cBLUE"- "cWH"Состояние насосов\t"cGR"%d%%\t"cWH"%s\n\
        "cBLUE"\t\n\
        "cBLUE"- "cWH"Пробег автомобиля\t"cGR"%d км", 
        floatround(vehicle[vehicle_id][consumables_oil], floatround_round),
        vehicle[vehicle_id][consumables_candles_date],
        floatround(vehicle[vehicle_id][consumables_candles], floatround_round),
        vehicle[vehicle_id][consumables_oil_date],
		floatround(vehicle[vehicle_id][consumables_brake], floatround_round),
		vehicle[vehicle_id][consumables_brake_date],
		floatround(vehicle[vehicle_id][consumables_belt], floatround_round),
		vehicle[vehicle_id][consumables_belt_date],
		floatround(vehicle[vehicle_id][consumables_starter], floatround_round),
		vehicle[vehicle_id][consumables_starter_date],
		floatround(vehicle[vehicle_id][consumables_generator], floatround_round),
		vehicle[vehicle_id][consumables_generator_date],
		floatround(vehicle[vehicle_id][consumables_forsunki], floatround_round),
		vehicle[vehicle_id][consumables_forsunki_date],
		floatround(vehicle[vehicle_id][consumables_fuel], floatround_round),
		vehicle[vehicle_id][consumables_fuel_date],
		floatround(vehicle[vehicle_id][cMileage], floatround_round));
    return SPD(playerid, DIALOG_ENGINE_STATUS, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Состояние автомобиля:", String1024, !"Выбрать", !"Закрыть"); 


}

stock show_electrocar_engine_cmd(playerid, sql_id)
{

	new 
		vehicle_id;

	for(new i; i < MAX_PLAYERS_VEHICLE_SL; i++)
	{
		if(vehicle_player_max_sql[playerid][i] == sql_id)
		{	
			vehicle_id = vehicle_player_max[playerid][i];
			break;
		}
	}

    format(String1024, sizeof(String1024), "\
        "cGREY"Запчасть\t"cGREY"Состояние\t"cGREY"Дата замены\n\
        "cBLUE"- "cWH"Состояние тормозов\t"cGR"%d%%\t"cWH"%s\n\
        "cBLUE"- "cWH"Состояние генератора\t"cGR"%d%%\t"cWH"%s\n\
        "cBLUE"- "cWH"Состояние батареи\t"cGR"%d%%\t"cWH"%s\n\
        "cBLUE"\t\n\
        "cBLUE"- "cWH"Пробег автомобиля\t"cGR"%d км", 
		floatround(vehicle[vehicle_id][consumables_brake], floatround_round),
		vehicle[vehicle_id][consumables_brake_date],
		floatround(vehicle[vehicle_id][cGeneratorEnergy], floatround_round),
		vehicle[vehicle_id][consumables_generator_date],
		floatround(vehicle[vehicle_id][cBatteryEnergy], floatround_round),
		vehicle[vehicle_id][consumables_fuel_date],
		floatround(vehicle[vehicle_id][cMileage], floatround_round));
    return SPD(playerid, DIALOG_ENGINE_STATUS_ELECTRO, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Состояние автомобиля:", String1024, !"Выбрать", !"Закрыть"); 

}