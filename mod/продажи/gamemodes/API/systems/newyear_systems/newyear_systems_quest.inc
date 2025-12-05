stock show_newyear_quest_previow(playerid)
{
	TextDrawShowForPlayer(playerid, quest_newyear_start[0]);
	TextDrawShowForPlayer(playerid, quest_newyear_start[1]);
	TextDrawShowForPlayer(playerid, quest_newyear_start[2]);
	TextDrawShowForPlayer(playerid, quest_newyear_start[3]);

	SelectTextDraw(playerid, COLOR_BLUE);

	TogglePlayerAllHudElements(playerid, HUD_ELEMENT_HIDE);

	return true;
}

stock close_prewiow_quest_newyear(playerid)
{
	TextDrawHideForPlayer(playerid, quest_newyear_start[0]);
	TextDrawHideForPlayer(playerid, quest_newyear_start[1]);
	TextDrawHideForPlayer(playerid, quest_newyear_start[2]);
	TextDrawHideForPlayer(playerid, quest_newyear_start[3]);

	CancelSelectTextDraw(playerid);

	TogglePlayerAllHudElements(playerid, HUD_ELEMENT_SHOW);	

	show_quest_panel(playerid);

	return true;
}


stock show_quest_newyear_panel(playerid)
{

	SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодние задания", !"\
	"cWH"Дед Мороз: Новый год подошёл к концу, а с ним и нужна в заданиях пропала!\n\n\
	Вы очень хорошо постарались и помогли мне сделать этот праздник лучше!\n\n\
	Увидимся в следующем году!", !"Начать", !"Нет");			


	//show_quest_newyear(playerid, TEXTDRAW_HIDE);
	//show_quest_newyear(playerid, TEXTDRAW_SHOW);	

	return true;
}

stock show_quest_newyear(playerid, type)
{

	switch(type)
	{
		case TEXTDRAW_SHOW:
		{
			new 
				fmt_str[90];

			close_prewiow_quest_newyear(playerid);

			show_quest_systems_general(playerid, TEXTDRAW_HIDE);

			TextDrawShowForPlayer(playerid, quest_newyear_td);	

			SetPVarIntNew(playerid, "select_quest_number_panel", QUEST_PAGE_SELECT_1);

			create_quest_newyear_p(playerid);

			show_quest_panel_newyear_page(playerid, 1);	

			page_quest_panel[playerid] = 1;
			
		 	format(fmt_str,sizeof(fmt_str),"%d/2", page_quest_panel[playerid]);
			PlayerTextDrawSetString(playerid, quest_newyear_p[10][playerid], fmt_str);
			PlayerTextDrawShow(playerid, quest_newyear_p[10][playerid]);	

			TogglePlayerHudElement(playerid, HUD_ELEMENT_TAGS, HUD_ELEMENT_HIDE);

			SelectTextDraw(playerid, COLOR_BLUE);
		}
		case TEXTDRAW_HIDE:
		{
			TextDrawHideForPlayer(playerid, quest_newyear_td);

			PlayerTextDrawHideEx(playerid, quest_newyear_p[0][playerid]);
			PlayerTextDrawHideEx(playerid, quest_newyear_p[1][playerid]);
			PlayerTextDrawHideEx(playerid, quest_newyear_p[2][playerid]);
			PlayerTextDrawHideEx(playerid, quest_newyear_p[3][playerid]);
			PlayerTextDrawHideEx(playerid, quest_newyear_p[4][playerid]);
			PlayerTextDrawHideEx(playerid, quest_newyear_p[5][playerid]);
			PlayerTextDrawHideEx(playerid, quest_newyear_p[6][playerid]);
			PlayerTextDrawHideEx(playerid, quest_newyear_p[7][playerid]);
			PlayerTextDrawHideEx(playerid, quest_newyear_p[8][playerid]);
			PlayerTextDrawHideEx(playerid, quest_newyear_p[9][playerid]);
			PlayerTextDrawHideEx(playerid, quest_newyear_p[10][playerid]);
			PlayerTextDrawHideEx(playerid, quest_newyear_p[11][playerid]);
			PlayerTextDrawHideEx(playerid, quest_newyear_p[12][playerid]);
			PlayerTextDrawHideEx(playerid, quest_newyear_p[13][playerid]);

			TogglePlayerHudElement(playerid, HUD_ELEMENT_TAGS, HUD_ELEMENT_SHOW);	

		}
		case TEXTDRAW_UPDATE:
		{

		}
	}
	return true;
}

stock close_quest_panel_newyear(playerid)
{
	show_quest_newyear(playerid, TEXTDRAW_HIDE);
	SetCameraBehindPlayer(playerid);
	CancelSelectTextDraw(playerid);
	return true;
}

stock get_prize_quest_newyear_newyear(h)
{
	new 
		name[40];

	switch(h)
	{
		case 1: name = "1_EXP_1_SNOW";
		case 2: name = "1_EXP_1_SNOW";
		case 3: name = "1_EXP_1_SNOW";
		case 4: name = "1_EXP_1_SNOW";
		case 5: name = "1_EXP_1_SNOW";
		case 6: name = "1_EXP_1_SNOW";
		case 7: name = "1_EXP_1_SNOW";
		case 8: name = "1_EXP_1_SNOW";
		case 9: name = "1_EXP_1_SNOW";
		case 10: name = "1_EXP_1_SNOW";
		default: name = "None";
	}
	return name;
}

stock next_page_quest_panel_newyear(playerid)
{	

	if(page_quest_panel[playerid] == 2)
		return true;

	PlayerTextDrawHideEx(playerid, quest_newyear_p[0][playerid]);
	PlayerTextDrawHideEx(playerid, quest_newyear_p[1][playerid]);
	PlayerTextDrawHideEx(playerid, quest_newyear_p[2][playerid]);
	PlayerTextDrawHideEx(playerid, quest_newyear_p[6][playerid]);
	PlayerTextDrawHideEx(playerid, quest_newyear_p[7][playerid]);
	PlayerTextDrawHideEx(playerid, quest_newyear_p[10][playerid]);
	PlayerTextDrawHideEx(playerid, quest_newyear_p[11][playerid]);
	PlayerTextDrawHideEx(playerid, quest_newyear_p[12][playerid]);
	PlayerTextDrawHideEx(playerid, quest_newyear_p[13][playerid]);




	page_quest_panel[playerid]++;

	show_quest_panel_newyear_page(playerid, page_quest_panel[playerid]);

	SetPVarIntNew(playerid, "select_quest_number_panel", QUEST_PAGE_SELECT_1);

	new 
		fmt_str[90];

 	format(fmt_str,sizeof(fmt_str),"%d/2", page_quest_panel[playerid]);
	PlayerTextDrawSetString(playerid, quest_newyear_p[10][playerid], fmt_str);
	PlayerTextDrawShow(playerid, quest_newyear_p[10][playerid]);	


 	format(fmt_str,sizeof(fmt_str),"%s", get_prize_quest_newyear_newyear(page_quest_panel[playerid]));
	PlayerTextDrawSetString(playerid, quest_newyear_p[12][playerid], fmt_str);
	PlayerTextDrawShow(playerid, quest_newyear_p[12][playerid]);	

	SelectTextDraw(playerid, COLOR_BLUE);
	return true;

}

stock pre_page_quest_panel_newyear(playerid)
{
	if(page_quest_panel[playerid] == 1)
		return true;

	PlayerTextDrawHideEx(playerid, quest_newyear_p[0][playerid]);
	PlayerTextDrawHideEx(playerid, quest_newyear_p[1][playerid]);
	PlayerTextDrawHideEx(playerid, quest_newyear_p[2][playerid]);
	PlayerTextDrawHideEx(playerid, quest_newyear_p[6][playerid]);
	PlayerTextDrawHideEx(playerid, quest_newyear_p[7][playerid]);
	PlayerTextDrawHideEx(playerid, quest_newyear_p[10][playerid]);
	PlayerTextDrawHideEx(playerid, quest_newyear_p[11][playerid]);
	PlayerTextDrawHideEx(playerid, quest_newyear_p[12][playerid]);
	PlayerTextDrawHideEx(playerid, quest_newyear_p[13][playerid]);


	page_quest_panel[playerid]--;

	show_quest_panel_newyear_page(playerid, page_quest_panel[playerid]);	

	SetPVarIntNew(playerid, "select_quest_number_panel", QUEST_PAGE_SELECT_1);

	new 
		fmt_str[90];

 	format(fmt_str,sizeof(fmt_str),"%d/2", page_quest_panel[playerid]);
	PlayerTextDrawSetString(playerid, quest_newyear_p[10][playerid], fmt_str);
	PlayerTextDrawShow(playerid, quest_newyear_p[10][playerid]);	

 	format(fmt_str,sizeof(fmt_str),"%s", get_prize_quest_newyear_newyear(page_quest_panel[playerid]));
	PlayerTextDrawSetString(playerid, quest_newyear_p[12][playerid], fmt_str);
	PlayerTextDrawShow(playerid, quest_newyear_p[12][playerid]);	

	SelectTextDraw(playerid, COLOR_BLUE);
	return true;
}


stock show_quest_panel_newyear_page(playerid, page)
{

	switch(page)
	{
		case QUEST_PAGE_1:
		{
			if(GetPVarIntNew(playerid, "select_quest_number_panel") == QUEST_PAGE_SELECT_1)
			{
				show_quest_newyear(playerid, TEXTDRAW_HIDE);

				new 
					fmt_str[90];

				TextDrawShowForPlayer(playerid, quest_newyear_td);

				create_quest_newyear_p(playerid);

				PlayerTextDrawSetString(playerid, quest_newyear_p[0][playerid], "brp_quest:quest_newyear_background_1");
				PlayerTextDrawShow(playerid, quest_newyear_p[0][playerid]);


				PlayerTextDrawSetString(playerid, quest_newyear_p[1][playerid], "brp_quest:quest_newyear_1_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[1][playerid]);
				PlayerTextDrawSetString(playerid, quest_newyear_p[2][playerid], "brp_quest:quest_newyear_2_no_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[2][playerid]);			
				PlayerTextDrawSetString(playerid, quest_newyear_p[6][playerid], "brp_quest:quest_newyear_3_no_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[6][playerid]);		
				PlayerTextDrawSetString(playerid, quest_newyear_p[7][playerid], "brp_quest:quest_newyear_6_no_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[7][playerid]);	

				PlayerTextDrawShow(playerid, quest_newyear_p[3][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[4][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[5][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[7][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[8][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[9][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[10][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[11][playerid]);


			 	format(fmt_str,sizeof(fmt_str),"%s", get_prize_quest_newyear_newyear(1));
				PlayerTextDrawSetString(playerid, quest_newyear_p[12][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_newyear_p[12][playerid]);	

				if(pData[playerid][pQuestNewYear][0] == 1)
				{
					PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_4");
					PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);		
				}
				else if(pData[playerid][pQuestNewYear][0] == 2)
				{
					PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_3");
					PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);		
				}
				else if(!pData[playerid][pQuestNewYear][0])
				{
					PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_5");
					PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);		
				}


			 	format(fmt_str,sizeof(fmt_str),"%d/2", page_quest_panel[playerid]);
				PlayerTextDrawSetString(playerid, quest_newyear_p[10][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_newyear_p[10][playerid]);	

				SetPVarIntNew(playerid, "quest_count_newyear_panel", 1);

				SelectTextDraw(playerid, COLOR_BLUE);
			}
			else if(GetPVarIntNew(playerid, "select_quest_number_panel") == QUEST_PAGE_SELECT_2)
			{
				show_quest_newyear(playerid, TEXTDRAW_HIDE);

				new 
					fmt_str[90];

				TextDrawShowForPlayer(playerid, quest_newyear_td);
				create_quest_newyear_p(playerid);

				PlayerTextDrawSetString(playerid, quest_newyear_p[0][playerid], "brp_quest:quest_newyear_background_2");
				PlayerTextDrawShow(playerid, quest_newyear_p[0][playerid]);


				PlayerTextDrawSetString(playerid, quest_newyear_p[1][playerid], "brp_quest:quest_newyear_1_no_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[1][playerid]);
				PlayerTextDrawSetString(playerid, quest_newyear_p[2][playerid], "brp_quest:quest_newyear_2_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[2][playerid]);			
				PlayerTextDrawSetString(playerid, quest_newyear_p[6][playerid], "brp_quest:quest_newyear_3_no_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[6][playerid]);		
				PlayerTextDrawSetString(playerid, quest_newyear_p[7][playerid], "brp_quest:quest_newyear_6_no_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[7][playerid]);	




				PlayerTextDrawShow(playerid, quest_newyear_p[3][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[4][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[5][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[7][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[8][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[9][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[10][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[11][playerid]);


			 	format(fmt_str,sizeof(fmt_str),"%s", get_prize_quest_newyear_newyear(2));
				PlayerTextDrawSetString(playerid, quest_newyear_p[12][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_newyear_p[12][playerid]);	

				if(pData[playerid][pQuestNewYear][1] == 1)
				{
					PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_4");
					PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);		
				}
				else if(pData[playerid][pQuestNewYear][1] == 2)
				{
					PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_3");
					PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);		
				}
				else if(!pData[playerid][pQuestNewYear][1])
				{
					PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_5");
					PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);		
				}

			 	format(fmt_str,sizeof(fmt_str),"%d/2", page_quest_panel[playerid]);
				PlayerTextDrawSetString(playerid, quest_newyear_p[10][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_newyear_p[10][playerid]);	

				SetPVarIntNew(playerid, "quest_count_newyear_panel", 2);

				SelectTextDraw(playerid, COLOR_BLUE);
			}
			else if(GetPVarIntNew(playerid, "select_quest_number_panel") == QUEST_PAGE_SELECT_3)
			{
				show_quest_newyear(playerid, TEXTDRAW_HIDE);

				new 
					fmt_str[90];

				TextDrawShowForPlayer(playerid, quest_newyear_td);

				create_quest_newyear_p(playerid);

				PlayerTextDrawSetString(playerid, quest_newyear_p[0][playerid], "brp_quest:quest_newyear_background_3");
				PlayerTextDrawShow(playerid, quest_newyear_p[0][playerid]);


				PlayerTextDrawSetString(playerid, quest_newyear_p[1][playerid], "brp_quest:quest_newyear_1_no_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[1][playerid]);
				PlayerTextDrawSetString(playerid, quest_newyear_p[2][playerid], "brp_quest:quest_newyear_2_no_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[2][playerid]);			
				PlayerTextDrawSetString(playerid, quest_newyear_p[6][playerid], "brp_quest:quest_newyear_3_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[6][playerid]);		
				PlayerTextDrawSetString(playerid, quest_newyear_p[7][playerid], "brp_quest:quest_newyear_6_no_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[7][playerid]);	




				PlayerTextDrawShow(playerid, quest_newyear_p[3][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[4][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[5][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[7][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[8][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[9][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[10][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[11][playerid]);

			 	format(fmt_str,sizeof(fmt_str),"%s", get_prize_quest_newyear_newyear(3));
				PlayerTextDrawSetString(playerid, quest_newyear_p[12][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_newyear_p[12][playerid]);	

				if(pData[playerid][pQuestNewYear][2] == 1)
				{
					PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_4");
					PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);		
				}
				else if(pData[playerid][pQuestNewYear][2] == 2)
				{
					PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_3");
					PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);		
				}
				else if(!pData[playerid][pQuestNewYear][2])
				{
					PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_5");
					PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);		
				}

			 	format(fmt_str,sizeof(fmt_str),"%d/2", page_quest_panel[playerid]);
				PlayerTextDrawSetString(playerid, quest_newyear_p[10][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_newyear_p[10][playerid]);	

				SetPVarIntNew(playerid, "quest_count_newyear_panel", 3);

				SelectTextDraw(playerid, COLOR_BLUE);
			}
			else if(GetPVarIntNew(playerid, "select_quest_number_panel") == QUEST_PAGE_SELECT_4)
			{
				show_quest_newyear(playerid, TEXTDRAW_HIDE);

				new 
					fmt_str[90];

				TextDrawShowForPlayer(playerid, quest_newyear_td);

				create_quest_newyear_p(playerid);

				PlayerTextDrawSetString(playerid, quest_newyear_p[0][playerid], "brp_quest:quest_newyear_background_4");
				PlayerTextDrawShow(playerid, quest_newyear_p[0][playerid]);


				PlayerTextDrawSetString(playerid, quest_newyear_p[1][playerid], "brp_quest:quest_newyear_1_no_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[1][playerid]);
				PlayerTextDrawSetString(playerid, quest_newyear_p[2][playerid], "brp_quest:quest_newyear_2_no_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[2][playerid]);			
				PlayerTextDrawSetString(playerid, quest_newyear_p[6][playerid], "brp_quest:quest_newyear_3_no_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[6][playerid]);		
				PlayerTextDrawSetString(playerid, quest_newyear_p[7][playerid], "brp_quest:quest_newyear_6_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[7][playerid]);	




				PlayerTextDrawShow(playerid, quest_newyear_p[3][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[4][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[5][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[7][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[8][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[9][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[10][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[11][playerid]);


			 	format(fmt_str,sizeof(fmt_str),"%s", get_prize_quest_newyear_newyear(4));
				PlayerTextDrawSetString(playerid, quest_newyear_p[12][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_newyear_p[12][playerid]);	

				if(pData[playerid][pQuestNewYear][3] == 1)
				{
					PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_4");
					PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);		
				}
				else if(pData[playerid][pQuestNewYear][3] == 2)
				{
					PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_3");
					PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);		
				}
				else if(!pData[playerid][pQuestNewYear][3])
				{
					PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_5");
					PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);		
				}

			 	format(fmt_str,sizeof(fmt_str),"%d/2", page_quest_panel[playerid]);
				PlayerTextDrawSetString(playerid, quest_newyear_p[10][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_newyear_p[10][playerid]);	

				SetPVarIntNew(playerid, "quest_count_newyear_panel", 4);

				SelectTextDraw(playerid, COLOR_BLUE);
			}
		}
		case QUEST_PAGE_2:
		{		
			if(GetPVarIntNew(playerid, "select_quest_number_panel") == QUEST_PAGE_SELECT_1)
			{
				show_quest_newyear(playerid, TEXTDRAW_HIDE);

				new 
					fmt_str[90];

				TextDrawShowForPlayer(playerid, quest_newyear_td);

				create_quest_newyear_p(playerid);

				PlayerTextDrawSetString(playerid, quest_newyear_p[0][playerid], "brp_quest:quest_newyear_background_5");
				PlayerTextDrawShow(playerid, quest_newyear_p[0][playerid]);


				PlayerTextDrawSetString(playerid, quest_newyear_p[1][playerid], "brp_quest:quest_newyear_4_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[1][playerid]);
				PlayerTextDrawSetString(playerid, quest_newyear_p[2][playerid], "brp_quest:quest_newyear_5_no_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[2][playerid]);			
				PlayerTextDrawSetString(playerid, quest_newyear_p[6][playerid], "brp_quest:quest_newyear_8_no_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[6][playerid]);		
				PlayerTextDrawSetString(playerid, quest_newyear_p[7][playerid], "brp_quest:quest_newyear_9_no_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[7][playerid]);	



				PlayerTextDrawShow(playerid, quest_newyear_p[3][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[4][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[5][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[7][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[8][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[9][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[10][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[11][playerid]);


			 	format(fmt_str,sizeof(fmt_str),"%s", get_prize_quest_newyear_newyear(5));
				PlayerTextDrawSetString(playerid, quest_newyear_p[12][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_newyear_p[12][playerid]);	

				if(pData[playerid][pQuestNewYear][4] == 1)
				{
					PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_4");
					PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);		
				}
				else if(pData[playerid][pQuestNewYear][4] == 2)
				{
					PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_3");
					PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);		
				}
				else if(!pData[playerid][pQuestNewYear][4])
				{
					PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_5");
					PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);		
				}

			 	format(fmt_str,sizeof(fmt_str),"%d/2", page_quest_panel[playerid]);
				PlayerTextDrawSetString(playerid, quest_newyear_p[10][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_newyear_p[10][playerid]);	

				SetPVarIntNew(playerid, "quest_count_newyear_panel", 5);

				SelectTextDraw(playerid, COLOR_BLUE);
			}
			else if(GetPVarIntNew(playerid, "select_quest_number_panel") == QUEST_PAGE_SELECT_2)
			{
				show_quest_newyear(playerid, TEXTDRAW_HIDE);

				new 
					fmt_str[90];

				TextDrawShowForPlayer(playerid, quest_newyear_td);

				create_quest_newyear_p(playerid);

				PlayerTextDrawSetString(playerid, quest_newyear_p[0][playerid], "brp_quest:quest_newyear_background_6");
				PlayerTextDrawShow(playerid, quest_newyear_p[0][playerid]);


				PlayerTextDrawSetString(playerid, quest_newyear_p[1][playerid], "brp_quest:quest_newyear_4_no_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[1][playerid]);
				PlayerTextDrawSetString(playerid, quest_newyear_p[2][playerid], "brp_quest:quest_newyear_5_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[2][playerid]);			
				PlayerTextDrawSetString(playerid, quest_newyear_p[6][playerid], "brp_quest:quest_newyear_8_no_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[6][playerid]);		
				PlayerTextDrawSetString(playerid, quest_newyear_p[7][playerid], "brp_quest:quest_newyear_9_no_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[7][playerid]);	


				PlayerTextDrawShow(playerid, quest_newyear_p[3][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[4][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[5][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[7][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[8][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[9][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[10][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[11][playerid]);


			 	format(fmt_str,sizeof(fmt_str),"%s", get_prize_quest_newyear_newyear(6));
				PlayerTextDrawSetString(playerid, quest_newyear_p[12][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_newyear_p[12][playerid]);	

				if(pData[playerid][pQuestNewYear][5] == 1)
				{
					PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_4");
					PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);		
				}
				else if(pData[playerid][pQuestNewYear][5] == 2)
				{
					PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_3");
					PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);		
				}
				else if(!pData[playerid][pQuestNewYear][5])
				{
					PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_5");
					PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);		
				}

			 	format(fmt_str,sizeof(fmt_str),"%d/2", page_quest_panel[playerid]);
				PlayerTextDrawSetString(playerid, quest_newyear_p[10][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_newyear_p[10][playerid]);	

				SetPVarIntNew(playerid, "quest_count_newyear_panel", 6);

				SelectTextDraw(playerid, COLOR_BLUE);
			}
			else if(GetPVarIntNew(playerid, "select_quest_number_panel") == QUEST_PAGE_SELECT_3)
			{
				show_quest_newyear(playerid, TEXTDRAW_HIDE);

				new 
					fmt_str[90];

				TextDrawShowForPlayer(playerid, quest_newyear_td);

				create_quest_newyear_p(playerid);

				PlayerTextDrawSetString(playerid, quest_newyear_p[0][playerid], "brp_quest:quest_newyear_background_7");
				PlayerTextDrawShow(playerid, quest_newyear_p[0][playerid]);


				PlayerTextDrawSetString(playerid, quest_newyear_p[1][playerid], "brp_quest:quest_newyear_4_no_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[1][playerid]);
				PlayerTextDrawSetString(playerid, quest_newyear_p[2][playerid], "brp_quest:quest_newyear_5_no_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[2][playerid]);			
				PlayerTextDrawSetString(playerid, quest_newyear_p[6][playerid], "brp_quest:quest_newyear_8_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[6][playerid]);		
				PlayerTextDrawSetString(playerid, quest_newyear_p[7][playerid], "brp_quest:quest_newyear_9_no_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[7][playerid]);	

				PlayerTextDrawShow(playerid, quest_newyear_p[3][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[4][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[5][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[7][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[8][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[9][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[10][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[11][playerid]);


			 	format(fmt_str,sizeof(fmt_str),"%s", get_prize_quest_newyear_newyear(7));
				PlayerTextDrawSetString(playerid, quest_newyear_p[12][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_newyear_p[12][playerid]);	

				if(pData[playerid][pQuestNewYear][6] == 1)
				{
					PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_4");
					PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);		
				}
				else if(pData[playerid][pQuestNewYear][6] == 2)
				{
					PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_3");
					PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);		
				}
				else if(!pData[playerid][pQuestNewYear][6])
				{
					PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_5");
					PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);		
				}

			 	format(fmt_str,sizeof(fmt_str),"%d/2", page_quest_panel[playerid]);
				PlayerTextDrawSetString(playerid, quest_newyear_p[10][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_newyear_p[10][playerid]);	

				SetPVarIntNew(playerid, "quest_count_newyear_panel", 7);

				SelectTextDraw(playerid, COLOR_BLUE);
			}
			else if(GetPVarIntNew(playerid, "select_quest_number_panel") == QUEST_PAGE_SELECT_4)
			{
				show_quest_newyear(playerid, TEXTDRAW_HIDE);

				new 
					fmt_str[90];

				TextDrawShowForPlayer(playerid, quest_newyear_td);
				create_quest_newyear_p(playerid);

				PlayerTextDrawSetString(playerid, quest_newyear_p[0][playerid], "brp_quest:quest_newyear_background_8");
				PlayerTextDrawShow(playerid, quest_newyear_p[0][playerid]);


				PlayerTextDrawSetString(playerid, quest_newyear_p[1][playerid], "brp_quest:quest_newyear_4_no_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[1][playerid]);
				PlayerTextDrawSetString(playerid, quest_newyear_p[2][playerid], "brp_quest:quest_newyear_5_no_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[2][playerid]);			
				PlayerTextDrawSetString(playerid, quest_newyear_p[6][playerid], "brp_quest:quest_newyear_8_no_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[6][playerid]);		
				PlayerTextDrawSetString(playerid, quest_newyear_p[7][playerid], "brp_quest:quest_newyear_9_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[7][playerid]);		

				PlayerTextDrawShow(playerid, quest_newyear_p[3][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[4][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[5][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[7][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[8][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[9][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[10][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[11][playerid]);


			 	format(fmt_str,sizeof(fmt_str),"%s", get_prize_quest_newyear_newyear(8));
				PlayerTextDrawSetString(playerid, quest_newyear_p[12][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_newyear_p[12][playerid]);	

				if(pData[playerid][pQuestNewYear][7] == 1)
				{
					PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_4");
					PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);		
				}
				else if(pData[playerid][pQuestNewYear][7] == 2)
				{
					PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_3");
					PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);		
				}
				else if(!pData[playerid][pQuestNewYear][7])
				{
					PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_5");
					PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);		
				}

			 	format(fmt_str,sizeof(fmt_str),"%d/2", page_quest_panel[playerid]);
				PlayerTextDrawSetString(playerid, quest_newyear_p[10][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_newyear_p[10][playerid]);	

				SetPVarIntNew(playerid, "quest_count_newyear_panel", 8);

				SelectTextDraw(playerid, COLOR_BLUE);
			}
		}
		case QUEST_PAGE_3:
		{		
			if(GetPVarIntNew(playerid, "select_quest_number_panel") == QUEST_PAGE_SELECT_1)
			{
				show_quest_newyear(playerid, TEXTDRAW_HIDE);

				new 
					fmt_str[90];

				TextDrawShowForPlayer(playerid, quest_newyear_td);

				create_quest_newyear_p(playerid);

				PlayerTextDrawSetString(playerid, quest_newyear_p[0][playerid], "brp_quest:quest_newyear_background_9");
				PlayerTextDrawShow(playerid, quest_newyear_p[0][playerid]);


				PlayerTextDrawHideEx(playerid, quest_newyear_p[6][playerid]);
				PlayerTextDrawHideEx(playerid, quest_newyear_p[7][playerid]);	


				PlayerTextDrawSetString(playerid, quest_newyear_p[1][playerid], "brp_quest:quest_newyear_10_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[1][playerid]);
				PlayerTextDrawSetString(playerid, quest_newyear_p[2][playerid], "brp_quest:quest_newyear_11_no_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[2][playerid]);			

				PlayerTextDrawShow(playerid, quest_newyear_p[3][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[4][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[5][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[7][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[8][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[9][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[10][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[11][playerid]);


			 	format(fmt_str,sizeof(fmt_str),"%s", get_prize_quest_newyear_newyear(9));
				PlayerTextDrawSetString(playerid, quest_newyear_p[12][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_newyear_p[12][playerid]);	

				if(pData[playerid][pQuestNewYear][8] == 1)
				{
					PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_4");
					PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);		
				}
				else if(pData[playerid][pQuestNewYear][8] == 2)
				{
					PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_3");
					PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);		
				}
				else if(!pData[playerid][pQuestNewYear][8])
				{
					PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_5");
					PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);		
				}

			 	format(fmt_str,sizeof(fmt_str),"%d/2", page_quest_panel[playerid]);
				PlayerTextDrawSetString(playerid, quest_newyear_p[10][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_newyear_p[10][playerid]);	

				SetPVarIntNew(playerid, "quest_count_newyear_panel", 9);

				SelectTextDraw(playerid, COLOR_BLUE);
			}
			else if(GetPVarIntNew(playerid, "select_quest_number_panel") == QUEST_PAGE_SELECT_2)
			{
				show_quest_newyear(playerid, TEXTDRAW_HIDE);

				new 
					fmt_str[90];

				TextDrawShowForPlayer(playerid, quest_newyear_td);
				create_quest_newyear_p(playerid);

				PlayerTextDrawSetString(playerid, quest_newyear_p[0][playerid], "brp_quest:quest_newyear_background_10");
				PlayerTextDrawShow(playerid, quest_newyear_p[0][playerid]);

				PlayerTextDrawHideEx(playerid, quest_newyear_p[6][playerid]);
				PlayerTextDrawHideEx(playerid, quest_newyear_p[7][playerid]);	

				PlayerTextDrawSetString(playerid, quest_newyear_p[1][playerid], "brp_quest:quest_newyear_10_no_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[1][playerid]);
				PlayerTextDrawSetString(playerid, quest_newyear_p[2][playerid], "brp_quest:quest_newyear_11_active");
				PlayerTextDrawShow(playerid, quest_newyear_p[2][playerid]);			

				PlayerTextDrawShow(playerid, quest_newyear_p[3][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[4][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[5][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[7][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[8][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[9][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[10][playerid]);
				PlayerTextDrawShow(playerid, quest_newyear_p[11][playerid]);


			 	format(fmt_str,sizeof(fmt_str),"%s", get_prize_quest_newyear_newyear(10));
				PlayerTextDrawSetString(playerid, quest_newyear_p[12][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_newyear_p[12][playerid]);	

				if(pData[playerid][pQuestNewYear][9] == 1)
				{
					PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_4");
					PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);		
				}
				else if(pData[playerid][pQuestNewYear][9] == 2)
				{
					PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_3");
					PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);		
				}
				else if(!pData[playerid][pQuestNewYear][9])
				{
					PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_5");
					PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);		
				}

			 	format(fmt_str,sizeof(fmt_str),"%d/2", page_quest_panel[playerid]);
				PlayerTextDrawSetString(playerid, quest_newyear_p[10][playerid], fmt_str);
				PlayerTextDrawShow(playerid, quest_newyear_p[10][playerid]);	

				SetPVarIntNew(playerid, "quest_count_newyear_panel", 10);

				SelectTextDraw(playerid, COLOR_BLUE);
			}
		}
	}

	return true;
}


stock send_quest_newyear_info(playerid)
{ 
	if(pData[playerid][pQuestNewYear][3] == 2)
	{
		if(GetPVarIntNew(playerid, "wood_quest_newyear") >= 10)
		{
			SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Вы успешно срубили 10 деревьев!\n\n\
			"cBLUE"Отправляйтесь к Ивану и положите дрова!\n\n\
			"cWH"(( Иван находится резеденции Деда Мороза на втором этаже! ))", !"Закрыть", "");

			SetPlayerCheckpoint(playerid, GPS_NEWYEAR_DED, 5.0);
		}
	}
	if(pData[playerid][pQuestNewYear][4] == 2)
	{
		if(GetPVarIntNew(playerid, "pizza_quest_newyear") == 1)
		{
			SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Вы успешно купили пиццу!\n\n\
			"cBLUE"Отправляйтесь к Ивану и накормите его наконец-то!\n\n\
			"cWH"(( Иван находится резеденции Деда Мороза на втором этаже! ))", !"Закрыть", "");

			SetPlayerCheckpoint(playerid, GPS_NEWYEAR_DED, 5.0);
		}
	}
	return true;
}

stock dialog_ivan_quest_newyear(playerid)
{
	if(pData[playerid][pQuestNewYear][3] == 2)
	{
		if(GetPVarIntNew(playerid, "wood_quest_newyear") >= 10)
		{
			SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Иван на печи", ""cWH"Спасибо за дрова!\n\n\
			"cBLUE"Теперь будет действительно теплёнько, есть чем печь топить!\n\n\
			"cWH"Ладно, держи свой подарок, приступай к следующим заданиям!", !"Закрыть", "");

			DeletePVarNew(playerid, "wood_quest_newyear");

			check_accept_quest_newyear(playerid, 3);
		}
	}
	if(pData[playerid][pQuestNewYear][4] == 2)
	{
		if(GetPVarIntNew(playerid, "pizza_quest_newyear") == 1)
		{
			SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Иван на печи", ""cWH"Спасибо за пиццу!\n\n\
			"cBLUE"Наконец-то я смогу нормально поесть! А ты молодчина!\n\n\
			"cWH"Держи снежинки и опыт за помощь, я ценю таких!", !"Закрыть", "");

			DeletePVarNew(playerid, "pizza_quest_newyear");

			check_accept_quest_newyear(playerid, 4);
		}
	}
	else if(!pData[playerid][pQuestNewYear][4] && !pData[playerid][pQuestNewYear][3])
	{
		SendInf(playerid, "Иван: Давай ты сперва разберешься с остальными заданиями и потом мы поговорим!");
	}
	return true;
}

stock check_accept_quest_newyear(playerid, quest_id)
{
	switch(quest_id)
	{
		case 0:
		{	
			if(pData[playerid][pQuestNewYear][0] == 2)
			{
				pData[playerid][pQuestNewYear][0] = 1;

				SCM(playerid, -1, "");
				SendSucc(playerid, "Квестовое задание успешно выполнено! Вы получили 1 очко опыта и 1 снежинку!");
				SendInf(playerid, "Принять новое задание можно через команду /quest или у NPC на спавнах!");

				logs_quest_player(playerid, pData[playerid][pMysqlID], "Выполнил полностью 1 квест!");
			
				pData[playerid][pCountSnow]++;
				UpdatePlayerData(playerid, "pCountSnow", pData[playerid][pCountSnow]);
				pData[playerid][pExp]++;
				check_next_level_player(playerid);

				show_notify_gui_newyear(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:newyear_snow_give_1", 4500);
				show_notify_gui_newyear(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:newyear_snow_quest_final", 4500);	
			}
		}
		case 1:
		{	
			if(pData[playerid][pQuestNewYear][1] == 2)
			{
				if(GetPVarIntNew(playerid, "count_working_snow") >= 3)
				{
					pData[playerid][pQuestNewYear][1] = 1;
				
					SCM(playerid, -1, "");
					SendSucc(playerid, "Квестовое задание успешно выполнено! Вы получили 1 очко опыта и 1 снежинку!");
					SendInf(playerid, "Принять новое задание можно через команду /quest или у NPC на спавнах!");

					logs_quest_player(playerid, pData[playerid][pMysqlID], "Выполнил полностью 2 квест!");

					pData[playerid][pCountSnow]++;
					UpdatePlayerData(playerid, "pCountSnow", pData[playerid][pCountSnow]);
					pData[playerid][pExp]++;
					check_next_level_player(playerid);		

					show_notify_gui_newyear(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:newyear_snow_give_1", 4500);	
					show_notify_gui_newyear(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:newyear_snow_quest_final", 4500);	
				}
			}
		}
		case 2:
		{	
			if(pData[playerid][pQuestNewYear][2] == 2)
			{
				if(GetPVarIntNew(playerid, "count_prize_snow_quest") >= 10)
				{

					pData[playerid][pQuestNewYear][2] = 1;

					SCM(playerid, -1, "");					
					SendSucc(playerid, "Квестовое задание успешно выполнено! Вы получили 1 очко опыта и 1 снежинку!");
					SendInf(playerid, "Принять новое задание можно через команду /quest или у NPC на спавнах!");

					logs_quest_player(playerid, pData[playerid][pMysqlID], "Выполнил полностью 3 квест!");

					pData[playerid][pCountSnow]++;
					UpdatePlayerData(playerid, "pCountSnow", pData[playerid][pCountSnow]);
					pData[playerid][pExp]++;
					check_next_level_player(playerid);			

					show_notify_gui_newyear(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:newyear_snow_give_1", 4500);
					show_notify_gui_newyear(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:newyear_snow_quest_final", 4500);	
				}

			}
		}
		case 3:
		{	
			if(pData[playerid][pQuestNewYear][3] == 2)
			{
				pData[playerid][pQuestNewYear][3] = 1;

				SCM(playerid, -1, "");				
				SendSucc(playerid, "Квестовое задание успешно выполнено! Вы получили 1 очко опыта и 1 снежинку!");
				SendInf(playerid, "Принять новое задание можно через команду /quest или у NPC на спавнах!");

				logs_quest_player(playerid, pData[playerid][pMysqlID], "Выполнил полностью 4 квест!");

				pData[playerid][pCountSnow]++;
				UpdatePlayerData(playerid, "pCountSnow", pData[playerid][pCountSnow]);
				pData[playerid][pExp]++;
				check_next_level_player(playerid);		

				show_notify_gui_newyear(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:newyear_snow_give_1", 4500);	
				show_notify_gui_newyear(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:newyear_snow_quest_final", 4500);	

			}
		}
		case 4:
		{	
			if(pData[playerid][pQuestNewYear][4] == 2)
			{
				pData[playerid][pQuestNewYear][4] = 1;


				SCM(playerid, -1, "");
				SendSucc(playerid, "Квестовое задание успешно выполнено! Вы получили 1 очко опыта и 1 снежинку!");
				SendInf(playerid, "Принять новое задание можно через команду /quest или у NPC на спавнах!");

				logs_quest_player(playerid, pData[playerid][pMysqlID], "Выполнил полностью 5 квест!");

				pData[playerid][pCountSnow]++;
				UpdatePlayerData(playerid, "pCountSnow", pData[playerid][pCountSnow]);
				pData[playerid][pExp]++;
				check_next_level_player(playerid);	

				show_notify_gui_newyear(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:newyear_snow_give_1", 4500);		
				show_notify_gui_newyear(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:newyear_snow_quest_final", 4500);	

			}
		}

		case 5:
		{	
			if(pData[playerid][pQuestNewYear][5] == 2)
			{
				pData[playerid][pQuestNewYear][5] = 1;

				SCM(playerid, -1, "");
				SendSucc(playerid, "Квестовое задание успешно выполнено! Вы получили 1 очко опыта и 1 снежинку!");
				SendInf(playerid, "Принять новое задание можно через команду /quest или у NPC на спавнах!");

				logs_quest_player(playerid, pData[playerid][pMysqlID], "Выполнил полностью 6 квест!");

				pData[playerid][pCountSnow]++;
				UpdatePlayerData(playerid, "pCountSnow", pData[playerid][pCountSnow]);
				pData[playerid][pExp]++;
				check_next_level_player(playerid);		

				show_notify_gui_newyear(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:newyear_snow_give_1", 4500);	
				show_notify_gui_newyear(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:newyear_snow_quest_final", 4500);	

			}
		}
		case 6:
		{	
			if(pData[playerid][pQuestNewYear][6] == 2)
			{
				pData[playerid][pQuestNewYear][6] = 1;

				SCM(playerid, -1, "");
				SendSucc(playerid, "Квестовое задание успешно выполнено! Вы получили 1 очко опыта и 1 снежинку!");
				SendInf(playerid, "Принять новое задание можно через команду /quest или у NPC на спавнах!");

				logs_quest_player(playerid, pData[playerid][pMysqlID], "Выполнил полностью 7 квест!");

				pData[playerid][pCountSnow]++;
				UpdatePlayerData(playerid, "pCountSnow", pData[playerid][pCountSnow]);
				pData[playerid][pExp]++;
				check_next_level_player(playerid);		

				show_notify_gui_newyear(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:newyear_snow_give_1", 4500);	
				show_notify_gui_newyear(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:newyear_snow_quest_final", 4500);	

			}
		}
		case 7:
		{	
			if(pData[playerid][pQuestNewYear][7] == 2)
			{
				pData[playerid][pQuestNewYear][7] = 1;

				SCM(playerid, -1, "");
				SendSucc(playerid, "Квестовое задание успешно выполнено! Вы получили 1 очко опыта и 1 снежинку!");
				SendInf(playerid, "Принять новое задание можно через команду /quest или у NPC на спавнах!");

				logs_quest_player(playerid, pData[playerid][pMysqlID], "Выполнил полностью 8 квест!");

				pData[playerid][pCountSnow]++;
				UpdatePlayerData(playerid, "pCountSnow", pData[playerid][pCountSnow]);
				pData[playerid][pExp]++;
				check_next_level_player(playerid);	

				show_notify_gui_newyear(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:newyear_snow_give_1", 4500);
				show_notify_gui_newyear(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:newyear_snow_quest_final", 4500);	

				pData[playerid][pQuestNewYear][0] = 0;
				pData[playerid][pQuestNewYear][1] = 0;
				pData[playerid][pQuestNewYear][2] = 0;
				pData[playerid][pQuestNewYear][3] = 0;
				pData[playerid][pQuestNewYear][4] = 0;
				pData[playerid][pQuestNewYear][5] = 0;
				pData[playerid][pQuestNewYear][6] = 0;
				pData[playerid][pQuestNewYear][7] = 0;

				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Вы выполнили все задания и у Вас есть уникальные возможность пройти их вновь!\n\n\
				Все выполненные задания были аннулированы, теперь Вы можете пройти всё вновь!", !"Закрыть", "");
			}
		}

	}
	return true;
}

stock check_status_quest_newyear(playerid, quest_id)
{

	switch(quest_id)
	{
		case 0:
		{
			if(!pData[playerid][pQuestNewYear][0])
			{
				pData[playerid][pQuestNewYear][0] = 2;
				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Вы успешно приняли задание, отправляйтесь на работу Снегоуборщиком!\n\n\
				"cBLUE"Найти работу можно через навигатор: /gps - Работы - Работа Снегоуборщиком!\n\n\
				"cWH"Для выполнения задания Вам требуется устроиться на работу!", !"Закрыть", "");

				PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_3");
				PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);

			}
			else if(pData[playerid][pQuestNewYear][0] == 2)
			{
				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Вы уже приняли задание, отправляйтесь на работу Снегоуборщиком!\n\n\
				"cBLUE"Найти работу можно через навигатор: /gps - Работы - Работа Снегоуборщиком!\n\n\
				"cWH"Для выполнения задания Вам требуется устроиться на работу!", !"Закрыть", "");
			}
			else if(pData[playerid][pQuestNewYear][0] == 1)
			{
				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Вы уже выполняли данное задание, выберите следующее!", !"Закрыть", "");
			}
		}

		case 1:
		{
			if(!pData[playerid][pQuestNewYear][1] && pData[playerid][pQuestNewYear][0] == 1)
			{
				pData[playerid][pQuestNewYear][1] = 2;
				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Вы успешно приняли задание, отправляйтесь на работу Снегоуборщиком!\n\n\
				"cBLUE"Найти работу можно через навигатор: /gps - Работы - Работа Снегоуборщиком!\n\n\
				"cWH"Для выполнения задания Вам требуется проехать 3 рейса!", !"Закрыть", "");

				PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_3");
				PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);

			}
			else if(!pData[playerid][pQuestNewYear][1] && !pData[playerid][pQuestNewYear][0])
			{
				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Сперва требуется выполнить предыдущее задание!", !"Закрыть", "");
			}
			else if(pData[playerid][pQuestNewYear][1] == 2)
			{
				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Вы уже приняли задание, отправляйтесь на работу Снегоуборщиком!\n\n\
				"cBLUE"Найти работу можно через навигатор: /gps - Работы - Работа Снегоуборщиком!\n\n\
				"cWH"Для выполнения задания Вам требуется проехать 3 рейса!", !"Закрыть", "");
			}
			else if(pData[playerid][pQuestNewYear][1] == 1)
			{
				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Вы уже выполняли данное задание, выберите следующее!", !"Закрыть", "");
			}
		}
		case 2:
		{
			if(!pData[playerid][pQuestNewYear][2] && pData[playerid][pQuestNewYear][0] == 1 && pData[playerid][pQuestNewYear][1] == 1)
			{
				pData[playerid][pQuestNewYear][2] = 2;
				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Вы успешно приняли задание, отправляйтесь на главную площадь!\n\n\
				"cBLUE"Найти площадь можно через навигатор: /gps - Новогодние развлечения - Новогодняя площадь!\n\n\
				"cWH"Для выполнения задания Вам требуется раскидать снег по площади 10 раз (на специальных пикапах)!", !"Закрыть", "");

				quest_snow_random_accept(playerid);

				PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_3");
				PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);

			}
			else if(!pData[playerid][pQuestNewYear][2] && !pData[playerid][pQuestNewYear][0] && !pData[playerid][pQuestNewYear][1])
			{
				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Сперва требуется выполнить предыдущее задание!", !"Закрыть", "");
			}
			else if(pData[playerid][pQuestNewYear][2] == 2)
			{
				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Вы уже приняли задание, отправляйтесь на главную площадь!\n\n\
				"cBLUE"Найти площадь можно через навигатор: /gps - Новогодние развлечения - Новогодняя площадь!\n\n\
				"cWH"Для выполнения задания Вам требуется раскидать снег по площади 10 раз (на специальных пикапах)!", !"Закрыть", "");

				quest_snow_random_accept(playerid);
			}
			else if(pData[playerid][pQuestNewYear][2] == 1)
			{
				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Вы уже выполняли данное задание, выберите следующее!", !"Закрыть", "");
			}
		}
		case 3:
		{
			if(!pData[playerid][pQuestNewYear][3] && pData[playerid][pQuestNewYear][0] == 1 && pData[playerid][pQuestNewYear][1] == 1 && pData[playerid][pQuestNewYear][2] == 1)
			{
				pData[playerid][pQuestNewYear][3] = 2;
				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Вы успешно приняли задание, отправляйтесь на лесопилку и нарубите дров!\n\n\
				"cBLUE"Найти лесопилку можно через навигатор: /gps - Работы - Лесопилка!\n\n\
				"cWH"Для выполнения задания Вам требуется срубить 10 деревьев и отвезти их Ивану!", !"Закрыть", "");

				SetPlayerCheckpoint(playerid, GPS_WORK_WOOD, 5.0);

				PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_3");
				PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);

			}
			else if(!pData[playerid][pQuestNewYear][3] && !pData[playerid][pQuestNewYear][0] && !pData[playerid][pQuestNewYear][1] && !pData[playerid][pQuestNewYear][2])
			{
				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Сперва требуется выполнить предыдущее задание!", !"Закрыть", "");
			}
			else if(pData[playerid][pQuestNewYear][3] == 2)
			{
				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Вы уже приняли задание, отправляйтесь на лесопилку и нарубите дров!\n\n\
				"cBLUE"Найти лесопилку можно через навигатор: /gps - Работы - Лесопилка!\n\n\
				"cWH"Для выполнения задания Вам требуется срубить 10 деревьев и отвезти их Ивану!", !"Закрыть", "");

				SetPlayerCheckpoint(playerid, GPS_WORK_WOOD, 5.0);
			}
			else if(pData[playerid][pQuestNewYear][3] == 1)
			{
				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Вы уже выполняли данное задание, выберите следующее!", !"Закрыть", "");
			}
		}

		case 4:
		{
			if(!pData[playerid][pQuestNewYear][4] && pData[playerid][pQuestNewYear][0] == 1 && pData[playerid][pQuestNewYear][1] == 1 && pData[playerid][pQuestNewYear][2] == 1
			&& pData[playerid][pQuestNewYear][3] == 1)
			{
				pData[playerid][pQuestNewYear][4] = 2;
				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Вы успешно приняли задание, отправляйтесь в кафе 'Лес'!\n\n\
				"cBLUE"Найти кафе можно через навигатор: /gps - Новогодние развлечения - Кафе 'Лес'!\n\n\
				"cWH"Для выполнения задания Вам требуется купить пиццу и отнести её Ивану!", !"Закрыть", "");



				PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_3");
				PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);

			}
			else if(!pData[playerid][pQuestNewYear][4] && !pData[playerid][pQuestNewYear][0] && !pData[playerid][pQuestNewYear][1] && !pData[playerid][pQuestNewYear][2]
			&& !pData[playerid][pQuestNewYear][3])
			{
				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Сперва требуется выполнить предыдущее задание!", !"Закрыть", "");
			}
			else if(pData[playerid][pQuestNewYear][4] == 2)
			{
				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Вы уже приняли задание, отправляйтесь в кафе 'Лес'!\n\n\
				"cBLUE"Найти кафе можно через навигатор: /gps - Новогодние развлечения - Кафе 'Лес'!\n\n\
				"cWH"Для выполнения задания Вам требуется купить пиццу и отнести её Ивану!", !"Закрыть", "");
			}
			else if(pData[playerid][pQuestNewYear][4] == 1)
			{
				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Вы уже выполняли данное задание, выберите следующее!", !"Закрыть", "");
			}
		}

		case 5:
		{
			if(!pData[playerid][pQuestNewYear][5] && pData[playerid][pQuestNewYear][0] == 1 && pData[playerid][pQuestNewYear][1] == 1 && pData[playerid][pQuestNewYear][2] == 1
			&& pData[playerid][pQuestNewYear][3] == 1 && pData[playerid][pQuestNewYear][4] == 1)
			{
				pData[playerid][pQuestNewYear][5] = 2;
				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Вы успешно приняли задание, отправляйтесь на завод и соберите мебель!\n\n\
				"cBLUE"Найти завод можно через навигатор: /gps - Работы - Завод!\n\n\
				"cWH"Для выполнения задания Вам требуется собрать 10 единиц мебели!", !"Закрыть", "");

				SetPlayerCheckpoint(playerid, GPS_WORK_ZAVOD, 5.0);

				PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_3");
				PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);

			}
			else if(!pData[playerid][pQuestNewYear][5] && !pData[playerid][pQuestNewYear][0] && !pData[playerid][pQuestNewYear][1] && !pData[playerid][pQuestNewYear][2]
			&& !pData[playerid][pQuestNewYear][3] && !pData[playerid][pQuestNewYear][4])
			{
				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Сперва требуется выполнить предыдущее задание!", !"Закрыть", "");
			}
			else if(pData[playerid][pQuestNewYear][5] == 2)
			{
				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Вы уже приняли задание, отправляйтесь на завод и соберите мебель!\n\n\
				"cBLUE"Найти завод можно через навигатор: /gps - Работы - Завод!\n\n\
				"cWH"Для выполнения задания Вам требуется собрать 10 единиц мебели!", !"Закрыть", "");

				SetPlayerCheckpoint(playerid, GPS_WORK_ZAVOD, 5.0);
			}
			else if(pData[playerid][pQuestNewYear][5] == 1)
			{
				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Вы уже выполняли данное задание, выберите следующее!", !"Закрыть", "");
			}
		}

		case 6:
		{
			if(!pData[playerid][pQuestNewYear][6] && pData[playerid][pQuestNewYear][0] == 1 && pData[playerid][pQuestNewYear][1] == 1 && pData[playerid][pQuestNewYear][2] == 1
			&& pData[playerid][pQuestNewYear][3] == 1 && pData[playerid][pQuestNewYear][4] == 1 && pData[playerid][pQuestNewYear][5] == 1)
			{
				pData[playerid][pQuestNewYear][6] = 2;
				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Вы успешно приняли задание, отправляйтесь на шахту и соберите 10 алмазов!\n\n\
				"cBLUE"Найти шахту можно через навигатор: /gps - Работы - Шахта!\n\n\
				"cWH"Для выполнения задания Вам требуется собрать 10 алмазов!", !"Закрыть", "");

				SetPlayerCheckpoint(playerid, GPS_WORK_MINER, 5.0);

				PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_3");
				PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);

			}
			else if(!pData[playerid][pQuestNewYear][6] && !pData[playerid][pQuestNewYear][0] && !pData[playerid][pQuestNewYear][1] && !pData[playerid][pQuestNewYear][2]
			&& !pData[playerid][pQuestNewYear][3] && !pData[playerid][pQuestNewYear][4] && !pData[playerid][pQuestNewYear][5])
			{
				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Сперва требуется выполнить предыдущее задание!", !"Закрыть", "");
			}
			else if(pData[playerid][pQuestNewYear][6] == 2)
			{
				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Вы уже приняли задание, отправляйтесь на шахту и соберите 10 алмазов!\n\n\
				"cBLUE"Найти шахту можно через навигатор: /gps - Работы - Шахта!\n\n\
				"cWH"Для выполнения задания Вам требуется собрать 10 алмазов!", !"Закрыть", "");

				SetPlayerCheckpoint(playerid, GPS_WORK_MINER, 5.0);
			}
			else if(pData[playerid][pQuestNewYear][6] == 1)
			{
				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Вы уже выполняли данное задание, выберите следующее!", !"Закрыть", "");
			}
		}

		case 7:
		{
			if(!pData[playerid][pQuestNewYear][7] && pData[playerid][pQuestNewYear][0] == 1 && pData[playerid][pQuestNewYear][1] == 1 && pData[playerid][pQuestNewYear][2] == 1
			&& pData[playerid][pQuestNewYear][3] == 1 && pData[playerid][pQuestNewYear][4] == 1 && pData[playerid][pQuestNewYear][5] == 1 && pData[playerid][pQuestNewYear][6] == 1)
			{
				pData[playerid][pQuestNewYear][7] = 2;
				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Вы успешно приняли задание, отправляйтесь по домам и развезите подарки!\n\n\
				"cBLUE"Дома отмечаются у Вас на карте, повторная попытка - /housepodarok!\n\n\
				"cWH"Для выполнения задания Вам требуется развести 30 подарков!", !"Закрыть", "");

				generate_random_house_newyear(playerid);

				PlayerTextDrawSetString(playerid, quest_newyear_p[13][playerid], "brp_quest:quest_newyear_3");
				PlayerTextDrawShow(playerid, quest_newyear_p[13][playerid]);

			}
			else if(!pData[playerid][pQuestNewYear][7] && !pData[playerid][pQuestNewYear][0] && !pData[playerid][pQuestNewYear][1] && !pData[playerid][pQuestNewYear][2]
			&& !pData[playerid][pQuestNewYear][3] && !pData[playerid][pQuestNewYear][4] && !pData[playerid][pQuestNewYear][5] && !pData[playerid][pQuestNewYear][6])
			{
				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Сперва требуется выполнить предыдущее задание!", !"Закрыть", "");
			}
			else if(pData[playerid][pQuestNewYear][7] == 2)
			{
				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Вы уже приняли задание, отправляйтесь по домам и развезите подарки!\n\n\
				"cBLUE"Дома отмечаются у Вас на карте, повторная попытка - /housepodarok!\n\n\
				"cWH"Для выполнения задания Вам требуется развести 30 подарков!", !"Закрыть", "");

				generate_random_house_newyear(playerid);
			}
			else if(pData[playerid][pQuestNewYear][7] == 1)
			{
				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Вы уже выполняли данное задание, выберите следующее!", !"Закрыть", "");
			}
		}
	}

	return true;
} 


/*CMD:housepodarok(playerid)
{
	return generate_random_house_newyear(playerid);
}*/

stock generate_random_house_newyear(playerid)
{
	if(GetPVarIntNew(playerid, "house_count_prize_newyear") >= 30)
	{
		return check_accept_quest_newyear(playerid, 7);
	}

	new 
		i = random(94);

	SetPlayerCheckpoint(playerid, House[i][house_enter_x], House[i][house_enter_y], House[i][house_enter_z], 5.0);


	SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новогодний квест", ""cWH"Позиция дома установлена у Вас на мини-карте!\n\n\
	Отправляйтесь и доставьте подарок!", !"Закрыть", "");

	format(String64, sizeof(String64), "Вам осталось развести %d подарков!", 30-GetPVarIntNew(playerid, "house_count_prize_newyear"));
	SendInf(playerid, String64);

	status_navigator_player(playerid, TEXTDRAW_SHOW);

	SetPVarIntNew(playerid, "active_player_house_newyear", 1);
	return true;	
	

}


