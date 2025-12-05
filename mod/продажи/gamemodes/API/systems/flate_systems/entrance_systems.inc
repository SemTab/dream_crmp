

new 
	actor_padik[4];

callback:: load_entrance_all()
{
	new Result:flate_player = sql_queryEx(zConn, "SELECT * FROM `entrance` ORDER BY `entrance_id`", QUERY_CACHED);

	new all_apartament_load = sql_num_rows(flate_player);

	new time = GetTickCount();

 	for(new i; i < all_apartament_load; i++)
	{
		apartament[i][apartament_id]  = sql_get_field_assoc_int_ex(flate_player, i, "entrance_id"); 

		apartament[i][apartament_class]  = sql_get_field_assoc_int_ex(flate_player, i, "entrance_class"); 
		apartament[i][apartament_lock]  = sql_get_field_assoc_int_ex(flate_player, i, "entrance_lock"); 

  		apartament[i][apartament_enter_x] = sql_get_field_assoc_float_ex(flate_player, i, "entrance_pos_x");
  		apartament[i][apartament_enter_y] = sql_get_field_assoc_float_ex(flate_player, i, "entrance_pos_y");
  		apartament[i][apartament_enter_z] = sql_get_field_assoc_float_ex(flate_player, i, "entrance_pos_z");

  		apartament[i][apartament_exit_x] = sql_get_field_assoc_float_ex(flate_player, i, "entrance_exit_x");
  		apartament[i][apartament_exit_y] = sql_get_field_assoc_float_ex(flate_player, i, "entrance_exit_y");
  		apartament[i][apartament_exit_z] = sql_get_field_assoc_float_ex(flate_player, i, "entrance_exit_z");


		create_dynamic_area(apartament[i][apartament_enter_x], apartament[i][apartament_enter_y], apartament[i][apartament_enter_z], -1, i , APARTAMENT_ENTER, 1.5);

		create_dynamic_area(apartaments_exit_coord[1][0], apartaments_exit_coord[1][1], apartaments_exit_coord[1][2], i, i, APARTAMENT_EXIT, 1.5);



		apartament[i][apartament_pickup] = CreateDynamicPickup(13733, 23, apartament[i][apartament_enter_x], apartament[i][apartament_enter_y], apartament[i][apartament_enter_z], -1, -1, -1, STREAM_DISTANCE_DYNAMIC_PICKUP);
		apartament[i][apartament_map_icon] = CreateDynamicMapIcon(apartament[i][apartament_enter_x], apartament[i][apartament_enter_y], apartament[i][apartament_enter_z], 40, COLOR_WHITE, 0, -1, -1, 100.0);

		new 
			fmt_str[45];

		format(fmt_str, 45, "\
			Подъезд дома\n\
			"cBLUE"№%d\n\
			"cWH"[ALT]", i+1);

		apartament[i][apartament_3dtext] = CreateDynamic3DTextLabel(fmt_str, -1, apartament[i][apartament_enter_x], apartament[i][apartament_enter_y], apartament[i][apartament_enter_z], 5.0);



  		all_apartaments++;
	}

	CreateDynamic3DTextLabel(""cWH"Выход из подъезда\n"cBLUE"[ALT]",-1, \
	apartaments_exit_coord[1][0], apartaments_exit_coord[1][1], apartaments_exit_coord[1][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	


	CreateDynamicPickup(13702, 23, apartaments_exit_coord[1][0], apartaments_exit_coord[1][1], apartaments_exit_coord[1][2], -1, -1, -1, STREAM_DISTANCE_DYNAMIC_PICKUP);

	printf("[Подъезды]: <%i из %i>. Времени затрачено: <%d мс>" ,all_apartament_load, all_apartaments, GetTickCount()-  time);

	return true;
}

callback:: save_entrance(h)
{
    static 
    	formate_str[300];

    formate_str[0] = EOS; 

    format(formate_str, 300, "UPDATE `entrance` SET \
    	entrance_class = '%d',\
    	entrance_lock = '%d'\
    	WHERE entrance_id = '%d'",
		apartament[h][apartament_id],
		apartament[h][apartament_class],
		apartament[h][apartament_lock]);

    sql_queryEx(zConn, formate_str, QUERY_THREADED);	

    return true;
}


stock get_apartament_class(h)
{
	new 
		name[20],
		class = apartament[h][apartament_class];

	switch(class)
	{
		case 1: name = "Низкий";
		case 2: name = "Средний";
		case 3: name = "Высокий";
		case 4: name = "Особняк";
		default: name = "Заброшенный";
	}
	return name;
}

stock enter_apartament(playerid, h)
{
	if(h == -1) 
		return true;


	SetPlayerPosEx(playerid, -1460.5315,-801.0299,14.0578,89.9754);


	h = h+1;

	if(opcode) FormattedMessage(playerid, -1, "[debug] area_enter_apartament: %d", h);

	timer_key_state_change[playerid] += 3;

	SetPVarIntNew(playerid, "entrance_enter_id_vw", h);

	SetPlayerVirtualWorld(playerid, h);
	return true;
}

stock exit_apartament(playerid, h)
{
	if(h == -1) 
		return true;

	if(opcode) FormattedMessage(playerid, -1, "[debug] area_exit_apartament: %d", h);

	timer_key_state_change[playerid] += 3;

	SetPlayerPosEx(playerid, apartament[h][apartament_enter_x], apartament[h][apartament_enter_y], apartament[h][apartament_enter_z], 90.0);
	SetPlayerVirtualWorld(playerid, 0);

	DeletePVarNew(playerid, "entrance_enter_id_vw");

	return true;
}


CMD:addapartament(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    new 
    	Float:x,Float:y,Float:z;

    if(sscanf(params, "d",params[0])) 
    	return SendInf(playerid, "Используйте: /addapartament [Класс]");

    if(params[0] < 1 || params[0] > 4) 
    	return SendInf(playerid, "1 - Низкий | 2 - Средний | 3 - Высокий | 4 - Особняк");

    GetPlayerPos(playerid, x, y, z);
    
	static 
		formate_str[310];

    format(formate_str, 310, "INSERT INTO entrance(entrance_pos_x, entrance_pos_y, entrance_pos_z, entrance_exit_x, entrance_exit_y, entrance_exit_z, entrance_class) VALUES ('%f','%f','%f','%f','%f','%f','%d')",
    x, y, z, x, y, z, params[0]);
    sql_queryEx(zConn, formate_str, QUERY_THREADED);	

    formate_str[0] = EOS;

    SendSucc(playerid, "Вы добавили подъезд! Он появится после рестарта");
	return true;
}

CMD:gotoapart(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

	if(sscanf(params, "d", params[0]))
	{
		SendInf(playerid, "Используйте: /gotoapart "cWH"[ID Подъезда]");
		return true;
	}

	new 
		id_flate = params[0];


	SetPlayerPos(playerid, apartament[id_flate][apartament_enter_x], apartament[id_flate][apartament_enter_y], apartament[id_flate][apartament_enter_z]);

	new 
		fmt_str[144];

    format(fmt_str, sizeof(fmt_str), "Вы телепортировались к подъезду №%d", id_flate);
    SendInf(playerid, fmt_str);
	return true;
}

CMD:delapart(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    if(sscanf(params, "d",params[0])) 
    	return SendInf(playerid, "Используйте: /delapart [ID подъезда]");

	static 
		formate_str[250];

    format(formate_str, 250, "DELETE FROM `entrance` WHERE `entrance_id` = '%d'", params[0]);
    sql_queryEx(zConn, formate_str, QUERY_THREADED);	

	new 
		fmt_str[350];

    format(fmt_str, sizeof(fmt_str), "Вы успешно удалили подъезд №%d", params[0]);
    SendSucc(playerid, fmt_str);
	return true;
}

CMD:aeditapart(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

	new 
		type, count, flate_ids;

	new 
		fmt_str[350];

	if(sscanf(params, "ddd", flate_ids, type, count))
	{
		SendInf(playerid, "Используйте:/aeditapart "cWH"[ID подъезда] "cORANGE"[Тип] "cWH"[Значение]");
		SendInf(playerid, "[1] Класс подъезда");
		return true;
	}

	switch(type)
	{
		case 1: 
		{
			apartament[flate_ids][apartament_class] = count;
		    format(fmt_str, sizeof(fmt_str), "Класс подъезда был обновлен! Подъезд: №%d | Класс: %s", flate_ids, get_apartament_class(flate_ids));
		    SendSucc(playerid, fmt_str);

		}
	}

	return true;
}
