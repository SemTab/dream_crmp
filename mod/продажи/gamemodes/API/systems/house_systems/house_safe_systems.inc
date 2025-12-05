
#define POSITION_SAFE_INT_LOW		-2571.9600,393.9823,1.8041
#define POSITION_SAFE_INT_MEDIUM	1427.4348,-1892.7561,1117.8174
#define POSITION_SAFE_INT_HARD		5.1734,196.9668,1206.0798
#define POSITION_SAFE_INT_LUXE		-1134.7477,-1100.7867,1234.5591

#define POSITION_SAFE_INT_LUXE1		492.3643,2308.2539,1601.2031
#define POSITION_SAFE_INT_LUXE2		66.5759,446.5252,1201.9380

#define POSITION_SAFE_INT_POSELOK	160.0720,-263.1499,1201.9316


stock create_safe_position()
{
	CreateDynamic3DTextLabel(""cWH"Домашний Сейф",-1, \
  		POSITION_SAFE_INT_LOW, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	create_circle_pickup_o(POSITION_SAFE_INT_LOW, TRIGGER_LBLUE);
	create_dynamic_area(POSITION_SAFE_INT_LOW, -1, 1, HOUSE_SAFE, 1.5);

	CreateDynamic3DTextLabel(""cWH"Домашний Сейф",-1, \
  		POSITION_SAFE_INT_MEDIUM, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	create_circle_pickup_o(POSITION_SAFE_INT_MEDIUM, TRIGGER_LBLUE);
	create_dynamic_area(POSITION_SAFE_INT_MEDIUM, -1, 1, HOUSE_SAFE, 1.5);


	CreateDynamic3DTextLabel(""cWH"Домашний Сейф",-1, \
  		POSITION_SAFE_INT_HARD, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	create_circle_pickup_o(POSITION_SAFE_INT_HARD, TRIGGER_LBLUE);
	create_dynamic_area(POSITION_SAFE_INT_HARD, -1, 1, HOUSE_SAFE, 1.5);

	CreateDynamic3DTextLabel(""cWH"Домашний Сейф",-1, \
  		POSITION_SAFE_INT_LUXE, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	create_circle_pickup_o(POSITION_SAFE_INT_LUXE, TRIGGER_LBLUE);
	create_dynamic_area(POSITION_SAFE_INT_LUXE, -1, 1, HOUSE_SAFE, 1.5);

	CreateDynamic3DTextLabel(""cWH"Домашний Сейф",-1, \
  		POSITION_SAFE_INT_LUXE1, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	create_circle_pickup_o(POSITION_SAFE_INT_LUXE1, TRIGGER_LBLUE);
	create_dynamic_area(POSITION_SAFE_INT_LUXE1, -1, 1, HOUSE_SAFE, 1.5);

	CreateDynamic3DTextLabel(""cWH"Домашний Сейф",-1, \
  		POSITION_SAFE_INT_LUXE2, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	create_circle_pickup_o(POSITION_SAFE_INT_LUXE2, TRIGGER_LBLUE);
	create_dynamic_area(POSITION_SAFE_INT_LUXE2, -1, 1, HOUSE_SAFE, 1.5);

	CreateDynamic3DTextLabel(""cWH"Домашний Сейф",-1, \
  		POSITION_SAFE_INT_POSELOK, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	create_circle_pickup_o(POSITION_SAFE_INT_POSELOK, TRIGGER_LBLUE);
	create_dynamic_area(POSITION_SAFE_INT_POSELOK, -1, 1, HOUSE_SAFE, 1.5);

	return true;
}


stock safe_max_money_text(id_house)
{
	new 
		count[30],
		class = House[id_house][safe_house_status];

	switch(class)
	{
		case 1: count = ""cLRED"50000";
		case 2: count = ""cORANGE"250000";
		case 3: count = ""cGR"1000000";
		default: count = ""cLRED"Отсутствует";
	}
	return count;
}


stock safe_max_money(h)
{
	new 
		count,
		class = House[h][safe_house_status];

	switch(class)
	{
		case 1: count = 50000;
		case 2: count = 250000;
		case 3: count = 1000000;
		default: count = 0;
	}
	return count;
}

stock safe_max_drugs_text(h)
{
	new 
		count[30],
		class = House[h][safe_house_status];

	switch(class)
	{
		case 1: count = ""cLRED"500";
		case 2: count = ""cORANGE"1000";
		case 3: count = ""cGR"3000";
		default: count = ""cLRED"Отсутствует";
	}
	return count;
}

stock safe_max_drugs(h)
{
	new 
		count,
		class = House[h][safe_house_status];

	switch(class)
	{
		case 1: count = 500;
		case 2: count = 1000;
		case 3: count = 3000;
		default: count = 0;
	}
	return count;
}

stock show_money_safe_menu(playerid, id_house)
{
	new 
		fmt_str[200];

    format(fmt_str, 200, "\
    "cGREY"Тип\t"cGREY"Информация\n\
    "cBLUE"- "cWH"Взять деньги из сейфа\t"cBLUE"%d рублей\n\
    "cBLUE"- "cWH"Положить деньги в сейф\t"cBLUE"Положить", House[id_house][safe_house_money]);
    return SPD(playerid, DIALOG_GENERAL_MENU_MONEY, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Сейф в доме", fmt_str, !"Выбрать", !"Закрыть"); 

}

stock input_money_safe_menu(playerid, h)
{
	if(House[h][safe_house_money] == 0)
	{
		show_money_safe_menu(playerid, h);
		return SendErr(playerid, "В сейфе нет денег, чтобы взять их!");
	}

	new 
		fmt_str[130]; 

	format(fmt_str, 130, "\
	"cWH"В вашем сейфе находится "cGR"%d рублей"cWH" на данный момент\n\n\
	"cBLUE"Сколько денег Вы хотите взять?", House[h][safe_house_money]);

	return SPD(playerid, DIALOG_INPUT_MENU_MONEY, DIALOG_STYLE_INPUT, !""cBLUE"Сейф в доме", fmt_str, !"Далее", !"Назад");

}

stock put_money_safe_menu(playerid, h)
{
	new 
		fmt_str[350]; 

	new 
		max_money_counts = safe_max_money(h) - House[h][safe_house_money];

	format(fmt_str, 350, "\
	"cWH"В вашем сейфе находится "cGR"%d рублей"cWH" на данный момент\n\n\
	У вас %s "cWH"и Вы можете положить максимум "cGR"%d рублей"cWH" в сейф\n\
	На текущий момент, Вы можете положить "cGR"%d рублей"cWH" в сейф\n\n\
	"cBLUE"Сколько денег Вы хотите положить?", House[h][safe_house_drugs], get_house_seif(h), safe_max_money(h), max_money_counts);

	return SPD(playerid, DIALOG_PUT_MENU_MONEY, DIALOG_STYLE_INPUT, !""cBLUE"Сейф в доме", fmt_str, !"Далее", !"Назад");
}


stock show_house_safe_code(playerid)
{
	new 
		id_house = pData[playerid][pHouse];

	if(pData[playerid][pHouse] == -1)
		return SendErr(playerid, "У вас нет доступа к данному сейфу!");	

	if(GetPlayerVirtualWorld(playerid) != id_house)
		return SendErr(playerid, "Вы находитесь не в своем доме!");


	if(House[id_house][safe_house_status] == 0)
		return SendErr(playerid, "У вас в доме нет сейфа!");

	return SPD(playerid, DIALOG_CODE_SAFE_INPUT, DIALOG_STYLE_INPUT, !""cBLUE"Доступ к сейфу", \
		!""cWH"Чтобы открыть сейф, введите код-пароль:", !"Открыть", !"Назад");
}


stock show_change_safe_code(playerid)
{
	return SPD(playerid, DIALOG_CHANGE_PASS_SAFE, DIALOG_STYLE_INPUT, !""cBLUE"Новый код к сейфу", \
		!""cWH"Ввведите новый код от сейфа\n\n\
		"cBLUE"Код должен состоять от 4 до 8 символов", !"Открыть", !"Назад");
}

stock show_drugs_safe_info(playerid, h)
{	
	new 
		max_drugs_counts = safe_max_drugs(h) - House[h][safe_house_drugs] - House[h][safe_house_drugs_hard];

	new 
		fmt_str[400];

    format(fmt_str, 400, "\
    "cGREY"Тип\t"cGREY"Информация\n\
    "cBLUE"- "cWH"Легких наркотиков\t"cBLUE"%d грамм\n\
    "cBLUE"- "cWH"Тяжёлых наркотиков\t"cBLUE"%d грамм\n\
    "cBLUE"\t\n\
    "cBLUE"- "cWH"Максимум можно положить\t"cBLUE"%d грамм\n\
    "cBLUE"- "cWH"Сколько ещё можно положить\t"cBLUE"%d грамм", House[h][safe_house_drugs], House[h][safe_house_drugs_hard], safe_max_drugs(h), max_drugs_counts);
    return SPD(playerid, DIALOG_INFO_DRUGS_ALL, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Сейф в доме", fmt_str, !"Закрыть", ""); 

}

stock show_house_safe(playerid, h)
{
	new 
		fmt_str[400];

    format(fmt_str, 400, "\
    "cGREY"Тип\t"cGREY"Информация\n\
    "cBLUE"- "cWH"Тип сейфа\t%s\n\
    "cBLUE"- "cWH"Пароль сейфа\t"cBLUE"Изменить\n\
    "cBLUE"\t\n\
    "cBLUE"- "cWH"Лёгкие наркотики в сейфе\t"cLRED"Открыть\n\
    "cBLUE"- "cWH"Тяжёлые наркотики в сейфе\t"cLRED"Открыть\n\
    "cBLUE"- "cWH"Деньги в сейфе\t"cLRED"Открыть", get_house_seif(h), safe_max_drugs_text(h), safe_max_money_text(h));
    return SPD(playerid, DIALOG_SAFE_GENERAL, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Сейф в доме", fmt_str, !"Выбрать", !"Закрыть"); 
}

stock show_drugs_safe_menu_lite(playerid, h)
{
	new 
		fmt_str[200];

    format(fmt_str, 200, "\
    "cGREY"Тип\t"cGREY"Информация\n\
    "cBLUE"- "cWH"Взять лёгкие наркотики\t"cBLUE"%d грамм\n\
    "cBLUE"- "cWH"Положить лёгкие наркотики\t"cBLUE"Положить\n\
    "cBLUE"- "cWH"Общая информация\t"cBLUE"Открыть", House[h][safe_house_drugs]);
    return SPD(playerid, DIALOG_GENERAL_MENU_DRUGS, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Сейф в доме", fmt_str, !"Выбрать", !"Закрыть"); 
}

stock show_drugs_safe_menu_hard(playerid, h)
{
	new 
		fmt_str[200];

    format(fmt_str, 200, "\
    "cGREY"Тип\t"cGREY"Информация\n\
    "cBLUE"- "cWH"Взять тяжёлые наркотики\t"cBLUE"%d грамм\n\
    "cBLUE"- "cWH"Положить тяжёлые наркотики\t"cBLUE"Положить\n\
    "cBLUE"- "cWH"Общая информация\t"cBLUE"Открыть", House[h][safe_house_drugs_hard]);
    return SPD(playerid, DIALOG_GENERAL_MENU_DRUGS_HARD, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Сейф в доме", fmt_str, !"Выбрать", !"Закрыть"); 
}


stock input_drugs_safe_menu_lite(playerid, h)
{
	if(House[h][safe_house_drugs] == 0)
	{
		show_drugs_safe_menu_lite(playerid, h);
		return SendErr(playerid, "В вашем сейфе нет лёгких наркотив, чтобы взять их!");
	}

	new 
		fmt_str[130]; 

	format(fmt_str, 130, "\
	"cWH"В вашем сейфе находится "cBLUE"%d"cWH" грамм легких наркотиков\n\
	"cBLUE"Сколько грамм наркотиков Вы хотите достать?", House[h][safe_house_drugs]);

	return SPD(playerid, DIALOG_INPUT_MENU_DRUGS, DIALOG_STYLE_INPUT, !""cBLUE"Сейф в доме", fmt_str, !"Далее", !"Назад");

}

stock put_drugs_safe_menu_lite(playerid, h)
{
	new 
		fmt_str[350]; 

	new 
		max_drugs_counts = safe_max_drugs(h) - House[h][safe_house_drugs] - House[h][safe_house_drugs_hard];

	format(fmt_str, 350, "\
	"cWH"В вашем сейфе находится "cBLUE"%d"cWH" грамм легких наркотиков\n\n\
	"cWH"У вас %s"cWH" и Вы можете положить максимум %s"cWH" грамм наркотиков всех видов\n\
	"cWH"На текущий момент, Вы можете положить %s"cWH" грамм легких наркотиков\n\n\
	"cBLUE"Сколько грамм легких наркотиков Вы хотите положить?", House[h][safe_house_drugs], get_house_seif(h), safe_max_drugs_text(h), max_drugs_counts);

	return SPD(playerid, DIALOG_PUT_MENU_DRUGS, DIALOG_STYLE_INPUT, !""cBLUE"Сейф в доме", fmt_str, !"Далее", !"Назад");
}


stock input_drugs_safe_menu_hard(playerid, h)
{

	if(House[h][safe_house_drugs_hard] == 0)
	{
		show_drugs_safe_menu_hard(playerid, h);
		return SendErr(playerid, "В вашем сейфе нет лёгких наркотив, чтобы взять их!");
	}


	new 
		fmt_str[130]; 

	format(fmt_str, 130, "\
	"cWH"В вашем сейфе находится "cBLUE"%d"cWH" грамм легких наркотиков\n\
	"cBLUE"Сколько грамм наркотиков Вы хотите достать?", House[h][safe_house_drugs_hard]);

	return SPD(playerid, DIALOG_INPUT_MENU_DRUGS_HARD, DIALOG_STYLE_INPUT, !""cBLUE"Сейф в доме", fmt_str, !"Далее", !"Назад");

}

stock put_drugs_safe_menu_hard(playerid, h)
{
	new 
		fmt_str[350]; 

	new 
		max_drugs_counts = safe_max_drugs(h) - House[h][safe_house_drugs] - House[h][safe_house_drugs_hard];

	format(fmt_str, 350, "\
	"cWH"В вашем сейфе находится "cBLUE"%d"cWH" грамм тяжёлых наркотиков\n\n\
	"cWH"У вас %s "cWH"и Вы можете положить максимум %s"cWH" грамм наркотиков всех видов\n\
	"cWH"На текущий момент, Вы можете положить %s"cWH" грамм тяжёлых наркотиков\n\n\
	"cBLUE"Сколько тяжёлых легких наркотиков Вы хотите положить?", House[h][safe_house_drugs_hard], get_house_seif(h), safe_max_drugs_text(h), max_drugs_counts);

	return SPD(playerid, DIALOG_PUT_MENU_DRUGS_HARD, DIALOG_STYLE_INPUT, !""cBLUE"Сейф в доме", fmt_str, !"Далее", !"Назад");
}


stock change_pass_safe(playerid)
{
	new 
		fmt_str[200];

    format(fmt_str, 200, "\
    "cGREY"Тип\t"cGREY"Информация\n\
    "cBLUE"- "cWH"Использовать свой код для сейфа\t"cBLUE"Изменить\n\
    "cBLUE"- "cWH"Рандомный код для сейфа\t"cBLUE"Генерировать");
    return SPD(playerid, DIALOG_CHANGE_SAFE_SELECT, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Сейф в доме", fmt_str, !"Выбрать", !"Закрыть"); 
}

stock change_pass_safe_random(playerid, h)
{


	new 
		code_safe_random;

	new 
		rand_safe_pass = 1000 + random(9999);

	code_safe_random = rand_safe_pass;


	House[h][safe_house_pass] = code_safe_random;

	SendSucc(playerid, "Пароль от сейфа был обновлен!");

	SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Новый пароль от сейфа - %d", code_safe_random);	

	show_house_safe_code(playerid);

	save_house(h);

	return true;
}

stock dialog_house_items(playerid, dialogid, response, listitem, inputtext[])
{

	switch(dialogid)
	{
		case DIALOG_CODE_SAFE_INPUT:
		{
			if(!response)
				return true;

			new 
				id_house = pData[playerid][pHouse];

			if(strval(inputtext) != House[id_house][safe_house_pass])
			{
				show_house_safe_code(playerid);
				return SendErr(playerid, "Код-пароль от сейфа был введен не верно!");
			}			
			show_house_safe(playerid, id_house);

		}
		case DIALOG_INFO_DRUGS_ALL:
		{
			new 
				id_house = pData[playerid][pHouse];		
				
			if(!response)
				return show_house_safe(playerid, id_house);

			show_house_safe(playerid, id_house);
					
		}
		case DIALOG_SAFE_GENERAL:
		{
			new 
				id_house = pData[playerid][pHouse];

			if(!response)
				return SendSucc(playerid, "Сейф был закрыт на замок!");

			switch(listitem)
			{
				case 0: return show_house_safe(playerid, id_house);
				case 1: return change_pass_safe(playerid);
				case 2: return show_house_safe(playerid, id_house);
				case 3:	return show_drugs_safe_menu_lite(playerid, id_house);
				case 4: return show_drugs_safe_menu_hard(playerid, id_house);
				case 5: return show_money_safe_menu(playerid, id_house);
			
			}				

		}
		case DIALOG_CHANGE_SAFE_SELECT:
		{
			new 
				id_house = pData[playerid][pHouse];

			if(!response)
				return SendSucc(playerid, "Сейф был закрыт на замок!");

			switch(listitem)
			{
				case 0: return show_change_safe_code(playerid);
				case 1: return change_pass_safe_random(playerid, id_house);
			
			}				
		}
		case DIALOG_CHANGE_PASS_SAFE:
		{
			new 
				id_house = pData[playerid][pHouse];

			if(!response)
				return show_house_safe(playerid, id_house);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверный пароль для сейфа!");
				return change_pass_safe(playerid);
			}

			if(strlen(inputtext) < 4 || strlen(inputtext) > 8 || inputtext[0] == '0'  || inputtext[0] == ' ')
			{
				SendErr(playerid,"Вы указали неверное значение для пароля у сейфа!");
				SendInf(playerid,"Нельзя устанавливать слишком простые коды. Пример: 0000");
				return change_pass_safe(playerid);
			}

			new 
				new_password_safe = strval(inputtext);


			House[id_house][safe_house_pass] = new_password_safe;

			SendSucc(playerid, "Пароль от сейфа был обновлен!");
			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Новый пароль от сейфа - %d", new_password_safe);	

			show_house_safe_code(playerid);

			save_house(id_house);

		}
		case DIALOG_GENERAL_MENU_DRUGS:
		{
			new 
				id_house = pData[playerid][pHouse];

			if(!response)
				return show_house_safe(playerid, id_house);

			switch(listitem)
			{
				case 0: return input_drugs_safe_menu_lite(playerid, id_house);
				case 1: return put_drugs_safe_menu_lite(playerid, id_house);
				case 2: return show_drugs_safe_info(playerid, id_house);
			
			}

		}
		case DIALOG_GENERAL_MENU_DRUGS_HARD:
		{
			new 
				id_house = pData[playerid][pHouse];

			if(!response)
				return show_house_safe(playerid, id_house);

			switch(listitem)
			{
				case 0: return input_drugs_safe_menu_hard(playerid, id_house);
				case 1: return put_drugs_safe_menu_hard(playerid, id_house);
				case 2: return show_drugs_safe_info(playerid, id_house);
			
			}
		}

		case DIALOG_INPUT_MENU_DRUGS:
		{
			new 
				id_house = pData[playerid][pHouse];

			if(!response)
				return show_drugs_safe_menu_lite(playerid, id_house);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное количество граммов!");
				return input_drugs_safe_menu_lite(playerid, id_house);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное количество граммов!");
				return input_drugs_safe_menu_lite(playerid, id_house);				
			}

			new 
				count_drugs_input = strval(inputtext);

			if(count_drugs_input < 1)
			{
				SendErr(playerid,"У вас недостаточно наркотиков в сейфе!");
				return input_drugs_safe_menu_lite(playerid, id_house);		
			}

			if(House[id_house][safe_house_drugs] < count_drugs_input)
			{
				SendErr(playerid,"У вас недостаточно наркотиков в сейфе!");
				return input_drugs_safe_menu_lite(playerid, id_house);				
			}

			House[id_house][safe_house_drugs] -= count_drugs_input;

			pData[playerid][pDrugs] += count_drugs_input;
			UpdatePlayerData(playerid, "drugs", pData[playerid][pDrugs]);		

			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы взяли из сейфа - %d грамм наркотиков", count_drugs_input);	

			show_drugs_safe_menu_lite(playerid, id_house);

			save_house(id_house);	

		}
		case DIALOG_PUT_MENU_DRUGS:
		{
			new 
				id_house = pData[playerid][pHouse];

			if(!response)
				return show_drugs_safe_menu_lite(playerid, id_house);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное количество граммов!");
				return put_drugs_safe_menu_lite(playerid, id_house);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное количество граммов!");
				return put_drugs_safe_menu_lite(playerid, id_house);				
			}


			new 
				count_drugs_put = strval(inputtext);

			if(count_drugs_put < 1)
			{
				SendErr(playerid,"У вас недостаточно наркотиков!");
				return put_drugs_safe_menu_lite(playerid, id_house);		
			}


			new 
				max_drugs_count = safe_max_drugs(id_house) - House[id_house][safe_house_drugs] - House[id_house][safe_house_drugs_hard];

			if(pData[playerid][pDrugs] < count_drugs_put)
			{
				SendErr(playerid,"У вас недостаточно наркотиков!");
				return put_drugs_safe_menu_lite(playerid, id_house);				
			}
			if(max_drugs_count < count_drugs_put)
			{
				SendErr(playerid,"У вас недостаточно места в сейфе!");
				return put_drugs_safe_menu_lite(playerid, id_house);					
			}

			pData[playerid][pDrugs] -= count_drugs_put;
			UpdatePlayerData(playerid, "drugs", pData[playerid][pDrugs]);		

			House[id_house][safe_house_drugs] += count_drugs_put;

			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы положили в сейф - %d грамм наркотиков", count_drugs_put);	

			show_drugs_safe_menu_lite(playerid, id_house);

			save_house(id_house);	

		}


		case DIALOG_INPUT_MENU_DRUGS_HARD:
		{
			new 
				id_house = pData[playerid][pHouse];

			if(!response)
				return show_drugs_safe_menu_hard(playerid, id_house);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное количество граммов!");
				return input_drugs_safe_menu_hard(playerid, id_house);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное количество граммов!");
				return input_drugs_safe_menu_hard(playerid, id_house);				
			}


			new 
				count_drugs_input = strval(inputtext);


			if(count_drugs_input < 1)
			{
				SendErr(playerid,"У вас недостаточно наркотиков в сейфе!");
				return input_drugs_safe_menu_hard(playerid, id_house);		
			}


			if(House[id_house][safe_house_drugs_hard] < count_drugs_input)
			{
				SendErr(playerid,"У вас недостаточно наркотиков в сейфе!");
				return input_drugs_safe_menu_hard(playerid, id_house);				
			}

			House[id_house][safe_house_drugs_hard] -= count_drugs_input;

			pData[playerid][pHDrugs] += count_drugs_input;
			UpdatePlayerData(playerid, "hdrugs", pData[playerid][pHDrugs]);		

			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы взяли из сейфа - %d грамм тяжёлых наркотиков", count_drugs_input);	

			show_drugs_safe_menu_hard(playerid, id_house);

			save_house(id_house);	

		}
		case DIALOG_PUT_MENU_DRUGS_HARD:
		{
			new 
				id_house = pData[playerid][pHouse];

			if(!response)
				return show_drugs_safe_menu_hard(playerid, id_house);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное количество граммов!");
				return put_drugs_safe_menu_hard(playerid, id_house);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное количество граммов!");
				return put_drugs_safe_menu_hard(playerid, id_house);				
			}


			new 
				count_drugs_put = strval(inputtext);

			if(count_drugs_put < 1)
			{
				SendErr(playerid,"У вас недостаточно наркотиков!");
				return put_drugs_safe_menu_hard(playerid, id_house);		
			}


			new 
				max_drugs_count = safe_max_drugs(id_house) - House[id_house][safe_house_drugs] - House[id_house][safe_house_drugs_hard];

			if(pData[playerid][pHDrugs] < count_drugs_put)
			{
				SendErr(playerid,"У вас недостаточно наркотиков!");
				return put_drugs_safe_menu_hard(playerid, id_house);				
			}
			if(max_drugs_count < count_drugs_put)
			{
				SendErr(playerid,"У вас недостаточно места в сейфе!");
				return put_drugs_safe_menu_hard(playerid, id_house);					
			}

			pData[playerid][pHDrugs] -= count_drugs_put;
			UpdatePlayerData(playerid, "hdrugs", pData[playerid][pHDrugs]);		

			House[id_house][safe_house_drugs_hard] += count_drugs_put;

			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы положили в сейф - %d грамм тяжёлых наркотиков", count_drugs_put);	

			show_drugs_safe_menu_hard(playerid, id_house);

			save_house(id_house);	

		}

		case DIALOG_GENERAL_MENU_MONEY:
		{
			new 
				id_house = pData[playerid][pHouse];

			if(!response)
				return show_house_safe(playerid, id_house);

			switch(listitem)
			{
				case 0: return input_money_safe_menu(playerid, id_house);
				case 1: return put_money_safe_menu(playerid, id_house);
			}	
		}
		case DIALOG_INPUT_MENU_MONEY:
		{
			new 
				id_house = pData[playerid][pHouse];

			if(!response)
				return show_money_safe_menu(playerid, id_house);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное количество денег!");
				return input_money_safe_menu(playerid, id_house);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное количество денег!");
				return input_money_safe_menu(playerid, id_house);			
			}


			new 
				count_money_input = strval(inputtext);

			if(count_money_input < 1)
			{
				SendErr(playerid,"У вас недостаточно денег в сейфе!");
				return input_money_safe_menu(playerid, id_house);	
			}

			if(House[id_house][safe_house_money] < count_money_input)
			{
				SendErr(playerid,"У вас недостаточно денег в сейфе!");
				return input_money_safe_menu(playerid, id_house);				
			}

			House[id_house][safe_house_money] -= count_money_input;

		 	format(String144, sizeof(String144), "Деньги с сейфа №%d", id_house);
			give_money(playerid, count_money_input, String144);

			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы взяли из сейфа - "cGR"%d рублей"cWH"", count_money_input);	

			show_money_safe_menu(playerid, id_house);

			save_house(id_house);	

		}
		case DIALOG_PUT_MENU_MONEY:
		{
			new 
				id_house = pData[playerid][pHouse];

			if(!response)
				return show_money_safe_menu(playerid, id_house);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное количество денег!");
				return put_money_safe_menu(playerid, id_house);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное количество денег!");
				return put_money_safe_menu(playerid, id_house);		
			}

			new 
				count_money_put = strval(inputtext);

			if(count_money_put < 1)
			{
				SendErr(playerid,"Вы указали неверное количество денег!");
				return put_money_safe_menu(playerid, id_house);		
			}


			new 
				max_money_count = safe_max_money(id_house) - House[id_house][safe_house_money];

			if(GetPlayerMoneyEx(playerid) < count_money_put)
			{
				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
				SendErr(playerid,"У вас недостаточно денег!");
				return put_money_safe_menu(playerid, id_house);				
			}
			if(max_money_count < count_money_put)
			{
				SendErr(playerid,"У вас недостаточно места в сейфе!");
				return put_money_safe_menu(playerid, id_house);					
			}


			House[id_house][safe_house_money] += count_money_put;

		 	format(String144, sizeof(String144), "Деньги в сейф №%d", id_house);
			give_money(playerid, -count_money_put, String144);

			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы положили в сейф - "cGR"%d рублей"cWH"", count_money_put);	

			show_money_safe_menu(playerid, id_house);

			save_house(id_house);	

		}

	}
	return true;
}
