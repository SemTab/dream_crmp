

stock create_bus_pickups()
{

	bus_actor = CreateActor(101, -485.7885,878.8422,12.1426,325.7766);
	bus_trigger = create_circle_pickup(-485.3754,879.4495,12.1426, TRIGGER_LBLUE);


	return true;
}

stock select_bus_work_route(playerid)
{
	if(!pData[playerid][pLicenses][LIC_DRIVING])
		return SendErr(playerid, "У вас нет лицензии на управление транспортом!");

	if(pData[playerid][pLevel] < 2)
		return SendErr(playerid, "Данный тип работы доступен со 2-го уровня!");

    format(String256, sizeof(String256), "\
    "cGREY"Маршрут\t"cGREY"Тип\t"cGREY"Водителей\n\
    "cBLUE"1. "cWH"Арзамас\tГородской\t"cBLUE"%d"cWH" водителей", driver_bus_route_1);
    return SPD(playerid, DIALOG_SELECT_ROUTE, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Выбор машрута", String256, !"Выбрать", !"Закрыть"); 
}

stock dialog_bus_rent(playerid)
{
	if(pTemp[playerid][rent_car] == GetPlayerVehicleID(playerid))
	{
		KillTimer(pTemp[playerid][rent_car_spawn_timer]);
		return true;
	}
	if(pTemp[playerid][rent_car] != INVALID_VEHICLE_ID)
	{
		SendErr(playerid, "Вы уже арендуете какой-либо транспорт");
		return RemovePlayerFromVehicleEx(playerid); 
	}

    WN_showCaptcha(playerid);

	PlayerPlaySound(playerid, 30803, 0.0, 0.0, 0.0);

	new
		price = get_job_level(playerid, SKILL_BUS_DRIVER)*100 + 500;

	format(String255, sizeof(String255), "\
		"cWH"Для того, чтобы начать работу водителя маршрутки необходимо внести\n\
		арендную плату за маршрутку, чтобы начать работать!\n\n\
		Стоимость аренды составляет "cGR"%d"cWH" рублей", price);
	return SPD(playerid, DIALOG_BUS_START, DIALOG_STYLE_MSGBOX, !""cBLUE"Аренда маршрутки", String255, !"Согласен", !"Позже");
}

stock work_bus_create(playerid)
{
	new 
		c1,
		c2;	

	if(GetPVarIntNew(playerid, "bus_route_1") == 1)
	{
		c1 = 7,
		c2 = 7;	
	}
	else if(GetPVarIntNew(playerid, "bus_route_1") == 2)
	{
		c1 = 3,
		c2 = 3;
	}

	new 
		bus_veh = CreateVehicle(418, -575.2104,888.6608,12.3600,181.5192, c1, c2, 600);	

	PutPlayerInVehicleEx(playerid, bus_veh, 0);

	vehicle[bus_veh][cFuel] = 50.0;
	vehicle[bus_veh][cHealth] = 1000.0;
	vehicle[bus_veh][cIsCreated] = true;
	vehicle[bus_veh][cOwnTo] = VEHICLES_BUS;
	vehicle[bus_veh][cLock] = 1;
	vehicle[bus_veh][consumables_oil] = 1000.0;

	vehicle_lock_status(bus_veh, false);

	if(GetPVarIntNew(playerid, "bus_route_1") == 1)
	{
		format(String144, sizeof(String144), "\
		"cBLUE"Рейсовый Автобус"cWH"\n\
		Маршрут:\nАрзамас");
		vehicle[bus_veh][cLabelTaxi] = CreateDynamic3DTextLabel(String144, -1, 0.0, 0.0, 0.5, 10.0, INVALID_PLAYER_ID, bus_veh, 1);
	}
	else if(GetPVarIntNew(playerid, "bus_route_2") == 1)
	{
		format(String144, sizeof(String144), "\
		"cLRED"Междугородний Автобус"cWH"\n\
		Маршрут:\nАрзамас-Батырево-Арзамас");
		vehicle[bus_veh][cLabelTaxi] = CreateDynamic3DTextLabel(String144, -1, 0.0, 0.0, 0.5, 10.0, INVALID_PLAYER_ID, bus_veh, 1);
	}

	new
		v = GetPlayerVehicleID(playerid);	

	pTemp[playerid][rent_car] = v;

	TogglePlayerControllable(playerid, true);

	return true;

}

stock job_rent_bus(playerid)
{

	if(pTemp[playerid][rent_car] != INVALID_VEHICLE_ID)
	{
		SendErr(playerid, "Вы уже арендуете какой-либо транспорт");
		return RemovePlayerFromVehicleEx(playerid); 
	}

	new 
		price = get_job_level(playerid, SKILL_BUS_DRIVER)*100 + 400;

	if(GetPlayerMoneyEx(playerid) < price)
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
		SendErr(playerid,"Недостаточно денежных средств!");
		return true;
	}

	check_quest_prize_start(playerid, 17);

	work_bus_create(playerid);

	if(GetPVarIntNew(playerid, "bus_route_1") == 1)
	{
		driver_bus_route_1++;
	}
	if(GetPVarIntNew(playerid, "bus_route_2") == 1)
	{
		driver_bus_route_2++;
	}

	SetPVarIntNew(playerid, "bus_job_cp", 1);

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_RIGHT, "brilliantother:info_gui_vehicle_rent", 3500);

	DisablePlayerCheckpoint(playerid);
	DisablePlayerRaceCheckpoint(playerid);

	new
		v = GetPlayerVehicleID(playerid);	

	bus_next_cp(playerid, v);

	return true;
}

stock work_bus_unrent(playerid)
{
	if(!GetPVarIntNew(playerid, "bus_job_cp")) return true;
	new 
		v = pTemp[playerid][rent_car];

	if(v == INVALID_VEHICLE_ID) 
		return true;

	if(vehicle[v][cOwnTo] != VEHICLES_BUS) 
		return true;

	DestroyVehicle(v);
	DisablePlayerRaceCheckpoint(playerid);
	DestroyDynamic3DTextLabel(vehicle[v][cLabelTaxi]);

 
	pTemp[playerid][rent_car] = INVALID_VEHICLE_ID;
	pTemp[playerid][rent_car_spawn_timer] = INVALID_TIMER_ID;

	if(GetPVarIntNew(playerid, "bus_route_1") == 1)
	{
		driver_bus_route_1--;
	}
	if(GetPVarIntNew(playerid, "bus_route_2") == 1)
	{
		driver_bus_route_2--;
	}

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:info_gui_vehicle_unrent", 3500);

	DeletePVarNew(playerid, "bus_route_1");
	DeletePVarNew(playerid, "bus_route_2");	

	DeletePVarNew(playerid, "bus_station_name");

	DeletePVarNew(playerid, "bus_job_cp");
	DeletePVarNew(playerid, "bus_job_salary");
	DeletePVarNew(playerid, "bus_job_cp_count");
	DeletePVarNew(playerid, "job_count_route");
	return true;
}

callback:: spawn_rent_car_bus(i, v, time)
{

	if(IsPlayerConnected(i))
	{	
		time--;
		
		if(!time)
		{
			work_bus_unrent(i);
			return true;
		}
		pTemp[i][rent_car_spawn_timer] = SetTimerEx("spawn_rent_car_bus", 1000, false, "iii", i, v, time);
	}
	return true; 
}

#define STATION 			1.0
#define NO_STATION 			2.0
#define FINAL_STATION		4.0

static const Float:bus_checkpoints_1[][] = {
	{0.0,			0.0,			0.0,			NO_STATION},
	{-512.9771,		868.7460,		12.3607,		NO_STATION},
	{-472.1646,		909.3768,		12.3564,		NO_STATION},
	{-467.3391,		951.6549,		12.3584,		STATION},
	{-398.5733,		963.9346,		12.4136,		NO_STATION},
	{-385.7494,		904.8724,		12.4162,		NO_STATION},
	{-386.6005,		728.2375,		12.4177,		NO_STATION},
	{-381.2990,		629.0808,		12.4173,		STATION},
	{-344.4970,		601.8409,		12.4217,		NO_STATION},
	{-338.9817,		504.5170,		13.0374,		NO_STATION},
	{-385.7621,		121.1563,		14.1584,		NO_STATION},
	{-421.0354,		111.3886,		14.1349,		NO_STATION},
	{-589.4114,		89.6589,		14.1214,		NO_STATION},
	{-568.8454,		63.6528,		14.1276,		NO_STATION},
	{-568.8454,		63.6528,		14.1276,		NO_STATION},
	{-562.7297,		102.8915,		14.1342,		NO_STATION},
	{-508.0236,		101.4037,		13.428,			NO_STATION},
	{-396.2592,		102.5959,		13.4389,		STATION},
	{-369.4340,		142.7820,		13.4025,		NO_STATION},
	{-314.8684,		582.9995,		11.7106,		NO_STATION},
	{-272.6119,		591.5726,		11.7139,		NO_STATION},
	{-4.8446,		555.7745,		11.7051,		NO_STATION},
	{99.7901,		540.4219,		11.7051,		STATION}, //TTT
	{131.7659,		554.7308,		11.7044,		NO_STATION},
	{218.5600,		779.0656,		11.7056,		NO_STATION},
	{265.8713,		775.5659,		11.7066,		NO_STATION},
	{464.7686,		695.8300,		11.704,			NO_STATION},
	{609.1060,		643.0933,		11.7056,		STATION},
	{669.4732,		619.6528,		11.7043,		NO_STATION},
	{671.0507,		584.9408,		11.7045,		NO_STATION},
	{635.2315,		494.5375,		11.7078,		NO_STATION},
	{464.9650,		416.9711,		11.6050,		NO_STATION},
	{295.0574,		475.9111,		11.7067,		NO_STATION},
	{198.3635,		515.4150,		11.7050,		NO_STATION},
	{139.9013,		537.5311,		11.7042,		STATION},
	{30.0810,		566.5374,		11.7056,		NO_STATION},
	{-124.3176,		586.8825,		11.7058,		NO_STATION},
	{-195.4675,		595.8119,		11.7067,		STATION},
	{-318.0673,		611.1984,		11.7077,		NO_STATION},
	{-371.8184,		656.1144,		11.7064,		NO_STATION},
	{-371.2174,		817.2916,		11.7052,		NO_STATION}, 
	{-370.9258,		895.3364,		11.7068,		STATION},
	{-371.7988,		955.3146,		11.7067,		NO_STATION},
	{-342.1007,		963.9858,		11.7132,		NO_STATION},
	{-195.2385,		947.1727,		11.7069,		NO_STATION},
	{-63.5679,		896.9265,		11.7063,		NO_STATION},
	{92.5267,		839.2349,		11.7055,		STATION},
	{200.5464,		803.2830,		11.7054,		NO_STATION},
	{233.7971,		818.5803,		11.7051,		NO_STATION},
	{251.4085,		863.0366,		11.7068,		NO_STATION}, 
	{278.6031,		1004.8176,		11.9234,		STATION},
	{295.5305,		1159.8976,		11.7042,		NO_STATION},
	{312.0038,		1322.8494,		11.6006,		NO_STATION}, 
	{327.3912,		1494.5240,		11.7031,		STATION},
	{340.8529,		1632.3369,		11.7020,		NO_STATION}, 
	{337.7795,		1659.8646,		11.7042,		STATION},
	{302.9279,		1690.4034,		11.7038,		NO_STATION},
	{183.7955,		1638.2612,		11.7038,		NO_STATION},
	{113.6467,		1299.7699,		11.7049,		NO_STATION}, //
	{93.7021,		1197.7141,		11.7057,		STATION},
	{57.2625,		1020.3268,		11.7045,		NO_STATION},
	{28.8602,		930.2723,		11.7068,		NO_STATION}, //
	{14.4272,		892.3505,		11.7062,		STATION},
	{-10.5603,		892.5357,		11.7042,		NO_STATION},
	{-107.2474,		929.3679,		11.7082,		NO_STATION},
	{-184.8389,		958.2745,		11.7076,		STATION},
	{-361.7608,		977.9287,		11.7135,		NO_STATION},
	{-497.4229,		977.8580,		11.6988,		NO_STATION},
	{-581.9317,		957.4437,		11.6760,		NO_STATION},
	{-534.5046,		870.7560,		11.6531,		NO_STATION},
	{-467.4989,		883.8018,		11.6512,		NO_STATION},
	{-469.8915,		919.8259,		11.6521,		FINAL_STATION}
};


stock get_name_next_st_bus_1(cp)
{
	new 
		name[40];

	switch(cp)
	{
		case 1: name = "Поле";
		case 2: name = "Автошкола";
		case 3: name = "Автосалон";
		case 4: name = "Старый Район";
		case 5: name = "Отель Диана";
		case 6: name = "Оперный театр";
		case 7: name = "Ресторан «У Сани»'";
		case 8: name = "Мэрия г.Арзамас";
		case 9: name = "ТЦ Спектр";
		case 10: name = "Банк";
		case 11: name = "Больница г.Арзамас";
		case 12: name = "Полицейский Участок г.Арзамас";
		case 13: name = "Рынок «Славянский»";
		case 14: name = "Развлекательный Центр";
		case 15: name = "Вокзал";
		default: name = "Отсутствует";
	}
	return name;
}

static const Float:bus_checkpoints_2[][] = {
	{0.0,			0.0,			0.0,			NO_STATION},
	{-472.1381,		914.7823,		11.6514,		STATION},
	{-467.1987,		957.8580,		11.6715,		NO_STATION},
	{-393.8067,		968.6158,		11.7069,		NO_STATION},
	{-371.5710,		1097.0934,		11.7067,		NO_STATION},
	{-572.3322,		1246.6980,		20.4571,		NO_STATION},
	{-965.0140,		1546.5349,		30.1157,		NO_STATION},
	{-1284.6068,	1830.0032,		48.1117,		NO_STATION},
	{-1529.0288,	2440.4282,		42.4861,		NO_STATION},
	{-1504.5389,	2481.6807,		41.1983,		NO_STATION},
	{-1410.1140,	2550.6563,		40.0981,		NO_STATION},
	{-1378.1162,	2623.0579,		40.0969,		NO_STATION},
	{-1386.8473,	2661.1238,		40.0999,		NO_STATION},
	{-1409.4221,	2651.9011,		40.0976,		NO_STATION},
	{-1485.6182,	2579.6638,		40.0969,		NO_STATION},
	{-1537.2596,	2460.4175,		42.4886,		NO_STATION},
	{-1966.5448,	2499.2766,		38.7422,		NO_STATION},
	{-2581.4683,	2407.7385,		52.7006,		NO_STATION},
	{-2641.2527,	1986.4261,		52.7207,		NO_STATION},
	{-2428.4180,	1787.0605,		52.7205,		NO_STATION},
	{-2289.2808,	1576.0989,		44.5464,		NO_STATION},
	{-2609.6560,	1103.8694,		9.1107,			NO_STATION},
	{-2647.0806,	795.0380,		9.7607,			NO_STATION},
	{-2661.5044,	450.3135,		9.5303,			NO_STATION},
	{-2620.5168,	-502.5285,		28.7563,		NO_STATION},
	{-2569.5198,	-1303.4934,		9.2089,			NO_STATION},
	{-2323.8564,	-1639.9507,		8.8696,			NO_STATION},
	{-1881.2997,	-2152.2068,		27.3051,		NO_STATION},
	{-1361.5723,	-2501.7166,		28.2981,		NO_STATION},
	{-1224.0979,	-2482.0171,		28.2371,		NO_STATION},
	{-1044.2188,	-2461.5027,		28.1582,		NO_STATION},
	{-935.0537,		-2408.1357,		32.7489,		NO_STATION},
	{-728.6686,		-2342.4082,		40.2879,		NO_STATION},
	{-454.0668,		-1618.2178,		40.6572,		NO_STATION},
	{43.2236,		-1028.5924,		40.6625,		NO_STATION},
	{481.6533,		-891.6306,		34.8545,		NO_STATION},
	{1126.3645,		-688.4708,		41.0737,		NO_STATION},
	{1573.1283,		-703.7689,		41.0626,		NO_STATION},
	{1739.1523,		-978.1027,		11.9632,		NO_STATION},
	{1805.0626,		-988.2532,		13.0705,		NO_STATION},
	{2442.7239,		-801.0519,		12.1433,		NO_STATION},
	{2791.3958,		-924.4969,		20.9558,		NO_STATION},
	{2754.7229,		-757.4438,		23.5145,		NO_STATION},
	{2844.0542,		-345.7442,		26.4556,		NO_STATION},
	{2914.8975,		45.7564,		23.1658,		NO_STATION},
	{2815.9417,		821.6918,		30.3846,		NO_STATION},
	{2740.7363,		1737.9940,		15.4930,		NO_STATION},
	{2749.1357,		1884.4708,		15.9961,		NO_STATION},
	{2683.5701,		1899.2235,		15.6822,		NO_STATION},
	{2379.8599,		1899.5563,		14.9777, 		NO_STATION},
	{2364.0767,		1952.7955,		15.5689,		STATION},
	{2347.8784,		1996.3966,		15.6970,		NO_STATION},
	{2326.6958,		1911.8645,		15.6213,		NO_STATION},
	{1978.1299,		1907.7637,		15.2240,		NO_STATION},
	{1967.9795,		1978.1123,		15.6037,		NO_STATION},
	{1903.4474,		2059.5317,		15.5808,		NO_STATION},
	{1895.5959,		2093.6064,		15.5704,		STATION},
	{1867.4778,		2342.2568,		15.6545,		NO_STATION},
	{1794.2748,		2472.3262,		15.4118,		NO_STATION},
	{1815.2643,		2516.8574,		15.3662, 		STATION},

	{1815.2509,		2517.0361,		15.3650,		NO_STATION},
	{1771.2919,		2511.6772,		15.3745,		STATION},
	{1785.6649,		2454.8506,		15.6502,		NO_STATION},
	{1887.3936,		2239.5056,		15.6580,		NO_STATION},
	{1880.6083,		2091.4290,		15.5426,		STATION},
	{1924.6593,		2053.4963,		15.5738,		NO_STATION},
	{1961.8318,		1935.8073,		15.2768,		NO_STATION},
	{1997.7198,		1902.2810,		15.2234,		NO_STATION},
	{2290.2222,		1903.4365,		15.6231,		NO_STATION},
	{2363.6775,		1952.7037,		15.5889,		STATION},
	{2358.4758,		1991.3759,		15.6970,		NO_STATION},
	{2350.6116,		1956.4117,		15.6048,		NO_STATION},
	{2324.9934,		1911.7357,		15.6187,		NO_STATION},
	{2067.9397,		1910.0459,		15.6334,		NO_STATION},
	{1968.1208,		1936.9269,		15.2775,		NO_STATION},
	{1931.2129,		2057.9590,		15.5750,		NO_STATION},
	{1896.6615,		2092.5354,		15.5147,		STATION},
	{1891.8439,		2211.2368,		15.6338,		NO_STATION},
	{1820.4081,		2414.2402,		15.6558,		NO_STATION},
	{1928.8701,		2694.6379,		14.9266,		NO_STATION},
	{2074.7205,		2944.3315,		11.6179,		NO_STATION},
	{2023.6357,		2961.8574,		12.3685,		NO_STATION},
	{1845.1588,		2971.7693,		11.5139,		STATION},
	{1657.9824,		2967.3975,		11.6949,		NO_STATION},
	{1457.5551,		2966.4417,		11.7057,		NO_STATION},
	{1349.6295,		2902.7009,		11.7057,		NO_STATION},
	{1053.5062,		2703.1936,		11.7085,		NO_STATION},
	{764.1358,		2532.9946,		11.7084,		NO_STATION},
	{397.3159,		1869.9224,		10.5042,		NO_STATION},
	{314.6491,		1511.7372,		11.7090,		NO_STATION},
	{220.8930,		823.2200,		11.7056,		NO_STATION},
	{137.7030,		836.4500,		11.7066,		NO_STATION},
	{-18.0151,		902.5106,		11.7027,		STATION},
	{-59.7510,		911.9000,		11.7065,		NO_STATION},
	{-361.1829,		977.9359,		11.7136,		NO_STATION},
	{-372.6361,		1159.3940,		11.7748,		NO_STATION},
	{-574.9475,		1247.6903,		20.4567,		NO_STATION},
	{-1002.5146,	1559.5974,		31.6668,		NO_STATION},
	{-1319.3330,	1959.6648,		22.9496,		NO_STATION},
	{-1408.7017,	2289.4573,		45.5581,		NO_STATION},
	{-1517.8654,	2465.6746,		41.8888,		NO_STATION},
	{-1399.8059,	2564.4207,		40.0981,		NO_STATION},
	{-1377.2076,	2625.7397,		40.0983,		NO_STATION},
	{-1387.9390,	2661.6035,		40.1010,		STATION},
	{-1410.8154,	2650.1809,		40.0966,		NO_STATION},
	{-1497.8849,	2559.2324,		40.0960,		NO_STATION},
	{-1538.7086,	2456.9241,		42.4849,		NO_STATION},
	{-2007.7638,	2502.6497,		36.6702,		NO_STATION},
	{-2629.1609,	2234.3130,		52.6995,		NO_STATION},
	{-2455.4468,	1800.8346,		52.7206,		NO_STATION},
	{-2278.9885,	1561.7711,		42.7304,		NO_STATION},
	{-2619.2048,	1084.1837,		9.0426,			NO_STATION},
	{-2667.3943,	448.3927,		9.4015,			NO_STATION},
	{-2664.8132,	37.0080,		10.8272,		NO_STATION},

	{-2666.8152,	-197.2000,		13.4401,		NO_STATION},
	{-2612.7842,	-526.2404,		29.2520,		NO_STATION},
	{-2600.6785,	-994.7363,		29.6206,		NO_STATION},
	{-2614.6904,	-1261.0597,		9.2537,			NO_STATION},
	{-2503.4968,	-1371.1385,		9.7208,			NO_STATION},
	{-2091.4524,	-1983.1180,		9.2800,			NO_STATION},
	{-1784.8698,	-2216.7737,		28.5375,		NO_STATION},
	{-1438.1589,	-2468.7583,		28.4105,		NO_STATION},
	{-1141.8363,	-2478.0408,		28.2614,		NO_STATION},
	{-1046.2561,	-2459.6882,		28.3945,		STATION},
	{-992.4623,		-2435.6289,		30.0063,		NO_STATION},
	{-746.0604,		-2369.9507,		37.9335,		NO_STATION},
	{-728.8467,		-2240.8916,		40.6649,		NO_STATION},
	{-599.9443,		-1874.2178,		40.6559,		NO_STATION},
	{-342.0536,		-1430.8857,		40.6696,		NO_STATION},
	{-36.3289,		-1054.8733,		40.6287,		NO_STATION},
	{-36.6872,		-1032.3960,		40.7811,		NO_STATION},
	{-129.0572,		-1014.0223,		42.2930,		NO_STATION},
	{-490.7895,		-740.5836,		47.6126,		NO_STATION},
	{-856.0029,		-732.5112,		54.8510,		NO_STATION},
	{-871.4103,		-460.9563,		54.8596,		NO_STATION},
	{-764.8864,		-290.5199,		54.8594,		NO_STATION},
	{-872.1052,		-127.4621,		54.8605,		NO_STATION},
	{-402.6224,		607.4131,		11.7487,		NO_STATION},
	{-376.3170,		645.5505,		11.7062,		NO_STATION},
	{-377.0433,		925.8669,		11.7069,		NO_STATION},
	{-408.4598,		973.6761,		11.7070,		NO_STATION},
	{-577.7079,		951.3939,		11.6571,		NO_STATION},
	{-525.5798,		871.3390,		11.6522,		NO_STATION},
	{-472.6075,		907.6775,		11.6514,		FINAL_STATION}
};




stock dialog_all_bus_work(playerid, dialogid, response, listitem)
{
	switch(dialogid)
	{
		case DIALOG_SELECT_ROUTE:
		{
			if (!response) 
				return true;

			switch(listitem)
			{
				case 0: 
				{
					SetPVarIntNew(playerid, "bus_route_1", 1);
					SendSucc(playerid, "Вы выбрали городской маршрут Арзамаса!");
					return dialog_bus_rent(playerid);			
				}
				case 1:
				{
					SetPVarIntNew(playerid, "bus_route_2", 1);
					SendSucc(playerid, "Вы выбрали междугородний маршрут Арзамас-Батырево-Арзамас!");
					return dialog_bus_rent(playerid);			
				}
			}		
		}
		case DIALOG_BUS_START: 
		{

			if (!response) 
				return true;

			return job_rent_bus(playerid);

		}

		case DIALOG_BUS_CONTINUE: 
		{

			if(!response)
			{
				SendSucc(playerid, "Вы закончили рабочий день водителем автобуса!");

				new 
					job_count_rout = GetPVarIntNew(playerid, "job_count_route");

				new 
					final_salary = job_count_rout*4000;

				give_money(playerid, final_salary, "Водитель автобуса (ЗП)");

				return work_bus_unrent(playerid);
			}
			
			DeletePVarNew(playerid, "bus_station_name");
			SetPVarIntNew(playerid, "bus_job_cp", 1);	
			bus_next_cp(playerid, GetPlayerVehicleID(playerid));
			return true;
		}
	}
	return true;
}

stock bus_next_cp(playerid, carid)
{
	new time = GetTickCount();


	if(vehicle[carid][cOwnTo] != VEHICLES_BUS) 
		return true;

	if(pTemp[playerid][rent_car] != carid) 
		return true;

	new
		cp = GetPVarIntNew(playerid, "bus_job_cp"),
		len_str = sizeof bus_checkpoints_1 - 1,
		cp_next = cp + 1;


	if(cp_next > len_str) cp_next = 1;
	if(len_str < cp < 1) 
		return true;


	if(bus_checkpoints_1[cp][3] == STATION)
		return bus_station_for_driver(playerid);

	if(bus_checkpoints_1[cp][3] == FINAL_STATION)
		return bus_station_final(playerid);



	SetPlayerRaceCheckpoint(playerid, 3, 
		bus_checkpoints_1[cp][0], bus_checkpoints_1[cp][1], bus_checkpoints_1[cp][2], 
		bus_checkpoints_1[cp_next][0], bus_checkpoints_1[cp_next][1], bus_checkpoints_1[cp_next][2] - 2.0, 4.0);

	cp++;
	if(cp > len_str) cp = 1;


	bus_station_count(playerid);
	SetPVarIntNew(playerid, "bus_job_cp", cp);

	if(debug_mode)
	{
		printf("[bus_next_cp]: Времени затрачено: <%d мс>" , GetTickCount() - time);
	}

	return true;
}

stock bus_next_cp_2(playerid, carid)
{
	new time = GetTickCount();


	if(vehicle[carid][cOwnTo] != VEHICLES_BUS) 
		return true;

	if(pTemp[playerid][rent_car] != carid) 
		return true;

	new
		cp = GetPVarIntNew(playerid, "bus_job_cp"),
		len_str = sizeof bus_checkpoints_2 - 1,
		cp_next = cp + 1;


	if(cp_next > len_str) cp_next = 1;
	if(len_str < cp < 1) 
		return true;


	if(bus_checkpoints_2[cp][3] == FINAL_STATION)
		return bus_station_final(playerid);



	SetPlayerRaceCheckpoint(playerid, 3, 
		bus_checkpoints_2[cp][0], bus_checkpoints_2[cp][1], bus_checkpoints_2[cp][2], 
		bus_checkpoints_2[cp_next][0], bus_checkpoints_2[cp_next][1], bus_checkpoints_2[cp_next][2] - 2.0, 4.0);

	cp++;
	if(cp > len_str) cp = 1;


	bus_station_count(playerid);
	SetPVarIntNew(playerid, "bus_job_cp", cp);

	if(debug_mode)
	{
		printf("[bus_next_cp]: Времени затрачено: <%d мс>" , GetTickCount() - time);
	}

	return true;
}

stock bus_station_for_driver(playerid)
{	
	TextDrawShowForPlayer(playerid, bus_timer);
	create_bus_timer_p(playerid);

	SetPVarIntNew(playerid, "bus_in_station", 1);

	DisablePlayerRaceCheckpoint(playerid);
	bus_station_count(playerid);
	TogglePlayerControllable(playerid, false);
	SetTimerEx("bus_station", 1000, false, "ii", playerid, BUS_JOB_STATION_TIME);

	SetPVarIntNew(playerid, "bus_station_name", GetPVarIntNew(playerid, "bus_station_name")+1);

	if(GetPVarIntNew(playerid, "bus_route_1") == 1)
	{
		new
			bus_name_st_count = GetPVarIntNew(playerid, "bus_station_name");

		ProxDetector(30.0,playerid,"",0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF);	
		format(String256, sizeof(String256),"• {00CC00}[Остановка] "cWH"Маршрутка отправляется через {00CC00}%d"cWH" секунд!", BUS_JOB_STATION_TIME);
		ProxDetector(30.0,playerid,String256,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF);
		format(String256, sizeof(String256),"• {00CC00}[Остановка] "cWH"Следующая остановка - {00CC00}%s"cWH"", get_name_next_st_bus_1(bus_name_st_count));
		ProxDetector(30.0,playerid,String256,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF);
		format(String256, sizeof(String256),"• {00CC00}[Остановка] "cWH"Пожалуйста, оплатите проезд и займите свои места!");
		ProxDetector(30.0,playerid,String256,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF);
	}

	return true;
}

stock bus_station_final(playerid)
{
	new 
		final_salary,
		fmt_str[200];

	DisablePlayerRaceCheckpoint(playerid);
	bus_station_count(playerid);

	add_player_job_skill(playerid, SKILL_BUS_DRIVER, 3);

	new 
		job_count_rout = SetPVarIntNew(playerid, "job_count_route", GetPVarIntNew(playerid, "job_count_route")+1);

	if(GetPVarIntNew(playerid, "bus_route_1") == 1)
	{
		final_salary = job_count_rout*5000;
	}
	else if(GetPVarIntNew(playerid, "bus_route_2") == 1)
	{
		final_salary = job_count_rout*5100;
	}

	format(fmt_str, 200, "\
		"cWH"Хотите проехать еще раз маршрут?\n\
		Вы уже проехали "cBLUE"%i"cWH" раз и заработали: "cGR"%i"cWH" рублей", job_count_rout, final_salary);
	return SPD(playerid, DIALOG_BUS_CONTINUE, DIALOG_STYLE_MSGBOX, !""cBLUE"Продолжение работы", fmt_str, !"Согласен", !"Закончить");	
}

callback::bus_station(i, time)
{
	new time_debug = GetTickCount();

	new 
		Float:x, Float:y, Float:z;

	GetPlayerPos(i, x, y, z);	


	time--;

	format(String64, 32,"%i", time);
	PlayerTextDrawSetString(i, bus_timer_p[i], String64);
	PlayerTextDrawShow(i, bus_timer_p[i]);

	if(!time)
	{
		SetPVarIntNew(i, "bus_job_cp", GetPVarIntNew(i, "bus_job_cp")+1);
		TogglePlayerControllable(i, true);


		PlayerTextDrawHide(i, bus_timer_p[i]);
		PlayerTextDrawDestroy(i, bus_timer_p[i]);
		TextDrawHideForPlayer(i, bus_timer);

		DeletePVarNew(i, "bus_in_station");

		if(GetPVarIntNew(i, "bus_route_1") == 1)
		{
			bus_next_cp(i, GetPlayerVehicleID(i));
		}
		else if(GetPVarIntNew(i, "bus_route_2") == 1)
		{
			bus_next_cp_2(i, GetPlayerVehicleID(i));
		}
	}
	else
	{
		SetTimerEx("bus_station", 1000, false, "ii", i, time);
	}

	return true;
}

stock bus_station_count(playerid)
{
	SetPVarIntNew(playerid,"bus_job_salary", GetPVarIntNew(playerid,"bus_job_salary") + BUS_JOB_SALARY_PER_CP);
	SetPVarIntNew(playerid,"bus_job_cp_count", GetPVarIntNew(playerid,"bus_job_cp_count") + 1);	
	return true;
}