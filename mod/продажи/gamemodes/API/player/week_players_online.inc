new 
	day_player_week;

stock get_day_player_week()
{
	new 
		year, month, day;

	getdate(year, month, day);

	day_player_week = weekday(day, month, year);
}

callback:: update_player_online_week()
{
	if(day_player_week == 1)
	{
		foreach(new i : logged_players)
		{
			pData[i][pOnlineDay1] = pData[i][pOnlineDay2] = pData[i][pOnlineDay3] = pData[i][pOnlineDay4] = pData[i][pOnlineDay5] = pData[i][pOnlineDay6] = pData[i][pOnlineDay7] = 0;
		}

		sql_queryEx(zConn, "UPDATE `accounts` SET `pOnlineDay1` = '0', `pOnlineDay2` = '0', `pOnlineDay3` = '0', `pOnlineDay4` = '0', `pOnlineDay5` = '0', `pOnlineDay6` = '0', `pOnlineDay7` = '0'", QUERY_THREADED);
	}
	return true;
}

stock get_player_day_online(playerid)
{
	new 
		week_online_params;

	switch(day_player_week)
	{
		case 1: week_online_params = pData[playerid][pOnlineDay1]; 
		case 2: week_online_params = pData[playerid][pOnlineDay2]; 
		case 3: week_online_params = pData[playerid][pOnlineDay3]; 
		case 4: week_online_params = pData[playerid][pOnlineDay4]; 
		case 5: week_online_params = pData[playerid][pOnlineDay5]; 
		case 6: week_online_params = pData[playerid][pOnlineDay6]; 
		case 0: week_online_params = pData[playerid][pOnlineDay7]; 
	}	
	return week_online_params;
}

stock get_player_day_prew_online(playerid)
{
	new 
		week_online_params;

	switch(day_player_week-1)
	{
		case 1: week_online_params = pData[playerid][pOnlineDay1]; 
		case 2: week_online_params = pData[playerid][pOnlineDay2]; 
		case 3: week_online_params = pData[playerid][pOnlineDay3]; 
		case 4: week_online_params = pData[playerid][pOnlineDay4]; 
		case 5: week_online_params = pData[playerid][pOnlineDay5]; 
		case 6: week_online_params = pData[playerid][pOnlineDay6]; 
		case 0: week_online_params = pData[playerid][pOnlineDay7]; 
	}	
	return week_online_params;
}

stock get_player_week_online(playerid)
{
	new 
		week_online_params;

	week_online_params = pData[playerid][pOnlineDay1] + pData[playerid][pOnlineDay2] + pData[playerid][pOnlineDay3] + pData[playerid][pOnlineDay4] + pData[playerid][pOnlineDay5]
	+ pData[playerid][pOnlineDay5] + pData[playerid][pOnlineDay6] + pData[playerid][pOnlineDay7];
	return week_online_params;
}

callback:: update_player_online(i)
{
	switch(day_player_week)
	{
		case 1: pData[i][pOnlineDay1] ++;
		case 2: pData[i][pOnlineDay2] ++;
		case 3: pData[i][pOnlineDay3] ++;
		case 4: pData[i][pOnlineDay4] ++;
		case 5: pData[i][pOnlineDay5] ++;
		case 6: pData[i][pOnlineDay6] ++;
		case 0: pData[i][pOnlineDay7] ++;
	}
}