
#define NEY_YEAR_SNOW_PRICE	10

stock give_random_prize(playerid)
{
	new
		rand = random(1001);

	switch(rand)
	{
		case 0..300:
		{
			return give_prize_exp(playerid);
		}
		/*case 300:
		{
			return give_prize_sim_newyear(playerid);	
		}*/
		case 301..600:
		{
			return give_prize_donate(playerid);
		}
		case 601..689:
		{
			return give_prize_acs(playerid);
		}
		case 690..700:
		{
			return give_prize_car(playerid);
		}
		case 1000:
		{
			return give_prize_snowmobile(playerid);
		}
		default:
		{
			return give_prize_money(playerid);
		}
	}
	return true;
}

stock give_prize_car(playerid)
{
	new
		vehicle;

	switch(random(7))
	{
		case 0:vehicle = 420;
		case 1:vehicle = 438;
		case 2:vehicle = 467;
		case 3:vehicle = 474;
		case 4:vehicle = 475;
		case 5:vehicle = 517;
		case 6:vehicle = 526;
		case 7:vehicle = 589;
	}

	new 
		fmt_str[200];
	format(fmt_str, sizeof(fmt_str), "SELECT * FROM player_vehicles WHERE userid = '%d' LIMIT 1", pData[playerid][pMysqlID]);
	new Result:carfind = sql_queryEx(zConn, fmt_str, QUERY_CACHED);// zConn

	if(sql_num_rows(carfind))
	{
		SetPVarIntNew(playerid, "win_new_year_car", vehicle);


		new
			sellprice = transport_config[GetPVarIntNew(playerid, "win_new_year_car")-400][transport_price],
			string_mes[512];

		format(string_mes, sizeof(string_mes), "\n\
			"cWH"Вы потратили "cBLUE"%d снежинок "cWH"и получили:\n\t\
			- Автомобиль "cBLUE"'%s'"cWH"!\n\n\
			"cWH"У Вас уже имеется транспорт!\n\
			"cWH"Вы можете заменить его, либо продать '%s' государству.\n\
			"cWH"Стоимость продажи транспорта государству: "cBLUE"%d рублей", NEY_YEAR_SNOW_PRICE, transport_config[GetPVarIntNew(playerid, "win_new_year_car")-400][transport_name], transport_config[GetPVarIntNew(playerid, "win_new_year_car")-400][transport_name], sellprice);


		SPD(playerid, DIALOG_SELECT_PRIZE_CAR, 0, !""cBLUE"Новогодний подарок", string_mes, !"Заменить", !"Продать");
	}
	else
	{
		new
			string_mes[512];

		format(string_mes, sizeof(string_mes), "\n\
			"cWH"Вы потратили "cBLUE"%d снежинок "cWH"и получили:\n\t\
			- Автомобиль "cBLUE"'%s'"cWH"!\n\n\
			"cWH"Чтобы получить транспорт, используйте команду /unpark", NEY_YEAR_SNOW_PRICE, transport_config[GetPVarIntNew(playerid, "win_new_year_car")-400][transport_name]);


		SPD(playerid, 0, 0, !""cBLUE"Новогодний подарок", string_mes, !"Отлично", "");

		new 
			color_car = random(255);

		format(String1024,sizeof(String1024),"INSERT INTO `player_vehicles`(`userid`,`model`,`color_1`,`color_2`, `parking_x`,`parking_y`,`parking_z`,`parking_a`, `parking_vw`, `parking_garage`) VALUES ('%d','%d','%d','%d','%f','%f','%f','%f', '%d', '%d')", pData[playerid][pMysqlID], vehicle,
		color_car, color_car, 937.5283,1002.4365,11.9524,283.6047, 0, 0);
		sql_queryEx(zConn, String1024, QUERY_THREADED);// zConn
	}

	format(String144, sizeof(String144), "Выиграл из подарка автомобиль %d номер!", vehicle);
	logs_prize_newyear_player(playerid, pData[playerid][pMysqlID], String144);

	return true;
}

stock give_prize_acs(playerid)
{
	new 
		win_acs,
		rand = random(5),
		string_mes[512];

	switch(rand)
	{
		case 0: win_acs = 18156;
		case 1: win_acs = 18157;
		case 2: win_acs = 18158;
		case 3: win_acs = 18159;
		case 4: win_acs = 18160;
	}

	if((win_acs == 18156 || win_acs == 18157 && pData[playerid][pSlotItem][0] != -1) || (win_acs == 18158 || win_acs == 18159 || win_acs == 18160 && pData[playerid][pSlotItem][2] != -1))
	{
		SetPVarIntNew(playerid, "new_year_win_acs", win_acs);

		format(string_mes, sizeof(string_mes), "\n\
			"cWH"Вы потратили "cBLUE"%d снежинок "cWH"и получили:\n\t\
			- Уникальный аксессуар %s!\n\n\
			"cWH"У Вас уже имеется активный аксессуар данного типа!\n\
			"cWH"Вы можете заменить его, либо продать за "cGR"50000 рублей", NEY_YEAR_SNOW_PRICE, get_acs_name(win_acs));


		SPD(playerid, DIALOG_SELECT_PRIZE_ACS, 0, !""cBLUE"Новогодний подарок", string_mes, !"Заменить", !"Продать");
		return true;
	}

	switch(win_acs)
	{
		case 18156..18157: 
		{
			pData[playerid][pSlotItem][0] = win_acs;
		}
		case 18158..18160:	
		{
			pData[playerid][pSlotItem][2] = win_acs;
		}
	}
	AttachAcsToPlayer(playerid, GetPlayerSkin(playerid));

	format(string_mes, sizeof(string_mes), "\n\
		"cWH"Вы потратили "cBLUE"%d снежинок "cWH"и получили:\n\t\
		- Уникальный аксессуар %s!\n\n\
		"cWH"Счастливого "cLRED"Нового Года!", NEY_YEAR_SNOW_PRICE, get_acs_name(win_acs));
	SPD(playerid, 0, 0, !""cBLUE"Новогодний подарок", string_mes, !"Принять", "");

	format(String144, sizeof(String144), "Выиграл из подарка аксессуар %d номер!", win_acs);
	logs_prize_newyear_player(playerid, pData[playerid][pMysqlID], String144);

	return true;
}

stock give_prize_snowmobile(playerid)
{
	new 
		fmt_str[200];
	format(fmt_str, sizeof(fmt_str), "SELECT * FROM player_vehicles WHERE userid = '%d' LIMIT 1", pData[playerid][pMysqlID]);
	new Result:carfind = sql_queryEx(zConn, fmt_str, QUERY_CACHED);// zConn

	if(sql_num_rows(carfind))
	{
		SetPVarIntNew(playerid, "win_new_year_car", 471);

		new
			sellprice = transport_config[GetPVarIntNew(playerid, "win_new_year_car")-400][transport_price],
			string_mes[512];

		format(string_mes, sizeof(string_mes), "\n\
			"cWH"Вы потратили "cBLUE"%d снежинок "cWH"и получили:\n\t\
			- Уникальный транспорт "cBLUE"'Снегоход'"cWH"!\n\n\
			"cWH"У Вас уже имеется транспорт!\n\
			"cWH"Вы можете заменить его, либо продать 'Снегоход' государству.\n\
			"cWH"Стоимость продажи Снегохода государству: "cBLUE"%d рублей", NEY_YEAR_SNOW_PRICE, sellprice);


		SPD(playerid, DIALOG_SELECT_PRIZE_CAR, 0, !""cBLUE"Новогодний подарок", string_mes, !"Заменить", !"Продать");
	}
	else
	{
		new
			string_mes[512];

		format(string_mes, sizeof(string_mes), "\n\
			"cWH"Вы потратили "cBLUE"%d снежинок "cWH"и получили:\n\t\
			- Уникальный транспорт "cBLUE"'Снегоход'"cWH"!\n\n\
			"cWH"Чтобы получить транспорт, используйте команду /unpark", NEY_YEAR_SNOW_PRICE);


		SPD(playerid, 0, 0, !""cBLUE"Новогодний подарок", string_mes, !"Отлично", "");

		new 
			color_car = random(255);

		format(String1024,sizeof(String1024),"INSERT INTO `player_vehicles`(`userid`,`model`,`color_1`,`color_2`, `parking_x`,`parking_y`,`parking_z`,`parking_a`, `parking_vw`, `parking_garage`) VALUES ('%d','%d','%d','%d','%f','%f','%f','%f', '%d', '%d')", pData[playerid][pMysqlID], 471,
		color_car, color_car, 937.5283,1002.4365,11.9524,283.6047, 0, 0);
		sql_queryEx(zConn, String1024, QUERY_THREADED);// zConn
	}

	SendClientMessageToAll(COLOR_YELLOW, "Свершилось новогоднее чудо!");

	new
		string128[128];

	format(string128, sizeof(string128), "%s[%i] получил подарок под ёлку в виде уникального транспорта 'Снегоход'!", pData[playerid][pNickname], playerid);
	SendClientMessageToAll(COLOR_YELLOW, string128);

	format(String144, sizeof(String144), "Выиграл из подарка Снегоход");
	logs_prize_newyear_player(playerid, pData[playerid][pMysqlID], String144);

	return true;
}

stock give_prize_sim_newyear(playerid)
{
	if(new_year_sim != 0)
		return give_random_prize(playerid);

	new_year_sim = 1;

	sql_queryEx(zConn, "UPDATE `serverdata` SET `new_year_sim` = '1'", QUERY_CACHED);

	pData[playerid][pPhone] = 2021;
	UpdatePlayerData(playerid, "phone", pData[playerid][pPhone]);

	new
		string_mes[512];

	format(string_mes, sizeof(string_mes), "\n\
		"cWH"Вы потратили "cBLUE"%d снежинок "cWH"и получили:\n\t\
		- Уникальный телефонный номер "cBLUE"'2021'"cWH"!\n\n\
		"cWH"Данный номер является единственным на сервере!", NEY_YEAR_SNOW_PRICE);


	SPD(playerid, 0, 0, !""cBLUE"Новогодний подарок", string_mes, !"Отлично", "");

	SendClientMessageToAll(COLOR_YELLOW, "Свершилось новогоднее чудо!");

	new
		string128[128];

	format(string128, sizeof(string128), "%s[%i] получил подарок под ёлку в виде уникального телефонного номера '2021'!", pData[playerid][pNickname], playerid);
	SendClientMessageToAll(COLOR_YELLOW, string128);

	format(String144, sizeof(String144), "Выиграл из подарка Симкарту");
	logs_prize_newyear_player(playerid, pData[playerid][pMysqlID], String144);

	return true;
}

stock give_prize_money(playerid)
{
	new
		string_mes[256],
		money = RandomEx(70000,130000);
	
	give_money(playerid, money, "Новогодний подарок");

	format(string_mes, sizeof(string_mes), "\n\
		"cWH"Вы потратили "cBLUE"%d снежинок "cWH"и получили:\n\t\
		- Игровую валюту в размере %d рублей\n\n\
		"cWH"В следующий раз повезёт ещё больше!", NEY_YEAR_SNOW_PRICE, money);

	SPD(playerid, 0, 0, !""cBLUE"Новогодний подарок", string_mes, !"Отлично", "");
	return true;
}

stock give_prize_exp(playerid)
{
	new
		string_mes[256],
		exp = RandomEx(3,6);
	
	pData[playerid][pExp] += exp;
	UpdatePlayerData(playerid, "exp", pData[playerid][pExp]);
	if(pData[playerid][pExp] >= pData[playerid][pLevel]*6)
	{
		SendClientMessage(playerid, CGREEN, "Ваш игровой уровень и IC возраст повысился.");
	    pData[playerid][pExp] = pData[playerid][pExp] - (pData[playerid][pLevel]*6);
		pData[playerid][pLevel]++;
		pData[playerid][pAge]++;
		SetPlayerScore(playerid, pData[playerid][pLevel]);
		UpdatePlayerData(playerid, "exp", pData[playerid][pExp]);
		UpdatePlayerData(playerid, "level", pData[playerid][pLevel]);
		UpdatePlayerData(playerid, "age", pData[playerid][pAge]);
	}

	format(string_mes, sizeof(string_mes), "\n\
		"cWH"Вы потратили "cBLUE"%d снежинок "cWH"и получили:\n\t\
		- Игровой опыт в размере %d EXP\n\n\
		"cWH"В следующий раз повезёт ещё больше!", NEY_YEAR_SNOW_PRICE, exp);

	SPD(playerid, 0, 0, !""cBLUE"Новогодний подарок", string_mes, !"Отлично", "");

	format(String144, sizeof(String144), "Выиграл из подарка %d EXP", exp);
	logs_prize_newyear_player(playerid, pData[playerid][pMysqlID], String144);

	return true;
}

stock give_prize_donate(playerid)
{
	new
		string_mes[256],
		donate = RandomEx(50,120);
	
	pData[playerid][pDonate] += donate;
	UpdatePlayerData(playerid, "donate", pData[playerid][pDonate]);

	format(string_mes, sizeof(string_mes), "\n\
		"cWH"Вы потратили "cBLUE"%d снежинок "cWH"и получили:\n\t\
		- Донат в размере %d рублей\n\n\
		"cWH"В следующий раз повезёт ещё больше!", NEY_YEAR_SNOW_PRICE, donate);

	SPD(playerid, 0, 0, !""cBLUE"Новогодний подарок", string_mes, !"Отлично", "");

	format(String144, sizeof(String144), "Выиграл из подарка %d доната", donate);
	logs_prize_newyear_player(playerid, pData[playerid][pMysqlID], String144);

	return true;
}

stock dialog_new_year(playerid, dialogid, response)// OnDialogResponse
{
	switch(dialogid)
	{
		case DIALOG_OPEN_NEW_YEAR_PRIZE:
		{
			if(!response)
				return true;

			if(GetPlayerSnow(playerid) < NEY_YEAR_SNOW_PRICE)
			{
				SendErr(playerid, "У Вас недостаточно снежинок");
				return SendInf(playerid, "Вы можете получить снежинки за квесты, купить у игроков, либо же в донат меню");
			}

			pData[playerid][pCountSnow] -= 10;
			UpdatePlayerData(playerid, "pCountSnow", pData[playerid][pCountSnow]);

			return give_random_prize(playerid);
		}
		case DIALOG_SELECT_PRIZE_CAR:
		{
			if(!GetPVarIntNew(playerid, "win_new_year_car"))
				return SendErr(playerid, "Произошла неизвестная ошибка (#2412)");
			if(!response)
			{
				new 
					sellprice = transport_config[GetPVarIntNew(playerid, "win_new_year_car")-400][transport_price];

				give_money(playerid, sellprice, "Продажа новогоднего транспорта государству");

				new 
					string[128];

				format(string, sizeof(string), "Вы продали транспорт государству за "cGR"%d рублей", sellprice);
				SendSucc(playerid, string);
				DeletePVarNew(playerid, "win_new_year_car");
				return true;
			}
			new query[350];
			format(query,sizeof(query),"UPDATE `player_vehicles` SET `model` = '%d', `mileage` = '0.0' WHERE `userid` = '%d'", GetPVarIntNew(playerid, "win_new_year_car"), pData[playerid][pMysqlID]);
			sql_queryEx(zConn, query, QUERY_THREADED);// zConn

			SPD(playerid, 0, 0, !""cBLUE"Новогодний транспорт", "\n\
				"cWH"Вы успешно заменили старый транспорт на новогодний!\n\
				"cWH"Счастливого "cLRED"Нового Года!", !"Понятно", "");

			DeletePVarNew(playerid, "win_new_year_car");
			return true;
		}
		case DIALOG_SELECT_PRIZE_ACS:
		{
			if(!GetPVarIntNew(playerid, "new_year_win_acs"))
				return SendErr(playerid, "Произошла неизвестная ошибка (#2412)");
			if(!response)
			{
				give_money(playerid, 50000, "Продажа новогоднего аксессуара");

				SendSucc(playerid, "Вы обменяли новогодний аксессуар на "cGR"50000 рублей");
				DeletePVarNew(playerid, "new_year_win_acs");
				return true;
			}

			new 
				string_mes[256],
				win_acs = GetPVarIntNew(playerid, "new_year_win_acs");

			switch(win_acs)
			{
				case 18156..18157: 
				{
					pData[playerid][pSlotItem][0] = win_acs;
				}
				case 18158..18160:	
				{
					pData[playerid][pSlotItem][2] = win_acs;
				}
			}
			AttachAcsToPlayer(playerid, GetPlayerSkin(playerid));

			format(string_mes, sizeof(string_mes), "\n\
				"cWH"Вы успешно заменили старый аксессуар на новый\n\
				"cWH"Счастливого "cLRED"Нового Года!");
			SPD(playerid, 0, 0, !""cBLUE"Новогодний подарок", string_mes, !"Принять", "");
			return true;
		}
	}
	return true;
}

stock show_dialog_open_new_year_prize(playerid)
{
	new 
		string_mes[700];

	format(string_mes, sizeof(string_mes), "\n\
		"cWH"Вы действительно хотите открыть новогодний подарок?\n\t\
		"cWH"Стоимость открытия: "cBLUE"%d снежинок\n\t\
		"cWH"У вас: "cBLUE"%d снежинок\n\n\
		"cWH"С открытия подарка есть шанс получить:\n\t\
		"cBLUE"- "cWH"Игровую валюту\n\t\
		"cBLUE"- "cWH"Очки опыта\n\t\
		"cBLUE"- "cWH"Донат\n\t\
		{FF0033}- Новогодний аксессуар\n\t\
		{FF0022}- Автомобиль\n\t\
		{FF0011}- Уникальный транспорт 'Снегоход'\n\t\
		{FF0000}- Уникальный телефонный номер '2021'", NEY_YEAR_SNOW_PRICE, GetPlayerSnow(playerid));
	SPD(playerid, DIALOG_OPEN_NEW_YEAR_PRIZE, 0, !""cBLUE"Новогодняя ёлка", string_mes, !"Открыть", !"Отмена");
	return true;
}

stock get_acs_name(acs_id)
{
	new 
		string[32];

	switch(acs_id)
	{
		case 18156: string = "Шапка-ушанка";
		case 18157: string = "Шапка Деда Мороза";
		case 18158: string = "Маска 'Дед Мороз'";
		case 18159: string = "Маска 'Собака'";
		case 18160: string = "Маска 'Ёлка'";
	}
	return string;
}

stock GetPlayerSnow(playerid)
{
	return pData[playerid][pCountSnow];
}
//DIALOG_OPEN_NEW_YEAR_PRIZE
//DIALOG_SELECT_PRIZE_CAR