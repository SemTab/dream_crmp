#define PROMOCODE_MAX_LEVEL_ACTIVE			4

CMD:promocode(playerid)
{
	return promocode_menu_general(playerid);
}

stock promocode_player_status_create(playerid)
{

	new 
		status_promo[50];

	switch(pData[playerid][pPromoFriend])
	{
		case 0: status_promo = ""cORANGE"Промокод не создан";
		case 1: status_promo = ""cGR"Промокод создан";
		case 2: status_promo = ""cLRED"Доступ заблокирован";

	}
	return status_promo;
}

stock promocode_player_status(playerid)
{

	new 
		status_promo[50];

	switch(pData[playerid][pPromoFriendActive])
	{
		case 0: status_promo = ""cORANGE"Промокод не активирован";
		case 1: status_promo = ""cGR"Промокод активирован";
		case 2: status_promo = ""cLRED"Активация недоступна";
	}
	return status_promo;
}

stock promocode_menu_general(playerid)
{

    format(String512, sizeof(String512), "\
    "cGREY"Тип\t"cGREY"Информация\t"cGREY"Действие\n\
    "cBLUE"1. "cWH"Личный промокод для друзей\t%s\tОткрыть\n\
    "cBLUE"2. "cWH"Активация промокода друга\t%s\tОткрыть\n\
    "cBLUE"3. "cWH"Активация сторонних промокодов\t%s\tОткрыть", promocode_player_status_create(playerid), promocode_player_status(playerid),
    (pData[playerid][promocode_admin] != -1) ? (""cGR"Имеется активный") : (""cLRED"Нет активных"));
    return SPD(playerid, DIALOG_MENU_PROMOCODE, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Промокоды", String512, !"Выбрать", !"Закрыть"); 			
}



stock menu_friend_promocode(playerid)
{

	new 
		promocode_create = pData[playerid][pPromoFriend];

	new 
		promocode_name[20];

	if(promocode_create == 0)
	{
	    format(String320, sizeof(String320), "\
	    "cGREY"Тип\t"cGREY"Информация\n\
	    "cBLUE"- "cWH"Создать промокод игрока\t"cBLUE"Создать");
	    SPD(playerid, DIALOG_CREATE_PROMOCODE_FRIEND, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Индивидуальный промокод", String320, !"Выбрать", !"Закрыть"); 
	}
	else if(promocode_create == 1)
	{
		format(String1024, sizeof(String1024), "SELECT * FROM promocode_friend WHERE promocode_userid = '%d' LIMIT 1", pData[playerid][pMysqlID]);
		new Result:promocode_find = sql_queryEx(zConn, String1024, QUERY_CACHED);

		if(sql_num_rows(promocode_find)) 
		{
			sql_get_field_assoc_ex(promocode_find, 0, "promocode_name", promocode_name, 20);
			
		    format(String512, sizeof(String512), "\
		    "cGREY"Тип\t"cGREY"Информация\n\
		    "cBLUE"1. "cWH"Текущий промокод\t"cBLUE"%s\n\
		    "cBLUE"2. "cWH"Информация о активациях промокода\t"cBLUE"Посмотреть\n\
		    "cBLUE"3. "cWH"Общая статистика промокода\t"cBLUE"Посмотреть", promocode_name);
		    SPD(playerid, DIALOG_INFO_PROMO_FRIEND, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Индивидуальный промокод", String512, !"Выбрать", !"Закрыть"); 			

		}
		sql_free_result(promocode_find);

	}
	else if(promocode_create == 2)
	{
   		SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Индивидуальный промокод (Блокировка)", \
        ""cWH"Вам запрещено создавать промокоды!\n\n\
        "cBLUE"Если у Вас возникли вопросы, то обратитесь на форум проекта", !"Понял", "");

	}	
	return true;
}

stock menu_activate_promocode(playerid)
{
	if(pData[playerid][pPromoFriendActive] == 1)
		return show_menu_active_promo_p(playerid);

	if(pData[playerid][pLevel] >= PROMOCODE_MAX_LEVEL_ACTIVE)
	{
		promocode_menu_general(playerid);
		return SendErr(playerid, "Вы уже достигли 4-го уровня и не можете активировать промокод друга!");
	}

	format(String512, sizeof(String512), "\
	"cWH"Вы можете ввести промокод Вашего друга, чтобы при достижении 4-го уровня\n\
	получить вознаграждение за активацию промокода\n\n\
	Так же при каждом пополнении донат-счёта Ваш друг будет получать 20 процентов\n\
	от суммы пополнения счёта!\n\n\
	Введите наименование промокода друга:");
	return SPD(playerid, DIALOG_ACTIVE_PROMO_FRIEND, DIALOG_STYLE_INPUT, !""cBLUE"Активация промокода", String512, !"Далее", !"Назад");	

}

stock show_menu_active_promo_p(playerid)
{

	format(String1024, sizeof(String1024), "SELECT * FROM promocode_friend_active WHERE promocode_activate_user_id	= '%d' LIMIT 1", pData[playerid][pMysqlID]);
	new Result:promocode_find = sql_queryEx(zConn, String1024, QUERY_CACHED);

	if(sql_num_rows(promocode_find)) 
	{
		new 
			promocode_user_create,
			promocode_donate_percent_count,
			promocode_name[20],
			promocode_date_active[20];

		sql_get_field_assoc_ex(promocode_find, 0, "promocode_activate_date", promocode_date_active, 20);

		promocode_donate_percent_count = sql_get_field_assoc_int_ex(promocode_find, 0, "promocode_donate_percent_count");

		promocode_user_create = sql_get_field_assoc_int_ex(promocode_find, 0, "promocode_userid_create");


		format(String1024, sizeof(String1024), "SELECT * FROM promocode_friend WHERE promocode_userid = '%d' LIMIT 1", promocode_user_create);
		new Result:promocode_finds = sql_queryEx(zConn, String1024, QUERY_CACHED);

		if(sql_num_rows(promocode_finds)) 
		{
			sql_get_field_assoc_ex(promocode_finds, 0, "promocode_name", promocode_name, 20);	
		}
		sql_free_result(promocode_finds);	

	    format(String512, sizeof(String512), "\
	    "cGREY"Тип\t"cGREY"Информация\n\
	    "cBLUE"1. "cWH"Текущий промокод\t"cBLUE"%s\n\
	    "cBLUE"2. "cWH"Дата активации\t"cBLUE"%s\n\
	    "cBLUE"3. "cWH"С пополнений друг получил\t"cBLUE"%d"cWH" донат-очков", promocode_name, promocode_date_active, promocode_donate_percent_count);
	    SPD(playerid, DIALOG_CLOSE_ACTIVE_PROMO, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Активированный промокод", String512, !"Выбрать", !"Закрыть"); 			

	}
	sql_free_result(promocode_find);

	return true;
}

stock show_stats_promo_general(playerid)
{
	new 
		count_player_not_get_promo,
		count_player_get_promo,
		promocode_donate_percent_count,
		promocode_name[20],
		promocode_date_active[20];

	format(String1024, sizeof(String1024), "SELECT * FROM promocode_friend WHERE promocode_userid = '%d' LIMIT 1", pData[playerid][pMysqlID]);
	new Result:promocode_find = sql_queryEx(zConn, String1024, QUERY_CACHED);

	if(sql_num_rows(promocode_find)) 
	{
		sql_get_field_assoc_ex(promocode_find, 0, "promocode_name", promocode_name, 20);	
		sql_get_field_assoc_ex(promocode_find, 0, "promocode_create_date", promocode_date_active, 20);	

		promocode_donate_percent_count = sql_get_field_assoc_int_ex(promocode_find, 0, "promocode_donate_percent_count");		
	}
	sql_free_result(promocode_find);	

	format(String1024, sizeof(String1024), "SELECT COUNT(promocode_friend_id) FROM `promocode_friend_active` WHERE `promocode_userid_create` = '%d' AND `promocode_activate_status` = '1'", pData[playerid][pMysqlID]);
	new Result:promocode_find_1 = sql_queryEx(zConn, String1024, QUERY_CACHED);

	if(sql_num_rows(promocode_find_1)) 
	{
		count_player_not_get_promo = sql_get_field_assoc_int_ex(promocode_find_1, 0, "COUNT(promocode_friend_id)");
	}
	sql_free_result(promocode_find_1);

	format(String1024, sizeof(String1024), "SELECT COUNT(promocode_friend_id) FROM `promocode_friend_active` WHERE `promocode_userid_create` = '%d' AND `promocode_activate_status` = '2'", pData[playerid][pMysqlID]);
	new Result:promocode_find_2 = sql_queryEx(zConn, String1024, QUERY_CACHED);
	
	if(sql_num_rows(promocode_find_2)) 
	{
		count_player_get_promo = sql_get_field_assoc_int_ex(promocode_find_2, 0, "COUNT(promocode_friend_id)");
	}
	sql_free_result(promocode_find_2);

    format(String512, sizeof(String512), "\
    "cGREY"Тип\t"cGREY"Информация\n\
    "cBLUE"1. "cWH"Текущий промокод\t"cBLUE"%s\n\
    "cBLUE"2. "cWH"Дата создания\t"cBLUE"%s\n\
    "cBLUE"3. "cWH"Получило бонус с промокода\t"cBLUE"%d"cWH" человек(а)\n\
    "cBLUE"4. "cWH"Не получило бонус с промокода\t"cBLUE"%d"cWH" человек(а)\n\
    "cBLUE"5. "cWH"Получено донат-очков\t"cBLUE"%d"cWH" донат-очков", promocode_name, promocode_date_active, count_player_get_promo, count_player_not_get_promo, promocode_donate_percent_count);
    SPD(playerid, DIALOG_CLOSE_ACTIVE_PROMO, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Индивидуальный промокод", String512, !"Выбрать", !"Закрыть"); 			

    return true;

}


stock create_promocode_menu(playerid)
{

	format(String512, sizeof(String512), "\
	"cWH"Вы можете создать промокод, который будет использовать для приглашения\n\
	Ваших друзей на сервер и они смогут получить бонус при достижении 4-го уровня\n\
	Так же Вы получите бонус за достижение Ваших друзей 4-го уровня\n\n\
	При пополнении донат-счета Вашими друзьями, Вы будете получать 20 процентов\n\
	с их пополнения на свой донат-счёт\n\n\
	Введите наименование Вашего промокода для друзей:\n\n\
	"cBLUE"Можно использовать от 3 до 15 символов в наименовании!");

	return SPD(playerid, DIALOG_CREATE_PROMO_NAME, DIALOG_STYLE_INPUT, !""cBLUE"Создание промокода", String512, !"Далее", !"Назад");

}


stock show_friend_promo_stats(playerid)
{

	format(String4096, sizeof(String4096), ""cGREY"№. Имя\t"cGREY"Уровень\t"cGREY"Дата активации\n");

	format(String1024, sizeof(String1024), "SELECT * FROM promocode_friend_active WHERE promocode_userid_create = '%d' ORDER BY `promocode_activate_date`", pData[playerid][pMysqlID]);
	new Result:promocode_find = sql_queryEx(zConn, String1024, QUERY_CACHED);

	new all_promocode_user = sql_num_rows(promocode_find);

	new 
		format_params_count = 0;

 	for(new i; i < all_promocode_user; i++)
	{
		new 
			player_promo_date_active[20],
			player_promo_name[32],
			player_promo_sql_id,
			player_promo_level;

		player_promo_sql_id = sql_get_field_assoc_int_ex(promocode_find, i, "promocode_activate_user_id");

		GetPlayerNameByID(player_promo_sql_id, player_promo_name);

		sql_get_field_assoc_ex(promocode_find, i, "promocode_activate_date", player_promo_date_active, 20);

		format(String144,sizeof(String144),"SELECT `level` FROM `accounts` WHERE `id` = '%d'",player_promo_sql_id);
		new Result:level_sql = sql_queryEx(zConn, String144, QUERY_CACHED);

	  	if(!sql_num_rows(level_sql)) 
	  	{
		  sql_free_result(level_sql);
		  return 1;
		}

	  	player_promo_level = sql_get_field_assoc_int_ex(level_sql, 0, "level");
		sql_free_result(level_sql);		

		format(String4096, sizeof(String4096), "%s%d."cWH"%s\t%d\t%s\n",String4096, \
    	format_params_count+1, player_promo_name, player_promo_level, player_promo_date_active);	

    	format_params_count++;	

	}
	sql_free_result(promocode_find);

	SPD(playerid, DIALOG_STATS_PROMO_CLOSE, DIALOG_STYLE_TABLIST_HEADERS ,""cBLUE"Статистика промокода",String4096, !"Закрыть", "");
	return true;
}


stock dialog_promocode_friend(playerid, dialogid, response, listitem, inputtext[])
{


	switch(dialogid)
	{
		case DIALOG_STATS_PROMO_CLOSE:
		{
			if(!response)
				return menu_friend_promocode(playerid);					
		}
		case DIALOG_CLOSE_ACTIVE_PROMO:
		{
			if(!response)
				return promocode_menu_general(playerid);					
		}
		case DIALOG_CREATE_PROMO_NAME:
		{
			if(!response)
				return menu_friend_promocode(playerid);		
				
			if(strlen(inputtext) < 3 || strlen(inputtext) > 15)
			{
			    SendErr(playerid,"Слишком короткое/длинное наименование промокода!");
				return create_promocode_menu(playerid);
			}
			if(IsNumeric(inputtext) || check_no_valid_symbol_text(inputtext) || check_sql_injection_text(inputtext))
			{
				create_promocode_menu(playerid);
				return SendErr(playerid,"Название содержит запрещенные символы!");
			}			
		    for(new i = strlen(inputtext); i != 0; --i)
		    {
		        switch(inputtext[i])
		        {
		            case 'А'..'Я', 'а'..'я', ' ':
		            {
						create_promocode_menu(playerid);
						return SendErr(playerid,"Название содержит запрещенные символы!");
		            }
		        }
		    }


 			format(String2048, sizeof(String2048), "SELECT * FROM `promocode_friend` WHERE `promocode_name` = '%s'", inputtext);

			new 
				Result:r3 = sql_queryEx(zConn, String2048, QUERY_CACHED);

			new 
				name_promocode_sql = sql_num_rows(r3);

	        sql_free_result(r3);

			if(name_promocode_sql)
			{
			    SendErr(playerid,"Данное название промокода недоступно!");
				return create_promocode_menu(playerid);
			}			

			new 
				promocode_name[16];

			format(promocode_name, 20, inputtext);

			format(String1024, sizeof(String1024),"INSERT INTO `promocode_friend`(`promocode_userid`,`promocode_name`,`promocode_status`) VALUES ('%d','%s','%d')",
			pData[playerid][pMysqlID], promocode_name, 1);
			sql_queryEx(zConn, String1024, QUERY_THREADED);			

			pData[playerid][pPromoFriend] = 1;
			UpdatePlayerData(playerid,"pPromoFriend", pData[playerid][pPromoFriend]);

			SendInf(playerid, "Вы успешно создали промокод для друзей!");
			SendInf(playerid, "Теперь Ваши друзья могут указывать Ваш промокод и получать бонус при достижении 4-го уровня!");
			SendInf(playerid, "Так же Вы будете получать 20 процентов с пополнения доната Ваших друзей!");

			menu_friend_promocode(playerid);

		}
		case DIALOG_CREATE_PROMOCODE_FRIEND:
		{
			if(!response)
				return true;

			switch(listitem)
			{
				case 0: return create_promocode_menu(playerid);
			}
		}
		case DIALOG_INFO_PROMO_FRIEND:
		{
			if(!response)
				return true;

			switch(listitem)
			{
				case 0: return menu_friend_promocode(playerid);
				case 1: return show_friend_promo_stats(playerid);
				case 2: return show_stats_promo_general(playerid);
			}			
		}
	    case DIALOG_MENU_PROMOCODE: 
	    {

			if(!response)
				return true;

			switch(listitem)
			{
				case 0: return menu_friend_promocode(playerid);
				case 1: return menu_activate_promocode(playerid);
				case 2: return show_activate_promo_admin(playerid);
			}	

	    }
	    case DIALOG_ACTIVE_PROMO_FRIEND:
	    {
			if(!response)
				return promocode_menu_general(playerid);		
				
			if(strlen(inputtext) < 3 || strlen(inputtext) > 15)
			{
			    SendErr(playerid,"Слишком короткое/длинное наименование промокода!");
				return menu_activate_promocode(playerid);
			}
			if(IsNumeric(inputtext) || check_no_valid_symbol_text(inputtext) || check_sql_injection_text(inputtext))
			{
				menu_activate_promocode(playerid);
				return SendErr(playerid,"Название содержит запрещенные символы!");
			}			
		    for(new i = strlen(inputtext); i != 0; --i)
		    {
		        switch(inputtext[i])
		        {
		            case 'А'..'Я', 'а'..'я', ' ':
		            {
						menu_activate_promocode(playerid);
						return SendErr(playerid,"Название содержит запрещенные символы!");
		            }
		        }
		    }

			new 
				promocode_userid_cr,
				promocode_status_active;



			format(String1024, sizeof(String1024), "SELECT * FROM promocode_friend WHERE promocode_name = '%s' LIMIT 1", inputtext);
			new Result:promocode_find = sql_queryEx(zConn, String1024, QUERY_CACHED);

			if(sql_num_rows(promocode_find)) 
			{
				promocode_userid_cr = sql_get_field_assoc_int_ex(promocode_find, 0, "promocode_userid");
				promocode_status_active = sql_get_field_assoc_int_ex(promocode_find, 0, "promocode_status");
			}
			sql_free_result(promocode_find);

			if(promocode_userid_cr == pData[playerid][pMysqlID])
			{
				menu_activate_promocode(playerid);
				return SendErr(playerid, "Вы не можете активировать свой промокод!");
			}

			if(promocode_status_active == 2)
			{
				menu_activate_promocode(playerid);
				return SendErr(playerid, "Данный промокод недоступен для активации!");
			}

			format(String1024, sizeof(String1024),"INSERT INTO `promocode_friend_active`(`promocode_userid_create`,`promocode_activate_user_id`) VALUES ('%d','%d')",
			promocode_userid_cr, pData[playerid][pMysqlID]);
			sql_queryEx(zConn, String1024, QUERY_THREADED);			

			pData[playerid][pPromoFriendActive] = 1;
			UpdatePlayerData(playerid,"pPromoFriendActive", pData[playerid][pPromoFriendActive]);

			pData[playerid][pPromoActiveID] = promocode_userid_cr;
			UpdatePlayerData(playerid,"pPromoActiveID", pData[playerid][pPromoActiveID]);


			SendInf(playerid, "Вы успешно активировали промокод друга!");
			SendInf(playerid, "Теперь при достижении 4-го уровня Вы получите бонус!");
			SendInf(playerid, "Так же создатель промокода будет получать 20 процентов с пополнения Вами донат-счёта!");

			promocode_menu_general(playerid);
	    }

	}
	return true;
}


stock check_promocode_prize(playerid)
{

	new 
		promocode_creator_id = pData[playerid][pPromoActiveID];

	if(pData[playerid][pMysqlID] == promocode_creator_id)
		return SendErr(playerid, "Возникла системная ошибка №301. Сообщите на форум!");

	format(String256,sizeof(String256),"UPDATE `promocode_friend_active` SET `promocode_activate_status` = 2 WHERE `promocode_activate_user_id` = '%d'" , pData[playerid][pMysqlID]);
	mysql_tquery(connect_main, String256);

	pData[playerid][promocode_bonus_active] = 1;
	UpdatePlayerData(playerid, "promocode_bonus_active", pData[playerid][promocode_bonus_active]);	
	
	give_money(playerid, 50000, "Бонус за промокод");


	SendInf(playerid, "На ваш банковский счет добавлено 50.000P за введенный промокод!");	
	SendInf(playerid, "Ваш друг получил 50.000 рублей за получение Вами 4-го уровня!");	


	new 
		owner_promocode_name[32];

	GetPlayerNameByID(promocode_creator_id, owner_promocode_name);

	new 
		player_id = GetPlayerID(owner_promocode_name);

	if(IsPlayerConnected(player_id))
	{
		if(pData[player_id][pMysqlID] == promocode_creator_id)
		{	

			pData[player_id][pBank] += 50000;

			SendInf(player_id, "На ваш банковский счет добавлено 50.000P за приглашенного друга");	
			SendInf(playerid, "Ваш друг получил 50.000 рублей за получение Вами 4-го уровня!");	

			format(String256,sizeof(String256),"UPDATE `accounts` SET `bankstore2` = bankstore2 + %i WHERE `id` = '%d'", 1, promocode_creator_id);
	        mysql_tquery(connect_main, String256);

		}
	}
	else
	{	
        format(String256,sizeof(String256),"UPDATE `accounts` SET bank = bank + 50000 WHERE `id` = '%d'", promocode_creator_id);
        mysql_tquery(connect_main, String256);

		format(String256,sizeof(String256),"UPDATE `accounts` SET `bankstore2` = bankstore2 + %i WHERE `id` = '%d'", 1, promocode_creator_id);
        mysql_tquery(connect_main, String256);
        
        SendInf(playerid, "Ваш друг получил 50.000 рублей за получение Вами 4-го уровня!");

	}


	return true;
}

stock check_promocode_donate_percent(playerid, sum)
{
	new 
		promocode_creator_id = pData[playerid][pPromoActiveID];

	if(pData[playerid][pMysqlID] == promocode_creator_id)
		return SendErr(playerid, "Возникла системная ошибка №301. Сообщите на форум!");

	format(String256,sizeof(String256),"UPDATE `promocode_friend_active` SET `promocode_activate_status` = 2 WHERE `promocode_activate_user_id` = '%d'" , pData[playerid][pMysqlID]);
	sql_queryEx(zConn, String256, QUERY_THREADED);	



	new 
		owner_promocode_name[32];

	GetPlayerNameByID(promocode_creator_id, owner_promocode_name);

	new 
		player_id = GetPlayerID(owner_promocode_name);

	if(IsPlayerConnected(player_id))
	{
		if(pData[player_id][pMysqlID] == promocode_creator_id)
		{	

			pData[player_id][pDonate] += floatround(sum*0.2);

			SendInf(player_id, "Вы получили процент с доната с Вашего реферала!");	

			format(String256,sizeof(String256),"UPDATE `accounts` SET `donate` = donate + %i WHERE `id` = '%d'", 1, promocode_creator_id);
	        sql_queryEx(zConn, String256, QUERY_THREADED);

			format(String256,sizeof(String256),"UPDATE `promocode_friend_active` SET `promocode_donate_percent_count` = `promocode_donate_percent_count`+%d WHERE `promocode_userid_create` = '%d'" , floatround(sum*0.2), promocode_creator_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	

		}
	}
	else
	{	
        format(String256,sizeof(String256),"UPDATE `accounts` SET donate = donate + %d WHERE `id` = '%d'", floatround(sum*0.2), promocode_creator_id);
        sql_queryEx(zConn, String256, QUERY_THREADED);

		format(String256,sizeof(String256),"UPDATE `promocode_friend_active` SET `promocode_donate_percent_count` = `promocode_donate_percent_count`+%d WHERE `promocode_userid_create` = '%d'" , floatround(sum*0.2), promocode_creator_id);
		sql_queryEx(zConn, String256, QUERY_THREADED);	

	}


	return true;
}


CMD:banpromop(playerid, params[])
{

	if(pData[playerid][pAdmin] < 8) 
		return NoCMD(playerid);

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/banpromop [ID]");


	pData[params[0]][pPromoFriend] = 2;
	UpdatePlayerData(params[0],"pPromoFriend", pData[params[0]][pPromoFriend]);


	SendInf(playerid, "Вы успешно заблокировали возможность игроку создавать промокоды!");

	return true;
}


CMD:closepromop(playerid, params[])
{

	if(pData[playerid][pAdmin] < 8) 
		return NoCMD(playerid);

	if(sscanf(params, "s[32]", params[0])) 
		return SendInf(playerid, "/closepromop [Наименование]");

	format(String256,sizeof(String256), "SELECT * FROM `promocode_friend` WHERE `promocode_name` = '%s'", params[0]);
	new Result:rj = sql_queryEx(zConn,String256, QUERY_CACHED);
	
	if(sql_num_rows(rj)) 
	{
		format(String256,sizeof(String256),"UPDATE `promocode_friend` SET `promocode_status` = 2 WHERE `promocode_name` = '%s'" ,params[0]);
		sql_queryEx(zConn, String256, QUERY_THREADED);	
		SendInf(playerid, "Промокод успешно деактивирован");
	}
	sql_free_result(rj);	

	return true;
}

CMD:openpromop(playerid, params[])
{

	if(pData[playerid][pAdmin] < 8) 
		return NoCMD(playerid);

	if(sscanf(params, "s[32]", params[0])) 
		return SendInf(playerid, "/openpromop [Наименование]");

	format(String256,sizeof(String256), "SELECT * FROM `promocode_friend` WHERE `promocode_name` = '%s'", params[0]);
	new Result:rj = sql_queryEx(zConn,String256, QUERY_CACHED);
	
	if(sql_num_rows(rj)) 
	{
		format(String256,sizeof(String256),"UPDATE `promocode_friend` SET `promocode_status` = 1 WHERE `promocode_name` = '%s'" ,params[0]);
		sql_queryEx(zConn, String256, QUERY_THREADED);	
		SendInf(playerid, "Промокод успешно активирован");
	}
	sql_free_result(rj);	

	return true;
}