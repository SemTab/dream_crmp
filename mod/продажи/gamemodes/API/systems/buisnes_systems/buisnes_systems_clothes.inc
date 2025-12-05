


new all_clothes_variants_woomen[][SKIN_DATA] =
{
	{9, 13000},
	{39, 15000},
	{232, 20000},
	{225, 25000},
	{231, 45000},
	{102, 380000},
	{103, 43000},
	{104, 350000}
};

new all_clothes_variants_man[][SKIN_DATA] =
{ 

	{79, 20000},
	{136, 23000},
	{235, 32000},
	{239, 33000},
	{135, 35000},
	{236, 37000},
	{234, 45000},
	{51, 125000},
	{56, 145000},
	{57, 105000},
	{58, 148000},
	{82, 160000},
	{52, 200000},
	{105, 580000},
	{106, 620000},
	{107, 650000},
	{101, 680000},
	{98, 720000},
	{109, 730000},
	{116, 980000},
	{108, 1000000}	

};

stock get_skin_price(playerid, index) 
{
	if(pData[playerid][pSex] == 2)
	{
		if(index < 0 || index > sizeof(all_clothes_variants_woomen) - 1) return 0;
		return all_clothes_variants_woomen[index][skinPrice];
	}
	else
	{
		if(index < 0 || index > sizeof(all_clothes_variants_man) - 1) return 0;
		return all_clothes_variants_man[index][skinPrice];		
	}
}

stock get_skin_id(playerid, index) 
{
	if(pData[playerid][pSex] == 2)
	{	
		if(index < 0 || index > sizeof(all_clothes_variants_woomen) - 1) return 0;
		return all_clothes_variants_woomen[index][skinID];
	}
	else
	{
		if(index < 0 || index > sizeof(all_clothes_variants_man) - 1) return 0;
		return all_clothes_variants_man[index][skinID];		
	}



}

stock dialog_show_select_clothes(playerid, type)
{


	switch(type)
	{
		case BUISNES_CLOTHES:
		{
			SPD(playerid, DIALOG_START_SELECT_CLOTHES_1, DIALOG_STYLE_MSGBOX, !""cBLUE"Магазин одежды", !"\
			"cBLUE"-"cWH" Добро пожаловать в Магазин Одежды!\n\n\
			Мы поможем Вам подобрать одежду по Вашему вкусу и стилю, приступим?", !"Да", !"Нет");			
		}
	}

	return true;
}

stock start_select_clothes_shop(playerid, type_shop)
{
	switch(type_shop)
	{
		case BUISNES_CLOTHES:
		{


			SetPlayerVirtualWorld(playerid, playerid+1);

			show_clothes_start_1(playerid);

			TogglePlayerControllable(playerid, false);

			SetPVarIntNew(playerid, "type_select_clothes_shop", BUISNES_CLOTHES);
		}
	}

	return true;
}


stock show_clothes_start_1(playerid)
{


	textdraw_clothes_select(playerid, TEXTDRAW_SHOW, BUISNES_CLOTHES);

	if(pData[playerid][pSex] == 1)
	{
				
		InterpolateCameraPos(playerid, -76.247840, 950.448669, 1598.918823, -86.793464, 958.899414, 1598.814575, 1500);
		InterpolateCameraLookAt(playerid, -72.952079, 954.203918, 1598.729492, -81.805633, 959.039733, 1598.495483, 1500);

		SetPlayerPosEx(playerid, -82.8325,958.8977,1597.9788,89.6432);
		SetPlayerSkin(playerid, all_clothes_variants_man[0][skinID]);

	}
	else
	{
		InterpolateCameraPos(playerid, -61.276138, 951.690185, 1598.646118, -49.390293, 958.780395, 1598.758300, 1500);
		InterpolateCameraLookAt(playerid, -64.610664, 955.411376, 1598.829223, -54.384803, 958.727905, 1598.530029, 1500);

		SetPlayerPosEx(playerid, -52.9678,958.8631,1597.9788,268.5029);
		SetPlayerSkin(playerid, all_clothes_variants_woomen[0][skinID]);
	}


	textdraw_clothes_select(playerid, TEXTDRAW_UPDATE, BUISNES_CLOTHES);

	clothes_select_count[playerid] = 0;

	return true;
}


stock show_clothes_next_1(playerid)
{
	if(pData[playerid][pSex] == 1)
	{
		if(clothes_select_count[playerid] == 20)
			return true;
	
		clothes_select_count[playerid]++;

		SetPlayerSkin(playerid, get_skin_id(playerid, clothes_select_count[playerid]));
		textdraw_clothes_select(playerid, TEXTDRAW_UPDATE, BUISNES_CLOTHES);

	}
	else
	{
		if(clothes_select_count[playerid] == 7)
			return true;	

		clothes_select_count[playerid]++;

		SetPlayerSkin(playerid, get_skin_id(playerid, clothes_select_count[playerid]));
		textdraw_clothes_select(playerid, TEXTDRAW_UPDATE, BUISNES_CLOTHES);

	}

	return true;
}



stock show_clothes_prew_1(playerid)
{

	if(pData[playerid][pSex] == 1)
	{
		if(clothes_select_count[playerid] == 0)
			return true;
	
		clothes_select_count[playerid]--;

		SetPlayerSkin(playerid, get_skin_id(playerid, clothes_select_count[playerid]));
		textdraw_clothes_select(playerid, TEXTDRAW_UPDATE, BUISNES_CLOTHES);

	}
	else
	{
		if(clothes_select_count[playerid] == 0)
			return true;	

		clothes_select_count[playerid]--;

		SetPlayerSkin(playerid, get_skin_id(playerid, clothes_select_count[playerid]));
		textdraw_clothes_select(playerid, TEXTDRAW_UPDATE, BUISNES_CLOTHES);

	}

	return true;
}


stock textdraw_clothes_select(playerid, status, type_salon)
{
	
	switch(status)
	{
		case TEXTDRAW_SHOW:
		{
			switch(type_salon)
			{
				case BUISNES_CLOTHES:
				{


					TextDrawShowForPlayer(playerid, clothes_select_td[0]);
					TextDrawShowForPlayer(playerid, clothes_select_td[1]);
					TextDrawShowForPlayer(playerid, clothes_select_td[2]);
					TextDrawShowForPlayer(playerid, clothes_select_td[3]);
					TextDrawShowForPlayer(playerid, clothes_select_td[4]);
					TextDrawShowForPlayer(playerid, clothes_select_td[5]);

					create_clothes_shop_price(playerid);
				}
			}
			SelectTextDraw(playerid, COLOR_BLUE);


		}
		case TEXTDRAW_HIDE:
		{

			TextDrawHideForPlayer(playerid, clothes_select_td[0]);
			TextDrawHideForPlayer(playerid, clothes_select_td[1]);
			TextDrawHideForPlayer(playerid, clothes_select_td[2]);
			TextDrawHideForPlayer(playerid, clothes_select_td[3]);
			TextDrawHideForPlayer(playerid, clothes_select_td[4]);
			TextDrawHideForPlayer(playerid, clothes_select_td[5]);
			
			PlayerTextDrawHideEx(playerid, clothes_select_price[playerid]);

			CancelSelectTextDraw(playerid);

		}
		case TEXTDRAW_UPDATE:
		{
			new 
				format_str[25];

			new 
				clothes_id = clothes_select_count[playerid];


		 	format(format_str, sizeof(format_str),"%d_RUB", get_skin_price(playerid, clothes_id));
		 	PlayerTextDrawSetString(playerid, clothes_select_price[playerid], format_str);
		 	PlayerTextDrawShow(playerid, clothes_select_price[playerid]);

		}
	}

	return true;
}

stock buy_skin_player_click(playerid)
{
	SPD(playerid, DIALOG_BUY_CLOTHES_PREW, DIALOG_STYLE_MSGBOX, !""cBLUE"Магазин одежды", !"\
	"cBLUE"-"cWH" Вы действительно хотите приобрести данную одежду?", !"Да", !"Нет");	

	return true;
}

stock buy_skin_player_prew(playerid)
{
	new 
		clothes_id = clothes_select_count[playerid];


	new 
		skin_id = get_skin_id(playerid, clothes_select_count[playerid]),
		skin_price = get_skin_price(playerid, clothes_id);

	if(GetPlayerMoneyEx(playerid) < skin_price)
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
		return SendErr(playerid, "У вас недостаточно денежных средств для покупки!");
	}

	if(pData[playerid][pSkin] != 140)
	{
		if(pData[playerid][pHouse] != -1 && pData[playerid][pFlate] == -1)
		{
			new 
				h = pData[playerid][pHouse];

			if(House[h][wardrobe_status] != 0)
			{
				if(House[h][wardrobe_skin_1] == -1)
				{
					House[h][wardrobe_skin_1] = pData[playerid][pSkin];
					SendInf(playerid, "Ваш старый скин был помещён в шкаф дома, на первую вешалку!");

					buy_skin_transfer_money(playerid, skin_price);

					pData[playerid][pSkin] = skin_id;
					UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);

					return exit_select_clothes(playerid);
				}
				else if(House[h][wardrobe_skin_2] == -1)
				{
					House[h][wardrobe_skin_2] = pData[playerid][pSkin];
					SendInf(playerid, "Ваш старый скин был помещён в шкаф дома, на вторую вешалку!");

					buy_skin_transfer_money(playerid, skin_price);

					pData[playerid][pSkin] = skin_id;
					UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);

					return exit_select_clothes(playerid);
				}
				else if(House[h][wardrobe_skin_3] == -1)
				{
					House[h][wardrobe_skin_3] = pData[playerid][pSkin];
					SendInf(playerid, "Ваш старый скин был помещён в шкаф дома, на третью вешалку!");

					buy_skin_transfer_money(playerid, skin_price);

					pData[playerid][pSkin] = skin_id;
					UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);

					return exit_select_clothes(playerid);
				}
				else if(House[h][wardrobe_skin_1] != -1 && House[h][wardrobe_skin_2] != -1 && House[h][wardrobe_skin_3] != -1)
				{
					SPD(playerid, DIALOG_BUY_CLOTHES_FINAL, DIALOG_STYLE_MSGBOX, !""cBLUE"Магазин одежды", !"\
					"cBLUE"-"cWH" В шкафу Вашего дома недостаточно места!\n\n\
					Текущая одежда будет заменена новой, Вы уверены в покупке?", !"Да", !"Нет");	
				}
			}
			else
			{
				SPD(playerid, DIALOG_BUY_CLOTHES_FINAL, DIALOG_STYLE_MSGBOX, !""cBLUE"Магазин одежды", !"\
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
				if(flate[h][wardrobe_skin_1] == -1)
				{
					flate[h][wardrobe_skin_1] = pData[playerid][pSkin];
					SendInf(playerid, "Ваш старый скин был помещён в шкаф квартиры, на первую вешалку!");

					buy_skin_transfer_money(playerid, skin_price);

					pData[playerid][pSkin] = skin_id;
					UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);

					return exit_select_clothes(playerid);
				}
				else if(flate[h][wardrobe_skin_2] == -1)
				{
					flate[h][wardrobe_skin_2] = pData[playerid][pSkin];
					SendInf(playerid, "Ваш старый скин был помещён в шкаф квартиры, на вторую вешалку!");

					buy_skin_transfer_money(playerid, skin_price);

					pData[playerid][pSkin] = skin_id;
					UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);

					return exit_select_clothes(playerid);
				}
				else if(flate[h][wardrobe_skin_3] == -1)
				{
					flate[h][wardrobe_skin_3] = pData[playerid][pSkin];
					SendInf(playerid, "Ваш старый скин был помещён в шкаф квартиры, на третью вешалку!");

					buy_skin_transfer_money(playerid, skin_price);

					pData[playerid][pSkin] = skin_id;
					UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);

					return exit_select_clothes(playerid);
				}
				else if(flate[h][wardrobe_skin_1] != -1 && flate[h][wardrobe_skin_2] != -1 && flate[h][wardrobe_skin_3] != -1)
				{
					SPD(playerid, DIALOG_BUY_CLOTHES_FINAL, DIALOG_STYLE_MSGBOX, !""cBLUE"Магазин одежды", !"\
					"cBLUE"-"cWH" В шкафу Вашей квартиры недостаточно места!\n\n\
					Текущая одежда будет заменена новой, Вы уверены в покупке?", !"Да", !"Нет");	
				}
			}
			else
			{
				SPD(playerid, DIALOG_BUY_CLOTHES_FINAL, DIALOG_STYLE_MSGBOX, !""cBLUE"Магазин одежды", !"\
				"cBLUE"-"cWH" У вас нет шкафа!\n\n\
				Текущая одежда будет заменена новой, Вы уверены в покупке?", !"Да", !"Нет");	
			}
		}
		else if(pData[playerid][pHouse] == -1 && pData[playerid][pFlate] == -1)
		{
			SPD(playerid, DIALOG_BUY_CLOTHES_FINAL, DIALOG_STYLE_MSGBOX, !""cBLUE"Магазин одежды", !"\
			"cBLUE"-"cWH" У вас нет шкафа!\n\n\
			Текущая одежда будет заменена новой, Вы уверены в покупке?", !"Да", !"Нет");	
		}		
	}
	else
	{
		buy_skin_accept_final(playerid);
	}
	return true;
}

stock buy_skin_accept_final(playerid)
{
	new 
		clothes_id = clothes_select_count[playerid];


	new 
		skin_id = get_skin_id(playerid, clothes_select_count[playerid]),
		skin_price = get_skin_price(playerid, clothes_id);

	if(GetPlayerMoneyEx(playerid) < skin_price)
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
		return SendErr(playerid, "У вас недостаточно денежных средств для покупки!");
	}

	buy_skin_transfer_money(playerid, skin_price);

	pData[playerid][pSkin] = skin_id;
	UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);

	return exit_select_clothes(playerid);
}

stock buy_skin_transfer_money(playerid, price_skin)
{
	new 
		b_id = GetPVarIntNew(playerid, "buisnes_enter_id");

	buisness_bank_update(b_id, floatround(price_skin*0.5), "Покупка скина");

 	format(String144, sizeof(String144), "Покупка скина %d | №%d", clothes_select_count[playerid], b_id);
	give_money(playerid, -price_skin, String144);

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_buy_skin", 4000);

	check_quest_prize_start(playerid, 14);

	SendSucc(playerid, "Вы успешно приобрели новую одежду!");

	return true;
}

stock exit_select_clothes(playerid)
{
	new 
		type = GetPVarIntNew(playerid, "type_select_clothes_shop"),
		b_id = GetPVarIntNew(playerid, "buisnes_enter_id");

	switch(type)
	{
		case BUISNES_CLOTHES:
		{
			textdraw_clothes_select(playerid, TEXTDRAW_HIDE, BUISNES_CLOTHES);

			SetPlayerSkin(playerid, pData[playerid][pSkin]);

			CancelSelectTextDraw(playerid);
			SetCameraBehindPlayer(playerid);

			SetPlayerVirtualWorld(playerid, b_id);
			TogglePlayerControllable(playerid, true);
			SetPlayerPosEx(playerid, -67.8017,964.6206,1597.9788,0.9658);
		}
	}

	clear_pvar_select_clothes(playerid);
	return true;
}


stock clear_pvar_select_clothes(playerid)
{

	DeletePVarNew(playerid, "type_select_clothes_shop");

	clothes_id_buy[playerid] = 0;
	clothes_select_count[playerid] = 0;

	return true;
}
