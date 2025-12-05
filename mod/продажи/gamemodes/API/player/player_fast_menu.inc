
	
stock show_fast_menu(playerid, type, status)
{

	switch(type)
	{
		case FAST_MENU_GENERAL_MENU:
		{
			switch(status)
			{
				case TEXTDRAW_SHOW:
				{
					show_fast_menu(playerid, FAST_MENU_GENERAL_PLAYER, TEXTDRAW_HIDE);

					TextDrawShowForPlayer(playerid, fast_menu_general_1[0]);
					TextDrawShowForPlayer(playerid, fast_menu_general_1[1]);
					TextDrawShowForPlayer(playerid, fast_menu_general_1[2]);
					TextDrawShowForPlayer(playerid, fast_menu_general_1[3]);
					TextDrawShowForPlayer(playerid, fast_menu_general_1[4]);
					TextDrawShowForPlayer(playerid, fast_menu_general_1[5]);
					TextDrawShowForPlayer(playerid, fast_menu_general_1[6]);

					SelectTextDraw(playerid, COLOR_BLUE);
				}
				case TEXTDRAW_HIDE:
				{
					TextDrawHideForPlayer(playerid, fast_menu_general_1[0]);
					TextDrawHideForPlayer(playerid, fast_menu_general_1[1]);
					TextDrawHideForPlayer(playerid, fast_menu_general_1[2]);
					TextDrawHideForPlayer(playerid, fast_menu_general_1[3]);
					TextDrawHideForPlayer(playerid, fast_menu_general_1[4]);
					TextDrawHideForPlayer(playerid, fast_menu_general_1[5]);
					TextDrawHideForPlayer(playerid, fast_menu_general_1[6]);

					CancelSelectTextDraw(playerid);

				}
			}
		}
		case FAST_MENU_GENERAL_PLAYER:
		{
			switch(status)
			{
				case TEXTDRAW_SHOW:
				{
					show_fast_menu(playerid, FAST_MENU_GENERAL_MENU, TEXTDRAW_HIDE);

					TextDrawShowForPlayer(playerid, fast_menu_general_2[0]);
					TextDrawShowForPlayer(playerid, fast_menu_general_2[1]);
					TextDrawShowForPlayer(playerid, fast_menu_general_2[2]);
					TextDrawShowForPlayer(playerid, fast_menu_general_2[3]);
					TextDrawShowForPlayer(playerid, fast_menu_general_2[4]);
					TextDrawShowForPlayer(playerid, fast_menu_general_2[5]);
					TextDrawShowForPlayer(playerid, fast_menu_general_2[6]);

					SelectTextDraw(playerid, COLOR_BLUE);
				}
				case TEXTDRAW_HIDE:
				{
					TextDrawHideForPlayer(playerid, fast_menu_general_2[0]);
					TextDrawHideForPlayer(playerid, fast_menu_general_2[1]);
					TextDrawHideForPlayer(playerid, fast_menu_general_2[2]);
					TextDrawHideForPlayer(playerid, fast_menu_general_2[3]);
					TextDrawHideForPlayer(playerid, fast_menu_general_2[4]);
					TextDrawHideForPlayer(playerid, fast_menu_general_2[5]);
					TextDrawHideForPlayer(playerid, fast_menu_general_2[6]);

					CancelSelectTextDraw(playerid);					
				}
			}
		}
	}


	return true;
} 


CMD:key(playerid)
{
	return show_car_fast_menu(playerid, TEXTDRAW_SHOW);
}

stock show_car_fast_menu(playerid, status)
{
	switch(status)
	{
		case TEXTDRAW_SHOW:
		{


			new 
				vehicle_id;

			foreach(new v:vehicle_in_stream[playerid])
			{	

				new
					Float:pl_pos_x,
					Float:pl_pos_y,
					Float:pl_pos_z;

				GetPlayerPos(playerid, pl_pos_x, pl_pos_y, pl_pos_z);


				if(IsVehicleInRangeOfPoint(v, 7.0, pl_pos_x, pl_pos_y, pl_pos_z)) {}
					else continue;
				
				for(new i; i < 3; i++)
				{
					if(v == vehicle_player_max[playerid][i])
					{
						vehicle_id = vehicle_player_max[playerid][i];
						break;
					}
				}

			}
			if(transport_config[GetVehicleModel(vehicle_id)-400][transport_class] == 1 || transport_config[GetVehicleModel(vehicle_id)-400][transport_class] == 2)
			{
				TextDrawShowForPlayer(playerid, player_veh_key_back[0]);
				TextDrawShowForPlayer(playerid, player_veh_key_back[1]);
				TextDrawShowForPlayer(playerid, player_veh_key_back[2]);

				create_vehicle_key_player(playerid);

			    new engine, lights, alarm, doors, bonnet, boot, objective;


				GetVehicleParamsEx(vehicle_id, engine, lights, alarm, doors, bonnet, boot, objective);

				if(lights)
				{
					PlayerTextDrawSetString(playerid, player_veh_key[3][playerid], "brckey:key_td_lighton");
				}
				else
				{
					PlayerTextDrawSetString(playerid, player_veh_key[3][playerid], "brckey:key_td_lightoff");
				}
				PlayerTextDrawShow(playerid, player_veh_key[3][playerid]);

				if(engine)
				{
					PlayerTextDrawSetString(playerid, player_veh_key[4][playerid], "brckey:key_td_engineon");
				}
				else
				{
					PlayerTextDrawSetString(playerid, player_veh_key[4][playerid], "brckey:key_td_engineoff");			
				}
				PlayerTextDrawShow(playerid, player_veh_key[4][playerid]);

				if(doors)
				{
					PlayerTextDrawSetString(playerid, player_veh_key[0][playerid], "brckey:key_td_unlock");
				}
				else
				{
					PlayerTextDrawSetString(playerid, player_veh_key[0][playerid], "brckey:key_td_lock");			
				}
				PlayerTextDrawShow(playerid, player_veh_key[0][playerid]);

				if(bonnet)
				{
					PlayerTextDrawSetString(playerid, player_veh_key[1][playerid], "brckey:key_td_trunkon");
				}
				else
				{
					PlayerTextDrawSetString(playerid, player_veh_key[1][playerid], "brckey:key_td_trunkoff");			
				}
				PlayerTextDrawShow(playerid, player_veh_key[1][playerid]);

				if(boot)
				{
					PlayerTextDrawSetString(playerid, player_veh_key[2][playerid], "brckey:key_td_hoodon");
				}
				else
				{
					PlayerTextDrawSetString(playerid, player_veh_key[2][playerid], "brckey:key_td_hoodoff");			
				}
				PlayerTextDrawShow(playerid, player_veh_key[2][playerid]);
			}
			else if(transport_config[GetVehicleModel(vehicle_id)-400][transport_class] == 3 || transport_config[GetVehicleModel(vehicle_id)-400][transport_class] == 4)
			{
				TextDrawShowForPlayer(playerid, key_vehicle_electrog[0]);
				TextDrawShowForPlayer(playerid, key_vehicle_electrog[1]);
				TextDrawShowForPlayer(playerid, key_vehicle_electrog[2]);
				TextDrawShowForPlayer(playerid, key_vehicle_electrog[3]);
				TextDrawShowForPlayer(playerid, key_vehicle_electrog[4]);
				TextDrawShowForPlayer(playerid, key_vehicle_electrog[5]);
				TextDrawShowForPlayer(playerid, key_vehicle_electrog[6]);

				create_vehicle_key_electro_p(playerid);

			    new engine, lights, alarm, doors, bonnet, boot, objective;


				GetVehicleParamsEx(vehicle_id, engine, lights, alarm, doors, bonnet, boot, objective);

				if(lights)
				{
					PlayerTextDrawSetString(playerid, key_vehicle_electro[3][playerid], "brckey:key_td_e_lighton");
				}
				else
				{
					PlayerTextDrawSetString(playerid, key_vehicle_electro[3][playerid], "brckey:key_td_e_lightoff");
				}
				PlayerTextDrawShow(playerid, key_vehicle_electro[3][playerid]);

				if(engine)
				{
					PlayerTextDrawSetString(playerid, key_vehicle_electro[4][playerid], "brckey:key_td_e_engineon");
				}
				else
				{
					PlayerTextDrawSetString(playerid, key_vehicle_electro[4][playerid], "brckey:key_td_e_engineoff");			
				}
				PlayerTextDrawShow(playerid, key_vehicle_electro[4][playerid]);

				if(doors)
				{
					PlayerTextDrawSetString(playerid, key_vehicle_electro[0][playerid], "brckey:key_td_e_unlock");
				}
				else
				{
					PlayerTextDrawSetString(playerid, key_vehicle_electro[0][playerid], "brckey:key_td_e_lock");			
				}
				PlayerTextDrawShow(playerid, key_vehicle_electro[0][playerid]);

				if(bonnet)
				{
					PlayerTextDrawSetString(playerid, key_vehicle_electro[1][playerid], "brckey:key_td_e_trunkon");
				}
				else
				{
					PlayerTextDrawSetString(playerid, key_vehicle_electro[1][playerid], "brckey:key_td_e_trunkoff");			
				}
				PlayerTextDrawShow(playerid, key_vehicle_electro[1][playerid]);

				if(boot)
				{
					PlayerTextDrawSetString(playerid, key_vehicle_electro[2][playerid], "brckey:key_td_e_hoodon");
				}
				else
				{
					PlayerTextDrawSetString(playerid, key_vehicle_electro[2][playerid], "brckey:key_td_e_hoodoff");			
				}
				PlayerTextDrawShow(playerid, key_vehicle_electro[2][playerid]);				
			}
			SelectTextDraw(playerid, COLOR_BLUE);
		}
		case TEXTDRAW_HIDE:
		{
			TextDrawHideForPlayer(playerid, player_veh_key_back[0]);
			TextDrawHideForPlayer(playerid, player_veh_key_back[1]);
			TextDrawHideForPlayer(playerid, player_veh_key_back[2]);


			TextDrawHideForPlayer(playerid, key_vehicle_electrog[0]);
			TextDrawHideForPlayer(playerid, key_vehicle_electrog[1]);
			TextDrawHideForPlayer(playerid, key_vehicle_electrog[2]);
			TextDrawHideForPlayer(playerid, key_vehicle_electrog[3]);
			TextDrawHideForPlayer(playerid, key_vehicle_electrog[4]);
			TextDrawHideForPlayer(playerid, key_vehicle_electrog[5]);
			TextDrawHideForPlayer(playerid, key_vehicle_electrog[6]);

			PlayerTextDrawHideEx(playerid, player_veh_key[0][playerid]);
			PlayerTextDrawHideEx(playerid, player_veh_key[1][playerid]);
			PlayerTextDrawHideEx(playerid, player_veh_key[2][playerid]);
			PlayerTextDrawHideEx(playerid, player_veh_key[3][playerid]);
			PlayerTextDrawHideEx(playerid, player_veh_key[4][playerid]);

			PlayerTextDrawHideEx(playerid, key_vehicle_electro[0][playerid]);
			PlayerTextDrawHideEx(playerid, key_vehicle_electro[1][playerid]);
			PlayerTextDrawHideEx(playerid, key_vehicle_electro[2][playerid]);
			PlayerTextDrawHideEx(playerid, key_vehicle_electro[3][playerid]);
			PlayerTextDrawHideEx(playerid, key_vehicle_electro[4][playerid]);

			CancelSelectTextDraw(playerid);
		}
	}


	return true;
}



stock select_player_fast_menu(playerid)
{
	new 
		string_select[256],
		count;

	foreach(new i: logged_players)
	{
		if(IsPlayerConnected(i) && GetPlayerDistanceToPlayer(playerid, i) < 5)
		{
			if(i == playerid)
				continue;

			count ++;

			format(string_select, sizeof(string_select), "%s"cBLUE"%d. "cWH"%s\n", string_select, count, pData[i][pNickname]);
		}
	}

	if(count == 0)
		return SendErr(playerid, "Рядом нет игроков, которым можно что-то предложить!");

	return SPD(playerid, DIALOG_SELECT_FAST_MENU_P, DIALOG_STYLE_TABLIST, !""cBLUE"Выберите игрока", string_select, !"Выбрать", !"Отмена");
}


stock dialog_all_fast_menu_player(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
		case DIALOG_SELECT_FAST_MENU_P:
		{
			if(!response)
				return SelectTextDraw(playerid, COLOR_BLUE);

			new 
				id = GetPlayerID(inputtext[3]);

			if(GetPlayerDistanceToPlayer(playerid, id) > 10)
			{
				return SendErr(playerid, "Игрок слишком далеко");
			}

			switch(GetPVarIntNew(playerid, "fast_menu_select_type"))
			{
				case FAST_MENU_TYPE_MONEY:
				{
					SetPVarIntNew(playerid, "fast_menu_player_id", id+1);

					SPD(playerid, DIALOG_FASTMENU_PAY, DIALOG_STYLE_INPUT, !""cBLUE"Передача денег", "\
					"cWH"Сколько денежных средств Вы хотите передать?\n\n\
					Разрешенная сумма передачи от 1 рубля до 5 тысяч!", !"Далее", !"Отмена");

					return true;		 
				}
				case FAST_MENU_TYPE_SKILL:
				{
					return offer_player(playerid, id, OFFER_SKILL);
				}
				case FAST_MENU_TYPE_MED:
				{
					format(String64, sizeof(String64), "/med %d", id);
					PC_EmulateCommand(playerid, String64);
				}
				case FAST_MENU_TYPE_HI:
				{
					format(String64, sizeof(String64), "/hi %d", id);
					PC_EmulateCommand(playerid, String64);
				}
				case FAST_MENU_TYPE_PASS:
				{
					return offer_player(playerid, id, OFFER_PASS);
				}	
				case FAST_MENU_TYPE_UDOST:
				{
					return offer_player(playerid, id, OFFER_UDOST);
				}
			}
		}
		case DIALOG_FASTMENU_PAY:
		{
			if(!response)
				return SelectTextDraw(playerid, COLOR_BLUE);

			if(!IsNumeric(inputtext) || !strlen(inputtext))
			{
				SendErr(playerid,"Вы указали неверное значение!");
				return true;
			}

			new 
				count_money_fastmenu = strval(inputtext);

			if(count_money_fastmenu < 1)
			{
				SendErr(playerid,"У вас недостаточно денежных средств для передачи!");
				return true;
			}

			if(GetPlayerMoneyEx(playerid) < count_money_fastmenu)
			{
				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
				return SendErr(playerid,"У вас недостаточно денежных средств для передачи!");
			}

			if(count_money_fastmenu < 1 || count_money_fastmenu > 5000) 
				return SendErr(playerid,"Можно передавать от 1 до 5000 рублей");

			if(pTemp[playerid][pLastPay] > 1 && pData[playerid][pLevel] < 15 && (!pData[playerid][pFraction] || (pData[playerid][pFraction] > 0 && !IsALeader(playerid)) ) && !pData[playerid][pAdmin] && pData[playerid][pBikerRank] != 7) 
				return SendErr(playerid,"Деньги можно передавать не чаще 1 раза в минуту");

		
			new 
				actplayerid = GetPVarIntNew(playerid, "fast_menu_player_id")-1;

			if(GetPlayerDistanceToPlayer(playerid,actplayerid) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(actplayerid) || pRealState[actplayerid] > 3) 
				return SendErr(playerid,"Вы далеко друг от друга");


			give_money(playerid , -count_money_fastmenu, "Передача денег");
			give_money(actplayerid , count_money_fastmenu, "Передача денег");

			new mes[128];
			pTemp[playerid][pLastPay] = 60;
			format(mes,sizeof(mes),"%s {"#cINFO"}передал Вам "cGR"%d рублей",pData[playerid][pNickname],count_money_fastmenu);
			SendClientMessage(actplayerid,CWHITE,mes);
			format(mes,sizeof(mes),"Вы передали "cWH"%s "cGR"%d рублей",pData[actplayerid][pNickname],count_money_fastmenu);
			SendClientMessage(playerid,CINFO,mes);
			format(mes,sizeof(mes),"достал деньги и передал их %s",pData[actplayerid][pNickname]);
			MeAction(playerid,mes);

		}
	}
	return true;
}

stock show_fast_menu_other(playerid)
{
	if(pData[playerid][pHouse] != -1)
	{
		PC_EmulateCommand(playerid, "/home");
	}
	else if(pData[playerid][pFlate] != -1)
	{
		PC_EmulateCommand(playerid, "/flate");
	}
	return true;
}