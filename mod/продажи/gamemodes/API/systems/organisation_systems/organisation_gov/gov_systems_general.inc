static const Float:position_spawn_car_gov[][] =
{
	{-54.1287,819.1041,11.2305,160.0088},
	{-57.6460,820.1533,11.2305,159.0526},
	{-60.6075,821.2206,11.2305,159.4042},
	{-63.9841,822.4157,11.2305,161.1502},
	{-66.8837,823.9008,11.2305,159.3325},
	{-70.2556,824.5840,11.2305,159.6127},
	{-96.7937,834.9299,11.2305,159.1928},
	{-100.0909,835.9729,11.2305,160.2152},
	{-103.3427,837.5428,11.2305,158.6640},
	{-106.4653,838.6835,11.2305,159.6997},
	{-109.5649,839.5329,11.2305,159.2064},
	{-112.7514,840.7891,11.2305,158.9718}

};


new gov_vehicle_model[] =
{
	507, 561
};


stock create_gov_other_element()
{

	pickup_spawn_car_gov[0] = create_circle_pickup(-93.1005,836.6360,12.0030, TRIGGER_LRED);
	pickup_spawn_car_gov[1] = create_circle_pickup(-72.2483,828.8929,12.0030, TRIGGER_LRED);


	CreateDynamic3DTextLabel(""cWH"Автопарк Правительства\n\
		"cLRED"[Встаньте на пикап]", CWHITE, -93.1005,836.6360,12.0030, 5.0,INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
	CreateDynamic3DTextLabel(""cWH"Автопарк Правительства\n\
		"cLRED"[Встаньте на пикап]", CWHITE, -72.2483,828.8929,12.0030, 5.0,INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);



	return true;
}


stock spawn_gov_vehicle(playerid)
{
	format(String512, sizeof(String512), "\
    "cGREY"Автомобиль\t"cGREY"Действие\n\
    "cBLUE"1. "cWH"%s\t"cGR"Взять\n\
    "cBLUE"2. "cWH"%s\t"cGR"Взять\n\
    \t\n\
    "cWH"Доступно всего: \t"cBLUE"%d"cWH" автомобилей", 
    transport_config[gov_vehicle_model[0]-400][transport_name],
    transport_config[gov_vehicle_model[1]-400][transport_name],
    count_gov_vehicle
    );
 	SPD(playerid, DIALOG_SELECT_CAR_GOV, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Выбор автомобиля", String512, !"Выбрать", !"Закрыть"); 

 	return true;
}

stock spawn_gov_veh_start(playerid, type_car)
{
	switch(type_car)
	{
		case 0:
		{
			if(count_gov_vehicle == 0)
			{
				spawn_gov_vehicle(playerid);
				return SendErr(playerid, "Недостаточно госсударственных автомобилей!");
			}

			if(pData[playerid][pFraction] != 11)	
			{
				SendErr(playerid, "Доступно только правительству!");
				return true;
			}	

			create_vehicle_gov(playerid, 0);
		}
		case 1:
		{
			if(count_gov_vehicle == 0)
			{
				spawn_gov_vehicle(playerid);
				return SendErr(playerid, "Недостаточно госсударственных автомобилей!");
			}

			if(pData[playerid][pFraction] != 11)	
			{
				SendErr(playerid, "Доступно только правительству!");
				return true;
			}	

			create_vehicle_gov(playerid, 1);
		}
		case 2:
		{
			if(count_gov_vehicle == 0)
			{
				spawn_gov_vehicle(playerid);
				return SendErr(playerid, "Недостаточно госсударственных автомобилей!");
			}

			if(pData[playerid][pFraction] != 11)	
			{
				SendErr(playerid, "Доступно только правительству!");
				return true;
			}	

			create_vehicle_gov(playerid, 2);
		}
		case 3:
		{
			if(count_gov_vehicle == 0)
			{
				spawn_gov_vehicle(playerid);
				return SendErr(playerid, "Недостаточно госсударственных автомобилей!");
			}

			if(pData[playerid][pFraction] != 11)	
			{
				SendErr(playerid, "Доступно только правительству!");
				return true;
			}	

			create_vehicle_gov(playerid, 3);
		}
	}

	return true;
}

stock create_vehicle_gov(playerid, veh_type)
{
	new 
		random_pos = random(12);

	new 
		c1 = 1,
		c2 = 1;	

	new 
		vehicle_gov = CreateVehicle(gov_vehicle_model[veh_type], position_spawn_car_gov[random_pos][0], position_spawn_car_gov[random_pos][1], position_spawn_car_gov[random_pos][2], position_spawn_car_gov[random_pos][3], c1, c2, 600);	

	format(vehicle[vehicle_gov][cPlate], 20, "Мэрия");
	SetVehicleNumberPlate(vehicle_gov, vehicle[vehicle_gov][cPlate]);

	format(vehicle[vehicle_gov][cPlate], 20, "а0%daa", count_gov_vehicle);
	SetVehicleGosNumberPlate(vehicle_gov, vehicle[vehicle_gov][cPlate], "77");

	PutPlayerInVehicleEx(playerid, vehicle_gov, 0);

	vehicle[vehicle_gov][cFuel] = transport_config[GetVehicleModel(vehicle_gov)-400][transport_tank];
	vehicle[vehicle_gov][cHealth] = 1000.0;
	vehicle[vehicle_gov][cIsCreated] = true;
	vehicle[vehicle_gov][consumables_oil] = 1000.0;

	vehicle[vehicle_gov][cOwnTo] = VEHICLE_GOV;

	vehicle[vehicle_gov][cLock] = 2;

	vehicle_lock_status(vehicle_gov, true);

	count_gov_vehicle--;

	return true;
}

stock dialog_all_gov(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
	    case DIALOG_SELECT_CAR_GOV: 
	    {
	    	if(!response)
	    		return true;
	    	
	    	switch(listitem)
	    	{
		    	case 0: return spawn_gov_veh_start(playerid, 0);
		    	case 1: return spawn_gov_veh_start(playerid, 1);
		    	case 2: return spawn_gov_vehicle(playerid);
		    	case 3: return spawn_gov_vehicle(playerid);
		    }
	    }
	}



	return true;
}




stock load_charity_pickup()
{
	charity_pickup = create_circle_pickup(689.0124,-13.5208,1201.8580, TRIGGER_LRED);

	CreateDynamic3DTextLabel(""cWH"Благотворительность\n"cLRED"[Встаньте на пикап]",-1, \
	689.0124,-13.5208,1201.8580, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID);

	return true;
}

callback:: load_charity_information()
{
	new Result:charity_load = sql_queryEx(zConn, "SELECT * FROM `charity` ORDER BY `charity_amount` DESC LIMIT 10", QUERY_CACHED);

	all_charity = sql_num_rows(charity_load);

	new time = GetTickCount();

	new 
		load_charity; 

	for(new i; i < all_charity; i++)
	{
		charity_userid[i] = sql_get_field_assoc_int_ex(charity_load, i, "userid"); 

		charity_amount[i] = sql_get_field_assoc_int_ex(charity_load, i, "charity_amount"); 

		load_charity++;
	}

	printf("[Пожертвования]: <%i из %i>. Времени затрачено: <%d мс>" , all_charity, load_charity, GetTickCount()-  time);

	sql_free_result(charity_load);
	return true;
}


stock dialog_charity(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
		case DIALOG_SELECT_CHARITY:
		{
			if(!response)
				return true;

			switch(listitem)
			{
				case 0: return charity_top(playerid);
				case 1: return charity_input(playerid);
				case 2: return charity_info(playerid);
			}
		}
		case DIALOG_CHARITY_INPUT:
		{
			if(!response)
				return charity_menu(playerid);

			if(!strlen(inputtext) || !IsNumeric(inputtext))
			{
		   		charity_input(playerid);
		   		SendErr(playerid, "Неверное значение");
		   		return true;     
		   	}
				
			if(strval(inputtext) < MIN_CHARITY_MONEY || strval(inputtext) > MAX_CHARITY_MONEY)
		    {
		   		charity_input(playerid);
		   		SendErr(playerid, "Вы ввели недопустимое значение");
		   		return true;     
		   	}

		   	if(strval(inputtext) < 0)
		   	{
		   		charity_input(playerid);
		   		SendErr(playerid, "Вы ввели недопустимое значение");
		   		return true; 		   		
		   	}

		   	if(GetPlayerMoneyEx(playerid) < strval(inputtext))
		   	{
		   		charity_input(playerid);
		   		return SendErr(playerid, "Недостаточно денежных средств!");
		   	}

		   	new 
		   		string[144];

		   	if(strval(inputtext) >= 1000000)
		   	{
		   		format(string, sizeof(string), "[Пожертвование] %s[%d] пожертвовал области %d рублей!", pData[playerid][pNickname], playerid, strval(inputtext));
		   		SendClientMessageToAll(COLOR_YELLOW, string);
		   	}

		   	new 
		   		count_money = strval(inputtext);

		   	give_money(playerid, -count_money, "Пожертвование");

		   	format(string, sizeof(string), "Вы пожертвовали области "cGR"%d рублей", strval(inputtext));
		   	SendSucc(playerid, string);

		   	update_player_charity(playerid, strval(inputtext));
		   	load_charity_information();
			return true;
		}
	}
	return true;
}

stock update_player_charity(playerid, money)
{
	new 
		query[250];

	format(query, sizeof(query), "SELECT * FROM `charity` WHERE `userid` = '%d'", pData[playerid][pMysqlID]);
	new Result:r = sql_queryEx(zConn, query, QUERY_CACHED);
	if(!sql_num_rows(r))
	{
		format(query,sizeof(query),"INSERT INTO `charity` (userid, charity_amount) VALUES ('%d','%d')", pData[playerid][pMysqlID], money);
		sql_queryEx(zConn, query);
	}
	else
	{
		format(query,sizeof(query),"UPDATE `charity` SET `charity_amount` = `charity_amount` + %d WHERE `userid` = '%d'", money, pData[playerid][pMysqlID]);
		sql_queryEx(zConn, query);
	}
	sql_free_result(r);
	return true;
}

stock charity_menu(playerid)
{
	return SPD(playerid, DIALOG_SELECT_CHARITY, DIALOG_STYLE_LIST, !""cBLUE"Благотворительность", !"\
		"cBLUE"- "cWH"ТОП 10 благотворителей области\n\
		"cBLUE"- "cWH"Пожертвовать деньги области\n\
		"cBLUE"- "cWH"Бонусы для ТОП благотворителей", !"Далее", !"Закрыть");
}

stock charity_top(playerid)
{
	if(!all_charity)
	{
		SendErr(playerid, "Список благотворителей пуст");
		return charity_menu(playerid);
	}

	new 
		nickname[MAX_PLAYER_NAME],
		string[1024];

	strcat(string, ""cGREY"№. Никнейм\t"cGREY"Сумма\n");

	for(new i; i < all_charity; i++)
	{
		GetPlayerNameByID(charity_userid[i],nickname);
		format(string, sizeof(string), "%s"cBLUE"%d. "cWH"%s\t"cGR"%d рублей\n", string, i+1, nickname, charity_amount[i]);
	}
	new 
		money,
		query[144];

	format(query, sizeof(query), "SELECT * FROM `charity` WHERE `userid` = '%d'", pData[playerid][pMysqlID]);
	new Result:r = sql_queryEx(zConn, query, QUERY_CACHED);

	if(!sql_num_rows(r))
	{
		money = 0;
	}
	else
	{
		money = sql_get_field_assoc_int(r, "charity_amount");
	}

	format(string, sizeof(string), "%s\n"cBLUE"Вы пожертвовали: "cWH"%d рублей", string, money);

	SPD(playerid, 0, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"ТОП 10 благотворителей", string, !"Закрыть", "");

	sql_free_result(r);
	return true;
}

stock charity_input(playerid)
{
	format(String512, sizeof(String512), "\n\
		"cWH"Введите сумму, которую хотите пожертвовать области.\n\
		"cWH"Вы можете внести за раз:\n\
		"cWH"от "cGR"%d рублей "cWH"и до "cGR"%d рублей\n\n\
		"cBLUE"Примечание: "cWH"при пожертвовании более "cGR"1000000 рублей\n\
		"cWH"об этом напишет всему серверу!", MIN_CHARITY_MONEY, MAX_CHARITY_MONEY);

	SPD(playerid, DIALOG_CHARITY_INPUT, DIALOG_STYLE_INPUT, !""cBLUE"Благотворительность", String512, !"Далее", !"Назад");
	return true;
}

stock charity_info(playerid)
{	
	return SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Бонусы благотворителям", !"\n\
		"cWH"Каждая область нуждается в финансовых вливаниях со стороны и мы не исключение!\n\n\
		У Вас есть уникальная возможность стать главным меценатом области!\n\
		Пока наша область лишь набирает обороты, но в будущем Вы сможете получать привелегии!\n\n\
		Чем больше пожертования - тем больше Ваш рейтинг! Покажите Всем, кто тут богач!", !"Закрыть", "");
}
