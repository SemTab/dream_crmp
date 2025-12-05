

callback:: load_flate_all()
{
	new Result:flate_player = sql_queryEx(zConn, "SELECT * FROM `flate` ORDER BY `flate_id`", QUERY_CACHED);

	new all_flate_house = sql_num_rows(flate_player);

	new time = GetTickCount();


 	for(new i; i < all_flate_house; i++)
	{
		flate[i][flate_id]  = sql_get_field_assoc_int_ex(flate_player, i, "flate_id"); 

		flate[i][flate_entrance_id]	= sql_get_field_assoc_int_ex(flate_player, i, "flate_entrance_id"); 

		flate[i][flate_id_in_entrance]	= sql_get_field_assoc_int_ex(flate_player, i, "flate_id_in_entrance"); 

		flate[i][flate_owned]  = sql_get_field_assoc_int_ex(flate_player, i, "flate_owned_id"); 

		flate[i][flate_class]  = sql_get_field_assoc_int_ex(flate_player, i, "flate_class"); 
		flate[i][flate_price]  = sql_get_field_assoc_int_ex(flate_player, i, "flate_price"); 
		flate[i][flate_lock]  = sql_get_field_assoc_int_ex(flate_player, i, "flate_lock"); 
		flate[i][flate_takings]  = sql_get_field_assoc_int_ex(flate_player, i, "flate_takings"); 	
		flate[i][flate_days]  = sql_get_field_assoc_int_ex(flate_player, i, "flate_day"); 

  		flate[i][flate_enter_x] = sql_get_field_assoc_float_ex(flate_player, i, "flate_enter_x");
  		flate[i][flate_enter_y] = sql_get_field_assoc_float_ex(flate_player, i, "flate_enter_y");
  		flate[i][flate_enter_z] = sql_get_field_assoc_float_ex(flate_player, i, "flate_enter_z");

  		flate[i][flate_exit_x] = sql_get_field_assoc_float_ex(flate_player, i, "flate_exit_x");
  		flate[i][flate_exit_y] = sql_get_field_assoc_float_ex(flate_player, i, "flate_exit_y");
  		flate[i][flate_exit_z] = sql_get_field_assoc_float_ex(flate_player, i, "flate_exit_z");

		flate[i][flate_people_1_id]  = sql_get_field_assoc_int_ex(flate_player, i, "flate_people_1_id"); 
		flate[i][flate_people_1_day]  = sql_get_field_assoc_int_ex(flate_player, i, "flate_people_1_day"); 
		flate[i][flate_people_2_id]  = sql_get_field_assoc_int_ex(flate_player, i, "flate_people_2_id"); 
		flate[i][flate_people_2_day]  = sql_get_field_assoc_int_ex(flate_player, i, "flate_people_2_day"); 	
		flate[i][flate_people_3_id]  = sql_get_field_assoc_int_ex(flate_player, i, "flate_people_3_id"); 
		flate[i][flate_people_3_day]  = sql_get_field_assoc_int_ex(flate_player, i, "flate_people_3_day"); 
		flate[i][flate_people_4_id]  = sql_get_field_assoc_int_ex(flate_player, i, "flate_people_4_id"); 	
		flate[i][flate_people_4_day]  = sql_get_field_assoc_int_ex(flate_player, i, "flate_people_4_day"); 

		flate[i][safe_flate_status]  = sql_get_field_assoc_int_ex(flate_player, i, "safe_flate_status"); 
		flate[i][safe_flate_pass]  = sql_get_field_assoc_int_ex(flate_player, i, "safe_flate_pass"); 
		flate[i][safe_flate_money]  = sql_get_field_assoc_int_ex(flate_player, i, "safe_flate_money"); 
		flate[i][safe_flate_drugs]  = sql_get_field_assoc_int_ex(flate_player, i, "safe_flate_drugs"); 
		flate[i][safe_flate_drugs_hard] = sql_get_field_assoc_int_ex(flate_player, i, "safe_flate_drugs_hard");

		flate[i][wardrobe_gun_1]  = sql_get_field_assoc_int_ex(flate_player, i, "wardrobe_gun_1"); 
		flate[i][wardrobe_gun_2]  = sql_get_field_assoc_int_ex(flate_player, i, "wardrobe_gun_2"); 
		flate[i][wardrobe_gun_3]  = sql_get_field_assoc_int_ex(flate_player, i, "wardrobe_gun_3"); 

		flate[i][wardrobe_gun_ammo_1]  = sql_get_field_assoc_int_ex(flate_player, i, "wardrobe_gun_ammo_1"); 
		flate[i][wardrobe_gun_ammo_2]  = sql_get_field_assoc_int_ex(flate_player, i, "wardrobe_gun_ammo_2"); 
		flate[i][wardrobe_gun_ammo_3]  = sql_get_field_assoc_int_ex(flate_player, i, "wardrobe_gun_ammo_3"); 

		flate[i][wardrobe_skin_1]  = sql_get_field_assoc_int_ex(flate_player, i, "wardrobe_skin_1"); 
		flate[i][wardrobe_skin_2]  = sql_get_field_assoc_int_ex(flate_player, i, "wardrobe_skin_2"); 
		flate[i][wardrobe_skin_3]  = sql_get_field_assoc_int_ex(flate_player, i, "wardrobe_skin_3"); 

		flate[i][wardrobe_aks_1]  = sql_get_field_assoc_int_ex(flate_player, i, "wardrobe_aks_1"); 
		flate[i][wardrobe_aks_2]  = sql_get_field_assoc_int_ex(flate_player, i, "wardrobe_aks_2"); 
		flate[i][wardrobe_aks_3]  = sql_get_field_assoc_int_ex(flate_player, i, "wardrobe_aks_3"); 

		flate[i][wardrobe_status]  = sql_get_field_assoc_int_ex(flate_player, i, "wardrobe_status"); 

		flate[i][flate_people_status]  = sql_get_field_assoc_int_ex(flate_player, i, "flate_people_status");
		flate[i][flate_people_price]  = sql_get_field_assoc_int_ex(flate_player, i, "flate_people_price");

		flate[i][flate_status_people]  = sql_get_field_assoc_int_ex(flate_player, i, "flate_status_people");
		flate[i][flate_subsidii_status]  = sql_get_field_assoc_int_ex(flate_player, i, "flate_subsidii_status");

		flate[i][flate_sell_status]  = sql_get_field_assoc_int_ex(flate_player, i, "flate_sell_status");
		flate[i][flate_sell_count_payday]  = sql_get_field_assoc_int_ex(flate_player, i, "flate_sell_count_payday");

		create_dynamic_area(flate[i][flate_enter_x], flate[i][flate_enter_y], flate[i][flate_enter_z], flate[i][flate_entrance_id], i, FLATE_ENTER, 1.5);


		if(flate[i][flate_owned] == -1)
		{
			flate[i][flate_pickup] = CreateDynamicPickup(13731, 23, flate[i][flate_enter_x], flate[i][flate_enter_y], flate[i][flate_enter_z], flate[i][flate_entrance_id]);
		}
		else
		{
			flate[i][flate_pickup] = CreateDynamicPickup(13732, 23, flate[i][flate_enter_x], flate[i][flate_enter_y], flate[i][flate_enter_z], flate[i][flate_entrance_id]);

		}

		CreateDynamic3DTextLabel(""cWH"Взаимодействие с квартирой\n"cBLUE"[ALT]",-1, \
		flate[i][flate_enter_x], flate[i][flate_enter_y], flate[i][flate_enter_z], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, flate[i][flate_entrance_id]);	

  		all_flates++;
	}


	CreateDynamic3DTextLabel(""cWH"Выход из квартиры\n"cBLUE"[ALT]",-1, \
	flate_int_exit_coord[1][0], flate_int_exit_coord[1][1], flate_int_exit_coord[1][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	

	CreateDynamicPickup(13702, 23, flate_int_exit_coord[1][0], flate_int_exit_coord[1][1], flate_int_exit_coord[1][2], -1, -1, -1, STREAM_DISTANCE_DYNAMIC_PICKUP);

	create_flate_safe_position();
	create_flate_wardrobe_position();

	create_dynamic_area(flate_int_exit_coord[1][0], flate_int_exit_coord[1][1], flate_int_exit_coord[1][2], -1, 1, FLATE_EXIT);

	printf("[Квартиры]: <%i из %i>. Времени затрачено: <%d мс>" ,all_flate_house, all_flates, GetTickCount()-  time);

	return true;
}

callback:: save_flate(h)
{
    static 
    	formate_str[2500];

    formate_str[0] = EOS; 

    format(formate_str, sizeof(formate_str), "UPDATE `flate` SET \
    	flate_owned_id = '%d',\
    	flate_price = '%d',\
    	flate_takings = '%d',\
    	flate_lock = '%d',\
    	flate_day = '%d',\
    	flate_class = '%d',\
    	flate_people_1_id = '%d',\
    	flate_people_1_day = '%d',\
    	flate_people_2_id = '%d',\
    	flate_people_2_day = '%d',\
    	flate_people_3_id = '%d',\
    	flate_people_3_day = '%d',\
    	flate_people_4_id = '%d',\
    	flate_people_4_day = '%d',\
    	safe_flate_status = '%d',\
    	safe_flate_pass = '%d',\
    	safe_flate_money = '%d',\
    	safe_flate_drugs = '%d',\
    	safe_flate_drugs_hard = '%d',\
    	wardrobe_gun_1 = '%d',\
    	wardrobe_gun_2 = '%d',\
    	wardrobe_gun_3 = '%d',\
    	wardrobe_skin_1 = '%d',\
    	wardrobe_skin_2 = '%d',\
    	wardrobe_skin_3 = '%d',\
    	wardrobe_status = '%d',\
    	flate_people_status = '%d',\
    	flate_people_price = '%d',\
		flate_status_people = '%d',\
		flate_subsidii_status = '%d',\
		flate_sell_status = '%d',\
		flate_sell_count_payday = '%d',\
		wardrobe_aks_1 = '%d',\
		wardrobe_aks_2 = '%d',\
		wardrobe_aks_3 = '%d'\
    	WHERE flate_id = '%d'",
    	flate[h][flate_owned],
    	flate[h][flate_price],
    	flate[h][flate_takings],
    	flate[h][flate_lock],
    	flate[h][flate_days],
    	flate[h][flate_class],
    	flate[h][flate_people_1_id],
    	flate[h][flate_people_1_day],
    	flate[h][flate_people_2_id],
    	flate[h][flate_people_2_day],
    	flate[h][flate_people_3_id],
    	flate[h][flate_people_3_day],
    	flate[h][flate_people_4_id],
    	flate[h][flate_people_4_day],
    	flate[h][safe_flate_status],
    	flate[h][safe_flate_pass],
    	flate[h][safe_flate_money],
    	flate[h][safe_flate_drugs],
    	flate[h][safe_flate_drugs_hard],
    	flate[h][wardrobe_gun_1],
    	flate[h][wardrobe_gun_2],
    	flate[h][wardrobe_gun_3],
    	flate[h][wardrobe_skin_1],
    	flate[h][wardrobe_skin_2],
    	flate[h][wardrobe_skin_3],
    	flate[h][wardrobe_status],
    	flate[h][flate_people_status],
    	flate[h][flate_people_price],
		flate[h][flate_status_people],
		flate[h][flate_subsidii_status],

		flate[h][flate_sell_status],
		flate[h][flate_sell_count_payday],

    	flate[h][wardrobe_aks_1],
		flate[h][wardrobe_aks_2],
		flate[h][wardrobe_aks_3],

    	flate[h][flate_id]);

    sql_queryEx(zConn, formate_str, QUERY_THREADED);	

    return true;
}


callback:: sell_flate_admin(h, reason[], money_back)
{
	if(flate[h][flate_owned] == -1) 
		return printf("Ошибка! Квартира №%d никому не принадлежит!", h);

	new 
		price = flate[h][flate_price],
		owner_id = flate[h][flate_owned];

	new 
		owner_flate_name[32];

	new 
		fmt_str[144];

	GetPlayerNameByID(owner_id, owner_flate_name);

	new 
		player_id = GetPlayerID(owner_flate_name);

	if(IsPlayerConnected(player_id))
	{
		if(pData[player_id][pFlate] == h)
		{	
			pData[player_id][pFlate] = -1;
			UpdatePlayerData(player_id,"flate", pData[player_id][pFlate]);
			SFCM(player_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Ваша квартира была продана администратором. Причина: %s", reason);	

			pData[player_id][pSpawn] = 0;
			UpdatePlayerData(player_id, "spawn", pData[player_id][pSpawn]);

			if(money_back == 1)
			{

				format(fmt_str, sizeof(fmt_str), "Возврат за продажу администратором квартиры №: %d", h);
				give_money(player_id, price, fmt_str);				
			}

		}
	}
	else
	{	
		new 
			formate_str[280];

		format(formate_str, 80, "UPDATE accounts SET flate = '-1' WHERE flate = '%d'", h);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	
		if(money_back == 1)
		{
			format(formate_str, sizeof(formate_str), "UPDATE `accounts` SET `bank` = bank + %i WHERE `id` = '%i'" , price, owner_id);
  			sql_queryEx(zConn, formate_str, QUERY_THREADED);
  		}

	}


   	flate[h][flate_owned] = -1;
    flate[h][flate_lock] = 0;
    
    flate[h][flate_class] = 1;
    flate[h][flate_days] = 3;

    flate[h][flate_people_status] = 0;
    flate[h][flate_status_people] = 0;	

    flate[h][safe_flate_status] = 0;
    flate[h][safe_flate_pass] = 1111;
    flate[h][safe_flate_money] = 0;
    flate[h][safe_flate_drugs] = 0;	

	flate[h][wardrobe_gun_1] = -1;	
	flate[h][wardrobe_gun_2] = -1;	
	flate[h][wardrobe_gun_3] = -1;	
	flate[h][wardrobe_skin_1] = 0;
	flate[h][wardrobe_skin_2] = 0;
	flate[h][wardrobe_skin_3] = 0;

    flate[h][wardrobe_status] = 0;		
    flate[h][flate_subsidii_status] = 0;		

    update_flate_pickup(h);
    save_flate(h);
    return true;
}

stock sell_flate_accept(playerid)
{
	SPD(playerid, DIALOG_ACCEPT_SELL_FLATE, DIALOG_STYLE_MSGBOX, !""cBLUE"Продажа квартиры", !"\
	"cWH"Вы уверены, что хотите продать квартиру в гос.стоимость?\n\n\
	Вам будет возвращено 80%% от стоимости!", !"Да", !"Нет");

	return true;

}

stock sell_flate(playerid, h)
{
	if(flate[h][flate_owned] == -1) 
		return printf("Ошибка! Квартира №%d никому не принадлежит!", h);

	if(pData[playerid][pFlate] == h)
	{	
		new 
			final_money = floatround(flate[h][flate_price]*0.8);

		pData[playerid][pFlate] = -1;
		UpdatePlayerData(playerid,"flate", pData[playerid][pFlate]);
		pData[playerid][pSpawn] = 0;
		UpdatePlayerData(playerid, "spawn", pData[playerid][pSpawn]);

		SendSucc(playerid, "Вы успешно продали квартиру в гос.стоимость!");

	 	format(String144, sizeof(String144), "Продажа квартиры №%d", h);
		give_money(playerid, final_money, String144);

		format(String256, sizeof(String256), "SELECT * FROM player_vehicles WHERE userid = '%d' LIMIT 1", pData[playerid][pMysqlID]);
		new Result:carfind = sql_queryEx(zConn, String256, QUERY_CACHED);

		if(sql_num_rows(carfind)) 
		{
		    vehicle_destroy(playerid);
		    SendClientMessage(playerid, COLOR_LIGHTRED, "Ваша машина была отправлена на штраф-стоянку из продажи жилья!");
		}

		sql_free_result(carfind);

	    exit_flate(playerid, GetPVarIntNew(playerid, "flate_id_active"));

	   	flate[h][flate_owned] = -1;
	    flate[h][flate_lock] = 0;
	    
	    flate[h][flate_class] = 1;
	    flate[h][flate_days] = 3;

	    flate[h][flate_people_status] = 0;
	    flate[h][flate_status_people] = 0;	

	    flate[h][safe_flate_status] = 0;
	    flate[h][safe_flate_pass] = 1111;
	    flate[h][safe_flate_money] = 0;
	    flate[h][safe_flate_drugs] = 0;	

		flate[h][wardrobe_gun_1] = -1;	
		flate[h][wardrobe_gun_2] = -1;	
		flate[h][wardrobe_gun_3] = -1;	
		flate[h][wardrobe_skin_1] = 0;
		flate[h][wardrobe_skin_2] = 0;
		flate[h][wardrobe_skin_3] = 0;

	    flate[h][wardrobe_status] = 0;		
	    flate[h][flate_subsidii_status] = 0;		

	    update_flate_pickup(h);
	    save_flate(h);
	}

	return true;
}


stock unrent_flate_payday_1(h)
{
	new 
		renter_id = flate[h][flate_people_1_id];	

	new 
		rent_house_name[32];

	GetPlayerNameByID(renter_id, rent_house_name);

	new 
		rent_id = GetPlayerID(rent_house_name);

	if(IsPlayerConnected(rent_id))
	{
		if(pData[rent_id][pFlateRent] == h)
		{	
			pData[rent_id][pFlateRent] = -1;
			UpdatePlayerData(rent_id,"flate_rent", pData[rent_id][pFlateRent]);
			SFCM(rent_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы были выселены из квартиры за неуплату!");	


			pData[rent_id][pSpawn] = 0;
			UpdatePlayerData(rent_id, "spawn", pData[rent_id][pSpawn]);
		}
	}
	else
	{	
		new 
			formate_str[280];

		format(formate_str, 80, "UPDATE accounts SET flate_rent = '-1' WHERE flate_rent = '%d'", h);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	

		format(formate_str, 80, "UPDATE accounts SET spawn = '0' WHERE id = '%d'", rent_id);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	


		send_off_message(-1, rent_house_name, "Вы были выселены из квартиры за неуплату комнаты!");

	}

	return true;

}

stock unrent_flate_payday_2(h)
{
	new 
		renter_id = flate[h][flate_people_2_id];	

	new 
		rent_house_name[32];

	GetPlayerNameByID(renter_id, rent_house_name);

	new 
		rent_id = GetPlayerID(rent_house_name);

	if(IsPlayerConnected(rent_id))
	{
		if(pData[rent_id][pFlateRent] == h)
		{	
			pData[rent_id][pFlateRent] = -1;
			UpdatePlayerData(rent_id,"flate_rent", pData[rent_id][pFlateRent]);
			SFCM(rent_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы были выселены из квартиры за неуплату!");	


			pData[rent_id][pSpawn] = 0;
			UpdatePlayerData(rent_id, "spawn", pData[rent_id][pSpawn]);
		}
	}
	else
	{	
		new 
			formate_str[280];

		format(formate_str, 80, "UPDATE accounts SET flate_rent = '-1' WHERE flate_rent = '%d'", h);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	

		format(formate_str, 80, "UPDATE accounts SET spawn = '0' WHERE id = '%d'", rent_id);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	


		send_off_message(-1, rent_house_name, "Вы были выселены из квартиры за неуплату комнаты!");

	}

	return true;

}

stock unrent_flate_payday_3(h)
{
	new 
		renter_id = flate[h][flate_people_3_id];	

	new 
		rent_house_name[32];

	GetPlayerNameByID(renter_id, rent_house_name);

	new 
		rent_id = GetPlayerID(rent_house_name);

	if(IsPlayerConnected(rent_id))
	{
		if(pData[rent_id][pFlateRent] == h)
		{	
			pData[rent_id][pFlateRent] = -1;
			UpdatePlayerData(rent_id,"flate_rent", pData[rent_id][pFlateRent]);
			SFCM(rent_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы были выселены из квартиры за неуплату!");	


			pData[rent_id][pSpawn] = 0;
			UpdatePlayerData(rent_id, "spawn", pData[rent_id][pSpawn]);
		}
	}
	else
	{	
		new 
			formate_str[280];

		format(formate_str, 80, "UPDATE accounts SET flate_rent = '-1' WHERE flate_rent = '%d'", h);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	

		format(formate_str, 80, "UPDATE accounts SET spawn = '0' WHERE id = '%d'", rent_id);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	


		send_off_message(-1, rent_house_name, "Вы были выселены из квартиры за неуплату комнаты!");

	}

	return true;

}

stock unrent_flate_payday_4(h)
{
	new 
		renter_id = flate[h][flate_people_4_id];	

	new 
		rent_house_name[32];

	GetPlayerNameByID(renter_id, rent_house_name);

	new 
		rent_id = GetPlayerID(rent_house_name);

	if(IsPlayerConnected(rent_id))
	{
		if(pData[rent_id][pFlateRent] == h)
		{	
			pData[rent_id][pFlateRent] = -1;
			UpdatePlayerData(rent_id,"flate_rent", pData[rent_id][pFlateRent]);
			SFCM(rent_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы были выселены из квартиры за неуплату!");	


			pData[rent_id][pSpawn] = 0;
			UpdatePlayerData(rent_id, "spawn", pData[rent_id][pSpawn]);
		}
	}
	else
	{	
		new 
			formate_str[280];

		format(formate_str, 80, "UPDATE accounts SET flate_rent = '-1' WHERE flate_rent = '%d'", h);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	

		format(formate_str, 80, "UPDATE accounts SET spawn = '0' WHERE id = '%d'", rent_id);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	


		send_off_message(-1, rent_house_name, "Вы были выселены из квартиры за неуплату комнаты!");

	}

	return true;

}


stock flate_sell_payday(h)
{
	if(flate[h][flate_owned] == -1) 
		return printf("Ошибка! Квартира №%d никому не принадлежит!", h);

	new 
		owner_id = flate[h][flate_owned];

	new 
		owner_house_name[32];

	GetPlayerNameByID(owner_id, owner_house_name);

	new 
		player_id = GetPlayerID(owner_house_name);

	new 
		final_money = floatround(flate[h][flate_price]*0.8);


	if(IsPlayerConnected(player_id))
	{
		if(pData[player_id][pFlate] == h)
		{	
			pData[player_id][pFlate] = -1;
			UpdatePlayerData(player_id,"flate", pData[player_id][pFlate]);
			SFCM(player_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Ваша квартира была продана в гос.стоимость. Причина: Неоплата имущества");	

			pData[player_id][pSpawn] = 0;
			UpdatePlayerData(player_id, "spawn", pData[player_id][pSpawn]);

	        SendClientMessage(player_id, COLOR_LIGHTRED, "Вы можете вернуть 80 процентов от стоимости имущества");
	        SendClientMessage(player_id, COLOR_LIGHTRED, "Для этого введите команду /returnmoney");

	        pData[player_id][pReturnMoney] += final_money;
	        if(pData[player_id][pReturnMoney] > 20000000 ) pData[player_id][pReturnMoney] = 0;

	        vehicle_destroy(player_id);
	        SendClientMessage(player_id, COLOR_LIGHTRED, "Ваша машина была отправлена на штраф-стоянку из продажи жилья!");

		}
	}
	else
	{	
		new 
			formate_str[280];

		format(formate_str, 80, "UPDATE accounts SET flate = '-1' WHERE flate = '%d'", h);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	

		format(formate_str, 80, "UPDATE accounts SET spawn = '0' WHERE id = '%d'", owner_id);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	

		format(String256,sizeof(String256),"UPDATE `accounts` SET returnmoney = returnmoney + %d WHERE id = '%i'", final_money, owner_id);
		sql_queryEx(zConn, String256, QUERY_THREADED);

		send_off_message(-1, owner_house_name, "Ваша квартира была продана в гос.стоимость за неуплату. Мы вернули 80 процентов (/returnmoney)");

	}


	flate[h][flate_sell_status] = 3;
	flate[h][flate_sell_count_payday] = RandomEx(2, 22);

   	flate[h][flate_owned] = -1;
    flate[h][flate_lock] = 0;
    
    flate[h][flate_class] = 1;
    flate[h][flate_days] = 3;

    flate[h][flate_people_status] = 0;
    flate[h][flate_status_people] = 0;	

    flate[h][safe_flate_status] = 0;
    flate[h][safe_flate_pass] = 1111;
    flate[h][safe_flate_money] = 0;
    flate[h][safe_flate_drugs] = 0;	

	flate[h][wardrobe_gun_1] = -1;	
	flate[h][wardrobe_gun_2] = -1;	
	flate[h][wardrobe_gun_3] = -1;	
	flate[h][wardrobe_skin_1] = 0;
	flate[h][wardrobe_skin_2] = 0;
	flate[h][wardrobe_skin_3] = 0;

    flate[h][wardrobe_status] = 0;		
    flate[h][flate_subsidii_status] = 0;		

    update_flate_pickup(h);
    save_flate(h);

    return true;	
}

stock update_flate_pickup(h)
{
	DestroyDynamicMapIcon(flate[h][flate_mapicon]);
    DestroyDynamicPickup(flate[h][flate_pickup]);
    if(flate[h][flate_owned] == -1)
    {
        flate[h][flate_pickup] = CreateDynamicPickup(1273, 23, flate[h][flate_enter_x], flate[h][flate_enter_y], flate[h][flate_enter_z], -1);
        flate[h][flate_mapicon] = CreateDynamicMapIcon(flate[h][flate_enter_x], flate[h][flate_enter_y], flate[h][flate_enter_z], 31, COLOR_WHITE, 0, -1, -1, 100.0);
    }
    else
    {
        flate[h][flate_pickup] = CreateDynamicPickup(1272, 23, flate[h][flate_enter_x], flate[h][flate_enter_y], flate[h][flate_enter_z],-1);
        flate[h][flate_mapicon] = CreateDynamicMapIcon(flate[h][flate_enter_x], flate[h][flate_enter_y], flate[h][flate_enter_z], 32, COLOR_WHITE, 0, -1, -1, 100.0);
    }
    return true;
}

stock get_flate_class(h)
{
	new 
		name[20],
		class = flate[h][flate_class];

	switch(class)
	{
		case 1: name = "Низкий";
		case 2: name = "Апартаменты";
		case 3: name = "Высокий";
		case 4: name = "Особняк";
		default: name = "Заброшенный";
	}
	return name;
}

stock get_flate_seif(h)
{
	new 
		name[30],
		class = flate[h][safe_flate_status];

	switch(class)
	{
		case 1: name = ""cBLUE"Маленький сейф";
		case 2: name = ""cBLUE"Средний сейф";
		case 3: name = ""cBLUE"Большой сейф";
		default: name = ""cLRED"Отсутствует";
	}
	return name;
}

stock enter_flate(playerid, h)
{
	if(h == -1) 
		return true;

	if(opcode) FormattedMessage(playerid, -1, "[debug] area_enter_flate: №%d", h);

	new 
		class = flate[h][flate_class];


	SetPVarIntNew(playerid, "entrance_enter_id_vw", flate[h][flate_entrance_id]);

	SetPVarIntNew(playerid, "flate_id_enter", GetPlayerVirtualWorld(playerid));
	SetPVarIntNew(playerid, "flate_id_active", h);

	SetPlayerPosEx(playerid, flate_int_exit_coord[class][0], flate_int_exit_coord[class][1], flate_int_exit_coord[class][2], flate_int_exit_coord[class][3]);
	SetPlayerVirtualWorld(playerid, flate[h][flate_id]-1);

	return true;
}

stock exit_flate(playerid, h)
{
	if(h == -1) 
		return true;

	if(opcode) FormattedMessage(playerid, -1, "[debug] area_exit_flate: №%d", h);

	h = GetPVarIntNew(playerid, "entrance_enter_id_vw");

	new 
		p = GetPVarIntNew(playerid, "flate_id_active");

	SetPlayerPosEx(playerid, flate[p][flate_enter_x], flate[p][flate_enter_y], flate[p][flate_enter_z], 2);
	SetPlayerVirtualWorld(playerid, h);

	DeletePVarNew(playerid, "flate_id_active");

	return true;
}

stock flate_info(playerid, id_flate)
{

	static 
		h_class[24],
		h_owner[24];

	format(h_class, 24, "%s", get_flate_class(id_flate));

	if(flate[id_flate][flate_owned] != -1)
	{
		GetPlayerNameByID(flate[id_flate][flate_owned], flate[id_flate][flate_owner]);
		format(h_owner, 24, flate[id_flate][flate_owner]);
	}
	else
	{
		format(h_owner, 24, "Государство");	
	}

	if(flate[id_flate][flate_owned] == -1)
	{
		format(String1024, sizeof(String1024), "\
			"cWH"Номер квартиры: 		\t"cBLUE"%d\n\
			"cWH"Номер подъезда: 		\t"cBLUE"%d\n\
			"cWH"Класс квартиры:		\t"cBLUE"%s\n\
			"cWH"Владелец: 			\t"cBLUE"%s\n\
			"cWH"Статус: 			\t\t%s\n\
			"cWH"Цена: 				\t"cGR"%d рублей\n\
			"cWH"Ежедневная оплата: \t\t\t"cGR"%d рублей\n\n\
			"cBLUE"Вы действительно хотите купить квартиру?",
			flate[id_flate][flate_id_in_entrance],
			flate[id_flate][flate_entrance_id],
			h_class,
			h_owner,
			(flate[id_flate][flate_owned]) ? (""cGR"Продается") : (""cLRED"Куплен"),
			flate[id_flate][flate_price], flate[id_flate][flate_takings]);
		SPD(playerid, DIALOG_BUY_FLATE, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка квартиры", String1024, !"Купить", !"Закрыть");		
	}
	else if(flate[id_flate][flate_people_status] == 0)
	{
		format(String1024, sizeof(String1024), "\
		"cWH"Номер квартиры: 		\t"cBLUE"%d\n\
		"cWH"Номер подъезда: 		\t"cBLUE"%d\n\
		"cWH"Класс квартиры:		\t"cBLUE"%s\n\
		"cWH"Владелец: 			\t"cBLUE"%s\n\
		"cWH"Статус: 			\t\t%s\n\
		"cWH"Стоимость: 		\t\t"cGR"%d руб\n\
		"cWH"Ежедневная оплата: \t\t\t"cGR"%d рублей",
		flate[id_flate][flate_id_in_entrance],
		flate[id_flate][flate_entrance_id],
		h_class,
		h_owner,
		(flate[id_flate][flate_lock] == 1) ? (""cGR"Дверь открыта") : (""cLRED"Дверь закрыта"),
		flate[id_flate][flate_price], flate[id_flate][flate_takings]);		
		SPD(playerid, DIALOG_INFO_FLATE, DIALOG_STYLE_MSGBOX, !""cBLUE"Информация о квартире", String1024, !"Войти", !"Закрыть");		
	}
	else if(flate[id_flate][flate_people_status] == 1 && flate[id_flate][flate_people_status] == 1)
	{
		SetPVarIntNew(playerid, "id_flate_rent", id_flate);

		format(String1024, sizeof(String1024), "\
		"cWH"Номер квартиры: 		\t"cBLUE"%d\n\
		"cWH"Номер подъезда: 		\t"cBLUE"%d\n\
		"cWH"Владелец: \t"cBLUE"%s\n\
		"cWH"Статус: \t%s\n\
		"cWH"Стоимость: \t"cGR"%d руб\n\
		"cWH"\t\n\
		"cWH"Ежедневная оплата за комнату: \t "cGR"%d руб\n\
		"cWH"Арендовать комнату \t"cGR"Аренда\n\n\
		"cWH"\t\n\
		"cWH"Войти в квартиру",
		flate[id_flate][flate_id_in_entrance],
		flate[id_flate][flate_entrance_id],
		h_owner,
		(flate[id_flate][flate_lock] == 1) ? (""cGR"Дверь открыта") : (""cLRED"Дверь закрыта"),
		flate[id_flate][flate_price], flate[id_flate][flate_people_price]);		
		SPD(playerid, DIALOG_INFO_RENT_FLATE, DIALOG_STYLE_TABLIST, !""cBLUE"Информация о квартире", String1024, !"Выбор", !"Закрыть");		
	}	

	return true;
}

stock flate_panel_change(playerid, h)
{
	if(opcode) FormattedMessage(playerid, -1, "[debug] area_flate_menu: №%d", h);

	if(flate[h][flate_status_people] == 0 && flate[h][flate_owned] == pData[playerid][pMysqlID])
	{
	    format(String512, sizeof(String512), "\
	    "cGREY"Пункт\t"cGREY"Действие\n\
	    "cBLUE"1. "cWH"Информация о квартире\t"cGR"Открыть\n\
	    "cBLUE"2. "cWH"Двери в квартире\t%s\n\
	    "cBLUE"3. "cWH"Улучшения\t"cGR"Купить\n\
	    "cBLUE"4. "cWH"Продать квартире\t"cGR"Продажа\n\
	    "cWH"\t\n\
	    "cBLUE"- "cWH"Выйти из квартиры\t",
	    (flate[h][flate_lock] == 1) ? (""cGR"Дверь открыта") : (""cLRED"Дверь закрыта"));
	    SPD(playerid, SHOW_CHANGE_MENU_FLATE_1, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление квартирой", String512, !"Выбрать", !"Закрыть"); 
	}
	else if(flate[h][flate_status_people] == 1 && flate[h][flate_owned] == pData[playerid][pMysqlID])
	{
	    format(String512, sizeof(String512), "\
	    "cGREY"Пункт\t"cGREY"Действие\n\
	    "cBLUE"1. "cWH"Информация о квартире\t"cGR"Открыть\n\
	    "cBLUE"2. "cWH"Двери в квартире\t%s\n\
	    "cBLUE"3. "cWH"Улучшения\t"cGR"Купить\n\
	    "cBLUE"4. "cWH"Продать квартиру\t"cGR"Продажа\n\
	    "cBLUE"5. "cWH"Жильцы квартиры\t"cBLUE"Управление\n\
	    "cWH"\t\n\
	    "cBLUE"- "cWH"Выйти из квартиры\t",
	    (flate[h][flate_lock] == 1)? (""cGR"Дверь открыта") : (""cLRED"Дверь закрыта"));
	    SPD(playerid, SHOW_CHANGE_MENU_FLATE_2, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление квартирой", String512, !"Выбрать", !"Закрыть"); 		
	}
	else if(flate[h][flate_status_people] == 0 && flate[h][flate_owned] != pData[playerid][pMysqlID])
	{
	    format(String512, sizeof(String512), "\
	    "cGREY"Пункт\t"cGREY"Действие\n\
	    "cBLUE"- "cWH"Информация о квартире\t"cGR"Открыть\n\
	    "cWH"\t\n\
	    "cBLUE"- "cWH"Выйти из квартиры\t");
	    SPD(playerid, SHOW_CHANGE_MENU_FLATE_3, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление квартирой", String512, !"Выбрать", !"Закрыть"); 			
	}
	else if(flate[h][flate_status_people] == 1 && flate[h][flate_people_status] == 1 && flate[h][flate_owned] != pData[playerid][pMysqlID])
	{
	    format(String512, sizeof(String512), "\
	    "cGREY"Пункт\t"cGREY"Действие\n\
	    "cBLUE"- "cWH"Информация о квартире\t"cGR"Открыть\n\
	    "cBLUE"- "cWH"Аренда комнаты\t"cGR"Открыть\n\
	    "cWH"\t\n\
	    "cBLUE"- "cWH"Выйти из квартиры\t");
	    SPD(playerid, SHOW_CHANGE_MENU_FLATE_4, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление квартирой", String512, !"Выбрать", !"Закрыть"); 			
	}
	else
	{
	    format(String512, sizeof(String512), "\
	    "cGREY"Пункт\t"cGREY"Действие\n\
	    "cBLUE"- "cWH"Информация о квартире\t"cGR"Открыть\n\
	    "cWH"\t\n\
	    "cBLUE"- "cWH"Выйти из квартиры\t");
	    SPD(playerid, SHOW_CHANGE_MENU_FLATE_3, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление квартирой", String512, !"Выбрать", !"Закрыть"); 		
	}
    return true;
}

alias:flate("flatemenu", "kvartira");
CMD:flate(playerid)
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
		h;

	if(pData[playerid][pFlate] != -1 && pData[playerid][pFlateRent] == -1)
	{
		h = pData[playerid][pFlate];
	}
	else if(pData[playerid][pFlate] == -1 && pData[playerid][pFlateRent] != -1)
	{
		h = pData[playerid][pFlateRent];
	}

	if(h == -1)
		SendErr(playerid, "У вас нет дома или квартиры для использования данной команды!");


	return flate_panel_change_cmd(playerid, h);
}


stock flate_panel_change_cmd(playerid, h)
{

	if(opcode) FormattedMessage(playerid, -1, "[debug] area_flate_menu: %d", h);

	if(flate[h][flate_status_people] == 0 && flate[h][flate_owned] == pData[playerid][pMysqlID])
	{
	    format(String512, sizeof(String512), "\
	    "cGREY"Пункт\t"cGREY"Действие\n\
	    "cBLUE"1. "cWH"Информация о квартире\t"cGR"Открыть\n\
	    "cBLUE"2. "cWH"Двери в квартире\t%s\n\
	    "cBLUE"3. "cWH"Улучшения\t"cGR"Купить\n\
	    "cBLUE"4. "cWH"Продать квартире\t"cGR"Продажа",
	    (flate[h][flate_lock] == 1) ? (""cGR"Дверь открыта") : (""cLRED"Дверь закрыта"));
	    SPD(playerid, SHOW_CHANGE_MENU_FLATE_1, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление квартирой", String512, !"Выбрать", !"Закрыть"); 
	}
	else if(flate[h][flate_status_people] == 1 && flate[h][flate_owned] == pData[playerid][pMysqlID])
	{
	    format(String512, sizeof(String512), "\
	    "cGREY"Пункт\t"cGREY"Действие\n\
	    "cBLUE"1. "cWH"Информация о квартире\t"cGR"Открыть\n\
	    "cBLUE"2. "cWH"Двери в квартире\t%s\n\
	    "cBLUE"3. "cWH"Улучшения\t"cGR"Купить\n\
	    "cBLUE"4. "cWH"Продать квартиру\t"cGR"Продажа\n\
	    "cBLUE"5. "cWH"Жильцы квартиры\t"cBLUE"Управление",
	    (flate[h][flate_lock] == 1)? (""cGR"Дверь открыта") : (""cLRED"Дверь закрыта"));
	    SPD(playerid, SHOW_CHANGE_MENU_FLATE_2, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление квартирой", String512, !"Выбрать", !"Закрыть"); 		
	}
	else if(flate[h][flate_status_people] == 0 && flate[h][flate_owned] != pData[playerid][pMysqlID])
	{
	    format(String512, sizeof(String512), "\
	    "cGREY"Пункт\t"cGREY"Действие\n\
	    "cBLUE"- "cWH"Информация о квартире\t"cGR"Открыть");
	    SPD(playerid, SHOW_CHANGE_MENU_FLATE_3, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление квартирой", String512, !"Выбрать", !"Закрыть"); 			
	}
	else if(flate[h][flate_status_people] == 1 && flate[h][flate_people_status] == 1 && flate[h][flate_owned] != pData[playerid][pMysqlID])
	{
	    format(String512, sizeof(String512), "\
	    "cGREY"Пункт\t"cGREY"Действие\n\
	    "cBLUE"- "cWH"Информация о квартире\t"cGR"Открыть\n\
	    "cBLUE"- "cWH"Аренда комнаты\t"cGR"Открыть");
	    SPD(playerid, SHOW_CHANGE_MENU_FLATE_4, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление квартирой", String512, !"Выбрать", !"Закрыть"); 			
	}
	else
	{
	    format(String512, sizeof(String512), "\
	    "cGREY"Пункт\t"cGREY"Действие\n\
	    "cBLUE"- "cWH"Информация о квартире\t"cGR"Открыть");
	    SPD(playerid, SHOW_CHANGE_MENU_FLATE_3, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление квартирой", String512, !"Выбрать", !"Закрыть"); 		
	}
    return true;
}

stock manage_people_flate_p(playerid, id_flate)
{

	format(String512, sizeof(String512), "\
	"cWH"В вашей квартире может поселиться максимум "cBLUE"4 человека"cWH"\n\
	Каждый из них оплачивает аренду за проживание в сутки\n\
	Вы можете регулировать стоимость аренды комнаты и выставлять свою стоимость\n\
	Максимальное и минимальное значение стоимости 1 дня аренды - ограничены\n\n\
	Текущая стоимость: "cGR"%d"cWH" рублей\n\n\
	Укажите новую стоимость 1 дня аренды комнаты\n\
	"cBLUE"От 500 рублей и до 15000 рублей", flate[id_flate][flate_people_price]);

	SPD(playerid, DIALOG_CHANGE_PRICE_P_F, DIALOG_STYLE_INPUT, !""cBLUE"Изменение стоимости", String512, !"Далее", !"Назад");



	return true;
}

stock show_menu_rent_flate(playerid, id_flate)
{
	if(pData[playerid][pFlateRent] != id_flate)
		return SendErr(playerid, "Системная ошибка #001 | Обратитесь на форум!");


	if(pData[playerid][pFlateRent] == -1 && pData[playerid][pHouseRent] == -1)
		return mute_flate_start_rent(playerid, id_flate);

	if(pData[playerid][pFlateRent] == id_flate)
	{
		new 
			day_counts;

		if(flate[id_flate][flate_people_1_id] == pData[playerid][pMysqlID])
		{
			day_counts = flate[id_flate][flate_people_1_day];
		}
		else if(flate[id_flate][flate_people_2_id] == pData[playerid][pMysqlID])
		{
			day_counts = flate[id_flate][flate_people_2_day];
		}
		else if(flate[id_flate][flate_people_3_id] == pData[playerid][pMysqlID])
		{
			day_counts = flate[id_flate][flate_people_3_day];
		}
		else if(flate[id_flate][flate_people_4_id] == pData[playerid][pMysqlID])
		{
			day_counts = flate[id_flate][flate_people_4_day];
		}


	    format(String512, sizeof(String512), "\
	    "cGREY"№\t"cGREY"Тип\t"cGREY"Информация\n\
	    "cBLUE"1. \t"cWH"Дней оплачено\t"cBLUE"%d дней\n\
	    "cBLUE"2. \t"cWH"Продление аренды\t"cBLUE"Продлить\n\
	    "cBLUE"3. \t"cWH"Завершить аренду\t"cLRED"Закончить аренду", day_counts);
	    SPD(playerid, DIALOG_FLATE_RENT_P, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Аренда комнаты", String512, !"Выбрать", !"Закрыть"); 
	}
	return true;
}

stock countinue_rent_flate(playerid, id_flate)
{
	new 
		day_counts;

	if(flate[id_flate][flate_people_1_id] == pData[playerid][pMysqlID])
	{
		day_counts = flate[id_flate][flate_people_1_day];
	}
	else if(flate[id_flate][flate_people_2_id] == pData[playerid][pMysqlID])
	{
		day_counts = flate[id_flate][flate_people_2_day];
	}
	else if(flate[id_flate][flate_people_3_id] == pData[playerid][pMysqlID])
	{
		day_counts = flate[id_flate][flate_people_3_day];
	}
	else if(flate[id_flate][flate_people_4_id] == pData[playerid][pMysqlID])
	{
		day_counts = flate[id_flate][flate_people_4_day];
	}

	if(flate[id_flate][flate_people_status]  == 0)
		return SendErr(playerid, "Возможность продление аренды запрещена владельцем дома!");

	new 
		final_max_day = MAX_RENT_FLAYT_DAY - day_counts;

	SetPVarIntNew(playerid, "final_max_day_rent", final_max_day);

	format(String512, sizeof(String512), "\
	"cWH"На сколько дней Вы хотите продлить аренду комнаты?\n\n\
	Вы можете продлить аренду максимум на %d дней!\n\
	Текущая стоимость 1 дня: "cGR"%d"cWH" рублей\n\n\
	"cBLUE"Введите количество дней аренды:", final_max_day, flate[id_flate][flate_people_price]);

	SPD(playerid, DIALOG_CONTINUE_RENT_FLATE, DIALOG_STYLE_INPUT, !""cBLUE"Выбор кол-ва дней аренды", String512, !"Далее", !"Назад");



	return true;
}

stock final_continue_rent_flate(playerid, id_flate, day)
{

	if(pData[playerid][pFlateRent] != id_flate)
		return SendErr(playerid, "Системная ошибка #003 | Обратитесь на форум!");

	new 
		final_money_price = day*flate[id_flate][flate_people_price];

	new 
		fmt_str[200];

	new 
		owner_flate_name[32];

	if(GetPlayerMoneyEx(playerid) < final_money_price) 
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
		show_menu_rent_flate(playerid, id_flate);
		return SendErr(playerid,"У вас недостаточно денежных средств для продления на такое количество дней!");	
	}


	if(flate[id_flate][flate_people_1_id] == pData[playerid][pMysqlID])
	{
		flate[id_flate][flate_people_1_day] = flate[id_flate][flate_people_1_day]+day;

		GetPlayerNameByID(flate[id_flate][flate_owned],owner_flate_name);

		new 
			player_id = GetPlayerID(owner_flate_name);


		if(IsPlayerConnected(player_id))
		{
			if(flate[id_flate][flate_owned] == pData[player_id][pMysqlID] && player_id != playerid)
			{
				SFCM(player_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы получили "cGR"%d"cWH" рублей на банковский счёт за продление аренды "cBLUE"%s"cWH" на "cBLUE"%d"cWH" дней", final_money_price, pData[playerid][pNickname], day);	
				pData[player_id][pBank] += final_money_price;
			}
		}
		else
		{

			format(fmt_str, sizeof(fmt_str), "UPDATE `accounts` SET  `bank` = bank + %i WHERE `id` = '%i'" , final_money_price, flate[id_flate][flate_owned]);
	  		sql_queryEx(zConn, fmt_str, QUERY_THREADED);
		}

		format(fmt_str, sizeof(fmt_str), "Продление аренды квартиры №: %d", flate[id_flate][flate_id]);
		give_money(playerid, -final_money_price, fmt_str);



		SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы успешно продлили аренду комнаты в квартире №%d на "cBLUE"%d"cWH" дней", id_flate+1, day);	

	}
	else if(flate[id_flate][flate_people_2_id] == pData[playerid][pMysqlID])
	{
		flate[id_flate][flate_people_2_day] = flate[id_flate][flate_people_2_day]+day;

		GetPlayerNameByID(flate[id_flate][flate_owned],owner_flate_name);

		new 
			player_id = GetPlayerID(owner_flate_name);


		if(IsPlayerConnected(player_id))
		{
			if(flate[id_flate][flate_owned] == pData[player_id][pMysqlID] && player_id != playerid)
			{
				SFCM(player_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы получили "cGR"%d"cWH" рублей на банковский счёт за продление аренды "cBLUE"%s"cWH" на "cBLUE"%d"cWH" дней", final_money_price, pData[playerid][pNickname], day);	
				pData[player_id][pBank] += final_money_price;
			}
		}
		else
		{

			format(fmt_str, sizeof(fmt_str), "UPDATE `accounts` SET  `bank` = bank + %i WHERE `id` = '%i'" , final_money_price, flate[id_flate][flate_owned]);
	  		sql_queryEx(zConn, fmt_str, QUERY_THREADED);
		}

		format(fmt_str, sizeof(fmt_str), "Продление аренды квартиры №: %d", flate[id_flate][flate_id]);
		give_money(playerid, -final_money_price, fmt_str);


		SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы успешно продлили аренду комнаты в квартире №%d на "cBLUE"%d"cWH" дней", id_flate+1, day);	

	}
	else if(flate[id_flate][flate_people_3_id] == pData[playerid][pMysqlID])
	{
		flate[id_flate][flate_people_3_day] = flate[id_flate][flate_people_3_day]+day;

		GetPlayerNameByID(flate[id_flate][flate_owned],owner_flate_name);

		new 
			player_id = GetPlayerID(owner_flate_name);


		if(IsPlayerConnected(player_id))
		{
			if(flate[id_flate][flate_owned] == pData[player_id][pMysqlID] && player_id != playerid)
			{
				SFCM(player_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы получили "cGR"%d"cWH" рублей на банковский счёт за продление аренды "cBLUE"%s"cWH" на "cBLUE"%d"cWH" дней", final_money_price, pData[playerid][pNickname], day);	
				pData[player_id][pBank] += final_money_price;
			}
		}
		else
		{

			format(fmt_str, sizeof(fmt_str), "UPDATE `accounts` SET  `bank` = bank + %i WHERE `id` = '%i'" , final_money_price, flate[id_flate][flate_owned]);
	  		sql_queryEx(zConn, fmt_str, QUERY_THREADED);
		}

		format(fmt_str, sizeof(fmt_str), "Продление аренды квартиры №: %d", flate[id_flate][flate_id]);
		give_money(playerid, -final_money_price, fmt_str);


		SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы успешно продлили аренду комнаты в квартире №%d на "cBLUE"%d"cWH" дней", id_flate+1, day);	

	}
	else if(flate[id_flate][flate_people_4_id] == pData[playerid][pMysqlID])
	{
		flate[id_flate][flate_people_4_day] = flate[id_flate][flate_people_4_day]+day;

		GetPlayerNameByID(flate[id_flate][flate_owned],owner_flate_name);

		new 
			player_id = GetPlayerID(owner_flate_name);


		if(IsPlayerConnected(player_id))
		{
			if(flate[id_flate][flate_owned] == pData[player_id][pMysqlID] && player_id != playerid)
			{
				SFCM(player_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы получили "cGR"%d"cWH" рублей на банковский счёт за продление аренды "cBLUE"%s"cWH" на "cBLUE"%d"cWH" дней", final_money_price, pData[playerid][pNickname], day);	
				pData[player_id][pBank] += final_money_price;
			}
		}
		else
		{

			format(fmt_str, sizeof(fmt_str), "UPDATE `accounts` SET  `bank` = bank + %i WHERE `id` = '%i'" , final_money_price, flate[id_flate][flate_owned]);
	  		sql_queryEx(zConn, fmt_str, QUERY_THREADED);
		}

		format(fmt_str, sizeof(fmt_str), "Продление аренды квартиры №: %d", flate[id_flate][flate_id]);
		give_money(playerid, -final_money_price, fmt_str);


		SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы успешно продлили аренду комнаты в квартире №%d на "cBLUE"%d"cWH" дней", id_flate+1, day);	

	}


	save_flate(pData[playerid][pFlateRent]);
	return true;
}

stock final_rent_flate(playerid, id_flate)
{
	if(pData[playerid][pFlateRent] != id_flate)
		return SendErr(playerid, "Системная ошибка #002 | Обратитесь на форум!");

	new 
		day_counts;

	if(flate[id_flate][flate_people_1_id] == pData[playerid][pMysqlID])
	{
		day_counts = flate[id_flate][flate_people_1_day];
	}
	else if(flate[id_flate][flate_people_2_id] == pData[playerid][pMysqlID])
	{
		day_counts = flate[id_flate][flate_people_2_day];
	}
	else if(flate[id_flate][flate_people_3_id] == pData[playerid][pMysqlID])
	{
		day_counts = flate[id_flate][flate_people_3_day];
	}
	else if(flate[id_flate][flate_people_4_id] == pData[playerid][pMysqlID])
	{
		day_counts = flate[id_flate][flate_people_4_day];
	}


	format(String512, sizeof(String512), "\
	"cWH"Вы действительно хотите отказаться от аренды комнаты?\n\n\
	- Если Вы откажетесь от аренды, то деньги не будут возвращены\n\
	- Аренда квартиры оплачена на "cBLUE"%d"cWH" дня\n\n\
	"cBLUE"Нажмите 'Далее', чтобы отказаться от аренды", day_counts);

	SPD(playerid, DIALOG_ENG_RENT_FLATE, DIALOG_STYLE_MSGBOX, !""cBLUE"Откат от аренды квартиры", String512, !"Далее", !"Назад");


	return true;
}

stock cancel_rent_flate_p(playerid, id_flate)
{
	if(flate[id_flate][flate_people_1_id] == pData[playerid][pMysqlID])
	{
		flate[id_flate][flate_people_1_id] = -1;
		flate[id_flate][flate_people_1_day] = 0;
	}
	else if(flate[id_flate][flate_people_2_id] == pData[playerid][pMysqlID])
	{
		flate[id_flate][flate_people_2_id] = -1;
		flate[id_flate][flate_people_2_day] = 0;
	}
	else if(flate[id_flate][flate_people_3_id] == pData[playerid][pMysqlID])
	{
		flate[id_flate][flate_people_3_id] = -1;
		flate[id_flate][flate_people_3_day] = 0;
	}
	else if(flate[id_flate][flate_people_4_id] == pData[playerid][pMysqlID])
	{
		flate[id_flate][flate_people_4_id] = -1;
		flate[id_flate][flate_people_4_day] = 0;
	}

	exit_flate(playerid, GetPlayerVirtualWorld(playerid));

	pData[playerid][pFlateRent] = -1;

	UpdatePlayerData(playerid,"flate_rent", pData[playerid][pFlateRent]);

	SendInf(playerid, "Вы отказались от аренды комнат и были выставлены за дверь!");

	format(String512, sizeof(String512), "\
	"cWH"Вы успешно отказались от аренды комнаты\n\n\
	- Деньги за аренду не были возвращены\n\n\
	"cBLUE"Хозяин квартиры выставил Вас за дверь!");

	SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Откат от аренды квартиры", String512, !"Далее", !"Назад");

	return true;
}

stock manage_general_flate_menu(playerid, id_flate)
{

    format(String512, sizeof(String512), "\
    "cGREY"№\t"cGREY"Тип\t"cGREY"Информация\n\
    "cBLUE"1. \t"cWH"Изменение стоимости аренды\t"cBLUE"Изменить\n\
    "cBLUE"2. \t"cWH"Список жильцов в квартире\t"cBLUE"%d жильцов\n\
    "cBLUE"3. \t"cWH"Разрешение на аренду\t"cBLUE"%s", 
    count_people_in_flate(id_flate), (flate[id_flate][flate_people_status]) ? (""cGR"Аренда возможна") : (""cLRED"Аренда запрещена"));
    SPD(playerid, DIALOG_CHANGE_MENU_FLATE, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Жильцы квартиры", String512, !"Выбрать", !"Закрыть"); 

    return true;
}

stock manage_people_flate(playerid, id_flate)
{

	new 
		name_people_1[32],
		name_people_2[32],
		name_people_3[32],
		name_people_4[32];

	GetPlayerNameByID(flate[id_flate][flate_people_1_id], name_people_1);

	if(flate[id_flate][flate_people_1_id] != -1)
	{
		GetPlayerNameByID(flate[id_flate][flate_people_1_id], name_people_1);
	}
	else
	{
		format(name_people_1, 32, "Отсутствует");	
	}
	if(flate[id_flate][flate_people_2_id] != -1)
	{
		GetPlayerNameByID(flate[id_flate][flate_people_2_id], name_people_2);
	}
	else
	{
		format(name_people_2, 32, "Отсутствует");	
	}
	if(flate[id_flate][flate_people_3_id] != -1)
	{
		GetPlayerNameByID(flate[id_flate][flate_people_3_id], name_people_3);
	}
	else
	{
		format(name_people_3, 32, "Отсутствует");	
	}
	if(flate[id_flate][flate_people_4_id] != -1)
	{
		GetPlayerNameByID(flate[id_flate][flate_people_4_id], name_people_4);
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
	flate[id_flate][flate_people_1_day],
	name_people_2,
	flate[id_flate][flate_people_2_day],
	name_people_3,
	flate[id_flate][flate_people_3_day],
	name_people_4,
	flate[id_flate][flate_people_4_day]);
    SPD(playerid, SHOW_CHANGE_MENU_FLATE_PEOP_ALL, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Жильцы квартиры", String512, !"Выбрать", !"Закрыть"); 


	return true;
}

alias:fllock("flatelock");
CMD:fllock(playerid)
{

	new 
		id_flate = pData[playerid][pFlate];

	update_lock_flate(playerid, id_flate);

	return true;
}

stock update_lock_flate(playerid, id_flate)
{
	if(flate[id_flate][flate_lock] == 1)
	{
		flate[id_flate][flate_lock] = 2;
		SendSucc(playerid, "Вы успешно "cLRED"закрыли"cWH" двери в квартире!");

		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_house_4", 4000);
	}
	else
	{
		flate[id_flate][flate_lock] = 1;
		SendSucc(playerid, "Вы успешно "cGR"открыли"cWH" двери в квартире!");

		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_house_2", 4000);
	}

	flate_panel_change(playerid, id_flate);	
	return true;
}

stock menu_update_flate(playerid, id_flate)
{
    format(String512, sizeof(String512), "\
    "cGREY"Пункт\t"cGREY"Стоимость\t"cGREY"Статус улучшения\n\
    "cBLUE"1. "cWH"Шкаф\t"cGR"%d рублей\t%s\n\
    "cBLUE"2. "cWH"Сейф\t"cGR"%d рублей\t%s\n\
    "cBLUE"3. "cWH"Подселение жильцов\t"cGR"%d рублей\t%s\n\
    "cBLUE"4. "cWH"Субсидии\t"cGR"%d рублей\t%s",
    PRICE_BUY_SHKAF_FLATE, (flate[id_flate][wardrobe_status]) ? (""cGR"Улучшение куплено") : (""cLRED"Улучшение не куплено"),
    PRICE_BUY_SEIF_ONE, get_flate_seif(id_flate),
    PRICE_BUY_PEOPLE, (flate[id_flate][flate_status_people]) ? (""cGR"Улучшение куплено") : (""cLRED"Улучшение не куплено"),
    PRICE_BUY_SUBSIDII, (flate[id_flate][flate_subsidii_status]) ? (""cGR"Улучшение куплено") : (""cLRED"Улучшение не куплено"));
    SPD(playerid, SHOW_CHANGE_MENU_FLATE_UPGRADE, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Магазин оружия:", String512, !"Выбрать", !"Закрыть"); 

	return true;
}

stock show_flate_info_big(playerid, id_flate)
{

	static 
		h_class[24],
		h_owner[24];

	format(h_class, 24, "%s", get_flate_class(id_flate));

	if(flate[id_flate][flate_owned] != -1)
	{
		GetPlayerNameByID(flate[id_flate][flate_owned], flate[id_flate][flate_owner]);
		format(h_owner, 24, flate[id_flate][flate_owner]);
	}
	else
	{
		format(h_owner, 24, "Государство");	
	}


    format(String1024, sizeof(String1024), "\
    "cBLUE"- "cWH"Номер квартиры\t\t"cBLUE"%d\n\
    "cBLUE"- "cWH"Класс квартиры\t\t"cBLUE"%s\n\
    "cBLUE"- "cWH"Владелец\t\t\t"cBLUE"%s\n\
    "cBLUE"- "cWH"Двери\t\t\t%s\n\
    "cBLUE"- "cWH"Стоимость\t\t\t"cGR"%d рублей\n\
    "cBLUE"- "cWH"Налог на квартиру\t\t"cGR"%d рублей\n\
    "cWH"\n\
    "cBLUE"- "cWH"Шкаф\t\t\t\t%s\n\
    "cBLUE"- "cWH"Сейф\t\t\t\t%s\n\n\
    "cBLUE"- "cWH"Кол-во жильцов\t\t"cBLUE"%d человек\n\
    "cBLUE"- "cWH"Подселение жильцов\t%s\n\
    "cBLUE"- "cWH"Субсидии\t\t\t%s%s",

    id_flate+1,
    h_class,
    h_owner,
    (flate[id_flate][flate_lock] == 1) ? (""cGR"Дверь открыта") : (""cLRED"Дверь закрыта"),
    flate[id_flate][flate_price], 
    flate[id_flate][flate_takings],
    (flate[id_flate][wardrobe_status]) ? (""cGR"Улучшение куплено") : (""cLRED"Улучшение не куплено"),
    get_flate_seif(id_flate),
    count_people_in_flate(id_flate), (flate[id_flate][flate_status_people]) ? (""cGR"Улучшение куплено") : (""cLRED"Улучшение не куплено"),
    (flate[id_flate][flate_subsidii_status]) ? (""cGR"Улучшение куплено") : (""cLRED"Улучшение не куплено"));
    SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Информация о квартире", String1024, !"Закрыть", ""); 


	return true;
}

stock sell_flate_menu(playerid, id_flate)
{


	return true;
}

stock count_people_in_flate(id_flate)
{
	new 
		all_flate_people;

	if(flate[id_flate][flate_people_1_id] != -1)
	{	
		all_flate_people++;
	}
	if(flate[id_flate][flate_people_2_id] != -1)
	{	
		all_flate_people++;
	}
	if(flate[id_flate][flate_people_3_id] != -1)
	{	
		all_flate_people++;
	}
	if(flate[id_flate][flate_people_4_id] != -1)
	{	
		all_flate_people++;
	}

	return all_flate_people;
}

stock mute_flate_start_rent(playerid, id_flate)
{
	if(flate[id_flate][flate_owned] == pData[playerid][pMysqlID])
		return flate_info(playerid, id_flate);

	if(flate[id_flate][flate_people_1_id] != -1 && flate[id_flate][flate_people_2_id] != -1 && flate[id_flate][flate_people_3_id] != -1 && flate[id_flate][flate_people_4_id] != -1)
	{
		SendErr(playerid, "Все комнаты в квартире заняты и аренда комнаты невозможна!");
		return flate_info(playerid, id_flate);
	}

	if(pData[playerid][pFlateRent] != -1)
		return SendErr(playerid, "Вы уже арендуете дом или квартиру!");
	if(pData[playerid][pFlate] != -1)
		return SendErr(playerid, "Вы уже владеете домом или квартирой!");	
	if(pData[playerid][pHouse] != -1)
		return SendErr(playerid, "Вы уже владеете домом или квартирой!");	
	if(pData[playerid][pHouseRent] != -1)
		return SendErr(playerid, "Вы уже арендуете дом или квартиру!");	

	if(pData[playerid][pHotelRoom] != -1)
	{	
		flate_info(playerid, id_flate);
		return SendErr(playerid, "Вы уже арендуете номер в отеле!");
	}
 
	

	new 
		fmt_str[550];

	format(fmt_str, 550, "\
	"cWH"На сколько дней Вы хотите снять комнату?\n\n\
	Максимальное кол-во дней аренды: 30 дней\n\
	Минимальное кол-во дней аренды: 3 дня\n\n\
	Текущая стоимость 1 дня: "cGR"%d"cWH" рублей\n\n\
	"cBLUE"Введите количество дней аренды:", flate[id_flate][flate_people_price]);

	SPD(playerid, DIALOG_SELECT_FLATE_DAY_R, DIALOG_STYLE_INPUT, !""cBLUE"Выбор кол-ва дней аренды", fmt_str, !"Далее", !"Назад");



	return true;
}

stock rent_comnat_flate(playerid, id_flate, day)
{


	if(flate[id_flate][flate_owned] == pData[playerid][pMysqlID])
		return flate_info(playerid, id_flate);

	if(flate[id_flate][flate_people_1_id] != -1 && flate[id_flate][flate_people_2_id] != -1 && flate[id_flate][flate_people_3_id] != -1 && flate[id_flate][flate_people_4_id] != -1)
	{
		SendErr(playerid, "Все комнаты в квартире заняты и аренда комнаты невозможна!");
		return flate_info(playerid, id_flate);
	}

	if(GetPlayerMoneyEx(playerid) < day*flate[id_flate][flate_people_price]) 
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
		return SendErr(playerid,"У вас недостаточно денежных средств для аренды на такое количество дней!");	
	}

	new 
		final_money_price = day*flate[id_flate][flate_people_price];

	new 
		fmt_str[200];

	new 
		owner_flate_name[32];

	if(flate[id_flate][flate_people_1_id] == -1)
	{
		flate[id_flate][flate_people_1_id] = pData[playerid][pMysqlID];
		flate[id_flate][flate_people_1_day] = day;

		pData[playerid][pFlateRent] = id_flate;

		UpdatePlayerData(playerid,"flate_rent", pData[playerid][pFlateRent]);


		GetPlayerNameByID(flate[id_flate][flate_owned],owner_flate_name);

		new 
			player_id = GetPlayerID(owner_flate_name);


		if(IsPlayerConnected(player_id))
		{
			if(flate[id_flate][flate_owned] == pData[player_id][pMysqlID] && player_id != playerid)
			{
				SFCM(player_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы получили "cGR"%d"cWH" рублей на банковский счёт за аренду комнаты "cBLUE"%s"cWH" на "cBLUE"%d"cWH" дней", final_money_price, pData[playerid][pNickname], day);	
				pData[player_id][pBank] += final_money_price;
			}
		}
		else
		{

			format(fmt_str, sizeof(fmt_str), "UPDATE `accounts` SET  `bank` = bank + %i WHERE `id` = '%i'" , final_money_price, flate[id_flate][flate_owned]);
	  		sql_queryEx(zConn, fmt_str, QUERY_THREADED);
		}

		format(fmt_str, sizeof(fmt_str), "Аренда квартиры №: %d", flate[id_flate][flate_id]);
		give_money(playerid, -final_money_price, fmt_str);

		save_flate(pData[playerid][pFlateRent]);
		SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы успешно арендовали комнату в квартире №%d на "cBLUE"%d"cWH" дней", id_flate+1, day);	
		return true;
	}
	else if(flate[id_flate][flate_people_2_id] == -1)
	{
		flate[id_flate][flate_people_2_id] = pData[playerid][pMysqlID];
		flate[id_flate][flate_people_2_day] = day;
		pData[playerid][pFlateRent] = id_flate;

		UpdatePlayerData(playerid,"flate_rent", pData[playerid][pFlateRent]);


		GetPlayerNameByID(flate[id_flate][flate_owned],owner_flate_name);

		new 
			player_id = GetPlayerID(owner_flate_name);

		if(IsPlayerConnected(player_id))
		{
			if(flate[id_flate][flate_owned] == pData[player_id][pMysqlID] && player_id != playerid)
			{
				SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы получили "cGR"%d"cWH" рублей на банковский счёт за аренду комнаты "cBLUE"%s"cWH" на "cBLUE"%d"cWH" дней", final_money_price, pData[playerid][pNickname], day);	
				pData[player_id][pBank] += final_money_price;
			}
		}
		else
		{

			format(fmt_str, sizeof(fmt_str), "UPDATE `accounts` SET  `bank` = bank + %i WHERE `id` = '%i'" , final_money_price, flate[id_flate][flate_owned]);
	  		sql_queryEx(zConn, fmt_str, QUERY_THREADED);
		}

		format(fmt_str, sizeof(fmt_str), "Аренда квартиры №: %d", flate[id_flate][flate_id]);
		give_money(playerid, -final_money_price, fmt_str);

		save_flate(pData[playerid][pFlateRent]);
		SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы успешно арендовали комнату в квартире №%d на "cBLUE"%d"cWH" дней", id_flate+1, day);	
		return true;
	}
	else if(flate[id_flate][flate_people_3_id] == -1)
	{
		flate[id_flate][flate_people_3_id] = pData[playerid][pMysqlID];	
		flate[id_flate][flate_people_3_day] = day;

		pData[playerid][pFlateRent] = id_flate;

		UpdatePlayerData(playerid,"flate_rent", pData[playerid][pFlateRent]);


		GetPlayerNameByID(flate[id_flate][flate_owned],owner_flate_name);

		new 
			player_id = GetPlayerID(owner_flate_name);

		if(IsPlayerConnected(player_id))
		{
			if(flate[id_flate][flate_owned] == pData[player_id][pMysqlID] && player_id != playerid)
			{
				SFCM(player_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы получили "cGR"%d"cWH" рублей на банковский счёт за аренду комнаты "cBLUE"%s"cWH" на "cBLUE"%d"cWH" дней", final_money_price, pData[playerid][pNickname], day);	
				pData[player_id][pBank] += final_money_price;
			}
		}
		else
		{

			format(fmt_str, sizeof(fmt_str), "UPDATE `accounts` SET  `bank` = bank + %i WHERE `id` = '%i'" , final_money_price, flate[id_flate][flate_owned]);
	  		sql_queryEx(zConn, fmt_str, QUERY_THREADED);
		}

		format(fmt_str, sizeof(fmt_str), "Аренда квартиры №: %d", flate[id_flate][flate_id]);
		give_money(playerid, -final_money_price, fmt_str);

		save_flate(pData[playerid][pFlateRent]);
		SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы успешно арендовали комнату в квартире №%d на "cBLUE"%d"cWH" дней", id_flate+1, day);	
		return true;
	}
	else if(flate[id_flate][flate_people_4_id] == -1)
	{
		flate[id_flate][flate_people_4_id] = pData[playerid][pMysqlID];
		flate[id_flate][flate_people_4_day] = day;

		pData[playerid][pFlateRent] = id_flate;

		UpdatePlayerData(playerid,"flate_rent", pData[playerid][pFlateRent]);

		GetPlayerNameByID(flate[id_flate][flate_owned],owner_flate_name);

		new 
			player_id = GetPlayerID(owner_flate_name);


		if(IsPlayerConnected(player_id))
		{
			if(flate[id_flate][flate_owned] == pData[player_id][pMysqlID] && player_id != playerid)
			{
				SFCM(player_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы получили "cGR"%d"cWH" рублей на банковский счёт за аренду комнаты "cBLUE"%s"cWH" на "cBLUE"%d"cWH" дней", final_money_price, pData[playerid][pNickname], day);	
				pData[player_id][pBank] += final_money_price;
			}
		}
		else
		{

			format(fmt_str, sizeof(fmt_str), "UPDATE `accounts` SET  `bank` = bank + %i WHERE `id` = '%i'" , final_money_price, flate[id_flate][flate_owned]);
	  		sql_queryEx(zConn, fmt_str, QUERY_THREADED);
		}

		format(fmt_str, sizeof(fmt_str), "Аренда квартиры №: %d", flate[id_flate][flate_id]);
		give_money(playerid, -final_money_price, fmt_str);

		save_flate(pData[playerid][pFlateRent]);
		SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы успешно арендовали комнату в квартире №%d на "cBLUE"%d"cWH" дней", id_flate+1, day);	
		return true;
	}
	save_flate(pData[playerid][pFlateRent]);

	return true;
}


stock buy_update_flate(playerid, id_flate, type)
{

	switch(type)
	{
		case 1:
		{
			pTemp[playerid][offer_time] = 25;

			if(GetPlayerMoneyEx(playerid) < PRICE_BUY_SHKAF_FLATE) 
			{
				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
				pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
				menu_update_flate(playerid, id_flate);
				return SendErr(playerid,"У вас недостаточно денег для покупки улучшения!");			
			}
			if(flate[id_flate][wardrobe_status] == 1)
			{
				pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
				menu_update_flate(playerid, id_flate);
				return SendErr(playerid,"У вас уже куплено данное улучшение!");			
			}				

			flate[id_flate][wardrobe_status] = 1;

			SendSucc(playerid, "Вы успешно приобрели 'Личный шкаф' в свою квартиру!");	

		 	format(String144, sizeof(String144), "Покупка шкафа в квартиру №%d", id_flate);
			give_money(playerid, -PRICE_BUY_SHKAF_FLATE, String144);

			pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;

			menu_update_flate(playerid, id_flate);
		}
		case 2:
		{
			pTemp[playerid][offer_time] = 25;

			if(GetPlayerMoneyEx(playerid) < PRICE_BUY_SEIF_ONE) 
			{
				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
				pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
				menu_update_flate(playerid, id_flate);
				return SendErr(playerid,"У вас недостаточно денег для покупки улучшения!");			
			}
			if(flate[id_flate][safe_flate_status] == 3)
			{
				pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
				menu_update_flate(playerid, id_flate);
				return SendErr(playerid,"У вас уже куплен самый большой сейф!");			
			}				


			if(flate[id_flate][safe_flate_status] == 0)
			{
				SendSucc(playerid, "Вы успешно приобрели 'Новый маленький сейф' в свою квартиру!");	
				flate[id_flate][safe_flate_status] = 1;
			}
			else if(flate[id_flate][safe_flate_status] == 1)
			{
				SendSucc(playerid, "Вы успешно приобрели 'Новый средний сейф' в свою квартиру!");	
				flate[id_flate][safe_flate_status] = 2;
			}
			else if(flate[id_flate][safe_flate_status] == 2)
			{
				SendSucc(playerid, "Вы успешно приобрели 'Новый большой сейф' в свою квартиру!");	
				flate[id_flate][safe_flate_status] = 3;
			}

			SendInf(playerid, "Стандартный пароль сейфа - 1111");

		 	format(String144, sizeof(String144), "Покупка сейфа в квартиру №%d", id_flate);
			give_money(playerid, -PRICE_BUY_SEIF_ONE, String144);

			pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;

			menu_update_flate(playerid, id_flate);
		}
		case 3:
		{
			pTemp[playerid][offer_time] = 25;

			if(GetPlayerMoneyEx(playerid) < PRICE_BUY_PEOPLE) 
			{
				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
				pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
				menu_update_flate(playerid, id_flate);
				return SendErr(playerid,"У вас недостаточно денег для покупки улучшения!");			
			}
			if(flate[id_flate][flate_status_people] == 1)
			{
				pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
				menu_update_flate(playerid, id_flate);
				return SendErr(playerid,"У вас уже куплено улучшение по подселению жильцов");			
			}				


			SendSucc(playerid, "Вы успешно приобрели 'Возможность подселения' в свою квартиру!");	
			flate[id_flate][flate_status_people] = 1;

		 	format(String144, sizeof(String144), "Покупка возможности подселения в квартиру №%d", id_flate);
			give_money(playerid, -PRICE_BUY_PEOPLE, String144);

			pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;

			menu_update_flate(playerid, id_flate);
		}
		case 4:
		{
			pTemp[playerid][offer_time] = 25;

			if(GetPlayerMoneyEx(playerid) < PRICE_BUY_SUBSIDII) 
			{
				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
				pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
				menu_update_flate(playerid, id_flate);
				return SendErr(playerid,"У вас недостаточно денег для покупки улучшения!");			
			}
			if(flate[id_flate][flate_subsidii_status] == 1)
			{
				pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
				menu_update_flate(playerid, id_flate);
				return SendErr(playerid,"У вас уже куплено улучшение по уменьшению налогов!");			
			}				


			SendSucc(playerid, "Вы успешно приобрели 'Уменьшение налогов' для своего квартиры!");	
			flate[id_flate][flate_subsidii_status] = 1;

			//give_money(playerid, -PRICE_BUY_SUBSIDII, "Покупка уменьших налогов в квартиру!");

		 	format(String144, sizeof(String144), "Покупка уменьших налогов в квартиру №%d", id_flate);
			give_money(playerid, -PRICE_BUY_SUBSIDII, String144);

			pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;

			menu_update_flate(playerid, id_flate);
		}
	}


	save_flate(id_flate);
	return true;
}

stock dialog_all_flate(playerid, dialogid, response, listitem, inputtext[])
{

	switch(dialogid)
	{
		case DIALOG_CHANGE_PRICE_P_F:
		{
			new 
				id_flate = pData[playerid][pFlate];

			if(opcode) FormattedMessage(playerid, -1, "[debug] dialog price rent house: №%d", id_flate);

			if(!response)
				return true;

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверную стоимость!");
				return manage_people_flate_p(playerid, id_flate);
			}

			new 
				count_money = strval(inputtext);


			if(count_money < 500 || count_money > 15000)
			{
			    SendErr(playerid,"От 500 до 15000 рублей за 1 сутки проживания!");
				return manage_people_flate_p(playerid, id_flate);
			}	

			flate[id_flate][flate_people_price] = count_money;

			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Новая цена 1 дня аренды комнаты - "cGR"%d"cWH" рублей", count_money);	

			manage_general_flate_menu(playerid, id_flate);

		}
		case DIALOG_SELECT_FLATE_DAY_R:
		{
			new 
				id_flate;
				
			if(!id_flate || id_flate == -1)
			{
				id_flate = pTemp[playerid][area_item_id];
			}
			else
			{
				id_flate = GetPVarIntNew(playerid, "flate_id_active");
			}

			if(opcode) FormattedMessage(playerid, -1, "[debug] dialog select day rent house: №%d", id_flate);

			if(!response)
				return flate_info(playerid, id_flate);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное количество дней!");
				return flate_info(playerid, id_flate);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное количество дней!");
				return flate_info(playerid, id_flate);	
			}

			new 
				count_money = strval(inputtext);


			if(count_money < 3 || count_money > 30)
			{
			    SendErr(playerid,"От 3 до 30 дней!");
				return flate_info(playerid, id_flate);
			}	

			if(GetPlayerMoneyEx(playerid) < count_money*flate[id_flate][flate_people_price]) 
			{
				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
				return SendErr(playerid,"У вас недостаточно денежных средств для аренды на такое количество дней!");	
			}

			rent_comnat_flate(playerid, id_flate, count_money);

		}
		case DIALOG_CHANGE_MENU_FLATE:
		{

			new 
				id_flate = pData[playerid][pFlate];

			if(opcode) FormattedMessage(playerid, -1, "[debug] dialog show manage rent house: №%d", id_flate);

			if(!response)
				return flate_panel_change(playerid, id_flate);	


			switch(listitem)
			{
				case 0: return manage_people_flate_p(playerid, id_flate);
				case 1: return manage_people_flate(playerid, id_flate);
				case 2:
				{
					if(flate[id_flate][flate_people_status] == 1)
					{
						flate[id_flate][flate_people_status] = 0;
						SendSucc(playerid, "Вы запретили возможность подселения жильцов в Вашу квартиру!");
						SendInf(playerid, "Жильцы, которые уже снимают комнату в квартире, доживут арендованные дни!");


						return flate_panel_change(playerid, id_flate);	
					}
					else
					{
						flate[id_flate][flate_people_status] = 1;
						SendSucc(playerid, "Вы разрешили возможность подселения жильцов в Вашу квартиру!");	

						return flate_panel_change(playerid, id_flate);					
					}
				}
			
			}			
		}
		case SHOW_CHANGE_MENU_FLATE_PEOP_ALL:
		{
			new 
				id_flate = pData[playerid][pFlate];

			if(!response)
				return flate_panel_change(playerid, id_flate);	

			flate_panel_change(playerid, id_flate);					
		}

		case DIALOG_ACCEPT_SELL_FLATE:
		{
			new 
				id_flate = pData[playerid][pFlate];

			if(!response)
				return flate_panel_change(playerid, id_flate);	

			sell_flate(playerid, id_flate);				
		}	

		case SHOW_CHANGE_MENU_FLATE_1:
		{
			if(!response)
				return true;	

			new 
				id_flate = pData[playerid][pFlate];

			if(opcode) FormattedMessage(playerid, -1, "[debug] dialog change menu house: №%d", id_flate);


			switch(listitem)
			{
				case 0: return show_flate_info_big(playerid, id_flate);
				case 1: return update_lock_flate(playerid, id_flate);
				case 2: return menu_update_flate(playerid, id_flate);
				case 3: return sell_flate_accept(playerid);
				case 5: return exit_flate(playerid, GetPVarIntNew(playerid, "flate_id_active"));
			
			}

		}
		case SHOW_CHANGE_MENU_FLATE_2:
		{
			if(!response)
				return true;	

			new 
				id_flate = pData[playerid][pFlate];

			if(opcode) FormattedMessage(playerid, -1, "[debug] menu house id house: №%d", id_flate);

			switch(listitem)
			{
				case 0: return show_flate_info_big(playerid, id_flate);
				case 1: return update_lock_flate(playerid, id_flate);
				case 2: return menu_update_flate(playerid, id_flate);
				case 3: return sell_flate_accept(playerid);
				case 4: return manage_general_flate_menu(playerid, id_flate);
				case 6: return exit_flate(playerid, GetPVarIntNew(playerid, "flate_id_active"));
			
			}

		}

		case SHOW_CHANGE_MENU_FLATE_3:
		{
			if(!response)
				return true;	

			new 
				id_flate = GetPVarIntNew(playerid, "flate_id_active");


			if(opcode) FormattedMessage(playerid, -1, "[debug] menu house id house: №%d", id_flate);

			switch(listitem)
			{
				case 0: return show_flate_info_big(playerid, id_flate);
				case 2: return exit_flate(playerid, GetPVarIntNew(playerid, "flate_id_active"));
			
			}			
		}
		case SHOW_CHANGE_MENU_FLATE_4:
		{
			if(!response)
				return true;	

			new 
				id_flate = pData[playerid][pFlateRent];


			if(opcode) FormattedMessage(playerid, -1, "[debug] menu house id house: №%d", id_flate);

			switch(listitem)
			{
				case 0: return show_flate_info_big(playerid, id_flate);
				case 1: return show_menu_rent_flate(playerid, id_flate);
				case 3: return exit_flate(playerid, GetPVarIntNew(playerid, "flate_id_active"));
			
			}			
		} 

		case SHOW_CHANGE_MENU_FLATE_UPGRADE:
		{
			new 
				id_flate = pData[playerid][pFlate];

			if(!response)
				return flate_panel_change(playerid, id_flate);	


			if(opcode) FormattedMessage(playerid, -1, "[debug] menu house upgrade id: №%d", id_flate);

			switch(listitem)
			{
				case 0: return buy_update_flate(playerid, id_flate, 1);
				case 1: return buy_update_flate(playerid, id_flate, 2);
				case 2: return buy_update_flate(playerid, id_flate, 3);
				case 3: return buy_update_flate(playerid, id_flate, 4);
			
			}

		}
		case DIALOG_BUY_FLATE:
		{
			if(!response)
				return true;	

			new 
				id_flate = pTemp[playerid][area_item_id];

			if(opcode) FormattedMessage(playerid, -1, "[debug] menu buy house id: №%d", id_flate);

			buy_flate(playerid, id_flate);	
		}
		case DIALOG_INFO_FLATE:
		{
			if(!response)
				return true;	
			new 
				id_flate;

			if(!id_flate)
			{
				id_flate = pTemp[playerid][area_item_id];
			}
			else
			{
				id_flate = GetPVarIntNew(playerid, "flate_id_active");
			}

			if(flate[id_flate][flate_lock] == 2 && pData[playerid][pFlate] != id_flate)
			{
				GameTextForPlayer(playerid, "~r~closed", 2000, 3);
				flate_info(playerid, id_flate);
				return SendInf(playerid, "Двери квартиры - закрыты. Вы не можете войти!");
			}
			else if(flate[id_flate][flate_lock] == 2 && pData[playerid][pFlate] == id_flate)
			{
				return enter_flate(playerid, id_flate);
			}
			enter_flate(playerid, id_flate);
		}
		case DIALOG_INFO_RENT_FLATE:
		{
			if(!response)
				return true;

			new 
				id_flate;
				
			if(!id_flate || id_flate == -1)
			{
				id_flate = pTemp[playerid][area_item_id];
			}
			else
			{
				id_flate = GetPVarIntNew(playerid, "flate_id_active");
			}


			if(opcode) FormattedMessage(playerid, -1, "[debug] dialog info in the rent people: №%d", id_flate);	

			switch(listitem)
			{
				case 0: return flate_info(playerid, id_flate);
				case 1: return flate_info(playerid, id_flate);
				case 2: return flate_info(playerid, id_flate);
				case 3: return flate_info(playerid, id_flate);
				case 4: return flate_info(playerid, id_flate);
				case 5: return flate_info(playerid, id_flate);
				case 6: return flate_info(playerid, id_flate);
				case 7: return mute_flate_start_rent(playerid, id_flate);
				case 8: return flate_info(playerid, id_flate);
				case 9: return enter_flate(playerid, id_flate);
			
			}
		}
		case DIALOG_FLATE_RENT_P:
		{
			new 
				id_flate; 

			if(pData[playerid][pFlate] == -1 && pData[playerid][pFlateRent] != -1)
			{
				id_flate = pData[playerid][pFlateRent];
			}


			if(!response)
				return flate_panel_change(playerid, id_flate);	

			switch(listitem)
			{
				case 0: return show_menu_rent_flate(playerid, id_flate);
				case 1: return countinue_rent_flate(playerid, id_flate);
				case 2: return final_rent_flate(playerid, id_flate);
			
			}						
		}
		case DIALOG_CONTINUE_RENT_FLATE:
		{
			new 
				id_flate; 

			if(pData[playerid][pFlate] == -1 && pData[playerid][pFlateRent] != -1)
			{
				id_flate = pData[playerid][pFlateRent];
			}


			if(!response)
				return show_menu_rent_flate(playerid, id_flate);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное количество дней!");
				return show_menu_rent_flate(playerid, id_flate);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное количество дней!");
				return show_menu_rent_flate(playerid, id_flate);		
			}

			new 
				count_day = strval(inputtext);

			new 
				max_day = GetPVarIntNew(playerid, "final_max_day_rent");

			if(count_day < 1 || count_day > max_day)
			{
			    SendErr(playerid,"Неверное кол-во дней!");
				return show_menu_rent_flate(playerid, id_flate);
			}	

			if(GetPlayerMoneyEx(playerid) < count_day*flate[flate_id][flate_people_price]) 
			{	
				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
				show_menu_rent_flate(playerid, id_flate);
				return SendErr(playerid,"У вас недостаточно денежных средств для продления аренды на такое количество дней!");	
			}

			final_continue_rent_flate(playerid, id_flate, count_day);

		}
		case DIALOG_ENG_RENT_FLATE:
		{	
			new 
				id_flate; 

			if(pData[playerid][pFlate] == -1 && pData[playerid][pFlateRent] != -1)
			{
				id_flate = pData[playerid][pFlateRent];
			}

			if(!response)
				return show_menu_rent_flate(playerid, id_flate);

			cancel_rent_flate_p(playerid, id_flate);			
		}

	}
	return true;
}

stock buy_flate(playerid, h)
{

	if(pData[playerid][pFlate] != -1)
		return SendErr(playerid, "Вы не можете купить квартиру, так как у Вас уж есть дом!");

	if(pData[playerid][pFlateRent] != -1 || pData[playerid][pFlateRent] != -1)
		return SendErr(playerid, "Вы уже арендуете дом или квартиру! Откажитесь от аренды для покупки!");

	if(pData[playerid][pFlate] != -1)
		return SendErr(playerid, "Вы уже владеете квартирой!");	

	if(pData[playerid][pHotelRoom] != -1)
		return SendErr(playerid, "Вы уже арендуете номер в отеле!");

	if(pData[playerid][pGarage] != -1)
		return SendErr(playerid, "Вы уже владеете гаражом!");

	if(flate[h][flate_owned] != -1)
		return SendErr(playerid, "Дом недоступен для покупи в данный момент");

	if(GetPlayerMoneyEx(playerid) < flate[h][flate_price]) 
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
		return SendErr(playerid,"У вас недостаточно денежных средств для покупки квартиры!");	
	}


	if(flate[h][flate_sell_status] == 3)
		return SendErr(playerid, "Квартира недоступна для покупки в данный момент, так как она опечатана!");

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_buy_flate", 4000);


	flate[h][flate_owned] = pData[playerid][pMysqlID];
	format(flate[h][flate_owner], 24, pData[playerid][pNickname]);
	flate[h][flate_days] = 3;

	pData[playerid][pFlate] = h;

	if(opcode) FormattedMessage(playerid, -1, "[debug] house buy: %d | flate_owner_sql: %d ", h, flate[h][flate_owned]);

	UpdatePlayerData(playerid,"flate",pData[playerid][pFlate]);	

 	format(String144, sizeof(String144), "Покупка частной квартиры №%d", h);
	give_money(playerid, -flate[h][flate_price], String144);

	save_flate(h);
	update_flate_pickup(h);


	format(String512, sizeof(String512), "\
		"cWH"Поздравляем Вас с приобретением частной квартиры!\n\n\
		Вы купили квартиру "cBLUE"№%d\n\
		"cWH"Ежедневная оплата: "cGR"%d"cWH" рублей\n\n\
		"cWH"Квартира оплачена на "cBLUE"%d"cWH" дней\n\
		Советутем Вам посетить банк для оплаты!",
		pData[playerid][pFlate],
		flate[h][flate_takings], flate[h][flate_days]);
	return SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка квартиры", String512, !"Понял", !"");
}


CMD:addflate(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    new 
    	Float:x,Float:y,Float:z;

    if(sscanf(params, "dddd",params[0], params[1], params[2], params[3])) 
    	return SendInf(playerid, "Используйте: /addflate [Подъезд] [Класс] [Цена] [Плата в день] ");

    if(params[1] < 1 || params[1] > 4) 
    	return SendInf(playerid, "1 - Низкий | 2 - Средний | 3 - Высокий | 4 - Особняк");

    GetPlayerPos(playerid, x, y, z);
    
	static 
		formate_str[310];

    format(formate_str, 310, "INSERT INTO flate(flate_enter_x, flate_enter_y, flate_enter_z, flate_exit_x, flate_exit_y, flate_exit_z, flate_entrance_id, flate_class, flate_price, flate_takings) VALUES ('%f','%f','%f','%f','%f','%f','%d','%d','%d','%d')",
    x, y, z, x, y, z, params[0], params[1], params[2], params[3]);
    sql_queryEx(zConn, formate_str, QUERY_THREADED);	

    formate_str[0] = EOS;

    SendSucc(playerid, "Вы добавили квартиру! Он появится после рестарта");
	return true;
}

CMD:delflate(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    if(sscanf(params, "d",params[0])) 
    	return SendInf(playerid, "Используйте: /delflate [ID квартиры]");

	static 
		formate_str[250];

    format(formate_str, 250, "UPDATE `accounts` SET `flate` = '-1' WHERE `flate` = '%d'", params[0]);
    sql_queryEx(zConn, formate_str, QUERY_THREADED);	
    format(formate_str, 250, "DELETE FROM `flate` WHERE `flate_id` = '%d'", params[0]);
    sql_queryEx(zConn, formate_str, QUERY_THREADED);	

	new 
		fmt_str[350];

    format(fmt_str, sizeof(fmt_str), "Вы успешно удалили квартиру №%d", params[0]);
    SendSucc(playerid, fmt_str);
	return true;
}

CMD:asellflate(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    if(sscanf(params, "ds[32]d",params[0],params[1],params[2])) 
    	return SendInf(playerid, "Используйте: /asellflate [ID квартиры] [Причина] [Возврат денег (1 - вернуть | 2 - не возвращать)]");


	new 
		fmt_str[350];

    format(fmt_str, sizeof(fmt_str), "Вы успешно продали квартиру №%d", params[0]);
    SendSucc(playerid, fmt_str);

	sell_flate_admin(params[0], params[1], params[2]);

	return true;
}

CMD:aeditflate(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

	new 
		type, count, flate_ids;

	new 
		fmt_str[350];

	if(sscanf(params, "ddd", flate_ids, type, count))
	{
		SendInf(playerid, "Используйте:/aeditflate "cWH"[ID квартиры] "cORANGE"[Тип] "cWH"[Значение]");
		SendInf(playerid, "[1] Класс квартиры [2] Гос.стоимость квартиры [3] Налог [4] Кол-во дней оплаты");
		return true;
	}

	switch(type)
	{
		case 1: 
		{
			flate[flate_ids][flate_class] = count;
		    format(fmt_str, sizeof(fmt_str), "Класс квартиры был обновлен! квартиру №%d | Класс: %s", flate_ids, get_flate_class(flate_ids));
		    SendSucc(playerid, fmt_str);

		}
		case 2: 
		{
			flate[flate_ids][flate_price] = count;
		    format(fmt_str, sizeof(fmt_str), "Гос.Стоимость квартиры была обновлена! квартиру №%d | Новая цена: %d", flate_ids, count);
		    SendSucc(playerid, fmt_str);
		}
		case 3: 
		{
			flate[flate_ids][flate_takings] = count;
		    format(fmt_str, sizeof(fmt_str), "Ежедневная оплата квартиры была обновлена! квартиру №%d | Новая оплата в день: %d", flate_ids, count);
		    SendSucc(playerid, fmt_str);
		}
		case 4: 
		{

			flate[flate_ids][flate_days] = count;
		    format(fmt_str, sizeof(fmt_str), "Кол-во дней оплаты квартиры были обновлены! квартиру №%d | Оплачено на: %d", flate_ids, count);
		    SendSucc(playerid, fmt_str);

		}
	}
	save_flate(flate_ids);
	return true;
}

CMD:gotoflate(playerid, params[])
{
    if(pData[playerid][pAdmin] < 5) 
    	return NoCMD(playerid);

	if(sscanf(params, "d", params[0]))
	{
		SendInf(playerid, "Используйте: /gotoflate "cWH"[ID Квартиры]");
		return true;
	}

	new 
		id_flate = params[0];

	SetPlayerPos(playerid, flate[id_flate][flate_enter_x], flate[id_flate][flate_enter_y], flate[id_flate][flate_enter_z]);
	SetPlayerVirtualWorld(playerid, flate[id_flate][flate_entrance_id]);

	new 
		fmt_str[144];

    format(fmt_str, sizeof(fmt_str), "Вы телепортировались к квартире №%d", id_flate);
    SendSucc(playerid, fmt_str);
	return true;
}

CMD:sellallflate(playerid)
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

	new time = GetTickCount();

	for(new h, idx = all_flates; h < idx; h ++)
	{
	   	flate[h][flate_owned] = -1;
	    flate[h][flate_lock] = 0;
	    
	    flate[h][flate_class] = 1;
	    flate[h][flate_days] = 3;

	    flate[h][flate_people_status] = 0;
	    flate[h][flate_status_people] = 0;	

	    flate[h][safe_flate_status] = 0;
	    flate[h][safe_flate_pass] = 1111;
	    flate[h][safe_flate_money] = 0;
	    flate[h][safe_flate_drugs] = 0;	
	    flate[h][safe_flate_drugs_hard] = 0;

		flate[h][wardrobe_gun_1] = -1;	
		flate[h][wardrobe_gun_2] = -1;	
		flate[h][wardrobe_gun_3] = -1;	
		flate[h][wardrobe_skin_1] = 0;
		flate[h][wardrobe_skin_2] = 0;
		flate[h][wardrobe_skin_3] = 0;

	    flate[h][wardrobe_status] = 0;		
	    flate[h][flate_subsidii_status] = 0;		


		flate[h][flate_people_1_id] = -1;
		flate[h][flate_people_1_day] = 0;
		flate[h][flate_people_2_id] = -1;
		flate[h][flate_people_2_day] = 0;
		flate[h][flate_people_3_id] = -1;
		flate[h][flate_people_3_day] = 0;
		flate[h][flate_people_4_id] = -1;
		flate[h][flate_people_4_day] = 0;

		flate[h][wardrobe_gun_ammo_1] = 0;
		flate[h][wardrobe_gun_ammo_2] = 0;
		flate[h][wardrobe_gun_ammo_3] = 0;

		flate[h][wardrobe_status] = 0;

	    update_flate_pickup(h);
	    save_flate(h);
	}

    format(String144, sizeof(String144), "Было продано "cGR"%d"cWH" квартир. Запрос занял: "cGR"%d"cWH" мс", all_flates, GetTickCount()-  time);
    SendSucc(playerid, String144);
	return true;
}

#include <..\..\gamemodes\API\systems\flate_systems\flate_safe_systems.inc>
#include <..\..\gamemodes\API\systems\flate_systems\flate_wardrobe_systems.inc>










