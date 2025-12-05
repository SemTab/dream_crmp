#define MAX_REPORT_COUNT 1000

new
	rep_id[MAX_REPORT_COUNT] = 0,
	rep_player[MAX_REPORT_COUNT] = INVALID_PLAYER_ID,
	rep_text[MAX_REPORT_COUNT][128],
	rep_time[MAX_REPORT_COUNT];

new 
	report_avg_time,
	report_all_answer,
	report_count,
	type_report;

callback:: load_report_systems() 
{
	new Result:report_load = sql_query(zConn, "SELECT * FROM `serverdata`", QUERY_CACHED);

	new time = GetTickCount();
	
	if(sql_num_rows(report_load))
	{
		type_report = sql_get_field_assoc_int_ex(report_load, 0, "type_report");
	}	

	printf("[Репорт]: Времени затрачено: <%d мс>", GetTickCount() -  time);
	sql_free_result(report_load);
}

stock show_report_dialog(playerid)
{
	SPD(playerid, DIALOG_REPORT_SEND, DIALOG_STYLE_INPUT, !""cBLUE"Связь с администрацией", !"\n\
		"cWH"Введите Ваш вопрос или жалобу\n\
		"cWH"Администрация постарается решить Вашу проблему", !"Отправить", !"Отмена");
	return true;
}

stock dialog_report_systems(playerid, dialogid, response, inputtext[])
{
	switch(dialogid)
	{
		case DIALOG_REPORT_SEND:
		{
			if(!response)
				return true;

			if(pData[playerid][pMut]) 
				return SendErr(playerid, "У вас бан чата. Используйте /mutetime чтобы узнать время бана.");

			if(GetPVarIntNew(playerid, "active_report"))
				return SendErr(playerid, "У Вас уже имеется заданный вопрос, ожидайте ответа от администрации");

			switch(type_report)
			{
				case 1:
				{
					send_default_report(playerid, inputtext);
				}
				case 2:
				{
					send_new_report(playerid, inputtext);
				}	
			}
			return true;
		}
		case DIALOG_REPORT_ANSWER:
		{	
			new 
				id = GetPVarIntNew(playerid, "admin_report")-1;

			if(rep_player[id] == INVALID_PLAYER_ID)
			{
				DeletePVarNew(playerid, "admin_report");
				SendErr(playerid, "Репорт уже неактивен");
				return true;
			}

			if(!strlen(inputtext) || strlen(inputtext) > 128)
			{
				show_answer_report(playerid, id);
			    SendErr(playerid, "Длина репорта должна до 128 символов");
			    return true;
			}

			new 
				time = gettime()-rep_time[id],
				player = rep_player[id];

			if(rep_player[id] != INVALID_PLAYER_ID)
			{

				show_notify_gui(rep_player[id], TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_24", 5000);

				format(String512, sizeof(String512), "\n\
					"cBLUE"Администратор: "cWH"%s\n\
					"cBLUE"Прошло: "cWH"%s\n\n\
					"cBLUE"Ваш репорт:\n\
					"cWH"%s\n\n\
					"cBLUE"Ответ администратора:\n\
					"cWH"%s",
					pData[playerid][pNickname],
					time_to_words(time), 
					rep_text[id], inputtext);
				SPD(rep_player[id], 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Ответ администратора", String512, !"Закрыть", "");

				format(String144, sizeof(String144), "Администратор %s[%i] для %s[%i]: %s",pData[playerid][pNickname], playerid, pData[rep_player[id]][pNickname], rep_player[id], inputtext);
				AdminChat(0xFF9945FF, String144);
				format(String144, sizeof(String144), "Администратор %s[%i] ответил Вам: %s",pData[playerid][pNickname], playerid, inputtext);
				SCM(rep_player[id], 0xFF9945FF, String144);

				DeletePVarNew(playerid, "admin_report");
				DeletePVarNew(rep_player[id], "active_report");

				report_avg_time += gettime() - rep_time[id];
				report_all_answer += 1;
	 
				rep_player[id] = INVALID_PLAYER_ID;
				rep_text[id][0] = EOS;
				rep_time[id] = -1;
			}
			rep_player[id] = INVALID_PLAYER_ID;
			rep_text[id][0] = EOS;
			rep_time[id] = -1;
			return true;
		}
	}
	return true;
}

stock send_default_report(playerid, message[])
{
	if(strlen(message) < 3 || strlen(message) > 128)
	{
	    SendErr(playerid, "Длина репорта должна быть от 3 до 128 символов");
	    return true;
	}

    format(String144, sizeof(String144), "[AREP] %s[%d]: {FFCD00}%s", pData[playerid][pNickname], playerid, message);
	AdminChat(0xfa5000FF, String144);


	format(String144, sizeof(String144), "%s[%d]: {FFCD00}%s", pData[playerid][pNickname], playerid, message);
	SCM(playerid, COLOR_GREEN, String144);
	SendInf(playerid, "Ожидайте ответа от администрации");

	SetPVarIntNew(playerid, "active_report", 600);
	return true;
}

stock send_new_report(playerid, message[])
{
	if(report_count == MAX_REPORT_COUNT)
		return true;

	if(strlen(message) < 3 || strlen(message) > 128)
	{
	    SendErr(playerid, "Длина репорта должна быть от 3 до 128 символов");
	    return true;
	}

    report_count ++;

    for(new i; i < MAX_REPORT_COUNT; i++)
   	{
   		if(rep_id[i] == 0)
   		{
   			rep_id[i] = report_count;
	   		rep_player[i] = playerid;
	   		strmid(rep_text[i], (message), 0, strlen(message), 128);
	   		rep_time[i] = gettime();
	   		break;
   		}
   	}

    format(String144, sizeof(String144), "[AREP] %s[%d]: {FFCD00}%s", pData[playerid][pNickname], playerid, message);
	AdminChat(0xfa5000FF, String144);

	format(String64, sizeof(String64), "[AREP] Всего репортов: {FFCD00}%i", report_count);
	AdminChat(0xfa5000FF, String64);

	format(String144, sizeof(String144), "%s[%d]: {FFCD00}%s", pData[playerid][pNickname], playerid, message);
	SCM(playerid, COLOR_GREEN, String144);

	format(String144, sizeof(String144), "Ожидайте ответа от администрации. Среднее время ответа %s", get_avarage_answer_time());
	SendInf(playerid, String144);

	SetPVarIntNew(playerid, "active_report", 600);
	return true;
}

stock get_avarage_answer_time()
{
	new 
		time;

	if(report_avg_time == 0)
	{
		time = 1;
	}
	else
	{
		time = floatround(report_avg_time / report_all_answer);
	}

	format(String64, sizeof(String64), "%s", time_to_words(time));
	return String64;
}

callback:: update_time_kd_repot(playerid)
{
	if(GetPVarIntNew(playerid, "active_report"))
	{
		new 
			time = GetPVarIntNew(playerid, "active_report");

		if(time == 1)
		{
			DeletePVarNew(playerid, "active_report");
			SendInf(playerid, "К сожалению, администрация не смогла ответить на Ваш репорт. Попробуйте ещё раз");
		}
		else
		{
			SetPVarIntNew(playerid, "active_report", time-1);
		}
	}
}

stock disconnect_report(playerid)
{	

	if(GetPVarIntNew(playerid, "admin_report"))
	{
		new 
			id = GetPVarIntNew(playerid, "admin_report")-1;

		DeletePVarNew(playerid, "admin_report");
		DeletePVarNew(rep_player[id], "active_report");

		SendInf(rep_player[id], "К сожалению, администрация не смогла ответить на Ваш репорт. Попробуйте ещё раз");

		rep_player[id] = INVALID_PLAYER_ID;
		rep_text[id][0] = EOS;
		rep_time[id] = -1;

	}
	return true;
}

stock remove_gvar_report(playerid) // OnPlayerDisconnect
{
	DeletePVarNew(playerid, "active_report");
	DeletePVarNew(playerid, "admin_report");
	return true;
}

stock update_report_queue()
{
	for(new i; i < MAX_REPORT_COUNT; i++)
	{
		if(rep_id[i] > 1)
		{
			rep_id[i] = rep_id[i]-1;
		}
	}
	return true;
}

CMD:rep(playerid, params[])
{
	if(pData[playerid][pMut]) 
		return SendErr(playerid, "У вас бан чата. Используйте /mutetime чтобы узнать время бана.");

	if(GetPVarIntNew(playerid, "active_report"))
		return SendErr(playerid, "У Вас уже имеется заданный вопрос, ожидайте ответа от администрации");

	if(sscanf(params, "s[128]", params[0])) 
	{
		return show_report_dialog(playerid);
	}

	switch(type_report)
	{
		case 1:
		{
			return send_default_report(playerid, params[0]);
		}
		case 2:
		{
			return send_new_report(playerid, params[0]);
		}
	}
	return true;
}

CMD:ans(playerid, params[])
{
	if(!pData[playerid][pAdmin])
		return NoCMD(playerid);

	if(sscanf(params, "ds[128]", params[0], params[1])) 
		return SendInf(playerid, "/ans [ID игрока] [Ответ]");

 	if(!IsPlayerConnected(params[0])) 
 		return SendErr(playerid,"Неверный ID");

    if(!pData[params[0]][pMysqlID]) 
    	return SendErr(playerid,"Игрок не авторизовался");

	format(String144, sizeof(String144), "Администратор %s[%d] для %s[%d]: %s",pData[playerid][pNickname], playerid, pData[params[0]][pNickname], params[0], params[1]);
	AdminChat(0xFF9945FF, String144);

	format(String144, sizeof(String144), "Администратор %s[%d] ответил Вам: %s",pData[playerid][pNickname], playerid, params[1]);
	SCM(params[0], 0xFF9945FF, String144);

	//DeletePVarNew(params[0], "active_report");

	return true;
}
alias:arep("ot", "ще");
CMD:arep(playerid)
{
	if(!pData[playerid][pAdmin])
		return NoCMD(playerid);

	if(type_report != 2)
		return SendErr(playerid, "В данный момент работает старая система репрота, используйте /ans");

	for(new i; i < MAX_REPORT_COUNT; i++)
	{
		if(rep_id[i] == 1)
		{
			rep_id[i] = 0;

			report_count -= 1;

			update_report_queue();

			show_answer_report(playerid, i);
			return true;
		}

	}
	SendErr(playerid, "Нет активных репортов");
	return true;
}

CMD:change_report_type(playerid)
{
	if(pData[playerid][pAdmin] < 7)
		return NoCMD(playerid);

	switch(type_report)
	{
		case 1:
		{
			type_report = 2;
			
			report_avg_time = 0;
			report_all_answer = 0;
		}
		case 2:
		{
			type_report = 1;

			report_avg_time = 0;
			report_all_answer = 0;

			for(new i; i < MAX_REPORT_COUNT; i++)
			{
				rep_id[i] = 0;
				DeletePVarNew(rep_player[i], "active_report");
				rep_player[i] = INVALID_PLAYER_ID;
				rep_text[i][0] = EOS;
				rep_time[i] = -1;
			}
		}
	}

	format(String144, sizeof(String144),"Администратор %s сменил тип репорта на %s",pData[playerid][pNickname], type_report == 1 ? ("старый") :  ("новый"));
	AdminChat(CGRAY, String144);

	new 
		query[250];

	format(query,sizeof(query),"UPDATE `serverdata` SET `type_report` = '%d'", type_report);
	sql_query(zConn, query);

	return true;
}

stock show_answer_report(playerid, id)
{
	SetPVarIntNew(playerid, "admin_report", id+1);
	new 
		time = gettime()-rep_time[id],
		player = rep_player[id];

	if(rep_player[id] == INVALID_PLAYER_ID)
		return SendErr(playerid, "Игрок вышел");

	format(String256, sizeof(String256), "\n\
		"cBLUE"Игрок: "cWH"%s [%i]\n\
		"cBLUE"Прошло: "cWH"%s\n\n\
		"cBLUE"Текст репорта:\n\
		"cWH"%s\n\n\
		"cBLUE"Введите ответ:",
		pData[player][pNickname],
		player,
		time_to_words(time), 
		rep_text[id]);
	SPD(playerid, DIALOG_REPORT_ANSWER, DIALOG_STYLE_INPUT, !""cBLUE"Репорт", String256, !"Ответить", "");
	return true;
}


stock report_admin_reload_payday()
{
	report_avg_time = 0;
	report_all_answer = 0;

	return true;
}