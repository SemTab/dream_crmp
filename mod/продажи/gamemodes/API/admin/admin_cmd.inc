static RankAdmins[][] = 
{
	"Мл. Модератор",
	"Модератор",
	"Мл. Администратор",
	"Администратор",
	"Старший администратор",
	"Куратор сервера / Помощник куратора",
	"Гл. Админ / Зам Гл. Админа",
	"Разработчик / Основатель"
};

stock admin_unlogin(playerid)
{ 
	if(!pData[playerid][pAdmin]) 
		return true;

	new 
		stats[60],
		temp_string[200];

	format(stats, 60, "%d,%d,%d,%d,%d,%d,%d,%d", GetPVarIntNew(playerid, "a_ans"), GetPVarIntNew(playerid, "a_kick"), GetPVarIntNew(playerid, "a_ban"), GetPVarIntNew(playerid, "a_msg"), GetPVarIntNew(playerid, "a_warn"), GetPVarIntNew(playerid, "a_veh"), GetPVarIntNew(playerid, "a_mute"), GetPVarIntNew(playerid, "a_jail"));

	format(temp_string, 200, "UPDATE admins SET playerid = '-1', admin_stats = '%s', panel_spectate_status = '%d' WHERE userid = '%d'", stats, GetPVarIntNew(playerid, "admin_speec_panel_other"), pData[playerid][pMysqlID]);
	sql_queryEx(zConn, temp_string, QUERY_THREADED);

	Iter_Remove(Admins, playerid);
	return true;
}

stock admin_login(playerid)
{
	static
		temp_string[500];

	format(temp_string, sizeof(temp_string), "SELECT * FROM admins WHERE userid = '%d' AND admin_status = '1' LIMIT 1", pData[playerid][pMysqlID]);
	new Result:adminfind = sql_queryEx(zConn, temp_string, QUERY_CACHED);

	if(sql_num_rows(adminfind)) 
	{
		new 
			temp_string[144],
			a_ans, a_kick, a_ban, a_msg, a_warn, a_veh, a_mute, a_jail;

		pData[playerid][pAdmin] = sql_get_field_assoc_int_ex(adminfind, 0, "level_admin");
		sql_get_field_assoc_ex(adminfind, 0, "admin_stats", String512, 8 * 5);
		sscanf(temp_string, "p<,>dddddddd", a_ans, a_kick, a_ban, a_msg, a_warn, a_veh, a_mute, a_jail);

		new 
			admin_panel_status = sql_get_field_assoc_int_ex(adminfind, 0, "panel_spectate_status");

		SetPVarIntNew(playerid, "admin_speec_panel_other", admin_panel_status);

	   	SetPVarIntNew(playerid, "a_ans", a_ans);
	   	SetPVarIntNew(playerid, "a_kick", a_kick);
		SetPVarIntNew(playerid, "a_ban", a_ban);
		SetPVarIntNew(playerid, "a_msg", a_msg);
		SetPVarIntNew(playerid, "a_warn", a_warn);
	   	SetPVarIntNew(playerid, "a_veh", a_veh);
		SetPVarIntNew(playerid, "a_mute", a_mute);
		SetPVarIntNew(playerid, "a_jail", a_jail);

		if(!Iter_Contains(Admins, playerid)) Iter_Add(Admins, playerid);


	    admloged[playerid] = 1;
	    new send[128],pip[16];
		GetPlayerIp(playerid,pip,16);

		if(pData[playerid][pAdmin] == 7 || pData[playerid][pAdmin] == 8)
		if(pData[playerid][pAdmin] >= 1 && pData[playerid][pAdmin] <= 6)
		
		if(GetAdmin(playerid) <= 8)
		{	
			new  
				string[128];
		
			format(string, sizeof(string), "Вы вошли как %s %d уровня.", RankAdmins[pData[playerid][pAdmin]], pData[playerid][pAdmin]);
			SCM(playerid, CYELLOW, string);
			
		}


	    if(pData[playerid][pAdmin] < 7) 
	    {
            if(pData[playerid][pSex] == 2) 
            {
				format(send,sizeof(send),"%s авторизовалась %s [IP:%s]",pData[playerid][pNickname], (type_player_systems[playerid] == PLAYER_IN_MOBILE_VERSION) ? ("с Android") : ("с PC"), pip);
			}
			else
			{
				if(strlen(pData[playerid][pMob]) < 5)
				{
 					format(send,sizeof(send),"%s авторизовался %s [IP:%s] ",pData[playerid][pNickname], (type_player_systems[playerid] == PLAYER_IN_MOBILE_VERSION) ? ("с Android") : ("с PC"), pip);
				}
				else 
				{
					format(send,sizeof(send),"%s авторизовался %s [IP:%s]",pData[playerid][pNickname], (type_player_systems[playerid] == PLAYER_IN_MOBILE_VERSION) ? ("с Android") : ("с PC"), pip);
				}
			}
	    	AdminChat(0xc3ef15FF, send, 1);															
		}

	}
	else
	{
		pData[playerid][pAdmin] = 0;
	}
	sql_free_result(adminfind);

	return true;
}

CMD:ap(playerid)
{
    if(pData[playerid][pAdmin] < 1) 
    	return NoCMD(playerid);

	if(GetPVarIntNew(playerid, "admin_speec_panel_other") == 1)
	{
		SetPVarIntNew(playerid, "admin_speec_panel_other", 2);
		SendSucc(playerid, "Вы успешно отключили отображение панели с кнопками в режиме наблюдения!");
	}
	else
	{
		SetPVarIntNew(playerid, "admin_speec_panel_other", 1);
		SendSucc(playerid, "Вы успешно включили отображение панели с кнопками в режиме наблюдения!");		
	}
	return true;
}

CMD:getvw(playerid, params[])
{
    if(pData[playerid][pAdmin] < 2) 
    	return NoCMD(playerid);

	FormattedMessage(playerid, COLOR_ORANGE, "Вирт. мир: "cWH"%d"cORANGE" | Интерьер: "cWH"%d", GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid));
    return true;
}

CMD:setcar(playerid, params[])
{
	if(pData[playerid][pAdmin] < 6)
		return NoCMD(playerid);
		
	new id,
		modelid,
		color1,
		color2;
		
	new Float: pos_x,
		Float: pos_y,
		Float: pos_z,
		Float: pos_a;
				
	new fmtqu[328];
	
	if(sscanf(params, "dddd", id, modelid, color1, color2)) 
	{
		SendInf(playerid, "/setcar [playerid] [modelid] [color1] [color2]");
	
		return true;
	}
	
	if(!IsPlayerConnected(id)) 
		return SendErr(playerid, "Данного игрока нет на сервере!");
	
	if(0 >= color1 >= 128 && 0 >= color2 >= 128)
		return SendErr(playerid, "Цвет авто не может быть меньше 0 и больше 128!");
			
	if(400 >= modelid >= 611)
		return SendErr(playerid, "Модель авто не может быть меньше 400 и больше 611!");
		
	GetPlayerPos(playerid, pos_x, pos_y, pos_z);
	GetPlayerFacingAngle(playerid, pos_a);
	
	format
	(
		fmtqu,
		sizeof(fmtqu),
		"INSERT INTO `player_vehicles`(`owner`,`model`,`color_1`,`color_2`, `parking_x`,`parking_y`,`parking_z`,`parking_a`) VALUES ('%s','%d','%d','%d','%f','%f','%f','%f')",
		GetNameEx(id),
		modelid,
		color1,
		color2,
		pos_x,
		pos_y,
		pos_z,
		pos_a
	);
	
	mysql_query(connect_main, fmtqu);
	
	return true;
}

CMD:givemoney(playerid, params[])
{
	if(pData[playerid][pAdmin] < 7)
		return NoCMD(playerid);
		
	new id,
		value;
		
	if(sscanf(params, "dd", id, value))
	{
		SendInf(playerid, "/givemoney [playerid] [value]");
	
		return true;
	}

	new
		string[54+(-2+MAX_PLAYER_NAME)+(-2+8)+(-2+sizeof(value))],
		str[63+(-2+MAX_PLAYER_NAME)+(-2+8)+(-2+MAX_PLAYER_NAME)+(-2+8)+(-2+sizeof(value))];
		
	GiveMoneyNew(value, id);
	
	format
	(
		string,
		sizeof(string),
		"Вы успешно выдали деньги игроку %s [%d] в размере %d!",
		GetNameEx(id),
		id,
		value
	);
	
	SendInf(playerid, string);
	
	format
	(
		str,
		sizeof(str),
		"Администратор %s [%d] выдал денег игроку %s [%d] в размере %d!",
		GetNameEx(playerid),
		playerid,
		GetNameEx(id),
		id,
		value
	);	
	
	SendAdminMessage(COLOR_LIGHTRED,str,id);
	
	return true;
}

CMD:tpcor(playerid, params[])
{
	if(pData[playerid][pAdmin] < 4)
		return NoCMD(playerid);
		
	new Float: X,
		Float: Y,
		Float: Z;
		
	new teleport[128];
		
	if(sscanf(params, "fff", X, Y, Z))
	{
		SendInf(playerid, "/tpcor X Y Z");
		return true;
	}
		
	SetPlayerPos(playerid, X, Y, Z);
	
	format(teleport, 128, "Вы успешно телепортировались по назначению: %f %f %f", X, Y, Z);
	SendInf(playerid, teleport);
	
	return true;
}

CMD:tp(playerid)
{

    if(pData[playerid][pAdmin] < 3)
    	return NoCMD(playerid);

	return show_gps_admin(playerid);

}

CMD:givezakon(playerid)
{

    if(pData[playerid][pAdmin] >=8)
    {
    	foreach(new players : Player)
        {
			pData[players][pZakon]=100;
    		UpdatePlayerData(players, "zakon", pData[players][pZakon]);
		}
        SCM(playerid,COLOR_LIGHTBLUE,"Вы выдали всем законопослушность");

	}

	return true;

}

CMD:giveurl(playerid, params[]){

    if(pData[playerid][pAdmin] < 8)
    	return NoCMD(playerid);	

	
	if(sscanf(params, "ds[128]", params[0], params[1])) 
		return SendInf(playerid, "/giveurl [ID] [URL]");

	format(String256,sizeof(String256),"%s", params[1]);
	OpenLinkForPlayer(params[0], String256);

	return true;
}

CMD:setfire(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8)
    	return NoCMD(playerid);	

	if(fire_id == -1)
	{
		create_fire_global_params(random(sizeof fire_info));
		SendSucc(playerid, "Пожара не было, поэтому Вы его создали!");
	}
	else
	{
		create_fire_global_params(-1);
		SendSucc(playerid, "Вы убрали существующий пожар!");
	}
	return true;
}


CMD:makeadmin(playerid, params[])
{
    if(pData[playerid][pAdmin] < 5)
    	return NoCMD(playerid);	

	if(sscanf(params, "dd", params[0], params[1])) 
		return SendInf(playerid, "/makeadmin [ID игрока] [LVL]");

	static
		temp_string[500];

    new str[100];
    new para1;
	new level;
	para1 = params[0];
	level = params[1];

	if(pData[para1][pWarnc]) return SendClientMessage(playerid,CGRAY,"У игрока есть варн");
	if(pData[playerid][pAdmin] >= 7)
	{
	    if(IsPlayerConnected(para1))
	    {
	        if(para1 != INVALID_PLAYER_ID)
	        {
	            if(level < 0 || level > 7) 
	            	return SendClientMessage(playerid, COLOR_GREY, "Админка от 0 до 7!");

				pData[para1][pAdmin] = level;

		   		if( pData[para1][pScoreGame][12] < level && level > 1)
		   		{
					format(String256, sizeof( String256 ), "На ваш счет зачислено %d доната",(level -1 )*100 );
					pData[para1][pDonate] += (level-1)*100;
				    UpdatePlayerData(para1,"donate",pData[para1][pDonate]);
			   		pData[ para1 ][ pScoreGame ][12] = level;
					UpdatePlayerData( para1 , "game13", pData[ para1 ][ pScoreGame ][12] );
					if( level == 3 )
					{
			    	    give_money(para1 ,200000, "Администраторский бонус");
			        }
					else if( level == 4 )
					{
			    	    give_money(para1 ,250000, "Администраторский бонус");
			        }
					else if( level == 5 )
					{
			    	    give_money(para1 ,250000, "Администраторский бонус");
			        }
				}
				if(level > 0)
				{
					format(str, sizeof(str), "%s назначил Вас администратором", pData[playerid][pNickname]);
					SendClientMessage(para1, COLOR_YELLOW, str);
					format(str, sizeof(str), "Вы назначили %s администратором %i уровня.", pData[para1][pNickname], level);
					SendClientMessage(playerid, COLOR_YELLOW, str);

					format(temp_string, sizeof(temp_string), "SELECT * FROM admins WHERE username = '%s' LIMIT 1", pData[para1][pNickname]);
					new Result:adminfind = sql_queryEx(zConn, temp_string, QUERY_CACHED);

					if(sql_num_rows(adminfind)) 
					{

						format(temp_string, 200, "UPDATE admins SET level_admin = '%d', promote_name = '%s', admin_status = '1' WHERE username = '%s'", level, pData[playerid][pNickname], pData[para1][pNickname]);
					 	sql_queryEx(zConn, temp_string, QUERY_THREADED);
					}
					else
					{
					    format(temp_string, 256,"\
					    	INSERT INTO admins(username, userid, level_admin, promote_name, admin_status) \
					    	VALUES('%s', '%d', '%d', '%s', '1')", pData[para1][pNickname], pData[para1][pMysqlID], level, pData[playerid][pNickname]);
					   	sql_queryEx(zConn, temp_string, QUERY_THREADED);
					}

				}
				else if(level == 0)
				{
					SFCM(playerid, COLOR_YELLOW, "Вы сняли %s с должности администратора.", pData[para1][pNickname]);
				    SFCM(para1, COLOR_YELLOW, "%s снял вас с должности администратора.", pData[playerid][pNickname]);
					format(String256,sizeof(String256),"UPDATE `accounts` SET atime = 0 WHERE `nickname`='%s'", pData[para1][pNickname]);
				    pData[para1][pTextType] = 0;
					pData[para1][pPhone] = 0;
					sql_queryEx(zConn, String256, QUERY_THREADED);
					new query2[250];
					format(query2,sizeof(query2),"UPDATE `accounts` SET `phone` = '0', WHERE id = '%d'" ,pData[para1][pMysqlID]);
					sql_queryEx(zConn, query2, QUERY_THREADED);

					format(temp_string, 128, "DELETE FROM admins WHERE username = '%s'", pData[para1][pNickname]);
					sql_queryEx(zConn, temp_string, QUERY_THREADED);

					format(temp_string, 128, "DELETE FROM white_list_pc_version WHERE white_list_nickname = '%s'", params[0]);
					sql_queryEx(zConn, temp_string, QUERY_THREADED);

				}
				new query[150];
				format(query,sizeof(query),"UPDATE `accounts` SET `admin` = '%d' WHERE id = '%d'",pData[para1][pAdmin],pData[para1][pMysqlID]);
				sql_queryEx(zConn, query, QUERY_THREADED);

			}
		}
	}



	return true;
}

CMD:toner_car(playerid, params[])
{
    if(pData[playerid][pAdmin] < 6)
    	return NoCMD(playerid);	

	if(sscanf(params, "ddd", params[0], params[1], params[2])) 
		return SendInf(playerid, "/toner_car [ID транспорта] [ID Слот] [ID тонировки]");
	

	switch(params[1])
	{
		case TONER_SLOT_FRONT:
		{	
			SetVehicleToner(params[0], TONER_SLOT_FRONT, params[2]);
		}
		case TONER_SLOT_MIDDLE:
		{
			SetVehicleToner(params[0], TONER_SLOT_MIDDLE, params[2]);
		}
		case TONER_SLOT_REAR:
		{
			SetVehicleToner(params[0], TONER_SLOT_REAR, params[2]);
		}
	}

	return true;    
}

CMD:number_cars(playerid, params[])
{
	if(sscanf(params, "dds[6]s[3]", params[0], params[1], params[2], params[3])) 
	{
		SendInf(playerid, "1 - RU | 2 - UA | 3 - BY | 4 - KZ | 5 - RU POLICE");
		return SendInf(playerid, "/number_car [ID VEH] [ID Number type] [Number] [Region]");
	}

	switch(params[1])
	{
		case 1:
		{
			//format(String144, sizeof(String144), "%s", params[2]);
			//format(String256, sizeof(String256), "%s", params[3]);
			SetVehicleRuNumberPlate(params[0], params[2], params[3]);
		}
		case 2:
		{
			SetVehicleUaNumberPlate(params[0], params[2]);
		}
		case 3:
		{
			SetVehicleBuNumberPlate(params[0], params[2]);
		}
		case 4:
		{
			SetVehicleKzNumberPlate(params[0], params[2], params[3]);
		}
		case 5:
		{
			SetVehicleRuPolNumberPlate(params[0], params[2], params[3]);
		}
	}

	return true;
}

CMD:ncar(playerid, params[])
{
	if(sscanf(params, "dd", params[0], params[1])) 
	{
		SendInf(playerid, "1 - RU | 2 - UA | 3 - BY | 4 - KZ | 5 - RU POLICE |  6 - TAXI");
		return SendInf(playerid, "/ncar [ID VEH] [ID Number type]");
	}

	switch(params[1])
	{
		case 1:
		{ 
			SetVehicleRuNumberPlate(params[0], "x777am", "777");
		}
		case 2:
		{
			SetVehicleUaNumberPlate(params[0], "x777am");
		}
		case 3:
		{
			SetVehicleBuNumberPlate(params[0], "x777am");
		}
		case 4:
		{
			SetVehicleKzNumberPlate(params[0], "x777am", "777");
		}
		case 5:
		{
			SetVehicleRuPolNumberPlate(params[0], "x777am", "777");
		}
		case 6:
		{
			SetVehicleTaxiNumberPlate(params[0], "x777am", "777");
		}
		case 7:
		{
			SetVehicleGosNumberPlate(params[0], "x777am", "777");
		}
		case 8: 
		{
			SetVehicleNoPlateNumberPlate(params[0],  "", "");
		}
	}


	return true;
}

CMD:sound_car(playerid)
{
	new 
		Float:x, Float:y, Float:z;

	new 
		vehicleid = GetPlayerVehicleID(playerid);	

	GetVehiclePos(vehicleid, x, y, z);

	if(vehicle[vehicleid][vehicle_sound_id] != -1)
	{
		DestroyStreamSource(vehicle[vehicleid][vehicle_sound_id]);
	}



	return true;
}

CMD:voice_volume(playerid, params[])
{
	if(sscanf(params, "d", params[0])) 
	{
		return SendInf(playerid, "/voice_volume [От 1 до 200]");
	}

	VoiceChat_SetVolume(playerid, params[0]);

	return true;
}


CMD:light_car(playerid, params[])
{
    if(pData[playerid][pAdmin] < 6)
    	return NoCMD(playerid);	

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/light_car [ID VEH]");

	SetVehicleLightsColors(params[0], 224, 20, 20);

	return true;
}

CMD:handling_car(playerid, params[])
{
    if(pData[playerid][pAdmin] < 6)
    	return NoCMD(playerid);	

    new 
    	Float:grav;

	if(sscanf(params, "ddf", params[0], params[1], grav)) 
		return SendInf(playerid, "/handling_car [ID VEH] [ID HANDLING] [PARAMS]");


	switch(params[1])
	{	

		case 0:
		{
 			SetVehicleMass(params[0], grav);	
		}
		case 1:
		{
 			SetVehicleMassTurn(params[0], grav);	
		}
		case 2:
		{
 			SetVehicleMaxSpeed(params[0], grav);	
		}
		case 3:
		{
 			SetVehicleAcceleration(params[0], grav);	
		}
		case 4:
		{
 			SetVehicleGear(params[0], grav);	
		}
		case 5:
		{
 			SetVehicleBrakeCoef(params[0], grav);	
		}
		case 6:
		{
 			SetVehicleTractionCoef(params[0], grav);	
		}
		case 7:
		{
 			SetVehicleTractionLoss(params[0], grav);	
		}
		case 8:
		{
 			SetVehicleTractionBias(params[0], grav);	
		}
		case 9:
		{
 			SetVehicleSuspensionBias(params[0], grav);	
		}
		case 10:
		{
 			SetVehicleWheelSize(params[0], grav);	
		}
		case 11:
		{
 			SetVehicleSuspensionLower(params[0], grav);	
		}
	}
	return true;
}

CMD:action_exp(playerid)
{
    if(pData[playerid][pAdmin] < 8)
    	return NoCMD(playerid);

	if(IsActionTrue2 == 1)
	{
		IsActionTrue2 = 0;
		SendSucc(playerid, "Вы выключили Х2 EXP!");
	}
	else
	{
		IsActionTrue2 = 1;
		SendSucc(playerid, "Вы включили Х2 EXP!");
	}

	return 1;
}

CMD:gtv(playerid, params[])
{

	new 
		Float:X, Float:Z, Float:Y;

    if(pData[playerid][pAdmin] < 3)
    	return NoCMD(playerid);
	
	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/gtv [ID транспорта]");

	GetVehiclePos(params[0], X, Y, Z);

	SetPlayerPosDebug(playerid, X, Y, Z);

    SetPlayerInterior(playerid, 0);
    SetPlayerVirtualWorld(playerid, GetVehicleVirtualWorld(params[0]));

	format(String256,sizeof(String256),"Администратор %s [%d] телепортировался к автомобилю ID: %d",pData[playerid][pNickname], playerid, params[0]);
	AdminChat(CGRAY,String256);
	logs_admin_other(playerid, pData[playerid][pMysqlID], String256);
	return true;
}

CMD:cc(playerid)
{
    if(pData[playerid][pAdmin] < 5)
    	return NoCMD(playerid);

	for(new i; i < 30; i ++) SendClientMessageToAll(-1, " ");

	format(String256,sizeof(String256),"Администратор %s [%d] очистил чат",pData[playerid][pNickname], playerid);
	AdminChat(CGRAY,String256);

	logs_admin_other(playerid, pData[playerid][pMysqlID], String256);

	return true;
}

CMD:agm(playerid)
{

	if(pData[playerid][pAdmin] < 4)
	{

		if(AdminGM[playerid] == 0)
		{
			AdminGM[playerid] = 1;
			SCM(playerid, COLOR_GRAD3,"ГМ включен");
		}
		else if(AdminGM[playerid] == 0)
		{
			AdminGM[playerid] = 0;
			SCM(playerid, COLOR_GRAD3,"ГМ выключен");
		}		
	}


	return true;
}

CMD:ears(playerid)
{

    if(pData[playerid][pAdmin] < 3)															
    {
		if( pTemp[playerid][pEars] == 0)		
		{
			pTemp[playerid][pEars] = 1;
			SCM(playerid, COLOR_GRAD3," Вы включили прослушку");
		}
		else
		{
			pTemp[playerid][pEars] = 0;
			SCM(playerid, COLOR_GRAD3," Вы выключили прослушку");
		}
	}

	return true;

}


CMD:startmp(playerid, params[])
{

    if(pData[playerid][pAdmin] >= 2)															    
    {

		if(sscanf(params, "d", params[0])) 
			return SendInf(playerid, "/startmp [Кол-во игроков]");

		if(MPPLAYERS > 0) 
			return SCM(playerid,CGRAY,"Сначало остановите предыдущее МП");


		new MPPLAYERSC = params[0];

		if( MPPLAYERSC < 5 || MPPLAYERS > 50) 
			return SCM(playerid,CGRAY,"/startmp [ Кол-во игроков ( 5-50) ]");


		SetPVarIntNew( playerid, "admmp", MPPLAYERSC);

		format( String256, sizeof( String256), "\n\n"cWH"Введите текст мероприятия (макс. 100 сим.):\nИгроки будут телепортированы на место вашей позиции\n(Количество игроков: %d)\n\n\n",MPPLAYERS );
		SPD(playerid,dAdmText,1, ""cBLUE"Мероприятие" , String256 ,"Создать","Отмена");
	}
	return true;
}


CMD:allgun(playerid, params[])
{

	if(pData[playerid][pAdmin] >=8)
	{

		if(sscanf(params, "d", params[0])) 
			return SendInf(playerid, "/allgun [радиус]");


	    if(!params[0]) 
	    	return SCM(playerid,COLOR_WHITE,"Используйте: /allgun [радиус]");
	    new 
	    	Float:pos = floatstr(params[0]),Float:player_x,Float:player_y,Float:player_z;

	    for(new players=0; players < MAX_PLAYERS; players++)
	    {
			if(!IsPlayerConnected(players)) 
				continue;

	        GetPlayerPos(players,player_x,player_y,player_z);
	        if(IsPlayerInRangeOfPoint(playerid,pos,player_x,player_y,player_z))
	        {
	        	GivePlayerWeapon(players, 24, 100);
	        	GivePlayerWeapon(players, 31, 250);
	        	SCM(players, COLOR_YELLOW,"Администратор выдал Вам оружие.");
	        }
	    }
	    SCM(playerid,COLOR_LIGHTBLUE,"Вы выдали оружие игрокам в установленном радиусе.");
	}
	return true;

}


CMD:deletegun(playerid, params[])
{

	if(pData[playerid][pAdmin] >= 4)
	{

		if(sscanf(params, "d", params[0])) 
			return SendInf(playerid, "/deletegun [радиус]");


	    if(!params[0]) 
	    	return SCM(playerid,COLOR_WHITE,"Используйте: /deletegun [радиус]");

        new Float:pos = floatstr(params[0]),Float:player_x,Float:player_y,Float:player_z;
        if( pos > 50) return SCM(playerid,COLOR_WHITE,"Радиус не может быть больше 50");

        foreach(new players : Player)
	    {
			if(!IsPlayerConnected(players)) 
				continue;

	        GetPlayerPos(players,player_x,player_y,player_z);
	        if(IsPlayerInRangeOfPoint(playerid,pos,player_x,player_y,player_z))
	        {
                ResetPlayerWeapons(players);
                SCM(players, COLOR_YELLOW,"Администратор изъял Ваше оружие.");
	        }
	    }
	    SCM(playerid,COLOR_LIGHTBLUE,"Вы изъяли оружие у игроков в установленном радиусе.");
	}
	return true;

}

CMD:agl(playerid, params[])
{
    if(pData[playerid][pAdmin] < 7) 
    	return true;

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/agl [playerid]");    


    new actplayerid = params[0];
    pData[actplayerid][pLicenses] = {1,1,1,1};
    SCM(playerid, COLOR_RED, "Вы выдали игроку все лицензии.");
    new query[135];
	format(query,sizeof(query),"UPDATE `accounts` SET `licDrive` = '1',`licFly` = '1',`licBoat` = '1',`licWeap` = '1' WHERE `id` = '%d'",pData[actplayerid][pMysqlID]);
	sql_queryEx(zConn, query, QUERY_THREADED);
	SCM(actplayerid, COLOR_RED, "Вы получили все лицензии от администратора.");


	format(String256,sizeof(String256),"Администратор %s [%d] выдал все лицензии %s [%d]",pData[playerid][pNickname], playerid, pData[params[0]][pNickname], params[0]);
	AdminChat(CGRAY,String256);

	logs_admin(playerid, pData[playerid][pMysqlID], String256);

	return true;
}

alias:veh("мур");
CMD:veh(playerid, params[])
{
    if(pData[playerid][pAdmin] < 3)
    	return NoCMD(playerid);


	if(sscanf(params, "dI(0)I(0)", params[0], params[1], params[2])) 
		return SendInf(playerid, "/veh [id авто] [цвет 1] [цвет 2]");  

	if(params[0] > 611 || params[0] < 400)
		return SendErr(playerid, "Модель транспорта от 400 до 611!");

	

	new c1,c2,vehmod;
	vehmod = params[0];

	if(params[1] == 0 && params[2] == 0)
	{
		c1 = random(256);
		c2 = random(256);
	}
	else
	{
		if(params[1] > 256 || params[1] < 0 || params[2] > 256 || params[2] < 0) 
			return SendErr(playerid, "ID цвета транспорта может быть от 0 до 256!");

		c1 = params[1];
		c2 = params[2];
	}

	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid,x,y,z);
	x += 1.5;

	new vehid = CreateVehicle(vehmod, x,y,z,0.0, c1, c2, 500000);

	LinkVehicleToInterior(vehid,GetPlayerInterior(playerid));
	SetVehicleVirtualWorld(vehid, GetPlayerVirtualWorld(playerid));
 	
 	SetVehicleRuNumberPlate(vehid,  "-----", "--");

	SFCM(playerid,-1,"• {00CC00}[Успешно] "cWH"Вы создали транспорт с уникальным ID -  %d (Модель - %d)", vehid, vehmod);

	format(String256,sizeof(String256),"Администратор %s [%d] заспавнил транспорт с уникальным ID -  %d (Модель - %d)",pData[playerid][pNickname], playerid, vehid, vehmod);
	logs_admin_other(playerid, pData[playerid][pMysqlID], String256);

	vehicle[vehid][consumables_oil] = 1000.0;

	vehicle[vehid][cFuel] = transport_config[GetVehicleModel(vehid)-400][transport_tank];
	vehicle[vehid][cEnergy] = transport_config[GetVehicleModel(vehid)-400][transport_tank];
	vehicle[vehid][cBatteryEnergy] = 100.0;


	vehicle[vehid][cHealth] = 1000.0;
	vehicle[vehid][cIsCreated] = true;
	SetPVarIntNew(playerid, "a_veh", 1);
	
	
	return true;
}

CMD:admins(playerid)
{
	if(pData[playerid][pAdmin] < 1) return true;
	new aadmins;

	foreach(new i: logged_players)
	{
		if(!pData[i][pAdmin]) continue;
		aadmins ++;
	}
	format( String256, sizeof( String256), "Администраторы онлайн: (%d)", aadmins);
	SCM(playerid,COLOR_GREEN, String256);

	foreach(new i: logged_players)
	{
		if(!pData[i][pAdmin]) continue;
		new mes[64]; format(mes,sizeof(mes),""cWH"%s[%d] (%d) [%s]",pData[i][pNickname],i,pData[i][pAdmin], (type_player_systems[playerid] == PLAYER_IN_MOBILE_VERSION) ? ("С Android") : ("С PC"));
		if(pTemp[i][pAFK]) format(mes,sizeof(mes), "%s {ffa800}[AFK: %s]", mes,Converts(pTemp[i][pAFK]));
		SCM(playerid,COLOR_YELLOW,mes);
	}

	new mind = pTemp[playerid][pAdminExp];
	format(String256,sizeof(String256), "Время администрирования за сегодня: %d минут",mind);
	SCM(playerid,COLOR_YELLOW,String256);

 	return true;
}

CMD:delad(playerid)
{
	if(pData[playerid][pAdmin] < 4) 
		return true;

	for(new i;i<MAX_ADVERT_COUNT;i++)	 	 
	{
		gAdvert[i][adCheking] = false;
		gAdvert[i][adCheked] = false;
		strdel(gAdvert[i][adSender],0,23);
		gAdvert[i][adPhone] = 0;
		strdel(gAdvert[i][adText],0,99);
		strdel(gAdvert[i][adCheker],0,23);
		strdel(gAdvert[i][adRang],0,23);
		gAdvert[i][adBusy] = false;
		gAdvert[i][adTime] = 0;
		gAdvert[i][adSenderID] = 0;
		gAdvert[i][adCheckerID] = 0;
		gAdvert[i][adMoney] = 0;
	}
	gAdvertCount = 0;
	gAdvertTime = 0;
	SCM(playerid, 0xC99700ff, "Объявления удалены");
	return true;
}


CMD:setweather(playerid)
{
	if(pData[playerid][pAdmin] < 6) return true;
	format(String1024,sizeof(String1024),"1) Разные версии синих небес/облаков \
	\n2) Разные версии синих небес/облаков  \
	\n3) Разные версии синих небес/облаков \
	\n4) Разные версии синих небес/облаков \
	\n5) Разные версии синих небес/облаков \
	\n6) Разные версии синих небес/облаков \
	\n7) Разные версии синих небес/облаков \
	\n8) Гроза \
	\n9) Пасмурно и туман \
	\n10) Ясное синее небо ");
	format(String1024,sizeof(String1024),"%s\n11) Обжигающая жаркая \
	\n12) Очень тусклый, бесцветный, смутные \
	\n13) Очень тусклый, бесцветный, смутные \
	\n14) Очень тусклый, бесцветный, смутные \
	\n15) Очень тусклый, бесцветный, смутные \
	\n16) Тусклый, неясный, дождливые \
	\n17) Опаливая горячие \
	\n18) Опаливая горячие \
	\n19) Песчаная буря",String1024);
	format(String1024,sizeof(String1024),"%s\n20) Туманный/зеленоватые \
	\n21) Очень темное, gradiented очертание, пурпурные \
	\n22) Очень темное, gradiented очертание, зеленые \
		\n23) Изменения бледного апельсина \
	\n26) Изменения бледного апельсина \
	\n27) Изменения свежий синие \
	\n29) Изменения свежий синие \
	\n30) Изменения темного, неясного, чирка",String1024);
	format(String1024,sizeof(String1024),"%s\n32) Изменения темного, неясного, чирка \
	\n33) Темный, неясный, коричневый \
	\n34) Синий/пурпурный, регулярный \
	\n35) Тусклые коричневые \
	\n36) Яркий, туманный, апельсин \
	\n38) Яркий, туманный, апельсин \
	\n39) Чрезвычайно яркие",String1024);
	format(String1024,sizeof(String1024),"%s\n40) Ярезвычайно яркие \
	\n42) Синий/пурпурные неясные \
	\n43) Темные токсичные облака \
	\n44) Черное/белое небо \
	\n45) Черное/пурпурное небо \
	\n81) Небо темнеет независимо от времени суток \
	\n91) Небо становится черным как ночью \
	\n200) Приближается шторм",String1024);
	return SPD(playerid, dWeather, 2,"Погода",String1024,"Принять","Отмена");
}


CMD:debugtimer(playerid)
{
	if(!pData[playerid][pAdmin]) return true;
	new test[256]; format(test, 256, "PT2=%d | MT=%d | MT2=%d | OPU=%d | MinT=%d | SU=%d | SF=%d | SQL=%d | SFPS = %d",
		PlayerTimer_time,
		MainTimer_time,
		MainTimer2_time,
		OnPlayerUpdate_time,
		Minute_timer,
		SQLS,
		GetServerTickRate());
	SCM(playerid, COLOR_RED, test);


	return true;
}

stock AdminHelpRank(playerid, rank)
{
	switch(rank)
	{
		case 1:
		{
			if(pData[playerid][pAdmin] < 1)
				return true;
			
			ShowPlayerDialog
			(
				playerid,
				0, 
				DIALOG_STYLE_MSGBOX,
				"Помощь по командам | I Rank",
				"{FFFFFF}/sp - слежка за игроком /weap что-то связанное с орудием /a - чат /stats - статистика \n"\
				"/ans - ответить на жалобу /admins - список администраторов /jail - тюрьма /unjail - выпустить из тюрьмы"\
                "/slap - поднять в воздух игрока /askin - скин администратора",
				"Принял",
				"Назад"
			);		
		}
		case 2:
		{
			if(pData[playerid][pAdmin] < 2)
				return true;
					
			ShowPlayerDialog
			(
				playerid,
				0, 
				DIALOG_STYLE_MSGBOX,
				"Помощь по командам | II Rank",
				"{FFFFFF}/respawn - респавн /setfuel - установить значение бензина /skick - тихий кик\n"\
				"/offstats - оффлайн статистика /tp - телепорт"\
				"/ban - бан, /startmp/stopmp - мероприятие, /agun - выдать оружие",
				"Принял",
				"Назад"
			);		
		}
		case 3:
		{
			if(pData[playerid][pAdmin] < 3)
				return true;
				
			new str[512];
			format(str, sizeof str, "{FFFFFF}/warn - варн /unwarn - снять варн /offwarn - убрать варн /get - получить некие данные\n /templeader - временное лидерство /gethere - телепортировать к себе игрока /veh - создать транспорт\n /msg - сообщение на весь сервер /delv - убрать транспорт /setleader - установить лидерство /unban - убрать бан\n /gtv - телепорт к авто по id /down - опустить что то /goto - телепорт у игроку /gethere - телепортировать к себе игрока\n/respv - респавн авто /getcar  - данные об авто /ears - что то /ban - забанить игрока /unban - разбанить игрока\n/sban - тихий бан /lip - что то /offban - офлайн бан /offget - офлайн данные /num - что то /unoffban");
			
			ShowPlayerDialog
			(
				playerid,
				0, 
				DIALOG_STYLE_MSGBOX,
				"Помощь по командам | III Rank",
				str,
				"Принял",
				"Назад"
			);		
		}
		case 4:
		{
			if(pData[playerid][pAdmin] < 4)
				return true;
			
			ShowPlayerDialog
			(
				playerid,
				0, 
				DIALOG_STYLE_MSGBOX,
				"Помощь по командам | IV Rank",
				"{FFFFFF}/hp - значение HP /rhp - убрать HP /skin - установить скин \n"\
				"/gun - выдать оружие /deletegun - удалить оружие /delad - удалить что то \n"\
				"/okay , nookay - смена Ника /iokay - смена ника /rskin - убрать скин ",
				"Принял",
				"Назад"
			);		
		}
		case 5:
		{
			if(pData[playerid][pAdmin] < 5)
				return true;
			
			ShowPlayerDialog
			(
				playerid,
				0, 
				DIALOG_STYLE_MSGBOX,
				"Помощь по командам | V Rank",
				"{FFFFFF}/cc - очистка чата /makeadmin - выдать администратора игроку /tpcar - ТП по кординатам",
				"Принял",
				"Назад"
			);		
		}
		case 6:
		{
			if(pData[playerid][pAdmin] < 6)
				return true;
			
			ShowPlayerDialog
			(
				playerid,
				0, 
				DIALOG_STYLE_MSGBOX,
				"Помощь по командам | VI Rank",
				"{FFFFFF}/setweather - изменить погоду",
				"Принял",
				"Назад"
			);		
		}
		case 7:
		{
			if(pData[playerid][pAdmin] < 7)
				return true;
			
			ShowPlayerDialog
			(
				playerid,
				0, 
				DIALOG_STYLE_MSGBOX,
				"Помощь по командам | VII Rank",
				"{FFFFFF}/givemoney /agl /apanel",
				"Принял",
				"Назад"
			);		
		}
		case 8:
		{
			if(pData[playerid][pAdmin] < 8)
				return true;
			
			ShowPlayerDialog
			(
				playerid,
				0, 
				DIALOG_STYLE_MSGBOX,
				"Помощь по командам | DEVELOPER Rank",
				"{FFFFFF}Все команды, которые имеются у предыдущих привилегий.",
				"Принял",
				"Назад"
			);		
		}
	}
	return true;
}

CMD:ahelp(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1) 
		return true;
	
	new 
		arank;
		
	if(sscanf(params, "d", arank))
	{
		SendInf(playerid, "/ahelp [arank]");
	
		return true;
	}

	AdminHelpRank(playerid, arank);

	return true;
}

CMD:netstats(playerid, params)
{
	if(pData[playerid][pAdmin] < 8) 
		return false;
	
    new 
		stats[420];

    GetNetworkStats(stats, sizeof(stats));
	
    return SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !"Статистика сети сервера", stats, !"Закрыть", !"");
}

alias:setpos("stp", "ыуезщы", "ыез");
alias:goto("tpto", "пщещ", "езещ");
CMD:goto(playerid, params[])
{
	if(pData[playerid][pAdmin] < 3) 
		return NoCMD(playerid);

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/goto [ID игрока], чтобы телепортироваться к игроку");

	if(params[0] == playerid) 
		return SendErr(playerid, "Телепортироваться к себе не получится");

	if(GetPlayerState(params[0]) == PLAYER_STATE_SPECTATING)
		return FormattedMessage(playerid, -1, "• {AC0000}[Ошибка] "cWH"Администратор %s в режиме наблюдения", pData[params[0]][pNickname]);

	if(!IsPlayerConnected(params[0]))
		return SendErr(playerid,"Неверный ID игрока");

	new 
		Float:x, Float:y, Float:z;

	GetPlayerPos(params[0], x, y, z);

	if(IsPlayerInAnyVehicle(playerid))
	{
		SetVehiclePos(GetPlayerVehicleID(playerid), x, y+2, z);
		LinkVehicleToInterior(GetPlayerVehicleID(playerid), GetPlayerInterior(params[0]));
		SetVehicleVirtualWorld(GetPlayerVehicleID(playerid), GetPlayerVirtualWorld(params[0]));
	}
	else
	{
		SetPlayerPosDebug(playerid, x, y+2, z);
		SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld(params[0]));
		SetPlayerInterior(playerid, GetPlayerInterior(params[0]));
	}


	format(String256,sizeof(String256),"Администратор %s [%d] телепортировался к %s [%d]",pData[playerid][pNickname], playerid, pData[params[0]][pNickname], params[0]);
	AdminChat(CGRAY,String256);

	logs_admin_other(playerid, pData[playerid][pMysqlID], String256);

	return true;
}


alias:gethere("gth", "пуеруку", "пер");
CMD:gethere(playerid, params[])
{
	if(pData[playerid][pAdmin] < 3) 
		return NoCMD(playerid);

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/gethere [ID игрока], чтобы телепортировать игрока к себе");


	if(playerid == params[0]) 
		return SendErr(playerid, "Телепортироваться к себе не получится");

	if(GetPlayerState(params[0]) == PLAYER_STATE_SPECTATING)
		return FormattedMessage(playerid, -1, "• {AC0000}[Ошибка] "cWH"Администратор %s в режиме наблюдения", pData[params[0]][pNickname]);

	if(pData[params[0]][pJail] && pData[params[0]][pPrison]) 
		return SendErr(playerid, "Игрок в ДеМоргане");

	if(!IsPlayerConnected(params[0]))
		return SendErr(playerid,"Неверный ID игрока");


	new 
		Float:x, Float:y, Float:z;

	GetPlayerPos(playerid, x, y, z);

	if(IsPlayerInAnyVehicle(params[0]))
	{
		SetVehiclePos(GetPlayerVehicleID(params[0]), x, y+2, z);
		LinkVehicleToInterior(GetPlayerVehicleID(params[0]), GetPlayerInterior(playerid));
		SetVehicleVirtualWorld(GetPlayerVehicleID(params[0]), GetPlayerVirtualWorld(playerid));
	}

	SetPlayerPosDebug(params[0], x, y+2, z);
	SetPlayerVirtualWorld(params[0], GetPlayerVirtualWorld(playerid));
	SetPlayerInterior(params[0], GetPlayerInterior(playerid));

	FormattedMessage(params[0], -1, "• {FFC800}[Подсказка] "cWH"Администратор %s телепортировал Вас к себе", pData[playerid][pNickname]);
	FormattedMessage(playerid, -1, "• {00CC00}[Успешно] "cWH"Вы телепортировали к себе %s [%d]", pData[params[0]][pNickname], params[0]);



	format(String256,sizeof(String256),"Администратор %s [%d] телепортировал %s [%d] к себе",pData[playerid][pNickname], playerid, pData[params[0]][pNickname], params[0]);
	AdminChat(CGRAY,String256);

	logs_admin_other(playerid, pData[playerid][pMysqlID], String256);

	return true;
}


CMD:offjail(playerid, params[])
{
	if(pData[playerid][pAdmin] < 4) 
		return NoCMD(playerid);

	new 
		nick[32],
		reason[128];

	if(sscanf(params, "s[32]ds[32]", nick, params[1], reason)) 
		return SendInf(playerid, "/offjail [Ник игрока] [минуты] [Причина]");

	new time = params[1];

	if(time < 1 || time > 9999)
	{
		new mes[128];
	    format(mes, sizeof( mes), "/offjail [Ник игрока] [минуты] [Причина]");
		return SendInf(playerid, mes);
	}

	sql_escape_string(zConn, nick, nick, 24);

    if(GetPlayerID(nick) != -1) 
    	return SendErr(playerid, "Игрок с данным именем находится на сервере. Выдать наказание не удалось");

	new query[256];

	format(query,sizeof(query),"SELECT `id` FROM `accounts` WHERE `nickname` = '%s' AND `jail` = '0'",nick);
	new Result:zID = sql_queryEx(zConn, query, QUERY_CACHED);

  	if(!sql_num_rows(zID)) 
  	{
		SendErr(playerid, "Данный игрок не найден в базе данных/уже находится в тюрьме");
		sql_free_result(zID);
		return 1;
	}
	new SIDS = sql_get_field_int(zID, 0);
	sql_free_result(zID);
	new prisos= random(3);

	format(query,sizeof(query),"UPDATE `accounts` SET `jail` = '%d', `prison` = '%d', `wanted` = '0' WHERE `nickname` = '%s'",time*60, prisos, nick);
	sql_queryEx(zConn, query, QUERY_THREADED);

	format(String256,sizeof(String256),"Администратор %s посадил %s в тюрьму в оффлайне на %d минут. Причина: %s",pData[playerid][pNickname],nick,time,reason);
	AdminChat( COLOR_LIGHTRED ,String256);
	logs_admin(playerid, pData[playerid][pMysqlID], String256);

	sql_escape_string(zConn, reason, reason, 50);
	format(String256, sizeof(String256), "INSERT INTO offpunish VALUES ('%d', '%d', '%s', '%s', '%d', '%d')", SIDS, 3, reason, pData[playerid][pNickname],time,pData[playerid][pMysqlID]);
	sql_queryEx(zConn, String256);

	new y,m,d,h,mi,s;
	getdate(y,m,d);
	gettime(h,mi,s);
	format(String256,sizeof(String256),"INSERT INTO `unbanlog` VALUES('','%s','%s','%d-%d-%d %d:%d:%d','%d')",pData[playerid][pNickname],  nick ,y,m,d,h,mi,s,190);
	sql_queryEx(zConn, String256,QUERY_THREADED);

	pData[ playerid ][pScoreGame][11] += 3;
	UpdatePlayerData( playerid , "game12", pData[ playerid ][ pScoreGame ][11]);

	return 1;
}

CMD:unoffjail(playerid, params[])
{
	if(pData[playerid][pAdmin] < 4) 
		return NoCMD(playerid);

	new 
		nick[32];

	if(sscanf(params, "s[32]", nick)) 
		return SendInf(playerid, "/unoffjail [Ник игрока]");

	sql_escape_string(zConn, nick, nick, 24);

    if(GetPlayerID(nick) != -1) 
    	return SendErr(playerid, "Игрок с данным именем находится на сервере. Снять наказание не удалось");

	new query[256];

	format(query,sizeof(query),"SELECT `id` FROM `accounts` WHERE `nickname` = '%s' AND `jail` > '0'",nick);
	new Result:zID = sql_queryEx(zConn, query, QUERY_CACHED);

  	if(!sql_num_rows(zID)) 
  	{
	  SendErr(playerid, "Данный игрок не найден в базе данных/не находится в тюрьме");
	  sql_free_result(zID);
	  return 1;
	}

	sql_free_result(zID);

	format(query,sizeof(query),"UPDATE `accounts` SET `jail` = '0', `prison` = '0' WHERE `nickname` = '%s'", nick);
	sql_queryEx(zConn, query, QUERY_THREADED);

	format(String256,sizeof(String256),"Администратор %s освободил %s из тюрьмы в оффлайне",pData[playerid][pNickname],nick);
	AdminChat( COLOR_LIGHTRED ,String256);
	logs_admin(playerid, pData[playerid][pMysqlID], String256);

	new y,m,d,h,mi,s;
	getdate(y,m,d);
	gettime(h,mi,s);
	format(String256,sizeof(String256),"INSERT INTO `unbanlog` VALUES('','%s','%s','%d-%d-%d %d:%d:%d','%d')",pData[playerid][pNickname], nick ,y,m,d,h,mi,s,191);
	sql_queryEx(zConn, String256,QUERY_THREADED);

	return 1;
}

CMD:apanel(playerid)
{
	if(pData[playerid][pAdmin] < 7)
		return NoCMD(playerid);

	ShowPlayerDialog
	(
		playerid,
		3999,
		DIALOG_STYLE_LIST,
		"Панель основателя",
		"{FF99AA}[1] {FFFFFF}Отключить сервер\n"\
		"{FF99AA}[2] {FFFFFF}Перезагрузить сервер\n"\
		"{FF99AA}[3] {FFFFFF}Включить X2 Сервер\n"\
		"{FF99AA}[4] {FFFFFF}Выключить X2 Сервер\n"\
		"{FF99AA}[5] {FFFFFF}Закрыть сервер на технические работы\n"\
		"{FF99AA}[6] {FFFFFF}Заспавнить автомобили",
		"Далее",
		"Назад"
	);

	return true;
}

CMD:giveskill(playerid, params[])
{
	if(pData[playerid][pAdmin] < 8) 
		return NoCMD(playerid);

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/giveskills [ID]");

    new actplayerid = params[0];
	SendClientMessage(playerid, COLOR_RED, "Вы выдали игроку все скиллы на 100");
    pTemp[actplayerid][pGunSkill][0] = 100,
	pTemp[actplayerid][pGunSkill][1] = 100,
	pTemp[actplayerid][pGunSkill][2] = 100,
	pTemp[actplayerid][pGunSkill][3] = 100,
	pTemp[actplayerid][pGunSkill][4] = 100,
	pTemp[actplayerid][pGunSkill][5] = 100;
	format(String255,sizeof(String255),"UPDATE `accounts` SET `skills`='100,100,100,100,100,100' WHERE `nickname`='%s'", pData[actplayerid][pSkills], pData[actplayerid][pNickname]);
	sql_queryEx(zConn, String255, QUERY_THREADED);
	return true;	
}

CMD:setacc(playerid, params[])
{
	if(pData[playerid][pAdmin] < 8) 
		return NoCMD(playerid);

	if(sscanf(params, "ddd", params[0], params[1], params[2])) 
	{
		SendClientMessage(playerid, CGRAY, "/setacc [ID игрока] [Номер данных] [Значение]");
		SendClientMessage(playerid, COLOR_LIGHTGREEN, "Номера данных: 1)Пол 2)Возраст 3)Работа");
	    SendClientMessage(playerid, COLOR_LIGHTGREEN, "4)Скин 5)Деньги 6)Банк 7)Уровень 8)Exp 9)Номер телефона");
	    SendClientMessage(playerid, COLOR_LIGHTGREEN, "10)Наркотики 11)Лицензия вождение 12)Лицензия полёты");
	    SendClientMessage(playerid, COLOR_LIGHTGREEN, "13)Лицензия лодки 14)Лицензия оружие 15)Донат");
	    SendClientMessage(playerid, COLOR_LIGHTGREEN, "16)Патроны 17)Ед.оружия 18)фракц. скин 19)цвет кожи 20)законопослушность");
		return 1;
	}


	new i = params[0];
	if(!IsPlayerConnected(i)) 
		return SendClientMessage(playerid, CGRAY, "Указанный игрок не найден.");

	new value = params[2];
	new zStr[100];

	switch(params[1])
	{
	    case 1:
		{
		    if(value < 1 || value > 2) return SendClientMessage(playerid, CGRAY, "Пол | 1)Мужской 2)Женский");
			pData[i][pSex] = value;
		    UpdatePlayerData(i,"sex",pData[i][pSex]);
		    format(zStr, 100, "Вы успешно изменили пол %s", pData[i][pNickname]);
		    SendClientMessage(playerid, COLOR_LIGHTRED, zStr);
		}
		case 2:
		{
		    if(value < 4 || value > 110) return SendErr(playerid,"Возраст не может быть менее 4 и более 110");
            pData[i][pAge] = value;
		    UpdatePlayerData(i,"age",pData[i][pAge]);
		    format(zStr, 100, "Вы успешно изменили возраст %s", pData[i][pNickname]);
		    SendClientMessage(playerid, COLOR_LIGHTRED, zStr);
		}
		case 3:
		{
		    if(value < 1 || value > 6) return SendErr(playerid,"Работа | 1)Автобусник 2)Дальнобой 3)Таксист 4)Механик 5)Развозчик товаров 6)Развозчик топлива");
		    pData[i][pJob] = value;
		    UpdatePlayerData(i,"job",pData[i][pJob]);
		    format(zStr, 100, "Вы успешно изменили место работы %s", pData[i][pNickname]);
		    SendClientMessage(playerid, COLOR_LIGHTRED, zStr);
		}
		case 4:
		{
		    if(value < 1 || value > 312) return SendErr(playerid,"ID скина от 1 до 312");
			pData[i][pSkin] = value;
		    UpdatePlayerData(i,"skin",pData[i][pSkin]);
		    format(zStr, 100, "Вы успешно изменили скин игроку %s", pData[i][pNickname]);
		    if(!pData[i][pFraction]) SetPlayerSkin(i, value);
		    SendClientMessage(playerid, COLOR_LIGHTRED, zStr);
		}
		case 5:
		{
		    format(zStr, 100, "Вы успешно изменили количество денег %s", pData[i][pNickname]);
		    SendClientMessage(playerid, COLOR_LIGHTRED, zStr);

			give_money(i ,value, "Выдано администратором");

		}
		case 6:
		{
		    pData[i][pBank] = value;
		    UpdatePlayerData(i,"bank",pData[i][pBank]);
		    format(zStr, 100, "Вы успешно изменили количество денег в банке %s", pData[i][pNickname]);
		    SendClientMessage(playerid, COLOR_LIGHTRED, zStr);

		}
		case 7:
		{
		    pData[i][pLevel] = value; SetPlayerScore(i, value);
		    UpdatePlayerData(i,"level",pData[i][pLevel]);
   			format(zStr, 100, "Вы успешно изменили количество уровень игрока %s", pData[i][pNickname]);
		    SendClientMessage(playerid, COLOR_LIGHTRED, zStr);
			if( pData[i][pLevel] == 7 ) SendInf(playerid, "ТЫ КРИВОЙ!!!");
		}
		case 8:
		{
		    pData[i][pExp] = value;
		    UpdatePlayerData(i,"exp",pData[i][pExp]);
   			format(zStr, 100, "Вы успешно изменили EXP игрока %s", pData[i][pNickname]);
		    SendClientMessage(playerid, COLOR_LIGHTRED, zStr);

			SetLevelProgresss(i, pData[i][pExp], (pData[i][pLevel] * 6));
		}
		case 9:
		{
		    pData[i][pPhone] = value;
		    UpdatePlayerData(i,"phone",pData[i][pPhone]);
   			format(zStr, 100, "Вы успешно изменили номер телефона %s", pData[i][pNickname]);
		    SendClientMessage(playerid, COLOR_LIGHTRED, zStr);
		}
		case 10:
		{
		    pData[i][pDrugs] = value;
		    UpdatePlayerData(i,"drugs",pData[i][pDrugs]);
   			format(zStr, 100, "Вы успешно изменили количество наркотиков у %s", pData[i][pNickname]);
		    SendClientMessage(playerid, COLOR_LIGHTRED, zStr);
		}
		case 11:
		{
		    if(value) {
				pData[i][pLicenses][LIC_DRIVING] = 1;
				format(zStr, 100, "Вы выдали %s лицензию на вождение", pData[i][pNickname]);
			}
		    else {
		        pData[i][pLicenses][LIC_DRIVING] = 0;
		        format(zStr, 100, "Вы забрали лицензию на вождение у %s", pData[i][pNickname]);
			}
			new query[128];
			format(query,sizeof(query),"UPDATE `accounts` SET `licDrive` = '%d' WHERE `id` = '%d'",pData[i][pLicenses][LIC_DRIVING],pData[i][pMysqlID]);
			sql_queryEx(zConn, query, QUERY_THREADED);
		    SendClientMessage(playerid, COLOR_LIGHTRED, zStr);
		}
		case 12:
		{
		    if(value) {
				pData[i][pLicenses][LIC_FLY] = 1;
				format(zStr, 100, "Вы выдали %s лицензию на полёты", pData[i][pNickname]);
			}
		    else {
		        pData[i][pLicenses][LIC_FLY] = 0;
		        format(zStr, 100, "Вы забрали лицензию на полёты у %s", pData[i][pNickname]);
			}
			new query[128];
			format(query,sizeof(query),"UPDATE `accounts` SET `licFly` = '%d' WHERE `id` = '%d'",pData[i][pLicenses][LIC_FLY],pData[i][pMysqlID]);
			sql_queryEx(zConn, query, QUERY_THREADED);
		    SendClientMessage(playerid, COLOR_LIGHTRED, zStr);
		}
		case 13:
		{
		    if(value) {
				pData[i][pLicenses][LIC_BOAT] = 1;
				format(zStr, 100, "Вы выдали %s лицензию на лодку", pData[i][pNickname]);
			}
		    else {
		        pData[i][pLicenses][LIC_BOAT] = 0;
		        format(zStr, 100, "Вы забрали лицензию на лодку у %s", pData[i][pNickname]);
			}
			new query[128];
			format(query,sizeof(query),"UPDATE `accounts` SET `licBoat` = '%d' WHERE `id` = '%d'",pData[i][pLicenses][LIC_BOAT],pData[i][pMysqlID]);
			sql_queryEx(zConn, query, QUERY_THREADED);
		    SendClientMessage(playerid, COLOR_LIGHTRED, zStr);
		}
		case 14:
		{
		    if(value) {
				pData[i][pLicenses][LIC_WEAP] = 1;
				format(zStr, 100, "Вы выдали %s лицензию на оружие", pData[i][pNickname]);
			}
		    else {
		       	pData[i][pLicenses][LIC_WEAP] = 0;
		        format(zStr, 100, "Вы забрали лицензию на оружие у %s", pData[i][pNickname]);
			}
			new query[128];
			format(query,sizeof(query),"UPDATE `accounts` SET `licWeap` = '%d' WHERE `id` = '%d'",pData[i][pLicenses][LIC_WEAP],pData[i][pMysqlID]);
			sql_queryEx(zConn, query, QUERY_THREADED);
		    SendClientMessage(playerid, COLOR_LIGHTRED, zStr);
		}
		case 15:
		{
            pData[i][pDonate] = value;
		    UpdatePlayerData(i,"donate",pData[i][pDonate]);
   			format(zStr, 100, "Вы успешно изменили количество доната у %s", pData[i][pNickname]);
		    SendClientMessage(playerid, COLOR_LIGHTRED, zStr);
		}
		case 16:
		{
		    pData[i][pAmmo] = value;
		    UpdatePlayerData(i,"ammo",pData[i][pAmmo]);
   			format(zStr, 100, "Вы успешно изменили количество патрон у %s", pData[i][pNickname]);
		    SendClientMessage(playerid, COLOR_LIGHTRED, zStr);
		}
		case 17:
		{
		    pData[i][pGunAmount] = value; 
		    UpdatePlayerData(i,"gunamount",pData[i][pGunAmount]);
   			format(zStr, 100, "Вы успешно изменили количество патрон у %s", pData[i][pNickname]);
		    SendClientMessage(playerid, COLOR_LIGHTRED, zStr);
		}
		case 18:
		{
		    if(value < 1 || value > 299) return SendErr(playerid,"ID скина от 1 до 299");
			if(!pData[i][pFraction]) return SendClientMessage(playerid, CGRAY, "Игрок не в организации");
			pData[i][pFractionSkin] = value;
		    UpdatePlayerData(i,"fractionskin",pData[i][pFractionSkin]);
		    format(zStr, 100, "Вы успешно изменили фракционный скин игроку %s", pData[i][pNickname]);
		    SetPlayerSkin(i, value);
		    SendClientMessage(playerid, COLOR_LIGHTRED, zStr);
		}
		case 19:
		{
            if(value < 1 || value > 2) return SendClientMessage(playerid, CGRAY, "Цвет кожи | 1)Черный 2)Белый");
			if(value == 1) pData[i][pColor] = 1;
			else pData[i][pColor] = 0;
		    UpdatePlayerData(i,"color",pData[i][pColor]);
		    format(zStr, 100, "Вы успешно изменили пол %s", pData[i][pNickname]);
		    SendClientMessage(playerid, COLOR_LIGHTRED, zStr);
		}
		case 20:
		{
            if(value < -100 || value > 100) return SendClientMessage(playerid, CGRAY, "Законопослушность -100 - 100");
			pData[i][pZakon] = value;
		    UpdatePlayerData(i,"zakon",pData[i][pZakon]); // hotelroom
		    format(zStr, 100, "Вы успешно изменили законопослушность %s", pData[i][pNickname]);
		    SendClientMessage(playerid, COLOR_LIGHTRED, zStr);
		}

	    default:
		{
			SendClientMessage(playerid, CGRAY, "/redacc [ID игрока] [Номер данных] [Значение]");
			SendClientMessage(playerid, COLOR_LIGHTGREEN, "Номера данных: 1)Пол 2)Возраст 3)Работа");
		    SendClientMessage(playerid, COLOR_LIGHTGREEN, "4)Скин 5)Деньги 6)Банк 7)Уровень 8)Exp 9)Номер телефона");
		    SendClientMessage(playerid, COLOR_LIGHTGREEN, "10)Наркотики 11)Лицензия вождение 12)Лицензия полёты");
		    SendClientMessage(playerid, COLOR_LIGHTGREEN, "13)Лицензия лодки 14)Лицензия оружие 15)Донат");
		    SendClientMessage(playerid, COLOR_LIGHTGREEN, "16)Патроны 17)Ед.оружия 18)Фрак.скин 19)цвет кожи");
			return 1;
		}
	}
    return true;
}

CMD:mute(playerid, params[])
{
	if(pData[playerid][pAdmin] < 2) 
		return NoCMD(playerid);

	if(sscanf(params, "dds[64]", params[0], params[1], params[2])) 
		return SendInf(playerid, "/mute [ID игрока] [К-во минут] [Причина]");

	new id = params[0];
	if(!IsPlayerConnected(id)) 
		return SendErr(playerid,"Неверный ID");
	if(!pData[id][pMysqlID]) 
		return SendErr(playerid,"Этот игрок не зарегистрирован");
	if( pData[id][pMut] > 0)
	{
		format(String256, sizeof( String256), "Время бана чата игрока: %d мин",pData[id][pMut]);
		SendInf(playerid, String256);
	}

	new time = params[1];
	if(time < 10 || time > 180) 
		return SendErr(playerid,"Введите время от 10 до 180 минут");
	if(pData[id][pMut] > 0) 
		return SendClientMessage(playerid, -1, "Данному игроку уже выдан бан чата!");
	if(pData[id][pAdmin] == 7 && pData[playerid][pAdmin] < 8) 
		return SendClientMessage(playerid, -1, "Данный игрок является старшим администратором!");

	pData[id][pMut] = time;
	UpdatePlayerData(id,"mut",time);

	VoiceChat_MutePlayer(playerid);

	new mes[144];
	format(mes,sizeof(mes),"Администратор %s выдал бан чата игроку %s на %d минут. Причина: %s",pData[playerid][pNickname],pData[id][pNickname],time,params[2]);
	SendAdminMessage(COLOR_LIGHTRED,mes,id);

	logs_admin(playerid, pData[playerid][pMysqlID], mes);

	show_notify_gui(params[0], TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_34", 4000);

	format(mes,sizeof(mes),"Вы получили бан чата от администратора %s на %d минут. Причина: %s",pData[playerid][pNickname],time,params[2]);
	SendClientMessage( id , COLOR_LIGHTRED, mes );
	pData[ playerid ][pScoreGame][11] += 3;
	UpdatePlayerData( playerid , "game12", pData[ playerid ][ pScoreGame ][11] );


	return true;

}


CMD:unjail(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1) 
		return NoCMD(playerid);

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/unjail  [ID игрока]");

	new acter;
	acter = params[0];
	if( acter < 0 || acter > 999)  
		return SCM(playerid, COLOR_WHITE, "Введите: /unjail [id]");

	new 
		string[128];

	if(!IsPlayerConnected(params[0]))
		return SendErr(playerid,"Неверный ID игрока");

	if(pData[acter][pJail] == 0) 
		return SCM(playerid, COLOR_WHITE, "Игрок не в тюрьме");

	pData[acter][pJail] = 1;


	format(string, sizeof(string), "Вы выпустили %s из тюрьмы", pData[acter][pNickname]);
	SCM(playerid, COLOR_LIGHTRED, string);

	SetPlayerSkin(acter,pData[acter][pSkin]);
	
	format(string, sizeof(string), "Администратор %s выпустил Вас из тюрьмы.",pData[playerid][pNickname]);
	SCM(acter, -1, string);

	format(string,sizeof(string),"Администратор %s выпустил игрока %s из тюрьмы",pData[playerid][pNickname],pData[acter][pNickname]);
	AdminChat(CGRAY,string);

	logs_admin(playerid, pData[playerid][pMysqlID], string);

	SetPlayerInterior(acter, 0);
	SetPlayerVirtualWorld(acter, 0);
	SetPlayerPosDebug(acter,1552.9467,-1675.5570,16.1953);

	return 1;
}

CMD:jail(playerid, params[])
{

	
	if(pData[playerid][pAdmin] < 1) 
		return NoCMD(playerid);


	if(sscanf(params, "dds[32]", params[0], params[1], params[2])) 
		return SendInf(playerid, "/jail  [ID игрока] [минуты] [Причина]");

	if(!IsPlayerConnected(params[0]))
		return SendErr(playerid,"Неверный ID игрока");

	new acter, time;
	acter = params[0];

	if( pData[acter][pJail] > 0)
	{
		format(String256, sizeof( String256), "Игрок в тюрьме. Время игрока в тюрьме: %d мин",pData[acter][pJail]/60);
		SendInf(playerid, String256);
		return 1;
	}

	time = params[1];

	if(time == 0) 
		return SendInf(playerid, "/jail  [ID игрока] [минуты] [Причина]");

	if(!strlen(params[2]) || strlen(params[2]) > 50) 
		return SendInf(playerid, "/jail  [ID игрока] [минуты] [Причина]");

	if( acter < 0 || acter > 999)  
		SendInf(playerid, "/jail  [ID игрока] [минуты] [Причина]");


	if(pData[acter][pAdmin] > 6 && pData[playerid][pAdmin] < 7) 
		return SCM(playerid,COLOR_WHITE,"Вы не можете посадить этого игрока");

	for( new d; d < 6; d++) 
	{
		if(pData[acter][pWantedi][d] == 0) 
		{
			pData[acter][pWantedi][d] = 0;
			break;
		}
	}


	format(pData[acter][pWantedinf],80,"%d,%d,%d,%d,%d,%d",
	pData[acter][pWantedi][0],pData[acter][pWantedi][1],pData[acter][pWantedi][2],
	pData[acter][pWantedi][3],pData[acter][pWantedi][4],pData[acter][pWantedi][5]);
	format(String1024,sizeof(String1024),"UPDATE `accounts` SET `wantedi`='%s' WHERE `nickname`='%s'", pData[acter][pWantedinf] , pData[acter][pNickname]);
	sql_queryEx(zConn, String1024, QUERY_THREADED);


	new string[256];
	format(string, sizeof(string), "Вы посадили %s в тюрьму", pData[acter][pNickname]);
	SCM(playerid, COLOR_LIGHTRED, string);
	ResetPlayerWeapons(acter);

	show_notify_gui(acter, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_36", 4000);

	new camid = random(sizeof(CamCoords));
	SetPlayerPosDebug(acter, CamCoords[camid][0],CamCoords[camid][1],CamCoords[camid][2]);
	SetPlayerFacingAngle(acter,359.4348);

	TogglePlayerControllable(playerid,1);
	pData[acter][pJail] = time*60;
	new prisos= random(3);
	pData[acter][pPrison] = prisos;
	SetPlayerVirtualWorld(acter, prisos+1);

	if( pData[acter][pSex] == 2)
	{
		SetPlayerSkin(acter, 243);
	}
	else 
	{
		SetPlayerSkin(acter, 242);
	}

	format(string, sizeof(string), "Администратор %s посадил Вас в тюрьму на %d минут. Причина: %s", pData[playerid][pNickname], time, params[2]);
	SCM(acter, COLOR_LIGHTRED, string);
	SendInf(acter, "Чтобы посмотреть сколько Вам осталось сидеть в тюрьме, введите команду {FFFF10}/ptime");
	format(string,sizeof(string),"Администратор %s посадил игрока %s в тюрьму на %d минут. Причина: %s",pData[playerid][pNickname],pData[acter][pNickname],time,params[2]);
	AdminChat(CGRAY,string);

	logs_admin(playerid, pData[playerid][pMysqlID], string);

	PlayerTimerWanted[acter] = 0;
	if( PlayerTimerWantedEx[acter] != 0) 
	{
		KillTimer(PlayerTimerWantedEx[acter]);
		PlayerTimerWantedEx[acter] = 0;
	}
	PlayerTimerWantedEx[acter] = SetTimerEx("ShowWantedMenuEx", 140, 1, "dd", acter,0);
	format(String256,sizeof(String256),"UPDATE `accounts` SET `jail` = '%d', prison = '%d', wanted = '0' WHERE `id` = '%d'",pData[acter][pJail],pData[acter][pPrison],pData[acter][pMysqlID]);
	sql_queryEx(zConn, String256, QUERY_THREADED);


	pData[ playerid ][pScoreGame][11] += 3;
	UpdatePlayerData( playerid , "game12", pData[ playerid ][ pScoreGame ][11]);


	return 1;
}

CMD:unbanip(playerid, params[])
{
    if(pData[playerid][pAdmin] > 6)
 	{
		if(sscanf(params, "s[24]", params[0])) 
			return SendInf(playerid, "/unbanip  [IP]");

    	format(String256,sizeof(String256),"unbanip %s", params[0]);
    	SendRconCommand(String256);
    	SendRconCommand("reloadbans");

		new mes[128];
		format(mes,sizeof(mes),"Администратор %s разбанил IP %s",pData[playerid][pNickname], params[0]);
		AdminChat( -1 ,mes);

		logs_admin(playerid, pData[playerid][pMysqlID], mes);

		SCM(playerid, 0xFF0000FF, "IP адрес разбанен!");
	}
	return true;
}

CMD:banip(playerid, params[])
{
    if(pData[playerid][pAdmin] >= 6)
 	{
		if(sscanf(params, "s[24]", params[0])) 
			return SendInf(playerid, "/banip [ID игрока]");
		new ip[16];
	    GetPlayerIp(strval(params[0]), ip,16);

    	format(String256,sizeof(String256),"banip %s", ip);
    	SendRconCommand(String256);
    	SendRconCommand("reloadbans");
		new mes[128];

		format(mes,sizeof(mes),"Администратор %s забанил IP %s",pData[playerid][pNickname], params[0]);
		AdminChat( -1 ,mes);

		logs_admin(playerid, pData[playerid][pMysqlID], mes);

		SCM(playerid, CGRAY, "IP адрес забанен!");
	}
	return true;
}

CMD:setleader(playerid, params[])
{
	if(pData[playerid][pAdmin] < 3)
		return NoCMD(playerid);
		
	new id,
		idfrac;
		
	if(sscanf(params, "dd", id, idfrac))
	{
		SendInf(playerid, "/setleader [playerid] [ID fraction]");
		return true;
	}
		
	if(!IsPlayerConnected(id))
		return SendErr(playerid, "Данного игрока нет на сервере, либо его не существует!");
		
	if(idfrac == 1 || idfrac == 3 || idfrac == 4 || idfrac == 5 || idfrac == 6 || idfrac == 7 || idfrac > 15 || idfrac == -1)
		return SendErr(playerid, "Данную фракцию нельзя использовать!");
		
	if(!idfrac)
	{
		SendInf(id, "Вас сняли с поста лидера.");
		
		pData[id][pFraction] = 0;
		pData[id][pRank] = 0;
		
		new query[256];
	    format(query,sizeof(query),"UPDATE `accounts` SET `fraction` = '%d', `rank` = '%d', `subfraction` = '%d' WHERE `id` = '%d'", 0, 0, 0, pData[id][pMysqlID]);
	    sql_queryEx(zConn, query, QUERY_THREADED);
		return true;
	}
	
	if(idfrac > FRACTION_COUNT+1)
	{
	    SCM(playerid,-1,"Ошибка ID фракции!");
		return 1;
	}
	
	new subfrakid = GetSubfractionID(idfrac-1);
	new zS[144];

    if(idfrac == 12) subfrakid = -1;

    new subfrak = 0;

    if(subfrakid == -1 || subfrak == 0) 
    {
		format(zS, sizeof(zS), "Администратор %s [%d] поставил Вас на пост лидера фракции %s [%d]", GetNameEx(playerid), playerid, gFractionName[idfrac-1], idfrac);
		SendSucc(id, zS);
		
		pData[id][pFraction] = idfrac;
		pData[id][pSubfraction] = subfrak;
		pData[id][pRank] = gFractionRankCount[pData[id][pFraction]-1];
		pData[id][pFractionSkin] = gFractionSkin[idfrac-1][6];
		
		pTemp[playerid][spawn_id] = SPAWN_ORG;
		SpawnPlayer(id);
	}
	
	set_player_skin(playerid, pData[id][pFractionSkin]);

    new query[256];
	format(query,sizeof(query),"UPDATE `accounts` SET `fraction` = '%d', `rank` = '%d', `subfraction` = '%d', `fractionskin` = '%d' WHERE `id` = '%d'", idfrac, gFractionRankCount[idfrac-1], subfrak, pData[id][pFractionSkin], pData[id][pMysqlID]);
	sql_queryEx(zConn, query, QUERY_THREADED);
	
	return true;
}

CMD:templeader(playerid, params[])
{
    if(pData[playerid][pAdmin] < 3)
    	return NoCMD(playerid);

	if(sscanf(params, "dd", params[0], params[1])) 
		return SendInf(playerid, "/templeader [ID фракции] [ID подфракции]");

    new frak = params[0];


	if(frak == 1 || frak == 3 || frak == 4 || frak == 5 || frak == 6 || frak == 7 || frak > 15 || frak == -1)
	return SendErr(playerid, "Данная фракция недоступна!");

    if(frak == 0)
	{
	    SCM(playerid,-1,"Вы покинули временную фракцию");
	    pData[playerid][pFraction] = 0;
	    pData[playerid][pRank] = 0;

	    if(pData[playerid][pBikerRank] == 7)
	    {
			pData[playerid][pBikerRank] = 0;
			pData[playerid][pBiker] = 0;
		}
		return 1;
	}
	if(frak > FRACTION_COUNT+1)
	{
	    SCM(playerid,-1,"Ошибка ID фракции");
		return 1;
	}
	new subfrakid = GetSubfractionID(frak-1);
	new zS[144];

    if(frak == 12) subfrakid = -1;

    new subfrak = params[1];

    if(subfrakid == -1 || subfrak == 0) 
    {//|| frak == 12
		format(zS, sizeof(zS), "Вы тихо вступили во фракцию %s (%d)", gFractionName[frak-1], frak);
		SendSucc(playerid, zS);
		pData[playerid][pFraction] = frak;
		pData[playerid][pSubfraction] = 0;
		pData[playerid][pRank] = gFractionRankCount[frak-1];
	}
	else 
	{
	 	if(subfrak < 1 || subfrak > 3) return SendErr(playerid, "Подфракция от 1 до 3");
	    format(zS, sizeof(zS), "Вы тихо вступили во фракцию %s, подфракцию %s", gFractionName[frak-1], gSubfractionName[subfrakid][subfrak-1]);
		SendSucc(playerid, zS);
		pData[playerid][pFraction] = frak;
		pData[playerid][pSubfraction] = subfrak;
		pData[playerid][pRank] = gFractionRankCount[frak-1];
	}
	return 1;
}

CMD:msg(playerid, params[])
{
	new 
		string[128];

    if(pData[playerid][pAdmin] < 3)
    	return NoCMD(playerid);

	if(sscanf(params, "s[100]", params[0])) 
		return SendInf(playerid, "/msg [Текст]");


	format(string, 130, "Администратор %s: %s", pData[playerid][pNickname], params[0]);
	SendClientMessageToAll(0xFFCD00ff, string);

	logs_admin_other(playerid, pData[playerid][pMysqlID], string);

	return true;
}


alias:setvw("stv", "ыуемц", "ыем");
CMD:setvw(playerid, params[])
{
    if(pData[playerid][pAdmin] < 3)
    	return NoCMD(playerid);



	if(sscanf(params, "dd", params[0], params[1])) 
		return SendInf(playerid, "/setvw [ID игрока] [ID мира]");

	if(!IsPlayerConnected(params[0]))
		return SendErr(playerid,"Неверный ID игрока");

	SetPlayerVirtualWorld(params[0], params[1]);

	return true;
}

alias:setint("sti", "ыуеште");
CMD:setint(playerid, params[])
{
    if(pData[playerid][pAdmin] < 3)
    	return NoCMD(playerid);



	if(sscanf(params, "dd", params[0], params[1])) 
		return SendInf(playerid, "/setint [ID игрока] [Интерьер]");

	if(!IsPlayerConnected(params[0]))
		return SendErr(playerid,"Неверный ID игрока");

	SetPlayerInterior(params[0], params[1]);

	return true;
}

CMD:skin(playerid, params[])
{
	if(pData[playerid][pAdmin] < 4) 
		return NoCMD(playerid);

	if(sscanf(params, "dd", params[0], params[1])) 
		return SendInf(playerid, "/skin [id игрока] [скин]");

	if(params[1] < 1 || params[1] > 390) 
		return SendErr(playerid, "Неверный скин");

	if(!IsPlayerConnected(params[0]))
		return SendErr(playerid,"Неверный ID игрока");

	SetPVarIntNew(playerid, "askin", 1);

	SetPlayerSkin(params[0],params[1]);

	SFCM(params[0], -1, "• {00CC00}[Успешно] "cWH"Администратор %s выдал Вам временный скин №%d",pData[playerid][pNickname], params[1]);
	SFCM(playerid, -1, "• {00CC00}[Успешно] "cWH"Вы выдали %s [%d] временный скин №%d",pData[params[0]][pNickname],params[0],params[1]);




	return true;
}

CMD:asetskin(playerid, params[])
{
	if(pData[playerid][pAdmin] < 7) 
		return NoCMD(playerid);

	if(sscanf(params, "dd", params[0], params[1])) 
		return SendInf(playerid, "/asetskin [id игрока] [скин]");

	if(params[1] < 1 || params[1] > 290) 
		return SendErr(playerid, "Неверный скин");

	if(!IsPlayerConnected(params[0]))
		return SendErr(playerid,"Неверный ID игрока");

	pData[params[0]][pSkin] = params[1];

	UpdatePlayerData(params[0], "skin", params[1]);

	SetPlayerSkin(params[0],params[1]);

	SFCM(params[0], -1, "• {FFC800}[Подсказка] "cWH"Администратор %s выдал вам постоянный №%d",pData[playerid][pNickname], params[1]);
	SFCM(playerid, -1, "• {FFC800}[Подсказка] "cWH"Вы выдали %s [%d] постоянный скин №%d",pData[params[0]][pNickname],params[0],params[1]);


	return true;
}

CMD:freeze(playerid, params[])
{
	if(pData[playerid][pAdmin] < 2) 
		return NoCMD(playerid);


	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/freeze [ID игрока]");

	TogglePlayerControllable(params[0], false);

	SFCM(params[0], -1, "• {FFC800}[Подсказка] "cWH"Администратор %s заморозил Вас!", pData[playerid][pNickname]);
	SFCM(playerid, -1, "• {00CC00}[Успешно] "cWH"Вы успешно заморозили %s[%d]", pData[params[0]][pNickname], params[0]);


	return true;
}

CMD:unfreeze(playerid, params[])
{
	if(pData[playerid][pAdmin] < 2) 
		return NoCMD(playerid);


	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/unfreeze [ID игрока]");

	TogglePlayerControllable(params[0], true);

	SFCM(params[0], -1, "• {FFC800}[Подсказка] "cWH"Администратор %s разморозил Вас!", pData[playerid][pNickname]);
	SFCM(playerid, -1, "• {00CC00}[Успешно] "cWH"Вы успешно разморозили %s[%d]", pData[params[0]][pNickname], params[0]);


	return true;
}

CMD:fv(playerid, params[])
{
	if(pData[playerid][pAdmin] < 4) 
		return NoCMD(playerid);

	if(sscanf(params,"I(-1)", params[0])) 
		return SendInf(playerid, "/fv [ID игрока]");

	if(params[0] == -1)
	{
		if(!IsPlayerInAnyVehicle(playerid)) 
			return SendErr(playerid, "Вы не в транспорте");
		return RepairVehicle(GetPlayerVehicleID(playerid)), SendSucc(playerid, "Транспорт починен");
	}



	if(!IsPlayerInAnyVehicle(params[0])) return SendErr(playerid, "Игрок не в транспорте");

	new id = GetPlayerVehicleID(params[0]);
	if(!IsValidVehicle(id)) return SendErr(playerid, "Транспорт недоступен");

	vehicle[id][cHealth] = 1000.0;

	RepairVehicle(id);
	SFCM(params[0], -1, "• {00CC00}[Успешно] Администратор %s починил Ваш транспорт", pData[playerid][pNickname]);

	format(String256,sizeof(String256),"Администратор %s починил транспорт игроку %s [%d] | Транспорт: №%d",pData[playerid][pNickname], pData[params[0]][pNickname],params[0], id);
	AdminChat(CGRAY,String256);

	logs_admin_other(playerid, pData[playerid][pMysqlID], String256);

 	return true;
}

CMD:fvc(playerid, params[])
{
	if(pData[playerid][pAdmin] < 4) 
		return NoCMD(playerid);

	if(sscanf(params,"I(-1)", params[0])) 
		return SendInf(playerid, "/fvc [ID транспорта]");

	if(params[0] == -1)
	{
		if(!IsValidVehicle(params[0])) 
			return SendErr(playerid, "Транспорт недоступен");

		return RepairVehicle(params[0]), SendSucc(playerid, "Транспорт починен");
	}

	if(!IsValidVehicle(params[0])) 
		return SendErr(playerid, "Транспорт недоступен");

	vehicle[params[0]][cHealth] = 1000.0;

	RepairVehicle(params[0]);

	format(String256,sizeof(String256),"Администратор %s починил транспорт №%d",pData[playerid][pNickname], params[0]);
	AdminChat(CGRAY,String256);

	logs_admin_other(playerid, pData[playerid][pMysqlID], String256);

 	return true;
}

CMD:hp(playerid, params[])
{
	if(pData[playerid][pAdmin] < 4) 
		return NoCMD(playerid);

	if(sscanf(params,"I(-1)d", params[0], params[1])) 
		return SendInf(playerid, "/hp [ID игрока] [Кол-во HP]");

	if(!IsPlayerConnected(params[0]))
		return SendErr(playerid,"Неверный ID игрока");

	if(params[0] == -1)
	{
		SetPlayerHealth(playerid, 100.0);
		SendSucc(playerid, "Вы выдали себе 100 здоровья!");
		show_hud_element(playerid);
		return true;
	}


	if(pData[playerid][pAdmin] < 5)
	{
		if(params[1] < 1 || params[1] > 100)
			return SendErr(playerid, "От 1 до 100 ХП");
	}

	SFCM(params[0], -1, "• {FFC800}[Подсказка] "cWH"%s изменил Вам количество здоровья", pData[playerid][pNickname]);
	SFCM(playerid,0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"установили здоровье игроку %s [%d] на %d единиц",pData[params[0]][pNickname], params[0], params[1]);

	SetPlayerHealth(params[0], params[1]);

	pData[params[0]][pHealth] = params[1];

	show_hud_element(params[0]);
	show_hud_element(playerid);

	format(String256,sizeof(String256),"Администратор %s установили здоровье игроку %s [%d] на %d единиц",pData[playerid][pNickname], pData[params[0]][pNickname],params[0], params[1]);
	AdminChat(CGRAY,String256);

	logs_admin_other(playerid, pData[playerid][pMysqlID], String256);


 	return true;
}


CMD:slap(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1) 
		return NoCMD(playerid);

	if(sscanf(params,"d", params[0])) 
		return SendInf(playerid, "/slap [ID игрока]");



	if(pData[params[0]][pAdmin] > pData[playerid][pAdmin]) 
		return NoPlayer(playerid);

	if(!IsPlayerConnected(params[0]))
		return SendErr(playerid,"Неверный ID игрока");

	if(GetPlayerState(params[0]) == PLAYER_STATE_SPECTATING)
		return true;

	new 
		Float:x, Float:y, Float:z;

	GetPlayerPos(params[0], x, y, z);

	SetPlayerPosDebug(params[0], x, y, z + 5.0);

	PlayerPlaySound(params[0], 1130, 0.0, 0.0, 0.0);

	format(String256,sizeof(String256),"Администратор %s [%d] слапнул игрока %s [%d]",pData[playerid][pNickname], playerid, pData[params[0]][pNickname],params[0]);
	AdminChat(CGRAY,String256);

	logs_admin_other(playerid, pData[playerid][pMysqlID], String256);

	return true;
}

CMD:down(playerid, params[])
{
	if (pData[playerid][pAdmin] < 3) return 1;

	if(sscanf(params,"d", params[0])) 
		return SendInf(playerid, "/down [ID игрока]");


    if(pData[playerid][pAdmin] < pData[params[0]][pAdmin]) 
    	return SendClientMessage(playerid, COLOR_GREY, "Вы не можете подкидывать админстратора выше уровнем");

    new string[80];
    new Float:slx, Float:sly, Float:slz;

	TogglePlayerControllable(params[0],1);
	GetPlayerPos(params[0], slx, sly, slz);
	SetPlayerPosDebug(params[0], slx, sly, slz-2);
    PlayerPlaySound(params[0], 1130, slx, sly, slz+5);
	format(string, sizeof(string), "Администратор %s опустил игрока %s",pData[playerid][pNickname], pData[params[0]][pNickname]);
	AdminChat(COLOR_GRAD1,string);

	logs_admin_other(playerid, pData[playerid][pMysqlID], string);

	return true;
}

alias:delv("respv", "respawnradius");
CMD:delv(playerid, params[])
{
	if(pData[playerid][pAdmin] < 3) 
		return NoCMD(playerid);
	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/delv [радиус (0 - удалить все)]");

 	GetPlayerPos(playerid,ACInfo[playerid][acPosX],ACInfo[playerid][acPosY], ACInfo[playerid][acPosZ]);

	new count;
	for(new i = 0,j = MAX_VEHICLES; i < j;i++)
    {
        if(!vehicle[i][cIsCreated]) continue;
		if(IsVehicleOccupied(i) || !IsValidVehicle(i)) continue;
		if(!params[0])
		{
			
		    DestroyVehicle(i);
			vehicle[i][cIsCreated] = false;
			count++;
			vehicle_is_rent(i);
		}
		else
		{
	        if(params[0] >= GetVehicleDistanceFromPoint(i, ACInfo[playerid][acPosX],ACInfo[playerid][acPosY], ACInfo[playerid][acPosZ])) 
	        	DestroyVehicle(i), vehicle[i][cIsCreated] = false, vehicle_is_rent(i), count++;
  		}
    }
	new temp_string[144];
	if(params[0] != 0)
		format(temp_string, 144, "[A] %s [%d] удалил весь созданный транспорт в радиусе %d м. от него (%d шт.)", pData[playerid][pNickname], playerid, params[0], count);
	else
		format(temp_string, 144, "[A] %s [%d] удалил весь созданный транспорт (%d шт.)", pData[playerid][pNickname], playerid, count);

	AdminChat(CGRAY,temp_string);
	logs_admin_other(playerid, pData[playerid][pMysqlID], temp_string);

	return true;
}

alias:getweapon("gtw", "пуецуфзщт", "пем", "weap");
CMD:getweapon(playerid, params[])
{
	if(pData[playerid][pAdmin] < 2) 
		return NoCMD(playerid);

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/weap [ID игрока]");

	if(!IsPlayerConnected(params[0]))
		return SendErr(playerid,"Неверный ID игрока");

	static
		temp_string[400],
		tmp[60], 
		gunname[30],
		d_name[36];

	format(d_name, 36, ""cBLUE"Оружие %s:", pData[params[0]][pNickname]);
	format(temp_string, 400, ""cGREY"Слот\t"cGREY"Название\t"cGREY"Патроны\n");

	for(new i; i < 13; i++)
	{
		GetWeaponName(ACInfo[params[0]][acWeapon][i], gunname, 30);
		if(!ACInfo[params[0]][acAmmo][i])
	    	format(tmp, 60, ""cBLUE"%d\t"cWH"\t0\n", i);
	    else
	    	format(tmp, 60, ""cBLUE"%d\t"cWH"%s\t%d\n", i, gunname, ACInfo[params[0]][acAmmo][i]);

		strcat(temp_string, tmp);
	}

	SPD(playerid, 0, DIALOG_STYLE_MSGBOX, d_name, temp_string, !"Закрыть", !"");
	temp_string[0] = EOS;
	return true;
}

CMD:agun(playerid, params[])
{
	if(pData[playerid][pAdmin] < 2) 
		return NoCMD(playerid);

	if(sscanf(params, "ddd", params[0], params[1], params[2]))
	{
		SendInf(playerid, "/agun [id игрока] [id оружия] [патроны]"),

		SendInf(playerid, "[3] Дубинка [4] Нож [5] Бита [6] Лопата [7] Кий [8] Катана");
		SendInf(playerid, "[9] Бензопила [10-13] Дилдо [14] Цветы [15] Топор [16-18] Гранаты [22] Пистолет");
		SendInf(playerid, "[23] Пистолет с глушителем [24] Desert Eagle [25] Дробовик [26] Обрез");
		SendInf(playerid, "[27] Боевой дробовик [28] UZI [29] MP5 [30] AK-47");
		SendInf(playerid, "[31] М4 [32] TEC9 [33] Охотничье ружье [34] Снайперская винтовка");
		SendInf(playerid, "[35] РПГ [36] Самонаводящиеся ракеты [37] Огнемет [38] Миниган");
		SendInf(playerid, "[41] Баллончик с краской [42] Огнетушитель [43] Камера [46] Парашют");
		return true;
	}

	if(!IsPlayerConnected(params[0]))
		return SendErr(playerid,"Неверный ID игрока");

	GivePlayerWeaponEx(params[0], params[1], params[2]);

	new
		weap_name[30];

	GetWeaponName(params[1], weap_name, 30);

	format(String256,sizeof(String256),"Администратор %s [%d] выдал оружие %s игроку %s [%d] с %d патронов",pData[playerid][pNickname], playerid, weap_name, pData[params[0]][pNickname], params[0], params[2]);
	AdminChat(CGRAY,String256);

	logs_admin_other(playerid, pData[playerid][pMysqlID], String256);

	return true;
}

CMD:gun(playerid, params[])
{
	if(pData[playerid][pAdmin] < 4) 
		return NoCMD(playerid);

	if(sscanf(params, "dd", params[1], params[2]))
	{
		SendInf(playerid, "/gun [id оружия] [патроны]"),

		SendInf(playerid, "[3] Дубинка [4] Нож [5] Бита [6] Лопата [7] Кий [8] Катана");
		SendInf(playerid, "[9] Бензопила [10-13] Дилдо [14] Цветы [15] Топор [16-18] Гранаты [22] Пистолет");
		SendInf(playerid, "[23] Пистолет с глушителем [24] Desert Eagle [25] Дробовик [26] Обрез");
		SendInf(playerid, "[27] Боевой дробовик [28] UZI [29] MP5 [30] AK-47");
		SendInf(playerid, "[31] М4 [32] TEC9 [33] Охотничье ружье [34] Снайперская винтовка");
		SendInf(playerid, "[35] РПГ [36] Самонаводящиеся ракеты [37] Огнемет [38] Миниган");
		SendInf(playerid, "[41] Баллончик с краской [42] Огнетушитель [43] Камера [46] Парашют");
		return true;
	}



	GivePlayerWeaponEx(playerid, params[1], params[2]);

	new
		weap_name[30];

	GetWeaponName(params[1], weap_name, 30);

	format(String256,sizeof(String256),"Администратор %s [%d] выдал себе оружие %s с %d патронов",pData[playerid][pNickname], playerid, weap_name, params[2]);
	AdminChat(CGRAY,String256);

	logs_admin_other(playerid, pData[playerid][pMysqlID], String256);

	return true;
}


CMD:spawn(playerid, params[])
{
	if(pData[playerid][pAdmin] < 2) 
		return NoCMD(playerid);


	if(sscanf(params, "I(-1)", params[0])) 
		return SendInf(playerid, "Используйте: /spawn [ID игрока]");

	if(params[0] == -1)
	{
		return SpawnPlayer(playerid);
	}

	pTemp[params[0]][spawn_id] = SPAWN_NONE;

	SpawnPlayer(params[0]);

	PSPAWN[params[0]] = 1;

	new 
		temp_string[144];


	format(temp_string,sizeof(temp_string),"Администратор %s [%d] заспавнил игрока %s [%d]",pData[playerid][pNickname], playerid, pData[params[0]][pNickname], params[0]);
	AdminChat(CGRAY,temp_string);

	logs_admin_other(playerid, pData[playerid][pMysqlID], temp_string);

	return true;

}

CMD:a(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1) 
		return NoCMD(playerid);

	if(sscanf(params, "s[128]", params[0])) 
		return SendInf(playerid, "Используйте: /a [Текст]");

	new 
		temp_string[144];

	format(temp_string,sizeof(temp_string),"[A] %s[%i]: %s",pData[playerid][pNickname],playerid,params[0]);
	AdminChat(0x9ACD32AA, temp_string);

	//logs_admin_achat(playerid, pData[playerid][pMysqlID], temp_string);

	return true;

}


CMD:giveveh(playerid, params[])
{
	if(pData[playerid][pAdmin] < 8) 
		return NoCMD(playerid);



	if(sscanf(params, "dd", params[0], params[1])) 
		return SendInf(playerid, "Используйте: /giveveh [ID игрока] [ID авто]");

	if(pData[playerid][pCar] != 0)
		return SendInf(playerid, "У игрока уже есть транспорт!");


	format(String1024,sizeof(String1024),"INSERT INTO `player_vehicles`(`userid`,`model`) VALUES ('%d','%d')", pData[params[0]][pMysqlID], params[1]);
	sql_queryEx(zConn, String1024, QUERY_THREADED);

	SFCM(playerid,0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Вы успешно выдали %s [%d] автомобиль в личное пользование %d!",pData[params[0]][pNickname], params[0], params[1]);

	return SendSucc(playerid, "Вы успешно выдали игроку транспорт!");
}

CMD:auninviteall(playerid, params[])
{
	if(pData[playerid][pAdmin] < 7) 
		return NoCMD(playerid);

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "Используйте: /auninviteall [ID фракции (3-7)]");


	new 
		fracid = params[0];

	if(fracid < 3 || fracid > 7) 
		return SendInf(playerid, "Неверный ID фракции");

	new query[256];
	format(query,sizeof(query),"UPDATE `accounts` SET `fraction` = '0', `rank` = '0', `dvs` = '0', `fractionskin` = '0', `subfraction` = '0'WHERE `fraction` = '%d'", fracid );
	sql_queryEx(zConn, query, QUERY_THREADED);

	foreach(new actplayerid: logged_players) 
	{
	    if( pData[actplayerid][pFraction] == fracid )
	    {
			pData[actplayerid][pFraction] = 0;
			pData[actplayerid][pRank] = 0;
			pData[actplayerid][pDivision] = 0;
			pData[actplayerid][pFractionSkin] = 0;
			pData[actplayerid][pSubfraction] = 0;
			pData[actplayerid][pFWarn] = 0;
			UpdatePlayerData(actplayerid, "fwarn", pData[actplayerid][pFWarn]);

			SetPlayerColor(actplayerid,0xFFFFFF11);

			SetPlayerSkin(actplayerid,pData[actplayerid][pSkin]);
			new mes[128];
			format(mes,sizeof(mes),"Администратор %s расформировал Вашу банду",pData[playerid][pNickname]);
			SendClientMessage(actplayerid,CBADINFO,mes);
		}
	}

	format(String256,sizeof(String256),"Банда %s была расформирована администратором %s", gFractionName[fracid-1],pData[playerid][pNickname]);
	AdminChat(COLOR_LIGHTRED,String256);

	logs_admin_other(playerid, pData[playerid][pMysqlID], String256);

	return true;
}

CMD:auninvite(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5) 
		return NoCMD(playerid);

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "Используйте: /auninvite [ID игрока]");


	new actplayerid = params[0];
	if(!IsPlayerConnected(actplayerid))
		return SendErr(playerid,"Неверный ID игрока");

	if(!pData[actplayerid][pFraction]) 
		return SendErr(playerid,"Игрок не состоит во фракции");

	new query[256];
	format(query,sizeof(query),"UPDATE `accounts` SET `fraction` = '0', `rank` = '0', `dvs` = '0', `fractionskin` = '0', `subfraction` = '0' WHERE `id` = '%d'",pData[actplayerid][pMysqlID]);
	sql_queryEx(zConn, query, QUERY_THREADED);
	pData[actplayerid][pFraction] = 0;
	pData[actplayerid][pRank] = 0;
	pData[actplayerid][pDivision] = 0;
	pData[actplayerid][pFractionSkin] = 0;
	pData[actplayerid][pSubfraction] = 0;
	pData[actplayerid][pFWarn] = 0;
	UpdatePlayerData(actplayerid, "fwarn", pData[actplayerid][pFWarn]);

	SetPlayerColor(actplayerid,0xFFFFFF11);

	SetPlayerSkin(actplayerid,pData[actplayerid][pSkin]);

	new mes[128];
	format(mes,sizeof(mes),"Администратор %s уволил Вас из организации",pData[playerid][pNickname]);
	SendClientMessage(actplayerid,CBADINFO,mes);
	format(mes,sizeof(mes),"%s был уволен из организации",pData[actplayerid][pNickname]);
	SendClientMessage(playerid,CINFO,mes);

	format(mes,sizeof(mes),"%s был уволен из организации администратором %s",pData[actplayerid][pNickname], pData[playerid][pNickname]);
	logs_admin_other(playerid, pData[playerid][pMysqlID], mes);

	return true;
}

CMD:kick(playerid, params[])
{
	if(pData[playerid][pAdmin] < 2) 
		return NoCMD(playerid);

	if(sscanf(params, "ds[64]", params[0], params[1])) 
		return SendInf(playerid, "Используйте: /kick [ID игрока] [Причина]");


	new id = params[0];
	if(!IsPlayerConnected(id)) 
		return SendErr(playerid,"Неверный ID");


	new mes[128];
	new nick[24];
	if(pData[id][pAdmin] > pData[playerid][pAdmin]) 
	{
        format(mes,sizeof(mes),"Администратор %s попытался кикнуть Администратора %s",pData[playerid][pNickname],pData[id][pNickname]);
		AdminChat(CGRAY,mes);
		return 1;
	}
	if(pData[id][pAdmin] == 7 && pData[playerid][pAdmin] < 8) 
		return SendClientMessage(playerid, -1, "Данный игрок является старшим администратором!");

	GetPlayerName(id,nick,24);
	format(mes,sizeof(mes),"Администратор %s кикнул игрока %s. Причина: %s",pData[playerid][pNickname],nick,params[1]);
	SendAdminMessage(COLOR_LIGHTRED,mes,id);

	logs_admin(playerid, pData[playerid][pMysqlID], mes);

	show_notify_gui(params[0], TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_33", 4000);

	NewKick(id);
	pData[ playerid ][pScoreGame][11] += 2;
	UpdatePlayerData( playerid , "game12", pData[ playerid ][ pScoreGame ][11] );

	return true;

}

CMD:deloffadmin(playerid, params[])
{
	if(pData[playerid][pAdmin] >= 7)
	{

		if(sscanf(params, "s[32]", params[0])) 
			return SendInf(playerid, "Используйте: /deloffadmin [Ник]");


		if(strfind(params[0],"'") != -1 || strfind(params[0],"`") != -1 || strfind(params[0],"|") != -1 || strfind(params[0],"%%") != -1 || strfind(params[0],"\\") != -1 )
  		{
 	 		return SendInf(playerid, "Используйте: /deloffadmin [Ник]");
		}
	   	new query[300];
		sql_escape_string(zConn, params[0], params[0], 128);
	   	format(query, sizeof(query), "SELECT `admin` FROM `accounts` WHERE `nickname` = '%s'", params[0]);
	   	new Result:r = sql_queryEx(zConn, query, QUERY_CACHED);
	   	if(!sql_num_rows(r)) return SendErr(playerid,"Неверный никнейм");
	   	new sqlid = sql_get_field_int(r, 0);
		sql_free_result(r);
		if( sqlid < 1 ) return SendErr(playerid,"Данный игрок не является администратором");
		format(String256,sizeof(String256),"UPDATE `accounts` SET `admin` = '0', `phone` = '0', `table` = '0' WHERE `nickname` = '%s'", params[0]);
		sql_queryEx(zConn, String256, QUERY_THREADED);
	    format(String256,sizeof(String256),"Администратор %s снял с должности %s в оффлайн режиме",pData[playerid][pNickname], params[0]);
	    AdminChat(COLOR_LIGHTRED,String256);

	    logs_admin(playerid, pData[playerid][pMysqlID], String256);
	}
	return 1;
}

CMD:unmute(playerid, params[])
{
	if(pData[playerid][pAdmin] < 2) return 1;

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "Используйте: /unmute [ID игрока]");



	new id = params[0];
	if(!IsPlayerConnected(id)) 
		return SendErr(playerid,"Неверный ID");
	if(!pData[id][pMysqlID]) 
		return SendErr(playerid,"Этот игрок не зарегистрирован");
	if(pData[id][pMut] == 0) 
		return SendErr(playerid,"Данный игрок не наказан бан чатом!");

	pData[id][pMut] = 0;
	UpdatePlayerData(id,"mut",0);

	VoiceChat_UnMutePlayer(playerid);

	new mes[128];
	format(mes,sizeof(mes),"Администратор %s снял бан чата игроку %s",pData[playerid][pNickname],pData[id][pNickname]);
	SendClientMessageToAll(COLOR_LIGHTRED,mes);


	logs_admin(playerid, pData[playerid][pMysqlID], mes);

	format(mes,sizeof(mes),"Администратор %s снял вам бан чата",pData[playerid][pNickname]);
	SendClientMessage(id,COLOR_LIGHTRED,mes);

	return true;
}

CMD:unban(playerid, params[])
{
	if(pData[playerid][pAdmin] < 3) return 1;

	new 
		nickname[32];

	if(sscanf(params, "s[32]", nickname)) 
		return SendInf(playerid, "Используйте: /unban [Ник]");

	UnBanAccount(playerid, nickname);

	return true;
}


CMD:warn(playerid, params[])
{
	if(pData[playerid][pAdmin] < 3) 
		return NoCMD(playerid);

	if(sscanf(params, "ds[32]", params[0], params[1])) 
		return SendInf(playerid, "Используйте: /warn [ID игрока] [Причина]");

	new 
		id = params[0];

	if(!IsPlayerConnected(id) || IsKicked(id))
		return SendErr(playerid,"Неверный ID");

	if(!pData[id][pMysqlID]) 
		return SendErr(playerid,"Этот игрок не зарегистрирован");

	if(pData[id][pAdmin] == 7 && pData[playerid][pAdmin] < 8) 
		return SendClientMessage(playerid, -1, "Данный игрок является старшим администратором!");

	if(pData[id][pAdmin] == 8 && pData[playerid][pAdmin] < 8) 
		return SendClientMessage(playerid, -1, "Данный игрок является старшим администратором!");

	new 
		mes[266];

	ResetPlayerWeaponsEx(id);
	pData[id][pWarnc]++;

	if(pData[id][pWarnc]-1 > 0)
	{
	 	pData[id][pWarn] += WARN_TIME;
	}
	else
	{
		pData[id][pWarn] = gCurDay + WARN_TIME;
	} 

	format(mes,sizeof(mes),"UPDATE `accounts` SET `warn` = '%i', `warnc` = '%i', `fraction` = '0', `subfraction` = '0',`rank` = '0',`fwarn` = '0', `fractionskin` = '0' WHERE `id` = '%d'",pData[id][pWarn],pData[id][pWarnc],pData[id][pMysqlID]);
	sql_queryEx(zConn, mes, QUERY_THREADED);

	if(pData[id][pWarnc] < 3) 
	{
		format(String144,sizeof(String144),"Администратор %s выдал предупреждение игроку %s [%i/3]. Причина: %s",pData[playerid][pNickname],pData[id][pNickname],pData[id][pWarnc],params[1]);
		logs_admin(playerid, pData[playerid][pMysqlID], String144);

		show_notify_gui(id, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_35", 4000);
	}
	else
	{
	    format(mes,sizeof(mes),"UPDATE `accounts` SET `warn` = '0', `warnc` = '0' WHERE `id` = '%d'", pData[id][pMysqlID]);
		sql_queryEx(zConn, mes, QUERY_THREADED);

		format(String144,sizeof(String144),"Администратор %s забанил игрока %s (3 предупреждения). Причина: %s",pData[playerid][pNickname],pData[id][pNickname],params[1]);
		logs_admin(playerid, pData[playerid][pMysqlID], String144);


		new
			date[35], 
			h, m, s, 
			day, month, year;  

		gettime(h, m, s);
		getdate(year, month, day);
		format(date, sizeof(date),"%d-%02d-%d %02d:%02d:%02d", year, month, day, h, m, s);

		OnlineBanAccount(playerid, id, params[1], date, 10);

	}
	SendClientMessageToAll(COLOR_LIGHTRED, String144);
	NewKick(id);
	return true;
}

CMD:offmute(playerid, params[])
{
    if(pData[playerid][pAdmin] < 1)
    	return NoCMD(playerid);

    new 
    	nick[32];
    new id;

	if(sscanf(params, "s[32]s[32]", nick, params[1])) 
		return SendInf(playerid, "/offmute [Ник игрока] [Причина] [Минуты]");

	new query[128];
	format(query,sizeof(query),"SELECT * FROM `accounts` WHERE `nickname` = '%s'",nick);
	new Result:zID = sql_queryEx(zConn, query, QUERY_CACHED);
	if(!sql_num_rows(zID)) 
	{ 
		sql_free_result(zID);
		id = sql_get_field_assoc_int_ex(zID, 0, "id");
		return SendErr(playerid,"Неверный никнейм"); 
	}

	new 
		adm = sql_get_field_assoc_int_ex(zID, 0, "admin");

	sql_free_result(zID);

	if(adm > pData[playerid][pAdmin] && pData[playerid][pAdmin] < 8) 
		return SendErr(playerid,"Вы не можете замутить администратора выше уровнем");

    if( pData[id][pMut] > 0)
	{
		format(String256, sizeof( String256), "Время бана чата игрока: %d мин",pData[id][pMut]);
		SendInf(playerid, String256);
	}

	new time = params[2];
	if(time < 10 || time > 180) 
		return SendErr(playerid,"Введите время от 10 до 180 минут");
	if(pData[id][pMut] > 0) 
		return SendClientMessage(playerid, -1, "Данному игроку уже выдан бан чата!");
	if(pData[id][pAdmin] == 7 && pData[playerid][pAdmin] < 8) 
		return SendClientMessage(playerid, -1, "Данный игрок является старшим администратором!");

    new uery[128];
	format(uery,sizeof(uery),"UPDATE `pMut` FROM `accounts` WHERE `nickname` = '%s'",nick);
	sql_queryEx(zConn, uery, QUERY_CACHED);
	
	new mes[144];
	format(mes,sizeof(mes),"Администратор %s выдал оффлайн бан чата игроку %s на %d минут. Причина: %s",pData[playerid][pNickname],pData[id][pNickname],time,params[2]);
	SendAdminMessage(COLOR_LIGHTRED,mes,id);

	logs_admin(playerid, pData[playerid][pMysqlID], mes);
	
    return true;
}

CMD:offwarn(playerid, params[])
{
    if(pData[playerid][pAdmin] < 3) 
    	return NoCMD(playerid);

    new 
    	nick[32];

	if(sscanf(params, "s[32]s[32]", nick, params[1])) 
		return SendInf(playerid, "/offwarn [Ник игрока] [Причина]");

	new query[128];
	format(query,sizeof(query),"SELECT * FROM `accounts` WHERE `nickname` = '%s'",nick);
	new Result:zID = sql_queryEx(zConn, query, QUERY_CACHED);
	if(!sql_num_rows(zID)) 
	{ 
		sql_free_result(zID); 
		return SendErr(playerid,"Неверный никнейм"); 
	}

	new 
		adm = sql_get_field_assoc_int_ex(zID, 0, "admin");

	sql_free_result(zID);

	if(adm > pData[playerid][pAdmin] && pData[playerid][pAdmin] < 8) 
		return SendErr(playerid,"Вы не можете заварнить администратора выше уровнем");

    AddOffline(playerid, nick, params[1]);
    return true;
}

stock AddOffline(playerid, name[], reason[])
{
	if(pData[playerid][pAdmin] < 4) 
		return true;

	if(!strlen(name) || !strlen(reason)) 
		return SendInf(playerid, "/off(назв) [ник] [причина]");

    if(strlen(reason) > 32 || strlen(reason) < 2) 
    	return SendErr(playerid, "Причина может быть от 2 символов до 32");

    if(strfind(reason,"`") != -1 || strfind(reason,"'") != -1 || strfind(reason,"=") != -1) 
    	return SendErr(playerid, "Найдены запрещенные символы в причине наказания");

    if(strfind(name,"`") != -1 || strfind(name,"'") != -1 || strfind(name,"=") != -1) 
    	return SendErr(playerid, "Найдены запрещенные символы в нике");

	sql_escape_string(zConn, name, name, 32);

    if(GetPlayerID(name) != -1) 
    	return SendErr(playerid, "Игрок с данным именем находится на сервере. Выдать наказание не удалось");

	new query[256];
	format(query,sizeof(query),"SELECT * FROM `accounts` WHERE `nickname` = '%s'", name);
	new Result:zID = sql_queryEx(zConn, query, QUERY_CACHED);
	if(!sql_num_rows(zID)) 
	{ 
		sql_free_result(zID); 
		return SendErr(playerid,"Неверный никнейм"); 
	}

	new 
		warntime = sql_get_field_assoc_int_ex(zID, 0, "warn"),
		warnc = sql_get_field_assoc_int_ex(zID, 0, "warnc");
	sql_free_result(zID);

	if(warnc < 2)
	{	
		if(warnc-1 > 0)
		{
		 	warntime += WARN_TIME;
		}
		else
		{
			warntime = gCurDay + WARN_TIME;
		}
		// Дописать добавление инфы в /notify для игрока 

		send_off_message(-1, name, "Вы были выселены из дома за неуплату комнаты!");

		format(query, sizeof(query), "UPDATE `accounts` SET `warn` = '%i', `warnc` = '%i', `fraction` = '0', `subfraction` = '0',`rank` = '0',`fwarn` = '0', `fractionskin` = '0' WHERE `nickname` = '%s'", warntime, warnc, name);
		sql_queryEx(zConn, query, QUERY_THREADED);

		format(String144, sizeof(String144), "%s получил оффлайн предупреждение от Администратора %s. Причина: %s", name, pData[playerid][pNickname], reason);
		SendClientMessageToAll(COLOR_LIGHTRED, String144);

		send_off_message(pData[playerid][pNickname], name, String144);
	}
	else
	{
		format(String144, sizeof(String144), "Игрок %s получил оффлайн бан (3 предупреждения) от Администратора %s. Причина: %s", name, pData[playerid][pNickname], reason);
		SendClientMessageToAll(COLOR_LIGHTRED, String144);

		new 
			query[256];	
		sql_escape_string(zConn, name,name, 25);
	   	format(query, sizeof(query), "SELECT `id`, `admin` FROM `accounts` WHERE `nickname` = '%s'", name);
		new Result:numacc = sql_queryEx(zConn, query, QUERY_CACHED);

		if(!sql_num_rows(numacc)) 
			return SendErr(playerid, "Аккаунт не найден в базе данных");

		new id = sql_get_field_assoc_int(numacc, "id");
		new admin = sql_get_field_assoc_int(numacc, "admin");
		sql_free_result(numacc);


		new
			date[35], 
			h, m, s, 
			day, month, year;  

		gettime(h, m, s);
		getdate(year, month, day);
		format(date, sizeof(date),"%d-%02d-%d %02d:%02d:%02d", year, month, day, h, m, s);

		OfflineBanAccount(playerid, id, name, reason, date, 10);

	}
	return true;
}

CMD:unwarn(playerid, params[])
{
	if(pData[playerid][pAdmin] < 3) 
		return NoCMD(playerid);

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "Используйте: /unwarn [ID игрока]");


	new 
		id = params[0];

	if(!IsPlayerConnected(id)) 
		return SendErr(playerid,"Неверный ID");

	if(!pData[id][pMysqlID]) 
		return SendErr(playerid,"Этот игрок не зарегистрирован");

	if(!pData[id][pWarnc]) 
		return SendErr(playerid,"У этого игрока нет варнов");

	pData[id][pWarn] -= WARN_TIME;
	pData[id][pWarnc] -= 1;
	UpdatePlayerData(id,"warn",pData[id][pWarn]);
	UpdatePlayerData(id,"warnc",pData[id][pWarnc]);

	format(String144, sizeof(String144), "Администратор %s снял предупреждение игроку %s", pData[playerid][pNickname], pData[id][pNickname]);
	AdminChat(0xAFAFAFff,String144);

	logs_admin(playerid, pData[playerid][pMysqlID], String144);

	format(String144, sizeof(String144), "Администратор %s снял Вам предупреждение", pData[playerid][pNickname]);
	SendClientMessage(id, COLOR_LIGHTRED, String144);
	return true;
}

CMD:unwarnoff(playerid, params[])
{
    if(pData[playerid][pAdmin] < 4) 
		return NoCMD(playerid);

    new 
    	nick[32];

	if(sscanf(params, "s[32]", nick)) 
		return SendInf(playerid, "Используйте: /unwarnoff [Ник]");

    if(GetPlayerID(nick) != -1) 
    	return SendErr(playerid, "Игрок с данным именем находится на сервере. Снять наказание не удалось");

	new 
		query[256];

	format(query,sizeof(query),"SELECT * FROM `accounts` WHERE `nickname` = '%s' AND warnc > 0",nick);
	new Result:zID = sql_queryEx(zConn, query, QUERY_CACHED);

  	if(!sql_num_rows(zID)) 
  	{
	  SendErr(playerid, "Данный игрок не найден в базе данных/не имеет предупреждений");
	  sql_free_result(zID);
	  return true;
	}
	sql_free_result(zID);

	format(query,sizeof(query),"UPDATE `accounts` SET `warn` = warn - %i , `warnc` = warnc - 1 WHERE `nickname` = '%s'", WARN_TIME, nick);
	sql_queryEx(zConn, query);

	format(query,sizeof(query),"Администратор %s снял предупреждение игроку %s", pData[playerid][pNickname], nick);
	AdminChat(0xAFAFAFff,query);

	logs_admin(playerid, pData[playerid][pMysqlID], query);
	return true;
}

CMD:ssteretacc(playerid, params[])
{
    new 
    	nick[32];

	if(pData[playerid][pAdmin] >= 7)
	{

		if(sscanf(params, "s[32]", nick)) 
			return SendInf(playerid, "Используйте: /ssteretacc [Ник]");


		sql_escape_string(zConn, nick, nick, 256);
		SetPVarStringNew(playerid, "delakk", nick );

		new query[256];
		format(query,sizeof(query),"SELECT `id`,`ip`,`money`,`bank`,`level`,`last`,`create_date`,`donate`,`LastIP` FROM `accounts` WHERE `nickname` = '%s'",nick);
		new Result:r = sql_queryEx(zConn, query, QUERY_CACHED);
		if(!sql_num_rows(r)) {
		sql_free_result(r);
		return SendErr(playerid,"Неверный Ник");}
		new IPF[32];
		new ip[32];
		new regdate[32];
		new lastdate[32];
		new IDS = sql_get_field_int(r, 0);
		sql_get_field(r, 1, IPF);
		new MONEY = sql_get_field_int(r, 2);
		new BANKI = sql_get_field_int(r, 3);
		new LEVEL = sql_get_field_int(r, 4);
		sql_get_field(r, 5, lastdate);
		sql_get_field(r, 6, regdate);
		new DONAT = sql_get_field_int(r, 7);
		sql_get_field(r, 8, ip);
		sql_free_result(r);

 		new y,m,d,h,mi,s;
		getdate(y,m,d);
		gettime(h,mi,s);
		format(String256,sizeof(String256),"INSERT INTO `unbanlog` VALUES('','%s','%s','%d-%d-%d %d:%d:%d','%d')",pData[playerid][pNickname],params[0],y,m,d,h,mi,s,101);
		sql_queryEx(zConn, String256,QUERY_THREADED);

		format(String1024,sizeof(String1024),"\n\n\n"cWH"Вы действительно хотите удалить аккаунт {00AD00}%s\n\
		Номер аккаунта:\t%d\n\
		Наличные:\t\t%d\n\
		Осн. банк счёт:\t\t%d\n\
		Уровень:\t\t%d\nIP адрес(регис.):\t%s\n\
		IP адрес(послед.):\t%s\n\
		Дата регистрации:\t%s\n\
		Дата авторизации:\t%s\n\
		Донат:\t\t\t%d\n\n\n",nick,IDS,MONEY,BANKI,LEVEL,IPF,ip,regdate,lastdate, DONAT);
		return SPD(playerid, dAcceptDel, DIALOG_STYLE_MSGBOX, "{FFFF1A}Удаление аккаунта", String1024, "Удалить", "Отмена");
	}

	return true;
}

CMD:skick(playerid, params[])
{
	if(pData[playerid][pAdmin] < 2) 
		return NoCMD(playerid);

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "Используйте: /skick [ID игрока]");



	new id = params[0];
	if(!IsPlayerConnected(id) || IsKicked(id)) 
		return SendErr(playerid,"Неверный ID");

	if(pData[id][pAdmin] == 7 && pData[playerid][pAdmin] < 8) 
		return SendClientMessage(playerid, -1, "Данный игрок является старшим администратором!");

	if( pTemp[id][pCasinoBet][0] > 0 || pTemp[id][pCasinoBet][1] > 0 || pTemp[id][pCasinoBet][2] > 0  || pTemp[id][pCasinoBet][3] > 0 || pTemp[id][pBJBet][0] > 0
	|| pTemp[id][pBJBet][1] > 0 || pTemp[id][pBJBet][2] > 0 || pTemp[id][pBJBet][3] > 0 )
    {
	    SendErr(playerid,"В данный момент нельзя кинуть данного игрока тихо");
		return 1;
	}

	new mes[256];
	if(pData[id][pAdmin] > pData[playerid][pAdmin]) 
	{
        format(mes,sizeof(mes),"Администратор %s попытался кикнуть Администратора %s",pData[playerid][pNickname],pData[id][pNickname]);
		AdminChat(CGRAY,mes);
		logs_admin(playerid, pData[playerid][pMysqlID], mes);
		return 1;
	}

	new nick[24];
	GetPlayerName(id,nick,24);
	format(mes,sizeof(mes),"Администратор %s кикнул игрока %s тихим киком.",pData[playerid][pNickname],nick);
	AdminChat(CGRAY,mes);
	logs_admin(playerid, pData[playerid][pMysqlID], mes);
	NewKick(id);

	pData[ playerid ][pScoreGame][11] += 2;
	UpdatePlayerData( playerid , "game12", pData[ playerid ][ pScoreGame ][11] );

	new y,m,d,h,mi,s;
	getdate(y,m,d);
	gettime(h,mi,s);

	format(mes,sizeof(mes),"INSERT INTO `unbanlog` VALUES('','%s','%s','%d-%d-%d %d:%d:%d','%d')",pData[playerid][pNickname],nick,y,m,d,h,mi,s,78);
	sql_queryEx(zConn, mes,QUERY_THREADED);

	return true;
}

CMD:debug(playerid, params[])
{
	if(pData[playerid][pAdmin] < 7) 
		return NoCMD(playerid);

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "Используйте: /debug [0 - Выключить 1- Включить]");

	opcode = params[0];

	return true;
}

CMD:ipkick(playerid, params[])
{
	if(pData[playerid][pAdmin] < 7) 
		return NoCMD(playerid);

	if(sscanf(params, "dd", params[0], params[1])) 
		return SendInf(playerid, "Используйте: /ipkick [ID игрока] [Минуты]");


	new id = params[0];
	if(!IsPlayerConnected(id) || IsKicked(id)) 
		return SendErr(playerid,"Неверный ID");

	new wid = params[1];
	if( wid < 0 || wid > 9999 ) return SendErr(playerid,"/ipkick [ID игрока] [Минуты]");

	new mes[128];
	new nick[24];
	if(pData[id][pAdmin] > pData[playerid][pAdmin]) 
	{
        format(mes,sizeof(mes),"Администратор %s попытался блокировать Администратора %s",pData[playerid][pNickname],pData[id][pNickname]);
		AdminChat(CGRAY,mes);
		logs_admin(playerid, pData[playerid][pMysqlID], mes);
		return 1;
	}
	if(pData[id][pAdmin] == 7 && pData[playerid][pAdmin] < 8) 
		return SendClientMessage(playerid, -1, "Данный игрок является старшим администратором!");

	new aipi[16];
	GetPlayerIp(id, aipi , 16);
	GetPlayerName(id,nick,24);
	BlockIpAddress( aipi , wid * 1000);

	format(mes,sizeof(mes),"Администратор %s заблокировал адрес игрока %s на %d минут",pData[playerid][pNickname],nick,wid);
	AdminChat(COLOR_LIGHTRED,mes);
	logs_admin(playerid, pData[playerid][pMysqlID], mes);
	return true;
}

CMD:getnumber(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

	if(sscanf(params, "s[16]", params[0])) 
		return SendInf(playerid, "/getnumber [номер]");
	if(pData[playerid][car_id] == INVALID_VEHICLE_ID) 
		return NoMyCar(playerid);
	
	new v = pData[playerid][car_id];


	format(vehicle[v][cPlate], 20, "%s", params[0]);

	//SetVehicleNumberPlate(v, vehicle[v][cPlate]);
	UpdateDynamic3DTextLabelText(vehicle[v][cLabel], 0xFFFFFFFF, vehicle[v][cPlate]);


	//vehicle_save(playerid, pData[playerid][car_sql_1]);
	return true;
}


CMD:setfuel(playerid, params[])
{
	if(pData[playerid][pAdmin] < 3) 
		return NoCMD(playerid);

	if(sscanf(params,"I(-1)", params[0])) 
		return SendInf(playerid, "/setfuel [ID авто]");

	if(params[0] == -1)
	{
		if(!IsPlayerInAnyVehicle(playerid)) 
			return SendErr(playerid, "Вы не в транспорте");

		new 
			fill_id_v_a = GetPlayerVehicleID(playerid);

		new strcom[144];
		format(strcom, 144, "• {00CC00}[Успешно] Вы установили 60 литров в авто №%d", fill_id_v_a);
		SCM(playerid, -1, strcom);

		vehicle[fill_id_v_a][cFuel] = transport_config[GetVehicleModel(fill_id_v_a)-400][transport_tank];

		format(strcom, 144, "[A] %s [%d] поставил 60 литров транспорту №%d", pData[playerid][pNickname], playerid, fill_id_v_a);
		AdminChat(COLOR_GREY,strcom);
		logs_admin_other(playerid, pData[playerid][pMysqlID], strcom);

		return true;
	}



    new carid = params[0];

	new strcom[144];
	format(strcom, 144, "• {00CC00}[Успешно] Вы установили 60 литров в авто №%d", carid);
	SCM(playerid, -1, strcom);

	vehicle[carid][cFuel] = 60;

	format(strcom, 144, "[A] %s [%d] поставил 60 литров транспорту №%d", pData[playerid][pNickname], playerid, carid);
	AdminChat(COLOR_GREY,strcom);
	logs_admin_other(playerid, pData[playerid][pMysqlID], strcom);
 	return true;
}

CMD:setoil(playerid, params[])
{
	if(pData[playerid][pAdmin] < 3) 
		return NoCMD(playerid);

	if(sscanf(params,"I(-1)", params[0])) 
		return SendInf(playerid, "/setoil [ID авто]");

	if(params[0] == -1)
	{
		if(!IsPlayerInAnyVehicle(playerid)) 
			return SendErr(playerid, "Вы не в транспорте");

		new 
			fill_id_v_a = GetPlayerVehicleID(playerid);

		new strcom[144];
		format(strcom, 144, "• {00CC00}[Успешно] Вы установили уровень масла в авто №%d", fill_id_v_a);
		SCM(playerid, -1, strcom);

		vehicle[fill_id_v_a][consumables_oil] = 1000.0;

		format(strcom, 144, "[A] %s [%d] поставил уровень масла транспорту №%d", pData[playerid][pNickname], playerid, fill_id_v_a);
		AdminChat(COLOR_GREY,strcom);
		logs_admin_other(playerid, pData[playerid][pMysqlID], strcom);

		return true;
	}



    new carid = params[0];

	new strcom[144];
	format(strcom, 144, "• {00CC00}[Успешно] Вы установили уровень масла в авто №%d", carid);
	SCM(playerid, -1, strcom);

	vehicle[carid][consumables_oil] = 1000.0;

	format(strcom, 144, "[A] %s [%d] поставил уровень масла транспорту №%d", pData[playerid][pNickname], playerid, carid);
	AdminChat(COLOR_GREY,strcom);
	logs_admin_other(playerid, pData[playerid][pMysqlID], strcom);
 	return true;
}


CMD:restimit(playerid, params[])
{
	if(pData[playerid][pAdmin] < 8) 
		return NoCMD(playerid);


	new time = GetTickCount();

	for(new i, idx = all_houses; i < idx; i ++) save_house(i);
	for(new i, idx = all_flates; i < idx; i ++) save_flate(i);
	for(new i, idx = all_apartaments; i < idx; i ++) save_entrance(i);
	for(new i, idx = all_hotels; i < idx; i ++) save_hotel(i);
	for(new i, idx = all_hotel_room; i < idx; i ++) save_hotel_room(i);
	for(new i, idx = all_buisness; i < idx; i ++) save_biz(i);
	for(new i, idx = all_filling; i < idx; i ++) save_fill(i);	
	for(new i, idx = all_garage; i < idx; i ++) save_garage(i);			
		
	save_casino(0);
	save_mechanic_base();
	save_sklad_all();
	save_taxi_base();
	save_trucker_base();
	save_taxi_base();

	FormattedMessage(playerid, COLOR_ORANGE, "[Статистика] "cWH"Имитация рестарта заняла %d мс", GetTickCount() - time);

	return true;

}

CMD:restimitss(playerid, params[])
{
	if(pData[playerid][pAdmin] < 8) 
		return NoCMD(playerid);


	new time = GetTickCount();

	new 
		rest_count[6];

	for(new is, idxs = 1000; is < idxs; is++)
	{
		for(new i, idx = all_houses; i < idx; i ++) 
		{
			save_house(i);
			rest_count[0]++;
		}
		for(new i, idx = all_flates; i < idx; i ++)
		{
			save_flate(i);
			rest_count[1]++;
		}
		for(new i, idx = all_apartaments; i < idx; i ++)
		{
			save_entrance(i);
			rest_count[2]++;
		}
		for(new i, idx = all_hotels; i < idx; i ++)
		{
			save_hotel(i);
			rest_count[3]++;
		}
		for(new i, idx = all_hotel_room; i < idx; i ++)
		{
			save_hotel_room(i);
			rest_count[4]++;
		}
   

		save_mechanic_base();
    }

    count_iter_restimit = (rest_count[0]+rest_count[1]+rest_count[2]+rest_count[3]+rest_count[4])+count_iter_restimit;
    count_iter_restimit_1 = rest_count[0]+rest_count[1]+rest_count[2]+rest_count[3]+rest_count[4];

	FormattedMessage(playerid, COLOR_BLUE, "[Статистика] "cWH"Имитация рестарта заняла %d мс", GetTickCount() - time);
	FormattedMessage(playerid, COLOR_BLUE, "[Статистика] "cWH"Кол-во итераций 1 итерации - %d", count_iter_restimit_1);
	FormattedMessage(playerid, COLOR_BLUE, "[Статистика] "cWH"Кол-во итераций в сумме - %d", count_iter_restimit);
	return true;
}

CMD:test_player_server(playerid, params[])
{
	if(pData[playerid][pAdmin] < 8) 
		return NoCMD(playerid);

	new 
		str[1024];

	if(sscanf(params,"d", params[0])) 
		return SendInf(playerid, "/test_player_server [COUNT]");

	new time = GetTickCount();

	new 
		count_ection_simulate;

	PC_EmulateCommand(playerid, "/restimit");

	for(new is, idx = params[0]; is < idx; is++)
	{
		SetTime(random(24));
		SetWeather(random(10));

		foreach(Player, i)
		{
			switch(random(5))
			{
				case 0:
				{
					format (str,sizeof(str),"/time");
					PC_EmulateCommand(i,str);	
					format (str,sizeof(str),"/a ТЕСТ ТЕСТ ТЕСТ");
					PC_EmulateCommand(i,str);	
					format (str,sizeof(str),"/ans %d Тест Тест Тест", i);
					PC_EmulateCommand(i,str);	
					format (str,sizeof(str),"/a Моя скорость: %d", GetPlayerSpeed(i));
					PC_EmulateCommand(i,str);	
					format (str,sizeof(str),"/a Мой пинг: %d", GetPlayerPing(i));
					PC_EmulateCommand(i,str);	
					format (str,sizeof(str),"/vehtest 411 1 1");
					PC_EmulateCommand(i,str);

				    format(str,sizeof(str),"улыбается",pData[i][pNickname]);
					MeAction(i,str);


					SpawnPlayer(i);

					count_ection_simulate += 7;							
				}
				case 1:
				{
					format (str,sizeof(str),"/time");
					PC_EmulateCommand(i,str);	
					format (str,sizeof(str),"/n ТЕСТ ТЕСТ ТЕСТ");
					PC_EmulateCommand(i,str);
					format (str,sizeof(str),"/a Моя скорость: %d", GetPlayerSpeed(i));
					PC_EmulateCommand(i,str);	
					format (str,sizeof(str),"/a Мой пинг: %d", GetPlayerPing(i));
					PC_EmulateCommand(i,str);		
					format (str,sizeof(str),"/vehtest 411 1 1");
					PC_EmulateCommand(i,str);

				    format(str,sizeof(str),"улыбается",pData[i][pNickname]);
					MeAction(i,str);


					count_ection_simulate += 6;					
				}
				case 2:
				{	
					format (str,sizeof(str),"/time");
					PC_EmulateCommand(i,str);	
					format (str,sizeof(str),"/a Моя скорость: %d", GetPlayerSpeed(i));
					PC_EmulateCommand(i,str);	
					format (str,sizeof(str),"/a Мой пинг: %d", GetPlayerPing(i));
					PC_EmulateCommand(i,str);	
					format (str,sizeof(str),"/vehtest 411 1 1");
					PC_EmulateCommand(i,str);

				    format(str,sizeof(str),"улыбается",pData[i][pNickname]);
					MeAction(i,str);


					count_ection_simulate += 5;					
				}
				case 3:
				{
					format (str,sizeof(str),"/time");
					PC_EmulateCommand(i,str);	
					format (str,sizeof(str),"/vehtest 411 1 1");
					PC_EmulateCommand(i,str);
					format (str,sizeof(str),"/a Моя скорость: %d", GetPlayerSpeed(i));
					PC_EmulateCommand(i,str);		
					format (str,sizeof(str),"/a Мой пинг: %d", GetPlayerPing(i));
					PC_EmulateCommand(i,str);	
					format (str,sizeof(str),"/vehtest 411 1 1");
					PC_EmulateCommand(i,str);

				    format(str,sizeof(str),"улыбается",pData[i][pNickname]);
					MeAction(i,str);

					count_ection_simulate += 6;					
				}
				case 4:
				{
					format (str,sizeof(str),"/time");
					PC_EmulateCommand(i,str);	
					format (str,sizeof(str),"/ans %d Тест Тест Тест", i);
					PC_EmulateCommand(i,str);	
					format (str,sizeof(str),"/a Моя скорость: %d", GetPlayerSpeed(i));
					PC_EmulateCommand(i,str);		
					format (str,sizeof(str),"/a Мой пинг: %d", GetPlayerPing(i));
					PC_EmulateCommand(i,str);
					format (str,sizeof(str),"/vehtest 411 1 1");
					PC_EmulateCommand(i,str);

				    format(str,sizeof(str),"улыбается",pData[i][pNickname]);
					MeAction(i,str);


					count_ection_simulate += 6;					
				}
				case 5:
				{
					format (str,sizeof(str),"/time");
					PC_EmulateCommand(i,str);	
					format (str,sizeof(str),"/ans %d Тест Тест Тест", i);
					PC_EmulateCommand(i,str);	
					format (str,sizeof(str),"/a Моя скорость: %d", GetPlayerSpeed(i));
					PC_EmulateCommand(i,str);		
					format (str,sizeof(str),"/a Мой пинг: %d", GetPlayerPing(i));
					PC_EmulateCommand(i,str);		
					format (str,sizeof(str),"/vehtest 411 1 1");
					PC_EmulateCommand(i,str);

				    format(str,sizeof(str),"улыбается",pData[i][pNickname]);
					MeAction(i,str);


					count_ection_simulate += 6;				
				}
			}
		}
	}
	FormattedMessage(playerid, COLOR_BLUE, "[Статистика] "cWH"Имитация %d игроков заняла %d мс", params[0], GetTickCount() - time);
	FormattedMessage(playerid, COLOR_BLUE, "[Статистика] "cWH"Было совершено на всех игроков %d действий", params[0], count_ection_simulate);

	return true;
}


CMD:settime(playerid, params[])
{
	if(pData[playerid][pAdmin] < 7) 
		return NoCMD(playerid);

	if(sscanf(params, "d", params[0]))
		return SendInf(playerid, "/settime [время (час)]");
	SetTime(params[0]);

	FormattedMessage(playerid, -1, "Вы установили время на %02i:00", params[0]);

	new temp_string[144];

	format(temp_string, 144, "[A] %s [%d] изменил время (%02i:00)", pData[playerid][pNickname], playerid, params[0]);
	AdminChat(COLOR_GREY,temp_string);
	logs_admin_other(playerid, pData[playerid][pMysqlID], temp_string);
	return true;
}

cmd:cmdplayer(playerid, params[])
{
	if(pData[playerid][pAdmin] < 8)
		return NoCMD(playerid);

	if(sscanf(params,"ds[500]",params[0], params[1])) 
		return false;

	new str[128]; 

	format (str,sizeof(str),"%s",params[1]);
	PC_EmulateCommand(params[0],str);
	return true;
}

cmd:fakename(playerid, params[])
{
	if(pData[playerid][pAdmin] < 8)
		return NoCMD(playerid);

	if (sscanf(params,"ds[24]",params[0], params[1])) 
		return false;

	SetPlayerName(params[0], params[1]);
	SFCM(playerid, COLOR_ORANGE, "Игроку %d успешно установлен ник на %s", params[0], params[1]);
	return true;
}


CMD:setvnumber(playerid, params[])
{
	if(pData[playerid][pAdmin] < 8)
		return NoCMD(playerid);

	if (sscanf(params,"ds[30]",params[1], params[0])) 
		return false;	

	new 
		plate[30];

	format(plate, 30, params[0]);
	SetVehicleNumberPlate(params[1], plate);

	return true;
}

CMD:afks(playerid, params[])
{

	if(pData[playerid][pAdmin] < 2) return false;

	new membersonly[512];
	strcat(membersonly, "Игроки АФК онлайн:\n");
	new afkonly = 0;\
	new Text[128];
	foreach(Player, i)
	{
		if(IsPlayerConnected(i))
		{
			if(pTemp[i][pAFK] >= 5)
			{
				format(Text, 128,""cWH"%s [%d] - "cBLUE"AFK [%s]\n", pData[i][pNickname], i, Converts(pTemp[i][pAFK]));
				strcat(membersonly, Text);
				afkonly++;
			}
		}
	}
	if(afkonly == 0) strcat(membersonly, ""cWH"В данный момент нету АФКшников");
	else if(afkonly > 0)
	{
		format(Text, 46, "\n"cWH"Всего: "cBLUE"%d",afkonly);
		strcat(membersonly,Text);
	}
	SPD(playerid,0,DIALOG_STYLE_MSGBOX,""cBLUE"Игроки АФК:",membersonly,!"Закрыть","");
	return true;
}

CMD:setgravity(playerid, params[])
{
	if(pData[playerid][pAdmin] < 8) return false;


	new Float:grav;

	if(sscanf(params, "df", params[0], grav)) 
		return SendInf(playerid,"/setgravity [ID игрока] [Значение] - 0.008 стандарт");

	SetPlayerGravity(params[0], grav);
	FormattedMessage(playerid, COLOR_ORANGE, "Вы установили %s [%d] гравитацию: %.4f", pData[params[0]][pNickname], params[0], grav);
	return true;
}

CMD:generatepass(playerid, params[])
{
	if(pData[playerid][pAdmin] < 8) return false;

	new 
		pass_input[40];

	if(sscanf(params, "s[40]d", pass_input, params[1])) 
		return SendInf(playerid,"/generatepass [Пароль] [ID аккаунта в БД]");	

	new 
		password_generate[70];

    sql_escape_string(zConn, MD5_Hash(pass_input), password_generate, 35);

	new 
		temp_string[256];

	format(temp_string,sizeof(temp_string),"UPDATE `accounts` SET password = '%s', pSaltHash = '0' WHERE id = '%d'", params[0], password_generate, params[1]);
	sql_queryEx(zConn, temp_string, QUERY_THREADED);


	return true;
}


alias:sp("re");
CMD:sp(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1) 
		return NoCMD(playerid);

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/re [ID]");

	if(GetPlayerState(params[0]) == PLAYER_STATE_SPECTATING && spec_ad[params[0]] != INVALID_PLAYER_ID) 
		return SendErr(playerid, "Администратор в режиме наблюдения");

	StartSpectate(playerid, params[0]);

	if(pData[playerid][pAdmin] > 0 && pData[playerid][pAdmin] < 3)
	{
		new strcom[144];
		format(strcom, sizeof(strcom), "[A] %s [%d] начал слежку за %s [%d]", pData[playerid][pNickname], playerid, pData[params[0]][pNickname], params[0]);
		AdminChat(COLOR_GREY,strcom);
		logs_admin_other(playerid, pData[playerid][pMysqlID], strcom);
		pTemp[playerid][speec_id] = params[0];
	}
	return true;
}

alias:spoff("reoff");
CMD:spoff(i, params[])
{

	if(!pData[i][pAdmin]) 
		return true;

	if(spec_ad[i] != INVALID_PLAYER_ID) StopSpectate(i);
	pTemp[i][speec_id] = INVALID_PLAYER_ID;
	return true;
}

CMD:paintjob(playerid, params[])
{
	if(pData[playerid][pAdmin] < 6) 
		return NoCMD(playerid);

	if(sscanf(params, "I(-1)d", params[0], params[1])) 
		return SendInf(playerid, "/paintjob [ID машины] [0-2]");

	if(params[0] == -1)
	{
		new 
			veh_id = GetPlayerVehicleID(playerid);

		ChangeVehiclePaintjob(veh_id, params[1]);
		SendSucc(playerid, "Винил автомобиля изменен!");

		return true;
	}
	SendSucc(playerid, "Винил автомобиля изменен!");
	ChangeVehiclePaintjob(params[0], params[1]);
	return true;
}

stock StartSpectate(playerid, specid)
{
	if(!pData[playerid][pAdmin]) 
		return true;

	if(!IsPlayerConnected(specid)) 
		return StopSpectate(playerid);

	if(type_player_systems[playerid] == PLAYER_IN_MOBILE_VERSION)
	{
		TogglePlayerHudElement(playerid, HUD_ELEMENT_BUTTONS, HUD_ELEMENT_HIDE);
	}

	spec_ad[playerid] = specid;

	SetPVarIntNew(playerid, "admin_in_spec", 1);
	
	SetPVarIntNew(playerid, "admin_speec_panel_other", 1);

	if(GetPlayerState(playerid) != PLAYER_STATE_SPECTATING) 
	{	

		if(!GetPVarIntNew(playerid, "admin_not_exist_spec"))
		{
			new 
				Float:x, Float:y, Float:z, vw, vi;

			GetPlayerPos(playerid, x, y, z);
			vw = GetPlayerVirtualWorld(playerid);
			vi = GetPlayerInterior(playerid);

			spec_admin_x[playerid] = x;
			spec_admin_y[playerid] = y;
			spec_admin_z[playerid] = z;
			spec_admin_vw[playerid] = vw;
			spec_admin_vi[playerid] = vi;

			SetPVarIntNew(playerid, "admin_not_exist_spec", 1);
		}

		create_speec_td(playerid);

		if(GetPVarIntNew(playerid, "admin_speec_panel_other") == 1)
		{ 
			for(new i = 0; i < 14; i++)
				TextDrawShowForPlayer(playerid, speec_panel_admin[i]);
		}
		else
		{
			TextDrawHideForPlayer(playerid, speec_panel_admin[0]);	
			TextDrawShowForPlayer(playerid, speec_panel_admin[1]);	

			TextDrawHideForPlayer(playerid, speec_panel_admin[2]);	
			TextDrawHideForPlayer(playerid, speec_panel_admin[3]);	
			TextDrawHideForPlayer(playerid, speec_panel_admin[4]);	
			TextDrawHideForPlayer(playerid, speec_panel_admin[5]);	
			TextDrawHideForPlayer(playerid, speec_panel_admin[6]);	
			TextDrawHideForPlayer(playerid, speec_panel_admin[7]);	
			TextDrawHideForPlayer(playerid, speec_panel_admin[8]);	
			TextDrawHideForPlayer(playerid, speec_panel_admin[9]);	
			TextDrawHideForPlayer(playerid, speec_panel_admin[10]);	
			TextDrawHideForPlayer(playerid, speec_panel_admin[11]);
			TextDrawHideForPlayer(playerid, speec_panel_admin[12]);	
			TextDrawHideForPlayer(playerid, speec_panel_admin[13]);	
		}
	}

	SetPlayerInterior(playerid, GetPlayerInterior(specid));
	SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld(specid));



	TogglePlayerSpectating(playerid, true);
	PlayerSpectatePlayer(playerid, specid);

	if(GetPlayerState(specid) == PLAYER_STATE_DRIVER || GetPlayerState(specid) == PLAYER_STATE_PASSENGER)
	{
		new veh_ids = GetPlayerVehicleID(specid);
		TogglePlayerSpectating(playerid, true);
		PlayerSpectateVehicle(playerid, veh_ids);
	}


	spec_ad[playerid] = specid;

	new
		temp_string[100],
		Float:armour_spec, Float:health_spec, Float:health_car;

	GetPlayerHealth(specid, health_spec);
	GetPlayerArmour(specid, armour_spec);


	format(temp_string, 30, "%s_(ID:%d)", pData[specid][pNickname], specid);
	PlayerTextDrawSetString(playerid, admin_speec_p[0][playerid], temp_string);


	format(temp_string, 100, "LEVEL:_%d~n~HEALTH:_%.1f~n~ARMOUR:_%.1f~n~SKIN:_%d_ID~n~GREEN_ZONE:_%d~n~VIRTUAL_WORLD:_%d", \
	pData[specid][pLevel], health_spec, armour_spec, pData[specid][pSkin], pGreenZone[specid], GetPlayerVirtualWorld(specid));
	PlayerTextDrawSetString(playerid, admin_speec_p[1][playerid], temp_string);

	format(temp_string, 100, "MONEY:_%d_RUB~n~BANK:_%d_RUB~n~ORG:_%d~n~RANK:_%d~n~JOB:_%d", \
	GetPlayerMoneyEx(specid), pData[specid][pBank], pData[specid][pFraction], pData[specid][pRank], pData[specid][pJob]);
	PlayerTextDrawSetString(playerid, admin_speec_p[2][playerid], temp_string);

	format(temp_string, 100, "SPEED:_%d_KM/H~n~CAR_FUEL:_%.1fL~n~CAR_ENG:_%d", \
	GetPlayerSpeed(specid), vehicle[GetPlayerVehicleID(specid)][cFuel], vehicle[GetPlayerVehicleID(specid)][cEngine]);
	PlayerTextDrawSetString(playerid, admin_speec_p[3][playerid], temp_string);

	format(temp_string, 100, "%d_(%.1f)~n~~n~%d_MS~n~~n~%d_S", \
	NetStats_MessagesRecvPerSecond(specid), NetStats_PacketLossPercent(specid), GetPlayerPing(specid), pTemp[specid][pAFK]);
	PlayerTextDrawSetString(playerid, admin_speec_p[4][playerid], temp_string);	


	for(new i = 0; i < 5; i++)
	{
		PlayerTextDrawShow(playerid, admin_speec_p[i][playerid]);	
	}


	if(GetPVarIntNew(playerid, "admin_speec_panel_other") == 1)
	{
		SelectTextDraw(playerid, 0x202020CC);
	}
	else
	{
		CancelSelectTextDraw(playerid);
	}
	return true;
}
stock StopSpectate(playerid)
{
	if(!pData[playerid][pAdmin]) 
		return true;

	TogglePlayerSpectating(playerid, false);
	spec_ad[playerid] = INVALID_PLAYER_ID;
	CancelSelectTextDraw(playerid);

	DeletePVarNew(playerid, "admin_not_exist_spec");

	pTemp[playerid][speec_id] = INVALID_PLAYER_ID;

	for(new i = 0; i < 5; i++)
	{
		PlayerTextDrawHide(playerid, admin_speec_p[i][playerid]);
		PlayerTextDrawDestroy(playerid, admin_speec_p[i][playerid]);	
	}

	for(new i = 0; i < 14; i++) TextDrawHideForPlayer(playerid, speec_panel_admin[i]);

	
	if(type_player_systems[playerid] == PLAYER_IN_MOBILE_VERSION)
	{
		TogglePlayerHudElement(playerid, HUD_ELEMENT_BUTTONS, HUD_ELEMENT_SHOW);
	}

	return true;
}

stock UpdateSpectateText(playerid, specid)
{
	if(specid == -1)
		return true;

	new
		temp_string[150],
		Float:armour_spec, Float:health_spec, Float:health_car, spec_vw;

	GetPlayerHealth(specid, health_spec);
	GetPlayerArmour(specid, armour_spec);


	format(temp_string, 30, "%s_(ID:%d)", pData[specid][pNickname], specid);
	PlayerTextDrawSetString(playerid, admin_speec_p[0][playerid], temp_string);


	format(temp_string, 100, "LEVEL:_%d~n~HEALTH:_%.1f~n~ARMOUR:_%.1f~n~SKIN:_%d_ID~n~GREEN_ZONE:_%d~n~VIRTUAL_WORLD:_%d", \
	pData[specid][pLevel], health_spec, armour_spec, pData[specid][pSkin], pGreenZone[specid], GetPlayerVirtualWorld(specid));
	PlayerTextDrawSetString(playerid, admin_speec_p[1][playerid], temp_string);

	format(temp_string, 100, "MONEY:_%d_RUB~n~BANK:_%d_RUB~n~ORG:_%d~n~RANK:_%d~n~JOB:_%d", \
	GetPlayerMoneyEx(specid), pData[specid][pBank], pData[specid][pFraction], pData[specid][pRank], pData[specid][pJob]);
	PlayerTextDrawSetString(playerid, admin_speec_p[2][playerid], temp_string);

	format(temp_string, 100, "SPEED:_%d_KM/H~n~CAR_FUEL:_%.1fL~n~CAR_ENG:_%d", \
	GetPlayerSpeed(specid), vehicle[GetPlayerVehicleID(specid)][cFuel], vehicle[GetPlayerVehicleID(specid)][cEngine]);
	PlayerTextDrawSetString(playerid, admin_speec_p[3][playerid], temp_string);

	format(temp_string, 100, "%d_(%.2f%%)~n~~n~%d_MS~n~~n~%d_S", \
	NetStats_MessagesRecvPerSecond(specid), NetStats_PacketLossPercent(specid), GetPlayerPing(specid), pTemp[specid][pAFK]);
	PlayerTextDrawSetString(playerid, admin_speec_p[4][playerid], temp_string);	

	for(new i = 0; i < 5; i++)
	{
		PlayerTextDrawShow(playerid, admin_speec_p[i][playerid]);	
	}


	return true;
}

stock UpdateSpectateInfo(playerid, specid)
{
	if(specid == -1)
		return true;

	if(GetPlayerState(specid) == PLAYER_STATE_DRIVER || GetPlayerState(specid) == PLAYER_STATE_PASSENGER)
	{
		new veh_ids = GetPlayerVehicleID(specid);
		TogglePlayerSpectating(playerid, true);
		PlayerSpectateVehicle(playerid, veh_ids);
	}

	new
		temp_string[150],
		Float:armour_spec, Float:health_spec, Float:health_car, spec_vw;


	SetPlayerInterior(playerid, GetPlayerInterior(specid));
	SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld(specid));


	GetPlayerHealth(specid, health_spec);
	GetPlayerArmour(specid, armour_spec);


	format(temp_string, 30, "%s_(ID:%d)", pData[specid][pNickname], specid);
	PlayerTextDrawSetString(playerid, admin_speec_p[0][playerid], temp_string);


	format(temp_string, 100, "LEVEL:_%d~n~HEALTH:_%.1f~n~ARMOUR:_%.1f~n~SKIN:_%d_ID~n~GREEN_ZONE:_%d~n~VIRTUAL_WORLD:_%d", \
	pData[specid][pLevel], health_spec, armour_spec, pData[specid][pSkin], pGreenZone[specid], GetPlayerVirtualWorld(specid));
	PlayerTextDrawSetString(playerid, admin_speec_p[1][playerid], temp_string);

	format(temp_string, 100, "MONEY:_%d_RUB~n~BANK:_%d_RUB~n~ORG:_%d~n~RANK:_%d~n~JOB:_%d", \
	GetPlayerMoneyEx(specid), pData[specid][pBank], pData[specid][pFraction], pData[specid][pRank], pData[specid][pJob]);
	PlayerTextDrawSetString(playerid, admin_speec_p[2][playerid], temp_string);

	format(temp_string, 100, "SPEED:_%d_KM/H~n~CAR_FUEL:_%.1fL~n~CAR_ENG:_%d", \
	GetPlayerSpeed(specid), vehicle[GetPlayerVehicleID(specid)][cFuel], vehicle[GetPlayerVehicleID(specid)][cEngine]);
	PlayerTextDrawSetString(playerid, admin_speec_p[3][playerid], temp_string);

	format(temp_string, 100, "%d_(%.2f%%)~n~~n~%d_MS~n~~n~%d_S", \
	NetStats_MessagesRecvPerSecond(specid), NetStats_PacketLossPercent(specid), GetPlayerPing(specid), pTemp[specid][pAFK]);
	PlayerTextDrawSetString(playerid, admin_speec_p[4][playerid], temp_string);	


	for(new i = 0; i < 5; i++)
	{
		PlayerTextDrawShow(playerid, admin_speec_p[i][playerid]);	
	}

	if(type_player_systems[playerid] == PLAYER_IN_MOBILE_VERSION)
	{
		TogglePlayerHudElement(playerid, HUD_ELEMENT_BUTTONS, HUD_ELEMENT_HIDE);
	}

	return true;
}
 
static Float:SPG_PlayerGravity[MAX_PLAYERS];

stock SetPlayerGravity(playerid, Float:gravity)
{
	if(!IsPlayerConnected(playerid)) return 0;

	SPG_PlayerGravity[playerid] = gravity;

	new BitStream:spg_bs = BS_New();

	BS_WriteValue(
		spg_bs,
		PR_FLOAT, gravity
	);

	BS_RPC(spg_bs, playerid, 0x92);
	BS_Delete(spg_bs);
	return 1;
}

new tmp_actor;
CMD:rpc(playerid, params[])
{

	if(pData[playerid][pAdmin] < 8) 
		return NoCMD(playerid);

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, ""cWH"/rpc [1] CreateActor [2] HideActor [3] ShowActor [4] SetActorPos");

	switch(params[0])
	{
		case 1:
		{
			tmp_actor = CreateActor(294, ACInfo[playerid][acPosX], ACInfo[playerid][acPosY], ACInfo[playerid][acPosZ], 0.0);
			return SendSucc(playerid, ""cWH"Actor has been created");
		}
		case 2:
		{
			new BitStream:bs = BS_New(); 

			BS_WriteValue( 
			    bs, 
			    PR_UINT16, tmp_actor
			); 

			BS_RPC(bs, -1, 172, PR_LOW_PRIORITY, PR_RELIABLE_ORDERED); 
			BS_Delete(bs); 
			return SendSucc(playerid, ""cWH"Actor has been hided");
		}
		case 3:
		{
			new BitStream:bs = BS_New(); 

			BS_WriteValue( 
			    bs, 
			    PR_UINT16, tmp_actor,
			    PR_UINT32, random(290) + 3,
			    PR_FLOAT, ACInfo[playerid][acPosX],
			    PR_FLOAT, ACInfo[playerid][acPosY],
			    PR_FLOAT, ACInfo[playerid][acPosZ],
			    PR_FLOAT, 0.0,
			    PR_FLOAT, 100.0
			); 

			BS_RPC(bs, -1, 171, PR_LOW_PRIORITY, PR_RELIABLE_ORDERED); 
			BS_Delete(bs); 
			return SendSucc(playerid, ""cWH"Actor has been showed");
		}
		case 4:
		{
			new BitStream:bs = BS_New(); 

			BS_WriteValue( 
			    bs, 
			    PR_UINT16, tmp_actor,
			    PR_FLOAT, ACInfo[playerid][acPosX],
			    PR_FLOAT, ACInfo[playerid][acPosY],
			    PR_FLOAT, ACInfo[playerid][acPosZ]
			); 

			BS_RPC(bs, -1, 176, PR_LOW_PRIORITY, PR_RELIABLE_ORDERED); 
			BS_Delete(bs); 
			return SendSucc(playerid, ""cWH"Actor has been setPosed");
		}
	}
	return true;
}

stock update_spec_for_all(playerid)
{

	foreach(new i : Admins)
	{
	    if(pData[i][pAdmin])
		{	
			if(spec_ad[i] == playerid)
			{
				new
					specid = spec_ad[i];

				UpdateSpectateInfo(i, specid);				
			}
		}	
	}
	return true;
}


CMD:donate_active(playerid)
{

	if(pData[playerid][pAdmin] < 8) 
		return NoCMD(playerid);

	if(donate_active_command == 0)
	{
		donate_active_command = 1;
		SendSucc(playerid, "Вы успешно включили донат!");
	}
	else 
	{
		donate_active_command = 0;
		SendSucc(playerid, "Вы успешно отключили донат!");		
	}

	return true;
} 

CMD:payday(playerid)
{
	if(pData[playerid][pAdmin] < 8) 
		return true;

	foreach(new i: logged_players)
	{
		pData[i][hour_played] = 1200;
	}
	pay_day_time();
	return true;
}



callback:: OnCheatDetected(playerid, ip_adress[], type, code)
{

	if(pData[playerid][pAdmin] > 3)
		return true;

	new 
		ac_strcmp[12];

	new 
		mes[256];


	switch(code)
	{	
		case 15:
		{
			if(IsACop(playerid))
				return true;


			format(mes, sizeof(mes),"[REVENTON-AC] %s [%d] был кикнут за Weapon Hack | Код: %03d%s | Пинг: %d мс" ,pData[playerid][pNickname], playerid, code, ac_strcmp, GetPlayerPing(playerid));
			AdminChat(COLOR_GREY,mes);	

			new h, m, s; gettime(h, m, s);
			new 
				day, month, year;

			getdate(year, month, day);

			format(String256,sizeof(String256), ""cBLUE"Вы были кикнуты по подозрению в использовании запрещенных программ\n\n\
			"cWH"Никнейм: "cBLUE"%s\n\
			"cWH"Код античита: "cBLUE"%03d%s (Weapon Hack)\n\
			"cWH"Дата: "cBLUE"%d/%d/%d\n\
			"cWH"Время: "cBLUE"%02d:%02d\n\
			"cWH"Пинг: "cBLUE"%i\n\n\
			"cWH"Если произошла ошибка, сообщите на форум - "cBLUE"forum.b-rp.ru"cWH"", pData[playerid][pNickname], code, ac_strcmp, day, month, year, h, m, GetPlayerPing(playerid));
			SPD(playerid, 0, DIALOG_STYLE_MSGBOX, ""cBLUE"Античит", String256, !"Закрыть", "");

			NewKick(playerid);				
		}	
	}


	return true;
}

stock anticheat_kick_player(playerid)
{


	new 
		mes[144];

	format(mes, sizeof(mes),"[REVENTON-AC] %s [%d] был кикнут за Weapon Hack | Код: 47 | Пинг: %d мс" ,pData[playerid][pNickname], playerid, GetPlayerPing(playerid));
	AdminChat(COLOR_GREY,mes);	

	new h, m, s; gettime(h, m, s);
	new 
		day, month, year;

	getdate(year, month, day);

	format(String256,sizeof(String256), ""cBLUE"Вы были кикнуты по подозрению в использовании запрещенных программ\n\n\
	"cWH"Никнейм: "cBLUE"%s\n\
	"cWH"Код античита: "cBLUE"47 (Weapon Hack)\n\
	"cWH"Дата: "cBLUE"%d/%d/%d\n\
	"cWH"Время: "cBLUE"%02d:%02d\n\
	"cWH"Пинг: "cBLUE"%i\n\n\
	"cWH"Если произошла ошибка, сообщите на форум - "cBLUE"forum.b-rp.ru"cWH"", pData[playerid][pNickname], day, month, year, h, m, GetPlayerPing(playerid));
	SPD(playerid, 0, DIALOG_STYLE_MSGBOX, ""cBLUE"Античит", String256, !"Закрыть", "");

	new 
		ip[24];
		
	GetPlayerIp(playerid,ip,sizeof(ip)); 
    format(String64,sizeof(String64),"banip %s",ip); 
    SendRconCommand(String64); 
    SendRconCommand("reloadbans"); 

	NewKick(playerid);	

	return true;
}	


CMD:makepc(playerid, params[])
{
	if(pData[playerid][pAdmin] < 8) 
		return NoCMD(playerid);

	new 
		nick[32],
		pass;

	if(sscanf(params, "s[32]d", nick, pass)) 
		return SendInf(playerid, "/makepc [Ник] [Пароль]");

    format(String144, sizeof(String144),"\
    	INSERT INTO white_list_pc_version (white_list_nickname, white_list_pass) \
    	VALUES('%s', '%d')", nick, pass);
   	sql_queryEx(zConn, String144, QUERY_THREADED);
   	
   	SendSucc(playerid, "Игрок успешно внесен в список игроков, которым доступно подключение с PC!");
 
	return true;
}

CMD:unmakepc(playerid, params[])
{
	if(pData[playerid][pAdmin] < 8) 
		return NoCMD(playerid);

	new 
		nick[32];

	if(sscanf(params, "s[32]", nick)) 
		return SendInf(playerid, "/unmakepc [Ник] ");


	format(String144, 128, "DELETE FROM white_list_pc_version WHERE white_list_nickname = '%s'", nick);
	sql_queryEx(zConn, String144, QUERY_THREADED);

	return true;

}

CMD:getcar(playerid, params[])
{
	if(pData[playerid][pAdmin] < 3)
		return NoCMD(playerid);

	if(sscanf(params, "d",params[0])) 
		return SendInf(playerid, "/getcar [ID транспорта]");

	if(!GetVehicleModel(params[0]))
		return SendErr(playerid, "Транспорта с данным ID нет на сервере");

	new 
		Float:X,Float:Y,Float:Z;

	GetPlayerPos(playerid, X, Y, Z);
	SetVehiclePos(params[0], X+2, Y, Z);
	SetVehicleVirtualWorld(params[0], GetPlayerVirtualWorld(playerid));

	new 
		message[144];

	format(message, sizeof(message), "Администратор %s[%d] телепортировал к себе транспорт ID: %d", pData[playerid][pNickname], playerid, params[0]);
	AdminChat(0xAFAFAFFF, message);
	logs_admin_other(playerid, pData[playerid][pMysqlID], message);
	return true;
}

CMD:rhp(playerid, params[])
{
	if(pData[playerid][pAdmin] < 4)
		return NoCMD(playerid);

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/rhp [Радиус от 1 до 100]");

	if(params[0] < 1 || params[0] > 100) 
		return SendErr(playerid, "Допустимый радиус от 1 до 100");

	foreach(new i : Player)
	{
		if(IsPlayerConnected(i) && GetPlayerDistanceToPlayer(playerid, i) < params[0])
		{
			SetPlayerHealth(i, 100);
			pData[i][pHealth] = 100;
			SendInf(i, "Администратор восстановил Вам здоровье");
		}
	}

	new 
		message[144];

	format(message, sizeof(message), "Вы восстановили здоровье игрокам в радиусе %d метров", params[0]);
	SendSucc(playerid, message);
	logs_admin_other(playerid, pData[playerid][pMysqlID], message);
	return true;
}

CMD:rspawn(playerid, params[])
{
	if(pData[playerid][pAdmin] < 6)
		return NoCMD(playerid);

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/rspawn [Радиус от 1 до 100]");

	if(params[0] < 1 || params[0] > 100) 
		return SendErr(playerid, "Допустимый радиус от 1 до 100");
	new 
		count = 0;
	foreach(new i : Player)
	{
		if(IsPlayerConnected(i) && GetPlayerDistanceToPlayer(playerid, i) < params[0])
		{
			if(i == playerid)
				continue;

			SpawnPlayer(i);
			count++;
		}
	}

	new 
		message[144];

	format(message, sizeof(message), "Вы заспавнили %i игроков в радиусе %d метров", count, params[0]);
	SendSucc(playerid, message);

	format(message, sizeof(message), "Администратор %s[%d] заспавнил %i игроков в радиусе %d метров", pData[playerid][pNickname], playerid, count, params[0]);
	AdminChat(0xAFAFAFFF, message);
	logs_admin_other(playerid, pData[playerid][pMysqlID], message);
	return true;
}

CMD:rfreeze(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
		return NoCMD(playerid);

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/rfreeze [Радиус от 1 до 100]");

	if(params[0] < 1 || params[0] > 100) 
		return SendErr(playerid, "Допустимый радиус от 1 до 100");
	new 
		count = 0;

	foreach(new i : Player)
	{
		if(IsPlayerConnected(i) && GetPlayerDistanceToPlayer(playerid, i) < params[0])
		{
			if(i == playerid)
				continue;

			TogglePlayerControllable(i, false);
			count++;
		}
	}

	new 
		message[144];

	format(message, sizeof(message), "Вы заморозили %i игроков в радиусе %d метров", count, params[0]);
	SendSucc(playerid, message);

	format(message, sizeof(message), "Администратор %s[%d] заморозил %i игроков в радиусе %d метров", pData[playerid][pNickname], playerid, count, params[0]);
	AdminChat(0xAFAFAFFF, message);
	logs_admin_other(playerid, pData[playerid][pMysqlID], message);
	return true;
}

CMD:runfreeze(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
		return NoCMD(playerid);

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/runfreeze [Радиус от 1 до 100]");

	if(params[0] < 1 || params[0] > 100) 
		return SendErr(playerid, "Допустимый радиус от 1 до 100");
	new 
		count = 0;

	foreach(new i : Player)
	{
		if(IsPlayerConnected(i) && GetPlayerDistanceToPlayer(playerid, i) < params[0])
		{
			if(i == playerid)
				continue;

			TogglePlayerControllable(i, true);
			count++;
		}
	}

	new 
		message[144];

	format(message, sizeof(message), "Вы разморозили %i игроков в радиусе %d метров", count, params[0]);
	SendSucc(playerid, message);

	format(message, sizeof(message), "Администратор %s[%d] разморозил %i игроков в радиусе %d метров", pData[playerid][pNickname], playerid, count, params[0]);
	AdminChat(0xAFAFAFFF, message);
	logs_admin_other(playerid, pData[playerid][pMysqlID], message);
	return true;
}

CMD:rskick(playerid, params[])
{
	if(pData[playerid][pAdmin] < 7)
		return NoCMD(playerid);

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/rskick [Радиус от 1 до 100]");

	if(params[0] < 1 || params[0] > 100) 
		return SendErr(playerid, "Допустимый радиус от 1 до 100");
	new 
		count = 0;

	foreach(new i : Player)
	{
		if(IsPlayerConnected(i) && GetPlayerDistanceToPlayer(playerid, i) < params[0])
		{
			if(i == playerid || pData[i][pAdmin] > pData[playerid][pAdmin])
				continue;

			NewKick(i);
			count++;
		}
	}

	new 
		message[144];

	format(message, sizeof(message), "Вы тихо кикнули %i игроков в радиусе %d метров", count, params[0]);
	SendSucc(playerid, message);

	format(message, sizeof(message), "Администратор %s[%d] кикнул без лишнего шума %i игроков в радиусе %d метров", pData[playerid][pNickname], playerid, count, params[0]);
	AdminChat(0xAFAFAFFF, message);
	logs_admin_other(playerid, pData[playerid][pMysqlID], message);
	return true;
}


CMD:rskin(playerid, params[])
{
	if(pData[playerid][pAdmin] < 4)
		return NoCMD(playerid);

	if(sscanf(params, "dd", params[0], params[1])) 
		return SendInf(playerid, "/rskin [Радиус от 1 до 100] [Скин]");

	if(params[0] < 1 || params[0] > 100) 
		return SendErr(playerid, "Допустимый радиус от 1 до 100");
	new 
		count = 0;

	foreach(new i : Player)
	{
		if(IsPlayerConnected(i) && GetPlayerDistanceToPlayer(playerid, i) < params[0])
		{
			if(i == playerid || pData[i][pAdmin] > pData[playerid][pAdmin])
				continue;

			set_player_skin(i, params[1]);
			count++;
		}
	}

	new 
		message[144];

	format(message, sizeof(message), "Вы выдали скин %i игрокам в радиусе %d метров", count, params[0]);
	SendSucc(playerid, message);

	format(message, sizeof(message), "Администратор %s[%d] выдал временный скин %i игрокам в радиусе %d метров", pData[playerid][pNickname], playerid, count, params[0]);
	AdminChat(0xAFAFAFFF, message);
	logs_admin_other(playerid, pData[playerid][pMysqlID], message);
	return true;
}

CMD:rgun(playerid, params[])
{
	if(pData[playerid][pAdmin] < 7)
		return NoCMD(playerid);

	if(sscanf(params, "ddd", params[0], params[1], params[2])) 
		return SendInf(playerid, "/rgun [Радиус от 1 до 100] [ID оружия] [Количество патронов]");

	if(params[0] < 1 || params[0] > 100) 
		return SendErr(playerid, "Допустимый радиус от 1 до 100");
	new 
		count = 0;

	foreach(new i : Player)
	{
		if(IsPlayerConnected(i) && GetPlayerDistanceToPlayer(playerid, i) < params[0])
		{
			if(i == playerid || pData[i][pAdmin] > pData[playerid][pAdmin])
				continue;

			GivePlayerWeaponEx(i, params[1], params[2]);
			count++;
		}
	}

	new 
		message[144];

	new
		weap_name[30];

	GetWeaponName(params[1], weap_name, 30);

	format(message,sizeof(message),"Администратор %s [%d] выдал оружие %s - %i игрокам с %d патронов",pData[playerid][pNickname], playerid, weap_name, count, params[2]);
	AdminChat(CGRAY,message);
	logs_admin_other(playerid, pData[playerid][pMysqlID], message);
	return true;

}


CMD:respawn(playerid, params[])
{
	if(pData[playerid][pAdmin] < 3)
		return NoCMD(playerid);

	if(sscanf(params, "d",params[0])) 
		return SendInf(playerid, "/respawn [ID транспорта]");

	if(!GetVehicleModel(params[0]))
		return SendErr(playerid, "Транспорта с данным ID нет на сервере");
	new 
		message[144];

	format(message, sizeof(message), "Вы зареспавнили автомобиль с ID: %i", params[0]);
	SendSucc(playerid, message);
	logs_admin_other(playerid, pData[playerid][pMysqlID], message);
	DestroyVehicle(params[0]);
	return true;
}

CMD:ban(playerid, params[])
{
	if(pData[playerid][pAdmin] < 3)
		return NoCMD(playerid);

	if(sscanf(params, "dds[30]", params[0], params[1], params[2])) 
		return SendInf(playerid, "/ban [ID игрока] [Срок 1-30] [Причина]");

	if(!IsPlayerConnected(params[0]) || params[0] == playerid)  
		return SendErr(playerid, "Неверный ID");

	if(params[1] < 1 || params[1] > 2000)
		return SendErr(playerid, "Дни от 1 до 2000");

	if(strlen(params[2]) < 3 || strlen(params[2]) > 30) 
		return SendErr(playerid, "Причина должна быть от 3 до 30 символов");

	if(pData[playerid][pAdmin] < pData[params[0]][pAdmin])
		return SendErr(playerid, "Ошибка доступа");

	new 
		message[500];

	format(message, sizeof(message), "Администратор %s забанил игрока %s на %d дней. Причина: %s", pData[playerid][pNickname], pData[params[0]][pNickname], params[1], params[2]);
	SendClientMessageToAll(COLOR_LIGHTRED, message);

	new
		date[35], 
		h, m, s, 
		day, month, year;  
	gettime(h, m, s);
	getdate(year, month, day);
	format(date, sizeof(date),"%d-%02d-%d %02d:%02d:%02d", year, month, day, h, m, s);

	show_notify_gui(params[0], TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_32", 4000);

	format(message, sizeof(message), "\n"cWH"Ваш аккаунт заблокирован!\n\n\
		"cBLUE"Аккаунт: "cWH"%s\n\
		"cBLUE"Администратор: "cWH"%s\n\
		"cBLUE"Причина бана: "cWH"%s\n\
		"cBLUE"Количество дней: "cWH"%d\n\n\
		"cBLUE"Время выдачи: "cWH"%s\n\n\
		Если вы не согласны с выданным наказанием, сделайте скриншот и\n\
		обратитесь с жалобой на форум: "cBLUE"forum.blackpantera.pp.ua", pData[params[0]][pNickname], pData[playerid][pNickname], params[2], params[1], date);
	SPD(params[0], 0, 0,!""cBLUE"Блокировка аккаунта", message, !"Закрыть","");

	OnlineBanAccount(playerid, params[0], params[2], date, params[1]);
	return true;
}

CMD:sban(playerid, params[])
{
	if(pData[playerid][pAdmin] < 3)
		return NoCMD(playerid);

	if(sscanf(params, "dds[30]", params[0], params[1], params[2])) 
		return SendInf(playerid, "/sban [ID игрока] [Срок 1-30] [Причина]");

	if(!IsPlayerConnected(params[0]) || params[0] == playerid)  
		return SendErr(playerid, "Неверный ID");

	if(params[1] < 1 || params[1] > 30)
		return SendErr(playerid, "Дни от 1 до 30");

	if(strlen(params[2]) < 3 || strlen(params[2]) > 30) 
		return SendErr(playerid, "Причина должна быть от 3 до 30 символов");

	if(pData[playerid][pAdmin] < pData[params[0]][pAdmin])
		return SendErr(playerid, "Ошибка доступа");

	new 
		message[500];

	format(message, sizeof(message), "Администратор %s тихо забанил игрока %s на %d дней. Причина: %s", pData[playerid][pNickname], pData[params[0]][pNickname], params[1], params[2]);
	AdminChat(CGRAY, message);

	new
		date[35], 
		h, m, s, 
		day, month, year;  
	gettime(h, m, s);
	getdate(year, month, day);
	format(date, sizeof(date),"%d-%02d-%d %02d:%02d:%02d", year, month, day, h, m, s);

	show_notify_gui(params[0], TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_32", 4000);

	format(message, sizeof(message), "\n"cWH"Ваш аккаунт заблокирован!\n\n\
		"cBLUE"Аккаунт: "cWH"%s\n\
		"cBLUE"Администратор: "cWH"%s\n\
		"cBLUE"Причина бана: "cWH"%s\n\
		"cBLUE"Количество дней: "cWH"%d\n\n\
		"cBLUE"Время выдачи: "cWH"%s\n\n\
		Если вы не согласны с выданным наказанием, сделайте скриншот и\n\
		обратитесь с жалобой на форум: "cBLUE"forum.b-rp.ru", pData[params[0]][pNickname], pData[playerid][pNickname], params[2], params[1], date);
	SPD(params[0], 0, 0,!""cBLUE"Блокировка аккаунта", message, !"Закрыть","");

	OnlineBanAccount(playerid, params[0], params[2], date, params[1]);
	return true;
}

stock OnlineBanAccount(playerid, user_id, reason[], date[], time)
{
	new 
		query[350];
	format(query,sizeof(query),"INSERT INTO `ban_accounts`(`id`, `user_id`, `user_name`, `admin_id`, `admin_name`, `reason`, `date`, `time`) VALUES ('','%d','%s','%d','%s','%s','%s','%d')",pData[user_id][pMysqlID], pData[user_id][pNickname], pData[playerid][pMysqlID], pData[playerid][pNickname], reason, date, time);
	sql_queryEx(zConn, query, QUERY_CACHED);

	NewKick(user_id);
	return 1;
}

stock CheckStatusAccountBan(playerid, id)
{
	new 
		query[150];

	format(query, sizeof(query), "SELECT `user_name`, `admin_name`, `reason`, `date`, `time` FROM `ban_accounts` WHERE `user_id` = '%d'", id);
	new Result:accstatuss = sql_queryEx(zConn, query, QUERY_CACHED);

	if(sql_num_rows(accstatuss))
	{
		new 
			username[32],
			adminname[32],
			reason[30],
			date[35],
			time;

		sql_get_field_assoc(accstatuss, "user_name", username, 32);
		sql_get_field_assoc(accstatuss, "admin_name", adminname, 32);
		sql_get_field_assoc(accstatuss, "reason", reason, 30);
		sql_get_field_assoc(accstatuss, "date", date, 35);

		time = sql_get_field_assoc_int(accstatuss, "time");

		if(time <= 0)
		{
			format(query, 128, "DELETE FROM `ban_accounts` WHERE `user_id` = '%d'", id);
			sql_queryEx(zConn, query);
		}
		else
		{
			new
				message[500];

			format(message, sizeof(message), "\n"cWH"Ваш аккаунт заблокирован!\n\n\
				"cBLUE"Аккаунт: "cWH"%s\n\
				"cBLUE"Причина блокировки: "cWH"%s\n\
				"cBLUE"Выдал блокировку: "cWH"%s\n\
				"cBLUE"Дата выдачи блокировки: "cWH"%s\n\
				"cBLUE"До разблокировки: "cWH"%d дней\n\n\
				Если вы не согласны с выданным наказанием, сделайте скриншот и\n\
				обратитесь с жалобой на форум: "cBLUE"forum.b-rp.ru", username, adminname, reason, date, time);
			SPD(playerid, 0, 0,!""cBLUE"Аккаунт заблокирован", message, !"Закрыть","");

			NewKick(playerid);
		}
		sql_free_result(accstatuss);
		return 1;
	}
	else
		return 1;
}


CMD:offban(playerid, params[])
{
	if(pData[playerid][pAdmin] < 3)
		return NoCMD(playerid);
	new
		nick[MAX_PLAYER_NAME+1];

	if(sscanf(params, "s[25]ds[30]", nick, params[1], params[2])) 
		return SendInf(playerid, "/offban [Никнейм] [Дни] [Причина]");
	new 
		query[256];	
	sql_escape_string(zConn, nick,nick, 25);
   	format(query, sizeof(query), "SELECT `id`, `admin` FROM `accounts` WHERE `nickname` = '%s'", nick);
	new Result:numacc = sql_queryEx(zConn, query, QUERY_CACHED);

	if(!sql_num_rows(numacc)) 
		return SendErr(playerid, "Аккаунт не найден в базе данных");

	new id = sql_get_field_assoc_int(numacc, "id");
	new admin = sql_get_field_assoc_int(numacc, "admin");
	sql_free_result(numacc);


	if(strlen(params[2]) < 3 || strlen(params[2]) > 30) 
		return SendErr(playerid, "Причина должна быть от 3 до 30 символов");

	if(params[1] < 1 || params[1] > 2000)
		return SendErr(playerid, "Дни от 1 до 2000");

	if(pData[playerid][pAdmin] < admin)
		return SendErr(playerid, "Ошибка доступа");

	if(GetPlayerID(nick) != -1)
		return SendErr(playerid, "Игрок с данным именем находится на сервере.");

	
	format(query, sizeof(query), "SELECT `user_id` FROM `ban_accounts` WHERE `user_id` = '%d'", id);
	new Result:DeactiveAcc = sql_queryEx(zConn, query, QUERY_CACHED);

	if(sql_num_rows(DeactiveAcc)) 
		return SendErr(playerid, "Аккаунт уже заблокирован!");

	sql_free_result(DeactiveAcc);

	new 
		message[200];


	format(message, sizeof(message), "Администратор %s забанил в оффлайне игрока %s на %d дней. Причина: %s", pData[playerid][pNickname], nick, params[1], params[2]);
	SendClientMessageToAll(COLOR_LIGHTRED, message);

	logs_admin_other(playerid, pData[playerid][pMysqlID], message);

	new
		date[35], 
		h, m, s, 
		day, month, year;  
	gettime(h, m, s);
	getdate(year, month, day);
	format(date, sizeof(date),"%d-%02d-%d %02d:%02d:%02d", year, month, day, h, m, s);

	OfflineBanAccount(playerid, id, nick, params[2], date, params[1]);
	return true;
}

CMD:soffban(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
		return NoCMD(playerid);
	new
		nick[MAX_PLAYER_NAME+1];

	if(sscanf(params, "s[25]ds[30]", nick, params[1], params[2])) 
		return SendInf(playerid, "/soffban [Никнейм] [Дни] [Причина]");
	new 
		query[256];	
	sql_escape_string(zConn, nick,nick, 25);
   	format(query, sizeof(query), "SELECT `id`, `admin` FROM `accounts` WHERE `nickname` = '%s'", nick);
	new Result:numacc = sql_queryEx(zConn, query, QUERY_CACHED);

	if(!sql_num_rows(numacc)) 
		return SendErr(playerid, "Аккаунт не найден в базе данных");

	new id = sql_get_field_assoc_int(numacc, "id");
	new admin = sql_get_field_assoc_int(numacc, "admin");
	sql_free_result(numacc);


	if(strlen(params[2]) < 3 || strlen(params[2]) > 30) 
		return SendErr(playerid, "Причина должна быть от 3 до 30 символов");

	if(params[1] < 1 || params[1] > 30)
		return SendErr(playerid, "Дни от 1 до 30");

	if(pData[playerid][pAdmin] < admin)
		return SendErr(playerid, "Ошибка доступа");

	if(GetPlayerID(nick) != -1)
		return SendErr(playerid, "Игрок с данным именем находится на сервере.");

	
	format(query, sizeof(query), "SELECT `user_id` FROM `ban_accounts` WHERE `user_id` = '%d'", id);
	new Result:DeactiveAcc = sql_queryEx(zConn, query, QUERY_CACHED);

	if(sql_num_rows(DeactiveAcc)) 
		return SendErr(playerid, "Аккаунт уже заблокирован!");

	sql_free_result(DeactiveAcc);

	new 
		message[200];


	format(message, sizeof(message), "Администратор %s тихо забанил в оффлайне игрока %s на %d дней. Причина: %s", pData[playerid][pNickname], nick, params[1], params[2]);
	AdminChat(CGRAY, message);

	logs_admin_other(playerid, pData[playerid][pMysqlID], message);

	new
		date[35], 
		h, m, s, 
		day, month, year;  
	gettime(h, m, s);
	getdate(year, month, day);
	format(date, sizeof(date),"%d-%02d-%d %02d:%02d:%02d", year, month, day, h, m, s);

	OfflineBanAccount(playerid, id, nick, params[2], date, params[1]);
	return true;
}


stock OfflineBanAccount(playerid, user_id, user_name[], reason[], date[], time)
{
	new 
		query[350];

	format(query,sizeof(query),"INSERT INTO `ban_accounts`(`id`, `user_id`, `user_name`, `admin_id`, `admin_name`, `reason`, `date`, `time`) VALUES ('','%d','%s','%d','%s','%s','%s','%d')",user_id, user_name, pData[playerid][pMysqlID], pData[playerid][pNickname], reason, date, time);
	sql_queryEx(zConn, query, QUERY_CACHED);

	return 1;
}


CMD:adeactive(playerid, params[])
{
	if(pData[playerid][pAdmin] < 7)
		return NoCMD(playerid);

	if(sscanf(params, "ds[30]", params[0], params[1])) 
		return SendInf(playerid, "/adeactive [ID игрока] [Причина]");

	if(!IsPlayerConnected(params[0]) || params[0] == playerid)  
		return SendErr(playerid, "Неверный ID");

	if(strlen(params[1]) < 3 || strlen(params[1]) > 30) 
		return SendErr(playerid, "Причина должна быть от 3 до 30 символов");

	if(pData[playerid][pAdmin] < pData[params[0]][pAdmin])
		return SendErr(playerid, "Ошибка доступа");

	format(String512, sizeof(String512), "Администратор деактивировал аккаунт игрока %s. Причина: %s", pData[params[0]][pNickname], params[1]);
	SendClientMessageToAll(COLOR_LIGHTRED, String512);
	logs_admin_other(playerid, pData[playerid][pMysqlID], String512);

	format(String512, sizeof(String512), "Ваш аккаунт был деактивирован по причине: %s", params[1]);
	SendClientMessage(params[0], COLOR_LIGHTRED, String512);

	new
		date[35], 
		h, m, s, 
		day, month, year;  
	gettime(h, m, s);
	getdate(year, month, day);
	format(date, sizeof(date),"%d-%02d-%d %02d:%02d:%02d", year, month, day, h, m, s);

	show_notify_gui(params[0], TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_32", 4000);

	format(String512, sizeof(String512), "\n"cWH"Ваш аккаунт деактивирован!\n\n\
		"cBLUE"Аккаунт: "cWH"%s\n\
		"cBLUE"Причина деактивации: "cWH"%s\n\
		"cBLUE"Время выдачи: "cWH"%s\n\n\
		Если вы не согласны с выданным наказанием, сделайте скриншот и\n\
		обратитесь с жалобой на форум: "cBLUE"forum.b-rp.ru", pData[params[0]][pNickname], params[1], date);
	SPD(params[0], 0, 0,!""cBLUE"Блокировка аккаунта", String512, !"Закрыть","");


	OnlineDeactivateAccount(playerid, params[0], params[1], date);
	return true;
}



CMD:offdeactivate(playerid, params[])
{
	if(pData[playerid][pAdmin] < 7)
		return NoCMD(playerid);
	new
		nick[MAX_PLAYER_NAME+1];

	if(sscanf(params, "s[25]s[30]", nick, params[1])) 
		return SendInf(playerid, "/offdeactivate [Никнейм] [Причина]");
	new 
		query[256];	
	sql_escape_string(zConn, nick,nick, 25);
   	format(query, sizeof(query), "SELECT `id`, `admin` FROM `accounts` WHERE `nickname` = '%s'", nick);
	new Result:numacc = sql_queryEx(zConn, query, QUERY_CACHED);

	if(!sql_num_rows(numacc)) 
		return SendErr(playerid, "Аккаунт не найден в базе данных");

	new id = sql_get_field_assoc_int(numacc, "id");
	new admin = sql_get_field_assoc_int(numacc, "admin");
	sql_free_result(numacc);


	if(strlen(params[1]) < 3 || strlen(params[1]) > 30) 
		return SendErr(playerid, "Причина должна быть от 3 до 30 символов");

	if(pData[playerid][pAdmin] < admin)
		return SendErr(playerid, "Ошибка доступа");

	if(GetPlayerID(nick) != -1)
		return SendErr(playerid, "Игрок с данным именем находится на сервере.");

	
	format(query, sizeof(query), "SELECT `user_id` FROM `deactivate_accounts` WHERE `user_id` = '%d'", id);
	new Result:DeactiveAcc = sql_queryEx(zConn, query, QUERY_CACHED);

	if(sql_num_rows(DeactiveAcc)) 
		return SendErr(playerid, "Аккаунт уже деактивирован");

	sql_free_result(DeactiveAcc);

	new 
		message[144];

	format(message, sizeof(message), "Администратор деактивировал аккаунт игрока %s. Причина: %s", nick, params[1]);
	SendClientMessageToAll(COLOR_LIGHTRED, message);
	logs_admin_other(playerid, pData[playerid][pMysqlID], message);

	new
		date[35], 
		h, m, s, 
		day, month, year;  
	gettime(h, m, s);
	getdate(year, month, day);
	format(date, sizeof(date),"%d-%02d-%d %02d:%02d:%02d", year, month, day, h, m, s);

	OfflineDeactivateAccount(playerid, id, nick, params[1], date);
	return true;
}


CMD:aactive(playerid, params[])
{
	if(pData[playerid][pAdmin] < 7)
		return 1;

	if(sscanf(params, "s[24]", params[0])) 
		return SendInf(playerid, "/aactive [Никнейм]");

	ActiveAccount(playerid, params[0]);
	return 1;
}

stock OnlineDeactivateAccount(playerid, user_id, reason[], date[])
{
	new 
		query[350];
	format(query,sizeof(query),"INSERT INTO `deactivate_accounts`(`id`, `user_id`, `user_name`, `admin_id`, `admin_name`, `reason`, `date`) VALUES ('','%d','%s','%d','%s','%s','%s')",pData[user_id][pMysqlID], pData[user_id][pNickname], pData[playerid][pMysqlID], pData[playerid][pNickname], reason, date);
	sql_queryEx(zConn, query, QUERY_CACHED);

	NewKick(user_id);
	return 1;
}

stock OfflineDeactivateAccount(playerid, user_id, user_name[], reason[], date[])
{
	new 
		query[350];
	format(query,sizeof(query),"INSERT INTO `deactivate_accounts`(`id`, `user_id`, `user_name`, `admin_id`, `admin_name`, `reason`, `date`) VALUES ('','%d','%s','%d','%s','%s','%s')", user_id, user_name, pData[playerid][pMysqlID], pData[playerid][pNickname], reason, date);
	sql_queryEx(zConn, query, QUERY_CACHED);
	return 1;
}

stock CheckStatusAccount(playerid, id)
{
	new 
		query[100];

	format(query, sizeof(query), "SELECT `user_name`, `reason`, `date` FROM `deactivate_accounts` WHERE `user_id` = '%d'", id);
	new Result:accstatus = sql_queryEx(zConn, query, QUERY_CACHED);

	if(sql_num_rows(accstatus))
	{
		new 
			username[32],
			reason[30],
			date[35];

		sql_get_field_assoc(accstatus, "user_name", username, 32);
		sql_get_field_assoc(accstatus, "reason", reason, 30);
		sql_get_field_assoc(accstatus, "date", date, 35);

		new
			message[500];

		format(message, sizeof(message), "\n"cWH"Ваш аккаунт деактивирован!\n\n\
			"cBLUE"Аккаунт: "cWH"%s\n"cBLUE"Причина деактивации: "cWH"%s\n\
			"cBLUE"Время деактивации: "cWH"%s\n\n\
			Если вы не согласны с выданным наказанием, сделайте скриншот и\n\
			обратитесь с жалобой на форум: "cBLUE"forum.b-rp.ru", username, reason, date);
		SPD(playerid, 0, 0,!""cBLUE"Аккаунт деактивирован", message, !"Закрыть","");
		sql_free_result(accstatus);
		NewKick(playerid);
		return 1;
	}
	else
		return 1;
}

stock ActiveAccount(playerid, nickname[])
{
	new 
		query[256];

   	format(query, sizeof(query), "SELECT `id` FROM `accounts` WHERE `nickname` = '%s'", nickname);
	new Result:numacc = sql_queryEx(zConn, query, QUERY_CACHED);

	if(!sql_num_rows(numacc)) 
		return SendErr(playerid, "Неверный никнейм");

	new id = sql_get_field_assoc_int(numacc, "id");
	sql_free_result(numacc);

	format(query, sizeof(query), "DELETE FROM `deactivate_accounts` WHERE `user_id` = '%d'", id);
	new Result:ActiveAcc = sql_queryEx(zConn, query);

	if(sql_affected_rows(ActiveAcc)) 
	{
		new 
			message[144];

		format(message, sizeof(message), "Администратор %s[%d] активировал аккаунт %s", pData[playerid][pNickname], playerid, nickname);
		AdminChat(0xAFAFAFFF, message);
		logs_admin_other(playerid, pData[playerid][pMysqlID], message);
		return true;
	}
	else
		return SendErr(playerid, "Аккаунт не деактивирован");
}

stock UnBanAccount(playerid, nickname[])
{
	new 
		query[256];

   	format(query, sizeof(query), "SELECT `id` FROM `accounts` WHERE `nickname` = '%s'", nickname);
	new Result:numacc = sql_queryEx(zConn, query, QUERY_CACHED);

	if(!sql_num_rows(numacc)) 
		return SendErr(playerid, "Неверный никнейм");

	new id = sql_get_field_assoc_int(numacc, "id");
	sql_free_result(numacc);

	format(query, sizeof(query), "DELETE FROM `ban_accounts` WHERE `user_id` = '%d'", id);
	new Result:ActiveAcc = sql_queryEx(zConn, query);

	if(sql_affected_rows(ActiveAcc)) 
	{
		new 
			message[144];

		format(message, sizeof(message), "Администратор %s[%d] разблокировал аккаунт %s", pData[playerid][pNickname], playerid, nickname);
		AdminChat(0xAFAFAFFF, message);
		logs_admin_other(playerid, pData[playerid][pMysqlID], message);
		return true;
	}
	else
		return SendErr(playerid, "Аккаунт не заблокирован");
}

CMD:offgivemoney(playerid, params[])
{
    if(!general_red_admin(pData[playerid][pNickname])) 
    	return NoCMD(playerid);

    if(pData[playerid][pAdmin] < 1) 
    	return true;

    new 
    	nickname_params[32],
    	money_player_offline,
    	money_player_update;

	if(sscanf(params, "s[30]d", nickname_params, params[0])) 
		return SendInf(playerid, "/offgivemoney [Ник] [Сумма] (Будет добавлена игроку)");    

    if(GetPlayerID(nickname_params) != -1) 
    	return SendErr(playerid, "Игрок с данным именем находится на сервере!");

	new query[256];

	format(query,sizeof(query),"SELECT `money` FROM `accounts` WHERE `nickname` = '%s'", nickname_params);
	new Result:zID = sql_queryEx(zConn, query, QUERY_CACHED);

  	if(!sql_num_rows(zID)) 
  	{
		SendErr(playerid, "Данный игрок не найден в базе данных");
		sql_free_result(zID);
		return 1;
	}


	format(query,sizeof(query),"UPDATE `accounts` SET `money` = money+%d WHERE `nickname` = '%s'", params[0], nickname_params);
	sql_queryEx(zConn, query, QUERY_THREADED);

	format(String144, sizeof(String144), "Вы успешно выдали деньги на аккаунт %s в размере %d рублей", nickname_params, params[0]);
	SendSucc(playerid, String144);

	format(String256,sizeof(String256),"Администратор %s [%d] выдал %d денег на аккаунт %s",pData[playerid][pNickname], playerid, params[0], nickname_params);
	logs_admin_other(playerid, pData[playerid][pMysqlID], String256);

	return true;
}

CMD:offgivelevel(playerid, params[])
{
    if(!general_red_admin(pData[playerid][pNickname])) 
    	return NoCMD(playerid);

    if(pData[playerid][pAdmin] < 1) 
    	return true;

    new 
    	nickname_params[32];

	if(sscanf(params, "s[30]d", nickname_params, params[0])) 
		return SendInf(playerid, "/offgivelevel [Ник] [Уровень]");    

    if(GetPlayerID(nickname_params) != -1) 
    	return SendErr(playerid, "Игрок с данным именем находится на сервере!");

	new query[256];

	format(query,sizeof(query),"SELECT `level` FROM `accounts` WHERE `nickname` = '%s'", nickname_params);
	new Result:zID = sql_queryEx(zConn, query, QUERY_CACHED);

  	if(!sql_num_rows(zID)) 
  	{
		SendErr(playerid, "Данный игрок не найден в базе данных");
		sql_free_result(zID);
		return 1;
	}

	format(query,sizeof(query),"UPDATE `accounts` SET `level` = %d WHERE `nickname` = '%s'", params[0], nickname_params);
	sql_queryEx(zConn, query, QUERY_THREADED);

	format(String144, sizeof(String144), "Вы успешно выдали %d уровень на аккаунт %s",  params[0], nickname_params);
	SendSucc(playerid, String144);

	format(String256,sizeof(String256),"Администратор %s [%d] выдал %d уровень на аккаунт %s",pData[playerid][pNickname], playerid, params[0], nickname_params);
	logs_admin_other(playerid, pData[playerid][pMysqlID], String256);

	return true;
}

CMD:offgiveexp(playerid, params[])
{
    if(!general_red_admin(pData[playerid][pNickname])) 
    	return NoCMD(playerid);

    if(pData[playerid][pAdmin] < 1) 
    	return true;

    new 
    	nickname_params[32];

	if(sscanf(params, "s[30]d", nickname_params, params[0])) 
		return SendInf(playerid, "/offgiveexp [Ник] [EXP]");    

    if(GetPlayerID(nickname_params) != -1) 
    	return SendErr(playerid, "Игрок с данным именем находится на сервере!");

	new query[256];

	format(query,sizeof(query),"SELECT `level` FROM `accounts` WHERE `nickname` = '%s'", nickname_params);
	new Result:zID = sql_queryEx(zConn, query, QUERY_CACHED);

  	if(!sql_num_rows(zID)) 
  	{
		SendErr(playerid, "Данный игрок не найден в базе данных");
		sql_free_result(zID);
		return 1;
	}

	format(query,sizeof(query),"UPDATE `accounts` SET `exp` = exp+%d WHERE `nickname` = '%s'", params[0], nickname_params);
	sql_queryEx(zConn, query, QUERY_THREADED);

	format(String144, sizeof(String144), "Вы успешно выдали %d EXP на аккаунт %s",  params[0], nickname_params);
	SendSucc(playerid, String144);

	format(String256,sizeof(String256),"Администратор %s [%d] выдал %d EXP на аккаунт %s",pData[playerid][pNickname], playerid, params[0], nickname_params);
	logs_admin_other(playerid, pData[playerid][pMysqlID], String256);

	return true;
}

CMD:restart(playerid,params[])
{

	if(pData[playerid][pAdmin] < 7)
		return NoCMD(playerid);

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, ""cWH"Используйте: /restart [минуты] - используйте -1 для отмены рестарта");

	if(params[0] == -1)
	{
		gmx_time = 0;
		SendClientMessageToAll(COLOR_LIGHTRED, "Внимание! Перезагрузка сервера была отменена");
		return true;
	}
	gmx_time = params[0] ? params[0] * 60 : 2;


	static str[60];
	format(str, 60, "Внимание! Перезагрузка сервера через "cWH"%s мин", time_to_string(gmx_time));
	SendClientMessageToAll(COLOR_LIGHTRED, str);
	return true;
}

CMD:restart_hard(playerid)
{
	if(pData[playerid][pAdmin] < 7)
		return NoCMD(playerid);

	gmx_mode_ex();

	return true;
}

CMD:givesnow(playerid, params[])
{
	if(pData[playerid][pAdmin] < 8)
		return NoCMD(playerid);

	if(sscanf(params, "dd", params[0], params[1])) 
		return SendInf(playerid, ""cWH"Используйте: /givesnow [ID] [Количество снежинок]");


	pData[params[0]][pCountSnow] += params[1];
	UpdatePlayerData(params[0], "pCountSnow", pData[params[0]][pCountSnow]);		

	show_notify_gui_newyear(params[0], TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:newyear_snow_give_6", 4500);	

	static str[120];
	format(str, sizeof(str), "Вы выдали игроку %s[%d] снежинок в количестве %d штук!", pData[params[0]][pNickname], params[0], params[1]);
	SendSucc(playerid, str);

	return true;
}

CMD:checkinfo(playerid, params[])
{
	if(pData[playerid][pAdmin] < 7)
		return NoCMD(playerid);

	new 
		nickname_search[32];

	if(sscanf(params, "s[32]", nickname_search)) 
		return SendInf(playerid, ""cWH"Используйте: /checkinfo [Ник]");

	check_info_account_player(playerid, nickname_search);

	return true;
}

CMD:checkmoneylog(playerid, params[])
{
	if(pData[playerid][pAdmin] < 7)
		return NoCMD(playerid);

	new 
		nickname_search[32];

	if(sscanf(params, "s[32]dd", nickname_search, params[1], params[2])) 
	{
		SendInf(playerid, ""cWH"Используйте: /checkmoneylog [Ник] [0 и 50 - последние 50 транзакций]");
		SendInf(playerid, ""cWH"Используйте: /checkmoneylog [Ник] [50 и 100 - с 50 по 100 транзакцию]");
		return SendInf(playerid, ""cWH"Используйте: /checkmoneylog [Ник] [Количество] [Количество]");
	}
	check_info_log_money(playerid, nickname_search, params[1], params[2]);
	return true;
}

CMD:checkmoneylogt(playerid, params[])
{
	if(pData[playerid][pAdmin] < 8)
		return NoCMD(playerid);

	new 
		nickname_search[32],
		phrase_search[64];

	if(sscanf(params, "s[32]s[64]", nickname_search, phrase_search)) 
	{
		return SendInf(playerid, ""cWH"Используйте: /checkmoneylog [Ник] [Фраза]");
	}
	check_info_log_money(playerid, nickname_search, params[1], params[2]);
	return true;
}


callback:: check_info_log_money(playerid, player_name[], limit_1, limit_2)
{
	format(String8096, sizeof(String8096), ""cGREY"№. Никнейм\t"cGREY"Действие\t"cGREY"Сумма транзакции\t"cGREY"Дата транзакции\n");

	format(String256, sizeof(String256), "SELECT * FROM `logs_money` WHERE username = '%s' ORDER BY `date_action` DESC LIMIT %d,%d", player_name, limit_1, limit_2);
	new Result:accounts_search = sql_queryEx(zConnLog, String256, QUERY_CACHED);

	new all_logs_money = sql_num_rows(accounts_search);

	new 
		userid_money_logs,
		username_money_logs[24],
		action_logs_money[128],
		sum_action,
		date_action[32];

    new 
    	logs_money_id = 0;

 	for(new i; i < all_logs_money; i++)
	{	

		userid_money_logs = sql_get_field_assoc_int_ex(accounts_search, i, "userid");
		sum_action = sql_get_field_assoc_int_ex(accounts_search, i, "sum_action");

		sql_get_field_assoc_ex(accounts_search, i, "username", username_money_logs, 24);
		sql_get_field_assoc_ex(accounts_search, i, "action", action_logs_money, 128);
		sql_get_field_assoc_ex(accounts_search, i, "date_action", date_action, 32);

    	format(String8096, sizeof(String8096), "%s%d."cWH" (SQL: %d)"cGR"%s\t%s\t%d"cWH" рублей\t"cGREY"%s\n",String8096, \
    	logs_money_id+1, userid_money_logs, username_money_logs, \
    	action_logs_money, sum_action, date_action);


    	logs_money_id++;
	}
	sql_free_result(accounts_search);
	SPD(playerid,0, DIALOG_STYLE_TABLIST_HEADERS ,""cBLUE"Логи денег",String8096,"Далее","Закрыть");
	return true;
}

callback:: check_info_account_player(playerid, player_name[])
{

	format(String256, sizeof(String256), "SELECT * FROM `accounts` WHERE nickname = '%s'", player_name);
	new Result:accounts_search = sql_queryEx(zConn, String256, QUERY_CACHED);

	new 
		search_sql_id,
		search_nickname[32],
		search_email[24],
		search_ip_last[24],
		search_ip_reg[24],
		search_last_date[24],
		search_reg_date[24],
		search_warn,
		search_warnc,
		search_player_payday,
		search_player_money,
		search_player_bank;

	if(sql_num_rows(accounts_search)) 
	{
		search_sql_id = sql_get_field_assoc_int_ex(accounts_search, 0, "id");
		sql_get_field_assoc_ex(accounts_search, 0, "nickname", search_nickname, 24);
		sql_get_field_assoc_ex(accounts_search, 0, "last", search_last_date, 24);
		sql_get_field_assoc_ex(accounts_search, 0, "create_date", search_reg_date, 24);

		sql_get_field_assoc_ex(accounts_search, 0, "email", search_email, 64);
		sql_get_field_assoc_ex(accounts_search, 0, "ip", search_ip_last, 16);
		sql_get_field_assoc_ex(accounts_search, 0, "LastIP", search_ip_reg, 16);

		search_warn = sql_get_field_assoc_int_ex(accounts_search, 0, "warn");
		search_warnc = sql_get_field_assoc_int_ex(accounts_search, 0, "warnc");
		search_player_payday = sql_get_field_assoc_int_ex(accounts_search, 0, "count_time_payday");
		search_player_money = sql_get_field_assoc_int_ex(accounts_search, 0, "money");
		search_player_bank = sql_get_field_assoc_int_ex(accounts_search, 0, "bank");		

		format(String1024, sizeof(String1024), "\
        "cGREY"Поле\t"cGREY"Значение\n\
        "cBLUE"- "cWH"Номер аккаунта\t"cBLUE"%d\n\
        "cBLUE"- "cWH"Ник\t"cBLUE"%s\n\
        "cBLUE"- "cWH"Почта\t"cBLUE"%s\n\
        "cBLUE"- "cWH"IP (Последний)\t"cBLUE"%s\n\
        "cBLUE"- "cWH"IP (Регистрационный)\t"cBLUE"%s\n\
        "cBLUE"- "cWH"Дата последнего входа\t"cBLUE"%s\n\
        "cBLUE"- "cWH"Дата регистрации\t"cBLUE"%s\n\
        "cBLUE"\t\n\
        "cBLUE"- "cWH"Варнов\t"cGR"%d штук\n\
        "cBLUE"- "cWH"Дней до снятия варна\t"cGR"%d дней\n\
        "cBLUE"- "cWH"Отыграно за час\t"cGR"%s\n\
        "cBLUE"- "cWH"Денег на руках\t"cGR"%d рублей\n\
        "cBLUE"- "cWH"Денег в банке\t"cGR"%d рублей", 
		
		search_sql_id,
		search_nickname,
		search_email,
		search_ip_last,
		search_ip_reg,
		search_last_date,
		search_reg_date,
		search_warn,
		search_warnc,
		time_to_words(search_player_payday),
		search_player_money,
		search_player_bank        

		);
	    SPD(playerid, 0, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Статистика аккаунта", String1024, !"Закрыть", ""); 

	}

	sql_free_result(accounts_search);
	return true;
}

/*CMD:packet_debug(playerid)
{
	if(pData[playerid][pAdmin] < 7)
		return NoCMD(playerid);

	SCM(playerid, -1, "");
	SCM(playerid, -1, "");
	SCM(playerid, -1, "");

	check_packet_player_all_admin(playerid);

	return true;
}

CMD:packetloss(playerid)
{
	if(pData[playerid][pAdmin] < 7)
		return NoCMD(playerid);


	if(debug_packet_loss == 1)
	{
		debug_packet_loss = 0;
		SendSucc(playerid, "Логирование потери пакетов игроков завершено!");
	}
	else
	{
		debug_packet_loss = 1;
		SendSucc(playerid, "Логирование потери пакетов игроко активировано!");
	}
	return true;
}

callback:: check_packet_player_all()
{
	count_iteration_loss++;

	foreach(new i: logged_players)
	{

		new y,m,d,h,mi,s;
		getdate(y,m,d);
		gettime(h,mi,s);



		new 
			file_name[50];

		format(file_name, 128, "debug_count_loss_%d.ini", count_iteration_loss);

	    new File:file = fopen(file_name, io_append);
	    format(String1024, sizeof(String1024), "\n[%d-%d-%d %d:%d:%d] ID: %d | NICKNAME: %s | PACKET: %d_(%.1f) | TIME CONNECT: %i | STATUS: %s", y,m,d,h,mi,s, i, pData[i][pNickname], NetStats_MessagesRecvPerSecond(i), NetStats_PacketLossPercent(i)), NetStats_GetConnectedTime(i), PR_StatusConnect(NetStats_ConnectionStatus(i));
	    fwrite(file, String1024), fclose(file);

	}
	return true;
}

callback:: check_packet_player_all_admin(playerid)
{
	count_iteration_loss++;

	foreach(new i: logged_players)
	{
		format(String256, sizeof(String256), "ID: %d | NICKNAME: %s | PACKET: %d_(%.1f) | TIME CONNECT: %i | STATUS: %s", i, pData[i][pNickname], NetStats_MessagesRecvPerSecond(i), NetStats_PacketLossPercent(i)), NetStats_GetConnectedTime(i), PR_StatusConnect(NetStats_ConnectionStatus(i));
		SCM(playerid, COLOR_GREY, String256);

		new y,m,d,h,mi,s;
		getdate(y,m,d);
		gettime(h,mi,s);

		new 
			file_name[50];

		format(file_name, 128, "debug_count_loss_adm_%d.ini", count_iteration_loss);

	    new File:file = fopen(file_name, io_append);
	    format(String1024, sizeof(String1024), "\n[%d-%d-%d %d:%d:%d] ID: %d | NICKNAME: %s | PACKET: %d_(%.1f) | TIME CONNECT: %i | STATUS: %s", y,m,d,h,mi,s, i, pData[i][pNickname], NetStats_MessagesRecvPerSecond(i), NetStats_PacketLossPercent(i)), NetStats_GetConnectedTime(i), PR_StatusConnect(NetStats_ConnectionStatus(i));
	    fwrite(file, String1024), fclose(file);

	    

	}
	return true;
}*/

CMD:rpc_debug(playerid)
{
	if(pData[playerid][pAdmin] < 7)
		return NoCMD(playerid);


	if(debug_rpc_packet == 1)
	{
		debug_rpc_packet = 0;
		SendSucc(playerid, "Логирование RPC пакетов игроков завершено!");
	}
	else
	{
		debug_rpc_packet = 1;
		SendSucc(playerid, "Логирование RPC пакетов игроко активировано!");
	}

	return true;
}

CMD:property_payday(playerid)
{
	if(pData[playerid][pAdmin] < 8)
		return NoCMD(playerid);

	return check_payday_all_property();
}

CMD:aaction(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8)
    	return NoCMD(playerid);	

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/aaction [1 - EXP | 2 - Зарплаты]");

	switch(params[0])
	{
		case 1:
		{
			if(IsActionTrue2)
			{
				IsActionTrue2 = 0;
				SendSucc(playerid, "Вы выключили акцию Х2 EXP!");
			}
			else
			{
				IsActionTrue2 = 1;
				SendSucc(playerid, "Вы включили акцию Х2 EXP!");
			}
		}
		case 2:
		{
			if(IsActionTrue4)
			{
				IsActionTrue4 = 0;
				SendSucc(playerid, "Вы выключили акцию Х2 зарплаты!");
			}
			else
			{
				IsActionTrue4 = 1;
				SendSucc(playerid, "Вы включили акцию Х2 зарплаты!");
			}
		}
	}
	return true;
}

const 
	ID_CONNECTION_REQUEST 			= 12,
	ID_AUTH_KEY 					= 13,
	ID_NO_FREE_INCOMING_CONNECTIONS = 32,
	ID_DISCONNECTION_NOTIFICATION 	= 33,
	ID_CONNECTION_LOST 				= 34,
	ID_CONNECTION_REQUEST_ACCEPTED 	= 35,
	ID_CONNECTION_ATTEMPT_FAILED 	= 36,
	ID_MODIFIED_PACKET 				= 39,
	ID_ONFOOT_SYNC 					= 207,
	ID_DRIVER_SYNC 					= 200,
	ID_PASSENGER_SYNC 				= 211,
	ID_TRAILER_SYNC 				= 210,
	ID_UNOCCUPIED_SYNC 				= 209,
	ID_AIM_SYNC						= 203,
	ID_BULLET_SYNC 					= 206,
	ID_RCON_COMMAND 				= 201,
	ID_WEAPONS_UPDATE 				= 204,
	ID_STATS_UPDATE 				= 205,
			
	RPC_SET_POS 					= 12,
	RPC_SET_POS_FIND_Z 				= 13,
	RPC_SET_HEALTH 					= 14,
	RPC_CONTROLLABLE				= 15,
	RPC_RESET_WEAPON				= 21,
	RPC_GIVE_WEAPON					= 22,
	RPC_SET_DRUNK_LEVEL 			= 35,
	RPC_SET_WORLD					= 50,
	RPC_SPAWN_PLAYER    			= 52,
	RPC_SET_ARMOUR 					= 66,
	RPC_SET_ARM_WEAPON 				= 67,
	RPC_PUT_VEHICLE					= 70,
	RPC_REMOVE_VEHICLE  			= 71,
	RPC_APPLY_ANIMATION 			= 86,
	RPC_CLEAR_ANIMATION 			= 87,
	RPC_SET_ACTION					= 88,
	RPC_VEHICLE_VELOCITY 			= 91,
	RPC_SPECTATING					= 124,
	RPC_DESTROY_CAR					= 136,
	RPC_SET_AMMO					= 145,
	RPC_SET_VEH_POS					= 159;

/*public OnIncomingPacket(playerid, packetid, BitStream:bs)
{
	if(debug_rpc_packet == 1)
	{
		if(playerid != -1)
		{
			//printf("IN_Packet: PLAYER ID: %d | PLAYER NAME: %s | %s:%d", pData[playerid][pNickname], playerid, PR_GetPacketNames(packetid), packetid);

			new y,m,d,h,mi,s;
			getdate(y,m,d);
			gettime(h,mi,s);

		    new File:file = fopen("debug_raknet_in_packet.ini", io_append);
		    format(String1024, sizeof(String1024), "\n[%d-%d-%d %d:%d:%d] OnIncomingPacket: PLAYER ID: %d | PLAYER NAME: %s | %s:%d", y,m,d,h,mi,s, playerid, pData[playerid][pNickname], PR_GetPacketNames(packetid), packetid);
		    fwrite(file, String1024), fclose(file);
		}

	}
	return true;
}

public OnOutcomingPacket(playerid, packetid, BitStream:bs)
{
	if(debug_rpc_packet == 1)
	{
		//printf("OUT_Packet: PLAYER ID: %d | PLAYER NAME: %s| %s:%d", pData[playerid][pNickname], playerid, PR_GetPacketNames(packetid), packetid);
		if(playerid != -1)
		{
			new y,m,d,h,mi,s;
			getdate(y,m,d);
			gettime(h,mi,s);

		    new File:file = fopen("debug_raknet_out_packet.ini", io_append);
		    format(String1024, sizeof(String1024), "\n[%d-%d-%d %d:%d:%d] OnOutcomingPacket: PLAYER ID: %d | PLAYER NAME: %s| %s:%d", y,m,d,h,mi,s, playerid, pData[playerid][pNickname], PR_GetPacketNames(packetid), packetid);
		    fwrite(file, String1024), fclose(file);
		}
	}
	return true;
}

public OnIncomingRPC(playerid, rpcid, BitStream:bs)
{
	if(debug_rpc_packet == 1)
	{
		if(playerid != -1)
		{		
			new y,m,d,h,mi,s;
			getdate(y,m,d);
			gettime(h,mi,s);

		    new File:file = fopen("debug_raknet_in_rpc.ini", io_append);
		    format(String1024, sizeof(String1024), "\n[%d-%d-%d %d:%d:%d] OnIncomingRPC: PLAYER ID: %d | PLAYER NAME: %s | %s:%d |", y,m,d,h,mi,s, playerid, pData[playerid][pNickname], PR_getInRPCName(rpcid), rpcid);
		    fwrite(file, String1024), fclose(file);
		}
	}
	return true;
}

public OnOutcomingRPC(playerid, rpcid, BitStream:bs)
{
	if(debug_rpc_packet == 1)
	{
		if(playerid != -1)
		{	
			new 
				y,m,d,h,mi,s;
			getdate(y,m,d);
			gettime(h,mi,s);

		    new File:file = fopen("debug_raknet_out_packet.ini", io_append);
		    format(String1024, sizeof(String1024), "\n[%d-%d-%d %d:%d:%d] OnOutcomingRPC: PLAYER ID: %d | PLAYER NAME: %s | %s:%d", y,m,d,h,mi,s, playerid, pData[playerid][pNickname], PR_GetOutRPCName(rpcid), rpcid);
		    fwrite(file, String1024), fclose(file);

		}
	}
	return true;
}*/

stock PR_StatusConnect(connect_id)
{
	new 
		string[51];

	switch(connect_id)
	{
		case 0: string = "DISCONNECT_ASAP";
		case 1: string = "DISCONNECT_ASAP_SILENTLY";
		case 2: string = "DISCONNECT_ON_NO_ACK";
		case 3: string = "REQUESTED_CONNECTION";
		case 4: string = "HANDLING_CONNECTION_REQUEST";
		case 5: string = "UNVERIFIED_SENDER";
		case 6: string = "SET_ENCRYPTION_ON_MULTIPLE_16_BYTE_PACKET";
		case 7: string = "CONNECTED";
		default: string = "NONE";
	}
	return string;
}

stock PR_GetPacketNames(packetid)
{
	new 
		string[31];

	switch(packetid)
	{
		case 12: string = "ID_CONNECTION_REQUEST";
		case 13: string = "ID_AUTH_KEY";
		case 32: string = "ID_NO_FREE_INCOMING_CONS";
		case 33: string = "ID_DISCONNECTION_NOTIFICATION";
		case 34: string = "ID_CONNECTION_LOST";
		case 35: string = "ID_CONNECTION_REQUEST_ACCEPTED";
		case 36: string = "ID_CONNECTION_ATTEMPT_FAILED";
		case 39: string = "ID_MODIFIED_PACKET";
		case 207: string = "ID_ONFOOT_SYNC";
		case 200: string = "ID_DRIVER_SYNC";
		case 211: string = "ID_PASSENGER_SYNC";
		case 210: string = "ID_TRAILER_SYNC";
		case 209: string = "ID_UNOCCUPIED_SYNC";
		case 203: string = "ID_AIM_SYNC";
		case 206: string = "ID_BULLET_SYNC";
		case 201: string = "ID_RCON_COMMAND";
		case 204: string = "ID_WEAPONS_UPDATE";
		case 205: string = "ID_STATS_UPDATE";
	}
	return string;
}

stock PR_GetOutRPCName(rpcid){
	new string[31];
	switch(rpcid){
		case 171: string = "ShowActor";
		case 172: string = "HideActor";
		case 173: string = "ApplyActorAnimation";
		case 174: string = "ClearActorAnimation";
		case 175: string = "SetActorFacingAngle";
		case 176: string = "SetActorPos";
		case 178: string = "SetActorHealth";
		case 113: string = "SetPlayerAttachedObject";
		case 59: string = "ChatBubble";
		case 37: string = "DisableCheckpoint";
		case 38: string = "SetRaceCheckpoint";
		case 39: string = "DisableRaceCheckpoint";
		case 107: string = "SetCheckpoint";
		case 61: string = "ShowDialog";
		case 108: string = "AddGangZone";
		case 120: string = "GangZoneDestroy";
		case 121: string = "GangZoneFlash";
		case 85: string = "GangZoneStopFlash";
		case 73: string = "ShowGameText";
		case 146: string = "SetGravity";
		case 56: string = "SetPlayerMapIcon";
		case 144: string = "RemovePlayerMapIcon";
		case 77: string = "ShowMenu";
		case 78: string = "HideMenu";
		case 80: string = "ShowPlayerNameTag";
		case 44: string = "CreateObject";
		case 75: string = "AttachObjectToPlayer";
		case 27: string = "SelectObject";
		case 28: string = "CancelEdit";
		case 45: string = "SetObjectPos";
		case 46: string = "SetObjectRotation";
		case 47: string = "DestroyObject";
		case 122: string = "StopObject";
		case 95: string = "CreatePickup";
		case 138: string = "ServerQuit";
		case 137: string = "ServerJoin";
		case 155: string = "UpdateScoresAndPings";
		case 86: string = "ApplyPlayerAnimation";
		case 87: string = "ClearPlayerAnimation";
		case 166: string = "DeathBroadcast";
		case 11: string = "SetPlayerName";
		case 12: string = "SetPlayerPos";
		case 13: string = "SetPlayerPosFindZ";
		case 34: string = "SetPlayerSkillLevel";
		case 153: string = "SetPlayerSkin";
		case 29: string = "SetPlayerTime";
		case 88: string = "SetPlayerSpecialAction";
		case 152: string = "SetPlayerWeather";
		case 17: string = "SetWorldBounds";
		case 90: string = "SetPlayerVelocity";
		case 15: string = "TogglePlayerControllable";
		case 124: string = "TogglePlayerSpectating";
		case 30: string = "ToggleClock";
		case 69: string = "SetPlayerTeam";
		case 16: string = "PlayerPlaySound";
		case 18: string = "GivePlayerMoney";
		case 20: string = "ResetPlayerMoney";
		case 21: string = "ResetPlayerWeapons";
		case 22: string = "GivePlayerWeapon";
		case 41: string = "PlayAudioStream";
		case 42: string = "StopAudioStream";
		case 43: string = "RemoveBuilding";
		case 14: string = "SetPlayerHealth";
		case 66: string = "SetPlayerArmour";
		case 145: string = "SetPlayerAmmo";
		case 162: string = "SetPlayerCameraBehindPlayer";
		case 67: string = "SetArmedWeapon";
		case 32: string = "WorldPlayerAdd";
		case 163: string = "WorldPlayerRemove";
		case 79: string = "CreateExplosion";
		case 55: string = "SendDeathMessage";
		case 93: string = "SendClientMessage";
		case 35: string = "SetPlayerDrunkLevel";
		case 89: string = "SetPlayerFightingStyle";
		case 156: string = "SetPlayerInterior";
		case 72: string = "SetPlayerColor";
		case 74: string = "ForceClassSelection";
		case 111: string = "ToggleWidescreen";
		case 133: string = "SetPlayerWantedLevel";
		case 157: string = "SetPlayerCameraPos";
		case 158: string = "SetPlayerCameraLookAt";
		case 68: string = "SetSpawnInfo";
		case 128: string = "RequestClass";
		case 126: string = "SpectatePlayer";
		case 127: string = "SpectateVehicle";
		case 104: string = "EnableStuntBonus";
		case 83: string = "SelectTextDraw";
		case 105: string = "TextDrawSetString";
		case 134: string = "ShowTextDraw";
		case 135: string = "HideTextDraw";
		case 57: string = "RemoveVehicleComponent";
		case 65: string = "LinkVehicleToInterior";
		case 70: string = "PutPlayerInVehicle";
		case 71: string = "RemovePlayerFromVehicle";
		case 106: string = "UpdateVehicleDamageStatus";
		case 123: string = "SetVehicleNumberPlate";
		case 147: string = "SetVehicleHealth";
		case 159: string = "SetVehiclePos";
		case 160: string = "SetVehicleZAngle";
		case 161: string = "SetVehicleParams";
		case 164: string = "WorldVehicleAdd";
		case 165: string = "WorldVehicleRemove";
		case 58: string = "Update3DTextLabel";
		case 170: string = "SetTargeting";
	}
	return string;
}

stock PR_getInRPCName(rpcid){
	new string[31];
	switch(rpcid){
		case 26: string = "EnterVehicle";
		case 154: string = "ExitVehicle";
		case 52: string = "SendSpawn";
		case 101: string = "SendChatMessage";
		case 118: string = "InteriorChangeNotification";
		case 53: string = "SendDeathNotification";
		case 50: string = "SendCommand";
		case 62: string = "SendDialogResponse";
		case 103: string = "ClientCheckResponse";
		case 115: string = "GiveTakeDamage";
		case 119: string = "ClickMap";
		case 128: string = "RequestClass";
		case 129: string = "RequestSpawn";
		case 132: string = "OnPlayerSelectedMenuRow";
		case 140: string = "OnPlayerExitedMenu";
		case 131: string = "OnPlayerPickupPickup";
		case 16: string = "OnPlayerEditAttachedObject";
		case 117: string = "OnPlayerEditObject";
		case 155: string = "UpdateScoresAndPings";
		case 25: string = "ClientJoin";
		case 54: string = "NPCJoin";
		case 168: string = "OnCameraTarget";
	}
	return string;
}


CMD:get(playerid, params[])
{

	if(pData[playerid][pAdmin] < 3)
		return NoCMD(playerid);

	if(sscanf(params, "d", params[0]))
		return SendInf(playerid, "/get [ID]");

	new
	id = params[0];

	if(!IsPlayerConnected(id))
		return SendErr(playerid,"Неверный ID");

	if(pData[id][pAdmin] == 8)
		return SendErr(playerid, "Вы не можете посмотреть рег. данные данного аккаунта");

	new query[228];
	format(query,sizeof(query),"SELECT * FROM `accounts` WHERE `nickname` = '%s'",pData[id][pNickname]);
	new Result:r = sql_queryEx(zConn, query, QUERY_CACHED);
		
	new 
		regdate[32],
		lastlogin[32],
		lastip[32];

	sql_get_field_assoc_ex(r, 0, "create_date", regdate);
	sql_get_field_assoc_ex(r, 0, "last", lastlogin);
	sql_get_field_assoc_ex(r, 0, "LastIP", lastip);
	sql_free_result(r);

	format(String1024,sizeof(String1024),""cWH"Номер аккаунта:"cBLUE"\t%d\n\
	"cWH"Наличные:"cBLUE"\t\t%d\n\
	"cWH"Осн. банк счёт:"cBLUE"\t\t%d\n\
	"cWH"Уровень:"cBLUE"\t\t%d\
	\n"cWH"IP адрес(регис.):"cBLUE"\t%s\n\
	"cWH"IP адрес(послед.):"cBLUE"\t%s\n\
	"cWH"Дата регистрации:"cBLUE"\t%s\n\
	"cWH"Дата авторизации:"cBLUE"\t%s\n\
	"cWH"Донат:"cBLUE"\t\t\t%d",pData[id][pMysqlID], pData[id][pMoney], pData[id][pBank], pData[id][pLevel], pData[id][pRegIP], lastip, regdate, lastlogin, pData[id][pDonate]);
	SPD(playerid,0,0,pData[id][pNickname],String1024,"Закрыть","");

	new y,m,d,h,mi,s;
	getdate(y,m,d);
	gettime(h,mi,s);
	format(query,sizeof(query),"INSERT INTO `unbanlog` VALUES('','%s','%s','%d-%d-%d %d:%d:%d','%d')",pData[playerid][pNickname],pData[id][pNickname],y,m,d,h,mi,s,69);
	sql_queryEx(zConn, query, QUERY_THREADED);
	return 1;
}

CMD:num(playerid, params[])
{
    if(pData[playerid][pAdmin] < 3)
		return NoCMD(playerid);

	if(sscanf(params, "d",params[0])) 
		return SendInf(playerid, "/num [ID аккаунта]");

	new 
		query[144];

	format(query, sizeof(query), "SELECT * FROM `accounts` WHERE `id` = '%i'", params[0]);
	new Result:r = sql_queryEx(zConn, query, QUERY_CACHED);

	if(!sql_num_rows(r))
	{
		sql_free_result(r);
		return SendErr(playerid, "Неверный номер аккаунта");
	} 

	new 
		nickname[32],
		lastlogin[32],
		regdate[32],
		lastip[32],
		regip[32],
		level = sql_get_field_assoc_int_ex(r, 0, "level"),
		donate = sql_get_field_assoc_int_ex(r, 0, "donate"),
		bank = sql_get_field_assoc_int_ex(r, 0, "bank"),
		money = sql_get_field_assoc_int_ex(r, 0, "money"),
		admin = sql_get_field_assoc_int_ex(r, 0, "admin");

	sql_get_field_assoc_ex(r, 0, "ip", regip);
	sql_get_field_assoc_ex(r, 0, "create_date", regdate);
	sql_get_field_assoc_ex(r, 0, "last", lastlogin);
	sql_get_field_assoc_ex(r, 0, "LastIP", lastip);
	sql_get_field_assoc_ex(r, 0, "nickname", nickname);

	sql_free_result(r);

	if(admin == 8)
		return SendErr(playerid, "Вы не можете посмотреть рег. данные данного аккаунта");

	format(String1024,sizeof(String1024),"\
	"cWH"Номер аккаунта:"cBLUE"\t%i\n\
	"cWH"Наличные:"cBLUE"\t\t%i\n\
	"cWH"Осн. банк счёт:"cBLUE"\t\t%i\n\
	"cWH"Уровень:"cBLUE"\t\t%i\n\
	"cWH"IP адрес(регис.):"cBLUE"\t%s\n\
	"cWH"IP адрес(послед.):"cBLUE"\t%s\n\
	"cWH"Дата регистрации:"cBLUE"\t%s\n\
	"cWH"Дата авторизации:"cBLUE"\t%s\n\
	"cWH"Донат:"cBLUE"\t\t\t%i", params[0], money, bank, level, regip, lastip, regdate, lastlogin, donate);

	SPD(playerid, 0, DIALOG_STYLE_MSGBOX, nickname, String1024, !"Закрыть","");
	return true;
}

CMD:offget(playerid, params[])
{
    if(pData[playerid][pAdmin] < 3)
		return NoCMD(playerid);

	if(sscanf(params, "s[32]",params[0])) 
		return SendInf(playerid, "/offget [Ник игрока]");

	new 
		query[144];
		
	format(query, sizeof(query), "SELECT * FROM `accounts` WHERE `nickname` = '%s'", params[0]);
	new Result:r = sql_queryEx(zConn, query, QUERY_CACHED);

	if(!sql_num_rows(r))
	{
		sql_free_result(r);
		return SendErr(playerid, "Аккаунт не найдет в базе данных");
	} 

	new 
		lastlogin[32],
		regdate[32],
		lastip[32],
		regip[32],
		id = sql_get_field_assoc_int_ex(r, 0, "id"),
		level = sql_get_field_assoc_int_ex(r, 0, "level"),
		donate = sql_get_field_assoc_int_ex(r, 0, "donate"),
		bank = sql_get_field_assoc_int_ex(r, 0, "bank"),
		money = sql_get_field_assoc_int_ex(r, 0, "money"),
		admin = sql_get_field_assoc_int_ex(r, 0, "admin");

	sql_get_field_assoc_ex(r, 0, "ip", regip);
	sql_get_field_assoc_ex(r, 0, "create_date", regdate);
	sql_get_field_assoc_ex(r, 0, "last", lastlogin);
	sql_get_field_assoc_ex(r, 0, "LastIP", lastip);

	sql_free_result(r);

	if(admin == 8)
		return SendErr(playerid, "Вы не можете посмотреть рег. данные данного аккаунта");

	format(String1024,sizeof(String1024),"\
	"cWH"Номер аккаунта:"cBLUE"\t%i\n\
	"cWH"Наличные:"cBLUE"\t\t%i\n\
	"cWH"Осн. банк счёт:"cBLUE"\t\t%i\n\
	"cWH"Уровень:"cBLUE"\t\t%i\n\
	"cWH"IP адрес(регис.):"cBLUE"\t%s\n\
	"cWH"IP адрес(послед.):"cBLUE"\t%s\n\
	"cWH"Дата регистрации:"cBLUE"\t%s\n\
	"cWH"Дата авторизации:"cBLUE"\t%s\n\
	"cWH"Донат:"cBLUE"\t\t\t%i", id, money, bank, level, regip, lastip, regdate, lastlogin, donate);

	SPD(playerid, 0, DIALOG_STYLE_MSGBOX, params[0], String1024, !"Закрыть","");
	return true;
}

CMD:lip(playerid, params[])
{
	if(pData[playerid][pAdmin] < 3)
		return NoCMD(playerid);

	if(sscanf(params, "s[20]", params[0])) 
		return SendInf(playerid, "/lip [ip]");

	new 
		query[144];

	format(query, sizeof(query), "SELECT * FROM `accounts` WHERE `LastIP` = '%s' ORDER BY `money` DESC", params[0]);
	new Result:r = sql_queryEx(zConn, query, QUERY_CACHED);

	if(!sql_num_rows(r))
	{
		sql_free_result(r);
		return SendErr(playerid, "Аккаунты с указанным IP не найдены в базе данных");
	} 
	format(String2048, sizeof(String2048), ""cBLUE"ID\t"cBLUE"Ник\t"cBLUE"Деньги/Банк\t"cBLUE"Уровень\n\n");
    for(new i; i < sql_num_rows(r); i++)
	{
		new 
			level = sql_get_field_assoc_int_ex(r, i, "level"),
			bank = sql_get_field_assoc_int_ex(r, i, "bank"),
			money = sql_get_field_assoc_int_ex(r, i, "money"),
			nickname[MAX_PLAYER_NAME],
			id = sql_get_field_assoc_int_ex(r, i, "id");

		sql_get_field_assoc_ex(r, i, "nickname", nickname);

		format(String2048, sizeof(String2048), "%s"cWH"%i\t"cWH"%s\t"cWH"%i/%i\t"cWH"%i\n",String2048, id, nickname, money, bank, level);
	}

	ShowPlayerDialog(playerid, 0, DIALOG_STYLE_TABLIST_HEADERS, params[0], String2048, !"Закрыть", "");
	sql_free_result(r);
	return true;
}

CMD:glip(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
		return NoCMD(playerid);

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/glip [ID аккаунта]");

	new 
		query[144];

	format(query, sizeof(query), "SELECT * FROM `accounts` WHERE `id` = '%i'", params[0]);
	new Result:r = sql_queryEx(zConn, query, QUERY_CACHED);

	if(!sql_num_rows(r))
	{
		sql_free_result(r);
		return SendErr(playerid, "Аккаунты не найдены в базе данных");
	} 

	new 
		lastip[32];

	sql_get_field_assoc_ex(r, 0, "LastIP", lastip);
	sql_free_result(r);

	format(query, sizeof(query), "SELECT * FROM `accounts` WHERE `LastIP` = '%s'", lastip);
	new Result:result = sql_queryEx(zConn, query, QUERY_CACHED);

	if(!sql_num_rows(result))
	{
		sql_free_result(result);
		return SendErr(playerid, "Аккаунты не найдены в базе данных");
	}


	format(String2048, sizeof(String2048), ""cBLUE"ID\t"cBLUE"Ник\t"cBLUE"Деньги/Банк\t"cBLUE"Уровень\n\n");
    for(new i; i < sql_num_rows(result); i++)
	{
		new 
			level = sql_get_field_assoc_int_ex(result, i, "level"),
			bank = sql_get_field_assoc_int_ex(result, i, "bank"),
			money = sql_get_field_assoc_int_ex(result, i, "money"),
			nickname[MAX_PLAYER_NAME],
			id = sql_get_field_assoc_int_ex(result, i, "id");

		sql_get_field_assoc_ex(result, i, "nickname", nickname);

		format(String2048, sizeof(String2048), "%s"cWH"%i\t"cWH"%s\t"cWH"%i/%i\t"cWH"%i\n",String2048, id, nickname, money, bank, level);
	}

	ShowPlayerDialog(playerid, 0, DIALOG_STYLE_TABLIST_HEADERS, lastip, String2048, !"Закрыть", "");
	sql_free_result(result);
	return true;
}

CMD:olip(playerid, params[])
{
	if(pData[playerid][pAdmin] < 5)
		return NoCMD(playerid);

	if(sscanf(params, "s[20]", params[0])) 
		return SendInf(playerid, "/olip [IP]");
	new 
		count;

	format(String2048, sizeof(String2048), ""cBLUE"ID\t"cBLUE"Ник\t"cBLUE"Деньги/Банк\t"cBLUE"Уровень\n\n");
	foreach(new i : Player)
	{
		if(GetString(pTemp[i][pLastIP], params[0]))
		{
			count ++;
			format(String2048, sizeof(String2048), "%s"cWH"%i\t"cWH"%s[%i]\t"cWH"%i/%i\t"cWH"%i\n",
				String2048, pData[i][pMysqlID], pData[i][pNickname], i, pData[i][pMoney], pData[i][pBank], pData[i][pLevel]);
		}
	}
	if(count == 0)
		return SendErr(playerid, "Аккаунты с указанным IP не найдены на сервере");

	ShowPlayerDialog(playerid, 0, DIALOG_STYLE_TABLIST_HEADERS, params[0], String2048, !"Закрыть", "");
	return true;
}

CMD:money(playerid, params[])
{

	if(pData[playerid][pAdmin] < 2)
		return NoCMD(playerid);

	if(sscanf(params, "d", params[0]))
		return SendInf(playerid, "/money [ID]");

	new 
	id = params[0];

	if(!IsPlayerConnected(id))
		return SendErr(playerid,"Неверный ID");

	format(String1024,sizeof(String1024),"\
	"cWH"Номер аккаунта:"cBLUE"\t%d\n\
	"cWH"Наличные:"cBLUE"\t\t%d\n\
	"cWH"Осн. банк счёт:"cBLUE"\t\t%d\n\
	"cWH"Уровень:"cBLUE"\t\t%d\n\
	"cWH"Донат:"cBLUE"\t\t\t%d",pData[id][pMysqlID],pData[id][pMoney],pData[id][pBank],pData[id][pLevel], pData[id][pDonate]);
	SPD(playerid,0,0,pData[id][pNickname],String1024,"Закрыть","");

	return true;
}

CMD:offmoney(playerid, params[])
{
    if(pData[playerid][pAdmin] < 2)
		return NoCMD(playerid);

	if(sscanf(params, "s[32]",params[0])) 
		return SendInf(playerid, "/offmoney [Ник игрока]");

	new 
		query[144];
		
	format(query, sizeof(query), "SELECT * FROM `accounts` WHERE `nickname` = '%s'", params[0]);
	new Result:r = sql_queryEx(zConn, query, QUERY_CACHED);

	if(!sql_num_rows(r))
	{
		sql_free_result(r);
		return SendErr(playerid, "Аккаунт не найдет в базе данных");
	} 

	new 
		id = sql_get_field_assoc_int_ex(r, 0, "id"),
		level = sql_get_field_assoc_int_ex(r, 0, "level"),
		donate = sql_get_field_assoc_int_ex(r, 0, "donate"),
		bank = sql_get_field_assoc_int_ex(r, 0, "bank"),
		money = sql_get_field_assoc_int_ex(r, 0, "money");

	format(String1024,sizeof(String1024),"\
	"cWH"Номер аккаунта:"cBLUE"\t%i\n\
	"cWH"Наличные:"cBLUE"\t\t%i\n\
	"cWH"Осн. банк счёт:"cBLUE"\t\t%i\n\
	"cWH"Уровень:"cBLUE"\t\t%i\n\
	"cWH"Донат:"cBLUE"\t\t\t%i", id, money, bank, level, donate);

	SPD(playerid, 0, DIALOG_STYLE_MSGBOX, params[0], String1024, !"Закрыть","");
	return true;
}

CMD:askin(playerid, params[])
{
    if(!pData[playerid][pAdmin])
        return NoCMD(playerid);
    
    if(pData[playerid][pSkin] != 57) {
        SetPVarIntNew(playerid, "askin", 1);
        SetPlayerSkin(playerid, 57);
    } else {
        new fmt_str[512];
	    format(fmt_str, sizeof(fmt_str), "SELECT * FROM `accounts` WHERE nickname = '%s'",pData[playerid][pNickname]);
	    new Result:pldata = sql_queryEx(zConn, fmt_str, QUERY_CACHED);
        SetPlayerSkin(playerid, sql_get_field_assoc_int_ex(pldata, 0, "skin"));
    }
    return true;
}

CMD:mypos(playerid, params[])
{
	if(!pData[playerid][pAdmin])
		return NoCMD(playerid);

	new Float:POS[4];
	new fmt_str[64];

	GetPlayerPos(playerid, POS[0], POS[1], POS[2]);
	GetPlayerFacingAngle(playerid, POS[3]);

	format(fmt_str, 64, "X: %f Y: %f Z: %f ANGLE: %f", POS[0], POS[1], POS[2], POS[3]);
	SCM(playerid, -1, fmt_str);
	return 1;
}

CMD:savec(playerid, params[])
{

  if(pData[playerid][pAdmin] < 7) 
    return NoCMD(playerid);



  if(sscanf(params, "ds[32]s[32]", params[0], params[1], params[2])) 
  {
    SCM(playerid, COLOR_BLUE, !"Подсказка: "cWH"/savec [ID] [Наименование] [Доп.Информация]");
    SCM(playerid, COLOR_BLUE, !"Подсказка: "cWH"ID - для более точного понимания");
    SCM(playerid, COLOR_BLUE, !"Подсказка: "cWH"Наименование - основное наименование координаты. Макс - 32 символа");
    SCM(playerid, COLOR_BLUE, !"Подсказка: "cWH"Доп.Информация - дополнительный данные. Макс - 32 символа");

  }



  new 
    filename[128],
    tagstring[512],
    coordstring[512], 
    namestring[32];

  new 
    local_vw = GetPlayerVirtualWorld(playerid),
    local_int = GetPlayerInterior(playerid);

  new 
    Float:x, Float:y, Float:z, Float:r;

  GetPlayerPos(playerid, x, y, z);
  GetPlayerFacingAngle(playerid, r);

  new 
    local_veh = GetPlayerVehicleID(playerid);

  format(filename, 128, "save_coord_brilliant_%d_%s.txt", params[0], params[1]);

  format(tagstring, sizeof(tagstring), "|----------%s----------|\r\n", params[0]);
  format(tagstring, sizeof(tagstring), "%s\r\n", params[2]);
  format(namestring, sizeof(namestring),"Позиция автомобиля (X | Y | Z | R | VI | VW):\r\n");
  format(coordstring,sizeof(coordstring),"%d %f, %f, %f, %f, %d, %d", local_veh, x, y, z, r, local_vw, local_int);
  new File:File = fopen(filename, io_write);
  fwrite(File, tagstring);
  fwrite(File, namestring);
  fwrite(File, coordstring);
  fclose(File);  

  SCM(playerid, COLOR_BLUE, !"Подсказка: "cWH"Координаты успешно сохранены!");
  SFCM(playerid,COLOR_BLUE,"Подсказка: "cWH"Номер - %d | Наименование - %s",params[0], params[1]);
  SFCM(playerid,COLOR_BLUE,"Подсказка: "cWH"Доп.Информация - %s", params[2]);
  SFCM(playerid,COLOR_BLUE,"Подсказка: "cWH"ID автомобиля - %d", local_veh);
  SFCM(playerid,COLOR_BLUE,"Подсказка: "cWH"Координаты: X - %f Y - %f Z - %f R - %f | Мир - %d | Интерьер - %d", x, y, z, r, local_vw, local_int);


  return true;
}

/*
CMD:genrl(playerid, params[])
{
	if(!pData[playerid][pAdmin])
		return NoCMD(playerid);

	if(sscanf(params, "d", params[0])) 
	{
		SendInf(playerid, "0 - ERR CASH | 1 - DONE CASH | 2 - WARNING | 3 - DONE | 4 - NOTIF + BTN");
		return SendInf(playerid, "/genrl [ID notif]");
	}

	switch(params[1])
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
			EROM(playerid, 4, "BTN + NOTIF BY WEIKTON GAMES", 7, "Далее", "/test");
			SCM(playerid, -1, "Уведомление вызывает команду /test");
		}
	}
	return 1;
}

CMD:test(playerid)
{
	SCM(playerid, -1, "WEIKTON | ERROR | JUSPER - TEST NOTIF");
	return 1;
}*/
/*
CMD:atune(playerid, params[])
{
	if(!pDara[playerid][pAdmin])
		return NoCMD(playerid);

	extract params -> new vehicleid, set_code, set_value; else {

		SendClientMessage(playerid, 0xCECECEFF, "Используйте: /atune [id транспорта] [код] [значение]");
		SendClientMessage(playerid, 0xFF6600FF, "Коды: 1 - Диски | 2 - Гидра");

		return 1;
	}

	if(!IsValidVehicle(vehicleid)) return SendClientMessage(playerid, 0xFF6600FF, "Seat to vehicle, please");

	new fmt_msg[128];

	switch(set_code)
	{
		case 1:
		{
        	if(!(1073 <= set_value <= 1085)) return SendClientMessage(playerid, 0xFF6600FF, "Введите ид дисков от 1073 до 1085");

		//	new car = g_ownable_car[vehicleid][OC_SQL_ID];

			new color_2 = 1;

 			AddVehicleComponent(vehicleid, set_value);

			format(fmt_msg, sizeof fmt_msg, "Вы поставили на транспорт №%d диски №%d", vehicleid, set_value);
			SCM(playerid, COLOR_WHITE, fmt_msg);
			ChangeVehicleColor(color_2);
		}
  		case 2:
		{
        	if(!(1087 <= set_value <= 1087)) return SendClientMessage(playerid, 0xFF6600FF, "Введите ид гидры 1087");

			//new car = g_ownable_car[vehicleid][OC_SQL_ID];

 			AddVehicleComponent(vehicleid, set_value);


			format(fmt_msg, sizeof fmt_msg, "Вы поставили гидру на автомобиль %d", vehicleid);
			SCM(playerid, 0x66CC00FF, fmt_msg);
		}
		default: return SendClientMessage(playerid, 0xFF6600FF, "Ошибка введеный вами код некоректен");
	}

	return 1;
}*/