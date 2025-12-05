static const mounth_hotel_stats[][] =
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



callback:: load_hotel_all()
{
	new Result:hotel_all_biz = sql_queryEx(zConn, "SELECT * FROM `hotel` ORDER BY `hotel_id`", QUERY_CACHED);

	new all_hotel_biz = sql_num_rows(hotel_all_biz);

	new time = GetTickCount();


 	for(new i; i < all_hotel_biz; i++)
	{
		hotel[i][hotel_id]  = sql_get_field_assoc_int_ex(hotel_all_biz, i, "hotel_id"); 

		sql_get_field_assoc_ex(hotel_all_biz, i,"hotel_name", hotel[i][hotel_name], 25);

		hotel[i][hotel_owned]  = sql_get_field_assoc_int_ex(hotel_all_biz, i, "hotel_owned_id"); 

		hotel[i][hotel_class]  = sql_get_field_assoc_int_ex(hotel_all_biz, i, "hotel_class"); 
		hotel[i][hotel_price]  = sql_get_field_assoc_int_ex(hotel_all_biz, i, "hotel_price"); 
		hotel[i][hotel_lock]  = sql_get_field_assoc_int_ex(hotel_all_biz, i, "hotel_lock"); 
		hotel[i][hotel_days]  = sql_get_field_assoc_int_ex(hotel_all_biz, i, "hotel_day"); 

		hotel[i][hotel_price_rent]  = sql_get_field_assoc_int_ex(hotel_all_biz, i, "hotel_price_rent"); 

		hotel[i][hotel_bank]  = sql_get_field_assoc_int_ex(hotel_all_biz, i, "hotel_bank"); 

  		hotel[i][hotel_enter_x] = sql_get_field_assoc_float_ex(hotel_all_biz, i, "hotel_enter_x");
  		hotel[i][hotel_enter_y] = sql_get_field_assoc_float_ex(hotel_all_biz, i, "hotel_enter_y");
  		hotel[i][hotel_enter_z] = sql_get_field_assoc_float_ex(hotel_all_biz, i, "hotel_enter_z");

  		hotel[i][hotel_exit_x] = sql_get_field_assoc_float_ex(hotel_all_biz, i, "hotel_exit_x");
  		hotel[i][hotel_exit_y] = sql_get_field_assoc_float_ex(hotel_all_biz, i, "hotel_exit_y");
  		hotel[i][hotel_exit_z] = sql_get_field_assoc_float_ex(hotel_all_biz, i, "hotel_exit_z");

  		hotel[i][hotel_enter_price] = sql_get_field_assoc_int_ex(hotel_all_biz, i, "hotel_enter_price"); 

  		hotel[i][hotel_finka_ogran] = sql_get_field_assoc_int_ex(hotel_all_biz, i, "hotel_finka_ogran"); 
  		hotel[i][hotel_finka_day] = sql_get_field_assoc_int_ex(hotel_all_biz, i, "hotel_finka_day"); 


  		hotel[i][hotel_sell_day_payday] = sql_get_field_assoc_int_ex(hotel_all_biz, i, "hotel_sell_day_payday"); 
  		hotel[i][hotel_status_sell] = sql_get_field_assoc_int_ex(hotel_all_biz, i, "hotel_status_sell"); 


		create_dynamic_area(hotel[i][hotel_enter_x], hotel[i][hotel_enter_y], hotel[i][hotel_enter_z], -1, i, HOTEL_ENTER);

		create_dynamic_area(hotel_int_exit_coord[1][0], hotel_int_exit_coord[1][1], hotel_int_exit_coord[1][2], -1, i, HOTEL_EXIT);

		CreateDynamic3DTextLabel(""cWH"Выход из отеля\n"cBLUE"[ALT]",-1, \
		hotel_int_exit_coord[1][0], hotel_int_exit_coord[1][1], hotel_int_exit_coord[1][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	

		
		hotel[i][hotel_pickup] = CreateDynamicPickup(13702, 23, hotel[i][hotel_enter_x], hotel[i][hotel_enter_y], hotel[i][hotel_enter_z], -1, -1, -1, STREAM_DISTANCE_DYNAMIC_PICKUP);
		hotel[i][hotel_mapicon] = CreateDynamicMapIcon(hotel[i][hotel_enter_x], hotel[i][hotel_enter_y], hotel[i][hotel_enter_z], 24, COLOR_WHITE, 0, -1, -1, 100.0);

		new
			h_class[24],
			h_owner[24];

		format(h_class, 24, "%s", get_hotel_class(i));

		if(hotel[i][hotel_owned] != -1)
		{
			GetPlayerNameByID(hotel[i][hotel_owned], hotel[i][hotel_owner]);
			format(h_owner, 24, hotel[i][hotel_owner]);
		}
		else
		{
			format(h_owner, 24, "Государство");	
		}


		format(String256, sizeof(String256), "\
			"cBLUE"Отель:\n"cWH"%s\n\n\
			"cBLUE"Владелец: "cWH"%s\n\
			"cBLUE"Класс отеля: "cWH"%s\n\
			"cBLUE"Cтоимость входа: "cWH"%dр\n\n\
			"cBLUE"[ALT]", hotel[i][hotel_name], h_owner, h_class, hotel[i][hotel_enter_price]);

		hotel[i][hotel_pickup_text] = CreateDynamic3DTextLabel(String256, -1, hotel[i][hotel_enter_x], hotel[i][hotel_enter_y], hotel[i][hotel_enter_z], 5.0);


  		all_hotels++;
	}

	create_other_hotel();

	printf("[Отели]: <%i из %i>. Времени затрачено: <%d мс>" ,all_hotel_biz, all_hotels, GetTickCount()-  time);

	return true;
} 

stock create_other_hotel()
{


	CreateDynamic3DTextLabel(""cWH"Лифт\n"cBLUE"[ALT]",-1, \
	HOTEL_LOW_INT_LIFT_1, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	CreateDynamic3DTextLabel(""cWH"Лифт\n"cBLUE"[ALT]",-1, \
	HOTEL_LOW_INT_LIFT_2, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	CreateDynamic3DTextLabel(""cWH"Лифт\n"cBLUE"[ALT]",-1, \
	HOTEL_LOW_INT_LIFT_3, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	CreateDynamic3DTextLabel(""cWH"Лифт\n"cBLUE"[ALT]",-1, \
	HOTEL_LOW_INT_LIFT_4, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	

	CreateDynamicPickup(1239, 23, HOTEL_LOW_INT_RESEPTION, -1);	

	CreateDynamicPickup(13702, 23, HOTEL_LOW_INT_LIFT_1, -1);
	CreateDynamicPickup(13702, 23, HOTEL_LOW_INT_LIFT_2, -1);
	CreateDynamicPickup(13702, 23, HOTEL_LOW_INT_LIFT_3, -1);
	CreateDynamicPickup(13702, 23, HOTEL_LOW_INT_LIFT_4, -1);

	hotel_reception = CreateDynamicSphere(HOTEL_LOW_INT_RESEPTION, 1.0, -1,-1);

	hotel_lift[0] = CreateDynamicSphere(HOTEL_LOW_INT_LIFT_1, 1.0, -1,-1);
	hotel_lift[1] = CreateDynamicSphere(HOTEL_LOW_INT_LIFT_2, 1.0, -1,-1);

	hotel_lift[2] = CreateDynamicSphere(HOTEL_LOW_INT_LIFT_3, 1.0, -1,-1);
	hotel_lift[3] = CreateDynamicSphere(HOTEL_LOW_INT_LIFT_4, 1.0, -1,-1);


	CreateDynamic3DTextLabel(""cWH"Ресепшен Отеля",-1, \
	HOTEL_LOW_INT_RESEPTION, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	

	CreateDynamicPickup(13702, 23, hotel_int_exit_coord[1][0], hotel_int_exit_coord[1][1], hotel_int_exit_coord[1][2], -1);
	CreateDynamicPickup(13702, 23, hotel_room_int_exit_coord[1][0], hotel_room_int_exit_coord[1][1], hotel_room_int_exit_coord[1][2], -1);
	return true;
}

callback:: save_hotel(h)
{

    format(String1024, sizeof(String1024), "UPDATE `hotel` SET \
    	hotel_owned_id = '%d',\
    	hotel_class = '%d',\
    	hotel_price = '%d',\
    	hotel_lock = '%d',\
    	hotel_day = '%d',\
    	hotel_enter_x = '%f',\
    	hotel_enter_y = '%f',\
    	hotel_enter_z = '%f',\
    	hotel_exit_x = '%f',\
    	hotel_exit_y = '%f',\
    	hotel_exit_z = '%f',\
    	hotel_enter_price = '%d',\
		hotel_finka_ogran = '%d',\
		hotel_finka_day = '%d',\
		hotel_sell_day_payday = '%d',\
		hotel_status_sell = '%d',\
    	hotel_bank = '%d'\
    	WHERE hotel_id = '%d'",
    	hotel[h][hotel_owned],
    	hotel[h][hotel_class],
    	hotel[h][hotel_price],
    	hotel[h][hotel_lock],
    	hotel[h][hotel_days],
    	hotel[h][hotel_enter_x],
    	hotel[h][hotel_enter_y],
    	hotel[h][hotel_enter_z],
    	hotel[h][hotel_exit_x],
    	hotel[h][hotel_exit_y],
    	hotel[h][hotel_exit_z],
    	hotel[h][hotel_enter_price],

    	hotel[h][hotel_finka_ogran],
    	hotel[h][hotel_finka_day],
    	
		hotel[h][hotel_sell_day_payday],
		hotel[h][hotel_status_sell],

    	hotel[h][hotel_bank],
    	hotel[h][hotel_id]);

    sql_queryEx(zConn, String1024, QUERY_THREADED);	

    return true;
}

stock update_hotel_text_3d(i)
{
	new
		h_class[24],
		h_owner[24];

	format(h_class, 24, "%s", get_hotel_class(i));

	if(hotel[i][hotel_owned] != -1)
	{
		GetPlayerNameByID(hotel[i][hotel_owned], hotel[i][hotel_owner]);
		format(h_owner, 24, hotel[i][hotel_owner]);
	}
	else
	{
		format(h_owner, 24, "Государство");	
	}


	format(String256, sizeof(String256), "\
		"cBLUE"Отель:\n"cWH"%s\n\n\
		"cBLUE"Владелец: "cWH"%s\n\
		"cBLUE"Класс отеля: "cWH"%s\n\
		"cBLUE"Cтоимость входа: "cWH"%dр\n\n\
		"cBLUE"[ALT]", hotel[i][hotel_name], h_owner, h_class, hotel[i][hotel_enter_price]);
	UpdateDynamic3DTextLabelText(hotel[i][hotel_pickup_text], -1, String256);

	if(hotel[i][hotel_status_sell] == 3)
	{
		format(String256, sizeof(String256), "\
			"cBLUE"Отель:\n"cWH"%s\n\n\
			"cORANGE"Отель опечатан\n\n\
			"cBLUE"Владелец: "cWH"%s\n\
			"cBLUE"Класс отеля: "cWH"%s\n\
			"cBLUE"Cтоимость входа: "cWH"%dр\n\n\
			"cBLUE"[ALT]", hotel[i][hotel_name], h_owner, h_class, hotel[i][hotel_enter_price]);
		UpdateDynamic3DTextLabelText(hotel[i][hotel_pickup_text], -1, String256);		
	}

	return true;
}

stock sell_hotel_payday(f)
{
	if(hotel[f][hotel_days] >= 0 && hotel[f][hotel_owned] != -1)
		return printf("[HOTEL PAYDAY] Попытка слета!");

	new 
		owner_id = hotel[f][hotel_owned];

	new 
		owner_garage_name[32];


	GetPlayerNameByID(owner_id, owner_garage_name);

	new 
		player_id = GetPlayerID(owner_garage_name);	

	new 
		final_money = floatround(hotel[f][hotel_price]*0.8);


	if(IsPlayerConnected(player_id))
	{
		if(pData[player_id][pHotelOwner] == f)
		{	
			pData[player_id][pHotelOwner] = -1;
			UpdatePlayerData(player_id,"pHotelOwner", pData[player_id][pHotelOwner]);
			SFCM(player_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Ваш Отель был продан за неуплату!");	

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

		format(formate_str, 80, "UPDATE accounts SET pHotelOwner = '-1' WHERE pHotelOwner = '%d'", f);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	

		format(String256,sizeof(String256),"UPDATE `accounts` SET returnmoney = returnmoney + %d WHERE id = '%i'", final_money, f);
		sql_queryEx(zConn, String256, QUERY_THREADED);

		send_off_message(-1, owner_garage_name, "Ваша АЗС была продана государству за неуплату. Мы вернули 80 процентов (/returnmoney)");
	}




	hotel[f][hotel_owned] = -1;	
	hotel[f][hotel_bank] = 0;

	hotel[f][hotel_status_sell] = 3;
	hotel[f][hotel_sell_day_payday] = RandomEx(2, 22);	

	update_hotel_text_3d(f);
	save_hotel(f);
	return true;
}

stock sell_hotel_accept(playerid)
{
	SPD(playerid, DIALOG_ACCEPT_SELL_HOTEL, DIALOG_STYLE_MSGBOX, !""cBLUE"Продажа отеля", !"\
	"cWH"Вы уверены, что хотите продать отель государству?\n\n\
	Вам будет возвращено 80%% от стоимости!", !"Да", !"Нет");

	return true;

}

stock sell_hotel(playerid, f)
{


	if(pData[playerid][pHotelOwner] == f)
	{	

		new 
			final_money = floatround(hotel[f][hotel_price]*0.8);

		pData[playerid][pHotelOwner] = -1;
		UpdatePlayerData(playerid,"pHotelOwner", pData[playerid][pHotelOwner]);

		SendSucc(playerid, "Вы продали отель государству!");

	 	format(String256, sizeof(String256), "Продажа отеля №%d", f);
		give_money(playerid, final_money, String256);


		hotel[f][hotel_owned] = -1;	
		hotel[f][hotel_bank] = 0;

		update_hotel_text_3d(f);
		save_hotel(f);
	}

	return true;
}

stock get_level_hotel_lift(playerid)
{

	new 
		hotel_level = GetPVarIntNew(playerid, "hotel_number_vw");

		

	switch(hotel_level)
	{
		case HOTEL_1:
		{	
			show_menu_lifht(playerid, HOTEL_1);
		}	
		case HOTEL_2:
		{
			show_menu_lifht(playerid, HOTEL_2);
		}
		case HOTEL_3:
		{
			show_menu_lifht(playerid, HOTEL_3);
		}
		case HOTEL_4:
		{
			show_menu_lifht(playerid, HOTEL_4);
		}
	}
	return true;
}

stock show_menu_lifht(playerid, hotel_params)
{
	switch(hotel_params)
	{
		case HOTEL_1:
		{	
			format(String512, sizeof(String512), "\
			"cWH"Холл "cBLUE"(Этаж №1)\n\
			"cWH"Этаж "cBLUE"№2"cWH"\n\
			"cWH"Этаж "cBLUE"№3"cWH"\n\
			"cWH"Этаж "cBLUE"№4"cWH"\n\
			"cWH"Этаж "cBLUE"№5"cWH"\n\
			"cWH"Этаж "cBLUE"№6"cWH"\n\
			"cWH"Этаж "cBLUE"№7"cWH"\n\
			"cWH"Этаж "cBLUE"№8"cWH"\n\
			"cWH"Этаж "cBLUE"№9"cWH"\n\
			"cWH"Этаж "cBLUE"№10"cWH"");	
			SPD(playerid, DIALOG_LIFT_HOTEL_1, DIALOG_STYLE_TABLIST, !""cBLUE"Лифт отеля", String512, !"Выбор", !"Закрыть");	
		}	
		case HOTEL_2:
		{
			format(String512, sizeof(String512), "\
			"cWH"Холл "cBLUE"(Этаж №1)\n\
			"cWH"Этаж "cBLUE"№2\n\
			"cWH"Этаж "cBLUE"№3\n\
			"cWH"Этаж "cBLUE"№4\n\
			"cWH"Этаж "cBLUE"№5\n\
			"cWH"Этаж "cBLUE"№6\n\
			"cWH"Этаж "cBLUE"№7");		
			SPD(playerid, DIALOG_LIFT_HOTEL_2, DIALOG_STYLE_TABLIST, !""cBLUE"Лифт отеля", String512, !"Выбор", !"Закрыть");	
		}
		case HOTEL_3:
		{
			format(String512, sizeof(String512), "\
			"cWH"Холл "cBLUE"(Этаж №1)\n\
			"cWH"Этаж "cBLUE"№2\n\
			"cWH"Этаж "cBLUE"№3\n\
			"cWH"Этаж "cBLUE"№4");		
			SPD(playerid, DIALOG_LIFT_HOTEL_3, DIALOG_STYLE_TABLIST, !""cBLUE"Лифт отеля", String512, !"Выбор", !"Закрыть");	
		}
		case HOTEL_4:
		{
			format(String512, sizeof(String512), "\
			"cWH"Холл "cBLUE"(Этаж №1)\n\
			"cWH"Этаж "cBLUE"№2\n\
			"cWH"Этаж "cBLUE"№3\n\
			"cWH"Этаж "cBLUE"№4");		
			SPD(playerid, DIALOG_LIFT_HOTEL_4, DIALOG_STYLE_TABLIST, !""cBLUE"Лифт отеля", String512, !"Выбор", !"Закрыть");	
		}
	}
	return true;
}

stock teleport_hotel_level(playerid, hotel_params, level)
{
	switch(hotel_params)
	{
		case HOTEL_1:
		{	
			if(level == 1)
			{
				SetPlayerVirtualWorld(playerid, HOTEL_1);
				SetPVarIntNew(playerid, "hotel_number_vw", HOTEL_1);
				PlayerPlaySound(playerid, 6401, 0.0, 0.0, 0.0);
				return SetPlayerPosEx(playerid, -2737.1484,-1764.9561,2.3055,358.9787);
			}
			PlayerPlaySound(playerid, 6401, 0.0, 0.0, 0.0);
			SetPlayerVirtualWorld(playerid, level+100);
			SetPlayerPosEx(playerid, -1886.8456,1985.4697,1165.4636,180.2364);
		}	
		case HOTEL_2:
		{
			if(level == 1)
			{
				SetPlayerVirtualWorld(playerid, HOTEL_2);
				PlayerPlaySound(playerid, 6401, 0.0, 0.0, 0.0);
				SetPVarIntNew(playerid, "hotel_number_vw", HOTEL_2);
				return SetPlayerPosEx(playerid, -2737.1484,-1764.9561,2.3055,358.9787);
			}
			PlayerPlaySound(playerid, 6401, 0.0, 0.0, 0.0);
			SetPlayerVirtualWorld(playerid, level+200);
			SetPlayerPosEx(playerid, -1886.8456,1985.4697,1165.4636,180.2364);
		}
		case HOTEL_3:
		{
			if(level == 1)
			{
				SetPlayerVirtualWorld(playerid, HOTEL_3);
				PlayerPlaySound(playerid, 6401, 0.0, 0.0, 0.0);
				SetPVarIntNew(playerid, "hotel_number_vw", HOTEL_3);
				return SetPlayerPosEx(playerid, -2737.1484,-1764.9561,2.3055,358.9787);
			}
			SetPlayerVirtualWorld(playerid, level+300);
			PlayerPlaySound(playerid, 6401, 0.0, 0.0, 0.0);
			SetPlayerPosEx(playerid, -1886.8456,1985.4697,1165.4636,180.2364);
		}
		case HOTEL_4:
		{
			if(level == 1)
			{
				SetPlayerVirtualWorld(playerid, HOTEL_4);
				SetPVarIntNew(playerid, "hotel_number_vw", HOTEL_4);
				PlayerPlaySound(playerid, 6401, 0.0, 0.0, 0.0);
				return SetPlayerPosEx(playerid, -2737.1484,-1764.9561,2.3055,358.9787);
			}
			SetPlayerVirtualWorld(playerid, level+400);
			PlayerPlaySound(playerid, 6401, 0.0, 0.0, 0.0);
			SetPlayerPosEx(playerid, -1886.8456,1985.4697,1165.4636,180.2364);
		}
	}

	return true;
}

stock get_hotel_class(h)
{
	new 
		name[20],
		class = hotel[h][hotel_class];

	switch(class)
	{
		case 1: name = "Низкий";
		case 2: name = "Средний";
		case 3: name = "Высокий";
		default: name = "Заброшенный";
	}
	return name;
}

stock get_hotel_name(type)
{
	new 
		name[21];

	switch(type)
	{
		case 1: name = "Москва-Сити";
		case 2: name = "Бюджетный";
		case 3: name = "Диана";
		default: name = "Заброшенный";
	}
	return name;
}

stock hotel_info(playerid, h)
{

	static 
		h_class[24],
		h_owner[24];

	format(h_class, 24, "%s", get_hotel_class(h));

	if(hotel[h][hotel_owned] != -1)
	{
		GetPlayerNameByID(hotel[h][hotel_owned], hotel[h][hotel_owner]);
		format(h_owner, 24, hotel[h][hotel_owner]);
	}
	else
	{
		format(h_owner, 24, "Государство");	
	}

	if(hotel[h][hotel_owned] == -1)
	{
		format(String512, sizeof(String512), "\
		"cWH"Наименование отеля: \t"cBLUE"%s\n\
		"cWH"Класс отеля:		\t\t"cBLUE"%s\n\
		"cWH"Владелец: 			\t"cBLUE"%s\n\
		"cWH"Статус: 			\t\t%s\n\
		"cWH"Цена: 				\t"cGR"%d рублей\n\
		"cWH"Ежедневная оплата: \t\t\t"cGR"%d рублей\n\n\
		"cBLUE"Вы действительно хотите купить отель?",
		hotel[h][hotel_name],
		h_class,
		h_owner,
		(hotel[h][hotel_owned]) ? (""cGR"Продается") : (""cLRED"Куплен"),
		hotel[h][hotel_price], hotel[h][hotel_takings]);
		SPD(playerid, DIALOG_BUY_HOTEL, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка отеля", String512, !"Купить", !"Закрыть");		
	}
	if(hotel[h][hotel_owned] != -1)
	{
		format(String512, sizeof(String512), "\
		"cWH"Наименование отеля: \t"cBLUE"%s\n\
		"cWH"Класс отеля: \t"cBLUE"%s\n\
		"cWH"Владелец: \t"cBLUE"%s\n\
		"cWH"Статус: \t%s\n\
		"cWH"Стоимость: \t"cGR"%d руб\n\
		"cWH"\t\n\
		"cWH"Cтоимость входа: \t "cGR"%d руб\n\
		"cWH"\t\n\
		"cWH"Войти в отель",
		hotel[h][hotel_name],
		h_class,
		h_owner,
		(hotel[h][hotel_lock] == 1) ? (""cGR"Дверь открыта") : (""cLRED"Дверь закрыта"),
		hotel[h][hotel_price], hotel[h][hotel_enter_price]);		
		SPD(playerid, DIALOG_INFO_HOTEL, DIALOG_STYLE_TABLIST, !""cBLUE"Отель", String512, !"Выбор", !"Закрыть");	

	}
	return true;
}

stock select_menu_enter_hotel(playerid, h)
{
	if(hotel[h][hotel_owned] == -1)
	{
    	format(String144, sizeof(String144), "\
   	 	"cBLUE"- "cWH"Информация о покупке отеля\n\
    	"cBLUE"- "cWH"Войти в отель");
    	SPD(playerid, DIALOG_SELECT_ENTER_HOTEL, DIALOG_STYLE_LIST, !""cBLUE"Вход в отель", String144, !"Выбрать", !"Закрыть"); 
    }
    else 
    {
    	hotel_info(playerid, h);
    }
    return true;
}


stock buy_hotel(playerid, h)
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

	if(hotel[h][hotel_owned] != -1)
		return SendErr(playerid, "Отель недоступен для покупки!");

	if(GetPlayerMoneyEx(playerid) < hotel[h][hotel_price]) 
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
		return SendErr(playerid,"У вас недостаточно денежных средств для покупки отеля!");	
	}


	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_buy_hotel", 4000);


	hotel[h][hotel_owned] = pData[playerid][pMysqlID];
	format(hotel[h][hotel_owner], 24, pData[playerid][pNickname]);
	hotel[h][hotel_days] = 3;

	pData[playerid][pHotelOwner] = h;

	if(opcode) FormattedMessage(playerid, -1, "[debug] hotel buy: %d | hotel_owner_sql: %d ", h, hotel[h][hotel_owned]);

	UpdatePlayerData(playerid,"pHotelOwner",pData[playerid][pHotelOwner]);	

 	format(String256, sizeof(String256), "Покупка отеля №%d", h);
	give_money(playerid, -hotel[h][hotel_price], String256);


	update_hotel_text_3d(h);
	save_hotel(h);
	update_hotel_text_3d(h);

	format(String512, sizeof(String512), "\
		"cWH"Поздравляем Вас с приобретением отеля!\n\n\
		Вы купили отель "cBLUE"%s\n\
		"cWH"Ежедневная оплата: "cGR"%d"cWH" рублей\n\n\
		"cWH"Отель оплачен на "cBLUE"%d"cWH" дней\n\
		Советутем Вам посетить банк для оплаты!",
		hotel[h][hotel_name],
		hotel[h][hotel_takings], hotel[h][hotel_days]);
	return SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Отель", String512, !"Понял", !"");
}

stock menu_reseption(playerid, h)
{

	static 
		h_class[24],
		h_owner[24];

	new 
		room_id = pData[playerid][pHotelRoom];

	if(hotel[h][hotel_owned] == pData[playerid][pMysqlID] && room_id == -1)
	{
		format(String512, sizeof(String512), "\
		"cWH"Список номеров\t"cBLUE"Открыть\n\
		"cWH"Арендовать номер\t"cBLUE"%d рублей",
		hotel[h][hotel_price_rent]);		
		SPD(playerid, DIALOG_MENU_RENT_NEW, DIALOG_STYLE_TABLIST, !""cBLUE"Отель", String512, !"Выбор", !"Закрыть");			
	}
	if(hotel[h][hotel_owned] == pData[playerid][pMysqlID] && room_id != -1)
	{
		format(String512, sizeof(String512), "\
		"cWH"Список номеров\t"cBLUE"Открыть\n\
		"cWH"Продлить аренду номера\t"cBLUE"%d дней\n\
		"cWH"Отказаться от аренды\t"cLRED"Отказаться",
		hotel_room[room_id][hotel_room_day]);	
		SPD(playerid, DIALOG_MENU_RENT_RENT, DIALOG_STYLE_TABLIST, !""cBLUE"Отель", String512, !"Выбор", !"Закрыть");			
	}
	if(room_id != -1 && hotel[h][hotel_owned] != pData[playerid][pMysqlID])
	{
		format(String512, sizeof(String512), "\
		"cWH"Список номеров\t"cBLUE"Открыть\n\
		"cWH"Продлить аренду номера\t"cBLUE"%d дней\n\
		"cWH"Отказаться от аренды\t"cLRED"Отказаться",
		hotel_room[room_id][hotel_room_day]);		
		SPD(playerid, DIALOG_MENU_RENT_RENT, DIALOG_STYLE_TABLIST, !""cBLUE"Отель", String512, !"Выбор", !"Закрыть");	
	}

	if(room_id == -1 && hotel[h][hotel_owned] != pData[playerid][pMysqlID])
	{
		format(String512, sizeof(String512), "\
		"cWH"Список номеров\t"cBLUE"Открыть\n\
		"cWH"Арендовать номер\t"cBLUE"%d рублей",
		hotel[h][hotel_price_rent]);		
		SPD(playerid, DIALOG_MENU_RENT_NEW, DIALOG_STYLE_TABLIST, !""cBLUE"Отель", String512, !"Выбор", !"Закрыть");	
	}



	return true;
}

stock panel_manage_hotel(playerid)
{
	if(pData[playerid][pHotelOwner] == -1)
		return SendErr(playerid, "Вы не владеете отелем!");

	new 
		h = pData[playerid][pHotelOwner];


	format(String512, sizeof(String512), "\
	"cWH"Список номеров\t"cBLUE"Открыть\n\
	"cWH"Изменить цену на номер\t"cBLUE"Изменить\n\
	"cWH"Изменить стоимость входа\t"cBLUE"Изменить\n\
	"cWH"Статистика отеля\t"cBLUE"Изучить\n\
	"cWH"Управление кассой отеля\t"cBLUE"Открыть\n\
	"cWH"\t\n\
	"cWH"Стоимость номера \t"cGR"%d руб\n\
	"cWH"Cтоимость входа \t "cGR"%d руб\n\
	"cWH"Оплачено на\t "cBLUE"%d дней\n\
	"cWH"Продать отель\t "cBLUE"Продать",
	
	hotel[h][hotel_price_rent],
	hotel[h][hotel_enter_price],
	hotel[h][hotel_days]);		
	SPD(playerid, DIALOG_CHANGE_HOTEL, DIALOG_STYLE_TABLIST, !""cBLUE"Отель", String512, !"Выбор", !"Закрыть");	

	return true;

}

CMD:hotel(playerid)
{
	return panel_manage_hotel(playerid);
}

stock change_price_room_hotel(playerid, h)
{
	format(String512, sizeof(String512), "\
	"cWH"Текущая стоимость аренды номера: "cGR"%d"cWH" рублей\n\n\
	"cBLUE"Введите новую стоимость:", hotel[h][hotel_price_rent]);

	SPD(playerid, DIALOG_CHANGE_PRICE_NUMBER_H, DIALOG_STYLE_INPUT, !""cBLUE"Изменение стоимости аренды", String512, !"Далее", !"Назад");


	return true;
}

stock change_price_enter_hotel(playerid, h)
{
	format(String512, sizeof(String512), "\
	"cWH"Текущая стоимость входа: "cGR"%d"cWH" рублей\n\n\
	"cBLUE"Введите новую стоимость входа:", hotel[h][hotel_enter_price]);

	SPD(playerid, DIALOG_CHANGE_PRICE_ENTER_HOTEL, DIALOG_STYLE_INPUT, !""cBLUE"Изменение стоимости входа", String512, !"Далее", !"Назад");


	return true;
}

stock show_hotel_room_all(playerid, h)
{
	switch(h)
	{
		case HOTEL_1:
		{
		    format(String4096, sizeof(String4096), ""cGREY"№\t"cGREY"Арендует\n");

			format(String1024, sizeof(String1024), "SELECT * FROM `hotel_room` WHERE `hotel_id` = %d ORDER BY `hotel_room_id`", HOTEL_1);
			new Result:rnew = sql_queryEx(zConn, String1024, QUERY_CACHED);

			new all_list_hotel_room = sql_num_rows(rnew);

		    new 
		    	hotel_room_id_all = 0;


		 	for(new i; i < all_list_hotel_room; i++)
			{
				new 
					h_owner[32],
					h_owners[32],
					hotel_room_owneds;

				hotel_room_owneds = sql_get_field_assoc_int_ex(rnew, i, "hotel_room_owned");

				if(hotel_room_owneds != -1)
				{
					GetPlayerNameByID(hotel_room_owneds, h_owners);
					format(h_owner, 32, h_owners);
				}
				else
				{
					format(h_owner, 32, ""cGR"Свободен");	
				}


		    	format(String4096, sizeof(String4096), "%s%d."cWH"\t"cBLUE"%s\n",String4096, \
		    	hotel_room_id_all+1, h_owner);
	

				hotel_room_id_all++;


			}
			sql_free_result(rnew);


			ShowPlayerDialog(playerid,0, DIALOG_STYLE_TABLIST_HEADERS ,""cBLUE"Список номеров отеля",String4096,"Далее","Закрыть");		
		}
		case HOTEL_2:
		{
		    format(String4096, sizeof(String4096), ""cGREY"№\t"cGREY"Арендует\n");

			format(String1024, sizeof(String1024), "SELECT * FROM `hotel_room` WHERE `hotel_id` = %d ORDER BY `hotel_room_id`", HOTEL_2);
			new Result:rnew = sql_queryEx(zConn, String1024, QUERY_CACHED);

			new all_list_hotel_room = sql_num_rows(rnew);

		    new 
		    	hotel_room_id_all = 0;


		 	for(new i; i < all_list_hotel_room; i++)
			{
				new 
					h_owner[32],
					h_owners[32],
					hotel_room_owneds;

				hotel_room_owneds = sql_get_field_assoc_int_ex(rnew, i, "hotel_room_owned");

				if(hotel_room_owneds != -1)
				{
					GetPlayerNameByID(hotel_room_owneds, h_owners);
					format(h_owner, 32, h_owners);
				}
				else
				{
					format(h_owner, 32, ""cGR"Свободен");	
				}


		    	format(String4096, sizeof(String4096), "%s%d."cWH"\t"cBLUE"%s\n",String4096, \
		    	hotel_room_id_all+1, h_owner);
	

				hotel_room_id_all++;


			}
			sql_free_result(rnew);


			ShowPlayerDialog(playerid,0, DIALOG_STYLE_TABLIST_HEADERS ,""cBLUE"Список номеров отеля",String4096,"Далее","Закрыть");		
		}
		case HOTEL_3:
		{
		    format(String4096, sizeof(String4096), ""cGREY"№\t"cGREY"Арендует\n");

			format(String1024, sizeof(String1024), "SELECT * FROM `hotel_room` WHERE `hotel_id` = %d ORDER BY `hotel_room_id`", HOTEL_3);
			new Result:rnew = sql_queryEx(zConn, String1024, QUERY_CACHED);

			new all_list_hotel_room = sql_num_rows(rnew);

		    new 
		    	hotel_room_id_all = 0;


		 	for(new i; i < all_list_hotel_room; i++)
			{
				new 
					h_owner[32],
					h_owners[32],
					hotel_room_owneds;

				hotel_room_owneds = sql_get_field_assoc_int_ex(rnew, i, "hotel_room_owned");

				if(hotel_room_owneds != -1)
				{
					GetPlayerNameByID(hotel_room_owneds, h_owners);
					format(h_owner, 32, h_owners);
				}
				else
				{
					format(h_owner, 32, ""cGR"Свободен");	
				}


		    	format(String4096, sizeof(String4096), "%s%d."cWH"\t"cBLUE"%s\n",String4096, \
		    	hotel_room_id_all+1, h_owner);
	

				hotel_room_id_all++;


			}
			sql_free_result(rnew);


			ShowPlayerDialog(playerid,0, DIALOG_STYLE_TABLIST_HEADERS ,""cBLUE"Список номеров отеля",String4096,"Далее","Закрыть");		
		}
		case HOTEL_4:
		{
		    format(String4096, sizeof(String4096), ""cGREY"№\t"cGREY"Арендует\n");

			format(String1024, sizeof(String1024), "SELECT * FROM `hotel_room` WHERE `hotel_id` = %d ORDER BY `hotel_room_id`", HOTEL_4);
			new Result:rnew = sql_queryEx(zConn, String1024, QUERY_CACHED);

			new all_list_hotel_room = sql_num_rows(rnew);

		    new 
		    	hotel_room_id_all = 0;


		 	for(new i; i < all_list_hotel_room; i++)
			{
				new 
					h_owner[32],
					h_owners[32],
					hotel_room_owneds;

				hotel_room_owneds = sql_get_field_assoc_int_ex(rnew, i, "hotel_room_owned");

				if(hotel_room_owneds != -1)
				{
					GetPlayerNameByID(hotel_room_owneds, h_owners);
					format(h_owner, 32, h_owners);
				}
				else
				{
					format(h_owner, 32, ""cGR"Свободен");	
				}


		    	format(String4096, sizeof(String4096), "%s%d."cWH"\t"cBLUE"%s\n",String4096, \
		    	hotel_room_id_all+1, h_owner);
	

				hotel_room_id_all++;


			}
			sql_free_result(rnew);


			ShowPlayerDialog(playerid,0, DIALOG_STYLE_TABLIST_HEADERS ,""cBLUE"Список номеров отеля",String4096,"Далее","Закрыть");		
		}
	}
	return true;
}

stock rent_room_hotel(playerid, h)
{

	if(pData[playerid][pHotelRoom] != -1)
		return SendErr(playerid, "Вы уже арендуете номер в отеле!");

	if(pData[playerid][pHouseRent] != -1)
		return SendErr(playerid, "Вы уже арендуете комнату в доме!");

	if(pData[playerid][pFlateRent] != -1)
		return SendErr(playerid, "Вы уже арендуете комнату в квартире!");

	if(pData[playerid][pHouse] != -1 || pData[playerid][pFlate] != -1)
		return SendErr(playerid, "Вы уже владете домом или квартирой!");	
	

	format(String512, sizeof(String512), "\
	"cWH"Текущая стоимость аренды номера: "cGR"%d"cWH" рублей за 1 день\n\n\
	"cWH"Насколько Вы хотите арендовать номер?\n\n\
	"cBLUE"(От 3 до 30 дней)", hotel[h][hotel_price_rent]);

	return SPD(playerid, DIALOG_RENT_ROOM_FINAL, DIALOG_STYLE_INPUT, !""cBLUE"Аренда номера в отеле", String512, !"Далее", !"Назад");
}

stock rent_room_long(playerid, h)
{
	if(pData[playerid][pHotelRoom] == -1)
		return SendErr(playerid, "Вы уже не арендуете номер в отеле!");

	new 
		room_id = pData[playerid][pHotelRoom];

	if(hotel_room[room_id][hotel_room_day] == 30)
		return SendErr(playerid, "Номер в отеле уже оплачен на максимальное количество дней");

	new 
		max_day = 30-hotel_room[room_id][hotel_room_day];

	SetPVarIntNew(playerid, "max_day_continue_room", max_day);


	format(String512, sizeof(String512), "\
	"cWH"Текущая стоимость аренды номера: "cGR"%d"cWH" рублей за 1 день\n\n\
	"cWH"Насколько Вы хотите продлить аренду номера?\n\n\
	"cWH"Номер оплачен на "cBLUE"%d"cWH" дней\n\n\
	"cBLUE"Вы можете продлить аренду на %d дней", hotel[h][hotel_price_rent], hotel_room[room_id][hotel_room_day], max_day);

	return SPD(playerid, DIALOG_CONTINUE_RENT_ROOM, DIALOG_STYLE_INPUT, !""cBLUE"Продление аренды номера", String512, !"Далее", !"Назад");

}

stock final_continue_rent_room_h(playerid, h, day)
{

	new 
		room_id = pData[playerid][pHotelRoom];

 	format(String256, sizeof(String256), "Продление аренды номера в отеле №%d", h);
	give_money(playerid, -hotel[h][hotel_price_rent]*day, String256);

	hotel_bank_update(h, hotel[h][hotel_price_rent]*day, "Продление аренды комнаты в отеле");

	hotel_room[room_id][hotel_room_day] += day;

	update_pickup_hotel_room(playerid, room_id);
	save_hotel_room(room_id);
	save_hotel(h); 

	SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы продлили аренду комнаты на "cBLUE"%d"cWH" дней на "cGR"%d"cWH" рублей", day, hotel[h][hotel_price_rent]*day);	

	return true;
}

stock cancel_rent_room(playerid, h)
{
	new 
		fmt_str[220];

	if(pData[playerid][pHotelRoom] == -1)
		return SendErr(playerid, "Вы уже не арендуете номер в отеле!");

	new 
		room_id = pData[playerid][pHotelRoom];

	format(fmt_str, 220, "\
	"cWH"Вы уверен, что хотите отказаться от аренды?\n\
	"cWH"Деньги не будут возвращены за оплаченные дни\n\n\
	"cWH"Номер оплачен на "cBLUE"%d"cWH" дней\n\n\
	"cBLUE"Вы уверены, что хотите отказаться от аренды?", hotel_room[room_id][hotel_room_day]);

	return SPD(playerid, DIALOG_CANCEL_RENT_ROOM, DIALOG_STYLE_MSGBOX, !""cBLUE"Отказ от аренды номера", fmt_str, !"Далее", !"Назад");
}

stock final_cancel_rent_room(playerid, h)
{
	
	new 
		room_id = pData[playerid][pHotelRoom];


	pData[playerid][pHotel] = -1;
	pData[playerid][pHotelRoom] = -1;

	UpdatePlayerData(playerid,"pHotel",pData[playerid][pHotel]);	
	UpdatePlayerData(playerid,"hotelroom",pData[playerid][pHotelRoom]);	

	pData[playerid][pSpawn] = 0;
	UpdatePlayerData(playerid, "spawn", pData[playerid][pSpawn]);

	hotel_room[room_id][hotel_room_day] = 3;
	hotel_room[h][hotel_room_owned] = -1;

	format(hotel[h][hotel_owner], 24, "Отсутствует");	

	update_pickup_hotel_room(playerid, h);
	save_hotel_room(h);
	save_hotel(h);

	SendSucc(playerid, "Вы отказались от аренды номера в отеле!");
	SendInf(playerid, "Теперь Вы будете появляться на вокзале!");

	return true;
}

stock rent_room_random_player(playerid, h, day)
{
	new 
		hotel_room_in_player;

 	for(new i; i < all_hotel_room; i++)
	{
		if(hotel_room[i][hotel_h_id] != h) continue;
		if(hotel_room[i][hotel_room_owned] != -1) continue;

		hotel_room_in_player = i;

		break;
	}	


	hotel_room[h][hotel_room_owned] = pData[playerid][pMysqlID];
	format(hotel_room[h][hotel_room_owner], 24, pData[playerid][pNickname]);

	pData[playerid][pHotel] = h;
	pData[playerid][pHotelRoom] = hotel_room_in_player;

	UpdatePlayerData(playerid,"pHotel",pData[playerid][pHotel]);	
	UpdatePlayerData(playerid,"hotelroom",pData[playerid][pHotelRoom]);	

 	format(String256, sizeof(String256), "Аренда номера в отеле №%d", h);
	give_money(playerid, -hotel[h][hotel_price_rent]*day, String256);

	hotel_bank_update(h, hotel[h][hotel_price_rent]*day, "Аренда комнаты в отеле");

	hotel_room[hotel_room_in_player][hotel_room_day] = day;

	update_pickup_hotel_room(playerid, h);
	save_hotel_room(h);
	save_hotel(h);

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:info_gui_hotel_rent", 4000);

	static
		fmt_str[550];

	format(fmt_str, 550, "\
		"cWH"Поздравляем Вас с арендой номера в отеле!\n\n\
		Вы арендовали номер отеле: "cBLUE"%s\n\
		"cWH"Ежедневная оплата: "cGR"%d"cWH" рублей\n\
		"cWH"Отель оплачен на "cBLUE"%d"cWH" дней\n\
		"cWH"Общая сумма за "cBLUE"%d"cWH" дней - "cGR"%d"cWH" рублей\n\n\
		"cWH"Комната номер: "cBLUE"%d\n\
		"cWH"Этаж отеля: "cBLUE"%d\n\n\
		Хорошего Вам отдыха! Следите за здоровьем!",
		hotel[h][hotel_name],
		hotel[h][hotel_price_rent],
		hotel_room[hotel_room_in_player][hotel_room_day],
		hotel_room[hotel_room_in_player][hotel_room_day],
		hotel[h][hotel_price_rent]*day,
		hotel_room_in_player+1,
		hotel_room[hotel_room_in_player][hotel_room_level]);
	return SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Аренда номера", fmt_str, !"Понял", !"");	
}


stock show_bank_hotel(playerid, h)
{
	new 
		fmt_str[200];

    format(fmt_str, 200, "\
    "cGREY"Тип\t"cGREY"Информация\n\
    "cBLUE"- "cWH"Взять деньги из кассы\t"cBLUE"%d рублей\n\
    "cBLUE"- "cWH"Положить деньги в кассу\t"cBLUE"Положить", hotel[h][hotel_bank]);
    return SPD(playerid, DIALOG_BANK_HOTEL, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Касса отеля", fmt_str, !"Выбрать", !"Закрыть"); 

}

stock input_money_hotel(playerid, h)
{
	if(hotel[h][hotel_bank] == 0)
	{
		show_bank_hotel(playerid, h);
		return SendErr(playerid, "В кассе нет денег, чтобы взять их!");
	}

	new 
		fmt_str[130]; 

	format(fmt_str, 130, "\
	"cWH"В кассе отеля находится "cGR"%d рублей"cWH" на данный момент\n\n\
	"cBLUE"Сколько денег Вы хотите взять?", hotel[h][hotel_bank]);

	return SPD(playerid, DIALOG_INPUT_MONEY_BANK_HOTEL, DIALOG_STYLE_INPUT, !""cBLUE"Касса отеля", fmt_str, !"Далее", !"Назад");

}

stock put_money_hotel(playerid, h)
{
	new 
		fmt_str[200]; 

	format(fmt_str, 200, "\
	"cWH"В кассе Вашего отеля находится "cGR"%d рублей"cWH" на данный момент\n\n\
	"cBLUE"Сколько денег Вы хотите положить?", hotel[h][hotel_bank]);

	return SPD(playerid, DIALOG_PUT_MONEY_BANK_HOTEL, DIALOG_STYLE_INPUT, !""cBLUE"Касса отеля", fmt_str, !"Далее", !"Назад");
}

stock dialog_all_hotel(playerid, dialogid, response, listitem, inputtext[])
{

	switch(dialogid)
	{
		case DIALOG_SELECT_ENTER_HOTEL:
		{
			if(!response)
				return true;

			new 
				h_id = pTemp[playerid][area_item_id];

			switch(listitem)
			{
				case 0: return hotel_info(playerid, h_id);
				case 1: return enter_hotel(playerid, h_id);
			}

		}
		case DIALOG_BANK_HOTEL:
		{
			new 
				id_hotels = pData[playerid][pHotelOwner];

			if(!response)
				return show_bank_hotel(playerid, id_hotels);

			switch(listitem)
			{
				case 0: return input_money_hotel(playerid, id_hotels);
				case 1: return put_money_hotel(playerid, id_hotels);
			}	
		}
		case DIALOG_INPUT_MONEY_BANK_HOTEL:
		{
			new 
				id_hotels = pData[playerid][pHotelOwner];

			if(!response)
				return show_bank_hotel(playerid, id_hotels);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное количество денег!");
				return input_money_hotel(playerid, id_hotels);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное количество денег!");
				return input_money_hotel(playerid, id_hotels);			
			}


			new 
				count_money_input = strval(inputtext);

			if(count_money_input < 1)
			{
				SendErr(playerid,"Вы указали неверное количество денег!");
				return input_money_hotel(playerid, id_hotels);
			}


			if(hotel[id_hotels][hotel_bank] < count_money_input)
			{
				SendErr(playerid,"У вас недостаточно денег в кассе отеля!!");
				return input_money_hotel(playerid, id_hotels);				
			}

			hotel[id_hotels][hotel_bank] -= count_money_input;

		 	format(String256, sizeof(String256), "Деньги из кассы отеля №%d", id_hotels);
			give_money(playerid, count_money_input, String256);

			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы взяли из кассы отеля - "cGR"%d рублей"cWH"", count_money_input);	

			show_bank_hotel(playerid, id_hotels);

			save_hotel(id_hotels);	

		}
		case DIALOG_PUT_MONEY_BANK_HOTEL:
		{
			new 
				id_hotels = pData[playerid][pHotelOwner];

			if(!response)
				return show_bank_hotel(playerid, id_hotels);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное количество денег!");
				return put_money_hotel(playerid, id_hotels);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное количество денег!");
				return put_money_hotel(playerid, id_hotels);		
			}

			new 
				count_money_put = strval(inputtext);

			if(count_money_put < 1)
			{
				SendErr(playerid,"Вы указали неверное количество денег!");
				return put_money_hotel(playerid, id_hotels);
			}


			if(GetPlayerMoneyEx(playerid) < count_money_put)
			{
				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
				SendErr(playerid,"У вас недостаточно денег!");
				return put_money_hotel(playerid, id_hotels);				
			}

			hotel[id_hotels][hotel_bank] += count_money_put;

		 	format(String256, sizeof(String256), "Деньги в кассу отеля №%d", id_hotels);
			give_money(playerid, -count_money_put, String256);

			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы положили в кассу отеля - "cGR"%d рублей"cWH"", count_money_put);	

			show_bank_hotel(playerid, id_hotels);

			save_hotel(id_hotels);	

		}

		case DIALOG_MENU_RENT_NEW:
		{

			new 
				h = GetPVarIntNew(playerid, "hotel_number_vw");

			if(!response)
				return true;	

			switch(listitem)
			{
				case 0: return show_hotel_room_all(playerid, h);
				case 1: return rent_room_hotel(playerid, h);
			}			
		}
		case DIALOG_MENU_RENT_RENT:
		{
			new 
				h = GetPVarIntNew(playerid, "hotel_number_vw");

			if(!response)
				return true;	

			switch(listitem)
			{
				case 0: return show_hotel_room_all(playerid, h);
				case 1: return rent_room_long(playerid, h);
				case 2: return cancel_rent_room(playerid, h);
			}			
		}
		case DIALOG_LIFT_HOTEL_1:
		{
			if(!response)
				return true;	

			switch(listitem)
			{
				case 0: return teleport_hotel_level(playerid, HOTEL_1, 1);
				case 1: return teleport_hotel_level(playerid, HOTEL_1, 2);
				case 2: return teleport_hotel_level(playerid, HOTEL_1, 3);
				case 3: return teleport_hotel_level(playerid, HOTEL_1, 4);
				case 4: return teleport_hotel_level(playerid, HOTEL_1, 5);
				case 5: return teleport_hotel_level(playerid, HOTEL_1, 6);
				case 6: return teleport_hotel_level(playerid, HOTEL_1, 7);
				case 7: return teleport_hotel_level(playerid, HOTEL_1, 8);
				case 8: return teleport_hotel_level(playerid, HOTEL_1, 9);
				case 9: return teleport_hotel_level(playerid, HOTEL_1, 10);
				case 10: return teleport_hotel_level(playerid, HOTEL_1, 11);
			}			
		}
		case DIALOG_LIFT_HOTEL_2:
		{
			if(!response)
				return true;	

			switch(listitem)
			{
				case 0: return teleport_hotel_level(playerid, HOTEL_2, 1);
				case 1: return teleport_hotel_level(playerid, HOTEL_2, 2);
				case 2: return teleport_hotel_level(playerid, HOTEL_2, 3);
				case 3: return teleport_hotel_level(playerid, HOTEL_2, 4);
				case 4: return teleport_hotel_level(playerid, HOTEL_2, 5);
				case 5: return teleport_hotel_level(playerid, HOTEL_2, 6);
				case 6: return teleport_hotel_level(playerid, HOTEL_2, 7);
			}				
		}
		case DIALOG_LIFT_HOTEL_3:
		{
			if(!response)
				return true;	

			switch(listitem)
			{
				case 0: return teleport_hotel_level(playerid, HOTEL_3, 1);
				case 1: return teleport_hotel_level(playerid, HOTEL_3, 2);
				case 2: return teleport_hotel_level(playerid, HOTEL_3, 3);
				case 3: return teleport_hotel_level(playerid, HOTEL_3, 4);
				case 4: return teleport_hotel_level(playerid, HOTEL_3, 5);
				case 5: return teleport_hotel_level(playerid, HOTEL_3, 6);
				case 6: return teleport_hotel_level(playerid, HOTEL_3, 7);
				case 7: return teleport_hotel_level(playerid, HOTEL_3, 8);
				case 8: return teleport_hotel_level(playerid, HOTEL_3, 9);
				case 9: return teleport_hotel_level(playerid, HOTEL_3, 10);
			}				
		}
		case DIALOG_LIFT_HOTEL_4:
		{
			if(!response)
				return true;	

			switch(listitem)
			{
				case 0: return teleport_hotel_level(playerid, HOTEL_4, 1);
				case 1: return teleport_hotel_level(playerid, HOTEL_4, 2);
				case 2: return teleport_hotel_level(playerid, HOTEL_4, 3);
				case 3: return teleport_hotel_level(playerid, HOTEL_4, 4);
				case 4: return teleport_hotel_level(playerid, HOTEL_4, 5);
				case 5: return teleport_hotel_level(playerid, HOTEL_4, 6);
				case 6: return teleport_hotel_level(playerid, HOTEL_4, 7);
				case 7: return teleport_hotel_level(playerid, HOTEL_4, 8);
				case 8: return teleport_hotel_level(playerid, HOTEL_4, 9);
				case 9: return teleport_hotel_level(playerid, HOTEL_4, 10);
			}				
		}
		case DIALOG_CHANGE_HOTEL:
		{
			if(!response)
				return true;	

			new 
				h = pData[playerid][pHotelOwner];

			switch(listitem)
			{
				case 0: return show_hotel_room_all(playerid, h);
				case 1: return change_price_room_hotel(playerid, h);
				case 2: return change_price_enter_hotel(playerid, h);
				case 3: return change_statistic_hotel(playerid);
				case 4: return show_bank_hotel(playerid, h);
				case 5: return panel_manage_hotel(playerid);
				case 6: return panel_manage_hotel(playerid);
				case 7: return panel_manage_hotel(playerid);
				case 8: return panel_manage_hotel(playerid);
				case 9: return sell_hotel_accept(playerid);
			}				
		}

		case DIALOG_ACCEPT_SELL_HOTEL:
		{
			new 
				h = pData[playerid][pHotelOwner];

			if(!response)
				return menu_reseption(playerid, h);


			sell_hotel(playerid, h);				
		}		

		case DIALOG_CHANGE_PRICE_ENTER_HOTEL:
		{
			new 
				h = pData[playerid][pHotelOwner];

			if(!response)
				return menu_reseption(playerid, h);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное значение!");
				return change_price_enter_hotel(playerid, h);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное значение!");
				return change_price_enter_hotel(playerid, h);		
			}

			new 
				count_price = strval(inputtext);

			if(count_price < 1)
			{
			    SendErr(playerid,"От 100 до 15.000 рублей!");
				return change_price_enter_hotel(playerid, h);
			}



			if(count_price < 100 || count_price > 15000)
			{
			    SendErr(playerid,"От 100 до 15.000 рублей!");
				return change_price_enter_hotel(playerid, h);
			}	

			hotel[h][hotel_enter_price] = count_price;
			SendSucc(playerid, "Вы успешно изменили стоимость входа в отель!");
			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Новая стоимость входа - "cGR"%d"cWH"", count_price);	

			save_hotel(h);

			panel_manage_hotel(playerid);

		}
		case DIALOG_RENT_ROOM_FINAL:
		{
			new 
				h = GetPVarIntNew(playerid, "hotel_number_vw");


			if(!response)
				return menu_reseption(playerid, h);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное количество дней!");
				return rent_room_hotel(playerid, h);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное количество дней!");
				return rent_room_hotel(playerid, h);
			}

			new 
				count_day_rent = strval(inputtext);


			if(count_day_rent < 3 || count_day_rent > 30)
			{
			    SendErr(playerid,"От 3 до 30 дней!");
				return rent_room_hotel(playerid, h);
			}	

			if(GetPlayerMoneyEx(playerid) < hotel[h][hotel_price_rent]*count_day_rent) 
			{
				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
			    SendErr(playerid,"Недостаточно денежных средств для аренды номера на такой срок!");
				return rent_room_hotel(playerid, h);
			}

			rent_room_random_player(playerid, h, count_day_rent);

		}
		case DIALOG_CANCEL_RENT_ROOM:
		{
			new
				h = GetPVarIntNew(playerid, "hotel_number_vw");

			if(!response)
				return menu_reseption(playerid, h);			

			final_cancel_rent_room(playerid, h);

		}
		case DIALOG_CONTINUE_RENT_ROOM:
		{
			new 
				h = GetPVarIntNew(playerid, "hotel_number_vw");

			new 
				max_day = GetPVarIntNew(playerid, "max_day_continue_room");

			if(!response)
				return menu_reseption(playerid, h);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное количество дней!");
				return rent_room_long(playerid, h);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное количество дней!");
				return rent_room_long(playerid, h);
			}

			new 
				count_day_rent = strval(inputtext);


			if(count_day_rent < 1 || count_day_rent > max_day)
			{
			    SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"От "cGR"1"cWH" дня и до "cGR"%d"cWH" дней", max_day);	
				return rent_room_long(playerid, h);
			}	

			if(GetPlayerMoneyEx(playerid) < hotel[h][hotel_price_rent]*count_day_rent) 
			{
				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
			    SendErr(playerid,"Недостаточно денежных средств для аренды номера на такой срок!");
				return rent_room_long(playerid, h);
			}
			final_continue_rent_room_h(playerid, h, count_day_rent);

		}
		case DIALOG_ENTER_HOTEL_ROOM:
		{
			if(!response)
				return true;

			new 
				h = pTemp[playerid][area_item_id];

			enter_hotel_room(playerid, h);	
		}

		case DIALOG_CHANGE_PRICE_NUMBER_H:
		{
			new 
				h = pData[playerid][pHotelOwner];

			if(!response)
				return menu_reseption(playerid, h);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное значение!");
				return change_price_room_hotel(playerid, h);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное значение!");
				return change_price_room_hotel(playerid, h);		
			}

			new 
				count_price = strval(inputtext);

			if(count_price < 1)
			{
				SendErr(playerid,"Вы указали неверное значение!");
				return change_price_room_hotel(playerid, h);	
			}


			new 
				get_class = hotel[h][hotel_class];

			new 
				max_price_rent;

			if(get_class == 1)
			{
				max_price_rent = 2500;
			}
			if(get_class == 2)
			{
				max_price_rent = 5000;
			}
			if(get_class == 3)
			{
				max_price_rent = 15000;
			}

			if(count_price < 1000 || count_price > max_price_rent)
			{
			   SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"От "cGR"1000"cWH" рублей и до "cGR"%d"cWH" рублей", max_price_rent);	
			   return change_price_room_hotel(playerid, h);
			}	

			hotel[h][hotel_price_rent] = count_price;
			SendSucc(playerid, "Вы успешно изменили стоимость аренды номера в отеле!");
			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Новая стоимость аренды номера - "cGR"%d"cWH"", count_price);	

			save_hotel(h);

			panel_manage_hotel(playerid);
		}


		case DIALOG_BUY_HOTEL:
		{
			if(!response)
				return true;	

			new 
				id_hotel = pTemp[playerid][area_item_id];

			if(opcode) FormattedMessage(playerid, -1, "[debug] menu buy univermag id: %d", id_hotel);


			buy_hotel(playerid, id_hotel);
		}
		case DIALOG_INFO_HOTEL:
		{
			if(!response)
				return true;	
			new 
				id_hotel = pTemp[playerid][area_item_id];


			switch(listitem)
			{
				case 0: return hotel_info(playerid, id_hotel);
				case 1: return hotel_info(playerid, id_hotel);
				case 2: return hotel_info(playerid, id_hotel);
				case 3: return hotel_info(playerid, id_hotel);
				case 4: return hotel_info(playerid, id_hotel);
				case 5: return hotel_info(playerid, id_hotel);
				case 6: return hotel_info(playerid, id_hotel);
				case 7: return hotel_info(playerid, id_hotel);
				case 8: return enter_hotel(playerid, id_hotel);
			}					

			enter_hotel(playerid, id_hotel);
		}
	}
	return true;
}



stock enter_hotel(playerid, h)
{
	if(h == -1) 
		return true; 

	if(hotel[h][hotel_lock] == 2)
	{
		hotel_info(playerid, h);
		return SendInf(playerid, "Двери отеля - закрыты. Вы не можете войти!");
	}

	if(GetPlayerMoneyEx(playerid) < hotel[h][hotel_enter_price]) 
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
		hotel_info(playerid, h);
		return SendErr(playerid,"У вас недостаточно денежных средств для входа в отель!");	
	}

	give_money(playerid, -hotel[h][hotel_enter_price], "Вход в отель");
 
	new 
		class = hotel[h][hotel_class];

	if(opcode)
	{
		FormattedMessage(playerid, -1, "[debug] area_enter_hotel: %d", h);
	}

	SetPVarIntNew(playerid, "hotel_number_vw", h);

	SetPlayerPosEx(playerid, hotel_int_coord[class][0], hotel_int_coord[class][1], hotel_int_coord[class][2], hotel_int_coord[class][3]);
	SetPlayerVirtualWorld(playerid, h);
	return true;
}

stock exit_hotel(playerid, h)
{
	if(h == -1) 
		return true;

	if(opcode) FormattedMessage(playerid, -1, "[debug] area_exit_hotel: %d", h);

	SetPlayerPosEx(playerid, hotel[h][hotel_enter_x], hotel[h][hotel_enter_y], hotel[h][hotel_enter_z], 2);
	SetPlayerVirtualWorld(playerid, 0);

	DeletePVarNew(playerid, "hotel_number_vw");

	return true;
}

stock hotel_bank_update(hotel_ids, sum, reason[])
{
	
	if(hotel[hotel_ids][hotel_finka_day] >= hotel[hotel_ids][hotel_finka_ogran])
		return true;

	if(hotel[hotel_ids][hotel_owned] == -1)
		return true;

	hotel[hotel_ids][hotel_bank] += sum;
	hotel[hotel_ids][hotel_finka_day] += sum;

	save_hotel(hotel_ids);

	format(String256,sizeof(String256),"UPDATE `hotel_stats` SET `stats_all_time` = `stats_all_time`+'%d' WHERE `hotel_id` = '%d'" , sum, hotel_ids);
	sql_queryEx(zConn, String256, QUERY_THREADED);	
	format(String256,sizeof(String256),"UPDATE `hotel_stats` SET `stats_mounth` = `stats_mounth`+'%d' WHERE `hotel_id` = '%d'" , sum, hotel_ids);
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
			format(String256,sizeof(String256),"UPDATE `hotel_stats` SET `stats_day_1` = `stats_day_1`+'%d' WHERE `hotel_id` = '%d'" , sum, hotel_ids);
			sql_queryEx(zConn, String256, QUERY_THREADED);	

			format(String256,sizeof(String256),"UPDATE `hotel_stats` SET `stats_today` = `stats_today`+'%d' WHERE `hotel_id` = '%d'" , sum, hotel_ids);
			sql_queryEx(zConn, String256, QUERY_THREADED);	

		}
		case 1:
		{
			format(String256,sizeof(String256),"UPDATE `hotel_stats` SET `stats_day_2` = `stats_day_2`+'%d' WHERE `hotel_id` = '%d'" , sum, hotel_ids);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `hotel_stats` SET `stats_today` = `stats_today`+'%d' WHERE `hotel_id` = '%d'" , sum, hotel_ids);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}	

		case 2:
		{
			format(String256,sizeof(String256),"UPDATE `hotel_stats` SET `stats_day_3` = `stats_day_3`+'%d' WHERE `hotel_id` = '%d'" , sum, hotel_ids);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `hotel_stats` SET `stats_today` = `stats_today`+'%d' WHERE `hotel_id` = '%d'" , sum, hotel_ids);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}
		case 3:
		{
			format(String256,sizeof(String256),"UPDATE `hotel_stats` SET `stats_day_4` = `stats_day_4`+'%d' WHERE `hotel_id` = '%d'" , sum, hotel_ids);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `hotel_stats` SET `stats_today` = `stats_today`+'%d' WHERE `hotel_id` = '%d'" , sum, hotel_ids);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}

		case 4:
		{
			format(String256,sizeof(String256),"UPDATE `hotel_stats` SET `stats_day_5` = `stats_day_5`+'%d' WHERE `hotel_id` = '%d'" , sum, hotel_ids);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `hotel_stats` SET `stats_today` = `stats_today`+'%d' WHERE `hotel_id` = '%d'" , sum, hotel_ids);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}	
		case 5:
		{
			format(String256,sizeof(String256),"UPDATE `hotel_stats` SET `stats_day_6` = `stats_day_6`+'%d' WHERE `hotel_id` = '%d'" , sum, hotel_ids);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `hotel_stats` SET `stats_today` = `stats_today`+'%d' WHERE `hotel_id` = '%d'" , sum, hotel_ids);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}
		case 6:
		{
			format(String256,sizeof(String256),"UPDATE `hotel_stats` SET `stats_day_7` = `stats_day_7`+'%d' WHERE `hotel_id` = '%d'" , sum, hotel_ids);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `hotel_stats` SET `stats_today` = `stats_today`+'%d' WHERE `hotel_id` = '%d'" , sum, hotel_ids);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}

	}	

	return true;
}

stock clear_stats_hotel_newday()
{


    new 
    	lyear, lmonth, lday;
	getdate(lyear, lmonth, lday);

	new 
		lwday = weekday(lday, lmonth, lyear);

	for(new i, idx = all_hotels; i < idx; i ++)
	{
		switch(lwday)
		{
			case 0:
			{
				format(String256,sizeof(String256),"UPDATE `hotel_stats` SET `stats_day_1` = '0' WHERE `hotel_id` = '%d'" , i);
				sql_queryEx(zConn, String256, QUERY_THREADED);	

				format(String256,sizeof(String256),"UPDATE `hotel_stats` SET `stats_today` = '0' WHERE `hotel_id` = '%d'" , i);
				sql_queryEx(zConn, String256, QUERY_THREADED);	

			}
			case 1:
			{
				format(String256,sizeof(String256),"UPDATE `hotel_stats` SET `stats_day_2` = '0' WHERE `hotel_id` = '%d'" , i);
				sql_queryEx(zConn, String256, QUERY_THREADED);	
			
				format(String256,sizeof(String256),"UPDATE `hotel_stats` SET `stats_today` = '0' WHERE `hotel_id` = '%d'" , i);
				sql_queryEx(zConn, String256, QUERY_THREADED);	
			}	

			case 2:
			{
				format(String256,sizeof(String256),"UPDATE `hotel_stats` SET `stats_day_3` = '0' WHERE `hotel_id` = '%d'" , i);
				sql_queryEx(zConn, String256, QUERY_THREADED);	
			
				format(String256,sizeof(String256),"UPDATE `hotel_stats` SET `stats_today` = '0' WHERE `hotel_id` = '%d'" , i);
				sql_queryEx(zConn, String256, QUERY_THREADED);	
			}
			case 3:
			{
				format(String256,sizeof(String256),"UPDATE `hotel_stats` SET `stats_day_4` = '0' WHERE `hotel_id` = '%d'" , i);
				sql_queryEx(zConn, String256, QUERY_THREADED);	
			
				format(String256,sizeof(String256),"UPDATE `hotel_stats` SET `stats_today` = '0' WHERE `hotel_id` = '%d'" , i);
				sql_queryEx(zConn, String256, QUERY_THREADED);	
			}

			case 4:
			{
				format(String256,sizeof(String256),"UPDATE `hotel_stats` SET `stats_day_5` = '0' WHERE `hotel_id` = '%d'" , i);
				sql_queryEx(zConn, String256, QUERY_THREADED);	
			
				format(String256,sizeof(String256),"UPDATE `hotel_stats` SET `stats_today` = '0' WHERE `hotel_id` = '%d'" , i);
				sql_queryEx(zConn, String256, QUERY_THREADED);	
			}	
			case 5:
			{
				format(String256,sizeof(String256),"UPDATE `hotel_stats` SET `stats_day_6` = '0' WHERE `hotel_id` = '%d'" , i);
				sql_queryEx(zConn, String256, QUERY_THREADED);	
			
				format(String256,sizeof(String256),"UPDATE `hotel_stats` SET `stats_today` = '0' WHERE `hotel_id` = '%d'" , i);
				sql_queryEx(zConn, String256, QUERY_THREADED);	
			}
			case 6:
			{
				format(String256,sizeof(String256),"UPDATE `hotel_stats` SET `stats_day_7` = '0' WHERE `hotel_id` = '%d'" , i);
				sql_queryEx(zConn, String256, QUERY_THREADED);	
			
				format(String256,sizeof(String256),"UPDATE `hotel_stats` SET `stats_today` = '0' WHERE `hotel_id` = '%d'" , i);
				sql_queryEx(zConn, String256, QUERY_THREADED);	
			}

		}	
	}
	return true;
}

stock clear_stats_hotel_newmouth()
{
	for(new i, idx = all_hotels; i < idx; i ++)
	{
		format(String256,sizeof(String256),"UPDATE `hotel_stats` SET `stats_mounth_back` = `stats_mounth` WHERE `hotel_id` = '%d'" , i);
		sql_queryEx(zConn, String256, QUERY_THREADED);	
	}

	format(String256,sizeof(String256),"UPDATE `hotel_stats` SET `stats_mounth` = '0' WHERE `hotel_id` = '%d'" , 0);
	sql_queryEx(zConn, String256, QUERY_THREADED);	

	return true;
}

stock change_statistic_hotel(playerid)
{
	new 
		hotel_ids = pData[playerid][pHotelOwner];

	format(String512, sizeof(String512), "SELECT * FROM hotel_stats WHERE hotel_id = '%d' LIMIT 1", hotel_ids);
	new Result:hotel_stats = sql_queryEx(zConn, String512, QUERY_CACHED);

	if(sql_num_rows(hotel_stats)) 
	{
		new 
			ye, m, d;

		getdate(ye, m, d);

		new 
			hotel_stats_day[8],
			hotel_stats_today,
			hotel_stats_mounth,
			hotel_status_all,
			hotel_stats_prewiow;

  		hotel_stats_day[1] = sql_get_field_assoc_int(hotel_stats, "stats_day_1");
  		hotel_stats_day[2] = sql_get_field_assoc_int(hotel_stats, "stats_day_2");
  		hotel_stats_day[3] = sql_get_field_assoc_int(hotel_stats, "stats_day_3");
  		hotel_stats_day[4] = sql_get_field_assoc_int(hotel_stats, "stats_day_4");
  		hotel_stats_day[5] = sql_get_field_assoc_int(hotel_stats, "stats_day_5");
  		hotel_stats_day[6] = sql_get_field_assoc_int(hotel_stats, "stats_day_6");
  		hotel_stats_day[7] = sql_get_field_assoc_int(hotel_stats, "stats_day_7");

  		hotel_stats_today = sql_get_field_assoc_int(hotel_stats, "stats_today");
  		hotel_stats_mounth = sql_get_field_assoc_int(hotel_stats, "stats_mounth");
  		hotel_status_all = sql_get_field_assoc_int(hotel_stats, "stats_all_time");
  		hotel_stats_prewiow = sql_get_field_assoc_int(hotel_stats, "stats_mounth_back");

  		new 
  			all_day_seven = hotel_stats_day[1]+hotel_stats_day[2]+hotel_stats_day[3]+hotel_stats_day[4]+hotel_stats_day[5]+hotel_stats_day[6]+hotel_stats_day[7];


	    format(String2048, sizeof(String2048), "\
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

        get_stats_color(hotel_stats_day[1], hotel_stats_day[1]), hotel_stats_day[1],
        get_stats_color(hotel_stats_day[2], hotel_stats_day[1]), hotel_stats_day[2], get_stats_phrase(hotel_stats_day[2], hotel_stats_day[1]), get_percent_pribil(hotel_stats_day[2], hotel_stats_day[1]), 
        get_stats_color(hotel_stats_day[3], hotel_stats_day[2]), hotel_stats_day[3], get_stats_phrase(hotel_stats_day[3], hotel_stats_day[1]), get_percent_pribil(hotel_stats_day[3], hotel_stats_day[2]), 
        get_stats_color(hotel_stats_day[4], hotel_stats_day[3]), hotel_stats_day[4], get_stats_phrase(hotel_stats_day[4], hotel_stats_day[1]), get_percent_pribil(hotel_stats_day[4], hotel_stats_day[3]), 
        get_stats_color(hotel_stats_day[5], hotel_stats_day[4]), hotel_stats_day[5], get_stats_phrase(hotel_stats_day[5], hotel_stats_day[1]), get_percent_pribil(hotel_stats_day[5], hotel_stats_day[4]), 
        get_stats_color(hotel_stats_day[6], hotel_stats_day[5]), hotel_stats_day[6], get_stats_phrase(hotel_stats_day[6], hotel_stats_day[1]), get_percent_pribil(hotel_stats_day[6], hotel_stats_day[5]), 
        get_stats_color(hotel_stats_day[7], hotel_stats_day[6]), hotel_stats_day[7], get_stats_phrase(hotel_stats_day[7], hotel_stats_day[1]), get_percent_pribil(hotel_stats_day[7], hotel_stats_day[6]), 
        mounth_hotel_stats[m], get_stats_color(hotel_stats_mounth, hotel_stats_prewiow), hotel_stats_mounth, get_stats_phrase(hotel_stats_mounth, hotel_stats_prewiow), get_percent_pribil(hotel_stats_mounth, hotel_stats_prewiow), 
        mounth_hotel_stats[m-1], hotel_stats_prewiow,
        all_day_seven,
        hotel_status_all,
        hotel_stats_today);
	    SPD(playerid, 0, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Статистика отеля", String2048, !"Закрыть", ""); 

  	}
  	sql_free_result(hotel_stats);


	return true;
}

CMD:addhotel(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    new 
    	Float:x,Float:y,Float:z;

    if(sscanf(params, "ddd",params[0], params[1], params[2]))
    {
    	SendInf(playerid, "Используйте: /addhotel [Класс] [Цена за вход] [Наименование отеля (цифра)]");
    	SendInf(playerid, "1 - Низкий | 2 - Средний | 3 - Высокий");
    	SendInf(playerid, "1 - Отель Москва-Сити | 2 - Отель Бюджетный | 3 - Отель Думайте Сами");
    	SendInf(playerid, "От 100 до 15.000 рублей");

    	return true;
    }

    if(params[0] < 1 || params[0] > 4) 
    	return SendInf(playerid, "1 - Низкий | 2 - Средний | 3 - Высокий");

    if(params[2] < 1 || params[2] > 3) 
    	return SendInf(playerid, "1 - Отель Москва-Сити | 2 - Отель Бюджетный | 3 - Отель Думайте Сами");

    if(params[1] < 100 || params[1] > 15000) 
    	return SendInf(playerid, "От 100 до 15.000 рублей");

    GetPlayerPos(playerid, x, y, z);
    
	static 
		formate_str[310];

    format(formate_str, 310, "INSERT INTO hotel(hotel_enter_x, hotel_enter_y, hotel_enter_z, hotel_exit_x, hotel_exit_y, hotel_exit_z, hotel_class, hotel_enter_price, hotel_name) VALUES ('%f','%f','%f','%f','%f','%f','%d','%d','%s')",
    x, y, z, x, y, z, params[0], params[1], get_hotel_name(params[2]));
    sql_queryEx(zConn, formate_str, QUERY_THREADED);	

    formate_str[0] = EOS;

    SendSucc(playerid, "Вы добавили отель! Он появится после рестарта");
	return true;
}

CMD:gotohotel(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

	if(sscanf(params, "d", params[0]))
	{
		SendInf(playerid, "Используйте: /gotohotel "cWH"[ID Отеля]");
		return true;
	}

	new 
		id_hotel = params[0];


	SetPlayerPos(playerid, hotel[id_hotel][hotel_enter_x], hotel[id_hotel][hotel_enter_y], hotel[id_hotel][hotel_enter_z]);

	new 
		fmt_str[144];

    format(fmt_str, sizeof(fmt_str), "Вы телепортировались к отелю №%d", id_hotel);
    SendSucc(playerid, fmt_str);
	return true;
}

CMD:ahotelfin(playerid, params[])
{


    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

	if(sscanf(params, "dd", params[0], params[1]))
	{
		SendInf(playerid, "Используйте: /ahotelfin "cWH"[ID Отеля] [Ограничение]");
		return true;
	}

	hotel[params[0]][hotel_finka_ogran] = params[1];
	save_hotel(params[0]);

    format(String144, sizeof(String144), "Вы успешно изменили максимальную прибыль для Отеля №%d на "cGR"%d "cWH"рублей!", params[0], params[1]);
    SendSucc(playerid, String144);

	return true;
}



#include <..\..\gamemodes\API\systems\hotel_systems\hotel_room_systems.inc>