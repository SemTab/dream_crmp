

callback:: load_house_all()
{
	new Result:house_player = sql_queryEx(zConn, "SELECT * FROM `house` ORDER BY `house_id`", QUERY_CACHED);

	new all_mechanic_station = sql_num_rows(house_player);

	new time = GetTickCount();


 	for(new i; i < all_mechanic_station; i++)
	{
		House[i][house_id]  = sql_get_field_assoc_int_ex(house_player, i, "house_id"); 

		House[i][house_owned]  = sql_get_field_assoc_int_ex(house_player, i, "house_owned_id"); 

		House[i][house_class]  = sql_get_field_assoc_int_ex(house_player, i, "house_class"); 
		House[i][house_price]  = sql_get_field_assoc_int_ex(house_player, i, "house_price"); 
		House[i][house_lock]  = sql_get_field_assoc_int_ex(house_player, i, "house_lock"); 
		House[i][house_takings]  = sql_get_field_assoc_int_ex(house_player, i, "house_takings"); 	
		House[i][house_days]  = sql_get_field_assoc_int_ex(house_player, i, "house_day"); 

  		House[i][house_enter_x] = sql_get_field_assoc_float_ex(house_player, i, "house_enter_x");
  		House[i][house_enter_y] = sql_get_field_assoc_float_ex(house_player, i, "house_enter_y");
  		House[i][house_enter_z] = sql_get_field_assoc_float_ex(house_player, i, "house_enter_z");

  		House[i][house_exit_x] = sql_get_field_assoc_float_ex(house_player, i, "house_exit_x");
  		House[i][house_exit_y] = sql_get_field_assoc_float_ex(house_player, i, "house_exit_y");
  		House[i][house_exit_z] = sql_get_field_assoc_float_ex(house_player, i, "house_exit_z");

  		House[i][house_park_x] = sql_get_field_assoc_float_ex(house_player, i, "house_park_x");
  		House[i][house_park_y] = sql_get_field_assoc_float_ex(house_player, i, "house_park_y");
  		House[i][house_park_z] = sql_get_field_assoc_float_ex(house_player, i, "house_park_z");
  		House[i][house_park_a] = sql_get_field_assoc_float_ex(house_player, i, "house_park_a");

		House[i][house_people_1_id]  = sql_get_field_assoc_int_ex(house_player, i, "house_people_1_id"); 
		House[i][house_people_1_day]  = sql_get_field_assoc_int_ex(house_player, i, "house_people_1_day"); 
		House[i][house_people_2_id]  = sql_get_field_assoc_int_ex(house_player, i, "house_people_2_id"); 
		House[i][house_people_2_day]  = sql_get_field_assoc_int_ex(house_player, i, "house_people_2_day"); 	
		House[i][house_people_3_id]  = sql_get_field_assoc_int_ex(house_player, i, "house_people_3_id"); 
		House[i][house_people_3_day]  = sql_get_field_assoc_int_ex(house_player, i, "house_people_3_day"); 
		House[i][house_people_4_id]  = sql_get_field_assoc_int_ex(house_player, i, "house_people_4_id"); 	
		House[i][house_people_4_day]  = sql_get_field_assoc_int_ex(house_player, i, "house_people_4_day"); 

		House[i][safe_house_status]  = sql_get_field_assoc_int_ex(house_player, i, "safe_house_status"); 
		House[i][safe_house_pass]  = sql_get_field_assoc_int_ex(house_player, i, "safe_house_pass"); 
		House[i][safe_house_money]  = sql_get_field_assoc_int_ex(house_player, i, "safe_house_money"); 
		House[i][safe_house_drugs]  = sql_get_field_assoc_int_ex(house_player, i, "safe_house_drugs"); 
		House[i][safe_house_drugs_hard] = sql_get_field_assoc_int_ex(house_player, i, "safe_house_drugs_hard");

		House[i][wardrobe_gun_1]  = sql_get_field_assoc_int_ex(house_player, i, "wardrobe_gun_1"); 
		House[i][wardrobe_gun_2]  = sql_get_field_assoc_int_ex(house_player, i, "wardrobe_gun_2"); 
		House[i][wardrobe_gun_3]  = sql_get_field_assoc_int_ex(house_player, i, "wardrobe_gun_3"); 

		House[i][wardrobe_gun_ammo_1]  = sql_get_field_assoc_int_ex(house_player, i, "wardrobe_gun_ammo_1"); 
		House[i][wardrobe_gun_ammo_2]  = sql_get_field_assoc_int_ex(house_player, i, "wardrobe_gun_ammo_2"); 
		House[i][wardrobe_gun_ammo_3]  = sql_get_field_assoc_int_ex(house_player, i, "wardrobe_gun_ammo_3"); 

		House[i][wardrobe_skin_1]  = sql_get_field_assoc_int_ex(house_player, i, "wardrobe_skin_1"); 
		House[i][wardrobe_skin_2]  = sql_get_field_assoc_int_ex(house_player, i, "wardrobe_skin_2"); 
		House[i][wardrobe_skin_3]  = sql_get_field_assoc_int_ex(house_player, i, "wardrobe_skin_3"); 

		House[i][wardrobe_aks_1]  = sql_get_field_assoc_int_ex(house_player, i, "wardrobe_aks_1"); 
		House[i][wardrobe_aks_2]  = sql_get_field_assoc_int_ex(house_player, i, "wardrobe_aks_2"); 
		House[i][wardrobe_aks_3]  = sql_get_field_assoc_int_ex(house_player, i, "wardrobe_aks_3"); 

		House[i][wardrobe_status]  = sql_get_field_assoc_int_ex(house_player, i, "wardrobe_status"); 

		House[i][house_people_status]  = sql_get_field_assoc_int_ex(house_player, i, "house_people_status");
		House[i][house_people_price]  = sql_get_field_assoc_int_ex(house_player, i, "house_people_price");

		House[i][house_status_people]  = sql_get_field_assoc_int_ex(house_player, i, "house_status_people");
		House[i][house_subsidii_status]  = sql_get_field_assoc_int_ex(house_player, i, "house_subsidii_status");

		House[i][house_sell_status]  = sql_get_field_assoc_int_ex(house_player, i, "house_sell_status");
		House[i][house_sell_count_payday]  = sql_get_field_assoc_int_ex(house_player, i, "house_sell_count_payday");

		House[i][house_virtualword] = sql_get_field_assoc_int_ex(house_player, i, "house_virtualword");


		House[i][house_garage_status] = sql_get_field_assoc_int_ex(house_player, i, "house_garage_status");
		House[i][house_garage_class] = sql_get_field_assoc_int_ex(house_player, i, "house_garage_class");

  		House[i][house_park_garage_x] = sql_get_field_assoc_float_ex(house_player, i, "house_park_garage_x");
  		House[i][house_park_garage_y] = sql_get_field_assoc_float_ex(house_player, i, "house_park_garage_y");
  		House[i][house_park_garage_z] = sql_get_field_assoc_float_ex(house_player, i, "house_park_garage_z");
  		House[i][house_park_garage_a] = sql_get_field_assoc_float_ex(house_player, i, "house_park_garage_a");

		if(House[i][house_class] == 5 || House[i][house_class] == 6)
		{
			if(House[i][house_owned] == -1)
			{
				House[i][house_pickup] = CreateDynamicPickup(13731, 23, House[i][house_enter_x], House[i][house_enter_y], House[i][house_enter_z], House[i][house_virtualword], -1, -1, STREAM_DISTANCE_DYNAMIC_PICKUP);
			}
			else
			{
				House[i][house_pickup] = CreateDynamicPickup(13732, 23, House[i][house_enter_x], House[i][house_enter_y], House[i][house_enter_z], House[i][house_virtualword], -1, -1, STREAM_DISTANCE_DYNAMIC_PICKUP);
				
			}


			create_dynamic_area(House[i][house_enter_x], House[i][house_enter_y], House[i][house_enter_z], House[i][house_virtualword], i, H_ENTER, 1.0);
		}
		else
		{
			if(House[i][house_owned] == -1)
			{
				House[i][house_pickup] = CreateDynamicPickup(13731, 23, House[i][house_enter_x], House[i][house_enter_y], House[i][house_enter_z], -1, -1, -1, STREAM_DISTANCE_DYNAMIC_PICKUP);
				House[i][house_mapicon] = CreateDynamicMapIcon(House[i][house_enter_x], House[i][house_enter_y], House[i][house_enter_z], 31, COLOR_WHITE, 0, -1, -1, 100.0);
			}
			else
			{
				House[i][house_pickup] = CreateDynamicPickup(13732, 23, House[i][house_enter_x], House[i][house_enter_y], House[i][house_enter_z], -1, -1, -1, STREAM_DISTANCE_DYNAMIC_PICKUP);
				House[i][house_mapicon] = CreateDynamicMapIcon(House[i][house_enter_x], House[i][house_enter_y], House[i][house_enter_z], 32, COLOR_WHITE, 0, -1, -1, 100.0);
				
			}


			create_dynamic_area(House[i][house_enter_x], House[i][house_enter_y], House[i][house_enter_z], -1, i, H_ENTER);
		}
	 
		if(House[i][house_garage_status] && House[i][house_garage_class] > 1)
		{

			create_dynamic_area(House[i][house_park_garage_x], House[i][house_park_garage_y], House[i][house_park_garage_z], -1, i, H_G_ENTER, 5.0);

			create_circle_pickup_o(House[i][house_park_garage_x], House[i][house_park_garage_y], House[i][house_park_garage_z], TRIGGER_BLUE);

			garage_text_house[i] = CreateDynamic3DTextLabel(""cWH"Гараж дома\n\
				"cWH"Чтобы заехать нажмите "cBLUE"[ГУДОК]\n\
				"cWH"Чтобы зайти нажмите "cBLUE"[ALT]",-1, \
			House[i][house_park_garage_x], House[i][house_park_garage_y], House[i][house_park_garage_z]+1.0, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
		}



		CreateDynamic3DTextLabel(""cWH"Взаимодействие с домом\n"cBLUE"[ALT]",-1, \
		House[i][house_enter_x], House[i][house_enter_y], House[i][house_enter_z], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	

  		all_houses++;
	}


	CreateDynamicPickup(13702, 23, house_int_exit_coord[1][0], house_int_exit_coord[1][1], house_int_exit_coord[1][2], -1);
	CreateDynamicPickup(13702, 23, house_int_exit_coord[2][0], house_int_exit_coord[2][1], house_int_exit_coord[2][2], -1);
	CreateDynamicPickup(13702, 23, house_int_exit_coord[3][0], house_int_exit_coord[3][1], house_int_exit_coord[3][2], -1);
	CreateDynamicPickup(13702, 23, house_int_exit_coord[4][0], house_int_exit_coord[4][1], house_int_exit_coord[4][2], -1);
	CreateDynamicPickup(13702, 23, house_int_exit_coord[5][0], house_int_exit_coord[5][1], house_int_exit_coord[5][2], -1);
	CreateDynamicPickup(13702, 23, house_int_exit_coord[6][0], house_int_exit_coord[6][1], house_int_exit_coord[6][2], -1);
	CreateDynamicPickup(13702, 23, house_int_exit_coord[7][0], house_int_exit_coord[7][1], house_int_exit_coord[7][2], -1);

	create_safe_position(); 
	create_wardrobe_position();

	CreateDynamic3DTextLabel(""cWH"Выход из дома\n"cBLUE"[ALT]",-1, \
	house_int_exit_coord[1][0], house_int_exit_coord[1][1], house_int_exit_coord[1][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	

	CreateDynamic3DTextLabel(""cWH"Выход из дома\n"cBLUE"[ALT]",-1, \
	house_int_exit_coord[2][0], house_int_exit_coord[2][1], house_int_exit_coord[2][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	

	CreateDynamic3DTextLabel(""cWH"Выход из дома\n"cBLUE"[ALT]",-1, \
	house_int_exit_coord[3][0], house_int_exit_coord[3][1], house_int_exit_coord[3][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	

	CreateDynamic3DTextLabel(""cWH"Выход из дома\n"cBLUE"[ALT]",-1, \
	house_int_exit_coord[4][0], house_int_exit_coord[4][1], house_int_exit_coord[4][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	

	CreateDynamic3DTextLabel(""cWH"Выход из апартаментов\n"cBLUE"[ALT]",-1, \
	house_int_exit_coord[5][0], house_int_exit_coord[5][1], house_int_exit_coord[5][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	

	CreateDynamic3DTextLabel(""cWH"Выход из апартаментов\n"cBLUE"[ALT]",-1, \
	house_int_exit_coord[6][0], house_int_exit_coord[6][1], house_int_exit_coord[6][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	


	CreateDynamic3DTextLabel(""cWH"Выход из дома\n"cBLUE"[ALT]",-1, \
	house_int_exit_coord[7][0], house_int_exit_coord[7][1], house_int_exit_coord[7][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	


	create_dynamic_area(house_int_exit_coord[1][0], house_int_exit_coord[1][1], house_int_exit_coord[1][2], -1, 1, H_EXIT);
	create_dynamic_area(house_int_exit_coord[2][0], house_int_exit_coord[2][1], house_int_exit_coord[2][2], -1, 1, H_EXIT);

	create_dynamic_area(house_int_exit_coord[3][0], house_int_exit_coord[3][1], house_int_exit_coord[3][2], -1, 1, H_EXIT);
	create_dynamic_area(house_int_exit_coord[4][0], house_int_exit_coord[4][1], house_int_exit_coord[4][2], -1, 1, H_EXIT);

	create_dynamic_area(house_int_exit_coord[5][0], house_int_exit_coord[5][1], house_int_exit_coord[5][2], -1, 1, H_EXIT);
	create_dynamic_area(house_int_exit_coord[6][0], house_int_exit_coord[6][1], house_int_exit_coord[6][2], -1, 1, H_EXIT);

	create_dynamic_area(house_int_exit_coord[7][0], house_int_exit_coord[7][1], house_int_exit_coord[7][2], -1, 1, H_EXIT);


	create_dynamic_area(-330.9939, -831.6519, 1201.9314, -1, 1, H_G_EXIT, 1.0);// low
	create_dynamic_area(-292.0885, -511.4091, 1201.9314, -1, 1, H_G_EXIT, 1.0);// medium
	create_dynamic_area(883.7798, -430.4661, 1201.9314, -1, 1, H_G_EXIT, 1.0);// high

	create_circle_pickup_o(-330.9939, -831.6519, 1201.9314, TRIGGER_LRED);
	create_circle_pickup_o(-292.0885, -511.4091, 1201.9314, TRIGGER_LRED);
	create_circle_pickup_o(883.7798, -430.4661, 1201.9314, TRIGGER_LRED);

	CreateDynamic3DTextLabel(""cWH"Выход из гаража\n"cBLUE"[ALT]",-1, \
	-330.9939, -831.6519, 1201.9314, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);

	CreateDynamic3DTextLabel(""cWH"Выход из гаража\n"cBLUE"[ALT]",-1, \
	-292.0885, -511.4091, 1201.9314, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	

	CreateDynamic3DTextLabel(""cWH"Выход из гаража\n"cBLUE"[ALT]",-1, \
	883.7798, -430.4661, 1201.9314, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);

	create_dynamic_area(-343.6736,-833.6750,1201.9314, -1, 1, H_G_EXIT_V, 5.0);// low
	create_dynamic_area(-309.4497,-525.3882,1201.9314, -1, 1, H_G_EXIT_V, 5.0);// medium
	create_dynamic_area(872.9420,-444.0222,1201.9314, -1, 1, H_G_EXIT_V, 5.0);// high

	create_circle_pickup_o(-343.6736,-833.6750,1201.9314, TRIGGER_BLUE);
	create_circle_pickup_o(-309.4497,-525.3882,1201.9314, TRIGGER_BLUE);
	create_circle_pickup_o(872.9420,-444.0222,1201.9314, TRIGGER_BLUE);

	CreateDynamic3DTextLabel(""cWH"Выезд из гаража\n"cBLUE"[ГУДОК]",-1, \
	-343.6736,-833.6750,1201.9314+1.0, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);

	CreateDynamic3DTextLabel(""cWH"Выезд из гаража\n"cBLUE"[ГУДОК]",-1, \
	-309.4497,-525.3882,1201.9314+1.0, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	

	CreateDynamic3DTextLabel(""cWH"Выезд из гаража\n"cBLUE"[ГУДОК]",-1, \
	872.9420,-444.0222,1201.9314+1.0, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);

	printf("[Дома]: <%i из %i>. Времени затрачено: <%d мс>" ,all_mechanic_station, all_houses, GetTickCount()-  time);

	return true;
}

callback:: save_house(h)
{
    static 
    	formate_str[2500];

    formate_str[0] = EOS; 

    format(formate_str, 1500, "UPDATE `house` SET \
    	house_owned_id = '%d',\
    	house_price = '%d',\
    	house_takings = '%d',\
    	house_lock = '%d',\
    	house_day = '%d',\
    	house_class = '%d',\
    	house_people_1_id = '%d',\
    	house_people_1_day = '%d',\
    	house_people_2_id = '%d',\
    	house_people_2_day = '%d',\
    	house_people_3_id = '%d',\
    	house_people_3_day = '%d',\
    	house_people_4_id = '%d',\
    	house_people_4_day = '%d',\
    	safe_house_status = '%d',\
    	safe_house_pass = '%d',\
    	safe_house_money = '%d',\
    	safe_house_drugs = '%d',\
    	safe_house_drugs_hard = '%d',\
    	wardrobe_gun_1 = '%d',\
    	wardrobe_gun_2 = '%d',\
    	wardrobe_gun_3 = '%d',\
    	wardrobe_skin_1 = '%d',\
    	wardrobe_skin_2 = '%d',\
    	wardrobe_skin_3 = '%d',\
    	wardrobe_status = '%d',\
    	house_people_status = '%d',\
    	house_people_price = '%d',\
		house_status_people = '%d',\
		house_subsidii_status = '%d',\
		house_sell_status = '%d',\
		house_sell_count_payday = '%d',\
		wardrobe_aks_1 = '%d',\
		wardrobe_aks_2 = '%d',\
		wardrobe_aks_3 = '%d',\
		house_garage_status = '%d',\
		house_park_garage_x = '%f',\
		house_park_garage_y = '%f',\
		house_park_garage_z = '%f',\
		house_park_garage_a = '%f',\
		house_garage_class = '%d'\
    	WHERE house_id = '%d'",
    	House[h][house_owned],
    	House[h][house_price],
    	House[h][house_takings],
    	House[h][house_lock],
    	House[h][house_days],
    	House[h][house_class],
    	House[h][house_people_1_id],
    	House[h][house_people_1_day],
    	House[h][house_people_2_id],
    	House[h][house_people_2_day],
    	House[h][house_people_3_id],
    	House[h][house_people_3_day],
    	House[h][house_people_4_id],
    	House[h][house_people_4_day],
    	House[h][safe_house_status],
    	House[h][safe_house_pass],
    	House[h][safe_house_money],
    	House[h][safe_house_drugs],
    	House[h][safe_house_drugs_hard],
    	House[h][wardrobe_gun_1],
    	House[h][wardrobe_gun_2],
    	House[h][wardrobe_gun_3],
    	House[h][wardrobe_skin_1],
    	House[h][wardrobe_skin_2],
    	House[h][wardrobe_skin_3],
    	House[h][wardrobe_status],
    	House[h][house_people_status],
    	House[h][house_people_price],
		House[h][house_status_people],
		House[h][house_subsidii_status],

		House[h][house_sell_status],
		House[h][house_sell_count_payday],

		House[h][wardrobe_aks_1],
		House[h][wardrobe_aks_2],
		House[h][wardrobe_aks_3],

		House[h][house_garage_status],
		House[h][house_park_garage_x],
		House[h][house_park_garage_y],
		House[h][house_park_garage_z],
		House[h][house_park_garage_a],
		House[h][house_garage_class],

    	House[h][house_id]);

    sql_queryEx(zConn, formate_str, QUERY_THREADED);	

    return true;
}


callback:: sell_house_admin(h, reason[], money_back)
{
	if(House[h][house_owned] == -1) 
		return printf("Ошибка! Дом №%d никому не принадлежит!", h);

	new 
		price = House[h][house_price],
		owner_id = House[h][house_owned];

	new 
		owner_house_name[32];

	new 
		fmt_str[144];

	GetPlayerNameByID(owner_id, owner_house_name);

	new 
		player_id = GetPlayerID(owner_house_name);

	if(IsPlayerConnected(player_id))
	{
		if(pData[player_id][pHouse] == h)
		{	
			pData[player_id][pHouse] = -1;
			UpdatePlayerData(player_id,"house", pData[player_id][pHouse]);
			SFCM(player_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Ваш дом был продан администратором. Причина: %s", reason);	

			if(pData[player_id][pFamily] != -1 && pData[player_id][pFamilyRank] == 7)
			{
				new 
					fam_id = pData[player_id][pFamily];

				format(String256, sizeof(String256), "UPDATE `family` SET \
			    	family_house = '-1'\
			    	WHERE family_id = '%i'",
			    	fam_id);

				sql_queryEx(zConn, String256, QUERY_THREADED);
			}

			pData[player_id][pSpawn] = 0;
			UpdatePlayerData(player_id, "spawn", pData[player_id][pSpawn]);

			if(money_back == 1)
			{

				format(fmt_str, sizeof(fmt_str), "Возврат за продажу администратором дома №: %d", h);
				give_money(player_id, price, fmt_str);				
			}

		}
	}
	else
	{	
		new 
			formate_str[280];

		format(formate_str, 80, "UPDATE accounts SET house = '-1' WHERE house = '%d'", h);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	

		format(formate_str, 80, "UPDATE accounts SET spawn = '0' WHERE id = '%d'", owner_id);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	

		format(formate_str,sizeof(formate_str),"UPDATE `family` SET `family_house` = '-1' WHERE `family_house` = '%d'", h);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	

		if(money_back == 1)
		{
			format(formate_str, sizeof(formate_str), "UPDATE `accounts` SET `bank` = bank + %i WHERE `id` = '%i'" , price, owner_id);
  			sql_queryEx(zConn, formate_str, QUERY_THREADED);
  		}

	}


   	House[h][house_owned] = -1;
    House[h][house_lock] = 1;
    
    House[h][house_days] = 3;

    House[h][house_people_status] = 0;
    House[h][house_status_people] = 0;	

    House[h][safe_house_status] = 0;
    House[h][safe_house_pass] = 1111;
    House[h][safe_house_money] = 0;
    House[h][safe_house_drugs] = 0;	

	House[h][wardrobe_gun_1] = -1;	
	House[h][wardrobe_gun_2] = -1;	
	House[h][wardrobe_gun_3] = -1;	
	House[h][wardrobe_skin_1] = 0;
	House[h][wardrobe_skin_2] = 0;
	House[h][wardrobe_skin_3] = 0;

    House[h][wardrobe_status] = 0;		
    House[h][house_subsidii_status] = 0;

    House[h][house_garage_class] = 1;		

    update_house_pickup(h);
    save_house(h);
    return true;
}

callback:: sell_house_admin2(h, reason[], money_back)
{
	if(House[h][house_owned] == -1) 
		return printf("Ошибка! Дом №%d никому не принадлежит!", h);

	new 
		price = House[h][house_price],
		owner_id = House[h][house_owned];

	new 
		owner_house_name[32];

	new 
		fmt_str[144];

	GetPlayerNameByID(owner_id, owner_house_name);

	new 
		player_id = GetPlayerID(owner_house_name);

	if(IsPlayerConnected(player_id))
	{
		if(pData[player_id][pHouse] == h)
		{	
			pData[player_id][pHouse] = -1;
			UpdatePlayerData(player_id,"house", pData[player_id][pHouse]);
			SFCM(player_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Ваш дом был продан администратором. Причина: %s", reason);	

			pData[player_id][pSpawn] = 0;
			UpdatePlayerData(player_id, "spawn", pData[player_id][pSpawn]);


			if(pData[player_id][pFamily] != -1 && pData[player_id][pFamilyRank] == 7)
			{
				new 
					fam_id = pData[player_id][pFamily];
					
				format(String256, sizeof(String256), "UPDATE `family` SET \
			    	family_house = '-1'\
			    	WHERE family_id = '%i'",
			    	fam_id);

				sql_queryEx(zConn, String256, QUERY_THREADED);
			}

			if(money_back == 1)
			{

				format(fmt_str, sizeof(fmt_str), "Возврат за продажу администратором дома №: %d", h);
				give_money(player_id, price, fmt_str);				
			}

		}
	}
	else
	{	
		new 
			formate_str[280];

		format(formate_str, 80, "UPDATE accounts SET house = '-1' WHERE house = '%d'", h);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	

		format(formate_str, 80, "UPDATE accounts SET spawn = '0' WHERE id = '%d'", owner_id);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	

		format(formate_str,sizeof(formate_str),"UPDATE `family` SET `family_house` = '-1' WHERE `family_house` = '%d'", h);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);

		if(money_back == 1)
		{
			format(formate_str, sizeof(formate_str), "UPDATE `accounts` SET `bank` = bank + %i WHERE `id` = '%i'" , price, owner_id);
  			sql_queryEx(zConn, formate_str, QUERY_THREADED);
  		}

	}


   	House[h][house_owned] = -1;
    House[h][house_lock] = 1;
    
    House[h][house_days] = 3;

    House[h][house_people_status] = 0;
    House[h][house_status_people] = 0;	

    House[h][safe_house_status] = 0;
    House[h][safe_house_pass] = 1111;
    House[h][safe_house_money] = 0;
    House[h][safe_house_drugs] = 0;	

	House[h][wardrobe_gun_1] = -1;	
	House[h][wardrobe_gun_2] = -1;	
	House[h][wardrobe_gun_3] = -1;	
	House[h][wardrobe_skin_1] = 0;
	House[h][wardrobe_skin_2] = 0;
	House[h][wardrobe_skin_3] = 0;

    House[h][wardrobe_status] = 0;		
    House[h][house_subsidii_status] = 0;

    House[h][house_garage_class] = 1;		

    update_house_pickup(h);
    save_house(h);
    return true;
}


stock sell_house_accept(playerid)
{
	SPD(playerid, DIALOG_ACCEPT_SELL_HOUSE, DIALOG_STYLE_MSGBOX, !""cBLUE"Продажа дома", !"\
	"cWH"Вы уверены, что хотите продать дом государству?\n\n\
	Вам будет возвращено 80% от стоимости!", !"Да", !"Нет");

	return true;

}

stock sell_house(playerid, h)
{
    if(pData[playerid][pHouse] == h)
	{

		new 
			final_money = floatround(House[h][house_price]*0.8);

		pData[playerid][pHouse] = -1;
		UpdatePlayerData(playerid,"house", pData[playerid][pHouse]);
		pData[playerid][pSpawn] = 0;
		UpdatePlayerData(playerid, "spawn", pData[playerid][pSpawn]);

		SendSucc(playerid, "Вы продали дом государству!");

	 	format(String144, sizeof(String144), "Продажа дома №%d", h);
		give_money(playerid, final_money, String144);

		if(GetPVarIntNew(playerid, "house_id_enter_p") == h)
		{
	   		exit_house(playerid, GetPlayerVirtualWorld(playerid));
		}

		if(pData[playerid][pFamily] != -1 && pData[playerid][pFamilyRank] == 7)
		{
			new 
				fam_id = pData[playerid][pFamily];
				
			format(String256, sizeof(String256), "UPDATE `family` SET \
		    	family_house = '-1'\
		    	WHERE family_id = '%i'",
		    	fam_id);

			sql_queryEx(zConn, String256, QUERY_THREADED);
		}
		
		new 
			formate_str[280];
		new owner_id = House[h][house_owned];
		
		format(formate_str, 80, "UPDATE accounts SET house = '-1' WHERE house = '%d'", h);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	

		format(formate_str, 80, "UPDATE accounts SET spawn = '0' WHERE id = '%d'", owner_id);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	

		format(formate_str,sizeof(formate_str),"UPDATE `family` SET `family_house` = '-1' WHERE `family_house` = '%d'", h);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	
		
    House[h][house_owned] = -1;
    House[h][house_lock] = 1;
    
    House[h][house_days] = 3;

    House[h][house_people_status] = 0;
    House[h][house_status_people] = 0;	

    House[h][safe_house_status] = 0;
    House[h][safe_house_pass] = 1111;
    House[h][safe_house_money] = 0;
    House[h][safe_house_drugs] = 0;	

	House[h][wardrobe_gun_1] = -1;	
	House[h][wardrobe_gun_2] = -1;	
	House[h][wardrobe_gun_3] = -1;	
	House[h][wardrobe_skin_1] = 0;
	House[h][wardrobe_skin_2] = 0;
	House[h][wardrobe_skin_3] = 0;

    House[h][wardrobe_status] = 0;		
    House[h][house_subsidii_status] = 0;

    House[h][house_garage_class] = 1;		

    update_house_pickup(h);
    save_house(h);
	}

	return true;
}

stock unrent_house_payday_1(h)
{
	new 
		renter_id = House[h][house_people_1_id];	

	new 
		rent_house_name[32];

	GetPlayerNameByID(renter_id, rent_house_name);

	new 
		rent_id = GetPlayerID(rent_house_name);

	if(IsPlayerConnected(rent_id))
	{
		if(pData[rent_id][pHouseRent] == h)
		{	
			pData[rent_id][pHouseRent] = -1;
			UpdatePlayerData(rent_id,"house_rent", pData[rent_id][pHouseRent]);
			SFCM(rent_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы были выселены из дома за неуплату!");	


			pData[rent_id][pSpawn] = 0;
			UpdatePlayerData(rent_id, "spawn", pData[rent_id][pSpawn]);
		}
	}
	else
	{	
		new 
			formate_str[280];

		format(formate_str, 80, "UPDATE accounts SET house_rent = '-1' WHERE house_rent = '%d'", h);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	

		format(formate_str, 80, "UPDATE accounts SET spawn = '0' WHERE id = '%d'", renter_id);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	


		send_off_message(-1, rent_house_name, "Вы были выселены из дома за неуплату комнаты!");

	}

	return true;

}

stock unrent_house_payday_2(h)
{
	new 
		renter_id = House[h][house_people_2_id];	

	new 
		rent_house_name[32];

	GetPlayerNameByID(renter_id, rent_house_name);

	new 
		rent_id = GetPlayerID(rent_house_name);

	if(IsPlayerConnected(rent_id))
	{
		if(pData[rent_id][pHouseRent] == h)
		{	
			pData[rent_id][pHouseRent] = -1;
			UpdatePlayerData(rent_id,"house_rent", pData[rent_id][pHouseRent]);
			SFCM(rent_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы были выселены из дома за неуплату!");	


			pData[rent_id][pSpawn] = 0;
			UpdatePlayerData(rent_id, "spawn", pData[rent_id][pSpawn]);
		}
	}
	else
	{	
		new 
			formate_str[280];

		format(formate_str, 80, "UPDATE accounts SET house_rent = '-1' WHERE house_rent = '%d'", h);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	

		format(formate_str, 80, "UPDATE accounts SET spawn = '0' WHERE id = '%d'", renter_id);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	


		send_off_message(-1, rent_house_name, "Вы были выселены из дома за неуплату комнаты!");

	}

	return true;

}

stock unrent_house_payday_3(h)
{
	new 
		renter_id = House[h][house_people_3_id];	

	new 
		rent_house_name[32];

	GetPlayerNameByID(renter_id, rent_house_name);

	new 
		rent_id = GetPlayerID(rent_house_name);

	if(IsPlayerConnected(rent_id))
	{
		if(pData[rent_id][pHouseRent] == h)
		{	
			pData[rent_id][pHouseRent] = -1;
			UpdatePlayerData(rent_id,"house_rent", pData[rent_id][pHouseRent]);
			SFCM(rent_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы были выселены из дома за неуплату!");	


			pData[rent_id][pSpawn] = 0;
			UpdatePlayerData(rent_id, "spawn", pData[rent_id][pSpawn]);
		}
	}
	else
	{	
		new 
			formate_str[280];

		format(formate_str, 80, "UPDATE accounts SET house_rent = '-1' WHERE house_rent = '%d'", h);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	

		format(formate_str, 80, "UPDATE accounts SET spawn = '0' WHERE id = '%d'", renter_id);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	


		send_off_message(-1, rent_house_name, "Вы были выселены из дома за неуплату комнаты!");

	}

	return true;

}

stock unrent_house_payday_4(h)
{
	new 
		renter_id = House[h][house_people_4_id];	

	new 
		rent_house_name[32];

	GetPlayerNameByID(renter_id, rent_house_name);

	new 
		rent_id = GetPlayerID(rent_house_name);

	if(IsPlayerConnected(rent_id))
	{
		if(pData[rent_id][pHouseRent] == h)
		{	
			pData[rent_id][pHouseRent] = -1;
			UpdatePlayerData(rent_id,"house_rent", pData[rent_id][pHouseRent]);
			SFCM(rent_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы были выселены из дома за неуплату!");	


			pData[rent_id][pSpawn] = 0;
			UpdatePlayerData(rent_id, "spawn", pData[rent_id][pSpawn]);
		}
	}
	else
	{	
		new 
			formate_str[280];

		format(formate_str, 80, "UPDATE accounts SET house_rent = '-1' WHERE house_rent = '%d'", h);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	

		format(formate_str, 80, "UPDATE accounts SET spawn = '0' WHERE id = '%d'", renter_id);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	


		send_off_message(-1, rent_house_name, "Вы были выселены из дома за неуплату комнаты!");

	}

	return true;

}

stock house_sell_payday(h)
{
	if(House[h][house_owned] == -1) 
		return printf("Ошибка! Дом №%d никому не принадлежит!", h);

	new 
		owner_id = House[h][house_owned];

	new 
		owner_house_name[32];

	GetPlayerNameByID(owner_id, owner_house_name);

	new 
		player_id = GetPlayerID(owner_house_name);

	new 
		final_money = floatround(House[h][house_price]*0.8);


	if(IsPlayerConnected(player_id))
	{
		if(pData[player_id][pHouse] == h)
		{	
			pData[player_id][pHouse] = -1;
			UpdatePlayerData(player_id,"house", pData[player_id][pHouse]);
			SFCM(player_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Ваш дом был продан в гос.стоимость. Причина: Неоплата имущества");	

			pData[player_id][pSpawn] = 0;
			UpdatePlayerData(player_id, "spawn", pData[player_id][pSpawn]);

	        SendClientMessage(player_id, COLOR_LIGHTRED, "Вы можете вернуть 80 процентов от стоимости имущества");
	        SendClientMessage(player_id, COLOR_LIGHTRED, "Для этого введите команду /returnmoney");

	        pData[player_id][pReturnMoney] += final_money;
	        if(pData[player_id][pReturnMoney] > 20000000 ) pData[player_id][pReturnMoney] = 0;

	        
		}
	}
	else
	{	
		new 
			formate_str[280];

		format(formate_str, 80, "UPDATE accounts SET house = '-1' WHERE house = '%d'", h);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	

		format(formate_str, 80, "UPDATE accounts SET spawn = '0' WHERE id = '%d'", owner_id);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	

		format(String256,sizeof(String256),"UPDATE `accounts` SET returnmoney = returnmoney + %d WHERE id = '%i'", final_money, owner_id);
		sql_queryEx(zConn, String256, QUERY_THREADED);


		send_off_message(-1, owner_house_name, "Ваш дом был продан в гос.стоимость за неуплату. Мы вернули 80 процентов (/returnmoney)");

	}
	
	House[h][house_sell_count_payday] = RandomEx(2, 22);

   	House[h][house_owned] = -1;
    House[h][house_lock] = 1;
    
    House[h][house_days] = 3;

    House[h][house_people_status] = 0;
    House[h][house_status_people] = 0;	

    House[h][safe_house_status] = 0;
    House[h][safe_house_pass] = 1111;
    House[h][safe_house_money] = 0;
    House[h][safe_house_drugs] = 0;	

	House[h][wardrobe_gun_1] = -1;	
	House[h][wardrobe_gun_2] = -1;	
	House[h][wardrobe_gun_3] = -1;	
	House[h][wardrobe_skin_1] = 0;
	House[h][wardrobe_skin_2] = 0;
	House[h][wardrobe_skin_3] = 0;

    House[h][wardrobe_status] = 0;		
    House[h][house_subsidii_status] = 0;	

    House[h][house_sell_status] = 3;		

    update_house_pickup(h);
    save_house(h);

    return true;	
}

stock update_house_pickup(h)
{
	DestroyDynamicMapIcon(House[h][house_mapicon]);
    DestroyDynamicPickup(House[h][house_pickup]);

    if(House[h][house_owned] == -1)
    {
        House[h][house_pickup] = CreateDynamicPickup(1273, 23, House[h][house_enter_x], House[h][house_enter_y], House[h][house_enter_z], -1);
        House[h][house_mapicon] = CreateDynamicMapIcon(House[h][house_enter_x], House[h][house_enter_y], House[h][house_enter_z], 31, COLOR_WHITE, 0, -1, -1, 100.0);
    }
    else
    {
        House[h][house_pickup] = CreateDynamicPickup(1272, 23, House[h][house_enter_x], House[h][house_enter_y], House[h][house_enter_z],-1);
        House[h][house_mapicon] = CreateDynamicMapIcon(House[h][house_enter_x], House[h][house_enter_y], House[h][house_enter_z], 32, COLOR_WHITE, 0, -1, -1, 100.0);
    }
}

stock get_house_class(h)
{
	new 
		name[20],
		class = House[h][house_class];

	switch(class)
	{
		case 1: name = "Низкий";
		case 2: name = "Средний";
		case 3: name = "Высокий";
		case 4: name = "Особняк";
		case 5: name = "Апартаменты";
		case 6: name = "Апартаменты Люкс";
		case 7: name = "Посёлочный";
		default: name = "Заброшенный";
	}
	return name;
}

stock get_house_seif(h)
{
	new 
		name[30],
		class = House[h][safe_house_status];

	switch(class)
	{
		case 1: name = ""cBLUE"Маленький сейф";
		case 2: name = ""cBLUE"Средний сейф";
		case 3: name = ""cBLUE"Большой сейф";
		default: name = ""cLRED"Отсутствует";
	}
	return name;
}

stock enter_house(playerid, h)
{
	if(h == -1) 
		return true;

	if(debug_mode) FormattedMessage(playerid, -1, "[debug] area_enter_house: %d", h);

	new 
		class = House[h][house_class];

	SetPVarIntNew(playerid, "house_id_enter_p", h);

	SetPlayerPosEx(playerid, house_int_exit_coord[class][0], house_int_exit_coord[class][1], house_int_exit_coord[class][2], house_int_exit_coord[class][3]);
	SetPlayerVirtualWorld(playerid, h);

	return true;
}

stock exit_house(playerid, h)
{
	if(h == -1) 
		return true;

	if(debug_mode) FormattedMessage(playerid, -1, "[debug] area_exit_house: %d", h);

	if(GetPlayerVirtualWorld(playerid) != GetPVarIntNew(playerid, "house_id_enter_p"))
		return SendErr(playerid, "Вы должны находиться в своём доме!");

	if(House[h][house_class] == 5 || House[h][house_class] == 6)
	{	
		DeletePVarNew(playerid, "house_id_enter_p");
		SetPlayerPosEx(playerid, House[h][house_enter_x], House[h][house_enter_y], House[h][house_enter_z], 2);
		SetPlayerVirtualWorld(playerid, House[h][house_virtualword]);
	}
	else
	{
		SetPlayerPosEx(playerid, House[h][house_enter_x], House[h][house_enter_y], House[h][house_enter_z], 2);
		SetPlayerVirtualWorld(playerid, 0);

		DeletePVarNew(playerid, "house_id_enter_p");
	}

	DeletePVarNew(playerid, "house_id_enter_p");

	return true;
}

stock exit_house_garage(playerid, h)
{
	if(House[h][house_garage_class] == 1)
		return true;

	if(House[h][house_garage_status] == 0)
		return true;

	DeletePVarNew(playerid, "player_in_garage_house");

	SetPlayerPosEx(playerid, House[h][house_park_garage_x], House[h][house_park_garage_y], House[h][house_park_garage_z], House[h][house_park_garage_a]);
	SetPlayerVirtualWorld(playerid, 0);
	return true;
}

stock exit_house_garage_vehicle(playerid, h)
{
	if(House[h][house_garage_class] == 1)
		return true;

	if(House[h][house_garage_status] == 0)
		return true;

	new 
		vehicleid = GetPlayerVehicleID(playerid);

	SetVehiclePosEx(vehicleid, House[h][house_park_x], House[h][house_park_y], House[h][house_park_z], House[h][house_park_a]);

	DeletePVarNew(playerid, "player_in_garage_house");

	SetPlayerVirtualWorld(playerid, 0);
	SetVehicleVirtualWorld(vehicleid, 0);
	LinkVehicleToInterior(vehicleid, 0);
	return true;
}

stock house_info(playerid, id_house)
{

	static 
		h_class[24],
		h_owner[24];

	format(h_class, 24, "%s", get_house_class(id_house));

	if(House[id_house][house_owned] != -1)
	{
		GetPlayerNameByID(House[id_house][house_owned], House[id_house][house_owner]);
		format(h_owner, 24, House[id_house][house_owner]);
	}
	else
	{
		format(h_owner, 24, "Государство");	
	}

	if(House[id_house][house_owned] == -1)
	{
		format(String512, sizeof(String512), "\
			"cWH"Номер дома: 		\t\t"cBLUE"%d\n\
			"cWH"Класс дома:		\t\t"cBLUE"%s\n\
			"cWH"Владелец: 			\t"cBLUE"%s\n\
			"cWH"Статус: 			\t\t%s\n\
			"cWH"Цена: 				\t"cGR"%d рублей\n\
			"cWH"Возможность установить гараж:\t%s\n\
			"cWH"Ежедневная оплата: \t\t\t"cGR"%d рублей\n\n\
			"cBLUE"Вы действительно хотите купить частный дом?",
			id_house+1,
			h_class,
			h_owner,
			(House[id_house][house_owned]) ? (""cGR"Продается") : (""cLRED"Куплен"),
			House[id_house][house_price], 
			House[id_house][house_garage_status] == 1 ? (""cGR"Есть") : (""cLRED"Нет"),
			House[id_house][house_takings]);
		SPD(playerid, DIALOG_BUY_HOUSE, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка частного дома", String512, !"Купить", !"Закрыть");		
	}
	else if(House[id_house][house_people_status] == 0)
	{
		format(String512, sizeof(String512), "\
		"cWH"Номер дома: 		\t\t"cBLUE"%d\n\
		"cWH"Класс дома:		\t\t"cBLUE"%s\n\
		"cWH"Владелец: 			\t"cBLUE"%s\n\
		"cWH"Статус: 			\t\t%s\n\
		"cWH"Стоимость: 		\t\t"cGR"%d руб\n\
		"cWH"Ежедневная оплата: \t\t\t"cGR"%d рублей",
		id_house+1,
		h_class,
		h_owner,
		(House[id_house][house_lock] == 1) ? (""cGR"Дверь открыта") : (""cLRED"Дверь закрыта"),
		House[id_house][house_price], House[id_house][house_takings]);		
		SPD(playerid, DIALOG_INFO_HOUSE, DIALOG_STYLE_MSGBOX, !""cBLUE"Информация о частном доме", String512, !"Войти", !"Закрыть");		
	}
	else if(House[id_house][house_people_status] == 1 && House[id_house][house_people_status] == 1)
	{
		format(String512, sizeof(String512), "\
		"cWH"Номер дома: \t"cBLUE"%d\n\
		"cWH"Класс дома: \t"cBLUE"%s\n\
		"cWH"Владелец: \t"cBLUE"%s\n\
		"cWH"Статус: \t%s\n\
		"cWH"Стоимость: \t"cGR"%d руб\n\
		"cWH"\t\n\
		"cWH"Ежедневная оплата за комнату: \t "cGR"%d руб\n\
		"cWH"Арендовать комнату \t"cGR"Аренда\n\n\
		"cWH"\t\n\
		"cWH"Войти в дом",
		id_house+1,
		h_class,
		h_owner,
		(House[id_house][house_lock] == 1) ? (""cGR"Дверь открыта") : (""cLRED"Дверь закрыта"),
		House[id_house][house_price], House[id_house][house_people_price]);		
		SPD(playerid, DIALOG_INFO_RENT_HOUSE, DIALOG_STYLE_TABLIST, !""cBLUE"Информация о частном доме", String512, !"Выбор", !"Закрыть");		
	}

	return true;
}

stock house_panel_change(playerid, h)
{

	if(debug_mode) FormattedMessage(playerid, -1, "[debug] area_house_menu: %d", h);


	if(House[h][house_status_people] == 0 && House[h][house_owned] == pData[playerid][pMysqlID])
	{
	    format(String512, sizeof(String512), "\
	    "cGREY"Пункт\t"cGREY"Действие\n\
	    "cBLUE"1. "cWH"Информация о доме\t"cGR"Открыть\n\
	    "cBLUE"2. "cWH"Двери в доме\t%s\n\
	    "cBLUE"3. "cWH"Улучшения\t"cGR"Купить\n\
	    "cBLUE"4. "cWH"Продать дом\t"cGR"Продажа\n\
	    \t\n\
	    "cBLUE"- "cWH"Выйти из дома\t"cGR"Выход",
	    (House[h][house_lock] == 1) ? (""cGR"Дверь открыта") : (""cLRED"Дверь закрыта"));
	    return SPD(playerid, SHOW_CHANGE_MENU_HOUSE_1, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление домом", String512, !"Выбрать", !"Закрыть"); 
	}
	else if(House[h][house_status_people] == 1 && House[h][house_owned] == pData[playerid][pMysqlID])
	{
	    format(String512, sizeof(String512), "\
	    "cGREY"Пункт\t"cGREY"Действие\n\
	    "cBLUE"1. "cWH"Информация о доме\t"cGR"Открыть\n\
	    "cBLUE"2. "cWH"Двери в доме\t%s\n\
	    "cBLUE"3. "cWH"Улучшения\t"cGR"Купить\n\
	    "cBLUE"4. "cWH"Продать дом\t"cGR"Продажа\n\
	    "cBLUE"5. "cWH"Жильцы дома\t"cBLUE"Управление\n\
	    \t\n\
	    "cBLUE"- "cWH"Выйти из дома\t"cGR"Выход",
	    (House[h][house_lock] == 1)? (""cGR"Дверь открыта") : (""cLRED"Дверь закрыта"));
	    return SPD(playerid, SHOW_CHANGE_MENU_HOUSE_2, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление домом", String512, !"Выбрать", !"Закрыть"); 		
	}
	else if(House[h][house_status_people] == 0 && House[h][house_owned] != pData[playerid][pMysqlID])
	{
	    format(String512, sizeof(String512), "\
	    "cGREY"Пункт\t"cGREY"Действие\n\
	    "cBLUE"- "cWH"Информация о доме\t"cGR"Открыть\n\
	    \t\n\
	    "cBLUE"- "cWH"Выйти из дома\t"cGR"Выход");
	    return SPD(playerid, SHOW_CHANGE_MENU_HOUSE_3, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление домом", String512, !"Выбрать", !"Закрыть"); 			
	}
	else if(House[h][house_status_people] == 1 && House[h][house_people_status] == 1 && House[h][house_owned] != pData[playerid][pMysqlID])
	{
	    format(String512, sizeof(String512), "\
	    "cGREY"Пункт\t"cGREY"Действие\n\
	    "cBLUE"- "cWH"Информация о доме\t"cGR"Открыть\n\
	    "cBLUE"- "cWH"Аренда комнаты\t"cGR"Открыть\n\
	    \t\n\
	    "cBLUE"- "cWH"Выйти из дома\t"cGR"Выход");
	    return SPD(playerid, SHOW_CHANGE_MENU_HOUSE_4, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление домом", String512, !"Выбрать", !"Закрыть"); 			
	}
	else
	{
	    format(String512, sizeof(String512), "\
	    "cGREY"Пункт\t"cGREY"Действие\n\
	    "cBLUE"- "cWH"Информация о доме\t"cGR"Открыть\n\
	    \t\n\
	    "cBLUE"- "cWH"Выйти из дома\t"cGR"Выход");
	    SPD(playerid, SHOW_CHANGE_MENU_HOUSE_3, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление домом", String512, !"Выбрать", !"Закрыть"); 			
	}
	return true;
}

stock house_panel_change_cmd(playerid, h)
{
	if(debug_mode) FormattedMessage(playerid, -1, "[debug] area_house_menu: %d", h);

	if(House[h][house_status_people] == 0 && House[h][house_owned] == pData[playerid][pMysqlID])
	{
	    format(String512, sizeof(String512), "\
	    "cGREY"Пункт\t"cGREY"Действие\n\
	    "cBLUE"1. "cWH"Информация о доме\t"cGR"Открыть\n\
	    "cBLUE"2. "cWH"Двери в доме\t%s\n\
	    "cBLUE"3. "cWH"Улучшения\t"cGR"Купить\n\
	    "cBLUE"4. "cWH"Продать дом\t"cGR"Продажа",
	    (House[h][house_lock] == 1) ? (""cGR"Дверь открыта") : (""cLRED"Дверь закрыта"));
	    return SPD(playerid, SHOW_CHANGE_MENU_HOUSE_1, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление домом", String512, !"Выбрать", !"Закрыть"); 
	}
	else if(House[h][house_status_people] == 1 && House[h][house_owned] == pData[playerid][pMysqlID])
	{
	    format(String512, sizeof(String512), "\
	    "cGREY"Пункт\t"cGREY"Действие\n\
	    "cBLUE"1. "cWH"Информация о доме\t"cGR"Открыть\n\
	    "cBLUE"2. "cWH"Двери в доме\t%s\n\
	    "cBLUE"3. "cWH"Улучшения\t"cGR"Купить\n\
	    "cBLUE"4. "cWH"Продать дом\t"cGR"Продажа\n\
	    "cBLUE"5. "cWH"Жильцы дома\t"cBLUE"Управление",
	    (House[h][house_lock] == 1)? (""cGR"Дверь открыта") : (""cLRED"Дверь закрыта"));
	    return SPD(playerid, SHOW_CHANGE_MENU_HOUSE_2, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление домом", String512, !"Выбрать", !"Закрыть"); 		
	}
	else if(House[h][house_status_people] == 0 && House[h][house_owned] != pData[playerid][pMysqlID])
	{
	    format(String512, sizeof(String512), "\
	    "cGREY"Пункт\t"cGREY"Действие\n\
	    "cBLUE"- "cWH"Информация о доме\t"cGR"Открыть");
	    return SPD(playerid, SHOW_CHANGE_MENU_HOUSE_3, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление домом", String512, !"Выбрать", !"Закрыть"); 			
	}
	else if(House[h][house_status_people] == 1 && House[h][house_people_status] == 1 && House[h][house_owned] != pData[playerid][pMysqlID])
	{
	    format(String512, sizeof(String512), "\
	    "cGREY"Пункт\t"cGREY"Действие\n\
	    "cBLUE"- "cWH"Информация о доме\t"cGR"Открыть\n\
	    "cBLUE"- "cWH"Аренда комнаты\t"cGR"Открыть");
	    return SPD(playerid, SHOW_CHANGE_MENU_HOUSE_4, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление домом", String512, !"Выбрать", !"Закрыть"); 			
	}
	else
	{
	    format(String512, sizeof(String512), "\
	    "cGREY"Пункт\t"cGREY"Действие\n\
	    "cBLUE"- "cWH"Информация о доме\t"cGR"Открыть");
	    SPD(playerid, SHOW_CHANGE_MENU_HOUSE_3, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление домом", String512, !"Выбрать", !"Закрыть"); 			
	}
	return true;
}

stock manage_people_house_p(playerid, id_house)
{

	format(String512, sizeof(String512), "\
	"cWH"В вашем доме может поселиться максимум "cBLUE"4 человека"cWH"\n\
	Каждый из них оплачивает аренду за проживание в сутки\n\
	Вы можете регулировать стоимость аренды комнаты и выставлять свою стоимость\n\
	Максимальное и минимальное значение стоимости 1 дня аренды - ограничены\n\n\
	Текущая стоимость: "cGR"%d"cWH" рублей\n\n\
	Укажите новую стоимость 1 дня аренды комнаты\n\
	"cBLUE"От 500 рублей и до 15000 рублей", House[id_house][house_people_price]);

	SPD(playerid, DIALOG_CHANGE_PRICE_PEOPLE, DIALOG_STYLE_INPUT, !""cBLUE"Изменение стоимости", String512, !"Далее", !"Назад");



	return true;
}

stock show_menu_rent_house(playerid, id_house)
{
	if(pData[playerid][pHouseRent] != id_house)
		return SendErr(playerid, "Системная ошибка #001 | Обратитесь на форум!");

	if(pData[playerid][pHouseRent] == -1 && pData[playerid][pFlateRent])
		return menu_start_rent(playerid, id_house);

	if(pData[playerid][pHouseRent] == id_house)
	{
		new 
			day_counts;

		if(House[id_house][house_people_1_id] == pData[playerid][pMysqlID])
		{
			day_counts = House[id_house][house_people_1_day];
		}
		else if(House[id_house][house_people_2_id] == pData[playerid][pMysqlID])
		{
			day_counts = House[id_house][house_people_2_day];
		}
		else if(House[id_house][house_people_3_id] == pData[playerid][pMysqlID])
		{
			day_counts = House[id_house][house_people_3_day];
		}
		else if(House[id_house][house_people_4_id] == pData[playerid][pMysqlID])
		{
			day_counts = House[id_house][house_people_4_day];
		}


	    format(String512, sizeof(String512), "\
	    "cGREY"№\t"cGREY"Тип\t"cGREY"Информация\n\
	    "cBLUE"1. \t"cWH"Дней оплачено\t"cBLUE"%d дней\n\
	    "cBLUE"2. \t"cWH"Продление аренды\t"cBLUE"Продлить\n\
	    "cBLUE"3. \t"cWH"Завершить аренду\t"cLRED"Закончить аренду", day_counts);
	    SPD(playerid, DIALOG_RENT_HOUSE_P, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Аренда комнаты", String512, !"Выбрать", !"Закрыть"); 
	}
	else
	{
		SendErr(playerid, "Вы арендуете другой дом!");
	}
	return true;
}

stock countinue_rent_house(playerid, id_house)
{
	new 
		day_counts;

	if(House[id_house][house_people_1_id] == pData[playerid][pMysqlID])
	{
		day_counts = House[id_house][house_people_1_day];
	}
	else if(House[id_house][house_people_2_id] == pData[playerid][pMysqlID])
	{
		day_counts = House[id_house][house_people_2_day];
	}
	else if(House[id_house][house_people_3_id] == pData[playerid][pMysqlID])
	{
		day_counts = House[id_house][house_people_3_day];
	}
	else if(House[id_house][house_people_4_id] == pData[playerid][pMysqlID])
	{
		day_counts = House[id_house][house_people_4_day];
	}


	if(House[id_house][house_people_status] == 0)
		return SendErr(playerid, "Возможность продление аренды запрещена владельцем дома!");

	new 
		final_max_day = MAX_RENT_HOUSE_DAY - day_counts;

	SetPVarIntNew(playerid, "final_max_day_rent", final_max_day);


	format(String1024, sizeof(String1024), "\
	"cWH"На сколько дней Вы хотите продлить аренду комнаты?\n\n\
	Вы можете продлить аренду максимум на %d дней!\n\
	Текущая стоимость 1 дня: "cGR"%d"cWH" рублей\n\n\
	"cBLUE"Введите количество дней аренды:", final_max_day, House[id_house][house_people_price]);

	SPD(playerid, DIALOG_CONTINUT_RENT_HOUSE, DIALOG_STYLE_INPUT, !""cBLUE"Выбор кол-ва дней аренды", String1024, !"Далее", !"Назад");



	return true;
}

stock final_continue_rent_p(playerid, id_house, day)
{

	if(pData[playerid][pHouseRent] != id_house)
		return SendErr(playerid, "Системная ошибка #003 | Обратитесь на форум!");

	new 
		final_money_price = day*House[id_house][house_people_price];

	new 
		fmt_str[200];

	new 
		owner_house_name[32];

	if(GetPlayerMoneyEx(playerid) < final_money_price) 
	{
		//show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
		show_menu_rent_house(playerid, id_house);
		return SendErr(playerid,"У вас недостаточно денежных средств для продления на такое количество дней!");	
	}


	if(House[id_house][house_people_1_id] == pData[playerid][pMysqlID])
	{
		House[id_house][house_people_1_day] = House[id_house][house_people_1_day]+day;

		GetPlayerNameByID(House[id_house][house_owned],owner_house_name);

		new 
			player_id = GetPlayerID(owner_house_name);


		if(IsPlayerConnected(player_id))
		{
			if(House[id_house][house_owned] == pData[player_id][pMysqlID] && player_id != playerid)
			{
				SFCM(player_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы получили "cGR"%d"cWH" рублей на банковский счёт за продление аренды "cBLUE"%s"cWH" на "cBLUE"%d"cWH" дней", final_money_price, pData[playerid][pNickname], day);	
				pData[player_id][pBank] += final_money_price;
			}
		}
		else
		{

			format(fmt_str, sizeof(fmt_str), "UPDATE `accounts` SET  `bank` = bank + %i WHERE `id` = '%i'" , final_money_price, House[id_house][house_owned]);
	  		sql_queryEx(zConn, fmt_str, QUERY_THREADED);
		}

		format(fmt_str, sizeof(fmt_str), "Продление аренды дома №: %d", House[id_house][house_id]);
		give_money(playerid, -final_money_price, fmt_str);


		SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы успешно продлили аренду комнаты в доме №%d на "cBLUE"%d"cWH" дней", id_house+1, day);	

	}
	else if(House[id_house][house_people_2_id] == pData[playerid][pMysqlID])
	{
		House[id_house][house_people_2_day] = House[id_house][house_people_2_day]+day;

		GetPlayerNameByID(House[id_house][house_owned],owner_house_name);

		new 
			player_id = GetPlayerID(owner_house_name);


		if(IsPlayerConnected(player_id))
		{
			if(House[id_house][house_owned] == pData[player_id][pMysqlID] && player_id != playerid)
			{
				SFCM(player_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы получили "cGR"%d"cWH" рублей на банковский счёт за продление аренды "cBLUE"%s"cWH" на "cBLUE"%d"cWH" дней", final_money_price, pData[playerid][pNickname], day);	
				pData[player_id][pBank] += final_money_price;
			}
		}
		else
		{

			format(fmt_str, sizeof(fmt_str), "UPDATE `accounts` SET  `bank` = bank + %i WHERE `id` = '%i'" , final_money_price, House[id_house][house_owned]);
	  		sql_queryEx(zConn, fmt_str, QUERY_THREADED);
		}

		format(fmt_str, sizeof(fmt_str), "Продление аренды дома №: %d", House[id_house][house_id]);
		give_money(playerid, -final_money_price, fmt_str);


		SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы успешно продлили аренду комнаты в доме №%d на "cBLUE"%d"cWH" дней", id_house+1, day);	

	}
	else if(House[id_house][house_people_3_id] == pData[playerid][pMysqlID])
	{
		House[id_house][house_people_3_day] = House[id_house][house_people_3_day]+day;

		GetPlayerNameByID(House[id_house][house_owned],owner_house_name);

		new 
			player_id = GetPlayerID(owner_house_name);


		if(IsPlayerConnected(player_id))
		{
			if(House[id_house][house_owned] == pData[player_id][pMysqlID] && player_id != playerid)
			{
				SFCM(player_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы получили "cGR"%d"cWH" рублей на банковский счёт за продление аренды "cBLUE"%s"cWH" на "cBLUE"%d"cWH" дней", final_money_price, pData[playerid][pNickname], day);	
				pData[player_id][pBank] += final_money_price;
			}
		}
		else
		{

			format(fmt_str, sizeof(fmt_str), "UPDATE `accounts` SET  `bank` = bank + %i WHERE `id` = '%i'" , final_money_price, House[id_house][house_owned]);
	  		sql_queryEx(zConn, fmt_str, QUERY_THREADED);
		}

		format(fmt_str, sizeof(fmt_str), "Продление аренды дома №: %d", House[id_house][house_id]);
		give_money(playerid, -final_money_price, fmt_str);


		SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы успешно продлили аренду комнаты в доме №%d на "cBLUE"%d"cWH" дней", id_house+1, day);	

	}
	else if(House[id_house][house_people_4_id] == pData[playerid][pMysqlID])
	{
		House[id_house][house_people_4_day] = House[id_house][house_people_4_day]+day;

		GetPlayerNameByID(House[id_house][house_owned],owner_house_name);

		new 
			player_id = GetPlayerID(owner_house_name);


		if(IsPlayerConnected(player_id))
		{
			if(House[id_house][house_owned] == pData[player_id][pMysqlID] && player_id != playerid)
			{
				SFCM(player_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы получили "cGR"%d"cWH" рублей на банковский счёт за продление аренды "cBLUE"%s"cWH" на "cBLUE"%d"cWH" дней", final_money_price, pData[playerid][pNickname], day);	
				pData[player_id][pBank] += final_money_price;
			}
		}
		else
		{

			format(fmt_str, sizeof(fmt_str), "UPDATE `accounts` SET  `bank` = bank + %i WHERE `id` = '%i'" , final_money_price, House[id_house][house_owned]);
	  		sql_queryEx(zConn, fmt_str, QUERY_THREADED);
		}

		format(fmt_str, sizeof(fmt_str), "Продление аренды дома №: %d", House[id_house][house_id]);
		give_money(playerid, -final_money_price, fmt_str);


		SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы успешно продлили аренду комнаты в доме №%d на "cBLUE"%d"cWH" дней", id_house+1, day);	

	}

	save_house(pData[playerid][pHouseRent]);

	return true;
}

stock final_rent_house(playerid, id_house)
{
	if(pData[playerid][pHouseRent] != id_house)
		return SendErr(playerid, "Системная ошибка #002 | Обратитесь на форум!");

	new 
		day_counts;

	if(House[id_house][house_people_1_id] == pData[playerid][pMysqlID])
	{
		day_counts = House[id_house][house_people_1_day];
	}
	else if(House[id_house][house_people_2_id] == pData[playerid][pMysqlID])
	{
		day_counts = House[id_house][house_people_2_day];
	}
	else if(House[id_house][house_people_3_id] == pData[playerid][pMysqlID])
	{
		day_counts = House[id_house][house_people_3_day];
	}
	else if(House[id_house][house_people_4_id] == pData[playerid][pMysqlID])
	{
		day_counts = House[id_house][house_people_4_day];
	}


	format(String1024, sizeof(String1024), "\
	"cWH"Вы действительно хотите отказаться от аренды комнаты?\n\n\
	- Если Вы откажетесь от аренды, то деньги не будут возвращены\n\
	- Аренда дома оплачена на "cBLUE"%d"cWH" дня\n\n\
	"cBLUE"Нажмите 'Далее', чтобы отказаться от аренды", day_counts);

	SPD(playerid, DIALOG_END_RENT_HOUSE, DIALOG_STYLE_MSGBOX, !""cBLUE"Откат от аренды дома", String1024, !"Далее", !"Назад");


	return true;
}

stock cancel_rent_house_p(playerid, id_house)
{
	if(House[id_house][house_people_1_id] == pData[playerid][pMysqlID])
	{
		House[id_house][house_people_1_id] = -1;
		House[id_house][house_people_1_day] = 0;
	}
	else if(House[id_house][house_people_2_id] == pData[playerid][pMysqlID])
	{
		House[id_house][house_people_2_id] = -1;
		House[id_house][house_people_2_day] = 0;
	}
	else if(House[id_house][house_people_3_id] == pData[playerid][pMysqlID])
	{
		House[id_house][house_people_3_id] = -1;
		House[id_house][house_people_3_day] = 0;
	}
	else if(House[id_house][house_people_4_id] == pData[playerid][pMysqlID])
	{
		House[id_house][house_people_4_id] = -1;
		House[id_house][house_people_4_day] = 0;
	}

	exit_house(playerid, GetPlayerVirtualWorld(playerid));

	pData[playerid][pHouseRent] = -1;

	UpdatePlayerData(playerid,"house_rent", pData[playerid][pHouseRent]);

	SendSucc(playerid, "Вы отказались от аренды комнат и были выставлены за дверь!");

	format(String320, sizeof(String320), "\
	"cWH"Вы успешно отказались от аренды комнаты\n\n\
	- Деньги за аренду не были возвращены\n\n\
	"cBLUE"Хозяин квартиры выставил Вас за дверь!");

	SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Откат от аренды дома", String320, !"Далее", !"Назад");

	return true;
}

stock manage_general_menu(playerid, id_house)
{
    format(String512, sizeof(String512), "\
    "cGREY"№\t"cGREY"Тип\t"cGREY"Информация\n\
    "cBLUE"1. \t"cWH"Изменение стоимости аренды\t"cBLUE"Изменить\n\
    "cBLUE"2. \t"cWH"Список жильцов в доме\t"cBLUE"%d жильцов\n\
    "cBLUE"3. \t"cWH"Разрешение на аренду\t"cBLUE"%s", 
    count_people_in_house(id_house), (House[id_house][house_people_status]) ? (""cGR"Аренда возможна") : (""cLRED"Аренда запрещена"));
    SPD(playerid, DIALOG_CHANGE_MANAGE_MENU, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Жильцы дома", String512, !"Выбрать", !"Закрыть"); 

    return true;
}

stock manage_people_house(playerid, id_house)
{

	new 
		name_people_1[32],
		name_people_2[32],
		name_people_3[32],
		name_people_4[32];

	GetPlayerNameByID(House[id_house][house_people_1_id], name_people_1);

	if(House[id_house][house_people_1_id] != -1)
	{
		GetPlayerNameByID(House[id_house][house_people_1_id], name_people_1);
	}
	else
	{
		format(name_people_1, 32, "Отсутствует");	
	}
	if(House[id_house][house_people_2_id] != -1)
	{
		GetPlayerNameByID(House[id_house][house_people_2_id], name_people_2);
	}
	else
	{
		format(name_people_2, 32, "Отсутствует");	
	}
	if(House[id_house][house_people_3_id] != -1)
	{
		GetPlayerNameByID(House[id_house][house_people_3_id], name_people_3);
	}
	else
	{
		format(name_people_3, 32, "Отсутствует");	
	}
	if(House[id_house][house_people_4_id] != -1)
	{
		GetPlayerNameByID(House[id_house][house_people_4_id], name_people_4);
	}
	else
	{
		format(name_people_4, 32, "Отсутствует");	
	}

    format(String512, sizeof(String512), "\
    "cGREY"№\t"cGREY"Жилец\t"cGREY"Дней оплачено\n\
    "cBLUE"1. \t"cWH"%s\t"cBLUE"%d дней\n\
    "cBLUE"2. \t"cWH"%s\t"cBLUE"%d дней\n\
    "cBLUE"3. \t"cWH"%s\t"cBLUE"%d дней\n\
    "cBLUE"4. \t"cWH"%s\t"cBLUE"%d дней",

	name_people_1,
	House[id_house][house_people_1_day],
	name_people_2,
	House[id_house][house_people_2_day],
	name_people_3,
	House[id_house][house_people_3_day],
	name_people_4,
	House[id_house][house_people_4_day]);
    SPD(playerid, SHOW_CHANGE_MENU_HOUSE_PEOP_ALL, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Жильцы дома", String512, !"Выбрать", !"Закрыть"); 


	return true;
}

alias:hlock("houselock", "homelock");
CMD:hlock(playerid)
{
	new 
		id_house = pData[playerid][pHouse];

	update_lock_house(playerid, id_house);

	return true;
}

stock update_lock_house(playerid, id_house)
{
	if(House[id_house][house_lock] == 1)
	{
		House[id_house][house_lock] = 2;
		SendSucc(playerid, "Вы успешно "cLRED"закрыли"cWH" двери в доме!");
		//show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_house_1", 4000);
	}
	else if(House[id_house][house_lock] == 2)
	{
		House[id_house][house_lock] = 1;
		SendSucc(playerid, "Вы успешно "cGR"открыли"cWH" двери в доме!");
		//show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_house_3", 4000);
	}

	house_panel_change(playerid, id_house);	
	return true;
}

stock menu_update_house(playerid, id_house)
{
    format(String1024, sizeof(String1024), "\
    "cGREY"Пункт\t"cGREY"Стоимость\t"cGREY"Статус улучшения\n\
    "cBLUE"1. "cWH"Шкаф\t"cGR"%d рублей\t%s\n\
    "cBLUE"2. "cWH"Сейф\t"cGR"%d рублей\t%s\n\
    "cBLUE"3. "cWH"Подселение жильцов\t"cGR"%d рублей\t%s\n\
    "cBLUE"4. "cWH"Субсидии\t"cGR"%d рублей\t%s\n\
    "cBLUE"5. "cWH"Гараж\t"cGR"%i рублей\t%s",
    PRICE_BUY_SHKAF_HOUSE, (House[id_house][wardrobe_status]) ? (""cGR"Улучшение куплено") : (""cLRED"Улучшение не куплено"),
    PRICE_BUY_SEIF_ONE, get_house_seif(id_house),
    PRICE_BUY_PEOPLE, (House[id_house][house_status_people]) ? (""cGR"Улучшение куплено") : (""cLRED"Улучшение не куплено"),
    PRICE_BUY_SUBSIDII, (House[id_house][house_subsidii_status]) ? (""cGR"Улучшение куплено") : (""cLRED"Улучшение не куплено"),
    get_house_garage_cost(id_house), get_house_garage_class_name(id_house));
    SPD(playerid, SHOW_CHANGE_MENU_HOUSE_UPGRADE, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Улучшения", String1024, !"Выбрать", !"Закрыть"); 

	return true;
}

stock get_house_garage_cost(id_house)
{
	new 
		price;

	if(House[id_house][house_garage_class] == 1)
	{
		price = PRICE_GARAGE_LOW;
	}
	if(House[id_house][house_garage_class] == 2)
	{
		price = PRICE_GARAGE_MEDIUM;
	}
	if(House[id_house][house_garage_class] == 3)
	{
		price = PRICE_GARAGE_HIGH;
	}
	if(House[id_house][house_garage_class] == 4)
	{
		price = PRICE_GARAGE_HIGH;
	}
	return price;
}

stock enter_house_garage(playerid, id_house)
{
	if(House[id_house][house_garage_class] == 1)
		return true;

	if(House[id_house][house_garage_status] == 0)
		return true;

	new 
		family_ids = pData[playerid][pFamily];

	new 
		id_houses;

	if(get_family_house(family_ids) != -1)
	{
		id_houses = get_family_house(family_ids);
	}

	if(pData[playerid][pHouse] == id_house || pData[playerid][pHouseRent] == id_house || id_houses == id_house)
	{
		switch(House[id_house][house_garage_class])
		{
			case 2: SetPlayerPosEx(playerid, -330.9939, -831.6519, 1201.9314, 94.8475);
			case 3:	SetPlayerPosEx(playerid, -292.0885, -511.4091, 1201.9314, 0.1867);
			case 4:	SetPlayerPosEx(playerid, 883.7798, -430.4661, 1201.9314, 0.5372);
		}
		SetPlayerVirtualWorld(playerid, id_house);
		SetPVarIntNew(playerid, "player_in_garage_house", 1);
	}
	else
		SendErr(playerid, "Вы не можете зайти в чужой гараж");
	return true;
}

stock enter_house_garage_vehicle(playerid, id_house)
{
	if(House[id_house][house_garage_class] == 1)
		return true;
 
	if(House[id_house][house_garage_status] == 0)
		return true;

	new 
		family_ids = pData[playerid][pFamily];

	new 
		id_houses;

	if(get_family_house(family_ids) != -1)
	{
		id_houses = get_family_house(family_ids);
	}

	if(pData[playerid][pHouse] == id_house || pData[playerid][pHouseRent] == id_house || id_houses == id_house)
	{
		new 
			vehicleid = GetPlayerVehicleID(playerid);

		SetVehicleVirtualWorld(vehicleid, id_house);
		SetPlayerVirtualWorld(playerid, id_house);
		LinkVehicleToInterior(vehicleid, 0);

		SetPVarIntNew(playerid, "player_in_garage_house", 1);

		switch(House[id_house][house_garage_class])
		{
			case 2: SetVehiclePosEx(vehicleid, -335.9163,-831.3466,1201.7351,0.7018);
			case 3:	SetVehiclePosEx(vehicleid, -294.4487,-521.9686,1201.9314,355.6411);
			case 4:	SetVehiclePosEx(vehicleid, 878.7042,-444.5991,1201.9314,270.3010);
		}
	}
	else
		SendErr(playerid, "Вы не можете заехать в чужой гараж");
	return true;
}

stock get_house_garage_class_name(id_house)
{
	new 
		mes[60];

	if(House[id_house][house_garage_status] == 0)
	{
		mes = ""cLRED"Недоступно";
	}
	if(House[id_house][house_garage_class] == 1 && House[id_house][house_garage_status] == 1)
	{
		mes = ""cLRED"Не установлен";
	}
	if(House[id_house][house_garage_class] == 2 && House[id_house][house_garage_status] == 1)
	{
		mes = ""cGR"На 2 места";
	}
	if(House[id_house][house_garage_class] == 3 && House[id_house][house_garage_status] == 1)
	{
		mes = ""cGR"На 4 места";
	}
	if(House[id_house][house_garage_class] == 4 && House[id_house][house_garage_status] == 1)
	{
		mes = ""cGR"На 8 мест";
	}
	return mes;
}

stock show_house_info_big(playerid, id_house)
{

	static 
		h_class[24],
		h_owner[24];

	format(h_class, 24, "%s", get_house_class(id_house));

	if(House[id_house][house_owned] != -1)
	{
		GetPlayerNameByID(House[id_house][house_owned], House[id_house][house_owner]);
		format(h_owner, 24, House[id_house][house_owner]);
	}
	else
	{
		format(h_owner, 24, "Государство");	
	}


    format(String1024, sizeof(String1024), "\
    "cBLUE"- "cWH"Номер дома\t\t\t"cBLUE"%d\n\
    "cBLUE"- "cWH"Класс дома\t\t\t"cBLUE"%s\n\
    "cBLUE"- "cWH"Владелец\t\t\t"cBLUE"%s\n\
    "cBLUE"- "cWH"Двери\t\t\t%s\n\
    "cBLUE"- "cWH"Стоимость\t\t\t"cGR"%d рублей\n\
    "cBLUE"- "cWH"Налог на дом\t\t\t"cGR"%d рублей\n\
    "cWH"\n\
    "cBLUE"- "cWH"Шкаф\t\t\t\t%s\n\
    "cBLUE"- "cWH"Сейф\t\t\t\t%s\n\n\
    "cBLUE"- "cWH"Кол-во жильцов\t\t"cBLUE"%d человек\n\
    "cBLUE"- "cWH"Подселение жильцов\t%s\n\
    "cBLUE"- "cWH"Субсидии\t\t\t%s\n\
    "cBLUE"- "cWH"Гараж\t\t\t\t"cGR"%s\n",

    id_house+1,
    h_class,
    h_owner,
    (House[id_house][house_lock] == 1) ? (""cGR"Дверь открыта") : (""cLRED"Дверь закрыта"),
    House[id_house][house_price], 
    House[id_house][house_takings],
    (House[id_house][wardrobe_status]) ? (""cGR"Улучшение куплено") : (""cLRED"Улучшение не куплено"),
    get_house_seif(id_house),
    count_people_in_house(id_house), (House[id_house][house_status_people]) ? (""cGR"Улучшение куплено") : (""cLRED"Улучшение не куплено"),
    (House[id_house][house_subsidii_status]) ? (""cGR"Улучшение куплено") : (""cLRED"Улучшение не куплено"),
    get_house_garage_class_name(id_house));
    SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Информация о доме", String1024, !"Закрыть", ""); 


	return true;
}

stock sell_house_menu(playerid, id_house)
{


	return true;
}

stock count_people_in_house(id_house)
{
	new 
		all_house_people;

	if(House[id_house][house_people_1_id] != -1)
	{	
		all_house_people++;
	}
	if(House[id_house][house_people_2_id] != -1)
	{	
		all_house_people++;
	}
	if(House[id_house][house_people_3_id] != -1)
	{	
		all_house_people++;
	}
	if(House[id_house][house_people_4_id] != -1)
	{	
		all_house_people++;
	}

	return all_house_people;
}

stock menu_start_rent(playerid, id_house)
{
	if(House[id_house][house_owned] == pData[playerid][pMysqlID])
		return house_info(playerid, id_house);

	if(House[id_house][house_people_1_id] != -1 && House[id_house][house_people_2_id] != -1 && House[id_house][house_people_3_id] != -1 && House[id_house][house_people_4_id] != -1)
	{
		SendErr(playerid, "Все комнаты в доме заняты и аренда комнаты невозможна!");
		return house_info(playerid, id_house);
	}

	if(pData[playerid][pFlateRent] != -1)
		return SendErr(playerid, "Вы уже арендуете дом или квартиру!");
	if(pData[playerid][pFlate] != -1)
		return SendErr(playerid, "Вы уже владеете домом или квартирой!");	
	if(pData[playerid][pHouse] != -1)
		return SendErr(playerid, "Вы уже владеете домом или квартирой!");	
	if(pData[playerid][pHouseRent] != -1)
		return SendErr(playerid, "Вы уже владеете домом или квартирой!");	

	if(pData[playerid][pHotelRoom] != -1)
	{
		house_info(playerid, id_house);
		return SendErr(playerid, "Вы уже арендуете номер в отеле!");
	}

	new 
		fmt_str[550];

	format(fmt_str, 550, "\
	"cWH"На сколько дней Вы хотите снять комнату?\n\n\
	Максимальное кол-во дней аренды: 30 дней\n\
	Минимальное кол-во дней аренды: 3 дня\n\n\
	Текущая стоимость 1 дня: "cGR"%d"cWH" рублей\n\n\
	"cBLUE"Введите количество дней аренды:", House[id_house][house_people_price]);

	SPD(playerid, DIALOG_SELECT_DAY_RENT, DIALOG_STYLE_INPUT, !""cBLUE"Выбор кол-ва дней аренды", fmt_str, !"Далее", !"Назад");



	return true;
}

stock rent_comnat_house(playerid, id_house, day)
{
	if(House[id_house][house_owned] == pData[playerid][pMysqlID])
		return house_info(playerid, id_house);

	if(House[id_house][house_people_1_id] != -1 && House[id_house][house_people_2_id] != -1 && House[id_house][house_people_3_id] != -1 && House[id_house][house_people_4_id] != -1)
	{
		SendErr(playerid, "Все комнаты в доме заняты и аренда комнаты невозможна!");
		return house_info(playerid, id_house);
	}

	if(GetPlayerMoneyEx(playerid) < day*House[id_house][house_people_price]) 
	{
		//show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
		return SendErr(playerid,"У вас недостаточно денежных средств для аренды на такое количество дней!");	
	}

	new 
		final_money_price = day*House[id_house][house_people_price];

	new 
		fmt_str[200];

	new 
		owner_house_name[32];

	if(House[id_house][house_people_1_id] == -1)
	{
		House[id_house][house_people_1_id] = pData[playerid][pMysqlID];
		House[id_house][house_people_1_day] = day;

		pData[playerid][pHouseRent] = id_house;

		UpdatePlayerData(playerid,"house_rent", pData[playerid][pHouseRent]);


		GetPlayerNameByID(House[id_house][house_owned],owner_house_name);

		new 
			player_id = GetPlayerID(owner_house_name);


		if(IsPlayerConnected(player_id))
		{
			if(House[id_house][house_owned] == pData[player_id][pMysqlID] && player_id != playerid)
			{
				SFCM(player_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы получили "cGR"%d"cWH" рублей на банковский счёт за аренду комнаты "cBLUE"%s"cWH" на "cBLUE"%d"cWH" дней", final_money_price, pData[playerid][pNickname], day);	
				pData[player_id][pBank] += final_money_price;
			}
		}
		else
		{

			format(fmt_str, sizeof(fmt_str), "UPDATE `accounts` SET  `bank` = bank + %i WHERE `id` = '%i'" , final_money_price, House[id_house][house_owned]);
	  		sql_queryEx(zConn, fmt_str, QUERY_THREADED);
		}

		format(fmt_str, sizeof(fmt_str), "Аренда дома №: %d", House[id_house][house_id]);
		give_money(playerid, -final_money_price, fmt_str);

		save_house(pData[playerid][pHouseRent]);

		SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы успешно арендовали комнату в доме №%d на "cBLUE"%d"cWH" дней", id_house+1, day);	
		return true;
	}
	else if(House[id_house][house_people_2_id] == -1)
	{
		House[id_house][house_people_2_id] = pData[playerid][pMysqlID];
		House[id_house][house_people_2_day] = day;
		pData[playerid][pHouseRent] = id_house;

		UpdatePlayerData(playerid,"house_rent", pData[playerid][pHouseRent]);


		GetPlayerNameByID(House[id_house][house_owned],owner_house_name);

		new 
			player_id = GetPlayerID(owner_house_name);

		if(IsPlayerConnected(player_id))
		{
			if(House[id_house][house_owned] == pData[player_id][pMysqlID] && player_id != playerid)
			{
				SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы получили "cGR"%d"cWH" рублей на банковский счёт за аренду комнаты "cBLUE"%s"cWH" на "cBLUE"%d"cWH" дней", final_money_price, pData[playerid][pNickname], day);	
				pData[player_id][pBank] += final_money_price;
			}
		}
		else
		{

			format(fmt_str, sizeof(fmt_str), "UPDATE `accounts` SET  `bank` = bank + %i WHERE `id` = '%i'" , final_money_price, House[id_house][house_owned]);
	  		sql_queryEx(zConn, fmt_str, QUERY_THREADED);
		}

		format(fmt_str, sizeof(fmt_str), "Аренда дома №: %d", House[id_house][house_id]);
		give_money(playerid, -final_money_price, fmt_str);

		save_house(pData[playerid][pHouseRent]);

		SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы успешно арендовали комнату в доме №%d на "cBLUE"%d"cWH" дней", id_house+1, day);	
		return true;
	}
	else if(House[id_house][house_people_3_id] == -1)
	{
		House[id_house][house_people_3_id] = pData[playerid][pMysqlID];	
		House[id_house][house_people_3_day] = day;

		pData[playerid][pHouseRent] = id_house;

		UpdatePlayerData(playerid,"house_rent", pData[playerid][pHouseRent]);


		GetPlayerNameByID(House[id_house][house_owned],owner_house_name);

		new 
			player_id = GetPlayerID(owner_house_name);

		if(IsPlayerConnected(player_id))
		{
			if(House[id_house][house_owned] == pData[player_id][pMysqlID] && player_id != playerid)
			{
				SFCM(player_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы получили "cGR"%d"cWH" рублей на банковский счёт за аренду комнаты "cBLUE"%s"cWH" на "cBLUE"%d"cWH" дней", final_money_price, pData[playerid][pNickname], day);	
				pData[player_id][pBank] += final_money_price;
			}
		}
		else
		{

			format(fmt_str, sizeof(fmt_str), "UPDATE `accounts` SET  `bank` = bank + %i WHERE `id` = '%i'" , final_money_price, House[id_house][house_owned]);
	  		sql_queryEx(zConn, fmt_str, QUERY_THREADED);
		}

		format(fmt_str, sizeof(fmt_str), "Аренда дома №: %d", House[id_house][house_id]);
		give_money(playerid, -final_money_price, fmt_str);

		save_house(pData[playerid][pHouseRent]);

		SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы успешно арендовали комнату в доме №%d на "cBLUE"%d"cWH" дней", id_house+1, day);	
		return true;
	}
	else if(House[id_house][house_people_4_id] == -1)
	{
		House[id_house][house_people_4_id] = pData[playerid][pMysqlID];
		House[id_house][house_people_4_day] = day;

		pData[playerid][pHouseRent] = id_house;

		UpdatePlayerData(playerid,"house_rent", pData[playerid][pHouseRent]);

		GetPlayerNameByID(House[id_house][house_owned],owner_house_name);

		new 
			player_id = GetPlayerID(owner_house_name);


		if(IsPlayerConnected(player_id))
		{
			if(House[id_house][house_owned] == pData[player_id][pMysqlID] && player_id != playerid)
			{
				SFCM(player_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы получили "cGR"%d"cWH" рублей на банковский счёт за аренду комнаты "cBLUE"%s"cWH" на "cBLUE"%d"cWH" дней", final_money_price, pData[playerid][pNickname], day);	
				pData[player_id][pBank] += final_money_price;
			}
		}
		else
		{

			format(fmt_str, sizeof(fmt_str), "UPDATE `accounts` SET  `bank` = bank + %i WHERE `id` = '%i'" , final_money_price, House[id_house][house_owned]);
	  		sql_queryEx(zConn, fmt_str, QUERY_THREADED);
		}

		format(fmt_str, sizeof(fmt_str), "Аренда дома №: %d", House[id_house][house_id]);
		give_money(playerid, -final_money_price, fmt_str);

		save_house(pData[playerid][pHouseRent]);

		SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы успешно арендовали комнату в доме №%d на "cBLUE"%d"cWH" дней", id_house+1, day);	
		return true;
	}
	

	return true;
}


stock buy_update_house(playerid, id_house, type)
{

	switch(type)
	{
		case 1:
		{
			pTemp[playerid][offer_time] = 25;

			if(GetPlayerMoneyEx(playerid) < PRICE_BUY_SHKAF_HOUSE) 
			{
				//show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
				pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
				menu_update_house(playerid, id_house);
				return SendErr(playerid,"У вас недостаточно денег для покупки улучшения!");			
			}
			if(House[id_house][wardrobe_status] == 1)
			{
				pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
				menu_update_house(playerid, id_house);
				return SendErr(playerid,"У вас уже куплено данное улучшение!");			
			}				

			House[id_house][wardrobe_status] = 1;

			SendSucc(playerid, "Вы успешно приобрели 'Личный шкаф' в свой дом!");	

		 	format(String144, sizeof(String144), "Покупка шкафа в дом №%d", id_house);
			give_money(playerid,  -PRICE_BUY_SHKAF_HOUSE, String144);

			pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;

			menu_update_house(playerid, id_house);
		}
		case 2:
		{
			pTemp[playerid][offer_time] = 25;

			if(GetPlayerMoneyEx(playerid) < PRICE_BUY_SEIF_ONE) 
			{
				//show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
				pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
				menu_update_house(playerid, id_house);
				return SendErr(playerid,"У вас недостаточно денег для покупки улучшения!");			
			}
			if(House[id_house][safe_house_status] == 3)
			{
				pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
				menu_update_house(playerid, id_house);
				return SendErr(playerid,"У вас уже куплен самый большой сейф!");			
			}				


			if(House[id_house][safe_house_status] == 0)
			{
				SendSucc(playerid, "Вы успешно приобрели 'Новый маленький сейф' в свой дом!");	
				House[id_house][safe_house_status] = 1;
			}
			else if(House[id_house][safe_house_status] == 1)
			{
				SendSucc(playerid, "Вы успешно приобрели 'Новый средний сейф' в свой дом!");	
				House[id_house][safe_house_status] = 2;
			}
			else if(House[id_house][safe_house_status] == 2)
			{
				SendSucc(playerid, "Вы успешно приобрели 'Новый большой сейф' в свой дом!");	
				House[id_house][safe_house_status] = 3;
			}

			SendInf(playerid, "Стандартный пароль сейфа - 1111");

		 	format(String144, sizeof(String144), "Покупка сейфа в дом №%d", id_house);
			give_money(playerid,  -PRICE_BUY_SEIF_ONE, String144);


			pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;

			menu_update_house(playerid, id_house);
		}
		case 3:
		{
			pTemp[playerid][offer_time] = 25;

			if(GetPlayerMoneyEx(playerid) < PRICE_BUY_PEOPLE) 
			{
				//show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
				pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
				menu_update_house(playerid, id_house);
				return SendErr(playerid,"У вас недостаточно денег для покупки улучшения!");			
			}
			if(House[id_house][house_status_people] == 1)
			{
				pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
				menu_update_house(playerid, id_house);
				return SendErr(playerid,"У вас уже куплено улучшение по подселению жильцов");			
			}				


			SendSucc(playerid, "Вы успешно приобрели 'Возможность подселения' в свой дом!");	
			House[id_house][house_status_people] = 1;

		 	format(String144, sizeof(String144), "Покупка возможности подселения в дом №%d", id_house);
			give_money(playerid,  -PRICE_BUY_PEOPLE, String144);


			pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;

			menu_update_house(playerid, id_house);
		}
		case 4:
		{
			pTemp[playerid][offer_time] = 25;

			if(GetPlayerMoneyEx(playerid) < PRICE_BUY_SUBSIDII) 
			{
				//show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
				pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
				menu_update_house(playerid, id_house);
				return SendErr(playerid,"У вас недостаточно денег для покупки улучшения!");			
			}
			if(House[id_house][house_subsidii_status] == 1)
			{
				pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
				menu_update_house(playerid, id_house);
				return SendErr(playerid,"У вас уже куплено улучшение по уменьшению налогов!");			
			}				


			SendSucc(playerid, "Вы успешно приобрели 'Уменьшение налогов' для своего дома!");	
			House[id_house][house_subsidii_status] = 1;

		 	format(String144, sizeof(String144), "Покупка уменьших налогов в дом в дом №%d", id_house);
			give_money(playerid,  -PRICE_BUY_SUBSIDII, String144);

			pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
 
			menu_update_house(playerid, id_house);
		}
		case 5:
		{
			pTemp[playerid][offer_time] = 25;

			if(House[id_house][house_garage_status] == 0)
				return SendErr(playerid, "В ваш дом невозможно установить гараж");

			if(House[id_house][house_garage_class] == 4)
				return SendErr(playerid, "В вашем доме установлен гараж максимального класса");

			if(GetPlayerMoneyEx(playerid) < get_house_garage_cost(id_house)) 
			{
				//show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
				pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
				menu_update_house(playerid, id_house);
				return SendErr(playerid,"У вас недостаточно денег для покупки улучшения!");			
			} 

			give_money(playerid, -get_house_garage_cost(id_house), "Покупка улучшения гаража для дома");

			House[id_house][house_garage_class] ++;

			format(String144, sizeof(String144), "Вы %s гараж для дома. '%s'", House[id_house][house_garage_class] == 2 ? ("купили") : ("улучшили"), get_house_garage_class_name(id_house));
			SendSucc(playerid, String144);
			save_house(id_house);

			if(House[id_house][house_garage_class] == 2)
			{
				create_dynamic_area(House[id_house][house_park_garage_x], House[id_house][house_park_garage_y], House[id_house][house_park_garage_z], -1, id_house, H_G_ENTER, 5.0);

				create_circle_pickup_o(House[id_house][house_park_garage_x], House[id_house][house_park_garage_y], House[id_house][house_park_garage_z], TRIGGER_BLUE);

				garage_text_house[id_house] = CreateDynamic3DTextLabel(""cWH"Гараж дома\n\
					"cWH"Чтобы заехать нажмите "cBLUE"[ГУДОК]\n\
					"cWH"Чтобы зайти нажмите "cBLUE"[ALT]",-1, \
				House[id_house][house_park_garage_x], House[id_house][house_park_garage_y], House[id_house][house_park_garage_z]+1.0, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
			}

			switch(House[id_house][house_garage_class])
			{
				case 1: vehicle_player_max_user[playerid] = 2;
				case 2: vehicle_player_max_user[playerid] = 4;
				case 4: vehicle_player_max_user[playerid] = 8;
				default: vehicle_player_max_user[playerid] = 1;
			}	
		}
	}

	save_house(id_house);
	return true;
}

stock dialog_all_house(playerid, dialogid, response, listitem, inputtext[])
{

	switch(dialogid)
	{
		case DIALOG_CHANGE_PRICE_PEOPLE:
		{
			new 
				id_house = pData[playerid][pHouse];

			if(debug_mode) FormattedMessage(playerid, -1, "[debug] dialog price rent house: %d", id_house);

			if(!response)
				return true;

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверную стоимость!");
				return manage_people_house_p(playerid, id_house);
			}

			new 
				count_money = strval(inputtext);


			if(count_money < 500 || count_money > 15000)
			{
			    SendErr(playerid,"От 500 до 15000 рублей за 1 сутки проживания!");
				return manage_people_house_p(playerid, id_house);
			}	

			House[id_house][house_people_price] = count_money;

			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Новая цена 1 дня аренды комнаты - "cGR"%d"cWH" рублей", count_money);	

			manage_general_menu(playerid, id_house);

		}
		case DIALOG_SELECT_DAY_RENT:
		{
			new 
				id_house;

			if(!id_house)
			{
				id_house = pTemp[playerid][area_item_id];
			}
			else
			{
				id_house = GetPVarIntNew(playerid, "house_id_enter_p");
			}

			if(debug_mode) FormattedMessage(playerid, -1, "[debug] dialog select day rent house: %d", id_house);

			if(!response)
				return house_info(playerid, id_house);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное количество дней!");
				return house_info(playerid, id_house);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное количество дней!");
				return house_info(playerid, id_house);	
			}

			new 
				count_money = strval(inputtext);


			if(count_money < 3 || count_money > 30)
			{
			    SendErr(playerid,"От 3 до 30 дней!");
				return house_info(playerid, id_house);
			}	

			if(GetPlayerMoneyEx(playerid) < count_money*House[house_id][house_people_price]) 
			{
				//show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
				return SendErr(playerid,"У вас недостаточно денежных средств для аренды на такое количество дней!");	
			}

			rent_comnat_house(playerid, id_house, count_money);

		}
		case DIALOG_CHANGE_MANAGE_MENU:
		{

			new 
				id_house = pData[playerid][pHouse];

			if(debug_mode) FormattedMessage(playerid, -1, "[debug] dialog show manage rent house: %d", id_house);

			if(!response)
				return house_panel_change_cmd(playerid, id_house);	


			switch(listitem)
			{
				case 0: return manage_people_house_p(playerid, id_house);
				case 1: return manage_people_house(playerid, id_house);
				case 2:
				{
					if(House[id_house][house_people_status] == 1)
					{
						House[id_house][house_people_status] = 0;
						SendSucc(playerid, "Вы запретили возможность подселения жильцов в Ваш дом!");
						SendInf(playerid, "Жильцы, которые уже снимают комнату в доме, доживут арендованные дни!");


						return house_panel_change(playerid, id_house);	
					}
					else
					{
						House[id_house][house_people_status] = 1;
						SendSucc(playerid, "Вы разрешили возможность подселения жильцов в Ваш дом!");	

						return house_panel_change(playerid, id_house);					
					}
				}
			
			}			
		}
		case SHOW_CHANGE_MENU_HOUSE_PEOP_ALL:
		{
			new 
				id_house = pData[playerid][pHouse];

			if(!response)
				return house_panel_change_cmd(playerid, id_house);

			house_panel_change_cmd(playerid, id_house);			
		}
		case SHOW_CHANGE_MENU_HOUSE_1:
		{
			if(!response)
				return true;	

			new 
				id_house;

			if(pData[playerid][pHouse] != -1 && pData[playerid][pHouseRent] == -1)
			{
				id_house = pData[playerid][pHouse];
			}
			else if(pData[playerid][pHouse] == -1 && pData[playerid][pHouseRent] != -1)
			{
				id_house = pData[playerid][pHouseRent];
			}

			if(debug_mode) FormattedMessage(playerid, -1, "[debug] dialog change menu house: %d", id_house);


			switch(listitem)
			{
				case 0: return show_house_info_big(playerid, id_house);
				case 1: return update_lock_house(playerid, id_house);
				case 2: return menu_update_house(playerid, id_house);
				case 3: return sell_house_accept(playerid);
				case 5: return exit_house(playerid, GetPlayerVirtualWorld(playerid));
			
			}

		}

		case DIALOG_ACCEPT_SELL_HOUSE:
		{
			new 
				id_house = pData[playerid][pHouse];

			if(!response)
				return house_panel_change(playerid, id_house);	

			sell_house(playerid, id_house);			
		}

		case SHOW_CHANGE_MENU_HOUSE_2:
		{
			if(!response)
				return true;	

			new 
				id_house = pData[playerid][pHouse];

			if(debug_mode) FormattedMessage(playerid, -1, "[debug] menu house id house: %d", id_house);

			switch(listitem)
			{
				case 0: return show_house_info_big(playerid, id_house);
				case 1: return update_lock_house(playerid, id_house);
				case 2: return menu_update_house(playerid, id_house);
				case 3: return sell_house_accept(playerid);
				case 4: return manage_general_menu(playerid, id_house);
				case 6: return exit_house(playerid, GetPlayerVirtualWorld(playerid));
			
			}

		}

		case SHOW_CHANGE_MENU_HOUSE_3:
		{
			if(!response)
				return true;	

			new 
				id_house;

			id_house = GetPlayerVirtualWorld(playerid);
	

			if(debug_mode) FormattedMessage(playerid, -1, "[debug] menu house id house: %d", id_house);

			switch(listitem)
			{
				case 0: return show_house_info_big(playerid, id_house);
				case 2: return exit_house(playerid, GetPlayerVirtualWorld(playerid));
			
			}			
		}
		case SHOW_CHANGE_MENU_HOUSE_4:
		{
			if(!response)
				return true;	

			new 
				id_house;

			if(pData[playerid][pHouse] != -1 && pData[playerid][pHouseRent] == -1)
			{
				id_house = pData[playerid][pHouse];
			}
			else if(pData[playerid][pHouse] == -1 && pData[playerid][pHouseRent] != -1)
			{
				id_house = pData[playerid][pHouseRent];
			}

			if(debug_mode) FormattedMessage(playerid, -1, "[debug] menu house id house: %d", id_house);

			switch(listitem)
			{
				case 0: return show_house_info_big(playerid, id_house);
				case 1: return show_menu_rent_house(playerid, id_house);
				case 3: return exit_house(playerid, GetPlayerVirtualWorld(playerid));
			
			}			
		} 

		case SHOW_CHANGE_MENU_HOUSE_UPGRADE:
		{
			new 
				id_house = pData[playerid][pHouse];

			if(!response)
				return house_panel_change_cmd(playerid, id_house);	


			if(debug_mode) FormattedMessage(playerid, -1, "[debug] menu house upgrade id: %d", id_house);

			switch(listitem)
			{
				case 0: return buy_update_house(playerid, id_house, 1);
				case 1: return buy_update_house(playerid, id_house, 2);
				case 2: return buy_update_house(playerid, id_house, 3);
				case 3: return buy_update_house(playerid, id_house, 4);
				case 4: return buy_update_house(playerid, id_house, 5);
			
			}

		}
		case DIALOG_BUY_HOUSE:
		{
			if(!response)
				return true;	

			new 
				id_house = pTemp[playerid][area_item_id];

			if(debug_mode) FormattedMessage(playerid, -1, "[debug] menu buy house id: %d", id_house);

			buy_house(playerid, id_house);	
		}
		case DIALOG_INFO_HOUSE:
		{
			if(!response)
				return true;	

			new 
				id_house;


			id_house = pTemp[playerid][area_item_id];


			if(House[id_house][house_lock] == 2 && pData[playerid][pHouse] != id_house)
			{
				GameTextForPlayer(playerid, "~r~closed", 2000, 3);
				house_info(playerid, id_house);
				return SendInf(playerid, "Двери дома - закрыты. Вы не можете войти!");
			}
			if(House[id_house][house_lock] == 2 && pData[playerid][pHouse] == id_house)
			{
				return enter_house(playerid, id_house);
			}

			enter_house(playerid, id_house);
		}
		case DIALOG_INFO_RENT_HOUSE:
		{
			if(!response)
				return true;
			new 
				id_house;

			if(!id_house)
			{
				id_house = pTemp[playerid][area_item_id];
			}
			else
			{
				id_house = GetPVarIntNew(playerid, "house_id_enter_p");
			}

			if(debug_mode) FormattedMessage(playerid, -1, "[debug] dialog info in the rent people: %d", id_house);	

			switch(listitem)
			{
				case 0: return house_info(playerid, id_house);
				case 1: return house_info(playerid, id_house);
				case 2: return house_info(playerid, id_house);
				case 3: return house_info(playerid, id_house);
				case 4: return house_info(playerid, id_house);
				case 5: return house_info(playerid, id_house);
				case 6: return house_info(playerid, id_house);
				case 7: return menu_start_rent(playerid, id_house);
				case 8: return house_info(playerid, id_house);
				case 9: return enter_house(playerid, id_house);
			
			}
		}
		case DIALOG_RENT_HOUSE_P:
		{
			new 
				id_house; 

			if(pData[playerid][pHouse] == -1 && pData[playerid][pHouseRent] != -1)
			{
				id_house = pData[playerid][pHouseRent];
			}


			if(!response)
				return house_panel_change_cmd(playerid, id_house);	

			switch(listitem)
			{
				case 0: return show_menu_rent_house(playerid, id_house);
				case 1: return countinue_rent_house(playerid, id_house);
				case 2: return final_rent_house(playerid, id_house);
			
			}						
		}
		case DIALOG_CONTINUT_RENT_HOUSE:
		{
			new 
				id_house; 

			if(pData[playerid][pHouse] == -1 && pData[playerid][pHouseRent] != -1)
			{
				id_house = pData[playerid][pHouseRent];
			}


			if(!response)
				return show_menu_rent_house(playerid, id_house);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное количество дней!");
				return show_menu_rent_house(playerid, id_house);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное количество дней!");
				return show_menu_rent_house(playerid, id_house);		
			}

			new 
				count_day = strval(inputtext);

			new 
				max_day = GetPVarIntNew(playerid, "final_max_day_rent");

			if(count_day < 1 || count_day > max_day)
			{
			    SendErr(playerid,"Неверное кол-во дней!");
				return show_menu_rent_house(playerid, id_house);
			}	

			if(GetPlayerMoneyEx(playerid) < count_day*House[house_id][house_people_price]) 
			{
				//show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
				show_menu_rent_house(playerid, id_house);
				return SendErr(playerid,"У вас недостаточно денежных средств для продления аренды на такое количество дней!");	
			}

			final_continue_rent_p(playerid, id_house, count_day);

		}
		case DIALOG_END_RENT_HOUSE:
		{	
			new 
				id_house; 

			if(pData[playerid][pHouse] == -1 && pData[playerid][pHouseRent] != -1)
			{
				id_house = pData[playerid][pHouseRent];
			}

			if(!response)
				return show_menu_rent_house(playerid, id_house);

			cancel_rent_house_p(playerid, id_house);			
		}

	}
	return true;
}

stock buy_house(playerid, h)
{

	if(pData[playerid][pHouse] != -1)
		return SendErr(playerid, "Вы не можете купить дом, так как у Вас уж есть дом!");

	if(pData[playerid][pHouseRent] != -1 || pData[playerid][pFlateRent] != -1)
		return SendErr(playerid, "Вы уже арендуете дом или квартиру! Откажитесь от аренды для покупки!");

	if(pData[playerid][pFlate] != -1)
		return SendErr(playerid, "Вы уже владете квартирой!");	

	if(pData[playerid][pHotelRoom] != -1)
		return SendErr(playerid, "Вы уже арендуете номер в отеле!");

	if(pData[playerid][pGarage] != -1)
		return SendErr(playerid, "Вы уже владеете гаражом!");

	if(House[h][house_sell_status] == 3)
		return SendErr(playerid, "Дом недоступен для покупи в данный момент, так как он опечатан!");

	if(House[h][house_owned] != -1)
		return SendErr(playerid, "Дом недоступен для покупи в данный момент");

	if(GetPlayerMoneyEx(playerid) < House[h][house_price]) 
	{
		//show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
		return SendErr(playerid,"У вас недостаточно денежных средств для покупки дома!");	
	}

	//show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_buy_house", 4000);

	House[h][house_owned] = pData[playerid][pMysqlID];
	format(House[h][house_owner], 24, pData[playerid][pNickname]);
	House[h][house_days] = 3;

	pData[playerid][pHouse] = h;

	if(debug_mode) FormattedMessage(playerid, -1, "[debug] house buy: %d | house_owner_sql: %d ", h, House[h][house_owned]);

	UpdatePlayerData(playerid,"house",pData[playerid][pHouse]);	

 	format(String144, sizeof(String144), "Покупка частного дома №%d", h);
	give_money(playerid, -House[h][house_price], String144);

	save_house(h);
	update_house_pickup(h);

	format(String512, sizeof(String512), "\
		"cWH"Поздравляем Вас с приобретением частного дома!\n\n\
		Вы купили дом "cBLUE"№%d\n\
		"cWH"Ежедневная оплата: "cGR"%d"cWH" рублей\n\n\
		"cWH"Доп оплачен на "cBLUE"%d"cWH" дней\n\
		Советутем Вам посетить банк для оплаты!",
		pData[playerid][pHouse],
		House[h][house_takings], House[h][house_days]);
	return SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Частный дом", String512, !"Понял", !"");
}


alias:home("hmenu", "house", "рщгы", "рщьу");
CMD:home(playerid)
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

	new 
		h = -1;

	if(pData[playerid][pHouse] != -1 && pData[playerid][pHouseRent] == -1)
	{
		h = pData[playerid][pHouse];
	}
	else if(pData[playerid][pHouse] == -1 && pData[playerid][pHouseRent] != -1)
	{
		h = pData[playerid][pHouseRent];
	}

	if(h == -1)
		return SendErr(playerid, "У вас нет дома или квартиры для использования данной команды!");


	return house_panel_change_cmd(playerid, h);
}


CMD:addapart(playerid)
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

	static 
		formate_str[310];


    format(formate_str, 310, "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('%f','%f','%f','%f','%f','%f','%d','%d','%d','%d')",
    499.5122,-368.5431,1201.9318,499.5122,-368.5431,1201.9318, 5, 6500000, 5000, 30);
    sql_queryEx(zConn, formate_str, QUERY_THREADED);

    format(formate_str, 310, "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('%f','%f','%f','%f','%f','%f','%d','%d','%d','%d')",
    499.5121,-371.7499,1201.9318,499.5121,-371.7499,1201.9318, 5, 6500000, 5000, 30);
    sql_queryEx(zConn, formate_str, QUERY_THREADED);	

    format(formate_str, 310, "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('%f','%f','%f','%f','%f','%f','%d','%d','%d','%d')",
    499.5125,-376.5361,1201.9318,499.5125,-376.5361,1201.9318, 5, 6500000, 5000, 30);
    sql_queryEx(zConn, formate_str, QUERY_THREADED);	

    format(formate_str, 310, "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('%f','%f','%f','%f','%f','%f','%d','%d','%d','%d')",
    499.5122,-379.7667,1201.9318,499.5122,-379.7667,1201.9318, 5, 6500000, 5000, 30);
    sql_queryEx(zConn, formate_str, QUERY_THREADED);	


    format(formate_str, 310, "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('%f','%f','%f','%f','%f','%f','%d','%d','%d','%d')",
    499.5122,-368.5431,1201.9318,499.5122,-368.5431,1201.9318, 6, 8500000, 7500, 40);
    sql_queryEx(zConn, formate_str, QUERY_THREADED);

    format(formate_str, 310, "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('%f','%f','%f','%f','%f','%f','%d','%d','%d','%d')",
    499.5121,-371.7499,1201.9318,499.5121,-371.7499,1201.9318, 6, 8500000, 7500, 40);
    sql_queryEx(zConn, formate_str, QUERY_THREADED);	

    format(formate_str, 310, "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('%f','%f','%f','%f','%f','%f','%d','%d','%d','%d')",
    499.5125,-376.5361,1201.9318,499.5125,-376.5361,1201.9318, 6, 8500000, 7500, 40);
    sql_queryEx(zConn, formate_str, QUERY_THREADED);	

    format(formate_str, 310, "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('%f','%f','%f','%f','%f','%f','%d','%d','%d','%d')",
    499.5122,-379.7667,1201.9318,499.5122,-379.7667,1201.9318, 6, 8500000, 7500, 40);
    sql_queryEx(zConn, formate_str, QUERY_THREADED);	


	return true;
}

CMD:house_go(playerid)
{
	if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

	new 
		string[1024];

	
	format(string, sizeof(string), "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('-251.729583','-1427.975708','41.948436','-251.729583','-1427.975708','41.948436','7','3000000','2500','0')");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('-221.411941','-1466.151855','42.049999','-221.411941','-1466.151855','42.049999','7','3000000','2500','0')");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('-146.521743','-1446.729858','43.299999','-146.521743','-1446.729858','43.299999','7','3000000','2500','0')");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('-183.537612','-1516.254760','43.299999','-183.537612','-1516.254760','43.299999','7','3000000','2500','0')");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('-127.770133','-1514.434448','41.948436','-127.770133','-1514.434448','41.948436','7','3000000','2500','0')");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('-151.578201','-1582.758666','42.049999','-151.578201','-1582.758666','42.049999','7','3000000','2500','0')");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('-243.178939','-1588.947143','41.948436','-243.178939','-1588.947143','41.948436','7','3000000','2500','0')");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('-295.601684','-1565.999511','42.049999','-295.601684','-1565.999511','42.049999','7','3000000','2500','0')");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('-355.104644','-1531.373046','43.299999','-355.104644','-1531.373046','43.299999','7','3000000','2500','0')");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('-396.123382','-1594.698242','42.049999','-396.123382','-1594.698242','42.049999','7','3000000','2500','0')");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('-340.179107','-1641.377075','41.948436','-340.179107','-1641.377075','41.948436','7','3000000','2500','0')");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('-296.715179','-1671.194335','43.299999','-296.715179','-1671.194335','43.299999','7','3000000','2500','0')");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('-174.741943','-1628.384399','42.049999','-174.741943','-1628.384399','42.049999','7','3000000','2500','0')");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('-124.693046','-1675.591796','41.948436','-124.693046','-1675.591796','41.948436','7','3000000','2500','0')");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('-233.281066','-1691.815429','43.299999','-233.281066','-1691.815429','43.299999','7','3000000','2500','0')");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('-327.948516','-1742.027099','43.299999','-327.948516','-1742.027099','43.299999','7','3000000','2500','0')");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('-379.477172','-1715.000732','41.948436','-379.477172','-1715.000732','41.948436','7','3000000','2500','0')");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('-441.492736','-1692.874389','42.049999','-441.492736','-1692.874389','42.049999','7','3000000','2500','0')");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('-465.000030','-1748.521606','41.948436','-465.000030','-1748.521606','41.948436','7','3000000','2500','0')");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('-392.544830','-1767.967407','42.049999','-392.544830','-1767.967407','42.049999','7','3000000','2500','0')");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('-427.844146','-1819.718872','43.299999','-427.844146','-1819.718872','43.299999','7','3000000','2500','0')");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('-456.488861','-1880.231567','41.948436','-456.488861','-1880.231567','41.948436','7','3000000','2500','0')");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('-512.088745','-1828.294433','43.299999','-512.088745','-1828.294433','43.299999','7','3000000','2500','0')");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('-414.716918','-1964.269165','43.299999','-414.716918','-1964.269165','43.299999','7','3000000','2500','0')");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('-359.813903','-2011.212524','41.948436','-359.813903','-2011.212524','41.948436','7','3000000','2500','0')");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('-301.111541','-2000.512084','42.049999','-301.111541','-2000.512084','42.049999','7','3000000','2500','0')");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('-237.470001','-1966.773193','43.299999','-237.470001','-1966.773193','43.299999','7','3000000','2500','0')");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('-298.225738','-1922.459106','43.299999','-298.225738','-1922.459106','43.299999','7','3000000','2500','0')");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('-262.683837','-1877.457397','42.049999','-262.683837','-1877.457397','42.049999','7','3000000','2500','0')");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('-213.124740','-1829.030639','41.948436','-213.124740','-1829.030639','41.948436','7','3000000','2500','0')");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('-169.557434','-1905.450805','41.948436','-169.557434','-1905.450805','41.948436','7','3000000','2500','0')");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('-136.825332','-1845.839843','41.948436','-136.825332','-1845.839843','41.948436','7','3000000','2500','0')");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('-125.457305','-1787.147705','43.299999','-125.457305','-1787.147705','43.299999','7','3000000','2500','0')");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('-201.141113','-1756.615844','42.049999','-201.141113','-1756.615844','42.049999','7','3000000','2500','0')");
	sql_queryEx(zConn, string, QUERY_THREADED);

	SendSucc(playerid, "Дома импортированы");
	return true;
}
CMD:garage_go(playerid)
{
	if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

	new 
		string[1024];

	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '36'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '2316.040527',house_park_garage_y = '-203.904022',house_park_garage_z = '2.167500',house_park_garage_a = '185.542282'WHERE house_id = '36'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '2316.173095',house_park_y = '-207.992736',house_park_z = '1.956029',house_park_a = '181.709899'WHERE house_id = '36'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '38'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '2216.902099',house_park_garage_y = '-202.556900',house_park_garage_z = '2.122683',house_park_garage_a = '180.698577'WHERE house_id = '38'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '2218.128417',house_park_y = '-207.843627',house_park_z = '1.884069',house_park_a = '181.340438'WHERE house_id = '38'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '42'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '796.662536',house_park_garage_y = '-1362.229248',house_park_garage_z = '40.711311',house_park_garage_a = '342.138977'WHERE house_id = '42'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '798.110290',house_park_y = '-1357.234497',house_park_z = '40.401695',house_park_a = '342.902648'WHERE house_id = '42'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '53'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '704.554748',house_park_garage_y = '-1304.251953',house_park_garage_z = '40.730113',house_park_garage_a = '157.731842'WHERE house_id = '53'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '703.484619',house_park_y = '-1308.599487',house_park_z = '40.467319',house_park_a = '166.956436'WHERE house_id = '53'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '67'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '1094.605590',house_park_garage_y = '2650.485839',house_park_garage_z = '12.221003',house_park_garage_a = '213.678787'WHERE house_id = '67'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '1096.991455',house_park_y = '2646.639404',house_park_z = '11.907533',house_park_a = '211.745819'WHERE house_id = '67'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '1090.166503',house_park_garage_y = '2579.570800',house_park_garage_z = '12.148437',house_park_garage_a = '36.287036'WHERE house_id = '68'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '68'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '1087.949707',house_park_y = '2582.953125',house_park_z = '11.917569',house_park_a = '31.828649'WHERE house_id = '68'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '69'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '1040.000366',house_park_garage_y = '2623.648437',house_park_garage_z = '12.250000',house_park_garage_a = '213.952133'WHERE house_id = '69'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '1042.054077',house_park_y = '2620.460937',house_park_z = '12.013612',house_park_a = '213.048965'WHERE house_id = '69'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '1047.193847',house_park_garage_y = '2485.377929',house_park_garage_z = '12.250000',house_park_garage_a = '33.490127'WHERE house_id = '70'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '70'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '1045.250000',house_park_y = '2488.591308',house_park_z = '12.015176',house_park_a = '31.647680'WHERE house_id = '70'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '936.158935',house_park_garage_y = '2486.545166',house_park_garage_z = '12.238300',house_park_garage_a = '29.055658'WHERE house_id = '71'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '71'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '934.167541',house_park_y = '2489.760742',house_park_z = '11.990820',house_park_a = '32.911193'WHERE house_id = '71'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '72'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '906.265563',house_park_garage_y = '2536.616943',house_park_garage_z = '12.224813',house_park_garage_a = '210.647094'WHERE house_id = '72'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '908.520629',house_park_y = '2532.797119',house_park_z = '11.911953',house_park_a = '210.034851'WHERE house_id = '72'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '818.778503',house_park_y = '2488.046875',house_park_z = '11.980443',house_park_a = '210.864913'WHERE house_id = '73'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '73'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '816.648559',house_park_garage_y = '2491.787841',house_park_garage_z = '12.237216',house_park_garage_a = '209.208724'WHERE house_id = '73'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '833.362487',house_park_y = '2424.459716',house_park_z = '12.023582',house_park_a = '31.849182'WHERE house_id = '74'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '835.068664',house_park_garage_y = '2421.602294',house_park_garage_z = '12.250000',house_park_garage_a = '31.674945'WHERE house_id = '74'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '74'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '782.682617',house_park_y = '2376.254394',house_park_z = '11.990381',house_park_a = '122.263786'WHERE house_id = '75'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '75'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '785.893554',house_park_garage_y = '2378.309814',house_park_garage_z = '12.237935',house_park_garage_a = '128.962142'WHERE house_id = '75'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '830.895141',house_park_y = '2282.625244',house_park_z = '11.930796',house_park_a = '120.959625'WHERE house_id = '76'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '833.909240',house_park_garage_y = '2284.512939',house_park_garage_z = '12.233129',house_park_garage_a = '120.066581'WHERE house_id = '76'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '76'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '905.867736',house_park_y = '2311.473144',house_park_z = '12.024163',house_park_a = '209.300643'WHERE house_id = '77'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '77'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '904.381225',house_park_garage_y = '2314.251464',house_park_garage_z = '12.250000',house_park_garage_a = '209.502517'WHERE house_id = '77'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '989.086120',house_park_y = '2297.650390',house_park_z = '11.933809',house_park_a = '145.704071'WHERE house_id = '78'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '991.055725',house_park_garage_y = '2300.736816',house_park_garage_z = '12.241515',house_park_garage_a = '152.390625'WHERE house_id = '78'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '78'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '1078.395263',house_park_y = '2283.681640',house_park_z = '11.916582',house_park_a = '236.057220'WHERE house_id = '79'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '79'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '1075.070068',house_park_garage_y = '2285.946289',house_park_garage_z = '12.148437',house_park_garage_a = '236.577514'WHERE house_id = '79'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '1124.206176',house_park_garage_y = '2258.723876',house_park_garage_z = '12.148437',house_park_garage_a = '60.682315'WHERE house_id = '80'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '80'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '1121.576538',house_park_y = '2260.333251',house_park_z = '11.932007',house_park_a = '59.241683'WHERE house_id = '80'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '1124.833374',house_park_y = '2349.019042',house_park_z = '11.935508',house_park_a = '236.122665'WHERE house_id = '81'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '1122.137329',house_park_garage_y = '2350.780029',house_park_garage_z = '12.236360',house_park_garage_a = '237.116638'WHERE house_id = '81'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '81'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '1168.185424',house_park_y = '2313.166992',house_park_z = '12.024139',house_park_a = '56.255104'WHERE house_id = '82'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '1170.779541',house_park_garage_y = '2311.386474',house_park_garage_z = '12.250000',house_park_garage_a = '56.779846'WHERE house_id = '82'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '82'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '1162.353271',house_park_y = '2407.952148',house_park_z = '11.924110',house_park_a = '235.719635'WHERE house_id = '83'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '83'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '1159.344482',house_park_garage_y = '2410.106445',house_park_garage_z = '12.148437',house_park_garage_a = '237.856475'WHERE house_id = '83'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '1210.617309',house_park_y = '2381.001953',house_park_z = '12.011543',house_park_a = '56.947853'WHERE house_id = '84'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '84'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '1213.229370',house_park_garage_y = '2379.312500',house_park_garage_z = '12.248558',house_park_garage_a = '57.502166'WHERE house_id = '84'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '1196.138305',house_park_y = '2451.625000',house_park_z = '11.914556',house_park_a = '235.621185'WHERE house_id = '85'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '1192.353149',house_park_garage_y = '2454.147949',house_park_garage_z = '12.236690',house_park_garage_a = '238.644149'WHERE house_id = '85'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '85'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '86'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '1359.698242',house_park_garage_y = '2363.666992',house_park_garage_z = '12.227310',house_park_garage_a = '125.338897'WHERE house_id = '86'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '1356.229614',house_park_y = '2361.300048',house_park_z = '11.910196',house_park_a = '122.045219'WHERE house_id = '86'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '1308.727539',house_park_y = '2338.922607',house_park_z = '12.025909',house_park_a = '299.531127'WHERE house_id = '87'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '1306.362792',house_park_garage_y = '2337.520751',house_park_garage_z = '12.250000',house_park_garage_a = '301.996459'WHERE house_id = '87'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '87'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '1391.461181',house_park_y = '2300.882080',house_park_z = '11.928147',house_park_a = '122.199172'WHERE house_id = '88'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '1394.192260',house_park_garage_y = '2302.645507',house_park_garage_z = '12.148437',house_park_garage_a = '118.505035'WHERE house_id = '88'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '88'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '1343.751831',house_park_y = '2266.770507',house_park_z = '12.006680',house_park_a = '301.315673'WHERE house_id = '89'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '89'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '1341.371582',house_park_garage_y = '2265.380859',house_park_garage_z = '12.238777',house_park_garage_a = '300.704895'WHERE house_id = '89'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '1380.091796',house_park_y = '2206.245605',house_park_z = '12.022563',house_park_a = '302.195678'WHERE house_id = '90'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '1377.220703',house_park_garage_y = '2204.516601',house_park_garage_z = '12.250000',house_park_garage_a = '301.831848'WHERE house_id = '90'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '90'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '1427.927246',house_park_y = '2142.371826',house_park_z = '11.922522',house_park_a = '302.088867'WHERE house_id = '91'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '1424.710693',house_park_garage_y = '2140.380371',house_park_garage_z = '12.148437',house_park_garage_a = '301.333312'WHERE house_id = '91'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '91'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '1258.157348',house_park_y = '2035.994628',house_park_z = '11.922962',house_park_a = '122.625129'WHERE house_id = '92'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '1261.121215',house_park_garage_y = '2037.857543',house_park_garage_z = '12.148437',house_park_garage_a = '123.899383'WHERE house_id = '92'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '92'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '1215.254516',house_park_y = '2010.378295',house_park_z = '12.016213',house_park_a = '300.019989'WHERE house_id = '93'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '1212.247680',house_park_garage_y = '2008.647705',house_park_garage_z = '12.250000',house_park_garage_a = '301.981628'WHERE house_id = '93'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '93'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '1175.229614',house_park_y = '2068.272216',house_park_z = '11.984609',house_park_a = '301.811370'WHERE house_id = '94'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '1171.657714',house_park_garage_y = '2066.085449',house_park_garage_z = '12.238404',house_park_garage_a = '296.767822'WHERE house_id = '94'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '94'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '1221.110229',house_park_y = '2095.405029',house_park_z = '11.934405',house_park_a = '120.963737'WHERE house_id = '95'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '95'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '1223.690795',house_park_garage_y = '2097.043212',house_park_garage_z = '12.228765',house_park_garage_a = '121.722572'WHERE house_id = '95'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '1179.190551',house_park_y = '2158.477050',house_park_z = '12.008979',house_park_a = '121.650306'WHERE house_id = '96'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '1182.568603',house_park_garage_y = '2160.724853',house_park_garage_z = '12.250000',house_park_garage_a = '122.553955'WHERE house_id = '96'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '96'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '-247.256576',house_park_garage_y = '-1433.372070',house_park_garage_z = '41.898437',house_park_garage_a = '305.655456'WHERE house_id = '261'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '261'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '-243.202301',house_park_y = '-1430.169799',house_park_z = '41.686367',house_park_a = '307.805664'WHERE house_id = '261'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '-213.490417',house_park_y = '-1482.645996',house_park_z = '41.686969',house_park_a = '309.319793'WHERE house_id = '262'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '-216.269241',house_park_garage_y = '-1484.868041',house_park_garage_z = '41.898437',house_park_garage_a = '308.563018'WHERE house_id = '262'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '262'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '-155.708816',house_park_garage_y = '-1434.404541',house_park_garage_z = '41.890842',house_park_garage_a = '130.411605'WHERE house_id = '263'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '263'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '-159.415740',house_park_y = '-1436.558471',house_park_z = '41.682498',house_park_a = '126.345932'WHERE house_id = '263'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '264'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '-173.990997',house_park_garage_y = '-1528.405517',house_park_garage_z = '41.898437',house_park_garage_a = '305.345672'WHERE house_id = '264'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '-170.306335',house_park_y = '-1525.723144',house_park_z = '41.687061',house_park_a = '306.980621'WHERE house_id = '264'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '265'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '-128.128097',house_park_garage_y = '-1507.360229',house_park_garage_z = '41.898437',house_park_garage_a = '85.486351'WHERE house_id = '265'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '-131.256378',house_park_y = '-1507.319580',house_park_z = '41.680484',house_park_a = '91.977226'WHERE house_id = '265'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '266'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '-135.491333',house_park_garage_y = '-1572.280273',house_park_garage_z = '41.898437',house_park_garage_a = '57.397254'WHERE house_id = '266'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '-137.979324',house_park_y = '-1570.599243',house_park_z = '41.687438',house_park_a = '56.607086'WHERE house_id = '266'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '-249.429733',house_park_garage_y = '-1585.766357',house_park_garage_z = '41.890842',house_park_garage_a = '148.140502'WHERE house_id = '267'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '267'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '-251.288726',house_park_y = '-1589.069091',house_park_z = '41.685420',house_park_a = '152.418045'WHERE house_id = '267'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '-307.775726',house_park_garage_y = '-1550.709472',house_park_garage_z = '41.890842',house_park_garage_a = '153.158950'WHERE house_id = '268'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '268'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '-309.208343',house_park_y = '-1553.680053',house_park_z = '41.675624',house_park_a = '150.723419'WHERE house_id = '268'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '-362.812805',house_park_garage_y = '-1544.259155',house_park_garage_z = '41.890129',house_park_garage_a = '237.544677'WHERE house_id = '269'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '269'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '-360.294036',house_park_y = '-1545.971679',house_park_z = '41.681301',house_park_a = '239.872100'WHERE house_id = '269'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '-385.078735',house_park_garage_y = '-1610.542236',house_park_garage_z = '41.898437',house_park_garage_a = '325.115417'WHERE house_id = '270'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '270'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '-382.983764',house_park_y = '-1606.925781',house_park_z = '41.623760',house_park_a = '327.825683'WHERE house_id = '270'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '-334.040771',house_park_garage_y = '-1644.204589',house_park_garage_z = '41.890842',house_park_garage_a = '334.011627'WHERE house_id = '271'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '271'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '-332.080963',house_park_y = '-1641.376220',house_park_z = '41.681427',house_park_a = '331.831573'WHERE house_id = '271'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '-283.177917',house_park_garage_y = '-1678.391479',house_park_garage_z = '41.898437',house_park_garage_a = '325.688873'WHERE house_id = '272'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '272'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '-281.645843',house_park_y = '-1674.706054',house_park_z = '41.679992',house_park_a = '332.079681'WHERE house_id = '272'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '273'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '-165.859252',house_park_garage_y = '-1645.775268',house_park_garage_z = '41.898437',house_park_garage_a = '328.929443'WHERE house_id = '273'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '-162.953125',house_park_y = '-1641.936035',house_park_z = '41.683029',house_park_a = '320.567230'WHERE house_id = '273'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '274'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '-119.680717',house_park_garage_y = '-1680.560546',house_park_garage_z = '41.898437',house_park_garage_a = '312.845764'WHERE house_id = '274'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '-116.719131',house_park_y = '-1677.728271',house_park_z = '41.666603',house_park_a = '315.530578'WHERE house_id = '274'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '275'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '-225.499694',house_park_garage_y = '-1678.323120',house_park_garage_z = '41.898437',house_park_garage_a = '57.463832'WHERE house_id = '275'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '-229.656524',house_park_y = '-1676.009521',house_park_z = '41.691841',house_park_a = '60.109066'WHERE house_id = '275'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '276'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '-341.305145',house_park_garage_y = '-1734.715209',house_park_garage_z = '41.890842',house_park_garage_a = '150.879043'WHERE house_id = '276'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '-342.639862',house_park_y = '-1737.622924',house_park_z = '41.679412',house_park_a = '152.253723'WHERE house_id = '276'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '277'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '-385.679046',house_park_garage_y = '-1711.811523',house_park_garage_z = '41.898437',house_park_garage_a = '149.250167'WHERE house_id = '277'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '-387.401519',house_park_y = '-1715.321533',house_park_z = '41.681545',house_park_a = '151.904281'WHERE house_id = '277'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '278'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '-453.482727',house_park_garage_y = '-1677.743896',house_park_garage_z = '41.890842',house_park_garage_a = '159.548049'WHERE house_id = '278'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '-455.024597',house_park_y = '-1680.603637',house_park_z = '41.679759',house_park_a = '152.257705'WHERE house_id = '278'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '279'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '-458.876373',house_park_garage_y = '-1751.653320',house_park_garage_z = '41.898437',house_park_garage_a = '329.828277'WHERE house_id = '279'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '-457.236999',house_park_y = '-1748.860107',house_park_z = '41.684555',house_park_a = '330.368530'WHERE house_id = '279'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '280'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '-407.603546',house_park_garage_y = '-1780.091186',house_park_garage_z = '41.898437',house_park_garage_a = '239.439392'WHERE house_id = '280'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '-404.112457',house_park_y = '-1781.969360',house_park_z = '41.687122',house_park_a = '241.959762'WHERE house_id = '280'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '281'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '-435.062072',house_park_garage_y = '-1832.835937',house_park_garage_z = '41.890842',house_park_garage_a = '238.724441'WHERE house_id = '281'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '-432.070068',house_park_y = '-1834.964355',house_park_z = '41.682968',house_park_a = '240.470001'WHERE house_id = '281'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '282'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '-459.710296',house_park_garage_y = '-1886.358398',house_park_garage_z = '41.898437',house_park_garage_a = '239.281692'WHERE house_id = '282'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '-456.969726',house_park_y = '-1888.541625',house_park_z = '41.680698',house_park_a = '238.311218'WHERE house_id = '282'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '283'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '-525.482177',house_park_garage_y = '-1821.240234',house_park_garage_z = '41.898437',house_park_garage_a = '154.592987'WHERE house_id = '283'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '-527.439941',house_park_y = '-1823.994873',house_park_z = '41.681613',house_park_a = '151.629287'WHERE house_id = '283'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '284'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '-406.786071',house_park_garage_y = '-1977.143066',house_park_garage_z = '41.898437',house_park_garage_a = '300.918029'WHERE house_id = '284'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '-403.309844',house_park_y = '-1975.165283',house_park_z = '41.687599',house_park_a = '301.841064'WHERE house_id = '284'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '285'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '-353.331451',house_park_garage_y = '-2013.285278',house_park_garage_z = '41.898437',house_park_garage_a = '336.223999'WHERE house_id = '285'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '-351.472229',house_park_y = '-2009.730834',house_park_z = '41.683650',house_park_a = '338.570495'WHERE house_id = '285'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '286'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '-281.918823',house_park_garage_y = '-1996.368408',house_park_garage_z = '41.890842',house_park_garage_a = '34.928192'WHERE house_id = '286'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '-284.450195',house_park_y = '-1992.600708',house_park_z = '41.688129',house_park_a = '33.408813'WHERE house_id = '286'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '287'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '-247.741485',house_park_garage_y = '-1955.515747',house_park_garage_z = '41.898437',house_park_garage_a = '133.254562'WHERE house_id = '287'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '-250.144500',house_park_y = '-1957.704956',house_park_z = '41.686954',house_park_a = '132.226531'WHERE house_id = '287'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '288'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '-287.441650',house_park_garage_y = '-1911.970825',house_park_garage_z = '41.898437',house_park_garage_a = '40.626132'WHERE house_id = '288'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '-289.775451',house_park_y = '-1909.375366',house_park_z = '41.687320',house_park_a = '44.805191'WHERE house_id = '288'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '289'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '-244.498901',house_park_garage_y = '-1870.529418',house_park_garage_z = '41.898437',house_park_garage_a = '39.785709'WHERE house_id = '289'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '-246.996261',house_park_y = '-1867.809936',house_park_z = '41.687152',house_park_a = '42.658866'WHERE house_id = '289'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '290'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '-208.232589',house_park_garage_y = '-1824.158935',house_park_garage_z = '41.898437',house_park_garage_a = '43.507781'WHERE house_id = '290'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '-210.501892',house_park_y = '-1822.375610',house_park_z = '41.648765',house_park_a = '46.150348'WHERE house_id = '290'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '291'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '-164.420654',house_park_garage_y = '-1910.112670',house_park_garage_z = '41.898437',house_park_garage_a = '315.209899'WHERE house_id = '291'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '-161.943923',house_park_y = '-1907.079101',house_park_z = '41.679637',house_park_a = '318.006195'WHERE house_id = '291'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '292'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '-133.899368',house_park_garage_y = '-1839.688842',house_park_garage_z = '41.898437',house_park_garage_a = '59.010032'WHERE house_id = '292'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '-136.996337',house_park_y = '-1838.108154',house_park_z = '41.673072',house_park_a = '62.186706'WHERE house_id = '292'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '-127.897689',house_park_garage_y = '-1772.266723',house_park_garage_z = '41.898437',house_park_garage_a = '97.010765'WHERE house_id = '293'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '293'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '-131.976654',house_park_y = '-1772.823852',house_park_z = '41.687278',house_park_a = '100.326705'WHERE house_id = '293'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_garage_x = '-186.530960',house_park_garage_y = '-1743.873046',house_park_garage_z = '41.898437',house_park_garage_a = '62.341995'WHERE house_id = '294'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_garage_status = '1'WHERE house_id = '294'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	format(string, sizeof(string), "UPDATE `house` SET house_park_x = '-190.362945',house_park_y = '-1742.270019',house_park_z = '41.679843',house_park_a = '63.667819'WHERE house_id = '294'");
	sql_queryEx(zConn, string, QUERY_THREADED);
	SendSucc(playerid, "Гаражи импортированы");
	return true;
}

CMD:addhouse(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    new 
    	Float:x,Float:y,Float:z;

    if(sscanf(params, "dddd",params[0], params[1], params[2], params[3])) 
    	return SendInf(playerid, "Используйте: /addhouse [Класс] [Цена] [Плата в день] [Виртуальный Мир]");

    if(params[0] < 1 || params[0] > 7) 
    	return SendInf(playerid, "1 - Низкий | 2 - Средний | 3 - Высокий | 4 - Особняк | 5 - Апартаменты | | 6 - Апартаменты Элитные");

    GetPlayerPos(playerid, x, y, z);
    
	static 
		formate_str[310];

    format(formate_str, 310, "INSERT INTO house(house_enter_x, house_enter_y, house_enter_z, house_exit_x, house_exit_y, house_exit_z, house_class, house_price, house_takings, house_virtualword) VALUES ('%f','%f','%f','%f','%f','%f','%d','%d','%d','%d')",
    x, y, z, x, y, z, params[0], params[1], params[2], params[3]);
    sql_queryEx(zConn, formate_str, QUERY_THREADED);	

    new File:file = fopen("house_add_sql_go.ini", io_append);
    format(formate_str, sizeof(String1024), "\n%s", formate_str);
    fwrite(file, formate_str), fclose(file);

    formate_str[0] = EOS;

    SendSucc(playerid, "Вы добавили дом! Он появится после рестарта");
	return true;
}

CMD:delhouse(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    if(sscanf(params, "d",params[0])) 
    	return SendInf(playerid, "Используйте: /delhouse [ID дома]");

	static 
		formate_str[250];

    format(formate_str, 250, "UPDATE `accounts` SET `house` = '-1' WHERE `house` = '%d'", params[0]);
    sql_queryEx(zConn, formate_str, QUERY_THREADED);	
    format(formate_str, 250, "DELETE FROM `house` WHERE `house_id` = '%d'", params[0]);
    sql_queryEx(zConn, formate_str, QUERY_THREADED);	

	new 
		fmt_str[350];

    format(fmt_str, sizeof(fmt_str), "Вы успешно удалили дом №%d", params[0]);
    SendSucc(playerid, fmt_str);
	return true;
}

CMD:asellhouse(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    if(sscanf(params, "ds[32]d",params[0],params[1],params[2])) 
    	return SendInf(playerid, "Используйте: /asellhouse [ID дома] [Причина] [Возврат денег (1 - вернуть | 2 - не возвращать)]");


	new 
		fmt_str[350];

    format(fmt_str, sizeof(fmt_str), "Вы успешно продали дом №%d", params[0]);
    SendInf(playerid, fmt_str);

	sell_house_admin(params[0], params[1], params[2]);

	return true;
}

CMD:asellhouse2(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    if(sscanf(params, "ds[32]d",params[0],params[1],params[2])) 
    	return SendInf(playerid, "Используйте: /asellhouse [ID дома] [Причина] [Возврат денег (1 - вернуть | 2 - не возвращать)]");


	new 
		fmt_str[350];

    format(fmt_str, sizeof(fmt_str), "Вы успешно продали дом №%d", params[0]);
    SendInf(playerid, fmt_str);

	sell_house_admin2(params[0], params[1], params[2]);

	return true;
}

CMD:asellhouselow(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    if(sscanf(params, "d",params[0])) 
    	return SendInf(playerid, "Используйте: /asellhouselow [количество PayDay]");

    for(new i, idx = all_houses; i < idx; i ++)
    {
    	if(House[i][house_owned] == -1)
    	{
			House[i][house_sell_count_payday] = params[0];
			House[i][house_sell_status] = 3;	
			save_house(i);
    	}
    }	
    return true;
}

CMD:updateclassleon(playerid, params[])
{

    for(new i, idx = all_houses; i < idx; i ++)
    {
    	if(i >= 66 && i < 96)
    	{
			House[i][house_class] = 4;
			save_house(i);
    	}
    }	
	return true;
}

CMD:aedithouse(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

	new 
		type, count, house_ids;

	new 
		fmt_str[350];

	if(sscanf(params, "ddd", house_ids, type, count))
	{
		SendInf(playerid, "Используйте:/aedithouse "cWH"[ID Дома] [Тип] "cWH"[Значение]");
		SendInf(playerid, "[1] Класс дома [2] Гос.стоимость дома [3] Налог [4] Кол-во дней оплаты");
		return true;
	}

	switch(type)
	{
		case 1: 
		{
			House[house_ids][house_class] = count;
		    format(fmt_str, sizeof(fmt_str), "Класс дома был обновлен! Дом №%d | Класс: %s", house_ids, get_house_class(house_ids));
		    SendSucc(playerid, fmt_str);

		}
		case 2: 
		{
			House[house_ids][house_price] = count;
		    format(fmt_str, sizeof(fmt_str), "Гос.Стоимость дома была обновлена! Дом №%d | Новая цена: %d", house_ids, count);
		    SendSucc(playerid, fmt_str);
		}
		case 3: 
		{
			House[house_ids][house_takings] = count;
		    format(fmt_str, sizeof(fmt_str), "Ежедневная оплата дома была обновлена! Дом №%d | Новая оплата в день: %d", house_ids, count);
		    SendSucc(playerid, fmt_str);
		}
		case 4: 
		{

			House[house_ids][house_days] = count;
		    format(fmt_str, sizeof(fmt_str), "Кол-во дней оплаты дома были обновлены! Дом №%d | Оплачено на: %d", house_ids, count);
		    SendSucc(playerid, fmt_str);

		}
	}
	save_house(house_ids);
	return true;
}

CMD:parkhouse(playerid, params[])
{
    if(pData[playerid][pAdmin] < 7) 
    	return NoCMD(playerid);

	if(sscanf(params, "d", params[0]))
		return SendInf(playerid, "Используйте: /parkhouse "cWH"[ID Дома]");

	if(!IsPlayerInAnyVehicle(playerid)) 
		return SendErr(playerid, "Вы должны находиться в авто");

	new
		Float:x, Float:y, Float:z, Float:a, formate_str[256];

	GetVehiclePos(GetPlayerVehicleID(playerid), x, y, z);
	GetVehicleZAngle(GetPlayerVehicleID(playerid), a);

	House[params[0]][house_park_x] = x;
	House[params[0]][house_park_y] = y;
	House[params[0]][house_park_z] = z;
	House[params[0]][house_park_a] = a;

    format(formate_str, sizeof(formate_str), "UPDATE `house` SET \
    	house_park_x = '%f',\
    	house_park_y = '%f',\
    	house_park_z = '%f',\
    	house_park_a = '%f'\
    	WHERE house_id = '%d'", 
    	House[params[0]][house_park_x],
    	House[params[0]][house_park_y],
    	House[params[0]][house_park_z],
    	House[params[0]][house_park_a],
    	House[params[0]][house_id]);

    sql_queryEx(zConn, formate_str, QUERY_THREADED);		

    new File:file = fopen("house_update_sql_go.ini", io_append);
    format(formate_str, sizeof(formate_str), "\n%s", formate_str);
    fwrite(file, formate_str), fclose(file);


    SendSucc(playerid, "Вы обновили позицию парковки у данного дома!");

	return true;
}

CMD:set_house_garage(playerid, params[])
{
    if(pData[playerid][pAdmin] < 7) 
    	return NoCMD(playerid);

	if(sscanf(params, "d", params[0]))
		return SendInf(playerid, "Используйте: /set_house_garage [id house (ot 0)]");

	new
		Float:x, Float:y, Float:z, Float:a, formate_str[256];

	GetPlayerPos(playerid, x, y, z);
	GetPlayerFacingAngle(playerid, a);

	House[params[0]][house_park_garage_x] = x;
	House[params[0]][house_park_garage_y] = y;
	House[params[0]][house_park_garage_z] = z;
	House[params[0]][house_park_garage_a] = a;

    format(formate_str, sizeof(formate_str), "UPDATE `house` SET \
    	house_park_garage_x = '%f',\
    	house_park_garage_y = '%f',\
    	house_park_garage_z = '%f',\
    	house_park_garage_a = '%f'\
    	WHERE house_id = '%d'",
    	House[params[0]][house_park_garage_x],
    	House[params[0]][house_park_garage_y],
    	House[params[0]][house_park_garage_z],
    	House[params[0]][house_park_garage_a],
    	House[params[0]][house_id]);

    sql_queryEx(zConn, formate_str, QUERY_THREADED);		

    new File:file = fopen("house_update_sql_go.ini", io_append);
    format(formate_str, sizeof(formate_str), "\n%s", formate_str);
    fwrite(file, formate_str), fclose(file);

    SendSucc(playerid, "Вы обновили позицию гаража у дома");

	return true;
}

CMD:add_house_garage(playerid, params[])
{
	if(pData[playerid][pAdmin] < 7) 
    	return NoCMD(playerid);

	if(sscanf(params, "dd", params[0], params[1]))
		return SendInf(playerid, "Используйте: /add_house_garage [id house (ot 0)] [0 - убрать, 1 - установить]");

	if(params[1] < 0 || params[1] > 1)
		return SendInf(playerid, "0 - убрать, 1 - установить");

	format(String256, sizeof(String256), "UPDATE `house` SET \
    	house_garage_status = '%i'\
    	WHERE house_id = '%d'",
    	params[1],
    	House[params[0]][house_id]);

    sql_queryEx(zConn, String256, QUERY_THREADED);		

    House[params[0]][house_garage_status] = params[1];

    new File:file = fopen("house_update_sql_go.ini", io_append);
    format(String1024, sizeof(String1024), "\n%s", String256);
    fwrite(file, String1024), fclose(file);

    format(String144, sizeof(String144), "Вы %s гараж дому %i", params[1] == 1 ? ("установили") : ("убрали"), params[0]);
    SendSucc(playerid, String144);
	return true;
}

alias:gotohouse("house");
CMD:gotohouse(playerid, params[])
{
    if(pData[playerid][pAdmin] < 5) 
    	return NoCMD(playerid);

	if(sscanf(params, "d", params[0]))
	{
		SendInf(playerid, "Используйте: /gotohouse "cWH"[ID Дома]");
		return true;
	}

	new 
		id_house = params[0];

	SetPlayerPos(playerid, House[id_house][house_enter_x], House[id_house][house_enter_y], House[id_house][house_enter_z]);

	new 
		fmt_str[144];

    format(fmt_str, sizeof(fmt_str), "Вы телепортировались к дому №%d", id_house);
    SendSucc(playerid, fmt_str);
	return true;
}

CMD:sellallhouse(playerid)
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

	new time = GetTickCount();

	for(new h, idx = all_houses; h < idx; h ++)
	{
	   	House[h][house_owned] = -1;
	    House[h][house_lock] = 1;
	    
	    House[h][house_days] = 3;

	    House[h][house_people_status] = 0;
	    House[h][house_status_people] = 0;	

	    House[h][safe_house_status] = 0;
	    House[h][safe_house_pass] = 1111;
	    House[h][safe_house_money] = 0;
	    House[h][safe_house_drugs] = 0;	
	    House[h][safe_house_drugs_hard] = 0;

		House[h][wardrobe_gun_1] = -1;	
		House[h][wardrobe_gun_2] = -1;	
		House[h][wardrobe_gun_3] = -1;	
		House[h][wardrobe_skin_1] = 0;
		House[h][wardrobe_skin_2] = 0;
		House[h][wardrobe_skin_3] = 0;

		House[h][house_people_1_id] = -1;
		House[h][house_people_1_day] = 0;
		House[h][house_people_2_id] = -1;
		House[h][house_people_2_day] = 0;
		House[h][house_people_3_id] = -1;
		House[h][house_people_3_day] = 0;
		House[h][house_people_4_id] = -1;
		House[h][house_people_4_day] = 0;

		House[h][wardrobe_gun_ammo_1] = 0;
		House[h][wardrobe_gun_ammo_2] = 0;
		House[h][wardrobe_gun_ammo_3] = 0;

	    House[h][wardrobe_status] = 0;		
	    House[h][house_subsidii_status] = 0;		

	    update_house_pickup(h);
	    save_house(h);
	}
    format(String144, sizeof(String144), "Было продано "cGR"%d"cWH" домов. Запрос занял: "cGR"%d"cWH" мс", all_houses, GetTickCount()-  time);
    SendSucc(playerid, String144);
	return true;
}

#include <..\..\gamemodes\API\systems\house_systems\house_safe_systems.inc>
#include <..\..\gamemodes\API\systems\house_systems\house_wardrobe_systems.inc>