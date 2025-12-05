new bind_command_params[MAX_PLAYERS], bind_command_types[MAX_PLAYERS];

stock load_bind_command_player(playerid)
{
	format(String1024, sizeof(String1024), "SELECT * FROM `bind_command` WHERE `id` = '%d'", pData[playerid][pMysqlID]);
	new Result:rdd = sql_queryEx(zConn, String1024, QUERY_CACHED);

	if(sql_num_rows(rdd)) 
	{
	    sql_get_field(rdd, 1, pData[playerid][bind_command_1]);
	    sql_get_field(rdd, 2, pData[playerid][bind_command_2]);
	    sql_get_field(rdd, 3, pData[playerid][bind_command_3]);
	    sql_get_field(rdd, 4, pData[playerid][bind_command_4]);
	    sql_get_field(rdd, 5, pData[playerid][bind_command_5]);
	    sql_get_field(rdd, 6, pData[playerid][bind_command_6]);
	    sql_get_field(rdd, 7, pData[playerid][bind_command_7]);
	    sql_get_field(rdd, 8, pData[playerid][bind_command_8]);
	    sql_get_field(rdd, 9, pData[playerid][bind_command_9]);
	    sql_get_field(rdd, 10, pData[playerid][bind_command_10]);
	    sql_get_field(rdd, 11, pData[playerid][bind_command_11]);
	    sql_get_field(rdd, 12, pData[playerid][bind_command_12]);
	    sql_get_field(rdd, 13, pData[playerid][bind_command_13]);
	    sql_get_field(rdd, 14, pData[playerid][bind_command_14]);
	    sql_get_field(rdd, 15, pData[playerid][bind_command_15]);
	    sql_get_field(rdd, 16, pData[playerid][bind_command_16]);
	    sql_get_field(rdd, 17, pData[playerid][bind_command_17]);
	    sql_get_field(rdd, 18, pData[playerid][bind_command_18]);
	    sql_get_field(rdd, 19, pData[playerid][bind_command_19]);
	    sql_get_field(rdd, 20, pData[playerid][bind_command_20]);

	    pData[playerid][bind_command_type][0] = sql_get_field_int(rdd, 21);
	    pData[playerid][bind_command_type][1] = sql_get_field_int(rdd, 22);
	    pData[playerid][bind_command_type][2] = sql_get_field_int(rdd, 23);
	    pData[playerid][bind_command_type][3] = sql_get_field_int(rdd, 24);
	    pData[playerid][bind_command_type][4] = sql_get_field_int(rdd, 25);
	    pData[playerid][bind_command_type][5] = sql_get_field_int(rdd, 26);
	    pData[playerid][bind_command_type][6] = sql_get_field_int(rdd, 27);
	    pData[playerid][bind_command_type][7] = sql_get_field_int(rdd, 28);
	    pData[playerid][bind_command_type][8] = sql_get_field_int(rdd, 29);
	    pData[playerid][bind_command_type][9] = sql_get_field_int(rdd, 30);
	    pData[playerid][bind_command_type][10] = sql_get_field_int(rdd, 31);
	    pData[playerid][bind_command_type][11] = sql_get_field_int(rdd, 32);
	    pData[playerid][bind_command_type][12] = sql_get_field_int(rdd, 33);
	    pData[playerid][bind_command_type][13] = sql_get_field_int(rdd, 34);
	    pData[playerid][bind_command_type][14] = sql_get_field_int(rdd, 35);
	    pData[playerid][bind_command_type][15] = sql_get_field_int(rdd, 36);
	    pData[playerid][bind_command_type][16] = sql_get_field_int(rdd, 37);
	    pData[playerid][bind_command_type][17] = sql_get_field_int(rdd, 38);
	    pData[playerid][bind_command_type][18] = sql_get_field_int(rdd, 39);
	    pData[playerid][bind_command_type][19] = sql_get_field_int(rdd, 40);
	}
	else
	{
		format(String256, sizeof(String256), "INSERT INTO `bind_command` VALUES ('%d', \
			'0', '0', '0', '0', '0', '0', '0', '0',\
			'0', '0', '0', '0', '0', '0', '0', '0',\
			'0', '0', '0', '0', '0', '0', '0', '0',\
			'0', '0', '0', '0', '0', '0', '0', '0',\
			'0', '0', '0', '0', '0', '0', '0', '0'\
			)", pData[playerid][pMysqlID]);
		sql_queryEx(zConn, String256);
 	}

	sql_free_result(rdd);

	return true;
}

CMD:binder(playerid)
{
    menu_bind_command_general(playerid);

	return true;
}

CMD:b1(playerid)
{
	if(pData[playerid][pMut]) 
		return SendClientMessage(playerid,CGRAY,"У Вас бан чата. Используйте /mutetime чтобы узнать время бана.");

	if(pTemp[playerid][pMutM])
	{
		SendClientMessage(playerid,CGRAY,"У Вас затычка во рту.");
		return 1;
	}

	if(strlen(pData[playerid][bind_command_1]) < 2)
		return SendErr(playerid, "У вас не настроен биндер на данную команду. Настройка - /binder");

	if(pData[playerid][bind_command_type][0] == 3)
	{
		printf("%s", pData[playerid][bind_command_1]);
		TryAction(playerid, pData[playerid][bind_command_1]);
	}
	else if(pData[playerid][bind_command_type][0] == 2)
	{
		printf("%s", pData[playerid][bind_command_1]);
		DoAction(playerid, pData[playerid][bind_command_1]);
	}
	else if(pData[playerid][bind_command_type][0] == 1)
	{
		printf("%s", pData[playerid][bind_command_1]);
		MeActionEx(playerid, pData[playerid][bind_command_1]);
	}
	return true;
}

CMD:b2(playerid)
{
	if(pData[playerid][pMut]) 
		return SendClientMessage(playerid,CGRAY,"У Вас бан чата. Используйте /mutetime чтобы узнать время бана.");

	if(pTemp[playerid][pMutM])
	{
		SendClientMessage(playerid,CGRAY,"У Вас затычка во рту.");
		return 1;
	}

	if(strlen(pData[playerid][bind_command_2]) < 2)
		return SendErr(playerid, "У вас не настроен биндер на данную команду. Настройка - /binder");

	if(pData[playerid][bind_command_type][1] == 3)
	{
		TryAction(playerid, pData[playerid][bind_command_2]);
	}
	else if(pData[playerid][bind_command_type][1] == 2)
	{
		DoAction(playerid, pData[playerid][bind_command_2]);
	}
	else if(pData[playerid][bind_command_type][1] == 1)
	{
		MeActionEx(playerid, pData[playerid][bind_command_2]);
	}
	return true;
}

CMD:b3(playerid)
{
	if(pData[playerid][pMut]) 
		return SendClientMessage(playerid,CGRAY,"У Вас бан чата. Используйте /mutetime чтобы узнать время бана.");

	if(pTemp[playerid][pMutM])
	{
		SendClientMessage(playerid,CGRAY,"У Вас затычка во рту.");
		return 1;
	}

	if(strlen(pData[playerid][bind_command_3]) < 2)
		return SendErr(playerid, "У вас не настроен биндер на данную команду. Настройка - /binder");

	if(pData[playerid][bind_command_type][2] == 3)
	{
		TryAction(playerid, pData[playerid][bind_command_3]);
	}
	else if(pData[playerid][bind_command_type][2] == 2)
	{
		DoAction(playerid, pData[playerid][bind_command_3]);
	}
	else if(pData[playerid][bind_command_type][2] == 1)
	{
		MeActionEx(playerid, pData[playerid][bind_command_3]);
	}
	return true;
}

CMD:b4(playerid)
{
	if(pData[playerid][pMut]) 
		return SendClientMessage(playerid,CGRAY,"У Вас бан чата. Используйте /mutetime чтобы узнать время бана.");

	if(pTemp[playerid][pMutM])
	{
		SendClientMessage(playerid,CGRAY,"У Вас затычка во рту.");
		return 1;
	}

	if(strlen(pData[playerid][bind_command_4]) < 2)
		return SendErr(playerid, "У вас не настроен биндер на данную команду. Настройка - /binder");

	if(pData[playerid][bind_command_type][3] == 3)
	{
		TryAction(playerid, pData[playerid][bind_command_4]);
	}
	else if(pData[playerid][bind_command_type][3] == 2)
	{
		DoAction(playerid, pData[playerid][bind_command_4]);
	}
	else if(pData[playerid][bind_command_type][3] == 1)
	{
		MeActionEx(playerid, pData[playerid][bind_command_4]);
	}
	return true;
}

CMD:b5(playerid)
{
	if(pData[playerid][pMut]) 
		return SendClientMessage(playerid,CGRAY,"У Вас бан чата. Используйте /mutetime чтобы узнать время бана.");

	if(pTemp[playerid][pMutM])
	{
		SendClientMessage(playerid,CGRAY,"У Вас затычка во рту.");
		return 1;
	}

	if(strlen(pData[playerid][bind_command_5]) < 2)
		return SendErr(playerid, "У вас не настроен биндер на данную команду. Настройка - /binder");

	if(pData[playerid][bind_command_type][4] == 3)
	{
		TryAction(playerid, pData[playerid][bind_command_5]);
	}
	else if(pData[playerid][bind_command_type][4] == 2)
	{
		DoAction(playerid, pData[playerid][bind_command_5]);
	}
	else if(pData[playerid][bind_command_type][4] == 1)
	{
		MeActionEx(playerid, pData[playerid][bind_command_5]);
	}
	return true;
}

CMD:b6(playerid)
{
	if(pData[playerid][pMut]) 
		return SendClientMessage(playerid,CGRAY,"У Вас бан чата. Используйте /mutetime чтобы узнать время бана.");

	if(pTemp[playerid][pMutM])
	{
		SendClientMessage(playerid,CGRAY,"У Вас затычка во рту.");
		return 1;
	}

	if(strlen(pData[playerid][bind_command_6]) < 2)
		return SendErr(playerid, "У вас не настроен биндер на данную команду. Настройка - /binder");

	if(pData[playerid][bind_command_type][5] == 3)
	{
		TryAction(playerid, pData[playerid][bind_command_6]);
	}
	else if(pData[playerid][bind_command_type][5] == 2)
	{
		DoAction(playerid, pData[playerid][bind_command_6]);
	}
	else if(pData[playerid][bind_command_type][5] == 1)
	{
		MeActionEx(playerid, pData[playerid][bind_command_6]);
	}
	return true;
}

CMD:b7(playerid)
{
	if(pData[playerid][pMut]) 
		return SendClientMessage(playerid,CGRAY,"У Вас бан чата. Используйте /mutetime чтобы узнать время бана.");

	if(pTemp[playerid][pMutM])
	{
		SendClientMessage(playerid,CGRAY,"У Вас затычка во рту.");
		return 1;
	}

	if(strlen(pData[playerid][bind_command_7]) < 2)
		return SendErr(playerid, "У вас не настроен биндер на данную команду. Настройка - /binder");

	if(pData[playerid][bind_command_type][6] == 3)
	{
		TryAction(playerid, pData[playerid][bind_command_7]);
	}
	else if(pData[playerid][bind_command_type][6] == 2)
	{
		DoAction(playerid, pData[playerid][bind_command_7]);
	}
	else if(pData[playerid][bind_command_type][6] == 1)
	{
		MeActionEx(playerid, pData[playerid][bind_command_7]);
	}
	return true;
}

CMD:b8(playerid)
{
	if(pData[playerid][pMut]) 
		return SendClientMessage(playerid,CGRAY,"У Вас бан чата. Используйте /mutetime чтобы узнать время бана.");

	if(pTemp[playerid][pMutM])
	{
		SendClientMessage(playerid,CGRAY,"У Вас затычка во рту.");
		return 1;
	}

	if(strlen(pData[playerid][bind_command_8]) < 2)
		return SendErr(playerid, "У вас не настроен биндер на данную команду. Настройка - /binder");

	if(pData[playerid][bind_command_type][7] == 3)
	{
		TryAction(playerid, pData[playerid][bind_command_8]);
	}
	else if(pData[playerid][bind_command_type][7] == 2)
	{
		DoAction(playerid, pData[playerid][bind_command_8]);
	}
	else if(pData[playerid][bind_command_type][7] == 1)
	{
		MeActionEx(playerid, pData[playerid][bind_command_8]);
	}
	return true;
}

CMD:b9(playerid)
{
	if(pData[playerid][pMut]) 
		return SendClientMessage(playerid,CGRAY,"У Вас бан чата. Используйте /mutetime чтобы узнать время бана.");

	if(pTemp[playerid][pMutM])
	{
		SendClientMessage(playerid,CGRAY,"У Вас затычка во рту.");
		return 1;
	}

	if(strlen(pData[playerid][bind_command_9]) < 2)
		return SendErr(playerid, "У вас не настроен биндер на данную команду. Настройка - /binder");

	if(pData[playerid][bind_command_type][8] == 3)
	{
		TryAction(playerid, pData[playerid][bind_command_9]);
	}
	else if(pData[playerid][bind_command_type][8] == 2)
	{
		DoAction(playerid, pData[playerid][bind_command_9]);
	}
	else if(pData[playerid][bind_command_type][8] == 1)
	{
		MeActionEx(playerid, pData[playerid][bind_command_9]);
	}
	return true;
}

CMD:b10(playerid)
{
	if(pData[playerid][pMut]) 
		return SendClientMessage(playerid,CGRAY,"У Вас бан чата. Используйте /mutetime чтобы узнать время бана.");

	if(pTemp[playerid][pMutM])
	{
		SendClientMessage(playerid,CGRAY,"У Вас затычка во рту.");
		return 1;
	}

	if(strlen(pData[playerid][bind_command_10]) < 2)
		return SendErr(playerid, "У вас не настроен биндер на данную команду. Настройка - /binder");

	if(pData[playerid][bind_command_type][9] == 3)
	{
		TryAction(playerid, pData[playerid][bind_command_10]);
	}
	else if(pData[playerid][bind_command_type][9] == 2)
	{
		DoAction(playerid, pData[playerid][bind_command_10]);
	}
	else if(pData[playerid][bind_command_type][9] == 1)
	{
		MeActionEx(playerid, pData[playerid][bind_command_10]);
	}
	return true;
}

CMD:b11(playerid)
{
	if(pData[playerid][pMut]) 
		return SendClientMessage(playerid,CGRAY,"У Вас бан чата. Используйте /mutetime чтобы узнать время бана.");

	if(pTemp[playerid][pMutM])
	{
		SendClientMessage(playerid,CGRAY,"У Вас затычка во рту.");
		return 1;
	}

	if(strlen(pData[playerid][bind_command_11]) < 2)
		return SendErr(playerid, "У вас не настроен биндер на данную команду. Настройка - /binder");

	if(pData[playerid][bind_command_type][10] == 3)
	{
		TryAction(playerid, pData[playerid][bind_command_11]);
	}
	else if(pData[playerid][bind_command_type][10] == 2)
	{
		DoAction(playerid, pData[playerid][bind_command_11]);
	}
	else if(pData[playerid][bind_command_type][10] == 1)
	{
		MeActionEx(playerid, pData[playerid][bind_command_11]);
	}
	return true;
}

CMD:b12(playerid)
{
	if(pData[playerid][pMut]) 
		return SendClientMessage(playerid,CGRAY,"У Вас бан чата. Используйте /mutetime чтобы узнать время бана.");

	if(pTemp[playerid][pMutM])
	{
		SendClientMessage(playerid,CGRAY,"У Вас затычка во рту.");
		return 1;
	}

	if(strlen(pData[playerid][bind_command_12]) < 2)
		return SendErr(playerid, "У вас не настроен биндер на данную команду. Настройка - /binder");

	if(pData[playerid][bind_command_type][11] == 3)
	{
		TryAction(playerid, pData[playerid][bind_command_12]);
	}
	else if(pData[playerid][bind_command_type][11] == 2)
	{
		DoAction(playerid, pData[playerid][bind_command_12]);
	}
	else if(pData[playerid][bind_command_type][11] == 1)
	{
		MeActionEx(playerid, pData[playerid][bind_command_12]);
	}
	return true;
}

CMD:b13(playerid)
{
	if(pData[playerid][pMut]) 
		return SendClientMessage(playerid,CGRAY,"У Вас бан чата. Используйте /mutetime чтобы узнать время бана.");

	if(pTemp[playerid][pMutM])
	{
		SendClientMessage(playerid,CGRAY,"У Вас затычка во рту.");
		return 1;
	}

	if(strlen(pData[playerid][bind_command_13]) < 2)
		return SendErr(playerid, "У вас не настроен биндер на данную команду. Настройка - /binder");

	if(pData[playerid][bind_command_type][12] == 3)
	{
		TryAction(playerid, pData[playerid][bind_command_13]);
	}
	else if(pData[playerid][bind_command_type][12] == 2)
	{
		DoAction(playerid, pData[playerid][bind_command_13]);
	}
	else if(pData[playerid][bind_command_type][12] == 1)
	{
		MeActionEx(playerid, pData[playerid][bind_command_13]);
	}
	return true;
}

CMD:b14(playerid)
{
	if(pData[playerid][pMut]) 
		return SendClientMessage(playerid,CGRAY,"У Вас бан чата. Используйте /mutetime чтобы узнать время бана.");

	if(pTemp[playerid][pMutM])
	{
		SendClientMessage(playerid,CGRAY,"У Вас затычка во рту.");
		return 1;
	}

	if(strlen(pData[playerid][bind_command_14]) < 2)
		return SendErr(playerid, "У вас не настроен биндер на данную команду. Настройка - /binder");

	if(pData[playerid][bind_command_type][13] == 3)
	{
		TryAction(playerid, pData[playerid][bind_command_14]);
	}
	else if(pData[playerid][bind_command_type][13] == 2)
	{
		DoAction(playerid, pData[playerid][bind_command_14]);
	}
	else if(pData[playerid][bind_command_type][13] == 1)
	{
		MeActionEx(playerid, pData[playerid][bind_command_14]);
	}
	return true;
}

CMD:b15(playerid)
{
	if(pData[playerid][pMut]) 
		return SendClientMessage(playerid,CGRAY,"У Вас бан чата. Используйте /mutetime чтобы узнать время бана.");

	if(pTemp[playerid][pMutM])
	{
		SendClientMessage(playerid,CGRAY,"У Вас затычка во рту.");
		return 1;
	}

	if(strlen(pData[playerid][bind_command_15]) < 2)
		return SendErr(playerid, "У вас не настроен биндер на данную команду. Настройка - /binder");

	if(pData[playerid][bind_command_type][14] == 3)
	{
		TryAction(playerid, pData[playerid][bind_command_15]);
	}
	else if(pData[playerid][bind_command_type][14] == 2)
	{
		DoAction(playerid, pData[playerid][bind_command_15]);
	}
	else if(pData[playerid][bind_command_type][14] == 1)
	{
		MeActionEx(playerid, pData[playerid][bind_command_15]);
	}
	return true;
}

CMD:b16(playerid)
{
	if(pData[playerid][pMut]) 
		return SendClientMessage(playerid,CGRAY,"У Вас бан чата. Используйте /mutetime чтобы узнать время бана.");

	if(pTemp[playerid][pMutM])
	{
		SendClientMessage(playerid,CGRAY,"У Вас затычка во рту.");
		return 1;
	}

	if(strlen(pData[playerid][bind_command_16]) < 2)
		return SendErr(playerid, "У вас не настроен биндер на данную команду. Настройка - /binder");

	if(pData[playerid][bind_command_type][15] == 3)
	{
		TryAction(playerid, pData[playerid][bind_command_16]);
	}
	else if(pData[playerid][bind_command_type][15] == 2)
	{
		DoAction(playerid, pData[playerid][bind_command_16]);
	}
	else if(pData[playerid][bind_command_type][15] == 1)
	{
		MeActionEx(playerid, pData[playerid][bind_command_16]);
	}
	return true;
}

CMD:b17(playerid)
{
	if(pData[playerid][pMut]) 
		return SendClientMessage(playerid,CGRAY,"У Вас бан чата. Используйте /mutetime чтобы узнать время бана.");

	if(pTemp[playerid][pMutM])
	{
		SendClientMessage(playerid,CGRAY,"У Вас затычка во рту.");
		return 1;
	}

	if(strlen(pData[playerid][bind_command_17]) < 2)
		return SendErr(playerid, "У вас не настроен биндер на данную команду. Настройка - /binder");

	if(pData[playerid][bind_command_type][16] == 3)
	{
		TryAction(playerid, pData[playerid][bind_command_17]);
	}
	else if(pData[playerid][bind_command_type][16] == 2)
	{
		DoAction(playerid, pData[playerid][bind_command_17]);
	}
	else if(pData[playerid][bind_command_type][16] == 1)
	{
		MeActionEx(playerid, pData[playerid][bind_command_17]);
	}
	return true;
}

CMD:b18(playerid)
{
	if(pData[playerid][pMut]) 
		return SendClientMessage(playerid,CGRAY,"У Вас бан чата. Используйте /mutetime чтобы узнать время бана.");

	if(pTemp[playerid][pMutM])
	{
		SendClientMessage(playerid,CGRAY,"У Вас затычка во рту.");
		return 1;
	}

	if(strlen(pData[playerid][bind_command_18]) < 2)
		return SendErr(playerid, "У вас не настроен биндер на данную команду. Настройка - /binder");

	if(pData[playerid][bind_command_type][17] == 3)
	{
		TryAction(playerid, pData[playerid][bind_command_18]);
	}
	else if(pData[playerid][bind_command_type][17] == 2)
	{
		DoAction(playerid, pData[playerid][bind_command_18]);
	}
	else if(pData[playerid][bind_command_type][17] == 1)
	{
		MeActionEx(playerid, pData[playerid][bind_command_18]);
	}
	return true;
}

CMD:b19(playerid)
{
	if(pData[playerid][pMut]) 
		return SendClientMessage(playerid,CGRAY,"У Вас бан чата. Используйте /mutetime чтобы узнать время бана.");

	if(pTemp[playerid][pMutM])
	{
		SendClientMessage(playerid,CGRAY,"У Вас затычка во рту.");
		return 1;
	}

	if(strlen(pData[playerid][bind_command_19]) < 2)
		return SendErr(playerid, "У вас не настроен биндер на данную команду. Настройка - /binder");

	if(pData[playerid][bind_command_type][18] == 3)
	{
		TryAction(playerid, pData[playerid][bind_command_19]);
	}
	else if(pData[playerid][bind_command_type][18] == 2)
	{
		DoAction(playerid, pData[playerid][bind_command_19]);
	}
	else if(pData[playerid][bind_command_type][18] == 1)
	{
		MeActionEx(playerid, pData[playerid][bind_command_19]);
	}
	return true;
}

CMD:b20(playerid)
{
	if(pData[playerid][pMut]) 
		return SendClientMessage(playerid,CGRAY,"У Вас бан чата. Используйте /mutetime чтобы узнать время бана.");

	if(pTemp[playerid][pMutM])
	{
		SendClientMessage(playerid,CGRAY,"У Вас затычка во рту.");
		return 1;
	}

	if(strlen(pData[playerid][bind_command_20]) < 2)
		return SendErr(playerid, "У вас не настроен биндер на данную команду. Настройка - /binder");

	if(pData[playerid][bind_command_type][19] == 3)
	{
		TryAction(playerid, pData[playerid][bind_command_20]);
	}
	else if(pData[playerid][bind_command_type][19] == 2)
	{
		DoAction(playerid, pData[playerid][bind_command_20]);
	}
	else if(pData[playerid][bind_command_type][19] == 1)
	{
		MeActionEx(playerid, pData[playerid][bind_command_20]);
	}
	return true;
}

stock menu_bind_command_general(playerid)
{

    format(String1024,sizeof(String1024),""cGREY"Наименование\t"cGREY"Команда\t\n\
    "cBLUE"1. "cWH"Бинд команды - B1\t /b1\n\
    "cBLUE"2. "cWH"Бинд команды - B2\t /b2\n\
    "cBLUE"3. "cWH"Бинд команды - B3\t /b3\n\
    "cBLUE"4. "cWH"Бинд команды - B4\t /b4\n\
    "cBLUE"5. "cWH"Бинд команды - B5\t /b5\n\
    "cBLUE"6. "cWH"Бинд команды - B6\t /b6\n\
    "cBLUE"7. "cWH"Бинд команды - B7\t /b7\n\
    "cBLUE"8. "cWH"Бинд команды - B8\t /b8\n\
    "cBLUE"9. "cWH"Бинд команды - B9\t /b9\n\
    "cBLUE"10. "cWH"Бинд команды - B10\t /b10\n\
    "cBLUE"11. "cWH"Бинд команды - B11\t /b11\n\
    "cBLUE"12. "cWH"Бинд команды - B12\t /b12\n\
    "cBLUE"13. "cWH"Бинд команды - B13\t /b13\n\
    "cBLUE"14. "cWH"Бинд команды - B14\t /b14\n\
    "cBLUE"15. "cWH"Бинд команды - B15\t /b15\n\
    "cBLUE"16. "cWH"Бинд команды - B16\t /b16\n\
    "cBLUE"17. "cWH"Бинд команды - B17\t /b17\n\
    "cBLUE"18. "cWH"Бинд команды - B18\t /b18\n\
    "cBLUE"19. "cWH"Бинд команды - B19\t /b19\n\
    "cBLUE"20. "cWH"Бинд команды - B20\t /b20");

    SPD(playerid, DIALOG_BIND_COMMAND_G, DIALOG_STYLE_TABLIST_HEADERS,!""cBLUE"Настройка биндера:",String1024,!"Открыть",!"Закрыть"); 	
	return true;
}

stock set_bind_command_config(playerid, type)
{
	bind_command_params[playerid] = type;

	SendSucc(playerid, "Вы успешно выбрали команду, на которую будете устанавливать биндер!");
	SendInf(playerid, "Далее Вам следует выбрать тип команды, которая будет использоваться!");

	return select_type_bind_command(playerid);
}


stock select_type_bind_command(playerid)
{
    format(String256,sizeof(String256),""cGREY"Наименование\t"cGREY"Тип\t\n\
    "cBLUE"1. "cWH"Бинд для команды - /me\t"cBLUE"Изменить\n\
    "cBLUE"2. "cWH"Бинд для команды - /do\t"cBLUE"Изменить\n\
    "cBLUE"3. "cWH"Бинд для команды - /try\t"cBLUE"Изменить");

    SPD(playerid, DIALOG_BIND_COMMAND_T, DIALOG_STYLE_TABLIST_HEADERS,!""cBLUE"Настройка биндера:",String256,!"Открыть",!"Закрыть"); 
   
    return true;
}

stock set_bind_type_config(playerid, type)
{
    bind_command_types[playerid] = type;

	SendSucc(playerid, "Вы успешно выбрали тип команды, на которую будете устанавливать биндер!");
	SendInf(playerid, "Далее Вам следует ввести текст, который будет выводиться при использовании!");
	SendInf(playerid, "Текст должен быть до 128 символов! Минимум - 6 символов!");

	return dialog_input_bind_command(playerid);
}

stock dialog_input_bind_command(playerid)
{
	new 
		fmt_str[350];

	format(fmt_str, 350, \
		""cBLUE"-"cWH" Минимальное количество символов - 6 символов\n\
		"cBLUE"-"cWH" Максимальное количество символов - 128 символов\n\n\
		"cBLUE"-"cWH" Тип на которую будет применен текст - "cBLUE"%s\n\
		"cBLUE"-"cWH" Команда на которую будет применен текст - "cBLUE"%s", get_name_bind_type(bind_command_types[playerid]), 
		get_name_bind_command(bind_command_params[playerid]));
	SPD(playerid, DIALOG_BIND_COMMAND_W, DIALOG_STYLE_INPUT, !""cBLUE"Текст для биндера:", fmt_str, !"Войти", !"Отмена");

	return true;
}


stock get_name_bind_type(type_id)
{
	new 
		name[35];

	switch(type_id)
	{
		case 1: name = "/me";
		case 2: name = "/do";
		case 3: name = "/try";
		default: name = "Не выбран";
	}
	return name;
}

stock get_name_bind_command(type_id)
{
	new 
		name[35];

	switch(type_id)
	{
		case 1: name = "/b1";
		case 2: name = "/b2";
		case 3: name = "/b3";
		case 4: name = "/b4";
		case 5: name = "/b5";
		case 6: name = "/b6";	
		case 7: name = "/b7";
		case 8: name = "/b8";	
		case 9: name = "/b9";
		case 10: name = "/b10";
		case 11: name = "/b11";
		case 12: name = "/b12";
		case 13: name = "/b13";
		case 14: name = "/b14";	
		case 15: name = "/b15";
		case 16: name = "/b16";	
		case 17: name = "/b17";
		case 18: name = "/b18";	
		case 19: name = "/b19";
		case 20: name = "/b20";
		default: name = "Не выбран";
	}
	return name;
}


stock dialog_bind_command(playerid, dialogid, response, listitem, inputtext[]) 
{
	switch(dialogid)
	{
		case DIALOG_BIND_COMMAND_G:
		{
			if(!response) 
				return true;

			switch(listitem)
			{
				case 0: return set_bind_command_config(playerid, 1);
				case 1: return set_bind_command_config(playerid, 2);
				case 2: return set_bind_command_config(playerid, 3);
				case 3: return set_bind_command_config(playerid, 4);
				case 4: return set_bind_command_config(playerid, 5);
				case 5: return set_bind_command_config(playerid, 6);
				case 6: return set_bind_command_config(playerid, 7);
				case 7: return set_bind_command_config(playerid, 8);
				case 8: return set_bind_command_config(playerid, 9);
				case 9: return set_bind_command_config(playerid, 10);
				case 10: return set_bind_command_config(playerid, 11);
				case 11: return set_bind_command_config(playerid, 12);
				case 12: return set_bind_command_config(playerid, 13);
				case 13: return set_bind_command_config(playerid, 14);
				case 14: return set_bind_command_config(playerid, 15);
				case 15: return set_bind_command_config(playerid, 16);
				case 16: return set_bind_command_config(playerid, 17);
				case 17: return set_bind_command_config(playerid, 18);
				case 18: return set_bind_command_config(playerid, 19);
				case 19: return set_bind_command_config(playerid, 20);
			}
		}
		case DIALOG_BIND_COMMAND_T:
		{
			if(!response) 
				return true;
				
			switch(listitem)
			{
				case 0: return set_bind_type_config(playerid, 1);
				case 1: return set_bind_type_config(playerid, 2);
				case 2: return set_bind_type_config(playerid, 3);
			}			
		}
		case DIALOG_BIND_COMMAND_W:
		{
			if(!strlen(inputtext)) 
				return true;

			if(strlen(inputtext) < 6 || strlen(inputtext) > 128) 
				return dialog_input_bind_command(playerid);
				
			if(check_no_valid_symbol_text(inputtext) || check_sql_injection_text(inputtext))
			{
				return SendErr(playerid,"Бинд запрещенные символы!");
			}

			if(bind_command_params[playerid] == 1)
			{
				sql_escape_string(zConn, inputtext, pData[playerid][bind_command_1], 128);
			}
			else if(bind_command_params[playerid] == 2)
			{
				sql_escape_string(zConn, inputtext, pData[playerid][bind_command_2], 128);
			}
			else if(bind_command_params[playerid] == 3)
			{
				sql_escape_string(zConn, inputtext, pData[playerid][bind_command_3], 128);
			}
			else if(bind_command_params[playerid] == 4)
			{
				sql_escape_string(zConn, inputtext, pData[playerid][bind_command_4], 128);
			}
			else if(bind_command_params[playerid] == 5)
			{
				sql_escape_string(zConn, inputtext, pData[playerid][bind_command_5], 128);
			}
			else if(bind_command_params[playerid] == 6)
			{
				sql_escape_string(zConn, inputtext, pData[playerid][bind_command_6], 128);
			}
			else if(bind_command_params[playerid] == 7)
			{
				sql_escape_string(zConn, inputtext, pData[playerid][bind_command_7], 128);
			}
			else if(bind_command_params[playerid] == 8)
			{
				sql_escape_string(zConn, inputtext, pData[playerid][bind_command_8], 128);
			}
			else if(bind_command_params[playerid] == 9)
			{
				sql_escape_string(zConn, inputtext, pData[playerid][bind_command_9], 128);
			}
			else if(bind_command_params[playerid] == 10)
			{
				sql_escape_string(zConn, inputtext, pData[playerid][bind_command_10], 128);
			}
			else if(bind_command_params[playerid] == 11)
			{
				sql_escape_string(zConn, inputtext, pData[playerid][bind_command_11], 128);
			}
			else if(bind_command_params[playerid] == 12)
			{
				sql_escape_string(zConn, inputtext, pData[playerid][bind_command_12], 128);
			}
			else if(bind_command_params[playerid] == 13)
			{
				sql_escape_string(zConn, inputtext, pData[playerid][bind_command_13], 128);
			}
			else if(bind_command_params[playerid] == 14)
			{
				sql_escape_string(zConn, inputtext, pData[playerid][bind_command_14], 128);
			}
			else if(bind_command_params[playerid] == 15)
			{
				sql_escape_string(zConn, inputtext, pData[playerid][bind_command_15], 128);
			}
			else if(bind_command_params[playerid] == 16)
			{
				sql_escape_string(zConn, inputtext, pData[playerid][bind_command_16], 128);
			}
			else if(bind_command_params[playerid] == 17)
			{
				sql_escape_string(zConn, inputtext, pData[playerid][bind_command_17], 128);
			}
			else if(bind_command_params[playerid] == 18)
			{
				sql_escape_string(zConn, inputtext, pData[playerid][bind_command_18], 128);
			}
			else if(bind_command_params[playerid] == 19)
			{
			    sql_escape_string(zConn, inputtext, pData[playerid][bind_command_19], 128);
			}
			else if(bind_command_params[playerid] == 20)
			{
				sql_escape_string(zConn, inputtext, pData[playerid][bind_command_20], 128);
			}
			
			pData[playerid][bind_command_type][bind_command_params[playerid]-1] = bind_command_types[playerid];

			format(String4096,sizeof(String4096),"UPDATE `bind_command` SET `b1` = '%s', `b2` = '%s', \
			`b3` = '%s', `b4` = '%s', `b5` = '%s', `b6` = '%s', `b7` = '%s', `b8` = '%s', `b9` = '%s', `b10` = '%s',\
			`b11` = '%s',`b12` = '%s',`b13` = '%s',`b14` = '%s',`b15` = '%s',`b16` = '%s',`b17` = '%s',`b18` = '%s',`b19` = '%s',\
			`b20` = '%s', \
			`b1_type` = '%d', `b2_type` = '%d', `b3_type` = '%d', `b4_type` = '%d', `b5_type` = '%d', `b6_type` = '%d',\
			`b7_type` = '%d', `b8_type` = '%d', `b9_type` = '%d', `b10_type` = '%d', `b11_type` = '%d', `b12_type` = '%d', `b13_type` = '%d',\
			`b14_type` = '%d', `b15_type` = '%d', `b16_type` = '%d', `b17_type` = '%d', `b18_type` = '%d', `b19_type` = '%d', `b20_type` = '%d' WHERE `id` = '%d'",
			pData[playerid][bind_command_1], pData[playerid][bind_command_2], pData[playerid][bind_command_3],
			pData[playerid][bind_command_4], pData[playerid][bind_command_5], pData[playerid][bind_command_6],
			pData[playerid][bind_command_7], pData[playerid][bind_command_8], pData[playerid][bind_command_9],
			pData[playerid][bind_command_10],pData[playerid][bind_command_11],pData[playerid][bind_command_12],pData[playerid][bind_command_13],
			pData[playerid][bind_command_14],pData[playerid][bind_command_15],pData[playerid][bind_command_16],pData[playerid][bind_command_17],
			pData[playerid][bind_command_18],pData[playerid][bind_command_19],pData[playerid][bind_command_20],
			pData[playerid][bind_command_type][0], pData[playerid][bind_command_type][1], pData[playerid][bind_command_type][2],
			pData[playerid][bind_command_type][3], pData[playerid][bind_command_type][4], pData[playerid][bind_command_type][5],
			pData[playerid][bind_command_type][6], pData[playerid][bind_command_type][7], pData[playerid][bind_command_type][8], 
			pData[playerid][bind_command_type][9], pData[playerid][bind_command_type][10], pData[playerid][bind_command_type][11], 
			pData[playerid][bind_command_type][12], pData[playerid][bind_command_type][13], pData[playerid][bind_command_type][14],
			pData[playerid][bind_command_type][15], pData[playerid][bind_command_type][16], pData[playerid][bind_command_type][17],
            pData[playerid][bind_command_type][18], pData[playerid][bind_command_type][19], pData[playerid][pMysqlID]);
            
            sql_queryEx(zConn, String4096, QUERY_THREADED);

			SendSucc(playerid, "Вы успешно настроили биндер на клавишу!");

		}
	}
	return true;
}