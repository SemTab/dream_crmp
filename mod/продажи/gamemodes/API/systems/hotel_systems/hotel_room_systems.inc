callback:: load_hotel_room_all()
{
	new Result:hotel_room_p = sql_queryEx(zConn, "SELECT * FROM `hotel_room` ORDER BY `hotel_room_id`", QUERY_CACHED);

	new all_room_hotel = sql_num_rows(hotel_room_p);

	new time = GetTickCount();

	new 
		fmt_str[45];

 	for(new i; i < all_room_hotel; i++)
	{
		hotel_room[i][hotel_room_id]  = sql_get_field_assoc_int_ex(hotel_room_p, i, "hotel_room_id"); 

		hotel_room[i][hotel_h_id]	= sql_get_field_assoc_int_ex(hotel_room_p, i, "hotel_id"); 


		new 
			id = hotel_room[i][hotel_room_id];

		hotel_room[i][hotel_room_lock]  = sql_get_field_assoc_int_ex(hotel_room_p, i, "hotel_room_lock"); 

		hotel_room[i][hotel_room_day]  = sql_get_field_assoc_int_ex(hotel_room_p, i, "hotel_room_day"); 

		hotel_room[i][hotel_room_class]  = sql_get_field_assoc_int_ex(hotel_room_p, i, "hotel_room_class"); 

		hotel_room[i][hotel_room_owned]  = sql_get_field_assoc_int_ex(hotel_room_p, i, "hotel_room_owned"); 

  		hotel_room[i][hotel_room_enter_x] = sql_get_field_assoc_float_ex(hotel_room_p, i, "hotel_room_enter_x");
  		hotel_room[i][hotel_room_enter_y] = sql_get_field_assoc_float_ex(hotel_room_p, i, "hotel_room_enter_y");
  		hotel_room[i][hotel_room_enter_z] = sql_get_field_assoc_float_ex(hotel_room_p, i, "hotel_room_enter_z");

  		hotel_room[i][hotel_room_exit_x] = sql_get_field_assoc_float_ex(hotel_room_p, i, "hotel_room_exit_x");
  		hotel_room[i][hotel_room_exit_y] = sql_get_field_assoc_float_ex(hotel_room_p, i, "hotel_room_exit_y");
  		hotel_room[i][hotel_room_exit_z] = sql_get_field_assoc_float_ex(hotel_room_p, i, "hotel_room_exit_z");

  		hotel_room[i][hotel_room_level] = sql_get_field_assoc_int_ex(hotel_room_p, i, "hotel_level"); 

		if(hotel_room[i][hotel_h_id] == HOTEL_1)
		{
			if(hotel_room[i][hotel_room_owned] == -1)
			{
				hotel_room[i][hotel_room_pickup] = CreateDynamicPickup(13731, 23, hotel_room[i][hotel_room_enter_x], hotel_room[i][hotel_room_enter_y], hotel_room[i][hotel_room_enter_z], hotel_room[id][hotel_room_level]+100);
			}
			else
			{
				hotel_room[i][hotel_room_pickup] = CreateDynamicPickup(13732, 23, hotel_room[i][hotel_room_enter_x], hotel_room[i][hotel_room_enter_y], hotel_room[i][hotel_room_enter_z], hotel_room[id][hotel_room_level]+100);
			}



		}
		if(hotel_room[i][hotel_h_id] == HOTEL_2)
		{
			if(hotel_room[i][hotel_room_owned] == -1)
			{
				hotel_room[i][hotel_room_pickup] = CreateDynamicPickup(13731, 23, hotel_room[i][hotel_room_enter_x], hotel_room[i][hotel_room_enter_y], hotel_room[i][hotel_room_enter_z], hotel_room[id][hotel_room_level]+200);
			}
			else
			{
				hotel_room[i][hotel_room_pickup] = CreateDynamicPickup(13732, 23, hotel_room[i][hotel_room_enter_x], hotel_room[i][hotel_room_enter_y], hotel_room[i][hotel_room_enter_z], hotel_room[id][hotel_room_level]+200);
			}
		}
		if(hotel_room[i][hotel_h_id] == HOTEL_3)
		{
			if(hotel_room[i][hotel_room_owned] == -1)
			{
				hotel_room[i][hotel_room_pickup] = CreateDynamicPickup(13731, 23, hotel_room[i][hotel_room_enter_x], hotel_room[i][hotel_room_enter_y], hotel_room[i][hotel_room_enter_z], hotel_room[id][hotel_room_level]+300);
			}
			else
			{
				hotel_room[i][hotel_room_pickup] = CreateDynamicPickup(13732, 23, hotel_room[i][hotel_room_enter_x], hotel_room[i][hotel_room_enter_y], hotel_room[i][hotel_room_enter_z], hotel_room[id][hotel_room_level]+300);
			}
		}
		if(hotel_room[i][hotel_h_id] == HOTEL_4)
		{
			if(hotel_room[i][hotel_room_owned] == -1)
			{
				hotel_room[i][hotel_room_pickup] = CreateDynamicPickup(13731, 23, hotel_room[i][hotel_room_enter_x], hotel_room[i][hotel_room_enter_y], hotel_room[i][hotel_room_enter_z], hotel_room[id][hotel_room_level]+400);
			}
			else
			{
				hotel_room[i][hotel_room_pickup] = CreateDynamicPickup(13732, 23, hotel_room[i][hotel_room_enter_x], hotel_room[i][hotel_room_enter_y], hotel_room[i][hotel_room_enter_z], hotel_room[id][hotel_room_level]+400);
			}
		}



		if(hotel_room[i][hotel_h_id] == HOTEL_1)
		{

			format(fmt_str, 45, "\
				Номер в отеле\n\
				"cBLUE"№%d", i+1);

			hotel_room[i][hotel_room_pickup_text] = CreateDynamic3DTextLabel(fmt_str, -1, hotel_room[i][hotel_room_enter_x], hotel_room[i][hotel_room_enter_y], hotel_room[i][hotel_room_enter_z], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, hotel_room[id][hotel_room_level]+100);

  			create_dynamic_area(hotel_room[i][hotel_room_enter_x], hotel_room[i][hotel_room_enter_y], hotel_room[i][hotel_room_enter_z], hotel_room[id][hotel_room_level]+100, i, HOTEL_ROOM_ENTER);
		}
		if(hotel_room[i][hotel_h_id] == HOTEL_2)
		{

			format(fmt_str, 45, "\
				Номер в отеле\n\
				"cBLUE"№%d", i+1);

			hotel_room[i][hotel_room_pickup_text] = CreateDynamic3DTextLabel(fmt_str, -1, hotel_room[i][hotel_room_enter_x], hotel_room[i][hotel_room_enter_y], hotel_room[i][hotel_room_enter_z], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, hotel_room[id][hotel_room_level]+200);


  			create_dynamic_area(hotel_room[i][hotel_room_enter_x], hotel_room[i][hotel_room_enter_y], hotel_room[i][hotel_room_enter_z], hotel_room[id][hotel_room_level]+200, i, HOTEL_ROOM_ENTER);
		}  		
		if(hotel_room[i][hotel_h_id] == HOTEL_3)
		{

			format(fmt_str, 45, "\
				Номер в отеле\n\
				"cBLUE"№%d", i+1);

			hotel_room[i][hotel_room_pickup_text] = CreateDynamic3DTextLabel(fmt_str, -1, hotel_room[i][hotel_room_enter_x], hotel_room[i][hotel_room_enter_y], hotel_room[i][hotel_room_enter_z], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, hotel_room[id][hotel_room_level]+300);

  			create_dynamic_area(hotel_room[i][hotel_room_enter_x], hotel_room[i][hotel_room_enter_y], hotel_room[i][hotel_room_enter_z], hotel_room[id][hotel_room_level]+300, i, HOTEL_ROOM_ENTER);
		}  	
		if(hotel_room[i][hotel_h_id] == HOTEL_4)
		{

			format(fmt_str, 45, "\
				Номер в отеле\n\
				"cBLUE"№%d", i+1);

			hotel_room[i][hotel_room_pickup_text] = CreateDynamic3DTextLabel(fmt_str, -1, hotel_room[i][hotel_room_enter_x], hotel_room[i][hotel_room_enter_y], hotel_room[i][hotel_room_enter_z], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, hotel_room[id][hotel_room_level]+400);

  			create_dynamic_area(hotel_room[i][hotel_room_enter_x], hotel_room[i][hotel_room_enter_y], hotel_room[i][hotel_room_enter_z], hotel_room[id][hotel_room_level]+400, i, HOTEL_ROOM_ENTER);
		}    				
		CreateDynamic3DTextLabel(""cWH"Выход из номера\n"cBLUE"[ALT]",-1, \
  		hotel_room_int_exit_coord[1][0], hotel_room_int_exit_coord[1][1], hotel_room_int_exit_coord[1][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	

  		create_dynamic_area(hotel_room_int_exit_coord[1][0], hotel_room_int_exit_coord[1][1], hotel_room_int_exit_coord[1][2], -1, i, HOTEL_ROOM_EXIT); 

  		all_hotel_room++;
	}


	//CreateDynamicPickup(19132, 23, hotel_room_int_exit_coord[1][0], hotel_room_int_exit_coord[1][1], hotel_room_int_exit_coord[1][2]);

	//create_dynamic_area(hotel_room_int_exit_coord[1][0], hotel_room_int_exit_coord[1][1], hotel_room_int_exit_coord[1][2], -1, 1, hotel_room_EXIT);

	printf("[Номера Отелей]: <%i из %i>. Времени затрачено: <%d мс>" , all_room_hotel, all_hotel_room, GetTickCount()-  time);

	return true;
}

callback:: save_hotel_room(h)
{
    static 
    	formate_str[1000];

    formate_str[0] = EOS; 

    format(formate_str, 1000, "UPDATE `hotel_room` SET \
    	hotel_room_lock = '%d',\
    	hotel_room_day = '%d',\
    	hotel_room_class = '%d',\
    	hotel_room_owned = '%d'\
    	WHERE hotel_room_id = '%d'",
    	hotel_room[h][hotel_room_lock],
    	hotel_room[h][hotel_room_day],
    	hotel_room[h][hotel_room_class],
    	hotel_room[h][hotel_room_owned],
    	hotel_room[h][hotel_room_id]);

    sql_queryEx(zConn, formate_str, QUERY_THREADED);	

    return true;
}


stock get_hotel_room_class(h)
{
	new 
		name[20],
		class = hotel_room[h][hotel_room_class];

	switch(class)
	{
		case 1: name = "Низкий";
		case 2: name = "Средний";
		case 3: name = "Высокий";
		default: name = "Заброшенный";
	}
	return name;
}

stock hotel_unrent_room(h)
{
	if(hotel_room[h][hotel_room_owned] == -1) 
		return printf("Ошибка! Номер в отеле №%d никому не принадлежит!", h);

	new 
		owner_id = hotel_room[h][hotel_room_owned];

	new 
		owner_garage_name[32];


	GetPlayerNameByID(owner_id, owner_garage_name);

	new 
		player_id = GetPlayerID(owner_garage_name);	

	if(IsPlayerConnected(player_id))
	{
		if(pData[player_id][pHotelRoom] == h)
		{	
			pData[player_id][pHotelRoom] = -1;
			UpdatePlayerData(player_id,"pHotelRoom", pData[player_id][pHotelRoom]);
			SFCM(player_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы были выселены из отеля за неуплату!");	

			pData[player_id][pSpawn] = 0;
			UpdatePlayerData(player_id, "spawn", pData[player_id][pSpawn]);

	        vehicle_destroy(player_id);
	        SendClientMessage(player_id, COLOR_LIGHTRED, "Ваша машина была отправлена на штраф-стоянку из продажи жилья!");
		}
	}
	else
	{	
		new 
			formate_str[280];

		format(formate_str, 80, "UPDATE accounts SET pHotelRoom = '-1' WHERE id = '%d'", owner_id);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	

		send_off_message(-1, owner_garage_name, "Вы были выселены из отеля за неуплату");
	}


	save_hotel_room(h);

	return true;
}

stock sell_hotel_admin(playerid, h, reason[])
{


	if(hotel_room[h][hotel_room_owned] == -1) 
		return printf("Ошибка! Номер в отеле №%d никому не принадлежит!", h);

	new 
		owner_id = hotel_room[h][hotel_room_owned];

	new 
		owner_garage_name[32];


	GetPlayerNameByID(owner_id, owner_garage_name);

	new 
		player_id = GetPlayerID(owner_garage_name);

	if(IsPlayerConnected(player_id))
	{
		if(pData[player_id][pHotelRoom] == h)
		{	
			pData[player_id][pHotelRoom] = -1;
			UpdatePlayerData(player_id,"pHotelRoom", pData[player_id][pHotelRoom]);
			SFCM(player_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Ваш номер в отеле была продана администратором. Причина: %s", reason);	

			pData[player_id][pSpawn] = 0;
			UpdatePlayerData(player_id, "spawn", pData[player_id][pSpawn]);
		}
	}
	else
	{	
		new 
			formate_str[280];

		format(formate_str, 80, "UPDATE accounts SET pHotelRoom = '-1' WHERE id = '%d'", owner_id);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	
	}


	save_hotel_room(h);

	return true;
}

stock update_pickup_hotel_room(playerid, h)
{		

	if(hotel_room[h][hotel_h_id] == 0)
	{
		DestroyDynamicPickup(hotel_room[h][hotel_room_pickup]);
		if(hotel_room[h][hotel_room_owned] == -1)
		{
			hotel_room[h][hotel_room_pickup] = CreateDynamicPickup(13731, 23, hotel_room[h][hotel_room_enter_x], hotel_room[h][hotel_room_enter_y], hotel_room[h][hotel_room_enter_z], hotel_room[h][hotel_room_level]+100);
		}
		else
		{
			hotel_room[h][hotel_room_pickup] = CreateDynamicPickup(13732, 23, hotel_room[h][hotel_room_enter_x], hotel_room[h][hotel_room_enter_y], hotel_room[h][hotel_room_enter_z], hotel_room[h][hotel_room_level]+100);
		}
	}
	if(hotel_room[h][hotel_h_id] == 1)
	{
		DestroyDynamicPickup(hotel_room[h][hotel_room_pickup]);
		if(hotel_room[h][hotel_room_owned] == -1)
		{
			hotel_room[h][hotel_room_pickup] = CreateDynamicPickup(13731, 23, hotel_room[h][hotel_room_enter_x], hotel_room[h][hotel_room_enter_y], hotel_room[h][hotel_room_enter_z], hotel_room[h][hotel_room_level]+200);
		}
		else
		{
			hotel_room[h][hotel_room_pickup] = CreateDynamicPickup(13732, 23, hotel_room[h][hotel_room_enter_x], hotel_room[h][hotel_room_enter_y], hotel_room[h][hotel_room_enter_z], hotel_room[h][hotel_room_level]+200);
		}
	}
	if(hotel_room[h][hotel_h_id] == 2)
	{
		DestroyDynamicPickup(hotel_room[h][hotel_room_pickup]);
		if(hotel_room[h][hotel_room_owned] == -1)
		{
			hotel_room[h][hotel_room_pickup] = CreateDynamicPickup(13731, 23, hotel_room[h][hotel_room_enter_x], hotel_room[h][hotel_room_enter_y], hotel_room[h][hotel_room_enter_z], hotel_room[h][hotel_room_level]+300);
		}
		else
		{
			hotel_room[h][hotel_room_pickup] = CreateDynamicPickup(13732, 23, hotel_room[h][hotel_room_enter_x], hotel_room[h][hotel_room_enter_y], hotel_room[h][hotel_room_enter_z], hotel_room[h][hotel_room_level]+300);
		}
	}
	if(hotel_room[h][hotel_h_id] == 3)
	{
		DestroyDynamicPickup(hotel_room[h][hotel_room_pickup]);
		if(hotel_room[h][hotel_room_owned] == -1)
		{
			hotel_room[h][hotel_room_pickup] = CreateDynamicPickup(13731, 23, hotel_room[h][hotel_room_enter_x], hotel_room[h][hotel_room_enter_y], hotel_room[h][hotel_room_enter_z], hotel_room[h][hotel_room_level]+400);
		}
		else
		{
			hotel_room[h][hotel_room_pickup] = CreateDynamicPickup(13732, 23, hotel_room[h][hotel_room_enter_x], hotel_room[h][hotel_room_enter_y], hotel_room[h][hotel_room_enter_z], hotel_room[h][hotel_room_level]+400);
		}
	}	
	return true;
}

stock info_hotel_room(playerid, h)
{
	static 
		fmt_str[700],
		h_class[32],
		h_owner[32];


	format(h_class, 32, "%s", get_hotel_room_class(h));

	if(hotel_room[h][hotel_room_owned] != -1)
	{
		GetPlayerNameByID(hotel_room[h][hotel_room_owned], hotel_room[h][hotel_room_owner]);
		format(h_owner, 32, hotel_room[h][hotel_room_owner]);
	}
	else
	{
		format(h_owner, 32, "Отсутствует");	
	}

	new 
		hid = GetPVarIntNew(playerid, "hotel_number_vw");


	format(fmt_str, 450, "\
	"cWH"Наименование отеля: \t\t"cBLUE"%s\n\
	"cWH"Уникальный номер:	 \t\t"cBLUE"%d\n\
	"cWH"Этаж:	 			 \t"cBLUE"%d\n\
	"cWH"Класс номера:		 \t\t"cBLUE"%s\n\
	"cWH"Владелец: 			 \t"cBLUE"%s\n\
	"cWH"Статус: 			 \t\t%s",
	hotel[hid][hotel_name],
	h+1,
	hotel_room[h][hotel_room_level],
	h_class,
	h_owner,
	(hotel_room[h][hotel_room_lock]) ? (""cGR"Открыт") : (""cLRED"Закрыт"));
	SPD(playerid, DIALOG_ENTER_HOTEL_ROOM, DIALOG_STYLE_MSGBOX, !""cBLUE"Номер в отеле", fmt_str, !"Войти", !"Закрыть");	




	return true;
}

stock enter_hotel_room(playerid, h)
{
	if(h == -1) 
		return true;

	new 
		hs = GetPVarIntNew(playerid, "hotel_number_vw");

	new 
		class = hotel[hs][hotel_class];

	if(hotel_room[h][hotel_room_lock] == 2)
	{
		GameTextForPlayer(playerid, "~r~closed", 2000, 3);
		return SendErr(playerid, "Номер в отель закрыт!");
	}

	if(opcode)
	{
		FormattedMessage(playerid, -1, "[debug] area_enter_hotel_room: %d", h);
	}

	SetPVarIntNew(playerid, "hotel_room_id_enter", h);

	SetPVarIntNew(playerid, "number_hotel_id", h);

	h = h+playerid;

	SetPlayerPosEx(playerid, hotel_room_int_coord[class][0], hotel_room_int_coord[class][1], hotel_room_int_coord[class][2], hotel_room_int_coord[class][3]);
	SetPlayerVirtualWorld(playerid, h);
	return true;
}

stock exit_hotel_room(playerid, h)
{
	if(h == -1) 
		return true;

	if(opcode) FormattedMessage(playerid, -1, "[debug] area_exit_hotel_room: %d", h);

	new 
		vw;
 
	if(hotel_room[h][hotel_h_id] == HOTEL_1)
	{
		vw = hotel_room[h][hotel_room_level]+100;
	}
	if(hotel_room[h][hotel_h_id] == HOTEL_2)
	{
		vw = hotel_room[h][hotel_room_level]+200;
	}
	if(hotel_room[h][hotel_h_id] == HOTEL_3)
	{
		vw = hotel_room[h][hotel_room_level]+300;
	}
	if(hotel_room[h][hotel_h_id] == HOTEL_4)
	{
		vw = hotel_room[h][hotel_room_level]+400;
	}

	DeletePVarNew(playerid, "hotel_room_id_enter");


	SetPlayerPosEx(playerid, hotel_room[h][hotel_room_enter_x], hotel_room[h][hotel_room_enter_y], hotel_room[h][hotel_room_enter_z], 2);
	SetPlayerVirtualWorld(playerid, vw);
	return true;
}

CMD:addhroom(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    new 
    	Float:x,Float:y,Float:z;

    if(sscanf(params, "ddd", params[0], params[1], params[2]))
    {
    	SendInf(playerid, "Используйте: /addhroom [Класс] [Этаж] [Отель от 0 до 2]");
    	SendInf(playerid, "1 - Низкий | 2 - Средний | 3 - Высокий");
    	return true;
    }

    if(params[0] < 1 || params[0] > 4) 
    	return SendInf(playerid, "1 - Низкий | 2 - Средний | 3 - Высокий");

    GetPlayerPos(playerid, x, y, z);
    
	static 
		formate_str[310];

    format(formate_str, 310, "INSERT INTO hotel_room(hotel_room_enter_x, hotel_room_enter_y, hotel_room_enter_z, hotel_room_exit_x, hotel_room_exit_y, hotel_room_exit_z, hotel_level, hotel_room_class, hotel_id) VALUES ('%f','%f','%f','%f','%f','%f','%d','%d','%d')",
    x, y, z, x, y, z, params[1], params[0], params[2]);
    sql_queryEx(zConn, formate_str, QUERY_THREADED);	

    formate_str[0] = EOS;

    SendSucc(playerid, "Вы добавили номер в отеле! Он появится после рестарта!");
	return true;
}


CMD:asellhotelroom(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    if(sscanf(params, "ds[32]",params[0],params[1])) 
    	return SendInf(playerid, "Используйте: /asellhotel [ID отеля] [Причина]");


	new 
		fmt_str[350];

    format(fmt_str, sizeof(fmt_str), "Вы успешно продали отель №%d", params[0]);
    SendSucc(playerid, fmt_str);

	sell_hotel_admin(playerid, params[0], params[1]);

	return true;
}



/*


INSERT INTO `hotel_room` (`hotel_id`, `hotel_level`, `hotel_room_class`, `hotel_room_owned`, `hotel_room_lock`, `hotel_room_day`, `hotel_room_enter_x`, `hotel_room_enter_y`, `hotel_room_enter_z`, `hotel_room_exit_x`, `hotel_room_exit_y`, `hotel_room_exit_z`) VALUES
(0, 10, 1, -1, 1, 0, -1889.15, 1983.39, 1165.46, -1889.15, 1983.39, 1165.46),
(0, 10, 1, -1, 1, 0, -1889.14, 1980.82, 1165.46, -1889.14, 1980.82, 1165.46),
(0, 10, 1, -1, 1, 0, -1889.15, 1978.25, 1165.46, -1889.15, 1978.25, 1165.46),
(0, 10, 1, -1, 1, 0, -1889.14, 1975.71, 1165.46, -1889.14, 1975.71, 1165.46),
(0, 10, 1, -1, 1, 0, -1889.15, 1973.14, 1165.46, -1889.15, 1973.14, 1165.46),
(0, 10, 1, -1, 1, 0, -1889.14, 1970.56, 1165.46, -1889.14, 1970.56, 1165.46),
(0, 10, 1, -1, 1, 0, -1884.6, 1983.38, 1165.46, -1884.6, 1983.38, 1165.46),
(0, 10, 1, -1, 1, 0, -1884.6, 1980.79, 1165.46, -1884.6, 1980.79, 1165.46),
(0, 10, 1, -1, 1, 0, -1884.6, 1978.26, 1165.46, -1884.6, 1978.26, 1165.46),
(0, 10, 1, -1, 1, 0, -1884.6, 1975.64, 1165.46, -1884.6, 1975.64, 1165.46),
(0, 10, 1, -1, 1, 0, -1884.6, 1973.13, 1165.46, -1884.6, 1973.13, 1165.46),
(0, 10, 1, -1, 1, 0, -1884.6, 1970.5, 1165.46, -1884.6, 1970.5, 1165.46);


*/