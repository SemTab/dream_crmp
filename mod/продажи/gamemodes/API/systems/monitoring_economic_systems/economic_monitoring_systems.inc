stock update_server_money_stats(money)
{
	new 
		query[256];

	if(money >= 0)
	{
		format(query,sizeof(query),"UPDATE `server_money_stats` SET `money_day_plus` =  money_day_plus+%i, `money_week_plus` =  money_week_plus+%i,\
			`money_month_plus` =  money_month_plus+%i, `money_all_plus` =  money_all_plus+%i", money, money, money, money);
		sql_queryEx(zConn, query);
	}
	else
	{
		format(query,sizeof(query),"UPDATE `server_money_stats` SET `money_day_lose` =  money_day_lose+%i, `money_week_lose` =  money_week_lose+%i,\
			`money_month_lose` =  money_month_lose+%i, `money_all_lose` =  money_all_lose+%i", money*-1, money*-1, money*-1, money*-1);
		sql_queryEx(zConn, query);
	}
	return true;
}

stock update_server_money_stats_week()
{
	if(day_player_week == 1)
	{
		sql_queryEx(zConn, "UPDATE `server_money_stats` SET `money_week_plus` =  0, `money_week_lose` =  0");
	}
	return true;
}

stock update_server_money_stats_month()
{
	new 
		day,month,year; 
	getdate(year,month,day);

	if(day == 1)
	{
		sql_queryEx(zConn, "UPDATE `server_money_stats` SET `money_month_plus` =  0, `money_month_lose` =  0");
	}
	return true;
}

stock update_server_money_stats_day()
{
	sql_queryEx(zConn, "UPDATE `server_money_stats` SET `money_day_plus` =  0, `money_day_plus` =  0");
}

CMD:moneystats(playerid)
{
	if(pData[playerid][pAdmin] < 8)
		return NoCMD(playerid);

	new Result:money_stats = sql_queryEx(zConn, "SELECT * FROM `server_money_stats`", QUERY_CACHED);

	new 
		day_plus = sql_get_field_assoc_int_ex(money_stats, 0, "money_day_plus"),
		week_plus = sql_get_field_assoc_int_ex(money_stats, 0, "money_week_plus"),
		month_plus = sql_get_field_assoc_int_ex(money_stats, 0, "money_month_plus"),
		all_plus = sql_get_field_assoc_int_ex(money_stats, 0, "money_all_plus"),

		day_lose = sql_get_field_assoc_int_ex(money_stats, 0, "money_day_lose"),
		week_lose = sql_get_field_assoc_int_ex(money_stats, 0, "money_week_lose"),
		month_lose = sql_get_field_assoc_int_ex(money_stats, 0, "money_month_lose"),
		all_lose = sql_get_field_assoc_int_ex(money_stats, 0, "money_all_lose");

	new 
		day_text[80];

	if(day_plus >= day_lose)
	{
		format(day_text, sizeof(day_text), ""cGR"получает "cBLUE"денег на %i рублей", day_plus-day_lose);
	}
	if(day_plus < day_lose)
	{
		format(day_text, sizeof(day_text), ""cLRED"теряет "cBLUE"денег на %i рублей", day_lose-day_plus);
	}

	new 
		week_text[80];

	if(week_plus >= week_lose)
	{
		format(week_text, sizeof(week_text), ""cGR"получает "cBLUE"денег на %i рублей", week_plus-week_lose);
	}
	if(week_plus < week_lose)
	{
		format(week_text, sizeof(week_text), ""cLRED"теряет "cBLUE"денег на %i рублей", week_lose-week_plus);
	}

	new 
		month_text[80];

	if(month_plus >= month_lose)
	{
		format(month_text, sizeof(month_text), ""cGR"получает "cBLUE"денег на %i рублей", month_plus-month_lose);
	}
	if(month_plus < month_lose)
	{
		format(month_text, sizeof(month_text), ""cLRED"теряет "cBLUE"денег на %i рублей", month_lose-month_plus);
	}

	new 
		all_text[80];

	if(all_plus >= all_lose)
	{
		format(all_text, sizeof(all_text), ""cGR"получает "cBLUE"денег на %i рублей", all_plus-all_lose);
	}
	if(all_plus < all_lose)
	{
		format(all_text, sizeof(all_text), ""cLRED"теряет "cBLUE"денег на %i рублей", all_lose-all_plus);
	}

	format(String2048, sizeof(String2048), "\
		"cWH"Получено денег на сервер за день: "cGREY"%i рублей\n\
		"cWH"Выведено денег с сервера за день: "cGREY"%i рублей\n\
		"cBLUE"Сервер %s\n\n\
		"cWH"Получено денег на сервер за неделю: "cGREY"%i рублей\n\
		"cWH"Выведено денег с сервера за неделю: "cGREY"%i рублей\n\
		"cBLUE"Сервер %s\n\n\
		"cWH"Получено денег на сервер за месяц: "cGREY"%i рублей\n\
		"cWH"Выведено денег с сервера за месяц: "cGREY"%i рублей\n\
		"cBLUE"Сервер %s\n\n\
		"cWH"Получено денег на сервер за всё время: "cGREY"%i рублей\n\
		"cWH"Выведено денег с сервера за всё время: "cGREY"%i рублей\n\
		"cBLUE"Сервер %s\n\n",
		day_plus, day_lose, day_text,
		week_plus, week_lose, week_text,
		month_plus, month_lose, month_text,
		all_plus, all_lose, all_text);

	return SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Статистика денег сервера", String2048, !"Закрыть", "");
}