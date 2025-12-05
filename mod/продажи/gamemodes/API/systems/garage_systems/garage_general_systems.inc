callback:: load_garage_all()
{
	new Result:garage_player = sql_queryEx(zConn, "SELECT * FROM `garage` ORDER BY `garage_id`", QUERY_CACHED);

	new all_garage_player = sql_num_rows(garage_player);

	new time = GetTickCount();


 	for(new i; i < all_garage_player; i++)
	{
		garage[i][garage_id]  = sql_get_field_assoc_int_ex(garage_player, i, "garage_id"); 


		garage[i][garage_owner_id]  = sql_get_field_assoc_int_ex(garage_player, i, "garage_owner_id"); 

		garage[i][garage_class]  = sql_get_field_assoc_int_ex(garage_player, i, "garage_class"); 
		garage[i][garage_price]  = sql_get_field_assoc_int_ex(garage_player, i, "garage_price"); 
		garage[i][garage_lock]  = sql_get_field_assoc_int_ex(garage_player, i, "garage_lock"); 
		garage[i][garage_takings]  = sql_get_field_assoc_int_ex(garage_player, i, "garage_nalog"); 	
		garage[i][garage_days]  = sql_get_field_assoc_int_ex(garage_player, i, "garage_day"); 

  		garage[i][garage_enter_x] = sql_get_field_assoc_float_ex(garage_player, i, "garage_enter_x");
  		garage[i][garage_enter_y] = sql_get_field_assoc_float_ex(garage_player, i, "garage_enter_y");
  		garage[i][garage_enter_z] = sql_get_field_assoc_float_ex(garage_player, i, "garage_enter_z");

  		garage[i][garage_exit_x] = sql_get_field_assoc_float_ex(garage_player, i, "garage_exit_x");
  		garage[i][garage_exit_y] = sql_get_field_assoc_float_ex(garage_player, i, "garage_exit_y");
  		garage[i][garage_exit_z] = sql_get_field_assoc_float_ex(garage_player, i, "garage_exit_z");


  		garage[i][garage_exit_x_car] = sql_get_field_assoc_float_ex(garage_player, i, "garage_exit_x_car");
  		garage[i][garage_exit_y_car] = sql_get_field_assoc_float_ex(garage_player, i, "garage_exit_y_car");
  		garage[i][garage_exit_z_car] = sql_get_field_assoc_float_ex(garage_player, i, "garage_exit_a_car");
  		garage[i][garage_exit_a_car] = sql_get_field_assoc_float_ex(garage_player, i, "garage_exit_z_car");

  		CreateDynamicPickup(13702, 23, -1026.7318,-2611.7268,18.6245, -1, -1, -1, STREAM_DISTANCE_DYNAMIC_PICKUP);

		create_dynamic_area(garage[i][garage_enter_x], garage[i][garage_enter_y], garage[i][garage_enter_z], -1, i, GARAGE_ENTER, 3.5);
		create_dynamic_area(-1026.7318,-2611.7268,18.6245, -1, i, GARAGE_EXIT_P);
		create_dynamic_area(-1029.1536,-2615.8589,18.4220, -1, i, GARAGE_EXIT_C);



		garage[i][garage_pickup] = CreateDynamicPickup(13702, 23, garage[i][garage_enter_x], garage[i][garage_enter_y], garage[i][garage_enter_z], -1, -1, -1, STREAM_DISTANCE_DYNAMIC_PICKUP);

		garage[i][garage_mapicon] = CreateDynamicMapIcon(garage[i][garage_enter_x], garage[i][garage_enter_y], garage[i][garage_enter_z], 56, COLOR_WHITE, 0, -1, -1, 100.0);

		new 
			fmt_str[45];

		format(fmt_str, 45, "\
			Гараж "cBLUE"№%d\n\
			%s", i+1, (garage[i][garage_owner_id] == -1) ? (""cGR"Продается") : (""cLRED"Занят"));

		garage[i][garage_3dtext] = CreateDynamic3DTextLabel(fmt_str, -1, garage[i][garage_enter_x], garage[i][garage_enter_y], garage[i][garage_enter_z], 5.0);

		create_dynamic_area(-1029.4912,-2612.8867,18.6245, -1, i, GARAGE_PANEL_CHANGE);
		
  		all_garage++;
  		all_garage_add++;
	}


	CreateDynamic3DTextLabel(""cWH"Выход из гаража\n"cBLUE"[ALT]",-1, \
	-1026.7318,-2611.7268,18.6245, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	


	CreateDynamic3DTextLabel(""cWH"Управление гаражом\n"cBLUE"[ALT]",-1, \
	-1029.4912,-2612.8867,18.6245, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);		


	printf("[Гаражи]: <%i из %i>. Времени затрачено: <%d мс>" , all_garage_player, all_garage, GetTickCount()-  time);

	return true;
}

callback:: save_garage(h)
{
    static 
    	formate_str[1000];

    formate_str[0] = EOS; 

    format(formate_str, 1000, "UPDATE `garage` SET \
    	garage_owner_id = '%d',\
    	garage_class = '%d',\
    	garage_price = '%d',\
    	garage_lock = '%d',\
    	garage_nalog = '%d',\
    	garage_day = '%d',\
		garage_sell_count_payday = '%d',\
		garage_sell_status = '%d'\
    	WHERE garage_id = '%d'",
    	garage[h][garage_owner_id],
    	garage[h][garage_class],
    	garage[h][garage_price],
    	garage[h][garage_lock],
    	garage[h][garage_takings],
    	garage[h][garage_days],

		garage[h][garage_sell_count_payday],
		garage[h][garage_sell_status],  	

    	garage[h][garage_id]);

    sql_queryEx(zConn, formate_str, QUERY_THREADED);	

    return true;
}

stock update_3d_text_garage(h)
{


	new 
		fmt_str[45];

	format(fmt_str, 45, "\
		Гараж "cBLUE"№%d\n\
		%s", h+1, (garage[h][garage_owner_id] == -1) ? (""cGR"Продается") : (""cLRED"Занят"));

	UpdateDynamic3DTextLabelText(garage[h][garage_3dtext], -1, fmt_str);

	if(garage[h][garage_sell_status] == 3)
	{
		format(fmt_str, 45, "\
			Гараж "cBLUE"№%d\n\
			%s\n\n"cORANGE"Гараж опечатан", h+1, (garage[h][garage_owner_id] == -1) ? (""cGR"Продается") : (""cLRED"Занят"));

		UpdateDynamic3DTextLabelText(garage[h][garage_3dtext], -1, fmt_str);

	}

	return true;
}

stock sell_garage_payday(h)
{
	if(garage[h][garage_owner_id] == -1) 
		return printf("Ошибка! Гараж №%d никому не принадлежит!", h);

	new 
		owner_id = garage[h][garage_owner_id];

	new 
		owner_garage_name[32];


	GetPlayerNameByID(owner_id, owner_garage_name);

	new 
		player_id = GetPlayerID(owner_garage_name);	

	new 
		final_money = floatround(garage[h][garage_price]*0.8);



	if(IsPlayerConnected(player_id))
	{
		if(pData[player_id][pGarage] == h)
		{	
			pData[player_id][pGarage] = -1;
			UpdatePlayerData(player_id,"pGarage", pData[player_id][pGarage]);
			SFCM(player_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Ваш гараж был продан за неуплату!");	

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

		format(formate_str, 80, "UPDATE accounts SET pGarage = '-1' WHERE pGarage = '%d'", h);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	

		format(String256,sizeof(String256),"UPDATE `accounts` SET returnmoney = returnmoney + %d WHERE id = '%i'", final_money, owner_id);
		sql_queryEx(zConn, String256, QUERY_THREADED);

		send_off_message(-1, owner_garage_name, "Ваш гараж был продан за неуплату!");
	}


	garage[h][garage_sell_count_payday] = RandomEx(2, 22);
	garage[h][garage_owner_id] = -1;
	garage[h][garage_sell_status] = 3;			

	update_3d_text_garage(h);
	save_garage(h);

	return true;
}

stock get_class_garage(h)
{
	new 
		name[20],
		class = garage[h][garage_class];

	switch(class)
	{
		case 1: name = "Низкий";
		case 2: name = "Средний";
		case 3: name = "Высокий";
		case 4: name = "Особняк";
		default: name = "Заброшенный";
	}
	return name;
}


stock info_garage(playerid, g)
{

	static 
		garage_classs[24],
		garage_owners[24];

	format(garage_classs, 24, "%s", get_class_garage(g));

	if(garage[g][garage_owner_id] != -1)
	{
		GetPlayerNameByID(garage[g][garage_owner_id], garage[g][garage_owner_name]);
		format(garage_owners, 24, garage[g][garage_owner_name]);
	}
	else
	{
		format(garage_owners, 24, "Государство");	
	}

	if(garage[g][garage_owner_id] == -1)
	{
		format(String512,sizeof(String512),"\
			"cWH"Номер гаража: 		\t\t"cBLUE"%d\n\
			"cWH"Класс гаража:		\t\t"cBLUE"%s\n\
			"cWH"Владелец: 			\t"cBLUE"%s\n\
			"cWH"Статус: 			\t\t%s\n\
			"cWH"Цена: 				\t"cGR"%d рублей\n\
			"cWH"Ежедневная оплата: \t\t\t"cGR"%d рублей\n\n\
			"cBLUE"Вы действительно хотите купить гараж?",
			garage[g][garage_id]+1,
			garage_classs,
			garage_owners,
			(garage[g][garage_owner_id] == -1) ? (""cGR"Продается") : (""cLRED"Куплен"),
			garage[g][garage_price], garage[g][garage_takings]);
		SPD(playerid, DIALOG_BUY_GARAGE, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка гаража", String512, !"Купить", !"Закрыть");		
	}
	else
	{
		format(String512,sizeof(String512),"\
		"cWH"Номер гаража: 		\t\t"cBLUE"%d\n\
		"cWH"Класс гаража:		\t\t"cBLUE"%s\n\
		"cWH"Владелец: 			\t"cBLUE"%s\n\
		"cWH"Статус: 			\t\t%s\n\
		"cWH"Цена: 				\t"cGR"%d рублей\n\
		"cWH"Ежедневная оплата: \t\t\t"cGR"%d рублей",
		garage[g][garage_id]+1,
		garage_classs,
		garage_owners,
		(garage[g][garage_owner_id] == -1) ? (""cGR"Открыт") : (""cLRED"Закрыт"),
		garage[g][garage_price], garage[g][garage_takings]);
		SPD(playerid, DIALOG_INFO_ENTER_GARAGE, DIALOG_STYLE_MSGBOX, !""cBLUE"Гараж", String512, !"Войти", !"Закрыть");		
	}
	

	return true;
}

cmd:garage(playerid)
{

	if(pData[playerid][pGarage] == -1)
		return SendErr(playerid, "У вас нет гаража, чтобы управлять им!");
	new 
		g = pData[playerid][pGarage];

    format(String256, sizeof(String256), "\
    "cGREY"Тип\t"cGREY"Информация\n\
    "cBLUE"- "cWH"Гараж\t%s\n\
    "cBLUE"- "cWH"Продать гараж\t"cBLUE"Продать", (garage[g][garage_lock] == 1) ? (""cGR"Открыт") : (""cLRED"Закрыт"));
    return SPD(playerid, DIALOG_CHANGE_GARAGE, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление гаражом", String256, !"Выбрать", !"Закрыть"); 
}

stock garage_door(playerid)
{

	new 
		g = pData[playerid][pGarage];

	if(garage[g][garage_lock] == 1)
	{
		garage[g][garage_lock] = 2;
		SendSucc(playerid, "Вы успешно "cLRED"закрыли"cWH" двери в гараже!");
	}
	else if(garage[g][garage_lock] == 2)
	{
		garage[g][garage_lock] = 1;
		SendSucc(playerid, "Вы успешно "cGR"открыли"cWH" двери в гараже!");
	}

	PC_EmulateCommand(playerid, "/garage");

	return true;
}

stock sell_garage_accept(playerid, g)
{
	SPD(playerid, DIALOG_ACCEPT_SELL_GARAGE, DIALOG_STYLE_MSGBOX, !""cBLUE"Продажа гаража", !"\
	"cWH"Вы уверены, что хотите продать гараж в гос.стоимость?\n\n\
	Вам будет возвращено 80%% от стоимости!", !"Да", !"Нет");

	return true;

}

stock sell_garage(playerid, g)
{
	if(garage[g][garage_owner_id] == -1) 
		return printf("Ошибка! Гараж №%d никому не принадлежит!", g);

	new 
		final_money = floatround(garage[g][garage_price]*0.8);


	if(pData[playerid][pGarage] == g)
	{	
		pData[playerid][pGarage] = -1;
		UpdatePlayerData(playerid,"pGarage", pData[playerid][pGarage]);
		
		SendSucc(playerid, "Вы успешно продали гараж в гос.стоимость!");

	 	format(String144, sizeof(String144), "Продажа гаража №%d", g);
		give_money(playerid, final_money, String144);

        vehicle_destroy(playerid);
        SendClientMessage(playerid, COLOR_LIGHTRED, "Ваша машина была отправлена на штраф-стоянку из продажи жилья!");
	}


	garage[g][garage_owner_id] = -1;

	update_3d_text_garage(g);
	save_garage(g);

	return true;
}

callback:: sell_garage_admin(h, reason[], money_back)
{
	if(garage[h][garage_owner_id] == -1) 
		return printf("Ошибка! Гараж №%d никому не принадлежит!", h);

	new 
		price = garage[h][garage_price],
		owner_id = garage[h][garage_owner_id];

	new 
		owner_garage_name[32];

	new 
		fmt_str[144];

	GetPlayerNameByID(owner_id, owner_garage_name);

	new 
		player_id = GetPlayerID(owner_garage_name);

	if(IsPlayerConnected(player_id))
	{
		if(pData[player_id][pGarage] == h)
		{	
			pData[player_id][pGarage] = -1;
			UpdatePlayerData(player_id,"pGarage", pData[player_id][pGarage]);
			SFCM(player_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Ваш гараж была продана администратором. Причина: %s", reason);	

			pData[player_id][pSpawn] = 0;
			UpdatePlayerData(player_id, "spawn", pData[player_id][pSpawn]);

			if(money_back == 1)
			{

				format(fmt_str, sizeof(fmt_str), "Возврат за продажу администратором гаража №: %d", h);
				give_money(player_id, price, fmt_str);
			}

		}
	}
	else
	{	
		new 
			formate_str[280];

		format(formate_str, 80, "UPDATE accounts SET pGarage = '-1' WHERE pGarage = '%d'", h);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	
		if(money_back == 1)
		{
			format(formate_str, sizeof(formate_str), "UPDATE `accounts` SET `bank` = bank + %i WHERE `id` = '%i'" , price, owner_id);
  			sql_queryEx(zConn, formate_str, QUERY_THREADED);
  		}

	}


   	garage[h][garage_owner_id] = -1;
    garage[h][garage_lock] = 2;
    
    garage[h][garage_days] = 3;


    save_garage(h);
	
    return true;
}


stock enter_garage_p(playerid, g)
{
	if(g == -1) 
		return true;

	if(garage[g][garage_lock] == 2)
	{
		GameTextForPlayer(playerid, "~r~closed", 2000, 3);
		return SendErr(playerid, "Гараж закрыт и Вы не сможете войти!");
	}

	SetPVarIntNew(playerid, "garage_id_vw", g);

	SetPlayerPosEx(playerid, -1026.7716,-2612.8406,18.6245,178.7631);
	SetPlayerVirtualWorld(playerid, g);
	return true;
}

stock enter_garage_p_car(playerid, g)
{
	if(g == -1) 
		return true;

	if(garage[g][garage_lock] == 2)
		return SendErr(playerid, "Гараж закрыт и Вы не сможете заехать!");

	new 
		vehid = GetPlayerVehicleID(playerid);

	if(vehid == -1)
		return enter_garage_p(playerid, g);

	SetVehiclePos(vehid, -1029.1536,-2615.8589,18.4220);
	SetVehicleZAngle(vehid, 359.9972);

	LinkVehicleToInterior(vehid, 0);
	SetVehicleVirtualWorld(vehid, g);

	SetPlayerVirtualWorld(playerid, g);


	SetPVarIntNew(playerid, "vehicle_in_garage", 1);
	SetPVarIntNew(playerid, "garage_id_vw", g);

	SendInf(playerid, "Чтобы припакровать автомобиль в гараже, используйте команду - /park");

	return true;
}


stock exit_garage_p(playerid, g)
{
	if(g == -1) 
		return true;

	DeletePVarNew(playerid, "vehicle_in_garage");
	DeletePVarNew(playerid, "garage_id_vw");


	SetPlayerPosEx(playerid, garage[g][garage_exit_x], garage[g][garage_exit_y], garage[g][garage_exit_z], 90.0);
	SetPlayerVirtualWorld(playerid, 0);


	return true;	
}


stock exit_garage_p_car(playerid, g)
{
	if(g == -1) 
		return true;


	new 
		vehid = GetPlayerVehicleID(playerid);

	if(vehid == -1)
		return exit_garage_p(playerid, g);

	SetVehiclePos(vehid, garage[g][garage_exit_x], garage[g][garage_exit_y], garage[g][garage_exit_z]);
	LinkVehicleToInterior(vehid, 0);
	SetVehicleVirtualWorld(vehid, 0);

	SetPlayerVirtualWorld(playerid, 0);

	DeletePVarNew(playerid, "vehicle_in_garage");
	DeletePVarNew(playerid, "garage_id_vw");


	return true;	
}


stock buy_garage(playerid, g)
{

	if(pData[playerid][pHouse] != -1 && pData[playerid][pFlate] != -1)
		return SendErr(playerid, "Вы не можете купить гараж, так как у Вас уже есть дом или квартира!");

	if(pData[playerid][pHouseRent] != -1 || pData[playerid][pFlateRent] != -1)
		return SendErr(playerid, "Вы уже арендуете дом или квартиру! Откажитесь от аренды для покупки!");

	if(pData[playerid][pGarage] != -1)
		return SendErr(playerid, "Вы уже владете гаражом!");	

	if(pData[playerid][pHotelRoom] != -1)
		return SendErr(playerid, "Вы уже арендуете номер в отеле!");


	if(garage[g][garage_sell_status] == 3)
		return SendErr(playerid, "Гараж недоступен для покупки в данный момент, так как он опечатан!");



	if(GetPlayerMoneyEx(playerid) < garage[g][garage_price]) 
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
		return SendErr(playerid,"У вас недостаточно денежных средств для покупки дома!");	
	}

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_buy_garage", 4000);


	garage[g][garage_owner_id] = pData[playerid][pMysqlID];

	format(garage[g][garage_owner_name], 24, pData[playerid][pNickname]);

	pData[playerid][pGarage] = g;

	UpdatePlayerData(playerid,"pGarage",pData[playerid][pGarage]);	

 	format(String144, sizeof(String144), "Покупка гаража №%d", g);
	give_money(playerid, -garage[g][garage_price], String144);

	garage[g][garage_days] = 3;
	


	save_garage(g);
	for(new i; i < all_garage; i++) update_3d_text_garage(i);

	format(String256, sizeof(String256), "\
		"cWH"Поздравляем Вас с покупкой гаража!\n\n\
		"cWH"Ежедневная оплата: "cGR"%d"cWH" рублей\n\
		"cWH"Гараж оплачен на "cBLUE"%d"cWH" дней",
		garage[g][garage_takings], garage[g][garage_days]);
	return SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка гаража", String256, !"Понял", !"");	
}

stock dialog_all_garage(playerid, dialogid, response, listitem)
{

	switch(dialogid)
	{
		case DIALOG_BUY_GARAGE:
		{
			if(!response)
				return true;

			new 
				id_garage = pTemp[playerid][area_item_id];

			buy_garage(playerid, id_garage);

		}
		case DIALOG_INFO_ENTER_GARAGE:
		{
			if(!response)
				return true;
			new 
				id_garage = pTemp[playerid][area_item_id];

			enter_garage_p(playerid, id_garage);	
		}
		case DIALOG_CHANGE_GARAGE:
		{
			if(!response)
				return true;

			new 
				g = pData[playerid][pGarage];

			switch(listitem)
			{
				case 0: return garage_door(playerid);
				case 1: return sell_garage_accept(playerid, g);
			}	
		}
		case DIALOG_ACCEPT_SELL_GARAGE:
		{
			if(!response)
				return PC_EmulateCommand(playerid, "/garage");

			sell_garage(playerid, pData[playerid][pGarage]);				
		}
	}
	return true;
}


CMD:addgarage(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    new 
    	Float:x,Float:y,Float:z;

    if(sscanf(params, "dd",params[0], params[1]))
    {
    	SendInf(playerid, "Используйте: /addgarage [Класс] [Цена]");
    	SendInf(playerid, "1 - Низкий | 2 - Средний | 3 - Высокий");
    	return true;
    }

    if(params[0] < 1 || params[0] > 4) 
    	return SendInf(playerid, "1 - Низкий | 2 - Средний | 3 - Высокий");


    GetPlayerPos(playerid, x, y, z);
    
	static 
		formate_str[310];

    format(formate_str, 310, "INSERT INTO garage(garage_enter_x, garage_enter_y, garage_enter_z, garage_exit_x, garage_exit_y, garage_exit_z, garage_class, garage_price) VALUES ('%f','%f','%f','%f','%f','%f','%d','%d')",
    x, y, z, x, y, z, params[0], params[1]);
    sql_queryEx(zConn, formate_str, QUERY_THREADED);	

    formate_str[0] = EOS;

    all_garage_add++;

    SFCM(playerid, -1,!"• {FFC800}[Подсказка] "cWH"Номер гаража в БД - %d", all_garage_add);	


    SendSucc(playerid, "Вы добавили гараж! Он появится после рестарта!");
    SendInf(playerid, "Чтобы обновить позицию спавна у гаража, используйте - /addgaragepark [ID гаража в БД]");
	return true;
}

CMD:addgaragepark(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    if(sscanf(params, "d",params[0]))
    {
    	SendInf(playerid, "Используйте: /addgaragepark [ID Гаража]");
    	SendInf(playerid, "Так же Вы должны находиться в автомобиле!");
    	return true;
    }

    new 
    	Float:x, Float:y, Float:z, Float:a;
    
	static 
		formate_str[310];

	GetVehiclePos(GetPlayerVehicleID(playerid), x, y, z);
	GetVehicleZAngle(GetPlayerVehicleID(playerid), a);

    format(formate_str, 1000, "UPDATE `garage` SET \
    	garage_exit_x_car = '%f',\
    	garage_exit_y_car = '%f',\
    	garage_exit_z_car = '%f',\
    	garage_exit_a_car = '%f'\
    	WHERE garage_id = '%d'",
    	x,
    	y,
    	z,
    	a,
    	params[0]);

    sql_queryEx(zConn, formate_str, QUERY_THREADED);	

    formate_str[0] = EOS;

    SendSucc(playerid, "Вы обновили позицию выезда авто у гаража, обновится после рестарта!");
	return true;
}

CMD:gotogarage(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

	if(sscanf(params, "d", params[0]))
	{
		SendInf(playerid, "Используйте: /gotogarage "cWH"[ID Гаража]");
		return true;
	}

	new 
		id_garage = params[0];


	SetPlayerPos(playerid, garage[id_garage][garage_enter_x], garage[id_garage][garage_enter_y], garage[id_garage][garage_enter_z]);

	new 
		fmt_str[144];

    format(fmt_str, sizeof(fmt_str), "Вы телепортировались к гаражу №%d", id_garage);
    SendSucc(playerid, fmt_str);
	return true;
}


CMD:asellgarage(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    if(sscanf(params, "ds[32]d",params[0],params[1],params[2])) 
    	return SendInf(playerid, "Используйте: /asellgarage [ID гаража] [Причина] [Возврат денег (1 - вернуть | 2 - не возвращать)]");


	new 
		fmt_str[350];

    format(fmt_str, sizeof(fmt_str), "Вы успешно продали гараж №%d", params[0]);
    SendSucc(playerid, fmt_str);

	sell_garage_admin(params[0], params[1], params[2]);

	return true;
}