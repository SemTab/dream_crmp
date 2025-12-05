

CMD:quest(playerid)
{
	show_dialog_quest_manual(playerid);

	return true;
}

stock show_dialog_quest_manual(playerid)
{
	SPD(playerid, DIALOG_SELECT_QUEST_START, DIALOG_STYLE_LIST, ""cBLUE"Квесты",""cBLUE"1. "cWH"Список заданий\n\
	"cBLUE"2. "cWH"Как принять квест?","Выбор","Выход");

	return true;
}

stock show_quest_panel(playerid)
{
	if(pData[playerid][pQuestShow] == 0)
	{
		show_newyear_quest_previow(playerid);
		return true;
	}


	show_quest_systems_general(playerid, TEXTDRAW_HIDE);
	show_quest_systems_general(playerid, TEXTDRAW_SHOW);
	show_quest_systems_general(playerid, TEXTDRAW_HIDE);
	show_quest_systems_general(playerid, TEXTDRAW_SHOW);

	return true;
}



stock show_info_start_quest(playerid) 
{

	SPD(playerid, DIALOG_SELECT_QUEST_INFO, DIALOG_STYLE_MSGBOX, !""cBLUE"Информация о квестах", !"\
	"cBLUE"-"cWH" Квестовые задания никак не нужно начинать или нажимать какие-то кнопки!\n\n\
	В меню с квестами Вы можете ознакомиться с условиями для выполнения квеста\n\
	Все остальные процессы происходят автоматически, как и выдача вознаграждения!\n\n\
	Выполнили условия - автоматически получили вознаграждение, всё просто!", !"Далее", "");	

	return true;
}

stock show_quest_systems_general(playerid, type)
{
	switch(type)
	{
		case TEXTDRAW_SHOW:
		{
			create_quest_general_p(playerid);

			PlayerTextDrawShow(playerid, quest_general_panel_s[0][playerid]);
			PlayerTextDrawShow(playerid, quest_general_panel_s[1][playerid]);
			PlayerTextDrawShow(playerid, quest_general_panel_s[2][playerid]);
			PlayerTextDrawShow(playerid, quest_general_panel_s[3][playerid]);
			PlayerTextDrawShow(playerid, quest_general_panel_s[4][playerid]);
			PlayerTextDrawShow(playerid, quest_general_panel_s[5][playerid]);

			SelectTextDraw(playerid, COLOR_BLUE);
		}
		case TEXTDRAW_HIDE:
		{
			PlayerTextDrawHideEx(playerid, quest_general_panel_s[0][playerid]);
			PlayerTextDrawHideEx(playerid, quest_general_panel_s[1][playerid]);
			PlayerTextDrawHideEx(playerid, quest_general_panel_s[2][playerid]);
			PlayerTextDrawHideEx(playerid, quest_general_panel_s[3][playerid]);
			PlayerTextDrawHideEx(playerid, quest_general_panel_s[4][playerid]);
			PlayerTextDrawHideEx(playerid, quest_general_panel_s[5][playerid]);

			CancelSelectTextDraw(playerid);
		}
	}
	return true;
}


stock show_quest_select_pane(playerid, type)
{
	show_quest_systems_general(playerid, TEXTDRAW_HIDE);

	switch(type)
	{
		case 0:
		{	
			show_quest_systems_general(playerid, TEXTDRAW_HIDE);
		}
		case 1:
		{
			show_quest_panel(playerid);
		}
		case 2:
		{

		}
	}
}

stock show_quest_systems_panel(playerid, type)
{

	switch(type)
	{
		case TEXTDRAW_SHOW:
		{
			show_quest_systems_general(playerid, TEXTDRAW_HIDE);

			create_quest_p(playerid);

			PlayerTextDrawSetString(playerid, quest_panel_general_p[0][playerid], "brp_quest:quest_background_clear");
			PlayerTextDrawShow(playerid, quest_panel_general_p[0][playerid]);

			PlayerTextDrawShow(playerid, quest_panel_general_p[1][playerid]);
			PlayerTextDrawShow(playerid, quest_panel_general_p[2][playerid]);
			PlayerTextDrawShow(playerid, quest_panel_general_p[3][playerid]);

			PlayerTextDrawSetString(playerid,  quest_panel_general_p[4][playerid], "brp_quest:quest_button_1_no_select");
			PlayerTextDrawShow(playerid,  quest_panel_general_p[4][playerid]);
			PlayerTextDrawSetString(playerid,  quest_panel_general_p[5][playerid], "brp_quest:quest_button_2_no_select");
			PlayerTextDrawShow(playerid,  quest_panel_general_p[5][playerid]);	
			PlayerTextDrawSetString(playerid,  quest_panel_general_p[6][playerid], "brp_quest:quest_button_3_no_select");
			PlayerTextDrawShow(playerid,  quest_panel_general_p[6][playerid]);	
			PlayerTextDrawSetString(playerid, quest_panel_general_p[7][playerid], "brp_quest:quest_button_4_no_select");
			PlayerTextDrawShow(playerid, quest_panel_general_p[7][playerid]);	

			PlayerTextDrawShow(playerid, quest_panel_general_p[8][playerid]);
			PlayerTextDrawShow(playerid, quest_panel_general_p[9][playerid]);
			//PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);

			PlayerTextDrawSetString(playerid, quest_panel_general_p[12][playerid], "1/5");
			PlayerTextDrawShow(playerid, quest_panel_general_p[12][playerid]);	

			TogglePlayerHudElement(playerid, HUD_ELEMENT_TAGS, HUD_ELEMENT_HIDE);

			SelectTextDraw(playerid, COLOR_BLUE);

			SetPVarIntNew(playerid, "select_quest_number_panel", QUEST_PAGE_SELECT_1);

			show_quest_panel_page(playerid, QUEST_PAGE_1);


			page_quest_panel[playerid] = 1;

		}
		case TEXTDRAW_HIDE:
		{
			PlayerTextDrawHideEx(playerid, quest_panel_general_p[0][playerid]);
			PlayerTextDrawHideEx(playerid, quest_panel_general_p[1][playerid]);
			PlayerTextDrawHideEx(playerid, quest_panel_general_p[2][playerid]);
			PlayerTextDrawHideEx(playerid, quest_panel_general_p[3][playerid]);
			PlayerTextDrawHideEx(playerid, quest_panel_general_p[4][playerid]);
			PlayerTextDrawHideEx(playerid, quest_panel_general_p[5][playerid]);
			PlayerTextDrawHideEx(playerid, quest_panel_general_p[6][playerid]);
			PlayerTextDrawHideEx(playerid, quest_panel_general_p[7][playerid]);
			PlayerTextDrawHideEx(playerid, quest_panel_general_p[8][playerid]);
			PlayerTextDrawHideEx(playerid, quest_panel_general_p[9][playerid]);
			PlayerTextDrawHideEx(playerid, quest_panel_general_p[10][playerid]);
			PlayerTextDrawHideEx(playerid, quest_panel_general_p[11][playerid]);
			PlayerTextDrawHideEx(playerid, quest_panel_general_p[12][playerid]);

			TogglePlayerHudElement(playerid, HUD_ELEMENT_TAGS, HUD_ELEMENT_SHOW);

			CancelSelectTextDraw(playerid);
		}
	}


	return true;
}

stock get_prize_quest(h)
{
	new 
		name[40];

	switch(h)
	{
		case 1: name = "500_RUB";
		case 2: name = "750_RUB";
		case 3: name = "1_EXP_750_RUB";
		case 4: name = "1_EXP_5000_RUB";
		case 5: name = "1_EXP_5000_RUB";
		case 6: name = "2_EXP_10000_RUB";
		case 7: name = "2_EXP_10000_RUB";
		case 8: name = "750_RUB";
		case 9: name = "750_RUB";
		case 10: name = "750_RUB";
		case 11: name = "1_EXP_2000_RUB";
		case 12: name = "250_RUB";
		case 13: name = "250_RUB";
		case 14: name = "250_RUB";
		case 15: name = "1_EXP_2500_RUB";
		case 16: name = "1_EXP_2500_RUB";
		case 17: name = "1_EXP_500_RUB";
		case 18: name = "1000_RUB";
		case 19: name = "1_EXP_2500_RUB";
		case 20: name = "3_EXP_15000_RUB";
		default: name = "Заброшенный";
	}
	return name;
}

stock next_page_quest_panel(playerid)
{	

	if(page_quest_panel[playerid] == 5)
		return true;

	page_quest_panel[playerid]++;

	show_quest_panel_page(playerid, page_quest_panel[playerid]);

	SetPVarIntNew(playerid, "select_quest_number_panel", QUEST_PAGE_SELECT_1);

	new 
		fmt_str[90];

 	format(fmt_str,sizeof(fmt_str),"%d/5", page_quest_panel[playerid]);
	PlayerTextDrawSetString(playerid, quest_panel_general_p[12][playerid], fmt_str);
	PlayerTextDrawShow(playerid, quest_panel_general_p[12][playerid]);	


 	format(fmt_str,sizeof(fmt_str),"%s", get_prize_quest(page_quest_panel[playerid]));
	PlayerTextDrawSetString(playerid, quest_panel_general_p[11][playerid], fmt_str);
	PlayerTextDrawShow(playerid, quest_panel_general_p[11][playerid]);	

	return true;

}

stock prew_page_quest_panel(playerid)
{
	if(page_quest_panel[playerid] == 1)
		return true;

	page_quest_panel[playerid]--;

	show_quest_panel_page(playerid, page_quest_panel[playerid]);	

	SetPVarIntNew(playerid, "select_quest_number_panel", QUEST_PAGE_SELECT_1);

	new 
		fmt_str[90];

 	format(fmt_str,sizeof(fmt_str),"%d/5", page_quest_panel[playerid]);
	PlayerTextDrawSetString(playerid, quest_panel_general_p[12][playerid], fmt_str);
	PlayerTextDrawShow(playerid, quest_panel_general_p[12][playerid]);	

 	format(fmt_str,sizeof(fmt_str),"%s", get_prize_quest(page_quest_panel[playerid]));
	PlayerTextDrawSetString(playerid, quest_panel_general_p[11][playerid], fmt_str);
	PlayerTextDrawShow(playerid, quest_panel_general_p[11][playerid]);	

	return true;
}

stock close_quest_panel(playerid)
{
	show_quest_systems_panel(playerid, TEXTDRAW_HIDE);
	SetCameraBehindPlayer(playerid);

	return true;
}

stock start_quest_panel_new(playerid)
{
	if(pData[playerid][pQuestStandart][0] == 0)
	{
		pData[playerid][pQuestStandart][0] = 1;
		PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_final");
		PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);		

		check_quest_prize_start(playerid, 0);	
	}
	return true;
}

stock show_quest_panel_page(playerid, page)
{

	new 
		fmt_str[90];


	switch(page)
	{
		case QUEST_PAGE_1:
		{
			if(!GetPVarIntNew(playerid, "select_quest_number_panel"))
			{
				PlayerTextDrawSetString(playerid, quest_panel_general_p[0][playerid], "brp_quest:quest_background_clear");
				PlayerTextDrawShow(playerid, quest_panel_general_p[0][playerid]);

				PlayerTextDrawSetString(playerid, quest_panel_general_p[4][playerid], "brp_quest:quest_button_1_no_select");
				PlayerTextDrawShow(playerid, quest_panel_general_p[4][playerid]);
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[5][playerid], "brp_quest:quest_button_2_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[5][playerid]);	
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[6][playerid], "brp_quest:quest_button_3_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[6][playerid]);	
				PlayerTextDrawSetString(playerid, quest_panel_general_p[7][playerid], "brp_quest:quest_button_4_no_select");
				PlayerTextDrawShow(playerid, quest_panel_general_p[7][playerid]);	

				check_quest_prize_start(playerid, 0);

				if(pData[playerid][pQuestStandart][0] == 0)
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_no_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);	
				}	
				else
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);						
				}
				start_quest_panel_new(playerid);
							
			}
			else if(GetPVarIntNew(playerid, "select_quest_number_panel") == QUEST_PAGE_SELECT_1)
			{
				PlayerTextDrawSetString(playerid, quest_panel_general_p[0][playerid], "brp_quest:quest_background_1");
				PlayerTextDrawShow(playerid, quest_panel_general_p[0][playerid]);

				PlayerTextDrawSetString(playerid,  quest_panel_general_p[4][playerid], "brp_quest:quest_button_1_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[4][playerid]);
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[5][playerid], "brp_quest:quest_button_2_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[5][playerid]);	
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[6][playerid], "brp_quest:quest_button_3_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[6][playerid]);	
				PlayerTextDrawSetString(playerid, quest_panel_general_p[7][playerid], "brp_quest:quest_button_4_no_select");
				PlayerTextDrawShow(playerid, quest_panel_general_p[7][playerid]);	

			 	format(fmt_str,sizeof(fmt_str),"%s", get_prize_quest(1));
				PlayerTextDrawSetString(playerid, quest_panel_general_p[11][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_panel_general_p[11][playerid]);	

				check_quest_prize_start(playerid, 0);

				if(pData[playerid][pQuestStandart][0] == 0)
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_no_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);	
				}	
				else
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);						
				}

			}
			else if(GetPVarIntNew(playerid, "select_quest_number_panel") == QUEST_PAGE_SELECT_2)
			{
				PlayerTextDrawSetString(playerid, quest_panel_general_p[0][playerid], "brp_quest:quest_background_2");
				PlayerTextDrawShow(playerid, quest_panel_general_p[0][playerid]);

				PlayerTextDrawSetString(playerid,  quest_panel_general_p[4][playerid], "brp_quest:quest_button_1_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[4][playerid]);
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[5][playerid], "brp_quest:quest_button_2_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[5][playerid]);	
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[6][playerid], "brp_quest:quest_button_3_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[6][playerid]);	
				PlayerTextDrawSetString(playerid, quest_panel_general_p[7][playerid], "brp_quest:quest_button_4_no_select");
				PlayerTextDrawShow(playerid, quest_panel_general_p[7][playerid]);	

			 	format(fmt_str,sizeof(fmt_str),"%s", get_prize_quest(2));
				PlayerTextDrawSetString(playerid, quest_panel_general_p[11][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_panel_general_p[11][playerid]);	

				check_quest_prize_start(playerid, 1);

				if(pData[playerid][pQuestStandart][1] == 0)
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_no_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);	
				}	
				else
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);						
				}

			}
			else if(GetPVarIntNew(playerid, "select_quest_number_panel") == QUEST_PAGE_SELECT_3)
			{
				PlayerTextDrawSetString(playerid, quest_panel_general_p[0][playerid], "brp_quest:quest_background_3");
				PlayerTextDrawShow(playerid, quest_panel_general_p[0][playerid]);

				PlayerTextDrawSetString(playerid,  quest_panel_general_p[4][playerid], "brp_quest:quest_button_1_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[4][playerid]);
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[5][playerid], "brp_quest:quest_button_2_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[5][playerid]);	
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[6][playerid], "brp_quest:quest_button_3_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[6][playerid]);	
				PlayerTextDrawSetString(playerid, quest_panel_general_p[7][playerid], "brp_quest:quest_button_4_no_select");
				PlayerTextDrawShow(playerid, quest_panel_general_p[7][playerid]);			

			 	format(fmt_str,sizeof(fmt_str),"%s", get_prize_quest(3));
				PlayerTextDrawSetString(playerid, quest_panel_general_p[11][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_panel_general_p[11][playerid]);	

				check_quest_prize_start(playerid, 2);

				if(pData[playerid][pQuestStandart][2] == 0)
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_no_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);	
				}	
				else
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);						
				}

			}
			else if(GetPVarIntNew(playerid, "select_quest_number_panel") == QUEST_PAGE_SELECT_4)
			{
				PlayerTextDrawSetString(playerid, quest_panel_general_p[0][playerid], "brp_quest:quest_background_4");
				PlayerTextDrawShow(playerid, quest_panel_general_p[0][playerid]);

				PlayerTextDrawSetString(playerid,  quest_panel_general_p[4][playerid], "brp_quest:quest_button_1_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[4][playerid]);
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[5][playerid], "brp_quest:quest_button_2_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[5][playerid]);	
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[6][playerid], "brp_quest:quest_button_3_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[6][playerid]);	
				PlayerTextDrawSetString(playerid, quest_panel_general_p[7][playerid], "brp_quest:quest_button_4_select");
				PlayerTextDrawShow(playerid, quest_panel_general_p[7][playerid]);	

			 	format(fmt_str,sizeof(fmt_str),"%s", get_prize_quest(4));
				PlayerTextDrawSetString(playerid, quest_panel_general_p[11][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_panel_general_p[11][playerid]);	

				check_quest_prize_start(playerid, 3);

				if(pData[playerid][pQuestStandart][3] == 0)
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_no_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);	
				}	
				else
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);						
				}

			}
		}
		case QUEST_PAGE_2:
		{
			if(!GetPVarIntNew(playerid, "select_quest_number_panel"))
			{
				PlayerTextDrawSetString(playerid, quest_panel_general_p[0][playerid], "brp_quest:quest_background_clear");
				PlayerTextDrawShow(playerid, quest_panel_general_p[0][playerid]);

				PlayerTextDrawSetString(playerid,  quest_panel_general_p[4][playerid], "brp_quest:quest_button_5_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[4][playerid]);
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[5][playerid], "brp_quest:quest_button_6_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[5][playerid]);	
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[6][playerid], "brp_quest:quest_button_7_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[6][playerid]);	
				PlayerTextDrawSetString(playerid, quest_panel_general_p[7][playerid], "brp_quest:quest_button_8_no_select");
				PlayerTextDrawShow(playerid, quest_panel_general_p[7][playerid]);	
			
			}
			else if(GetPVarIntNew(playerid, "select_quest_number_panel") == QUEST_PAGE_SELECT_1)
			{
				PlayerTextDrawSetString(playerid, quest_panel_general_p[0][playerid], "brp_quest:quest_background_5");
				PlayerTextDrawShow(playerid, quest_panel_general_p[0][playerid]);

				PlayerTextDrawSetString(playerid,  quest_panel_general_p[4][playerid], "brp_quest:quest_button_5_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[4][playerid]);
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[5][playerid], "brp_quest:quest_button_6_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[5][playerid]);	
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[6][playerid], "brp_quest:quest_button_7_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[6][playerid]);	
				PlayerTextDrawSetString(playerid, quest_panel_general_p[7][playerid], "brp_quest:quest_button_8_no_select");
				PlayerTextDrawShow(playerid, quest_panel_general_p[7][playerid]);	

			 	format(fmt_str,sizeof(fmt_str),"%s", get_prize_quest(5));
				PlayerTextDrawSetString(playerid, quest_panel_general_p[11][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_panel_general_p[11][playerid]);	

				check_quest_prize_start(playerid, 4);

				if(pData[playerid][pQuestStandart][4] == 0)
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_no_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);	
				}	
				else
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);						
				}

			}
			else if(GetPVarIntNew(playerid, "select_quest_number_panel") == QUEST_PAGE_SELECT_2)
			{
				PlayerTextDrawSetString(playerid, quest_panel_general_p[0][playerid], "brp_quest:quest_background_6");
				PlayerTextDrawShow(playerid, quest_panel_general_p[0][playerid]);

				PlayerTextDrawSetString(playerid,  quest_panel_general_p[4][playerid], "brp_quest:quest_button_5_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[4][playerid]);
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[5][playerid], "brp_quest:quest_button_6_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[5][playerid]);	
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[6][playerid], "brp_quest:quest_button_7_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[6][playerid]);	
				PlayerTextDrawSetString(playerid, quest_panel_general_p[7][playerid], "brp_quest:quest_button_8_no_select");
				PlayerTextDrawShow(playerid, quest_panel_general_p[7][playerid]);	

			 	format(fmt_str,sizeof(fmt_str),"%s", get_prize_quest(6));
				PlayerTextDrawSetString(playerid, quest_panel_general_p[11][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_panel_general_p[11][playerid]);	

				check_quest_prize_start(playerid, 5);

				if(pData[playerid][pQuestStandart][5] == 0)
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_no_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);	
				}	
				else
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);						
				}

			}
			else if(GetPVarIntNew(playerid, "select_quest_number_panel") == QUEST_PAGE_SELECT_3)
			{
				PlayerTextDrawSetString(playerid, quest_panel_general_p[0][playerid], "brp_quest:quest_background_7");
				PlayerTextDrawShow(playerid, quest_panel_general_p[0][playerid]);

				PlayerTextDrawSetString(playerid,  quest_panel_general_p[4][playerid], "brp_quest:quest_button_5_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[4][playerid]);
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[5][playerid], "brp_quest:quest_button_6_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[5][playerid]);	
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[6][playerid], "brp_quest:quest_button_7_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[6][playerid]);	
				PlayerTextDrawSetString(playerid, quest_panel_general_p[7][playerid], "brp_quest:quest_button_8_no_select");
				PlayerTextDrawShow(playerid, quest_panel_general_p[7][playerid]);			

			 	format(fmt_str,sizeof(fmt_str),"%s", get_prize_quest(7));
				PlayerTextDrawSetString(playerid, quest_panel_general_p[11][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_panel_general_p[11][playerid]);	

				check_quest_prize_start(playerid, 6);

				if(pData[playerid][pQuestStandart][6] == 0)
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_no_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);	
				}	
				else
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);						
				}

			}
			else if(GetPVarIntNew(playerid, "select_quest_number_panel") == QUEST_PAGE_SELECT_4)
			{
				PlayerTextDrawSetString(playerid, quest_panel_general_p[0][playerid], "brp_quest:quest_background_8");
				PlayerTextDrawShow(playerid, quest_panel_general_p[0][playerid]);

				PlayerTextDrawSetString(playerid,  quest_panel_general_p[4][playerid], "brp_quest:quest_button_5_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[4][playerid]);
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[5][playerid], "brp_quest:quest_button_6_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[5][playerid]);	
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[6][playerid], "brp_quest:quest_button_7_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[6][playerid]);	
				PlayerTextDrawSetString(playerid, quest_panel_general_p[7][playerid], "brp_quest:quest_button_8_select");
				PlayerTextDrawShow(playerid, quest_panel_general_p[7][playerid]);	

			 	format(fmt_str,sizeof(fmt_str),"%s", get_prize_quest(8));
				PlayerTextDrawSetString(playerid, quest_panel_general_p[11][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_panel_general_p[11][playerid]);	

				check_quest_prize_start(playerid, 7);

				if(pData[playerid][pQuestStandart][7] == 0)
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_no_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);	
				}	
				else
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);						
				}

			}

		}
		case QUEST_PAGE_3:
		{

			if(!GetPVarIntNew(playerid, "select_quest_number_panel"))
			{
				PlayerTextDrawSetString(playerid, quest_panel_general_p[0][playerid], "brp_quest:quest_background_clear");
				PlayerTextDrawShow(playerid, quest_panel_general_p[0][playerid]);

				PlayerTextDrawSetString(playerid,  quest_panel_general_p[4][playerid], "brp_quest:quest_button_9_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[4][playerid]);
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[5][playerid], "brp_quest:quest_button_10_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[5][playerid]);	
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[6][playerid], "brp_quest:quest_button_11_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[6][playerid]);	
				PlayerTextDrawSetString(playerid, quest_panel_general_p[7][playerid], "brp_quest:quest_button_12_no_select");
				PlayerTextDrawShow(playerid, quest_panel_general_p[7][playerid]);					
			}
			else if(GetPVarIntNew(playerid, "select_quest_number_panel") == QUEST_PAGE_SELECT_1)
			{
				PlayerTextDrawSetString(playerid, quest_panel_general_p[0][playerid], "brp_quest:quest_background_9");
				PlayerTextDrawShow(playerid, quest_panel_general_p[0][playerid]);

				PlayerTextDrawSetString(playerid,  quest_panel_general_p[4][playerid], "brp_quest:quest_button_9_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[4][playerid]);
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[5][playerid], "brp_quest:quest_button_10_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[5][playerid]);	
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[6][playerid], "brp_quest:quest_button_11_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[6][playerid]);	
				PlayerTextDrawSetString(playerid, quest_panel_general_p[7][playerid], "brp_quest:quest_button_12_no_select");
				PlayerTextDrawShow(playerid, quest_panel_general_p[7][playerid]);	

			 	format(fmt_str,sizeof(fmt_str),"%s", get_prize_quest(9));
				PlayerTextDrawSetString(playerid, quest_panel_general_p[11][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_panel_general_p[11][playerid]);	

				check_quest_prize_start(playerid, 8);

				if(pData[playerid][pQuestStandart][8] == 0)
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_no_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);	
				}	
				else
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);						
				}

			}
			else if(GetPVarIntNew(playerid, "select_quest_number_panel") == QUEST_PAGE_SELECT_2)
			{
				PlayerTextDrawSetString(playerid, quest_panel_general_p[0][playerid], "brp_quest:quest_background_10");
				PlayerTextDrawShow(playerid, quest_panel_general_p[0][playerid]);

				PlayerTextDrawSetString(playerid,  quest_panel_general_p[4][playerid], "brp_quest:quest_button_9_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[4][playerid]);
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[5][playerid], "brp_quest:quest_button_10_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[5][playerid]);	
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[6][playerid], "brp_quest:quest_button_11_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[6][playerid]);	
				PlayerTextDrawSetString(playerid, quest_panel_general_p[7][playerid], "brp_quest:quest_button_12_no_select");
				PlayerTextDrawShow(playerid, quest_panel_general_p[7][playerid]);	

			 	format(fmt_str,sizeof(fmt_str),"%s", get_prize_quest(10));
				PlayerTextDrawSetString(playerid, quest_panel_general_p[11][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_panel_general_p[11][playerid]);	

				check_quest_prize_start(playerid, 9);

				if(pData[playerid][pQuestStandart][9] == 0)
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_no_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);	
				}	
				else
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);						
				}

			}
			else if(GetPVarIntNew(playerid, "select_quest_number_panel") == QUEST_PAGE_SELECT_3)
			{
				PlayerTextDrawSetString(playerid, quest_panel_general_p[0][playerid], "brp_quest:quest_background_11");
				PlayerTextDrawShow(playerid, quest_panel_general_p[0][playerid]);

				PlayerTextDrawSetString(playerid,  quest_panel_general_p[4][playerid], "brp_quest:quest_button_9_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[4][playerid]);
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[5][playerid], "brp_quest:quest_button_10_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[5][playerid]);	
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[6][playerid], "brp_quest:quest_button_11_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[6][playerid]);	
				PlayerTextDrawSetString(playerid, quest_panel_general_p[7][playerid], "brp_quest:quest_button_12_no_select");
				PlayerTextDrawShow(playerid, quest_panel_general_p[7][playerid]);			

			 	format(fmt_str,sizeof(fmt_str),"%s", get_prize_quest(11));
				PlayerTextDrawSetString(playerid, quest_panel_general_p[11][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_panel_general_p[11][playerid]);	

				check_quest_prize_start(playerid, 10);

				if(pData[playerid][pQuestStandart][10] == 0)
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_no_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);	
				}	
				else
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);						
				}

			}
			else if(GetPVarIntNew(playerid, "select_quest_number_panel") == QUEST_PAGE_SELECT_4)
			{
				PlayerTextDrawSetString(playerid, quest_panel_general_p[0][playerid], "brp_quest:quest_background_12");
				PlayerTextDrawShow(playerid, quest_panel_general_p[0][playerid]);

				PlayerTextDrawSetString(playerid,  quest_panel_general_p[4][playerid], "brp_quest:quest_button_9_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[4][playerid]);
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[5][playerid], "brp_quest:quest_button_10_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[5][playerid]);	
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[6][playerid], "brp_quest:quest_button_11_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[6][playerid]);	
				PlayerTextDrawSetString(playerid, quest_panel_general_p[7][playerid], "brp_quest:quest_button_12_select");
				PlayerTextDrawShow(playerid, quest_panel_general_p[7][playerid]);	

			 	format(fmt_str,sizeof(fmt_str),"%s", get_prize_quest(12));
				PlayerTextDrawSetString(playerid, quest_panel_general_p[11][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_panel_general_p[11][playerid]);

				check_quest_prize_start(playerid, 11);	


				if(pData[playerid][pQuestStandart][11] == 0)
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_no_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);	
				}	
				else
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);						
				}

			}


		}
		case QUEST_PAGE_4:
		{

			if(!GetPVarIntNew(playerid, "select_quest_number_panel"))
			{
				PlayerTextDrawSetString(playerid, quest_panel_general_p[0][playerid], "brp_quest:quest_background_clear");
				PlayerTextDrawShow(playerid, quest_panel_general_p[0][playerid]);

				PlayerTextDrawSetString(playerid,  quest_panel_general_p[4][playerid], "brp_quest:quest_button_13_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[4][playerid]);
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[5][playerid], "brp_quest:quest_button_14_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[5][playerid]);	
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[6][playerid], "brp_quest:quest_button_15_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[6][playerid]);	
				PlayerTextDrawSetString(playerid, quest_panel_general_p[7][playerid], "brp_quest:quest_button_16_no_select");
				PlayerTextDrawShow(playerid, quest_panel_general_p[7][playerid]);					
			}
			else if(GetPVarIntNew(playerid, "select_quest_number_panel") == QUEST_PAGE_SELECT_1)
			{
				PlayerTextDrawSetString(playerid, quest_panel_general_p[0][playerid], "brp_quest:quest_background_13");
				PlayerTextDrawShow(playerid, quest_panel_general_p[0][playerid]);

				PlayerTextDrawSetString(playerid,  quest_panel_general_p[4][playerid], "brp_quest:quest_button_13_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[4][playerid]);
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[5][playerid], "brp_quest:quest_button_14_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[5][playerid]);	
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[6][playerid], "brp_quest:quest_button_15_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[6][playerid]);	
				PlayerTextDrawSetString(playerid, quest_panel_general_p[7][playerid], "brp_quest:quest_button_16_no_select");
				PlayerTextDrawShow(playerid, quest_panel_general_p[7][playerid]);	

			 	format(fmt_str,sizeof(fmt_str),"%s", get_prize_quest(13));
				PlayerTextDrawSetString(playerid, quest_panel_general_p[11][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_panel_general_p[11][playerid]);	

				check_quest_prize_start(playerid, 12);


				if(pData[playerid][pQuestStandart][12] == 0)
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_no_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);	
				}	
				else
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);						
				}

			}
			else if(GetPVarIntNew(playerid, "select_quest_number_panel") == QUEST_PAGE_SELECT_2)
			{
				PlayerTextDrawSetString(playerid, quest_panel_general_p[0][playerid], "brp_quest:quest_background_14");
				PlayerTextDrawShow(playerid, quest_panel_general_p[0][playerid]);

				PlayerTextDrawSetString(playerid,  quest_panel_general_p[4][playerid], "brp_quest:quest_button_13_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[4][playerid]);
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[5][playerid], "brp_quest:quest_button_14_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[5][playerid]);	
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[6][playerid], "brp_quest:quest_button_15_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[6][playerid]);	
				PlayerTextDrawSetString(playerid, quest_panel_general_p[7][playerid], "brp_quest:quest_button_16_no_select");
				PlayerTextDrawShow(playerid, quest_panel_general_p[7][playerid]);	

			 	format(fmt_str,sizeof(fmt_str),"%s", get_prize_quest(14));
				PlayerTextDrawSetString(playerid, quest_panel_general_p[11][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_panel_general_p[11][playerid]);	

				check_quest_prize_start(playerid, 13);

				if(pData[playerid][pQuestStandart][13] == 0)
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_no_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);	
				}	
				else
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);						
				}

			}
			else if(GetPVarIntNew(playerid, "select_quest_number_panel") == QUEST_PAGE_SELECT_3)
			{
				PlayerTextDrawSetString(playerid, quest_panel_general_p[0][playerid], "brp_quest:quest_background_15");
				PlayerTextDrawShow(playerid, quest_panel_general_p[0][playerid]);

				PlayerTextDrawSetString(playerid,  quest_panel_general_p[4][playerid], "brp_quest:quest_button_13_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[4][playerid]);
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[5][playerid], "brp_quest:quest_button_14_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[5][playerid]);	
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[6][playerid], "brp_quest:quest_button_15_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[6][playerid]);	
				PlayerTextDrawSetString(playerid, quest_panel_general_p[7][playerid], "brp_quest:quest_button_16_no_select");
				PlayerTextDrawShow(playerid, quest_panel_general_p[7][playerid]);			

			 	format(fmt_str,sizeof(fmt_str),"%s", get_prize_quest(15));
				PlayerTextDrawSetString(playerid, quest_panel_general_p[11][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_panel_general_p[11][playerid]);	


				if(pData[playerid][pQuestStandart][14] == 0)
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_no_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);	
				}	
				else
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);						
				}

			}
			else if(GetPVarIntNew(playerid, "select_quest_number_panel") == QUEST_PAGE_SELECT_4)
			{
				PlayerTextDrawSetString(playerid, quest_panel_general_p[0][playerid], "brp_quest:quest_background_16");
				PlayerTextDrawShow(playerid, quest_panel_general_p[0][playerid]);

				PlayerTextDrawSetString(playerid,  quest_panel_general_p[4][playerid], "brp_quest:quest_button_13_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[4][playerid]);
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[5][playerid], "brp_quest:quest_button_14_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[5][playerid]);	
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[6][playerid], "brp_quest:quest_button_15_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[6][playerid]);	
				PlayerTextDrawSetString(playerid, quest_panel_general_p[7][playerid], "brp_quest:quest_button_16_select");
				PlayerTextDrawShow(playerid, quest_panel_general_p[7][playerid]);	

			 	format(fmt_str,sizeof(fmt_str),"%s", get_prize_quest(16));
				PlayerTextDrawSetString(playerid, quest_panel_general_p[11][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_panel_general_p[11][playerid]);	


				if(pData[playerid][pQuestStandart][15] == 0)
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_no_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);	
				}	
				else
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);						
				}

			}

		}
		case QUEST_PAGE_5:
		{



			if(!GetPVarIntNew(playerid, "select_quest_number_panel"))
			{
				PlayerTextDrawSetString(playerid, quest_panel_general_p[0][playerid], "brp_quest:quest_background_clear");
				PlayerTextDrawShow(playerid, quest_panel_general_p[0][playerid]);

				PlayerTextDrawSetString(playerid,  quest_panel_general_p[4][playerid], "brp_quest:quest_button_17_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[4][playerid]);
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[5][playerid], "brp_quest:quest_button_18_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[5][playerid]);	
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[6][playerid], "brp_quest:quest_button_19_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[6][playerid]);	
				PlayerTextDrawSetString(playerid, quest_panel_general_p[7][playerid], "brp_quest:quest_button_20_no_select");
				PlayerTextDrawShow(playerid, quest_panel_general_p[7][playerid]);					
			}
			else if(GetPVarIntNew(playerid, "select_quest_number_panel") == QUEST_PAGE_SELECT_1)
			{
				PlayerTextDrawSetString(playerid, quest_panel_general_p[0][playerid], "brp_quest:quest_background_17");
				PlayerTextDrawShow(playerid, quest_panel_general_p[0][playerid]);

				PlayerTextDrawSetString(playerid,  quest_panel_general_p[4][playerid], "brp_quest:quest_button_17_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[4][playerid]);
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[5][playerid], "brp_quest:quest_button_18_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[5][playerid]);	
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[6][playerid], "brp_quest:quest_button_19_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[6][playerid]);	
				PlayerTextDrawSetString(playerid, quest_panel_general_p[7][playerid], "brp_quest:quest_button_20_no_select");
				PlayerTextDrawShow(playerid, quest_panel_general_p[7][playerid]);	

			 	format(fmt_str,sizeof(fmt_str),"%s", get_prize_quest(17));
				PlayerTextDrawSetString(playerid, quest_panel_general_p[11][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_panel_general_p[11][playerid]);	


				if(pData[playerid][pQuestStandart][16] == 0)
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_no_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);	
				}	
				else
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);						
				}

			}
			else if(GetPVarIntNew(playerid, "select_quest_number_panel") == QUEST_PAGE_SELECT_2)
			{
				PlayerTextDrawSetString(playerid, quest_panel_general_p[0][playerid], "brp_quest:quest_background_18");
				PlayerTextDrawShow(playerid, quest_panel_general_p[0][playerid]);

				PlayerTextDrawSetString(playerid,  quest_panel_general_p[4][playerid], "brp_quest:quest_button_17_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[4][playerid]);
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[5][playerid], "brp_quest:quest_button_18_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[5][playerid]);	
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[6][playerid], "brp_quest:quest_button_19_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[6][playerid]);	
				PlayerTextDrawSetString(playerid, quest_panel_general_p[7][playerid], "brp_quest:quest_button_20_no_select");
				PlayerTextDrawShow(playerid, quest_panel_general_p[7][playerid]);	

			 	format(fmt_str,sizeof(fmt_str),"%s", get_prize_quest(18));
				PlayerTextDrawSetString(playerid, quest_panel_general_p[11][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_panel_general_p[11][playerid]);	



				if(pData[playerid][pQuestStandart][17] == 0)
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_no_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);	
				}	
				else
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);						
				}

			}
			else if(GetPVarIntNew(playerid, "select_quest_number_panel") == QUEST_PAGE_SELECT_3)
			{
				PlayerTextDrawSetString(playerid, quest_panel_general_p[0][playerid], "brp_quest:quest_background_19");
				PlayerTextDrawShow(playerid, quest_panel_general_p[0][playerid]);

				PlayerTextDrawSetString(playerid,  quest_panel_general_p[4][playerid], "brp_quest:quest_button_17_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[4][playerid]);
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[5][playerid], "brp_quest:quest_button_18_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[5][playerid]);	
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[6][playerid], "brp_quest:quest_button_19_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[6][playerid]);	
				PlayerTextDrawSetString(playerid, quest_panel_general_p[7][playerid], "brp_quest:quest_button_20_no_select");
				PlayerTextDrawShow(playerid, quest_panel_general_p[7][playerid]);			

			 	format(fmt_str,sizeof(fmt_str),"%s", get_prize_quest(19));
				PlayerTextDrawSetString(playerid, quest_panel_general_p[11][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_panel_general_p[11][playerid]);	


				if(pData[playerid][pQuestStandart][18] == 0)
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_no_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);	
				}	
				else
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);						
				}

			}
			else if(GetPVarIntNew(playerid, "select_quest_number_panel") == QUEST_PAGE_SELECT_4)
			{
				PlayerTextDrawSetString(playerid, quest_panel_general_p[0][playerid], "brp_quest:quest_background_20");
				PlayerTextDrawShow(playerid, quest_panel_general_p[0][playerid]);

				PlayerTextDrawSetString(playerid,  quest_panel_general_p[4][playerid], "brp_quest:quest_button_17_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[4][playerid]);
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[5][playerid], "brp_quest:quest_button_18_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[5][playerid]);	
				PlayerTextDrawSetString(playerid,  quest_panel_general_p[6][playerid], "brp_quest:quest_button_19_no_select");
				PlayerTextDrawShow(playerid,  quest_panel_general_p[6][playerid]);	
				PlayerTextDrawSetString(playerid, quest_panel_general_p[7][playerid], "brp_quest:quest_button_20_select");
				PlayerTextDrawShow(playerid, quest_panel_general_p[7][playerid]);	

			 	format(fmt_str,sizeof(fmt_str),"%s", get_prize_quest(20));
				PlayerTextDrawSetString(playerid, quest_panel_general_p[11][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_panel_general_p[11][playerid]);	


				if(pData[playerid][pQuestStandart][19] == 0)
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_no_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);	
				}	
				else
				{
					PlayerTextDrawSetString(playerid, quest_panel_general_p[10][playerid], "brp_quest:quest_button_final");
					PlayerTextDrawShow(playerid, quest_panel_general_p[10][playerid]);						
				}

			}

		}
	}


	return true;
}



stock check_status_quest_start(playerid, quest_id)
{

	if(pData[playerid][pQuestStandart][quest_id] == 0)
	{
		check_quest_prize_start(playerid, quest_id);
	}
	return true;
}

stock check_quest_prize_start(playerid, quest_id)
{

	switch(quest_id)
	{
		case 0:
		{
			if(pData[playerid][pQuestStandart][0] == 0)
			{
				pData[playerid][pQuestStandart][0] = 1;
				SendSucc(playerid, "Поздравляем с выполнением квестового задания «Первые шаги»");
				SendInf(playerid, "Вы получили за выполнение квестового задания 500 рублей!");

				give_money(playerid, money_bonus + 500, "Выполнение квестового задания «Первые шаги»");
				give_donate(playerid, donate_bonus, "donate_bonus");
				UpdatePlayerData(playerid, "licDrive", 1);
				pData[playerid][pLevel] = reg_lvl;

				save_quest(playerid);		
			}
		}
		case 1:
		{
			if(pData[playerid][pQuestStandart][1] == 0)
			{
				pData[playerid][pQuestStandart][1] = 1;
				SendSucc(playerid, "Поздравляем с выполнением квестового задания «Новое начало»");
				SendInf(playerid, "Вы получили за выполнение квестового задания 750 рублей!");

				give_money(playerid, 750, "Выполнение квестового задания «Новое начало»");	

				save_quest(playerid);
			}
		}
		case 2:
		{
			if(pData[playerid][pQuestStandart][2] == 0) // Готово
			{
				if(get_job_level(playerid, SKILL_MINER) >= 2 && pData[playerid][job_skill][SKILL_MINER] >= 50)
				{
					pData[playerid][pQuestStandart][2] = 1;
					SendSucc(playerid, "Поздравляем с выполнением квестового задания «Несколько ударов киркой»");
					SendInf(playerid, "Вы получили за выполнение квестового задания 1 очко опыта и 7500 рублей!");

					give_money(playerid, 7500, "Выполнение квестового задания «Несколько ударов киркой»");	
					GivePlayerExp(playerid, 1);

					save_quest(playerid);
				}
			}
		}
		case 3:
		{
			if(pData[playerid][pQuestStandart][3] == 0) // Готово
			{
				if(get_job_level(playerid, SKILL_FACTORY) >= 2 && pData[playerid][job_skill][SKILL_FACTORY] >= 50)
				{
					pData[playerid][pQuestStandart][3] = 1;
					SendSucc(playerid, "Поздравляем с выполнением квестового задания «Стамеска и я - друзья навсегда»");
					SendInf(playerid, "Вы получили за выполнение квестового задания 1 очко опыта и 5000 рублей!");

					give_money(playerid, 5000, "Выполнение квестового задания «Стамеска и я - друзья навсегда»");	
					GivePlayerExp(playerid, 1);

					save_quest(playerid);
				}
			}
		}
		case 4:
		{
			if(pData[playerid][pQuestStandart][4] == 0) // Готово
			{
				if(get_job_level(playerid, SKILL_WOODCUTTER) >= 2 && pData[playerid][job_skill][SKILL_WOODCUTTER] >= 50)
				{
					pData[playerid][pQuestStandart][4] = 1;
					SendSucc(playerid, "Поздравляем с выполнением квестового задания «Пила лесоруба»");
					SendInf(playerid, "Вы получили за выполнение квестового задания 1 очко опыта и 5000 рублей!");

					give_money(playerid, 5000, "Выполнение квестового задания «Пила лесоруба»");	
					GivePlayerExp(playerid, 1);

					save_quest(playerid);

				}
			}
		}
		case 5:
		{
			if(pData[playerid][pQuestStandart][5] == 0) // Готово
			{
				if(get_job_level(playerid, SKILL_FACTORY) >= 3 && pData[playerid][job_skill][SKILL_FACTORY] >= 100 && get_job_level(playerid, SKILL_MINER) >= 3 && pData[playerid][job_skill][SKILL_MINER] >= 100 && get_job_level(playerid, SKILL_WOODCUTTER) >= 3 
				&& pData[playerid][job_skill][SKILL_WOODCUTTER] >= 100)
				{
					pData[playerid][pQuestStandart][5] = 1;
					SendSucc(playerid, "Поздравляем с выполнением квестового задания «Мастер на все руки»");
					SendInf(playerid, "Вы получили за выполнение квестового задания 2 очка опыта и 10000 рублей!");

					give_money(playerid, 10000, "Выполнение квестового задания «Мастер на все руки»");	
					GivePlayerExp(playerid, 2);

					save_quest(playerid);
				}
			}
		}
		case 6:
		{
			if(pData[playerid][pQuestStandart][6] == 0) // Готово
			{
				if(get_job_level(playerid, SKILL_FACTORY) >= 3 && pData[playerid][job_skill][SKILL_FACTORY] >= 150 && get_job_level(playerid, SKILL_MINER) >= 3 && pData[playerid][job_skill][SKILL_MINER] >= 150 && get_job_level(playerid, SKILL_WOODCUTTER) >= 3 
				&& pData[playerid][job_skill][SKILL_WOODCUTTER] >= 150)
				{
					pData[playerid][pQuestStandart][6] = 1;
					SendSucc(playerid, "Поздравляем с выполнением квестового задания «Работяга»");
					SendInf(playerid, "Вы получили за выполнение квестового задания 2 очка опыта и 10000 рублей!");

					give_money(playerid, 10000, "Выполнение квестового задания «Работяга»");	
					GivePlayerExp(playerid, 2);

					save_quest(playerid);
				}
			}
		}
		case 7:
		{
			if(pData[playerid][pQuestStandart][7] == 0) // Готово
			{
				if(pData[playerid][pLicenses][LIC_DRIVING] == 1)
				{
					pData[playerid][pQuestStandart][7] = 1;
					SendSucc(playerid, "Поздравляем с выполнением квестового задания «Водительское удостоверение»");
					SendInf(playerid, "Вы получили за выполнение квестового задания 750 рублей!");

					give_money(playerid, 750, "Выполнение квестового задания «Водительское удостоверение»");

					save_quest(playerid);	
				}
			}
		}
		case 8:
		{
			if(pData[playerid][pQuestStandart][8] == 0) // Готово
			{
				if(pData[playerid][pLicenses][LIC_FLY] == 1)
				{
					pData[playerid][pQuestStandart][8] = 1;
					SendSucc(playerid, "Поздравляем с выполнением квестового задания «Лицензия на пилотирование»");
					SendInf(playerid, "Вы получили за выполнение квестового задания 750 рублей!");

					give_money(playerid, 750, "Выполнение квестового задания «Лицензия на пилотирование»");	

					save_quest(playerid);
				}
			}
		}
		case 9:
		{
			if(pData[playerid][pQuestStandart][9] == 0) // Готово
			{
				if(pData[playerid][pLicenses][LIC_BOAT] == 1)
				{
					pData[playerid][pQuestStandart][9] = 1;
					SendSucc(playerid, "Поздравляем с выполнением квестового задания «Права на моторную лодку»");
					SendInf(playerid, "Вы получили за выполнение квестового задания 750 рублей!");

					give_money(playerid, 750, "Выполнение квестового задания «Права на моторную лодку»");	

					save_quest(playerid);
				}
			}
		}
		case 10:
		{
			if(pData[playerid][pQuestStandart][10] == 0) // Готово
			{

				if(pData[playerid][pLicenses][LIC_DRIVING] != 0 && pData[playerid][pLicenses][LIC_FLY] != 0 && pData[playerid][pLicenses][LIC_BOAT] != 0)
				{
					pData[playerid][pQuestStandart][10] = 1;
					SendSucc(playerid, "Поздравляем с выполнением квестового задания «Драйвер»");
					SendInf(playerid, "Вы получили за выполнение квестового задания 1 очко опыта и 2000 рублей!");

					give_money(playerid, 2000, "Выполнение квестового задания «Драйвер»");	
					GivePlayerExp(playerid, 1);

					save_quest(playerid);
				}
			}
		}
		case 11:
		{
			if(pData[playerid][pQuestStandart][11] == 0) // Готово
			{
				if(pData[playerid][pPhone] != 0)
				{
					pData[playerid][pQuestStandart][11] = 1;
					SendSucc(playerid, "Поздравляем с выполнением квестового задания «Смартфон»");
					SendInf(playerid, "Вы получили за выполнение квестового задания 250 рублей!");

					give_money(playerid, 250, "Выполнение квестового задания «Смартфон»");	

					save_quest(playerid);
				}
			}
		}
		case 12:
		{
			if(pData[playerid][pQuestStandart][12] == 0) // Готово
			{
				if(pData[playerid][pWatch] == 1)
				{
					pData[playerid][pQuestStandart][12] = 1;
					SendSucc(playerid, "Поздравляем с выполнением квестового задания «Часы на запястье»");
					SendInf(playerid, "Вы получили за выполнение квестового задания 250 рублей!");

					give_money(playerid, 250, "Выполнение квестового задания «Часы на запястье»");	

					save_quest(playerid);
				}
			}
		}
		case 13:
		{
			if(pData[playerid][pQuestStandart][13] == 0) // Готово
			{
				if(pData[playerid][pBook] == 1)
				{
					pData[playerid][pQuestStandart][13] = 1;
					SendSucc(playerid, "Поздравляем с выполнением квестового задания «Телефонная книга»");
					SendInf(playerid, "Вы получили за выполнение квестового задания 250 рублей!");

					give_money(playerid, 250, "Выполнение квестового задания «Телефонная книга»");

					save_quest(playerid);	
				}
			}
		}
		case 14:
		{
			if(pData[playerid][pQuestStandart][14] == 0) // Готово
			{
				pData[playerid][pQuestStandart][14] = 1;
				SendSucc(playerid, "Поздравляем с выполнением квестового задания «Новый лук»");
				SendInf(playerid, "Вы получили за выполнение квестового задания 1 очко опыта и 2500 рублей!");

				give_money(playerid, 2500, "Выполнение квестового задания «Новый лук»");	
				GivePlayerExp(playerid, 1);

				save_quest(playerid);
			}
		}
		case 15:
		{
			if(pData[playerid][pQuestStandart][15] == 0) // Готово
			{
				pData[playerid][pQuestStandart][15] = 1;
				SendSucc(playerid, "Поздравляем с выполнением квестового задания «Ещё немного уникальности»");
				SendInf(playerid, "Вы получили за выполнение квестового задания 1 очко опыта и 2500 рублей!");

				give_money(playerid, 2500, "Выполнение квестового задания «Ещё немного уникальности»");	
				GivePlayerExp(playerid, 1);

				save_quest(playerid);
			}
		}
		case 16:
		{
			if(pData[playerid][pQuestStandart][16] == 0) // Готово
			{
				pData[playerid][pQuestStandart][16] = 1;
				SendSucc(playerid, "Поздравляем с выполнением квестового задания «Вкусный хавчик»");
				SendInf(playerid, "Вы получили за выполнение квестового задания 1 очко опыта и 500 рублей!");

				give_money(playerid, 500, "Выполнение квестового задания «Вкусный хавчик»");	
				GivePlayerExp(playerid, 1);

				save_quest(playerid);
			}
		}
		case 17:
		{
			if(pData[playerid][pQuestStandart][17] == 0)
			{
				pData[playerid][pQuestStandart][17] = 1;
				SendSucc(playerid, "Поздравляем с выполнением квестового задания «Водитель маршрутки»");
				SendInf(playerid, "Вы получили за выполнение квестового задания 1000 рублей!");

				save_quest(playerid);

				give_money(playerid, 1000, "Выполнение квестового задания «Водитель маршрутки»");	
			}
		}
		case 18:
		{
			if(pData[playerid][pQuestStandart][18] == 0) // Готово
			{
				if(pData[playerid][job_skill][SKILL_BUS_DRIVER] > 10)
				{
					pData[playerid][pQuestStandart][18] = 1;
					SendSucc(playerid, "Поздравляем с выполнением квестового задания «Дорогу осилит едущий»");
					SendInf(playerid, "Вы получили за выполнение квестового задания 1 очко опыта и 2500 рублей!");

					give_money(playerid, 2500, "Выполнение квестового задания «Дорогу осилит едущий»");	
					GivePlayerExp(playerid, 1);

					save_quest(playerid);
				}
			}
		}
		case 19:
		{
			if(pData[playerid][pQuestStandart][19] == 0) // Готово
			{
				if(pData[playerid][pQuestStandart][0] == 1 && pData[playerid][pQuestStandart][1] == 1 && pData[playerid][pQuestStandart][2] == 1 && pData[playerid][pQuestStandart][3] == 1 &&
				pData[playerid][pQuestStandart][4] == 1 && pData[playerid][pQuestStandart][5] == 1 && pData[playerid][pQuestStandart][6] == 1 && pData[playerid][pQuestStandart][7] == 1 &&
				pData[playerid][pQuestStandart][8] == 1 && pData[playerid][pQuestStandart][9] == 1 && pData[playerid][pQuestStandart][10] == 1 && pData[playerid][pQuestStandart][11] == 1 &&
				pData[playerid][pQuestStandart][12] == 1 && pData[playerid][pQuestStandart][13] == 1 && pData[playerid][pQuestStandart][14] == 1 && pData[playerid][pQuestStandart][15] == 1 &&
				pData[playerid][pQuestStandart][16] == 1 && pData[playerid][pQuestStandart][17] == 1 && pData[playerid][pQuestStandart][18] == 1)
				{  
					pData[playerid][pQuestStandart][19] = 1;
					SendSucc(playerid, "Поздравляем с выполнением квестового задания «Уважаемый гражданин»");
					SendInf(playerid, "Вы получили за выполнение квестового задания 3 очка опыта и 15000 рублей!");

					give_money(playerid, 15000, "Выполнение квестового задания «Уважаемый гражданин»");	
					GivePlayerExp(playerid, 3);

					save_quest(playerid);
				}
			}
		}
	}

	return true;
}

stock save_quest(playerid)
{

	new 
		quest_str[350*5];

	format(quest_str, sizeof quest_str, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
		pData[playerid][pQuestStandart][0],
		pData[playerid][pQuestStandart][1],
		pData[playerid][pQuestStandart][2],
		pData[playerid][pQuestStandart][3],
		pData[playerid][pQuestStandart][4],
		pData[playerid][pQuestStandart][5],
		pData[playerid][pQuestStandart][6],
		pData[playerid][pQuestStandart][7],
		pData[playerid][pQuestStandart][8],
		pData[playerid][pQuestStandart][9],
		pData[playerid][pQuestStandart][10],
		pData[playerid][pQuestStandart][11],
		pData[playerid][pQuestStandart][12],
		pData[playerid][pQuestStandart][13],
		pData[playerid][pQuestStandart][14],
		pData[playerid][pQuestStandart][15],
		pData[playerid][pQuestStandart][16],
		pData[playerid][pQuestStandart][17],
		pData[playerid][pQuestStandart][18],
		pData[playerid][pQuestStandart][19],
		pData[playerid][pQuestStandart][20]
		);

	format(String512,sizeof(String512),"UPDATE `accounts` SET `pQuestStandart`='%s' WHERE `nickname`='%s'", quest_str, pData[playerid][pNickname]);
	sql_queryEx(zConn, String512, QUERY_THREADED);


	return true;
}
