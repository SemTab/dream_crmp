static const Float:position_spawn_police_car_1[][] =
{
	{168.5801,1276.2194,5.1747,258.7832},
	{168.1637,1272.0826,5.1747,258.1454},
	{167.0975,1268.2930,5.1746,258.1841},
	{164.7701,1257.2832,5.1748,258.1845},
	{163.9179,1253.2584,5.1747,259.5934},
	{163.1035,1249.2577,5.1747,259.0452},
	{162.2700,1245.1857,5.1748,258.5002},
	{161.4317,1241.2384,5.1748,258.8195},
	{160.9364,1237.4570,5.1748,258.8775},
	{159.8587,1232.7363,5.1748,259.1055},
	{158.9762,1229.0916,5.1777,257.9242},
	{158.1846,1225.1937,5.1747,257.9868},
	{155.8680,1214.1494,5.1747,258.4004},
	{154.9189,1210.3082,5.1776,258.0960},
	{154.1556,1206.1423,5.1747,258.1957},
	{153.4173,1202.0922,5.1747,258.0408},
	{152.5817,1197.9452,5.1762,257.4240},
	{151.8844,1193.8307,5.1747,258.2355},
	{143.4719,1195.5996,5.1801,78.2354},
	{144.5682,1199.7709,5.1748,78.3533},
	{145.5125,1203.7002,5.1747,78.4179},
	{146.5102,1207.8143,5.1747,78.5025},
	{147.0365,1211.8080,5.1748,78.1967},
	{147.9721,1215.8625,5.1746,77.3258},
	{150.3006,1226.6534,5.1746,77.6959},
	{151.1582,1230.6868,5.1746,78.3763},
	{151.8046,1234.6627,5.1746,77.9035},
	{152.5559,1239.1488,5.1801,77.9684},
	{153.4079,1242.8162,5.1746,78.0696},
	{154.4789,1246.8303,5.1748,77.8456},
	{155.4377,1250.8032,5.1746,78.6539},
	{156.2522,1254.8519,5.1747,79.7508},
	{156.4769,1259.0334,5.1747,77.5242},
	{159.0281,1269.9037,5.1748,78.7412},
	{159.6900,1273.8661,5.1747,77.8851},
	{160.6373,1277.8273,5.1747,78.3288}
};


static const Float:position_spawn_police_car_2[][] =
{
	{2578.2183,-2446.2773,21.5369,1.2668}, // ПД Южный 1
	{2574.7456,-2446.3757,21.5414,358.7095}, // ПД Южный 2
	{2571.1733,-2446.1843,21.5413,0.0156}, // ПД Южный 3
	{2567.5576,-2446.1270,21.5414,359.7522}, // ПД Южный 4
	{2563.8054,-2446.3618,21.5414,359.7100}, // ПД Южный 5
	{2560.2542,-2446.2537,21.5413,359.5957}, // ПД Южный 6
	{2556.6335,-2446.3718,21.5414,359.6219}, // ПД Южный 7
	{2552.9524,-2446.3064,21.5413,359.5277}, // ПД Южный 8
	{2549.6099,-2446.1660,21.5414,358.2723}, // ПД Южный 9
	{2543.3289,-2446.8069,21.5414,271.0926}, // ПД Южный 10
	{2542.9963,-2440.4919,21.5414,269.9392}, // ПД Южный 11
	{2542.8445,-2434.2197,21.5414,269.4773}, // ПД Южный 12
	{2543.1440,-2427.8218,21.5414,269.7175}, // ПД Южный 13
	{2543.0083,-2421.5774,21.5414,269.3903}, // ПД Южный 14
	{2543.0408,-2415.2803,21.5413,269.7816}, // ПД Южный 15
	{2543.1270,-2408.9111,21.5413,268.6598}, // ПД Южный 16
	{2559.8789,-2408.1794,21.5413,89.1126}, // ПД Южный 17
	{2559.7939,-2411.7358,21.5414,89.5416}, // ПД Южный 18
	{2559.9849,-2415.6558,21.5413,87.5702}, // ПД Южный 19
	{2559.9426,-2419.7651,21.5413,89.8326}, // ПД Южный 20
	{2560.0330,-2424.3232,21.5414,87.2603} // ПД Южный 21
};


new police_car_model[] =
{
	596, 597, 598, 427
};


stock create_police_other_element()
{


	number_gai_free = create_circle_pickup(537.8614,324.3953,1201.9609, TRIGGER_LRED, 2);
	CreateDynamic3DTextLabel(""cWH"Получение бесплатных номерных знаков\n\
		"cLRED"[Встаньте на пикап]", CWHITE, 537.8614,324.3953,1201.9609, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 2);

	area_buy_weapon_lic = CreateDynamicSphere(537.8614,324.3953,1201.9609, 1.0, 1);

	CreateDynamic3DTextLabel(""cWH"Покупка лицензии на оружие\n\
		"cLRED"[Встаньте на пикап]", CWHITE, 537.8614,324.3953,1201.9609, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 1);		

	pickup_spawn_car_police[0] = create_circle_pickup(164.8644,1277.6555,5.6389, TRIGGER_LRED);

	CreateDynamic3DTextLabel(""cWH"Автопарк Полиции г.Арзамас\n\
		"cLRED"[Встаньте на пикап]", CWHITE, 164.8644,1277.6555,5.6389, 5.0,INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);


	pickup_spawn_car_police[1] = create_circle_pickup(2578.7800,-2440.5547,21.9865, TRIGGER_LRED);

	CreateDynamic3DTextLabel(""cWH"Автопарк Полиции г.Южный\n\
		"cLRED"[Встаньте на пикап]", CWHITE, 2578.7800,-2440.5547,21.9865, 5.0,INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);

	count_police_vehicle = 30;


	return true;
}


stock spawn_police_vehicle(playerid)
{
	if(!IsACop(playerid))
		return SendErr(playerid, "Вы не являетесь сотрудником МВД!"); 

	format(String512, sizeof(String512), "\
    "cGREY"Автомобиль\t"cGREY"Действие\n\
    "cBLUE"1. "cWH"%s\t"cGR"Взять\n\
    "cBLUE"2. "cWH"%s\t"cGR"Взять\n\
    "cBLUE"3. "cWH"%s\t"cGR"Взять\n\
    "cBLUE"4. "cWH"%s\t"cGR"Взять\n\
    \t\n\
    "cWH"Доступно всего: \t"cBLUE"%d"cWH" автомобилей", 
    transport_config[police_car_model[0]-400][transport_name],
    transport_config[police_car_model[1]-400][transport_name],
    transport_config[police_car_model[2]-400][transport_name],
    transport_config[police_car_model[3]-400][transport_name],
    count_police_vehicle
    );
 	SPD(playerid, DIALOG_SELECT_CAR_POLICE, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Выбор автомобиля", String512, !"Выбрать", !"Закрыть"); 

 	return true;
}

stock spawn_police_veh_start(playerid, type_car)
{
	switch(type_car)
	{
		case 0:
		{
			if(count_police_vehicle == 0)
			{
				spawn_police_vehicle(playerid);
				return SendErr(playerid, "Недостаточно госсударственных автомобилей!");
			}
    
			if(!IsACop(playerid))
			{
				SendErr(playerid, "Доступно только полицейским!");
				return true;
			}	

			create_vehicle_police(playerid, 0);
		}
		case 1:
		{
			if(count_police_vehicle == 0)
			{
				spawn_police_vehicle(playerid);
				return SendErr(playerid, "Недостаточно госсударственных автомобилей!");
			}

			if(!IsACop(playerid))
			{
				SendErr(playerid, "Доступно только полицейским!");
				return true;
			}	

			create_vehicle_police(playerid, 1);
		}
		case 2:
		{
			if(count_police_vehicle == 0)
			{
				spawn_police_vehicle(playerid);
				return SendErr(playerid, "Недостаточно госсударственных автомобилей!");
			}

			if(!IsACop(playerid))
			{
				SendErr(playerid, "Доступно только полицейским!");
				return true;
			}	

			create_vehicle_police(playerid, 2);
		}
		case 3:
		{
			if(count_police_vehicle == 0)
			{
				spawn_police_vehicle(playerid);
				return SendErr(playerid, "Недостаточно госсударственных автомобилей!");
			}

			if(!IsACop(playerid))
			{
				SendErr(playerid, "Доступно только полицейским!");
				return true;
			}	

			create_vehicle_police(playerid, 3);
		}
		case 4:
		{
			if(count_police_vehicle == 0)
			{
				spawn_police_vehicle(playerid);
				return SendErr(playerid, "Недостаточно госсударственных автомобилей!");
			}

			if(!IsACop(playerid))
			{
				SendErr(playerid, "Доступно только полицейским!");
				return true;
			}	

			create_vehicle_police(playerid, 4);
		}
	}

	return true;
}

stock create_vehicle_police(playerid, veh_type)
{

	new 
		Float:x, 
		Float:y,
		Float:z;

	GetPlayerPos(playerid, x, y, z);

	
	if(IsPlayerInRangeOfPoint(playerid, 50.0, 164.6990,1277.6998,5.6389))
	{
		new 
			random_pos = random(35);

		new 
			c1 = 1,
			c2 = 7;	

		new 
			vehicle_police = CreateVehicle(police_car_model[veh_type], position_spawn_police_car_1[random_pos][0], position_spawn_police_car_1[random_pos][1], position_spawn_police_car_1[random_pos][2], position_spawn_police_car_1[random_pos][3], c1, c2, 600);	

		format(vehicle[vehicle_police][cPlate], 20, "а%dаа", count_police_vehicle);
		SetVehicleRuPolNumberPlate(vehicle_police, vehicle[vehicle_police][cPlate], "77");

		PutPlayerInVehicleEx(playerid, vehicle_police, 0);

		vehicle[vehicle_police][cFuel] = transport_config[GetVehicleModel(vehicle_police)-400][transport_tank];
		vehicle[vehicle_police][cHealth] = 1000.0;
		vehicle[vehicle_police][cIsCreated] = true;
		vehicle[vehicle_police][consumables_oil] = 1000.0;

		vehicle[vehicle_police][cOwnTo] = VEHICLE_POLICES;

		vehicle[vehicle_police][cLock] = 2;

		vehicle_lock_status(vehicle_police, true);
		
	}
	else if(!IsPlayerInRangeOfPoint(playerid, 50.0, 164.6990,1277.6998,5.6389))
	{
		new 
			random_pos = random(20);

		new 
			c1 = 1,
			c2 = 7;	

		new 
			vehicle_police = CreateVehicle(police_car_model[veh_type], position_spawn_police_car_2[random_pos][0], position_spawn_police_car_2[random_pos][1], position_spawn_police_car_2[random_pos][2], position_spawn_police_car_2[random_pos][3], c1, c2, 600);	

		format(vehicle[vehicle_police][cPlate], 20, "а%dаа", count_police_vehicle);
		SetVehicleRuPolNumberPlate(vehicle_police, vehicle[vehicle_police][cPlate], "77");

		PutPlayerInVehicleEx(playerid, vehicle_police, 0);	

		vehicle[vehicle_police][cFuel] = transport_config[GetVehicleModel(vehicle_police)-400][transport_tank];
		vehicle[vehicle_police][cHealth] = 1000.0;
		vehicle[vehicle_police][cIsCreated] = true;
		vehicle[vehicle_police][consumables_oil] = 1000.0;

		vehicle[vehicle_police][cOwnTo] = VEHICLE_POLICES;

		vehicle[vehicle_police][cLock] = 2;

		vehicle_lock_status(vehicle_police, true);

	}


	count_police_vehicle--;

	return true;
}


stock select_number_veh_buy(playerid, status)
{
	switch(status)
	{
		case TEXTDRAW_SHOW:
		{	

			TextDrawShowForPlayer(playerid, buy_number_gai[0]);
			TextDrawShowForPlayer(playerid, buy_number_gai[1]);
			TextDrawShowForPlayer(playerid, buy_number_gai[2]);
			TextDrawShowForPlayer(playerid, buy_number_gai[3]);
			TextDrawShowForPlayer(playerid, buy_number_gai[4]);
			TextDrawShowForPlayer(playerid, buy_number_gai[5]);
			TextDrawShowForPlayer(playerid, buy_number_gai[6]);
			TextDrawShowForPlayer(playerid, buy_number_gai[7]);
			TextDrawShowForPlayer(playerid, buy_number_gai[8]);
			TextDrawShowForPlayer(playerid, buy_number_gai[9]);
			TextDrawShowForPlayer(playerid, buy_number_gai[10]);
			TextDrawShowForPlayer(playerid, buy_number_gai[11]);
			TextDrawShowForPlayer(playerid, buy_number_gai[12]);

			create_buy_number_gai_p(playerid);

			PlayerTextDrawShow(playerid, buy_number_gai_p[0][playerid]);
			PlayerTextDrawShow(playerid, buy_number_gai_p[1][playerid]);
			PlayerTextDrawShow(playerid, buy_number_gai_p[2][playerid]);
			PlayerTextDrawShow(playerid, buy_number_gai_p[3][playerid]);
			PlayerTextDrawShow(playerid, buy_number_gai_p[4][playerid]);
			PlayerTextDrawShow(playerid, buy_number_gai_p[5][playerid]);

			SelectTextDraw(playerid, COLOR_BLUE);

		}
		case TEXTDRAW_HIDE:
		{
			TextDrawHideForPlayer(playerid, buy_number_gai[0]);
			TextDrawHideForPlayer(playerid, buy_number_gai[1]);
			TextDrawHideForPlayer(playerid, buy_number_gai[2]);
			TextDrawHideForPlayer(playerid, buy_number_gai[3]);
			TextDrawHideForPlayer(playerid, buy_number_gai[4]);
			TextDrawHideForPlayer(playerid, buy_number_gai[5]);
			TextDrawHideForPlayer(playerid, buy_number_gai[6]);
			TextDrawHideForPlayer(playerid, buy_number_gai[7]);
			TextDrawHideForPlayer(playerid, buy_number_gai[8]);
			TextDrawHideForPlayer(playerid, buy_number_gai[9]);
			TextDrawHideForPlayer(playerid, buy_number_gai[10]);
			TextDrawHideForPlayer(playerid, buy_number_gai[11]);
			TextDrawHideForPlayer(playerid, buy_number_gai[12]);


			PlayerTextDrawHideEx(playerid, buy_number_gai_p[0][playerid]);
			PlayerTextDrawHideEx(playerid, buy_number_gai_p[1][playerid]);
			PlayerTextDrawHideEx(playerid, buy_number_gai_p[2][playerid]);
			PlayerTextDrawHideEx(playerid, buy_number_gai_p[3][playerid]);
			PlayerTextDrawHideEx(playerid, buy_number_gai_p[4][playerid]);
			PlayerTextDrawHideEx(playerid, buy_number_gai_p[5][playerid]);

			CancelSelectTextDraw(playerid);
		}
	}
	return true;
}

stock select_number_veh_free(playerid, status)
{
	switch(status)
	{
		case TEXTDRAW_SHOW:
		{	

			TextDrawShowForPlayer(playerid, free_number_gai[0]);
			TextDrawShowForPlayer(playerid, free_number_gai[1]);
			TextDrawShowForPlayer(playerid, free_number_gai[2]);
			TextDrawShowForPlayer(playerid, free_number_gai[3]);
			TextDrawShowForPlayer(playerid, free_number_gai[4]);

			create_free_number_gai_p(playerid);

			PlayerTextDrawShow(playerid, free_number_gai_p[0][playerid]);
			PlayerTextDrawShow(playerid, free_number_gai_p[1][playerid]);
			PlayerTextDrawShow(playerid, free_number_gai_p[2][playerid]);
			PlayerTextDrawShow(playerid, free_number_gai_p[3][playerid]);
			PlayerTextDrawShow(playerid, free_number_gai_p[4][playerid]);
			PlayerTextDrawShow(playerid, free_number_gai_p[5][playerid]);

			SelectTextDraw(playerid, COLOR_BLUE);

		}
		case TEXTDRAW_HIDE:
		{
			TextDrawHideForPlayer(playerid, free_number_gai[0]);
			TextDrawHideForPlayer(playerid, free_number_gai[1]);
			TextDrawHideForPlayer(playerid, free_number_gai[2]);
			TextDrawHideForPlayer(playerid, free_number_gai[3]);
			TextDrawHideForPlayer(playerid, free_number_gai[4]);

			PlayerTextDrawHideEx(playerid, free_number_gai_p[0][playerid]);
			PlayerTextDrawHideEx(playerid, free_number_gai_p[1][playerid]);
			PlayerTextDrawHideEx(playerid, free_number_gai_p[2][playerid]);
			PlayerTextDrawHideEx(playerid, free_number_gai_p[3][playerid]);
			PlayerTextDrawHideEx(playerid, free_number_gai_p[4][playerid]);
			PlayerTextDrawHideEx(playerid, free_number_gai_p[5][playerid]);
			PlayerTextDrawHideEx(playerid, free_number_gai_p[6][playerid]);

			CancelSelectTextDraw(playerid);
		}
	}
	return true;
}


stock select_number_veh_region_free(playerid, type)
{
	switch(type)
	{
		case NUMBER_REGION_RU:
		{
			PlayerTextDrawSetString(playerid, free_number_gai_p[0][playerid], "brilliantother:number_pl_ru_select");
			PlayerTextDrawShow(playerid, free_number_gai_p[0][playerid]);
			PlayerTextDrawSetString(playerid, free_number_gai_p[1][playerid], "brilliantother:number_pl_kz_no_select");
			PlayerTextDrawShow(playerid, free_number_gai_p[1][playerid]);
			PlayerTextDrawSetString(playerid, free_number_gai_p[2][playerid], "brilliantother:number_pl_by_no_select");
			PlayerTextDrawShow(playerid, free_number_gai_p[2][playerid]);
			PlayerTextDrawSetString(playerid, free_number_gai_p[3][playerid], "brilliantother:number_pl_ua_no_select");
			PlayerTextDrawShow(playerid, free_number_gai_p[3][playerid]);


			SetPVarIntNew(playerid, "select_region_number", NUMBER_REGION_RU);
		}
		case NUMBER_REGION_KZ:
		{
			PlayerTextDrawSetString(playerid, free_number_gai_p[0][playerid], "brilliantother:number_pl_ru_no_select");
			PlayerTextDrawShow(playerid, free_number_gai_p[0][playerid]);
			PlayerTextDrawSetString(playerid, free_number_gai_p[1][playerid], "brilliantother:number_pl_kz_select");
			PlayerTextDrawShow(playerid, free_number_gai_p[1][playerid]);
			PlayerTextDrawSetString(playerid, free_number_gai_p[2][playerid], "brilliantother:number_pl_by_no_select");
			PlayerTextDrawShow(playerid, free_number_gai_p[2][playerid]);
			PlayerTextDrawSetString(playerid, free_number_gai_p[3][playerid], "brilliantother:number_pl_ua_no_select");
			PlayerTextDrawShow(playerid, free_number_gai_p[3][playerid]);


			SetPVarIntNew(playerid, "select_region_number", NUMBER_REGION_KZ);
		}
		case NUMBER_REGION_BY:
		{
			PlayerTextDrawSetString(playerid, free_number_gai_p[0][playerid], "brilliantother:number_pl_ru_no_select");
			PlayerTextDrawShow(playerid, free_number_gai_p[0][playerid]);
			PlayerTextDrawSetString(playerid, free_number_gai_p[1][playerid], "brilliantother:number_pl_kz_no_select");
			PlayerTextDrawShow(playerid, free_number_gai_p[1][playerid]);
			PlayerTextDrawSetString(playerid, free_number_gai_p[2][playerid], "brilliantother:number_pl_by_select");
			PlayerTextDrawShow(playerid, free_number_gai_p[2][playerid]);
			PlayerTextDrawSetString(playerid, free_number_gai_p[3][playerid], "brilliantother:number_pl_ua_no_select");
			PlayerTextDrawShow(playerid, free_number_gai_p[3][playerid]);


			SetPVarIntNew(playerid, "select_region_number", NUMBER_REGION_BY);
		}
		case NUMBER_REGION_UA:
		{
			PlayerTextDrawSetString(playerid, free_number_gai_p[0][playerid], "brilliantother:number_pl_ru_no_select");
			PlayerTextDrawShow(playerid, free_number_gai_p[0][playerid]);
			PlayerTextDrawSetString(playerid, free_number_gai_p[1][playerid], "brilliantother:number_pl_kz_no_select");
			PlayerTextDrawShow(playerid, free_number_gai_p[1][playerid]);
			PlayerTextDrawSetString(playerid, free_number_gai_p[2][playerid], "brilliantother:number_pl_by_no_select");
			PlayerTextDrawShow(playerid, free_number_gai_p[2][playerid]);
			PlayerTextDrawSetString(playerid, free_number_gai_p[3][playerid], "brilliantother:number_pl_ua_select");
			PlayerTextDrawShow(playerid, free_number_gai_p[3][playerid]);


			SetPVarIntNew(playerid, "select_region_number", NUMBER_REGION_UA);
		}
	}


	return true;
}

stock select_number_veh_region_buy(playerid, type)
{
	switch(type)
	{
		case NUMBER_REGION_RU:
		{
			PlayerTextDrawSetString(playerid, buy_number_gai_p[0][playerid], "brilliantother:number_pl_ru_select");
			PlayerTextDrawShow(playerid, buy_number_gai_p[0][playerid]);
			PlayerTextDrawSetString(playerid, buy_number_gai_p[1][playerid], "brilliantother:number_pl_kz_no_select");
			PlayerTextDrawShow(playerid, buy_number_gai_p[1][playerid]);
			PlayerTextDrawSetString(playerid, buy_number_gai_p[2][playerid], "brilliantother:number_pl_by_no_select");
			PlayerTextDrawShow(playerid, buy_number_gai_p[2][playerid]);
			PlayerTextDrawSetString(playerid, buy_number_gai_p[3][playerid], "brilliantother:number_pl_ua_no_select");
			PlayerTextDrawShow(playerid, buy_number_gai_p[3][playerid]);


			SetPVarIntNew(playerid, "select_region_number", NUMBER_REGION_RU);
		}
		case NUMBER_REGION_KZ:
		{
			PlayerTextDrawSetString(playerid, buy_number_gai_p[0][playerid], "brilliantother:number_pl_ru_no_select");
			PlayerTextDrawShow(playerid, buy_number_gai_p[0][playerid]);
			PlayerTextDrawSetString(playerid, buy_number_gai_p[1][playerid], "brilliantother:number_pl_kz_select");
			PlayerTextDrawShow(playerid, buy_number_gai_p[1][playerid]);
			PlayerTextDrawSetString(playerid, buy_number_gai_p[2][playerid], "brilliantother:number_pl_by_no_select");
			PlayerTextDrawShow(playerid, buy_number_gai_p[2][playerid]);
			PlayerTextDrawSetString(playerid, buy_number_gai_p[3][playerid], "brilliantother:number_pl_ua_no_select");
			PlayerTextDrawShow(playerid, buy_number_gai_p[3][playerid]);


			SetPVarIntNew(playerid, "select_region_number", NUMBER_REGION_KZ);
		}
		case NUMBER_REGION_BY:
		{
			PlayerTextDrawSetString(playerid, buy_number_gai_p[0][playerid], "brilliantother:number_pl_ru_no_select");
			PlayerTextDrawShow(playerid, buy_number_gai_p[0][playerid]);
			PlayerTextDrawSetString(playerid, buy_number_gai_p[1][playerid], "brilliantother:number_pl_kz_no_select");
			PlayerTextDrawShow(playerid, buy_number_gai_p[1][playerid]);
			PlayerTextDrawSetString(playerid, buy_number_gai_p[2][playerid], "brilliantother:number_pl_by_select");
			PlayerTextDrawShow(playerid, buy_number_gai_p[2][playerid]);
			PlayerTextDrawSetString(playerid, buy_number_gai_p[3][playerid], "brilliantother:number_pl_ua_no_select");
			PlayerTextDrawShow(playerid, buy_number_gai_p[3][playerid]);


			SetPVarIntNew(playerid, "select_region_number", NUMBER_REGION_BY);
		}
		case NUMBER_REGION_UA:
		{
			PlayerTextDrawSetString(playerid, buy_number_gai_p[0][playerid], "brilliantother:number_pl_ru_no_select");
			PlayerTextDrawShow(playerid, buy_number_gai_p[0][playerid]);
			PlayerTextDrawSetString(playerid, buy_number_gai_p[1][playerid], "brilliantother:number_pl_kz_no_select");
			PlayerTextDrawShow(playerid, buy_number_gai_p[1][playerid]);
			PlayerTextDrawSetString(playerid, buy_number_gai_p[2][playerid], "brilliantother:number_pl_by_no_select");
			PlayerTextDrawShow(playerid, buy_number_gai_p[2][playerid]);
			PlayerTextDrawSetString(playerid, buy_number_gai_p[3][playerid], "brilliantother:number_pl_ua_select");
			PlayerTextDrawShow(playerid, buy_number_gai_p[3][playerid]);


			SetPVarIntNew(playerid, "select_region_number", NUMBER_REGION_UA);
		}
	}


	return true;
}

stock select_region_number_free(playerid)
{

	new 
		i = pData[playerid][car_id];

	if(i == INVALID_VEHICLE_ID) 
		return SendErr(playerid, "Или Вы не имеете транспортное средство или Вы оно находится на парковке!");


	if(!GetPVarIntNew(playerid, "select_region_number"))
		return SendInf(playerid, "Сперва Вам требуется выбрать регион, который Вы хотите получить!");

	new 
		type = GetPVarIntNew(playerid, "select_region_number");

	switch(type)
	{
		case NUMBER_REGION_RU:
		{
			return SPD(playerid, DIALOG_SELECT_REGION_1, DIALOG_STYLE_INPUT, !""cBLUE"Выбор региона России", !"\
			"cWH"Выберите регион на который будет зарегистрирован номерной знак\n\n\
			Пример: А000АА 777 - Один из Московских Регионов ", !"Далее", !"Назад");				


		}
		case NUMBER_REGION_KZ:
		{
			return SPD(playerid, DIALOG_SELECT_REGION_2, DIALOG_STYLE_INPUT, !""cBLUE"Выбор региона Казахстана", !"\
			"cWH"Выберите регион на который будет зарегистрирован номерной знак\n\n\
			Пример: 111NWA 02 - г.Алма-Ата", !"Далее", !"Назад");			


		}
		case NUMBER_REGION_BY:
		{
			return SPD(playerid, DIALOG_SELECT_REGION_3, DIALOG_STYLE_INPUT, !""cBLUE"Выбор региона Беларуси", !"\
			"cWH"Выберите регион на который будет зарегистрирован номерной знак\n\n\
			Пример: 1234AB 07 - г.Минск", !"Далее", !"Назад");		

		}
		case NUMBER_REGION_UA:
		{
			return SPD(playerid, DIALOG_SELECT_REGION_4, DIALOG_STYLE_INPUT, !""cBLUE"Выбор региона Украины", !"\
			"cWH"Выберите регион на который будет зарегистрирован номерной знак\n\n\
			Пример:\n\n\
			1. КА - город Киев\n\
			2. КВ - Винницкая область\n\
			3. КС - Волынская область\n\
			4. КЕ - Днепропетровская область\n\
			5. КН - Донецкая область\n\
			6. КМ - Житомирская область\n\
			7. КО - Закарпатская область\n\
			8. КР - Запорожская область\n\
			9. КТ - Ивано-Франковская область\n\
			10. КI - Киевская область\n\
			11. КК - АР Крым\n\
			12. НА - Кировоградская область\n\
			13. НВ - Луганская область\n\
			14. НС - Львовская область\n\
			15. НЕ - Николаевская область\n\
			16. НН - Одесская область\n\
			17. НI - Полтавская область\n\
			18. НК - Ровенская область\n\
			19. НМ - Сумская область\n\
			20. НО - Тернопольская область\n\
			21. КХ - Харьковская область\n\
			22. НТ - Херсонская область\n\
			23. НХ - Хмельницкая область\n\
			24. IА - Черкасская область\n\
			25. IВ - Черниговская область\n\
			26. IЕ - Черновицкая область\n\
			27. ІН - город Севастополь\n\n\
			Введите номер региона в строку ниже\
			", !"Далее", !"Назад");

		}
	}


	return true;
}

stock generate_veh_number_free(playerid)
{
	if(!GetPVarIntNew(playerid, "select_region_number"))
		return SendInf(playerid, "Сперва Вам требуется выбрать регион, который Вы хотите получить!");

	new 
		i = pData[playerid][car_id];

	if(i == INVALID_VEHICLE_ID) 
		return SendErr(playerid, "Или Вы не имеете транспортное средство или Вы оно находится на парковке!");

	new 
		type = GetPVarIntNew(playerid, "select_region_number");

	new X = random(sizeof(Carnb));
	new Y = random(sizeof(Carnb));
	new I = random(sizeof(Carnb));
	new Z = random(sizeof(Carnb));

	new 
		fmt_str[150];


	switch(type)
	{
		case NUMBER_REGION_RU:
		{

			if(car_number_ru == 0) 
			{
				car_number_ru = 1;
			}
			if(car_number_ru > 99) 
			{
				format(vehicle[i][cPlate], 12, "%c%d%c%c", Carnb[X],car_number_ru,Carnb[Y],Carnb[I]);
			
			 	format(fmt_str,sizeof(fmt_str),"%c%d%c%c_%d", Carnb[X],car_number_ru,Carnb[Y],Carnb[I], vehicle[i][cPlateRegion]);
			 	PlayerTextDrawSetString(playerid, free_number_gai_p[6][playerid], fmt_str);
			 	PlayerTextDrawShow(playerid, free_number_gai_p[6][playerid]);
			}
			else if(car_number_ru > 9 && car_number_ru <= 99) 
			{
				format(vehicle[i][cPlate], 12, "%c0%d%c%c", Carnb[X],car_number_ru,Carnb[Y],Carnb[I]);

			 	format(fmt_str,sizeof(fmt_str),"%c0%d%c%c_%d", Carnb[X],car_number_ru,Carnb[Y],Carnb[I], vehicle[i][cPlateRegion]);
			 	PlayerTextDrawSetString(playerid, free_number_gai_p[6][playerid], fmt_str);
			 	PlayerTextDrawShow(playerid, free_number_gai_p[6][playerid]);

			}
			else if(car_number_ru > 0 && car_number_ru <= 9) 
			{
				format(vehicle[i][cPlate], 12, "%c00%d%c%c", Carnb[X],car_number_ru,Carnb[Y],Carnb[I]);
			
			 	format(fmt_str,sizeof(fmt_str),"%c00%d%c%c_%d", Carnb[X],car_number_ru,Carnb[Y],Carnb[I], vehicle[i][cPlateRegion]);
			 	PlayerTextDrawSetString(playerid, free_number_gai_p[6][playerid], fmt_str);
			 	PlayerTextDrawShow(playerid, free_number_gai_p[6][playerid]);
			}

			car_number_ru ++;
			if(car_number_ru > 999) 
			{ 
				car_number_ru = 1; 
			}

			PlayerTextDrawSetString(playerid, free_number_gai_p[5][playerid], "brilliantother:number_pl_buy_background");
			PlayerTextDrawShow(playerid, free_number_gai_p[5][playerid]);

			format(vehicle[i][cPlate], 12, vehicle[i][cPlate]);
			format(vehicle[i][cPlateRegion], 12, vehicle[i][cPlateRegion]);
		 	SetVehicleRuNumberPlate(i, vehicle[i][cPlate], vehicle[i][cPlateRegion]);

		 	SendSucc(playerid, "Вы успешно зарегистрировали номерные знаки на Ваше транспортное средство!");
		 	SendInf(playerid, "Номерные знаки уже установлены на Ваш автомобиль!");

		 	pData[playerid][pCarNumberStatus] = 1;
		 	UpdatePlayerData(playerid, "pCarNumberStatus", pData[playerid][pCarNumberStatus]);

		 	vehicle[i][cPlateType] = NUMBER_REGION_RU;

		 	SelectTextDraw(playerid, COLOR_BLUE);

		}
		case NUMBER_REGION_KZ:
		{
			if(car_number_kz == 0) 
			{
				car_number_kz = 1;
			}
			if(car_number_kz > 99) 
			{
				format(vehicle[i][cPlate], 12, "%d%c%c%c", car_number_kz, Carnb[X], Carnb[Y], Carnb[I]);

			 	format(fmt_str,sizeof(fmt_str),"%d%c%c%c_%d", car_number_kz, Carnb[X], Carnb[Y], Carnb[I], vehicle[i][cPlateRegion]);
			 	PlayerTextDrawSetString(playerid, free_number_gai_p[6][playerid], fmt_str);
			 	PlayerTextDrawShow(playerid, free_number_gai_p[6][playerid]);

			}
			else if(car_number_kz > 9 && car_number_kz <= 99) 
			{
				format(vehicle[i][cPlate], 12, "0%d%c%c%c", car_number_kz, Carnb[X], Carnb[Y], Carnb[I]);

			 	format(fmt_str,sizeof(fmt_str),"0%d%c%c%c_%d", car_number_kz, Carnb[X], Carnb[Y], Carnb[I], vehicle[i][cPlateRegion]);
			 	PlayerTextDrawSetString(playerid, free_number_gai_p[6][playerid], fmt_str);
			 	PlayerTextDrawShow(playerid, free_number_gai_p[6][playerid]);

			}
			else if(car_number_kz > 0 && car_number_kz <= 9) 
			{
				format(vehicle[i][cPlate], 12, "00%d%c%c%c", car_number_kz, Carnb[X], Carnb[Y], Carnb[I]);

			 	format(fmt_str,sizeof(fmt_str),"00%d%c%c%c_%d", car_number_kz, Carnb[X], Carnb[Y], Carnb[I], vehicle[i][cPlateRegion]);
			 	PlayerTextDrawSetString(playerid, free_number_gai_p[6][playerid], fmt_str);
			 	PlayerTextDrawShow(playerid, free_number_gai_p[6][playerid]);


			}

			car_number_kz ++;
			if(car_number_kz > 999) 
			{ 
				car_number_kz = 1; 
			}

			PlayerTextDrawSetString(playerid, free_number_gai_p[5][playerid], "brilliantother:number_pl_buy_background");
			PlayerTextDrawShow(playerid, free_number_gai_p[5][playerid]);

		 	SendSucc(playerid, "Вы успешно зарегистрировали номерные знаки на Ваше транспортное средство!");
		 	SendInf(playerid, "Номерные знаки уже установлены на Ваш автомобиль!");

		 	format(vehicle[i][cPlate], 12, vehicle[i][cPlate]);
		 	format(vehicle[i][cPlateRegion], 12, vehicle[i][cPlateRegion]);
		 	SetVehicleKzNumberPlate(i, vehicle[i][cPlate], vehicle[i][cPlateRegion]);

		 	pData[playerid][pCarNumberStatus] = 1;
		 	UpdatePlayerData(playerid, "pCarNumberStatus", pData[playerid][pCarNumberStatus]);

		 	vehicle[i][cPlateType] = NUMBER_REGION_KZ;

		 	SelectTextDraw(playerid, COLOR_BLUE);

		}
		case NUMBER_REGION_BY:
		{

			if(car_number_by == 0) 
			{
				car_number_by = 1;
			}
			if(car_number_by > 999) 
			{
				format(vehicle[i][cPlate], 12, "%d%c%c-%d", car_number_by, Carnb[X], Carnb[Y], vehicle[i][cPlateRegion]);

			 	format(fmt_str,sizeof(fmt_str),"%d%c%c-%d", car_number_by, Carnb[X], Carnb[Y], vehicle[i][cPlateRegion]);
			 	PlayerTextDrawSetString(playerid, free_number_gai_p[6][playerid], fmt_str);
			 	PlayerTextDrawShow(playerid, free_number_gai_p[6][playerid]);

			}
			else if(car_number_by > 99 && car_number_by <= 999) 
			{
				format(vehicle[i][cPlate], 12, "0%d%c%c-%d", car_number_by, Carnb[X], Carnb[Y], vehicle[i][cPlateRegion]);

			 	format(fmt_str,sizeof(fmt_str),"0%d%c%c-%d", car_number_by, Carnb[X], Carnb[Y], vehicle[i][cPlateRegion]);
			 	PlayerTextDrawSetString(playerid, free_number_gai_p[6][playerid], fmt_str);
			 	PlayerTextDrawShow(playerid, free_number_gai_p[6][playerid]);

			}			
			else if(car_number_by > 9 && car_number_by <= 99) 
			{
				format(vehicle[i][cPlate], 12, "00%d%c%c-%d", car_number_by, Carnb[X], Carnb[Y], vehicle[i][cPlateRegion]);

			 	format(fmt_str,sizeof(fmt_str),"00%d%c%c-%d", car_number_by, Carnb[X], Carnb[Y], vehicle[i][cPlateRegion]);
			 	PlayerTextDrawSetString(playerid, free_number_gai_p[6][playerid], fmt_str);
			 	PlayerTextDrawShow(playerid, free_number_gai_p[6][playerid]);

			}
			else if(car_number_by > 0 && car_number_by <= 9) 
			{
				format(vehicle[i][cPlate], 12, "000%d%c%c-%d", car_number_by, Carnb[X], Carnb[Y], vehicle[i][cPlateRegion]);

			 	format(fmt_str,sizeof(fmt_str),"000%d%c%c-%d", car_number_by, Carnb[X], Carnb[Y], vehicle[i][cPlateRegion]);
			 	PlayerTextDrawSetString(playerid, free_number_gai_p[6][playerid], fmt_str);
			 	PlayerTextDrawShow(playerid, free_number_gai_p[6][playerid]);


			}

			car_number_by ++;
			if(car_number_by > 9999) 
			{ 
				car_number_by = 1; 
			}
			PlayerTextDrawSetString(playerid, free_number_gai_p[5][playerid], "brilliantother:number_pl_buy_background");
			PlayerTextDrawShow(playerid, free_number_gai_p[5][playerid]);

		 	SendSucc(playerid, "Вы успешно зарегистрировали номерные знаки на Ваше транспортное средство!");
		 	SendInf(playerid, "Номерные знаки уже установлены на Ваш автомобиль!");

		 	format(vehicle[i][cPlate], 12, vehicle[i][cPlate]);
		 	SetVehicleBuNumberPlate(i, vehicle[i][cPlate]);

		 	pData[playerid][pCarNumberStatus] = 1;
		 	UpdatePlayerData(playerid, "pCarNumberStatus", pData[playerid][pCarNumberStatus]);

		 	vehicle[i][cPlateType] = NUMBER_REGION_BY;

		 	SelectTextDraw(playerid, COLOR_BLUE);

		}
		case NUMBER_REGION_UA:
		{
			if(car_number_ua == 0) 
			{
				car_number_ua = 1;
			}
			if(car_number_ua > 999) 
			{
				format(vehicle[i][cPlate], 12, "%s%d%c%c", get_ua_region_number(vehicle[i][cPlateRegion]),car_number_ua, Carnb[I], Carnb[Z]);

			 	format(fmt_str,sizeof(fmt_str),"%s%d%c%c", get_ua_region_number(vehicle[i][cPlateRegion]), car_number_ua, Carnb[I], Carnb[Z]);
			 	PlayerTextDrawSetString(playerid, free_number_gai_p[6][playerid], fmt_str);
			 	PlayerTextDrawShow(playerid, free_number_gai_p[6][playerid]);

			}
			else if(car_number_ua > 99 && car_number_ua <= 999) 
			{
				format(vehicle[i][cPlate], 12, "%s0%d%c%c", get_ua_region_number(vehicle[i][cPlateRegion]),car_number_ua, Carnb[I], Carnb[Z]);

			 	format(fmt_str,sizeof(fmt_str),"%s0%d%c%c", get_ua_region_number(vehicle[i][cPlateRegion]), car_number_ua, Carnb[I], Carnb[Z]);
			 	PlayerTextDrawSetString(playerid, free_number_gai_p[6][playerid], fmt_str);
			 	PlayerTextDrawShow(playerid, free_number_gai_p[6][playerid]);


			}			
			else if(car_number_ua > 9 && car_number_ua <= 99) 
			{
				format(vehicle[i][cPlate], 12, "%s00%d%c%c", get_ua_region_number(vehicle[i][cPlateRegion]),car_number_ua, Carnb[I], Carnb[Z]);

			 	format(fmt_str,sizeof(fmt_str),"%s00%d%c%c", get_ua_region_number(vehicle[i][cPlateRegion]), car_number_ua, Carnb[I], Carnb[Z]);
			 	PlayerTextDrawSetString(playerid, free_number_gai_p[6][playerid], fmt_str);
			 	PlayerTextDrawShow(playerid, free_number_gai_p[6][playerid]);

			}
			else if(car_number_ua > 0 && car_number_ua <= 9) 
			{
				format(vehicle[i][cPlate], 12, "%s000%d%c%c", get_ua_region_number(vehicle[i][cPlateRegion]), car_number_ua, Carnb[I], Carnb[Z]);


			 	format(fmt_str,sizeof(fmt_str),"%s000%d%c%c", get_ua_region_number(vehicle[i][cPlateRegion]), car_number_ua, Carnb[I], Carnb[Z]);
			 	PlayerTextDrawSetString(playerid, free_number_gai_p[6][playerid], fmt_str);
			 	PlayerTextDrawShow(playerid, free_number_gai_p[6][playerid]);

			}

			car_number_ua ++;
			if(car_number_ua > 9999) 
			{ 
				car_number_ua = 1; 
			}

			PlayerTextDrawSetString(playerid, free_number_gai_p[5][playerid], "brilliantother:number_pl_buy_background");
			PlayerTextDrawShow(playerid, free_number_gai_p[5][playerid]);

		 	SendSucc(playerid, "Вы успешно зарегистрировали номерные знаки на Ваше транспортное средство!");
		 	SendInf(playerid, "Номерные знаки уже установлены на Ваш автомобиль!");


		 	pData[playerid][pCarNumberStatus] = 1;
		 	UpdatePlayerData(playerid, "pCarNumberStatus", pData[playerid][pCarNumberStatus]);

		 	format(vehicle[i][cPlate], 12, vehicle[i][cPlate]);
		 	SetVehicleUaNumberPlate(i, vehicle[i][cPlate]);


		 	vehicle[i][cPlateType] = NUMBER_REGION_UA;

		 	SelectTextDraw(playerid, COLOR_BLUE);
		}
	}

	return true;
}


stock get_ua_region_number(region)
{
	new 
		name[30];

	switch(region)
	{
		case 1: name = "КА";
		case 2: name = "КВ";
		case 3: name = "КС";
		case 4: name = "КЕ";
		case 5: name = "КН";
		case 6: name = "КМ";
		case 7: name = "КО";
		case 8: name = "КР";
		case 9: name = "КТ";
		case 10: name = "КI";
		case 11: name = "КК";
		case 12: name = "НА";
		case 13: name = "НВ";
		case 14: name = "НС";
		case 15: name = "НЕ";
		case 16: name = "НН";
		case 17: name = "НI";
		case 18: name = "НК";
		case 19: name = "НМ";
		case 20: name = "НО";
		case 21: name = "КХ";
		case 22: name = "НТ";
		case 23: name = "НХ";
		case 24: name = "IА";
		case 25: name = "IВ";
		case 26: name = "IЕ";
		case 27: name = "ІН";

	}
	return name;	
}

stock dialog_all_police(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
	    case DIALOG_SELECT_CAR_POLICE: 
	    {
	    	if(!response)
	    		return true;
	    	
	    	switch(listitem)
	    	{
		    	case 0: return spawn_police_veh_start(playerid, 0);
		    	case 1: return spawn_police_veh_start(playerid, 1);
		    	case 2: return spawn_police_veh_start(playerid, 2);
		    	case 3: return spawn_police_veh_start(playerid, 3);
		    	case 4: return spawn_police_vehicle(playerid);
		    	case 5: return spawn_police_vehicle(playerid);
		    }
	    }
		case DIALOG_SELECT_REGION_1:
		{

	    	if(!response)
	    		return SelectTextDraw(playerid, COLOR_BLUE);

			new 
				i = pData[playerid][car_id];

			if(i == INVALID_VEHICLE_ID) 
				return SendErr(playerid, "Или Вы не имеете транспортное средство или Вы оно находится на парковке!");


			if(!IsNumeric(inputtext)) 
			{
				select_region_number_free(playerid);
				return SendErr(playerid,"Вы указали неверное значение номерного знака для Российской Федерации!");
			}

			if(check_no_valid_symbol_text(inputtext) || check_sql_injection_text(inputtext))
			{
				select_region_number_free(playerid);
				return SendErr(playerid,"Вы указали неверное значение номерного знака для Российской Федерации!");
			}

			new 
				count_max_symbol = strval(inputtext);	

			if(count_max_symbol < 1 || count_max_symbol > 1000)
			{
				select_region_number_free(playerid);
				SendErr(playerid,"Вы указали неверное значение номерного знака для Российской Федерации!");			
				return SendErr(playerid, "От 1 до 1000 регион!");	
			}			

			vehicle[i][cPlateRegion] = strval(inputtext);
			SendSucc(playerid, "Регион для номерного знака успешно выбран! Теперь осталось сгенерировать номерной знак!");
			generate_veh_number_free(playerid);

		}
		case DIALOG_SELECT_REGION_2:
		{
	    	if(!response)
	    		return SelectTextDraw(playerid, COLOR_BLUE);

			new 
				i = pData[playerid][car_id];

			if(i == INVALID_VEHICLE_ID) 
				return SendErr(playerid, "Или Вы не имеете транспортное средство или Вы оно находится на парковке!");


			if(!IsNumeric(inputtext)) 
			{
				select_region_number_free(playerid);
				return SendErr(playerid,"Вы указали неверное значение номерного знака для Казахстана!");
			}	

			if(check_no_valid_symbol_text(inputtext) || check_sql_injection_text(inputtext))
			{
				select_region_number_free(playerid);
				return SendErr(playerid,"Вы указали неверное значение номерного знака для Казахстана!");
			}

			new 
				count_max_symbol = strval(inputtext);	

			if(count_max_symbol < 1 || count_max_symbol > 16)
			{
				select_region_number_free(playerid);
				SendErr(playerid,"Вы указали неверное значение номерного знака для Казахстана!");			
				return SendErr(playerid, "От 1 до 16 регион!");	
			}			


			vehicle[i][cPlateRegion] = strval(inputtext);
			SendSucc(playerid, "Регион для номерного знака успешно выбран! Теперь осталось сгенерировать номерной знак!");
			generate_veh_number_free(playerid);

		}
		case DIALOG_SELECT_REGION_3:
		{
	    	if(!response)
	    		return SelectTextDraw(playerid, COLOR_BLUE);

			new 
				i = pData[playerid][car_id];

			if(i == INVALID_VEHICLE_ID) 
				return SendErr(playerid, "Или Вы не имеете транспортное средство или Вы оно находится на парковке!");


			if(!IsNumeric(inputtext)) 
			{
				select_region_number_free(playerid);
				return SendErr(playerid,"Вы указали неверное значение номерного знака для Республики Беларусь!");
			}	

			if(check_no_valid_symbol_text(inputtext) || check_sql_injection_text(inputtext))
			{
				select_region_number_free(playerid);
				return SendErr(playerid,"Вы указали неверное значение номерного знака для Республики Беларусь!");
			}


			new 
				count_max_symbol = strval(inputtext);	

			if(count_max_symbol < 1 || count_max_symbol > 16)
			{
				select_region_number_free(playerid);
				SendErr(playerid,"Вы указали неверное значение номерного знака для Республики Беларусь!");			
				return SendErr(playerid, "От 1 до 7 регион!");	
			}			


			vehicle[i][cPlateRegion] = strval(inputtext);
			SendSucc(playerid, "Регион для номерного знака успешно выбран! Теперь осталось сгенерировать номерной знак!");
			generate_veh_number_free(playerid);

		}
		case DIALOG_SELECT_REGION_4:
		{
	    	if(!response)
	    		return SelectTextDraw(playerid, COLOR_BLUE);

			new 
				i = pData[playerid][car_id];

			if(i == INVALID_VEHICLE_ID) 
				return SendErr(playerid, "Или Вы не имеете транспортное средство или Вы оно находится на парковке!");


			if(!IsNumeric(inputtext)) 
			{
				select_region_number_free(playerid);
				return SendErr(playerid,"Вы указали неверное значение номерного знака для Украины!");
			}	

			if(check_no_valid_symbol_text(inputtext) || check_sql_injection_text(inputtext))
			{
				select_region_number_free(playerid);
				return SendErr(playerid,"Вы указали неверное значение номерного знака для Украины!");
			}

		    for(new i = strlen(inputtext); i != 0; --i)
		    {
		        switch(inputtext[i])
		        {
		            case 'А'..'Я', 'а'..'я', ' ':
		            {
						select_region_number_free(playerid);
						SendErr(playerid,"Вы указали неверное значение номерного знака для Украины!");
						return SendInf(playerid, "Используйте английскую раскладку клавиатуры!");
		            }
		        }
		    }


			new 
				count_max_symbol = strval(inputtext);	

			if(count_max_symbol < 1 || count_max_symbol > 27)
			{
				select_region_number_free(playerid);
				SendErr(playerid,"Вы указали неверное значение номерного знака для Украины!");			
				return SendErr(playerid, "От 1 до 27 регион!");	
			}			

			format(vehicle[i][cPlateRegion], 12, inputtext);

			SendSucc(playerid, "Регион для номерного знака успешно выбран! Теперь осталось сгенерировать номерной знак!");
			generate_veh_number_free(playerid);

		}


		case DIALOG_SELECT_REGION_1_BUY:
		{

	    	if(!response)
	    		return SelectTextDraw(playerid, COLOR_BLUE);

			new 
				i = pData[playerid][car_id];

			if(i == INVALID_VEHICLE_ID) 
				return SendErr(playerid, "Или Вы не имеете транспортное средство или Вы оно находится на парковке!");


			if(!IsNumeric(inputtext)) 
			{
				select_region_number_free(playerid);
				return SendErr(playerid,"Вы указали неверное значение номерного знака для Российской Федерации!");
			}

			if(check_no_valid_symbol_text(inputtext) || check_sql_injection_text(inputtext))
			{
				select_region_number_free(playerid);
				return SendErr(playerid,"Вы указали неверное значение номерного знака для Российской Федерации!");
			}

			new 
				count_max_symbol = strval(inputtext);	

			if(count_max_symbol < 1 || count_max_symbol > 85)
			{
				select_region_number_free(playerid);
				SendErr(playerid,"Вы указали неверное значение номерного знака для Российской Федерации!");			
				return SendErr(playerid, "От 1 до 85 регион!");	
			}			

			format(vehicle[i][cPlateRegion], 12, inputtext);

			SendSucc(playerid, "Регион для номерного знака успешно выбран! Теперь осталось сгенерировать номерной знак!");
			generate_veh_number_free(playerid);

		}
		case DIALOG_SELECT_REGION_2_BUY:
		{
	    	if(!response)
	    		return SelectTextDraw(playerid, COLOR_BLUE);

			new 
				i = pData[playerid][car_id];

			if(i == INVALID_VEHICLE_ID) 
				return SendErr(playerid, "Или Вы не имеете транспортное средство или Вы оно находится на парковке!");


			if(!IsNumeric(inputtext)) 
			{
				select_region_number_free(playerid);
				return SendErr(playerid,"Вы указали неверное значение номерного знака для Казахстана!");
			}	

			if(check_no_valid_symbol_text(inputtext) || check_sql_injection_text(inputtext))
			{
				select_region_number_free(playerid);
				return SendErr(playerid,"Вы указали неверное значение номерного знака для Казахстана!");
			}

			new 
				count_max_symbol = strval(inputtext);	

			if(count_max_symbol < 1 || count_max_symbol > 16)
			{
				select_region_number_free(playerid);
				SendErr(playerid,"Вы указали неверное значение номерного знака для Казахстана!");			
				return SendErr(playerid, "От 1 до 16 регион!");	
			}			

			format(vehicle[i][cPlateRegion], 12, inputtext);

			SendSucc(playerid, "Регион для номерного знака успешно выбран! Теперь осталось сгенерировать номерной знак!");
			generate_veh_number_free(playerid);

		}
		case DIALOG_SELECT_REGION_3_BUY:
		{
	    	if(!response)
	    		return SelectTextDraw(playerid, COLOR_BLUE);

			new 
				i = pData[playerid][car_id];

			if(i == INVALID_VEHICLE_ID) 
				return SendErr(playerid, "Или Вы не имеете транспортное средство или Вы оно находится на парковке!");


			if(!IsNumeric(inputtext)) 
			{
				select_region_number_free(playerid);
				return SendErr(playerid,"Вы указали неверное значение номерного знака для Республики Беларусь!");
			}	

			if(check_no_valid_symbol_text(inputtext) || check_sql_injection_text(inputtext))
			{
				select_region_number_free(playerid);
				return SendErr(playerid,"Вы указали неверное значение номерного знака для Республики Беларусь!");
			}


			new 
				count_max_symbol = strval(inputtext);	

			if(count_max_symbol < 1 || count_max_symbol > 16)
			{
				select_region_number_free(playerid);
				SendErr(playerid,"Вы указали неверное значение номерного знака для Республики Беларусь!");			
				return SendErr(playerid, "От 1 до 7 регион!");	
			}			


			format(vehicle[i][cPlateRegion], 12, inputtext);
			SendSucc(playerid, "Регион для номерного знака успешно выбран! Теперь осталось сгенерировать номерной знак!");
			generate_veh_number_free(playerid);

		}
		case DIALOG_SELECT_REGION_4_BUY:
		{
	    	if(!response)
	    		return SelectTextDraw(playerid, COLOR_BLUE);

			new 
				i = pData[playerid][car_id];

			if(i == INVALID_VEHICLE_ID) 
				return SendErr(playerid, "Или Вы не имеете транспортное средство или Вы оно находится на парковке!");


			if(!IsNumeric(inputtext)) 
			{
				select_region_number_free(playerid);
				return SendErr(playerid,"Вы указали неверное значение номерного знака для Украины!");
			}	

			if(check_no_valid_symbol_text(inputtext) || check_sql_injection_text(inputtext))
			{
				select_region_number_free(playerid);
				return SendErr(playerid,"Вы указали неверное значение номерного знака для Украины!");
			}

			new 
				count_max_symbol = strval(inputtext);	

			if(count_max_symbol < 1 || count_max_symbol > 27)
			{
				select_region_number_free(playerid);
				SendErr(playerid,"Вы указали неверное значение номерного знака для Украины!");			
				return SendErr(playerid, "От 1 до 27 регион!");	
			}			


			format(vehicle[i][cPlateRegion], 12, inputtext);
			SendSucc(playerid, "Регион для номерного знака успешно выбран! Теперь осталось сгенерировать номерной знак!");
			generate_veh_number_free(playerid);

		}

	}
	return true;
}


stock get_plate_price_ru(playerid)
{
	new stoim = 0;
	if(PlayerPlateNumber[playerid][0] == PlayerPlateNumber[playerid][4] && PlayerPlateNumber[playerid][0] == PlayerPlateNumber[playerid][5])
	{
		stoim += 450000;
	}
	else if(PlayerPlateNumber[playerid][0] == PlayerPlateNumber[playerid][4] || PlayerPlateNumber[playerid][4] == PlayerPlateNumber[playerid][5] || PlayerPlateNumber[playerid][0] == PlayerPlateNumber[playerid][5])
	{
		stoim += 150000;
	}
	else if(PlayerPlateNumber[playerid][0] == 0 && PlayerPlateNumber[playerid][5] == 5 && PlayerPlateNumber[playerid][4] == 6)
	{
		stoim += 350000;
		//АМР
	}
	else if(PlayerPlateNumber[playerid][0] == 3 && PlayerPlateNumber[playerid][5] == 10 && PlayerPlateNumber[playerid][4] == 9)
	{
		stoim += 350000;
		//ЕКХ
	}
	else if(PlayerPlateNumber[playerid][0] == 1 && PlayerPlateNumber[playerid][5] == 8 && PlayerPlateNumber[playerid][4] == 6)
	{
		stoim += 350000;
		//ВОР
	}
	else if(PlayerPlateNumber[playerid][0] == 9 && PlayerPlateNumber[playerid][5] == 0 && PlayerPlateNumber[playerid][4] == 5)
	{
		stoim += 350000;
		//ХАМ
	}

	if(PlayerPlateNumber[playerid][1] == PlayerPlateNumber[playerid][2] && PlayerPlateNumber[playerid][1] == PlayerPlateNumber[playerid][3])
	{
	// 3 один. цифры
	    if(stoim == 450000) stoim += 1050000;
	    else if(stoim == 350000) stoim += 1000000;
	    else if(stoim == 150000) stoim += 650000;
	    else stoim += 400000;
	}
	else if(PlayerPlateNumber[playerid][1] == 0 && PlayerPlateNumber[playerid][2] == 0 && PlayerPlateNumber[playerid][3] != 0  )
	{
	    if(stoim == 450000) stoim += 700000;
	    else if(stoim == 350000) stoim += 500000;
	    else if(stoim == 150000) stoim += 300000;
	    else stoim += 250000;
	}
	else if(PlayerPlateNumber[playerid][2] == 0 && PlayerPlateNumber[playerid][3] == 0  && PlayerPlateNumber[playerid][1] != 0 )
	{
	    if(stoim == 450000) stoim += 450000;
	    else if(stoim == 350000) stoim += 350000;
	    else if(stoim == 150000) stoim += 300000;
	    else stoim += 140000;
	}
	else if(PlayerPlateNumber[playerid][1] == PlayerPlateNumber[playerid][2] || PlayerPlateNumber[playerid][1] == PlayerPlateNumber[playerid][3]  || PlayerPlateNumber[playerid][2] == PlayerPlateNumber[playerid][3])
	{
	    // 2 цифры остальные
	    if(stoim == 450000) stoim += 600000;
	    else if(stoim == 350000) stoim += 600000;
	    else if(stoim == 150000) stoim += 250000;
	    else stoim += 120000;
	}
	else if(PlayerPlateNumber[playerid][1] == PlayerPlateNumber[playerid][2]+1 && PlayerPlateNumber[playerid][2] == PlayerPlateNumber[playerid][3]+1)
	{
	//123
	    if(stoim == 450000) stoim += 600000;
	    else if(stoim == 350000) stoim += 600000;
	    else if(stoim == 150000) stoim += 350000;
	    else stoim += 140000;
	}
	else if( PlayerPlateNumber[playerid][1]+1 == PlayerPlateNumber[playerid][2] && PlayerPlateNumber[playerid][2]+1 == PlayerPlateNumber[playerid][3])
	{
	//321
	    if(stoim == 450000) stoim += 500000;
	    else if(stoim == 350000) stoim += 400000;
	    else if(stoim == 150000) stoim += 350000;
	    else stoim += 100000;
	}

	
	if(PlayerPlateNumber[playerid][2] == 0 && PlayerPlateNumber[playerid][3] == 0  && PlayerPlateNumber[playerid][1] == 0)
	{
		stoim = 0;
	}

	return stoim;
}



stock get_plate_price_kz(playerid)
{
	new stoim = 0;


	if(PlayerPlateNumber[playerid][0] == PlayerPlateNumber[playerid][1] && PlayerPlateNumber[playerid][0] == PlayerPlateNumber[playerid][2])
	{
		stoim += 450000;
	}
	else if(PlayerPlateNumber[playerid][0] == PlayerPlateNumber[playerid][1] && PlayerPlateNumber[playerid][0] != PlayerPlateNumber[playerid][2])
	{
		stoim += 250000;
	}
	else if(PlayerPlateNumber[playerid][0] == PlayerPlateNumber[playerid][1] && PlayerPlateNumber[playerid][0] != PlayerPlateNumber[playerid][2] && PlayerPlateNumber[playerid][1] != PlayerPlateNumber[playerid][2])
	{
		stoim += 150000;
	}

	else if(PlayerPlateNumber[playerid][3] == 0 && PlayerPlateNumber[playerid][4] == 5 && PlayerPlateNumber[playerid][5] == 6)
	{
		stoim += 350000;
	}


	else if(PlayerPlateNumber[playerid][3] == 0 && PlayerPlateNumber[playerid][4] == 5 && PlayerPlateNumber[playerid][5] == 6)
	{
		stoim += 350000;
		//АМР
	}
	else if(PlayerPlateNumber[playerid][3] == 3 && PlayerPlateNumber[playerid][4] == 10 && PlayerPlateNumber[playerid][5] == 9)
	{
		stoim += 350000;
		//ЕКХ
	}
	else if(PlayerPlateNumber[playerid][3] == 1 && PlayerPlateNumber[playerid][4] == 8 && PlayerPlateNumber[playerid][5] == 6)
	{
		stoim += 350000;
		//ВОР
	}
	else if(PlayerPlateNumber[playerid][3] == 9 && PlayerPlateNumber[playerid][4] == 0 && PlayerPlateNumber[playerid][5] == 5)
	{
		stoim += 350000;
		//ХАМ
	}

	if(PlayerPlateNumber[playerid][0] == PlayerPlateNumber[playerid][1] && PlayerPlateNumber[playerid][0] == PlayerPlateNumber[playerid][3])
	{
	// 3 один. цифры
	    if(stoim == 450000) stoim += 1050000;
	    else if(stoim == 350000) stoim += 1000000;
	    else if(stoim == 150000) stoim += 650000;
	    else stoim += 400000;
	}
	else if(PlayerPlateNumber[playerid][0] == 0 && PlayerPlateNumber[playerid][1] == 0 && PlayerPlateNumber[playerid][2] != 0  )
	{
	    if(stoim == 450000) stoim += 700000;
	    else if(stoim == 350000) stoim += 500000;
	    else if(stoim == 150000) stoim += 300000;
	    else stoim += 250000;
	}
	else if(PlayerPlateNumber[playerid][1] == 0 && PlayerPlateNumber[playerid][2] == 0  && PlayerPlateNumber[playerid][0] != 0 )
	{
	    if(stoim == 450000) stoim += 450000;
	    else if(stoim == 350000) stoim += 350000;
	    else if(stoim == 150000) stoim += 300000;
	    else stoim += 140000;
	}
	else if(PlayerPlateNumber[playerid][0] == PlayerPlateNumber[playerid][1] || PlayerPlateNumber[playerid][0] == PlayerPlateNumber[playerid][2]  || PlayerPlateNumber[playerid][1] == PlayerPlateNumber[playerid][2])
	{
	    // 2 цифры остальные
	    if(stoim == 450000) stoim += 600000;
	    else if(stoim == 350000) stoim += 600000;
	    else if(stoim == 150000) stoim += 250000;
	    else stoim += 120000;
	}
	else if(PlayerPlateNumber[playerid][0] == PlayerPlateNumber[playerid][1]+1 && PlayerPlateNumber[playerid][1] == PlayerPlateNumber[playerid][2]+1)
	{
	//123
	    if(stoim == 450000) stoim += 600000;
	    else if(stoim == 350000) stoim += 600000;
	    else if(stoim == 150000) stoim += 350000;
	    else stoim += 140000;
	}
	else if( PlayerPlateNumber[playerid][0]+1 == PlayerPlateNumber[playerid][1] && PlayerPlateNumber[playerid][1]+1 == PlayerPlateNumber[playerid][2])
	{
	//321
	    if(stoim == 450000) stoim += 500000;
	    else if(stoim == 350000) stoim += 400000;
	    else if(stoim == 150000) stoim += 350000;
	    else stoim += 100000;
	}

	
	if(PlayerPlateNumber[playerid][2] == 0 && PlayerPlateNumber[playerid][3] == 0  && PlayerPlateNumber[playerid][0] == 0)
	{
		stoim = 0;
	}

	return stoim;
}


stock get_plate_price_by(playerid)
{
	new stoim = 0;

	if(PlayerPlateNumber[playerid][4] == 0 && PlayerPlateNumber[playerid][5] == 0
	|| PlayerPlateNumber[playerid][4] == 1 && PlayerPlateNumber[playerid][5] == 1
	|| PlayerPlateNumber[playerid][4] == 2 && PlayerPlateNumber[playerid][5] == 2
	|| PlayerPlateNumber[playerid][4] == 3 && PlayerPlateNumber[playerid][5] == 3
	|| PlayerPlateNumber[playerid][4] == 4 && PlayerPlateNumber[playerid][5] == 4
	|| PlayerPlateNumber[playerid][4] == 5 && PlayerPlateNumber[playerid][5] == 5
	|| PlayerPlateNumber[playerid][4] == 6 && PlayerPlateNumber[playerid][5] == 6
	|| PlayerPlateNumber[playerid][4] == 7 && PlayerPlateNumber[playerid][5] == 7
	|| PlayerPlateNumber[playerid][4] == 8 && PlayerPlateNumber[playerid][5] == 8
	|| PlayerPlateNumber[playerid][4] == 9 && PlayerPlateNumber[playerid][5] == 9
	|| PlayerPlateNumber[playerid][4] == 10 && PlayerPlateNumber[playerid][5] == 10)
	{
		stoim += 450000;
	}

	if(PlayerPlateNumber[playerid][0] == PlayerPlateNumber[playerid][1] && PlayerPlateNumber[playerid][0] == PlayerPlateNumber[playerid][2] && PlayerPlateNumber[playerid][0] == PlayerPlateNumber[playerid][3])
	{
		// 3 один. цифры
	    if(stoim == 450000) stoim += 1050000;
	    else if(stoim == 350000) stoim += 1000000;
	    else if(stoim == 150000) stoim += 650000;
	    else stoim += 400000;
	}
	else if(PlayerPlateNumber[playerid][0] == PlayerPlateNumber[playerid][1] && PlayerPlateNumber[playerid][0] == PlayerPlateNumber[playerid][2] && PlayerPlateNumber[playerid][0] == PlayerPlateNumber[playerid][3] 
	&& PlayerPlateNumber[playerid][0] == PlayerPlateNumber[playerid][4])
	{
		// 4 один. цифры
	    if(stoim == 450000) stoim += 1250000;
	    else if(stoim == 350000) stoim += 1200000;
	    else if(stoim == 150000) stoim += 750000;
	    else stoim += 600000;
	}	

	else if(PlayerPlateNumber[playerid][0] == PlayerPlateNumber[playerid][1] && PlayerPlateNumber[playerid][0] == PlayerPlateNumber[playerid][2] && PlayerPlateNumber[playerid][0] != PlayerPlateNumber[playerid][3] 
	&& PlayerPlateNumber[playerid][0] !== PlayerPlateNumber[playerid][4])
	{
		// 2 один. цифры
	    if(stoim == 450000) stoim += 550000;
	    else if(stoim == 350000) stoim += 700000;
	    else if(stoim == 150000) stoim += 650000;
	    else stoim += 400000;
	}	

	
	if(PlayerPlateNumber[playerid][2] == 0 && PlayerPlateNumber[playerid][3] == 0  && PlayerPlateNumber[playerid][1] == 0)
	{
		stoim = 0;
	}

	return stoim;
}

stock get_plate_price_ua(playerid)
{
	new stoim = 0;

	if(PlayerPlateNumber[playerid][4] == 0 && PlayerPlateNumber[playerid][5] == 0
	|| PlayerPlateNumber[playerid][4] == 1 && PlayerPlateNumber[playerid][5] == 1
	|| PlayerPlateNumber[playerid][4] == 2 && PlayerPlateNumber[playerid][5] == 2
	|| PlayerPlateNumber[playerid][4] == 3 && PlayerPlateNumber[playerid][5] == 3
	|| PlayerPlateNumber[playerid][4] == 4 && PlayerPlateNumber[playerid][5] == 4
	|| PlayerPlateNumber[playerid][4] == 5 && PlayerPlateNumber[playerid][5] == 5
	|| PlayerPlateNumber[playerid][4] == 6 && PlayerPlateNumber[playerid][5] == 6
	|| PlayerPlateNumber[playerid][4] == 7 && PlayerPlateNumber[playerid][5] == 7
	|| PlayerPlateNumber[playerid][4] == 8 && PlayerPlateNumber[playerid][5] == 8
	|| PlayerPlateNumber[playerid][4] == 9 && PlayerPlateNumber[playerid][5] == 9
	|| PlayerPlateNumber[playerid][4] == 10 && PlayerPlateNumber[playerid][5] == 10)
	{
		stoim += 450000;
	}


	if(PlayerPlateNumber[playerid][0] == PlayerPlateNumber[playerid][1] && PlayerPlateNumber[playerid][0] == PlayerPlateNumber[playerid][2] && PlayerPlateNumber[playerid][0] == PlayerPlateNumber[playerid][3])
	{
		// 3 один. цифры
	    if(stoim == 450000) stoim += 1050000;
	    else if(stoim == 350000) stoim += 1000000;
	    else if(stoim == 150000) stoim += 650000;
	    else stoim += 400000;
	}
	else if(PlayerPlateNumber[playerid][0] == PlayerPlateNumber[playerid][1] && PlayerPlateNumber[playerid][0] == PlayerPlateNumber[playerid][2] && PlayerPlateNumber[playerid][0] == PlayerPlateNumber[playerid][3] 
	&& PlayerPlateNumber[playerid][0] == PlayerPlateNumber[playerid][4])
	{
		// 4 один. цифры
	    if(stoim == 450000) stoim += 1250000;
	    else if(stoim == 350000) stoim += 1200000;
	    else if(stoim == 150000) stoim += 750000;
	    else stoim += 600000;
	}	

	else if(PlayerPlateNumber[playerid][0] == PlayerPlateNumber[playerid][1] && PlayerPlateNumber[playerid][0] == PlayerPlateNumber[playerid][2] && PlayerPlateNumber[playerid][0] != PlayerPlateNumber[playerid][3] 
	&& PlayerPlateNumber[playerid][0] !== PlayerPlateNumber[playerid][4])
	{
		// 2 один. цифры
	    if(stoim == 450000) stoim += 550000;
	    else if(stoim == 350000) stoim += 700000;
	    else if(stoim == 150000) stoim += 650000;
	    else stoim += 400000;
	}	

	
	if(PlayerPlateNumber[playerid][2] == 0 && PlayerPlateNumber[playerid][3] == 0  && PlayerPlateNumber[playerid][1] == 0)
	{
		stoim = 0;
	}

	return stoim;
}

CMD:remove_break(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
		return NoCMD(playerid);

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/remove_break [ID игрока]");
		
	if(!IsPlayerConnected(params[0])) 
		return SendErr(playerid, "Неверный ID");

	if(!GetPVarIntNew(playerid, "break_objects"))
		return SendErr(playerid, "У игрока не установлены объекты");

	for(new i; i < MAX_BREAK_COUNT; i++)
	{
		DestroyDynamicObject(police_object[i][params[0]]);
		DestroyDynamic3DTextLabel(police_text[i][params[0]]);
		DestroyDynamicArea(police_ships[i][params[0]]);
	}

	DeletePVarNew(params[0], "break_objects");

	format(String144, sizeof(String144), "Вы удалили все объекты игрока %s[%i]", pData[params[0]][pNickname], params[0]);
	SendSucc(playerid, String144);
	return true;
}

CMD:break(playerid)
{
	if(!IsACop(playerid))
		return SendErr(playerid, "Команда доступна полиции");

	if(GetPlayerVirtualWorld(playerid) != 0)
		return SendErr(playerid, "Команда доступна только на улице");

	if(IsPlayerInAnyVehicle(playerid)) 
		return SendErr(playerid,  "Вы не можете ставить ограждения находясь в машине");

	if(pGreenZone[playerid] == 1)
		return SendErr(playerid, "Запрещено ставить ограждения в Зеленой Зоне!");

	
	SPD(playerid, DIALOG_BREAK_SELECT, DIALOG_STYLE_LIST, !""cBLUE"Полицейские объекты", "\
		"cBLUE"1. "cWH"Поставить конус\n\
		"cBLUE"2. "cWH"Поставить бочку\n\
		"cBLUE"3. "cWH"Поставить забор\n\
		"cBLUE"4. "cWH"Поставить шипы\n\
		"cBLUE"5. "cWH"Убрать объекты",
		 !"Выбрать", !"Отмена");

	return true;
}

stock dialog_police_commad(playerid, dialogid, response, listitem)
{
	switch(dialogid)
	{
		case DIALOG_BREAK_SELECT:
		{
			if(!response)
				return true;

			new 
				Float:x, Float:y, Float:z, Float:angle;

	        GetPlayerPos(playerid, x, y, z);
	        GetPlayerFacingAngle(playerid, angle);

	        x += floatsin(-angle, degrees);
			y += floatcos(-angle, degrees);

			new 
				count;

			if(!GetPVarIntNew(playerid, "break_objects"))
			{
				count = 0;
			}
			else
			{
				count = GetPVarIntNew(playerid, "break_objects");
			}

			switch(listitem)
			{
				case 0:
				{
					if(count == MAX_BREAK_COUNT)
						return SendErr(playerid, "У вас максимальное количество установленных объектов");

        			police_object[count][playerid] = CreateDynamicObject(18191, x, y, z-0.8, 0, 0, angle, 0, 0);

        			SendSucc(playerid, "Вы установили объект 'Конус'");
				}
				case 1:
				{
					if(count == MAX_BREAK_COUNT)
						return SendErr(playerid, "У вас максимальное количество установленных объектов");

        			police_object[count][playerid] = CreateDynamicObject(18192, x, y, z-0.8, 0, 0, angle, 0, 0);

        			SendSucc(playerid, "Вы установили объект 'Бочка'");
				}
				case 2:
				{
					if(count == MAX_BREAK_COUNT)
						return SendErr(playerid, "У вас максимальное количество установленных объектов");

        			police_object[count][playerid] = CreateDynamicObject(18193, x, y, z-0.5, 0, 0, angle, 0, 0);

        			SendSucc(playerid, "Вы установили объект 'Забор'");
				}
				case 3:
				{
					if(count == MAX_BREAK_COUNT)
						return SendErr(playerid, "У вас максимальное количество установленных объектов");

        			police_object[count][playerid] = CreateDynamicObject(18194, x, y, z-0.9, 0, -90, angle, 0, 0);
        			police_ships[count][playerid] = CreateDynamicSphere(x, y, z, 2.0, 0, 0);

        			SendSucc(playerid, "Вы установили объект 'Шипы'");
				}
				case 4:
				{
					if(!GetPVarIntNew(playerid, "break_objects"))
						return SendErr(playerid, "У Вас нет установленных объектов");

					for(new i; i < MAX_BREAK_COUNT; i++)
					{
						DestroyDynamicObject(police_object[i][playerid]);
						DestroyDynamic3DTextLabel(police_text[i][playerid]);
						DestroyDynamicArea(police_ships[i][playerid]);
					}
					DeletePVarNew(playerid, "break_objects");
					SendSucc(playerid, "Вы удалили все свои установленные объекты");

					return true;
				}
			}

			new 
				text[3];

	   		format(text, sizeof(text), "%i", playerid);

			police_text[count][playerid] = CreateDynamic3DTextLabel(text, 0xFFFFFFAA, x, y, z-0.8, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0);

			ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 2, 0, 0, 0, 0, 0);

			SetPVarIntNew(playerid, "break_objects", count + 1);

			Streamer_Update(playerid);
			return true;
		}
	}
	return true;
}

stock area_police_ships(playerid, areaid)
{
	foreach(new p: logged_players)
	{
		for(new i; i < MAX_BREAK_COUNT; i++)
		{
			if(areaid == police_ships[i][p] && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
			{
			    new panels, doors, lights, tires;
				GetVehicleDamageStatus(GetPlayerVehicleID(playerid), panels, doors, lights, tires);
				UpdateVehicleDamageStatus(GetPlayerVehicleID(playerid), panels, doors, lights, 15);
			}
		}
	}
}

stock disconnect_police_break(playerid)
{
	if(GetPVarIntNew(playerid, "break_objects"))
	{
		for(new i; i < MAX_BREAK_COUNT; i++)
		{
			DestroyDynamicObject(police_object[i][playerid]);
			DestroyDynamic3DTextLabel(police_text[i][playerid]);
			DestroyDynamicArea(police_ships[i][playerid]);
		}
		DeletePVarNew(playerid, "break_objects");
	}
	return true;
}