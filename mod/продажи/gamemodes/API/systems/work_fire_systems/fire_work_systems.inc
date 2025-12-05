
static const Float:position_spawn_fire[][] =
{
	{-474.0541,1009.2141,12.0300,269.4424},
	{-474.1083,1013.5948,12.0341,270.9648}
};

stock create_fire_pickups()
{
    CreateDynamic3DTextLabel(""cLRED"[МЧС] {FFFFFF}Министерство по чрезвычайным ситуациям\n"cLRED"Пожарная станция", -1, -423.3132,1035.3926,12.0145, 25.0);

	fire_clothes = create_circle_pickup(-432.6002,1030.6121,12.0145, TRIGGER_LRED);
	fire_weapon = create_circle_pickup(-437.1055,1030.6121,12.0376, TRIGGER_LRED);

	CreateDynamic3DTextLabel("Работа Пожарным\n"cLRED"[Встаньте на пикап]", -1, -432.6002,1030.6121,12.0145, 15.0);
	CreateDynamic3DTextLabel("Огнетушитель\n"cLRED"[Встаньте на пикап]", -1, -437.1055,1030.6121,12.0376, 15.0);

	for(new i; i < MAX_GYDRANTS; i++)
	{
		create_circle_pickup(Gydrants[i][0],  Gydrants[i][1],  Gydrants[i][2], TRIGGER_LRED);
		CreateDynamic3DTextLabel("Гидрант\n"cLRED"[Используйте /fire]", -1, Gydrants[i][0],  Gydrants[i][1],  Gydrants[i][2] + 0.2, 15.0);
	}
	return true;
}

stock fire_work_panel_p(playerid, status)
{
	switch(status)
	{
		case TEXTDRAW_SHOW:
		{	

			create_player_fire_work(playerid);

			PlayerTextDrawShow(playerid, fire_work_panel[0][playerid]);
			PlayerTextDrawShow(playerid, fire_work_panel[2][playerid]);
			

			if(pData[playerid][pJob] == SKILL_FIRE)
			{
				PlayerTextDrawSetString(playerid, fire_work_panel[1][playerid], "brilliantother:fire_work_gui_2");
				PlayerTextDrawShow(playerid,  fire_work_panel[1][playerid]);				
			}
			else
			{
				PlayerTextDrawSetString(playerid,  fire_work_panel[1][playerid], "brilliantother:fire_work_gui_1");
				PlayerTextDrawShow(playerid,  fire_work_panel[1][playerid]);				
			}
			SelectTextDraw(playerid, COLOR_BLUE);
		}
		case TEXTDRAW_HIDE:
		{
			PlayerTextDrawHideEx(playerid, fire_work_panel[0][playerid]);
			PlayerTextDrawHideEx(playerid, fire_work_panel[1][playerid]);
			PlayerTextDrawHideEx(playerid, fire_work_panel[2][playerid]);
			
			TextDrawHideForPlayer(playerid, fire_work_close);
			TextDrawHideForPlayer(playerid, fire_panel_close);

			CancelSelectTextDraw(playerid);
		}
		case TEXTDRAW_UPDATE:
		{
			if(pData[playerid][pJob] == SKILL_FIRE)
			{
				PlayerTextDrawSetString(playerid, fire_work_panel[1][playerid], "brilliantother:fire_work_gui_2");
				PlayerTextDrawShow(playerid,  fire_work_panel[1][playerid]);				
			}
			else
			{
				PlayerTextDrawSetString(playerid,  fire_work_panel[1][playerid], "brilliantother:fire_work_gui_1");
				PlayerTextDrawShow(playerid,  fire_work_panel[1][playerid]);				
			}
			SelectTextDraw(playerid, COLOR_BLUE);			
		}
	}

	return true;
}

stock fire_panel_p(playerid, status)
{
	switch(status)
	{
		case TEXTDRAW_SHOW:
		{	

			TextDrawShowForPlayer(playerid, fire_panel_background);
				

			create_player_fire_panel(playerid);

			PlayerTextDrawShow(playerid, fire_panel[0][playerid]);
			PlayerTextDrawShow(playerid, fire_panel[1][playerid]);
			PlayerTextDrawShow(playerid, fire_panel[2][playerid]);

			TextDrawShowForPlayer(playerid, fire_panel_close);


			SelectTextDraw(playerid, COLOR_BLUE);
		}
		case TEXTDRAW_HIDE:
		{
			PlayerTextDrawHideEx(playerid, fire_panel[0][playerid]);
			PlayerTextDrawHideEx(playerid, fire_panel[1][playerid]);
			PlayerTextDrawHideEx(playerid, fire_panel[2][playerid]);

			TextDrawHideForPlayer(playerid, fire_panel_background);
			TextDrawHideForPlayer(playerid, fire_panel_close);

			CancelSelectTextDraw(playerid);
		}
		case TEXTDRAW_UPDATE:
		{
			new 
				format_str[50];

		 	format(format_str, sizeof(format_str),"%d", GetPVarIntNew(playerid, "count_fire_final"));
		 	PlayerTextDrawSetString(playerid, fire_panel[0][playerid], format_str);
		 	PlayerTextDrawShow(playerid, fire_panel[0][playerid]);

		 	format(format_str, sizeof(format_str),"%d_RUB", GetPVarIntNew(playerid, "count_fire_money"));
		 	PlayerTextDrawSetString(playerid, fire_panel[1][playerid], format_str);
		 	PlayerTextDrawShow(playerid, fire_panel[1][playerid]);

		 	format(format_str, sizeof(format_str),"%d% (%d)", fire_progress, pTemp[playerid][fire_count]);
		 	PlayerTextDrawSetString(playerid, fire_panel[2][playerid], format_str);
		 	PlayerTextDrawShow(playerid, fire_panel[2][playerid]);
		
		}
	}

	return true;
}

stock fire_extinguisher(playerid)
{
	if(pData[playerid][pJob] != SKILL_FIRE) 
		return true;

	GivePlayerWeaponEx(playerid, WEAPON_FIREEXTINGUISHER, 1);
	SetPlayerAmmo(playerid, WEAPON_FIREEXTINGUISHER, 500);

	SetPlayerArmedWeapon(playerid, WEAPON_FIREEXTINGUISHER);
	return true;
}

stock start_fire_job(playerid)
{
	end_all_work(playerid);

	if(pData[playerid][pLevel] < 5) 
	{
		SelectTextDraw(playerid, COLOR_BLUE);
		return EROM(playerid, 0, "Работать пожарным можно только с {00FF00}5 уровня{FFFFFF}", 5, "", "");
	}

	pData[playerid][pJob] = SKILL_FIRE;

	set_player_fire_skin(playerid);

	if(get_job_level(playerid, SKILL_FIRE) < 5)
	{
		SFCM(playerid, -1, ""cLRED"[МЧС] "cWH"Ваш навык работника: "cLRED"%d уровень"cWH"", get_job_level(playerid, SKILL_FIRE));
		SFCM(playerid, -1, ""cLRED"[МЧС] "cWH"Для повышения навыка необходимо потушить "cLRED"%d"cWH" пожаров", get_job_level_next(playerid, SKILL_FIRE));
	}
	else
	{
		SFCM(playerid, -1, ""cLRED"[МЧС] "cWH"Ваш навык работника: "cLRED"%d уровень", get_job_level(playerid, SKILL_FIRE));
	}

	fire_panel_p(playerid, TEXTDRAW_SHOW);
	fire_panel_p(playerid, TEXTDRAW_UPDATE);

	fire_extinguisher(playerid);

	fire_work_panel_p(playerid, TEXTDRAW_HIDE);

	create_fire_work_car(playerid);

	update_fire_td(playerid);


	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_work_18", 4000);

	fire_work_panel_p(playerid, TEXTDRAW_HIDE);
	
	return true;
}

stock create_fire_work_car(playerid)
{
	if(pTemp[playerid][rent_car] != INVALID_VEHICLE_ID)
	{
		SendErr(playerid, "Вы уже арендуете какой-либо транспорт");
		return true;
	}

	if(pData[playerid][pLevel] < 5) 
		return EROM(playerid, 0, "Работать пожарным можно только с {00FF00}5 уровня{FFFFFF}", 5, "", "");

	if(!pData[playerid][pLicenses][LIC_DRIVING])
		return SendErr(playerid, "У вас отсутствует лицензия на управления транспортом!");

	if(get_job_level(playerid, SKILL_FIRE) == 0)
	{
		add_player_job_skill(playerid, SKILL_FIRE, 1);
	}

	SendSucc(playerid, "Вы устроились на работу Пожарным");

	new 
		random_pos = random(1);

	swork_vehicle[playerid] = CreateVehicle(407, position_spawn_fire[random_pos][0], position_spawn_fire[random_pos][1], position_spawn_fire[random_pos][2], position_spawn_fire[random_pos][3], -1, -1, 600);

	vehicle[swork_vehicle[playerid]][cFuel] = 50.0;
	vehicle[swork_vehicle[playerid]][cHealth] = 1000.0;
	vehicle[swork_vehicle[playerid]][cIsCreated] = true;
	vehicle[swork_vehicle[playerid]][cOwnTo] = VEHICLE_FIRE;
	vehicle[swork_vehicle[playerid]][cLock] = 1;
	vehicle[swork_vehicle[playerid]][consumables_oil] = 1000.0;
	vehicle[swork_vehicle[playerid]][cWater] = 2500;

	vehicle_lock_status(swork_vehicle[playerid], false);
	vehicle[swork_vehicle[playerid]][cFuel] = 80;
 	
 	pTemp[playerid][rent_car] = swork_vehicle[playerid];

	format(String144,sizeof(String144),"\
		"cLRED"Воды в цистернах:\n\
		"cWH"%d/%d литров", vehicle[swork_vehicle[playerid]][cWater], MAX_FIRE_WATER_FILLED);
	vehicle[swork_vehicle[playerid]][cMechText] = CreateDynamic3DTextLabel(String144, CWHITE, 0.0,0.0,1.0, 10.0, INVALID_PLAYER_ID, swork_vehicle[playerid]);


	new
		v = GetPlayerVehicleID(playerid);	

	pTemp[playerid][rent_car] = swork_vehicle[playerid];
	PutPlayerInVehicle(playerid, swork_vehicle[playerid], 0);
	return true;
}

callback:: spawn_rent_car_fire_work(i, v, time)
{
	if(IsPlayerConnected(i))
	{	
		time--;

		if(!time)
		{
			end_fire_job(i);
			return true;
		}
		pTemp[i][rent_car_spawn_timer] = SetTimerEx("spawn_rent_car_fire_work", 1000, false, "iii", i, v, time);
	}
	return true; 
}


stock end_fire_job(playerid)
{
	if(pData[playerid][pJob] != SKILL_FIRE) 
		return true;

	pData[playerid][pJob] = SKILL_JOB_NONE;

	SetPlayerSkin(playerid, pData[playerid][pSkin]);

	fire_panel_p(playerid, TEXTDRAW_HIDE);

	SetPlayerAmmo(playerid, WEAPON_FIREEXTINGUISHER, 1);

	new 
		v = pTemp[playerid][rent_car];

	if(v == INVALID_VEHICLE_ID) 
		return true;

	if(vehicle[v][cOwnTo] != VEHICLE_FIRE) 
		return true;

	DestroyDynamic3DTextLabel(vehicle[v][cMechText]);
	DestroyDynamic3DTextLabel(vehicle[swork_vehicle[playerid]][cMechText]);
	vehicle[v][cMechText] = Text3D:INVALID_3DTEXT_ID;	
	vehicle[swork_vehicle[playerid]][cMechText] = Text3D:INVALID_3DTEXT_ID;	

	pTemp[playerid][rent_car] = INVALID_VEHICLE_ID;
	pTemp[playerid][rent_car_spawn_timer] = INVALID_TIMER_ID;

	fire_work_panel_p(playerid, TEXTDRAW_HIDE);

	DestroyVehicle(swork_vehicle[playerid]);
	swork_vehicle[playerid] = INVALID_VEHICLE_ID;


	DeletePVarNew(playerid, "count_fire_money");
	DeletePVarNew(playerid, "count_fire_final");


	DisablePlayerCheckpoint(playerid);
	DisablePlayerRaceCheckpoint(playerid);

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_work_20", 4000);


	fire_work_panel_p(playerid, TEXTDRAW_HIDE);

	return true;
}

stock set_player_fire_skin(playerid)
{
	if(pData[playerid][pSex] == 2) 
	{
		SetPlayerSkin(playerid, 191);
	}
	else
	{
		SetPlayerSkin(playerid, 36);
	}

	return true;
}

stock create_fire_global_params(fID)
{
	new 
		temp_string[144];
	
	if(fID == -1)
	{
    	for(new i; i < MAX_FIRE_OBJECTS; i++)
    	{
		    DestroyDynamicObject(fire_objects[i]);
		    fire_objects[i] = INVALID_OBJECT_ID;
    	}

		fire_id = -1;
		fire_progress = 0;

		foreach(new i: logged_players)
		{
	    	if(pData[i][pJob] == SKILL_FIRE)
	    	{
	    		DisablePlayerCheckpoint(i);
	    		DisablePlayerRaceCheckpoint(i);
	    	}

	    	update_fire_td(i);

			pTemp[i][fire_count] = 0;
		}
	}
	else 										
	{
		for(new i; i < MAX_FIRE_OBJECTS; i++)
		{
			new 
				Float:offsetx = random(4),
				Float:offsety = random(4),
				rand_1 = random(3),
				rand_2 = random(3);

			if(rand_1 == 1) offsetx = offsetx * -1.0;
			if(rand_2 == 1) offsety = offsety * -1.0;

			fire_objects[i] = CreateDynamicObject(18689, fire_info[fID][fire_x] + offsetx, fire_info[fID][fire_y] + offsety, fire_info[fID][fire_z] - 2.8, 0.0, 0.0, 0.0);
		}
		CreateExplosion(fire_info[fID][fire_x], fire_info[fID][fire_y], fire_info[fID][fire_z], 9, 2.0);

		fire_id = fID;
		fire_timer = 300;

		format(temp_string, 144, ""cLRED"[МЧС]: "cWH"Внимание обнаружен пожар! Примерное место возгорания: %s", fire_info[fID][fire_name]);
		send_fire_job(SKILL_FIRE, COLOR_LIGHTRED, temp_string);

		// format(temp_string, 144, ""cWH);
		// send_fire_job(SKILL_FIRE, COLOR_LIGHTRED, temp_string);
		foreach(new i: logged_players)
		{
	    	if(pData[i][pJob] != SKILL_FIRE) 
	    		continue;
			
			EROM(i, 4, "Отметить место на карте", 10, "/fire", ">>");
		}

		foreach(new i: logged_players)
		{
	    	if(pData[i][pJob] != SKILL_FIRE) 
	    		continue;

	    	pTemp[i][fire_count] = 0;

			update_fire_td(i);

			create_player_notify_work(i);


			PlayerTextDrawShow(i, work_notify_new[i]);
			
			//PlayerPlaySound(i, 3401, 0.0, 0.0, 0.0);
			SetTimerEx("stop_fire_sound", 5000, false, "i", i);
		}
	}
	return true;
}

stock send_fire_job(job, color, msg[])
{
	foreach(new i: logged_players)
	{
		if(!IsPlayerConnected(i)) continue;
		if(pData[i][pJob] == SKILL_FIRE)
		{
			SendClientMessage(i, color, msg);
		}
	}
	return true;
}

callback:: stop_fire_sound(playerid)
{
	PlayerTextDrawHideEx(playerid, work_notify_new[playerid]);

	return true;
}

stock end_fire()
{
	new
		price;

	// send_fire_job(SKILL_FIRE, -1, ""cLRED"МЧС: "cWH"Пожар был успешно устранен!");

	foreach(Player, id)
	{
	    if(pData[id][pJob] != SKILL_FIRE) continue;

		if(!IsPlayerInRangeOfPoint(id, 20.0, fire_info[fire_id][fire_x], fire_info[fire_id][fire_y], fire_info[fire_id][fire_z])) 
			continue;

        EROM(id, 1, "Пожар был успешно устранен", 6, "", "");
		add_player_job_skill(id, SKILL_FIRE, 5);

		price = pTemp[id][fire_count]*150;

		give_money(id, price, "Тушение пожара");

		SetPVarIntNew(id, "count_fire_money", GetPVarIntNew(id, "count_fire_money")+price);
		SetPVarIntNew(id, "count_fire_final", GetPVarIntNew(id, "count_fire_final")+1);

		

		show_notify_gui(id, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_work_19", 4000);

		update_fire_td(id);
		pTemp[id][fire_count] = 0;

		fire_progress = 0;

		fire_panel_p(id, TEXTDRAW_UPDATE);

	}
	create_fire_global_params(-1);
	return true;
}

stock update_fire_td(playerid = -1)
{
	if(playerid == -1)
	{
		foreach(new i: logged_players)
		{
			if(pData[i][pJob] != SKILL_FIRE) 
				continue;
			fire_panel_p(i, TEXTDRAW_UPDATE);
		}
		return true;
	}
	new temp_string[90];

	if(fire_id == -1)
	{

	}
	else
	{
		fire_panel_p(playerid, TEXTDRAW_UPDATE);
	}
	return true;
}

CMD:fire(playerid, params[])
{
	if(pData[playerid][pJob] != SKILL_FIRE) 
		return SendErr(playerid, "Данная команда доступна только сотрудникам МЧС");

	new
		place[100],
		temp_string[400];

	if(fire_id == -1)
		format(place, 30, ""cLRED"Пожара нет");
	else
		format(place, 30, ""cLRED"%s", fire_info[fire_id][fire_name]);

	if(IsPlayerInAnyVehicle(playerid))
	{
		if(GetPlayerVehicleModel(playerid) == 407)
		{	

			format(temp_string, 400, "\
				"cGREY"Значение\t"cGREY"Статус\n\
				"cLRED"1. "cWH"Отметить место активного пожара \t%s\n\
				"cLRED"2. "cWH"Заправить пожарную машину \t "cLRED"%d литров", place, vehicle[GetPlayerVehicleID(playerid)][cWater]);

			return SPD(playerid, DIALOG_FIRE_PANEL, DIALOG_STYLE_TABLIST_HEADERS, !""cLRED"Работа пожарного", temp_string, !"Выбрать", !"Закрыть");
		}
	}

	format(temp_string, 400, "\
		"cGREY"Значение\t"cGREY"Статус\n\
		"cLRED"1. "cWH"Отметить место пожара \t%s\n\
		"cLRED"2. "cWH"Заправить пожарную машину", place);

	return SPD(playerid, DIALOG_FIRE_PANEL, DIALOG_STYLE_TABLIST_HEADERS, !""cLRED"Работа пожарного", temp_string, !"Выбрать", !"Закрыть");
	
}

stock get_nearest_gydrant(playerid)
{
    new
	    Float:new_distance,
	    Float:max_distance = 30000.0,
	    gydrant;

	for(new i; i < MAX_GYDRANTS; i++)
	{
		new_distance = GetPlayerDistanceFromPoint(playerid, Gydrants[i][0],Gydrants[i][1],Gydrants[i][2]);

		if(max_distance > new_distance)
		{
			max_distance = new_distance;
			gydrant = i;
		}
	}
	return gydrant;
}


stock get_fire_rank_name(rank_name[18], rank)
{
	switch(rank)
	{
		case 1: rank_name = "Пожарный стажер";
		case 2: rank_name = "Лейтенант";
		case 3: rank_name = "Старший лейтенант";
		case 4: rank_name = "Капитан";
		case 5: rank_name = "Старший капитан";
	}
	return true;
}


stock dialog_all_fire(playerid, dialogid, response, listitem, inputtext[])
{

	switch(dialogid)
	{
		case DIALOG_FIRE_PANEL:
		{
			if(!response) 
				return true;

			switch(listitem)
			{
				case 0:
				{
					if(fire_id == -1) 
						return SendErr(playerid, "В данный момент пожара нет");

					SetPlayerCheckpoint(playerid, fire_info[fire_id][fire_x], fire_info[fire_id][fire_y], fire_info[fire_id][fire_z], 5.0);
					status_navigator_player(playerid, TEXTDRAW_SHOW);
					SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
				}
				case 1:
				{
					if(!IsPlayerInAnyVehicle(playerid) || GetPlayerVehicleModel(playerid) != 407)
						return SendInf(playerid, "Вы должны находиться в транспорте МЧС!");

					new v = GetPlayerVehicleID(playerid);

					if(vehicle[v][cWater] + FIRE_WATER_PER_FILL >= MAX_FIRE_WATER_FILLED + 1)
						return SendErr(playerid, "Автоцистерна Вашего транспорта полна!");

					new is_near;
					for(new i; i < MAX_GYDRANTS; i++)
					{
						if(!IsPlayerInRangeOfPoint(playerid, 10.0, Gydrants[i][0], Gydrants[i][1], Gydrants[i][2])) continue;
						is_near++;
					}

					if(is_near)
					{
						new
							available = MAX_FIRE_WATER_FILLED - vehicle[v][cWater],
							price = floatround(available * floatdiv(float(FIRE_WATER_PRICE), float(FIRE_WATER_PER_FILL)));

						if(available < FIRE_WATER_PER_FILL) return SendErr(playerid, "Автоцистерна Вашего транспорта полна!");

						new 
							temp_string[128];

						format(temp_string, 128, "\
							"cWH"Вы хотите залить в пожарную машину %d литров воды?\n\
							Стоимость %d литров воды: "cGR"%d рублей", available, available, price);

						return SPD(playerid, DIALOG_FIRE_WATER_BUY, DIALOG_STYLE_MSGBOX, !""cLRED"Заправка водой", temp_string, !"Далее", !"Назад");
					}
					else
					{
						new 
							i = get_nearest_gydrant(playerid);

						SetPlayerCheckpoint(playerid, Gydrants[i][0], Gydrants[i][1], Gydrants[i][2], 5.0);
						status_navigator_player(playerid, TEXTDRAW_SHOW);
						SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");

						return true;
					}
				}
			}
		}
		case DIALOG_FIRE_WATER_BUY: 
		{

			if(!response) 
				return PC_EmulateCommand(playerid, "/fire");

			new
				v = GetPlayerVehicleID(playerid),
				available = MAX_FIRE_WATER_FILLED - vehicle[v][cWater],
				price = floatround(available * floatdiv(float(FIRE_WATER_PRICE), float(FIRE_WATER_PER_FILL)));

			if(available < FIRE_WATER_PER_FILL) 
				return SendErr(playerid, "Автоцистерна Вашего транспорта полна");

			if(price < 1 || price > 500000) 
				return true;

			if(GetPlayerMoneyEx(playerid) < price) 
				return NoMoney(playerid);

			if(!IsPlayerInAnyVehicle(playerid) || GetPlayerVehicleModel(playerid) != 407)
				return SendInf(playerid, "Вы должны находиться в транспорте МЧС, который имеет пожарную машину");

			if(GetPVarIntNew(playerid, "fueling_fire_car")) 
				return true;

			SetPVarIntNew(playerid, "fueling_fire_car", 1);


			new
				Float:x, Float:y, Float:z;

			GetPlayerPos(playerid, x, y, z);

			give_money(playerid, -price, "Залил с гидранта");

			while(vehicle[v][cWater] < MAX_FIRE_WATER_FILLED - 1)
			{
				wait_ms(1000);

				if(IsPlayerInRangeOfPoint(playerid, 15.0, x, y, z))
				{
					vehicle[v][cWater] += 35;
					if(vehicle[v][cWater] >= MAX_FIRE_WATER_FILLED)
					{
						vehicle[v][cWater] = MAX_FIRE_WATER_FILLED;
						format(String144,sizeof(String144),"\
						"cLRED"Воды в цистернах:\n\
						"cWH"%d/%d литров", vehicle[v][cWater], MAX_FIRE_WATER_FILLED);
						UpdateDynamic3DTextLabelText(vehicle[v][cMechText], -1, String144);	


						break;
					} 
				}
				else
				{
					SendInf(playerid, "Вы прервали заправку автоцистерны!");
					format(String144,sizeof(String144),"\
					"cLRED"Воды в цистернах:\n\
					"cWH"%d/%d литров", vehicle[v][cWater], MAX_FIRE_WATER_FILLED);
					UpdateDynamic3DTextLabelText(vehicle[v][cMechText], -1, String144);	
					break;
				}
			}
			DeletePVarNew(playerid, "fueling_fire_car");

			return true;

		}
	}
	return true;
}

