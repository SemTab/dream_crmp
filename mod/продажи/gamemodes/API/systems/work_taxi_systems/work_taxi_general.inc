

static const taxi_rank_name[][] =
{	
	"Отсутствует",
    "Таксист",
    "Управляющий",
    "Владелец",
    "Рак Заморский"
};

static const mounth_taxi_stats[][] =
{	
	"ВЫ ЧЕ",
    "январь",
    "февраль",
    "март",
    "апрель",
    "май",
    "июнь",
    "июль",
    "августа", 
    "сентябрь",
    "октябрь",
    "ноябрь",
    "декабрь"
};


stock get_name_develiry(type)
{
	new 
		name[40];

	switch(type)
	{
		case 0: name = "Телефон Xiaomi";
		case 1: name = "Деньги в конверте";
		case 2: name = "Паспорт";
		case 3: name = "Неизвестная коробка 18+";
		case 4: name = "Мультиварка";
		case 5: name = "Наушники AirBuds";
		case 6: name = "Телефон Samsung";
		case 7: name = "Таблетки для памяти";
		case 8: name = "Плюшевого Мишку";
		case 9: name = "Продукты из магазина";
		case 10: name = "Видеокарту для компьютера";		
		case 11: name = "Розы (101 штука)";	
		case 12: name = "Чемодан с вещами";	
		case 13: name = "Геймерское кресло";	
		case 14: name = "Чехол для телефона";
		case 15: name = "Чёрный Ящик";		
		default: name = "Заброшенный";
	}
	return name;
}

static const Float:position_spawn_taxi_yandex[][] =
{
	{413.0704,582.4881,11.7052,339.9365},
	{409.6962,583.4920,11.7054,338.8212},
	{405.3818,585.0568,11.7047,341.2979},
	{401.7180,586.5297,11.7054,340.1907},
	{397.5559,587.9612,11.7048,339.5776},
	{393.2209,589.5099,11.7048,340.0268},
	{389.3830,590.9228,11.7053,341.5351},
	{410.4698,575.5977,11.7054,161.1686},
	{406.8541,576.9659,11.7048,159.0892},
	{402.8493,578.4699,11.7053,159.5545},
	{398.9522,579.7590,11.7050,160.4791},
	{395.0691,581.3200,11.7052,159.0626},
	{390.8242,582.8680,11.7051,159.6104},
	{387.0627,584.2621,11.7049,159.7082}
};

static const Float:position_spawn_taxi_uber[][] =
{
	{2404.6621,-1737.4105,21.5650,359.4641}, 
	{2409.0742,-1736.7736,21.5649,1.7029}, 
	{2413.3623,-1737.6931,21.5648,359.4670}, 
	{2417.9517,-1736.9574,21.5649,0.7347}, 
	{2422.1689,-1737.2921,21.5649,359.7640}, 
	{2426.6882,-1737.3702,21.5648,1.0723}, 
	{2431.0254,-1737.6563,21.5648,358.8517}, 
	{2421.8743,-1715.8646,21.5653,179.0901}

};

static const Float:position_spawn_taxi_city[][] =
{
	{1740.3207,2467.5220,15.4146,305.3513},
	{1737.9958,2471.3896,15.4148,304.4827},
	{1735.5170,2474.9426,15.4114,305.6621},
	{1733.2955,2478.7773,15.4109,306.2827}, 
	{1730.5109,2482.2158,15.4109,304.4020},
	{1727.8264,2485.8113,15.4078,305.5747},
	{1725.8542,2489.3877,15.4072,306.6776},
	{1718.8055,2484.6929,15.4077,125.0809},
	{1721.3389,2480.8545,15.4076,125.7365},
	{1723.8767,2477.5303,15.4078,125.6277},
	{1726.3203,2473.8918,15.4067,124.2199},
	{1728.7761,2470.4783,15.4077,125.7019},
	{1731.1815,2466.5610,15.4072,125.3118},
	{1733.5980,2463.1523,15.4074,124.7070}
};

static const Float:position_spawn_people_taxi[][] =
{
	{-2473.6360,2954.0249,37.7824,179.7888},
	{-2388.9277,2884.2395,37.7981,183.5265},
	{-2419.5149,2822.0947,37.6340,178.2020},
	{-2424.4570,2790.2969,37.6563,179.0143},
	{-2405.1421,2750.0415,39.1431,270.2542},
	{-2582.6006,179.5227,12.7502,267.3378},
	{-2423.7012,58.3173,21.2252,349.9520},
	{-2333.5518,272.7211,23.9369,170.5240},
	{-2190.7427,184.5097,29.0623,20.7838},
	{-2127.5198,21.4629,27.2934,292.9498},
	{-2218.8977,-0.8709,25.7579,348.9284},
	{-2143.1462,-234.7180,25.9898,259.5156},
	{684.9648,-1304.8396,40.6681,160.9441},
	{525.0026,-1304.8375,40.7311,340.9811},
	{1816.7467,-2559.0337,11.0010,87.2000},
	{1778.7852,-2443.3945,10.9956,90.0273},
	{1739.1824,-2322.3242,11.0010,91.7190},
	{2317.0537,-2639.7881,21.9886,1.9744},
	{2314.1548,-2591.4834,22.0434,183.1555},
	{2508.1438,-2590.5256,22.6037,270.8698},
	{2545.7625,-2512.0520,22.0053,91.3807},
	{2646.8186,-2410.6802,21.9766,271.2692},
	{2640.9529,-2231.2546,22.5529,270.2540},
	{2396.2563,-2554.2200,21.9886,1.7431}, // 24 (подруби анимку сидения)
	{2369.3428,-2498.8335,21.8714,84.8192}, // 25 (подруби анимку сидения)
	{2301.8398,-2478.0132,21.9495,91.4519}, // 26 (подруби анимку сидения)
	{2214.8796,-2473.7563,21.9417,180.6618}, // 27
	{2212.2778,-2390.7886,21.9430,358.8647},
	{1941.1453,-2214.0156,11.2510,0.1441},
	{1739.4137,-2373.5234,11.4047,87.1842},
	{1777.4335,-2421.4924,11.0010,91.4489},
	{1818.3602,-2535.7378,10.9956,90.0278},
	{2064.4475,-2391.7432,21.9430,272.8248},
	{2402.2693,-2116.5007,21.9779,270.7426},
	{2402.3171,-2026.8005,21.9779,271.6224},
	{2326.2151,-1922.1482,22.0800,271.8997},
	{2435.3259,-2130.4316,21.9779,0.5549},
	{2396.7710,-2617.6067,21.9886,90.3740}, // 38 (анимку сидения)
	{2068.4893,-2374.1565,21.9430,269.1862}, // 39
	{2270.9399,-1844.2422,21.9627,266.4050},
	{2355.0122,-261.4990,2.7890,176.0197},
	{2223.9939,-180.2720,2.1452,270.3047},
	{1999.2600,1339.1442,26.1511,180.2218},
	{1868.6863,1381.1144,9.7556,268.4771},
	{2248.5151,1362.5568,11.3675,188.0664},
	{1942.2638,2066.4431,15.7053,180.4044},
	{1856.3195,2166.2454,15.9226,94.2470},
	{1793.0728,2165.0408,15.9806,270.0727},
	{-237.9674,-90.8529,13.9821,221.7513},
	{-137.9134,596.7781,12.1346,171.6543},
	{-307.1755,490.3254,13.2244,83.5956},
	{-225.6926,656.5713,13.2334,269.3119},
	{-223.9924,617.8553,12.0010,182.8838},
	{-243.7030,905.0935,13.6375,180.8532},
	{-304.3335,911.8961,12.1497,91.0412},
	{-358.6742,1003.7504,12.1338,0.6199},
	{-234.6659,1053.7946,12.0010,90.3641},
	{-180.0776,1067.5513,12.3796,90.5672},
	{-146.7743,979.1054,14.5556,88.1985},
	{-18.1886,1198.2378,12.0000,317.6359},
	{-31.1001,1277.9799,12.1763,318.9285},
	{91.3094,1340.4333,12.2653,77.0837},
	{63.9763,1229.9773,12.0000,169.7909}, // 63 (посади в анимке)
	{125.1086,1129.8271,12.0000,346.6100}, // 64 (посади в анимке)
	{178.6935,1135.4810,12.2763,82.5129}, // 65
	{381.7248,1112.9907,12.6063,353.0388}, // 66
	{285.6120,1508.2181,12.0984,174.8441}, // 67
	{225.2718,1628.7302,11.9981,260.5125}, // 68
	{-33.6676,1351.1321,12.8750,348.3621}, // 69
	{-37.4737,1085.7360,12.0000,109.2399}, // 70 (посади в анимку)
	{212.2686,610.4219,12.1360,338.0074}, // 71
	{259.6908,680.1535,12.0000,249.3981}, // 72
	{250.7273,755.8986,12.0000,250.0072}, // 73
	{278.4233,821.0433,12.3019,338.4134}, // 74
	{282.7681,868.8997,12.1667,249.6096}, // 75
	{253.2243,1057.6449,12.1646,308.8369}, // 76
	{-1372.3704,2655.3923,40.5717,52.5271}, // 77
	{155.0899,574.7554,12.0000,71.7952}, // 78
	{2402.2571,-2066.5386,21.9779,267.4942}, // 79
	{-291.3768,958.9504,12.1497,2.1517}, // 80
	{-7.6072,912.2155,12.0020,158.8324}, // 81
	{218.8993,415.6465,11.1568,251.6358}, // 82
	{133.0303,664.9681,12.7650,250.8237}, // 83
	{2260.9666,-2103.7441,21.9688,89.2025}, // 84
	{-2163.5471,112.0794,29.0623,289.4698}, // 85
	{-2165.5017,142.1619,25.6479,292.5153}, // 86
	{305.4934,1646.5286,11.9981,269.3009}, // 87
	{150.1458,779.8357,12.1555,278.7762}, // 88
	{1795.2578,2507.2927,15.6532,35.9923}, // 89
	{-2390.7305,260.3038,23.7133,172.4364}, // 90
	{-2407.1973,2804.9553,37.6340,2.0843}, // 91
	{-2376.8875,188.2311,21.4564,78.1578}, // 92
	{2353.2864,-2140.6260,21.9609,178.8013}, // 93
	{199.6334,827.2847,12.4385,238.7201}, // 94
	{1853.7533,2035.0083,16.9742,2.7002}, // 95
	{1892.6381,1728.8828,15.5405,270.8732}, // 96
	{387.8474,1399.0350,11.8959,86.2516}, // 97
	{2484.2163,-1939.9766,23.4458,182.1241}, // 98
	{-496.3959,909.8751,12.1426,273.0374}, // 99
	{2741.4673,-2469.2915,21.8921,271.8928}, // 100
	{-2475.7368,2768.6531,38.0793,359.8661}, // 101
	{-14.7029,952.1176,11.8036,341.8128}, // 102
	{-0.8198,1584.3472,9.5653,126.0337}, // 103
	{5.9288,1756.7716,9.3984,183.0884}, // 104 (посади в анимку)
	{261.2715,1929.2932,12.0000,262.1017}, // 105 (посади в анимку)
	{373.0245,1940.5554,11.4922,22.4068}, // 106 (посади в анимку)
	{374.1683,1947.1116,11.4922,152.4212} // 107 (посади в анимку)



};


callback:: load_taxi_server()
{

	new Result:taxi_load_company = sql_queryEx(zConn, "SELECT * FROM `taxi` ORDER BY `taxi_id`", QUERY_CACHED);

	new all_taxi_company = sql_num_rows(taxi_load_company);

	new time = GetTickCount();

	new 
		load_taxi_company; 

 	for(new i; i < all_taxi_company; i++)
	{

		taxi_company[i][taxi_company_id]  = sql_get_field_assoc_int_ex(taxi_load_company, i, "taxi_id"); 

		taxi_company[i][taxi_company_owner_id]  = sql_get_field_assoc_int_ex(taxi_load_company, i, "taxi_owner_id"); 

		taxi_company[i][taxi_company_price]  = sql_get_field_assoc_int_ex(taxi_load_company, i, "taxi_company_price"); 
		taxi_company[i][taxi_company_closed]  = sql_get_field_assoc_int_ex(taxi_load_company, i, "taxi_company_closed"); 
		taxi_company[i][taxi_company_days]  = sql_get_field_assoc_int_ex(taxi_load_company, i, "taxi_company_days"); 
		taxi_company[i][taxi_company_bank]  = sql_get_field_assoc_int_ex(taxi_load_company, i, "taxi_company_bank"); 	

		taxi_company[i][taxi_company_price_econom]  = sql_get_field_assoc_int_ex(taxi_load_company, i, "taxi_company_price_econom"); 
		taxi_company[i][taxi_company_price_comfort]  = sql_get_field_assoc_int_ex(taxi_load_company, i, "taxi_company_price_comfort"); 
		taxi_company[i][taxi_company_price_buisnes]  = sql_get_field_assoc_int_ex(taxi_load_company, i, "taxi_company_price_buisnes"); 	

		taxi_company[i][taxi_company_percent_1]  = sql_get_field_assoc_int_ex(taxi_load_company, i, "taxi_company_percent_1");
		taxi_company[i][taxi_company_percent_2]  = sql_get_field_assoc_int_ex(taxi_load_company, i, "taxi_company_percent_2"); 	

		taxi_company[i][taxi_finka_ogran]  = sql_get_field_assoc_int_ex(taxi_load_company, i, "taxi_finka_ogran");
		taxi_company[i][taxi_finka_ogran_day]  = sql_get_field_assoc_int_ex(taxi_load_company, i, "taxi_finka_ogran_day"); 	
		taxi_company[i][taxi_sell_day_payday]  = sql_get_field_assoc_int_ex(taxi_load_company, i, "taxi_sell_day_payday"); 

  		taxi_company[i][taxi_pos_x] = sql_get_field_assoc_float_ex(taxi_load_company, i, "taxi_pos_x");
  		taxi_company[i][taxi_pos_y] = sql_get_field_assoc_float_ex(taxi_load_company, i, "taxi_pos_y");
  		taxi_company[i][taxi_pos_z] = sql_get_field_assoc_float_ex(taxi_load_company, i, "taxi_pos_z");

		taxi_company[i][taxi_company_icon] = CreateDynamicMapIcon(taxi_company[i][taxi_pos_x], taxi_company[i][taxi_pos_y], taxi_company[i][taxi_pos_z], 42 , -1);

		new 
			pickup_color;

		if(i == TAXI_COMPANY_CITY)
		{
			pickup_color = TRIGGER_ORANGE;
		}
		else if(i == TAXI_COMPANY_YANDEX)
		{
			pickup_color = TRIGGER_YELLOW;
		}
		else if(i == TAXI_COMPANY_UBER)
		{
			pickup_color = TRIGGER_BLACK;
		}


		taxi_company[i][taxi_company_pickup] = create_circle_pickup(taxi_company[i][taxi_pos_x], taxi_company[i][taxi_pos_y], taxi_company[i][taxi_pos_z], pickup_color);


		taxi_company[i][taxi_company_count_car] = 30;
		taxi_company[i][taxi_company_count_working] = 0;

		load_taxi_company++;

	}

	create_taxi_company_other();
	create_taxi_text_company();

	printf("[Такси]: <%i из %i>. Времени затрачено: <%d мс>" , all_taxi_company, load_taxi_company, GetTickCount()-  time);
	sql_next_row(taxi_load_company);

	return true;
}

stock save_taxi_base()
{
	for(new i; i < MAX_TAXI_COMPANY; i++)
	{

		format(String2048, sizeof(String2048), "\
			UPDATE taxi SET \
			taxi_owner_id = '%d', \
			taxi_company_price = '%d', \
			taxi_company_closed = '%d', \
			taxi_company_days = '%d', \
			taxi_company_bank = '%d', \
			taxi_company_price_econom = '%d', \
			taxi_company_price_comfort = '%d', \
			taxi_company_price_buisnes = '%d', \
			taxi_company_percent_1 = '%d', \
			taxi_company_percent_2 = '%d', \
			taxi_finka_ogran = '%d', \
			taxi_finka_ogran_day = '%d', \
			taxi_sell_day_payday = '%d' \
			WHERE taxi_id = '%d'",

			taxi_company[i][taxi_company_owner_id],
			taxi_company[i][taxi_company_price],
			taxi_company[i][taxi_company_closed],
			taxi_company[i][taxi_company_days],
			taxi_company[i][taxi_company_bank],

			taxi_company[i][taxi_company_price_econom],
			taxi_company[i][taxi_company_price_comfort],
			taxi_company[i][taxi_company_price_buisnes],

			taxi_company[i][taxi_company_percent_1],
			taxi_company[i][taxi_company_percent_2],

			taxi_company[i][taxi_finka_ogran],
			taxi_company[i][taxi_finka_ogran_day],
			taxi_company[i][taxi_sell_day_payday],

			i);

		sql_queryEx(zConn, String2048, QUERY_THREADED);	
	}
	return true;
}
 
stock sell_taxi_payday(f)
{

	if(taxi_company[f][taxi_company_days] == 0 && taxi_company[f][taxi_company_owner_id] != -1)
		return printf("[ДАЛЬНОБОИ PAYDAY СЛЕТ] %d (%d) - оплачено | %d - владелец",f, taxi_company[f][taxi_company_days], taxi_company[f][taxi_company_owner_id]);


	new 
		owner_id = taxi_company[f][taxi_company_owner_id];

	new 
		taxi_change_name_dialog[32];


	GetPlayerNameByID(owner_id, taxi_change_name_dialog);

	new 
		player_id = GetPlayerID(taxi_change_name_dialog);	

	new 
		final_money = floatround(taxi_company[f][taxi_company_price]*0.8);


	GetPlayerNameByID(owner_id,taxi_change_name_dialog);


	if(IsPlayerConnected(player_id))
	{
		if(pData[player_id][pTaxiOwnerID] == f)
		{	
			pData[player_id][pTaxiOwnerID] = -1;
			UpdatePlayerData(player_id,"pTaxiOwnerID", pData[player_id][pTaxiOwnerID]);


			pData[player_id][pTaxi] = -1;
			pData[player_id][pTaxiOwnerLowID] = -1;
			pData[player_id][pTaxiRank] = 0;
			pData[player_id][pJob] = 0;

			UpdatePlayerData(player_id,"pTaxi", pData[player_id][pTaxi]);
			UpdatePlayerData(player_id,"pTaxiOwnerLowID", pData[player_id][pTaxiOwnerLowID]);
			UpdatePlayerData(player_id,"pTaxiRank", pData[player_id][pTaxiRank]);
			UpdatePlayerData(player_id, "job", pData[player_id][pJob]);

			format(String256,sizeof(String256),"DELETE FROM `taxi_personal` WHERE `user_id` = '%d'", owner_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);

			SFCM(player_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Ваше Такси было продано за неуплату!");	

	        SendClientMessage(player_id, COLOR_LIGHTRED, "Вы можете вернуть 80 процентов от стоимости имущества");
	        SendClientMessage(player_id, COLOR_LIGHTRED, "Для этого введите команду /returnmoney");


	        pData[player_id][pReturnMoney] += final_money;
	        if(pData[player_id][pReturnMoney] > 20000000 ) pData[player_id][pReturnMoney] = 0;
		}
	}
	else
	{	
		new 
			formate_str[100];

		format(formate_str, 80, "UPDATE accounts SET pTaxiOwnerID = '-1' WHERE pTaxiOwnerID = '%d'", f);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);

		format(String256,sizeof(String256),"DELETE FROM `taxi_personal` WHERE `user_id` = '%d'", owner_id);
		sql_queryEx(zConn, String256, QUERY_THREADED);	

		format(String256,sizeof(String256),"UPDATE `accounts` SET returnmoney = returnmoney + %d WHERE id = '%i'", final_money, owner_id);
		sql_queryEx(zConn, String256, QUERY_THREADED);

		send_off_message(-1, taxi_change_name_dialog, "Ваше Такси было продано государству за неуплату. Мы вернули 80 процентов (/returnmoney)");
	}




	taxi_company[f][taxi_company_owner_id] = -1;	
	taxi_company[f][taxi_company_bank] = 0;

	taxi_company[f][taxi_status_sell] = 3;
	taxi_company[f][taxi_sell_day_payday] = RandomEx(2, 22);	

	save_taxi_base();
	update_taxi_3d_text();
	return true;
}

stock create_taxi_company_other()
{

	actor_taxi_company_yandex = CreateActor(12, 428.4042,585.7468,12.0000,105.1629);
	ApplyActorAnimation(actor_taxi_company_yandex, "COP_AMBIENT", "coplook_loop", 4.1, 1, 1, 1, 0, 0);	

	actor_taxi_company_uber = CreateActor(12, 2444.9429,-1721.1563,21.8600,126.6897);
	ApplyActorAnimation(actor_taxi_company_uber, "COP_AMBIENT", "coplook_loop", 4.1, 1, 1, 1, 0, 0);	

	actor_taxi_company_city = CreateActor(12, 1755.1302,2460.6970,15.7025,67.3923);
	ApplyActorAnimation(actor_taxi_company_city, "COP_AMBIENT", "coplook_loop", 4.1, 1, 1, 1, 0, 0);	


  	CreateDynamic3DTextLabel(""cWH"Работа в «СитиМобил»\n "cORANGE"Информация",-1, \
  		1754.3031,2460.9456,15.7025, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
	CreateDynamicPickup(13710, 23, 1754.3031,2460.9456,15.7025, -1, -1, -1, 15.0);

  	CreateDynamic3DTextLabel(""cWH"Работа в «YandexGO»\n "cYELLOW"Информация",-1, \
  		427.5262,585.5109,12.0000, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
	CreateDynamicPickup(13710, 23, 427.5262,585.5109,12.0000, -1, -1, -1, 15.0);

  	CreateDynamic3DTextLabel(""cWH"Работа в «UBER»\n "cUBER"Информация",-1, \
  		2444.2749,-1721.6536,21.8600, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
	CreateDynamicPickup(13710, 23, 2444.2749,-1721.6536,21.8600, -1, -1, -1, 15.0);


	area_taxi_work_yandex = CreateDynamicSphere(427.5262,585.5109,12.0000, 1.0, -1, -1, -1);
	area_taxi_work_uber = CreateDynamicSphere(2444.2749,-1721.6536,21.8600, 1.0, -1, -1, -1);
	area_taxi_work_city = CreateDynamicSphere(1754.3031,2460.9456,15.7025, 1.0, -1, -1, -1);

	return true;
}

stock create_taxi_text_company()
{

	new
		owner[24];

	if(taxi_company[TAXI_COMPANY_YANDEX][taxi_company_owner_id] != -1)
	{
		GetPlayerNameByID(taxi_company[TAXI_COMPANY_YANDEX][taxi_company_owner_id], taxi_company[TAXI_COMPANY_YANDEX][taxi_company_owner_name]);
		format(owner, 24, taxi_company[TAXI_COMPANY_YANDEX][taxi_company_owner_name]);
	}
	else
	{
		format(owner, 24, "Отсутствует");	
	}

	format(String1024, sizeof(String1024), "\
		Компания "cYELLOW"«YandexGO»\n\
		"cWH"Владелец: "cYELLOW"%s\n\n\
		\t"cYELLOW"Остальная информация:\n\n\
		"cWH"Статус компании: %s\n\n\
		"cWH"Тариф Эконом: 1 км - "cGR"%d рублей\n\
		"cWH"Тариф Комфорт: 1 км - "cGR"%d рублей\n\
		"cWH"Тариф Бизнес: 1 км - "cGR"%d рублей\n\n\
		"cWH"Процент с личного авто: "cYELLOW"%d%%\n\
		"cWH"Процент с авто такси: "cYELLOW"%d%%",
		owner,
		(taxi_company[TAXI_COMPANY_YANDEX][taxi_company_closed]) ? (""cGR"Работает") : (""cLRED"Закрыта"),

		taxi_company[TAXI_COMPANY_YANDEX][taxi_company_price_econom],
		taxi_company[TAXI_COMPANY_YANDEX][taxi_company_price_comfort],
		taxi_company[TAXI_COMPANY_YANDEX][taxi_company_price_buisnes],

		taxi_company[TAXI_COMPANY_YANDEX][taxi_company_percent_1],
		taxi_company[TAXI_COMPANY_YANDEX][taxi_company_percent_2]);

	taxi_company[TAXI_COMPANY_YANDEX][taxi_company_pick_info] = CreateDynamic3DTextLabel(String1024, -1, taxi_company[TAXI_COMPANY_YANDEX][taxi_pos_x], taxi_company[TAXI_COMPANY_YANDEX][taxi_pos_y], taxi_company[TAXI_COMPANY_YANDEX][taxi_pos_z]+1.0, 20.0);

	if(taxi_company[TAXI_COMPANY_UBER][taxi_company_owner_id] != -1)
	{
		GetPlayerNameByID(taxi_company[TAXI_COMPANY_UBER][taxi_company_owner_id], taxi_company[TAXI_COMPANY_UBER][taxi_company_owner_name]);
		format(owner, 24, taxi_company[TAXI_COMPANY_UBER][taxi_company_owner_name]);
	}
	else
	{
		format(owner, 24, "Отсутствует");	
	}

	format(String1024, sizeof(String1024), "\
		Компания "cUBER"«UBER»\n\
		"cWH"Владелец: "cUBER"%s\n\n\
		\t"cUBER"Остальная информация:\n\n\
		"cWH"Статус компании: %s\n\n\
		"cWH"Тариф Эконом: 1 км - "cGR"%d рублей\n\
		"cWH"Тариф Комфорт: 1 км - "cGR"%d рублей\n\
		"cWH"Тариф Бизнес: 1 км - "cGR"%d рублей\n\n\
		"cWH"Процент с личного авто: "cUBER"%d%%\n\
		"cWH"Процент с авто такси: "cUBER"%d%%",
		owner,
		(taxi_company[TAXI_COMPANY_UBER][taxi_company_closed]) ? (""cGR"Работает") : (""cLRED"Закрыта"),

		taxi_company[TAXI_COMPANY_UBER][taxi_company_price_econom],
		taxi_company[TAXI_COMPANY_UBER][taxi_company_price_comfort],
		taxi_company[TAXI_COMPANY_UBER][taxi_company_price_buisnes],

		taxi_company[TAXI_COMPANY_UBER][taxi_company_percent_1],
		taxi_company[TAXI_COMPANY_UBER][taxi_company_percent_2]);

	taxi_company[TAXI_COMPANY_UBER][taxi_company_pick_info] = CreateDynamic3DTextLabel(String1024, -1, taxi_company[TAXI_COMPANY_UBER][taxi_pos_x], taxi_company[TAXI_COMPANY_UBER][taxi_pos_y], taxi_company[TAXI_COMPANY_UBER][taxi_pos_z]+1.0, 20.0);
	

	if(taxi_company[TAXI_COMPANY_CITY][taxi_company_owner_id] != -1)
	{
		GetPlayerNameByID(taxi_company[TAXI_COMPANY_CITY][taxi_company_owner_id], taxi_company[TAXI_COMPANY_CITY][taxi_company_owner_name]);
		format(owner, 24, taxi_company[TAXI_COMPANY_CITY][taxi_company_owner_name]);
	}
	else
	{
		format(owner, 24, "Отсутствует");	
	}


	format(String1024, sizeof(String1024), "\
		Компания "cORANGE"«СитиМобил»\n\
		"cWH"Владелец: "cORANGE"%s\n\n\
		\t"cORANGE"Остальная информация:\n\n\
		"cWH"Статус компании: %s\n\n\
		"cWH"Тариф Эконом: 1 км - "cGR"%d рублей\n\
		"cWH"Тариф Комфорт: 1 км - "cGR"%d рублей\n\
		"cWH"Тариф Бизнес: 1 км - "cGR"%d рублей\n\n\
		"cWH"Процент с личного авто: "cORANGE"%d%%\n\
		"cWH"Процент с авто такси: "cORANGE"%d%%",
		owner,
		(taxi_company[TAXI_COMPANY_CITY][taxi_company_closed]) ? (""cGR"Работает") : (""cLRED"Закрыта"),

		taxi_company[TAXI_COMPANY_CITY][taxi_company_price_econom],
		taxi_company[TAXI_COMPANY_CITY][taxi_company_price_comfort],
		taxi_company[TAXI_COMPANY_CITY][taxi_company_price_buisnes],

		taxi_company[TAXI_COMPANY_CITY][taxi_company_percent_1],
		taxi_company[TAXI_COMPANY_CITY][taxi_company_percent_2]);


	taxi_company[TAXI_COMPANY_CITY][taxi_company_pick_info] = CreateDynamic3DTextLabel(String1024, -1, taxi_company[TAXI_COMPANY_CITY][taxi_pos_x], taxi_company[TAXI_COMPANY_CITY][taxi_pos_y], taxi_company[TAXI_COMPANY_CITY][taxi_pos_z]+1.0, 20.0);
	

	return true;
}



stock update_taxi_3d_text()
{

	new
		owner[24];

	if(taxi_company[TAXI_COMPANY_YANDEX][taxi_company_owner_id] != -1)
	{
		GetPlayerNameByID(taxi_company[TAXI_COMPANY_YANDEX][taxi_company_owner_id], taxi_company[TAXI_COMPANY_YANDEX][taxi_company_owner_name]);
		format(owner, 24, taxi_company[TAXI_COMPANY_YANDEX][taxi_company_owner_name]);
	}
	else
	{
		format(owner, 24, "Отсутствует");	
	}

	format(String1024, sizeof(String1024), "\
		Компания "cYELLOW"«YandexGO»\n\
		"cWH"Владелец: "cYELLOW"%s\n\n\
		\t"cYELLOW"Остальная информация:\n\n\
		"cWH"Статус компании: %s\n\n\
		"cWH"Тариф Эконом: 1 км - "cGR"%d рублей\n\
		"cWH"Тариф Комфорт: 1 км - "cGR"%d рублей\n\
		"cWH"Тариф Бизнес: 1 км - "cGR"%d рублей\n\n\
		"cWH"Процент с личного авто: "cYELLOW"%d%%\n\
		"cWH"Процент с авто такси: "cYELLOW"%d%%",
		owner,
		(taxi_company[TAXI_COMPANY_YANDEX][taxi_company_closed]) ? (""cGR"Работает") : (""cLRED"Закрыта"),

		taxi_company[TAXI_COMPANY_YANDEX][taxi_company_price_econom],
		taxi_company[TAXI_COMPANY_YANDEX][taxi_company_price_comfort],
		taxi_company[TAXI_COMPANY_YANDEX][taxi_company_price_buisnes],

		taxi_company[TAXI_COMPANY_YANDEX][taxi_company_percent_1],
		taxi_company[TAXI_COMPANY_YANDEX][taxi_company_percent_2]);

	UpdateDynamic3DTextLabelText(taxi_company[TAXI_COMPANY_YANDEX][taxi_company_pick_info], -1, String1024);	

	if(taxi_company[TAXI_COMPANY_YANDEX][taxi_status_sell] == 3)
	{
		format(String1024, sizeof(String1024), "\
			Компания "cYELLOW"«YandexGO» (ОПЕЧАТАНА)\n\
			"cWH"Владелец: "cYELLOW"%s\n\n\
			\t"cYELLOW"Остальная информация:\n\n\
			"cWH"Статус компании: %s\n\n\
			"cWH"Тариф Эконом: 1 км - "cGR"%d рублей\n\
			"cWH"Тариф Комфорт: 1 км - "cGR"%d рублей\n\
			"cWH"Тариф Бизнес: 1 км - "cGR"%d рублей\n\n\
			"cWH"Процент с личного авто: "cYELLOW"%d%%\n\
			"cWH"Процент с авто такси: "cYELLOW"%d%%",
			owner,
			(taxi_company[TAXI_COMPANY_YANDEX][taxi_company_closed]) ? (""cGR"Работает") : (""cLRED"Закрыта"),

			taxi_company[TAXI_COMPANY_YANDEX][taxi_company_price_econom],
			taxi_company[TAXI_COMPANY_YANDEX][taxi_company_price_comfort],
			taxi_company[TAXI_COMPANY_YANDEX][taxi_company_price_buisnes],

			taxi_company[TAXI_COMPANY_YANDEX][taxi_company_percent_1],
			taxi_company[TAXI_COMPANY_YANDEX][taxi_company_percent_2]);

		UpdateDynamic3DTextLabelText(taxi_company[TAXI_COMPANY_YANDEX][taxi_company_pick_info], -1, String1024);	

	}


	if(taxi_company[TAXI_COMPANY_UBER][taxi_company_owner_id] != -1)
	{
		GetPlayerNameByID(taxi_company[TAXI_COMPANY_UBER][taxi_company_owner_id], taxi_company[TAXI_COMPANY_UBER][taxi_company_owner_name]);
		format(owner, 24, taxi_company[TAXI_COMPANY_UBER][taxi_company_owner_name]);
	}
	else
	{
		format(owner, 24, "Отсутствует");	
	}

	format(String1024, sizeof(String1024), "\
		Компания "cUBER"«UBER»\n\
		"cWH"Владелец: "cUBER"%s\n\n\
		\t"cUBER"Остальная информация:\n\n\
		"cWH"Статус компании: %s\n\n\
		"cWH"Тариф Эконом: 1 км - "cGR"%d рублей\n\
		"cWH"Тариф Комфорт: 1 км - "cGR"%d рублей\n\
		"cWH"Тариф Бизнес: 1 км - "cGR"%d рублей\n\n\
		"cWH"Процент с личного авто: "cUBER"%d%%\n\
		"cWH"Процент с авто такси: "cUBER"%d%%",
		owner,
		(taxi_company[TAXI_COMPANY_UBER][taxi_company_closed]) ? (""cGR"Работает") : (""cLRED"Закрыта"),

		taxi_company[TAXI_COMPANY_UBER][taxi_company_price_econom],
		taxi_company[TAXI_COMPANY_UBER][taxi_company_price_comfort],
		taxi_company[TAXI_COMPANY_UBER][taxi_company_price_buisnes],

		taxi_company[TAXI_COMPANY_UBER][taxi_company_percent_1],
		taxi_company[TAXI_COMPANY_UBER][taxi_company_percent_2]);

	UpdateDynamic3DTextLabelText(taxi_company[TAXI_COMPANY_UBER][taxi_company_pick_info], -1, String1024);	

	if(taxi_company[TAXI_COMPANY_UBER][taxi_status_sell] == 3)
	{
		format(String1024, sizeof(String1024), "\
			Компания "cUBER"«UBER» (ОПЕЧАТАНА)\n\
			"cWH"Владелец: "cUBER"%s\n\n\
			\t"cUBER"Остальная информация:\n\n\
			"cWH"Статус компании: %s\n\n\
			"cWH"Тариф Эконом: 1 км - "cGR"%d рублей\n\
			"cWH"Тариф Комфорт: 1 км - "cGR"%d рублей\n\
			"cWH"Тариф Бизнес: 1 км - "cGR"%d рублей\n\n\
			"cWH"Процент с личного авто: "cUBER"%d%%\n\
			"cWH"Процент с авто такси: "cUBER"%d%%",
			owner,
			(taxi_company[TAXI_COMPANY_UBER][taxi_company_closed]) ? (""cGR"Работает") : (""cLRED"Закрыта"),

			taxi_company[TAXI_COMPANY_UBER][taxi_company_price_econom],
			taxi_company[TAXI_COMPANY_UBER][taxi_company_price_comfort],
			taxi_company[TAXI_COMPANY_UBER][taxi_company_price_buisnes],

			taxi_company[TAXI_COMPANY_UBER][taxi_company_percent_1],
			taxi_company[TAXI_COMPANY_UBER][taxi_company_percent_2]);

		UpdateDynamic3DTextLabelText(taxi_company[TAXI_COMPANY_UBER][taxi_company_pick_info], -1, String1024);	
	}

	if(taxi_company[TAXI_COMPANY_CITY][taxi_company_owner_id] != -1)
	{
		GetPlayerNameByID(taxi_company[TAXI_COMPANY_CITY][taxi_company_owner_id], taxi_company[TAXI_COMPANY_CITY][taxi_company_owner_name]);
		format(owner, 24, taxi_company[TAXI_COMPANY_CITY][taxi_company_owner_name]);
	}
	else
	{
		format(owner, 24, "Отсутствует");	
	}


	format(String1024, sizeof(String1024), "\
		Компания "cORANGE"«СитиМобил»\n\
		"cWH"Владелец: "cORANGE"%s\n\n\
		\t"cORANGE"Остальная информация:\n\n\
		"cWH"Статус компании: %s\n\n\
		"cWH"Тариф Эконом: 1 км - "cGR"%d рублей\n\
		"cWH"Тариф Комфорт: 1 км - "cGR"%d рублей\n\
		"cWH"Тариф Бизнес: 1 км - "cGR"%d рублей\n\n\
		"cWH"Процент с личного авто: "cORANGE"%d%%\n\
		"cWH"Процент с авто такси: "cORANGE"%d%%",
		owner,
		(taxi_company[TAXI_COMPANY_CITY][taxi_company_closed]) ? (""cGR"Работает") : (""cLRED"Закрыта"),

		taxi_company[TAXI_COMPANY_CITY][taxi_company_price_econom],
		taxi_company[TAXI_COMPANY_CITY][taxi_company_price_comfort],
		taxi_company[TAXI_COMPANY_CITY][taxi_company_price_buisnes],

		taxi_company[TAXI_COMPANY_CITY][taxi_company_percent_1],
		taxi_company[TAXI_COMPANY_CITY][taxi_company_percent_2]);



	UpdateDynamic3DTextLabelText(taxi_company[TAXI_COMPANY_CITY][taxi_company_pick_info], -1, String1024);


	if(taxi_company[TAXI_COMPANY_UBER][taxi_status_sell] == 3)
	{
		format(String1024, sizeof(String1024), "\
			Компания "cORANGE"«СитиМобил» (ОПЕЧАТАНА)\n\
			"cWH"Владелец: "cORANGE"%s\n\n\
			\t"cORANGE"Остальная информация:\n\n\
			"cWH"Статус компании: %s\n\n\
			"cWH"Тариф Эконом: 1 км - "cGR"%d рублей\n\
			"cWH"Тариф Комфорт: 1 км - "cGR"%d рублей\n\
			"cWH"Тариф Бизнес: 1 км - "cGR"%d рублей\n\n\
			"cWH"Процент с личного авто: "cORANGE"%d%%\n\
			"cWH"Процент с авто такси: "cORANGE"%d%%",
			owner,
			(taxi_company[TAXI_COMPANY_CITY][taxi_company_closed]) ? (""cGR"Работает") : (""cLRED"Закрыта"),

			taxi_company[TAXI_COMPANY_CITY][taxi_company_price_econom],
			taxi_company[TAXI_COMPANY_CITY][taxi_company_price_comfort],
			taxi_company[TAXI_COMPANY_CITY][taxi_company_price_buisnes],

			taxi_company[TAXI_COMPANY_CITY][taxi_company_percent_1],
			taxi_company[TAXI_COMPANY_CITY][taxi_company_percent_2]);



		UpdateDynamic3DTextLabelText(taxi_company[TAXI_COMPANY_CITY][taxi_company_pick_info], -1, String1024);

	}


	return true;
}



stock show_taxi_station_menu(playerid, type)
{
	if(taxi_company[type][taxi_company_owner_id] == -1)
		return show_taxi_station_buy(playerid, type);


	return show_taxi_menu(playerid, type);
}

stock show_taxi_station_buy(playerid, type)
{
	new
		owner[24];

	if(taxi_company[type][taxi_company_owner_id] != -1)
	{
		GetPlayerNameByID(taxi_company[type][taxi_company_owner_id], taxi_company[type][taxi_company_owner_name]);
		format(owner, 24, taxi_company[type][taxi_company_owner_name]);
	}
	else
	{
		format(owner, 24, "Отсутствует");	
	}

	SetPVarIntNew(playerid, "id_buy_taxi_base", type);

	if(type == TAXI_COMPANY_YANDEX)
	{
		format(String512, sizeof(String512), "\
		"cWH"Название: \t\t\t\t "cYELLOW"YandexGO\n\
		"cWH"Владелец: \t\t\t\t "cYELLOW"%s\n\
		"cWH"Статус: \t\t\t\t\t %s\n\
		"cWH"Цена: \t\t\t\t\t "cGR"%d руб\n\n\
		"cWH"Вы действительно хотите приобрести таксопарк?",
		owner,
		(taxi_company[type][taxi_company_closed]) ? (""cGR"Работает") : (""cLRED"Закрыта"),
		taxi_company[type][taxi_company_price]);

		SPD(playerid, DIALOG_BUY_TAXI_COMPANY, DIALOG_STYLE_MSGBOX, !""cYELLOW"Покупка таксопарка", String512, !"Купить", !"Закрыть");
	
	}
	else if(type == TAXI_COMPANY_UBER)
	{
		format(String512, sizeof(String512), "\
		"cWH"Название: \t\t\t\t "cUBER"UBER\n\
		"cWH"Владелец: \t\t\t\t "cUBER"%s\n\
		"cWH"Статус: \t\t\t\t\t %s\n\
		"cWH"Цена: \t\t\t\t\t "cGR"%d руб\n\n\
		"cWH"Вы действительно хотите приобрести таксопарк?",
		owner,
		(taxi_company[type][taxi_company_closed]) ? (""cGR"Работает") : (""cLRED"Закрыта"),
		taxi_company[type][taxi_company_price]);

		SPD(playerid, DIALOG_BUY_TAXI_COMPANY, DIALOG_STYLE_MSGBOX, !""cUBER"Покупка таксопарка", String512, !"Купить", !"Закрыть");
	
	}
	else if(type == TAXI_COMPANY_CITY)
	{
		format(String512, sizeof(String512), "\
		"cWH"Название: \t\t\t\t "cORANGE"UBER\n\
		"cWH"Владелец: \t\t\t\t "cORANGE"%s\n\
		"cWH"Статус: \t\t\t\t\t %s\n\
		"cWH"Цена: \t\t\t\t\t "cGR"%d руб\n\n\
		"cWH"Вы действительно хотите приобрести таксопарк?",
		owner,
		(taxi_company[type][taxi_company_closed]) ? (""cGR"Работает") : (""cLRED"Закрыта"),
		taxi_company[type][taxi_company_price]);

		SPD(playerid, DIALOG_BUY_TAXI_COMPANY, DIALOG_STYLE_MSGBOX, !""cORANGE"Покупка таксопарка", String512, !"Купить", !"Закрыть");
	
	}

	return true;
}

stock show_taxi_menu(playerid, type)
{

	if(taxi_company[type][taxi_company_owner_id] == pData[playerid][pMysqlID])
		return show_taxi_menu_change(playerid, type);

	if(pData[playerid][pTaxiOwnerLowID] == type)
		return show_taxi_menu_zam(playerid, type);

	return true;
}

stock show_taxi_menu_zam(playerid, type)
{
	if(pData[playerid][pTaxiOwnerLowID] != type)
		return true;


    format(String1024, sizeof(String1024), "\
        "cGREY"Тип\t"cGREY"Действие\n\
        "cBLUE"1. "cWH"Сотрудники\t"cGR"Просмотреть\n\
        "cBLUE"2. "cWH"Статистика\t"cGR"Просмотреть");
    SPD(playerid, DIALOG_CHANGE_TAXI, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление такси", String1024, !"Выбрать", !"Закрыть"); 

	return true;
}

stock show_taxi_menu_change(playerid, type)
{

	if(pData[playerid][pTaxiOwnerID] != type)
		return true;

   	format(String1024, sizeof(String1024), "\
   	"cGREY"Тип\t"cGREY"Действие\n\
   	"cBLUE"1. "cWH"Управление кассой\t"cGR"Открыть\n\
   	"cBLUE"2. "cWH"Изменение процента на личном авто\t"cGR"Изменить\n\
   	"cBLUE"3. "cWH"Изменение процента на авто такси\t"cGR"Изменить\n\
   	"cBLUE"4. "cWH"Изменение стоимости тарифа Эконом\t"cGR"Изменить\n\
   	"cBLUE"5. "cWH"Изменение стоимости тарифа Комфорт\t"cGR"Изменить\n\
   	"cBLUE"6. "cWH"Изменение стоимости тарифа Бизнес\t"cGR"Изменить\n\
   	"cBLUE"7. "cWH"Сотрудники\t"cGR"Просмотреть\n\
   	"cBLUE"8. "cWH"Статистика\t"cGR"Просмотреть\n\
   	"cBLUE"9. "cWH"Продать такси\t"cGR"Продать");
   	return SPD(playerid, DIALOG_CHANGE_TAXI, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление такси", String1024, !"Выбрать", !"Закрыть"); 
}

stock buy_taxi_station(playerid, type)
{
	if(pData[playerid][pBusiness] != -1)
		return SendErr(playerid, "Вы не можете купить бизнес, так как уже владеете бизнесом!");
	if(pData[playerid][pHotelOwner] != -1)
		return SendErr(playerid, "Вы не можете купить бизнес, так как уже владеете отелем!");
	if(pData[playerid][pTaxiOwnerID] != -1)
		return SendErr(playerid,  "Вы не можете купить бизнес, так как уже владеете СТО!");
	if(pData[playerid][pFillStation] != -1)
		return SendErr(playerid,  "Вы не можете купить бизнес, так как уже владеете АЗС!");
	if(pData[playerid][pTaxiOwnerID] != -1)
		return SendErr(playerid,  "Вы не можете купить бизнес, так как уже владеете Таксопарком!");
	if(pData[playerid][pTruckerOwnerID] != -1)
		return SendErr(playerid,  "Вы не можете купить бизнес, так как уже владеете Транспортной Компанией!");
	if(pData[playerid][pCasinoOwner] != -1)
		return SendErr(playerid, "Вы не можете купить бизнес, так как уже владеете казино!");


	new 
		id_company_taxi = GetPVarIntNew(playerid, "id_buy_taxi_base");

	if(pData[playerid][pMoney] <= taxi_company[id_company_taxi][taxi_company_price]) 
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
		return SendErr(playerid, "У вас недостаточно денег");
	}

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_buy_taxi", 4000);

	taxi_company[id_company_taxi][taxi_company_owner_id] = pData[playerid][pMysqlID];
	taxi_company[id_company_taxi][taxi_company_days] = 3;
	taxi_company[id_company_taxi][taxi_company_bank] = 0;

	pData[playerid][pTaxi] = id_company_taxi;

	new 
		mech_owner_str[32];

	format(taxi_company[id_company_taxi][taxi_company_owner_name], 32, pData[playerid][pNickname]);
	format(mech_owner_str, 32, pData[playerid][pNickname]);

	format(String256,sizeof(String256),"UPDATE `taxi` SET `taxi_owner_id` = '%d' WHERE `taxi_id` = '%d'" , pData[playerid][pMysqlID], id_company_taxi);
	sql_queryEx(zConn, String256, QUERY_THREADED);	

    pData[playerid][pMoney] -= taxi_company[id_company_taxi][taxi_company_price];
    ResetPlayerMoney(playerid);
	GivePlayerMoney(playerid,pData[playerid][pMoney]);

	pData[playerid][pTaxiOwnerID] = type;
	pData[playerid][pTaxiRank] = 3;


	format(String1024,sizeof(String1024),"INSERT INTO `taxi_personal`(`id`,`user_id`,`user_rank`) VALUES ('%d','%d','%d')", id_company_taxi, 
	pData[playerid][pMysqlID], 3);
	sql_queryEx(zConn, String1024, QUERY_THREADED);

	UpdatePlayerData(playerid,"pTaxiRank",pData[playerid][pTaxiRank]);	
	UpdatePlayerData(playerid,"pTaxi",pData[playerid][pTaxi]);	
	UpdatePlayerData(playerid,"pTaxiOwnerID",pData[playerid][pTaxiOwnerID]);	

	update_taxi_3d_text();

	if(type == TAXI_COMPANY_YANDEX)
	{
		format(String256, sizeof(String256), "\
			"cWH"Поздравляем Вас с приобретением Таксопарка!\n\n\
			Вы купили Такспопарк YandexGO (№%d)\n\n\
			"cWH"Таксопарк автоматически оплачен на %d дня\n\
			Советуем Вам как можно быстрее посетить банк и продлить оплату",
			taxi_company[id_company_taxi][taxi_company_id]+1,
			taxi_company[id_company_taxi][taxi_company_days]);
		SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка YandexGO", String256, !"Понял", !"");
	}
	else if(type == TAXI_COMPANY_UBER)
	{
		format(String256, sizeof(String256), "\
			"cWH"Поздравляем Вас с приобретением Таксопарка!\n\n\
			Вы купили Такспопарк UBER (№%d)\n\n\
			"cWH"Таксопарк автоматически оплачен на %d дня\n\
			Советуем Вам как можно быстрее посетить банк и продлить оплату",
			taxi_company[id_company_taxi][taxi_company_id]+1,
			taxi_company[id_company_taxi][taxi_company_days]);
		SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cUBER"Покупка UBER", String256, !"Понял", !"");		
	}
	else if(type == TAXI_COMPANY_CITY)
	{
		format(String256, sizeof(String256), "\
			"cWH"Поздравляем Вас с приобретением Таксопарка!\n\n\
			Вы купили Такспопарк СитиМобил (№%d)\n\n\
			"cWH"Таксопарк автоматически оплачен на %d дня\n\
			Советуем Вам как можно быстрее посетить банк и продлить оплату",
			taxi_company[id_company_taxi][taxi_company_id]+1,
			taxi_company[id_company_taxi][taxi_company_days]);
		SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cORANGE"Покупка СитиМобил", String256, !"Понял", !"");		
	}
	return true;
}


stock dialog_all_taxi(playerid, dialogid, response, listitem, inputtext[])
{

	switch(dialogid)
	{
		case DIALOG_ACCEPT_SELL_TAXI_GOS:
		{
			if(!response)
				return true;

			sell_taxi_gos_final(playerid);
		}
		case DIALOG_BUY_TAXI_COMPANY: 
		{
			if(!response)
			{
				DeletePVarNew(playerid, "id_buy_taxi_base");
				return true;
			}

			if(pData[playerid][pBusiness] != -1)
				return SendErr(playerid, "Вы не можете купить бизнес, так как уже владеете бизнесом!");

			if(pData[playerid][pHotelOwner] != -1)
				return SendErr(playerid, "Вы не можете купить бизнес, так как уже владеете отелем!");

			if(pData[playerid][pTaxiOwnerID] != -1)
				return SendErr(playerid,  "Вы не можете купить бизнес, так как уже владеете такси!");
			
			buy_taxi_station(playerid, GetPVarIntNew(playerid, "id_buy_taxi_base"));
		}

		case DIALOG_CHANGE_TAXI: 
		{
			if(!response)
				return true;

			switch(listitem) 
			{
				case 0: return change_bank_taxi(playerid);
				case 1: return change_percent_taxi_1(playerid);
				case 2: return change_percent_taxi_2(playerid);
				case 3: return change_tarif_taxi_econom(playerid);
				case 4: return change_tarif_taxi_comfort(playerid);
				case 5: return change_tarif_taxi_buisnes(playerid);
				case 6: return change_personal_taxi(playerid);	
				case 7: return change_statistic_taxi(playerid);
				case 8: return sell_taxi_company_gos(playerid);
			}
		}
		case DIALOG_CHANGE_TAXI_BANK:
		{
			new 
				id_taxi;

			if(pData[playerid][pTaxiOwnerID] != -1)
			{
				id_taxi = pData[playerid][pTaxiOwnerID];		
			}
			else
			{
				id_taxi = pData[playerid][pTaxiOwnerLowID];
			}

			if(!response) 
				return show_taxi_menu_change(playerid, id_taxi);	
				
			switch(listitem) 
			{
				case 0: return taxi_bank_operation(playerid, 1);
				case 1: return taxi_bank_operation(playerid, 2);
			}

		}
		case DIALOG_TAXI_INPUT_MONEY:
		{
			if(!response) 
				return change_bank_taxi(playerid);

			if(!IsNumeric(inputtext)) 
				return SendErr(playerid,"Вы указали неверное количество денег");


			new 
				id_taxi;

			if(pData[playerid][pTaxiOwnerID] != -1)
			{
				id_taxi = pData[playerid][pTaxiOwnerID];		
			}
			else
			{
				id_taxi = pData[playerid][pTaxiOwnerLowID];
			}

			new 
				count_money = strval(inputtext);

			if(count_money < 1)
			{
				SendErr(playerid,"Вы указали неверное количество денег!");
				return change_bank_taxi(playerid);
			}


			if(taxi_company[id_taxi][taxi_company_bank] < count_money)
			{
				change_bank_taxi(playerid);
				return SendErr(playerid,"Недостаточно денег в кассе такси!");
			}

			taxi_company[id_taxi][taxi_company_bank] -= count_money;

		 	format(String144, sizeof(String144), "Снятие с кассы такси №%d", id_taxi);
			give_money(playerid, count_money, String144);

			SFCM(playerid,COLOR_BLUE,"• {FFC800}[Подсказка] "cWH"Вы сняли с кассы такси - %d рублей", count_money);	

		}
		case DIALOG_TAXI_PUT_MONEY:
		{
			if(!response) 
				return change_bank_taxi(playerid);

			if(!IsNumeric(inputtext)) 
				return SendErr(playerid,"Вы указали неверное количество денег");

			new 
				id_taxi;

			if(pData[playerid][pTaxiOwnerID] != -1)
			{
				id_taxi = pData[playerid][pTaxiOwnerID];		
			}
			else
			{
				id_taxi = pData[playerid][pTaxiOwnerLowID];
			}

			new 
				count_money = strval(inputtext);

			if(count_money < 1)
			{
				SendErr(playerid,"Вы указали неверное количество денег!");
				return change_bank_taxi(playerid);
			}


			if(pData[playerid][pMoney] < count_money)
			{
				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
				change_bank_taxi(playerid);
				return SendErr(playerid,"Недостаточно денег, чтобы положить в кассу!");
			}

			taxi_company[id_taxi][taxi_company_bank] += count_money;	

		 	format(String144, sizeof(String144), "Пополнение кассы такси №%d", id_taxi);
			give_money(playerid, -count_money, String144);

			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы пополнили кассу такси на %d рублей", count_money);		

		}	

		case DIALOG_CHANGE_TAXI_PERCENT_1:
		{
			new 
				id_taxi;

			if(pData[playerid][pTaxiOwnerID] != -1)
			{
				id_taxi = pData[playerid][pTaxiOwnerID];		
			}
			else
			{
				id_taxi = pData[playerid][pTaxiOwnerLowID];
			}

			if(!response) 
				return show_taxi_menu_change(playerid, id_taxi);	
			
			
			if(!IsNumeric(inputtext)) 
				return SendErr(playerid,"Вы указали неверный процент!");


			new 
				count_money = strval(inputtext);	

			if(count_money < 1 || count_money > 50)
			{
			    SendErr(playerid,"От 1 до 50 процентов!");
				return show_taxi_menu_change(playerid, id_taxi);	
			}	

			taxi_company[id_taxi][taxi_company_percent_1] = count_money;		

			SendSucc(playerid, "Процент взымаемый с таксиста на личном авто обновлен!");

			SFCM(playerid,0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Новый процент - "cGR"%d%%"cWH"", count_money);	

			format(String144, sizeof(String144), "[TAXI] Владелец %s изменил процент взымаемый с личного авто на %d%%!", pData[playerid][pNickname], count_money);
			send_taxi_job(id_taxi, COLOR_GREY, String144);

			show_taxi_menu_change(playerid, id_taxi);	
			update_taxi_3d_text();

		}

		case DIALOG_TAXI_PERS:
		{

			new 
				id_taxi;

			if(pData[playerid][pTaxiOwnerID] != -1)
			{
				id_taxi = pData[playerid][pTaxiOwnerID];		
			}
			else
			{
				id_taxi = pData[playerid][pTaxiOwnerLowID];
			}

			if(!response) 
				return show_taxi_menu_change(playerid, id_taxi);	

			if(listitem == 20) 
			{
				return change_personal_taxi(playerid, GetPVarIntNew(playerid, "check_page_panel_taxi")+1);
			}
			else if(listitem == 21 || GetPVarIntNew(playerid, "button_back_personal_menu") == listitem && listitem != 0) 
			{
				return change_personal_taxi(playerid, GetPVarIntNew(playerid, "check_page_panel_taxi")-1);
			}


			new 
				id = dialog_listitem_values[playerid][listitem];


			return change_rank_personal_taxi(playerid, id);			
		}
		case DIALOG_TAXI_PERS_2:
		{

			new 
				id_taxi;

			if(pData[playerid][pTaxiOwnerID] != -1)
			{
				id_taxi = pData[playerid][pTaxiOwnerID];		
			}
			else
			{
				id_taxi = pData[playerid][pTaxiOwnerLowID];
			}

			if(!response) 
				return show_taxi_menu_change(playerid, id_taxi);	

			new 
				id = GetPVarIntNew(playerid, "uninvite_taxi_id");

				
			switch(listitem) 
			{
				case 2: return give_rank_truck_taxi(playerid, id);
				case 3: return give_rank_manage_taxi(playerid, id);
				case 4: return uninvite_panel_taxi_t(playerid, id);
			}			
		}
		case DIALOG_TAXI_PERSONAL_CLOSE:
		{
			new 
				id_taxi;

			if(pData[playerid][pTaxiOwnerID] != -1)
			{
				id_taxi = pData[playerid][pTaxiOwnerID];		
			}
			else
			{
				id_taxi = pData[playerid][pTaxiOwnerLowID];
			}

			if(!response) 
				return show_taxi_menu_change(playerid, id_taxi);

			show_taxi_menu_change(playerid, id_taxi);
		}
		case DIALOG_SELECT_MENU_YANDEX: 
		{
			if(!response)
				return true;

			switch(listitem) 
			{
				case 0: return show_info_work_taxi(playerid, TAXI_COMPANY_YANDEX);
				case 1: return invite_taxi_station(playerid, TAXI_COMPANY_YANDEX);
			}
		}
		case DIALOG_SELECT_MENU_CITY: 
		{
			if(!response)
				return true;

			switch(listitem) 
			{
				case 0: return show_info_work_taxi(playerid, TAXI_COMPANY_CITY);
				case 1: return invite_taxi_station(playerid, TAXI_COMPANY_CITY);
			}
		}
		case DIALOG_SELECT_MENU_UBER: 
		{
			if(!response)
				return true;

			switch(listitem) 
			{
				case 0: return show_info_work_taxi(playerid, TAXI_COMPANY_UBER);
				case 1: return invite_taxi_station(playerid, TAXI_COMPANY_UBER);
			}
		}
		case DIALOG_SELECT_YANDEX_WORK: 
		{
			if(!response)
				return true;

			switch(listitem) 
			{
				case 0: return show_type_work_taxi(playerid, TAXI_COMPANY_YANDEX);
				case 1: return taxi_job_stats(playerid);
				case 2: return leave_taxi_company(playerid);
			}

		}
		case DIALOG_SELECT_CITY_WORK: 
		{
			if(!response)
				return true;

			switch(listitem) 
			{
				case 0: return show_type_work_taxi(playerid, TAXI_COMPANY_CITY);
				case 1: return taxi_job_stats(playerid);
				case 2: return leave_taxi_company(playerid);
			}

		}
		case DIALOG_SELECT_UBER_WORK: 
		{
			if(!response)
				return true;

			switch(listitem) 
			{
				case 0: return show_type_work_taxi(playerid, TAXI_COMPANY_UBER);
				case 1: return taxi_job_stats(playerid);
				case 2: return leave_taxi_company(playerid);
			}

		}
		case DIALOG_SELECT_YANDEX_ST_WORK: 
		{
			if(!response)
				return show_info_taxi_work(playerid, TAXI_COMPANY_YANDEX);

			switch(listitem) 
			{
				case 0: return start_work_taxi_car_taxi(playerid, TAXI_COMPANY_YANDEX);
			}			
		}
		case DIALOG_SELECT_CITY_ST_WORK: 
		{
			if(!response)
				return show_info_taxi_work(playerid, TAXI_COMPANY_CITY);

			switch(listitem) 
			{
				case 0: return start_work_taxi_car_taxi(playerid, TAXI_COMPANY_CITY);
			}

		}
		case DIALOG_SELECT_UBER_ST_WORK: 
		{
			if(!response)
				return show_info_taxi_work(playerid, TAXI_COMPANY_UBER);

			switch(listitem) 
			{
				case 0: return start_work_taxi_car_taxi(playerid, TAXI_COMPANY_UBER);
			}
		}
		case DIALOG_SELECT_YANDEX_TARIF_WORK:
		{
			if(!response)
				return show_type_work_taxi(playerid, TAXI_COMPANY_YANDEX);

			switch(listitem) 
			{
				case 0: return start_work_taxi_car_final(playerid, TAXI_COMPANY_YANDEX, TARIF_TAXI_ECONOM);
				case 1: return start_work_taxi_car_final(playerid, TAXI_COMPANY_YANDEX, TARIF_TAXI_COMFORT);
				case 2: return start_work_taxi_car_final(playerid, TAXI_COMPANY_YANDEX, TARIF_TAXI_BUISNES);
			}			
		}
		case DIALOG_SELECT_CITY_TARIF_WORK:
		{
			if(!response)
				return show_type_work_taxi(playerid, TAXI_COMPANY_CITY);

			switch(listitem) 
			{
				case 0: return start_work_taxi_car_final(playerid, TAXI_COMPANY_CITY, TARIF_TAXI_ECONOM);
				case 1: return start_work_taxi_car_final(playerid, TAXI_COMPANY_CITY, TARIF_TAXI_COMFORT);
				case 2: return start_work_taxi_car_final(playerid, TAXI_COMPANY_CITY, TARIF_TAXI_BUISNES);
			}
		}
		case DIALOG_SELECT_UBER_TARIF_WORK:
		{
			if(!response)
				return show_type_work_taxi(playerid, TAXI_COMPANY_UBER);

			switch(listitem) 
			{
				case 0: return start_work_taxi_car_final(playerid, TAXI_COMPANY_UBER, TARIF_TAXI_ECONOM);
				case 1: return start_work_taxi_car_final(playerid, TAXI_COMPANY_UBER, TARIF_TAXI_COMFORT);
				case 2: return start_work_taxi_car_final(playerid, TAXI_COMPANY_UBER, TARIF_TAXI_BUISNES);
			}
		}

		case DIALOG_CHANGE_TAXI_PERCENT_2:
		{
			if(!response)
				return show_taxi_menu(playerid, pData[playerid][pTaxiOwnerID]);

			new 
				id_taxi;

			if(pData[playerid][pTaxiOwnerID] != -1)
			{
				id_taxi = pData[playerid][pTaxiOwnerID];		
			}

			if(!response) 
				return show_taxi_menu(playerid, id_taxi);	
			
			
			if(!IsNumeric(inputtext)) 
				return SendErr(playerid,"Вы указали неверный процент!");


			new 
				count_money = strval(inputtext);	

			if(count_money < 1 || count_money > 50)
			{
			    SendErr(playerid,"От 1 до 50 процентов!");
				return change_percent_taxi_2(playerid);
			}	

			taxi_company[id_taxi][taxi_company_percent_2] = count_money;		

			SendSucc(playerid, "Процент взымаемый с таксистов на авто таксопарка обновлен!");

			SFCM(playerid,0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Новый процент - "cGR"%d%%"cWH"", count_money);	

			format(String144, sizeof(String144), "[TAXI] Владелец %s изменил процент взымаемый с авто таксопарка на %d%%!", pData[playerid][pNickname], count_money);
			send_taxi_job(id_taxi, COLOR_GREY, String144);

			show_taxi_menu(playerid, id_taxi);
			update_taxi_3d_text();

		}
		case DIALOG_CHANGE_TAXI_TARIF_1:
		{
			if(!response)
				return show_taxi_menu(playerid, pData[playerid][pTaxiOwnerID]);

			new 
				id_taxi;

			if(pData[playerid][pTaxiOwnerID] != -1)
			{
				id_taxi = pData[playerid][pTaxiOwnerID];		
			}
			
			if(!response) 
				return show_taxi_menu(playerid, id_taxi);	
			
			
			if(!IsNumeric(inputtext)) 
				return SendErr(playerid,"Вы указали неверный процент!");


			new 
				count_money = strval(inputtext);	

			if(count_money < 50 || count_money > 100)
			{
			    SendErr(playerid,"От 50 до 100 рублей!");
				return change_tarif_taxi_econom(playerid);
			}	

			taxi_company[id_taxi][taxi_company_price_econom] = count_money;		

			SendSucc(playerid, "Тариф был успешно обновлен!");

			SFCM(playerid,0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Новая цена тарифа 'Эконом' - "cGR"%d"cWH" рублей", count_money);	

			format(String144, sizeof(String144), "[TAXI] Владелец %s изменил стоимость тарифа 'Эконом'. Новая: %d рублей!", pData[playerid][pNickname], count_money);
			send_taxi_job(id_taxi, COLOR_GREY, String144);

			show_taxi_menu(playerid, id_taxi);
			update_taxi_3d_text();

		}
		case DIALOG_CHANGE_TAXI_TARIF_2:
		{
			if(!response)
				return show_taxi_menu(playerid, pData[playerid][pTaxiOwnerID]);

			new 
				id_taxi;

			if(pData[playerid][pTaxiOwnerID] != -1)
			{
				id_taxi = pData[playerid][pTaxiOwnerID];		
			}
			
			if(!response) 
				return show_taxi_menu(playerid, id_taxi);	
			
			
			if(!IsNumeric(inputtext)) 
				return SendErr(playerid,"Вы указали неверный процент!");


			new 
				count_money = strval(inputtext);	

			if(count_money < 75 || count_money > 150)
			{
			    SendErr(playerid,"От 75 до 150 рублей!");
				return change_tarif_taxi_econom(playerid);
			}	

			taxi_company[id_taxi][taxi_company_price_comfort] = count_money;		

			SendSucc(playerid, "Тариф был успешно обновлен!");

			SFCM(playerid,0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Новая цена тарифа 'Комфорт' - "cGR"%d"cWH" рублей", count_money);	

			format(String144, sizeof(String144), "[TAXI] Владелец %s изменил стоимость тарифа 'Комфорт'. Новая: %d рублей!", pData[playerid][pNickname], count_money);
			send_taxi_job(id_taxi, COLOR_GREY, String144);

			show_taxi_menu(playerid, id_taxi);
			update_taxi_3d_text();

		}
		case DIALOG_CHANGE_TAXI_TARIF_3:
		{
			if(!response)
				return show_taxi_menu(playerid, pData[playerid][pTaxiOwnerID]);

			new 
				id_taxi;

			if(pData[playerid][pTaxiOwnerID] != -1)
			{
				id_taxi = pData[playerid][pTaxiOwnerID];		
			}
			
			if(!response) 
				return show_taxi_menu(playerid, id_taxi);	
			
			
			if(!IsNumeric(inputtext)) 
				return SendErr(playerid,"Вы указали неверный процент!");


			new 
				count_money = strval(inputtext);	

			if(count_money < 100 || count_money > 200)
			{
			    SendErr(playerid,"От 100 до 200 рублей!");
				return change_tarif_taxi_econom(playerid);
			}	

			taxi_company[id_taxi][taxi_company_price_buisnes] = count_money;		

			SendSucc(playerid, "Тариф был успешно обновлен!");

			SFCM(playerid,0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Новая цена тарифа 'Бизнес' - "cGR"%d"cWH" рублей", count_money);	

			format(String144, sizeof(String144), "[TAXI] Владелец %s изменил стоимость тарифа 'Бизнес'. Новая: %d рублей!", pData[playerid][pNickname], count_money);
			send_taxi_job(id_taxi, COLOR_GREY, String144);

			show_taxi_menu(playerid, id_taxi);
			update_taxi_3d_text();
		}
	}
	return true;

}


stock change_percent_taxi_1(playerid)
{
	new 
		id_taxi;

	if(pData[playerid][pTaxiOwnerID] != -1)
	{
		id_taxi = pData[playerid][pTaxiOwnerID];		
	}


	format(String144, sizeof(String144), "\
	"cWH"Укажите процент, который будет взыматься с личных авто (От 1 процента до 50 процентов)\n\n\
	Текущий процент: "cGR"%d"cWH" процент(ов)", taxi_company[id_taxi][taxi_company_percent_1]);

	return SPD(playerid, DIALOG_CHANGE_TAXI_PERCENT_1, DIALOG_STYLE_INPUT, !""cWH"Изменение процента", String144, !"Далее", !"Назад");
}

stock change_percent_taxi_2(playerid)
{
	new 
		id_taxi;

	if(pData[playerid][pTaxiOwnerID] != -1)
	{
		id_taxi = pData[playerid][pTaxiOwnerID];		
	}

	format(String256, sizeof(String256), "\
	"cWH"Укажите процент, который будет взыматься с заказов на авто таксопарка (От 1 процента до 50 процентов)\n\n\
	Текущий процент: "cGR"%d"cWH" процент(ов)", taxi_company[id_taxi][taxi_company_percent_2]);

	return SPD(playerid, DIALOG_CHANGE_TAXI_PERCENT_2, DIALOG_STYLE_INPUT, !""cWH"Изменение процента", String256, !"Далее", !"Назад");
}

stock change_tarif_taxi_econom(playerid)
{
	new 
		id_taxi;

	if(pData[playerid][pTaxiOwnerID] != -1)
	{
		id_taxi = pData[playerid][pTaxiOwnerID];		
	}

	format(String144, sizeof(String144), "\
	"cWH"Укажите стоимость тарифа 'Эконом', от 50 до 100 рублей\n\n\
	Текущая стоимость: "cGR"%d"cWH" рублей", taxi_company[id_taxi][taxi_company_price_econom]);

	return SPD(playerid, DIALOG_CHANGE_TAXI_TARIF_1, DIALOG_STYLE_INPUT, !""cWH"Изменение тарифа", String144, !"Далее", !"Назад");
}


stock sell_taxi_company_gos(playerid)
{
	if(pData[playerid][pTaxiOwnerID] == -1)
		return SendErr(playerid, "Вы не владеете таксопарком!");

	SPD(playerid, DIALOG_ACCEPT_SELL_TAXI_GOS, DIALOG_STYLE_MSGBOX, !""cBLUE"Продажа таксопарка", !"\
	"cWH"Вы уверены, что хотите продать таксопарк государству?\n\n\
	Вам будет возвращено 80% от стоимости!", !"Да", !"Нет");


	return true;
}

stock sell_taxi_gos_final(playerid)
{
	if(pData[playerid][pTaxiOwnerID] == -1)
		return SendErr(playerid, "Вы не владеете таксопарком!");


	new 
		f = pData[playerid][pTaxiOwnerID];


	new 
		final_money = floatround(taxi_company[f][taxi_company_price]*0.8);

	new 
		fmt_str[90];

	format(fmt_str, sizeof(fmt_str), "Продажа таксопарка в гос.стоимость №: %d", f);
	give_money(playerid, final_money, fmt_str);

	pData[playerid][pTaxiOwnerID] = -1;
	UpdatePlayerData(playerid,"pTaxiOwnerID", pData[playerid][pTaxiOwnerID]);
	
	SendSucc(playerid, "Вы успешно продали таксопарк государству!");


	pData[playerid][pTaxi] = -1;
	pData[playerid][pTaxiRank] = 0;
	pData[playerid][pJob] = 0;

	UpdatePlayerData(playerid,"pTaxi", pData[playerid][pTaxi]);
	UpdatePlayerData(playerid,"pTaxiRank", pData[playerid][pTaxiRank]);
	UpdatePlayerData(playerid, "job", pData[playerid][pJob]);



	format(String256,sizeof(String256),"DELETE FROM `taxi_personal` WHERE `user_id` = '%d'", pData[playerid][pMysqlID]);
	sql_queryEx(zConn, String256, QUERY_THREADED);

	format(String256,sizeof(String256),"UPDATE `accounts` SET `pTaxi` = '-1', `pTaxiOwnerLowID` = '-1', `job` = '0' WHERE `id` = '%i'", pData[playerid][pMysqlID]);
	sql_queryEx(zConn, String256, QUERY_THREADED);

	taxi_company[f][taxi_company_owner_id] = -1;	
	taxi_company[f][taxi_company_bank] = 0;

	save_taxi_base();
	update_taxi_3d_text();

	return true;
}

stock change_tarif_taxi_comfort(playerid)
{
	new 
		id_taxi;

	if(pData[playerid][pTaxiOwnerID] != -1)
	{
		id_taxi = pData[playerid][pTaxiOwnerID];		
	}

	format(String144, sizeof(String144), "\
	"cWH"Укажите стоимость тарифа 'Комфорт', от 75 до 150 рублей\n\n\
	Текущая стоимость: "cGR"%d"cWH" рублей", taxi_company[id_taxi][taxi_company_price_comfort]);

	return SPD(playerid, DIALOG_CHANGE_TAXI_TARIF_2, DIALOG_STYLE_INPUT, !""cWH"Изменение тарифа", String144, !"Далее", !"Назад");
}

stock change_tarif_taxi_buisnes(playerid)
{
	new 
		id_taxi;

	if(pData[playerid][pTaxiOwnerID] != -1)
	{
		id_taxi = pData[playerid][pTaxiOwnerID];		
	}

	format(String144, sizeof(String144), "\
	"cWH"Укажите стоимость тарифа 'Бизнес', от 100 до 200 рублей\n\n\
	Текущая стоимость: "cGR"%d"cWH" рублей", taxi_company[id_taxi][taxi_company_price_buisnes]);

	return SPD(playerid, DIALOG_CHANGE_TAXI_TARIF_3, DIALOG_STYLE_INPUT, !""cWH"Изменение тарифа", String144, !"Далее", !"Назад");
}


//change_car_taxi_all


stock change_bank_taxi(playerid)
{

	if(pData[playerid][pTaxiOwnerID] == -1)
		return SendErr(playerid, "Вы не являетесь владельцем Таксопарка!");

    format(String256, sizeof(String256), "\
        "cGREY"Тип\t"cGREY"Действие\n\
        "cBLUE"1. "cWH"Снять деньги с кассы\t"cGR"Снять\n\
        "cBLUE"2. "cWH"Положить деньги в кассу\t"cGR"Пополнить");
    SPD(playerid, DIALOG_CHANGE_TAXI_BANK, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление такси", String256, !"Выбрать", !"Закрыть"); 
	return true;
}

stock taxi_bank_operation(playerid, type)
{
	new 
		id_taxi;

	switch(type)
	{
		case 1:
		{
			if(pData[playerid][pTaxiOwnerID] != -1)
			{
				id_taxi = pData[playerid][pTaxiOwnerID];		
			}

			format(String256, sizeof(String256), "\
			"cWH"Сколько денежных средств Вы хотите снять?\n\n\
			в банке такси находится "cGR"%d"cWH" рублей", taxi_company[id_taxi][taxi_company_bank]);

			SPD(playerid, DIALOG_TAXI_INPUT_MONEY, DIALOG_STYLE_INPUT, !""cBLUE"Снятие денег", String256, !"Далее", !"Назад");

		}
		case 2:
		{
			if(pData[playerid][pTaxiOwnerID] != -1)
			{
				id_taxi = pData[playerid][pTaxiOwnerID];		
			}
			else if(pData[playerid][pTaxiOwnerLowID] != -1)
			{
				id_taxi = pData[playerid][pTaxiOwnerLowID];
			}


			format(String256, sizeof(String256), "\
			"cWH"Сколько денежных средств Вы хотите положить?\n\n\
			в банке такси находится "cGR"%d"cWH" рублей", taxi_company[id_taxi][taxi_company_bank]);

			SPD(playerid, DIALOG_TAXI_PUT_MONEY, DIALOG_STYLE_INPUT, !""cBLUE"Пополнение кассы", String256, !"Далее", !"Назад");

		}
	}
	return true;
}


stock change_personal_taxi(playerid, page = 0)
{

	new 
		id_taxi;

	if(page < 0)
	{
		page = 0;
	}

	if(pData[playerid][pTaxiOwnerID] != -1)
	{
		id_taxi = pData[playerid][pTaxiOwnerID];		
	}
	else if(pData[playerid][pTaxiOwnerLowID] != -1)
	{
		id_taxi = pData[playerid][pTaxiOwnerLowID];
	}


    format(String4096, sizeof(String4096), ""cGREY"№. Имя\t"cGREY"Должность\t"cGREY"Общий доход (За сутки)\t"cGREY"Последний заход\n");

    SetPVarIntNew(playerid, "check_page_panel_taxi", page);

	format(String1024, sizeof(String1024), "SELECT * FROM `taxi_personal` WHERE `id` = %d ORDER BY `user_data_last_join` LIMIT %d,20", id_taxi, page*20);
	new Result:rnew = sql_queryEx(zConn, String1024, QUERY_CACHED);

	new all_taxi_stations = sql_num_rows(rnew);

    new 
    	taxi_id_all = page*20;


 	for(new i; i < all_taxi_stations; i++)
	{


		new 
			taxi_personal_user_id,
			taxi_personal_user_rank,
			taxi_per_user_money_day,
			taxi_per_user_money_all,
			taxi_personal_user_name[32],
			taxi_personal_user_join[20],
			taxi_personal_user_last[20];

		taxi_personal_user_id = sql_get_field_assoc_int_ex(rnew, i, "user_id");
		taxi_personal_user_rank = sql_get_field_assoc_int_ex(rnew, i, "user_rank");
		taxi_per_user_money_day = sql_get_field_assoc_int_ex(rnew, i, "user_money_day");
		taxi_per_user_money_all = sql_get_field_assoc_int_ex(rnew, i, "user_money_all");

		dialog_listitem_values[playerid][i] = taxi_personal_user_id;

		GetPlayerNameByID(taxi_personal_user_id,taxi_personal_user_name);

		sql_get_field_assoc_ex(rnew, i, "user_data_join", taxi_personal_user_join, 20);
		sql_get_field_assoc_ex(rnew, i, "user_data_last_join", taxi_personal_user_last, 20);

	    new onnn = 0;


		foreach(Player, x)
		{

			if(pData[x][pMysqlID] == taxi_personal_user_id && pData[x][pTaxi] == pData[playerid][pTaxi]) onnn = 1;
		}


		if(onnn > 0)
		{
			if(taxi_id_all < 9 ) 
			{
		    	format(String4096, sizeof(String4096), "%s%s%d."cWH"  %s \t%s\t%s %d"cWH" %s (%d)"cWH" рублей\t%s\n",String4096, \
		    	get_taxi_color(id_taxi), taxi_id_all+1, taxi_personal_user_name, \
		    	taxi_rank_name[taxi_personal_user_rank], \
		    	get_color_m_taxi(taxi_per_user_money_all), taxi_per_user_money_all, get_color_m_taxi(taxi_per_user_money_day), taxi_per_user_money_day, "{00CC44}Online{FFFFFF}");
		    }
		    else			    
		    {
		    	format(String4096, sizeof(String4096), "%s%s%d."cWH"  %s \t%s\t%s %d"cWH" %s (%d)"cWH" рублей\t%s\n",String4096, \
		    	get_taxi_color(id_taxi), taxi_id_all+1, taxi_personal_user_name, \
		    	taxi_rank_name[taxi_personal_user_rank], \
		    	get_color_m_taxi(taxi_per_user_money_all), taxi_per_user_money_all, get_color_m_taxi(taxi_per_user_money_day), taxi_per_user_money_day,"{00CC44}Online{FFFFFF}");

			}
		}
		else 
		{
			if(taxi_id_all < 9 ) 
			{
		    	format(String4096, sizeof(String4096), "%s%s%d."cWH"  %s \t%s\t%s %d"cWH" %s (%d)"cWH" рублей\t%s\n",String4096, \
		    	get_taxi_color(id_taxi), taxi_id_all+1, taxi_personal_user_name, \
		    	taxi_rank_name[taxi_personal_user_rank], \
		    	get_color_m_taxi(taxi_per_user_money_all), taxi_per_user_money_all, get_color_m_taxi(taxi_per_user_money_day), taxi_per_user_money_day, taxi_personal_user_last);
		    }
		    else			    
		    {
		    	format(String4096, sizeof(String4096), "%s%s%d."cWH"  %s \t%s\t%s %d"cWH" %s (%d)"cWH" рублей\t%s\n",String4096, \
		    	get_taxi_color(id_taxi), taxi_id_all+1, taxi_personal_user_name, \
		    	taxi_rank_name[taxi_personal_user_rank], \
		    	get_color_m_taxi(taxi_per_user_money_all), taxi_per_user_money_all, get_color_m_taxi(taxi_per_user_money_day), taxi_per_user_money_day, taxi_personal_user_last);
			}
		}


		taxi_id_all++;


	}
	sql_next_row(rnew);

	if(all_taxi_stations < 20)
	{
		SetPVarIntNew(playerid, "button_back_personal_menu", all_taxi_stations);
	}

    if(all_taxi_stations == 20) strcat(String4096, ""cGREY"Далее >>>\n");
    if(page >= 1) strcat(String4096, ""cGREY"<<< Назад");

	SPD(playerid,DIALOG_TAXI_PERS, DIALOG_STYLE_TABLIST_HEADERS ,""cBLUE"Персонал такси",String4096,"Далее","Закрыть");
	return true;
}


stock change_rank_personal_taxi(playerid, user_sql_id)
{
	SetPVarIntNew(playerid, "uninvite_taxi_id", user_sql_id);


	new 
		id_taxi;


	if(pData[playerid][pTaxiOwnerID] != -1)
	{
		id_taxi = pData[playerid][pTaxiOwnerID];		
	}
	else if(pData[playerid][pTaxiOwnerLowID] != -1)
	{
		id_taxi = pData[playerid][pTaxiOwnerLowID];
	}

	format(String256, sizeof(String256), "SELECT * FROM taxi_personal WHERE user_id = '%d' LIMIT 1", user_sql_id);
	new Result:taxi_find = sql_queryEx(zConn, String256, QUERY_CACHED);

	if(sql_num_rows(taxi_find)) 
	{
		new 
			taxi_change_name_dialog[32],
			taxi_rank;


  		taxi_rank = sql_get_field_assoc_int(taxi_find, "user_rank");

		GetPlayerNameByID(user_sql_id,taxi_change_name_dialog);

		if(pData[playerid][pTaxiOwnerID] == id_taxi && pData[playerid][pTaxiOwnerLowID] == -1)
		{
		    format(String512, sizeof(String512), "\
	        "cGREY"Сотрудник\t"cGREY"Управление\n\
	        "cBLUE"- "cWH"%s\t"cGR"%s\n\
	        "cBLUE"\t\n\
	        "cBLUE"- "cWH"Таксист\t"cGR"Понизить\n\
	        "cBLUE"- "cWH"Управляющий\t"cGR"Повысить\n\
	        "cBLUE"- "cWH"Уволить сотрудника\t"cGR"Уволить", 
	        taxi_change_name_dialog, taxi_rank_name[taxi_rank]);
		    SPD(playerid, DIALOG_TAXI_PERS_2, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Персонал такси:", String512, !"Выбрать", !"Закрыть"); 					
		}
		else if(pData[playerid][pTaxiOwnerLowID] == id_taxi && pData[playerid][pTaxiOwnerID] == -1)
		{
		    format(String512, sizeof(String512), "\
	        "cGREY"Сотрудник\t"cGREY"Управление\n\
	        "cBLUE"- "cWH"%s\t"cGR"%s\n\
	        "cBLUE"\t\n\
	        "cBLUE"- "cWH"Таксист\t"cGR"Понизить\n\
	        "cBLUE"- "cWH"Управляющий\t"cGR"Повысить\n\
	        "cBLUE"- "cWH"Уволить сотрудника\t"cGR"Уволить", 
	        taxi_change_name_dialog, taxi_rank_name[taxi_rank]);
		    SPD(playerid, DIALOG_TAXI_PERS_2, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Персонал такси:", String512, !"Выбрать", !"Закрыть"); 					
		}

	}
	return true;
}


stock give_rank_truck_taxi(playerid, user_sql_id)
{
	if(pData[playerid][pTaxiOwnerID] == -1)
		return change_rank_personal_taxi(playerid, user_sql_id);

	if(pData[playerid][pMysqlID] == user_sql_id)
	{	
		change_rank_personal_taxi(playerid, user_sql_id);
		return SendErr(playerid, "Вы не можете изменить себе ранг!");
	}


	format(String512, sizeof(String512), "SELECT * FROM taxi_personal WHERE user_id = '%d' LIMIT 1", user_sql_id);
	new Result:taxi_find = sql_queryEx(zConn, String512, QUERY_CACHED);

	if(sql_num_rows(taxi_find)) 
	{
		new 
			taxi_change_name_dialog[32],
			taxi_rank;


  		taxi_rank = sql_get_field_assoc_int(taxi_find, "user_rank");

		GetPlayerNameByID(user_sql_id,taxi_change_name_dialog);

		new 
			player_id = GetPlayerID(taxi_change_name_dialog);

		if(IsPlayerConnected(player_id))
		{
			if(taxi_rank == 1)
			{
				SFCM(playerid, 0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Таксист %s и так уже имеет ранг Таксиста!", taxi_change_name_dialog);
				return change_rank_personal_taxi(playerid, user_sql_id);
			}
			else
			{
				format(String256,sizeof(String256),"UPDATE `taxi_personal` SET `user_rank` = 1 WHERE `user_id` = '%d'" , pData[player_id][pMysqlID]);
				sql_queryEx(zConn, String256, QUERY_THREADED);	

				pData[playerid][pTaxiOwnerLowID] = -1;

				UpdatePlayerData(player_id,"pTaxiOwnerLowID", pData[player_id][pTaxiOwnerLowID]);


				SFCM(player_id, 0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Владелец %s [%d] понизил Вас до должности 'Таксист'", pData[playerid][pNickname], playerid);	

				new 
					id_taxi = pData[playerid][pTaxiOwnerID];


				format(String144, sizeof(String144), "[T] Сотрудник %s был понижен до должности 'Таксист' владельцем %s", taxi_change_name_dialog, pData[playerid][pNickname]);
				send_taxi_job(id_taxi, COLOR_GREY, String144);

				return change_rank_personal_taxi(playerid, user_sql_id);	
			}
		}
		else
		{
			if(taxi_rank == 1)
			{
				SFCM(playerid, 0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Таксист %s и так уже имеет ранг Таксиста!", taxi_change_name_dialog);
				return change_rank_personal_taxi(playerid, user_sql_id);
			}
			else
			{
				format(String256,sizeof(String256),"UPDATE `taxi_personal` SET `user_rank` = 1 WHERE `user_id` = '%d'" , user_sql_id);
				sql_queryEx(zConn, String256, QUERY_THREADED);		

				format(String256,sizeof(String256),"UPDATE `accounts` SET `pTaxiOwnerLowID` = '-1' WHERE `id` = '%i'", user_sql_id);
				sql_queryEx(zConn, String256, QUERY_THREADED);

				SFCM(playerid, 0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Вы успешно понизили %s до должности Таксиста оффлайн!", taxi_change_name_dialog);

				new 
					id_taxi = pData[playerid][pTaxiOwnerID];


				format(String144, sizeof(String144), "[TAXI] Сотрудник %s был понижен до должности 'Таксиста' владельцем %s", taxi_change_name_dialog, pData[playerid][pNickname]);
				send_taxi_job(id_taxi, COLOR_GREY, String144);

				return change_rank_personal_taxi(playerid, user_sql_id);	
			}			
		}


	}	

	return true;
}
stock give_rank_manage_taxi(playerid, user_sql_id)
{
	if(pData[playerid][pTaxiOwnerID] == -1)
		return change_rank_personal_taxi(playerid, user_sql_id);

	if(pData[playerid][pMysqlID] == user_sql_id)
	{	
		change_rank_personal_taxi(playerid, user_sql_id);
		return SendErr(playerid, "Вы не можете изменить себе ранг!");
	}


	format(String512, sizeof(String512), "SELECT * FROM taxi_personal WHERE user_id = '%d' LIMIT 1", user_sql_id);
	new Result:taxi_find = sql_queryEx(zConn, String512, QUERY_CACHED);

	if(sql_num_rows(taxi_find)) 
	{
		new 
			taxi_change_name_dialog[32],
			taxi_rank;


  		taxi_rank = sql_get_field_assoc_int(taxi_find, "user_rank");

		GetPlayerNameByID(user_sql_id,taxi_change_name_dialog);

		new 
			player_id = GetPlayerID(taxi_change_name_dialog);

		if(IsPlayerConnected(player_id))
		{

			if(taxi_rank == 2)
			{
				SFCM(playerid, 0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Таксист %s и так уже является управляющим!", taxi_change_name_dialog);
				return change_rank_personal_taxi(playerid, user_sql_id);
			}
			else
			{
				format(String256,sizeof(String256),"UPDATE `taxi_personal` SET `user_rank` = 2 WHERE `user_id` = '%d'" , user_sql_id);
				sql_queryEx(zConn, String256, QUERY_THREADED);		


				format(String256,sizeof(String256),"UPDATE `accounts` SET `pTaxiOwnerLowID` = '%d' WHERE `id` = '%i'", pData[playerid][pTaxiOwnerID], user_sql_id);
				sql_queryEx(zConn, String256, QUERY_THREADED);

				pData[player_id][pTaxiOwnerLowID] = pData[playerid][pTaxiOwnerID];

				SFCM(player_id, 0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Владелец %s [%d] повысил Вас до должности Управляющего такси!", pData[playerid][pNickname], playerid);

				new 
					id_taxi = pData[playerid][pTaxiOwnerID];


				format(String144, sizeof(String144), "[TAXI] Сотрудник %s был повышен до должности 'Управляющего' владельцем %s", taxi_change_name_dialog, pData[playerid][pNickname]);
				send_taxi_job(id_taxi, COLOR_GREY, String144);

				return change_rank_personal_taxi(playerid, user_sql_id);	
			}
		}
		else
		{
			if(taxi_rank == 2)
			{
				SFCM(playerid, 0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Таксист %s и так уже является управляющим!", taxi_change_name_dialog);
				return change_rank_personal_taxi(playerid, user_sql_id);
			}
			else
			{
				format(String256,sizeof(String256),"UPDATE `taxi_personal` SET `user_rank` = 2 WHERE `user_id` = '%d'" , user_sql_id);
				sql_queryEx(zConn, String256, QUERY_THREADED);		


				format(String256,sizeof(String256),"UPDATE `accounts` SET `pTaxiOwnerLowID` = '%d' WHERE `id` = '%i'", user_sql_id, pData[playerid][pTaxiOwnerID]);
				sql_queryEx(zConn, String256, QUERY_THREADED);

				SFCM(playerid, 0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Вы успешно повысили %s до должности управляющего оффлайн!", taxi_change_name_dialog);

				new 
					id_taxi = pData[playerid][pTaxiOwnerID];


				format(String144, sizeof(String144), "[TAXI] Сотрудник %s был повышен до должности 'Управляющего' владельцем %s", taxi_change_name_dialog, pData[playerid][pNickname]);
				send_taxi_job(id_taxi, COLOR_GREY, String144);

				return change_rank_personal_taxi(playerid, user_sql_id);	
			}			
		}


	}	
	return true;
}
stock uninvite_panel_taxi_t(playerid, user_sql_id)
{

	printf("UNINVITE ID - %d", user_sql_id);

	new 
		id_taxi;


	if(pData[playerid][pTaxiOwnerID] != -1)
	{
		id_taxi = pData[playerid][pTaxiOwnerID];		
	}
	else if(pData[playerid][pTaxiOwnerLowID] != -1)
	{
		id_taxi = pData[playerid][pTaxiOwnerLowID];
	}

	new 
		taxi_change_name_dialog[MAX_PLAYER_NAME];

	new 
		taxi_rank;

	if(pData[playerid][pMysqlID] == user_sql_id)
	{	
		change_rank_personal_taxi(playerid, user_sql_id);
		return SendErr(playerid, "Вы не можете уволить себя!");
	}

	if(pData[playerid][pTaxiOwnerLowID])
	{
		taxi_rank = 2;
	}
	else if(pData[playerid][pTaxiOwnerID])
	{
		taxi_rank = 3;
	}	

	GetPlayerNameByID(user_sql_id,taxi_change_name_dialog);

	new 
		player_id = GetPlayerID(taxi_change_name_dialog);

	if(IsPlayerConnected(player_id))
	{
		pData[player_id][pTaxi] = -1;
		pData[player_id][pTaxiOwnerLowID] = -1;
		pData[player_id][pTaxiRank] = 0;
		pData[player_id][pJob] = 0;

		UpdatePlayerData(player_id,"pTaxi", pData[player_id][pTaxi]);
		UpdatePlayerData(player_id,"pTaxiOwnerLowID", pData[player_id][pTaxiOwnerLowID]);
		UpdatePlayerData(player_id,"pTaxiRank", pData[player_id][pTaxiRank]);
		UpdatePlayerData(player_id, "job", pData[player_id][pJob]);

		format(String256,sizeof(String256),"DELETE FROM `taxi_personal` WHERE `user_id` = '%d'", user_sql_id);
		sql_queryEx(zConn, String256, QUERY_THREADED);

		format(String256,sizeof(String256),"UPDATE `accounts` SET `pTaxi` = '-1', `pTaxiOwnerLowID` = '-1', `job` = '0' WHERE `id` = '%i'", user_sql_id);
		sql_queryEx(zConn, String256, QUERY_THREADED);


		SFCM(player_id, 0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"%s %s [%d] уволил Вас c Таксопарка №%d", taxi_rank_name[taxi_rank], pData[playerid][pNickname], playerid, id_taxi);


		format(String256, sizeof(String256), "[TAXI] Сотрудник %s был уволен с такси %s %s", pData[player_id][pNickname], taxi_rank_name[taxi_rank], pData[playerid][pNickname]);
		send_taxi_job(id_taxi, COLOR_GREY, String256);

	}
	else
	{


		format(String256,sizeof(String256),"DELETE FROM `taxi_personal` WHERE `user_id` = '%d'", user_sql_id);
		sql_queryEx(zConn, String256, QUERY_THREADED);

		format(String256,sizeof(String256),"UPDATE `accounts` SET `pTaxi` = '-1', `pTaxiOwnerLowID` = '-1', `job` = '0'  WHERE `id` = '%i'", user_sql_id);
		sql_queryEx(zConn, String256, QUERY_THREADED);

		SFCM(playerid, 0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Вы успешно уволили %s c Таксопарка", taxi_change_name_dialog);


		format(String256, sizeof(String256), "[TAXI] Сотрудник %s был уволен с такси %s %s", taxi_change_name_dialog, taxi_rank_name[taxi_rank], pData[playerid][pNickname]);
		send_taxi_job(id_taxi, COLOR_GREY, String256);

	}

	DeletePVarNew(playerid, "uninvite_taxi_id");

	change_personal_taxi(playerid);

	return true;
}

stock uninvite_command_pers_taxi(playerid, player_id_to)
{

	new 
		id_taxi;


	if(pData[playerid][pTaxiOwnerID] != -1)
	{
		id_taxi = pData[playerid][pTaxiOwnerID];		
	}
	else if(pData[playerid][pTaxiOwnerLowID] != -1)
	{
		id_taxi = pData[playerid][pTaxiOwnerLowID];
	}


	new 
		taxi_rank;

	if(playerid == player_id_to)
	{	
		return SendErr(playerid, "Вы не можете уволить себя!");
	}

	if(pData[playerid][pTaxiOwnerLowID])
	{
		taxi_rank = 2;
	}
	else if(pData[playerid][pTaxiOwnerID])
	{
		taxi_rank = 3;
	}	


	if(IsPlayerConnected(player_id_to))
	{
		pData[player_id_to][pTaxi] = -1;
		pData[player_id_to][pTaxiOwnerLowID] = -1;
		pData[player_id_to][pTaxiRank] = 0;

		UpdatePlayerData(player_id_to,"pTaxi", pData[player_id_to][pTaxi]);
		UpdatePlayerData(player_id_to,"pTaxiOwnerLowID", pData[player_id_to][pTaxiOwnerLowID]);
		UpdatePlayerData(player_id_to,"pTaxiRank", pData[player_id_to][pTaxiRank]);

		format(String256,sizeof(String256),"DELETE FROM `taxi_personal` WHERE `user_id` = '%d'", pData[player_id_to][pMysqlID]);
		sql_queryEx(zConn, String256, QUERY_THREADED);

		format(String256,sizeof(String256),"UPDATE `accounts` SET `pTaxi` = '-1', `pTaxiOwnerLowID` = '-1' WHERE `id` = '%i'", pData[player_id_to][pMysqlID]);
		sql_queryEx(zConn, String256, QUERY_THREADED);


		SFCM(player_id_to, 0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"%s %s [%d] уволил Вас c Таксопарка №%d", taxi_rank_name[taxi_rank], pData[playerid][pNickname], playerid, id_taxi+1);


		format(String256, sizeof(String256), "[TAXI] Сотрудник %s был уволен с такси %s %s", pData[player_id_to][pNickname], taxi_rank_name[taxi_rank], pData[playerid][pNickname]);
		send_taxi_job(id_taxi, COLOR_GREY, String256);

	}

	return true;
}

stock change_statistic_taxi(playerid)
{

	new 
		id_taxi;


	if(pData[playerid][pTaxiOwnerID] != -1)
	{
		id_taxi = pData[playerid][pTaxiOwnerID];		
	}
	else if(pData[playerid][pTaxiOwnerLowID] != -1)
	{
		id_taxi = pData[playerid][pTaxiOwnerLowID];
	}

	format(String256, sizeof(String256), "SELECT * FROM taxi_stats WHERE taxi_id = '%d' LIMIT 1", id_taxi);
	new Result:taxi_stats = sql_queryEx(zConn, String256, QUERY_CACHED);

	if(sql_num_rows(taxi_stats)) 
	{
		new 
			ye, m, d;

		getdate(ye, m, d);

		new 
			taxi_stats_day[8],
			taxi_stats_today,
			taxi_stats_mounth,
			taxi_status_all,
			taxi_stats_prewiow;

  		taxi_stats_day[1] = sql_get_field_assoc_int(taxi_stats, "stats_day_1");
  		taxi_stats_day[2] = sql_get_field_assoc_int(taxi_stats, "stats_day_2");
  		taxi_stats_day[3] = sql_get_field_assoc_int(taxi_stats, "stats_day_3");
  		taxi_stats_day[4] = sql_get_field_assoc_int(taxi_stats, "stats_day_4");
  		taxi_stats_day[5] = sql_get_field_assoc_int(taxi_stats, "stats_day_5");
  		taxi_stats_day[6] = sql_get_field_assoc_int(taxi_stats, "stats_day_6");
  		taxi_stats_day[7] = sql_get_field_assoc_int(taxi_stats, "stats_day_7");

  		taxi_stats_today = sql_get_field_assoc_int(taxi_stats, "stats_today");
  		taxi_stats_mounth = sql_get_field_assoc_int(taxi_stats, "stats_mounth");
  		taxi_status_all = sql_get_field_assoc_int(taxi_stats, "stats_all_time");
  		taxi_stats_prewiow = sql_get_field_assoc_int(taxi_stats, "stats_mounth_back");

  		new 
  			all_day_seven = taxi_stats_day[1]+taxi_stats_day[2]+taxi_stats_day[3]+taxi_stats_day[4]+taxi_stats_day[5]+taxi_stats_day[6]+taxi_stats_day[7];

		switch(id_taxi)
		{
			case TAXI_COMPANY_YANDEX:
			{
			    format(String4096, sizeof(String4096), "\
		        "cGREY"Дата\t"cGREY"Сумма\t"cGREY"Выгода/Убыток\n\
		        "cORANGE"- "cWH"Понедельник\t%s %d рублей\t"cGR"Не изменилась\n\
		        "cORANGE"- "cWH"Вторник\t%s %d рублей\t%s %d рублей\n\
		        "cORANGE"- "cWH"Среда\t%s %d рублей\t%s %d рублей\n\
		        "cORANGE"- "cWH"Четверг\t%s %d рублей\t%s %d рублей\n\
		        "cORANGE"- "cWH"Пятница\t%s %d рублей\t%s %d рублей\n\
		        "cORANGE"- "cWH"Суббота\t%s %d рублей\t%s %d рублей\n\
		        "cORANGE"- "cWH"Воскресенье\t%s %d рублей\t%s %d рублей\n\
		        "cORANGE"\t\n\
		        "cORANGE"- "cWH"За %s\t%s%d рублей\t%s %d рублей\n\
		        "cORANGE"- "cWH"За %s\t"cGR"%d рублей\n\
		        "cORANGE"- "cWH"За неделю\t"cGR"%d рублей\n\
		        "cORANGE"- "cWH"За все время\t"cGR"%d рублей\n\
		        "cORANGE"- "cWH"За текущий день\t"cGR"%d рублей", 

		        get_color_st_taxi(taxi_stats_day[1], taxi_stats_day[1]), taxi_stats_day[1],
		        get_color_st_taxi(taxi_stats_day[2], taxi_stats_day[1]), taxi_stats_day[2], get_color_taxi_statix(taxi_stats_day[2], taxi_stats_day[1]), get_percent_taxi_c(taxi_stats_day[2], taxi_stats_day[1]), 
		        get_color_st_taxi(taxi_stats_day[3], taxi_stats_day[2]), taxi_stats_day[3], get_color_taxi_statix(taxi_stats_day[3], taxi_stats_day[1]), get_percent_taxi_c(taxi_stats_day[3], taxi_stats_day[2]), 
		        get_color_st_taxi(taxi_stats_day[4], taxi_stats_day[3]), taxi_stats_day[4], get_color_taxi_statix(taxi_stats_day[4], taxi_stats_day[1]), get_percent_taxi_c(taxi_stats_day[4], taxi_stats_day[3]), 
		        get_color_st_taxi(taxi_stats_day[5], taxi_stats_day[4]), taxi_stats_day[5], get_color_taxi_statix(taxi_stats_day[5], taxi_stats_day[1]), get_percent_taxi_c(taxi_stats_day[5], taxi_stats_day[4]), 
		        get_color_st_taxi(taxi_stats_day[6], taxi_stats_day[5]), taxi_stats_day[6], get_color_taxi_statix(taxi_stats_day[6], taxi_stats_day[1]), get_percent_taxi_c(taxi_stats_day[6], taxi_stats_day[5]), 
		        get_color_st_taxi(taxi_stats_day[7], taxi_stats_day[6]), taxi_stats_day[7], get_color_taxi_statix(taxi_stats_day[7], taxi_stats_day[1]), get_percent_taxi_c(taxi_stats_day[7], taxi_stats_day[6]), 
		        mounth_taxi_stats[m], get_color_st_taxi(taxi_stats_mounth, taxi_stats_prewiow), taxi_stats_mounth, get_color_taxi_statix(taxi_stats_mounth, taxi_stats_prewiow), get_percent_taxi_c(taxi_stats_mounth, taxi_stats_prewiow), 
		        mounth_taxi_stats[m-1], taxi_stats_prewiow,
		        all_day_seven,
		        taxi_status_all,
		        taxi_stats_today);
			    SPD(playerid, DIALOG_TAXI_PERSONAL_CLOSE, DIALOG_STYLE_TABLIST_HEADERS, !""cORANGE"Статистика такси", String4096, !"Закрыть", ""); 
			}
			case TAXI_COMPANY_UBER:
			{
			    format(String4096, sizeof(String4096), "\
		        "cGREY"Дата\t"cGREY"Сумма\t"cGREY"Выгода/Убыток\n\
		        "cBLUE"- "cWH"Понедельник\t%s %d рублей\t"cGR"Не изменилась\n\
		        "cBLUE"- "cWH"Вторник\t%s %d рублей\t%s %d рублей\n\
		        "cBLUE"- "cWH"Среда\t%s %d рублей\t%s %d рублей\n\
		        "cBLUE"- "cWH"Четверг\t%s %d рублей\t%s %d рублей\n\
		        "cBLUE"- "cWH"Пятница\t%s %d рублей\t%s %d рублей\n\
		        "cBLUE"- "cWH"Суббота\t%s %d рублей\t%s %d рублей\n\
		        "cBLUE"- "cWH"Воскресенье\t%s %d рублей\t%s %d рублей\n\
		        "cBLUE"\t\n\
		        "cBLUE"- "cWH"За %s\t%s%d рублей\t%s %d рублей\n\
		        "cBLUE"- "cWH"За %s\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"За неделю\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"За все время\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"За текущий день\t"cGR"%d рублей", 

		        get_color_st_taxi(taxi_stats_day[1], taxi_stats_day[1]), taxi_stats_day[1],
		        get_color_st_taxi(taxi_stats_day[2], taxi_stats_day[1]), taxi_stats_day[2], get_color_taxi_statix(taxi_stats_day[2], taxi_stats_day[1]), get_percent_taxi_c(taxi_stats_day[2], taxi_stats_day[1]), 
		        get_color_st_taxi(taxi_stats_day[3], taxi_stats_day[2]), taxi_stats_day[3], get_color_taxi_statix(taxi_stats_day[3], taxi_stats_day[1]), get_percent_taxi_c(taxi_stats_day[3], taxi_stats_day[2]), 
		        get_color_st_taxi(taxi_stats_day[4], taxi_stats_day[3]), taxi_stats_day[4], get_color_taxi_statix(taxi_stats_day[4], taxi_stats_day[1]), get_percent_taxi_c(taxi_stats_day[4], taxi_stats_day[3]), 
		        get_color_st_taxi(taxi_stats_day[5], taxi_stats_day[4]), taxi_stats_day[5], get_color_taxi_statix(taxi_stats_day[5], taxi_stats_day[1]), get_percent_taxi_c(taxi_stats_day[5], taxi_stats_day[4]), 
		        get_color_st_taxi(taxi_stats_day[6], taxi_stats_day[5]), taxi_stats_day[6], get_color_taxi_statix(taxi_stats_day[6], taxi_stats_day[1]), get_percent_taxi_c(taxi_stats_day[6], taxi_stats_day[5]), 
		        get_color_st_taxi(taxi_stats_day[7], taxi_stats_day[6]), taxi_stats_day[7], get_color_taxi_statix(taxi_stats_day[7], taxi_stats_day[1]), get_percent_taxi_c(taxi_stats_day[7], taxi_stats_day[6]), 
		        mounth_taxi_stats[m], get_color_st_taxi(taxi_stats_mounth, taxi_stats_prewiow), taxi_stats_mounth, get_color_taxi_statix(taxi_stats_mounth, taxi_stats_prewiow), get_percent_taxi_c(taxi_stats_mounth, taxi_stats_prewiow), 
		        mounth_taxi_stats[m-1], taxi_stats_prewiow,
		        all_day_seven,
		        taxi_status_all,
		        taxi_stats_today);
			    SPD(playerid, DIALOG_TAXI_PERSONAL_CLOSE, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Статистика такси", String4096, !"Закрыть", ""); 
			}
			case TAXI_COMPANY_CITY:
			{
			    format(String4096, sizeof(String4096), "\
		        "cGREY"Дата\t"cGREY"Сумма\t"cGREY"Выгода/Убыток\n\
		        "cBLUE"- "cWH"Понедельник\t%s %d рублей\t"cGR"Не изменилась\n\
		        "cBLUE"- "cWH"Вторник\t%s %d рублей\t%s %d рублей\n\
		        "cBLUE"- "cWH"Среда\t%s %d рублей\t%s %d рублей\n\
		        "cBLUE"- "cWH"Четверг\t%s %d рублей\t%s %d рублей\n\
		        "cBLUE"- "cWH"Пятница\t%s %d рублей\t%s %d рублей\n\
		        "cBLUE"- "cWH"Суббота\t%s %d рублей\t%s %d рублей\n\
		        "cBLUE"- "cWH"Воскресенье\t%s %d рублей\t%s %d рублей\n\
		        "cBLUE"\t\n\
		        "cBLUE"- "cWH"За %s\t%s%d рублей\t%s %d рублей\n\
		        "cBLUE"- "cWH"За %s\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"За неделю\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"За все время\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"За текущий день\t"cGR"%d рублей", 

		        get_color_st_taxi(taxi_stats_day[1], taxi_stats_day[1]), taxi_stats_day[1],
		        get_color_st_taxi(taxi_stats_day[2], taxi_stats_day[1]), taxi_stats_day[2], get_color_taxi_statix(taxi_stats_day[2], taxi_stats_day[1]), get_percent_taxi_c(taxi_stats_day[2], taxi_stats_day[1]), 
		        get_color_st_taxi(taxi_stats_day[3], taxi_stats_day[2]), taxi_stats_day[3], get_color_taxi_statix(taxi_stats_day[3], taxi_stats_day[1]), get_percent_taxi_c(taxi_stats_day[3], taxi_stats_day[2]), 
		        get_color_st_taxi(taxi_stats_day[4], taxi_stats_day[3]), taxi_stats_day[4], get_color_taxi_statix(taxi_stats_day[4], taxi_stats_day[1]), get_percent_taxi_c(taxi_stats_day[4], taxi_stats_day[3]), 
		        get_color_st_taxi(taxi_stats_day[5], taxi_stats_day[4]), taxi_stats_day[5], get_color_taxi_statix(taxi_stats_day[5], taxi_stats_day[1]), get_percent_taxi_c(taxi_stats_day[5], taxi_stats_day[4]), 
		        get_color_st_taxi(taxi_stats_day[6], taxi_stats_day[5]), taxi_stats_day[6], get_color_taxi_statix(taxi_stats_day[6], taxi_stats_day[1]), get_percent_taxi_c(taxi_stats_day[6], taxi_stats_day[5]), 
		        get_color_st_taxi(taxi_stats_day[7], taxi_stats_day[6]), taxi_stats_day[7], get_color_taxi_statix(taxi_stats_day[7], taxi_stats_day[1]), get_percent_taxi_c(taxi_stats_day[7], taxi_stats_day[6]), 
		        mounth_taxi_stats[m], get_color_st_taxi(taxi_stats_mounth, taxi_stats_prewiow), taxi_stats_mounth, get_color_taxi_statix(taxi_stats_mounth, taxi_stats_prewiow), get_percent_taxi_c(taxi_stats_mounth, taxi_stats_prewiow), 
		        mounth_taxi_stats[m-1], taxi_stats_prewiow,
		        all_day_seven,
		        taxi_status_all,
		        taxi_stats_today);
			    SPD(playerid, DIALOG_TAXI_PERSONAL_CLOSE, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Статистика такси", String4096, !"Закрыть", ""); 
			}
		}

  	}
  	sql_free_result(taxi_stats);


	return true;
}


stock invite_taxi_station(playerid, id_taxi)
{


	if(pData[playerid][pTaxi] == id_taxi)
		return SendErr(playerid, "Вы уже являетесь сотрудником компании!");

	if(!pData[playerid][pLicenses][LIC_DRIVING])
		return SendErr(playerid, "У вас нет лицензии на управление транспортом!");

	if(pData[playerid][pLevel] < 3)
		return SendErr(playerid, "У вас меньше 3 лет проживания в области!");


	if(pData[playerid][pTrucker] != -1)
		return SendErr(playerid, "Вы уже состоите в транспортной компании!");
	if(pData[playerid][pMech] != -1)
		return SendErr(playerid, "Вы уже состоите в СТО!");
	if(pData[playerid][pTaxi] != -1)
		return SendErr(playerid, "Вы уже состоите в Такси!");


	pData[playerid][pTaxi] = id_taxi;
	pData[playerid][pTaxiOwnerLowID] = -1;
	pData[playerid][pTaxiRank] = 1;
	pData[playerid][pJob] = SKILL_TAXI;

	UpdatePlayerData(playerid,"pTaxiOwnerLowID", pData[playerid][pTaxiOwnerLowID]);	
	UpdatePlayerData(playerid,"pTaxi", pData[playerid][pTaxi]);	
	UpdatePlayerData(playerid,"pTaxi", pData[playerid][pTaxiRank]);	
	UpdatePlayerData(playerid,"job", pData[playerid][pJob]);

	format(String1024,sizeof(String1024),"INSERT INTO `taxi_personal`(`id`,`user_id`,`user_rank`) VALUES ('%d','%d','%d')", id_taxi, 
	pData[playerid][pMysqlID], 1);
	sql_queryEx(zConn, String1024, QUERY_THREADED);


	format(String144, sizeof(String144), "[TAXI] В таксопарк устроился новый сотрудник - %s", pData[playerid][pNickname]);
	send_taxi_job(id_taxi, COLOR_GREY, String144);

	taxi_job_initialization(playerid);

	return true;
}

stock leave_taxi_company(playerid)
{
	if(pData[playerid][pTaxiOwnerID] != -1)
	{
		return SendErr(playerid, "Вы не можете уволиться без соглашения с владельцем компании!");
	}

	if(pData[playerid][pTaxi] == -1) 
		return SendErr(playerid, "Вы не работаете таксистом!");

	if(pData[playerid][pTaxiOwnerLowID] != -1)
		return SendErr(playerid, "Вы не можете уволиться без соглашения с владельцем компании!");

	new 
		id_taxi = pData[playerid][pTaxi];

	pData[playerid][pTaxi] = -1;
	pData[playerid][pTaxiRank] = 0;
	pData[playerid][pTaxiOwnerLowID] = -1;
	pData[playerid][pJob] = 0;

	format(String256,sizeof(String256),"DELETE FROM `taxi_personal` WHERE `user_id` = '%d'", pData[playerid][pMysqlID]);
	sql_queryEx(zConn, String256, QUERY_THREADED);


	UpdatePlayerData(playerid,"pTaxiOwnerLowID", pData[playerid][pTaxiOwnerLowID]);	
	UpdatePlayerData(playerid,"pTaxi", pData[playerid][pTaxi]);	
	UpdatePlayerData(playerid,"pTaxiRank", pData[playerid][pTaxiRank]);	
	UpdatePlayerData(playerid, "job",  pData[playerid][pJob]);

	format(String144, sizeof(String144), "[TAXI] %s уволился из таксопарка", pData[playerid][pNickname]);
	send_taxi_job(id_taxi, COLOR_GREY, String144);

	SendSucc(playerid, "Вы уволились из таксопарка!");
	
	panel_working_td_others(playerid, TEXTDRAW_HIDE);

	return true;
}

stock send_taxi_job(taxi_id, color, msg[])
{
	foreach(new i: logged_players)
	{
		if(!IsPlayerConnected(i)) continue;
		if(pData[i][pTaxi] == taxi_id)
		{
			SendClientMessage(i, color, msg);
		}
	}
	return true;
}

CMD:taxmute(playerid, params[])
{
	if(pData[playerid][pTaxiOwnerID] != -1 && pData[playerid][pTaxiOwnerLowID] == -1 || pData[playerid][pTaxiOwnerID] == -1 && pData[playerid][pTaxiOwnerLowID] != -1)
	{
	
		if(sscanf(params, "dds[64]", params[0], params[1], params[2])) 
			return SendInf(playerid, "/tmute [ID игрока] [К-во минут] [Причина]");

		if(!IsPlayerConnected(params[0]) || params[0] == playerid) 
			return SendInf(playerid, "Неверный ID игрока");

		if(pData[params[0]][pTaxi] != pData[playerid][pTaxi])
			return SendErr(playerid, "Игрок не состоит в Вашем Таксопарке");

		new 
			id_trucker = pData[playerid][pTaxi];

		new 
			id = params[0];
		new time = params[1];
		if(time < 10 || time > 180) 
			return SendErr(playerid,"Введите время от 10 до 180 минут");

		if(pData[id][pMutTaxi] > 0) 
			return SendErr(playerid, "Данному игроку уже выдан бан чата рации!");

		pData[id][pMutTaxi] = time;
		UpdatePlayerData(id,"pMutTaxi",time);

		format(String256, sizeof(String256), "[TAXI] %s[%d] выдал блокировку рации %s[%d] на %d минут. Причина: %s", pData[playerid][pNickname], playerid,
		pData[id][pNickname], id, time, params[2]);
		send_taxi_job(id_trucker, COLOR_GREY, String256);
	}
	else
	{
		SendErr(playerid, "Вы не владеете Таксопарком или не являетесь заместителем!");
	}
	return true;
}

CMD:taxunmute(playerid, params[])
{
	if(pData[playerid][pTaxiOwnerID] != -1 && pData[playerid][pTaxiOwnerLowID] == -1 || pData[playerid][pTaxiOwnerID] == -1 && pData[playerid][pTaxiOwnerLowID] != -1)
	{
	
		if(sscanf(params, "d", params[0])) 
			return SendInf(playerid, "/tunmute [ID игрока]");

		if(!IsPlayerConnected(params[0]) || params[0] == playerid) 
			return SendInf(playerid, "Неверный ID игрока");

		if(pData[params[0]][pTaxi] != pData[playerid][pTaxi])
			return SendErr(playerid, "Игрок не состоит в Вашем Таксопарке");

		new 
			id_trucker = pData[playerid][pTaxi];

		if(pData[params[0]][pMutTaxi] == 0) 
			return SendErr(playerid, "У данного игрока нет блокировки рации!");

		pData[params[0]][pMutTaxi] = 0;
		UpdatePlayerData(params[0],"pMutTaxi",0);

		format(String256, sizeof(String256), "[TAXI] %s[%d] снял блокировку рации с %s[%d]", pData[playerid][pNickname], playerid,
		pData[params[0]][pNickname], params[0]);
		send_taxi_job(id_trucker, COLOR_GREY, String256);

	}
	else
	{
		SendErr(playerid, "Вы не владеете Таксопарком или не являетесь заместителем!");
	}
	return true;
}

CMD:taxm(playerid, params[])
{
	if(pData[playerid][pTaxi] == -1) 
		return SendErr(playerid, "Чтобы использовать чат работы, нужно устроиться на работу");

	if(pData[playerid][pMut])
	{
		return SendErr(playerid, "У Вас бан чата. Используйте /mutetime чтобы узнать время бана.");
	}
	if(pTemp[playerid][pMutM])
	{
		return SendErr(playerid, "У Вас затычка во рту.");
	}

	if(pData[playerid][pMutTaxi])
	{
		return SendErr(playerid, "У Вас бан чата. Используйте /time чтобы узнать время бана.");
	}

	if(sscanf(params, "s[90]", params[0])) 
		return SendInf(playerid, "/taxm [Текст] чтобы написать в чат Таксистов (IC информация)");

	switch(pData[playerid][pTaxi])
	{
		case TAXI_COMPANY_YANDEX:
		{
			format(String256, sizeof(String256), "[YandexGO] %s %s [%d]: "cWH"%s", taxi_rank_name[pData[playerid][pTaxiRank]],  pData[playerid][pNickname], playerid, params[0]);
			send_taxi_job(0, COLOR_YELLOW, String256);
		}
		case TAXI_COMPANY_UBER:
		{
			format(String256, sizeof(String256), "[UBER] %s %s [%d]: "cWH"%s", taxi_rank_name[pData[playerid][pTaxiRank]],  pData[playerid][pNickname], playerid, params[0]);
			send_taxi_job(1, COLOR_ORANGE, String256);
		}
		case TAXI_COMPANY_CITY:
		{
			format(String256, sizeof(String256), "[СитиМобил] %s %s [%d]: "cWH"%s", taxi_rank_name[pData[playerid][pTaxiRank]],  pData[playerid][pNickname], playerid, params[0]);
			send_taxi_job(2, COLOR_ORANGE, String256);
		}
	}

	return true;
}

stock taxi_job_initialization(playerid)
{


	format(String144, sizeof(String144), "SELECT * FROM taxi_personal WHERE user_id = '%d' LIMIT 1", pData[playerid][pMysqlID]);
	new Result:taxi_find_pers = sql_queryEx(zConn, String144, QUERY_CACHED);

	if(sql_num_rows(taxi_find_pers)) 
	{
		new 
			taxi_rank;


  		taxi_rank = sql_get_field_assoc_int(taxi_find_pers, "user_rank");
  		pData[playerid][pTaxiRank] = taxi_rank;
  		UpdatePlayerData(playerid,"pTaxiRank", pData[playerid][pTaxiRank]);	

	}	
	sql_free_result(taxi_find_pers);

	return true;
}

stock taxi_job_stats(playerid)
{
	if(pData[playerid][pTaxi] == -1)
		return true;

	format(String144, sizeof(String144), "SELECT * FROM taxi_personal WHERE user_id = '%d' LIMIT 1", pData[playerid][pMysqlID]);
	new Result:taxi_find_pers = sql_queryEx(zConn, String144, QUERY_CACHED);

	if(sql_num_rows(taxi_find_pers)) 
	{
		new 
			mehcnaic_date[32],
			taxi_user_money_day,
			taxi_user_money_all;


  		taxi_user_money_day = sql_get_field_assoc_int(taxi_find_pers, "user_money_day");
  		taxi_user_money_all = sql_get_field_assoc_int(taxi_find_pers, "user_money_all");

  		sql_get_field_assoc(taxi_find_pers, "user_data_join", mehcnaic_date, 20);


	    format(String1024, sizeof(String1024), "\
        "cGREY"Тип\t"cGREY"Информация\t\n\
        "cBLUE"- "cWH"Доход за день\t"cGR"%d рублей\n\
        "cBLUE"- "cWH"Общий доход за всё время\t"cGR"%d рублей\n\
        "cBLUE"\t\n\
        "cBLUE"- "cWH"Должность\t"cGREY"%s\n\
        "cBLUE"- "cWH"Дата вступления\t"cGREY"%s", 
        taxi_user_money_day, taxi_user_money_all,
        taxi_rank_name[pData[playerid][pTaxiRank]], mehcnaic_date);
	    SPD(playerid, 0, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Ваш доход в такси:", String1024, !"Закрыть", ""); 

	}	
	sql_free_result(taxi_find_pers);



	return true;
}

stock start_taxi_job(playerid)
{

	if(pData[playerid][pTaxi] == -1)
		return SendErr(playerid, "Вы не работаете в Такспопарке, чтобы начать работу!");
	new 
		id_taxi;

	id_taxi = pData[playerid][pTaxi];

	if(get_job_level(playerid, SKILL_taxi) == 0)
	{
		add_player_job_skill(playerid, SKILL_taxi, 1);
	}

	format(String144, sizeof(String144), "[TAXI] %s %s[%d] начал работу", taxi_rank_name[pData[playerid][pTaxiRank]], pData[playerid][pNickname], playerid);
	send_taxi_job(id_taxi, COLOR_GREY, String144);

	SetPVarIntNew(playerid, "taxi_job", 1);
	SetPVarIntNew(playerid, "taxi_active_job", 1);

	DeletePVarNew(playerid, "price_final_taxi_work");
	DeletePVarNew(playerid, "price_final_distance");
	DeletePVarNew(playerid, "active_player_gruz_taxi_p");

	DestroyDynamic3DTextLabel(taxi_actor_text[playerid]);
	DestroyActor(taxi_actor_dynamic[playerid]);

	return true;
}

stock end_taxi_job(playerid)
{

	if(pData[playerid][pTaxi] == -1)
		return true;
 
	if(GetPVarIntNew(playerid, "taxi_job") != 1)
		return true;

	new 
		id_taxi;

	id_taxi = pData[playerid][pTaxi];


	format(String144, sizeof(String144), "[TAXI] %s %s[%d] закончил работу", taxi_rank_name[pData[playerid][pTaxiRank]], pData[playerid][pNickname], playerid);
	send_taxi_job(id_taxi, COLOR_GREY, String144);

	DeletePVarNew(playerid, "taxi_active_job");
	DeletePVarNew(playerid, "taxi_job"); 

	DestroyDynamic3DTextLabel(taxi_actor_text[playerid]);
	DestroyActor(taxi_actor_dynamic[playerid]);

	SetPlayerSkin(playerid, pData[playerid][pSkin]);

	DeletePVarNew(playerid, "price_final_taxi_work");
	DeletePVarNew(playerid, "price_final_distance");
	DeletePVarNew(playerid, "active_player_gruz_taxi_p");

	DestroyDynamic3DTextLabel(taxi_actor_text[playerid]);
	DestroyActor(taxi_actor_dynamic[playerid]);

	SendSucc(playerid, "Вы успешно закончили рабочий день в Такспопарке");

	unrent_job_taxi(playerid);
	return true;
}

stock unrent_job_taxi(playerid)
{
	new 
		v = pTemp[playerid][rent_car];

	if(v == INVALID_VEHICLE_ID) return true;
	DestroyVehicle(v);
	DisablePlayerRaceCheckpoint(playerid);

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:info_gui_vehicle_unrent", 3500);


	DeletePVarNew(playerid, "price_final_taxi_work");
	DeletePVarNew(playerid, "price_final_distance");
	DeletePVarNew(playerid, "active_player_gruz_taxi_p");

	DestroyDynamic3DTextLabel(taxi_actor_text[playerid]);
	DestroyActor(taxi_actor_dynamic[playerid]);

	pTemp[playerid][rent_car] = INVALID_VEHICLE_ID;
	pTemp[playerid][rent_car_spawn_timer] = INVALID_TIMER_ID;


	taxi_count_truck[pData[playerid][pTaxi]]++;

	return true;
}


stock get_color_m_taxi(money)
{
	new color[10];

	if(money < 0) color = ""cLRED"";
	if(money > 0) color = ""cGR"";
	if(money == 0) color = ""cGR"";

	return color;
}

stock get_taxi_color(taxi_id)
{
	new 
		color[10];

	if(taxi_id == TAXI_COMPANY_YANDEX) color = ""cORANGE"";
	if(taxi_id == TAXI_COMPANY_UBER) color = ""cBLUE"";
	if(taxi_id == TAXI_COMPANY_CITY) color = ""cLRED"";

	return color;
}

stock get_color_st_taxi(money_first, money_previow)
{
	new 
		color[10];

	if(money_first == money_previow) color = ""cYELLOW"";
	if(money_previow > money_first) color = ""cLRED"";
	if(money_previow < money_first) color = ""cGR"";

	return color;
}

stock get_color_taxi_statix(money_first, money_previow)
{
	new 
		color[25];

	if(money_first == money_previow) color = ""cGR"Больше на";
	if(money_previow > money_first) color = ""cLRED"Меньше на";
	if(money_previow < money_first) color = ""cGR"Больше на";

	return color;
}

stock get_percent_taxi_c(money_previow, money_first)
{

	new 
		final_money = money_previow - money_first;
	
	return final_money;
}

CMD:taxstats(playerid)
{

	if(pData[playerid][pTaxi] == -1)
		return SendErr(playerid, "Вы не работаете в Такспопарке, чтобы просмотреть свою статистику!");

	return taxi_job_stats(playerid);
}

stock pay_taxi_money(playerid, pay_playerid, money, text[])
{
	new 
		id_taxi;

	id_taxi = pData[pay_playerid][pTaxi];

	if(GetPlayerMoney(playerid) < 0) ResetPlayerMoney(playerid);
	if(GetPlayerMoney(pay_playerid) < 0) ResetPlayerMoney(pay_playerid);

	new 
		percent_money = percent_money_taxi(money, taxi_company[id_taxi][taxi_base_percent]);

	taxi_company[id_taxi][taxi_company_bank] += percent_money;	

	new 
		id1 = -1, id2 = -1, remain1, remain2;

	if(pay_playerid >= 0)
	{
		if(pData[pay_playerid][pEConfirmed] < 99 || money < 0)	
		{
			pData[pay_playerid][pMoney] = pData[pay_playerid][pMoney] + (money-percent_money);
			GivePlayerMoney(pay_playerid,money);
		}
		id2 = pData[pay_playerid][pMysqlID];
		remain2 = pData[pay_playerid][pMoney];
	}
	if(playerid >= 0)
	{
		GivePlayerMoney(playerid,-money);
		pData[playerid][pMoney] = pData[playerid][pMoney] - money;
		id1 = pData[playerid][pMysqlID];
		remain1 = pData[playerid][pMoney];
	}
	new y,m,d,h,mi,s;
	getdate(y,m,d);
	gettime(h,mi,s);

	if(playerid >= 0) UpdatePlayerData(playerid,"money",pData[playerid][pMoney]);
	if(pay_playerid >= 0) UpdatePlayerData(pay_playerid,"money",pData[pay_playerid][pMoney]);


	return true;
}

stock percent_money_taxi(x, y)
{
    new 
    	money_final = (x/100) * y;

    return money_final;
}



stock pay_money_taxi_company(sum, taxi_id)
{
	
	/*if(taxi_company[taxi_id][taxi_company_finka_day] >= taxi_company[taxi_id][taxi_finka_ogran])
		return true;*/

	taxi_company[taxi_id][taxi_company_bank] += sum;
	taxi_company[taxi_id][taxi_finka_ogran_day] += sum;

	format(String256,sizeof(String256),"UPDATE `taxi_stats` SET `stats_all_time` = `stats_all_time`+'%d' WHERE `taxi_id` = '%d'" , sum, taxi_id);
	sql_queryEx(zConn, String256, QUERY_THREADED);	
	format(String256,sizeof(String256),"UPDATE `taxi_stats` SET `stats_mounth` = `stats_mounth`+'%d' WHERE `taxi_id` = '%d'" , sum, taxi_id);
	sql_queryEx(zConn, String256, QUERY_THREADED);	

    new 
    	lyear, lmonth, lday;
	getdate(lyear, lmonth, lday);

	new 
		lwday = weekday(lday, lmonth, lyear);

	switch(lwday)
	{
		case 0:
		{
			format(String256,sizeof(String256),"UPDATE `taxi_stats` SET `stats_day_1` = `stats_day_1`+'%d' WHERE `taxi_id` = '%d'" , sum, taxi_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	

			format(String256,sizeof(String256),"UPDATE `taxi_stats` SET `stats_today` = `stats_today`+'%d' WHERE `taxi_id` = '%d'" , sum, taxi_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	

		}
		case 1:
		{
			format(String256,sizeof(String256),"UPDATE `taxi_stats` SET `stats_day_2` = `stats_day_2`+'%d' WHERE `taxi_id` = '%d'" , sum, taxi_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `taxi_stats` SET `stats_today` = `stats_today`+'%d' WHERE `taxi_id` = '%d'" , sum, taxi_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}	

		case 2:
		{
			format(String256,sizeof(String256),"UPDATE `taxi_stats` SET `stats_day_3` = `stats_day_3`+'%d' WHERE `taxi_id` = '%d'" , sum, taxi_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `taxi_stats` SET `stats_today` = `stats_today`+'%d' WHERE `taxi_id` = '%d'" , sum, taxi_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}
		case 3:
		{
			format(String256,sizeof(String256),"UPDATE `taxi_stats` SET `stats_day_4` = `stats_day_4`+'%d' WHERE `taxi_id` = '%d'" , sum, taxi_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `taxi_stats` SET `stats_today` = `stats_today`+'%d' WHERE `taxi_id` = '%d'" , sum, taxi_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}

		case 4:
		{
			format(String256,sizeof(String256),"UPDATE `taxi_stats` SET `stats_day_5` = `stats_day_5`+'%d' WHERE `taxi_id` = '%d'" , sum, taxi_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `taxi_stats` SET `stats_today` = `stats_today`+'%d' WHERE `taxi_id` = '%d'" , sum, taxi_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}	
		case 5:
		{
			format(String256,sizeof(String256),"UPDATE `taxi_stats` SET `stats_day_6` = `stats_day_6`+'%d' WHERE `taxi_id` = '%d'" , sum, taxi_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `taxi_stats` SET `stats_today` = `stats_today`+'%d' WHERE `taxi_id` = '%d'" , sum, taxi_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}
		case 6:
		{
			format(String256,sizeof(String256),"UPDATE `taxi_stats` SET `stats_day_7` = `stats_day_7`+'%d' WHERE `taxi_id` = '%d'" , sum, taxi_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `taxi_stats` SET `stats_today` = `stats_today`+'%d' WHERE `taxi_id` = '%d'" , sum, taxi_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}

	}	

	return true;
}

stock clear_stats_taxi_day()
{


    new 
    	lyear, lmonth, lday;
	getdate(lyear, lmonth, lday);

	new 
		lwday = weekday(lday, lmonth, lyear);

	switch(lwday)
	{
		case 0:
		{
			format(String256,sizeof(String256),"UPDATE `taxi_stats` SET `stats_day_1` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	

			format(String256,sizeof(String256),"UPDATE `taxi_stats` SET `stats_today` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	

		}
		case 1:
		{
			format(String256,sizeof(String256),"UPDATE `taxi_stats` SET `stats_day_2` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `taxi_stats` SET `stats_today` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}	

		case 2:
		{
			format(String256,sizeof(String256),"UPDATE `taxi_stats` SET `stats_day_3` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `taxi_stats` SET `stats_today` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}
		case 3:
		{
			format(String256,sizeof(String256),"UPDATE `taxi_stats` SET `stats_day_4` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `taxi_stats` SET `stats_today` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}

		case 4:
		{
			format(String256,sizeof(String256),"UPDATE `taxi_stats` SET `stats_day_5` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `taxi_stats` SET `stats_today` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}	
		case 5:
		{
			format(String256,sizeof(String256),"UPDATE `taxi_stats` SET `stats_day_6` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `taxi_stats` SET `stats_today` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}
		case 6:
		{
			format(String256,sizeof(String256),"UPDATE `taxi_stats` SET `stats_day_7` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `taxi_stats` SET `stats_today` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}

	}	
	return true;
}

stock clear_stats_taxi_mounth()
{
	for(new i; i < MAX_TAXI_COMPANY; i++)
	{
		format(String256,sizeof(String256),"UPDATE `taxi_stats` SET `stats_mounth_back` = `stats_mounth` WHERE `taxi_id` = '%d'" , i);
		sql_queryEx(zConn, String256, QUERY_THREADED);	
	}
	format(String256,sizeof(String256),"UPDATE `taxi_stats` SET `stats_mounth` = '0'");
	sql_queryEx(zConn, String256, QUERY_THREADED);	

	return true;
}



CMD:ataxifin(playerid, params[])
{


    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

	if(sscanf(params, "dd", params[0], params[1]))
	{
		SendInf(playerid, "Используйте: /ataxifin "cWH"[ID Такси] [Ограничение]");
		return true;
	}

	taxi_company[params[0]][taxi_company_finka_ogran] = params[1];

    format(String144, sizeof(String144), "Вы успешно изменили максимальную прибыль для Такси №%d на "cGR"%d "cWH"рублей!", params[0], params[1]);
    SendSucc(playerid, String144);

	return true;
}


stock start_work_taxi_car_user(playerid, type_company)
{
	switch(type_company)
	{
		case TAXI_COMPANY_YANDEX:
		{
			if(!pData[playerid][car_sql_1])
			{
				show_type_work_taxi(playerid, TAXI_COMPANY_YANDEX);
				return SendErr(playerid, "У вас нет личного автомобиля!");
			}

			new 
				v = pData[playerid][car_id];

			if(v == INVALID_VEHICLE_ID) 
			{
				show_type_work_taxi(playerid, TAXI_COMPANY_YANDEX);
				return SendErr(playerid, "Ваш автомобиль недоступен!");
			}

			if(!IsPlayerInRangeOfPoint(playerid, 10.0, ACVehInfo[v][acPosX], ACVehInfo[v][acPosY], ACVehInfo[v][acPosZ]))
			{
				show_type_work_taxi(playerid, TAXI_COMPANY_YANDEX);
				return SendInf(playerid, "Вы слишком далеко от транспорта!");
			}

			new 
				random_position_car = random(12);

			SetVehiclePos(v, position_spawn_taxi_yandex[random_position_car][0], position_spawn_taxi_yandex[random_position_car][1], position_spawn_taxi_yandex[random_position_car][2]);
			SetVehicleZAngle(v, position_spawn_taxi_yandex[random_position_car][3]);

			if(transport_config[GetVehicleModel(v)-400][transport_name] == 1)
			{
				SetPVarIntNew(playerid, "taxi_work_tarif", TARIF_TAXI_ECONOM);

				SendSucc(playerid, "Вы начали работать таксистом на тарифе 'Эконом'. Отправляйтесь к автомобилю!");

				format(String144, sizeof(String144), "\
				"cYELLOW"«ЯндексGO»"cWH"\n\
				Эконом Такси");
				vehicle[v][cLabelTaxi] = CreateDynamic3DTextLabel(String144, -1, 0.0, 0.0, 0.5, 10.0, INVALID_PLAYER_ID, v, 1);


			}
			else if(transport_config[GetVehicleModel(v)-400][transport_name] == 2)
			{
				SetPVarIntNew(playerid, "taxi_work_tarif", TARIF_TAXI_COMFORT);

				SendSucc(playerid, "Вы начали работать таксистом на тарифе 'Комфорт'. Отправляйтесь к автомобилю!");

				format(String144, sizeof(String144), "\
				"cYELLOW"«ЯндексGO»"cWH"\n\
				Такси Комфорт");
				vehicle[v][cLabelTaxi] = CreateDynamic3DTextLabel(String144, -1, 0.0, 0.0, 0.5, 10.0, INVALID_PLAYER_ID, v, 1);

			}
			else if(transport_config[GetVehicleModel(v)-400][transport_name] == 3 || transport_config[GetVehicleModel(v)-400][transport_name] == 4)
			{
				SetPVarIntNew(playerid, "taxi_work_tarif", TARIF_TAXI_BUISNES);	
				SendSucc(playerid, "Вы начали работать таксистом на тарифе 'Бизнес'. Отправляйтесь к автомобилю!");

				format(String144, sizeof(String144), "\
				"cYELLOW"«ЯндексGO»"cWH"\n\
				Бизнес Такси");
				vehicle[v][cLabelTaxi] = CreateDynamic3DTextLabel(String144, -1, 0.0, 0.0, 0.5, 10.0, INVALID_PLAYER_ID, v, 1);

			}
			taxi_company[TAXI_COMPANY_YANDEX][taxi_company_count_working]++;


		}
		case TAXI_COMPANY_CITY:
		{
			if(!pData[playerid][car_sql_1])
			{
				show_type_work_taxi(playerid, TAXI_COMPANY_CITY);
				return SendErr(playerid, "У вас нет личного автомобиля!");
			}

			new 
				v = pData[playerid][car_id];

			if(v == INVALID_VEHICLE_ID) 
			{
				show_type_work_taxi(playerid, TAXI_COMPANY_CITY);
				return SendErr(playerid, "Ваш автомобиль недоступен!");
			}

			if(!IsPlayerInRangeOfPoint(playerid, 10.0, ACVehInfo[v][acPosX], ACVehInfo[v][acPosY], ACVehInfo[v][acPosZ]))
			{
				show_type_work_taxi(playerid, TAXI_COMPANY_CITY);
				return SendInf(playerid, "Вы слишком далеко от транспорта!");
			}


			new 
				random_position_car = random(12);

			SetVehiclePos(v, position_spawn_taxi_city[random_position_car][0], position_spawn_taxi_city[random_position_car][1], position_spawn_taxi_city[random_position_car][2]);
			SetVehicleZAngle(v, position_spawn_taxi_city[random_position_car][3]);

			if(transport_config[GetVehicleModel(v)-400][transport_name] == 1)
			{
				SetPVarIntNew(playerid, "taxi_work_tarif", TARIF_TAXI_ECONOM);

				SendSucc(playerid, "Вы начали работать таксистом на тарифе 'Эконом'. Отправляйтесь к автомобилю!");

				format(String144, sizeof(String144), "\
				"cORANGE"«СитиМобил»"cWH"\n\
				Эконом Такси");
				vehicle[v][cLabelTaxi] = CreateDynamic3DTextLabel(String144, -1, 0.0, 0.0, 0.5, 10.0, INVALID_PLAYER_ID, v, 1);


			}
			else if(transport_config[GetVehicleModel(v)-400][transport_name] == 2)
			{
				SetPVarIntNew(playerid, "taxi_work_tarif", TARIF_TAXI_COMFORT);

				SendSucc(playerid, "Вы начали работать таксистом на тарифе 'Комфорт'. Отправляйтесь к автомобилю!");

				format(String144, sizeof(String144), "\
				"cORANGE"«СитиМобил»"cWH"\n\
				Такси Комфорт");
				vehicle[v][cLabelTaxi] = CreateDynamic3DTextLabel(String144, -1, 0.0, 0.0, 0.5, 10.0, INVALID_PLAYER_ID, v, 1);

			}
			else if(transport_config[GetVehicleModel(v)-400][transport_name] == 3 || transport_config[GetVehicleModel(v)-400][transport_name] == 4)
			{
				SetPVarIntNew(playerid, "taxi_work_tarif", TARIF_TAXI_BUISNES);	
				SendSucc(playerid, "Вы начали работать таксистом на тарифе 'Бизнес'. Отправляйтесь к автомобилю!");

				format(String144, sizeof(String144), "\
				"cORANGE"«СитиМобил»"cWH"\n\
				Бизнес Такси");
				vehicle[v][cLabelTaxi] = CreateDynamic3DTextLabel(String144, -1, 0.0, 0.0, 0.5, 10.0, INVALID_PLAYER_ID, v, 1);

			}
			taxi_company[TAXI_COMPANY_CITY][taxi_company_count_working]++;

		}
		case TAXI_COMPANY_UBER:
		{
			if(!pData[playerid][car_sql_1])
			{
				show_type_work_taxi(playerid, TAXI_COMPANY_UBER);
				return SendErr(playerid, "У вас нет личного автомобиля!");
			}

			new 
				v = pData[playerid][car_id];

			if(v == INVALID_VEHICLE_ID) 
			{
				show_type_work_taxi(playerid, TAXI_COMPANY_UBER);
				return SendErr(playerid, "Ваш автомобиль недоступен!");
			}

			if(!IsPlayerInRangeOfPoint(playerid, 10.0, ACVehInfo[v][acPosX], ACVehInfo[v][acPosY], ACVehInfo[v][acPosZ]))
			{
				show_type_work_taxi(playerid, TAXI_COMPANY_UBER);
				return SendInf(playerid, "Вы слишком далеко от транспорта!");
			}


			new 
				random_position_car = random(8);

			SetVehiclePos(v, position_spawn_taxi_uber[random_position_car][0], position_spawn_taxi_uber[random_position_car][1], position_spawn_taxi_uber[random_position_car][2]);
			SetVehicleZAngle(v, position_spawn_taxi_uber[random_position_car][3]);

			if(transport_config[GetVehicleModel(v)-400][transport_name] == 1)
			{
				SetPVarIntNew(playerid, "taxi_work_tarif", TARIF_TAXI_ECONOM);

				SendSucc(playerid, "Вы начали работать таксистом на тарифе 'Эконом'. Отправляйтесь к автомобилю!");

				format(String144, sizeof(String144), "\
				"cUBER"«UBER»"cWH"\n\
				Эконом Такси");
				vehicle[v][cLabelTaxi] = CreateDynamic3DTextLabel(String144, -1, 0.0, 0.0, 0.5, 10.0, INVALID_PLAYER_ID, v, 1);


			}
			else if(transport_config[GetVehicleModel(v)-400][transport_name] == 2)
			{
				SetPVarIntNew(playerid, "taxi_work_tarif", TARIF_TAXI_COMFORT);

				SendSucc(playerid, "Вы начали работать таксистом на тарифе 'Комфорт'. Отправляйтесь к автомобилю!");

				format(String144, sizeof(String144), "\
				"cUBER"«UBER»"cWH"\n\
				Такси Комфорт");
				vehicle[v][cLabelTaxi] = CreateDynamic3DTextLabel(String144, -1, 0.0, 0.0, 0.5, 10.0, INVALID_PLAYER_ID, v, 1);

			}
			else if(transport_config[GetVehicleModel(v)-400][transport_name] == 3 || transport_config[GetVehicleModel(v)-400][transport_name] == 4)
			{
				SetPVarIntNew(playerid, "taxi_work_tarif", TARIF_TAXI_BUISNES);	
				SendSucc(playerid, "Вы начали работать таксистом на тарифе 'Бизнес'. Отправляйтесь к автомобилю!");

				format(String144, sizeof(String144), "\
				"cUBER"«UBER»"cWH"\n\
				Бизнес Такси");
				vehicle[v][cLabelTaxi] = CreateDynamic3DTextLabel(String144, -1, 0.0, 0.0, 0.5, 10.0, INVALID_PLAYER_ID, v, 1);

			}
			taxi_company[TAXI_COMPANY_UBER][taxi_company_count_working]++;
		}		
	}
	return true;
}

stock start_work_taxi_tarif(playerid, type_company)
{
	switch(type_company)
	{
		case TAXI_COMPANY_YANDEX:
		{
		    format(String512, sizeof(String512), "\
		    "cGREY"№\t"cGREY"Информация\t"cGREY"Доступ\n\
		    "cYELLOW"- "cWH"Эконом\t"cGR"%d рублей"cWH" за 1 км\tС 1-го уровня таксиста\n\
		    "cYELLOW"- "cWH"Комфорт\t"cGR"%d рублей"cWH" за 1 км\tСо 2-го уровня таксиста\n\
		    "cYELLOW"- "cWH"Бизнес\t"cGR"%d рублей"cWH" за 1 км\tС 3-го уровня таксиста", taxi_company[TAXI_COMPANY_YANDEX][taxi_company_price_econom],
			taxi_company[TAXI_COMPANY_YANDEX][taxi_company_price_comfort],
			taxi_company[TAXI_COMPANY_YANDEX][taxi_company_price_buisnes]);
		    return SPD(playerid, DIALOG_SELECT_YANDEX_TARIF_WORK, DIALOG_STYLE_TABLIST_HEADERS, !""cYELLOW"«YandexGO»", String512, !"Выбрать", !"Закрыть"); 
					
		}
		case TAXI_COMPANY_CITY:
		{
		    format(String512, sizeof(String512), "\
		    "cGREY"№\t"cGREY"Информация\t"cGREY"Доступ\n\
		    "cORANGE"- "cWH"Эконом\t"cGR"%d рублей"cWH" за 1 км\tС 1-го уровня таксиста\n\
		    "cORANGE"- "cWH"Комфорт\t"cGR"%d рублей"cWH" за 1 км\tСо 2-го уровня таксиста\n\
		    "cORANGE"- "cWH"Бизнес\t"cGR"%d рублей"cWH" за 1 км\tС 3-го уровня таксиста", taxi_company[TAXI_COMPANY_CITY][taxi_company_price_econom],
			taxi_company[TAXI_COMPANY_CITY][taxi_company_price_comfort],
			taxi_company[TAXI_COMPANY_CITY][taxi_company_price_buisnes]);
		    return SPD(playerid, DIALOG_SELECT_CITY_TARIF_WORK, DIALOG_STYLE_TABLIST_HEADERS, !""cORANGE"«СитиМобил»", String512, !"Выбрать", !"Закрыть"); 			
		}
		case TAXI_COMPANY_UBER:
		{
		    format(String512, sizeof(String512), "\
		    "cGREY"№\t"cGREY"Информация\t"cGREY"Доступ\n\
		    "cUBER"- "cWH"Эконом\t1 км - "cGR"%d рублей"cWH"\tС 1-го уровня таксиста\n\
		    "cUBER"- "cWH"Комфорт\t1 км - "cGR"%d рублей"cWH"\tСо 2-го уровня таксиста\n\
		    "cUBER"- "cWH"Бизнес\t1 км - "cGR"%d рублей"cWH"\tС 3-го уровня таксиста", taxi_company[TAXI_COMPANY_UBER][taxi_company_price_econom],
			taxi_company[TAXI_COMPANY_UBER][taxi_company_price_comfort],
			taxi_company[TAXI_COMPANY_UBER][taxi_company_price_buisnes]);
		    return SPD(playerid, DIALOG_SELECT_UBER_TARIF_WORK, DIALOG_STYLE_TABLIST_HEADERS, !""cUBER"«UBER»", String512, !"Выбрать", !"Закрыть"); 			
		}		
	}
	return true;	
}

stock start_work_taxi_car_taxi(playerid, type_company)
{
	switch(type_company)
	{
		case TAXI_COMPANY_YANDEX:
		{
			start_work_taxi_tarif(playerid, TAXI_COMPANY_YANDEX);
		}
		case TAXI_COMPANY_CITY:
		{
			start_work_taxi_tarif(playerid, TAXI_COMPANY_CITY);
		}
		case TAXI_COMPANY_UBER:
		{
			start_work_taxi_tarif(playerid, TAXI_COMPANY_UBER);
		}		
	}
	return true;
}


stock show_type_work_taxi(playerid, type_company)
{
	switch(type_company)
	{
		case TAXI_COMPANY_YANDEX:
		{
		    format(String256, sizeof(String256), "\
		    "cGREY"№\t"cGREY"Информация\n\
		    "cYELLOW"- "cWH"Работа на авто таксопарка\t"cWH"Процент с поездки: "cYELLOW"%d%%", taxi_company[TAXI_COMPANY_YANDEX][taxi_company_percent_1], taxi_company[TAXI_COMPANY_YANDEX][taxi_company_percent_2]);
		    return SPD(playerid, DIALOG_SELECT_YANDEX_ST_WORK, DIALOG_STYLE_TABLIST_HEADERS, !""cYELLOW"«YandexGO»", String256, !"Выбрать", !"Закрыть"); 
		
		}
		case TAXI_COMPANY_CITY:
		{
		    format(String256, sizeof(String256), "\
		    "cGREY"№\t"cGREY"Информация\n\
		    "cORANGE"- "cWH"Работа на авто таксопарка\t"cWH"Процент с поездки: "cORANGE"%d%%", taxi_company[TAXI_COMPANY_CITY][taxi_company_percent_1], taxi_company[TAXI_COMPANY_CITY][taxi_company_percent_2]);
		    return SPD(playerid, DIALOG_SELECT_CITY_ST_WORK, DIALOG_STYLE_TABLIST_HEADERS, !""cORANGE"«СитиМобил»", String256, !"Выбрать", !"Закрыть"); 
		}
		case TAXI_COMPANY_UBER:
		{
		    format(String256, sizeof(String256), "\
		    "cGREY"№\t"cGREY"Информация\n\
		    "cUBER"- "cWH"Работа на авто таксопарка\t"cWH"Процент с поездки: "cUBER"%d%%", taxi_company[TAXI_COMPANY_UBER][taxi_company_percent_1], taxi_company[TAXI_COMPANY_UBER][taxi_company_percent_2]);
		    return SPD(playerid, DIALOG_SELECT_UBER_ST_WORK, DIALOG_STYLE_TABLIST_HEADERS, !""cUBER"«UBER»", String256, !"Выбрать", !"Закрыть"); 
		}
	}
	return true;	
}


stock show_info_taxi_work(playerid, type_company)
{
	switch(type_company)
	{
		case TAXI_COMPANY_YANDEX:
		{


		    format(String512, sizeof(String512), "\
		    "cGREY"№\t"cGREY"Информация\t"cGREY"Информация\n\
		    "cYELLOW"1. "cWH"Работа водителем такси\t"cYELLOW"Информация\t"cYELLOW"%d"cWH" таксистов\n\
		    "cYELLOW"2. "cWH"Статистика водителя в компании\t"cYELLOW"Изучить\n\
		    "cYELLOW"3. "cWH"Уволиться из компании\t"cYELLOW"Уволиться", taxi_company[TAXI_COMPANY_YANDEX][taxi_company_count_working]);
		    return SPD(playerid, DIALOG_SELECT_YANDEX_WORK, DIALOG_STYLE_TABLIST_HEADERS, !""cYELLOW"«YandexGO»", String512, !"Выбрать", !"Закрыть"); 
		}
		case TAXI_COMPANY_UBER:
		{


		    format(String512, sizeof(String512), "\
		    "cGREY"№\t"cGREY"Информация\t"cGREY"Информация\n\
		    "cUBER"1. "cWH"Работа водителем такси\t"cUBER"Информация\t"cUBER"%d"cWH" таксистов\n\
		    "cUBER"2. "cWH"Статистика водителя в компании\t"cUBER"Изучить\n\
		    "cUBER"3. "cWH"Уволиться из компании\t"cUBER"Уволиться", taxi_company[TAXI_COMPANY_UBER][taxi_company_count_working]);
		    return SPD(playerid, DIALOG_SELECT_UBER_WORK, DIALOG_STYLE_TABLIST_HEADERS, !""cUBER"«UBER»", String512, !"Выбрать", !"Закрыть");
		}
		case TAXI_COMPANY_CITY:
		{


		    format(String512, sizeof(String512), "\
		    "cGREY"№\t"cGREY"Информация\t"cGREY"Информация\n\
		    "cORANGE"1. "cWH"Работа водителем такси\t"cORANGE"Информация\t"cORANGE"%d"cWH" таксистов\n\
		    "cORANGE"2. "cWH"Статистика водителя в компании\t"cORANGE"Изучить\n\
		    "cORANGE"3. "cWH"Уволиться из компании\t"cORANGE"Уволиться", taxi_company[TAXI_COMPANY_CITY][taxi_company_count_working]);
		    return SPD(playerid, DIALOG_SELECT_CITY_WORK, DIALOG_STYLE_TABLIST_HEADERS, !""cORANGE"«СитиМобил»", String512, !"Выбрать", !"Закрыть");
		}
	}
	return true;	
}




stock show_info_taxi_company_work(playerid, type_company)
{
	if(pData[playerid][pTaxi] != -1)
		return show_info_taxi_work(playerid, type_company);



	switch(type_company)
	{
		case TAXI_COMPANY_YANDEX:
		{
		    format(String256, sizeof(String256), "\
		    "cGREY"№\t"cGREY"Информация\n\
		    "cYELLOW"1. "cWH"Информация о «YandexGO»\t"cYELLOW"Изучить\n\
		    "cYELLOW"2. "cWH"Устройство в компанию\t"cYELLOW"Устроиться");
		    return SPD(playerid, DIALOG_SELECT_MENU_YANDEX, DIALOG_STYLE_TABLIST_HEADERS, !""cYELLOW"«YandexGO»", String256, !"Выбрать", !"Закрыть"); 
		}
		case TAXI_COMPANY_UBER:
		{
		    format(String256, sizeof(String256), "\
		    "cGREY"№\t"cGREY"Информация\n\
		    "cUBER"1. "cWH"Информация о «UBER»\t"cUBER"Изучить\n\
		    "cUBER"2. "cWH"Устройство в компанию\t"cUBER"Устроиться");
		    return SPD(playerid, DIALOG_SELECT_MENU_UBER, DIALOG_STYLE_TABLIST_HEADERS, !""cUBER"«UBER»", String256, !"Выбрать", !"Закрыть");
		}
		case TAXI_COMPANY_CITY:
		{
		    format(String256, sizeof(String256), "\
		    "cGREY"№\t"cGREY"Информация\n\
		    "cORANGE"1. "cWH"Информация о «СитиМобил»\t"cORANGE"Изучить\n\
		    "cORANGE"2. "cWH"Устройство в компанию\t"cORANGE"Устроиться");
		    return SPD(playerid, DIALOG_SELECT_MENU_CITY, DIALOG_STYLE_TABLIST_HEADERS, !""cORANGE"«СитиМобил»", String256, !"Выбрать", !"Закрыть");
		}
	}
	return true;
}


stock show_info_work_taxi(playerid, type_company)
{
	switch(type_company)
	{
		case TAXI_COMPANY_YANDEX:
		{
			SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cYELLOW"Работа в «YandexGO»", !"\
			"cYELLOW"-"cWH" Привет! Ищешь работу? Тогда приглашаем тебя в YandexGo!\n\n\
			Яндекс.Такси — это сервис, который позволяет быстро заказать машину без звонка диспетчеру\n\
			и следить за выполнением заказа на карте. \n\
			Сделать заказ можно на сайте или через мобильное приложение Яндекс Go для смартфонов. \n\
			Среднее время подачи машины — 4-5 минут.\n\
			Заказы передаются нашим партнёрам. Проверяется состояние автомобиля и его соответствие\n\
			нашим стандартам качества\n\n\
			Заинтересовала? Тогда устраивайся и работай с нами!", !"Закрыть", "");
		}
		case TAXI_COMPANY_UBER:
		{
			SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cUBER"Работа в «UBER»", !"\
			"cUBER"-"cWH" Привет! Ищешь работу? Тогда приглашаем тебя в UBER!\n\n\
			UBER — это сервис, который позволяет быстро заказать машину без звонка диспетчеру\n\
			и следить за выполнением заказа на карте. \n\
			Сделать заказ можно на сайте или через мобильное приложение UBER для смартфонов. \n\
			Среднее время подачи машины — 4-5 минут.\n\
			Заказы передаются нашим партнёрам. Проверяется состояние автомобиля и его соответствие\n\
			нашим стандартам качества\n\n\
			Заинтересовала? Тогда устраивайся и работай с нами!", !"Закрыть", "");
		}
		case TAXI_COMPANY_CITY:
		{
			SPD(playerid, DIALOG_INFO_TAXI, DIALOG_STYLE_MSGBOX, !""cORANGE"Работа в «СитиМобил»", !"\
			"cORANGE"-"cWH" Привет! Ищешь работу? Тогда приглашаем тебя в СитиМобил!\n\n\
			СитиМобил — это сервис, который позволяет быстро заказать машину без звонка диспетчеру\n\
			и следить за выполнением заказа на карте. \n\
			Сделать заказ можно на сайте или через мобильное приложение СитиМобил для смартфонов. \n\
			Среднее время подачи машины — 4-5 минут.\n\
			Заказы передаются нашим партнёрам. Проверяется состояние автомобиля и его соответствие\n\
			нашим стандартам качества\n\n\
			Заинтересовала? Тогда устраивайся и работай с нами!", !"Закрыть", "");
		}
	}
	return true;
}


stock start_work_taxi_car_final(playerid, type_company, type_tarif)
{

	if(pData[playerid][pTaxi] == -1)
		return SendErr(playerid, "Вы не работаете в Таксопарка!");


	if(taxi_company[type_company][taxi_company_count_car] == 0)
		return SendErr(playerid, "В таксопарке недостаточно автомобилей для работы!");

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

	switch(type_company)
	{
		case TAXI_COMPANY_YANDEX:
		{
			switch(type_tarif)
			{
				case TARIF_TAXI_ECONOM:
				{
					new 
						random_pos = random(13);

					new 
						c1 = 6,
						c2 = 6;	

					new 
						taxi_base_station_1 = CreateVehicle(535, position_spawn_taxi_yandex[random_pos][0], position_spawn_taxi_yandex[random_pos][1], position_spawn_taxi_yandex[random_pos][2], position_spawn_taxi_yandex[random_pos][3], c1, c2, 600);	

					ChangeVehiclePaintjob(taxi_base_station_1, 1);
					PutPlayerInVehicleEx(playerid, taxi_base_station_1, 0);

					vehicle[taxi_base_station_1][cFuel] = transport_config[GetVehicleModel(taxi_base_station_1)-400][transport_tank];
					vehicle[taxi_base_station_1][cHealth] = 1000.0;
					vehicle[taxi_base_station_1][cIsCreated] = true;
					vehicle[taxi_base_station_1][consumables_oil] = 1000.0;

					vehicle[taxi_base_station_1][cOwnTo] = VEHICLE_YANDEX;

					SetPVarIntNew(playerid, "rent_taxi_vehicle", 1);

					vehicle[taxi_base_station_1][cLock] = 2;

					vehicle_lock_status(taxi_base_station_1, true);

					new
						v = GetPlayerVehicleID(playerid);	

					pTemp[playerid][rent_car] = v;

					format(String144, sizeof(String144), "\
					"cYELLOW"«ЯндексGO»"cWH"\n\
					Эконом Такси", taxi_company[TAXI_COMPANY_YANDEX][taxi_company_price_econom]);
					vehicle[taxi_base_station_1][cLabelTaxi] = CreateDynamic3DTextLabel(String144, -1, 0.0, 0.0, 0.5, 10.0, INVALID_PLAYER_ID, taxi_base_station_1, 1);

					SetPVarIntNew(playerid, "taxi_work_tarif", TARIF_TAXI_ECONOM);

					taxi_company[TAXI_COMPANY_YANDEX][taxi_company_count_car]--;	
					taxi_company[TAXI_COMPANY_YANDEX][taxi_company_count_working]++;
				}
				case TARIF_TAXI_COMFORT:
				{
					new 
						random_pos = random(13);

					new 
						c1 = 6,
						c2 = 6;	

					new 
						taxi_base_station_2 = CreateVehicle(535, position_spawn_taxi_yandex[random_pos][0], position_spawn_taxi_yandex[random_pos][1], position_spawn_taxi_yandex[random_pos][2], position_spawn_taxi_yandex[random_pos][3], c1, c2, 600);	

					PutPlayerInVehicleEx(playerid, taxi_base_station_2, 0);
					ChangeVehiclePaintjob(taxi_base_station_2, 1);

					vehicle[taxi_base_station_2][cFuel] = transport_config[GetVehicleModel(taxi_base_station_2)-400][transport_tank];
					vehicle[taxi_base_station_2][cHealth] = 1000.0;
					vehicle[taxi_base_station_2][cIsCreated] = true;
					vehicle[taxi_base_station_2][consumables_oil] = 1000.0;

					vehicle[taxi_base_station_2][cOwnTo] = VEHICLE_YANDEX;

					SetPVarIntNew(playerid, "rent_taxi_vehicle", 1);

					vehicle[taxi_base_station_2][cLock] = 2;

					vehicle_lock_status(taxi_base_station_2, true);

					new
						v = GetPlayerVehicleID(playerid);	

					pTemp[playerid][rent_car] = v;

					format(String144, sizeof(String144), "\
					"cYELLOW"«ЯндексGO»"cWH"\n\
					Такси Комфорт", taxi_company[TAXI_COMPANY_YANDEX][taxi_company_price_comfort]);
					vehicle[taxi_base_station_2][cLabelTaxi] = CreateDynamic3DTextLabel(String144, -1, 0.0, 0.0, 0.5, 10.0, INVALID_PLAYER_ID, taxi_base_station_2, 1);

					SetPVarIntNew(playerid, "taxi_work_tarif", TARIF_TAXI_COMFORT);

					taxi_company[TAXI_COMPANY_YANDEX][taxi_company_count_car]--;	
					taxi_company[TAXI_COMPANY_YANDEX][taxi_company_count_working]++;

				}
				case TARIF_TAXI_BUISNES:
				{
					new 
						random_pos = random(13);

					new 
						c1 = 6,
						c2 = 6;	

					new 
						taxi_base_station_3 = CreateVehicle(470, position_spawn_taxi_yandex[random_pos][0], position_spawn_taxi_yandex[random_pos][1], position_spawn_taxi_yandex[random_pos][2], position_spawn_taxi_yandex[random_pos][3], c1, c2, 600);	


					PutPlayerInVehicleEx(playerid, taxi_base_station_3, 0);

					vehicle[taxi_base_station_3][cFuel] = transport_config[GetVehicleModel(taxi_base_station_3)-400][transport_tank];
					vehicle[taxi_base_station_3][cHealth] = 1000.0;
					vehicle[taxi_base_station_3][cIsCreated] = true;
					vehicle[taxi_base_station_3][consumables_oil] = 1000.0;

					vehicle[taxi_base_station_3][cOwnTo] = VEHICLE_YANDEX;

					SetPVarIntNew(playerid, "rent_taxi_vehicle", 1);

					vehicle[taxi_base_station_3][cLock] = 2;

					vehicle_lock_status(taxi_base_station_3, true);

					new
						v = GetPlayerVehicleID(playerid);	

					pTemp[playerid][rent_car] = v;

					format(String144, sizeof(String144), "\
					"cYELLOW"«ЯндексGO»"cWH"\n\
					Бизнес Такси", taxi_company[TAXI_COMPANY_YANDEX][taxi_company_price_buisnes]);
					vehicle[taxi_base_station_3][cLabelTaxi] = CreateDynamic3DTextLabel(String144, -1, 0.0, 0.0, 0.5, 10.0, INVALID_PLAYER_ID, taxi_base_station_3, 1);

					SetPVarIntNew(playerid, "taxi_work_tarif", TARIF_TAXI_BUISNES);

					taxi_company[TAXI_COMPANY_YANDEX][taxi_company_count_car]--;	
					taxi_company[TAXI_COMPANY_YANDEX][taxi_company_count_working]++;

				}
			}
		}
		case TAXI_COMPANY_CITY:
		{
			switch(type_tarif)
			{
				case TARIF_TAXI_ECONOM:
				{
					new 
						random_pos = random(13);

					new 
						c1 = 6,
						c2 = 6;	

					new 
						taxi_base_station_1 = CreateVehicle(535, position_spawn_taxi_city[random_pos][0], position_spawn_taxi_city[random_pos][1], position_spawn_taxi_city[random_pos][2], position_spawn_taxi_city[random_pos][3], c1, c2, 600);	

					ChangeVehiclePaintjob(taxi_base_station_1, 0);

					PutPlayerInVehicleEx(playerid, taxi_base_station_1, 0);

					vehicle[taxi_base_station_1][cFuel] = transport_config[GetVehicleModel(taxi_base_station_1)-400][transport_tank];
					vehicle[taxi_base_station_1][cHealth] = 1000.0;
					vehicle[taxi_base_station_1][cIsCreated] = true;
					vehicle[taxi_base_station_1][consumables_oil] = 1000.0;

					vehicle[taxi_base_station_1][cOwnTo] = VEHICLE_CITY;

					SetPVarIntNew(playerid, "rent_taxi_vehicle", 1);

					vehicle[taxi_base_station_1][cLock] = 2;

					vehicle_lock_status(taxi_base_station_1, true);

					new
						v = GetPlayerVehicleID(playerid);	

					pTemp[playerid][rent_car] = v;

					format(String144, sizeof(String144), "\
					"cORANGE"«СитиМобил»"cWH"\n\
					Эконом Такси", taxi_company[TAXI_COMPANY_CITY][taxi_company_price_econom]);
					vehicle[taxi_base_station_1][cLabelTaxi] = CreateDynamic3DTextLabel(String144, -1, 0.0, 0.0, 0.5, 10.0, INVALID_PLAYER_ID, taxi_base_station_1, 1);

					SetPVarIntNew(playerid, "taxi_work_tarif", TARIF_TAXI_ECONOM);

					taxi_company[TAXI_COMPANY_CITY][taxi_company_count_car]--;	
					taxi_company[TAXI_COMPANY_CITY][taxi_company_count_working]++;

				}
				case TARIF_TAXI_COMFORT:
				{
					new 
						random_pos = random(13);

					new 
						c1 = 6,
						c2 = 6;	

					new 
						taxi_base_station_2 = CreateVehicle(535, position_spawn_taxi_city[random_pos][0], position_spawn_taxi_city[random_pos][1], position_spawn_taxi_city[random_pos][2], position_spawn_taxi_city[random_pos][3], c1, c2, 600);	

					ChangeVehiclePaintjob(taxi_base_station_2, 0);

					PutPlayerInVehicleEx(playerid, taxi_base_station_2, 0);

					vehicle[taxi_base_station_2][cFuel] = transport_config[GetVehicleModel(taxi_base_station_2)-400][transport_tank];
					vehicle[taxi_base_station_2][cHealth] = 1000.0;
					vehicle[taxi_base_station_2][cIsCreated] = true;
					vehicle[taxi_base_station_2][consumables_oil] = 1000.0;

					vehicle[taxi_base_station_2][cOwnTo] = VEHICLE_CITY;

					SetPVarIntNew(playerid, "rent_taxi_vehicle", 1);

					vehicle[taxi_base_station_2][cLock] = 2;

					vehicle_lock_status(taxi_base_station_2, true);

					new
						v = GetPlayerVehicleID(playerid);	

					pTemp[playerid][rent_car] = v;


					format(String144, sizeof(String144), "\
					"cORANGE"«СитиМобил»"cWH"\n\
					Такси Комфорт", taxi_company[TAXI_COMPANY_CITY][taxi_company_price_comfort]);
					vehicle[taxi_base_station_2][cLabelTaxi] = CreateDynamic3DTextLabel(String144, -1, 0.0, 0.0, 0.5, 10.0, INVALID_PLAYER_ID, taxi_base_station_2, 1);

					SetPVarIntNew(playerid, "taxi_work_tarif", TARIF_TAXI_COMFORT);

					taxi_company[TAXI_COMPANY_CITY][taxi_company_count_car]--;	
					taxi_company[TAXI_COMPANY_CITY][taxi_company_count_working]++;

				}
				case TARIF_TAXI_BUISNES:
				{
					new 
						random_pos = random(13);

					new 
						c1 = 6,
						c2 = 6;	

					new 
						taxi_base_station_3 = CreateVehicle(470, position_spawn_taxi_city[random_pos][0], position_spawn_taxi_city[random_pos][1], position_spawn_taxi_city[random_pos][2], position_spawn_taxi_city[random_pos][3], c1, c2, 600);	


					PutPlayerInVehicleEx(playerid, taxi_base_station_3, 0);

					vehicle[taxi_base_station_3][cFuel] = transport_config[GetVehicleModel(taxi_base_station_3)-400][transport_tank];
					vehicle[taxi_base_station_3][cHealth] = 1000.0;
					vehicle[taxi_base_station_3][cIsCreated] = true;
					vehicle[taxi_base_station_3][consumables_oil] = 1000.0;

					vehicle[taxi_base_station_3][cOwnTo] = VEHICLE_CITY;

					SetPVarIntNew(playerid, "rent_taxi_vehicle", 1);

					vehicle[taxi_base_station_3][cLock] = 2;

					vehicle_lock_status(taxi_base_station_3, true);

					new
						v = GetPlayerVehicleID(playerid);	

					pTemp[playerid][rent_car] = v;		

					format(String144, sizeof(String144), "\
					"cORANGE"«СитиМобил»"cWH"\n\
					Бизнес Такси", taxi_company[TAXI_COMPANY_CITY][taxi_company_price_buisnes]);
					vehicle[taxi_base_station_3][cLabelTaxi] = CreateDynamic3DTextLabel(String144, -1, 0.0, 0.0, 0.5, 10.0, INVALID_PLAYER_ID, taxi_base_station_3, 1);

					SetPVarIntNew(playerid, "taxi_work_tarif", TARIF_TAXI_BUISNES);

					taxi_company[TAXI_COMPANY_CITY][taxi_company_count_car]--;	
					taxi_company[TAXI_COMPANY_CITY][taxi_company_count_working]++;

				}
			}
		}
		case TAXI_COMPANY_UBER:
		{
			switch(type_tarif)
			{
				case TARIF_TAXI_ECONOM:
				{
					new 
						random_pos = random(8);

					new 
						c1 = 6,
						c2 = 6;	

					new 
						taxi_base_station_1 = CreateVehicle(535, position_spawn_taxi_uber[random_pos][0], position_spawn_taxi_uber[random_pos][1], position_spawn_taxi_uber[random_pos][2], position_spawn_taxi_uber[random_pos][3], c1, c2, 600);	

					ChangeVehiclePaintjob(taxi_base_station_1, 2);

					PutPlayerInVehicleEx(playerid, taxi_base_station_1, 0);

					vehicle[taxi_base_station_1][cFuel] = transport_config[GetVehicleModel(taxi_base_station_1)-400][transport_tank];
					vehicle[taxi_base_station_1][cHealth] = 1000.0;
					vehicle[taxi_base_station_1][cIsCreated] = true;
					vehicle[taxi_base_station_1][consumables_oil] = 1000.0;

					vehicle[taxi_base_station_1][cOwnTo] = VEHICLE_UBER;

					vehicle[taxi_base_station_1][cLock] = 2;

					vehicle_lock_status(taxi_base_station_1, true);

					SetPVarIntNew(playerid, "rent_taxi_vehicle", 1);

					new
						v = GetPlayerVehicleID(playerid);	

					pTemp[playerid][rent_car] = v;

					format(String144, sizeof(String144), "\
					"cUBER"«UBER»"cWH"\n\
					Эконом Такси", taxi_company[TAXI_COMPANY_UBER][taxi_company_price_econom]);
					vehicle[taxi_base_station_1][cLabelTaxi] = CreateDynamic3DTextLabel(String144, -1, 0.0, 0.0, 0.5, 10.0, INVALID_PLAYER_ID, taxi_base_station_1, 1);

					SetPVarIntNew(playerid, "taxi_work_tarif", TARIF_TAXI_ECONOM);

					taxi_company[TAXI_COMPANY_UBER][taxi_company_count_car]--;	
					taxi_company[TAXI_COMPANY_UBER][taxi_company_count_working]++;

				}
				case TARIF_TAXI_COMFORT:
				{
					new 
						random_pos = random(13);

					new 
						c1 = 6,
						c2 = 6;	

					new 
						taxi_base_station_2 = CreateVehicle(535, position_spawn_taxi_uber[random_pos][0], position_spawn_taxi_uber[random_pos][1], position_spawn_taxi_uber[random_pos][2], position_spawn_taxi_uber[random_pos][3], c1, c2, 600);	

					ChangeVehiclePaintjob(taxi_base_station_2, 2);

					PutPlayerInVehicleEx(playerid, taxi_base_station_2, 0);

					vehicle[taxi_base_station_2][cFuel] = transport_config[GetVehicleModel(taxi_base_station_2)-400][transport_tank];
					vehicle[taxi_base_station_2][cHealth] = 1000.0;
					vehicle[taxi_base_station_2][cIsCreated] = true;
					vehicle[taxi_base_station_2][consumables_oil] = 1000.0;

					vehicle[taxi_base_station_2][cOwnTo] = VEHICLE_UBER;

					SetPVarIntNew(playerid, "rent_taxi_vehicle", 1);

					vehicle[taxi_base_station_2][cLock] = 2;

					vehicle_lock_status(taxi_base_station_2, true);

					new
						v = GetPlayerVehicleID(playerid);	

					pTemp[playerid][rent_car] = v;

					format(String144, sizeof(String144), "\
					"cUBER"«UBER»"cWH"\n\
					Такси Комфорт", taxi_company[TAXI_COMPANY_UBER][taxi_company_price_comfort]);
					vehicle[taxi_base_station_2][cLabelTaxi] = CreateDynamic3DTextLabel(String144, -1, 0.0, 0.0, 0.5, 10.0, INVALID_PLAYER_ID, taxi_base_station_2, 1);

					SetPVarIntNew(playerid, "taxi_work_tarif", TARIF_TAXI_COMFORT);

					taxi_company[TAXI_COMPANY_UBER][taxi_company_count_car]--;	
					taxi_company[TAXI_COMPANY_UBER][taxi_company_count_working]++;

				}
				case TARIF_TAXI_BUISNES:
				{
					new 
						random_pos = random(13);

					new 
						c1 = 6,
						c2 = 6;	

					new 
						taxi_base_station_3 = CreateVehicle(470, position_spawn_taxi_uber[random_pos][0], position_spawn_taxi_uber[random_pos][1], position_spawn_taxi_uber[random_pos][2], position_spawn_taxi_uber[random_pos][3], c1, c2, 600);	


					PutPlayerInVehicleEx(playerid, taxi_base_station_3, 0);

					vehicle[taxi_base_station_3][cFuel] = transport_config[GetVehicleModel(taxi_base_station_3)-400][transport_tank];
					vehicle[taxi_base_station_3][cHealth] = 1000.0;
					vehicle[taxi_base_station_3][cIsCreated] = true;
					vehicle[taxi_base_station_3][consumables_oil] = 1000.0;

					vehicle[taxi_base_station_3][cOwnTo] = VEHICLE_UBER;

					SetPVarIntNew(playerid, "rent_taxi_vehicle", 1);

					vehicle[taxi_base_station_3][cLock] = 2;

					vehicle_lock_status(taxi_base_station_3, true);

					new
						v = GetPlayerVehicleID(playerid);	

					pTemp[playerid][rent_car] = v;	

					format(String144, sizeof(String144), "\
					"cUBER"«UBER»"cWH"\n\
					Бизнес Такси", taxi_company[TAXI_COMPANY_UBER][taxi_company_price_buisnes]);
					vehicle[taxi_base_station_3][cLabelTaxi] = CreateDynamic3DTextLabel(String144, -1, 0.0, 0.0, 0.5, 10.0, INVALID_PLAYER_ID, taxi_base_station_3, 1);

					SetPVarIntNew(playerid, "taxi_work_tarif", TARIF_TAXI_BUISNES);

					taxi_company[TAXI_COMPANY_UBER][taxi_company_count_car]--;	
					taxi_company[TAXI_COMPANY_UBER][taxi_company_count_working]++;


				}
			}
		}
	}
	SCM(playerid, -1, "");
	SendSucc(playerid, "Вы успешно взяли в аренду автомобиль таксопарка!");
	SendInf(playerid, "Принимайте заказы и зарабатывайте деньги, актуальная информация - /gotaxi");
	SendInf(playerid, "Так же Вы можете брать заказы напрямую!");

	panel_working_td_others(playerid, TEXTDRAW_SHOW);

	SetPVarIntNew(playerid, "taxi_work_active", 1);
	SetPVarIntNew(playerid, "taxi_work_rent_car", 1);

	return true;
}


stock end_working_taxi(playerid)
{
	new 
		id_taxi = pData[playerid][pTaxi];

	if(!GetPVarIntNew(playerid, "taxi_work_active"))
		return true;

	switch(id_taxi)
	{
		case TAXI_COMPANY_YANDEX:
		{

			if(pTemp[playerid][rent_car] != INVALID_VEHICLE_ID)
			{

				new 
					v = pTemp[playerid][rent_car];

				if(v == INVALID_VEHICLE_ID) 
					return true;

				DestroyVehicle(v);
				DestroyDynamic3DTextLabel(vehicle[v][cLabelTaxi]);

				pTemp[playerid][rent_car] = INVALID_VEHICLE_ID;
				pTemp[playerid][rent_car_spawn_timer] = INVALID_TIMER_ID;

				taxi_company[TAXI_COMPANY_YANDEX][taxi_company_count_car]++;
			}

			if(taxi_company[TAXI_COMPANY_YANDEX][taxi_company_count_working] != 0)
			{
				taxi_company[TAXI_COMPANY_YANDEX][taxi_company_count_working]--;
			}
			format(String144, sizeof(String144), "[TAXI] %s закончил рабочий день!", pData[playerid][pNickname]);
			send_taxi_job(TAXI_COMPANY_YANDEX, COLOR_GREY, String144);

			DeletePVarNew(playerid, "taxi_work_tarif");
		}
		case TAXI_COMPANY_UBER:
		{
			if(pTemp[playerid][rent_car] != INVALID_VEHICLE_ID)
			{
				new 
					v = pTemp[playerid][rent_car];

				if(v == INVALID_VEHICLE_ID) 
					return true;

				DestroyVehicle(v);
				DestroyDynamic3DTextLabel(vehicle[v][cLabelTaxi]);

				pTemp[playerid][rent_car] = INVALID_VEHICLE_ID;
				pTemp[playerid][rent_car_spawn_timer] = INVALID_TIMER_ID;

				taxi_company[TAXI_COMPANY_UBER][taxi_company_count_car]++;
			}

			if(taxi_company[TAXI_COMPANY_UBER][taxi_company_count_working] != 0)
			{
				taxi_company[TAXI_COMPANY_UBER][taxi_company_count_working]--;
			}
			format(String144, sizeof(String144), "[TAXI] %s закончил рабочий день!", pData[playerid][pNickname]);
			send_taxi_job(TAXI_COMPANY_UBER, COLOR_GREY, String144);

			DeletePVarNew(playerid, "taxi_work_tarif");
		}
		case TAXI_COMPANY_CITY:
		{
			if(pTemp[playerid][rent_car] != INVALID_VEHICLE_ID)
			{
				new 
					v = pTemp[playerid][rent_car];

				if(v == INVALID_VEHICLE_ID) 
					return true;
				DestroyVehicle(v);
				DestroyDynamic3DTextLabel(vehicle[v][cLabelTaxi]);

				pTemp[playerid][rent_car] = INVALID_VEHICLE_ID;
				pTemp[playerid][rent_car_spawn_timer] = INVALID_TIMER_ID;

				taxi_company[TAXI_COMPANY_CITY][taxi_company_count_car]++;
			}

			if(taxi_company[TAXI_COMPANY_CITY][taxi_company_count_working] != 0)
			{
				taxi_company[TAXI_COMPANY_CITY][taxi_company_count_working]--;
			}
			format(String144, sizeof(String144), "[TAXI] %s закончил рабочий день!", pData[playerid][pNickname]);
			send_taxi_job(TAXI_COMPANY_CITY, COLOR_GREY, String144);

			DeletePVarNew(playerid, "taxi_work_tarif");
		}
	}
	panel_working_td_others(playerid, TEXTDRAW_HIDE);
	taxi_driver_cancel_call(playerid);
	DeletePVarNew(playerid, "taxi_work_active");
	SendSucc(playerid, "Вы закончили рабочий день таксистом!");

	return true;
}

callback:: spawn_rent_car_taxi(i, v, time)
{

	if(IsPlayerConnected(i))
	{	
		time--;

		if(!time)
		{
			end_working_taxi(i);
			return true;
		}
		pTemp[i][rent_car_spawn_timer] = SetTimerEx("spawn_rent_car_taxi", 1000, false, "iii", i, v, time);
	}
	return true;
}

stock panel_working_td_others(playerid, status)
{
	switch(status)
	{
		case TEXTDRAW_SHOW:
		{
			create_other_info_tax(playerid);

			new 
				format_str[10];

			PlayerTextDrawShow(playerid, work_tax_info_p[0][playerid]);

		 	format(format_str, sizeof(format_str),"%d", GetPVarIntNew(playerid, "get_count_client_taxi"));
		 	PlayerTextDrawSetString(playerid, work_tax_info_p[1][playerid], format_str);
		 	PlayerTextDrawShow(playerid, work_tax_info_p[1][playerid]);
		 	format(format_str, sizeof(format_str),"%d_RUB", GetPVarIntNew(playerid, "get_count_money_taxi"));
		 	PlayerTextDrawSetString(playerid, work_tax_info_p[2][playerid], format_str);
		 	PlayerTextDrawShow(playerid, work_tax_info_p[2][playerid]);

		}
		case TEXTDRAW_HIDE:
		{
			PlayerTextDrawHideEx(playerid, work_tax_info_p[0][playerid]);
			PlayerTextDrawHideEx(playerid, work_tax_info_p[1][playerid]);
			PlayerTextDrawHideEx(playerid, work_tax_info_p[2][playerid]);
		}
	}
	return true;
}

stock update_static_sesion_tax(playerid, type, count)
{
	new 
		format_str[10];

	switch(type)
	{
		case UPDATE_COUNT_CLIENT_TAXI:
		{
			SetPVarIntNew(playerid, "get_count_client_taxi", GetPVarIntNew(playerid, "get_count_client_taxi")+count);
		 	format(format_str, sizeof(format_str),"%d", GetPVarIntNew(playerid, "get_count_client_taxi"));
		 	PlayerTextDrawSetString(playerid, work_tax_info_p[1][playerid], format_str);
		 	PlayerTextDrawShow(playerid, work_tax_info_p[1][playerid]);
		}
		case UPDATE_COUNT_MONEY_TAXI:
		{
			SetPVarIntNew(playerid, "get_count_money_taxi", GetPVarIntNew(playerid, "get_count_money_taxi")+count);
		 	format(format_str, sizeof(format_str),"%d_RUB", GetPVarIntNew(playerid, "get_count_money_taxi"));
		 	PlayerTextDrawSetString(playerid, work_tax_info_p[2][playerid], format_str);
		 	PlayerTextDrawShow(playerid, work_tax_info_p[2][playerid]);			
		}
	}
	return true;
}



CMD:taxwork(playerid)
{
	if(pData[playerid][pTaxi] == -1) 
		return SendErr(playerid, "Чтобы использовать данную команду, нужно устроиться на работу");

	new
		v = GetPlayerVehicleID(playerid);	

	if(!GetPVarIntNew(playerid, "rent_taxi_vehicle"))
		return SendErr(playerid, "Вы должны находится в рабочем автомобиле!");

	new 
		type_taxi = pData[playerid][pTaxi];

	return panel_working_td_other(playerid, type_taxi, TEXTDRAW_SHOW);
}


stock panel_working_td_other(playerid, type_taxi, status)
{

	switch(status)
	{
		case TEXTDRAW_SHOW:
		{
			switch(type_taxi)
			{

				case TAXI_COMPANY_YANDEX:
				{	
					create_taxi_work_dop(playerid);

					PlayerTextDrawSetString(playerid, work_taxi_panel[0][playerid], "brilliantother:tax_work_back_3");
					PlayerTextDrawShow(playerid, work_taxi_panel[0][playerid]);

					PlayerTextDrawSetString(playerid, work_taxi_panel[1][playerid], "brilliantother:tax_work_button_5");
					PlayerTextDrawShow(playerid, work_taxi_panel[1][playerid]);

					PlayerTextDrawSetString(playerid, work_taxi_panel[2][playerid], "brilliantother:tax_work_button_6");
					PlayerTextDrawShow(playerid, work_taxi_panel[2][playerid]);

					PlayerTextDrawShow(playerid, work_taxi_panel[3][playerid]);

				}
				case TAXI_COMPANY_CITY:
				{
					create_taxi_work_dop(playerid);

					PlayerTextDrawSetString(playerid, work_taxi_panel[0][playerid], "brilliantother:tax_work_back_1");
					PlayerTextDrawShow(playerid, work_taxi_panel[0][playerid]);

					PlayerTextDrawSetString(playerid, work_taxi_panel[1][playerid], "brilliantother:tax_work_button_1");
					PlayerTextDrawShow(playerid, work_taxi_panel[1][playerid]);

					PlayerTextDrawSetString(playerid, work_taxi_panel[2][playerid], "brilliantother:tax_work_button_2");
					PlayerTextDrawShow(playerid, work_taxi_panel[2][playerid]);

					PlayerTextDrawShow(playerid, work_taxi_panel[3][playerid]);
				}
				case TAXI_COMPANY_UBER:
				{
					create_taxi_work_dop(playerid);

					PlayerTextDrawSetString(playerid, work_taxi_panel[0][playerid], "brilliantother:tax_work_back_2");
					PlayerTextDrawShow(playerid, work_taxi_panel[0][playerid]);

					PlayerTextDrawSetString(playerid, work_taxi_panel[1][playerid], "brilliantother:tax_work_button_3");
					PlayerTextDrawShow(playerid, work_taxi_panel[1][playerid]);

					PlayerTextDrawSetString(playerid, work_taxi_panel[2][playerid], "brilliantother:tax_work_button_4");
					PlayerTextDrawShow(playerid, work_taxi_panel[2][playerid]);

					PlayerTextDrawShow(playerid, work_taxi_panel[3][playerid]);
				}
			}
			SelectTextDraw(playerid, COLOR_BLUE);
		}
		case TEXTDRAW_HIDE:
		{

			PlayerTextDrawHideEx(playerid, work_taxi_panel[0][playerid]);	
			PlayerTextDrawHideEx(playerid, work_taxi_panel[1][playerid]);	
			PlayerTextDrawHideEx(playerid, work_taxi_panel[2][playerid]);	
			PlayerTextDrawHideEx(playerid, work_taxi_panel[3][playerid]);	
			CancelSelectTextDraw(playerid);
		}
	}
	return true;
}

stock start_working_taxi_other(playerid, type_working_other)
{
	switch(type_working_other)
	{
		case WORKING_TAXI_HOUSE_OTHER:
		{
			generate_random_house_taxi(playerid);
		}
		case WORKING_TAXI_PEOPLE_OTHER:
		{
			generate_random_people_taxi(playerid);
		}
	}


	return true;
}

stock final_gruz_taxi_house(playerid)
{
	printf("TUT!");

	DeletePVarNew(playerid, "active_player_gruz_taxi");

	new 
		money_final = floatround(GetPVarIntNew(playerid, "price_final_taxi_work")/0.5),
		price;

	if(get_job_level(playerid, SKILL_TAXI) == 1)
	{
		if(IsActionTrue4)  
		{
			price = money_final*2;
		}
		else if(!IsActionTrue4 && IsPlayerOnlineForBonusSalary(playerid))
		{
			price = money_final*2;
		}	
		else
		{
			price = money_final;
		}
	}
	else if(get_job_level(playerid, SKILL_TAXI) == 2)
	{
		if(IsActionTrue4)  
		{
			price = floatround(money_final*1.2)*2;
		}
		else if(!IsActionTrue4 && IsPlayerOnlineForBonusSalary(playerid))
		{
			price = floatround(money_final*1.2)*2;
		}
		else
		{
			price = floatround(money_final*1.2);
		}
	}
	else if(get_job_level(playerid, SKILL_TAXI) == 3)
	{
		if(IsActionTrue4)  
		{
			price = floatround(money_final*1.4)*2;
		}
		else if(!IsActionTrue4 && IsPlayerOnlineForBonusSalary(playerid))
		{
			price = floatround(money_final*1.4)*2;
		}
		else
		{
			price = floatround(money_final*1.4);
		}
	}
	else if(get_job_level(playerid, SKILL_TAXI) == 4)
	{
		if(IsActionTrue4)  
		{
			price = floatround(money_final*1.6)*2;
		}
		else if(!IsActionTrue4 && IsPlayerOnlineForBonusSalary(playerid))
		{
			price = floatround(money_final*1.6)*2;
		}
		else
		{
			price = floatround(money_final*1.6);
		}
	}
	else if(get_job_level(playerid, SKILL_TAXI) == 5)
	{
		if(IsActionTrue4)  
		{
			price = (money_final*2)*2;
		}
		else if(!IsActionTrue4 && IsPlayerOnlineForBonusSalary(playerid))
		{
			price = (money_final*2)*2;
		}
		else
		{
			price = money_final*2;
		}
	}

	price = price-(price/100*taxi_company[pData[playerid][pTaxi]][taxi_company_percent_1]);

	new 
		pricepercent = (price/100*taxi_company[pData[playerid][pTaxi]][taxi_company_percent_1]);

	pay_money_taxi_company(pricepercent, pData[playerid][pTaxi]);

    give_money(playerid, price, "Зарплата за доставку");

	format(String144, sizeof(String144), "Вы проехали %d метров и получили за это %d рублей! Благодарим за доставку!", GetPVarIntNew(playerid, "price_final_distance"), price);
	SendSucc(playerid, String144);
    format(String144, sizeof(String144), "Комиссия таксопарка: "cGR"%d "cWH"рублей!", pricepercent);
    SendInf(playerid, String144);

    show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_RIGHT, "brilliantother:notify_player_work_42", 4000);

	format(String144, sizeof(String144), "[TAXI] Водитель %s доставил посылку '%s' до дома!", pData[playerid][pNickname], get_name_develiry(random(15)));
	send_taxi_job(pData[playerid][pTaxi], COLOR_GREY, String144);

    update_static_sesion_tax(playerid, UPDATE_COUNT_CLIENT_TAXI, 1);
    update_static_sesion_tax(playerid, UPDATE_COUNT_MONEY_TAXI, price);

	format(String256,sizeof(String256),"UPDATE `taxi_personal` SET `user_money_day` = user_money_day+%d WHERE `user_id` = '%d'" , price, pData[playerid][pMysqlID]);
	sql_queryEx(zConn, String256, QUERY_THREADED);	
	format(String256,sizeof(String256),"UPDATE `taxi_personal` SET `user_money_all` = user_money_all+%d WHERE `user_id` = '%d'" , price, pData[playerid][pMysqlID]);
	sql_queryEx(zConn, String256, QUERY_THREADED);	

	generate_random_house_taxi(playerid);	
	return true;
}

stock generate_random_house_taxi(playerid)
{

	DeletePVarNew(playerid, "price_final_taxi_work");
	DeletePVarNew(playerid, "price_final_distance");
	DeletePVarNew(playerid, "active_player_gruz_taxi_p");

	new 
		i = random(91);

	SetPlayerCheckpoint(playerid, House[i][house_enter_x], House[i][house_enter_y], House[i][house_enter_z], 1.0);

	SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Доставка в такси", ""cWH"Позиция дома установлена у Вас на мини-карте!\n\n\
	Отправляйтесь и доставьте товар!", !"Закрыть", "");

	status_navigator_player(playerid, TEXTDRAW_SHOW);

	new 
		Float:x, 
		Float:y,
		Float:z;

	GetPlayerPos(playerid, x, y, z);

	new 
		price_work_tax = floatround(GetDistanceBetweenPoints(x, y, z, House[i][house_enter_x], House[i][house_enter_y], House[i][house_enter_z]));



	SetPVarIntNew(playerid, "price_final_distance", price_work_tax);



	SetPVarIntNew(playerid, "price_final_taxi_work", price_work_tax);

	SetPVarIntNew(playerid, "active_player_gruz_taxi", 1);
	return true;	
}

stock generate_random_people_taxi(playerid)
{

	DeletePVarNew(playerid, "price_final_taxi_work");
	DeletePVarNew(playerid, "price_final_distance");
	DeletePVarNew(playerid, "active_player_gruz_taxi_p");

	DestroyDynamic3DTextLabel(taxi_actor_text[playerid]);
	DestroyActor(taxi_actor_dynamic[playerid]);

	new 
		i = random(100);

	SetPlayerCheckpoint(playerid, position_spawn_people_taxi[i][0], position_spawn_people_taxi[i][1], position_spawn_people_taxi[i][2], 2.0);

	new 
		Float:x, 
		Float:y,
		Float:z;

	GetPlayerPos(playerid, x, y, z);

	new 
		price_work_tax = floatround(GetDistanceBetweenPoints(x, y, z, position_spawn_people_taxi[i][0], position_spawn_people_taxi[i][1], position_spawn_people_taxi[i][2]));

	taxi_actor_dynamic[playerid] = CreateActor(RandomEx(30,250), position_spawn_people_taxi[i][0], position_spawn_people_taxi[i][1], position_spawn_people_taxi[i][2], position_spawn_people_taxi[i][3]);


	switch(i)
	{
		case 24, 25, 26, 38, 63, 64, 70, 104, 105, 106, 107:
		{
			ApplyActorAnimation(taxi_actor_dynamic[playerid], "ped","SEAT_up", 4, 0, 0, 0, 0, 0);
		}
	}


	format(String144, sizeof(String144), "Ожидает доставки от водителя\n"cBLUE"%s", pData[playerid][pNickname]);
	taxi_actor_text[playerid] = CreateDynamic3DTextLabel(String144, -1, position_spawn_people_taxi[i][0], position_spawn_people_taxi[i][1], position_spawn_people_taxi[i][2], 5.0);

	SetPVarIntNew(playerid, "price_final_distance", price_work_tax);



	SetPVarIntNew(playerid, "price_final_taxi_work", price_work_tax);

	SetPVarIntNew(playerid, "active_player_gruz_taxi_p", 1);

	SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Доставка в такси", ""cWH"Позиция человека установлена у Вас на мини-карте!\n\n\
	Отправляйтесь и доставьте товар!", !"Закрыть", "");
	return true;
}


stock final_gruz_taxi_people(playerid)
{
	DeletePVarNew(playerid, "active_player_gruz_taxi");

	new 
		money_final = floatround(GetPVarIntNew(playerid, "price_final_taxi_work")/0.40),
		price;

	if(get_job_level(playerid, SKILL_TAXI) == 1)
	{
		if(IsActionTrue4 || IsPlayerOnlineForBonusSalary(playerid))  
		{
			price = money_final*2;
		}
		else
		{
			price = money_final;
		}
	}
	else if(get_job_level(playerid, SKILL_TAXI) == 2)
	{
		if(IsActionTrue4 || IsPlayerOnlineForBonusSalary(playerid))  
		{
			price = floatround(money_final*1.2)*2;
		}
		else
		{
			price = floatround(money_final*1.2);
		}
	}
	else if(get_job_level(playerid, SKILL_TAXI) == 3)
	{
		if(IsActionTrue4 || IsPlayerOnlineForBonusSalary(playerid))  
		{
			price = floatround(money_final*1.4)*2;
		}
		else
		{
			price = floatround(money_final*1.4);
		}
	}
	else if(get_job_level(playerid, SKILL_TAXI) == 4)
	{
		if(IsActionTrue4 || IsPlayerOnlineForBonusSalary(playerid))  
		{
			price = floatround(money_final*1.6)*2;
		}
		else
		{
			price = floatround(money_final*1.6);
		}
	}
	else if(get_job_level(playerid, SKILL_TAXI) == 5)
	{
		if(IsActionTrue4 || IsPlayerOnlineForBonusSalary(playerid))  
		{
			price = (money_final*2)*2;
		}
		else
		{
			price = money_final*2;
		}
	}

	price = price-(price/100*taxi_company[pData[playerid][pTaxi]][taxi_company_percent_1]);

	new 
		pricepercent = (price/100*taxi_company[pData[playerid][pTaxi]][taxi_company_percent_1]);

	pay_money_taxi_company(pricepercent, pData[playerid][pTaxi]);

    give_money(playerid, price, "Зарплата за доставку");

	format(String144, sizeof(String144), "Вы проехали %d метров и получили за это %d рублей! Благодарим за доставку!", GetPVarIntNew(playerid, "price_final_distance"), price);
	SendSucc(playerid, String144);
    format(String144, sizeof(String144), "Комиссия таксопарка: "cGR"%d "cWH"рублей!", pricepercent);
    SendInf(playerid, String144);

    show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_RIGHT, "brilliantother:notify_player_work_43", 4000);


	format(String256,sizeof(String256),"UPDATE `taxi_personal` SET `user_money_day` = user_money_day+%d WHERE `user_id` = '%d'" , price, pData[playerid][pMysqlID]);
	sql_queryEx(zConn, String256, QUERY_THREADED);	
	format(String256,sizeof(String256),"UPDATE `taxi_personal` SET `user_money_all` = user_money_all+%d WHERE `user_id` = '%d'" , price, pData[playerid][pMysqlID]);
	sql_queryEx(zConn, String256, QUERY_THREADED);	

	format(String144, sizeof(String144), "[TAXI] Водитель %s доставил посылку '%s' до клиента!", pData[playerid][pNickname], get_name_develiry(random(15)));
	send_taxi_job(pData[playerid][pTaxi], COLOR_GREY, String144);

    update_static_sesion_tax(playerid, UPDATE_COUNT_CLIENT_TAXI, 1);
    update_static_sesion_tax(playerid, UPDATE_COUNT_MONEY_TAXI, price);

    DestroyActor(taxi_actor_dynamic[playerid]);
    DestroyDynamic3DTextLabel(taxi_actor_text[playerid]);

	generate_random_people_taxi(playerid);	
	return true;
}