
stock logs_money(playerid, userid, sum_action, action[])
{
	new 
		ip_logs[24];
		
	GetPlayerIp(playerid, ip_logs, 24);

	new	
		query[105+(-2+8)+(-2+MAX_PLAYER_NAME)+(-2+12)+(-2+64)+(-2+sizeof(ip_logs))];
		
	format
	(
		query,
		sizeof(query),
		"INSERT INTO logs_cash(userid, name, action_sum, action, ipaddress) VALUES ('%d', '%s', '%d', '%s', '%s')",
		userid,
		GetNameEx(playerid),
		sum_action,
		action,
		ip_logs
	);
	
	mysql_tquery(connect_logs, query);
	

	return true;
}

stock logs_vehicle(playerid, userid, action[])
{
	new 
		ip_logs[24];

	GetPlayerIp(playerid, ip_logs, 24);

	new	
		query[86+(-2+8)+(-2+MAX_PLAYER_NAME)+(-2+64)+(-2+sizeof(ip_logs))];
		
	format
	(
		query,
		sizeof(query),
		"INSERT INTO logs_vehicle(userid, name, action, ipaddress) VALUES ('%d', '%s', '%s', '%s')",
		userid,
		GetNameEx(playerid),
		action,
		ip_logs
	);
	
	mysql_tquery(connect_logs, query);

	return true;
}


stock logs_donate(playerid, userid, sum_action, action[])
{
	new 
		ip_logs[24];

	GetPlayerIp(playerid, ip_logs, 24);

	new	
		query[106+(-2+8)+(-2+MAX_PLAYER_NAME)+(-2+16)+(-2+64)+(-2+sizeof(ip_logs))];
		
	format
	(
		query,
		sizeof(query),
		"INSERT INTO logs_donate(userid, name, action_sum, action, ipaddress) VALUES ('%d', '%s', '%d', '%s', '%s')",
		userid,
		GetNameEx(playerid),
		action,
		ip_logs
	);
	
	mysql_tquery(connect_logs, query);

	return true;
}

stock logs_inventory(playerid, userid, sum_action, action[])
{
	new 
		ip_logs[24];

	GetPlayerIp(playerid, ip_logs, 24);

	format(String256f,sizeof(String256f),"INSERT INTO `logs_inventory`(userid, username, sum_action, action, ip) VALUES ('%d', '%s', '%d', '%s', '%s')", userid, pData[playerid][pNickname], sum_action, action, ip_logs);
	mysql_tquery(connect_logs, String256f);

	return true;
}

stock logs_connection(playerid, nickname[], action[])
{
	new 
		ip_logs[24];

	GetPlayerIp(playerid, ip_logs, 24);

	format(String256f,sizeof(String256f),"INSERT INTO `logs_connection`(username, action, ip) VALUES ('%s', '%s', '%s')", nickname, action, ip_logs);
	mysql_tquery(connect_logs, String256f);

	return true;
}


stock logs_admin(playerid, userid, action[])
{


	format(String256f,sizeof(String256f),"INSERT INTO `logs_admin`(userid, username, action) VALUES ('%d', '%s', '%s')", userid, pData[playerid][pNickname], action);
	mysql_tquery(connect_logs, String256f);

	return true;
}

stock logs_admin_other(playerid, userid, action[])
{


	format(String256f,sizeof(String256f),"INSERT INTO `logs_admin_other`(userid, username, action) VALUES ('%d', '%s', '%s')", userid, pData[playerid][pNickname], action);
	mysql_tquery(connect_logs, String256f);

	return true;
}

stock logs_admin_achat(playerid, userid, action[])
{


	format(String256f,sizeof(String256f),"INSERT INTO `logs_admin_achat`(userid, username, action) VALUES ('%d', '%s', '%s')", userid, pData[playerid][pNickname], action);
	mysql_tquery(connect_logs, String256f);

	return true;
}

stock logs_admin_report(playerid, userid, action[])
{


	format(String256f,sizeof(String256f),"INSERT INTO `logs_admin_report`(userid, username, action) VALUES ('%d', '%s', '%s')", userid, pData[playerid][pNickname], action);
	mysql_tquery(connect_logs, String256f);

	return true;
}

stock logs_status_server_info(action[])
{
	format(String256f,sizeof(String256f),"INSERT INTO `logs_status_server_info`(action) VALUES ('%s')", action);
	mysql_tquery(connect_logs, String256f);

	return true;	
}

stock logs_payday_info(action[])
{
	format(String256f,sizeof(String256f),"INSERT INTO `logs_payday`(action) VALUES ('%s')", action);
	mysql_tquery(connect_logs, String256f);

	return true;	
}


stock logs_payday_property(userid, action[])
{


	format(String256f,sizeof(String256f),"INSERT INTO `logs_payday_property`(userid, action) VALUES ('%d', '%s')", userid, action);
	mysql_tquery(connect_logs, String256f);

	return true;
}

stock logs_payday_property_sell(userid, action[])
{


	format(String256f,sizeof(String256f),"INSERT INTO `logs_payday_property_sell`(userid, action) VALUES ('%d', '%s')", userid, action);
	mysql_tquery(connect_logs, String256f);

	return true;
}

stock logs_payday_property_final(userid, action[])
{


	format(String256f,sizeof(String256f),"INSERT INTO `logs_payday_property_final`(userid, action) VALUES ('%d', '%s')", userid, action);
	mysql_tquery(connect_logs, String256f);

	return true;
}

stock logs_quest_player(playerid, userid, action[])
{


	format(String256f,sizeof(String256f),"INSERT INTO `logs_quest_player`(userid, username, action) VALUES ('%d', '%s', '%s')", userid, pData[playerid][pNickname], action);
	mysql_tquery(connect_logs, String256f);

	return true;
}

stock logs_prize_newyear_player(playerid, userid, action[])
{


	format(String256f,sizeof(String256f),"INSERT INTO `logs_prize_newyear_player`(userid, username, action) VALUES ('%d', '%s', '%s')", userid, pData[playerid][pNickname], action);
	mysql_tquery(connect_logs, String256f);

	return true;
}

stock logs_player_crashe(playerid, userid, action[])
{


	format(String256f,sizeof(String256f),"INSERT INTO `logs_player_crashe`(userid, username, action) VALUES ('%d', '%s', '%s')", userid, pData[playerid][pNickname], action);
	mysql_tquery(connect_logs, String256f);

	return true;
}


stock logs_player_casino_win(playerid, userid, action[])
{


	format(String256f,sizeof(String256f),"INSERT INTO `logs_player_casino_win`(userid, username, action) VALUES ('%d', '%s', '%s')", userid, pData[playerid][pNickname], action);
	mysql_tquery(connect_logs, String256f);

	return true;
}

stock logs_player_dialog(playerid, userid, action[])
{


	format(String256f,sizeof(String256f),"INSERT INTO `logs_player_dialog`(userid, username, action) VALUES ('%d', '%s', '%s')", userid, pData[playerid][pNickname], action);
	mysql_tquery(connect_logs, String256f);

	return true;
}




stock logs_player_crashe_other(playerid, userid)
{
	new 
		fmt_str[256];

	format(fmt_str, sizeof(fmt_str), "SELECT * FROM logs_player_crashe_unique WHERE username = '%s'", pData[playerid][pNickname]);
	new Cache:account_pc_user = mysql_query(zConnLog, fmt_str);

	new 
		count_crash;

	if(cache_num_rows()) 
	{
		cache_get_value_name_int(i, "count_crash", count_crash); 

		count_crash++;

		format(String256,sizeof(String256),"UPDATE `logs_player_crashe_unique` SET `count_crash`='%d', `packet_loss`='%.1f' WHERE `username`='%s'", count_crash, NetStats_PacketLossPercent(playerid), pData[playerid][pNickname]);	
		mysql_tquery(connect_logs, String256f);

	}
	else
	{
		format(String256f,sizeof(String256f),"INSERT INTO `logs_player_crashe_unique`(userid, username, count_crash, packet_loss) VALUES ('%d', '%s', '%d', '%.1f')", userid, pData[playerid][pNickname], 0, NetStats_PacketLossPercent(playerid));
		mysql_tquery(connect_logs, String256f);
	}
	cache_delete(account_pc_user);
	return true;
}