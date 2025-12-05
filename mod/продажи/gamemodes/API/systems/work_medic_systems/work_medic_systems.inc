

stock create_work_hospital_pickup()
{


	pickup_start_job_hospital = create_circle_pickup(-1071.5912,-1464.1051,23.4042, TRIGGER_LRED);

	CreateDynamic3DTextLabel("Снаряжение Медика\n"cLRED"[Встаньте на пикап]", -1, -1071.5912,-1464.1051,23.4042, 2.0);

	return true;
}


cmd:createhospital(playerid)
{
    if(pData[playerid][pAdmin] < 8)
    	return NoCMD(playerid);	

	if(call_hospital_id == -1)
	{
		create_help_people(random(sizeof hospital_help));
		SendSucc(playerid, "Пострадавшего не было, поэтому Вы его создали!");
	}
	else
	{
		create_help_people(-1); 
		SendSucc(playerid, "Вы убрали существующего пострадавшего!");
	}

	return true;
}

cmd:mhelp(playerid)
{
	if(pData[playerid][pFraction] != 2)
		return SendErr(playerid, "Вы не работаете медиком!");

	if(call_hospital_id == -1)
		return SendErr(playerid, "Активных вызовов нет в данный момент!");

	SetPlayerCheckpoint(playerid, hospital_help[call_hospital_id][actor_hospital_x], hospital_help[call_hospital_id][actor_hospital_y], hospital_help[call_hospital_id][actor_hospital_z], 5.0);
	status_navigator_player(playerid, TEXTDRAW_SHOW);
	SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");

	SendSucc(playerid, "Вы успешно приняли вызов, метка была выставлена в вашем навигаторе!");


	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_work_22", 5000);

	return true;

}

stock take_medick_element(playerid)
{
	if(pData[playerid][pFraction] != 2)
		return SendErr(playerid, "Вы не работаете медиком!");

	if(GetPVarIntNew(playerid, "medic_element_1") == 1)
		return SendErr(playerid, "Вы не смогли взять медикаменты и дефрибеллятор, так как они у Вас уже имеются!");

	SetPVarIntNew(playerid, "medic_element_1", 1);

	SendSucc(playerid, "Вы успешно взяли медикаменты, а именно адреналин и дефрибеллятор!");
	SendInf(playerid, "Следить за вызовами можно с помощью команды - /mhelp");

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_work_21", 5000);

	return true;
}


stock help_actor_panel(playerid)
{
	if(pData[playerid][pFraction] != 2)
		return SendErr(playerid, "Вы не работаете медиком!");

	if(!GetPVarIntNew(playerid, "medic_element_1"))
		return SendErr(playerid, "У вас отсутствуют нужные медикаменты для лечения!");

	create_hospital_npc_p(playerid);

	new fmt_str[144];

	SelectTextDraw(playerid, COLOR_BLUE);

	TextDrawShowForPlayer(playerid, hospital_npc[0]);
	TextDrawShowForPlayer(playerid, hospital_npc[1]);
	TextDrawShowForPlayer(playerid, hospital_npc[2]);
	TextDrawShowForPlayer(playerid, hospital_npc[3]);	
	TextDrawShowForPlayer(playerid, hospital_npc[4]);

	ApplyAnim(playerid, "MEDIC", "CPR", 4.1, 1, 1, 1, 0, 0, 1);

	format(fmt_str, 144, "%s", get_help_med_n(hospital_name_actor));
	PlayerTextDrawSetString(playerid, hospital_npc_p[0][playerid], fmt_str);
	PlayerTextDrawShow(playerid,hospital_npc_p[0][playerid]);

	format(fmt_str, 144, "%d", call_hospital_progress);
	PlayerTextDrawSetString(playerid, hospital_npc_p[2][playerid], fmt_str);
	PlayerTextDrawShow(playerid,hospital_npc_p[2][playerid]);

	SetTimerEx("update_puls_actor", 1000, true, "i", playerid);

	return true;
}

stock hide_npc_heal_panel(playerid)
{

	TextDrawHideForPlayer(playerid, hospital_npc[0]);
	TextDrawHideForPlayer(playerid, hospital_npc[1]);
	TextDrawHideForPlayer(playerid, hospital_npc[2]);
	TextDrawHideForPlayer(playerid, hospital_npc[3]);	
	TextDrawHideForPlayer(playerid, hospital_npc[4]);

	PlayerTextDrawHideEx(playerid, hospital_npc_p[0][playerid]);
	PlayerTextDrawHideEx(playerid, hospital_npc_p[1][playerid]);
	PlayerTextDrawHideEx(playerid, hospital_npc_p[2][playerid]);

	return true;
}

stock actor_heal(playerid)
{
	CancelSelectTextDrawEx(playerid);
	create_help_people(-1);
	ClearAnimations(playerid, 0);

	timer_puls_actor[playerid] = SetTimerEx("update_puls_actor", 1000, false, "i", playerid);

	return true;
}

stock select_medic_type(playerid, type)
{
	switch(type)
	{
		case TYPE_MED_ADRENALIN:
		{
			if(gettime() < time_user_med[playerid])
				return SendInf(playerid, "Использовать можно раз в 10 секунд один из элементов!");

			SendSucc(playerid, "Вы вкололи одну ампулу адреналина!");

			use_adrenalin_actor++;

			new mese[90];
			format(mese,sizeof(mese),"достал(а) шприц с адреналином и произвел(а) укол для поднятия пульса");
			MeAction(playerid, mese);

			if(use_adrenalin_actor > 3)
			{
				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_work_24", 5000);
				call_hospital_progress -= 45;
				use_adrenalin_actor = 0;
				SendInf(playerid, "Вы использовали больше 3-ех ампул адреналина и пациенту стало хуже!");
			}
			else
			{

				call_hospital_progress += 15;

				ApplyAnim(playerid, "MEDIC", "CPR", 4.1, 1, 1, 1, 0, 0, 1);

				format(String144, sizeof(String144), ""cWH"Использование адреналина увеличило пульс до %d единиц", call_hospital_progress);
				SendSucc(playerid, String144);
			}
			time_user_med[playerid] = gettime()+10;
		}
		case TYPE_MED_DEF:
		{
			if(gettime() < time_user_med[playerid])
				return SendInf(playerid, "Использовать можно раз в 10 секунд один из элементов!");

			SendSucc(playerid, "Вы использовали дефрибеллятор!");

			new mese[90];
			format(mese,sizeof(mese),"достал(а) дефрибеллятор и произвел(а) манипуляции для поднятия пульса");
			MeAction(playerid, mese);

			use_def_actor++;

			if(use_def_actor > 3)
			{
				use_def_actor = 0;
				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:notify_player_work_25", 5000);
				call_hospital_progress -= 45;
				SendInf(playerid, "Вы использовали больше 3 раз дефибриллятор и пациенту стало хуже!");
			}
			else
			{
				
				call_hospital_progress += 25;

				ApplyAnim(playerid, "MEDIC", "CPR", 4.1, 1, 1, 1, 0, 0, 1);

				format(String144, sizeof(String144), ""cWH"Использование дефибриллятора увеличило пульс до %d единиц", call_hospital_progress);
				SendSucc(playerid, String144);
			}
			time_user_med[playerid] = gettime()+10;
		}
	}

	return true;
}

stock create_help_people(hospitalID)
{
	new 
		fmt_str[144];

	if(hospitalID == -1)
	{
    	DestroyActor(hospital_actor);

		call_hospital_id = -1;
		use_adrenalin_actor = 0;
		use_def_actor = 0;
		use_pills_actor = 0;
		call_hospital_progress = 0;

		DestroyDynamic3DTextLabel(hospital_actor_text);

		foreach(new i: logged_players)
		{
			if(pData[i][pFraction] == 2)
			{			
				KillTimer(timer_puls_actor[i]);
	    		DisablePlayerRaceCheckpoint(i);
	    	}
		}
	}
	else 
	{

		hospital_actor = CreateActor(RandomEx(10,250), hospital_help[hospitalID][actor_hospital_x], hospital_help[hospitalID][actor_hospital_y], hospital_help[hospitalID][actor_hospital_z], hospital_help[hospitalID][actor_hospital_r]); 
		ApplyActorAnimation(hospital_actor,  "CRACK", "Crckidle1", 4.1, 1, 0, 0, 0, 0);

		hospital_actor_text = CreateDynamic3DTextLabel("Пострадавший\n"cLRED"[ALT]", -1, hospital_help[hospitalID][actor_hospital_x], hospital_help[hospitalID][actor_hospital_y], hospital_help[hospitalID][actor_hospital_z], 5.0);

		call_hospital_id = hospitalID;
		hospital_timer = 300;

		format(fmt_str, 144, "Диспетчер: "cWH"Внимание! Был замечен пострадавший! Примерное место: %s", hospital_help[hospitalID][hospital_help_name]);
		send_medic_job(COLOR_LIGHTRED, fmt_str);

		format(fmt_str, 144, "Диспетчер: "cWH"Для того, чтобы отметить место на карте, напишите команду "cLRED"/mhelp");
		send_medic_job(COLOR_LIGHTRED, fmt_str);

		hospital_name_actor = random(10);

		foreach(new i: logged_players)
		{
			if(pData[i][pFraction] == 2)
			{

				create_player_notify_work(i);
				PlayerTextDrawSetString(i, work_notify_new[i], "brilliantother:hospital_7");
				PlayerTextDrawShow(i, work_notify_new[i]);

				SetTimerEx("stop_medic_notify", 5000, false, "i", i);
			}

		}
	}
	return true;
}

callback:: stop_medic_notify(playerid)
{

	PlayerTextDrawHideEx(playerid, work_notify_new[playerid]);

	return true;
}


callback:: update_puls_actor(playerid)
{
	if(pData[playerid][pFraction] == 2)
	{	
		new 
			puls_update, fmt_str[144];

		puls_update = call_hospital_progress+random(15);


		format(fmt_str, 144, "%d", puls_update);
		PlayerTextDrawSetString(playerid, hospital_npc_p[1][playerid], fmt_str);
		PlayerTextDrawShow(playerid,hospital_npc_p[1][playerid]);

		format(fmt_str, 144, "%d", call_hospital_progress);
		PlayerTextDrawSetString(playerid, hospital_npc_p[2][playerid], fmt_str);
		PlayerTextDrawShow(playerid,hospital_npc_p[2][playerid]);

		if(call_hospital_progress >= 100)
		{
			if(pData[playerid][pFraction] == 2)
			{
				SendSucc(playerid, "Вы успешно вылечили пострадавшего! Благодаря Вам он будет жить!");
				SendSucc(playerid, "За это Вам положено денежное вознаграждение!");

				hide_npc_heal_panel(playerid);
				CancelSelectTextDraw(playerid);

				ClearAnimations(playerid);

				give_money(playerid, 1750, "Лечение пострадавшего");

				create_help_people(-1);

				KillTimer(timer_puls_actor[playerid]);

				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_work_23", 5000);
			}

			return true;
		}
	}

	return true;

}

stock send_medic_job(color, msg[])
{
	foreach(new i: logged_players)
	{
		if(!IsPlayerConnected(i)) continue;
		if(pData[i][pFraction] == 2)
		{
			SendClientMessage(i, color, msg);
		}
	}
	return true;
}
