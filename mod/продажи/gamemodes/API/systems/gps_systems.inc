


#define GPS_WORK_MINER				-1364.5054,2646.8506,40.5409
#define GPS_WORK_WOOD				-1043.4275,-2463.5049,28.4671
#define GPS_WORK_ZAVOD				2337.9241,2015.9314,15.9863
#define GPS_WORK_BUS				-484.5710,880.5175,12.1426

#define GPS_AUTOSCHOOL				-507.8322,21.0782,13.7661
#define GPS_CASINO					-111.7280,980.6890,12.1494
#define GPS_VOENKOMAT				1897.0640,2298.2080,15.7049
#define GPS_MOSCOW					-246.3821,90.6485,12.8541
#define GPS_BANK_ARZAMAS			357.0725,1367.5712,11.8959
#define GPS_BANK_YUG				2376.4111,-2143.4458,21.9567
#define GPS_BANK_BATIREVO			1850.7589,2041.4792,15.8850
		
#define GPS_SPAWN_1					1825.2239,2525.8062,15.6610
#define GPS_SPAWN_2					2722.7747,-2447.0801,21.8921
#define GPS_SPAWN_3					-489.1782,910.8972,12.1426
#define GPS_SPAWN_4					-2459.5256,2839.0706,38.4074
#define GPS_SPAWN_5					2501.8269,-2126.1152,23.4458
#define GPS_SPAWN_6					-42.5737,923.3008,12.0039
#define GPS_SPAWN_7					-491.3420,917.4787,12.1426	

#define GPS_AUTOSALON_1				430.8475,1174.6079,12.0006
#define GPS_AUTOSALON_2				456.5164,2200.9331,12.0003
#define GPS_AUTOSALON_3				2323.0161,-1804.0836,22.4540
#define GPS_AUTOSALON_4				1799.4829, -2277.5376, 11.0099
		
#define GPS_FSB						525.3879,329.9670,12.3440
#define GPS_POLICE_1				142.9867,1265.1210,12.0023
#define GPS_POLICE_2				2575.9224,-2416.0825,22.4946
#define GPS_PRAVO					-69.9947,864.3931,12.0030
#define GPS_HOSPITAL_1				405.4019,1762.2495,12.1223
#define GPS_HOSPITAL_2				2113.7642,-2386.4185,21.9430
#define GPS_FM_CENTER_1				-317.2266,827.1416,13.0559
#define GPS_FM_CENTER_2				2126.5369,-1953.3085,20.2422
#define GPS_ARMY					1900.6313,1731.8867,15.8589

#define GPS_BANDA_1					2417.9287,-1926.0703,22.0043
#define GPS_BANDA_2					-286.8448,514.4326,13.2709
#define GPS_BANDA_3					1800.4529,2200.8169,15.5873

#define GPS_HOTEL_1					189.5876,488.3698,12.0000
#define GPS_HOTEL_2					-224.8691,101.4548,12.8541
#define GPS_HOTEL_3					-2475.1953,2907.7063,37.7356
#define GPS_HOTEL_4					2085.3931,-2284.1201,21.7399

#define GPS_TAXI_YANDEX				418.5059,598.5196,12.0000
#define GPS_TAXI_UBER				2431.1577,-1710.4707,21.9431
#define GPS_TAXI_CITY				1756.0111,2477.9490,15.7101

#define GPS_TRUCKER_1				2199.4294,-875.2246,13.9766
#define GPS_TRUCKER_2				1847.4065,2905.9768,12.5645
#define GPS_TRUCKER_3				-2499.6423,-77.4533,13.3416

#define GPS_TECH_1					2055.1714,1887.4185,15.5409
#define GPS_TECH_2					2122.0769,-1830.2207,18.8213
#define GPS_TECH_3					398.2093,796.1278,12.1119

#define GPS_ZAVOD_NEFT				-2164.3894,-2651.2314,19.9106
#define GPS_MOSCOW_APART			-117.0529,-140.0708,12.9034	
#define GPS_RACE_CLASSIC			-1509.5198,1608.2966,36.7735

#define GPS_RACE_NEWYEAR			576.7292,2596.8311,11.6400
#define GPS_NEWYEAR_GENERAL			953.5804,974.9277,13.0000
#define GPS_NEWYEAR_KATOK			1083.0935,829.5957,14.5340
#define GPS_NEWYEAR_DED				1199.1659,888.4371,16.0000
#define GPS_NEWYEAR_ELKA			1148.3280,884.6901,12.8531

#define GPS_WORK_SNOW_DRIVER_1		780.4943, 752.0287, 12.9307
#define GPS_WORK_SNOW_DRIVER_2		2574.6716,-2081.0750,21.9640
#define GPS_WORK_SNOW_DRIVER_3		1757.4318,2242.6582,15.8598
#define GPS_WORK_SNOW_DRIVER_4		-2483.2371,2787.2449,37.8606
#define GPS_WORK_SNOW_DRIVER_5		-2243.6160,263.2382,24.5337

#define GPS_CAFE_LES				1137.1337,815.3893,12.2500	

#define HUNTER_SELLER_LEGAL			-1500.0608,-2229.7354,34.2995
#define HUNTER_SELLER_NO_LEGAL		-1639.6512,-2108.4402,29.7104

#define GREEN_HOUSE_GPS				1210.5452,-571.4602,41.2923

#define FISH_WORK_GPS				-1127.5762,2287.2266,38.8179	
#define TRASH_WORK_GPS				-2231.4395,258.1529,24.5337

#define BANK_WORK_GPS_1				357.1647,1363.6855,11.8959	
#define BANK_WORK_GPS_2				2378.8394,-2124.8313,21.7747
#define BANK_WORK_GPS_3				1860.7008,2041.5295,15.8850

#define GPS_WORK_FIRE				-433.0996,1025.3038,12.0093

#define GPS_PARKING_1				2219.08, -1960.96, 18.8197
#define GPS_PARKING_2				-425.717, 680.484, 12.1529
#define GPS_REALTOR					2197.2200,-2279.6899,22.9958

CMD:gps(playerid, params[])
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


	if(pTemp[playerid][pGPS] == true)
	{
		pTemp[playerid][pGPS] = false;
		SendSucc(playerid, "Метка в навигаторе снята!");
		
		DisablePlayerCheckpoint(playerid);
		DisablePlayerRaceCheckpoint(playerid);
		
		WN_showGPS(playerid, 2);
	}
	
	return dialog_show_gps(playerid);
}

stock dialog_show_gps(playerid)
{
	return SPD(playerid, DIALOG_GPS_SHOW, DIALOG_STYLE_LIST, !""cBLUE"Навигатор", !"\
		"cBLUE"- "cWH"Найти ближайший магазин 24/7\n\
		"cBLUE"- "cWH"Найти ближайший магазин одежды\n\
		"cBLUE"- "cWH"Найти ближайший магазин аксессуаров\n\
		"cBLUE"- "cWH"Найти ближайший клуб\n\
		"cBLUE"- "cWH"Найти ближайший банкомат\n\
		"cBLUE"- "cWH"Найти ближайшую АЗС\n\
		"cBLUE"- "cWH"Найти ближайший ресторан/закусочную\n\
		"cBLUE"- "cWH"Найти ближайший магазина оружия\n\
		"cBLUE"1. "cWH"Работы\n\
		"cBLUE"2. "cWH"Общественные места\n\
		"cBLUE"3. "cWH"Авторынки\n\
		"cBLUE"4. "cWH"Государственные организации\n\
		"cBLUE"5. "cWH"Криминальные структуры\n\
		"cBLUE"6. "cWH"Отели\n\
		"cBLUE"7. "cWH"Таксопарки\n\
		"cBLUE"8. "cWH"Транспортные Компании\n\
		"cBLUE"9. "cWH"Станции Технического Обслуживания\n\
		"cBLUE"10. "cWH"Развлечения", !"Выбрать", !"Закрыть");
}

stock show_gps_admin(playerid)
{
	return SPD(playerid, DIALOG_GPS_SHOW_ADMIN, DIALOG_STYLE_LIST, !""cBLUE"Телепорты", !"\
		"cBLUE"1. "cWH"Работы\n\
		"cBLUE"2. "cWH"Общественные места\n\
		"cBLUE"3. "cWH"Авторынки\n\
		"cBLUE"4. "cWH"Государственные организации\n\
		"cBLUE"5. "cWH"Криминальные структуры\n\
		"cBLUE"6. "cWH"Отели\n\
		"cBLUE"7. "cWH"Таксопарки\n\
		"cBLUE"8. "cWH"Транспортные Компании (Дальнобойщики)\n\
		"cBLUE"9. "cWH"Станции Технического Обслуживания\n\
		"cBLUE"10. "cWH"Развлечения", !"Выбрать", !"Закрыть");
}


stock dialog_show_gps_general(playerid, page)
{

	new 
		Float:x, 
		Float:y,
		Float:z;

	GetPlayerPos(playerid, x, y, z);

	switch(page)
	{
		case 0:
		{
			new
				Float:_distance = 3000.0,
				_b_id;

			for(new i = 0; i < all_buisness; i++)
			{
				if(buisness[i][buisnes_type] != BUISNES_PRODUCTION) 
					continue;

				new Float:__distance = GetPlayerDistanceFromPoint(playerid, buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z]);
				if(_distance > __distance) _distance = __distance, _b_id = i;
			}
			SetPlayerCheckpoint(playerid, buisness[_b_id][buisnes_enter_x], buisness[_b_id][buisnes_enter_y], buisness[_b_id][buisnes_enter_z], 5.0);
			WN_showGPS(playerid, 1);
			SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");

		}
		case 1:
		{
			new
				Float:_distance = 3000.0,
				_b_id;

			for(new i = 0; i < all_buisness; i++)
			{
				if(buisness[i][buisnes_type] != BUISNES_CLOTHES) 
					continue;

				new Float:__distance = GetPlayerDistanceFromPoint(playerid, buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z]);
				if(_distance > __distance) _distance = __distance, _b_id = i;
			}
			SetPlayerCheckpoint(playerid, buisness[_b_id][buisnes_enter_x], buisness[_b_id][buisnes_enter_y], buisness[_b_id][buisnes_enter_z], 5.0);
			WN_showGPS(playerid, 1);
			SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");

		}
		case 2:
		{
			new
				Float:_distance = 3000.0,
				_b_id;

			for(new i = 0; i < all_buisness; i++)
			{
				if(buisness[i][buisnes_type] != BUISNES_ACCESSORIES) 
					continue;

				new Float:__distance = GetPlayerDistanceFromPoint(playerid, buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z]);
				if(_distance > __distance) _distance = __distance, _b_id = i;
			}
			SetPlayerCheckpoint(playerid, buisness[_b_id][buisnes_enter_x], buisness[_b_id][buisnes_enter_y], buisness[_b_id][buisnes_enter_z], 5.0);
			WN_showGPS(playerid, 1);
			SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");

		}
		case 3:
		{
			new
				Float:_distance = 3000.0,
				_b_id;

			for(new i = 0; i < all_buisness; i++)
			{
				if(buisness[i][buisnes_type] != BUISNES_CLUB) 
					continue;

				new Float:__distance = GetPlayerDistanceFromPoint(playerid, buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z]);
				if(_distance > __distance) _distance = __distance, _b_id = i;
			}
			SetPlayerCheckpoint(playerid, buisness[_b_id][buisnes_enter_x], buisness[_b_id][buisnes_enter_y], buisness[_b_id][buisnes_enter_z], 5.0);
			WN_showGPS(playerid, 1);
			SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");

		}		
		case 4:
		{
			new 
				Float: DDist,
				AZS = -1;

			for(new i;i<ATM_COUNT;i++)                                       
			{
				if(DDist > GetPlayerDistanceFromPoint(playerid, gATMC[i][0], gATMC[i][1], gATMC[i][2]) || DDist < 0.5)
				{
					DDist = GetPlayerDistanceFromPoint(playerid, gATMC[i][0], gATMC[i][1], gATMC[i][2]);
					AZS = i;
				}

			}

			if(AZS != -1) 
			{

				SetPlayerCheckpoint(playerid, gATMC[AZS][0], gATMC[AZS][1], gATMC[AZS][2],5.0);
				WN_showGPS(playerid, 1);
				SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
				return 1;
			}
		}
		case 5:
		{
			new 
				Float: DDist,
				AZS = -1;

			for(new id_fill = 0; id_fill < sizeof(all_filling); id_fill++)                                                  
			{
				if(DDist > GetPlayerDistanceFromPoint(playerid, filling[id_fill][filling_info_enter_x], filling[id_fill][filling_info_enter_y], filling[id_fill][filling_info_enter_z]) || DDist < 0.5)
				{
					DDist = GetPlayerDistanceFromPoint(playerid, filling[id_fill][filling_info_enter_x], filling[id_fill][filling_info_enter_y], filling[id_fill][filling_info_enter_z]);
					AZS = id_fill;
				}

			}

			if(AZS != -1) 
			{

				SetPlayerCheckpoint(playerid, filling[AZS][filling_info_enter_x], filling[AZS][filling_info_enter_y], filling[AZS][filling_info_enter_z],5.0);
				WN_showGPS(playerid, 1);
				SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
				return 1;
			}
		}
		case 6:
		{

			new
				Float:_distance = 3000.0,
				_b_id;

			for(new i = 0; i < all_buisness; i++)
			{
				if(buisness[i][buisnes_type] != BUISNES_FASTFOOD) 
					continue;

				new Float:__distance = GetPlayerDistanceFromPoint(playerid, buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z]);
				if(_distance > __distance) _distance = __distance, _b_id = i;
			}
			SetPlayerCheckpoint(playerid, buisness[_b_id][buisnes_enter_x], buisness[_b_id][buisnes_enter_y], buisness[_b_id][buisnes_enter_z], 5.0);
			WN_showGPS(playerid, 1);
			SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");


		}

		case 7:
		{

			new
				Float:_distance = 3000.0,
				_b_id;

			for(new i = 0; i < all_buisness; i++)
			{
				if(buisness[i][buisnes_type] != BUISNES_AMMO_1) 
					continue;

				new Float:__distance = GetPlayerDistanceFromPoint(playerid, buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z]);
				if(_distance > __distance) _distance = __distance, _b_id = i;
			}
			SetPlayerCheckpoint(playerid, buisness[_b_id][buisnes_enter_x], buisness[_b_id][buisnes_enter_y], buisness[_b_id][buisnes_enter_z], 5.0);
			WN_showGPS(playerid, 1);
			SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");


		}

		case 8: 
		{

		    format(String3096, sizeof(String3096), "\
		        "cGREY"Пункт\t"cGREY"Расстояние\n\
				"cBLUE"1. "cWH"Шахта (Начальная работа)\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"2. "cWH"Лесопилка (Начальная работа)\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"3. "cWH"Завод (Начальная работа)\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"4. "cWH"Водитель автобуса\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"5. "cWH"Снегоуборщик г.Арзамас\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"6. "cWH"Снегоуборщик г.Южного\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"7. "cWH"Снегоуборщик п.Батырево\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"8. "cWH"Снегоуборщик г.Эдово\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"9. "cWH"Снегоуборщик г.Лыткарино\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"10. "cWH"Лесничий (продажа мяса)\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"11. "cWH"Браконьер (продажа мяса)\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"12. "cWH"Тепличный Комплекс\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"13. "cWH"Водитель мусоровоза\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"14. "cWH"Озеро для рыбалки\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"15. "cWH"Инкассатор г.Арзамас\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"16. "cWH"Инкассатор г.Южный\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"17. "cWH"Инкассатор п.Батырево\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"18. "cWH"Пожарный\t%d"cBLUE" метров"cWH"\
		        ", 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_WORK_MINER)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_WORK_WOOD)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_WORK_ZAVOD)),
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_WORK_BUS)),
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_WORK_SNOW_DRIVER_1)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_WORK_SNOW_DRIVER_2)),
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_WORK_SNOW_DRIVER_3)),
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_WORK_SNOW_DRIVER_4)),
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_WORK_SNOW_DRIVER_5)),
		        floatround(GetDistanceBetweenPoints(x, y, z, HUNTER_SELLER_LEGAL)),
		        floatround(GetDistanceBetweenPoints(x, y, z, HUNTER_SELLER_NO_LEGAL)),
		        floatround(GetDistanceBetweenPoints(x, y, z, GREEN_HOUSE_GPS)),
		        floatround(GetDistanceBetweenPoints(x, y, z, TRASH_WORK_GPS)),
		        floatround(GetDistanceBetweenPoints(x, y, z, FISH_WORK_GPS)),
		        floatround(GetDistanceBetweenPoints(x, y, z, BANK_WORK_GPS_1)),
		        floatround(GetDistanceBetweenPoints(x, y, z, BANK_WORK_GPS_2)),
		        floatround(GetDistanceBetweenPoints(x, y, z, BANK_WORK_GPS_3)),
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_WORK_FIRE))
		        );
		    return SPD(playerid, DIALOG_GPS_JOB, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Работы", String3096, !"Выбрать", !"Закрыть"); 
		}

		case 9:
		{
		    format(String2048, sizeof(String2048), "\
		        "cGREY"Пункт\t"cGREY"Расстояние\n\
				"cBLUE"1. "cWH"Автошкола\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"2. "cWH"Казино\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"3. "cWH"Военкомат\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"4. "cWH"Москва Сити\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"5. "cWH"Апартаменты Москва Сити\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"6. "cWH"Банк г. Арзамаc\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"7. "cWH"Банк г. Южный\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"8. "cWH"Банк п. Батырево\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"9. "cWH"Автовокзал п.Батырево\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"10. "cWH"Автовокзал г.Южный\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"11. "cWH"Автовокзал г.Арзамас\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"12. "cWH"Автовокзал п.Гарель\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"13. "cWH"ЖД Вокзал г.Южный\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"14. "cWH"Парк г.Арзамас\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"15. "cWH"Нефтезавод\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"16. "cWH"Паркинг г.Южный\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"17. "cWH"Паркинг г.Арзамас\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"18. "cWH"Риелторское Агенство\t%d"cBLUE" метров"cWH"\n\
		        ", 
		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_AUTOSCHOOL)), 
		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_CASINO)), 
		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_VOENKOMAT)), 
		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_MOSCOW)), 
		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_MOSCOW_APART)), 
		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_BANK_ARZAMAS)), 
		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_BANK_YUG)), 
		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_BANK_BATIREVO)),

		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_SPAWN_1)),
		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_SPAWN_2)),
		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_SPAWN_3)),
		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_SPAWN_4)),
		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_SPAWN_5)), 
		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_SPAWN_6)),
		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_ZAVOD_NEFT)),

		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_PARKING_1)), 
		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_PARKING_2)),
		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_REALTOR))

		        );
		    return SPD(playerid, DIALOG_GPS_OTHER, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Общественные места", String2048, !"Выбрать", !"Закрыть"); 

		}

		case 10:
		{

		    format(String512, sizeof(String512), "\
		        "cGREY"Пункт\t"cGREY"Расстояние\n\
				"cBLUE"1. "cWH"АвтоХаус (Премиум класс)\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"2. "cWH"АрзамасКарс (Средний класс)\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"3. "cWH"Автодвор (Эконом класс)\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"4. "cWH"Авторынок\t%d"cBLUE" метров"cWH"", 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_AUTOSALON_1)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_AUTOSALON_2)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_AUTOSALON_3)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_AUTOSALON_4))
		 	);
		    return SPD(playerid, DIALOG_GPS_CAR, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Авторынки", String512, !"Выбрать", !"Закрыть"); 


		}

		case 11:
		{
		    format(String1024, sizeof(String1024), "\
		        "cGREY"Пункт\t"cGREY"Расстояние\n\
				"cBLUE"1. "cWH"ФСБ\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"2. "cWH"Полиция г. Арзамас\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"3. "cWH"Полиция г. Южный\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"4. "cWH"Мэрия г. Арзамас\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"5. "cWH"Больница г. Арзамас\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"6. "cWH"Больница г. Южный\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"7. "cWH"Радиоцентр «Ритм»\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"8. "cWH"ТРК «Останкино»\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"9. "cWH"Армия\t%d"cBLUE" метров"cWH"", 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_FSB)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_POLICE_1)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_POLICE_2)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_PRAVO)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_HOSPITAL_1)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_HOSPITAL_2)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_FM_CENTER_1)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_FM_CENTER_2)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_ARMY))
		        );
		    return SPD(playerid, DIALOG_GPS_GOS, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Государственные организации", String1024, !"Выбрать", !"Закрыть"); 


		}

		case 12:
		{
		    format(String256, sizeof(String256), "\
		        "cGREY"Пункт\t"cGREY"Расстояние\n\
				"cBLUE"1. "cWH"Тамбовская ОПГ\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"2. "cWH"Курганская ОПГ\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"3. "cWH"Измайловская ОПГ\t%d"cBLUE" метров"cWH"", 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_BANDA_1)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_BANDA_2)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_BANDA_3)) 
		        );
		    return SPD(playerid, DIALOG_GPS_CRIME, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Криминальные структуры", String256, !"Выбрать", !"Закрыть"); 


		}	

		case 13:
		{

		    format(String512, sizeof(String512), "\
		        "cGREY"Пункт\t"cGREY"Расстояние\n\
				"cBLUE"1. "cWH"Гостиница Диана\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"2. "cWH"Гостиница Brilliant\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"3. "cWH"Гостиница г. Эдово\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"4. "cWH"Гостиница г. Южный\t%d"cBLUE" метров"cWH"", 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_HOTEL_1)),  
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_HOTEL_2)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_HOTEL_3)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_HOTEL_4)) 
		        );
		    return SPD(playerid, DIALOG_GPS_HOTEL, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Отели", String512, !"Выбрать", !"Закрыть"); 


		}
		case 14:
		{
		    format(String256, sizeof(String256), "\
		        "cGREY"Пункт\t"cGREY"Расстояние\n\
				"cBLUE"1. "cWH"Такси «YandexGO»\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"2. "cWH"Такси «UBER»\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"3. "cWH"Такси «СитиМобил»\t%d"cBLUE" метров"cWH"", 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_TAXI_YANDEX)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_TAXI_UBER)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_TAXI_CITY))
		        );
		    return SPD(playerid, DIALOG_GPS_TAXI, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Таксопарки", String256, !"Выбрать", !"Закрыть"); 


		}
		case 15:
		{
		    format(String256, sizeof(String256), "\
		        "cGREY"Пункт\t"cGREY"Расстояние\n\
				"cBLUE"1. "cWH"ТК «Деловые Линии»\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"2. "cWH"ТК «ЭйрТрансс»\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"3. "cWH"ТК «EMS Почта России»\t%d"cBLUE" метров"cWH"", 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_TRUCKER_1)),  
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_TRUCKER_2)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_TRUCKER_3)) 
		        );
		    return SPD(playerid, DIALOG_GPS_TRUCKER, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Транспортные компании", String256, !"Выбрать", !"Закрыть"); 


		}
		case 16:
		{
		    format(String256, sizeof(String256), "\
		        "cGREY"Пункт\t"cGREY"Расстояние\n\
				"cBLUE"1. "cWH"СТО №1\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"2. "cWH"СТО №2\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"3. "cWH"СТО №3\t%d"cBLUE" метров"cWH"", 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_TECH_1)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_TECH_2)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_TECH_3)) 
		        );
		    return SPD(playerid, DIALOG_GPS_STO, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"СТО", String256, !"Выбрать", !"Закрыть"); 
		}
		case 17:
		{
		    format(String256, sizeof(String256), "\
		        "cGREY"Пункт\t"cGREY"Расстояние\n\
				"cBLUE"1. "cWH"Классические гонки\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"2. "cWH"Гонки на снегоходах\t%d"cBLUE" метров"cWH"", 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_RACE_CLASSIC)),
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_RACE_NEWYEAR))
		        );
		    return SPD(playerid, DIALOG_RELAX_GPS, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Развлечения", String256, !"Выбрать", !"Закрыть"); 
		}
	}
	return true;
}


stock dialog_all_navigator(playerid, dialogid, response, listitem)
{
	switch(dialogid)
	{
	    case DIALOG_GPS_SHOW: 
	    {
			if(!response) 
				return true;

	    	switch(listitem)
	    	{
	    		//case 0: return dialog_show_gps_newyear(playerid);
		    	case 0: return dialog_show_gps_general(playerid, 0);
		    	case 1: return dialog_show_gps_general(playerid, 1);
		    	case 2: return dialog_show_gps_general(playerid, 2);
		    	case 3: return dialog_show_gps_general(playerid, 3);
		    	case 4: return dialog_show_gps_general(playerid, 4);
		    	case 5: return dialog_show_gps_general(playerid, 5);
		    	case 6: return dialog_show_gps_general(playerid, 6);
		    	case 7: return dialog_show_gps_general(playerid, 7);
		    	case 8: return dialog_show_gps_general(playerid, 8);
		    	case 9: return dialog_show_gps_general(playerid, 9);
		    	case 10: return dialog_show_gps_general(playerid, 10);
		    	case 11: return dialog_show_gps_general(playerid, 11);
		    	case 12: return dialog_show_gps_general(playerid, 12);
		    	case 13: return dialog_show_gps_general(playerid, 13);
		    	case 14: return dialog_show_gps_general(playerid, 14);
		    	case 15: return dialog_show_gps_general(playerid, 15);
		    	case 16: return dialog_show_gps_general(playerid, 16);
		    	case 17: return dialog_show_gps_general(playerid, 17);
		    }
	    }

	    case DIALOG_GPS_NEWYEAR:
	    {
			if(!response) 
				return true;

	    	switch(listitem)
	    	{
		    	case 0:
		    	{
					SetPlayerCheckpoint(playerid, GPS_NEWYEAR_GENERAL, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 1:
		    	{
					SetPlayerCheckpoint(playerid, GPS_NEWYEAR_KATOK, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 2:
		    	{
					SetPlayerCheckpoint(playerid, GPS_NEWYEAR_DED, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 3:
		    	{
					SetPlayerCheckpoint(playerid, GPS_NEWYEAR_ELKA, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 4:
		    	{
					SetPlayerCheckpoint(playerid, GPS_RACE_NEWYEAR, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 5:
		    	{

					SetPlayerCheckpoint(playerid, GPS_CAFE_LES, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");		    		
		    	}
		    }	    	
	    }

		case DIALOG_GPS_JOB: 
	    {	
			if(!response) 
				return true;

	    	switch(listitem)
	    	{
		    	case 0:
		    	{
					SetPlayerCheckpoint(playerid, GPS_WORK_MINER, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 1:
		    	{
					SetPlayerCheckpoint(playerid, GPS_WORK_WOOD, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 2:
		    	{
					SetPlayerCheckpoint(playerid, GPS_WORK_ZAVOD, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 3:
		    	{
					SetPlayerCheckpoint(playerid, GPS_WORK_BUS, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 4:
		    	{
					SetPlayerCheckpoint(playerid, GPS_WORK_SNOW_DRIVER_1, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 5:
		    	{
					SetPlayerCheckpoint(playerid, GPS_WORK_SNOW_DRIVER_2, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 6:
		    	{
					SetPlayerCheckpoint(playerid, GPS_WORK_SNOW_DRIVER_3, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 7:
		    	{
					SetPlayerCheckpoint(playerid, GPS_WORK_SNOW_DRIVER_4, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 8:
		    	{
					SetPlayerCheckpoint(playerid, GPS_WORK_SNOW_DRIVER_5, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 9:
		    	{
					SetPlayerCheckpoint(playerid, HUNTER_SELLER_LEGAL, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 10:
		    	{
					SetPlayerCheckpoint(playerid, HUNTER_SELLER_NO_LEGAL, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 11:
		    	{
					SetPlayerCheckpoint(playerid, GREEN_HOUSE_GPS, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 12:
		    	{
		    		SetPlayerCheckpoint(playerid, TRASH_WORK_GPS, 5.0);
		    		WN_showGPS(playerid, 1);
		    		SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");

		    	}
		    	case 13:
		    	{
		    		SetPlayerCheckpoint(playerid, FISH_WORK_GPS, 5.0);
		    		WN_showGPS(playerid, 1);
		    		SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 14:
		    	{
		    		SetPlayerCheckpoint(playerid, BANK_WORK_GPS_1, 5.0);
		    		WN_showGPS(playerid, 1);
		    		SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 15:
		    	{
		    		SetPlayerCheckpoint(playerid, BANK_WORK_GPS_2, 5.0);
		    		WN_showGPS(playerid, 1);
		    		SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 16:
		    	{
		    		SetPlayerCheckpoint(playerid, BANK_WORK_GPS_3, 5.0);
		    		WN_showGPS(playerid, 1);
		    		SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 17:
		    	{
		    		SetPlayerCheckpoint(playerid, GPS_WORK_FIRE, 5.0);
		    		WN_showGPS(playerid, 1);
		    		SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		        case 18:
		        {
		            SetPlayerCheckpoint(playerid, -1202.01, 39.13, 14.15, 5.0);
		    		WN_showGPS(playerid, 1);
		    		SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		        }
		    }
	    }
		case DIALOG_GPS_OTHER: 
	    {	
			if(!response) 
				return true;

	    	switch(listitem)
	    	{	    	
		    	case 0:
		    	{
					SetPlayerCheckpoint(playerid, GPS_AUTOSCHOOL, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 1:
		    	{
					SetPlayerCheckpoint(playerid, GPS_CASINO, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 2:
		    	{
					SetPlayerCheckpoint(playerid, GPS_VOENKOMAT, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 3:
		    	{
					SetPlayerCheckpoint(playerid, GPS_MOSCOW, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");	    		
		    	}
		    	case 4:
		    	{
					SetPlayerCheckpoint(playerid, GPS_MOSCOW_APART, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");	 
		    	}
		    	case 5:
		    	{
					SetPlayerCheckpoint(playerid, GPS_BANK_ARZAMAS, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");	    		
		    	}
		    	case 6:
		    	{
					SetPlayerCheckpoint(playerid, GPS_BANK_YUG, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");	    		
		    	}
		    	case 7:
		    	{
					SetPlayerCheckpoint(playerid, GPS_BANK_BATIREVO, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");	    		
		    	}
		    	case 8:
		    	{
					SetPlayerCheckpoint(playerid, GPS_SPAWN_1, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");	    		
		    	} 
		    	case 9:
		    	{
					SetPlayerCheckpoint(playerid, GPS_SPAWN_2, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");	    		
		    	} 
		    	case 10:
		    	{
					SetPlayerCheckpoint(playerid, GPS_SPAWN_3, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");	    		
		    	} 
		    	case 11:
		    	{
					SetPlayerCheckpoint(playerid, GPS_SPAWN_4, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");	    		
		    	} 
		    	case 12:
		    	{
					SetPlayerCheckpoint(playerid, GPS_SPAWN_5, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");	    		
		    	} 
		    	case 13:
		    	{
					SetPlayerCheckpoint(playerid, GPS_SPAWN_6, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");	    		
		    	} 	
		    	case 14:
		    	{
					SetPlayerCheckpoint(playerid, GPS_ZAVOD_NEFT, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");	    
		    	}	
		    	case 15:
		    	{
					SetPlayerCheckpoint(playerid, GPS_PARKING_1, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");	    
		    	}   
		    	case 16:
		    	{
					SetPlayerCheckpoint(playerid, GPS_PARKING_2, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");	    
		    	} 	
		    	case 17:
		    	{
					SetPlayerCheckpoint(playerid, GPS_REALTOR, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");	 
		    	}
		    }   	
	    }
		case DIALOG_GPS_CAR: 
	    {	
			if(!response) 
				return true;

	    	switch(listitem)
	    	{
		    	case 0:
		    	{
					SetPlayerCheckpoint(playerid, GPS_AUTOSALON_1, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 1:
		    	{
					SetPlayerCheckpoint(playerid, GPS_AUTOSALON_2, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 2:
		    	{
					SetPlayerCheckpoint(playerid, GPS_AUTOSALON_3, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 3:
		    	{
					SetPlayerCheckpoint(playerid, GPS_AUTOSALON_4, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");    		
		    	}
		    }
	    }
		case DIALOG_GPS_GOS: 
	    {	
			if(!response) 
				return true;

	    	switch(listitem)
	    	{	  
		    	case 0:
		    	{
					SetPlayerCheckpoint(playerid, GPS_FSB, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 1:
		    	{
					SetPlayerCheckpoint(playerid, GPS_POLICE_1, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 2:
		    	{
					SetPlayerCheckpoint(playerid, GPS_POLICE_2, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 3:
		    	{
					SetPlayerCheckpoint(playerid, GPS_PRAVO, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");	    		
		    	}
		    	case 4:
		    	{
					SetPlayerCheckpoint(playerid, GPS_HOSPITAL_1, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");	    		
		    	}
		    	case 5:
		    	{
					SetPlayerCheckpoint(playerid, GPS_HOSPITAL_2, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");	    		
		    	}
		    	case 6:
		    	{
					SetPlayerCheckpoint(playerid, GPS_FM_CENTER_1, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");	    		
		    	}
		    	case 7:
		    	{
					SetPlayerCheckpoint(playerid, GPS_FM_CENTER_2, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");	    		
		    	}
		    	case 8:
		    	{
					SetPlayerCheckpoint(playerid, GPS_ARMY, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");	    		
		    	}	 
		    }   		    	
	    }
		case DIALOG_GPS_CRIME: 
	    {	
			if(!response) 
				return true;

	    	switch(listitem)
	    	{	    	
		    	case 0:
		    	{
					SetPlayerCheckpoint(playerid, GPS_BANDA_1, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 1:
		    	{
					SetPlayerCheckpoint(playerid, GPS_BANDA_2, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 2:
		    	{
					SetPlayerCheckpoint(playerid, GPS_BANDA_3, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    }
	    }
		case DIALOG_GPS_HOTEL: 
	    {	
			if(!response) 
				return true;

	    	switch(listitem)
	    	{	    	
		    	case 0:
		    	{
					SetPlayerCheckpoint(playerid, GPS_HOTEL_1, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 1:
		    	{
					SetPlayerCheckpoint(playerid, GPS_HOTEL_2, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 2:
		    	{
					SetPlayerCheckpoint(playerid, GPS_HOTEL_3, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 3:
		    	{
					SetPlayerCheckpoint(playerid, GPS_HOTEL_4, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    }
	    }
		case DIALOG_GPS_TAXI: 
	    {	
			if(!response) 
				return true;

	    	switch(listitem)
	    	{	    	
		    	case 0:
		    	{
					SetPlayerCheckpoint(playerid, GPS_TAXI_YANDEX, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 1:
		    	{
					SetPlayerCheckpoint(playerid, GPS_TAXI_UBER, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 2:
		    	{
					SetPlayerCheckpoint(playerid, GPS_TAXI_CITY, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    }
	    }
		case DIALOG_GPS_TRUCKER: 
	    {	
			if(!response) 
				return true;

	    	switch(listitem)
	    	{
		    	case 0:
		    	{
					SetPlayerCheckpoint(playerid, GPS_TRUCKER_1, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 1:
		    	{
					SetPlayerCheckpoint(playerid, GPS_TRUCKER_2, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 2:
		    	{
					SetPlayerCheckpoint(playerid, GPS_TRUCKER_3, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    }
	    }
		case DIALOG_GPS_STO: 
	    {	
			if(!response) 
				return true;

	    	switch(listitem)
	    	{
		    	case 0:
		    	{
					SetPlayerCheckpoint(playerid, GPS_TECH_1, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 1:
		    	{
					SetPlayerCheckpoint(playerid, GPS_TECH_2, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 2:
		    	{
					SetPlayerCheckpoint(playerid, GPS_TECH_3, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    }
	    }

	    case DIALOG_RELAX_GPS:
	    {
			if(!response) 
				return true;

	    	switch(listitem)
	    	{
		    	case 0:
		    	{
					SetPlayerCheckpoint(playerid, GPS_RACE_CLASSIC, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
		    	}
		    	case 1:
		    	{
					SetPlayerCheckpoint(playerid, GPS_RACE_NEWYEAR, 5.0);
					WN_showGPS(playerid, 1);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");

		    	}
		    }	    	
	    }










	    case DIALOG_GPS_SHOW_ADMIN: 
	    {
			if(!response) 
				return true;

	    	switch(listitem)
	    	{
		    	case 0: return dialog_show_gps_admin(playerid, 0);
		    	case 1: return dialog_show_gps_admin(playerid, 1);
		    	case 2: return dialog_show_gps_admin(playerid, 2);
		    	case 3: return dialog_show_gps_admin(playerid, 3);
		    	case 4: return dialog_show_gps_admin(playerid, 4);
		    	case 5: return dialog_show_gps_admin(playerid, 5);
		    	case 6: return dialog_show_gps_admin(playerid, 6);
		    	case 7: return dialog_show_gps_admin(playerid, 7);
		    	case 8: return dialog_show_gps_admin(playerid, 8);
		    	case 9: return dialog_show_gps_admin(playerid, 9);
		    	case 10: return dialog_show_gps_admin(playerid, 10);
		    	case 11: return dialog_show_gps_admin(playerid, 11);
		    	case 12: return dialog_show_gps_admin(playerid, 12);
		    	case 13: return dialog_show_gps_admin(playerid, 13);
		    }
	    }

	    case DIALOG_GPS_NEWYEAR_ADMIN:
	    {
			if(!response) 
				return true;

	    	switch(listitem)
	    	{
		    	case 0:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_NEWYEAR_GENERAL);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_NEWYEAR_GENERAL);
					}	
		    	}
		    	case 1:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_NEWYEAR_KATOK);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_NEWYEAR_KATOK);
					}
		    	}
		    	case 2:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_NEWYEAR_DED);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_NEWYEAR_DED);
					}
		    	}
		    	case 3:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_NEWYEAR_ELKA);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_NEWYEAR_ELKA);
					}
		    	}
		    	case 4:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_RACE_NEWYEAR);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_RACE_NEWYEAR);
					}
		    	}
		    }	    	
	    }

		case DIALOG_GPS_JOB_ADMIN: 
	    {	
			if(!response) 
				return true;

	    	switch(listitem)
	    	{
		    	case 0:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_WORK_MINER);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_WORK_MINER);
					}					
		    	}
		    	case 1:
		    	{

					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_WORK_WOOD);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_WORK_WOOD);
					}					
		    	}
		    	case 2:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_WORK_ZAVOD);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_WORK_ZAVOD);
					}	
		    	}
		    	case 3:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_WORK_BUS);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_WORK_BUS);
					}		    		
		    	}

		    	case 4:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_WORK_SNOW_DRIVER_1);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_WORK_SNOW_DRIVER_1);
					}		    		
		    	}
		    	case 5:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_WORK_SNOW_DRIVER_2);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_WORK_SNOW_DRIVER_2);
					}		    		
		    	}
		    	case 6:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_WORK_SNOW_DRIVER_3);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_WORK_SNOW_DRIVER_3);
					}		    		
		    	}
		    	case 7:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_WORK_SNOW_DRIVER_4);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_WORK_SNOW_DRIVER_4);
					}		    		
		    	}
		    	case 8:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_WORK_SNOW_DRIVER_5);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_WORK_SNOW_DRIVER_5);
					}		    		
		    	}
		    	case 9:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), HUNTER_SELLER_LEGAL);
					}
					else
					{
						SetPlayerPosDebug(playerid, HUNTER_SELLER_LEGAL);
					}	
		    	}
		    	case 10:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), HUNTER_SELLER_NO_LEGAL);
					}
					else
					{
						SetPlayerPosDebug(playerid, HUNTER_SELLER_NO_LEGAL);
					}
		    	}
		    	case 11:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GREEN_HOUSE_GPS);
					}
					else
					{
						SetPlayerPosDebug(playerid, GREEN_HOUSE_GPS);
					}
		    	}
		    	case 12:
		    	{

					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), TRASH_WORK_GPS);
					}
					else
					{
						SetPlayerPosDebug(playerid, TRASH_WORK_GPS);
					}
		    	}
		    	case 13:
		    	{

					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), FISH_WORK_GPS);
					}
					else
					{
						SetPlayerPosDebug(playerid, FISH_WORK_GPS);
					}
		    	}
		    	case 14:
		    	{

					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), BANK_WORK_GPS_1);
					}
					else
					{
						SetPlayerPosDebug(playerid, BANK_WORK_GPS_1);
					}
		    	}
		    	case 15:
		    	{

					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), BANK_WORK_GPS_2);
					}
					else
					{
						SetPlayerPosDebug(playerid, BANK_WORK_GPS_2);
					}
		    	}
		    	case 16:
		    	{

					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), BANK_WORK_GPS_3);
					}
					else
					{
						SetPlayerPosDebug(playerid, BANK_WORK_GPS_3);
					}
		    	}	
		    	case 17:
		    	{

					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_WORK_FIRE);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_WORK_FIRE);
					}
		    	}	    			    	
		    }
	    }
		case DIALOG_GPS_OTHER_ADMIN: 
	    {	
			if(!response) 
				return true;

	    	switch(listitem)
	    	{	    	
		    	case 0:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_AUTOSCHOOL);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_AUTOSCHOOL);
					}

		    	}
		    	case 1:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_CASINO);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_CASINO);
					}

		    	}
		    	case 2:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_VOENKOMAT);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_VOENKOMAT);
					}

		    	}
		    	case 3:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_MOSCOW);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_MOSCOW);
					}
		    	}
		    	case 4:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_MOSCOW_APART);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_MOSCOW_APART);
					}
		    	}
		    	case 5:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_BANK_ARZAMAS);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_BANK_ARZAMAS);
					}

		    	}
		    	case 6:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_BANK_YUG);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_BANK_YUG);
					}
		    	}
		    	case 7:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_BANK_BATIREVO);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_BANK_BATIREVO);
					}
		    	}
		    	case 8:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_SPAWN_1);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_SPAWN_1);
					}  		
		    	} 
		    	case 9:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_SPAWN_2);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_SPAWN_2);
					}   		
		    	} 
		    	case 10:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_SPAWN_3);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_SPAWN_3);
					}	
		    	} 
		    	case 11:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_SPAWN_4);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_SPAWN_4);
					}   		
		    	} 
		    	case 12:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_SPAWN_5);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_SPAWN_5);
					}		
		    	} 
		    	case 13:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_SPAWN_6);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_SPAWN_6);
					}    		
		    	} 	
		    	case 14:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_ZAVOD_NEFT);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_ZAVOD_NEFT);
					}  
		    	} 
		    	case 15:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_PARKING_1);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_PARKING_1);
					}  
		    	}
		    	case 16:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_PARKING_2);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_PARKING_2);
					} 
		    	}
		    	case 17:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_REALTOR);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_REALTOR);
					} 
		    	}

		    }   	
	    }
		case DIALOG_GPS_CAR_ADMIN: 
	    {	
			if(!response) 
				return true;

	    	switch(listitem)
	    	{
		    	case 0:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_AUTOSALON_1);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_AUTOSALON_1);
					}

		    	}
		    	case 1:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_AUTOSALON_2);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_AUTOSALON_2);
					}
		    	}
		    	case 2:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_AUTOSALON_3);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_AUTOSALON_3);
					}
		    	}
		    	case 3:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_AUTOSALON_4);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_AUTOSALON_4);
					} 		
		    	}
		    }
	    }
		case DIALOG_GPS_GOS_ADMIN: 
	    {	
			if(!response) 
				return true;

	    	switch(listitem)
	    	{	  
		    	case 0:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_FSB);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_FSB);
					}

		    	}
		    	case 1:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_POLICE_1);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_POLICE_1);
					}
		    	}
		    	case 2:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_POLICE_2);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_POLICE_2);
					}
		    	}
		    	case 3:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_PRAVO);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_PRAVO);
					}
		    	}
		    	case 4:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_HOSPITAL_1);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_HOSPITAL_1);
					}
		    	}
		    	case 5:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_HOSPITAL_2);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_HOSPITAL_2);
					}   		
		    	}
		    	case 6:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_FM_CENTER_1);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_FM_CENTER_1);
					} 
		    	}
		    	case 7:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_FM_CENTER_2);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_FM_CENTER_2);
					}  		
		    	}
		    	case 8:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_ARMY);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_ARMY);
					}
		    	}	 
		    }   		    	
	    }
		case DIALOG_GPS_CRIME_ADMIN: 
	    {	
			if(!response) 
				return true;

	    	switch(listitem)
	    	{	    	
		    	case 0:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_BANDA_1);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_BANDA_1);
					}
		    	}
		    	case 1:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_BANDA_2);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_BANDA_2);
					}
		    	}
		    	case 2:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_BANDA_3);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_BANDA_3);
					}
		    	}
		    }
	    }
		case DIALOG_GPS_HOTEL_ADMIN: 
	    {	
			if(!response) 
				return true;

	    	switch(listitem)
	    	{	    	
		    	case 0:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_HOTEL_1);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_HOTEL_1);
					}
		    	}
		    	case 1:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_HOTEL_2);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_HOTEL_2);
					}
		    	}
		    	case 2:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_HOTEL_3);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_HOTEL_3);
					}
		    	}
		    	case 3:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_HOTEL_4);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_HOTEL_4);
					}
		    	}
		    }
	    }
		case DIALOG_GPS_TAXI_ADMIN: 
	    {	
			if(!response) 
				return true;

	    	switch(listitem)
	    	{	    	
		    	case 0:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_TAXI_YANDEX);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_TAXI_YANDEX);
					}

		    	}
		    	case 1:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_TAXI_UBER);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_TAXI_UBER);
					}
		    	}
		    	case 2:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_TAXI_CITY);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_TAXI_CITY);
					}
		    	}
		    }
	    }
		case DIALOG_GPS_TRUCKER_ADMIN: 
	    {	
			if(!response) 
				return true;

	    	switch(listitem)
	    	{
		    	case 0:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_TRUCKER_1);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_TRUCKER_1);
					}
		    	}
		    	case 1:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_TRUCKER_2);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_TRUCKER_2);
					}
		    	}
		    	case 2:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_TRUCKER_3);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_TRUCKER_3);
					}
		    	}
		    }
	    }
		case DIALOG_GPS_STO_ADMIN: 
	    {	
			if(!response) 
				return true;

	    	switch(listitem)
	    	{
		    	case 0:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_TECH_1);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_TECH_1);
					}
		    	}
		    	case 1:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_TECH_2);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_TECH_2);
					}
		    	}
		    	case 2:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_TECH_3);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_TECH_3);
					}
		    	}
		    }
	    }
	    case DIALOG_RELAX_GPS_ADMIN:
	    {
			if(!response) 
				return true;

	    	switch(listitem)
	    	{
		    	case 0:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_RACE_CLASSIC);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_RACE_CLASSIC);
					}
		    	}
		    	case 1:
		    	{
					if(IsPlayerInAnyVehicle(playerid))
					{
						SetVehiclePos(GetPlayerVehicleID(playerid), GPS_RACE_NEWYEAR);
					}
					else
					{
						SetPlayerPosDebug(playerid, GPS_RACE_NEWYEAR);
					}
		    	}
		    }	    	
	    }


	}



	return true;
}
















stock dialog_show_gps_admin(playerid, page)
{

	new 
		Float:x, 
		Float:y,
		Float:z;

	GetPlayerPos(playerid, x, y, z);

	switch(page)
	{
		case 0: 
		{

		    format(String3096, sizeof(String3096), "\
		        "cGREY"Пункт\t"cGREY"Расстояние\n\
				"cBLUE"1. "cWH"Шахта (Начальная работа)\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"2. "cWH"Лесопилка (Начальная работа)\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"3. "cWH"Завод (Начальная работа)\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"4. "cWH"Водитель автобуса\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"5. "cWH"Снегоуборщик г.Арзамас\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"6. "cWH"Снегоуборщик г.Южного\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"7. "cWH"Снегоуборщик п.Батырево\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"8. "cWH"Снегоуборщик г.Эдово\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"9. "cWH"Снегоуборщик г.Лыткарино\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"10. "cWH"Лесничий (продажа мяса)\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"11. "cWH"Браконьер (продажа мяса)\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"12. "cWH"Тепличный Комплекс\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"13. "cWH"Водитель мусоровоза\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"14. "cWH"Озеро для рыбалки\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"15. "cWH"Инкассатор г.Арзамас\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"16. "cWH"Инкассатор г.Южный\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"17. "cWH"Инкассатор п.Батырево\t%d"cBLUE" метров"cWH"\n\    
		        "cBLUE"18. "cWH"Пожарный\t%d"cBLUE" метров"cWH"\
		        ", 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_WORK_MINER)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_WORK_WOOD)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_WORK_ZAVOD)),
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_WORK_BUS)),
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_WORK_SNOW_DRIVER_1)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_WORK_SNOW_DRIVER_2)),
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_WORK_SNOW_DRIVER_3)),
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_WORK_SNOW_DRIVER_4)),
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_WORK_SNOW_DRIVER_5)),
		        floatround(GetDistanceBetweenPoints(x, y, z, HUNTER_SELLER_LEGAL)),
		        floatround(GetDistanceBetweenPoints(x, y, z, HUNTER_SELLER_NO_LEGAL)),
		        floatround(GetDistanceBetweenPoints(x, y, z, GREEN_HOUSE_GPS)),
		        floatround(GetDistanceBetweenPoints(x, y, z, TRASH_WORK_GPS)),
		        floatround(GetDistanceBetweenPoints(x, y, z, FISH_WORK_GPS)),
		        floatround(GetDistanceBetweenPoints(x, y, z, BANK_WORK_GPS_1)),
		        floatround(GetDistanceBetweenPoints(x, y, z, BANK_WORK_GPS_2)),
		        floatround(GetDistanceBetweenPoints(x, y, z, BANK_WORK_GPS_3)),
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_WORK_FIRE))
		        );
		    return SPD(playerid, DIALOG_GPS_JOB_ADMIN, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Работы", String3096, !"Выбрать", !"Закрыть"); 
		}

		case 1:
		{
		    format(String2048, sizeof(String2048), "\
		        "cGREY"Пункт\t"cGREY"Расстояние\n\
				"cBLUE"1. "cWH"Автошкола\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"2. "cWH"Казино\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"3. "cWH"Военкомат\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"4. "cWH"Москва Сити\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"5. "cWH"Апартаменты Москва Сити\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"6. "cWH"Банк г. Арзамаc\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"7. "cWH"Банк г. Южный\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"8. "cWH"Банк п. Батырево\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"9. "cWH"Автовокзал п.Батырево\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"10. "cWH"Автовокзал г.Южный\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"11. "cWH"Автовокзал г.Арзамас\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"12. "cWH"Автовокзал п.Гарель\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"13. "cWH"ЖД Вокзал г.Южный\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"14. "cWH"Парк г.Арзамас\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"15. "cWH"Нефтезавод\t%d"cBLUE" метров"cWH"\n\
		        "cBLUE"16. "cWH"Паркинг г.Южный\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"17. "cWH"Паркинг г.Арзамас\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"18. "cWH"Риелторское Агенство\t%d"cBLUE" метров"cWH"\n\
		        ", 
		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_AUTOSCHOOL)), 
		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_CASINO)), 
		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_VOENKOMAT)), 
		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_MOSCOW)), 
		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_MOSCOW_APART)), 
		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_BANK_ARZAMAS)), 
		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_BANK_YUG)), 
		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_BANK_BATIREVO)),

		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_SPAWN_1)),
		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_SPAWN_2)),
		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_SPAWN_3)),
		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_SPAWN_4)),
		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_SPAWN_5)), 
		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_SPAWN_6)),
		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_ZAVOD_NEFT)),

		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_PARKING_1)), 
		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_PARKING_2)),
		       floatround(GetDistanceBetweenPoints(x, y, z, GPS_REALTOR))

		        );
		    return SPD(playerid, DIALOG_GPS_OTHER_ADMIN, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Общественные места", String2048, !"Выбрать", !"Закрыть"); 

		}

		case 2:
		{

		    format(String512, sizeof(String512), "\
		        "cGREY"Пункт\t"cGREY"Расстояние\n\
				"cBLUE"1. "cWH"АвтоХаус (Премиум класс)\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"2. "cWH"АрзамасКарс (Средний класс)\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"3. "cWH"Автодвор (Эконом класс)\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"4. "cWH"Авторынок\t%d"cBLUE" метров"cWH"", 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_AUTOSALON_1)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_AUTOSALON_2)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_AUTOSALON_3)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_AUTOSALON_4))
		 	);
		    return SPD(playerid, DIALOG_GPS_CAR_ADMIN, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Авторынки", String512, !"Выбрать", !"Закрыть"); 


		}

		case 3:
		{
		    format(String1024, sizeof(String1024), "\
		        "cGREY"Пункт\t"cGREY"Расстояние\n\
				"cBLUE"1. "cWH"ФСБ\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"2. "cWH"Полиция г. Арзамас\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"3. "cWH"Полиция г. Южный\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"4. "cWH"Мэрия г. Арзамас\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"5. "cWH"Больница г. Арзамас\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"6. "cWH"Больница г. Южный\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"7. "cWH"Радиоцентр «Ритм»\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"8. "cWH"ТРК «Останкино»\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"9. "cWH"Армия\t%d"cBLUE" метров"cWH"", 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_FSB)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_POLICE_1)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_POLICE_2)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_PRAVO)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_HOSPITAL_1)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_HOSPITAL_2)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_FM_CENTER_1)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_FM_CENTER_2)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_ARMY))
		        );
		    return SPD(playerid, DIALOG_GPS_GOS_ADMIN, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Государственные организации", String1024, !"Выбрать", !"Закрыть"); 


		}

		case 4:
		{
		    format(String256, sizeof(String256), "\
		        "cGREY"Пункт\t"cGREY"Расстояние\n\
				"cBLUE"1. "cWH"Тамбовская ОПГ\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"2. "cWH"Курганская ОПГ\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"3. "cWH"Измайловская ОПГ\t%d"cBLUE" метров"cWH"", 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_AUTOSALON_1)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_AUTOSALON_2)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_AUTOSALON_3)) 
		        );
		    return SPD(playerid, DIALOG_GPS_CRIME_ADMIN, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Криминальные структуры", String256, !"Выбрать", !"Закрыть"); 


		}	

		case 5:
		{

		    format(String512, sizeof(String512), "\
		        "cGREY"Пункт\t"cGREY"Расстояние\n\
				"cBLUE"1. "cWH"Гостиница Диана\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"2. "cWH"Гостиница Brilliant\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"3. "cWH"Гостиница г. Эдово\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"4. "cWH"Гостиница г. Южный\t%d"cBLUE" метров"cWH"", 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_HOTEL_1)),  
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_HOTEL_2)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_HOTEL_3)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_HOTEL_4)) 
		        );
		    return SPD(playerid, DIALOG_GPS_HOTEL_ADMIN, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Отели", String512, !"Выбрать", !"Закрыть"); 


		}
		case 6:
		{
		    format(String256, sizeof(String256), "\
		        "cGREY"Пункт\t"cGREY"Расстояние\n\
				"cBLUE"1. "cWH"Такси «YandexGO»\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"2. "cWH"Такси «UBER»\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"3. "cWH"Такси «СитиМобил»\t%d"cBLUE" метров"cWH"", 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_TAXI_YANDEX)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_TAXI_UBER)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_TAXI_CITY))
		        );
		    return SPD(playerid, DIALOG_GPS_TAXI_ADMIN, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Таксопарки", String256, !"Выбрать", !"Закрыть"); 


		}
		case 7:
		{
		    format(String256, sizeof(String256), "\
		        "cGREY"Пункт\t"cGREY"Расстояние\n\
				"cBLUE"1. "cWH"ТК «Деловые Линии»\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"2. "cWH"ТК «ЭйрТрансс»\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"3. "cWH"ТК «EMS Почта России»\t%d"cBLUE" метров"cWH"", 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_TRUCKER_1)),  
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_TRUCKER_2)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_TRUCKER_3)) 
		        );
		    return SPD(playerid, DIALOG_GPS_TRUCKER_ADMIN, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Транспортные компании", String256, !"Выбрать", !"Закрыть"); 


		}
		case 8:
		{
		    format(String256, sizeof(String256), "\
		        "cGREY"Пункт\t"cGREY"Расстояние\n\
				"cBLUE"1. "cWH"СТО №1\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"2. "cWH"СТО №2\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"3. "cWH"СТО №3\t%d"cBLUE" метров"cWH"", 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_TECH_1)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_TECH_2)), 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_TECH_3)) 
		        );
		    return SPD(playerid, DIALOG_GPS_STO_ADMIN, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"СТО", String256, !"Выбрать", !"Закрыть"); 
		}
		case 9:
		{
		    format(String256, sizeof(String256), "\
		        "cGREY"Пункт\t"cGREY"Расстояние\n\
				"cBLUE"1. "cWH"Классические гонки\t%d"cBLUE" метров"cWH"\n\
				"cBLUE"2. "cWH"Гонки на снегоходах\t%d"cBLUE" метров"cWH"", 
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_RACE_CLASSIC)),
		        floatround(GetDistanceBetweenPoints(x, y, z, GPS_RACE_NEWYEAR)) 
		        );
		    return SPD(playerid, DIALOG_RELAX_GPS_ADMIN, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Развлечения", String256, !"Выбрать", !"Закрыть"); 
		}
	}
	return true;
}

stock status_navigator_player(playerid, type)
{

	switch(type)
	{
		case TEXTDRAW_SHOW:
		{
			show_player_gps(playerid, TEXTDRAW_SHOW);
			pTemp[playerid][pGPS] = true;
		}
		case TEXTDRAW_HIDE:
		{
			show_player_gps(playerid, TEXTDRAW_HIDE);
		}
	}

	return true;
}