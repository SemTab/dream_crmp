

callback:: load_player_inventory(playerid)
{
	new 
		time = GetTickCount();

	format(String1024, sizeof(String1024), "SELECT * FROM `inventory_player` WHERE `inventory_user_id` = '%d'", pData[playerid][pMysqlID]);
	new Result:inventory_players = sql_queryEx(zConn, String1024, QUERY_CACHED);

	new 
		inventory_all_items = sql_num_rows(inventory_players),
		inventory_load_player_count;

	if(sql_num_rows(inventory_players)) 
	{

		sql_get_field_assoc_ex(inventory_players, 0, "inventory_items_id", inventory_player[playerid][inventory_items_id]);
		sql_get_field_assoc_ex(inventory_players, 0, "inventory_slot", inventory_player[playerid][inventory_slot_id]);
		sql_get_field_assoc_ex(inventory_players, 0, "inventory_count", inventory_player[playerid][inventory_count]);

		sscanf(inventory_player[playerid][inventory_items_id], "p<,>a<i>[96]", inventory_player[playerid][inventory_items_id]);
		sscanf(inventory_player[playerid][inventory_slot_id], "p<,>a<i>[96]", inventory_player[playerid][inventory_slot_id]);
		sscanf(inventory_player[playerid][inventory_count], "p<,>a<i>[96]", inventory_player[playerid][inventory_count]);
 
	}
	else
	{
		format(String256,sizeof(String256),"INSERT INTO `inventory_player`(`inventory_user_id`) VALUES ('%d')", pData[playerid][pMysqlID]);
		sql_queryEx(zConn, String256, QUERY_THREADED);		
	}
	sql_free_result(inventory_players);
	return true;
}

stock disconnect_player_inventory(playerid)
{
	inventory_gui_panel(playerid, TEXTDRAW_HIDE);
	CancelSelectTextDraw(playerid);

	for(new i; i < 72; i++)
	{
		inventory_player[playerid][inventory_items_id][i] = 0;
		inventory_player[playerid][inventory_slot_id][i] = 0;
		inventory_player[playerid][inventory_count][i] = 0;
	}
	return true;
}


CMD:save_inventory(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8)
    	return NoCMD(playerid);	

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/save_inventory [COUNT]");

	for(new i = 0; i < params[0]; i++)
	{
		save_player_inventory(playerid);
	}

	return true;
}


callback:: save_player_inventory(playerid)
{
	new 
		time = GetTickCount();

	new 
		inventory_items_ids[150],
		inventory_save_slots[150],
		inventory_save_counts[150];

	format(inventory_items_ids, sizeof(inventory_items_ids), "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,\
	%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",

	inventory_player[playerid][inventory_items_id][0],
	inventory_player[playerid][inventory_items_id][1],
	inventory_player[playerid][inventory_items_id][2],
	inventory_player[playerid][inventory_items_id][3],
	inventory_player[playerid][inventory_items_id][4],
	inventory_player[playerid][inventory_items_id][5],
	inventory_player[playerid][inventory_items_id][6],
	inventory_player[playerid][inventory_items_id][7],
	inventory_player[playerid][inventory_items_id][8],
	inventory_player[playerid][inventory_items_id][9],
	inventory_player[playerid][inventory_items_id][10],
	inventory_player[playerid][inventory_items_id][11],
	inventory_player[playerid][inventory_items_id][12],
	inventory_player[playerid][inventory_items_id][13],
	inventory_player[playerid][inventory_items_id][14],
	inventory_player[playerid][inventory_items_id][15],
	inventory_player[playerid][inventory_items_id][16],
	inventory_player[playerid][inventory_items_id][17],
	inventory_player[playerid][inventory_items_id][18],
	inventory_player[playerid][inventory_items_id][19],
	inventory_player[playerid][inventory_items_id][20],
	inventory_player[playerid][inventory_items_id][21],
	inventory_player[playerid][inventory_items_id][22],
	inventory_player[playerid][inventory_items_id][23],
	inventory_player[playerid][inventory_items_id][24],
	inventory_player[playerid][inventory_items_id][25],
	inventory_player[playerid][inventory_items_id][26],
	inventory_player[playerid][inventory_items_id][27],
	inventory_player[playerid][inventory_items_id][28],
	inventory_player[playerid][inventory_items_id][29],
	inventory_player[playerid][inventory_items_id][30],
	inventory_player[playerid][inventory_items_id][31],
	inventory_player[playerid][inventory_items_id][32],
	inventory_player[playerid][inventory_items_id][33],
	inventory_player[playerid][inventory_items_id][34],
	inventory_player[playerid][inventory_items_id][35],
	inventory_player[playerid][inventory_items_id][36],
	inventory_player[playerid][inventory_items_id][37],
	inventory_player[playerid][inventory_items_id][38],
	inventory_player[playerid][inventory_items_id][39],
	inventory_player[playerid][inventory_items_id][40],
	inventory_player[playerid][inventory_items_id][41],
	inventory_player[playerid][inventory_items_id][42],
	inventory_player[playerid][inventory_items_id][43],
	inventory_player[playerid][inventory_items_id][44],
	inventory_player[playerid][inventory_items_id][45],
	inventory_player[playerid][inventory_items_id][46],
	inventory_player[playerid][inventory_items_id][47],
	inventory_player[playerid][inventory_items_id][48],
	inventory_player[playerid][inventory_items_id][49],
	inventory_player[playerid][inventory_items_id][50],
	inventory_player[playerid][inventory_items_id][51],
	inventory_player[playerid][inventory_items_id][52],
	inventory_player[playerid][inventory_items_id][53],
	inventory_player[playerid][inventory_items_id][54],
	inventory_player[playerid][inventory_items_id][55],
	inventory_player[playerid][inventory_items_id][56],
	inventory_player[playerid][inventory_items_id][57],
	inventory_player[playerid][inventory_items_id][58],
	inventory_player[playerid][inventory_items_id][59],
	inventory_player[playerid][inventory_items_id][60],
	inventory_player[playerid][inventory_items_id][61],
	inventory_player[playerid][inventory_items_id][62],
	inventory_player[playerid][inventory_items_id][63],
	inventory_player[playerid][inventory_items_id][64],
	inventory_player[playerid][inventory_items_id][65],
	inventory_player[playerid][inventory_items_id][66],
	inventory_player[playerid][inventory_items_id][67],
	inventory_player[playerid][inventory_items_id][68],
	inventory_player[playerid][inventory_items_id][69],
	inventory_player[playerid][inventory_items_id][70],
	inventory_player[playerid][inventory_items_id][71],
	inventory_player[playerid][inventory_items_id][72],
	inventory_player[playerid][inventory_items_id][73],
	inventory_player[playerid][inventory_items_id][74],
	inventory_player[playerid][inventory_items_id][75],
	inventory_player[playerid][inventory_items_id][76],
	inventory_player[playerid][inventory_items_id][77],
	inventory_player[playerid][inventory_items_id][78],
	inventory_player[playerid][inventory_items_id][79],
	inventory_player[playerid][inventory_items_id][80],
	inventory_player[playerid][inventory_items_id][81],
	inventory_player[playerid][inventory_items_id][82],
	inventory_player[playerid][inventory_items_id][83],
	inventory_player[playerid][inventory_items_id][84],
	inventory_player[playerid][inventory_items_id][85],
	inventory_player[playerid][inventory_items_id][86],
	inventory_player[playerid][inventory_items_id][87],
	inventory_player[playerid][inventory_items_id][88],
	inventory_player[playerid][inventory_items_id][89],
	inventory_player[playerid][inventory_items_id][90],
	inventory_player[playerid][inventory_items_id][91]);


	format(inventory_save_slots, sizeof(inventory_save_slots), "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,\
	%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",

	inventory_player[playerid][inventory_slot_id][0],
	inventory_player[playerid][inventory_slot_id][1],
	inventory_player[playerid][inventory_slot_id][2],
	inventory_player[playerid][inventory_slot_id][3],
	inventory_player[playerid][inventory_slot_id][4],
	inventory_player[playerid][inventory_slot_id][5],
	inventory_player[playerid][inventory_slot_id][6],
	inventory_player[playerid][inventory_slot_id][7],
	inventory_player[playerid][inventory_slot_id][8],
	inventory_player[playerid][inventory_slot_id][9],
	inventory_player[playerid][inventory_slot_id][10],
	inventory_player[playerid][inventory_slot_id][11],
	inventory_player[playerid][inventory_slot_id][12],
	inventory_player[playerid][inventory_slot_id][13],
	inventory_player[playerid][inventory_slot_id][14],
	inventory_player[playerid][inventory_slot_id][15],
	inventory_player[playerid][inventory_slot_id][16],
	inventory_player[playerid][inventory_slot_id][17],
	inventory_player[playerid][inventory_slot_id][18],
	inventory_player[playerid][inventory_slot_id][19],
	inventory_player[playerid][inventory_slot_id][20],
	inventory_player[playerid][inventory_slot_id][21],
	inventory_player[playerid][inventory_slot_id][22],
	inventory_player[playerid][inventory_slot_id][23],
	inventory_player[playerid][inventory_slot_id][24],
	inventory_player[playerid][inventory_slot_id][25],
	inventory_player[playerid][inventory_slot_id][26],
	inventory_player[playerid][inventory_slot_id][27],
	inventory_player[playerid][inventory_slot_id][28],
	inventory_player[playerid][inventory_slot_id][29],
	inventory_player[playerid][inventory_slot_id][30],
	inventory_player[playerid][inventory_slot_id][31],
	inventory_player[playerid][inventory_slot_id][32],
	inventory_player[playerid][inventory_slot_id][33],
	inventory_player[playerid][inventory_slot_id][34],
	inventory_player[playerid][inventory_slot_id][35],
	inventory_player[playerid][inventory_slot_id][36],
	inventory_player[playerid][inventory_slot_id][37],
	inventory_player[playerid][inventory_slot_id][38],
	inventory_player[playerid][inventory_slot_id][39],
	inventory_player[playerid][inventory_slot_id][40],
	inventory_player[playerid][inventory_slot_id][41],
	inventory_player[playerid][inventory_slot_id][42],
	inventory_player[playerid][inventory_slot_id][43],
	inventory_player[playerid][inventory_slot_id][44],
	inventory_player[playerid][inventory_slot_id][45],
	inventory_player[playerid][inventory_slot_id][46],
	inventory_player[playerid][inventory_slot_id][47],
	inventory_player[playerid][inventory_slot_id][48],
	inventory_player[playerid][inventory_slot_id][49],
	inventory_player[playerid][inventory_slot_id][50],
	inventory_player[playerid][inventory_slot_id][51],
	inventory_player[playerid][inventory_slot_id][52],
	inventory_player[playerid][inventory_slot_id][53],
	inventory_player[playerid][inventory_slot_id][54],
	inventory_player[playerid][inventory_slot_id][55],
	inventory_player[playerid][inventory_slot_id][56],
	inventory_player[playerid][inventory_slot_id][57],
	inventory_player[playerid][inventory_slot_id][58],
	inventory_player[playerid][inventory_slot_id][59],
	inventory_player[playerid][inventory_slot_id][60],
	inventory_player[playerid][inventory_slot_id][61],
	inventory_player[playerid][inventory_slot_id][62],
	inventory_player[playerid][inventory_slot_id][63],
	inventory_player[playerid][inventory_slot_id][64],
	inventory_player[playerid][inventory_slot_id][65],
	inventory_player[playerid][inventory_slot_id][66],
	inventory_player[playerid][inventory_slot_id][67],
	inventory_player[playerid][inventory_slot_id][68],
	inventory_player[playerid][inventory_slot_id][69],
	inventory_player[playerid][inventory_slot_id][70],
	inventory_player[playerid][inventory_slot_id][71],
	inventory_player[playerid][inventory_slot_id][72],
	inventory_player[playerid][inventory_slot_id][73],
	inventory_player[playerid][inventory_slot_id][74],
	inventory_player[playerid][inventory_slot_id][75],
	inventory_player[playerid][inventory_slot_id][76],
	inventory_player[playerid][inventory_slot_id][77],
	inventory_player[playerid][inventory_slot_id][78],
	inventory_player[playerid][inventory_slot_id][79],
	inventory_player[playerid][inventory_slot_id][80],
	inventory_player[playerid][inventory_slot_id][81],
	inventory_player[playerid][inventory_slot_id][82],
	inventory_player[playerid][inventory_slot_id][83],
	inventory_player[playerid][inventory_slot_id][84],
	inventory_player[playerid][inventory_slot_id][85],
	inventory_player[playerid][inventory_slot_id][86],
	inventory_player[playerid][inventory_slot_id][87],
	inventory_player[playerid][inventory_slot_id][88],
	inventory_player[playerid][inventory_slot_id][89],
	inventory_player[playerid][inventory_slot_id][90],
	inventory_player[playerid][inventory_slot_id][91]);

	format(inventory_save_counts, sizeof(inventory_save_counts), "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,\
	%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",

	inventory_player[playerid][inventory_count][0],
	inventory_player[playerid][inventory_count][1],
	inventory_player[playerid][inventory_count][2],
	inventory_player[playerid][inventory_count][3],
	inventory_player[playerid][inventory_count][4],
	inventory_player[playerid][inventory_count][5],
	inventory_player[playerid][inventory_count][6],
	inventory_player[playerid][inventory_count][7],
	inventory_player[playerid][inventory_count][8],
	inventory_player[playerid][inventory_count][9],
	inventory_player[playerid][inventory_count][10],
	inventory_player[playerid][inventory_count][11],
	inventory_player[playerid][inventory_count][12],
	inventory_player[playerid][inventory_count][13],
	inventory_player[playerid][inventory_count][14],
	inventory_player[playerid][inventory_count][15],
	inventory_player[playerid][inventory_count][16],
	inventory_player[playerid][inventory_count][17],
	inventory_player[playerid][inventory_count][18],
	inventory_player[playerid][inventory_count][19],
	inventory_player[playerid][inventory_count][20],
	inventory_player[playerid][inventory_count][21],
	inventory_player[playerid][inventory_count][22],
	inventory_player[playerid][inventory_count][23],
	inventory_player[playerid][inventory_count][24],
	inventory_player[playerid][inventory_count][25],
	inventory_player[playerid][inventory_count][26],
	inventory_player[playerid][inventory_count][27],
	inventory_player[playerid][inventory_count][28],
	inventory_player[playerid][inventory_count][29],
	inventory_player[playerid][inventory_count][30],
	inventory_player[playerid][inventory_count][31],
	inventory_player[playerid][inventory_count][32],
	inventory_player[playerid][inventory_count][33],
	inventory_player[playerid][inventory_count][34],
	inventory_player[playerid][inventory_count][35],
	inventory_player[playerid][inventory_count][36],
	inventory_player[playerid][inventory_count][37],
	inventory_player[playerid][inventory_count][38],
	inventory_player[playerid][inventory_count][39],
	inventory_player[playerid][inventory_count][40],
	inventory_player[playerid][inventory_count][41],
	inventory_player[playerid][inventory_count][42],
	inventory_player[playerid][inventory_count][43],
	inventory_player[playerid][inventory_count][44],
	inventory_player[playerid][inventory_count][45],
	inventory_player[playerid][inventory_count][46],
	inventory_player[playerid][inventory_count][47],
	inventory_player[playerid][inventory_count][48],
	inventory_player[playerid][inventory_count][49],
	inventory_player[playerid][inventory_count][50],
	inventory_player[playerid][inventory_count][51],
	inventory_player[playerid][inventory_count][52],
	inventory_player[playerid][inventory_count][53],
	inventory_player[playerid][inventory_count][54],
	inventory_player[playerid][inventory_count][55],
	inventory_player[playerid][inventory_count][56],
	inventory_player[playerid][inventory_count][57],
	inventory_player[playerid][inventory_count][58],
	inventory_player[playerid][inventory_count][59],
	inventory_player[playerid][inventory_count][60],
	inventory_player[playerid][inventory_count][61],
	inventory_player[playerid][inventory_count][62],
	inventory_player[playerid][inventory_count][63],
	inventory_player[playerid][inventory_count][64],
	inventory_player[playerid][inventory_count][65],
	inventory_player[playerid][inventory_count][66],
	inventory_player[playerid][inventory_count][67],
	inventory_player[playerid][inventory_count][68],
	inventory_player[playerid][inventory_count][69],
	inventory_player[playerid][inventory_count][70],
	inventory_player[playerid][inventory_count][71],
	inventory_player[playerid][inventory_count][72],
	inventory_player[playerid][inventory_count][73],
	inventory_player[playerid][inventory_count][74],
	inventory_player[playerid][inventory_count][75],
	inventory_player[playerid][inventory_count][76],
	inventory_player[playerid][inventory_count][77],
	inventory_player[playerid][inventory_count][78],
	inventory_player[playerid][inventory_count][79],
	inventory_player[playerid][inventory_count][80],
	inventory_player[playerid][inventory_count][81],
	inventory_player[playerid][inventory_count][82],
	inventory_player[playerid][inventory_count][83],
	inventory_player[playerid][inventory_count][84],
	inventory_player[playerid][inventory_count][85],
	inventory_player[playerid][inventory_count][86],
	inventory_player[playerid][inventory_count][87],
	inventory_player[playerid][inventory_count][88],
	inventory_player[playerid][inventory_count][89],
	inventory_player[playerid][inventory_count][90],
	inventory_player[playerid][inventory_count][91]);
	
	new 
		fmt_str[1024];

	format(fmt_str,sizeof(fmt_str),"UPDATE `inventory_player` SET `inventory_items_id` = '%s' WHERE `inventory_user_id`= '%d'", inventory_items_ids, pData[playerid][pMysqlID]);
	sql_queryEx(zConn, fmt_str, QUERY_THREADED);
	format(fmt_str,sizeof(fmt_str),"UPDATE `inventory_player` SET `inventory_slot` = '%s' WHERE `inventory_user_id`= '%d'", inventory_save_slots, pData[playerid][pMysqlID]);
	sql_queryEx(zConn, fmt_str, QUERY_THREADED);
	format(fmt_str,sizeof(fmt_str),"UPDATE `inventory_player` SET `inventory_count` = '%s' WHERE `inventory_user_id`= '%d'", inventory_save_counts, pData[playerid][pMysqlID]);
	sql_queryEx(zConn, fmt_str, QUERY_THREADED);

	printf("[Сохранение инвентаря] Аккаунт: %s[%d] | Времени затрачено: <%d мс>",pData[playerid][pNickname], pData[playerid][pMysqlID], GetTickCount() - time);

	return true;
}

CMD:inv(playerid)
{	
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
		return SendErr(playerid, "Недоступно за рулём!");

	if(GetPVarIntNew(playerid, "show_inventory_player"))
	{
		inventory_gui_panel(playerid, TEXTDRAW_HIDE);
	}
	else
	{
		inventory_gui_panel(playerid, TEXTDRAW_SHOW);
	}
	return true;
}


stock select_items_player(playerid, slot_inventory)
{
	new 
		page_inventory = GetPVarIntNew(playerid, "inventory_show_page");

	switch(page_inventory)
	{
		case PAGE_INVENTORY_1:
		{
			new 
				slot_inventory_f = slot_inventory;

			if(inventory_player[playerid][inventory_count][slot_inventory_f] == 0 && slot_inventory != 24 && slot_inventory != 26 && slot_inventory != 29)
				return true;

			new 
				items_id = inventory_player[playerid][inventory_items_id][slot_inventory_f];

			SetPVarIntNew(playerid, "items_inventory_id", items_id);
			SetPVarIntNew(playerid, "items_inventory_slot", slot_inventory_f);

			if(items_id == 336 || items_id == 337 || items_id == 338 || items_id == 339 || items_id == 341 || items_id == 342 || items_id == 343 || items_id == 344
			|| items_id == 345 || items_id == 346 || items_id == 347 || items_id == 348 || items_id == 358 || items_id == 359 || items_id == 360 || items_id == 361
			|| items_id == 362 || items_id == 363 || items_id == 364 || items_id == 365 || items_id == 366 || items_id == 367 || items_id == 368 || items_id == 369
			|| items_id == 370 || items_id == 371 || items_id == 372)
			{
			    format(String2048, sizeof(String2048), "\
			        "cGREY"Информация\t"cGREY"Действие\n\
		        	"cGREY"Предмет: \t"cBLUE"%s\n\
		        	"cGREY"Количество:\t"cBLUE"%d\n\
		        	"cGREY"Описание: \t"cBLUE"%s\n\
		        	"cGREY"Занимает места: \t"cBLUE"%f"cGREY" килограмм\n\
			        \t\n\
			        "cBLUE"-"cWH"Употребить в пищу\t"cGR"Использовать\n\
			        "cBLUE"-"cWH"Выкинуть\t"cGR"Использовать", 

		        	inventory_items[items_id][items_inv_name],
		        	inventory_player[playerid][inventory_count][slot_inventory_f],
		        	inventory_items[items_id][items_inv_text],
		        	inventory_items[items_id][items_inv_mass]*inventory_player[playerid][inventory_count][slot_inventory_f]
			        );
			    SPD(playerid, DIALOG_ACTION_INVENTORY_ITEMS, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Предмет в инвентаре", String2048, !"Выбрать", !"Закрыть"); 
			    return true;
			}
			else if(items_id == 340)
			{
			    format(String256, sizeof(String256), "\
		        	"cGREY"Предмет: "cBLUE"%s\n\
		        	"cGREY"Осталось дней: "cBLUE"%d дней\n\
		        	"cGREY"Описание: "cBLUE"%s", 
		        	inventory_items[items_id][items_inv_name],
		        	pData[playerid][pHunterLic],
		        	inventory_items[items_id][items_inv_text]
			        );
			    return SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Предмет в инвентаре", String256, !"Закрыть", ""); 				
			}
			else if(items_id >= 11 && items_id <= 16)
			{
			    format(String2048, sizeof(String2048), "\
			        "cGREY"Информация\t"cGREY"Действие\n\
		        	"cGREY"Головной Убор: \t"cBLUE"%s (%d)\n\
		        	"cGREY"Количество:\t"cBLUE"%d\n\
		        	"cGREY"Описание: \t"cBLUE"%s\n\
		        	"cGREY"Занимает места: \t"cBLUE"%f"cGREY" килограмм\n\
			        \t\n\
			        "cBLUE"-"cWH"Использовать аксессуар\t"cGR"Использовать\n\
			        "cBLUE"-"cWH"Выкинуть аксессуар\t"cGR"Использовать", 

		        	inventory_items[items_id][items_inv_name], inventory_items[items_id][items_inv_id],
		        	inventory_player[playerid][inventory_count][slot_inventory_f],
		        	inventory_items[items_id][items_inv_text],
		        	inventory_items[items_id][items_inv_mass]*inventory_player[playerid][inventory_count][slot_inventory_f]
			        );
			    return SPD(playerid, DIALOG_ACTION_INVENTORY_ITEMS, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Предмет в инвентаре", String2048, !"Выбрать", !"Закрыть"); 					
			}
			else if(slot_inventory == 24 && pData[playerid][pSlotItem][0] != 0)
			{
				SetPVarIntNew(playerid, "type_inventory_aks", INVENTORY_AKS_HEAD);

			    format(String256, sizeof(String256), "\
			        "cGREY"Информация\t"cGREY"Действие\n\
		        	"cGREY"Головной Убор: \t"cBLUE"%s (%d)\n\
		        	"cGREY"Описание: \t"cBLUE"%s\n\
			        \t\n\
			        "cBLUE"-"cWH"Снять аксессуар\t"cGR"Использовать\n\
			        "cBLUE"-"cWH"Выкинуть аксессуар\t"cGR"Использовать", 

		        	inventory_items[items_id][items_inv_name], inventory_items[items_id][items_inv_id],
		        	inventory_items[items_id][items_inv_text]
			        );
			    return SPD(playerid, DIALOG_ACTION_INV_ITEMS_AKS, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Предмет в инвентаре", String256, !"Выбрать", !"Закрыть"); 					
			}
			else if(slot_inventory == 24 && pData[playerid][pSlotItem][0] == 0)
			{	
				return true;
			}
			else if(slot_inventory == 26 && pData[playerid][pSlotItem][2] != 0)
			{
				SetPVarIntNew(playerid, "type_inventory_aks", INVENTORY_AKS_FACE);

			    format(String256, sizeof(String256), "\
			        "cGREY"Информация\t"cGREY"Действие\n\
		        	"cGREY"Маска: \t"cBLUE"%s (%d)\n\
		        	"cGREY"Описание: \t"cBLUE"%s\n\
			        \t\n\
			        "cBLUE"-"cWH"Снять аксессуар\t"cGR"Использовать\n\
			        "cBLUE"-"cWH"Выкинуть аксессуар\t"cGR"Использовать", 

		        	inventory_items[items_id][items_inv_name], inventory_items[items_id][items_inv_id],
		        	inventory_items[items_id][items_inv_text]
			        );
			    return SPD(playerid, DIALOG_ACTION_INV_ITEMS_AKS, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Предмет в инвентаре", String256, !"Выбрать", !"Закрыть"); 					
			}
			else if(slot_inventory == 26 && pData[playerid][pSlotItem][2] == 0)
			{	
				return true;
			}
			else if(slot_inventory == 29 && pData[playerid][pSlotItem][3] != 0)
			{
				SetPVarIntNew(playerid, "type_inventory_aks", INVENTORY_AKS_BACK);

			    format(String256, sizeof(String256), "\
			        "cGREY"Информация\t"cGREY"Действие\n\
		        	"cGREY"Рюкзак: \t"cBLUE"%s (%d)\n\
		        	"cGREY"Описание: \t"cBLUE"%s\n\
			        \t\n\
			        "cBLUE"-"cWH"Снять аксессуар\t"cGR"Использовать\n\
			        "cBLUE"-"cWH"Выкинуть аксессуар\t"cGR"Использовать", 

		        	inventory_items[items_id][items_inv_name], inventory_items[items_id][items_inv_id],
		        	inventory_items[items_id][items_inv_text]
			        );
			    return SPD(playerid, DIALOG_ACTION_INV_ITEMS_AKS, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Предмет в инвентаре", String256, !"Выбрать", !"Закрыть"); 					
			}
			else if(slot_inventory == 29 && pData[playerid][pSlotItem][3] == 0)
			{	
				return true;
			}
			else
			{
			    format(String2048, sizeof(String2048), "\
			        "cGREY"Информация\t"cGREY"Действие\n\
		        	"cGREY"Предмет: \t"cBLUE"%s (%d)\n\
		        	"cGREY"Количество:\t"cBLUE"%d\n\
		        	"cGREY"Описание: \t"cBLUE"%s\n\
		        	"cGREY"Занимает места: \t"cBLUE"%f"cGREY" килограмм\n\
			        \t\n\
			        "cBLUE"-"cWH"Использовать предмет\t"cGR"Использовать\n\
			        "cBLUE"-"cWH"Выкинуть предмет\t"cGR"Использовать", 

		        	inventory_items[items_id][items_inv_name], inventory_items[items_id][items_inv_id],
		        	inventory_player[playerid][inventory_count][slot_inventory_f],
		        	inventory_items[items_id][items_inv_text],
		        	inventory_items[items_id][items_inv_mass]*inventory_player[playerid][inventory_count][slot_inventory_f]
			        );
			    return SPD(playerid, DIALOG_ACTION_INVENTORY_ITEMS, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Предмет в инвентаре", String2048, !"Выбрать", !"Закрыть"); 				
			}


		}
		case PAGE_INVENTORY_2:
		{
			new 
				slot_inventory_f = slot_inventory+48;

			if(inventory_player[playerid][inventory_count][slot_inventory_f] == 0 && slot_inventory != 24 && slot_inventory != 26 && slot_inventory != 29)
				return true;

			new 
				items_id = inventory_player[playerid][inventory_items_id][slot_inventory_f];

			SetPVarIntNew(playerid, "items_inventory_id", items_id);
			SetPVarIntNew(playerid, "items_inventory_slot", slot_inventory_f);

			if(items_id == 336 || items_id == 337 || items_id == 338 || items_id == 339 || items_id == 341 || items_id == 342 || items_id == 343 || items_id == 344
			|| items_id == 345 || items_id == 346 || items_id == 347 || items_id == 348 || items_id == 358 || items_id == 359 || items_id == 360 || items_id == 361
			|| items_id == 362 || items_id == 363 || items_id == 364 || items_id == 365 || items_id == 366 || items_id == 367 || items_id == 368 || items_id == 369
			|| items_id == 370 || items_id == 371 || items_id == 372)
			{
			    format(String2048, sizeof(String2048), "\
			        "cGREY"Информация\t"cGREY"Действие\n\
		        	"cGREY"Предмет: \t"cBLUE"%s\n\
		        	"cGREY"Количество:\t"cBLUE"%d\n\
		        	"cGREY"Описание: \t"cBLUE"%s\n\
		        	"cGREY"Занимает места: \t"cBLUE"%f"cGREY" килограмм\n\
			        \t\n\
			        "cBLUE"-"cWH"Употребить в пищу\t"cGR"Использовать\n\
			        "cBLUE"-"cWH"Выкинуть\t"cGR"Использовать", 

		        	inventory_items[items_id][items_inv_name],
		        	inventory_player[playerid][inventory_count][slot_inventory_f],
		        	inventory_items[items_id][items_inv_text],
		        	inventory_items[items_id][items_inv_mass]*inventory_player[playerid][inventory_count][slot_inventory_f]
			        );
			    SPD(playerid, DIALOG_ACTION_INVENTORY_ITEMS, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Предмет в инвентаре", String2048, !"Выбрать", !"Закрыть"); 
			    return true;
			}
			else if(items_id == 340)
			{
			    format(String256, sizeof(String256), "\
		        	"cGREY"Предмет: "cBLUE"%s\n\
		        	"cGREY"Осталось дней: "cBLUE"%d дней\n\
		        	"cGREY"Описание: "cBLUE"%s", 
		        	inventory_items[items_id][items_inv_name],
		        	pData[playerid][pHunterLic],
		        	inventory_items[items_id][items_inv_text]
			        );
			    return SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Предмет в инвентаре", String256, !"Закрыть", ""); 				
			}
			else if(items_id >= 11 && items_id <= 16)
			{
			    format(String2048, sizeof(String2048), "\
			        "cGREY"Информация\t"cGREY"Действие\n\
		        	"cGREY"Головной Убор: \t"cBLUE"%s (%d)\n\
		        	"cGREY"Количество:\t"cBLUE"%d\n\
		        	"cGREY"Описание: \t"cBLUE"%s\n\
		        	"cGREY"Занимает места: \t"cBLUE"%f"cGREY" килограмм\n\
			        \t\n\
			        "cBLUE"-"cWH"Использовать аксессуар\t"cGR"Использовать\n\
			        "cBLUE"-"cWH"Выкинуть аксессуар\t"cGR"Использовать", 

		        	inventory_items[items_id][items_inv_name], inventory_items[items_id][items_inv_id],
		        	inventory_player[playerid][inventory_count][slot_inventory_f],
		        	inventory_items[items_id][items_inv_text],
		        	inventory_items[items_id][items_inv_mass]*inventory_player[playerid][inventory_count][slot_inventory_f]
			        );
			    return SPD(playerid, DIALOG_ACTION_INVENTORY_ITEMS, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Предмет в инвентаре", String2048, !"Выбрать", !"Закрыть"); 					
			}
			else if(slot_inventory == 24 && pData[playerid][pSlotItem][0] != 0)
			{
				SetPVarIntNew(playerid, "type_inventory_aks", INVENTORY_AKS_HEAD);

			    format(String256, sizeof(String256), "\
			        "cGREY"Информация\t"cGREY"Действие\n\
		        	"cGREY"Головной Убор: \t\n\
		        	"cGREY"Описание: \t"cBLUE"%s\n\
			        \t\n\
			        "cBLUE"-"cWH"Снять аксессуар\t"cGR"Использовать\n\
			        "cBLUE"-"cWH"Выкинуть аксессуар\t"cGR"Использовать", 

		        	inventory_items[items_id][items_inv_text]
			        );
			    return SPD(playerid, DIALOG_ACTION_INV_ITEMS_AKS, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Предмет в инвентаре", String256, !"Выбрать", !"Закрыть"); 					
			}
			else if(slot_inventory == 24 && pData[playerid][pSlotItem][0] == 0)
			{	
				return true;
			}
			else if(slot_inventory == 26 && pData[playerid][pSlotItem][2] != 0)
			{
				SetPVarIntNew(playerid, "type_inventory_aks", INVENTORY_AKS_FACE);

			    format(String256, sizeof(String256), "\
			        "cGREY"Информация\t"cGREY"Действие\n\
		        	"cGREY"Маска: \t\n\
		        	"cGREY"Описание: \t"cBLUE"%s\n\
			        \t\n\
			        "cBLUE"-"cWH"Снять аксессуар\t"cGR"Использовать\n\
			        "cBLUE"-"cWH"Выкинуть аксессуар\t"cGR"Использовать", 

		        	inventory_items[items_id][items_inv_text]
			        );
			    return SPD(playerid, DIALOG_ACTION_INV_ITEMS_AKS, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Предмет в инвентаре", String256, !"Выбрать", !"Закрыть"); 					
			}
			else if(slot_inventory == 26 && pData[playerid][pSlotItem][2] == 0)
			{	
				return true;
			}
			else if(slot_inventory == 29 && pData[playerid][pSlotItem][3] != 0)
			{
				SetPVarIntNew(playerid, "type_inventory_aks", INVENTORY_AKS_BACK);

			    format(String256, sizeof(String256), "\
			        "cGREY"Информация\t"cGREY"Действие\n\
		        	"cGREY"Рюкзак: \t"cBLUE"\n\
		        	"cGREY"Описание: \t"cBLUE"%s\n\
			        \t\n\
			        "cBLUE"-"cWH"Снять аксессуар\t"cGR"Использовать\n\
			        "cBLUE"-"cWH"Выкинуть аксессуар\t"cGR"Использовать", 

		        	inventory_items[items_id][items_inv_text]
			        );
			    return SPD(playerid, DIALOG_ACTION_INV_ITEMS_AKS, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Предмет в инвентаре", String256, !"Выбрать", !"Закрыть"); 					
			}
			else if(slot_inventory == 29 && pData[playerid][pSlotItem][3] == 0)
			{	
				return true;
			}
			else
			{
			    format(String2048, sizeof(String2048), "\
			        "cGREY"Информация\t"cGREY"Действие\n\
		        	"cGREY"Предмет: \t"cBLUE"%s (%d)\n\
		        	"cGREY"Количество:\t"cBLUE"%d\n\
		        	"cGREY"Описание: \t"cBLUE"%s\n\
		        	"cGREY"Занимает места: \t"cBLUE"%f"cGREY" килограмм\n\
			        \t\n\
			        "cBLUE"-"cWH"Использовать предмет\t"cGR"Использовать\n\
			        "cBLUE"-"cWH"Выкинуть предмет\t"cGR"Использовать", 

		        	inventory_items[items_id][items_inv_name], inventory_items[items_id][items_inv_id],
		        	inventory_player[playerid][inventory_count][slot_inventory_f],
		        	inventory_items[items_id][items_inv_text],
		        	inventory_items[items_id][items_inv_mass]*inventory_player[playerid][inventory_count][slot_inventory_f]
			        );
			    return SPD(playerid, DIALOG_ACTION_INVENTORY_ITEMS, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Предмет в инвентаре", String2048, !"Выбрать", !"Закрыть"); 				
			}

		}
		case PAGE_INVENTORY_3:
		{
			new 
				slot_inventory_f = slot_inventory+72;

			if(inventory_player[playerid][inventory_count][slot_inventory_f] == 0 && slot_inventory != 24 && slot_inventory != 26 && slot_inventory != 29)
				return true;

			new 
				items_id = inventory_player[playerid][inventory_items_id][slot_inventory_f];

			SetPVarIntNew(playerid, "items_inventory_id", items_id);
			SetPVarIntNew(playerid, "items_inventory_slot", slot_inventory_f);

			if(items_id == 336 || items_id == 337 || items_id == 338 || items_id == 339 || items_id == 341 || items_id == 342 || items_id == 343 || items_id == 344
			|| items_id == 345 || items_id == 346 || items_id == 347 || items_id == 348 || items_id == 358 || items_id == 359 || items_id == 360 || items_id == 361
			|| items_id == 362 || items_id == 363 || items_id == 364 || items_id == 365 || items_id == 366 || items_id == 367 || items_id == 368 || items_id == 369
			|| items_id == 370 || items_id == 371 || items_id == 372)
			{
			    format(String2048, sizeof(String2048), "\
			        "cGREY"Информация\t"cGREY"Действие\n\
		        	"cGREY"Предмет: \t"cBLUE"%s\n\
		        	"cGREY"Количество:\t"cBLUE"%d\n\
		        	"cGREY"Описание: \t"cBLUE"%s\n\
		        	"cGREY"Занимает места: \t"cBLUE"%f"cGREY" килограмм\n\
			        \t\n\
			        "cBLUE"-"cWH"Употребить в пищу\t"cGR"Использовать\n\
			        "cBLUE"-"cWH"Выкинуть мясо\t"cGR"Использовать", 

		        	inventory_items[items_id][items_inv_name],
		        	inventory_player[playerid][inventory_count][slot_inventory_f],
		        	inventory_items[items_id][items_inv_text],
		        	inventory_items[items_id][items_inv_mass]*inventory_player[playerid][inventory_count][slot_inventory_f]
			        );
			    SPD(playerid, DIALOG_ACTION_INVENTORY_ITEMS, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Предмет в инвентаре", String2048, !"Выбрать", !"Закрыть"); 
			    return true;
			}
			else if(items_id == 340)
			{
			    format(String256, sizeof(String256), "\
		        	"cGREY"Предмет: "cBLUE"%s\n\
		        	"cGREY"Осталось дней: "cBLUE"%d дней\n\
		        	"cGREY"Описание: "cBLUE"%s", 
		        	inventory_items[items_id][items_inv_name],
		        	pData[playerid][pHunterLic],
		        	inventory_items[items_id][items_inv_text]
			        );
			    return SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Предмет в инвентаре", String256, !"Закрыть", ""); 				
			}
			else if(items_id >= 11 && items_id <= 16)
			{
			    format(String2048, sizeof(String2048), "\
			        "cGREY"Информация\t"cGREY"Действие\n\
		        	"cGREY"Головной Убор: \t"cBLUE"%s (%d)\n\
		        	"cGREY"Количество:\t"cBLUE"%d\n\
		        	"cGREY"Описание: \t"cBLUE"%s\n\
		        	"cGREY"Занимает места: \t"cBLUE"%f"cGREY" килограмм\n\
			        \t\n\
			        "cBLUE"-"cWH"Использовать аксессуар\t"cGR"Использовать\n\
			        "cBLUE"-"cWH"Выкинуть аксессуар\t"cGR"Использовать", 

		        	inventory_items[items_id][items_inv_name], inventory_items[items_id][items_inv_id],
		        	inventory_player[playerid][inventory_count][slot_inventory_f],
		        	inventory_items[items_id][items_inv_text],
		        	inventory_items[items_id][items_inv_mass]*inventory_player[playerid][inventory_count][slot_inventory_f]
			        );
			    return SPD(playerid, DIALOG_ACTION_INVENTORY_ITEMS, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Предмет в инвентаре", String2048, !"Выбрать", !"Закрыть"); 					
			}
			else if(slot_inventory == 24 && pData[playerid][pSlotItem][0] != 0)
			{
				SetPVarIntNew(playerid, "type_inventory_aks", INVENTORY_AKS_HEAD);

			    format(String256, sizeof(String256), "\
			        "cGREY"Информация\t"cGREY"Действие\n\
		        	"cGREY"Головной Убор: \t"cBLUE"%s (%d)\n\
		        	"cGREY"Описание: \t"cBLUE"%s\n\
			        \t\n\
			        "cBLUE"-"cWH"Снять аксессуар\t"cGR"Использовать\n\
			        "cBLUE"-"cWH"Выкинуть аксессуар\t"cGR"Использовать", 

		        	inventory_items[items_id][items_inv_name], inventory_items[items_id][items_inv_id],
		        	inventory_items[items_id][items_inv_text]
			        );
			    return SPD(playerid, DIALOG_ACTION_INV_ITEMS_AKS, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Предмет в инвентаре", String256, !"Выбрать", !"Закрыть"); 					
			}
			else if(slot_inventory == 24 && pData[playerid][pSlotItem][0] == 0)
			{	
				return true;
			}
			else if(slot_inventory == 26 && pData[playerid][pSlotItem][2] != 0)
			{
				SetPVarIntNew(playerid, "type_inventory_aks", INVENTORY_AKS_FACE);

			    format(String256, sizeof(String256), "\
			        "cGREY"Информация\t"cGREY"Действие\n\
		        	"cGREY"Маска: \t"cBLUE"%s (%d)\n\
		        	"cGREY"Описание: \t"cBLUE"%s\n\
			        \t\n\
			        "cBLUE"-"cWH"Снять аксессуар\t"cGR"Использовать\n\
			        "cBLUE"-"cWH"Выкинуть аксессуар\t"cGR"Использовать", 

		        	inventory_items[items_id][items_inv_name], inventory_items[items_id][items_inv_id],
		        	inventory_items[items_id][items_inv_text]
			        );
			    return SPD(playerid, DIALOG_ACTION_INV_ITEMS_AKS, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Предмет в инвентаре", String256, !"Выбрать", !"Закрыть"); 					
			}
			else if(slot_inventory == 26 && pData[playerid][pSlotItem][2] == 0)
			{	
				return true;
			}
			else if(slot_inventory == 29 && pData[playerid][pSlotItem][3] != 0)
			{
				SetPVarIntNew(playerid, "type_inventory_aks", INVENTORY_AKS_BACK);

			    format(String256, sizeof(String256), "\
			        "cGREY"Информация\t"cGREY"Действие\n\
		        	"cGREY"Рюкзак: \t"cBLUE"%s (%d)\n\
		        	"cGREY"Описание: \t"cBLUE"%s\n\
			        \t\n\
			        "cBLUE"-"cWH"Снять аксессуар\t"cGR"Использовать\n\
			        "cBLUE"-"cWH"Выкинуть аксессуар\t"cGR"Использовать", 

		        	inventory_items[items_id][items_inv_name], inventory_items[items_id][items_inv_id],
		        	inventory_items[items_id][items_inv_text]
			        );
			    return SPD(playerid, DIALOG_ACTION_INV_ITEMS_AKS, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Предмет в инвентаре", String256, !"Выбрать", !"Закрыть"); 					
			}
			else if(slot_inventory == 29 && pData[playerid][pSlotItem][3] == 0)
			{	
				return true;
			}
			else
			{
			    format(String2048, sizeof(String2048), "\
			        "cGREY"Информация\t"cGREY"Действие\n\
		        	"cGREY"Предмет: \t"cBLUE"%s (%d)\n\
		        	"cGREY"Количество:\t"cBLUE"%d\n\
		        	"cGREY"Описание: \t"cBLUE"%s\n\
		        	"cGREY"Занимает места: \t"cBLUE"%f"cGREY" килограмм\n\
			        \t\n\
			        "cBLUE"-"cWH"Использовать предмет\t"cGR"Использовать\n\
			        "cBLUE"-"cWH"Выкинуть предмет\t"cGR"Использовать", 

		        	inventory_items[items_id][items_inv_name], inventory_items[items_id][items_inv_id],
		        	inventory_player[playerid][inventory_count][slot_inventory_f],
		        	inventory_items[items_id][items_inv_text],
		        	inventory_items[items_id][items_inv_mass]*inventory_player[playerid][inventory_count][slot_inventory_f]
			        );
			    return SPD(playerid, DIALOG_ACTION_INVENTORY_ITEMS, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Предмет в инвентаре", String2048, !"Выбрать", !"Закрыть"); 				
			}			
		}
	}

	return true;
}

stock dialog_all_inventory(playerid, dialogid, response, listitem, inputtext[])
{

	switch(dialogid)
	{
		case DIALOG_ACTION_INVENTORY_ITEMS:
		{
			if(!response)
				return true;

			new 
				items_id = GetPVarIntNew(playerid, "items_inventory_id"),
				items_slot = GetPVarIntNew(playerid, "items_inventory_slot");


			switch(listitem)
			{
				case 0: SelectTextDraw(playerid, COLOR_BLUE); 
				case 1: SelectTextDraw(playerid, COLOR_BLUE);
				case 2: SelectTextDraw(playerid, COLOR_BLUE);
				case 3: SelectTextDraw(playerid, COLOR_BLUE);
				case 4: SelectTextDraw(playerid, COLOR_BLUE);
				case 5: return use_inventory_items(playerid, items_id, items_slot);
				case 6: return drop_inventory_items(playerid, items_id, items_slot);
			}
		}
		case DIALOG_ACTION_INV_ITEMS_AKS:
		{
			if(!response)
				return true;
			
			new Str[128];

			format(Str, sizeof Str, "%d", listitem);
			SendClientMessage(playerid, -1, Str);

			new 
				items_id = GetPVarIntNew(playerid, "items_inventory_id"),
				items_slot = GetPVarIntNew(playerid, "items_inventory_slot"),
				type_aks = GetPVarIntNew(playerid, "type_inventory_aks");

			switch(listitem)
			{
				case 0: SelectTextDraw(playerid, COLOR_BLUE); 
				case 1: SelectTextDraw(playerid, COLOR_BLUE);
				case 2: SelectTextDraw(playerid, COLOR_BLUE);
				case 3: return change_inventory_items_aks(playerid, type_aks);
				case 4: return drop_inventory_items_aks(playerid, type_aks);
			}			

		}
	}


	return true;
}

stock change_inventory_items_aks(playerid, type_aks)
{
	switch(type_aks)
	{
		case INVENTORY_AKS_HEAD:
		{
			SetPVarIntNew(playerid, "old_aks_1_inventory", pData[playerid][pSlotItem][0]);

			pData[playerid][pSlotItem][0] = 0;
			AttachAcsToPlayer(playerid, GetPlayerSkin(playerid));

			switch(GetPVarIntNew(playerid, "old_aks_1_inventory"))
			{
				case 18156: give_inventory_items(playerid, 11, 1);
				case 18157: give_inventory_items(playerid, 12, 1);
				case 10998: give_inventory_items(playerid, 13, 1);
				case 10999: give_inventory_items(playerid, 14, 1);
				case 11000: give_inventory_items(playerid, 15, 1);
				case 11001: give_inventory_items(playerid, 16, 1);
			}

			DeletePVarNew(playerid, "old_aks_1_inventory");

			inventory_update_player(playerid);

			SendSucc(playerid, "Вы успешно сняли аксессуар с головы!");

		}
		case INVENTORY_AKS_FACE:
		{
			SetPVarIntNew(playerid, "old_aks_2_inventory", pData[playerid][pSlotItem][2]);

			pData[playerid][pSlotItem][2] = 0;
			AttachAcsToPlayer(playerid, GetPlayerSkin(playerid));

			switch(GetPVarIntNew(playerid, "old_aks_2_inventory"))
			{
				case 18158: give_inventory_items(playerid, 17, 1);
				case 18159: give_inventory_items(playerid, 18, 1);
				case 18160: give_inventory_items(playerid, 19, 1);
				case 10971: give_inventory_items(playerid, 20, 1);
				case 10972: give_inventory_items(playerid, 357, 1);
				case 10973: give_inventory_items(playerid, 21, 1);
				case 10974: give_inventory_items(playerid, 22, 1);
				case 10975: give_inventory_items(playerid, 23, 1);
				case 10976: give_inventory_items(playerid, 24, 1);
				case 10977: give_inventory_items(playerid, 25, 1);
				case 10978: give_inventory_items(playerid, 26, 1);
				case 10979: give_inventory_items(playerid, 27, 1);
				case 10980: give_inventory_items(playerid, 28, 1);
				case 10981: give_inventory_items(playerid, 29, 1);
				case 10982: give_inventory_items(playerid, 30, 1);

			}

			DeletePVarNew(playerid, "old_aks_2_inventory");

			inventory_update_player(playerid);

			SendSucc(playerid, "Вы успешно сняли аксессуар с лица!");

		}
		case INVENTORY_AKS_BACK:
		{
			SetPVarIntNew(playerid, "old_aks_3_inventory", pData[playerid][pSlotItem][3]);

			pData[playerid][pSlotItem][3] = 0;
			AttachAcsToPlayer(playerid, GetPlayerSkin(playerid));

			switch(GetPVarIntNew(playerid, "old_aks_3_inventory"))
			{
				case 11002: give_inventory_items(playerid, 31, 1);
				case 11003: give_inventory_items(playerid, 32, 1);
				case 11004: give_inventory_items(playerid, 33, 1);
				case 11005: give_inventory_items(playerid, 34, 1);
				case 11006: give_inventory_items(playerid, 35, 1);
				case 11007: give_inventory_items(playerid, 36, 1);
			}
			DeletePVarNew(playerid, "old_aks_3_inventory");

			inventory_update_player(playerid);

			SendSucc(playerid, "Вы успешно сняли аксессуар со спины!");

		}
	}

	return true;
}

stock drop_inventory_items_aks(playerid, type_aks)
{


	switch(type_aks)
	{
		case INVENTORY_AKS_HEAD:
		{
			format(String144, sizeof(String144), "Выкинул головной убор %d из инвентаря!", pData[playerid][pSlotItem][2]);
			logs_inventory(playerid, pData[playerid][pMysqlID], 1, String144);

			pData[playerid][pSlotItem][0] = 0;
			AttachAcsToPlayer(playerid, GetPlayerSkin(playerid));

			logs_inventory(playerid, pData[playerid][pMysqlID], 1, "Выкинул головной убор из инвентаря!");

			show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_42", 5000);

			inventory_update_player(playerid);
		}
		case INVENTORY_AKS_FACE:
		{
			format(String144, sizeof(String144), "Выкинул маску %d из инвентаря!", pData[playerid][pSlotItem][2]);
			logs_inventory(playerid, pData[playerid][pMysqlID], 1, String144);


			pData[playerid][pSlotItem][2] = 0;
			AttachAcsToPlayer(playerid, GetPlayerSkin(playerid));

			SendInf(playerid, "Вы успешно выкинули из инвентаря маску!");

			show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_42", 5000);

			inventory_update_player(playerid);
		}
		case INVENTORY_AKS_BACK:
		{
			format(String144, sizeof(String144), "Выкинул рюкзак %d из инвентаря!", pData[playerid][pSlotItem][3]);
			logs_inventory(playerid, pData[playerid][pMysqlID], 1, String144);

			pData[playerid][pSlotItem][3] = 0;
			AttachAcsToPlayer(playerid, GetPlayerSkin(playerid));

			SendInf(playerid, "Вы успешно выкинули из инвентаря рюкзак!");

			show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_42", 5000);

			inventory_update_player(playerid);
		}
	}

	return true;
}

stock use_inventory_items(playerid, items_id, items_slot)
{
	switch(items_id)
	{
		case 1:
		{
			PC_EmulateCommand(playerid, "/healme");	
		}
		case 2:
		{
			PC_EmulateCommand(playerid, "/time");	
		}
		case 3:
		{
			GivePlayerWeaponEx(playerid,14,1);
			return SendSucc(playerid, "Вы взяли в руки цветы!");
		}
		case 9:
		{
			PC_EmulateCommand(playerid, "/phone");
		}
		case 8:
		{
			PC_EmulateCommand(playerid, "/repaircar");
		}
		case 7:
		{
			PC_EmulateCommand(playerid, "/phonebook");
		}
		case 376:
		{
			PC_EmulateCommand(playerid, "/filloil");
		}
		case 377:
		{
			PC_EmulateCommand(playerid, "/fillcar");
		}
		case 11..16:
		{	
			SetPVarIntNew(playerid, "old_aks_1_inventory", pData[playerid][pSlotItem][0]);

			pData[playerid][pSlotItem][0] = inventory_items[items_id][items_inv_id];
			AttachAcsToPlayer(playerid, GetPlayerSkin(playerid));

			switch(GetPVarIntNew(playerid, "old_aks_1_inventory"))
			{
				case 18156: inventory_player[playerid][inventory_items_id][items_slot] = 11, inventory_player[playerid][inventory_count][items_slot] = 1;
				case 18157: inventory_player[playerid][inventory_items_id][items_slot] = 12, inventory_player[playerid][inventory_count][items_slot] = 1;
				case 10998: inventory_player[playerid][inventory_items_id][items_slot] = 13, inventory_player[playerid][inventory_count][items_slot] = 1;
				case 10999: inventory_player[playerid][inventory_items_id][items_slot] = 14, inventory_player[playerid][inventory_count][items_slot] = 1;
				case 11000: inventory_player[playerid][inventory_items_id][items_slot] = 15, inventory_player[playerid][inventory_count][items_slot] = 1;
				case 11001: inventory_player[playerid][inventory_items_id][items_slot] = 16, inventory_player[playerid][inventory_count][items_slot] = 1;
				case 0:
				{
					check_remove_inventory(playerid, items_id, items_slot, -1);
					DeletePVarNew(playerid, "old_aks_1_inventory");
					return true;
				}
			}
			format(String144, sizeof(String144), "Одел на себя шапку под номером %d | Старый аксессуар: %d", pData[playerid][pSlotItem][0], GetPVarIntNew(playerid, "old_aks_1_inventory"));
			logs_inventory(playerid, pData[playerid][pMysqlID], 1, String144);
			inventory_update_player(playerid);
		}

		case 17..30, 357:
		{	 
			SetPVarIntNew(playerid, "old_aks_2_inventory", pData[playerid][pSlotItem][2]);

			pData[playerid][pSlotItem][2] = inventory_items[items_id][items_inv_id];
			AttachAcsToPlayer(playerid, GetPlayerSkin(playerid));

			switch(GetPVarIntNew(playerid, "old_aks_2_inventory"))
			{
				case 18158: inventory_player[playerid][inventory_items_id][items_slot] = 17,  inventory_player[playerid][inventory_count][items_slot] = 1;
				case 18159: inventory_player[playerid][inventory_items_id][items_slot] = 18,  inventory_player[playerid][inventory_count][items_slot] = 1;
				case 18160: inventory_player[playerid][inventory_items_id][items_slot] = 19,  inventory_player[playerid][inventory_count][items_slot] = 1;
				case 10971: inventory_player[playerid][inventory_items_id][items_slot] = 20,  inventory_player[playerid][inventory_count][items_slot] = 1;
				case 10972: inventory_player[playerid][inventory_items_id][items_slot] = 357, inventory_player[playerid][inventory_count][items_slot] = 1;
				case 10973: inventory_player[playerid][inventory_items_id][items_slot] = 21,  inventory_player[playerid][inventory_count][items_slot] = 1;
				case 10974: inventory_player[playerid][inventory_items_id][items_slot] = 22,  inventory_player[playerid][inventory_count][items_slot] = 1;
				case 10975: inventory_player[playerid][inventory_items_id][items_slot] = 23,  inventory_player[playerid][inventory_count][items_slot] = 1;
				case 10976: inventory_player[playerid][inventory_items_id][items_slot] = 24,  inventory_player[playerid][inventory_count][items_slot] = 1;
				case 10977: inventory_player[playerid][inventory_items_id][items_slot] = 25,  inventory_player[playerid][inventory_count][items_slot] = 1;
				case 10978: inventory_player[playerid][inventory_items_id][items_slot] = 26,  inventory_player[playerid][inventory_count][items_slot] = 1;
				case 10979: inventory_player[playerid][inventory_items_id][items_slot] = 27,  inventory_player[playerid][inventory_count][items_slot] = 1;
				case 10980: inventory_player[playerid][inventory_items_id][items_slot] = 28,  inventory_player[playerid][inventory_count][items_slot] = 1;
				case 10981: inventory_player[playerid][inventory_items_id][items_slot] = 29,  inventory_player[playerid][inventory_count][items_slot] = 1;
				case 10982: inventory_player[playerid][inventory_items_id][items_slot] = 30,  inventory_player[playerid][inventory_count][items_slot] = 1;
				case 0:
				{
					check_remove_inventory(playerid, items_id, items_slot, -1);
					DeletePVarNew(playerid, "old_aks_2_inventory");
					return true;
				}
			}
			format(String144, sizeof(String144), "Одел на себя маску под номером %d | Старый аксессуар: %d", pData[playerid][pSlotItem][2], GetPVarIntNew(playerid, "old_aks_2_inventory"));
			logs_inventory(playerid, pData[playerid][pMysqlID], 1, String144);

			inventory_update_player(playerid);
		}
		case 31..36:
		{	
			SetPVarIntNew(playerid, "old_aks_3_inventory", pData[playerid][pSlotItem][3]);

			pData[playerid][pSlotItem][3] = inventory_items[items_id][items_inv_id];
			AttachAcsToPlayer(playerid, GetPlayerSkin(playerid));

			switch(GetPVarIntNew(playerid, "old_aks_3_inventory"))
			{
				case 11002: inventory_player[playerid][inventory_items_id][items_slot] = 31, inventory_player[playerid][inventory_count][items_slot] = 1;
				case 11003: inventory_player[playerid][inventory_items_id][items_slot] = 32, inventory_player[playerid][inventory_count][items_slot] = 1;
				case 11004: inventory_player[playerid][inventory_items_id][items_slot] = 33, inventory_player[playerid][inventory_count][items_slot] = 1;
				case 11005: inventory_player[playerid][inventory_items_id][items_slot] = 34, inventory_player[playerid][inventory_count][items_slot] = 1;
				case 11006: inventory_player[playerid][inventory_items_id][items_slot] = 35, inventory_player[playerid][inventory_count][items_slot] = 1;
				case 11007: inventory_player[playerid][inventory_items_id][items_slot] = 36, inventory_player[playerid][inventory_count][items_slot] = 1;
				case 0:
				{
					check_remove_inventory(playerid, items_id, items_slot, -1);
					DeletePVarNew(playerid, "old_aks_3_inventory");
					return true;
				}
			}

			format(String144, sizeof(String144), "Одел на себя рюкзак под номером %d | Старый аксессуар: %d", pData[playerid][pSlotItem][3], GetPVarIntNew(playerid, "old_aks_3_inventory"));
			logs_inventory(playerid, pData[playerid][pMysqlID], 1, String144);

			inventory_update_player(playerid);
		}
		case 37..335:
		{	
			SetPVarIntNew(playerid, "old_skin_inventory", pData[playerid][pSkin]);

			pData[playerid][pSkin] = inventory_items[items_id][items_inv_id];
			SetPlayerSkin(playerid, pData[playerid][pSkin]);

			inventory_player[playerid][inventory_items_id][items_slot] = GetPVarIntNew(playerid, "old_skin_inventory")+36;
			inventory_player[playerid][inventory_count][items_slot] = 1;
			DeletePVarNew(playerid, "old_skin_inventory");
		}
		case 336:
		{
			inventory_gui_panel(playerid, TEXTDRAW_HIDE);

    		pData[playerid][hungry] += 8;
    		show_hud_hungry(playerid);

			new 
				Float:health;
			GetPlayerHealth(playerid, health);
			SetPlayerHealth(playerid, health-15.0);

			SendSucc(playerid, "Вы успешно употребили сырое Мясо Лося и Ваше здоровье ухудшилось, но голод упал!");


			format(String144, sizeof(String144), "Использовал сырое мясо лося из инвентаря!");
			logs_inventory(playerid, pData[playerid][pMysqlID], 1, String144);

			check_remove_inventory(playerid, items_id, items_slot, -1);
		}
		case 337:
		{
			inventory_gui_panel(playerid, TEXTDRAW_HIDE);

    		pData[playerid][hungry] += 8;
    		show_hud_hungry(playerid);

			new 
				Float:health;
			GetPlayerHealth(playerid, health);
			SetPlayerHealth(playerid, health-10.0);


			SendSucc(playerid, "Вы успешно употребили сырое Мясо Зайца и Ваше здоровье ухудшилось, но голод упал!");

			format(String144, sizeof(String144), "Использовал сырое мясо зайца из инвентаря!");
			logs_inventory(playerid, pData[playerid][pMysqlID], 1, String144);

			check_remove_inventory(playerid, items_id, items_slot, -1);
		}
		case 338:
		{
    		pData[playerid][hungry] += 8;
    		show_hud_hungry(playerid);

			new 
				Float:health;
			GetPlayerHealth(playerid, health);
			SetPlayerHealth(playerid, health-25.0);

			SendSucc(playerid, "Вы успешно употребили сырое Мясо Кабана и Ваше здоровье ухудшилось, но голод упал!");

			format(String144, sizeof(String144), "Использовал сырое мясо кабана из инвентаря!");
			logs_inventory(playerid, pData[playerid][pMysqlID], 1, String144);

			check_remove_inventory(playerid, items_id, items_slot, -1);
		}
		case 339:
		{
			inventory_gui_panel(playerid, TEXTDRAW_HIDE);

    		pData[playerid][hungry] += 8;
    		show_hud_hungry(playerid);

			new 
				Float:health;
			GetPlayerHealth(playerid, health);
			SetPlayerHealth(playerid, health-25.0);

			SendSucc(playerid, "Вы успешно употребили сырое Мясо Медведя и Ваше здоровье ухудшилось, но голод упал!");

			format(String144, sizeof(String144), "Использовал сырое мясо медведя из инвентаря!");
			logs_inventory(playerid, pData[playerid][pMysqlID], 1, String144);

			check_remove_inventory(playerid, items_id, items_slot, -1);
		}
		case 358..372:
		{
			inventory_gui_panel(playerid, TEXTDRAW_HIDE);

    		pData[playerid][hungry] += 8;
    		show_hud_hungry(playerid);

			new 
				Float:health;
			GetPlayerHealth(playerid, health);
			SetPlayerHealth(playerid, health-25.0);

			SendSucc(playerid, "Вы успешно употребили сырую рыбу и Ваше здоровье ухудшилось, но голод упал!");

			format(String144, sizeof(String144), "Использовал сырую рыбу из инвентаря!");
			logs_inventory(playerid, pData[playerid][pMysqlID], 1, String144);

			check_remove_inventory(playerid, items_id, items_slot, -1);			
		}
		case 343..348:
		{
			inventory_gui_panel(playerid, TEXTDRAW_HIDE);

    		pData[playerid][hungry] += 10;
    		show_hud_hungry(playerid);

			SendSucc(playerid, "Вы успешно употребили фрукт в пищу!");

			format(String144, sizeof(String144), "Использовал фрукт из инвентаря!");
			logs_inventory(playerid, pData[playerid][pMysqlID], 1, String144);

			check_remove_inventory(playerid, items_id, items_slot, -1);			
		}
		case 341, 342:
		{
			inventory_gui_panel(playerid, TEXTDRAW_HIDE);

    		pData[playerid][hungry] += 10;
    		show_hud_hungry(playerid);

			SendSucc(playerid, "Вы успешно употребили овощ в пищу!");

			format(String144, sizeof(String144), "Использовал овощ из инвентаря!");
			logs_inventory(playerid, pData[playerid][pMysqlID], 1, String144);

			check_remove_inventory(playerid, items_id, items_slot, -1);			
		}		
		case 373:
		{
			if(GetPVarIntNew(playerid, "udochka_type_hand") == 1 || GetPVarIntNew(playerid, "udochka_type_hand") == 2 || GetPVarIntNew(playerid, "udochka_type_hand") == 3)
			{
				fish_attach_player_ud(playerid, TEXTDRAW_HIDE);
				DeletePVarNew(playerid, "udochka_type_hand");
				return true;
			}

			fish_attach_player_ud(playerid, TEXTDRAW_HIDE);
			fish_attach_player_ud(playerid, TEXTDRAW_SHOW, 18183);
			SetPVarIntNew(playerid, "udochka_type_hand", 1);

		}
		case 374:
		{
			if(GetPVarIntNew(playerid, "udochka_type_hand") == 1 || GetPVarIntNew(playerid, "udochka_type_hand") == 2 || GetPVarIntNew(playerid, "udochka_type_hand") == 3)
			{
				fish_attach_player_ud(playerid, TEXTDRAW_HIDE);
				DeletePVarNew(playerid, "udochka_type_hand");
				return true;
			}


			fish_attach_player_ud(playerid, TEXTDRAW_HIDE);
			fish_attach_player_ud(playerid, TEXTDRAW_SHOW, 18184);
			SetPVarIntNew(playerid, "udochka_type_hand", 2);
		}
		case 375:
		{
			if(GetPVarIntNew(playerid, "udochka_type_hand") == 1 || GetPVarIntNew(playerid, "udochka_type_hand") == 2 || GetPVarIntNew(playerid, "udochka_type_hand") == 3)
			{
				fish_attach_player_ud(playerid, TEXTDRAW_HIDE);
				DeletePVarNew(playerid, "udochka_type_hand");
				return true;
			}


			fish_attach_player_ud(playerid, TEXTDRAW_HIDE);
			fish_attach_player_ud(playerid, TEXTDRAW_SHOW, 18185);
			SetPVarIntNew(playerid, "udochka_type_hand", 3);
		}
	}
	return true;
}

stock drop_inventory_items(playerid, items_id, items_slot)
{

	if(inventory_player[playerid][inventory_count][items_slot] > 0)
	{
		inventory_player[playerid][inventory_count][items_slot]--;

		if(inventory_player[playerid][inventory_count][items_slot] == 0)
		{
			inventory_player[playerid][inventory_items_id][items_slot] = 0;
			inventory_player[playerid][inventory_count][items_slot] = 0;
			inventory_player[playerid][inventory_slot_id][items_slot] = 0;
		}

		format(String144, sizeof(String144), "Вы успешно выкинули из инвентаря %s. У вас осталось: %d штук!", 
		inventory_items[items_id][items_inv_name], inventory_player[playerid][inventory_count][items_slot]);
		SendInf(playerid, String144);

		logs_inventory(playerid, pData[playerid][pMysqlID], 1, String144);

		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_42", 5000);

		inventory_update_player(playerid);

		return true;
	}
	return true;
}

stock check_remove_inventory(playerid, items_id, items_slot, items_count = 1)
{

	if(inventory_player[playerid][inventory_count][items_slot] > 0)
	{
		format(String256, sizeof(String256), "Добавлен предмет в инвентаре ID: %d | Было: %d | Увеличилось на: %d | Слот: %d", items_id, inventory_player[playerid][inventory_count][items_slot], items_count, items_slot);
		logs_inventory(playerid, pData[playerid][pMysqlID], items_count, String256);

		inventory_player[playerid][inventory_count][items_slot] += items_count;

		if(inventory_player[playerid][inventory_count][items_slot] == 0)
		{
			inventory_player[playerid][inventory_items_id][items_slot] = 0;
			inventory_player[playerid][inventory_count][items_slot] = 0;
			inventory_player[playerid][inventory_slot_id][items_slot] = 0;

			format(String144, sizeof(String144), "Полностью удаёт предмет в инвентаре ID: %d", items_id);
			logs_inventory(playerid, pData[playerid][pMysqlID], items_count, String144);

		}
		if(GetPVarIntNew(playerid, "show_inventory_player")) inventory_update_player(playerid);
	}
	return true;
}



stock remove_inventory_items_full(playerid, items_id)
{
	if(pData[playerid][pInventoryLevel] == 1)
	{
	 	for(new i; i < 24; i++)
		{
			if(inventory_player[playerid][inventory_items_id][i] == items_id)
			{
				inventory_player[playerid][inventory_count][i] = 0;
				inventory_player[playerid][inventory_items_id][i] = 0;
				inventory_player[playerid][inventory_slot_id][i] = 0;

				format(String144, sizeof(String144), "Полностью удаёт предмет в инвентаре ID: %d", items_id);
				logs_inventory(playerid, pData[playerid][pMysqlID], 1, String144);

				inventory_update_player(playerid);

				//show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_42", 5000);
				return true;
			}
		}	
	}
	else if(pData[playerid][pInventoryLevel] == 2)
	{
	 	for(new i; i < 48; i++)
		{
			if(inventory_player[playerid][inventory_items_id][i] == items_id)
			{
				inventory_player[playerid][inventory_count][i] = 0;
				inventory_player[playerid][inventory_items_id][i] = 0;
				inventory_player[playerid][inventory_slot_id][i] = 0;

				format(String144, sizeof(String144), "Полностью удаёт предмет в инвентаре ID: %d", items_id);
				logs_inventory(playerid, pData[playerid][pMysqlID], 1, String144);

				inventory_update_player(playerid);

				//show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_42", 5000);
				return true;
			}
		}
	}
	else if(pData[playerid][pInventoryLevel] == 3)
	{
	 	for(new i; i < 72; i++)
		{
			if(inventory_player[playerid][inventory_items_id][i] == items_id)
			{
				inventory_player[playerid][inventory_count][i] = 0;
				inventory_player[playerid][inventory_items_id][i] = 0;
				inventory_player[playerid][inventory_slot_id][i] = 0;

				format(String144, sizeof(String144), "Полностью удаёт предмет в инвентаре ID: %d", items_id);
				logs_inventory(playerid, pData[playerid][pMysqlID], 1, String144);

				inventory_update_player(playerid);

				//show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_42", 5000);
				return true;
			}
		}
	}
	return true;
}

stock inventory_update_player(playerid)
{
	inventory_gui_panel(playerid, TEXTDRAW_HIDE);
	inventory_gui_panel(playerid, TEXTDRAW_SHOW);

	return true;
}

CMD:give_items(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8)
    	return NoCMD(playerid);	

	if(sscanf(params, "ddd", params[0], params[1], params[2])) 
		return SendInf(playerid, "/give_items [ID игрока] [ID предмета] [Количество]");
	
	give_inventory_items(params[0], params[1], params[2]);

	return true;
}

CMD:inventory_level(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8)
    	return NoCMD(playerid);	

	if(sscanf(params, "dd", params[0], params[1])) 
		return SendInf(playerid, "/inventory_level [ID игрока] [Уровень инвентаря]");

	pData[params[0]][pInventoryLevel] = params[1];
	return true;
}

stock give_inventory_items(playerid, items_id, items_count)
{
	if(pData[playerid][pInventoryLevel] == 1)
	{
	 	for(new i; i < 24; i++)
		{
			if(inventory_player[playerid][inventory_items_id][i] == items_id)
			{
				inventory_player[playerid][inventory_count][i] += items_count;

				format(String144, sizeof(String144), "Cуществующий предмет в инвентаре ID: %d увеличен до %d штук", items_id, items_count);
				logs_inventory(playerid, pData[playerid][pMysqlID], items_count, String144);


				return SendSucc(playerid, "Предмет был успешно добавлен в существующий слот!");
			}
			if(!inventory_player[playerid][inventory_slot_id][i] && !inventory_player[playerid][inventory_count][i])
			{
				inventory_player[playerid][inventory_slot_id][i] = i;
				inventory_player[playerid][inventory_items_id][i] = items_id;
				inventory_player[playerid][inventory_count][i] = items_count;

				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_41", 5000);

				format(String144, sizeof(String144), "Новый предмет в инвентаре ID: %d | Слот: %d | Количество: %d", items_id, i, items_count);
				logs_inventory(playerid, pData[playerid][pMysqlID], items_count, String144);

				return SendSucc(playerid, "Вам успешно добавили новый предмет в инвентарь!");
			}
		}
	}
	else if(pData[playerid][pInventoryLevel] == 2)
	{
	 	for(new i; i < 48; i++)
		{
			if(inventory_player[playerid][inventory_items_id][i] == items_id)
			{
				inventory_player[playerid][inventory_count][i] += items_count;

				format(String144, sizeof(String144), "Cуществующий предмет в инвентаре ID: %d увеличен до %d штук", items_id, items_count);
				logs_inventory(playerid, pData[playerid][pMysqlID], items_count, String144);

				return SendSucc(playerid, "Предмет был успешно добавлен в существующий слот!");
			}
			if(!inventory_player[playerid][inventory_slot_id][i] && !inventory_player[playerid][inventory_count][i])
			{
				inventory_player[playerid][inventory_slot_id][i] = i;
				inventory_player[playerid][inventory_items_id][i] = items_id;
				inventory_player[playerid][inventory_count][i] = items_count;

				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_41", 5000);

				format(String144, sizeof(String144), "Новый предмет в инвентаре ID: %d | Слот: %d | Количество: %d", items_id, i, items_count);
				logs_inventory(playerid, pData[playerid][pMysqlID], items_count, String144);

				return SendSucc(playerid, "Вам успешно добавили новый предмет в инвентарь!");
			}
		}		
	}
	else if(pData[playerid][pInventoryLevel] == 3)
	{
	 	for(new i; i < 72; i++)
		{
			if(inventory_player[playerid][inventory_items_id][i] == items_id)
			{
				inventory_player[playerid][inventory_count][i] += items_count;

				format(String144, sizeof(String144), "Cуществующий предмет в инвентаре ID: %d увеличен до %d штук", items_id, items_count);
				logs_inventory(playerid, pData[playerid][pMysqlID], items_count, String144);

				return SendSucc(playerid, "Предмет был успешно добавлен в существующий слот!");
			}
			if(!inventory_player[playerid][inventory_slot_id][i] && !inventory_player[playerid][inventory_count][i])
			{
				inventory_player[playerid][inventory_slot_id][i] = i;
				inventory_player[playerid][inventory_items_id][i] = items_id;
				inventory_player[playerid][inventory_count][i] = items_count;

				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_41", 5000);

				format(String144, sizeof(String144), "Новый предмет в инвентаре ID: %d | Слот: %d | Количество: %d", items_id, i, items_count);
				logs_inventory(playerid, pData[playerid][pMysqlID], items_count, String144);

				return SendSucc(playerid, "Вам успешно добавили новый предмет в инвентарь!");
			}
		}		
	}
	return true;
}


stock get_inventory_items(playerid, items_id)
{
	new 
		count_items;
	if(pData[playerid][pInventoryLevel] == 1)
	{
	 	for(new i; i < 24; i++)
		{
			if(inventory_player[playerid][inventory_items_id][i] == items_id)
			{
				count_items = inventory_player[playerid][inventory_count][i];
				break;
			}
		}
		return count_items;
	}
	else if(pData[playerid][pInventoryLevel] == 2)
	{
	 	for(new i; i < 48; i++)
		{
			if(inventory_player[playerid][inventory_items_id][i] == items_id)
			{
				count_items = inventory_player[playerid][inventory_count][i];
				break;
			}
		}
		return count_items;		
	}
	else if(pData[playerid][pInventoryLevel] == 3)
	{
	 	for(new i; i < 72; i++)
		{
			if(inventory_player[playerid][inventory_items_id][i] == items_id)
			{
				count_items = inventory_player[playerid][inventory_count][i];
				break;
			}
		}
		return count_items;		
	}
	return true;
}

stock get_inventory_items_slot(playerid, items_id)
{
	new 
		count_items;

	if(pData[playerid][pInventoryLevel] == 1)
	{
	 	for(new i; i < 24; i++)
		{
			if(inventory_player[playerid][inventory_items_id][i] == items_id)
			{
				count_items = inventory_player[playerid][inventory_slot_id][i];
				break;
			}
		}
		return count_items;
	}
	else if(pData[playerid][pInventoryLevel] == 2)
	{
	 	for(new i; i < 48; i++)
		{
			if(inventory_player[playerid][inventory_items_id][i] == items_id)
			{
				count_items = inventory_player[playerid][inventory_slot_id][i];
				break;
			}
		}
		return count_items;		
	}
	else if(pData[playerid][pInventoryLevel] == 3)
	{
	 	for(new i; i < 72; i++)
		{
			if(inventory_player[playerid][inventory_items_id][i] == items_id)
			{
				count_items = inventory_player[playerid][inventory_slot_id][i];
				break;
			}
		}
		return count_items;		
	}
	return true;
}

stock inventory_update_page(playerid)
{
	new 
		inventory_page = GetPVarIntNew(playerid, "inventory_show_page"),
		fmt_str[50];

	if(pData[playerid][pInventoryLevel] == 1)
	{
	 	format(fmt_str,sizeof(fmt_str),"%d/1", inventory_page);
	 	PlayerTextDrawSetString(playerid, inventory_gui_p[33][playerid], fmt_str);
	 	PlayerTextDrawShow(playerid, inventory_gui_p[33][playerid]);

	}
	else if(pData[playerid][pInventoryLevel] == 2)
	{
	 	format(fmt_str,sizeof(fmt_str),"%d/2", inventory_page);
	 	PlayerTextDrawSetString(playerid, inventory_gui_p[33][playerid], fmt_str);
	 	PlayerTextDrawShow(playerid, inventory_gui_p[33][playerid]);
	}
	else if(pData[playerid][pInventoryLevel] == 3)
	{
	 	format(fmt_str,sizeof(fmt_str),"%d/3", inventory_page);
	 	PlayerTextDrawSetString(playerid, inventory_gui_p[33][playerid], fmt_str);
	 	PlayerTextDrawShow(playerid, inventory_gui_p[33][playerid]);		
	}
 	return true;
}

stock inventory_update_mass(playerid)
{

	new 
		Float:mass_inventory,
		fmt_str[50];

	if(pData[playerid][pInventoryLevel] == 1)
	{
	 	for(new i; i < 24; i++)
		{
			new 
				slot_id = inventory_player[playerid][inventory_slot_id][i],
				items_id = inventory_player[playerid][inventory_items_id][i];
			mass_inventory += inventory_items[items_id][items_inv_mass]*inventory_player[playerid][inventory_count][i];
		}
	 	format(fmt_str,sizeof(fmt_str),"%d_KG", floatround(mass_inventory));
	 	PlayerTextDrawSetString(playerid, inventory_gui_p[34][playerid], fmt_str);
	 	PlayerTextDrawShow(playerid, inventory_gui_p[34][playerid]);

	}
	else if(pData[playerid][pInventoryLevel] == 2)
	{
	 	for(new i; i < 48; i++)
		{
			new 
				slot_id = inventory_player[playerid][inventory_slot_id][i],
				items_id = inventory_player[playerid][inventory_items_id][i];
			mass_inventory += inventory_items[items_id][items_inv_mass]*inventory_player[playerid][inventory_count][i];
		}
	 	format(fmt_str,sizeof(fmt_str),"%d_KG", floatround(mass_inventory));
	 	PlayerTextDrawSetString(playerid, inventory_gui_p[34][playerid], fmt_str);
	 	PlayerTextDrawShow(playerid, inventory_gui_p[34][playerid]);
	}
	else if(pData[playerid][pInventoryLevel] == 3)
	{
	 	for(new i; i < 72; i++)
		{
			new 
				slot_id = inventory_player[playerid][inventory_slot_id][i],
				items_id = inventory_player[playerid][inventory_items_id][i];
			mass_inventory += inventory_items[items_id][items_inv_mass]*inventory_player[playerid][inventory_count][i];
		}
	 	format(fmt_str,sizeof(fmt_str),"%d_KG", floatround(mass_inventory));
	 	PlayerTextDrawSetString(playerid, inventory_gui_p[34][playerid], fmt_str);
	 	PlayerTextDrawShow(playerid, inventory_gui_p[34][playerid]);		
	}
 	return true;
}

stock inventory_gui_panel(playerid, status, page = PAGE_INVENTORY_1)
{
	new 
		fmt_str[50];

	switch(status)
	{
		case TEXTDRAW_SHOW:
		{	

			show_info_gui(playerid, TEXTDRAW_HIDE);
			TogglePlayerAllHudElements(playerid, HUD_ELEMENT_HIDE);

			hide_hud_element(playerid);
			show_player_green_zone(playerid, TEXTDRAW_HIDE);
 
			SetPVarIntNew(playerid, "show_inventory_player", 1);

			TextDrawShowForPlayer(playerid, inventory_gui_back[0]);
			TextDrawShowForPlayer(playerid, inventory_gui_back[1]);
			TextDrawShowForPlayer(playerid, inventory_gui_back[2]);
			TextDrawShowForPlayer(playerid, inventory_gui_back[3]);

			create_player_inventory(playerid);

			new 
				Float:mass_inventory;

			SetPVarIntNew(playerid, "inventory_show_page", page);
			inventory_update_page(playerid);
			inventory_update_mass(playerid);

			switch(page)
			{
				case PAGE_INVENTORY_1:
				{


					if(pData[playerid][pSlotItem][0])
					{
						PlayerTextDrawSetString(playerid, inventory_gui_p[24][playerid], "brillinv:inventory_slot_12");	
						PlayerTextDrawShow(playerid, inventory_gui_p[24][playerid]);				
					}
					else
					{
						PlayerTextDrawSetString(playerid, inventory_gui_p[24][playerid], "brillinv:inventory_head_slot");	
						PlayerTextDrawShow(playerid, inventory_gui_p[24][playerid]);						
					}

					if(pData[playerid][pSlotItem][2])
					{
						PlayerTextDrawSetString(playerid, inventory_gui_p[26][playerid], "brillinv:inventory_slot_11");	
						PlayerTextDrawShow(playerid, inventory_gui_p[26][playerid]);				
					}
					else
					{
						PlayerTextDrawSetString(playerid, inventory_gui_p[26][playerid], "brillinv:inventory_mask_slot");	
						PlayerTextDrawShow(playerid, inventory_gui_p[26][playerid]);						
					}

					if(pData[playerid][pSlotItem][3])
					{
						PlayerTextDrawSetString(playerid, inventory_gui_p[31][playerid], "brillinv:inventory_slot_14");	
						PlayerTextDrawShow(playerid, inventory_gui_p[31][playerid]);				
					}
					else
					{
						PlayerTextDrawSetString(playerid, inventory_gui_p[31][playerid], "brillinv:inventory_back_slot");	
						PlayerTextDrawShow(playerid, inventory_gui_p[31][playerid]);						
					}

					PlayerTextDrawShow(playerid, inventory_gui_p[25][playerid]);
					PlayerTextDrawShow(playerid, inventory_gui_p[32][playerid]);
					PlayerTextDrawShow(playerid, inventory_gui_p[27][playerid]);
					PlayerTextDrawShow(playerid, inventory_gui_p[28][playerid]);
					PlayerTextDrawShow(playerid, inventory_gui_p[29][playerid]);
					PlayerTextDrawShow(playerid, inventory_gui_p[30][playerid]);
					PlayerTextDrawShow(playerid, inventory_gui_p[32][playerid]);
					PlayerTextDrawShow(playerid, inventory_gui_p[33][playerid]);
					PlayerTextDrawShow(playerid, inventory_gui_p[34][playerid]);

				 	for(new i; i < 24; i++)
					{		
						new 
							slot_id = inventory_player[playerid][inventory_slot_id][i],
							items_id = inventory_player[playerid][inventory_items_id][i];

						PlayerTextDrawSetString(playerid, inventory_gui_p[i][playerid], "brillinv:inventory_slot");	
						PlayerTextDrawShow(playerid, inventory_gui_p[i][playerid]);

						

						new 
							fmt_str[50];

						// Жёсткие костыли, так как цикл вызывает проблемы
						// Первая строчка
					 	if(inventory_player[playerid][inventory_count][0] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][0]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[35][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[35][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][1] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][1]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[36][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[36][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][2] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][2]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[37][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[37][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][3] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][3]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[38][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[38][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][4] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][4]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[39][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[39][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][5] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][5]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[40][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[40][playerid]);
						}

					 	// Вторая строчка
					 	if(inventory_player[playerid][inventory_count][6] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][6]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[41][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[41][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][7] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][7]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[42][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[42][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][8] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][8]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[43][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[43][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][9] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][9]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[44][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[44][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][10] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][10]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[45][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[45][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][11] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][11]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[46][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[46][playerid]);
						}

					 	// Третья строчка

					 	if(inventory_player[playerid][inventory_count][12] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][12]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[47][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[47][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][13] != 0)
					 	{						
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][13]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[48][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[48][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][14] != 0)
					 	{	
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][14]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[49][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[49][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][15] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][15]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[50][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[50][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][16] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][16]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[51][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[51][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][17] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][17]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[52][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[52][playerid]);
						}

					 	// Чётвертая строчка
					 	if(inventory_player[playerid][inventory_count][18] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][18]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[53][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[53][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][19] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][19]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[54][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[54][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][20] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][20]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[55][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[55][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][21] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][21]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[56][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[56][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][22] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][22]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[57][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[57][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][23] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][23]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[58][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[58][playerid]);
						}

						if(inventory_player[playerid][inventory_items_id][i] < 10 && inventory_player[playerid][inventory_items_id][i] > 0)
						{
							

							format(String64, sizeof(String64), "brillinv:inventory_slot_%d", inventory_player[playerid][inventory_items_id][i]);
							PlayerTextDrawSetString(playerid, inventory_gui_p[i][playerid], String64);	
							PlayerTextDrawShow(playerid, inventory_gui_p[i][playerid]);			
						}

						else if(inventory_player[playerid][inventory_items_id][i] < 17 && inventory_player[playerid][inventory_items_id][i] >= 10)
						{

							PlayerTextDrawSetString(playerid, inventory_gui_p[i][playerid], "brillinv:inventory_slot_13");
							PlayerTextDrawShow(playerid, inventory_gui_p[i][playerid]);
						}
						else if(inventory_player[playerid][inventory_items_id][i] < 31 && inventory_player[playerid][inventory_items_id][i] >= 17)
						{

							PlayerTextDrawSetString(playerid, inventory_gui_p[i][playerid], "brillinv:inventory_slot_11");	
							PlayerTextDrawShow(playerid, inventory_gui_p[i][playerid]);	
						}
						else if(inventory_player[playerid][inventory_items_id][i] < 37 && inventory_player[playerid][inventory_items_id][i] > 30)
						{

							PlayerTextDrawSetString(playerid, inventory_gui_p[i][playerid], "brillinv:inventory_slot_14");	
							PlayerTextDrawShow(playerid, inventory_gui_p[i][playerid]);
						}
						else if(inventory_player[playerid][inventory_items_id][i] < 37 && inventory_player[playerid][inventory_items_id][i] > 36)
						{

							PlayerTextDrawSetString(playerid, inventory_gui_p[i][playerid], "brillinv:inventory_slot_14");	
							PlayerTextDrawShow(playerid, inventory_gui_p[i][playerid]);
						}	
						else if(inventory_player[playerid][inventory_items_id][i] < 336 && inventory_player[playerid][inventory_items_id][i] > 36)
						{

							PlayerTextDrawSetString(playerid, inventory_gui_p[i][playerid], "brillinv:inventory_slot_10");	
							PlayerTextDrawShow(playerid, inventory_gui_p[i][playerid]);
						}			

						else if(inventory_player[playerid][inventory_items_id][i] < 2000 && inventory_player[playerid][inventory_items_id][i] > 335)
						{
							PlayerTextDrawSetString(playerid, inventory_gui_p[i][playerid], "brillinv:inventory_slot_10");	
							PlayerTextDrawShow(playerid, inventory_gui_p[i][playerid]);

							format(String64, sizeof(String64), "brillinv:inventory_slot_%d", inventory_player[playerid][inventory_items_id][i]);
							PlayerTextDrawSetString(playerid, inventory_gui_p[i][playerid], String64);	
							PlayerTextDrawShow(playerid, inventory_gui_p[i][playerid]);	

						}	

					}
				}
				case PAGE_INVENTORY_2:
				{

					if(pData[playerid][pSlotItem][0])
					{
						PlayerTextDrawSetString(playerid, inventory_gui_p[24][playerid], "brillinv:inventory_slot_12");	
						PlayerTextDrawShow(playerid, inventory_gui_p[24][playerid]);				
					}
					else
					{
						PlayerTextDrawSetString(playerid, inventory_gui_p[24][playerid], "brillinv:inventory_head_slot");	
						PlayerTextDrawShow(playerid, inventory_gui_p[24][playerid]);						
					}

					if(pData[playerid][pSlotItem][2])
					{
						PlayerTextDrawSetString(playerid, inventory_gui_p[26][playerid], "brillinv:inventory_slot_11");	
						PlayerTextDrawShow(playerid, inventory_gui_p[26][playerid]);				
					}
					else
					{
						PlayerTextDrawSetString(playerid, inventory_gui_p[26][playerid], "brillinv:inventory_mask_slot");	
						PlayerTextDrawShow(playerid, inventory_gui_p[26][playerid]);						
					}

					if(pData[playerid][pSlotItem][3])
					{
						PlayerTextDrawSetString(playerid, inventory_gui_p[31][playerid], "brillinv:inventory_slot_14");	
						PlayerTextDrawShow(playerid, inventory_gui_p[31][playerid]);				
					}
					else
					{
						PlayerTextDrawSetString(playerid, inventory_gui_p[31][playerid], "brillinv:inventory_back_slot");	
						PlayerTextDrawShow(playerid, inventory_gui_p[31][playerid]);						
					}

					PlayerTextDrawShow(playerid, inventory_gui_p[25][playerid]);
					PlayerTextDrawShow(playerid, inventory_gui_p[32][playerid]);
					PlayerTextDrawShow(playerid, inventory_gui_p[27][playerid]);
					PlayerTextDrawShow(playerid, inventory_gui_p[28][playerid]);
					PlayerTextDrawShow(playerid, inventory_gui_p[29][playerid]);
					PlayerTextDrawShow(playerid, inventory_gui_p[30][playerid]);
					PlayerTextDrawShow(playerid, inventory_gui_p[32][playerid]);
					PlayerTextDrawShow(playerid, inventory_gui_p[33][playerid]);
					PlayerTextDrawShow(playerid, inventory_gui_p[34][playerid]);

				 	for(new i; i < 24; i++)
					{		
						new 
							slot_id = inventory_player[playerid][inventory_slot_id][i+24],
							items_id = inventory_player[playerid][inventory_items_id][i+24];

						PlayerTextDrawSetString(playerid, inventory_gui_p[i][playerid], "brillinv:inventory_slot");	
						PlayerTextDrawShow(playerid, inventory_gui_p[i][playerid]);

						new 
							fmt_str[50];

						// Жёсткие костыли, так как цикл вызывает проблемы
						// Первая строчка
					 	if(inventory_player[playerid][inventory_count][24] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][24]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[35][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[35][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][25] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][25]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[36][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[36][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][26] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][26]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[37][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[37][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][27] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][27]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[38][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[38][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][28] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][28]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[39][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[39][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][29] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][29]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[40][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[40][playerid]);
						}

					 	// Вторая строчка
					 	if(inventory_player[playerid][inventory_count][30] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][30]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[41][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[41][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][31] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][31]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[42][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[42][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][32] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][32]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[43][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[43][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][33] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][33]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[44][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[44][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][34] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][34]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[45][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[45][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][35] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][35]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[46][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[46][playerid]);
						}

					 	// Третья строчка

					 	if(inventory_player[playerid][inventory_count][36] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][36]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[47][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[47][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][37] != 0)
					 	{						
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][37]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[48][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[48][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][38] != 0)
					 	{	
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][38]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[49][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[49][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][39] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][39]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[50][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[50][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][40] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][40]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[51][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[51][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][41] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][41]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[52][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[52][playerid]);
						}

					 	// Чётвертая строчка
					 	if(inventory_player[playerid][inventory_count][42] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][42]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[53][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[53][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][43] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][44]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[54][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[54][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][45] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][45]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[55][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[55][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][46] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][46]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[56][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[56][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][47] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][47]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[57][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[57][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][48] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][48]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[58][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[58][playerid]);
						}

						if(inventory_player[playerid][inventory_items_id][i+24] < 10 && inventory_player[playerid][inventory_items_id][i+24] > 0)
						{
							

							format(String64, sizeof(String64), "brillinv:inventory_slot_%d", inventory_player[playerid][inventory_items_id][i+24]);
							PlayerTextDrawSetString(playerid, inventory_gui_p[i][playerid], String64);	
							PlayerTextDrawShow(playerid, inventory_gui_p[i][playerid]);			
						}

						else if(inventory_player[playerid][inventory_items_id][i+24] < 17 && inventory_player[playerid][inventory_items_id][i+24] >= 10)
						{

							PlayerTextDrawSetString(playerid, inventory_gui_p[i][playerid], "brillinv:inventory_slot_13");
							PlayerTextDrawShow(playerid, inventory_gui_p[i][playerid]);
						}
						else if(inventory_player[playerid][inventory_items_id][i+24] < 31 && inventory_player[playerid][inventory_items_id][i+24] >= 17)
						{

							PlayerTextDrawSetString(playerid, inventory_gui_p[i][playerid], "brillinv:inventory_slot_11");	
							PlayerTextDrawShow(playerid, inventory_gui_p[i][playerid]);	
						}
						else if(inventory_player[playerid][inventory_items_id][i+24] < 37 && inventory_player[playerid][inventory_items_id][i+24] > 30)
						{

							PlayerTextDrawSetString(playerid, inventory_gui_p[i][playerid], "brillinv:inventory_slot_14");	
							PlayerTextDrawShow(playerid, inventory_gui_p[i][playerid]);
						}
						else if(inventory_player[playerid][inventory_items_id][i+24] < 37 && inventory_player[playerid][inventory_items_id][i+24] > 36)
						{

							PlayerTextDrawSetString(playerid, inventory_gui_p[i][playerid], "brillinv:inventory_slot_14");	
							PlayerTextDrawShow(playerid, inventory_gui_p[i][playerid]);
						}	
						else if(inventory_player[playerid][inventory_items_id][i+24] < 336 && inventory_player[playerid][inventory_items_id][i+24] > 36)
						{

							PlayerTextDrawSetString(playerid, inventory_gui_p[i][playerid], "brillinv:inventory_slot_10");	
							PlayerTextDrawShow(playerid, inventory_gui_p[i][playerid]);
						}			

						else if(inventory_player[playerid][inventory_items_id][i+24] < 2000 && inventory_player[playerid][inventory_items_id][i+24] > 335)
						{
							PlayerTextDrawSetString(playerid, inventory_gui_p[i][playerid], "brillinv:inventory_slot_10");	
							PlayerTextDrawShow(playerid, inventory_gui_p[i][playerid]);

							format(String64, sizeof(String64), "brillinv:inventory_slot_%d", inventory_player[playerid][inventory_items_id][i+24]);
							PlayerTextDrawSetString(playerid, inventory_gui_p[i][playerid], String64);	
							PlayerTextDrawShow(playerid, inventory_gui_p[i][playerid]);	

						}	

					}
				}
				case PAGE_INVENTORY_3:
				{
					if(pData[playerid][pSlotItem][0])
					{
						PlayerTextDrawSetString(playerid, inventory_gui_p[24][playerid], "brillinv:inventory_slot_12");	
						PlayerTextDrawShow(playerid, inventory_gui_p[24][playerid]);				
					}
					else
					{
						PlayerTextDrawSetString(playerid, inventory_gui_p[24][playerid], "brillinv:inventory_head_slot");	
						PlayerTextDrawShow(playerid, inventory_gui_p[24][playerid]);						
					}

					if(pData[playerid][pSlotItem][2])
					{
						PlayerTextDrawSetString(playerid, inventory_gui_p[26][playerid], "brillinv:inventory_slot_11");	
						PlayerTextDrawShow(playerid, inventory_gui_p[26][playerid]);				
					}
					else
					{
						PlayerTextDrawSetString(playerid, inventory_gui_p[26][playerid], "brillinv:inventory_mask_slot");	
						PlayerTextDrawShow(playerid, inventory_gui_p[26][playerid]);						
					}

					if(pData[playerid][pSlotItem][3])
					{
						PlayerTextDrawSetString(playerid, inventory_gui_p[31][playerid], "brillinv:inventory_slot_14");	
						PlayerTextDrawShow(playerid, inventory_gui_p[31][playerid]);				
					}
					else
					{
						PlayerTextDrawSetString(playerid, inventory_gui_p[31][playerid], "brillinv:inventory_back_slot");	
						PlayerTextDrawShow(playerid, inventory_gui_p[31][playerid]);						
					}

					PlayerTextDrawShow(playerid, inventory_gui_p[25][playerid]);
					PlayerTextDrawShow(playerid, inventory_gui_p[32][playerid]);
					PlayerTextDrawShow(playerid, inventory_gui_p[27][playerid]);
					PlayerTextDrawShow(playerid, inventory_gui_p[28][playerid]);
					PlayerTextDrawShow(playerid, inventory_gui_p[29][playerid]);
					PlayerTextDrawShow(playerid, inventory_gui_p[30][playerid]);
					PlayerTextDrawShow(playerid, inventory_gui_p[32][playerid]);
					PlayerTextDrawShow(playerid, inventory_gui_p[33][playerid]);
					PlayerTextDrawShow(playerid, inventory_gui_p[34][playerid]);

				 	for(new i; i < 24; i++)
					{		
						new 
							slot_id = inventory_player[playerid][inventory_slot_id][i+49],
							items_id = inventory_player[playerid][inventory_items_id][i+49];

						PlayerTextDrawSetString(playerid, inventory_gui_p[i][playerid], "brillinv:inventory_slot");	
						PlayerTextDrawShow(playerid, inventory_gui_p[i][playerid]);

						new 
							fmt_str[50];

						// Жёсткие костыли, так как цикл вызывает проблемы
						// Первая строчка
					 	if(inventory_player[playerid][inventory_count][49] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][49]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[35][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[35][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][50] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][50]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[36][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[36][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][51] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][51]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[37][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[37][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][52] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][52]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[38][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[38][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][53] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][53]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[39][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[39][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][54] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][55]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[40][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[40][playerid]);
						}

					 	// Вторая строчка
					 	if(inventory_player[playerid][inventory_count][56] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][56]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[41][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[41][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][57] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][57]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[42][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[42][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][58] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][58]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[43][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[43][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][59] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][59]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[44][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[44][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][60] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][60]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[45][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[45][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][61] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][61]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[46][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[46][playerid]);
						}

					 	// Третья строчка

					 	if(inventory_player[playerid][inventory_count][62] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][62]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[47][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[47][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][63] != 0)
					 	{						
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][63]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[48][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[48][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][64] != 0)
					 	{	
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][64]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[49][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[49][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][65] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][65]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[50][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[50][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][66] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][66]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[51][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[51][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][67] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][67]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[52][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[52][playerid]);
						}

					 	// Чётвертая строчка
					 	if(inventory_player[playerid][inventory_count][68] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][68]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[53][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[53][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][69] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][69]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[54][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[54][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][70] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][70]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[55][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[55][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][71] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][71]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[56][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[56][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][72] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][72]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[57][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[57][playerid]);
						}
					 	if(inventory_player[playerid][inventory_count][73] != 0)
					 	{
						 	format(fmt_str,sizeof(fmt_str),"%d", inventory_player[playerid][inventory_count][73]);
						 	PlayerTextDrawSetString(playerid, inventory_gui_p[58][playerid], fmt_str);
						 	PlayerTextDrawShow(playerid, inventory_gui_p[58][playerid]);
						}

						if(inventory_player[playerid][inventory_items_id][i+49] < 10 && inventory_player[playerid][inventory_items_id][i+49] > 0)
						{
							

							format(String64, sizeof(String64), "brillinv:inventory_slot_%d", inventory_player[playerid][inventory_items_id][i+49]);
							PlayerTextDrawSetString(playerid, inventory_gui_p[i][playerid], String64);	
							PlayerTextDrawShow(playerid, inventory_gui_p[i][playerid]);			
						}

						else if(inventory_player[playerid][inventory_items_id][i+49] < 17 && inventory_player[playerid][inventory_items_id][i+49] >= 10)
						{

							PlayerTextDrawSetString(playerid, inventory_gui_p[i][playerid], "brillinv:inventory_slot_13");
							PlayerTextDrawShow(playerid, inventory_gui_p[i][playerid]);
						}
						else if(inventory_player[playerid][inventory_items_id][i+49] < 31 && inventory_player[playerid][inventory_items_id][i+49] >= 17)
						{

							PlayerTextDrawSetString(playerid, inventory_gui_p[i][playerid], "brillinv:inventory_slot_11");	
							PlayerTextDrawShow(playerid, inventory_gui_p[i][playerid]);	
						}
						else if(inventory_player[playerid][inventory_items_id][i+49] < 37 && inventory_player[playerid][inventory_items_id][i+49] > 30)
						{

							PlayerTextDrawSetString(playerid, inventory_gui_p[i][playerid], "brillinv:inventory_slot_14");	
							PlayerTextDrawShow(playerid, inventory_gui_p[i][playerid]);
						}
						else if(inventory_player[playerid][inventory_items_id][i+49] < 37 && inventory_player[playerid][inventory_items_id][i+49] > 36)
						{

							PlayerTextDrawSetString(playerid, inventory_gui_p[i][playerid], "brillinv:inventory_slot_14");	
							PlayerTextDrawShow(playerid, inventory_gui_p[i][playerid]);
						}	
						else if(inventory_player[playerid][inventory_items_id][i+49] < 336 && inventory_player[playerid][inventory_items_id][i+49] > 36)
						{

							PlayerTextDrawSetString(playerid, inventory_gui_p[i][playerid], "brillinv:inventory_slot_10");	
							PlayerTextDrawShow(playerid, inventory_gui_p[i][playerid]);
						}			

						else if(inventory_player[playerid][inventory_items_id][i+49] < 2000 && inventory_player[playerid][inventory_items_id][i+49] > 335)
						{
							PlayerTextDrawSetString(playerid, inventory_gui_p[i][playerid], "brillinv:inventory_slot_10");	
							PlayerTextDrawShow(playerid, inventory_gui_p[i][playerid]);

							format(String64, sizeof(String64), "brillinv:inventory_slot_%d", inventory_player[playerid][inventory_items_id][i+49]);
							PlayerTextDrawSetString(playerid, inventory_gui_p[i][playerid], String64);	
							PlayerTextDrawShow(playerid, inventory_gui_p[i][playerid]);	

						}	

					}
				}
			}

			SelectTextDraw(playerid, COLOR_BLUE);
		}
		case TEXTDRAW_HIDE:
		{
			TogglePlayerAllHudElements(playerid, HUD_ELEMENT_SHOW);

			CancelSelectTextDraw(playerid);

			for(new i; i < 59; i++)
			{
				PlayerTextDrawHideEx(playerid, inventory_gui_p[i][playerid]);
			}

			TextDrawHideForPlayer(playerid, inventory_gui_back[0]);
			TextDrawHideForPlayer(playerid, inventory_gui_back[1]);
			TextDrawHideForPlayer(playerid, inventory_gui_back[2]);
			TextDrawHideForPlayer(playerid, inventory_gui_back[3]);

			if(pGreenZone[playerid])
			{
				show_player_green_zone(playerid, TEXTDRAW_SHOW);
			}
			show_hud_element(playerid);
			show_hud_hungry(playerid);

			show_info_gui(playerid, TEXTDRAW_SHOW);

			DeletePVarNew(playerid, "show_inventory_player");
			DeletePVarNew(playerid, "inventory_show_page");
		}
	}
	return true;
}


stock inventory_params_clear(playerid)
{
	inventory_gui_panel(playerid, TEXTDRAW_HIDE);

	DeletePVarNew(playerid, "show_inventory_player");
	DeletePVarNew(playerid, "inventory_show_page");
	return true;
}