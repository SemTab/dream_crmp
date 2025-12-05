



stock enter_pickup_sklad(playerid)
{

	if(GetPVarIntNew(playerid, "miner_type_work") != STAP_JOB_MINER_SKLAD)
		return true;

	new
		price;

	price = (get_job_level(playerid, SKILL_MINER) * 100) * (GetPVarInt(playerid,"miner_job_count")*50);


	DestroyDynamicPickup(mine_player_pickup[playerid][0]);
	DestroyDynamicPickup(mine_player_pickup[playerid][1]);
	DestroyDynamicPickup(mine_player_pickup[playerid][2]);

	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
	RemovePlayerAttachedObject(playerid, 6);

	DisablePlayerCheckpoint(playerid);

	SetPVarIntNew(playerid, "miner_job_count", GetPVarIntNew(playerid, "miner_job_count")+5);

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

    format(String144, sizeof(String144), "Вы уже заработали "cGR"%d "cWH"рублей!", price);
    SendInf(playerid, String144);

	return true;
}