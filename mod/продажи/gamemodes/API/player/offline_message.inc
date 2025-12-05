
#define MAX_PLAYER_MSG_OFF			30

enum player_data_offline_mes
{

	message_offline_msg[128],
	message_offline_date[16],
	message_offline_msg_previow[11],
	message_offline_send_name[MAX_PLAYER_NAME]
}
new 
	msg_off_p[MAX_PLAYERS][MAX_PLAYER_MSG_OFF][player_data_offline_mes];

new 
	count_offline_message[MAX_PLAYERS];


stock send_off_message(from_playerid, nick[], text[])
{
	new 
		adm_name[24];

	if(IsPlayerConnected(from_playerid))
		format(adm_name, 24, pData[from_playerid][pNickname]);
	else
		format(adm_name, 24, "Система");

	format(String256f,sizeof(String256f), "INSERT INTO offline_messages(message_username, message_msg, send_adm) VALUES ('%s', '%s', '%s')", nick, text, adm_name);
	sql_queryEx(zConn, String256f, QUERY_THREADED);

	return true;
}

stock off_messages_checker(playerid)
{

	format(String256f,sizeof(String256f),"SELECT * FROM offline_messages WHERE message_username = '%s' AND status = '1'", pData[playerid][pNickname]);
	new Result:r = sql_queryEx(zConn, String256f, QUERY_CACHED);

	if(!sql_num_rows(r))
		return true;

	count_offline_message[playerid] = sql_num_rows(r);


	sql_free_result(r);

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:info_gui_notify", 3000);
	format(String256f, sizeof(String256f), "У Вас %d новых уведомлений!", count_offline_message[playerid]);
	SendInf(playerid, String256f);

	SendInf(playerid, "Чтобы прочитать новые уведомления, используйте команду - /notify");

	return true;
}


CMD:notify(playerid)
{
	if(!count_offline_message[playerid])
		return SendErr(playerid, "У вас нет новых уведомлений!");

    format(String2048, sizeof(String2048), ""cGREY"№\t"cGREY"Сообщение\t"cGREY"Дата\t"cGREY"Отправил(а)\n");


	format(String256,sizeof(String256),"SELECT * FROM offline_messages WHERE message_username = '%s' AND status = '1'", pData[playerid][pNickname]);
	new Result:r = sql_queryEx(zConn, String256, QUERY_CACHED);

	new 
		all_new_message = sql_num_rows(r);

	new 
		counts_message = 0;

 	for(new i; i < all_new_message; i++)
	{

		new 
			notify_personal_user_id,
			message_offline_send_names[32],
			message_offline_send_date[20],
			message_offline_send[128],
			message_offline_send_prewiow[128];


		notify_personal_user_id = sql_get_field_assoc_int_ex(r, i, "message_id");
		sql_get_field_assoc_ex(r, i,"send_adm", message_offline_send_names, MAX_PLAYER_NAME);
		sql_get_field_assoc_ex(r, i,"message_date", message_offline_send_date, 20);
		sql_get_field_assoc_ex(r, i,"message_msg", message_offline_send, 128);
		sql_get_field_assoc_ex(r, i,"message_msg", message_offline_send_prewiow, MAX_PLAYER_NAME);

		strdel(message_offline_send_prewiow, 15, 128);

		dialog_listitem_values[playerid][i] = notify_personal_user_id;

    	format(String2048, sizeof(String2048), "%s"cBLUE"%d."cWH"\t%s..\t"cBLUE"%s"cWH"\t%s\n",String2048, \
    	counts_message+1, message_offline_send_prewiow, message_offline_send_date, \
    	message_offline_send_names);

    	counts_message++;

	}
	sql_free_result(r);

	SPD(playerid, DIALOG_SELECT_OFF_MES, DIALOG_STYLE_TABLIST_HEADERS ,""cBLUE"Уведомления",String2048,"Открыть","Закрыть");
	return true;
}


stock learn_off_message(playerid, message_id)
{

	format(String256,sizeof(String256),"SELECT * FROM offline_messages WHERE message_id = '%d'", message_id);
	new Result:r = sql_queryEx(zConn, String256, QUERY_CACHED);

	if(sql_num_rows(r)) 
	{
		new 
			message_offline_send_names[32],
			message_offline_send_date[20],
			message_offline_send[128];


		sql_get_field_assoc_ex(r, 0,"send_adm", message_offline_send_names, MAX_PLAYER_NAME);
		sql_get_field_assoc_ex(r, 0,"message_date", message_offline_send_date, 20);
		sql_get_field_assoc_ex(r, 0,"message_msg", message_offline_send, 128);

		format(String256, sizeof(String256), "\
			"cWH"Отправитель: "cBLUE"%s\n\
			"cWH"Дата отправки: "cBLUE"%s\n\n\
			"cWH"Сообщение: %s", message_offline_send_names, message_offline_send_date, message_offline_send);
		SPD(playerid, DIALOG_LEARN_OFF_MES, DIALOG_STYLE_MSGBOX, !""cBLUE"Новое уведомление", String256, !"Удалить", "");


	}
	sql_free_result(r);

	count_offline_message[playerid]--;

	SendSucc(playerid, "Вы успешно прочитали уведомление и оно было удалено!");

	format(String256, 100, "UPDATE offline_messages SET status = '0' WHERE message_id = '%d'", message_id);
	sql_queryEx(zConn, String256, QUERY_THREADED);
	return true;
}

stock dialog_all_off_message(playerid, dialogid, response, listitem)
{	
	switch(dialogid)
	{
		case DIALOG_SELECT_OFF_MES:
		{
			new 
				id = dialog_listitem_values[playerid][listitem];

			return learn_off_message(playerid, id);
		}
		case DIALOG_LEARN_OFF_MES:
		{
			if(!response)
			{
				return PC_EmulateCommand(playerid, "/notify");
			}
			return PC_EmulateCommand(playerid, "/notify");
		}
	}
	return true;
}


CMD:offmes(playerid,params[])
{
	if(pData[playerid][pAdmin] < 6) 
		return NoCMD(playerid);

	static
		nick[24],
		reason[144];
	
	if(sscanf(params, "s[24]s[128]", nick, reason)) 
		return SendInf(playerid, "Используйте: /offmes [Ник] [Текст]");

	format(reason, 144, "%s", reason);
	send_off_message(playerid, nick, reason);

	format(String144, sizeof(String144), "Вы отправили %s сообщение в оффлайне. Он получит его, как только зайдет на сервер!", nick);
	SendInf(playerid, String144);
	format(String144, sizeof(String144), "Ваше сообщение: %s"cWH"", reason);
	SendInf(playerid, String144);

	nick[0] = reason[0] = EOS;
    return true;
}