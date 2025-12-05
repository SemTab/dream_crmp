static const Float:gov_elections_position[][] =
{
	{698.2570,-14.4593,1201.8580},
	{698.2302,-12.9335,1201.8580},
	{698.3260,-11.2924,1201.8580}

};


#define ELECTION_START		1
#define ELECTION_STOP		2

enum election_data
{
	election_id,
	election_status,
	election_persona_1,
	election_persona_2,
	election_persona_3,
	election_persona_4,
	election_persona_5,
	election_persona_6,
	election_persona_7,
	election_persona_8,
	election_persona_9,
	election_persona_10,


	election_persona_1_count,
	election_persona_2_count,
	election_persona_3_count,
	election_persona_4_count,
	election_persona_5_count,
	election_persona_6_count,
	election_persona_7_count,
	election_persona_8_count,
	election_persona_9_count,
	election_persona_10_count,

	election_name_persona_1[MAX_PLAYER_NAME],
	election_name_persona_2[MAX_PLAYER_NAME],
	election_name_persona_3[MAX_PLAYER_NAME],
	election_name_persona_4[MAX_PLAYER_NAME],
	election_name_persona_5[MAX_PLAYER_NAME],
	election_name_persona_6[MAX_PLAYER_NAME],
	election_name_persona_7[MAX_PLAYER_NAME],
	election_name_persona_8[MAX_PLAYER_NAME],
	election_name_persona_9[MAX_PLAYER_NAME],
	election_name_persona_10[MAX_PLAYER_NAME]
}

new 
	election_information[1][election_data];


callback:: load_election_global()
{

	format(String256, sizeof(String256), "SELECT * FROM `election_gov` WHERE election_id = '0'");
	new Result:election_load = sql_queryEx(zConn, String256, QUERY_CACHED);
		
	new time = GetTickCount();

	if(sql_num_rows(election_load)) 
	{
        election_information[0][election_id] = sql_get_field_assoc_int_ex(election_load, 0, "election_id");
        election_information[0][election_status] = sql_get_field_assoc_int_ex(election_load, 0, "election_status");

        election_information[0][election_persona_1] = sql_get_field_assoc_int_ex(election_load, 0, "election_persona_1");
        election_information[0][election_persona_2] = sql_get_field_assoc_int_ex(election_load, 0, "election_persona_2");
        election_information[0][election_persona_3] = sql_get_field_assoc_int_ex(election_load, 0, "election_persona_3");
        election_information[0][election_persona_4] = sql_get_field_assoc_int_ex(election_load, 0, "election_persona_4");
        election_information[0][election_persona_5] = sql_get_field_assoc_int_ex(election_load, 0, "election_persona_5");
        election_information[0][election_persona_6] = sql_get_field_assoc_int_ex(election_load, 0, "election_persona_6");
        election_information[0][election_persona_7] = sql_get_field_assoc_int_ex(election_load, 0, "election_persona_7");
        election_information[0][election_persona_8] = sql_get_field_assoc_int_ex(election_load, 0, "election_persona_8");
        election_information[0][election_persona_9] = sql_get_field_assoc_int_ex(election_load, 0, "election_persona_9");
        election_information[0][election_persona_10] = sql_get_field_assoc_int_ex(election_load, 0, "election_persona_10");

        election_information[0][election_persona_1_count] = sql_get_field_assoc_int_ex(election_load, 0, "election_persona_1_count");
        election_information[0][election_persona_2_count] = sql_get_field_assoc_int_ex(election_load, 0, "election_persona_2_count");
        election_information[0][election_persona_3_count] = sql_get_field_assoc_int_ex(election_load, 0, "election_persona_3_count");
        election_information[0][election_persona_4_count] = sql_get_field_assoc_int_ex(election_load, 0, "election_persona_4_count");
        election_information[0][election_persona_5_count] = sql_get_field_assoc_int_ex(election_load, 0, "election_persona_5_count");
        election_information[0][election_persona_6_count] = sql_get_field_assoc_int_ex(election_load, 0, "election_persona_6_count");
        election_information[0][election_persona_7_count] = sql_get_field_assoc_int_ex(election_load, 0, "election_persona_7_count");
        election_information[0][election_persona_8_count] = sql_get_field_assoc_int_ex(election_load, 0, "election_persona_8_count");
        election_information[0][election_persona_9_count] = sql_get_field_assoc_int_ex(election_load, 0, "election_persona_9_count");
        election_information[0][election_persona_10_count] = sql_get_field_assoc_int_ex(election_load, 0, "election_persona_10_count");

        if(election_information[0][election_status])
        {
        	election_other_element_g(ELECTION_START);
        }

        printf("[Система Выборов]: Выборы были успешно загружены. Времени затрачено: <%d мс>" , GetTickCount()-  time);
    }
    else
    {
    	printf("[Система Выборов]: Выборы не найдены. Времени затрачено: <%d мс>" , GetTickCount()-  time);
    }

	return true;
}

stock save_election_gov()
{
	format(String2048, sizeof(String2048), "\
		UPDATE election_gov SET \
		election_persona_1 = '%d', \
		election_persona_2 = '%d', \
		election_persona_3 = '%d', \
		election_persona_4 = '%d', \
		election_persona_5 = '%d', \
		election_persona_6 = '%d', \
		election_persona_7 = '%d', \
		election_persona_8 = '%d', \
		election_persona_9 = '%d', \
		election_persona_10 = '%d', \
		election_persona_1_count = '%d', \
		election_persona_2_count = '%d', \
		election_persona_3_count = '%d', \
		election_persona_4_count = '%d', \
		election_persona_5_count = '%d', \
		election_persona_6_count = '%d', \
		election_persona_7_count = '%d', \
		election_persona_8_count = '%d', \
		election_persona_9_count = '%d', \
		election_persona_10_count = '%d'\
		WHERE election_id = '%d'",

		election_information[0][election_persona_1], 
		election_information[0][election_persona_2], 
		election_information[0][election_persona_3], 
		election_information[0][election_persona_4], 
		election_information[0][election_persona_5], 
		election_information[0][election_persona_6], 
		election_information[0][election_persona_7], 
		election_information[0][election_persona_8], 
		election_information[0][election_persona_9], 
		election_information[0][election_persona_10],

		election_information[0][election_persona_1_count], 
		election_information[0][election_persona_2_count], 
		election_information[0][election_persona_3_count], 
		election_information[0][election_persona_4_count], 
		election_information[0][election_persona_5_count], 
		election_information[0][election_persona_6_count], 
		election_information[0][election_persona_7_count], 
		election_information[0][election_persona_8_count], 
		election_information[0][election_persona_9_count], 
		election_information[0][election_persona_10_count],

		0);

	sql_queryEx(zConn, String2048, QUERY_THREADED);	
	
	return true;
}

CMD:election(playerid)
{

    if(pData[playerid][pAdmin] < 7)
    	return NoCMD(playerid);	

	return show_panel_edit_election(playerid);
}


stock show_panel_edit_election(playerid)
{
    format(String512, sizeof(String512), "\
    "cGREY"Тип\t"cGREY"Информация\n\
    "cBLUE"1. "cWH"Начать выборы\tОткрыть\n\
    "cBLUE"2. "cWH"Закончить выборы\tОткрыть\n\
    "cBLUE"3. "cWH"Изменить список кандидатов\tОткрыть\n\
    "cBLUE"4. "cWH"Очистить выборы полностью\tОчистить\n\
    "cBLUE"5. "cWH"Сохранить выборы\tСохранить");
    return SPD(playerid, DIALOG_MENU_ELECTION_ADMIN, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Система выборов", String512, !"Выбрать", !"Закрыть"); 
}

stock election_check_status(playerid, type_election)
{


	switch(type_election)
	{
		case ELECTION_START:
		{
			if(!election_information[0][election_status])
			{
				if(election_information[0][election_persona_1] == -1 || election_information[0][election_persona_2] == -1)
					return SendErr(playerid, "У вас не выбраны кандидаты для проведения выборов!");

				start_election_global(playerid);
			}
			else
			{
				SendErr(playerid, "Выбор уже проводятся!");
				return show_panel_edit_election(playerid);
			}
		}
		case ELECTION_STOP:
		{
			if(election_information[0][election_status])
			{
				end_election_global(playerid);
			}
			else
			{
				SendErr(playerid, "Выбор не проводятся, чтобы завершать их!");
				return show_panel_edit_election(playerid);
			}
		}
	}

	return true;
}

stock election_other_element_g(status)
{
	switch(status)
	{
		case ELECTION_START:
		{		

			election_pickup[0] = create_circle_pickup(gov_elections_position[0][0], gov_elections_position[0][1], gov_elections_position[0][2], TRIGGER_LRED);
			election_pickup[1] = create_circle_pickup(gov_elections_position[1][0], gov_elections_position[1][1], gov_elections_position[1][2], TRIGGER_LRED);
			election_pickup[2] = create_circle_pickup(gov_elections_position[2][0], gov_elections_position[2][1], gov_elections_position[2][2], TRIGGER_LRED);

			election_text_pickup[0] = CreateDynamic3DTextLabel(""cWH"Выборы кандидата\n "cLRED"[Встаньте на пикап]",-1, \
  			gov_elections_position[0][0], gov_elections_position[0][1], gov_elections_position[0][2], 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);			
			election_text_pickup[1] = CreateDynamic3DTextLabel(""cWH"Выборы кандидата\n "cLRED"[Встаньте на пикап]",-1, \
  			gov_elections_position[1][0], gov_elections_position[1][1], gov_elections_position[1][2], 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);			
			election_text_pickup[2] = CreateDynamic3DTextLabel(""cWH"Выборы кандидата\n "cLRED"[Встаньте на пикап]",-1, \
  			gov_elections_position[2][0], gov_elections_position[2][1], gov_elections_position[2][2], 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
		}
		case ELECTION_STOP:
		{	

			DestroyDynamicObject(election_pickup[0]);
			DestroyDynamicObject(election_pickup[1]);
			DestroyDynamicObject(election_pickup[2]);

			DestroyDynamicArea(election_pickup[0]);
			DestroyDynamicArea(election_pickup[1]);
			DestroyDynamicArea(election_pickup[2]);

			DestroyDynamic3DTextLabel(election_text_pickup[0]);
			DestroyDynamic3DTextLabel(election_text_pickup[1]);
			DestroyDynamic3DTextLabel(election_text_pickup[2]);

		}
	}
	return true;
}

stock start_election_global(playerid)
{
	show_message_active_election_g();

	election_information[0][election_status] = 1;
	election_other_element_g(ELECTION_START);
	SendSucc(playerid, "Вы успешно начали выборы Губернатора Области!");
	show_panel_edit_election(playerid);

	sql_queryEx(zConn, "UPDATE `accounts` SET `election_status_p` = '0'", QUERY_THREADED); 

	foreach(new i: logged_players)
	{
	 	pData[i][election_status_p] = 0;
	 	UpdatePlayerData(i, "election_status_p", pData[i][election_status_p]);			
	}
	
	return true;
}

stock end_election_global(playerid)
{
	show_message_false_election_g();
	SendSucc(playerid, "Вы успешно завершили выборы Губернатора Области!");
	election_other_element_g(ELECTION_STOP);

	sql_queryEx(zConn, "UPDATE `accounts` SET `election_status_p` = '0'", QUERY_THREADED); 

	foreach(new i: logged_players)
	{
	 	pData[i][election_status_p] = 0;
	 	UpdatePlayerData(i, "election_status_p", pData[i][election_status_p]);			
	}

	return true;
}


stock show_message_active_election_g()
{
	SendClientMessageToAll(0x4466ccff, "");
	SendClientMessageToAll(0x4466ccff, "----------------------------------------------------------------------------------------------------");
	SendClientMessageToAll(0x4466ccff, "[Гос.Новости] В области начались выборы Губернатора!");
	SendClientMessageToAll(0x4466ccff, "[Гос.Новости] Приглашаем Вас проголосовать за кандидата, который достоен стать Губернатором Области!");
	SendClientMessageToAll(0x4466ccff, "[Гос.Новости] Оставить свой голос можно в Мэрии г.Арзамаса и только один раз!");
	SendClientMessageToAll(0x4466ccff, "----------------------------------------------------------------------------------------------------");
	SendClientMessageToAll(0x4466ccff, "");
	return true;
}

stock show_message_false_election_g()
{
	SendClientMessageToAll(0x4466ccff, "");
	SendClientMessageToAll(0x4466ccff, "----------------------------------------------------------------------------------------------------");
	SendClientMessageToAll(0x4466ccff, "[Гос.Новости] В области закончились выборы Губернатора!");
	SendClientMessageToAll(0x4466ccff, "[Гос.Новости] Спасибо Всем, кто принимал участие в выборах!");
	SendClientMessageToAll(0x4466ccff, "----------------------------------------------------------------------------------------------------");
	SendClientMessageToAll(0x4466ccff, "");
	return true;
}

stock election_change_person(playerid)
{

	new 
		name_election_1[MAX_PLAYER_NAME],
		name_election_2[MAX_PLAYER_NAME],
		name_election_3[MAX_PLAYER_NAME],
		name_election_4[MAX_PLAYER_NAME],
		name_election_5[MAX_PLAYER_NAME],
		name_election_6[MAX_PLAYER_NAME],
		name_election_7[MAX_PLAYER_NAME],
		name_election_8[MAX_PLAYER_NAME],
		name_election_9[MAX_PLAYER_NAME],
		name_election_10[MAX_PLAYER_NAME];

	if(election_information[0][election_persona_1] != -1)
	{	
		new 
			userid = election_information[0][election_persona_1];

		GetPlayerNameByID(userid, name_election_1);
	}
	else name_election_1 = "Отсутствует";	

	if(election_information[0][election_persona_2] != -1)
	{	
		new 
			userid = election_information[0][election_persona_2];

		GetPlayerNameByID(userid, name_election_2);
	}
	else name_election_2 = "Отсутствует";	


	if(election_information[0][election_persona_3] != -1)
	{	
		new 
			userid = election_information[0][election_persona_3];

		GetPlayerNameByID(userid, name_election_3);
	}
	else name_election_3 = "Отсутствует";	


	if(election_information[0][election_persona_4] != -1)
	{	
		new 
			userid = election_information[0][election_persona_4];

		GetPlayerNameByID(userid, name_election_4);
	}
	else name_election_4 = "Отсутствует";	

	if(election_information[0][election_persona_5] != -1)
	{	
		new 
			userid = election_information[0][election_persona_5];

		GetPlayerNameByID(userid, name_election_5);
	}
	else name_election_5 = "Отсутствует";	

	if(election_information[0][election_persona_6] != -1)
	{	
		new 
			userid = election_information[0][election_persona_6];

		GetPlayerNameByID(userid, name_election_6);
	}
	else name_election_6 = "Отсутствует";	

	if(election_information[0][election_persona_7] != -1)
	{	
		new 
			userid = election_information[0][election_persona_7];

		GetPlayerNameByID(userid, name_election_7);
	}
	else name_election_7 = "Отсутствует";	

	if(election_information[0][election_persona_8] != -1)
	{	
		new 
			userid = election_information[0][election_persona_8];

		GetPlayerNameByID(userid, name_election_8);
	}
	else name_election_8 = "Отсутствует";	


	if(election_information[0][election_persona_9] != -1)
	{	
		new 
			userid = election_information[0][election_persona_9];

		GetPlayerNameByID(userid, name_election_9);
	}
	else name_election_9 = "Отсутствует";	


	if(election_information[0][election_persona_10] != -1)
	{	
		new 
			userid = election_information[0][election_persona_10];

		GetPlayerNameByID(userid, name_election_10);
	}
	else name_election_10 = "Отсутствует";	



    format(String1024, sizeof(String1024), "\
    "cGREY"Кандидат\t"cGREY"Голосов\t"cGREY"Информация\n\
    "cBLUE"1. "cWH"%s\t"cGR"%d голосов\t"cBLUE"Изменить\n\
    "cBLUE"2. "cWH"%s\t"cGR"%d голосов\t"cBLUE"Изменить\n\
    "cBLUE"3. "cWH"%s\t"cGR"%d голосов\t"cBLUE"Изменить\n\
    "cBLUE"4. "cWH"%s\t"cGR"%d голосов\t"cBLUE"Изменить\n\
    "cBLUE"5. "cWH"%s\t"cGR"%d голосов\t"cBLUE"Изменить\n\
    "cBLUE"6. "cWH"%s\t"cGR"%d голосов\t"cBLUE"Изменить\n\
    "cBLUE"7. "cWH"%s\t"cGR"%d голосов\t"cBLUE"Изменить\n\
    "cBLUE"8. "cWH"%s\t"cGR"%d голосов\t"cBLUE"Изменить\n\
    "cBLUE"9. "cWH"%s\t"cGR"%d голосов\t"cBLUE"Изменить\n\
    "cBLUE"10. "cWH"%s\t"cGR"%d голосов\t"cBLUE"Изменить",

    name_election_1, election_information[0][election_persona_1_count], 
    name_election_2, election_information[0][election_persona_2_count], 
    name_election_3, election_information[0][election_persona_3_count], 
    name_election_4, election_information[0][election_persona_4_count], 
    name_election_5, election_information[0][election_persona_5_count], 
    name_election_6, election_information[0][election_persona_6_count],     
    name_election_7, election_information[0][election_persona_7_count], 
    name_election_8, election_information[0][election_persona_8_count], 
    name_election_9, election_information[0][election_persona_9_count], 
    name_election_10, election_information[0][election_persona_10_count]

    );
    return SPD(playerid, DIALOG_MENU_ELECTION_PERSON, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Система выборов", String1024, !"Выбрать", !"Закрыть"); 
}

stock show_select_name_candidat(playerid)
{
	return SPD(playerid, DIALOG_MENU_ELECTION_PERSS, DIALOG_STYLE_INPUT, !""cBLUE"Выбор кандидата", !"\
	"cWH"Введите ID кандидата, которого хотите внести в список\n\n\
	Если хотите убрать - введите '-1'", !"Далее", !"Назад");		
}



stock dialog_all_election(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
		case DIALOG_MENU_ELECTION_ADMIN:
		{
			if(!response)
				return true;

			switch(listitem)
			{
				case 0: return election_check_status(playerid, ELECTION_START);
				case 1: return election_check_status(playerid, ELECTION_STOP);
				case 2: return election_change_person(playerid);
				case 3: return clear_election_global(playerid);
				case 4: return save_election_gov();
			}
		}
		case DIALOG_MENU_ELECTION_PERSON:
		{
			if(!response)
				return show_panel_edit_election(playerid);

			dialog_listitem_valuess[playerid] = listitem; 

			show_select_name_candidat(playerid);			
		}
		case DIALOG_MENU_ELECTION_PERSS:
		{
			if(!response)
				return election_change_person(playerid);

			new
				candidat_id = strval(inputtext),
				id_persona = dialog_listitem_valuess[playerid];

			if(candidat_id != -1)
			{
				if(!IsPlayerConnected(candidat_id)) 
				{
					show_select_name_candidat(playerid);
					return SendErr(playerid,"Неверный ID кандидата!");
				}
			}

			if(candidat_id != -1)
			{

				switch(id_persona)
				{
					case 0: election_information[0][election_persona_1] = pData[candidat_id][pMysqlID]; 
					case 1: election_information[0][election_persona_2] = pData[candidat_id][pMysqlID]; 
					case 2: election_information[0][election_persona_3] = pData[candidat_id][pMysqlID]; 
					case 3: election_information[0][election_persona_4] = pData[candidat_id][pMysqlID]; 
					case 4: election_information[0][election_persona_5] = pData[candidat_id][pMysqlID]; 
					case 5: election_information[0][election_persona_6] = pData[candidat_id][pMysqlID]; 
					case 6: election_information[0][election_persona_7] = pData[candidat_id][pMysqlID]; 
					case 7: election_information[0][election_persona_8] = pData[candidat_id][pMysqlID]; 
					case 8: election_information[0][election_persona_9] = pData[candidat_id][pMysqlID]; 
					case 9: election_information[0][election_persona_10] = pData[candidat_id][pMysqlID]; 
				}
			}
			else
			{
				switch(id_persona)
				{
					case 0: election_information[0][election_persona_1] = -1; 
					case 1: election_information[0][election_persona_2] = -1; 
					case 2: election_information[0][election_persona_3] = -1; 
					case 3: election_information[0][election_persona_4] = -1; 
					case 4: election_information[0][election_persona_5] = -1; 
					case 5: election_information[0][election_persona_6] = -1; 
					case 6: election_information[0][election_persona_7] = -1; 
					case 7: election_information[0][election_persona_8] = -1; 
					case 8: election_information[0][election_persona_9] = -1; 
					case 9: election_information[0][election_persona_10] = -1; 
				}				
			}
			format(String144, sizeof(String144), "Вы успешно назначали %s[%d] на пост кандидата №%d", pData[candidat_id][pNickname], id_persona+1);
			SendSucc(playerid, String144);
			election_change_person(playerid);
			save_election_gov();
		}
		case DIALOG_MENU_ELECTION_PLAYER:
		{
			if(!response)
				return SCM(playerid, COLOR_YELLOW, "[Наблюдатели] Как передумаете - приходите голосовать! Каждый голос важен!");


			switch(listitem)
			{
				case 0: 
				{
					if(election_information[0][election_persona_1] != -1)
					{
						election_information[0][election_persona_1_count]++;
						SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Голос на выборах", !"\
						"cWH"Спасибо за Ваш голос! Он очень важен для области!", !"Закрыть", "");
					
						pData[playerid][election_status_p] = 1;
						UpdatePlayerData(playerid, "election_status_p", pData[playerid][election_status_p]);
					}
					else
					{
						election_person_player(playerid);
						return SendErr(playerid, "Кандидат отсутствует!");
					}
				}
				case 1: 
				{
					if(election_information[0][election_persona_2] != -1)
					{
						election_information[0][election_persona_2_count]++;
						SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Голос на выборах", !"\
						"cWH"Спасибо за Ваш голос! Он очень важен для области!", !"Закрыть", "");
					
						pData[playerid][election_status_p] = 1;
						UpdatePlayerData(playerid, "election_status_p", pData[playerid][election_status_p]);
					}
					else
					{
						election_person_player(playerid);
						return SendErr(playerid, "Кандидат отсутствует!");
					}
				}
				case 2: 
				{
					if(election_information[0][election_persona_3] != -1)
					{
						election_information[0][election_persona_3_count]++;
						SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Голос на выборах", !"\
						"cWH"Спасибо за Ваш голос! Он очень важен для области!", !"Закрыть", "");
					
						pData[playerid][election_status_p] = 1;
						UpdatePlayerData(playerid, "election_status_p", pData[playerid][election_status_p]);
					}
					else
					{
						election_person_player(playerid);
						return SendErr(playerid, "Кандидат отсутствует!");
					}
				}
				case 3: 
				{
					if(election_information[0][election_persona_4] != -1)
					{
						election_information[0][election_persona_4_count]++;
						SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Голос на выборах", !"\
						"cWH"Спасибо за Ваш голос! Он очень важен для области!", !"Закрыть", "");
					
						pData[playerid][election_status_p] = 1;
						UpdatePlayerData(playerid, "election_status_p", pData[playerid][election_status_p]);
					}
					else
					{
						election_person_player(playerid);
						return SendErr(playerid, "Кандидат отсутствует!");
					}
				}
				case 4: 
				{
					if(election_information[0][election_persona_5] != -1)
					{
						election_information[0][election_persona_5_count]++;
						SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Голос на выборах", !"\
						"cWH"Спасибо за Ваш голос! Он очень важен для области!", !"Закрыть", "");
					
						pData[playerid][election_status_p] = 1;
						UpdatePlayerData(playerid, "election_status_p", pData[playerid][election_status_p]);
					}
					else
					{
						election_person_player(playerid);
						return SendErr(playerid, "Кандидат отсутствует!");
					}
				}


				case 5: 
				{
					if(election_information[0][election_persona_6] != -1)
					{
						election_information[0][election_persona_6_count]++;
						SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Голос на выборах", !"\
						"cWH"Спасибо за Ваш голос! Он очень важен для области!", !"Закрыть", "");
					
						pData[playerid][election_status_p] = 1;
						UpdatePlayerData(playerid, "election_status_p", pData[playerid][election_status_p]);
					}
					else
					{
						election_person_player(playerid);
						return SendErr(playerid, "Кандидат отсутствует!");
					}
				}
				case 6: 
				{
					if(election_information[0][election_persona_7] != -1)
					{
						election_information[0][election_persona_7_count]++;
						SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Голос на выборах", !"\
						"cWH"Спасибо за Ваш голос! Он очень важен для области!", !"Закрыть", "");
					
						pData[playerid][election_status_p] = 1;
						UpdatePlayerData(playerid, "election_status_p", pData[playerid][election_status_p]);
					}
					else
					{
						election_person_player(playerid);
						return SendErr(playerid, "Кандидат отсутствует!");
					}
				}
				case 7: 
				{
					if(election_information[0][election_persona_8] != -1)
					{
						election_information[0][election_persona_8_count]++;
						SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Голос на выборах", !"\
						"cWH"Спасибо за Ваш голос! Он очень важен для области!", !"Закрыть", "");
					
						pData[playerid][election_status_p] = 1;
						UpdatePlayerData(playerid, "election_status_p", pData[playerid][election_status_p]);
					}
					else
					{
						election_person_player(playerid);
						return SendErr(playerid, "Кандидат отсутствует!");
					}
				}
				case 8: 
				{
					if(election_information[0][election_persona_9] != -1)
					{
						election_information[0][election_persona_9_count]++;
						SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Голос на выборах", !"\
						"cWH"Спасибо за Ваш голос! Он очень важен для области!", !"Закрыть", "");
					
						pData[playerid][election_status_p] = 1;
						UpdatePlayerData(playerid, "election_status_p", pData[playerid][election_status_p]);
					}
					else
					{
						election_person_player(playerid);
						return SendErr(playerid, "Кандидат отсутствует!");
					}
				}
				case 9: 
				{
					if(election_information[0][election_persona_10] != -1)
					{
						election_information[0][election_persona_10_count]++;
						SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Голос на выборах", !"\
						"cWH"Спасибо за Ваш голос! Он очень важен для области!", !"Закрыть", "");

						pData[playerid][election_status_p] = 1;
						UpdatePlayerData(playerid, "election_status_p", pData[playerid][election_status_p]);

					}
					else
					{
						election_person_player(playerid);
						return SendErr(playerid, "Кандидат отсутствует!");
					}
				}

			}


		}
	}
	return true;
}

stock clear_election_global(playerid)
{

	election_information[0][election_persona_1] = -1;
	election_information[0][election_persona_2] = -1;
	election_information[0][election_persona_3] = -1;
	election_information[0][election_persona_4] = -1;
	election_information[0][election_persona_5] = -1;
	election_information[0][election_persona_6] = -1;
	election_information[0][election_persona_7] = -1;
	election_information[0][election_persona_8] = -1;
	election_information[0][election_persona_9] = -1;
	election_information[0][election_persona_10] = -1;

	election_information[0][election_status] = 0;

	SendSucc(playerid, "Вы успешно очистили все активные параметры выборов!");

	show_panel_edit_election(playerid);

	return true;
}

stock election_person_player(playerid)
{
	if(pData[playerid][election_status_p])
	{
		SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Голос на выборах", !"\
		"cWH"Спасибо за Вашу активность, но повторно голосовать нельзя!", !"Закрыть", "");
		return true;
	}

	new 
		name_election_1[MAX_PLAYER_NAME],
		name_election_2[MAX_PLAYER_NAME],
		name_election_3[MAX_PLAYER_NAME],
		name_election_4[MAX_PLAYER_NAME],
		name_election_5[MAX_PLAYER_NAME],
		name_election_6[MAX_PLAYER_NAME],
		name_election_7[MAX_PLAYER_NAME],
		name_election_8[MAX_PLAYER_NAME],
		name_election_9[MAX_PLAYER_NAME],
		name_election_10[MAX_PLAYER_NAME];

	if(election_information[0][election_persona_1] != -1)
	{	
		new 
			userid = election_information[0][election_persona_1];

		GetPlayerNameByID(userid, name_election_1);
	}
	else name_election_1 = "Отсутствует";	

	if(election_information[0][election_persona_2] != -1)
	{	
		new 
			userid = election_information[0][election_persona_2];

		GetPlayerNameByID(userid, name_election_2);
	}
	else name_election_2 = "Отсутствует";	


	if(election_information[0][election_persona_3] != -1)
	{	
		new 
			userid = election_information[0][election_persona_3];

		GetPlayerNameByID(userid, name_election_3);
	}
	else name_election_3 = "Отсутствует";	


	if(election_information[0][election_persona_4] != -1)
	{	
		new 
			userid = election_information[0][election_persona_4];

		GetPlayerNameByID(userid, name_election_4);
	}
	else name_election_4 = "Отсутствует";	

	if(election_information[0][election_persona_5] != -1)
	{	
		new 
			userid = election_information[0][election_persona_5];

		GetPlayerNameByID(userid, name_election_5);
	}
	else name_election_5 = "Отсутствует";	

	if(election_information[0][election_persona_6] != -1)
	{	
		new 
			userid = election_information[0][election_persona_6];

		GetPlayerNameByID(userid, name_election_6);
	}
	else name_election_6 = "Отсутствует";	

	if(election_information[0][election_persona_7] != -1)
	{	
		new 
			userid = election_information[0][election_persona_7];

		GetPlayerNameByID(userid, name_election_7);
	}
	else name_election_7 = "Отсутствует";	

	if(election_information[0][election_persona_8] != -1)
	{	
		new 
			userid = election_information[0][election_persona_8];

		GetPlayerNameByID(userid, name_election_8);
	}
	else name_election_8 = "Отсутствует";	


	if(election_information[0][election_persona_9] != -1)
	{	
		new 
			userid = election_information[0][election_persona_9];

		GetPlayerNameByID(userid, name_election_9);
	}
	else name_election_9 = "Отсутствует";	


	if(election_information[0][election_persona_10] != -1)
	{	
		new 
			userid = election_information[0][election_persona_10];

		GetPlayerNameByID(userid, name_election_10);
	}
	else name_election_10 = "Отсутствует";	





    format(String1024, sizeof(String1024), "\
    "cGREY"Кандидат\t"cGREY"Информация\n\
    "cBLUE"1. "cWH"%s\t"cBLUE"Проголосовать\n\
    "cBLUE"2. "cWH"%s\t"cBLUE"Проголосовать\n\
    "cBLUE"3. "cWH"%s\t"cBLUE"Проголосовать\n\
    "cBLUE"4. "cWH"%s\t"cBLUE"Проголосовать\n\
    "cBLUE"5. "cWH"%s\t"cBLUE"Проголосовать\n\
    "cBLUE"6. "cWH"%s\t"cBLUE"Проголосовать\n\
    "cBLUE"7. "cWH"%s\t"cBLUE"Проголосовать\n\
    "cBLUE"8. "cWH"%s\t"cBLUE"Проголосовать\n\
    "cBLUE"9. "cWH"%s\t"cBLUE"Проголосовать\n\
    "cBLUE"10. "cWH"%s\t"cBLUE"Проголосовать",

    name_election_1,
    name_election_2,
    name_election_3,
    name_election_4,
    name_election_5,
    name_election_6,    
    name_election_7,
    name_election_8,
    name_election_9,
    name_election_10

    );
    return SPD(playerid, DIALOG_MENU_ELECTION_PLAYER, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Выборы Губернатора", String1024, !"Выбрать", !"Закрыть"); 
}
