static const mounth_buisnes_stats[][] =
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


static const get_buisnes_autosalon_n[][] =
{	
	"Отсутствует",
    "АвтоХаус Премиум",
    "АрзамасКарс",
    "Авторынок",
    "АвтоДвор"
};


callback:: load_buisnes_all()
{
	new Result:buisnes_player = sql_queryEx(zConn, "SELECT * FROM `buisnes` ORDER BY `buisnes_id`", QUERY_CACHED);

	new all_buisnes_player = sql_num_rows(buisnes_player);
 
	new time = GetTickCount();
 
 
 	for(new i; i < all_buisnes_player; i++)
	{
		buisness[i][buisnes_id]  = sql_get_field_assoc_int_ex(buisnes_player, i, "buisnes_id"); 


		buisness[i][buisnes_owned]  = sql_get_field_assoc_int_ex(buisnes_player, i, "buisnes_owner_id"); 

		buisness[i][buisnes_name]  = sql_get_field_assoc_int_ex(buisnes_player, i, "buisnes_name"); 

		buisness[i][buisnes_type]  = sql_get_field_assoc_int_ex(buisnes_player, i, "buisnes_type"); 
		buisness[i][buisnes_price]  = sql_get_field_assoc_int_ex(buisnes_player, i, "buisnes_price"); 
		buisness[i][buisnes_lock]  = sql_get_field_assoc_int_ex(buisnes_player, i, "buisnes_lock"); 
		buisness[i][buisnes_takings]  = sql_get_field_assoc_int_ex(buisnes_player, i, "buisnes_nalog"); 	
		buisness[i][buisnes_days]  = sql_get_field_assoc_int_ex(buisnes_player, i, "buisnes_day"); 

		buisness[i][buisnes_bank]  = sql_get_field_assoc_int_ex(buisnes_player, i, "buisnes_bank"); 

		buisness[i][buisnes_enterprice]  = sql_get_field_assoc_int_ex(buisnes_player, i, "buisnes_enterprice"); 

  		buisness[i][buisnes_enter_x] = sql_get_field_assoc_float_ex(buisnes_player, i, "buisnes_enter_x");
  		buisness[i][buisnes_enter_y] = sql_get_field_assoc_float_ex(buisnes_player, i, "buisnes_enter_y");
  		buisness[i][buisnes_enter_z] = sql_get_field_assoc_float_ex(buisnes_player, i, "buisnes_enter_z");

  		buisness[i][buisnes_exit_x] = sql_get_field_assoc_float_ex(buisnes_player, i, "buisnes_exit_x");
  		buisness[i][buisnes_exit_y] = sql_get_field_assoc_float_ex(buisnes_player, i, "buisnes_exit_y");
  		buisness[i][buisnes_exit_z] = sql_get_field_assoc_float_ex(buisnes_player, i, "buisnes_exit_z");

		buisness[i][buisnes_upgrade_1]  = sql_get_field_assoc_int_ex(buisnes_player, i, "buisnes_upgrade_1"); 
		buisness[i][buisnes_upgrade_2]  = sql_get_field_assoc_int_ex(buisnes_player, i, "buisnes_upgrade_2"); 
		buisness[i][buisnes_upgrade_3]  = sql_get_field_assoc_int_ex(buisnes_player, i, "buisnes_upgrade_3"); 
		buisness[i][buisnes_upgrade_4]  = sql_get_field_assoc_int_ex(buisnes_player, i, "buisnes_upgrade_4"); 	
		buisness[i][buisnes_upgrade_5]  = sql_get_field_assoc_int_ex(buisnes_player, i, "buisnes_upgrade_5"); 
		buisness[i][buisnes_upgrade_6]  = sql_get_field_assoc_int_ex(buisnes_player, i, "buisnes_upgrade_6"); 

		buisness[i][buisnes_finka_ogran]  = sql_get_field_assoc_int_ex(buisnes_player, i, "buisnes_finka_ogran"); 
		buisness[i][buisnes_finka_day]  = sql_get_field_assoc_int_ex(buisnes_player, i, "buisnes_finka_day"); 

		buisness[i][buisnes_count_prod] = sql_get_field_assoc_int_ex(buisnes_player, i, "buisnes_count_prod"); 

		buisness[i][buisnes_status_sell] = sql_get_field_assoc_int_ex(buisnes_player, i, "buisnes_status_sell"); 
		buisness[i][buisnes_sell_day_payday] = sql_get_field_assoc_int_ex(buisnes_player, i, "buisnes_sell_day_payday"); 

		buisness[i][buisnes_price_day_rent] = sql_get_field_assoc_int_ex(buisnes_player, i, "buisnes_price_day_rent"); 

		buisness[i][buisnes_mafia] = sql_get_field_assoc_int_ex(buisnes_player, i, "buisnes_mafia"); 
 

		create_dynamic_area(buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], -1, i, B_ENTER);
		
		buisness[i][buisnes_pickup] = CreateDynamicPickup(13702, 23, buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], -1, -1, -1, STREAM_DISTANCE_DYNAMIC_PICKUP);

		if(buisness[i][buisnes_type] == BUISNES_PARKING)
		{
			new
				b_owner[24];

			if(buisness[i][buisnes_owned] != -1)
			{
				GetPlayerNameByID(buisness[i][buisnes_owned], buisness[i][buisnes_owner]);
				format(b_owner, 24, buisness[i][buisnes_owner]);
			}
			else
			{
				format(b_owner, 24, "Государство");	
			}

			format(String320, sizeof(String320), "\
				"cWH"Паркинг "cBLUE"№%d\n\n\
				"cBLUE"Владелец: \
				"cWH"%s\n\
				"cBLUE"Крышует: \
				"cWH"%s\n\
				"cBLUE"[ALT]", i+1, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));

			buisness[i][buisnes_pickup_3d] = CreateDynamic3DTextLabel(String320, -1, buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 5.0);
			CreateDynamicMapIcon(buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 55, COLOR_WHITE, 0, -1, -1, 100.0);
		}

		if(buisness[i][buisnes_type] == BUISNES_RIELTOR_AGENCY)
		{
			CreateDynamicPickup(13702, 23, 1101.0665,308.2863,1205.0166, -1, -1, -1, 10.0);

			CreateDynamic3DTextLabel(""cWH"Выход из Риелторского Агенства\n"cBLUE"[ALT]",-1, \
			1101.0665,308.2863,1205.0166, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 20, -1);	

			new
				buisnes_names[24],
				b_owner[24];

			format(buisnes_names, 24, "%s", get_buisnes_realtor(i));

			if(buisness[i][buisnes_owned] != -1)
			{
				GetPlayerNameByID(buisness[i][buisnes_owned], buisness[i][buisnes_owner]);
				format(b_owner, 24, buisness[i][buisnes_owner]);
			}
			else
			{
				format(b_owner, 24, "Государство");	
			}

			format(String320, sizeof(String320), "\
				"cWH"Риелторское Агенство "cBLUE"№%d\n\n\
				"cBLUE"Название: \
				"cWH"%s\n\
				"cBLUE"Владелец: \
				"cWH"%s\n\
				"cBLUE"Крышует: \
				"cWH"%s\n\
				"cBLUE"Цена входа: \
				"cWH"%d рублей\n\n\
				"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]), buisness[i][buisnes_enterprice]);

			buisness[i][buisnes_pickup_3d] = CreateDynamic3DTextLabel(String320, -1, buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 5.0);


			create_dynamic_area(1101.0665,308.2863,1205.0166, i, i, B_EXIT);

			if(buisness[i][buisnes_owned] == -1)
			{
				buisness[i][buisnes_mapicon] = CreateDynamicMapIcon(buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 42, COLOR_WHITE, 0, -1, -1, 100.0);
			}
			else
			{
				buisness[i][buisnes_mapicon] = CreateDynamicMapIcon(buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 42, COLOR_RED, 0, -1, -1, 100.0);
			}

		}

		if(buisness[i][buisnes_type] == BUISNES_CLOTHES)
		{
			CreateDynamicPickup(13702, 23, MAGAZING_CLOTHES_1_EXIT, -1, -1, -1, 10.0);

			CreateDynamic3DTextLabel(""cWH"Выход из магазина\n"cBLUE"[ALT]",-1, \
			MAGAZING_CLOTHES_1_EXIT, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 20, -1);	


			new
				buisnes_names[24],
				b_owner[24];

			format(buisnes_names, 24, "%s", get_buisnes_clothes_n(i));

			if(buisness[i][buisnes_owned] != -1)
			{
				GetPlayerNameByID(buisness[i][buisnes_owned], buisness[i][buisnes_owner]);
				format(b_owner, 24, buisness[i][buisnes_owner]);
			}
			else
			{
				format(b_owner, 24, "Государство");	
			}

			format(String320, sizeof(String320), "\
				"cWH"Магазин Одежды "cBLUE"№%d\n\n\
				"cBLUE"Название: \
				"cWH"%s\n\
				"cBLUE"Владелец: \
				"cWH"%s\n\
				"cBLUE"Крышует: \
				"cWH"%s\n\n\
				"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));

			buisness[i][buisnes_pickup_3d] = CreateDynamic3DTextLabel(String320, -1, buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 5.0);


			create_dynamic_area(MAGAZING_CLOTHES_1_EXIT, i, i, B_EXIT);

			if(buisness[i][buisnes_owned] == -1)
			{
				buisness[i][buisnes_mapicon] = CreateDynamicMapIcon(buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 45, COLOR_WHITE, 0, -1, -1, 100.0);
			}
			else
			{
				buisness[i][buisnes_mapicon] = CreateDynamicMapIcon(buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 45, COLOR_RED, 0, -1, -1, 100.0);
			}
		}

		if(buisness[i][buisnes_type] == BUISNES_ACCESSORIES)
		{
			CreateDynamicPickup(13702, 23, MAGAZIN_AKS_1_EXIT, -1, -1, -1, 10.0);

			CreateDynamic3DTextLabel(""cWH"Выход из магазина\n"cBLUE"[ALT]",-1, \
			MAGAZIN_AKS_1_EXIT, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 20, -1);	


			new
				buisnes_names[24],
				b_owner[24];

			format(buisnes_names, 24, "%s", get_buisnes_aks_n(i));

			if(buisness[i][buisnes_owned] != -1)
			{
				GetPlayerNameByID(buisness[i][buisnes_owned], buisness[i][buisnes_owner]);
				format(b_owner, 24, buisness[i][buisnes_owner]);
			}
			else
			{
				format(b_owner, 24, "Государство");	
			}

			format(String320, sizeof(String320), "\
				"cWH"Магазин Аксессуаров "cBLUE"№%d\n\n\
				"cBLUE"Название: \
				"cWH"%s\n\
				"cBLUE"Владелец: \
				"cWH"%s\n\
				"cBLUE"Крышует: \
				"cWH"%s\n\n\
				"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));

			buisness[i][buisnes_pickup_3d] = CreateDynamic3DTextLabel(String320, -1, buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 5.0);


			create_dynamic_area(MAGAZIN_AKS_1_EXIT, i, i, B_EXIT);

			if(buisness[i][buisnes_owned] == -1)
			{
				buisness[i][buisnes_mapicon] = CreateDynamicMapIcon(buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 39, COLOR_WHITE, 0, -1, -1, 100.0);
			}
			else
			{
				buisness[i][buisnes_mapicon] = CreateDynamicMapIcon(buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 39, COLOR_RED, 0, -1, -1, 100.0);
			}
		}
		

		if(buisness[i][buisnes_type] == BUISNES_AUTOSALON_1)
		{
			CreateDynamicPickup(13702, 23, MAGAZINE_CAR_1_EXIT, -1, -1, -1, 10.0);

			CreateDynamic3DTextLabel(""cWH"Выход из автосалона\n"cBLUE"[ALT]",-1, \
			MAGAZINE_CAR_1_EXIT, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	


			new
				buisnes_names[24],
				b_owner[24];

			format(buisnes_names, 24, "%s", get_buisnes_autosalon_n[buisness[i][buisnes_name]]);

			if(buisness[i][buisnes_owned] != -1)
			{
				GetPlayerNameByID(buisness[i][buisnes_owned], buisness[i][buisnes_owner]);
				format(b_owner, 24, buisness[i][buisnes_owner]);
			}
			else
			{
				format(b_owner, 24, "Государство");	
			}

			format(String320, sizeof(String320), "\
				"cWH"Автосалон "cBLUE"№%d\n\n\
				"cBLUE"Название: \
				"cWH"%s\n\
				"cBLUE"Владелец: \
				"cWH"%s\n\
				"cBLUE"Крышует: \
				"cWH"%s\n\n\
				"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));

			buisness[i][buisnes_pickup_3d] = CreateDynamic3DTextLabel(String320, -1, buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 5.0);


			autosalon_count_rent_car[0] = MAX_RENT_CAR_AUTOSALON_1;

			create_dynamic_area(MAGAZINE_CAR_1_EXIT, 10, i, B_EXIT);

			if(buisness[i][buisnes_owned] == -1)
			{
				buisness[i][buisnes_mapicon] = CreateDynamicMapIcon(buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 55, COLOR_WHITE, 0, -1, -1, 100.0);
			}
			else
			{
				buisness[i][buisnes_mapicon] = CreateDynamicMapIcon(buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 55, COLOR_RED, 0, -1, -1, 100.0);
			}
		}

		if(buisness[i][buisnes_type] == BUISNES_AUTOSALON_2)
		{
			CreateDynamicPickup(13702, 23, MAGAZINE_CAR_2_EXIT, -1, -1, -1, 10.0);

			CreateDynamic3DTextLabel(""cWH"Выход из автосалона\n"cBLUE"[ALT]",-1, \
			MAGAZINE_CAR_2_EXIT, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	


			new
				buisnes_names[24],
				b_owner[24];

			format(buisnes_names, 24, "%s", get_buisnes_autosalon_n[buisness[i][buisnes_name]]);

			if(buisness[i][buisnes_owned] != -1)
			{
				GetPlayerNameByID(buisness[i][buisnes_owned], buisness[i][buisnes_owner]);
				format(b_owner, 24, buisness[i][buisnes_owner]);
			}
			else
			{
				format(b_owner, 24, "Государство");	
			}

			format(String320, sizeof(String320), "\
				"cWH"Автосалон "cBLUE"№%d\n\n\
				"cBLUE"Название: \
				"cWH"%s\n\
				"cBLUE"Владелец: \
				"cWH"%s\n\
				"cBLUE"Крышует: \
				"cWH"%s\n\n\
				"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));

			buisness[i][buisnes_pickup_3d] = CreateDynamic3DTextLabel(String320, -1, buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 5.0);

			autosalon_count_rent_car[1] = MAX_RENT_CAR_AUTOSALON_2;

			create_dynamic_area(MAGAZINE_CAR_2_EXIT, 10, i, B_EXIT);

			if(buisness[i][buisnes_owned] == -1)
			{
				buisness[i][buisnes_mapicon] = CreateDynamicMapIcon(buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 55, COLOR_WHITE, 0, -1, -1, 100.0);
			}
			else
			{
				buisness[i][buisnes_mapicon] = CreateDynamicMapIcon(buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 55, COLOR_RED, 0, -1, -1, 100.0);
			}
		}

		if(buisness[i][buisnes_type] == BUISNES_AUTOSALON_3)
		{
			CreateDynamicPickup(13702, 23, MAGAZINE_CAR_3_EXIT, -1, -1, -1, 10.0);

			CreateDynamic3DTextLabel(""cWH"Выход из автосалона\n"cBLUE"[ALT]",-1, \
			MAGAZINE_CAR_3_EXIT, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	


			new
				buisnes_names[24],
				b_owner[24];

			format(buisnes_names, 24, "%s", get_buisnes_autosalon_n[buisness[i][buisnes_name]]);

			if(buisness[i][buisnes_owned] != -1)
			{
				GetPlayerNameByID(buisness[i][buisnes_owned], buisness[i][buisnes_owner]);
				format(b_owner, 24, buisness[i][buisnes_owner]);
			}
			else
			{
				format(b_owner, 24, "Государство");	
			}

			format(String320, sizeof(String320), "\
				"cWH"Автосалон "cBLUE"№%d\n\n\
				"cBLUE"Название: \
				"cWH"%s\n\
				"cBLUE"Владелец: \
				"cWH"%s\n\
				"cBLUE"Крышует: \
				"cWH"%s\n\n\
				"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));

			buisness[i][buisnes_pickup_3d] = CreateDynamic3DTextLabel(String320, -1, buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 5.0);

			autosalon_count_rent_car[2] = MAX_RENT_CAR_AUTOSALON_3;

			create_dynamic_area(MAGAZINE_CAR_3_EXIT, 10, i, B_EXIT);

			if(buisness[i][buisnes_owned] == -1)
			{
				buisness[i][buisnes_mapicon] = CreateDynamicMapIcon(buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 55, COLOR_WHITE, 0, -1, -1, 100.0);
			}
			else
			{
				buisness[i][buisnes_mapicon] = CreateDynamicMapIcon(buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 55, COLOR_RED, 0, -1, -1, 100.0);
			}
		}


		if(buisness[i][buisnes_type] == BUISNES_PRODUCTION)
		{
			buisness[i][buisnes_pickup] = CreateDynamicPickup(13702, 23, BUISNES_PRODUCTION_EXIT, -1, -1, -1, 10.0);

			CreateDynamic3DTextLabel(""cWH"Выход из магазина\n"cBLUE"[ALT]",-1, \
			BUISNES_PRODUCTION_EXIT, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	

			new
				buisnes_names[24],
				b_owner[24];

			format(buisnes_names, 24, "%s", get_buisnes_univermag_n(i));

			if(buisness[i][buisnes_owned] != -1)
			{
				GetPlayerNameByID(buisness[i][buisnes_owned], buisness[i][buisnes_owner]);
				format(b_owner, 24, buisness[i][buisnes_owner]);
			}
			else
			{
				format(b_owner, 24, "Государство");	
			}

			format(String320, sizeof(String320), "\
				"cWH"Продуктовый Магазин "cBLUE"№%d\n\n\
				"cBLUE"Название: \
				"cWH"%s\n\
				"cBLUE"Владелец: \
				"cWH"%s\n\
				"cBLUE"Крышует: \
				"cWH"%s\n\n\
				"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));

			buisness[i][buisnes_pickup_3d] = CreateDynamic3DTextLabel(String320, -1, buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 5.0);


			create_dynamic_area(BUISNES_PRODUCTION_EXIT, i, i, B_EXIT);

			if(buisness[i][buisnes_owned] == -1)
			{
				buisness[i][buisnes_mapicon] = CreateDynamicMapIcon(buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 52, COLOR_WHITE, 0, -1, -1, 100.0);
			}
			else
			{
				buisness[i][buisnes_mapicon] = CreateDynamicMapIcon(buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 52, COLOR_RED, 0, -1, -1, 100.0);
			}
		}

		if(buisness[i][buisnes_type] == BUISNES_BAR)
		{

			new
				buisnes_names[24],
				b_owner[24];

			format(buisnes_names, 24, "%s", get_buisnes_bar_n(i));

			if(buisness[i][buisnes_owned] != -1)
			{
				GetPlayerNameByID(buisness[i][buisnes_owned], buisness[i][buisnes_owner]);
				format(b_owner, 24, buisness[i][buisnes_owner]);
			}
			else
			{
				format(b_owner, 24, "Государство");	
			}

			format(String320, sizeof(String320), "\
				"cWH"Бар "cBLUE"№%d\n\n\
				"cBLUE"Название: \
				"cWH"%s\n\
				"cBLUE"Владелец: \
				"cWH"%s\n\
				"cBLUE"Крышует: \
				"cWH"%s\n\n\
				"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));

			buisness[i][buisnes_pickup_3d] = CreateDynamic3DTextLabel(String320, -1, buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 5.0);


			if(buisness[i][buisnes_owned] == -1)
			{
				buisness[i][buisnes_mapicon] = CreateDynamicMapIcon(buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 49, COLOR_WHITE, 0, -1, -1, 100.0);
			}
			else
			{
				buisness[i][buisnes_mapicon] = CreateDynamicMapIcon(buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 49, COLOR_RED, 0, -1, -1, 100.0);
			}
		}

		if(buisness[i][buisnes_type] == BUISNES_AMMO_1)
		{

			CreateDynamicPickup(13702, 23, 9.9908,14.8014,1601.7458, -1, -1, -1, 10.0);

			CreateDynamic3DTextLabel(""cWH"Выход из магазина\n"cBLUE"[ALT]",-1, \
			9.9908,14.8014,1601.7458, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	

			new
				buisnes_names[24],
				b_owner[24];

			format(buisnes_names, 24, "%s", get_buisnes_ammo_n(i));

			if(buisness[i][buisnes_owned] != -1)
			{
				GetPlayerNameByID(buisness[i][buisnes_owned], buisness[i][buisnes_owner]);
				format(b_owner, 24, buisness[i][buisnes_owner]);
			}
			else
			{
				format(b_owner, 24, "Государство");	
			}

			format(String320, sizeof(String320), "\
				"cWH"Магазин Оружия "cBLUE"№%d\n\n\
				"cBLUE"Название: \
				"cWH"%s\n\
				"cBLUE"Владелец: \
				"cWH"%s\n\
				"cBLUE"Крышует: \
				"cWH"%s\n\n\
				"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));



			buisness[i][buisnes_pickup_3d] = CreateDynamic3DTextLabel(String320, -1, buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 5.0);



			create_dynamic_area(9.9908,14.8014,1601.7458, i, i, B_EXIT);

			if(buisness[i][buisnes_owned] == -1)
			{
				buisness[i][buisnes_mapicon] = CreateDynamicMapIcon(buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 6, COLOR_WHITE, 0, -1, -1, 100.0);
			}
			else
			{
				buisness[i][buisnes_mapicon] = CreateDynamicMapIcon(buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 6, COLOR_RED, 0, -1, -1, 100.0);
			}
		}
		if(buisness[i][buisnes_type] == BUISNES_AMMO_2)
		{
			new
				buisnes_names[24],
				b_owner[24];

			format(buisnes_names, 24, "%s", get_buisnes_ammo_n(i));

			if(buisness[i][buisnes_owned] != -1)
			{
				GetPlayerNameByID(buisness[i][buisnes_owned], buisness[i][buisnes_owner]);
				format(b_owner, 24, buisness[i][buisnes_owner]);
			}
			else
			{
				format(b_owner, 24, "Государство");	
			}

			format(String320, sizeof(String320), "\
				"cWH"Магазин Оружия "cBLUE"№%d\n\n\
				"cBLUE"Название: \
				"cWH"%s\n\
				"cBLUE"Владелец: \
				"cWH"%s\n\
				"cBLUE"Крышует: \
				"cWH"%s\n\n\
				"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));

			buisness[i][buisnes_pickup_3d] = CreateDynamic3DTextLabel(String320, -1, buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 5.0);

			create_dynamic_area(9.9908,14.8014,1601.7458, i, i, B_EXIT);

			if(buisness[i][buisnes_owned] == -1)
			{
				buisness[i][buisnes_mapicon] = CreateDynamicMapIcon(buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 6, COLOR_WHITE, 0, -1, -1, 100.0);
			}
			else
			{
				buisness[i][buisnes_mapicon] = CreateDynamicMapIcon(buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 6, COLOR_RED, 0, -1, -1, 100.0);
			}
		}
		if(buisness[i][buisnes_type] == BUISNES_RESTORAN)
		{

			buisness[i][buisnes_pickup] = CreateDynamicPickup(13702, 23, POSITION_RESTORAN, -1, -1, -1, 10.0);

			new
				buisnes_names[24],
				b_owner[24];

			format(buisnes_names, 24, "%s", get_buisnes_restoran_n(i));

			if(buisness[i][buisnes_owned] != -1)
			{
				GetPlayerNameByID(buisness[i][buisnes_owned], buisness[i][buisnes_owner]);
				format(b_owner, 24, buisness[i][buisnes_owner]);
			}
			else
			{
				format(b_owner, 24, "Государство");	
			}

			format(String320, sizeof(String320), "\
				"cWH"Ресторан "cBLUE"№%d\n\n\
				"cBLUE"Название: \
				"cWH"%s\n\
				"cBLUE"Владелец: \
				"cWH"%s\n\
				"cBLUE"Крышует: \
				"cWH"%s\n\n\
				"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));

			buisness[i][buisnes_pickup_3d] = CreateDynamic3DTextLabel(String320, -1, buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 5.0);



			if(buisness[i][buisnes_owned] == -1)
			{
				buisness[i][buisnes_mapicon] = CreateDynamicMapIcon(buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 50, COLOR_WHITE, 0, -1, -1, 100.0);
			}
			else
			{
				buisness[i][buisnes_mapicon] = CreateDynamicMapIcon(buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 50, COLOR_RED, 0, -1, -1, 100.0);
			}
			create_dynamic_area(POSITION_RESTORAN, i, i, B_EXIT);
		}

		if(buisness[i][buisnes_type] == BUISNES_FASTFOOD)
		{

			buisness[i][buisnes_pickup] = CreateDynamicPickup(13702, 23, POSITION_FASTFOOD, -1, -1, -1, 10.0);

			new
				buisnes_names[24],
				b_owner[24];

			format(buisnes_names, 24, "%s", get_buisnes_fastfood_n(i));

			if(buisness[i][buisnes_owned] != -1)
			{
				GetPlayerNameByID(buisness[i][buisnes_owned], buisness[i][buisnes_owner]);
				format(b_owner, 24, buisness[i][buisnes_owner]);
			}
			else
			{
				format(b_owner, 24, "Государство");	
			}

			format(String320, sizeof(String320), "\
				"cWH"Закусочная "cBLUE"№%d\n\n\
				"cBLUE"Название: \
				"cWH"%s\n\
				"cBLUE"Владелец: \
				"cWH"%s\n\
				"cBLUE"Крышует: \
				"cWH"%s\n\n\
				"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));

			buisness[i][buisnes_pickup_3d] = CreateDynamic3DTextLabel(String320, -1, buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 5.0);


			if(buisness[i][buisnes_owned] == -1)
			{
				buisness[i][buisnes_mapicon] = CreateDynamicMapIcon(buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 10, COLOR_WHITE, 0, -1, -1, 100.0);
			}
			else
			{
				buisness[i][buisnes_mapicon] = CreateDynamicMapIcon(buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 10, COLOR_RED, 0, -1, -1, 100.0);
			}

			create_dynamic_area(POSITION_FASTFOOD, i, i, B_EXIT);
		}

		if(buisness[i][buisnes_type] == BUISNES_CLUB)
		{
			new
				buisnes_names[24],
				b_owner[24];

			buisness[i][buisnes_pickup] = CreateDynamicPickup(13702, 23, 141.3090,-1172.5457,1200.6801, -1, -1, -1, 10.0);


			format(buisnes_names, 24, "%s", get_buisnes_club_n(i));

			if(buisness[i][buisnes_owned] != -1)
			{
				GetPlayerNameByID(buisness[i][buisnes_owned], buisness[i][buisnes_owner]);
				format(b_owner, 24, buisness[i][buisnes_owner]);
			}
			else
			{
				format(b_owner, 24, "Государство");	
			}

			format(String320, sizeof(String320), "\
				"cWH"Ночной клуб "cBLUE"№%d\n\n\
				"cBLUE"Название: \
				"cWH"%s\n\
				"cBLUE"Владелец: \
				"cWH"%s\n\
				"cBLUE"Крышует: \
				"cWH"%s\n\n\
				"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia])); 

			buisness[i][buisnes_pickup_3d] = CreateDynamic3DTextLabel(String320, -1, buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 5.0);

			arClubBar = create_circle_pickup(158.9573,-1152.2617,1201.7816, TRIGGER_LBLUE);	
			create_dynamic_area(141.3090,-1172.5457,1200.6801, i, i, B_EXIT);

			if(buisness[i][buisnes_owned] == -1)
			{
				buisness[i][buisnes_mapicon] = CreateDynamicMapIcon(buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 48, COLOR_WHITE, 0, -1, -1, 100.0);
			}
			else
			{
				buisness[i][buisnes_mapicon] = CreateDynamicMapIcon(buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z], 48, COLOR_RED, 0, -1, -1, 100.0);
			}
		}

  		all_buisness++;
	}

	sql_free_result(buisnes_player);
 	create_info_car_autosalon();
 	create_other_element_biz();

	printf("[Бизнесы]: <%i из %i>. Времени затрачено: <%d мс>" ,all_buisnes_player, all_buisness, GetTickCount()-  time);

	return true;
}

callback:: save_biz(h)
{
	new time = GetTickCount();

    format(String2048, sizeof(String2048), "UPDATE `buisnes` SET \
    	buisnes_owner_id = '%d',\
    	buisnes_type = '%d',\
    	buisnes_name = '%d',\
    	buisnes_price = '%d',\
    	buisnes_bank = '%d',\
    	buisnes_lock = '%d',\
    	buisnes_day = '%d',\
    	buisnes_nalog = '%d',\
    	buisnes_enter_x = '%f',\
    	buisnes_enter_y = '%f',\
    	buisnes_enter_z = '%f',\
    	buisnes_exit_x = '%f',\
    	buisnes_exit_y = '%f',\
    	buisnes_exit_z = '%f',\
    	buisnes_enterprice = '%d',\
    	buisnes_upgrade_1 = '%d',\
    	buisnes_upgrade_2 = '%d',\
    	buisnes_upgrade_3 = '%d',\
    	buisnes_upgrade_4 = '%d',\
    	buisnes_upgrade_5 = '%d',\
    	buisnes_upgrade_6 = '%d',\
		buisnes_finka_ogran = '%d',\
		buisnes_finka_day = '%d',\
		buisnes_count_prod = '%d',\
		buisnes_status_sell = '%d',\
		buisnes_sell_day_payday = '%d',\
		buisnes_mafia = '%d',\
		buisnes_price_day_rent = '%d'\
    	WHERE buisnes_id = '%d'",
    	buisness[h][buisnes_owned],
    	buisness[h][buisnes_type],
    	buisness[h][buisnes_name],
    	buisness[h][buisnes_price],
    	buisness[h][buisnes_bank],
    	buisness[h][buisnes_lock],
    	buisness[h][buisnes_days],
    	buisness[h][buisnes_takings],
    	buisness[h][buisnes_enter_x],
    	buisness[h][buisnes_enter_y],
    	buisness[h][buisnes_enter_z],
		buisness[h][buisnes_exit_x],
		buisness[h][buisnes_exit_y],
		buisness[h][buisnes_exit_z], 

    	buisness[h][buisnes_enterprice],
    	buisness[h][buisnes_upgrade_1],
    	buisness[h][buisnes_upgrade_2],
    	buisness[h][buisnes_upgrade_3],
    	buisness[h][buisnes_upgrade_4],
    	buisness[h][buisnes_upgrade_5],    	
    	buisness[h][buisnes_upgrade_6],
		buisness[h][buisnes_finka_ogran],
		buisness[h][buisnes_finka_day],
		buisness[h][buisnes_count_prod],

		buisness[h][buisnes_status_sell],
		buisness[h][buisnes_sell_day_payday],
		buisness[h][buisnes_mafia],
		buisness[h][buisnes_price_day_rent],
    	buisness[h][buisnes_id]);

    sql_queryEx(zConn, String2048, QUERY_THREADED);	

	if(debug_mode)
	{
		printf("[save_biz]: Времени затрачено: <%d мс>" , GetTickCount() - time);
	}

    return true;
}

stock create_info_car_autosalon()
{
 
	autosalon_area_info_1[0] = create_circle_pickup(-206.4267,-11.8036,1201.9778, TRIGGER_LBLUE);	
	autosalon_area_info_1[1] = create_circle_pickup(-223.8152,-11.5610,1201.9778, TRIGGER_LBLUE);	
	autosalon_area_info_1[2] = create_circle_pickup(-192.5828,9.1882,1201.9934, TRIGGER_LBLUE);	
	autosalon_area_info_1[3] = create_circle_pickup(-186.0139,9.1323,1201.9934, TRIGGER_LBLUE);	



	autosalon_area_info_2[0] = create_circle_pickup(-27.4821,367.7938,1601.7495, TRIGGER_LBLUE);	
	autosalon_area_info_2[1] = create_circle_pickup(-27.9091,362.5171,1601.7495, TRIGGER_LBLUE);	
	autosalon_area_info_2[2] = create_circle_pickup(-27.7022,351.8504,1601.7495, TRIGGER_LBLUE);	
	autosalon_area_info_2[3] = create_circle_pickup(-27.9780,346.8946,1601.7495, TRIGGER_LBLUE);	

	autosalon_area_info_2[4] = create_circle_pickup(-27.8159,336.3489,1601.7495, TRIGGER_LBLUE);	
	autosalon_area_info_2[5] = create_circle_pickup(-26.6178,328.1407,1601.7495, TRIGGER_LBLUE);	
	autosalon_area_info_2[6] = create_circle_pickup(6.1735,347.1485,1609.5936, TRIGGER_LBLUE);	
	autosalon_area_info_2[7] = create_circle_pickup(-15.9762,353.6224,1601.7948, TRIGGER_LBLUE);	


	autosalon_actor[0] = CreateActor(12, -188.1110,-4.3891,1202.0325,177.6645);
	SetActorVirtualWorld(autosalon_actor[0], 10);
	autosalon_actor[1] = CreateActor(17, -247.1565,-13.4299,1202.0481,269.6830);
	SetActorVirtualWorld(autosalon_actor[1], 10);
	ApplyActorAnimation(autosalon_actor[1], "COP_AMBIENT", "coplook_loop", 4.1, 1, 1, 1, 0, 0);


	autosalon_actor[2] = CreateActor(17, -201.1625,21.4844,1201.9456,181.1234);
	SetActorVirtualWorld(autosalon_actor[2], 10);
	autosalon_actor[3] = CreateActor(17, -207.4042,21.3896,1201.9456,180.2796);
	SetActorVirtualWorld(autosalon_actor[3], 10);


	autosalon_actor[3] = CreateActor(12, -16.8011,359.8202,1601.7495,89.6010);
	SetActorVirtualWorld(autosalon_actor[2], 10);
	autosalon_actor[4] = CreateActor(17, -16.7991,362.4908,1601.7495,90.7922);
	SetActorVirtualWorld(autosalon_actor[3], 10);	

	autosalon_actor[4] = CreateActor(17, -22.4772,-698.9580,1201.9474,180.8720);
	SetActorVirtualWorld(autosalon_actor[4], 10);	


	CreateDynamic3DTextLabel(""cWH"Покупка одежды\n"cBLUE"[ALT]",-1, \
	-67.9118,964.6990,1597.9788, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	

	create_circle_pickup_o(-67.9118,964.6990,1597.9788, TRIGGER_LBLUE);
	create_dynamic_area(-67.9118,964.6990,1597.9788, -1, BUISNES_CLOTHES, BUY_CLOTHES_ZONE);


	create_circle_pickup_o(-653.0558,-715.7249,1201.9475, TRIGGER_LBLUE);
	create_dynamic_area(-653.0558,-715.7249,1201.9475, -1, BUISNES_ACCESSORIES, BUY_ACCESSORIES_ZONE);


	CreateDynamic3DTextLabel(""cWH"Покупка автомобиля\n"cBLUE"[ALT]",-1, \
	-188.1124,-6.1309,1202.0325, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	

	create_circle_pickup_o(-188.1124,-6.1309,1202.0325, TRIGGER_LBLUE);
	create_dynamic_area(-188.1124,-6.1309,1202.0325, 10, BUISNES_AUTOSALON_1, BUY_CAR_ZONE);

	CreateDynamic3DTextLabel(""cWH"Покупка автомобиля\n"cBLUE"[ALT]",-1, \
	-19.0693,359.8874,1601.7495, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	

	create_circle_pickup_o(-19.0693,359.8874,1601.7495, TRIGGER_LBLUE);
	create_dynamic_area(-19.0693,359.8874,1601.7495, 10, BUISNES_AUTOSALON_2, BUY_CAR_ZONE);


	CreateDynamic3DTextLabel(""cWH"Покупка автомобиля\n"cBLUE"[ALT]",-1, \
	-22.3619,-701.2791,1201.9474, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	

	create_circle_pickup_o(-22.3619,-701.2791,1201.9474, TRIGGER_LBLUE);
	create_dynamic_area(-22.3619,-701.2791,1201.9474, 10, BUISNES_AUTOSALON_3, BUY_CAR_ZONE);


	CreateDynamic3DTextLabel(""cWH"Аренда автомобиля\n"cGR"[ALT]",-1, \
	498.6458,2253.0095,12.0078, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	

	create_circle_pickup_o(498.6458,2253.0095,12.0078, TRIGGER_GREEN);
	create_dynamic_area(498.6458,2253.0095,12.0078, 0, BUISNES_AUTOSALON_1, RENT_CAR_ZONE);

	CreateDynamic3DTextLabel(""cWH"Аренда автомобиля\n"cGR"[ALT]",-1, \
	472.1013,1183.7905,12.0080, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	

	create_circle_pickup_o(472.1013,1183.7905,12.0080, TRIGGER_GREEN);
	create_dynamic_area(472.1013,1183.7905,12.0080, 0, BUISNES_AUTOSALON_2, RENT_CAR_ZONE);


	CreateDynamic3DTextLabel(""cWH"Аренда автомобиля\n"cGR"[ALT]",-1, \
	2315.8848,-1790.6884,22.4540, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	

	create_circle_pickup_o(2315.8848,-1790.6884,22.4540, TRIGGER_GREEN);
	create_dynamic_area(2315.8848,-1790.6884,22.4540, 0, BUISNES_AUTOSALON_3, RENT_CAR_ZONE);


	return true;
}

stock create_other_element_biz()
{

	ammunation_actor[0] = CreateActor(30, 9.9127,22.6606,1601.7458,178.7493);
	SetActorVirtualWorld(ammunation_actor[0], 21);	
 
	ammunation_actor[1] = CreateActor(30, 9.9127,22.6606,1601.7458,178.7493);
	SetActorVirtualWorld(ammunation_actor[1], 20);	

	clothes_actor = CreateActor(12, -68.4601,966.4313,1597.9788,180.4187);
	SetActorVirtualWorld(clothes_actor, 20);	



	
	return true;
}

stock get_buisnes_aks_n(h)
{
	new 
		name[40],
		class = buisness[h][buisnes_name];

	switch(class)
	{
		case 1: name = "MontanaShop";
		case 2: name = "Gucci";
		case 3: name = "ZaraShop";
		case 4: name = "Prado";
		default: name = "Заброшенный";
	}
	return name;
}

stock get_buisnes_realtor(h)
{
	new 
		name[40],
		class = buisness[h][buisnes_name];

	switch(class)
	{
		case 1: name = "Агенство Бизнесмэн";
		case 2: name = "Агенство Дома-строй";
		case 3: name = "Агенство Счастливый владелец";
		default: name = "Заброшенный";
	}


	return name;
}

stock get_buisnes_clothes_n(h)
{
	new 
		name[40],
		class = buisness[h][buisnes_name];

	switch(class)
	{
		case 1: name = "Waikiki";
		case 2: name = "NewYorker";
		case 3: name = "Bershka";
		default: name = "Заброшенный";
	}
	return name;
}

stock get_buisnes_univermag_n(h)
{
	new 
		name[40],
		class = buisness[h][buisnes_name];

	switch(class)
	{
		case 1: name = "Универмаг Северный";
		case 2: name = "Универмаг Евроопт";
		case 3: name = "Универмаг Раковидный";
		case 4: name = "Универмаг ПАМАГИТЕ";
		default: name = "Заброшенный";
	}
	return name;
}

stock get_buisnes_bar_n(h)
{
	new 
		name[40],
		class = buisness[h][buisnes_name];

	switch(class)
	{
		case 1: name = "Бар 'Голубая Устрица'";
		case 2: name = "Бар 'Четыре шишки'";
		default: name = "Заброшенный";
	}
	return name;
}

stock get_buisnes_ammo_n(h)
{
	new 
		name[40],
		class = buisness[h][buisnes_name];

	switch(class)
	{
		case 1: name = "Магазин Оружия 'Выстрел'";
		case 2: name = "Магазин Оружия 'Выстрел'";
		default: name = "Заброшенный";
	}
	return name;
}

stock get_buisnes_restoran_n(h)
{
	new 
		name[40],
		class = buisness[h][buisnes_name];

	switch(class)
	{
		case 1: name = "Ресторан 'Мезантроп'";
		case 2: name = "Ресторан 'Мезантроп'";
		default: name = "Заброшенный";
	}
	return name;
}

stock get_buisnes_fastfood_n(h)
{
	new 
		name[40],
		class = buisness[h][buisnes_name];

	switch(class)
	{
		case 1: name = "Закусочная 'Burgerking'";
		case 2: name = "Закусочная 'KFC'";
		default: name = "Заброшенный";
	}
	return name;
}

stock get_buisnes_club_n(h)
{
	new 
		name[40],
		class = buisness[h][buisnes_name];

	switch(class)
	{
		case 1: name = "Клуб 'Голубая Устрица'";
		case 2: name = "Клуб 'Четыре шишки'";
		default: name = "Заброшенный";
	}
	return name;
}

stock panel_change_general_biz(playerid)
{
	if(pData[playerid][pBusiness] == -1)
		return SendErr(playerid, "Вы не владеете бизнесом!");

	new 
		biz_id = pData[playerid][pBusiness];

	if(buisness[biz_id][buisnes_type] == BUISNES_PARKING)
	{
		if(buisness[biz_id][buisnes_finka_day] >= buisness[biz_id][buisnes_finka_ogran])
		{

		    format(String512, sizeof(String512), "\
		    "cGREY"Тип\t"cGREY"Информация\n\
		    "cBLUE"- "cWH"Информация о бизнесе\t"cBLUE"Информация\n\
		    "cBLUE"- "cWH"Статистика бизнеса\t"cGR"Открыть\n\
		    "cBLUE"- "cWH"Касса бизнеса\t"cGR"%d"cWH"Открыть\n\
		    "cBLUE"- "cWH"Продажа бизнеса\t"cGR"%d"cWH"Открыть\n\
		    "cBLUE""cWH"\t"cGR"\n\
		    "cLRED"- "cWH"Прибыль ограничена!\tЛимит на прибыль был исчерпан!", buisness[biz_id][buisnes_price_day_rent]);
		    SPD(playerid, DIALOG_CHANGE_PANEL_BIZ_P, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление бизнесом", String512, !"Выбрать", !"Закрыть"); 
		}
		else
		{
		    format(String512, sizeof(String512), "\
		    "cGREY"Тип\t"cGREY"Информация\n\
		    "cBLUE"- "cWH"Информация о бизнесе\t"cBLUE"Информация\n\
		    "cBLUE"- "cWH"Статистика бизнеса\t"cGR"Открыть\n\
		    "cBLUE"- "cWH"Касса бизнеса\t"cGR"%d"cWH"Открыть\n\
		    "cBLUE"- "cWH"Продажа бизнеса\t"cGR"%d"cWH"Открыть", buisness[biz_id][buisnes_price_day_rent]);
		    SPD(playerid, DIALOG_CHANGE_PANEL_BIZ_P, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление бизнесом", String512, !"Выбрать", !"Закрыть"); 		
		}			
	}
	else if(buisness[biz_id][buisnes_type] == BUISNES_RIELTOR_AGENCY)
	{
		if(buisness[biz_id][buisnes_finka_day] >= buisness[biz_id][buisnes_finka_ogran])
		{

		    format(String512, sizeof(String512), "\
		    "cGREY"Тип\t"cGREY"Информация\n\
		    "cBLUE"- "cWH"Информация о бизнесе\t"cBLUE"Информация\n\
		    "cBLUE"- "cWH"Изменение цены входа в бизнес\t"cGR"%d рублей\n\
		    "cBLUE"- "cWH"Статистика бизнеса\t"cGR"Открыть\n\
		    "cBLUE"- "cWH"Касса бизнеса\t"cGR"%d"cWH"Открыть\n\
		    "cBLUE"- "cWH"Продажа бизнеса\t"cGR"%d"cWH"Открыть\n\
		    "cBLUE""cWH"\t"cGR"\n\
		    "cLRED"- "cWH"Прибыль ограничена!\tЛимит на прибыль был исчерпан!", buisness[biz_id][buisnes_enterprice]);
		    SPD(playerid, DIALOG_CHANGE_PANEL_BIZ_R, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление бизнесом", String512, !"Выбрать", !"Закрыть"); 
		}
		else
		{
		    format(String512, sizeof(String512), "\
		    "cGREY"Тип\t"cGREY"Информация\n\
		    "cBLUE"- "cWH"Информация о бизнесе\t"cBLUE"Информация\n\
		    "cBLUE"- "cWH"Изменение цены входа в бизнес\t"cGR"%d рублей\n\
		    "cBLUE"- "cWH"Статистика бизнеса\t"cGR"Открыть\n\
		    "cBLUE"- "cWH"Касса бизнеса\t"cGR"%d"cWH"Открыть\n\
		    "cBLUE"- "cWH"Продажа бизнеса\t"cGR"%d"cWH"Открыть", buisness[biz_id][buisnes_enterprice]);
		    SPD(playerid, DIALOG_CHANGE_PANEL_BIZ_R, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление бизнесом", String512, !"Выбрать", !"Закрыть"); 		
		}		
	}
	else
	{
		if(buisness[biz_id][buisnes_finka_day] >= buisness[biz_id][buisnes_finka_ogran])
		{

		    format(String512, sizeof(String512), "\
		    "cGREY"Тип\t"cGREY"Информация\n\
		    "cBLUE"- "cWH"Информация о бизнесе\t"cBLUE"Информация\n\
		    "cBLUE"- "cWH"Заказать продукты\t"cBLUE"%d ед\n\
		    "cBLUE"- "cWH"Статистика бизнеса\t"cGR"Открыть\n\
		    "cBLUE"- "cWH"Касса бизнеса\t"cGR"%d"cWH"Открыть\n\
		    "cBLUE"- "cWH"Продажа бизнеса\t"cGR"%d"cWH"Открыть\n\
		    "cBLUE""cWH"\t"cGR"\n\
		    "cLRED"- "cWH"Прибыль ограничена!\tЛимит на прибыль был исчерпан!", buisness[biz_id][buisnes_count_prod]);
		    SPD(playerid, DIALOG_CHANGE_PANEL_BIZ, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление бизнесом", String512, !"Выбрать", !"Закрыть"); 
		}
		else
		{
		    format(String512, sizeof(String512), "\
		    "cGREY"Тип\t"cGREY"Информация\n\
		    "cBLUE"- "cWH"Информация о бизнесе\t"cBLUE"Информация\n\
		    "cBLUE"- "cWH"Заказать продукты\t"cBLUE"%d ед\n\
		    "cBLUE"- "cWH"Статистика бизнеса\t"cGR"Открыть\n\
		    "cBLUE"- "cWH"Касса бизнеса\t"cGR"%d"cWH"Открыть\n\
		    "cBLUE"- "cWH"Продажа бизнеса\t"cGR"%d"cWH"Открыть", buisness[biz_id][buisnes_count_prod]);
		    SPD(playerid, DIALOG_CHANGE_PANEL_BIZ, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Управление бизнесом", String512, !"Выбрать", !"Закрыть"); 		
		}
	}
	return true;
}

stock info_biz_panel_change(playerid)
{
	static 
		buisnes_names[24],
		b_owner[24];

	new 
		biz_id = pData[playerid][pBusiness];


	if(buisness[biz_id][buisnes_type] == BUISNES_PRODUCTION)
	{
		format(buisnes_names, 24, "%s", get_buisnes_univermag_n(biz_id));
	}
	else if(buisness[biz_id][buisnes_type] == BUISNES_BAR)
	{
		format(buisnes_names, 24, "%s", get_buisnes_bar_n(biz_id));
	}
	else if(buisness[biz_id][buisnes_type] == BUISNES_AMMO_1)
	{
		format(buisnes_names, 24, "%s", get_buisnes_ammo_n(biz_id));
	}
	else if(buisness[biz_id][buisnes_type] == BUISNES_AMMO_2)
	{
		format(buisnes_names, 24, "%s", get_buisnes_ammo_n(biz_id));
	}
	else if(buisness[biz_id][buisnes_type] == BUISNES_RESTORAN)
	{
		format(buisnes_names, 24, "%s", get_buisnes_restoran_n(biz_id));
	}
	else if(buisness[biz_id][buisnes_type] == BUISNES_FASTFOOD)
	{
		format(buisnes_names, 24, "%s", get_buisnes_fastfood_n(biz_id));
	}
	else if(buisness[biz_id][buisnes_type] == BUISNES_CLUB)
	{
		format(buisnes_names, 24, "%s", get_buisnes_club_n(biz_id));
	}	
	else if(buisness[biz_id][buisnes_type] == BUISNES_AUTOSALON_1)
	{
		format(buisnes_names, 24, "%s", get_buisnes_autosalon_n[buisness[biz_id][buisnes_name]]);
	}	
	else if(buisness[biz_id][buisnes_type] == BUISNES_CLOTHES)
	{
		format(buisnes_names, 24, "%s", get_buisnes_clothes_n(biz_id));
	}
	else if(buisness[biz_id][buisnes_type] == BUISNES_AUTOSALON_2)
	{
		format(buisnes_names, 24, "%s", get_buisnes_autosalon_n[buisness[biz_id][buisnes_name]]);
	}	
	else if(buisness[biz_id][buisnes_type] == BUISNES_AUTOSALON_3)
	{
		format(buisnes_names, 24, "%s", get_buisnes_autosalon_n[buisness[biz_id][buisnes_name]]);
	}	
	else if(buisness[biz_id][buisnes_type] == BUISNES_CLOTHES)
	{
		format(buisnes_names, 24, "%s", get_buisnes_clothes_n(biz_id));
	}	
	else if(buisness[biz_id][buisnes_type] == BUISNES_ACCESSORIES)
	{
		format(buisnes_names, 24, "%s", get_buisnes_aks_n(biz_id));
	}
	else if(buisness[biz_id][buisnes_type] == BUISNES_RIELTOR_AGENCY)
	{
		format(buisnes_names, 24, "%s", get_buisnes_realtor(biz_id));
	}
	if(buisness[biz_id][buisnes_owned] != -1)
	{
		GetPlayerNameByID(buisness[biz_id][buisnes_owned], buisness[biz_id][buisnes_owner]);
		format(b_owner, 24, buisness[biz_id][buisnes_owner]);
	}
	else
	{
		format(b_owner, 24, "Государство");	
	}

	if(buisness[biz_id][buisnes_type] == BUISNES_PARKING)
	{
		format(String512, sizeof(String512), "\
		"cWH"Номер бизнеса: 	\t"cBLUE"%d\n\
		"cWH"Тип бизнеса:		\t"cBLUE"Паркинг\n\
		"cWH"Владелец: 			\t"cBLUE"%s\n\
		"cWH"Статус: 			\t\t%s\n\
		"cWH"Цена: 				\t"cGR"%d рублей\n\
		"cWH"Ежедневная оплата: \t\t\t"cGR"%d рублей\n\
		"cWH"Крышует бизнес: \t\t\t"cGR"%s",
		biz_id+1,
		b_owner,
		(buisness[biz_id][buisnes_owned]) ? (""cGR"Работает") : (""cLRED"Закрыт"),
		buisness[biz_id][buisnes_price], buisness[biz_id][buisnes_takings], get_mafia_name(buisness[biz_id][buisnes_mafia]));
		SPD(playerid, DIALOG_INFO_BIZ_PANEL, DIALOG_STYLE_MSGBOX, !""cBLUE"Информация о бизнесе", String512, !"Закрыть", "");	
	}
	else
	{
		format(String512, sizeof(String512), "\
		"cWH"Номер бизнеса: 	\t"cBLUE"%d\n\
		"cWH"Тип бизнеса:		\t"cBLUE"%s\n\
		"cWH"Владелец: 			\t"cBLUE"%s\n\
		"cWH"Статус: 			\t\t%s\n\
		"cWH"Цена: 				\t"cGR"%d рублей\n\
		"cWH"Ежедневная оплата: \t\t\t"cGR"%d рублей\n\
		"cWH"Крышует бизнес: \t\t\t"cGR"%s",
		biz_id+1,
		buisnes_names,
		b_owner,
		(buisness[biz_id][buisnes_owned]) ? (""cGR"Работает") : (""cLRED"Закрыт"),
		buisness[biz_id][buisnes_price], buisness[biz_id][buisnes_takings], get_mafia_name(buisness[biz_id][buisnes_mafia]));
		SPD(playerid, DIALOG_INFO_BIZ_PANEL, DIALOG_STYLE_MSGBOX, !""cBLUE"Информация о бизнесе", String512, !"Закрыть", "");	
	}
	return true;
}


stock change_bank_biz(playerid)
{
	if(pData[playerid][pBusiness] == -1)
		return SendErr(playerid, "Вы не владеете бизнесом!");

	new 
		biz_id = pData[playerid][pBusiness];

    format(String512, sizeof(String512), "\
    "cGREY"Тип\t"cGREY"Информация\n\
    "cBLUE"- "cWH"Снять деньги с кассы бизнеса\t"cGR"%d"cWH" рублей\n\
    "cBLUE"- "cWH"Положить деньги в кассу бизнеса\tПоложить", buisness[biz_id][buisnes_bank]);
    return SPD(playerid, DIALOG_CHANGE_CASSA_BIZ, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Касса бизнеса", String512, !"Выбрать", !"Закрыть"); 

}

stock change_bank_biz_input(playerid)
{
	if(pData[playerid][pBusiness] == -1)
		return SendErr(playerid, "Вы не владеете бизнесом!");

	new 
		biz_id = pData[playerid][pBusiness];

	format(String256, sizeof(String256), "\
	"cWH"В кассе Вашего бизнеса находится "cGR"%d рублей"cWH" на данный момент\n\n\
	"cBLUE"Сколько денег Вы хотите взять?", buisness[biz_id][buisnes_bank]);

	return SPD(playerid, DIALOG_INPUT_MONEY_BANK_BIZ, DIALOG_STYLE_INPUT, !""cBLUE"Касса бизнеса", String256, !"Далее", !"Назад");
}
stock change_bank_biz_put(playerid)
{
	if(pData[playerid][pBusiness] == -1)
		return SendErr(playerid, "Вы не владеете бизнесом!");

	new 
		biz_id = pData[playerid][pBusiness];

	format(String256, sizeof(String256), "\
	"cWH"В кассе Вашего бизнеса находится "cGR"%d рублей"cWH" на данный момент\n\n\
	"cBLUE"Сколько денег Вы хотите положить?", buisness[biz_id][buisnes_bank]);

	return SPD(playerid, DIALOG_PUT_MONEY_BANK_BIZ, DIALOG_STYLE_INPUT, !""cBLUE"Касса бизнеса", String256, !"Далее", !"Назад");
}

stock delivery_prod_biz(playerid)
{


	return true;
}


stock update_biz_text()
{
	for(new i, idx = all_buisness; i < idx; i ++) 
	{

		if(buisness[i][buisnes_type] == BUISNES_PARKING)
		{
			new
				b_owner[24];

			if(buisness[i][buisnes_owned] != -1)
			{
				GetPlayerNameByID(buisness[i][buisnes_owned], buisness[i][buisnes_owner]);
				format(b_owner, 24, buisness[i][buisnes_owner]);
			}
			else
			{
				format(b_owner, 24, "Государство");	
			}

			format(String320, sizeof(String320), "\
				"cWH"Паркинг "cBLUE"№%d\n\n\
				"cBLUE"Владелец: \
				"cWH"%s\n\
				"cBLUE"Крышует: \
				"cWH"%s\n\
				"cBLUE"[ALT]", i+1, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));

			UpdateDynamic3DTextLabelText(buisness[i][buisnes_pickup_3d], -1, String320);




			if(buisness[i][buisnes_status_sell] == 3)
			{
				format(String320, sizeof(String320), "\
					"cWH"Паркинг "cBLUE"№%d\n\n\
					"cORANGE"Бизнес опечатан\n\n\
					"cBLUE"Владелец: \
					"cWH"%s\n\
					"cBLUE"Крышует: \
					"cWH"%s\n\
					"cBLUE"[ALT]", i+1, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));

				UpdateDynamic3DTextLabelText(buisness[i][buisnes_pickup_3d], -1, String320);
			}			
		}


		if(buisness[i][buisnes_type] == BUISNES_RIELTOR_AGENCY)
		{
			new
				buisnes_names[24],
				b_owner[24];

			format(buisnes_names, 24, "%s", get_buisnes_realtor(i));

			if(buisness[i][buisnes_owned] != -1)
			{
				GetPlayerNameByID(buisness[i][buisnes_owned], buisness[i][buisnes_owner]);
				format(b_owner, 24, buisness[i][buisnes_owner]);
			}
			else
			{
				format(b_owner, 24, "Государство");	
			}

			format(String320, sizeof(String320), "\
				"cWH"Риелторское Агенство "cBLUE"№%d\n\n\
				"cBLUE"Название: \
				"cWH"%s\n\
				"cBLUE"Владелец: \
				"cWH"%s\n\
				"cBLUE"Крышует: \
				"cWH"%s\n\
				"cBLUE"Цена входа: \
				"cWH"%d рублей\n\n\
				"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]), buisness[i][buisnes_enterprice]);

			UpdateDynamic3DTextLabelText(buisness[i][buisnes_pickup_3d], -1, String320);




			if(buisness[i][buisnes_status_sell] == 3)
			{
				format(String320, sizeof(String320), "\
					"cWH"Риелторское Агенство "cBLUE"№%d\n\n\
					"cORANGE"Бизнес опечатан\n\n\
					"cBLUE"Название: \
					"cWH"%s\n\
					"cBLUE"Владелец: \
					"cWH"%s\n\
					"cBLUE"Крышует: \
					"cWH"%s\n\
					"cBLUE"Цена входа: \
					"cWH"%d рублей\n\n\
					"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]), buisness[i][buisnes_enterprice]);

				UpdateDynamic3DTextLabelText(buisness[i][buisnes_pickup_3d], -1, String320);				
				
			}			
		}

		if(buisness[i][buisnes_type] == BUISNES_CLOTHES)
		{
			new
				buisnes_names[24],
				b_owner[24];

			format(buisnes_names, 24, "%s", get_buisnes_clothes_n(i));

			if(buisness[i][buisnes_owned] != -1)
			{
				GetPlayerNameByID(buisness[i][buisnes_owned], buisness[i][buisnes_owner]);
				format(b_owner, 24, buisness[i][buisnes_owner]);
			}
			else
			{
				format(b_owner, 24, "Государство");	
			}

			format(String320, sizeof(String320), "\
				"cWH"Магазин Одежды "cBLUE"№%d\n\n\
				"cBLUE"Название: \
				"cWH"%s\n\
				"cBLUE"Владелец: \
				"cWH"%s\n\
				"cBLUE"Охрана: \
				"cWH"Отсутствует\n\n\
				"cBLUE"[ALT]", i+1, buisnes_names, b_owner);

			UpdateDynamic3DTextLabelText(buisness[i][buisnes_pickup_3d], -1, String320);

			if(buisness[i][buisnes_status_sell] == 3)
			{
				format(String320, sizeof(String320), "\
					"cWH"Магазин Одежды "cBLUE"№%d\n\n\
					"cORANGE"Магазин опечатан\n\n\
					"cBLUE"Название: \
					"cWH"%s\n\
					"cBLUE"Владелец: \
					"cWH"%s\n\
					"cBLUE"Крышует: \
					"cWH"%s\n\n\
					"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));

				UpdateDynamic3DTextLabelText(buisness[i][buisnes_pickup_3d], -1, String320);				
			}

		}

		if(buisness[i][buisnes_type] == BUISNES_ACCESSORIES)
		{
			new
				buisnes_names[24],
				b_owner[24];

			format(buisnes_names, 24, "%s", get_buisnes_aks_n(i));

			if(buisness[i][buisnes_owned] != -1)
			{
				GetPlayerNameByID(buisness[i][buisnes_owned], buisness[i][buisnes_owner]);
				format(b_owner, 24, buisness[i][buisnes_owner]);
			}
			else
			{
				format(b_owner, 24, "Государство");	
			}

			format(String320, sizeof(String320), "\
				"cWH"Магазин Аксессуаров "cBLUE"№%d\n\n\
				"cBLUE"Название: \
				"cWH"%s\n\
				"cBLUE"Владелец: \
				"cWH"%s\n\
				"cBLUE"Крышует: \
				"cWH"%s\n\n\
				"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));

			UpdateDynamic3DTextLabelText(buisness[i][buisnes_pickup_3d], -1, String320);

			if(buisness[i][buisnes_status_sell] == 3)
			{
				format(String320, sizeof(String320), "\
					"cWH"Магазин Аксессуаров "cBLUE"№%d\n\n\
					"cORANGE"Магазин опечатан\n\n\
					"cBLUE"Название: \
					"cWH"%s\n\
					"cBLUE"Владелец: \
					"cWH"%s\n\
					"cBLUE"Крышует: \
					"cWH"%s\n\n\
					"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));

				UpdateDynamic3DTextLabelText(buisness[i][buisnes_pickup_3d], -1, String320);				
			}			
		}


		if(buisness[i][buisnes_type] == BUISNES_AUTOSALON_1)
		{
			new
				buisnes_names[24],
				b_owner[24];

			format(buisnes_names, 24, "%s", get_buisnes_autosalon_n[buisness[i][buisnes_name]]);

			if(buisness[i][buisnes_owned] != -1)
			{
				GetPlayerNameByID(buisness[i][buisnes_owned], buisness[i][buisnes_owner]);
				format(b_owner, 24, buisness[i][buisnes_owner]);
			}
			else
			{
				format(b_owner, 24, "Государство");	
			}

			format(String320, sizeof(String320), "\
				"cWH"Автосалон "cBLUE"№%d\n\n\
				"cBLUE"Название: \
				"cWH"%s\n\
				"cBLUE"Владелец: \
				"cWH"%s\n\
				"cBLUE"Крышует: \
				"cWH"%s\n\n\
				"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));

			UpdateDynamic3DTextLabelText(buisness[i][buisnes_pickup_3d], -1, String320);

			if(buisness[i][buisnes_status_sell] == 3)
			{
				format(String320, sizeof(String320), "\
					"cWH"Автосалон "cBLUE"№%d\n\n\
					"cORANGE"Автосалон опечатан\n\n\
					"cBLUE"Название: \
					"cWH"%s\n\
					"cBLUE"Владелец: \
					"cWH"%s\n\
					"cBLUE"Крышует: \
					"cWH"%s\n\n\
					"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));

				UpdateDynamic3DTextLabelText(buisness[i][buisnes_pickup_3d], -1, String320);				
			}

		}

		if(buisness[i][buisnes_type] == BUISNES_AUTOSALON_2)
		{
			new
				buisnes_names[24],
				b_owner[24];

			format(buisnes_names, 24, "%s", get_buisnes_autosalon_n[buisness[i][buisnes_name]]);

			if(buisness[i][buisnes_owned] != -1)
			{
				GetPlayerNameByID(buisness[i][buisnes_owned], buisness[i][buisnes_owner]);
				format(b_owner, 24, buisness[i][buisnes_owner]);
			}
			else
			{
				format(b_owner, 24, "Государство");	
			}

			format(String320, sizeof(String320), "\
				"cWH"Автосалон "cBLUE"№%d\n\n\
				"cBLUE"Название: \
				"cWH"%s\n\
				"cBLUE"Владелец: \
				"cWH"%s\n\
				"cBLUE"Крышует: \
				"cWH"%s\n\n\
				"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));

			UpdateDynamic3DTextLabelText(buisness[i][buisnes_pickup_3d], -1, String320);

			if(buisness[i][buisnes_status_sell] == 3)
			{
				format(String320, sizeof(String320), "\
					"cWH"Автосалон "cBLUE"№%d\n\n\
					"cORANGE"Автосалон опечатан\n\n\
					"cBLUE"Название: \
					"cWH"%s\n\
					"cBLUE"Владелец: \
					"cWH"%s\n\
					"cBLUE"Крышует: \
					"cWH"%s\n\n\
					"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));

				UpdateDynamic3DTextLabelText(buisness[i][buisnes_pickup_3d], -1, String320);				
			}

		}


		if(buisness[i][buisnes_type] == BUISNES_PRODUCTION)
		{
			new
				buisnes_names[24],
				b_owner[24];

			format(buisnes_names, 24, "%s", get_buisnes_univermag_n(i));

			if(buisness[i][buisnes_owned] != -1)
			{
				GetPlayerNameByID(buisness[i][buisnes_owned], buisness[i][buisnes_owner]);
				format(b_owner, 24, buisness[i][buisnes_owner]);
			}
			else
			{
				format(b_owner, 24, "Государство");	
			}

			format(String320, sizeof(String320), "\
				"cWH"Продуктовый Магазин "cBLUE"№%d\n\n\
				"cBLUE"Название: \
				"cWH"%s\n\
				"cBLUE"Владелец: \
				"cWH"%s\n\
				"cBLUE"Крышует: \
				"cWH"%s\n\n\
				"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));

			UpdateDynamic3DTextLabelText(buisness[i][buisnes_pickup_3d], -1, String320);

			if(buisness[i][buisnes_status_sell] == 3)
			{
				format(String320, sizeof(String320), "\
					"cWH"Продуктовый Магазин "cBLUE"№%d\n\n\
					"cORANGE"Магазин опечатан\n\n\
					"cBLUE"Название: \
					"cWH"%s\n\
					"cBLUE"Владелец: \
					"cWH"%s\n\
					"cBLUE"Крышует: \
					"cWH"%s\n\n\
					"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));

				UpdateDynamic3DTextLabelText(buisness[i][buisnes_pickup_3d], -1, String320);				
			}

		}

		if(buisness[i][buisnes_type] == BUISNES_BAR)
		{

			new
				buisnes_names[24],
				b_owner[24];

			format(buisnes_names, 24, "%s", get_buisnes_bar_n(i));

			if(buisness[i][buisnes_owned] != -1)
			{
				GetPlayerNameByID(buisness[i][buisnes_owned], buisness[i][buisnes_owner]);
				format(b_owner, 24, buisness[i][buisnes_owner]);
			}
			else
			{
				format(b_owner, 24, "Государство");	
			}

			format(String320, sizeof(String320), "\
				"cWH"Бар "cBLUE"№%d\n\n\
				"cBLUE"Название: \
				"cWH"%s\n\
				"cBLUE"Владелец: \
				"cWH"%s\n\
				"cBLUE"Крышует: \
				"cWH"%s\n\n\
				"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));

			UpdateDynamic3DTextLabelText(buisness[i][buisnes_pickup_3d], -1, String320);

			if(buisness[i][buisnes_status_sell] == 3)
			{
				format(String320, sizeof(String320), "\
					"cWH"Бар "cBLUE"№%d\n\n\
					"cORANGE"Бар опечатан\n\n\
					"cBLUE"Название: \
					"cWH"%s\n\
					"cBLUE"Владелец: \
					"cWH"%s\n\
					"cBLUE"Крышует: \
					"cWH"%s\n\n\
					"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));

				UpdateDynamic3DTextLabelText(buisness[i][buisnes_pickup_3d], -1, String320);				
			}

		}

		if(buisness[i][buisnes_type] == BUISNES_AMMO_1)
		{
			new
				buisnes_names[24],
				b_owner[24];

			format(buisnes_names, 24, "%s", get_buisnes_ammo_n(i));

			if(buisness[i][buisnes_owned] != -1)
			{
				GetPlayerNameByID(buisness[i][buisnes_owned], buisness[i][buisnes_owner]);
				format(b_owner, 24, buisness[i][buisnes_owner]);
			}
			else
			{
				format(b_owner, 24, "Государство");	
			}

			format(String320, sizeof(String320), "\
				"cWH"Магазин Оружия "cBLUE"№%d\n\n\
				"cBLUE"Название: \
				"cWH"%s\n\
				"cBLUE"Владелец: \
				"cWH"%s\n\
				"cBLUE"Крышует: \
				"cWH"%s\n\n\
				"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));

			UpdateDynamic3DTextLabelText(buisness[i][buisnes_pickup_3d], -1, String320);
		
			if(buisness[i][buisnes_status_sell] == 3)
			{
				format(String320, sizeof(String320), "\
					"cWH"Магазин Оружия "cBLUE"№%d\n\n\
					"cORANGE"Магазин Оружия опечатан\n\n\
					"cBLUE"Название: \
					"cWH"%s\n\
					"cBLUE"Владелец: \
					"cWH"%s\n\
					"cBLUE"Крышует: \
					"cWH"%s\n\n\
					"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));

				UpdateDynamic3DTextLabelText(buisness[i][buisnes_pickup_3d], -1, String320);				
			}

		}
		if(buisness[i][buisnes_type] == BUISNES_AMMO_2)
		{
			new
				buisnes_names[24],
				b_owner[24];

			format(buisnes_names, 24, "%s", get_buisnes_ammo_n(i));

			if(buisness[i][buisnes_owned] != -1)
			{
				GetPlayerNameByID(buisness[i][buisnes_owned], buisness[i][buisnes_owner]);
				format(b_owner, 24, buisness[i][buisnes_owner]);
			}
			else
			{
				format(b_owner, 24, "Государство");	
			}

			format(String320, sizeof(String320), "\
				"cWH"Магазин Оружия "cBLUE"№%d\n\n\
				"cBLUE"Название: \
				"cWH"%s\n\
				"cBLUE"Владелец: \
				"cWH"%s\n\
				"cBLUE"Крышует: \
				"cWH"%s\n\n\
				"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));

			UpdateDynamic3DTextLabelText(buisness[i][buisnes_pickup_3d], -1, String320);
		
			if(buisness[i][buisnes_status_sell] == 3)
			{
				format(String320, sizeof(String320), "\
					"cWH"Магазин Оружия "cBLUE"№%d\n\n\
					"cORANGE"Магазин Оружия опечатан\n\n\
					"cBLUE"Название: \
					"cWH"%s\n\
					"cBLUE"Владелец: \
					"cWH"%s\n\
					"cBLUE"Крышует: \
					"cWH"%s\n\n\
					"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));

				UpdateDynamic3DTextLabelText(buisness[i][buisnes_pickup_3d], -1, String320);				
			}

		}
		if(buisness[i][buisnes_type] == BUISNES_RESTORAN)
		{
			new
				buisnes_names[24],
				b_owner[24];

			format(buisnes_names, 24, "%s", get_buisnes_restoran_n(i));

			if(buisness[i][buisnes_owned] != -1)
			{
				GetPlayerNameByID(buisness[i][buisnes_owned], buisness[i][buisnes_owner]);
				format(b_owner, 24, buisness[i][buisnes_owner]);
			}
			else
			{
				format(b_owner, 24, "Государство");	
			}

			format(String320, sizeof(String320), "\
				"cWH"Ресторан "cBLUE"№%d\n\n\
				"cBLUE"Название: \
				"cWH"%s\n\
				"cBLUE"Владелец: \
				"cWH"%s\n\
				"cBLUE"Крышует: \
				"cWH"%s\n\n\
				"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));

			UpdateDynamic3DTextLabelText(buisness[i][buisnes_pickup_3d], -1, String320);


			if(buisness[i][buisnes_status_sell] == 3)
			{
				format(String320, sizeof(String320), "\
					"cWH"Ресторан "cBLUE"№%d\n\n\
					"cORANGE"Ресторан опечатан\n\n\
					"cBLUE"Название: \
					"cWH"%s\n\
					"cBLUE"Владелец: \
					"cWH"%s\n\
					"cBLUE"Крышует: \
					"cWH"%s\n\n\
					"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));

				UpdateDynamic3DTextLabelText(buisness[i][buisnes_pickup_3d], -1, String320);				
			}

		}

		if(buisness[i][buisnes_type] == BUISNES_FASTFOOD)
		{
			new
				buisnes_names[24],
				b_owner[24];

			format(buisnes_names, 24, "%s", get_buisnes_fastfood_n(i));

			if(buisness[i][buisnes_owned] != -1)
			{
				GetPlayerNameByID(buisness[i][buisnes_owned], buisness[i][buisnes_owner]);
				format(b_owner, 24, buisness[i][buisnes_owner]);
			}
			else
			{
				format(b_owner, 24, "Государство");	
			}

			format(String320, sizeof(String320), "\
				"cWH"Закусочная "cBLUE"№%d\n\n\
				"cBLUE"Название: \
				"cWH"%s\n\
				"cBLUE"Владелец: \
				"cWH"%s\n\
				"cBLUE"Крышует: \
				"cWH"%s\n\n\
				"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));

			UpdateDynamic3DTextLabelText(buisness[i][buisnes_pickup_3d], -1, String320);

			if(buisness[i][buisnes_status_sell] == 3)
			{
				format(String320, sizeof(String320), "\
					"cWH"Закусочная "cBLUE"№%d\n\n\
					"cORANGE"Закусочная опечатана\n\n\
					"cBLUE"Название: \
					"cWH"%s\n\
					"cBLUE"Владелец: \
					"cWH"%s\n\
					"cBLUE"Крышует: \
					"cWH"%s\n\n\
					"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));

				UpdateDynamic3DTextLabelText(buisness[i][buisnes_pickup_3d], -1, String320);				
			}


		}

		if(buisness[i][buisnes_type] == BUISNES_CLUB)
		{
			new
				buisnes_names[24],
				b_owner[24];

			format(buisnes_names, 24, "%s", get_buisnes_club_n(i));

			if(buisness[i][buisnes_owned] != -1)
			{
				GetPlayerNameByID(buisness[i][buisnes_owned], buisness[i][buisnes_owner]);
				format(b_owner, 24, buisness[i][buisnes_owner]);
			}
			else
			{
				format(b_owner, 24, "Государство");	
			}

			format(String320, sizeof(String320), "\
				"cWH"Ночной клуб "cBLUE"№%d\n\n\
				"cBLUE"Название: \
				"cWH"%s\n\
				"cBLUE"Владелец: \
				"cWH"%s\n\
				"cBLUE"Крышует: \
				"cWH"%s\n\n\
				"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));

			UpdateDynamic3DTextLabelText(buisness[i][buisnes_pickup_3d], -1, String320);

			if(buisness[i][buisnes_status_sell] == 3)
			{
				format(String320, sizeof(String320), "\
					"cWH"Ночной клуб "cBLUE"№%d\n\n\
					"cORANGE"Ночной клуб опечатан\n\n\
					"cBLUE"Название: \
					"cWH"%s\n\
					"cBLUE"Владелец: \
					"cWH"%s\n\
					"cBLUE"Крышует: \
					"cWH"%s\n\n\
					"cBLUE"[ALT]", i+1, buisnes_names, b_owner, get_mafia_name(buisness[i][buisnes_mafia]));

				UpdateDynamic3DTextLabelText(buisness[i][buisnes_pickup_3d], -1, String320);				
			}

		}
	}
	return true;
}


stock select_menu_enter_autosalon(playerid, b_id)
{
	if(buisness[b_id][buisnes_type] == BUISNES_AUTOSALON_1 || buisness[b_id][buisnes_type] == BUISNES_AUTOSALON_2 || buisness[b_id][buisnes_type] == BUISNES_AUTOSALON_3)
	{
		if(buisness[b_id][buisnes_owned] == -1)
		{
    		format(String144, sizeof(String144), "\
   	 		"cBLUE"- "cWH"Информация о покупке автосалона\n\
    		"cBLUE"- "cWH"Войти в автосалон");
    		SPD(playerid, DIALOG_SELECT_ENTER_AUTOSALON, DIALOG_STYLE_LIST, !""cBLUE"Вход в автосалон", String144, !"Выбрать", !"Закрыть"); 
    	}
    	else
    	{
			if(buisness[b_id][buisnes_type] == BUISNES_AUTOSALON_1)
			{
				return enter_buisnes(playerid, BUISNES_AUTOSALON_1, b_id);
			}
			if(buisness[b_id][buisnes_type] == BUISNES_AUTOSALON_2)
			{
				return enter_buisnes(playerid, BUISNES_AUTOSALON_2, b_id);
			}
			if(buisness[b_id][buisnes_type] == BUISNES_AUTOSALON_3)
			{
				return enter_buisnes(playerid, BUISNES_AUTOSALON_3, b_id);
			}	
    	}
    }	
    else 
    {
    	info_autosalon_general(playerid, b_id);
    }
    return true;
}

stock select_menu_enter_aks(playerid, b_id)
{
	

	if(buisness[b_id][buisnes_type] == BUISNES_ACCESSORIES)
	{
		if(buisness[b_id][buisnes_owned] == -1)
		{
    		format(String144, sizeof(String144), "\
   	 		"cBLUE"- "cWH"Информация о покупке магазина\n\
    		"cBLUE"- "cWH"Войти в магазин");
    		SPD(playerid, DIALOG_SELECT_ENTER_AKS, DIALOG_STYLE_LIST, !""cBLUE"Вход в магазин аксессуаров", String144, !"Выбрать", !"Закрыть"); 
    	}
    	else
    	{
			return enter_buisnes(playerid, BUISNES_ACCESSORIES, b_id);
    	}
    }	
    else 
    {
    	info_aks_general(playerid, b_id);
    }
    return true;

}

stock info_aks_general(playerid, b_id)
{
	static 
		buisnes_names[24],
		b_owner[24];

	format(buisnes_names, 24, "%s", get_buisnes_aks_n(b_id));

	if(buisness[b_id][buisnes_owned] != -1)
	{
		GetPlayerNameByID(buisness[b_id][buisnes_owned], buisness[b_id][buisnes_owner]);
		format(b_owner, 24, buisness[b_id][buisnes_owner]);
	}
	else
	{
		format(b_owner, 24, "Государство");	
	}

	if(buisness[b_id][buisnes_type] == BUISNES_ACCESSORIES)
	{
		if(buisness[b_id][buisnes_owned] == -1)
		{

			format(String512, sizeof(String512), "\
			"cWH"Номер бизнеса: 	\t"cBLUE"%d\n\
			"cWH"Тип бизнеса:		\t"cBLUE"%s\n\
			"cWH"Владелец: 			\t"cBLUE"%s\n\
			"cWH"Статус: 			\t\t%s\n\
			"cWH"Цена: 				\t"cGR"%d рублей\n\
			"cWH"Ежедневная оплата: \t\t\t"cGR"%d рублей\n\n\
			"cBLUE"Вы действительно хотите купить магазин аксессуаров?",
			b_id+1,
			buisnes_names,
			b_owner,
			(buisness[b_id][buisnes_owned]) ? (""cGR"Продается") : (""cLRED"Куплен"),
			buisness[b_id][buisnes_price], buisness[b_id][buisnes_takings]);
			SPD(playerid, DIALOG_BUY_AKS_SHOP, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка магазина аксессуаров", String512, !"Купить", !"Закрыть");					
		}
		if(buisness[b_id][buisnes_owned] != -1)
		{
			format(String512, sizeof(String512), "\
			"cWH"Номер бизнеса: 	\t"cBLUE"%d\n\
			"cWH"Тип бизнеса:		\t"cBLUE"%s\n\
			"cWH"Владелец: 			\t"cBLUE"%s\n\
			"cWH"Статус: 			\t\t%s\n\
			"cWH"Цена: 				\t"cGR"%d рублей\n\
			"cWH"Ежедневная оплата: \t\t\t"cGR"%d рублей",
			b_id+1,
			buisnes_names,
			b_owner,
			(buisness[b_id][buisnes_owned]) ? (""cGR"Работает") : (""cLRED"Закрыт"),
			buisness[b_id][buisnes_price], buisness[b_id][buisnes_takings]);
			SPD(playerid, DIALOG_INFO_AKS_SHOP, DIALOG_STYLE_MSGBOX, !""cBLUE"Магазин аксессуаров", String512, !"Войти", !"Закрыть");		
		}
	}
	return true;
}


stock select_menu_enter_clothes(playerid, b_id)
{
	if(buisness[b_id][buisnes_type] == BUISNES_CLOTHES)
	{
		if(buisness[b_id][buisnes_owned] == -1)
		{
    		format(String144, sizeof(String144), "\
   	 		"cBLUE"- "cWH"Информация о покупке магазина\n\
    		"cBLUE"- "cWH"Войти в магазин");
    		SPD(playerid, DIALOG_SELECT_ENTER_CLOTHES, DIALOG_STYLE_LIST, !""cBLUE"Вход в магазин одежды", String144, !"Выбрать", !"Закрыть"); 
    	}
    	else
    	{
			return enter_buisnes(playerid, BUISNES_CLOTHES, b_id);
    	}
    }	
    else 
    {
    	info_clothes_general(playerid, b_id);
    }
    return true;
}

stock select_menu_enter_realter(playerid, b_id)
{
	if(buisness[b_id][buisnes_type] == BUISNES_RIELTOR_AGENCY)
	{
		if(buisness[b_id][buisnes_owned] == -1)
		{
    		format(String144, sizeof(String144), "\
   	 		"cBLUE"- "cWH"Информация о покупке агенства\n\
    		"cBLUE"- "cWH"Войти в агенство");
    		SPD(playerid, DIALOG_SELECT_ENTER_REALTOR, DIALOG_STYLE_LIST, !""cBLUE"Вход в Риелторское Агенство", String144, !"Выбрать", !"Закрыть"); 
    	}
    	else
    	{
			return enter_buisnes(playerid, BUISNES_RIELTOR_AGENCY, b_id);
    	}
    }	
    else 
    {
    	info_realtor_general(playerid, b_id);
    }
    return true;

}

stock select_menu_parking_biz(playerid, b_id)
{
	if(buisness[b_id][buisnes_type] == BUISNES_PARKING)
	{
		if(buisness[b_id][buisnes_owned] == -1)
		{
    		format(String144, sizeof(String144), "\
   	 		"cBLUE"- "cWH"Информация о покупке паркинга");
    		SPD(playerid, DIALOG_SELECT_PARKING_ENTER, DIALOG_STYLE_LIST, !""cBLUE"Паркинг", String144, !"Выбрать", !"Закрыть"); 
    	}
    }	
    else 
    {
    	info_parking_general(playerid, b_id);
    }	
    return true;
}

stock info_parking_general(playerid, b_id)
{
	static 
		b_owner[24];

	if(buisness[b_id][buisnes_owned] != -1)
	{
		GetPlayerNameByID(buisness[b_id][buisnes_owned], buisness[b_id][buisnes_owner]);
		format(b_owner, 24, buisness[b_id][buisnes_owner]);
	}
	else
	{
		format(b_owner, 24, "Государство");	
	}

	if(buisness[b_id][buisnes_type] == BUISNES_PARKING)
	{
		if(buisness[b_id][buisnes_owned] == -1)
		{

			format(String512, sizeof(String512), "\
			"cWH"Номер бизнеса: 	\t"cBLUE"%d\n\
			"cWH"Тип бизнеса:		\t"cBLUE"Паркинг\n\
			"cWH"Владелец: 			\t"cBLUE"%s\n\
			"cWH"Статус: 			\t\t%s\n\
			"cWH"Цена: 				\t"cGR"%d рублей\n\
			"cWH"Ежедневная оплата: \t\t\t"cGR"%d рублей\n\n\
			"cBLUE"Вы действительно хотите купить паркинг?",
			b_id+1,
			b_owner,
			(buisness[b_id][buisnes_owned]) ? (""cGR"Продается") : (""cLRED"Куплен"),
			buisness[b_id][buisnes_price], buisness[b_id][buisnes_takings]);
			SPD(playerid, DIALOG_BUY_PARKING, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка паркинга", String512, !"Купить", !"Закрыть");					
		}
		if(buisness[b_id][buisnes_owned] != -1)
		{
			format(String512, sizeof(String512), "\
			"cWH"Номер бизнеса: 	\t"cBLUE"%d\n\
			"cWH"Тип бизнеса:		\t"cBLUE"Паркинг\n\
			"cWH"Владелец: 			\t"cBLUE"%s\n\
			"cWH"Статус: 			\t\t%s\n\
			"cWH"Цена: 				\t"cGR"%d рублей\n\
			"cWH"Ежедневная оплата: \t\t\t"cGR"%d рублей",
			b_id+1,
			b_owner,
			(buisness[b_id][buisnes_owned]) ? (""cGR"Работает") : (""cLRED"Закрыт"),
			buisness[b_id][buisnes_price], buisness[b_id][buisnes_takings]);
			SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Паркинг", String512, !"Закрыть", !"");		
		}
	}

	return true;
}


stock info_realtor_general(playerid, b_id)
{
	static 
		buisnes_names[24],
		b_owner[24];

	format(buisnes_names, 24, "%s", get_buisnes_realtor(b_id));

	if(buisness[b_id][buisnes_owned] != -1)
	{
		GetPlayerNameByID(buisness[b_id][buisnes_owned], buisness[b_id][buisnes_owner]);
		format(b_owner, 24, buisness[b_id][buisnes_owner]);
	}
	else
	{
		format(b_owner, 24, "Государство");	
	}

	if(buisness[b_id][buisnes_type] == BUISNES_RIELTOR_AGENCY)
	{
		if(buisness[b_id][buisnes_owned] == -1)
		{

			format(String512, sizeof(String512), "\
			"cWH"Номер бизнеса: 	\t"cBLUE"%d\n\
			"cWH"Тип бизнеса:		\t"cBLUE"%s\n\
			"cWH"Владелец: 			\t"cBLUE"%s\n\
			"cWH"Статус: 			\t\t%s\n\
			"cWH"Цена: 				\t"cGR"%d рублей\n\
			"cWH"Ежедневная оплата: \t\t\t"cGR"%d рублей\n\n\
			"cBLUE"Вы действительно хотите купить Риелторское Агенство?",
			b_id+1,
			buisnes_names,
			b_owner,
			(buisness[b_id][buisnes_owned]) ? (""cGR"Продается") : (""cLRED"Куплен"),
			buisness[b_id][buisnes_price], buisness[b_id][buisnes_takings]);
			SPD(playerid, DIALOG_BUY_REALTOR, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка Риелторского Агенства", String512, !"Купить", !"Закрыть");					
		}
		if(buisness[b_id][buisnes_owned] != -1)
		{
			format(String512, sizeof(String512), "\
			"cWH"Номер бизнеса: 	\t"cBLUE"%d\n\
			"cWH"Тип бизнеса:		\t"cBLUE"%s\n\
			"cWH"Владелец: 			\t"cBLUE"%s\n\
			"cWH"Статус: 			\t\t%s\n\
			"cWH"Цена: 				\t"cGR"%d рублей\n\
			"cWH"Ежедневная оплата: \t\t\t"cGR"%d рублей",
			b_id+1,
			buisnes_names,
			b_owner,
			(buisness[b_id][buisnes_owned]) ? (""cGR"Работает") : (""cLRED"Закрыт"),
			buisness[b_id][buisnes_price], buisness[b_id][buisnes_takings]);
			SPD(playerid, DIALOG_INFO_REALTOR, DIALOG_STYLE_MSGBOX, !""cBLUE"Риелторское Агенство", String512, !"Войти", !"Закрыть");		
		}
	}

	return true;
}


stock info_clothes_general(playerid, b_id)
{
	static 
		buisnes_names[24],
		b_owner[24];

	format(buisnes_names, 24, "%s", get_buisnes_clothes_n(b_id));

	if(buisness[b_id][buisnes_owned] != -1)
	{
		GetPlayerNameByID(buisness[b_id][buisnes_owned], buisness[b_id][buisnes_owner]);
		format(b_owner, 24, buisness[b_id][buisnes_owner]);
	}
	else
	{
		format(b_owner, 24, "Государство");	
	}

	if(buisness[b_id][buisnes_type] == BUISNES_CLOTHES)
	{
		if(buisness[b_id][buisnes_owned] == -1)
		{

			format(String512, sizeof(String512), "\
			"cWH"Номер бизнеса: 	\t"cBLUE"%d\n\
			"cWH"Тип бизнеса:		\t"cBLUE"%s\n\
			"cWH"Владелец: 			\t"cBLUE"%s\n\
			"cWH"Статус: 			\t\t%s\n\
			"cWH"Цена: 				\t"cGR"%d рублей\n\
			"cWH"Ежедневная оплата: \t\t\t"cGR"%d рублей\n\n\
			"cBLUE"Вы действительно хотите купить магазин одежды?",
			b_id+1,
			buisnes_names,
			b_owner,
			(buisness[b_id][buisnes_owned]) ? (""cGR"Продается") : (""cLRED"Куплен"),
			buisness[b_id][buisnes_price], buisness[b_id][buisnes_takings]);
			SPD(playerid, DIALOG_BUY_CLOTHES, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка магазина одежды", String512, !"Купить", !"Закрыть");					
		}
		if(buisness[b_id][buisnes_owned] != -1)
		{
			format(String512, sizeof(String512), "\
			"cWH"Номер бизнеса: 	\t"cBLUE"%d\n\
			"cWH"Тип бизнеса:		\t"cBLUE"%s\n\
			"cWH"Владелец: 			\t"cBLUE"%s\n\
			"cWH"Статус: 			\t\t%s\n\
			"cWH"Цена: 				\t"cGR"%d рублей\n\
			"cWH"Ежедневная оплата: \t\t\t"cGR"%d рублей",
			b_id+1,
			buisnes_names,
			b_owner,
			(buisness[b_id][buisnes_owned]) ? (""cGR"Работает") : (""cLRED"Закрыт"),
			buisness[b_id][buisnes_price], buisness[b_id][buisnes_takings]);
			SPD(playerid, DIALOG_INFO_CLOTHES, DIALOG_STYLE_MSGBOX, !""cBLUE"Магазин одежды", String512, !"Войти", !"Закрыть");		
		}
	}
	return true;
}

stock info_autosalon_general(playerid, b_id)
{
	static 
		buisnes_names[24],
		b_owner[24];

	format(buisnes_names, 24, "%s", get_buisnes_autosalon_n[buisness[b_id][buisnes_name]]);

	if(buisness[b_id][buisnes_owned] != -1)
	{
		GetPlayerNameByID(buisness[b_id][buisnes_owned], buisness[b_id][buisnes_owner]);
		format(b_owner, 24, buisness[b_id][buisnes_owner]);
	}
	else
	{
		format(b_owner, 24, "Государство");	
	}

	if(buisness[b_id][buisnes_type] == BUISNES_AUTOSALON_1 || buisness[b_id][buisnes_type] == BUISNES_AUTOSALON_2 || buisness[b_id][buisnes_type] == BUISNES_AUTOSALON_3)
	{
		if(buisness[b_id][buisnes_owned] == -1)
		{

			format(String512, sizeof(String512), "\
			"cWH"Номер бизнеса: 	\t"cBLUE"%d\n\
			"cWH"Тип бизнеса:		\t"cBLUE"%s\n\
			"cWH"Владелец: 			\t"cBLUE"%s\n\
			"cWH"Статус: 			\t\t%s\n\
			"cWH"Цена: 				\t"cGR"%d рублей\n\
			"cWH"Ежедневная оплата: \t\t\t"cGR"%d рублей\n\n\
			"cBLUE"Вы действительно хотите купить автосалон?",
			b_id+1,
			buisnes_names,
			b_owner,
			(buisness[b_id][buisnes_owned]) ? (""cGR"Продается") : (""cLRED"Куплен"),
			buisness[b_id][buisnes_price], buisness[b_id][buisnes_takings]);
			SPD(playerid, DIALOG_BUY_AUTOSALON, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка автосалона", String512, !"Купить", !"Закрыть");					
		}
		if(buisness[b_id][buisnes_owned] != -1)
		{
			format(String512, sizeof(String512), "\
			"cWH"Номер бизнеса: 	\t"cBLUE"%d\n\
			"cWH"Тип бизнеса:		\t"cBLUE"%s\n\
			"cWH"Владелец: 			\t"cBLUE"%s\n\
			"cWH"Статус: 			\t\t%s\n\
			"cWH"Цена: 				\t"cGR"%d рублей\n\
			"cWH"Ежедневная оплата: \t\t\t"cGR"%d рублей",
			b_id+1,
			buisnes_names,
			b_owner,
			(buisness[b_id][buisnes_owned]) ? (""cGR"Работает") : (""cLRED"Закрыт"),
			buisness[b_id][buisnes_price], buisness[b_id][buisnes_takings]);
			SPD(playerid, DIALOG_INFO_AUTOSALON, DIALOG_STYLE_MSGBOX, !""cBLUE"Автосалон", String512, !"Войти", !"Закрыть");		
		}
	}
	return true;
}

stock info_univermag_general(playerid, b_id)
{
	static 
		buisnes_names[24],
		b_owner[24];

	format(buisnes_names, 24, "%s", get_buisnes_univermag_n(b_id));

	if(buisness[b_id][buisnes_owned] != -1)
	{
		GetPlayerNameByID(buisness[b_id][buisnes_owned], buisness[b_id][buisnes_owner]);
		format(b_owner, 24, buisness[b_id][buisnes_owner]);
	}
	else
	{
		format(b_owner, 24, "Государство");	
	}

	if(buisness[b_id][buisnes_type] == BUISNES_PRODUCTION)
	{
		if(buisness[b_id][buisnes_owned] == -1)
		{

			format(String512, sizeof(String512), "\
			"cWH"Номер бизнеса: 	\t"cBLUE"%d\n\
			"cWH"Тип бизнеса:		\t"cBLUE"%s\n\
			"cWH"Владелец: 			\t"cBLUE"%s\n\
			"cWH"Статус: 			\t\t%s\n\
			"cWH"Цена: 				\t"cGR"%d рублей\n\
			"cWH"Ежедневная оплата: \t\t\t"cGR"%d рублей\n\n\
			"cBLUE"Вы действительно хотите купить универмаг?",
			b_id+1,
			buisnes_names,
			b_owner,
			(buisness[b_id][buisnes_owned]) ? (""cGR"Продается") : (""cLRED"Куплен"),
			buisness[b_id][buisnes_price], buisness[b_id][buisnes_takings]);
			SPD(playerid, DIALOG_BUY_UNIVERMAG, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка универмага", String512, !"Купить", !"Закрыть");					
		}
		if(buisness[b_id][buisnes_owned] != -1)
		{
			format(String512, sizeof(String512), "\
			"cWH"Номер бизнеса: 	\t"cBLUE"%d\n\
			"cWH"Тип бизнеса:		\t"cBLUE"%s\n\
			"cWH"Владелец: 			\t"cBLUE"%s\n\
			"cWH"Статус: 			\t\t%s\n\
			"cWH"Цена: 				\t"cGR"%d рублей\n\
			"cWH"Ежедневная оплата: \t\t\t"cGR"%d рублей",
			b_id+1,
			buisnes_names,
			b_owner,
			(buisness[b_id][buisnes_owned]) ? (""cGR"Работает") : (""cLRED"Закрыт"),
			buisness[b_id][buisnes_price], buisness[b_id][buisnes_takings]);
			SPD(playerid, DIALOG_INFO_UNIVERMAG, DIALOG_STYLE_MSGBOX, !""cBLUE"Универмаг", String512, !"Войти", !"Закрыть");		
		}
	}
	return true;
}

stock info_bar_general(playerid, b_id)
{
	static 
		buisnes_names[24],
		b_owner[24];

	format(buisnes_names, 24, "%s", get_buisnes_bar_n(b_id));

	if(buisness[b_id][buisnes_owned] != -1)
	{
		GetPlayerNameByID(buisness[b_id][buisnes_owned], buisness[b_id][buisnes_owner]);
		format(b_owner, 24, buisness[b_id][buisnes_owner]);
	}
	else
	{
		format(b_owner, 24, "Государство");	
	}

	if(buisness[b_id][buisnes_type] == BUISNES_BAR)
	{
		if(buisness[b_id][buisnes_owned] == -1)
		{

			format(String512, sizeof(String512), "\
			"cWH"Номер бизнеса: 	\t"cBLUE"%d\n\
			"cWH"Тип бизнеса:		\t"cBLUE"%s\n\
			"cWH"Владелец: 			\t"cBLUE"%s\n\
			"cWH"Статус: 			\t\t%s\n\
			"cWH"Цена: 				\t"cGR"%d рублей\n\
			"cWH"Ежедневная оплата: \t\t\t"cGR"%d рублей\n\n\
			"cBLUE"Вы действительно хотите купить бар?",
			b_id+1,
			buisnes_names,
			b_owner,
			(buisness[b_id][buisnes_owned]) ? (""cGR"Продается") : (""cLRED"Куплен"),
			buisness[b_id][buisnes_price], buisness[b_id][buisnes_takings]);
			SPD(playerid, DIALOG_BUY_BAR, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка бара", String512, !"Купить", !"Закрыть");					
		}
		if(buisness[b_id][buisnes_owned] != -1)
		{
			format(String512, sizeof(String512), "\
			"cWH"Номер бизнеса: 	\t"cBLUE"%d\n\
			"cWH"Тип бизнеса:		\t"cBLUE"%s\n\
			"cWH"Владелец: 			\t"cBLUE"%s\n\
			"cWH"Статус: 			\t\t%s\n\
			"cWH"Цена: 				\t"cGR"%d рублей\n\
			"cWH"Ежедневная оплата: \t\t\t"cGR"%d рублей",
			b_id+1,
			buisnes_names,
			b_owner,
			(buisness[b_id][buisnes_owned]) ? (""cGR"Работает") : (""cLRED"Закрыт"),
			buisness[b_id][buisnes_price], buisness[b_id][buisnes_takings]);
			SPD(playerid, DIALOG_INFO_BAR, DIALOG_STYLE_MSGBOX, !""cBLUE"Бар", String512, !"Войти", !"Закрыть");		
		}
	}
	return true;
}

stock info_ammo_general(playerid, b_id)
{
	static 
		buisnes_names[24],
		b_owner[24];

	format(buisnes_names, 24, "%s", get_buisnes_ammo_n(b_id));

	if(buisness[b_id][buisnes_owned] != -1)
	{
		GetPlayerNameByID(buisness[b_id][buisnes_owned], buisness[b_id][buisnes_owner]);
		format(b_owner, 24, buisness[b_id][buisnes_owner]);
	}
	else
	{
		format(b_owner, 24, "Государство");	
	}

	if(buisness[b_id][buisnes_type] == BUISNES_AMMO_1 || buisness[b_id][buisnes_type] == BUISNES_AMMO_2)
	{
		if(buisness[b_id][buisnes_owned] == -1)
		{

			format(String512, sizeof(String512), "\
			"cWH"Номер бизнеса: 	\t"cBLUE"%d\n\
			"cWH"Тип бизнеса:		\t"cBLUE"%s\n\
			"cWH"Владелец: 			\t"cBLUE"%s\n\
			"cWH"Статус: 			\t\t%s\n\
			"cWH"Цена: 				\t"cGR"%d рублей\n\
			"cWH"Ежедневная оплата: \t\t\t"cGR"%d рублей\n\n\
			"cBLUE"Вы действительно хотите купить магазин оружия?",
			b_id+1,
			buisnes_names,
			b_owner,
			(buisness[b_id][buisnes_owned]) ? (""cGR"Продается") : (""cLRED"Куплен"),
			buisness[b_id][buisnes_price], buisness[b_id][buisnes_takings]);
			SPD(playerid, DIALOG_BUY_AMMO, DIALOG_STYLE_MSGBOX, !""cBLUE"Магазин оружия", String512, !"Купить", !"Закрыть");					
		}
		if(buisness[b_id][buisnes_owned] != -1)
		{
			format(String512, sizeof(String512), "\
			"cWH"Номер бизнеса: 	\t"cBLUE"%d\n\
			"cWH"Тип бизнеса:		\t"cBLUE"%s\n\
			"cWH"Владелец: 			\t"cBLUE"%s\n\
			"cWH"Статус: 			\t\t%s\n\
			"cWH"Цена: 				\t"cGR"%d рублей\n\
			"cWH"Ежедневная оплата: \t\t\t"cGR"%d рублей",
			b_id+1,
			buisnes_names,
			b_owner,
			(buisness[b_id][buisnes_owned]) ? (""cGR"Работает") : (""cLRED"Закрыт"),
			buisness[b_id][buisnes_price], buisness[b_id][buisnes_takings]);
			SPD(playerid, DIALOG_INFO_AMMO, DIALOG_STYLE_MSGBOX, !""cBLUE"Магазин оружия", String512, !"Войти", !"Закрыть");		
		}
	}
	return true;
}


stock info_restoran_general(playerid, b_id)
{
	static 
		buisnes_names[24],
		b_owner[24];

	format(buisnes_names, 24, "%s", get_buisnes_restoran_n(b_id));

	if(buisness[b_id][buisnes_owned] != -1)
	{
		GetPlayerNameByID(buisness[b_id][buisnes_owned], buisness[b_id][buisnes_owner]);
		format(b_owner, 24, buisness[b_id][buisnes_owner]);
	}
	else
	{
		format(b_owner, 24, "Государство");	
	}

	if(buisness[b_id][buisnes_type] == BUISNES_RESTORAN)
	{
		if(buisness[b_id][buisnes_owned] == -1)
		{

			format(String512, sizeof(String512), "\
			"cWH"Номер бизнеса: 	\t"cBLUE"%d\n\
			"cWH"Тип бизнеса:		\t"cBLUE"%s\n\
			"cWH"Владелец: 			\t"cBLUE"%s\n\
			"cWH"Статус: 			\t\t%s\n\
			"cWH"Цена: 				\t"cGR"%d рублей\n\
			"cWH"Ежедневная оплата: \t\t\t"cGR"%d рублей\n\n\
			"cBLUE"Вы действительно хотите купить ресторан?",
			b_id+1,
			buisnes_names,
			b_owner,
			(buisness[b_id][buisnes_owned]) ? (""cGR"Продается") : (""cLRED"Куплен"),
			buisness[b_id][buisnes_price], buisness[b_id][buisnes_takings]);
			SPD(playerid, DIALOG_BUY_RESTORAN, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка ресторана", String512, !"Купить", !"Закрыть");					
		}
		if(buisness[b_id][buisnes_owned] != -1)
		{
			format(String512, sizeof(String512), "\
			"cWH"Номер бизнеса: 	\t"cBLUE"%d\n\
			"cWH"Тип бизнеса:		\t"cBLUE"%s\n\
			"cWH"Владелец: 			\t"cBLUE"%s\n\
			"cWH"Статус: 			\t\t%s\n\
			"cWH"Цена: 				\t"cGR"%d рублей\n\
			"cWH"Ежедневная оплата: \t\t\t"cGR"%d рублей",
			b_id+1,
			buisnes_names,
			b_owner,
			(buisness[b_id][buisnes_owned]) ? (""cGR"Работает") : (""cLRED"Закрыт"),
			buisness[b_id][buisnes_price], buisness[b_id][buisnes_takings]);
			SPD(playerid, DIALOG_INFO_RESTORAN, DIALOG_STYLE_MSGBOX, !""cBLUE"Ресторан", String512, !"Войти", !"Закрыть");		
		}
	}
	return true;
}


stock info_fastfood_general(playerid, b_id)
{
	static 
		buisnes_names[24],
		b_owner[24];

	format(buisnes_names, 24, "%s", get_buisnes_fastfood_n(b_id));

	if(buisness[b_id][buisnes_owned] != -1)
	{
		GetPlayerNameByID(buisness[b_id][buisnes_owned], buisness[b_id][buisnes_owner]);
		format(b_owner, 24, buisness[b_id][buisnes_owner]);
	}
	else
	{
		format(b_owner, 24, "Государство");	
	}

	if(buisness[b_id][buisnes_type] == BUISNES_FASTFOOD)
	{
		if(buisness[b_id][buisnes_owned] == -1)
		{

			format(String512, sizeof(String512), "\
			"cWH"Номер бизнеса: 	\t"cBLUE"%d\n\
			"cWH"Тип бизнеса:		\t"cBLUE"%s\n\
			"cWH"Владелец: 			\t"cBLUE"%s\n\
			"cWH"Статус: 			\t\t%s\n\
			"cWH"Цена: 				\t"cGR"%d рублей\n\
			"cWH"Ежедневная оплата: \t\t\t"cGR"%d рублей\n\n\
			"cBLUE"Вы действительно хотите купить закусочную?",
			b_id+1,
			buisnes_names,
			b_owner,
			(buisness[b_id][buisnes_owned]) ? (""cGR"Продается") : (""cLRED"Куплен"),
			buisness[b_id][buisnes_price], buisness[b_id][buisnes_takings]);
			SPD(playerid, DIALOG_BUY_FASTFOOD, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка закусочной", String512, !"Купить", !"Закрыть");					
		}
		if(buisness[b_id][buisnes_owned] != -1)
		{
			format(String512, sizeof(String512), "\
			"cWH"Номер бизнеса: 	\t"cBLUE"%d\n\
			"cWH"Тип бизнеса:		\t"cBLUE"%s\n\
			"cWH"Владелец: 			\t"cBLUE"%s\n\
			"cWH"Статус: 			\t\t%s\n\
			"cWH"Цена: 				\t"cGR"%d рублей\n\
			"cWH"Ежедневная оплата: \t\t\t"cGR"%d рублей",
			b_id+1,
			buisnes_names,
			b_owner,
			(buisness[b_id][buisnes_owned]) ? (""cGR"Работает") : (""cLRED"Закрыт"),
			buisness[b_id][buisnes_price], buisness[b_id][buisnes_takings]);
			SPD(playerid, DIALOG_INFO_FASTFOOD, DIALOG_STYLE_MSGBOX, !""cBLUE"Закусочная", String512, !"Войти", !"Закрыть");		
		}
	}
	return true;
}

stock info_club_general(playerid, b_id)
{
	static 
		buisnes_names[24],
		b_owner[24];

	format(buisnes_names, 24, "%s", get_buisnes_club_n(b_id));

	if(buisness[b_id][buisnes_owned] != -1)
	{
		GetPlayerNameByID(buisness[b_id][buisnes_owned], buisness[b_id][buisnes_owner]);
		format(b_owner, 24, buisness[b_id][buisnes_owner]);
	}
	else
	{
		format(b_owner, 24, "Государство");	
	}

	if(buisness[b_id][buisnes_type] == BUISNES_CLUB)
	{
		if(buisness[b_id][buisnes_owned] == -1)
		{

			format(String512, sizeof(String512), "\
			"cWH"Номер бизнеса: 	\t"cBLUE"%d\n\
			"cWH"Тип бизнеса:		\t"cBLUE"%s\n\
			"cWH"Владелец: 			\t"cBLUE"%s\n\
			"cWH"Статус: 			\t\t%s\n\
			"cWH"Цена: 				\t"cGR"%d рублей\n\
			"cWH"Ежедневная оплата: \t\t\t"cGR"%d рублей\n\n\
			"cBLUE"Вы действительно хотите купить клуб?",
			b_id+1,
			buisnes_names,
			b_owner,
			(buisness[b_id][buisnes_owned]) ? (""cGR"Продается") : (""cLRED"Куплен"),
			buisness[b_id][buisnes_price], buisness[b_id][buisnes_takings]);
			SPD(playerid, DIALOG_BUY_CLUB, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка клуба", String512, !"Купить", !"Закрыть");					
		}
		if(buisness[b_id][buisnes_owned] != -1)
		{
			format(String512, sizeof(String512), "\
			"cWH"Номер бизнеса: 	\t"cBLUE"%d\n\
			"cWH"Тип бизнеса:		\t"cBLUE"%s\n\
			"cWH"Владелец: 			\t"cBLUE"%s\n\
			"cWH"Статус: 			\t\t%s\n\
			"cWH"Цена: 				\t"cGR"%d рублей\n\
			"cWH"Ежедневная оплата: \t\t\t"cGR"%d рублей",
			b_id+1,
			buisnes_names,
			b_owner,
			(buisness[b_id][buisnes_owned]) ? (""cGR"Работает") : (""cLRED"Закрыт"),
			buisness[b_id][buisnes_price], buisness[b_id][buisnes_takings]);
			SPD(playerid, DIALOG_INFO_CLUB, DIALOG_STYLE_MSGBOX, !""cBLUE"Клуб", String512, !"Войти", !"Закрыть");		
		}
	}
	return true;
}

stock show_buisnes_select_info(playerid, type, b_id)
{
	switch(type)
	{
		case BUISNES_PRODUCTION:
		{
			if(buisness[b_id][buisnes_owned] == -1)
			{
		    	format(String256, sizeof(String256), "\
		   	 	"cBLUE"- "cWH"Информация о покупке универмага\n\
		    	"cBLUE"- "cWH"Войти в универмаг");
		    	SPD(playerid, DIALOG_SELECT_ENTER_BIZ_TYPE_1, DIALOG_STYLE_LIST, !""cBLUE"Вход в универмаг", String256, !"Выбрать", !"Закрыть"); 
		    }
		    else return show_buisnes_info(playerid, BUISNES_PRODUCTION, b_id);

		}
		case BUISNES_BAR:
		{
			if(buisness[b_id][buisnes_owned] == -1)
			{
		    	format(String256, sizeof(String256), "\
		   	 	"cBLUE"- "cWH"Информация о покупке бара\n\
		    	"cBLUE"- "cWH"Войти в бар");
		    	SPD(playerid, DIALOG_SELECT_ENTER_BIZ_TYPE_2, DIALOG_STYLE_LIST, !""cBLUE"Вход в бар", String256, !"Выбрать", !"Закрыть"); 
		    }
		    else return show_buisnes_info(playerid, BUISNES_BAR, b_id);
		}
		case BUISNES_AMMO_1:
		{
			if(buisness[b_id][buisnes_owned] == -1)
			{
		    	format(String256, sizeof(String256), "\
		   	 	"cBLUE"- "cWH"Информация о покупке магазина оружия\n\
		    	"cBLUE"- "cWH"Войти в магазин оружия");
		    	SPD(playerid, DIALOG_SELECT_ENTER_BIZ_TYPE_3, DIALOG_STYLE_LIST, !""cBLUE"Вход в магазин оружия", String256, !"Выбрать", !"Закрыть"); 
		    }
		    else return show_buisnes_info(playerid, BUISNES_AMMO_1, b_id);
		}
		case BUISNES_AMMO_2:
		{
			if(buisness[b_id][buisnes_owned] == -1)
			{
		    	format(String256, sizeof(String256), "\
		   	 	"cBLUE"- "cWH"Информация о покупке магазина оружия\n\
		    	"cBLUE"- "cWH"Войти в магазин оружия");
		    	SPD(playerid, DIALOG_SELECT_ENTER_BIZ_TYPE_3, DIALOG_STYLE_LIST, !""cBLUE"Вход в магазин оружия", String256, !"Выбрать", !"Закрыть"); 
		    }
		    else return show_buisnes_info(playerid, BUISNES_AMMO_2, b_id);
		}
		case BUISNES_RESTORAN:
		{
			if(buisness[b_id][buisnes_owned] == -1)
			{
		    	format(String256, sizeof(String256), "\
		   	 	"cBLUE"- "cWH"Информация о покупке ресторана\n\
		    	"cBLUE"- "cWH"Войти в ресторан");
		    	SPD(playerid, DIALOG_SELECT_ENTER_BIZ_TYPE_4, DIALOG_STYLE_LIST, !""cBLUE"Вход в ресторан", String256, !"Выбрать", !"Закрыть"); 
		    }
		    else return show_buisnes_info(playerid, BUISNES_RESTORAN, b_id);
		}
		case BUISNES_FASTFOOD:
		{
			if(buisness[b_id][buisnes_owned] == -1)
			{
		    	format(String256, sizeof(String256), "\
		   	 	"cBLUE"- "cWH"Информация о покупке закусочной\n\
		    	"cBLUE"- "cWH"Войти в закусочную");
		    	SPD(playerid, DIALOG_SELECT_ENTER_BIZ_TYPE_5, DIALOG_STYLE_LIST, !""cBLUE"Вход в закусочную", String256, !"Выбрать", !"Закрыть"); 
		    }
		    else return show_buisnes_info(playerid, BUISNES_FASTFOOD, b_id);
		}
		case BUISNES_CLUB:
		{
			if(buisness[b_id][buisnes_owned] == -1)
			{
		    	format(String256, sizeof(String256), "\
		   	 	"cBLUE"- "cWH"Информация о покупке клуба\n\
		    	"cBLUE"- "cWH"Войти в клуб");
		    	SPD(playerid, DIALOG_SELECT_ENTER_BIZ_TYPE_6, DIALOG_STYLE_LIST, !""cBLUE"Вход в клуб", String256, !"Выбрать", !"Закрыть"); 
		    }
		    else return show_buisnes_info(playerid, BUISNES_CLUB, b_id);
		}
	}	
	return true;
}

stock show_buisnes_info(playerid, type, b_id)
{

	switch(type)
	{
		case BUISNES_PRODUCTION:
		{
			info_univermag_general(playerid, b_id);
		}
		case BUISNES_BAR:
		{
			info_bar_general(playerid, b_id);
		}
		case BUISNES_AMMO_1:
		{
			info_ammo_general(playerid, b_id);
		}
		case BUISNES_AMMO_2:
		{
			info_ammo_general(playerid, b_id);
		}
		case BUISNES_RESTORAN:
		{
			info_restoran_general(playerid, b_id);
		}
		case BUISNES_FASTFOOD:
		{
			info_fastfood_general(playerid, b_id);
		}
		case BUISNES_CLUB:
		{
			info_club_general(playerid, b_id);
		}
	}


	return true;
}

stock enter_buisnes(playerid, type, b_id)
{

	switch(type)
	{
		case BUISNES_AMMO_1:
		{
			SetPlayerPosEx(playerid, 9.9426,15.5443,1601.7458,359.7251);

			pTemp[playerid][pSelectedBusinessID] = b_id;
			SetPlayerVirtualWorld(playerid, b_id);

			SetPVarIntNew(playerid, "buisnes_enter_type", BUISNES_AMMO_1);
			SetPVarIntNew(playerid, "buisnes_enter_id", b_id);	
		}
		case BUISNES_AMMO_2:
		{
			SetPlayerPosEx(playerid, 9.9426,15.5443,1601.7458,359.7251);

			pTemp[playerid][pSelectedBusinessID] = b_id;
			SetPlayerVirtualWorld(playerid, b_id);

			SetPVarIntNew(playerid, "buisnes_enter_type", BUISNES_AMMO_2);
			SetPVarIntNew(playerid, "buisnes_enter_id", b_id);
		}
		case BUISNES_AUTOSALON_1:
		{
			SetPlayerPosEx(playerid, MAGAZINE_CAR_1_ENTER);
			SetPlayerVirtualWorld(playerid, 10);	

			SetPlayerTime(playerid, 19, 0);	
			
			SetPVarIntNew(playerid, "buisnes_enter_type", BUISNES_AUTOSALON_1);
			SetPVarIntNew(playerid, "buisnes_enter_id", b_id);

		}
		case BUISNES_AUTOSALON_2:
		{
			SetPlayerPosEx(playerid, MAGAZINE_CAR_2_ENTER);
			SetPlayerVirtualWorld(playerid, 10);		

			SetPlayerTime(playerid, 19, 0);
			
			SetPVarIntNew(playerid, "buisnes_enter_type", BUISNES_AUTOSALON_2);
			SetPVarIntNew(playerid, "buisnes_enter_id", b_id);

		}
		case BUISNES_AUTOSALON_3:
		{
			SetPlayerPosEx(playerid, MAGAZINE_CAR_3_ENTER);
			SetPlayerVirtualWorld(playerid, 10);		

			SetPlayerTime(playerid, 20, 0);
			
			SetPVarIntNew(playerid, "buisnes_enter_type", BUISNES_AUTOSALON_3);
			SetPVarIntNew(playerid, "buisnes_enter_id", b_id);

		}
		case BUISNES_PRODUCTION:
		{
			SetPlayerPosEx(playerid, BUISNES_PRODUCTION_ENTER);
			SetPlayerVirtualWorld(playerid, b_id);
			SendInf(playerid, "Добро пожаловать в продуктовый магазин!");

			SetPVarIntNew(playerid, "buisnes_enter_type", BUISNES_PRODUCTION);
			SetPVarIntNew(playerid, "buisnes_enter_id", b_id);
		}
		case BUISNES_BAR:
		{
			//SetPlayerPosEx(playerid, POSITION_BAR);
			SetPlayerVirtualWorld(playerid, b_id);

			SendInf(playerid, "Добро пожаловать в бар!");

			SetPVarIntNew(playerid, "buisnes_enter_type", BUISNES_BAR);
			SetPVarIntNew(playerid, "buisnes_enter_id", b_id);			
		}
		case BUISNES_RESTORAN:
		{
			SetPVarIntNew(playerid, "buisnes_enter_type", BUISNES_RESTORAN);
			SetPVarIntNew(playerid, "buisnes_enter_id", b_id);				
			SendInf(playerid, "Добро пожаловать в ресторан!");

			SetPlayerTime(playerid, 12, 0);

			SetPlayerPosEx(playerid, ENTER_FASTFOOD);
			SetPlayerVirtualWorld(playerid, b_id);

		}
		case BUISNES_FASTFOOD:
		{
			SetPVarIntNew(playerid, "buisnes_enter_type", BUISNES_FASTFOOD);
			SetPVarIntNew(playerid, "buisnes_enter_id", b_id);				
			SendInf(playerid, "Добро пожаловать в закусочную!");

			SetPlayerTime(playerid, 12, 0);

			SetPlayerPosEx(playerid, ENTER_FASTFOOD);
			SetPlayerVirtualWorld(playerid, b_id);
		}
		case BUISNES_CLUB:
		{
			SetPlayerPosEx(playerid, 141.3583,-1171.4988,1200.6801,0.9098);

			SetPVarIntNew(playerid, "buisnes_enter_type", BUISNES_CLUB);
			SetPVarIntNew(playerid, "buisnes_enter_id", b_id);			
			SendInf(playerid, "Добро пожаловать в клуб!");

			SetPlayerVirtualWorld(playerid, b_id);
		}
		case BUISNES_CLOTHES:
		{
			SetPVarIntNew(playerid, "buisnes_enter_type", BUISNES_CLOTHES);
			SetPVarIntNew(playerid, "buisnes_enter_id", b_id);				

			SetPlayerTime(playerid, 12, 0);

			SetPlayerPosEx(playerid, MAGAZING_CLOTHES_1_ENTER);
			SetPlayerVirtualWorld(playerid, b_id);	
		}
		case BUISNES_ACCESSORIES:
		{
			SetPVarIntNew(playerid, "buisnes_enter_type", BUISNES_ACCESSORIES);
			SetPVarIntNew(playerid, "buisnes_enter_id", b_id);				

			SetPlayerTime(playerid, 20, 0);

			SetPlayerPosEx(playerid, MAGAZIN_AKS_1_ENTER);
			SetPlayerVirtualWorld(playerid, b_id);			
		}
		case BUISNES_RIELTOR_AGENCY:
		{
			if(GetPlayerMoneyEx(playerid) < buisness[b_id][buisnes_enterprice])
				return SendErr(playerid, "Недостаточно денег для входа!");

			SetPVarIntNew(playerid, "buisnes_enter_type", BUISNES_RIELTOR_AGENCY);
			SetPVarIntNew(playerid, "buisnes_enter_id", b_id);		

			give_money(playerid, -buisness[b_id][buisnes_enterprice], "Вход в Риелторское Агенство");

			SetPlayerTime(playerid, 20, 0);

			SetPlayerPosEx(playerid, 1097.3052,308.3914,1205.0166,90.0240);
			SetPlayerVirtualWorld(playerid, b_id);	

			buy_buisnes_all(BUISNES_RIELTOR_AGENCY, GetPVarIntNew(playerid, "buisnes_enter_id"), buisness[b_id][buisnes_enterprice]);


		}
	}



	return true;
}

stock exit_buisnes(playerid, type, b_id)
{

	switch(type)
	{
		case BUISNES_PRODUCTION:
		{
			SetPlayerPosEx(playerid, buisness[b_id][buisnes_enter_x], buisness[b_id][buisnes_enter_y], buisness[b_id][buisnes_enter_z], 90.0);
			SetPlayerVirtualWorld(playerid, 0);

		}
		case BUISNES_BAR:
		{
			SetPlayerPosEx(playerid, buisness[b_id][buisnes_enter_x], buisness[b_id][buisnes_enter_y], buisness[b_id][buisnes_enter_z], 90.0);
			SetPlayerVirtualWorld(playerid, 0);
			
		}
		case BUISNES_AMMO_1:
		{
			SetPlayerPosEx(playerid, buisness[b_id][buisnes_enter_x], buisness[b_id][buisnes_enter_y], buisness[b_id][buisnes_enter_z], 90.0);
			SetPlayerVirtualWorld(playerid, 0);
			
		}
		case BUISNES_AMMO_2:
		{
			SetPlayerPosEx(playerid, buisness[b_id][buisnes_enter_x], buisness[b_id][buisnes_enter_y], buisness[b_id][buisnes_enter_z], 90.0);
			SetPlayerVirtualWorld(playerid, 0);
			
		}
		case BUISNES_RESTORAN:
		{
			SetPlayerPosEx(playerid, buisness[b_id][buisnes_enter_x], buisness[b_id][buisnes_enter_y], buisness[b_id][buisnes_enter_z], 90.0);
			SetPlayerVirtualWorld(playerid, 0);
			
			new 
				hour, minute;

			gettime(hour, minute);

			SetPlayerTime(playerid, hour, minute);

		}
		case BUISNES_FASTFOOD:
		{
			SetPlayerPosEx(playerid, buisness[b_id][buisnes_enter_x], buisness[b_id][buisnes_enter_y], buisness[b_id][buisnes_enter_z], 90.0);
			SetPlayerVirtualWorld(playerid, 0);
		
			new 
				hour, minute;

			gettime(hour, minute);

			SetPlayerTime(playerid, hour, minute);

		}
		case BUISNES_CLUB:
		{
			SetPlayerPosEx(playerid, buisness[b_id][buisnes_enter_x], buisness[b_id][buisnes_enter_y], buisness[b_id][buisnes_enter_z], 90.0);
			SetPlayerVirtualWorld(playerid, 0);
			
		}
		case BUISNES_AUTOSALON_1:
		{
			SetPlayerPosEx(playerid, buisness[b_id][buisnes_enter_x], buisness[b_id][buisnes_enter_y], buisness[b_id][buisnes_enter_z], 90.0);
			SetPlayerVirtualWorld(playerid, 0);

			new 
				hour, minute;

			gettime(hour, minute);

			SetPlayerTime(playerid, hour, minute);



			
		}
		case BUISNES_AUTOSALON_2:
		{
			new 
				hour, minute;

			gettime(hour, minute);

			SetPlayerTime(playerid, hour, minute);

			SetPlayerPosEx(playerid, buisness[b_id][buisnes_enter_x], buisness[b_id][buisnes_enter_y], buisness[b_id][buisnes_enter_z], 90.0);
			SetPlayerVirtualWorld(playerid, 0);
			
		}
		case BUISNES_AUTOSALON_3:
		{
			new 
				hour, minute;

			gettime(hour, minute);

			SetPlayerTime(playerid, hour, minute);

			SetPlayerPosEx(playerid, buisness[b_id][buisnes_enter_x], buisness[b_id][buisnes_enter_y], buisness[b_id][buisnes_enter_z], 90.0);
			SetPlayerVirtualWorld(playerid, 0);
			
		}
		case BUISNES_CLOTHES:
		{
			new 
				hour, minute;

			gettime(hour, minute);

			SetPlayerTime(playerid, hour, minute);

			SetPlayerPosEx(playerid, buisness[b_id][buisnes_enter_x], buisness[b_id][buisnes_enter_y], buisness[b_id][buisnes_enter_z], 90.0);
			SetPlayerVirtualWorld(playerid, 0);
			
		}
		case BUISNES_ACCESSORIES:
		{
			new 
				hour, minute;

			gettime(hour, minute);

			SetPlayerTime(playerid, hour, minute);

			SetPlayerPosEx(playerid, buisness[b_id][buisnes_enter_x], buisness[b_id][buisnes_enter_y], buisness[b_id][buisnes_enter_z], 90.0);
			SetPlayerVirtualWorld(playerid, 0);			
		}
		case BUISNES_RIELTOR_AGENCY:
		{
			new 
				hour, minute;

			gettime(hour, minute);

			SetPlayerTime(playerid, hour, minute);

			SetPlayerPosEx(playerid, buisness[b_id][buisnes_enter_x], buisness[b_id][buisnes_enter_y], buisness[b_id][buisnes_enter_z], 90.0);
			SetPlayerVirtualWorld(playerid, 0);			
		}

	}

	clear_pvar_buisnes(playerid);

	return true;
}

stock clear_pvar_buisnes(playerid)
{
	DeletePVarNew(playerid, "buisnes_enter_type");
	DeletePVarNew(playerid, "buisnes_enter_id");
	return true;
}

stock buy_buisnes_all(type, b_id, sum)
{

	switch(type)
	{
		case BUISNES_PRODUCTION:
		{
			buisness_bank_update(b_id, sum, "Покупка в магазине");
		}
		case BUISNES_BAR:
		{
			buisness_bank_update(b_id, sum, "Покупка в баре");
		}
		case BUISNES_AMMO_1:
		{
			buisness_bank_update(b_id, sum, "Покупка в магазине оружия");
		}
		case BUISNES_AMMO_2:
		{ 
			buisness_bank_update(b_id, sum, "Покупка в магазине оружия");
		}		
		case BUISNES_RESTORAN:
		{
			buisness_bank_update(b_id, sum, "Покупка в ресторане");
		}
		case BUISNES_FASTFOOD:
		{
			buisness_bank_update(b_id, sum, "Покупка в закусочной");
		}
		case BUISNES_CLUB:
		{
			buisness_bank_update(b_id, sum, "Покупка в клубе");
		}
		case BUISNES_CLOTHES:
		{
			buisness_bank_update(b_id, sum, "Покупка в магазине одежды");
		}
		case BUISNES_ACCESSORIES:
		{
			buisness_bank_update(b_id, sum, "Покупка в магазине аксессуаров");
		}
		case VEHICLE_AUTOSALON_1:
		{
			buisness_bank_update(b_id, sum, "Аренда автомобиля");
		}
		case VEHICLE_AUTOSALON_2:
		{
			buisness_bank_update(b_id, sum, "Аренда автомобиля");
		}
		case VEHICLE_AUTOSALON_3:
		{	
			buisness_bank_update(b_id, sum, "Аренда автомобиля");
		}
		case BUISNES_RIELTOR_AGENCY:
		{
			buisness_bank_update(b_id, sum, "Услуги агенства");
		}
		case BUISNES_PARKING:
		{
			buisness_bank_update(b_id, sum, "Услуги паркинга");
		}
	}

	return true;
}

stock dialog_all_buisnes(playerid, dialogid, response, listitem, inputtext[])
{

	switch(dialogid)
	{
		case DIALOG_CLUB_BUY_MENU_BAR:
		{
			if(!response)
				return true;

			switch(listitem)
			{
				case 0:
				{
					if(GetPlayerMoneyEx(playerid) < 340)
					{
						show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
						return SendErr(playerid, "У вас недостаточно денежных средств!");
					}

					buy_buisnes_all(BUISNES_CLUB, GetPVarIntNew(playerid, "buisnes_enter_id"), 340);
					buisness[GetPVarIntNew(playerid, "buisnes_enter_id")][buisnes_count_prod] -= 1;

					give_money(playerid, -340, "Виски");

					SendSucc(playerid, "Вы купили коктейль \"Виски-кола\"");
				}
				case 1:
				{
					if(GetPlayerMoneyEx(playerid) < 150)
					{
						show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
						return SendErr(playerid, "У вас недостаточно денежных средств!");
					}

					buy_buisnes_all(BUISNES_CLUB, GetPVarIntNew(playerid, "buisnes_enter_id"), 150);
					buisness[GetPVarIntNew(playerid, "buisnes_enter_id")][buisnes_count_prod] -= 1;

					give_money(playerid, -150, "Водка");

					SendSucc(playerid, "Вы купили Водку 100 мл");
				}
				case 2:
				{
					if(GetPlayerMoneyEx(playerid) < 350)
					{
						show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
						return SendErr(playerid, "У вас недостаточно денежных средств!");
					}

					give_money(playerid, -350, "Пина Колада");

					buy_buisnes_all(BUISNES_CLUB, GetPVarIntNew(playerid, "buisnes_enter_id"), 350);
					buisness[GetPVarIntNew(playerid, "buisnes_enter_id")][buisnes_count_prod] -= 1;

					SendSucc(playerid, "Вы купили коктейль \"Пина Колада\"");
				}
				case 3:
				{
					if(GetPlayerMoneyEx(playerid) < 380)
					{
						show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
						return SendErr(playerid, "У вас недостаточно денежных средств!");
					}

					buy_buisnes_all(BUISNES_CLUB, GetPVarIntNew(playerid, "buisnes_enter_id"), 380);
					buisness[GetPVarIntNew(playerid, "buisnes_enter_id")][buisnes_count_prod] -= 1;

					give_money(playerid, -380, "Мохито");

					SendSucc(playerid, "Вы купили коктейль \"Мохито\"");
				}
				case 4:
				{
					if(GetPlayerMoneyEx(playerid) < 320)
					{
						show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
						return SendErr(playerid, "У вас недостаточно денежных средств!");
					}

					buy_buisnes_all(BUISNES_CLUB, GetPVarIntNew(playerid, "buisnes_enter_id"), 320);
					buisness[GetPVarIntNew(playerid, "buisnes_enter_id")][buisnes_count_prod] -= 1;

					give_money(playerid, -320, "Кровавая Мэри");

					SendSucc(playerid, "Вы купили коктейль \"Кровавая Мэри\"");
				}
				case 5:
				{
					if(GetPlayerMoneyEx(playerid) < 300)
					{
						show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
						return SendErr(playerid, "У вас недостаточно денежных средств!");
					}

					buy_buisnes_all(BUISNES_CLUB, GetPVarIntNew(playerid, "buisnes_enter_id"), 300);
					buisness[GetPVarIntNew(playerid, "buisnes_enter_id")][buisnes_count_prod] -= 1;

					give_money(playerid, -300, "Текила Бум");

					SendSucc(playerid, "Вы купили коктейль \"Текила Бум\"");
				}
			}
			return 1;			
		}
		case DIALOG_START_SELECT_CLOTHES_1:
		{
			if(!response)
				return true;	

			return start_select_clothes_shop(playerid, BUISNES_CLOTHES);			
		}
		case DIALOG_SELECT_AKS:
		{
			if(!response)
				return true;

			switch(listitem)
			{
				case 0:
				{
					start_select_aks_shop(playerid, BUISNES_ACCESSORIES, 0);
				}
				case 1:
				{
					start_select_aks_shop(playerid, BUISNES_ACCESSORIES, 1);
				}
				case 2:
				{
					start_select_aks_shop(playerid, BUISNES_ACCESSORIES, 2);
				}
			}
		}
		case DIALOG_START_SELECT_CAR_1:
		{
			if(!response)
				return true;	

			return start_select_vehicle_shop(playerid, BUISNES_AUTOSALON_1);
		}
		case DIALOG_START_SELECT_CAR_2:
		{
			if(!response)
				return true;	

			return start_select_vehicle_shop(playerid, BUISNES_AUTOSALON_2);
		}
		case DIALOG_START_SELECT_CAR_3:
		{
			if(!response)
				return true;	

			return start_select_vehicle_shop(playerid, BUISNES_AUTOSALON_3);
		}		
		case DIALOG_START_SELECT_RENT_CAR_1:
		{
			if(!response)
				return true;	

			return select_vehicle_rent_autosalon(playerid, BUISNES_AUTOSALON_1);
		}
		case DIALOG_START_SELECT_RENT_CAR_2:
		{
			if(!response)
				return true;	

			return select_vehicle_rent_autosalon(playerid, BUISNES_AUTOSALON_2);
		}
		case DIALOG_START_SELECT_RENT_CAR_3:
		{
			if(!response)
				return true;	

			return select_vehicle_rent_autosalon(playerid, BUISNES_AUTOSALON_3);
		}
		case DIALOG_SELECT_TYPE_BUY_CAR:
		{
			if(!response)
				return true;

			switch(listitem)
			{
				case 0: buy_car_autosalon(playerid);
				case 1: buy_autosalon_family_car(playerid);
			}
		}
		case DIALOG_SELECT_RENT_C_SALON_1:
		{
			if(!response)
				return true;

			switch(listitem)
			{
				case 0: return rent_car_autosalon_1(playerid, MiddleVehicles[0]);
				case 1: return rent_car_autosalon_1(playerid, MiddleVehicles[1]);
				case 2: return rent_car_autosalon_1(playerid, MiddleVehicles[2]);
				case 3: return rent_car_autosalon_1(playerid, MiddleVehicles[3]);
				case 4: return rent_car_autosalon_1(playerid, MiddleVehicles[4]);
				case 5: return rent_car_autosalon_1(playerid, MiddleVehicles[5]);
				case 6: return rent_car_autosalon_1(playerid, MiddleVehicles[6]);
				case 7: return rent_car_autosalon_1(playerid, MiddleVehicles[7]);
				case 8: return rent_car_autosalon_1(playerid, MiddleVehicles[8]);
				case 9: return rent_car_autosalon_1(playerid, MiddleVehicles[9]);
				case 10: return select_vehicle_rent_autosalon(playerid, BUISNES_AUTOSALON_1);
				case 11: return select_vehicle_rent_autosalon(playerid, BUISNES_AUTOSALON_1);
			}	
		}
		case DIALOG_SELECT_RENT_C_SALON_2:
		{
			if(!response)
				return true;

			switch(listitem)
			{
				case 0: return rent_car_autosalon_2(playerid, EliteVehicles[0]);
				case 1: return rent_car_autosalon_2(playerid, EliteVehicles[1]);
				case 2: return rent_car_autosalon_2(playerid, EliteVehicles[2]);
				case 3: return rent_car_autosalon_2(playerid, EliteVehicles[3]);
				case 4: return rent_car_autosalon_2(playerid, EliteVehicles[4]);
				case 5: return rent_car_autosalon_2(playerid, EliteVehicles[5]);
				case 6: return rent_car_autosalon_2(playerid, EliteVehicles[6]);
				case 7: return rent_car_autosalon_2(playerid, EliteVehicles[7]);
				case 8: return rent_car_autosalon_2(playerid, EliteVehicles[8]);
				case 9: return rent_car_autosalon_2(playerid, EliteVehicles[9]);				
				case 10: return select_vehicle_rent_autosalon(playerid, BUISNES_AUTOSALON_2);
				case 11: return select_vehicle_rent_autosalon(playerid, BUISNES_AUTOSALON_2);
			}
		}
		case DIALOG_SELECT_RENT_C_SALON_3:
		{
			if(!response)
				return true;

			switch(listitem)
			{
				case 0: return rent_car_autosalon_3(playerid, EkonomVehicles[0]);
				case 1: return rent_car_autosalon_3(playerid, EkonomVehicles[1]);
				case 2: return rent_car_autosalon_3(playerid, EkonomVehicles[2]);
				case 3: return rent_car_autosalon_3(playerid, EkonomVehicles[3]);
				case 4: return rent_car_autosalon_3(playerid, EkonomVehicles[4]);
				case 5: return rent_car_autosalon_3(playerid, EkonomVehicles[5]);
				case 6: return rent_car_autosalon_3(playerid, EkonomVehicles[6]);
				case 7: return rent_car_autosalon_3(playerid, EkonomVehicles[7]);
				case 8: return rent_car_autosalon_3(playerid, EkonomVehicles[8]);
				case 10: return select_vehicle_rent_autosalon(playerid, BUISNES_AUTOSALON_3);
				case 11: return select_vehicle_rent_autosalon(playerid, BUISNES_AUTOSALON_3);
			}
		}
		case DIALOG_INFO_BIZ_PANEL:
		{
			if(!response)
				return panel_change_general_biz(playerid);			
				
			return panel_change_general_biz(playerid);	
		}
		case DIALOG_CHANGE_PANEL_BIZ:
		{
			if(!response)
				return true;

			switch(listitem)
			{
				case 0: return info_biz_panel_change(playerid);
				case 1: return show_order_prod_biz(playerid);
				case 2: return change_statistic_buisnes(playerid);
				case 3: return change_bank_biz(playerid);
				case 4: return sell_buisnes_accept(playerid);
				case 5: return update_buisnes_prod_action(playerid);
			}			

		}
		case DIALOG_CHANGE_PANEL_BIZ_R:
		{
			if(!response)
				return true;

			switch(listitem)
			{
				case 0: return info_biz_panel_change(playerid);
				case 1: return show_change_price_enter(playerid);
				case 2: return change_statistic_buisnes(playerid);
				case 3: return change_bank_biz(playerid);
				case 4: return sell_buisnes_accept(playerid);
				case 5: return update_buisnes_prod_action(playerid);
			}				
		}
		case DIALOG_CHANGE_PANEL_BIZ_P:
		{
			if(!response)
				return true;

			switch(listitem)
			{
				case 0: return info_biz_panel_change(playerid);
				case 1: return change_statistic_buisnes(playerid);
				case 2: return change_bank_biz(playerid);
				case 3: return sell_buisnes_accept(playerid);
				case 4: return update_buisnes_prod_action(playerid);
			}			
		}
		case DIALOG_ACCEPT_SELL_BUISNES:
		{
			if(!response)
				return panel_change_general_biz(playerid);		

			new 
				biz_id = pData[playerid][pBusiness];

			sell_biz(playerid, biz_id);				
		}
		case DIALOG_CHANGE_CASSA_BIZ:
		{
			if(!response)
				return true;

			switch(listitem)
			{
				case 0: return change_bank_biz_input(playerid);
				case 1: return change_bank_biz_put(playerid);
			}			

		}
		case DIALOG_INPUT_MONEY_BANK_BIZ:
		{
			new 
				biz_id = pData[playerid][pBusiness];

			if(!response)
				return change_bank_biz(playerid);

			if(!IsNumeric(inputtext) || !strlen(inputtext))
			{
				SendErr(playerid,"Вы указали неверное количество денег!");
				return change_bank_biz_input(playerid);		
			}

			new 
				count_money_input = strval(inputtext);


			if(count_money_input < 1)
			{
				SendErr(playerid,"У вас недостаточно денежных средств в кассе!");
				return change_bank_biz_input(playerid);				
			}

			if(buisness[biz_id][buisnes_bank] < count_money_input)
			{
				SendErr(playerid,"У вас недостаточно денег в кассе бизнеса!");
				return change_bank_biz_input(playerid);				
			}

			buisness[biz_id][buisnes_bank] -= count_money_input;

			give_money(playerid, count_money_input, "Деньги из кассы бизнеса");

			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы взяли из кассы бизнеса - "cGR"%d рублей"cWH"", count_money_input);	

			change_bank_biz(playerid);

			save_biz(biz_id);

		}
		case DIALOG_PUT_MONEY_BANK_BIZ:
		{
			new 
				biz_id = pData[playerid][pBusiness];

			if(!response)
				return change_bank_biz(playerid);

			if(!IsNumeric(inputtext) || !strlen(inputtext))
			{
				SendErr(playerid,"Вы указали неверное количество денег!");
				return change_bank_biz_put(playerid);		
			}

			new 
				count_money_input = strval(inputtext);


			if(count_money_input < 1)
			{
				SendErr(playerid,"У вас недостаточно денежных средств в кассе!");
				return change_bank_biz_put(playerid);				
			}

			if(GetPlayerMoneyEx(playerid) < count_money_input)
			{
				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
				SendErr(playerid,"У вас недостаточно денег!");
				return change_bank_biz_put(playerid);				
			}

			buisness[biz_id][buisnes_bank] += count_money_input;

		 	format(String144, sizeof(String144), "Деньги в кассу бизнеса №%d", biz_id);
			give_money(playerid, -count_money_input, String144);

			SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы положили деньги в кассу бизнеса - "cGR"%d рублей"cWH"", count_money_input);	

			change_bank_biz(playerid);

			save_biz(biz_id);

		}
		case DIALOG_SELECT_ENTER_AUTOSALON:
		{
			if(!response)
				return true;

			new 
				h_id = pTemp[playerid][area_item_id];

			switch(listitem)
			{
				case 0: return info_autosalon_general(playerid, h_id);
				case 1: 
				{
					if(buisness[h_id][buisnes_type] == BUISNES_AUTOSALON_1)
					{
						return enter_buisnes(playerid, BUISNES_AUTOSALON_1, h_id);
					}
					if(buisness[h_id][buisnes_type] == BUISNES_AUTOSALON_2)
					{
						return enter_buisnes(playerid, BUISNES_AUTOSALON_2, h_id);
					}
					if(buisness[h_id][buisnes_type] == BUISNES_AUTOSALON_3)
					{
						return enter_buisnes(playerid, BUISNES_AUTOSALON_3, h_id);
					}						
				}
			}			
		}
		case DIALOG_SELECT_ENTER_AKS:
		{
			if(!response)
				return true;

			new 
				h_id = pTemp[playerid][area_item_id];

			switch(listitem)
			{
				case 0: return info_aks_general(playerid, h_id);
				case 1: 
				{
					if(buisness[h_id][buisnes_type] == BUISNES_ACCESSORIES)
					{
						return enter_buisnes(playerid, BUISNES_ACCESSORIES, h_id);
					}				
				}
			}			
		}
		case DIALOG_BUY_AKS_SHOP:
		{
			if(!response)
				return true;	

			new 
				id_autosalon = pTemp[playerid][area_item_id];


			buy_aks_biz(playerid, id_autosalon);				
		}
		case DIALOG_SELECT_ENTER_CLOTHES:
		{

			if(!response)
				return true;

			new 
				h_id = pTemp[playerid][area_item_id];

			switch(listitem)
			{
				case 0: return info_clothes_general(playerid, h_id);
				case 1: 
				{
					if(buisness[h_id][buisnes_type] == BUISNES_CLOTHES)
					{
						return enter_buisnes(playerid, BUISNES_CLOTHES, h_id);
					}				
				}
			}

		}
		case DIALOG_SELECT_ENTER_REALTOR:
		{
			if(!response)
				return true;

			new 
				h_id = pTemp[playerid][area_item_id];

			switch(listitem)
			{
				case 0: return info_realtor_general(playerid, h_id);
				case 1:
				{
					if(buisness[h_id][buisnes_type] == BUISNES_RIELTOR_AGENCY)
					{
						return enter_buisnes(playerid, BUISNES_RIELTOR_AGENCY, h_id);
					}
				}
			}
		}
		case DIALOG_SELECT_PARKING_ENTER:
		{
			if(!response)
				return true;

			new 
				h_id = pTemp[playerid][area_item_id];

			switch(listitem)
			{
				case 0: return info_parking_general(playerid, h_id);
			}			
		}
		case DIALOG_BUY_REALTOR:
		{
			if(!response)
				return true;	

			new 
				id_autosalon = pTemp[playerid][area_item_id];


			buy_realtor_biz(playerid, id_autosalon);				
		}
		case DIALOG_BUY_PARKING:
		{
			if(!response)
				return true;	

			new 
				id_autosalon = pTemp[playerid][area_item_id];


			buy_parking_biz(playerid, id_autosalon);				
		}
		case DIALOG_BUY_CLOTHES:
		{
			if(!response)
				return true;	

			new 
				id_autosalon = pTemp[playerid][area_item_id];


			buy_clothes_biz(playerid, id_autosalon);				
		}
		case DIALOG_BUY_CLOTHES_FINAL:
		{
			if(!response)
				return SelectTextDraw(playerid, COLOR_BLUE);

			buy_skin_accept_final(playerid);					
		}
		case DIALOG_BUY_AKS_FINAL:
		{
			if(!response)
				return SelectTextDraw(playerid, COLOR_BLUE);

			buy_aks_accept_final(playerid);				
		}
		case DIALOG_BUY_AKS_PREW:
		{
			if(!response)
				return SelectTextDraw(playerid, COLOR_BLUE);

			buy_aks_player_prew(playerid);				
		}
		case DIALOG_BUY_CLOTHES_PREW:
		{
			if(!response)
				return SelectTextDraw(playerid, COLOR_BLUE);

			buy_skin_player_prew(playerid);					
		}
		case DIALOG_INFO_CLOTHES:
		{
			if(!response)
				return true;	
			new 
				id_autosalon = pTemp[playerid][area_item_id];

			if(buisness[id_autosalon][buisnes_lock] == 2)
			{
				GameTextForPlayer(playerid, "~r~closed", 2000, 3);
				info_clothes_general(playerid, id_autosalon);
				return SendInf(playerid, "Двери магазина - закрыты. Вы не можете войти!");
			}

			if(buisness[id_autosalon][buisnes_type] == BUISNES_CLOTHES)
			{
				return enter_buisnes(playerid, BUISNES_CLOTHES, id_autosalon);
			}
		}
		case DIALOG_INFO_REALTOR:
		{
			if(!response)
				return true;

			new 
				id_autosalon = pTemp[playerid][area_item_id];

			if(buisness[id_autosalon][buisnes_lock] == 2)
			{
				GameTextForPlayer(playerid, "~r~closed", 2000, 3);
				info_realtor_general(playerid, id_autosalon);
				return SendInf(playerid, "Двери агенства - закрыты. Вы не можете войти!");
			}

			if(buisness[id_autosalon][buisnes_type] == BUISNES_RIELTOR_AGENCY)
			{
				return enter_buisnes(playerid, BUISNES_RIELTOR_AGENCY, id_autosalon);
			}
		}
		case DIALOG_INFO_AKS_SHOP:
		{
			if(!response)
				return true;	
			new 
				id_autosalon = pTemp[playerid][area_item_id];

			if(buisness[id_autosalon][buisnes_lock] == 2)
			{
				GameTextForPlayer(playerid, "~r~closed", 2000, 3);
				info_clothes_general(playerid, id_autosalon);
				return SendInf(playerid, "Двери магазина - закрыты. Вы не можете войти!");
			}

			if(buisness[id_autosalon][buisnes_type] == BUISNES_ACCESSORIES)
			{
				return enter_buisnes(playerid, BUISNES_ACCESSORIES, id_autosalon);
			}
		}
		case DIALOG_BUY_AUTOSALON:
		{
			if(!response)
				return true;	

			new 
				id_autosalon = pTemp[playerid][area_item_id];


			buy_autosalon_biz(playerid, id_autosalon);			
		}
		case DIALOG_INFO_AUTOSALON:
		{
			if(!response)
				return true;	
			new 
				id_autosalon = pTemp[playerid][area_item_id];

			if(buisness[id_autosalon][buisnes_lock] == 2)
			{
				GameTextForPlayer(playerid, "~r~closed", 2000, 3);
				info_autosalon_general(playerid, id_autosalon);
				return SendInf(playerid, "Двери автосалона - закрыты. Вы не можете войти!");
			}

			if(buisness[id_autosalon][buisnes_type] == BUISNES_AUTOSALON_1)
			{
				return enter_buisnes(playerid, BUISNES_AUTOSALON_1, id_autosalon);
			}
			if(buisness[id_autosalon][buisnes_type] == BUISNES_AUTOSALON_2)
			{
				return enter_buisnes(playerid, BUISNES_AUTOSALON_2, id_autosalon);
			}	
			if(buisness[id_autosalon][buisnes_type] == BUISNES_AUTOSALON_3)
			{
				return enter_buisnes(playerid, BUISNES_AUTOSALON_3, id_autosalon);
			}	
		}
		case DIALOG_BUY_UNIVERMAG:
		{
			if(!response)
				return true;	

			new 
				id_univermag = pTemp[playerid][area_item_id];


			buy_univermag_biz(playerid, id_univermag);
		}
		case DIALOG_INFO_UNIVERMAG:
		{
			if(!response)
				return true;	
			new 
				id_univermag = pTemp[playerid][area_item_id];

			if(buisness[id_univermag][buisnes_lock] == 2)
			{
				GameTextForPlayer(playerid, "~r~closed", 2000, 3);
				info_univermag_general(playerid, id_univermag);
				return SendInf(playerid, "Двери универмага - закрыты. Вы не можете войти!");
			}

			enter_buisnes(playerid, BUISNES_PRODUCTION, id_univermag);
		}

		case DIALOG_BUY_BAR:
		{
			if(!response)
				return true;	

			new 
				id_buisness = pTemp[playerid][area_item_id];


			buy_bar_biz(playerid, id_buisness);
		}
		case DIALOG_INFO_BAR:
		{
			if(!response)
				return true;	
			new 
				id_buisness = pTemp[playerid][area_item_id];

			if(buisness[id_buisness][buisnes_lock] == 2)
			{
				GameTextForPlayer(playerid, "~r~closed", 2000, 3);
				info_bar_general(playerid, id_buisness);
				return SendInf(playerid, "Двери бара - закрыты. Вы не можете войти!");
			}

			enter_buisnes(playerid, BUISNES_BAR, id_buisness);
		}

		case DIALOG_BUY_AMMO:
		{
			if(!response)
				return true;	

			new 
				id_buisness = pTemp[playerid][area_item_id];


			buy_ammo_biz(playerid, id_buisness);
		}
		case DIALOG_INFO_AMMO:
		{
			if(!response)
				return true;	
			new 
				id_buisness = pTemp[playerid][area_item_id];

			if(buisness[id_buisness][buisnes_lock] == 2)
			{
				GameTextForPlayer(playerid, "~r~closed", 2000, 3);
				info_bar_general(playerid, id_buisness);
				return SendInf(playerid, "Двери магазина оружия - закрыты. Вы не можете войти!");
			}
			if(buisness[id_buisness][buisnes_type] == BUISNES_AMMO_1)
			{
				return enter_buisnes(playerid, BUISNES_AMMO_1, id_buisness);
			}
			if(buisness[id_buisness][buisnes_type] == BUISNES_AMMO_2)
			{
				return enter_buisnes(playerid, BUISNES_AMMO_2, id_buisness);
			}	
		}

		case DIALOG_BUY_RESTORAN:
		{
			if(!response)
				return true;	

			new 
				id_buisness = pTemp[playerid][area_item_id];


			buy_restoran_biz(playerid, id_buisness);
		}
		case DIALOG_INFO_RESTORAN:
		{
			if(!response)
				return true;	
			new 
				id_buisness = pTemp[playerid][area_item_id];

			if(buisness[id_buisness][buisnes_lock] == 2)
			{
				GameTextForPlayer(playerid, "~r~closed", 2000, 3);
				info_bar_general(playerid, id_buisness);
				return SendInf(playerid, "Двери ресторана - закрыты. Вы не можете войти!");
			}

			enter_buisnes(playerid, BUISNES_RESTORAN, id_buisness);
		}


		case DIALOG_BUY_FASTFOOD:
		{
			if(!response)
				return true;	

			new 
				id_buisness = pTemp[playerid][area_item_id];


			buy_fastfood_biz(playerid, id_buisness);
		}
		case DIALOG_INFO_FASTFOOD:
		{
			if(!response)
				return true;	
			new 
				id_buisness = pTemp[playerid][area_item_id];

			if(buisness[id_buisness][buisnes_lock] == 2)
			{
				GameTextForPlayer(playerid, "~r~closed", 2000, 3);
				info_bar_general(playerid, id_buisness);
				return SendInf(playerid, "Двери закусочной - закрыты. Вы не можете войти!");
			}

			enter_buisnes(playerid, BUISNES_FASTFOOD, id_buisness);
		}


		case DIALOG_BUY_CLUB:
		{
			if(!response)
				return true;	

			new 
				id_buisness = pTemp[playerid][area_item_id];


			buy_club_biz(playerid, id_buisness);
		}
		case DIALOG_INFO_CLUB:
		{
			if(!response)
				return true;	
			new 
				id_buisness = pTemp[playerid][area_item_id];

			if(buisness[id_buisness][buisnes_lock] == 2)
			{
				GameTextForPlayer(playerid, "~r~closed", 2000, 3);
				info_bar_general(playerid, id_buisness);
				return SendInf(playerid, "Двери ночного клуба - закрыты. Вы не можете войти!");
			}

			enter_buisnes(playerid, BUISNES_CLUB, id_buisness);
		}

		case DIALOG_SELECT_ENTER_BIZ_TYPE_1:
		{
			if(!response)
				return true;	

			new 
				b_id = pTemp[playerid][area_item_id];

			switch(listitem)
			{
				case 0: return show_buisnes_info(playerid, BUISNES_PRODUCTION, b_id);
				case 1: return enter_buisnes(playerid, BUISNES_PRODUCTION, b_id);
			}
		}
		case DIALOG_SELECT_ENTER_BIZ_TYPE_2:
		{
			if(!response)
				return true;	

			new 
				b_id = pTemp[playerid][area_item_id];

			switch(listitem)
			{
				case 0: return show_buisnes_info(playerid, BUISNES_BAR, b_id);
				case 1: return enter_buisnes(playerid, BUISNES_BAR, b_id);
			}
		}
		case DIALOG_SELECT_ENTER_BIZ_TYPE_3:
		{
			if(!response)
				return true;	

			new 
				b_id = pTemp[playerid][area_item_id];

			switch(listitem)
			{
				case 0:
				{
					if(buisness[b_id][buisnes_type] == BUISNES_AMMO_1)
					{
						return show_buisnes_info(playerid, BUISNES_AMMO_1, b_id);
					}
					if(buisness[b_id][buisnes_type] == BUISNES_AMMO_2)
					{
						return show_buisnes_info(playerid, BUISNES_AMMO_2, b_id);
					}	
				}
				case 1:
				{
					if(buisness[b_id][buisnes_type] == BUISNES_AMMO_1)
					{
						return enter_buisnes(playerid, BUISNES_AMMO_1, b_id);
					}
					if(buisness[b_id][buisnes_type] == BUISNES_AMMO_2)
					{
						return enter_buisnes(playerid, BUISNES_AMMO_2, b_id);
					}	
				}
			}
		}
		case DIALOG_SELECT_ENTER_BIZ_TYPE_4:
		{
			if(!response)
				return true;	

			new 
				b_id = pTemp[playerid][area_item_id];

			switch(listitem)
			{
				case 0: return show_buisnes_info(playerid, BUISNES_RESTORAN, b_id);
				case 1: return enter_buisnes(playerid, BUISNES_RESTORAN, b_id);
			}
		}
		case DIALOG_SELECT_ENTER_BIZ_TYPE_5:
		{
			if(!response)
				return true;	

			new 
				b_id = pTemp[playerid][area_item_id];

			switch(listitem)
			{
				case 0: return show_buisnes_info(playerid, BUISNES_FASTFOOD, b_id);
				case 1: return enter_buisnes(playerid, BUISNES_FASTFOOD, b_id);
			}
		}
		case DIALOG_SELECT_ENTER_BIZ_TYPE_6:
		{
			if(!response)
				return true;	

			new 
				b_id = pTemp[playerid][area_item_id];

			switch(listitem)
			{
				case 0: return show_buisnes_info(playerid, BUISNES_CLUB, b_id);
				case 1: return enter_buisnes(playerid, BUISNES_CLUB, b_id);
			}
		}
		case DIALOG_PANEL_BUISNES_CONTROL:
		{
			if(!response)
				return true;	

			switch(listitem)
			{
				case 0: return show_order_prod_biz(playerid);
				case 1: return change_statistic_buisnes(playerid);
			}			
		}
		case DIALOG_BUY_PROD_ORDER:
		{
			if(!response)
				return PC_EmulateCommand(playerid, "/buisnes");

			new 
				f = pData[playerid][pBusiness];


			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное значение!");
				return show_order_prod_biz(playerid);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное значение!");
				return show_order_prod_biz(playerid);
			}	

			new 
				count_fill_order = strval(inputtext);	

			new 
				fill_final_count_order = MAX_PROD_STOCK-buisness[f][buisnes_count_prod];

			if(count_fill_order < 1 || count_fill_order > fill_final_count_order)
			{
			   SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"От "cGR"1"cWH" товара и до "cGR"%d"cWH" товаров");	
			   return show_order_prod_biz(playerid);
			}		

		    format(String144, sizeof(String144), "INSERT INTO magazinorders(magazin_id, count_orders) VALUES ('%d', '%d')",
		    f, count_fill_order);
		    sql_queryEx(zConn, String144, QUERY_THREADED);

		    SendSucc(playerid, "Вы успешно заказали товары в свой бизнес!");					
		}
		case DIALOG_CHANGE_BIZ_ENTER_PRICE:
		{
			if(!response)
				return PC_EmulateCommand(playerid, "/buisnes");

			new 
				f = pData[playerid][pBusiness];

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное значение!");
				return show_change_price_enter(playerid);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное значение!");
				return show_change_price_enter(playerid);
			}	

			new 
				price_enter_biz = strval(inputtext);

			if(price_enter_biz < 2000 || price_enter_biz > 15000)
			{
			   SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"От "cGR"2000"cWH" рублей и до "cGR"15000"cWH" рублей");	
			   return show_change_price_enter(playerid);
			}											

			buisness[f][buisnes_enterprice] = price_enter_biz;

			save_biz(playerid);

			SendSucc(playerid, "Цена на вход в Риелторское Агенство успешно изменена!");	
		}
		case DIALOG_CHANGE_BIZ_RENT_PRICE:
		{
			if(!response)
				return PC_EmulateCommand(playerid, "/buisnes");

			new 
				f = pData[playerid][pBusiness];

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное значение!");
				return show_change_price_rent(playerid);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное значение!");
				return show_change_price_rent(playerid);
			}	

			new 
				price_enter_biz = strval(inputtext);

			if(price_enter_biz < 1000 || price_enter_biz > 2500)
			{
			   SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"От "cGR"1000"cWH" рублей и до "cGR"2500"cWH" рублей");	
			   return show_change_price_rent(playerid);
			}											

			buisness[f][buisnes_price_day_rent] = price_enter_biz;

			save_biz(playerid);

			SendSucc(playerid, "Цена на аренду парковочного места была успешно изменена!");				
		}
	}
	return true;
}

stock show_order_prod_biz(playerid)
{	

	if(pData[playerid][pBusiness] == -1)
		return SendErr(playerid, "Вы не владеете бизнесом!");

	new 
		biz_id = pData[playerid][pBusiness];

	format(String144, sizeof(String144), "SELECT * FROM magazinorders WHERE magazin_id = '%d' LIMIT 1", biz_id);
	new Result:fill_orders = sql_queryEx(zConn, String144, QUERY_CACHED);


	if(sql_num_rows(fill_orders)) 
	{
		PC_EmulateCommand(playerid, "/buisnes");
		return SendErr(playerid, "Вы уже заказывали доставку товаров!");
	}

	new 
		fill_final_count_order = MAX_PROD_STOCK-buisness[biz_id][buisnes_count_prod];
		
	format(String256, sizeof(String256), "\
	"cWH"Текущая стоимость закупки товаров: "cGR"%d"cWH" рублей\n\n\
	"cWH"Вы можете заказать максимум "cBLUE"%d"cWH" товара\n\n\
	"cBLUE"Сколько хотите закупить?",PRICE_BUY_FUEL_DELIVERY, fill_final_count_order);
	SPD(playerid, DIALOG_BUY_PROD_ORDER, DIALOG_STYLE_INPUT, !""cBLUE"Покупка товара", String256, !"Далее", !"Назад");

	return true;
}

stock show_change_price_enter(playerid)
{

	if(pData[playerid][pBusiness] == -1)
		return SendErr(playerid, "Вы не владеете бизнесом!");

	new 
		biz_id = pData[playerid][pBusiness];

	format(String256, sizeof(String256), "\
	"cWH"Текущая стоимость входа: "cGR"%d"cWH" рублей\n\n\
	"cBLUE"Введите новую стоимость входа от 2 до 15 тысяч", buisness[biz_id][buisnes_enterprice]);
	SPD(playerid, DIALOG_CHANGE_BIZ_ENTER_PRICE, DIALOG_STYLE_INPUT, !""cBLUE"Стоимость входа", String256, !"Далее", !"Назад");


	return true;
}

stock show_change_price_rent(playerid)
{
	if(pData[playerid][pBusiness] == -1)
		return SendErr(playerid, "Вы не владеете бизнесом!");

	new 
		biz_id = pData[playerid][pBusiness];

	format(String256, sizeof(String256), "\
	"cWH"Текущая стоимость аренды: "cGR"%d"cWH" рублей\n\n\
	"cBLUE"Введите новую стоимость входа от 1 тысяч до 2500 тысячи", buisness[biz_id][buisnes_price_day_rent]);
	SPD(playerid, DIALOG_CHANGE_BIZ_RENT_PRICE, DIALOG_STYLE_INPUT, !""cBLUE"Стоимость аренды", String256, !"Далее", !"Назад");


	return true;	
}

alias:buisnes("busines", "business");
CMD:buisnes(playerid)
{
	if(pData[playerid][pBusiness] == -1)
		return SendErr(playerid, "Вы не владеете бизнесом!");



    panel_change_general_biz(playerid);

    return true;
}

stock update_buisnes_prod_action(playerid)
{
	if(pData[playerid][pBusiness] == -1)
		return SendErr(playerid, "Вы не владеете бизнесом!");

	new 
		f = pData[playerid][pBusiness];

	buisness[f][buisnes_count_prod] = 15000;
	save_biz(f);
	return true;
}

stock sell_buisnes_accept(playerid)
{
	SPD(playerid, DIALOG_ACCEPT_SELL_BUISNES, DIALOG_STYLE_MSGBOX, !""cBLUE"Продажа бизнеса", !"\
	"cWH"Вы уверены, что хотите продать бизнес государству?\n\n\
	Вам будет возвращено 80% от стоимости!", !"Да", !"Нет");

	return true;

}

stock sell_biz(playerid, f)
{

	new 
		final_money = floatround(buisness[f][buisnes_price]*0.8);

	pData[playerid][pBusiness] = -1;
	UpdatePlayerData(playerid,"bussiness", pData[playerid][pBusiness]);

	SendSucc(playerid, "Вы продали бизнес государству!");

 	format(String144, sizeof(String144), "Продажа бизнеса №%d", f);
	give_money(playerid, final_money, String144);


	buisness[f][buisnes_owned] = -1;	
	buisness[f][buisnes_bank] = 0;
	update_biz_text();
	save_biz(f);


	return true;
}

stock sell_buisness_payday(f)
{
	new 
		owner_id = buisness[f][buisnes_owned];

	new 
		owner_garage_name[32];


	GetPlayerNameByID(owner_id, owner_garage_name);

	new 
		player_id = GetPlayerID(owner_garage_name);	

	new 
		final_money = floatround(buisness[f][buisnes_price]*0.8);


	if(IsPlayerConnected(player_id))
	{
		if(pData[player_id][pBusiness] == f)
		{	
			pData[player_id][pBusiness] = -1;
			UpdatePlayerData(player_id,"bussiness", pData[player_id][pBusiness]);
			SFCM(player_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Ваш бизнес был продан за неуплату!");	

	        SendClientMessage(player_id, COLOR_LIGHTRED, "Вы можете вернуть 80 процентов от стоимости имущества");
	        SendClientMessage(player_id, COLOR_LIGHTRED, "Для этого введите команду /returnmoney");

	        pData[player_id][pReturnMoney] += final_money;
	        if(pData[player_id][pReturnMoney] > 20000000 ) pData[player_id][pReturnMoney] = 0;
		}
	}
	else
	{	
		new 
			formate_str[280];

		format(formate_str, 80, "UPDATE accounts SET bussiness = '-1' WHERE bussiness = '%d'", owner_id);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	

		format(String256,sizeof(String256),"UPDATE `accounts` SET returnmoney = returnmoney + %d WHERE id = '%i'", final_money, owner_id);
		mysql_tquery(connect_main, String256);

		send_off_message(-1, owner_garage_name, "Ваш бизнес был продан государству за неуплату. Мы вернули 80 процентов (/returnmoney)");
	}




	buisness[f][buisnes_owned] = -1;	
	buisness[f][buisnes_bank] = 0;

	buisness[f][buisnes_status_sell] = 3;
	buisness[f][buisnes_sell_day_payday] = RandomEx(2, 22);	

	update_biz_text();
	save_biz(f);
	return true;
}

stock sell_buisness_admin2(f)
{
	new 
		owner_id = buisness[f][buisnes_owned];

	new 
		owner_garage_name[32];


	GetPlayerNameByID(owner_id, owner_garage_name);

	new 
		player_id = GetPlayerID(owner_garage_name);	

	new 
		final_money = floatround(buisness[f][buisnes_price]*0.8);


	if(IsPlayerConnected(player_id))
	{
		if(pData[player_id][pBusiness] == f)
		{	
			pData[player_id][pBusiness] = -1;
			UpdatePlayerData(player_id,"bussiness", pData[player_id][pBusiness]);
			SFCM(player_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Ваш бизнес был продан за неуплату!");	

	        SendClientMessage(player_id, COLOR_LIGHTRED, "Вы можете вернуть 80 процентов от стоимости имущества");
	        SendClientMessage(player_id, COLOR_LIGHTRED, "Для этого введите команду /returnmoney");

	        pData[player_id][pReturnMoney] += final_money;
	        if(pData[player_id][pReturnMoney] > 20000000 ) pData[player_id][pReturnMoney] = 0;
		}
	}
	else
	{	
		new 
			formate_str[280];

		format(formate_str, 80, "UPDATE accounts SET bussiness = '-1' WHERE bussiness = '%d'", owner_id);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	

		format(String256,sizeof(String256),"UPDATE `accounts` SET returnmoney = returnmoney + %d WHERE id = '%i'", final_money, owner_id);
		mysql_tquery(connect_main, String256);

		send_off_message(-1, owner_garage_name, "Ваш бизнес был продан государству за неуплату. Мы вернули 80 процентов (/returnmoney)");
	}




	buisness[f][buisnes_owned] = -1;	
	buisness[f][buisnes_bank] = 0;



	update_biz_text();
	save_biz(f);
	return true;
}

stock sell_buisness_admin3(f, count_payday)
{
	new 
		owner_id = buisness[f][buisnes_owned];

	new 
		owner_garage_name[32];


	GetPlayerNameByID(owner_id, owner_garage_name);

	new 
		player_id = GetPlayerID(owner_garage_name);	

	new 
		final_money = floatround(buisness[f][buisnes_price]*0.8);


	if(IsPlayerConnected(player_id))
	{
		if(pData[player_id][pBusiness] == f)
		{	
			pData[player_id][pBusiness] = -1;
			UpdatePlayerData(player_id,"bussiness", pData[player_id][pBusiness]);
			SFCM(player_id,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Ваш бизнес был продан за неуплату!");	

	        SendClientMessage(player_id, COLOR_LIGHTRED, "Вы можете вернуть 80 процентов от стоимости имущества");
	        SendClientMessage(player_id, COLOR_LIGHTRED, "Для этого введите команду /returnmoney");

	        pData[player_id][pReturnMoney] += final_money;
	        if(pData[player_id][pReturnMoney] > 20000000 ) pData[player_id][pReturnMoney] = 0;
		}
	}
	else
	{	
		new 
			formate_str[280];

		format(formate_str, 80, "UPDATE accounts SET bussiness = '-1' WHERE bussiness = '%d'", owner_id);
		sql_queryEx(zConn, formate_str, QUERY_THREADED);	

		format(String256,sizeof(String256),"UPDATE `accounts` SET returnmoney = returnmoney + %d WHERE id = '%i'", final_money, owner_id);
		mysql_tquery(connect_main, String256);

		send_off_message(-1, owner_garage_name, "Ваш бизнес был продан государству за неуплату. Мы вернули 80 процентов (/returnmoney)");
	}




	buisness[f][buisnes_owned] = -1;	
	buisness[f][buisnes_bank] = 0;


	buisness[f][buisnes_status_sell] = 3;
	buisness[f][buisnes_sell_day_payday] = count_payday;	


	update_biz_text();
	save_biz(f);
	return true;
}

stock buy_autosalon_biz(playerid, h)
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


	if(buisness[h][buisnes_sell_day_payday] >= 0)
		return SendErr(playerid, "Вы не можете приобрести бизнес, так как пока он не доступен для продажи и опечатан!");

	if(GetPlayerMoneyEx(playerid) < buisness[h][buisnes_price]) 
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
		return SendErr(playerid,"У вас недостаточно денежных средств для покупки бизнеса!");	
	}


	if(buisness[h][buisnes_owned] != -1)
		return SendErr(playerid, "Бизнес недоступен для покупки!");

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_buy_biz", 4000);

	buisness[h][buisnes_owned] = pData[playerid][pMysqlID];

	format(buisness[h][buisnes_owner], 24, pData[playerid][pNickname]);

	buisness[h][buisnes_days] = 3;

	pData[playerid][pBusiness] = h;

	UpdatePlayerData(playerid,"bussiness",pData[playerid][pBusiness]);	

 	format(String144, sizeof(String144), "Покупка автосалона №%d", h);
	give_money(playerid, -buisness[h][buisnes_price], String144);


	save_biz(h);
	update_biz_text();

	format(String512, sizeof(String512), "\
		"cWH"Поздравляем Вас с приобретением Автосалона!\n\n\
		Вы купили автосалон "cBLUE"№%d\n\
		"cWH"Ежедневная оплата: "cGR"%d"cWH" рублей\n\n\
		"cWH"Автосалон оплачен на "cBLUE"%d"cWH" дней\n\
		Советутем Вам посетить банк для оплаты!",
		pData[playerid][pBusiness],
		buisness[h][buisnes_takings], buisness[h][buisnes_days]);
	return SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка автосалона", String512, !"Понял", !"");	
}

stock buy_aks_biz(playerid, h)
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

	if(buisness[h][buisnes_sell_day_payday] >= 0)
		return SendErr(playerid, "Вы не можете приобрести бизнес, так как пока он не доступен для продажи и опечатан!");

	if(GetPlayerMoneyEx(playerid) < buisness[h][buisnes_price]) 
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
		return SendErr(playerid,"У вас недостаточно денежных средств для покупки бизнеса!");	
	}
	

	if(buisness[h][buisnes_owned] != -1)
		return SendErr(playerid, "Бизнес недоступен для покупки!");

	buisness[h][buisnes_owned] = pData[playerid][pMysqlID];

	format(buisness[h][buisnes_owner], 24, pData[playerid][pNickname]);

	buisness[h][buisnes_days] = 3;

	pData[playerid][pBusiness] = h;

	UpdatePlayerData(playerid,"bussiness",pData[playerid][pBusiness]);	

 	format(String144, sizeof(String144), "Покупка в магазина аксессуаров №%d", h);
	give_money(playerid, -buisness[h][buisnes_price], String144);

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_buy_biz", 4000);

	save_biz(h);
	update_biz_text();

	format(String512, sizeof(String512), "\
		"cWH"Поздравляем Вас с приобретением Магазина Аксессуаров!\n\n\
		Вы купили магазин "cBLUE"№%d\n\
		"cWH"Ежедневная оплата: "cGR"%d"cWH" рублей\n\n\
		"cWH"Магазин оплачен на "cBLUE"%d"cWH" дней\n\
		Советутем Вам посетить банк для оплаты!",
		pData[playerid][pBusiness],
		buisness[h][buisnes_takings], buisness[h][buisnes_days]);
	return SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка магазина аксессуаров", String512, !"Понял", !"");		
}

stock buy_realtor_biz(playerid, h)
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

	if(buisness[h][buisnes_sell_day_payday] >= 0)
		return SendErr(playerid, "Вы не можете приобрести бизнес, так как пока он не доступен для продажи и опечатан!");

	if(buisness[h][buisnes_owned] != -1)
		return SendErr(playerid, "Бизнес недоступен для покупки!");

	if(GetPlayerMoneyEx(playerid) < buisness[h][buisnes_price]) 
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
		return SendErr(playerid,"У вас недостаточно денежных средств для покупки бизнеса!");	
	}
	


	buisness[h][buisnes_owned] = pData[playerid][pMysqlID];

	format(buisness[h][buisnes_owner], 24, pData[playerid][pNickname]);

	buisness[h][buisnes_days] = 3;

	pData[playerid][pBusiness] = h;

	UpdatePlayerData(playerid,"bussiness",pData[playerid][pBusiness]);	

 	format(String144, sizeof(String144), "Покупка Риелторского Агенства №%d", h);
	give_money(playerid, -buisness[h][buisnes_price], String144);

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_buy_biz", 4000);

	save_biz(h);
	update_biz_text();

	format(String512, sizeof(String512), "\
		"cWH"Поздравляем Вас с приобретением Риелторского Агенства\n\n\
		Вы купили агенство "cBLUE"№%d\n\
		"cWH"Ежедневная оплата: "cGR"%d"cWH" рублей\n\n\
		"cWH"Магазин оплачен на "cBLUE"%d"cWH" дней\n\
		Советутем Вам посетить банк для оплаты!",
		pData[playerid][pBusiness],
		buisness[h][buisnes_takings], buisness[h][buisnes_days]);
	return SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка Риелторского Агенства", String512, !"Понял", !"");	

}

stock buy_parking_biz(playerid, h)
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

	if(buisness[h][buisnes_sell_day_payday] >= 0)
		return SendErr(playerid, "Вы не можете приобрести бизнес, так как пока он не доступен для продажи и опечатан!");

	if(buisness[h][buisnes_owned] != -1)
		return SendErr(playerid, "Бизнес недоступен для покупки!");

	if(GetPlayerMoneyEx(playerid) < buisness[h][buisnes_price]) 
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
		return SendErr(playerid,"У вас недостаточно денежных средств для покупки бизнеса!");	
	}
	


	buisness[h][buisnes_owned] = pData[playerid][pMysqlID];

	format(buisness[h][buisnes_owner], 24, pData[playerid][pNickname]);

	buisness[h][buisnes_days] = 3;

	pData[playerid][pBusiness] = h;

	UpdatePlayerData(playerid,"bussiness",pData[playerid][pBusiness]);	

 	format(String144, sizeof(String144), "Покупка Риелторского Агенства №%d", h);
	give_money(playerid, -buisness[h][buisnes_price], String144);

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_buy_biz", 4000);

	save_biz(h);
	update_biz_text();

	format(String512, sizeof(String512), "\
		"cWH"Поздравляем Вас с приобретением паркинга\n\n\
		Вы купили паркинг "cBLUE"№%d\n\
		"cWH"Ежедневная оплата: "cGR"%d"cWH" рублей\n\n\
		"cWH"Магазин оплачен на "cBLUE"%d"cWH" дней\n\
		Советутем Вам посетить банк для оплаты!",
		pData[playerid][pBusiness],
		buisness[h][buisnes_takings], buisness[h][buisnes_days]);
	return SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка паркинга", String512, !"Понял", !"");	

}

stock buy_clothes_biz(playerid, h)
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

	if(buisness[h][buisnes_sell_day_payday] >= 0)
		return SendErr(playerid, "Вы не можете приобрести бизнес, так как пока он не доступен для продажи и опечатан!");

	if(buisness[h][buisnes_owned] != -1)
		return SendErr(playerid, "Бизнес недоступен для покупки!");

	if(GetPlayerMoneyEx(playerid) < buisness[h][buisnes_price]) 
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
		return SendErr(playerid,"У вас недостаточно денежных средств для покупки бизнеса!");	
	}
	


	buisness[h][buisnes_owned] = pData[playerid][pMysqlID];

	format(buisness[h][buisnes_owner], 24, pData[playerid][pNickname]);

	buisness[h][buisnes_days] = 3;

	pData[playerid][pBusiness] = h;

	UpdatePlayerData(playerid,"bussiness",pData[playerid][pBusiness]);	

 	format(String144, sizeof(String144), "Покупка в магазина одежды №%d", h);
	give_money(playerid, -buisness[h][buisnes_price], String144);

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_buy_biz", 4000);

	save_biz(h);
	update_biz_text();

	format(String512, sizeof(String512), "\
		"cWH"Поздравляем Вас с приобретением Магазина Одежды!\n\n\
		Вы купили магазин "cBLUE"№%d\n\
		"cWH"Ежедневная оплата: "cGR"%d"cWH" рублей\n\n\
		"cWH"Магазин оплачен на "cBLUE"%d"cWH" дней\n\
		Советутем Вам посетить банк для оплаты!",
		pData[playerid][pBusiness],
		buisness[h][buisnes_takings], buisness[h][buisnes_days]);
	return SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка магазина одежды", String512, !"Понял", !"");	
}

stock buy_univermag_biz(playerid, h)
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

	if(buisness[h][buisnes_sell_day_payday] >= 0)
		return SendErr(playerid, "Вы не можете приобрести бизнес, так как пока он не доступен для продажи и опечатан!");


	if(buisness[h][buisnes_owned] != -1)
		return SendErr(playerid, "Бизнес недоступен для покупки!");

	if(GetPlayerMoneyEx(playerid) < buisness[h][buisnes_price]) 
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
		return SendErr(playerid,"У вас недостаточно денежных средств для покупки бизнеса!");	
	}
	


	buisness[h][buisnes_owned] = pData[playerid][pMysqlID];

	format(buisness[h][buisnes_owner], 24, pData[playerid][pNickname]);

	buisness[h][buisnes_days] = 3;

	pData[playerid][pBusiness] = h;

	UpdatePlayerData(playerid,"bussiness",pData[playerid][pBusiness]);	

 	format(String144, sizeof(String144), "Покупка в Универмага №%d", h);
	give_money(playerid, -buisness[h][buisnes_price], String144);

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_buy_biz", 4000);

	save_biz(h);
	update_biz_text();

	format(String512, sizeof(String512), "\
		"cWH"Поздравляем Вас с приобретением Универмага!\n\n\
		Вы купили универмаг "cBLUE"№%d\n\
		"cWH"Ежедневная оплата: "cGR"%d"cWH" рублей\n\n\
		"cWH"Универмаг оплачен на "cBLUE"%d"cWH" дней\n\
		Советутем Вам посетить банк для оплаты!",
		pData[playerid][pBusiness],
		buisness[h][buisnes_takings], buisness[h][buisnes_days]);
	return SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка универмага", String512, !"Понял", !"");
}

stock buy_bar_biz(playerid, h)
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


	if(buisness[h][buisnes_owned] != -1)
		return SendErr(playerid, "Бизнес недоступен для покупки!");

	if(GetPlayerMoneyEx(playerid) < buisness[h][buisnes_price]) 
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
		return SendErr(playerid,"У вас недостаточно денежных средств для покупки бизнеса!");	
	}
	

	if(buisness[h][buisnes_sell_day_payday] >= 0)
		return SendErr(playerid, "Вы не можете приобрести бизнес, так как пока он не доступен для продажи и опечатан!");

	buisness[h][buisnes_owned] = pData[playerid][pMysqlID];

	format(buisness[h][buisnes_owner], 24, pData[playerid][pNickname]);

	buisness[h][buisnes_days] = 3;

	pData[playerid][pBusiness] = h;

	UpdatePlayerData(playerid,"bussiness",pData[playerid][pBusiness]);	

 	format(String144, sizeof(String144), "Покупка бара №%d", h);
	give_money(playerid, -buisness[h][buisnes_price], String144);

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_buy_biz", 4000);


	save_biz(h);
	update_biz_text();

	format(String512, sizeof(String512), "\
		"cWH"Поздравляем Вас с приобретением Бара!\n\n\
		Вы купили бар "cBLUE"№%d\n\
		"cWH"Ежедневная оплата: "cGR"%d"cWH" рублей\n\n\
		"cWH"Бар оплачен на "cBLUE"%d"cWH" дней\n\
		Советутем Вам посетить банк для оплаты!",
		pData[playerid][pBusiness],
		buisness[h][buisnes_takings], buisness[h][buisnes_days]);
	return SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка бара", String512, !"Понял", !"");
}

stock buy_ammo_biz(playerid, h)
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


	if(buisness[h][buisnes_owned] != -1)
		return SendErr(playerid, "Бизнес недоступен для покупки!");

	if(GetPlayerMoneyEx(playerid) < buisness[h][buisnes_price]) 
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
		return SendErr(playerid,"У вас недостаточно денежных средств для покупки бизнеса!");	
	}
	

	if(buisness[h][buisnes_sell_day_payday] >= 0)
		return SendErr(playerid, "Вы не можете приобрести бизнес, так как пока он не доступен для продажи и опечатан!");


	buisness[h][buisnes_owned] = pData[playerid][pMysqlID];

	format(buisness[h][buisnes_owner], 24, pData[playerid][pNickname]);

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_buy_biz", 4000);

	buisness[h][buisnes_days] = 3;

	pData[playerid][pBusiness] = h;

	UpdatePlayerData(playerid,"bussiness",pData[playerid][pBusiness]);	

 	format(String144, sizeof(String144), "Покупка магазина оружия №%d", h);
	give_money(playerid, -buisness[h][buisnes_price], String144);


	save_biz(h);
	update_biz_text();

	format(String512, sizeof(String512), "\
		"cWH"Поздравляем Вас с приобретением Магазина Оружия!\n\n\
		Вы купили магазин оружия "cBLUE"№%d\n\
		"cWH"Ежедневная оплата: "cGR"%d"cWH" рублей\n\n\
		"cWH"Бизнес оплачен на "cBLUE"%d"cWH" дней\n\
		Советутем Вам посетить банк для оплаты!",
		pData[playerid][pBusiness],
		buisness[h][buisnes_takings], buisness[h][buisnes_days]);
	return SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка магазина оружия", String512, !"Понял", !"");
}

stock buy_restoran_biz(playerid, h)
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


	if(buisness[h][buisnes_owned] != -1)
		return SendErr(playerid, "Бизнес недоступен для покупки!");

	if(GetPlayerMoneyEx(playerid) < buisness[h][buisnes_price]) 
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
		return SendErr(playerid,"У вас недостаточно денежных средств для покупки бизнеса!");	
	}
	

	if(buisness[h][buisnes_sell_day_payday] >= 0)
		return SendErr(playerid, "Вы не можете приобрести бизнес, так как пока он не доступен для продажи и опечатан!");


	buisness[h][buisnes_owned] = pData[playerid][pMysqlID];

	format(buisness[h][buisnes_owner], 24, pData[playerid][pNickname]);

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_buy_biz", 4000);

	buisness[h][buisnes_days] = 3;

	pData[playerid][pBusiness] = h;

	UpdatePlayerData(playerid,"bussiness",pData[playerid][pBusiness]);	

 	format(String144, sizeof(String144), "Покупка ресторана №%d", h);
	give_money(playerid, -buisness[h][buisnes_price], String144);


	save_biz(h);
	update_biz_text();

	format(String512, sizeof(String512), "\
		"cWH"Поздравляем Вас с приобретением Ресторана!\n\n\
		Вы купили ресторан "cBLUE"№%d\n\
		"cWH"Ежедневная оплата: "cGR"%d"cWH" рублей\n\n\
		"cWH"Бизнес оплачен на "cBLUE"%d"cWH" дней\n\
		Советутем Вам посетить банк для оплаты!",
		pData[playerid][pBusiness],
		buisness[h][buisnes_takings], buisness[h][buisnes_days]);
	return SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка ресторана", String512, !"Понял", !"");
}

stock buy_fastfood_biz(playerid, h)
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


	if(buisness[h][buisnes_owned] != -1)
		return SendErr(playerid, "Бизнес недоступен для покупки!");

	if(GetPlayerMoneyEx(playerid) < buisness[h][buisnes_price]) 
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
		return SendErr(playerid,"У вас недостаточно денежных средств для покупки бизнеса!");	
	}
	

	if(buisness[h][buisnes_sell_day_payday] >= 0)
		return SendErr(playerid, "Вы не можете приобрести бизнес, так как пока он не доступен для продажи и опечатан!");


	buisness[h][buisnes_owned] = pData[playerid][pMysqlID];

	format(buisness[h][buisnes_owner], 24, pData[playerid][pNickname]);

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_buy_biz", 4000);

	buisness[h][buisnes_days] = 3;

	pData[playerid][pBusiness] = h;

	UpdatePlayerData(playerid,"bussiness",pData[playerid][pBusiness]);	

 	format(String144, sizeof(String144), "Покупка закусочной №%d", h);
	give_money(playerid, -buisness[h][buisnes_price], String144);


	save_biz(h);
	update_biz_text();

	format(String512, sizeof(String512), "\
		"cWH"Поздравляем Вас с приобретением Закусочной!\n\n\
		Вы купили закусочную "cBLUE"№%d\n\
		"cWH"Ежедневная оплата: "cGR"%d"cWH" рублей\n\n\
		"cWH"Бизнес оплачен на "cBLUE"%d"cWH" дней\n\
		Советутем Вам посетить банк для оплаты!",
		pData[playerid][pBusiness],
		buisness[h][buisnes_takings], buisness[h][buisnes_days]);
	return SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка закусочной", String512, !"Понял", !"");
}

stock buy_club_biz(playerid, h)
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

	if(GetPlayerMoneyEx(playerid) < buisness[h][buisnes_price]) 
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_21", 3000);
		return SendErr(playerid,"У вас недостаточно денежных средств для покупки бизнеса!");	
	}
	

	if(buisness[h][buisnes_owned] != -1)
		return SendErr(playerid, "Бизнес недоступен для покупки!");

	if(buisness[h][buisnes_sell_day_payday] >= 0)
		return SendErr(playerid, "Вы не можете приобрести бизнес, так как пока он не доступен для продажи и опечатан!");

	buisness[h][buisnes_owned] = pData[playerid][pMysqlID];

	format(buisness[h][buisnes_owner], 24, pData[playerid][pNickname]);

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_buy_biz", 4000);

	buisness[h][buisnes_days] = 3;

	pData[playerid][pBusiness] = h;

	UpdatePlayerData(playerid,"bussiness",pData[playerid][pBusiness]);	

 	format(String144, sizeof(String144), "Покупка ночного клуба №%d", h);
	give_money(playerid, -buisness[h][buisnes_price], String144);


	save_biz(h);
	update_biz_text();

	format(String512, sizeof(String512), "\
		"cWH"Поздравляем Вас с приобретением Ночного Клуба!\n\n\
		Вы купили ночной клуб "cBLUE"№%d\n\
		"cWH"Ежедневная оплата: "cGR"%d"cWH" рублей\n\n\
		"cWH"Бизнес оплачен на "cBLUE"%d"cWH" дней\n\
		Советутем Вам посетить банк для оплаты!",
		pData[playerid][pBusiness],
		buisness[h][buisnes_takings], buisness[h][buisnes_days]);
	return SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка ночного клуба", String512, !"Понял", !"");
}



stock buisness_bank_update(buisness_ids, sum, reason[])
{
	if(buisness[buisness_ids][buisnes_finka_day] >= buisness[buisness_ids][buisnes_finka_ogran])
		return true;

	if(buisness[buisness_ids][buisnes_owned] == -1)
		return true;

	if(buisness[buisness_ids][buisnes_count_prod] >= 25)
	{
		buisness[buisness_ids][buisnes_bank] += sum;
		buisness[buisness_ids][buisnes_finka_day] += sum;
	}

	if(buisness[buisness_ids][buisnes_type] == BUISNES_RIELTOR_AGENCY || buisness[buisness_ids][buisnes_type] == BUISNES_PARKING)
	{
		buisness[buisness_ids][buisnes_bank] += sum;
		buisness[buisness_ids][buisnes_finka_day] += sum;		
	}

	if(buisness[buisness_ids][buisnes_type] != BUISNES_FASTFOOD || buisness[buisness_ids][buisnes_type] != BUISNES_RESTORAN)
	{
		buisness[buisness_ids][buisnes_count_prod] -= 25;
	}

	save_biz(buisness_ids);

	format(String256,sizeof(String256),"UPDATE `buisnes_stats` SET `stats_all_time` = `stats_all_time`+'%d' WHERE `buisnes_id` = '%d'" , sum, buisness_ids);
	mysql_tquery(connect_main, String256);	
	format(String256,sizeof(String256),"UPDATE `buisnes_stats` SET `stats_mounth` = `stats_mounth`+'%d' WHERE `buisnes_id` = '%d'" , sum, buisness_ids);
	mysql_tquery(connect_main, String256);	

    new 
    	lyear, lmonth, lday;
	getdate(lyear, lmonth, lday);

	new 
		lwday = weekday(lday, lmonth, lyear);

	switch(lwday)
	{
		case 0:
		{
			format(String256,sizeof(String256),"UPDATE `buisnes_stats` SET `stats_day_1` = `stats_day_1`+'%d' WHERE `buisnes_id` = '%d'" , sum, buisness_ids);
			mysql_tquery(connect_main, String256);	

			format(String256,sizeof(String256),"UPDATE `buisnes_stats` SET `stats_today` = `stats_today`+'%d' WHERE `buisnes_id` = '%d'" , sum, buisness_ids);
			mysql_tquery(connect_main, String256);	

		}
		case 1:
		{
			format(String256,sizeof(String256),"UPDATE `buisnes_stats` SET `stats_day_2` = `stats_day_2`+'%d' WHERE `buisnes_id` = '%d'" , sum, buisness_ids);
			mysql_tquery(connect_main, String256);	
		
			format(String256,sizeof(String256),"UPDATE `buisnes_stats` SET `stats_today` = `stats_today`+'%d' WHERE `buisnes_id` = '%d'" , sum, buisness_ids);
			mysql_tquery(connect_main, String256);	
		}	

		case 2:
		{
			format(String256,sizeof(String256),"UPDATE `buisnes_stats` SET `stats_day_3` = `stats_day_3`+'%d' WHERE `buisnes_id` = '%d'" , sum, buisness_ids);
			mysql_tquery(connect_main, String256);	
		
			format(String256,sizeof(String256),"UPDATE `buisnes_stats` SET `stats_today` = `stats_today`+'%d' WHERE `buisnes_id` = '%d'" , sum, buisness_ids);
			mysql_tquery(connect_main, String256);	
		}
		case 3:
		{
			format(String256,sizeof(String256),"UPDATE `buisnes_stats` SET `stats_day_4` = `stats_day_4`+'%d' WHERE `buisnes_id` = '%d'" , sum, buisness_ids);
			mysql_tquery(connect_main, String256);	
		
			format(String256,sizeof(String256),"UPDATE `buisnes_stats` SET `stats_today` = `stats_today`+'%d' WHERE `buisnes_id` = '%d'" , sum, buisness_ids);
			mysql_tquery(connect_main, String256);	
		}

		case 4:
		{
			format(String256,sizeof(String256),"UPDATE `buisnes_stats` SET `stats_day_5` = `stats_day_5`+'%d' WHERE `buisnes_id` = '%d'" , sum, buisness_ids);
			mysql_tquery(connect_main, String256);	
		
			format(String256,sizeof(String256),"UPDATE `buisnes_stats` SET `stats_today` = `stats_today`+'%d' WHERE `buisnes_id` = '%d'" , sum, buisness_ids);
			mysql_tquery(connect_main, String256);	
		}	
		case 5:
		{
			format(String256,sizeof(String256),"UPDATE `buisnes_stats` SET `stats_day_6` = `stats_day_6`+'%d' WHERE `buisnes_id` = '%d'" , sum, buisness_ids);
			mysql_tquery(connect_main, String256);	
		
			format(String256,sizeof(String256),"UPDATE `buisnes_stats` SET `stats_today` = `stats_today`+'%d' WHERE `buisnes_id` = '%d'" , sum, buisness_ids);
			mysql_tquery(connect_main, String256);	
		}
		case 6:
		{
			format(String256,sizeof(String256),"UPDATE `buisnes_stats` SET `stats_day_7` = `stats_day_7`+'%d' WHERE `buisnes_id` = '%d'" , sum, buisness_ids);
			mysql_tquery(connect_main, String256);	
		
			format(String256,sizeof(String256),"UPDATE `buisnes_stats` SET `stats_today` = `stats_today`+'%d' WHERE `buisnes_id` = '%d'" , sum, buisness_ids);
			mysql_tquery(connect_main, String256);	
		}

	}	

	return true;
}

stock clear_stats_buisness_newday()
{


    new 
    	lyear, lmonth, lday;
	getdate(lyear, lmonth, lday);

	new 
		lwday = weekday(lday, lmonth, lyear);

	for(new i, idx = all_buisness; i < idx; i ++)
	{
		switch(lwday)
		{
			case 0:
			{
				format(String256,sizeof(String256),"UPDATE `buisnes_stats` SET `stats_day_1` = '0' WHERE `buisnes_id` = '%d'" , i);
				mysql_tquery(connect_main, String256);	

				format(String256,sizeof(String256),"UPDATE `buisnes_stats` SET `stats_today` = '0' WHERE `buisnes_id` = '%d'" , i);
				mysql_tquery(connect_main, String256);	

			}
			case 1:
			{
				format(String256,sizeof(String256),"UPDATE `buisnes_stats` SET `stats_day_2` = '0' WHERE `buisnes_id` = '%d'" , i);
				mysql_tquery(connect_main, String256);	
			
				format(String256,sizeof(String256),"UPDATE `buisnes_stats` SET `stats_today` = '0' WHERE `buisnes_id` = '%d'" , i);
				mysql_tquery(connect_main, String256);	
			}	

			case 2:
			{
				format(String256,sizeof(String256),"UPDATE `buisnes_stats` SET `stats_day_3` = '0' WHERE `buisnes_id` = '%d'" , i);
				mysql_tquery(connect_main, String256);	
			
				format(String256,sizeof(String256),"UPDATE `buisnes_stats` SET `stats_today` = '0' WHERE `buisnes_id` = '%d'" , i);
				mysql_tquery(connect_main, String256);	
			}
			case 3:
			{
				format(String256,sizeof(String256),"UPDATE `buisnes_stats` SET `stats_day_4` = '0' WHERE `buisnes_id` = '%d'" , i);
				mysql_tquery(connect_main, String256);	
			
				format(String256,sizeof(String256),"UPDATE `buisnes_stats` SET `stats_today` = '0' WHERE `buisnes_id` = '%d'" , i);
				mysql_tquery(connect_main, String256);	
			}

			case 4:
			{
				format(String256,sizeof(String256),"UPDATE `buisnes_stats` SET `stats_day_5` = '0' WHERE `buisnes_id` = '%d'" , i);
				mysql_tquery(connect_main, String256);	
			
				format(String256,sizeof(String256),"UPDATE `buisnes_stats` SET `stats_today` = '0' WHERE `buisnes_id` = '%d'" , i);
				mysql_tquery(connect_main, String256);	
			}	
			case 5:
			{
				format(String256,sizeof(String256),"UPDATE `buisnes_stats` SET `stats_day_6` = '0' WHERE `buisnes_id` = '%d'" , i);
				mysql_tquery(connect_main, String256);	
			
				format(String256,sizeof(String256),"UPDATE `buisnes_stats` SET `stats_today` = '0' WHERE `buisnes_id` = '%d'" , i);
				mysql_tquery(connect_main, String256);	
			}
			case 6:
			{
				format(String256,sizeof(String256),"UPDATE `buisnes_stats` SET `stats_day_7` = '0' WHERE `buisnes_id` = '%d'" , i);
				mysql_tquery(connect_main, String256);	
			
				format(String256,sizeof(String256),"UPDATE `buisnes_stats` SET `stats_today` = '0' WHERE `buisnes_id` = '%d'" , i);
				mysql_tquery(connect_main, String256);	
			}

		}	
	}
	return true;
}

stock clear_stats_buisness_newmouth()
{
	for(new i, idx = all_buisness; i < idx; i ++)
	{
		format(String256,sizeof(String256),"UPDATE `buisnes_stats` SET `stats_mounth_back` = `stats_mounth` WHERE `buisnes_id` = '%d'" , i);
		mysql_tquery(connect_main, String256);	
	}

	format(String256,sizeof(String256),"UPDATE `buisnes_stats` SET `stats_mounth` = '0' WHERE `buisnes_id` = '%d'" , 0);
	mysql_tquery(connect_main, String256);	

	return true;
}

stock change_statistic_buisnes(playerid)
{
	new 
		buisness_ids = pData[playerid][pBusiness];

	format(String512, sizeof(String512), "SELECT * FROM buisnes_stats WHERE buisnes_id = '%d' LIMIT 1", buisness_ids);
	new Result:buisness_stats = sql_queryEx(zConn, String512, QUERY_CACHED);

	if(sql_num_rows(buisness_stats)) 
	{
		new 
			ye, m, d;

		getdate(ye, m, d);

		new 
			buisness_stats_day[8],
			buisness_stats_today,
			buisness_stats_mounth,
			buisness_status_all,
			buisness_stats_prewiow;

  		buisness_stats_day[1] = sql_get_field_assoc_int(buisness_stats, "stats_day_1");
  		buisness_stats_day[2] = sql_get_field_assoc_int(buisness_stats, "stats_day_2");
  		buisness_stats_day[3] = sql_get_field_assoc_int(buisness_stats, "stats_day_3");
  		buisness_stats_day[4] = sql_get_field_assoc_int(buisness_stats, "stats_day_4");
  		buisness_stats_day[5] = sql_get_field_assoc_int(buisness_stats, "stats_day_5");
  		buisness_stats_day[6] = sql_get_field_assoc_int(buisness_stats, "stats_day_6");
  		buisness_stats_day[7] = sql_get_field_assoc_int(buisness_stats, "stats_day_7");

  		buisness_stats_today = sql_get_field_assoc_int(buisness_stats, "stats_today");
  		buisness_stats_mounth = sql_get_field_assoc_int(buisness_stats, "stats_mounth");
  		buisness_status_all = sql_get_field_assoc_int(buisness_stats, "stats_all_time");
  		buisness_stats_prewiow = sql_get_field_assoc_int(buisness_stats, "stats_mounth_back");

  		new 
  			all_day_seven = buisness_stats_day[1]+buisness_stats_day[2]+buisness_stats_day[3]+buisness_stats_day[4]+buisness_stats_day[5]+buisness_stats_day[6]+buisness_stats_day[7];


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

        get_stats_color(buisness_stats_day[1], buisness_stats_day[1]), buisness_stats_day[1],
        get_stats_color(buisness_stats_day[2], buisness_stats_day[1]), buisness_stats_day[2], get_stats_phrase(buisness_stats_day[2], buisness_stats_day[1]), get_percent_pribil(buisness_stats_day[2], buisness_stats_day[1]), 
        get_stats_color(buisness_stats_day[3], buisness_stats_day[2]), buisness_stats_day[3], get_stats_phrase(buisness_stats_day[3], buisness_stats_day[1]), get_percent_pribil(buisness_stats_day[3], buisness_stats_day[2]), 
        get_stats_color(buisness_stats_day[4], buisness_stats_day[3]), buisness_stats_day[4], get_stats_phrase(buisness_stats_day[4], buisness_stats_day[1]), get_percent_pribil(buisness_stats_day[4], buisness_stats_day[3]), 
        get_stats_color(buisness_stats_day[5], buisness_stats_day[4]), buisness_stats_day[5], get_stats_phrase(buisness_stats_day[5], buisness_stats_day[1]), get_percent_pribil(buisness_stats_day[5], buisness_stats_day[4]), 
        get_stats_color(buisness_stats_day[6], buisness_stats_day[5]), buisness_stats_day[6], get_stats_phrase(buisness_stats_day[6], buisness_stats_day[1]), get_percent_pribil(buisness_stats_day[6], buisness_stats_day[5]), 
        get_stats_color(buisness_stats_day[7], buisness_stats_day[6]), buisness_stats_day[7], get_stats_phrase(buisness_stats_day[7], buisness_stats_day[1]), get_percent_pribil(buisness_stats_day[7], buisness_stats_day[6]), 
        mounth_buisnes_stats[m], get_stats_color(buisness_stats_mounth, buisness_stats_prewiow), buisness_stats_mounth, get_stats_phrase(buisness_stats_mounth, buisness_stats_prewiow), get_percent_pribil(buisness_stats_mounth, buisness_stats_prewiow), 
        mounth_buisnes_stats[m-1], buisness_stats_prewiow,
        all_day_seven,
        buisness_status_all,
        buisness_stats_today);
	    SPD(playerid, 0, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Статистика бизнеса", String2048, !"Закрыть", ""); 

  	}
  	sql_free_result(buisness_stats);


	return true;
}

alias:gotobiz("biz");
CMD:gotobiz(playerid, params[])
{
    if(pData[playerid][pAdmin] < 5) 
    	return NoCMD(playerid);

	if(sscanf(params, "d", params[0]))
	{
		SendInf(playerid, "Используйте: /gotobiz "cWH"[ID Бизнеса]");
		return true;
	}

	new 
		id_biz = params[0];


	SetPlayerPos(playerid, buisness[id_biz][buisnes_enter_x], buisness[id_biz][buisnes_enter_y], buisness[id_biz][buisnes_enter_z]);

	new 
		fmt_str[144];

    format(fmt_str, sizeof(fmt_str), "Вы телепортировались к бизнесу №%d", id_biz);
    SendSucc(playerid, fmt_str);
	return true;
}


CMD:updatebizenter(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    new 
    	Float:x,Float:y,Float:z;

    if(sscanf(params, "d",params[0])) 
    	return SendInf(playerid, "Используйте: /updatebizenter [ID]");

    GetPlayerPos(playerid, x, y, z);
    
	new 
		id_biz = params[0];

	buisness[id_biz][buisnes_enter_x] = x;
	buisness[id_biz][buisnes_enter_y] = y;
	buisness[id_biz][buisnes_enter_z] = z;

	save_biz(id_biz);

	return true;
}

CMD:updatebizexit(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    new 
    	Float:x,Float:y,Float:z;

    if(sscanf(params, "d",params[0])) 
    	return SendInf(playerid, "Используйте: /updatebizexit [ID]");

    GetPlayerPos(playerid, x, y, z);
    
	new 
		id_biz = params[0];

	buisness[id_biz][buisnes_exit_x] = x;
	buisness[id_biz][buisnes_exit_y] = y;
	buisness[id_biz][buisnes_exit_z] = z;

	save_biz(id_biz);

	return true;
}

CMD:addmagazin(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    new 
    	Float:x,Float:y,Float:z;

    if(sscanf(params, "ddd",params[0], params[1], params[2])) 
    	return SendInf(playerid, "Используйте: /addmagazin [Название (От 1 до 4)] [Цена] [Макс.Финка]");

    GetPlayerPos(playerid, x, y, z);
    

    format(String320, sizeof(String320), "INSERT INTO buisnes(buisnes_type, buisnes_enter_x, buisnes_enter_y, buisnes_enter_z, buisnes_exit_x, buisnes_exit_y, buisnes_exit_z, buisnes_name, buisnes_price, buisnes_finka_ogran) VALUES ('%d', '%f','%f','%f','%f','%f','%f', '%d','%d','%d')",
    BUISNES_PRODUCTION, x, y, z, x, y, z, params[0], params[1], params[2]);
    sql_queryEx(zConn, String320, QUERY_THREADED);	

    SendSucc(playerid, "Вы добавили Магазин! Он появится после рестарта!");
	return true;
}

CMD:addbar(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    new 
    	Float:x,Float:y,Float:z;

    if(sscanf(params, "ddd",params[0], params[1], params[2])) 
    	return SendInf(playerid, "Используйте: /addbar [Название (От 1 до 4)] [Цена] [Макс.Финка]");

    GetPlayerPos(playerid, x, y, z);
    

    format(String320, sizeof(String320), "INSERT INTO buisnes(buisnes_type, buisnes_enter_x, buisnes_enter_y, buisnes_enter_z, buisnes_exit_x, buisnes_exit_y, buisnes_exit_z, buisnes_name, buisnes_price, buisnes_finka_ogran) VALUES ('%d', '%f','%f','%f','%f','%f','%f', '%d','%d','%d')",
    BUISNES_BAR, x, y, z, x, y, z, params[0], params[1], params[2]);
    sql_queryEx(zConn, String320, QUERY_THREADED);	

    SendSucc(playerid, "Вы добавили Бар! Он появится после рестарта!");
	return true;
}

CMD:addammo1(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    new 
    	Float:x,Float:y,Float:z;

    if(sscanf(params, "ddd",params[0], params[1], params[2])) 
    	return SendInf(playerid, "Используйте: /addammo [Название (От 1 до 4)] [Цена] [Макс.Финка]");

    GetPlayerPos(playerid, x, y, z);
    

    format(String320, sizeof(String320), "INSERT INTO buisnes(buisnes_type, buisnes_enter_x, buisnes_enter_y, buisnes_enter_z, buisnes_exit_x, buisnes_exit_y, buisnes_exit_z, buisnes_name, buisnes_price, buisnes_finka_ogran) VALUES ('%d', '%f','%f','%f','%f','%f','%f', '%d','%d','%d')",
    BUISNES_AMMO_1, x, y, z, x, y, z, params[0], params[1], params[2]);
    sql_queryEx(zConn, String320, QUERY_THREADED);	

    SendSucc(playerid, "Вы добавили Магазин Оружия! Он появится после рестарта!");
	return true;
}

CMD:addammo2(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    new 
    	Float:x,Float:y,Float:z;

    if(sscanf(params, "ddd",params[0], params[1], params[2])) 
    	return SendInf(playerid, "Используйте: /addammo [Название (От 1 до 4)] [Цена] [Макс.Финка]");

    GetPlayerPos(playerid, x, y, z);
    

    format(String320, sizeof(String320), "INSERT INTO buisnes(buisnes_type, buisnes_enter_x, buisnes_enter_y, buisnes_enter_z, buisnes_exit_x, buisnes_exit_y, buisnes_exit_z, buisnes_name, buisnes_price, buisnes_finka_ogran) VALUES ('%d', '%f','%f','%f','%f','%f','%f', '%d','%d','%d')",
    BUISNES_AMMO_2, x, y, z, x, y, z, params[0], params[1], params[2]);
    sql_queryEx(zConn, String320, QUERY_THREADED);	

    SendSucc(playerid, "Вы добавили Магазин Оружия! Он появится после рестарта!");
	return true;
}


CMD:addrestoran(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    new 
    	Float:x,Float:y,Float:z;

    if(sscanf(params, "ddd",params[0], params[1], params[2])) 
    	return SendInf(playerid, "Используйте: /addrestoran [Название (От 1 до 4)] [Цена] [Макс.Финка]");

    GetPlayerPos(playerid, x, y, z);
    

    format(String320, sizeof(String320), "INSERT INTO buisnes(buisnes_type, buisnes_enter_x, buisnes_enter_y, buisnes_enter_z, buisnes_exit_x, buisnes_exit_y, buisnes_exit_z, buisnes_name, buisnes_price, buisnes_finka_ogran) VALUES ('%d', '%f','%f','%f','%f','%f','%f', '%d','%d','%d')",
    BUISNES_RESTORAN, x, y, z, x, y, z, params[0], params[1], params[2]);
    sql_queryEx(zConn, String320, QUERY_THREADED);	

    SendSucc(playerid, "Вы добавили Ресторан! Он появится после рестарта!");
	return true;
}


CMD:addfastfood(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    new 
    	Float:x,Float:y,Float:z;

    if(sscanf(params, "ddd",params[0], params[1], params[2])) 
    	return SendInf(playerid, "Используйте: /addfastfood [Название (От 1 до 4)] [Цена] [Макс.Финка]");

    GetPlayerPos(playerid, x, y, z);
    

    format(String320, sizeof(String320), "INSERT INTO buisnes(buisnes_type, buisnes_enter_x, buisnes_enter_y, buisnes_enter_z, buisnes_exit_x, buisnes_exit_y, buisnes_exit_z, buisnes_name, buisnes_price, buisnes_finka_ogran) VALUES ('%d', '%f','%f','%f','%f','%f','%f', '%d','%d','%d')",
    BUISNES_FASTFOOD, x, y, z, x, y, z, params[0], params[1], params[2]);
    sql_queryEx(zConn, String320, QUERY_THREADED);	

    SendSucc(playerid, "Вы добавили Фастфуд! Он появится после рестарта!");
	return true;
}


CMD:addclub(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    new 
    	Float:x,Float:y,Float:z;

    if(sscanf(params, "ddd",params[0], params[1], params[2])) 
    	return SendInf(playerid, "Используйте: /addclub [Название (От 1 до 4)] [Цена] [Макс.Финка]");

    GetPlayerPos(playerid, x, y, z);
    

    format(String320, sizeof(String320), "INSERT INTO buisnes(buisnes_type, buisnes_enter_x, buisnes_enter_y, buisnes_enter_z, buisnes_exit_x, buisnes_exit_y, buisnes_exit_z, buisnes_name, buisnes_price, buisnes_finka_ogran) VALUES ('%d', '%f','%f','%f','%f','%f','%f', '%d','%d','%d')",
    BUISNES_CLUB, x, y, z, x, y, z, params[0], params[1], params[2]);
    sql_queryEx(zConn, String320, QUERY_THREADED);	

    SendSucc(playerid, "Вы добавили Клуб! Он появится после рестарта!");
	return true;
}


CMD:addautosalon1(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    new 
    	Float:x,Float:y,Float:z;

    if(sscanf(params, "ddd",params[0], params[1], params[2])) 
    	return SendInf(playerid, "Используйте: /addautosalon [Название (От 1 до 3)] [Цена] [Макс.Финка]");

    GetPlayerPos(playerid, x, y, z);
    

    format(String320, sizeof(String320), "INSERT INTO buisnes(buisnes_type, buisnes_enter_x, buisnes_enter_y, buisnes_enter_z, buisnes_exit_x, buisnes_exit_y, buisnes_exit_z, buisnes_name, buisnes_price, buisnes_finka_ogran) VALUES ('%d', '%f','%f','%f','%f','%f','%f', '%d','%d','%d')",
    BUISNES_AUTOSALON_1, x, y, z, x, y, z, params[0], params[1], params[2]);
    sql_queryEx(zConn, String320, QUERY_THREADED);	

    SendSucc(playerid, "Вы добавили Автосалон! Он появится после рестарта!");
	return true;
}

CMD:addautosalon2(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    new 
    	Float:x,Float:y,Float:z;

    if(sscanf(params, "ddd",params[0], params[1], params[2])) 
    	return SendInf(playerid, "Используйте: /addautosalon [Название (От 1 до 3)] [Цена] [Макс.Финка]");

    GetPlayerPos(playerid, x, y, z);
    

    format(String320, sizeof(String320), "INSERT INTO buisnes(buisnes_type, buisnes_enter_x, buisnes_enter_y, buisnes_enter_z, buisnes_exit_x, buisnes_exit_y, buisnes_exit_z, buisnes_name, buisnes_price, buisnes_finka_ogran) VALUES ('%d', '%f','%f','%f','%f','%f','%f', '%d','%d','%d')",
    BUISNES_AUTOSALON_2, x, y, z, x, y, z, params[0], params[1], params[2]);
    sql_queryEx(zConn, String320, QUERY_THREADED);	

    SendSucc(playerid, "Вы добавили Автосалон! Он появится после рестарта!");
	return true;
}

CMD:addautosalon3(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    new 
    	Float:x,Float:y,Float:z;

    if(sscanf(params, "ddd",params[0], params[1], params[2])) 
    	return SendInf(playerid, "Используйте: /addautosalon [Название (От 1 до 3)] [Цена] [Макс.Финка]");

    GetPlayerPos(playerid, x, y, z);
    

    format(String320, sizeof(String320), "INSERT INTO buisnes(buisnes_type, buisnes_enter_x, buisnes_enter_y, buisnes_enter_z, buisnes_exit_x, buisnes_exit_y, buisnes_exit_z, buisnes_name, buisnes_price, buisnes_finka_ogran) VALUES ('%d', '%f','%f','%f','%f','%f','%f', '%d','%d','%d')",
    BUISNES_AUTOSALON_3, x, y, z, x, y, z, params[0], params[1], params[2]);
    sql_queryEx(zConn, String320, QUERY_THREADED);	

    SendSucc(playerid, "Вы добавили Автосалон! Он появится после рестарта!");
	return true;
}

CMD:addclothes(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    new 
    	Float:x,Float:y,Float:z;

    if(sscanf(params, "ddd",params[0], params[1], params[2])) 
    	return SendInf(playerid, "Используйте: /addclothes [Название (От 1 до 3)] [Цена] [Макс.Финка]");

    GetPlayerPos(playerid, x, y, z);
    

    format(String320, sizeof(String320), "INSERT INTO buisnes(buisnes_type, buisnes_enter_x, buisnes_enter_y, buisnes_enter_z, buisnes_exit_x, buisnes_exit_y, buisnes_exit_z, buisnes_name, buisnes_price, buisnes_finka_ogran) VALUES ('%d', '%f','%f','%f','%f','%f','%f', '%d','%d','%d')",
    BUISNES_CLOTHES, x, y, z, x, y, z, params[0], params[1], params[2]);
    sql_queryEx(zConn, String320, QUERY_THREADED);	

    SendSucc(playerid, "Вы добавили Магазин Одежды! Он появится после рестарта!");
	return true;
}

CMD:addaksshop(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    new 
    	Float:x,Float:y,Float:z;

    if(sscanf(params, "ddd",params[0], params[1], params[2])) 
    	return SendInf(playerid, "Используйте: /addaksshop [Название (От 1 до 3)] [Цена] [Макс.Финка]");

    GetPlayerPos(playerid, x, y, z);
    

    format(String320, sizeof(String320), "INSERT INTO buisnes(buisnes_type, buisnes_enter_x, buisnes_enter_y, buisnes_enter_z, buisnes_exit_x, buisnes_exit_y, buisnes_exit_z, buisnes_name, buisnes_price, buisnes_finka_ogran) VALUES ('%d', '%f','%f','%f','%f','%f','%f', '%d','%d','%d')",
    BUISNES_ACCESSORIES, x, y, z, x, y, z, params[0], params[1], params[2]);
    sql_queryEx(zConn, String320, QUERY_THREADED);	

    SendSucc(playerid, "Вы добавили Магазин Аксессуаров! Он появится после рестарта!");
	return true;
}

CMD:addrealtor(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    new 
    	Float:x,Float:y,Float:z;

    if(sscanf(params, "ddd",params[0], params[1], params[2])) 
    	return SendInf(playerid, "Используйте: /addrealtor [Название (От 1 до 3)] [Цена] [Макс.Финка]");

    GetPlayerPos(playerid, x, y, z);
    

    format(String512, sizeof(String512), "INSERT INTO buisnes(buisnes_type, buisnes_enter_x, buisnes_enter_y, buisnes_enter_z, buisnes_exit_x, buisnes_exit_y, buisnes_exit_z, buisnes_name, buisnes_price, buisnes_finka_ogran, buisnes_enterprice) VALUES ('%d', '%f','%f','%f','%f','%f','%f', '%d','%d','%d','%d')",
    BUISNES_RIELTOR_AGENCY, x, y, z, x, y, z, params[0], params[1], params[2], 5000);
    sql_queryEx(zConn, String512, QUERY_THREADED);	

    SendSucc(playerid, "Вы добавили Риелторское Агенство! Он появится после рестарта!");
	return true;
}

CMD:addparking(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    new 
    	Float:x,Float:y,Float:z;

    if(sscanf(params, "ddd",params[0], params[1], params[2])) 
    	return SendInf(playerid, "Используйте: /addparking [Цена] [Макс.Финка] [Стоимость 1 дня аренды]");

    GetPlayerPos(playerid, x, y, z);
    

    format(String512, sizeof(String512), "INSERT INTO buisnes(buisnes_type, buisnes_enter_x, buisnes_enter_y, buisnes_enter_z, buisnes_exit_x, buisnes_exit_y, buisnes_exit_z, buisnes_name, buisnes_price, buisnes_finka_ogran, buisnes_enterprice, buisnes_price_day_rent) VALUES ('%d', '%f','%f','%f','%f','%f','%f', '%d','%d','%d','%d','%d')",
    BUISNES_PARKING, x, y, z, x, y, z, params[0], params[1], params[2], 5000);
    sql_queryEx(zConn, String512, QUERY_THREADED);	

    SendSucc(playerid, "Вы добавили Риелторское Агенство! Он появится после рестарта!");
	return true;
}

CMD:asellbiz(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    if(sscanf(params, "d",params[0])) 
    	return SendInf(playerid, "Используйте: /asellbiz [ID]");


	sell_buisness_admin2(params[0]);

	return true;
}

CMD:asellbizpayday(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    if(sscanf(params, "dd",params[0],params[1])) 
    	return SendInf(playerid, "Используйте: /asellbizpayday [ID] [HOUR]");

	

	sell_buisness_admin3(params[0], params[1]);

	return true;
}


CMD:changemafiabiz(playerid, params[])
{
    if(pData[playerid][pAdmin] < 7) 
    	return NoCMD(playerid);

    if(sscanf(params, "dd", params[0], params[1])) 
    {
    	SendInf(playerid, "13 - Тамбовская | 14 - Измайловская | 15 - Курганская | 0 - Отсутствует");
    	return SendInf(playerid, "Используйте: /changemafiabiz [ID Бизнеса] [ID мафии]");
    }


	buisness[params[0]][buisnes_mafia] = params[1];

	save_biz(params[0]);
	update_biz_text();

	return true;
}


CMD:changefinkabiz(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    if(sscanf(params, "dd", params[0], params[1])) 
    {
    	return SendInf(playerid, "Используйте: /changefinkabiz [ID Бизнеса] [Финка]");
    }


	buisness[params[0]][buisnes_finka_ogran] = params[1];

	save_biz(params[0]);
	update_biz_text();

	format(String144, sizeof(String144), "Ограничение финки у бизнеса %d была успешно обновлено! Новое ограничение: %d рублей", params[0], params[1]);
	SendSucc(playerid, String144);
	return true;
}

CMD:clearfinkabiz(playerid)
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

	for(new i, idx = all_buisness; i < idx; i ++)
	{

		buisness[i][buisnes_finka_day] = 0;
		save_biz(i);
		update_biz_text();
	}
	SendSucc(playerid, "Вы успешно очистили параметры финки у всех бизнесов!");
	return true;
}

CMD:fullprodbiz(playerid)
{

    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

	for(new i, idx = all_buisness; i < idx; i ++)
	{

		buisness[i][buisnes_count_prod] = 5000;
		save_biz(i);
		update_biz_text();
	}
	SendSucc(playerid, "Вы успешно пополнили продукты у бизнесов!");

	return true;
}

CMD:clearfinkabizz(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8) 
    	return NoCMD(playerid);

    if(sscanf(params, "dd", params[0], params[1])) 
    {
    	return SendInf(playerid, "Используйте: /clearfinkabizz [ID Бизнеса] [Финка]");
    }


	buisness[params[0]][buisnes_finka_day] = params[1];

	save_biz(params[0]);
	update_biz_text();

	format(String144, sizeof(String144), "Ограничение финки у бизнеса %d была успешно обновлено! Новое ограничение: %d рублей", params[0], params[1]);
	SendSucc(playerid, String144);
	return true;
}
