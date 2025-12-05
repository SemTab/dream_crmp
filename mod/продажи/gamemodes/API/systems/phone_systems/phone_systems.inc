static const day_name_phone_calendar[][] = {
    "Воскресенье",
    "Понедельник",
    "Вторник",
    "Среда",
    "Четверг",
    "Пятница",
    "Суббота"
};

static const mounth_phone_calendar[][] =
{	
	"ВЫ ЧЕ",
    "Январь",
    "Февраль",
    "Март",
    "Апрель",
    "Май",
    "Июнь",
    "Июль",
    "Августа",
    "Сентябрь",
    "Октябрь",
    "Ноябрь",
    "Декабрь"
};

stock show_phone_general_back(playerid)
{

	new 
		type = phone_background_img[playerid];

	switch(type)
	{
		case 0:
		{
			PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantphone:phone_td_bg1");
			PlayerTextDrawShow(playerid, phone_background_info[playerid]);
		}
		case 1:
		{
			PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantphone:phone_td_bg1");
			PlayerTextDrawShow(playerid, phone_background_info[playerid]);
		}
		case 2:
		{
			PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantphone:phone_td_bg1");
			PlayerTextDrawShow(playerid, phone_background_info[playerid]);
		}
		case 3:
		{
			PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantphone:phone_td_bg1");
			PlayerTextDrawShow(playerid, phone_background_info[playerid]);
		}
		case 4:
		{
			PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantphone:phone_td_bg1");
			PlayerTextDrawShow(playerid, phone_background_info[playerid]);
		}
		case 5:
		{
			PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantphone:phone_td_bg1");
			PlayerTextDrawShow(playerid, phone_background_info[playerid]);
		}
		case 6:
		{
			PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantphone:phone_td_bg1");
			PlayerTextDrawShow(playerid, phone_background_info[playerid]);
		}
		case 7:
		{
			PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantphone:phone_td_bg1");
			PlayerTextDrawShow(playerid, phone_background_info[playerid]);
		}
		case 8:
		{
			PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantphone:phone_td_bg1");
			PlayerTextDrawShow(playerid, phone_background_info[playerid]);
		}
		case 9:
		{
			PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantphone:phone_td_bg1");
			PlayerTextDrawShow(playerid, phone_background_info[playerid]);
		}
		case 10:
		{
			PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantphone:phone_td_bg1");
			PlayerTextDrawShow(playerid, phone_background_info[playerid]);
		}
		case 11:
		{
			PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantphone:phone_td_bg1");
			PlayerTextDrawShow(playerid, phone_background_info[playerid]);
		}
		case 12:
		{
			PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantphone:phone_td_bg1");
			PlayerTextDrawShow(playerid, phone_background_info[playerid]);
		}
		case 13:
		{
			PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantphone:phone_td_bg1");
			PlayerTextDrawShow(playerid, phone_background_info[playerid]);
		}
		case 14:
		{
			PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantphone:phone_td_bg1");
			PlayerTextDrawShow(playerid, phone_background_info[playerid]);
		}
		case 15:
		{
			PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantphone:phone_td_bg1");
			PlayerTextDrawShow(playerid, phone_background_info[playerid]);
		}
		case 16:
		{
			PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantphone:phone_td_bg1");
			PlayerTextDrawShow(playerid, phone_background_info[playerid]);
		}
	}
	PlayerTextDrawShow(playerid, phone_background_info[playerid]);
	return true;
}

stock check_status_phone(playerid)
{
	if(!pData[playerid][pPhone]) 
		return SendErr(playerid, "У Вас нет телефона. Вы можете купить его в Универмаге");

	if(GetPVarIntNew(playerid, "phone_td_status") == 1)
		return hide_phone_general(playerid);

	show_phone_general(playerid);

	return true;
}


stock show_phone_general(playerid)
{
	create_phone_general_p(playerid);
	show_phone_general_back(playerid);


	TextDrawShowForPlayer(playerid, phone_general);

    PlayerTextDrawShow(playerid, phone_background_info[playerid]);

    TextDrawShowForPlayer(playerid, phone_general_player[0]);
    TextDrawShowForPlayer(playerid, phone_general_player[1]);
    TextDrawShowForPlayer(playerid, phone_general_player[2]);
    TextDrawShowForPlayer(playerid, phone_general_player[3]);
    TextDrawShowForPlayer(playerid, phone_general_player[4]);
    TextDrawShowForPlayer(playerid, phone_general_player[5]);
    TextDrawShowForPlayer(playerid, phone_general_player[6]);
    TextDrawShowForPlayer(playerid, phone_general_player[7]);

	SelectTextDraw(playerid, COLOR_BLUE);

	SetPVarIntNew(playerid, "phone_td_status", 1);

	update_clock_phone(playerid);

	return true;
}

stock show_button_taxi_yandex(playerid)
{
	create_phone_yandex_taxi(playerid);

	PlayerTextDrawShow(playerid, yandex_taxi_td[0][playerid]);
	PlayerTextDrawShow(playerid, yandex_taxi_td[1][playerid]);
	PlayerTextDrawShow(playerid, yandex_taxi_td[2][playerid]);
	PlayerTextDrawShow(playerid, yandex_taxi_td[3][playerid]);
	PlayerTextDrawShow(playerid, yandex_taxi_td[4][playerid]);
	return true;
}

stock hide_button_taxi_yandex(playerid)
{
	PlayerTextDrawHideEx(playerid, yandex_taxi_td[0][playerid]);
	PlayerTextDrawHideEx(playerid, yandex_taxi_td[1][playerid]);
	PlayerTextDrawHideEx(playerid, yandex_taxi_td[2][playerid]);
	PlayerTextDrawHideEx(playerid, yandex_taxi_td[3][playerid]);
	PlayerTextDrawHideEx(playerid, yandex_taxi_td[4][playerid]);



	return true;
}


stock show_button_taxi_uber(playerid)
{

	create_phone_uber_taxi(playerid);	

	PlayerTextDrawShow(playerid, uber_taxi_td[0][playerid]);
	PlayerTextDrawShow(playerid, uber_taxi_td[1][playerid]);
	PlayerTextDrawShow(playerid, uber_taxi_td[2][playerid]);
	PlayerTextDrawShow(playerid, uber_taxi_td[3][playerid]);
	PlayerTextDrawShow(playerid, uber_taxi_td[4][playerid]);
	return true;
}

stock hide_button_taxi_uber(playerid)
{
	PlayerTextDrawHideEx(playerid, uber_taxi_td[0][playerid]);
	PlayerTextDrawHideEx(playerid, uber_taxi_td[1][playerid]);
	PlayerTextDrawHideEx(playerid, uber_taxi_td[2][playerid]);
	PlayerTextDrawHideEx(playerid, uber_taxi_td[3][playerid]);
	PlayerTextDrawHideEx(playerid, uber_taxi_td[4][playerid]);
	return true;
}


stock show_button_taxi_city(playerid)
{

	create_phone_sity_taxi(playerid);

	PlayerTextDrawShow(playerid, siti_taxi_select[0][playerid]);
	PlayerTextDrawShow(playerid, siti_taxi_select[1][playerid]);
	PlayerTextDrawShow(playerid, siti_taxi_select[2][playerid]);
	PlayerTextDrawShow(playerid, siti_taxi_select[3][playerid]);
	PlayerTextDrawShow(playerid, siti_taxi_select[4][playerid]);
	return true;
}

stock hide_button_taxi_city(playerid)
{
	PlayerTextDrawHideEx(playerid, siti_taxi_select[0][playerid]);
	PlayerTextDrawHideEx(playerid, siti_taxi_select[1][playerid]);
	PlayerTextDrawHideEx(playerid, siti_taxi_select[2][playerid]);
	PlayerTextDrawHideEx(playerid, siti_taxi_select[3][playerid]);
	PlayerTextDrawHideEx(playerid, siti_taxi_select[4][playerid]);
	return true;
}


stock show_phone_page_taxi(playerid, type_taxi)
{
    TextDrawHideForPlayer(playerid, phone_general_player[0]);
    TextDrawHideForPlayer(playerid, phone_general_player[1]);
    TextDrawHideForPlayer(playerid, phone_general_player[2]);
    TextDrawHideForPlayer(playerid, phone_general_player[3]);
    TextDrawHideForPlayer(playerid, phone_general_player[4]);
    TextDrawHideForPlayer(playerid, phone_general_player[5]);
    TextDrawHideForPlayer(playerid, phone_general_player[6]);
    TextDrawHideForPlayer(playerid, phone_general_player[7]);

	switch(type_taxi)
	{
		case TAXI_COMPANY_YANDEX:
		{
			if(taxi_company[TAXI_COMPANY_YANDEX][taxi_company_count_working] == 0)
			{
				PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantother:yandex_taxi_404");
				PlayerTextDrawShow(playerid, phone_background_info[playerid]);	

				SetPVarIntNew(playerid, "no_active_phone_screen", 1);

				return true;
			}

			if(GetPVarIntNew(playerid, "active_call_taxi"))
			{
				PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantother:yandex_taxi_wait");
				PlayerTextDrawShow(playerid, phone_background_info[playerid]);	

				SetPVarIntNew(playerid, "no_active_phone_screen", 1);

				return true;					
			}

			if(GetPVarIntNew(playerid, "wait_taxi_driver"))
			{
				PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantother:yandex_taxi_accept");
				PlayerTextDrawShow(playerid, phone_background_info[playerid]);		

				SetPVarIntNew(playerid, "no_active_phone_screen", 1);

				return true;					
			}


			show_button_taxi_yandex(playerid);

			PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantother:yandex_taxi_econom_select");
			PlayerTextDrawShow(playerid, phone_background_info[playerid]);	

			SetPVarIntNew(playerid, "taxi_select_phone", TAXI_COMPANY_YANDEX);
		}
		case TAXI_COMPANY_UBER:
		{
			if(taxi_company[TAXI_COMPANY_UBER][taxi_company_count_working] == 0)
			{
				PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantother:uber_taxi_404");
				PlayerTextDrawShow(playerid, phone_background_info[playerid]);

				SetPVarIntNew(playerid, "no_active_phone_screen", 1);

				return true;		
			}

			if(GetPVarIntNew(playerid, "active_call_taxi"))
			{
				PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantother:uber_taxi_wait");
				PlayerTextDrawShow(playerid, phone_background_info[playerid]);

				SetPVarIntNew(playerid, "no_active_phone_screen", 1);	

				return true;					
			}

			if(GetPVarIntNew(playerid, "wait_taxi_driver"))
			{
				PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantother:uber_taxi_accept");
				PlayerTextDrawShow(playerid, phone_background_info[playerid]);	

				SetPVarIntNew(playerid, "no_active_phone_screen", 1);	

				return true;					
			}

			show_button_taxi_uber(playerid);
			PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantother:uber_select_econom");
			PlayerTextDrawShow(playerid, phone_background_info[playerid]);

			SetPVarIntNew(playerid, "taxi_select_phone", TAXI_COMPANY_UBER);
		}
		case TAXI_COMPANY_CITY:
		{
			if(taxi_company[TAXI_COMPANY_CITY][taxi_company_count_working] == 0)
			{
				PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantother:city_taxi_404");
				PlayerTextDrawShow(playerid, phone_background_info[playerid]);

				SetPVarIntNew(playerid, "no_active_phone_screen", 1);

				return true;				
			}

			if(GetPVarIntNew(playerid, "active_call_taxi"))
			{
				PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantother:siti_taxi_wait");
				PlayerTextDrawShow(playerid, phone_background_info[playerid]);	

				SetPVarIntNew(playerid, "no_active_phone_screen", 1);

				return true;					
			}

			if(GetPVarIntNew(playerid, "wait_taxi_driver"))
			{
				PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantother:siti_taxi_accept");
				PlayerTextDrawShow(playerid, phone_background_info[playerid]);	

				SetPVarIntNew(playerid, "no_active_phone_screen", 1);	

				return true;					
			}

			show_button_taxi_city(playerid);

			PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantother:siti_taxi_econom_select");
			PlayerTextDrawShow(playerid, phone_background_info[playerid]);

			SetPVarIntNew(playerid, "taxi_select_phone", TAXI_COMPANY_CITY);

		}
	}

	return true;
}

stock update_clock_phone(playerid)
{
	if(GetPVarIntNew(playerid, "phone_td_status") == 1)
	{
		new
			hour, minuite;

		gettime(hour, minuite);

    	format(String64,sizeof(String64),"%02d:%02d",hour,minuite);
    	TextDrawSetString(phone_general, String64);	
    	TextDrawShowForPlayer(playerid, phone_general);
    }
    return true;
}

stock hide_phone_general(playerid)
{
	PlayerTextDrawHideEx(playerid, phone_background_info[playerid]);
	TextDrawHideForPlayer(playerid, phone_general_player[0]);
	TextDrawHideForPlayer(playerid, phone_general_player[1]);
	TextDrawHideForPlayer(playerid, phone_general_player[2]);
	TextDrawHideForPlayer(playerid, phone_general_player[3]);
	TextDrawHideForPlayer(playerid, phone_general_player[4]);
	TextDrawHideForPlayer(playerid, phone_general_player[5]);
	TextDrawHideForPlayer(playerid, phone_general_player[6]);
	TextDrawHideForPlayer(playerid, phone_general_player[7]);

	hide_button_taxi_yandex(playerid);
	hide_button_taxi_uber(playerid);
	hide_button_taxi_city(playerid);

	TextDrawHideForPlayer(playerid, phone_general);	

	CancelSelectTextDraw(playerid);

	DeletePVarNew(playerid, "phone_td_status");
	DeletePVarNew(playerid, "no_active_phone_screen");

	UpdatePlayerData(playerid,"phone_background_img", phone_background_img[playerid]);

	return true;
}

stock show_setting_phone(playerid)
{
    return SPD(playerid, DIALOG_SETTING_PHONE_1, DIALOG_STYLE_LIST, !""cBLUE"Выбор фона", 
    ""cBLUE"-"cWH" Фоновая заставка №1\n\
    "cBLUE"-"cWH" Фоновая заставка №2\n\
    "cBLUE"-"cWH" Фоновая заставка №3\n\
    "cBLUE"-"cWH" Фоновая заставка №4\n\
    "cBLUE"-"cWH" Фоновая заставка №5\n\
    "cBLUE"-"cWH" Фоновая заставка №6\n\
    "cBLUE"-"cWH" Фоновая заставка №7\n\
    "cBLUE"-"cWH" Фоновая заставка №8\n\
    "cBLUE"-"cWH" Фоновая заставка №9\n\
    "cBLUE"-"cWH" Фоновая заставка №10\n\
    "cBLUE"-"cWH" Фоновая заставка №11\n\
    "cBLUE"-"cWH" Фоновая заставка №12\n\
    "cBLUE"-"cWH" Фоновая заставка №13\n\
    "cBLUE"-"cWH" Фоновая заставка №14\n\
    "cBLUE"-"cWH" Фоновая заставка №15\n\
    "cBLUE"-"cWH" Фоновая заставка №16", "Выбрать","Отмена");
}

stock show_calendar_phone(playerid)
{

    new year, month, day;
    getdate(year, month, day);


    format(String256, sizeof(String256), "\
    "cGREY"№\t"cGREY"Дата\n\
    "cWH"Год\t"cBLUE"%d\n\
    "cWH"Месяц\t"cBLUE"%s (%d)\n\
    "cWH"День\t"cBLUE"%s (%d)", 
    year,
    mounth_phone_calendar[month], month,
    day_name_phone_calendar[get_number_day(year, month, day)], day);
    return SPD(playerid, DIALOG_PHONE_CALENDAR, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Календарь телефона", String256, !"Закрыть", "");     
}

stock show_note_phone(playerid)
{

    new year, month, day;
    getdate(year, month, day);


    format(String144, sizeof(String144), "\
    "cGREY"№\t"cGREY"Действие\n\
    "cWH"Создать заметку\t"cBLUE"Создать\n\
    "cWH"Просмотреть текущие заметки\t"cBLUE"Читать");
    return SPD(playerid, DIALOG_PHONE_NOTE_MENU, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Заметки телефона", String144, !"Далее", "Закрыть");     
}


stock note_show_player_all(playerid)
{
    format(String2048, sizeof(String2048), ""cGREY"№\t"cGREY"Заметка\t"cGREY"Дата\n");


	format(String256,sizeof(String256),"SELECT * FROM phone_note_player WHERE note_player_id = '%d' LIMIT 10", pData[playerid][pMysqlID]);
	new Result:r = sql_queryEx(zConn, String256, QUERY_CACHED);

	new 
		all_new_message = sql_num_rows(r);

	new 
		counts_message = 0;

 	for(new i; i < all_new_message; i++)
	{

		new 
			note_phone_id_dialog,
			note_phone_dialog_date[20],
			note_phone_dialog_msg[128],
			note_phone_dialog_msg_prewiow[128];


		note_phone_id_dialog = sql_get_field_assoc_int_ex(r, i, "note_id");
		sql_get_field_assoc_ex(r, i,"note_date", note_phone_dialog_date, 20);
		sql_get_field_assoc_ex(r, i,"note_msg", note_phone_dialog_msg, 128);
		sql_get_field_assoc_ex(r, i,"note_msg", note_phone_dialog_msg_prewiow, MAX_PLAYER_NAME);

		strdel(note_phone_dialog_msg_prewiow, 15, 128);

		dialog_listitem_values[playerid][i] = note_phone_id_dialog;

    	format(String2048, sizeof(String2048), "%s"cBLUE"%d."cWH"\t%s..\t"cBLUE"%s"cWH"\n",String2048, \
    	counts_message+1, note_phone_dialog_msg_prewiow, note_phone_dialog_date);

    	counts_message++;

	}
	sql_free_result(r);

	return SPD(playerid, DIALOG_SELECT_NOTE_PHONE, DIALOG_STYLE_TABLIST_HEADERS ,""cBLUE"Заметки",String2048,"Открыть","Закрыть");
}

stock learn_note_phone(playerid, message_id)
{

	SetPVarIntNew(playerid, "note_phone_id", message_id);

	format(String256,sizeof(String256),"SELECT * FROM phone_note_player WHERE note_id = '%d' AND note_player_id = '%d'", message_id, pData[playerid][pMysqlID]);
	new Result:r = sql_queryEx(zConn, String256, QUERY_CACHED);

	if(sql_num_rows(r)) 
	{
		new 
			note_phone_dialog_date[20],
			note_phone_dialog_msg[128];


		sql_get_field_assoc_ex(r, 0, "note_date", note_phone_dialog_date, 20);
		sql_get_field_assoc_ex(r, 0, "note_msg", note_phone_dialog_msg, 128);

		format(String256, sizeof(String256), "\
			"cWH"Дата создания: "cBLUE"%s\n\n\
			"cWH"Заметка: \n\
			%s", note_phone_dialog_date, note_phone_dialog_msg);
		SPD(playerid, DIALOG_PHONE_NOTE_LEARN, DIALOG_STYLE_MSGBOX, !""cBLUE"Заметка", String256, !"Удалить", !"Закрыть");


	}
	sql_free_result(r);
	return true;
}

stock note_phone_delete(playerid)
{
	new 
		note_id = GetPVarIntNew(playerid, "note_phone_id");

    format(String256, sizeof(String256), "DELETE FROM `phone_note_player` WHERE `note_id` = '%d' AND note_player_id = '%d'", note_id, pData[playerid][pMysqlID]);
    sql_queryEx(zConn, String256);

    SendInf(playerid, "Заметка была успешно удалена!");

    note_show_player_all(playerid);
	return true;
}

stock create_note_phone(playerid)
{
	return SPD(playerid, DIALOG_CREATE_NOTE, DIALOG_STYLE_INPUT, !""cBLUE"Создание заметки", !"\
	"cWH"Введите заметку, которую хотите создать\n\n"cBLUE"От 5 и до 128 символов!", !"Далее", !"Назад");
}

stock dialog_all_phone(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
		case DIALOG_SETTING_PHONE_1:
		{
			if(!response)
				return SelectTextDraw(playerid, COLOR_BLUE);			

			switch(listitem)
			{
				case 0: 
				{	
					phone_background_img[playerid] = 1;
					show_phone_general_back(playerid);
					show_setting_phone(playerid);
				}
				case 1: 
				{
					phone_background_img[playerid] = 1;
					show_phone_general_back(playerid);
					show_setting_phone(playerid);
				}
				case 2: 
				{
					phone_background_img[playerid] = 2;
					show_phone_general_back(playerid);
					show_setting_phone(playerid);
				}
				case 3: 
				{
					phone_background_img[playerid] = 3;
					show_phone_general_back(playerid);
					show_setting_phone(playerid);
				}
				case 4: 
				{
					phone_background_img[playerid] = 4;
					show_phone_general_back(playerid);
					show_setting_phone(playerid);
				}
				case 5: 
				{
					phone_background_img[playerid] = 5;
					show_phone_general_back(playerid);
					show_setting_phone(playerid);
				}
				case 6: 
				{
					phone_background_img[playerid] = 6;
					show_phone_general_back(playerid);
					show_setting_phone(playerid);
				}
				case 7: 
				{
					phone_background_img[playerid] = 7;
					show_phone_general_back(playerid);
					show_setting_phone(playerid);
				}
				case 8: 
				{
					phone_background_img[playerid] = 8;
					show_phone_general_back(playerid);
					show_setting_phone(playerid);
				}
				case 9: 
				{
					phone_background_img[playerid] = 9;
					show_phone_general_back(playerid);
					show_setting_phone(playerid);
				}
				case 10: 
				{
					phone_background_img[playerid] = 10;
					show_phone_general_back(playerid);
					show_setting_phone(playerid);
				}
				case 11: 
				{
					phone_background_img[playerid] = 11;
					show_phone_general_back(playerid);
					show_setting_phone(playerid);
				}
				case 12: 
				{
					phone_background_img[playerid] = 12;
					show_phone_general_back(playerid);
					show_setting_phone(playerid);
				}
				case 13: 
				{
					phone_background_img[playerid] = 13;
					show_phone_general_back(playerid);
					show_setting_phone(playerid);
				}
				case 14: 
				{
					phone_background_img[playerid] = 14;
					show_phone_general_back(playerid);
					show_setting_phone(playerid);
				}
				case 15: 
				{
					phone_background_img[playerid] = 15;
					show_phone_general_back(playerid);
					show_setting_phone(playerid);
				}
				case 16: 
				{
					phone_background_img[playerid] = 16;
					show_phone_general_back(playerid);
					show_setting_phone(playerid);
				}
			}
		}
		case DIALOG_PHONE_NOTE_LEARN:
		{
			if(!response)
			{
				return note_show_player_all(playerid);
			}
			return note_phone_delete(playerid);
		}
		case DIALOG_SELECT_NOTE_PHONE:	
		{
			if(!response)
				return SelectTextDraw(playerid, COLOR_BLUE);

			new 
				id = dialog_listitem_values[playerid][listitem];

			return learn_note_phone(playerid, id);
		}
		case DIALOG_PHONE_NOTE_MENU:
		{
			if(!response)
				return SelectTextDraw(playerid, COLOR_BLUE);

			switch(listitem)
			{
				case 0: return create_note_phone(playerid);
				case 1: return note_show_player_all(playerid);
			}

		}
		case DIALOG_CREATE_NOTE:
		{
			if(!response)
				return show_note_phone(playerid);


			if(strlen(inputtext) < 3 || strlen(inputtext) > 20)
			{
			    SendErr(playerid,"Слишком короткий/длинный текст заметки!");
				return create_note_phone(playerid);
			}
			if(IsNumeric(inputtext) || check_no_valid_symbol_text(inputtext) || check_sql_injection_text(inputtext))
			{
				create_note_phone(playerid);
				return SendErr(playerid,"Заметка содержит запрещенные символы!");
			}

			format(String256f,sizeof(String256f), "INSERT INTO phone_note_player(note_player_id, note_msg) VALUES ('%d','%s')", pData[playerid][pMysqlID], inputtext);
			sql_queryEx(zConn, String256f, QUERY_THREADED);

			SendInf(playerid, "Заметка была успешна создана!");

			show_note_phone(playerid);
		}
	    case DIALOG_PHONE_CALENDAR: 
	    {
	    	if(!response) 
	    		return SelectTextDraw(playerid, COLOR_BLUE);

	    	return SelectTextDraw(playerid, COLOR_BLUE);
	    }
	}
	return true;
}

