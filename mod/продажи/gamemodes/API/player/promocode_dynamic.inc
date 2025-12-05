
#define ADMIN_PRIZE_PROMO_START		1
#define ADMIN_PRIZE_PROMO_DYNAMIC	2

new 
	promocode_name_admin[MAX_PLAYERS][32];


enum promocode_create_data
{
	promocode_money_prize,
	promocode_exp_prize,
	promocode_skin_prize,
	promocode_donate_prize,
	promocode_vehicle_prize,

	promocode_weapon_1_prize,
	promocode_weapon_2_prize,
	promocode_weapon_3_prize,
	promocode_weapon_4_prize,
	promocode_weapon_5_prize,
	promocode_weapon_6_prize,

	promocode_play_time,
	promocode_active_time,

	promocode_level_min,
	promocode_level_max

}

new 
	promocode_create[MAX_PLAYERS][promocode_create_data];

CMD:adminpromo(playerid)
{
    if(pData[playerid][pAdmin] < 8)
    	return NoCMD(playerid);	

	return show_create_admin_promo(playerid);
}

stock show_create_admin_promo(playerid)
{
	return SPD(playerid, DIALOG_CREATE_PROMO_A_Y, DIALOG_STYLE_INPUT, ""cBLUE"Создание ютуберского промокода", \
	!""cWH"Введите наименование промокода, который хотите создать\n\n\
	Промокод будет активирован игроком 1 раз", !"Далее", !"Закрыть");
}

stock show_create_admin_promo_start(playerid)
{
	return SPD(playerid, DIALOG_CREATE_PROMO_A_Y_1, DIALOG_STYLE_INPUT, ""cBLUE"Создание ютуберского промокода", \
	!""cWH"Введите наименование промокода, который хотите создать\n\n\
	Промокод будет активирован игроком 1 раз", !"Далее", !"Закрыть");
}


stock select_admin_promo_prize_m(playerid)
{

	return SPD(playerid, DIALOG_SELECT_PROMO_A_Y, DIALOG_STYLE_LIST, !""cBLUE"Выбор типа вознаграждения", \
	""cBLUE"1. "cWH"Набор новичка\n\
	"cBLUE"2. "cWH"Динамический выбор вознаграждения", !"Выбрать", !"Закрыть");
}

stock select_admin_promo_prize(playerid, type_prize_promo)
{

	switch(type_prize_promo)
	{
		case ADMIN_PRIZE_PROMO_START: return show_create_admin_promo_start(playerid);
		case ADMIN_PRIZE_PROMO_DYNAMIC: return select_params_promo_dynamic(playerid);
	}

	return true;
}

stock prefinall_create_promo_start(playerid)
{
	return SPD(playerid, DIALOG_SELECT_PROMO_START_P, DIALOG_STYLE_LIST, !""cBLUE"Выбор типа вознаграждения", \
	""cBLUE"1. "cWH"Набор новичка - 1", !"Выбрать", !"Закрыть");
}

stock select_params_promo_dynamic(playerid)
{

    format(String2048, sizeof(String2048), "\
        "cGREY"Тип приза\t"cGREY"Значение\t"cGREY"Статус\n\
        "cBLUE"1. "cWH"Денежные средства\t"cGR"%d\t%s\n\
        "cBLUE"2. "cWH"Количество EXP\t"cGR"%d\t%s\n\
        "cBLUE"3. "cWH"Скин\t"cGR"%d\t%s\n\
        "cBLUE"4. "cWH"Количество доната\t"cGR"%d\t%s\n\
        "cBLUE"5. "cWH"Транспортное средство\t"cGR"%d\t%s\n\
        "cBLUE"6. "cWH"Скилл на Макаров\t"cGR"%d\t%s\n\
        "cBLUE"7. "cWH"Скилл на Дигл\t"cGR"%d\t%s\n\
        "cBLUE"8. "cWH"Скилл на Дробовик\t"cGR"%d\t%s\n\
        "cBLUE"9. "cWH"Скилл на МП5\t"cGR"%d\t%s\n\
        "cBLUE"10. "cWH"Скилл на АК47\t"cGR"%d\t%s\n\
        "cBLUE"11. "cWH"Скилл на M4\t"cGR"%d\t%s\n\
        "cBLUE""cWH"\t\t\n\
        "cBLUE"- "cWH"Требуется отыграть\t"cGR"%d\tчасов\n\
        "cBLUE"- "cWH"Активен будет\t"cGR"%d\tдней\n\
        "cBLUE""cWH"\t\t\n\
        "cBLUE"- "cWH"С какого уровня\t"cGR"%d\t%s\n\
        "cBLUE"- "cWH"До какого уровня\t"cGR"%d\t%s\n\
        "cBLUE""cWH"\t\t\n\
        "cBLUE"- "cWH"Создать промокод",

        promocode_create[playerid][promocode_money_prize], (promocode_create[playerid][promocode_money_prize] > 0) ? (""cGR"Выбран") : (""cLRED"Отсутствует"),
        promocode_create[playerid][promocode_exp_prize], (promocode_create[playerid][promocode_exp_prize] > 0) ? (""cGR"Выбран") : (""cLRED"Отсутствует"),
        promocode_create[playerid][promocode_skin_prize], (promocode_create[playerid][promocode_skin_prize] > 0) ? (""cGR"Выбран") : (""cLRED"Отсутствует"),
        promocode_create[playerid][promocode_donate_prize], (promocode_create[playerid][promocode_donate_prize] > 0) ? (""cGR"Выбран") : (""cLRED"Отсутствует"),
        promocode_create[playerid][promocode_vehicle_prize], (promocode_create[playerid][promocode_vehicle_prize] > 0) ? (""cGR"Выбран") : (""cLRED"Отсутствует"),

        promocode_create[playerid][promocode_weapon_1_prize], (promocode_create[playerid][promocode_weapon_1_prize] > 0) ? (""cGR"Выбран") : (""cLRED"Отсутствует"),
        promocode_create[playerid][promocode_weapon_2_prize], (promocode_create[playerid][promocode_weapon_2_prize] > 0) ? (""cGR"Выбран") : (""cLRED"Отсутствует"),
        promocode_create[playerid][promocode_weapon_3_prize], (promocode_create[playerid][promocode_weapon_3_prize] > 0) ? (""cGR"Выбран") : (""cLRED"Отсутствует"),
        promocode_create[playerid][promocode_weapon_4_prize], (promocode_create[playerid][promocode_weapon_4_prize] > 0) ? (""cGR"Выбран") : (""cLRED"Отсутствует"),
        promocode_create[playerid][promocode_weapon_5_prize], (promocode_create[playerid][promocode_weapon_5_prize] > 0) ? (""cGR"Выбран") : (""cLRED"Отсутствует"),
        promocode_create[playerid][promocode_weapon_6_prize], (promocode_create[playerid][promocode_weapon_6_prize] > 0) ? (""cGR"Выбран") : (""cLRED"Отсутствует"),

        promocode_create[playerid][promocode_play_time], promocode_create[playerid][promocode_active_time],

        promocode_create[playerid][promocode_level_min], (promocode_create[playerid][promocode_level_min] > 0) ? (""cGR"Выбран") : (""cLRED"Не выбран"),
        promocode_create[playerid][promocode_level_max], (promocode_create[playerid][promocode_level_max] > 0) ? (""cGR"Выбран") : (""cLRED"Не выбран")

        );
    return SPD(playerid, DIALOG_SELECT_PROMO_DYNAMIC, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Выбор призов в промокоде:", String2048, !"Выбрать", !"Закрыть"); 
}

stock final_create_promo_dynamic(playerid)
{
	new 
		money_count[15],
		exp_count[15],
		skin_count[15],
		donate_count[15],
		vehicle_count[15],
		skill_count_1[15],
		skill_count_2[15],
		skill_count_3[15],
		skill_count_4[15],
		skill_count_5[15],
		skill_count_6[15];


	if(promocode_create[playerid][promocode_money_prize] > 0)
	{
		format(money_count, sizeof(money_count), "%d рублей", promocode_create[playerid][promocode_money_prize]);
	}
	else 
	{
		money_count = "Отсутствует";	
	}

	if(promocode_create[playerid][promocode_exp_prize] > 0)
	{
		format(exp_count, sizeof(exp_count), "%d EXP", promocode_create[playerid][promocode_exp_prize]);
	}
	else 
	{
		exp_count = "Отсутствует";	
	}

	if(promocode_create[playerid][promocode_skin_prize] > 0)
	{
		format(skin_count, sizeof(skin_count), "%d EXP", promocode_create[playerid][promocode_skin_prize]);
	}
	else 
	{
		skin_count = "Отсутствует";	
	}

	if(promocode_create[playerid][promocode_donate_prize] > 0)
	{
		format(donate_count, sizeof(donate_count), "%d EXP", promocode_create[playerid][promocode_donate_prize]);
	}
	else 
	{
		donate_count = "Отсутствует";	
	}

	if(promocode_create[playerid][promocode_vehicle_prize] > 0)
	{
		format(vehicle_count, sizeof(vehicle_count), "%d ID", promocode_create[playerid][promocode_vehicle_prize]);
	}
	else 
	{
		vehicle_count = "Отсутствует";	
	}


	if(promocode_create[playerid][promocode_weapon_1_prize] > 0)
	{
		format(skill_count_1, sizeof(skill_count_1), "%d", promocode_create[playerid][promocode_weapon_1_prize]);
	}
	else 
	{
		skill_count_1 = "Отсутствует";	
	}

	if(promocode_create[playerid][promocode_weapon_2_prize] > 0)
	{
		format(skill_count_2, sizeof(skill_count_2), "%d", promocode_create[playerid][promocode_weapon_2_prize]);
	}
	else 
	{
		skill_count_2 = "Отсутствует";	
	}

	if(promocode_create[playerid][promocode_weapon_3_prize] > 0)
	{
		format(skill_count_3, sizeof(skill_count_3), "%d", promocode_create[playerid][promocode_weapon_3_prize]);
	}
	else 
	{
		skill_count_3 = "Отсутствует";	
	}

	if(promocode_create[playerid][promocode_weapon_4_prize] > 0)
	{
		format(skill_count_4, sizeof(skill_count_4), "%d", promocode_create[playerid][promocode_weapon_4_prize]);
	}
	else 
	{
		skill_count_4 = "Отсутствует";	
	}

	if(promocode_create[playerid][promocode_weapon_5_prize] > 0)
	{
		format(skill_count_5, sizeof(skill_count_5), "%d", promocode_create[playerid][promocode_weapon_5_prize]);
	}
	else 
	{
		skill_count_5 = "Отсутствует";	
	}

	if(promocode_create[playerid][promocode_weapon_6_prize] > 0)
	{
		format(skill_count_6, sizeof(skill_count_6), "%d", promocode_create[playerid][promocode_weapon_6_prize]);
	}
	else 
	{
		skill_count_6 = "Отсутствует";	
	}

	new 
		promocode_name[20];

	format(promocode_name, 20, promocode_name_admin[playerid]);

	format(String1024, sizeof(String1024), "\
		"cWH"Создание промокода:\n\n\
		"cWH"Наименование промокода: "cBLUE"%s\n\n\
		"cWH"Количество денег: "cGR"%s"cWH"\n\n\
		"cWH"Скин: "cBLUE"%s"cWH"\n\
		"cWH"Доната: "cBLUE"%s"cWH"\n\
		"cWH"Транспорт: "cBLUE"%s"cWH"\n\
		"cWH"Скилл Макарова: "cBLUE"%s"cWH"\n\
		"cWH"Скилл Дигла: "cBLUE"%s"cWH"\n\
		"cWH"Скилл Дробовика: "cBLUE"%s"cWH"\n\
		"cWH"Скилл МП5: "cBLUE"%s"cWH"\n\
		"cWH"Скилл АК47: "cBLUE"%s"cWH"\n\
		"cWH"Скилл М4: "cBLUE"%s"cWH"\n\n\
		"cWH"Требуется отыграть: "cBLUE"%d"cWH" часов\n\
		"cWH"Активен будет: "cBLUE"%d"cWH" дней\n\
		"cWH"С какого уровня: "cBLUE"%s"cWH"\n\
		"cWH"До какого уровня: "cBLUE"%d"cWH"",promocode_name,
		money_count, exp_count, skin_count, donate_count, vehicle_count, skill_count_1, skill_count_2, skill_count_3, skill_count_4, skill_count_5, skill_count_6,
		promocode_create[playerid][promocode_play_time], promocode_create[playerid][promocode_active_time], promocode_create[playerid][promocode_level_min], promocode_create[playerid][promocode_level_max]);
	return SPD(playerid, DIALOG_FINAL_CREATE_DYNAMIC_P, DIALOG_STYLE_MSGBOX, !""cBLUE"Финал создания промкода", String1024, !"Далее", !"Закрыть");	
}

stock accept_create_promo_dynamic(playerid)
{
	new 
		promocode_name[20];

	format(promocode_name, 20, promocode_name_admin[playerid]);

	format(String2048, sizeof(String2048),"INSERT INTO `promocode`(`promocode_name`,`promocode_money`,`promocode_exp`,`promocode_skin`,`promocode_donate`,`promocode_vehicle`,`promocode_skill_1`,\
	`promocode_skill_2`,`promocode_skill_3`,`promocode_skill_4`,`promocode_skill_5`,`promocode_skill_6`,`promocode_count_player`,`promocode_count_day`,`promocode_count_level_min`,\
	`promocode_count_level_max`) VALUES ('%s','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d')",
	promocode_name, 
	promocode_create[playerid][promocode_money_prize],
	promocode_create[playerid][promocode_exp_prize],
	promocode_create[playerid][promocode_skin_prize],
	promocode_create[playerid][promocode_donate_prize],
	promocode_create[playerid][promocode_vehicle_prize],
	promocode_create[playerid][promocode_weapon_1_prize],
	promocode_create[playerid][promocode_weapon_2_prize],
	promocode_create[playerid][promocode_weapon_3_prize],
	promocode_create[playerid][promocode_weapon_4_prize],
	promocode_create[playerid][promocode_weapon_5_prize],
	promocode_create[playerid][promocode_weapon_6_prize],
	promocode_create[playerid][promocode_play_time],
	promocode_create[playerid][promocode_active_time],
	promocode_create[playerid][promocode_level_min],
	promocode_create[playerid][promocode_level_max]);
	sql_queryEx(zConn, String2048, QUERY_THREADED);			

	format(String128, sizeof(String128), "Промокод %s был успешно создан! Время работы промокода: %d дней!", promocode_name, promocode_create[playerid][promocode_active_time]);
	SendSucc(playerid, String128);	

	return true;
}

stock final_create_promo_free(playerid, type)
{
	new 
		promocode_name[20];

	format(promocode_name, 20, promocode_name_admin[playerid]);

	switch(type)
	{
		case 0:
		{

			new 
				promocode_name[20];

			format(promocode_name, 20, promocode_name_admin[playerid]);

			format(String2048, sizeof(String2048),"INSERT INTO `promocode`(`promocode_name`,`promocode_money`,`promocode_skin`,`promocode_donate`,`promocode_vehicle`,`promocode_skill_1`,\
			`promocode_skill_2`,`promocode_skill_3`,`promocode_skill_4`,`promocode_skill_5`,`promocode_skill_6`,`promocode_count_player`,`promocode_count_day`,`promocode_count_level_min`,\
			`promocode_count_level_max`) VALUES ('%s','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d')",
			promocode_name, 
			150000,
			55,
			200,
			0,
			100,
			0,
			0,
			100,
			0,
			15,
			360,
			1,
			5);
			sql_queryEx(zConn, String2048, QUERY_THREADED);			

			format(String128, sizeof(String128), "Промокод %s был успешно создан! Время работы промокода: %d дней!", promocode_name, 360);
			SendSucc(playerid, String128);				

		}
	}

	return true;
}

stock select_promo_dynamic_money(playerid)
{
	return SPD(playerid, DIALOG_PROMO_DYNAMIC_MONEY, DIALOG_STYLE_INPUT, !""cBLUE"Вознаграждение промокода", !"\
	"cWH"Введите количество денег, которые получит игрок", !"Далее", !"Назад");		
}

stock select_promo_dynamic_exp(playerid)
{
	return SPD(playerid, DIALOG_PROMO_DYNAMIC_EXP, DIALOG_STYLE_INPUT, !""cBLUE"Вознаграждение промокода", !"\
	"cWH"Введите количество EXP, которые получит игрок", !"Далее", !"Назад");		
}

stock select_promo_dynamic_skin(playerid)
{
	return SPD(playerid, DIALOG_PROMO_DYNAMIC_SKIN, DIALOG_STYLE_INPUT, !""cBLUE"Вознаграждение промокода", !"\
	"cWH"Введите ID скина, который получит игрок", !"Далее", !"Назад");		
}

stock select_promo_dynamic_donate(playerid)
{
	return SPD(playerid, DIALOG_PROMO_DYNAMIC_DONATE, DIALOG_STYLE_INPUT, !""cBLUE"Вознаграждение промокода", !"\
	"cWH"Введите количество доната, которое получит игрок", !"Далее", !"Назад");		
}

stock select_promo_dynamic_vehicle(playerid)
{
	return SPD(playerid, DIALOG_PROMO_DYNAMIC_VEHICLE, DIALOG_STYLE_INPUT, !""cBLUE"Вознаграждение промокода", !"\
	"cWH"Введите ID модели автомобиля, которое получит игрок", !"Далее", !"Назад");		
}

stock select_promo_dynamic_weapon_1(playerid)
{
	return SPD(playerid, DIALOG_PROMO_DYNAMIC_WEAPON_1, DIALOG_STYLE_INPUT, !""cBLUE"Вознаграждение промокода", !"\
	"cWH"Введите количесто скиллов, которое получит игрок на оружие Макаров", !"Далее", !"Назад");		
}

stock select_promo_dynamic_weapon_2(playerid)
{
	return SPD(playerid, DIALOG_PROMO_DYNAMIC_WEAPON_2, DIALOG_STYLE_INPUT, !""cBLUE"Вознаграждение промокода", !"\
	"cWH"Введите количесто скиллов, которое получит игрок на оружие Дигл", !"Далее", !"Назад");		
}

stock select_promo_dynamic_weapon_3(playerid)
{
	return SPD(playerid, DIALOG_PROMO_DYNAMIC_WEAPON_3, DIALOG_STYLE_INPUT, !""cBLUE"Вознаграждение промокода", !"\
	"cWH"Введите количесто скиллов, которое получит игрок на оружие Дробовик", !"Далее", !"Назад");		
}

stock select_promo_dynamic_weapon_4(playerid)
{
	return SPD(playerid, DIALOG_PROMO_DYNAMIC_WEAPON_4, DIALOG_STYLE_INPUT, !""cBLUE"Вознаграждение промокода", !"\
	"cWH"Введите количесто скиллов, которое получит игрок на оружие МП5", !"Далее", !"Назад");		
}

stock select_promo_dynamic_weapon_5(playerid)
{
	return SPD(playerid, DIALOG_PROMO_DYNAMIC_WEAPON_5, DIALOG_STYLE_INPUT, !""cBLUE"Вознаграждение промокода", !"\
	"cWH"Введите количесто скиллов, которое получит игрок на оружие АК47", !"Далее", !"Назад");		
}

stock select_promo_dynamic_weapon_6(playerid)
{
	return SPD(playerid, DIALOG_PROMO_DYNAMIC_WEAPON_6, DIALOG_STYLE_INPUT, !""cBLUE"Вознаграждение промокода", !"\
	"cWH"Введите количесто скиллов, которое получит игрок на оружие М4", !"Далее", !"Назад");		
}

stock select_promo_dynamic_player(playerid)
{
	return SPD(playerid, DIALOG_PROMO_DYNAMIC_PLAY, DIALOG_STYLE_INPUT, !""cBLUE"Вознаграждение промокода", !"\
	"cWH"Введите количесто часов, которое должны отыграть игроки для получения приза", !"Далее", !"Назад");		
}

stock select_promo_dynamic_active(playerid)
{
	return SPD(playerid, DIALOG_PROMO_DYNAMIC_ACTIVE, DIALOG_STYLE_INPUT, !""cBLUE"Вознаграждение промокода", !"\
	"cWH"Введите количесто дней, через которое промокод будет удалён", !"Далее", !"Назад");		
}

stock select_promo_dynamic_level_min(playerid)
{
	return SPD(playerid, DIALOG_PROMO_DYNAMIC_LEVEL_MIN, DIALOG_STYLE_INPUT, !""cBLUE"Вознаграждение промокода", !"\
	"cWH"Введите минимальный уровень активации промокода", !"Далее", !"Назад");		
}

stock select_promo_dynamic_level_max(playerid)
{
	return SPD(playerid, DIALOG_PROMO_DYNAMIC_LEVEL_MAX, DIALOG_STYLE_INPUT, !""cBLUE"Вознаграждение промокода", !"\
	"cWH"Введите максимальный уровень активации промокода", !"Далее", !"Назад");		
}


stock dialog_all_promo_admin(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
		case DIALOG_FINAL_CREATE_DYNAMIC_P:
		{
			if(!response)
				return select_params_promo_dynamic(playerid);	
			
			accept_create_promo_dynamic(playerid);

		}
		case DIALOG_CREATE_PROMO_A_Y:
		{
			if(!response)
				return true;
		
			if(strlen(inputtext) < 3 || strlen(inputtext) > 15)
			{
			    SendErr(playerid,"Слишком короткое/длинное наименование промокода!");
				return show_create_admin_promo(playerid);
			}

			if(IsNumeric(inputtext) || check_no_valid_symbol_text(inputtext) || check_sql_injection_text(inputtext))
			{
				show_create_admin_promo(playerid);
				return SendErr(playerid,"Название содержит запрещенные символы!");
			}		

		    for(new i = strlen(inputtext); i != 0; --i)
		    {
		        switch(inputtext[i])
		        {
		            case 'А'..'Я', 'а'..'я', ' ':
		            {
						show_create_admin_promo(playerid);
						return SendErr(playerid,"Название содержит запрещенные символы!");
		            }
		        }
		    }


			sql_escape_string(zConn, inputtext, promocode_name_admin[playerid], 35);	
			select_admin_promo_prize_m(playerid);
		}
		case DIALOG_CREATE_PROMO_A_Y_1:
		{
			if(!response)
				return true;
		
			if(strlen(inputtext) < 3 || strlen(inputtext) > 15)
			{
			    SendErr(playerid,"Слишком короткое/длинное наименование промокода!");
				return show_create_admin_promo_start(playerid);
			}

			if(IsNumeric(inputtext) || check_no_valid_symbol_text(inputtext) || check_sql_injection_text(inputtext))
			{
				show_create_admin_promo_start(playerid);
				return SendErr(playerid,"Название содержит запрещенные символы!");
			}		

		    for(new i = strlen(inputtext); i != 0; --i)
		    {
		        switch(inputtext[i])
		        {
		            case 'А'..'Я', 'а'..'я', ' ':
		            {
						show_create_admin_promo_start(playerid);
						return SendErr(playerid,"Название содержит запрещенные символы!");
		            }
		        }
		    }


			sql_escape_string(zConn, inputtext, promocode_name_admin[playerid], 35);	
			prefinall_create_promo_start(playerid);		
		}
		case DIALOG_SELECT_PROMO_START_P:
		{
			if(!response)
				return show_create_admin_promo_start(playerid);

			switch(listitem)
			{
				case 0:	return final_create_promo_free(playerid, 0);
			}

		}
		case DIALOG_SELECT_PROMO_A_Y:
		{
			if(!response)
				return show_create_admin_promo(playerid);

			switch(listitem)
			{
				case 0:	return select_admin_promo_prize(playerid, ADMIN_PRIZE_PROMO_START);
				case 1: return select_admin_promo_prize(playerid, ADMIN_PRIZE_PROMO_DYNAMIC);
			}
		}
		case DIALOG_SELECT_PROMO_DYNAMIC:
		{
			if(!response)
				return true;

			switch(listitem)
			{
				case 0:	return select_promo_dynamic_money(playerid);
				case 1: return select_promo_dynamic_exp(playerid);
				case 2: return select_promo_dynamic_skin(playerid);
				case 3: return select_promo_dynamic_donate(playerid);
				case 4: return select_promo_dynamic_vehicle(playerid);
				case 5: return select_promo_dynamic_weapon_1(playerid);
				case 6: return select_promo_dynamic_weapon_2(playerid);
				case 7: return select_promo_dynamic_weapon_3(playerid);
				case 8: return select_promo_dynamic_weapon_4(playerid);
				case 9: return select_promo_dynamic_weapon_5(playerid);
				case 10: return select_promo_dynamic_weapon_6(playerid);
				case 11: return select_params_promo_dynamic(playerid);
				case 12: return select_promo_dynamic_player(playerid);
				case 13: return select_promo_dynamic_active(playerid);
				case 14: return select_params_promo_dynamic(playerid);
				case 15: return select_params_promo_dynamic(playerid);
				case 16: return select_promo_dynamic_level_min(playerid);
				case 17: return select_promo_dynamic_level_max(playerid);
				case 18: return final_create_promo_dynamic(playerid);

			}			
		}


		case DIALOG_PROMO_DYNAMIC_LEVEL_MIN:
		{
			if(strval(inputtext) < 0)
			{
				select_promo_dynamic_level_min(playerid);
				return SendErr(playerid,"Неверное значение!");				
			}

			if(strval(inputtext) > 500)
			{
				select_promo_dynamic_level_min(playerid);
				return SendErr(playerid,"Неверное значение!");					
			}

			new 
				count_money_promo = strval(inputtext);

			promocode_create[playerid][promocode_level_min] = count_money_promo;

			format(String256, sizeof(String256), "Новый параметр минимального уровня промокода - "cGR"%d уровень", promocode_create[playerid][promocode_level_min]);
		    SendSucc(playerid, String256);

			select_params_promo_dynamic(playerid);			
		}
		case DIALOG_PROMO_DYNAMIC_LEVEL_MAX:
		{
			if(strval(inputtext) < 0)
			{
				select_promo_dynamic_level_max(playerid);
				return SendErr(playerid,"Неверное значение!");				
			}

			if(strval(inputtext) > 500)
			{
				select_promo_dynamic_level_max(playerid);
				return SendErr(playerid,"Неверное значение!");					
			}

			new 
				count_money_promo = strval(inputtext);

			promocode_create[playerid][promocode_level_max] = count_money_promo;

			format(String256, sizeof(String256), "Новый параметр максимального уровня промокода - "cGR"%d уровень", promocode_create[playerid][promocode_level_max]);
		    SendSucc(playerid, String256);

			select_params_promo_dynamic(playerid);			
		}
		case DIALOG_PROMO_DYNAMIC_PLAY:
		{

			if(strval(inputtext) < 0)
			{
				select_promo_dynamic_player(playerid);
				return SendErr(playerid,"Неверное значение!");				
			}

			if(strval(inputtext) > 30)
			{
				select_promo_dynamic_player(playerid);
				return SendErr(playerid,"Неверное значение!");					
			}

			new 
				count_money_promo = strval(inputtext);

			promocode_create[playerid][promocode_play_time] = count_money_promo;

			format(String256, sizeof(String256), "Новый параметр отыгрыша часов промокода - "cGR"%d часов", promocode_create[playerid][promocode_play_time]);
		    SendSucc(playerid, String256);

			select_params_promo_dynamic(playerid);			
		}
		case DIALOG_PROMO_DYNAMIC_ACTIVE:
		{

			if(strval(inputtext) < 0)
			{
				select_promo_dynamic_active(playerid);
				return SendErr(playerid,"Неверное значение!");				
			}

			if(strval(inputtext) > 30)
			{
				select_promo_dynamic_active(playerid);
				return SendErr(playerid,"Неверное значение!");					
			}

			new 
				count_money_promo = strval(inputtext);

			promocode_create[playerid][promocode_active_time] = count_money_promo;

			format(String256, sizeof(String256), "Новый параметр до удаления промокода - "cGR"%d часов", promocode_create[playerid][promocode_active_time]);
		    SendSucc(playerid, String256);

			select_params_promo_dynamic(playerid);			
		}
		case DIALOG_PROMO_DYNAMIC_MONEY:
		{


			if(strval(inputtext) < 0)
			{
				select_promo_dynamic_money(playerid);
				return SendErr(playerid,"Неверное значение!");				
			}

			if(strval(inputtext) > 1000000)
			{
				select_promo_dynamic_money(playerid);
				return SendErr(playerid,"Неверное значение!");					
			}

			new 
				count_money_promo = strval(inputtext);

			promocode_create[playerid][promocode_money_prize] = count_money_promo;

			format(String256, sizeof(String256), "Новый параметр денег промокода - "cGR"%d рублей", promocode_create[playerid][promocode_money_prize]);
		    SendSucc(playerid, String256);

			select_params_promo_dynamic(playerid);

			return true;
		}
		case DIALOG_PROMO_DYNAMIC_EXP:
		{

			if(strval(inputtext) < 0)
			{
				select_promo_dynamic_exp(playerid);
				return SendErr(playerid,"Неверное значение!");				
			}

			if(strval(inputtext) > 15)
			{
				select_promo_dynamic_exp(playerid);
				return SendErr(playerid,"Неверное значение!");					
			}			

			new 
				count_exp_promo = strval(inputtext);

			promocode_create[playerid][promocode_exp_prize] = count_exp_promo;

			format(String256, sizeof(String256), "Новый параметр EXP промокода - "cGR"%d EXP", promocode_create[playerid][promocode_exp_prize]);
		    SendSucc(playerid, String256);

			select_params_promo_dynamic(playerid);			
		}
		case DIALOG_PROMO_DYNAMIC_SKIN:
		{
			if(strval(inputtext) < 10)
			{
				select_promo_dynamic_skin(playerid);
				return SendErr(playerid,"Неверное значение!");				
			}

			if(strval(inputtext) > 288)
			{
				select_promo_dynamic_skin(playerid);
				return SendErr(playerid,"Неверное значение!");					
			}	

			new 
				count_skin_promo = strval(inputtext);

			promocode_create[playerid][promocode_skin_prize] = count_skin_promo;

			format(String256, sizeof(String256), "Новый параметр скин промокода - "cGR"%d скин", promocode_create[playerid][promocode_skin_prize]);
		    SendSucc(playerid, String256);

			select_params_promo_dynamic(playerid);	

		}
		case DIALOG_PROMO_DYNAMIC_DONATE:
		{
			if(strval(inputtext) < 10)
			{
				select_promo_dynamic_donate(playerid);
				return SendErr(playerid,"Неверное значение!");				
			}

			if(strval(inputtext) > 288)
			{
				select_promo_dynamic_donate(playerid);
				return SendErr(playerid,"Неверное значение!");					
			}	

			new 
				count_skin_promo = strval(inputtext);

			promocode_create[playerid][promocode_donate_prize] = count_skin_promo;

			format(String256, sizeof(String256), "Новый параметр доната промокода - "cGR"%d рублей", promocode_create[playerid][promocode_donate_prize]);
		    SendSucc(playerid, String256);

			select_params_promo_dynamic(playerid);	

		}

		case DIALOG_PROMO_DYNAMIC_VEHICLE:
		{

			if(strval(inputtext) < 10)
			{
				select_promo_dynamic_vehicle(playerid);
				return SendErr(playerid,"Неверное значение!");				
			}

			if(strval(inputtext) > 288)
			{
				select_promo_dynamic_vehicle(playerid);
				return SendErr(playerid,"Неверное значение!");					
			}	

			new 
				count_skin_promo = strval(inputtext);

			promocode_create[playerid][promocode_vehicle_prize] = count_skin_promo;

			format(String256, sizeof(String256), "Новый параметр транспорта промокода - "cGR"%d (%s) автомобиль", promocode_create[playerid][promocode_skin_prize], transport_config[GetVehicleModel(count_skin_promo)-400][transport_name]);
		    SendSucc(playerid, String256);

			select_params_promo_dynamic(playerid);	

		}

		case DIALOG_PROMO_DYNAMIC_WEAPON_1:
		{

			if(strval(inputtext) < 10)
			{
				select_promo_dynamic_weapon_1(playerid);
				return SendErr(playerid,"Неверное значение!");				
			}

			if(strval(inputtext) > 288)
			{
				select_promo_dynamic_weapon_1(playerid);
				return SendErr(playerid,"Неверное значение!");					
			}	

			new 
				count_skin_promo = strval(inputtext);

			promocode_create[playerid][promocode_weapon_1_prize] = count_skin_promo;

			format(String256, sizeof(String256), "Новый параметр скилла на Макаров промокода - "cGR"%d", promocode_create[playerid][promocode_weapon_1_prize]);
		    SendSucc(playerid, String256);

			select_params_promo_dynamic(playerid);	

		}
		case DIALOG_PROMO_DYNAMIC_WEAPON_2:
		{
			if(strval(inputtext) < 10)
			{
				select_promo_dynamic_weapon_2(playerid);
				return SendErr(playerid,"Неверное значение!");				
			}

			if(strval(inputtext) > 288)
			{
				select_promo_dynamic_weapon_2(playerid);
				return SendErr(playerid,"Неверное значение!");					
			}	

			new 
				count_skin_promo = strval(inputtext);

			promocode_create[playerid][promocode_weapon_2_prize] = count_skin_promo;

			format(String256, sizeof(String256), "Новый параметр скилла на Дигл промокода - "cGR"%d", promocode_create[playerid][promocode_weapon_2_prize]);
		    SendSucc(playerid, String256);

			select_params_promo_dynamic(playerid);	

		}
		case DIALOG_PROMO_DYNAMIC_WEAPON_3:
		{
			if(strval(inputtext) < 10)
			{
				select_promo_dynamic_weapon_3(playerid);
				return SendErr(playerid,"Неверное значение!");				
			}

			if(strval(inputtext) > 288)
			{
				select_promo_dynamic_weapon_3(playerid);
				return SendErr(playerid,"Неверное значение!");					
			}	

			new 
				count_skin_promo = strval(inputtext);

			promocode_create[playerid][promocode_weapon_3_prize] = count_skin_promo;

			format(String256, sizeof(String256), "Новый параметр скилла на Дробовик промокода - "cGR"%d", promocode_create[playerid][promocode_weapon_3_prize]);
		    SendSucc(playerid, String256);

			select_params_promo_dynamic(playerid);	

		}

		case DIALOG_PROMO_DYNAMIC_WEAPON_4:
		{
			if(strval(inputtext) < 10)
			{
				select_promo_dynamic_weapon_4(playerid);
				return SendErr(playerid,"Неверное значение!");				
			}

			if(strval(inputtext) > 288)
			{
				select_promo_dynamic_weapon_4(playerid);
				return SendErr(playerid,"Неверное значение!");					
			}	

			new 
				count_skin_promo = strval(inputtext);

			promocode_create[playerid][promocode_weapon_4_prize] = count_skin_promo;

			format(String256, sizeof(String256), "Новый параметр скилла на МП5 промокода - "cGR"%d", promocode_create[playerid][promocode_weapon_4_prize]);
		    SendSucc(playerid, String256);

			select_params_promo_dynamic(playerid);	

		}
		case DIALOG_PROMO_DYNAMIC_WEAPON_5:
		{
			if(strval(inputtext) < 10)
			{
				select_promo_dynamic_weapon_5(playerid);
				return SendErr(playerid,"Неверное значение!");				
			}

			if(strval(inputtext) > 288)
			{
				select_promo_dynamic_weapon_5(playerid);
				return SendErr(playerid,"Неверное значение!");					
			}	

			new 
				count_skin_promo = strval(inputtext);

			promocode_create[playerid][promocode_weapon_5_prize] = count_skin_promo;

			format(String256, sizeof(String256), "Новый параметр скилла на АК47 промокода - "cGR"%d", promocode_create[playerid][promocode_weapon_5_prize]);
		    SendSucc(playerid, String256);

			select_params_promo_dynamic(playerid);	

		}
		case DIALOG_PROMO_DYNAMIC_WEAPON_6:
		{

			if(strval(inputtext) < 10)
			{
				select_promo_dynamic_weapon_6(playerid);
				return SendErr(playerid,"Неверное значение!");				
			}

			if(strval(inputtext) > 288)
			{
				select_promo_dynamic_weapon_6(playerid);
				return SendErr(playerid,"Неверное значение!");					
			}	

			new 
				count_skin_promo = strval(inputtext);

			promocode_create[playerid][promocode_weapon_6_prize] = count_skin_promo;

			format(String256, sizeof(String256), "Новый параметр скилла на М4 промокода - "cGR"%d", promocode_create[playerid][promocode_weapon_6_prize]);
		    SendSucc(playerid, String256);

			select_params_promo_dynamic(playerid);	

		}
		case DIALOG_ACTIVATE_PROMO_ADMIN:
		{

			if(!response)
				return true;
		
			if(strlen(inputtext) < 3 || strlen(inputtext) > 15)
			{
			    SendErr(playerid,"Слишком короткое/длинное наименование промокода!");
				return show_activate_promo_admin(playerid);
			}

			if(IsNumeric(inputtext) || check_no_valid_symbol_text(inputtext) || check_sql_injection_text(inputtext))
			{
				show_activate_promo_admin(playerid);
				return SendErr(playerid,"Название содержит запрещенные символы!");
			}		

		    for(new i = strlen(inputtext); i != 0; --i)
		    {
		        switch(inputtext[i])
		        {
		            case 'А'..'Я', 'а'..'я', ' ':
		            {
						show_activate_promo_admin(playerid);
						return SendErr(playerid,"Название содержит запрещенные символы!");
		            }
		        }
		    }


			sql_escape_string(zConn, inputtext, promocode_name_admin[playerid], 35);	
			promocode_active_admin_pre(playerid);


		}
		case DIALOG_CHANGE_PROMOCODE_ADMIN:
		{
			if(!response)
				return true;

			new 
				id = dialog_listitem_values[playerid][listitem];

			change_admin_promocode_menu(playerid, id);
		}
		case DIALOG_CHANGE_PROMOCODE_FINAL:
		{
			if(!response)
				return show_admin_promo(playerid);

			new 
				promo_id = GetPVarIntNew(playerid, "promocode_admin_change");

			switch(listitem)
			{
				case 0: return change_admin_promocode_menu(playerid, promo_id);
				case 1: return change_admin_promocode_menu(playerid, promo_id);
				case 2: return dele_admin_promocode_menu(playerid, promo_id);

			}
		}
	}

	return true;
}




stock give_promocode_prize_admin(playerid, promocode_id)
{
	if(pData[playerid][promocode_admin] != -1)
	{

		pData[playerid][promocode_admin] = -1;
		UpdatePlayerData(playerid, "promocode_admin", pData[playerid][promocode_admin]);

		format(String256,sizeof(String256), "SELECT * FROM `promocode` WHERE `id` = '%d'", promocode_id);
		new Result:rjj = sql_queryEx(zConn,String256, QUERY_CACHED);

		new 
			promocode_names[20],
			promocode_admin_times,
			promocode_admin_money,
			promocode_admin_exp,
			promocode_admin_skin,
			promocode_admin_donate,
			promocode_admin_vehicle,
			promocode_admin_skill_1,
			promocode_admin_skill_2,
			promocode_admin_skill_3,
			promocode_admin_skill_4,
			promocode_admin_skill_5,
			promocode_admin_skill_6;

		if(sql_num_rows(rjj)) 	
		{

			format(String256,sizeof(String256),"UPDATE `promocode_player` SET `promocode_status` = 1 WHERE `promocode_id` = '%d'" , promocode_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	

			sql_get_field_assoc_ex(rjj, 0, "promocode_name", promocode_names, 20);	

			promocode_admin_money = sql_get_field_assoc_int_ex(rjj, 0, "promocode_money");
			promocode_admin_exp = sql_get_field_assoc_int_ex(rjj, 0, "promocode_exp");
			promocode_admin_skin = sql_get_field_assoc_int_ex(rjj, 0, "promocode_skin");
			promocode_admin_donate = sql_get_field_assoc_int_ex(rjj, 0, "promocode_donate");
			promocode_admin_vehicle = sql_get_field_assoc_int_ex(rjj, 0, "promocode_vehicle");
			promocode_admin_skill_1 = sql_get_field_assoc_int_ex(rjj, 0, "promocode_skill_1");
			promocode_admin_skill_2 = sql_get_field_assoc_int_ex(rjj, 0, "promocode_skill_2");
			promocode_admin_skill_3 = sql_get_field_assoc_int_ex(rjj, 0, "promocode_skill_3");
			promocode_admin_skill_4 = sql_get_field_assoc_int_ex(rjj, 0, "promocode_skill_4");
			promocode_admin_skill_5 = sql_get_field_assoc_int_ex(rjj, 0, "promocode_skill_5");
			promocode_admin_skill_6 = sql_get_field_assoc_int_ex(rjj, 0, "promocode_skill_6");

			if(promocode_admin_money > 0)
			{
				give_money(playerid, promocode_admin_money, "Деньги с промокода стороннего");
			}

			if(promocode_admin_exp > 0)
			{
				pData[playerid][pExp] += promocode_admin_exp;
				UpdatePlayerData(playerid, "exp", pData[playerid][pExp]);

				format(String64, sizeof(String64), "Вы получили %d EXP с промокода!", promocode_admin_exp);
				SendSucc(playerid, String64);

				if(pData[playerid][pExp] >= (pData[playerid][pLevel])*6)
				{
					pData[playerid][pExp] -= (pData[playerid][pLevel])*6;
					pData[playerid][pLevel]++;
					SetPlayerScore(playerid, pData[playerid][pLevel]);
					pData[playerid][pAge]++;

					UpdatePlayerData(playerid, "level", pData[playerid][pLevel]);
					UpdatePlayerData(playerid, "exp", pData[playerid][pExp]);
					UpdatePlayerData(playerid, "age", pData[playerid][pAge]);
					UpdatePlayerData(playerid, "zakon", pData[playerid][pZakon]);
					UpdatePlayerData(playerid, "bank", pData[playerid][pBank]);
					UpdatePlayerData(playerid, "wanted", pData[playerid][pWanted]);

					UpdatePlayerData(playerid, "count_time_payday", pData[playerid][hour_played]);

					SendSucc(playerid, "Поздравляем! Ваш игровой уровень повысился.");
					
				}				
			}

			if(promocode_admin_skin > 0)
			{
				pData[playerid][pSkin] = promocode_admin_skin;
				SetPlayerSkin(playerid, promocode_admin_skin);

				format(String64, sizeof(String64), "Вы получили %d одежду с промокода!", promocode_admin_skin);
				SendSucc(playerid, String64);

			}

			if(promocode_admin_donate > 0)
			{
				pData[playerid][pDonate] += promocode_admin_donate;
				UpdatePlayerData(playerid, "donate", pData[playerid][pDonate]);	

				format(String64, sizeof(String64), "Вы получили %d доната с промокода!", promocode_admin_donate);
				SendSucc(playerid, String64);

			}

			if(promocode_admin_skill_1)
			{
				pTemp[playerid][pGunSkill][1] = 100;
				SendSucc(playerid, "Вы получили максимальный навык на Дигл с промокода!");
			}
			if(promocode_admin_skill_2)
			{
				pTemp[playerid][pGunSkill][0] = 100;
				SendSucc(playerid, "Вы получили максимальный навык на макаров с промокода!");
			}
			if(promocode_admin_skill_3)
			{
				pTemp[playerid][pGunSkill][2] = 100;
				SendSucc(playerid, "Вы получили максимальный навык на дробовик с промокода!");
			}
			if(promocode_admin_skill_4)
			{
				pTemp[playerid][pGunSkill][3] = 100;
				SendSucc(playerid, "Вы получили максимальный навык на МП5 с промокода!");
			}
			if(promocode_admin_skill_5)
			{
				pTemp[playerid][pGunSkill][4] = 100;
				SendSucc(playerid, "Вы получили максимальный навык на АК47 с промокода!");
			}
			if(promocode_admin_skill_6)
			{
				pTemp[playerid][pGunSkill][5] = 100;
				SendSucc(playerid, "Вы получили максимальный навык на М4 с промокода!");
			}
		}
		sql_free_result(rjj);
	}


	return true;
}

stock show_activate_promo_admin(playerid)
{
	if(pData[playerid][promocode_admin] != -1)
	{

		format(String256,sizeof(String256), "SELECT * FROM `promocode` WHERE `id` = '%d'", pData[playerid][promocode_admin]);
		new Result:rjj = sql_queryEx(zConn,String256, QUERY_CACHED);

		new 
			promocode_names[20],
			promocode_admin_times;

		if(sql_num_rows(rjj)) 	
		{
			sql_get_field_assoc_ex(rjj, 0, "promocode_name", promocode_names, 20);	
			promocode_admin_times = sql_get_field_assoc_int_ex(rjj, 0, "promocode_count_player");

			format(String512, sizeof(String512), "\
				"cWH"Информация о промокоде:\n\n\
				"cWH"Наименование промокода: "cBLUE"%s\n\n\
				"cWH"Отыграно часов: "cGR"%s (Требуется: %d часов)"cWH"", promocode_names, time_to_words(pData[playerid][promocode_admin_time_player]), promocode_admin_times);
			SPD(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !""cBLUE"Активный сторонний промокод", String512, !"Закрыть", "");		
		}
		sql_free_result(rjj);
	}
    else
    {
    	SPD(playerid, DIALOG_ACTIVATE_PROMO_ADMIN, DIALOG_STYLE_INPUT, !""cBLUE"Активация промокода", !"\
    	"cWH"Введите промокод, который хотите активировать (не игрока)", !"Далее", !"Назад");    
    }
    return true;
}

stock promocode_active_admin_pre(playerid)
{
	new 
		promocode_id,
		promocode_admin_times,
		promocode_admin_level_1,
		promocode_admin_level_2;

	if(pData[playerid][promocode_admin] != -1)
		return SendErr(playerid, "У вас уже имеется активный промокод!");



	format(String256,sizeof(String256), "SELECT * FROM `promocode` WHERE `promocode_name` = '%s'", promocode_name_admin[playerid]);
	new Result:rj = sql_queryEx(zConn,String256, QUERY_CACHED);
	
	if(sql_num_rows(rj)) 
	{

		promocode_id = sql_get_field_assoc_int_ex(rj, 0, "id");
		promocode_admin_times = sql_get_field_assoc_int_ex(rj, 0, "promocode_count_player");
		promocode_admin_level_1 = sql_get_field_assoc_int_ex(rj, 0, "promocode_count_level_min");
		promocode_admin_level_2 = sql_get_field_assoc_int_ex(rj, 0, "promocode_count_level_max");

		format(String256,sizeof(String256), "SELECT * FROM `promocode_player` WHERE `promocode_id` = '%d' AND `promocode_userid` = '%d'", promocode_id, pData[playerid][pMysqlID]);
		new Result:rjj = sql_queryEx(zConn,String256, QUERY_CACHED);

		if(sql_num_rows(rjj)) 	
		{
			show_activate_promo_admin(playerid);
			sql_free_result(rjj);
			return SendErr(playerid, "Вы уже активировали данный промокод!");
		}
		else
		{

			if(pData[playerid][pLevel] < promocode_admin_level_1)
				return SendErr(playerid, "У Вас недостаточный уровень для активации промокода!");
			if(pData[playerid][pLevel] > promocode_admin_level_2)
				return SendErr(playerid, "У Вас слишком высокий уровень для активации промокода!");

			format(String512, sizeof(String512),"INSERT INTO `promocode_player`(`promocode_id`,`promocode_userid`) VALUES ('%d','%d')",
			promocode_id, pData[playerid][pMysqlID]);
			sql_queryEx(zConn, String512, QUERY_THREADED);	

			pData[playerid][promocode_admin_time] = promocode_admin_times;
			pData[playerid][promocode_admin] = promocode_id;

			UpdatePlayerData(playerid,"promocode_admin_time", pData[playerid][promocode_admin_time]);
			UpdatePlayerData(playerid,"promocode_admin", pData[playerid][promocode_admin]);

			format(String128, sizeof(String128), "Промокод %s был активирован, для получения приза нужно отыграть %d часов", promocode_name_admin[playerid], pData[playerid][promocode_admin_time]);
			SendSucc(playerid, String128);		

			show_activate_promo_admin(playerid);

		}
		sql_free_result(rjj);
	}
	else
	{
		SendErr(playerid, "Такой промокод не найден!");
		show_activate_promo_admin(playerid);
	}
	sql_free_result(rj);	


	return true;
}

CMD:alladminpromo(playerid)
{
    if(pData[playerid][pAdmin] < 8)
    	return NoCMD(playerid);	

	return show_admin_promo(playerid);
}

stock show_admin_promo(playerid)
{

	format(String4096, sizeof(String4096), ""cGREY"№. Имя\t"cGREY"Статистика\t"cGREY"Дата создания\n");

	new Result:promocode_find = sql_queryEx(zConn, "SELECT * FROM `promocode` ORDER BY `id`", QUERY_CACHED);

	new all_promocode_user = sql_num_rows(promocode_find);

	new 
		format_params_count = 0;

 	for(new i; i < all_promocode_user; i++)
	{
		new 
			promocode_name[20],
			promocode_date[20];

		sql_get_field_assoc_ex(promocode_find, i, "promocode_name", promocode_name, 20);
		sql_get_field_assoc_ex(promocode_find, i, "promocode_create_date", promocode_date, 20);

		new 
			count_player_not_get_promo,
			count_player_get_promo; 


		format(String1024, sizeof(String1024), "SELECT COUNT(promocode_id) FROM `promocode_player` WHERE `promocode_id` = '%d' AND `promocode_status` = '0'", i);
		new Result:promocode_find_1 = sql_queryEx(zConn, String1024, QUERY_CACHED);

		if(sql_num_rows(promocode_find_1)) 
		{
			count_player_not_get_promo = sql_get_field_assoc_int_ex(promocode_find_1, 0, "COUNT(promocode_id)");
		}
		sql_free_result(promocode_find_1);

		format(String1024, sizeof(String1024), "SELECT COUNT(promocode_id) FROM `promocode_player` WHERE `promocode_id` = '%d' AND `promocode_status` = '1'", i);
		new Result:promocode_find_2 = sql_queryEx(zConn, String1024, QUERY_CACHED);
		
		if(sql_num_rows(promocode_find_2)) 
		{
			count_player_get_promo = sql_get_field_assoc_int_ex(promocode_find_2, 0, "COUNT(promocode_id)");
		}
		sql_free_result(promocode_find_2);


		format(String4096, sizeof(String4096), "%s%d."cWH"%s\t"cLRED"%d человек | "cGR"%d человек\t"cGREY"%s\n",String4096, \
    	format_params_count+1, promocode_name, count_player_not_get_promo, count_player_get_promo, promocode_date);	

    	format_params_count++;	

	}
	sql_free_result(promocode_find);

	SPD(playerid, DIALOG_CHANGE_PROMOCODE_ADMIN, DIALOG_STYLE_TABLIST_HEADERS ,""cBLUE"Активные промокоды",String4096, !"Закрыть", "");
	return true;
}

stock change_admin_promocode_menu(playerid, promocode_id)
{
	SetPVarIntNew(playerid, "promocode_admin_change", promocode_id);


	format(String144,sizeof(String144), "SELECT * FROM `promocode` WHERE `id` = '%d'", promocode_id);
	new Result:rjj = sql_queryEx(zConn,String144, QUERY_CACHED);

	new 
		promocode_names[20],
		promocode_date[20];

	if(sql_num_rows(rjj)) 	
	{	
		sql_get_field_assoc_ex(rjj, 0, "promocode_name", promocode_names, 20);	
		sql_get_field_assoc_ex(rjj, 0, "promocode_create_date", promocode_date, 20);

	    format(String256, sizeof(String256), "\
        "cGREY"Промокод\t"cGREY"Управление\n\
        "cBLUE"- "cWH"%s\t"cGR"%s\n\
        "cBLUE"\t\n\
        "cBLUE"- "cWH"Удаление промокода\t"cGR"Удалить", 
        promocode_names, promocode_date);
	    SPD(playerid, DIALOG_CHANGE_PROMOCODE_FINAL, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Изменение промокода", String256, !"Выбрать", !"Закрыть"); 			
	}
	else
	{
		return SendErr(playerid, "Произошла техническая ошибка! Промокод не найден!");
	}

	sql_free_result(rjj);

	return true;
}

stock dele_admin_promocode_menu(playerid, promo_id)
{
    format(String144, sizeof(String144), "DELETE FROM `promocode` WHERE `id` = '%d'", promo_id);
    sql_queryEx(zConn, String144);	

    SendSucc(playerid, "Промокод был успешно удалён!");
	
	return show_admin_promo(playerid);
}