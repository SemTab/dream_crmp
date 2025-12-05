



stock enter_pickup_sklad(playerid)
{

	if(GetPVarIntNew(playerid, "miner_type_work") != STAP_JOB_MINER_SKLAD)
		return true;

	add_player_job_skill(playerid, SKILL_MINER);

	DestroyDynamicPickup(mine_player_pickup[playerid][0]);
	DestroyDynamicPickup(mine_player_pickup[playerid][1]);
	DestroyDynamicPickup(mine_player_pickup[playerid][2]);

	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
	RemovePlayerAttachedObject(playerid, 6);

	DisablePlayerCheckpoint(playerid);

	sklad[0][sklad_other_count_1] += random(10);
	sklad[0][sklad_other_count_2] += random(10);
	sklad[0][sklad_other_count_3] += random(10);
	sklad[0][sklad_other_count_4] += random(10);
	sklad[0][sklad_other_count_5] += random(10);
	update_sklad_3d_text();

	SetPVarIntNew(playerid, "miner_job_count", GetPVarIntNew(playerid, "miner_job_count")+1);


	new
		price;

	if(get_job_level(playerid, SKILL_MINER) == 1)
	{
		price = GetPVarIntNew(playerid,"miner_job_count")*400;
	}
	else if(get_job_level(playerid, SKILL_MINER) == 2)
	{
		price = floatround((GetPVarIntNew(playerid,"miner_job_count")*400)*1.2);
	}
	else if(get_job_level(playerid, SKILL_MINER) == 3)
	{
		price = floatround((GetPVarIntNew(playerid,"miner_job_count")*400)*1.4);
	}
	else if(get_job_level(playerid, SKILL_MINER) == 4)
	{
		price = floatround((GetPVarIntNew(playerid,"miner_job_count")*400)*1.6);
	}
	else if(get_job_level(playerid, SKILL_MINER) == 5)
	{
		price = floatround((GetPVarIntNew(playerid,"miner_job_count")*400)*2);
	}

 	SCM(playerid, -1, "");
 	SendInf(playerid, "Вы успешно занесли готовую руду на склад!");
 	SendInf(playerid, "Отправляйтесь обратно в шахту для продолжения работы!");

 	SetPVarIntNew(playerid, "miner_type_work", STAP_JOB_MINER_MINING);


	if(get_job_level(playerid, SKILL_MINER) < 5)
	{
		SFCM(playerid, COLOR_ORANGE, "[Навык] "cWH"Ваш навык шахтера: "cGR"%d уровень"cWH"", get_job_level(playerid, SKILL_MINER));
		SFCM(playerid, COLOR_ORANGE, "[Навык] "cWH"Для повышения навыка необходимо выполнить работу "cGR"%d"cWH" раз!", get_job_level_next(playerid, SKILL_MINER));
	}
	else
	{
		SFCM(playerid, COLOR_ORANGE, "[Навык] "cWH"Ваш навык шахтера: "cGR"%d уровень", get_job_level(playerid, SKILL_MINER));
	}

	check_quest_prize_start(playerid, 5);
	check_quest_prize_start(playerid, 6);
	check_quest_prize_start(playerid, 2);

    format(String144, sizeof(String144), "Вы уже заработали "cGR"%d "cWH"рублей!", price);
    SendInf(playerid, String144);

    show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:info_gui_miner_5", 4000);

	return true;
}