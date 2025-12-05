


cmd:unrent(playerid)
{

	unrent_start_game_transport(playerid);
	autosalon_unrent_car(playerid);
	end_working_taxi(playerid);
	end_mechanic_jobs(playerid);
	end_trucker_job(playerid);
	unrent_job_trucker(playerid);
	end_snow_work(playerid);

	rent_update_timer(playerid);
	end_trash_work(playerid);

	return true;

}


CMD:company(playerid)
{

	new
		owner_1[24], 
		owner_1_r[24],
		owner_2[24], 
		owner_2_r[24],  
		owner_3[24], 
		owner_3_r[24];

	new 
		owner_4[24], 
		owner_4_r[24], 
		owner_5[24], 
		owner_5_r[24],
		owner_6[24],
		owner_6_r[24];



	if(trucker_station[0][trucker_base_owner_id] != -1)
	{
		GetPlayerNameByID(trucker_station[0][trucker_base_owner_id], trucker_station[0][trucker_base_owner]);
		format(owner_1, 24, trucker_station[0][trucker_base_owner]);
	}
	else 
	{
		format(owner_1, 24, "Отсутствует");	
	}

	if(trucker_station[0][trucker_low_owner_id] != -1)
	{
		GetPlayerNameByID(trucker_station[0][trucker_low_owner_id], trucker_station[0][trucker_low_owner]);
		format(owner_1_r, 24, trucker_station[0][trucker_low_owner]);
	}
	else
	{
		format(owner_1_r, 24, "Отсутствует");	
	}

	if(trucker_station[1][trucker_base_owner_id] != -1)
	{
		GetPlayerNameByID(trucker_station[1][trucker_base_owner_id], trucker_station[1][trucker_base_owner]);
		format(owner_2, 24, trucker_station[1][trucker_base_owner]);
	}
	else
	{
		format(owner_2, 24, "Отсутствует");	
	}

	if(trucker_station[1][trucker_low_owner_id] != -1)
	{
		GetPlayerNameByID(trucker_station[1][trucker_low_owner_id], trucker_station[1][trucker_low_owner]);
		format(owner_2_r, 24, trucker_station[1][trucker_low_owner]);
	}
	else
	{
		format(owner_2_r, 24, "Отсутствует");	
	}

	if(trucker_station[2][trucker_base_owner_id] != -1)
	{
		GetPlayerNameByID(trucker_station[2][trucker_base_owner_id], trucker_station[2][trucker_base_owner]);
		format(owner_3, 24, trucker_station[2][trucker_base_owner]);
	}
	else
	{
		format(owner_3, 24, "Отсутствует");	
	}

	if(trucker_station[2][trucker_low_owner_id] != -1)
	{
		GetPlayerNameByID(trucker_station[2][trucker_low_owner_id], trucker_station[2][trucker_low_owner]);
		format(owner_3_r, 24, trucker_station[2][trucker_low_owner]);
	}
	else
	{
		format(owner_3_r, 24, "Отсутствует");	
	}

	new 
		number_tk_1[10],
		number_tk_2[10],
		number_tk_3[10],
		number_tk_4[10],
		number_tk_5[10],
		number_tk_6[10];

	if(GetPlayerID(owner_1) != -1)
	{
		format(number_tk_1, 10, pData[GetPlayerID(owner_1)][pPhone]);
	}
	else
	{
		format(number_tk_1, 10, "******** ");
	}

	if(GetPlayerID(owner_1_r) != -1)
	{
		format(number_tk_2, 10, pData[GetPlayerID(owner_2)][pPhone]);
	}
	else
	{
		format(number_tk_2, 10, "******** ");	
	}

	if(GetPlayerID(owner_2) != -1)
	{
		format(number_tk_3, 10, pData[GetPlayerID(owner_3)][pPhone]);
	}
	else
	{
		format(number_tk_3, 10, "******** ");
	}

	if(GetPlayerID(owner_2_r) != -1)
	{
		format(number_tk_4, 10, pData[GetPlayerID(owner_4)][pPhone]);
	}
	else
	{
		format(number_tk_4, 10, "******** ");	
	}

	if(GetPlayerID(owner_3) != -1)
	{
		format(number_tk_5, 10, pData[GetPlayerID(owner_5)][pPhone]);
	}
	else
	{
		format(number_tk_5, 10, "******** ");
	}

	if(GetPlayerID(owner_3_r) != -1)
	{
		format(number_tk_6, 10, pData[GetPlayerID(owner_6)][pPhone]);
	}
	else
	{
		format(number_tk_6, 10, "******** ");
	}


	new 
		mechanic_low_nick_1[32],
		mechanic_low_phone_1[10];

	new 
		mechanic_low_nick_2[32],
		mechanic_low_phone_2[10];

	new 
		mechanic_low_nick_3[32],
		mechanic_low_phone_3[10];

	new Result:pldata = sql_queryEx(zConn, "SELECT * FROM `accounts` WHERE mech = '0' LIMIT 1", QUERY_CACHED);
	if(sql_num_rows(pldata)) 
	{
		sql_get_field_assoc_ex(pldata, 0, "nickname", mechanic_low_nick_1, 24);
		sql_get_field_assoc_ex(pldata, 0, "phone", mechanic_low_phone_1, 10);

		format(mechanic_low_phone_1, 10, mechanic_low_phone_1);	
	}
	else
	{
		format(mechanic_low_phone_1, 10, "******** ");	
		format(mechanic_low_nick_1, 24, "Отсутствует");
	}	
	sql_free_result(pldata);

	new Result:pldata0 = sql_queryEx(zConn, "SELECT * FROM `accounts` WHERE mech = '1' LIMIT 1", QUERY_CACHED);
	if(sql_num_rows(pldata0)) 
	{
		sql_get_field_assoc_ex(pldata0, 0, "nickname", mechanic_low_nick_2, 24);
		sql_get_field_assoc_ex(pldata0, 0, "phone", mechanic_low_phone_2, 10);

		format(mechanic_low_phone_2, 10, mechanic_low_phone_2);		
	}
	else
	{
		format(mechanic_low_phone_2, 10,"******** ");	
		format(mechanic_low_nick_2, 24, "Отсутствует");
	}

	sql_free_result(pldata0);

	new Result:pldata1 = sql_queryEx(zConn, "SELECT * FROM `accounts` WHERE mech = '2' LIMIT 1", QUERY_CACHED);
	if(sql_num_rows(pldata1)) 
	{
		sql_get_field_assoc_ex(pldata1, 0, "nickname", mechanic_low_nick_3, 24);
		sql_get_field_assoc_ex(pldata1, 0, "phone", mechanic_low_phone_3, 10);
		format(mechanic_low_phone_3, 10, mechanic_low_phone_3);			
	}
	else
	{
		format(mechanic_low_phone_3, 10, "******** ");	
		format(mechanic_low_nick_3, 24, "Отсутствует");
	}

	sql_free_result(pldata1);

	new
		mowner[24],
		mowner1[24],
		mowner2[24];

	if(!strcmp("None", mechanic[0][mechanic_base_owner]))
		format(mowner, 24, "Отсутствует");
	else
		format(mowner, 24, mechanic[0][mechanic_base_owner]);

	if(!strcmp("None", mechanic[1][mechanic_base_owner]))
		format(mowner1, 24, "Отсутствует");
	else
		format(mowner1, 24, mechanic[1][mechanic_base_owner]);

	if(!strcmp("None", mechanic[2][mechanic_base_owner]))
		format(mowner2, 24, "Отсутствует");
	else
		format(mowner2, 24, mechanic[2][mechanic_base_owner]);

	new 
		mechanic_phone_1[10],
		mechanic_phone_2[10],
		mechanic_phone_3[10];

	new Result:pldata2 = sql_queryEx(zConn, "SELECT * FROM `accounts` WHERE pMechOwnerID = '0' LIMIT 1", QUERY_CACHED);
	if(sql_num_rows(pldata2)) 
	{

		sql_get_field_assoc_ex(pldata2, 0, "phone", mechanic_phone_1, 10);
		format(mechanic_phone_1, 10, mechanic_phone_1);	
	}
	else
	{
		format(mechanic_phone_1, 10, "******** ");
	}

	sql_free_result(pldata2);

	new Result:pldata3 = sql_queryEx(zConn, "SELECT * FROM `accounts` WHERE pMechOwnerID = '1' LIMIT 1", QUERY_CACHED);
	if(sql_num_rows(pldata3)) 
	{
		sql_get_field_assoc_ex(pldata3, 0, "phone", mechanic_phone_2, 10);
		format(mechanic_phone_2, 10, mechanic_phone_2);		
	}
	else
	{
		format(mechanic_phone_2, 10, "******** ");
	}

	sql_free_result(pldata3);

	new Result:pldata4 = sql_queryEx(zConn, "SELECT * FROM `accounts` WHERE pMechOwnerID = '2' LIMIT 1", QUERY_CACHED);
	if(sql_num_rows(pldata4)) 
	{
		sql_get_field_assoc_ex(pldata4, 0, "phone", mechanic_phone_3, 10);
		format(mechanic_phone_3, 10, mechanic_phone_2);	
	}
	else
	{
		format(mechanic_phone_3, 10, "******** ");
	}

	sql_free_result(pldata4);

    format(String2048, sizeof(String2048), "\
        "cGREY"Компания\t"cGREY"Контакт\t"cGREY"Номер (Статус)\n\
        "cBLUE"- "cWH"Транспортная Компания №1 (Владелец)\t"cBLUE"%s\t"cGR"%s %s\n\
        "cBLUE"- "cWH"Транспортная Компания №1 (Заместитель)\t"cBLUE"%s\t"cGR"%s %s\n\
        "cBLUE"- "cWH"Транспортная Компания №2 (Владелец)\t"cBLUE"%s\t"cGR"%s %s\n\
        "cBLUE"- "cWH"Транспортная Компания №2 (Заместитель)\t"cBLUE"%s\t"cGR"%s %s\n\
        "cBLUE"- "cWH"Транспортная Компания №3 (Владелец)\t"cBLUE"%s\t"cGR"%s %s\n\
        "cBLUE"- "cWH"Транспортная Компания №3 (Заместитель)\t"cBLUE"%s\t"cGR"%s %s\n\
        \t\t\t\n\
        "cBLUE"- "cWH"СТО №1 (Владелец)\t"cBLUE"%s\t"cGR"%s %s\n\
        "cBLUE"- "cWH"СТО №1 (Заместитель)\t"cBLUE"%s\t"cGR"%s %s\n\
        "cBLUE"- "cWH"СТО №2 (Владелец)\t"cBLUE"%s\t"cGR"%s %s\n\
        "cBLUE"- "cWH"СТО №2 (Заместитель)\t"cBLUE"%s\t"cGR"%s %s\n\
        "cBLUE"- "cWH"СТО №3 (Владелец)\t"cBLUE"%s\t"cGR"%s %s\n\
        "cBLUE"- "cWH"СТО №3 (Заместитель)\t"cBLUE"%s\t"cGR"%s %s",

        owner_1, number_tk_1, (GetPlayerID(owner_1) != -1) ? (""cGR" [Онлайн]") : (""cLRED" [Оффлайн]"),
        owner_1_r, number_tk_2, (GetPlayerID(owner_1_r) != -1) ? (""cGR" [Онлайн]") : (""cLRED" [Оффлайн]"),
        owner_2, number_tk_3, (GetPlayerID(owner_2) != -1) ? (""cGR" [Онлайн]") : (""cLRED" [Оффлайн]"),
        owner_2_r, number_tk_4, (GetPlayerID(owner_2_r) != -1) ? (""cGR" [Онлайн]") : (""cLRED" [Оффлайн]"),
        owner_3, number_tk_5, (GetPlayerID(owner_3_r) != -1) ? (""cGR" [Онлайн]") : (""cLRED" [Оффлайн]"),
        owner_3_r, number_tk_6, (GetPlayerID(owner_3_r) != -1) ? (""cGR" [Онлайн]") : (""cLRED" [Оффлайн]"),

        mowner, mechanic_phone_1, (GetPlayerID(owner_2_r) != -1) ? (""cGR" [Онлайн]") : (""cLRED" [Оффлайн]"),
        mechanic_low_nick_1, mechanic_low_phone_1, (GetPlayerID(mechanic_low_nick_1) != -1) ? (""cGR" [Онлайн]") : (""cLRED" [Оффлайн]"),
        mowner1, mechanic_phone_2, (GetPlayerID(owner_2_r) != -1) ? (""cGR" [Онлайн]") : (""cLRED" [Оффлайн]"),
        mechanic_low_nick_2, mechanic_low_phone_2, (GetPlayerID(mechanic_low_nick_2) != -1) ? (""cGR" [Онлайн]") : (""cLRED" [Оффлайн]"),
        mowner2, mechanic_phone_3, (GetPlayerID(owner_2_r) != -1) ? (""cGR" [Онлайн]") : (""cLRED" [Оффлайн]"),
        mechanic_low_nick_3, mechanic_low_phone_3, (GetPlayerID(mechanic_low_nick_3) != -1) ? (""cGR" [Онлайн]") : (""cLRED" [Оффлайн]")

        );
    return SPD(playerid, 0, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Список компаний:", String2048, !"Закрыть", ""); 

}

CMD:offblack(playerid, params[])
{
	if( pData[playerid][pFraction] < 1 ) return 1;
	if(IsAGang(playerid))
	{
		new h; gettime(h);
		if(pData[playerid][pRank] < 10) return SendClientMessage(playerid,COLOR_LIGHTRED,"Функция доступна только лидеру!");
		new faction = pData[playerid][pFraction]-3;

		if(sscanf(params, "s[32]", params[0])) 
			return SendInf(playerid, "/offblack [Name]");

   		sql_escape_string(zConn, params[0], params[0], 128);

//			new query[512];
		format(String512,sizeof(String512),"SELECT `id`,`fraction`,`blist` FROM `accounts` WHERE `nickname` = '%s'", params[0]);
		new Result:r = sql_queryEx(zConn, String512, QUERY_CACHED);
		if(!sql_num_rows(r)) {
		sql_free_result(r);
		return SendClientMessage(playerid,CGRAY,"Неверный Ник");}

		new SIDS = sql_get_field_int(r, 0);
		new SFRAC = sql_get_field_int(r, 1);
		new SBLAKLIST[80];
		sql_get_field(r, 2, SBLAKLIST );
		sql_free_result( r );

		new SBLAKLISTPL[5];

        sscanf(SBLAKLIST, "p<,>a<i>[5]", SBLAKLISTPL ); //Считываем чс


		foreach(Player, x)
		{
		    if( pData[x][pMysqlID] == SIDS ) return SendClientMessage(playerid,CGRAY,"Данный игрок Online");
		}
		if( SFRAC == pData[playerid][pFraction] ) return SendClientMessage(playerid,CGRAY,"Игрок состоит в вашей банде");

		if( SBLAKLISTPL[faction] == 0 )
		{
			SBLAKLISTPL[faction] = 1;
			format(String256, sizeof(String256), "Вы добавили %s в черный список ОПГ", params[0]);
			SendSucc(playerid, String256);
			format(String256, sizeof(String256), "%s добавил %s в черный список ОПГ", pData[playerid][pNickname],params[0]);
			SendFMes(pData[playerid][pFraction],CBLUE, String256);

		}
		else if( SBLAKLISTPL[faction] != 0 )
		{
			SBLAKLISTPL[faction] = 0;
			format(String256, sizeof(String256), "Вы убрали %s из черного списка ОПГ",params[0]);
			SendSucc(playerid, String256);
	
			format(String256, sizeof(String256), "%s убрал %s из черного списка ОПГ", pData[playerid][pNickname],params[0]);
			SendFMes(pData[playerid][pFraction],CBLUE, String256);

		}
		new SETBLACK[80];
		format(SETBLACK ,80,"%d,%d,%d,%d,%d",
		SBLAKLISTPL[0],SBLAKLISTPL[1],SBLAKLISTPL[2],
		SBLAKLISTPL[3],SBLAKLISTPL[4]);
		format(String1024,sizeof(String1024),"UPDATE `accounts` SET `blist`='%s' WHERE `nickname`='%s'",SETBLACK , params[0]);
		sql_queryEx(zConn, String1024, QUERY_THREADED);
	}
	else 
	{
		new h; gettime(h);
        if(pData[playerid][pRank] < gFractionRankCount[pData[playerid][pFraction]-1]) return SendClientMessage(playerid,CGRAY,"Команда доступна только лидеру организации.");
		new faction = pData[playerid][pFraction]-1;

   		sql_escape_string(zConn, params[0], params[0], 128);

		format(String512,sizeof(String512),"SELECT `id`,`fraction`,`blist2` FROM `accounts` WHERE `nickname` = '%s'",params[0]);
		new Result:r = sql_queryEx(zConn, String512, QUERY_CACHED);
		if(!sql_num_rows(r)) 
		{
			sql_free_result(r);
			return SendClientMessage(playerid,CGRAY,"Неверный Ник");
		}

		new SIDS = sql_get_field_int(r, 0);
		new SFRAC = sql_get_field_int(r, 1);
		new SBLAKLIST[150];
		sql_get_field(r, 2, SBLAKLIST );
		sql_free_result( r );

		new SBLAKLISTPL[15];
	    sscanf(SBLAKLIST, "p<,>a<i>[15]", SBLAKLISTPL ); //Считываем чс


		foreach(Player, x)
		{
		    if( pData[x][pMysqlID] == SIDS ) return SendClientMessage(playerid,CGRAY,"Данный игрок Online");
		}


		if(SFRAC == pData[playerid][pFraction] ) return SendClientMessage(playerid,CGRAY,"Игрок состоит в вашей фракции");

		if( SBLAKLISTPL[faction] == 0 )
		{
			SBLAKLISTPL[faction] = 1;
			format(String256, sizeof(String256), "Вы добавили %s в черный список фракции", params[0] );
			SendSucc(playerid, String256);
	
			format(String256, sizeof(String256), "%s добавил %s в черный список фракции", pData[playerid][pNickname], params[0]);
			SendFMes(pData[playerid][pFraction],CBLUE, String256);

		}
		else if( SBLAKLISTPL[faction] != 0 )
		{
			SBLAKLISTPL[faction] = 0;
			format(String256, sizeof(String256), "Вы убрали %s из черного списка фракции", params[0]);
			SendSucc(playerid, String256);
	
	
			format(String256, sizeof(String256), "%s убрал %s из черного списка фракции", pData[playerid][pNickname], params[0] );
			SendFMes(pData[playerid][pFraction],CBLUE, String256);

		}
		new SETBLACK[150];

		format(SETBLACK,150,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
		SBLAKLISTPL[0],SBLAKLISTPL[1],SBLAKLISTPL[2],
		SBLAKLISTPL[3],SBLAKLISTPL[4],
		SBLAKLISTPL[5],SBLAKLISTPL[6],SBLAKLISTPL[7],
		SBLAKLISTPL[8],SBLAKLISTPL[9],
		SBLAKLISTPL[10],SBLAKLISTPL[11],SBLAKLISTPL[12],
		SBLAKLISTPL[13],SBLAKLISTPL[14]			);
		format(String1024,sizeof(String1024),"UPDATE `accounts` SET `blist2`='%s' WHERE `nickname`='%s'",SETBLACK , params[0]  );
		sql_queryEx(zConn, String1024, QUERY_THREADED);
	}
	return true;
}

CMD:blackinfo(playerid, params[])
{
	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/blackinfo [ID]");

	if( pData[playerid][pFraction] < 1 ) return 1;
	if(IsAGang(playerid))
	{
		new h; gettime(h);
		if(pData[playerid][pRank] < 10) return SendClientMessage(playerid,COLOR_LIGHTRED,"Функция доступна только лидеру!");
		new faction = pData[playerid][pFraction]-3;

		new actplayerid = params[0];
		if(!IsPlayerConnected(actplayerid) || actplayerid == playerid || pData[actplayerid][pMysqlID] == 0 ) return SendClientMessage(playerid,CGRAY,"Неверный ID игрока");
		if(pData[actplayerid][pFraction] == pData[playerid][pFraction] ) return SendClientMessage(playerid,CGRAY,"Игрок состоит в вашей банде");

		if( pData[actplayerid][pBlackList][faction] == 0 )
		{
			format(String256, sizeof(String256), "%s {99FFBB}не состоит в черном списке фракции", pData[actplayerid][pNickname]);
			SendInf(playerid, String256);
		}
		else if( pData[actplayerid][pBlackList][faction] != 0 )
		{
			format(String256, sizeof(String256), "%s {FF0000}состоит в черном списке фракции", pData[actplayerid][pNickname]);
			SendInf(playerid, String256);
		}
	}
	else 
	{
		new h; gettime(h);
        if(pData[playerid][pRank] < gFractionRankCount[pData[playerid][pFraction]-1]) return SendClientMessage(playerid,CGRAY,"Команда доступна только лидеру организации.");
		new faction = pData[playerid][pFraction]-1;

		new actplayerid = params[0];
		if(!IsPlayerConnected(actplayerid) || actplayerid == playerid || pData[actplayerid][pMysqlID] == 0 ) return SendClientMessage(playerid,CGRAY,"Неверный ID игрока");
		if(pData[actplayerid][pFraction] == pData[playerid][pFraction] ) return SendClientMessage(playerid,CGRAY,"Игрок состоит в вашей фракции");

		if( pData[actplayerid][pBlackListNew][faction] == 0 )
		{
			format(String256, sizeof(String256), "%s {99FFBB}не состоит в черном списке фракции", pData[actplayerid][pNickname]);
			SendSucc(playerid, String256);
		}
		else if(pData[actplayerid][pBlackListNew][faction] != 0 )
		{
			format(String256, sizeof(String256), "%s {FF0000}состоит в черном списке фракции", pData[actplayerid][pNickname]);
			SendSucc(playerid, String256);
		}
	}
	return true;
}

CMD:ticket(playerid, params[])
{
	if(sscanf(params, "dds[32]", params[0], params[1], params[2])) 
		return SendInf(playerid, "/ticket [ID игрока] [Сумма] [Причина]");


	if(!IsACop(playerid)) 
		return SendClientMessage(playerid,CGRAY,"Эта функция только для МВД/ФСБ");
	if( pData[playerid][pRank] < 3) 
		return SendClientMessage(playerid,CGRAY,"Ваш ранг не достаточен для этого");

	new id = params[0];

	if(!IsPlayerConnected(id) || id == playerid || id < 0 || id > MAX_PLAYERS-1) 
		return SendClientMessage(playerid,CGRAY,"Неверный ID игрока");

	if(pData[id][pFraction] == 9) 
		return SendClientMessage(playerid,CGRAY,"Нельзя оштрафовать законника");

	if(GetPVarIntNew(id, "shtaftime") > gettime()) 
		return SendErr(playerid, "Этот водитель недавно был оштрафован");

	if(id == playerid)  
		return SendErr(playerid, "Вы не можете оштрафовать самого себя");

	new money = params[1];

	if(money < 100 || money > 5000) 
		return SendClientMessage(playerid,CGRAY,"Штраф не может быть меньше P100 и больше P5000");

	if(!params[1]) 
		return SendClientMessage(playerid,CGRAY,"/ticket [ID игрока] [Сумма] [Причина]");

	if(GetPlayerDistanceToPlayer(playerid,id) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(id)) 
		return SendClientMessage(playerid,CGRAY,"Вы далеко друг от друга");

    pData[id][pUnemployment] += money;
    UpdatePlayerData(id,"unemployment", pData[id][pUnemployment] );
	new percent = money/50;
	if(percent > 100) 
	{ 
		percent = 100; 
	}
	else if(percent < 0)
	{ 
		percent = 0; 
	}

	pData[playerid][pSalary] += percent;
	UpdatePlayerData(playerid, "salary", pData[playerid][pSalary]);

    format(String256,sizeof(String256),"%s {FFCC33}выписал Вам штраф в размере {FFFFFF}%dP{FFCC33}. Причина: {FFFFFF}%s",pData[playerid][pNickname],money,params[2]);
    SendClientMessage(id,0xFFFFFFFF, String256);

    format(String256,sizeof(String256),"{FFFFFF}%s {FFCC33}выписал %s штраф в размере {FFFFFF}%dP{FFCC33}. Причина: {FFFFFF}%s",pData[playerid][pNickname],pData[id][pNickname],money,params[2]);
	CopMes(CDEPARTMENT,String256);
	SendInf(id,"Оплатить штраф вы можете в отделениях МВД");
	SetPVarIntNew(id, "shtaftime", gettime() + 60*5);

	if(pData[playerid][pSex] == 2) 
	{
		MeAction(playerid,"выписала штраф");
	}
	else 
	{
		MeAction(playerid,"выписал штраф");
	}

	return true;
}

CMD:black(playerid, params[])
{
	if(pData[playerid][pFraction] < 1) return 1;

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/black [ID]");

	if(IsAGang(playerid))
	{
		new h; gettime(h);
		if(pData[playerid][pRank] < 10) 
			return SendClientMessage(playerid,COLOR_LIGHTRED,"Функция доступна только лидеру!");

		new faction = pData[playerid][pFraction]-3;

		new actplayerid = params[0];

		if(!IsPlayerConnected(actplayerid) || actplayerid == playerid || pData[actplayerid][pMysqlID] == 0 ) return SendClientMessage(playerid,CGRAY,"Неверный ID игрока");
		if(pData[actplayerid][pFraction] == pData[playerid][pFraction] ) return SendClientMessage(playerid,CGRAY,"Игрок состоит в вашей банде");

		if( pData[actplayerid][pBlackList][faction] == 0 )
		{
			pData[actplayerid][pBlackList][faction] = 1;
			format(String256, sizeof(String256), "Вы добавили %s в черный список ОПГ", pData[actplayerid][pNickname]);
			SendSucc(playerid, String256);
			format(String256, sizeof(String256), "%s добавил вас в черный список %s", pData[playerid][pNickname],gFractionName[faction+2]);
			SendClientMessage(actplayerid,0xFFECB3FF, String256 );
	
			format(String256, sizeof(String256), "%s добавил %s в черный список ОПГ", pData[playerid][pNickname],pData[actplayerid][pNickname]);
			SendFMes(pData[playerid][pFraction],CBLUE, String256);

		}
		else if( pData[actplayerid][pBlackList][faction] != 0 )
		{
			pData[actplayerid][pBlackList][faction] = 0;
			format(String256, sizeof(String256), "Вы убрали %s из черного списка ОПГ", pData[actplayerid][pNickname]);
			SendSucc(playerid, String256);
	
			format(String256, sizeof(String256), "%s убрал вас из черного списка %s", pData[playerid][pNickname],gFractionName[faction+2]);
			SendClientMessage(actplayerid,0xFFECB3FF, String256 );
	
			format(String256, sizeof(String256), "%s убрал %s из черного списка ОПГ", pData[playerid][pNickname],pData[actplayerid][pNickname]);
			SendFMes(pData[playerid][pFraction],CBLUE, String256);

		}

		format(pData[actplayerid][pBlack],80,"%d,%d,%d,%d,%d",
		pData[actplayerid][pBlackList][0],pData[actplayerid][pBlackList][1],pData[actplayerid][pBlackList][2],
		pData[actplayerid][pBlackList][3],pData[actplayerid][pBlackList][4]);
		format(String1024,sizeof(String1024),"UPDATE `accounts` SET `blist`='%s' WHERE `nickname`='%s'", pData[actplayerid][pBlack] , pData[actplayerid][pNickname]);
		sql_queryEx(zConn, String1024, QUERY_THREADED);
		}
	else 
	{
		new h; gettime(h);
        if(pData[playerid][pRank] < gFractionRankCount[pData[playerid][pFraction]-1]) 
        	return SendClientMessage(playerid,CGRAY,"Команда доступна только лидеру организации.");
		new faction = pData[playerid][pFraction]-1;

		new actplayerid = params[0];
		if(!IsPlayerConnected(actplayerid) || actplayerid == playerid || pData[actplayerid][pMysqlID] == 0 ) 
			return SendClientMessage(playerid,CGRAY,"Неверный ID игрока");
		if(pData[actplayerid][pFraction] == pData[playerid][pFraction] ) 
			return SendClientMessage(playerid,CGRAY,"Игрок состоит в вашей фракции");

		if( pData[actplayerid][pBlackListNew][faction] == 0 )
		{
			pData[actplayerid][pBlackListNew][faction] = 1;
			format(String256, sizeof(String256), "Вы добавили %s в черный список фракции", pData[actplayerid][pNickname]);
			SendSucc(playerid, String256);
			format(String256, sizeof(String256), "%s добавил вас в черный список %s", pData[playerid][pNickname],gFractionName[faction]);
			SendClientMessage(actplayerid,0xFFECB3FF, String256 );
	
			format(String256, sizeof(String256), "%s добавил %s в черный список фракции", pData[playerid][pNickname],pData[actplayerid][pNickname]);
			SendFMes(pData[playerid][pFraction],CBLUE, String256);

		}
		else if( pData[actplayerid][pBlackListNew][faction] != 0 )
		{
			pData[actplayerid][pBlackListNew][faction] = 0;
			format(String256, sizeof(String256), "Вы убрали %s из черного списка фракции", pData[actplayerid][pNickname]);
			SendSucc(playerid, String256);
	
			format(String256, sizeof(String256), "%s убрал вас из черного списка %s", pData[playerid][pNickname],gFractionName[faction]);
			SendClientMessage(actplayerid,0xFFECB3FF, String256 );
	
			format(String256, sizeof(String256), "%s убрал %s из черного списка фракции", pData[playerid][pNickname],pData[actplayerid][pNickname]);
			SendFMes(pData[playerid][pFraction],CBLUE, String256);

		}

		format(pData[actplayerid][pBlack2],150,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
		pData[actplayerid][pBlackListNew][0],pData[actplayerid][pBlackListNew][1],pData[actplayerid][pBlackListNew][2],
		pData[actplayerid][pBlackListNew][3],pData[actplayerid][pBlackListNew][4],
		pData[actplayerid][pBlackListNew][5],pData[actplayerid][pBlackListNew][6],pData[actplayerid][pBlackListNew][7],
		pData[actplayerid][pBlackListNew][8],pData[actplayerid][pBlackListNew][9],
		pData[actplayerid][pBlackListNew][10],pData[actplayerid][pBlackListNew][11],pData[actplayerid][pBlackListNew][12],
		pData[actplayerid][pBlackListNew][13],pData[actplayerid][pBlackListNew][14]			);
		format(String1024,sizeof(String1024),"UPDATE `accounts` SET `blist2`='%s' WHERE `nickname`='%s'", pData[actplayerid][pBlack2] , pData[actplayerid][pNickname]);
		sql_queryEx(zConn, String1024, QUERY_THREADED);
	}	

	return true;
}

CMD:flower(playerid, params[])
{
	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/flower [ID]");


	if(GetPlayerDistanceToPlayer(playerid, params[0]) > 5.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(params[0])) 
		return SendErr(playerid,"Вы далеко друг от друга");

	if(GetPlayerState(playerid) != 1) 
		return SendErr(playerid,"Вы не должны находиться в автомобиле");
	if(GetPlayerState(params[0]) != 1) 
		return SendErr(playerid,"Игрок не должен находиться в автомобиле");


	for(new i; i < 13; i++)
	{
		if(ACInfo[playerid][acWeapon][i] == 14)
		{
			ACInfo[playerid][acAmmo][i] = 0;
			ACInfo[playerid][acWeapon][i] = 0;
			ResetPlayerWeaponsEx(playerid);
			GivePlayerWeaponEx(params[0],14,1);

		}
	}


	new mes[128];
	format(mes,sizeof(mes),"подарил(а) цветы %s",pData[params[0]][pNickname]);
	MeAction(playerid,mes);
	ApplyAnimation(playerid,"DEALER","Dealer_Deal",4.1,0,0,0,0,0,1);
	format(mes,128,"Вы подарили цветы %s", pData[params[0]][pNickname]); SendSucc(playerid, mes);
	format(mes,128,"%s подарил(а) Вам цветы", pData[playerid][pNickname]); SendSucc(params[0], mes);


	return true;
}

CMD:uninvite(playerid, params[])
{
	if(!pData[playerid][pFraction]) return SendClientMessage(playerid,CGRAY,"Вы не состоите в организации.");
	if(pData[playerid][pAdmin] > 3 && pData[playerid][pAdmin] < 7 ) return SendClientMessage(playerid,CGRAY,"Команда недоступна");

	if(!IsAbleToUninvite(playerid)) return SendClientMessage(playerid,CGRAY,"Ваш ранг недостаточен");

	if(sscanf(params, "ds[64]", params[0], params[1])) 
		return SendInf(playerid, "/uninvite [ID] [Причина]");


	new actplayerid = params[0];

	if(!IsPlayerConnected(actplayerid) || actplayerid == playerid) 
		return SendClientMessage(playerid,CGRAY,"Неверный ID игрока");

	if(pData[actplayerid][pFraction] != pData[playerid][pFraction]) 
		return SendClientMessage(playerid,CGRAY,"Игрок не состоит в вашей организации");


	if(pData[playerid][pSubfraction] > 0)
	{
		if(pData[actplayerid][pSubfraction] != pData[playerid][pSubfraction]) return SendClientMessage(playerid,CGRAY,"Игрок не состоит в вашей подфракции");
	}
	if(pData[actplayerid][pRank] >= pData[playerid][pRank]) return SendClientMessage(playerid,CGRAY,"Ваш ранг недостаточен");
	new query[200];
	format(query,sizeof(query),"UPDATE `accounts` SET `fraction` = '0', `rank` = '0',`dvs` = '0', `fractionskin` = '0', `subfraction` = '0', `fwarn` = '0' WHERE `id` = '%d'",pData[actplayerid][pMysqlID]);
	sql_queryEx(zConn, query, QUERY_THREADED);
    SetPlayerArmourEx(actplayerid, 0);
	ResetPlayerWeaponsEx(actplayerid);
	pData[actplayerid][pFraction] = 0;
	pData[actplayerid][pRank] = 0;
	pData[actplayerid][pDivision] = 0;
	pData[actplayerid][pFractionSkin] = 0;
	pData[actplayerid][pSubfraction] = 0;
	pTemp[actplayerid][pDChat] = 0;
	pData[actplayerid][pFWarn] = 0;
	UpdatePlayerData(actplayerid, "fwarn", pData[actplayerid][pFWarn]);

	ResetPlayerWeaponsEx(actplayerid);
	SetPlayerColor(actplayerid,0xFFFFFF11);

	SetPlayerSkin(actplayerid,pData[actplayerid][pSkin]);
	format(query,sizeof(query),"%s уволил Вас из организации. Причина: %s",pData[playerid][pNickname], params[1]);
	SendClientMessage(actplayerid,CBADINFO,query);
	format(query,sizeof(query),"%s был уволен из организации. Причина: %s",pData[actplayerid][pNickname], params[1]);
	SendClientMessage(playerid,CINFO,query);
	format(String256,sizeof(String256),"%s уволил %s из организации. Причина: %s",pData[playerid][pNickname],pData[actplayerid][pNickname], params[1]);
	SendFMes(pData[playerid][pFraction],CBLUE, String256);

	return true;

}
 
CMD:unfwarn(playerid, params[])
{
	if(!pData[playerid][pFraction]) return SendInf(playerid, "Вы не состоите в организации.");
	if(IsACop(playerid) || pData[playerid][pFraction] < 3 || (pData[playerid][pFraction] >=8 && pData[playerid][pFraction] <= 12))
	{}
	else
	{
	return SendInf(playerid, "Команда доступна только гос. организациям");
	}

	if(sscanf(params, "ds[64]", params[0], params[1])) 
		return SendInf(playerid, "/unfwarn [ID] [Причина]");


	if(pData[playerid][pFraction] == 11 && !pData[playerid][pSubfraction]) {
	if(pData[playerid][pRank] < 8) { return SendInf(playerid, "Ваш ранг недостаточен"); }
	}
	else {
	if(!IsAbleToUninvite(playerid)) return SendInf(playerid, "Ваш ранг недостаточен");
	}

	new actplayerid =  params[0];


	if(!IsPlayerConnected(actplayerid) || actplayerid == playerid) return SendInf(playerid, "Неверный ID игрока");
	if(pData[actplayerid][pFraction] != pData[playerid][pFraction]) return SendInf(playerid, "Игрок не состоит в вашей организации");
	if(pData[playerid][pSubfraction] > 0)
	{
		if(pData[actplayerid][pSubfraction] != pData[playerid][pSubfraction]) return SendInf(playerid, "Игрок не состоит в вашей подфракции");
	}
	if(pData[actplayerid][pRank] >= pData[playerid][pRank]) return SendInf(playerid, "Ваш ранг недостаточен");
	if( pData[actplayerid][pFWarn] < 1) return SendInf(playerid, "У игрока нет выговоров");
    pData[actplayerid][pFWarn] --;

	format(String256, sizeof(String256), "%s снял вам выговор (%d/3). Причина: %s", pData[playerid][pNickname], pData[actplayerid][pFWarn],params[1]);
	SCM(actplayerid, COLOR_LIGHTRED, String256);
	format(String256, sizeof(String256), "Вы сняли с %s выговор (%d/3). Причина: %s", pData[actplayerid][pNickname], pData[actplayerid][pFWarn],  params[1]);
	SCM(playerid, COLOR_LIGHTRED, String256);
	UpdatePlayerData(actplayerid, "fwarn", pData[actplayerid][pFWarn]);

	return true;
}

CMD:rang(playerid, params[])
{
	if(!pData[playerid][pFraction]) return SendInf(playerid, "Вы не состоите в организации.");
	if(pData[playerid][pAdmin] > 3 && pData[playerid][pAdmin] < 7) return SendInf(playerid, "Команда недоступна");

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/rang [ID]");

	new fractionid = pData[playerid][pFraction]-1;
	if(!IsAbleToGiveRank(playerid)) return SendInf(playerid, "Ваш ранг недостаточен");

	new actplayerid = params[0];
	if(!IsPlayerConnected(actplayerid) || actplayerid == playerid) return SendInf(playerid, "Неверный ID игрока");
	if(pData[actplayerid][pFraction] != pData[playerid][pFraction] || pData[actplayerid][pSubfraction] != pData[playerid][pSubfraction]) return SendInf(playerid, "Игрок не состоит в вашей организации");
	if(pData[playerid][pSubfraction] > 0)
	{
		if(pData[actplayerid][pSubfraction] != pData[playerid][pSubfraction]) return SendInf(playerid, "Игрок не состоит в вашей подфракции");
	}
	if(pData[actplayerid][pRank] >= pData[playerid][pRank]) return SendInf(playerid, "Ваш ранг недостаточен");
	if(GetPlayerDistanceToPlayer(playerid,actplayerid) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(actplayerid)) return SendInf(playerid, "Вы далеко друг от друга");
	SetPVarIntNew(playerid,"actgrplayerid",actplayerid+1);
	new mes[400];
	new m = pData[playerid][pRank]-1;
	if(pData[playerid][pFraction] == 11 && !pData[playerid][pSubfraction]) m = 9;
	if(pData[playerid][pFraction] == 11 && !pData[playerid][pSubfraction] && pData[playerid][pRank] == 9) m = 8;
	for(new i = 0;i<m;i++)
	{
		if(pData[actplayerid][pRank] == i+1)
		{
		    if(pData[actplayerid][pFraction] == 11 && !pData[actplayerid][pSubfraction])
				format(mes,sizeof(mes),"%s"cGR"%s\n",mes,gPrezRankName[i]);
			else if(pData[actplayerid][pFraction] == 8 && pData[actplayerid][pSubfraction] == 3)
				format(mes,sizeof(mes),"%s"cGR"%s\n",mes,gVmfRankName[i]);
			else format(mes,sizeof(mes),"%s"cGR"%s\n",mes,gFractionRankName[fractionid][i]);
		}
		else
		{
			if(pData[actplayerid][pFraction] == 11 && !pData[actplayerid][pSubfraction])
				format(mes,sizeof(mes),"%s%s\n",mes,gPrezRankName[i]);
			else if(pData[actplayerid][pFraction] == 8 && pData[actplayerid][pSubfraction] == 3)
				format(mes,sizeof(mes),"%s%s\n",mes,gVmfRankName[i]);
			else format(mes,sizeof(mes),"%s%s\n",mes,gFractionRankName[fractionid][i]);
		}
	}
	SPD(playerid,dSetRank,2,"{FFFF7A}Смена ранга",mes,"Сменить","Выход");
    return true;
}

CMD:division(playerid, params[])
{
	if(pData[playerid][pRank] < 9) return SendInf(playerid, "Данная команда вам не доступна");

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/division [ID]");

	new actplayerid = params[0];
	if(!IsPlayerConnected(actplayerid)) return SendInf(playerid, "Неверный ID игрока");
	if(pData[actplayerid][pFraction] != pData[playerid][pFraction] || (pData[actplayerid][pSubfraction] != pData[playerid][pSubfraction] && pData[playerid][pSubfraction] != 0)) return SendInf(playerid, "Игрок не состоит в вашей организации");
	SetPVarIntNew(playerid,"actgrplayerid",actplayerid+1);
	new mes[400];
	new m = sizeof(Division);
	format(mes,sizeof(mes),"{6700C7}%d."cWH" Отсутствие подразделения\n",1);
	for(new i = 0;i<m;i++)
	{
	    if(i == 4) {
			format(mes,sizeof(mes),"%s{6700C7}%d."cWH" %s",mes,i+2,Division[i]);
		}
		else {
			format(mes,sizeof(mes),"%s{6700C7}%d."cWH" %s\n",mes,i+2,Division[i]);
		}
	}
	SPD(playerid,dSetDivision , 2 ,"{FFFF7A}Смена подразделения",mes,"Сменить","Выход");
    return true;
}

CMD:fwarnoff(playerid, params[])
{
	if(!pData[playerid][pFraction]) return SendInf(playerid, "Вы не состоите в организации.");
	if(IsACop(playerid) || pData[playerid][pFraction] < 3 || (pData[playerid][pFraction] >=8 && pData[playerid][pFraction] <= 12))
	{}
	else
	{
	return SendInf(playerid, "Команда доступна только гос. организациям");
	}

	if(sscanf(params, "s[32]s[64]", params[0],params[1])) 
		return SendInf(playerid, "/division /fwarnoff [ Ник ] [Причина]");

    if(pData[playerid][pFraction] == 11 && !pData[playerid][pSubfraction]) {
	if(pData[playerid][pRank] < 9) { return SendInf(playerid, "Ваш ранг недостаточен"); }
	}
	else {
	if(!IsAbleToUninvite(playerid)) return SendInf(playerid, "Ваш ранг недостаточен");
	}


	sql_escape_string(zConn, params[0], params[0], 128);
	if(GetPlayerID(params[0]) != -1) return SendErr(playerid, "Игрок с данным именем находится на сервере. Выдать выговор не удалось");

//			new query[512];
	format(String512,sizeof(String512),"SELECT `id`,`fraction`,`rank`,`fwarn`,`subfraction` FROM `accounts` WHERE `nickname` = '%s'",params[0]);
	new Result:r = sql_queryEx(zConn, String512, QUERY_CACHED);
	if(!sql_num_rows(r)) {
	sql_free_result(r);
	return SendInf(playerid, "Неверный Ник");}

	new SIDS = sql_get_field_int(r, 0);
	new SFRAC = sql_get_field_int(r, 1);
	new SRANK = sql_get_field_int(r, 2);
	new SFWARN = sql_get_field_int(r, 3);
	new SSUBFRAC = sql_get_field_int(r, 4);
	sql_free_result(r);

	new reason[64];
	format(reason,64, params[1]);
	if(!strlen(reason) || strlen(reason) > 62) return SendInf(playerid, "/fwarnoff [Ник игрока] [Причина]");

	if(SFRAC != pData[playerid][pFraction]) return SendInf(playerid, "Игрок не состоит в вашей организации");
	if(pData[playerid][pSubfraction] > 0)
	{
		if(SSUBFRAC != pData[playerid][pSubfraction]) return SendInf(playerid, "Игрок не состоит в вашей подфракции");
	}
	if(SRANK >= pData[playerid][pRank])
	{
		return SendInf(playerid, "Ваш ранг недостаточен");
	}
	
	format(String256, sizeof(String256), "%s получил оффлайн выговор (%d/3). Причина: %s",  params[0] , SFWARN + 1 ,  reason);
	SCM(playerid, COLOR_LIGHTRED, String256);
	SFWARN ++;
	format(String256, sizeof(String256), "%s получил оффлайн выговор (%d/3) от %s. Причина: %s", params[0], SFWARN, pData[playerid][pNickname], reason);
	SendFMes(pData[playerid][pFraction],CBLUE, String256);
	format(String256,sizeof(String256),"UPDATE `accounts` SET `fwarn` = '%d' WHERE `id` = '%d'",SFWARN, SIDS);
	sql_queryEx(zConn, String256, QUERY_THREADED);

	if(SFWARN >= 3)
	{
	    new query[200];
		format(query,sizeof(query),"UPDATE `accounts` SET `fraction` = '0', `fwarn` = '0', `rank` = '0', `fractionskin` = '0', `subfraction` = '0' WHERE `id` = '%d'", SIDS);
		sql_queryEx(zConn, query, QUERY_THREADED);
		format(query,sizeof(query),"%s был уволен из организации. Причина: %s", params[0], reason);
		SCM(playerid,CINFO,query);

	}

	return true;
}

CMD:takelic(playerid, params[])
{
    if(!IsACop(playerid) || pData[playerid][pRank] < 6) return SendInf(playerid, "Эта функция только для МВД/ФСБ с 6 ранга");
   
	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/takelic [ID игрока][Причина]");

	new actplayerid = params[0];

	if(!IsPlayerConnected(actplayerid) || actplayerid == playerid || (IsACop(actplayerid) && pData[actplayerid][pRank] >= pData[playerid][pRank])) return SendErr(playerid,"Неверный ID игрока или нет полномочий");
	if(GetPlayerDistanceToPlayer(playerid,actplayerid) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(actplayerid)) return SendErr(playerid,"Вы далеко друг от друга");
	if(!pData[actplayerid][pLicenses][LIC_DRIVING]) return SendErr(playerid, "У игрока нет лицензии");
	

	new mes[144];
	format(mes,sizeof(mes),"UPDATE `accounts` SET `licDrive` = '0' WHERE `id` = '%d'",pData[actplayerid][pMysqlID]);
	sql_queryEx(zConn, mes, QUERY_THREADED);
	pData[actplayerid][pLicenses][LIC_DRIVING] = 0;
	format(mes,sizeof(mes),"%s забрал у Вас лицензию на вождение. Причина: %s",pData[playerid][pNickname],  params[0]);
	SCM(actplayerid,CBADINFO,mes);
	format(mes,sizeof(mes),"%s был лишён лицензии на вождение. Причина: %s",pData[actplayerid][pNickname],  params[0]);
	SCM(playerid,CINFO,mes);
	format(mes, sizeof(mes), "%s %s[%d] забрал лицензию на вождение у %s. Причина: %s", gFractionRankName[pData[playerid][pFraction]-1][pData[playerid][pRank]-1], pData[playerid][pNickname], playerid, pData[actplayerid][pNickname], params[0]);
	SendFMes(pData[playerid][pFraction],CBLUE, mes);


	return true;
}

CMD:fwarn(playerid, params[])
{
	if(!pData[playerid][pFraction]) return SendInf(playerid, "Вы не состоите в организации.");

	if(sscanf(params, "ds[64]", params[0], params[1])) 
		return SendInf(playerid, "/fwarn [ID] [Причина]");


	if(IsACop(playerid) || pData[playerid][pFraction] < 3 || (pData[playerid][pFraction] >=8 && pData[playerid][pFraction] <= 12))
	{}
	else
	{
	return SendInf(playerid, "Команда доступна только гос. организациям");
	}
//		new fractionid = pData[playerid][pFraction]-1;
    if(pData[playerid][pFraction] == 11 && !pData[playerid][pSubfraction]) {
	if(pData[playerid][pRank] < 9) { return SendInf(playerid, "Ваш ранг недостаточен"); }
	}
	else {
	if(!IsAbleToUninvite(playerid)) return SendInf(playerid, "Ваш ранг недостаточен");
	}

	new actplayerid = params[0];

	if(!IsPlayerConnected(actplayerid) || actplayerid == playerid) return SendInf(playerid, "Неверный ID игрока");

	if(pData[actplayerid][pFraction] != pData[playerid][pFraction]) return SendInf(playerid, "Игрок не состоит в вашей организации");
	if(pData[playerid][pSubfraction] > 0)
	{
		if(pData[actplayerid][pSubfraction] != pData[playerid][pSubfraction]) return SendInf(playerid, "Игрок не состоит в вашей подфракции");
	}
	if(pData[actplayerid][pRank] >= pData[playerid][pRank])
	{
		return SendInf(playerid, "Ваш ранг недостаточен");
	}
    pData[actplayerid][pFWarn] ++;

	format(String256, sizeof(String256), "%s выдал вам выговор (%d/3). Причина: %s", pData[playerid][pNickname], pData[actplayerid][pFWarn],params[1]);
	SCM(actplayerid, COLOR_LIGHTRED, String256);
	format(String256, sizeof(String256), "%s получил выговор (%d/3). Причина: %s", pData[actplayerid][pNickname], pData[actplayerid][pFWarn],  params[1]);
	SCM(playerid, COLOR_LIGHTRED, String256);
	UpdatePlayerData(actplayerid, "fwarn", pData[actplayerid][pFWarn]);

	format(String256, sizeof(String256), "%s получил выговор (%d/3) от %s. Причина: %s", pData[actplayerid][pNickname], pData[actplayerid][pFWarn], pData[playerid][pNickname], params[1]);
	SendFMes(pData[playerid][pFraction],CBLUE, String256);

	if(pData[actplayerid][pFWarn] >= 3)
	{
	new query[255];
	format(query,sizeof(query),"UPDATE `accounts` SET `fraction` = '0', `fwarn` = '0', `rank` = '0', `dvs` = '0', `fractionskin` = '0', `subfraction` = '0' WHERE `id` = '%d'",pData[actplayerid][pMysqlID]);
	sql_queryEx(zConn, query, QUERY_THREADED);
    SetPlayerArmourEx(actplayerid, 0);
	ResetPlayerWeaponsEx(actplayerid);
	pData[actplayerid][pFraction] = 0;
	pData[actplayerid][pRank] = 0;
	pData[actplayerid][pDivision] = 0;
	pData[actplayerid][pFractionSkin] = 0;
	pData[actplayerid][pSubfraction] = 0;
	pData[actplayerid][pFWarn] = 0;
	ResetPlayerWeaponsEx(actplayerid);
	SetPlayerColor(actplayerid,0xFFFFFF11);

	SetPlayerSkin(actplayerid,pData[actplayerid][pSkin]);
	format(query,sizeof(query),"%s уволил Вас из организации. Причина: %s",pData[playerid][pNickname], params[1]);
	SCM(actplayerid,CBADINFO,query);
	format(query,sizeof(query),"%s был уволен из организации. Причина: %s",pData[actplayerid][pNickname], params[1]);
	SCM(playerid,CINFO,query);
	}

	return true;

}

CMD:invite(playerid, params[])
{
	if(!pData[playerid][pFraction]) return SendInf(playerid, "Вы не состоите в организации");
	if(pData[playerid][pAdmin] > 3 && pData[playerid][pAdmin] < 7) return SendInf(playerid, "Команда недоступна");

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/invite [ID]");

	new fractionid = pData[playerid][pFraction]-1;
	if(pData[playerid][pRank] < 9) return SendInf(playerid, "Ваш ранг недостаточен");

	new actplayerid = params[0];

	if(actplayerid < 0 || actplayerid > 999) return SendInf(playerid, "Неверный ID игрока");
	if(pData[actplayerid][pAdmin] && pData[actplayerid][pAdmin] < 8) return SendErr(playerid, "Вы не можете принять во фракцию Администратора");
	if(fractionid >= 3 && fractionid <= 7)
	{
		if(pData[actplayerid][pLevel] < 2 ) return SendInf(playerid, "У игрока должен быть 2 уровень");
	}
	else
	{
		if(pData[actplayerid][pLevel] < 3) return SendInf(playerid, "У игрока должен быть 3 уровень");
	}
	if(!IsPlayerConnected(actplayerid)) return SendInf(playerid, "Неверный ID игрока");
	else if(pData[actplayerid][pFraction]) return SendInf(playerid, "Игрок уже состоит в организации");
	if(pData[actplayerid][pWarnc]) return SendInf(playerid, "У игрока есть варн");
	if(fractionid > 1 && fractionid < 7)
	{
		if(pData[actplayerid][pBlackList][fractionid-2] != 0) return SendInf(playerid, "Игрок состоит в черном списке");
	}
	else 
	{
		if(pData[actplayerid][pBlackListNew][fractionid] != 0) return SendInf(playerid, "Игрок состоит в черном списке");
	}

	if(pTemp[actplayerid][pCasino])	return SendInf(playerid, "В данный момент игрок не может вступить в организацию");
	if(GetPlayerDistanceToPlayer(playerid,actplayerid) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(actplayerid)) return SendInf(playerid, "Вы далеко друг от друга");
	new mes[128];
	format(mes,sizeof(mes),"Вы предложили %s вступить в вашу фракцию",pData[actplayerid][pNickname]);
	SCM(playerid,CBLUE,mes);
	format(mes,sizeof(mes),"%s предложил Вам вступить во фракцию \"%s\"",pData[playerid][pNickname],gFractionName[fractionid]);
	pTemp[actplayerid][pOfferFraction] = playerid;
	pTemp[actplayerid][pOfferFractionid] = fractionid;
	SetPVarIntNew(playerid,"actinplayerid",actplayerid+1);
	SPD(actplayerid,dInvite,0,"{FFFF7A}Вступление во фракцию",mes,"Вступить","Отмена");

	return true;
}

cmd:hi(playerid, params[])
{

    if(IsPlayerConnected(playerid))
    {


 		if(sscanf(params, "d", params[0])) 
			return SendInf(playerid, "/hi [ID]");
   	

	    new actplayerid = params[0];
	    if(actplayerid == playerid) return SCM(playerid,CRED,"Вы не можете пожать руку самому себе");

	    if(IsPlayerConnected(actplayerid))
	    {
	        if(actplayerid != INVALID_PLAYER_ID)
	        {
		        if(GetPVarIntNew(actplayerid,"perenos") > 0 || GetPVarIntNew(actplayerid,"woodamount") > 0 || GetPVarIntNew(actplayerid,"gunamount") == 2) 
		        	return SCM(playerid, COLOR_GREY, "В данный момент команда не доступна");

		     	if (GetPlayerDistanceToPlayer(playerid,actplayerid) < 2.0 && GetPlayerState(playerid) == 1 && GetPlayerState(actplayerid) == 1)
		      	{
					if(pTemp[actplayerid][pShowHipl] == playerid) return SCM(playerid,CRED,"Вы уже предложили этому игроку пожать руку");
					if(GetPlayerDistanceToPlayer(playerid,actplayerid) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(actplayerid)) return SendInf(playerid, "Вы далеко друг от друга");
					new mes[255];
					SetPVarIntNew(playerid, "SimTime", GetTickCount()+ 1000*60*2);

					format(mes,sizeof(mes),"Вы предложили "cWH"%s {"#cINFO"}пожать руку",pData[actplayerid][pNickname]);
					SCM(playerid,CINFO,mes);
					format(mes,sizeof(mes),"%s {"#cINFO"} предложил(а) пожать вам руку. Чтобы подтвердить нажмите "cGR"Y{"#cINFO"}, иначе "cGR"N",pData[playerid][pNickname]);
					SCM(actplayerid,CWHITE,mes);
					pTemp[actplayerid][pShowHipl] = playerid;
					pTemp[actplayerid][pShowHiact] = actplayerid;

					pTemp[actplayerid][pSellCarOffer] = INVALID_PLAYER_ID;
					pTemp[actplayerid][pSellCarOffee] = INVALID_PLAYER_ID;
					pTemp[actplayerid][pSellVertOffer] = INVALID_PLAYER_ID;
					pTemp[actplayerid][pSellVertOffee] = INVALID_PLAYER_ID;
					pTemp[actplayerid][pSellBoatOffer] = INVALID_PLAYER_ID;
					pTemp[actplayerid][pSellBoatOffee] = INVALID_PLAYER_ID;

					pTemp[actplayerid][pSellBusinessOffer] = INVALID_PLAYER_ID;
					pTemp[actplayerid][pSellBusinessOffee] = INVALID_PLAYER_ID;
					pTemp[actplayerid][pSellHouseOffer] = INVALID_PLAYER_ID;
					pTemp[actplayerid][pSellHouseOffee] = INVALID_PLAYER_ID;
					pTemp[actplayerid][pSellPhoneOffer] = INVALID_PLAYER_ID;
					pTemp[actplayerid][pSellPhoneNomer] = 0;
					pTemp[actplayerid][pSellPhoneNomerEx] = 0;
					pTemp[actplayerid][pSellPhoneOffee] = INVALID_PLAYER_ID;

					pTemp[actplayerid][pSellBiletOffer] = INVALID_PLAYER_ID;
					pTemp[actplayerid][pSellBiletOffee] = INVALID_PLAYER_ID;
					pTemp[actplayerid][pSellEggOffer] = INVALID_PLAYER_ID;
					pTemp[actplayerid][pSellEggOffee] = INVALID_PLAYER_ID;

					SetPVarIntNew(actplayerid,"drugoffee",-1);
					SetPVarIntNew(actplayerid,"drugoffer",-1);
					SetPVarIntNew(actplayerid,"drugprice",0);


			 		SetPVarIntNew(actplayerid,"gunoffee",-1);
					SetPVarIntNew(actplayerid,"gunoffer",-1);
					SetPVarIntNew(actplayerid,"gunprice",0);
			       	return true;
		      	}
		      	else
		      	{
		          SCM(playerid, COLOR_GREY, "Игрок далеко от Вас");
		          return true;
		      	}
		    }
    	}
    }
    else
    {
        SCM(playerid, COLOR_GREY, "Игрок не найден");
        return true;
    }

    return true;

}

alias:report("rep", "ask", "vopros", "кузщке", "мщзкщы");
CMD:report(playerid, params[])
{

	if(pData[playerid][pMut]) 
		return SendErr(playerid, "У вас бан чата. Используйте /mutetime чтобы узнать время бана.");

	if(GetPVarIntNew(playerid, "active_report"))
		return SendErr(playerid, "У Вас уже имеется заданный вопрос, ожидайте ответа от администрации");

	if(sscanf(params, "s[128]", params[0])) 
	{
		return show_report_dialog(playerid);
	}

	switch(type_report)
	{
		case 1:
		{
			return send_default_report(playerid, params[0]);
		}
		case 2:
		{
			return send_new_report(playerid, params[0]);
		}
	}

	return true;

}

CMD:mp(playerid)
{
	if(MPPLAYERS <= 0) return SendErr(playerid,"В данный момент не проводится мероприятие либо все места заняты");
	if(pData[playerid][pJail] > 0) return SendErr(playerid,"Команда не доступна в тюрьме");
	if(pTemp[playerid][pInCasino] > 0) return SendErr(playerid,"Команда не доступна в данной локации");
	if(pTemp[playerid][pTied] != 0) { return SendErr(playerid, "Вы связаны!"); }
	if(pTemp[playerid][pWantedSu] != 0) return SendErr(playerid,"За вами идет погоня");
	if(pTemp[playerid][pCuffee] == playerid) return SendInf(playerid, "Вы в наручниках");

	if(pTemp[playerid][pWork] == 2 || pTemp[playerid][pWork] == 3 || pTemp[playerid][pWork] == 4) return SCM(playerid,COLOR_WHITE,"Сначало закончите работу");

    MPPLAYERS --;
    SetPlayerPos(playerid, MPPOS[0], MPPOS[1] , MPPOS[2]);
    SetPlayerInterior(playerid, MPINT);
    SetPlayerVirtualWorld(playerid, MPWORLD);
	SendInf(playerid, "Вы были телепортированы на мероприятие");


	return true;
}

CMD:sms(playerid, params[])
{
	new 
		text_sms[128];

	if(sscanf(params, "ds[128]", params[0], text_sms)) 
		return SendInf(playerid, "/sms [Номер] [Сообщение]");

	if(!pData[playerid][pPhone]) 
		return SendClientMessage(playerid,CGRAY,"Ошибка: У Вас нет телефона. Вы можете купить его в Универмаге");
	if(!pTemp[playerid][pTPhone]) 
		return SendClientMessage(playerid,CGRAY,"Ошибка: Сначала нужно включить телефон");
	if(pData[playerid][pMut]) 
		return SendClientMessage(playerid,CGRAY,"Ошибка: У Вас бан чата. Используйте /mutetime чтобы узнать время бана.");
	if(pData[playerid][pJail] && pData[playerid][pPrison] > 3) 
		return SendClientMessage(playerid, CGRAY, "Ошибка: Вы в тюрьме.");
	if(pTemp[playerid][pCuffee] == playerid) 
		return SendClientMessage(playerid,CGRAY,"Вы в наручниках");

	new id = -1;

	new 
		number = params[0];

	if(!number) 
		return SendClientMessage(playerid,CGRAY,"Ошибка: Игрока с этим номером нет на сервере");

	foreach(Player, i)
	{
		if(!IsPlayerConnected(i)) 
			continue;
		if(pData[i][pPhone] == number) 
		{
			id = i; 
			break;
		}
	}
	

	if(pData[playerid][pPhoneMoney] < 5) 
		return SendClientMessage(playerid, CGRAY, "Ошибка: На счету недостаточно средств");


	if(id == playerid) 
		return SendClientMessage(playerid,CGRAY,"Ошибка: вы ввели свой номер");
	if(id == -1) 
		return SendClientMessage(playerid,CGRAY,"Ошибка: Игрока с этим номером нет на сервере");
	if(!pData[id][pPhone]) 
		return SendClientMessage(playerid,CGRAY,"Ошибка: У игрока нет телефона");
	if(!pTemp[id][pTPhone]) 
		return SendClientMessage(playerid,CGRAY,"Ошибка: У игрока выключен телефон");
	if(pData[id][pJail] && pData[id][pPrison] > 3) 
		return SendClientMessage(playerid, CGRAY, "Ошибка: Игрок в тюрьме.");

	new mes[300];
	format(mes,sizeof(mes),"{FFA500}SMS: {FFFF00}%s {FFA500}| {FFFF00}Получатель: %s (тел. %d)",text_sms, pData[id][pNickname],pData[id][pPhone]);
	SendClientMessage(playerid,CYELLOW,mes);
	format(mes,sizeof(mes),"{FF8C00}SMS: {FFFF00}%s {FF8C00}| {FFFF00}Отправитель: %s (тел. %d)",text_sms, pData[playerid][pNickname], pData[playerid][pPhone]);
	SendClientMessage(id,CYELLOW,mes);
	format(mes,sizeof(mes),"{FF8C00}ASMS:{FFFF00}%s|Отправитель:%s(%d) Получатель:%s(%d)",text_sms, pData[playerid][pNickname], pData[playerid][pPhone],pData[id][pNickname],pData[id][pPhone]);


	if(pData[playerid][pSex] == 2) 
	{
		SetPlayerChatBubble(playerid, "Отправила СМС", CPINK, 10.0, 3000);
	}
	else
	{
		SetPlayerChatBubble(playerid, "Отправил СМС", CPINK, 10.0, 3000);
	}
	pData[playerid][pPhoneMoney] -= 5;
	PlayerPlaySound(playerid,1054,0.0,0.0,0.0);
	PlayerPlaySound(id,1054,0.0,0.0,0.0);

	return true;

}

CMD:stopmp(playerid)
{

    if(pData[playerid][pAdmin] >= 5)															    
    {
        if(MPPLAYERS  == 0)
        {
			return SendErr(playerid,"Телепорт на МП закончен или не начинался");
		}
        MPPLAYERS = 0;
        format(String256, sizeof(String256), "Администратор %s остановил телепорт на МП",pData[playerid][pNickname]);
        AdminChat(0x007fffff,String256);

    }

    return true;

}

CMD:phonebook(playerid)
{

	if(!get_inventory_items(playerid, 7))
		return SendErr(playerid, "У вас нет телефонной книги. Её можно купить в Универмаге");

	new wwan;
	new test[120];
	new testname[32];
	format(String2048,sizeof(String2048),"{FFD966}\t\t\tДобавить\n");
	for(new i = 0; i < 20; i ++)
	{
			wwan ++;
			format(String64,sizeof(String64), "pbook_%d",i);
			new numb = GetPVarIntNew(playerid, String64 );
			format(String64,sizeof(String64), "pbookn_%d",i);
		    GetPVarStringNew(playerid, String64 ,testname,32);

			if(numb < 1) test = "\t\t\t-\n";
			else {
			    new onnn = 0;
				foreach(Player, x)
				{
					if(pData[x][pPhone] == numb && pData[x][pAdmin] < 1) onnn = 1;
				}
				if(onnn == 1) {
					format(test,sizeof(test), "%s:\t{7598FF}%d\t{00CC44}[Online]"cWH"\n",testname,numb);
				}
				else {
					format(test,sizeof(test), "%s:\t{7598FF}%d\t{B5B5B5}[Offline]"cWH"\n",testname,numb);
				}
			}
			format(String2048, sizeof(String2048), "%s{FFDD75}%d. "cWH"%s",String2048,i+1,test);
    }

    SPD(playerid, dShowBook, 2 , "{FFDB94}Телефонная книга", String2048, "Удалить", "Закрыть");

    return true;
}


CMD:offobject(playerid)
{
    RemovePlayerAttachedObject(playerid,4);
    RemovePlayerAttachedObject(playerid,5);
    RemovePlayerAttachedObject(playerid,6);
    RemovePlayerAttachedObject(playerid,7);
    RemovePlayerAttachedObject(playerid,8);
    RemovePlayerAttachedObject(playerid,9);
    return SendSucc(playerid, "Вы сняли прикрепленные объекты");
}

CMD:take(playerid, params[])
{

    if(IsACop(playerid) && pData[playerid][pRank]) 
    {


		if(sscanf(params, "d", params[0])) 
			return SendInf(playerid, "/take [playerid]");
    	new
    		targetid = params[0], Float:x[3];

    	GetPlayerPos(targetid, x[0], x[1], x[2]);

    	if(GetPlayerDistanceFromPoint(playerid, x[0], x[1], x[2]) > 2.0) 
    	{
    	    SCM(playerid, COLOR_GREY, "Вы далеко от игрока!");
    	    return true;
    	}
    	if(pTemp[targetid][pCuffer] == INVALID_PLAYER_ID) 
    	{
			SendInf(playerid, "Игрок не в наручниках");
			return true;
		}
        SetPVarIntNew(playerid, "TakeOffer", targetid + 1);
        SPD(playerid, dCopTake, 2, "{FFD966}Что забрать", "{1F57FF}1. "cWH"Наркотики\n{1F57FF}2. "cWH"Оружие\n{1F57FF}3. "cWH"Патроны\n{1F57FF}4. "cWH"Единицы оружия", "Забрать", "Отмена");
	}
	else 
	{
		SCM(playerid, COLOR_GREY, "Вы не полицейский или ваш ранг слишком мал");
	}

	return true;

}

CMD:s(playerid, params[])
{

	if(sscanf(params, "s[32]", params[0])) 
		return SendInf(playerid, "/s [Текст]");


	if(pData[playerid][pBilet] == 101) 
		return SendInf(playerid, "У Вас пропал голос, вы не можете кричать");

	new mes[128];
	format(mes,sizeof(mes),"крикнул: %s",params[0]);
	if(strlen(params[0]) < 6) StopFlood[playerid]--;
	if(gettime() < StopFlood[playerid]) return SendClientMessage(playerid, CGRAY, "Не флудите"),true;
	StopFlood[playerid] = gettime()+CHAT_INTERVAL;
	if(strlen(FloodText[playerid]) > 5 && !strcmp(params[0], FloodText[playerid], true)) return SendClientMessage(playerid, CGRAY, "Сообщение слишком похоже на предыдущее"),true;
	format(FloodText[playerid], 128, params[0]);
	LoudSpeech(playerid,params[0],LANG_ENGLISH,13.0);
	if(IsPlayerInAnyVehicle(playerid) || pTemp[playerid][pWater] > 0) { }
	else ApplyAnimation(playerid,"ON_LOOKERS","shout_01",4.1,0,0,0,0,3000);

	return true;
}


CMD:usedrugs(playerid, params[])
{

	if(sscanf(params, "d", params[0])) 
	{
		SendInf(playerid, "/usedrugs [1-2]");
		return SendInf(playerid, "1 - Легкие наркотики | 2 - Тяжелые наркотики");
	}
	
	new id = params[0];


	if(!pData[playerid][pDrugs] && !pData[playerid][pHDrugs]) 
		return SendErr(playerid, "У Вас нет наркотиков");

	if(pTemp[playerid][AntiCrack]>=1)
		return SendErr(playerid, "Вы должны подождать перед следующим приемом наркотиков.");

	if(pTemp[playerid][pWater] != 0)
	{
		SendClientMessage(playerid,CRED,"Вы не можете использовать наркотики во время работы");
		return true;
	}
	if(pData[playerid][pHospital] != 0 && !IsPlayerInDynamicArea(playerid, hospital_area_heal) && pTemp[playerid][pWorld] != 0) {
		SendClientMessage(playerid,CRED,"Вы не можете использовать наркотики в больнице/тюрьме");
		return true;
	}
	if(pTemp[playerid][pCuffee] == playerid)
	{
		SendClientMessage(playerid,CRED,"Вы не можете использовать наркотики находясь в наручниках");
		return true;
	}

	new Float:PPOS[4];
	GetPlayerPos(playerid, PPOS[0], PPOS[1], PPOS[2]);

	if(PPOS[2] < -1.0) 
		return SendClientMessage(playerid,CRED,"Вы не можете использовать анимации в данный момент");


	if(id == 1)
	{
 		if(!pData[playerid][pDrugs]) return SendErr(playerid, "У Вас нет легких наркотиков");
        pTemp[playerid][AntiCrack] +=10;
        pTemp[playerid][PlayerStoned] += 1;

		if(pTemp[playerid][PlayerStoned] >= 2) GameTextForPlayer(playerid, "~w~‹‘~n~~p~Њ’•м‘", 4000, 1);
		GetPlayerHealth(playerid, pData[playerid][pHealth]);


		SetPlayerHealth(playerid,pData[playerid][pHealth]+10.0);
        MeAction(playerid,"употребил наркотики");
        ApplyAnimation(playerid,"SMOKING","M_smk_drag",4.1,0,0,0,0,0,1);
        SetPlayerDrunkLevel (playerid, 3900);
		pData[playerid][pDrugs]--;
		UpdatePlayerData(playerid, "drugs", pData[playerid][pDrugs]);
	}
	else if(id == 2)
	{
		if(Playernarko[playerid] > 0) return SendErr(playerid, "Вы уже использовали тяжелый наркотик");
 		if(pData[playerid][pHDrugs] < 10) return SendErr(playerid, "У Вас нет тяжелых наркотиков");
        pTemp[playerid][AntiCrack] +=10;
        pTemp[playerid][PlayerStoned] += 1;
		if(pTemp[playerid][PlayerStoned] >= 2) GameTextForPlayer(playerid, "~w~‹‘~n~~p~Њ’•м‘", 4000, 1);
        MeAction(playerid,"употребил наркотики");
		pData[playerid][pHDrugs]-=10;
		UpdatePlayerData(playerid, "hdrugs", pData[playerid][pHDrugs]);


	    new Float:health;
	    GetPlayerHealth(playerid, health);


	    SetPlayerWeather(playerid, 1+random(44));
   		ApplyAnimation(playerid,"SMOKING","M_smk_drag",4.1,0,0,0,0,0);
        SetPlayerTime(playerid,17,0); //noon
	    SetPlayerHealth(playerid, health+random(99));
		Playernarko[playerid] = 90+random(100);
	}
	else
	{
		SendInf(playerid, "/usedrugs [1-2]");
		SendInf(playerid, "1 - Легкие наркотики | 2 - Тяжелые наркотики");		
	}
	return true;
}

CMD:number(playerid, params[])
{

    if(!pData[playerid][pBook]) 
    	return SendErr(playerid, "У вас нет телефонной книги. Её можно купить в магазине 24/7");
    new
    	nickname[32];

	if(sscanf(params, "s[32]", nickname)) 
	{
		return SendInf(playerid, "/number [Полный никнейм]");
	}

	sql_escape_string(zConn, nickname,nickname,24);
	new query[256];	format(query,sizeof(query),"SELECT `phone`,`admin`,`online` FROM `accounts` WHERE `nickname` = '%s'",nickname);
	new Result:r = sql_queryEx(zConn, query, QUERY_CACHED);
	if(sql_num_rows(r))
	{
		new number = sql_get_field_int(r, 0);
		if(sql_get_field_int(r, 1) || !number) SendErr(playerid, "Номер данного абонента не удалось определить");
		else 
		{
			format(query, sizeof(query), "{33FF1F}Номер %s: {FF5500}%d", nickname, number);
			SendClientMessage(playerid, -1, query);
			if(!sql_get_field_int(r, 2)) SendClientMessage(playerid, COLOR_BLUE, "Телефон абонента вне зоны доступа");
			else SendClientMessage(playerid, COLOR_LIGHTGREEN, "Абонент доступен для звонка");
		}
		return sql_free_result(r);
	}
	else SendErr(playerid, "Данный абонент не найден в базе");
	sql_free_result(r);
	return true;
}

CMD:newleader(playerid, params[])
{
	if(!pData[playerid][pFraction]) 
		return SendInf(playerid, "Вы не состоите во фракции");

	if(pData[playerid][pAdmin] > 1 && pData[playerid][pAdmin] < 7)  
		return SendInf(playerid, "Вам не доступна данная команда");

	new 
		fractionid = pData[playerid][pFraction] - 1;

	if(pData[playerid][pRank] < gFractionRankCount[fractionid]) 
		return SendInf(playerid, "Функция доступна только лидеру");

	new frid = GetSubfractionID(fractionid);

	if(pData[playerid][pSubfraction] > 0) 
		return SendInf(playerid, "Функция доступна только лидеру");
	if(pData[playerid][pFraction] == 12) 
		return SendInf(playerid, "В вашей фракции нет подфракций");

	if(frid == -1) 
		return SendInf(playerid, "В вашей фракции нет подфракций");


	if(sscanf(params, "d", params[0])) 
	{
		return SendInf(playerid, "/newleader [ID]");
	}


	new id = params[0];

	if(id == playerid && pData[playerid][pAdmin] < 8) 
		return SendInf(playerid, "Нельзя указывать свой ID");

	if(!IsPlayerConnected(id) || !pData[id][pMysqlID]) 
		return SendInf(playerid, "Неверный ID / игрок не зарегестрирован");

	if(GetPlayerDistanceToPlayer(playerid, id) > 10.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(id)) 
		return SendInf(playerid, "Вы далеко друг от друга");

	if(pData[id][pFraction] && pData[id][pFraction] != pData[playerid][pFraction]) 
		return SendInf(playerid, "Игрок уже состоит в организации");

	if(pData[id][pLevel] < 5) 
		return SendErr(playerid, "Игрок не достиг 5 уровня");

	if(pData[id][pZakon] < 0 && !IsAGang(id) && !IsAMafia(id))  
		return SendInf(playerid, "У игрока отрицательная законопослушность!");

	SetPVarIntNew(playerid,"actsubleader",id);
	new mes[128];
	strcat(mes,"Выберите подфракцию:");
	new subfr = 3;
	if(frid == 1) subfr= 2;
	for(new i = 0;i < subfr;i++)
	{
		if(strlen(gSubfractionName[frid][i]))
		{
			strcat(mes,"\n");
			strcat(mes,gSubfractionName[frid][i]);
		}
	}
	pTemp[id][pOfferFraction] = playerid;
	pTemp[id][pOfferFractionid] = fractionid;
	pTemp[playerid][pInviteLeader1] = id;
	return SPD(playerid,dSubleader,2,"{FFFF9E}Выберите подфракцию:",mes,"Назначить","Отмена");
}

CMD:gnews(playerid, params[])
{
	if(pData[playerid][pMut]) 
		return SendInf(playerid, "У Вас бан чата. Используйте /mutetime чтобы узнать время бана.");

	if(pTemp[playerid][pMutM])
	{
		SendInf(playerid, "У Вас затычка во рту.");
		return true;
	}

	if(sscanf(params, "s[64]", params[0])) 
	{
		return SendInf(playerid, "/gnews [Сообщение]");
	}


	if(pData[playerid][pAdmin] > 0 && pData[playerid][pAdmin] < 7) 
		return SendInf(playerid, "Функция не доступна.");

	if(!pData[playerid][pFraction])
		return SendInf(playerid, "Вы не состоите во фракции");
	if(pTemp[playerid][pNotReportG] > 10) 
		return SendInf(playerid, "Вы сможете использовать команду через 10 минут");

	new fraction = pData[playerid][pFraction];

	switch(fraction) 
	{
	    case 1, 2, 8, 9, 10, 11, 12: 
	    {
	        new rank = pData[playerid][pRank];
			if(fraction == 1 || fraction == 12) rank --;

	        if(rank < gFractionRankCount[fraction - 1] - 1) 
	        {
				return SendClientMessage(playerid, CBLUE,"Вам не доступна эта функция");
			}

			pTemp[playerid][pNotReportG] += 3;
			new mes[270];
			format(mes,sizeof(mes),"[Гос.Новости] %s [%d]: %s", pData[playerid][pNickname],playerid,params[0]);
			SendClientMessageToAll(0x4466ccff,mes);
	    }
	    default: 
	    {
	        return SendClientMessage(playerid, CBLUE,"Вам не доступна эта функция");
	    }
	}
	return true;
}

CMD:out(playerid, params[])
{
    if(pData[playerid][pFraction] != 11 || pData[playerid][pRank] < 2 || pData[playerid][pRank] > 3)
	{
	  return SendInf(playerid, "Эта функция только для охранников");
	}


	if(IsPlayerInDynamicArea(playerid, player_in_meria)) 
		return SendErr(playerid,"Команда доступна только в администрации президента и мэрии");


	if(sscanf(params, "d", params[0])) 
	{
		return SendInf(playerid, "/out [ID]");
	}


	new id = params[0];
	if(!IsPlayerConnected(id) || !pData[id][pMysqlID]) 
		return SendInf(playerid, "Неверный ID игрока");

	if(GetPlayerDistanceToPlayer(playerid,id) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(id)) 
		return SendInf(playerid, "Вы далеко друг от друга");

	if(pTemp[id][pTazer] < 1) 
		return SendInf(playerid, "Сначало оглушите нарушителя");

	foreach(Player, d)
	{
		if(	pTemp[d][pHolder] == playerid +1)
		{
			new mes[256];
			format(mes,sizeof(mes),"Вы уже ведете за собой игрока");
			SendClientMessage(playerid,CINFO,mes);
		}
	}
	SetPlayerSpecialAction(id, SPECIAL_ACTION_CUFFED);
	pTemp[id][pTazer] = 0;
	pTemp[id][pHolder] = playerid+1;
	MeAction(playerid,"повел нарушителя за собой");
	return true;	
}

CMD:unout(playerid, params[])
{
    if(pData[playerid][pFraction] != 11 || pData[playerid][pRank] < 2 || pData[playerid][pRank] > 3)
	{
	  return SendInf(playerid, "Эта функция только для охранников");
	}


	if(sscanf(params, "d", params[0])) 
	{
		return SendInf(playerid, "/unout [ID]");
	}


	new id = params[0];

	if(!IsPlayerConnected(id) || !pData[id][pMysqlID]) 
		return SendInf(playerid, "Неверный ID игрока");
	if(pTemp[id][pHolder] != playerid +1) 
		return SendInf(playerid, "Вы не ведете этого игрока за собой");

	pTemp[id][pHolder] = INVALID_PLAYER_ID;
	MeAction(playerid,"остановил нарушителя");
	ClearAnimations(id, 1);
 	ApplyAnimation(id,"ped","IDLE_chat",4.1,1,0,0,0,1,1);
    if(ControllableTimer[id] != -1) 	
    {
		KillTimer(ControllableTimer[id]);
		ControllableTimer[id] = - 1;		
	}
    TogglePlayerControllable(id, false);
    ControllableTimer[id] = SetTimerEx("ToggleControllable", 1000, false, "ii", id, 1);

	return true;
}

CMD:pursuit(playerid, params[])
{
	if(!IsACop(playerid)) return SendInf(playerid, "Эта функция только для МВД/ФСБ");
	if(pData[playerid][pRank] < 2) return SendInf(playerid, "Ваш ранг не достаточен для этого");



	if(sscanf(params, "d", params[0])) 
	{
		return SendInf(playerid, "/pursuit [ID]");
	}


	new id = params[0];

	if(!IsPlayerConnected(id) || !pData[id][pMysqlID]) 
		return SendInf(playerid, "Неверный ID игрока");

	if(pData[id][pWanted] < 2) 
		return SendErr(playerid, "Данный игрок не в розыске или уровень розыска меньше 2");

	if(GetPlayerDistanceToPlayer(playerid,id) > 30.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(id)) 
		return SendInf(playerid, "Вы далеко друг от друга");

	if(pTemp[id][pWantedSu] != 0) 
		return SendErr(playerid,"За этим игроком уже идет погоня");

	foreach(Player, d)
	{
		if(	pTemp[d][pWantedSu] == playerid +1)
		{
			new mes[260];
			format(mes,sizeof(mes),"Вы уже начали погоню");
			SendClientMessage(playerid,CINFO,mes);
		}
	}
	if(GetPlayerState(id) == 2 ||  GetPlayerState(id) == 3)
	{
		SetVehicleParamsForPlayer(GetPlayerVehicleID(id), playerid, 1, 0);
	}
	pTemp[id][pWantedSu] = playerid+1;
	SendClientMessage(id,0xFF0000FF,"За вами погоня! Если вы выйдите из игры, вас автоматически посадит в тюрьму!");
	SendClientMessage(playerid,0xFFCC00FF,"Вы начали погоню за преступником! Не упускайте его из виду!");
	return 1;
}

CMD:unmask(playerid, params[])
{
	if(!IsACop(playerid)) 
		return SendInf(playerid, "Эта функция только для МВД/ФСБ");

	if(sscanf(params, "d", params[0])) 
	{
		return SendInf(playerid, "/unmask [ID]");
	}

	new id = params[0];

	if(!IsPlayerConnected(id) || id == playerid) 
		return SendInf(playerid, "Неверный ID игрока");

	if(pData[id][pFraction] == 9 && pData[playerid][pFraction] != 12) 
		return SendInf(playerid, "Нельзя одеть наручники на законника");

	if(pData[id][pWanted] < 1) 
		return SendInf(playerid, "Игрок не в розыске");

	if(pTemp[id][pCuffee] != id) 
		return SendInf(playerid, "Игрок не в наручниках");

	if(!pData[id][pMasked]) 
		return SendClientMessage(playerid, COLOR_GREY, "Игрок не в маске");

	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER && GetPlayerVehicleID(playerid) != GetPlayerVehicleID(id)) 
		return SendErr(playerid, "Игрок находится в другой машине.");

	if(GetPlayerDistanceToPlayer(playerid,id) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(id)) 
		return SendInf(playerid, "Вы далеко друг от друга");


	if(!pData[id][pFraction]) SetPlayerColor(id,0xffffff25);
	if(pData[id][pFraction]) SetPlayerColor(id,gFractionColor[pData[id][pFraction] - 1]);
	if(pData[playerid][pSex] == 2) 
	{
		MeAction(playerid,"сняла маску с преступника");
	}
	else 
	{
		MeAction(playerid,"снял маску с преступника");
	}

	pData[id][pMasked] = 0;
    return 1;
}

CMD:cuff(playerid, params[])
{
	if(!IsACop(playerid)) return SendInf(playerid, "Эта функция только для МВД/ФСБ");

	if(sscanf(params, "d", params[0])) 
	{
		return SendInf(playerid, "/cuff [ID]");
	}

	new id = params[0];

	if(!IsPlayerConnected(id) || id == playerid) 
		return SendInf(playerid, "Неверный ID игрока");
	if(pData[id][pFraction] == 9 && pData[playerid][pFraction] != 12) 
		return SendInf(playerid, "Нельзя одеть наручники на законника");
	if(pTemp[id][pCuffee] == id) 
		return SendInf(playerid, "Игрок уже в наручниках");
	if(!pData[id][pWanted] && !pData[id][pJail]) 
		return SendErr(playerid, "Игрок не находится в розыске или тюрьме");
	if(pTemp[playerid][pCuffer] == playerid) 
		return SendInf(playerid, "У Вас с собой только одни наручники");
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER && GetPlayerVehicleID(playerid) != GetPlayerVehicleID(id)) 
		return SendErr(playerid, "Игрок находится в другой машине.");

	if(GetPlayerDistanceToPlayer(playerid,id) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(id)) 
		return SendInf(playerid, "Вы далеко друг от друга");

	if(pTemp[id][pTazer])
	{
		pTemp[id][pTazer] = 0;
		TogglePlayerControllable(id,1);
		SetPlayerSpecialAction(id,SPECIAL_ACTION_NONE);
	}
	SetPlayerSpecialAction(id, SPECIAL_ACTION_CUFFED);
    SetPlayerAttachedObject(id, 0, 19418, 6, -0.011000, 0.028000, -0.022000, -15.600012, -33.699977, -81.700035, 0.891999, 1.000000, 1.168000);
	pTemp[id][pCuffee] = id;
	pTemp[id][pCuffer] = playerid;
	if(pData[playerid][pSex] == 2) {
	if(pData[id][pJail] > 0) MeAction(playerid,"надела наручники на заключенного");
	else MeAction(playerid,"надела наручники на подозреваемого");
	}
	else {
	if(pData[id][pJail] > 0) MeAction(playerid,"надел наручники на заключенного");
	else MeAction(playerid,"надел наручники на подозреваемого");
	}
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER) TogglePlayerControllable(id,0);

	return true;

}

CMD:setmark(playerid, params[])
{
    if(!IsACop(playerid)) 
    	return SendErr(playerid, "Эта функция только для МВД/ФСБ");
	if(pTemp[playerid][Marked]) 
		return SendErr(playerid, "Вы уже запустили систему поиска преступника. Дождитесь её окончания.");

	if(sscanf(params, "d", params[0])) 
	{
		return SendInf(playerid, "/setmark [ID]");
	}


	if(!params[0])
	{
		if(pTemp[playerid][pGPS] && pTemp[playerid][MarkedEx] == true)
		{
			DisablePlayerCheckpoint(playerid);
			pTemp[playerid][pGPS] = false;
			SendClientMessage(playerid,CRED,"Метка "cWH"снята с радара");
			PLAYERPDELPER[playerid] = 0;
			pTemp[playerid][MarkedEx] = false;
		}
		return SendInf(playerid, "Введите /setmark [ID]");
	}

	if(pTemp[playerid][MarkedEx] == true && pTemp[playerid][pGPS])
	{
		pTemp[playerid][pGPS] = false;
		pTemp[playerid][MarkedEx] = false;
	}
	if(pTemp[playerid][pGPS]) return SendErr(playerid, "У Вас уже есть метка на радаре");

	new id = params[0];

	if(id < 0 || id > 999 || pData[id][pWanted] < 2) return SendErr(playerid, "Данный игрок не в розыске или уровень розыска меньше 2");
	SendSucc(playerid, "Система спутникового поиска преступника активирована. Ожидайте ответа от спутника.");
	pTemp[playerid][Marked] = true;
	SetTimerEx("SetMark", 1000*random(10)+1000,0,"dd",playerid,id);
	return 1;
}

CMD:skip(playerid, params[])
{
    if(pData[playerid][pFraction] == 12 && pData[playerid][pRank] >= 5)
    {
		if(sscanf(params, "d", params[0])) 
		{
			return SendInf(playerid, "/skip [ID]");
		}

		new id = params[0];
	    if(!IsPlayerConnected(id) || id == playerid) 
	    	return SendErr(playerid,"Неверный ID игрока");
		if(GetPlayerDistanceToPlayer(playerid,id) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(id)) 
			return SendInf(playerid, "Вы далеко друг от друга");

		pTemp[id][FBISkip] = 1;
		new str[64]; format(str, 64, "%s выдал Вам пропуск в здание ФСБ",pData[playerid][pNickname]);
		SendSucc(id, str);
  		format(str, 64, "Вы выдали пропуск в здание ФСБ %s",pData[id][pNickname]);
 		SendSucc(playerid, str);
	}
	else if(pData[playerid][pFraction] == 9 && pData[playerid][pRank] >= 5)
    {
		if(sscanf(params, "d", params[0])) 
		{
			return SendInf(playerid, "/skip [ID]");
		}

		new id = params[0];
	    if(!IsPlayerConnected(id) || id == playerid) 
	    	return SendErr(playerid,"Неверный ID игрока");
		if(GetPlayerDistanceToPlayer(playerid,id) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(id)) 
			return SendInf(playerid, "Вы далеко друг от друга");

		pTemp[id][PDSkip] = 1;
		new str[64]; format(str, 64, "%s выдал Вам пропуск в здание МВД",pData[playerid][pNickname]);
		SendSucc(id, str);
  		format(str, 64, "Вы выдали пропуск в здание МВД %s",pData[id][pNickname]);
 		SendSucc(playerid, str);
	}
	else 
	{
		SendErr(playerid, "Доступно только для сотрудников МВД и ФСБ с 5 ранга.");
	}
    return 1;
}

CMD:eject(playerid, params[])
{
	if(!IsPlayerInAnyVehicle(playerid)) 
		return SendClientMessage(playerid,CWHITE,"Вы должны быть в т.с.");
	if(GetPlayerVehicleSeat(playerid) != 0) 
		return SendInf(playerid, "Вы должны быть за рулем");
	if(GetPVarIntNew(playerid,"pushej") >  GetTickCount()) 
		return SendInf(playerid, "Пожалуйста, подождите");

	if(sscanf(params, "d", params[0])) 
	{
		return SendInf(playerid, "/eject [ID]");
	}

	new id = params[0];

	if(!IsPlayerConnected(id) || id == playerid) 
		return SendInf(playerid, "Неверный ID игрока");

	new vehicleid = GetPlayerVehicleID(playerid);

	if(vehicleid >= aBus[0] && vehicleid <= aBus[26])
	{
	    SendErr(playerid, "Вы не можете выкинуть из автобуса");
	    return 1;
	}

	if(vehicleid == GetPlayerVehicleID(id) && GetPlayerVehicleSeat(id) != 0)
	{
		SFCM(id,CGRAY,"%s вытолкнул вас из т.с.",pData[playerid][pNickname]);
		SFCM(playerid,CGRAY,"Вы вытолкнули %s из т.с.",pData[id][pNickname]);
		if(pTemp[id][pCuffee] == id) TogglePlayerControllable(id,1);
        if(pTemp[id][pTied] != 0) SetPlayerSpecialAction(id, SPECIAL_ACTION_CUFFED);
		RemovePlayerFromVehicle(id);
	}

	return true;
}

CMD:limit(playerid, params[])
{
	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) 
		return SendInf(playerid, "Вы должны быть за рулем");

	if(pTemp[playerid][pSpectating] == true)
	{
		return SendInf(playerid, "Вы должны быть за рулем");
	}

	if(sscanf(params, "d", params[0])) 
	{
		return SendInf(playerid, "/limit [Скорость]");
	}


	if(!params[0])
	{
		if(pTemp[playerid][pSLimit])
		{
			pTemp[playerid][pSLimit] = 0;
			SendInf(playerid, "Ограничение скорости снято");
		}
		else 
		{
			SendInf(playerid, "/limit [скорость]");
		}
		return 1;
	}
	new limit = params[0];
	if(limit < 10 || limit > 400) 
		return SendInf(playerid, "Ограничение должно быть от 10 до 400");

	pTemp[playerid][pSLimit] = limit;
	SendInf(playerid, "Установлено ограничение скорости");

	return true;
}


CMD:arrest(playerid, params[])
{
	if(!IsACop(playerid)) 
		return SendErr(playerid, "Эта функция только для МВД/ФСБ");

	if(sscanf(params, "d", params[0])) 
	{
		return SendInf(playerid, "/arrest [ID]");
	}

	new id = params[0];



	if(!IsPlayerConnected(id)) 
		return SendErr(playerid, "Неверный ID игрока");
	if(GetPlayerDistanceToPlayer(playerid,id) > 10.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(id)) 
		return SendErr(playerid, "Вы далеко друг от друга");
	if(!pData[id][pWanted])
		return SendErr(playerid, "Этот игрок не совершал преступление");
	if(pData[id][pJail]) 
		return SendErr(playerid, "Этот игрок уже находится в КПЗ");
	if(pData[id][pFraction] == 11 && !pData[playerid][pSubfraction] && pData[playerid][pRank] > 10)  
		return SendErr(playerid, "Вы не можете арестовать этого игрока");
	if(id == playerid)  
		return SendErr(playerid, "Вы не можете арестовать самого себя");

	new prison;
	if(!IsPlayerInDynamicArea(playerid,gAreas[arArrest][0]) &&
	!IsPlayerInDynamicArea(playerid,gAreas[arArrest][1]) &&
	!IsPlayerInDynamicArea(playerid,gAreas[arArrest][3]) &&
	!IsPlayerInDynamicArea(playerid,gAreas[arArrest][2])) return SendErr(playerid, "Вы должны быть рядом с участком");
	if(IsPlayerInDynamicArea(playerid,gAreas[arArrest][0])) { prison= 0;}
	else if(IsPlayerInDynamicArea(playerid,gAreas[arArrest][1])) { prison= 1;}
	else if(IsPlayerInDynamicArea(playerid,gAreas[arArrest][2])) { prison= 2;}
	else if(IsPlayerInDynamicArea(playerid,gAreas[arArrest][3])) { prison= 0;}

	if(pTemp[id][pCuffer] != INVALID_PLAYER_ID)
	{
		new cuffer = pTemp[id][pCuffer];
		SetPlayerSpecialAction(id,SPECIAL_ACTION_NONE);
		RemovePlayerAttachedObject(id,0);
		pTemp[id][pCuffer] = INVALID_PLAYER_ID;
		pTemp[id][pCuffee] = INVALID_PLAYER_ID;
		pTemp[cuffer][pCuffee] = INVALID_PLAYER_ID;
		pTemp[cuffer][pCuffer] = INVALID_PLAYER_ID;
	}

	new mes[128];
    if(GetPlayerMoneyEx(id) >=  pData[id][pWanted] * ArrestPay) 
    {
	    give_money(playerid ,pData[id][pWanted] * ArrestPay , "Премия за арест игрока");

		format(mes,sizeof(mes),"Вы получили премию {009900}%d рублей",pData[id][pWanted]* ArrestPay);
		SendClientMessage(playerid,CINFO,mes);
		GosMoney[1] -= pData[id][pWanted]* ArrestPay;
	    SaveNewsMoney();
    }
	new wantt = pData[id][pWanted];
    new time = pData[id][pWanted] * JAIL_QUATE/2;
	new camid = random(sizeof(CamCoords));

	SetPlayerPos(id, CamCoords[camid][0],CamCoords[camid][1],CamCoords[camid][2]);
	SetPlayerFacingAngle(id,359.4348);
	SetPlayerVirtualWorld(id,prison+1);
	SetPlayerSkin(id, 268);

	pData[id][pJail] = time;
	pData[id][pPrison] = prison;
	pData[id][pWanted] = 0;

	SetPlayerWantedLevel(id,0);
	SetPlayerInterior(id,0);

	ResetPlayerWeaponsEx(id);

	PSPAWN[id] = 1;

	SpawnPlayer(id);

	new 
		query[256];

	format(query,sizeof(query),"UPDATE `accounts` SET `jail` = '%d', prison = '%d', wanted = '0' WHERE `id` = '%d'",pData[id][pJail],pData[id][pPrison],pData[id][pMysqlID]);
	sql_queryEx(zConn, query, QUERY_THREADED);

	if(wantt < 3) 
	{
		format(mes,sizeof(mes),"Cотрудник МВД %s поместил Вас в КПЗ на %d минут",pData[playerid][pNickname],floatround(time/60));
	}
	else 
	{
		format(mes,sizeof(mes),"Cотрудник МВД %s поместил Вас в КПЗ",pData[playerid][pNickname]);
	}

	SendClientMessage(id,COLOR_LIGHTRED,mes);
	SendInf(id, "Чтобы посмотреть сколько Вам осталось сидеть в тюрьме, введите команду {FFFF10}/ptime");

	if(wantt < 3) 
	{
		format(mes,sizeof(mes),"Вы поместили %s в КПЗ на %d минут",pData[id][pNickname],floatround(time/60));
	}
	else 
	{
		format(mes,sizeof(mes),"Вы поместили %s в КПЗ",pData[id][pNickname]);
	}

	SendClientMessage(playerid,CINFO,mes);
	PlayerTimerWanted[id] = 0;

	if(PlayerTimerWantedEx[id] != 0) 
	{
		KillTimer(PlayerTimerWantedEx[id]);
		PlayerTimerWantedEx[id] = 0;
	}
	PlayerTimerWantedEx[id] = SetTimerEx("ShowWantedMenuEx", 140, 1, "dd", id,0);
	pData[id][pDrugs] = 0;
	UpdatePlayerData(id, "drugs", pData[id][pDrugs]);
	pData[id][pHDrugs] = 0;
	UpdatePlayerData(id, "hdrugs", pData[id][pHDrugs]);

	return true;
}

CMD:push(playerid, params[])
{
	if(IsACop(playerid)) 
	{
		if(sscanf(params, "d", params[0])) 
		{
			return SendInf(playerid, "/push [ID игрока]");
		}
		
		new id = params[0];
		if(!IsPlayerConnected(id) || id == playerid) 
			return SendClientMessage(playerid,CGRAY,"Неверный ID игрока");
		if(GetPlayerDistanceToPlayer(playerid,id) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(id)) 
			return SendClientMessage(playerid,CGRAY,"Вы далеко друг от друга");
		if(pData[id][pWanted] < 1 ) 
			return SendClientMessage(playerid,CGRAY,"Посадить в транспорт можно только преступника");
		if(GetPlayerState(id) == 3) 
			return SendClientMessage(playerid,CGRAY,"Игрок находится в автомобиле");
		if(pTemp[id][pCuffee] != id) 
			return SendClientMessage(playerid,CGRAY,"Игрок не в наручниках");


		new Float:x, Float:y, Float:z;
		GetPlayerPos(id,x,y,z);

		foreach(new v:vehicle_in_stream[playerid])
		{		
			new
				Float:pl_pos_x,
				Float:pl_pos_y,
				Float:pl_pos_z;

			GetPlayerPos(playerid, pl_pos_x, pl_pos_y, pl_pos_z);


			if(GetVehicleModel(v) == 528 || GetVehicleModel(v) == 533 || GetVehicleModel(v) == 552 || GetVehicleModel(v) == 596 || GetVehicleModel(v) == 597 || GetVehicleModel(v) == 598 || GetVehicleModel(v) == 427)
			{

				new Float:vx, Float:vy, Float:vz;
				GetVehiclePos(v,vx,vy,vz);
				if(GetDistanceXYZ(x,y,z,vx,vy,vz) <= 8.0)
				{
					new seat = GetFreeSeat(v, GetVehicleModel(v));
					if(seat == -1) continue;
					pTemp[id][pHolder] = INVALID_PLAYER_ID;
					PutPlayerInVehicle(id,v,seat);

					format(String64, sizeof(String64), "посадил подозреваемого %s в транспорт", pData[id][pNickname]);
					MeAction(playerid, String64);
					if(pTemp[id][pCuffee] == id) TogglePlayerControllable(id,0);
					SetPVarIntNew(playerid,"pushej", GetTickCount()+ 6000);

					return 1;
				}
			}
			else
			{
				SendErr(playerid, "Рядом с вами нет транспорта в который можно затолкнуть человека");
			}
		}
	}
	return true;
}

CMD:m(playerid, params[])
{
	if(!IsACop(playerid)) return SendErr(playerid,"Эта функция только для МВД/ФСБ");
	if(!IsPlayerInAnyVehicle(playerid)) return SendErr(playerid,"Вы должны быть в служебном т/с");
	if(pData[playerid][pMut]) return SendErr(playerid,"У Вас бан чата. Используйте /mutetime чтобы узнать время бана.");
	if(pTemp[playerid][pMutM])
	{
		SendErr(playerid,"У Вас затычка во рту.");
		return 1;
	}
	new 
		vehicleid = GetPlayerVehicleID(playerid);

	if(GetVehicleModel(vehicleid) == 528 || GetVehicleModel(vehicleid) == 533 || GetVehicleModel(vehicleid) == 552 || GetVehicleModel(vehicleid) == 596 || GetVehicleModel(vehicleid) == 597 || GetVehicleModel(vehicleid) == 598 || GetVehicleModel(vehicleid) == 427)
	{
		if(sscanf(params, "s[64]", params[0])) 
		{
			return SendInf(playerid, "/m [текст]");
		}
		

		new mes[128];
		format(mes,sizeof(mes),"<<< %s %s: %s >>>",gFractionRankName[pData[playerid][pFraction]-1][pData[playerid][pRank]-1], pData[playerid][pNickname], params[0]);

		new 
			pWorldX = GetPlayerVirtualWorld(playerid);

		foreach(new i: logged_players)
		{
			if(!PlayerConnect[i]) continue;

			if(!pTemp[i][pLogined] || !pData[i][pMysqlID] || pWorldX != GetPlayerVirtualWorld(i)) continue;
			new Float:rdist;
			rdist = GetPlayerDistanceToPlayer(playerid,i);
			if(rdist > 45.0) continue;
			SendClientMessage(i,CYELLOW,mes);
		}
	}
	else
	{
		SendErr(playerid, "Вы должны находиться в службеном транспорте!");
	}
	return true;
}

CMD:ad(playerid, params[])
{
	if(gAdvertCount >= MAX_ADVERT_COUNT) 
		return SendErr(playerid,"К сожалению, очередь на объявления занята, попробуйте позже");
	if(!pData[playerid][pPhone]) 
		return SendErr(playerid,"Вам нужен телефон, чтобы отправить объявление");
	if(pTemp[playerid][pAdvertTime]) 
		return SendErr(playerid,"Нельзя посылать чаще одного объявления в минуту");

	if(sscanf(params, "s[64]", params[0])) 
	{
		return SendInf(playerid, "/ad [текст]");
	}

	new len = strlen(params[0]);


	if(len > 100) 
		return SendErr(playerid,"Максимальная длина объявления - 100 символов");

	SetPVarStringNew(playerid,"advert",params[0]);


	new price = AdPay; // 200

	new 
		mes[128];
	format(mes,sizeof(mes),""cWH"Цена объявления: "cGR"%d рублей.\n"cWH"Вы действительно хотите отправить объявление?",price);
	return SPD(playerid,dAdvertSend,0,"{FFFF9E}Объявление",mes,"Да","Нет");
}

CMD:pay(playerid, params[])
{

	if(sscanf(params, "dd", params[0], params[1])) 
	{
		return SendInf(playerid, "/pay [ID] [Сумма]");
	}

	new 
		actplayerid = params[0];

	if(!IsPlayerConnected(actplayerid) || playerid == actplayerid) 
		return SendErr(playerid,"Неверный ID игрока");
	
	if(GetPlayerDistanceToPlayer(playerid,actplayerid) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(actplayerid) || pRealState[actplayerid] > 3) 
		return SendErr(playerid,"Вы далеко друг от друга");



	new 
		money = params[1];

	if(pData[playerid][pLevel] < 2) 
		return SendClientMessage(playerid,-1,"Данная команда доступна со 2 уровня");

	if(money < 1 || money > 5000) 
		return SendErr(playerid,"Можно передавать от 1 до 5000P");


	if(GetPlayerMoneyEx(playerid) < money) 
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:info_gui_no_money", 3000);
		return SendErr(playerid,"У Вас недостаточно денег");
	}
	if(GetPlayerMoneyEx(playerid) <= 0) 
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:info_gui_no_money", 3000);
		return SendErr(playerid,"У Вас недостаточно денег");
	}

	if(pTemp[playerid][pLastPay] > 1 && pData[playerid][pLevel] < 15 && (!pData[playerid][pFraction] || (pData[playerid][pFraction] > 0 && !IsALeader(playerid)) ) && !pData[playerid][pAdmin] && pData[playerid][pBikerRank] != 7) 
		return SendErr(playerid,"Деньги можно передавать не чаще 1 раза в минуту");
	
	if(GetPlayerState(playerid) == PLAYER_STATE_PASSENGER)
	{
		foreach(new i: logged_players)
		{

		}
	}

	give_money(playerid , -money, "Передача денег");
	give_money(actplayerid , money, "Передача денег");

	new mes[128];
	pTemp[playerid][pLastPay] = 60;
	format(mes,sizeof(mes),"%s {"#cINFO"}передал Вам "cGR"%d рублей",pData[playerid][pNickname],money);
	SendClientMessage(actplayerid,CWHITE,mes);
	format(mes,sizeof(mes),"Вы передали "cWH"%s "cGR"%d рублей",pData[actplayerid][pNickname],money);
	SendClientMessage(playerid,CINFO,mes);
	format(mes,sizeof(mes),"достал деньги и передал их %s",pData[actplayerid][pNickname]);
	MeAction(playerid,mes);


	return true;
}


CMD:free(playerid, params[])
{
	if(pData[playerid][pFraction] == 11 && pData[playerid][pRank] == 6 && pData[playerid][pSubfraction] != 0) 
	{
		if(pData[playerid][pJail]  > 0)
			return SendClientMessage(playerid, COLOR_WHITE, "Вы не можете выпускать людей находясь в тюрьме");

		if(sscanf(params, "d", params[0])) 
			return SendInf(playerid, "/free [ID]");

		new acter;
		acter = params[0];

		if(pData[acter][pJail]  < 1 || !IsPlayerConnected(acter))					
			return SendClientMessage(playerid, COLOR_WHITE, "Этот игрок не в тюрьме");	

		if(GetPlayerDistanceToPlayer(acter,playerid) > 5.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(acter))
			return SendErr(playerid,"Вы далеко друг от друга");
		
		if(pData[acter][pJail]  > 60*60)																	
			return SendClientMessage(playerid, COLOR_WHITE, "Этот игрок имеет слишком большой срок заключения");
		
		if(pData[acter][pPrison] == 5)
		{
			return SendClientMessage(playerid, COLOR_WHITE, "Этого игрока нельзя освободить");
		}

		if(acter == playerid)																
		{
			return SendClientMessage(playerid, COLOR_WHITE, "Вы не можете выпустить сам себя");	
		}

		format(String256,sizeof(String256),"Вы предложили "cWH"%s {"#cINFO"}освободиться из тюрьмы",pData[acter][pNickname]);
		SendClientMessage(playerid,CINFO,String256);
		format(String256,sizeof(String256),"%s {"#cINFO"}хочет выпустить вас из тюрьмы. Цена: {295EFF}P5000. {"#cINFO"}Чтобы подтвердить нажмите "cGR"Y{"#cINFO"}, иначе "cGR"N",pData[playerid][pNickname]);
		SendClientMessage(acter,CWHITE,String256);
		pTemp[acter][pAcceptFree] = playerid;
		pTemp[acter][pAcceptFreeact] = acter;


	}
	else
	{
		SendClientMessage(playerid, COLOR_WHITE, "Вы не адвокат");
	}
	return true;
}

CMD:dial(playerid, params[])
{
	if(pData[playerid][pFraction] != 10 || pData[playerid][pSubfraction] == 0) return SendErr(playerid,"Эта функция доступна только сотрудникам СМИ");
	if(!pTemp[playerid][pEther]) return SendErr(playerid,"Вы должны быть в эфире, чтобы начать принимать звонки");
	if(pData[playerid][pRank] < 5) return SendErr(playerid,"Принимать звонки можно с пятого ранга");
	if(gNewsDialing[pData[playerid][pSubfraction]-1] && gNewsDialer[pData[playerid][pSubfraction]-1] >= 0 && gNewsDialer[pData[playerid][pSubfraction]-1] < MAX_PLAYERS)
	{
		new mes[128];
		format(mes,sizeof(mes),"%s уже принимает звонки",pData[gNewsDialer[pData[playerid][pSubfraction]-1]][pNickname]);
		SendClientMessage(playerid,CGRAY,mes);
		return 1;
	}
	if(sscanf(params, "d", params[0])) 
	{
		return SendInf(playerid, "/dial [Стоимость]");
	}

	new price = params[0];

	if(price > 150) 
		return SendErr(playerid,"Цена за 1 звонок не может быть больше P150");

	new mes[128];
	format(mes,sizeof(mes),"[R] %s начал принимать звонки и СМС. Цена звонка: %d рублей.",pData[playerid][pNickname],price);
	for(new i=0; i< MAX_PLAYERS; i ++)
	{
	    if(!IsPlayerConnected(i)) continue;
		if(pData[i][pFraction] == 10) {
			SendClientMessage(i,CBLUE,mes);
			switch(pData[playerid][pSubfraction]-1) {
				case 0: SendClientMessage(i, CBLUE, "[R] Телефон студии: 9900 [Южный]");
				case 1: SendClientMessage(i, CBLUE, "[R] Телефон студии: 9901 [Эдово]");
				case 2: SendClientMessage(i, CBLUE, "[R] Телефон студии: 9902 [Арзамас]");
			}
		}
	}
	SendInf(playerid, "Чтобы закончить прием звонков введите команду /stopdial");
	gNewsDialing[pData[playerid][pSubfraction]-1] = true;
	gNewsDialer[pData[playerid][pSubfraction]-1] = playerid;
	gNewsDialee[pData[playerid][pSubfraction]-1] = INVALID_PLAYER_ID;
	gNewsDialPrice[pData[playerid][pSubfraction]-1] = price;

	return true;
}

CMD:uncuff(playerid, params[])
{
	if(!IsACop(playerid)) 
		return SendInf(playerid, "Эта функция только для МВД/ФСБ");

	if(sscanf(params, "d", params[0])) 
	{
		return SendInf(playerid, "/uncuff [ID]");
	}

	new id = params[0];

	if(!IsPlayerConnected(id)) 
		return SendInf(playerid, "Неверный ID игрока");
	if(GetPlayerDistanceToPlayer(playerid,id) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(id)) 
		return SendInf(playerid, "Вы далеко друг от друга");
	if(pTemp[id][pCuffer] == INVALID_PLAYER_ID) 
		return SendInf(playerid, "Игрок не в наручниках");
	if(id == playerid) 
		return SendErr(playerid, "Вы не можете снять наручники с себя");

	SetPlayerSpecialAction(id,SPECIAL_ACTION_NONE);
	RemovePlayerAttachedObject(id,0);
	pTemp[id][pCuffer] = INVALID_PLAYER_ID;
	pTemp[id][pCuffee] = INVALID_PLAYER_ID;
	pTemp[playerid][pCuffee] = INVALID_PLAYER_ID;
	pTemp[playerid][pCuffer] = INVALID_PLAYER_ID;
	pTemp[id][pHolder] = INVALID_PLAYER_ID;
	TogglePlayerControllable(id,1);
	if(pData[id][pJail] > 0) MeAction(playerid,"снял наручники с заключенного");
	else MeAction(playerid,"снял наручники с подозреваемого");

	return true;
}


CMD:uninviteoff(playerid, params[])
{
    if(!pData[playerid][pFraction]) 
    	return SendErr(playerid,"Вы не состоите в организации.");

	if(sscanf(params, "s[32]", params[0])) 
	{
		return SendInf(playerid, "/uninviteoff [Ник Игрока]");
	}


	if(strfind(params[0], pData[playerid][pNickname]) != -1)  
		return SendErr(playerid,"Вы не можете уволить самого себя");
	if(pData[playerid][pAdmin] > 3 && pData[playerid][pAdmin] < 7) 
		return SendErr(playerid,"Команда недоступна");


	sql_escape_string(zConn, params[0], params[0], 32);
	new query[256];

	if(pData[playerid][pSubfraction]) 
	{
	    if(pData[playerid][pRank] < gFractionRankCount[pData[playerid][pFraction]-1]-1) return SendErr(playerid,"Команда доступна только лидеру организации.");
		format(query, sizeof(query), "SELECT `id` FROM `accounts` WHERE `nickname` = '%s' AND `fraction`='%d' AND `subfraction`='%d'", params[0], pData[playerid][pFraction], pData[playerid][pSubfraction]);
	}
	else 
	{
		if(pData[playerid][pRank] < gFractionRankCount[pData[playerid][pFraction]-1]) return SendErr(playerid,"Команда доступна только лидеру организации.");
		format(query, sizeof(query), "SELECT `id` FROM `accounts`  WHERE `nickname` = '%s' AND `fraction`='%d'", params[0], pData[playerid][pFraction]);
	}
	if(pData[playerid][pFraction] == 11)
	{
		if(!pData[playerid][pSubfraction] && pData[playerid][pRank] < 9)
		{
			return SendErr(playerid,"Команда доступна только лидеру организации.");
		}
	}

	new Result:r = sql_queryEx(zConn, query,QUERY_CACHED);

    if(!sql_num_rows(r)) 
    { 
    	sql_free_result(r); 
    	return SendErr(playerid,"Игрок с введенным ником не найден в Вашей организации."); 
	}
    sql_free_result(r);

	if(pData[playerid][pSubfraction]) 
	{
	    if(pData[playerid][pRank] < gFractionRankCount[pData[playerid][pFraction]-1]-1) return SendErr(playerid,"Команда доступна только лидеру организации.");
		format(query, sizeof(query), "UPDATE `accounts` SET `fraction` = '0',`rank`='0',`fractionskin`='0',`fwarn` = '0' WHERE `nickname` = '%s' AND `fraction`='%d' AND `subfraction`='%d'", params[0], pData[playerid][pFraction], pData[playerid][pSubfraction]);
	}
	else 
	{
		if(pData[playerid][pRank] < gFractionRankCount[pData[playerid][pFraction]-1]) return SendErr(playerid,"Команда доступна только лидеру организации.");
		format(query, sizeof(query), "UPDATE `accounts` SET `fraction` = '0',`rank`='0',`fractionskin`='0',`fwarn` = '0' WHERE `nickname` = '%s' AND `fraction`='%d'", params[0], pData[playerid][pFraction]);
	}

	r = sql_queryEx(zConn, query);
	format(query, sizeof(query), "Лидер организации %s уволил в оффлайне игрока %s",pData[playerid][pNickname], params[0]);

	foreach(new i: logged_players)
	{
	    if(!IsPlayerConnected(i)) continue;
	    if(pData[i][pFraction] == pData[playerid][pFraction]) 
	    {
			if(pData[playerid][pSubfraction] && pData[i][pSubfraction] == pData[playerid][pSubfraction]) 
			{
				SendClientMessage(i,COLOR_ORANGE, query);
				continue;
			}
			if(!pData[playerid][pSubfraction]) 
			{
			    SendClientMessage(i,COLOR_ORANGE, query);
			    continue;
			}
		}
	}
	sql_free_result(r);
	return 1;
}

CMD:clear(playerid, params[])
{
	if(!IsACop(playerid) || pData[playerid][pRank] < 4) 
		return SendErr(playerid, "Вы не можете использовать данную команду");

	if(sscanf(params, "d", params[0])) 
	{
		return SendInf(playerid, "/clear [ID]");
	}

	new id = params[0];

	if(!IsPlayerConnected(id)) 
		return SendErr(playerid,"Неверный ID");
	if(!pData[id][pWanted]) 
		return SendErr(playerid,"У игрока нет розыска");

	pData[id][pWanted] = 0;
	UpdatePlayerData(id,"wanted",0);
	SetPlayerWantedLevel(id,0);


	new mes[128];
	format(mes,sizeof(mes),"%s %s снял розыск %s",gFractionRankName[pData[playerid][pFraction]-1][pData[playerid][pRank]-1], pData[playerid][pNickname],pData[id][pNickname]);
	CopMes(CDEPARTMENT,mes);
	format(mes,sizeof(mes), "%s %s снял вам розыск",gFractionRankName[pData[playerid][pFraction]-1][pData[playerid][pRank]-1],pData[playerid][pNickname]);
	SendClientMessage(id,CDEPARTMENT,mes);
	return 1;
}

CMD:hold(playerid, params[])
{
	if(IsACop(playerid)) 
	{
		if(pData[playerid][pRank] < 2) 
			return SendInf(playerid, "Ваш ранг не достаточен для этого");

		if(sscanf(params, "d", params[0])) 
		{
			return SendInf(playerid, "/hold [ID]");
		}


		new id = params[0];

		if(!IsPlayerConnected(id) || !pData[id][pMysqlID]) 
			return SendInf(playerid, "Неверный ID игрока");
		if(pData[id][pWanted] < 1 && !pData[id][pJail]) 
			return SendErr(playerid, "Данный игрок не в розыске и не в тюрьме");

		if(GetPlayerDistanceToPlayer(playerid,id) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(id))
			return SendInf(playerid, "Вы далеко друг от друга");
		if(pTemp[id][pCuffee] != id) 
			return SendInf(playerid, "Игрок не в наручниках");

		foreach(Player, d)
		{
			if(	pTemp[d][pHolder] == playerid +1)
			{
			    new mes[256];
				format(mes,sizeof(mes),"Вы уже ведете за собой игрока");
				SendClientMessage(playerid,CINFO,mes);
				return true;
			}
		}
		pTemp[id][pHolder] = playerid+1; // pTemp[id][pCuffee] != id
		if(pData[id][pJail] > 0)
		{
			MeAction(playerid,"повел заключенного за собой");
		}
		else
		{
			MeAction(playerid,"повел подозреваемого за собой");
		}
		return true;
	}
	return true;
}

CMD:unhold(playerid, params[])
{
	if(IsACop(playerid))
	{
		if(pData[playerid][pRank] < 2) 
			return SendInf(playerid, "Ваш ранг не достаточен для этого");


		if(sscanf(params, "d", params[0])) 
		{
			return SendInf(playerid, "/unhold [ID]");
		}


		new id = params[0];


		if(!IsPlayerConnected(id) || !pData[id][pMysqlID]) 
			return SendInf(playerid, "Неверный ID игрока");
		if(pTemp[id][pHolder] != playerid +1) 
			return SendInf(playerid, "Вы не ведете этого игрока за собой");

		pTemp[id][pHolder] = INVALID_PLAYER_ID;

		if(pData[id][pJail] > 0) MeAction(playerid,"остановил заключенного");
		else MeAction(playerid,"остановил преступника");

		ClearAnimations(id, 1);
	 	ApplyAnimation(id,"ped","IDLE_chat",4.1,1,0,0,0,1,1);

	    if(ControllableTimer[id] != -1) 	
	    {
			KillTimer(ControllableTimer[id]);
			ControllableTimer[id] = - 1;		
		}
	    TogglePlayerControllable(id, false);
	    ControllableTimer[id] = SetTimerEx("ToggleControllable", 1000, false, "ii", id, 1);
		return true;
	}
	return true;
}

CMD:su(playerid, params[])
{
	if(!IsACop(playerid)) 
		return SendInf(playerid, "Эта функция только для МВД/ФСБ");

	if(pData[playerid][pRank] < 2) 
		return SendInf(playerid, "Эта функция только со второго ранга");

	if(sscanf(params, "d", params[0])) 
	{
		return SendInf(playerid, "/su [ID]");
	}


	new id = params[0];
	if(!IsPlayerConnected(id) || !pData[id][pMysqlID]) 
		return SendInf(playerid, "Неверный ID игрока");

	if(id == playerid) 
		return SendInf(playerid, "Вы не можете изменить розыск самому себе");
	if(pData[id][pJail]) 
		return SendInf(playerid, "Игрок уже находится в КПЗ");

	if(pData[id][pWanted] >= 6) 
		return SendInf(playerid, "У игрока уже имеется максимальный уровень розыска");

	format(String4096,sizeof(String4096),"");
	for(new x; x < 13; x ++)
	{
		format(String256,sizeof(String256),"{FFCC33}%d. "cWH"%s\n",x+1, sucmd[x]);
		strcat(String4096, String256);
	}
	SetPVarIntNew(playerid,"wantedsid",id);

	return SPD(playerid, dSu, DIALOG_STYLE_LIST, pData[id][pNickname] ,String4096, "Далее", "Отмена");

}


CMD:fm(playerid)
{
	return SPD(playerid,dReportRadio,1,"{FFD65C}Радио-Репорт","\n\nВведите вопрос / заказ:\n\n","Далее","Отмена");
}

CMD:topadvert(playerid)
{
	if(pData[playerid][pFraction] != 10) return SendInf(playerid, "Эта функция доступна только сотрудникам СМИ.");
	SPD(playerid,dAdvInf,2,"{FFDF80}Лучшие сотрудники","{FFDF80}1. "cWH"Радиоцентр г.Южный\n{FFDF80}2. "cWH"Радиоцентр г.Эдово\n{FFDF80}3. "cWH"Радиоцентр г.Арзамас\n{99CCFF}-  "cWH"Общий рейтинг","Далее","Закрыть");
	return true;
}

CMD:topmedic(playerid)
{
	if(pData[playerid][pFraction] != 2) return SendInf(playerid, "Эта функция доступна только сотрудникам больницы.");
	SPD(playerid,dAdvInf2,2,"{FFDF80}Лучшие сотрудники больниц","{FFDF80}1. "cWH"Больница г.Южный\n{FFDF80}2. "cWH"Больница г.Арзамас\n{FFDF80}3. "cWH"Больница п.Батырево\n{99CCFF}-  "cWH"Общий рейтинг","Далее","Закрыть");
	return true;
}

alias:menu("mm", "mn", "ьутг", "ьт", "ьь");
CMD:menu(playerid)
{
	return SPD(playerid,dPlayerMenu,2,""cBLUE"Меню игрока:",\
		""cBLUE"1."cWH" Статистика игрока\n\
		"cBLUE"2."cWH" Личные настройки\n\
		"cBLUE"3."cWH" Настройки клиента\n\
		"cBLUE"4."cWH" Список команд\n\
		"cBLUE"5."cWH" Трудовая книжка\n\
		"cBLUE"6."cWH" Связь с администрацией\n\
		"cBLUE"7."cWH" Безопасность аккаунта\n\
		"cBLUE"8."cWH" Промокоды\n\
		"cBLUE"9."cWH" Донат\n\
		"cBLUE"10."cWH" Смена нонРП ника\n\
		"cBLUE"11."cWH" Улучшения\n\
		"cBLUE"12."cWH" Полезные ссылки\n\
		"cBLUE"13."cWH" Биндер","ОК","Выход");
}

alias:setting("ыуеештп");
CMD:setting(playerid)
{
	show_setting_player(playerid);

	return true;
}

CMD:w(playerid, params[])
{
	if(pData[playerid][pMut]) return SendClientMessage(playerid,CGRAY,"У Вас бан чата. Используйте /mutetime чтобы узнать время бана.");
	if( pTemp[playerid][pMutM] )
	{
		SendClientMessage(playerid,CGRAY,"У Вас затычка во рту.");
		return 1;
	}

	if(sscanf(params, "s[128]", params[0]))
	{
		SendInf(playerid, "/w [Сообщение]");
		return true;
	}

	if(!strlen(params[0])) return SendClientMessage(playerid,CGRAY,"/w [текст]");
	if(strlen(params[0]) < 6) StopFlood[playerid]--;
	if(gettime() < StopFlood[playerid]) return SendClientMessage(playerid, CGRAY, "Не флудите"),true;
	if(!pTemp[playerid][pLogined] || !pData[playerid][pMysqlID]) return 1;

	new sstate = GetPlayerState(playerid);
	if( sstate == PLAYER_STATE_SPECTATING || sstate == 0 ) return 1;
	new Float:sX,Float:sY,Float:sZ;
	GetPlayerPos(playerid,sX,sY,sZ );
	if( sX < -9999 || sX > 9999 || sY < -9999  || sY > 9999  || sZ < -9999  || sZ > 9999 ) return 1;

	StopFlood[playerid] = gettime()+CHAT_INTERVAL;
	if(strlen(FloodText[playerid]) > 5 && !strcmp(params[0], FloodText[playerid], true)) return SendClientMessage(playerid, CGRAY, "Сообщение слишком похоже на предыдущее"),true;
	format(FloodText[playerid], 128, params[0]);
	format(String255,sizeof(String255), "{BDB76B}%s шепчет: %s", pData[playerid][pNickname], params[0]);
	ProxDetector(1.2, playerid, String255,0xBDB76BFF,0xBDB76BFF,0xBDB76BFF,0xBDB76BFF,0xBDB76BFF);
	SetPlayerChatBubble(playerid,String255,CGREEN,1.2,10000);

	return true;
}


CMD:try(playerid, params[])
{
	if(pData[playerid][pMut]) return SendClientMessage(playerid,CGRAY,"У Вас бан чата.  Используйте /mutetime чтобы узнать время бана.");
	if(pTemp[playerid][pMutM])
	{
		SendClientMessage(playerid,CGRAY,"У Вас затычка во рту.");
		return 1;
	}

	if(sscanf(params, "s[128]", params[0]))
	{
		SendInf(playerid, "/try [Действие]");
		return true;
	}

	if(!strlen(params[0])) 
		return SendClientMessage(playerid,CGRAY,"/try [Действие]");

	if(strlen(params[0]) > 70) 
		return SendClientMessage(playerid,CGRAY,"Слишком длинное сообщение");
	if(strlen(params[0]) < 6) StopFlood[playerid]--;

	if(gettime() < StopFlood[playerid]) return SendClientMessage(playerid, CGRAY, "Не флудите"),true;
	StopFlood[playerid] = gettime()+CHAT_INTERVAL;
	if(strlen(FloodText[playerid]) > 5 && !strcmp(params[0], FloodText[playerid], true)) return SendClientMessage(playerid, CGRAY, "Действие слишком похоже на предыдущее"),true;
	format(FloodText[playerid], 128, params[0]);
	TryAction(playerid, params[0]);

	return true;
}

CMD:me(playerid, params[])
{
	if(sscanf(params, "s[64]", params[0]))
	{
		SendInf(playerid, "/me [действие]");
		return SCM(playerid, COLOR_BLUE, !"[Пример] "cWH"/me достает телефон");
	}
	MeActionEx(playerid,params[0]);
	return true;
}

CMD:do(playerid, params[])
{
	if(sscanf(params, "s[64]", params[0]))
	{
		SendInf(playerid, "/do [действие]");
		return SCM(playerid, COLOR_BLUE, !"[Пример] "cWH"/do На руке Васи татуировка.");
	}
	DoAction(playerid,params[0]);
	return true;
}

CMD:todo(playerid, params[])
{
    new data_temp_text_todo[128], data_temp_string[54];

    if(sscanf(params, "s[128]", data_temp_text_todo)) 
    {
    	SendInf(playerid, "/todo [Текст*Действие]");
    	return SCM(playerid, COLOR_BLUE, !"[Пример] "cWH"/todo Ладно, поехали *выкинув сигарету в кусты");

    }
    if(strfind(data_temp_text_todo, "*") == -1)
    {
    	SendInf(playerid, "/todo [Текст*Действие]");
    	return SCM(playerid, COLOR_BLUE, !"[Пример] "cWH"/todo Ладно, поехали *выкинув сигарету в кусты");

    }

    format(data_temp_string, sizeof(data_temp_string), "', {DD90FF}- сказал(а) %s, ", pData[playerid][pNickname]);

    new 
    	data_of_token = strfind(data_temp_text_todo, "*");

    strdel(data_temp_text_todo, strfind(data_temp_text_todo, "*"), strfind(data_temp_text_todo, "*")+1);
    strins(data_temp_text_todo, data_temp_string, data_of_token);
    strins(data_temp_text_todo, "'", 0);

    SetPlayerChatBubble(playerid, data_temp_text_todo, 0x6495EDFF, 20.0, 10000);
    ProxDetector(20.0, playerid, data_temp_text_todo, 0xE6E6E6E6,0xC8C8C8C8,0xAAAAAAAA,0x8C8C8C8C,0x6E6E6E6E);
    return 1;
}


CMD:r(playerid, params[])
{
	if(IsAGang(playerid) || IsAMafia(playerid) || pData[playerid][pFraction] == 1) return SendInf(playerid, "Ошибка: Вам недоступна эта функция");
	if(!pData[playerid][pFraction]) return SendInf(playerid, "Ошибка: Вам недоступна эта функция");
	if(pData[playerid][pMut]) return SendInf(playerid, "Ошибка: У Вас бан чата.  Используйте /mutetime чтобы узнать время бана.");
	if(pTemp[playerid][pMutM])
	{
		SendInf(playerid, "У Вас затычка во рту.");
		return true;
	}

	if(pData[playerid][pJail]) return SCM(playerid, CGRAY, "Ошибка: Вы в тюрьме.");
	if(pTemp[playerid][pTied] == 1) { return SCM(playerid, COLOR_GREY, "Вы не можете достать рацию!"); }
	if(pTemp[playerid][pCuffee] == playerid) return SendInf(playerid, "Вы в наручниках");

	if(sscanf(params, "s[64]", params[0]))
	{
		return SendInf(playerid, "/r [текст]");
	}


	new fractionid = pData[playerid][pFraction]-1;
	new rank = pData[playerid][pRank];
	new mesid[128];
	SetPlayerChatBubble(playerid, "Сказал что-то в рацию", CPINK, 10.0, 3000);
	
	format(mesid,sizeof(mesid),"[R] %s %s[%d]: %s",gFractionRankName[fractionid][rank-1],pData[playerid][pNickname],playerid,params[0]);
	if(pData[playerid][pDivision] > 0 && pData[playerid][pFraction] == 9)// DivisionEx
	{
		format(mesid,sizeof(mesid),"[R] %s %s %s[%d]: %s",DivisionEx[pData[playerid][pDivision]],gFractionRankName[fractionid][rank-1],pData[playerid][pNickname],playerid,params[0]);
	}
	if(fractionid+1 == 11 && !pData[playerid][pSubfraction] && rank <= 9) {
		format(mesid,sizeof(mesid),"[R] %s %s[%d]: %s",gPrezRankName[rank-1],pData[playerid][pNickname],playerid,params[0]);
	}
	else if(fractionid+1 == 8 && pData[playerid][pSubfraction] == 3 && rank <= 12) {
		format(mesid,sizeof(mesid),"[R] %s %s[%d]: %s",gVmfRankName[rank-1],pData[playerid][pNickname],playerid,params[0]);
	}

	foreach(new i: logged_players)
	{
		if(IsPlayerConnected(i) && pData[i][pFraction] == fractionid+1 &&
		pData[i][pSubfraction] == pData[playerid][pSubfraction]) SCM(i,0xACE600FF,mesid);// 4a7e2f
		else if( pData[i][pFraction] == 11 && pTemp[i][pDChat] != 0 && pTemp[i][pDChat] == fractionid+1) SCM(i,0xACE600FF,mesid);
	}
    return true;
}

CMD:rn(playerid, params[])
{
	if(IsAGang(playerid) || IsAMafia(playerid) || pData[playerid][pFraction] == 1) return SendInf(playerid, "Ошибка: Вам недоступна эта функция");
	if(!pData[playerid][pFraction]) return SendInf(playerid, "Ошибка: Вам недоступна эта функция");
	if(pData[playerid][pMut]) return SendInf(playerid, "Ошибка: У Вас бан чата.  Используйте /mutetime чтобы узнать время бана.");
	if(pTemp[playerid][pMutM])
	{
		SendInf(playerid, "У Вас затычка во рту.");
		return true;
	}

	if(pData[playerid][pJail]) return SCM(playerid, CGRAY, "Ошибка: Вы в тюрьме.");
	if(pTemp[playerid][pTied] == 1) { return SCM(playerid, COLOR_GREY, "Вы не можете достать рацию!"); }
	if(pTemp[playerid][pCuffee] == playerid) return SendInf(playerid, "Вы в наручниках");

	if(sscanf(params, "s[64]", params[0]))
	{
		return SendInf(playerid, "/rn [текст]");
	}


	new fractionid = pData[playerid][pFraction]-1;
	new rank = pData[playerid][pRank];
	new mesid[128];
	SetPlayerChatBubble(playerid, "Сказал что-то в рацию", CPINK, 10.0, 3000);

	format(mesid,sizeof(mesid),"[R] %s %s[%d]: ((%s))",gFractionRankName[fractionid][rank-1],pData[playerid][pNickname],playerid,params[0]);
	if(pData[playerid][pDivision] > 0 && pData[playerid][pFraction] == 9)// DivisionEx
	{
		format(mesid,sizeof(mesid),"[R] %s %s %s[%d]: ((%s))",DivisionEx[pData[playerid][pDivision]],gFractionRankName[fractionid][rank-1],pData[playerid][pNickname],playerid,params[0]);
	}
	if(fractionid+1 == 11 && !pData[playerid][pSubfraction] && rank <= 9) {
		format(mesid,sizeof(mesid),"[R] %s %s[%d]: ((%s))",gPrezRankName[rank-1],pData[playerid][pNickname],playerid,params[0]);
	}
	else if(fractionid+1 == 8 && pData[playerid][pSubfraction] == 3 && rank <= 12) {
		format(mesid,sizeof(mesid),"[R] %s %s[%d]: ((%s))",gVmfRankName[rank-1],pData[playerid][pNickname],playerid,params[0]);
	}
	foreach(new i: logged_players)
	{
		if(IsPlayerConnected(i) && pData[i][pFraction] == fractionid+1 &&
		pData[i][pSubfraction] == pData[playerid][pSubfraction]) SCM(i,0xACE600FF,mesid);// 4a7e2f
		else if( pData[i][pFraction] == 11 && pTemp[i][pDChat] != 0 && pTemp[i][pDChat] == fractionid+1) SCM(i,0xACE600FF,mesid);
	}
    return true;
}

CMD:l(playerid, params[])
{
    new mesid[140];
	if(pData[playerid][pFraction] == 0 || (!IsALeader(playerid) || IsAGang(playerid) || IsAMafia(playerid))) {
		if(pData[playerid][pFraction] == 11 && pData[playerid][pRank] == 9) {}
		else return SendInf(playerid, "Ошибка: Вам недоступна эта функция");
	}
	if(pData[playerid][pMut]) return SendInf(playerid, "Ошибка: У Вас бан чата.  Используйте /mutetime чтобы узнать время бана.");
	if(pTemp[playerid][pMutM])
	{
		SendInf(playerid, "У Вас затычка во рту.");
		return true;
	}


	if(sscanf(params, "s[64]", params[0]))
	{
		return SendInf(playerid, "/l [текст]");
	}

	if(pData[playerid][pJail]) return SCM(playerid, CGRAY, "Ошибка: Вы в тюрьме.");

	if(params[0] < 6) StopFlood[playerid]--;
	if(gettime() < StopFlood[playerid]) return SCM(playerid, CGRAY, "Не флудите"),true;
	StopFlood[playerid] = gettime()+CHAT_INTERVAL;
	if(strlen(FloodText[playerid]) > 5 && !strcmp(params[0], FloodText[playerid], true)) return SCM(playerid, CGRAY, "Сообщение слишком похоже на предыдущее"),true;
	format(FloodText[playerid], 128, params[0]);

	SetPlayerChatBubble(playerid, "Сказал что-то в рацию", CPINK, 10.0, 3000);
	if(pData[playerid][pFraction] == 11 && !pData[playerid][pSubfraction] && pData[playerid][pRank] <= 9)
	format(mesid,sizeof(mesid),"[L]:%s %s[%d]: %s",gPrezRankName[ pData[playerid][pRank]-1 ],pData[playerid][pNickname],playerid,params[0]);
    else if(pData[playerid][pFraction] == 11 && !pData[playerid][pSubfraction] && pData[playerid][pRank] > 9)
	format(mesid,sizeof(mesid),"[L]:%s %s[%d]: %s",gFractionRankName[ pData[playerid][pFraction] - 1 ][ pData[playerid][pRank]-1 ],pData[playerid][pNickname],playerid,params[0]);
	else if(pData[playerid][pFraction] == 8 && pData[playerid][pSubfraction] == 3)
	format(mesid,sizeof(mesid),"[L]:%s %s[%d]: %s",gVmfRankName[pData[playerid][pRank]-1],pData[playerid][pNickname],playerid,params[0]);
	else 
	{
	    if(pData[playerid][pSubfraction] > 0) {
		new fractionid = pData[playerid][pFraction]-1;
		new frid = GetSubfractionID(fractionid);
		new subid = pData[playerid][pSubfraction] - 1;
		format(mesid,sizeof(mesid),"[L]:(%s) %s %s[%d]: %s",gSubfractionName[frid][subid],gFractionRankName[ pData[playerid][pFraction] - 1 ][pData[playerid][pRank]-1],pData[playerid][pNickname],playerid,params[0]);
		}
		else {
			format(mesid,sizeof(mesid),"[L]:%s %s[%d]: %s",gFractionRankName[ pData[playerid][pFraction] - 1 ][pData[playerid][pRank]-1],pData[playerid][pNickname],playerid,params[0]);
		}
	}
	foreach(new i: logged_players)
	{
	    if(!IsPlayerConnected(i)) continue;
		if((pData[i][pFraction] > 0 && IsALeader(i) && !IsAGang(i) && !IsAMafia(i)) || (pData[i][pFraction] == 11 && pData[i][pRank] == 9)) {
			SCM(i, 0xFFEFADFF, mesid);
		}
	}
    return true;
}

CMD:togphone(playerid)
{
	if(!pData[playerid][pPhone]) 
		return SendClientMessage(playerid,CGRAY,"Ошибка: У Вас нет телефона. Вы можете купить его в Универмаге");
	if(!pTemp[playerid][pTPhone])
	{
		pTemp[playerid][pTPhone] = true;
		SendClientMessage(playerid,CGREEN,"Телефон включен");
	}
	else
	{
		pTemp[playerid][pTPhone] = false;
		SendClientMessage(playerid,CGREEN,"Телефон выключен");
		if(gCalls[playerid][g_caller] == INVALID_PLAYER_ID && gCalls[playerid][g_callee] == INVALID_PLAYER_ID) 
		{

		}
		else 
		{
			new id;
			if(gCalls[playerid][g_caller] == playerid) id = gCalls[playerid][g_callee];
			else if(gCalls[playerid][g_callee] == playerid) id = gCalls[playerid][g_caller];
			else
			{
			    gCalls[playerid][g_caller] = INVALID_PLAYER_ID;
			    gCalls[playerid][g_callee] = INVALID_PLAYER_ID;
				return 1;
			}
			SendClientMessage(playerid,CYELLOW,"Вы повесили трубку");
			SendClientMessage(id,CYELLOW,"Собеседник повесил трубку");
			SetPlayerSpecialAction(playerid,SPECIAL_ACTION_STOPUSECELLPHONE);
			SetTimerEx("ClearPhone",2000,false,"i",playerid);
			SetPlayerSpecialAction(id,SPECIAL_ACTION_STOPUSECELLPHONE);
			SetTimerEx("ClearPhone",2000,false,"i",id);
			gCalls[playerid][g_caller] = INVALID_PLAYER_ID;
			gCalls[playerid][g_callee] = INVALID_PLAYER_ID;
			gCalls[id][g_caller] = INVALID_PLAYER_ID;
			gCalls[id][g_callee] = INVALID_PLAYER_ID;
			pTemp[playerid][pCall] = false;
			pTemp[id][pCall] = false;
		}


	}
	return true;
}

CMD:call(playerid, params[])
{
	if(!pData[playerid][pPhone]) 
		return SendInf(playerid, "У Вас нет телефона. Вы можете купить его в Универмаге");
	if(!pTemp[playerid][pTPhone]) 
		return SendInf(playerid, "Сначала нужно включить телефон");
	if(pTemp[playerid][pCuffee] == playerid) 
		return SendInf(playerid, "Вы в наручниках");

	if(sscanf(params, "d", params[0]))
	{
		format(String64, sizeof(String64), "СТО %s | Номер телефона: %d", mechanic[0][mechanic_base_name], mechanic[0][mechanic_base_phone]);
		SendInf(playerid, String64);
		format(String64, sizeof(String64), "СТО %s | Номер телефона: %d", mechanic[1][mechanic_base_name], mechanic[1][mechanic_base_phone]);
		SendInf(playerid, String64);
		format(String64, sizeof(String64), "СТО %s | Номер телефона: %d", mechanic[2][mechanic_base_name], mechanic[2][mechanic_base_phone]);
		SendInf(playerid, String64);

		SendInf(playerid, "ЯндексТакси | Номер телефона: 1001");
		SendInf(playerid, "UBER | Номер телефона: 1002");
		SendInf(playerid, "СитиМобил | Номер телефона: 1003");
		return SendInf(playerid, "/call [Номер]");
	}

	if(gCalls[playerid][g_caller] != INVALID_PLAYER_ID || gCalls[playerid][g_callee] != INVALID_PLAYER_ID) 
		return SendInf(playerid, "Сначала завершите текущий разговор (/h)");

	new number = params[0];

	if(number == 111)
	{
		if(pData[playerid][pPhoneMoney] < 5) return SCM(playerid, CGRAY, "Ошибка: На счету недостаточно средств");
		if(pData[playerid][pJail] && pData[playerid][pPrison] > 3) return SCM(playerid, CGRAY, "Ошибка: Вы в тюрьме.");
		if(pData[playerid][pMut]) return SendInf(playerid, "У Вас бан чата. Используйте /mutetime чтобы узнать время бана.");
		if(pTemp[playerid][pNotReportP]) return SendInf(playerid, "Нельзя писать сообщение чаще, чем 1 раз в минуту");
		SPD(playerid,dServicePrez,1,"{FFC994}Горячая линия Президента",""cWH"Здравствуйте. Опишите ваш вопрос или предложение:","Далее","Отмена");
		return true;
	}
	else if(number == 102)
	{
		if(pData[playerid][pJail] && pData[playerid][pPrison] > 3) return SCM(playerid, CGRAY, "Ошибка: Вы в тюрьме.");
		if(GetPlayerInterior(playerid) != 0) return SendErr(playerid,"Сигнал недоступен");
		if(pData[playerid][pMut]) return SendInf(playerid, "У Вас бан чата. Используйте /mutetime чтобы узнать время бана.");
		SPD(playerid,dEmergencyCall,2,"{FFC994}Экстренные службы государства","{9494FF}1."cWH" МВД\n{9494FF}2."cWH" Скорая помощь\n{9494FF}3."cWH" Механик","Далее","Отмена");
		return true;
	}

	else if(number == mechanic[0][mechanic_base_phone])
	{
		if(pData[playerid][pPhoneMoney] < 250) 
			return SCM(playerid, CGRAY, "Ошибка: На счету недостаточно средств, требуется 250 рублей!");

		if(pData[playerid][pJail] && pData[playerid][pPrison] > 3) 
			return SCM(playerid, CGRAY, "Ошибка: Вы в тюрьме.");

		pData[playerid][pPhoneMoney] =- 250;
		UpdatePlayerData(playerid,"phonemoney",pData[playerid][pPhoneMoney]);	

		return Call_Mechanic(playerid, number);
	}
	else if(number == mechanic[1][mechanic_base_phone])
	{
		if(pData[playerid][pPhoneMoney] < 250) 
			return SCM(playerid, CGRAY, "Ошибка: На счету недостаточно средств, требуется 250 рублей!");

		if(pData[playerid][pJail] && pData[playerid][pPrison] > 3) 
			return SCM(playerid, CGRAY, "Ошибка: Вы в тюрьме.");

		pData[playerid][pPhoneMoney] =- 250;
		UpdatePlayerData(playerid,"phonemoney",pData[playerid][pPhoneMoney]);	

		return Call_Mechanic(playerid, number);
	}
	else if(number == mechanic[2][mechanic_base_phone])
	{
		if(pData[playerid][pPhoneMoney] < 250) 
			return SCM(playerid, CGRAY, "Ошибка: На счету недостаточно средств, требуется 250 рублей!");

		if(pData[playerid][pJail] && pData[playerid][pPrison] > 3) 
			return SCM(playerid, CGRAY, "Ошибка: Вы в тюрьме.");

		pData[playerid][pPhoneMoney] =- 250;
		UpdatePlayerData(playerid,"phonemoney",pData[playerid][pPhoneMoney]);	

		return Call_Mechanic(playerid, number);
	}

	else if(number == 1001)
	{
		if(taxi_company[TAXI_COMPANY_YANDEX][taxi_company_count_working] == 0)
		{
			return SendInf(playerid, "Нет свободных водителей!");				
		}

		SendSucc(playerid, "Такси вызвано, ожидайте!");
		SetPVarIntNew(playerid, "active_call_taxi", 1);
		
		
		call_driver_yandex_taxi(playerid);
		taxi_client_timer[playerid] = 300;

	}
	else if(number == 1002)
	{

		if(taxi_company[TAXI_COMPANY_UBER][taxi_company_count_working] == 0)
		{
			return SendInf(playerid, "Нет свободных водителей!");			
		}

		SendSucc(playerid, "Такси вызвано, ожидайте!");
		SetPVarIntNew(playerid, "active_call_taxi", 1);
		
		
		call_driver_uber_taxi(playerid);
		taxi_client_timer[playerid] = 300;
	}
	else if(number == 1003)
	{
		if(taxi_company[TAXI_COMPANY_CITY][taxi_company_count_working] == 0)
		{
			return SendInf(playerid, "Нет свободных водителей!");						
		}		

		SendSucc(playerid, "Такси вызвано, ожидайте!");
		SetPVarIntNew(playerid, "active_call_taxi", 1);
		
		
		call_driver_city_taxi(playerid);
		taxi_client_timer[playerid] = 300;
	}

	else if(number >= 9900 && number <= 9902)
	{
		if(pData[playerid][pPhoneMoney] < 5) return SCM(playerid, CGRAY, "Ошибка: На счету недостаточно средств");
		if(pData[playerid][pJail] && pData[playerid][pPrison] > 3) return SCM(playerid, CGRAY, "Ошибка: Вы в тюрьме.");
		if(pData[playerid][pFraction] == 10 && pData[playerid][pSubfraction] != 0) return SendInf(playerid, "Вы не можете звонить в свою организацию");
	    if(gettime() < pTemp[playerid][radioTime]) return SendErr(playerid, "После последнего звонка в студию должно пройти 30 секунд");
		new price;
		switch(number)
	    {
	        case 9900:
	        {
				if(!gNewsDialing[0]) return SendInf(playerid, "Звонки не принимаются");
				if(gNewsDialee[0] != INVALID_PLAYER_ID) return SendInf(playerid, "Линия занята");
				if(GetPlayerMoneyEx(playerid) < gNewsDialPrice[0]) 
				{
					show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:info_gui_no_money", 3000);
					return SendInf(playerid, "У вас недостаточно денег");
				}
				price = gNewsDialPrice[0];
				SetPVarIntNew(playerid, "newsdial", 1);
			}
			case 9901:
			{
			    if(!gNewsDialing[1]) return SendInf(playerid, "Звонки не принимаются");
                if(gNewsDialee[1] != INVALID_PLAYER_ID) return SendInf(playerid, "Линия занята");
				if(GetPlayerMoneyEx(playerid) < gNewsDialPrice[1]) 
				{
					show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:info_gui_no_money", 3000);
					return SendInf(playerid, "У вас недостаточно денег");
				}
                price = gNewsDialPrice[1];
				SetPVarIntNew(playerid, "newsdial", 2);
			}
			case 9902:
			{
				if(!gNewsDialing[2]) return SendInf(playerid, "Звонки не принимаются");
			    if(gNewsDialee[2] != INVALID_PLAYER_ID) return SendInf(playerid, "Линия занята");
				if(GetPlayerMoneyEx(playerid) < gNewsDialPrice[2]) 
				{
					show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:info_gui_no_money", 3000);
					return SendInf(playerid, "У вас недостаточно денег");
				}
                price = gNewsDialPrice[2];
				SetPVarIntNew(playerid, "newsdial", 3);
			}
  		}
  		new mes[128];
		format(mes,sizeof(mes),"Цена звонка: %d рублей\n\n"cGR"ВНИМАНИЕ! "cWH"Есть вероятность, что вы не сможете дозвониться.\nДеньги буду сняты в любом случае.\n\n\t\t\t{"#cYELLOW"}Продолжить?",price);
		SPD(playerid,dNewsDial,0,"{9494FF}Дозвон",mes,"Да","Нет");
		return true;
	}
	
	
	//if(!number) 
		//return SendInf(playerid, "Игрока с этим номером нет на сервере");
		

	if(pData[playerid][pPhoneMoney] < 5) 
		return SCM(playerid, CGRAY, "Ошибка: На счету недостаточно средств");


	new id = -1;
	foreach(new i: logged_players)
	{
		if(!IsPlayerConnected(i)) continue;
		if(pData[i][pPhone] == number) 
		{
			id = i; 
			break;
		}
	}
	if(id == -1) 
		return SendInf(playerid, "Игрока с этим номером нет на сервере");
		
		
	if(id == playerid) 
		return SendInf(playerid, "Ошибка: вы ввели свой номер");
		
		
	if(!pTemp[id][pTPhone]) 
		return SendInf(playerid, "У игрока выключен телефон");


	if(pData[playerid][pJail] && pData[playerid][pPrison] > 3)
	{
		if(pData[id][pFraction] == 11 && pData[id][pRank] == 6 && pData[id][pSubfraction] != 0) {
		}
		else 
		{
			return SCM(playerid, CGRAY, "Ошибка: В тюрьме можно позвонить только адвокату");
		}
	}
	if(pData[id][pJail] && pData[id][pPrison] > 3) return SCM(playerid, CGRAY, "Игрок не может ответить на ваш звонок");

	if(gCalls[id][g_caller] != INVALID_PLAYER_ID || gCalls[id][g_callee] != INVALID_PLAYER_ID || id == playerid) return SendInf(playerid, "Занято...");
	gCalls[playerid][g_caller] = playerid;
	gCalls[playerid][g_callee] = id;
	gCalls[id][g_caller] = playerid;
	gCalls[id][g_callee] = id;

	SetPlayerSpecialAction(playerid,SPECIAL_ACTION_USECELLPHONE);

	SendSucc(playerid, "Вы начали звонок по телефону... Ожидайте ответа..");

	new mes[128];
	format(mes,sizeof(mes),"%s(тел. %d) звонит Вам на моб. телефон. {"#cGRAY"}(/p - ответить, /h - отклонить)",pData[playerid][pNickname],pData[playerid][pPhone]);
	SCM(id,CWHITE,mes);
    return true;
}

CMD:p(playerid)
{
	if(pTemp[playerid][pWater] != 0)
	{
		SCM(playerid,CRED,"Вы не можете звонить во время работы");
		return true;
	}
	if(gCalls[playerid][g_callee] != playerid) return SendInf(playerid, "Вам никто не звонит");
	if(pTemp[playerid][pEther]) return SendInf(playerid, "Нельзя во время эфира");
	new caller = gCalls[playerid][g_caller];
	if(caller == INVALID_PLAYER_ID || !IsPlayerConnected(caller)) return SendInf(playerid, "Собеседник вышел из игры");

	SendSucc(playerid, "Вы ответили на звонок..");

	SetPlayerSpecialAction(playerid,SPECIAL_ACTION_USECELLPHONE);
	SetPlayerAttachedObject(playerid,0,330,6);
	SCM(caller,CYELLOW,"Собеседник поднял телефон");
	pTemp[playerid][pCall] = true;
	pTemp[caller][pCall] = true;

	return true;
}

CMD:h(playerid)
{
    for(new i=0; i<3; i++) 
    {
    	if(gNewsDialee[i] == playerid)
		{
			SCM(playerid,CWHITE,"Вы положили трубку");
			SetPlayerSpecialAction(playerid,SPECIAL_ACTION_STOPUSECELLPHONE);
			SetTimerEx("ClearPhone",2000,false,"i",playerid);
			gNewsDialee[i] = INVALID_PLAYER_ID;
			SCM(gNewsDialer[i],CSYSTEM,"Игрок положил трубку");
			return true;
		}
	}
	if(gCalls[playerid][g_caller] == INVALID_PLAYER_ID && gCalls[playerid][g_callee] == INVALID_PLAYER_ID) return SendInf(playerid, "Вы не используете телефон");
	new id;
	if(gCalls[playerid][g_caller] == playerid) id = gCalls[playerid][g_callee];
	else if(gCalls[playerid][g_callee] == playerid) id = gCalls[playerid][g_caller];
	else
	{
	    gCalls[playerid][g_caller] = INVALID_PLAYER_ID;
	    gCalls[playerid][g_callee] = INVALID_PLAYER_ID;
		return true;
	}
	SCM(playerid,CYELLOW,"Вы повесили трубку");
	SCM(id,CYELLOW,"Собеседник повесил трубку");
	SetPlayerSpecialAction(playerid,SPECIAL_ACTION_STOPUSECELLPHONE);
	SetPlayerArmedWeapon(playerid,0);
	SetTimerEx("ClearPhone",2000,false,"i",playerid);
	SetPlayerSpecialAction(id,SPECIAL_ACTION_STOPUSECELLPHONE);
	SetPlayerArmedWeapon(id,0);
	SetTimerEx("ClearPhone",2000,false,"i",id);
	gCalls[playerid][g_caller] = INVALID_PLAYER_ID;
	gCalls[playerid][g_callee] = INVALID_PLAYER_ID;
	gCalls[id][g_caller] = INVALID_PLAYER_ID;
	gCalls[id][g_callee] = INVALID_PLAYER_ID;
	pTemp[playerid][pCall] = false;
	pTemp[id][pCall] = false;

	return true;
}



CMD:f(playerid, params[])
{
    if(!pData[playerid][pFraction]) return SendInf(playerid, "Ошибка: Вам недоступна эта функция");
	if(pData[playerid][pMut]) return SendInf(playerid, "Ошибка: У Вас бан чата. Используйте /mutetime чтобы узнать время бана.");
	if(pTemp[playerid][pMutM])
	{
		SendInf(playerid, "У Вас затычка во рту.");
		return true;
	}
	if(pTemp[playerid][pTied] == 1) { return SCM(playerid, COLOR_GREY, "Вы не можете достать рацию!"); }
	if(pTemp[playerid][pCuffee] == playerid) return SendInf(playerid, "Вы в наручниках");

	if(sscanf(params, "s[64]", params[0]))
	{
		return SendInf(playerid, "/f [Текст]");
	}



	new fractionid = pData[playerid][pFraction]-1;
	new rank = pData[playerid][pRank];
	new mesid[128];
	SetPlayerChatBubble(playerid, "Сказал что-то в рацию", CPINK, 10.0, 3000);
	format(mesid,sizeof(mesid),"[F] %s %s[%d]: %s",gFractionRankName[fractionid][rank-1],pData[playerid][pNickname],playerid,params[0]);
    if(fractionid+1 == 11 && !pData[playerid][pSubfraction] && rank <= 9)
        format(mesid,sizeof(mesid),"[F] %s %s[%d]: %s",gPrezRankName[rank-1],pData[playerid][pNickname],playerid,params[0]);
    else if(fractionid+1 == 8 && pData[playerid][pSubfraction] == 3 && rank <= 12)
        format(mesid,sizeof(mesid),"[F] %s %s[%d]: %s",gVmfRankName[rank-1],pData[playerid][pNickname],playerid,params[0]);
    else if(pData[playerid][pDivision] > 0 && pData[playerid][pFraction] == 9)
    {
    format(mesid,sizeof(mesid),"[F] %s %s %s[%d]: %s",DivisionEx[pData[playerid][pDivision]],gFractionRankName[fractionid][rank-1],pData[playerid][pNickname],playerid,params[0]);
	}
	SendFMes(fractionid+1,CBLUE, mesid);

	return true;
}

CMD:fn(playerid, params[])
{
    if(!pData[playerid][pFraction]) return SendInf(playerid, "Ошибка: Вам недоступна эта функция");
	if(pData[playerid][pMut]) return SendInf(playerid, "Ошибка: У Вас бан чата. Используйте /mutetime чтобы узнать время бана.");
	if(pTemp[playerid][pMutM])
	{
		SendInf(playerid, "У Вас затычка во рту.");
		return true;
	}
	if(pTemp[playerid][pTied] == 1) { return SCM(playerid, COLOR_GREY, "Вы не можете достать рацию!"); }
	if(pTemp[playerid][pCuffee] == playerid) return SendInf(playerid, "Вы в наручниках");

	if(sscanf(params, "s[64]", params[0]))
	{
		return SendInf(playerid, "/fn [Текст]");
	}



	new fractionid = pData[playerid][pFraction]-1;
	new rank = pData[playerid][pRank];
	new mesid[128];
	SetPlayerChatBubble(playerid, "Сказал что-то в рацию", CPINK, 10.0, 3000);
	format(mesid,sizeof(mesid),"[F] %s %s[%d]: ((%s))",gFractionRankName[fractionid][rank-1],pData[playerid][pNickname],playerid, params[0]);
    if(fractionid+1 == 11 && !pData[playerid][pSubfraction] && rank <= 9)
        format(mesid,sizeof(mesid),"[F] %s %s[%d]: ((%s))",gPrezRankName[rank-1],pData[playerid][pNickname],playerid, params[0]);
    else if(fractionid+1 == 8 && pData[playerid][pSubfraction] == 3 && rank <= 12)
        format(mesid,sizeof(mesid),"[F] %s %s[%d]: ((%s))",gVmfRankName[rank-1],pData[playerid][pNickname],playerid, params[0]);
    else if(pData[playerid][pDivision] > 0 && pData[playerid][pFraction] == 9)
    {
        format(mesid,sizeof(mesid),"[F] %s %s %s[%d]: ((%s))",DivisionEx[pData[playerid][pDivision]],gFractionRankName[fractionid][rank-1],pData[playerid][pNickname],playerid,params[0]);
	}
	SendFMes(fractionid+1,CBLUE, mesid);

	return true;
}

CMD:n(playerid, params[])
{
	if(pData[playerid][pMut]) return SendInf(playerid, "Ошибка: У Вас бан чата. Используйте /mutetime чтобы узнать время бана.");
	if(pTemp[playerid][pMutM])
	{
		SendInf(playerid, "У Вас затычка во рту.");
		return true;
	}
    new string[256];


	if(sscanf(params, "s[64]", params[0]))
	{
		return SendInf(playerid, "/n [Текст]");
	}



	if(strlen(params[0]) < 6) StopFlood[playerid]--;
	if(gettime() < StopFlood[playerid]) return SCM(playerid, CGRAY, "Не флудите"),true;
	StopFlood[playerid] = gettime()+CHAT_INTERVAL;
	if(strlen(FloodText[playerid]) > 5 && !strcmp(params[0], FloodText[playerid], true)) return SCM(playerid, CGRAY, "Сообщение слишком похоже на предыдущее"),true;
	format(FloodText[playerid], 128, params[0]);
	format(string, sizeof(string), "{CCCC99}(( %s[%d]: %s ))", pData[playerid][pNickname],playerid, params[0]);
	if(pData[playerid][pBilet] == 101) {
	ProxDetector(5.0, playerid, string,0xCCCC99FF,0xCCCC99FF,0xCCCC99FF,0xCCCC99FF,0xCCCC99FF);
	}
	else
	{
	ProxDetector(20.0, playerid, string,0xCCCC99FF,0xCCCC99FF,0xCCCC99FF,0xCCCC99FF,0xCCCC99FF);
	}
	SetPlayerChatBubble(playerid, params[0], 0xCCCC99FF, 20.0, 7000);
    return true;
}

CMD:wedding(playerid, params[])
{

	if(!IsPlayerInRangeOfPoint(playerid, 3.0 , 1879.9982,1170.7963,30.0087)) return SCM(playerid,-1,"Вы не в церкви"); //SendMes
	if(pData[playerid][pLevel] < 2) return SendErr(playerid, "Вы должны прожить 2 года в государстве для вступления в брак");

	if(sscanf(params, "d", params[0]))
	{
		return SendInf(playerid, "/wedding [ID игрока]");
	}

	if(GetPVarIntNew(playerid,"prbrakt") > GetTickCount())  return SCM(playerid, COLOR_WHITE, "Вы не можете вступать в брак так часто");

	new actplayerid = params[0]; // sendmes

    if(!(0 <= actplayerid < MAX_PLAYERS)) return SCM(playerid, COLOR_WHITE, "Используйте: /wedding [ID игрока] (Неверный ID)");
	if(!IsPlayerInRangeOfPoint(actplayerid,3.0 , 1879.9982,1170.7963,30.0087)) return SCM(playerid,0xff2400ff,"Дама, которой вы хотите сделать предложение не у церкви");
	if(pData[playerid][pMarried] > 0) return   SCM(playerid, 0xff2400ff, "Вы уже состоите в браке");
	if(pData[playerid][pSex] == 2) return SCM(playerid,0xff2400ff,"Вы женщина, с вашей стороны предложение вступить в брак запрещено!");
	if(!IsPlayerConnected(actplayerid) || playerid == actplayerid) return SCM(playerid,0xff2400ff,"Неверный ID игрока");

	if(pData[playerid][pSex] == pData[actplayerid][pSex]) return SCM(playerid,0xff2400ff,"Однополые браки запрещены!");

	if(IsPlayerConnected(actplayerid))
	{
		if(actplayerid != INVALID_PLAYER_ID)
		{
			if(pData[actplayerid][pMarried] > 0) return SCM(playerid, 0xff2400ff, "Данный человек состоит в браке");
		    if(GetPlayerDistanceToPlayer(playerid,actplayerid) > 20.0) return SCM(playerid, 0xff2400ff, "вы далеко друг от друга");
		    SFCM(playerid,0xadff2fff,"Вы сделали предложение %s",pData[actplayerid][pNickname]);  //SFCM(
		    SetPVarIntNew(playerid, "brakid", actplayerid);
			SFCM(actplayerid,0xadff2fff,"%s приглашает вас вступить в брак",pData[playerid][pNickname]);//SFCM(
			SCM(actplayerid,-1,"Нажмите {00ff1e}Y для подтверждения или {ffa500}N Для отказа");//SFCM(
			WeddingTwo[actplayerid] = playerid;
			predlojbrak[actplayerid] = 1;
	 	}
 	}
    return true;
}

CMD:heal(playerid, params[])
{
    new string[100];
	if(pData[playerid][pFraction] != 2) return SendInf(playerid, "Вам недоступна эта Команда");

	if(sscanf(params, "dd", params[0], params[1]))
	{
		return SendInf(playerid, "/heal [ID игрока] [Цена]");
	}


	new actplayerid = params[0];

	if(actplayerid == playerid ) return SendInf(playerid, "Вы не можете вылечить самого себя");
	new price = params[1];

	if(price < 1 || price > HealPay) {
		format(String256, sizeof(String256), "Цена должна быть от 1р до %dр", HealPay);
		return SCM(playerid,CGRAY,String256);
	}
	if(!IsPlayerInDynamicArea(playerid, hospital_area_heal)) 
		return SendInf(playerid, "Вы должны быть в больнице");

	if(GetPlayerDistanceToPlayer(playerid,actplayerid) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(actplayerid)) return SendInf(playerid, "Вы далеко друг от друга");

	SetPVarIntNew(actplayerid,"healprice",price);
	SetPVarIntNew(actplayerid,"doctorid",playerid);
	format(string, 100, "Вы предложили %s купить лекарство за %dр", pData[actplayerid][pNickname], price);
	SCM(playerid, CGREEN, string);
	SPFD(actplayerid,dHeal,0,"Мед. обслуживание","Да","Нет",""cWH"%s предлагает Вам купить лекарство за %dр",pData[playerid][pNickname],price);
    return true;
}

CMD:setskin(playerid, params[])
{
	if(!pData[playerid][pFraction]) return SendInf(playerid, "Вы не состоите в организации.");
	new fractionid = pData[playerid][pFraction] - 1;
	if(!IsAbleToGiveSkin(playerid)) return SendInf(playerid, "Ваш ранг недостаточен");

	if(sscanf(params, "d", params[0]))
	{
		return SendInf(playerid, "/setskin [ID игрока]");
	}

	new actplayerid = params[0];
	if(!IsPlayerConnected(actplayerid)) return SendInf(playerid, "Неверный ID игрока");
	if(pData[actplayerid][pFraction] != pData[playerid][pFraction]) return SendInf(playerid, "Игрок не состоит в вашей организации");
	if(pData[actplayerid][pJail] > 0) return SCM(playerid,COLOR_WHITE,"Этот игрок в тюрьме");
	if(pTemp[actplayerid][pAFK] > 2) return SCM(playerid,COLOR_WHITE,"Этот игрок AFK");
	if(pTemp[actplayerid][pWork] == 2 || pTemp[actplayerid][pWork] == 3) return SCM(playerid,COLOR_WHITE,"В данный момент нельзя сменить скин игроку");
	if(GetPlayerDistanceToPlayer(playerid,actplayerid) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(actplayerid)) return SendInf(playerid, "Вы далеко друг от друга");
	if(GetPlayerState(actplayerid) > 1 && GetPlayerState(actplayerid) < 4)			{
		SCM(playerid,CRED,"Игрок находится в автомобиле");
		return true;																}
	if(GetPlayerSpecialAction(actplayerid) == SPECIAL_ACTION_ENTER_VEHICLE )			{
		SCM(playerid,CRED,"Игрок находится в автомобиле");
		return true;																}


	if(pData[actplayerid][pFraction] != pData[playerid][pFraction]) return SendInf(playerid, "Игрок не состоит в вашей организации");
	if(pData[playerid][pSubfraction] > 0)
	{
		if(pData[actplayerid][pSubfraction] != pData[playerid][pSubfraction]) return SendInf(playerid, "Игрок не состоит в вашей подфракции");
	}
	if(pData[actplayerid][pRank] >= pData[playerid][pRank] && actplayerid != playerid) return SendInf(playerid, "Ваш ранг недостаточен");
	SetPVarIntNew(playerid,"actplayerid",actplayerid);
	new mes[300];
	for(new i = 0;i<12+8;i++)
	{
		new skinid = gFractionSkin[fractionid][i];
		if(!skinid) break;
		if(skinid == pData[actplayerid][pFractionSkin])
		{
			if(!i) format(mes,sizeof(mes),""cGR"Скин %d [%d]",i+1,skinid);
			else format(mes,sizeof(mes),"%s\n"cGR"Скин %d [%d]",mes,i+1,skinid);
		}
		else
		{
			if(!i) format(mes,sizeof(mes),"Скин %d [%d]",i+1,skinid);
			else format(mes,sizeof(mes),"%s\nСкин %d [%d]",mes,i+1,skinid);
		}
	}
	SPD(playerid,dFractionSkin,2,pData[actplayerid][pNickname],mes,"OK","Отмена");

    return true;
}

CMD:otvet(playerid, params[])
{

	if((pData[playerid][pFraction] == 11 && pData[playerid][pRank] > 3 && pData[playerid][pSubfraction] == 0) && IsPlayerInDynamicArea(playerid, gAreas[arPrezText4]))
	{

		if(sscanf(params, "ds[64]", params[0],params[1]))
		{
			return SendInf(playerid, "/otvet [ID игрока] [Ответ]");
		}

		new str[140];

		if(!IsPlayerConnected(params[0])) return SendInf(playerid, "Игрок не в сети");
		if(GetPVarIntNew(params[0], "prezcall") < 1) return SendErr(playerid, "Данный игрок не задавал вопросов на горячую линию");
		format(str, 140, "[Горячая линия] %s[%d]: %s",pData[playerid][pNickname], playerid, params[1]);
		SCM(params[0], 0x1A75FFFF, str);
		format(str, 128, "[Горячая линия] %s ответил(а) на звонок %s: %s",pData[playerid][pNickname], pData[params[0]][pNickname], params[1]);
		MeActionExes(playerid,str);
	}
	else 
	{
		SendErr(playerid, "Вы должны находиться на ресепшене Администрации Президента / У вас нет доступа");
	}
	return true;
}

CMD:vacancy(playerid)
{
	format(String4096,sizeof(String4096),"");
	new ff;
	for(new x; x < FRACTION_COUNT; x ++)
	{
		for(new z; z < 4; z ++)
		{
			if(gFractionSobes[ x ][ z ] > 0)
			{

			if(z > 0) {
			new frid = GetSubfractionID(x);
			format(String256,sizeof(String256),"{FFCC33}%d. "cWH"%s\n",ff+1, gSubfractionName[frid][z-1]);
			}
			else
			{
			format(String256,sizeof(String256),"{FFCC33}%d. "cWH"%s\n",ff+1, gFractionName[x]);
			}
			strcat(String4096, String256);
			format(String64, sizeof(String64),"sobes_%d", ff);
			SetPVarIntNew(playerid, String64, x);
			format(String64, sizeof(String64),"sobess_%d", ff);
			SetPVarIntNew(playerid, String64, z);
			ff ++;
			}
		}
	}
	if(ff == 0)
	{
		SPD(playerid, dMes, DIALOG_STYLE_MSGBOX, "Собеседования" ,"\n\nВ данный момент собеседования не проводятся\n\n", "Закрыть", "");
		return true;
	}
	
	
	SPD(playerid, dShowSobes, DIALOG_STYLE_LIST, "Собеседования" ,String4096, "Далее", "Закрыть");

	return true;
}

CMD:addvacancy(playerid)
{
    if(pData[playerid][pFraction] < 1 || IsAGang(playerid) ||IsAMafia(playerid) || !IsALeader(playerid)) return SendErr(playerid, "У вас нет прав на использование этой команды");
	if(gFractionSobes[ pData[playerid][pFraction]-1 ][ pData[playerid][pSubfraction] ] > 0)
	{
	    SPD(playerid, dDelSobes, DIALOG_STYLE_MSGBOX, "{FFDB70}Отменить собеседование", \
		"Вы хотите отменить собеседование?","Да","Закрыть");
	}
	else {
	    SPD(playerid, dAddSobes, DIALOG_STYLE_INPUT, "{FFDB70}Добавить собеседование", \
		"Введите место проведения собеседования и критерии набора","Далее","Закрыть");
	}

	return true;
}

CMD:pdhelp(playerid)
{
	if(!IsACop(playerid)) return SendInf(playerid, "Эта функция только для МВД/ФСБ");
	if(pData[playerid][pRank] < 2) return SendInf(playerid, "Ваш ранг не достаточен для этого");
	for(new x; x < 10; x ++)
	{
	if(PDhelp[x] == playerid + 1)
	{
    return SendInf(playerid, "Пожалуйста подождите, вы недавно запрашивали помощь");
		}
	}

	for(new x; x < 10; x ++)
	{
	if(PDhelp[x] == 0)
	{
	PDhelp[x] = playerid+1;
	GetPlayerPos(playerid, PDhelpPos[x][0],PDhelpPos[x][1],PDhelpPos[x][2]);
	SetTimerEx("ClearHelp",60000,false,"ii",x,PDhelp[x]);
	break;
	}
	if(x == 9)  return SendInf(playerid, "Пожалуйста подождите, все каналы связи заняты");
	}

	new mes[256];
	format(mes,sizeof(mes),"[Внимание] {FFD966}%s{007FFF} просит помощи, введите {FFD966}/helplist {007FFF}для просмотра местоположения.",pData[playerid][pNickname]);
	CopMes(CDEPARTMENT,mes);

	return true;
}

CMD:helplist(playerid)
{
    if(!IsACop(playerid)) return SendInf(playerid, "Эта функция только для МВД/ФСБ");
    for(new x; x < 10; x ++)
	{
	    if(PDhelp[x])
	    {
	        SetPlayerCheckpoint(playerid, PDhelpPos[x][0], PDhelpPos[x][1], PDhelpPos[x][2], 3.0);
	        return 1;
	    }
    }
    return SendErr(playerid, "Список пустой");
}

CMD:warntime(playerid)
{
    if(!pData[playerid][pWarnc]) return SendErr(playerid, "Предупреждений не обнаружено");
    if(	pData[playerid][pWarn]-gCurDay < 0)
    {
        if(pData[playerid][pWarn] > WARN_TIME){
		pData[playerid][pWarn] -= WARN_TIME; }
		else { pData[playerid][pWarn] = 0; }
		pData[playerid][pWarnc] = 0;
		return SendErr(playerid, "Предупреждений не обнаружено");
	}

    if(pData[playerid][pWarn]-gCurDay < WARN_TIME && pData[playerid][pWarnc] > 1){
		pData[playerid][pWarnc] --;
		new mes[256];
		format(mes,sizeof(mes),"UPDATE `accounts` SET `warnc` = '%d' WHERE `id` = '%d'",pData[playerid][pWarnc],pData[playerid][pMysqlID]);
		sql_queryEx(zConn, mes, QUERY_THREADED);
	}

    new zStr[64]; format(zStr, sizeof(zStr), "До снятия Вашего предупреждения осталось %d дней.", pData[playerid][pWarn]-gCurDay);
	SCM(playerid, CGRAY, zStr);
    return true;
}

CMD:racket(playerid, params[])
{
    if(!IsAMafia(playerid)) return true;
	if(pData[playerid][pRank] < 7) return SendErr(playerid, "Ваш ранг не достаточен!");
	if(sscanf(params, "dd", params[0], params[1]))
	    return SendErr(playerid, "/racket [ID игрока] [долг]");
    
    new mes[256];
	format(mes,sizeof(mes),"UPDATE `accounts` SET `racket` = '%d' WHERE `id` = '%d'", params[1], pData[params[0]][pMysqlID]);
	sql_queryEx(zConn, mes, QUERY_THREADED);
	
	SendInf(playerid, "Вы выписали долг данному человеку");
}

CMD:beat(playerid, params[])
{
    if(!IsAMafia(playerid)) return true;
	if(pData[playerid][pRank] < 7) return SendErr(playerid, "Ваш ранг не достаточен!");
	if(sscanf(params, "d", params[0]))
	    return SendErr(playerid, "/beat [ID игрока]");
    
    format(String2048, sizeof(String2048), "SELECT `racket` FROM `accounts` WHERE `id` = %d", pData[params[0]][pMysqlID]);
	new Result:r = sql_queryEx(zConn, String2048, QUERY_CACHED);
	
	new racket = sql_get_field_int_ex(r, 0, 0);
	
	if(pData[params[0]][pMoney] < racket)
	   SendErr(playerid, "У человека недостаточно денег");
    
    give_money(params[0], -racket, "долг");
    give_money(playerid, racket, "долг");
    
    new mes[256];
	format(mes,sizeof(mes),"UPDATE `accounts` SET `racket` = '%d' WHERE `id` = '%d'", 0, pData[params[0]][pMysqlID]);
	sql_queryEx(zConn, mes, QUERY_THREADED);
}

CMD:racketlist(playerid)
{
	if(!IsAMafia(playerid)) return true;
	if(pData[playerid][pRank] < 7) return SendErr(playerid, "Ваш ранг не достаточен!");

	format(String4096,sizeof(String4096),"Имя\tДолг\tОставшееся время\tСтатус"cWH"");

	format(String2048, sizeof(String2048), "SELECT `id`,`nickname`,`racket`,`racketday` FROM `accounts` WHERE `racketfr` = %d AND `racketday` >= %d", pData[playerid][pFraction], gettime());
	new Result:r = sql_queryEx(zConn, String2048, QUERY_CACHED);
	if(sql_num_rows(r))
	{
	new nn[MAX_PLAYER_NAME];
	new sqls = sql_num_rows(r); if(sqls > 30) { sqls = 30; }
	if(sqls < 0) { sql_free_result(r); return SendErr(playerid, "Ваша мафия не выбивает денег"); }
    for(new i=0; i< sqls; i++) //sql_num_rows(r)
	{
	    new mid = sql_get_field_int_ex(r, i, 0);
	    
	    format(String256, sizeof(String256), "rkt_%d",i);
		SetPVarIntNew(playerid, String256, mid);
		
	    sql_get_field_ex(r, i, 1, nn);
	    new mane = sql_get_field_int_ex(r, i, 2);
	    new daysm = sql_get_field_int_ex(r, i, 3);
		format(String256, sizeof(String256), "{CC0000}Offline"cWH"");
		foreach(Player, v)
		{
			if(mid == pData[v][pMysqlID]) {
			    format(String256, sizeof(String256), "racketex_%d",pData[v][pMysqlID] );
			    new racketex = GetGVarInt(String256 ,1002);
				if(racketex < gettime()) {
				format(String256, sizeof(String256), "{009900}Online"cWH" (Доступно выбивание)");
				}
				else {
				format(String256, sizeof(String256), "{009900}Online"cWH"");
				}
				break;
			}
		}
	    format(String4096, sizeof(String4096), "%s\n%s\t%d рублей\t%d дней\t%s",String4096,nn, mane, daysm/(60*60*24)-gettime()/(60*60*24) ,String256);
	}

	SPD(playerid,dMesMaf, DIALOG_STYLE_TABLIST_HEADERS, "Список должников мафии" , String4096 ,"Удалить","Закрыть");
	}
	else SCM(playerid, CGRAY, "Ваша мафия не выбивает денег");
	sql_free_result(r);


	return true;
}


CMD:kazna(playerid)
{
	if(pData[playerid][pFraction] != 11 || pData[playerid][pSubfraction] || pData[playerid][pRank] < 9)	
	{
		SendErr(playerid, "Доступно только Президенту и Премьер-Министру");
		return true;
	}
	if(pData[playerid][pRank] == 11) 
	{
	    show_kazna_menu(playerid);
	}
	else
	{
    	show_kazna_menu_low(playerid);
	}
	return true;
}

stock show_kazna_menu(playerid)
{
    format(String1024,sizeof(String1024),""cWH"Бюджет казны государства "cBLUE"%s"cWH": "cGR"%d рублей"cWH"\n\
    "cBLUE"1."cWH" Выделение денег гос.фракциям\n\
	"cBLUE"2."cWH" Изменение пенсионного возраста\n"cBLUE"5."cWH" Изменение пенсии\n\
	"cBLUE"3."cWH" Просмотр зарплат гос.служащих",ServerName,GosMoney[0]);
	strcat(String1024, "\n\
	"cBLUE"4."cWH" Регулирование зарплат сотрудников администрации\n\
	"cBLUE"5."cWH" Регулирование зарплат министров\n\
	"cBLUE"6."cWH" Регулирование зарплат мэрии\n\
	"cBLUE"7."cWH" Регулирование зарплат ФСБ");
	SPD(playerid, dKaznaMenu, DIALOG_STYLE_LIST, ""cBLUE"Казна государства", String1024, "Выбор", "Отмена");

	return true;
}

stock show_kazna_menu_low(playerid)
{
	format(String1024,sizeof(String1024),""cWH"Бюджет казны государства "cBLUE"%s"cWH": "cGR"%d рублей"cWH"\
	\n\
	"cBLUE"1."cWH" Просмотр зарплат гос.служащих",ServerName,GosMoney[0]);
	strcat(String1024, "\n\
	"cBLUE"2."cWH" Регулирование зарплат министров\n\
	"cBLUE"3."cWH" Регулирование зарплат мэрии\n\
	"cBLUE"4."cWH" Просмотр гос.служащих");
	SPD(playerid, dKaznaMenuVic, DIALOG_STYLE_LIST, ""cBLUE"Казна государства", String1024, "Выбор", "Отмена");	

	return true;
}

CMD:returnmoney(playerid)
{
    if(!pData[playerid][pReturnMoney]) return SendErr(playerid, "Компенсация за имущество не найдена");
	if(pData[playerid][pReturnMoney] > 10000000)  pData[playerid][pReturnMoney] = 100;


	give_money(playerid , pData[playerid][pReturnMoney], "Возврат денег за имущество");

	new zStr[128]; format(zStr, sizeof(zStr), "{FFFF05}Вам было компенсировано {FF05F0}%d рублей {FFFF05}от стоимости списанного имущества",pData[playerid][pReturnMoney]);
	pData[playerid][pReturnMoney] = 0;
	UpdatePlayerData(playerid, "returnmoney", 0);

	return true;
}


CMD:maskirovka(playerid)
{
	if(pData[playerid][pFraction] != 12) return SendInf(playerid, "У Вас нет доступа к служебному инвентарю");
	if(pData[playerid][pRank] < 3) return SendInf(playerid, "Функция доступна только с 3 ранга");
	if(pTemp[playerid][pChangingSkin] == true) return SendInf(playerid, "Функция не доступна в данный момент");
	SPD(playerid,dMaskirovka,2,"{FFDF80}Выбор маскировки","Тамбовская ОПГ\nОреховская ОПГ\nИзмайловская ОПГ\nКурганская ОПГ\nМедведковская ОПГ\nБатыревское ОА\nЮжное ОА\nГражданский 1\nГражданский 2\nГражданский 3\nВернуть свою внешность","Выбрать","Отмена");
    if(GetPVarIntNew(playerid,"seloldsk") > 0) return true;
	SetPVarIntNew(playerid, "OldSkinm", GetPlayerSkin(playerid));
	SetPVarIntNew(playerid,"seloldsk",1);


	return true;
}



CMD:advocats(playerid)
{
	SCM(playerid,COLOR_GREEN,"Адвокаты онлайн:");

	foreach(new i: logged_players)
	{
		if(!IsPlayerConnected(i)) continue;
    	if(pData[i][pFraction] == 11 && pData[i][pRank] == 6 && pData[i][pSubfraction] != 0) {
		new mes[128];
		if(!pData[i][pPhone]) format(mes, sizeof(mes), "Номер телефона: Отсутствует");
		else format(mes, sizeof(mes), "Номер телефона: {FFAF00}%d",pData[i][pPhone]);
		format(mes,sizeof(mes),""cWH"%s %s | %s",gFractionRankName[10][pData[i][pRank]-1],pData[i][pNickname],mes);
		if(pTemp[i][pAFK]) format(mes,sizeof(mes), "%s {ffa800}[AFK: %s]",mes,Converts(pTemp[i][pAFK]));
		SCM(playerid,COLOR_YELLOW,mes);
		}
	}
	return true;
}

CMD:endskin(playerid)
{
    if(GetPVarIntNew(playerid, "askin") > 0)	
    {
		SetPlayerSkin(playerid, pData[playerid][pSkin]);
		SetPVarIntNew(playerid, "askin", 0);
		SendInf(playerid, "Вы выбросили одежду и вернули свою старую!");
	}
	else	
	{
		return SendInf(playerid, "На вас не одета форма");
	}
	return true;
}

CMD:forma(playerid)
{
    if(PlayerForma[playerid] != 0)
    {
		SetPVarIntNew(playerid, "askin", GetPlayerSkin(playerid));
		SetPlayerSkinNA(playerid, PlayerForma[playerid]);
		PlayerPlaySound(playerid, 20803, 0.0, 0.0, 0.0);
		SFCM(playerid, 0xFFDF80FF, "Вы одели форму, введите {809FFF}/endskin {FFDF80}чтобы снять ее");
		PlayerForma[playerid] = 0;
	}
	return true;
}

CMD:fillcar(playerid)
{
	if(!get_inventory_items(playerid, 377))
		return SendErr(playerid, "У вас отсутствует канистра с маслом!");

	foreach(new v:vehicle_in_stream[playerid])
	{	

		new
			Float:pl_pos_x,
			Float:pl_pos_y,
			Float:pl_pos_z;

		GetVehiclePos(v, pl_pos_x, pl_pos_y, pl_pos_z);

		if(IsPlayerInRangeOfPoint(playerid, 2.0, pl_pos_x, pl_pos_y, pl_pos_z))
		{
			new 
				Float:fuel_count_car = vehicle[v][cFuel];

			new 
				max_fuel = transport_config[GetVehicleModel(v)-400][transport_tank];	

			if(max_fuel == floatround(fuel_count_car, floatround_round))
				return SendErr(playerid, "Вы не можете заправить автомобиль!");

			vehicle[v][cFuel] += 15;

			check_remove_inventory(playerid, 377, get_inventory_items_slot(playerid, 377), -1);
			SendSucc(playerid, "Вы заправили транспортное средство топливом!");

		}
		else
		{
			SendErr(playerid, "Рядом с Вами нет транспорта!");
		}
	}

	return true;
}

CMD:filloil(playerid)
{
	if(!get_inventory_items(playerid, 376))
		return SendErr(playerid, "У вас отсутствует канистра с маслом!");

	foreach(new v:vehicle_in_stream[playerid])
	{	

		new
			Float:pl_pos_x,
			Float:pl_pos_y,
			Float:pl_pos_z;

		GetVehiclePos(v, pl_pos_x, pl_pos_y, pl_pos_z);

		if(IsPlayerInRangeOfPoint(playerid, 2.0, pl_pos_x, pl_pos_y, pl_pos_z))
		{
			if(floatround(vehicle[v][consumables_oil], floatround_round) > 65)
				return SendErr(playerid, "Вы не можете заправить автомобиль маслом!");

			vehicle[v][consumables_oil] += 35.0;

			check_remove_inventory(playerid, 376, get_inventory_items_slot(playerid, 376), -1);
			SendSucc(playerid, "Вы заправили транспортное средство маслом!");

		}
		else
		{
			SendErr(playerid, "Рядом с Вами нет транспорта!");
		}
	}

	return true;
}

alias:repaircar("repcar");
CMD:repaircar(playerid)
{
	if(!get_inventory_items(playerid, 8))
		return SendErr(playerid, "У вас отсутствует ремонтный комплект!");

	new 
		vehid = GetPlayerVehicleID(playerid);

	foreach(new v:vehicle_in_stream[playerid])
	{	

		new
			Float:pl_pos_x,
			Float:pl_pos_y,
			Float:pl_pos_z;

		GetVehiclePos(v, pl_pos_x, pl_pos_y, pl_pos_z);

		if(IsPlayerInRangeOfPoint(playerid, 2.0, pl_pos_x, pl_pos_y, pl_pos_z))
		{
			RepairVehicle(v);
			vehicle[v][cHealth] = 1000.0;

			check_remove_inventory(playerid, 8, get_inventory_items_slot(playerid, 8), -1);
			SendSucc(playerid, "Вы починили транспортное средство!");

		}
		else
		{
			SendErr(playerid, "Рядом с Вами нет транспорта!");
		}
	}
	return true;
}



CMD:donate(playerid)
{
	UpdateDonate(playerid);
	if(donate_active_command == 1)
	{
	    format(String2048,sizeof(String2048),"\
	    "cGREY"Услуга\t"cGREY"Стоимость\n\
	    "cBLUE"1."cWH" Игровая валюта\t"cGR"1 RUB - 1200 рублей\n\
	    "cBLUE"2."cWH" Смена ника\t"cGR"50 донат рублей\n\
	    "cBLUE"3."cWH" Смена национальности\t"cGR"75 донат рублей\n\
	    "cBLUE"4."cWH" Смена игрового возраста\t"cGR"50 донат рублей\n\
	    "cBLUE"5."cWH" Смена игрового пола\t"cGR"30 донат рублей\n\
	    "cBLUE"6."cWH" Снятие варна\t"cGR"100 донат рублей\n\
	    "cBLUE"7."cWH" Законопослушность (+10)\t"cGR"25 донат рублей\n\
	    "cBLUE"8."cWH" Решительность\t"cGR"200 донат рублей\n\
	    "cBLUE"9."cWH" Покупка 5-значного номера\t"cGR"3000 донат рублей\n\
	    "cBLUE"10."cWH" Максимальный навык стрельбы\t"cGR"200 донат рублей\n\
	    "cBLUE"11."cWH" Максимальный навык шахтёра\t"cGR"150 донат рублей\n\
	    "cBLUE"12."cWH" Максимальный навык лесоруба\t"cGR"150 донат рублей\n\
	    "cBLUE"13."cWH" Максимальный навык сборщика мебели\t"cGR"150 донат рублей\n\
	    "cBLUE"14."cWH" Максимальный навык снегоуборщика\t"cGR"150 донат рублей\n\
	    "cBLUE"15."cWH" Максимальный навык Пожарного\t"cGR"150 донат рублей\n\
	    "cBLUE"16."cWH" Максимальный навык Инкассатора\t"cGR"150 донат рублей\n\
	    "cBLUE"17."cWH" Максимальный навык Водителя мусоровоза\t"cGR"150 донат рублей\n\
	    "cBLUE"18."cWH" Покупка лицензий на транспорт\t"cGR"150 донат рублей\n\
	    "cBLUE"19."cWH" Покупка лицензии на оружие\t"cGR"150 донат рублей\n\
	    "cBLUE"20."cWH" Дополнительная (2 страница в инвентаре)\t"cGR"150 донат рублей\n\
	    "cBLUE"21."cWH" Дополнительная (3 страница в инвентаре)\t"cGR"250 донат рублей\n\
	    "cBLUE"--."cWH" Проверить баланс\tПроверить\n\
	    "cBLUE"--."cWH" Перейти на сайт пополнения\tПополнить");
		SPD(playerid, dDonate, DIALOG_STYLE_TABLIST_HEADERS, ""cBLUE"Услуги доната", String2048, !"Далее", !"Отмена");
	}
	else
	{
		format(String512, sizeof(String512), "\
		"cWH"Для Вашего же удобства, донат был временно отключен (приблизительно на 2 часа)\n\n\
		Все Ваши пополнения доходят до Ваших аккаунтов!\n\
		Воспользоваться донатом можно будет чуть-чуть позже :)\n\n\
		Пополнение происходит на сайте: b-rp.ru в разделе 'Донат'\n\n\
		На вашем счёте: "cGR"%d рублей", pData[playerid][pDonate]);
		SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Донат", String512, !"Понял", "");	

	}
	return true;
}

CMD:audience(playerid)
{
	if(pData[playerid][pFraction] != 10 && pData[playerid][pFraction] != 11) return true;

	new z[3], zStr[128];
	foreach(new i: logged_players)
	{
	    if(!IsPlayerConnected(i)) continue;
		if(pData[i][pRadio]) z[pData[i][pRadio]-1]++;
	}
	format(zStr, 128, "Радио г. Южный: %d\n\
					Радио г. Эдово: %d\n\
						Радио г. Арзамас: %d\n", z[0], z[1], z[2]);
	SPD(playerid, dMes, 0, "{FFFF9E}Количество слушателей:", zStr, "Ок", "");
	return true;
}

/*CMD:radio(playerid)
{
	if(pData[playerid][pRadio])
	{
		pData[playerid][pRadio] = 0;
		UpdatePlayerData(playerid, "radio", 0);
		SCM(playerid,CDARKGREEN,"Радиоприемник выключен");
	}
	else
	{
        SPD(playerid,dSetRadio,DIALOG_STYLE_LIST,"{FFFF9E}Выбор радиостанции:","Радио г. Южный\nРадио г. Эдово\nРадио г. Арзамас","Выбор","Отмена");
	}
	return true;
}*/

CMD:stopdial(playerid)
{
	if(pData[playerid][pFraction] != 10 || pData[playerid][pSubfraction] == 0) return SendInf(playerid, "Эта функция доступна только сотрудникам СМИ");
	if(pData[playerid][pRank] < 5) return SendInf(playerid, "Принимать звонки можно с пятого ранга");
	if(gNewsDialer[pData[playerid][pSubfraction]-1] != playerid) return SendInf(playerid, "Невозможно");

	if(pData[playerid][pFraction] != 10 || pData[playerid][pSubfraction] == 0) return SendInf(playerid, "Эта функция доступна только сотрудникам СМИ");
	if(gNewsDialee[pData[playerid][pSubfraction]-1] != INVALID_PLAYER_ID) {
	SCM(gNewsDialee[pData[playerid][pSubfraction]-1],CWHITE,"Вы были отсоединены ведущим");
	new zS[128]; format(zS, sizeof(zS), "%s %s отключил слушателя %s от эфира", gFractionRankName[9][pData[playerid][pRank]-1], pData[playerid][pNickname], pData[gNewsDialee[pData[playerid][pSubfraction]-1]][pNickname]);
	foreach(new i: logged_players)
	{
	    if(!IsPlayerConnected(i)) continue;
	    if(pData[i][pFraction] == 10 && pData[i][pSubfraction] == pData[playerid][pSubfraction]) SCM(i, COLOR_ORANGE, zS);
	}
	SetPlayerSpecialAction(gNewsDialee[pData[playerid][pSubfraction]-1],SPECIAL_ACTION_STOPUSECELLPHONE);
	SetTimerEx("ClearPhone",2000,false,"i",gNewsDialee[pData[playerid][pSubfraction]-1]);
	gNewsDialee[pData[playerid][pSubfraction]-1] = INVALID_PLAYER_ID;
	SCM(playerid,CSYSTEM,"Игрок отсоединен");
	}
	gNewsDialing[pData[playerid][pSubfraction]-1] = false;
	gNewsDialer[pData[playerid][pSubfraction]-1] = INVALID_PLAYER_ID;
	gNewsDialee[pData[playerid][pSubfraction]-1] = INVALID_PLAYER_ID;
	gNewsDialPrice[pData[playerid][pSubfraction]-1] = 0;
	new mes[128];
	format(mes,sizeof(mes),"[R] %s закончил принимать звонки. Доход: %d рублей",pData[playerid][pNickname],gNewsDialMoney[pData[playerid][pSubfraction]-1]);
	gNewsMoney[pData[playerid][pSubfraction]-1] += gNewsDialMoney[pData[playerid][pSubfraction]-1];
	SaveNewsMoney();
	gNewsDialMoney[pData[playerid][pSubfraction]-1] = 0;
	foreach(new i: logged_players)
	{
		if(!PlayerConnect[i]) continue;
		if(pData[i][pFraction] == 10) SCM(i,CBLUE,mes);
	}
	return true;
}

CMD:hdial(playerid)
{
	if(pData[playerid][pFraction] != 10 || pData[playerid][pSubfraction] == 0) return SendInf(playerid, "Эта функция доступна только сотрудникам СМИ");
	if(gNewsDialee[pData[playerid][pSubfraction]-1] == INVALID_PLAYER_ID) return SendInf(playerid, "Никого на линии нет");
	SCM(gNewsDialee[pData[playerid][pSubfraction]-1],CWHITE,"Вы были отсоединены ведущим");
	new zS[128]; format(zS, sizeof(zS), "%s %s отключил слушателя %s от эфира", gFractionRankName[9][pData[playerid][pRank]-1], pData[playerid][pNickname], pData[gNewsDialee[pData[playerid][pSubfraction]-1]][pNickname]);

	foreach(new i: logged_players)
	{
	    if(!IsPlayerConnected(i)) continue;
	    if(pData[i][pFraction] == 10 && pData[i][pSubfraction] == pData[playerid][pSubfraction]) SCM(i, COLOR_ORANGE, zS);
	}
	SetPlayerSpecialAction(gNewsDialee[pData[playerid][pSubfraction]-1],SPECIAL_ACTION_STOPUSECELLPHONE);
	SetTimerEx("ClearPhone",2000,false,"i",gNewsDialee[pData[playerid][pSubfraction]-1]);
	gNewsDialee[pData[playerid][pSubfraction]-1] = INVALID_PLAYER_ID;
	SCM(playerid,CSYSTEM,"Игрок отсоединен");

	return true;
}

CMD:indial(playerid, params[])
{
    if(pData[playerid][pFraction] != 10 || pData[playerid][pSubfraction] == 0) return SendErr(playerid, "Команда доступна только сотрудникам СМИ");
    new ndial = pData[playerid][pSubfraction]-1;


	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/indial [ID]");


    new id = params[0];
    if(!IsPlayerConnected(id)) return SendErr(playerid, "Игрок не найден");
    if(GetPVarIntNew(id, "newsdial") != pData[playerid][pSubfraction]) return SendErr(playerid, "Этот игрок не звонил в эфир");
    if(gNewsDialer[ndial] != playerid) return SendErr(playerid, "Вы не ведущий эфира");
    if(!gNewsDialing[ndial]) return SendErr(playerid,"Звонки не принимаются");
    if(gNewsDialee[ndial] != INVALID_PLAYER_ID) return SendErr(playerid,"Линия занята. Чтобы отсоединить игрока от эфира введите /hdial");
    SCM(id,CWHITE,"Вы были подключены к прямому эфиру радиостанции");
    new zS[64]; format(zS, sizeof(zS), "Вы подключили слушателя %s к прямому эфиру", pData[id][pNickname]);
    SendSucc(playerid, zS);
    pData[id][pRadio] = pData[playerid][pSubfraction];
    gNewsDialee[ndial] = id;
	SetPlayerSpecialAction(playerid,SPECIAL_ACTION_USECELLPHONE);
	SetPlayerAttachedObject(playerid,0,330,6);

	return true;
}

CMD:edit(playerid)
{
	if(pData[playerid][pFraction] != 10 || pData[playerid][pRank] < 2) return SendInf(playerid, "Эта функция доступна только сотрудникам СМИ со 2 ранга.");
	ShowAdvertList(playerid);

	return true;
}

CMD:ether(playerid)
{
	if(pData[playerid][pFraction] != 10 || pData[playerid][pSubfraction] == 0) return SendInf(playerid, "Эта функция доступна только сотрудникам СМИ");
	if(!pTemp[playerid][pEther])
	{
		new vehicleid = GetPlayerVehicleID(playerid);
		if(vehicleid >= aNews[0] && vehicleid <= aNews[1]
		|| vehicleid >= aRadio[0] && vehicleid <= aRadio[1]
		|| vehicleid >= aRadio1[0] && vehicleid <= aRadio1[1]
		|| IsPlayerInRangeOfPoint(playerid, 80, 595.7726,1480.4741,1513.0088 )	)
		{
			pTemp[playerid][pEther] = true;
			pData[playerid][pRadio] = pData[playerid][pSubfraction];//-1;
			SCM(playerid,CGREEN,"Вы в эфире {FFF510}(для приема звонков и СМС введите команду /dial)");
		}
		else return SendInf(playerid, "В эфир можно выходить только в служебном транспорте или в специальном помещении");
	}
	else
	{
		pTemp[playerid][pEther] = false;
		new mes[128];
		format(mes,sizeof(mes),"Вы вышли из эфира. Доход за СМС: %d рублей", gNewsDialMoney2[pData[playerid][pSubfraction]-1]);
		SCM(playerid,CGREEN,mes);

		gNewsMoney[pData[playerid][pSubfraction]-1] += gNewsDialMoney2[pData[playerid][pSubfraction]-1];
		SaveNewsMoney();
		gNewsDialMoney2[pData[playerid][pSubfraction]-1] = 0;

	}
	return true;
}

CMD:setspawn(playerid)
{
	if(pData[playerid][pHotelRoom] == -1 && pData[playerid][pFlate] == -1  && pData[playerid][pFlateRent] == -1 && pData[playerid][pSpawn] && pData[playerid][pHouse] == -1 && pData[playerid][pHouseRent] == -1) 
	{
	    UpdatePlayerData(playerid, "spawn", 0);
	    pData[playerid][pSpawn] = 0;
	}
	
	new vertid = -1;

	if(pData[playerid][pHotelRoom] == -1 && pData[playerid][pFlate] == -1  && pData[playerid][pFlateRent] == -1 && pData[playerid][pHouse] == -1 && pData[playerid][pHouseRent] == -1)
	{
	    SendErr(playerid, "Вы не проживаете в доме, квартире и не арендуете номер в отеле.");
		return true;
	}

    if(vertid >= 0) 
    {
		switch(pData[playerid][pSpawn])
		{
		    case 0: SPD(playerid, dSetSpawn, DIALOG_STYLE_LIST, ""cBLUE"Место появления", ""cBLUE"1. "cWH"Дом, квартира или отель\n"cBLUE"2. "cWH"Стандартный спавн", "Выбор", "Отмена");
		    default: SPD(playerid, dSetSpawn, DIALOG_STYLE_LIST, ""cBLUE"Место появления", ""cBLUE"1. "cWH"Стандартный спавн\n"cBLUE"2. "cWH"Дом, квартира или отель", "Выбор", "Отмена");
		}
    }
	else 
	{
		switch(pData[playerid][pSpawn]) 
		{

		    case 0: SPD(playerid, dSetSpawn, DIALOG_STYLE_LIST, ""cBLUE"Место появления", ""cBLUE"1. "cWH"Дом, квартира или отель\n"cBLUE"2. "cWH"Стандартный спавн", "Выбор", "Отмена");
		    default: SPD(playerid, dSetSpawn, DIALOG_STYLE_LIST, ""cBLUE"Место появления", ""cBLUE"1. "cWH"Стандартный спавн\n"cBLUE"2. "cWH"Дом, квартира или отель", "Выбор", "Отмена");
		}
	}
	return true;
}

CMD:showall(playerid) 
{

	return check_player_user_fraction(playerid);
}

stock check_player_user_fraction(playerid, page = 0)
{

	if(page < 0)
	{
		page = 0;
	}


	if(!pData[playerid][pFraction]) 
		return SendInf(playerid, "Вы не состоите в организации.");

	SetPVarIntNew(playerid, "check_page_panel_fraction", page);

	if(pData[playerid][pSubfraction]) 
	{
        if(pData[playerid][pRank] < gFractionRankCount[pData[playerid][pFraction]-1]-1) return SendInf(playerid, "Команда доступна только лидеру организации.");
		format(String2048, sizeof(String2048), "SELECT `nickname`,`rank`,`level`,`datas` FROM `accounts` WHERE `fraction` = %d AND `subfraction` = %d ORDER BY `rank` LIMIT %d,20", pData[playerid][pFraction], pData[playerid][pSubfraction], page*20);
	}
	else 
	{
        if(pData[playerid][pRank] < gFractionRankCount[pData[playerid][pFraction]-1]) return SendInf(playerid, "Команда доступна только лидеру организации.");
		new fractionid = pData[playerid][pFraction] - 1;

		if(!pData[playerid][pSubfraction] && ( fractionid+1 == 8 || fractionid+1 == 9 || fractionid+1 == 10  || fractionid+1 == 2  ) && IsALeader(playerid)) 
		{
			format(String2048, sizeof(String2048), "SELECT `nickname`,`rank`,`level`,`datas` FROM `accounts` WHERE `fraction` = %d ORDER BY `rank` LIMIT %d,20", pData[playerid][pFraction], page*20);
		}
		format(String2048, sizeof(String2048), "SELECT `nickname`,`rank`,`level`,`datas` FROM `accounts` WHERE `fraction` = %d AND `subfraction` = 0 ORDER BY `rank` LIMIT %d,20", pData[playerid][pFraction], page*20);
	}

	
	format(String4096, sizeof(String4096), ""cGREY"№  Уровень\t"cGREY"Имя игрока\t"cGREY"Ранг\t"cGREY"Последний заход\n");

	new Result:r = sql_queryEx(zConn, String2048, QUERY_CACHED);
	new all_trucker_stations = sql_num_rows(r);

    new 
    	trucker_id_all = page*20;


 	for(new i; i < all_trucker_stations; i++)
	{
		
		new nn[MAX_PLAYER_NAME], rank, lvl;
		new lastt[20];
		new typen;

		new onnn = 0;

	    sql_get_field_ex(r, i, 0, nn);
	    rank = sql_get_field_int_ex(r, i, 1);
		lvl = sql_get_field_int_ex(r, i, 2); 
	    sql_get_field_ex(r, i, 3, lastt);

		if(trucker_id_all < 9 ) 
		{
	    	format(String4096, sizeof(String4096), "%s%d.  %d\t%s\t%d\t%s\n",String4096, \
	    	trucker_id_all+1, lvl,nn, rank,lastt);
	    }
	    else			    
	    {
	    	format(String4096, sizeof(String4096), "%s%d.  %d\t%s\t%d\t%s\n",String4096, \
	    	trucker_id_all+1, lvl,nn, rank,lastt);
		}



		trucker_id_all++;

	}
	sql_next_row(r);

	if(all_trucker_stations < 20)
	{
		SetPVarIntNew(playerid, "button_back_personal_fraction", all_trucker_stations);
	}

    if(all_trucker_stations == 20) strcat(String4096, ""cGREY"Далее >>>\n");
    if(page >= 1) strcat(String4096, ""cGREY"<<< Назад");

	SPD(playerid,dMesEx, DIALOG_STYLE_TABLIST_HEADERS ,""cBLUE"Список сотрудников",String4096,"Далее","Закрыть");
	return true;

}

CMD:leave(playerid)
{
    if(!pData[playerid][pFraction]) return SendInf(playerid, "Вы не состоите в организации.");
	if(IsALeader(playerid)) return SendInf(playerid, "Вы не можете уволиться из организации");
	if(!pData[playerid][pUpgrade][0]) return SendErr(playerid,"Вы не можете уволиться из организации без улучшения 'Решительность' (/mn->Улучшения)");
	if(pData[playerid][pJail] > 0) return SCM(playerid,COLOR_WHITE,"Вы не можете уволиться из организации сейчас");

	return SPD(playerid, dLeave, DIALOG_STYLE_INPUT, "{ffff00}Увольнение из организации", "\nВы действительно хотите уволиться из организации?\nВведите причину вашего увольнения:\n\n", "Уволиться", "Отмена");

}

CMD:find(playerid)
{
	new want_text[120],want1;
	if(!pData[playerid][pFraction]) return SendInf(playerid, "Вы не состоите в организации");
	format(want_text,sizeof(want_text),"ID\tУровень\tТелефон\tРанг\tВыговоры\tИмя игрока\n\n");
	format(String4096,sizeof(String4096),"");
	strcat(String4096, want_text);
	new fractionid = pData[playerid][pFraction] - 1;
	new subfraction = GetSubfractionID(fractionid);
	new subfractionid = pData[playerid][pSubfraction] - 1;

	new typeprez;
	if(!pData[playerid][pSubfraction] && ( fractionid+1 == 8 || fractionid+1 == 9 || fractionid+1 == 10  || fractionid+1 == 2  ) && IsALeader(playerid)) {
			typeprez = 1;
	}

	if( pData[playerid][pFraction] == 8 && pData[playerid][pSubfraction] == 0 && IsALeader(playerid)) {//\nВоенно-Морской Флот
			SPD(playerid, dMesVoen, DIALOG_STYLE_LIST, "{ffff00}Члены организации онлайн", "Военно-Воздушные Силы\nСухопутные Войска\nМинистерство обороны", "Выбрать", "Закрыть");
			return true;
	}
	if( pData[playerid][pFraction] == 9 && pData[playerid][pSubfraction] == 0 && IsALeader(playerid)) {
			SPD(playerid, dMesVoen, DIALOG_STYLE_LIST, "{ffff00}Члены организации онлайн", "МВД г.Южный\nМВД г.Арзамас\nМВД п.Батырево\nМинистерство внутренних дел", "Выбрать", "Закрыть");
			return true;
	}
	if( pData[playerid][pFraction] == 2 && pData[playerid][pSubfraction] == 0 && IsALeader(playerid)) {
			SPD(playerid, dMesVoen, DIALOG_STYLE_LIST, "{ffff00}Члены организации онлайн", "Больница г.Южный\nБольница г.Арзамас\nБольница п.Батырево\nМинздрав", "Выбрать", "Закрыть");
			return true;
	}
	if( pData[playerid][pFraction] == 10 && pData[playerid][pSubfraction] == 0 && IsALeader(playerid)) {
			SPD(playerid, dMesVoen, DIALOG_STYLE_LIST, "{ffff00}Члены организации онлайн", "Радиоцентр г.Южный\nРадиоцентр г.Эдово\nРадиоцентр г.Арзамас\nНовостная сеть", "Выбрать", "Закрыть");
			return true;
	}
	if( pData[playerid][pFraction] == 11 && pData[playerid][pSubfraction] == 0 && IsALeader(playerid)) {
			SPD(playerid, dMesVoen, DIALOG_STYLE_LIST, "{ffff00}Члены организации онлайн", "Мэрия г.Южный\nМэрия г.Арзамас\nМэрия п.Батырево\nАдминистрация Президента", "Выбрать", "Закрыть");
			return true;
	}

	if( pData[playerid][pFraction] == 11 && pData[playerid][pSubfraction] == 0 && pData[playerid][pRank] == 5) {
			SPD(playerid, dMesVoen2, DIALOG_STYLE_LIST, "{ffff00}Члены организации онлайн", "МВД г.Южный\nМВД г.Аразамас\nМВД п.Батырево\nМинистерство внутренних дел\nАдминистрация Президента", "Выбрать", "Закрыть");
			return true;
	}
	if( pData[playerid][pFraction] == 11 && pData[playerid][pSubfraction] == 0 && pData[playerid][pRank] == 6) {
			SPD(playerid, dMesVoen2, DIALOG_STYLE_LIST, "{ffff00}Члены организации онлайн", "Военно-Воздушные Силы\nСухопутные Войска\nВоенно-Морской Флот\nМинистерство обороны\nАдминистрация Президента", "Выбрать", "Закрыть");
			return true;
	}
	if( pData[playerid][pFraction] == 11 && pData[playerid][pSubfraction] == 0 && pData[playerid][pRank] == 7) {
			SPD(playerid, dMesVoen2, DIALOG_STYLE_LIST, "{ffff00}Члены организации онлайн", "Радиоцентр г.Южный\nРадиоцентр г.Эдово\nРадиоцентр г.Арзамас\nНовостная сеть\nАдминистрация Президента", "Выбрать", "Закрыть");
			return true;
	}
	if( pData[playerid][pFraction] == 11 && pData[playerid][pSubfraction] == 0 && pData[playerid][pRank] == 8) {
			SPD(playerid, dMesVoen2, DIALOG_STYLE_LIST, "{ffff00}Члены организации онлайн", "Больница г.Южный\nБольница г.Арзамас\nБольница п.Батырево\nМинздрав\nАдминистрация Президента", "Выбрать", "Закрыть");
			return true;
	}
	foreach(new i: logged_players)
	{
	    if(!IsPlayerConnected(i)) continue;
	    if(pData[i][pAdmin] > 0) continue;
	    if(subfraction == -1)
		{


			if(pData[i][pFraction] != fractionid+1) continue;
			if(pData[i][pFraction] != 9) pData[i][pDivision] = 0;
			if(pData[i][pPhone] > 0)
			{
				if(pTemp[i][pAFK] > 1)
				{
			    	format(want_text,sizeof(want_text), ""cWH"%d\t%i\t\t%d\t\t%d %s\t%d/3\t%s {ffa800}[AFK: %s]"cWH"\n", i,pData[i][pLevel], pData[i][pPhone], pData[i][pRank],DivisionEx[pData[i][pDivision] ], pData[i][pFWarn], pData[i][pNickname], Converts(pTemp[i][pAFK]));
				}
				else
				{
			    	format(want_text,sizeof(want_text), ""cWH"%d\t%i\t\t%d\t\t%d %s\t%d/3\t%s\n", i, pData[i][pLevel], pData[i][pPhone], pData[i][pRank],DivisionEx[pData[i][pDivision] ], pData[i][pFWarn], pData[i][pNickname]);
				}
			}
			else
			{
				if(pTemp[i][pAFK] > 1)
				{
					format(want_text,sizeof(want_text), ""cWH"%d\t%d\t\tNone\t\t%d %s\t%d/3\t%s {ffa800}[AFK: %s]"cWH"\n", i,pData[i][pLevel], pData[i][pRank],DivisionEx[pData[i][pDivision] ], pData[i][pFWarn], pData[i][pNickname],Converts(pTemp[i][pAFK]));
				}
				else
				{
					format(want_text,sizeof(want_text), ""cWH"%d\t%d\t\tNone\t\t%d %s\t%d/3\t%s\n",i, pData[i][pLevel],pData[i][pRank],DivisionEx[pData[i][pDivision] ], pData[i][pFWarn], pData[i][pNickname]);
				}
			}
			strcat(String4096, want_text);
			want1+=1;
		}
		else
		{
		    if(pData[i][pFraction] != fractionid+1 || (pData[i][pSubfraction] != subfractionid + 1 && !typeprez)) continue;
			if(pData[i][pFraction] != 9) pData[i][pDivision] = 0;
			if(pTemp[i][pAFK] < 2)
		    {
		    if(pData[i][pPhone] > 0) format(want_text,sizeof(want_text), ""cWH"%d\t%d\t\t%i\t\t%d %s\t%d/3\t%s\n", i,pData[i][pLevel], pData[i][pPhone], pData[i][pRank],DivisionEx[pData[i][pDivision] ], pData[i][pFWarn], pData[i][pNickname]);
			else format(want_text,sizeof(want_text), ""cWH"%d\t%d\tNone\t\t%d %s\t%d/3\t%s\n", i,pData[i][pLevel], pData[i][pRank],DivisionEx[pData[i][pDivision] ], pData[i][pFWarn], pData[i][pNickname]);
			}
			else
			{
		    if(pData[i][pPhone] > 0) format(want_text,sizeof(want_text), ""cWH"%d\t%d\t\t%i\t\t%d %s\t%d/3\t%s {ffa800}[AFK: %s]"cWH"\n", i,pData[i][pLevel], pData[i][pPhone], pData[i][pRank],DivisionEx[pData[i][pDivision] ], pData[i][pFWarn], pData[i][pNickname],Converts(pTemp[i][pAFK]));
			else format(want_text,sizeof(want_text), ""cWH"%d\t%d\tNone\t\t%d %s\t%d/3\t%s {ffa800}[AFK: %s]"cWH"\n", i,pData[i][pLevel], pData[i][pRank],DivisionEx[pData[i][pDivision]], pData[i][pFWarn], pData[i][pNickname],Converts(pTemp[i][pAFK]));
			}

			strcat(String4096, want_text);
			want1+=1;
		}
	}
	if(want1 == 0) strcat(String4096, ""cWH"Информация не найдена");
	format(String4096, sizeof(String4096), ""cWH"Всего Online: {f0e48d}%d\n%s",want1,String4096);
	SPD(playerid, dMes, DIALOG_STYLE_MSGBOX, "{ffff00}Члены организации онлайн", String4096, "Закрыть", "");


	return true;

}

CMD:ssf(playerid)
{
    if(pData[playerid][pFraction] != 11 || (pData[playerid][pRank] < 4 || pData[playerid][pRank] > 8)) return SendInf(playerid, "Ошибка: Вам недоступна эта функция");
	if(pData[playerid][pMut]) return SendInf(playerid, "Ошибка: У Вас бан чата.  Используйте /mutetime чтобы узнать время бана.");
	if(pTemp[playerid][pTied] == 1) { return SCM(playerid, COLOR_GREY, "Вы не можете достать рацию!"); }
	if(pTemp[playerid][pCuffee] == playerid) return SendInf(playerid, "Вы в наручниках");
	if(pTemp[playerid][pDChat] == 0)	{

	if(pData[playerid][pRank] == 5)       						{
	SendInf(playerid, "Вы подключили рацию МВД"); pTemp[playerid][pDChat] = 12;	}
	else if(pData[playerid][pRank] == 6)       					{
	SendInf(playerid, "Вы подключили рацию МО");	 pTemp[playerid][pDChat] = 8;	}
	else if(pData[playerid][pRank] == 7)       					{
	SendInf(playerid, "Вы подключили рацию СМИ"); pTemp[playerid][pDChat] = 10;	}
	else if(pData[playerid][pRank] == 8)       					{
	SendInf(playerid, "Вы подключили рацию МЗ");	 pTemp[playerid][pDChat] = 2;	}
	else if(pData[playerid][pRank] == 4)       					{
	SendInf(playerid, "Вы подключили рацию АШ");	 pTemp[playerid][pDChat] = 1;	}
	}
	else if(pTemp[playerid][pDChat] != 0)	{
	pTemp[playerid][pDChat] = 0;
	if(pData[playerid][pRank] == 5)       						{
	SendInf(playerid, "Вы отключили рацию МВД");	}
	else if(pData[playerid][pRank] == 6)       					{
	SendInf(playerid, "Вы отключили рацию МО");		}
	else if(pData[playerid][pRank] == 7)       					{
	SendInf(playerid, "Вы отключили рацию СМИ");	}
	else if(pData[playerid][pRank] == 8)       					{
	SendInf(playerid, "Вы отключили рацию МЗ");		}
	else if(pData[playerid][pRank] == 4)       					{
	SendInf(playerid, "Вы отключили рацию АШ");		}
	}
    return true;
}


CMD:divorce(playerid)
{
	if(!IsPlayerInRangeOfPoint(playerid,2,1879.9982,1170.7963,30.0087)) return SCM(playerid,0xff2400ff,"Вы не в церкви");
	new string[128];
	if(pData[playerid][pMarried] == 0) return SCM(playerid, 0xff2400ff, "Вы не состоите в браке.");
	format(string,sizeof(string),""cWH"Ваша вторая половина: {adff2f}%s\n\n"cWH"Желаете расторгнуть брак?",pData[playerid][pDivorce]);
	return SPD(playerid,1217,DIALOG_STYLE_MSGBOX ,"{cc33ff}Семейное положение",string,"Развод","Отмена");
}

CMD:time(playerid)
{
	if(!get_inventory_items(playerid, 2))
		return SendErr(playerid, "У вас отсутствуют часы!");

	new
		year, month, day,
		hour, minute, second,
		saturday = 1310155200, w = gettime(), day_week;

	getdate(year, month, day);
	gettime(hour, minute, second);
	
	while(w - saturday > 60 * 60 * 24)
    {
        w -= 60 * 60 * 24;
        day_week ++;
    }
    while(day_week >= 7) day_week -= 7;
    


	static name_month[12][12] = {"января","февраля","марта","апреля","мая","июня","июля","августа","сентября","октября","ноября","декабря"};
	static name_day[7][12] = {"суббота","воскресенье","понедельник","вторник","среда","четверг","пятница"};

	new mes[24];

	new 
		temp_string[1024],
		other_string[256];

	format(other_string, sizeof(other_string), ""cWH"Текущее время: "cBLUE"%02d:%02d:%02d\n", hour, minute, second);
	strcat(temp_string, other_string);
	
	format(other_string, sizeof(other_string), ""cWH"Текущая дата: "cBLUE"%d %s %04d г. - %s\n\n", day, name_month[month-1], year, name_day[day_week]);
	strcat(temp_string, other_string);
	
	format(other_string, sizeof(other_string), ""cWH"Время в игре за час: "cBLUE"%s\n", time_to_words(pData[playerid][hour_played]));
	strcat(temp_string, other_string);
	
	format(other_string, sizeof(other_string), ""cWH"Время в игре за сегодня: "cBLUE"%s\n", time_to_words(get_player_day_online(playerid)));
	strcat(temp_string, other_string);
	
	format(other_string, sizeof(other_string), ""cWH"Время в игре за вчера: "cBLUE"%s\n", time_to_words(get_player_day_prew_online(playerid)));
	strcat(temp_string, other_string);

	format(other_string, sizeof(other_string), ""cWH"Время в игре за неделю: "cBLUE"%s\n\n", time_to_words(get_player_week_online(playerid)));
	strcat(temp_string, other_string);
	
	if(pData[playerid][pMut])
	{
		format(other_string, sizeof(other_string), ""cWH"Время мута: "cBLUE"%d минут\n", pData[playerid][pMut]);
		strcat(temp_string, other_string);
	} 
	if(pData[playerid][pMutFamily])
	{
		format(other_string, sizeof(other_string), ""cWH"Время мута чата семьи: "cBLUE"%d минут\n", pData[playerid][pMutFamily]);
		strcat(temp_string, other_string);
	} 
	if(pData[playerid][pMutTK])
	{
		format(other_string, sizeof(other_string), ""cWH"Время мута чата ТК: "cBLUE"%d минут\n", pData[playerid][pMutTK]);
		strcat(temp_string, other_string);
	} 
	if(pData[playerid][pMutTaxi])
	{
		format(other_string, sizeof(other_string), ""cWH"Время мута чата СТО: "cBLUE"%d минут\n", pData[playerid][pMutTaxi]);
		strcat(temp_string, other_string);
	} 
	if(pData[playerid][pMutMech])
	{
		format(other_string, sizeof(other_string), ""cWH"Время мута чата Такси: "cBLUE"%d минут\n", pData[playerid][pMutMech]);
		strcat(temp_string, other_string);
	} 

	if(pData[playerid][pJail])
	{
		format(other_string, sizeof(other_string), ""cWH"Осталось сидеть: "cBLUE"%s\n\n", time_to_words(pData[playerid][pJail]));
		strcat(temp_string, other_string);
	}

	format(other_string, sizeof(other_string), ""cWH"Отыграно для акции Х2 зарплаты за 3 часа игры: "cBLUE"%s\n\n", time_to_words(get_player_day_online(playerid)));
	strcat(temp_string, other_string);

	if(!pData[playerid][ActionStatusMoney])
	{
		format(other_string, sizeof(other_string), ""cWH"Отыграно для бонуса за 10 часов: "cBLUE"%s\n\n", time_to_words(pData[playerid][ActionTimeMoney]));
		strcat(temp_string, other_string);
	}

	if(!pData[playerid][pPlayrCarStatus])
	{
		format(other_string, sizeof(other_string), ""cWH"Отыграно для получения машины: "cBLUE"%s из 20 часов (До 5-го уровня)\n\n", time_to_words(pData[playerid][pPlayCar]));
		strcat(temp_string, other_string);		
	}
	if(!pData[playerid][pPlayOnlineDonateStatus])
	{
		format(other_string, sizeof(other_string), ""cWH"Отыграно для получения 200 доната: "cBLUE"%s из 5 часов (С 15:00 до 00:00)\n\n", time_to_words(pData[playerid][pPlayOnlineDonate]));
		strcat(temp_string, other_string);		
	}

	/*if(hour >= 15 && minute >= 0 && second >= 1 || hour < 0 && minute < 1 && second < 1)
	{
		format(other_string, sizeof(other_string), "Осталось сидеть: "cBLUE"%s\n\n", time_to_words(pData[playerid][pJail]));
		strcat(temp_string, other_string);		
	}*/

	SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Часы", temp_string, !"Закрыть", "");	

	if(minute < 10) {
	if(day < 10) {
	format(mes,sizeof(mes),"%d:0%d ~n~~b~0%d-0%d-%d",hour,minute,day,month,year);
	if(month > 10)		{
	format(mes,sizeof(mes),"%d:0%d ~n~~b~0%d-%d-%d",hour,minute,day,month,year);
	}
	}
	else		{
	format(mes,sizeof(mes),"%d:0%d ~n~~b~%d-0%d-%d",hour,minute,day,month,year);		}
	if(month > 10)		{
	format(mes,sizeof(mes),"%d:0%d ~n~~b~%d-%d-%d",hour,minute,day,month,year);
	}

	}
	else
	{
	if(day < 10) {
	format(mes,sizeof(mes),"%d:%d ~n~~b~0%d-%d-%d",hour,minute,day,month,year);		}
	else		{
	format(mes,sizeof(mes),"%d:%d ~n~~b~%d-%d-%d",hour,minute,day,month,year);		}
	}
	GameTextForPlayer(playerid,mes,5000,1);
	if(!pTemp[playerid][pAntiDM] && !pTemp[playerid][pWater] && pTemp[playerid][pHolder] == INVALID_PLAYER_ID) ApplyAnimation(playerid,"COP_AMBIENT","Coplook_watch",4.1,0,0,0,0,2000,1);
    return true;
}

CMD:mutetime(playerid)
{
	if(pData[playerid][pMut])
	{
		new 
			fmt_str[144];

		format(fmt_str,sizeof(fmt_str),"Бан чата: %d минут.",pData[playerid][pMut]);
		SCM(playerid,0xFF9945FF,fmt_str);
	}
	else
	{
		SCM(playerid,-1,"У вас нет бана чата");
	}
    return true;
}



CMD:klist(playerid)
{
	if(!pData[playerid][pKlist]) 
	{
		pData[playerid][pKlist] = 1;
	    UpdatePlayerData(playerid, "klist", pData[playerid][pKlist]);
	    SendSucc(playerid, "Вы включили отображение убийств");
	}
	else 
	{
	    pData[playerid][pKlist] = 0;
	    UpdatePlayerData(playerid, "klist", 0);
	    SendSucc(playerid, "Вы выключили отображение убийств");
	}

	return true;
}

CMD:leaders(playerid)
{
	new	zVal;
	format(String4096, sizeof(String4096), "Организация - Должность - Имя - Телефон\n\n"cWH"");
	foreach(new i: logged_players)
	{
			if(!PlayerConnect[i]) continue;
			if(pData[i][pAdmin] > 0) continue;
			if(pData[i][pFraction] && IsALeader(i)) 
			{
			if(pData[i][pSubfraction]) {
			if(pData[i][pFraction] == 8 && pData[i][pSubfraction] == 3)    {
			if(pTemp[i][pAFK] < 2) format(String4096, sizeof(String4096), "%s%s - %s - %s [%d] - %d\n", String4096, gSubfractionName[GetSubfractionID(pData[i][pFraction]-1)][pData[i][pSubfraction]-1], gVmfRankName[pData[i][pRank]-1], pData[i][pNickname],i, pData[i][pPhone]);
 			else format(String4096,sizeof(String4096), "%s%s - %s - %s [%d] - %d {ffa800}[AFK: %s]"cWH"\n", String4096, gSubfractionName[GetSubfractionID(pData[i][pFraction]-1)][pData[i][pSubfraction]-1], gVmfRankName[pData[i][pRank]-1], pData[i][pNickname],i, pData[i][pPhone], Converts(pTemp[i][pAFK]));
			}
			else {
			if(pTemp[i][pAFK] < 2) format(String4096, sizeof(String4096), "%s%s - %s - %s [%d] - %d\n", String4096, gSubfractionName[GetSubfractionID(pData[i][pFraction]-1)][pData[i][pSubfraction]-1], gFractionRankName[pData[i][pFraction]-1][pData[i][pRank]-1], pData[i][pNickname],i, pData[i][pPhone]);
 			else format(String4096,sizeof(String4096), "%s%s - %s - %s [%d] - %d {ffa800}[AFK: %s]"cWH"\n", String4096, gSubfractionName[GetSubfractionID(pData[i][pFraction]-1)][pData[i][pSubfraction]-1], gFractionRankName[pData[i][pFraction]-1][pData[i][pRank]-1], pData[i][pNickname],i, pData[i][pPhone], Converts(pTemp[i][pAFK]));
			}
		    }
			else 
			{
				if(pTemp[i][pAFK] < 2) format(String4096, sizeof(String4096), "%s%s - %s - %s [%d] - %d\n", String4096, gFractionName[pData[i][pFraction]-1], gFractionRankName[pData[i][pFraction]-1][pData[i][pRank]-1], pData[i][pNickname],i, pData[i][pPhone]);
				else format(String4096, sizeof(String4096), "%s%s - %s - %s [%d] - %d {ffa800}[AFK: %s]"cWH"\n", String4096, gFractionName[pData[i][pFraction]-1], gFractionRankName[pData[i][pFraction]-1][pData[i][pRank]-1], pData[i][pNickname],i, pData[i][pPhone], Converts(pTemp[i][pAFK]));
			}
		}

			zVal++;
	}
	if(!zVal) return SCM(playerid,-1,"Все лидеры находятся не в игре.");
	SPD(playerid, dMes, DIALOG_STYLE_MSGBOX, "{ffff00}Лидеры", String4096, "Закрыть", "");
	return true;
}


CMD:wanted(playerid)
{
	if(!IsACop(playerid)) 
		return SendInf(playerid, "Эта функция только для МВД/ФСБ");

	return true;

}

CMD:wantedtest(playerid)
{
	if(!IsACop(playerid)) return SendInf(playerid, "Эта функция только для МВД/ФСБ");
	new test[5];
	format(String1024, sizeof(String1024), "\tДело\tИмя преступника\tУровень розыска\n\n");
	pTemp[playerid][pListwanted] = 0;
	new wwan;
	foreach(new i: logged_players)
	{
		if(wwan > 40  || strlen(String1024) > 980) { pTemp[playerid][pListwanted] = i; break; }
		wwan ++;
		if(strlen(pData[i][pNickname]) < 14) test = "\t";
		else test = "";
		format(String1024, sizeof(String1024), "%s\t\t%d\tPlayer Name\t%s%d\n",String1024,i,test,random(6)+1);
    }
    if(wwan > 40) 
    {
		SPD(playerid,dMesEx2,0,"{FFFF9E}Список преступников",String1024,"Далее","Закрыть");
		return true;
	}
	SPD(playerid,0000,0,"{FFFF9E}Список преступников",String1024,"Закрыть","");
	return true;
}

CMD:ptime(playerid)
{
	if(!pData[playerid][pJail]) return SendInf(playerid, "Вы не находитесь в КПЗ");
	new mes[128],jailname[50];
	switch(pData[playerid][pPrison])
	{
		case 0: jailname = "МВД ЮЖНЫЙ";
		case 1: jailname = "МВД АРЗАМАС";
		case 4: jailname = "~g~ALCATRAZ";
	}
	ToRus(jailname);
	if(pData[playerid][pJail] > 60*60)
	{
	format(mes,sizeof(mes),"~g~%s~n~~w~ОСТАТОК: ~g~%d ~w~МИН",jailname,pData[playerid][pJail]/60);
		}
	else if(pData[playerid][pJail] > 60)
	{
	format(mes,sizeof(mes),"~g~%s~n~~w~ОСТАТОК: ~g~%d ~w~МИН",jailname,pData[playerid][pJail]/60);
	}

	else {
	format(mes,sizeof(mes),"~g~%s~n~~w~ОСТАТОК: ~g~%d ~w~СЕК",jailname,pData[playerid][pJail]);
	}
	ToRus(mes);
	GameTextForPlayer(playerid,mes,1,1);

	return true;
}

CMD:stop(playerid)
{
	StopAudioStreamForPlayer(playerid);
	SCM(playerid,CGREEN,"Онлайн-Радио выключено");

	return true;
}

CMD:healme(playerid)
{
	if(!get_inventory_items(playerid, 1))
		return SendErr(playerid, "У вас отсутствует аптечка!");


    pTemp[playerid][pAnimation] = 0;

	SetPlayerHealth(playerid,100.0);

	check_remove_inventory(playerid, 1, get_inventory_items_slot(playerid, 1), -1);

	MeAction(playerid,"перебинтовал рану");
	ApplyAnimation(playerid,"ped","gum_eat",4.0,0,0,0,0,0,1);
    return true;
}

CMD:troff(playerid)
{
	if(pData[playerid][pTaxi] < 1 && pData[playerid][pTruck] < 1  && pData[playerid][pMech] < 1) return SendInf(playerid, "Ошибка: Вам недоступна эта функция");
	if(pTemp[playerid][pTROFF] > 0 )
	{
		pTemp[playerid][pTROFF] = 0;
		if(pData[playerid][pTaxi] > 0)
		{
			SendInf(playerid, "Вы включили рацию таксистов");
		}
		else if(pData[playerid][pMech] > 0)
		{
			SendInf(playerid, "Вы включили рацию механиков");
		}
		else
		{
			SendInf(playerid, "Вы включили рацию дальнобойщиков");
		}

	}
	else
	{
		pTemp[playerid][pTROFF] = 1;
		if(pData[playerid][pTaxi] > 0)
		{
			SendInf(playerid, "Вы выключили рацию таксистов");
		}
		else if(pData[playerid][pMech] > 0)
		{
			SendInf(playerid, "Вы выключили рацию механиков");
		}
		else
		{
		SendInf(playerid, "Вы выключили рацию дальнобойщиков");
		}
	}

	return true;
}

CMD:en(playerid)
{


	new 
		carid = GetPlayerVehicleID(playerid);

	if(GetPVarIntNew(playerid, "RegInRace") == 1)
		return SendErr(playerid, "Запрещено использовать данную команду во время гонки!");

	if(GetPVarIntNew(playerid, "player_load_trucker") == 1)
		return SendErr(playerid, "Запрещено использовать данную команду во время загрузки фуры!");
			

	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) 
		return SendErr(playerid,"Вы должны быть на водительском месте");

	if(get_vehicle_type(carid) == TYPE_BYCICLE) 
		return false;


	if(GetVehicleModel(carid) != TYPE_TESLA_1)
	{

		if(GetPVarIntNew(playerid, "car_in_filling_station") == 1)
			return SendErr(playerid, "Запрещено заводить машину во время заправки!");

		if(vehicle[carid][cFuel] <= 0.0) 
		{	
			vehicle_engine_status(carid, false);
			show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:info_gui_vehicle_fuel", 3000);
			SPD(playerid, 0, 0, ""cBLUE"Недостаточно топлива", ""cWH"В двигателе недостаточно топлива, чтобы завести его!\n\n\
			Вызовите механиков или купите канистру с топливом на АЗС!", !"Закрыть", "");
			return GameTextForPlayer(playerid, "~b~NO FUEL", 2000, 3);
		}
    

		if(vehicle[carid][consumables_oil] <= 0.0)
		{
			new mese[90];
			format(mese,sizeof(mese),"пытается завести двигатель «%s»", transport_config[GetVehicleModel(carid)-400][transport_name]);
			MeAction(playerid ,mese);

			show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:info_gui_vehicle_oil", 3000);
			vehicle_engine_status(carid, false);
			GameTextForPlayer(playerid, "~b~NO OIL", 2000, 1);
			SPD(playerid, 0, 0, ""cBLUE"Недостаточно масла", ""cWH"В двигателе недостаточно масла, чтобы завести его!\n\n\
			Вызовите механиков или купите канистру с маслом на АЗС!", !"Закрыть", "");
			return SendErr(playerid, "В двигателе недостаточно масла, чтобы завести его!");
		}


		if(vehicle[carid][consumables_oil] <= 2.0)
		{
			SendInf(playerid, "В двигателе осталось слишком мало масло. Посетите СТО!");
		}
	}
	else
	{
		if(GetPVarIntNew(playerid, "car_in_filling_station") == 1)
			return SendErr(playerid, "Запрещено заводить машину во время зарядки!");

		if(vehicle[carid][cEnergy] <= 0.0) 
			return GameTextForPlayer(playerid, "~b~NO ENERGY", 2000, 3);

		if(vehicle[carid][cEnergy] <= 10.0) 
		{
			SendInf(playerid, "У вас слишком мало заряда батареи! Посетите зарядную станцию!");
		}

		if(vehicle[carid][cBatteryEnergy] < 50.0)
		{		
			SendInf(playerid, "Уровень изношенности батареи больше 50 процентов, советуем заранее посетить СТО!");
			SendInf(playerid, "Из-за высокого уровня изношенности батареи, расход увеличивается и заряд тратится быстрее!");
		}
		else if(vehicle[carid][cBatteryEnergy] < 10.0)
		{		
			SendInf(playerid, "Уровень изношенности батареи больше 90 процентов, советуем заранее посетить СТО!");
			SendInf(playerid, "Из-за высокого уровня изношенности батареи, расход увеличивается и заряд тратится быстрее!");
		}

		new mese[90];
		format(mese,sizeof(mese),"пытается завести двигатель «%s»", transport_config[GetVehicleModel(carid)-400][transport_name]);
		MeAction(playerid ,mese);


	}


    new 
    	Float:car_health;
	GetVehicleHealth(carid, car_health);

    if(car_health <= 350.0)
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:info_gui_vehicle_repair", 3000);
		SPD(playerid, 0, 0, ""cBLUE"Машина повреждена", ""cWH"Машина слишком сильно повреждена, Вы не можете продолжать движение!", !"Закрыть", "");
 
		new mese[90];
		format(mese,sizeof(mese),"пытается завести двигатель «%s»", transport_config[GetVehicleModel(carid)-400][transport_name]);
		MeAction(playerid ,mese);

		vehicle_engine_status(carid, false);
		SetVehicleHealth(carid, 300.0);
		return true;
	}

	vehicle_engine_status(carid, !vehicle[carid][cEngine]);
	return true;
}


CMD:id(playerid, params[])
{
    if(isnull(params)) 
		return SendInf(playerid, "/id [ID/Никнейм]");

	new 
		nickname[MAX_PLAYER_NAME+1],
		string[100],
		id = INVALID_PLAYER_ID;

	sscanf(params, "i", id);

	if(id != INVALID_PLAYER_ID)
	{
		if(!IsPlayerConnected(id)) 
        	return SendErr(playerid,"Неверный ID");

        if(pData[id][pAdmin])
        	return SendErr(playerid,"Неверный ID");

        SendClientMessage(playerid, CBLUE, !"Игроки онлайн:");

        GetPlayerName(id, nickname, MAX_PLAYER_NAME);

        if(pTemp[id][pAFK] > 3) 
            format(string, sizeof(string), "%s[%d] [№%d] - "cBLUE"AFK: %s", nickname, id, pData[id][pMysqlID], Converts(pTemp[id][pAFK]));
        else 
        	format(string, sizeof(string), "%s[%d] [№%d]", nickname, id, pData[id][pMysqlID]);

        SendClientMessage(playerid, CWHITE, string);
	}
	else
	{
		new 
			count;

		SendClientMessage(playerid, CBLUE, !"Игроки онлайн:");
		foreach(new i:Player)
        {
            if(!IsPlayerConnected(i))
            	continue;

            if(pData[i][pAdmin])
            	continue;

	        if(count > 5)
	        {
	            count++;
	            continue;
	        }
	        if(GetPlayerName(i, nickname, MAX_PLAYER_NAME)) 
	        {
		  		if(strfind(nickname, params, true) != -1)
		  		{
		            count++;
		            if(pTemp[i][pAFK] > 3) 
		            	format(string, sizeof(string), "%s[%d] [№%d] - "cBLUE"AFK: %s", pData[i][pNickname], i, pData[i][pMysqlID], Converts(pTemp[i][pAFK]));
		            else 
		            	format(string, sizeof(string), "%s[%d] [№%d]", pData[i][pNickname], i, pData[i][pMysqlID]);
		            SendClientMessage(playerid, CWHITE, string);
		        }
		    }
        }

        if(count == 0) 
        	return SendErr(playerid, "Ничего не найдено");

        else if(count > 5)
        {
            format(string, sizeof(string), "Показано 5 найденных");
            SendInf(playerid, string);
        }
	}
	return true;
}

CMD:offlback(playerid, params[])
{
	if( pData[playerid][pFraction] < 1 ) return 1;

	new h; gettime(h);
    if(pData[playerid][pRank] < gFractionRankCount[pData[playerid][pFraction]-1]) return SendClientMessage(playerid,CGRAY,"Команда доступна только лидеру организации.");
	new faction = pData[playerid][pFraction]-1;

	if(sscanf(params, "s[32]", params[0])) 
	{	
		return SendInf(playerid, "/offlback [Ник]");
	}	

	sql_escape_string(zConn, params[0], params[0], 128);

	format(String512,sizeof(String512),"SELECT `id`,`fraction`,`blist2` FROM `accounts` WHERE `nickname` = '%s'",params[0]);
	new Result:r = sql_queryEx(zConn, String512, QUERY_CACHED);
	if(!sql_num_rows(r)) {
	sql_free_result(r);
	return SendClientMessage(playerid,CGRAY,"Неверный Ник");}

	new SIDS = sql_get_field_int(r, 0);
	new SFRAC = sql_get_field_int(r, 1);
	new SBLAKLIST[150];
	sql_get_field(r, 2, SBLAKLIST );
	sql_free_result( r );

	new SBLAKLISTPL[15];
    sscanf(SBLAKLIST, "p<,>a<i>[15]", SBLAKLISTPL ); //Считываем чс


	foreach(Player, x)
	{
	    if( pData[x][pMysqlID] == SIDS ) return SendClientMessage(playerid,CGRAY,"Данный игрок Online");
	}


	if(SFRAC == pData[playerid][pFraction] ) return SendClientMessage(playerid,CGRAY,"Игрок состоит в вашей фракции");

	if( SBLAKLISTPL[faction] == 0 )
	{
	SBLAKLISTPL[faction] = 1;
	format(String256, sizeof(String256), "Вы добавили %s в черный список фракции", params[0] );
	SendSucc(playerid, String256);

	format(String256, sizeof(String256), "%s добавил %s в черный список фракции", pData[playerid][pNickname], params[0]);
	SendFMes(pData[playerid][pFraction],CBLUE, String256);

	}
	else if( SBLAKLISTPL[faction] != 0 )
	{
		SBLAKLISTPL[faction] = 0;
		format(String256, sizeof(String256), "Вы убрали %s из черного списка фракции", params[0]);
		SendSucc(playerid, String256);
		format(String256, sizeof(String256), "%s убрал %s из черного списка фракции", pData[playerid][pNickname], params[0] );
		SendFMes(pData[playerid][pFraction],CBLUE, String256);

	}
	new SETBLACK[150];

	format(SETBLACK,150,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
	SBLAKLISTPL[0],SBLAKLISTPL[1],SBLAKLISTPL[2],
	SBLAKLISTPL[3],SBLAKLISTPL[4],
	SBLAKLISTPL[5],SBLAKLISTPL[6],SBLAKLISTPL[7],
	SBLAKLISTPL[8],SBLAKLISTPL[9],
	SBLAKLISTPL[10],SBLAKLISTPL[11],SBLAKLISTPL[12],
	SBLAKLISTPL[13],SBLAKLISTPL[14]			);
	format(String1024,sizeof(String1024),"UPDATE `accounts` SET `blist2`='%s' WHERE `nickname`='%s'",SETBLACK , params[0] );
	sql_queryEx(zConn, String1024, QUERY_THREADED);


	return true;
}

CMD:setsex(playerid, params[])
{

	if(sscanf(params, "dd", params[0], params[1])) 
	{	
		return SendInf(playerid, "/setsex [ID] [Пол]");
	}	

    if(pData[playerid][pFraction] != 2 || pData[playerid][pRank] < 6) 
    	return SendErr(playerid, "Вам не доступна данная команда");

    new id = params[0];
    if(!IsPlayerConnected(id)) 
		return SendClientMessage(playerid, CGRAY, "Указанный игрок не найден.");
	if( id == playerid )  
		return SendClientMessage(playerid, CGRAY, "Вы не можете провести операцию на себе.");

	new value = params[1];
	if(value < 1 || value > 2) 
	{
	    SendInf(playerid, "/setsex [id] [Пол]");
		SendInf(playerid, "Пол | 1)Мужской 2)Женский");
		return 1;
	}
	if(pData[id][pSex] == value) 
		return SendErr(playerid, "Указанный игрок уже выбранного пола");
	SetPVarIntNew(playerid,"sexoffee",id);
	SetPVarIntNew(id,"sexoffee",id);
	SetPVarIntNew(id,"sexoffer",playerid);
	SetPVarIntNew(id,"sexvalue",value);
	new zStr[150], sexname[10];
	if(value == 1) format(sexname, 10, "Мужской");
	else format(sexname, 10, "Женский");
	format(zStr, 150, "Вы предложили {"#cWHITE"}%s{"#cINFO"} изменить его пол на{"#cWHITE"} %s. {FF1005}Цена: 1.500P",pData[id][pNickname],sexname);
	SendClientMessage(playerid, CINFO, zStr);
	format(zStr, 150, "{"#cWHITE"}%s {"#cINFO"}предложил изменить Ваш пол на {"#cWHITE"}%s {FF1005}Цена: 1.500P",pData[playerid][pNickname],sexname);
    SendClientMessage(id, CINFO, zStr);
    SendClientMessage(id,CINFO,"Чтобы согласиться нажмите {"#cGREEN"}Y, {"#cINFO"}иначе - {"#cRED"}N");
    return 1;
}

callback:: lock_vehicle_light_p(playerid, vehicle)
{
	vehicle_light_status(vehicle, 0);
	return true;
}

alias:lock("lk");
CMD:lock(playerid, params[])
{
	if(sscanf(params, "I(-1)", params[0])) 
	{	 
		SendInf(playerid, "/lock чтобы закрыть личный транспорт");
		SendInf(playerid, "/lock 1 чтобы закрыть арендованный или рабочий транспорт");
		return SendInf(playerid, "/lock 2 чтобы закрыть фракционный или другой транспорт");
	}

	if(params[0] == -1)
	{	
		foreach(new v:vehicle_in_stream[playerid])
		{	

			new
				Float:pl_pos_x,
				Float:pl_pos_y,
				Float:pl_pos_z;

			GetVehiclePos(v, pl_pos_x, pl_pos_y, pl_pos_z);

			for(new i; i < MAX_PLAYERS_VEHICLE_SL; i++)
			{
				if(v == vehicle_player_max[playerid][i])
				{
					new engine, lights, doors, bonnet, boot, objective;

					if(IsPlayerInRangeOfPoint(playerid, 7.0, pl_pos_x, pl_pos_y, pl_pos_z))
					{

						if(vehicle[v][cLock])
						{
							GameTextForPlayer(playerid, "~g~OPEN", 200, 1);

							vehicle_lock_status(v, false);

							vehicle_light_status(v, 1);

							SetTimerEx("lock_vehicle_light_p", 1000, false, "ii", playerid, v);

							new mese[120];
							format(mese,sizeof(mese),"открыл(а) личное транспортное средство «%s»", transport_config[GetVehicleModel(v)-400][transport_name]);
							MeAction(playerid ,mese);

							//SendSucc(playerid, "Вы открыли личный транспорт!");
							EROM(playerid, 1, "Вы открыли личный транспорт", 7, "", "");

						}
						else
						{
							GameTextForPlayer(playerid, "~r~LOCK", 200, 1);

							vehicle_lock_status(v, true);
							vehicle_light_status(v, 1);

							SetTimerEx("lock_vehicle_light_p", 1000, false, "ii", playerid, v);

							new mese[120];
							format(mese,sizeof(mese),"закрыл(а) личное транспортное средство «%s»", transport_config[GetVehicleModel(v)-400][transport_name]);
							MeAction(playerid ,mese);

							//SendSucc(playerid, "Вы закрыли личный транспорт!");
							EROM(playerid, 1, "Вы закрыли личный транспорт", 7, "", "");
						}
					}
					else
					{
						//SendInf(playerid, "Вы слишком далеко от транспорта!");
							EROM(playerid, 0, "Вы слишком далеко от транспорта", 7, "", "");
					}
					break;
				}
			}
		}
	}
	else if(params[0] == 1)
	{
		if(pTemp[playerid][rent_car] == INVALID_VEHICLE_ID) 
			return SendErr(playerid,"У Вас нет арендованного транспорта");

		new v = pTemp[playerid][rent_car];

		new
			Float:pl_pos_x,
			Float:pl_pos_y,
			Float:pl_pos_z;


		GetVehiclePos(v, pl_pos_x, pl_pos_y, pl_pos_z);

		if(IsPlayerInRangeOfPoint(playerid, 7.0, pl_pos_x, pl_pos_y, pl_pos_z))
		{
			
			if(vehicle[v][cLock])
			{
				GameTextForPlayer(playerid, "~g~OPEN", 1000, 1);

				PlayerPlaySound(playerid, 1145, ACVehInfo[v][acPosX], ACVehInfo[v][acPosY], ACVehInfo[v][acPosZ]);
				vehicle_lock_status(v, false);

				vehicle_light_status(v, 1);

				SetTimerEx("lock_vehicle_light_p", 1000, false, "ii", playerid, v);

				new mese[144];
				format(mese,sizeof(mese),"открыл(а) арендованное/рабочее транспортное средство «%s»", transport_config[GetVehicleModel(v)-400][transport_name]);
				MeAction(playerid ,mese);

				SendSucc(playerid, "Вы открыли рабочий/арендованный транспорт!");

			}
			else
			{
				GameTextForPlayer(playerid, "~r~LOCK", 1000, 1);

				vehicle_lock_status(v, true);
				vehicle_light_status(v, 1);

				SetTimerEx("lock_vehicle_light_p", 1000, false, "ii", playerid, v);

				new mese[144];
				format(mese,sizeof(mese),"закрыл(а) арендованное/рабочее транспортное средство «%s»", transport_config[GetVehicleModel(v)-400][transport_name]);
				MeAction(playerid ,mese);

				SendSucc(playerid, "Вы закрыли рабочий/арендованный транспорт!");

			}
		}
		else
		{
			return SendInf(playerid, "Вы слишком далеко от транспорта!");
		}

	}
	else if(params[0] == 2)
	{
		if(!pData[playerid][pFraction])
			return SendErr(playerid, "Вы не состоите в организации, чтобы использовать данную команду!");

		foreach(new v:vehicle_in_stream[playerid])
		{		
			new
				Float:pl_pos_x,
				Float:pl_pos_y,
				Float:pl_pos_z;

			GetPlayerPos(playerid, pl_pos_x, pl_pos_y, pl_pos_z);


			if(IsVehicleInRangeOfPoint(v, 7.0, pl_pos_x, pl_pos_y, pl_pos_z)) {}
				else continue;

			new
				own = vehicle[v][cOwnTo];
 
			switch(own)
			{
				case VEHICLE_MAFIA_1:
				{
					if(pData[playerid][pFraction] != 13)
					{
						return SendErr(playerid,"Вы не состоите в ОПГ!");				
					}
					if(vehicle[v][cLock])
					{
						GameTextForPlayer(playerid, "~g~OPEN", 1000, 1);

						vehicle_lock_status(v, false);

						vehicle_light_status(v, 1);

						SetTimerEx("lock_vehicle_light_p", 1000, false, "ii", playerid, v);

						new mese[120];
						format(mese,sizeof(mese),"открыл(а) транспортное средство «%s»", transport_config[GetVehicleModel(v)-400][transport_name]);
						MeAction(playerid ,mese);

						SendSucc(playerid, "Вы открыли фракционный/сторонний транспорт!");
					}
					else
					{
						GameTextForPlayer(playerid, "~r~LOCK", 1000, 1);

						vehicle_lock_status(v, true);
						vehicle_light_status(v, 1);

						SetTimerEx("lock_vehicle_light_p", 1000, false, "ii", playerid, v);

						new mese[120];
						format(mese,sizeof(mese),"закрыл(а) транспортное средство «%s»", transport_config[GetVehicleModel(v)-400][transport_name]);
						MeAction(playerid ,mese);

						SendSucc(playerid, "Вы закрыли фракционный/сторонний транспорт!");
					}
				}
				case VEHICLE_MAFIA_2:
				{
					if(pData[playerid][pFraction] != 14)
					{
						return SendErr(playerid,"Вы не состоите в ОПГ!");				
					}
					if(vehicle[v][cLock])
					{
						GameTextForPlayer(playerid, "~g~OPEN", 1000, 1);

						vehicle_lock_status(v, false);

						vehicle_light_status(v, 1);

						SetTimerEx("lock_vehicle_light_p", 1000, false, "ii", playerid, v);

						new mese[120];
						format(mese,sizeof(mese),"открыл(а) транспортное средство «%s»", transport_config[GetVehicleModel(v)-400][transport_name]);
						MeAction(playerid ,mese);

						SendSucc(playerid, "Вы открыли фракционный/сторонний транспорт!");
					}
					else
					{
						GameTextForPlayer(playerid, "~r~LOCK", 1000, 1);

						vehicle_lock_status(v, true);
						vehicle_light_status(v, 1);

						SetTimerEx("lock_vehicle_light_p", 1000, false, "ii", playerid, v);

						new mese[120];
						format(mese,sizeof(mese),"закрыл(а) транспортное средство «%s»", transport_config[GetVehicleModel(v)-400][transport_name]);
						MeAction(playerid ,mese);

						SendSucc(playerid, "Вы закрыли фракционный/сторонний транспорт!");
					}
				}
				case VEHICLE_MAFIA_3:
				{
					if(pData[playerid][pFraction] != 15)
					{
						return SendErr(playerid,"Вы не состоите в ОПГ!");				
					}
					if(vehicle[v][cLock])
					{
						GameTextForPlayer(playerid, "~g~OPEN", 1000, 1);

						vehicle_lock_status(v, false);

						vehicle_light_status(v, 1);

						SetTimerEx("lock_vehicle_light_p", 1000, false, "ii", playerid, v);

						new mese[120];
						format(mese,sizeof(mese),"открыл(а) транспортное средство «%s»", transport_config[GetVehicleModel(v)-400][transport_name]);
						MeAction(playerid ,mese);

						SendSucc(playerid, "Вы открыли фракционный/сторонний транспорт!");
					}
					else
					{
						GameTextForPlayer(playerid, "~r~LOCK", 1000, 1);

						vehicle_lock_status(v, true);
						vehicle_light_status(v, 1);

						SetTimerEx("lock_vehicle_light_p", 1000, false, "ii", playerid, v);

						new mese[120];
						format(mese,sizeof(mese),"закрыл(а) транспортное средство «%s»", transport_config[GetVehicleModel(v)-400][transport_name]);
						MeAction(playerid ,mese);

						SendSucc(playerid, "Вы закрыли фракционный/сторонний транспорт!");
					}
				}
				case VEHICLE_HOSPITAL:
				{
					if(pData[playerid][pFraction] != 2)
					{ 
						return SendErr(playerid,"Вы не являетесь работником мед.персонала!");
					}

					if(vehicle[v][cLock])
					{
						GameTextForPlayer(playerid, "~g~OPEN", 1000, 1);

						vehicle_lock_status(v, false);

						vehicle_light_status(v, 1);

						SetTimerEx("lock_vehicle_light_p", 1000, false, "ii", playerid, v);

						new mese[120];
						format(mese,sizeof(mese),"открыл(а) транспортное средство «%s»", transport_config[GetVehicleModel(v)-400][transport_name]);
						MeAction(playerid ,mese);

						SendSucc(playerid, "Вы открыли фракционный/сторонний транспорт!");
					}
					else
					{
						GameTextForPlayer(playerid, "~r~LOCK", 1000, 1);

						vehicle_lock_status(v, true);
						vehicle_light_status(v, 1);

						SetTimerEx("lock_vehicle_light_p", 1000, false, "ii", playerid, v);

						new mese[120];
						format(mese,sizeof(mese),"закрыл(а) транспортное средство «%s»", transport_config[GetVehicleModel(v)-400][transport_name]);
						MeAction(playerid ,mese);

						SendSucc(playerid, "Вы закрыли фракционный/сторонний транспорт!");
					}

				}
				case VEHICLE_GOV:
				{
					if(pData[playerid][pFraction] != 11)
					{
						return SendErr(playerid,"Вы не являетесь сотрудником Правительства!");			
					}

					if(vehicle[v][cLock])
					{
						GameTextForPlayer(playerid, "~g~OPEN", 1000, 1);

						vehicle_lock_status(v, false);

						vehicle_light_status(v, 1);

						SetTimerEx("lock_vehicle_light_p", 1000, false, "ii", playerid, v);

						new mese[120];
						format(mese,sizeof(mese),"открыл(а) транспортное средство «%s»", transport_config[GetVehicleModel(v)-400][transport_name]);
						MeAction(playerid ,mese);

						SendSucc(playerid, "Вы открыли фракционный/сторонний транспорт!");
					}
					else
					{
						GameTextForPlayer(playerid, "~r~LOCK", 1000, 1);

						vehicle_lock_status(v, true);
						vehicle_light_status(v, 1);

						SetTimerEx("lock_vehicle_light_p", 1000, false, "ii", playerid, v);

						new mese[120];
						format(mese,sizeof(mese),"закрыл(а) транспортное средство «%s»", transport_config[GetVehicleModel(v)-400][transport_name]);
						MeAction(playerid ,mese);

						SendSucc(playerid, "Вы закрыли фракционный/сторонний транспорт!");
					}

				}
				case VEHICLE_FEDERALS:
				{
					if(pData[playerid][pFraction] != 12)
					{
						return SendErr(playerid,"Вы не являетесь сотрудником ФСБ!");			
					}

					if(vehicle[v][cLock])
					{
						GameTextForPlayer(playerid, "~g~OPEN", 1000, 1);

						vehicle_lock_status(v, false);

						vehicle_light_status(v, 1);

						SetTimerEx("lock_vehicle_light_p", 1000, false, "ii", playerid, v);

						new mese[120];
						format(mese,sizeof(mese),"открыл(а) транспортное средство «%s»", transport_config[GetVehicleModel(v)-400][transport_name]);
						MeAction(playerid ,mese);

						SendSucc(playerid, "Вы открыли фракционный/сторонний транспорт!");
					}
					else
					{
						GameTextForPlayer(playerid, "~r~LOCK", 1000, 1);

						vehicle_lock_status(v, true);
						vehicle_light_status(v, 1);

						SetTimerEx("lock_vehicle_light_p", 1000, false, "ii", playerid, v);

						new mese[120];
						format(mese,sizeof(mese),"закрыл(а) транспортное средство «%s»", transport_config[GetVehicleModel(v)-400][transport_name]);
						MeAction(playerid ,mese);

						SendSucc(playerid, "Вы закрыли фракционный/сторонний транспорт!");
					}

				}
				case VEHICLE_POLICES:
				{
					if(!IsACop(playerid))
					{
						return SendErr(playerid,"Вы не являетесь сотрудником Полиции!");			
					}

					if(vehicle[v][cLock])
					{
						GameTextForPlayer(playerid, "~g~OPEN", 1000, 1);

						vehicle_lock_status(v, false);

						vehicle_light_status(v, 1);

						SetTimerEx("lock_vehicle_light_p", 1000, false, "ii", playerid, v);

						new mese[120];
						format(mese,sizeof(mese),"открыл(а) транспортное средство «%s»", transport_config[GetVehicleModel(v)-400][transport_name]);
						MeAction(playerid ,mese);

						SendSucc(playerid, "Вы открыли фракционный/сторонний транспорт!");
					}
					else
					{
						GameTextForPlayer(playerid, "~r~LOCK", 1000, 1);

						vehicle_lock_status(v, true);
						vehicle_light_status(v, 1);

						SetTimerEx("lock_vehicle_light_p", 1000, false, "ii", playerid, v);

						new mese[120];
						format(mese,sizeof(mese),"закрыл(а) транспортное средство «%s»", transport_config[GetVehicleModel(v)-400][transport_name]);
						MeAction(playerid ,mese);

						SendSucc(playerid, "Вы закрыли фракционный/сторонний транспорт!");
					}

				}
				case VEHICLE_NEWS_1:
				{
					if(pData[playerid][pFraction] != 10 || pData[playerid][pSubfraction] == 0)
					{ 
						return SendErr(playerid,"Вы не являетесь сотрудником СМИ!");
					}

					if(vehicle[v][cLock])
					{
						GameTextForPlayer(playerid, "~g~OPEN", 1000, 1);

						vehicle_lock_status(v, false);

						vehicle_light_status(v, 1);

						SetTimerEx("lock_vehicle_light_p", 1000, false, "ii", playerid, v);

						new mese[120];
						format(mese,sizeof(mese),"открыл(а) транспортное средство «%s»", transport_config[GetVehicleModel(v)-400][transport_name]);
						MeAction(playerid ,mese);

						SendSucc(playerid, "Вы открыли фракционный/сторонний транспорт!");
					}
					else
					{
						GameTextForPlayer(playerid, "~r~LOCK", 1000, 1);

						vehicle_lock_status(v, true);
						vehicle_light_status(v, 1);

						SetTimerEx("lock_vehicle_light_p", 1000, false, "ii", playerid, v);

						new mese[120];
						format(mese,sizeof(mese),"закрыл(а) транспортное средство «%s»", transport_config[GetVehicleModel(v)-400][transport_name]);
						MeAction(playerid ,mese);

						SendSucc(playerid, "Вы закрыли фракционный/сторонний транспорт!");
					}

				}
				case VEHICLE_NEWS_2:
				{
					if(pData[playerid][pFraction] != 10 || pData[playerid][pSubfraction] == 0)
					{ 
						return SendErr(playerid,"Вы не являетесь сотрудником СМИ!");
					}

					if(vehicle[v][cLock])
					{
						GameTextForPlayer(playerid, "~g~OPEN", 1000, 1);

						vehicle_lock_status(v, false);

						vehicle_light_status(v, 1);

						SetTimerEx("lock_vehicle_light_p", 1000, false, "ii", playerid, v);

						new mese[120];
						format(mese,sizeof(mese),"открыл(а) транспортное средство «%s»", transport_config[GetVehicleModel(v)-400][transport_name]);
						MeAction(playerid ,mese);

						SendSucc(playerid, "Вы открыли фракционный/сторонний транспорт!");
					}
					else
					{
						GameTextForPlayer(playerid, "~r~LOCK", 1000, 1);

						vehicle_lock_status(v, true);
						vehicle_light_status(v, 1);

						SetTimerEx("lock_vehicle_light_p", 1000, false, "ii", playerid, v);

						new mese[120];
						format(mese,sizeof(mese),"закрыл(а) транспортное средство «%s»", transport_config[GetVehicleModel(v)-400][transport_name]);
						MeAction(playerid ,mese);

						SendSucc(playerid, "Вы закрыли фракционный/сторонний транспорт!");
					}

				}
				case VEHICLE_HOSPITAL_1:
				{
					if(pData[playerid][pFraction] != 2 && pData[playerid][pSubfraction] != 2)
					{ 
						return SendErr(playerid,"Вы не являетесь сотрудником Больницы г.Арзамас!");
					}	

					if(vehicle[v][cLock])
					{
						GameTextForPlayer(playerid, "~g~OPEN", 1000, 1);

						vehicle_lock_status(v, false);

						vehicle_light_status(v, 1);

						SetTimerEx("lock_vehicle_light_p", 1000, false, "ii", playerid, v);

						new mese[120];
						format(mese,sizeof(mese),"открыл(а) транспортное средство «%s»", transport_config[GetVehicleModel(v)-400][transport_name]);
						MeAction(playerid ,mese);

						SendSucc(playerid, "Вы открыли фракционный/сторонний транспорт!");
					}
					else
					{
						GameTextForPlayer(playerid, "~r~LOCK", 1000, 1);

						vehicle_lock_status(v, true);
						vehicle_light_status(v, 1);

						SetTimerEx("lock_vehicle_light_p", 1000, false, "ii", playerid, v);

						new mese[120];
						format(mese,sizeof(mese),"закрыл(а) транспортное средство «%s»", transport_config[GetVehicleModel(v)-400][transport_name]);
						MeAction(playerid ,mese);

						SendSucc(playerid, "Вы закрыли фракционный/сторонний транспорт!");
					}

				}
				case VEHICLE_HOSPITAL_2:
				{
					if(pData[playerid][pFraction] != 2 && pData[playerid][pSubfraction] != 1)
					{ 
						return SendErr(playerid,"Вы не являетесь сотрудником Больницы г.Южный!");
					}

					if(vehicle[v][cLock])
					{
						GameTextForPlayer(playerid, "~g~OPEN", 1000, 1);

						vehicle_lock_status(v, false);

						vehicle_light_status(v, 1);

						SetTimerEx("lock_vehicle_light_p", 1000, false, "ii", playerid, v);

						new mese[120];
						format(mese,sizeof(mese),"открыл(а) транспортное средство «%s»", transport_config[GetVehicleModel(v)-400][transport_name]);
						MeAction(playerid ,mese);

						SendSucc(playerid, "Вы открыли фракционный/сторонний транспорт!");
					}
					else
					{
						GameTextForPlayer(playerid, "~r~LOCK", 1000, 1);

						vehicle_lock_status(v, true);
						vehicle_light_status(v, 1);

						SetTimerEx("lock_vehicle_light_p", 1000, false, "ii", playerid, v);

						new mese[120];
						format(mese,sizeof(mese),"закрыл(а) транспортное средство «%s»", transport_config[GetVehicleModel(v)-400][transport_name]);
						MeAction(playerid ,mese);

						SendSucc(playerid, "Вы закрыли фракционный/сторонний транспорт!");
					}

				}
				case VEHICLE_ARMY_1:
				{
					if(pData[playerid][pFraction] != 8)
					{ 
						return SendErr(playerid,"Вы не являетесь сотрудником Армии!");
					}	

					if(vehicle[v][cLock])
					{
						GameTextForPlayer(playerid, "~g~OPEN", 1000, 1);

						vehicle_lock_status(v, false);

						vehicle_light_status(v, 1);

						SetTimerEx("lock_vehicle_light_p", 1000, false, "ii", playerid, v);

						new mese[120];
						format(mese,sizeof(mese),"открыл(а) транспортное средство «%s»", transport_config[GetVehicleModel(v)-400][transport_name]);
						MeAction(playerid ,mese);

						SendSucc(playerid, "Вы открыли фракционный/сторонний транспорт!");
					}
					else
					{
						GameTextForPlayer(playerid, "~r~LOCK", 1000, 1);

						vehicle_lock_status(v, true);
						vehicle_light_status(v, 1);

						SetTimerEx("lock_vehicle_light_p", 1000, false, "ii", playerid, v);

						new mese[120];
						format(mese,sizeof(mese),"закрыл(а) транспортное средство «%s»", transport_config[GetVehicleModel(v)-400][transport_name]);
						MeAction(playerid ,mese);

						SendSucc(playerid, "Вы закрыли фракционный/сторонний транспорт!");
					}

				}
				case VEHICLE_ARMY_VERT:
				{
					if(pData[playerid][pFraction] != 8 && pData[playerid][pRank] < 5)
					{ 
						return SendErr(playerid,"Вы не являетесь сотрудником Армии или ваше звание недостаточное!");
					}	

					if(vehicle[v][cLock])
					{
						GameTextForPlayer(playerid, "~g~OPEN", 1000, 1);

						vehicle_lock_status(v, false);

						vehicle_light_status(v, 1);

						SetTimerEx("lock_vehicle_light_p", 1000, false, "ii", playerid, v);

						new mese[120];
						format(mese,sizeof(mese),"открыл(а) транспортное средство «%s»", transport_config[GetVehicleModel(v)-400][transport_name]);
						MeAction(playerid ,mese);

						SendSucc(playerid, "Вы открыли фракционный/сторонний транспорт!");
					}
					else
					{
						GameTextForPlayer(playerid, "~r~LOCK", 1000, 1);

						vehicle_lock_status(v, true);
						vehicle_light_status(v, 1);

						SetTimerEx("lock_vehicle_light_p", 1000, false, "ii", playerid, v);

						new mese[120];
						format(mese,sizeof(mese),"закрыл(а) транспортное средство «%s»", transport_config[GetVehicleModel(v)-400][transport_name]);
						MeAction(playerid ,mese);

						SendSucc(playerid, "Вы закрыли фракционный/сторонний транспорт!");
					}

				}		
			}
		}

	}
	return true;
}

CMD:ud(playerid, params[])
{
	if(sscanf(params, "I(-1)", params[0])) 
		return SendInf(playerid, "/ud [ID игрока]");

	if(params[0] == -1)
	{
		SendInf(playerid, "/ud [ID игрока]");
		return show_player_udost(playerid, playerid);
	}
	else return offer_player(playerid, params[0], OFFER_UDOST);
}


CMD:pass(playerid, params[])
{
	if(sscanf(params, "I(-1)", params[0])) 
		return SendInf(playerid, "/pass [ID игрока]");

	if(params[0] == -1)
	{
		SendInf(playerid, "/pass [ID игрока]");
		return show_player_pass(playerid, playerid);
	}
	else return offer_player(playerid, params[0], OFFER_PASS);
}

CMD:lic(playerid, params[])
{
	if(sscanf(params, "I(-1)", params[0])) 
		return SendInf(playerid, "/lic [ID игрока]");
	if(params[0] == -1)
	{
		SendInf(playerid, "/lic [ID игрока]");
		return show_player_lic(playerid, playerid);
	}
	else return offer_player(playerid, params[0], OFFER_LIC);
}

CMD:skill(playerid, params[])
{
	if(sscanf(params, "I(-1)", params[0])) 
		return SendInf(playerid, "/skill [ID игрока]");
	
	if(params[0] == -1)
	{
		SendInf(playerid, "/skill [ID игрока]");
		return show_player_skill(playerid, playerid);
	}
	else return offer_player(playerid, params[0], OFFER_SKILL);
}

CMD:stats(playerid, params[])
{
	if(sscanf(params, "I(-1)", params[0])) 
		return true;
	
	if(params[0] == -1)
	{
		return show_stats(playerid, playerid);
	}

	if(pData[playerid][pAdmin] > 1)
	{	
		show_stats(playerid, params[0]);
	}
	return true;
}

CMD:clear_attach(playerid)
{
	for(new i; i<7; i++)
	{
		RemovePlayerAttachedObject(playerid, i);
	}
	return true;
}

CMD:show_aks(playerid)
{

	AttachAcsToPlayer(playerid, GetPlayerSkin(playerid));
	return true;
}

CMD:anim(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) 
		return SendErr(playerid, "Вы не можете использовать анимацию, находясь в автомобиле");

	if(GetPVarIntNew(playerid, "Anim_Action"))
	{
		ClearAnimations(playerid);
	    DeletePVarNew(playerid,"Anim_Action");
	    SendSucc(playerid, "Анимация остановлена");
	    return 1;
	}

	if(sscanf(params, "d", params[0]))
	{
		new list_anim [] =
		!""cBLUE"1."cWH" Танец - 1\n"cBLUE"2."cWH" Танец - 2\n"cBLUE"3."cWH" Танец - 3\n"cBLUE"4."cWH" Танец - 4\n"cBLUE"5."cWH" Стойка дилера\n"cBLUE"\
		6."cWH" Передал что-то\n"cBLUE"7."cWH" Съел что-то\n"cBLUE"8."cWH" Справить нужду\n"cBLUE"9."cWH" Медитация\n"cBLUE"\
		10."cWH" Сидеть раненым\n"cBLUE"11."cWH" Спать на боку\n"cBLUE"12."cWH" Лечь на спину\n"cBLUE"13."cWH" Шлепнуть рукой\n"cBLUE"\
		14."cWH" Наносить граффити 1\n"cBLUE"15."cWH" Наносить граффити 2\n"cBLUE"16."cWH" Курение\n"cBLUE"17."cWH" Ограбление\n"cBLUE"\
		18."cWH" Одеть маску\n"cBLUE"19."cWH" Руки в верх\n"cBLUE"20."cWH" Позвать кого-то\n"cBLUE"21."cWH" Поднять руки\n"cBLUE"\
		22."cWH" Болельщик 1\n"cBLUE"23."cWH" Болельщик 2\n"cBLUE"24."cWH" Болельщик 3\n"cBLUE"25."cWH" Показать средний палец\n"cBLUE"\
		26."cWH" Выпить что-то\n"cBLUE"27."cWH" Махать руками\n"cBLUE"28."cWH" Мужское курение\n"cBLUE"29."cWH" Прилечь 1\n"cBLUE"\
		30."cWH" Прилечь 2\n"cBLUE"31."cWH" Прилечь 3\n"cBLUE"32."cWH" Прилечь 4\n"cBLUE"33."cWH" Присесть на пол\n"cBLUE"34."cWH" Читать реп 1\n"cBLUE"\
		35."cWH" Читать реп 2\n"cBLUE"36."cWH" Читать реп 3\n"cBLUE"37."cWH" Читать реп 4\n"cBLUE"38."cWH" Набивать мяч\n"cBLUE"39."cWH" Кинуть мяч\n"cBLUE"\
		40."cWH" Поднять мяч\n"cBLUE"41."cWH" Позвать\n"cBLUE"42."cWH" Чинить авто\n"cBLUE"43."cWH" Прислониться к авто\n"cBLUE"\
		44."cWH" Сложить руки вместе\n"cBLUE"45."cWH" Держать биту 1\n"cBLUE"46."cWH" Держать биту 2\n"cBLUE"47."cWH" Гангстерский жест 1\n"cBLUE"\
		48."cWH" Гангстерский жест 2\n"cBLUE"49."cWH" Гангстерский жест 3\n"cBLUE"50."cWH" Гангстерский жест 4\n"cBLUE"\
		51."cWH" Гангстерский жест 5\n"cBLUE"52."cWH" Гангстерский жест 6\n"cBLUE"53."cWH" Гангстерский жест 7\n"cBLUE"\
		54."cWH" Гангстерский жест 8\n"cBLUE"55."cWH" Плакать\n"cBLUE"56."cWH" Присесть 1\n"cBLUE"57."cWH" Присесть 2\n"cBLUE"\
		58."cWH" Присесть облокотившись\n"cBLUE"59."cWH" Женское курение\n"cBLUE"60."cWH" Искусственное дыхание\n"cBLUE"\
		61."cWH" Облокотиться 1\n"cBLUE"62."cWH" Облокотиться 2\n"cBLUE"63."cWH" Facepalm\n"cBLUE"64."cWH" Чесаться\n"cBLUE"\
		65."cWH" Поставить бомбу\n"cBLUE"66."cWH" Упал без сознания\n"cBLUE"67."cWH" Передозировка - 1\n"cBLUE"68."cWH" Передозировка - 2\n"cBLUE"\
		69."cWH" Танец - 5\n"cBLUE"70."cWH" Танец - 6\n"cBLUE"71."cWH" Танец - 7\n"cBLUE"72."cWH" Танец - 8\n"cBLUE"73."cWH" Танец - 9\n"cBLUE"\
		74."cWH" Гангстерский жест\n"cBLUE"75."cWH" Затянуть косяк\n"cBLUE"76."cWH" Танец - 10\n"cBLUE"77."cWH" Танец - 11\n"cBLUE"78."cWH" Танец - 12\n"cBLUE"\
		79."cWH" Танец - 13";

		SPD(playerid, DIALOG_SELECT_ANIM, DIALOG_STYLE_LIST,
		!""cBLUE"Анимации "cWH"| Выберите анимацию", list_anim, !"Выбрать", !"Закрыть");

		return SendInf(playerid, "/anim [1-79]");
	}

	if(params[0] < 1 || params[0] > 79)
		return SendInf(playerid, "Доступные номера анимаций от 1 до 79");

	PlayAnimForPlayer(playerid, params[0]);
	return true;
}

stock PlayAnimForPlayer(playerid, type)
{
	switch(type)
	{
		case 1: ApplyAnimation(playerid,"DANCING", "Dnce_M_a",4.1,1,0,0,0,0,0);
		case 2: ApplyAnimation(playerid,"DANCING", "Dnce_M_b",4.1,1,0,0,0,0,0);
		case 3: ApplyAnimation(playerid,"DANCING","Dan_up_a",4.1,1,0,0,0,0,0);
		case 4: ApplyAnimation(playerid,"DANCING", "Dnce_M_d",4.1,1,0,0,0,0,0);
        case 5: ApplyAnimation(playerid,"DEALER","Dealer_idle",4.1,1,0,0,0,0,0);
        case 6: ApplyAnimation(playerid,"DEALER","Dealer_Deal",4.1,0,0,0,0,0,1);
        case 7: ApplyAnimation(playerid,"FOOD","Eat_Burger",4.1,0,0,0,0,0,1);
		case 8: ApplyAnimation(playerid,"PAULNMAC","Piss_in",4.1,0,0,0,0,0,1);
		case 9: ApplyAnimation(playerid,"PARK","Tai_Chi_Loop",4.1,1,0,0,0,0,0);
		case 10: ApplyAnimation(playerid,"CRACK","Crckidle1",4.1,1,0,0,0,0,0);
		case 11: ApplyAnimation(playerid,"CRACK","Crckidle2",4.1,1,0,0,0,0,0);
		case 12: ApplyAnimation(playerid,"CRACK","Crckidle4",4.1,1,0,0,0,0,0);
		case 13: ApplyAnimation(playerid,"SWEET","sweet_ass_slap",4.1,0,0,0,0,0,1);
		case 14: ApplyAnimation(playerid,"SPRAYCAN","spraycan_full",4.1,1,0,0,0,0,0);
		case 15: ApplyAnimation(playerid,"GRAFFITI","spraycan_fire",4.1,1,0,0,0,0,0);
		case 16: ApplyAnimation(playerid,"SMOKING","M_smkstnd_loop",4.1,1,0,0,0,0,0);
		case 17: ApplyAnimation(playerid,"SHOP","ROB_Loop_Threat",4.1,1,0,0,0,0,0);
		case 18: ApplyAnimation(playerid,"SHOP","ROB_shifty",4.1,0,0,0,0,0,1);
		case 19: ApplyAnimation(playerid,"SHOP","SHP_Rob_HandsUP",4.1,1,0,0,0,0,0);
		case 20: ApplyAnimation(playerid,"RYDER","Ryd_Beckon_02",4.1,1,0,0,0,0,0);
		case 21: ApplyAnimation(playerid,"RIOT","Riot_Angry",4.1,0,0,0,0,0,0);
		case 22: ApplyAnimation(playerid,"RIOT","Riot_Angry_B",4.1,1,0,0,0,0,0);
		case 23: ApplyAnimation(playerid,"RIOT","Riot_Chant",4.1,1,1,0,0,0,0);
		case 24: ApplyAnimation(playerid,"RIOT","Riot_Punches",4.1,1,0,0,0,0,0);
		case 25: ApplyAnimation(playerid,"PED","fucku",4.1,0,0,0,0,0,1);
        case 26: ApplyAnimation(playerid,"BAR","dnK_StndM_loop",4.1,0,0,0,0,0,1);
        case 27: ApplyAnimation(playerid,"BD_FIRE","BD_Panic_03",4.1,1,0,0,0,0,0);
        case 28: ApplyAnimation(playerid,"BD_FIRE","M_smklean_loop",4.1,1,0,0,0,0,0);
		case 29: ApplyAnimation(playerid,"BEACH","bather",4.1,1,0,0,0,0,0);
		case 30: ApplyAnimation(playerid,"BEACH","Lay_Bac_loop",4.1,1,0,0,0,0,0);
		case 31: ApplyAnimation(playerid,"BEACH","Parksit_w_loop",4.1,1,0,0,0,0,0);
		case 32: ApplyAnimation(playerid,"BEACH","Sitnwait_Loop_W",4.1,1,0,0,0,0,0);
		case 33: ApplyAnimation(playerid,"BEACH","Parksit_M_loop",4.1,1,0,0,0,0,0);
		case 34: ApplyAnimation(playerid,"benchpress","gym_bp_celebrate",4.1,1,0,0,0,0,0);
		case 35: ApplyAnimation(playerid,"LOWRIDER","Rap_C_loop",4.1,1,0,0,0,0,0);
		case 36: ApplyAnimation(playerid,"LOWRIDER","Rap_B_loop",4.1,1,0,0,0,0,0);
		case 37: ApplyAnimation(playerid,"LOWRIDER","Rap_A_loop",4.1,1,0,0,0,0,0);
		case 38: ApplyAnimation(playerid,"BSKTBALL","BBALL_idleloop",4.1,1,0,0,0,0,0);
		case 39: ApplyAnimation(playerid,"BSKTBALL","BBALL_Jump_Shot",4.1,0,0,0,0,0,1);
		case 40: ApplyAnimation(playerid,"BSKTBALL","BBALL_pickup",4.1,0,0,0,0,0,1);
		case 41: ApplyAnimation(playerid,"CAMERA","camstnd_cmon",4.1,0,0,0,0,0,1);
		case 42: ApplyAnimation(playerid,"CAR","fixn_car_loop",4.1,1,0,0,0,0,0);
		case 43: ApplyAnimation(playerid,"CAR_CHAT","car_talkm_loop",4.1,1,0,0,0,0,0);
		case 44: ApplyAnimation(playerid,"COP_AMBIENT","coplook_loop",4.1,1,0,0,0,0,0);
		case 45: ApplyAnimation(playerid,"CRACK","Bbalbat_Idle_01",4.1,1,0,0,0,0,0);
        case 46: ApplyAnimation(playerid,"CRACK","Bbalbat_Idle_02",4.1,1,0,0,0,0,0);
		case 47: ApplyAnimation(playerid,"GHANDS","gsign1",4.1,0,0,0,0,0,1);
        case 48: ApplyAnimation(playerid,"GHANDS","gsign2",4.1,0,0,0,0,0,1);
        case 49: ApplyAnimation(playerid,"GHANDS","gsign3",4.1,0,0,0,0,0,1);
		case 50: ApplyAnimation(playerid,"GHANDS","gsign4",4.1,0,0,0,0,0,1);
		case 51: ApplyAnimation(playerid,"GHANDS","gsign5",4.1,0,0,0,0,0,1);
		case 52: ApplyAnimation(playerid,"GHANDS","gsign1LH",4.1,0,0,0,0,0,1);
		case 53: ApplyAnimation(playerid,"GHANDS","gsign2LH",4.1,0,0,0,0,0,1);
		case 54: ApplyAnimation(playerid,"GHANDS","gsign4LH",4.1,0,0,0,0,0,1);
		case 55: ApplyAnimation(playerid,"GRAVEYARD","mrnF_loop",4.1,1,0,0,0,0,0);
		case 56: ApplyAnimation(playerid,"MISC","seat_LR",4.1,1,0,0,0,0,0);
		case 57: ApplyAnimation(playerid,"INT_HOUSE","Lou_in",4.1,0,1,1,1,1,0);
		case 58: ApplyAnimation(playerid,"INT_OFFICE","OFF_sit_Bored_loop",4.1,1,0,0,0,0,0);
		case 59: ApplyAnimation(playerid,"LOWRIDER","F_smklean_loop",4.1,1,0,0,0,0,0);
		case 60: ApplyAnimation(playerid,"MEDIC","CPR",4.1,0,0,0,0,0,1);
		case 61: ApplyAnimation(playerid,"GANGS","LeanIn",4.1,0,1,1,1,1,0);
		case 62: ApplyAnimation(playerid,"MISC","plyrlean_loop",4.1,1,0,0,0,0,0);
		case 63: ApplyAnimation(playerid,"MISC","plyr_shkhead",4.1,0,0,0,0,0,1);
		case 64: ApplyAnimation(playerid,"MISC","scratchballs_01",4.1,1,0,0,0,0,0);
		case 65: ApplyAnimation(playerid,"BOMBER","BOM_Plant",4.1,1,0,0,0,0,0);
		case 66: ApplyAnimation(playerid,"CRACK","crckdeth2",4.1,1,0,0,0,0,0);
		case 67: ApplyAnimation(playerid,"CRACK","crckdeth3",4.1,1,0,0,0,0,0);
		case 68: ApplyAnimation(playerid,"CRACK","crckdeth1",4.1,1,0,0,0,0,0);
		case 69: ApplyAnimation(playerid,"DANCING","dance_loop",4.1,1,0,0,0,0,0);
		case 70: ApplyAnimation(playerid,"DANCING","DAN_Left_A",4.1,1,0,0,0,0,0);
		case 71: ApplyAnimation(playerid,"DANCING","dnce_M_a",4.1,1,0,0,0,0,0);
		case 72: ApplyAnimation(playerid,"DANCING","dnce_M_b",4.1,1,0,0,0,0,0);
		case 73: ApplyAnimation(playerid,"DANCING","dnce_M_d",4.1,1,0,0,0,0,0);
		case 74: ApplyAnimation(playerid,"GANGS","prtial_gngtlkD",4.1,1,0,0,0,0,0);
		case 75: ApplyAnimation(playerid,"GANGS","smkcig_prtl",4.1,1,0,0,0,0,0);
		case 76: ApplyAnimation(playerid,"DANCING","Dan_Down_a",4.1,1,0,0,0,0,0);
		case 77: ApplyAnimation(playerid,"DANCING","Dan_Left_A",4.1,1,0,0,0,0,0);
		case 78: ApplyAnimation(playerid,"DANCING","Dan_Loop_A",4.1,1,0,0,0,0,0);
		case 79: ApplyAnimation(playerid,"DANCING","Dan_Right_A",4.1,1,0,0,0,0,0);
	}

	SendInf(playerid, "Чтобы остановить анимацию введите повторно команду "cORANGE"/anim");
	SetPVarIntNew(playerid, "Anim_Action", 1);
	return true;
}


CMD:hidespeed(playerid)
{
	KillTimer(pTemp[playerid][vehicle_speed_timer]);
	pTemp[playerid][vehicle_speed_timer] = -1;

	hide_speed_player(playerid);

	PlayerTextDrawHideEx(playerid, player_speed_car[0][playerid]);
	PlayerTextDrawHideEx(playerid, player_speed_car[1][playerid]);
	PlayerTextDrawHideEx(playerid, player_speed_car[2][playerid]);
	PlayerTextDrawHideEx(playerid, player_speed_car[3][playerid]);
	PlayerTextDrawHideEx(playerid, player_speed_car[4][playerid]);
	PlayerTextDrawHideEx(playerid, player_speed_car[5][playerid]);		
	PlayerTextDrawHideEx(playerid, player_speed_car[6][playerid]);
	PlayerTextDrawHideEx(playerid, player_speed_car[7][playerid]);
	PlayerTextDrawHideEx(playerid, player_speed_car[8][playerid]);		
	PlayerTextDrawHideEx(playerid, player_speed_car[9][playerid]);
	PlayerTextDrawHideEx(playerid, player_speed_car[10][playerid]);
	return true;
}


CMD:sellsim(playerid, params[])
{
	if(!pData[playerid][pPhone])
		return SendErr(playerid, "У вас нет сим-карты");

	if(!IsPlayerInRangeOfPoint(playerid, 50.0, -909.2573,-2038.6021,25.7742)) 
		return SendErr(playerid, "Вы должны находиться в магазине 24/7");

	if(GetPVarIntNew(playerid, "OfferSim") || GetPVarIntNew(playerid, "RecieveSim"))
		return SendErr(playerid, "У вас уже есть активное предложение");

	if(GetPVarIntNew(playerid, "OfferSnow") || GetPVarIntNew(playerid, "RecieveSnow"))
		return SendErr(playerid, "У вас уже есть активное предложение");

	if(sscanf(params, "dd", params[0],params[1])) 
		return SendInf(playerid, "/sellsim [ID игрока] [Цена продажи]");

	if(!IsPlayerConnected(params[0]) || playerid == params[0])
		return SendErr(playerid, "Неверный ID");
	
	if(GetPlayerDistanceToPlayer(playerid, params[0]) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(params[0]))
		return SendErr(playerid, "Вы находитесь далеко друг от друга");	

	if(pData[playerid][pLevel] < 3)
		return SendErr(playerid, "Подавать сим-карты можно с 3 уровня");

	if(params[1] < 1000 || params[1] > 200000000)
		return SendErr(playerid, "Стоимость продажи должна быть от 1000 до 20млн. рублей");

	if(GetPlayerMoneyEx(params[0]) < params[1])
	{
		return SendErr(playerid, "У игрока нет данной суммы на руках");
	}



	new
		message[144];

	format(message, sizeof(message), "Вы предложили "cGR"%s "cWH"купить свою сим-карту за "cGR"%d "cWH"рублей", pData[params[0]][pNickname], params[1]);
	SendSucc(playerid, message);

	SetPVarIntNew(playerid, "OfferSim", params[0]+1);
	SetPVarIntNew(params[0], "RecieveSim", playerid+1);
	SetPVarIntNew(params[0], "SimCard", pData[playerid][pPhone]);
	SetPVarIntNew(params[0], "SimPrice", params[1]);

	new 
		sell_sim_message[300];

	format(sell_sim_message, sizeof (sell_sim_message), "\n"cBLUE"%s "cWH"предлагает купить его сим-карту\n\n\
		"cWH"Номер сим-карты: "cBLUE"%d\n\
		"cWH"Стоимость: "cBLUE"%d рублей\n\n\
		"cWH"При покупке, новый телефонный номер "cBLUE"заменит "cWH"ваш старый!\n\
		"cWH"Вы действительно хотите купить данную сим-карту?", pData[playerid][pNickname], pData[playerid][pPhone], params[1]);
	SPD(params[0], DIALOG_SELL_SIM, DIALOG_STYLE_MSGBOX, !""cBLUE"Предложение покупки сим-карты", sell_sim_message, !"Купить", !"Отмена");		
	return true;
}

CMD:tradesim(playerid, params[])
{
	if(!pData[playerid][pPhone])
		return SendErr(playerid, "У вас нет сим-карты");

	if(!IsPlayerInRangeOfPoint(playerid, 50.0, -909.2573,-2038.6021,25.7742)) 
		return SendErr(playerid, "Вы должны находиться в магазине 24/7");

	if(GetPVarIntNew(playerid, "OfferTradeSim") || GetPVarIntNew(playerid, "RecieveTradeSim"))
		return SendErr(playerid, "У вас уже есть активное предложение");

	if(GetPVarIntNew(playerid, "OfferSnow") || GetPVarIntNew(playerid, "RecieveSnow"))
		return SendErr(playerid, "У вас уже есть активное предложение");

	if(sscanf(params, "ddd", params[0], params[1], params[2])) 
		return SendInf(playerid, "/tradesim [ID игрока] [Доплата с Вашей стороны] [Доплата со стороный игрока]");

	if(!IsPlayerConnected(params[0]) || playerid == params[0])
		return SendErr(playerid, "Неверный ID");

	if(GetPlayerDistanceToPlayer(playerid, params[0]) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(params[0]))
		return SendErr(playerid, "Вы находитесь далеко друг от друга");	

	if(pData[playerid][pLevel] < 3)
		return SendErr(playerid, "Обмениваться сим-картами можно с 3 уровня");

	if(!pData[params[0]][pPhone])
		return SendErr(playerid, "У игрока нет сим-карты");

	if(params[1] < 0 || params[1] > 20000000)
		return SendErr(playerid, "Цена доплаты должна быть от 0 до 20млн. рублей");

	if(params[2] < 0 || params[2] > 20000000)
		return SendErr(playerid, "Цена доплаты с игрока должна быть от 0 до 20млн. рублей");

	if(GetPlayerMoneyEx(playerid) < params[1])
		return SendErr(playerid, "У Вас нет данной суммы на руках");

	if(GetPlayerMoneyEx(params[0]) < params[2])
		return SendErr(playerid, "У игрока нет данной суммы на руках");

	new
		message[144];

	format(message, sizeof(message), "Вы предложили "cGR"%s "cWH"обменять свою сим-карту "cGR"%d "cWH"на "cGR"%d", pData[params[0]][pNickname], pData[playerid][pPhone], pData[params[0]][pPhone]);
	SendSucc(playerid, message);

	format(message, sizeof(message), "Доплата с Вашей стороны: %d рублей. Со стороны игрока: %d рублей", params[1], params[2]);
	SendInf(playerid, message);

	SetPVarIntNew(playerid, "OfferTradeSim", params[0]+1);
	SetPVarIntNew(params[0], "RecieveTradeSim", playerid+1);
	SetPVarIntNew(params[0], "SimOfferCard", pData[playerid][pPhone]);
	SetPVarIntNew(params[0], "SimOfferPrice", params[1]);
	SetPVarIntNew(params[0], "SimRecieveCard", pData[params[0]][pPhone]);
	SetPVarIntNew(params[0], "SimRecievePrice", params[2]);

	new 
		trade_sim_message[500];

	format(trade_sim_message, sizeof (trade_sim_message), "\n"cBLUE"%s "cWH"предлагает обменяться сим-картами\n\n\
		"cWH"Вы получите сим-карту: "cBLUE"%d\n\
		"cWH"Игрок получит сим-карту: "cBLUE"%d\n\n\
		"cWH"Доплата со стороны игрока: "cBLUE"%d рублей\n\
		"cWH"Доплата с Вашей стороны: "cBLUE"%d рублей\n\n\
		"cWH"Вы действительно хотите произвести обмен сим-картами?", pData[playerid][pNickname], pData[playerid][pPhone], pData[params[0]][pPhone], params[1], params[2]);
	SPD(params[0], DIALOG_TRADE_SIM, DIALOG_STYLE_MSGBOX, !""cBLUE"Предложение обмена сим-картами", trade_sim_message, !"Обменять", !"Отмена");		
	return true;
}

stock dialog_sell_simcard(playerid, dialogid, response) // OnDialogResponse
{
	switch(dialogid)
	{
		case DIALOG_SELL_SIM:
		{
			new 
				offerid = GetPVarIntNew(playerid, "RecieveSim")-1,
				simcard = GetPVarIntNew(playerid, "SimCard"),
				price = GetPVarIntNew(playerid, "SimPrice");

			if(GetPVarIntNew(offerid, "OfferSim") != playerid+1)
				return SendErr(playerid, "Данное предложение неактивно");

			DeletePVarNew(offerid, "OfferSim");
			DeletePVarNew(playerid, "RecieveSim");
			DeletePVarNew(playerid, "SimCard");
			DeletePVarNew(playerid, "SimPrice");

			if(!response)
			{
				SendInf(playerid, "Вы отказались от покупки сим-карты");
				SendInf(offerid, "Игрок отказался от покупки сим-карты");
				return true;
			}

			if(pData[offerid][pPhone] != simcard)
				return SendErr(playerid, "У игрока нет данной сим-карты");

			if(GetPlayerMoneyEx(playerid) < price)
			{
				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:info_gui_no_money", 3000);
				return SendErr(playerid, "У Вас нет нужной суммы на руках");
			}

			if(GetPlayerDistanceToPlayer(playerid, offerid) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(offerid))
				return SendErr(playerid, "Вы находитесь далеко друг от друга");	

			pData[playerid][pPhone] = simcard;
			pData[offerid][pPhone] = 0;

			UpdatePlayerData(playerid, "phone", pData[playerid][pPhone]);
			UpdatePlayerData(offerid, "phone", 0);

			give_money(playerid, -price, "Покупка сим-карты у игрока");
			give_money(offerid, price, "Продажа сим-карты игроку");

			new 
				message[144];

			format(message, sizeof(message), "Вы купили номер "cGR"%d "cWH"у игрока "cGR"%s "cWH"за "cGR"%d "cWH"рублей", simcard, pData[offerid][pNickname], price);
			SendSucc(playerid, message);
			SendInf(playerid, "Новый телефонный номер заменил ваш старый");

			format(message, sizeof(message), "%s купил Ваш номер %d за %d рублей", pData[playerid][pNickname], simcard, price);
			SendSucc(offerid, message);
			SendInf(playerid, "Теперь у вас отсутствует сим-карта");
			return 1;
		}
		case DIALOG_TRADE_SIM:
		{
			new 
				offerid = GetPVarIntNew(playerid, "RecieveTradeSim")-1,
				simcard = GetPVarIntNew(playerid, "SimOfferCard"),
				price = GetPVarIntNew(playerid, "SimOfferPrice"),
				givesimcard = GetPVarIntNew(playerid, "SimRecieveCard"),
				price2 = GetPVarIntNew(playerid, "SimRecievePrice");

			if(GetPVarIntNew(offerid, "OfferTradeSim") != playerid+1)
				return SendErr(playerid, "Данное предложение неактивно");

			DeletePVarNew(offerid, "OfferTradeSim");
			DeletePVarNew(playerid, "RecieveTradeSim");
			DeletePVarNew(playerid, "SimOfferPrice");
			DeletePVarNew(playerid, "SimOfferCard");
			DeletePVarNew(playerid, "SimRecieveCard");
			DeletePVarNew(playerid, "SimRecievePrice");

			if(!response)
			{
				SendInf(playerid, "Вы отказались от обмена сим-картами");
				SendInf(offerid, "Игрок отказался от обмена сим-картами");
				return true;
			}

			if(pData[offerid][pPhone] != simcard)
				return SendErr(playerid, "У игрока нет данной сим-карты");

			if(pData[playerid][pPhone] != givesimcard)
				return SendErr(playerid, "У Вас нет данной сим-карты");

			if(GetPlayerMoneyEx(playerid) < price2)
			{
				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:info_gui_no_money", 3000);
				return SendErr(playerid, "У Вас нет нужной суммы на руках");
			}

			if(GetPlayerMoneyEx(offerid) < price)
				return SendErr(playerid, "У игрока нет нужной суммы на руках");

			if(GetPlayerDistanceToPlayer(playerid, offerid) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(offerid))
				return SendErr(playerid, "Вы находитесь далеко друг от друга");	

			pData[playerid][pPhone] = simcard;
			pData[offerid][pPhone] = givesimcard;

			UpdatePlayerData(playerid, "phone", pData[playerid][pPhone]);
			UpdatePlayerData(offerid, "phone", pData[offerid][pPhone]);

			give_money(playerid, -price2, "Обмен сим-картами доплата");
			give_money(offerid, -price, "Обмен сим-картами доплата");

			give_money(offerid, price2, "Обмен сим-картами (получение доплаты)");
			give_money(playerid, price, "Обмен сим-картами (получение доплаты)");

			new 
				message[144];

			format(message, sizeof(message), "Вы обменяли номер "cBLUE"%d "cWH"у игрока "cBLUE"%s "cWH"на "cBLUE"%d", givesimcard, pData[offerid][pNickname], simcard);
			SendSucc(playerid, message);
			SendInf(playerid, "Новый телефонный номер заменил ваш старый");

			format(message, sizeof(message), "Вы обменяли номер "cBLUE"%d "cWH"у игрока "cBLUE"%s "cWH"на "cBLUE"%d", simcard, pData[playerid][pNickname], givesimcard);
			SendSucc(offerid, message);
			SendInf(offerid, "Новый телефонный номер заменил ваш старый");
			return 1;
		}
	}
	return 1;
}

CMD:ff(playerid, params[])
{
    if(pData[playerid][pFraction] != 11) NoCMD(playerid);
    
    if(sscanf(params, "d", params[0]))
        SendErr(playerid, "/ff [ID Игрока]");
    new id = strval(params[0]);
    
    if(ff[id] == playerid) {
        ff[id] = -1;
        SendSucc(playerid, "Вы успешно выключили прослушку");
    }
    else if(ff[id] != playerid && ff[id] >= 0) {
        SendErr(playerid, "Данный человек на прослушке у другого работника");
    }
    else {
        ff[id] = playerid;
        SendSucc(playerid, "Вы успешно включили прослушку");
    }
    return true;
}

CMD:dress(playerid, params[])
{
    if(!pData[playerid][pFraction])
        return SendErr(playerid, "Вы не во фракции");
    if(!isDress[playerid]) {
        skinsjs[playerid] = pData[playerid][pSkin];
        pData[playerid][pSkin] = pData[playerid][pFractionSkin];
        set_player_skin(playerid, pData[playerid][pSkin]);
        isDress[playerid] = 1;
        SendSucc(playerid, "Вы успешно одели форму!");
    }
    else {
        pData[playerid][pSkin] =skinsjs[playerid];
        isDress[playerid] = 0;
        set_player_skin(playerid, pData[playerid][pSkin]);
        SendSucc(playerid, "Вы успешно сняли форму!");
    }
}

CMD:contraband(playerid, params[])
{
    if(!IsAMafia(playerid))
		return SendErr(playerid, "Данная команда доступна только ОПГ");
	if(pData[playerid][pRank] < 8) 
		return SendErr(playerid, "Функция доступна с 8 ранга");
    if(sscanf(params, "dd", params[0], params[1])) {
        SendErr(playerid, "/contraband [1 - лёгкие, 2 - тяжёлые] [кол-во]");
        SendInf(playerid, "лёгкие 1000, тяжелые 6000");
    }
    if(params[0] == 1 && pData[playerid][pMoney] < params[1]*1000)
        SendErr(playerid, "У Вас недостаточно средств");
    if(params[0] == 2 && pData[playerid][pMoney] < params[1]*6000)
        SendErr(playerid, "У Вас недостаточно средств");
        
    new mafID;
    switch(pData[playerid][pFraction])
	{
		case 13: mafID = 0;
		case 14: mafID = 1;
		case 15: mafID = 2;
	}
    
    if(params[0] == 1) {
        MafiaInfo[mafID][mDrugs] += params[2];
        give_money(playerid, -params[1]*1000);
        SendSucc(playerid, "Вы купили лёгкие наркотики");
    } else if(params[0] == 2) {
        MafiaInfo[mafID][mHdrugs] += params[2];
        give_money(playerid, -params[1]*6000);
        SendSucc(playerid, "Вы купили тяжёлые наркотики");
    }
}

CMD:frisk(playerid, params[])
{
    if(!IsACop(playerid)) return SendErr(playerid, "Эта функция только для МВД/ФСБ");
    if(sscanf(params, "d", params[0]))
        return SendErr(playerid, "/frisk [ID игрока]");
    if(!(GetPlayerDistanceToPlayer(playerid, params[0]) <= 5.0))
       return SendErr(playerid, "Вы не находитесь возле данного игрока");
       
   if(pData[params[0]][pDrugs]+pData[params[0]][pHDrugs] <= 0)
       return SendSucc(playerid, "Данный человек не имеет с собой наркотиков");
   else {
       new strnop[128];
       format(strnop, sizeof strnop, "Данный человек имеет с собой наркотики в размере %d штук", pData[params[0]][pDrugs]+pData[params[0]][pHDrugs]);
       return SendSucc(playerid, strnop);
   }
}


CMD:genrl(playerid, params[])
{
	if(sscanf(params, "d", params[0])) 
	{
		SendInf(playerid, "0 - ERR CASH | 1 - DONE CASH | 2 - WARNING | 3 - DONE | 4 - NOTIF + BTN");
		return SendInf(playerid, "/genrl [ID notif]");
	}

	switch(params[0])
	{
		case 0:
		{
			//format(String144, sizeof(String144), "%s", params[2]);
			//format(String256, sizeof(String256), "%s", params[3]);
			EROM(playerid, 0, "ERROR CASH NOTIF BY WEIKTON GAMES", 7, "", "");
		}
		case 1:
		{
			EROM(playerid, 1, "DONE CASH NOTIF BY WEIKTON GAMES", 7, "", "");
		}
		case 2:
		{
			EROM(playerid, 2, "ERROR NOTIF BY WEIKTON GAMES", 7, "", "");
		}
		case 3:
		{
			EROM(playerid, 3, "DONE NOTIF BY WEIKTON GAMES", 7, "", "");
		}
		case 4:
		{
			EROM(playerid, 4, "BTN + NOTIF BY WEIKTON GAMES", 7, "/test", "Далее");
			SCM(playerid, -1, "Уведомление вызывает команду /test");
		}
	}
	return 1;
}

CMD:test(playerid)
{
	SCM(playerid, -1, "WEIKTON | ERROR | JUSPER - TEST NOTIF");
	return 1;
}

CMD:llight(playerid)
{
	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) 
		return EROM(playerid, 0, "Вы должны находится за рулём автомобиля", 7, "", "");

	new 
		carid = GetPlayerVehicleID(playerid);
	vehicle_light_status(carid, !vehicle[carid][cLight]);
	/*if(vehicle_light_status(vehicleid, false))
	{
		vehicle_light_status(vehicleid, true);
	}
	
	if(vehicle_light_status(vehicleid, true))
	{
		vehicle_light_status(vehicleid, false);*/
	return 1;
}

CMD:cameditgui(playerid, params[])
{
        if(GetPVarInt(playerid,"cameditgui") == 0)
        {
            SetPVarInt(playerid,"cameditgui", 1);
            TogglePlayerAllHudElements(playerid, 0);
            EROM(playerid, 1, "Вы успешно скрыли игровой интерфейс", 7, "", "");
        }
        else
        {
             DeletePVar(playerid, "cameditgui");
            TogglePlayerAllHudElements(playerid, 1);
            EROM(playerid, 1, "Вы успешно включили отображение игрового интерфейса", 7, "", "");
        }
        return true;
}

CMD:pizda(playerid)
{
	SendErr(playerid, "Понял?");
	return 1;
}

CMD:strobs(playerid)
{
	EROM(playerid, 0, "Функция недоступна до ближайшего обновления", 7, "", "");
	return 1;
}

CMD:neon(playerid)
{
	EROM(playerid, 0, "Функция недоступна до ближайшего обновления", 7, "", "");
	return 1;
}