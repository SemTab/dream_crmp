new 
	STATUS_SERVER_IN_CONNECT = 0;

stock OnValidPlayerConnected(playerid, szSerial[], szLibraries[])
{
	printf("[CHECK ANDROID]: %d - valid client mobile", playerid);



	type_player_systems[playerid] = PLAYER_IN_MOBILE_VERSION;


	return true;
}

stock OnInvalidPlayerConnected(playerid)
{
	printf("[CHECK ANDROID]: %d - invalid client mobile", playerid);


	static
		fmt_str[500];

    new player_name[24];
    GetPlayerName(playerid, player_name, 24);

	format(fmt_str, sizeof(fmt_str), "SELECT * FROM white_list_pc_version WHERE white_list_nickname = '%s' LIMIT 1", player_name);
	new Result:account_pc_user = sql_queryEx(zConn, fmt_str, QUERY_CACHED);

	if(sql_num_rows(account_pc_user)) 
	{
		sql_get_field_assoc(account_pc_user, "white_list_pass", temp_password_check_android[playerid]);

		show_password_acces_pc_version(playerid);
	}
	else
	{

	    new player_name[24], ip_player[16];
	    GetPlayerName(playerid, player_name, 24);
	    GetPlayerIp(playerid, ip_player, 24);

		SendClientMessage(playerid, -1, "• {FFC800}[Подсказка] {FFFFFF}Авторизуйтесь с мобильного клиента!");
		//NewKick(playerid);		
	}

}

stock acces_user_pc_version(playerid)
{
	SendClientMessage(playerid, -1, "• {FFC800}[Подсказка] {FFFFFF}Вы авторизовались с ПК версии Brilliant Mobile!");
	printf("[CHECK ANDROID]: %d - Player Autorisation PC-Version", playerid);

	type_player_systems[playerid] = PLAYER_IN_PC_VERSION;

	SetTimerEx("OnPlayerJoin", 700, false, "i", playerid);
	SetTimerEx("OnPlayerJoin2", 200, false, "i", playerid);
	SetPlayerWeather(playerid , 1);

	return true;
}

stock show_password_acces_pc_version(playerid)
{
    new player_name[24];
    GetPlayerName(playerid, player_name, 24);

	format(String256, sizeof(String256), "\
	"cWH"Добро пожаловать, "cBLUE"%s"cWH"\n\n\
	"cWH"Для доступа с ПК-версии введите Ваш код-доступа:", player_name);
	SPD(playerid, DIALOG_AUTORISATION_PC_VERSION, DIALOG_STYLE_INPUT, !""cBLUE"Авторизация ПК-версии", String256, !"Далее", !"Назад");

	return true;
}

stock OnInvalidDataIncoming(playerid, system, value, value1)
{

	return true;
}

stock OnValidDataIncoming(playerid, system , value, value1)
{

	return true;
}