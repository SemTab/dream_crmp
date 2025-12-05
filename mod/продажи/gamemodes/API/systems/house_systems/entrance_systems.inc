
#define MAX_APART 				400
#define MAX_ENTRANCE			100
	
#define CLASS_ENTRANCE_LOW		1
#define CLASS_ENTRANCE_MEDIUM	2
#define CLASS_ENTRANCE_HIGH		3


new Float:apartament_int_exit_coord[][] = 
{

	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0}
};

new Float:entrance_int_exit_coord[][] = 
{

	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0}
};

new Float:elevator_entrance_int_exit_coord_l[][] = 
{

	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0}
};

new Float:elevator_entrance_int_enter_coord_l[][] = 
{

	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0}
};

new Float:elevator_entrance_int_exit_coord_m[][] = 
{

	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0}
};

new Float:elevator_entrance_int_enter_coord_m[][] = 
{

	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0}
};

new Float:elevator_entrance_int_exit_coord_h[][] = 
{

	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0}
};

new Float:elevator_entrance_int_enter_coord_h[][] = 
{

	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0, 0.0}
};

enum apartament_data
{
	apartament_id,
	apartament_owned,
	apartament_owner[24],
	Float:apartament_enter_x,
	Float:apartament_enter_y,
	Float:apartament_enter_z,
	Float:apartament_exit_x,
	Float:apartament_exit_y,
	Float:apartament_exit_z,
	Float:apartament_veh_x,
	Float:apartament_veh_y,
	Float:apartament_veh_z,
	Float:apartament_veh_a,
	apartament_class,
	apartament_price,
	apartament_lock,
	apartament_days,
	apartament_pickup
};

new 
	apartament[MAX_APART][apartament_data];


enum entrance_data
{
	entrance_id,
	entrance_name[24],
	entrance_class,
	Float:entrance_enter_x,
	Float:entrance_enter_y,
	Float:entrance_enter_z,
	Float:entrance_exit_x,
	Float:entrance_exit_y,
	Float:entrance_exit_z

}

new 
	entrance[MAX_ENTRANCE][apartament_data];

forward load_all_entrance();
public load_all_entrance()
{
    new 
    	time = GetTickCount(), rows;
    cache_get_row_count(rows);

    if(rows)
    {
        for(new idx; idx < rows; idx++)
        {
        	all_entrance++;
			load_apartament(idx);
        }
    }

    AddDynamicZone(apartament_int_exit_coord[1][0], apartament_int_exit_coord[1][1], apartament_int_exit_coord[1][2], -1, -1, APARTAMENT_EXIT);
    AddDynamicZone(apartament_int_exit_coord[2][0], apartament_int_exit_coord[2][1], apartament_int_exit_coord[2][2], -1, -1, APARTAMENT_EXIT);


    printf("[Подъезды]: <%i из %i>. Потрачено: <%i мс>" ,all_entrance, rows, GetTickCount()-  time);
    return 1;
}

forward load_entrance(a);
public load_entrance(a)
{

	cache_get_value_name_int(a,		"id", 			entrance[all_entrance][entrance_id]);
	cache_get_value_name(a, 		"owner",		entrance[all_entrance][entrance_owner], 24);
	cache_get_value_name_int(a,		"class", 		entrance[all_entrance][entrance_class]);
	cache_get_value_name_float(a,	"enter_x", 		entrance[all_entrance][entrance_enter_x]);
	cache_get_value_name_float(a,	"enter_y", 		entrance[all_entrance][entrance_enter_y]);
	cache_get_value_name_float(a,	"enter_z", 		entrance[all_entrance][entrance_enter_z]);
	cache_get_value_name_float(a,	"exit_x", 		entrance[all_entrance][entrance_exit_x]);
	cache_get_value_name_float(a,	"exit_y", 		entrance[all_entrance][entrance_exit_y]);
	cache_get_value_name_float(a,	"exit_z", 		entrance[all_entrance][entrance_exit_z]);
	
	AddDynamicZone(entrance[all_entrance][entrance_enter_x], entrance[all_entrance][entrance_enter_y], entrance[all_entrance][entrance_enter_z], -1, all_entrance, APARTAMENT_ENTER);
	
	if(!entrance[all_entrance][entrance_owned])
	{
		entrance[all_entrance][entrance_pickup] = 
			CreateDynamicPickup(1273, 23, entrance[all_entrance][entrance_enter_x], entrance[all_entrance][entrance_enter_y], 
				entrance[all_entrance][entrance_enter_z]);
	}
	else
	{
		entrance[all_entrance][entrance_pickup] = 
			CreateDynamicPickup(1272, 23, entrance[all_entrance][entrance_enter_x], entrance[all_entrance][entrance_enter_y], 
				entrance[all_entrance][entrance_enter_z],-1);

	}
	return 1;
}


forward load_all_apartaments();
public load_all_apartaments()
{
    new 
    	time = GetTickCount(), rows;
    cache_get_row_count(rows);

    if(rows)
    {
        for(new idx; idx < rows; idx++)
        {
        	all_apartaments++;
			load_apartament(idx);
        }
    }

    AddDynamicZone(apartament_int_exit_coord[1][0], apartament_int_exit_coord[1][1], apartament_int_exit_coord[1][2], -1, -1, APARTAMENT_EXIT);
    AddDynamicZone(apartament_int_exit_coord[2][0], apartament_int_exit_coord[2][1], apartament_int_exit_coord[2][2], -1, -1, APARTAMENT_EXIT);


    printf("[Квартиры]: <%i из %i>. Потрачено: <%i мс>" ,all_apartaments, rows, GetTickCount()-  time);
    return 1;
}

forward load_apartament(a);
public load_apartament(a)
{

	cache_get_value_name_int(a,		"id", 			apartament[all_apartaments][apartament_id]);
	cache_get_value_name(a, 		"owner",		apartament[all_apartaments][apartament_owner], 24);
	cache_get_value_name_int(a,		"owned", 		apartament[all_apartaments][apartament_owned]);
	cache_get_value_name_int(a,		"class", 		apartament[all_apartaments][apartament_class]);
	cache_get_value_name_int(a,		"price", 		apartament[all_apartaments][apartament_price]);
	cache_get_value_name_float(a,	"enter_x", 		apartament[all_apartaments][apartament_enter_x]);
	cache_get_value_name_float(a,	"enter_y", 		apartament[all_apartaments][apartament_enter_y]);
	cache_get_value_name_float(a,	"enter_z", 		apartament[all_apartaments][apartament_enter_z]);
	cache_get_value_name_int(a,		"lock_status", 	apartament[all_apartaments][apartament_lock]);
	cache_get_value_name_float(a,	"exit_x", 		apartament[all_apartaments][apartament_exit_x]);
	cache_get_value_name_float(a,	"exit_y", 		apartament[all_apartaments][apartament_exit_y]);
	cache_get_value_name_float(a,	"exit_z", 		apartament[all_apartaments][apartament_exit_z]);
	cache_get_value_name_int(a,		"days_payed", 	apartament[all_apartaments][apartament_days]);
	cache_get_value_name_float(a,	"vehicle_x", 	apartament[all_apartaments][apartament_veh_x]);
	cache_get_value_name_float(a,	"vehicle_y", 	apartament[all_apartaments][apartament_veh_y]);
	cache_get_value_name_float(a,	"vehicle_z", 	apartament[all_apartaments][apartament_veh_z]);
	cache_get_value_name_float(a,	"vehicle_a", 	apartament[all_apartaments][apartament_veh_a]);
	
	AddDynamicZone(apartament[all_apartaments][apartament_enter_x], apartament[all_apartaments][apartament_enter_y], apartament[all_apartaments][apartament_enter_z], -1, all_apartaments, APARTAMENT_ENTER);
	
	if(!apartament[all_apartaments][apartament_owned])
	{
		apartament[all_apartaments][apartament_pickup] = 
			CreateDynamicPickup(1273, 23, apartament[all_apartaments][apartament_enter_x], apartament[all_apartaments][apartament_enter_y], 
				apartament[all_apartaments][apartament_enter_z]);
	}
	else
	{
		apartament[all_apartaments][apartament_pickup] = 
			CreateDynamicPickup(1272, 23, apartament[all_apartaments][apartament_enter_x], apartament[all_apartaments][apartament_enter_y], 
				apartament[all_apartaments][apartament_enter_z],-1);

	}
	return 1;
}

forward save_apartament(a);
public save_apartament(a)
{
    static 
    	formate_str[1000], apartament_owners[29];
    	
    formate_str[0] = EOS; 

    mysql_format(connect_mysql, apartament_owners, 29, "%e" , apartament[a][apartament_owner]);

    format(formate_str, 600, "UPDATE `apartaments` SET \
    	owned = '%d',\
    	owner = '%s',\
    	price = '%d',\
    	lock_status = '%d',\
    	days_payed = '%d',\
    	class = '%d'\
    	WHERE id = '%d'",
    	apartament[a][apartament_owned],
    	apartament[a][apartament_owner],
    	apartament[a][apartament_price],
    	apartament[a][apartament_lock],
    	apartament[a][apartament_days],
    	apartament[a][apartament_class],
    	apartament[a][apartament_id]);

    mysql_pquery(connect_mysql, formate_str);
    return true;
}

forward save_entrance(a);
public save_entrance(a)
{
    static 
    	formate_str[1000], entrance_name[29];

    formate_str[0] = EOS; 

    mysql_format(connect_mysql, entrance_name, 29, "%e" , entrance[a][entrance_name]);

    format(formate_str, 600, "UPDATE `apartaments_entrance` SET \
    	name = '%s',\
    	class = '%d'\
    	WHERE id = '%d'",
    	entrance[a][entrance_name],
    	entrance[a][entrance_class],
    	entrance[a][entrance_id]);

    mysql_pquery(connect_mysql, formate_str);
    return true;
}


forward sell_apartament(a, reason);
public sell_apartament(a, reason)
{
	if(!apartament[a][apartament_owned]) 
		return printf("Ошибка! Квартира №%d никому не принадлежит!", a);

	new 
		price = floatround(apartament[a][apartament_price]*APARTAMENT_SELL_PRICE_DEFAULT),
		owner_id = GetPlayerID(apartament[a][apartament_owner]);

	if(player_connected(owner_id))
	{
		player[owner_id][apartament] = 0;
		SCMF(owner_id, COLOR_LBLUE, "Государство: "cWH"Ваш дом №%d был продан государству за "cBLUE"$%d%s", a, price, (reason == SELL_PLAYER)?(""):(" "cWH"Причина: Неуплата"));
	}
	else
	{	
		new 
			formate_str[80];

		format(formate_str, 80, "UPDATE users_data SET apartament = '0' WHERE apartament = '%d'", a);
		mysql_pquery(connect_mysql, formate_str);

	}


   	apartament[a][apartament_owned] = 0;
    apartament[a][apartament_lock] = 0;
    
    apartament[a][apartament_class] = 1;
    apartament[a][apartament_days] = 3;

    format(apartament[a][apartament_owner], 24, "None");
    update_apartament_pickup(a);
    save_apartament(a);

    return true;
}

stock update_apartament_pickup(a)
{
    DestroyDynamicPickup(apartament[a][apartament_pickup]);

    if(!apartament[a][apartament_owned])
    {
        apartament[a][apartament_pickup] = 
        	CreateDynamicPickup(1273, 23, apartament[a][apartament_enter_x], apartament[a][apartament_enter_y], apartament[a][apartament_enter_z], -1);

    }
    else
    {
        apartament[a][apartament_pickup] = 
        CreateDynamicPickup(1272, 23, apartament[a][apartament_enter_x], apartament[a][apartament_enter_y], apartament[a][apartament_enter_z],-1);
    }
}

stock update_entrance_pickup(a)
{
    DestroyDynamicPickup(entrance[a][entrance_pickup]);

    entrance[a][entrance_pickup] = 
    CreateDynamicPickup(1272, 23, entrance[a][entrance_enter_x], entrance[a][entrance_enter_y], entrance[a][entrance_enter_z],-1);
}

stock get_apartament_class(a)
{
	new 
		name[20],
		class = apartament[a][apartament_class];

	switch(class){
		case 1: name = "Отсутствует";
		case 2: name = "Средний";
		case 3: name = "Высокий";
		case 4: name = "Люкс";
		default: name = "Заброшенный";
	}
	return name;
}

stock get_entrance_class(a)
{
	new 
		name[20],
		class = entrance[a][entrance_class];

	switch(class){
		case 1: name = "Отсутствует";
		case 2: name = "Средний";
		case 3: name = "Высокий";
		case 4: name = "Люкс";
		default: name = "Заброшенный";
	}
	return name;
}

stock enter_apartament(playerid, a)
{
	if(!a) 
		return true;

	if(apartament[a][apartament_lock]) 
			return SCM(playerid, COLOR_BLUE, !"Ошибка: "cWH"Дверь квартиры закрыта");

	new 
		class = apartament[a][apartament_class];

	SetPlayerPosEx(playerid, apartament_int_exit_coord[class][0], apartament_int_exit_coord[class][1], apartament_int_exit_coord[class][2], 
		apartament_int_exit_coord[class][3], 3);

	SetPlayerVirtualWorld(playerid, a);

	return true;
}

stock enter_entrance(playerid, e)
{
	if(!e) 
		return true;

	new 
		class = entrance[e][entrance_class];

	SetPlayerPosEx(playerid, entrance_int_exit_coord[class][0], entrance_int_exit_coord[class][1], entrance_int_exit_coord[class][2], 
		entrance_int_exit_coord[class][3], 3);

	SetPlayerVirtualWorld(playerid, a);

	return true;
}


stock exit_apartament(playerid, a)
{
	if(!a) 
		return true;

	SetPlayerPosEx(playerid, apartament[a][apartament_enter_x], apartament[a][apartament_enter_y], apartament[a][apartament_enter_z], 2);
	SetPlayerVirtualWorld(playerid, 0);
	return true;
}


stock exit_entrance(playerid, a)
{
	if(!a) 
		return true;

	SetPlayerPosEx(playerid, entrance[a][entrance_enter_x], entrance[a][entrance_enter_y], entrance[a][entrance_enter_z], 2);
	SetPlayerVirtualWorld(playerid, 0);
	return true;
}


stock buy_apartament(playerid, a)
{

	if(player[playerid][cash] < apartament[a][apartament_price]) 
		return NoMoney(playerid);

	apartament[a][apartament_owned] = 1;
	format(apartament[a][apartament_owner], 24, player[playerid][nickname]);

	apartament[a][apartament_days] = 3;
	apartament[a][apartament_lock] = 1;
	player[playerid][apartament] = a;

	update_apartament_pickup(a);
	save_apartament(a);

	return true;

}

stock cancel_sell_apartament_to_player(playerid)
{
	

	//TODO 

	//	Тут будет продажа по команде или клавише, хер его знает

	return true;
}

stock elevator_apartament(playerid, type_elevator)
{

	switch(type_elevator)
	{
		case CLASS_ENTRANCE_LOW:
		{
			//TODO

			// В ДУШЕ НЕ ЗНАЮ ЧТО БУДЕТ ДИАЛОГ ИЛИ ТД
		}
		case CLASS_ENTRANCE_MEDIUM:
		{
			// В ДУШЕ НЕ ЗНАЮ ЧТО БУДЕТ ДИАЛОГ ИЛИ ТД

		}
		case CLASS_ENTRANCE_HIGH:
		{
			// В ДУШЕ НЕ ЗНАЮ ЧТО БУДЕТ ДИАЛОГ ИЛИ ТД

		}
	}

	return true;
}

cmd:add_entrance(playerid, params[]) 
{	

	if(player[playerid][admin_level] < 5) 
		return NoCMD(playerid);
    new 
    	Float:x,Float:y,Float:z;

    if(sscanf(params, "d",params[0]))
    {
    	SCM(playerid, COLOR_BLUE, !"Подсказка: \
    		"cWH"Используйте: /add_entrance [Класс подъезда]");
    }

	GetPlayerPos(playerid, x, y, z);

	static 
		format_str[300];

    format(format_str, 300, "INSERT INTO apartaments_entrance(enter_x, enter_y, enter_z, class) \
     VALUES ('%f','%f','%f','%d')", x, y, z, params[0]);
    mysql_query(connect_mysql, format_str);

    format_str[0] = EOS;


    SCM(playerid, COLOR_BLUE, !"Подсказка: "cWH"Вы успешно создали новый подъезд");

	return true;

}

cmd:set_entrance(playerid, params[]) 
{	

	if(player[playerid][admin_level] < 5) 
		return NoCMD(playerid);

    new 
    	id_entrance, type, count[24];


    if(sscanf(params, "dds[24]", id_entrance, type, count))
    {
    	SCM(playerid, COLOR_BLUE, !"Подсказка: \
    		"cWH"Используйте: /set_entrance [ID Квартиры] [Тип] [Значение]");

    	SCM(playerid, COLOR_BLUE, !"Подсказка: \
    		"cWH"[1] Изменить наименование [2] Изменить класс");
    }

    switch(type) 
    {

    	case 0: bicyle_rent[id_entrance][entrance_name] = count, \
    		SCMF(playerid, COLOR_BLUE, "Информация: "cWH"Подъезду установлено"cBLUE"название"cWH" на "cBLUE"%s"cWH" аккаунт", count);

    	case 1: bicyle_rent[id_entrance][entrance_class] = count, \
    		SCMF(playerid, COLOR_BLUE, "Информация: "cWH"Подъезду установлен"cBLUE"класс"cWH" на "cBLUE"%d"cWH"", count);

    }

	save_entrance(id_entrance);

	return true;

}

cmd:add_apartament(playerid, params[]) 
{	

	if(player[playerid][admin_level] < 5) 
		return NoCMD(playerid);

    new 
    	Float:x,Float:y,Float:z;

    if(sscanf(params, "dd",params[0], params[1]))
    {
    	SCM(playerid, COLOR_BLUE, !"Подсказка: \
    		"cWH"Используйте: /add_apartament [Класс подъезда] [Цена продажи]");
    }

	GetPlayerPos(playerid, x, y, z);

	static 
		format_str[300];

    format(format_str, 300, "INSERT INTO apartaments(enter_x, enter_y, enter_z, class, price) \
     VALUES ('%f','%f','%f','%d')", x, y, z, params[0], params[1]);
    mysql_query(connect_mysql, format_str);


    format_str[0] = EOS;


    SCM(playerid, COLOR_BLUE, !"Подсказка: "cWH"Вы успешно создали новую квартиру");

	return true;

}

