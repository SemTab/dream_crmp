

static const trucker_rank_name[][] =
{	
	"Отсутствует",
    "Дальнобойщик",
    "Управляющий",
    "Владелец",
    "Рак Заморский"
};

static const mounth_trucker_stats[][] =
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


static const Float:position_spawn_trucker_1[][] =
{
	{2257.9583,-933.5723,14.0136,359.9615},
	{2247.1514,-933.6605,14.0103,358.5665},
	{2236.3352,-933.5306,14.0132,0.5920},
	{2225.6045,-933.3782,14.0188,1.4066},
	{2215.1443,-933.5498,14.0171,359.9470},
	{2198.9121,-935.6592,14.0114,0.0462},
	{2188.2083,-935.5779,14.0082,359.9841},
	{2177.3108,-935.4380,14.0084,0.0619},
	{2166.5498,-935.3475,14.0093,0.5011},
	{2155.4695,-935.4337,14.0149,0.0853},
	{2144.3867,-935.6403,14.0090,1.3156},
	{2134.4158,-935.5936,14.0104,359.1941},
	{2117.7629,-896.1642,14.0069,180.0242},
	{2128.4631,-894.8182,14.0065,179.9158},
	{2139.4690,-894.6691,14.0090,180.1934},
	{2150.0327,-894.8989,14.0076,179.3404},
	{2161.0649,-894.7355,14.0090,179.9799},
	{2171.6541,-895.0988,14.0066,179.9625},
	{2182.7942,-894.8418,14.0060,180.5809}


};

static const Float:position_spawn_trucker_2[][] =
{
	{1905.6626,2847.3596,12.6053,358.7965},
	{1894.6429,2846.8411,12.6092,359.9872},
	{1883.9108,2846.8379,12.6039,358.7520},
	{1873.2455,2846.8059,12.5985,0.2474},
	{1862.2899,2846.8784,12.5984,359.8861},
	{1846.6311,2845.0754,12.6008,359.0035},
	{1835.4733,2844.9436,12.6020,358.9612},
	{1824.5331,2845.0564,12.6017,0.8110},
	{1813.8583,2845.0684,12.5988,1.3391},
	{1803.0411,2844.9365,12.5968,2.7801},
	{1792.6563,2845.3877,12.5958,358.5348},
	{1781.8774,2845.1887,12.5993,359.2439},
	{1767.5327,2888.1763,12.5960,180.8978},
	{1778.2094,2888.2966,12.5951,180.1128},
	{1788.8951,2888.1274,12.5935,178.8645},
	{1799.8391,2888.2263,12.5952,182.2955},
	{1810.6455,2888.1880,12.5962,179.8151},
	{1821.5901,2888.0933,12.5987,180.7401},
	{1832.4805,2888.2751,12.6008,182.5305}


};

static const Float:position_spawn_trucker_3[][] =
{
	{-2547.0730,-10.8756,13.3765,171.3195},
	{-2536.3564,-12.7943,13.3715,171.9104},
	{-2525.8093,-14.3558,13.3744,170.2615},
	{-2514.9785,-16.4898,13.3798,172.3701},
	{-2504.4775,-18.1312,13.3761,171.8798},
	{-2488.8386,-18.8951,13.3766,169.9020},
	{-2478.2271,-20.9125,13.3843,167.2278},
	{-2467.3218,-22.9022,13.3870,170.3264},
	{-2456.7007,-24.5032,13.3818,170.0476},
	{-2445.6985,-26.6355,13.3809,172.3928},
	{-2435.1216,-28.4612,13.3834,171.4377},
	{-2424.2400,-30.1814,13.3787,169.9522},
	{-2415.3696,-73.4242,13.3750,345.2384},
	{-2426.0630,-71.0855,13.3734,346.6260},
	{-2437.0364,-69.1693,13.3732,351.1822},
	{-2447.3882,-67.6223,13.3731,349.9878},
	{-2458.0376,-65.5937,13.3768,349.6441},
	{-2468.4707,-63.8061,13.3805,347.3944},
	{-2479.5627,-62.0725,13.3795,350.9845}



};


static const get_truck_veh_level[][] =
{	
	"Отсутствует",
    "Низкий (MAN и Mersedes Фургоны)",
    "Средний (МАЗ)",
    "Высокий (DAF)"
};

stock get_trucker_veh_color(type)
{

	new 
		name[40];

	switch(type)
	{
		case 0: name = "{000000}Текущий цвет";
		case 1: name = "{FDF5CC}Текущий цвет";
		case 3: name = "{962E30}Текущий цвет";
		case 6: name = "{EAA337}Текущий цвет";
		case 5: name = "{9B616F}Текущий цвет";
		case 16: name = "{55784F}Текущий цвет";
		case 79: name = "{36546E}Текущий цвет";
		case 106: name = "{439ADE}Текущий цвет";
		default: name = "Неизвестно";
	}
	return name;
}

callback:: load_trucker_server()
{

	new Result:trucker_load_station = sql_queryEx(zConn, "SELECT * FROM `trucker` ORDER BY `trucker_id`", QUERY_CACHED);

	new all_trucker_station = sql_num_rows(trucker_load_station);

	new time = GetTickCount();

	new 
		load_trucker; 

 	for(new i; i < all_trucker_station; i++)
	{

		trucker_station[i][trucker_base_id]  = sql_get_field_assoc_int_ex(trucker_load_station, i, "trucker_id"); 


		sql_get_field_assoc_ex(trucker_load_station, i,"trucker_base_name", trucker_station[i][trucker_base_name], 20);

		trucker_station[i][trucker_base_owner_id]  = sql_get_field_assoc_int_ex(trucker_load_station, i, "trucker_owner_id"); 
		trucker_station[i][trucker_low_owner_id]  = sql_get_field_assoc_int_ex(trucker_load_station, i, "trucker_low_owner_id"); 
		
		trucker_station[i][trucker_base_price]  = sql_get_field_assoc_int_ex(trucker_load_station, i, "trucker_base_price"); 
		trucker_station[i][trucker_base_closed]  = sql_get_field_assoc_int_ex(trucker_load_station, i, "trucker_base_closed"); 
		trucker_station[i][trucker_base_days]  = sql_get_field_assoc_int_ex(trucker_load_station, i, "trucker_base_days"); 
		trucker_station[i][trucker_base_bank]  = sql_get_field_assoc_int_ex(trucker_load_station, i, "trucker_base_bank"); 	

		trucker_station[i][trucker_sell_day_payday]  = sql_get_field_assoc_int_ex(trucker_load_station, i, "trucker_sell_day_payday"); 
		trucker_station[i][trucker_status_sell]  = sql_get_field_assoc_int_ex(trucker_load_station, i, "trucker_status_sell"); 	

		trucker_station[i][trucker_base_percent]  = sql_get_field_assoc_int_ex(trucker_load_station, i, "trucker_base_percent"); 	
		trucker_station[i][trucker_base_car_count]  = sql_get_field_assoc_int_ex(trucker_load_station, i, "trucker_base_car_count"); 

		trucker_station[i][trucker_base_finka_day]  = sql_get_field_assoc_int_ex(trucker_load_station, i, "trucker_base_finka_day"); 	
		trucker_station[i][trucker_base_finka_ogran]  = sql_get_field_assoc_int_ex(trucker_load_station, i, "trucker_base_finka_ogran"); 


		trucker_station[i][trucker_block_percent]  = sql_get_field_assoc_int_ex(trucker_load_station, i, "trucker_block_percent"); 	
		trucker_station[i][trucker_block_uninvite]  = sql_get_field_assoc_int_ex(trucker_load_station, i, "trucker_block_uninvite"); 
		trucker_station[i][trucker_block_bank]  = sql_get_field_assoc_int_ex(trucker_load_station, i, "trucker_block_bank"); 

		trucker_station[i][trucker_veh_count]  = sql_get_field_assoc_int_ex(trucker_load_station, i, "trucker_veh_count"); 
		trucker_station[i][trucker_person_count]  = sql_get_field_assoc_int_ex(trucker_load_station, i, "trucker_person_count"); 
		trucker_station[i][trucker_level_veh]  = sql_get_field_assoc_int_ex(trucker_load_station, i, "trucker_level_veh"); 
		trucker_station[i][trucker_car_color]  = sql_get_field_assoc_int_ex(trucker_load_station, i, "trucker_car_color"); 

  		trucker_station[i][trucker_pos_x] = sql_get_field_assoc_float_ex(trucker_load_station, i, "trucker_pos_x");
  		trucker_station[i][trucker_pos_y] = sql_get_field_assoc_float_ex(trucker_load_station, i, "trucker_pos_y");
  		trucker_station[i][trucker_pos_z] = sql_get_field_assoc_float_ex(trucker_load_station, i, "trucker_pos_z");

		trucker_station[i][trucker_base_icon] = CreateDynamicMapIcon(trucker_station[i][trucker_pos_x], trucker_station[i][trucker_pos_y], trucker_station[i][trucker_pos_z], 51 , -1);

		trucker_station[i][trucker_base_pickup] = create_circle_pickup(trucker_station[i][trucker_pos_x], trucker_station[i][trucker_pos_y], trucker_station[i][trucker_pos_z], TRIGGER_LBLUE);

		trucker_count_truck[i] = trucker_station[i][trucker_veh_count];

		load_trucker++;

	}



	printf("[Транспортные Компании]: <%i из %i>. Времени затрачено: <%d мс>" , all_trucker_station, load_trucker, GetTickCount()-  time);

	create_trucker_3d_text();
	create_trucker_box_rep();

	sql_next_row(trucker_load_station);

	return true;
}

stock sell_trucker_payday(f)
{

	if(trucker_station[f][trucker_base_days] == 0 && trucker_station[f][trucker_base_owner_id] != -1)
		return printf("[ДАЛЬНОБОИ PAYDAY СЛЕТ] %d (%d) - оплачено | %d - владелец",f, trucker_station[f][trucker_base_days], trucker_station[f][trucker_base_owner_id]);

	new 
		owner_id = trucker_station[f][trucker_base_owner_id];

	new 
		owner_garage_name[32];


	GetPlayerNameByID(owner_id, owner_garage_name);

	new 
		player_id = GetPlayerID(owner_garage_name);	

	new 
		final_money = floatround(trucker_station[f][trucker_base_price]*0.8);


	if(IsPlayerConnected(player_id))
	{
		if(pData[player_id][pTruckerOwnerID] == f)
		{	

			pData[player_id][pTruckerOwnerID] = -1;
			UpdatePlayerData(player_id,"pTruckerOwnerID", pData[player_id][pTruckerOwnerID]);
			SFCM(player_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Ваше ТК было продано за неуплату!");	

	        SendClientMessage(player_id, COLOR_LIGHTRED, "Вы можете вернуть 80 процентов от стоимости имущества");
	        SendClientMessage(player_id, COLOR_LIGHTRED, "Для этого введите команду /returnmoney");


			pData[player_id][pTrucker] = -1;
			pData[player_id][pTruckerOwnerLowID] = -1;
			pData[player_id][pTruckerRank] = 0;
			pData[player_id][pJob] = 0;

			UpdatePlayerData(player_id,"pTrucker", pData[player_id][pTrucker]);
			UpdatePlayerData(player_id,"pTruckerOwnerLowID", pData[player_id][pTruckerOwnerLowID]);
			UpdatePlayerData(player_id,"pTruckerRank", pData[player_id][pTruckerRank]);

			format(String256,sizeof(String256),"DELETE FROM `trucker_personal` WHERE `user_id` = '%d'", owner_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);

			format(String256,sizeof(String256),"UPDATE `accounts` SET `pTrucker` = '-1', `pTruckerOwnerLowID` = '-1', `job` = '0'  WHERE `id` = '%i'", owner_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);


	        pData[player_id][pReturnMoney] += final_money;
	        if(pData[player_id][pReturnMoney] > 20000000 ) pData[player_id][pReturnMoney] = 0;
		}
	}
	else
	{	
		new 
			formate_str[280];

		format(formate_str, 80, "UPDATE accounts SET pTruckerOwnerID = '-1' WHERE pTruckerOwnerID = '%d'", f);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	

		format(String256,sizeof(String256),"UPDATE `accounts` SET returnmoney = returnmoney + %d WHERE id = '%i'", final_money, owner_id);
		sql_queryEx(zConn, String256, QUERY_THREADED);


		format(String256,sizeof(String256),"DELETE FROM `trucker_personal` WHERE `user_id` = '%d'", owner_id);
		sql_queryEx(zConn, String256, QUERY_THREADED);

		format(String256,sizeof(String256),"UPDATE `accounts` SET `pTrucker` = '-1', `pTruckerOwnerLowID` = '-1', `job` = '0'  WHERE `id` = '%i'", owner_id);
		sql_queryEx(zConn, String256, QUERY_THREADED);

		send_off_message(-1, owner_garage_name, "Ваша ТК было продано государству за неуплату. Мы вернули 80 процентов (/returnmoney)");
	}




	trucker_station[f][trucker_base_owner_id] = -1;	
	trucker_station[f][trucker_base_bank] = 0;

	trucker_station[f][trucker_status_sell] = 3;
	trucker_station[f][trucker_sell_day_payday] = RandomEx(2, 22);	

	save_trucker_base();
	update_trucker_3d_text();
	return true;
}
 
stock create_trucker_box_rep()
{

	actor_trucker[0] = CreateActor(32, 1870.4514,2895.5906,12.5645,93.2530);
	ApplyActorAnimation(actor_trucker[0], "COP_AMBIENT", "coplook_loop", 4.1, 1, 1, 1, 0, 0);

	actor_trucker[1] = CreateActor(32, 2222.9468,-886.5164,13.9766,91.3954);
	ApplyActorAnimation(actor_trucker[1], "COP_AMBIENT", "coplook_loop", 4.1, 1, 1, 1, 0, 0);

	actor_trucker[2] = CreateActor(32, -2520.9836,-64.3470,13.3416,261.7675);
	ApplyActorAnimation(actor_trucker[2], "COP_AMBIENT", "coplook_loop", 4.1, 1, 1, 1, 0, 0);


  	CreateDynamic3DTextLabel(""cWH"Работа Дальнобойщиком\n "cBLUE"Информация",-1, \
  		1869.5455,2895.5625,12.5645, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
	CreateDynamicPickup(1275, 23, 1869.5455,2895.5625,12.5645, -1, -1, -1, 15.0);

  	CreateDynamic3DTextLabel(""cWH"Работа Дальнобойщиком\n "cBLUE"Информация",-1, \
  		2222.2012,-886.5297,13.9766, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
	CreateDynamicPickup(1275, 23, 2222.2012,-886.5297,13.9766, -1, -1, -1, 15.0);

  	CreateDynamic3DTextLabel(""cWH"Работа Дальнобойщиком\n "cBLUE"Информация",-1, \
  		-2520.0989,-64.4551,13.3416, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
	CreateDynamicPickup(1275, 23, -2520.0989,-64.4551,13.3416, -1, -1, -1, 15.0);

	trucker_skin_pickup[0] = CreateDynamicSphere(1869.5455,2895.5625,12.5645, 1.0, -1, -1, -1);
	trucker_skin_pickup[1] = CreateDynamicSphere(2222.2012,-886.5297,13.9766, 1.0, -1, -1, -1);
	trucker_skin_pickup[2] = CreateDynamicSphere(-2520.0989,-64.4551,13.3416, 1.0, -1, -1, -1);


	no_collizion_zone_trucker[0] = CreateDynamicSphere(1849.1874,2866.8835,12.5645, 100.0, -1, -1, -1);	// База 1
	no_collizion_zone_trucker[1] = CreateDynamicSphere(2200.8376,-916.1137,13.9841, 100.0, -1, -1, -1);	// База 2
	no_collizion_zone_trucker[2] = CreateDynamicSphere(-2495.0759,-43.1420,13.3416, 100.0, -1, -1, -1);	// База 3

	no_collizion_zone_trucker[3] = CreateDynamicSphere(-1427.4973,2593.1536,40.7841, 50.0, -1, -1, -1);	// Шахта
	no_collizion_zone_trucker[4] = CreateDynamicSphere(2766.3589,-2384.2488,21.9642, 30.0, -1, -1, -1);	// Завод
	no_collizion_zone_trucker[5] = CreateDynamicSphere(2491.6013,-649.1737,12.2062, 30.0, -1, -1, -1);	// Склад продуктов
	no_collizion_zone_trucker[6] = CreateDynamicSphere(-1946.6432,-2637.7834,7.7242, 30.0, -1, -1, -1);	// Нефтебаза

	no_collizion_zone_trucker[7] = CreateDynamicSphere(-1050.5479,-2476.2861,28.5196, 30.0, -1, -1, -1);	// Нефтебаза


  	CreateDynamic3DTextLabel(""cWH"Загрузка дальнобойщиков\n "cBLUE"[Нажмите на гудок]",-1, \
  		TRUCKER_ZAVOD_LOAD, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
  	CreateDynamic3DTextLabel(""cWH"Загрузка дальнобойщиков\n "cBLUE"[Нажмите на гудок]",-1, \
  		TRUCKER_SHOP_LOAD, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
  	CreateDynamic3DTextLabel(""cWH"Загрузка дальнобойщиков\n "cBLUE"[Нажмите на гудок]",-1, \
  		TRUCKER_FUEL_LOAD, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
  	CreateDynamic3DTextLabel(""cWH"Загрузка дальнобойщиков\n "cBLUE"[Нажмите на гудок]",-1, \
  		TRUCKER_SAMWILL_LOAD, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
  	CreateDynamic3DTextLabel(""cWH"Разгрузка дальнобойщиков\n "cBLUE"[Нажмите на гудок]",-1, \
  		TRUCKER_MINER_UNLOAD, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
  	CreateDynamic3DTextLabel(""cWH"Разгрузка дальнобойщиков\n "cBLUE"[Нажмите на гудок]",-1, \
  		TRUCKER_ZAVOD_UNLOAD, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);

	return true;
}

stock save_trucker_base()
{
	static
		mech_name_str[20];

	for(new i; i < MAX_TRUCKER_BASE; i++)
	{

		format(mech_name_str, 20, "%e", trucker_station[i][trucker_base_name]);

		format(String2048, sizeof(String2048), "\
			UPDATE trucker SET \
			trucker_owner_id = '%d', \
			trucker_low_owner_id = '%d', \
			trucker_base_price = '%d', \
			trucker_base_closed = '%d', \
			trucker_base_days = '%d', \
			trucker_base_bank = '%d', \
			trucker_base_percent = '%d', \
			trucker_veh_count = '%d', \
			trucker_block_percent = '%d', \
			trucker_block_uninvite = '%d', \
			trucker_block_bank = '%d', \
			trucker_person_count = '%d', \
			trucker_level_veh = '%d', \
			trucker_car_color = '%d' \
			WHERE trucker_id = '%d'",

			trucker_station[i][trucker_base_owner_id],
			trucker_station[i][trucker_low_owner_id],
			trucker_station[i][trucker_base_price],
			trucker_station[i][trucker_base_closed],
			trucker_station[i][trucker_base_days],
			trucker_station[i][trucker_base_bank],
			trucker_station[i][trucker_base_percent],
			trucker_station[i][trucker_veh_count],

			trucker_station[i][trucker_block_percent],
			trucker_station[i][trucker_block_uninvite],
			trucker_station[i][trucker_block_bank],

			trucker_station[i][trucker_person_count],
			trucker_station[i][trucker_level_veh],
			trucker_station[i][trucker_car_color],
			i);

		sql_queryEx(zConn, String2048, QUERY_THREADED);	
	}
	return true;
}

stock create_trucker_3d_text()
{

	new
		owner[24], ownerr[24];

	if(trucker_station[0][trucker_base_owner_id] != -1)
	{
		GetPlayerNameByID(trucker_station[0][trucker_base_owner_id], trucker_station[0][trucker_base_owner]);
		format(owner, 24, trucker_station[0][trucker_base_owner]);
	}
	else
	{
		format(owner, 24, "Государство");	
	}

	if(trucker_station[0][trucker_low_owner_id] != -1)
	{
		GetPlayerNameByID(trucker_station[0][trucker_low_owner_id], trucker_station[0][trucker_low_owner]);
		format(ownerr, 24, trucker_station[0][trucker_low_owner]);
	}
	else
	{
		format(ownerr, 24, "Государство");	
	}

	format(String1024, sizeof(String1024), "\
		Транспортная Компания №%d\n\
		"cBLUE"«%s»\n\n\
		"cWH"Владелец: "cBLUE"%s\n\
		"cWH"Заместитель: "cBLUE"%s\n\n\
		\t"cBLUE"Остальная информация:\n\n\
		"cWH"Статус компании: %s",
		trucker_station[0][trucker_base_id]+1,
		trucker_station[0][trucker_base_name],
		owner,ownerr,
		(trucker_station[0][trucker_base_closed]) ? (""cGR"Работает") : (""cLRED"Закрыта"));

	trucker_station[0][trucker_base_pick_info] = CreateDynamic3DTextLabel(String1024, -1, trucker_station[0][trucker_pos_x], trucker_station[0][trucker_pos_y], trucker_station[0][trucker_pos_z]+1.0, 20.0);

	if(trucker_station[1][trucker_base_owner_id] != -1)
	{
		GetPlayerNameByID(trucker_station[1][trucker_base_owner_id], trucker_station[1][trucker_base_owner]);
		format(owner, 24, trucker_station[1][trucker_base_owner]);
	}
	else
	{
		format(owner, 24, "Государство");	
	}

	if(trucker_station[1][trucker_low_owner_id] != -1)
	{
		GetPlayerNameByID(trucker_station[1][trucker_low_owner_id], trucker_station[1][trucker_low_owner]);
		format(ownerr, 24, trucker_station[1][trucker_low_owner]);
	}
	else
	{
		format(ownerr, 24, "Государство");	
	}


	format(String1024, sizeof(String1024), "\
		Транспортная Компания №%d\n\
		"cBLUE"«%s»\n\n\
		"cWH"Владелец: "cBLUE"%s\n\
		"cWH"Заместитель: "cBLUE"%s\n\n\
		\t"cBLUE"Остальная информация:\n\n\
		"cWH"Статус компании: %s",
		trucker_station[1][trucker_base_id]+1,
		trucker_station[1][trucker_base_name],
		owner,ownerr,
		(trucker_station[1][trucker_base_closed]) ? (""cGR"Работает") : (""cLRED"Закрыта"));

	trucker_station[1][trucker_base_pick_info] = CreateDynamic3DTextLabel(String1024, -1, trucker_station[1][trucker_pos_x], trucker_station[1][trucker_pos_y], trucker_station[1][trucker_pos_z]+1.0, 20.0);
	

	if(trucker_station[2][trucker_base_owner_id] != -1)
	{
		GetPlayerNameByID(trucker_station[2][trucker_base_owner_id], trucker_station[2][trucker_base_owner]);
		format(owner, 24, trucker_station[2][trucker_base_owner]);
	}
	else
	{
		format(owner, 24, "Государство");	
	}

	if(trucker_station[2][trucker_low_owner_id] != -1)
	{
		GetPlayerNameByID(trucker_station[2][trucker_low_owner_id], trucker_station[2][trucker_low_owner]);
		format(ownerr, 24, trucker_station[2][trucker_low_owner]);
	}
	else
	{
		format(ownerr, 24, "Государство");	
	}

	format(String1024, sizeof(String1024), "\
		Транспортная Компания №%d\n\
		"cBLUE"«%s»\n\n\
		"cWH"Владелец: "cBLUE"%s\n\
		"cWH"Заместитель: "cBLUE"%s\n\n\
		\t"cBLUE"Остальная информация:\n\n\
		"cWH"Статус компании: %s",
		trucker_station[2][trucker_base_id]+1,
		trucker_station[2][trucker_base_name],
		owner,ownerr,
		(trucker_station[2][trucker_base_closed]) ? (""cGR"Работает") : (""cLRED"Закрыта"));

	trucker_station[2][trucker_base_pick_info] = CreateDynamic3DTextLabel(String1024, -1, trucker_station[2][trucker_pos_x], trucker_station[2][trucker_pos_y], trucker_station[2][trucker_pos_z]+1.0, 20.0);
	
	return true;
}



stock update_trucker_3d_text()
{

	new
		owner[24], ownerr[24];

	if(trucker_station[0][trucker_base_owner_id] != -1)
	{
		GetPlayerNameByID(trucker_station[0][trucker_base_owner_id], trucker_station[0][trucker_base_owner]);
		format(owner, 24, trucker_station[0][trucker_base_owner]);
	}
	else
	{
		format(owner, 24, "Государство");	
	}

	if(trucker_station[0][trucker_low_owner_id] != -1)
	{
		GetPlayerNameByID(trucker_station[0][trucker_low_owner_id], trucker_station[0][trucker_low_owner]);
		format(ownerr, 24, trucker_station[0][trucker_low_owner]);
	}
	else
	{
		format(ownerr, 24, "Государство");	
	}


	format(String1024, sizeof(String1024), "\
		Транспортная Компания №%d\n\
		"cBLUE"«%s»\n\n\
		"cWH"Владелец: "cBLUE"%s\n\
		"cWH"Заместитель: "cBLUE"%s\n\n\
		\t"cBLUE"Остальная информация:\n\n\
		"cWH"Статус компании: %s",
		trucker_station[0][trucker_base_id]+1,
		trucker_station[0][trucker_base_name],
		owner, ownerr,
		(trucker_station[0][trucker_base_closed]) ? (""cGR"Работает") : (""cLRED"Закрыта"));

	UpdateDynamic3DTextLabelText(trucker_station[0][trucker_base_pick_info], -1, String1024);


	if(trucker_station[0][trucker_status_sell] == 3)
	{
		format(String1024, sizeof(String1024), "\
			Транспортная Компания №%d\n\
			"cBLUE"«%s»\n\n\
			"cBLUE"«Транспортная Компания опечатана»\n\n\
			"cWH"Владелец: "cBLUE"%s\n\
			"cWH"Заместитель: "cBLUE"%s\n\n\
			\t"cBLUE"Остальная информация:\n\n\
			"cWH"Статус компании: %s",
			trucker_station[0][trucker_base_id]+1,
			trucker_station[0][trucker_base_name],
			owner, ownerr,
			(trucker_station[0][trucker_base_closed]) ? (""cGR"Работает") : (""cLRED"Закрыта"));

		UpdateDynamic3DTextLabelText(trucker_station[0][trucker_base_pick_info], -1, String1024);


	}

	if(trucker_station[1][trucker_base_owner_id] != -1)
	{
		GetPlayerNameByID(trucker_station[1][trucker_base_owner_id], trucker_station[1][trucker_base_owner]);
		format(owner, 24, trucker_station[1][trucker_base_owner]);
	}
	else
	{
		format(owner, 24, "Государство");	
	}

	if(trucker_station[1][trucker_low_owner_id] != -1)
	{
		GetPlayerNameByID(trucker_station[1][trucker_low_owner_id], trucker_station[1][trucker_low_owner]);
		format(ownerr, 24, trucker_station[1][trucker_low_owner]);
	}
	else
	{
		format(ownerr, 24, "Государство");	
	}


	format(String1024, sizeof(String1024), "\
		Транспортная Компания №%d\n\
		"cBLUE"«%s»\n\n\
		"cWH"Владелец: "cBLUE"%s\n\
		"cWH"Заместитель: "cBLUE"%s\n\n\
		\t"cBLUE"Остальная информация:\n\n\
		"cWH"Статус компании: %s",
		trucker_station[1][trucker_base_id]+1,
		trucker_station[1][trucker_base_name],
		owner,ownerr,
		(trucker_station[1][trucker_base_closed]) ? (""cGR"Работает") : (""cLRED"Закрыта"));

	UpdateDynamic3DTextLabelText(trucker_station[1][trucker_base_pick_info], -1, String1024);

	if(trucker_station[1][trucker_status_sell] == 3)
	{
		format(String1024, sizeof(String1024), "\
			Транспортная Компания №%d\n\
			"cBLUE"«%s»\n\n\
			"cBLUE"«Транспортная Компания опечатана»\n\n\
			"cWH"Владелец: "cBLUE"%s\n\
			"cWH"Заместитель: "cBLUE"%s\n\n\
			\t"cBLUE"Остальная информация:\n\n\
			"cWH"Статус компании: %s",
			trucker_station[1][trucker_base_id]+1,
			trucker_station[1][trucker_base_name],
			owner,
			(trucker_station[1][trucker_base_closed]) ? (""cGR"Работает") : (""cLRED"Закрыта"));

		UpdateDynamic3DTextLabelText(trucker_station[1][trucker_base_pick_info], -1, String1024);
	}


	if(trucker_station[2][trucker_base_owner_id] != -1)
	{
		GetPlayerNameByID(trucker_station[2][trucker_base_owner_id], trucker_station[2][trucker_base_owner]);
		format(owner, 24, trucker_station[2][trucker_base_owner]);
	}
	else
	{
		format(owner, 24, "Государство");	
	}

	if(trucker_station[2][trucker_low_owner_id] != -1)
	{
		GetPlayerNameByID(trucker_station[2][trucker_low_owner_id], trucker_station[2][trucker_low_owner]);
		format(ownerr, 24, trucker_station[2][trucker_low_owner]);
	}
	else
	{
		format(ownerr, 24, "Государство");	
	}



	format(String1024, sizeof(String1024), "\
		Транспортная Компания №%d\n\
		"cBLUE"«%s»\n\n\
		"cWH"Владелец: "cBLUE"%s\n\
		"cWH"Заместитель: "cBLUE"%s\n\n\
		\t"cBLUE"Остальная информация:\n\n\
		"cWH"Статус компании: %s",
		trucker_station[2][trucker_base_id]+1,
		trucker_station[2][trucker_base_name],
		owner,ownerr,
		(trucker_station[2][trucker_base_closed]) ? (""cGR"Работает") : (""cLRED"Закрыта"));

	UpdateDynamic3DTextLabelText(trucker_station[2][trucker_base_pick_info], -1, String1024);

	if(trucker_station[2][trucker_status_sell] == 3)
	{

		format(String1024, sizeof(String1024), "\
			Транспортная Компания №%d\n\
			"cBLUE"«%s»\n\n\
			"cBLUE"«Транспортная Компания опечатана»\n\n\
			"cWH"Владелец: "cBLUE"%s\n\
			"cWH"Заместитель: "cBLUE"%s\n\n\
			\t"cBLUE"Остальная информация:\n\n\
			"cWH"Статус компании: %s",
			trucker_station[2][trucker_base_id]+1,
			trucker_station[2][trucker_base_name],
			owner,ownerr,
			(trucker_station[2][trucker_base_closed]) ? (""cGR"Работает") : (""cLRED"Закрыта"));

		UpdateDynamic3DTextLabelText(trucker_station[2][trucker_base_pick_info], -1, String1024);

	}

	return true;
}



stock show_trucker_station_menu(playerid, type)
{
	if(trucker_station[type][trucker_base_owner_id] == -1)
		return show_trucker_station_buy(playerid, type);


	return show_trucker_menu(playerid, type);
}

stock show_trucker_station_buy(playerid, type)
{

	if(pData[playerid][pBusiness] != -1)
		return SendErr(playerid, "У вас уже есть бизнес");

	new
		owner[24];

	if(trucker_station[type][trucker_base_owner_id] != -1)
	{
		GetPlayerNameByID(trucker_station[type][trucker_base_owner_id], trucker_station[type][trucker_base_owner]);
		format(owner, 24, trucker_station[type][trucker_base_owner]);
	}
	else
	{
		format(owner, 24, "Государство");	
	}

	SetPVarIntNew(playerid, "id_buy_trucker_base", type);

	format(String512, sizeof(String512), "\
	"cWH"Название: \t\t\t\t "cBLUE"%s\n\
	"cWH"Владелец: \t\t\t\t "cBLUE"%s\n\
	"cWH"Статус: \t\t\t\t\t %s\n\
	"cWH"Цена: \t\t\t\t\t "cGR"%d руб\n\n\
	"cWH"Вы действительно хотите приобрести ТК?",
	trucker_station[type][trucker_base_name],
	owner,
	(trucker_station[type][trucker_base_closed]) ? (""cGR"Работает") : (""cLRED"Закрыта"),
	trucker_station[type][trucker_base_price]);

	SPD(playerid, DIALOG_BUY_TRUCKER, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка ТК", String512, !"Купить", !"Закрыть");


	return true;
}

stock change_name_trucker(playerid)
{


	return true;
}

stock show_trucker_menu(playerid, type)
{

	if(pData[playerid][pTruckerOwnerID] == type)
	{
		return show_trucker_menu_change(playerid, type);
	}

	if(pData[playerid][pTruckerOwnerLowID] == type)
		return show_trucker_menu_zam(playerid, type);

	return true;
}

stock show_trucker_menu_zam(playerid, type)
{


	if(pData[playerid][pTruckerOwnerLowID] != type)
		return true;


    format(String1024, sizeof(String1024), "\
        "cGREY"Тип\t"cGREY"Действие\n\
        "cBLUE"1. "cWH"Сотрудники\t"cGR"Просмотреть\n\
        "cBLUE"2. "cWH"Статистика\t"cGR"Просмотреть");
    SPD(playerid, DIALOG_CHANGE_TRUCKER, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление ТК", String1024, !"Выбрать", !"Закрыть"); 

	return true;
}

stock show_trucker_menu_change(playerid, type)
{
	if(pData[playerid][pTruckerOwnerID] != type)
		return true;
	
   	format(String1024, sizeof(String1024), "\
   	"cGREY"Тип\t"cGREY"Действие\n\
   	"cBLUE"1. "cWH"Управление кассой\t"cGR"Открыть\n\
   	"cBLUE"2. "cWH"Изменение процента от прибыли\t"cGR"Изменить\n\
   	"cBLUE"3. "cWH"Сотрудники\t"cGR"Просмотреть\n\
   	"cBLUE"4. "cWH"Статистика\t"cGR"Просмотреть\n\
   	"cBLUE"5. "cWH"Доставка незанятых грузовиков\t"cGR"2500 рублей\n\
   	"cBLUE"5. "cWH"Покупка грузовиков\t"cGR"%d грузовиков\n\
   	"cBLUE"6. "cWH"Покупка дополнительных мест персонала\t"cGR"%d мест для персонала\n\
   	"cBLUE"7. "cWH"Покупка улучшения автопарка\t"cGR"%s\n\
   	"cBLUE"8. "cWH"Изменение цвета автопарка\t"cGR"%s\n\
   	"cBLUE"8. "cWH"Продать TK\t"cGR"Продать", trucker_station[type][trucker_veh_count], trucker_station[type][trucker_person_count], get_truck_veh_level[trucker_station[type][trucker_level_veh]],
   	get_trucker_veh_color(trucker_station[type][trucker_car_color]));
   	return SPD(playerid, DIALOG_CHANGE_TRUCKER, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление ТК", String1024, !"Выбрать", !"Закрыть"); 
}

stock select_color_trucker_veh(playerid)
{
    return SPD(playerid, DIALOG_SELECT_VEH_TK_C, DIALOG_STYLE_LIST, !""cBLUE"Выбор цвета грузовиков", "\
    {000000}Цвет №1 | Цена: "cGR"150.000 рублей\n\
    {FDF5CC}Цвет №2 | Цена: "cGR"150.000 рублей\n\
    {962E30}Цвет №3 | Цена: "cGR"150.000 рублей\n\
    {EAA337}Цвет №4 | Цена: "cGR"150.000 рублей\n\
    {9B616F}Цвет №5 | Цена: "cGR"150.000 рублей\n\
    {55784F}Цвет №6 | Цена: "cGR"150.000 рублей\n\
    {36546E}Цвет №7 | Цена: "cGR"150.000 рублей\n\
    {439ADE}Цвет №8 | Цена: "cGR"150.000 рублей", !"Выбрать", !"Закрыть"); 	
}

stock buy_trucker_station(playerid, type)
{
	if(pData[playerid][pBusiness] != -1)
		return SendErr(playerid, "Вы не можете купить бизнес, так как уже владеете бизнесом!");
	if(pData[playerid][pHotelOwner] != -1)
		return SendErr(playerid, "Вы не можете купить бизнес, так как уже владеете отелем!");
	if(pData[playerid][pMechOwnerID] != -1)
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
		id_station_trucker = GetPVarIntNew(playerid, "id_buy_trucker_base");

	if(pData[playerid][pMoney] <= trucker_station[id_station_trucker][trucker_base_price]) 
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
		return SendErr(playerid, "У вас недостаточно денег");
	}

	trucker_station[id_station_trucker][trucker_base_owner_id] = pData[playerid][pMysqlID];
	trucker_station[id_station_trucker][trucker_base_days] = 3;
	trucker_station[id_station_trucker][trucker_base_bank] = 0;

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_buy_tk", 4000);

	pData[playerid][pTrucker] = id_station_trucker;

	new 
		mech_owner_str[32];

	format(trucker_station[id_station_trucker][trucker_base_owner], 32, pData[playerid][pNickname]);
	format(mech_owner_str, 32, pData[playerid][pNickname]);

	format(String256,sizeof(String256),"UPDATE `trucker` SET `trucker_owner_id` = '%d' WHERE `trucker_id` = '%d'" , pData[playerid][pMysqlID], id_station_trucker);
	sql_queryEx(zConn, String256, QUERY_THREADED);	

    pData[playerid][pMoney] -= trucker_station[id_station_trucker][trucker_base_price];
    ResetPlayerMoney(playerid);
	GivePlayerMoney(playerid,pData[playerid][pMoney]);

	pData[playerid][pTruckerOwnerID] = type;
	pData[playerid][pTruckerRank] = 3;

	update_trucker_3d_text();	
	save_trucker_base();

	format(String1024,sizeof(String1024),"INSERT INTO `trucker_personal`(`id`,`user_id`,`user_rank`) VALUES ('%d','%d','%d')", id_station_trucker, 
		pData[playerid][pMysqlID], 3);
	sql_queryEx(zConn, String1024, QUERY_THREADED);

	UpdatePlayerData(playerid,"pTruckerRank",pData[playerid][pTruckerRank]);	
	UpdatePlayerData(playerid,"pTrucker",pData[playerid][pTrucker]);	
	UpdatePlayerData(playerid,"pTruckerOwnerID",pData[playerid][pTruckerOwnerID]);	

	format(String256, sizeof(String256), "\
		"cWH"Поздравляем Вас с приобретением Транспортной Компанией!\n\n\
		Вы купили Транспортную Компанию №%d\n\n\
		"cWH"ТК автоматически оплачено на %d дня\n\
		Советуем Вам как можно быстрее посетить банк и продлить оплату",
		trucker_station[id_station_trucker][trucker_base_id]+1,
		trucker_station[id_station_trucker][trucker_base_days]);
	return SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Приобритение ТК", String256, !"Понял", !"");
}


stock sell_trucker_gos_final(playerid)
{

	if(pData[playerid][pTruckerOwnerID] == -1)
		return SendErr(playerid, "Вы не владеете транспортной компанией!");

	new 
		f = pData[playerid][pTruckerOwnerID];


	new 
		final_money = floatround(trucker_station[f][trucker_base_price]*0.8);

	new 
		fmt_str[90];

	format(fmt_str, sizeof(fmt_str), "Продажа ТК в гос.стоимость №: %d", f);
	give_money(playerid, final_money, fmt_str);	
	SendSucc(playerid, "Вы успешно продали Транспортную Компанию государству!");

	pData[playerid][pTrucker] = -1;
	pData[playerid][pTruckerOwnerLowID] = -1;
	pData[playerid][pTruckerOwnerID] = -1;
	pData[playerid][pTruckerRank] = 0;
	pData[playerid][pJob] = 0;

	UpdatePlayerData(playerid,"pTrucker", pData[playerid][pTrucker]);
	UpdatePlayerData(playerid,"pTruckerOwnerLowID", pData[playerid][pTruckerOwnerLowID]);
	UpdatePlayerData(playerid,"pTruckerOwnerID",pData[playerid][pTruckerOwnerID]);	
	UpdatePlayerData(playerid,"pTruckerRank", pData[playerid][pTruckerRank]);

	format(String256,sizeof(String256),"DELETE FROM `trucker_personal` WHERE `user_id` = '%d'", pData[playerid][pMysqlID]);
	sql_queryEx(zConn, String256, QUERY_THREADED);

	format(String256,sizeof(String256),"UPDATE `accounts` SET `pTrucker` = '-1', `pTruckerOwnerLowID` = '-1', `job` = '0'  WHERE `id` = '%i'", pData[playerid][pMysqlID]);
	sql_queryEx(zConn, String256, QUERY_THREADED);

	trucker_station[f][trucker_base_owner_id] = -1;	
	trucker_station[f][trucker_base_bank] = 0;

	trucker_station[f][trucker_base_bank] = 0;
	trucker_station[f][trucker_person_count] = 25;
	trucker_station[f][trucker_level_veh] = 1;
	trucker_station[f][trucker_veh_count] = 25;


	save_trucker_base();
	update_trucker_3d_text();

	return true;

}

stock change_sell_trucker(playerid)
{
	if(pData[playerid][pTruckerOwnerID] == -1)
		return SendErr(playerid, "Вы не владеете Транспортной Компанией!");

	SPD(playerid, DIALOG_ACCEPT_SELL_TRUCKER_GOS, DIALOG_STYLE_MSGBOX, !""cBLUE"Продажа ТК", !"\
	"cWH"Вы уверены, что хотите продать транспортную компанию государству?\n\n\
	Вам будет возвращено 80% от стоимости!", !"Да", !"Нет");


	return true;
}

stock dialog_all_trucker(playerid, dialogid, response, listitem, inputtext[])
{

	switch(dialogid)
	{
		case DIALOG_BUY_TRUCKER_VEHICLE:
		{
			if(!response)
				return true;

			if(GetPlayerMoneyEx(playerid) < 750000)
				return SendErr(playerid, "У вас недостаточно денежных средств!");

			new 
				trucker_id = pData[playerid][pTrucker];

			trucker_station[trucker_id][trucker_veh_count]++;

			trucker_count_truck[trucker_id] = trucker_station[trucker_id][trucker_veh_count];

		 	format(String144, sizeof(String144), "Покупка грузовика в ТК №%d", trucker_id);
			give_money(playerid, -750000, String144);	

			buy_trucker_vehicle(playerid);
			return true;
		}
		case DIALOG_BUY_TRUCKER_PERSON:
		{
			new 
				trucker_id = pData[playerid][pTrucker];

			if(!response)
				return show_trucker_menu_change(playerid, trucker_id);

			if(GetPlayerMoneyEx(playerid) < 25000)
				return SendErr(playerid, "У вас недостаточно денежных средств!");

			trucker_station[trucker_id][trucker_person_count]++;

		 	format(String144, sizeof(String144), "Покупка места для персонала в ТК №%d", trucker_id);
			give_money(playerid, -25000, String144);	

			buy_trucker_person(playerid);
			return true;			
		}
		case DIALOG_BUY_TRUCKER_LEVEL:
		{
			new 
				trucker_id = pData[playerid][pTrucker];

			if(!response)
				return show_trucker_menu_change(playerid, trucker_id);

			if(GetPlayerMoneyEx(playerid) < 1000000)
				return SendErr(playerid, "У вас недостаточно денежных средств!");

			if(trucker_station[trucker_id][trucker_level_veh] == 3)
			{
				show_trucker_menu_change(playerid, trucker_id);
				SendErr(playerid, "У Вас уже максимально доступный уровень!");
				return true;
			}

			else if(trucker_station[trucker_id][trucker_level_veh] == 1)
			{
				trucker_station[trucker_id][trucker_level_veh] = 2;
				SendSucc(playerid, "Вы успешно улучшили тип грузовиков до 2-го уровня!");
			}
			else if(trucker_station[trucker_id][trucker_level_veh] == 2)
			{
				trucker_station[trucker_id][trucker_level_veh] = 3;
				SendSucc(playerid, "Вы успешно улучшили тип грузовиков до максимального уровня!");				
			}

		 	format(String144, sizeof(String144), "Покупка места для персонала в ТК №%d", trucker_id);
			give_money(playerid, -1000000, String144);	

			buy_trucker_level_truck(playerid);			
		}

		case DIALOG_ACCEPT_SELL_TRUCKER_GOS:
		{
			if(!response)
				return true;

			sell_trucker_gos_final(playerid);
		}
		case DIALOG_INVITE_P_ACCEPT:
		{
			if(!response)
			{
				DeletePVarNew(playerid, "id_trucker");
				return true;
			}

			invite_trucker_station_dialog(playerid);		
		}
		case DIALOG_TRUCKER_LOAD_MINER:
		{
			if(!response)
			{
				TogglePlayerControllable(playerid, true);
				return SendInf(playerid, "Чтобы изменить тип доставки, Вам нужно быть на базе Вашей ТК!");
			}
			
			visual_trucker_load_gruz(playerid);

			SetPVarIntNew(playerid, "type_load_checkpoint", 1);

			return dialog_input_load_trucker_1(playerid);
		}	
		case DIALOG_TRUCKER_LOAD_ZAVOD:
		{
			if(!response)
			{
				TogglePlayerControllable(playerid, true);
				return SendInf(playerid, "Чтобы изменить тип доставки, Вам нужно быть на базе Вашей ТК!");
			}
			
			SetPVarIntNew(playerid, "type_load_checkpoint", 2);

			visual_trucker_load_gruz(playerid);
			return dialog_input_load_trucker_1(playerid);
		}
		case DIALOG_TRUCKER_LOAD_SHOP:
		{
			if(!response)
			{
				TogglePlayerControllable(playerid, true);
				return SendInf(playerid, "Чтобы изменить тип доставки, Вам нужно быть на базе Вашей ТК!");
			}
			
			SetPVarIntNew(playerid, "type_load_checkpoint", 3);

			visual_trucker_load_gruz(playerid);
			return dialog_input_load_trucker_1(playerid);
		}
		case DIALOG_TRUCKER_LOAD_FILL_1:
		{
			if(!response)
			{
				TogglePlayerControllable(playerid, true);
				return SendInf(playerid, "Чтобы изменить тип доставки, Вам нужно быть на базе Вашей ТК!");
			}
			

			visual_trucker_load_gruz(playerid);
			return dialog_input_load_trucker_2(playerid);
		}
		case DIALOG_TRUCKER_LOAD_FILL_2:
		{
			if(!response)
			{
				TogglePlayerControllable(playerid, true);
				return SendInf(playerid, "Чтобы изменить тип доставки, Вам нужно быть на базе Вашей ТК!");
			}
			

			visual_trucker_load_gruz(playerid);
			return dialog_input_load_trucker_2(playerid);
		}
		case DIALOG_TRUCKER_LOAD_SAMWILLS:
		{
			if(!response)
			{
				TogglePlayerControllable(playerid, true);
				return SendInf(playerid, "Чтобы изменить тип доставки, Вам нужно быть на базе Вашей ТК!");
			}
			
			SetPVarIntNew(playerid, "type_load_checkpoint", 5);

			visual_trucker_load_gruz(playerid);
			return dialog_input_load_trucker_1(playerid);
		}
		case DIALOG_INPUT_TRUCKER_1:
		{	
			if(!response)
			{
				TogglePlayerControllable(playerid, true);
				return SendInf(playerid, "Чтобы изменить тип доставки, Вам нужно быть на базе Вашей ТК!");
			}
			


			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное значение!");
				return dialog_input_load_trucker_1(playerid);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное значение!");
				return dialog_input_load_trucker_1(playerid);
			}

			new 
				count_gruz = strval(inputtext);

			if(count_gruz < 1)
			{
				SendErr(playerid,"Вы указали неверное значение!");
				return dialog_input_load_trucker_1(playerid);	
			}

			new 
				get_max_gruz = get_job_level(playerid, SKILL_TRUCKER)*1000;			

			if(count_gruz > get_max_gruz)
			{
				SendErr(playerid,"Вы указали неверное значение!");
				return dialog_input_load_trucker_1(playerid);				
			}

			new 
				type_load = GetPVarIntNew(playerid, "type_load_checkpoint");

			start_load_gruz_trucker(playerid, type_load-1);

		}
		case DIALOG_INPUT_TRUCKER_2:
		{
			if(!response)
			{
				TogglePlayerControllable(playerid, true);
				return SendInf(playerid, "Чтобы изменить тип доставки, Вам нужно быть на базе Вашей ТК!");
			}
			

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное значение!");
				return dialog_input_load_trucker_1(playerid);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное значение!");
				return dialog_input_load_trucker_1(playerid);
			}

			new 
				count_gruz = strval(inputtext);

			if(count_gruz < 1)
			{
				SendErr(playerid,"Вы указали неверное значение!");
				return dialog_input_load_trucker_1(playerid);	
			}

			new 
				get_max_gruz = get_job_level(playerid, SKILL_TRUCKER)*1000;			

			if(count_gruz > get_max_gruz)
			{
				SendErr(playerid,"Вы указали неверное значение!");
				return dialog_input_load_trucker_1(playerid);				
			}

			start_load_gruz_trucker(playerid, 3);

		}
		case DIALOG_START_JOB_TRUCKER:
		{
			if(!response) return true;
			if(!GetPVarIntNew(playerid, "trucker_job"))
				return select_type_job_trucker(playerid);		
			else
				return end_trucker_job(playerid);			
		}
		case DIALOG_BUY_TRUCKER: 
		{
			if(!response)
			{
				DeletePVarNew(playerid, "id_buy_trucker_base");
				return true;
			}

			if(pData[playerid][pBusiness] != -1)
				return SendErr(playerid, "Вы не можете купить бизнес, так как уже владеете бизнесом!");

			if(pData[playerid][pHotelOwner] != -1)
				return SendErr(playerid, "Вы не можете купить бизнес, так как уже владеете отелем!");

			if(pData[playerid][pTruckerOwnerID] != -1)
				return SendErr(playerid,  "Вы не можете купить бизнес, так как уже владеете ТК!");
			
			buy_trucker_station(playerid, GetPVarIntNew(playerid, "id_buy_trucker_base"));
		}

		case DIALOG_CHANGE_TRUCKER: 
		{
			if(!response)
				return true;

			switch(listitem) 
			{
				case 0: return change_bank_trucker(playerid);
				case 1: return change_percent_trucker(playerid);
				case 2: return change_personal_trucker(playerid);	
				case 3: return change_statistic_trucker(playerid);
				case 4: return respawn_trucker_vehicle(playerid, pData[playerid][pTrucker]);
				case 5: return buy_trucker_vehicle(playerid);
				case 6: return buy_trucker_person(playerid);
				case 7: return buy_trucker_level_truck(playerid);
				case 8: return select_color_trucker_veh(playerid);
				case 9: return change_sell_trucker(playerid);
			}
		}
		case DIALOG_SELECT_VEH_TK_C:
		{
			new 
				id_trucker;

			if(pData[playerid][pTruckerOwnerID] == -1)
				return SendErr(playerid, "Вы не являетесь владельцем Транспортной Компании!");

			id_trucker = pData[playerid][pTruckerOwnerID];		

			if(!response) 
				return show_trucker_menu_change(playerid, id_trucker);	
				
			switch(listitem)
			{
				case 0:
				{
					if(GetPlayerMoneyEx(playerid) < 150000)
					{
						show_trucker_menu_change(playerid, id_trucker);
						return SendErr(playerid, "У Вас недостаточно денежных средств для покупки цвета для фур!");
					}

				 	format(String144, sizeof(String144), "Покупка нового цвета для грузовиков в ТК №%d", id_trucker);
					give_money(playerid, -150000, String144);	

					trucker_station[id_trucker][trucker_car_color] = 0;
					show_trucker_menu_change(playerid, id_trucker);
				}
				case 1:
				{
					if(GetPlayerMoneyEx(playerid) < 150000)
					{
						show_trucker_menu_change(playerid, id_trucker);
						return SendErr(playerid, "У Вас недостаточно денежных средств для покупки цвета для фур!");
					}

				 	format(String144, sizeof(String144), "Покупка нового цвета для грузовиков в ТК №%d", id_trucker);
					give_money(playerid, -150000, String144);	

					trucker_station[id_trucker][trucker_car_color] = 1;
					show_trucker_menu_change(playerid, id_trucker);
				}
				case 2:
				{
					if(GetPlayerMoneyEx(playerid) < 150000)
					{
						show_trucker_menu_change(playerid, id_trucker);
						return SendErr(playerid, "У Вас недостаточно денежных средств для покупки цвета для фур!");
					}

				 	format(String144, sizeof(String144), "Покупка нового цвета для грузовиков в ТК №%d", id_trucker);
					give_money(playerid, -150000, String144);	

					trucker_station[id_trucker][trucker_car_color] = 3;
					show_trucker_menu_change(playerid, id_trucker);
				}
				case 3:
				{
					if(GetPlayerMoneyEx(playerid) < 150000)
					{
						show_trucker_menu_change(playerid, id_trucker);
						return SendErr(playerid, "У Вас недостаточно денежных средств для покупки цвета для фур!");
					}

				 	format(String144, sizeof(String144), "Покупка нового цвета для грузовиков в ТК №%d", id_trucker);
					give_money(playerid, -150000, String144);	

					trucker_station[id_trucker][trucker_car_color] = 6;
					show_trucker_menu_change(playerid, id_trucker);
				}
				case 4:
				{
					if(GetPlayerMoneyEx(playerid) < 150000)
					{
						show_trucker_menu_change(playerid, id_trucker);
						return SendErr(playerid, "У Вас недостаточно денежных средств для покупки цвета для фур!");
					}

				 	format(String144, sizeof(String144), "Покупка нового цвета для грузовиков в ТК №%d", id_trucker);
					give_money(playerid, -150000, String144);	

					trucker_station[id_trucker][trucker_car_color] = 5;
					show_trucker_menu_change(playerid, id_trucker);
				}
				case 5:
				{
					if(GetPlayerMoneyEx(playerid) < 150000)
					{
						show_trucker_menu_change(playerid, id_trucker);
						return SendErr(playerid, "У Вас недостаточно денежных средств для покупки цвета для фур!");
					}

				 	format(String144, sizeof(String144), "Покупка нового цвета для грузовиков в ТК №%d", id_trucker);
					give_money(playerid, -150000, String144);	

					trucker_station[id_trucker][trucker_car_color] = 16;
					show_trucker_menu_change(playerid, id_trucker);
				}
				case 6:
				{
					if(GetPlayerMoneyEx(playerid) < 150000)
					{
						show_trucker_menu_change(playerid, id_trucker);
						return SendErr(playerid, "У Вас недостаточно денежных средств для покупки цвета для фур!");
					}

				 	format(String144, sizeof(String144), "Покупка нового цвета для грузовиков в ТК №%d", id_trucker);
					give_money(playerid, -150000, String144);	

					trucker_station[id_trucker][trucker_car_color] = 79;
					show_trucker_menu_change(playerid, id_trucker);
				}
				case 7:
				{
					if(GetPlayerMoneyEx(playerid) < 150000)
					{
						show_trucker_menu_change(playerid, id_trucker);
						return SendErr(playerid, "У Вас недостаточно денежных средств для покупки цвета для фур!");
					}

				 	format(String144, sizeof(String144), "Покупка нового цвета для грузовиков в ТК №%d", id_trucker);
					give_money(playerid, -150000, String144);	

					trucker_station[id_trucker][trucker_car_color] = 106;
					show_trucker_menu_change(playerid, id_trucker);
				}
			}			
		}
		case DIALOG_CHANGE_TRUCKER_BANK:
		{
			new 
				id_trucker;

			if(pData[playerid][pTruckerOwnerID] == -1)
				return SendErr(playerid, "Вы не являетесь владельцем Транспортной Компании!");

			id_trucker = pData[playerid][pTruckerOwnerID];		

			if(!response) 
				return show_trucker_menu_change(playerid, id_trucker);	
				
			switch(listitem) 
			{
				case 0: return trucker_bank_operation(playerid, 1);
				case 1: return trucker_bank_operation(playerid, 2);
			}

		}
		case DIALOG_TRUCKER_INPUT_MONEY:
		{
			if(!response) 
				return change_bank_trucker(playerid);

			if(!IsNumeric(inputtext)) 
				return SendErr(playerid,"Вы указали неверное количество денег");


			new 
				id_trucker;

			if(pData[playerid][pTruckerOwnerID] != -1)
			{
				id_trucker = pData[playerid][pTruckerOwnerID];		
			}
			else
			{
				id_trucker = pData[playerid][pTruckerOwnerLowID];
			}

			new 
				count_money = strval(inputtext);

			if(count_money < 1)
			{
				SendErr(playerid,"Вы указали неверное количество денег!");
				return change_bank_trucker(playerid);
			}

			if(count_money < 1)
			{
				SendErr(playerid,"Вы указали неверное количество денег!");
				return change_bank_trucker(playerid);
			}


			if(trucker_station[id_trucker][trucker_base_bank] < count_money)
			{
				change_bank_trucker(playerid);
				return SendErr(playerid,"Недостаточно денег в кассе ТК!");
			}

			trucker_station[id_trucker][trucker_base_bank] -= count_money;

		 	format(String144, sizeof(String144), "Снятие с кассы ТК №%d", id_trucker);
			give_money(playerid, count_money, String144);	

			save_trucker_base();

			SFCM(playerid,COLOR_BLUE,"• {FFC800}[Подсказка] "cWH"Вы сняли с кассы ТК - %d рублей", count_money);	

		}
		case DIALOG_TRUCKER_PUT_MONEY:
		{
			if(!response) 
				return change_bank_trucker(playerid);

			if(!IsNumeric(inputtext)) 
				return SendErr(playerid,"Вы указали неверное количество денег");

			new 
				id_trucker;

			if(pData[playerid][pTruckerOwnerID] != -1)
			{
				id_trucker = pData[playerid][pTruckerOwnerID];		
			}
			else
			{
				id_trucker = pData[playerid][pTruckerOwnerLowID];
			}

			new 
				count_money = strval(inputtext);

			if(count_money < 1)
			{
				SendErr(playerid,"Вы указали неверное количество денег!");
				return change_bank_trucker(playerid);
			}


			if(pData[playerid][pMoney] < count_money)
			{
				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
				change_bank_trucker(playerid);
				return SendErr(playerid,"Недостаточно денег, чтобы положить в кассу!");
			}

			trucker_station[id_trucker][trucker_base_bank] += count_money;

		 	format(String144, sizeof(String144), "Пополнение кассы ТК №%d", id_trucker);
			give_money(playerid, -count_money, String144);	

			save_trucker_base();

			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы пополнили кассу ТК на %d рублей", count_money);		

		}	

		case DIALOG_CHANGE_PERCENT:
		{
			new 
				id_trucker;

			if(pData[playerid][pTruckerOwnerID] != -1)
			{
				id_trucker = pData[playerid][pTruckerOwnerID];		
			}
			else
			{
				id_trucker = pData[playerid][pTruckerOwnerLowID];
			}

			if(!response) 
				return show_trucker_menu_change(playerid, id_trucker);	
			
			
			if(!IsNumeric(inputtext)) 
				return SendErr(playerid,"Вы указали неверный процент!");


			new 
				count_money = strval(inputtext);	

			if(count_money < 1 || count_money > 50)
			{
			    SendErr(playerid,"От 1 до 50 процентов!");
				return show_trucker_menu_change(playerid, id_trucker);	
			}	

			trucker_station[id_trucker][trucker_base_percent] = count_money;		

			SendSucc(playerid, "Процент от прибыли был успешно обновлен!");

			SFCM(playerid,0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Новый процент от прибыли - "cGR"%d%%"cWH"", count_money);	

			save_trucker_base();

			show_trucker_menu_change(playerid, id_trucker);	

		}

		case DIALOG_CHANGE_MECH_NAME:
		{

			new 
				id_trucker;

			if(pData[playerid][pTruckerOwnerID] != -1)
			{
				id_trucker = pData[playerid][pTruckerOwnerID];		
			}
			else
			{
				id_trucker = pData[playerid][pTruckerOwnerLowID];
			}

			if(!response) 
				return show_trucker_menu_change(playerid, id_trucker);	

			if(strlen(inputtext) < 3 || strlen(inputtext) > 20)
			{
			    SendErr(playerid,"Слишком короткое/длинное название ТК");
				return change_name_trucker(playerid);
			}
			if(IsNumeric(inputtext) || check_no_valid_symbol_text(inputtext) || check_sql_injection_text(inputtext))
			{
				change_name_trucker(playerid);
				return SendErr(playerid,"Название содержит запрещенные символы!");
			}

		    update_trucker_3d_text();

		}
		case DIALOG_TRUCKER_CHANGE_PERS:
		{

			new 
				id_trucker;

			if(pData[playerid][pTruckerOwnerID] != -1)
			{
				id_trucker = pData[playerid][pTruckerOwnerID];		
			}
			else
			{
				id_trucker = pData[playerid][pTruckerOwnerLowID];
			}

			if(!response) 
				return show_trucker_menu_change(playerid, id_trucker);	

			if(listitem == 20) 
			{
				return change_personal_trucker(playerid, GetPVarIntNew(playerid, "check_page_panel_trucker")+1);
			}
			else if(listitem == 21 || GetPVarIntNew(playerid, "button_back_personal_menu") == listitem && listitem != 0) 
			{
				return change_personal_trucker(playerid, GetPVarIntNew(playerid, "check_page_panel_trucker")-1);
			}

			new 
				id = dialog_listitem_values[playerid][listitem];

			return change_rank_personal_trucker(playerid, id);			
		}
		case DIALOG_TRUCKER_CHANGE_PERS_2:
		{

			new 
				id_trucker;

			if(pData[playerid][pTruckerOwnerID] != -1)
			{
				id_trucker = pData[playerid][pTruckerOwnerID];		
			}
			else
			{
				id_trucker = pData[playerid][pTruckerOwnerLowID];
			}

			if(!response) 
				return show_trucker_menu_change(playerid, id_trucker);	

			new 
				id = GetPVarIntNew(playerid, "uninvite_trucker_bank_id");

				
			switch(listitem) 
			{
				case 2: return give_rank_truck_trucker(playerid, id);
				case 3: return give_rank_manage_trucker(playerid, id);
				case 4: return uninvite_panel_trucker_t(playerid, id);
			}			
		}
		case DIALOG_START_TRUCKER_JOB:
		{
			if(!response) return true;
			if(!GetPVarIntNew(playerid, "trucker_job"))
				return start_trucker_job(playerid);
			else
				return end_trucker_job(playerid);			
		}
		case DIALOG_START_TRUCKER_JOB_1:
		{
			if(!response) 
				return true;	
				
			switch(listitem) 
			{
				case 0: return dialog_job_trucker(playerid);
				case 1: return trucker_job_stats(playerid);
				case 2: return leave_job_trucker(playerid);
			}				
		}
		case DIALOG_PERSONAL_CLOSE:
		{
			new 
				id_trucker;

			if(pData[playerid][pTruckerOwnerID] != -1)
			{
				id_trucker = pData[playerid][pTruckerOwnerID];		
			}
			else
			{
				id_trucker = pData[playerid][pTruckerOwnerLowID];
			}

			if(!response) 
				return show_trucker_menu_change(playerid, id_trucker);

			show_trucker_menu_change(playerid, id_trucker);
		}
	}
	return true;

}


stock change_percent_trucker(playerid)
{
	new 
		id_trucker;

	if(pData[playerid][pTruckerOwnerID] != -1)
	{
		id_trucker = pData[playerid][pTruckerOwnerID];		
	}
	else
	{
		id_trucker = pData[playerid][pTruckerOwnerLowID];
	}

	if(trucker_station[id_trucker][trucker_block_percent])
		return SendErr(playerid, "Возможность изменять прибыль в ТК отключена!");


	format(String144, sizeof(String144), "\
	"cWH"Укажите процент, который будете получать с прибыли (От 1 процента до 50 процентов)\n\n\
	Текущий процент: "cGR"%d"cWH" процент(ов)", trucker_station[id_trucker][trucker_base_percent]);

	return SPD(playerid, DIALOG_CHANGE_PERCENT, DIALOG_STYLE_INPUT, !""cWH"Изменение стоимости", String144, !"Далее", !"Назад");
}


stock change_bank_trucker(playerid)
{

	if(pData[playerid][pTruckerOwnerID] == -1)
		return SendErr(playerid, "Вы не являетесь владельцем Транспортной Компании!");

	new 
		id_trucker = pData[playerid][pTruckerOwnerID];

	if(trucker_station[id_trucker][trucker_block_bank])
		return SendErr(playerid, "Возможность пользоваться кассой ТК отключена!");

    format(String256, sizeof(String256), "\
        "cGREY"Тип\t"cGREY"Действие\n\
        "cBLUE"1. "cWH"Снять деньги с кассы\t"cGR"Снять\n\
        "cBLUE"2. "cWH"Положить деньги в кассу\t"cGR"Пополнить");
    SPD(playerid, DIALOG_CHANGE_TRUCKER_BANK, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление ТК", String256, !"Выбрать", !"Закрыть"); 
	return true;
}

stock trucker_bank_operation(playerid, type)
{
	new 
		id_trucker;

	switch(type)
	{
		case 1:
		{
			if(pData[playerid][pTruckerOwnerID] != -1)
			{
				id_trucker = pData[playerid][pTruckerOwnerID];		
			}


			if(trucker_station[id_trucker][trucker_block_bank])
				return SendErr(playerid, "Возможность пользоваться кассой ТК отключена!");


			format(String256, sizeof(String256), "\
			"cWH"Сколько денежных средств Вы хотите снять?\n\n\
			В банке ТК находится "cGR"%d"cWH" рублей", trucker_station[id_trucker][trucker_base_bank]);

			SPD(playerid, DIALOG_TRUCKER_INPUT_MONEY, DIALOG_STYLE_INPUT, !""cBLUE"Снятие денег", String256, !"Далее", !"Назад");

		}
		case 2:
		{
			if(pData[playerid][pTruckerOwnerID] != -1)
			{
				id_trucker = pData[playerid][pTruckerOwnerID];		
			}
			else if(pData[playerid][pTruckerOwnerLowID] != -1)
			{
				id_trucker = pData[playerid][pTruckerOwnerLowID];
			}

			if(trucker_station[id_trucker][trucker_block_bank])
				return SendErr(playerid, "Возможность пользоваться кассой ТК отключена!");

			format(String256, sizeof(String256), "\
			"cWH"Сколько денежных средств Вы хотите положить?\n\n\
			В банке ТК находится "cGR"%d"cWH" рублей", trucker_station[id_trucker][trucker_base_bank]);

			SPD(playerid, DIALOG_TRUCKER_PUT_MONEY, DIALOG_STYLE_INPUT, !""cBLUE"Пополнение кассы", String256, !"Далее", !"Назад");

		}
	}
	return true;
}


stock change_personal_trucker(playerid, page = 0)
{

	new 
		id_trucker;

	if(page < 0)
	{
		page = 0;
	}


	if(pData[playerid][pTruckerOwnerID] != -1)
	{
		id_trucker = pData[playerid][pTruckerOwnerID];		
	}
	else if(pData[playerid][pTruckerOwnerLowID] != -1)
	{
		id_trucker = pData[playerid][pTruckerOwnerLowID];
	}

	if(trucker_station[id_trucker][trucker_block_uninvite])
		return SendErr(playerid, "Возможность изменять персонал в ТК отключена!");


    format(String4096, sizeof(String4096), ""cGREY"№. Имя\t"cGREY"Должность\t"cGREY"Общий доход (За сутки)\t"cGREY"Последний заход\n");

    SetPVarIntNew(playerid, "check_page_panel_trucker", page);

	format(String1024, sizeof(String1024), "SELECT * FROM `trucker_personal` WHERE `id` = %d ORDER BY `user_data_last_join` LIMIT %d,20", id_trucker, page*20);
	new Result:rnew = sql_queryEx(zConn, String1024, QUERY_CACHED);			

	new all_trucker_stations = sql_num_rows(rnew);

    new 
    	trucker_id_all = page*20;


 	for(new i; i < all_trucker_stations; i++)
	{


		new 
			trucker_personal_user_id,
			trucker_personal_user_rank,
			trucker_per_user_money_day,
			trucker_per_user_money_all,
			trucker_personal_user_name[32],
			trucker_personal_user_join[20],
			trucker_personal_user_last[20];

		trucker_personal_user_id = sql_get_field_assoc_int_ex(rnew, i, "user_id");
		trucker_personal_user_rank = sql_get_field_assoc_int_ex(rnew, i, "user_rank");
		trucker_per_user_money_day = sql_get_field_assoc_int_ex(rnew, i, "user_money_day");
		trucker_per_user_money_all = sql_get_field_assoc_int_ex(rnew, i, "user_money_all");

		dialog_listitem_values[playerid][i] = trucker_personal_user_id;

		GetPlayerNameByID(trucker_personal_user_id,trucker_personal_user_name);

		sql_get_field_assoc_ex(rnew, i, "user_data_join", trucker_personal_user_join, 20);
		sql_get_field_assoc_ex(rnew, i, "user_data_last_join", trucker_personal_user_last, 20);

	    new onnn = 0;


		foreach(Player, x)
		{

			if(pData[x][pMysqlID] == trucker_personal_user_id && pData[x][pTrucker] == pData[playerid][pTrucker]) onnn = 1;
		}


		if(onnn > 0)
		{
			if(trucker_id_all < 9 ) 
			{
		    	format(String4096, sizeof(String4096), "%s%s%d."cWH"  %s \t%s\t%s %d"cWH" %s (%d)"cWH" рублей\t%s\n",String4096, \
		    	get_trucker_color(id_trucker), trucker_id_all+1, trucker_personal_user_name, \
		    	trucker_rank_name[trucker_personal_user_rank], \
		    	get_color_m_trucker(trucker_per_user_money_all), trucker_per_user_money_all, get_color_m_trucker(trucker_per_user_money_day), trucker_per_user_money_day, "{00CC44}Online{FFFFFF}");
		    }
		    else			    
		    {
		    	format(String4096, sizeof(String4096), "%s%s%d."cWH"  %s \t%s\t%s %d"cWH" %s (%d)"cWH" рублей\t%s\n",String4096, \
		    	get_trucker_color(id_trucker), trucker_id_all+1, trucker_personal_user_name, \
		    	trucker_rank_name[trucker_personal_user_rank], \
		    	get_color_m_trucker(trucker_per_user_money_all), trucker_per_user_money_all, get_color_m_trucker(trucker_per_user_money_day), trucker_per_user_money_day, "{00CC44}Online{FFFFFF}");
			}
		}
		else 
		{
			if(trucker_id_all < 9 ) 
			{
		    	format(String4096, sizeof(String4096), "%s%s%d."cWH"  %s \t%s\t%s %d"cWH" %s (%d)"cWH" рублей\t%s\n",String4096, \
		    	get_trucker_color(id_trucker), trucker_id_all+1, trucker_personal_user_name, \
		    	trucker_rank_name[trucker_personal_user_rank], \
		    	get_color_m_trucker(trucker_per_user_money_all), trucker_per_user_money_all, get_color_m_trucker(trucker_per_user_money_day), trucker_per_user_money_day, trucker_personal_user_last);
		    }
		    else			    
		    {
		    	format(String4096, sizeof(String4096), "%s%s%d."cWH"  %s \t%s\t%s %d"cWH" %s (%d)"cWH" рублей\t%s\n",String4096, \
		    	get_trucker_color(id_trucker), trucker_id_all+1, trucker_personal_user_name, \
		    	trucker_rank_name[trucker_personal_user_rank], \
		    	get_color_m_trucker(trucker_per_user_money_all), trucker_per_user_money_all, get_color_m_trucker(trucker_per_user_money_day), trucker_per_user_money_day, trucker_personal_user_last);
			}
		}


		trucker_id_all++;


	}
	sql_next_row(rnew);

	if(all_trucker_stations < 20)
	{
		SetPVarIntNew(playerid, "button_back_personal_menu", all_trucker_stations);
	}

    if(all_trucker_stations == 20) strcat(String4096, ""cGREY"Далее >>>\n");
    if(page >= 1) strcat(String4096, ""cGREY"<<< Назад");

	SPD(playerid,DIALOG_TRUCKER_CHANGE_PERS, DIALOG_STYLE_TABLIST_HEADERS ,""cBLUE"Персонал ТК",String4096,"Далее","Закрыть");
	return true;
}


stock change_rank_personal_trucker(playerid, user_sql_id)
{
	SetPVarIntNew(playerid, "uninvite_trucker_bank_id", user_sql_id);


	new 
		id_trucker;


	if(pData[playerid][pTruckerOwnerID] != -1)
	{
		id_trucker = pData[playerid][pTruckerOwnerID];		
	}
	else if(pData[playerid][pTruckerOwnerLowID] != -1)
	{
		id_trucker = pData[playerid][pTruckerOwnerLowID];
	}

	format(String256, sizeof(String256), "SELECT * FROM trucker_personal WHERE user_id = '%d' LIMIT 1", user_sql_id);
	new Result:trucker_find = sql_queryEx(zConn, String256, QUERY_CACHED);

	if(sql_num_rows(trucker_find)) 
	{
		new 
			mehcnaic_change_name[32],
			trucker_rank;


  		trucker_rank = sql_get_field_assoc_int(trucker_find, "user_rank");

		GetPlayerNameByID(user_sql_id,mehcnaic_change_name);

		if(pData[playerid][pTruckerOwnerID] == id_trucker && pData[playerid][pTruckerOwnerLowID] == -1)
		{
		    format(String512, sizeof(String512), "\
	        "cGREY"Сотрудник\t"cGREY"Управление\n\
	        "cBLUE"- "cWH"%s\t"cGR"%s\n\
	        "cBLUE"\t\n\
	        "cBLUE"- "cWH"Дальнобойщик\t"cGR"Понизить\n\
	        "cBLUE"- "cWH"Управляющий\t"cGR"Повысить\n\
	        "cBLUE"- "cWH"Уволить сотрудника\t"cGR"Уволить", 
	        mehcnaic_change_name, trucker_rank_name[trucker_rank]);
		    SPD(playerid, DIALOG_TRUCKER_CHANGE_PERS_2, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Персонал ТК:", String512, !"Выбрать", !"Закрыть"); 					
		}
		else if(pData[playerid][pTruckerOwnerLowID] == id_trucker && pData[playerid][pTruckerOwnerID] == -1)
		{
		    format(String512, sizeof(String512), "\
	        "cGREY"Сотрудник\t"cGREY"Управление\n\
	        "cBLUE"- "cWH"%s\t"cGR"%s\n\
	        "cBLUE"\t\n\
	        "cBLUE"- "cWH"Дальнобойщик\t"cGR"Понизить\n\
	        "cBLUE"- "cWH"Управляющий\t"cGR"Повысить\n\
	        "cBLUE"- "cWH"Уволить сотрудника\t"cGR"Уволить", 
	        mehcnaic_change_name, trucker_rank_name[trucker_rank]);
		    SPD(playerid, DIALOG_TRUCKER_CHANGE_PERS_2, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Персонал ТК:", String512, !"Выбрать", !"Закрыть"); 					
		}

	}
	return true;
}


stock give_rank_truck_trucker(playerid, user_sql_id)
{
	if(pData[playerid][pTruckerOwnerID] == -1)
		return change_rank_personal_trucker(playerid, user_sql_id);

	if(pData[playerid][pMysqlID] == user_sql_id)
	{	
		change_rank_personal_trucker(playerid, user_sql_id);
		return SendErr(playerid, "Вы не можете изменить себе ранг!");
	}


	format(String512, sizeof(String512), "SELECT * FROM trucker_personal WHERE user_id = '%d' LIMIT 1", user_sql_id);
	new Result:trucker_find = sql_queryEx(zConn, String512, QUERY_CACHED);

	if(sql_num_rows(trucker_find)) 
	{
		new 
			mehcnaic_change_name[32],
			trucker_rank;


  		trucker_rank = sql_get_field_assoc_int(trucker_find, "user_rank");

		GetPlayerNameByID(user_sql_id,mehcnaic_change_name);

		new 
			player_id = GetPlayerID(mehcnaic_change_name);

		if(IsPlayerConnected(player_id))
		{
			if(trucker_rank == 1)
			{
				SFCM(playerid, 0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Дальнобойщик %s и так уже имеет ранг дальнобойщика!", mehcnaic_change_name);
				return change_rank_personal_trucker(playerid, user_sql_id);
			}
			else
			{
				format(String256,sizeof(String256),"UPDATE `trucker_personal` SET `user_rank` = 1 WHERE `user_id` = '%d'" , pData[player_id][pMysqlID]);
				sql_queryEx(zConn, String256, QUERY_THREADED);	

				pData[playerid][pTruckerOwnerLowID] = -1;

				UpdatePlayerData(player_id,"pTruckerOwnerLowID", pData[player_id][pTruckerOwnerLowID]);


				pData[player_id][pTruckerRank] = 1; 
				UpdatePlayerData(player_id,"pTruckerRank", pData[player_id][pTruckerRank]);

				SFCM(player_id, 0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Владелец %s [%d] понизил Вас до должности 'Дальнобойщик'", pData[playerid][pNickname], playerid);	

				new 
					id_trucker = pData[playerid][pTruckerOwnerID];


				format(String144, sizeof(String144), "[T] Сотрудник %s был понижен до должности 'Дальнобойщик' владельцем %s", mehcnaic_change_name, pData[playerid][pNickname]);
				send_trucker_job(id_trucker, COLOR_GREY, String144);

				return change_rank_personal_trucker(playerid, user_sql_id);	
			}
		}
		else
		{
			if(trucker_rank == 1)
			{
				SFCM(playerid, 0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Дальнобойщик %s и так уже имеет ранг дальнобойщика!", mehcnaic_change_name);
				return change_rank_personal_trucker(playerid, user_sql_id);
			}
			else
			{
				format(String256,sizeof(String256),"UPDATE `trucker_personal` SET `user_rank` = 1 WHERE `user_id` = '%d'" , user_sql_id);
				sql_queryEx(zConn, String256, QUERY_THREADED);		

				format(String256,sizeof(String256),"UPDATE `accounts` SET `pTruckerOwnerLowID` = '-1', `pTruckerRank` = '1' WHERE `id` = '%i'", user_sql_id);
				sql_queryEx(zConn, String256, QUERY_THREADED);

				SFCM(playerid, 0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Вы успешно понизили %s до должности Дальнобойщика оффлайн!", mehcnaic_change_name);

				new 
					id_trucker = pData[playerid][pTruckerOwnerID];


				format(String144, sizeof(String144), "[TRUCK] Сотрудник %s был понижен до должности 'Дальнобойщика' владельцем %s", mehcnaic_change_name, pData[playerid][pNickname]);
				send_trucker_job(id_trucker, COLOR_GREY, String144);

				return change_rank_personal_trucker(playerid, user_sql_id);	
			}			
		}


	}	

	return true;
}
stock give_rank_manage_trucker(playerid, user_sql_id)
{
	if(pData[playerid][pTruckerOwnerID] == -1)
		return change_rank_personal_trucker(playerid, user_sql_id);

	if(pData[playerid][pMysqlID] == user_sql_id)
	{	
		change_rank_personal_trucker(playerid, user_sql_id);
		return SendErr(playerid, "Вы не можете изменить себе ранг!");
	}


	format(String512, sizeof(String512), "SELECT * FROM trucker_personal WHERE user_id = '%d' LIMIT 1", user_sql_id);
	new Result:trucker_find = sql_queryEx(zConn, String512, QUERY_CACHED);

	if(sql_num_rows(trucker_find)) 
	{
		new 
			mehcnaic_change_name[32],
			trucker_rank;


  		trucker_rank = sql_get_field_assoc_int(trucker_find, "user_rank");

		GetPlayerNameByID(user_sql_id,mehcnaic_change_name);

		new 
			player_id = GetPlayerID(mehcnaic_change_name);

		if(IsPlayerConnected(player_id))
		{

			if(trucker_rank == 2)
			{
				SFCM(playerid, 0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Дальнобойщик %s и так уже является управляющим!", mehcnaic_change_name);
				return change_rank_personal_trucker(playerid, user_sql_id);
			}
			else
			{
				format(String256,sizeof(String256),"UPDATE `trucker_personal` SET `user_rank` = 2 WHERE `user_id` = '%d'" , user_sql_id);
				sql_queryEx(zConn, String256, QUERY_THREADED);		


				format(String256,sizeof(String256),"UPDATE `accounts` SET `pTruckerOwnerLowID` = '%d' WHERE `id` = '%i'", pData[playerid][pTruckerOwnerID], user_sql_id);
				sql_queryEx(zConn, String256, QUERY_THREADED);

				pData[player_id][pTruckerOwnerLowID] = pData[playerid][pTruckerOwnerID];

				pData[player_id][pTruckerRank] = 2; 
				UpdatePlayerData(player_id,"pTruckerRank", pData[player_id][pTruckerRank]);

				SFCM(player_id, 0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Владелец %s [%d] повысил Вас до должности Управляющего ТК!", pData[playerid][pNickname], playerid);

				new 
					id_trucker = pData[playerid][pTruckerOwnerID];


				format(String144, sizeof(String144), "[TRUCK] Сотрудник %s был повышен до должности 'Управляющего' владельцем %s", mehcnaic_change_name, pData[playerid][pNickname]);
				send_trucker_job(id_trucker, COLOR_GREY, String144);

				return change_rank_personal_trucker(playerid, user_sql_id);	
			}
		}
		else
		{
			if(trucker_rank == 2)
			{
				SFCM(playerid, 0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Дальнобойщик %s и так уже является управляющим!", mehcnaic_change_name);
				return change_rank_personal_trucker(playerid, user_sql_id);
			}
			else
			{
				format(String256,sizeof(String256),"UPDATE `trucker_personal` SET `user_rank` = 2 WHERE `user_id` = '%d'" , user_sql_id);
				sql_queryEx(zConn, String256, QUERY_THREADED);		


				format(String256,sizeof(String256),"UPDATE `accounts` SET `pTruckerOwnerLowID` = '%d', `pTruckerRank` = '2' WHERE `id` = '%i'", user_sql_id, pData[playerid][pTruckerOwnerID]);
				sql_queryEx(zConn, String256, QUERY_THREADED);

				SFCM(playerid, 0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Вы успешно повысили %s до должности управляющего оффлайн!", mehcnaic_change_name);

				new 
					id_trucker = pData[playerid][pTruckerOwnerID];


				format(String144, sizeof(String144), "[TRUCK] Сотрудник %s был повышен до должности 'Управляющего' владельцем %s", mehcnaic_change_name, pData[playerid][pNickname]);
				send_trucker_job(id_trucker, COLOR_GREY, String144);

				return change_rank_personal_trucker(playerid, user_sql_id);	
			}			
		}


	}	
	return true;
}
stock uninvite_panel_trucker_t(playerid, user_sql_id)
{

	printf("UNINVITE ID - %d", user_sql_id);

	new 
		id_trucker;


	if(pData[playerid][pTruckerOwnerID] != -1)
	{
		id_trucker = pData[playerid][pTruckerOwnerID];		
	}
	else if(pData[playerid][pTruckerOwnerLowID] != -1)
	{
		id_trucker = pData[playerid][pTruckerOwnerLowID];
	}

	new 
		mehcnaic_change_name[MAX_PLAYER_NAME];

	new 
		trucker_rank;

	if(pData[playerid][pMysqlID] == user_sql_id)
	{	
		change_rank_personal_trucker(playerid, user_sql_id);
		return SendErr(playerid, "Вы не можете уволить себя!");
	}

	if(pData[playerid][pTruckerOwnerLowID])
	{
		trucker_rank = 2;
	}
	else if(pData[playerid][pTruckerOwnerID])
	{
		trucker_rank = 3;
	}	

	GetPlayerNameByID(user_sql_id,mehcnaic_change_name);

	new 
		player_id = GetPlayerID(mehcnaic_change_name);

	if(IsPlayerConnected(player_id))
	{
		pData[player_id][pTrucker] = -1;
		pData[player_id][pTruckerOwnerLowID] = -1;
		pData[player_id][pTruckerRank] = 0;
		pData[player_id][pJob] = 0;

		UpdatePlayerData(player_id,"pTrucker", pData[player_id][pTrucker]);
		UpdatePlayerData(player_id,"pTruckerOwnerLowID", pData[player_id][pTruckerOwnerLowID]);
		UpdatePlayerData(player_id,"pTruckerRank", pData[player_id][pTruckerRank]);
		UpdatePlayerData(player_id, "job", pData[player_id][pJob]);

		format(String256,sizeof(String256),"DELETE FROM `trucker_personal` WHERE `user_id` = '%d'", user_sql_id);
		sql_queryEx(zConn, String256, QUERY_THREADED);

		format(String256,sizeof(String256),"UPDATE `accounts` SET `pTrucker` = '-1', `pTruckerOwnerLowID` = '-1', `job` = '0'  WHERE `id` = '%i'", user_sql_id);
		sql_queryEx(zConn, String256, QUERY_THREADED);


		SFCM(player_id, 0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"%s %s [%d] уволил Вас c Транспортной Компании №%d", trucker_rank_name[trucker_rank], pData[playerid][pNickname], playerid, id_trucker);


		format(String256, sizeof(String256), "[TRUCK] Сотрудник %s был уволен с ТК %s %s", pData[player_id][pNickname], trucker_rank_name[trucker_rank], pData[playerid][pNickname]);
		send_trucker_job(id_trucker, COLOR_GREY, String256);

	}
	else
	{


		format(String256,sizeof(String256),"DELETE FROM `trucker_personal` WHERE `user_id` = '%d'", user_sql_id);
		sql_queryEx(zConn, String256, QUERY_THREADED);

		format(String256,sizeof(String256),"UPDATE `accounts` SET `pTrucker` = '-1', `pTruckerOwnerLowID` = '-1', `job` = '0'  WHERE `id` = '%i'", user_sql_id);
		sql_queryEx(zConn, String256, QUERY_THREADED);

		SFCM(playerid, 0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Вы успешно уволили %s c Транспортной Компании", mehcnaic_change_name);


		format(String256, sizeof(String256), "[TRUCK] Сотрудник %s был уволен с ТК %s %s", mehcnaic_change_name, trucker_rank_name[trucker_rank], pData[playerid][pNickname]);
		send_trucker_job(id_trucker, COLOR_GREY, String256);

	}

	DeletePVarNew(playerid, "uninvite_trucker_bank_id");

	change_personal_trucker(playerid);

	return true;
}

stock uninvite_command_pers_trucker(playerid, player_id_to)
{

	new 
		id_trucker;


	if(pData[playerid][pTruckerOwnerID] != -1)
	{
		id_trucker = pData[playerid][pTruckerOwnerID];		
	}
	else if(pData[playerid][pTruckerOwnerLowID] != -1)
	{
		id_trucker = pData[playerid][pTruckerOwnerLowID];
	}


	new 
		trucker_rank;

	if(playerid == player_id_to)
	{	
		return SendErr(playerid, "Вы не можете уволить себя!");
	}

	if(pData[playerid][pTruckerOwnerLowID])
	{
		trucker_rank = 2;
	}
	else if(pData[playerid][pTruckerOwnerID])
	{
		trucker_rank = 3;
	}	



	pData[player_id_to][pTrucker] = -1;
	pData[player_id_to][pTruckerOwnerLowID] = -1;
	pData[player_id_to][pTruckerRank] = 0;
	pData[player_id_to][pJob] = 0;

	UpdatePlayerData(player_id_to,"pTrucker", pData[player_id_to][pTrucker]);
	UpdatePlayerData(player_id_to,"pTruckerOwnerLowID", pData[player_id_to][pTruckerOwnerLowID]);
	UpdatePlayerData(player_id_to,"pTruckerRank", pData[player_id_to][pTruckerRank]);
	UpdatePlayerData(player_id_to, "job", pData[player_id_to][pJob]);

	format(String256,sizeof(String256),"DELETE FROM `trucker_personal` WHERE `user_id` = '%d'", pData[player_id_to][pMysqlID]);
	sql_queryEx(zConn, String256, QUERY_THREADED);

	format(String256,sizeof(String256),"UPDATE `accounts` SET `pTrucker` = '-1', `pTruckerOwnerLowID` = '-1', `job` = '0'  WHERE `id` = '%i'", pData[player_id_to][pMysqlID]);
	sql_queryEx(zConn, String256, QUERY_THREADED);


	SFCM(player_id_to, 0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"%s %s [%d] уволил Вас c Транспортной Компании №%d", trucker_rank_name[trucker_rank], pData[playerid][pNickname], playerid, id_trucker+1);


	format(String256, sizeof(String256), "[TRUCKER] Сотрудник %s был уволен с ТК %s %s", pData[player_id_to][pNickname], trucker_rank_name[trucker_rank], pData[playerid][pNickname]);
	send_trucker_job(id_trucker, COLOR_GREY, String256);


	return true;
}

stock change_statistic_trucker(playerid)
{

	new 
		id_trucker;


	if(pData[playerid][pTruckerOwnerID] != -1)
	{
		id_trucker = pData[playerid][pTruckerOwnerID];		
	}
	else if(pData[playerid][pTruckerOwnerLowID] != -1)
	{
		id_trucker = pData[playerid][pTruckerOwnerLowID];
	}

	format(String256, sizeof(String256), "SELECT * FROM trucker_stats WHERE trucker_id = '%d' LIMIT 1", id_trucker);
	new Result:trucker_stats = sql_queryEx(zConn, String256, QUERY_CACHED);

	if(sql_num_rows(trucker_stats)) 
	{ 
		new 
			ye, m, d;

		getdate(ye, m, d);

		new 
			trucker_stats_day[8],
			trucker_stats_today,
			trucker_stats_mounth,
			trucker_status_all,
			trucker_stats_prewiow;

  		trucker_stats_day[1] = sql_get_field_assoc_int(trucker_stats, "stats_day_1");
  		trucker_stats_day[2] = sql_get_field_assoc_int(trucker_stats, "stats_day_2");
  		trucker_stats_day[3] = sql_get_field_assoc_int(trucker_stats, "stats_day_3");
  		trucker_stats_day[4] = sql_get_field_assoc_int(trucker_stats, "stats_day_4");
  		trucker_stats_day[5] = sql_get_field_assoc_int(trucker_stats, "stats_day_5");
  		trucker_stats_day[6] = sql_get_field_assoc_int(trucker_stats, "stats_day_6");
  		trucker_stats_day[7] = sql_get_field_assoc_int(trucker_stats, "stats_day_7");

  		trucker_stats_today = sql_get_field_assoc_int(trucker_stats, "stats_today");
  		trucker_stats_mounth = sql_get_field_assoc_int(trucker_stats, "stats_mounth");
  		trucker_status_all = sql_get_field_assoc_int(trucker_stats, "stats_all_time");
  		trucker_stats_prewiow = sql_get_field_assoc_int(trucker_stats, "stats_mounth_back");

  		new 
  			all_day_seven = trucker_stats_day[1]+trucker_stats_day[2]+trucker_stats_day[3]+trucker_stats_day[4]+trucker_stats_day[5]+trucker_stats_day[6]+trucker_stats_day[7];

		switch(id_trucker)
		{
			case TRUCKER_BASE_STATION_1:
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

		        get_color_st_trucker(trucker_stats_day[1], trucker_stats_day[1]), trucker_stats_day[1],
		        get_color_st_trucker(trucker_stats_day[2], trucker_stats_day[1]), trucker_stats_day[2], get_color_st_phrase(trucker_stats_day[2], trucker_stats_day[1]), get_percent_trucker_c(trucker_stats_day[2], trucker_stats_day[1]), 
		        get_color_st_trucker(trucker_stats_day[3], trucker_stats_day[2]), trucker_stats_day[3], get_color_st_phrase(trucker_stats_day[3], trucker_stats_day[1]), get_percent_trucker_c(trucker_stats_day[3], trucker_stats_day[2]), 
		        get_color_st_trucker(trucker_stats_day[4], trucker_stats_day[3]), trucker_stats_day[4], get_color_st_phrase(trucker_stats_day[4], trucker_stats_day[1]), get_percent_trucker_c(trucker_stats_day[4], trucker_stats_day[3]), 
		        get_color_st_trucker(trucker_stats_day[5], trucker_stats_day[4]), trucker_stats_day[5], get_color_st_phrase(trucker_stats_day[5], trucker_stats_day[1]), get_percent_trucker_c(trucker_stats_day[5], trucker_stats_day[4]), 
		        get_color_st_trucker(trucker_stats_day[6], trucker_stats_day[5]), trucker_stats_day[6], get_color_st_phrase(trucker_stats_day[6], trucker_stats_day[1]), get_percent_trucker_c(trucker_stats_day[6], trucker_stats_day[5]), 
		        get_color_st_trucker(trucker_stats_day[7], trucker_stats_day[6]), trucker_stats_day[7], get_color_st_phrase(trucker_stats_day[7], trucker_stats_day[1]), get_percent_trucker_c(trucker_stats_day[7], trucker_stats_day[6]), 
		        mounth_trucker_stats[m], get_color_st_trucker(trucker_stats_mounth, trucker_stats_prewiow), trucker_stats_mounth, get_color_st_phrase(trucker_stats_mounth, trucker_stats_prewiow), get_percent_trucker_c(trucker_stats_mounth, trucker_stats_prewiow), 
		        mounth_trucker_stats[m-1], trucker_stats_prewiow,
		        all_day_seven,
		        trucker_status_all,
		        trucker_stats_today);
			    SPD(playerid, DIALOG_PERSONAL_CLOSE, DIALOG_STYLE_TABLIST_HEADERS, !""cORANGE"Статистика ТК", String4096, !"Закрыть", ""); 
			}
			case TRUCKER_BASE_STATION_2:
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

		        get_color_st_trucker(trucker_stats_day[1], trucker_stats_day[1]), trucker_stats_day[1],
		        get_color_st_trucker(trucker_stats_day[2], trucker_stats_day[1]), trucker_stats_day[2], get_color_st_phrase(trucker_stats_day[2], trucker_stats_day[1]), get_percent_trucker_c(trucker_stats_day[2], trucker_stats_day[1]), 
		        get_color_st_trucker(trucker_stats_day[3], trucker_stats_day[2]), trucker_stats_day[3], get_color_st_phrase(trucker_stats_day[3], trucker_stats_day[1]), get_percent_trucker_c(trucker_stats_day[3], trucker_stats_day[2]), 
		        get_color_st_trucker(trucker_stats_day[4], trucker_stats_day[3]), trucker_stats_day[4], get_color_st_phrase(trucker_stats_day[4], trucker_stats_day[1]), get_percent_trucker_c(trucker_stats_day[4], trucker_stats_day[3]), 
		        get_color_st_trucker(trucker_stats_day[5], trucker_stats_day[4]), trucker_stats_day[5], get_color_st_phrase(trucker_stats_day[5], trucker_stats_day[1]), get_percent_trucker_c(trucker_stats_day[5], trucker_stats_day[4]), 
		        get_color_st_trucker(trucker_stats_day[6], trucker_stats_day[5]), trucker_stats_day[6], get_color_st_phrase(trucker_stats_day[6], trucker_stats_day[1]), get_percent_trucker_c(trucker_stats_day[6], trucker_stats_day[5]), 
		        get_color_st_trucker(trucker_stats_day[7], trucker_stats_day[6]), trucker_stats_day[7], get_color_st_phrase(trucker_stats_day[7], trucker_stats_day[1]), get_percent_trucker_c(trucker_stats_day[7], trucker_stats_day[6]), 
		        mounth_trucker_stats[m], get_color_st_trucker(trucker_stats_mounth, trucker_stats_prewiow), trucker_stats_mounth, get_color_st_phrase(trucker_stats_mounth, trucker_stats_prewiow), get_percent_trucker_c(trucker_stats_mounth, trucker_stats_prewiow), 
		        mounth_trucker_stats[m-1], trucker_stats_prewiow,
		        all_day_seven,
		        trucker_status_all,
		        trucker_stats_today);
			    SPD(playerid, DIALOG_PERSONAL_CLOSE, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Статистика ТК", String4096, !"Закрыть", ""); 
			}
			case TRUCKER_BASE_STATION_3:
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

		        get_color_st_trucker(trucker_stats_day[1], trucker_stats_day[1]), trucker_stats_day[1],
		        get_color_st_trucker(trucker_stats_day[2], trucker_stats_day[1]), trucker_stats_day[2], get_color_st_phrase(trucker_stats_day[2], trucker_stats_day[1]), get_percent_trucker_c(trucker_stats_day[2], trucker_stats_day[1]), 
		        get_color_st_trucker(trucker_stats_day[3], trucker_stats_day[2]), trucker_stats_day[3], get_color_st_phrase(trucker_stats_day[3], trucker_stats_day[1]), get_percent_trucker_c(trucker_stats_day[3], trucker_stats_day[2]), 
		        get_color_st_trucker(trucker_stats_day[4], trucker_stats_day[3]), trucker_stats_day[4], get_color_st_phrase(trucker_stats_day[4], trucker_stats_day[1]), get_percent_trucker_c(trucker_stats_day[4], trucker_stats_day[3]), 
		        get_color_st_trucker(trucker_stats_day[5], trucker_stats_day[4]), trucker_stats_day[5], get_color_st_phrase(trucker_stats_day[5], trucker_stats_day[1]), get_percent_trucker_c(trucker_stats_day[5], trucker_stats_day[4]), 
		        get_color_st_trucker(trucker_stats_day[6], trucker_stats_day[5]), trucker_stats_day[6], get_color_st_phrase(trucker_stats_day[6], trucker_stats_day[1]), get_percent_trucker_c(trucker_stats_day[6], trucker_stats_day[5]), 
		        get_color_st_trucker(trucker_stats_day[7], trucker_stats_day[6]), trucker_stats_day[7], get_color_st_phrase(trucker_stats_day[7], trucker_stats_day[1]), get_percent_trucker_c(trucker_stats_day[7], trucker_stats_day[6]), 
		        mounth_trucker_stats[m], get_color_st_trucker(trucker_stats_mounth, trucker_stats_prewiow), trucker_stats_mounth, get_color_st_phrase(trucker_stats_mounth, trucker_stats_prewiow), get_percent_trucker_c(trucker_stats_mounth, trucker_stats_prewiow), 
		        mounth_trucker_stats[m-1], trucker_stats_prewiow,
		        all_day_seven,
		        trucker_status_all,
		        trucker_stats_today);
			    SPD(playerid, DIALOG_PERSONAL_CLOSE, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Статистика ТК", String4096, !"Закрыть", ""); 
			}
		}

  	}
  	sql_free_result(trucker_stats);


	return true;
}


stock invite_trucker_station(playerid, playerid_to)
{

	new 
		id_trucker;

	if(pData[playerid_to][pTruckerOwnerID] != -1)
	{
		id_trucker = pData[playerid_to][pTruckerOwnerID];		
	}
	else if(pData[playerid_to][pTruckerOwnerLowID] != -1)
	{
		id_trucker = pData[playerid_to][pTruckerOwnerLowID];
	}

	if(!pData[playerid][pLicenses][LIC_DRIVING])
		return SendErr(playerid_to, "У игрока нет лицензии на управление транспортом!");

	if(pData[playerid][pTrucker] == id_trucker)
		return SendErr(playerid_to, "Игрок уже является сотрудником Транспортной Компании!");

	if(pData[playerid][pLevel] < 3)
		return SendErr(playerid_to, "У игрока меньше 3 лет проживания в области!");


	pData[playerid][pTrucker] = id_trucker;
	pData[playerid][pTruckerOwnerLowID] = -1;
	pData[playerid][pTruckerRank] = 1;

	pData[playerid][pJob] = SKILL_TRUCKER;

	UpdatePlayerData(playerid,"pTruckerOwnerLowID", pData[playerid][pTruckerOwnerLowID]);	
	UpdatePlayerData(playerid,"pTrucker", pData[playerid][pTrucker]);	
	UpdatePlayerData(playerid,"pTruckerRank", pData[playerid][pTruckerRank]);	
	UpdatePlayerData(playerid, "job", pData[playerid][pJob]);


	format(String1024,sizeof(String1024),"INSERT INTO `trucker_personal`(`id`,`user_id`,`user_rank`) VALUES ('%d','%d','%d')", id_trucker, 
	pData[playerid][pMysqlID], 1);
	sql_queryEx(zConn, String1024, QUERY_THREADED);


	format(String144, sizeof(String144), "[T] В Транспортную Компанию был принят новый сотрудник - %s", pData[playerid][pNickname]);
	send_trucker_job(id_trucker, COLOR_GREY, String144);

	trucker_job_initialization(playerid);

	new mese[120];
	format(mese,sizeof(mese),"подписал(а) контракт на работу в ТК №%d", id_trucker+1);
	MeAction(playerid ,mese);

	offer_clear_accept(playerid);
	offer_clear_accept(playerid_to);

	return true;
}

stock invite_trucker_station_dialog(playerid)
{

	new 
		id_trucker = GetPVarIntNew(playerid, "id_trucker");

	if(pData[playerid][pTrucker] != -1)
		return SendErr(playerid, "Вы уже состоите в транспортной компании");


	pData[playerid][pTrucker] = id_trucker;
	pData[playerid][pTruckerOwnerLowID] = -1;

	pData[playerid][pTruckerRank] = 1;
	UpdatePlayerData(playerid,"pTruckerRank", pData[playerid][pTruckerRank]);	

	pData[playerid][pJob] = SKILL_TRUCKER;

	UpdatePlayerData(playerid,"pTruckerOwnerLowID", pData[playerid][pTruckerOwnerLowID]);	
	UpdatePlayerData(playerid,"pTrucker", pData[playerid][pTrucker]);	
	UpdatePlayerData(playerid, "job", pData[playerid][pJob]);


	format(String1024,sizeof(String1024),"INSERT INTO `trucker_personal`(`id`,`user_id`,`user_rank`) VALUES ('%d','%d','%d')", id_trucker, 
	pData[playerid][pMysqlID], 1);
	sql_queryEx(zConn, String1024, QUERY_THREADED);


	format(String144, sizeof(String144), "[T] В Транспортную Компанию был принят новый сотрудник - %s", pData[playerid][pNickname]);
	send_trucker_job(id_trucker, COLOR_GREY, String144);

	new mese[120];
	format(mese,sizeof(mese),"подписал(а) контракт на работу в ТК №%d", id_trucker+1);
	MeAction(playerid ,mese);

	trucker_job_initialization(playerid);

	DeletePVarNew(playerid, "id_trucker");

	offer_clear_accept(playerid);

	return true;
}



stock send_trucker_job(trucker_id, color, msg[])
{
	foreach(new i: logged_players)
	{
		if(!IsPlayerConnected(i)) continue;
		if(pData[i][pTrucker] == trucker_id)
		{
			SendClientMessage(i, color, msg);
		}
	}
	return true;
}

CMD:tm(playerid, params[])
{
	if(pData[playerid][pTrucker] == -1) 
		return SendErr(playerid, "Чтобы использовать чат работы, нужно устроиться на работу");

	if(pData[playerid][pMut])
	{
		return SendErr(playerid, "У Вас бан чата. Используйте /mutetime чтобы узнать время бана.");
	}
	if(pTemp[playerid][pMutM])
	{
		return SendErr(playerid, "У Вас затычка во рту.");
	}

	if(pData[playerid][pMutTK])
		return SendErr(playerid, "У вас блокировка чата рации ТК! Используйте /time!");


	if(sscanf(params, "s[90]", params[0])) 
		return SendInf(playerid, "/tm [Текст] чтобы написать в чат дальнобойщиков (IC информация)");

	switch(pData[playerid][pTrucker])
	{
		case 0:
		{
			format(String256, sizeof(String256), "[TRUCKER] %s %s [%d]: "cWH"%s", trucker_rank_name[pData[playerid][pTruckerRank]],  pData[playerid][pNickname], playerid, params[0]);
			send_trucker_job(0, COLOR_BLUE, String256);
		}
		case 1:
		{
			format(String256, sizeof(String256), "[TRUCKER] %s %s [%d]: "cWH"%s", trucker_rank_name[pData[playerid][pTruckerRank]],  pData[playerid][pNickname], playerid, params[0]);
			send_trucker_job(1, COLOR_BLUE, String256);
		}
		case 2:
		{
			format(String256, sizeof(String256), "[TRUCKER] %s %s [%d]: "cWH"%s", trucker_rank_name[pData[playerid][pTruckerRank]],  pData[playerid][pNickname], playerid, params[0]);
			send_trucker_job(2, COLOR_BLUE, String256);
		}
	}

	return true;
}

stock trucker_job_initialization(playerid)
{


	format(String256, sizeof(String256), "SELECT * FROM trucker_personal WHERE user_id = '%d' LIMIT 1", pData[playerid][pMysqlID]);
	new Result:trucker_find_pers = sql_queryEx(zConn, String256, QUERY_CACHED);

	if(sql_num_rows(trucker_find_pers)) 
	{
		new 
			trucker_rank;


  		trucker_rank = sql_get_field_assoc_int(trucker_find_pers, "user_rank");
  		pData[playerid][pTruckerRank] = trucker_rank;
  		UpdatePlayerData(playerid,"pTruckerRank", pData[playerid][pTruckerRank]);

	}	
	sql_free_result(trucker_find_pers);

	return true;
}

stock trucker_job_stats(playerid)
{
	if(pData[playerid][pTrucker] == -1)
		return true;

	format(String256, sizeof(String256), "SELECT * FROM trucker_personal WHERE user_id = '%d' LIMIT 1", pData[playerid][pMysqlID]);
	new Result:trucker_find_pers = sql_queryEx(zConn, String256, QUERY_CACHED);

	if(sql_num_rows(trucker_find_pers)) 
	{
		new 
			mehcnaic_date[32],
			mech_user_money_day,
			mech_user_money_all;


  		mech_user_money_day = sql_get_field_assoc_int(trucker_find_pers, "user_money_day");
  		mech_user_money_all = sql_get_field_assoc_int(trucker_find_pers, "user_money_all");

  		sql_get_field_assoc(trucker_find_pers, "user_data_join", mehcnaic_date, 20);


	    format(String1024, sizeof(String1024), "\
        "cGREY"Тип\t"cGREY"Информация\t\n\
        "cBLUE"- "cWH"Доход за день\t"cGR"%d рублей\n\
        "cBLUE"- "cWH"Общий доход за всё время\t"cGR"%d рублей\n\
        "cBLUE"\t\n\
        "cBLUE"- "cWH"Должность\t"cGREY"%s\n\
        "cBLUE"- "cWH"Дата вступления\t"cGREY"%s", 
        mech_user_money_day, mech_user_money_all,
        trucker_rank_name[pData[playerid][pTruckerRank]], mehcnaic_date);
	    SPD(playerid, 0, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Ваш доход в ТК:", String1024, !"Закрыть", ""); 

	}	
	sql_free_result(trucker_find_pers);



	return true;
}

stock job_trucker_station(playerid, trucker_id)
{
	if(pData[playerid][pTrucker] == -1)
		return true;


    format(String256, sizeof(String256), "\
    "cGREY"Пункт\t"cGREY"Действие\n\
    "cBLUE"1. "cWH"Работа\t"cGR"Приступить\n\
    "cBLUE"2. "cWH"Общая статистика дальнобойщиком\t"cGR"Открыть\n\
   	"cBLUE"3. "cWH"Уволиться из компании\t"cGR"Открыть");
    SPD(playerid, DIALOG_START_TRUCKER_JOB_1, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Работа В Транспортную Компанию", String256, !"Выбрать", !"Закрыть"); 			
	return true;
}

stock leave_job_trucker(playerid)
{
	if(pData[playerid][pTruckerRank] == 0)
		return SendErr(playerid, "Вы не работаете в ТК");

	new 
		trucker_id = pData[playerid][pTrucker];

	pData[playerid][pTrucker] = -1;
	pData[playerid][pTruckerOwnerLowID] = -1;
	pData[playerid][pTruckerRank] = 0;
	pData[playerid][pJob] = 0;

	UpdatePlayerData(playerid,"pTrucker", pData[playerid][pTrucker]);
	UpdatePlayerData(playerid,"pTruckerOwnerLowID", pData[playerid][pTruckerOwnerLowID]);
	UpdatePlayerData(playerid,"pTruckerRank", pData[playerid][pTruckerRank]);
	UpdatePlayerData(playerid, "job", pData[playerid][pJob]);

	format(String256,sizeof(String256),"DELETE FROM `trucker_personal` WHERE `user_id` = '%d'", pData[playerid][pMysqlID]);
	sql_queryEx(zConn, String256, QUERY_THREADED);

	format(String256,sizeof(String256),"UPDATE `accounts` SET `pTrucker` = '-1', `pTruckerOwnerLowID` = '-1', `job` = '0'  WHERE `id` = '%i'", pData[playerid][pMysqlID]);
	sql_queryEx(zConn, String256, QUERY_THREADED);

	SendSucc(playerid, "Вы успешно уволились из Транспортной Компании!");

	format(String256, sizeof(String256), "[TRUCK] Сотрудник %s самостоятельно уволился из Транспортной Компании", pData[playerid][pNickname]);
	send_trucker_job(trucker_id, COLOR_GREY, String256);		

	return true;
}

stock dialog_job_trucker(playerid)
{
	if(pData[playerid][pTruckerRank] == 0)
		return SendErr(playerid, "Вы не работаете в ТК");

	if(trucker_count_truck[pData[playerid][pTrucker]] == 0)
		return SendErr(playerid, "На базе Транспортной Компании недостаточно фур для работы!");

	if(!GetPVarIntNew(playerid, "trucker_job"))
	{
	    format(String256, sizeof(String256), "\
        "cBLUE"-"cWH" Вы хотите начать рабочий день дальнобойщиком?\n\n\
        Вам предстоит выполнять заказы и развозить грузы определенного типа, который Вы выберите!");
		SPD(playerid, DIALOG_START_JOB_TRUCKER, DIALOG_STYLE_MSGBOX, !""cBLUE"Начало работы", String256, !"Далее", !"Нет");
	}
	else
	{

		SPD(playerid, DIALOG_START_JOB_TRUCKER, DIALOG_STYLE_MSGBOX, !""cBLUE"Окончание работы В Транспортной Компании", !"\
		"cWH"Вы хотите закончить работать дальнобойщиком?", !"Начать", !"Нет");			
	}

	return true;
}

stock start_trucker_job(playerid)
{

	if(pData[playerid][pTrucker] == -1)
		return SendErr(playerid, "Вы не работаете В Транспортную Компанию, чтобы начать работу!");
	new 
		id_trucker;

	id_trucker = pData[playerid][pTrucker];

	if(trucker_count_truck[id_trucker] == 0)
		return SendErr(playerid, "На базе Транспортной Компании недостаточно фур для работы!");


	if(get_job_level(playerid, SKILL_TRUCKER) == 0)
	{
		add_player_job_skill(playerid, SKILL_TRUCKER, 1);
	}

	format(String144, sizeof(String144), "[TRUCKER] %s %s[%d] начал работу", trucker_rank_name[pData[playerid][pTruckerRank]], pData[playerid][pNickname], playerid);
	send_trucker_job(id_trucker, COLOR_GREY, String144);

	SetPVarIntNew(playerid, "trucker_job", 1);
	SetPVarIntNew(playerid, "trucker_active_job", 1);
	DeletePVarNew(playerid, "trucker_work_active_gruz");

	return true;
}

stock end_trucker_job(playerid)
{

	if(!GetPVarIntNew(playerid, "trucker_job"))
		return true;

	if(pData[playerid][pTrucker] == -1)
		return SendErr(playerid, "Вы не работаете В Транспортную Компанию, чтобы закончить работу!");

	new 
		id_trucker;

	id_trucker = pData[playerid][pTrucker];


	format(String144, sizeof(String144), "[TRUCKER] %s %s[%d] закончил работу", trucker_rank_name[pData[playerid][pTruckerRank]], pData[playerid][pNickname], playerid);
	send_trucker_job(id_trucker, COLOR_GREY, String144);


	unrent_job_trucker(playerid);

	DeletePVarNew(playerid, "trucker_active_job");
	DeletePVarNew(playerid, "trucker_job");

	SetPlayerSkin(playerid, pData[playerid][pSkin]);


	SendSucc(playerid, "Вы успешно закончили рабочий день В Транспортную Компанию");

	DeletePVarNew(playerid, "trucker_work_active_gruz");
	DeletePVarNew(playerid, "player_load_trucker");
	return true;
}

stock unrent_job_trucker(playerid)
{ 
	if(!GetPVarIntNew(playerid, "trucker_job"))
		return true;


	DeletePVarNew(playerid, "type_job_trucker");
	DeletePVarNew(playerid, "trucker_load_miner");
	DeletePVarNew(playerid, "trucker_load_zavod");
	DeletePVarNew(playerid, "trucker_load_shop");
	DeletePVarNew(playerid, "trucker_load_fill_1");
	DeletePVarNew(playerid, "trucker_load_fill_2");
	DeletePVarNew(playerid, "trucker_load_samwill");

	new 
		v = pTemp[playerid][rent_car];

	if(v == INVALID_VEHICLE_ID) 
		return true;

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:info_gui_vehicle_unrent", 3500);
	
	DestroyVehicle(v);
	DisablePlayerRaceCheckpoint(playerid);
	destroy_truck_trailer(playerid);

	pTemp[playerid][rent_car] = INVALID_VEHICLE_ID;
	pTemp[playerid][rent_car_spawn_timer] = INVALID_TIMER_ID;

	DeletePVarNew(playerid, "player_load_trucker");

	trucker_count_truck[pData[playerid][pTrucker]]++;

	return true;
}


stock get_color_m_trucker(money)
{
	new color[10];

	if(money < 0) color = ""cLRED"";
	if(money > 0) color = ""cGR"";
	if(money == 0) color = ""cGR"";

	return color;
}

stock get_trucker_color(trucker_id)
{
	new 
		color[10];

	if(trucker_id == TRUCKER_BASE_STATION_1) color = ""cORANGE"";
	if(trucker_id == TRUCKER_BASE_STATION_2) color = ""cBLUE"";
	if(trucker_id == TRUCKER_BASE_STATION_3) color = ""cLRED"";

	return color;
}

stock get_color_st_trucker(money_first, money_previow)
{
	new 
		color[10];

	if(money_first == money_previow) color = ""cYELLOW"";
	if(money_previow > money_first) color = ""cLRED"";
	if(money_previow < money_first) color = ""cGR"";

	return color;
}

stock get_color_st_phrase(money_first, money_previow)
{
	new 
		color[25];

	if(money_first == money_previow) color = ""cGR"Больше на";
	if(money_previow > money_first) color = ""cLRED"Меньше на";
	if(money_previow < money_first) color = ""cGR"Больше на";

	return color;
}

stock get_percent_trucker_c(money_previow, money_first)
{

	new 
		final_money = money_previow - money_first;
	
	return final_money;
}

CMD:tinvite(playerid, params[])
{

	if(pData[playerid][pTruckerOwnerID] != -1 && pData[playerid][pTruckerOwnerLowID] == -1 || pData[playerid][pTruckerOwnerID] == -1 && pData[playerid][pTruckerOwnerLowID] != -1)
	{
	
		if(sscanf(params, "d", params[0])) 
			return SendInf(playerid, "/tinvite [ID игрока]");

		format(String128, sizeof(String128), "SELECT id FROM `trucker_personal` WHERE id = '%d'", pData[playerid][pTrucker]);
		new Result:count_personal = sql_queryEx(zConn, String128, QUERY_CACHED);

		new 
			count_trucker_personal = sql_num_rows(count_personal);

		sql_free_result(count_personal);

		if(count_trucker_personal > trucker_station[pData[playerid][pTrucker]][trucker_person_count])
			return SendErr(playerid, "Запрещено принимать в Транспортную Компанию больше разрешенного количества!");

		if(pData[params[0]][pTrucker] != -1)
			return SendErr(playerid, "Игрок уже состоит в транспортной компании!");

		if(!pData[params[0]][pLicenses][LIC_DRIVING])
			return SendErr(playerid, "У игрока нет лицензии на управление транспортом!");


		if(pData[params[0]][pMech] != -1)
			return SendErr(playerid, "Игрок уже состоит в СТО!");
		if(pData[params[0]][pTaxi] != -1)
			return SendErr(playerid, "Игрок уже состоит в Такси!");
		offer_player(playerid, params[0], OFFER_TRUCKER_INVITE);
	}
	else
	{
		SendErr(playerid, "Вы не владеете Транспортной Компанией или не являетесь заместителем!");
	}
	return true;
}

CMD:tuninvite(playerid, params[])
{
	if(pData[playerid][pTruckerOwnerID] != -1 && pData[playerid][pTruckerOwnerLowID] == -1 || pData[playerid][pTruckerOwnerID] == -1 && pData[playerid][pTruckerOwnerLowID] != -1)
	{
	
		if(sscanf(params, "d", params[0])) 
			return SendInf(playerid, "/tuninvite [ID игрока]");

		if(!IsPlayerConnected(params[0]) || params[0] == playerid) 
			return SendInf(playerid, "Неверный ID игрока");

		if(!pData[params[0]][pLicenses][LIC_DRIVING])
			return SendErr(playerid, "У игрока нет лицензии на управление транспортом!");


		if(pData[params[0]][pTrucker] != pData[playerid][pTrucker])
			return SendErr(playerid, "Игрок не состоит в Вашей Транспортной Компании");

		new 
			id_trucker = pData[playerid][pTrucker];

		if(trucker_station[id_trucker][trucker_block_uninvite])
			return SendErr(playerid, "Возможность изменять персонал в ТК отключена!");


		uninvite_command_pers_trucker(playerid, params[0]);
	}
	else
	{
		SendErr(playerid, "Вы не владеете Транспортной Компанией или не являетесь заместителем!");
	}
	return true;
}

CMD:tmute(playerid, params[])
{
	if(pData[playerid][pTruckerOwnerID] != -1 && pData[playerid][pTruckerOwnerLowID] == -1 || pData[playerid][pTruckerOwnerID] == -1 && pData[playerid][pTruckerOwnerLowID] != -1)
	{
	
		if(sscanf(params, "dds[64]", params[0], params[1], params[2])) 
			return SendInf(playerid, "/tmute [ID игрока] [К-во минут] [Причина]");

		if(!IsPlayerConnected(params[0]) || params[0] == playerid) 
			return SendInf(playerid, "Неверный ID игрока");

		if(pData[params[0]][pTrucker] != pData[playerid][pTrucker])
			return SendErr(playerid, "Игрок не состоит в Вашей Транспортной Компании");

		new 
			id_trucker = pData[playerid][pTrucker];

		if(trucker_station[id_trucker][trucker_block_uninvite])
			return SendErr(playerid, "Возможность изменять персонал в ТК отключена!");

		new 
			id = params[0];
		new time = params[1];
		if(time < 10 || time > 180) 
			return SendErr(playerid,"Введите время от 10 до 180 минут");

		if(pData[id][pMutTK] > 0) 
			return SendErr(playerid, "Данному игроку уже выдан бан чата рации!");

		pData[id][pMutTK] = time;
		UpdatePlayerData(id,"pMutTK",time);

		format(String256, sizeof(String256), "[TRUCKER] %s[%d] выдал блокировку рации %s[%d] на %d минут. Причина: %s", pData[playerid][pNickname], playerid,
		pData[id][pNickname], id, time, params[2]);
		send_trucker_job(id_trucker, COLOR_GREY, String256);
	}
	else
	{
		SendErr(playerid, "Вы не владеете Транспортной Компанией или не являетесь заместителем!");
	}
	return true;
}

CMD:tunmute(playerid, params[])
{
	if(pData[playerid][pTruckerOwnerID] != -1 && pData[playerid][pTruckerOwnerLowID] == -1 || pData[playerid][pTruckerOwnerID] == -1 && pData[playerid][pTruckerOwnerLowID] != -1)
	{
	
		if(sscanf(params, "d", params[0])) 
			return SendInf(playerid, "/tunmute [ID игрока]");

		if(!IsPlayerConnected(params[0]) || params[0] == playerid) 
			return SendInf(playerid, "Неверный ID игрока");

		if(pData[params[0]][pTrucker] != pData[playerid][pTrucker])
			return SendErr(playerid, "Игрок не состоит в Вашей Транспортной Компании");

		new 
			id_trucker = pData[playerid][pTrucker];

		if(trucker_station[id_trucker][trucker_block_uninvite])
			return SendErr(playerid, "Возможность изменять персонал в ТК отключена!");


		if(pData[params[0]][pMutTK] == 0) 
			return SendErr(playerid, "У данного игрока нет блокировки рации!");

		pData[params[0]][pMutTK] = 0;
		UpdatePlayerData(params[0],"pMutTK",0);

		format(String256, sizeof(String256), "[TRUCKER] %s[%d] снял блокировку рации с %s[%d]", pData[playerid][pNickname], playerid,
		pData[params[0]][pNickname], params[0]);
		send_trucker_job(id_trucker, COLOR_GREY, String256);
	}
	else
	{
		SendErr(playerid, "Вы не владеете Транспортной Компанией или не являетесь заместителем!");
	}
	return true;
}




CMD:tstats(playerid)
{

	if(pData[playerid][pTrucker] == -1)
		return SendErr(playerid, "Вы не работаете В Транспортную Компанию, чтобы просмотреть свою статистику!");

	return trucker_job_stats(playerid);
}

stock pay_trucker_money(playerid, pay_playerid, money, text[])
{
	new 
		id_trucker;

	id_trucker = pData[pay_playerid][pTrucker];

	if(GetPlayerMoney(playerid) < 0) ResetPlayerMoney(playerid);
	if(GetPlayerMoney(pay_playerid) < 0) ResetPlayerMoney(pay_playerid);

	new 
		percent_money = percent_money_trucker(money, trucker_station[id_trucker][trucker_base_percent]);

	trucker_station[id_trucker][trucker_base_bank] += percent_money;	

	save_trucker_base();

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

stock percent_money_trucker(x, y)
{
    new 
    	money_final = (x/100) * y;

    return money_final;
}

























stock job_trucker_base(playerid, type)
{
	if(pData[playerid][pTrucker] == -1)
		return SendErr(playerid, "Вы не работаете в транспортной компании!");


	if(type == TRUCKER_BASE_STATION_1)
	{
		if(pData[playerid][pTrucker] != TRUCKER_BASE_STATION_1)
			return SendErr(playerid, "Вы не работаете в данной транспортной компании!");

		return show_info_start_job(playerid, TRUCKER_BASE_STATION_1);
	}
	if(type == TRUCKER_BASE_STATION_2)
	{
		if(pData[playerid][pTrucker] != TRUCKER_BASE_STATION_2)
			return SendErr(playerid, "Вы не работаете в данной транспортной компании!");

		return show_info_start_job(playerid, TRUCKER_BASE_STATION_2);
	}
	if(type == TRUCKER_BASE_STATION_3)
	{
		if(pData[playerid][pTrucker] != TRUCKER_BASE_STATION_3)
			return SendErr(playerid, "Вы не работаете в данной транспортной компании!");

		return show_info_start_job(playerid, TRUCKER_BASE_STATION_3);
	}
	return true;
}

stock show_info_start_job(playerid, type)
{
	if(pData[playerid][pTrucker] == -1)
		return SendErr(playerid, "Вы не работаете в транспортной компании!");


	if(type == TRUCKER_BASE_STATION_1)
	{
		if(pData[playerid][pTrucker] != TRUCKER_BASE_STATION_1)
			return SendErr(playerid, "Вы не работаете в данной транспортной компании!");

	    dialog_job_trucker(playerid);


	}
	if(type == TRUCKER_BASE_STATION_2)
	{
		if(pData[playerid][pTrucker] != TRUCKER_BASE_STATION_2)
			return SendErr(playerid, "Вы не работаете в данной транспортной компании!");

	    dialog_job_trucker(playerid);
	}	


	if(type == TRUCKER_BASE_STATION_3)
	{
		if(pData[playerid][pTrucker] != TRUCKER_BASE_STATION_3)
			return SendErr(playerid, "Вы не работаете в данной транспортной компании!");

	    dialog_job_trucker(playerid);
	}

	return true;
}

stock select_type_job_trucker(playerid)
{
	show_trucker_menu_select(playerid);

	return true;
}

stock select_job_trucker_final(playerid, type)
{

	switch(type)
	{
		case TRUCKER_JOB_ZAVOD:
		{
			new Result:find_magazing_orders = sql_queryEx(zConn, "SELECT * FROM `magazinorders`", QUERY_CACHED);

			new 
				biz_id = sql_num_rows(find_magazing_orders);

			if(sql_num_rows(find_magazing_orders)) 
			{
				SelectTextDraw(playerid, COLOR_BLUE);
				return SendErr(playerid, "Присутствуют активные грузы для бизнесов! Невозможно выбрать!");
			}
			SetPVarIntNew(playerid, "type_job_trucker", type);
			start_job_trucker_final(playerid);
		}
		case TRUCKER_JOB_SAMWILL:
		{
			new Result:find_magazing_orders = sql_queryEx(zConn, "SELECT * FROM `magazinorders`", QUERY_CACHED);

			new 
				biz_id = sql_num_rows(find_magazing_orders);

			if(sql_num_rows(find_magazing_orders)) 
			{
				SelectTextDraw(playerid, COLOR_BLUE);
				return SendErr(playerid, "Присутствуют активные грузы для бизнесов! Невозможно выбрать!");
			}
			SetPVarIntNew(playerid, "type_job_trucker", type);
			start_job_trucker_final(playerid);
		}
		case TRUCKER_JOB_MINER:
		{
			new Result:find_magazing_orders = sql_queryEx(zConn, "SELECT * FROM `magazinorders`", QUERY_CACHED);

			new 
				biz_id = sql_num_rows(find_magazing_orders);

			if(sql_num_rows(find_magazing_orders)) 
			{
				SelectTextDraw(playerid, COLOR_BLUE);
				return SendErr(playerid, "Присутствуют активные грузы для бизнесов! Невозможно выбрать!");
			}
			SetPVarIntNew(playerid, "type_job_trucker", type);
			start_job_trucker_final(playerid);
		}
	}


	SetPVarIntNew(playerid, "type_job_trucker", type);
	start_job_trucker_final(playerid);
	return true;
}


stock start_job_trucker_final(playerid)
{
	if(pData[playerid][pTrucker] == -1)
		return SendErr(playerid, "Вы не работаете в транспортной компании!");

	new 	
		type = pData[playerid][pTrucker];

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

	if(trucker_count_truck[type] == 0)
		return SendErr(playerid, "На базе Транспортной Компании недостаточно фур для работы!");

	SetPVarIntNew(playerid, "trucker_job", 1);

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_work_16", 5000);

	if(type == TRUCKER_BASE_STATION_1)
	{

		new 
			random_pos = random(15);

		new 
			c1 = trucker_station[type][trucker_car_color],
			c2 = trucker_station[type][trucker_car_color];	

		new 
			trucker_base_station_1;

		if(GetPVarIntNew(playerid, "type_job_trucker") == TRUCKER_JOB_FILL_1 || GetPVarIntNew(playerid, "type_job_trucker") == TRUCKER_JOB_FILL_2)
		{
			if(trucker_station[type][trucker_level_veh] == 1)
			{
				trucker_base_station_1 = CreateVehicle(414, position_spawn_trucker_1[random_pos][0], position_spawn_trucker_1[random_pos][1], position_spawn_trucker_1[random_pos][2], position_spawn_trucker_1[random_pos][3], c1, c2, 600);	
			}
			else if(trucker_station[type][trucker_level_veh] == 2)
			{
				trucker_base_station_1 = CreateVehicle(403, position_spawn_trucker_1[random_pos][0], position_spawn_trucker_1[random_pos][1], position_spawn_trucker_1[random_pos][2], position_spawn_trucker_1[random_pos][3], c1, c2, 600);	
			}	
			else if(trucker_station[type][trucker_level_veh] == 3)
			{
				trucker_base_station_1 = CreateVehicle(514, position_spawn_trucker_1[random_pos][0], position_spawn_trucker_1[random_pos][1], position_spawn_trucker_1[random_pos][2], position_spawn_trucker_1[random_pos][3], c1, c2, 600);	
			}		
		}
		else 
		{
			if(trucker_station[type][trucker_level_veh] == 1)
			{
				trucker_base_station_1 = CreateVehicle(456, position_spawn_trucker_1[random_pos][0], position_spawn_trucker_1[random_pos][1], position_spawn_trucker_1[random_pos][2], position_spawn_trucker_1[random_pos][3], c1, c2, 600);	
			}
			else if(trucker_station[type][trucker_level_veh] == 2)
			{
				trucker_base_station_1 = CreateVehicle(403, position_spawn_trucker_1[random_pos][0], position_spawn_trucker_1[random_pos][1], position_spawn_trucker_1[random_pos][2], position_spawn_trucker_1[random_pos][3], c1, c2, 600);	
			}	
			else if(trucker_station[type][trucker_level_veh] == 3)
			{
				trucker_base_station_1 = CreateVehicle(514, position_spawn_trucker_1[random_pos][0], position_spawn_trucker_1[random_pos][1], position_spawn_trucker_1[random_pos][2], position_spawn_trucker_1[random_pos][3], c1, c2, 600);	
			}
		}

		PutPlayerInVehicleEx(playerid, trucker_base_station_1, 0);

		vehicle[trucker_base_station_1][cFuel] = 60.0;
		vehicle[trucker_base_station_1][cHealth] = 1000.0;
		vehicle[trucker_base_station_1][cIsCreated] = true;
		vehicle[trucker_base_station_1][consumables_oil] = 1000.0;

		vehicle[trucker_base_station_1][cOwnTo] = VEHICLE_TRUCKER_1;

		vehicle[trucker_base_station_1][cLock] = 2;

		vehicle[trucker_base_station_1][consumables_oil] = 1000.0;

		vehicle_lock_status(trucker_base_station_1, true);

		new
			v = trucker_base_station_1;	

		pTemp[playerid][rent_car] = v;

		trucker_count_truck[TRUCKER_BASE_STATION_1]--;


	}
	if(type == TRUCKER_BASE_STATION_2)
	{

		new 
			random_pos = random(15);

		new 
			c1 = trucker_station[type][trucker_car_color],
			c2 = trucker_station[type][trucker_car_color];	

		new 
			trucker_base_station_2;

		if(GetPVarIntNew(playerid, "type_job_trucker") == TRUCKER_JOB_FILL_1 || GetPVarIntNew(playerid, "type_job_trucker") == TRUCKER_JOB_FILL_2)
		{
			if(trucker_station[type][trucker_level_veh] == 1)
			{
				trucker_base_station_2 = CreateVehicle(414, position_spawn_trucker_2[random_pos][0], position_spawn_trucker_2[random_pos][1], position_spawn_trucker_2[random_pos][2], position_spawn_trucker_2[random_pos][3], c1, c2, 600);	
			}
			else if(trucker_station[type][trucker_level_veh] == 2)
			{
				trucker_base_station_2 = CreateVehicle(403, position_spawn_trucker_2[random_pos][0], position_spawn_trucker_2[random_pos][1], position_spawn_trucker_2[random_pos][2], position_spawn_trucker_2[random_pos][3], c1, c2, 600);	
			}	
			else if(trucker_station[type][trucker_level_veh] == 3)
			{
				trucker_base_station_2 = CreateVehicle(514, position_spawn_trucker_2[random_pos][0], position_spawn_trucker_2[random_pos][1], position_spawn_trucker_2[random_pos][2], position_spawn_trucker_2[random_pos][3], c1, c2, 600);	
			}		
		}
		else 
		{
			if(trucker_station[type][trucker_level_veh] == 1)
			{
				trucker_base_station_2 = CreateVehicle(456, position_spawn_trucker_2[random_pos][0], position_spawn_trucker_2[random_pos][1], position_spawn_trucker_2[random_pos][2], position_spawn_trucker_2[random_pos][3], c1, c2, 600);	
			}
			else if(trucker_station[type][trucker_level_veh] == 2)
			{
				trucker_base_station_2 = CreateVehicle(403, position_spawn_trucker_2[random_pos][0], position_spawn_trucker_2[random_pos][1], position_spawn_trucker_2[random_pos][2], position_spawn_trucker_2[random_pos][3], c1, c2, 600);	
			}	
			else if(trucker_station[type][trucker_level_veh] == 3)
			{
				trucker_base_station_2 = CreateVehicle(514, position_spawn_trucker_2[random_pos][0], position_spawn_trucker_2[random_pos][1], position_spawn_trucker_2[random_pos][2], position_spawn_trucker_2[random_pos][3], c1, c2, 600);	
			}
		}

		PutPlayerInVehicleEx(playerid, trucker_base_station_2, 0);

		vehicle[trucker_base_station_2][cFuel] = 60.0;
		vehicle[trucker_base_station_2][cHealth] = 1000.0;
		vehicle[trucker_base_station_2][cIsCreated] = true;
		vehicle[trucker_base_station_2][consumables_oil] = 1000.0;

		vehicle[trucker_base_station_2][cOwnTo] = VEHICLE_TRUCKER_2;

		vehicle[trucker_base_station_2][cLock] = 2;

		vehicle[trucker_base_station_2][consumables_oil] = 1000.0;

		vehicle_lock_status(trucker_base_station_2, true);

		new
			v = trucker_base_station_2;	

		pTemp[playerid][rent_car] = v;

		trucker_count_truck[TRUCKER_BASE_STATION_2]--;

	}
	if(type == TRUCKER_BASE_STATION_3)
	{

		new 
			random_pos = random(18);

		new 
			c1 = trucker_station[type][trucker_car_color],
			c2 = trucker_station[type][trucker_car_color];	

		new 
			trucker_base_station_3;

		if(GetPVarIntNew(playerid, "type_job_trucker") == TRUCKER_JOB_FILL_1 || GetPVarIntNew(playerid, "type_job_trucker") == TRUCKER_JOB_FILL_2)
		{
			if(trucker_station[type][trucker_level_veh] == 1)
			{
				trucker_base_station_3 = CreateVehicle(414, position_spawn_trucker_3[random_pos][0], position_spawn_trucker_3[random_pos][1], position_spawn_trucker_3[random_pos][2], position_spawn_trucker_3[random_pos][3], c1, c2, 600);	
			}
			else if(trucker_station[type][trucker_level_veh] == 2)
			{
				trucker_base_station_3 = CreateVehicle(403, position_spawn_trucker_3[random_pos][0], position_spawn_trucker_3[random_pos][1], position_spawn_trucker_3[random_pos][2], position_spawn_trucker_3[random_pos][3], c1, c2, 600);	
			}	
			else if(trucker_station[type][trucker_level_veh] == 3)
			{
				trucker_base_station_3 = CreateVehicle(514, position_spawn_trucker_3[random_pos][0], position_spawn_trucker_3[random_pos][1], position_spawn_trucker_3[random_pos][2], position_spawn_trucker_3[random_pos][3], c1, c2, 600);	
			}		
		}
		else 
		{
			if(trucker_station[type][trucker_level_veh] == 1)
			{
				trucker_base_station_3 = CreateVehicle(456, position_spawn_trucker_3[random_pos][0], position_spawn_trucker_3[random_pos][1], position_spawn_trucker_3[random_pos][2], position_spawn_trucker_3[random_pos][3], c1, c2, 600);	
			}
			else if(trucker_station[type][trucker_level_veh] == 2)
			{
				trucker_base_station_3 = CreateVehicle(403, position_spawn_trucker_3[random_pos][0], position_spawn_trucker_3[random_pos][1], position_spawn_trucker_3[random_pos][2], position_spawn_trucker_3[random_pos][3], c1, c2, 600);	
			}	
			else if(trucker_station[type][trucker_level_veh] == 3)
			{
				trucker_base_station_3 = CreateVehicle(514, position_spawn_trucker_3[random_pos][0], position_spawn_trucker_3[random_pos][1], position_spawn_trucker_3[random_pos][2], position_spawn_trucker_3[random_pos][3], c1, c2, 600);	
			}
		}


		PutPlayerInVehicleEx(playerid, trucker_base_station_3, 0);

		vehicle[trucker_base_station_3][cFuel] = 60.0;
		vehicle[trucker_base_station_3][cHealth] = 1000.0;
		vehicle[trucker_base_station_3][cIsCreated] = true;
		vehicle[trucker_base_station_3][consumables_oil] = 1000.0;

		vehicle[trucker_base_station_3][cOwnTo] = VEHICLE_TRUCKER_3;

		vehicle[trucker_base_station_3][cLock] = 2;

		vehicle[trucker_base_station_3][consumables_oil] = 1000.0;

		vehicle_lock_status(trucker_base_station_3, true);

		DisableRemoteVehicleCollisions(playerid, 1);	

		new
			v = trucker_base_station_3;	

		pTemp[playerid][rent_car] = v;

		trucker_count_truck[TRUCKER_BASE_STATION_3]--;

	}
	hide_trucker_menu_select(playerid);
	show_rout_all_trucker(playerid);
	SetPVarIntNew(playerid, "trucker_job", 1);
	return true;
}


stock show_trucker_menu_select(playerid)
{
	TextDrawShowForPlayer(playerid, trucker_select_job[0]);
	TextDrawShowForPlayer(playerid, trucker_select_job[1]);
	TextDrawShowForPlayer(playerid, trucker_select_job[2]);
	TextDrawShowForPlayer(playerid, trucker_select_job[3]);
	TextDrawShowForPlayer(playerid, trucker_select_job[4]);
	TextDrawShowForPlayer(playerid, trucker_select_job[5]);
	TextDrawShowForPlayer(playerid, trucker_select_job[6]);
	TextDrawShowForPlayer(playerid, trucker_select_job[7]);
	TextDrawShowForPlayer(playerid, trucker_select_job[8]);


	SelectTextDraw(playerid, COLOR_BLUE);

	return true;
}

stock hide_trucker_menu_select(playerid)
{
	TextDrawHideForPlayer(playerid, trucker_select_job[0]);
	TextDrawHideForPlayer(playerid, trucker_select_job[1]);
	TextDrawHideForPlayer(playerid, trucker_select_job[2]);
	TextDrawHideForPlayer(playerid, trucker_select_job[3]);
	TextDrawHideForPlayer(playerid, trucker_select_job[4]);
	TextDrawHideForPlayer(playerid, trucker_select_job[5]);
	TextDrawHideForPlayer(playerid, trucker_select_job[6]);
	TextDrawHideForPlayer(playerid, trucker_select_job[7]);
	TextDrawHideForPlayer(playerid, trucker_select_job[8]);

	CancelSelectTextDraw(playerid);

	return true;
}


stock show_rout_all_trucker(playerid)
{
	new 
		type = GetPVarIntNew(playerid, "type_job_trucker");


	switch(type)
	{
		case TRUCKER_JOB_MINER: return show_rout_trucker_miner(playerid);
		case TRUCKER_JOB_ZAVOD: return show_rout_trucker_zavod(playerid);
		case TRUCKER_JOB_SHOP: return show_rout_trucker_shop(playerid);
		case TRUCKER_JOB_FILL_1: return show_rout_trucker_fill_1(playerid);
		case TRUCKER_JOB_FILL_2: return show_rout_trucker_fill_2(playerid);	
		case TRUCKER_JOB_SAMWILL: return show_rout_trucker_samwill(playerid);
	}	
	return true;
}

stock show_rout_trucker_miner(playerid)
{

	if(GetPVarIntNew(playerid, "type_job_trucker") != TRUCKER_JOB_MINER)
		return SendErr(playerid, "Вы не работаете на данном типе доставки!");

	SCM(playerid, -1, "");
	SendInf(playerid, "Отправляйтесь на Горнодобывающее Предприятие г.Арзамас и загрузите руду в фуру!");
	SendInf(playerid, "После загрузки руды, Вы получите дальнейшие инструкции по работе!");
	SendInf(playerid, "Горнодобывающее Предприятие было отмечено у Вас в навигаторе!");


	SetPlayerRaceCheckpoint(playerid, 1, TRUCKER_MINER_LOAD, 0.0, 0.0, 0.0, 8.0);

	SetPVarIntNew(playerid, "trucker_load_miner", 1);
	return true;
}


stock show_rout_trucker_zavod(playerid)
{

	if(GetPVarIntNew(playerid, "type_job_trucker") != TRUCKER_JOB_ZAVOD)
		return SendErr(playerid, "Вы не работаете на данном типе доставки!");

	SCM(playerid, -1, "");
	SendInf(playerid, "Отправляйтесь на Мебельный Завод г.Южный и загрузите готовую продукцию в фуру!");
	SendInf(playerid, "После загрузки, Вы получите дальнейшие инструкции по работе!");
	SendInf(playerid, "Мебельный Завод был отмечен у Вас в навигаторе!");

	SetPlayerRaceCheckpoint(playerid, 1, TRUCKER_ZAVOD_LOAD, 0.0, 0.0, 0.0, 18.0);

	SetPVarIntNew(playerid, "trucker_load_zavod", 1);
	return true;
}

stock show_rout_trucker_shop(playerid)
{
	if(GetPVarIntNew(playerid, "type_job_trucker") != TRUCKER_JOB_SHOP)
		return SendErr(playerid, "Вы не работаете на данном типе доставки!");


	SCM(playerid, -1, "");
	SendInf(playerid, "Отправляйтесь на Продуктовую Базу и загрузите готовую продукцию в фуру!");
	SendInf(playerid, "После загрузки, Вы получите дальнейшие инструкции по работе!");
	SendInf(playerid, "Продуктовая База была отмечена у Вас в навигаторе!");

	SetPlayerRaceCheckpoint(playerid, 1, TRUCKER_SHOP_LOAD, 0.0, 0.0, 0.0, 8.0);

	SetPVarIntNew(playerid, "trucker_load_shop", 1);
	return true;
}


stock show_rout_trucker_fill_1(playerid)
{
	if(GetPVarIntNew(playerid, "type_job_trucker") != TRUCKER_JOB_FILL_1)
		return SendErr(playerid, "Вы не работаете на данном типе доставки!");

	SCM(playerid, -1, "");
	SendInf(playerid, "Отправляйтесь на НПЗ и заправьте в бензовоз готовое топливо!");
	SendInf(playerid, "После заправки, Вы получите дальнейшие инструкции по работе!");
	SendInf(playerid, "НПЗ был отмечен у Вас в навигаторе!");

	SetPlayerRaceCheckpoint(playerid, 1, TRUCKER_FUEL_LOAD, 0.0, 0.0, 0.0, 8.0);

	SetPVarIntNew(playerid, "trucker_load_fill_1", 1);
	return true;
}

stock show_rout_trucker_fill_2(playerid)
{
	if(GetPVarIntNew(playerid, "type_job_trucker") != TRUCKER_JOB_FILL_2)
		return SendErr(playerid, "Вы не работаете на данном типе доставки!");

	SCM(playerid, -1, "");
	SendInf(playerid, "Отправляйтесь на НПЗ и заправьте в бензовоз готовое топливо!");
	SendInf(playerid, "После заправки, Вы получите дальнейшие инструкции по работе!");
	SendInf(playerid, "НПЗ был отмечен у Вас в навигаторе!");

	SetPlayerRaceCheckpoint(playerid, 1, TRUCKER_FUEL_LOAD, 0.0, 0.0, 0.0, 8.0);

	SetPVarIntNew(playerid, "trucker_load_fill_2", 1);
	return true;
}

stock show_rout_trucker_samwill(playerid)
{
	if(GetPVarIntNew(playerid, "type_job_trucker") != TRUCKER_JOB_SAMWILL)
		return SendErr(playerid, "Вы не работаете на данном типе доставки!");

	SCM(playerid, -1, "");
	SendInf(playerid, "Отправляйтесь на Лесопилку и загрузите дерево в фуру!");
	SendInf(playerid, "После загрузки, Вы получите дальнейшие инструкции по работе!");
	SendInf(playerid, "Лесопилка была отмечена у Вас в навигаторе!");

	SetPlayerRaceCheckpoint(playerid, 1, TRUCKER_SAMWILL_LOAD, 0.0, 0.0, 0.0, 8.0);

	SetPVarIntNew(playerid, "trucker_load_samwill", 1);
	return true;
}



stock enter_load_zone_miner(playerid)
{
	if(!GetPVarIntNew(playerid, "trucker_load_miner"))
		return true;

	if(!IsPlayerInAnyVehicle(playerid))
		return SendErr(playerid, "Вы должны находиться в рабочем транспорте!");

	if(GetPlayerVehicleModel(playerid) != TRUCKER_VEH_ID_1 && 
		GetPlayerVehicleModel(playerid) != TRUCKER_VEH_ID_2 && GetPlayerVehicleModel(playerid) != 456)
		return SendErr(playerid, "Вы должны находиться в тягаче!");

	return SPD(playerid, DIALOG_TRUCKER_LOAD_MINER, DIALOG_STYLE_MSGBOX, !""cBLUE"Загрузка руды", \
		""cBLUE"-"cWH" Добро пожаловать на Горнодобывающее Предприятие г.Арзамас!\n\n\
		"cBLUE"-"cWH" Горнодобывающее предприятие добывают руду и другие полезные ископаемые!\n\
		Вашей задачей будет доставить руду на завод для дальнейшей переработки и использования\n\
		За добросовестеное выполнение поставленной задачи, Вы получите денежное вознаграждение!\n\n\
		Готовы ли Вы взять за выполнение работы?", !"Да", !"Нет");

}

stock enter_load_zone_zavod(playerid)
{
	if(!GetPVarIntNew(playerid, "trucker_load_zavod"))
		return true;

	if(!IsPlayerInAnyVehicle(playerid))
		return SendErr(playerid, "Вы должны находиться в рабочем транспорте!");


	if(GetPlayerVehicleModel(playerid) != TRUCKER_VEH_ID_1 && 
		GetPlayerVehicleModel(playerid) != TRUCKER_VEH_ID_2 && GetPlayerVehicleModel(playerid) != 456)
		return SendErr(playerid, "Вы должны находиться в тягаче!");

	return SPD(playerid, DIALOG_TRUCKER_LOAD_ZAVOD, DIALOG_STYLE_MSGBOX, !""cBLUE"Мебельный завод", \
		""cBLUE"-"cWH" Добро пожаловать на Мебельный завод г.Южный!\n\n\
		"cBLUE"-"cWH" Мебельный завод обеспечивает жителей области нужными вещами!\n\
		Вашей задачей будет доставить готовую мебель в магазины для дальнейшей продажи\n\
		За добросовестеное выполнение поставленной задачи, Вы получите денежное вознаграждение!\n\
		Готовы ли Вы взять за выполнение работы?", !"Да", !"Нет");

}

stock enter_load_zone_shop(playerid)
{
	if(!GetPVarIntNew(playerid, "trucker_load_shop"))
		return true;

	if(!IsPlayerInAnyVehicle(playerid))
		return SendErr(playerid, "Вы должны находиться в рабочем транспорте!");


	if(GetPlayerVehicleModel(playerid) != TRUCKER_VEH_ID_1 && 
		GetPlayerVehicleModel(playerid) != TRUCKER_VEH_ID_2 && GetPlayerVehicleModel(playerid) != 456)
		return SendErr(playerid, "Вы должны находиться в тягаче!");

	return SPD(playerid, DIALOG_TRUCKER_LOAD_SHOP, DIALOG_STYLE_MSGBOX, !""cBLUE"Продуктовая база", \
		""cBLUE"-"cWH" Добро пожаловать на Продуктовую Базу!\n\n\
		"cBLUE"-"cWH" Продуктовая база обеспечивает все магазины в области нужными продуктами\n\
		Вашей задачей будет доставить продукты в магазины для дальнейшей продажи\n\
		За добросовестеное выполнение поставленной задачи, Вы получите денежное вознаграждение!\n\n\
		Готовы ли Вы взять за выполнение работы?", !"Да", !"Нет");

}

stock enter_load_zone_fill_1(playerid)
{
	if(!GetPVarIntNew(playerid, "trucker_load_fill_1"))
		return true;

	if(!IsPlayerInAnyVehicle(playerid))
		return SendErr(playerid, "Вы должны находиться в рабочем транспорте!");


	if(GetPlayerVehicleModel(playerid) != TRUCKER_VEH_ID_1 && 
		GetPlayerVehicleModel(playerid) != TRUCKER_VEH_ID_2 && GetPlayerVehicleModel(playerid) != 456)
		return SendErr(playerid, "Вы должны находиться в тягаче!");

	return SPD(playerid, DIALOG_TRUCKER_LOAD_FILL_1, DIALOG_STYLE_MSGBOX, !""cBLUE"НПЗ", \
		""cBLUE"-"cWH" Добро пожаловать на НПЗ!\n\n\
		Вашей задачей будет доставить готовое топливо на заправочные станции Газпром\n\
		За добросовестеное выполнение поставленной задачи, Вы получите денежное вознаграждение!\n\n\
		Готовы ли Вы взять за выполнение работы?", !"Да", !"Нет");

}

stock enter_load_zone_fill_2(playerid)
{
	if(!GetPVarIntNew(playerid, "trucker_load_fill_1"))
		return true;

	if(!IsPlayerInAnyVehicle(playerid))
		return SendErr(playerid, "Вы должны находиться в рабочем транспорте!");


	if(GetPlayerVehicleModel(playerid) != TRUCKER_VEH_ID_1 && 
		GetPlayerVehicleModel(playerid) != TRUCKER_VEH_ID_2 && GetPlayerVehicleModel(playerid) != 456)
		return SendErr(playerid, "Вы должны находиться в тягаче!");

	return SPD(playerid, DIALOG_TRUCKER_LOAD_FILL_2, DIALOG_STYLE_MSGBOX, !""cBLUE"НПЗ", \
		""cBLUE"-"cWH" Добро пожаловать на НПЗ!\n\n\
		Вашей задачей будет доставить готовое топливо на заправочные станции Лукойл\n\
		За добросовестеное выполнение поставленной задачи, Вы получите денежное вознаграждение!\n\n\
		Готовы ли Вы взять за выполнение работы?", !"Да", !"Нет");

}

stock enter_load_zone_samwill(playerid)
{
	if(!GetPVarIntNew(playerid, "trucker_load_samwill"))
		return true;

	if(!IsPlayerInAnyVehicle(playerid))
		return SendErr(playerid, "Вы должны находиться в рабочем транспорте!");


	if(GetPlayerVehicleModel(playerid) != TRUCKER_VEH_ID_1 && 
		GetPlayerVehicleModel(playerid) != TRUCKER_VEH_ID_2 && GetPlayerVehicleModel(playerid) != 456)
		return SendErr(playerid, "Вы должны находиться в тягаче!");

	return SPD(playerid, DIALOG_TRUCKER_LOAD_SAMWILLS, DIALOG_STYLE_MSGBOX, !""cBLUE"Лесопилка", \
		""cBLUE"-"cWH" Добро пожаловать на Лесопилка!\n\n\
		Вашей задачей будет доставить дерево с лесопилки на завод для переработки\n\
		За добросовестеное выполнение поставленной задачи, Вы получите денежное вознаграждение!\n\n\
		Готовы ли Вы взять за выполнение работы?", !"Да", !"Нет");

}

stock visual_trucker_load_gruz(playerid)
{
	new 
		type_load = GetPVarIntNew(playerid, "type_job_trucker");

	switch(type_load)
	{
		case TRUCKER_JOB_MINER:
		{

		}
		case TRUCKER_JOB_ZAVOD:
		{

		}
		case TRUCKER_JOB_SHOP:
		{

		}
		case TRUCKER_JOB_FILL_1:
		{

		}
		case TRUCKER_JOB_FILL_2:
		{

		}
		case TRUCKER_JOB_SAMWILL:
		{

		}
	}

	TogglePlayerControllable(playerid, false);

	return true;
}

stock visual_trucker_load_gruz_final(playerid)
{
	new 
		type_load = GetPVarIntNew(playerid, "type_job_trucker");

	DisablePlayerRaceCheckpoint(playerid);	

	switch(type_load)
	{
		case TRUCKER_JOB_MINER:
		{

			SetPlayerRaceCheckpoint(playerid, 1, TRUCKER_MINER_UNLOAD, 0.0, 0.0, 0.0, 8.0);
			SCM(playerid, -1, "");
			SendInf(playerid, "Точка разгрузки установлена у Вас в навигаторе!");
			SendInf(playerid, "Отправляйтесь на точку разгрузки, разгрузите товар и получите вознаграждение!");

			status_navigator_player(playerid, TEXTDRAW_SHOW);

			new 
				Float:x, 
				Float:y,
				Float:z;

			GetPlayerPos(playerid, x, y, z);

			new 
				price_trucker_work = floatround(GetDistanceBetweenPoints(x, y, z, TRUCKER_MINER_UNLOAD));

			SetPVarIntNew(playerid, "trucker_dist_money_price", price_trucker_work);

			new 
				id_trucker;
			id_trucker = pData[playerid][pTrucker];
			format(String144, sizeof(String144), "[TRUCKER] %s %s[%d] загрузил груз и отправляется к шахте на разгрузку", trucker_rank_name[pData[playerid][pTruckerRank]], pData[playerid][pNickname], playerid);
			send_trucker_job(id_trucker, COLOR_GREY, String144);

		}	
		case TRUCKER_JOB_ZAVOD:
		{
			SetPlayerRaceCheckpoint(playerid, 1, TRUCKER_ZAVOD_UNLOAD, 0.0, 0.0, 0.0, 8.0);
			SCM(playerid, -1, "");
			SendInf(playerid, "Точка разгрузки установлена у Вас в навигаторе!");
			SendInf(playerid, "Отправляйтесь на точку разгрузки, разгрузите товар и получите вознаграждение!");		

			status_navigator_player(playerid, TEXTDRAW_SHOW);

			new 
				Float:x, 
				Float:y,
				Float:z;

			GetPlayerPos(playerid, x, y, z);

			new 
				price_trucker_work = floatround(GetDistanceBetweenPoints(x, y, z, TRUCKER_ZAVOD_UNLOAD));

			SetPVarIntNew(playerid, "trucker_dist_money_price", price_trucker_work);

			new 
				id_trucker;
			id_trucker = pData[playerid][pTrucker];
			format(String144, sizeof(String144), "[TRUCKER] %s %s[%d] загрузил груз и отправляется к заводу на разгрузку", trucker_rank_name[pData[playerid][pTruckerRank]], pData[playerid][pNickname], playerid);
			send_trucker_job(id_trucker, COLOR_GREY, String144);

		}
		case TRUCKER_JOB_SHOP:
		{
			find_active_magazin(playerid);
		}
		case TRUCKER_JOB_FILL_1:
		{
			find_active_fuel_1(playerid);
		}
		case TRUCKER_JOB_FILL_2:
		{
			find_active_fuel_2(playerid);
		}
		case TRUCKER_JOB_SAMWILL:
		{
			SetPlayerRaceCheckpoint(playerid, 1, TRUCKER_SAMWILL_UNLOAD, 0.0, 0.0, 0.0, 8.0);
			SCM(playerid, -1, "");
			SendInf(playerid, "Точка разгрузки установлена у Вас в навигаторе!");
			SendInf(playerid, "Отправляйтесь на точку разгрузки, разгрузите товар и получите вознаграждение!");	

			new 
				Float:x, 
				Float:y,
				Float:z;

			GetPlayerPos(playerid, x, y, z);

			new 
				price_trucker_work = floatround(GetDistanceBetweenPoints(x, y, z, TRUCKER_SAMWILL_UNLOAD));

			SetPVarIntNew(playerid, "trucker_dist_money_price", price_trucker_work);

			status_navigator_player(playerid, TEXTDRAW_SHOW);

			new 
				id_trucker;
			id_trucker = pData[playerid][pTrucker];
			format(String144, sizeof(String144), "[TRUCKER] %s %s[%d] загрузил груз и отправляется к лесопилке на разгрузку", trucker_rank_name[pData[playerid][pTruckerRank]], pData[playerid][pNickname], playerid);
			send_trucker_job(id_trucker, COLOR_GREY, String144);

		}
	}

	TogglePlayerControllable(playerid, true);
	SetCameraBehindPlayer(playerid);

	return true;
}

stock dialog_input_load_trucker_1(playerid)
{
	new 
		get_max_gruz = get_job_level(playerid, SKILL_TRUCKER)*1000;

	format(String512, sizeof(String512), "\
		"cWH"Сколько килограмм груза Вы хотите загрузить\n\n\
		"cBLUE"-"cWH" Максимум: "cBLUE"%d"cWH" килограмм груза\n\
		"cBLUE"-"cWH" Доступно для загрузки: "cBLUE"%d"cWH" килограмм\n\
		Введите значение, которое хотите загрузить:", get_max_gruz);
	return SPD(playerid, DIALOG_INPUT_TRUCKER_1, DIALOG_STYLE_INPUT, !""cBLUE"Загрузка груза", String512, !"Далее", !"Назад");
}

stock dialog_input_load_trucker_2(playerid)
{
	new 
		get_max_gruz = get_job_level(playerid, SKILL_TRUCKER)*1000;

	format(String512, sizeof(String512), "\
		"cWH"Сколько литров Вы хотите загрузить\n\n\
		"cBLUE"-"cWH" Максимум: "cBLUE"%d"cWH" литров топлива\n\
		"cBLUE"-"cWH" Доступно для загрузки: "cBLUE"%d"cWH" литров\n\
		Введите значение, которое хотите загрузить:", get_max_gruz);
	return SPD(playerid, DIALOG_INPUT_TRUCKER_2, DIALOG_STYLE_INPUT, !""cBLUE"Загрузка груза", String512, !"Далее", !"Назад");
}


stock start_load_gruz_trucker(playerid, type)
{
	new 
		time_load_timer;

	if(get_job_level(playerid, SKILL_TRUCKER) == 1)	time_load_timer = 30000;
	if(get_job_level(playerid, SKILL_TRUCKER) == 2)	time_load_timer = 25000;
	if(get_job_level(playerid, SKILL_TRUCKER) == 3)	time_load_timer = 20000;
	if(get_job_level(playerid, SKILL_TRUCKER) == 4)	time_load_timer = 15000;
	if(get_job_level(playerid, SKILL_TRUCKER) == 5)	time_load_timer = 10000;

	SetPVarIntNew(playerid, "player_load_trucker", 1);

	SCM(playerid, -1, "");
	SendInf(playerid, "Ожидайте загрузки Вашей фуры!");

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_work_14", time_load_timer);

	TogglePlayerControllable(playerid, false);

	vehicle_engine_status(GetPlayerVehicleID(playerid), false);

	load_trucker(playerid, type, time_load_timer);

	return true;
}


stock final_load_gruz_trucker_1(playerid)
{
	visual_trucker_load_gruz_final(playerid);


	new 
		count_gruza;

	if(get_job_level(playerid, SKILL_TRUCKER) == 1)	count_gruza = 3000;
	if(get_job_level(playerid, SKILL_TRUCKER) == 2)	count_gruza = 2000;
	if(get_job_level(playerid, SKILL_TRUCKER) == 3)	count_gruza = 2000;
	if(get_job_level(playerid, SKILL_TRUCKER) == 4)	count_gruza = 1500;
	if(get_job_level(playerid, SKILL_TRUCKER) == 5)	count_gruza = 1000;


	count_truck_load_gruz[playerid] = count_gruza;

	vehicle_engine_status(GetPlayerVehicleID(playerid), true);

	DeletePVarNew(playerid, "player_load_trucker");

	SetPVarIntNew(playerid, "trucker_work_active_gruz", 1);
	return true;
}

stock start_load_gruz_trucker_2(playerid)
{
	new 
		time_load_timer;

	if(get_job_level(playerid, SKILL_TRUCKER) == 1)	time_load_timer = 30000;
	if(get_job_level(playerid, SKILL_TRUCKER) == 2)	time_load_timer = 25000;
	if(get_job_level(playerid, SKILL_TRUCKER) == 3)	time_load_timer = 20000;
	if(get_job_level(playerid, SKILL_TRUCKER) == 4)	time_load_timer = 15000;
	if(get_job_level(playerid, SKILL_TRUCKER) == 5)	time_load_timer = 15000;

	SetPVarIntNew(playerid, "player_load_trucker", 1);

	

	SCM(playerid, -1, "");
	SendInf(playerid, "Ожидайте загрузки Вашей фуры!");

	TogglePlayerControllable(playerid, false);
	vehicle_engine_status(GetPlayerVehicleID(playerid), false);

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_work_14", time_load_timer);

	load_trucker(playerid, 2, time_load_timer);

	return true;
}

stock final_load_gruz_trucker_2(playerid)
{	
	visual_trucker_load_gruz_final(playerid);

	new 
		count_gruza;

	if(get_job_level(playerid, SKILL_TRUCKER) == 1)	count_gruza = 3000;
	if(get_job_level(playerid, SKILL_TRUCKER) == 2)	count_gruza = 2000;
	if(get_job_level(playerid, SKILL_TRUCKER) == 3)	count_gruza = 2000;
	if(get_job_level(playerid, SKILL_TRUCKER) == 4)	count_gruza = 1500;
	if(get_job_level(playerid, SKILL_TRUCKER) == 5)	count_gruza = 1000;

	vehicle_engine_status(GetPlayerVehicleID(playerid), true);

	DeletePVarNew(playerid, "player_load_trucker");

	count_truck_load_gruz[playerid] = count_gruza;
	SetPVarIntNew(playerid, "trucker_work_active_gruz", 1);

	return true;
}


callback:: load_trucker_gruz_1(playerid)
{

	final_load_gruz_trucker_1(playerid);

	return true;
}

callback:: load_trucker_gruz_2(playerid)
{

	final_load_gruz_trucker_2(playerid);
	return true;
}



stock find_active_magazin(playerid)
{
	new Result:find_magazing_orders = sql_queryEx(zConn, "SELECT * FROM `magazinorders`", QUERY_CACHED);

	new 
		biz_id = sql_num_rows(find_magazing_orders),
		biz_ids, fuel_count;

	if(sql_num_rows(find_magazing_orders)) 
	{
		for(new i; i < biz_id; i++)
		{
			biz_ids  = sql_get_field_assoc_int_ex(find_magazing_orders, i, "magazin_id"); 

			SetPVarIntNew(playerid, "fuel_orders_active", biz_ids);

			fuel_count  = sql_get_field_assoc_int_ex(find_magazing_orders, i, "count_orders");
			SetPVarIntNew(playerid, "fuel_orders_count", fuel_count);

			DisablePlayerRaceCheckpoint(playerid);
			SetPlayerRaceCheckpoint(playerid, 1, buisness[biz_ids][buisnes_enter_x], buisness[biz_ids][buisnes_enter_y], buisness[biz_ids][buisnes_enter_z], 0.0, 0.0, 0.0, 8.0);

			new 
				Float:x, 
				Float:y,
				Float:z;

			GetPlayerPos(playerid, x, y, z);

			new 
				price_trucker_work = floatround(GetDistanceBetweenPoints(x, y, z, buisness[biz_ids][buisnes_enter_x], buisness[biz_ids][buisnes_enter_y], buisness[biz_ids][buisnes_enter_z]));

			SetPVarIntNew(playerid, "trucker_dist_money_price", price_trucker_work);

		}
	}	
	else
	{
		new 
			biz_random = random(all_buisness);
		DisablePlayerRaceCheckpoint(playerid);	
		SetPlayerRaceCheckpoint(playerid, 1, buisness[biz_random][buisnes_enter_x], buisness[biz_random][buisnes_enter_y], buisness[biz_random][buisnes_enter_z], 0.0, 0.0, 0.0, 8.0);

		new 
			Float:x, 
			Float:y,
			Float:z;

		GetPlayerPos(playerid, x, y, z);

		new 
			price_trucker_work = floatround(GetDistanceBetweenPoints(x, y, z, buisness[biz_random][buisnes_enter_x], buisness[biz_random][buisnes_enter_y], buisness[biz_random][buisnes_enter_z]));

		SetPVarIntNew(playerid, "trucker_dist_money_price", price_trucker_work);

	}

	new  
		id_trucker;
	id_trucker = pData[playerid][pTrucker];
	format(String144, sizeof(String144), "[TRUCKER] %s %s[%d] загрузил груз и отправляется к бизнесу на разгрузку", trucker_rank_name[pData[playerid][pTruckerRank]], pData[playerid][pNickname], playerid);
	send_trucker_job(id_trucker, COLOR_GREY, String144);

	SCM(playerid, -1, "");
	SendInf(playerid, "Точка разгрузки установлена у Вас в навигаторе!");
	SendInf(playerid, "Отправляйтесь на точку разгрузки, разгрузите товар и получите денежные средства!");


	status_navigator_player(playerid, TEXTDRAW_SHOW);

	return true;
}



stock find_active_fuel_1(playerid)
{

	new Result:fill_orders = sql_queryEx(zConn, "SELECT * FROM `fuelorders`", QUERY_CACHED);

	new 
		biz_id = sql_num_rows(fill_orders),
		fill_id,
		fuel_count;

	if(sql_num_rows(fill_orders)) 
	{
		for(new i; i < biz_id; i++)
		{
			fill_id  = sql_get_field_assoc_int_ex(fill_orders, i, "fuel_id"); 
			fuel_count  = sql_get_field_assoc_int_ex(fill_orders, i, "fuel_count"); 

			SetPVarIntNew(playerid, "fuel_orders_active", fill_id);
			SetPVarIntNew(playerid, "fuel_orders_count", fuel_count);

			DisablePlayerRaceCheckpoint(playerid);
			SetPlayerRaceCheckpoint(playerid, 1, filling[fill_id][filling_info_enter_x], filling[fill_id][filling_info_enter_y], filling[fill_id][filling_info_enter_z], 0.0, 0.0, 0.0, 8.0);
		

			new 
				Float:x, 
				Float:y,
				Float:z;

			GetPlayerPos(playerid, x, y, z);

			new 
				price_trucker_work = floatround(GetDistanceBetweenPoints(x, y, z, filling[fill_id][filling_info_enter_x], filling[fill_id][filling_info_enter_y], filling[fill_id][filling_info_enter_z]));

			SetPVarIntNew(playerid, "trucker_dist_money_price", price_trucker_work);
		}
	}	
	else
	{
		new 
			filling_random = random(all_filling);
		DisablePlayerRaceCheckpoint(playerid);	
		SetPlayerRaceCheckpoint(playerid, 1, filling[filling_random][filling_info_enter_x], filling[filling_random][filling_info_enter_y], filling[filling_random][filling_info_enter_z], 0.0, 0.0, 0.0, 8.0);	
	
		new 
			Float:x, 
			Float:y,
			Float:z;

		GetPlayerPos(playerid, x, y, z);

		new 
			price_trucker_work = floatround(GetDistanceBetweenPoints(x, y, z, filling[filling_random][filling_info_enter_x], filling[filling_random][filling_info_enter_y], filling[filling_random][filling_info_enter_z]));

		SetPVarIntNew(playerid, "trucker_dist_money_price", price_trucker_work);

	}

	new 
		id_trucker;
	id_trucker = pData[playerid][pTrucker];
	format(String144, sizeof(String144), "[TRUCKER] %s %s[%d] загрузил груз и отправляется к АЗС на разгрузку", trucker_rank_name[pData[playerid][pTruckerRank]], pData[playerid][pNickname], playerid);
	send_trucker_job(id_trucker, COLOR_GREY, String144);

	SCM(playerid, -1, "");
	SendInf(playerid, "Точка разгрузки установлена у Вас в навигаторе!");
	SendInf(playerid, "Отправляйтесь на АЗС, разгрузите товар и получите денежные средства!");

	status_navigator_player(playerid, TEXTDRAW_SHOW);

	return true;
}

stock find_active_fuel_2(playerid)
{
	
	new Result:fill_orders = sql_queryEx(zConn, "SELECT * FROM `fuelorders`", QUERY_CACHED);

	new 
		biz_id = sql_num_rows(fill_orders),
		fill_id,
		fuel_count;

	if(sql_num_rows(fill_orders)) 
	{
		for(new i; i < biz_id; i++)
		{
			fill_id  = sql_get_field_assoc_int_ex(fill_orders, i, "fuel_id"); 
			fuel_count  = sql_get_field_assoc_int_ex(fill_orders, i, "fuel_count"); 

			SetPVarIntNew(playerid, "fuel_orders_active", fill_id);
			SetPVarIntNew(playerid, "fuel_orders_count", fuel_count);

			DisablePlayerRaceCheckpoint(playerid);
			SetPlayerRaceCheckpoint(playerid, 1, filling[fill_id][filling_info_enter_x], filling[fill_id][filling_info_enter_y], filling[fill_id][filling_info_enter_z], 0.0, 0.0, 0.0, 8.0);
		
			new 
				Float:x, 
				Float:y,
				Float:z;

			GetPlayerPos(playerid, x, y, z);

			new 
				price_trucker_work = floatround(GetDistanceBetweenPoints(x, y, z, filling[fill_id][filling_info_enter_x], filling[fill_id][filling_info_enter_y], filling[fill_id][filling_info_enter_z]));

			SetPVarIntNew(playerid, "trucker_dist_money_price", price_trucker_work);


		}
	}		
	else
	{
		new 
			filling_random = random(all_filling);

		DisablePlayerRaceCheckpoint(playerid);
		SetPlayerRaceCheckpoint(playerid, 1, filling[filling_random][filling_info_enter_x], filling[filling_random][filling_info_enter_y], filling[filling_random][filling_info_enter_z], 0.0, 0.0, 0.0, 3.0);	
	
		new 
			Float:x, 
			Float:y,
			Float:z;

		GetPlayerPos(playerid, x, y, z);

		new 
			price_trucker_work = floatround(GetDistanceBetweenPoints(x, y, z, filling[filling_random][filling_info_enter_x], filling[filling_random][filling_info_enter_y], filling[filling_random][filling_info_enter_z]));

		SetPVarIntNew(playerid, "trucker_dist_money_price", price_trucker_work);

	}

	new 
		id_trucker;
	id_trucker = pData[playerid][pTrucker];
	format(String144, sizeof(String144), "[TRUCKER] %s %s[%d] загрузил груз и отправляется к АЗС на разгрузку", trucker_rank_name[pData[playerid][pTruckerRank]], pData[playerid][pNickname], playerid);
	send_trucker_job(id_trucker, COLOR_GREY, String144);

	SCM(playerid, -1, "");
	SendInf(playerid, "Точка разгрузки установлена у Вас в навигаторе!");
	SendInf(playerid, "Отправляйтесь на АЗС, разгрузите товар и получите денежные средства!");

	status_navigator_player(playerid, TEXTDRAW_SHOW);

	return true;
}



stock give_price_unload_gruz(playerid)
{
	new 
		money_final = floatround(GetPVarIntNew(playerid, "trucker_dist_money_price")/0.40),
		price;

	if(get_job_level(playerid, SKILL_TRUCKER) == 1)
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
	else if(get_job_level(playerid, SKILL_TRUCKER) == 2)
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
	else if(get_job_level(playerid, SKILL_TRUCKER) == 3)
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
	else if(get_job_level(playerid, SKILL_TRUCKER) == 4)
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
	else if(get_job_level(playerid, SKILL_TRUCKER) == 5)
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


	price = price-(price/100*trucker_station[pData[playerid][pTrucker]][trucker_base_percent]);

	new 
		pricepercent = (price/100*trucker_station[pData[playerid][pTrucker]][trucker_base_percent]);

	pay_money_bank_trucker(pricepercent, pData[playerid][pTrucker]);

	format(String144, sizeof(String144), "Вы проехали %d метров и получили за это %d рублей! Благодарим за работу!", GetPVarIntNew(playerid, "trucker_dist_money_price"), price);
	SendSucc(playerid, String144);
    format(String144, sizeof(String144), "Вы уже заработали "cGR"%d "cWH"рублей! Комиссия: "cGR"%d "cWH"рублей!", price, pricepercent);
    SendInf(playerid, String144);

    give_money(playerid, price, "Зарплата ТК");

	format(String256,sizeof(String256),"UPDATE `trucker_personal` SET `user_money_day` = user_money_day+%d WHERE `user_id` = '%d'" , price, pData[playerid][pMysqlID]);
	sql_queryEx(zConn, String256, QUERY_THREADED);	
	format(String256,sizeof(String256),"UPDATE `trucker_personal` SET `user_money_all` = user_money_all+%d WHERE `user_id` = '%d'" , price, pData[playerid][pMysqlID]);
	sql_queryEx(zConn, String256, QUERY_THREADED);	

    add_player_job_skill(playerid, SKILL_TRUCKER);
	return true;
}

stock give_price_unload_gruz_fill(playerid)
{
	new 
		money_final = floatround(GetPVarIntNew(playerid, "trucker_dist_money_price")/0.35),
		price;

	if(get_job_level(playerid, SKILL_TRUCKER) == 1)
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
	else if(get_job_level(playerid, SKILL_TRUCKER) == 2)
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
	else if(get_job_level(playerid, SKILL_TRUCKER) == 3)
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
	else if(get_job_level(playerid, SKILL_TRUCKER) == 4)
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
	else if(get_job_level(playerid, SKILL_TRUCKER) == 5)
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


	price = price-(price/100*trucker_station[pData[playerid][pTrucker]][trucker_base_percent]);

	new 
		pricepercent = (price/100*trucker_station[pData[playerid][pTrucker]][trucker_base_percent]);

	pay_money_bank_trucker(pricepercent, pData[playerid][pTrucker]);

	format(String144, sizeof(String144), "Вы проехали %d метров и получили за это %d рублей! Благодарим за работу!", GetPVarIntNew(playerid, "trucker_dist_money_price"), price);
	SendSucc(playerid, String144);
    format(String144, sizeof(String144), "Вы уже заработали "cGR"%d "cWH"рублей! Комиссия: "cGR"%d "cWH"рублей!", price, pricepercent);
    SendInf(playerid, String144);

    give_money(playerid, price, "Зарплата ТК");

	format(String256,sizeof(String256),"UPDATE `trucker_personal` SET `user_money_day` = user_money_day+%d WHERE `user_id` = '%d'" , price, pData[playerid][pMysqlID]);
	sql_queryEx(zConn, String256, QUERY_THREADED);	
	format(String256,sizeof(String256),"UPDATE `trucker_personal` SET `user_money_all` = user_money_all+%d WHERE `user_id` = '%d'" , price, pData[playerid][pMysqlID]);
	sql_queryEx(zConn, String256, QUERY_THREADED);	

    add_player_job_skill(playerid, SKILL_TRUCKER);


	return true;
}

stock unload_trucker_gruz(playerid)
{
	if(!GetPVarIntNew(playerid, "type_job_trucker"))
		return true;


	new 
		type_load = GetPVarIntNew(playerid, "type_job_trucker");

	DisablePlayerRaceCheckpoint(playerid);	

	if(count_truck_load_gruz[playerid] == 0)
		return true;

	if(!IsPlayerInAnyVehicle(playerid))
		return SendErr(playerid, "Вы должны находиться в рабочем транспорте!");

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_work_13", 5000);

	switch(type_load)
	{
		case TRUCKER_JOB_MINER:
		{
			count_truck_load_gruz[playerid] = 0;

			SCM(playerid, -1, "");
			SendSucc(playerid, "Вы успешно разгрузили груз!");
			SendInf(playerid, "Если хотите продолжить работу в данном направление, то отправляйтесь на место загрузки!");
			SendInf(playerid, "Для изменения типа развозимого груза, Вам требуется вернуться на базу Транспортной Компании!");

			SetPVarIntNew(playerid, "trucker_load_miner", 1);

			DisablePlayerRaceCheckpoint(playerid);	

			give_price_unload_gruz(playerid);

			new 
				id_trucker;

			id_trucker = pData[playerid][pTrucker];


			format(String144, sizeof(String144), "[TRUCKER] %s %s[%d] разгрузил груз на шахте", trucker_rank_name[pData[playerid][pTruckerRank]], pData[playerid][pNickname], playerid);
			send_trucker_job(id_trucker, COLOR_GREY, String144);


			SetPlayerRaceCheckpoint(playerid, 1, TRUCKER_MINER_LOAD, 0.0, 0.0, 0.0, 3.0);

			unload_trucker(playerid);

			return true;
		}	
		case TRUCKER_JOB_ZAVOD:
		{
			count_truck_load_gruz[playerid] = 0;

			SCM(playerid, -1, "");
			SendSucc(playerid, "Вы успешно разгрузили груз!");
			SendInf(playerid, "Если хотите продолжить работу в данном направление, то отправляйтесь на место загрузки!");
			SendInf(playerid, "Для изменения типа развозимого груза, Вам требуется вернуться на базу Транспортной Компании!");

			SetPlayerRaceCheckpoint(playerid, 1, TRUCKER_ZAVOD_LOAD, 0.0, 0.0, 0.0, 13.0);
			SetPVarIntNew(playerid, "trucker_load_zavod", 1);

			DisablePlayerRaceCheckpoint(playerid);	

			new 
				id_trucker;

			id_trucker = pData[playerid][pTrucker];


			format(String144, sizeof(String144), "[TRUCKER] %s %s[%d] разгрузил груз на заводе", trucker_rank_name[pData[playerid][pTruckerRank]], pData[playerid][pNickname], playerid);
			send_trucker_job(id_trucker, COLOR_GREY, String144);

			give_price_unload_gruz(playerid);


			SetPlayerRaceCheckpoint(playerid, 1, TRUCKER_ZAVOD_LOAD, 0.0, 0.0, 0.0, 13.0);

			unload_trucker(playerid);

			return true;
		}
		case TRUCKER_JOB_SHOP:
		{
			count_truck_load_gruz[playerid] = 0;

			if(GetPVarIntNew(playerid, "fuel_orders_active"))
			{
				new 
					magazin_id = GetPVarIntNew(playerid, "fuel_orders_active");

				buisness[magazin_id][buisnes_count_prod] += GetPVarIntNew(playerid, "fuel_orders_count");

				notify_owner_magazin_gruz(magazin_id);
				save_biz(magazin_id);

			}

			SCM(playerid, -1, "");
			SendSucc(playerid, "Вы успешно разгрузили груз!");
			SendInf(playerid, "Если хотите продолжить работу в данном направление, то отправляйтесь на место загрузки!");
			SendInf(playerid, "Для изменения типа развозимого груза, Вам требуется вернуться на базу Транспортной Компании!");

			new 
				id_trucker;

			id_trucker = pData[playerid][pTrucker];


			format(String144, sizeof(String144), "[TRUCKER] %s %s[%d] разгрузил груз в бизнес", trucker_rank_name[pData[playerid][pTruckerRank]], pData[playerid][pNickname], playerid);
			send_trucker_job(id_trucker, COLOR_GREY, String144);

			DisablePlayerRaceCheckpoint(playerid);	

			give_price_unload_gruz(playerid);


			SetPlayerRaceCheckpoint(playerid, 1, TRUCKER_SHOP_LOAD, 0.0, 0.0, 0.0, 3.0);
			SetPVarIntNew(playerid, "trucker_load_shop", 1);


			DeletePVarNew(playerid, "fuel_orders_count");
			DeletePVarNew(playerid, "fuel_orders_active");

			unload_trucker(playerid);

			return true;
		}
		case TRUCKER_JOB_FILL_1:
		{
			count_truck_load_gruz[playerid] = 0;

			if(GetPVarIntNew(playerid, "fuel_orders_active"))
			{
				new 
					fuel_id = GetPVarIntNew(playerid, "fuel_orders_active"),
					fuel_count = GetPVarIntNew(playerid, "fuel_orders_count");

				filling[fuel_id][filling_count_all_fill] += fuel_count;

				notify_owner_fill_gruz(fuel_id);
				save_fill(fuel_id);

			}

			DeletePVarNew(playerid, "fuel_orders_active");
			DeletePVarNew(playerid, "fuel_orders_count");

			new 
				id_trucker;

			id_trucker = pData[playerid][pTrucker];


			format(String144, sizeof(String144), "[TRUCKER] %s %s[%d] разгрузил груз на АЗС", trucker_rank_name[pData[playerid][pTruckerRank]], pData[playerid][pNickname], playerid);
			send_trucker_job(id_trucker, COLOR_GREY, String144);


			SCM(playerid, -1, "");
			SendSucc(playerid, "Вы успешно разгрузили груз!");
			SendInf(playerid, "Если хотите продолжить работу в данном направление, то отправляйтесь на место загрузки!");
			SendInf(playerid, "Для изменения типа развозимого груза, Вам требуется вернуться на базу Транспортной Компании!");

			give_price_unload_gruz_fill(playerid);

			DisablePlayerRaceCheckpoint(playerid);	


			SetPlayerRaceCheckpoint(playerid, 1, TRUCKER_FUEL_LOAD, 0.0, 0.0, 0.0, 3.0);
			SetPVarIntNew(playerid, "trucker_load_fill_1", 1);

			unload_trucker(playerid);

			return true;
		}
		case TRUCKER_JOB_FILL_2:
		{
			count_truck_load_gruz[playerid] = 0;

			if(GetPVarIntNew(playerid, "fuel_orders_active"))
			{
				new 
					fuel_id = GetPVarIntNew(playerid, "fuel_orders_active"),
					fuel_count = GetPVarIntNew(playerid, "fuel_orders_count");

				filling[fuel_id][filling_count_all_fill] += fuel_count;

				notify_owner_fill_gruz(fuel_id);
				save_fill(fuel_id);

			}

			DeletePVarNew(playerid, "fuel_orders_active");
			DeletePVarNew(playerid, "fuel_orders_count");

			new 
				id_trucker;

			id_trucker = pData[playerid][pTrucker];


			format(String144, sizeof(String144), "[TRUCKER] %s %s[%d] разгрузил груз на АЗС", trucker_rank_name[pData[playerid][pTruckerRank]], pData[playerid][pNickname], playerid);
			send_trucker_job(id_trucker, COLOR_GREY, String144);

			SCM(playerid, -1, "");
			SendSucc(playerid, "Вы успешно разгрузили груз!");
			SendInf(playerid, "Если хотите продолжить работу в данном направление, то отправляйтесь на место загрузки!");
			SendInf(playerid, "Для изменения типа развозимого груза, Вам требуется вернуться на базу Транспортной Компании!");

			give_price_unload_gruz_fill(playerid);

			DisablePlayerRaceCheckpoint(playerid);	

			SetPlayerRaceCheckpoint(playerid, 1, TRUCKER_FUEL_LOAD, 0.0, 0.0, 0.0, 3.0);
			SetPVarIntNew(playerid, "trucker_load_fill_2", 1);


			unload_trucker(playerid);
			return true;
		}
		case TRUCKER_JOB_SAMWILL:
		{

			count_truck_load_gruz[playerid] = 0;

			SCM(playerid, -1, "");
			SendSucc(playerid, "Вы успешно разгрузили груз!");
			SendInf(playerid, "Если хотите продолжить работу в данном направление, то отправляйтесь на место загрузки!");
			SendInf(playerid, "Для изменения типа развозимого груза, Вам требуется вернуться на базу Транспортной Компании!");

			new 
				id_trucker;

			id_trucker = pData[playerid][pTrucker];


			format(String144, sizeof(String144), "[TRUCKER] %s %s[%d] разгрузил груз на лесопилке", trucker_rank_name[pData[playerid][pTruckerRank]], pData[playerid][pNickname], playerid);
			send_trucker_job(id_trucker, COLOR_GREY, String144);

			DisablePlayerRaceCheckpoint(playerid);

			give_price_unload_gruz(playerid);

			SetPlayerRaceCheckpoint(playerid, 1, TRUCKER_SAMWILL_LOAD, 0.0, 0.0, 0.0, 3.0);
			SetPVarIntNew(playerid, "trucker_load_samwill", 1);

			unload_trucker(playerid);

			return true;
		}
	}
	DeletePVarNew(playerid, "trucker_work_active_gruz");
	add_player_job_skill(playerid, SKILL_TRUCKER, RandomEx(1, 2));

	new 
		status;

	if(get_job_level(playerid, SKILL_TRUCKER) == 1) status = 1500;
	if(get_job_level(playerid, SKILL_TRUCKER) == 2) status = 2500;
	if(get_job_level(playerid, SKILL_TRUCKER) == 3) status = 4500;
	if(get_job_level(playerid, SKILL_TRUCKER) == 4) status = 5500;
	if(get_job_level(playerid, SKILL_TRUCKER) == 5) status = 6500;


	return true;
}



stock notify_owner_fill_gruz(f)
{

	new 
		owner_id = filling[f][filling_owner_id];

	new 
		owner_fuel_name[MAX_PLAYER_NAME];


	GetPlayerNameByID(owner_id, owner_fuel_name);

	new 
		player_id = GetPlayerID(owner_fuel_name);	

	if(IsPlayerConnected(player_id))
	{
		if(pData[player_id][pFillStation] == f)
		{	
			SCM(player_id, -1, "");
			SendInf(player_id, "На вашу АЗС было доставлено топливо, которое Вы заказывали!");
			SendInf(player_id, "Благодарим Вас за использование наших услуг, с уважением, НПЗ!");
		}
	}
	else
	{	

		send_off_message(-1, owner_fuel_name, "На вашу АЗС было доставлено топливо, которое Вы заказывали!");
	}

	new 
		fmt_str[144];

	format(fmt_str, sizeof(fmt_str), "DELETE FROM `fuelorders` WHERE `fuel_id` = '%d'", f);
	sql_queryEx(zConn, fmt_str);

	return true;
}


stock notify_owner_magazin_gruz(f)
{

	new 
		owner_id = buisness[f][buisnes_owned];

	new 
		owner_biz_name[32];


	GetPlayerNameByID(owner_id, owner_biz_name);

	new 
		player_id = GetPlayerID(owner_biz_name);	


	if(IsPlayerConnected(player_id))
	{
		if(pData[player_id][pBusiness] == f)
		{	
			SCM(player_id, -1, "");
			SendInf(player_id, "В Ваш магазины были доставлены товары, которые Вы заказывали!");
			SendInf(player_id, "Благодарим Вас за использование наших услуг!");
		}
	}
	else
	{	

		send_off_message(-1, owner_biz_name, "В Ваш магазины были доставлены товары, которые Вы заказывали!");
	}

	new 
		fmt_str[144];

	format(fmt_str, sizeof(fmt_str), "DELETE FROM `magazinorders` WHERE `magazin_id` = '%d'", f);
	sql_queryEx(zConn, fmt_str);

	return true;
}

stock pay_money_bank_trucker(sum, trucker_bank_id)
{
	
	if(trucker_station[trucker_bank_id][trucker_base_finka_day] >= trucker_station[trucker_bank_id][trucker_base_finka_ogran])
		return true;

	trucker_station[trucker_bank_id][trucker_base_bank] += sum;
	trucker_station[trucker_bank_id][trucker_base_finka_day] += sum;



	save_trucker_base();

	format(String256,sizeof(String256),"UPDATE `trucker_stats` SET `stats_all_time` = `stats_all_time`+'%d' WHERE `trucker_id` = '%d'" , sum, trucker_bank_id);
	sql_queryEx(zConn, String256, QUERY_THREADED);	
	format(String256,sizeof(String256),"UPDATE `trucker_stats` SET `stats_mounth` = `stats_mounth`+'%d' WHERE `trucker_id` = '%d'" , sum, trucker_bank_id);
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
			format(String256,sizeof(String256),"UPDATE `trucker_stats` SET `stats_day_1` = `stats_day_1`+'%d' WHERE `trucker_id` = '%d'" , sum, trucker_bank_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	

			format(String256,sizeof(String256),"UPDATE `trucker_stats` SET `stats_today` = `stats_today`+'%d' WHERE `trucker_id` = '%d'" , sum, trucker_bank_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	

		}
		case 1:
		{
			format(String256,sizeof(String256),"UPDATE `trucker_stats` SET `stats_day_2` = `stats_day_2`+'%d' WHERE `trucker_id` = '%d'" , sum, trucker_bank_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `trucker_stats` SET `stats_today` = `stats_today`+'%d' WHERE `trucker_id` = '%d'" , sum, trucker_bank_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}	

		case 2:
		{
			format(String256,sizeof(String256),"UPDATE `trucker_stats` SET `stats_day_3` = `stats_day_3`+'%d' WHERE `trucker_id` = '%d'" , sum, trucker_bank_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `trucker_stats` SET `stats_today` = `stats_today`+'%d' WHERE `trucker_id` = '%d'" , sum, trucker_bank_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}
		case 3:
		{
			format(String256,sizeof(String256),"UPDATE `trucker_stats` SET `stats_day_4` = `stats_day_4`+'%d' WHERE `trucker_id` = '%d'" , sum, trucker_bank_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `trucker_stats` SET `stats_today` = `stats_today`+'%d' WHERE `trucker_id` = '%d'" , sum, trucker_bank_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}

		case 4:
		{
			format(String256,sizeof(String256),"UPDATE `trucker_stats` SET `stats_day_5` = `stats_day_5`+'%d' WHERE `trucker_id` = '%d'" , sum, trucker_bank_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `trucker_stats` SET `stats_today` = `stats_today`+'%d' WHERE `trucker_id` = '%d'" , sum, trucker_bank_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}	
		case 5:
		{
			format(String256,sizeof(String256),"UPDATE `trucker_stats` SET `stats_day_6` = `stats_day_6`+'%d' WHERE `trucker_id` = '%d'" , sum, trucker_bank_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `trucker_stats` SET `stats_today` = `stats_today`+'%d' WHERE `trucker_id` = '%d'" , sum, trucker_bank_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}
		case 6:
		{
			format(String256,sizeof(String256),"UPDATE `trucker_stats` SET `stats_day_7` = `stats_day_7`+'%d' WHERE `trucker_id` = '%d'" , sum, trucker_bank_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `trucker_stats` SET `stats_today` = `stats_today`+'%d' WHERE `trucker_id` = '%d'" , sum, trucker_bank_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}

	}	

	return true;
}

stock clear_stats_trucker_newday()
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
			format(String256,sizeof(String256),"UPDATE `trucker_stats` SET `stats_day_1` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	

			format(String256,sizeof(String256),"UPDATE `trucker_stats` SET `stats_today` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	

		}
		case 1:
		{
			format(String256,sizeof(String256),"UPDATE `trucker_stats` SET `stats_day_2` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `trucker_stats` SET `stats_today` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}	

		case 2:
		{
			format(String256,sizeof(String256),"UPDATE `trucker_stats` SET `stats_day_3` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `trucker_stats` SET `stats_today` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}
		case 3:
		{
			format(String256,sizeof(String256),"UPDATE `trucker_stats` SET `stats_day_4` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `trucker_stats` SET `stats_today` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}

		case 4:
		{
			format(String256,sizeof(String256),"UPDATE `trucker_stats` SET `stats_day_5` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `trucker_stats` SET `stats_today` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}	
		case 5:
		{
			format(String256,sizeof(String256),"UPDATE `trucker_stats` SET `stats_day_6` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `trucker_stats` SET `stats_today` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}
		case 6:
		{
			format(String256,sizeof(String256),"UPDATE `trucker_stats` SET `stats_day_7` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `trucker_stats` SET `stats_today` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}

	}	
	return true;
}

stock clear_stats_trucker_mounth()
{
	for(new i; i < MAX_TRUCKER_BASE; i++)
	{
		format(String256,sizeof(String256),"UPDATE `trucker_stats` SET `stats_mounth_back` = `stats_mounth` WHERE `trucker_id` = '%d'" , i);
		sql_queryEx(zConn, String256, QUERY_THREADED);	
	}
	format(String256,sizeof(String256),"UPDATE `trucker_stats` SET `stats_mounth` = '0'");
	sql_queryEx(zConn, String256, QUERY_THREADED);	

	return true;
}

CMD:atruckfin(playerid, params[])
{


    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

	if(sscanf(params, "dd", params[0], params[1]))
	{
		SendInf(playerid, "Используйте: /atruckfin "cWH"[ID ТРК] [Ограничение]");
		return true;
	}

	trucker_station[params[0]][trucker_base_finka_ogran] = params[1];
	save_trucker_base();

    format(String144, sizeof(String144), "Вы успешно изменили максимальную прибыль для ТРК №%d на "cGR"%d "cWH"рублей!", params[0], params[1]);
    SendSucc(playerid, String144);

	return true;
}

CMD:atruckerpercent(playerid, params[])
{

    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

	if(sscanf(params, "dd", params[0], params[1]))
	{
		SendInf(playerid, "Используйте: /atruckerpercent "cWH"[ID ТК] [Ограничение]");
		return true;
	}

	trucker_station[params[0]][trucker_base_percent] = params[1];
	save_trucker_base();

    format(String144, sizeof(String144), "Вы успешно изменили максимальную процент от прибыли для ТК №%d на "cGR"%d "cWH"процентов!", params[0], params[1]);
    SendSucc(playerid, String144);
    return true;

}

CMD:atruckerbclose(playerid, params[])
{

    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

	if(sscanf(params, "dd", params[0], params[1]))
	{
		SendInf(playerid, "Используйте: /atruckerbclose "cWH"[ID ТК] [Статус]");
		return true;
	}

	trucker_station[params[0]][trucker_block_bank] = params[1];
	save_trucker_base();

    format(String144, sizeof(String144), "Вы успешно изменили возможность ТК №%d пользоваться банком!", params[0]);
    SendSucc(playerid, String144);

    return true;
}

CMD:atruckerpclose(playerid, params[])
{

    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

	if(sscanf(params, "dd", params[0], params[1]))
	{
		SendInf(playerid, "Используйте: /atruckerpclose "cWH"[ID ТК] [Статус]");
		return true;
	}

	trucker_station[params[0]][trucker_block_percent] = params[1];
	save_trucker_base();

    format(String144, sizeof(String144), "Вы успешно изменили возможность ТК №%d пользоваться изменением процента!", params[0]);
    SendSucc(playerid, String144);

    return true;
}

CMD:atruckeruclose(playerid, params[])
{

    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

	if(sscanf(params, "dd", params[0], params[1]))
	{
		SendInf(playerid, "Используйте: /atruckeruclose "cWH"[ID ТК] [Статус]");
		return true;
	}

	trucker_station[params[0]][trucker_block_uninvite] = params[1];
	save_trucker_base();

    format(String144, sizeof(String144), "Вы успешно изменили возможность ТК №%d пользоваться изменением персонала!", params[0]);
    SendSucc(playerid, String144);

    return true;
}

CMD:atruckerinvite(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

	if(sscanf(params, "I(-1)", params[0]))
	{
		SendInf(playerid, "Используйте: /atruckerinvite "cWH"[ID ТК] (-1 для увольнения)");
		return true;
	}

	if(params[0] == -1)
	{
		pData[playerid][pTrucker] = -1;
		pData[playerid][pTruckerOwnerLowID] = -1;
		pData[playerid][pTruckerRank] = 1;

		pData[playerid][pJob] = 0;

		UpdatePlayerData(playerid,"pTruckerOwnerLowID", pData[playerid][pTruckerOwnerLowID]);	
		UpdatePlayerData(playerid,"pTrucker", pData[playerid][pTrucker]);	
		UpdatePlayerData(playerid,"pTruckerRank", pData[playerid][pTruckerRank]);	
		UpdatePlayerData(playerid, "job", pData[playerid][pJob]);	

		SendSucc(playerid, "Вы успешно уволились из ТК!");

		return true;
	}
	pData[playerid][pTrucker] = params[0];
	pData[playerid][pTruckerOwnerID] = params[0];
	pData[playerid][pTruckerRank] = 1;

	pData[playerid][pJob] = SKILL_TRUCKER;

	UpdatePlayerData(playerid,"pTruckerOwnerLowID", pData[playerid][pTruckerOwnerLowID]);	
	UpdatePlayerData(playerid,"pTrucker", pData[playerid][pTrucker]);	
	UpdatePlayerData(playerid,"pTruckerRank", pData[playerid][pTruckerRank]);	
	UpdatePlayerData(playerid, "job", pData[playerid][pJob]);	

    format(String144, sizeof(String144), "Вы успешно приняли себя в ТК №%d!", params[0]);
    SendSucc(playerid, String144);
	
	return true;	
}

stock buy_trucker_person(playerid)
{
	new 
		trucker_id = pData[playerid][pTrucker];

	format(String512, sizeof(String512), "\
		"cWH"У Вас в Транспортной Компании уже имеется "cGR"%d"cWH" грузовиков!\n\n\
		Хотите купить ещё одно место для персонала за "cGR"25.000 рублей?"cWH"\n\n\
		Новые грузовики позволят выполнять больше заказов!",
		trucker_station[trucker_id][trucker_person_count]);
	return SPD(playerid, DIALOG_BUY_TRUCKER_PERSON, DIALOG_STYLE_MSGBOX, !""cBLUE"Приобритение места для персонала", String512, !"Далее", !"Закрыть");

}

stock buy_trucker_level_truck(playerid)
{
	new 
		trucker_id = pData[playerid][pTrucker];

	if(trucker_station[trucker_id][trucker_level_veh] == 3)
	{
		SendErr(playerid, "У Вас максимально возможный уровень автопарка!");
		return true;
	}

	format(String512, sizeof(String512), "\
		"cWH"У Вас в Транспортной Компании уже имеется "cGR"%s"cWH" уровень грузовиков!\n\n\
		Хотите купить улучшение до следующего уровня за "cGR"1.000.000 рублей?"cWH"\n\n\
		Новые грузовики позволят выполнять больше заказов и быстрее!",
		get_truck_veh_level[trucker_station[trucker_id][trucker_level_veh]]);
	return SPD(playerid, DIALOG_BUY_TRUCKER_LEVEL, DIALOG_STYLE_MSGBOX, !""cBLUE"Приобритение уровня грузовиков", String512, !"Далее", !"Закрыть");
}


stock buy_trucker_vehicle(playerid)
{
	new 
		trucker_id = pData[playerid][pTrucker];


	format(String512, sizeof(String512), "\
		"cWH"У Вас в Транспортной Компании уже имеется "cGR"%d"cWH" грузовиков!\n\n\
		Хотите купить ещё один грузовик за "cGR"750.000 рублей?"cWH"\n\n\
		Новые грузовики позволят выполнять больше заказов!",
		trucker_station[trucker_id][trucker_veh_count]);
	return SPD(playerid, DIALOG_BUY_TRUCKER_VEHICLE, DIALOG_STYLE_MSGBOX, !""cBLUE"Приобритение грузовиков", String512, !"Далее", !"Закрыть");
}

stock respawn_trucker_vehicle(playerid, trucker_id)
{

	if(GetPlayerMoneyEx(playerid) < 2500)
	{

		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
		return SendErr(playerid, "У вас недостаточно денежных средств!");
	}

	switch(trucker_id)
	{
		case TRUCKER_BASE_STATION_1:
		{

			new count;
			foreach(Vehicles, i)
		    {
		        if(!vehicle[i][cIsCreated]) 
		        	continue;
				if(!IsVehicleOccupied(i) || !IsValidVehicle(i)) 
					continue;

				if(vehicle[i][cOwnTo] == VEHICLE_TRUCKER_1)
				{
				    DestroyVehicle(i);
					vehicle[i][cIsCreated] = false;
					count++;
					unrent_vehicle_trucker_respawn(i);
				}
				
		    }
		    if(count == 0)
		    	return SendErr(playerid, "Отсутствуют машины для транспортировки!");


		    give_money(playerid, -2500, "Доставка грузовиков в ТК");
			format(String144, sizeof(String144), "[T] %s [%d] вызвал эвакуатор и привёз на базу %d грузовиков, потратив 2500 рублей!", pData[playerid][pNickname], playerid, count);
			send_trucker_job(trucker_id, COLOR_GREY, String144);

		}
		case TRUCKER_BASE_STATION_2:
		{
			new count;
			foreach(Vehicles, i)
		    {
		        if(!vehicle[i][cIsCreated]) 
		        	continue;
				if(!IsVehicleOccupied(i) || !IsValidVehicle(i)) 
					continue;

				if(vehicle[i][cOwnTo] == VEHICLE_TRUCKER_2)
				{
				    DestroyVehicle(i);
					vehicle[i][cIsCreated] = false;
					count++;
					unrent_vehicle_trucker_respawn(i);
				}
				
		    }
		    if(count == 0)
		    	return SendErr(playerid, "Отсутствуют машины для транспортировки!");


		    give_money(playerid, -2500, "Доставка грузовиков в ТК");
			format(String144, sizeof(String144), "[T] %s [%d] вызвал эвакуатор и привёз на базу %d грузовиков, потратив 2500 рублей!", pData[playerid][pNickname], playerid, count);
			send_trucker_job(trucker_id, COLOR_GREY, String144);
		}
		case TRUCKER_BASE_STATION_3:
		{
			new count;
			foreach(Vehicles, i)
		    {
		        if(!vehicle[i][cIsCreated]) 
		        	continue;
				if(!IsVehicleOccupied(i) || !IsValidVehicle(i)) 
					continue;

				if(vehicle[i][cOwnTo] == VEHICLE_TRUCKER_3)
				{
				    DestroyVehicle(i);
					vehicle[i][cIsCreated] = false;
					count++;
					unrent_vehicle_trucker_respawn(i);
				}
				
		    }
		    if(count == 0)
		    	return SendErr(playerid, "Отсутствуют машины для транспортировки!");

		    give_money(playerid, -2500, "Доставка грузовиков в ТК");
			format(String144, sizeof(String144), "[T] %s [%d] вызвал эвакуатор и привёз на базу %d грузовиков, потратив 2500 рублей!", pData[playerid][pNickname], playerid, count);
			send_trucker_job(trucker_id, COLOR_GREY, String144);
		}
	}


	return true;
}

callback:: spawn_rent_car_trucker(i, v, time)
{
	if(IsPlayerConnected(i))
	{	
		time--;

		if(!time)
		{
			unrent_job_trucker(i);
			end_trucker_job(i);
			return true;
		}
		pTemp[i][rent_car_spawn_timer] = SetTimerEx("spawn_rent_car_trucker", 1000, false, "iii", i, v, time);
	}	
	return true;
} 


stock unrent_vehicle_trucker_respawn(carid)
{

	foreach(new i: logged_players)
	{
		new 
			v = pTemp[i][rent_car];

		if(v == carid)
		{
			unrent_job_trucker(i);
			end_trucker_job(i);
		}
	}
	return true;

}
