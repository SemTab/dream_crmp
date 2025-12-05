CMD:security(playerid)
{
	return show_security_menu(playerid);
}

stock show_security_menu(playerid)
{
	format(String144, sizeof(String144), "\
		"cGREY"Действие\t"cGREY"Статус\n\
		"cBLUE"1. "cWH"Изменить пароль\n\
		"cBLUE"2. "cWH"Код безопасности\t%s", 
		pData[playerid][pSecurityCode] != 0 ? (""cGR"[Установлен]") : (""cLRED"[Не установлен]"));

	SPD(playerid, DIALOG_SECURITY_SELECT, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Безопасность", String144, !"Выбрать", !"Закрыть");
	return true;
}

stock change_password_player(playerid, stage)
{
	switch(stage)
	{
		case 0:
		{
			return SPD(playerid, DIALOG_CHANGE_PASS_OLD, DIALOG_STYLE_PASSWORD, !""cBLUE"Изменение пароля", !"\n\
				"cWH"Введите Ваш "cBLUE"старый "cWH"пароль:", !"Далее", !"Отмена");
		}
		case 1:
		{
			return SPD(playerid, DIALOG_CHANGE_PASS_NEW, DIALOG_STYLE_PASSWORD, !""cBLUE"Изменение пароля", !"\n\
				"cWH"Введите Ваш "cBLUE"новый "cWH"пароль:", !"Далее", !"Отмена");
		}
		case 2:
		{
			return SPD(playerid, DIALOG_CHANGE_PASS_REPEAT, DIALOG_STYLE_PASSWORD, !""cBLUE"Изменение пароля", !"\n\
				"cWH"Введите повторно Ваш "cBLUE"новый "cWH"пароль:", !"Далее", !"Отмена");
		}
	}
	return true;
}

stock dialog_edit_code(playerid, stage)
{
	switch(stage)
	{
		case 0:
		{
			return SPD(playerid, DIALOG_CHANGE_CODE_OLD, DIALOG_STYLE_INPUT, !""cBLUE"Изменение кода безопасности", !"\n\
				"cWH"Перед тем как изменить, Вам необходимо\n\
				"cWH"Ввести "cBLUE"старый "cWH"код безопасности", !"Далее", !"Отмена");
		}
		case 1:
		{
			return SPD(playerid, DIALOG_CHANGE_CODE_NEW, DIALOG_STYLE_INPUT, !""cBLUE"Изменение кода безопасности", !"\n\
				"cWH"Вы успешно ввели старый код!\n\
				"cWH"Теперь необходимо ввести "cBLUE"новый "cWH"код безопасности\n\n\
				"cGREY"Код должен состоять из 6 цифр", !"Далее", !"Отмена");
		}
	}	
	return true;
}

stock dialog_add_code(playerid)
{
	SPD(playerid, DIALOG_ADD_CODE, DIALOG_STYLE_INPUT, !""cBLUE"Код безопасности", !"\n\
		"cWH"Введите код безопасности\n\
		"cWH"Он будет запрашиваться при "cBLUE"каждом "cWH"входе в игру\n\n\
		"cGREY"Код должен состоять из 6 цифр", !"Далее", !"Отмена");
	return true;
}

stock dialog_remove_code(playerid)
{
	SPD(playerid, DIALOG_REMOVE_SECURITY_CODE, DIALOG_STYLE_INPUT, !""cBLUE"Удаление кода безопасности", !"\n\
		"cWH"Перед тем как удалить код, Вам необходимо\n\
		"cWH"Ввести код безопасности", !"Далее", !"Отмена");
	return true;
}

stock dialog_security(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
		case DIALOG_SECURITY_SELECT:
		{
			if(!response)
				return true;

			switch(listitem)
			{
				case 0:
				{
					if(pData[playerid][pSecurityCode] != 0)
					{
						 return SPD(playerid, DIALOG_CHANGE_PASS_CODE, DIALOG_STYLE_INPUT, !""cBLUE"Изменение пароля", !"\n\
							"cWH"Введите  код безопасности:", !"Далее", !"Отмена");
					}
					else
					{
						return change_password_player(playerid, 0);
					}
				}
				case 1:
				{
					if(pData[playerid][pSecurityCode] != 0)
					{
						return SPD(playerid, DIALOG_SELECT_CODE, DIALOG_STYLE_LIST, !""cBLUE"Код безопасности", "\
							"cBLUE"1. "cWH"Изменить код безопасности\n\
							"cBLUE"2. "cWH"Удалить код безопасности",
							!"Выбрать", !"Назад");
					}
					else 
					{
						return dialog_add_code(playerid);
					}
				}
			}
			return true;
		}
		case DIALOG_CHANGE_PASS_CODE:
		{
			if(!response)
				return show_security_menu(playerid);

			if(!strlen(inputtext))
				return SPD(playerid, DIALOG_CHANGE_PASS_CODE, DIALOG_STYLE_INPUT, !""cBLUE"Изменение пароля", !"\n\
							"cWH"Введите  код безопасности:", !"Далее", !"Отмена");

			if(pData[playerid][pSecurityCode] != strval(inputtext))
				return SendErr(playerid, "Код безопасности введен неверно");

			change_password_player(playerid, 0);
			return true;
		}
		case DIALOG_CHANGE_PASS_OLD:
		{
			if(!response)
				return show_security_menu(playerid);

			if(!strlen(inputtext))
				return change_password_player(playerid, 0);

			if(strcmp(MD5_Hash(inputtext), pData[playerid][pPassword], true))
				return SendErr(playerid, "Пароль введён неверно");

			change_password_player(playerid, 1);
			return true;
		}
		case DIALOG_CHANGE_PASS_NEW:
		{
			if(!response)
				return show_security_menu(playerid);

			if(!strlen(inputtext))
				return change_password_player(playerid, 1);

			if(strlen(inputtext) < 6 || strlen(inputtext) > 22)
					return SendErr(playerid, "Длина пароля должна быть от 6-и до 22-х символов");

			if(!strcmp(MD5_Hash(inputtext), pData[playerid][pPassword], true))
				return SendErr(playerid, "Новый пароль совпадает со старым");


			SetPVarString(playerid, "new_pass", inputtext);

			change_password_player(playerid, 2);
			return true;
		}
		case DIALOG_CHANGE_PASS_REPEAT:
		{
			new 
				pass[22];

			GetPVarString(playerid, "new_pass", pass, 22);
			DeletePVar(playerid, "new_pass");

			if(!response)
				return show_security_menu(playerid);

			if(!strlen(inputtext))
				return change_password_player(playerid, 2);

			if(strcmp(inputtext, pass))
				return SendErr(playerid, "Введённые пароли не совпадают");	

			format(String144,sizeof(String144),"UPDATE `accounts` SET password = MD5('%s') WHERE id = '%d'", inputtext, pData[playerid][pMysqlID]);
			sql_queryEx(zConn, String144);

			format(pData[playerid][pPassword], 33, "%s", MD5_Hash(inputtext));

			format(String256, sizeof(String256), "\n\
				"cWH"Поздравляем!\n\
				"cWH"Вы успешно сменили пароль от аккаунта!\n\
				"cWH"Новый пароль: "cBLUE"%s\n\n\
				"cWH"Запишите или запомните его!", 
				inputtext);
			SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Смена пароля", String256, !"Принять", "");

			show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_37", 5000);

			NewKick(playerid);
			return true;
		}
		case DIALOG_SELECT_CODE:
		{
			if(!response)
				return show_security_menu(playerid);

			switch(listitem)
			{
				case 0:
				{
					return dialog_edit_code(playerid, 0);
				}
				case 1:
				{
					return dialog_remove_code(playerid);
				}
			}
			return true;
		}
		case DIALOG_CHANGE_CODE_OLD:
		{
			if(!response)
				return show_security_menu(playerid);

			if(!strlen(inputtext))
				return dialog_edit_code(playerid, 0);

			if(pData[playerid][pSecurityCode] != strval(inputtext))
				return SendErr(playerid, "Код безопасности введен неверно");

			dialog_edit_code(playerid, 1);
			return true;
		}
		case DIALOG_CHANGE_CODE_NEW:
		{
			if(!response)
				return show_security_menu(playerid);

			if(strlen(inputtext) != 6 || !IsNumeric(inputtext))
			{
				SendErr(playerid, "Код безопасности должен содержать 6 цифр");
				return dialog_edit_code(playerid, 1);
			}

			if(pData[playerid][pSecurityCode] == strval(inputtext))
			{
				SendErr(playerid, "Новый код не должен быть старым");
				return dialog_edit_code(playerid, 1);
			}

			pData[playerid][pSecurityCode] = strval(inputtext);
			UpdatePlayerData(playerid, "security_code", pData[playerid][pSecurityCode]);

			show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_38", 5000);

			format(String256, sizeof(String256), "\n\
				"cWH"Поздравляем!\n\
				"cWH"Вы успешно сменили код безопасности аккаунта!\n\n\
				"cWH"Новый код: "cBLUE"%s\n\n\
				"cWH"Запишите или запомните его!\n\
				"cWH"Он будет запрашиваться при "cBLUE"каждом "cWH"входе в игру", 
				inputtext);
			SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Смена кода безопасности", String256, !"Принять", "");
			return true;
		}
		case DIALOG_ADD_CODE:
		{
			if(!response)
				return show_security_menu(playerid);

			if(strlen(inputtext) != 6 || !IsNumeric(inputtext))
			{
				SendErr(playerid, "Код безопасности должен содержать 6 цифр");
				return dialog_edit_code(playerid, 1);
			}

			pData[playerid][pSecurityCode] = strval(inputtext);
			UpdatePlayerData(playerid, "security_code", pData[playerid][pSecurityCode]);


			format(String256, sizeof(String256), "\n\
				"cWH"Поздравляем!\n\
				"cWH"Вы успешно установили код безопасности аккаунта!\n\n\
				"cWH"Код: "cBLUE"%s\n\n\
				"cWH"Запишите или запомните его!\n\
				"cWH"Он будет запрашиваться при "cBLUE"каждом "cWH"входе в игру", 
				inputtext);
			SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Установка кода безопасности", String256, !"Принять", "");
			return true;
		}
		case DIALOG_REMOVE_SECURITY_CODE:
		{
			if(!response)
				return show_security_menu(playerid);

			if(!strlen(inputtext))
				return dialog_remove_code(playerid);

			if(pData[playerid][pSecurityCode] != strval(inputtext))
				return SendErr(playerid, "Код безопасности введен неверно");

			pData[playerid][pSecurityCode] = 0;
			UpdatePlayerData(playerid, "security_code", pData[playerid][pSecurityCode]);


			SendSucc(playerid, "Вы успешно удалили код безопасности аккаунта");
			return true;
		}
		case DIALOG_INPUT_SECURITY_CODE:
		{
			if(pData[playerid][pSecurityCode] != strval(inputtext) || !response)
			{
				SendErr(playerid, "Код безопасности введен неверно");
				NewKick(playerid);
				return true;
			}
			clear_chat_for_login(playerid);

			pTemp[playerid][pLogined] = true;

			LoadPlayerData(playerid);
			SetPlayerScore(playerid,pData[playerid][pLevel]);



			if(IsActionTrue2) 
			{
				SCM(playerid, 0x33AA33FF, "Внимание! Сегодня действует акция удвоенного ЕХР!");
			}
			if(IsActionTrue4) 
			{
				SCM(playerid, 0x33AA33FF, "Внимание! Сегодня действует акция удвоенной зарплаты на начальных работах и организациях!");
			}
			if(IsActionTrue) 
			{
				SCM(playerid, 0x33AA33FF, "Внимание! Сегодня действует скидка на все платные услуги!");
				SCM(playerid, 0x33AA33FF, "Подробнее в "cWH"/donate");
			}

			if(IsActionTrue5)
			{
				SCM(playerid, COLOR_ORANGE, "Внимание! Отыграйте 10 часов и получите бонус в размере 100.000 рублей!");
			}

			SpawnPlayer(playerid);
			CancelSelectTextDraw(playerid);

	   		format(String256, 150, "UPDATE accounts SET `last` = NOW() WHERE id = '%d'", pData[playerid][pMysqlID]);
	   		sql_queryEx(zConn, String256 , QUERY_THREADED);

	   		load_bind_command_player(playerid);

			if(GetPVarIntNew(playerid, "hud_hide") != 1)
			{
				show_hud_element(playerid);
				show_hud_hungry(playerid);
			}

	   		KillTimer(login_timer_p[playerid]);
	   		KillTimer(login_timer_p_2[playerid]);
			return true;
		}
	}
	return true;
}

stock get_player_security_code(playerid)
{
	format(String144, sizeof(String144), "\n\
		"cWH"К аккаунту "cBLUE"%s "cWH"привязан код безопасности\n\
		"cWH"Вам необходимо ввести его:", pData[playerid][pNickname]);

	SPD(playerid, DIALOG_INPUT_SECURITY_CODE, DIALOG_STYLE_INPUT, !""cBLUE"Код безопасности", String144, !"Далее", !"Отмена");
	return true;
}