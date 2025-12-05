

static const mechanic_rank_name[][] =
{	
	"Отсутствует",
    "Механик",
    "Управляющий",
    "Владелец",
    "Рак Заморский"
};

static const mounth_mech_stats[][] =
{	
	"ВЫ ЧЕ",
    "январь",
    "февраль",
    "март",
    "апрель",
    "май",
    "июнь",
    "июль",
    "августа",
    "сентябрь",
    "октябрь",
    "ноябрь",
    "декабрь"
};


static const Float:position_spawn_mech_1[][] =
{

	{2044.1844,1867.4164,15.4161,270.5581},
	{2043.5500,1870.7990,15.4266,268.7204},
	{2043.5393,1874.3102,15.4163,269.0868},
	{2043.5381,1878.1014,15.4249,269.8997},
	{2043.5303,1881.5721,15.4252,269.5935}


};


static const Float:position_spawn_mech_2[][] =
{
	{2129.2551,-1819.8823,18.6920,178.7286},
	{2128.5679,-1841.4126,18.6975,270.3401},
	{2128.5959,-1845.0490,18.6977,270.9528},
	{2128.5964,-1848.4065,18.6931,271.5446},
	{2128.4932,-1852.0287,18.6997,270.0626},
	{2148.4629,-1831.6295,18.6949,92.1879},
	{2159.1621,-1831.2201,18.6991,92.1878}
};

static const Float:position_spawn_mech_3[][] =
{
	{379.4046,783.6772,11.9368,249.7996},
	{380.6629,787.3260,11.9304,251.2191},
	{381.8946,790.8366,11.9352,251.5054},
	{383.1083,794.3205,11.9328,251.3821},
	{384.2678,797.7054,11.9515,250.4143}
};


callback:: load_mechanic_server()
{

	new Result:buisness_mechanic = sql_queryEx(zConn, "SELECT * FROM `mechanic` ORDER BY `id`", QUERY_CACHED);

	new all_mechanic_station = sql_num_rows(buisness_mechanic);

	new time = GetTickCount();

	new 
		load_mechanic; 

 	for(new i; i < all_mechanic_station; i++)
	{

		mechanic[i][mechanic_base_id]  = sql_get_field_assoc_int_ex(buisness_mechanic, i, "id"); 


		sql_get_field_assoc_ex(buisness_mechanic, i,"mechanic_base_name", mechanic[i][mechanic_base_name], 20);
		sql_get_field_assoc_ex(buisness_mechanic, i,"owner_name", mechanic[i][mechanic_base_owner], 32);

		mechanic[i][mechanic_base_owner_id]  = sql_get_field_assoc_int_ex(buisness_mechanic, i, "owner_id"); 

		mechanic[i][mechanic_base_price]  = sql_get_field_assoc_int_ex(buisness_mechanic, i, "mechanic_base_price"); 
		mechanic[i][mechanic_base_closed]  = sql_get_field_assoc_int_ex(buisness_mechanic, i, "mechanic_base_closed"); 
		mechanic[i][mechanic_base_days]  = sql_get_field_assoc_int_ex(buisness_mechanic, i, "mechanic_base_days"); 
		mechanic[i][mechanic_base_bank]  = sql_get_field_assoc_int_ex(buisness_mechanic, i, "mechanic_base_bank"); 	

		mechanic[i][mechanic_base_percent]  = sql_get_field_assoc_int_ex(buisness_mechanic, i, "mechanic_base_percent"); 	
		mechanic[i][mechanic_base_phone]  = sql_get_field_assoc_int_ex(buisness_mechanic, i, "mechanic_base_phone"); 	

		mechanic[i][mechanic_base_finka_day]  = sql_get_field_assoc_int_ex(buisness_mechanic, i, "mechanic_base_finka_day"); 	
		mechanic[i][mechanic_base_finka_ogran]  = sql_get_field_assoc_int_ex(buisness_mechanic, i, "mechanic_base_finka_ogran"); 	

  		mechanic[i][mechanic_pos_x] = sql_get_field_assoc_float_ex(buisness_mechanic, i, "mechanic_pos_x");
  		mechanic[i][mechanic_pos_y] = sql_get_field_assoc_float_ex(buisness_mechanic, i, "mechanic_pos_y");
  		mechanic[i][mechanic_pos_z] = sql_get_field_assoc_float_ex(buisness_mechanic, i, "mechanic_pos_z");

		mechanic[i][mechanic_price_remont]  = sql_get_field_assoc_int_ex(buisness_mechanic, i, "mechanic_price_rem"); 
		mechanic[i][mechanic_price_fuel]  = sql_get_field_assoc_int_ex(buisness_mechanic, i, "mechanic_price_fuel"); 
		mechanic[i][mechanic_price_oil]  = sql_get_field_assoc_int_ex(buisness_mechanic, i, "mechanic_price_oil"); 
		mechanic[i][mechanic_price_candles]  = sql_get_field_assoc_int_ex(buisness_mechanic, i, "mechanic_price_candles"); 	
		mechanic[i][mechanic_price_brake]  = sql_get_field_assoc_int_ex(buisness_mechanic, i, "mechanic_price_brake"); 
		mechanic[i][mechanic_price_belt]  = sql_get_field_assoc_int_ex(buisness_mechanic, i, "mechanic_price_belt"); 
		mechanic[i][mechanic_price_starter]  = sql_get_field_assoc_int_ex(buisness_mechanic, i, "mechanic_price_starter"); 
		mechanic[i][mechanic_price_generator]  = sql_get_field_assoc_int_ex(buisness_mechanic, i, "mechanic_price_generator"); 	
		mechanic[i][mechanic_price_forsunki]  = sql_get_field_assoc_int_ex(buisness_mechanic, i, "mechanic_price_forsunki"); 	

		mechanic[i][mechanic_price_nasos] = sql_get_field_assoc_int_ex(buisness_mechanic, i, "mechanic_price_nasos"); 	


		mechanic[i][mechanic_status_sell]  = sql_get_field_assoc_int_ex(buisness_mechanic, i, "mechanic_status_sell"); 	
		mechanic[i][mechanic_sell_day_payday]  = sql_get_field_assoc_int_ex(buisness_mechanic, i, "mechanic_sell_day_payday"); 	


		create_mechanic_3d_text();

		mechanic[i][mechanic_base_icon] = CreateDynamicMapIcon(mechanic[i][mechanic_pos_x], mechanic[i][mechanic_pos_y], mechanic[i][mechanic_pos_z], 27 , -1);

		new 
			pickup_color;

		if(i == 0)
		{
			pickup_color = TRIGGER_ORANGE;
		}
		else if(i == 1)
		{
			pickup_color = TRIGGER_LBLUE;
		}
		else if(i == 2)
		{
			pickup_color = TRIGGER_LRED;
		}

		mechanic[i][mechanic_base_pickup] = create_circle_pickup(mechanic[i][mechanic_pos_x], mechanic[i][mechanic_pos_y], mechanic[i][mechanic_pos_z], pickup_color);

		load_mechanic++;

	}

	printf("[Механики]: <%i из %i>. Времени затрачено: <%d мс>" ,all_mechanic_station, load_mechanic, GetTickCount() - time);

	create_mechanic_box_rep();
	clear_date_mechanic_box();


	mechanic_count_car[MECHANIC_BASE_STATION_1] = 25;
	mechanic_count_car[MECHANIC_BASE_STATION_2] = 25;
	mechanic_count_car[MECHANIC_BASE_STATION_3] = 25;

	sql_next_row(buisness_mechanic);

	return true;
}

stock create_mechanic_box_rep()
{
	mechanic_repair_box_1[0] = create_circle_pickup(2061.4761,1883.7048,15.5409, TRIGGER_ORANGE);
	mechanic_repair_box_1[1] = create_circle_pickup(2061.5144,1878.2296,15.5409, TRIGGER_ORANGE);
	mechanic_repair_box_1[2] = create_circle_pickup(2061.4758,1873.2306,15.5409, TRIGGER_ORANGE);
	mechanic_repair_box_1[3] = create_circle_pickup(2061.7471,1868.0739,15.5409, TRIGGER_ORANGE);


	mechanic_repair_box_2[0] = create_circle_pickup(2180.9019,-1820.7839,18.8105, TRIGGER_LBLUE);
	mechanic_repair_box_2[1] = create_circle_pickup(2181.4124,-1830.0486,18.8149, TRIGGER_LBLUE);
	mechanic_repair_box_2[2] = create_circle_pickup(2180.8872,-1838.2864,18.8148, TRIGGER_LBLUE);
	mechanic_repair_box_2[3] = create_circle_pickup(2180.6902,-1847.0455,18.8148, TRIGGER_LBLUE);
	mechanic_repair_box_2[4] = create_circle_pickup(2180.2500,-1855.0676,18.8103, TRIGGER_LBLUE);	

	mechanic_repair_box_3[0] = create_circle_pickup(403.7483,792.8860,12.1119, TRIGGER_LRED);
	mechanic_repair_box_3[1] = create_circle_pickup(401.9188,787.9308,12.1119, TRIGGER_LRED);
	mechanic_repair_box_3[2] = create_circle_pickup(400.0770,782.6754,12.1119, TRIGGER_LRED);
	mechanic_repair_box_3[3] = create_circle_pickup(398.6227,778.3241,12.1119, TRIGGER_LRED);


  	mechanic_repair_box_3_t[0] = CreateDynamic3DTextLabel(""cWH"Станция Технического Обслуживания\n "cLRED"Нажмите 'ГУДОК'",-1, \
  		403.7483,792.8860,12.1119, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
  	mechanic_repair_box_3_t[1] = CreateDynamic3DTextLabel(""cWH"Станция Технического Обслуживания\n "cLRED"Нажмите 'ГУДОК'",-1, \
  		401.9188,787.9308,12.1119, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
  	mechanic_repair_box_3_t[2] = CreateDynamic3DTextLabel(""cWH"Станция Технического Обслуживания\n "cLRED"Нажмите 'ГУДОК'",-1, \
  		400.0770,782.6754,12.1119, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
  	mechanic_repair_box_3_t[3] = CreateDynamic3DTextLabel(""cWH"Станция Технического Обслуживания\n "cLRED"Нажмите 'ГУДОК'",-1, \
  		398.6227,778.3241,12.1119, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);



  	mechanic_repair_box_1_t[0] = CreateDynamic3DTextLabel(""cWH"Станция Технического Обслуживания\n "cORANGE"Нажмите 'ГУДОК'",-1, \
  		2061.4761,1883.7048,15.5409, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
  	mechanic_repair_box_1_t[1] = CreateDynamic3DTextLabel(""cWH"Станция Технического Обслуживания\n "cORANGE"Нажмите 'ГУДОК'",-1, \
  		2061.5144,1878.2296,15.5409, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
  	mechanic_repair_box_1_t[2] = CreateDynamic3DTextLabel(""cWH"Станция Технического Обслуживания\n "cORANGE"Нажмите 'ГУДОК'",-1, \
  		2061.4758,1873.2306,15.5409, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
  	mechanic_repair_box_1_t[3] = CreateDynamic3DTextLabel(""cWH"Станция Технического Обслуживания\n "cORANGE"Нажмите 'ГУДОК'",-1, \
  		2061.7471,1868.0739,15.5409, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);



  	mechanic_repair_box_2_t[0] = CreateDynamic3DTextLabel(""cWH"Станция Технического Обслуживания\n "cBLUE"Нажмите 'ГУДОК'",-1, \
  		2180.9019,-1820.7839,18.8105, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
  	mechanic_repair_box_2_t[1] = CreateDynamic3DTextLabel(""cWH"Станция Технического Обслуживания\n "cBLUE"Нажмите 'ГУДОК'",-1, \
  		2181.4124,-1830.0486,18.8149, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
  	mechanic_repair_box_2_t[2] = CreateDynamic3DTextLabel(""cWH"Станция Технического Обслуживания\n "cBLUE"Нажмите 'ГУДОК'",-1, \
  		2180.8872,-1838.2864,18.8148, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
  	mechanic_repair_box_2_t[3] = CreateDynamic3DTextLabel(""cWH"Станция Технического Обслуживания\n "cBLUE"Нажмите 'ГУДОК'",-1, \
  		2180.6902,-1847.0455,18.8148, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
  	mechanic_repair_box_2_t[4] = CreateDynamic3DTextLabel(""cWH"Станция Технического Обслуживания\n "cBLUE"Нажмите 'ГУДОК'",-1, \
  		2180.2500,-1855.0676,18.8103, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);

  	CreateDynamic3DTextLabel(""cWH"Работа Механиком\n "cORANGE"Информация",-1, \
  		2069.5623,1888.1904,15.5484, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
	CreateDynamicPickup(1275, 23, 2069.5623,1888.1904,15.5484, -1, -1, -1, 15.0);

  	CreateDynamic3DTextLabel(""cWH"Работа Механиком\n "cBLUE"Информация",-1, \
  		2147.6699,-1837.4011,18.8203, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
	CreateDynamicPickup(1275, 23, 2147.6699,-1837.4011,18.8203, -1, -1, -1, 15.0);

  	CreateDynamic3DTextLabel(""cWH"Работа Механиком\n "cLRED"Информация",-1, \
  		412.7304,794.7852,12.1119, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
	CreateDynamicPickup(1275, 23, 412.7304,794.7852,12.1119, -1, -1, -1, 15.0);

	mechanic_skin_pickup[0] = CreateDynamicSphere(2069.5623,1888.1904,15.5484, 1.0, -1, -1, -1);
	mechanic_skin_pickup[1] = CreateDynamicSphere(2147.6699,-1837.4011,18.8203, 1.0, -1, -1, -1);
	mechanic_skin_pickup[2] = CreateDynamicSphere(412.7304,794.7852,12.1119, 1.0, -1, -1, -1);


  	CreateDynamic3DTextLabel(""cWH"Эвакуаторы СТО\n "cORANGE"Информация",-1, \
  		2044.1344,1888.4639,15.5409, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
	mechanic_vehicle_rent[0] = create_circle_pickup(2044.1344,1888.4639,15.5409, TRIGGER_ORANGE);

  	CreateDynamic3DTextLabel(""cWH"Эвакуаторы СТО\n "cBLUE"Информация",-1, \
  		2126.1865,-1836.3086,18.8184, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
	mechanic_vehicle_rent[1] = create_circle_pickup(2126.1865,-1836.3086,18.8184, TRIGGER_LBLUE);

  	CreateDynamic3DTextLabel(""cWH"Эвакуаторы СТО\n "cLRED"Информация",-1, \
  		387.8153,808.1393,12.1119, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
	mechanic_vehicle_rent[2] = create_circle_pickup(387.8153,808.1393,12.1119, TRIGGER_LRED);


	return true;
}

stock show_dialog_rent_mech_car(playerid)
{



	new 	
		type = pData[playerid][pMech];

	if(type == -1)
		return SendErr(playerid, "Вы не работаете на СТО!");

	switch(type)
	{
		case MECHANIC_BASE_STATION_1:
		{

			format(String144,sizeof(String144),""cWH"Вы действительно хотите взять эвакуатор?\n\n\
			На базе осталось: "cORANGE"%d эвакуаторов", mechanic_count_car[MECHANIC_BASE_STATION_1]);
			SPD(playerid,DIALOG_RENT_VEHICLE_MECH,0,""cORANGE"Эвакуаторы СТО",String144, !"Далее", !"Закрыть");	

		}
		case MECHANIC_BASE_STATION_2:
		{
			format(String144,sizeof(String144),""cWH"Вы действительно хотите взять эвакуатор?\n\n\
			На базе осталось: "cBLUE"%d эвакуаторов", mechanic_count_car[MECHANIC_BASE_STATION_2]);
			SPD(playerid,DIALOG_RENT_VEHICLE_MECH,0,""cBLUE"Эвакуаторы СТО",String144, !"Далее", !"Закрыть");	

		}
		case MECHANIC_BASE_STATION_3:
		{
			format(String144,sizeof(String144),""cWH"Вы действительно хотите взять эвакуатор?\n\n\
			На базе осталось: "cLRED"%d эвакуаторов", mechanic_count_car[MECHANIC_BASE_STATION_3]);
			SPD(playerid,DIALOG_RENT_VEHICLE_MECH,0,""cLRED"Эвакуаторы СТО",String144, !"Далее", !"Закрыть");	
		}

	}

	return true;
}

stock end_mechanic_jobs(playerid)
{

	if(pData[playerid][pMech] == -1)
		return true;

	new 
		v = pTemp[playerid][rent_car];

	if(v == INVALID_VEHICLE_ID) 
		return true;

	new 	
		type = pData[playerid][pMech];

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:info_gui_vehicle_unrent", 3500);
	
	DestroyVehicle(v);
	DisablePlayerRaceCheckpoint(playerid);


	pTemp[playerid][rent_car] = INVALID_VEHICLE_ID;
	pTemp[playerid][rent_car_spawn_timer] = INVALID_TIMER_ID;

	mechanic_count_car[type]++;

	return true;
}

stock create_vehicle_rent_mech(playerid)
{

	if(pData[playerid][pMech] == -1)
		return SendErr(playerid, "Вы не работаете в СТО!");

	new 	
		type = pData[playerid][pMech];

	if(pTemp[playerid][rent_car] == GetPlayerVehicleID(playerid))
	{
		KillTimer(pTemp[playerid][rent_car_spawn_timer]);
		return true;
	}
	if(pTemp[playerid][rent_car] != INVALID_VEHICLE_ID)
	{
		SendErr(playerid, "Вы уже арендуете какой-либо транспорт");
		return RemovePlayerFromVehicleEx(playerid); 
	}

	if(mechanic_count_car[type] == 0)
		return SendErr(playerid, "На базе СТО недостаточно тягачей для работы!");

	switch(type)
	{
		case MECHANIC_BASE_STATION_1:
		{

			if(pTemp[playerid][rent_car] == GetPlayerVehicleID(playerid))
			{
				KillTimer(pTemp[playerid][rent_car_spawn_timer]);
				return true;
			}
			if(pTemp[playerid][rent_car] != INVALID_VEHICLE_ID)
			{
				SendErr(playerid, "Вы уже арендуете какой-либо транспорт");
				return RemovePlayerFromVehicleEx(playerid); 
			}

			new 
				random_pos = random(4);

			new 
				mechanic_veh_1 = CreateVehicle(525, position_spawn_mech_1[random_pos][0], position_spawn_mech_1[random_pos][1], position_spawn_mech_1[random_pos][2], position_spawn_mech_1[random_pos][3], 6, 6, 60);


			show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_RIGHT, "brilliantother:info_gui_vehicle_rent", 3500);	

			PutPlayerInVehicleEx(playerid, mechanic_veh_1, 0);


			vehicle[mechanic_veh_1][cOwnTo] = VEHICLE_MECHANIC_1;
			vehicle[mechanic_veh_1][carMech] = MECHANIC_BASE_STATION_1;
			vehicle[mechanic_veh_1][cFuel] = 50.0;
			vehicle[mechanic_veh_1][carMechFuel] = 90;
			vehicle[mechanic_veh_1][carMechOil] = 90;
			vehicle[mechanic_veh_1][cHealth] = 1000.0;
			vehicle[mechanic_veh_1][consumables_oil] = 1000.0;

			format(String256,sizeof(String256),"\
				"cWH"Эвакуатор СТО\n\
				"cORANGE"«%s»\n\n\
				"cORANGE"Цена за ремонт: "cWH"%dp\n\n\
				"cORANGE"Топлива: "cWH"%d л.\n\
				"cORANGE"Цена за 1 л: "cWH"%dp\n\n\
				"cORANGE"Масла: "cWH"%d л.\n\
				"cORANGE"Цена за 1 л: "cWH"%dp", mechanic[MECHANIC_BASE_STATION_1][mechanic_base_name], mechanic[MECHANIC_BASE_STATION_1][mechanic_price_remont],vehicle[mechanic_veh_1][carMechFuel],mechanic[MECHANIC_BASE_STATION_1][mechanic_price_fuel],
			vehicle[mechanic_veh_1][carMechOil],mechanic[MECHANIC_BASE_STATION_1][mechanic_price_oil]);
			vehicle[mechanic_veh_1][cMechText] = CreateDynamic3DTextLabel(String256, CWHITE, 0.0,0.0,1.0, 10.0, INVALID_PLAYER_ID, mechanic_veh_1);

			SetVehicleRuNumberPlate(mechanic_veh_1, "s111mc", "777");

			RepairVehicle(mechanic_veh_1);

			pTemp[playerid][rent_car] = mechanic_veh_1;

			mechanic_count_car[MECHANIC_BASE_STATION_1]--;

		}
		case MECHANIC_BASE_STATION_2:
		{
			if(pTemp[playerid][rent_car] == GetPlayerVehicleID(playerid))
			{
				KillTimer(pTemp[playerid][rent_car_spawn_timer]);
				return true;
			}
			if(pTemp[playerid][rent_car] != INVALID_VEHICLE_ID)
			{
				SendErr(playerid, "Вы уже арендуете какой-либо транспорт");
				return RemovePlayerFromVehicleEx(playerid); 
			}

			new 
				random_pos = random(5);

			new 
				mechanic_veh_2 = CreateVehicle(525, position_spawn_mech_2[random_pos][0], position_spawn_mech_2[random_pos][1], position_spawn_mech_2[random_pos][2], position_spawn_mech_2[random_pos][3], 7, 7, 600);


			show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_RIGHT, "brilliantother:info_gui_vehicle_rent", 3500);	

			PutPlayerInVehicleEx(playerid, mechanic_veh_2, 0);


			vehicle[mechanic_veh_2][cOwnTo] = VEHICLE_MECHANIC_2;
			vehicle[mechanic_veh_2][carMech] = MECHANIC_BASE_STATION_2;
			vehicle[mechanic_veh_2][cFuel] = 50.0;
			vehicle[mechanic_veh_2][carMechFuel] = 90;
			vehicle[mechanic_veh_2][carMechOil] = 90;
			vehicle[mechanic_veh_2][cHealth] = 1000.0;
			vehicle[mechanic_veh_2][consumables_oil] = 1000.0;

			format(String256,sizeof(String256),"\
				"cWH"Эвакуатор СТО\n\
				"cBLUE"«%s»\n\n\
				"cBLUE"Цена за ремонт: "cWH"%dp\n\n\
				"cBLUE"Топлива: "cWH"%d л.\n\
				"cBLUE"Цена за 1 л: "cWH"%dp\n\n\
				"cBLUE"Масла: "cWH"%d л.\n\
				"cBLUE"Цена за 1 л: "cWH"%dp", mechanic[MECHANIC_BASE_STATION_2][mechanic_base_name], mechanic[MECHANIC_BASE_STATION_2][mechanic_price_remont],vehicle[mechanic_veh_2][carMechFuel],mechanic[MECHANIC_BASE_STATION_2][mechanic_price_fuel],
			vehicle[mechanic_veh_2][carMechOil],mechanic[MECHANIC_BASE_STATION_2][mechanic_price_oil]);
			vehicle[mechanic_veh_2][cMechText] = CreateDynamic3DTextLabel(String256, CWHITE, 0.0,0.0,1.0, 10.0, INVALID_PLAYER_ID, mechanic_veh_2);

			SetVehicleRuNumberPlate(mechanic_veh_2, "s111mc", "777");

			RepairVehicle(mechanic_veh_2);

			pTemp[playerid][rent_car] = mechanic_veh_2;


			mechanic_count_car[MECHANIC_BASE_STATION_2]--;

		}
		case MECHANIC_BASE_STATION_3:
		{
			if(pTemp[playerid][rent_car] == GetPlayerVehicleID(playerid))
			{
				KillTimer(pTemp[playerid][rent_car_spawn_timer]);
				return true;
			}
			if(pTemp[playerid][rent_car] != INVALID_VEHICLE_ID)
			{
				SendErr(playerid, "Вы уже арендуете какой-либо транспорт");
				return RemovePlayerFromVehicleEx(playerid); 
			}

			new 
				random_pos = random(5);

			new 
				mechanic_veh_3 = CreateVehicle(525, position_spawn_mech_3[random_pos][0], position_spawn_mech_3[random_pos][1], position_spawn_mech_3[random_pos][2], position_spawn_mech_3[random_pos][3], 3, 3, 600);


			show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_RIGHT, "brilliantother:info_gui_vehicle_rent", 3500);	

			PutPlayerInVehicleEx(playerid, mechanic_veh_3, 0);


			vehicle[mechanic_veh_3][cOwnTo] = VEHICLE_MECHANIC_3;
			vehicle[mechanic_veh_3][carMech] = MECHANIC_BASE_STATION_3;
			vehicle[mechanic_veh_3][cFuel] = 50.0;
			vehicle[mechanic_veh_3][carMechFuel] = 90;
			vehicle[mechanic_veh_3][carMechOil] = 90;
			vehicle[mechanic_veh_3][cHealth] = 1000.0;
			vehicle[mechanic_veh_3][consumables_oil] = 1000.0;
			
			format(String256,sizeof(String256),"\
				"cWH"Эвакуатор СТО\n\
				"cLRED"«%s»\n\n\
				"cLRED"Цена за ремонт: "cWH"%dp\n\n\
				"cLRED"Топлива: "cWH"%d л.\n\
				"cLRED"Цена за 1 л: "cWH"%dp\n\n\
				"cLRED"Масла: "cWH"%d л.\n\
				"cLRED"Цена за 1 л: "cWH"%dp", mechanic[MECHANIC_BASE_STATION_3][mechanic_base_name], mechanic[MECHANIC_BASE_STATION_3][mechanic_price_remont],vehicle[mechanic_veh_3][carMechFuel],mechanic[MECHANIC_BASE_STATION_3][mechanic_price_fuel],
			vehicle[mechanic_veh_3][carMechOil],mechanic[MECHANIC_BASE_STATION_3][mechanic_price_oil]);
			vehicle[mechanic_veh_3][cMechText] = CreateDynamic3DTextLabel(String256, CWHITE, 0.0,0.0,1.0, 10.0, INVALID_PLAYER_ID, mechanic_veh_3);

			SetVehicleRuNumberPlate(mechanic_veh_3, "s111mc", "777");

			RepairVehicle(mechanic_veh_3);

			pTemp[playerid][rent_car] = mechanic_veh_3;

			mechanic_count_car[MECHANIC_BASE_STATION_3]--;

		}
	}

	return true;
}

stock save_mechanic_base()
{
	static
		mech_owner_str[MAX_PLAYER_NAME],
		mech_name_str[20];

	for(new i; i < MAX_MECHANIC_BASE; i++)
	{

		format(mech_owner_str, MAX_PLAYER_NAME, "%s", mechanic[i][mechanic_base_owner]);
		format(mech_name_str, 20, "%s", mechanic[i][mechanic_base_name]);

		format(String2048, sizeof(String2048), "\
			UPDATE mechanic SET \
			owner_name = '%s', \
			mechanic_base_name = '%s', \
			owner_id = '%d', \
			mechanic_base_price = '%d', \
			mechanic_base_closed = '%d', \
			mechanic_base_days = '%d', \
			mechanic_base_bank = '%d', \
			mechanic_base_percent = '%d', \
			mechanic_base_phone = '%d', \
			mechanic_price_rem = '%d', \
			mechanic_price_fuel = '%d', \
			mechanic_price_oil = '%d', \
			mechanic_price_candles = '%d', \
			mechanic_price_brake = '%d', \
			mechanic_price_belt = '%d', \
			mechanic_price_starter = '%d', \
			mechanic_price_generator = '%d', \
			mechanic_price_forsunki = '%d', \
			mechanic_price_nasos = '%d', \
			mechanic_base_finka_day = '%d', \
			mechanic_base_finka_ogran = '%d', \
			mechanic_status_sell = '%d', \
			mechanic_sell_day_payday = '%d' \
			WHERE id = '%d'",

			mech_owner_str,
			mech_name_str,
			mechanic[i][mechanic_base_owner_id],
			mechanic[i][mechanic_base_price],
			mechanic[i][mechanic_base_closed],
			mechanic[i][mechanic_base_days],
			mechanic[i][mechanic_base_bank],
			mechanic[i][mechanic_base_percent],
			mechanic[i][mechanic_base_phone],

			mechanic[i][mechanic_price_remont],
			mechanic[i][mechanic_price_fuel],
			mechanic[i][mechanic_price_oil],
			mechanic[i][mechanic_price_candles],
			mechanic[i][mechanic_price_brake],
			mechanic[i][mechanic_price_belt],
			mechanic[i][mechanic_price_starter],
			mechanic[i][mechanic_price_generator],
			mechanic[i][mechanic_price_forsunki], 
			mechanic[i][mechanic_price_nasos], 
			mechanic[i][mechanic_base_finka_day],
			mechanic[i][mechanic_base_finka_ogran],

			mechanic[i][mechanic_status_sell],
			mechanic[i][mechanic_sell_day_payday],

			i);

		sql_queryEx(zConn, String2048, QUERY_THREADED);	
	}
	return true;
}

stock sell_mechanic_payday(f)
{


	if(mechanic[f][mechanic_base_days] == 0 && mechanic[f][mechanic_base_owner_id] != -1)
		return printf("[МЕХАНИКИ PAYDAY СЛЕТ] %d (%d) - оплачено | %d - владелец",f, mechanic[f][mechanic_base_days], mechanic[f][mechanic_base_owner_id]);

	new 
		owner_id = mechanic[f][mechanic_base_owner_id];

	new 
		owner_garage_name[32];


	GetPlayerNameByID(owner_id, owner_garage_name);

	new 
		player_id = GetPlayerID(owner_garage_name);	

	new 
		final_money = floatround(mechanic[f][mechanic_base_price]*0.8);


	if(IsPlayerConnected(player_id))
	{
		if(pData[player_id][pMechOwnerID] == f)
		{	
			new 
				mech_owner_str[32];
				
			format(mechanic[f][mechanic_base_owner], 32, "None");
			format(mech_owner_str, 32, "None");

			format(String256,sizeof(String256),"UPDATE `mechanic` SET `owner_name` = 'None' WHERE `id` = '%d'" , mech_owner_str, owner_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
			format(String256,sizeof(String256),"UPDATE `mechanic` SET `owner_id` = '-1' WHERE `id` = '%d'" , owner_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	

			pData[player_id][pBusiness] = -1;
			UpdatePlayerData(player_id,"bussiness",pData[player_id][pBusiness]);	

			pData[player_id][pMech] = -1;
			pData[player_id][pMechOwnerLowID] = -1;
			pData[player_id][pJob] = 0;
			pData[player_id][pMechRank] = 0;

			UpdatePlayerData(player_id,"pMechRank", pData[player_id][pMechRank]);	
			UpdatePlayerData(player_id,"mech", pData[player_id][pMech]);
			UpdatePlayerData(player_id,"pMechOwnerLowID", pData[player_id][pMechOwnerLowID]);
			UpdatePlayerData(player_id,"job", pData[player_id][pJob]);

			pData[player_id][pMechOwnerID] = -1;
			UpdatePlayerData(player_id,"pMechOwnerID", pData[player_id][pMechOwnerID]);
			SFCM(player_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Ваше СТО было продано за неуплату!");	

	        SendClientMessage(player_id, COLOR_LIGHTRED, "Вы можете вернуть 80 процентов от стоимости имущества");
	        SendClientMessage(player_id, COLOR_LIGHTRED, "Для этого введите команду /returnmoney");


	        pData[player_id][pReturnMoney] += final_money;
	        if(pData[player_id][pReturnMoney] > 20000000 ) pData[player_id][pReturnMoney] = 0;
		}
	}
	else
	{	
		new 
			formate_str[280],
			mech_owner_str[32];

		format(mechanic[f][mechanic_base_owner], 32, "None");
		format(mech_owner_str, 32, "None");

		format(String256,sizeof(String256),"UPDATE `mechanic` SET `owner_name` = 'None' WHERE `id` = '%d'" , mech_owner_str, owner_id);
		sql_queryEx(zConn, String256, QUERY_THREADED);	
		format(String256,sizeof(String256),"UPDATE `mechanic` SET `owner_id` = '-1', `pMechRank` = '-1', `mech` = '-1', `job` = '0' WHERE `id` = '%d'" , owner_id);
		sql_queryEx(zConn, String256, QUERY_THREADED);	

		format(formate_str, 80, "UPDATE accounts SET pMechOwnerID = '-1', bussiness = '-1' WHERE pMechOwnerID = '%d'", f);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	

		format(String256,sizeof(String256),"UPDATE `accounts` SET returnmoney = returnmoney + %d WHERE id = '%i'", final_money, owner_id);
		sql_queryEx(zConn, String256, QUERY_THREADED);

		send_off_message(-1, owner_garage_name, "Ваше СТО было продано государству за неуплату. Мы вернули 80 процентов (/returnmoney)");
	}




	mechanic[f][mechanic_base_owner_id] = -1;	
	mechanic[f][mechanic_base_bank] = 0;

	mechanic[f][mechanic_status_sell] = 3;
	mechanic[f][mechanic_sell_day_payday] = RandomEx(2, 22);	

	save_mechanic_base();
	update_mechanic_3d_text();
	return true;
}

stock sell_mechanic_admin(playerid, f)
{

	new 
		owner_id = mechanic[f][mechanic_base_owner_id];

	new 
		owner_garage_name[32];


	GetPlayerNameByID(owner_id, owner_garage_name);

	new 
		player_id = GetPlayerID(owner_garage_name);	


	if(IsPlayerConnected(player_id))
	{
		if(pData[player_id][pMechOwnerID] == f)
		{	
			new 
				mech_owner_str[32];
				
			format(mechanic[f][mechanic_base_owner], 32, "None");
			format(mech_owner_str, 32, "None");

			format(String256,sizeof(String256),"UPDATE `mechanic` SET `owner_name` = 'None' WHERE `id` = '%d'" , mech_owner_str, owner_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
			format(String256,sizeof(String256),"UPDATE `mechanic` SET `owner_id` = '-1' WHERE `id` = '%d'" , owner_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	

			pData[player_id][pBusiness] = -1;
			UpdatePlayerData(player_id,"bussiness",pData[player_id][pBusiness]);	

			pData[player_id][pMech] = -1;
			pData[player_id][pMechOwnerLowID] = -1;
			pData[player_id][pJob] = 0;
			pData[player_id][pMechRank] = 0;

			UpdatePlayerData(player_id,"pMechRank", pData[player_id][pMechRank]);	
			UpdatePlayerData(player_id,"mech", pData[player_id][pMech]);
			UpdatePlayerData(player_id,"pMechOwnerLowID", pData[player_id][pMechOwnerLowID]);
			UpdatePlayerData(player_id,"job", pData[player_id][pJob]);

			pData[player_id][pMechOwnerID] = -1;
			UpdatePlayerData(player_id,"pMechOwnerID", pData[player_id][pMechOwnerID]);
			SFCM(player_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Ваше СТО было продано за неуплату!");	
		}
	}
	else
	{	
		new 
			formate_str[280],
			mech_owner_str[32];

		format(mechanic[f][mechanic_base_owner], 32, "None");
		format(mech_owner_str, 32, "None");

		format(String256,sizeof(String256),"UPDATE `mechanic` SET `owner_name` = 'None' WHERE `id` = '%d'" , mech_owner_str, owner_id);
		sql_queryEx(zConn, String256, QUERY_THREADED);	
		format(String256,sizeof(String256),"UPDATE `mechanic` SET `owner_id` = '-1', `pMechRank` = '-1', `mech` = '-1', `job` = '0' WHERE `id` = '%d'" , owner_id);
		sql_queryEx(zConn, String256, QUERY_THREADED);	

		format(formate_str, 80, "UPDATE accounts SET pMechOwnerID = '-1', bussiness = '-1' WHERE pMechOwnerID = '%d'", f);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	

		send_off_message(-1, owner_garage_name, "Ваше СТО было продано государству за неуплату. Мы вернули 80 процентов (/returnmoney)");
	}




	mechanic[f][mechanic_base_owner_id] = -1;	
	mechanic[f][mechanic_base_bank] = 0;

	save_mechanic_base();
	update_mechanic_3d_text();
	return true;
}

stock sell_mechanic_accept(playerid)
{
	SPD(playerid, DIALOG_ACCEPT_SELL_MECHANIC, DIALOG_STYLE_MSGBOX, !""cBLUE"Продажа СТО", !"\
	"cWH"Вы уверены, что хотите продать СТО государству?\n\n\
	Вам будет возвращено 80%% от стоимости!", !"Да", !"Нет");

	return true;

}

stock sell_mechanic(playerid, f)
{

	new 	
		mech_owner_str[30];

	if(pData[playerid][pMechOwnerID] == f)
	{

		new 
			final_money = floatround(mechanic[f][mechanic_base_price]*0.8);


		format(mechanic[f][mechanic_base_owner], 32, "None");
		format(mech_owner_str, 32, "None");

		format(String256,sizeof(String256),"UPDATE `mechanic` SET `owner_name` = 'None' WHERE `id` = '%d'" , mech_owner_str, f);
		sql_queryEx(zConn, String256, QUERY_THREADED);	
		format(String256,sizeof(String256),"UPDATE `mechanic` SET `owner_id` = '-1' WHERE `id` = '%d'" , f);
		sql_queryEx(zConn, String256, QUERY_THREADED);	

		pData[playerid][pBusiness] = -1;
		UpdatePlayerData(playerid,"bussiness",pData[playerid][pBusiness]);	


		pData[playerid][pMech] = -1;
		pData[playerid][pMechOwnerLowID] = -1;
		pData[playerid][pJob] = 0;
		pData[playerid][pMechRank] = 0;

		UpdatePlayerData(playerid,"pMechRank", pData[playerid][pMechRank]);	
		UpdatePlayerData(playerid,"mech", pData[playerid][pMech]);
		UpdatePlayerData(playerid,"pMechOwnerLowID", pData[playerid][pMechOwnerLowID]);
		UpdatePlayerData(playerid,"job", pData[playerid][pJob]);

		pData[playerid][pMechOwnerID] = -1;
		UpdatePlayerData(playerid,"pMechOwnerID", pData[playerid][pMechOwnerID]);
		
		SendSucc(playerid, "Вы продали СТО государству!");

	 	format(String144, sizeof(String144), "Продажа СТО №%d", f);
		give_money(playerid, final_money, String144);

		mechanic[f][mechanic_base_owner_id] = -1;	
		mechanic[f][mechanic_base_bank] = 0;

		save_mechanic_base();
		update_mechanic_3d_text();
	}

	return true;
}

stock create_mechanic_3d_text()
{

	new
		owner[24];

	if(!strcmp("None", mechanic[0][mechanic_base_owner]))
		format(owner, 24, "Государство");
	else
		format(owner, 24, mechanic[0][mechanic_base_owner]);

	format(String512, sizeof(String512),"\
		Станция Технического Обслуживания №%d\n\
		"cORANGE"«%s»\n\n\
		"cWH"Владелец: "cORANGE"%s\n\n\
		\t"cORANGE"Остальная информация:\n\n\
		"cWH"Статус станции: %s\n\
		"cWH"Номер телефона: "cORANGE"%d",
		mechanic[0][mechanic_base_id]+1,
		mechanic[0][mechanic_base_name],
		owner,
		(mechanic[0][mechanic_base_closed]) ? (""cGR"Работает") : (""cLRED"Закрыта"),
		mechanic[0][mechanic_base_phone]);

	mechanic[0][mechanic_base_pick_info] = CreateDynamic3DTextLabel(String512, -1, mechanic[0][mechanic_pos_x], mechanic[0][mechanic_pos_y], mechanic[0][mechanic_pos_z]+1.0, 15.0);

	if(!strcmp("None", mechanic[1][mechanic_base_owner]))
		format(owner, 24, "Государство");
	else
		format(owner, 24, mechanic[1][mechanic_base_owner]);

	format(String512, sizeof(String512), "\
		Станция Технического Обслуживания №%d\n\
		"cBLUE"«%s»\n\n\
		"cWH"Владелец: "cBLUE"%s\n\n\
		\t"cBLUE"Остальная информация:\n\n\
		"cWH"Статус станции: %s\n\
		"cWH"Номер телефона: "cBLUE"%d",
		mechanic[1][mechanic_base_id]+1,
		mechanic[1][mechanic_base_name],
		owner,
		(mechanic[1][mechanic_base_closed]) ? (""cGR"Работает") : (""cLRED"Закрыта"),
		mechanic[1][mechanic_base_phone]);

	mechanic[1][mechanic_base_pick_info] = CreateDynamic3DTextLabel(String512, -1, mechanic[1][mechanic_pos_x], mechanic[1][mechanic_pos_y], mechanic[1][mechanic_pos_z]+1.0, 15.0);
	

	if(!strcmp("None", mechanic[2][mechanic_base_owner]))
		format(owner, 24, "Государство");
	else
		format(owner, 24, mechanic[2][mechanic_base_owner]);

	format(String512, sizeof(String512), "\
		Станция Технического Обслуживания №%d\n\
		"cLRED"«%s»\n\n\
		"cWH"Владелец: "cLRED"%s\n\n\
		\t"cLRED"Остальная информация:\n\n\
		"cWH"Статус станции: %s\n\
		"cWH"Номер телефона: "cLRED"%d",
		mechanic[2][mechanic_base_id]+1,
		mechanic[2][mechanic_base_name],
		owner,
		(mechanic[2][mechanic_base_closed]) ? (""cGR"Работает") : (""cLRED"Закрыта"),
		mechanic[2][mechanic_base_phone]);

	mechanic[2][mechanic_base_pick_info] = CreateDynamic3DTextLabel(String512, -1, mechanic[2][mechanic_pos_x], mechanic[2][mechanic_pos_y], mechanic[2][mechanic_pos_z]+1.0, 15.0);
	

	return true;
}

stock update_mechanic_car_3d_t()
{

	foreach(new i: Vehicles)
	{
		new
			own = vehicle[i][cOwnTo];
			
		switch(own)
		{
			case VEHICLE_MECHANIC_1:
			{
				format(String320,sizeof(String320),"\
				"cWH"Эвакуатор СТО\n\
				"cORANGE"«%s»\n\n\
				"cORANGE"Цена за ремонт: "cWH"%dp\n\n\
				"cORANGE"Топлива: "cWH"%d л.\n\
				"cORANGE"Цена за 1 л: "cWH"%dp\n\n\
				"cORANGE"Масла: "cWH"%d л.\n\
				"cORANGE"Цена за 1 л: "cWH"%dp", mechanic[MECHANIC_BASE_STATION_1][mechanic_base_name], mechanic[MECHANIC_BASE_STATION_1][mechanic_price_remont],vehicle[i][carMechFuel],mechanic[MECHANIC_BASE_STATION_1][mechanic_price_fuel],
				vehicle[i][carMechOil],mechanic[MECHANIC_BASE_STATION_1][mechanic_price_oil]);

				UpdateDynamic3DTextLabelText(vehicle[i][cMechText], -1, String320);				
			}
			case VEHICLE_MECHANIC_2:
			{
				format(String320,sizeof(String320),"\
				"cWH"Эвакуатор СТО\n\
				"cBLUE"«%s»\n\n\
				"cBLUE"Цена за ремонт: "cWH"%dp\n\n\
				"cBLUE"Топлива: "cWH"%d л.\n\
				"cBLUE"Цена за 1 л: "cWH"%dp\n\n\
				"cBLUE"Масла: "cWH"%d л.\n\
				"cBLUE"Цена за 1 л: "cWH"%dp", mechanic[MECHANIC_BASE_STATION_2][mechanic_base_name], mechanic[MECHANIC_BASE_STATION_2][mechanic_price_remont],vehicle[i][carMechFuel],mechanic[MECHANIC_BASE_STATION_2][mechanic_price_fuel],
				vehicle[i][carMechOil],mechanic[MECHANIC_BASE_STATION_2][mechanic_price_oil]);

				UpdateDynamic3DTextLabelText(vehicle[i][cMechText], -1, String320);
			}
			case VEHICLE_MECHANIC_3: 
			{
				format(String320,sizeof(String320),"\
				"cWH"Эвакуатор СТО\n\
				"cLRED"«%s»\n\n\
				"cLRED"Цена за ремонт: "cWH"%dp\n\n\
				"cLRED"Топлива: "cWH"%d л.\n\
				"cLRED"Цена за 1 л: "cWH"%dp\n\n\
				"cLRED"Масла: "cWH"%d л.\n\
				"cLRED"Цена за 1 л: "cWH"%dp", mechanic[MECHANIC_BASE_STATION_3][mechanic_base_name], mechanic[MECHANIC_BASE_STATION_3][mechanic_price_remont],vehicle[i][carMechFuel],mechanic[MECHANIC_BASE_STATION_3][mechanic_price_fuel],
				vehicle[i][carMechOil],mechanic[MECHANIC_BASE_STATION_3][mechanic_price_oil]);

				UpdateDynamic3DTextLabelText(vehicle[i][cMechText], -1, String320);				
			}
		}

	}
	return true;
}


stock update_mechanic_3d_text()
{

	new
		owner[24];

	if(!strcmp("None", mechanic[0][mechanic_base_owner]))
		format(owner, 24, "Государство");
	else
		format(owner, 24, mechanic[0][mechanic_base_owner]);

	format(String512, sizeof(String512), "\
		Станция Технического Обслуживания №%d\n\
		"cORANGE"«%s»\n\n\
		"cWH"Владелец: "cORANGE"%s\n\n\
		\t"cORANGE"Остальная информация:\n\n\
		"cWH"Статус станции: %s\n\
		"cWH"Номер телефона: "cORANGE"%d",
		mechanic[0][mechanic_base_id]+1,
		mechanic[0][mechanic_base_name],
		owner,
		(mechanic[0][mechanic_base_closed]) ? (""cGR"Работает") : (""cLRED"Закрыта"),
		mechanic[0][mechanic_base_phone]);

	UpdateDynamic3DTextLabelText(mechanic[0][mechanic_base_pick_info], -1, String512);


	if(mechanic[0][mechanic_status_sell] == 3)
	{
		format(String512, sizeof(String512), "\
			Станция Технического Обслуживания №%d\n\
			"cORANGE"«%s»\n\n\
			"cORANGE"«СТО опечатано»\n\n\
			"cWH"Владелец: "cORANGE"%s\n\n\
			\t"cORANGE"Остальная информация:\n\n\
			"cWH"Статус станции: %s\n\
			"cWH"Номер телефона: "cORANGE"%d",
			mechanic[0][mechanic_base_id]+1,
			mechanic[0][mechanic_base_name],
			owner,
			(mechanic[0][mechanic_base_closed]) ? (""cGR"Работает") : (""cLRED"Закрыта"),
			mechanic[0][mechanic_base_phone]);

		UpdateDynamic3DTextLabelText(mechanic[0][mechanic_base_pick_info], -1, String512);

	}


	if(!strcmp("None", mechanic[1][mechanic_base_owner]))
		format(owner, 24, "Государство");
	else
		format(owner, 24, mechanic[1][mechanic_base_owner]);

	format(String512, sizeof(String512), "\
		Станция Технического Обслуживания №%d\n\
		"cBLUE"«%s»\n\n\
		"cWH"Владелец: "cBLUE"%s\n\n\
		\t"cBLUE"Остальная информация:\n\n\
		"cWH"Статус станции: %s\n\
		"cWH"Номер телефона: "cBLUE"%d",
		mechanic[1][mechanic_base_id]+1,
		mechanic[1][mechanic_base_name],
		owner,
		(mechanic[1][mechanic_base_closed]) ? (""cGR"Работает") : (""cLRED"Закрыта"),
		mechanic[1][mechanic_base_phone]);

	UpdateDynamic3DTextLabelText(mechanic[1][mechanic_base_pick_info], -1, String512);


	if(mechanic[1][mechanic_status_sell] == 3)
	{
		format(String512, sizeof(String512), "\
		Станция Технического Обслуживания №%d\n\
		"cBLUE"«%s»\n\n\
		"cBLUE"«СТО опечатано»\n\n\
		"cWH"Владелец: "cBLUE"%s\n\n\
		\t"cBLUE"Остальная информация:\n\n\
		"cWH"Статус станции: %s\n\
		"cWH"Номер телефона: "cBLUE"%d",
		mechanic[1][mechanic_base_id]+1,
		mechanic[1][mechanic_base_name],
		owner,
		(mechanic[1][mechanic_base_closed]) ? (""cGR"Работает") : (""cLRED"Закрыта"),
		mechanic[1][mechanic_base_phone]);

		UpdateDynamic3DTextLabelText(mechanic[1][mechanic_base_pick_info], -1, String512);

	}



	if(!strcmp("None", mechanic[2][mechanic_base_owner]))
		format(owner, 24, "Государство");
	else
		format(owner, 24, mechanic[2][mechanic_base_owner]);

	format(String512, sizeof(String512), "\
		Станция Технического Обслуживания №%d\n\
		"cLRED"«%s»\n\n\
		"cWH"Владелец: "cLRED"%s\n\n\
		\t"cLRED"Остальная информация:\n\n\
		"cWH"Статус станции: %s\n\
		"cWH"Номер телефона: "cLRED"%d",
		mechanic[2][mechanic_base_id]+1,
		mechanic[2][mechanic_base_name],
		owner,
		(mechanic[2][mechanic_base_closed]) ? (""cGR"Работает") : (""cLRED"Закрыта"),
		mechanic[2][mechanic_base_phone]);

	UpdateDynamic3DTextLabelText(mechanic[2][mechanic_base_pick_info], -1, String512);


	if(mechanic[2][mechanic_status_sell] == 3)
	{
		format(String512, sizeof(String512), "\
		Станция Технического Обслуживания №%d\n\
		"cLRED"«%s»\n\n\
		"cLRED"«СТО опечатано»\n\n\
		"cWH"Владелец: "cLRED"%s\n\n\
		\t"cLRED"Остальная информация:\n\n\
		"cWH"Статус станции: %s\n\
		"cWH"Номер телефона: "cLRED"%d",
		mechanic[2][mechanic_base_id]+1,
		mechanic[2][mechanic_base_name],
		owner,
		(mechanic[2][mechanic_base_closed]) ? (""cGR"Работает") : (""cLRED"Закрыта"),
		mechanic[2][mechanic_base_phone]);

		UpdateDynamic3DTextLabelText(mechanic[2][mechanic_base_pick_info], -1, String512);

	}

	return true;
}


stock show_mechanic_station_menu(playerid, type)
{
	if(mechanic[type][mechanic_base_owner_id] == -1)
		return show_mechanic_station_buy(playerid, type);


	return show_mechanic_menu(playerid, type);
}

stock show_mechanic_station_buy(playerid, type)
{
	static
		owner[24];

	if(!strcmp("None", mechanic[type][mechanic_base_owner]))
		format(owner, 24, "Государство");
	else
		format(owner, 24, mechanic[type][mechanic_base_owner]);

	SetPVarIntNew(playerid, "id_buy_mechanic_base", type);

	switch(type)
	{
		case MECHANIC_BASE_STATION_1:
		{
			format(String512, sizeof(String512), "\
				"cWH"Название: \t\t\t\t "cORANGE"%s\n\
				"cWH"Владелец: \t\t\t\t "cORANGE"%s\n\
				"cWH"Статус: \t\t\t\t\t %s\n\
				"cWH"Цена: \t\t\t\t\t "cGR"%d руб\n\n\
				Вы действительно хотите приобрести СТО?",
				mechanic[type][mechanic_base_name],
				owner,
				(mechanic[type][mechanic_base_closed]) ? (""cGR"Работает") : (""cLRED"Закрыта"),
				mechanic[type][mechanic_base_price]);

			SPD(playerid, DIALOG_BUY_MECHANIC, DIALOG_STYLE_MSGBOX, !""cORANGE"Покупка СТО", String512, !"Купить", !"Закрыть");			
		}
		case MECHANIC_BASE_STATION_2:
		{
			format(String512, sizeof(String512), "\
				"cWH"Название: \t\t\t\t "cBLUE"%s\n\
				"cWH"Владелец: \t\t\t\t "cBLUE"%s\n\
				"cWH"Статус: \t\t\t\t\t %s\n\
				"cWH"Цена: \t\t\t\t\t "cGR"%d руб\n\n\
				Вы действительно хотите приобрести СТО?",
				mechanic[type][mechanic_base_name],
				owner,
				(mechanic[type][mechanic_base_closed]) ? (""cGR"Работает") : (""cLRED"Закрыта"),
				mechanic[type][mechanic_base_price]);

			SPD(playerid, DIALOG_BUY_MECHANIC, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка СТО", String512, !"Купить", !"Закрыть");
		}
		case MECHANIC_BASE_STATION_3:
		{
			format(String512, sizeof(String512), "\
				"cWH"Название: \t\t\t\t "cLRED"%s\n\
				"cWH"Владелец: \t\t\t\t "cLRED"%s\n\
				"cWH"Статус: \t\t\t\t\t %s\n\
				"cWH"Цена: \t\t\t\t\t "cGR"%d руб\n\n\
				Вы действительно хотите приобрести СТО?",
				mechanic[type][mechanic_base_name],
				owner,
				(mechanic[type][mechanic_base_closed]) ? (""cGR"Работает") : (""cLRED"Закрыта"),
				mechanic[type][mechanic_base_price]);

			SPD(playerid, DIALOG_BUY_MECHANIC, DIALOG_STYLE_MSGBOX, !""cLRED"Покупка СТО", String512, !"Купить", !"Закрыть");
		}
	}


	return true;
}

stock show_mechanic_menu(playerid, type)
{

	if(mechanic[type][mechanic_base_owner_id] == pData[playerid][pMysqlID])
		return show_mech_menu_change(playerid, type);

	if(pData[playerid][pMechOwnerLowID] == type)
		return show_mech_menu_zam(playerid, type);

	return true;
}

stock show_mech_menu_zam(playerid, type)
{
	if(pData[playerid][pMechOwnerLowID] != type)
		return true;

	if(type == MECHANIC_BASE_STATION_1)
	{
	    format(String320, sizeof(String320), "\
	        "cGREY"Тип\t"cGREY"Действие\n\
	        "cORANGE"1. "cWH"Сотрудники\t"cGR"Просмотреть\n\
	        "cORANGE"2. "cWH"Статистика\t"cGR"Просмотреть");
	    SPD(playerid, DIALOG_CHANGE_MECHANIC, DIALOG_STYLE_TABLIST_HEADERS, !""cORANGE"Управление СТО:", String320, !"Выбрать", !"Закрыть"); 
	}
	else if(type == MECHANIC_BASE_STATION_2)
	{
	    format(String320, sizeof(String320), "\
	        "cGREY"Тип\t"cGREY"Действие\n\
	        "cBLUE"1. "cWH"Сотрудники\t"cGR"Просмотреть\n\
	        "cBLUE"2. "cWH"Статистика\t"cGR"Просмотреть");
	    SPD(playerid, DIALOG_CHANGE_MECHANIC, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление СТО:", String320, !"Выбрать", !"Закрыть"); 
	}
	else if(type == MECHANIC_BASE_STATION_3)
	{
	    format(String320, sizeof(String320), "\
	        "cGREY"Тип\t"cGREY"Действие\n\
	        "cLRED"1. "cWH"Сотрудники\t"cGR"Просмотреть\n\
	        "cLRED"2. "cWH"Статистика\t"cGR"Просмотреть");
	    SPD(playerid, DIALOG_CHANGE_MECHANIC, DIALOG_STYLE_TABLIST_HEADERS, !""cLRED"Управление СТО:", String320, !"Выбрать", !"Закрыть"); 
	}

	return true;
}

stock show_mech_menu_change(playerid, type)
{

	if(pData[playerid][pMechOwnerID] != type)
		return true;
	

	if(type == MECHANIC_BASE_STATION_1)
	{
	    format(String1024, sizeof(String1024), "\
	        "cGREY"Тип\t"cGREY"Действие\n\
	        "cORANGE"1. "cWH"Управление кассой\t"cGR"Открыть\n\
	        "cORANGE"2. "cWH"Изменение тарифов\t"cGR"Изменить\n\
	        "cORANGE"3. "cWH"Управление названием СТО\t"cGR"Изменить\n\
	        "cORANGE"4. "cWH"Изменение процента от прибыли\t"cGR"Изменить\n\
	        "cORANGE"5. "cWH"Покупка номера телефона\t"cGR"Купить\n\
	        "cORANGE"6. "cWH"Сотрудники\t"cGR"Просмотреть\n\
	        "cORANGE"7. "cWH"Статистика\t"cGR"Просмотреть\n\
	        "cORANGE"8. "cWH"Доставка незанятых эвакуаторов\t"cGR"2500 рублей\n\
	        "cORANGE"9. "cWH"Продать СТО\t"cGR"Продать");
	    SPD(playerid, DIALOG_CHANGE_MECHANIC, DIALOG_STYLE_TABLIST_HEADERS, !""cORANGE"Управление СТО:", String1024, !"Выбрать", !"Закрыть"); 
	}
	else if(type == MECHANIC_BASE_STATION_2)
	{
	    format(String1024, sizeof(String1024), "\
	        "cGREY"Тип\t"cGREY"Действие\n\
	        "cBLUE"1. "cWH"Управление кассой\t"cGR"Открыть\n\
	        "cBLUE"2. "cWH"Изменение тарифов\t"cGR"Изменить\n\
	        "cBLUE"3. "cWH"Управление названием СТО\t"cGR"Изменить\n\
	        "cBLUE"4. "cWH"Изменение процента от прибыли\t"cGR"Изменить\n\
	        "cBLUE"5. "cWH"Покупка номера телефона\t"cGR"Купить\n\
	        "cBLUE"6. "cWH"Сотрудники\t"cGR"Просмотреть\n\
	        "cBLUE"7. "cWH"Статистика\t"cGR"Просмотреть\n\
	        "cBLUE"8. "cWH"Доставка незанятых эвакуаторов\t"cGR"2500 рублей\n\
	        "cBLUE"9. "cWH"Продать СТО\t"cGR"Продать");
	    SPD(playerid, DIALOG_CHANGE_MECHANIC, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление СТО:", String1024, !"Выбрать", !"Закрыть"); 
	}
	else if(type == MECHANIC_BASE_STATION_3)
	{
	    format(String1024, sizeof(String1024), "\
	        "cGREY"Тип\t"cGREY"Действие\n\
	        "cLRED"1. "cWH"Управление кассой\t"cGR"Открыть\n\
	        "cLRED"2. "cWH"Изменение тарифов\t"cGR"Изменить\n\
	        "cLRED"3. "cWH"Управление названием СТО\t"cGR"Изменить\n\
	        "cLRED"4. "cWH"Изменение процента от прибыли\t"cGR"Изменить\n\
	        "cLRED"5. "cWH"Покупка номера телефона\t"cGR"Купить\n\
	        "cLRED"6. "cWH"Сотрудники\t"cGR"Просмотреть\n\
	        "cLRED"7. "cWH"Статистика\t"cGR"Просмотреть\n\
	        "cLRED"8. "cWH"Доставка незанятых эвакуаторов\t"cGR"2500 рублей\n\
	        "cLRED"9. "cWH"Продать СТО\t"cGR"Продать");
	    SPD(playerid, DIALOG_CHANGE_MECHANIC, DIALOG_STYLE_TABLIST_HEADERS, !""cLRED"Управление СТО:", String1024, !"Выбрать", !"Закрыть"); 
	}

	return true;
}

stock buy_mechanic_station(playerid, type)
{
	if(pData[playerid][pBusiness] != -1)
		return SendErr(playerid, "Вы не можете купить бизнес, так как уже владеете бизнесом!");
	if(pData[playerid][pHotelOwner] != -1)
		return SendErr(playerid, "Вы не можете купить бизнес, так как уже владеете отелем!");
	if(pData[playerid][pMechOwnerID] != -1)
		return SendErr(playerid,  "Вы не можете купить бизнес, так как уже владеете СТО!");
	if(pData[playerid][pFillStation] != -1)
		return SendErr(playerid,  "Вы не можете купить бизнес, так как уже владеете АЗС!");
	if(pData[playerid][pTaxiOwnerID] != -1)
		return SendErr(playerid,  "Вы не можете купить бизнес, так как уже владеете Таксопарком!");
	if(pData[playerid][pTruckerOwnerID] != -1)
		return SendErr(playerid,  "Вы не можете купить бизнес, так как уже владеете Транспортной Компанией!");
	if(pData[playerid][pCasinoOwner] != -1)
		return SendErr(playerid, "Вы не можете купить бизнес, так как уже владеете казино!");


	if(mechanic[type][mechanic_status_sell] == 3)
		return SendErr(playerid, "СТО недоступно в данный момент для покупки, так как оно опечатано");

	new 
		id_station_mechanic = GetPVarIntNew(playerid, "id_buy_mechanic_base");

	if(pData[playerid][pMoney] <= mechanic[id_station_mechanic][mechanic_base_price]) 
		return SendErr(playerid, "У вас недостаточно денег");

	mechanic[id_station_mechanic][mechanic_base_owner_id] = pData[playerid][pMysqlID];
	mechanic[id_station_mechanic][mechanic_base_days] = 3;
	mechanic[id_station_mechanic][mechanic_base_bank] = 0;

	pData[playerid][pMech] = id_station_mechanic;

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_buy_mech", 4000);

	new 
		mech_owner_str[32];

	format(mechanic[id_station_mechanic][mechanic_base_owner], 32, pData[playerid][pNickname]);
	format(mech_owner_str, 32, pData[playerid][pNickname]);

	format(String256,sizeof(String256),"UPDATE `mechanic` SET `owner_name` = '%s' WHERE `id` = '%d'" , mech_owner_str, id_station_mechanic);
	sql_queryEx(zConn, String256, QUERY_THREADED);	
	format(String256,sizeof(String256),"UPDATE `mechanic` SET `owner_id` = '%d' WHERE `id` = '%d'" , pData[playerid][pMysqlID], id_station_mechanic);
	sql_queryEx(zConn, String256, QUERY_THREADED);	

    pData[playerid][pMoney] -= mechanic[id_station_mechanic][mechanic_base_price];
    ResetPlayerMoney(playerid);
	GivePlayerMoney(playerid,pData[playerid][pMoney]);

	pData[playerid][pMechOwnerID] = type;

	if(type == MECHANIC_BASE_STATION_1)
	{	
		pData[playerid][pBusiness] = BUISNESS_MECHANIC_1;
	}
	else if(type == MECHANIC_BASE_STATION_2)
	{	
		pData[playerid][pBusiness] = BUISNESS_MECHANIC_2;
	}
	else if(type == MECHANIC_BASE_STATION_3)
	{	
		pData[playerid][pBusiness] = BUISNESS_MECHANIC_3;
	}

	update_mechanic_3d_text();	
	save_mechanic_base();
	update_mechanic_car_3d_t();


	format(String1024,sizeof(String1024),"INSERT INTO `mechanic_personal`(`id`,`user_id`,`user_rank`) VALUES ('%d','%d','%d')", id_station_mechanic, 
	pData[playerid][pMysqlID], 3);
	sql_queryEx(zConn, String1024, QUERY_THREADED);


	pData[playerid][pJob] = SKILL_MECHANIC;
	pData[playerid][pMechRank] = 3;
	UpdatePlayerData(playerid,"pMechRank", pData[playerid][pMechRank]);	
	UpdatePlayerData(playerid,"job", pData[playerid][pJob]);

	UpdatePlayerData(playerid,"mech",pData[playerid][pMech]);	
	UpdatePlayerData(playerid,"pMechOwnerID",pData[playerid][pMechOwnerID]);	
	UpdatePlayerData(playerid,"bussiness",pData[playerid][pBusiness]);			


	if(type == MECHANIC_BASE_STATION_1)
	{

		format(String320, sizeof(String320), "\
			"cWH"Поздравляем Вас с приобретением СТО!\n\n\
			Вы купили СТО №%d\n\n\
			"cWH"СТО автоматически оплачено на %d дня\n\
			Советуем Вам как можно быстрее посетить банк и продлить оплату",
			mechanic[id_station_mechanic][mechanic_base_id]+1,
			mechanic[id_station_mechanic][mechanic_base_days]);
		SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cORANGE"Приобритение СТО", String320, !"Понял", !"");
	}
	else if(type == MECHANIC_BASE_STATION_2)
	{

		format(String320, sizeof(String320), "\
			"cWH"Поздравляем Вас с приобретением СТО!\n\n\
			Вы купили СТО №%d\n\n\
			"cWH"СТО автоматически оплачено на %d дня\n\
			Советуем Вам как можно быстрее посетить банк и продлить оплату",
			mechanic[id_station_mechanic][mechanic_base_id]+1,
			mechanic[id_station_mechanic][mechanic_base_days]);
		SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Приобритение СТО", String320, !"Понял", !"");
	}	
	else if(type == MECHANIC_BASE_STATION_3)
	{

		format(String320, sizeof(String320), "\
			"cWH"Поздравляем Вас с приобретением СТО!\n\n\
			Вы купили СТО №%d\n\n\
			"cWH"СТО автоматически оплачено на %d дня\n\
			Советуем Вам как можно быстрее посетить банк и продлить оплату",
			mechanic[id_station_mechanic][mechanic_base_id]+1,
			mechanic[id_station_mechanic][mechanic_base_days]);
		SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cLRED"Приобритение СТО", String320, !"Понял", !"");
	}

	return true;

}


stock dialog_all_mechanic(playerid, dialogid, response, listitem, inputtext[])
{

	switch(dialogid)
	{
		case DIALOG_REPAIR_VEHICLE_ACCEPT:
		{
			if(!response)
			{	
				new 
					mechanic_id = GetPVarIntNew(playerid, "mechanic_offer_id");

			    format(String144, sizeof(String144), "Клиент %s отказался от ремонта транспортного средства!", pData[playerid][pNickname]);
			    SendInf(mechanic_id, String144);				
			    SendSucc(playerid, "Вы успешно отказались от ремонта транспортного средства!");
				DeletePVarNew(playerid, "mechanic_offer_id");

				offer_clear_accept(playerid);
				offer_clear_accept(mechanic_id);

				return true;
			}
			new 
				mechanic_id = GetPVarIntNew(playerid, "mechanic_offer_id");


			mechanic_repair_vehicle(playerid, mechanic_id);

			return true;
		}
		case DIALOG_FILLING_VEHICLE_ACCEPT:
		{

			if(!response)
			{	
				new 
					mechanic_id = GetPVarIntNew(playerid, "mechanic_offer_id");

			    format(String144, sizeof(String144), "Клиент %s отказался от заправки транспортного средства!", pData[playerid][pNickname]);
			    SendInf(mechanic_id, String144);				
			    SendSucc(playerid, "Вы успешно отказались от заправки транспортного средства!");
				DeletePVarNew(playerid, "mechanic_offer_id");

				offer_clear_accept(playerid);
				offer_clear_accept(mechanic_id);


				return true;
			}
			new 
				mechanic_id = GetPVarIntNew(playerid, "mechanic_offer_id");


			mechanic_refill_vehicle(playerid, mechanic_id);

			return true;


		}
		case DIALOG_FILL_OIL_VEHICLE_ACCEPT:
		{
			if(!response)
			{	
				new 
					mechanic_id = GetPVarIntNew(playerid, "mechanic_offer_id");

			    format(String144, sizeof(String144), "Клиент %s отказался от заправки транспортного средства!", pData[playerid][pNickname]);
			    SendInf(mechanic_id, String144);				
			    SendSucc(playerid, "Вы успешно отказались от заправки транспортного средства!");
				DeletePVarNew(playerid, "mechanic_offer_id");

				offer_clear_accept(playerid);
				offer_clear_accept(mechanic_id);

				return true;
			}
			new 
				mechanic_id = GetPVarIntNew(playerid, "mechanic_offer_id");

			mechanic_reoil_vehicle(playerid, mechanic_id);

		}
		case DIALOG_INVITE_M_P_ACCEPT:
		{
			if(!response)
			{
				DeletePVarNew(playerid, "id_mechanic");
				return true;
			}
			invite_mechanic_station_dialog(playerid);

		}

		case DIALOG_RENT_VEHICLE_MECH:
		{
			if(!response)
				return true;

			create_vehicle_rent_mech(playerid);

		}
		
		case DIALOG_BUY_MECHANIC: 
		{
			if(!response)
			{
				DeletePVarNew(playerid, "id_buy_mechanic_base");
				return true;
			}

			if(pData[playerid][pBusiness] != -1)
				return SendErr(playerid, "Вы не можете купить бизнес, так как уже владеете бизнесом!");

			if(pData[playerid][pHotelOwner] != -1)
				return SendErr(playerid, "Вы не можете купить бизнес, так как уже владеете отелем!");

			if(pData[playerid][pMechOwnerID] != -1)
				return SendErr(playerid,  "Вы не можете купить бизнес, так как уже владеете СТО!");
			
			buy_mechanic_station(playerid, GetPVarIntNew(playerid, "id_buy_mechanic_base"));
		}

		case DIALOG_CHANGE_MECHANIC: 
		{
			if(!response)
				return true;

			switch(listitem) 
			{
				case 0: return change_bank_mechanic(playerid);
				case 1: return change_tarif_mechanic(playerid);
				case 2: return change_name_mechanic(playerid);
				case 3: return change_percent_mechanic(playerid);
				case 4: return change_phone_mechanic(playerid);
				case 5: return change_personal_mechanic(playerid);	
				case 6: return change_statistic_mechanic(playerid);
				case 7: return respawn_mechanic_vehicle(playerid, pData[playerid][pMech]);
				case 8: return sell_mechanic_accept(playerid);
			}
		}
		case DIALOG_CHANGE_MECHANIC_BANK:
		{
			new 
				id_mechanic;

			if(pData[playerid][pMechOwnerID] != -1)
			{
				id_mechanic = pData[playerid][pMechOwnerID];		
			}
			else
			{
				id_mechanic = pData[playerid][pMechOwnerLowID];
			}

			if(!response) 
				return show_mech_menu_change(playerid, id_mechanic);	
				
			switch(listitem) 
			{
				case 0: return mech_bank_operation(playerid, 1);
				case 1: return mech_bank_operation(playerid, 2);
			}

		}
		case DIALOG_ACCEPT_SELL_MECHANIC:
		{
			if(!response) 
				return change_bank_mechanic(playerid);
			
			new 
				id_mechanic = pData[playerid][pMechOwnerID];

			sell_mechanic(playerid, id_mechanic);			
		}
		case DIALOG_MECHANIC_INPUT_MONEY:
		{
			if(!response) 
				return change_bank_mechanic(playerid);

			if(!IsNumeric(inputtext)) 
				return SendErr(playerid,"Вы указали неверное количество денег");


			new 
				id_mechanic;

			if(pData[playerid][pMechOwnerID] != -1)
			{
				id_mechanic = pData[playerid][pMechOwnerID];		
			}
			else
			{
				id_mechanic = pData[playerid][pMechOwnerLowID];
			}

			new 
				count_money = strval(inputtext);

			if(count_money < 1)
			{
				SendErr(playerid,"Вы указали неверное количество денег!");
				return change_bank_mechanic(playerid);
			}

			if(mechanic[id_mechanic][mechanic_base_bank] < count_money)
			{
				change_bank_mechanic(playerid);
				return SendErr(playerid,"Недостаточно денег в кассе СТО!");
			}

			mechanic[id_mechanic][mechanic_base_bank] -= count_money;

		 	format(String144, sizeof(String144), "Снятие с кассы СТО №%d", id_mechanic);
			give_money(playerid, count_money, String144);


			SFCM(playerid,COLOR_BLUE,!"• {FFC800}[Подсказка] "cWH"Вы сняли с кассы СТО - %d рублей", count_money);	

		}
		case DIALOG_MECHANIC_PUT_MONEY:
		{
			if(!response) 
				return change_bank_mechanic(playerid);

			if(!IsNumeric(inputtext)) 
				return SendErr(playerid,"Вы указали неверное количество денег");

			new 
				id_mechanic;

			if(pData[playerid][pMechOwnerID] != -1)
			{
				id_mechanic = pData[playerid][pMechOwnerID];		
			}
			else
			{
				id_mechanic = pData[playerid][pMechOwnerLowID];
			}

			new 
				count_money = strval(inputtext);

			if(count_money < 1)
			{
				SendErr(playerid,"Вы указали неверное количество денег!");
				return change_bank_mechanic(playerid);
			}

			if(pData[playerid][pMoney] < count_money)
			{
				change_bank_mechanic(playerid);
				return SendErr(playerid,"Недостаточно денег, чтобы положить в кассу!");
			}

			mechanic[id_mechanic][mechanic_base_bank] += count_money;

		 	format(String144, sizeof(String144), "Пополнение кассы СТО №%d", id_mechanic);
			give_money(playerid, -count_money, String144);	

			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы пополнили кассу СТО на %d рублей", count_money);		

		}	
		case DIALOG_CHANGE_TARIF_MECHANIC:
		{
			new 
				id_mechanic;

			if(pData[playerid][pMechOwnerID] != -1)
			{
				id_mechanic = pData[playerid][pMechOwnerID];		
			}
			else
			{
				id_mechanic = pData[playerid][pMechOwnerLowID];
			}

			if(!response) 
				return show_mech_menu_change(playerid, id_mechanic);		
				
			switch(listitem) 
			{
				case 0: return change_tarif_mech(playerid, 1);
				case 1: return change_tarif_mech(playerid, 2);
				case 2: return change_tarif_mech(playerid, 3);
				case 3: return change_tarif_mech(playerid, 4);
				case 4: return change_tarif_mech(playerid, 5);
				case 5: return change_tarif_mech(playerid, 6);
				case 6: return change_tarif_mech(playerid, 7);
				case 7: return change_tarif_mech(playerid, 8);
				case 8: return change_tarif_mech(playerid, 9);
				case 9: return change_tarif_mech(playerid, 10);
			}

		}	
		case DIALOG_CHG_TARIF_MECH_1:
		{
			if(!response) 
				return change_tarif_mechanic(playerid);	

			if(!IsNumeric(inputtext)) 
				return SendErr(playerid,"Вы указали неверную стоимость!");

			new 
				id_mechanic;

			if(pData[playerid][pMechOwnerID] != -1)
			{
				id_mechanic = pData[playerid][pMechOwnerID];		
			}
			else
			{
				id_mechanic = pData[playerid][pMechOwnerLowID];
			}

			new 
				count_money = strval(inputtext);

			if(count_money < 1)
			{
			    SendErr(playerid,"От 10 до 20 рублей за 1 литр топлива!");
				return change_tarif_mechanic(playerid);	
			}

			if(count_money < 10 || count_money > 20)
			{
			    SendErr(playerid,"От 10 до 20 рублей за 1 литр топлива!");
				return change_tarif_mechanic(playerid);	
			}	

			mechanic[id_mechanic][mechanic_price_fuel] = count_money;

			SendSucc(playerid, "Тариф на заправку топливом был обновлен!");

			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Новая цена заправки за 1 литр - "cGR"%d"cWH" рублей", count_money);	

		    change_tarif_mechanic(playerid);	
		    update_mechanic_car_3d_t();

		}

		case DIALOG_CHG_TARIF_MECH_2:
		{
			if(!response) 
				return change_tarif_mechanic(playerid);	

			if(!IsNumeric(inputtext)) 
				return SendErr(playerid,"Вы указали неверную стоимость!");

			new 
				id_mechanic;

			if(pData[playerid][pMechOwnerID] != -1)
			{
				id_mechanic = pData[playerid][pMechOwnerID];		
			}
			else
			{
				id_mechanic = pData[playerid][pMechOwnerLowID];
			}

			new 
				count_money = strval(inputtext);

			if(count_money < 1)
			{
			    SendErr(playerid,"От 1500 до 3500 рублей за ремонт!");
				return change_tarif_mechanic(playerid);	
			}

			if(count_money < 1500 || count_money > 3500)
			{
			    SendErr(playerid,"От 1500 до 3500 рублей за ремонт!");
				return change_tarif_mechanic(playerid);	
			}	

			mechanic[id_mechanic][mechanic_price_remont] = count_money;

			SendSucc(playerid, "Тариф на ремонт был обновлен!");

			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Новая цена ремонта - "cGR"%d"cWH" рублей", count_money);	

			change_tarif_mechanic(playerid);	
			update_mechanic_car_3d_t();


		}

		case DIALOG_CHG_TARIF_MECH_3:
		{
			if(!response) 
				return change_tarif_mechanic(playerid);	
			
			if(!IsNumeric(inputtext)) 
				return SendErr(playerid,"Вы указали неверную стоимость!");

			new 
				id_mechanic;

			if(pData[playerid][pMechOwnerID] != -1)
			{
				id_mechanic = pData[playerid][pMechOwnerID];		
			}
			else
			{
				id_mechanic = pData[playerid][pMechOwnerLowID];
			}

			new 
				count_money = strval(inputtext);

			if(count_money < 500 || count_money > 1500)
			{
			    SendErr(playerid,"От 500 до 1500 рублей за 1 литр масла!");
				return change_tarif_mechanic(playerid);	
			}	

			mechanic[id_mechanic][mechanic_price_oil] = count_money;

			SendSucc(playerid, "Тариф на заправку 1 литра масла был обновлен!");

			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Новая цена масла за 1 литр - "cGR"%d"cWH" рублей", count_money);	

			change_tarif_mechanic(playerid);	
		}

		case DIALOG_CHG_TARIF_MECH_4:
		{
			if(!response) 
				return change_tarif_mechanic(playerid);	
			
			if(!IsNumeric(inputtext)) 
				return SendErr(playerid,"Вы указали неверную стоимость!");

			new 
				id_mechanic;

			if(pData[playerid][pMechOwnerID] != -1)
			{
				id_mechanic = pData[playerid][pMechOwnerID];		
			}
			else
			{
				id_mechanic = pData[playerid][pMechOwnerLowID];
			}

			new 
				count_money = strval(inputtext);

			if(count_money < 500 || count_money > 1500)
			{
			    SendErr(playerid,"От 500 до 1500 рублей за замену свечей!");
				return change_tarif_mechanic(playerid);	
			}	

			mechanic[id_mechanic][mechanic_price_candles] = count_money;

			SendSucc(playerid, "Тариф на замену свечей был обновлен!");

			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Новая цена замены свечей - "cGR"%d"cWH" рублей", count_money);	

			change_tarif_mechanic(playerid);	


		}

		case DIALOG_CHG_TARIF_MECH_5:
		{
			if(!response) 
				return change_tarif_mechanic(playerid);	
			
			if(!IsNumeric(inputtext)) 
				return SendErr(playerid,"Вы указали неверную стоимость!");

			new 
				id_mechanic;

			if(pData[playerid][pMechOwnerID] != -1)
			{
				id_mechanic = pData[playerid][pMechOwnerID];		
			}
			else
			{
				id_mechanic = pData[playerid][pMechOwnerLowID];
			}

			new 
				count_money = strval(inputtext);

			if(count_money < 10000 || count_money > 25000)
			{
			    SendErr(playerid,"От 10000 до 25000 рублей за замену тормозов!");
				return change_tarif_mechanic(playerid);	
			}	

			mechanic[id_mechanic][mechanic_price_brake] = count_money;

			SendSucc(playerid, "Тариф на замену тормозов был обновлен!");

			SFCM(playerid,COLOR_BLUE, "• {FFC800}[Подсказка] "cWH"Новая цена замены тормозов - "cGR"%d"cWH" рублей", count_money);	

			change_tarif_mechanic(playerid);	

		}
						
		case DIALOG_CHG_TARIF_MECH_6:
		{
			if(!response) 
				return change_tarif_mechanic(playerid);	
			
			if(!IsNumeric(inputtext)) 
				return SendErr(playerid,"Вы указали неверную стоимость!");

			new 
				id_mechanic;

			if(pData[playerid][pMechOwnerID] != -1)
			{
				id_mechanic = pData[playerid][pMechOwnerID];		
			}
			else
			{
				id_mechanic = pData[playerid][pMechOwnerLowID];
			}

			new 
				count_money = strval(inputtext);

			if(count_money < 2500 || count_money > 5000)
			{
			    SendErr(playerid,"От 2500 до 5000 рублей за замену ремней!");
				return change_tarif_mechanic(playerid);	
			}	

			mechanic[id_mechanic][mechanic_price_belt] = count_money;

			SendSucc(playerid, "Тариф на замену ремней был обновлен!");

			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Новая цена замены ремней - "cGR"%d"cWH" рублей", count_money);	

			change_tarif_mechanic(playerid);	

		}

		case DIALOG_CHG_TARIF_MECH_7:
		{
			if(!response) 
				return change_tarif_mechanic(playerid);	
			
			if(!IsNumeric(inputtext)) 
				return SendErr(playerid,"Вы указали неверную стоимость!");

			new 
				id_mechanic;

			if(pData[playerid][pMechOwnerID] != -1)
			{
				id_mechanic = pData[playerid][pMechOwnerID];		
			}
			else
			{
				id_mechanic = pData[playerid][pMechOwnerLowID];
			}

			new 
				count_money = strval(inputtext);

			if(count_money < 1000 || count_money > 3000)
			{
			    SendErr(playerid,"От 1000 до 3000 рублей за замену стартера!");
				return change_tarif_mechanic(playerid);	
			}	

			mechanic[id_mechanic][mechanic_price_starter] = count_money;

			SendSucc(playerid, "Тариф на замену стартера был обновлен!");

			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Новая цена замены стартера - "cGR"%d"cWH" рублей", count_money);	

			change_tarif_mechanic(playerid);	


		}

		case DIALOG_CHG_TARIF_MECH_8:
		{
			if(!response) 
				return change_tarif_mechanic(playerid);	
			
			if(!IsNumeric(inputtext)) 
				return SendErr(playerid,"Вы указали неверную стоимость!");

			new 
				id_mechanic;

			if(pData[playerid][pMechOwnerID] != -1)
			{
				id_mechanic = pData[playerid][pMechOwnerID];		
			}
			else
			{
				id_mechanic = pData[playerid][pMechOwnerLowID];
			}

			new 
				count_money = strval(inputtext);

			if(count_money < 1000 || count_money > 3000)
			{
			    SendErr(playerid,"От 3000 до 8000 рублей за замену генератора!");
				return change_tarif_mechanic(playerid);	
			}	

			mechanic[id_mechanic][mechanic_price_generator] = count_money;

			SendSucc(playerid, "Тариф на замену генератора был обновлен!");

			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Новая цена замены генератора - "cGR"%d"cWH" рублей", count_money);	

			change_tarif_mechanic(playerid);	


		}

		case DIALOG_CHG_TARIF_MECH_9:
		{
			if(!response) 
				return change_tarif_mechanic(playerid);	
			
			if(!IsNumeric(inputtext)) 
				return SendErr(playerid,"Вы указали неверную стоимость!");

			new 
				id_mechanic;

			if(pData[playerid][pMechOwnerID] != -1)
			{
				id_mechanic = pData[playerid][pMechOwnerID];		
			}
			else
			{
				id_mechanic = pData[playerid][pMechOwnerLowID];
			}

			new 
				count_money = strval(inputtext);

			if(count_money < 3000 || count_money > 5000)
			{
			    SendErr(playerid,"От 3000 до 5000 рублей за замену форсунок!");
				return change_tarif_mechanic(playerid);	
			}	

			mechanic[id_mechanic][mechanic_price_forsunki] = count_money;

			SendSucc(playerid, "Тариф на замену форсунок был обновлен!");

			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Новая цена замены форсунок - "cGR"%d"cWH" рублей", count_money);	

			change_tarif_mechanic(playerid);	

		}


		case DIALOG_CHG_TARIF_MECH_10:
		{
			if(!response) 
				return change_tarif_mechanic(playerid);	
			
			if(!IsNumeric(inputtext)) 
				return SendErr(playerid,"Вы указали неверную стоимость!");

			new 
				id_mechanic;

			if(pData[playerid][pMechOwnerID] != -1)
			{
				id_mechanic = pData[playerid][pMechOwnerID];		
			}
			else
			{
				id_mechanic = pData[playerid][pMechOwnerLowID];
			}

			new 
				count_money = strval(inputtext);

			if(count_money < 3000 || count_money > 5000)
			{
			    SendErr(playerid,"От 3000 до 5000 рублей за замену насоса!");
				return change_tarif_mechanic(playerid);	
			}	

			mechanic[id_mechanic][mechanic_price_nasos] = count_money;

			SendSucc(playerid, "Тариф на замену насоса был обновлен!");

			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Новая цена замены насоса - "cGR"%d"cWH" рублей", count_money);	

			change_tarif_mechanic(playerid);	

		}
		case DIALOG_CHANGE_PERCENT_MECHANIC:
		{
			new 
				id_mechanic;

			if(pData[playerid][pMechOwnerID] != -1)
			{
				id_mechanic = pData[playerid][pMechOwnerID];		
			}
			else
			{
				id_mechanic = pData[playerid][pMechOwnerLowID];
			}

			if(!response) 
				return show_mech_menu_change(playerid, id_mechanic);	
			
			
			if(!IsNumeric(inputtext)) 
				return SendErr(playerid,"Вы указали неверный процент!");


			new 
				count_money = strval(inputtext);	

			if(count_money < 1 || count_money > 50)
			{
			    SendErr(playerid,"От 1 до 50 процентов!");
				return show_mech_menu_change(playerid, id_mechanic);	
			}	

			mechanic[id_mechanic][mechanic_base_percent] = count_money;		

			SendSucc(playerid, "Процент от прибыли был успешно обновлен!");

			SFCM(playerid,0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Новый процент от прибыли - "cGR"%d%%"cWH"", count_money);	

			show_mech_menu_change(playerid, id_mechanic);	

		}
		case DIALOG_CHANGE_MECH_PHONE:
		{
			new 
				id_mechanic;

			if(pData[playerid][pMechOwnerID] != -1)
			{
				id_mechanic = pData[playerid][pMechOwnerID];		
			}
			else
			{
				id_mechanic = pData[playerid][pMechOwnerLowID];
			}

			if(!response) 
				return show_mech_menu_change(playerid, id_mechanic);	
			
			if(!IsNumeric(inputtext)) 
				return SendErr(playerid,"Вы указали неверный номер телефона!");

			new 
				phone_mech_new = strval(inputtext);

			new 
				price_buy = 50000;

			if( phone_mech_new < 1000 || phone_mech_new >= 9900 )
			{
				change_phone_mechanic(playerid);
			    return SendErr(playerid, "Неверное значение номера телефона!");
			}

			if(inputtext[0] ==  inputtext[1] &&  inputtext[1] ==  inputtext[2] &&  inputtext[2] ==  inputtext[3]) price_buy = 300000;

			if(price_buy > mechanic[id_mechanic][mechanic_base_bank])
			{
				change_phone_mechanic(playerid);
				return SendErr(playerid, "Недостаточно средств в кассе СТО!");
			}

			new 
				query[144];

			format(query,sizeof(query),"SELECT `id` FROM `accounts` WHERE `phone` = '%i'", phone_mech_new);
			new Result:r = sql_queryEx(zConn, query);
			if(sql_num_rows(r))
			{
				SendErr(playerid, "Данный номер телефона используется уже кем-то другим!");
				return sql_free_result(r);
			}
			sql_free_result(r);

			mechanic[id_mechanic][mechanic_base_bank] -= price_buy;
			mechanic[id_mechanic][mechanic_base_phone] = phone_mech_new;

			SFCM(playerid,0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Новый номер телефона - {FFC800}%d"cWH"", phone_mech_new);	

			update_mechanic_3d_text();
			update_mechanic_car_3d_t();

		}
		case DIALOG_CHANGE_MECH_NAME:
		{	

			new 
				id_mechanic;

			if(pData[playerid][pMechOwnerID] != -1)
			{
				id_mechanic = pData[playerid][pMechOwnerID];		
			}
			else
			{
				id_mechanic = pData[playerid][pMechOwnerLowID];
			} 

			if(!response) 
				return show_mech_menu_change(playerid, id_mechanic);	

			if(strlen(inputtext) < 3 || strlen(inputtext) > 20)
			{
			    SendErr(playerid,"Слишком короткое/длинное название СТО");
				return change_name_mechanic(playerid);
			}
			if(IsNumeric(inputtext) || check_no_valid_symbol_text(inputtext) || check_sql_injection_text(inputtext))
			{
				change_name_mechanic(playerid);
				return SendErr(playerid,"Название содержит запрещенные символы!");
			}

 			format(String2048, sizeof(String2048), "SELECT * FROM `mechanic` WHERE `mechanic_base_name` = '%s'", inputtext);
			new Result:r3 = sql_queryEx(zConn, String2048, QUERY_CACHED);
			new numrr = sql_num_rows(r3);
	        sql_free_result(r3);

			if(numrr)
			{
			    SendErr(playerid,"Данное название уже занято одной из СТО");
				return change_name_mechanic(playerid);
			}

			format(mechanic[id_mechanic][mechanic_base_name], 20, inputtext);
			format(String256,sizeof(String256),"UPDATE `mechanic` SET `mechanic_base_name` = '%s' WHERE `id` = '%d'" , inputtext, id_mechanic);
			sql_queryEx(zConn, String256, QUERY_THREADED);

			format(String256,sizeof(String256),"Новое название вашей СТО: %s", inputtext);
		    SendSucc(playerid,String256);

		    update_mechanic_3d_text();
		    update_mechanic_car_3d_t();

		}
		case DIALOG_MECHANIC_CHANGE_PERS:
		{

			new 
				id_mechanic;

			if(pData[playerid][pMechOwnerID] != -1)
			{
				id_mechanic = pData[playerid][pMechOwnerID];		
			}
			else
			{
				id_mechanic = pData[playerid][pMechOwnerLowID];
			}

			if(!response) 
				return show_mech_menu_change(playerid, id_mechanic);	

			if(listitem == 20) 
			{
				return change_personal_mechanic(playerid, GetPVarIntNew(playerid, "check_page_panel_mech")+1);
			}
			else if(listitem == 21 || GetPVarIntNew(playerid, "button_back_personal_menu") == listitem && listitem != 0) 
			{
				return change_personal_mechanic(playerid, GetPVarIntNew(playerid, "check_page_panel_mech")-1);
			}

			new 
				id = dialog_listitem_values[playerid][listitem];


			return change_rank_personal_mech(playerid, id);			
		}
		case DIALOG_MECHANIC_CHANGE_PERS_2:
		{

			new 
				id_mechanic;

			if(pData[playerid][pMechOwnerID] != -1)
			{
				id_mechanic = pData[playerid][pMechOwnerID];		
			}
			else
			{
				id_mechanic = pData[playerid][pMechOwnerLowID];
			}

			if(!response) 
				return show_mech_menu_change(playerid, id_mechanic);	

			new 
				id = GetPVarIntNew(playerid, "uninvite_mech_id");

				
			switch(listitem) 
			{
				case 2: return give_rank_mech_mech(playerid, id);
				case 3: return give_rank_manager_mech(playerid, id);
				case 4: return uninvite_panel_pers_mech(playerid, id);
			}			
		}
		case DIALOG_START_MECH_JOB:
		{
			if(!response) return true;
			if(!GetPVarIntNew(playerid, "mechanic_job"))
				return start_mechanic_job(playerid);
			else
				return end_mechanic_job(playerid);			
		}
		case DIALOG_START_MECH_JOB_1:
		{
			if(!response) 
				return true;	
				
			switch(listitem) 
			{
				case 0: return dialog_job_mechanic(playerid);
				case 1: return mechanic_job_stats(playerid);
				case 2: return uninvite_mechanic_personal(playerid);
			}				
		}
		case DIALOG_PERSONAL_CLOSE:
		{
			new 
				id_mechanic;

			if(pData[playerid][pMechOwnerID] != -1)
			{
				id_mechanic = pData[playerid][pMechOwnerID];		
			}
			else
			{
				id_mechanic = pData[playerid][pMechOwnerLowID];
			}

			if(!response) 
				return show_mech_menu_change(playerid, id_mechanic);

			show_mech_menu_change(playerid, id_mechanic);
		}

		case DIALOG_SELECT_ENGINE_MECH:
		{
			if(!response) 
				return clear_pvar_client_mech_all(playerid);

			switch(listitem) 
			{
				case 0: return select_engine_rem_list(playerid, 1);
				case 1: return select_engine_rem_list(playerid, 2);
				case 2: return select_engine_rem_list(playerid, 3);
				case 3: return select_engine_rem_list(playerid, 4);
				case 4: return select_engine_rem_list(playerid, 5);
				case 5: return select_engine_rem_list(playerid, 6);
				case 6: return select_engine_rem_list(playerid,7);
				case 7: return select_engine_rem_list(playerid, 8);
				case 8: return true;
				case 9: return accept_engine_rem(playerid);
				case 10: return clear_engine_rem(playerid);
			}						
		}
	}
	return true;

}

stock change_phone_mechanic(playerid)
{
	new 
		id_mechanic;


	if(pData[playerid][pMechOwnerID] != -1)
	{
		id_mechanic = pData[playerid][pMechOwnerID];		
	}
	else if(pData[playerid][pMechOwnerLowID] != -1)
	{
		id_mechanic = pData[playerid][pMechOwnerLowID];
	}


	if(id_mechanic == MECHANIC_BASE_STATION_1)
	{
	    format(String1024, sizeof(String1024), "\n\n\
	    "cWH"Текущий номер телефона вашей СТО: "cORANGE"%d"cWH"\n\n\
	    "cWH"Введите желаемый новый номер телефона для вашей СТО\n\
		Доступный диапазон: от "cORANGE"1000"cWH" до "cORANGE"9900"cWH"\n\
		Стоимость номера: "cGR"%dp"cWH"\n\
		Стоимость номера c 4 одинаковыми числами: "cGR"%dp"cWH"\n\n\n",mechanic[id_mechanic][mechanic_base_phone],50000,300000);
	    SPD(playerid,DIALOG_CHANGE_MECH_PHONE, DIALOG_STYLE_INPUT ,""cORANGE"Управление СТО",String1024, !"Выбрать", !"Закрыть"); 
	}
	else if(id_mechanic == MECHANIC_BASE_STATION_2)
	{
	    format(String1024, sizeof(String1024), "\n\n\
	    "cWH"Текущий номер телефона вашей СТО: "cBLUE"%d"cWH"\n\n\
	    "cWH"Введите желаемый новый номер телефона для вашей СТО\n\
		Доступный диапазон: от "cBLUE"1000"cWH" до "cBLUE"9900"cWH"\n\
		Стоимость номера: "cGR"%dp"cWH"\n\
		Стоимость номера c 4 одинаковыми числами: "cGR"%dp"cWH"\n\n\n",mechanic[id_mechanic][mechanic_base_phone],50000,300000);
	    SPD(playerid,DIALOG_CHANGE_MECH_PHONE, DIALOG_STYLE_INPUT ,""cBLUE"Управление СТО",String1024, !"Выбрать", !"Закрыть"); 
	}	
	else if(id_mechanic == MECHANIC_BASE_STATION_3)
	{
	    format(String1024, sizeof(String1024), "\n\n\
	    "cWH"Текущий номер телефона вашей СТО: "cLRED"%d"cWH"\n\n\
	    "cWH"Введите желаемый новый номер телефона для вашей СТО\n\
		Доступный диапазон: от "cLRED"1000"cWH" до "cLRED"9900"cWH"\n\
		Стоимость номера: "cGR"%dp"cWH"\n\
		Стоимость номера c 4 одинаковыми числами: "cGR"%dp"cWH"\n\n\n",mechanic[id_mechanic][mechanic_base_phone],50000,300000);
	    SPD(playerid,DIALOG_CHANGE_MECH_PHONE, DIALOG_STYLE_INPUT ,""cLRED"Управление СТО",String1024, !"Выбрать", !"Закрыть"); 
	}	
	return true;
}

stock change_name_mechanic(playerid)
{

	new 
		id_mechanic;


	if(pData[playerid][pMechOwnerID] != -1)
	{
		id_mechanic = pData[playerid][pMechOwnerID];		
	}
	else if(pData[playerid][pMechOwnerLowID] != -1)
	{
		id_mechanic = pData[playerid][pMechOwnerLowID];
	}


	if(id_mechanic == MECHANIC_BASE_STATION_1)
	{

		SPD(playerid,DIALOG_CHANGE_MECH_NAME,1,""cORANGE"Изменить название СТО","\n\n\
			"cORANGE"Введите новое название СТО:\n\n\
			"cWH"Минимальное количество символов: "cORANGE"3"cWH"\n\
			"cWH"Максимальное количество символов: "cORANGE"20"cWH"","Далее","Закрыть");
	}
	else if(id_mechanic == MECHANIC_BASE_STATION_2)
	{

		SPD(playerid,DIALOG_CHANGE_MECH_NAME,1,""cBLUE"Изменить название СТО","\n\n\
			"cBLUE"Введите новое название СТО:\n\n\
			"cWH"Минимальное количество символов: "cBLUE"3"cWH"\n\
			"cWH"Максимальное количество символов: "cBLUE"20"cWH"","Далее","Закрыть");
	}	
	else if(id_mechanic == MECHANIC_BASE_STATION_3)
	{

		SPD(playerid,DIALOG_CHANGE_MECH_NAME,1,""cLRED"Изменить название СТО","\n\n\
			"cLRED"Введите новое название СТО:\n\n\
			"cWH"Минимальное количество символов: "cLRED"3"cWH"\n\
			"cWH"Максимальное количество символов: "cLRED"20"cWH"","Далее","Закрыть");
	}
	return true;
}

stock change_percent_mechanic(playerid)
{
	new 
		id_mechanic;

	if(pData[playerid][pMechOwnerID] != -1)
	{
		id_mechanic = pData[playerid][pMechOwnerID];		
	}
	else
	{
		id_mechanic = pData[playerid][pMechOwnerLowID];
	}

	new 
		fmt_str[150];

	format(fmt_str, 150, "\
	"cWH"Укажите процент, который будете получать с прибыли (От 1 процента до 50 процентов)\n\n\
	Текущий процент: "cGR"%d"cWH" процент(ов)", mechanic[id_mechanic][mechanic_base_percent]);

	return SPD(playerid, DIALOG_CHANGE_PERCENT_MECHANIC, DIALOG_STYLE_INPUT, !""cWH"Изменение стоимости", fmt_str, !"Далее", !"Назад");
}

stock change_tarif_mechanic(playerid)
{
	new 
		id_mechanic;


	if(pData[playerid][pMechOwnerID] != -1)
	{
		id_mechanic = pData[playerid][pMechOwnerID];		
	}
	else if(pData[playerid][pMechOwnerLowID] != -1)
	{
		id_mechanic = pData[playerid][pMechOwnerLowID];
	}

	if(id_mechanic == MECHANIC_BASE_STATION_1)
	{
	    format(String1024, sizeof(String1024), "\
	        "cGREY"Тип\t"cGREY"Действие\n\
	        "cORANGE"1. "cWH"Тариф на топливо\t"cGR"Изменить\n\
	        "cORANGE"2. "cWH"Тариф на ремонт\t"cGR"Изменить\n\
	        "cORANGE"3. "cWH"Тариф на масло\t"cGR"Изменить\n\
	        "cORANGE"4. "cWH"Тариф на свечи\t"cGR"Изменить\n\
	        "cORANGE"5. "cWH"Тариф на тормоза\t"cGR"Изменить\n\
	        "cORANGE"6. "cWH"Тариф на ремни\t"cGR"Изменить\n\
	        "cORANGE"7. "cWH"Тариф на стартер\t"cGR"Изменить\n\
	        "cORANGE"8. "cWH"Тариф на генератор\t"cGR"Изменить\n\
	        "cORANGE"9. "cWH"Тариф на форсунки\t"cGR"Изменить\n\
	        "cORANGE"10. "cWH"Тариф на насос\t"cGR"Изменить");
	    SPD(playerid, DIALOG_CHANGE_TARIF_MECHANIC, DIALOG_STYLE_TABLIST_HEADERS, !""cORANGE"Управление СТО:", String1024, !"Выбрать", !"Закрыть"); 
	}
	else if(id_mechanic == MECHANIC_BASE_STATION_2)
	{
	    format(String1024, sizeof(String1024), "\
	        "cGREY"Тип\t"cGREY"Действие\n\
	        "cBLUE"1. "cWH"Тариф на топливо\t"cGR"Изменить\n\
	        "cBLUE"2. "cWH"Тариф на ремонт\t"cGR"Изменить\n\
	        "cBLUE"3. "cWH"Тариф на масло\t"cGR"Изменить\n\
	        "cBLUE"4. "cWH"Тариф на свечи\t"cGR"Изменить\n\
	        "cBLUE"5. "cWH"Тариф на тормоза\t"cGR"Изменить\n\
	        "cBLUE"6. "cWH"Тариф на ремни\t"cGR"Изменить\n\
	        "cBLUE"7. "cWH"Тариф на стартер\t"cGR"Изменить\n\
	        "cBLUE"8. "cWH"Тариф на генератор\t"cGR"Изменить\n\
	        "cBLUE"9. "cWH"Тариф на форсунки\t"cGR"Изменить\n\
	        "cBLUE"10. "cWH"Тариф на насос\t"cGR"Изменить");
	    SPD(playerid, DIALOG_CHANGE_TARIF_MECHANIC, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление СТО:", String1024, !"Выбрать", !"Закрыть"); 
	}
	else if(id_mechanic == MECHANIC_BASE_STATION_3)
	{
	    format(String1024, sizeof(String1024), "\
	        "cGREY"Тип\t"cGREY"Действие\n\
	        "cLRED"1. "cWH"Тариф на топливо\t"cGR"Изменить\n\
	        "cLRED"2. "cWH"Тариф на ремонт\t"cGR"Изменить\n\
	        "cLRED"3. "cWH"Тариф на масло\t"cGR"Изменить\n\
	        "cLRED"4. "cWH"Тариф на свечи\t"cGR"Изменить\n\
	        "cLRED"5. "cWH"Тариф на тормоза\t"cGR"Изменить\n\
	        "cLRED"6. "cWH"Тариф на ремни\t"cGR"Изменить\n\
	        "cLRED"7. "cWH"Тариф на стартер\t"cGR"Изменить\n\
	        "cLRED"8. "cWH"Тариф на генератор\t"cGR"Изменить\n\
	        "cLRED"9. "cWH"Тариф на форсунки\t"cGR"Изменить\n\
	        "cLRED"10. "cWH"Тариф на насос\t"cGR"Изменить");
	    SPD(playerid, DIALOG_CHANGE_TARIF_MECHANIC, DIALOG_STYLE_TABLIST_HEADERS, !""cLRED"Управление СТО:", String1024, !"Выбрать", !"Закрыть"); 
	}
	return true;

}

stock change_tarif_mech(playerid, type)
{
	new 
		id_mechanic;


	if(pData[playerid][pMechOwnerID] != -1)
	{
		id_mechanic = pData[playerid][pMechOwnerID];		
	}
	else if(pData[playerid][pMechOwnerLowID] != -1)
	{
		id_mechanic = pData[playerid][pMechOwnerLowID];
	}

	switch(type)
	{
		case 1:
		{

			format(String144, sizeof(String144), "\
			"cWH"Укажите новую стоимость заправки 1 литра топлива\n\n\
			Текущая стоимость: "cGR"%d"cWH" рублей", mechanic[id_mechanic][mechanic_price_fuel]);

			SPD(playerid, DIALOG_CHG_TARIF_MECH_1, DIALOG_STYLE_INPUT, !""cWH"Изменение стоимости", String144, !"Далее", !"Назад");
		}
		case 2:
		{ 

			format(String144, sizeof(String144), "\
			"cWH"Укажите новую стоимость ремонта\n\n\
			Текущая стоимость: "cGR"%d"cWH" рублей", mechanic[id_mechanic][mechanic_price_remont]);

			SPD(playerid, DIALOG_CHG_TARIF_MECH_2, DIALOG_STYLE_INPUT, !""cWH"Изменение стоимости", String144, !"Далее", !"Назад");			
		}
		case 3:
		{

			format(String144, sizeof(String144), "\
			"cWH"Укажите новую стоимость заправки 1 литра масла\n\n\
			Текущая стоимость: "cGR"%d"cWH" рублей", mechanic[id_mechanic][mechanic_price_oil]);

			SPD(playerid, DIALOG_CHG_TARIF_MECH_3, DIALOG_STYLE_INPUT, !""cWH"Изменение стоимости", String144, !"Далее", !"Назад");				
		}
		case 4:
		{

			format(String144, sizeof(String144), "\
			"cWH"Укажите новую стоимость замены свечей\n\n\
			Текущая стоимость: "cGR"%d"cWH" рублей", mechanic[id_mechanic][mechanic_price_candles]);

			SPD(playerid, DIALOG_CHG_TARIF_MECH_4, DIALOG_STYLE_INPUT, !""cWH"Изменение стоимости", String144, !"Далее", !"Назад");				
		}
		case 5:
		{

			format(String144, sizeof(String144), "\
			"cWH"Укажите новую стоимость замены тормозов\n\n\
			Текущая стоимость: "cGR"%d"cWH" рублей", mechanic[id_mechanic][mechanic_price_brake]);

			SPD(playerid, DIALOG_CHG_TARIF_MECH_5, DIALOG_STYLE_INPUT, !""cWH"Изменение стоимости", String144, !"Далее", !"Назад");				
		}
		case 6:
		{

			format(String144, sizeof(String144), "\
			"cWH"Укажите новую стоимость замены ремней\n\n\
			Текущая стоимость: "cGR"%d"cWH" рублей", mechanic[id_mechanic][mechanic_price_belt]);

			SPD(playerid, DIALOG_CHG_TARIF_MECH_6, DIALOG_STYLE_INPUT, !""cWH"Изменение стоимости", String144, !"Далее", !"Назад");			
		}	
		case 7:
		{

			format(String144, sizeof(String144), "\
			"cWH"Укажите новую стоимость стартера\n\n\
			Текущая стоимость: "cGR"%d"cWH" рублей", mechanic[id_mechanic][mechanic_price_starter]);

			SPD(playerid, DIALOG_CHG_TARIF_MECH_7, DIALOG_STYLE_INPUT, !""cWH"Изменение стоимости", String144, !"Далее", !"Назад");				
		}
		case 8:
		{

			format(String144, sizeof(String144), "\
			"cWH"Укажите новую стоимость генератора\n\n\
			Текущая стоимость: "cGR"%d"cWH" рублей", mechanic[id_mechanic][mechanic_price_generator]);

			SPD(playerid, DIALOG_CHG_TARIF_MECH_8, DIALOG_STYLE_INPUT, !""cWH"Изменение стоимости", String144, !"Далее", !"Назад");				
		}
		case 9:
		{

			format(String144, sizeof(String144), "\
			"cWH"Укажите новую стоимость форсунок\n\n\
			Текущая стоимость: "cGR"%d"cWH" рублей", mechanic[id_mechanic][mechanic_price_forsunki]);

			SPD(playerid, DIALOG_CHG_TARIF_MECH_9, DIALOG_STYLE_INPUT, !""cWH"Изменение стоимости", String144, !"Далее", !"Назад");				
		}
		case 10:
		{

			format(String144, sizeof(String144), "\
			"cWH"Укажите новую стоимость насоса\n\n\
			Текущая стоимость: "cGR"%d"cWH" рублей", mechanic[id_mechanic][mechanic_price_nasos]);

			return SPD(playerid, DIALOG_CHG_TARIF_MECH_10, DIALOG_STYLE_INPUT, !""cWH"Изменение стоимости", String144, !"Далее", !"Назад");				
		}			
	}


	return true;
}

stock change_bank_mechanic(playerid)
{
	new 
		id_mechanic;

	if(pData[playerid][pMechOwnerID] == -1)
		return SendErr(playerid, "Вы не владеете СТО!");


	id_mechanic = pData[playerid][pMechOwnerID];		

	if(id_mechanic == MECHANIC_BASE_STATION_1)
	{
	    format(String320, sizeof(String320), "\
	        "cGREY"Тип\t"cGREY"Действие\n\
	        "cORANGE"1. "cWH"Снять деньги с кассы\t"cGR"Снять\n\
	        "cORANGE"2. "cWH"Положить деньги в кассу\t"cGR"Пополнить");
	    SPD(playerid, DIALOG_CHANGE_MECHANIC_BANK, DIALOG_STYLE_TABLIST_HEADERS, !""cORANGE"Управление СТО:", String320, !"Выбрать", !"Закрыть"); 
	}
	else if(id_mechanic == MECHANIC_BASE_STATION_2)
	{
	    format(String320, sizeof(String320), "\
	        "cGREY"Тип\t"cGREY"Действие\n\
	        "cBLUE"1. "cWH"Снять деньги с кассы\t"cGR"Снять\n\
	        "cBLUE"2. "cWH"Положить деньги в кассу\t"cGR"Пополнить");
	    SPD(playerid, DIALOG_CHANGE_MECHANIC_BANK, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление СТО:", String320, !"Выбрать", !"Закрыть"); 
	}
	else if(id_mechanic == MECHANIC_BASE_STATION_3)
	{
	    format(String320, sizeof(String320), "\
	        "cGREY"Тип\t"cGREY"Действие\n\
	        "cLRED"1. "cWH"Снять деньги с кассы\t"cGR"Снять\n\
	        "cLRED"2. "cWH"Положить деньги в кассу\t"cGR"Пополнить");
	    SPD(playerid, DIALOG_CHANGE_MECHANIC_BANK, DIALOG_STYLE_TABLIST_HEADERS, !""cLRED"Управление СТО:", String320, !"Выбрать", !"Закрыть"); 
	}

	return true;
}

stock mech_bank_operation(playerid, type)
{
	new 
		id_mechanic;


	if(pData[playerid][pMechOwnerID] != -1)
	{
		id_mechanic = pData[playerid][pMechOwnerID];		
	}
	else if(pData[playerid][pMechOwnerLowID] != -1)
	{
		id_mechanic = pData[playerid][pMechOwnerLowID];
	}


	switch(type)
	{
		case 1:
		{
			if(id_mechanic == MECHANIC_BASE_STATION_1)
			{
				new 
					fmt_str[130];

				format(fmt_str, 130, "\
				"cWH"Сколько денежных средств Вы хотите снять?\n\n\
				В банке СТО находится "cGR"%d"cWH" рублей", mechanic[id_mechanic][mechanic_base_bank]);

				SPD(playerid, DIALOG_MECHANIC_INPUT_MONEY, DIALOG_STYLE_INPUT, !""cORANGE"Снятие денег", fmt_str, !"Далее", !"Назад");
			}
			else if(id_mechanic == MECHANIC_BASE_STATION_2)
			{
				new 
					fmt_str[130];

				format(fmt_str, 130, "\
				"cWH"Сколько денежных средств Вы хотите снять?\n\n\
				В банке СТО находится "cGR"%d"cWH" рублей", mechanic[id_mechanic][mechanic_base_bank]);

				SPD(playerid, DIALOG_MECHANIC_INPUT_MONEY, DIALOG_STYLE_INPUT, !""cBLUE"Снятие денег", fmt_str, !"Далее", !"Назад");
			}
			else if(id_mechanic == MECHANIC_BASE_STATION_3)
			{
				new 
					fmt_str[130];

				format(fmt_str, 130, "\
				"cWH"Сколько денежных средств Вы хотите снять?\n\n\
				В банке СТО находится "cGR"%d"cWH" рублей", mechanic[id_mechanic][mechanic_base_bank]);

				SPD(playerid, DIALOG_MECHANIC_INPUT_MONEY, DIALOG_STYLE_INPUT, !""cLRED"Снятие денег", fmt_str, !"Далее", !"Назад");
			}		
		}

		case 2:
		{
			if(id_mechanic == MECHANIC_BASE_STATION_1)
			{
				new 
					fmt_str[130];

				format(fmt_str, 130, "\
				"cWH"Сколько денежных средств Вы хотите положить на счёт?\n\n\
				В банке СТО находится "cGR"%d"cWH" рублей", mechanic[id_mechanic][mechanic_base_bank]);

				SPD(playerid, DIALOG_MECHANIC_PUT_MONEY, DIALOG_STYLE_INPUT, !""cORANGE"Пополнение кассы", fmt_str, !"Далее", !"Назад");
			}
			else if(id_mechanic == MECHANIC_BASE_STATION_2)
			{
				new 
					fmt_str[130];

				format(fmt_str, 130, "\
				"cWH"Сколько денежных средств Вы хотите положить на счёт?\n\n\
				В банке СТО находится "cGR"%d"cWH" рублей", mechanic[id_mechanic][mechanic_base_bank]);

				SPD(playerid, DIALOG_MECHANIC_PUT_MONEY, DIALOG_STYLE_INPUT, !""cBLUE"Пополнение кассы", fmt_str, !"Далее", !"Назад");
			}	
			else if(id_mechanic == MECHANIC_BASE_STATION_3)
			{
				new 
					fmt_str[130];

				format(fmt_str, 130, "\
				"cWH"Сколько денежных средств Вы хотите положить на счёт?\n\n\
				В банке СТО находится "cGR"%d"cWH" рублей", mechanic[id_mechanic][mechanic_base_bank]);

				SPD(playerid, DIALOG_MECHANIC_PUT_MONEY, DIALOG_STYLE_INPUT, !""cLRED"Пополнение кассы", fmt_str, !"Далее", !"Назад");
			}		
		}		
	}

	return true;
}


stock change_personal_mechanic(playerid, page = 0)
{

	new 
		id_mechanic;

	if(page < 0)
	{
		page = 0;
	}

	if(pData[playerid][pMechOwnerID] != -1)
	{
		id_mechanic = pData[playerid][pMechOwnerID];		
	}
	else if(pData[playerid][pMechOwnerLowID] != -1)
	{
		id_mechanic = pData[playerid][pMechOwnerLowID];
	}


    format(String4096, sizeof(String4096), ""cGREY"№. Имя\t"cGREY"Должность\t"cGREY"Общий доход (За сутки)\t"cGREY"Последний заход\n");

    SetPVarIntNew(playerid, "check_page_panel_mech", page);

	format(String1024, sizeof(String1024), "SELECT * FROM `mechanic_personal` WHERE `id` = %d ORDER BY `user_data_last_join` LIMIT %d,20", id_mechanic, page*20);
	new Result:rnew = sql_queryEx(zConn, String1024, QUERY_CACHED);

	new all_mechanic_stations = sql_num_rows(rnew);

    new 
    	mechanic_id_all = page*20;


 	for(new i; i < all_mechanic_stations; i++)
	{


		new 
			mechanic_personal_user_id,
			mechanic_personal_user_rank,
			mechanic_per_user_money_day,
			mechanic_per_user_money_all,
			mechanic_personal_user_name[32],
			mechanic_personal_user_join[20],
			mechanic_personal_user_last[20];

		mechanic_personal_user_id = sql_get_field_assoc_int_ex(rnew, i, "user_id");
		mechanic_personal_user_rank = sql_get_field_assoc_int_ex(rnew, i, "user_rank");
		mechanic_per_user_money_day = sql_get_field_assoc_int_ex(rnew, i, "user_money_day");
		mechanic_per_user_money_all = sql_get_field_assoc_int_ex(rnew, i, "user_money_all");

		dialog_listitem_values[playerid][i] = mechanic_personal_user_id;

		GetPlayerNameByID(mechanic_personal_user_id,mechanic_personal_user_name);

		sql_get_field_assoc_ex(rnew, i, "user_data_join", mechanic_personal_user_join, 20);
		sql_get_field_assoc_ex(rnew, i, "user_data_last_join", mechanic_personal_user_last, 20);

	    new onnn = 0;


		foreach(Player, x)
		{

			if(pData[x][pMysqlID] == mechanic_personal_user_id && pData[x][pMech] == pData[playerid][pMech]) onnn = 1;
		}


		if(onnn > 0)
		{
			if(mechanic_id_all < 9 ) 
			{
		    	format(String4096, sizeof(String4096), "%s%s%d."cWH"  %s \t%s\t%s %d"cWH" %s (%d)"cWH" рублей\t%s\n",String4096, \
		    	get_mechanic_color(id_mechanic), mechanic_id_all+1, mechanic_personal_user_name, \
		    	mechanic_rank_name[mechanic_personal_user_rank], \
		    	get_money_stats_color(mechanic_per_user_money_day), mechanic_per_user_money_day, get_money_stats_color(mechanic_per_user_money_all), mechanic_per_user_money_all,"{00CC44}Online{FFFFFF}");
		    }
		    else			    
		    {
		    	format(String4096, sizeof(String4096), "%s%s%d."cWH"  %s \t%s\t%s %d"cWH" %s (%d)"cWH" рублей\t%s\n",String4096, \
		    	get_mechanic_color(id_mechanic), mechanic_id_all+1, mechanic_personal_user_name, \
		    	mechanic_rank_name[mechanic_personal_user_rank], \
		    	get_money_stats_color(mechanic_per_user_money_day), mechanic_per_user_money_day, get_money_stats_color(mechanic_per_user_money_all), mechanic_per_user_money_all,"{00CC44}Online{FFFFFF}");

			}
		}
		else 
		{
			if(mechanic_id_all < 9 ) 
			{
		    	format(String4096, sizeof(String4096), "%s%s%d."cWH"  %s \t%s\t%s %d"cWH" %s (%d)"cWH" рублей\t%s\n",String4096, \
		    	get_mechanic_color(id_mechanic), mechanic_id_all+1, mechanic_personal_user_name, \
		    	mechanic_rank_name[mechanic_personal_user_rank], \
		    	get_money_stats_color(mechanic_per_user_money_day), mechanic_per_user_money_day, get_money_stats_color(mechanic_per_user_money_all), mechanic_per_user_money_all, mechanic_personal_user_last);
		    }
		    else			    
		    {
		    	format(String4096, sizeof(String4096), "%s%s%d."cWH"  %s \t%s\t%s %d"cWH" %s (%d)"cWH" рублей\t%s\n",String4096, \
		    	get_mechanic_color(id_mechanic), mechanic_id_all+1, mechanic_personal_user_name, \
		    	mechanic_rank_name[mechanic_personal_user_rank], \
		    	get_money_stats_color(mechanic_per_user_money_day), mechanic_per_user_money_day, get_money_stats_color(mechanic_per_user_money_all), mechanic_per_user_money_all, mechanic_personal_user_last);
			}
		}


		mechanic_id_all++;


	}
	sql_next_row(rnew);

	if(all_mechanic_stations < 20)
	{
		SetPVarIntNew(playerid, "button_back_personal_menu", all_mechanic_stations);
	}

    if(all_mechanic_stations == 20) strcat(String4096, ""cGREY"Далее >>>\n");
    if(page >= 1) strcat(String4096, ""cGREY"<<< Назад");

	if(id_mechanic == MECHANIC_BASE_STATION_1)
	{
		SPD(playerid,DIALOG_MECHANIC_CHANGE_PERS, DIALOG_STYLE_TABLIST_HEADERS ,""cORANGE"Персонал СТО",String4096,"Далее","Закрыть");
	}
	else if(id_mechanic == MECHANIC_BASE_STATION_2)
	{
		SPD(playerid,DIALOG_MECHANIC_CHANGE_PERS, DIALOG_STYLE_TABLIST_HEADERS ,""cBLUE"Персонал СТО",String4096,"Далее","Закрыть");
	}
	else if(id_mechanic == MECHANIC_BASE_STATION_3)
	{
		SPD(playerid,DIALOG_MECHANIC_CHANGE_PERS, DIALOG_STYLE_TABLIST_HEADERS ,""cLRED"Персонал СТО",String4096,"Далее","Закрыть");
	}
	return true;
}


stock change_rank_personal_mech(playerid, user_sql_id)
{
	SetPVarIntNew(playerid, "uninvite_mech_id", user_sql_id);

	static
		fmt_str[500];

	new 
		id_mechanic;


	if(pData[playerid][pMechOwnerID] != -1)
	{
		id_mechanic = pData[playerid][pMechOwnerID];		
	}
	else if(pData[playerid][pMechOwnerLowID] != -1)
	{
		id_mechanic = pData[playerid][pMechOwnerLowID];
	}

	format(fmt_str, sizeof(fmt_str), "SELECT * FROM mechanic_personal WHERE user_id = '%d' LIMIT 1", user_sql_id);
	new Result:mechanic_find = sql_queryEx(zConn, fmt_str, QUERY_CACHED);

	if(sql_num_rows(mechanic_find)) 
	{
		new 
			mehcnaic_change_name[32],
			mechanic_rank;


  		mechanic_rank = sql_get_field_assoc_int(mechanic_find, "user_rank");

		GetPlayerNameByID(user_sql_id,mehcnaic_change_name);

		if(pData[playerid][pMechOwnerID] == id_mechanic && pData[playerid][pMechOwnerLowID] == -1)
		{

			switch(id_mechanic)
			{
				case MECHANIC_BASE_STATION_1:
				{
				    format(fmt_str, 450, "\
			        "cGREY"Сотрудник\t"cGREY"Управление\n\
			        "cORANGE"- "cWH"%s\t"cGR"%s\n\
			        "cORANGE"\t\n\
			        "cORANGE"- "cWH"Механик\t"cGR"Понизить\n\
			        "cORANGE"- "cWH"Управляющий\t"cGR"Повысить\n\
			        "cORANGE"- "cWH"Уволить сотрудника\t"cGR"Уволить", 
			        mehcnaic_change_name, mechanic_rank_name[mechanic_rank]);
				    SPD(playerid, DIALOG_MECHANIC_CHANGE_PERS_2, DIALOG_STYLE_TABLIST_HEADERS, !""cORANGE"Персонал СТО:", fmt_str, !"Выбрать", !"Закрыть"); 
				}
				case MECHANIC_BASE_STATION_2:
				{
				    format(fmt_str, 450, "\
			        "cGREY"Сотрудник\t"cGREY"Управление\n\
			        "cBLUE"- "cWH"%s\t"cGR"%s\n\
			        "cBLUE"\t\n\
			        "cBLUE"- "cWH"Механик\t"cGR"Понизить\n\
			        "cBLUE"- "cWH"Управляющий\t"cGR"Повысить\n\
			        "cBLUE"- "cWH"Уволить сотрудника\t"cGR"Уволить", 
			        mehcnaic_change_name, mechanic_rank_name[mechanic_rank]);
				    SPD(playerid, DIALOG_MECHANIC_CHANGE_PERS_2, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Персонал СТО:", fmt_str, !"Выбрать", !"Закрыть"); 					
				}
				case MECHANIC_BASE_STATION_3:
				{
				    format(fmt_str, 450, "\
			        "cGREY"Сотрудник\t"cGREY"Управление\n\
			        "cLRED"- "cWH"%s\t"cGR"%s\n\
			        "cLRED"\t\n\
			        "cLRED"- "cWH"Механик\t"cGR"Понизить\n\
			        "cLRED"- "cWH"Управляющий\t"cGR"Повысить\n\
			        "cLRED"- "cWH"Уволить сотрудника\t"cGR"Уволить", 
			        mehcnaic_change_name, mechanic_rank_name[mechanic_rank]);
				    SPD(playerid, DIALOG_MECHANIC_CHANGE_PERS_2, DIALOG_STYLE_TABLIST_HEADERS, !""cLRED"Персонал СТО:", fmt_str, !"Выбрать", !"Закрыть"); 					
				}
			}
		}
		else if(pData[playerid][pMechOwnerLowID] == id_mechanic && pData[playerid][pMechOwnerID] == -1)
		{
			switch(id_mechanic)
			{
				case MECHANIC_BASE_STATION_1:
				{
				    format(fmt_str, 450, "\
			        "cGREY"Сотрудник\t"cGREY"Управление\n\
			        "cORANGE"- "cWH"%s\t"cGR"%s\n\
			        "cORANGE"\t\n\
			        "cORANGE"- "cWH"Механик\t"cGR"Понизить\n\
			        "cORANGE"- "cWH"Управляющий\t"cGR"Повысить\n\
			        "cORANGE"- "cWH"Уволить сотрудника\t"cGR"Уволить", 
			        mehcnaic_change_name, mechanic_rank_name[mechanic_rank]);
				    SPD(playerid, DIALOG_MECHANIC_CHANGE_PERS_2, DIALOG_STYLE_TABLIST_HEADERS, !""cORANGE"Персонал СТО:", fmt_str, !"Выбрать", !"Закрыть"); 
				}
				case MECHANIC_BASE_STATION_2:
				{
				    format(fmt_str, 450, "\
			        "cGREY"Сотрудник\t"cGREY"Управление\n\
			        "cBLUE"- "cWH"%s\t"cGR"%s\n\
			        "cBLUE"\t\n\
			        "cBLUE"- "cWH"Механик\t"cGR"Понизить\n\
			        "cBLUE"- "cWH"Управляющий\t"cGR"Повысить\n\
			        "cBLUE"- "cWH"Уволить сотрудника\t"cGR"Уволить", 
			        mehcnaic_change_name, mechanic_rank_name[mechanic_rank]);
				    SPD(playerid, DIALOG_MECHANIC_CHANGE_PERS_2, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Персонал СТО:", fmt_str, !"Выбрать", !"Закрыть"); 					
				}
				case MECHANIC_BASE_STATION_3:
				{
				    format(fmt_str, 450, "\
			        "cGREY"Сотрудник\t"cGREY"Управление\n\
			        "cLRED"- "cWH"%s\t"cGR"%s\n\
			        "cLRED"\t\n\
			        "cLRED"- "cWH"Механик\t"cGR"Понизить\n\
			        "cLRED"- "cWH"Управляющий\t"cGR"Повысить\n\
			        "cLRED"- "cWH"Уволить сотрудника\t"cGR"Уволить", 
			        mehcnaic_change_name, mechanic_rank_name[mechanic_rank]);
				    SPD(playerid, DIALOG_MECHANIC_CHANGE_PERS_2, DIALOG_STYLE_TABLIST_HEADERS, !""cLRED"Персонал СТО:", fmt_str, !"Выбрать", !"Закрыть"); 					
				}
			}
		}

	}
	return true;
}


stock give_rank_mech_mech(playerid, user_sql_id)
{
	if(pData[playerid][pMechOwnerID] == -1)
		return change_rank_personal_mech(playerid, user_sql_id);

	if(pData[playerid][pMysqlID] == user_sql_id)
	{	
		change_rank_personal_mech(playerid, user_sql_id);
		return SendErr(playerid, "Вы не можете изменить себе ранг!");
	}

	static
		fmt_str[500];

	format(fmt_str, sizeof(fmt_str), "SELECT * FROM mechanic_personal WHERE user_id = '%d' LIMIT 1", user_sql_id);
	new Result:mechanic_find = sql_queryEx(zConn, fmt_str, QUERY_CACHED);

	if(sql_num_rows(mechanic_find)) 
	{
		new 
			mehcnaic_change_name[32],
			mechanic_rank;


  		mechanic_rank = sql_get_field_assoc_int(mechanic_find, "user_rank");

		GetPlayerNameByID(user_sql_id,mehcnaic_change_name);

		new 
			player_id = GetPlayerID(mehcnaic_change_name);

		if(IsPlayerConnected(player_id))
		{
			if(mechanic_rank == 1)
			{
				SFCM(playerid, 0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Механик %s и так уже имеет ранг механика!", mehcnaic_change_name);
				return change_rank_personal_mech(playerid, user_sql_id);
			}
			else
			{
				format(String256,sizeof(String256),"UPDATE `mechanic_personal` SET `user_rank` = 1 WHERE `user_id` = '%d'" , pData[player_id][pMysqlID]);
				sql_queryEx(zConn, String256, QUERY_THREADED);	

				pData[playerid][pMechOwnerLowID] = -1;

				UpdatePlayerData(player_id,"pMechOwnerLowID", pData[player_id][pMechOwnerLowID]);


				SFCM(player_id, 0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Владелец %s [%d] понизил Вас до должности 'Механика'", pData[playerid][pNickname], playerid);	

				new 
					id_mechanic = pData[playerid][pMechOwnerID];


				format(fmt_str, sizeof(fmt_str), "[M] Сотрудник %s был понижен до должности 'Механика' владельцем %s", mehcnaic_change_name, pData[playerid][pNickname]);
				send_mechanic_job(id_mechanic, COLOR_GREY, fmt_str);

				return change_rank_personal_mech(playerid, user_sql_id);	
			}
		}
		else
		{
			if(mechanic_rank == 1)
			{
				SFCM(playerid, 0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Механик %s и так уже имеет ранг механика!", mehcnaic_change_name);
				return change_rank_personal_mech(playerid, user_sql_id);
			}
			else
			{
				format(String256,sizeof(String256),"UPDATE `mechanic_personal` SET `user_rank` = 1 WHERE `user_id` = '%d'" , user_sql_id);
				sql_queryEx(zConn, String256, QUERY_THREADED);		

				format(String256,sizeof(String256),"UPDATE `accounts` SET `pMechOwnerLowID` = '-1' WHERE `id` = '%i'", user_sql_id);
				sql_queryEx(zConn, String256, QUERY_THREADED);

				SFCM(playerid, 0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Вы успешно понизили %s до должности механика оффлайн!", mehcnaic_change_name);

				new 
					id_mechanic = pData[playerid][pMechOwnerID];


				format(fmt_str, sizeof(fmt_str), "[M] Сотрудник %s был понижен до должности 'Механика' владельцем %s", mehcnaic_change_name, pData[playerid][pNickname]);
				send_mechanic_job(id_mechanic, COLOR_GREY, fmt_str);

				return change_rank_personal_mech(playerid, user_sql_id);	
			}			
		}


	}	

	return true;
}
stock give_rank_manager_mech(playerid, user_sql_id)
{
	if(pData[playerid][pMechOwnerID] == -1)
		return change_rank_personal_mech(playerid, user_sql_id);

	if(pData[playerid][pMysqlID] == user_sql_id)
	{	
		change_rank_personal_mech(playerid, user_sql_id);
		return SendErr(playerid, "Вы не можете изменить себе ранг!");
	}

	static
		fmt_str[500];

	format(fmt_str, sizeof(fmt_str), "SELECT * FROM mechanic_personal WHERE user_id = '%d' LIMIT 1", user_sql_id);
	new Result:mechanic_find = sql_queryEx(zConn, fmt_str, QUERY_CACHED);

	if(sql_num_rows(mechanic_find)) 
	{
		new 
			mehcnaic_change_name[32],
			mechanic_rank;


  		mechanic_rank = sql_get_field_assoc_int(mechanic_find, "user_rank");

		GetPlayerNameByID(user_sql_id,mehcnaic_change_name);

		new 
			player_id = GetPlayerID(mehcnaic_change_name);

		if(IsPlayerConnected(player_id))
		{

			if(mechanic_rank == 2)
			{
				SFCM(playerid, 0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Механик %s и так уже является управляющим!", mehcnaic_change_name);
				return change_rank_personal_mech(playerid, user_sql_id);
			}
			else
			{
				format(String256,sizeof(String256),"UPDATE `mechanic_personal` SET `user_rank` = 2 WHERE `user_id` = '%d'" , user_sql_id);
				sql_queryEx(zConn, String256, QUERY_THREADED);		


				format(String256,sizeof(String256),"UPDATE `accounts` SET `pMechOwnerLowID` = '%d' WHERE `id` = '%i'", pData[playerid][pMechOwnerID], user_sql_id);
				sql_queryEx(zConn, String256, QUERY_THREADED);

				pData[player_id][pMechOwnerLowID] = pData[playerid][pMechOwnerID];

				SFCM(player_id, 0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Владелец %s [%d] повысил Вас до должности Управляющего СТО!", pData[playerid][pNickname], playerid);

				new 
					id_mechanic = pData[playerid][pMechOwnerID];


				format(fmt_str, sizeof(fmt_str), "[M] Сотрудник %s был повышен до должности 'Управляющего' владельцем %s", mehcnaic_change_name, pData[playerid][pNickname]);
				send_mechanic_job(id_mechanic, COLOR_GREY, fmt_str);

				return change_rank_personal_mech(playerid, user_sql_id);	
			}
		}
		else
		{
			if(mechanic_rank == 2)
			{
				SFCM(playerid, 0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Механик %s и так уже является управляющим!", mehcnaic_change_name);
				return change_rank_personal_mech(playerid, user_sql_id);
			}
			else
			{
				format(String256,sizeof(String256),"UPDATE `mechanic_personal` SET `user_rank` = 2 WHERE `user_id` = '%d'" , user_sql_id);
				sql_queryEx(zConn, String256, QUERY_THREADED);		


				format(String256,sizeof(String256),"UPDATE `accounts` SET `pMechOwnerLowID` = '%d' WHERE `id` = '%i'", user_sql_id, pData[playerid][pMechOwnerID]);
				sql_queryEx(zConn, String256, QUERY_THREADED);

				SFCM(playerid, 0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Вы успешно повысили %s до должности управляющего оффлайн!", mehcnaic_change_name);

				new 
					id_mechanic = pData[playerid][pMechOwnerID];


				format(fmt_str, sizeof(fmt_str), "[M] Сотрудник %s был повышен до должности 'Управляющего' владельцем %s", mehcnaic_change_name, pData[playerid][pNickname]);
				send_mechanic_job(id_mechanic, COLOR_GREY, fmt_str);

				return change_rank_personal_mech(playerid, user_sql_id);	
			}			
		}


	}	
	return true;
}
stock uninvite_panel_pers_mech(playerid, user_sql_id)
{

	printf("UNINVITE ID - %d", user_sql_id);

	new 
		id_mechanic;


	if(pData[playerid][pMechOwnerID] != -1)
	{
		id_mechanic = pData[playerid][pMechOwnerID];		
	}
	else if(pData[playerid][pMechOwnerLowID] != -1)
	{
		id_mechanic = pData[playerid][pMechOwnerLowID];
	}

	new 
		mehcnaic_change_name[MAX_PLAYER_NAME];

	new 
		mechanic_rank;

	if(pData[playerid][pMysqlID] == user_sql_id)
	{	
		change_rank_personal_mech(playerid, user_sql_id);
		return SendErr(playerid, "Вы не можете уволить себя!");
	}

	if(pData[playerid][pMechOwnerLowID])
	{
		mechanic_rank = 2;
	}
	else if(pData[playerid][pMechOwnerID])
	{
		mechanic_rank = 3;
	}	

	GetPlayerNameByID(user_sql_id,mehcnaic_change_name);

	new 
		player_id = GetPlayerID(mehcnaic_change_name);

	if(IsPlayerConnected(player_id))
	{

		pData[player_id][pMech] = -1;
		pData[player_id][pMechOwnerLowID] = -1;
		pData[player_id][pJob] = 0;
		pData[player_id][pMechRank] = 0;

		UpdatePlayerData(player_id,"pMechRank", pData[player_id][pMechRank]);	
		UpdatePlayerData(player_id,"mech", pData[player_id][pMech]);
		UpdatePlayerData(player_id,"pMechOwnerLowID", pData[player_id][pMechOwnerLowID]);
		UpdatePlayerData(player_id,"job", pData[player_id][pJob]);

		format(String256,sizeof(String256),"DELETE FROM `mechanic_personal` WHERE `user_id` = '%d'", user_sql_id);
		sql_queryEx(zConn, String256, QUERY_THREADED);

		format(String256,sizeof(String256),"UPDATE `accounts` SET `mech` = '-1', `pMechOwnerLowID` = '-1', `job` = '0' WHERE `id` = '%i'", user_sql_id);
		sql_queryEx(zConn, String256, QUERY_THREADED);

		UpdatePlayerData(playerid, "job", pData[player_id][pJob]);

		SFCM(player_id, 0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"%s %s [%d] уволил Вас со Станции Технического Обслуживания №%d", mechanic_rank_name[mechanic_rank], pData[playerid][pNickname], playerid, id_mechanic);

		new 
			fmt_str[144];

		format(fmt_str, sizeof(fmt_str), "[M] Сотрудник %s был уволен с СТО %s %s", pData[player_id][pNickname], mechanic_rank_name[mechanic_rank], pData[playerid][pNickname]);
		send_mechanic_job(id_mechanic, COLOR_GREY, fmt_str);

	}
	else
	{


		format(String256,sizeof(String256),"DELETE FROM `mechanic_personal` WHERE `user_id` = '%d'", user_sql_id);
		sql_queryEx(zConn, String256, QUERY_THREADED);

		format(String256,sizeof(String256),"UPDATE `accounts` SET `mech` = '-1', `pMechOwnerLowID` = '-1', `job` = '0' WHERE `id` = '%i'", user_sql_id);
		sql_queryEx(zConn, String256, QUERY_THREADED);

		SFCM(playerid, 0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"Вы успешно уволили %s со Станции Технического Обслуживания", mehcnaic_change_name);

		new 
			fmt_str[144];

		format(fmt_str, sizeof(fmt_str), "[M] Сотрудник %s был уволен с СТО %s %s", mehcnaic_change_name, mechanic_rank_name[mechanic_rank], pData[playerid][pNickname]);
		send_mechanic_job(id_mechanic, COLOR_GREY, fmt_str);

	}

	DeletePVarNew(playerid, "uninvite_mech_id");

	change_personal_mechanic(playerid);

	return true;
}

stock uninvite_mechanic_personal(playerid)
{

	if(pData[playerid][pMechOwnerID] != -1)
		return SendErr(playerid, "Вы не можете уволиться из СТО!");

	if(pData[playerid][pMechOwnerLowID] != -1)
		return SendErr(playerid, "Вы не можете уволиться из СТО!");



	new 
		id_mechanic = pData[playerid][pMech],
		mechanic_rank = pData[playerid][pMechRank];

	format(String144, sizeof(String144), "[M] %s %s самостоятельно уволился с СТО", pData[playerid][pNickname], mechanic_rank_name[mechanic_rank]);
	send_mechanic_job(id_mechanic, COLOR_GREY, String144);

	pData[playerid][pMech] = -1;
	pData[playerid][pMechOwnerLowID] = -1;
	pData[playerid][pJob] = 0;
	pData[playerid][pMechRank] = 0;

	UpdatePlayerData(playerid,"pMechRank", pData[playerid][pMechRank]);	
	UpdatePlayerData(playerid,"mech", pData[playerid][pMech]);
	UpdatePlayerData(playerid,"pMechOwnerLowID", pData[playerid][pMechOwnerLowID]);
	UpdatePlayerData(playerid,"job", pData[playerid][pJob]);

	format(String256,sizeof(String256),"DELETE FROM `mechanic_personal` WHERE `user_id` = '%d'", pData[playerid][pMysqlID]);
	sql_queryEx(zConn, String256, QUERY_THREADED);

	format(String256,sizeof(String256),"UPDATE `accounts` SET `mech` = '-1', `pMechOwnerLowID` = '-1' WHERE `id` = '%i'", pData[playerid][pMysqlID]);
	sql_queryEx(zConn, String256, QUERY_THREADED);


	return true;
}

stock uninvite_command_pers_mech(playerid, player_id_to)
{

	new 
		id_mechanic;


	if(pData[playerid][pMechOwnerID] != -1)
	{
		id_mechanic = pData[playerid][pMechOwnerID];		
	}
	else if(pData[playerid][pMechOwnerLowID] != -1)
	{
		id_mechanic = pData[playerid][pMechOwnerLowID];
	}


	new 
		mechanic_rank;

	if(playerid == player_id_to)
	{	
		return SendErr(playerid, "Вы не можете уволить себя!");
	}

	if(pData[playerid][pMechOwnerLowID])
	{
		mechanic_rank = 2;
	}
	else if(pData[playerid][pMechOwnerID])
	{
		mechanic_rank = 3;
	}	


	if(IsPlayerConnected(player_id_to))
	{
		pData[player_id_to][pMech] = -1;
		pData[player_id_to][pMechOwnerLowID] = -1;
		pData[player_id_to][pJob] = 0;
		pData[player_id_to][pMechRank] = 0;

		UpdatePlayerData(player_id_to,"mech", pData[player_id_to][pMech]);
		UpdatePlayerData(player_id_to,"pMechOwnerLowID", pData[player_id_to][pMechOwnerLowID]);
		UpdatePlayerData(player_id_to, "job", pData[player_id_to][pJob]);
		UpdatePlayerData(player_id_to,"pMechRank", pData[player_id_to][pMechRank]);	

		format(String256,sizeof(String256),"DELETE FROM `mechanic_personal` WHERE `user_id` = '%d'", pData[player_id_to][pMysqlID]);
		sql_queryEx(zConn, String256, QUERY_THREADED);

		format(String256,sizeof(String256),"UPDATE `accounts` SET `mech` = '-1', `pMechOwnerLowID` = '-1' WHERE `id` = '%i'", pData[player_id_to][pMysqlID]);
		sql_queryEx(zConn, String256, QUERY_THREADED);


		SFCM(player_id_to, 0xFFFFFFFF, "• {FFC800}[Подсказка] "cWH"%s %s [%d] уволил Вас со Станции Технического Обслуживания №%d", mechanic_rank_name[mechanic_rank], pData[playerid][pNickname], playerid, id_mechanic+1);


		format(String144, sizeof(String144), "[M] Сотрудник %s был уволен с СТО %s %s", pData[player_id_to][pNickname], mechanic_rank_name[mechanic_rank], pData[playerid][pNickname]);
		send_mechanic_job(id_mechanic, COLOR_GREY, String144);

	}

	return true;
}

stock change_statistic_mechanic(playerid)
{
	new 
		id_mechanic;


	if(pData[playerid][pMechOwnerID] != -1)
	{
		id_mechanic = pData[playerid][pMechOwnerID];		
	}
	else if(pData[playerid][pMechOwnerLowID] != -1)
	{
		id_mechanic = pData[playerid][pMechOwnerLowID];
	}

	format(String512, sizeof(String512), "SELECT * FROM mechanic_stats WHERE mechanic_id = '%d' LIMIT 1", id_mechanic);
	new Result:mechanic_stats = sql_queryEx(zConn, String512, QUERY_CACHED);

	if(sql_num_rows(mechanic_stats)) 
	{
		new 
			ye, m, d;

		getdate(ye, m, d);

		new 
			mechanic_stats_day[8],
			mechanic_stats_today,
			mechanic_stats_mounth,
			mechanic_status_all,
			mechanic_stats_prewiow;

  		mechanic_stats_day[1] = sql_get_field_assoc_int(mechanic_stats, "stats_day_1");
  		mechanic_stats_day[2] = sql_get_field_assoc_int(mechanic_stats, "stats_day_2");
  		mechanic_stats_day[3] = sql_get_field_assoc_int(mechanic_stats, "stats_day_3");
  		mechanic_stats_day[4] = sql_get_field_assoc_int(mechanic_stats, "stats_day_4");
  		mechanic_stats_day[5] = sql_get_field_assoc_int(mechanic_stats, "stats_day_5");
  		mechanic_stats_day[6] = sql_get_field_assoc_int(mechanic_stats, "stats_day_6");
  		mechanic_stats_day[7] = sql_get_field_assoc_int(mechanic_stats, "stats_day_7");

  		mechanic_stats_today = sql_get_field_assoc_int(mechanic_stats, "stats_today");
  		mechanic_stats_mounth = sql_get_field_assoc_int(mechanic_stats, "stats_mounth");
  		mechanic_status_all = sql_get_field_assoc_int(mechanic_stats, "stats_all_time");
  		mechanic_stats_prewiow = sql_get_field_assoc_int(mechanic_stats, "stats_mounth_back");

  		new 
  			all_day_seven = mechanic_stats_day[1]+mechanic_stats_day[2]+mechanic_stats_day[3]+mechanic_stats_day[4]+mechanic_stats_day[5]+mechanic_stats_day[6]+mechanic_stats_day[7];

		switch(id_mechanic)
		{
			case MECHANIC_BASE_STATION_1:
			{
			    format(String2048, sizeof(String2048), "\
		        "cGREY"Дата\t"cGREY"Сумма\t"cGREY"Выгода/Убыток\n\
		        "cORANGE"- "cWH"Понедельник\t%s %d рублей\t"cGR"Не изменилась\n\
		        "cORANGE"- "cWH"Вторник\t%s %d рублей\t%s %d рублей\n\
		        "cORANGE"- "cWH"Среда\t%s %d рублей\t%s %d рублей\n\
		        "cORANGE"- "cWH"Четверг\t%s %d рублей\t%s %d рублей\n\
		        "cORANGE"- "cWH"Пятница\t%s %d рублей\t%s %d рублей\n\
		        "cORANGE"- "cWH"Суббота\t%s %d рублей\t%s %d рублей\n\
		        "cORANGE"- "cWH"Воскресенье\t%s %d рублей\t%s %d рублей\n\
		        "cORANGE"\t\n\
		        "cORANGE"- "cWH"За %s\t%s%d рублей\t%s %d рублей\n\
		        "cORANGE"- "cWH"За %s\t"cGR"%d рублей\n\
		        "cORANGE"- "cWH"За неделю\t"cGR"%d рублей\n\
		        "cORANGE"- "cWH"За все время\t"cGR"%d рублей\n\
		        "cORANGE"- "cWH"За текущий день\t"cGR"%d рублей", 

		        get_stats_color(mechanic_stats_day[1], mechanic_stats_day[1]), mechanic_stats_day[1],
		        get_stats_color(mechanic_stats_day[2], mechanic_stats_day[1]), mechanic_stats_day[2], get_stats_phrase(mechanic_stats_day[2], mechanic_stats_day[1]), get_percent_pribil(mechanic_stats_day[2], mechanic_stats_day[1]), 
		        get_stats_color(mechanic_stats_day[3], mechanic_stats_day[2]), mechanic_stats_day[3], get_stats_phrase(mechanic_stats_day[3], mechanic_stats_day[1]), get_percent_pribil(mechanic_stats_day[3], mechanic_stats_day[2]), 
		        get_stats_color(mechanic_stats_day[4], mechanic_stats_day[3]), mechanic_stats_day[4], get_stats_phrase(mechanic_stats_day[4], mechanic_stats_day[1]), get_percent_pribil(mechanic_stats_day[4], mechanic_stats_day[3]), 
		        get_stats_color(mechanic_stats_day[5], mechanic_stats_day[4]), mechanic_stats_day[5], get_stats_phrase(mechanic_stats_day[5], mechanic_stats_day[1]), get_percent_pribil(mechanic_stats_day[5], mechanic_stats_day[4]), 
		        get_stats_color(mechanic_stats_day[6], mechanic_stats_day[5]), mechanic_stats_day[6], get_stats_phrase(mechanic_stats_day[6], mechanic_stats_day[1]), get_percent_pribil(mechanic_stats_day[6], mechanic_stats_day[5]), 
		        get_stats_color(mechanic_stats_day[7], mechanic_stats_day[6]), mechanic_stats_day[7], get_stats_phrase(mechanic_stats_day[7], mechanic_stats_day[1]), get_percent_pribil(mechanic_stats_day[7], mechanic_stats_day[6]), 
		        mounth_mech_stats[m], get_stats_color(mechanic_stats_mounth, mechanic_stats_prewiow), mechanic_stats_mounth, get_stats_phrase(mechanic_stats_mounth, mechanic_stats_prewiow), get_percent_pribil(mechanic_stats_mounth, mechanic_stats_prewiow), 
		        mounth_mech_stats[m-1], mechanic_stats_prewiow,
		        all_day_seven,
		        mechanic_status_all,
		        mechanic_stats_today);
			    SPD(playerid, DIALOG_PERSONAL_CLOSE, DIALOG_STYLE_TABLIST_HEADERS, !""cORANGE"Статистика СТО:", String2048, !"Закрыть", ""); 
			}
			case MECHANIC_BASE_STATION_2:
			{
			    format(String2048, sizeof(String2048), "\
		        "cGREY"Дата\t"cGREY"Сумма\t"cGREY"Выгода/Убыток\n\
		        "cBLUE"- "cWH"Понедельник\t%s %d рублей\t"cGR"Не изменилась\n\
		        "cBLUE"- "cWH"Вторник\t%s %d рублей\t%s %d рублей\n\
		        "cBLUE"- "cWH"Среда\t%s %d рублей\t%s %d рублей\n\
		        "cBLUE"- "cWH"Четверг\t%s %d рублей\t%s %d рублей\n\
		        "cBLUE"- "cWH"Пятница\t%s %d рублей\t%s %d рублей\n\
		        "cBLUE"- "cWH"Суббота\t%s %d рублей\t%s %d рублей\n\
		        "cBLUE"- "cWH"Воскресенье\t%s %d рублей\t%s %d рублей\n\
		        "cBLUE"\t\n\
		        "cBLUE"- "cWH"За %s\t%s%d рублей\t%s %d рублей\n\
		        "cBLUE"- "cWH"За %s\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"За неделю\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"За все время\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"За текущий день\t"cGR"%d рублей", 

		        get_stats_color(mechanic_stats_day[1], mechanic_stats_day[1]), mechanic_stats_day[1],
		        get_stats_color(mechanic_stats_day[2], mechanic_stats_day[1]), mechanic_stats_day[2], get_stats_phrase(mechanic_stats_day[2], mechanic_stats_day[1]), get_percent_pribil(mechanic_stats_day[2], mechanic_stats_day[1]), 
		        get_stats_color(mechanic_stats_day[3], mechanic_stats_day[2]), mechanic_stats_day[3], get_stats_phrase(mechanic_stats_day[3], mechanic_stats_day[1]), get_percent_pribil(mechanic_stats_day[3], mechanic_stats_day[2]), 
		        get_stats_color(mechanic_stats_day[4], mechanic_stats_day[3]), mechanic_stats_day[4], get_stats_phrase(mechanic_stats_day[4], mechanic_stats_day[1]), get_percent_pribil(mechanic_stats_day[4], mechanic_stats_day[3]), 
		        get_stats_color(mechanic_stats_day[5], mechanic_stats_day[4]), mechanic_stats_day[5], get_stats_phrase(mechanic_stats_day[5], mechanic_stats_day[1]), get_percent_pribil(mechanic_stats_day[5], mechanic_stats_day[4]), 
		        get_stats_color(mechanic_stats_day[6], mechanic_stats_day[5]), mechanic_stats_day[6], get_stats_phrase(mechanic_stats_day[6], mechanic_stats_day[1]), get_percent_pribil(mechanic_stats_day[6], mechanic_stats_day[5]), 
		        get_stats_color(mechanic_stats_day[7], mechanic_stats_day[6]), mechanic_stats_day[7], get_stats_phrase(mechanic_stats_day[7], mechanic_stats_day[1]), get_percent_pribil(mechanic_stats_day[7], mechanic_stats_day[6]), 
		        mounth_mech_stats[m], get_stats_color(mechanic_stats_mounth, mechanic_stats_prewiow), mechanic_stats_mounth, get_stats_phrase(mechanic_stats_mounth, mechanic_stats_prewiow), get_percent_pribil(mechanic_stats_mounth, mechanic_stats_prewiow), 
		        mounth_mech_stats[m-1], mechanic_stats_prewiow,
		        all_day_seven,
		        mechanic_status_all,
		        mechanic_stats_today);
			    SPD(playerid, DIALOG_PERSONAL_CLOSE, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Статистика СТО:", String2048, !"Закрыть", ""); 
			}
			case MECHANIC_BASE_STATION_3:
			{
			    format(String2048, sizeof(String2048), "\
		        "cGREY"Дата\t"cGREY"Сумма\t"cGREY"Выгода/Убыток\n\
		        "cLRED"- "cWH"Понедельник\t%s %d рублей\t"cGR"Не изменилась\n\
		        "cLRED"- "cWH"Вторник\t%s %d рублей\t%s %d рублей\n\
		        "cLRED"- "cWH"Среда\t%s %d рублей\t%s %d рублей\n\
		        "cLRED"- "cWH"Четверг\t%s %d рублей\t%s %d рублей\n\
		        "cLRED"- "cWH"Пятница\t%s %d рублей\t%s %d рублей\n\
		        "cLRED"- "cWH"Суббота\t%s %d рублей\t%s %d рублей\n\
		        "cLRED"- "cWH"Воскресенье\t%s %d рублей\t%s %d рублей\n\
		        "cLRED"\t\n\
		        "cLRED"- "cWH"За %s\t%s%d рублей\t%s %d рублей\n\
		        "cLRED"- "cWH"За %s\t"cGR"%d рублей\n\
		        "cLRED"- "cWH"За неделю\t"cGR"%d рублей\n\
		        "cLRED"- "cWH"За все время\t"cGR"%d рублей\n\
		        "cLRED"- "cWH"За текущий день\t"cGR"%d рублей", 

		        get_stats_color(mechanic_stats_day[1], mechanic_stats_day[1]), mechanic_stats_day[1],
		        get_stats_color(mechanic_stats_day[2], mechanic_stats_day[1]), mechanic_stats_day[2], get_stats_phrase(mechanic_stats_day[2], mechanic_stats_day[1]), get_percent_pribil(mechanic_stats_day[2], mechanic_stats_day[1]), 
		        get_stats_color(mechanic_stats_day[3], mechanic_stats_day[2]), mechanic_stats_day[3], get_stats_phrase(mechanic_stats_day[3], mechanic_stats_day[1]), get_percent_pribil(mechanic_stats_day[3], mechanic_stats_day[2]), 
		        get_stats_color(mechanic_stats_day[4], mechanic_stats_day[3]), mechanic_stats_day[4], get_stats_phrase(mechanic_stats_day[4], mechanic_stats_day[1]), get_percent_pribil(mechanic_stats_day[4], mechanic_stats_day[3]), 
		        get_stats_color(mechanic_stats_day[5], mechanic_stats_day[4]), mechanic_stats_day[5], get_stats_phrase(mechanic_stats_day[5], mechanic_stats_day[1]), get_percent_pribil(mechanic_stats_day[5], mechanic_stats_day[4]), 
		        get_stats_color(mechanic_stats_day[6], mechanic_stats_day[5]), mechanic_stats_day[6], get_stats_phrase(mechanic_stats_day[6], mechanic_stats_day[1]), get_percent_pribil(mechanic_stats_day[6], mechanic_stats_day[5]), 
		        get_stats_color(mechanic_stats_day[7], mechanic_stats_day[6]), mechanic_stats_day[7], get_stats_phrase(mechanic_stats_day[7], mechanic_stats_day[1]), get_percent_pribil(mechanic_stats_day[7], mechanic_stats_day[6]), 
		        mounth_mech_stats[m], get_stats_color(mechanic_stats_mounth, mechanic_stats_prewiow), mechanic_stats_mounth, get_stats_phrase(mechanic_stats_mounth, mechanic_stats_prewiow), get_percent_pribil(mechanic_stats_mounth, mechanic_stats_prewiow), 
		        mounth_mech_stats[m-1], mechanic_stats_prewiow,
		        all_day_seven,
		        mechanic_status_all,
		        mechanic_stats_today);
			    SPD(playerid, DIALOG_PERSONAL_CLOSE, DIALOG_STYLE_TABLIST_HEADERS, !""cLRED"Статистика СТО:", String2048, !"Закрыть", ""); 
			}
		}

  	}
  	sql_free_result(mechanic_stats);


	return true;
}



stock invite_mechanic_station(playerid, playerid_to)
{

	new 
		id_mechanic;

	if(pData[playerid_to][pMechOwnerID] != -1)
	{
		id_mechanic = pData[playerid_to][pMechOwnerID];		
	}
	else if(pData[playerid_to][pMechOwnerLowID] != -1)
	{
		id_mechanic = pData[playerid_to][pMechOwnerLowID];
	}


	if(pData[playerid][pMech] == id_mechanic)
		return SendErr(playerid_to, "Игрок уже является сотрудником СТО!");

	if(!pData[playerid][pLicenses][LIC_DRIVING])
		return SendErr(playerid_to, "У игрока нет лицензии на управление транспортом!");

	if(pData[playerid][pLevel] < 3)
		return SendErr(playerid_to, "У игрока меньше 3 лет проживания в области!");


	pData[playerid][pMech] = id_mechanic;
	pData[playerid][pMechOwnerLowID] = -1;
	pData[playerid][pMechRank] = 1;

	pData[playerid][pJob] = SKILL_MECHANIC;

	UpdatePlayerData(playerid, "job", pData[player_id][pJob]);

	UpdatePlayerData(playerid,"pMechOwnerLowID", pData[playerid][pMechOwnerLowID]);	
	UpdatePlayerData(playerid,"mech", pData[playerid][pMech]);	
	UpdatePlayerData(playerid,"pMechRank", pData[playerid][pMechRank]);	

	format(String1024,sizeof(String1024),"INSERT INTO `mechanic_personal`(`id`,`user_id`,`user_rank`) VALUES ('%d','%d','%d')", id_mechanic, 
	pData[playerid][pMysqlID], 1);
	sql_queryEx(zConn, String1024, QUERY_THREADED);

	new 
		fmt_str[45+MAX_PLAYER_NAME];

	format(fmt_str, sizeof(fmt_str), "[M] На СТО был принят новый сотрудник - %s", pData[playerid][pNickname]);
	send_mechanic_job(id_mechanic, COLOR_GREY, fmt_str);

	new mese[120];
	format(mese,sizeof(mese),"подписал(а) контракт на работу в СТО №%d", id_mechanic+1);
	MeAction(playerid ,mese);


	mechanic_job_initialization(playerid);

	return true;
}

stock invite_mechanic_station_dialog(playerid)
{

	new 
		id_mechanic = GetPVarIntNew(playerid, "id_mechanic");

	if(pData[playerid][pMech] == id_mechanic)
		return SendErr(playerid, "Вы уже являетесь сотрудником СТО!");

	if(!pData[playerid][pLicenses][LIC_DRIVING])
		return SendErr(playerid, "У вас нет лицензии на управление транспортом!");


	pData[playerid][pMech] = id_mechanic;
	pData[playerid][pMechOwnerLowID] = -1;

	pData[playerid][pMechRank] = 1;

	pData[playerid][pJob] = SKILL_MECHANIC;

	UpdatePlayerData(playerid,"pMechOwnerLowID", pData[playerid][pMechOwnerLowID]);	
	UpdatePlayerData(playerid,"mech", pData[playerid][pMech]);	
	UpdatePlayerData(playerid, "job", pData[playerid][pJob]);
	UpdatePlayerData(playerid,"pMechRank", pData[playerid][pMechRank]);	

	format(String1024,sizeof(String1024),"INSERT INTO `mechanic_personal`(`id`,`user_id`,`user_rank`) VALUES ('%d','%d','%d')", id_mechanic, 
	pData[playerid][pMysqlID], 1);
	sql_queryEx(zConn, String1024, QUERY_THREADED);

	new 
		fmt_str[45+MAX_PLAYER_NAME];

	format(fmt_str, sizeof(fmt_str), "[M] На СТО был принят новый сотрудник - %s", pData[playerid][pNickname]);
	send_mechanic_job(id_mechanic, COLOR_GREY, fmt_str);

	new mese[120];
	format(mese,sizeof(mese),"подписал(а) контракт на работу в СТО №%d", id_mechanic+1);
	MeAction(playerid ,mese);

	mechanic_job_initialization(playerid);

	return true;
}


stock send_mechanic_job(mechanic_id, color, msg[])
{
	foreach(new i: logged_players)
	{
		if(!IsPlayerConnected(i)) continue;
		if(pData[i][pMech] == mechanic_id && pData[i][pMech] != -1)
		{
			SendClientMessage(i, color, msg);
		}
	}
	return true;
}

CMD:rm(playerid, params[])
{
	if(pData[playerid][pMech] == -1) 
		return SendErr(playerid, "Чтобы использовать чат механиков, нужно устроиться на работу");

	if(pData[playerid][pMut])
	{
		return SendErr(playerid, "У Вас бан чата. Используйте /time чтобы узнать время бана.");
	}
	if(pTemp[playerid][pMutM])
	{
		return SendErr(playerid, "У Вас затычка во рту.");
	}
	if(pData[playerid][pMutMech])
	{
		return SendErr(playerid, "У Вас бан чата. Используйте /time чтобы узнать время бана.");
	}

	if(sscanf(params, "s[90]", params[0])) 
		return SendInf(playerid, "/rm [Текст] чтобы написать в чат механиков(IC информация)");

	switch(pData[playerid][pMech])
	{
		case MECHANIC_BASE_STATION_1:
		{

			format(String144, sizeof(String144), "[M] %s %s [%d]: "cWH"%s", mechanic_rank_name[pData[playerid][pMechRank]],  pData[playerid][pNickname], playerid, params[0]);
			send_mechanic_job(MECHANIC_BASE_STATION_1, COLOR_ORANGE, String144);
			return true;
		}
		case MECHANIC_BASE_STATION_2:
		{

			format(String144, sizeof(String144), "[M] %s %s [%d]: "cWH"%s", mechanic_rank_name[pData[playerid][pMechRank]],  pData[playerid][pNickname], playerid, params[0]);
			send_mechanic_job(MECHANIC_BASE_STATION_2, COLOR_BLUE, String144);
			return true;
		}
		case MECHANIC_BASE_STATION_3:
		{

			format(String144, sizeof(String144), "[M] %s %s [%d]: "cWH"%s", mechanic_rank_name[pData[playerid][pMechRank]],  pData[playerid][pNickname], playerid, params[0]);
			send_mechanic_job(MECHANIC_BASE_STATION_2, COLOR_ERROR, String144);

			return true;
		}
	}

	return true;
}

stock mechanic_job_initialization(playerid)
{

	format(String512, sizeof(String512), "SELECT * FROM mechanic_personal WHERE user_id = '%d' LIMIT 1", pData[playerid][pMysqlID]);
	new Result:mechanic_find_pers = sql_queryEx(zConn, String512, QUERY_CACHED);

	if(sql_num_rows(mechanic_find_pers)) 
	{
		new 
			mechanic_rank;


  		mechanic_rank = sql_get_field_assoc_int(mechanic_find_pers, "user_rank");

  		if(mechanic_rank == 1)
  		{
  			pData[playerid][pMechRank] = 1;

  			SendInf(playerid, "Вы авторизовались как механик СТО");
  		}
  		else if(mechanic_rank == 2)
  		{
  			pData[playerid][pMechRank] = 2;
  			SendInf(playerid, "Вы авторизовались как управляющий СТО");
  		} 
  		else if(mechanic_rank == 3)
  		{
  			pData[playerid][pMechRank] = 3;
  			SendInf(playerid, "Вы авторизовались как владелец СТО");
  		} 
	}	
	sql_free_result(mechanic_find_pers);

	return true;
}

stock mechanic_job_stats(playerid)
{
	if(pData[playerid][pMech] == -1)
		return true;

	new 
		id_mechanic;

	id_mechanic = pData[playerid][pMech];



	format(String1024, sizeof(String1024), "SELECT * FROM mechanic_personal WHERE user_id = '%d' LIMIT 1", pData[playerid][pMysqlID]);
	new Result:mechanic_find_pers = sql_queryEx(zConn, String1024, QUERY_CACHED);

	if(sql_num_rows(mechanic_find_pers)) 
	{
		new 
			mehcnaic_date[32],
			mech_user_money_day,
			mech_user_money_all;


  		mech_user_money_day = sql_get_field_assoc_int(mechanic_find_pers, "user_money_day");
  		mech_user_money_all = sql_get_field_assoc_int(mechanic_find_pers, "user_money_all");

  		sql_get_field_assoc(mechanic_find_pers, "user_data_join", mehcnaic_date, 20);
		switch(id_mechanic)
		{
			case MECHANIC_BASE_STATION_1:
			{
			    format(String1024, sizeof(String1024), "\
		        "cGREY"Тип\t"cGREY"Информация\t\n\
		        "cORANGE"- "cWH"Доход за день\t"cGR"%d рублей\n\
		        "cORANGE"- "cWH"Общий доход за всё время\t"cGR"%d рублей\n\
		        "cORANGE"\t\n\
		        "cORANGE"- "cWH"Должность\t"cGREY"%s\n\
		        "cORANGE"- "cWH"Дата вступления\t"cGREY"%s", 
		        mech_user_money_day, mech_user_money_all,
		        mechanic_rank_name[pData[playerid][pMechRank]], mehcnaic_date);
			    SPD(playerid, 0, DIALOG_STYLE_TABLIST_HEADERS, !""cORANGE"Ваш доход в СТО:", String1024, !"Закрыть", ""); 
			}
			case MECHANIC_BASE_STATION_2:
			{
			    format(String1024, sizeof(String1024), "\
		        "cGREY"Тип\t"cGREY"Информация\t\n\
		        "cBLUE"- "cWH"Доход за день\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"Общий доход за всё время\t"cGR"%d рублей\n\
		        "cBLUE"\t\n\
		        "cBLUE"- "cWH"Должность\t"cGREY"%s\n\
		        "cBLUE"- "cWH"Дата вступления\t"cGREY"%s", 
		        mech_user_money_day, mech_user_money_all,
		        mechanic_rank_name[pData[playerid][pMechRank]], mehcnaic_date);
			    SPD(playerid, 0, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Ваш доход в СТО:", String1024, !"Закрыть", ""); 
			}
			case MECHANIC_BASE_STATION_3:
			{
			    format(String1024, sizeof(String1024), "\
		        "cGREY"Тип\t"cGREY"Информация\t\n\
		        "cLRED"- "cWH"Доход за день\t"cGR"%d рублей\n\
		        "cLRED"- "cWH"Общий доход за всё время\t"cGR"%d рублей\n\
		        "cLRED"\t\n\
		        "cLRED"- "cWH"Должность\t"cGREY"%s\n\
		        "cLRED"- "cWH"Дата вступления\t"cGREY"%s", 
		        mech_user_money_day, mech_user_money_all,
		        mechanic_rank_name[pData[playerid][pMechRank]], mehcnaic_date);
			    SPD(playerid, 0, DIALOG_STYLE_TABLIST_HEADERS, !""cLRED"Ваш доход в СТО:", String1024, !"Закрыть", ""); 
			}
		}
	}	
	sql_free_result(mechanic_find_pers);



	return true;
}

stock job_mechanic_station(playerid, mechanic_id)
{

	if(pData[playerid][pMech] == -1)
		return true;

	switch(mechanic_id)
	{
		case MECHANIC_BASE_STATION_1:
		{
		    format(String256, sizeof(String256), "\
		    "cGREY"Пункт\t"cGREY"Действие\n\
		    "cORANGE"1. "cWH"Работа\t"cGR"Приступить\n\
		    "cORANGE"2. "cWH"Общая статистика механиком\t"cGR"Открыть\n\
		    "cORANGE"3. "cWH"Уволиться из СТО\t"cGR"Открыть");
		    SPD(playerid, DIALOG_START_MECH_JOB_1, DIALOG_STYLE_TABLIST_HEADERS, !""cORANGE"Работа на СТО", String256, !"Выбрать", !"Закрыть"); 			
		}
		case MECHANIC_BASE_STATION_2:
		{
		    format(String256, sizeof(String256), "\
		    "cGREY"Пункт\t"cGREY"Действие\n\
		    "cBLUE"1. "cWH"Работа\t"cGR"Приступить\n\
		    "cBLUE"2. "cWH"Общая статистика механиком\t"cGR"Открыть\n\
		    "cBLUE"3. "cWH"Уволиться из СТО\t"cGR"Открыть");
		    SPD(playerid, DIALOG_START_MECH_JOB_1, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Работа на СТО", String256, !"Выбрать", !"Закрыть"); 			
		}
		case MECHANIC_BASE_STATION_3:
		{
		    format(String256, sizeof(String256), "\
		    "cGREY"Пункт\t"cGREY"Действие\n\
		    "cLRED"1. "cWH"Работа\t"cGR"Приступить\n\
		    "cLRED"2. "cWH"Общая статистика механиком\t"cGR"Открыть\n\
		    "cLRED"3. "cWH"Уволиться из СТО\t"cGR"Открыть");
		    SPD(playerid, DIALOG_START_MECH_JOB_1, DIALOG_STYLE_TABLIST_HEADERS, !""cLRED"Работа на СТО", String256, !"Выбрать", !"Закрыть"); 			
		}
	}
	return true;
}

stock dialog_job_mechanic(playerid)
{
	new 
		id_mechanic;

	id_mechanic = pData[playerid][pMech];


	if(pData[playerid][pMech] == -1)
		return SendErr(playerid, "Вы не работаете на СТО, чтобы начать работу!");

	if(pData[playerid][pMechRank] == 0)
		return SendErr(playerid, "Вы не работаете на СТО, чтобы начать работу!");

	if(!GetPVarIntNew(playerid, "mechanic_job"))
	{
		switch(id_mechanic)
		{
			case MECHANIC_BASE_STATION_1:
			{
				SPD(playerid, DIALOG_START_MECH_JOB, DIALOG_STYLE_MSGBOX, !""cORANGE"Начало работы на СТО", !"\
				"cWH"Вы хотите начать работать механиком?", !"Начать", !"Нет");		
			}
			case MECHANIC_BASE_STATION_2:
			{
				SPD(playerid, DIALOG_START_MECH_JOB, DIALOG_STYLE_MSGBOX, !""cBLUE"Начало работы на СТО", !"\
				"cWH"Вы хотите начать работать механиком?", !"Начать", !"Нет");					
			}
			case MECHANIC_BASE_STATION_3:
			{
				SPD(playerid, DIALOG_START_MECH_JOB, DIALOG_STYLE_MSGBOX, !""cLRED"Начало работы на СТО", !"\
				"cWH"Вы хотите начать работать механиком?", !"Начать", !"Нет");				
			}
		}
	}
	else
	{
		switch(id_mechanic)
		{
			case MECHANIC_BASE_STATION_1:
			{
				SPD(playerid, DIALOG_START_MECH_JOB, DIALOG_STYLE_MSGBOX, !""cORANGE"Окончание работы на СТО", !"\
				"cWH"Вы хотите закончить работу механиком?", !"Да", !"Нет");
			}
			case MECHANIC_BASE_STATION_2:
			{
				SPD(playerid, DIALOG_START_MECH_JOB, DIALOG_STYLE_MSGBOX, !""cBLUE"Окончание работы на СТО", !"\
				"cWH"Вы хотите закончить работу механиком?", !"Да", !"Нет");			
			}
			case MECHANIC_BASE_STATION_3:
			{
				SPD(playerid, DIALOG_START_MECH_JOB, DIALOG_STYLE_MSGBOX, !""cLRED"Окончание работы на СТО", !"\
				"cWH"Вы хотите закончить работу механиком?", !"Да", !"Нет");		
			}
		}
	}
	return true;
}

stock start_mechanic_job(playerid)
{

	if(pData[playerid][pMech] == -1)
		return SendErr(playerid, "Вы не работаете на СТО, чтобы начать работу!");

	if(pData[playerid][pMechRank] == 0)
		return SendErr(playerid, "Вы не работаете на СТО, чтобы начать работу!");

	new 
		id_mechanic;

	id_mechanic = pData[playerid][pMech];

	new 
		fmt_str[45+MAX_PLAYER_NAME];

	format(fmt_str, sizeof(fmt_str), "[M] %s %s[%d] начал работу", mechanic_rank_name[pData[playerid][pMechRank]], pData[playerid][pNickname], playerid);
	send_mechanic_job(id_mechanic, COLOR_GREY, fmt_str);

	if(pData[playerid][pMechRank] == 1)
	{
		if(pData[playerid][pSex] == 2)
		{
			SetPlayerSkin(playerid, 157);	
		}
		else
		{
			SetPlayerSkin(playerid, 50);
		}
		SendSucc(playerid, "Вы успешно начали рабочий день на СТО");
	}
	else if(pData[playerid][pMechRank] == 2)
	{
		if(pData[playerid][pSex] == 2)
		{
			SetPlayerSkin(playerid, 150);	
		}
		else
		{
			SetPlayerSkin(playerid, 153);
		}
		SendSucc(playerid, "Вы успешно начали рабочий день на СТО");
	}
	else if(pData[playerid][pMechRank] == 3)
	{
		if(pData[playerid][pSex] == 2)
		{
			SetPlayerSkin(playerid, 150);	
		}
		else
		{
			SetPlayerSkin(playerid, 153);
		}
		SendSucc(playerid, "Вы успешно начали рабочий день на СТО");
	}
	SetPVarIntNew(playerid, "mechanic_job", 1);
	SetPVarIntNew(playerid, "mechanic_active_job", 1);

	return true;
}

stock end_mechanic_job(playerid)
{

	if(pData[playerid][pMech] == -1)
		return SendErr(playerid, "Вы не работаете на СТО, чтобы закончить работу!");

	if(pData[playerid][pMechRank] == 0)
		return SendErr(playerid, "Вы не работаете на СТО, чтобы закончить работу!");

	new 
		id_mechanic;

	id_mechanic = pData[playerid][pMech];

	new 
		fmt_str[45+MAX_PLAYER_NAME];

	format(fmt_str, sizeof(fmt_str), "[M] %s %s[%d] закончил работу", mechanic_rank_name[pData[playerid][pMechRank]], pData[playerid][pNickname], playerid);
	send_mechanic_job(id_mechanic, COLOR_GREY, fmt_str);

	DeletePVarNew(playerid, "mechanic_active_job");
	DeletePVarNew(playerid, "mechanic_job");

	SetPlayerSkin(playerid, pData[playerid][pSkin]);

	SendSucc(playerid, "Вы успешно закончили рабочий день на СТО");

	return true;
}

stock clear_pvar_mechanic(playerid)
{

	DeletePVarNew(playerid, "mechanic_active_job");
	DeletePVarNew(playerid, "mechanic_job");
	DeletePVarNew(playerid, "fill_car_m_count");
	DeletePVarNew(playerid, "full_fill_car_m");
	return true;
}

stock get_money_stats_color(money)
{
	new color[10];

	if(money < 0) color = ""cLRED"";
	if(money > 0) color = ""cGR"";
	if(money == 0) color = ""cGR"";

	return color;
}

stock get_mechanic_color(mechanic_id)
{
	new 
		color[10];

	if(mechanic_id == MECHANIC_BASE_STATION_1) color = ""cORANGE"";
	if(mechanic_id == MECHANIC_BASE_STATION_2) color = ""cBLUE"";
	if(mechanic_id == MECHANIC_BASE_STATION_3) color = ""cLRED"";

	return color;
}


stock random_phrase_box()
{
	new 
		phrase = random(6);

	new 
		phrase_text[50];

	switch(phrase)
	{
		case 0: phrase_text = "Тушит бычок рядом с канистрой топлива";
		case 1: phrase_text = "Пытается найти ключ на 15";
		case 2: phrase_text = "Скручивает пробег у авто";
		case 3: phrase_text = "Делает вид, что работает";
		case 4: phrase_text = "Курит сигарету и заливает топливо";
		case 5: phrase_text = "Плачет из-за компрессии";

	}
	return phrase_text;
}

stock get_percent_pribil(money_previow, money_first)
{

	new 
		final_money = money_previow - money_first;
	
	return final_money;
}

CMD:minvite(playerid, params[])
{
	if(pData[playerid][pMechOwnerID] != -1 && pData[playerid][pMechOwnerLowID] == -1 || pData[playerid][pMechOwnerID] == -1 && pData[playerid][pMechOwnerLowID] != -1)
	{

		if(sscanf(params, "d", params[0])) 
			return SendInf(playerid, "/minvite [ID игрока]");

		format(String512, sizeof(String512), "SELECT COUNT(id) FROM `mechanic_personal` WHERE id = '%d' LIMIT 1", pData[playerid][pMech]);
		new Result:count_personal = sql_queryEx(zConn, String512, QUERY_CACHED);

		new 
			count_trucker_personal = sql_num_rows(count_personal);

		sql_free_result(count_personal);

		if(pData[params[0]][pTrucker] != -1)
			return SendErr(playerid, "Игрок уже состоит в транспортной компании!");
		if(pData[params[0]][pMech] != -1)
			return SendErr(playerid, "Игрок уже состоит в СТО!");
		if(pData[params[0]][pTaxi] != -1)
			return SendErr(playerid, "Игрок уже состоит в Такси!");


		offer_player(playerid, params[0], OFFER_MECHANIC_INVITE);
	}
	else
	{
		SendErr(playerid, "Вы не владеете СТО или не являетесь заместителем!");
	}

	return true;
}


CMD:mmute(playerid, params[])
{
	if(pData[playerid][pMechOwnerID] != -1 && pData[playerid][pMechOwnerLowID] == -1 || pData[playerid][pMechOwnerID] == -1 && pData[playerid][pMechOwnerLowID] != -1)
	{
	
		if(sscanf(params, "dds[64]", params[0], params[1], params[2])) 
			return SendInf(playerid, "/tmute [ID игрока] [К-во минут] [Причина]");

		if(!IsPlayerConnected(params[0]) || params[0] == playerid) 
			return SendInf(playerid, "Неверный ID игрока");

		if(pData[params[0]][pMech] != pData[playerid][pMech])
			return SendErr(playerid, "Игрок не состоит в Вашей Транспортной Компании");

		new 
			id_trucker = pData[playerid][pMech];

		new 
			id = params[0];
		new time = params[1];
		if(time < 10 || time > 180) 
			return SendErr(playerid,"Введите время от 10 до 180 минут");

		if(pData[id][pMutMech] > 0) 
			return SendErr(playerid, "Данному игроку уже выдан бан чата рации!");

		pData[id][pMutMech] = time;
		UpdatePlayerData(id,"pMutMech",time);

		format(String256, sizeof(String256), "[СТО] %s[%d] выдал блокировку рации %s[%d] на %d минут. Причина: %s", pData[playerid][pNickname], playerid,
		pData[id][pNickname], id, time, params[2]);
		send_mechanic_job(id_trucker, COLOR_GREY, String256);
	}
	else
	{
		SendErr(playerid, "Вы не владеете СТО или не являетесь заместителем!");
	}
	return true;
}

CMD:munmute(playerid, params[])
{
	if(pData[playerid][pMechOwnerID] != -1 && pData[playerid][pMechOwnerLowID] == -1 || pData[playerid][pMechOwnerID] == -1 && pData[playerid][pMechOwnerLowID] != -1)
	{
	
		if(sscanf(params, "d", params[0])) 
			return SendInf(playerid, "/tunmute [ID игрока]");

		if(!IsPlayerConnected(params[0]) || params[0] == playerid) 
			return SendInf(playerid, "Неверный ID игрока");

		if(pData[params[0]][pMech] != pData[playerid][pMech])
			return SendErr(playerid, "Игрок не состоит в Вашей Транспортной Компании");

		new 
			id_trucker = pData[playerid][pMech];

		if(pData[params[0]][pMutMech] == 0) 
			return SendErr(playerid, "У данного игрока нет блокировки рации!");

		pData[params[0]][pMutMech] = 0;
		UpdatePlayerData(params[0],"pMutMech",0);

		format(String256, sizeof(String256), "[СТО] %s[%d] снял блокировку рации с %s[%d]", pData[playerid][pNickname], playerid,
		pData[params[0]][pNickname], params[0]);
		send_mechanic_job(id_trucker, COLOR_GREY, String256);

	}
	else
	{
		SendErr(playerid, "Вы не владеете СТО или не являетесь заместителем!");
	}
	return true;
}



CMD:muninvite(playerid, params[])
{
	if(pData[playerid][pMechOwnerID] != -1 && pData[playerid][pMechOwnerLowID] == -1 || pData[playerid][pMechOwnerID] == -1 && pData[playerid][pMechOwnerLowID] != -1)
	{
		if(sscanf(params, "d", params[0])) 
			return SendInf(playerid, "/minvite [ID игрока]");

		if(!IsPlayerConnected(params[0]) || params[0] == playerid) 
			return SendInf(playerid, "Неверный ID игрока");

		if(pData[params[0]][pMech] != pData[playerid][pMechOwnerID])
			return SendErr(playerid, "Игрок не состоит в Вашей Транспортной Компании");

		uninvite_command_pers_mech(playerid, params[0]);
	}
	else
	{
		SendErr(playerid, "Вы не владеете СТО или не являетесь заместителем!");
	}
	return true;
}

CMD:mstats(playerid)
{

	if(pData[playerid][pMech] == -1)
		return SendErr(playerid, "Вы не работаете на СТО, чтобы просмотреть свою статистику!");

	if(pData[playerid][pMechRank] == 0)
		return SendErr(playerid, "Вы не работаете на СТО, чтобы просмотреть свою статистику!");

	return mechanic_job_stats(playerid);
}

CMD:tow(playerid)
{
	if(pData[playerid][pMech] == -1) 
		return SendErr(playerid, "Вы не работаете на СТО, чтобы буксировать транспортные средства!");

	if(pData[playerid][pMechRank] == 0)
		return SendErr(playerid, "Вы не работаете на СТО, чтобы буксировать транспортные средства!");

	new
		pDCAR = GetPlayerVehicleID(playerid);

    if(IsTrailerAttachedToVehicle(pDCAR)) 
    {
    	SendInf(playerid, "Вы перестали буксировать транспортное средство!");
    	SendInf(playerid, "Чтобы начать буксировать транспортное средство, используйте - /tow");
        return DetachTrailerFromVehicle(pDCAR);
    }

    if(GetVehicleModel(pDCAR) != 525) 
        return SendErr(playerid,"Вы не за рулём эвакуатора!");

	if(IsPlayerInDynamicArea(playerid, gAreas[arCarMk])) 
		return SendErr(playerid,"Вы не можете эвакуировать транспорт из авторынка");

	if(get_vehicle_type(pDCAR) == TYPE_BOAT)
		return SendErr(playerid, "Вы не можете взять на буксировку лодку!");
	if(get_vehicle_type(pDCAR) == TYPE_PLANE)
		return SendErr(playerid, "Вы не можете взять на буксировку самолет!");
	if(get_vehicle_type(pDCAR) == TYPE_BYCICLE)
		return SendErr(playerid, "Вы не можете взять на буксировку велосипед!");
	if(get_vehicle_type(pDCAR) == TYPE_MOTO)
		return SendErr(playerid, "Вы не можете взять на буксировку мотоцикл!");

    foreach(Vehicles, i)
    {
        new Float:X,Float:Y,Float:Z;
        GetVehiclePos(i,X,Y,Z);

        if(IsVehicleOccupied(i) || !IsValidVehicle(i)) continue;
        if(IsPlayerInRangeOfPoint(playerid,7.0,X,Y,Z) && i != pDCAR)
        {

        	SendInf(playerid, "Вы начали буксировку транспортного средства!");
        	SendInf(playerid, "Чтобы перестать буксировать транспортное средство, используйте - /tow");
            AttachTrailerToVehicle(i,pDCAR);
            break;
        }
        else continue;
    }
	return true;
}

CMD:repair(playerid, params[])
{
	if(pData[playerid][pMech] == -1)
		return SendErr(playerid, "Вы не работаете на СТО, чтобы чинить автомобили клиентов!");

	if(pData[playerid][pMechRank] == 0)
		return SendErr(playerid, "Вы не работаете на СТО, чтобы чинить автомобили клиентов!");

	new 
		id_mechanic;
 
	id_mechanic = pData[playerid][pMech];

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/repair [ID игрока]");

	if(!IsPlayerConnected(params[0]) || params[0] == playerid) 
		return SendInf(playerid, "Неверный ID игрока");

	if(!IsPlayerInAnyVehicle(params[0])) 
		return SendErr(playerid, "Клиент не в транспорте!");

	if(GetPlayerMoneyEx(params[0]) < mechanic[id_mechanic][mechanic_price_remont]) 
		return SendErr(playerid,"У клиента недостаточно денежных средств!");

	offer_player(playerid, params[0], OFFER_MECHANIC_REPAIR);

	return true;
}


CMD:refill(playerid, params[])
{

	if(pData[playerid][pMech] == -1)
		return SendErr(playerid, "Вы не работаете на СТО, чтобы заправлять машины клиентов!");

	if(pData[playerid][pMechRank] == 0)
		return SendErr(playerid, "Вы не работаете на СТО, чтобы чинить автомобили клиентов!");
	new 
		id_mechanic;

	new 
		fill_count_mech = vehicle[GetPlayerVehicleID(playerid)][carMechFuel];

	id_mechanic = pData[playerid][pMech];

	if(sscanf(params, "dd", params[0], params[1]))
		return SendInf(playerid, "/refill [ID игрока] [Кол-литров]");


	if(!IsPlayerConnected(params[0]) || params[0] == playerid) 
		return SendInf(playerid, "Неверный ID игрока");

	if(!IsPlayerInAnyVehicle(params[0])) 
		return SendErr(playerid, "Клиент не в транспорте!");

	if(fill_count_mech < params[1])
		return SendErr(playerid, "Недостаточно топлива в эвакуаторе!");

	SetPVarIntNew(playerid, "fill_car_m_count", params[1]);
	DeletePVarNew(playerid, "full_fill_car_m");

	offer_player(playerid, params[0], OFFER_MECHANIC_REFILL);


	return true;
}





CMD:reoil(playerid, params[])
{

	if(pData[playerid][pMech] == -1)
		return SendErr(playerid, "Вы не работаете на СТО, чтобы заправлять машины клиентов!");

	if(pData[playerid][pMechRank] == 0)
		return SendErr(playerid, "Вы не работаете на СТО, чтобы заправлять машины клиентов!");
	new 
		id_mechanic;

	new 
		fill_count_mech = vehicle[GetPlayerVehicleID(playerid)][carMechOil];

	id_mechanic = pData[playerid][pMech];

	if(sscanf(params, "dd", params[0], params[1]))
		return SendInf(playerid, "/reoil [ID игрока] [Кол-литров]");


	if(!IsPlayerConnected(params[0]) || params[0] == playerid) 
		return SendInf(playerid, "Неверный ID игрока");

	if(!IsPlayerInAnyVehicle(params[0])) 
		return SendErr(playerid, "Клиент не в транспорте!");

	if(fill_count_mech < params[1])
		return SendErr(playerid, "Недостаточно масла в эвакуаторе!");


	new 
		count_oil = params[1];	

	if(count_oil < 1 || count_oil > 10)
	{
	    SendErr(playerid,"От 1 до 10 литров масла!");
		return true;
	}	

	SetPVarIntNew(playerid, "fill_car_m_count", params[1]);
	DeletePVarNew(playerid, "full_fill_car_m");

	offer_player(playerid, params[0], OFFER_MECHANIC_REOIL);


	return true;
}

stock mechanic_reoil_vehicle(playerid, from_playerid)
{
	new 
		id_mechanic;

	id_mechanic = pData[from_playerid][pMech];

	new 
		fill_count_mech = vehicle[GetPlayerVehicleID(from_playerid)][carMechOil];

	if(!IsPlayerInAnyVehicle(playerid)) 
		return SendErr(from_playerid, "Клиент не в транспорте!");


	new 
		carid_client = GetPlayerVehicleID(playerid),
		carid_mehanic = GetPlayerVehicleID(from_playerid);

	new 
		count_oil = GetPVarIntNew(from_playerid, "fill_car_m_count");

	new 
		fuel_count_price = count_oil * mechanic[id_mechanic][mechanic_price_oil];


	if(fill_count_mech < count_oil)
		return SendErr(from_playerid, "Недостаточно топлива в эвакуаторе!");

	if(GetPlayerMoneyEx(playerid) < fuel_count_price) 
		return SendErr(from_playerid,"У клиента недостаточно денежных средств!");	

	new 
		Float:final_oil = GetPVarIntNew(playerid, "fill_car_m_count")*100;

	if(floatround(final_oil)+floatround(vehicle[carid_client][consumables_oil])  > 1000)
		return SendErr(playerid, "В транспорте достаточно масла!");
	
	vehicle[carid_client][consumables_oil] += final_oil;

	vehicle[carid_mehanic][carMechOil] = vehicle[carid_mehanic][carMechOil]-floatround(final_oil);

	new 
		fmt_str[350];
		
    format(fmt_str, sizeof(fmt_str), "Вы заправили маслом транспорт %s за "cGR"%d"cWH" рублей на %d литров", pData[playerid][pNickname], fuel_count_price, GetPVarIntNew(playerid, "fill_car_m_count"));
    SendSucc(from_playerid, fmt_str);
    format(fmt_str, sizeof(fmt_str), "Механик %s заправил Ваш транспорт маслом за "cGR"%d"cWH" рублей на %d литров", pData[from_playerid][pNickname], \
    	fuel_count_price, GetPVarIntNew(playerid, "fill_car_m_count"));
    SendInf(playerid, fmt_str);	 

	new 
		message[144];
	format(message, sizeof(message), "[СТО] %s[%i] заправил маслом транспортное средство клиента %s[%i]", pData[from_playerid][pNickname], from_playerid, pData[playerid][pNickname], playerid);
	send_mechanic_job(pData[from_playerid][pMech], COLOR_GREY, message);

	give_money(playerid, -fuel_count_price, "Заправка транспортного средства");

	new mese[64];
	format(mese,sizeof(mese),"заправил(а) транспортное средство клиента маслом");
	MeAction(from_playerid ,mese);

	new 
		price = fuel_count_price;

   	if(IsActionTrue4)
	{
		price = price*2;
	}

	price = price-(price/100*mechanic[id_mechanic][mechanic_base_percent]);

	new 
		pricepercent = (price/100*mechanic[id_mechanic][mechanic_base_percent]);

	pay_money_bank_mechanic(pricepercent, id_mechanic);

    format(String144, sizeof(String144), "Вы уже заработали "cGR"%d "cWH"рублей! Комиссия: "cGR"%d "cWH"рублей!", price, pricepercent);
    SendInf(from_playerid, String144);

    give_money(from_playerid, price, "Зарплата Механика (Заправка)");


	update_mechanic_car_3d_t();

	DeletePVarNew(playerid, "fill_car_m_count");
	DeletePVarNew(playerid, "full_fill_car_m");
	DeletePVarNew(playerid, "mechanic_offer_id");

	format(String256,sizeof(String256),"UPDATE `mechanic_personal` SET `user_money_day` = user_money_day+%d WHERE `user_id` = '%d'" , fuel_count_price, pData[from_playerid][pMysqlID]);
	sql_queryEx(zConn, String256, QUERY_THREADED);	
	format(String256,sizeof(String256),"UPDATE `mechanic_personal` SET `user_money_all` = user_money_all+%d WHERE `user_id` = '%d'" , fuel_count_price, pData[from_playerid][pMysqlID]);
	sql_queryEx(zConn, String256, QUERY_THREADED);	

	offer_clear_accept(playerid);


	return true;
}


stock mechanic_refill_vehicle(playerid, from_playerid)
{
	new 
		id_mechanic;

	id_mechanic = pData[from_playerid][pMech];

	new 
		fill_count_mech = vehicle[GetPlayerVehicleID(from_playerid)][carMechFuel];


	if(!IsPlayerInAnyVehicle(playerid)) 
	{
		SendErr(playerid, "Вы не находитесь в транспорте для проведения ремонта!");
		return SendErr(from_playerid, "Клиент не в транспорте!");
	}


	new 
		fuel_count_price = GetPVarIntNew(from_playerid, "fill_car_m_count") * mechanic[id_mechanic][mechanic_price_fuel];

	if(fill_count_mech < GetPVarIntNew(from_playerid, "fill_car_m_count"))
	{
		SendErr(playerid, "У механика недостаточно топлива в эвакуаторе!");
		return SendErr(from_playerid, "Недостаточно топлива в эвакуаторе!");
	}

	if(GetPlayerMoneyEx(playerid) < fuel_count_price) 
	{
		SendErr(playerid, "У вас недостаточно денежных средств!");
		return SendErr(from_playerid,"У клиента недостаточно денежных средств!");	
	}

	new 
		carid_client = GetPlayerVehicleID(playerid),
		carid_mehanic = GetPlayerVehicleID(from_playerid);

	new 
		fuel_fill = GetPVarIntNew(from_playerid, "fill_car_m_count");

	vehicle[carid_client][cFuel] += float(fuel_fill);

	update_fuel_speed_player(playerid, vehicle[carid_client][cFuel]);

	vehicle[carid_mehanic][carMechFuel] = vehicle[carid_mehanic][carMechFuel]-GetPVarIntNew(from_playerid, "fill_car_m_count");

	new 
		fmt_str[350];

    format(fmt_str, sizeof(fmt_str), "Вы заправили транспорт %s за "cGR"%d"cWH" рублей на %d литров", pData[playerid][pNickname], fuel_count_price, GetPVarIntNew(from_playerid, "fill_car_m_count"));
    SendSucc(from_playerid, fmt_str);
    format(fmt_str, sizeof(fmt_str), "Механик %s заправил Ваш транспорт за "cGR"%d"cWH" рублей на %d литров", pData[from_playerid][pNickname], \
    	fuel_count_price, GetPVarIntNew(from_playerid, "fill_car_m_count"));
    SendInf(playerid, fmt_str);		

	new 
		message[144];
	format(message, sizeof(message), "[СТО] %s[%i] заправил топливом транспортное средство клиента %s[%i]", pData[from_playerid][pNickname], from_playerid, pData[playerid][pNickname], playerid);
	send_mechanic_job(pData[from_playerid][pMech], COLOR_GREY, message);


	give_money(playerid, -fuel_count_price, "Заправка транспортного средства");


	new 
		price = fuel_count_price;

   	if(IsActionTrue4)
	{
		price = price*2;
	}

	price = price-(price/100*mechanic[id_mechanic][mechanic_base_percent]);

	new 
		pricepercent = (price/100*mechanic[id_mechanic][mechanic_base_percent]);

	pay_money_bank_mechanic(pricepercent, id_mechanic);

    format(String144, sizeof(String144), "Вы уже заработали "cGR"%d "cWH"рублей! Комиссия: "cGR"%d "cWH"рублей!", price, pricepercent);
    SendInf(from_playerid, String144);

    give_money(from_playerid, price, "Зарплата Механика (Заправка)");

	new mese[64];
	format(mese,sizeof(mese),"заправил(а) транспортное средство клиента топливом");
	MeAction(from_playerid ,mese);

	update_mechanic_car_3d_t();

	format(String256,sizeof(String256),"UPDATE `mechanic_personal` SET `user_money_day` = user_money_day+%d WHERE `user_id` = '%d'" , fuel_count_price, pData[from_playerid][pMysqlID]);
	sql_queryEx(zConn, String256, QUERY_THREADED);	
	format(String256,sizeof(String256),"UPDATE `mechanic_personal` SET `user_money_all` = user_money_all+%d WHERE `user_id` = '%d'" , fuel_count_price, pData[from_playerid][pMysqlID]);
	sql_queryEx(zConn, String256, QUERY_THREADED);	

	DeletePVarNew(from_playerid, "fill_car_m_count");
	DeletePVarNew(from_playerid, "full_fill_car_m");
	DeletePVarNew(from_playerid, "mechanic_offer_id");

	offer_clear_accept(playerid);
	offer_clear_accept(from_playerid);

	

	return true;
}

stock mechanic_repair_vehicle(playerid, from_playerid)
{
	new 
		id_mechanic;

	id_mechanic = pData[from_playerid][pMech];

	if(!IsPlayerInAnyVehicle(playerid)) 
	{
		SendErr(playerid, "Вы не находитесь в транспорте для проведения ремонта!");
		return SendErr(from_playerid, "Клиент не в транспорте!");
	}


	if(GetPlayerMoneyEx(playerid) < mechanic[id_mechanic][mechanic_price_remont]) 
	{
		SendErr(playerid, "У вас недостаточно денежных средств!");
		return SendErr(from_playerid,"У клиента недостаточно денежных средств!");
	}


	new
		id_car = GetPlayerVehicleID(playerid);	

	vehicle[id_car][cHealth] = 1000.0;
	RepairVehicle(GetPlayerVehicleID(playerid));

	new 
		fmt_str[300];


    format(fmt_str, sizeof(fmt_str), "Вы починили транспорт %s за "cGR"%d"cWH" рублей. Вы получили: "cGR"%d"cWH" рублей", pData[playerid][pNickname], mechanic[id_mechanic][mechanic_price_remont], mechanic[id_mechanic][mechanic_price_remont]-percent_money_mechanic(mechanic[id_mechanic][mechanic_price_remont], mechanic[id_mechanic][mechanic_base_percent]));
    SendSucc(from_playerid, fmt_str);
    format(fmt_str, sizeof(fmt_str), "%s починил Ваш транспорт за "cGR"%d"cWH" рублей", pData[from_playerid][pNickname], mechanic[id_mechanic][mechanic_price_remont]);
    SendInf(playerid, fmt_str);


	new 
		message[144];
	format(message, sizeof(message), "[СТО] %s[%i] починил транспортное средство клиента %s[%i]", pData[from_playerid][pNickname], from_playerid, pData[playerid][pNickname], playerid);
	send_mechanic_job(pData[from_playerid][pMech], COLOR_GREY, message);

	give_money(playerid, -mechanic[id_mechanic][mechanic_price_remont], "Ремонт транспортного средства");

	new mese[120];
	format(mese,sizeof(mese),"произвел(а) ремонт транспортного средства клиента");
	MeAction(from_playerid ,mese);

	new 
		price = mechanic[id_mechanic][mechanic_price_remont];

   	if(IsActionTrue4)
	{
		price = price*2;
	}

	price = price-(price/100*mechanic[id_mechanic][mechanic_base_percent]);

	new 
		pricepercent = (price/100*mechanic[id_mechanic][mechanic_base_percent]);

	pay_money_bank_mechanic(pricepercent, id_mechanic);

    format(String144, sizeof(String144), "Вы уже заработали "cGR"%d "cWH"рублей! Комиссия: "cGR"%d "cWH"рублей!", price, pricepercent);
    SendInf(from_playerid, String144);

    give_money(from_playerid, price, "Зарплата Механика (Ремонт)");





	format(String256,sizeof(String256),"UPDATE `mechanic_personal` SET `user_money_day` = user_money_day+%d WHERE `user_id` = '%d'" , mechanic[id_mechanic][mechanic_price_remont], pData[from_playerid][pMysqlID]);
	sql_queryEx(zConn, String256, QUERY_THREADED);	
	format(String256,sizeof(String256),"UPDATE `mechanic_personal` SET `user_money_all` = user_money_all+%d WHERE `user_id` = '%d'" , mechanic[id_mechanic][mechanic_price_remont], pData[from_playerid][pMysqlID]);
	sql_queryEx(zConn, String256, QUERY_THREADED);	

	DeletePVarNew(playerid, "mechanic_offer_id");

	offer_clear_accept(playerid);
	offer_clear_accept(from_playerid);

	return true;
}

stock pay_mechanic_money(playerid, pay_playerid, money)
{
	new 
		id_mechanic;

	id_mechanic = pData[pay_playerid][pMech];

	if(GetPlayerMoney(playerid) < 0) ResetPlayerMoney(playerid);
	if(GetPlayerMoney(pay_playerid) < 0) ResetPlayerMoney(pay_playerid);

	new 
		percent_money = percent_money_mechanic(money, mechanic[id_mechanic][mechanic_base_percent]);

	mechanic[id_mechanic][mechanic_base_bank] += percent_money;	

	new 
		id1 = -1, id2 = -1, remain1, remain2;

	if(pay_playerid >= 0)
	{
		if(pData[pay_playerid][pEConfirmed] < 99 || money < 0)	
		{
			pData[pay_playerid][pMoney] = pData[pay_playerid][pMoney] + (money-percent_money);
			GivePlayerMoney(pay_playerid,money);
		}
		id2 = pData[pay_playerid][pMysqlID];
		remain2 = pData[pay_playerid][pMoney];
	}
	if(playerid >= 0)
	{
		GivePlayerMoney(playerid,-money);
		pData[playerid][pMoney] = pData[playerid][pMoney] - money;
		id1 = pData[playerid][pMysqlID];
		remain1 = pData[playerid][pMoney];
	}
	new y,m,d,h,mi,s;
	getdate(y,m,d);
	gettime(h,mi,s);

	if(playerid >= 0) UpdatePlayerData(playerid,"money",pData[playerid][pMoney]);
	if(pay_playerid >= 0) UpdatePlayerData(pay_playerid,"money",pData[pay_playerid][pMoney]);


	return true;
}

stock percent_money_mechanic(x, y)
{
    new 
    	money_final = (x/100) * y;

    return money_final;
}




stock show_client_box_menu(playerid, type, box)
{
	new 
		price_final = GetPVarIntNew(playerid, "repair_engine_final_price");

	switch(type)
	{
		case MECHANIC_BASE_STATION_1:
		{
		    format(String2048, sizeof(String2048), "\
		    "cGREY"Информация\t"cGREY"Действие\t"cGREY"Стоимость\n\
		    "cORANGE"- "cWH"Автомобильное масло\t"cORANGE"Заменить\t"cGR"%d рублей\n\
		    "cORANGE"- "cWH"Свечи\t"cORANGE"Заменить\t"cGR"%d рублей\n\
		    "cORANGE"- "cWH"Тормоза\t"cORANGE"Заменить\t"cGR"%d рублей\n\
		    "cORANGE"- "cWH"Ремни\t"cORANGE"Заменить\t"cGR"%d рублей\n\
		    "cORANGE"- "cWH"Стартер\t"cORANGE"Заменить\t"cGR"%d рублей\n\
		    "cORANGE"- "cWH"Генератор\t"cORANGE"Заменить\t"cGR"%d рублей\n\
		    "cORANGE"- "cWH"Форсунки\t"cORANGE"Заменить\t"cGR"%d рублей\n\
		    "cORANGE"- "cWH"Насос\t"cORANGE"Заменить\t"cGR"%d рублей\n\
		    "cORANGE"\t\n\
		    "cORANGE"- "cWH"Итого к оплате:\t"cGR"Оплатить\t"cGR"%d рублей\n\
		    "cORANGE"- "cWH"Выбранные услуги\t"cLRED"Очистить\t", 

		    mechanic[type][mechanic_price_oil],
		    mechanic[type][mechanic_price_candles],
		    mechanic[type][mechanic_price_brake],
		    mechanic[type][mechanic_price_belt],
		    mechanic[type][mechanic_price_starter],
		    mechanic[type][mechanic_price_generator],
		    mechanic[type][mechanic_price_forsunki],
		    mechanic[type][mechanic_price_nasos],
		    price_final);
		    SPD(playerid, DIALOG_SELECT_ENGINE_MECH, DIALOG_STYLE_TABLIST_HEADERS, !""cORANGE"Ремонт двигателя", String2048, !"Выбрать", !"Закрыть"); 	
		}
		case MECHANIC_BASE_STATION_2:
		{
		    format(String2048, sizeof(String2048), "\
		    "cGREY"Информация\t"cGREY"Действие\t"cGREY"Стоимость\n\
		    "cBLUE"- "cWH"Автомобильное масло\t"cBLUE"Заменить\t"cGR"%d рублей\n\
		    "cBLUE"- "cWH"Свечи зажигания\t"cBLUE"Заменить\t"cGR"%d рублей\n\
		    "cBLUE"- "cWH"Тормозные голодки\t"cBLUE"Заменить\t"cGR"%d рублей\n\
		    "cBLUE"- "cWH"Ремни\t"cBLUE"Заменить\t"cGR"%d рублей\n\
		    "cBLUE"- "cWH"Стартер\t"cBLUE"Заменить\t"cGR"%d рублей\n\
		    "cBLUE"- "cWH"Генератор\t"cBLUE"Заменить\t"cGR"%d рублей\n\
		    "cBLUE"- "cWH"Форсунки\t"cBLUE"Заменить\t"cGR"%d рублей\n\
		    "cBLUE"- "cWH"Насос\t"cBLUE"Заменить\t"cGR"%d рублей\n\
		    "cBLUE"\t\n\
		    "cBLUE"- "cWH"Итого к оплате:\t"cGR"Оплатить\t"cGR"%d рублей\n\
		    "cBLUE"- "cWH"Выбранные услуги\t"cLRED"Очистить\t", 

		    mechanic[type][mechanic_price_oil],
		    mechanic[type][mechanic_price_candles],
		    mechanic[type][mechanic_price_brake],
		    mechanic[type][mechanic_price_belt],
		    mechanic[type][mechanic_price_starter],
		    mechanic[type][mechanic_price_generator],
		    mechanic[type][mechanic_price_forsunki],
		    mechanic[type][mechanic_price_nasos],
		    price_final);
		    SPD(playerid, DIALOG_SELECT_ENGINE_MECH, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Ремонт двигателя", String2048, !"Выбрать", !"Закрыть"); 	
		}
		case MECHANIC_BASE_STATION_3:
		{
		    format(String2048, sizeof(String2048), "\
		    "cGREY"Информация\t"cGREY"Действие\t"cGREY"Стоимость\n\
		    "cLRED"- "cWH"Автомобильное масло\t"cLRED"Заменить\t"cGR"%d рублей\n\
		    "cLRED"- "cWH"Свечи\t"cLRED"Заменить\t"cGR"%d рублей\n\
		    "cLRED"- "cWH"Тормоза\t"cLRED"Заменить\t"cGR"%d рублей\n\
		    "cLRED"- "cWH"Ремни\t"cLRED"Заменить\t"cGR"%d рублей\n\
		    "cLRED"- "cWH"Стартер\t"cLRED"Заменить\t"cGR"%d рублей\n\
		    "cLRED"- "cWH"Генератор\t"cLRED"Заменить\t"cGR"%d рублей\n\
		    "cLRED"- "cWH"Форсунки\t"cLRED"Заменить\t"cGR"%d рублей\n\
		    "cLRED"- "cWH"Насос\t"cLRED"Заменить\t"cGR"%d рублей\n\
		    "cLRED"\t\n\
		    "cLRED"- "cWH"Итого к оплате:\t"cGR"Оплатить\t"cGR"%d рублей\n\
		    "cLRED"- "cWH"Выбранные услуги\t"cLRED"Очистить\t", 

		    mechanic[type][mechanic_price_oil],
		    mechanic[type][mechanic_price_candles],
		    mechanic[type][mechanic_price_brake],
		    mechanic[type][mechanic_price_belt],
		    mechanic[type][mechanic_price_starter],
		    mechanic[type][mechanic_price_generator],
		    mechanic[type][mechanic_price_forsunki],
		    mechanic[type][mechanic_price_nasos],
		    price_final);
		    SPD(playerid, DIALOG_SELECT_ENGINE_MECH, DIALOG_STYLE_TABLIST_HEADERS, !""cLRED"Ремонт двигателя", String2048, !"Выбрать", !"Закрыть"); 	
		}
	}


	return true;
}


stock select_engine_rem_list(playerid, type)
{
	new 
		type_mech = GetPVarIntNew(playerid, "box_mech_type_2"),
		box_mech = GetPVarIntNew(playerid, "box_mech_type");


	switch(type)
	{
		case 1:
		{
			if(GetPVarIntNew(playerid, "repair_engine_oil_c"))
				return SendErr(playerid, "Данная услуга по ремонту уже добавлена в Ваш список!");

			repair_engine_price(playerid, mechanic[type_mech][mechanic_price_oil]);

		    format(String144, sizeof(String144), "Вы успешно добавили в список ремонта 'Автомобильное масло'. Стоимость: "cGR"%d"cWH" рублей", mechanic[type_mech][mechanic_price_oil]);
		    SendSucc(playerid, String144);

		    SetPVarIntNew(playerid, "repair_engine_oil_c", 1);

			show_client_box_menu(playerid, type_mech, box_mech);
		}
		case 2:
		{
			if(GetPVarIntNew(playerid, "repair_engine_candles_c"))
				return SendErr(playerid, "Данная услуга по ремонту уже добавлена в Ваш список!");

			repair_engine_price(playerid, mechanic[type_mech][mechanic_price_candles]);

		    format(String144, sizeof(String144), "Вы успешно добавили в список ремонта 'Свечи'. Стоимость: "cGR"%d"cWH" рублей", mechanic[type_mech][mechanic_price_candles]);
		    SendSucc(playerid, String144);

		    SetPVarIntNew(playerid, "repair_engine_candles_c", 1);


			show_client_box_menu(playerid, type_mech, box_mech);			
		}
		case 3:
		{
			if(GetPVarIntNew(playerid, "repair_engine_brake_c"))
				return SendErr(playerid, "Данная услуга по ремонту уже добавлена в Ваш список!");

			repair_engine_price(playerid, mechanic[type_mech][mechanic_price_brake]);

		    format(String144, sizeof(String144), "Вы успешно добавили в список ремонта 'Тормоза'. Стоимость: "cGR"%d"cWH" рублей", mechanic[type_mech][mechanic_price_brake]);
		    SendSucc(playerid, String144);

		    SetPVarIntNew(playerid, "repair_engine_brake_c", 1);

			show_client_box_menu(playerid, type_mech, box_mech);
		}
		case 4:
		{
			if(GetPVarIntNew(playerid, "repair_engine_belt_c"))
				return SendErr(playerid, "Данная услуга по ремонту уже добавлена в Ваш список!");

			repair_engine_price(playerid, mechanic[type_mech][mechanic_price_belt]);

		    format(String144, sizeof(String144), "Вы успешно добавили в список ремонта 'Ремни'. Стоимость: "cGR"%d"cWH" рублей", mechanic[type_mech][mechanic_price_belt]);
		    SendSucc(playerid, String144);

		    SetPVarIntNew(playerid, "repair_engine_belt_c", 1);


			show_client_box_menu(playerid, type_mech, box_mech);			
		}
		case 5:
		{
			if(GetPVarIntNew(playerid, "repair_engine_starter_c"))
				return SendErr(playerid, "Данная услуга по ремонту уже добавлена в Ваш список!");

			repair_engine_price(playerid, mechanic[type_mech][mechanic_price_starter]);

		    format(String144, sizeof(String144), "Вы успешно добавили в список ремонта 'Стартер'. Стоимость: "cGR"%d"cWH" рублей", mechanic[type_mech][mechanic_price_starter]);
		    SendSucc(playerid, String144);

		    SetPVarIntNew(playerid, "repair_engine_starter_c", 1);

			show_client_box_menu(playerid, type_mech, box_mech);
		}
		case 6:
		{
			if(GetPVarIntNew(playerid, "repair_engine_generator_c"))
				return SendErr(playerid, "Данная услуга по ремонту уже добавлена в Ваш список!");

			repair_engine_price(playerid, mechanic[type_mech][mechanic_price_generator]);

		    format(String144, sizeof(String144), "Вы успешно добавили в список ремонта 'Генератор'. Стоимость: "cGR"%d"cWH" рублей", mechanic[type_mech][mechanic_price_generator]);
		    SendSucc(playerid, String144);

		    SetPVarIntNew(playerid, "repair_engine_generator_c", 1);

			show_client_box_menu(playerid, type_mech, box_mech);			
		}
		case 7:
		{
			if(GetPVarIntNew(playerid, "repair_engine_forsunki_c"))
				return SendErr(playerid, "Данная услуга по ремонту уже добавлена в Ваш список!");

			repair_engine_price(playerid, mechanic[type_mech][mechanic_price_forsunki]);

		    format(String144, sizeof(String144), "Вы успешно добавили в список ремонта 'Форсунки'. Стоимость: "cGR"%d"cWH" рублей", mechanic[type_mech][mechanic_price_forsunki]);
		    SendSucc(playerid, String144);

		    SetPVarIntNew(playerid, "repair_engine_forsunki_c", 1);

			show_client_box_menu(playerid, type_mech, box_mech);
		}
		case 8:
		{
			if(GetPVarIntNew(playerid, "repair_engine_nasos_c"))
				return SendErr(playerid, "Данная услуга по ремонту уже добавлена в Ваш список!");

			repair_engine_price(playerid, mechanic[type_mech][mechanic_price_nasos]);

		    format(String144, sizeof(String144), "Вы успешно добавили в список ремонта 'Насос'. Стоимость: "cGR"%d"cWH" рублей", mechanic[type_mech][mechanic_price_nasos]);
		    SendSucc(playerid, String144);

		    SetPVarIntNew(playerid, "repair_engine_nasos_c", 1);

			show_client_box_menu(playerid, type_mech, box_mech);			
		}
	}


	return true;
}

stock accept_engine_rem(playerid)
{
	new 
		price_final = GetPVarIntNew(playerid, "repair_engine_final_price"); 

	new 
		type_mech = GetPVarIntNew(playerid, "box_mech_type_2"),
		box_mech = GetPVarIntNew(playerid, "box_mech_type");	

	if(GetPlayerMoneyEx(playerid) < price_final)
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
		SendErr(playerid,"У вас недостаточно денег для оплаты услуг по ремонту двигателя!");

		return show_client_box_menu(playerid, type_mech, box_mech);
	}

	if(price_final == 0)
	{
		return show_client_box_menu(playerid, type_mech, box_mech);
	}

	start_repair_engine(playerid);
	return true;
}

stock start_repair_engine(playerid)
{
	new 
		vehicleids = GetPlayerVehicleID(playerid);

	TextDrawShowForPlayer(playerid, mech_background_repair);

	TogglePlayerAllHudElements(playerid, HUD_ELEMENT_HIDE);
	hide_hud_element(playerid);	

	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
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
	}

	show_player_green_zone(playerid, TEXTDRAW_HIDE);

	TogglePlayerControllable(playerid, 0);
	repair_engine_stap(playerid);

	return true;
}

stock final_repair_engine(playerid)
{

	new 
		veh_ids = GetPlayerVehicleID(playerid);

	TogglePlayerControllable(playerid, 1);

	TextDrawHideForPlayer(playerid, mech_background_repair);


	new 
		final_price = GetPVarIntNew(playerid, "repair_engine_final_price"); 

	pay_money_bank_mechanic(final_price, GetPVarIntNew(playerid, "box_mech_type_2"));


    give_money(playerid, -final_price, "Ремонт автомобиля у механиков");	

    format(String144,sizeof(String144),"Вы заплатили за ремонт "cGR"%d"cWH" рублей!", final_price);
    SendSucc(playerid, String144);

	show_hud_element(playerid);
	show_hud_hungry(playerid);
	TogglePlayerAllHudElements(playerid, HUD_ELEMENT_SHOW);

	if(pData[playerid][pSettings][10] == 1)
	{
	    new engine, lights, alarm, doors, bonnet, boot, objective;
	    GetVehicleParamsEx(veh_ids, engine, lights, alarm, doors, bonnet, boot, objective);


		show_speed_player(playerid);

		PlayerTextDrawShow(playerid, player_speed_car[0][playerid]);
		PlayerTextDrawShow(playerid, player_speed_car[1][playerid]);
		PlayerTextDrawShow(playerid, player_speed_car[2][playerid]);
		PlayerTextDrawShow(playerid, player_speed_car[3][playerid]);
		PlayerTextDrawShow(playerid, player_speed_car[4][playerid]);
		PlayerTextDrawShow(playerid, player_speed_car[5][playerid]);
		PlayerTextDrawShow(playerid, player_speed_car[6][playerid]);
		PlayerTextDrawShow(playerid, player_speed_car[7][playerid]);
		PlayerTextDrawShow(playerid, player_speed_car[8][playerid]);
		PlayerTextDrawShow(playerid, player_speed_car[9][playerid]);
		PlayerTextDrawShow(playerid, player_speed_car[10][playerid]);

		veh_timer_ex(playerid, veh_ids);

		update_fuel_speed_player(playerid, vehicle[veh_ids][cFuel]);
		update_speed_lock_car(veh_ids, doors);
		update_speed_light_car(veh_ids, lights);
		vehicle_engine_status(veh_ids, engine);

		update_hp_speed_player(veh_ids, vehicle[veh_ids][cHealth]);
		update_dist_speed_player(veh_ids, vehicle[veh_ids][cMileage]);
	}

	RepairVehicle(veh_ids);

	show_speed_player(playerid);

	show_player_green_zone(playerid, TEXTDRAW_SHOW);

	update_hp_speed_player(playerid, vehicle[veh_ids][cHealth]);

	PlayerTextDrawShow(playerid, player_speed_car[playerid][7]);
	PlayerTextDrawShow(playerid, player_speed_car[playerid][5]);
	PlayerTextDrawShow(playerid, player_speed_car[playerid][6]);	


	return true;
}

stock repair_engine_stap(playerid)
{
	if(GetPVarIntNew(playerid, "repair_engine_oil_c"))
	{

		wait_ms(2000);
	}
	if(GetPVarIntNew(playerid, "repair_engine_candles_c"))
	{

		wait_ms(5000);		
	}
	if(GetPVarIntNew(playerid, "repair_engine_brake_c"))
	{

		wait_ms(5000);		
	}
	if(GetPVarIntNew(playerid, "repair_engine_belt_c"))
	{

		wait_ms(5000);		
	}
	if(GetPVarIntNew(playerid, "repair_engine_starter_c"))
	{

		wait_ms(5000);		
	}
	if(GetPVarIntNew(playerid, "repair_engine_generator_c"))
	{

		wait_ms(5000);		
	}
	if(GetPVarIntNew(playerid, "repair_engine_forsunki_c"))
	{

		wait_ms(5000);		
	}
	if(GetPVarIntNew(playerid, "repair_engine_nasos_c"))
	{


		wait_ms(5000);		
	}	

	final_repair_engine(playerid);
	return true;
}


stock clear_engine_rem(playerid)
{

	SendSucc(playerid, "Список выбранных услуг - был сброшен!");

	new 
		type_mech = GetPVarIntNew(playerid, "box_mech_type_2"),
		box_mech = GetPVarIntNew(playerid, "box_mech_type");	

	clear_pvar_client_mech(playerid);

	show_client_box_menu(playerid, type_mech, box_mech);



	return true;
}

stock clear_pvar_client_mech(playerid)
{
	DeletePVarNew(playerid, "repair_engine_final_price");
	DeletePVarNew(playerid, "repair_engine_nasos_c");
	DeletePVarNew(playerid, "repair_engine_forsunki_c");
	DeletePVarNew(playerid, "repair_engine_generator_c");
	DeletePVarNew(playerid, "repair_engine_starter_c");
	DeletePVarNew(playerid, "repair_engine_belt_c");
	DeletePVarNew(playerid, "repair_engine_brake_c");
	DeletePVarNew(playerid, "repair_engine_candles_c");
	DeletePVarNew(playerid, "repair_engine_oil_c");

	DeletePVarNew(playerid, "repair_engine_final_price");


	return true;
}

stock clear_pvar_client_mech_all(playerid)
{
	DeletePVarNew(playerid, "repair_engine_final_price");
	DeletePVarNew(playerid, "repair_engine_nasos_c");
	DeletePVarNew(playerid, "repair_engine_forsunki_c");
	DeletePVarNew(playerid, "repair_engine_generator_c");
	DeletePVarNew(playerid, "repair_engine_starter_c");
	DeletePVarNew(playerid, "repair_engine_belt_c");
	DeletePVarNew(playerid, "repair_engine_brake_c");
	DeletePVarNew(playerid, "repair_engine_candles_c");
	DeletePVarNew(playerid, "repair_engine_oil_c");

	DeletePVarNew(playerid, "box_mech_type_2");
	DeletePVarNew(playerid, "box_mech_type");

	DeletePVarNew(playerid, "repair_engine_final_price");	
	return true;
}

stock repair_engine_price(playerid, price)
{
	new 
		price_final = GetPVarIntNew(playerid, "repair_engine_final_price")+price;

	if(GetPlayerMoneyEx(playerid) < price_final)
	{
		new 
			type_mech = GetPVarIntNew(playerid, "box_mech_type_2"),
			box_mech = GetPVarIntNew(playerid, "box_mech_type");

		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);	
		SendErr(playerid,"У вас недостаточно денег для добавления новой услуги по ремонту!");

		return show_client_box_menu(playerid, type_mech, box_mech);
	}

	SetPVarIntNew(playerid, "repair_engine_final_price", GetPVarIntNew(playerid, "repair_engine_final_price")+price);

	return true;
}

stock clear_date_mechanic_box()
{
	mechanic_box[0][0][mechanic_active_id] = -1;
	mechanic_box[0][1][mechanic_active_id] = -1;
	mechanic_box[0][2][mechanic_active_id] = -1;
	mechanic_box[0][3][mechanic_active_id] = -1;

	mechanic_box[1][0][mechanic_active_id] = -1;
	mechanic_box[1][1][mechanic_active_id] = -1;
	mechanic_box[1][2][mechanic_active_id] = -1;
	mechanic_box[1][3][mechanic_active_id] = -1;
	mechanic_box[1][4][mechanic_active_id] = -1;


	mechanic_box[2][0][mechanic_active_id] = -1;
	mechanic_box[2][1][mechanic_active_id] = -1;
	mechanic_box[2][2][mechanic_active_id] = -1;
	mechanic_box[2][3][mechanic_active_id] = -1;
	return true;
}




stock pay_money_bank_mechanic(sum, mech_id)
{
	
	if(mechanic[mech_id][mechanic_base_finka_day] >= mechanic[mech_id][mechanic_base_finka_ogran])
		return true;

	mechanic[mech_id][mechanic_base_bank] += sum;
	mechanic[mech_id][mechanic_base_finka_day] += sum;

	save_mechanic_base();

	format(String256,sizeof(String256),"UPDATE `mechanic_stats` SET `stats_all_time` = `stats_all_time`+'%d' WHERE `mechanic_id` = '%d'" , sum, mech_id);
	sql_queryEx(zConn, String256, QUERY_THREADED);	
	format(String256,sizeof(String256),"UPDATE `mechanic_stats` SET `stats_mounth` = `stats_mounth`+'%d' WHERE `mechanic_id` = '%d'" , sum, mech_id);
	sql_queryEx(zConn, String256, QUERY_THREADED);	

    new 
    	lyear, lmonth, lday;
	getdate(lyear, lmonth, lday);

	new 
		lwday = weekday(lday, lmonth, lyear);

	switch(lwday)
	{
		case 0:
		{
			format(String256,sizeof(String256),"UPDATE `mechanic_stats` SET `stats_day_1` = `stats_day_1`+'%d' WHERE `mechanic_id` = '%d'" , sum, mech_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	

			format(String256,sizeof(String256),"UPDATE `mechanic_stats` SET `stats_today` = `stats_today`+'%d' WHERE `mechanic_id` = '%d'" , sum, mech_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	

		}
		case 1:
		{
			format(String256,sizeof(String256),"UPDATE `mechanic_stats` SET `stats_day_2` = `stats_day_2`+'%d' WHERE `mechanic_id` = '%d'" , sum, mech_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `mechanic_stats` SET `stats_today` = `stats_today`+'%d' WHERE `mechanic_id` = '%d'" , sum, mech_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}	

		case 2:
		{
			format(String256,sizeof(String256),"UPDATE `mechanic_stats` SET `stats_day_3` = `stats_day_3`+'%d' WHERE `mechanic_id` = '%d'" , sum, mech_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `mechanic_stats` SET `stats_today` = `stats_today`+'%d' WHERE `mechanic_id` = '%d'" , sum, mech_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}
		case 3:
		{
			format(String256,sizeof(String256),"UPDATE `mechanic_stats` SET `stats_day_4` = `stats_day_4`+'%d' WHERE `mechanic_id` = '%d'" , sum, mech_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `mechanic_stats` SET `stats_today` = `stats_today`+'%d' WHERE `mechanic_id` = '%d'" , sum, mech_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}

		case 4:
		{
			format(String256,sizeof(String256),"UPDATE `mechanic_stats` SET `stats_day_5` = `stats_day_5`+'%d' WHERE `mechanic_id` = '%d'" , sum, mech_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `mechanic_stats` SET `stats_today` = `stats_today`+'%d' WHERE `mechanic_id` = '%d'" , sum, mech_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}	
		case 5:
		{
			format(String256,sizeof(String256),"UPDATE `mechanic_stats` SET `stats_day_6` = `stats_day_6`+'%d' WHERE `mechanic_id` = '%d'" , sum, mech_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `mechanic_stats` SET `stats_today` = `stats_today`+'%d' WHERE `mechanic_id` = '%d'" , sum, mech_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}
		case 6:
		{
			format(String256,sizeof(String256),"UPDATE `mechanic_stats` SET `stats_day_7` = `stats_day_7`+'%d' WHERE `mechanic_id` = '%d'" , sum, mech_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `mechanic_stats` SET `stats_today` = `stats_today`+'%d' WHERE `mechanic_id` = '%d'" , sum, mech_id);
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}

	}	

	return true;
}

stock clear_stats_mechanic_newday()
{


    new 
    	lyear, lmonth, lday;
	getdate(lyear, lmonth, lday);

	new 
		lwday = weekday(lday, lmonth, lyear);

	switch(lwday)
	{
		case 0:
		{
			format(String256,sizeof(String256),"UPDATE `mechanic_stats` SET `stats_day_1` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	

			format(String256,sizeof(String256),"UPDATE `mechanic_stats` SET `stats_today` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	

		}
		case 1:
		{
			format(String256,sizeof(String256),"UPDATE `mechanic_stats` SET `stats_day_2` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `mechanic_stats` SET `stats_today` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}	

		case 2:
		{
			format(String256,sizeof(String256),"UPDATE `mechanic_stats` SET `stats_day_3` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `mechanic_stats` SET `stats_today` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}
		case 3:
		{
			format(String256,sizeof(String256),"UPDATE `mechanic_stats` SET `stats_day_4` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `mechanic_stats` SET `stats_today` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}

		case 4:
		{
			format(String256,sizeof(String256),"UPDATE `mechanic_stats` SET `stats_day_5` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `mechanic_stats` SET `stats_today` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}	
		case 5:
		{
			format(String256,sizeof(String256),"UPDATE `mechanic_stats` SET `stats_day_6` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `mechanic_stats` SET `stats_today` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}
		case 6:
		{
			format(String256,sizeof(String256),"UPDATE `mechanic_stats` SET `stats_day_7` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		
			format(String256,sizeof(String256),"UPDATE `mechanic_stats` SET `stats_today` = '0'");
			sql_queryEx(zConn, String256, QUERY_THREADED);	
		}

	}	
	return true;
}

stock clear_stats_mechanic_newmouth()
{
	for(new i; i < MAX_MECHANIC_BASE; i++)
	{
		format(String256,sizeof(String256),"UPDATE `mechanic_stats` SET `stats_mounth_back` = `stats_mounth` WHERE `mechanic_id` = '%d'" , i);
		sql_queryEx(zConn, String256, QUERY_THREADED);	
	}
	format(String256,sizeof(String256),"UPDATE `mechanic_stats` SET `stats_mounth` = '0'");
	sql_queryEx(zConn, String256, QUERY_THREADED);	

	return true;
}

CMD:asellmech(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

	if(sscanf(params, "d", params[0]))
	{
		SendInf(playerid, "Используйте: /asellmech "cWH"[ID СТО]");
		return true;
	}
	return sell_mechanic_admin(playerid, params[0]);
}

CMD:amechfin(playerid, params[])
{


    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

	if(sscanf(params, "dd", params[0], params[1]))
	{
		SendInf(playerid, "Используйте: /amechfin "cWH"[ID СТО] [Ограничение]");
		return true;
	}

	mechanic[params[0]][mechanic_base_finka_ogran] = params[1];
	save_mechanic_base();

    format(String144, sizeof(String144), "Вы успешно изменили максимальную прибыль для СТО №%d на "cGR"%d "cWH"рублей!", params[0], params[1]);
    SendSucc(playerid, String144);

	return true;
}

CMD:maccept(playerid)
{
	if(pData[playerid][pMech] == -1)
		return SendErr(playerid, "Доступно только работникам СТО");
	new 
		string[2048],
		count;

	strcat(string, ""cGREY"№. Никнейм\t"cGREY"Номер\t"cGREY"Расстояние\n");

	foreach(new i : Player) 
	{
		if(!GetPVarIntNew(i, "CallMech"))
			continue;

		if(GetPVarIntNew(i, "TypeMech")-1 != pData[playerid][pMech])
			continue;

		count++;
		format(string, sizeof(string), "%s"cBLUE"%d. "cWH"%s\t%d\t"cBLUE"%.1f метров\n", string, count, pData[i][pNickname], pData[i][pPhone], GetDistanceBetweenPlayers(i, playerid));
	}

	if(count == 0)
		return SendErr(playerid, "Нет активных вызовов");

	SPD(playerid, DIALOG_ACCEPT_MECH, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"СТО | "cWH"Список вызовов", string, !"Принять", !"Закрыть");
	return true;
}

stock Call_Mechanic(playerid, number)
{
	if(GetPlayerVirtualWorld(playerid) != 0)
		return SendErr(playerid, "Абонент вне зоны действия сети");

	if(GetPVarIntNew(playerid, "CallMech"))
		return SendErr(playerid, "У Вас уже есть активный вызов СТО, ожидайте принятия");

	SetPVarIntNew(playerid, "CallMech", 2);

	SPD(playerid, 0, 0, !""cBLUE"СТО | "cWH"Вызов отправлен", 
	!"\n"cWH"Вы позвонили в СТО!\n\
	Ожидайте принятия вызова!", "Принять", "");

	new 
		mechID = -1,
		message[144],
		count;

	if(number == mechanic[0][mechanic_base_phone])
		mechID = 0;
	else if(number == mechanic[1][mechanic_base_phone])
		mechID = 1;
	else if(number == mechanic[2][mechanic_base_phone])
		mechID = 2;

	SetPVarIntNew(playerid, "TypeMech", mechID+1);

	pTemp[playerid][timer_mechanic_call] = SetTimerEx("cancel_call_mechanic", 120000, false, "d", playerid);

	format(message, sizeof(message), "[СТО] %s[%i] вызывает механика. Чтобы принять, используйте "cBLUE"/maccept", pData[playerid][pNickname], playerid);
	foreach(new i : Player)
	{
		if(GetPlayerDistanceToPlayer(playerid,i) < 1000)
		{
			if(!IsPlayerConnected(i) || pData[i][pMech] != mechID) 
				continue;

			count++;
			SendClientMessage(i, COLOR_GREY, message);
		}
	}

	if(count == 0)
		send_mechanic_job(mechID, COLOR_GREY, message);

	return true;
}

stock show_dialog_mechanic_accept(playerid, dialogid, response, inputtext[])
{
	switch(dialogid)
	{
		case DIALOG_ACCEPT_MECH:
		{
			if(!response)
				return 1;

			new 
				id = GetPlayerID(inputtext[3]);

			if(!GetPVarIntNew(id, "CallMech"))
				return SendErr(playerid, "Данный вызов уже не актуален");

			if(GetPVarIntNew(id, "TypeMech")-1 != pData[playerid][pMech])
				return SendErr(playerid, "Данный вызов уже не актуален");

			DeletePVarNew(id, "CallMech");
			DeletePVarNew(id, "TypeMech");

			new 
				message[144];

			KillTimer(pTemp[id][timer_mechanic_call]);

			format(message, sizeof(message), "\n"cWH"Ваш вызов принят!\n\n\
			"cWH"Номер СТО: "cBLUE"№%i\n\
			"cWH"Сотрудник: "cBLUE"%s\n\
			"cWH"Пожалуйста, ожидайте приезда не покидая место.", pData[playerid][pMech]+1, pData[playerid][pNickname]);

			SPD(id, 0, 0, !""cBLUE"СТО | "cWH"Вызов принят", message, "Принять", "");

			format(message, sizeof(message), "[СТО] %s[%i] принял вызов от %s[%i]", pData[playerid][pNickname], playerid, pData[id][pNickname], id);
			send_mechanic_job(pData[playerid][pMech], COLOR_GREY, message);

			pay_money_bank_mechanic(200, pData[playerid][pMech]);
			GosMoney[0] += 50;

			new Float:X, Float:Y, Float:Z;

			GetPlayerPos(id, X, Y, Z);
			SetPlayerCheckpoint(playerid, X, Y, Z, 4.0);
			status_navigator_player(playerid, TEXTDRAW_SHOW);
		}
	}
	return true;
}

stock Cancel_Mech_Call(playerid)
{
	DeletePVarNew(playerid, "CallMech");
	DeletePVarNew(playerid, "TypeMech");

	KillTimer(pTemp[playerid][timer_mechanic_call]);

	SPD(playerid, 0, 0, !""cBLUE"СТО | "cWH"Отмена вызова", 
	!"\n"cWH"К сожалению, СТО не смогло принять вызов\n\
	Попробуйте вызвать другое!", "Принять", "");
	return 1;
}

callback:: cancel_call_mechanic(playerid)
{
	Cancel_Mech_Call(playerid);


	return true;
}

callback:: spawn_rent_car_mechanic(i, v, time)
{
	if(IsPlayerConnected(i))
	{	
		time--;

		if(!time)
		{
			end_mechanic_jobs(i);
			return true;
		}
		pTemp[i][rent_car_spawn_timer] = SetTimerEx("spawn_rent_car_mechanic", 1000, false, "iii", i, v, time);
	}	
	return true;
} 

stock respawn_mechanic_vehicle(playerid, mechanic_id)
{

	if(GetPlayerMoneyEx(playerid) < 2500)
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
		return SendErr(playerid, "У вас недостаточно денежных средств!");
	}

	switch(mechanic_id)
	{
		case MECHANIC_BASE_STATION_1:
		{

			new count;
			foreach(Vehicles, i)
		    {
		        if(!vehicle[i][cIsCreated]) 
		        	continue;
				if(IsVehicleOccupied(i) || !IsValidVehicle(i)) 
					continue;

				if(vehicle[i][cOwnTo] == VEHICLE_MECHANIC_1)
				{
				    DestroyVehicle(i);
					vehicle[i][cIsCreated] = false;
					count++;
					unrent_vehicle_respawn_mech(i);
				}
				
		    }
		    if(count == 0)
		    	return SendErr(playerid, "Отсутствуют машины для транспортировки!");

		    give_money(playerid, -2500, "Доставка грузовиков в СТО");
			format(String144, sizeof(String144), "[T] %s [%d] вызвал эвакуатор и привёз на базу %d эвакуаторов, потратив 2500 рублей!", pData[playerid][pNickname], playerid, count);
			send_trucker_job(mechanic_id, COLOR_GREY, String144);

		}
		case MECHANIC_BASE_STATION_2:
		{
			new count;
			
			foreach(Vehicles, i)
		    {
		        if(!vehicle[i][cIsCreated]) 
		        	continue;
				if(IsVehicleOccupied(i) || !IsValidVehicle(i)) 
					continue;

				if(vehicle[i][cOwnTo] == VEHICLE_MECHANIC_2)
				{
				    DestroyVehicle(i);
					vehicle[i][cIsCreated] = false;
					count++;
					unrent_vehicle_respawn_mech(i);
				}
				
		    }
		    if(count == 0)
		    	return SendErr(playerid, "Отсутствуют машины для транспортировки!");

		    give_money(playerid, -2500, "Доставка грузовиков в СТО");
			format(String144, sizeof(String144), "[T] %s [%d] вызвал эвакуатор и привёз на базу %d эвакуаторов, потратив 2500 рублей!", pData[playerid][pNickname], playerid, count);
			send_trucker_job(mechanic_id, COLOR_GREY, String144);
		}
		case MECHANIC_BASE_STATION_3:
		{
			new count;
			foreach(Vehicles, i)
		    {
		        if(!vehicle[i][cIsCreated]) 
		        	continue;
				if(IsVehicleOccupied(i) || !IsValidVehicle(i)) 
					continue;

				if(vehicle[i][cOwnTo] == VEHICLE_MECHANIC_3)
				{
				    DestroyVehicle(i);
					vehicle[i][cIsCreated] = false;
					count++;
					unrent_vehicle_respawn_mech(i);
				}
				
		    }
		    if(count == 0)
		    	return SendErr(playerid, "Отсутствуют машины для транспортировки!");

		    give_money(playerid, -2500, "Доставка грузовиков в СТО");
			format(String144, sizeof(String144), "[T] %s [%d] вызвал эвакуатор и привёз на базу %d эвакуаторов, потратив 2500 рублей!", pData[playerid][pNickname], playerid, count);
			send_trucker_job(mechanic_id, COLOR_GREY, String144);
		}
	}


	return true;
}


stock unrent_vehicle_respawn_mech(carid)
{

	foreach(new i: logged_players)
	{
		new 
			v = pTemp[i][rent_car];

		if(v == carid)
		{
			end_mechanic_jobs(i);
		}
	}
	return true;

}

/*
strcat(String1024,"{"#cINFO"}-Механик\n");
strcat(String1024,"{"#cYELLOW"}/tow - {"#cWHITE"}Начать буксировку.\n");
strcat(String1024,"{"#cYELLOW"}/untow - {"#cWHITE"}Закончить буксировку.\n");
strcat(String1024,"{"#cYELLOW"}/repair - {"#cWHITE"}Починить автомобиль.\n");
strcat(String1024,"{"#cYELLOW"}/refill - {"#cWHITE"}Заправить автомобиль.\n");
strcat(String1024,"{"#cYELLOW"}/mechlist - {"#cWHITE"}Cписок вызывающих эвакуатор.\n");

*/
/*

	DIALOG_BUY_MECHANIC,
	DIALOG_CHANGE_MECHANIC,
	DIALOG_CHANGE_MECHANIC_BANK,
	DIALOG_MECHANIC_INPUT_MONEY,
	DIALOG_MECHANIC_PUT_MONEY,
	DIALOG_CHANGE_TARIF_MECHANIC,
	DIALOG_CHG_TARIF_MECH_1,
	DIALOG_CHG_TARIF_MECH_2,
	DIALOG_CHG_TARIF_MECH_3,
	DIALOG_CHG_TARIF_MECH_4,
	DIALOG_CHG_TARIF_MECH_5,
	DIALOG_CHG_TARIF_MECH_6,
	DIALOG_CHG_TARIF_MECH_7,
	DIALOG_CHG_TARIF_MECH_8,
	DIALOG_CHG_TARIF_MECH_9,
	DIALOG_CHG_TARIF_MECH_10,
	DIALOG_CHANGE_PERCENT,
	DIALOG_CHANGE_MECH_PHONE,
	DIALOG_CHANGE_MECH_NAME,

*/