static const mounth_casino_stats[][] =
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




callback:: load_casino_server()
{

	new Result:casino_loads = sql_queryEx(zConn, "SELECT * FROM `casino` ORDER BY `casino_id`", QUERY_CACHED);

	new all_casino_loads_serv = sql_num_rows(casino_loads);

	new time = GetTickCount();

 	for(new i; i < all_casino_loads_serv; i++)
	{

		casino[i][casino_id]  = sql_get_field_assoc_int_ex(casino_loads, i, "casino_id"); 

		casino[i][casino_owner_id]  = sql_get_field_assoc_int_ex(casino_loads, i, "casino_owner_id"); 

		casino[i][casino_buy_price]  = sql_get_field_assoc_int_ex(casino_loads, i, "casino_buy_price"); 
		casino[i][casino_closed_status]  = sql_get_field_assoc_int_ex(casino_loads, i, "casino_closed_status"); 
		casino[i][casino_day]  = sql_get_field_assoc_int_ex(casino_loads, i, "casino_day"); 
		casino[i][casino_bank]  = sql_get_field_assoc_int_ex(casino_loads, i, "casino_bank"); 	

		casino[i][casino_finka_ogran]  = sql_get_field_assoc_int_ex(casino_loads, i, "casino_finka_ogran"); 	

  		casino[i][casino_pos_x] = sql_get_field_assoc_float_ex(casino_loads, i, "casino_pos_x");
  		casino[i][casino_pos_y] = sql_get_field_assoc_float_ex(casino_loads, i, "casino_pos_y");
  		casino[i][casino_pos_z] = sql_get_field_assoc_float_ex(casino_loads, i, "casino_pos_z");

  		casino[i][casino_takings] = sql_get_field_assoc_int_ex(casino_loads, i, "casino_takings");

  		casino[i][casino_finka_day] = sql_get_field_assoc_int_ex(casino_loads, i, "casino_finka_day");

  		casino[i][casino_buy_status] = sql_get_field_assoc_int_ex(casino_loads, i, "casino_buy_status");
  		casino[i][casino_sell_day_payday] = sql_get_field_assoc_int_ex(casino_loads, i, "casino_sell_day_payday");



		casino[i][casino_icon] = CreateDynamicMapIcon(casino[i][casino_pos_x], casino[i][casino_pos_y], casino[i][casino_pos_z], 25 , -1);

		create_dynamic_area(casino[i][casino_pos_x], casino[i][casino_pos_y], casino[i][casino_pos_z], -1, i, CASINO_ENTER);

		create_dynamic_area(CASINO_EXIT_COORD, 5, i, CASINO_EXIT);

		CreateDynamic3DTextLabel(""cWH"Выход из казино\n"cBLUE"[ALT]",-1, \
		CASINO_EXIT_COORD, 2.0, -1, INVALID_VEHICLE_ID, 0, 5);	

		CreateDynamic3DTextLabel(""cWH"Вход из казино\n"cBLUE"[ALT]",-1, \
		casino[i][casino_pos_x], casino[i][casino_pos_y], casino[i][casino_pos_z], 2.0, -1, INVALID_VEHICLE_ID, 0, -1);	

		new
			h_owner[24];

		if(casino[i][casino_owner_id] != -1)
		{
			GetPlayerNameByID(casino[i][casino_owner_id], casino[i][casino_owner_name]);
			format(h_owner, 24, casino[i][casino_owner_name]);
		}
		else
		{
			format(h_owner, 24, "Государство");	
		}


		format(String256, sizeof(String256), "\
			"cBLUE"Казино: "cWH"Даймонд\n\n\
			"cBLUE"Владелец: "cWH"%s\n\
			"cBLUE"Cтоимость: "cWH"%dр\n\n\
			"cBLUE"[ALT]",h_owner, casino[i][casino_buy_price]);

		casino[i][casino_pick_info] = CreateDynamic3DTextLabel(String256, -1, casino[i][casino_pos_x], casino[i][casino_pos_y], casino[i][casino_pos_z], 5.0);

		CreateDynamicPickup(13702, 23, casino[i][casino_pos_x], casino[i][casino_pos_y], casino[i][casino_pos_z], -1, -1, -1, 45.0);	
		CreateDynamicPickup(13702, 23, CASINO_EXIT_COORD, -1, -1, -1, 45.0);	

		all_casino++;

	}

	create_casino_other();

	printf("[Казино]: <%i из %i>. Времени затрачено: <%d мс>" , all_casino_loads_serv, all_casino, GetTickCount()-  time);

	sql_next_row(casino_loads);

	return true;
}

callback:: save_casino(h)
{
	new time = GetTickCount();

    format(String1024, sizeof(String1024), "UPDATE `casino` SET \
    	casino_owner_id = '%d',\
    	casino_buy_price = '%d',\
    	casino_closed_status = '%d',\
    	casino_day = '%d',\
    	casino_bank = '%d',\
    	casino_finka_ogran = '%d',\
    	casino_pos_x = '%f',\
    	casino_pos_y = '%f',\
    	casino_pos_z = '%f',\
    	casino_finka_day = '%d',\
    	casino_takings = '%d',\
    	casino_buy_status = '%d',\
    	casino_sell_day_payday = '%d'\
    	WHERE casino_id = '%d'",
    	casino[h][casino_owner_id],
    	casino[h][casino_buy_price],
    	casino[h][casino_closed_status],
    	casino[h][casino_day],
    	casino[h][casino_bank],
    	casino[h][casino_finka_ogran],
    	casino[h][casino_pos_x],
    	casino[h][casino_pos_y],
    	casino[h][casino_pos_z],
    	casino[h][casino_finka_day],
    	casino[h][casino_takings],
 
		casino[h][casino_buy_status],
		casino[h][casino_sell_day_payday],

    	casino[h][casino_id]);

    sql_queryEx(zConn, String1024, QUERY_THREADED);	

	if(debug_mode)
	{
		printf("[save_casino]: Времени затрачено: <%d мс>" , GetTickCount() - time);
	}

    return true;
}

stock update_casino_3d_text(i)
{
	new
		h_owner[24];

	if(casino[i][casino_owner_id] != -1)
	{
		GetPlayerNameByID(casino[i][casino_owner_id], casino[i][casino_owner_name]);
		format(h_owner, 24, casino[i][casino_owner_name]);
	}
	else
	{
		format(h_owner, 24, "Государство");	
	}


	format(String256, sizeof(String256), "\
		"cBLUE"Казино:\n"cWH"Даймонд\n\n\
		"cBLUE"Владелец: "cWH"%s\n\
		"cBLUE"Cтоимость: "cWH"%dр\n\n\
		"cBLUE"[ALT]",h_owner, casino[i][casino_buy_price]);

	UpdateDynamic3DTextLabelText(casino[i][casino_pick_info], -1, String256);	

	if(casino[i][casino_sell_day_payday] >= 0)
	{
		format(String256, sizeof(String256), "\
			"cBLUE"Казино:\n"cWH"Даймонд\n\n\
			"cORANGE"Казино опечатано\n\n\
			"cBLUE"Владелец: "cWH"%s\n\
			"cBLUE"Cтоимость: "cWH"%dр\n\n\
			"cBLUE"[ALT]",h_owner, casino[i][casino_buy_price]);

		UpdateDynamic3DTextLabelText(casino[i][casino_pick_info], -1, String256);	

	}

}

stock create_casino_other()
{

    for(new i; i < MAX_TABLE; i++)
	{
		casino_tables[i][casino_t_players][0] =  casino_tables[i][casino_t_players][1] =  casino_tables[i][casino_t_players][2] =  casino_tables[i][casino_t_players][3] =  casino_tables[i][casito_t_crup] = -1; 
		casino_tables[i][casino_step] = 20,
		casino_tables[i][casino_t_bet] = 0,
		casino_tables[i][casino_t_bank] = 0,
		casino_tables[i][casino_t_status] = false;
	}


	CreateDynamic3DTextLabel(""cWH"Игровой Стол №1\n"cBLUE"[H]",-1, \
	19.5672,1007.6366,1301.1404-0.5, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	CreateDynamic3DTextLabel(""cWH"Игровой Стол №2\n"cBLUE"[H]",-1, \
	17.4072,1013.3321,1301.1404-0.5, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	CreateDynamic3DTextLabel(""cWH"Игровой Стол №3\n"cBLUE"[H]",-1, \
	11.1989,1016.8100,1301.1404-0.5, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	CreateDynamic3DTextLabel(""cWH"Игровой Стол №4\n"cBLUE"[H]",-1, \
	5.1953,1013.2671,1301.1404-0.5, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	


	CreateDynamic3DTextLabel(""cWH"Устройство на работу крупье\n"cLRED"[H]",-1, \
	21.0153,994.7589,1300.5625, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	

	//casino_table[0] = create_circle_pickup(-116.6234,985.9886,12.1494, TRIGGER_LBLUE);

	casino_actor[0] = CreateActor(12, 0.6511,975.5217,1300.5697,314.5873);
	SetActorVirtualWorld(casino_actor[0], 5);
	casino_actor[1] = CreateActor(17, -9.4630,972.4041,1301.0000,29.4513);
	SetActorVirtualWorld(casino_actor[1], 5);
	casino_actor[2] = CreateActor(17, -12.1341,1001.2014,1300.7969,182.7163);
	SetActorVirtualWorld(casino_actor[2], 5);
	casino_actor[3] = CreateActor(59, 11.9012,989.9748,1300.5625,357.0291);
	SetActorVirtualWorld(casino_actor[3], 5);
	casino_actor[4] = CreateActor(163,17.3787,1003.3265,1300.5625,65.4733);
	SetActorVirtualWorld(casino_actor[4], 5);
	casino_actor[5] = CreateActor(163,2.4221,984.4646,1300.5625,314.6440);
	SetActorVirtualWorld(casino_actor[5], 5);
	casino_actor[6] = CreateActor(163,-12.6874,985.8334,1301.0000,314.0992);
	SetActorVirtualWorld(casino_actor[6], 5);


	ApplyActorAnimation(casino_actor[4], "COP_AMBIENT", "coplook_loop", 4.1, 1, 1, 1, 0, 0);
	ApplyActorAnimation(casino_actor[5], "COP_AMBIENT", "coplook_loop", 4.1, 1, 1, 1, 0, 0);
	ApplyActorAnimation(casino_actor[6], "COP_AMBIENT", "coplook_loop", 4.1, 1, 1, 1, 0, 0);

	casino_table[1] = CreateDynamicSphere(19.5672,1007.6366,1301.1404, 4.5, 5);
	casino_table[2] = CreateDynamicSphere(17.4072,1013.3321,1301.1404, 4.5, 5);
	casino_table[3] = CreateDynamicSphere(11.1989,1016.8100,1301.1404, 4.5, 5);
	casino_table[4] = CreateDynamicSphere(5.1953,1013.2671,1301.1404, 4.5, 5);

	casino_start_job = create_circle_pickup(21.0153,994.7589,1300.5625, TRIGGER_LRED);


    return true;
}

stock sell_casino_payday(f)
{


	new 
		owner_id = casino[f][casino_owner_id];

	new 
		owner_garage_name[32];


	GetPlayerNameByID(owner_id, owner_garage_name);

	new 
		player_id = GetPlayerID(owner_garage_name);	

	new 
		final_money = floatround(casino[f][casino_buy_price]*0.8);


	if(IsPlayerConnected(player_id))
	{
		if(pData[player_id][pCasinoOwner] == f)
		{	
			pData[player_id][pCasinoOwner] = -1;
			UpdatePlayerData(player_id,"pCasinoOwner", pData[player_id][pCasinoOwner]);
			SFCM(player_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Ваше казино было продана за неуплату!");	

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

		format(formate_str, 80, "UPDATE accounts SET pCasinoOwner = '-1' WHERE pCasinoOwner = '%d'", owner_id);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	

		format(String256,sizeof(String256),"UPDATE `accounts` SET returnmoney = returnmoney + %d WHERE id = '%i'", final_money, owner_id);
		sql_queryEx(zConn, String256, QUERY_THREADED);

		send_off_message(-1, owner_garage_name, "Ваше казино продано государству за неуплату. Мы вернули 80 процентов (/returnmoney)");
	}




	casino[f][casino_owner_id] = -1;	
	casino[f][casino_bank] = 0;

	casino[f][casino_buy_status] = 3;
	casino[f][casino_sell_day_payday] = RandomEx(2, 22);	

	update_casino_3d_text(f);
	save_casino(f);
	return true;
}

stock sell_casino_temp(f)
{


	new 
		owner_id = casino[f][casino_owner_id];

	new 
		owner_garage_name[32];


	GetPlayerNameByID(owner_id, owner_garage_name);

	new 
		player_id = GetPlayerID(owner_garage_name);	

	new 
		final_money = floatround(casino[f][casino_buy_price]*0.8);


	if(IsPlayerConnected(player_id))
	{
		if(pData[player_id][pCasinoOwner] == f)
		{	
			pData[player_id][pCasinoOwner] = -1;
			UpdatePlayerData(player_id,"pCasinoOwner", pData[player_id][pCasinoOwner]);
			SFCM(player_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Ваше казино было продана за неуплату!");	
		}
	}
	else
	{	
		new 
			formate_str[280];

		format(formate_str, 80, "UPDATE accounts SET pCasinoOwner = '-1' WHERE pCasinoOwner = '%d'", owner_id);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	
	}




	casino[f][casino_owner_id] = -1;	
	casino[f][casino_bank] = 0;

	casino[f][casino_buy_status] = 3;
	casino[f][casino_sell_day_payday] = RandomEx(2, 22);	

	update_casino_3d_text(f);
	save_casino(f);
	return true;
}

stock sell_casino_accept(playerid)
{
	SPD(playerid, DIALOG_ACCEPT_SELL_CASINO, DIALOG_STYLE_MSGBOX, !""cBLUE"Продажа казино", !"\
	"cWH"Вы уверены, что хотите продать казино государству?\n\n\
	Вам будет возвращено 80% от стоимости!", !"Да", !"Нет");

	return true;

}

stock sell_casino(playerid, f)
{


	if(pData[playerid][pCasinoOwner] == f)
	{

		new 
			final_money = floatround(casino[f][casino_buy_price]*0.8);

		pData[playerid][pCasinoOwner] = -1;
		UpdatePlayerData(playerid,"pCasinoOwner", pData[playerid][pCasinoOwner]);

		SendSucc(playerid, "Вы продали казино государству!");

		give_money(playerid, final_money, "Продажа казино");

		casino[f][casino_owner_id] = -1;	
		casino[f][casino_bank] = 0;

		update_casino_3d_text(f);
		save_casino(f);	
	}

	return true;
}

stock select_menu_enter_casino(playerid, h)
{

	if(casino[h][casino_owner_id] == -1)
	{
		format(String144, sizeof(String144), "\
	 	"cBLUE"- "cWH"Информация о покупке казино\n\
		"cBLUE"- "cWH"Войти в казино");
		SPD(playerid, DIALOG_SELECT_ENTER_CASINO, DIALOG_STYLE_LIST, !""cBLUE"Вход в казино", String144, !"Выбрать", !"Закрыть"); 
	}	
    else 
    {
    	enter_casino(playerid);
    }
    return true;
}

stock info_casino(playerid, h)
{

	static 
		casino_owner[24];

	if(casino[h][casino_owner_id] != -1)
	{
		GetPlayerNameByID(casino[h][casino_owner_id], casino[h][casino_owner_name]);
		format(casino_owner, 24, casino[h][casino_owner_name]);
	}
	else
	{
		format(casino_owner, 24, "Государство");	
	}

	if(casino[h][casino_owner_id] == -1)
	{
		format(String512, sizeof(String512), "\
		"cWH"Владелец: 			\t"cBLUE"%s\n\
		"cWH"Статус: 			\t\t%s\n\
		"cWH"Цена: 				\t"cGR"%d рублей\n\
		"cWH"Ежедневная оплата: \t\t\t"cGR"%d рублей\n\n\
		"cBLUE"Вы действительно хотите купить казино?",
		casino_owner,
		(casino[h][casino_owner_id]) ? (""cGR"Продается") : (""cLRED"Куплен"),
		casino[h][casino_buy_price], casino[h][casino_takings]);
		SPD(playerid, DIALOG_BUY_CASINO, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка казино", String512, !"Купить", !"Закрыть");		
	}
	else
	{
		enter_casino(playerid);	
	}
	return true;
}




stock enter_casino(playerid)
{
	if(pData[playerid][pLevel] < 3)
		return SendErr(playerid, "Вход в казино доступен с 3-го уровня!");

	if(casino[0][casino_closed_status] == 2)
	{	
		GameTextForPlayer(playerid, "~r~closed", 2000, 3);
		return SendInf(playerid, "Казино в данный момент закрыто, вход невозможен!");
	}

	SetPlayerPosEx(playerid, -16.4215,978.4986,1301.0000,269.7063);
	SetPlayerVirtualWorld(playerid, 5);
	SetCameraBehindPlayer(playerid);
	return true;
}

stock exit_casino(playerid)
{
	leave_crupie_casino(playerid);

	SetPlayerPosEx(playerid, casino[0][casino_pos_x], casino[0][casino_pos_y], casino[0][casino_pos_z], 90.0);
	SetCameraBehindPlayer(playerid);
	SetPlayerVirtualWorld(playerid, 0);

	return true;
}


stock buy_casino(playerid, h)
{

	if(pData[playerid][pBusiness] != -1)
		return SendErr(playerid, "Вы не можете купить бизнес, так как уже владеете бизнесом!");

	if(pData[playerid][pHotelOwner] != -1)
		return SendErr(playerid, "Вы не можете купить бизнес, так как уже владеете бизнесом!");

	if(pData[playerid][pMechOwnerID] != -1)
		return SendErr(playerid,  "Вы не можете купить бизнес,  как уже владеете бизнесом!");

	if(pData[playerid][pFillStation] != -1)
		return SendErr(playerid,  "Вы не можете купить бизнес, так как уже владеете бизнесом!");

	if(pData[playerid][pCasinoOwner] != -1)
		return SendErr(playerid, "Вы не можете купить бизнес, так как уже владеете бизнесом!");

	if(casino[h][casino_buy_status] == 3)
		return SendErr(playerid, "Казино недоступно для покупки в данный момент, так как оно опечатано!");


	if(casino[h][casino_owner_id] != -1)
		return SendErr(playerid, "Казино недоступно для покупки!");

	if(GetPlayerMoneyEx(playerid) < casino[h][casino_buy_price]) 
		return SendErr(playerid,"У вас недостаточно денежных средств для покупки казино!");	

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_buy_casino", 4000);

	casino[h][casino_owner_id] = pData[playerid][pMysqlID];

	format(casino[h][casino_owner_name], 24, pData[playerid][pNickname]);
	casino[h][casino_day] = 3;

	pData[playerid][pCasinoOwner] = h;

	UpdatePlayerData(playerid,"pCasinoOwner",pData[playerid][pCasinoOwner]);	

	give_money(playerid, -casino[h][casino_buy_price], "Покупка казино");

	save_casino(h);
	update_casino_3d_text(h);

	format(String512, sizeof(String512), "\
		"cWH"Поздравляем Вас с приобретением казино!\n\n\
		"cWH"Ежедневная оплата: "cGR"%d"cWH" рублей\n\n\
		"cWH"Казино оплачено на "cBLUE"%d"cWH" дней\n\
		Советутем Вам посетить банк для оплаты!",
		casino[h][casino_takings], casino[h][casino_day]);
	return SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Казино", String512, !"Понял", !"");
}

CMD:casino(playerid)
{
	if(pData[playerid][pCasinoOwner] == -1)
		return SendErr(playerid, "Вы не владете казино!");	
	
	return change_panel_casino(playerid);
}

stock change_panel_casino(playerid)
{
	if(pData[playerid][pCasinoOwner] == -1)
		return SendErr(playerid, "Вы не владете казино!");	

	new 
		casino_ids = pData[playerid][pCasinoOwner];

    format(String512, sizeof(String512), "\
    "cGREY"Тип\t"cGREY"Информация\n\
    "cBLUE"- "cWH"Свободных рабочих мест крупье\t"cBLUE"%d мест\n\
    "cBLUE"- "cWH"Казино оплачено на\t"cBLUE"%d"cWH" дней\n\
    "cBLUE"- "cWH"Налог в сутки\t"cGR"%d"cWH" рублей\n\
    "cBLUE"- "cWH"Ограничение по прибыли в сутки\t"cGR"%d/%d"cWH" рублей\n\n\
    "cBLUE"- "cWH"Касса казино\t"cBLUE"Открыть\n\
    "cBLUE"- "cWH"Статистика казино\t"cBLUE"Изучить", casino_total_crupie, casino[casino_ids][casino_day], 
    casino[casino_ids][casino_takings], casino[casino_ids][casino_finka_day], casino[casino_ids][casino_finka_ogran]);
    return SPD(playerid, DIALOG_CHANGE_PANEL_CASINO, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление казино", String512, !"Выбрать", !"Закрыть"); 
}

stock change_bank_casino(playerid)
{
	if(pData[playerid][pCasinoOwner] == -1)
		return SendErr(playerid, "Вы не владете казино!");	
	new 
		casino_ids = pData[playerid][pCasinoOwner];

    format(String512, sizeof(String512), "\
    "cGREY"Тип\t"cGREY"Информация\n\
    "cBLUE"- "cWH"Снять деньги с кассы казино\t"cGR"%d"cWH" рублей\n\
    "cBLUE"- "cWH"Положить деньги в кассу казино\tПоложить", casino[casino_ids][casino_bank]);
    return SPD(playerid, DIALOG_CHANGE_BANK_CASINO, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Банк казино", String512, !"Выбрать", !"Закрыть"); 

}

stock change_bank_casino_input(playerid)
{
	if(pData[playerid][pCasinoOwner] == -1)
		return SendErr(playerid, "Вы не владете казино!");		
	new 
		casino_ids = pData[playerid][pCasinoOwner];

	format(String256, sizeof(String256), "\
	"cWH"В кассе Вашего казино находится "cGR"%d рублей"cWH" на данный момент\n\n\
	"cBLUE"Сколько денег Вы хотите взять?", casino[0][casino_bank]);

	return SPD(playerid, DIALOG_INPUT_MONEY_BANK_CASINO, DIALOG_STYLE_INPUT, !""cBLUE"Касса казино", String256, !"Далее", !"Назад");
}
stock change_bank_casino_put(playerid)
{
	new 
		casino_ids = pData[playerid][pCasinoOwner];


	format(String256, sizeof(String256), "\
	"cWH"В кассе Вашего казино находится "cGR"%d рублей"cWH" на данный момент\n\n\
	"cBLUE"Сколько денег Вы хотите положить?", casino[0][casino_bank]);

	return SPD(playerid, DIALOG_PUT_MONEY_BANK_CASINO, DIALOG_STYLE_INPUT, !""cBLUE"Касса казино", String256, !"Далее", !"Назад");
}


stock dialog_all_casino(playerid, dialogid, response, listitem, inputtext[])
{

	switch(dialogid)
	{
		case DIALOG_BUY_CASINO:
		{
			if(!response) 
				return true;


			new 
				id_casino = pTemp[playerid][area_item_id];


			buy_casino(playerid, id_casino);

		}
		case DIALOG_SELECT_ENTER_CASINO:
		{
			if(!response) 
				return true;

			new 
				id_casino = pTemp[playerid][area_item_id];


			switch(listitem)
			{
				case 0: return info_casino(playerid, id_casino);
				case 1: return enter_casino(playerid);
			}			
		}
		case DIALOG_CHANGE_CASINO_CLOSE:
		{
			if(!response) 
				return change_panel_casino(playerid);

			return change_panel_casino(playerid);
		}
		case DIALOG_CHANGE_PANEL_CASINO:
		{
			if(!response) 
				return true;

			switch(listitem)
			{
				case 0: return change_panel_casino(playerid);
				case 1: return change_panel_casino(playerid);
				case 2: return change_panel_casino(playerid);
				case 3: return change_panel_casino(playerid);
				case 4: return change_panel_casino(playerid);
				case 5: return change_bank_casino(playerid);
				case 6: return change_statistic_casino(playerid);
			}			
		}
		case DIALOG_CHANGE_BANK_CASINO:
		{
			if(!response) 
				return change_panel_casino(playerid);

			switch(listitem)
			{
				case 0: return change_bank_casino_input(playerid);
				case 1: return change_bank_casino_put(playerid);
			}			
		}
		case DIALOG_ACCEPT_SELL_CASINO:
		{
			if(!response) 
				return change_panel_casino(playerid);
			new 
				casino_ids = pData[playerid][pCasinoOwner];

			sell_casino(playerid, casino_ids);		

		}
		case DIALOG_INPUT_MONEY_BANK_CASINO:
		{
			new 
				casino_ids = pData[playerid][pCasinoOwner];

			if(!response)
				return change_bank_casino(playerid);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное количество денег!");
				return change_bank_casino_input(playerid);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное количество денег!");
				return change_bank_casino_input(playerid);			
			}


			new 
				count_money_input = strval(inputtext);

			if(count_money_input < 1)
			{
				SendErr(playerid,"У вас недостаточно денег в кассе казино!");
				return change_bank_casino_input(playerid);		
			}

			if(casino[casino_ids][casino_bank] < count_money_input)
			{
				SendErr(playerid,"У вас недостаточно денег в кассе казино!");
				return change_bank_casino_input(playerid);				
			}

			casino[casino_ids][casino_bank] -= count_money_input;

			give_money(playerid, count_money_input, "Деньги из кассы казино");

			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы взяли из кассы казино - "cGR"%d рублей"cWH"", count_money_input);	

			change_bank_casino(playerid);

			save_casino(casino_ids);
		}
		case DIALOG_PUT_MONEY_BANK_CASINO:
		{
			new 
				casino_ids = pData[playerid][pCasinoOwner];

			if(!response)
				return change_bank_casino(playerid);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное количество денег!");
				return change_bank_casino_put(playerid);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное количество денег!");
				return change_bank_casino_put(playerid);			
			}


			new 
				count_money_put = strval(inputtext);

			if(count_money_put < 1)
			{
				SendErr(playerid,"У вас недостаточно денег!");
				return change_bank_casino_put(playerid);	
			}

			if(GetPlayerMoneyEx(playerid) < count_money_put)
			{
				SendErr(playerid,"У вас недостаточно денег!");
				return change_bank_casino_put(playerid);				
			}

			casino[casino_ids][casino_bank] += count_money_put;

			give_money(playerid, -count_money_put, "Деньги в кассу казино");

			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы положили деньги в кассу казино - "cGR"%d рублей"cWH"", count_money_put);	

			change_bank_casino(playerid);

			save_casino(casino_ids);
		}

		case DIALOG_CRUPIE_MENU:
		{
			if(!response) 
				return true;
			new 
				tableid = GetPVarIntNew(playerid, "player_in_table");

			switch(listitem)
			{
				case 0:
				{
					/*if(casino_table_total_pl(tableid) < 2) 
						return SendErr(playerid, "Недоступно из-за количества игроков за столом!");*/

					if(casino_table_total_pl(tableid) > 0)
						return SendErr(playerid, "Невозможно поменять ставку!");

					change_bet_count_crupie(playerid);
				
				}
				case 1:
				{
					if(casino_table_total_pl(tableid) < 2) 
						return SendErr(playerid, "Недоступно из-за количества игроков за столом!");

					if(casino_tables[tableid][casino_t_bet] == 0) 
						return SendErr(playerid, "За столом не установлена ставка!");

					casino_tables[tableid][casino_t_bet] = 0;
					casino_update_info(tableid);
					SelectTextDraw(playerid, 0xFFFFFFFF);
					
					SendSucc(playerid, "Вы успешно удалили ставку!");
				}
				case 2:
				{
					if(casino_table_total_pl(tableid) < 2) 
						return SendErr(playerid, "За столом недостаточно игроков");

					casino_tables[tableid][casino_t_bank] = casino_tables[tableid][casino_t_bet]*casino_table_total_pl(tableid);

					casino_tables[tableid][casino_step] = 20;

					casino_timer[tableid] = SetTimerEx("casino_start_game", 500, true, "i", tableid);
					casino_tables[tableid][casino_t_status] = true;
					SelectTextDraw(playerid, 0xFFFFFFFF);	
					SendSucc(playerid, "Вы успешно запустили рулетку! Ожидайте окончания игры!");
				}
			}
		}
		case DIALOG_CRUPIE_UPDATE_BET:
		{
			if(!response) 
				return true;

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное количество дней!");
				return change_bet_count_crupie(playerid);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное количество дней!");
				return change_bet_count_crupie(playerid);
			}

			if(strval(inputtext) < 1000 || strval(inputtext) > 10000000) 
				return change_bet_count_crupie(playerid);

			new 
				tableid = GetPVarIntNew(playerid, "player_in_table");

			/*if(casino_table_total_pl(tableid) < 2) 
				return SendErr(playerid, "Недоступно из-за количества игроков за столом!");*/

			if(casino_table_total_pl(tableid) > 0)
				return SendErr(playerid, "Невозможно поменять ставку!");

			casino_tables[tableid][casino_t_bet] = strval(inputtext);

			casino_update_info(tableid);

			SelectTextDraw(playerid, 0xFFFFFFFF);
		}
		case DIALOG_CRUPIE_JOB:
		{
			if(!response) 
				return true;

			switch(listitem)
			{
				case 0: info_count_crupie(playerid);
				case 1: info_job_crupie(playerid);
				case 2: crupie_start_job(playerid);
			}			
		}
		case DIALOG_CASINO_JOB_CLOSE:
		{
			if(!response) 
				return crupie_start_job_menu(playerid);			


		}
	}
	return true;
}

stock key_table_casino(playerid, newkeys, oldkeys)
{
	new time = GetTickCount();

	//print("тут ебашит-2");

    if(newkeys == 262144)
	{
		if(!IsPlayerInAnyVehicle(playerid))
		{
			for(new t; t < sizeof(casino_table); t++)
			{
		        if(IsPlayerInDynamicArea(playerid,  casino_table[t]))
		        {
		        	if(GetPVarIntNew(playerid,"player_in_the_crupie") != 0)
					{

						if(casino_tables[t][casito_t_crup] != -1) 
							return SendErr(playerid, "Данный стол уже занят!");

						if(casino_tables[t][casino_t_status] == true) 
							return SendErr(playerid, "Рулетка уже запущена! Ожидайте следующей!");

						casino_tables[t][casito_t_crup] = playerid;

						SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы успешно заняли стол - "cGR"%d"cWH" как крупье, нажмите кнопку управления", t);	

				        SelectTextDraw(playerid, 0xFFFFFFFF);
				        SetPVarIntNew(playerid, "player_in_table",t);

						create_casino_panel_p(playerid);


						PlayerTextDrawShow(playerid, casino_general_p[0][playerid]);
						PlayerTextDrawShow(playerid, casino_general_p[1][playerid]);
						PlayerTextDrawShow(playerid, casino_general_p[2][playerid]);
						PlayerTextDrawShow(playerid, casino_general_p[3][playerid]);
						PlayerTextDrawShow(playerid, casino_general_p[4][playerid]);
						PlayerTextDrawShow(playerid, casino_general_p[5][playerid]);
						PlayerTextDrawShow(playerid, casino_general_p[6][playerid]);
						PlayerTextDrawShow(playerid, casino_general_p[7][playerid]);
						PlayerTextDrawShow(playerid, casino_general_p[8][playerid]);


						casino_update_info(t);

						SetPVarIntNew(playerid, "player_in_active_crupie", 1);

						return true;
					}
					else
					{
						if(casino_tables[t][casito_t_crup] == -1)
							return SendErr(playerid, "За столом нет крупье!");

						if(casino_tables[t][casino_t_status] == true) 
							return SendErr(playerid, "Рулетка уже запущена! Ожидайте следующей!");

				        SetPVarIntNew(playerid, "player_in_table",t);

						create_casino_panel_p(playerid);
						casino_update_info(t);

						PlayerTextDrawShow(playerid, casino_general_p[0][playerid]);
						PlayerTextDrawShow(playerid, casino_general_p[1][playerid]);
						PlayerTextDrawShow(playerid, casino_general_p[2][playerid]);
						PlayerTextDrawShow(playerid, casino_general_p[3][playerid]);
						PlayerTextDrawShow(playerid, casino_general_p[4][playerid]);
						PlayerTextDrawShow(playerid, casino_general_p[5][playerid]);
						PlayerTextDrawShow(playerid, casino_general_p[6][playerid]);
						PlayerTextDrawShow(playerid, casino_general_p[7][playerid]);
						PlayerTextDrawShow(playerid, casino_general_p[8][playerid]);						

						return true;
					}
		        }
			}
			if(IsPlayerInDynamicArea(playerid, casino_start_job))
			{
				crupie_start_job_menu(playerid);
			}
		}
	}

	if(debug_mode)
	{
		printf("[key_table_casino]: Времени затрачено: <%d мс>" , GetTickCount() - time);
	}

	return true;
}



stock info_count_crupie(playerid)
{

	format(String512, sizeof(String512), "\
	"cWH"Количество крупье зависит от общей суммы всех столов в казино\n\n\
	На данный момент активно "cBLUE"8 столов"cWH" в казино, соответственно одновременно может работать\n\
	максимум "cBLUE"8 крупье"cWH", которые контролируют стол, который они заняли в данный момент\n\n\
	Работа крупье выгодная и поэтому сотрудников всегда хватает, так что постарайтесь\n\
	успеть забрать место на должности крупье!\n\n\
	Свободно мест крупье: "cBLUE"%d"cWH" мест", casino_total_crupie);
	return SPD(playerid, DIALOG_CASINO_JOB_CLOSE, DIALOG_STYLE_MSGBOX, !""cBLUE"Количество крупье", String512, !"Понял", "");	
}

stock info_job_crupie(playerid)
{
	return SPD(playerid, DIALOG_CASINO_JOB_CLOSE, DIALOG_STYLE_MSGBOX, !""cBLUE"О работе крупье", \
    ""cWH"Работа крупье Вам позволяет зарабатывать  "cBLUE"1 процент"cWH" с банка ставки\n\n\
    "cWH"Ваша задача:\n\
    "cBLUE"1."cWH" Устанавливать ставки по желанию клиентов\n\
    "cBLUE"2."cWH" Запускать прокркутку рулетки для вынесения результатов\n\n\
    Каждая игра - Ваш доход и заработок, так что будьте активны!", !"Понял", "");
}

stock crupie_start_job_menu(playerid)
{

    format(String256, sizeof(String256), "\
    "cGREY"Тип\t"cGREY"Информация\n\
    "cBLUE"- "cWH"Свободных рабочих мест крупье\t"cBLUE"%d мест\n\
    "cBLUE"- "cWH"Работа крупье\t"cBLUE"Информация\n\
    "cBLUE"- "cWH"Начало/Окончание работы крупье\t"cBLUE"Информация", casino_total_crupie);
    return SPD(playerid, DIALOG_CRUPIE_JOB, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Работа крупье", String256, !"Выбрать", !"Закрыть"); 

}


stock crupie_start_bet_menu(playerid)
{

	new 
		tableid = GetPVarIntNew(playerid, "player_in_table");

    format(String256, sizeof(String256), "\
    "cGREY"Тип\t"cGREY"Информация\n\
    "cBLUE"- "cWH"Изменение суммы ставки\t"cGR"%d рублей\n\
    "cBLUE"- "cWH"Удалить ставку\t"cBLUE"Удалить\n\
    "cBLUE"- "cWH"Запустить рулетку\t"cBLUE"%d игроков", casino_tables[tableid][casino_t_bet], casino_table_total_pl(tableid));
    return SPD(playerid, DIALOG_CRUPIE_MENU, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление рулеткой", String256, !"Выбрать", !"Закрыть"); 

}

stock change_bet_count_crupie(playerid)
{
	return SPD(playerid, DIALOG_CRUPIE_UPDATE_BET, DIALOG_STYLE_INPUT, \
	!""cBLUE"Управление ставкой для стола", \
	""cWH"Введите ставку которую Вы хотите установить за Вашим столом:\n\n\
	"cBLUE"Можно выбрать от 1.000 рублей до 10.000.000 рублей", !"Выбрать", !"Отмена");
				
}

stock select_sum_casino_bet(playerid)
{

	if(GetPVarIntNew(playerid,"player_in_table") != -1)
	{
		new 
			tableid = GetPVarIntNew(playerid,"player_in_table");

		if(GetPVarIntNew(playerid, "player_in_active_crupie") == 1)
			return true;

		if(casino_tables[tableid][casino_t_bet] == 0)
			return SendErr(playerid, "За столом нет ставки!");

		if(casino_table_getplayerid(tableid, playerid) != -1)
			return SendErr(playerid, "Вы уже сделали ставку!");

		if(casino_table_total_pl(tableid) == 4)
			return SendErr(playerid, "За столом недостаточно мест!");

		if(GetPlayerMoneyEx(playerid) < casino_tables[tableid][casino_t_bet])
			return SendErr(playerid, "У вас недостаточно денежных средств, чтобы сделать ставку!");

		if(casino_tables[tableid][casino_t_status] == true)
			return SendErr(playerid, "Рулетка уже запущена! Ожидайте следующей!");

		give_money(playerid, -casino_tables[tableid][casino_t_bet], "Ставка в казино");

		casino_tables[tableid][casino_t_players][casino_table_get_slots(tableid)] = playerid;

		SetPVarIntNew(playerid, "player_bet_in_casino", 1);

		casino_update_info(tableid);
		SelectTextDraw(playerid, 0xFFFFFFFF);
	}

	return true;
}

stock exit_sum_casino_bet(playerid)
{

	new 
		tableid = GetPVarIntNew(playerid,"player_in_table");

	if(GetPVarIntNew(playerid, "player_in_table") != -1)
	{

		if(casino_tables[tableid][casino_t_status] == true && casino_table_getplayerid(tableid,playerid) != -1) 
			return true;

		if(casino_tables[tableid][casino_t_status] == true && casino_tables[tableid][casito_t_crup] == playerid) 
			return true;

		if(GetPVarIntNew(playerid,"player_in_table"))
		{
			if(GetPVarIntNew(playerid,"player_in_active_crupie") != 0)
			{
				for(new i = 0; i < 9; i++)
				{
					if(casino_general_p[i][playerid] != PlayerText:INVALID_TEXT_DRAW)
					{
						PlayerTextDrawHideEx(playerid, casino_general_p[i][playerid]);
					}
				}

				SetPVarIntNew(playerid, "player_in_active_crupie", 0);
				SetPVarIntNew(playerid, "player_in_table", -1);

				CancelSelectTextDraw(playerid);
				casino_update_info(tableid);
				casino_table_exit_all(tableid);

				casino_tables[tableid][casito_t_crup] = -1;
				casino_tables[tableid][casino_t_bet] = 0;

			}
			else
			{
				for(new i; i < 4; i++)
				{
					if(casino_tables[tableid][casino_t_players][i] == playerid)
					{
						if(casino_tables[tableid][casino_t_bet] > 0)
						{
							if(casino_tables[tableid][casino_t_status] == false)
						    {
								give_money(playerid, casino_tables[tableid][casino_t_bet], "Возврат ставки казино");
							}
							casino_tables[tableid][casino_t_players][i] = -1;
						}
						
					}
				}
				for(new i = 0; i < 9; i++)
				{
					if(casino_general_p[i][playerid] != PlayerText:INVALID_TEXT_DRAW)
					{
						PlayerTextDrawHideEx(playerid, casino_general_p[i][playerid]);
					}
				}

				casino_update_info(tableid);
				SetPVarIntNew(playerid, "player_in_table", -1);
				CancelSelectTextDraw(playerid);

			}
		}
	}
	return true;

}


stock crupie_start_job(playerid)
{

    if(GetPVarIntNew(playerid,"player_in_the_crupie") == 0) 
    {

	    if(casino_total_crupie == 0) 
	    {
	    	crupie_start_job_menu(playerid);
	    	return SendErr(playerid, "Превышен лимит крупье на работе! Приходите позже!");
	    }


    	SendSucc(playerid, "Вы начали рабочий день крупье! Подходите к свободному столу и начинайте работу!");

    	SetPVarIntNew(playerid,"player_in_the_crupie", 1);
    	
		if(pData[playerid][pSex] == 2)
		{
			SetPlayerSkin(playerid, SKIN_CRUPIE_FEMALE);	
		}
		else
		{
			SetPlayerSkin(playerid, SKIN_CRUPIE_MALE);
		}

    	casino_total_crupie--;
    }
    else
    {
    	SendSucc(playerid, "Вы закончили рабочий день крупье!");
    	SetPlayerSkin(playerid, pData[playerid][pSkin]);
    	DeletePVarNew(playerid,"player_in_the_crupie");

    	clear_pvar_casino(playerid);
    	clear_pvar_all_casino(playerid);

    	casino_total_crupie++;
    }
    return true;
}

stock leave_crupie_casino(playerid)
{
    if(GetPVarIntNew(playerid,"player_in_the_crupie") == 1) 
    {

    	casino_total_crupie++;

		SendSucc(playerid, "Вы закончили рабочий день крупье!");
		SetPlayerSkin(playerid, pData[playerid][pSkin]);
		DeletePVarNew(playerid,"player_in_the_crupie");

		clear_pvar_casino(playerid);
		clear_pvar_all_casino(playerid);

	    if(GetPVarIntNew(playerid, "player_in_table") != -1)
		{

			new 
				tableid = GetPVarIntNew(playerid,"player_in_table");
			casino_table_exit_all(tableid);
		}
		
	}

	return true;
}

stock clear_pvar_casino(playerid)
{
    SetPVarIntNew(playerid, "player_in_table", -1);


    return true;
}

stock clear_pvar_all_casino(playerid)
{
	DeletePVarNew(playerid,"player_in_the_crupie");
	DeletePVarNew(playerid,"player_in_table");
	DeletePVarNew(playerid,"table_winner_player");
	DeletePVarNew(playerid,"player_in_active_crupie");

	return true;
}

stock disconnect_player_casino(playerid)
{
    if(GetPVarIntNew(playerid, "player_in_table") != -1)
	{
		new 
			tableid = GetPVarIntNew(playerid, "player_in_table");

		for(new i; i < 4; i++)
		{
			if(casino_tables[tableid][casino_t_players][i] == playerid)
			{
				if(casino_tables[tableid][casino_t_bet] > 0)
				{
					if(casino_tables[tableid][casino_t_status] == false)
					{
						give_money(playerid, casino_tables[tableid][casino_t_bet], "Возврат ставки казино");
					}
				}
				casino_tables[tableid][casino_t_players][i] = -1;
			}
		}
		if(GetPVarIntNew(playerid,"player_in_the_crupie") != 0) 
		{
			casino_tables[tableid][casito_t_crup] = -1;
			casino_total_crupie++;
			casino_tables[tableid][casino_t_bet] = 0;

		}

		for(new i = 0; i < 9; i++)
		{
			if(casino_general_p[i][playerid] != PlayerText:INVALID_TEXT_DRAW)
			{
				PlayerTextDrawHideEx(playerid, casino_general_p[i][playerid]);
			}
		}

		SetPVarIntNew(playerid, "player_in_table", -1);
		casino_update_info(tableid);
		clear_pvar_all_casino(playerid);
	}
	return true;
}



callback:: casino_start_game(tableid)
{
	new string[128];

	new time = GetTickCount();

	if(casino_tables[tableid][casino_step] == 0)
    {
    	KillTimer(casino_timer[tableid]);

        for(new i; i < 4; i++)
        {
            if(casino_tables[tableid][casino_t_players][i] != -1 && casino_table_getplayerid(tableid, casino_tables[tableid][casino_t_players][i]) != -1)
            {
                SetPVarIntNew(casino_tables[tableid][casino_t_players][i],"table_winner_player", random(20));

                format(string,sizeof(string),"%d",GetPVarIntNew(casino_tables[tableid][casino_t_players][i],"table_winner_player"));
                GameTextForPlayer(casino_tables[tableid][casino_t_players][i], string, 1000, 3);
            }
        }

        new 
        	maxs,winid = -1;

        foreach(new i: logged_players)
        {
            if(GetPVarIntNew(i, "player_in_table") == tableid && casino_table_getplayerid(tableid,i) != -1)
            {
                new 
                	v = GetPVarIntNew(i,"table_winner_player");

                if(v > maxs) 
                {
                	maxs = v, 
                	winid = i;
                }

                else if(i != winid && i !=  casino_tables[tableid][casito_t_crup])
                {
			        format(String144, sizeof(String144), "• {FFC800}[Казино] "cWH"Вы проиграли - "cGR"%d"cWH" рублей. Ваше число: %d",  casino_tables[tableid][casino_t_bet], GetPVarIntNew(i,"table_winner_player"));	
			        SCM(i, -1, String144);

			        printf("CASINO PLAYER LOOS");
                }
            }
            if(GetPVarIntNew(i, "player_in_table") == tableid && casino_table_getplayerid(tableid,i) == -1)
            {
                format(string,sizeof(string),"%d", casino_tables[tableid][casino_step]);
                GameTextForPlayer(i, string, 1000, 3);

                printf("CASINO PLAYER LOOS-1");
            }
        }
        
        if(casino_tables[tableid][casito_t_crup] != -1)
        {
			new 
				crupiemoney = (casino_tables[tableid][casino_t_bank]/100)*1;

			new 
				prize_casino = (casino_tables[tableid][casino_t_bank]/100)*4;
	        pay_money_bank_casino(prize_casino);


            give_money(casino_tables[tableid][casito_t_crup], crupiemoney, "Процент у крупье");

	        format(String144, sizeof(String144), "• {FFC800}[Казино] "cWH"Вы получили - "cGR"%d"cWH" рублей от ставки в "cGR"%d"cWH" рублей", crupiemoney, casino_tables[tableid][casino_t_bet]*casino_table_total_pl(tableid));
	        SCM(casino_tables[tableid][casito_t_crup], -1, String144);

	        printf("CASINO PLAYER WIN-1");

        }
        
		new 
			prize = (casino_tables[tableid][casino_t_bank]/100)*90;


		GosMoney[0] += (casino_tables[tableid][casino_t_bank]/100)*5;

		printf("CASINO PLAYER WIN-2");

        give_money(winid, prize, "Выигрыш в казино");


        if(winid != -1)
        {
	        format(String144, sizeof(String144), "• {FFC800}[Казино] "cWH"Вы выиграли - "cGR"%d"cWH" рублей. Ваше число: %d", prize,GetPVarIntNew(winid,"table_winner_player"));
	        SCM(winid, -1, String144);

	        printf("CASINO PLAYER WIN-3");

		    format(String144, sizeof(String144), "• {FFC800}[Казино] "cWH"%s выиграл в казино "cGR"%d"cWH" рублей. Число: %d", pData[winid][pNickname], prize,GetPVarIntNew(winid,"table_winner_player"));
		    ProxDetector(30.0, winid, String144, COLOR_YELLOW, COLOR_YELLOW, COLOR_YELLOW, COLOR_YELLOW, COLOR_YELLOW);

		    printf("CASINO PLAYER WIN-4");

		    format(String256, sizeof(String256), "%s выиграл в казино %d рублей. Число: %d", pData[winid][pNickname], prize,GetPVarIntNew(winid,"table_winner_player"));
		    logs_player_casino_win(winid, pData[winid][pMysqlID], String256);

	    
	        printf("CASINO PLAYER WIN-5");
	    }


        for(new i; i < 4; i++) 
        {
        	printf("CASINO PLAYER WIN CLEAR");
        	DeletePVarNew(casino_tables[tableid][casino_t_players][i],"table_winner_player");
        	casino_tables[tableid][casino_t_players][i] = -1;
        }

        casino_tables[tableid][casino_t_players][0] =  casino_tables[tableid][casino_t_players][1] =  casino_tables[tableid][casino_t_players][2] =  casino_tables[tableid][casino_t_players][3] = -1;

        printf("CASINO PLAYER WIN CLEAR-2");

        casino_tables[tableid][casino_step] = -1;

        printf("CASINO PLAYER WIN CLEAR-3");

        casino_tables[tableid][casino_t_bet] = 0;
        
        printf("CASINO PLAYER WIN CLEAR-4");

        casino_tables[tableid][casino_t_bank] = 0;
        	
        printf("CASINO PLAYER WIN CLEAR-5");

        casino_tables[tableid][casino_t_status] = false;
        
        printf("CASINO PLAYER WIN CLEAR-6");

        casino_timer[tableid] = -1;

        printf("CASINO PLAYER WIN CLEAR-7");

        KillTimer(casino_timer[tableid]);

        printf("CASINO PLAYER WIN CLEAR-8");

        casino_update_info(tableid);

        printf("CASINO PLAYER WIN CLEAR - 9");

        return true;
	}
    else 
    {
        for(new i; i < 4; i++)
        {
            if(casino_tables[tableid][casino_t_players][i] != -1 && casino_table_getplayerid(tableid, casino_tables[tableid][casino_t_players][i]) != -1) // Если за столом найден игрок и его слот не ровняется -1
            {
                format(string,sizeof(string),"%d",random(20));
                GameTextForPlayer(casino_tables[tableid][casino_t_players][i], string, 1000, 3);
            }
        }
        foreach(new i: logged_players)
        {
            if(GetPVarIntNew(i, "player_in_table") == tableid && casino_table_getplayerid(tableid,i) == -1)
            {
                format(string,sizeof(string),"%d", casino_tables[tableid][casino_step]);
                GameTextForPlayer(i, string, 1000, 3);
            }
        }
        casino_tables[tableid][casino_step]--;
	}

	if(debug_mode)
	{
		printf("[casino_start_game]: Времени затрачено: <%d мс>" , GetTickCount() - time);
	}

	return true;
}

stock casino_table_get_slots(tableid)
{
	new 
		slot = -1;

	for(new i; i < 4; i++)
	{
		if(casino_tables[tableid][casino_t_players][i] == -1 && slot == -1) slot = i;
	}
	return slot;
}

stock casino_table_getplayerid(tableid,playerid)
{
	new 
		plid = -1;

	for(new i; i < 4; i++)
	{
		if(casino_tables[tableid][casino_t_players][i] == playerid) plid = i;
	}
	return plid;
}

stock casino_table_total_pl(tableid)
{
	new 
		total;

	for(new i; i < 4; i++)
	{
		if(casino_tables[tableid][casino_t_players][i] != -1) total++;
	}
	return total;
}

stock casino_table_exit_all(tableid)
{
	foreach(new i: logged_players)
	{
		if(GetPVarIntNew(i, "player_in_table") == tableid)
		{
			for(new is = 0; is < 4; is++)
			{
				if(casino_tables[tableid][casino_t_players][is] == i)
				{
					if(casino_tables[tableid][casino_t_bet] > 0)
					{
						give_money(i, casino_tables[tableid][casino_t_bet], "Возврат ставки казино (Крупье вышел)");
					}
					casino_tables[tableid][casino_t_players][is] = -1;					
				}
			}
			for(new is = 0; is < 9; is++)
			{
				if(casino_general_p[is][i] != PlayerText:INVALID_TEXT_DRAW)
				{
					PlayerTextDrawHideEx(i, casino_general_p[is][i]);
				}
			}

			SetPVarIntNew(i, "player_in_table", -1);
			CancelSelectTextDraw(i);		

		}

		casino_tables[tableid][casino_t_bank] = 0;
		casino_tables[tableid][casino_t_status] = false;
		casino_tables[tableid][casito_t_crup] = -1;
				
	}

	return true;
}

stock casino_update_info(tableid)
{

	foreach(new i: logged_players)
	{
		if(GetPVarIntNew(i, "player_in_table") != tableid)
			continue;

		if(casino_tables[tableid][casino_t_players][0] != -1)
		{
			format(String256, 32, "%s", SplitName(casino_tables[tableid][casino_t_players][0]));
			PlayerTextDrawSetString(i, casino_general_p[1][i], String256);
			PlayerTextDrawShow(i, casino_general_p[1][i]);					
		}
		else
		{
			format(String256, 32, "-----------");
			PlayerTextDrawSetString(i, casino_general_p[1][i], String256);
			PlayerTextDrawShow(i, casino_general_p[1][i]);						
		}


		if(casino_tables[tableid][casino_t_players][1] != -1)
		{
			format(String256, 32, "%s", SplitName(casino_tables[tableid][casino_t_players][1]));
			PlayerTextDrawSetString(i, casino_general_p[2][i], String256);
			PlayerTextDrawShow(i, casino_general_p[2][i]);					
		}
		else
		{
			format(String256, 32, "-----------");
			PlayerTextDrawSetString(i, casino_general_p[2][i], String256);
			PlayerTextDrawShow(i, casino_general_p[2][i]);						
		}	

		if(casino_tables[tableid][casino_t_players][2] != -1)
		{
			format(String256, 32, "%s", SplitName(casino_tables[tableid][casino_t_players][2]));
			PlayerTextDrawSetString(i, casino_general_p[3][i], String256);
			PlayerTextDrawShow(i, casino_general_p[3][i]);					
		}
		else
		{
			format(String256, 32, "-----------");
			PlayerTextDrawSetString(i, casino_general_p[3][i], String256);
			PlayerTextDrawShow(i, casino_general_p[3][i]);						
		}

		if(casino_tables[tableid][casino_t_players][3] != -1)
		{
			format(String256, 32, "%s", SplitName(casino_tables[tableid][casino_t_players][3]));
			PlayerTextDrawSetString(i, casino_general_p[4][i], String256);
			PlayerTextDrawShow(i, casino_general_p[4][i]);					
		}
		else
		{
			format(String256, 32, "-----------");
			PlayerTextDrawSetString(i, casino_general_p[4][i], String256);
			PlayerTextDrawShow(i, casino_general_p[4][i]);						
		}


		format(String256, 32, "%d_RUB", casino_tables[tableid][casino_t_bet]);
		PlayerTextDrawSetString(i, casino_general_p[7][i], String256);
		PlayerTextDrawShow(i, casino_general_p[7][i]);
		SelectTextDraw(i, 0xFFFFFFFF);

		
	}
	return true;
}

stock pay_money_bank_casino(sum)
{
	
	if(casino[0][casino_finka_day] >= casino[0][casino_finka_ogran])
		return true;

	if(casino[0][casino_owner_id] == -1)
		return true;

	casino[0][casino_bank] += sum;
	casino[0][casino_finka_day] += sum;

	save_casino(0);

	format(String256,sizeof(String256),"UPDATE `casino_stats` SET `stats_all_time` = `stats_all_time`+'%d' WHERE `casino_id` = '%d'" , sum, 0);
	sql_queryEx(zConn, String256, QUERY_THREADED);	
	format(String256,sizeof(String256),"UPDATE `casino_stats` SET `stats_mounth` = `stats_mounth`+'%d' WHERE `casino_id` = '%d'" , sum, 0);
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
			format(String256,sizeof(String256),"UPDATE `casino_stats` SET `stats_day_1` = `stats_day_1`+'%d' WHERE `casino_id` = '%d'" , sum, 0);
			sql_queryEx(zConn, String256, QUERY_THREADED);	

			format(String256,sizeof(String256),"UPDATE `casino_stats` SET `stats_today` = `stats_today`+'%d' WHERE `casino_id` = '%d'" , sum, 0);
			sql_queryEx(zConn, String256, QUERY_THREADED);	

		}
		case 1:
		{
			format(String256,sizeof(String256),"UPDATE `casino_stats` SET `stats_day_2` = `stats_day_2`+'%d' WHERE `casino_id` = '%d'" , sum, 0);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `casino_stats` SET `stats_today` = `stats_today`+'%d' WHERE `casino_id` = '%d'" , sum, 0);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}	

		case 2:
		{
			format(String256,sizeof(String256),"UPDATE `casino_stats` SET `stats_day_3` = `stats_day_3`+'%d' WHERE `casino_id` = '%d'" , sum, 0);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `casino_stats` SET `stats_today` = `stats_today`+'%d' WHERE `casino_id` = '%d'" , sum, 0);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}
		case 3:
		{
			format(String256,sizeof(String256),"UPDATE `casino_stats` SET `stats_day_4` = `stats_day_4`+'%d' WHERE `casino_id` = '%d'" , sum, 0);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `casino_stats` SET `stats_today` = `stats_today`+'%d' WHERE `casino_id` = '%d'" , sum, 0);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}

		case 4:
		{
			format(String256,sizeof(String256),"UPDATE `casino_stats` SET `stats_day_5` = `stats_day_5`+'%d' WHERE `casino_id` = '%d'" , sum, 0);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `casino_stats` SET `stats_today` = `stats_today`+'%d' WHERE `casino_id` = '%d'" , sum, 0);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}	
		case 5:
		{
			format(String256,sizeof(String256),"UPDATE `casino_stats` SET `stats_day_6` = `stats_day_6`+'%d' WHERE `casino_id` = '%d'" , sum, 0);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `casino_stats` SET `stats_today` = `stats_today`+'%d' WHERE `casino_id` = '%d'" , sum, 0);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}
		case 6:
		{
			format(String256,sizeof(String256),"UPDATE `casino_stats` SET `stats_day_7` = `stats_day_7`+'%d' WHERE `casino_id` = '%d'" , sum, 0);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `casino_stats` SET `stats_today` = `stats_today`+'%d' WHERE `casino_id` = '%d'" , sum, 0);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}

	}	

	return true;
}

stock clear_stats_casino_newday()
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
			format(String256,sizeof(String256),"UPDATE `casino_stats` SET `stats_day_1` = '0' WHERE `casino_id` = '%d'" , 0);
			sql_queryEx(zConn, String256, QUERY_THREADED);	

			format(String256,sizeof(String256),"UPDATE `casino_stats` SET `stats_today` = '0' WHERE `casino_id` = '%d'" , 0);
			sql_queryEx(zConn, String256, QUERY_THREADED);	

		}
		case 1:
		{
			format(String256,sizeof(String256),"UPDATE `casino_stats` SET `stats_day_2` = '0' WHERE `casino_id` = '%d'" , 0);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `casino_stats` SET `stats_today` = '0' WHERE `casino_id` = '%d'" , 0);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}	

		case 2:
		{
			format(String256,sizeof(String256),"UPDATE `casino_stats` SET `stats_day_3` = '0' WHERE `casino_id` = '%d'" , 0);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `casino_stats` SET `stats_today` = '0' WHERE `casino_id` = '%d'" , 0);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}
		case 3:
		{
			format(String256,sizeof(String256),"UPDATE `casino_stats` SET `stats_day_4` = '0' WHERE `casino_id` = '%d'" , 0);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `casino_stats` SET `stats_today` = '0' WHERE `casino_id` = '%d'" , 0);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}

		case 4:
		{
			format(String256,sizeof(String256),"UPDATE `casino_stats` SET `stats_day_5` = '0' WHERE `casino_id` = '%d'" , 0);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `casino_stats` SET `stats_today` = '0' WHERE `casino_id` = '%d'" , 0);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}	
		case 5:
		{
			format(String256,sizeof(String256),"UPDATE `casino_stats` SET `stats_day_6` = '0' WHERE `casino_id` = '%d'" , 0);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `casino_stats` SET `stats_today` = '0' WHERE `casino_id` = '%d'" , 0);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}
		case 6:
		{
			format(String256,sizeof(String256),"UPDATE `casino_stats` SET `stats_day_7` = '0' WHERE `casino_id` = '%d'" , 0);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `casino_stats` SET `stats_today` = '0' WHERE `casino_id` = '%d'" , 0);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}

	}	
	return true;
}

stock clear_stats_casino_newmouth()
{

	format(String256,sizeof(String256),"UPDATE `casino_stats` SET `stats_mounth_back` = `stats_mounth` WHERE `casino_id` = '%d'" , 0);
	sql_queryEx(zConn, String256, QUERY_THREADED);	

	format(String256,sizeof(String256),"UPDATE `casino_stats` SET `stats_mounth` = '0' WHERE `casino_id` = '%d'" , 0);
	sql_queryEx(zConn, String256, QUERY_THREADED);	

	return true;
}

stock change_statistic_casino(playerid)
{
	new 
		casino_ids = pData[playerid][pCasinoOwner];

	format(String512, sizeof(String512), "SELECT * FROM casino_stats WHERE casino_id = '%d' LIMIT 1", casino_ids);
	new Result:casino_stats = sql_queryEx(zConn, String512, QUERY_CACHED);

	if(sql_num_rows(casino_stats)) 
	{
		new 
			ye, m, d;

		getdate(ye, m, d);

		new 
			casino_stats_day[8],
			casino_stats_today,
			casino_stats_mounth,
			casino_status_all,
			casino_stats_prewiow;

  		casino_stats_day[1] = sql_get_field_assoc_int(casino_stats, "stats_day_1");
  		casino_stats_day[2] = sql_get_field_assoc_int(casino_stats, "stats_day_2");
  		casino_stats_day[3] = sql_get_field_assoc_int(casino_stats, "stats_day_3");
  		casino_stats_day[4] = sql_get_field_assoc_int(casino_stats, "stats_day_4");
  		casino_stats_day[5] = sql_get_field_assoc_int(casino_stats, "stats_day_5");
  		casino_stats_day[6] = sql_get_field_assoc_int(casino_stats, "stats_day_6");
  		casino_stats_day[7] = sql_get_field_assoc_int(casino_stats, "stats_day_7");

  		casino_stats_today = sql_get_field_assoc_int(casino_stats, "stats_today");
  		casino_stats_mounth = sql_get_field_assoc_int(casino_stats, "stats_mounth");
  		casino_status_all = sql_get_field_assoc_int(casino_stats, "stats_all_time");
  		casino_stats_prewiow = sql_get_field_assoc_int(casino_stats, "stats_mounth_back");

  		new 
  			all_day_seven = casino_stats_day[1]+casino_stats_day[2]+casino_stats_day[3]+casino_stats_day[4]+casino_stats_day[5]+casino_stats_day[6]+casino_stats_day[7];


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

        get_stats_color(casino_stats_day[1], casino_stats_day[1]), casino_stats_day[1],
        get_stats_color(casino_stats_day[2], casino_stats_day[1]), casino_stats_day[2], get_stats_phrase(casino_stats_day[2], casino_stats_day[1]), get_percent_pribil(casino_stats_day[2], casino_stats_day[1]), 
        get_stats_color(casino_stats_day[3], casino_stats_day[2]), casino_stats_day[3], get_stats_phrase(casino_stats_day[3], casino_stats_day[1]), get_percent_pribil(casino_stats_day[3], casino_stats_day[2]), 
        get_stats_color(casino_stats_day[4], casino_stats_day[3]), casino_stats_day[4], get_stats_phrase(casino_stats_day[4], casino_stats_day[1]), get_percent_pribil(casino_stats_day[4], casino_stats_day[3]), 
        get_stats_color(casino_stats_day[5], casino_stats_day[4]), casino_stats_day[5], get_stats_phrase(casino_stats_day[5], casino_stats_day[1]), get_percent_pribil(casino_stats_day[5], casino_stats_day[4]), 
        get_stats_color(casino_stats_day[6], casino_stats_day[5]), casino_stats_day[6], get_stats_phrase(casino_stats_day[6], casino_stats_day[1]), get_percent_pribil(casino_stats_day[6], casino_stats_day[5]), 
        get_stats_color(casino_stats_day[7], casino_stats_day[6]), casino_stats_day[7], get_stats_phrase(casino_stats_day[7], casino_stats_day[1]), get_percent_pribil(casino_stats_day[7], casino_stats_day[6]), 
        mounth_casino_stats[m], get_stats_color(casino_stats_mounth, casino_stats_prewiow), casino_stats_mounth, get_stats_phrase(casino_stats_mounth, casino_stats_prewiow), get_percent_pribil(casino_stats_mounth, casino_stats_prewiow), 
        mounth_casino_stats[m-1], casino_stats_prewiow,
        all_day_seven,
        casino_status_all,
        casino_stats_today);
	    SPD(playerid, DIALOG_CHANGE_CASINO_CLOSE, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Статистика казино", String2048, !"Закрыть", ""); 

  	}
  	sql_free_result(casino_stats);


	return true;
}

CMD:acasinofin(playerid, params[])
{


    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

	if(sscanf(params, "dd", params[0], params[1]))
	{
		SendInf(playerid, "Используйте: /acasinofin "cWH"[ID казино] [Ограничение]");
		return true;
	}

	casino[params[0]][casino_finka_ogran] = params[1];
	save_casino(params[0]);

    format(String144, sizeof(String144), "Вы успешно изменили максимальную прибыль для казино №%d на "cGR"%d "cWH"рублей!", params[0], params[1]);
    SendSucc(playerid, String144);

	return true;
}

CMD:closecasino(playerid, params[])
{
    if(pData[playerid][pAdmin] < 7) 
    	return NoCMD(playerid);

	if(sscanf(params, "dd", params[0], params[1]))
	{
		SendInf(playerid, "Используйте: /closecasino "cWH"[ID казино - 0]");
		return true;
	}    	

	if(casino[params[0]][casino_closed_status] == 2)
	{
		casino[params[0]][casino_closed_status] = 1;
	    format(String144, sizeof(String144), "Вы успешно "cGR"открыли"cWH" казино №%d!", params[0]);
	    SendSucc(playerid, String144);		
	}
	else
	{
		casino[params[0]][casino_closed_status] = 2;
	    format(String144, sizeof(String144), "Вы успешно "cLRED"закрыли"cWH" казино №%d!", params[0]);
	    SendSucc(playerid, String144);		
	}
	return true;
}

CMD:gotocasino(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

	if(sscanf(params, "d", params[0]))
	{
		SendInf(playerid, "Используйте: /gotocasino "cWH"[ID казино]");
		return true;
	}

	new 
		id_casino = params[0];


	SetPlayerPos(playerid, casino[id_casino][casino_pos_x], casino[id_casino][casino_pos_y], casino[id_casino][casino_pos_z]);


    format(String144, sizeof(String144), "Вы телепортировались к казино №%d", id_casino);
    SendSucc(playerid, String144);
	return true;
}


CMD:addcasino(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    new 
    	Float:x,Float:y,Float:z;

    if(sscanf(params, "dd", params[0], params[1]))
    {
    	SendInf(playerid, "Используйте: /addcasino [Стоимость] [Ограничение финки]");
    	return true;
    }

    GetPlayerPos(playerid, x, y, z);
    

    format(String256, sizeof(String256), "INSERT INTO casino(casino_pos_x, casino_pos_y, casino_pos_z, casino_buy_price, casino_finka_ogran) VALUES ('%f','%f','%f','%d','%d')",
    x, y, z, params[0], params[1]);
    sql_queryEx(zConn, String256, QUERY_THREADED);	


    SendSucc(playerid, "Вы добавили казино! Оно появится после рестарта");
	return true;
}

CMD:asellcasino(playerid)
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);
	
	sell_casino_temp(0);

	return true;
}

CMD:casinocrupie(playerid)
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);
    
	casino_total_crupie = 10;

	return true;
}