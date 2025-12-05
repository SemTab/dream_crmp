
stock get_weapon_name_magazin(type)
{
	new 
		name[40];

	switch(type)
	{
		case 1: name = "KACЏEЏ";
		case 2: name = "Ђ…ЏA";
		case 3: name = "ѓpo—oўњk";
		case 4: name = "DEAGLE";
		case 5: name = "MP5";
		case 6: name = "AK47";
		case 7: name = "‹њ®¦oўka";
		case 8: name = "M4A1";

		default: name = "Неизвестно";
	}
	return name;
}
 

stock show_ammo_menu_magazin(playerid, status)
{
	switch(status) 
	{
		case TEXTDRAW_SHOW:
		{
			show_info_gui(playerid, TEXTDRAW_HIDE);
			TogglePlayerAllHudElements(playerid, HUD_ELEMENT_HIDE);
			hide_hud_element(playerid);
			show_player_green_zone(playerid, TEXTDRAW_HIDE);


			create_ammo_menu_biz_p(playerid);

			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[0][playerid]);

			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[1][playerid], "brilliantother:weapon_menu_castet");
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[1][playerid]);
			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[2][playerid], "brilliantother:weapon_menu_bita");
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[2][playerid]);
			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[3][playerid], "brilliantother:weapon_menu_drop");
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[3][playerid]);
			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[4][playerid], "brilliantother:weapon_menu_deagle");
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[4][playerid]);

			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[7][playerid], "brilliantother:weapon_menu_mp5");
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[7][playerid]);
			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[8][playerid], "brilliantother:weapon_menu_ak47");
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[8][playerid]);


			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[9][playerid], "brilliantother:weapon_menu_vint");
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[9][playerid]);
			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[10][playerid], "brilliantother:weapon_menu_m4a1");
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[10][playerid]);

			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[11][playerid], "brilliantother:weapon_menu_clear");
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[11][playerid]);
			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[12][playerid], "brilliantother:weapon_menu_clear");
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[12][playerid]);
			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[13][playerid], "brilliantother:weapon_menu_clear");
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[13][playerid]);
			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[14][playerid], "brilliantother:weapon_menu_clear");
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[14][playerid]);

			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[5][playerid], "brilliantother:weapon_menu_select_castet");
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[5][playerid]);
			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[19][playerid], "brilliantother:weapon_buy_button");
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[19][playerid]);

			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[15][playerid]);
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[16][playerid]);
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[17][playerid]);	

			format(String64, sizeof(String64), "%s", get_weapon_name_magazin(1));
			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[18][playerid], String64);
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[18][playerid]);

			SetPVarIntNew(playerid, "select_menu_weapon_ammo", 1);

			SelectTextDraw(playerid, COLOR_BLUE);
		}
		case TEXTDRAW_HIDE:
		{
			if(pGreenZone[playerid])
			{
				show_player_green_zone(playerid, TEXTDRAW_SHOW);
			}
			show_hud_element(playerid);
			show_hud_hungry(playerid);

			show_info_gui(playerid, TEXTDRAW_SHOW);
			
			PlayerTextDrawHideEx(playerid, ammo_panel_menu_biz[0][playerid]);
			PlayerTextDrawHideEx(playerid, ammo_panel_menu_biz[1][playerid]);
			PlayerTextDrawHideEx(playerid, ammo_panel_menu_biz[2][playerid]);
			PlayerTextDrawHideEx(playerid, ammo_panel_menu_biz[3][playerid]);
			PlayerTextDrawHideEx(playerid, ammo_panel_menu_biz[4][playerid]);
			PlayerTextDrawHideEx(playerid, ammo_panel_menu_biz[5][playerid]);
			PlayerTextDrawHideEx(playerid, ammo_panel_menu_biz[19][playerid]);
			PlayerTextDrawHideEx(playerid, ammo_panel_menu_biz[7][playerid]);
			PlayerTextDrawHideEx(playerid, ammo_panel_menu_biz[8][playerid]);
			PlayerTextDrawHideEx(playerid, ammo_panel_menu_biz[9][playerid]);
			PlayerTextDrawHideEx(playerid, ammo_panel_menu_biz[10][playerid]);
			PlayerTextDrawHideEx(playerid, ammo_panel_menu_biz[11][playerid]);
			PlayerTextDrawHideEx(playerid, ammo_panel_menu_biz[12][playerid]);
			PlayerTextDrawHideEx(playerid, ammo_panel_menu_biz[13][playerid]);
			PlayerTextDrawHideEx(playerid, ammo_panel_menu_biz[14][playerid]);
			PlayerTextDrawHideEx(playerid, ammo_panel_menu_biz[15][playerid]);
			PlayerTextDrawHideEx(playerid, ammo_panel_menu_biz[16][playerid]);
			PlayerTextDrawHideEx(playerid, ammo_panel_menu_biz[17][playerid]);
			PlayerTextDrawHideEx(playerid, ammo_panel_menu_biz[18][playerid]);
				
			TogglePlayerAllHudElements(playerid, HUD_ELEMENT_SHOW);

			CancelSelectTextDraw(playerid);

		}
	}



	return true;
}

stock click_menu_ammo_magazin(playerid, click_button)
{
	switch(click_button)
	{
		case 1:
		{
			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[5][playerid], "brilliantother:weapon_menu_select_castet");
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[5][playerid]);
			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[19][playerid], "brilliantother:weapon_buy_button");
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[19][playerid]);

			format(String64, sizeof(String64), "%s", get_weapon_name_magazin(1));
			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[18][playerid], String64);
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[18][playerid]);	

			SetPVarIntNew(playerid, "select_menu_weapon_ammo", 1);	

			SelectTextDraw(playerid, COLOR_BLUE);	
		}
		case 2:
		{
			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[5][playerid], "brilliantother:weapon_menu_select_bita");
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[5][playerid]);
			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[19][playerid], "brilliantother:weapon_buy_button");
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[19][playerid]);
			
			format(String64, sizeof(String64), "%s", get_weapon_name_magazin(2));
			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[18][playerid], String64);
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[18][playerid]);

			SetPVarIntNew(playerid, "select_menu_weapon_ammo", 2);	

			SelectTextDraw(playerid, COLOR_BLUE);		
		}

		case 3:
		{
			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[5][playerid], "brilliantother:weapon_menu_select_drop");
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[5][playerid]);
			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[19][playerid], "brilliantother:weapon_buy_button");
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[19][playerid]);
			
			format(String64, sizeof(String64), "%s", get_weapon_name_magazin(3));
			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[18][playerid], String64);
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[18][playerid]);	

			SetPVarIntNew(playerid, "select_menu_weapon_ammo", 3);	

			SelectTextDraw(playerid, COLOR_BLUE);	
		}
		case 4:
		{
			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[5][playerid], "brilliantother:weapon_menu_select_deagle");
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[5][playerid]);
			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[19][playerid], "brilliantother:weapon_buy_button");
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[19][playerid]);
			
			format(String64, sizeof(String64), "%s", get_weapon_name_magazin(4));
			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[18][playerid], String64);
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[18][playerid]);	

			SetPVarIntNew(playerid, "select_menu_weapon_ammo", 4);	

			SelectTextDraw(playerid, COLOR_BLUE);	
		}
		case 5:
		{
			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[5][playerid], "brilliantother:weapon_menu_select_mp9");
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[5][playerid]);
			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[19][playerid], "brilliantother:weapon_buy_button");
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[19][playerid]);
			
			format(String64, sizeof(String64), "%s", get_weapon_name_magazin(5));
			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[18][playerid], String64);
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[18][playerid]);

			SetPVarIntNew(playerid, "select_menu_weapon_ammo", 5);	

			SelectTextDraw(playerid, COLOR_BLUE);		
		}
		case 6:
		{
			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[5][playerid], "brilliantother:weapon_menu_select_ak47");
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[5][playerid]);
			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[19][playerid], "brilliantother:weapon_buy_button");
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[19][playerid]);
			
			format(String64, sizeof(String64), "%s", get_weapon_name_magazin(6));
			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[18][playerid], String64);
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[18][playerid]);

			SetPVarIntNew(playerid, "select_menu_weapon_ammo", 6);

			SelectTextDraw(playerid, COLOR_BLUE);			
		}
		case 7:
		{
			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[5][playerid], "brilliantother:weapon_menu_select_vint");
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[5][playerid]);
			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[19][playerid], "brilliantother:weapon_buy_button");
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[19][playerid]);
			
			format(String64, sizeof(String64), "%s", get_weapon_name_magazin(7));
			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[18][playerid], String64);
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[18][playerid]);	

			SetPVarIntNew(playerid, "select_menu_weapon_ammo", 7);

			SelectTextDraw(playerid, COLOR_BLUE);		
		}
		case 8:
		{
			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[5][playerid], "brilliantother:weapon_menu_select_m4a1");
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[5][playerid]);
			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[19][playerid], "brilliantother:weapon_buy_button");
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[19][playerid]);
			
			format(String64, sizeof(String64), "%s", get_weapon_name_magazin(8));
			PlayerTextDrawSetString(playerid, ammo_panel_menu_biz[18][playerid], String64);
			PlayerTextDrawShow(playerid, ammo_panel_menu_biz[18][playerid]);	

			SetPVarIntNew(playerid, "select_menu_weapon_ammo", 8);	

			SelectTextDraw(playerid, COLOR_BLUE);	
		}
	}


	return true;
}


stock buy_menu_ammo_magazin(playerid)
{
	new 
		type_weapon_select = GetPVarIntNew(playerid, "select_menu_weapon_ammo");

    new 
    	id = pTemp[playerid][pSelectedBusinessID];

 	if(id < 0) 
 		return true;
 
    --type_weapon_select;

	switch(type_weapon_select)
	{
		case 0:
		{
	        new price = 3500;

			if(GetPlayerMoneyEx(playerid) < price) 
				return ShowMenuAmmo(playerid);


			SFCM(playerid, COLOR_WHITE, "• {FFC800}[Подсказка] "cWH"Вы купили кастет за "cGR"%d рублей", price);

			if(buisness[id][buisnes_count_prod] >= price/25)             
			{
				buisness[id][buisnes_count_prod] -= price/25;
				buisness_bank_update(id, price/2, "ammunation");                       
			}

			format(String144, sizeof(String144), "Покупка в аммунации №%d", id);
			give_money(playerid, -price, String144);
			GivePlayerWeaponEx(playerid, 1, 1);

			SelectTextDraw(playerid, COLOR_BLUE);
		}
		case 1:
		{
	        new price = 3500;

			if(GetPlayerMoneyEx(playerid) < price) 
				return ShowMenuAmmo(playerid);


			SFCM(playerid, COLOR_WHITE, "• {FFC800}[Подсказка] "cWH"Вы купили бейсбольную биту за "cGR"%d рублей", price);

			if(buisness[id][buisnes_count_prod] >= price/25)              
			{
				buisness[id][buisnes_count_prod] -= price/25;
				buisness_bank_update(id, price/2, "ammunation");                                 
			}

			format(String144, sizeof(String144), "Покупка в аммунации №%d", id);
			give_money(playerid, -price, String144);
			GivePlayerWeaponEx(playerid, 5, 1);

			SelectTextDraw(playerid, COLOR_BLUE);
		}
		case 2:
		{
			SPD(playerid, dGun1, 1, ""cBLUE"Покупка оружия:", \
				""cWH"Укажите число десятков патронов для Дробовика \n\
				Цена одного патрона - "cGR"140P", "Купить", "Назад");
		}
	    case 3:
	    {
			SPD(playerid, dGun2, 1, ""cBLUE"Покупка оружия:", \
				""cWH"Укажите число обойм Пустынного орла \n\
				Цена одного патрона - "cGR"120P", "Купить", "Назад");
	    }
	    case 4:
	    {
			SPD(playerid, dGun3, 1, ""cBLUE"Покупка оружия:", \
				""cWH"Укажите число патронов Полуавтомата МР5 \n\
				Цена одного патрона - "cGR"60P", "Купить", "Назад");
	    }
	    case 5:
	    {
			SPD(playerid, dGun4, 1, ""cBLUE"Покупка оружия:", \
				""cWH"Укажите число обойм Автомата АК47 \n\
				Цена одной обоймы - "cGR"120P", "Купить", "Назад");
	    }
	    case 6:
	    {
			SPD(playerid, dGun5, 1, ""cBLUE"Покупка оружия:", \
				""cWH"Укажите число десятков патронов Винтовки \n\
				Цена одного патрона - "cGR"140P", "Купить", "Назад");
	    }
	    case 7:
	    {
			SPD(playerid, dGun6, 1, ""cBLUE"Покупка оружия:", \
				""cWH"Укажите число обойм Автомата M4 \n\
				Цена одного патрона - "cGR"120P", "Купить", "Назад");
	    }
	}

	return true;
}