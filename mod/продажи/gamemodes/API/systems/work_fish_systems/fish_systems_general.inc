

static const Float:fish_position_static[][] = 
{

	{-1123.3955,2293.3430,37.2906},
	{-1121.8048,2296.2261,37.2906},
	{-1120.2345,2299.0723,37.2906},
	{-1118.2109,2302.7405,37.2906},
	{-1116.5103,2305.8250,37.2906}

};


stock get_fish_name(type)
{
	new 
		name[40];

	switch(type)
	{
		case 1: name = "Лосось";
		case 2: name = "Горбуша";
		case 3: name = "Сазан";
		case 4: name = "Сом";
		case 5: name = "Треска";
		case 6: name = "Тунец";
		case 7: name = "Судак";
		case 8: name = "Сёмга";
		case 9: name = "Скумбрия";
		case 10: name = "Лещ";
		case 11: name = "Щука";
		case 12: name = "Форель";
		case 13: name = "Плотва";
		case 14: name = "Лакендра";
		case 15: name = "Макрель";
		default: name = "Неизвестно";
	}
	return name;
}

stock get_fish_name_textdraw(type)
{
	new 
		name[40];

	switch(type)
	{
		case FISH_MODELS_LOSOS:  	name = "brilliantother:fish_object_3";
		case FISH_MODELS_GORBUSHA:  name = "brilliantother:fish_object_4";
		case FISH_MODELS_SAZAN:  	name = "brilliantother:fish_object_5";
		case FISH_MODELS_SOM: 	 	name = "brilliantother:fish_object_6";
		case FISH_MODELS_TRESKA: 	name = "brilliantother:fish_object_7";
		case FISH_MODELS_TUNEC: 	name = "brilliantother:fish_object_8";
		case FISH_MODELS_SUDAK: 	name = "brilliantother:fish_object_9";
		case FISH_MODELS_SEMGA: 	name = "brilliantother:fish_object_10";
		case FISH_MODELS_SKUMBRIA: 	name = "brilliantother:fish_object_2";
		case FISH_MODELS_LEH: 		name = "brilliantother:fish_object_12";
		case FISH_MODELS_SHUKA: 	name = "brilliantother:fish_object_13";
		case FISH_MODELS_FOREL: 	name = "brilliantother:fish_object_4";
		case FISH_MODELS_PLOTVA: 	name = "brilliantother:fish_object_14";
		case FISH_MODELS_LAKENDRA: 	name = "brilliantother:fish_object_1";
		case FISH_MODELS_MAKREL: 	name = "brilliantother:fish_object_11";
		default: name = "Неизвестно";
	}
	return name;
}


stock create_fish_other_elements()
{
	for(new i; i < sizeof(fish_position_static); i++)
	{
		fish_position_player[i] = create_circle_pickup(fish_position_static[i][0], fish_position_static[i][1], fish_position_static[i][2], TRIGGER_LBLUE);

		CreateDynamic3DTextLabel(""cWH"Место для ловли рыбы\n"cBLUE"[Встаньте на пикап]",-1, \
		fish_position_static[i][0], fish_position_static[i][1], fish_position_static[i][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	
	}

	CreateActor(FISH_ACTOR_SKIN, FISH_ACTOR_POSITION);
	CreateDynamic3DTextLabel("Рыбак Василич\n"cLRED"Продажа рыбу и информация", -1, -1118.5178,2308.0132,37.2906, 17.0);

	actor_fish_general = create_circle_pickup(-1118.2839,2307.0149,37.2906, TRIGGER_LRED);


	return true;
}

CMD:fishall(playerid)
{
	return fish_panel_all_fish(playerid, TEXTDRAW_SHOW);
}

stock fish_panel_all_fish(playerid, type)
{

	switch(type)
	{
		case TEXTDRAW_SHOW:
		{
			show_info_gui(playerid, TEXTDRAW_HIDE);

			hide_hud_element(playerid);
			show_player_green_zone(playerid, TEXTDRAW_HIDE);

			create_fish_panel_all(playerid);

			PlayerTextDrawShow(playerid, fish_panel_all[0][playerid]);

			for(new i = 1; i < 17; i++)
			{			
				PlayerTextDrawShow(playerid, fish_panel_all[i][playerid]);
			}

			new 
				fmt_str[20];

			format(fmt_str, sizeof(fmt_str), "%d", fish_count_player[playerid][0]);
			PlayerTextDrawSetString(playerid, fish_panel_all[17][playerid], fmt_str);
			PlayerTextDrawShow(playerid, fish_panel_all[17][playerid]);

			format(fmt_str, sizeof(fmt_str), "%d", fish_count_player[playerid][1]);
			PlayerTextDrawSetString(playerid, fish_panel_all[18][playerid], fmt_str);
			PlayerTextDrawShow(playerid, fish_panel_all[18][playerid]);

			format(fmt_str, sizeof(fmt_str), "%d", fish_count_player[playerid][2]);
			PlayerTextDrawSetString(playerid, fish_panel_all[19][playerid], fmt_str);
			PlayerTextDrawShow(playerid, fish_panel_all[19][playerid]);

			format(fmt_str, sizeof(fmt_str), "%d", fish_count_player[playerid][3]);
			PlayerTextDrawSetString(playerid, fish_panel_all[20][playerid], fmt_str);
			PlayerTextDrawShow(playerid, fish_panel_all[20][playerid]);

			format(fmt_str, sizeof(fmt_str), "%d", fish_count_player[playerid][4]);
			PlayerTextDrawSetString(playerid, fish_panel_all[21][playerid], fmt_str);
			PlayerTextDrawShow(playerid, fish_panel_all[21][playerid]);

			format(fmt_str, sizeof(fmt_str), "%d", fish_count_player[playerid][5]);
			PlayerTextDrawSetString(playerid, fish_panel_all[22][playerid], fmt_str);
			PlayerTextDrawShow(playerid, fish_panel_all[22][playerid]);

			format(fmt_str, sizeof(fmt_str), "%d", fish_count_player[playerid][6]);
			PlayerTextDrawSetString(playerid, fish_panel_all[23][playerid], fmt_str);
			PlayerTextDrawShow(playerid, fish_panel_all[23][playerid]);

			format(fmt_str, sizeof(fmt_str), "%d", fish_count_player[playerid][7]);
			PlayerTextDrawSetString(playerid, fish_panel_all[24][playerid], fmt_str);
			PlayerTextDrawShow(playerid, fish_panel_all[24][playerid]);

			format(fmt_str, sizeof(fmt_str), "%d", fish_count_player[playerid][8]);
			PlayerTextDrawSetString(playerid, fish_panel_all[25][playerid], fmt_str);
			PlayerTextDrawShow(playerid, fish_panel_all[25][playerid]);

			format(fmt_str, sizeof(fmt_str), "%d", fish_count_player[playerid][9]);
			PlayerTextDrawSetString(playerid, fish_panel_all[26][playerid], fmt_str);
			PlayerTextDrawShow(playerid, fish_panel_all[26][playerid]);

			format(fmt_str, sizeof(fmt_str), "%d", fish_count_player[playerid][10]);
			PlayerTextDrawSetString(playerid, fish_panel_all[27][playerid], fmt_str);
			PlayerTextDrawShow(playerid, fish_panel_all[27][playerid]);

			format(fmt_str, sizeof(fmt_str), "%d", fish_count_player[playerid][11]);
			PlayerTextDrawSetString(playerid, fish_panel_all[28][playerid], fmt_str);
			PlayerTextDrawShow(playerid, fish_panel_all[28][playerid]);

			format(fmt_str, sizeof(fmt_str), "%d", fish_count_player[playerid][12]);
			PlayerTextDrawSetString(playerid, fish_panel_all[29][playerid], fmt_str);
			PlayerTextDrawShow(playerid, fish_panel_all[29][playerid]);

			format(fmt_str, sizeof(fmt_str), "%d", fish_count_player[playerid][13]);
			PlayerTextDrawSetString(playerid, fish_panel_all[30][playerid], fmt_str);
			PlayerTextDrawShow(playerid, fish_panel_all[30][playerid]);

			format(fmt_str, sizeof(fmt_str), "%d", fish_count_player[playerid][14]);
			PlayerTextDrawSetString(playerid, fish_panel_all[31][playerid], fmt_str);
			PlayerTextDrawShow(playerid, fish_panel_all[31][playerid]);

			SelectTextDraw(playerid, COLOR_BLUE);

		}
		case TEXTDRAW_HIDE:
		{
			for(new i; i < 32; i++)
			{			
				PlayerTextDrawHideEx(playerid, fish_panel_all[i][playerid]);
			}

			if(pGreenZone[playerid])
			{
				show_player_green_zone(playerid, TEXTDRAW_SHOW);
			}
			show_hud_element(playerid);
			show_hud_hungry(playerid);

			show_info_gui(playerid, TEXTDRAW_SHOW);

			CancelSelectTextDraw(playerid);
		}
	}


	return true;
}

stock fish_attach_player_ud(playerid, status, type = 0)
{
	switch(status)
	{

		case TEXTDRAW_SHOW:
		{
			if(!IsPlayerAttachedObjectSlotUsed(playerid, 7))
			{
				SetPlayerAttachedObjectEx(playerid, 7, type, 6, 
				0.079376,0.037070,0.007706,
				181.482910,0.000000,0.000000,
				1.000000,1.000000,1.000000);
			}
		}
		case TEXTDRAW_HIDE:
		{
			RemovePlayerAttachedObject(playerid, 7);
		}
	}
	return true;
}

stock fish_panel_general_panel(playerid, status)	// Самая главная панель у рыболова
{

	if(!GetPVarIntNew(playerid, "udochka_type_hand"))
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:notify_player_work_34", 4000);
		return SendErr(playerid, "У вас должны быть удочка в руках!");
	}

	switch(status)
	{
		case TEXTDRAW_SHOW:
		{
			create_fish_general_panel(playerid);

			show_info_gui(playerid, TEXTDRAW_HIDE);

			PlayerTextDrawSetString(playerid, fish_p_general[0][playerid], "brilliantother:fish_progress_bar_0");
			PlayerTextDrawShow(playerid, fish_p_general[0][playerid]);

			PlayerTextDrawSetString(playerid, fish_p_general[2][playerid], "brilliantother:fish_button_start");
			PlayerTextDrawShow(playerid, fish_p_general[2][playerid]);

			PlayerTextDrawShow(playerid, fish_p_general[3][playerid]);

			SelectTextDraw(playerid, COLOR_BLUE);
		
			SetPVarIntNew(playerid, "fish_status_player", FISH_STATUS_NO_START);
		}
		case TEXTDRAW_HIDE:
		{

			PlayerTextDrawHideEx(playerid, fish_p_general[0][playerid]);
			PlayerTextDrawHideEx(playerid, fish_p_general[1][playerid]);
			PlayerTextDrawHideEx(playerid, fish_p_general[2][playerid]);
			PlayerTextDrawHideEx(playerid, fish_p_general[3][playerid]);
			
			CancelSelectTextDraw(playerid);
		}	
	}


	return true;
}

stock fish_card_prefinal(playerid, status)	// Золотая карточка, когда игрок словил рыбу
{
	switch(status)
	{
		case TEXTDRAW_SHOW:
		{
			TextDrawShowForPlayer(playerid, fish_prefinal_panel[0]);
			TextDrawShowForPlayer(playerid, fish_prefinal_panel[1]);
		
			SelectTextDraw(playerid, COLOR_BLUE);
		}
		case TEXTDRAW_HIDE:
		{
			TextDrawHideForPlayer(playerid, fish_prefinal_panel[0]);
			TextDrawHideForPlayer(playerid, fish_prefinal_panel[1]);

			CancelSelectTextDraw(playerid);			
		}
	}

	return true;
}

stock fish_car_open_panel(playerid, status, type)	// Открывается, когда игрок нажимает на карточку золотую
{
	new 
		fmt_str[20];

	fish_card_prefinal(playerid, TEXTDRAW_HIDE);

	switch(status)
	{
		case TEXTDRAW_SHOW:
		{	
			create_fish_final_player(playerid);

			switch(type)
			{
				case FISH_MODELS_LOSOS:	
				{
					PlayerTextDrawSetString(playerid, fish_panel_final[0][playerid], "brilliantother:fish_background_effect_1");
					PlayerTextDrawShow(playerid, fish_panel_final[0][playerid]);
					PlayerTextDrawSetString(playerid, fish_panel_final[1][playerid], "brilliantother:fish_panel_final_1");
					PlayerTextDrawShow(playerid, fish_panel_final[1][playerid]);

					PlayerTextDrawShow(playerid, fish_panel_final[2][playerid]);
					PlayerTextDrawShow(playerid, fish_panel_final[3][playerid]);

					update_count_fish_statistic(playerid, 1, FISH_MODELS_LOSOS);

					format(fmt_str, sizeof(fmt_str), "%d", fish_count_player[playerid][0]);
					PlayerTextDrawSetString(playerid, fish_panel_final[4][playerid], fmt_str);
					PlayerTextDrawShow(playerid, fish_panel_final[4][playerid]);


				}
				case FISH_MODELS_GORBUSHA:
				{

					PlayerTextDrawSetString(playerid, fish_panel_final[0][playerid], "brilliantother:fish_background_effect_1");
					PlayerTextDrawShow(playerid, fish_panel_final[0][playerid]);
					PlayerTextDrawSetString(playerid, fish_panel_final[1][playerid], "brilliantother:fish_panel_final_2");
					PlayerTextDrawShow(playerid, fish_panel_final[1][playerid]);

					PlayerTextDrawShow(playerid, fish_panel_final[2][playerid]);
					PlayerTextDrawShow(playerid, fish_panel_final[3][playerid]);

					update_count_fish_statistic(playerid, 1, FISH_MODELS_GORBUSHA);

					format(fmt_str, sizeof(fmt_str), "%d", fish_count_player[playerid][1]);
					PlayerTextDrawSetString(playerid, fish_panel_final[4][playerid], fmt_str);
					PlayerTextDrawShow(playerid, fish_panel_final[4][playerid]);

				}	
				case FISH_MODELS_SAZAN:	
				{
					PlayerTextDrawSetString(playerid, fish_panel_final[0][playerid], "brilliantother:fish_background_effect_1");
					PlayerTextDrawShow(playerid, fish_panel_final[0][playerid]);
					PlayerTextDrawSetString(playerid, fish_panel_final[1][playerid], "brilliantother:fish_panel_final_3");
					PlayerTextDrawShow(playerid, fish_panel_final[1][playerid]);

					PlayerTextDrawShow(playerid, fish_panel_final[2][playerid]);
					PlayerTextDrawShow(playerid, fish_panel_final[3][playerid]);	

					update_count_fish_statistic(playerid, 1, FISH_MODELS_SAZAN);

					format(fmt_str, sizeof(fmt_str), "%d", fish_count_player[playerid][2]);
					PlayerTextDrawSetString(playerid, fish_panel_final[4][playerid], fmt_str);
					PlayerTextDrawShow(playerid, fish_panel_final[4][playerid]);

				}
				case FISH_MODELS_SOM:
				{
					PlayerTextDrawSetString(playerid, fish_panel_final[0][playerid], "brilliantother:fish_background_effect_1");
					PlayerTextDrawShow(playerid, fish_panel_final[0][playerid]);
					PlayerTextDrawSetString(playerid, fish_panel_final[1][playerid], "brilliantother:fish_panel_final_4");
					PlayerTextDrawShow(playerid, fish_panel_final[1][playerid]);

					PlayerTextDrawShow(playerid, fish_panel_final[2][playerid]);
					PlayerTextDrawShow(playerid, fish_panel_final[3][playerid]);

					update_count_fish_statistic(playerid, 1, FISH_MODELS_SOM);	

					format(fmt_str, sizeof(fmt_str), "%d", fish_count_player[playerid][3]);
					PlayerTextDrawSetString(playerid, fish_panel_final[4][playerid], fmt_str);
					PlayerTextDrawShow(playerid, fish_panel_final[4][playerid]);

				}		
				case FISH_MODELS_TRESKA:
				{
					format(fmt_str, sizeof(fmt_str), "%d", fish_count_player[playerid][4]);
					PlayerTextDrawSetString(playerid, fish_panel_final[4][playerid], fmt_str);
					PlayerTextDrawShow(playerid, fish_panel_final[4][playerid]);

					PlayerTextDrawSetString(playerid, fish_panel_final[0][playerid], "brilliantother:fish_background_effect_1");
					PlayerTextDrawShow(playerid, fish_panel_final[0][playerid]);
					PlayerTextDrawSetString(playerid, fish_panel_final[1][playerid], "brilliantother:fish_panel_final_5");
					PlayerTextDrawShow(playerid, fish_panel_final[1][playerid]);

					PlayerTextDrawShow(playerid, fish_panel_final[2][playerid]);
					PlayerTextDrawShow(playerid, fish_panel_final[3][playerid]);	

					update_count_fish_statistic(playerid, 1, FISH_MODELS_TRESKA);	
				}
				case FISH_MODELS_TUNEC:
				{	
					format(fmt_str, sizeof(fmt_str), "%d", fish_count_player[playerid][5]);
					PlayerTextDrawSetString(playerid, fish_panel_final[4][playerid], fmt_str);
					PlayerTextDrawShow(playerid, fish_panel_final[4][playerid]);

					PlayerTextDrawSetString(playerid, fish_panel_final[0][playerid], "brilliantother:fish_background_effect_2");
					PlayerTextDrawShow(playerid, fish_panel_final[0][playerid]);
					PlayerTextDrawSetString(playerid, fish_panel_final[1][playerid], "brilliantother:fish_panel_final_6");
					PlayerTextDrawShow(playerid, fish_panel_final[1][playerid]);

					PlayerTextDrawShow(playerid, fish_panel_final[2][playerid]);
					PlayerTextDrawShow(playerid, fish_panel_final[3][playerid]);

					update_count_fish_statistic(playerid, 1, FISH_MODELS_TUNEC);		
				}
				case FISH_MODELS_SUDAK:
				{
					format(fmt_str, sizeof(fmt_str), "%d", fish_count_player[playerid][6]);
					PlayerTextDrawSetString(playerid, fish_panel_final[4][playerid], fmt_str);
					PlayerTextDrawShow(playerid, fish_panel_final[4][playerid]);

					PlayerTextDrawSetString(playerid, fish_panel_final[0][playerid], "brilliantother:fish_background_effect_2");
					PlayerTextDrawShow(playerid, fish_panel_final[0][playerid]);
					PlayerTextDrawSetString(playerid, fish_panel_final[1][playerid], "brilliantother:fish_panel_final_7");
					PlayerTextDrawShow(playerid, fish_panel_final[1][playerid]);

					PlayerTextDrawShow(playerid, fish_panel_final[2][playerid]);
					PlayerTextDrawShow(playerid, fish_panel_final[3][playerid]);	

					update_count_fish_statistic(playerid, 1, FISH_MODELS_SUDAK);
				}
				case FISH_MODELS_SEMGA:
				{
					format(fmt_str, sizeof(fmt_str), "%d", fish_count_player[playerid][7]);
					PlayerTextDrawSetString(playerid, fish_panel_final[4][playerid], fmt_str);
					PlayerTextDrawShow(playerid, fish_panel_final[4][playerid]);

					PlayerTextDrawSetString(playerid, fish_panel_final[0][playerid], "brilliantother:fish_background_effect_2");
					PlayerTextDrawShow(playerid, fish_panel_final[0][playerid]);
					PlayerTextDrawSetString(playerid, fish_panel_final[1][playerid], "brilliantother:fish_panel_final_8");
					PlayerTextDrawShow(playerid, fish_panel_final[1][playerid]);

					PlayerTextDrawShow(playerid, fish_panel_final[2][playerid]);
					PlayerTextDrawShow(playerid, fish_panel_final[3][playerid]);

					update_count_fish_statistic(playerid, 1, FISH_MODELS_SEMGA);	
				}
				case FISH_MODELS_SKUMBRIA:
				{
					format(fmt_str, sizeof(fmt_str), "%d", fish_count_player[playerid][8]);
					PlayerTextDrawSetString(playerid, fish_panel_final[4][playerid], fmt_str);
					PlayerTextDrawShow(playerid, fish_panel_final[4][playerid]);

					PlayerTextDrawSetString(playerid, fish_panel_final[0][playerid], "brilliantother:fish_background_effect_2");
					PlayerTextDrawShow(playerid, fish_panel_final[0][playerid]);
					PlayerTextDrawSetString(playerid, fish_panel_final[1][playerid], "brilliantother:fish_panel_final_9");
					PlayerTextDrawShow(playerid, fish_panel_final[1][playerid]);

					PlayerTextDrawShow(playerid, fish_panel_final[2][playerid]);
					PlayerTextDrawShow(playerid, fish_panel_final[3][playerid]);

					update_count_fish_statistic(playerid, 1, FISH_MODELS_SKUMBRIA);	
				}
				case FISH_MODELS_LEH:
				{
					format(fmt_str, sizeof(fmt_str), "%d", fish_count_player[playerid][9]);
					PlayerTextDrawSetString(playerid, fish_panel_final[4][playerid], fmt_str);
					PlayerTextDrawShow(playerid, fish_panel_final[4][playerid]);

					PlayerTextDrawSetString(playerid, fish_panel_final[0][playerid], "brilliantother:fish_background_effect_2");
					PlayerTextDrawShow(playerid, fish_panel_final[0][playerid]);
					PlayerTextDrawSetString(playerid, fish_panel_final[1][playerid], "brilliantother:fish_panel_final_10");
					PlayerTextDrawShow(playerid, fish_panel_final[1][playerid]);

					PlayerTextDrawShow(playerid, fish_panel_final[2][playerid]);
					PlayerTextDrawShow(playerid, fish_panel_final[3][playerid]);

					update_count_fish_statistic(playerid, 1, FISH_MODELS_LEH);	
				}		
				case FISH_MODELS_SHUKA:
				{
					format(fmt_str, sizeof(fmt_str), "%d", fish_count_player[playerid][10]);
					PlayerTextDrawSetString(playerid, fish_panel_final[4][playerid], fmt_str);
					PlayerTextDrawShow(playerid, fish_panel_final[4][playerid]);

					PlayerTextDrawSetString(playerid, fish_panel_final[0][playerid], "brilliantother:fish_background_effect_3");
					PlayerTextDrawShow(playerid, fish_panel_final[0][playerid]);
					PlayerTextDrawSetString(playerid, fish_panel_final[1][playerid], "brilliantother:fish_panel_final_11");
					PlayerTextDrawShow(playerid, fish_panel_final[1][playerid]);

					PlayerTextDrawShow(playerid, fish_panel_final[2][playerid]);
					PlayerTextDrawShow(playerid, fish_panel_final[3][playerid]);	

					update_count_fish_statistic(playerid, 1, FISH_MODELS_SHUKA);	
				}
				case FISH_MODELS_FOREL:
				{
					format(fmt_str, sizeof(fmt_str), "%d", fish_count_player[playerid][11]);
					PlayerTextDrawSetString(playerid, fish_panel_final[4][playerid], fmt_str);
					PlayerTextDrawShow(playerid, fish_panel_final[4][playerid]);

					PlayerTextDrawSetString(playerid, fish_panel_final[0][playerid], "brilliantother:fish_background_effect_3");
					PlayerTextDrawShow(playerid, fish_panel_final[0][playerid]);
					PlayerTextDrawSetString(playerid, fish_panel_final[1][playerid], "brilliantother:fish_panel_final_12");
					PlayerTextDrawShow(playerid, fish_panel_final[1][playerid]);

					PlayerTextDrawShow(playerid, fish_panel_final[2][playerid]);
					PlayerTextDrawShow(playerid, fish_panel_final[3][playerid]);

					update_count_fish_statistic(playerid, 1, FISH_MODELS_FOREL);
				}	
				case FISH_MODELS_PLOTVA:
				{
					format(fmt_str, sizeof(fmt_str), "%d", fish_count_player[playerid][12]);
					PlayerTextDrawSetString(playerid, fish_panel_final[4][playerid], fmt_str);
					PlayerTextDrawShow(playerid, fish_panel_final[4][playerid]);

					PlayerTextDrawSetString(playerid, fish_panel_final[0][playerid], "brilliantother:fish_background_effect_3");
					PlayerTextDrawShow(playerid, fish_panel_final[0][playerid]);
					PlayerTextDrawSetString(playerid, fish_panel_final[1][playerid], "brilliantother:fish_panel_final_13");
					PlayerTextDrawShow(playerid, fish_panel_final[1][playerid]);

					PlayerTextDrawShow(playerid, fish_panel_final[2][playerid]);
					PlayerTextDrawShow(playerid, fish_panel_final[3][playerid]);

					update_count_fish_statistic(playerid, 1, FISH_MODELS_PLOTVA);
				}	
				case FISH_MODELS_LAKENDRA:
				{	
					format(fmt_str, sizeof(fmt_str), "%d", fish_count_player[playerid][13]);
					PlayerTextDrawSetString(playerid, fish_panel_final[4][playerid], fmt_str);
					PlayerTextDrawShow(playerid, fish_panel_final[4][playerid]);

					PlayerTextDrawSetString(playerid, fish_panel_final[0][playerid], "brilliantother:fish_background_effect_3");
					PlayerTextDrawShow(playerid, fish_panel_final[0][playerid]);
					PlayerTextDrawSetString(playerid, fish_panel_final[1][playerid], "brilliantother:fish_panel_final_14");
					PlayerTextDrawShow(playerid, fish_panel_final[1][playerid]);

					PlayerTextDrawShow(playerid, fish_panel_final[2][playerid]);
					PlayerTextDrawShow(playerid, fish_panel_final[3][playerid]);	

					update_count_fish_statistic(playerid, 1, FISH_MODELS_LAKENDRA);
				}	
				case FISH_MODELS_MAKREL:
				{
					format(fmt_str, sizeof(fmt_str), "%d", fish_count_player[playerid][14]);
					PlayerTextDrawSetString(playerid, fish_panel_final[4][playerid], fmt_str);
					PlayerTextDrawShow(playerid, fish_panel_final[4][playerid]);

					PlayerTextDrawSetString(playerid, fish_panel_final[0][playerid], "brilliantother:fish_background_effect_3");
					PlayerTextDrawShow(playerid, fish_panel_final[0][playerid]);
					PlayerTextDrawSetString(playerid, fish_panel_final[1][playerid], "brilliantother:fish_panel_final_15");
					PlayerTextDrawShow(playerid, fish_panel_final[1][playerid]);

					PlayerTextDrawShow(playerid, fish_panel_final[2][playerid]);
					PlayerTextDrawShow(playerid, fish_panel_final[3][playerid]);

					update_count_fish_statistic(playerid, 1, FISH_MODELS_MAKREL);	
				}	
			}

			SelectTextDraw(playerid, COLOR_BLUE);
		}
		case TEXTDRAW_HIDE:
		{	
			PlayerTextDrawHideEx(playerid, fish_panel_final[0][playerid]);
			PlayerTextDrawHideEx(playerid, fish_panel_final[1][playerid]);
			PlayerTextDrawHideEx(playerid, fish_panel_final[2][playerid]);
			PlayerTextDrawHideEx(playerid, fish_panel_final[3][playerid]);			
			PlayerTextDrawHideEx(playerid, fish_panel_final[4][playerid]);
			CancelSelectTextDraw(playerid);			
		}
	}	

	return true;
}

stock check_status_button_fish(playerid, status)	// Проверка статуса и действие при ловле
{
	switch(status)
	{
		case FISH_STATUS_NO_START:
		{
			PlayerTextDrawSetString(playerid, fish_p_general[2][playerid], "brilliantother:fish_button_start");
			PlayerTextDrawShow(playerid, fish_p_general[2][playerid]);
			fish_select_working(playerid);
			generate_fish_player(playerid);
			ApplyAnimation(playerid,"SWORD","SWORD_3",4.1, 0, 1, 1, 1, 0, 1);

			SetPVarIntNew(playerid, "fish_status_player", FISH_STATUS_START_FISHING);
		}
		case FISH_STATUS_START_FISHING:
		{
			PlayerTextDrawSetString(playerid, fish_p_general[2][playerid], "brilliantother:fish_button_pre_final");
			PlayerTextDrawShow(playerid, fish_p_general[2][playerid]);
			fish_select_working(playerid);
			ApplyAnimation(playerid,"SWORD","SWORD_3",4.1, 0, 1, 1, 1, 0, 1);

			
		}
		case FISH_STATUS_START_PREFINAL:
		{
			PlayerTextDrawSetString(playerid, fish_p_general[2][playerid], "brilliantother:fish_button_final");
			PlayerTextDrawShow(playerid, fish_p_general[2][playerid]);
			ApplyAnimation(playerid,"SWORD","SWORD_3",4.1, 0, 1, 1, 1, 0, 1);
			fish_select_working(playerid);
			generate_setka_position_td(playerid);
			show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_RIGHT, "brilliantother:notify_player_work_35", 4000);
			
		}
		case FISH_STATUS_FINAL:
		{
			fish_panel_general_panel(playerid, TEXTDRAW_HIDE);	
			fish_card_prefinal(playerid, TEXTDRAW_SHOW);
		}
	}
	return true;
}

stock generate_fish_player(playerid)
{
	switch(random(100))
	{
		case 0..2:
		{
			switch(random(40))
			{
				case 0..10: fish_active_player[playerid] = FISH_MODELS_SHUKA;
				case 11..15: fish_active_player[playerid] = FISH_MODELS_FOREL;
				case 16..20: fish_active_player[playerid] = FISH_MODELS_PLOTVA;
				case 21..30: fish_active_player[playerid] = FISH_MODELS_LAKENDRA;
				case 31..40: fish_active_player[playerid] = FISH_MODELS_MAKREL;
			}
			
		}
		case 3..25:
		{
			switch(random(40))
			{
				case 0..10: fish_active_player[playerid] = FISH_MODELS_LOSOS;
				case 11..15: fish_active_player[playerid] = FISH_MODELS_FOREL;
				case 16..20: fish_active_player[playerid] = FISH_MODELS_SAZAN;
				case 21..30: fish_active_player[playerid] = FISH_MODELS_SOM;
				case 31..40: fish_active_player[playerid] = FISH_MODELS_TRESKA;
			}			
		}
		case 26..50:
		{
			switch(random(40))
			{
				case 0..10: fish_active_player[playerid] = FISH_MODELS_LOSOS;
				case 11..15: fish_active_player[playerid] = FISH_MODELS_FOREL;
				case 16..20: fish_active_player[playerid] = FISH_MODELS_SAZAN;
				case 21..30: fish_active_player[playerid] = FISH_MODELS_SOM;
				case 31..40: fish_active_player[playerid] = FISH_MODELS_TRESKA;
			}			
		}
		case 51..75:
		{
			switch(random(40))
			{
				case 0..10: fish_active_player[playerid] = FISH_MODELS_TUNEC;
				case 11..15: fish_active_player[playerid] = FISH_MODELS_SUDAK;
				case 16..20: fish_active_player[playerid] = FISH_MODELS_SEMGA;
				case 21..30: fish_active_player[playerid] = FISH_MODELS_SKUMBRIA;
				case 31..40: fish_active_player[playerid] = FISH_MODELS_LEH;
			}			
		}
		case 76..97:
		{
			switch(random(40))
			{
				case 0..10: fish_active_player[playerid] = FISH_MODELS_LOSOS;
				case 11..15: fish_active_player[playerid] = FISH_MODELS_FOREL;
				case 16..20: fish_active_player[playerid] = FISH_MODELS_SAZAN;
				case 21..30: fish_active_player[playerid] = FISH_MODELS_SOM;
				case 31..40: fish_active_player[playerid] = FISH_MODELS_TRESKA;
			}			
		}
		case 98..100:
		{
			switch(random(40))
			{
				case 0..10: fish_active_player[playerid] = FISH_MODELS_SHUKA;
				case 11..15: fish_active_player[playerid] = FISH_MODELS_FOREL;
				case 16..20: fish_active_player[playerid] = FISH_MODELS_PLOTVA;
				case 21..30: fish_active_player[playerid] = FISH_MODELS_LAKENDRA;
				case 31..40: fish_active_player[playerid] = FISH_MODELS_MAKREL;
			}
			
		}
	}
	generate_fish_position_td(playerid);

	return true;
}

stock generate_fish_position_td(playerid)
{


	static const Float: fish_point_position[][] =
	{
	    {162.666656, 150.162963},
	    {91.333320, 212.800018},
	    {262.666656, 268.800048},
	    {318.666656, 156.800018},
	    {438.666687, 261.748199},
	    {453.000000, 136.059326},
	    {261.999969, 89.185249},
	    {69.666641, 94.992630},
	    {6.999972, 180.444488},
	    {27.999971, 288.711212},
	    {149.999969, 269.629699},
	    {244.333312, 205.333419},
	    {401.333312, 204.088973},
	    {351.999969, 307.792694},
	    {513.666625, 194.133407},
	    {382.666625, 101.629684}
	};

	PlayerTextDrawHideEx(playerid, fish_p_general[1][playerid]);

	new 
		rand = random(sizeof fish_point_position);

	if(fish_p_general[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_p_general[1][playerid] = CreatePlayerTextDraw(playerid, fish_point_position[rand][0], fish_point_position[rand][1], "brilliantother:wood_job_click"); // Texture element
		PlayerTextDrawLetterSize(playerid, fish_p_general[1][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, fish_p_general[1][playerid], 119.333343, 90.429672);
		PlayerTextDrawAlignment(playerid, fish_p_general[1][playerid], 2);
		PlayerTextDrawColor(playerid, fish_p_general[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_p_general[1][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_p_general[1][playerid], 0);
		PlayerTextDrawFont(playerid, fish_p_general[1][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, fish_p_general[1][playerid], true);

		new 
			fmt_str[144];

		format(fmt_str, sizeof(fmt_str), "%s", get_fish_name_textdraw(fish_active_player[playerid]));
		PlayerTextDrawSetString(playerid, fish_p_general[1][playerid], fmt_str);

	}
	PlayerTextDrawShow(playerid, fish_p_general[1][playerid]);
	ApplyAnimation(playerid,"SWORD","SWORD_3",4.1, 0, 1, 1, 1, 0, 1);
	return true;
}

stock generate_setka_position_td(playerid)
{


	static const Float: fish_point_position[][] =
	{
	    {162.666656, 150.162963},
	    {91.333320, 212.800018},
	    {262.666656, 268.800048},
	    {318.666656, 156.800018},
	    {438.666687, 261.748199},
	    {453.000000, 136.059326},
	    {261.999969, 89.185249},
	    {69.666641, 94.992630},
	    {6.999972, 180.444488},
	    {27.999971, 288.711212},
	    {149.999969, 269.629699},
	    {244.333312, 205.333419},
	    {401.333312, 204.088973},
	    {351.999969, 307.792694},
	    {513.666625, 194.133407},
	    {382.666625, 101.629684}
	};

	new 
		rand = random(sizeof fish_point_position);

	PlayerTextDrawHideEx(playerid, fish_p_general[1][playerid]);

	if(fish_p_general[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_p_general[1][playerid] = CreatePlayerTextDraw(playerid, fish_point_position[rand][0], fish_point_position[rand][1], "brilliantother:fish_setka"); // Texture element
		PlayerTextDrawLetterSize(playerid, fish_p_general[1][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, fish_p_general[1][playerid], 119.333343, 90.429672);
		PlayerTextDrawAlignment(playerid, fish_p_general[1][playerid], 2);
		PlayerTextDrawColor(playerid, fish_p_general[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_p_general[1][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_p_general[1][playerid], 0);
		PlayerTextDrawFont(playerid, fish_p_general[1][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, fish_p_general[1][playerid], true);

	}
	PlayerTextDrawShow(playerid, fish_p_general[1][playerid]);
	ApplyAnimation(playerid,"SWORD","SWORD_3",4.1, 0, 1, 1, 1, 0, 1);
	return true;
}

stock click_random_point_fish(playerid)
{
	if(GetPVarIntNew(playerid, "fish_work_progress") < GetPVarIntNew(playerid, "count_point_work_fish_all")) 
	{

		SetPVarIntNew(playerid,"fish_work_progress",GetPVarIntNew(playerid,"fish_work_progress")+1);

		if(GetPVarIntNew(playerid, "fish_work_progress") == 5)
		{
			PlayerTextDrawSetString(playerid, fish_p_general[0][playerid], "brilliantother:fish_progress_bar_1");
			PlayerTextDrawShow(playerid, fish_p_general[0][playerid]);
		}
		if(GetPVarIntNew(playerid, "fish_work_progress") == 10)
		{
			PlayerTextDrawSetString(playerid, fish_p_general[0][playerid], "brilliantother:fish_progress_bar_2");
			PlayerTextDrawShow(playerid, fish_p_general[0][playerid]);
		}
		if(GetPVarIntNew(playerid, "fish_work_progress") >= 14)
		{
			PlayerTextDrawSetString(playerid, fish_p_general[0][playerid], "brilliantother:fish_progress_bar_3");
			PlayerTextDrawShow(playerid, fish_p_general[0][playerid]);
		}

		if(GetPVarIntNew(playerid, "fish_status_player") == FISH_STATUS_START_FISHING)
		{
			fish_point_textdraw(playerid, TEXTDRAW_HIDE);
			fish_point_textdraw(playerid, TEXTDRAW_SHOW);
		}
		else if(GetPVarIntNew(playerid, "fish_status_player") == FISH_STATUS_START_PREFINAL)
		{
			setka_point_textdraw(playerid, TEXTDRAW_HIDE);
			setka_point_textdraw(playerid, TEXTDRAW_SHOW);
		}
	}
	else 
	{
		if(GetPVarIntNew(playerid, "fish_status_player") == FISH_STATUS_START_FISHING)
		{
			SetPVarIntNew(playerid,"fish_status_player", FISH_STATUS_START_PREFINAL);
			check_status_button_fish(playerid, FISH_STATUS_START_PREFINAL);

			PlayerTextDrawSetString(playerid, fish_p_general[0][playerid], "brilliantother:fish_progress_bar_0");
			PlayerTextDrawShow(playerid, fish_p_general[0][playerid]);

			fish_point_textdraw(playerid, TEXTDRAW_HIDE);

			
		}
		else if(GetPVarIntNew(playerid, "fish_status_player") == FISH_STATUS_START_PREFINAL)
		{
			SetPVarIntNew(playerid,"fish_status_player", FISH_STATUS_FINAL);
			check_status_button_fish(playerid, FISH_STATUS_FINAL);

			PlayerTextDrawSetString(playerid, fish_p_general[0][playerid], "brilliantother:fish_progress_bar_0");
			PlayerTextDrawShow(playerid, fish_p_general[0][playerid]);

			

		}

		DeletePVarNew(playerid, "count_point_work_fish_all");
		DeletePVarNew(playerid, "fish_work_progress");
	}

    return true;
}

stock fish_point_textdraw(playerid, action)
{
	switch(action)
	{
		case TEXTDRAW_SHOW:
		{
			generate_fish_position_td(playerid);
			SelectTextDraw(playerid, COLOR_BLUE);		
		}
		case TEXTDRAW_HIDE:
		{
			PlayerTextDrawHideEx(playerid, fish_p_general[1][playerid]);
		}
	}
	return true;
}

stock setka_point_textdraw(playerid, action)
{
	switch(action)
	{
		case TEXTDRAW_SHOW:
		{
			generate_setka_position_td(playerid);
			SelectTextDraw(playerid, COLOR_BLUE);		
		}
		case TEXTDRAW_HIDE:
		{
			PlayerTextDrawHideEx(playerid, fish_p_general[1][playerid]);
		}
	}
	return true;
}

stock fish_select_working(playerid)
{

	new 
		count_point;

	count_point = 15;

	SetPVarIntNew(playerid, "count_point_work_fish_all", count_point);
	TogglePlayerControllable(playerid, false);

	return true;
}

stock final_give_fish_player(playerid)
{

	give_fish_inventory_player(playerid, fish_active_player[playerid], 1);

	fish_car_open_panel(playerid, TEXTDRAW_HIDE, 0);
	fish_panel_general_panel(playerid, TEXTDRAW_SHOW);
	clear_fish_pvar(playerid);
	SetPVarIntNew(playerid, "fish_status_player", FISH_STATUS_NO_START);
	return true;
}

stock outpout_fish_player(playerid)
{
	add_player_job_skill(playerid, SKILL_FISHER, RandomEx(1, 2));
	
	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_RIGHT, "brilliantother:notify_player_work_36", 4000);

	fish_car_open_panel(playerid, TEXTDRAW_HIDE, 0);
	fish_panel_general_panel(playerid, TEXTDRAW_SHOW);
	clear_fish_pvar(playerid);
	SetPVarIntNew(playerid, "fish_status_player", FISH_STATUS_NO_START);
	return true;
}

stock give_fish_inventory_player(playerid, type_fish, count_fish)
{	
	add_player_job_skill(playerid, SKILL_FISHER, RandomEx(1, 2));

	format(String144, sizeof(String144), "Рыба '%s' была добавлена Вам в инвентарь в количестве %d штук (( /inv ))", get_fish_name(type_fish), count_fish);
	SendSucc(playerid, String144);
	SetPVarIntNew(playerid, "fish_status_player", FISH_STATUS_NO_START);
	switch(type_fish)
	{

		case FISH_MODELS_LOSOS:	
		{
			give_inventory_items(playerid, 358, count_fish);	
		}
		case FISH_MODELS_GORBUSHA:
		{
			give_inventory_items(playerid, 359, count_fish);
		}	
		case FISH_MODELS_SAZAN:	
		{
			give_inventory_items(playerid, 360, count_fish);	
		}
		case FISH_MODELS_SOM:
		{
			give_inventory_items(playerid, 361, count_fish);	
		}		
		case FISH_MODELS_TRESKA:
		{
			give_inventory_items(playerid, 362, count_fish);	
		}
		case FISH_MODELS_TUNEC:
		{	
			give_inventory_items(playerid, 363, count_fish);	
		}
		case FISH_MODELS_SUDAK:
		{
			give_inventory_items(playerid, 364, count_fish);	
		}
		case FISH_MODELS_SEMGA:
		{
			give_inventory_items(playerid, 365, count_fish);	
		}
		case FISH_MODELS_SKUMBRIA:
		{
			give_inventory_items(playerid, 366, count_fish);	
		}
		case FISH_MODELS_LEH:
		{
			give_inventory_items(playerid, 367, count_fish);	
		}		
		case FISH_MODELS_SHUKA:
		{
			give_inventory_items(playerid, 368, count_fish);	
		}
		case FISH_MODELS_FOREL:
		{
			give_inventory_items(playerid, 369, count_fish);	
		}	
		case FISH_MODELS_PLOTVA:
		{
			give_inventory_items(playerid, 370, count_fish);	
		}	
		case FISH_MODELS_LAKENDRA:
		{	
			give_inventory_items(playerid, 371, count_fish);	
		}	
		case FISH_MODELS_MAKREL:
		{
			give_inventory_items(playerid, 372, count_fish);	
		}	
	}	


	return true;
}

stock update_count_fish_statistic(playerid, count_update, type_fish)
{

	format(String144, sizeof(String144), "В вашу статистику по ловле рыб добавлен улов рыбы %s в количестве %d штук!", get_fish_name(type_fish), count_update);
	SendSucc(playerid, String144);
	SetPVarIntNew(playerid, "fish_status_player", FISH_STATUS_NO_START);
	switch(type_fish)
	{
		case FISH_MODELS_LOSOS:	
		{
			fish_count_player[playerid][0] += count_update;
		}
		case FISH_MODELS_GORBUSHA:
		{
			fish_count_player[playerid][1] += count_update;
		}	
		case FISH_MODELS_SAZAN:	
		{
			fish_count_player[playerid][2] += count_update;
		}
		case FISH_MODELS_SOM:
		{
			fish_count_player[playerid][3] += count_update;
		}		
		case FISH_MODELS_TRESKA:
		{
			fish_count_player[playerid][4] += count_update;
		}
		case FISH_MODELS_TUNEC:
		{	
			fish_count_player[playerid][5] += count_update;
		}
		case FISH_MODELS_SUDAK:
		{
			fish_count_player[playerid][6] += count_update;
		}
		case FISH_MODELS_SEMGA:
		{
			fish_count_player[playerid][7] += count_update;
		}
		case FISH_MODELS_SKUMBRIA:
		{
			fish_count_player[playerid][8] += count_update;
		}
		case FISH_MODELS_LEH:
		{
			fish_count_player[playerid][9] += count_update;
		}		
		case FISH_MODELS_SHUKA:
		{
			fish_count_player[playerid][10] += count_update;
		}
		case FISH_MODELS_FOREL:
		{
			fish_count_player[playerid][11] += count_update;
		}	
		case FISH_MODELS_PLOTVA:
		{
			fish_count_player[playerid][12] += count_update;
		}	
		case FISH_MODELS_LAKENDRA:
		{
			fish_count_player[playerid][13] += count_update;
		}
		case FISH_MODELS_MAKREL:
		{
			fish_count_player[playerid][14] += count_update;
		}	

	}

	return true;
}

callback:: load_player_fish_statistic(playerid)
{
	new 
		time = GetTickCount();

	format(String1024, sizeof(String1024), "SELECT * FROM `fish_player_all` WHERE `fish_table_user` = '%d'", pData[playerid][pMysqlID]);
	new Result:fish_player_alls = sql_queryEx(zConn, String1024, QUERY_CACHED);

	if(sql_num_rows(fish_player_alls)) 
	{
		sql_get_field_assoc_ex(fish_player_alls, 0, "fish_count", String512, MAX_FISH_OBJECT * 15);
		sscanf(String512, "p<,>ddddddddddddddd", fish_count_player[playerid][0], fish_count_player[playerid][1], fish_count_player[playerid][2], fish_count_player[playerid][3],
	    fish_count_player[playerid][4], fish_count_player[playerid][5], fish_count_player[playerid][6], fish_count_player[playerid][7], fish_count_player[playerid][8],
	    fish_count_player[playerid][9], fish_count_player[playerid][10], fish_count_player[playerid][11], fish_count_player[playerid][12], fish_count_player[playerid][13],
	    fish_count_player[playerid][14]);
 
	}
	else
	{
	    format(String144, sizeof(String144), "INSERT INTO fish_player_all(fish_table_user, fish_count) VALUES ('%d', '%d')",
	    pData[playerid][pMysqlID], 0);
	    sql_queryEx(zConn, String144, QUERY_THREADED);		
	}
	sql_free_result(fish_player_alls);

	printf("[Загрузка списка рыбы] Аккаунт: %s[%d] | Времени затрачено: <%d мс>",pData[playerid][pNickname], pData[playerid][pMysqlID], GetTickCount() - time);

	return true;
}

stock clear_fish_pvar(playerid)
{

	fish_active_player[playerid] = -1;

	DeletePVarNew(playerid, "fish_status_player");
	DeletePVarNew(playerid, "count_point_work_fish_all");
	DeletePVarNew(playerid, "fish_work_progress");
	return true;
}

stock generate_price_fish_payday()
{
	fish_price_player[0] = RandomEx(250, 500);
	fish_price_player[1] = RandomEx(250, 500);
	fish_price_player[2] = RandomEx(250, 500);
	fish_price_player[3] = RandomEx(250, 500);
	fish_price_player[4] = RandomEx(250, 500);
	fish_price_player[5] = RandomEx(350, 900);
	fish_price_player[6] = RandomEx(350, 900);
	fish_price_player[7] = RandomEx(350, 900);
	fish_price_player[8] = RandomEx(350, 900);
	fish_price_player[9] = RandomEx(350, 900);
	fish_price_player[10] = RandomEx(550, 1200);
	fish_price_player[11] = RandomEx(550, 1200);
	fish_price_player[12] = RandomEx(550, 1200);
	fish_price_player[13] = RandomEx(550, 1200);
	fish_price_player[14] = RandomEx(550, 1200);
}


