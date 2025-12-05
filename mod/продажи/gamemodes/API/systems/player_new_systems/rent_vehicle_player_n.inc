



stock create_pickup_rent_n()
{

	// Спавн в неизвестном мне городе

	collizion_zone_spawn[0] = CreateDynamicSphere(1819.2357,2515.8604,15.6610, 35.0, -1,-1);

	create_circle_pickup_o(1816.4521,2520.7129,15.6610, TRIGGER_LBLUE);
	create_circle_pickup_o(1819.3401,2516.1885,15.6610, TRIGGER_LBLUE);
	create_circle_pickup_o(2743.9609,-2438.1252,21.8921, TRIGGER_LBLUE);
	create_circle_pickup_o(2743.8938,-2430.8013,21.8921, TRIGGER_LBLUE);

	create_circle_pickup_o(-478.5557,921.9304,11.9629, TRIGGER_LBLUE);
	create_circle_pickup_o(-478.1979,911.7108,11.9629, TRIGGER_LBLUE);

	create_circle_pickup_o(-2478.9338,2829.7532,37.6340, TRIGGER_LBLUE);
	create_circle_pickup_o(-2478.8167,2838.9043,37.6340, TRIGGER_LBLUE);

	create_circle_pickup_o(2482.4119,-2143.7095,21.9007, TRIGGER_LBLUE);
	create_circle_pickup_o(2510.0396,-2143.0569,21.9766, TRIGGER_LBLUE);
	create_circle_pickup_o(-38.2472,913.0458,12.0173, TRIGGER_LBLUE);
	create_circle_pickup_o(-24.8196,907.9672,12.0020, TRIGGER_LBLUE);


	CreateDynamic3DTextLabel(""cWH"Аренда Транспорта\n"cBLUE"«ALT»",-1, \
  		2482.4119,-2143.7095,21.9007, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	CreateDynamic3DTextLabel(""cWH"Аренда Транспорта\n"cBLUE"«ALT»",-1, \
  		2510.0396,-2143.0569,21.9766, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	CreateDynamic3DTextLabel(""cWH"Аренда Транспорта\n"cBLUE"«ALT»",-1, \
  		-38.2472,913.0458,12.0173, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	CreateDynamic3DTextLabel(""cWH"Аренда Транспорта\n"cBLUE"«ALT»",-1, \
  		-24.8196,907.9672,12.0020, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	

	CreateDynamic3DTextLabel(""cWH"Аренда Транспорта\n"cBLUE"«ALT»",-1, \
  		1816.4521,2520.7129,15.6610, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	CreateDynamic3DTextLabel(""cWH"Аренда Транспорта\n"cBLUE"«ALT»",-1, \
  		1819.3401,2516.1885,15.6610, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	CreateDynamic3DTextLabel(""cWH"Аренда Транспорта\n"cBLUE"«ALT»",-1, \
  		2743.9609,-2438.1252,21.8921, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	CreateDynamic3DTextLabel(""cWH"Аренда Транспорта\n"cBLUE"«ALT»",-1, \
  		2743.8938,-2430.8013,21.8921, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	

	CreateDynamic3DTextLabel(""cWH"Аренда Транспорта\n"cBLUE"«ALT»",-1, \
  		-478.5557,921.9304,11.9629, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	CreateDynamic3DTextLabel(""cWH"Аренда Транспорта\n"cBLUE"«ALT»",-1, \
  		-478.1979,911.7108,11.9629, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	

	CreateDynamic3DTextLabel(""cWH"Аренда Транспорта\n"cBLUE"«ALT»",-1, \
  		-2478.9338,2829.7532,37.6340, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	CreateDynamic3DTextLabel(""cWH"Аренда Транспорта\n"cBLUE"«ALT»",-1, \
  		-2478.8167,2838.9043,37.6340, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	



	create_dynamic_area(1816.4521,2520.7129,15.6610, -1, 1, RENT_START_GAME, 2.5); // Спавн в Батырево
	create_dynamic_area(1819.3401,2516.1885,15.6610, -1, 2, RENT_START_GAME, 2.5); // Спавн в Батырево

	create_dynamic_area(2743.9609,-2438.1252,21.8921, -1, 3, RENT_START_GAME, 2.5);	// Спавн Южный
	create_dynamic_area(2743.8938,-2430.8013,21.8921, -1, 4, RENT_START_GAME, 2.5);	// Спавн Южный

	create_dynamic_area(-478.5557,921.9304,11.9629, -1, 5, RENT_START_GAME, 2.5);	// Спавн Арзамас
	create_dynamic_area(-478.1979,911.7108,11.9629, -1, 6, RENT_START_GAME, 2.5);	// Спавн Арзамас

	create_dynamic_area(-2478.9338,2829.7532,37.6340, -1, 7, RENT_START_GAME, 2.5);	// Спавн Село какое-то
	create_dynamic_area(-2478.8167,2838.9043,37.6340, -1, 8, RENT_START_GAME, 2.5);	// Спавн Село какое-то

	create_dynamic_area(2482.4119,-2143.7095,21.9007, -1, 9, RENT_START_GAME, 2.5);	// Спавн Село какое-то
	create_dynamic_area(2510.0396,-2143.0569,21.9766, -1, 10, RENT_START_GAME, 2.5);	// Спавн Село какое-то
	create_dynamic_area(-38.2472,913.0458,12.0173, -1, 11, RENT_START_GAME, 2.5);	// Спавн Село какое-то
	create_dynamic_area(-24.8196,907.9672,12.0020, -1, 12, RENT_START_GAME, 2.5);	// Спавн Село какое-то	

	// временные позиции работы

	create_circle_pickup_o(-1375.8782,2655.2493,40.5409, TRIGGER_LBLUE);	
	CreateDynamic3DTextLabel(""cWH"Аренда Транспорта\n"cBLUE"«ALT»",-1, \
  		-1375.8782,2655.2493,40.5409, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	create_dynamic_area(-1375.8782,2655.2493,40.5409, -1, 13, RENT_START_GAME, 2.5);	// Шахта

	create_circle_pickup_o(-1037.7129,-2460.3850,28.4990, TRIGGER_LBLUE);	
	CreateDynamic3DTextLabel(""cWH"Аренда Транспорта\n"cBLUE"«ALT»",-1, \
  		-1037.7129,-2460.3850,28.4990, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	create_dynamic_area(-1037.7129,-2460.3850,28.4990, -1, 14, RENT_START_GAME, 2.5);	// Лесопилка

	create_circle_pickup_o(2319.5566,2038.9712,15.9863, TRIGGER_LBLUE);	
	CreateDynamic3DTextLabel(""cWH"Аренда Транспорта\n"cBLUE"«ALT»",-1, \
  		2319.5566,2038.9712,15.9863, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	create_dynamic_area(2319.5566,2038.9712,15.9863, -1, 15, RENT_START_GAME, 2.5);	// Завод


	create_circle_pickup_o(-493.7344,21.0193,13.7192, TRIGGER_LBLUE);	
	CreateDynamic3DTextLabel(""cWH"Аренда Транспорта\n"cBLUE"«ALT»",-1, \
  		-493.7344,21.0193,13.7192, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	create_dynamic_area(-493.7344,21.0193,13.7192, -1, 16, RENT_START_GAME, 2.5);	// Автошкола

	create_circle_pickup_o(390.7425,1776.1871,12.1223, TRIGGER_LBLUE);	
	CreateDynamic3DTextLabel(""cWH"Аренда Транспорта\n"cBLUE"«ALT»",-1, \
  		390.7425,1776.1871,12.1223, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	create_dynamic_area(390.7425,1776.1871,12.1223, -1, 17, RENT_START_GAME, 2.5);	// Больница Арзамаса

	create_circle_pickup_o(2106.5066,-2387.6431,21.9430, TRIGGER_LBLUE);	
	CreateDynamic3DTextLabel(""cWH"Аренда Транспорта\n"cBLUE"«ALT»",-1, \
  		2106.5066,-2387.6431,21.9430, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	create_dynamic_area(2106.5066,-2387.6431,21.9430, -1, 18, RENT_START_GAME, 2.5);	// Больница Южный


	return true;
}


stock rent_vehicle_player_n(playerid)
{

	if(pData[playerid][pLevel] < 4)
	{

	    if(GetPVarIntNew(playerid, "miner_job"))
	    	return SendErr(playerid, "Вы не можете аредовать скутер, когда работаете шахтером!");

	    if(GetPVarIntNew(playerid, "factoryjob"))
	    	return SendErr(playerid, "Вы не можете аредовать скутер, когда работаете на заводе!");

	    if(GetPVarIntNew(playerid, "wood_job"))
	    	return SendErr(playerid, "Вы не можете аредовать скутер, когда работаете на лесопилке!");


		if(pTemp[playerid][rent_car] != INVALID_VEHICLE_ID)
		{
			SendInf(playerid, "Вы уже арендуете какой-либо транспорт");
			return true; 
		}


		new 
			c1 = random(256),
			c2 = random(256);	

		new 
			Float:x, Float:y, Float:z;

		GetPlayerPos(playerid, x, y, z);
		x += 1.5;

		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_RIGHT, "brilliantother:info_gui_vehicle_rent", 3500);

		new 
			rent_fagio = CreateVehicle(462, x, y, z, 0.0, c1, c2, 600);	

		LinkVehicleToInterior(rent_fagio,GetPlayerInterior(playerid));
		SetVehicleVirtualWorld(rent_fagio, GetPlayerVirtualWorld(playerid));

		SetPVarIntNew(playerid, "first_enter_veh", 1);
		PutPlayerInVehicleEx(playerid, rent_fagio, 0);

		vehicle[rent_fagio][cFuel] = def_vehicle[cFuel];
		vehicle[rent_fagio][cHealth] = 1000.0;
		vehicle[rent_fagio][cIsCreated] = true;

		vehicle[rent_fagio][cOwnTo] = VEHICLE_START_GAME;

		vehicle[rent_fagio][cIsRent] = true;

		vehicle[rent_fagio][cLock] = 2;

		vehicle[rent_fagio][consumables_oil] = 1000.0;

		vehicle_lock_status(rent_fagio, true);



		SCM(playerid, -1, "");
		SendSucc(playerid, "Вы успешно взяли в аренду мопед!");
		SendInf(playerid, "Мопед был автоматически закрыт для избежания его кражи!");
		SendInf(playerid, "Открыть или закрыть мопед - /lock 2");
		SendInf(playerid, "Чтобы отменить аренду мопеда используйте команду - /unrent");
		SCM(playerid, -1, "");

		if(pData[playerid][pLevel] == 1)
		{
		    format(String512, sizeof(String512), "\
		        "cGREY"Пункт\t"cGREY"Расстояние\n\
				"cBLUE"1. "cWH"Шахта\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"2. "cWH"Лесопилка\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"3. "cWH"Завод\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"4. "cWH"Водитель автобуса\t%d"cBLUE" метров"cWH"", 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_WORK_MINER)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_WORK_WOOD)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_WORK_ZAVOD)),
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_WORK_BUS)));
		    SPD(playerid, DIALOG_GPS_JOB, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Работы", String512, !"Выбрать", !"Закрыть"); 
		}

		pTemp[playerid][rent_car] = rent_fagio;

		return true;

	}
	if(pData[playerid][pLevel] > 3)
	{
	    if(GetPVarIntNew(playerid, "miner_job"))
	    	return SendErr(playerid, "Вы не можете аредовать скутер, когда работаете шахтером!");

	    if(GetPVarIntNew(playerid, "factoryjob"))
	    	return SendErr(playerid, "Вы не можете аредовать скутер, когда работаете на заводе!");

	    if(GetPVarIntNew(playerid, "wood_job"))
	    	return SendErr(playerid, "Вы не можете аредовать скутер, когда работаете на лесопилке!");
		
		new 
			hour, minute, second;

		gettime(hour, minute, second);
		
		if(hour >= 23 && minute >= 0 && second >= 0 && hour < 8 && minute >= 0 && second >= 0)
			return SendErr(playerid, "Аренда доступна с 23 часов вечера и до 8 утра по Серверному времени!");

		if(pTemp[playerid][rent_car] != INVALID_VEHICLE_ID)
		{
			SendInf(playerid, "Вы уже арендуете какой-либо транспорт");
			return true; 
		}


		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_RIGHT, "brilliantother:info_gui_vehicle_rent", 3500);

		new 
			c1 = random(256),
			c2 = random(256);	

		new 
			Float:x, Float:y, Float:z;

		GetPlayerPos(playerid, x, y, z);
		x += 1.5;

		new 
			rent_fagio = CreateVehicle(462, x, y, z, 0.0, c1, c2, 600);	

		LinkVehicleToInterior(rent_fagio,GetPlayerInterior(playerid));
		SetVehicleVirtualWorld(rent_fagio, GetPlayerVirtualWorld(playerid));

		SetPVarIntNew(playerid, "first_enter_veh", 1);

		PutPlayerInVehicleEx(playerid, rent_fagio, 0);

		vehicle[rent_fagio][cFuel] = def_vehicle[cFuel];
		vehicle[rent_fagio][cHealth] = 1000.0;
		vehicle[rent_fagio][cIsCreated] = true;

		vehicle[rent_fagio][cOwnTo] = VEHICLE_START_GAME;

		vehicle[rent_fagio][cIsRent] = true;

		vehicle[rent_fagio][cLock] = 2;

		vehicle[rent_fagio][consumables_oil] = 1000.0;

		vehicle_lock_status(rent_fagio, true);

		SCM(playerid, -1, "");
		SendSucc(playerid, "Вы успешно взяли в аренду мопед, так как отсутствуют другие способы передвижения!");
		SendInf(playerid, "Мопед был автоматически закрыт для избежания его кражи!");
		SendInf(playerid, "Открыть или закрыть мопед - /lock 2");
		SCM(playerid, -1, "");

		pTemp[playerid][rent_car] = rent_fagio;		

		return true;
	} 

	return true;
}