new Float:gSnowRace[18][3] =
{
	{284.5143,2597.4932,13.4203},
	{111.5935,2598.4976,12.5537},
	{-105.1448,2602.4197,13.768},
	{-313.3444,2594.6421,12.6447},
	{-434.4280,2579.6948,21.5716},
	{-460.1840,2488.4409,28.5129},
	{-414.1746,2407.3640,20.3563},
	{-290.1125,2450.4827,16.1341},
	{-170.9638,2447.5264,14.9122},
	{-66.2565,2421.2944,14.9117},
	{71.1246,2464.0068,14.9100},
	{108.1855,2334.9998,17.0037},
	{285.5334,2350.7126,22.1768},
	{410.3174,2370.6350,23.9676},
	{507.1519,2472.6428,10.5290},
	{381.3823,2576.6887,13.6064},
	{356.2004,2600.1104,11.9683},
	{0.0, 0.0, 0.0}
};

new Float:gSnowRaceSpawn[8][4] =
{
	{481.9245,2591.7087,10.2977,91.1032},
	{481.9518,2593.7849,10.2810,92.5303},
	{481.8946,2595.4973,10.2767,89.1648},
	{481.7939,2597.1667,10.2818,91.1966},
	{481.7132,2598.9143,10.2817,92.1788},
	{481.6909,2600.7527,10.2854,93.6434},
	{481.5640,2602.5623,10.2817,91.6799},
	{481.3810,2604.4810,10.2761,93.0623}	
};


stock create_snow_race_area()
{

	arSnowRace = CreateDynamicSphere(570.6920,2597.5859,11.5958, 1.0, 0, 0);
	arSnowRaceRegister = create_circle_pickup(570.6920,2597.5859,11.5958, TRIGGER_LRED);

	CreateDynamic3DTextLabel(""cWH"Гонка на снегоходах\n\
		"cLRED"[Регистрация]", CWHITE, 569.8751,2597.2668,11.5976, 5.0,INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);

	return true;
}


CMD:snow_racestart(playerid, params[])
{
	if(pData[playerid][pAdmin] < 7)
		return true;
		//return NoCMD(playerid);

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, ""cWH"Используйте: /snow_racestart [минуты] - используйте -1 для отмены гонки");

	if(params[0] == -1)
	{
		snow_race_time_start = 0;
		remove_sound_snow_race_snow();
		return true;
	}

	reset_winner_snow_race_info();

	remove_sound_snow_race_snow();
	//create_sound_snow_race_snow();

	snow_race_time_start = params[0] ? params[0] * 60 : 2;

	static str[128];
	format(str,sizeof(str), "[Мероприятие] Мероприятие 'Гонка на снегоходах' начнётся через %s!", time_to_words(snow_race_time_start));
	SendClientMessageToAll(COLOR_YELLOW, str);
	SendClientMessageToAll(COLOR_YELLOW, "[Мероприятие] Регистрация проводится возле зимней гоночной трассы! (( /gps - Развлечения - Гонки на снегоходах ))");

	snow_race_info[snow_status] = 1;
	snow_race_info[snow_maxcount] = 8; 
	return true;
}
/*
stock start_snow_race_new()
{
	reset_winner_snow_race_info();

	remove_sound_snow_race_snow();
	create_sound_snow_race_snow();

	new 
		race_timse = 15;

	snow_race_time_start = race_timse ? race_timse * 60 : 2;

	static str[128];
	format(str,sizeof(str), "[Мероприятие] Мероприятие 'Гонка на снегоходах' начнётся через %s!", time_to_words(snow_race_time_start));
	SendClientMessageToAll(COLOR_YELLOW, str);
	SendClientMessageToAll(COLOR_YELLOW, "[Мероприятие] Регистрация проводится возле зимней гоночной трассы! (( /gps - Развлечения - Гонки на снегоходах ))");

	snow_race_info[snow_status] = 1;
	snow_race_info[snow_maxcount] = 8; 
	return true;
}
*/
/*
callback:: snow_race_start_mode()
{
	if(!snow_race_time_start) 
		return true;
	
	foreach(new i : logged_players)
	{
		if(!IsPlayerConnected(i))
			continue;
		
		if(GetPVarIntNew(i, "race_window_open") == 1)
		{
			gui_interface_race_snow_start(i, TEXTDRAW_UPDATE);
		}
	}

	snow_race_time_start--;

	if(!snow_race_time_start) 
		return start_snow_race(); 

	if(snow_race_time_start == 30 || snow_race_time_start == 90 || snow_race_time_start == 120 || snow_race_time_start == 150 || snow_race_time_start == 200 || snow_race_time_start == 250 || snow_race_time_start == 350 || snow_race_time_start == 500)
	{
		static str[128];
		format(str,sizeof(str), "[Мероприятие] Мероприятие 'Гонка на снегоходах' начнётся через %s!", time_to_words(snow_race_time_start));
		SendClientMessageToAll(COLOR_YELLOW, str);

		return SendClientMessageToAll(COLOR_YELLOW, "[Мероприятие] Регистрация проводится возле зимней гоночной трассы! (( /gps - Развлечения - Гонки на снегоходах ))");
	}

	else if(snow_race_time_start == 45)
	{
		foreach(new i : Player_In_Snow_Race)
		{
			if(!IsPlayerConnected(i))
				continue;
			
			create_sound_snow_race(i);

			gui_interface_race_snow_start(i, TEXTDRAW_HIDE);

			TogglePlayerAllHudElements(i, HUD_ELEMENT_HIDE);

			SetPlayerVirtualWorld(i, i+1);
			SetPlayerPos(i, 555.0018,2601.6775,11.4216);
			SetPlayerFacingAngle(i, 89.2074);

			hide_hud_element(i);

			TogglePlayerControllable(i, false);

			new 
				c1 = random(255);

			snow_race_info[snow_car][i] = CreateVehicle(471, 555.0244,2602.8062,10.9034,89.2074, c1, c1, -1);
			SetVehicleVirtualWorld(snow_race_info[snow_car][i], GetPlayerVirtualWorld(i));

			InterpolateCameraPos(i, 647.252685, 2619.896972, 17.791107, 550.956176, 2603.320068, 12.204793, 5000);
			InterpolateCameraLookAt(i, 644.775634, 2615.575927, 17.351171, 555.804016, 2602.132568, 11.907790, 5000);	
		}

	}
	else if(snow_race_time_start < 45)
	{

		return true;
	}

	return true;
}

callback:: snow_race_start_player()
{

	snow_race_timer_start();
	remove_sound_snow_race_snow();

    return true;
}

stock create_sound_snow_race_snow()
{
	/*new 
		sound_random = random(7);

	format(String64, sizeof(String64), "http://dl.b-rp.ru/sound_game/newyear_music_%d.mp3", sound_random+1);
	sound_zone_stream[10] = CreateStreamSource(-1509.5198,1608.2966,36.7735, 50.0, -1, -1, String64);
	return true;
} 
*/
stock remove_sound_snow_race_snow()
{
	DestroyStreamSource(sound_zone_stream[7]);
	return true;
}


stock create_sound_snow_race(playerid)
{
	/*PlayerPlayStream(playerid, "");

	new 
		sound_random = random(7);
	format(String64, sizeof(String64), "http://dl.b-rp.ru/sound_game/newyear_music_%d.mp3", sound_random+1);
	PlayerPlayStream(playerid, String64);*/

	return true;
}

stock remove_sound_snow_race(playerid)
{
	//PlayerPlayStream(playerid, "");

	return true;
}


stock gui_interface_race_snow_start(playerid, status)
{

	switch(status)
	{
		case TEXTDRAW_SHOW:
		{
			TextDrawShowForPlayer(playerid, race_interface_g_snow[0]);
			TextDrawShowForPlayer(playerid, race_interface_g_snow[1]);
			TextDrawShowForPlayer(playerid, race_interface_g_snow[2]);
			TextDrawShowForPlayer(playerid, race_interface_g_snow[5]);

			create_player_button_race_snow(playerid);

			if(GetPVarIntNew(playerid, "reg_in_snow_race"))
			{
				PlayerTextDrawSetString(playerid, race_player_button_snow[playerid], "brilliantother:race_button_2");
				PlayerTextDrawShow(playerid, race_player_button_snow[playerid]);	
			}
			else
			{
				PlayerTextDrawSetString(playerid, race_player_button_snow[playerid], "brilliantother:race_button_1");
				PlayerTextDrawShow(playerid, race_player_button_snow[playerid]);					
			}

			format(String144, sizeof(String144), "%s", time_to_string(race_time_start));
			TextDrawSetString(race_interface_g_snow[3], String144);
			TextDrawShowForPlayer(playerid, race_interface_g_snow[3]);

			format(String144, sizeof(String144), "%d_RUB", 1000);
			TextDrawSetString(race_interface_g_snow[4], String144);
			TextDrawShowForPlayer(playerid, race_interface_g_snow[4]);

			SelectTextDraw(playerid, COLOR_BLUE);

			SetPVarIntNew(playerid, "race_window_open", 1);

			TogglePlayerAllHudElements(playerid, HUD_ELEMENT_HIDE);


		}
		case TEXTDRAW_HIDE:
		{
			TextDrawHideForPlayer(playerid, race_interface_g_snow[0]);
			TextDrawHideForPlayer(playerid, race_interface_g_snow[1]);
			TextDrawHideForPlayer(playerid, race_interface_g_snow[2]);
			TextDrawHideForPlayer(playerid, race_interface_g_snow[3]);
			TextDrawHideForPlayer(playerid, race_interface_g_snow[4]);	
			TextDrawHideForPlayer(playerid, race_interface_g_snow[5]);
			
			PlayerTextDrawHideEx(playerid, race_player_button_snow[playerid]);	

			CancelSelectTextDraw(playerid);	

			DeletePVarNew(playerid, "race_window_open");

			TogglePlayerAllHudElements(playerid, HUD_ELEMENT_SHOW);
		}
		case TEXTDRAW_UPDATE:
		{
			if(GetPVarIntNew(playerid, "reg_in_snow_race"))
			{
				PlayerTextDrawSetString(playerid, race_player_button_snow[playerid], "brilliantother:race_button_2");
				PlayerTextDrawShow(playerid, race_player_button_snow[playerid]);	
			}
			else
			{
				PlayerTextDrawSetString(playerid, race_player_button_snow[playerid], "brilliantother:race_button_1");
				PlayerTextDrawShow(playerid, race_player_button_snow[playerid]);					
			}

			format(String144, sizeof(String144), "%s", time_to_string(race_time_start));
			TextDrawSetString(race_interface_g_snow[3], String144);
			TextDrawShowForPlayer(playerid, race_interface_g_snow[3]);

			format(String144, sizeof(String144), "%d_RUB", 1000);
			TextDrawSetString(race_interface_g_snow[4], String144);
			TextDrawShowForPlayer(playerid, race_interface_g_snow[4]);

			SelectTextDraw(playerid, COLOR_BLUE);
		}
	}


	return true;
}


stock gui_interface_timer_st_snow(playerid, time)
{

	TextDrawShowForPlayer(playerid, race_timer_snow[0]);

	format(String64, sizeof(String64), "%s", time_to_string(time));
	TextDrawSetString(race_timer_snow[1], String64);
	TextDrawShowForPlayer(playerid, race_timer_snow[1]);


	return true;
}


stock disconnect_player_in_snow_race(playerid)
{

	if(snow_race_info[snow_status] == 1 && GetPVarIntNew(playerid, "reg_in_snow_race"))
	{
		snow_race_info[snow_count] --;
	}
	else if(snow_race_info[snow_status] >= 2 && GetPVarIntNew(playerid, "reg_in_snow_race"))
	{
		snow_race_info[snow_count] --;
		if(snow_race_info[snow_car][playerid] != INVALID_VEHICLE_ID)
		{
			DestroyVehicle(snow_race_info[snow_car][playerid]);
			snow_race_info[snow_car][playerid] = INVALID_VEHICLE_ID;
		}
		SnowRaceTimer[playerid] = 0;
	}
	return true;
}

stock invite_to_snow_race_player(playerid)
{

	if(!pData[playerid][pLicenses][LIC_DRIVING]) 
		return SendErr(playerid, "У Вас нет лицензии на авто");

	if(snow_race_info[snow_status] != 1)
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_snow_race_5", 3500);	
		return SendErr(playerid, "Регистрация на гонку на снегоходах сейчас закрыта");
	}

	if(snow_race_info[snow_count] == snow_race_info[snow_maxcount])
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_snow_race_4", 3500);	
		return SendErr(playerid, "Все места на гонку на снегоходах заняты");
	}

	if(GetPlayerMoneyEx(playerid) < 1000)
		return SendErr(playerid, "У Вас недостаточно денег для регистрации");

	if(GetPVarIntNew(playerid, "reg_in_snow_race") == 1)
		return SendErr(playerid, "Вы уже зарегистрированы на гонку!");

	give_money(playerid, -1000, "Регистрация на гонку");

	SetPVarIntNew(playerid, "reg_in_snow_race", 1);
	snow_race_info[snow_count] ++;

	SetPVarIntNew(playerid, "race_player_number", snow_race_info[snow_count]+1);

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_snow_race_1", 3500);	

	SendSucc(playerid, "Вы зарегистрировались на гонку");
	SendInf(playerid, "Не покидайте место регистрации, поскольку будете исключены из гонки.");

	Iter_Add(Player_In_Snow_Race, playerid);

	return true;

}


stock start_snow_race()
{
	if(snow_race_info[snow_status] != 1)
		return printf("[A] Гонка не запущена (Ошибка #2412)");



	reset_winner_snow_race_info();
	
	if(snow_race_info[snow_count] < 2)
	{
		SendClientMessageToAll(COLOR_YELLOW, "[Мероприятие] На мероприятие 'Гонки на снегоходах' не было собрано нужное количество участников!");

		snow_race_info[snow_end_timer] = 0;
		snow_race_info[snow_status] = 0;
		snow_race_info[snow_count] = 0;
		snow_race_info[snow_maxcount] = 0;
		snow_race_info[snow_timer] = 0;
		snow_race_info[snow_lastplace] = 0;

		reset_winner_snow_race_info();

		foreach(new i : Player_In_Snow_Race)
		{
			reset_player_snow_race(i);
			spawn_before_snow_race(i);

		}
		return true;

	}

	snow_race_info[snow_status] = 2;
	snow_race_info[snow_prizepool] = snow_race_info[snow_count]*1000;

	new
		count;

	foreach(new i : Player_In_Snow_Race)
	{
		if(!IsPlayerConnected(i))
			continue;

		SetPlayerVirtualWorld(i, 1);

		create_sound_snow_race(i);
		count++;
		DestroyVehicle(snow_race_info[snow_car][i]);

		spawn_car_in_snow_race(i, count);
		spawn_cp_in_snow_race(i);

		SetCameraBehindPlayer(i);

		vehicle[snow_race_info[snow_car][i]][cFuel] = 80;
		SetVehicleVirtualWorld(snow_race_info[snow_car][i], 1);
		PutPlayerInVehicleEx(i, snow_race_info[snow_car][i], 0);
		TogglePlayerControllable(i, 0);

		snow_race_info[snow_timer] = 15;

		show_hud_element(i);
		show_hud_hungry(i);

		//race_timer_start();

		TogglePlayerAllHudElements(i, HUD_ELEMENT_SHOW);

		//gui_interface_timer_st_snow(i, snow_race_info[snow_timer]);
	}
	SendSnowRaceMessage(COLOR_YELLOW, "[Мероприятие] До старта гонок на снегохода 15 секунд. /leave_snow - покинуть гонку");
	return true;
}


stock reset_winner_snow_race_info()
{
	for(new i; i < 8; i++)
	{
		snow_winner_info[i][winner_name] = 0;
		snow_winner_info[i][winner_timer] = 0;
	}
	return true;
}

stock spawn_car_in_snow_race(playerid, count)
{
	snow_race_info[snow_car][playerid] = CreateVehicle(471, gSnowRaceSpawn[count-1][0], gSnowRaceSpawn[count-1][1], gSnowRaceSpawn[count-1][2], gSnowRaceSpawn[count-1][3], -1, -1, -1);


}

stock spawn_cp_in_snow_race(playerid)
{
	SetPVarIntNew(playerid, "RaceCP", 1);
	SetPVarIntNew(playerid, "RaceLap", 1);

	SetPlayerRaceCheckpoint(playerid, 0, gSnowRace[0][0], gSnowRace[0][1], gSnowRace[0][2], gSnowRace[1][0], gSnowRace[1][1], gSnowRace[1][2], 8.0);

	return true;
}

stock snow_race_checkpoint_enter(playerid)
{
	if(!GetPVarIntNew(playerid, "RaceCP") && !GetPVarIntNew(playerid, "reg_in_snow_race"))
		return true;

	DisablePlayerRaceCheckpoint(playerid);
	SetPVarIntNew(playerid, "RaceCP", GetPVarIntNew(playerid, "RaceCP")+1);

	give_next_cp_snow_race(playerid, GetPVarIntNew(playerid, "RaceCP"));
	return true;
}

stock give_next_cp_snow_race(playerid, id)
{
	if(!GetPVarIntNew(playerid, "RaceCP") && !GetPVarIntNew(playerid, "reg_in_snow_race"))
		return true;

	if(gSnowRace[id-1][0] == 0.0)
	{
		if(GetPVarIntNew(playerid, "RaceLap") < MAX_LAP_SNOW_RACE)
		{
			SetPVarIntNew(playerid, "RaceLap", GetPVarIntNew(playerid, "RaceLap")+1);
			SetPVarIntNew(playerid, "RaceCP", 1);
			SetPlayerRaceCheckpoint(playerid, 0, gSnowRace[0][0], gSnowRace[0][1], gSnowRace[0][2], gSnowRace[1][0], gSnowRace[1][1], gSnowRace[1][2], 8.0);


	        format(String64, sizeof(String64), "~y~KPY‚O‹ %d/%d", GetPVarIntNew(playerid, "RaceLap"), MAX_LAP_SNOW_RACE);
	        GameTextForPlayer(playerid, String64, 5000, 1);


		}
		else 
			end_snow_race_for_players(playerid);
	}
	else if(gSnowRace[id][0] == 0.0)
	{
		SetPlayerRaceCheckpoint(playerid, 1, gSnowRace[id-1][0], gSnowRace[id-1][1], gSnowRace[id-1][2], -1, -1, -1, 4.0);
	}
	else
	{
		SetPlayerRaceCheckpoint(playerid, 0, gSnowRace[id-1][0], gSnowRace[id-1][1], gSnowRace[id-1][2], gSnowRace[id][0], gSnowRace[id][1], gSnowRace[id][2], 8.0);
	}
	return true;
}

stock end_snow_race_for_players(playerid)
{
	if(snow_race_info[snow_lastplace] < 3)
	{
		snow_race_info[snow_lastplace]++;
		new 
			prizemoney = floatround(snow_race_info[snow_prizepool]/3);

		give_money(playerid, prizemoney, "Выигрыш на гонке на снегоходах");

		SendSucc(playerid, "Вы закончили гонку на призовом месте!");

		snow_winner_info[snow_race_info[snow_lastplace]-1][winner_name] = pData[playerid][pMysqlID];

		snow_winner_info[snow_race_info[snow_lastplace]-1][winner_timer] = SnowRaceTimer[playerid];


		spawn_before_snow_race(playerid);
		if(snow_race_info[snow_lastplace] == 3)
		{
			snow_race_info[snow_end_timer] = 60;
			SendSnowRaceMessage(CBLUE, "[Мероприятие] До окончания осталась 1 минута");
		}
	}
	else
	{
		snow_race_info[snow_lastplace]++;
		SendSucc(playerid, "Вы закончили гонку");
		spawn_before_snow_race(playerid);

		if(snow_race_info[snow_lastplace] == snow_race_info[snow_count])
			snow_race_info[snow_end_timer] = 10;
	}
	reset_player_snow_race(playerid);
	return true;
}

stock reset_player_snow_race(playerid)
{
	DeletePVarNew(playerid, "reg_in_snow_race");
	DeletePVarNew(playerid, "RaceCP");
	if(snow_race_info[snow_car][playerid] != INVALID_VEHICLE_ID)
	{
		DestroyVehicle(snow_race_info[snow_car][playerid]);
		snow_race_info[snow_car][playerid] = INVALID_VEHICLE_ID;
	}
	SnowRaceTimer[playerid] = 0;
	if(Iter_Contains(Player_In_Snow_Race, playerid))
		Iter_Remove(Player_In_Snow_Race, playerid);
	return true;
}

stock SendSnowRaceMessage(color, string[])
{
	foreach(new i : Player_In_Snow_Race)
	{
		SendClientMessage(i, color, string);
	}
	return true;
}

stock spawn_before_snow_race(playerid)
{
	new
		pos = random(4);

	switch(pos)
	{
		case 0: SetPlayerPos(playerid, 571.1696,2591.2673,11.6071);
		case 1:	SetPlayerPos(playerid, 570.0312,2599.9363,11.5988);
		case 2:	SetPlayerPos(playerid, 570.0247,2604.1821,11.5987);
		case 3:	SetPlayerPos(playerid, 570.8483,2607.1313,11.6461);
	}
	SetPlayerVirtualWorld(playerid, 0);

	return true;
}

callback:: end_snow_race_timer()
{
	if(snow_race_info[snow_status] != 3)
		return true;

	snow_race_info[snow_end_timer] --;

	if(snow_race_info[snow_end_timer] == 1)
	{
		snow_race_info[snow_end_timer] --;
		foreach(new i : Player_In_Snow_Race)
		{
			reset_player_snow_race(i);
			spawn_before_snow_race(i);
			show_notify_gui(i, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_snow_race_3", 3500);
		}
		snow_race_info[snow_status] = 0;
		snow_race_info[snow_count] = 0;
		snow_race_info[snow_maxcount] = 0;
		snow_race_info[snow_timer] = 0;
		snow_race_info[snow_lastplace] = 0;
		snow_race_info[snow_end_timer] = 0;
		SendClientMessageToAll(COLOR_YELLOW, !"[Мероприятие] Мероприятие 'Гонки на снегоходах' завершилось!");



	}
	return true;
}

callback:: snow_race_player_timer()
{
	if(snow_race_info[snow_status] == 3)
	{
		foreach(new i : Player_In_Snow_Race)
		{
			SnowRaceTimer[i]++;
		}
	}
}
callback:: snow_race_timer_start()
{
	if(snow_race_info[snow_status] != 2)
		return true;

	snow_race_info[snow_timer] --;

	if(snow_race_info[snow_timer])
	{
		foreach(new i : Player_In_Snow_Race)
		{	
			vehicle_engine_status(GetPlayerVehicleID(i), false);
			//gui_interface_timer_st_snow(i, snow_race_info[snow_timer]);
		}
	}
	else if(!snow_race_info[snow_timer])
	{
		foreach(new i : Player_In_Snow_Race)
		{
			TextDrawHideForPlayer(i, race_timer_snow[0]);
			TextDrawHideForPlayer(i, race_timer_snow[1]);

			TogglePlayerControllable(i, 1);

			vehicle_engine_status(GetPlayerVehicleID(i), true);

			GameTextForPlayer(i, "~g~GO! GO! GO!", 5000, 3);
		}
		snow_race_info[snow_status] = 3;
		return SendClientMessageToAll(COLOR_YELLOW, !"[Мероприятие] Мероприятие 'Гонки на снегоходах' началось!");
	}
	return true;
}

CMD:leaveracesnow(playerid)
{
	leave_snow_race_player(playerid);
	return true;
}

stock death_snow_race_player(playerid)
{

	if(!GetPVarIntNew(playerid, "reg_in_snow_race") && !GetPVarIntNew(playerid, "RaceCP"))
		return true;

	remove_sound_snow_race(playerid);
	snow_race_info[snow_count] --;
	
	reset_player_snow_race(playerid);
	spawn_before_snow_race(playerid);

	DeletePVarNew(playerid, "race_player_number");

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_snow_race_2", 3500);	

	SendSucc(playerid, "Вы покинули гонку");
	return true;
}

stock leave_snow_race_player(playerid)
{

	if(!GetPVarIntNew(playerid, "reg_in_snow_race") && !GetPVarIntNew(playerid, "RaceCP"))
		return true;

	remove_sound_snow_race(playerid);
	snow_race_info[snow_count] --;
	
	reset_player_snow_race(playerid);
	spawn_before_snow_race(playerid);

	DeletePVarNew(playerid, "race_player_number");

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_snow_race_2", 3500);	

	SendSucc(playerid, "Вы покинули гонку");

	return true;
}

