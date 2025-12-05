
new 
	temp_magazin_aks_slot_0[MAX_PLAYERS],
	temp_magazin_aks_slot_1[MAX_PLAYERS],
	temp_magazin_aks_slot_2[MAX_PLAYERS];

new all_aks_params_kap[] =
{
	10998,
	10998,
	10999,
	11000,
	11001

};

new all_aks_params_mask[] =
{
	10971,
	10971,
	10973,
	10974,
	10975,
	10976,
	10977,
	10978,
	10979,
	10980,
	10981,
	10982


};

new all_aks_params_back[] =
{
	11002,
	11002,
	11003,
	11004,
	11005,
	11006,
	11007

};


stock get_aks_price(playerid, index) 
{
	new 
		price;

	if(GetPVarIntNew(playerid, "type_select_aks") == 1)
	{
		switch(index)
		{
			case 0: price = 25000;
			case 1: price = 25000;
			case 2: price = 100000;
			case 3: price = 75000;
			case 4: price = 50000;
			default: price = 100000;
		}
		return price;
	}
	else if(GetPVarIntNew(playerid, "type_select_aks") == 2)
	{
		switch(index)
		{
			case 0: price = 50000;
			case 1: price = 50000;
			case 2: price = 25000;
			case 3: price = 150000;
			case 4: price = 500000;
			case 5: price = 350000;
			case 6: price = 300000;
			case 7: price = 800000;
			case 8: price = 1000000;
			case 9: price = 100000;
			case 10: price = 1500000;
			case 11: price = 1500000;
			default: price = 1500000;
		}
		return price;
	}
	else if(GetPVarIntNew(playerid, "type_select_aks") == 3)
	{
		switch(index)
		{
			case 0: price = 25000;
			case 1: price = 25000;
			case 2: price = 100000;
			case 3: price = 100000;
			case 4: price = 50000;
			case 5: price = 50000;
			case 6: price = 50000;
			default: price = 1500000;
		}
		return price;
	}	
	return true;
}

stock get_aks_id(playerid, index) 
{
	if(GetPVarIntNew(playerid, "type_select_aks") == 1)
	{
		return all_aks_params_kap[index];
	}
	else if(GetPVarIntNew(playerid, "type_select_aks") == 2)
	{
		return all_aks_params_mask[index];
	}	
	else if(GetPVarIntNew(playerid, "type_select_aks") == 3)
	{
		return all_aks_params_back[index];
	}
	return true;	
}

stock dialog_show_select_aks(playerid, type)
{


	switch(type)
	{
		case BUISNES_ACCESSORIES:
		{
			SPD(playerid, DIALOG_SELECT_AKS, DIALOG_STYLE_LIST, ""cBLUE"Магазин аксессуаров", \
			""cBLUE"1."cWH" Кепки\n\
			"cBLUE"2."cWH" Маски\n\
			"cBLUE"3."cWH" Рюкзаки", !"Выбрать", !"Закрыть");
		}
	}

	return true;
}

stock start_select_aks_shop(playerid, type_shop, type_aks)
{
	switch(type_shop)
	{
		case BUISNES_ACCESSORIES:
		{
			switch(type_aks)
			{

				case 0:
				{
					SetPlayerVirtualWorld(playerid, playerid+1);
					show_aks_start_1(playerid, 1);
					TogglePlayerControllable(playerid, false);
					textdraw_aks_select(playerid, TEXTDRAW_SHOW, BUISNES_ACCESSORIES);
					SetPVarIntNew(playerid, "type_select_aks", 1);

					TogglePlayerAllHudElements(playerid, HUD_ELEMENT_HIDE);
				}
				case 1:
				{
					SetPlayerVirtualWorld(playerid, playerid+1);
					show_aks_start_1(playerid, 2);
					TogglePlayerControllable(playerid, false);
					textdraw_aks_select(playerid, TEXTDRAW_SHOW, BUISNES_ACCESSORIES);
					SetPVarIntNew(playerid, "type_select_aks", 2);

					TogglePlayerAllHudElements(playerid, HUD_ELEMENT_HIDE);
				}
				case 2:
				{
					SetPlayerVirtualWorld(playerid, playerid+1);
					show_aks_start_1(playerid, 3);
					TogglePlayerControllable(playerid, false);
					SetPVarIntNew(playerid, "type_select_aks_shop", BUISNES_ACCESSORIES);
					SetPVarIntNew(playerid, "type_select_aks", 3);

					TogglePlayerAllHudElements(playerid, HUD_ELEMENT_HIDE);
				}
			}
		}
	}

	return true;
}


stock show_aks_start_1(playerid, type)
{

	switch(type)
	{
		case 1:
		{
			InterpolateCameraPos(playerid, -652.416687, -712.183105, 1202.757324, -649.101318, -713.672790, 1202.706176, 2000);
			InterpolateCameraLookAt(playerid, -651.544372, -717.102661, 1202.565307, -644.281311, -715.002136, 1202.693237, 2000);
			SetPlayerPosEx(playerid, -647.5887,-714.1224,1201.9475,41.0516);
			TogglePlayerControllable(playerid, false);

			aks_select_count[playerid] = 0;

			textdraw_aks_select(playerid, TEXTDRAW_SHOW, BUISNES_ACCESSORIES);
			//textdraw_aks_select(playerid, TEXTDRAW_UPDATE, BUISNES_ACCESSORIES);

			new 
				skin = GetPlayerSkin(playerid);
			temp_magazin_aks_slot_0[playerid] = get_aks_id(playerid, aks_select_count[playerid]);
			AttachAcsToPlayerMagazin(playerid, skin);

		}
		case 2:
		{
			InterpolateCameraPos(playerid, -652.039978, -713.426818, 1202.789794, -648.435974, -713.340148, 1202.606323, 2000);
			InterpolateCameraLookAt(playerid, -650.059997, -718.012939, 1202.572998, -644.792358, -716.763244, 1202.687011, 2000);
			SetPlayerPosEx(playerid, -647.5887,-714.1224,1201.9475,41.0516);
			TogglePlayerControllable(playerid, false);

			aks_select_count[playerid] = 0;

			textdraw_aks_select(playerid, TEXTDRAW_SHOW, BUISNES_ACCESSORIES);
			//textdraw_aks_select(playerid, TEXTDRAW_UPDATE, BUISNES_ACCESSORIES);

			new 
				skin = GetPlayerSkin(playerid);
			temp_magazin_aks_slot_1[playerid] = get_aks_id(playerid, aks_select_count[playerid]);
			AttachAcsToPlayerMagazin(playerid, skin);


		}
		case 3:
		{
			InterpolateCameraPos(playerid, -651.272399, -713.939880, 1202.620117, -647.914855, -715.678222, 1202.529296, 2000);
			InterpolateCameraLookAt(playerid, -648.857849, -718.317626, 1202.692626, -646.380065, -710.934936, 1202.147338, 2000);
			SetPlayerPosEx(playerid, -647.5887,-714.1224,1201.9475,41.0516);
			TogglePlayerControllable(playerid, false);

			aks_select_count[playerid] = 0;

			textdraw_aks_select(playerid, TEXTDRAW_SHOW, BUISNES_ACCESSORIES);
			//textdraw_aks_select(playerid, TEXTDRAW_UPDATE, BUISNES_ACCESSORIES);

			new 
				skin = GetPlayerSkin(playerid);
			temp_magazin_aks_slot_2[playerid] = get_aks_id(playerid, aks_select_count[playerid]);
			AttachAcsToPlayerMagazin(playerid, skin);

		}
	}
				
	for(new i; i<7; i++)
	{
		if(IsPlayerAttachedObjectSlotUsed(playerid, i))
			RemovePlayerAttachedObject(playerid, i);
	}
	return true;
}


stock show_aks_next_1(playerid)
{
	new 
		skin = GetPlayerSkin(playerid);

	if(aks_select_count[playerid] == 3)
		return true;

	SetPVarIntNew(playerid, "selectable_aks_magazin", 1);

	aks_select_count[playerid]++;
	temp_magazin_aks_slot_0[playerid] = get_aks_id(playerid, aks_select_count[playerid]);
	AttachAcsToPlayerMagazin(playerid, skin);
	textdraw_aks_select(playerid, TEXTDRAW_UPDATE, BUISNES_ACCESSORIES);
	return true;
}

stock show_aks_next_2(playerid)
{
	new 
		skin = GetPlayerSkin(playerid);

	if(aks_select_count[playerid] == 10)
		return true;

	SetPVarIntNew(playerid, "selectable_aks_magazin", 1);

	aks_select_count[playerid]++;
	temp_magazin_aks_slot_1[playerid] = get_aks_id(playerid, aks_select_count[playerid]);
	AttachAcsToPlayerMagazin(playerid, skin);
	textdraw_aks_select(playerid, TEXTDRAW_UPDATE, BUISNES_ACCESSORIES);
	return true;
}

stock show_aks_next_3(playerid)
{
	new 
		skin = GetPlayerSkin(playerid);

	if(aks_select_count[playerid] == 5)
		return true;

	SetPVarIntNew(playerid, "selectable_aks_magazin", 1);

	aks_select_count[playerid]++;
	temp_magazin_aks_slot_2[playerid] = get_aks_id(playerid, aks_select_count[playerid]);
	AttachAcsToPlayerMagazin(playerid, skin);
	textdraw_aks_select(playerid, TEXTDRAW_UPDATE, BUISNES_ACCESSORIES);
	return true;
}


stock show_aks_prew_1(playerid)
{

	new 
		skin = GetPlayerSkin(playerid);

	if(aks_select_count[playerid] == 0)
		return true;

	SetPVarIntNew(playerid, "selectable_aks_magazin", 1);

	aks_select_count[playerid]--;
	temp_magazin_aks_slot_0[playerid] = get_aks_id(playerid, aks_select_count[playerid]);
	AttachAcsToPlayerMagazin(playerid, skin);
	textdraw_aks_select(playerid, TEXTDRAW_UPDATE, BUISNES_ACCESSORIES);
	return true;
}


stock show_aks_prew_2(playerid)
{

	new 
		skin = GetPlayerSkin(playerid);

	if(aks_select_count[playerid] == 0)
		return true;

	SetPVarIntNew(playerid, "selectable_aks_magazin", 1);

	aks_select_count[playerid]--;
	temp_magazin_aks_slot_1[playerid] = get_aks_id(playerid, aks_select_count[playerid]);
	AttachAcsToPlayerMagazin(playerid, skin);
	textdraw_aks_select(playerid, TEXTDRAW_UPDATE, BUISNES_ACCESSORIES);
	return true;
}


stock show_aks_prew_3(playerid)
{

	new 
		skin = GetPlayerSkin(playerid);

	if(aks_select_count[playerid] == 0)
		return true;

	SetPVarIntNew(playerid, "selectable_aks_magazin", 1);

	aks_select_count[playerid]--;
	temp_magazin_aks_slot_2[playerid] = get_aks_id(playerid, aks_select_count[playerid]);
	AttachAcsToPlayerMagazin(playerid, skin);
	textdraw_aks_select(playerid, TEXTDRAW_UPDATE, BUISNES_ACCESSORIES);
	return true;
}


stock textdraw_aks_select(playerid, status, type_salon)
{
	
	switch(status)
	{
		case TEXTDRAW_SHOW:
		{
			switch(type_salon)
			{
				case BUISNES_ACCESSORIES:
				{


					TextDrawShowForPlayer(playerid, aks_select_td[0]);
					TextDrawShowForPlayer(playerid, aks_select_td[1]);
					TextDrawShowForPlayer(playerid, aks_select_td[2]);
					TextDrawShowForPlayer(playerid, aks_select_td[3]);
					TextDrawShowForPlayer(playerid, aks_select_td[4]);
					TextDrawShowForPlayer(playerid, aks_select_td[5]);

					create_aks_shop_price(playerid);
				}
			}
			SelectTextDraw(playerid, COLOR_BLUE);


		}
		case TEXTDRAW_HIDE:
		{

			TextDrawHideForPlayer(playerid, aks_select_td[0]);
			TextDrawHideForPlayer(playerid, aks_select_td[1]);
			TextDrawHideForPlayer(playerid, aks_select_td[2]);
			TextDrawHideForPlayer(playerid, aks_select_td[3]);
			TextDrawHideForPlayer(playerid, aks_select_td[4]);
			TextDrawHideForPlayer(playerid, aks_select_td[5]);
			
			PlayerTextDrawHideEx(playerid, aks_select_price[playerid]);

			CancelSelectTextDraw(playerid);

		}
		case TEXTDRAW_UPDATE:
		{
			new 
				format_str[25];

			new 
				aks_id = aks_select_count[playerid];


		 	format(format_str, sizeof(format_str),"%d_RUB", get_aks_price(playerid, aks_id));
		 	PlayerTextDrawSetString(playerid, aks_select_price[playerid], format_str);
		 	PlayerTextDrawShow(playerid, aks_select_price[playerid]);

		}
	}

	return true;
}

stock buy_aks_player_click(playerid)
{
	if(!GetPVarIntNew(playerid, "selectable_aks_magazin"))
		return true;

	SPD(playerid, DIALOG_BUY_AKS_PREW, DIALOG_STYLE_MSGBOX, !""cBLUE"Магазин аксессуаров", !"\
	"cBLUE"-"cWH" Вы действительно хотите приобрести данный аксессуар?", !"Да", !"Нет");	

	return true;
}

stock buy_aks_player_prew(playerid)
{

	new 
		aks_id = get_aks_id(playerid, aks_select_count[playerid]),
		aks_price = get_aks_price(playerid, aks_select_count[playerid]);

	if(GetPlayerMoneyEx(playerid) < aks_price)
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
		return SendErr(playerid, "У вас недостаточно денежных средств для покупки!");
	}

	if(!GetPVarIntNew(playerid, "selectable_aks_magazin"))
		return true;

	if(pData[playerid][pHouse] != -1 && pData[playerid][pFlate] == -1)
	{
		new 
			h = pData[playerid][pHouse];

		if(House[h][wardrobe_status] != 0)
		{
			if(House[h][wardrobe_aks_1] == -1)
			{
				if(GetPVarIntNew(playerid, "type_select_aks") == 1)
				{		
					House[h][wardrobe_aks_1] = pData[playerid][pSlotItem][0];
					pData[playerid][pSlotItem][0] = -1;
					pData[playerid][pSlotItem][0] = get_aks_id(playerid, aks_select_count[playerid]);
				}
				else if(GetPVarIntNew(playerid, "type_select_aks") == 2)
				{		
					House[h][wardrobe_aks_1] = pData[playerid][pSlotItem][2];
					pData[playerid][pSlotItem][2] = -1;
					pData[playerid][pSlotItem][2] = get_aks_id(playerid, aks_select_count[playerid]);
				}
				if(GetPVarIntNew(playerid, "type_select_aks") == 3)
				{		
					House[h][wardrobe_aks_1] = pData[playerid][pSlotItem][3];
					pData[playerid][pSlotItem][3] = -1;
					pData[playerid][pSlotItem][3] = get_aks_id(playerid, aks_select_count[playerid]);
				}

				
				
				SendInf(playerid, "Ваш старый аксессуар был помещён в шкаф дома, на первую полку!");

				buy_aks_transfer_money(playerid, aks_price);

				return exit_select_clothes(playerid);
			}
			else if(House[h][wardrobe_aks_2] == -1)
			{
				if(GetPVarIntNew(playerid, "type_select_aks") == 1)
				{		
					House[h][wardrobe_aks_2] = pData[playerid][pSlotItem][0];
					pData[playerid][pSlotItem][0] = -1;
					pData[playerid][pSlotItem][0] = get_aks_id(playerid, aks_select_count[playerid]);
				}
				else if(GetPVarIntNew(playerid, "type_select_aks") == 2)
				{		
					House[h][wardrobe_aks_2] = pData[playerid][pSlotItem][2];
					pData[playerid][pSlotItem][2] = -1;
					pData[playerid][pSlotItem][2] = get_aks_id(playerid, aks_select_count[playerid]);
				}
				if(GetPVarIntNew(playerid, "type_select_aks") == 3)
				{		
					House[h][wardrobe_aks_2] = pData[playerid][pSlotItem][3];
					pData[playerid][pSlotItem][3] = -1;
					pData[playerid][pSlotItem][3] = get_aks_id(playerid, aks_select_count[playerid]);
				}

				SendInf(playerid, "Ваш старый аксессуар был помещён в шкаф дома, на вторую полку!");

				buy_aks_transfer_money(playerid, aks_price);

				return exit_select_clothes(playerid);
			}
			else if(House[h][wardrobe_aks_3] == -1)
			{
				if(GetPVarIntNew(playerid, "type_select_aks") == 1)
				{		
					House[h][wardrobe_aks_3] = pData[playerid][pSlotItem][0];
					pData[playerid][pSlotItem][0] = -1;
					pData[playerid][pSlotItem][0] = get_aks_id(playerid, aks_select_count[playerid]);
				}
				else if(GetPVarIntNew(playerid, "type_select_aks") == 2)
				{		
					House[h][wardrobe_aks_3] = pData[playerid][pSlotItem][2];
					pData[playerid][pSlotItem][2] = -1;
					pData[playerid][pSlotItem][2] = get_aks_id(playerid, aks_select_count[playerid]);
				}
				if(GetPVarIntNew(playerid, "type_select_aks") == 3)
				{		
					House[h][wardrobe_aks_3] = pData[playerid][pSlotItem][3];
					pData[playerid][pSlotItem][3] = -1;
					pData[playerid][pSlotItem][3] = get_aks_id(playerid, aks_select_count[playerid]);
				}

				SendInf(playerid, "Ваш старый аксессуар был помещён в шкаф дома, на третью полку!");

				buy_aks_transfer_money(playerid, aks_price);



				return exit_select_clothes(playerid);
			}
			else if(House[h][wardrobe_aks_1] != -1 && House[h][wardrobe_aks_2] != -1 && House[h][wardrobe_aks_3] != -1)
			{
				SPD(playerid, DIALOG_BUY_CLOTHES_FINAL, DIALOG_STYLE_MSGBOX, !""cBLUE"Магазин аксессуаров", !"\
				"cBLUE"-"cWH" В шкафу Вашего дома недостаточно места!\n\n\
				Текущий акссесуар будет заменена новым, Вы уверены в покупке?", !"Да", !"Нет");	
			}
		}
		else
		{
			SPD(playerid, DIALOG_BUY_AKS_FINAL, DIALOG_STYLE_MSGBOX, !""cBLUE"Магазин аксессуаров", !"\
			"cBLUE"-"cWH" У вас нет шкафа!\n\n\
			Текущая одежда будет заменена новой, Вы уверены в покупке?", !"Да", !"Нет");					
		}
	}
	else if(pData[playerid][pHouse] == -1 && pData[playerid][pFlate] != -1)
	{
		new 
			h = pData[playerid][pFlate];

		if(flate[h][wardrobe_status] != 0)
		{
			if(flate[h][wardrobe_aks_1] == -1)
			{
				if(GetPVarIntNew(playerid, "type_select_aks") == 1)
				{		
					flate[h][wardrobe_aks_1] = temp_magazin_aks_slot_0[playerid];
					temp_magazin_aks_slot_0[playerid] = -1;
				}
				else if(GetPVarIntNew(playerid, "type_select_aks") == 2)
				{		
					flate[h][wardrobe_aks_1] = temp_magazin_aks_slot_1[playerid];
					temp_magazin_aks_slot_1[playerid] = -1;
				}
				if(GetPVarIntNew(playerid, "type_select_aks") == 3)
				{		
					flate[h][wardrobe_aks_1] = pData[playerid][pSlotItem][3];
					pData[playerid][pSlotItem][3] = -1;
				}


				SendInf(playerid, "Ваш старый скин был помещён в шкаф квартиры, на первую вешалку!");
				buy_aks_transfer_money(playerid, aks_price);

				return exit_select_clothes(playerid);
			}
			else if(flate[h][wardrobe_aks_2] == -1)
			{
				if(GetPVarIntNew(playerid, "type_select_aks") == 1)
				{		
					flate[h][wardrobe_aks_2] = temp_magazin_aks_slot_0[playerid];
					temp_magazin_aks_slot_0[playerid] = -1;
				}
				else if(GetPVarIntNew(playerid, "type_select_aks") == 2)
				{		
					flate[h][wardrobe_aks_2] = temp_magazin_aks_slot_1[playerid];
					temp_magazin_aks_slot_1[playerid] = -1;
				}
				if(GetPVarIntNew(playerid, "type_select_aks") == 3)
				{		
					flate[h][wardrobe_aks_2] = pData[playerid][pSlotItem][3];
					pData[playerid][pSlotItem][3] = -1;
				}

				SendInf(playerid, "Ваш старый скин был помещён в шкаф квартиры, на вторую вешалку!");

				buy_aks_transfer_money(playerid, aks_price);

				pData[playerid][pSkin] = aks_id;
				UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);

				return exit_select_clothes(playerid);
			}
			else if(flate[h][wardrobe_aks_3] == -1)
			{
				if(GetPVarIntNew(playerid, "type_select_aks") == 1)
				{		
					flate[h][wardrobe_aks_3] = temp_magazin_aks_slot_0[playerid];
					temp_magazin_aks_slot_0[playerid] = -1;
				}
				else if(GetPVarIntNew(playerid, "type_select_aks") == 2)
				{		
					flate[h][wardrobe_aks_3] = temp_magazin_aks_slot_1[playerid];
					temp_magazin_aks_slot_1[playerid] = -1;
				}
				if(GetPVarIntNew(playerid, "type_select_aks") == 3)
				{		
					flate[h][wardrobe_aks_3] = pData[playerid][pSlotItem][3];
					pData[playerid][pSlotItem][3] = -1;
				}
				
				SendInf(playerid, "Ваш старый скин был помещён в шкаф квартиры, на третью вешалку!");

				buy_aks_transfer_money(playerid, aks_price);

				pData[playerid][pSkin] = aks_id;
				UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);

				return exit_select_clothes(playerid);
			}
			else if(flate[h][wardrobe_aks_1] != -1 && flate[h][wardrobe_aks_2] != -1 && flate[h][wardrobe_aks_3] != -1)
			{
				SPD(playerid, DIALOG_BUY_AKS_FINAL, DIALOG_STYLE_MSGBOX, !""cBLUE"Магазин аксессуаров", !"\
				"cBLUE"-"cWH" В шкафу Вашей квартиры недостаточно места!\n\n\
				Текущий аксессуар будет заменен новым, Вы уверены в покупке?", !"Да", !"Нет");	
			}
		}
		else
		{
			SPD(playerid, DIALOG_BUY_AKS_FINAL, DIALOG_STYLE_MSGBOX, !""cBLUE"Магазин аксессуаров", !"\
			"cBLUE"-"cWH" У вас нет шкафа!\n\n\
			Текущий аксессуар будет заменена новым, Вы уверены в покупке?", !"Да", !"Нет");	
		}
	}
	else if(pData[playerid][pHouse] == -1 && pData[playerid][pFlate] == -1)
	{
		SPD(playerid, DIALOG_BUY_AKS_FINAL, DIALOG_STYLE_MSGBOX, !""cBLUE"Магазин аксессуаров", !"\
		"cBLUE"-"cWH" У вас нет шкафа!\n\n\
		Текущий аксессуар будет заменена новым, Вы уверены в покупке?", !"Да", !"Нет");	
	}		
	
	return true;
}

stock buy_aks_accept_final(playerid)
{

	new 
		aks_id = get_aks_id(playerid, aks_select_count[playerid]),
		aks_price = get_aks_price(playerid, aks_select_count[playerid]);

	if(GetPlayerMoneyEx(playerid) < aks_price)
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
		return SendErr(playerid, "У вас недостаточно денежных средств для покупки!");
	}


	if(GetPVarIntNew(playerid, "type_select_aks") == 1)
	{		
		pData[playerid][pSlotItem][0] = aks_id;
	}
	else if(GetPVarIntNew(playerid, "type_select_aks") == 2)
	{		
		pData[playerid][pSlotItem][2] = aks_id;
	}
	if(GetPVarIntNew(playerid, "type_select_aks") == 3)
	{		
		pData[playerid][pSlotItem][3] = aks_id;
	}

	AttachAcsToPlayer(playerid, GetPlayerSkin(playerid));

	buy_aks_transfer_money(playerid, aks_price);

	return exit_select_aks(playerid);
}

stock buy_aks_transfer_money(playerid, price_skin)
{
	new 
		b_id = GetPVarIntNew(playerid, "buisnes_enter_id");

	buisness_bank_update(b_id, floatround(price_skin*0.5), "Покупка аксессуара");

 	format(String144, sizeof(String144), "Покупка аксессуара %d | №%d", aks_select_count[playerid], b_id);
	give_money(playerid, -price_skin, String144);

	check_quest_prize_start(playerid, 15);
 
	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_buy_aks", 4000);

	SendSucc(playerid, "Вы успешно приобрели новый аксессуар!");

	return true;
}

stock exit_select_aks(playerid)
{
	new 
		type = GetPVarIntNew(playerid, "buisnes_enter_type"),
		b_id = GetPVarIntNew(playerid, "buisnes_enter_id");

	switch(type)
	{
		case BUISNES_ACCESSORIES:
		{
			textdraw_aks_select(playerid, TEXTDRAW_HIDE, BUISNES_ACCESSORIES);



			CancelSelectTextDraw(playerid);
			SetCameraBehindPlayer(playerid);

			SetPlayerVirtualWorld(playerid, b_id);
			TogglePlayerControllable(playerid, true);
			SetPlayerPosEx(playerid, -647.5845,-712.9646,1201.9475,86.6747);

			TogglePlayerAllHudElements(playerid, HUD_ELEMENT_SHOW);
			setting_hud_element_p(playerid);

			for(new i; i<7; i++)
			{
				if(IsPlayerAttachedObjectSlotUsed(playerid, i))
					RemovePlayerAttachedObject(playerid, i);
			}
			AttachAcsToPlayer(playerid, GetPlayerSkin(playerid));
		}
	}

	AttachAcsToPlayer(playerid, GetPlayerSkin(playerid));
	clear_pvar_select_aks(playerid);
	return true;
}


stock clear_pvar_select_aks(playerid)
{

	DeletePVarNew(playerid, "type_select_aks_shop");
	DeletePVarNew(playerid, "type_select_aks");
	DeletePVarNew(playerid, "selectable_aks_magazin");

	aks_id_buy[playerid] = 0;
	aks_select_count[playerid] = 0;

	temp_magazin_aks_slot_0[playerid] = 0;
	temp_magazin_aks_slot_1[playerid] = 0;
	temp_magazin_aks_slot_2[playerid] = 0;

	return true;
}

stock AttachAcsToPlayerMagazin(playerid, skin)
{
	ValidAcsSlot(playerid);// Проверяем занятые слоты аттачей

	if(temp_magazin_aks_slot_0[playerid])
	{
		switch(temp_magazin_aks_slot_0[playerid])// Голова
		{
			case 10998, 10999, 11000, 11001:// Кепки
			{
				switch(skin)
				{
					case 9: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.202000,-0.105000,-0.031999,102.099861,99.000022,-13.400002,1.093001,1.091004,0.933000);
					case 17: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.181999,-0.080999,-0.032000,94.100082,91.800140,0.000000,1.000000,1.000000,1.000000);
					case 30: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.202000,-0.087000,-0.031999,102.099861,99.000022,-13.400002,1.206000,1.091004,0.933000);
					case 31: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.214000,-0.087000,-0.031999,102.099861,98.800025,-13.400002,1.017999,1.164003,0.808001);
					case 39: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.177000,-0.078000,-0.030999,102.099861,99.000022,-13.400002,1.159000,1.111004,0.933000);
					case 46: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.174001,-0.075000,-0.029999,105.399902,93.100051,-12.800012,0.957002,0.940010,0.985000);
					case 51: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.184000,-0.093000,-0.030999,105.399902,93.100051,-12.800012,1.058002,1.014010,0.882999);
					case 52: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.207001,-0.065000,-0.022999,105.399902,93.100051,-12.800012,0.957002,0.940010,0.985000);
					case 54: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.203001,-0.085000,-0.034999,105.399902,93.100051,-12.800012,1.040003,1.104010,0.985000);
					case 57: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.197001,-0.109000,-0.030999,105.399902,93.100051,-12.800012,1.058002,1.014010,0.882999);
					case 58: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.197001,-0.073000,-0.024999,105.399902,93.100051,-12.800012,1.058002,1.014010,0.882999);
					case 59: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.177999,-0.096999,-0.040999,94.100082,91.800140,0.000000,1.124999,1.093999,1.152000);
					case 60: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.184000,-0.106000,-0.030999,105.399902,93.100051,-12.800012,1.144002,1.014010,0.882999);
					case 64: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.214000,-0.100000,-0.031999,102.099861,98.800025,-13.400002,1.214000,1.238003,0.933000);
					case 66: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.197001,-0.076000,-0.030999,105.399902,93.100051,-12.800012,1.058002,1.014010,0.882999);
					case 68: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.229001,-0.092000,-0.032999,105.399902,93.100051,-12.800012,1.165002,1.196010,1.012000);
					case 70: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.202001,-0.101000,-0.030999,105.399902,93.100051,-12.800012,1.144002,1.111010,0.882999);
					case 72: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.185001,-0.085000,-0.039999,105.399902,93.100051,-12.800012,1.040003,1.028010,0.985000);
					case 75: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.190001,-0.104000,-0.020999,102.299880,92.200042,-12.800012,1.119003,1.129009,0.898999);
					case 79: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.189000,-0.091000,-0.018999,102.099861,99.000022,-13.400002,1.093001,1.030004,0.933000);
					case 80: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.171000,-0.104000,-0.020999,102.299880,92.200042,-12.800012,1.119003,1.039009,0.898999);
					case 82: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.197001,-0.073000,-0.024999,105.399902,93.100051,-12.800012,1.058002,1.014010,0.882999);
					case 84: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.179001,-0.094000,-0.030999,105.399902,93.100051,-12.800012,1.013003,1.102010,0.884000);
					case 98: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.144999,-0.092999,-0.028999,94.100097,78.600326,-3.599994,0.980997,1.092001,1.165002);
					case 100: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.202000,-0.075000,-0.031999,102.099861,99.000022,-13.400002,1.206000,1.091004,0.933000);
					case 101: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.144999,-0.125999,-0.038999,94.100097,78.600326,-3.599994,1.116998,1.157001,1.165002);
					case 102: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.155999,-0.118999,-0.032999,93.800102,78.600326,-3.599994,1.096998,1.140002,1.138001);
					case 103: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.155999,-0.118999,-0.032999,93.800102,78.600326,-3.599994,1.096998,1.140002,1.138001);
					case 104: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.151999,-0.118999,-0.027999,93.800102,78.600326,-3.599994,1.096998,1.198002,1.134001);
					case 105: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.151999,-0.088999,-0.027999,93.800102,78.600326,-3.599994,1.039998,1.028000,1.134001);
					case 106: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.151999,-0.098999,-0.039999,93.800102,78.600326,-3.599994,1.118999,1.171000,1.313001);
					case 107: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.151999,-0.098999,-0.030999,93.800102,78.600326,-3.599994,1.166999,1.066001,1.172001);
					case 108: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.151999,-0.080999,-0.030999,94.100097,78.600326,-3.599994,1.104998,1.066001,1.172001);
					case 109: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.130999,-0.094999,-0.030999,94.100097,78.600326,-3.599994,1.104998,1.096001,1.172001);
					case 110: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.129999,-0.085999,-0.030999,94.100097,78.600326,-3.599994,1.104998,1.096001,1.172001);
					case 116: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.144999,-0.093999,-0.025999,94.100097,78.600326,-3.599994,0.980997,0.919001,1.093002);
					case 111: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.181001,-0.092000,-0.029999,105.399902,93.100051,-12.800012,1.011002,0.995009,0.985000);
					case 112: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.181001,-0.102000,-0.032999,105.399902,93.100051,-12.800012,1.040003,1.024010,0.985000);
					case 133: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.192001,-0.099000,-0.037999,102.299880,92.200042,-12.800012,1.196003,1.374010,1.006999);
					case 134: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.177000,-0.086000,-0.021999,102.099861,99.000022,-13.400002,1.177999,1.111004,0.933000);
					case 135: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.184000,-0.099000,-0.021999,100.899902,99.000022,-13.400002,1.108002,1.103007,0.890000);
					case 136: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.177000,-0.095000,-0.026999,100.899902,99.000022,-13.400002,1.177999,1.135004,1.128999);
					case 141: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.211999,-0.096999,-0.040999,94.100082,91.200263,0.000000,1.151998,1.128000,1.255000);
					case 148: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.171000,-0.090000,-0.022999,102.299880,92.200042,-12.800012,1.030004,1.024009,0.898999);
					case 151: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.184000,-0.104000,-0.045999,100.899902,99.000022,-13.400002,1.092002,1.123008,0.968999);
					case 152: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.186001,-0.104000,-0.030999,102.299880,99.000022,-12.800012,1.092002,1.123008,0.898999);
					case 155: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.190001,-0.080000,-0.045999,102.299880,92.200042,-12.800012,1.018003,1.028008,0.898999);
					case 163: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.195001,-0.088000,-0.043999,105.399902,93.100051,-12.800012,1.077003,1.102010,0.884000);
					case 164: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.186999,-0.086999,-0.036999,94.100082,91.200263,0.000000,1.084998,1.117001,1.138001);
					case 165: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.155999,-0.129999,-0.029999,93.800102,78.600326,-3.599994,1.086998,1.140002,1.138001);
					case 167: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.200001,-0.104000,-0.030999,102.299880,99.000022,-12.800012,1.092002,1.123008,0.898999);
					case 172: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.202001,-0.102000,-0.040999,105.399902,93.100051,-12.800012,1.077003,1.106011,1.021999);
					case 174: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.154001,-0.102000,-0.035999,105.399902,93.100051,-12.800012,1.077003,1.017011,0.884000);
					case 175: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.188001,-0.089000,-0.035999,105.399902,93.100051,-12.800012,1.077003,1.017011,0.884000);
					case 186: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.175001,-0.094000,-0.031999,105.399902,93.100051,-12.800012,1.040003,1.028010,0.985000);
					case 187: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.186999,-0.083999,-0.040999,94.100082,91.200263,0.000000,1.042998,1.005000,1.105000);
					case 188: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.160001,-0.072000,-0.025999,105.399902,93.100051,-12.800012,1.204003,1.186010,1.056000);
					case 198: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.205001,-0.107000,-0.033999,102.099861,99.000022,-13.400002,1.159000,1.317004,0.933000);
					case 202: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.165001,-0.068000,-0.031999,105.399902,93.100051,-12.800012,1.040003,1.028010,0.985000);
					case 211: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.160001,-0.102000,-0.040999,105.399902,93.100051,-12.800012,1.053003,1.089011,1.021999);
					case 225: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.177000,-0.106000,-0.026999,100.899902,99.000022,-13.400002,1.162999,1.128006,1.128999);
					case 231: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.177000,-0.112000,-0.026999,100.899902,99.000022,-13.400002,1.191000,1.226007,1.316000);
					case 232: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.177000,-0.103000,-0.016999,100.899902,99.000022,-13.400002,1.071000,1.050007,0.852000);
					case 234: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.177000,-0.071000,-0.021999,100.899902,99.000022,-13.400002,1.106001,1.103007,0.890000);
					case 239: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.184000,-0.089000,-0.027999,100.899902,99.000022,-13.400002,1.034002,0.980007,0.968999);
					case 247: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.179000,-0.091000,-0.018999,96.199867,82.900077,-10.599991,0.923999,0.966003,0.783002);
					case 248: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.179000,-0.097000,-0.020999,98.799842,85.800033,-10.299995,0.923999,0.966003,0.783002);
					case 254: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.179000,-0.091000,-0.012999,96.199867,82.900077,-10.599991,0.923999,0.966003,0.783002);
					case 266: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.194001,-0.084000,-0.024000,105.399902,93.100051,-12.800012,1.053003,1.089011,1.021999);
					case 268: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.173000,-0.061000,-0.021999,102.299880,92.200042,-12.800012,1.018003,1.028008,0.898999);
					case 275: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.183000,-0.085000,-0.024999,102.299880,92.200042,-12.800012,1.144002,1.005010,0.882999);
					case 276: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.175000,-0.096000,-0.033999,105.399902,93.100051,-12.800012,1.144002,1.111010,0.882999);
					case 284: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.160001,-0.059000,-0.033000,105.399902,93.100051,-12.800012,1.053003,1.089011,1.021999);
					case 285: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.171001,-0.055000,-0.018000,105.399902,93.100051,-12.800012,1.053003,1.089011,1.021999);
					case 295: SetPlayerAttachedObject (playerid, 1, temp_magazin_aks_slot_0[playerid], 2,0.176000,-0.113000,-0.028999,96.199867,82.900077,-10.599991,1.086999,1.072002,0.824001);
					default: SendInf(playerid, "Головной убор не будет отображен на данной одежде");
				}
			}
		}
	}
	if(temp_magazin_aks_slot_1[playerid])
	{
		switch(temp_magazin_aks_slot_1[playerid]) // Маски 
		{
			case 10971: // Маска bandmask
			{
				switch(skin)
				{
					case 8: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.582999,0.144999, 0.004999, 91.799964, 76.399963, 0.900001, 1.095996, 1.092001, 1.011999);
					case 9: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.585999,0.126999, -0.001000, 91.799964, 76.399963, 0.900001, 1.040000, 0.956000, 1.011999);
					case 13: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.585998,0.139999, -0.006000, 91.499969, 76.399963, 0.900001, 1.040995, 1.107015, 1.023000);
					case 17: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.569999,0.143999, 0.000999, 91.499969, 76.399963, 0.900001, 1.005995, 1.167011, 1.023000);
					case 27: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.593998,0.139999, -0.001000, 91.499969, 76.399963, 0.900001, 1.090996, 1.107015, 1.023000);
					case 30: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.580999,0.153000, 0.001999, 91.799964, 76.399963, 0.900001, 1.067999, 1.062000, 1.012000);
					case 31: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.580999,0.144999, 0.000999, 91.799964, 76.399963, 0.900001, 1.001999, 1.000999, 1.012000); 
					case 34: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.602999,0.144999, -0.004000, 91.499969, 76.399963, 0.900001, 1.067996, 1.027003, 1.011999);
					case 39: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.597999,0.145999, -0.005000, 91.799964, 76.399963, 0.900001, 1.067000, 1.142000, 1.011999);
					case 46: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.582999,0.152999, -0.000000, 91.499969, 76.399963, 0.900001, 0.999997, 1.078009, 1.023000);
					case 51: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.566999,0.132999, -0.003000, 91.499969, 76.399963, 0.900001, 0.954996, 1.051007, 1.023000);
					case 52: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.549999,0.165999, 0.003999, 91.499969, 76.399963, 0.900001, 0.999997, 1.057008, 1.023000);
					case 54: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.572999,0.145999, 0.004999, 91.499969, 76.399963, 0.900001, 1.046995, 1.118012, 1.023000);
					case 57: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.549999,0.125999, -0.002000, 91.499969, 76.399963, 0.900001, 1.031996, 1.100008, 1.023000);
					case 58: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.549999,0.161999, 0.005999, 91.499969, 76.399963, 0.900001, 0.964997, 1.100008, 1.023000);
					case 59: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.589999,0.144999, -0.003000, 91.499969, 76.399963, 0.900001, 1.150995, 1.167011, 1.023000);
					case 60: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.590999,0.133999, -0.005000, 91.499969, 76.399963, 0.900001, 1.040996, 1.051007, 1.023000);
					case 61: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.533999,0.333999, 0.001000, 88.900001, 60.299999, 5.299999, 0.984000, 0.892999, 0.992000); 
					case 63: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.602999,0.142999, -0.007000, 91.499969, 76.399963, 0.900001, 0.966996, 1.027003, 1.011999);
					case 64: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.580999,0.145999, 0.004999, 91.799964, 76.399963, 0.900001, 1.001999, 0.935999, 1.012000);
					case 66: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.549999,0.153999, 0.001999, 91.499969, 76.399963, 0.900001, 0.981996, 1.051007, 1.023000);
					case 68: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.549999,0.168999, 0.006999, 91.499969, 76.399963, 0.900001, 0.933997, 1.030008, 1.023000);
					case 69: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.584999,0.134999, -0.003000, 91.499969, 76.399963, 0.900001, 1.061996, 1.051007, 1.023000);
					case 70: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.584999,0.141999, -0.001000, 91.499969, 76.399963, 0.900001, 1.093996, 1.173007, 1.023000);
					case 72: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.584999,0.141999, -0.008000, 91.499969, 76.399963, 0.900001, 1.094996, 1.137013, 1.023000);
					case 73: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.529000,0.329999, -0.007999, 88.900001, 60.299999, 5.299999, 1.039000, 0.927999, 1.000000); 
					case 75: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.598999,0.119999, 0.011999, 91.799964, 76.399963, 0.900001, 1.130995, 1.196003, 1.011999);
					case 79: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.614999,0.138999, 0.001999, 91.799964, 76.399963, 0.900001, 1.105000, 1.225000, 1.011999);
					case 80: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.598999,0.130999, 0.004999, 91.499969, 76.399963, 0.900001, 1.073996, 1.130003, 1.011999);
					case 82: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.549999,0.163999, 0.001999, 91.499969, 76.399963, 0.900001, 0.964997, 1.100008, 1.023000);
					case 84: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.558999,0.130999, -0.003000, 91.499969, 76.399963, 0.900001, 0.987996, 1.147015, 1.023000);
					case 98: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.575999,0.133999, 0.000999, 91.499969, 76.399963, 0.900001, 1.035996, 1.084015, 1.023000);
					case 100: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.585999,0.150999, -0.005000, 91.799964, 76.399963, 0.900001, 1.126000, 1.062000, 1.011999);
					case 101: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.592999,0.120999, -0.002000, 91.499969, 76.399963, 0.900001, 1.142996, 1.202015, 1.023000);
					case 102: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.584999,0.141999, -0.007000, 91.499969, 76.399963, 0.900001, 0.959996, 0.964013, 1.023000);
					case 103: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.584999,0.160999, -0.001000, 91.499969, 76.399963, 0.900001, 0.959996, 0.964013, 1.023000);
					case 104: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.586999,0.149999, -0.002000, 91.499969, 76.399963, 0.900001, 0.959996, 1.043014, 1.023000);
					case 105: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.586999,0.152999, -0.002000, 91.499969, 76.399963, 0.900001, 1.039996, 1.043014, 1.023000);
					case 106: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.586999,0.134999, -0.005000, 91.499969, 76.399963, 0.900001, 1.107996, 1.075014, 1.023000);
					case 107: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.599999,0.144999, -0.003000, 91.499969, 76.399963, 0.900001, 1.107996, 1.075014, 1.023000);
					case 108: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.585999,0.154999, 0.000999, 91.499969, 76.399963, 0.900001, 1.107996, 1.161014, 1.023000);
					case 109: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.585999,0.144999, -0.005000, 91.499969, 76.399963, 0.900001, 1.107996, 1.161014, 1.023000);
					case 110: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.585999,0.141999, -0.001000, 91.499969, 76.399963, 0.900001, 1.081996, 1.071015, 1.023000);
					case 116: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.575999,0.141999, 0.000999, 91.499969, 76.399963, 0.900001, 0.964996, 1.071015, 1.023000);
					case 111: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.594999,0.146999, -0.000000, 91.499969, 76.399963, 0.900001, 1.088996, 1.168009, 1.023000);
					case 112: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.594999,0.140999, -0.000000, 91.499969, 76.399963, 0.900001, 1.088996, 1.168009, 1.023000);
					case 133: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.591999,0.156999, -0.000000, 91.499969, 76.399963, 0.900001, 0.990996, 1.139005, 1.011999);
					case 134: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.585999,0.145999, 0.002999, 91.799964, 76.399963, 0.900001, 1.067000, 1.142000, 1.011999);
					case 135: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.591999,0.141999, 0.000999, 91.799964, 76.399963, 0.900001, 1.070997, 1.191999, 1.011999);
					case 136: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.585999,0.132999, 0.002999, 91.799964, 76.399963, 0.900001, 1.067000, 1.142000, 1.011999);
					case 141: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.589999,0.163999, 0.000999, 91.499969, 76.399963, 0.900001, 0.962995, 1.104011, 1.023000);
					case 148: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.579999,0.140999, -0.000000, 91.499969, 76.399963, 0.900001, 1.021996, 0.987003, 1.011999);
					case 151: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.593999,0.138999, -0.019000, 91.799964, 76.399963, 0.900001, 1.092997, 1.059999, 1.011999);
					case 152: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.614999,0.135999, 0.000999, 91.799964, 76.399963, 0.900001, 1.092997, 1.035000, 1.011999);
					case 155: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.572999,0.155999, -0.016000, 91.799964, 76.399963, 0.900001, 1.010996, 1.035000, 1.011999);
					case 163: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.566999,0.138999, -0.009000, 91.499969, 76.399963, 0.900001, 1.059996, 1.147015, 1.023000);
					case 164: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.572999,0.146999, -0.002000, 91.499969, 76.399963, 0.900001, 1.112995, 1.158012, 1.023000);
					case 165: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.589999,0.138999, -0.004000, 91.499969, 76.399963, 0.900001, 1.036995, 1.110011, 1.023000);
					case 167: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.572999,0.127999, -0.005000, 91.799964, 76.399963, 0.900001, 1.095996, 1.035000, 1.011999);
					case 172: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.584998,0.131999, -0.007000, 91.499969, 76.399963, 0.900001, 1.113996, 1.089015, 1.023000);
					case 174: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.613998,0.127999, -0.003000, 91.499969, 76.399963, 0.900001, 1.059996, 1.147015, 1.023000);
					case 175: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.575998,0.144999, -0.004000, 91.499969, 76.399963, 0.900001, 0.997996, 1.089015, 1.023000);
					case 181: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.580999,0.140999, 0.003999, 91.799964, 76.399963, 0.900001, 1.067999, 1.062000, 1.012000); 
					case 186: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.566999,0.129999, -0.002000, 91.499969, 76.399963, 0.900001, 1.018996, 1.134015, 1.023000);
					case 187: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.589999,0.149999, -0.009000, 91.499969, 76.399963, 0.900001, 1.078995, 1.104011, 1.023000);
					case 188: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.573999,0.165999, 0.006999, 91.499969, 76.399963, 0.900001, 1.121996, 1.217015, 1.023000);
					case 191: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.530000,0.345999, -0.005999, 88.900001, 60.299999, 5.299999, 0.988999, 0.966999, 1.000000);
					case 198: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.597999,0.119999, -0.005000, 91.799964, 76.399963, 0.900001, 1.105000, 1.225000, 1.011999);
					case 202: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.592999,0.157999, -0.002000, 91.499969, 76.399963, 0.900001, 1.018996, 1.134015, 1.023000);
					case 211: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.604998,0.135999, -0.006000, 91.499969, 76.399963, 0.900001, 1.113996, 1.107015, 1.023000);
					case 225: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.585999,0.143999, 0.002999, 91.799964, 76.399963, 0.900001, 1.004999, 1.096000, 1.011999);
					case 231: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.585999,0.143999, 0.004999, 91.799964, 76.399963, 0.900001, 1.004999, 0.970000, 1.011999);
					case 232: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.607999,0.138999, 0.000999, 91.799964, 76.399963, 0.900001, 0.946999, 0.814001, 1.011999);
					case 234: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.592999,0.156999, 0.006999, 91.799964, 76.399963, 0.900001, 1.095998, 0.996000, 1.011999);
					case 235: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.596999,0.133999, 0.010999, 91.799964, 76.399963, 0.900001, 1.069998, 1.062000, 1.011999);
					case 236: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.582999,0.147999, 0.010999, 91.799964, 76.399963, 0.900001, 0.975998, 1.062000, 1.011999);
					case 239: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.580999,0.141999, -0.005000, 91.799964, 76.399963, 0.900001, 1.006997, 1.038998, 1.011999);
					case 247: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.593999,0.140000, 0.001999, 91.799964, 76.399963, 0.900001, 1.050000, 1.000000, 1.000000);
					case 248: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.589999,0.141000, -0.001000, 91.799964, 76.399963, 0.900001, 1.012000, 1.000000, 1.000000);
					case 254: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.578000,0.134000, 0.002999, 91.799964, 76.399963, 0.900001, 1.050000, 1.000000, 1.000000);
					case 255: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.525999,0.348999, -0.019999, 88.900001, 60.299999, 5.299999, 1.047000, 0.958999, 0.992000);
					case 266: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.578999,0.147999, 0.005999, 91.499969, 76.399963, 0.900001, 1.116995, 1.167011, 1.023000);
					case 268: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.582999,0.167999, 0.007999, 91.799964, 76.399963, 0.900001, 0.982996, 1.012000, 1.011999);
					case 274: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.584999,0.133999, -0.000000, 91.499969, 76.399963, 0.900001, 1.039996, 1.085005, 1.023000);
					case 275: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.584999,0.151999, -0.004000, 91.499969, 76.399963, 0.900001, 1.039996, 1.167006, 1.023000);
					case 276: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.584999,0.141999, -0.001000, 91.499969, 76.399963, 0.900001, 1.093996, 1.105006, 1.023000);
					case 280: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.605999,0.162999, -0.001000, 91.499969, 76.399963, 0.900001, 1.088996, 1.127011, 1.023000);
					case 283: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.601999,0.140999, -0.000000, 91.499969, 76.399963, 0.900001, 1.088996, 1.084009, 1.023000);
					case 284: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.605999,0.158999, -0.001000, 91.499969, 76.399963, 0.900001, 0.992995, 1.082011, 1.023000);
					case 285: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.581999,0.173999, 0.016999, 91.499969, 76.399963, 0.900001, 1.085995, 1.167011, 1.023000);
					case 287: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.530000,0.340999, -0.008999, 88.900001, 60.299999, 5.299999, 0.988999, 0.918000, 1.000000);
					case 295: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.551999,0.317999, -0.017999, 88.900001, 60.299999, 5.299999, 1.039000, 0.927999, 1.000000);
					default: SendInf(playerid, "Маска не будет отображена на данной одежде");
				}
			}
			case 10973: // Маска grimpmask
			{
				switch(skin)
				{
					case 8: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.565998, 0.048999, -0.035999, 27.799999, 86.099639, 70.599983, 0.782001, 0.898995, 0.992999);
					case 9: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.574999, 0.020000, -0.080999, 29.199968, 82.999824, 66.500000, 1.000000, 0.919001, 1.000000);
					case 13: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.577999, 0.143000, 0.000000, 94.699806, 80.500061, 1.800000, 0.683002, 0.886002, 0.991000);
					case 17: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.561000, 0.100999, 0.005000, 93.499839, 83.000083, 0.000000, 0.742002, 0.891001, 1.000000);
					case 27: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.592999, 0.151000, 0.003000, 94.699806, 80.500061, 1.800000, 0.683002, 0.900002, 0.991000);
					case 30: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.535999, 0.013000, -0.038999, -29.300025, 86.400001, 121.600135, 0.862000, 0.939999, 0.948000);
					case 31: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.538999, -0.020999, -0.045999, -28.800024, 85.800018, 124.200050, 0.875000, 0.909999, 0.955000);
					case 34: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.599000, 0.061999, -0.008000, 90.799995, 87.200035, 0.000000, 0.742002, 1.000000, 1.000000);
					case 39: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.578999, 0.058999, -0.075999, 29.199964, 83.499740, 66.899948, 0.858000, 1.040995, 0.993999);
					case 46: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.574000, 0.082999, 0.001000, 91.199821, 84.600082, 0.000000, 0.742002, 0.850002, 1.000000);
					case 51: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.562000, 0.039999, -0.000999, 91.199821, 86.500030, 0.000000, 0.742002, 0.928001, 1.000000);
					case 52: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.554000, 0.079999, 0.006000, 91.199821, 86.500030, 0.000000, 0.742002, 0.826002, 1.000000);
					case 54: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.546000, 0.137000, 0.004000, 91.099838, 82.000099, 0.000000, 0.742002, 0.949001, 0.976000);
					case 57: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.553000, 0.042999, 0.000000, 91.199821, 86.500030, 0.000000, 0.742002, 0.928001, 1.000000);
					case 58: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.549000, 0.073999, 0.006000, 91.199821, 86.500030, 0.000000, 0.742002, 0.928001, 1.000000);
					case 59: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.580000, 0.127000, 0.001000, 93.499839, 83.000083, 0.000000, 0.742002, 0.891001, 1.000000);
					case 60: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.573000, 0.051999, -0.002999, 91.199821, 86.500030, 0.000000, 0.742002, 0.931001, 1.000000);
					case 61: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.568000, 0.014000, 0.009000, 98.200035, 88.199996, 0.000000, 1.000000, 1.000000, 1.000000);
					case 63: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.596000, 0.043999, -0.001999, 90.799995, 87.200035, 0.000000, 0.742002, 1.000000, 1.000000);
					case 64: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.530999, -0.013999, -0.039999, -28.800024, 85.900009, 120.800148, 0.862000, 0.889999, 0.948000);
					case 66: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.551000, 0.070999, 0.006000, 91.199821, 86.500030, 0.000000, 0.742002, 0.928001, 1.000000);
					case 68: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.544000, 0.080999, 0.009000, 91.199821, 86.500030, 0.000000, 0.742002, 0.851002, 1.000000);
					case 69: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.573000, 0.057999, -0.003999, 91.199821, 86.500030, 0.000000, 0.742002, 0.931001, 1.000000);
					case 70: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.571000, 0.070999, 0.001000, 91.199821, 86.500030, 0.000000, 0.742002, 0.931001, 1.000000);
					case 72: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.562000, 0.119000, -0.008999, 91.099838, 82.000099, 0.000000, 0.742002, 0.949001, 0.976000);
					case 73: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.572000, 0.024000, 0.000000, 98.200035, 88.199996, 0.000000, 1.000000, 1.000000, 1.000000);
					case 75: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.596998, 0.026999, -0.033999, 19.800014, 86.199638, 70.599983, 0.782001, 0.928995, 0.992999);
					case 79: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.565999, 0.057999, -0.078999, 29.699970, 82.199752, 67.199966, 0.995000, 1.077001, 0.993999);
					case 80: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.589998, 0.031999, -0.036999, 19.800014, 86.199638, 70.599983, 0.782001, 0.928995, 0.992999);
					case 82: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.550000, 0.071999, 0.005000, 91.199821, 86.500030, 0.000000, 0.742002, 0.841002, 1.000000);
					case 84: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.554000, 0.061000, 0.001000, 94.699806, 84.899993, 1.800000, 0.742002, 0.872002, 0.991000);
					case 98: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.563000, 0.096000, 0.002000, 94.699806, 83.300018, 1.800000, 0.742002, 0.856001, 0.991000);
					case 100: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.561999, 0.055000, -0.082999, 29.199968, 82.700080, 66.500000, 1.000000, 1.000000, 1.000000);
					case 101: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.580000, 0.093000, 0.002000, 94.699806, 83.300018, 1.800000, 0.742002, 0.969000, 0.991000);
					case 102: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.572000, 0.114000, -0.002999, 91.099838, 82.000099, 0.000000, 0.742002, 0.866001, 0.976000);
					case 103: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.577000, 0.124000, 0.002000, 90.599777, 82.100112, 0.000000, 0.742002, 0.912000, 0.976000);
					case 104: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.581000, 0.120000, 0.007000, 95.099761, 81.300033, 0.100001, 0.742002, 0.859001, 0.991000);
					case 105: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.567000, 0.139000, 0.007000, 95.099761, 81.300033, 0.100001, 0.742002, 0.859001, 0.991000);
					case 106: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.559000, 0.131000, 0.000000, 94.699806, 82.000038, 1.800000, 0.742002, 0.859001, 0.991000);
					case 107: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.567000, 0.123000, 0.003000, 94.699806, 83.300018, 1.800000, 0.742002, 0.859001, 0.991000);
					case 108: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.561000, 0.131000, 0.002000, 94.699806, 83.300018, 1.800000, 0.742002, 0.895000, 0.991000);
					case 109: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.577000, 0.108000, -0.001999, 94.699806, 83.300018, 1.800000, 0.742002, 0.890000, 0.991000);
					case 110: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.571000, 0.108000, 0.005000, 94.699806, 83.300018, 1.800000, 0.742002, 0.890000, 0.991000);
					case 116: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.564000, 0.089000, 0.002000, 94.699806, 83.300018, 1.800000, 0.742002, 0.856001, 0.991000);
					case 111: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.573000, 0.118999, 0.005000, 93.499839, 83.000083, 0.000000, 0.742002, 0.966001, 1.000000);
					case 112: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.578000, 0.105999, 0.005000, 93.499839, 83.000083, 0.000000, 0.742002, 0.966001, 1.000000);
					case 133: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.582000, 0.055999, -0.003999, 94.599884, 88.100044, 0.000000, 0.742002, 0.979000, 1.000000);
					case 134: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.563999, 0.044999, -0.066999, 29.199964, 83.499740, 66.899948, 0.858000, 1.040995, 0.993999);
					case 135: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.566999, 0.051999, -0.042999, 27.799999, 86.099639, 70.599983, 0.782001, 0.987994, 0.992999);
					case 136: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.556999, 0.047999, -0.071999, 29.199964, 83.499740, 66.899948, 0.858000, 1.040995, 0.993999);
					case 141: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.583000, 0.111000, 0.007000, 93.499839, 83.000083, 0.000000, 0.742002, 0.873001, 1.000000);
					case 148: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.575000, 0.039999, 0.000000, 94.599884, 88.100044, 0.000000, 0.742002, 0.905001, 1.000000); 
					case 151: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.571999, 0.043999, -0.064999, 27.799999, 86.099639, 70.599983, 0.782001, 0.901995, 0.992999);
					case 152: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.603999, 0.044999, -0.041999, 27.799999, 86.099639, 70.599983, 0.782001, 0.892995, 0.992999);
					case 155: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.562999, 0.052999, -0.064999, 27.799999, 86.099639, 70.599983, 0.782001, 0.892995, 0.992999);
					case 163: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.554000, 0.088000, -0.004999, 94.699806, 85.299987, 1.800000, 0.683002, 0.962002, 0.991000);
					case 164: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.540000, 0.132000, 0.003000, 91.099838, 82.000099, 0.000000, 0.742002, 0.985000, 0.976000);
					case 165: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.571000, 0.110000, -0.003999, 91.099838, 82.000099, 0.000000, 0.742002, 0.872001, 0.976000);
					case 167: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.556999, 0.039999, -0.048999, 27.799999, 86.099639, 70.599983, 0.782001, 0.892995, 0.992999);
					case 172: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.569999, 0.095000, 0.000000, 94.699806, 84.200004, 1.800000, 0.683002, 0.867003, 0.991000);
					case 174: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.596999, 0.067000, -0.000999, 94.699806, 85.499984, 1.800000, 0.683002, 0.916003, 0.991000);
					case 175: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.564999, 0.084000, -0.000999, 94.699806, 85.499984, 1.800000, 0.683002, 0.878003, 0.991000);
					case 181: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.583999, 0.048999, -0.088999, 29.399976, 82.100074, 66.500000, 1.000000, 1.000000, 1.000000);
					case 186: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.552000, 0.080000, 0.002000, 94.699806, 83.300018, 1.800000, 0.742002, 0.866002, 0.991000);
					case 187: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.577000, 0.117000, -0.003999, 93.499839, 83.000083, 0.000000, 0.742002, 0.900001, 1.000000);
					case 188: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.572000, 0.116000, 0.010000, 94.699806, 84.200004, 1.800000, 0.742002, 0.912002, 0.991000);
					case 191: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.571000, 0.043000, 0.000000, 98.200035, 88.199996, 0.000000, 1.000000, 1.000000, 1.000000);
					case 198: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.585999, 0.043999, -0.087999, 29.199964, 82.299758, 66.899948, 0.995000, 1.040995, 0.993999);
					case 202: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.580000, 0.113000, 0.004000, 94.699806, 83.300018, 1.800000, 0.742002, 0.909001, 0.991000);
					case 211: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.585999, 0.143000, 0.003000, 94.699806, 80.500061, 1.800000, 0.683002, 0.886002, 0.991000);
					case 225: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.568999, 0.047999, -0.068999, 29.199964, 83.499740, 66.899948, 0.858000, 0.965995, 0.992999);
					case 231: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.562999, 0.028999, -0.058999, 24.000000, 84.099861, 66.399948, 0.858000, 0.967994, 0.992999);
					case 232: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.600998, 0.021999, -0.060999, 24.000000, 84.099861, 66.399948, 0.858000, 0.864995, 0.992999);
					case 234: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.574999, 0.065999, -0.044999, 24.000000, 85.499839, 66.399948, 0.858000, 0.914995, 0.992999);
					case 235: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.575999, 0.038999, -0.038999, 24.000000, 85.499839, 66.399948, 0.858000, 0.924995, 0.992999);
					case 236: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.571999, 0.044999, -0.037999, 24.000000, 85.499839, 66.399948, 0.858000, 0.933995, 0.992999);
					case 239: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.559999, 0.038999, -0.050999, 27.799999, 86.099639, 70.599983, 0.782001, 0.901995, 0.992999);
					case 247: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.555999, -0.008999, -0.044999, -28.800024, 85.800018, 124.200050, 0.910000, 0.971998, 0.962000);
					case 248: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.541999, -0.024999, -0.045999, -28.800024, 85.800018, 124.200050, 0.910000, 0.971998, 0.962000);
					case 254: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.539999, -0.035999, -0.033999, -37.700012, 85.700042, 127.400016, 1.000000, 0.948000, 0.963000);
					case 255: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.566000, 0.035000, -0.008999, 98.200035, 88.199996, 0.000000, 1.000000, 1.000000, 1.000000);
					case 266: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.568000, 0.123999, 0.014000, 93.499839, 83.000083, 0.000000, 0.742002, 0.900001, 1.000000);
					case 268: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.568998, 0.055999, -0.040999, 27.799999, 86.099639, 70.599983, 0.782001, 0.892995, 0.992999);
					case 274: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.562000, 0.003000, -0.074999, 8.300006, 83.399948, 84.800079, 1.000000, 1.000000, 1.000000);
					case 275: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.579000, 0.056999, -0.003999, 94.599884, 88.100044, 0.000000, 0.742002, 0.908001, 1.000000);
					case 276: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.572000, 0.067999, 0.004000, 91.199821, 86.500030, 0.000000, 0.742002, 0.908001, 1.000000);
					case 280: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.593999, 0.128999, 0.001999, 93.499839, 83.000083, 0.000000, 0.742002, 0.925001, 1.000000);
					case 283: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.587999, 0.107999, -0.000000, 93.499839, 83.000083, 0.000000, 0.742002, 0.876002, 1.000000);
					case 284: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.603999, 0.125999, 0.003999, 93.499839, 83.000083, 0.000000, 0.742002, 0.839001, 1.000000);
					case 285: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.578000, 0.150000, 0.020000, 93.499839, 83.000083, 0.000000, 0.742002, 0.900001, 1.000000);
					case 287: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.572000, 0.038000, -0.001999, 98.200035, 88.199996, 0.000000, 0.886000, 0.904000, 0.994000);
					case 295: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.581000, 0.022000, -0.011999, 98.200035, 88.199996, 0.000000, 1.000000, 1.000000, 1.000000);
					default: SendInf(playerid, "Маска не будет отображена на данной одежде");
				}
			}
			case 10974: // Маска mask6
			{
				switch(skin)
				{
					case 8: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.591997, -0.007999, -0.035000, 13.200003, 85.599258, 73.699989, 1.210000, 0.961997, 1.025999);
					case 9: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.564998, -0.037000, -0.024000, 9.400005, 88.199478, 83.800018, 1.085000, 1.032000, 0.986999);
					case 13: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.577998, -0.037000, -0.038999, 138.099975, 93.799995, -45.400062, 1.000000, 1.103000, 1.000000);
					case 17: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.550000, -0.081000, -0.068999, 137.299972, 97.499977, -41.800029, 1.000000, 1.103000, 1.000000);
					case 27: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.577998, -0.037000, -0.038999, 138.099975, 93.799995, -45.400062, 1.000000, 1.103000, 1.000000);
					case 30: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.571998, -0.009000, -0.014000, 9.400005, 89.599594, 84.200035, 1.085000, 1.032000, 0.986999);
					case 31: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.566998, -0.018000, -0.023000, 9.400007, 88.799629, 84.200057, 1.085000, 0.946999, 0.991999);
					case 34: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.664997, -0.001999, 0.005999, 14.700007, 90.999237, 73.699989, 0.969001, 0.846998, 1.101999);
					case 39: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.595997, -0.025000, -0.045000, 13.800005, 86.699501, 79.600036, 1.248000, 1.111000, 1.020999);
					case 46: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.459997, -0.022999, -0.046000, 14.700007, 86.299064, 83.199851, 1.117004, 1.036994, 0.840000);
					case 51: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.481997, -0.051999, 0.017999, 14.700007, 90.999153, 72.399917, 1.202000, 0.885998, 0.897999);
					case 52: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.444997, -0.010999, -0.042000, 14.700007, 86.299064, 83.199851, 1.154004, 1.039994, 0.840000);
					case 54: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.571000, 0.018999, 0.000000, 138.099975, 86.700065, -30.700044, 1.000000, 1.103000, 1.000000);
					case 57: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.487997, -0.075999, -0.014000, 14.700007, 89.399177, 79.399932, 1.299001, 0.975997, 0.897999);
					case 58: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.481997, -0.044999, -0.010000, 14.700007, 89.399177, 79.399932, 1.299001, 0.975997, 0.897999);
					case 59: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.558000, -0.062000, -0.069999, 137.299972, 97.499977, -41.800029, 1.000000, 1.103000, 1.000000);
					case 60: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.503997, -0.063999, 0.057999, 14.700007, 94.699188, 69.999946, 1.216001, 0.904998, 0.897999);
					case 61: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.544999, -0.028000, -0.012000, 4.600010, 88.899948, 92.300010, 1.185001, 1.053999, 0.980999);
					case 63: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.660997, -0.012999, 0.014999, 14.700007, 90.999237, 73.699989, 0.969001, 0.846998, 1.101999);
					case 64: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.562998, -0.017000, -0.020000, 9.400007, 88.799629, 84.200057, 1.085000, 0.946999, 0.991999);
					case 66: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.473997, -0.038999, 0.024999, 14.700007, 90.999153, 72.399917, 1.202000, 0.885998, 0.897999);
					case 68: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.471997, -0.025999, 0.013999, 14.700007, 89.999099, 74.899879, 1.257003, 0.867996, 0.889999);
					case 69: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.497997, -0.053999, -0.025000, 14.700007, 88.899177, 82.099906, 1.338001, 1.003998, 0.897999); 
					case 70: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.564999, -0.032000, -0.034999, 138.099975, 93.799995, -45.400062, 1.000000, 1.103000, 1.000000);
					case 72: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.561999, -0.035000, -0.036999, 138.099975, 93.799995, -45.400062, 1.000000, 1.103000, 1.000000);
					case 73: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.560998, -0.000000, -0.006000, 12.600004, 88.899993, 76.600082, 1.096001, 0.875997, 0.993000);
					case 75: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.638997, -0.100000, 0.029999, 14.700007, 90.999237, 73.699989, 1.592001, 1.148998, 1.066999);
					case 79: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.591997, -0.037000, -0.034000, 13.800005, 86.699501, 79.600036, 1.248000, 1.111000, 1.020999);
					case 80: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.638997, -0.034000, 0.021999, 14.700007, 90.999237, 73.699989, 1.054001, 0.915998, 1.066999);
					case 82: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.481997, -0.038999, -0.009000, 14.700007, 89.399177, 79.399932, 1.238002, 0.971997, 0.897999);
					case 84: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.540000, -0.068000, -0.032999, 138.099975, 93.799995, -45.400062, 1.000000, 1.103000, 1.000000);
					case 96: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.563000, -0.041000, -0.039999, 138.099975, 93.799995, -45.400062, 1.000000, 1.103000, 1.000000);
					case 98: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.558000, -0.048000, -0.036999, 138.099975, 93.799995, -45.400062, 1.000000, 1.103000, 1.000000);
					case 100: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.552998, -0.010000, -0.027000, 9.400005, 88.199478, 83.800018, 1.085000, 1.032000, 0.986999);
					case 101: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.566000, -0.061000, -0.034999, 138.099975, 93.799995, -45.400062, 1.000000, 1.103000, 1.000000);
					case 102: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.571999, -0.055000, -0.038999, 138.099975, 93.799995, -45.400062, 1.000000, 1.103000, 1.000000);
					case 103: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.576999, -0.042000, -0.035999, 138.099975, 93.799995, -45.400062, 1.000000, 1.103000, 1.000000);
					case 104: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.576999, -0.042000, -0.035999, 138.099975, 93.799995, -45.400062, 1.000000, 1.103000, 1.000000);
					case 105: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.562999, -0.033000, -0.033999, 138.099975, 93.799995, -45.400062, 1.000000, 1.103000, 1.000000);
					case 106: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.547000, -0.035000, -0.038999, 138.099975, 93.799995, -45.400062, 1.000000, 1.103000, 1.000000);
					case 107: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.561999, -0.038000, -0.031999, 138.099975, 93.799995, -45.400062, 1.000000, 1.103000, 1.000000);
					case 108: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.557999, -0.021000, -0.031999, 138.099975, 93.799995, -45.400062, 1.000000, 1.103000, 1.000000);
					case 109: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.574999, -0.029000, -0.038999, 138.099975, 93.799995, -45.400062, 1.000000, 1.103000, 1.000000);
					case 110: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.564000, -0.047000, -0.036999, 138.099975, 93.799995, -45.400062, 1.000000, 1.103000, 1.000000);
					case 116: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.558000, -0.046000, -0.034999, 138.099975, 93.799995, -45.400062, 1.000000, 1.103000, 1.000000);
					case 111: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.558999, 0.001999, -0.063000, 0.000000, 85.499816, 96.799972, 0.990999, 0.882000, 1.000000);
					case 112: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.569999, -0.040000, -0.065000, 0.000000, 85.499816, 96.799972, 1.199000, 0.975000, 1.000000);
					case 133: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.572999, -0.037000, -0.034999, 138.099975, 93.799995, -45.400062, 1.000000, 1.103000, 1.000000);
					case 134: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.581997, -0.025000, -0.040000, 13.800005, 86.699501, 79.600036, 1.248000, 1.111000, 1.020999);
					case 135: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.582997, -0.044999, 0.053999, 13.200003, 93.699333, 72.500030, 1.248000, 1.111000, 1.020999);
					case 136: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.578997, -0.044000, -0.041000, 13.800005, 86.699501, 79.600036, 1.248000, 1.111000, 1.020999);
					case 141: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.558000, -0.062000, -0.069999, 137.299972, 97.499977, -41.800029, 1.000000, 1.103000, 1.000000);
					case 148: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.569999, -0.047000, -0.027999, 138.099975, 93.799995, -45.400062, 1.000000, 1.103000, 1.000000);
					case 151: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.589997, -0.038999, -0.008000, 13.200003, 89.799247, 73.699989, 1.248000, 1.004998, 1.020999);
					case 152: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.611996, -0.037999, 0.013999, 13.200003, 89.799247, 73.699989, 1.248000, 1.004998, 1.020999);
					case 155: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.578997, -0.035000, 0.017999, 13.200003, 91.999221, 73.699989, 1.248000, 1.004998, 1.020999);
					case 163: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.563000, -0.041000, -0.039999, 138.099975, 93.799995, -45.400062, 1.000000, 1.103000, 1.000000);
					case 164: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.525000, -0.067000, -0.078999, 137.299972, 98.299964, -38.400028, 1.000000, 1.103000, 1.000000);
					case 165: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.563000, -0.069000, -0.077999, 137.299972, 97.499977, -41.800029, 1.000000, 1.103000, 1.000000);
					case 166: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.557000, -0.008000, -0.039999, 138.099975, 93.799995, -45.400062, 1.000000, 1.103000, 1.000000);
					case 167: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.576997, -0.045999, 0.006999, 13.200003, 89.799247, 73.699989, 1.248000, 1.004998, 1.020999);
					case 172: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.564999, -0.044000, -0.036999, 138.099975, 93.799995, -45.400062, 1.000000, 1.103000, 1.000000);
					case 173: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.563000, -0.041000, -0.039999, 138.099975, 93.799995, -45.400062, 1.000000, 1.103000, 1.000000);
					case 174: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.590999, -0.059000, -0.033999, 138.099975, 93.799995, -45.400062, 1.000000, 1.103000, 1.000000);
					case 175: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.564999, -0.044000, -0.036999, 138.099975, 93.799995, -45.400062, 1.000000, 1.103000, 1.000000);
					case 181: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.566998, -0.026000, -0.007000, 9.400005, 89.599594, 84.200035, 1.085000, 1.032000, 0.986999);
					case 186: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.547000, -0.064000, -0.034999, 138.099975, 93.799995, -45.400062, 1.000000, 1.103000, 1.000000);
					case 187: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.558000, -0.062000, -0.072999, 137.299972, 97.499977, -41.800029, 1.000000, 1.103000, 1.000000);
					case 188: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.566000, -0.024000, -0.024999, 138.099975, 93.799995, -45.400062, 1.000000, 1.103000, 1.000000);
					case 191: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.555000, 0.006000, -0.011000, 11.900001, 89.099983, 85.200012, 0.962000, 1.037999, 0.986000);
					case 198: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.590997, -0.033000, -0.046000, 13.800005, 86.699501, 79.600036, 1.248000, 1.111000, 1.020999);
					case 202: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.566000, -0.033000, -0.034999, 138.099975, 93.799995, -45.400062, 1.000000, 1.103000, 1.000000);
					case 211: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.584999, -0.038000, -0.036999, 138.099975, 93.799995, -45.400062, 1.000000, 1.103000, 1.000000);
					case 225: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.594997, -0.037000, -0.042000, 13.800005, 86.699501, 79.600036, 1.248000, 1.111000, 1.020999);
					case 231: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.594997, -0.043000, -0.042000, 13.800005, 86.699501, 79.600036, 1.248000, 1.111000, 1.020999);
					case 232: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.623997, -0.051999, -0.048000, 13.800005, 85.399398, 75.700035, 1.248000, 1.111000, 1.020999);
					case 234: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.603996, -0.013999, -0.036000, 13.800005, 85.599388, 75.800064, 1.248000, 1.111000, 1.020999);
					case 235: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.583997, -0.018999, 0.032999, 12.300001, 91.699340, 75.800064, 1.248000, 1.111000, 1.020999);
					case 236: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.591997, -0.045999, 0.034999, 12.300001, 91.699340, 75.800064, 1.248000, 1.111000, 1.020999);
					case 239: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.581997, -0.056999, -0.013000, 13.200003, 87.799270, 72.600006, 1.248000, 1.111000, 1.020999);
					case 247: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.559998, -0.030000, -0.000000, 4.100010, 89.699882, 84.900093, 1.155001, 0.987999, 0.980999);
					case 248: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.564998, -0.022000, -0.021000, 9.400007, 88.799629, 84.200057, 1.085000, 0.946999, 0.991999);
					case 254: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.546999, -0.040999, -0.021000, 4.600010, 88.899948, 92.300010, 1.185001, 1.053999, 0.980999);
					case 255: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.563998, -0.018999, -0.005000, 4.600010, 89.299942, 84.000045, 1.304003, 0.917999, 1.000999);
					case 263: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.622997, -0.080000, 0.023999, 14.700007, 90.999237, 73.699989, 1.592001, 1.413998, 1.066999);
					case 266: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.543999, -0.059000, -0.057999, 137.299972, 97.499977, -41.800029, 1.000000, 1.103000, 1.000000);
					case 268: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.571997, 0.002999, -0.033000, 13.200003, 85.599258, 73.699989, 1.169000, 0.843998, 0.992999);
					case 275: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.572999, -0.037000, -0.034999, 138.099975, 93.799995, -45.400062, 1.000000, 1.103000, 1.000000);
					case 276: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.572999, -0.037000, -0.034999, 138.099975, 93.799995, -45.400062, 1.000000, 1.103000, 1.000000);
					case 280: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.566999, -0.044000, -0.076999, 137.299972, 98.400024, -41.800029, 1.000000, 1.103000, 1.000000);
					case 282: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.550999, -0.059000, -0.072999, 137.299972, 97.499977, -41.800029, 1.000000, 1.103000, 1.000000);
					case 283: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.559999, -0.077999, -0.090000, 137.299972, 98.900016, -38.300048, 1.000000, 1.103000, 1.000000);
					case 284: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.579999, -0.059000, -0.066999, 137.299972, 97.499977, -41.800029, 1.000000, 1.103000, 1.000000);
					case 285: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.550000, -0.023000, -0.050999, 137.299972, 97.499977, -41.800029, 1.000000, 1.103000, 1.000000);
					case 287: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.562999, 0.004000, -0.019000, 7.500001, 88.899993, 87.100013, 1.002000, 0.935999, 0.987999);
					case 295: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.575998, -0.037000, -0.027000, 12.600004, 88.599998, 80.400039, 1.147002, 1.025997, 1.008000);
					default: SendInf(playerid, "Маска не будет отображена на данной одежде");
				}
			}
			case 10975: // Маска mask7
			{
				switch(skin)
				{
					case 8: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.566000, 0.035999, -0.016999, -13.899999, 87.900100, 105.899971, 0.713000, 0.934997, 1.000000);
					case 9: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.569000, 0.006999, -0.045999, -13.899999, 85.800148, 105.899971, 0.713000, 0.814999, 1.000000);
					case 13: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.573000, 0.022999, -0.041000, -13.899999, 86.799949, 105.899971, 0.713000, 0.904995, 1.000000);
					case 17: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.555000, 0.020999, -0.036000, -13.899999, 86.699951, 105.899971, 0.713000, 0.863996, 1.000000);
					case 27: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.587999, 0.030999, -0.027000, -13.899999, 87.799942, 105.899971, 0.713000, 0.927995, 1.000000);
					case 30: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.569000, 0.037999, -0.056999, -13.899999, 85.000160, 105.899971, 0.713000, 0.900999, 1.000000);
					case 31: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.558000, 0.013999, -0.060999, -13.899999, 84.400146, 105.899971, 0.713000, 0.869999, 1.000000);
					case 34: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.595000, 0.031999, -0.033999, -13.899999, 87.900100, 105.899971, 0.713000, 0.875997, 1.000000);
					case 39: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.582999, 0.032999, -0.028999, -13.899999, 87.400131, 105.899971, 0.713000, 0.974999, 1.000000);
					case 46: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.575000, 0.031999, -0.010000, -13.899999, 89.100036, 105.899971, 0.713000, 0.894997, 1.000000);
					case 51: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.560000, 0.000999, -0.033000, -13.899999, 87.300056, 105.899971, 0.713000, 0.890998, 1.000000);
					case 52: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.550000, 0.042999, -0.013000, -13.899999, 88.300048, 105.899971, 0.713000, 0.819997, 1.000000);
					case 54: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.552000, 0.021999, -0.031000, -13.899999, 86.699951, 105.899971, 0.713000, 1.016996, 1.000000);
					case 57: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.554000, 0.004999, -0.030000, -13.899999, 87.300056, 105.899971, 0.713000, 0.857996, 1.000000);
					case 58: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.551000, 0.030999, -0.018000, -13.899999, 87.800056, 105.899971, 0.713000, 0.887996, 1.000000);
					case 59: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.579000, 0.041999, -0.040000, -13.899999, 86.699951, 105.899971, 0.713000, 0.863996, 1.000000);
					case 60: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.563000, -0.000000, -0.077000, -13.899999, 83.300094, 105.899971, 0.713000, 0.920998, 1.000000);
					case 61: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.554000, -0.018000, -0.049999, -13.899999, 84.100173, 105.899971, 1.000000, 0.966998, 1.000000); 
					case 63: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.584000, 0.016999, -0.027999, -13.899999, 87.900100, 105.899971, 0.713000, 0.854997, 1.000000);
					case 64: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.558000, 0.015999, -0.060999, -13.899999, 84.400146, 105.899971, 0.713000, 0.869999, 1.000000);
					case 66: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.548000, 0.026999, -0.027000, -13.899999, 87.300056, 105.899971, 0.713000, 0.825998, 1.000000);
					case 68: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.540000, 0.033999, -0.019000, -13.899999, 87.800056, 105.899971, 0.713000, 0.909996, 1.000000);
					case 69: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.568000, 0.013999, -0.038000, -13.899999, 86.500068, 105.899971, 0.713000, 1.000997, 1.000000);
					case 70: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.569000, 0.032999, -0.021999, -13.899999, 87.900100, 105.899971, 0.713000, 0.932998, 1.000000);
					case 72: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.566000, 0.023999, -0.044000, -13.899999, 86.799949, 105.899971, 0.713000, 0.950995, 1.000000);
					case 73: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.548000, -0.009000, -0.062999, -13.899999, 84.100173, 105.899971, 1.000000, 0.947996, 1.000000);
					case 75: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.605999, 0.018999, -0.014999, -13.899999, 87.900100, 105.899971, 0.713000, 0.934997, 1.000000);
					case 79: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.582999, 0.024999, -0.041999, -13.899999, 85.800148, 105.899971, 0.713000, 1.019999, 1.000000); 
					case 80: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.601999, 0.019999, -0.017999, -13.899999, 87.900100, 105.899971, 0.713000, 0.934997, 1.000000);
					case 82: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.554000, 0.035999, -0.021000, -13.899999, 87.800056, 105.899971, 0.713000, 0.839996, 1.000000);
					case 84: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.552999, 0.003999, -0.037000, -13.899999, 86.799949, 105.899971, 0.713000, 0.913995, 1.000000);
					case 98: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.560999, 0.014999, -0.037000, -13.899999, 86.799949, 105.899971, 0.713000, 0.821995, 1.000000);
					case 100: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.569000, 0.039999, -0.048999, -13.899999, 85.800148, 105.899971, 0.713000, 0.942999, 1.000000);
					case 101: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.578999, 0.013999, -0.040000, -13.899999, 86.799949, 105.899971, 0.713000, 0.929995, 1.000000);
					case 102: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.581000, 0.009999, -0.040000, -13.899999, 86.799949, 105.899971, 0.713000, 0.894996, 1.000000);
					case 103: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.586999, 0.026999, -0.035000, -13.899999, 86.799949, 105.899971, 0.713000, 0.868996, 1.000000);
					case 104: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.578000, 0.010999, -0.033000, -13.899999, 86.799949, 105.899971, 0.713000, 0.868996, 1.000000);
					case 105: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.567000, 0.034999, -0.034000, -13.899999, 86.799949, 105.899971, 0.713000, 0.868996, 1.000000);
					case 106: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.557000, 0.028999, -0.042000, -13.899999, 86.799949, 105.899971, 0.713000, 0.893996, 1.000000);
					case 107: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.570999, 0.033999, -0.037000, -13.899999, 86.799949, 105.899971, 0.713000, 0.893996, 1.000000);
					case 108: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.563999, 0.047999, -0.036000, -13.899999, 86.799949, 105.899971, 0.713000, 0.931996, 1.000000);
					case 109: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.578999, 0.036999, -0.041000, -13.899999, 86.799949, 105.899971, 0.713000, 0.931996, 1.000000);
					case 110: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.570999, 0.021999, -0.035000, -13.899999, 86.799949, 105.899971, 0.713000, 0.931996, 1.000000);
					case 116: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.557999, 0.014999, -0.034000, -13.899999, 86.799949, 105.899971, 0.713000, 0.806996, 1.000000);
					case 111: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.575000, 0.039999, -0.009000, -13.899999, 89.100036, 105.899971, 0.713000, 0.907997, 1.000000);
					case 112: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.575000, 0.033999, -0.009000, -13.899999, 89.100036, 105.899971, 0.713000, 0.866997, 1.000000);
					case 133: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.587000, 0.028999, -0.023999, -13.899999, 87.900100, 105.899971, 0.713000, 0.979997, 1.000000);
					case 134: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.571999, 0.031999, -0.023999, -13.899999, 87.400131, 105.899971, 0.713000, 0.974999, 1.000000);
					case 135: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.573000, 0.028999, -0.028999, -13.899999, 87.400131, 105.899971, 0.713000, 0.940997, 1.000000);
					case 136: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.571999, 0.021999, -0.029999, -13.899999, 87.400131, 105.899971, 0.713000, 0.983999, 1.000000);
					case 141: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.579000, 0.029999, -0.032000, -13.899999, 86.699951, 105.899971, 0.713000, 0.863996, 1.000000);
					case 148: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.563000, 0.019999, -0.022999, -13.899999, 87.900100, 105.899971, 0.713000, 0.895997, 1.000000);
					case 151: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.569000, 0.030999, -0.047999, -13.899999, 87.400131, 105.899971, 0.713000, 0.887997, 1.000000);
					case 152: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.609000, 0.024999, -0.023999, -13.899999, 87.400131, 105.899971, 0.713000, 0.887997, 1.000000);
					case 155: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.559000, 0.038999, -0.044999, -13.899999, 87.400131, 105.899971, 0.713000, 0.887997, 1.000000);
					case 163: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.554999, 0.021999, -0.041000, -13.899999, 86.799949, 105.899971, 0.713000, 0.940995, 1.000000);
					case 164: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.558000, 0.039999, -0.035000, -13.899999, 86.699951, 105.899971, 0.713000, 0.918996, 1.000000);
					case 165: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.587000, 0.022999, -0.044000, -13.899999, 86.699951, 105.899971, 0.713000, 0.851996, 1.000000);
					case 167: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.553000, 0.021999, -0.029999, -13.899999, 87.400131, 105.899971, 0.713000, 0.887997, 1.000000);
					case 172: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.565000, 0.023999, -0.039000, -13.899999, 86.799949, 105.899971, 0.713000, 0.893995, 1.000000);
					case 174: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.601999, 0.006999, -0.036000, -13.899999, 86.799949, 105.899971, 0.713000, 0.940995, 1.000000);
					case 175: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.564000, 0.016999, -0.038000, -13.899999, 86.799949, 105.899971, 0.713000, 0.858996, 1.000000);
					case 181: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.569000, 0.025999, -0.045999, -13.899999, 85.800148, 105.899971, 0.713000, 0.885999, 1.000000);
					case 186: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.551999, 0.004999, -0.036000, -13.899999, 86.799949, 105.899971, 0.713000, 0.929995, 1.000000);
					case 187: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.572000, 0.031999, -0.043000, -13.899999, 86.699951, 105.899971, 0.713000, 0.931995, 1.000000);
					case 188: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.566999, 0.041999, -0.027000, -13.899999, 86.799949, 105.899971, 0.713000, 0.945995, 1.000000);
					case 191: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.548999, -0.005000, -0.059000, -13.899999, 84.100173, 105.899971, 1.000000, 1.025998, 1.000000);
					case 198: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.582999, 0.014999, -0.049999, -13.899999, 85.800148, 105.899971, 0.713000, 1.019999, 1.000000);
					case 202: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.572999, 0.035999, -0.036000, -13.899999, 86.799949, 105.899971, 0.713000, 0.929995, 1.000000);
					case 211: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.582999, 0.025999, -0.037000, -13.899999, 86.799949, 105.899971, 0.713000, 0.904995, 1.000000);
					case 225: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.571999, 0.020999, -0.026999, -13.899999, 87.400131, 105.899971, 0.713000, 0.917000, 1.000000);
					case 231: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.565000, 0.018999, -0.022999, -13.899999, 87.400131, 105.899971, 0.713000, 0.917000, 1.000000);
					case 232: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.599000, 0.008999, -0.028999, -13.899999, 87.400131, 105.899971, 0.713000, 0.787999, 1.000000);
					case 234: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.581000, 0.044999, -0.023999, -13.899999, 87.400131, 105.899971, 0.713000, 0.903998, 1.000000);
					case 235: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.581000, 0.021999, -0.019999, -13.899999, 87.400131, 105.899971, 0.713000, 0.979998, 1.000000);
					case 236: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.581000, 0.024999, -0.019999, -13.899999, 87.400131, 105.899971, 0.713000, 0.913998, 1.000000);
					case 239: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.560000, 0.014999, -0.034999, -13.899999, 87.400131, 105.899971, 0.713000, 0.887997, 1.000000);
					case 247: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.570000, 0.019999, -0.060999, -13.899999, 84.200149, 105.899971, 0.713000, 0.953998, 1.000000);
					case 248: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.558000, 0.017999, -0.059999, -13.899999, 84.400146, 105.899971, 0.713000, 0.869999, 1.000000);
					case 254: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.554000, 0.018999, -0.055999, -13.899999, 84.700157, 105.899971, 0.713000, 0.841999, 1.000000);
					case 255: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.554000, 0.006999, -0.070999, -13.899999, 84.100173, 105.899971, 1.000000, 1.024999, 1.000000);
					case 266: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.562000, 0.038999, -0.034000, -13.899999, 86.199958, 105.899971, 0.713000, 0.905996, 1.000000);
					case 268: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.566000, 0.043999, -0.023999, -13.899999, 87.400131, 105.899971, 0.713000, 0.887997, 1.000000);
					case 274: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.562000, -0.003999, -0.074999, 8.300006, 83.399948, 84.800079, 1.000000, 1.000000, 1.000000);
					case 275: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.578000, 0.036999, -0.026999, -13.899999, 87.900100, 105.899971, 0.713000, 0.885998, 1.000000);
					case 276: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.575000, 0.032999, -0.022999, -13.899999, 87.900100, 105.899971, 0.713000, 0.852998, 1.000000);
					case 280: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.597999, 0.056999, -0.013000, -13.899999, 89.100036, 105.899971, 0.713000, 0.940996, 1.000000);
					case 283: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.583000, 0.027999, -0.013000, -13.899999, 89.100036, 105.899971, 0.713000, 0.940996, 1.000000);
					case 284: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.590000, 0.025999, -0.057000, -13.899999, 84.800010, 105.899971, 0.713000, 0.863997, 1.000000);
					case 285: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.578000, 0.064999, -0.020000, -13.899999, 86.699951, 105.899971, 0.713000, 0.925996, 1.000000);
					case 287: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.548999, 0.000999, -0.064000, -13.899999, 84.100173, 105.899971, 1.000000, 0.912998, 1.000000);
					case 295: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.576000, -0.022000, -0.072999, -13.899999, 84.100173, 105.899971, 1.000000, 0.943999, 1.000000);
					default: SendInf(playerid, "Маска не будет отображена на данной одежде");
				}
			}
			case 10976: // Маска mask8
			{
				switch(skin)
				{
					case 8: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.556000, 0.000999, 0.005000, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 9: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.512000, -0.014000, -0.001999, 85.999923, 90.199867, 5.900000, 0.922001, 0.865999, 0.924000);
					case 13: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.562999, -0.005000, -0.009999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 17: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.526000, -0.017000, -0.000999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 27: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.568999, -0.001000, -0.002999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 30: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.547000, 0.020999, -0.002999, 80.799942, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 31: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.547000, 0.011999, -0.002999, 80.799942, 88.599884, 6.100000, 1.000000, 0.891999, 0.960999);
					case 34: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.594999, -0.003000, -0.011999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 39: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.526999, 0.017999, -0.006999, 85.999923, 90.199867, 5.900000, 0.922001, 0.865999, 0.924000);
					case 46: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.556000, -0.008000, -0.002999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 51: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.531999, -0.027000, -0.003999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 52: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.498999, 0.021999, 0.001000, 85.999923, 90.199867, 5.900000, 0.922001, 0.865999, 0.924000);
					case 54: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.531999, 0.002999, 0.003000, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 57: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.523999, -0.029000, -0.001999, 85.999923, 90.199867, 5.900000, 0.943000, 0.928998, 0.974999);
					case 58: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.523999, 0.004999, 0.002000, 85.999923, 90.199867, 5.900000, 0.943000, 0.928998, 0.974999);
					case 59: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.545999, 0.004999, -0.004999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 60: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.540000, -0.014000, -0.002999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 61: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.547000, 0.026999, 0.010000, 80.799942, 88.599884, 6.100000, 1.000000, 0.891999, 0.960999);
					case 63: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.567000, -0.016000, -0.007999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 64: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.547000, 0.011999, -0.002999, 80.799942, 88.599884, 6.100000, 1.000000, 0.891999, 0.960999);
					case 66: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.504999, -0.011000, 0.000000, 85.999923, 90.199867, 5.900000, 1.000000, 1.014998, 0.980999);
					case 68: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.477999, 0.014999, 0.004000, 85.999923, 90.199867, 5.900000, 0.922001, 0.865999, 0.924000);
					case 69: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.546000, -0.005000, -0.002999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 70: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.526000, 0.005999, -0.002999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 72: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.546999, -0.005000, -0.010999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 73: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.476000, -0.031999, 0.053999, 48.399909, 97.400192, 34.699974, 0.981000, 0.872999, 0.869999);
					case 75: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.570000, -0.009000, 0.004000, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 79: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.512000, 0.008999, 0.001000, 85.999923, 90.199867, 5.900000, 0.922001, 0.865999, 0.924000);
					case 80: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.555000, -0.016000, 0.005000, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 82: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.497999, 0.011999, 0.002000, 85.999923, 90.199867, 5.900000, 0.922001, 0.865999, 0.924000);
					case 84: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.531999, -0.025000, -0.002999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 98: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.510000, -0.008000, 0.001000, 85.999923, 90.199867, 5.900000, 0.922001, 0.865999, 0.924000);
					case 100: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.536000, 0.013999, -0.000999, 80.799942, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 101: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.529999, -0.008000, -0.004999, 85.999923, 90.199867, 5.900000, 0.922001, 0.865999, 0.924000);
					case 102: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.525000, -0.001000, -0.002999, 85.999923, 90.199867, 5.900000, 0.922001, 0.865999, 0.92400);
					case 103: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.525000, -0.001000, -0.002999, 85.999923, 90.199867, 5.900000, 0.922001, 0.865999, 0.924000);
					case 104: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.525000, -0.001000, -0.002999, 85.999923, 90.199867, 5.900000, 0.922001, 0.865999, 0.924000);
					case 105: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.506000, -0.001000, -0.000999, 85.999923, 90.199867, 5.900000, 0.922001, 0.865999, 0.924000);
					case 106: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.505000, -0.001000, -0.006999, 85.999923, 90.199867, 5.900000, 0.922001, 0.865999, 0.924000);
					case 107: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.511000, 0.019999, -0.007999, 85.999923, 90.199867, 5.900000, 0.922001, 0.865999, 0.924000);
					case 108: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.504000, 0.022999, -0.001999, 85.999923, 90.199867, 5.900000, 0.922001, 0.865999, 0.924000);
					case 109: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.518000, 0.010999, -0.008999, 85.999923, 90.199867, 5.900000, 0.922001, 0.865999, 0.924000);
					case 110: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.518000, 0.010999, -0.005999, 85.999923, 90.199867, 5.900000, 0.922001, 0.865999, 0.924000);
					case 111: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.528000, 0.000999, -0.001999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 112: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.550000, -0.002000, -0.001999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 116: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.510000, -0.008000, 0.001000, 85.999923, 90.199867, 5.900000, 0.922001, 0.865999, 0.924000);
					case 133: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.555000, 0.009999, -0.003999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 134: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.510000, 0.012999, -0.003999, 85.999923, 90.199867, 5.900000, 0.922001, 0.865999, 0.924000);
					case 135: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.521000, 0.008999, -0.000999, 85.999923, 90.199867, 5.900000, 0.922001, 0.865999, 0.924000);
					case 136: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.507000, 0.001999, -0.001999, 85.999923, 90.199867, 5.900000, 0.922001, 0.865999, 0.924000);
					case 141: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.545999, 0.004999, -0.004999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 148: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.543000, -0.004000, -0.000999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 151: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.536000, -0.004000, -0.022999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 152: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.573000, -0.004000, -0.000999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 155: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.532000, 0.003999, -0.023999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 163: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.524999, -0.003000, -0.006999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 164: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.534999, 0.002999, 0.001000, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 165: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.553999, -0.011000, -0.008999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 167: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.535000, -0.016000, -0.006999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 172: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.541999, -0.015000, -0.007999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 173: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.561999, -0.003000, -0.006999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 174: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.561999, -0.015000, -0.006999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 175: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.531999, -0.015000, -0.005999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 181: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.560999, -0.000000, 0.000000, 80.799942, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 186: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.530999, -0.020000, -0.001999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 187: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.545999, 0.002999, -0.008999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 188: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.543999, 0.013999, 0.005000, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 191: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.554999, -0.040999, 0.057999, 47.799919, 96.700218, 39.199981, 1.000000, 1.000000, 1.000000);
					case 198: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.526999, 0.017999, -0.006999, 85.999923, 90.199867, 5.900000, 0.922001, 0.865999, 0.924000);
					case 202: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.552999, 0.002999, -0.001999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 211: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.554999, -0.013000, -0.002999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 225: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.527999, 0.001999, -0.000999, 85.999923, 90.199867, 5.900000, 0.922001, 0.865999, 0.924000);
					case 231: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.518000, 0.001999, 0.004000, 85.999923, 90.199867, 5.900000, 0.922001, 0.865999, 0.924000);
					case 232: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.559999, -0.002000, 0.004000, 85.999923, 90.199867, 5.900000, 0.922001, 0.865999, 0.924000);
					case 234: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.515000, 0.026999, 0.002000, 85.999923, 90.199867, 5.900000, 0.922001, 0.865999, 0.924000);
					case 235: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.512000, 0.003999, 0.009000, 85.999923, 90.199867, 5.900000, 0.922001, 0.865999, 0.924000);
					case 236: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.545000, 0.003999, 0.009000, 85.999923, 90.199867, 5.900000, 0.922001, 0.865999, 0.924000);
					case 239: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.503001, -0.006000, -0.007999, 85.999923, 90.199867, 5.900000, 0.922001, 0.865999, 0.924000);
					case 247: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.547000, 0.014999, -0.001999, 80.799942, 88.599884, 6.100000, 1.000000, 0.891999, 0.960999); 
					case 248: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.547000, 0.011999, -0.002999, 80.799942, 88.599884, 6.100000, 1.000000, 0.891999, 0.960999);
					case 254: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.547000, 0.014999, 0.004000, 80.799942, 88.599884, 6.100000, 1.000000, 0.891999, 0.960999);
					case 255: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.547000, 0.046999, -0.005999, 80.799942, 88.599884, 6.100000, 1.000000, 0.891999, 0.960999);
					case 263: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.570000, 0.013999, -0.009999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 266: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.529999, 0.008999, 0.006000, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 268: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.532000, 0.023999, 0.005000, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 274: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.547000, -0.012000, -0.002999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 275: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.547000, -0.000000, -0.006999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 276: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.547000, -0.001000, -0.002999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 280: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.569999, 0.014999, -0.002999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 282: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.550999, -0.013000, -0.007999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 283: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.553000, -0.008000, -0.007999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 284: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.569999, 0.014999, -0.002999, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 285: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.546999, 0.031999, 0.015000, 85.999923, 90.199867, 5.900000, 1.000000, 0.891999, 0.960999);
					case 287: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.577999, -0.046999, 0.053999, 47.799919, 96.700218, 39.199981, 1.000000, 1.000000, 1.000000);
					case 295: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.547000, 0.003999, -0.004999, 76.599914, 89.799980, 6.699998, 1.000000, 0.891999, 0.975000);
					default: SendInf(playerid, "Маска не будет отображена на данной одежде");
				}
			}
			case 10977: // Маска mask9
			{
				switch(skin)
				{
					case 8: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.550999, 0.086001, -0.038000, 65.699920, 80.100013, 31.399976, 1.170001, 1.238002, 1.027000);
					case 9: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.531000, 0.084000, -0.054000, 65.699920, 80.100013, 31.399976, 1.017000, 1.269001, 1.000000);
					case 13: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.557999, -0.102997, -0.058000, -59.399951, 81.499977, 143.600021, 1.294014, 1.213003, 1.000000);
					case 17: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.526998, -0.093999, -0.048000, -59.399951, 81.499977, 143.600021, 1.040006, 1.115003, 1.000000);
					case 27: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.557999, -0.102997, -0.058000, -59.399951, 81.499977, 143.600021, 1.294014, 1.213003, 1.000000);
					case 30: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.562999, 0.112000, -0.054000, 65.699920, 80.100013, 31.399976, 1.107001, 1.164000, 1.000000);
					case 31: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.556999, 0.104999, -0.054000, 65.699920, 80.100013, 31.399976, 1.000000, 1.000000, 1.000000);
					case 39: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.573999, 0.105000, -0.054000, 65.699920, 80.100013, 31.399976, 1.009002, 1.180001, 0.997999);
					case 46: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.540998, -0.082999, -0.047000, -59.399951, 81.499977, 143.600021, 0.999000, 1.045001, 1.000000);
					case 51: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.547000, 0.082001, -0.059000, 63.599910, 80.100013, 31.399976, 1.015008, 1.192000, 1.027000);
					case 52: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.519999, -0.079999, -0.041000, -59.399951, 81.499977, 143.600021, 1.244999, 1.045001, 1.000000);
					case 54: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.516998, -0.093998, -0.045000, -59.399951, 81.499977, 143.600021, 1.238010, 1.213003, 1.000000);
					case 57: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.519000, 0.051001, -0.065000, 55.799953, 80.100013, 31.399976, 1.098009, 1.241001, 1.027000);
					case 58: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.519000, 0.090001, -0.065000, 55.799953, 80.100013, 31.399976, 1.098009, 1.241001, 1.027000);
					case 59: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.527998, -0.085999, -0.052000, -59.399951, 81.499977, 143.600021, 1.344007, 1.115003, 1.000000);
					case 60: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.535999, 0.083001, -0.059000, 63.599910, 80.100013, 31.399976, 1.158005, 1.382002, 1.027000);
					case 61: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.545999, 0.112999, -0.044000, 65.699920, 80.100013, 31.399976, 1.000000, 1.000000, 1.000000);
					case 64: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.556999, 0.120000, -0.054000, 65.699920, 80.100013, 31.399976, 1.000000, 1.000000, 1.000000);
					case 66: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.531000, 0.093001, -0.059000, 63.599910, 80.100013, 31.399976, 1.113008, 1.192000, 1.027000);
					case 68: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.515999, -0.079999, -0.040000, -59.399951, 81.499977, 143.600021, 1.244999, 1.045001, 1.000000);
					case 69: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.596999, 0.067001, -0.059000, 63.599910, 80.100013, 31.399976, 1.167008, 1.192000, 1.027000);
					case 70: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.535999, 0.083001, -0.059000, 63.599910, 80.100013, 31.399976, 1.158005, 1.382002, 1.027000);
					case 72: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.533998, -0.093998, -0.059000, -59.399951, 81.499977, 143.600021, 1.238010, 1.213003, 1.000000);
					case 73: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.562999, 0.123999, -0.048000, 65.699920, 80.100013, 31.399976, 1.000000, 1.000000, 1.000000);
					case 75: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.568998, 0.077001, -0.049000, 63.599910, 80.100013, 31.399976, 1.236005, 1.382002, 1.027000);
					case 80: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.577998, 0.064001, -0.049000, 63.599910, 80.100013, 31.399976, 1.236005, 1.382002, 1.027000);
					case 82: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.518000, -0.074999, -0.049000, -59.399951, 81.499977, 143.600021, 1.244999, 1.045001, 1.000000);
					case 84: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.517999, -0.117998, -0.046000, -59.399951, 81.499977, 143.600021, 1.085010, 1.213003, 1.000000);
					case 96: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.543999, -0.068998, -0.046000, -59.399951, 81.499977, 143.600021, 1.085010, 1.213003, 1.000000);
					case 98: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.533998, -0.107998, -0.055000, -59.399951, 81.499977, 143.600021, 1.193010, 1.213003, 1.000000);
					case 100: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.528000, 0.093000, -0.054000, 65.699920, 80.100013, 31.399976, 1.197002, 1.269001, 1.000000);
					case 101: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.536998, -0.113998, -0.052000, -59.399951, 81.499977, 143.600021, 1.193010, 1.213003, 1.000000);
					case 102: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.527998, -0.093998, -0.059000, -59.399951, 81.499977, 143.600021, 1.238010, 1.213003, 1.000000);
					case 103: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.536998, -0.081998, -0.053000, -59.399951, 81.499977, 143.600021, 1.238010, 1.213003, 1.000000);
					case 104: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.536998, -0.081998, -0.053000, -59.399951, 81.499977, 143.600021, 1.238010, 1.213003, 1.000000);
					case 105: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.523998, -0.102998, -0.053000, -59.399951, 81.499977, 143.600021, 1.238010, 1.213003, 1.000000);
					case 106: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.509998, -0.100998, -0.062000, -59.399951, 81.499977, 143.600021, 1.193010, 1.213003, 1.000000);
					case 107: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.521998, -0.094998, -0.047000, -59.399951, 81.499977, 143.600021, 1.193010, 1.213003, 1.000000);
					case 108: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.525998, -0.082998, -0.055000, -59.399951, 81.499977, 143.600021, 1.193010, 1.213003, 1.000000);
					case 109: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.537998, -0.093998, -0.055000, -59.399951, 81.499977, 143.600021, 1.193010, 1.213003, 1.000000);
					case 110: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.537998, -0.093998, -0.055000, -59.399951, 81.499977, 143.600021, 1.193010, 1.213003, 1.000000);
					case 116: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.533998, -0.107998, -0.055000, -59.399951, 81.499977, 143.600021, 1.193010, 1.213003, 1.000000);
					case 111: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.539998, -0.099999, -0.040000, -59.399951, 81.499977, 143.600021, 1.238000, 1.113002, 1.000000);
					case 112: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.531998, -0.105999, -0.046000, -59.399951, 81.499977, 143.600021, 1.238000, 1.113002, 1.000000);
					case 133: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.533998, 0.096001, -0.065000, 63.599910, 80.100013, 31.399976, 1.259005, 1.382002, 1.027000);
					case 134: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.573999, 0.105000, -0.054000, 65.699920, 80.100013, 31.399976, 1.029001, 1.180001, 1.027000);
					case 135: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.552999, 0.075001, -0.054000, 65.699920, 80.100013, 31.399976, 1.217001, 1.238002, 1.027000);
					case 136: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.563999, 0.088000, -0.058000, 65.699920, 80.100013, 31.399976, 1.029001, 1.180001, 1.027000);
					case 141: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.538998, -0.089998, -0.041000, -59.399951, 81.499977, 143.600021, 1.344007, 1.115003, 1.000000);
					case 148: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.553999, 0.068001, -0.061000, 63.599910, 80.100013, 31.399976, 1.236005, 1.382002, 1.027000);
					case 151: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.566999, 0.105001, -0.069000, 65.699920, 80.100013, 31.399976, 1.018001, 1.238002, 1.027000);
					case 152: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.587999, 0.114001, -0.055000, 65.699920, 80.100013, 31.399976, 1.018001, 1.238002, 1.027000);
					case 155: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.550999, 0.111001, -0.063000, 65.699920, 80.100013, 31.399976, 1.018001, 1.238002, 1.027000);
					case 163: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.512999, -0.092997, -0.059000, -59.399951, 81.499977, 143.600021, 1.196011, 1.213003, 1.000000);
					case 164: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.516998, -0.093998, -0.051000, -59.399951, 81.499977, 143.600021, 1.238010, 1.213003, 1.000000);
					case 165: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.530998, -0.098998, -0.059000, -59.399951, 81.499977, 143.600021, 1.238010, 1.213003, 1.000000);
					case 166: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.543999, -0.068998, -0.046000, -59.399951, 81.499977, 143.600021, 1.085010, 1.213003, 1.000000);
					case 167: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.550999, 0.111001, -0.063000, 65.699920, 80.100013, 31.399976, 1.018001, 1.238002, 1.027000);
					case 172: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.534999, -0.099997, -0.061000, -59.399951, 81.499977, 143.600021, 1.150014, 1.213003, 1.000000);
					case 173: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.512999, -0.092997, -0.059000, -59.399951, 81.499977, 143.600021, 1.196011, 1.213003, 1.000000);
					case 174: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.554999, -0.110997, -0.055000, -59.399951, 81.499977, 143.600021, 1.150014, 1.213003, 1.000000);
					case 175: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.531999, -0.096997, -0.061000, -59.399951, 81.499977, 143.600021, 1.150014, 1.213003, 1.000000);
					case 181: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.562999, 0.112000, -0.054000, 65.699920, 80.100013, 31.399976, 1.107001, 1.164000, 1.000000);
					case 186: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.517998, -0.119998, -0.051000, -59.399951, 81.499977, 143.600021, 1.085010, 1.213003, 1.000000);
					case 187: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.542998, -0.074998, -0.067000, -59.399951, 81.499977, 143.600021, 1.238010, 1.213003, 1.000000);
					case 188: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.525998, -0.072998, -0.046000, -59.399951, 81.499977, 143.600021, 1.085010, 1.213003, 1.000000);
					case 191: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.562999, 0.123999, -0.048000, 65.699920, 80.100013, 31.399976, 1.000000, 1.000000, 1.000000);
					case 198: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.573999, 0.079000, -0.054000, 65.699920, 80.100013, 31.399976, 1.206002, 1.338002, 1.000000);
					case 202: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.549998, -0.085998, -0.051000, -59.399951, 81.499977, 143.600021, 1.085010, 1.213003, 1.000000);
					case 211: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.557999, -0.102997, -0.058000, -59.399951, 81.499977, 143.600021, 1.294014, 1.213003, 1.000000);
					case 225: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.557999, 0.101000, -0.058000, 65.699920, 80.100013, 31.399976, 1.029001, 1.180001, 1.027000);
					case 231: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.560999, 0.101000, -0.052000, 65.699920, 80.100013, 31.399976, 1.029001, 1.180001, 1.027000);
					case 232: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.620999, 0.074000, -0.053000, 65.699920, 80.100013, 31.399976, 1.217001, 1.238002, 1.027000);
					case 234: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.567999, 0.108001, -0.061000, 65.699920, 80.100013, 31.399976, 1.217001, 1.238002, 1.027000);
					case 235: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.552999, 0.074001, -0.046000, 65.699920, 80.100013, 31.399976, 1.217001, 1.238002, 1.027000);
					case 236: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.552999, 0.089001, -0.041000, 65.699920, 80.100013, 31.399976, 1.217001, 1.238002, 1.027000);
					case 239: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.551999, 0.096001, -0.054000, 65.699920, 80.100013, 31.399976, 1.018001, 1.238002, 1.027000);
					case 247: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.559999, 0.101999, -0.051000, 65.699920, 80.100013, 31.399976, 1.000000, 1.000000, 1.000000);
					case 248: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.539999, 0.113999, -0.051000, 65.699920, 80.100013, 31.399976, 1.000000, 1.000000, 1.000000);
					case 254: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.550999, 0.117999, -0.051000, 65.699920, 80.100013, 31.399976, 1.000000, 1.000000, 1.000000);
					case 255: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.551999, 0.124999, -0.059000, 65.699920, 80.100013, 31.399976, 1.000000, 1.000000, 1.000000);
					case 263: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.561998, 0.100001, -0.049000, 65.699920, 80.100013, 31.399976, 1.453001, 1.382002, 1.027000);
					case 266: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.522998, -0.102999, -0.035000, -59.399951, 81.499977, 143.600021, 1.198002, 1.166003, 1.000000);
					case 268: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.551999, 0.119001, -0.054000, 65.699920, 80.100013, 31.399976, 1.018001, 1.238002, 1.027000); 
					case 275: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.565998, 0.105001, -0.071000, 63.599910, 80.100013, 31.399976, 1.079004, 1.382002, 1.027000);
					case 276: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.540998, 0.091001, -0.059000, 63.599910, 80.100013, 31.399976, 1.079004, 1.382002, 1.027000);
					case 280: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.579998, -0.079999, -0.046000, -59.399951, 81.499977, 143.600021, 1.238000, 1.113002, 1.000000);
					case 282: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.557998, -0.085999, -0.053000, -59.399951, 81.499977, 143.600021, 0.961000, 1.113002, 1.000000);
					case 283: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.567998, -0.103999, -0.046000, -59.399951, 81.499977, 143.600021, 1.238000, 1.113002, 1.000000);
					case 284: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.575998, -0.064999, -0.053000, -59.399951, 81.499977, 143.600021, 1.238000, 1.113002, 1.000000);
					case 285: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.521998, -0.072999, -0.023000, -59.399951, 81.499977, 143.600021, 1.250007, 1.115003, 1.000000);
					case 287: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.573999, 0.110999, -0.053000, 65.699920, 80.100013, 31.399976, 1.000000, 1.000000, 1.000000);
					case 295: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.551999, 0.096999, -0.058000, 65.699920, 80.100013, 31.399976, 1.000000, 1.000000, 1.000000);
					default: SendInf(playerid, "Маска не будет отображена на данной одежде");
				}
			}
			case 10978: // Маска mask10
			{
				switch(skin)
				{
					case 8: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.572000, 0.017000, -0.056000, 15.500001, 84.900047, 81.400032, 1.000000, 1.000000, 1.000000);
					case 9: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.572000, 0.012000, -0.057999, 15.500001, 84.900047, 76.000053, 0.869000, 0.848000, 1.000000);
					case 13: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.569000, 0.007999, -0.004999, 15.500001, 90.300041, 76.000053, 0.869000, 0.914999, 1.000000);
					case 17: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.554000, 0.005999, 0.003000, 15.500001, 90.300041, 76.000053, 0.869000, 0.914999, 1.000000);
					case 27: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.588000, 0.009999, -0.000999, 15.500001, 90.300041, 76.000053, 0.876000, 0.950999, 1.000000);
					case 30: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.567000, 0.024999, 0.001000, 15.500001, 90.300041, 76.000053, 0.876000, 0.922999, 1.000000);
					case 31: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.567000, 0.002999, 0.004000, 15.500001, 90.300041, 76.000053, 0.876000, 0.922999, 1.000000);
					case 34: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.596000, 0.011999, -0.005999, 15.500001, 90.300041, 76.000053, 0.876000, 0.922999, 1.000000);
					case 39: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.573000, 0.032000, -0.000999, 15.500001, 90.300041, 76.000053, 0.786000, 0.950997, 1.000000);
					case 46: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.573000, 0.020999, 0.002000, 15.500001, 90.300041, 76.000053, 0.786000, 0.867998, 1.000000);
					case 51: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.546001, -0.000000, -0.000999, 15.500001, 90.300041, 76.000053, 0.786000, 0.882997, 1.000000);
					case 52: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.548001, 0.034999, 0.007000, 15.500001, 90.300041, 76.000053, 0.786000, 0.890997, 1.000000);
					case 54: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.554001, 0.020999, 0.006000, 15.500001, 90.300041, 76.000053, 0.786000, 0.982997, 1.000000);
					case 57: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.541001, 0.000999, 0.004000, 15.500001, 90.500038, 76.000053, 0.786000, 0.905997, 1.000000);
					case 58: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.536001, 0.025999, 0.008999, 15.500001, 90.500038, 76.000053, 0.786000, 0.905997, 1.000000);
					case 59: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.573000, 0.039999, 0.000999, 15.500001, 90.500038, 76.000053, 0.786000, 0.905997, 1.000000);
					case 60: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.573000, 0.008999, 0.000999, 15.500001, 90.500038, 76.000053, 0.786000, 0.905997, 1.000000);
					case 61: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.566001, 0.030000, 0.019999, 15.500001, 90.500038, 76.000053, 0.786000, 0.905997, 1.000000);
					case 63: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.573001, 0.012000, 0.001000, 15.500001, 90.500038, 76.000053, 0.786000, 0.943997, 0.985000);
					case 64: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.557001, 0.022000, 0.001000, 15.500001, 90.500038, 76.000053, 0.786000, 0.943997, 0.985000);
					case 66: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.535001, 0.026000, 0.009000, 15.500001, 90.500038, 76.000053, 0.786000, 0.871997, 0.985000);
					case 68: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.524001, 0.026000, 0.013000, 15.500001, 90.500038, 76.000053, 0.786000, 0.901997, 0.985000);
					case 69: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.558001, 0.015000, 0.003000, 15.500001, 90.500038, 76.000053, 0.786000, 0.935997, 0.985000);
					case 70: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.555001, 0.029000, 0.004000, 15.500001, 90.500038, 76.000053, 0.786000, 0.935997, 0.985000);
					case 72: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.555001, 0.022000, -0.004999, 15.500001, 90.500038, 76.000053, 0.786000, 0.967996, 0.985000);
					case 73: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.548001, 0.035000, 0.010000, 15.500001, 90.500038, 76.000053, 0.786000, 0.967996, 0.985000);
					case 75: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.586000, 0.013000, 0.013000, 15.500001, 90.500038, 76.000053, 0.786000, 0.905996, 0.985000);
					case 79: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.603000, 0.031000, 0.011000, -166.500045, 89.099960, -101.999900, 0.786000, 1.039996, 1.018000);
					case 80: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.603000, 0.019000, 0.017000, -166.500045, 89.099960, -101.999900, 0.738000, 0.929996, 1.018000);
					case 82: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.555001, 0.036000, 0.013000, -166.500045, 89.099960, -101.999900, 0.738000, 0.881996, 1.018000);
					case 84: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.567001, 0.004999, 0.009000, -166.500045, 89.099960, -101.999900, 0.738000, 0.908996, 1.018000);
					case 96: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.587001, 0.037999, 0.009000, -166.500045, 89.099960, -101.999900, 0.738000, 0.908996, 1.018000);
					case 98: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.569001, 0.018999, 0.009000, -166.500045, 89.099960, -101.999900, 0.738000, 0.853996, 1.018000);
					case 100: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.584001, 0.050999, 0.009000, -166.500045, 89.099960, -101.999900, 0.738000, 0.925996, 1.018000);
					case 101: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.594001, 0.020000, 0.008000, -166.500045, 89.099960, -101.999900, 0.738000, 0.878996, 1.018000);
					case 102: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.589001, 0.014000, 0.005000, -166.500045, 89.099960, -101.999900, 0.738000, 0.878996, 1.018000);
					case 103: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.601001, 0.033000, 0.012000, -166.500045, 89.099960, -101.999900, 0.738000, 0.878996, 1.018000);
					case 104: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.589001, 0.017000, 0.012000, -166.500045, 89.099960, -101.999900, 0.738000, 0.878996, 1.018000);
					case 105: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.568001, 0.036000, 0.011000, -166.500045, 89.099960, -101.999900, 0.738000, 0.830996, 1.018000);
					case 106: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.566001, 0.029000, 0.001000, -166.500045, 89.099960, -101.999900, 0.738000, 0.846996, 1.018000);
					case 107: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.580001, 0.038000, 0.007000, -166.500045, 89.099960, -101.999900, 0.738000, 0.874996, 1.018000);
					case 108: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.572001, 0.052999, 0.009000, -164.000091, 89.099960, -101.999900, 0.738000, 0.874996, 1.018000);
					case 109: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.590001, 0.035999, 0.005000, -164.000091, 89.099960, -101.999900, 0.738000, 0.874996, 1.018000);
					case 110: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.579001, 0.024000, 0.011000, -164.000091, 89.099960, -101.999900, 0.738000, 0.883996, 1.018000);
					case 116: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.566001, 0.017000, 0.010000, -164.000091, 89.099960, -101.999900, 0.738000, 0.796996, 1.018000);
					case 111: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.583000, 0.039999, 0.010000, -164.000091, 89.099960, -101.999900, 0.738000, 0.883996, 1.018000);
					case 112: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.583000, 0.031000, 0.011000, -164.000091, 89.099960, -101.999900, 0.738000, 0.871996, 1.018000);
					case 133: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.587000, 0.032000, 0.009000, -164.000091, 89.099960, -101.999900, 0.738000, 0.948995, 1.018000);
					case 134: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.566001, 0.033000, 0.015000, -164.000091, 89.099960, -101.999900, 0.738000, 0.948995, 1.018000);
					case 135: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.587000, 0.037000, 0.012000, -164.000091, 89.099960, -101.999900, 0.738000, 0.948995, 1.018000);
					case 136: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.579001, 0.029000, 0.011000, -164.000091, 89.099960, -101.999900, 0.738000, 0.948995, 1.018000);
					case 141: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.593000, 0.034000, 0.011000, -164.000091, 89.099960, -101.999900, 0.738000, 0.948995, 1.018000);
					case 148: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.579000, 0.020000, 0.011000, -164.000091, 89.099960, -101.999900, 0.738000, 0.906995, 1.018000);
					case 151: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.579000, 0.035000, -0.008999, -164.000091, 89.099960, -101.999900, 0.738000, 0.906995, 1.018000);
					case 152: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.614000, 0.030000, 0.012000, -164.000091, 89.099960, -101.999900, 0.738000, 0.906995, 1.018000);
					case 155: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.566000, 0.000000, -0.018000, 76.800109, 90.800025, 17.299879, 1.000000, 0.916000, 1.000000);
					case 163: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.566001, 0.028000, 0.002000, -164.000091, 89.099960, -101.999900, 0.738000, 0.906995, 1.018000);
					case 164: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.566001, 0.040999, 0.011000, -164.000091, 89.099960, -101.999900, 0.738000, 0.906995, 1.018000);
					case 165: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.587000, 0.023000, 0.002000, -164.000091, 89.099960, -101.999900, 0.738000, 0.876996, 1.018000);
					case 166: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.591000, 0.045000, 0.002000, -164.000091, 89.099960, -101.999900, 0.738000, 0.876996, 1.018000);
					case 167: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.577000, 0.024000, 0.004000, -164.000091, 89.099960, -101.999900, 0.738000, 0.870995, 1.018000);
					case 172: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.577000, 0.024000, 0.004000, -164.000091, 89.099960, -101.999900, 0.738000, 0.870995, 1.018000);
					case 173: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.577000, 0.024000, 0.004000, -164.000091, 89.099960, -101.999900, 0.738000, 0.870995, 1.018000);
					case 174: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.613000, 0.008000, 0.007000, -164.000091, 89.099960, -101.999900, 0.738000, 0.897995, 1.018000);
					case 175: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.574001, 0.017000, 0.007000, -164.000091, 89.099960, -101.999900, 0.738000, 0.886995, 1.018000);
					case 181: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.586000, 0.030000, 0.012000, -164.000091, 89.099960, -101.999900, 0.738000, 0.886995, 1.018000);
					case 186: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.563001, 0.009000, 0.009000, -164.000091, 89.099960, -101.999900, 0.738000, 0.886995, 1.018000);
					case 187: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.581001, 0.031000, 0.003000, -164.000091, 89.099960, -101.999900, 0.756000, 0.922995, 1.018000);
					case 188: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.572001, 0.043000, 0.017000, -164.000091, 89.099960, -101.999900, 0.756000, 0.922995, 1.018000);
					case 191: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.572001, 0.041000, 0.015000, -164.000091, 89.099960, -101.999900, 0.756000, 0.952995, 1.018000);
					case 198: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.598001, 0.018000, 0.003000, -164.000091, 89.099960, -101.999900, 0.756000, 0.985995, 1.018000);
					case 202: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.588001, 0.036000, 0.010000, -164.000091, 89.099960, -101.999900, 0.756000, 0.908995, 1.018000);
					case 211: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.606001, 0.031000, 0.008000, -164.000091, 89.099960, -101.999900, 0.756000, 0.861995, 1.018000);
					case 225: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.583001, 0.019000, 0.010000, -164.000091, 89.099960, -101.999900, 0.756000, 0.898995, 1.018000);
					case 231: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.582001, 0.018000, 0.016000, -164.000091, 89.099960, -101.999900, 0.756000, 0.898995, 1.018000);
					case 232: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.528001, 0.008000, 0.009000, -164.000091, 89.099960, -101.999900, 0.756000, 0.803995, 0.895000);
					case 234: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.535001, 0.042000, 0.012000, -164.000091, 89.099960, -101.999900, 0.756000, 0.897995, 0.922000);
					case 235: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.539001, 0.025000, 0.016000, -164.000091, 89.099960, -101.999900, 0.756000, 0.960995, 0.922000);
					case 236: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.531001, 0.025000, 0.021000, -164.000091, 89.099960, -101.999900, 0.756000, 0.884995, 0.922000);
					case 239: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.514001, 0.020000, 0.003000, -164.000091, 89.099960, -101.999900, 0.756000, 0.864995, 0.922000);
					case 247: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.540001, 0.030000, 0.008000, -164.000091, 89.099960, -101.999900, 0.756000, 0.864995, 0.922000);
					case 248: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.523001, 0.022000, 0.008000, -164.000091, 89.099960, -101.999900, 0.756000, 0.864995, 0.922000);
					case 254: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.519001, 0.022000, 0.011000, -164.000091, 89.099960, -101.999900, 0.756000, 0.841995, 0.922000);
					case 255: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.508002, 0.053000, 0.004000, -164.000091, 89.099960, -101.999900, 0.756000, 0.910994, 0.922000);
					case 266: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.509002, 0.043000, 0.019000, -164.000091, 89.099960, -101.999900, 0.756000, 0.910994, 0.922000);
					case 268: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.509002, 0.043000, 0.015000, -164.000091, 89.099960, -101.999900, 0.756000, 0.866995, 0.922000);
					case 274: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.514002, 0.020000, 0.009000, -164.000091, 89.099960, -101.999900, 0.756000, 0.893994, 0.922000);
					case 275: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.522001, 0.039000, 0.007000, -164.000091, 89.099960, -101.999900, 0.756000, 0.893994, 0.922000);
					case 276: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.518002, 0.032000, 0.008000, -164.000091, 89.099960, -101.999900, 0.756000, 0.862995, 0.922000);
					case 280: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.538002, 0.052000, 0.007000, -164.000091, 89.099960, -101.999900, 0.756000, 0.919995, 0.922000);
					case 282: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.522002, 0.021000, 0.007000, -164.000091, 89.099960, -101.999900, 0.756000, 0.919995, 0.922000);
					case 283: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.526002, 0.023000, 0.005000, -164.000091, 89.099960, -101.999900, 0.756000, 0.927995, 0.922000);
					case 284: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.546001, 0.034000, 0.005000, -164.000091, 89.099960, -101.999900, 0.756000, 0.927995, 0.922000);
					case 285: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.528002, 0.067000, 0.025000, -164.000091, 89.099960, -101.999900, 0.756000, 0.877995, 0.922000);
					case 287: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.516002, 0.044000, 0.009000, -164.000091, 89.099960, -101.999900, 0.756000, 0.816995, 0.922000);
					case 295: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.534002, 0.026000, 0.001000, -164.000091, 89.099960, -101.999900, 0.756000, 0.851995, 0.922000);
					default: SendInf(playerid, "Маска не будет отображена на данной одежде");
				}
			}
			case 10979: // Маска mask11
			{
				switch(skin)
				{
					case 8: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.469999, 0.109999, 0.003000, 85.999992, 83.700027, 0.000000, 0.756999, 0.954002, 0.806000);
					case 9: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.454999, 0.020000, 0.009000, 49.799991, 91.200004, 41.100002, 0.634999, 0.967000, 0.840000);
					case 13: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.459999, 0.092999, -0.009999, 85.999992, 83.700027, 0.000000, 0.756999, 0.954002, 0.806000);
					case 17: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.540000, 0.049999, 0.003999, 99.500007, 86.600006, 0.000000, 0.867000, 1.080000, 0.969000);
					case 27: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.459999, 0.092999, -0.004999, 85.999992, 83.700027, 0.000000, 0.756999, 1.033002, 0.806000);
					case 30: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.470999, 0.055999, 0.004000, 49.799991, 91.200004, 41.100002, 0.634999, 0.967000, 0.840000);
					case 31: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.461999, 0.030000, 0.008000, 49.799991, 91.200004, 41.100002, 0.706999, 0.935999, 0.840000);
					case 34: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.485999, 0.083999, -0.010999, 85.999992, 84.700012, 0.000000, 0.765999, 1.036002, 0.799000);
					case 39: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.563999, 0.027000, 0.006000, 49.799991, 91.200004, 41.100002, 0.722999, 1.095000, 0.966000);
					case 46: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.515000, 0.040999, 0.003000, 99.500007, 87.299987, -4.300000, 0.842000, 1.023000, 0.909000);
					case 51: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.501000, 0.024999, 0.001000, 99.500007, 87.299987, -4.300000, 0.868000, 1.016000, 0.906000);
					case 52: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.502000, 0.062999, 0.011000, 99.500007, 87.299987, -4.300000, 0.842000, 1.023000, 0.909000);
					case 54: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.491000, 0.134000, -0.018000, 75.600006, 80.900032, 7.599997, 0.744999, 1.068999, 0.894999);
					case 57: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.485000, 0.023999, 0.002000, 99.500007, 87.299987, -4.300000, 0.868000, 1.008000, 0.906000);
					case 58: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.487000, 0.061999, 0.009000, 99.500007, 87.299987, -4.300000, 0.842000, 1.008000, 0.906000);
					case 59: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.563999, 0.083999, 0.005999, 99.500007, 86.600006, 0.000000, 0.750000, 1.080000, 0.960000);
					case 60: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.490999, 0.071999, -0.004999, 85.999992, 84.700012, 0.000000, 0.765999, 1.070002, 0.870000);
					case 61: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.459999, 0.038000, 0.023000, 49.799991, 91.200004, 41.100002, 0.706999, 0.989999, 0.835000);
					case 63: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.487999, 0.083999, -0.002999, 85.999992, 84.700012, 0.000000, 0.698999, 0.931002, 0.824000);
					case 64: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.461999, 0.041000, 0.007000, 49.799991, 91.200004, 41.100002, 0.634999, 0.843001, 0.840000);
					case 66: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.483000, 0.053999, 0.006000, 99.500007, 87.299987, -4.300000, 0.868000, 1.008000, 0.906000);
					case 68: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.496000, 0.062999, 0.008000, 99.500007, 87.299987, -4.300000, 0.842000, 1.012000, 0.930000);
					case 69: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.435999, 0.076999, -0.005999, 85.999992, 84.700012, 0.000000, 0.765999, 1.038002, 0.778000);
					case 70: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.525999, 0.110999, -0.003999, 85.999992, 83.700027, 0.000000, 0.724999, 0.998002, 0.948000);
					case 72: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.520000, 0.126000, -0.032000, 75.600006, 80.900032, 7.599997, 0.744999, 1.104000, 0.930999);
					case 73: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.463999, 0.046000, 0.008999, 49.799991, 91.200004, 41.100002, 0.706999, 0.989999, 0.835000);
					case 75: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.562999, 0.104999, 0.003000, 85.999992, 84.300018, 0.000000, 0.648000, 0.990002, 0.948000);
					case 79: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.563999, 0.030000, 0.017000, 49.799991, 91.200004, 41.100002, 0.722999, 1.065000, 0.966000);
					case 80: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.560999, 0.098999, 0.005000, 85.999992, 84.700012, 0.000000, 0.648000, 0.995002, 0.948000);
					case 82: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.497000, 0.062999, 0.009000, 99.500007, 87.299987, -4.300000, 0.842000, 0.982000, 0.906000);
					case 84: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.533999, 0.099999, -0.004999, 85.999992, 83.700027, 0.000000, 0.609999, 0.954002, 0.948000);
					case 98: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.528000, 0.111999, -0.021999, 75.600006, 80.900032, 7.599997, 0.820000, 0.942999, 0.926999);
					case 100: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.454999, 0.052000, 0.005000, 49.799991, 91.200004, 41.100002, 0.634999, 0.967000, 0.840000);
					case 101: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.533000, 0.105000, -0.023000, 75.600006, 80.900032, 7.599997, 0.785000, 1.098999, 0.926999);
					case 102: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.468999, 0.066999, -0.001999, 85.999992, 84.700012, 0.000000, 0.808999, 0.986002, 0.841000);
					case 103: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.471999, 0.078999, -0.000999, 85.999992, 84.700012, 0.000000, 0.808999, 0.952002, 0.841000);
					case 104: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.470999, 0.078999, 0.000000, 85.999992, 84.700012, 0.000000, 0.779000, 0.847002, 0.841000);
					case 105: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.490999, 0.091999, -0.001999, 85.999992, 84.700012, 0.000000, 0.779000, 0.939002, 0.885000);
					case 106: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.486999, 0.093999, -0.008999, 85.999992, 84.700012, 0.000000, 0.744000, 0.916002, 0.885000);
					case 107: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.494999, 0.102999, -0.005999, 85.999992, 84.700012, 0.000000, 0.723000, 1.003002, 0.885000);
					case 108: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.510999, 0.108999, -0.001999, 85.999992, 84.700012, 0.000000, 0.723000, 1.018002, 0.925000);
					case 109: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.523999, 0.100999, -0.009999, 85.999992, 84.700012, 0.000000, 0.723000, 0.929002, 0.902000);
					case 110: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.451999, 0.093999, 0.002000, 85.999992, 84.700012, 0.000000, 0.723000, 0.929002, 0.816000);
					case 116: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.528000, 0.106999, -0.020999, 75.600006, 80.900032, 7.599997, 0.858000, 0.918999, 0.926999);
					case 111: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.579000, 0.057999, 0.004999, 99.500007, 87.299987, -4.300000, 0.842000, 1.039000, 1.005000);
					case 112: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.542000, 0.055999, 0.003999, 99.500007, 87.299987, -4.300000, 0.842000, 1.039000, 0.933000);
					case 133: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.545999, 0.093999, -0.002999, 85.999992, 83.700027, 0.000000, 0.781999, 1.132002, 0.950000);
					case 134: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.555999, 0.028000, 0.016000, 49.799991, 91.200004, 41.100002, 0.722999, 1.051000, 0.966000);
					case 135: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.593999, 0.110999, 0.001000, 85.999992, 83.700027, 0.000000, 0.756999, 1.129000, 1.000000);
					case 136: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.555999, 0.017000, 0.009000, 49.799991, 91.200004, 41.100002, 0.722999, 1.090001, 0.966000);
					case 141: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.532000, 0.079999, 0.000999, 99.500007, 86.600006, 0.000000, 0.750000, 1.080000, 0.923999);
					case 148: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.466999, 0.082999, 0.002000, 85.999992, 83.700027, 0.000000, 0.781999, 1.027002, 0.836000);
					case 151: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.540999, 0.101999, -0.020999, 85.999992, 83.700027, 0.000000, 0.756999, 1.032001, 0.938000);
					case 152: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.528999, 0.097999, -0.005999, 85.999992, 83.700027, 0.000000, 0.756999, 1.049002, 0.887000);
					case 155: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.491999, 0.108999, -0.020999, 85.999992, 83.700027, 0.000000, 0.756999, 0.954002, 0.887000);
					case 163: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.499999, 0.098999, -0.013999, 85.999992, 83.700027, 0.000000, 0.756999, 1.122002, 0.907000);
					case 164: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.557000, 0.048999, 0.006999, 99.500007, 87.299987, -4.300000, 0.938000, 1.090001, 0.985999);
					case 165: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.560000, 0.048999, -0.002000, 99.500007, 87.299987, -4.300000, 0.938000, 1.090001, 0.985999);
					case 167: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.489999, 0.086999, -0.010999, 85.999992, 83.700027, 0.000000, 0.756999, 1.030002, 0.887000);
					case 172: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.457999, 0.092999, -0.007999, 85.999992, 83.700027, 0.000000, 0.756999, 0.953002, 0.806000);
					case 174: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.538998, 0.077999, -0.006999, 85.999992, 83.700027, 0.000000, 0.756999, 1.065001, 0.907000);
					case 175: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.495999, 0.091999, -0.005999, 85.999992, 83.700027, 0.000000, 0.756999, 0.971001, 0.907000);
					case 181: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.480999, 0.038000, 0.011000, 49.799991, 91.200004, 41.100002, 0.634999, 0.967000, 0.840000);
					case 186: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.527999, 0.095999, -0.007999, 85.999992, 83.700027, 0.000000, 0.639999, 0.947002, 0.948000);
					case 187: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.530000, 0.079999, -0.003000, 99.500007, 86.600006, 0.000000, 0.750000, 1.066000, 0.923999);
					case 188: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.563999, 0.016000, 0.002000, 49.799991, 91.200004, 41.100002, 0.722999, 1.184000, 0.966000);
					case 191: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.470999, 0.050000, 0.016000, 49.799991, 91.200004, 41.100002, 0.706999, 0.989999, 0.835000);
					case 202: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.558999, 0.126999, -0.007999, 85.999992, 83.700027, 0.000000, 0.680999, 0.986002, 0.948000);
					case 211: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.465999, 0.092999, -0.007999, 85.999992, 83.700027, 0.000000, 0.756999, 0.986002, 0.806000);
					case 225: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.559999, 0.020000, 0.008000, 49.799991, 91.200004, 41.100002, 0.722999, 1.045001, 0.966000);
					case 231: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.559999, 0.021000, 0.018000, 49.799991, 91.200004, 41.100002, 0.695999, 1.045001, 0.966000);
					case 234: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.554000, 0.047000, 0.015000, 49.799991, 91.200004, 41.100002, 0.695999, 1.045001, 0.966000);
					case 235: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.560000, 0.027000, 0.018000, 49.799991, 91.200004, 41.100002, 0.695999, 1.045001, 0.966000);
					case 236: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.507000, 0.029000, 0.021000, 49.799991, 91.200004, 41.100002, 0.695999, 0.971001, 0.861000);
					case 239: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.530999, 0.096999, -0.012999, 85.999992, 83.700027, 0.000000, 0.756999, 1.005000, 0.938000);
					case 247: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.475999, 0.032000, 0.012000, 49.799991, 91.200004, 41.100002, 0.706999, 0.989999, 0.835000);
					case 248: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.475999, 0.027000, 0.008000, 49.799991, 91.200004, 41.100002, 0.706999, 0.989999, 0.835000);
					case 254: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.470999, 0.026000, 0.012000, 49.799991, 91.200004, 41.100002, 0.706999, 0.989999, 0.835000);
					case 255: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.459999, 0.053999, 0.001999, 49.799991, 91.200004, 41.100002, 0.706999, 0.989999, 0.835000);
					case 266: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.505001, 0.076999, 0.010999, 99.500007, 87.299987, -4.300000, 0.805000, 0.985000, 0.892000);
					case 268: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.499999, 0.123999, 0.001000, 85.999992, 83.700027, 0.000000, 0.756999, 0.954002, 0.887000);
					case 274: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.545999, 0.098999, -0.003999, 85.999992, 83.700027, 0.000000, 0.738999, 0.990002, 0.950000);
					case 275: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.545999, 0.110999, -0.007999, 85.999992, 83.700027, 0.000000, 0.738999, 1.016002, 0.950000);
					case 276: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.493999, 0.104999, -0.004999, 85.999992, 83.700027, 0.000000, 0.738999, 0.953002, 0.880000);
					case 280: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.531000, 0.076999, 0.001999, 99.500007, 87.299987, -4.300000, 0.842000, 1.039000, 0.884000);
					case 283: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.544000, 0.055999, -0.002000, 99.500007, 87.299987, -4.300000, 0.842000, 1.039000, 0.933000);
					case 284: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.492001, 0.076999, 0.000999, 99.500007, 87.299987, -4.300000, 0.805000, 0.984000, 0.835000);
					case 285: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.522000, 0.102999, 0.019999, 99.500007, 87.299987, -4.300000, 0.805000, 0.985000, 0.917000);
					case 287: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.460999, 0.039000, 0.009999, 49.799991, 91.200004, 41.100002, 0.781000, 0.957999, 0.815000);
					case 295: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.472999, 0.030000, -0.003000, 49.799991, 91.200004, 41.100002, 0.706999, 0.989999, 0.835000);
					default: SendInf(playerid, "Маска не будет отображена на данной одежде");
				}
			}
			case 10980: // Маска mask12
			{
				switch(skin)
				{
					case 8: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.565000, -0.016000, 0.001000, 76.800109, 90.800025, 17.299879, 1.000000, 0.990999, 1.000000);
					case 9: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.565000, -0.016000, -0.002999, 76.800109, 90.800025, 17.299879, 1.000000, 0.887999, 1.000000);
					case 13: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.473000, -0.111000, 0.014000, 76.800109, 101.500045, 17.299879, 1.000000, 0.921999, 0.884000);
					case 17: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.590000, -0.103000, 0.014000, 76.800109, 96.900085, 17.299879, 1.000000, 1.030000, 1.077000);
					case 27: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.565000, -0.074999, 0.007999, 76.800109, 96.900085, 17.299879, 1.000000, 0.987999, 0.979000);
					case 30: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.581000, -0.069999, 0.010999, 76.800109, 96.900085, 17.299879, 1.000000, 0.950999, 1.053000);
					case 31: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.550000, -0.087999, 0.009999, 76.800109, 96.900085, 17.299879, 1.000000, 0.905999, 1.008999);
					case 34: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.600001, -0.058999, 0.001999, 76.800109, 95.600097, 17.299879, 0.928000, 0.905999, 1.008999);
					case 39: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.576001, -0.058999, 0.005999, 76.800109, 95.600097, 17.299879, 0.928000, 1.048999, 1.036000);
					case 46: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.576001, -0.068999, 0.009999, 76.800109, 95.600097, 17.299879, 0.931999, 1.012999, 1.036000);
					case 51: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.560001, -0.096000, 0.006999, 76.800109, 95.600097, 17.299879, 1.016999, 1.012999, 1.036000);
					case 52: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.560001, -0.060999, 0.014999, 76.800109, 95.600097, 17.299879, 1.005999, 1.009999, 1.036000);
					case 54: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.556001, -0.060999, 0.014999, 76.800109, 95.600097, 17.299879, 1.005999, 1.009999, 1.036000);
					case 57: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.551001, -0.103999, 0.005999, 76.800109, 95.600097, 17.299879, 1.005999, 1.049999, 1.036000);
					case 58: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.546001, -0.066999, 0.016000, 76.800109, 95.600097, 17.299879, 0.954000, 1.012999, 1.036000);
					case 59: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.581001, -0.053999, 0.005000, 76.800109, 95.600097, 17.299879, 0.954000, 1.012999, 1.036000);
					case 60: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.570001, -0.091999, 0.006000, 76.800109, 95.600097, 17.299879, 1.072000, 1.054999, 1.036000);
					case 61: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.570001, -0.071999, 0.020999, 76.800109, 95.600097, 17.299879, 0.997000, 1.054999, 1.036000);
					case 63: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.510002, -0.054999, -0.001000, 76.800109, 95.600097, 17.299879, 0.863000, 0.907999, 0.901000);
					case 64: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.494002, -0.030999, 0.010999, 76.800109, 95.600097, 17.299879, 0.863000, 0.907999, 0.901000);
					case 66: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.563002, -0.043999, 0.005999, 76.800109, 93.100135, 17.299879, 0.943000, 1.009998, 1.062999);
					case 68: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.523002, -0.020999, 0.010999, 76.800109, 93.100135, 17.299879, 0.943000, 1.009998, 0.998999);
					case 69: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.524002, -0.045999, -0.003000, 76.800109, 93.100135, 17.299879, 0.943000, 1.059999, 0.962999);
					case 70: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.563002, -0.032999, 0.002999, 76.800109, 93.100135, 17.299879, 0.943000, 1.059999, 1.038999);
					case 72: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.584002, -0.039999, -0.007000, 76.800109, 93.100135, 17.299879, 0.943000, 1.059999, 1.038999);
					case 73: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.489002, -0.013999, 0.003999, 76.800109, 93.100135, 17.299879, 0.943000, 0.976998, 0.913999);
					case 75: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.521002, -0.023999, 0.014999, 76.800109, 93.100135, 17.299879, 0.943000, 0.976998, 0.913999);
					case 79: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.583001, 0.115000, -0.032000, 76.800109, 80.000137, 17.299879, 0.943000, 1.071998, 1.047000);
					case 80: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.601001, 0.111000, -0.027000, 76.800109, 80.000137, 17.299879, 0.943000, 0.999998, 1.047000);
					case 82: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.562001, 0.119000, -0.031000, 76.800109, 80.000137, 17.299879, 0.958000, 0.999998, 1.047000);
					case 84: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.572001, -0.041999, -0.005000, 76.800109, 91.000137, 17.299879, 0.958000, 1.073998, 1.047000);
					case 96: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.604001, -0.012999, -0.005000, 76.800109, 91.000137, 17.299879, 0.958000, 1.073998, 1.047000);
					case 98: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.588001, -0.027999, -0.005000, 76.800109, 91.000137, 17.299879, 0.940000, 1.005998, 1.047000);
					case 100: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.579001, 0.102000, -0.031000, 76.800109, 82.600173, 17.299879, 0.940000, 1.005998, 1.047000);
					case 101: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.607001, -0.034999, -0.002000, 76.800109, 91.500183, 17.299879, 0.940000, 1.063999, 1.047000);
					case 102: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.562001, -0.017999, -0.002000, 76.800109, 91.500183, 17.299879, 0.940000, 1.063999, 0.989000);
					case 103: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.562001, -0.005999, -0.002000, 76.800109, 91.500183, 17.299879, 0.940000, 1.026999, 0.989000);
					case 104: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.508001, -0.013999, -0.002000, 76.800109, 91.500183, 17.299879, 0.940000, 0.906999, 0.915000);
					case 105: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.557001, 0.019000, -0.009000, 76.800109, 89.100158, 17.299879, 0.940000, 0.976999, 1.020000);
					case 106: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.566001, 0.011000, -0.011000, 76.800109, 89.100158, 17.299879, 0.940000, 0.947999, 1.020000);
					case 107: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.584001, 0.027000, -0.009000, 76.800109, 89.100158, 17.299879, 0.940000, 0.947999, 1.036000);
					case 108: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.580001, 0.032000, -0.009000, 76.800109, 89.100158, 17.299879, 0.940000, 0.970999, 1.036000);
					case 109: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.626000, 0.013000, -0.013000, 76.800109, 89.100158, 17.299879, 0.940000, 0.986999, 1.088000);
					case 110: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.555001, 0.013000, -0.004000, 76.800109, 89.100158, 17.299879, 0.940000, 0.976999, 0.992999);
					case 116: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.568001, 0.097000, -0.033000, 76.800109, 80.100143, 17.299879, 0.979000, 0.952999, 1.032998);
					case 111: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.622001, 0.127000, -0.033000, 76.800109, 80.100143, 17.299879, 0.940000, 0.976999, 1.100999);
					case 112: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.615001, 0.119000, -0.033000, 76.800109, 80.100143, 17.299879, 0.940000, 0.976999, 1.100999);
					case 133: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.573001, -0.048999, 0.000999, 76.800109, 94.200111, 17.299879, 0.979000, 1.066000, 1.007997);
					case 134: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.541002, -0.060999, 0.007999, 76.800109, 94.200111, 17.299879, 1.025001, 1.162000, 1.007997);
					case 135: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.645001, -0.001999, -0.016000, 76.800109, 88.300216, 21.499893, 1.097001, 1.181005, 1.133999);
					case 136: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.640001, -0.001999, -0.016000, 76.800109, 88.300216, 21.499893, 1.097001, 1.164005, 1.133999);
					case 141: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.593001, -0.043999, 0.007999, 76.800109, 94.200111, 17.299879, 0.972001, 1.046000, 1.062997);
					case 148: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.562002, -0.058999, 0.007999, 76.800109, 94.200111, 17.299879, 0.972001, 1.014001, 1.024997);
					case 151: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.593001, 0.102000, -0.051000, 76.800109, 81.100105, 17.299879, 0.972001, 1.014001, 1.058997);
					case 152: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.620001, -0.069999, 0.006999, 76.800109, 94.900138, 17.299879, 1.027001, 1.014001, 1.044996); 
					case 155: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.543000, 0.000000, -0.022000, 76.800109, 90.800025, 17.299879, 1.000000, 0.916000, 1.000000);
					case 163: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.563001, -0.075999, -0.003000, 76.800109, 94.900138, 17.299879, 1.027001, 1.102001, 1.050997);
					case 164: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.563001, -0.073999, 0.007999, 76.800109, 94.900138, 17.299879, 1.158001, 1.194002, 1.051997);
					case 165: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.535002, -0.073999, -0.003000, 76.800109, 94.900138, 17.299879, 1.129001, 0.918003, 0.958997);
					case 166: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.539002, -0.166999, 0.036999, 76.800109, 105.800186, 17.299879, 1.129001, 1.201003, 1.035997);
					case 167: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.585002, -0.060999, 0.000999, 76.800109, 94.200202, 15.299890, 0.924000, 1.065004, 1.068998);
					case 172: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.549002, -0.050999, 0.000999, 76.800109, 94.200202, 15.299890, 0.924000, 0.991004, 0.987998);
					case 173: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.549002, -0.050999, 0.000999, 76.800109, 94.200202, 15.299890, 0.924000, 0.991004, 0.987998);
					case 174: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.594002, -0.067999, 0.004999, 76.800109, 94.200202, 15.299890, 0.933000, 1.003004, 1.016998);
					case 175: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.555001, -0.048999, 0.006999, 76.800109, 94.200202, 15.299890, 0.933000, 0.959004, 1.016998);
					case 181: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.582001, -0.048999, 0.006999, 76.800109, 94.200202, 15.299890, 0.933000, 0.959004, 1.008998);
					case 186: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.548001, -0.068999, 0.001999, 76.800109, 94.200202, 15.299882, 0.933000, 0.959004, 1.008998);
					case 187: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.575001, -0.053999, -0.001000, 76.800109, 94.200202, 15.299882, 1.083000, 1.056004, 1.030999);
					case 188: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.553001, -0.018999, 0.011999, 76.800109, 94.200202, 15.299882, 0.873000, 0.976004, 0.991999);
					case 191: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.540002, -0.013999, 0.011999, 76.800109, 94.200202, 15.299882, 0.873000, 0.976004, 0.991999);
					case 198: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.589001, -0.037999, 0.003999, 76.800109, 94.200202, 15.299882, 0.873000, 1.031004, 1.021999);
					case 202: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.589001, -0.026999, 0.003999, 76.800109, 94.200202, 15.299882, 0.873000, 1.031004, 1.021999);
					case 211: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.592001, 0.210000, -0.058000, 76.800109, 73.200149, 17.199886, 0.873000, 0.939004, 1.052999);
					case 225: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.597001, 0.058000, -0.015000, 76.800109, 86.100120, 17.199886, 0.873000, 0.959004, 1.030999);
					case 231: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.590001, 0.057000, -0.012000, 76.800109, 86.100120, 17.199886, 0.873000, 0.959004, 1.030999);
					case 232: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.494002, 0.038000, -0.015000, 76.800109, 86.100120, 17.199886, 0.873000, 0.825004, 0.836999);
					case 234: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.565002, 0.090000, -0.014000, 76.800109, 86.100120, 25.099901, 0.873000, 0.966004, 0.979998);
					case 235: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.564002, -0.058999, 0.022999, 76.800109, 97.000137, 21.499893, 0.873000, 0.966004, 0.979998);
					case 236: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.553002, -0.058999, 0.023999, 76.800109, 97.000137, 21.499893, 0.873000, 0.897003, 0.979998);
					case 239: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.579002, 0.016000, -0.016000, 76.800109, 88.300216, 21.499893, 0.919000, 0.941003, 1.039999);
					case 247: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.601001, 0.023000, -0.013000, 76.800109, 88.300216, 21.499893, 0.919000, 1.017003, 1.047999);
					case 248: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.600002, 0.001000, -0.009000, 76.800109, 88.300216, 21.499893, 1.051000, 1.025003, 1.068999);
					case 254: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.600002, 0.010000, -0.009000, 76.800109, 88.300216, 21.499893, 1.034000, 1.032002, 1.068999);
					case 255: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.600002, 0.030000, -0.019000, 76.800109, 88.300216, 21.499893, 1.034000, 1.032002, 1.068999);
					case 266: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.600002, 0.030000, -0.003000, 76.800109, 88.300216, 21.499893, 1.034000, 1.032002, 1.068999);
					case 268: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.600002, 0.030000, -0.005000, 76.800109, 88.300216, 21.499893, 1.034000, 1.032002, 1.068999);
					case 274: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.600002, -0.005999, -0.013000, 76.800109, 88.300216, 21.499893, 1.034000, 1.110003, 1.068999);
					case 275: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.600002, 0.015000, -0.016000, 76.800109, 88.300216, 21.499893, 1.009000, 1.110003, 1.068999);
					case 276: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.600002, 0.015000, -0.011000, 76.800109, 88.300216, 21.499893, 1.009000, 0.969003, 1.054999);
					case 280: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.616001, 0.032000, -0.015000, 76.800109, 88.300216, 21.499893, 1.009000, 1.060003, 1.054999);
					case 282: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.629001, 0.011000, -0.015000, 76.800109, 88.300216, 21.499893, 1.009000, 1.118005, 1.078000);
					case 283: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.588001, 0.024000, -0.021000, 76.800109, 88.300216, 21.499893, 0.916000, 1.051005, 1.035000);
					case 284: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.564001, 0.032000, -0.012000, 76.800109, 88.300216, 21.499893, 0.916000, 0.939005, 0.955000);
					case 285: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.636001, 0.037000, -0.000000, 76.800109, 88.300216, 21.499893, 1.064001, 1.128005, 1.124000);
					case 287: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.590001, 0.050000, -0.007000, 76.800109, 88.300216, 21.499893, 0.828001, 0.909004, 1.034000);
					case 295: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.645001, -0.001999, -0.018000, 76.800109, 88.300216, 21.499893, 1.097001, 1.154005, 1.133999);
					default: SendInf(playerid, "Маска не будет отображена на данной одежде");
				}
			}
			case 10981: // Маска mask-kom
			{
				switch(skin)
				{
					case 8: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.545001, -0.080999, 0.018999, 81.400215, 98.399719, 11.199994, 0.974001, 1.118016, 0.984998);
					case 9: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.513000, -0.177999, -0.003999, 91.700164, 104.499664, -0.900010, 1.045002, 1.034002, 0.985998);
					case 13: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.539999, -0.153999, -0.008999, 89.099929, 103.299858, 4.700020, 1.105999, 1.064005, 1.000000);
					case 17: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.544000, -0.074999, -0.013000, 98.599990, 96.799781, -2.800000, 0.910000, 1.014999, 1.000000);
					case 27: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.549999, -0.148999, 0.001000, 89.099929, 103.299858, 2.700021, 1.063998, 1.094005, 1.000000);
					case 30: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.541000, -0.120999, -0.005999, 91.500076, 102.199714, 0.100006, 1.004001, 1.025000, 0.985998);
					case 31: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.539000, -0.114999, -0.011999, 94.500053, 99.899772, 0.100006, 1.004001, 1.033998, 0.985998);
					case 34: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.567001, -0.108999, 0.002999, 82.400192, 100.299682, 11.699975, 0.974001, 1.041015, 0.984998);
					case 39: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.548000, -0.115999, -0.023999, 97.700134, 100.899665, -0.900010, 1.004000, 1.155005, 0.984998);
					case 46: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.535002, -0.130999, 0.017999, 82.400192, 102.099594, 6.300048, 0.961002, 1.050023, 0.984998);
					case 51: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.518002, -0.141999, 0.013999, 82.400192, 102.099594, 10.699986, 0.879002, 1.022022, 0.984998);
					case 52: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.510002, -0.115999, 0.021999, 82.400192, 102.099594, 8.800049, 0.961002, 1.027022, 0.984998);
					case 54: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.542000, -0.075999, -0.014000, 98.599990, 96.799781, -0.299996, 1.032000, 1.113002, 1.000000);
					case 57: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.507002, -0.150999, 0.015999, 82.400192, 102.099594, 10.000015, 0.961002, 1.014020, 0.984998);
					case 58: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.501002, -0.122999, 0.020999, 82.400192, 102.099594, 10.000015, 0.961002, 1.014020, 0.984998);
					case 59: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.560000, -0.061999, -0.013000, 98.599990, 96.799781, -8.499999, 0.979000, 1.072997, 1.000000);
					case 60: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.536002, -0.150999, 0.016999, 82.400192, 102.099594, 6.999969, 1.021002, 1.058024, 0.984998);
					case 61: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.539000, -0.110000, 0.010000, 91.200080, 100.999847, 1.300002, 0.936001, 1.035997, 0.993998);
					case 63: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.553001, -0.124999, 0.008999, 82.400192, 100.299682, 8.799970, 0.974001, 1.031014, 0.984998);
					case 64: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.540000, -0.114999, -0.010999, 94.500053, 99.899772, 0.100006, 1.004001, 1.130000, 0.985998);
					case 66: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.508002, -0.115999, 0.021999, 82.400192, 102.099594, 8.500006, 0.879002, 0.983021, 0.984998);
					case 68: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.500002, -0.122999, 0.024999, 82.400192, 102.099594, 8.800049, 0.961002, 1.047022, 0.984998);
					case 69: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.528002, -0.136999, 0.014999, 82.400192, 102.099594, 11.199984, 1.021002, 1.058023, 0.984998);
					case 70: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.531002, -0.129999, 0.021999, 82.400192, 102.099594, 4.899971, 1.021002, 1.091022, 0.984998);
					case 72: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.559000, -0.080999, -0.020000, 98.599990, 96.799781, -5.099996, 1.032000, 1.141003, 1.000000);
					case 73: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.533000, -0.103000, -0.001000, 92.100051, 100.599891, -1.499999, 0.976999, 1.028998, 0.993998);
					case 75: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.562001, -0.118999, 0.024000, 82.400192, 100.299682, 8.599990, 0.974001, 1.025014, 0.984998);
					case 79: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.538000, -0.122999, 0.000000, 91.700164, 100.699684, -0.900010, 1.056001, 1.107003, 0.984998);
					case 80: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.562001, -0.121999, 0.024000, 82.400192, 100.299682, 6.099990, 0.974001, 1.077015, 0.984998);
					case 82: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.505002, -0.122999, 0.020999, 82.400192, 102.099594, 8.800049, 0.961002, 1.014020, 0.984998);
					case 84: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.541999, -0.082999, -0.002999, 89.099929, 95.999923, 6.500010, 0.937000, 1.052003, 1.000000);
					case 98: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.559999, -0.059999, -0.000999, 89.099929, 95.999923, 4.000005, 0.867001, 0.943004, 1.000000);
					case 100: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.513000, -0.151999, -0.015999, 94.200080, 104.699676, -2.400010, 1.045002, 1.152001, 0.985998);
					case 101: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.575999, -0.095999, -0.005999, 89.099929, 95.999923, 6.900009, 1.099000, 1.121004, 1.000000);
					case 102: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.559000, -0.100999, -0.025000, 98.599990, 96.799781, -5.099996, 1.032000, 1.141003, 1.000000);
					case 103: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.571000, -0.084999, -0.017000, 98.599990, 96.799781, -5.099996, 1.032000, 1.141003, 1.000000);
					case 104: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.563000, -0.084999, -0.018000, 98.599990, 96.799781, -4.299997, 0.929000, 1.141003, 1.000000);
					case 105: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.549000, -0.068999, -0.012000, 98.599990, 96.799781, -6.799995, 0.998000, 1.031001, 1.000000);
					case 106: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.556999, -0.043999, -0.009999, 89.099929, 93.499961, 5.500001, 1.000000, 1.052002, 1.000000);
					case 107: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.560999, -0.076999, -0.002999, 89.099929, 97.199905, 5.000004, 1.017000, 1.074005, 1.000000);
					case 108: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.558999, -0.064999, -0.001999, 89.099929, 97.199905, 5.000004, 1.017000, 1.043004, 1.000000);
					case 109: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.566999, -0.077999, -0.006999, 89.099929, 97.199905, 5.100005, 1.017000, 1.091005, 1.000000);
					case 110: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.555999, -0.088999, -0.001999, 89.099929, 97.199905, 5.100005, 1.017000, 1.091005, 1.000000);
					case 116: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.547999, -0.073999, 0.000000, 89.099929, 97.199905, 4.000005, 0.867001, 0.918004, 1.000000);
					case 111: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.536002, -0.119999, 0.014999, 82.800186, 101.799606, 9.000048, 1.012999, 1.108023, 0.984998);
					case 112: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.545002, -0.101999, 0.013999, 82.800186, 100.199630, 9.000048, 0.944999, 1.076022, 0.984998);
					case 133: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.542001, -0.132999, 0.013999, 82.400192, 102.299652, 12.199978, 1.001001, 1.119017, 0.984998);
					case 134: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.527001, -0.121999, -0.015999, 97.400138, 101.699615, -3.300011, 1.004000, 1.087003, 0.984998);
					case 135: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.535001, -0.132999, 0.017000, 80.700248, 102.399642, 14.100006, 1.004000, 1.196013, 0.984998);
					case 136: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.528001, -0.142999, -0.020999, 97.400138, 102.399604, -3.300011, 1.004000, 1.154004, 0.984998);
					case 141: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.560000, -0.077999, -0.010000, 98.599990, 96.799781, -7.200002, 1.029000, 1.164001, 1.000000);
					case 148: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.541001, -0.103999, 0.016999, 82.400192, 100.299682, 8.699973, 0.877002, 0.983015, 0.984998);
					case 151: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.527001, -0.147999, 0.007000, 80.700248, 104.299674, 10.799993, 1.016001, 1.144014, 0.984998);
					case 152: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.559001, -0.160999, 0.018999, 80.700248, 104.299674, 16.099990, 1.016001, 1.108014, 0.984998);
					case 163: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.524000, -0.137999, -0.003999, 89.099929, 101.199882, 1.700019, 1.045000, 1.158002, 1.000000);
					case 164: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.542000, -0.070999, -0.007000, 98.599990, 96.799781, -10.500000, 1.032000, 1.082001, 1.000000);
					case 165: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.521002, -0.136999, 0.005999, 80.700248, 104.299674, 11.899991, 0.952001, 1.005013, 0.984998);
					case 167: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.518002, -0.168999, 0.021999, 80.700248, 104.299674, 10.199989, 1.016001, 1.075013, 0.984998);
					case 172: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.542999, -0.115999, -0.003999, 89.099929, 101.199882, 4.400018, 0.871000, 1.052003, 1.000000);
					case 174: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.571999, -0.144999, -0.000999, 89.099929, 101.199882, 1.700019, 0.977000, 1.087002, 1.000000);
					case 175: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.541999, -0.118999, -0.000999, 89.099929, 101.199882, 1.300019, 0.871000, 1.031002, 1.000000);
					case 181: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.544000, -0.130999, -0.002999, 91.500076, 102.199714, 0.100006, 1.004001, 1.036000, 0.985998);
					case 186: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.539999, -0.082999, -0.004999, 89.099929, 95.999923, 6.500010, 0.937000, 1.052003, 1.000000);
					case 187: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.560000, -0.064999, -0.022000, 98.599990, 96.799781, -2.500004, 0.946000, 1.140998, 1.000000);
					case 188: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.558999, -0.044999, 0.005000, 89.099929, 95.999923, 6.500010, 0.937000, 1.052003, 1.000000);
					case 191: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.551000, -0.060000, 0.001999, 93.000030, 96.399909, 0.000000, 0.976999, 1.117999, 0.993998);
					case 198: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.548000, -0.132999, -0.008999, 91.700164, 100.699684, -0.900010, 1.056001, 1.206005, 0.984998);
					case 202: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.570999, -0.057999, 0.000000, 89.099929, 95.999923, 3.500012, 0.998000, 1.104003, 1.000000);
					case 211: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.563999, -0.122999, -0.004999, 89.099929, 101.199882, 7.000016, 1.009998, 1.034003, 1.000000);
					case 225: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.528001, -0.137999, -0.016999, 97.400138, 102.399604, -3.300008, 1.004000, 1.148005, 0.984998);
					case 231: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.528001, -0.144999, -0.016999, 97.400138, 102.399604, -3.300008, 1.004000, 1.148005, 0.984998);
					case 232: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.557000, -0.157999, -0.024999, 97.400138, 102.399604, -3.300008, 1.004000, 0.974005, 0.984998);
					case 234: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.504001, -0.187000, -0.011999, 95.100128, 109.099571, -3.400007, 1.004000, 1.122007, 0.984998);
					case 235: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.539001, -0.129999, 0.031000, 79.300254, 101.899658, 12.999996, 1.004000, 1.176010, 0.984998);
					case 236: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.533001, -0.131999, 0.036000, 79.300254, 101.999633, 11.900003, 1.004000, 1.106009, 0.984998);
					case 239: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.531001, -0.130999, 0.016000, 80.700248, 102.399642, 11.599997, 0.897001, 1.008012, 0.984998);
					case 247: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.552000, -0.120999, 0.001000, 88.900070, 101.399803, 5.200004, 0.960001, 1.033998, 0.985998);
					case 248: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.539000, -0.114999, -0.011999, 94.500053, 99.899772, 0.100006, 1.004001, 1.033998, 0.985998);
					case 254: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.550000, -0.095999, 0.000000, 91.200080, 97.699882, 0.800003, 1.041001, 0.980997, 0.985998);
					case 255: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.529000, -0.102000, -0.009999, 91.200080, 100.999847, 1.300002, 1.087000, 1.129999, 0.993998);
					case 266: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.554000, -0.060999, -0.005000, 98.599990, 96.799781, -4.999997, 1.000000, 1.106999, 1.000000);
					case 268: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.527001, -0.124999, 0.029999, 80.000236, 104.099678, 11.799992, 0.974001, 1.008013, 0.984998);
					case 274: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.536002, -0.127999, 0.017999, 82.400192, 102.099594, 8.799973, 0.891002, 1.073019, 0.984998);
					case 275: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.536002, -0.128999, 0.015999, 82.400192, 102.099594, 7.399972, 1.021002, 1.116021, 0.984998);
					case 276: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.536002, -0.121999, 0.015999, 82.400192, 102.099594, 10.899971, 1.021002, 1.024021, 0.984998);
					case 280: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.561001, -0.090999, 0.010999, 82.800186, 100.199630, 9.000048, 1.023999, 1.076022, 0.984998);
					case 283: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.553001, -0.092999, 0.009999, 82.800186, 100.199630, 9.000048, 0.862999, 1.076022, 0.984998);
					case 284: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.561001, -0.101999, 0.010999, 82.800186, 100.199630, 9.000048, 0.947000, 1.064022, 0.984998);
					case 285: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.563000, -0.041000, -0.000000, 98.599990, 96.799781, -2.800000, 1.000000, 1.106999, 1.000000);
					case 287: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.562000, 0.040999, 0.000000, 93.000030, 88.699981, 0.000000, 0.855000, 0.995000, 1.000000);
					case 295: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.557000, -0.132000, -0.010999, 92.100051, 100.899848, -1.499999, 1.054000, 1.033999, 0.993998);
					default: SendInf(playerid, "Маска не будет отображена на данной одежде");
				}
			}
			case 10982: // Маска pay_mask
			{
				switch(skin)
				{
					case 8: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.745998, -0.019999, 0.006999, 92.299972, 90.199943, 0.000000, 1.089003, 1.348002, 1.266001);
					case 9: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.807996, -0.023999, -0.002000, 92.299972, 90.199943, 0.000000, 1.037002, 1.348002, 1.347000);
					case 13: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.701996, 0.150999, -0.009000, 89.899902, 79.599929, 3.099789, 0.895000, 1.048002, 1.181005);
					case 17: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.790996, -0.014999, -0.002000, 92.299972, 90.199943, 0.000000, 0.952001, 1.197002, 1.346999);
					case 30: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.945992, 0.000000, -0.004000, 92.299972, 90.199943, 0.000000, 1.156003, 1.275003, 1.546003);
					case 31: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.826990, 0.016000, -0.003000, 92.299972, 87.899894, 0.000000, 1.185005, 1.347005, 1.367005);
					case 34: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.724995, 0.150999, -0.013000, 89.899902, 79.599929, 3.099789, 0.895000, 1.048002, 1.181005);
					case 39: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.832990, 0.032000, -0.004000, 92.299972, 87.899894, 0.000000, 1.012005, 1.347005, 1.367005);
					case 46: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.714990, 0.024000, -0.004000, 92.299972, 87.899894, 0.000000, 0.951005, 1.228004, 1.210005);
					case 51: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.700990, -0.000999, -0.004000, 92.299972, 87.899894, 0.000000, 0.943005, 1.228004, 1.208005);
					case 52: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.696990, 0.037000, 0.004999, 92.299972, 87.899894, 0.000000, 0.930005, 1.228004, 1.212006);
					case 54: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.721990, -0.024999, -0.000000, 92.299972, 92.499824, 0.000000, 0.938006, 1.233005, 1.250007);
					case 57: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.699990, -0.075999, -0.002000, 92.299972, 92.499824, 0.000000, 0.997005, 1.226006, 1.229006);
					case 58: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.679990, -0.037000, 0.001999, 92.299972, 92.499824, 0.000000, 0.941005, 1.226006, 1.209005);
					case 59: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.884989, 0.013999, -0.004000, 92.299972, 88.700065, 0.000000, 1.210007, 1.376011, 1.450010);
					case 60: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.878989, -0.002000, -0.004000, 92.299972, 88.700065, 0.000000, 0.964006, 1.265010, 1.450010);
					case 61: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.689996, 0.163999, 0.012999, 89.899902, 79.599929, 3.099789, 0.895000, 1.085002, 1.181005);
					case 63: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.711996, 0.146999, -0.007000, 89.899902, 79.599929, 3.099789, 0.895000, 1.085002, 1.181005);
					case 64: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.878989, 0.032999, -0.000000, 92.299972, 88.700065, 0.000000, 0.999005, 1.313011, 1.450010);
					case 66: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.790990, 0.013999, 0.000999, 92.299972, 88.700065, 0.000000, 0.958005, 1.118011, 1.360008);
					case 68: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.776990, -0.003000, 0.006000, 92.299972, 91.300025, 0.000000, 0.938005, 1.420011, 1.360008);
					case 70: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.803990, -0.034000, -0.004000, 92.299972, 91.300025, 0.000000, 1.178008, 1.311014, 1.360008);
					case 72: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.814989, -0.034000, -0.010000, 92.299972, 91.300025, 0.000000, 1.055009, 1.292015, 1.360008);
					case 73: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.692996, 0.180999, -0.001000, 89.899902, 79.599929, 3.099789, 0.895000, 1.085002, 1.181005);
					case 75: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.840989, -0.062000, 0.004000, 92.299972, 93.899986, 0.000000, 1.009007, 1.340016, 1.373009);
					case 79: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.819987, 0.005999, 0.004999, 92.299972, 89.000061, -1.600000, 1.044008, 1.333016, 1.373009);
					case 80: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.848987, -0.004000, 0.004999, 92.299972, 89.000061, -1.600000, 1.014007, 1.222015, 1.373009);
					case 82: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.762988, 0.015999, 0.005999, 92.299972, 89.000061, -1.600000, 0.939007, 1.222015, 1.314009);
					case 84: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.767988, -0.018000, -0.000000, 92.299972, 89.000061, -1.600000, 0.979007, 1.215016, 1.314009);
					case 96: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.698996, 0.168999, -0.003000, 89.899902, 79.599929, 3.099789, 0.895000, 1.085002, 1.181005);
					case 98: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.780987, 0.032999, 0.000999, 92.299972, 86.800094, -1.600000, 0.972007, 1.211016, 1.314009);
					case 100: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.764988, -0.077000, -0.007000, 92.299972, 94.299980, -1.600000, 1.160010, 1.300017, 1.314009);
					case 101: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.800987, -0.072999, -0.007000, 92.299972, 92.400009, -0.300000, 1.042010, 1.300017, 1.334010);
					case 102: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.734988, -0.021000, -0.006000, 92.299972, 91.500022, -0.300000, 0.876010, 1.005015, 1.225009);
					case 103: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.709988, 0.011999, -0.002000, 92.299972, 90.200042, -0.300000, 0.876010, 1.005015, 1.176008);
					case 104: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.662989, 0.016999, -0.002000, 92.299972, 89.000061, -0.300000, 0.876010, 1.005015, 1.114007);
					case 105: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.693988, -0.080000, -0.005000, 92.299972, 94.900062, -0.300000, 1.096011, 1.215020, 1.209010);
					case 106: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.727988, -0.097000, -0.016000, 92.299972, 94.900062, -0.300000, 1.174012, 1.282021, 1.272012);
					case 107: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.767987, -0.090000, -0.007000, 92.299972, 94.900062, -0.300000, 1.113013, 1.316021, 1.314013);
					case 108: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.787987, 0.008999, -0.004999, 92.299972, 90.100097, -0.300000, 1.110013, 1.316021, 1.329014);
					case 109: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.802987, -0.016000, -0.007999, 92.299972, 90.100097, -0.300000, 1.044014, 1.225023, 1.329014);
					case 110: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.798987, 0.029999, -0.000999, 92.299972, 87.300125, -0.300000, 1.022014, 1.225023, 1.329014);
					case 116: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.769987, 0.051999, 0.001000, 92.299972, 85.500137, -0.300000, 0.940015, 1.167022, 1.297014);
					case 111: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.793987, 0.029999, 0.001000, 92.299972, 87.300125, -0.300000, 1.050014, 1.225023, 1.329014);
					case 112: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.793987, 0.029999, 0.001000, 92.299972, 87.300125, -0.300000, 1.050014, 1.225023, 1.329014);
					case 133: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.732988, 0.013999, -0.000999, 92.299972, 90.400131, -0.300000, 0.871015, 1.102020, 1.229014);
					case 134: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.735988, -0.009000, 0.002000, 92.299972, 90.400131, -0.300000, 1.067015, 1.205020, 1.260014);
					case 135: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.742988, -0.024000, -0.000999, 92.299972, 90.400131, -0.300000, 1.131015, 1.359021, 1.260014);
					case 136: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.731988, -0.024000, -0.000999, 92.299972, 90.400131, -0.300000, 1.131015, 1.359021, 1.260014);
					case 141: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.657988, 0.025999, 0.003000, 92.299972, 90.400131, -0.300000, 0.883014, 0.984021, 1.117014);
					case 148: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.755987, 0.001999, 0.003000, 92.299972, 90.400131, -0.300000, 0.902015, 1.135021, 1.272015);
					case 151: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.760987, 0.001999, -0.022999, 92.299972, 90.400131, -0.300000, 0.902015, 1.135021, 1.272015);
					case 152: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.695987, 0.005000, 0.001000, 92.299972, 90.400131, -0.300000, 0.902015, 1.039021, 1.132015);
					case 155: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.697986, -0.001999, -0.019999, 92.299972, 90.400131, -0.300000, 1.094016, 1.159021, 1.197017);
					case 163: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.706986, -0.089000, -0.006999, 92.299972, 95.400054, -0.300000, 1.155017, 1.349023, 1.247017);
					case 164: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.723986, 0.030999, -0.001999, 92.299972, 87.000038, -0.300000, 1.155017, 1.267023, 1.247017);
					case 165: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.652987, 0.020999, -0.006999, 92.299972, 89.000030, -0.300000, 0.877016, 0.977023, 1.099016);
					case 166: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.688996, 0.049999, -0.003000, 89.899902, 88.699859, 3.099789, 0.895000, 1.085002, 1.181005);
					case 167: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.707986, -0.093000, -0.009999, 92.299972, 94.700050, -0.300000, 1.048017, 1.300025, 1.235019);
					case 172: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.746986, -0.089999, -0.009999, 92.299972, 94.700050, -0.300000, 1.130016, 1.372026, 1.276019);
					case 173: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.696996, 0.020999, -0.007000, 89.899902, 88.699859, 3.099789, 0.895000, 1.085002, 1.181005);
					case 174: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.775985, -0.100000, -0.009999, 92.299972, 94.700050, -0.300000, 1.074015, 1.372026, 1.276019);
					case 175: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.725986, -0.080000, -0.008999, 92.299972, 94.700050, -0.300000, 1.012015, 1.177025, 1.260019);
					case 181: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.744986, -0.088000, -0.008999, 92.299972, 94.700050, -0.300000, 1.061015, 1.177025, 1.260019);
					case 186: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.700986, -0.091000, -0.008999, 92.299972, 94.000015, -0.300000, 1.028014, 1.214025, 1.235018);
					case 187: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.671987, -0.068000, -0.008999, 92.299972, 94.000015, -0.300000, 1.102019, 1.325028, 1.170015);
					case 188: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.539987, -0.003000, 0.005000, 92.299972, 94.000015, -0.300000, 0.769019, 1.138027, 0.964013);
					case 191: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.530988, -0.003000, 0.005000, 92.299972, 94.000015, -0.300000, 0.769019, 1.138027, 0.964013);
					case 198: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.530988, -0.003000, 0.005000, 92.299972, 94.000015, -0.300000, 0.769019, 1.138027, 0.964013);
					case 202: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.777998, 0.002999, -0.031000, 0.000000, 87.800041, 89.299957, 0.972000, 1.304000, 1.296999);
					case 211: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.724998, -0.021000, -0.042999, 0.000000, 87.800041, 94.999885, 1.217001, 1.339001, 1.206999);
					case 225: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.712998, 0.006999, -0.035999, 0.000000, 87.800041, 94.999885, 0.877002, 1.339001, 1.206999);
					case 231: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.858998, -0.100000, -0.003000, -87.699951, 84.800041, -176.399826, 1.169002, 1.367000, 1.448999);
					case 232: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.470999, -0.024000, -0.007000, -87.699951, 86.500015, -176.399826, 0.894002, 0.913000, 0.812999);
					case 234: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.810999, 0.005999, -0.046000, 0.299999, 86.799797, 87.999984, 1.146999, 1.329000, 1.343000);
					case 235: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.810999, -0.015000, -0.024000, 0.299999, 87.499786, 87.999984, 1.146999, 1.329000, 1.343000);
					case 236: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.807999, -0.008000, 0.001999, 0.299999, 89.299743, 87.999984, 1.146999, 1.283999, 1.343000);
					case 239: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.800999, -0.013000, -0.013000, 0.299999, 89.499740, 87.999984, 1.024998, 1.206999, 1.343000);
					case 247: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.811999, -0.013000, -0.003000, 0.299999, 89.499740, 87.999984, 1.024998, 1.298999, 1.343000);
					case 248: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.801999, -0.013000, -0.006000, 0.299999, 89.499740, 87.999984, 1.024998, 1.298999, 1.343000);
					case 254: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.801999, -0.013000, 0.001999, 0.299999, 89.799736, 87.999984, 1.024998, 1.298999, 1.343000);
					case 255: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.682996, 0.044999, -0.007000, 89.899902, 88.699859, 3.099789, 0.895000, 1.085002, 1.181005);
					case 266: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.798999, 0.000999, 0.006999, 0.299999, 89.799736, 87.999984, 1.236999, 1.416000, 1.343000);
					case 268: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.690999, 0.008999, 0.003999, 0.299999, 89.799736, 87.999984, 1.046000, 1.227000, 1.180001);
					case 274: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.688000, -0.033000, 0.005999, 0.299999, 90.199729, 87.999984, 1.106000, 1.279000, 1.180001);
					case 275: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.696999, -0.006000, -0.000000, 0.299999, 90.199729, 87.999984, 1.106000, 1.279000, 1.180001);
					case 276: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.858998, -0.022000, 0.005999, 0.299999, 90.199729, 87.999984, 1.154000, 1.333001, 1.427002);
					case 280: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.562998, 0.025999, 0.008999, 0.299999, 90.799720, 87.999984, 0.941000, 1.178001, 0.964003);
					case 282: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.543998, -0.013000, 0.008999, 3.800002, 91.399772, 88.799903, 1.078000, 1.274001, 0.964003);
					case 283: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.558998, -0.013000, 0.008999, 3.800002, 91.399772, 88.799903, 1.090001, 1.194001, 0.964003);
					case 284: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.572998, 0.029000, 0.016999, 3.800002, 91.399772, 88.799903, 0.898001, 0.992002, 0.964003);
					case 285: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.805997, 0.008000, 0.032999, 3.800002, 91.399772, 88.799903, 1.145000, 1.307002, 1.339003);
					case 287: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.566998, 0.021000, 0.015999, 3.800002, 91.399772, 88.799903, 0.883000, 1.034001, 0.998005);
					case 295: SetPlayerAttachedObject (playerid, 3, temp_magazin_aks_slot_1[playerid], 2, -0.858995, 0.003000, -0.054000, 27.099987, 86.899902, 59.999767, 1.209000, 1.325002, 1.404005);
					default: SendInf(playerid, "Маска не будет отображена на данной одежде");
				}
			}
		}	
	}
	if(temp_magazin_aks_slot_2[playerid])
	{
		switch(temp_magazin_aks_slot_2[playerid])// Спина
		{
			case 11002, 11003, 11004, 11005, 11006, 11007: // Рюкзаки
			{
				switch(skin)
				{
					case 8: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.090999, -0.099999, 0.000000, -4.099999, 89.200042, -178.599945, 1.000000, 1.000000, 1.000000);
					case 9: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.082000, -0.071000, -0.002999, 176.800003, 90.599960, 1.900004, 1.000000, 1.000000, 1.000000); 
					case 13: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.084999, -0.095999, -0.005999, -4.099999, 88.700065, -178.599945, 1.000000, 1.000000, 1.000000);
					case 17: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.156999, -0.090999, -0.001999, -4.099999, 87.900039, -178.599945, 1.000000, 1.000000, 1.000000);
					case 27: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.114999, -0.098999, -0.005999, -4.099999, 88.700065, -178.599945, 1.000000, 1.000000, 1.000000);
					case 30: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.072999, -0.085999, -0.007999, -10.399994, 91.899902, -173.500076, 0.996997, 0.878000, 1.000000);
					case 31: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.116999, -0.050999, -0.012999, -19.899986, 88.300071, -156.699768, 0.875000, 0.845999, 1.024000);
					case 34: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.070999, -0.125999, 0.000000, -4.099999, 89.200042, -178.599945, 1.000000, 1.000000, 1.000000);
					case 39: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.118000, -0.102000, -0.002999, 176.800003, 90.599960, 1.900004, 1.000000, 1.000000, 1.000000);
					case 46: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.099999, -0.091999, 0.008000, -4.099999, 89.200042, -178.599945, 1.000000, 1.000000, 1.000000);
					case 51: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.192999, -0.084999, -0.001999, -4.099999, 89.200042, -178.599945, 1.000000, 1.000000, 1.000000);
					case 52: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.131999, -0.060999, 0.008000, -4.099999, 89.200042, -178.599945, 1.000000, 1.000000, 1.000000);
					case 54: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.120999, -0.087999, 0.014000, -4.099999, 87.900039, -178.599945, 1.000000, 1.000000, 1.000000);
					case 57: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.172999, -0.106999, -0.001999, -4.099999, 89.200042, -178.599945, 1.000000, 1.000000, 1.000000);
					case 58: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.101999, -0.090999, -0.001999, -4.099999, 89.200042, -178.599945, 1.000000, 1.000000, 1.000000);
					case 59: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.097999, -0.088999, -0.001999, -4.099999, 87.900039, -178.599945, 1.000000, 1.000000, 1.000000);
					case 60: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.077999, -0.107999, -0.001999, -4.099999, 89.200042, -178.599945, 1.000000, 1.000000, 1.000000);
					case 61: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.155999, -0.071999, 0.000999, -5.699998, 91.499900, -175.900131, 1.098999, 1.023998, 1.000000);
					case 63: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.070999, -0.062999, 0.000000, -4.099999, 89.200042, -178.599945, 1.000000, 1.000000, 1.000000);
					case 64: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.130999, -0.053999, -0.012999, -19.899986, 88.300071, -159.300003, 0.875000, 0.838997, 1.024000);
					case 66: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.104999, -0.084999, -0.001999, -4.099999, 89.200042, -178.599945, 1.000000, 1.000000, 1.000000);
					case 68: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.186999, -0.046999, 0.008000, -4.099999, 89.200042, -178.599945, 1.000000, 1.000000, 1.000000);
					case 69: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.077999, -0.107999, -0.001999, -4.099999, 89.200042, -178.599945, 1.000000, 1.000000, 1.000000);
					case 70: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.077999, -0.110999, -0.001999, -4.099999, 89.200042, -178.599945, 1.000000, 1.000000, 1.000000);
					case 72: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.080999, -0.118999, -0.012000, -4.099999, 87.900039, -178.599945, 1.000000, 1.000000, 1.000000);
					case 73: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.167999, -0.065999, -0.001000, -6.099996, 91.099899, -170.700134, 1.051000, 1.056999, 1.000000);
					case 75: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.090999, -0.099999, 0.000000, -4.099999, 89.200042, -178.599945, 1.000000, 1.000000, 1.000000);
					case 79: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.084000, -0.098000, -0.002999, 176.800003, 90.599960, 1.900004, 1.000000, 1.000000, 1.000000);
					case 80: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.090999, -0.099999, 0.000000, -4.099999, 89.200042, -178.599945, 1.000000, 1.000000, 1.000000);
					case 82: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.188999, -0.070999, 0.008000, -4.099999, 89.200042, -178.599945, 1.000000, 1.000000, 1.000000);
					case 84: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.131999, -0.120999, -0.000999, -4.099999, 88.700065, -178.599945, 1.000000, 1.000000, 1.000000);
					case 96: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.053999, -0.108999, -0.011999, -4.099999, 88.700065, -178.599945, 1.000000, 1.000000, 1.000000);
					case 98: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.116999, -0.072999, -0.000999, -4.099999, 88.700065, -178.599945, 1.000000, 1.000000, 1.000000);
					case 100: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.106000, -0.119000, -0.020000, 176.800003, 90.599960, 1.900004, 1.000000, 1.000000, 1.000000);
					case 101: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.105999, -0.112999, -0.000999, -4.099999, 88.700065, -178.599945, 1.000000, 1.000000, 1.000000);
					case 102: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.150999, -0.072999, -0.012000, -4.099999, 87.900039, -178.599945, 1.000000, 1.000000, 1.000000); 
					case 103: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.051999, -0.080999, -0.009999, -4.099999, 91.400024, -178.599945, 1.000000, 1.000000, 1.000000);
					case 104: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.141999, -0.081999, -0.009999, -4.099999, 91.400024, -178.599945, 1.000000, 1.000000, 1.000000); 
					case 105: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.116999, -0.083999, -0.009999, -4.099999, 91.400024, -178.599945, 1.000000, 1.000000, 1.000000); 
					case 106: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.066999, -0.100999, -0.009999, -4.099999, 91.400024, -178.599945, 1.000000, 1.000000, 1.000000); 
					case 107: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.081999, -0.091999, 0.002000, -4.099999, 91.400024, -178.599945, 1.000000, 1.000000, 1.000000);
					case 108: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.111999, -0.079999, -0.000999, -4.099999, 91.400024, -178.599945, 1.000000, 1.000000, 1.000000);
					case 109: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.106999, -0.107999, 0.002000, -4.099999, 91.400024, -178.599945, 1.000000, 1.000000, 1.000000);
					case 110: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.111999, -0.085999, -0.000999, -4.099999, 88.700065, -178.599945, 1.000000, 1.000000, 1.000000);
					case 116: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.156999, -0.072999, -0.000999, -4.099999, 88.700065, -178.599945, 1.000000, 1.000000, 1.000000);
					case 111: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.099999, -0.084999, 0.008000, -4.099999, 89.200042, -178.599945, 1.000000, 1.000000, 1.000000);
					case 112: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.099999, -0.080999, 0.008000, -4.099999, 89.200042, -178.599945, 1.000000, 1.000000, 1.000000);
					case 133: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.137999, -0.050999, 0.000000, -4.099999, 89.200042, -178.599945, 1.000000, 1.000000, 1.000000);
					case 134: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.175000, -0.082000, -0.002999, 176.800003, 90.599960, 1.900004, 1.000000, 1.000000, 1.000000);
					case 135: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.117000, -0.089000, -0.013000, 176.800003, 90.599960, 2.600004, 1.000000, 1.000000, 1.000000);
					case 136: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.119000, -0.112000, -0.002999, 176.800003, 90.599960, 1.900004, 1.000000, 1.000000, 1.000000);
					case 141: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.142999, -0.067999, -0.001999, -4.099999, 87.900039, -178.599945, 1.000000, 1.000000, 1.000000);
					case 148: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.155999, -0.064999, 0.000000, -4.099999, 89.200042, -178.599945, 1.000000, 1.000000, 1.000000);
					case 163: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.141999, -0.103999, -0.011999, -4.099999, 88.700065, -178.599945, 1.000000, 1.000000, 1.000000);
					case 164: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.096999, -0.092999, -0.012000, -4.099999, 87.900039, -178.599945, 1.000000, 1.000000, 1.000000);
					case 165: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.154999, -0.055999, -0.012000, -4.099999, 87.900039, -178.599945, 1.000000, 1.000000, 1.000000);
					case 166: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.143999, -0.108999, -0.000999, -4.099999, 88.700065, -178.599945, 1.000000, 1.000000, 1.000000);
					case 172: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.147999, -0.067999, -0.011999, -4.099999, 88.700065, -178.599945, 1.000000, 1.000000, 1.000000);
					case 173: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.138999, -0.086999, -0.011999, -4.099999, 88.700065, -178.599945, 1.000000, 1.000000, 1.000000);
					case 174: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.095999, -0.102999, -0.011999, -4.099999, 88.700065, -178.599945, 1.000000, 1.000000, 1.000000);
					case 175: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.089999, -0.086999, -0.011999, -4.099999, 88.700065, -178.599945, 1.000000, 1.000000, 1.000000);  
					case 181: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.066000, -0.078000, -0.019000, 176.800003, 90.599960, -3.099998, 1.000000, 1.000000, 1.000000);
					case 186: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.174999, -0.102999, -0.000999, -4.099999, 88.700065, -178.599945, 1.000000, 1.000000, 1.000000);
					case 187: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.110999, -0.096999, -0.012000, -4.099999, 87.900039, -178.599945, 1.000000, 1.000000, 1.000000);
					case 188: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.163999, -0.047999, -0.000999, -4.099999, 88.700065, -178.599945, 1.000000, 1.000000, 1.000000);
					case 191: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.164999, -0.065999, -0.001000, -6.099996, 91.099899, -170.700134, 1.051000, 1.056999, 1.000000);
					case 198: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.079000, -0.102000, -0.002999, 176.800003, 90.599960, 1.900004, 1.000000, 1.000000, 1.000000);
					case 202: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.129999, -0.087999, -0.000999, -4.099999, 88.700065, -178.599945, 1.000000, 1.000000, 1.000000);
					case 211: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.085999, -0.103999, -0.005999, -4.099999, 88.700065, -178.599945, 1.000000, 1.000000, 1.000000);
					case 225: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.094000, -0.100000, -0.002999, 176.800003, 90.599960, 1.900004, 1.000000, 1.000000, 1.000000);
					case 231: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.075000, -0.069000, -0.002999, 176.800003, 90.599960, 1.900004, 1.000000, 1.000000, 1.000000);
					case 232: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.114000, -0.064000, -0.003999, 176.800003, 90.599960, 1.900004, 1.000000, 1.000000, 1.000000);
					case 234: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.162000, -0.091000, -0.003999, 176.800003, 90.599960, 1.900004, 1.000000, 1.000000, 1.000000);
					case 235: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.050000, -0.091000, 0.006000, 176.800003, 90.599960, 1.900004, 1.000000, 1.000000, 1.000000); 
					case 236: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.137000, -0.079000, 0.006000, 176.800003, 90.599960, 1.900004, 1.000000, 1.000000, 1.000000); 
					case 239: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.167000, -0.088000, -0.008999, 176.800003, 90.599960, 2.600004, 1.000000, 1.000000, 1.000000);
					case 247: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.032999, -0.095999, -0.007999, -22.199998, 89.600013, -159.499954, 1.000000, 1.000000, 1.000000); 
					case 248: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.089999, -0.101999, -0.012999, -22.199998, 89.600013, -155.999771, 1.000000, 1.000000, 1.000000);
					case 254: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.160999, -0.102999, 0.000000, -22.199998, 89.600013, -159.499954, 1.000000, 1.000000, 1.000000);
					case 255: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.165999, -0.071999, -0.015000, -5.699998, 91.499900, -169.300125, 1.098999, 1.023998, 1.000000);
					case 263: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.090999, -0.099999, 0.000000, -4.099999, 89.200042, -178.599945, 1.000000, 1.000000, 1.000000);
					case 266: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.130999, -0.105999, -0.007999, -4.099999, 87.600013, -178.599945, 1.000000, 1.000000, 1.000000);
					case 268: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.143999, -0.061999, 0.000000, -4.099999, 89.200042, -178.599945, 1.000000, 1.000000, 1.000000);
					case 274: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.154999, -0.081999, 0.000000, -4.099999, 89.200042, -178.599945, 1.000000, 1.000000, 1.000000);
					case 275: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.151999, -0.072999, -0.004999, -4.099999, 89.200042, -178.599945, 1.000000, 1.000000, 1.000000);
					case 276: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.077999, -0.072999, -0.001999, -4.099999, 89.200042, -178.599945, 1.000000, 1.000000, 1.000000);
					case 280: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.075999, -0.087999, -0.007999, -4.099999, 87.600013, -178.599945, 1.000000, 1.000000, 1.000000);
					case 283: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.154999, -0.091999, -0.007999, -4.099999, 87.600013, -178.599945, 1.000000, 1.000000, 1.000000);
					case 284: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.130999, -0.042999, -0.007999, -4.099999, 87.600013, -178.599945, 1.000000, 1.000000, 1.000000); 
					case 285: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.105999, -0.067999, 0.006000, -4.099999, 87.600013, -178.599945, 1.000000, 1.000000, 1.000000);
					case 287: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.151999, -0.085999, -0.001000, -6.099996, 91.099899, -170.700134, 1.000000, 1.000000, 1.000000);
					case 295: SetPlayerAttachedObject (playerid, 4, temp_magazin_aks_slot_2[playerid], 1, 0.131999, -0.082999, -0.015000, -6.099996, 91.099899, -170.700134, 1.051000, 1.056999, 1.000000);
					default: SendInf(playerid, "Рюкзак не будет отображен на данной одежде");
				}
			}
		}
	}
	return true;
}
