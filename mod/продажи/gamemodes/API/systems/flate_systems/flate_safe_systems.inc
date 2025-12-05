
#define POSITION_SAFE_INT_FLATE_LOW			-2393.9141, -442.1600, 33.2104
#define POSITION_SAFE_INT_FLATE_MEDIUM		492.3407,2308.2129,1601.2031
#define POSITION_SAFE_INT_FLATE_HARD		-2393.9141, -442.1600, 33.2104
#define POSITION_SAFE_INT_FLATE_LUXE		-2393.9141, -442.1600, 33.2104

stock create_flate_safe_position()
{
	CreateDynamic3DTextLabel(""cWH"Домашний Сейф",-1, \
  		POSITION_SAFE_INT_FLATE_LOW, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1, -1);	
	create_circle_pickup_o(POSITION_SAFE_INT_FLATE_LOW, TRIGGER_LBLUE);
	create_dynamic_area(POSITION_SAFE_INT_FLATE_LOW, -1, 1, FLATE_SAFE, 1.5);

	return true;
}


stock flate_safe_max_m_t(id_flate)
{
	new 
		count[30],
		class = flate[id_flate][safe_flate_status];

	switch(class)
	{
		case 1: count = ""cLRED"50000";
		case 2: count = ""cORANGE"250000";
		case 3: count = ""cGR"1000000";
		default: count = ""cLRED"Отсутствует";
	}
	return count;
}


stock flate_safe_max_m(h)
{
	new 
		count,
		class = flate[h][safe_flate_status];

	switch(class)
	{
		case 1: count = 50000;
		case 2: count = 250000;
		case 3: count = 1000000;
		default: count = 0;
	}
	return count;
}

stock flate_safe_m_d(h)
{
	new 
		count[30],
		class = flate[h][safe_flate_status];

	switch(class)
	{
		case 1: count = ""cLRED"500";
		case 2: count = ""cORANGE"1000";
		case 3: count = ""cGR"3000";
		default: count = ""cLRED"Отсутствует";
	}
	return count;
}

stock flate_safe_m_dd(h)
{
	new 
		count,
		class = flate[h][safe_flate_status];

	switch(class)
	{
		case 1: count = 500;
		case 2: count = 1000;
		case 3: count = 3000;
		default: count = 0;
	}
	return count;
}

stock show_money_safe_flate(playerid, id_flate)
{
	new 
		fmt_str[200];

    format(fmt_str, 200, "\
    "cGREY"Тип\t"cGREY"Информация\n\
    "cBLUE"- "cWH"Взять деньги из сейфа\t"cBLUE"%d рублей\n\
    "cBLUE"- "cWH"Положить деньги в сейф\t"cBLUE"Положить", flate[id_flate][safe_flate_money]);
    return SPD(playerid, DIALOG_FLATE_G_F_M, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Сейф в доме", fmt_str, !"Выбрать", !"Закрыть"); 

}

stock input_money_safe_flate(playerid, h)
{
	if(flate[h][safe_flate_money] == 0)
	{
		show_money_safe_flate(playerid, h);
		return SendErr(playerid, "В сейфе нет денег, чтобы взять их!");
	}

	new 
		fmt_str[130]; 

	format(fmt_str, 130, "\
	"cWH"В вашем сейфе находится "cGR"%d рублей"cWH" на данный момент\n\n\
	"cBLUE"Сколько денег Вы хотите взять?", flate[h][safe_flate_money]);

	return SPD(playerid, DIALOG_FLATE_INPUT_MONEY_S, DIALOG_STYLE_INPUT, !""cBLUE"Сейф в доме", fmt_str, !"Далее", !"Назад");

}

stock put_money_safe_flate(playerid, h)
{
	new 
		fmt_str[350]; 

	new 
		max_money_counts = flate_safe_max_m(h) - flate[h][safe_flate_money];

	format(fmt_str, 350, "\
	"cWH"В вашем сейфе находится "cGR"%d рублей"cWH" на данный момент\n\n\
	У вас %s "cWH"и Вы можете положить максимум "cGR"%d рублей"cWH" в сейф\n\
	На текущий момент, Вы можете положить "cGR"%d рублей"cWH" в сейф\n\n\
	"cBLUE"Сколько денег Вы хотите положить?", flate[h][safe_flate_drugs], get_flate_seif(h), flate_safe_max_m(h), max_money_counts);

	return SPD(playerid, DIALOG_PUT_MONEY_F_S, DIALOG_STYLE_INPUT, !""cBLUE"Сейф в доме", fmt_str, !"Далее", !"Назад");
}


stock show_flate_safe_code(playerid)
{
	new 
		id_flate = pData[playerid][pFlate];

	if(pData[playerid][pFlate] == -1)
		return SendErr(playerid, "У вас нет доступа к данному сейфу!");	

	if(GetPlayerVirtualWorld(playerid) != id_flate)
		return SendErr(playerid, "Вы находитесь не в своей квартире!");

	if(flate[id_flate][safe_flate_status] == 0)
		return SendErr(playerid, "У вас в доме нет сейфа!");

	return SPD(playerid, DIALOG_FLATE_CODE_SAFE_INPUT, DIALOG_STYLE_INPUT, !""cBLUE"Доступ к сейфу", \
		!""cWH"Чтобы открыть сейф, введите код-пароль:", !"Открыть", !"Назад");
}


stock show_change_flate_safe_p(playerid)
{
	return SPD(playerid, DIALOG_CHANGE_FLATE_S_P, DIALOG_STYLE_INPUT, !""cBLUE"Новый код к сейфу", \
		!""cWH"Ввведите новый код от сейфа\n\n\
		"cBLUE"Код должен состоять от 4 до 8 символов", !"Открыть", !"Назад");
}

stock show_d_info_flate_safe(playerid, h)
{	
	new 
		max_drugs_counts = flate_safe_m_dd(h) - flate[h][safe_flate_drugs] - flate[h][safe_flate_drugs_hard];

	new 
		fmt_str[400];

    format(fmt_str, 400, "\
    "cGREY"Тип\t"cGREY"Информация\n\
    "cBLUE"- "cWH"Легких наркотиков\t"cBLUE"%d грамм\n\
    "cBLUE"- "cWH"Тяжёлых наркотиков\t"cBLUE"%d грамм\n\
    "cBLUE"\t\n\
    "cBLUE"- "cWH"Максимум можно положить\t"cBLUE"%d грамм\n\
    "cBLUE"- "cWH"Сколько ещё можно положить\t"cBLUE"%d грамм", flate[h][safe_flate_drugs], flate[h][safe_flate_drugs_hard], flate_safe_m_dd(h), max_drugs_counts);
    return SPD(playerid, DIALOG_FLATE_D_INFO_ALL, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Сейф в доме", fmt_str, !"Закрыть", ""); 

}

stock show_flate_safe(playerid, h)
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
    "cBLUE"- "cWH"Деньги в сейфе\t"cLRED"Открыть", get_flate_seif(h), flate_safe_m_d(h), flate_safe_max_m_t(h));
    return SPD(playerid, DIALOG_FLATE_GENERAL_SAFE, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Сейф в доме", fmt_str, !"Выбрать", !"Закрыть"); 
}

stock show_drugs_flate_menu_l(playerid, h)
{
	new 
		fmt_str[200];

    format(fmt_str, 200, "\
    "cGREY"Тип\t"cGREY"Информация\n\
    "cBLUE"- "cWH"Взять лёгкие наркотики\t"cBLUE"%d грамм\n\
    "cBLUE"- "cWH"Положить лёгкие наркотики\t"cBLUE"Положить\n\
    "cBLUE"- "cWH"Общая информация\t"cBLUE"Открыть", flate[h][safe_flate_drugs]);
    return SPD(playerid, DIALOG_FLATE_D_GENERAL, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Сейф в доме", fmt_str, !"Выбрать", !"Закрыть"); 
}

stock show_drugs_flate_menu_h(playerid, h)
{
	new 
		fmt_str[200];

    format(fmt_str, 200, "\
    "cGREY"Тип\t"cGREY"Информация\n\
    "cBLUE"- "cWH"Взять тяжёлые наркотики\t"cBLUE"%d грамм\n\
    "cBLUE"- "cWH"Положить тяжёлые наркотики\t"cBLUE"Положить\n\
    "cBLUE"- "cWH"Общая информация\t"cBLUE"Открыть", flate[h][safe_flate_drugs_hard]);
    return SPD(playerid, DIALOG_FLATE_D_GENERAL_HARD, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Сейф в доме", fmt_str, !"Выбрать", !"Закрыть"); 
}


stock input_d_safe_menu_flate(playerid, h)
{
	if(flate[h][safe_flate_drugs] == 0)
	{
		show_drugs_flate_menu_l(playerid, h);
		return SendErr(playerid, "В вашем сейфе нет лёгких наркотив, чтобы взять их!");
	}

	new 
		fmt_str[130]; 

	format(fmt_str, 130, "\
	"cWH"В вашем сейфе находится "cBLUE"%d"cWH" грамм легких наркотиков\n\
	"cBLUE"Сколько грамм наркотиков Вы хотите достать?", flate[h][safe_flate_drugs]);

	return SPD(playerid, DIALOG_FLATE_INPUT_DRUGS, DIALOG_STYLE_INPUT, !""cBLUE"Сейф в доме", fmt_str, !"Далее", !"Назад");

}

stock put_d_safe_menu_flate(playerid, h)
{
	new 
		fmt_str[350]; 

	new 
		max_drugs_counts = flate_safe_m_dd(h) - flate[h][safe_flate_drugs] - flate[h][safe_flate_drugs_hard];

	format(fmt_str, 350, "\
	"cWH"В вашем сейфе находится "cBLUE"%d"cWH" грамм легких наркотиков\n\n\
	"cWH"У вас %s"cWH" и Вы можете положить максимум %s"cWH" грамм наркотиков всех видов\n\
	"cWH"На текущий момент, Вы можете положить %s"cWH" грамм легких наркотиков\n\n\
	"cBLUE"Сколько грамм легких наркотиков Вы хотите положить?", flate[h][safe_flate_drugs], get_flate_seif(h), flate_safe_m_d(h), max_drugs_counts);

	return SPD(playerid, DIALOG_FLATE_PUT_DRUGS, DIALOG_STYLE_INPUT, !""cBLUE"Сейф в доме", fmt_str, !"Далее", !"Назад");
}


stock input_d_safe_menu_flate_hard(playerid, h)
{

	if(flate[h][safe_flate_drugs_hard] == 0)
	{
		show_drugs_flate_menu_h(playerid, h);
		return SendErr(playerid, "В вашем сейфе нет лёгких наркотив, чтобы взять их!");
	}


	new 
		fmt_str[130]; 

	format(fmt_str, 130, "\
	"cWH"В вашем сейфе находится "cBLUE"%d"cWH" грамм легких наркотиков\n\
	"cBLUE"Сколько грамм наркотиков Вы хотите достать?", flate[h][safe_flate_drugs_hard]);

	return SPD(playerid, DIALOG_FLATE_INPUT_DRUGS_HARD, DIALOG_STYLE_INPUT, !""cBLUE"Сейф в доме", fmt_str, !"Далее", !"Назад");

}

stock put_d_safe_menu_flate_hard(playerid, h)
{
	new 
		fmt_str[350]; 

	new 
		max_drugs_counts = flate_safe_m_dd(h) - flate[h][safe_flate_drugs] - flate[h][safe_flate_drugs_hard];

	format(fmt_str, 350, "\
	"cWH"В вашем сейфе находится "cBLUE"%d"cWH" грамм тяжёлых наркотиков\n\n\
	"cWH"У вас %s "cWH"и Вы можете положить максимум %s"cWH" грамм наркотиков всех видов\n\
	"cWH"На текущий момент, Вы можете положить %s"cWH" грамм тяжёлых наркотиков\n\n\
	"cBLUE"Сколько тяжёлых легких наркотиков Вы хотите положить?", flate[h][safe_flate_drugs_hard], get_flate_seif(h), flate_safe_m_d(h), max_drugs_counts);

	return SPD(playerid, DIALOG_FLATE_PUT_DRUGS_HARD, DIALOG_STYLE_INPUT, !""cBLUE"Сейф в доме", fmt_str, !"Далее", !"Назад");
}


stock change_pass_flate_s(playerid)
{
	new 
		fmt_str[200];

    format(fmt_str, 200, "\
    "cGREY"Тип\t"cGREY"Информация\n\
    "cBLUE"- "cWH"Использовать свой код для сейфа\t"cBLUE"Изменить\n\
    "cBLUE"- "cWH"Рандомный код для сейфа\t"cBLUE"Генерировать");
    return SPD(playerid, DIALOG_CHANGE_FLATE_S_C, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Сейф в доме", fmt_str, !"Выбрать", !"Закрыть"); 
}

stock change_pass_flate_s_random(playerid, h)
{


	new 
		code_safe_random;

	new 
		rand_safe_pass = 1000 + random(9999);

	code_safe_random = rand_safe_pass;


	flate[h][safe_flate_pass] = code_safe_random;

	SendSucc(playerid, "Пароль от сейфа был обновлен!");

	SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Новый пароль от сейфа - %d", code_safe_random);	

	show_flate_safe_code(playerid);

	save_flate(h);

	return true;
}

stock dialog_flate_items(playerid, dialogid, response, listitem, inputtext[])
{

	switch(dialogid)
	{
		case DIALOG_FLATE_CODE_SAFE_INPUT:
		{
			if(!response)
				return true;

			new 
				id_flate = pData[playerid][pFlate];

			if(strval(inputtext) != flate[id_flate][safe_flate_pass])
			{
				show_flate_safe_code(playerid);
				return SendErr(playerid, "Код-пароль от сейфа был введен не верно!");
			}			
			show_flate_safe(playerid, id_flate);

		}
		case DIALOG_FLATE_D_INFO_ALL:
		{
			new 
				id_flate = pData[playerid][pFlate];		
				
			if(!response)
				return show_flate_safe(playerid, id_flate);

			show_flate_safe(playerid, id_flate);
					
		}
		case DIALOG_FLATE_GENERAL_SAFE:
		{
			new 
				id_flate = pData[playerid][pFlate];

			if(!response)
				return SendSucc(playerid, "Сейф был закрыт на замок!");

			switch(listitem)
			{
				case 0: return show_flate_safe(playerid, id_flate);
				case 1: return change_pass_flate_s(playerid);
				case 2: return show_flate_safe(playerid, id_flate);
				case 3:	return show_drugs_flate_menu_l(playerid, id_flate);
				case 4: return show_drugs_flate_menu_h(playerid, id_flate);
				case 5: return show_money_safe_flate(playerid, id_flate);
			
			}				

		}
		case DIALOG_CHANGE_FLATE_S_C:
		{
			new 
				id_flate = pData[playerid][pFlate];

			if(!response)
				return SendSucc(playerid, "Сейф был закрыт на замок!");

			switch(listitem)
			{
				case 0: return show_change_flate_safe_p(playerid);
				case 1: return change_pass_flate_s_random(playerid, id_flate);
			
			}				
		}
		case DIALOG_CHANGE_FLATE_S_P:
		{
			new 
				id_flate = pData[playerid][pFlate];

			if(!response)
				return show_flate_safe(playerid, id_flate);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверный пароль для сейфа!");
				return change_pass_flate_s(playerid);
			}

			if(strlen(inputtext) < 4 || strlen(inputtext) > 8 || inputtext[0] == '0'  || inputtext[0] == ' ')
			{
				SendErr(playerid,"Вы указали неверное значение для пароля у сейфа!");
				SendInf(playerid,"Нельзя устанавливать слишком простые коды. Пример: 0000");
				return change_pass_flate_s(playerid);
			}

			new 
				new_password_safe = strval(inputtext);


			flate[id_flate][safe_flate_pass] = new_password_safe;

			SendSucc(playerid, "Пароль от сейфа был обновлен!");
			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Новый пароль от сейфа - %d", new_password_safe);	

			show_flate_safe_code(playerid);

			save_flate(id_flate);

		}
		case DIALOG_FLATE_D_GENERAL:
		{
			new 
				id_flate = pData[playerid][pFlate];

			if(!response)
				return show_flate_safe(playerid, id_flate);

			switch(listitem)
			{
				case 0: return input_d_safe_menu_flate(playerid, id_flate);
				case 1: return put_d_safe_menu_flate(playerid, id_flate);
				case 2: return show_d_info_flate_safe(playerid, id_flate);
			
			}

		}
		case DIALOG_FLATE_D_GENERAL_HARD:
		{
			new 
				id_flate = pData[playerid][pFlate];

			if(!response)
				return show_flate_safe(playerid, id_flate);

			switch(listitem)
			{
				case 0: return input_d_safe_menu_flate_hard(playerid, id_flate);
				case 1: return put_d_safe_menu_flate_hard(playerid, id_flate);
				case 2: return show_d_info_flate_safe(playerid, id_flate);
			
			}
		}

		case DIALOG_FLATE_INPUT_DRUGS:
		{
			new 
				id_flate = pData[playerid][pFlate];

			if(!response)
				return show_drugs_flate_menu_l(playerid, id_flate);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное количество граммов!");
				return input_d_safe_menu_flate(playerid, id_flate);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное количество граммов!");
				return input_d_safe_menu_flate(playerid, id_flate);				
			}

			new 
				count_drugs_input = strval(inputtext);


			if(count_drugs_input < 1)
			{
				SendErr(playerid,"У вас недостаточно наркотиков в сейфе!");
				return input_d_safe_menu_flate(playerid, id_flate);		
			}

			if(flate[id_flate][safe_flate_drugs] < count_drugs_input)
			{
				SendErr(playerid,"У вас недостаточно наркотиков в сейфе!");
				return input_d_safe_menu_flate(playerid, id_flate);				
			}

			flate[id_flate][safe_flate_drugs] -= count_drugs_input;

			pData[playerid][pDrugs] += count_drugs_input;
			UpdatePlayerData(playerid, "drugs", pData[playerid][pDrugs]);		

			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы взяли из сейфа - %d грамм наркотиков", count_drugs_input);	

			show_drugs_flate_menu_l(playerid, id_flate);

			save_flate(id_flate);	

		}
		case DIALOG_FLATE_PUT_DRUGS:
		{
			new 
				id_flate = pData[playerid][pFlate];

			if(!response)
				return show_drugs_flate_menu_l(playerid, id_flate);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное количество граммов!");
				return put_d_safe_menu_flate(playerid, id_flate);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное количество граммов!");
				return put_d_safe_menu_flate(playerid, id_flate);				
			}


			new 
				count_drugs_put = strval(inputtext);

			if(count_drugs_put < 1)
			{
				SendErr(playerid,"У вас недостаточно наркотиков!");
				return put_d_safe_menu_flate(playerid, id_flate);
			}

			new 
				max_drugs_count = flate_safe_m_dd(id_flate) - flate[id_flate][safe_flate_drugs] - flate[id_flate][safe_flate_drugs_hard];



			if(pData[playerid][pDrugs] < count_drugs_put)
			{
				SendErr(playerid,"У вас недостаточно наркотиков!");
				return put_d_safe_menu_flate(playerid, id_flate);				
			}
			if(max_drugs_count < count_drugs_put)
			{
				SendErr(playerid,"У вас недостаточно места в сейфе!");
				return put_d_safe_menu_flate(playerid, id_flate);					
			}

			pData[playerid][pDrugs] -= count_drugs_put;
			UpdatePlayerData(playerid, "drugs", pData[playerid][pDrugs]);		

			flate[id_flate][safe_flate_drugs] += count_drugs_put;

			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы положили в сейф - %d грамм наркотиков", count_drugs_put);	

			show_drugs_flate_menu_l(playerid, id_flate);

			save_flate(id_flate);	

		}


		case DIALOG_FLATE_INPUT_DRUGS_HARD:
		{
			new 
				id_flate = pData[playerid][pFlate];

			if(!response)
				return show_drugs_flate_menu_h(playerid, id_flate);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное количество граммов!");
				return  input_d_safe_menu_flate_hard(playerid, id_flate);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное количество граммов!");
				return  input_d_safe_menu_flate_hard(playerid, id_flate);				
			}


			new 
				count_drugs_input = strval(inputtext);

			if(count_drugs_input < 1)
			{
				SendErr(playerid,"У вас недостаточно наркотиков в сейфе!");
				return  input_d_safe_menu_flate_hard(playerid, id_flate);		
			}

			if(flate[id_flate][safe_flate_drugs_hard] < count_drugs_input)
			{
				SendErr(playerid,"У вас недостаточно наркотиков в сейфе!");
				return  input_d_safe_menu_flate_hard(playerid, id_flate);				
			}

			flate[id_flate][safe_flate_drugs_hard] -= count_drugs_input;

			pData[playerid][pHDrugs] += count_drugs_input;
			UpdatePlayerData(playerid, "hdrugs", pData[playerid][pHDrugs]);		

			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы взяли из сейфа - %d грамм тяжёлых наркотиков", count_drugs_input);	

			show_drugs_flate_menu_h(playerid, id_flate);

			save_flate(id_flate);	

		}
		case DIALOG_FLATE_PUT_DRUGS_HARD:
		{
			new 
				id_flate = pData[playerid][pFlate];

			if(!response)
				return show_drugs_flate_menu_h(playerid, id_flate);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное количество граммов!");
				return put_d_safe_menu_flate_hard(playerid, id_flate);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное количество граммов!");
				return put_d_safe_menu_flate_hard(playerid, id_flate);				
			}


			new 
				count_drugs_put = strval(inputtext);

			new 
				max_drugs_count = flate_safe_m_dd(id_flate) - flate[id_flate][safe_flate_drugs] - flate[id_flate][safe_flate_drugs_hard];

			if(count_drugs_put < 1)
			{
				SendErr(playerid,"У вас недостаточно наркотиков!");
				return put_d_safe_menu_flate_hard(playerid, id_flate);		
			}

			if(pData[playerid][pHDrugs] < count_drugs_put)
			{
				SendErr(playerid,"У вас недостаточно наркотиков!");
				return put_d_safe_menu_flate_hard(playerid, id_flate);				
			}
			if(max_drugs_count < count_drugs_put)
			{
				SendErr(playerid,"У вас недостаточно места в сейфе!");
				return put_d_safe_menu_flate_hard(playerid, id_flate);					
			}

			pData[playerid][pHDrugs] -= count_drugs_put;
			UpdatePlayerData(playerid, "hdrugs", pData[playerid][pHDrugs]);		

			flate[id_flate][safe_flate_drugs_hard] += count_drugs_put;

			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы положили в сейф - %d грамм тяжёлых наркотиков", count_drugs_put);	

			show_drugs_flate_menu_h(playerid, id_flate);

			save_flate(id_flate);	

		}

		case DIALOG_FLATE_G_F_M:
		{
			new 
				id_flate = pData[playerid][pFlate];

			if(!response)
				return show_flate_safe(playerid, id_flate);

			switch(listitem)
			{
				case 0: return input_money_safe_flate(playerid, id_flate);
				case 1: return put_money_safe_flate(playerid, id_flate);
			}	
		}
		case DIALOG_FLATE_INPUT_MONEY_S:
		{
			new 
				id_flate = pData[playerid][pFlate];

			if(!response)
				return show_money_safe_flate(playerid, id_flate);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное количество денег!");
				return input_money_safe_flate(playerid, id_flate);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное количество денег!");
				return input_money_safe_flate(playerid, id_flate);			
			}


			new 
				count_money_input = strval(inputtext);

			if(count_money_input < 1)
			{
				SendErr(playerid,"Вы указали неверное количество денег!");
				return input_money_safe_flate(playerid, id_flate);	
			}

			if(flate[id_flate][safe_flate_money] < count_money_input)
			{
				SendErr(playerid,"У вас недостаточно денег в сейфе!");
				return input_money_safe_flate(playerid, id_flate);				
			}

			flate[id_flate][safe_flate_money] -= count_money_input;

		 	format(String144, sizeof(String144), "Деньги из сейфа дома №%d", id_flate);
			give_money(playerid, count_money_input, String144);

			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы взяли из сейфа - "cGR"%d рублей"cWH"", count_money_input);	

			show_money_safe_flate(playerid, id_flate);

			save_flate(id_flate);	

		}
		case DIALOG_PUT_MONEY_F_S:
		{
			new 
				id_flate = pData[playerid][pFlate];

			if(!response)
				return show_money_safe_flate(playerid, id_flate);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное количество денег!");
				return put_money_safe_flate(playerid, id_flate);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное количество денег!");
				return put_money_safe_flate(playerid, id_flate);		
			}

			new 
				count_money_put = strval(inputtext);

			new 
				max_money_count = flate_safe_max_m(id_flate) - flate[id_flate][safe_flate_money];

			if(count_money_put < 1)
			{
				SendErr(playerid,"Вы указали неверное количество денег!");
				return put_money_safe_flate(playerid, id_flate);		
			}

			if(GetPlayerMoneyEx(playerid) < count_money_put)
			{
				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
				SendErr(playerid,"У вас недостаточно денег!");
				return put_money_safe_flate(playerid, id_flate);				
			}
			if(max_money_count < count_money_put)
			{
				SendErr(playerid,"У вас недостаточно места в сейфе!");
				return put_money_safe_flate(playerid, id_flate);					
			}


			flate[id_flate][safe_flate_money] += count_money_put;

		 	format(String144, sizeof(String144), "Деньги в сейф дома №%d", id_flate);
			give_money(playerid, -count_money_put, String144);

			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы положили в сейф - "cGR"%d рублей"cWH"", count_money_put);	

			show_money_safe_flate(playerid, id_flate);

			save_flate(id_flate);	

		}

	}
	return true;
}
