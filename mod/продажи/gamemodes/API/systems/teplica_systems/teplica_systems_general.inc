

stock get_prod_green_house_n(type)
{
	new 
		name[40];

	switch(type)
	{
		case 1: name = "Огурцов";
		case 2: name = "Помидоров";
		case 3: name = "Манго";
		case 4: name = "Слив";
		case 5: name = "Маракуйа";
		case 6: name = "Граната";
		case 7: name = "Персиков";
		case 8: name = "Лимонов";
		default: name = "Неизвестно";
	}
	return name;
}

stock get_green_house_n(type)
{
	new 
		name[40];

	switch(type)
	{
		case 1: name = "Малая Теплица";
		case 2: name = "Средняя Теплица";
		case 3: name = "Крупная теплица";
		default: name = "Неизвестно";
	}
	return name;
}


stock create_green_house_element()
{


  	CreateDynamic3DTextLabel(""cWH"Работа на теплице\n "cBLUE"Информация",-1, \
  	GREEN_HOUSE_PANEL_1, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
	green_house_pickup_1 = create_circle_pickup(GREEN_HOUSE_PANEL_1, TRIGGER_LBLUE);	

  	CreateDynamic3DTextLabel(""cWH"Работа на теплице\n "cBLUE"Информация",-1, \
  	GREEN_HOUSE_PANEL_2, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
	green_house_pickup_2 = create_circle_pickup(GREEN_HOUSE_PANEL_2, TRIGGER_LBLUE);	

  	CreateDynamic3DTextLabel(""cWH"Работа на теплице\n "cBLUE"Информация",-1, \
  	GREEN_HOUSE_PANEL_3, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
	green_house_pickup_3 = create_circle_pickup(GREEN_HOUSE_PANEL_3, TRIGGER_LBLUE);	


  	CreateDynamic3DTextLabel(""cWH"Тепличный Комплекс\n "cBLUE"Информация",-1, \
  	GREEN_HOUSE_GENERAL, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
	green_house_pickup = create_circle_pickup(GREEN_HOUSE_GENERAL, TRIGGER_LBLUE);	

	CreateDynamicPickup(13702, 23, GREEN_HOUSE_EXIT_1, -1, -1, -1, STREAM_DISTANCE_DYNAMIC_PICKUP);
	CreateDynamicPickup(13702, 23, GREEN_HOUSE_EXIT_2, -1, -1, -1, STREAM_DISTANCE_DYNAMIC_PICKUP);
	CreateDynamicPickup(13702, 23, GREEN_HOUSE_EXIT_3, -1, -1, -1, STREAM_DISTANCE_DYNAMIC_PICKUP);

	green_house_exit_1 = CreateDynamicSphere(GREEN_HOUSE_EXIT_1, 1.0);
	green_house_exit_2 = CreateDynamicSphere(GREEN_HOUSE_EXIT_2, 1.0);
	green_house_exit_3 = CreateDynamicSphere(GREEN_HOUSE_EXIT_3, 1.0);

	generate_price_green_house();

	return true;
}


stock show_menu_start_teplica(playerid, type)
{

	switch(type)
	{
		case TEXTDRAW_SHOW:
		{
			show_info_gui(playerid, TEXTDRAW_HIDE);

			hide_hud_element(playerid);
			show_player_green_zone(playerid, TEXTDRAW_HIDE);

			TextDrawShowForPlayer(playerid, menu_teplica_general_st[0]);
			TextDrawShowForPlayer(playerid, menu_teplica_general_st[1]);
			TextDrawShowForPlayer(playerid, menu_teplica_general_st[2]);
			TextDrawShowForPlayer(playerid, menu_teplica_general_st[3]);
			TextDrawShowForPlayer(playerid, menu_teplica_general_st[4]);
			TextDrawShowForPlayer(playerid, menu_teplica_general_st[5]);
			TextDrawShowForPlayer(playerid, menu_teplica_general_st[6]);
			TextDrawShowForPlayer(playerid, menu_teplica_general_st[7]);
			TextDrawShowForPlayer(playerid, menu_teplica_general_st[8]);
			TextDrawShowForPlayer(playerid, menu_teplica_general_st[9]);
			TextDrawShowForPlayer(playerid, menu_teplica_general_st[10]);
			TextDrawShowForPlayer(playerid, menu_teplica_general_st[11]);

			SelectTextDraw(playerid, COLOR_BLUE);

			
		}
		case TEXTDRAW_HIDE:
		{
			if(pGreenZone[playerid])
			{
				show_player_green_zone(playerid, TEXTDRAW_SHOW);
			}
			show_hud_element(playerid);
			show_hud_hungry(playerid);

			show_info_gui(playerid, TEXTDRAW_SHOW);

			TextDrawHideForPlayer(playerid, menu_teplica_general_st[0]);
			TextDrawHideForPlayer(playerid, menu_teplica_general_st[1]);
			TextDrawHideForPlayer(playerid, menu_teplica_general_st[2]);
			TextDrawHideForPlayer(playerid, menu_teplica_general_st[3]);
			TextDrawHideForPlayer(playerid, menu_teplica_general_st[4]);
			TextDrawHideForPlayer(playerid, menu_teplica_general_st[5]);
			TextDrawHideForPlayer(playerid, menu_teplica_general_st[6]);
			TextDrawHideForPlayer(playerid, menu_teplica_general_st[7]);
			TextDrawHideForPlayer(playerid, menu_teplica_general_st[8]);
			TextDrawHideForPlayer(playerid, menu_teplica_general_st[9]);
			TextDrawHideForPlayer(playerid, menu_teplica_general_st[10]);
			TextDrawHideForPlayer(playerid, menu_teplica_general_st[11]);


			CancelSelectTextDraw(playerid);

		}

	}


	return true;
}


stock show_menu_buy_teplica_flate(playerid, type)
{
	switch(type)
	{
		case TEXTDRAW_SHOW:
		{
			show_menu_start_teplica(playerid, TEXTDRAW_HIDE);

			show_info_gui(playerid, TEXTDRAW_HIDE);

			hide_hud_element(playerid);
			show_player_green_zone(playerid, TEXTDRAW_HIDE);

			TextDrawShowForPlayer(playerid, teplica_buy_menu[0]);
			TextDrawShowForPlayer(playerid, teplica_buy_menu[1]);
			TextDrawShowForPlayer(playerid, teplica_buy_menu[2]);
			TextDrawShowForPlayer(playerid, teplica_buy_menu[3]);
			TextDrawShowForPlayer(playerid, teplica_buy_menu[4]);
			TextDrawShowForPlayer(playerid, teplica_buy_menu[5]);
			TextDrawShowForPlayer(playerid, teplica_buy_menu[6]);

			SelectTextDraw(playerid, COLOR_BLUE);

		}
		case TEXTDRAW_HIDE:
		{
			if(pGreenZone[playerid])
			{
				show_player_green_zone(playerid, TEXTDRAW_SHOW);
			}
			show_hud_element(playerid);
			show_hud_hungry(playerid);

			show_info_gui(playerid, TEXTDRAW_SHOW);

			TextDrawHideForPlayer(playerid, teplica_buy_menu[0]);
			TextDrawHideForPlayer(playerid, teplica_buy_menu[1]);
			TextDrawHideForPlayer(playerid, teplica_buy_menu[2]);
			TextDrawHideForPlayer(playerid, teplica_buy_menu[3]);
			TextDrawHideForPlayer(playerid, teplica_buy_menu[4]);
			TextDrawHideForPlayer(playerid, teplica_buy_menu[5]);
			TextDrawHideForPlayer(playerid, teplica_buy_menu[6]);

			CancelSelectTextDraw(playerid);
		}
	}



	return true;
}


stock show_menu_buy_teplica_house(playerid, type)
{
	switch(type)
	{
		case TEXTDRAW_SHOW:
		{
			show_menu_start_teplica(playerid, TEXTDRAW_HIDE);

			show_info_gui(playerid, TEXTDRAW_HIDE);

			hide_hud_element(playerid);
			show_player_green_zone(playerid, TEXTDRAW_HIDE);

			TextDrawShowForPlayer(playerid, teplica_buy_menu[0]);
			TextDrawShowForPlayer(playerid, teplica_buy_menu[1]);
			TextDrawShowForPlayer(playerid, teplica_buy_menu[2]);
			TextDrawShowForPlayer(playerid, teplica_buy_menu[3]);
			TextDrawShowForPlayer(playerid, teplica_buy_menu[4]);
			TextDrawShowForPlayer(playerid, teplica_buy_menu[5]);
			TextDrawShowForPlayer(playerid, teplica_buy_menu[6]);

			SelectTextDraw(playerid, COLOR_BLUE);

		}
		case TEXTDRAW_HIDE:
		{
			if(pGreenZone[playerid])
			{
				show_player_green_zone(playerid, TEXTDRAW_SHOW);
			}
			show_hud_element(playerid);
			show_hud_hungry(playerid);

			show_info_gui(playerid, TEXTDRAW_SHOW);

			TextDrawHideForPlayer(playerid, teplica_buy_menu[0]);
			TextDrawHideForPlayer(playerid, teplica_buy_menu[1]);
			TextDrawHideForPlayer(playerid, teplica_buy_menu[2]);
			TextDrawHideForPlayer(playerid, teplica_buy_menu[3]);
			TextDrawHideForPlayer(playerid, teplica_buy_menu[4]);
			TextDrawHideForPlayer(playerid, teplica_buy_menu[5]);
			TextDrawHideForPlayer(playerid, teplica_buy_menu[6]);

			CancelSelectTextDraw(playerid);
		}
	}
	return true;
}

stock hide_all_green_house_gui(playerid)
{


	show_menu_buy_teplica_flate(playerid, TEXTDRAW_HIDE);
	show_menu_buy_teplica_house(playerid, TEXTDRAW_HIDE);
	show_menu_start_teplica(playerid, TEXTDRAW_HIDE);

	return true;
}

stock buy_teplica_pre_finall(playerid, type)
{

	if(pData[playerid][pGreenHouse] == type)
		return SendErr(playerid, "У вас уже имеется теплицы данного класса!");

	SetPVarIntNew(playerid, "buy_teplica_type", type);

	switch(type)
	{
		case 1:
		{
			format(String512, sizeof(String512), "\
			"cWH"Вы действительно хотите приобрести теплицу?\n\n\
			Класс теплицы: %s\n\
			Стоимость теплицы: "cGR"%d рублей"cWH"\n\n\
			Доступные продукты для выращивания:\n\n\
			"cBLUE"-"cWH" Огурцы\n\
			"cBLUE"-"cWH" Помидоры\n\n\
			Для подтверждения покупки нажмите 'Далее'\n\
			", get_green_house_n(type), GREEN_HOUSE_PRICE_1);
			SPD(playerid, DIALOG_BUY_TEPLICA, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка теплицы", String512, !"Далее", !"Назад");	
		}
		case 2: 
		{
			format(String512, sizeof(String512), "\
			"cWH"Вы действительно хотите приобрести теплицу?\n\n\
			Класс теплицы: "cBLUE"%s"cWH"\n\
			Стоимость теплицы: "cGR"%d рублей"cWH"\n\n\
			Доступные продукты для выращивания:\n\n\
			"cBLUE"-"cWH" Огурцы\n\
			"cBLUE"-"cWH" Помидоры\n\
			"cBLUE"-"cWH" Лимоны\n\
			"cBLUE"-"cWH" Манго\n\
			"cBLUE"-"cWH" Сливы\n\n\
			Для подтверждения покупки нажмите 'Далее'\n\
			", get_green_house_n(type), GREEN_HOUSE_PRICE_2);
			SPD(playerid, DIALOG_BUY_TEPLICA, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка теплицы", String512, !"Далее", !"Назад");	
		}
		case 3:
		{
			format(String1024, sizeof(String1024), "\
			"cWH"Вы действительно хотите приобрести теплицу?\n\n\
			Класс теплицы: "cBLUE"%s"cWH"\n\
			Стоимость теплицы: "cGR"%d рублей"cWH"\n\n\
			Доступные продукты для выращивания:\n\n\
			"cBLUE"-"cWH" Огурцы\n\
			"cBLUE"-"cWH" Помидоры\n\
			"cBLUE"-"cWH" Лимоны\n\
			"cBLUE"-"cWH" Манго\n\
			"cBLUE"-"cWH" Сливы\n\
			"cBLUE"-"cWH" Маракуйя\n\
			"cBLUE"-"cWH" Гранаты\n\
			"cBLUE"-"cWH" Персики\n\n\
			Для подтверждения покупки нажмите 'Далее'\n\
			", get_green_house_n(type), GREEN_HOUSE_PRICE_3);
			SPD(playerid, DIALOG_BUY_TEPLICA, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка теплицы", String1024, !"Далее", !"Назад");	
		}
	}
	return true;
}

stock enter_teplice_player(playerid)
{
	new 
		green_house_class;


	format(String144, sizeof(String144), "SELECT * FROM `greenhouse` WHERE greenhouse_owner_id = '%d'", pData[playerid][pMysqlID]);
	new Result:greenhouse_info = sql_queryEx(zConn, String144, QUERY_CACHED);

	if(sql_num_rows(greenhouse_info)) 
	{
		green_house_class = sql_get_field_assoc_int_ex(greenhouse_info, 0, "greenhouse_class");

	}
	else
	{
		return SendErr(playerid, "У вас нет теплицы!");
	}
	sql_free_result(greenhouse_info);


	if(pData[playerid][pHouse] != -1)
	{
		SetPVarIntNew(playerid, "enter_teplica_house", 1);
		SendInf(playerid, "Вы успешно вошли в свою теплицу из дома!");
	}
	else
	{
		SetPVarIntNew(playerid, "enter_teplica_local", 1);
		SendInf(playerid, "Вы успешно вошли в свою теплицу!");
	}

	if(pData[playerid][pGreenHouse] == GREEN_HOUSE_CLASS_1)
	{
		SetPlayerPosEx(playerid, GREEN_HOUSE_1_ENTER);
		SetPlayerVirtualWorld(playerid, playerid+1);
	}
	else if(pData[playerid][pGreenHouse] == GREEN_HOUSE_CLASS_2)
	{
		SetPlayerPosEx(playerid, GREEN_HOUSE_2_ENTER);
		SetPlayerVirtualWorld(playerid, playerid+1);			
	}
	else if(pData[playerid][pGreenHouse] == GREEN_HOUSE_CLASS_3)
	{
		SetPlayerPosEx(playerid, GREEN_HOUSE_3_ENTER);
		SetPlayerVirtualWorld(playerid, playerid+1);			
	}

	hide_all_green_house_gui(playerid);

	return true;
}

stock exit_green_house(playerid)
{

	SetPlayerPosEx(playerid, GREEN_HOUSE_EXIT_COORD);
	SetPlayerVirtualWorld(playerid, 0);
	return true;
}

stock green_house_menu_semena(playerid, type)
{

	SetPVarIntNew(playerid, "select_green_house_type", type);

    format(String256, sizeof(String256), "\
        "cGREY"Тип\t"cGREY"Стоимость\n\
        "cBLUE"1. "cWH"Покупка семян растения\t"cGR"%d рублей"cWH" за 1 семя\n\
        "cBLUE"2. "cWH"Продажа %s\t"cGR"%d рублей"cWH" за 1 штуку", green_house_price_semena[type-1], get_prod_green_house_n(type), green_house_price_prod[type-1]);
    return SPD(playerid, DIALOG_SELECT_GREEN_HOUSE, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Тепличный Комплекс", String256, !"Выбрать", !"Закрыть"); 
}

stock green_house_semena_all(playerid)
{
    format(String1024, sizeof(String1024), "\
        "cGREY"Тип\t"cGREY"Стоимость\n\
        "cBLUE"1. "cWH"Покупка семян %s\t"cGR"%d рублей"cWH" за 1\n\
        "cBLUE"2. "cWH"Покупка семян %s\t"cGR"%d рублей"cWH" за 1\n\
        "cBLUE"3. "cWH"Покупка семян %s\t"cGR"%d рублей"cWH" за 1\n\
        "cBLUE"4. "cWH"Покупка семян %s\t"cGR"%d рублей"cWH" за 1\n\
        "cBLUE"5. "cWH"Покупка семян %s\t"cGR"%d рублей"cWH" за 1\n\
        "cBLUE"6. "cWH"Покупка семян %s\t"cGR"%d рублей"cWH" за 1\n\
        "cBLUE"7. "cWH"Покупка семян %s\t"cGR"%d рублей"cWH" за 1\n\
        "cBLUE"8. "cWH"Покупка семян %s\t"cGR"%d рублей"cWH" за 1", 

        get_prod_green_house_n(1), green_house_price_semena[0],
        get_prod_green_house_n(2), green_house_price_semena[1],
        get_prod_green_house_n(3), green_house_price_semena[2],
        get_prod_green_house_n(4), green_house_price_semena[3],
        get_prod_green_house_n(5), green_house_price_semena[4],
        get_prod_green_house_n(6), green_house_price_semena[5],
        get_prod_green_house_n(7), green_house_price_semena[6],
        get_prod_green_house_n(8), green_house_price_semena[7]);
    return SPD(playerid, DIALOG_SELECT_BUY_SEMENA, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Тепличный Комплекс", String1024, !"Выбрать", !"Закрыть"); 
}

stock green_house_buy_semena(playerid, type)
{
	if(pData[playerid][pGreenHouse] == 1 && type == 3 || pData[playerid][pGreenHouse] == 1 && type == 4 || pData[playerid][pGreenHouse] == 1 && type == 5 ||
	pData[playerid][pGreenHouse] == 1 && type == 6 || pData[playerid][pGreenHouse] == 1 && type == 7 || pData[playerid][pGreenHouse] == 1 && type == 8)
	return SendErr(playerid, "Вам недоступна покупка семян данного типа!");

	if(pData[playerid][pGreenHouse] == 2 && type == 6 || pData[playerid][pGreenHouse] == 2 && type == 7 || pData[playerid][pGreenHouse] == 2 && type == 8)
		return SendErr(playerid, "Вам недоступна покупка семян данного типа!");

	SetPVarIntNew(playerid, "select_green_house_type", type);

	format(String256, sizeof(String256), "\
	"cWH"Сколько семян Вы хотите приобрести?\n\n\
	Стоимость 1-го семяни %s составляет "cGR"%d рублей"cWH" на данный момент!", get_prod_green_house_n(type), green_house_price_semena[type-1]);
	return SPD(playerid, DIALOG_BUY_SEMENA_GREEN_H, DIALOG_STYLE_INPUT, !""cBLUE"Покупка семян", String256, !"Далее", !"Назад");			
}

stock green_house_sell_prod(playerid, type)
{
	format(String256, sizeof(String256), "\
	"cWH"Сколько продукции Вы хотите продать?\n\n\
	Стоимость 1-го %s составляет "cGR"%d рублей"cWH" на данный момент!", get_prod_green_house_n(type), green_house_price_prod[type-1]);
	return SPD(playerid, DIALOG_SELL_SEMENA_GREEN_H, DIALOG_STYLE_INPUT, !""cBLUE"Продажа продукции", String256, !"Далее", !"Назад");			
}

stock dialog_all_green_house(playerid, dialogid, response, listitem, inputtext[])
{

	switch(dialogid)
	{
		case DIALOG_SELECT_BUY_SEMENA:
		{
			if(!response)
				return true;

			green_house_buy_semena(playerid, listitem+1);	
		}
		case DIALOG_BUY_TEPLICA:
		{
			if(!response)
			{
				DeletePVarNew(playerid, "buy_teplica_type");
				return true;
			}		
			
			new 
				type_teplica_price;

			if(GetPVarIntNew(playerid, "buy_teplica_type") == 1) type_teplica_price = GREEN_HOUSE_PRICE_1;
			else if(GetPVarIntNew(playerid, "buy_teplica_type") == 2) type_teplica_price = GREEN_HOUSE_PRICE_2;
			else if(GetPVarIntNew(playerid, "buy_teplica_type") == 3) type_teplica_price = GREEN_HOUSE_PRICE_3;

			if(GetPlayerMoneyEx(playerid) < type_teplica_price)
			{
				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
				buy_teplica_pre_finall(playerid, GetPVarIntNew(playerid, "buy_teplica_type"));
				return SendErr(playerid, "У вас недостаточно денежных средств!");
			}

			if(pData[playerid][pGreenHouse] == GetPVarIntNew(playerid, "buy_teplica_type"))
				return SendErr(playerid, "У Вас уже имеется теплица данного уровня!");

			give_money(playerid, -type_teplica_price, "Покупка теплицы");

		    format(String144, sizeof(String144), "INSERT INTO greenhouse(greenhouse_owner_id, greenhouse_class) VALUES ('%d', '%d')",
		    pData[playerid][pMysqlID], GetPVarIntNew(playerid, "buy_teplica_type"));
		    sql_queryEx(zConn, String144, QUERY_THREADED);

			pData[playerid][pGreenHouse] = GetPVarIntNew(playerid, "buy_teplica_type");
			UpdatePlayerData(playerid,"pGreenHouse", pData[playerid][pGreenHouse]);

			show_menu_buy_teplica_flate(playerid, TEXTDRAW_HIDE);
			show_menu_buy_teplica_house(playerid, TEXTDRAW_HIDE);
			show_menu_start_teplica(playerid, TEXTDRAW_SHOW);


			format(String256, sizeof(String256), "\
				"cWH"Поздравляем Вас с приобретением Теплицы!\n\n\
				"cWH"Для того, чтобы выращивать продукцию в теплицы приобретите семена!");
			return SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка теплицы", String256, !"Понял", !"");

		}
		case DIALOG_SELECT_GREEN_HOUSE:
		{
			if(!response)
			{
				DeletePVarNew(playerid, "select_green_house_type");
				return true;
			}

			switch(listitem)
			{
				case 0: return green_house_buy_semena(playerid, GetPVarIntNew(playerid, "select_green_house_type"));
				case 1: return green_house_sell_prod(playerid, GetPVarIntNew(playerid, "select_green_house_type"));
			}
		}
		case DIALOG_BUY_SEMENA_GREEN_H:
		{
			if(!response)
			{
				green_house_menu_semena(playerid, GetPVarIntNew(playerid, "select_green_house_type"));
				return true;
			}			

			if(!IsNumeric(inputtext) || !strlen(inputtext))
			{
				SendErr(playerid,"Вы указали неверное количество семян!");
				return green_house_buy_semena(playerid, GetPVarIntNew(playerid, "select_green_house_type"));
			}

			new 
				count_semena_buy = strval(inputtext);


			if(count_semena_buy < 1)
			{
				SendErr(playerid,"Вы указали неверное количество семян!");
				return green_house_buy_semena(playerid, GetPVarIntNew(playerid, "select_green_house_type"));			
			}

			new 
				final_price_semena = count_semena_buy*green_house_price_semena[GetPVarIntNew(playerid, "select_green_house_type")-1];

			if(GetPlayerMoneyEx(playerid) < final_price_semena)
			{
				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
				green_house_buy_semena(playerid, GetPVarIntNew(playerid, "select_green_house_type"));
				return SendErr(playerid, "У вас недостаточно денежных средств!");
			}

			give_money(playerid, -final_price_semena, "Покупка семян");

			if(GetPVarIntNew(playerid, "select_green_house_type") == 1) give_inventory_items(playerid, 349, count_semena_buy);
			else if(GetPVarIntNew(playerid, "select_green_house_type") == 2) give_inventory_items(playerid, 350, count_semena_buy);
			else if(GetPVarIntNew(playerid, "select_green_house_type") == 3) give_inventory_items(playerid, 351, count_semena_buy);
			else if(GetPVarIntNew(playerid, "select_green_house_type") == 4) give_inventory_items(playerid, 352, count_semena_buy);
			else if(GetPVarIntNew(playerid, "select_green_house_type") == 5) give_inventory_items(playerid, 353, count_semena_buy);
			else if(GetPVarIntNew(playerid, "select_green_house_type") == 6) give_inventory_items(playerid, 354, count_semena_buy);
			else if(GetPVarIntNew(playerid, "select_green_house_type") == 7) give_inventory_items(playerid, 355, count_semena_buy);
			else if(GetPVarIntNew(playerid, "select_green_house_type") == 8) give_inventory_items(playerid, 356, count_semena_buy);

			new 
				type = GetPVarIntNew(playerid, "select_green_house_type");

			format(String144, sizeof(String144), "Вы успешно приобрели семена %s в количестве %d штук! Вы отдали "cGR"%d рублей"cWH"!", get_prod_green_house_n(type), count_semena_buy, final_price_semena);
			SendSucc(playerid, String144);

			update_count_semena_panel(playerid, GetPVarIntNew(playerid, "select_green_house_type"));


		}
		case DIALOG_SELL_SEMENA_GREEN_H:
		{
			if(!response)
			{
				green_house_menu_semena(playerid, GetPVarIntNew(playerid, "select_green_house_type"));
				return true;
			}			

			if(!IsNumeric(inputtext) || !strlen(inputtext))
			{
				SendErr(playerid,"Вы указали неверное количество продукции!");
				return green_house_sell_prod(playerid, GetPVarIntNew(playerid, "select_green_house_type"));
			}

			new 
				count_semena_buy = strval(inputtext);


			if(count_semena_buy < 1)
			{
				SendErr(playerid,"Вы указали неверное количество семян!");
				return green_house_sell_prod(playerid, GetPVarIntNew(playerid, "select_green_house_type"));			
			}

			new 
				type_prod_id;

			if(GetPVarIntNew(playerid, "select_green_house_type") == 1) type_prod_id = 341;
			else if(GetPVarIntNew(playerid, "select_green_house_type") == 2) type_prod_id = 342;
			else if(GetPVarIntNew(playerid, "select_green_house_type") == 3) type_prod_id = 343;
			else if(GetPVarIntNew(playerid, "select_green_house_type") == 4) type_prod_id = 344;
			else if(GetPVarIntNew(playerid, "select_green_house_type") == 5) type_prod_id = 345;
			else if(GetPVarIntNew(playerid, "select_green_house_type") == 6) type_prod_id = 346;
			else if(GetPVarIntNew(playerid, "select_green_house_type") == 7) type_prod_id = 347;
			else if(GetPVarIntNew(playerid, "select_green_house_type") == 8) type_prod_id = 348;

			if(get_inventory_items(playerid, type_prod_id) < count_semena_buy)
			{
				SendErr(playerid,"У вас недостаточно продукции для продажи!");
				return green_house_sell_prod(playerid, GetPVarIntNew(playerid, "select_green_house_type"));		
			}

			new 
				final_price_semena = count_semena_buy*green_house_price_prod[GetPVarIntNew(playerid, "select_green_house_type")-1];

			check_remove_inventory(playerid, type_prod_id, get_inventory_items_slot(playerid, type_prod_id), -count_semena_buy);

			give_money(playerid, final_price_semena, "Покупка семян");


			new 
				type = GetPVarIntNew(playerid, "select_green_house_type");

			format(String144, sizeof(String144), "Вы успешно продали продукцию %s в количестве %d штук! Вы получили "cGR"%d рублей"cWH"!", get_prod_green_house_n(type), green_house_price_prod[type-1], final_price_semena);
			SendSucc(playerid, String144);			
		}
	}
	return true;
}

stock green_house_place_semena(playerid)
{
	new 
		semena_type = GetPVarIntNew(playerid, "select_type_semena");

	switch(semena_type)
	{
		case 1:
		{
			if(GetPVarIntNew(playerid, "place_green_house_final"))
				return SendErr(playerid, "Вы уже посадили семена, ожидайте пока они вырастут!");

			if(get_inventory_items(playerid, 349) < MIN_COUNT_SEMENA)
				return SendErr(playerid,"У вас недостаточно семян для посадки в огород (Минимально 5 семян)!");

			give_inventory_items(playerid, 349, -MIN_COUNT_SEMENA);
			SendSucc(playerid, "Вы успешно посадили семена 'Огурцов' в огород!");

			SetPVarIntNew(playerid, "place_green_house_final", 1);

			start_rise_plant_player(playerid, 1);
			update_count_semena_panel(playerid, 1);
		}
		case 2:
		{
			if(GetPVarIntNew(playerid, "place_green_house_final"))
				return SendErr(playerid, "Вы уже посадили семена, ожидайте пока они вырастут!");

			if(get_inventory_items(playerid, 350) < MIN_COUNT_SEMENA)
				return SendErr(playerid,"У вас недостаточно семян для посадки в огород (Минимально 5 семян)!");

			give_inventory_items(playerid, 350, -MIN_COUNT_SEMENA);
			SendSucc(playerid, "Вы успешно посадили семена 'Помидоров' в огород!");

			SetPVarIntNew(playerid, "place_green_house_final", 2);

			start_rise_plant_player(playerid, 2);
			update_count_semena_panel(playerid, 2);
		}
		case 3:
		{
			if(GetPVarIntNew(playerid, "place_green_house_final"))
				return SendErr(playerid, "Вы уже посадили семена, ожидайте пока они вырастут!");

			if(get_inventory_items(playerid, 351) < MIN_COUNT_SEMENA)
				return SendErr(playerid,"У вас недостаточно семян для посадки в огород (Минимально 5 семян)!");
			give_inventory_items(playerid, 351, -MIN_COUNT_SEMENA);
			SendSucc(playerid, "Вы успешно посадили семена 'Манго' в огород!");

			SetPVarIntNew(playerid, "place_green_house_final", 3);

			start_rise_plant_player(playerid, 3);
			update_count_semena_panel(playerid, 3);
		}
		case 4:
		{
			if(GetPVarIntNew(playerid, "place_green_house_final"))
				return SendErr(playerid, "Вы уже посадили семена, ожидайте пока они вырастут!");

			if(get_inventory_items(playerid, 352) < MIN_COUNT_SEMENA)
				return SendErr(playerid,"У вас недостаточно семян для посадки в огород (Минимально 5 семян)!");

			give_inventory_items(playerid, 352, -MIN_COUNT_SEMENA);
			SendSucc(playerid, "Вы успешно посадили семена 'Слив' в огород!");

			SetPVarIntNew(playerid, "place_green_house_final", 4);

			start_rise_plant_player(playerid, 4);
			update_count_semena_panel(playerid, 4);
		}
		case 5:
		{
			if(GetPVarIntNew(playerid, "place_green_house_final"))
				return SendErr(playerid, "Вы уже посадили семена, ожидайте пока они вырастут!");

			if(get_inventory_items(playerid, 353) < MIN_COUNT_SEMENA)
				return SendErr(playerid,"У вас недостаточно семян для посадки в огород (Минимально 5 семян)!");

			give_inventory_items(playerid, 353, -MIN_COUNT_SEMENA);
			SendSucc(playerid, "Вы успешно посадили семена 'Маракуйа' в огород!");

			SetPVarIntNew(playerid, "place_green_house_final", 5);

			start_rise_plant_player(playerid, 5);
			update_count_semena_panel(playerid, 5);
		}
		case 6:
		{
			if(GetPVarIntNew(playerid, "place_green_house_final"))
				return SendErr(playerid, "Вы уже посадили семена, ожидайте пока они вырастут!");

			if(get_inventory_items(playerid, 354) < MIN_COUNT_SEMENA)
				return SendErr(playerid,"У вас недостаточно семян для посадки в огород (Минимально 5 семян)!");

			give_inventory_items(playerid, 354, -MIN_COUNT_SEMENA);
			SendSucc(playerid, "Вы успешно посадили семена 'Граната' в огород!");

			SetPVarIntNew(playerid, "place_green_house_final", 6);

			start_rise_plant_player(playerid, 6);
			update_count_semena_panel(playerid, 6);
		}
		case 7:
		{
			if(GetPVarIntNew(playerid, "place_green_house_final"))
				return SendErr(playerid, "Вы уже посадили семена, ожидайте пока они вырастут!");

			if(get_inventory_items(playerid, 355) < MIN_COUNT_SEMENA)
				return SendErr(playerid,"У вас недостаточно семян для посадки в огород (Минимально 5 семян)!");

			give_inventory_items(playerid, 355, -MIN_COUNT_SEMENA);
			SendSucc(playerid, "Вы успешно посадили семена 'Персиков' в огород!");

			SetPVarIntNew(playerid, "place_green_house_final", 7);

			start_rise_plant_player(playerid, 7);
			update_count_semena_panel(playerid, 7);
		}
		case 8:
		{
			if(GetPVarIntNew(playerid, "place_green_house_final"))
				return SendErr(playerid, "Вы уже посадили семена, ожидайте пока они вырастут!");

			if(get_inventory_items(playerid, 356) < MIN_COUNT_SEMENA)
				return SendErr(playerid,"У вас недостаточно семян для посадки в огород (Минимально 5 семян)!");

			give_inventory_items(playerid, 356, -MIN_COUNT_SEMENA);
			SendSucc(playerid, "Вы успешно посадили семена 'Лимонов' в огород!");

			SetPVarIntNew(playerid, "place_green_house_final", 8);

			start_rise_plant_player(playerid, 8);
			update_count_semena_panel(playerid, 8);
		}
	}

	return true;
}

stock start_rise_plant_player(playerid, type)
{
	switch(type)
	{
		case 1:
		{
			timer_rice_plant[playerid] = SetTimerEx("timer_rice_plant_callback", 30000, 1, "i", playerid);
			progress_rice_water[playerid] = 50;
			show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_work_40", 5000);
		}
		case 2:
		{
			timer_rice_plant[playerid] = SetTimerEx("timer_rice_plant_callback", 30000, 1, "i", playerid);
			progress_rice_water[playerid] = 50;
			show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_work_40", 5000);
		}
		case 3:
		{
			timer_rice_plant[playerid] = SetTimerEx("timer_rice_plant_callback", 25000, 1, "i", playerid);
			progress_rice_water[playerid] = 50;
			show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_work_40", 5000);
		}
		case 4:
		{
			timer_rice_plant[playerid] = SetTimerEx("timer_rice_plant_callback", 25000, 1, "i", playerid);
			progress_rice_water[playerid] = 50;
			show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_work_40", 5000);
		}
		case 5:
		{
			timer_rice_plant[playerid] = SetTimerEx("timer_rice_plant_callback", 25000, 1, "i", playerid);
			progress_rice_water[playerid] = 50;
			show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_work_40", 5000);
		}
		case 6:
		{
			timer_rice_plant[playerid] = SetTimerEx("timer_rice_plant_callback", 15000, 1, "i", playerid);
			progress_rice_water[playerid] = 50;
			show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_work_40", 5000);
		}
		case 7:
		{
			timer_rice_plant[playerid] = SetTimerEx("timer_rice_plant_callback", 15000, 1, "i", playerid);
			progress_rice_water[playerid] = 50;
			show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_work_40", 5000);
		}
		case 8:
		{
			timer_rice_plant[playerid] = SetTimerEx("timer_rice_plant_callback", 15000, 1, "i", playerid);
			progress_rice_water[playerid] = 50;
			show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_work_40", 5000);
		}
	}



	return true;
}


callback:: timer_rice_plant_callback(playerid)
{

	if(progress_rice_water[playerid] < 5)
	{
		progress_water_warning[playerid]++;

		SendErr(playerid, "Растение скоро засохнет! Нажмите 'Полить грядку'");

		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_work_37", 5000);

		if(progress_water_warning[playerid] == 3)
		{
			progress_water_warning[playerid] = 0;
			return green_house_fail_prod(playerid);

		}
	}

	if(progress_rice_plant[playerid] < 100 && progress_rice_water[playerid] > 10)
	{	

		create_player_green_house_2(playerid);

		progress_rice_water[playerid] -= 25;
		progress_rice_plant[playerid] += 25;

		if(progress_rice_plant[playerid] >= 25 && progress_rice_plant[playerid] < 50)
		{
			PlayerTextDrawShow(playerid, general_green_house[9][playerid]);
		}
		else if(progress_rice_plant[playerid] >= 50 && progress_rice_plant[playerid] < 75)
		{
			PlayerTextDrawShow(playerid, general_green_house[9][playerid]);
			PlayerTextDrawShow(playerid, general_green_house[10][playerid]);
		}
		else if(progress_rice_plant[playerid] >= 100)
		{
			PlayerTextDrawShow(playerid, general_green_house[9][playerid]);
			PlayerTextDrawShow(playerid, general_green_house[10][playerid]);
			PlayerTextDrawShow(playerid, general_green_house[11][playerid]);
		}


		if(progress_rice_water[playerid] >= 25 && progress_rice_water[playerid] < 50)
		{
			PlayerTextDrawHideEx(playerid, general_green_house[7][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[8][playerid]);
			PlayerTextDrawShow(playerid, general_green_house[6][playerid]);
		}
		else if(progress_rice_water[playerid] >= 50 && progress_rice_water[playerid] < 75)
		{
			PlayerTextDrawHideEx(playerid, general_green_house[8][playerid]);
			PlayerTextDrawShow(playerid, general_green_house[7][playerid]);
		}
		else if(progress_rice_water[playerid] >= 75 && progress_rice_water[playerid] <= 100)
		{
			PlayerTextDrawShow(playerid, general_green_house[8][playerid]);
		}

		if(progress_rice_plant[playerid] >= 100)
		{
			final_rice_plant_player(playerid);
		}
	}


	return true;
}


stock update_visual_green_rice(playerid, type)
{
	if(GetPVarIntNew(playerid, "place_green_house_final") == type)
	{	

		create_player_green_house_2(playerid);

		if(progress_rice_plant[playerid] >= 25 && progress_rice_plant[playerid] < 50)
		{
			PlayerTextDrawShow(playerid, general_green_house[9][playerid]);
		}
		else if(progress_rice_plant[playerid] >= 50 && progress_rice_plant[playerid] < 75)
		{
			PlayerTextDrawShow(playerid, general_green_house[9][playerid]);
			PlayerTextDrawShow(playerid, general_green_house[10][playerid]);
		}
		else if(progress_rice_plant[playerid] >= 100)
		{
			PlayerTextDrawShow(playerid, general_green_house[9][playerid]);
			PlayerTextDrawShow(playerid, general_green_house[10][playerid]);
			PlayerTextDrawShow(playerid, general_green_house[11][playerid]);
		}

		if(progress_rice_water[playerid] >= 25 && progress_rice_water[playerid] < 50)
		{
			PlayerTextDrawHideEx(playerid, general_green_house[7][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[8][playerid]);
			PlayerTextDrawShow(playerid, general_green_house[6][playerid]);
		}
		else if(progress_rice_water[playerid] >= 50 && progress_rice_water[playerid] < 75)
		{
			PlayerTextDrawHideEx(playerid, general_green_house[8][playerid]);
			PlayerTextDrawShow(playerid, general_green_house[7][playerid]);
		}
		else if(progress_rice_water[playerid] >= 75 && progress_rice_water[playerid] <= 100)
		{
			PlayerTextDrawShow(playerid, general_green_house[8][playerid]);
		}

	}

	update_count_semena_panel(playerid, type);
	return true;
}

callback:: timer_rice_plant_temp(playerid)
{
	if(GetPVarIntNew(playerid, "green_house_panel_open") == TEXTDRAW_SHOW)
	{
		new 
			teplica_temp_update, fmt_str[32];

		teplica_temp_update = RandomEx(20,40);

		format(fmt_str, 32, "%d", teplica_temp_update);
		PlayerTextDrawSetString(playerid, general_green_house[25][playerid], fmt_str);
		PlayerTextDrawShow(playerid,general_green_house[25][playerid]);
	}

}

stock final_rice_plant_player(playerid)
{
	KillTimer(timer_rice_plant[playerid]);
	

	SendSucc(playerid, "Растение выросло и Вы можете его собрать! Нажмите кнопку 'Выкопать выросшее растение'");

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_work_39", 5000);

	return true;
}

stock water_rice_plant_player(playerid)
{
	if(progress_rice_water[playerid] < 100 && progress_rice_plant[playerid] > 0)
	{
		progress_rice_water[playerid] +=25;
		SendSucc(playerid, "Вы успешно полили растение и рост продолжается!");

		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_work_38", 5000);

		create_player_green_house_2(playerid);

		if(progress_rice_water[playerid] >= 25 && progress_rice_water[playerid] < 50)
		{
			PlayerTextDrawShow(playerid, general_green_house[6][playerid]);
		}
		else if(progress_rice_water[playerid] >= 50 && progress_rice_water[playerid] < 75)
		{
			PlayerTextDrawShow(playerid, general_green_house[7][playerid]);
		}
		else if(progress_rice_water[playerid] >= 75 && progress_rice_water[playerid] <= 100)
		{
			PlayerTextDrawShow(playerid, general_green_house[8][playerid]);
		}

		if(progress_rice_water[playerid] >= 25 && progress_rice_water[playerid] < 50)
		{
			PlayerTextDrawHideEx(playerid, general_green_house[7][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[8][playerid]);
			PlayerTextDrawShow(playerid, general_green_house[6][playerid]);
		}
		else if(progress_rice_water[playerid] >= 50 && progress_rice_water[playerid] < 75)
		{
			PlayerTextDrawHideEx(playerid, general_green_house[8][playerid]);
			PlayerTextDrawShow(playerid, general_green_house[7][playerid]);
		}
		else if(progress_rice_water[playerid] >= 75 && progress_rice_water[playerid] <= 100)
		{
			PlayerTextDrawShow(playerid, general_green_house[8][playerid]);
		}
	}

	return true;
}

stock green_house_fail_prod(playerid)
{


	progress_rice_water[playerid] = 0;
	progress_rice_plant[playerid] = 0;
	KillTimer(timer_rice_plant[playerid]);

	PlayerTextDrawHideEx(playerid, general_green_house[9][playerid]);
	PlayerTextDrawHideEx(playerid, general_green_house[10][playerid]);
	PlayerTextDrawHideEx(playerid, general_green_house[11][playerid]);
	PlayerTextDrawHideEx(playerid, general_green_house[8][playerid]);
	PlayerTextDrawHideEx(playerid, general_green_house[7][playerid]);
	PlayerTextDrawHideEx(playerid, general_green_house[6][playerid]);

	DeletePVarNew(playerid, "place_green_house_final");

	SendErr(playerid, "Растение засохло и умерло!");

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_work_41", 5000);

	return true;
}

stock give_final_product_green_h(playerid)
{
	new 
		type_production = GetPVarIntNew(playerid, "place_green_house_final");

	if(progress_rice_plant[playerid] < 100)
		return SendErr(playerid, "Растение находится в стадии роста, ожидайте!");

	progress_rice_water[playerid] = 0;
	KillTimer(timer_rice_plant[playerid]);
	progress_rice_plant[playerid] = 0;

	PlayerTextDrawHideEx(playerid, general_green_house[9][playerid]);
	PlayerTextDrawHideEx(playerid, general_green_house[10][playerid]);
	PlayerTextDrawHideEx(playerid, general_green_house[11][playerid]);
	PlayerTextDrawHideEx(playerid, general_green_house[8][playerid]);
	PlayerTextDrawHideEx(playerid, general_green_house[7][playerid]);
	PlayerTextDrawHideEx(playerid, general_green_house[6][playerid]);

	switch(type_production)
	{
		case 1:
		{
			give_inventory_items(playerid, 341, 5);
			format(String144, sizeof(String144), "Вы успешно собрали урожай %s в количестве %d штук! (( /inv ))", get_prod_green_house_n(type_production), 5);
			SendSucc(playerid, String144);

			DeletePVarNew(playerid, "place_green_house_final");
		}
		case 2:
		{
			give_inventory_items(playerid, 342, 5);

			format(String144, sizeof(String144), "Вы успешно собрали урожай %s в количестве %d штук! (( /inv ))", get_prod_green_house_n(type_production), 5);
			SendSucc(playerid, String144);

			DeletePVarNew(playerid, "place_green_house_final");

		}
		case 3:
		{
			give_inventory_items(playerid, 343, 5);

			format(String144, sizeof(String144), "Вы успешно собрали урожай %s в количестве %d штук! (( /inv ))", get_prod_green_house_n(type_production), 5);
			SendSucc(playerid, String144);

			DeletePVarNew(playerid, "place_green_house_final");

		}
		case 4:
		{
			give_inventory_items(playerid, 344, 5);

			format(String144, sizeof(String144), "Вы успешно собрали урожай %s в количестве %d штук! (( /inv ))", get_prod_green_house_n(type_production), 5);
			SendSucc(playerid, String144);

			DeletePVarNew(playerid, "place_green_house_final");

		}
		case 5:
		{
			give_inventory_items(playerid, 345, 5);

			format(String144, sizeof(String144), "Вы успешно собрали урожай %s в количестве %d штук! (( /inv ))", get_prod_green_house_n(type_production), 5);
			SendSucc(playerid, String144);

			DeletePVarNew(playerid, "place_green_house_final");

		}
		case 6:
		{
			give_inventory_items(playerid, 346, 5);

			format(String144, sizeof(String144), "Вы успешно собрали урожай %s в количестве %d штук! (( /inv ))", get_prod_green_house_n(type_production), 5);
			SendSucc(playerid, String144);

			DeletePVarNew(playerid, "place_green_house_final");

		}
		case 7:
		{
			give_inventory_items(playerid, 347, 5);

			format(String144, sizeof(String144), "Вы успешно собрали урожай %s в количестве %d штук! (( /inv ))", get_prod_green_house_n(type_production), 5);
			SendSucc(playerid, String144);

			DeletePVarNew(playerid, "place_green_house_final");

		}
		case 8:
		{
			give_inventory_items(playerid, 348, 5);

			format(String144, sizeof(String144), "Вы успешно собрали урожай %s в количестве %d штук! (( /inv ))", get_prod_green_house_n(type_production), 5);
			SendSucc(playerid, String144);

			DeletePVarNew(playerid, "place_green_house_final");

		}
	}

	return true;
}

stock update_count_semena_panel(playerid, type_semena)
{
	new 
		fmt_str[32];

	switch(type_semena)
	{
		case 1:
		{
			new 
				count_semena_player;

			count_semena_player = get_inventory_items(playerid, 349);

			format(fmt_str, sizeof(fmt_str), "%d", count_semena_player);
			PlayerTextDrawSetString(playerid, general_green_house[27][playerid], fmt_str);
			PlayerTextDrawShow(playerid, general_green_house[27][playerid]);
		}
		case 2:
		{
			new 
				count_semena_player;

			count_semena_player = get_inventory_items(playerid, 350);

			format(fmt_str, sizeof(fmt_str), "%d", count_semena_player);
			PlayerTextDrawSetString(playerid, general_green_house[27][playerid], fmt_str);
			PlayerTextDrawShow(playerid, general_green_house[27][playerid]);
		}
		case 3:
		{
			new 
				count_semena_player;

			count_semena_player = get_inventory_items(playerid, 351);

			format(fmt_str, sizeof(fmt_str), "%d", count_semena_player);
			PlayerTextDrawSetString(playerid, general_green_house[27][playerid], fmt_str);
			PlayerTextDrawShow(playerid, general_green_house[27][playerid]);
		}
		case 4:
		{
			new 
				count_semena_player;

			count_semena_player = get_inventory_items(playerid, 352);

			format(fmt_str, sizeof(fmt_str), "%d", count_semena_player);
			PlayerTextDrawSetString(playerid, general_green_house[27][playerid], fmt_str);
			PlayerTextDrawShow(playerid, general_green_house[27][playerid]);
		}
		case 5:
		{
			new 
				count_semena_player;

			count_semena_player = get_inventory_items(playerid, 353);

			format(fmt_str, sizeof(fmt_str), "%d", count_semena_player);
			PlayerTextDrawSetString(playerid, general_green_house[27][playerid], fmt_str);
			PlayerTextDrawShow(playerid, general_green_house[27][playerid]);
		}
		case 6:
		{
			new 
				count_semena_player;

			count_semena_player = get_inventory_items(playerid, 354);

			format(fmt_str, sizeof(fmt_str), "%d", count_semena_player);
			PlayerTextDrawSetString(playerid, general_green_house[27][playerid], fmt_str);
			PlayerTextDrawShow(playerid, general_green_house[27][playerid]);
		}
		case 7:
		{
			new 
				count_semena_player;

			count_semena_player = get_inventory_items(playerid, 355);

			format(fmt_str, sizeof(fmt_str), "%d", count_semena_player);
			PlayerTextDrawSetString(playerid, general_green_house[27][playerid], fmt_str);
			PlayerTextDrawShow(playerid, general_green_house[27][playerid]);
		}
		case 8:
		{
			new 
				count_semena_player;

			count_semena_player = get_inventory_items(playerid, 356);

			format(fmt_str, sizeof(fmt_str), "%d", count_semena_player);
			PlayerTextDrawSetString(playerid, general_green_house[27][playerid], fmt_str);
			PlayerTextDrawShow(playerid, general_green_house[27][playerid]);			
		}
	}

	return true;
}

stock show_player_green_house_p(playerid, status, type = 1)
{
	switch(status)
	{
		case TEXTDRAW_SHOW:
		{
			SetPVarIntNew(playerid, "select_type_semena", type);
			SetPVarIntNew(playerid, "green_house_panel_open", TEXTDRAW_SHOW);

			timer_rice_temp_plant[playerid] = SetTimerEx("timer_rice_plant_temp", 15000, 1, "i", playerid);
			timer_rice_plant_temp(playerid);

			switch(type)
			{
				case 1:
				{
					show_player_green_house_st(playerid, TEXTDRAW_HIDE);
					show_player_green_house_st(playerid, TEXTDRAW_SHOW);					

					PlayerTextDrawSetString(playerid, general_green_house[0][playerid], "brilliantother:teplica_info_gen_5");
					PlayerTextDrawShow(playerid, general_green_house[0][playerid]);

					PlayerTextDrawShow(playerid, general_green_house[1][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[2][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[3][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[4][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[5][playerid]);

					PlayerTextDrawShow(playerid, general_green_house[20][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[21][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[22][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[23][playerid]);

					PlayerTextDrawShow(playerid, general_green_house[26][playerid]);

					PlayerTextDrawSetString(playerid, general_green_house[12][playerid], "brilliantother:teplica_info_icon_5_o");
					PlayerTextDrawShow(playerid, general_green_house[12][playerid]);

				}
				case 2:
				{
					show_player_green_house_st(playerid, TEXTDRAW_HIDE);
					show_player_green_house_st(playerid, TEXTDRAW_SHOW);

					PlayerTextDrawSetString(playerid, general_green_house[0][playerid], "brilliantother:teplica_info_gen_7");
					PlayerTextDrawShow(playerid, general_green_house[0][playerid]);

					PlayerTextDrawShow(playerid, general_green_house[1][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[2][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[3][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[4][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[5][playerid]);

					PlayerTextDrawShow(playerid, general_green_house[20][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[21][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[22][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[23][playerid]);

					PlayerTextDrawShow(playerid, general_green_house[26][playerid]);

					PlayerTextDrawSetString(playerid, general_green_house[13][playerid], "brilliantother:teplica_info_icon_7_o");
					PlayerTextDrawShow(playerid, general_green_house[13][playerid]);
				}
				case 3:
				{
					show_player_green_house_st(playerid, TEXTDRAW_HIDE);
					show_player_green_house_st(playerid, TEXTDRAW_SHOW);

					PlayerTextDrawSetString(playerid, general_green_house[0][playerid], "brilliantother:teplica_info_gen_8");
					PlayerTextDrawShow(playerid, general_green_house[0][playerid]);

					PlayerTextDrawShow(playerid, general_green_house[1][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[2][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[3][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[4][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[5][playerid]);

					PlayerTextDrawShow(playerid, general_green_house[20][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[21][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[22][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[23][playerid]);

					PlayerTextDrawShow(playerid, general_green_house[26][playerid]);

					PlayerTextDrawSetString(playerid, general_green_house[14][playerid], "brilliantother:teplica_info_icon_8_o");
					PlayerTextDrawShow(playerid, general_green_house[14][playerid]);
				}
				case 4:
				{
					show_player_green_house_st(playerid, TEXTDRAW_HIDE);
					show_player_green_house_st(playerid, TEXTDRAW_SHOW);

					PlayerTextDrawSetString(playerid, general_green_house[0][playerid], "brilliantother:teplica_info_gen_1");
					PlayerTextDrawShow(playerid, general_green_house[0][playerid]);

					PlayerTextDrawShow(playerid, general_green_house[1][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[2][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[3][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[4][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[5][playerid]);

					PlayerTextDrawShow(playerid, general_green_house[20][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[21][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[22][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[23][playerid]);

					PlayerTextDrawShow(playerid, general_green_house[26][playerid]);

					PlayerTextDrawSetString(playerid, general_green_house[15][playerid], "brilliantother:teplica_info_icon_1_o");
					PlayerTextDrawShow(playerid, general_green_house[15][playerid]);
				}
				case 5:
				{
					show_player_green_house_st(playerid, TEXTDRAW_HIDE);
					show_player_green_house_st(playerid, TEXTDRAW_SHOW);

					PlayerTextDrawSetString(playerid, general_green_house[0][playerid], "brilliantother:teplica_info_gen_3");
					PlayerTextDrawShow(playerid, general_green_house[0][playerid]);

					PlayerTextDrawShow(playerid, general_green_house[1][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[2][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[3][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[4][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[5][playerid]);

					PlayerTextDrawShow(playerid, general_green_house[20][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[21][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[22][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[23][playerid]);

					PlayerTextDrawShow(playerid, general_green_house[26][playerid]);

					PlayerTextDrawSetString(playerid, general_green_house[16][playerid], "brilliantother:teplica_info_icon_3_o");
					PlayerTextDrawShow(playerid, general_green_house[16][playerid]);
				}
				case 6:
				{
					show_player_green_house_st(playerid, TEXTDRAW_HIDE);
					show_player_green_house_st(playerid, TEXTDRAW_SHOW);

					PlayerTextDrawSetString(playerid, general_green_house[0][playerid], "brilliantother:teplica_info_gen_2");
					PlayerTextDrawShow(playerid, general_green_house[0][playerid]);

					PlayerTextDrawShow(playerid, general_green_house[1][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[2][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[3][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[4][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[5][playerid]);

					PlayerTextDrawShow(playerid, general_green_house[20][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[21][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[22][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[23][playerid]);

					PlayerTextDrawShow(playerid, general_green_house[26][playerid]);

					PlayerTextDrawSetString(playerid, general_green_house[17][playerid], "brilliantother:teplica_info_icon_2_o");
					PlayerTextDrawShow(playerid, general_green_house[17][playerid]);
				}
				case 7:
				{
					show_player_green_house_st(playerid, TEXTDRAW_HIDE);
					show_player_green_house_st(playerid, TEXTDRAW_SHOW);

					PlayerTextDrawSetString(playerid, general_green_house[0][playerid], "brilliantother:teplica_info_gen_4");
					PlayerTextDrawShow(playerid, general_green_house[0][playerid]);

					PlayerTextDrawShow(playerid, general_green_house[1][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[2][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[3][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[4][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[5][playerid]);

					PlayerTextDrawShow(playerid, general_green_house[20][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[21][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[22][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[23][playerid]);

					PlayerTextDrawShow(playerid, general_green_house[26][playerid]);

					PlayerTextDrawSetString(playerid, general_green_house[18][playerid], "brilliantother:teplica_info_icon_4_o");
					PlayerTextDrawShow(playerid, general_green_house[18][playerid]);
				}
				case 8:
				{
					show_player_green_house_st(playerid, TEXTDRAW_HIDE);
					show_player_green_house_st(playerid, TEXTDRAW_SHOW);

					PlayerTextDrawSetString(playerid, general_green_house[0][playerid], "brilliantother:teplica_info_gen_6");
					PlayerTextDrawShow(playerid, general_green_house[0][playerid]);

					PlayerTextDrawShow(playerid, general_green_house[1][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[2][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[3][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[4][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[5][playerid]);

					PlayerTextDrawShow(playerid, general_green_house[20][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[21][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[22][playerid]);
					PlayerTextDrawShow(playerid, general_green_house[23][playerid]);

					PlayerTextDrawShow(playerid, general_green_house[26][playerid]);

					PlayerTextDrawSetString(playerid, general_green_house[19][playerid], "brilliantother:teplica_info_icon_6_o");
					PlayerTextDrawShow(playerid, general_green_house[19][playerid]);
				}
			}
			SelectTextDraw(playerid, COLOR_BLUE);
			update_count_semena_panel(playerid, type);
			update_visual_green_rice(playerid, type);

			new 
				teplica_temp_update, fmt_str[32];

			teplica_temp_update = RandomEx(20,40);

			format(fmt_str, 32, "%d", teplica_temp_update);
			PlayerTextDrawSetString(playerid, general_green_house[25][playerid], fmt_str);
			PlayerTextDrawShow(playerid,general_green_house[25][playerid]);

		}
		case TEXTDRAW_HIDE:
		{
			PlayerTextDrawHideEx(playerid, general_green_house[0][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[1][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[2][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[3][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[4][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[5][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[6][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[7][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[8][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[9][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[10][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[11][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[12][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[13][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[14][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[15][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[16][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[17][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[18][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[19][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[20][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[21][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[22][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[23][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[24][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[25][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[26][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[27][playerid]);


			CancelSelectTextDraw(playerid);

			KillTimer(timer_rice_temp_plant[playerid]);

			DeletePVarNew(playerid, "green_house_panel_open");
			DeletePVarNew(playerid, "select_type_semena");
		}
	}
	return true;

}

stock show_player_green_house_st(playerid, status)
{
	switch(status)
	{
		case TEXTDRAW_SHOW:
		{
			create_player_green_house(playerid);

			if(pData[playerid][pGreenHouse] == 1)
			{
				PlayerTextDrawSetString(playerid, general_green_house[12][playerid], "brilliantother:teplica_info_icon_5");
				PlayerTextDrawShow(playerid, general_green_house[12][playerid]);
				PlayerTextDrawSetString(playerid, general_green_house[13][playerid], "brilliantother:teplica_info_icon_7");
				PlayerTextDrawShow(playerid, general_green_house[13][playerid]);
			}
			else if(pData[playerid][pGreenHouse] == 2)
			{
				PlayerTextDrawSetString(playerid, general_green_house[12][playerid], "brilliantother:teplica_info_icon_5");
				PlayerTextDrawShow(playerid, general_green_house[12][playerid]);
				PlayerTextDrawSetString(playerid, general_green_house[13][playerid], "brilliantother:teplica_info_icon_7");
				PlayerTextDrawShow(playerid, general_green_house[13][playerid]);

				PlayerTextDrawSetString(playerid, general_green_house[14][playerid], "brilliantother:teplica_info_icon_8");
				PlayerTextDrawShow(playerid, general_green_house[14][playerid]);
				PlayerTextDrawSetString(playerid, general_green_house[15][playerid], "brilliantother:teplica_info_icon_1");
				PlayerTextDrawShow(playerid, general_green_house[15][playerid]);
				PlayerTextDrawSetString(playerid, general_green_house[16][playerid], "brilliantother:teplica_info_icon_3");
				PlayerTextDrawShow(playerid, general_green_house[16][playerid]);

			}
			else if(pData[playerid][pGreenHouse] == 3)
			{
				PlayerTextDrawSetString(playerid, general_green_house[12][playerid], "brilliantother:teplica_info_icon_5");
				PlayerTextDrawShow(playerid, general_green_house[12][playerid]);
				PlayerTextDrawSetString(playerid, general_green_house[13][playerid], "brilliantother:teplica_info_icon_7");
				PlayerTextDrawShow(playerid, general_green_house[13][playerid]);

				PlayerTextDrawSetString(playerid, general_green_house[14][playerid], "brilliantother:teplica_info_icon_8");
				PlayerTextDrawShow(playerid, general_green_house[14][playerid]);
				PlayerTextDrawSetString(playerid, general_green_house[15][playerid], "brilliantother:teplica_info_icon_1");
				PlayerTextDrawShow(playerid, general_green_house[15][playerid]);
				PlayerTextDrawSetString(playerid, general_green_house[16][playerid], "brilliantother:teplica_info_icon_3");
				PlayerTextDrawShow(playerid, general_green_house[16][playerid]);

				PlayerTextDrawSetString(playerid, general_green_house[17][playerid], "brilliantother:teplica_info_icon_2");
				PlayerTextDrawShow(playerid, general_green_house[17][playerid]);
				PlayerTextDrawSetString(playerid, general_green_house[18][playerid], "brilliantother:teplica_info_icon_4");
				PlayerTextDrawShow(playerid, general_green_house[18][playerid]);
				PlayerTextDrawSetString(playerid, general_green_house[19][playerid], "brilliantother:teplica_info_icon_6");
				PlayerTextDrawShow(playerid, general_green_house[19][playerid]);
			}

			PlayerTextDrawShow(playerid, general_green_house[22][playerid]);
			PlayerTextDrawShow(playerid, general_green_house[26][playerid]);

			SelectTextDraw(playerid, COLOR_BLUE);
		}
		case TEXTDRAW_HIDE:
		{
			PlayerTextDrawHideEx(playerid, general_green_house[0][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[1][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[2][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[3][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[4][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[5][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[6][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[7][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[8][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[9][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[10][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[11][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[12][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[13][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[14][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[15][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[16][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[17][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[18][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[19][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[20][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[21][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[22][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[23][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[24][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[25][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[26][playerid]);
			PlayerTextDrawHideEx(playerid, general_green_house[27][playerid]);

			CancelSelectTextDraw(playerid);

		}
	}


	return true;
}

stock generate_price_green_house()
{
	// Динамическая генерация цен на семена в теплицах

	green_house_price_semena[0] = RandomEx(1, 3);
	green_house_price_semena[1] = RandomEx(1, 3);
	green_house_price_semena[2] = RandomEx(3, 5);
	green_house_price_semena[3] = RandomEx(3, 5);
	green_house_price_semena[4] = RandomEx(3, 5);
	green_house_price_semena[5] = RandomEx(3, 5);
	green_house_price_semena[6] = RandomEx(3, 5);
	green_house_price_semena[7] = RandomEx(5, 10);

	// Динамическая генерация цен на готовую продукцию в теплицах

	green_house_price_prod[0] = floatround(RandomEx(340, 390)*1.5);
	green_house_price_prod[1] = floatround(RandomEx(340, 390)*1.5);
	green_house_price_prod[2] = floatround(RandomEx(340, 390)*1.5);
	green_house_price_prod[3] = floatround(RandomEx(445, 535)*1.5);
	green_house_price_prod[4] = floatround(RandomEx(445, 535)*1.5);
	green_house_price_prod[5] = floatround(RandomEx(500, 855)*1.5);
	green_house_price_prod[6] = floatround(RandomEx(505, 855)*1.5);
	green_house_price_prod[7] = floatround(RandomEx(505, 855)*1.5);

	return true;
}