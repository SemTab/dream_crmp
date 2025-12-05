stock load_bankwork_info() // OnGameModeInit
{
	CreateDynamicPickup(1275, 21, 2376.6301,-2129.6448,22.1167);
	CreateDynamic3DTextLabel(""cBLUE"Работа инкассатора\n"cWH"[Встаньте на пикап]", -1, 2376.6301,-2129.6448,22.1167, 5.0);
	bankwork_area_job[0] = CreateDynamicSphere(2376.6301,-2129.6448,22.1167, 1.0, 0, -1);

	CreateDynamicPickup(1275, 21, 362.3373,1364.4431,11.8959);
	CreateDynamic3DTextLabel(""cBLUE"Работа инкассатора\n"cWH"[Встаньте на пикап]", -1, 362.3373,1364.4431,11.8959, 5.0);
	bankwork_area_job[1] = CreateDynamicSphere(362.3373,1364.4431,11.8959, 1.0, 0, -1);

	CreateDynamicPickup(1275, 21, 1860.6772,2037.2057,15.8850);
	CreateDynamic3DTextLabel(""cBLUE"Работа инкассатора\n"cWH"[Встаньте на пикап]", -1, 1860.6772,2037.2057,15.8850, 5.0);
	bankwork_area_job[2] = CreateDynamicSphere(1860.6772,2037.2057,15.8850, 1.0, 0, -1);

	bankwork_area_load[0] = CreateDynamicSphere(2380.2808,-2116.4436,21.7747, 4.0, 0);

	bankwork_area_load[1] = CreateDynamicSphere(376.9771,1400.4796,11.8959, 4.0, 0);

	bankwork_area_load[2] = CreateDynamicSphere(1826.0754,2040.0364,15.8850, 4.0, 0);
	return true;
}

stock dialog_bank_work(playerid, dialogid, response, inputtext[])// OnDialogResponse
{
	switch(dialogid)
	{
		case DIALOG_SELECT_BANK_WORK:
		{
			if(!response)
				return true;

			new 
				id = strval(inputtext);

			if(GetPVarIntNew(id, "bank_work"))
			{
				return SendErr(playerid, "Данный человек уже работает");
			}

			if(GetPlayerDistanceToPlayer(playerid, id) > 10)
			{
				return SendErr(playerid, "Игрок слишком далеко");
			}

			if(pData[id][pLevel] < 6)
			{
				return SendErr(playerid, "У игрока недостаточный уровень для работы");
			}

			if(!pData[id][pLicenses][LIC_DRIVING])
			{
				return SendErr(playerid, "У игрока нет водительских прав");
			}

			format(String256, sizeof(String256), "Вы отправили %s предложение о совместной работе инкассатором", inputtext[3]);
			SendSucc(playerid, String256);


			return invite_for_bank_work(playerid, id);


		}
		case DIALOG_ACCEPT_BANK_WORK:
		{
			new 
				string[128],
				id = GetPVarIntNew(playerid, "offer_bank_work")-1;

			DeletePVarNew(playerid, "offer_bank_work");

			if(!response)
			{
				if(GetPVarIntNew(id, "invite_bank_work") == playerid+1)
				{
					DeletePVarNew(id, "invite_bank_work");
					format(string, sizeof(string), "%s отклонил Ваше предложение о совместной работе", pData[playerid][pNickname]);
					SendInf(id, string);
				}
				format(string, sizeof(string), "Вы отклонили предложение %s о совместной работе", pData[id][pNickname]);
				return SendInf(playerid, string);
			}

			if(GetPVarIntNew(id, "invite_bank_work") != playerid+1)
				return SendErr(playerid, "Данное предложение неактивно");

			if(GetPVarIntNew(id, "bank_work"))
				return SendErr(playerid, "Данный человек уже работает");

			if(GetPlayerDistanceToPlayer(playerid, id) > 10)
				return SendErr(playerid, "Игрок слишком далеко");

			DeletePVarNew(id, "invite_bank_work");

			format(string, sizeof(string), "Вы приняли предложение "cGR"%s "cWH"о совместной работе", pData[id][pNickname]);
			SendSucc(playerid, string);
			format(string, sizeof(string), ""cGR"%s "cWH"принял Ваше предложение о совместной работе", pData[playerid][pNickname]);
			SendSucc(id, string);

			SetPVarIntNew(playerid, "bank_work", 1);
			SetPVarIntNew(id, "bank_work", 1);

			new
				type;

			if(IsPlayerInRangeOfPoint(playerid, 20.0, 2376.6301,-2129.6448,22.1167))
			{	
				type = 1;
			}

			else if(IsPlayerInRangeOfPoint(playerid, 20.0, 362.3373,1364.4431,11.8959))
			{	
				type = 2;
			}

			else if(IsPlayerInRangeOfPoint(playerid, 20.0, 1860.6772,2037.2057,15.8850))
			{	
				type = 3;
			}
			else 
			{
				SendErr(playerid, "Произошла техническая ошибка");
				SendErr(id, "Произошла техническая ошибка");

				new 
					partner = GetPVarIntNew(playerid, "bank_work_partner")-1;

				end_bank_work(playerid);

				end_bank_work(partner);
				return true;
			}
			return start_bank_work(playerid, id, type);
		}
	}
	return true;
}

stock area_bankwork_job(playerid, areaid)// OnPlayerEnterDynamicArea
{
	for(new i; i < 3; i++)
	{
		if(areaid == bankwork_area_job[i])
		{
			if(pData[playerid][pLevel] < 6)
				return SendErr(playerid, "Работа инкассатора доступна с 6 уровня");

			if(!pData[playerid][pLicenses][LIC_DRIVING])
				return SendErr(playerid, "У Вас нет водительских прав");

			panel_bank_work(playerid, TEXTDRAW_SHOW);

		}
		if(areaid == bankwork_area_load[i])
		{
			if(!GetPVarIntNew(playerid, "bank_work_load"))
				return true;

			new 
				partnerid = GetPVarIntNew(playerid, "bank_work_partner")-1;

			DisablePlayerCheckpoint(playerid);
			DisablePlayerCheckpoint(partnerid);

			format(String144, sizeof (String144), "Нажмите "cGR"гудок"cWH", чтобы начать %s денег", GetPVarIntNew(playerid, "bank_work_load") == 1 ? ("разгрузку") : ("загрузку"));
			SendInf(playerid, String144);
			return true;
		}
	}
	if(areaid == bank_work_area_atm[playerid])
	{
		if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
		{
				
			new 
				partnerid = GetPVarIntNew(playerid, "bank_work_partner")-1;

			DisablePlayerCheckpoint(playerid);
			DisablePlayerCheckpoint(partnerid);

			if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
			{
				new
					carid = GetPlayerVehicleID(playerid);

				if(carid != bank_work_vehicle[playerid])
				{
					return SendErr(playerid, "Вы должны находиться в инкассаторском транспорте");
				}

				DestroyDynamicArea(bank_work_area_atm[playerid]);

				format(String64, sizeof(String64), "Вы начали %s", GetPVarIntNew(playerid, "bank_work_type") == 1 ? ("разгрузку") : ("загрузку"));
				SendSucc(playerid, String64);

				new 
					partner = GetPVarIntNew(playerid, "bank_work_partner")-1;

				SetPVarIntNew(partner, "bank_work_vehid", carid);

				if(GetPVarIntNew(playerid, "bank_work_type") == 1)
				{
					SendInf(playerid, "Помогите напарнику взять деньги и пополнить банкомат");
					SendInf(partner, "Возьмите деньги и пополните банкомат");
				}
				else if(GetPVarIntNew(playerid, "bank_work_type") == 2)
				{
					SendInf(playerid, "Помогите напарнику забрать деньги с банкомата и отнести в машину");
					SendInf(partner, "Заберите деньги с банкомата и отнесите в машину");
				}
				return true;
			}
			return true;
		}
		return true;
	}
	return true;
} 

stock full_bank_work_count(playerid, partner, type_load)
{
	new 
		type = random(3);

	SetPlayerCheckpoint(playerid, gBankLoadPos[type][0], gBankLoadPos[type][1], gBankLoadPos[type][2], 4.0);
	SetPlayerCheckpoint(partner, gBankLoadPos[type][0], gBankLoadPos[type][1], gBankLoadPos[type][2], 4.0);

	SetPVarIntNew(partner, "bank_work_load", type_load);
	
	switch(type_load)
	{
		case 1:
		{
			SendErr(playerid, "В инкассаторской машине слишком много денег");
			SendInf(playerid, "Отправляйтесь к банку для разгрузки");

			SendErr(partner, "В инкассаторской машине слишком много денег");
			SendInf(partner, "Отправляйтесь к банку для разгрузки");
		}
		case 2:
		{
			SendErr(playerid, "В инкассаторской машине нет  денег");
			SendInf(playerid, "Отправляйтесь к банку для загрузки");

			SendErr(partner, "В инкассаторской машине нет  денег");
			SendInf(partner, "Отправляйтесь к банку для загрузки");
		}
	}
	return true;
}

stock give_next_atm(playerid, partner, old_atm)
{
	new 
		atm = random(ATM_COUNT);

	if(atm == old_atm && atm != 0)
	{
		atm = atm-1;
	}
	else if(atm == old_atm && atm == 0)
	{
		atm = 1;
	}

	new 
		Float:x, 
		Float:y,
		Float:z;

	GetPlayerPos(playerid, x, y, z);

	new 
		price_bank_work = floatround(GetDistanceBetweenPoints(x, y, z, gATMC[atm][0], gATMC[atm][1], gATMC[atm][2]));

	SetPVarIntNew(playerid, "price_bank_work_dist", price_bank_work);
	SetPVarIntNew(partner, "price_bank_work_dist", price_bank_work);

	SetPlayerCheckpoint(playerid, gATMC[atm][0], gATMC[atm][1], gATMC[atm][2], 8.0);
	SetPlayerCheckpoint(partner, gATMC[atm][0], gATMC[atm][1], gATMC[atm][2], 8.0);

	bank_work_area_atm[partner] = CreateDynamicSphere(gATMC[atm][0], gATMC[atm][1], gATMC[atm][2], 8.0, 0, 0);

	SetPVarIntNew(playerid, "bank_work_atm", atm+1);
	SetPVarIntNew(partner, "bank_work_atm", atm+1);

	SendInf(playerid, "Отправляйтесь к следующему банкомату");
	SendInf(partner, "Отправляйтесь к следующему банкомату");
	return true;
}

stock end_bank_work(playerid)// Окончание работы
{
	if(GetPVarIntNew(playerid, "bank_work"))
	{
		DeletePVarNew(playerid, "bank_work_atm");
		DeletePVarNew(playerid, "bank_work");
		DeletePVarNew(playerid, "bank_work_type");
		DeletePVarNew(playerid, "bank_work_partner");
		DeletePVarNew(playerid, "bank_work_role");
		DeletePVarNew(playerid, "bank_work_take_money");
		DeletePVarNew(playerid, "bank_work_vehid");
		DeletePVarNew(playerid, "no_money_in_car");
		DeletePVarNew(playerid, "bank_work_load");
		DeletePVarNew(playerid, "bank_money_take");
		DeletePVarNew(playerid, "bank_money_give");

		

		if(bank_work_vehicle[playerid] != INVALID_VEHICLE_ID)
		{
			new 
				vehid = bank_work_vehicle[playerid];

			DestroyDynamicArea(bank_work_area_atm[playerid]);
			DestroyVehicle(bank_work_vehicle[playerid]);

			DestroyDynamic3DTextLabel(bank_work_text[vehid]);

			bank_work_text[vehid] = Text3D:INVALID_3DTEXT_ID;
			bank_work_vehicle[playerid] = INVALID_VEHICLE_ID;

			new 
				v = pTemp[playerid][rent_car];

			if(v == INVALID_VEHICLE_ID) 
				return true;

			show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:info_gui_vehicle_unrent", 3500);
			
			pTemp[playerid][rent_car] = INVALID_VEHICLE_ID;
			pTemp[playerid][rent_car_spawn_timer] = INVALID_TIMER_ID;

		}

		RemovePlayerAttachedObject(playerid, 0);

		SetPlayerArmour(playerid, 0);

		SetPlayerSkinEx(playerid,pData[playerid][pSkin]);
		
		
		SendSucc(playerid, "Вы закончили работу инкассатора");
	}
	return true;
}

stock select_bank_work_partner(playerid)// Выбор напарника для работы
{
	new 
		string_select[256],
		count;

	foreach(new i: logged_players)
	{
		if(IsPlayerConnected(i) && GetPlayerDistanceToPlayer(playerid, i) < 5)
		{
			if(GetPVarIntNew(playerid,	"bank_work") || i == playerid)
				continue;

			count ++;

			format(string_select, sizeof(string_select), "%s"cBLUE"%d. "cWH"%s\n", string_select, count, pData[i][pNickname]);
		}
	}

	if(count == 0)
		return SendErr(playerid, "Рядом нет игроков, с которыми можно начать работу");

	SPD(playerid, DIALOG_SELECT_BANK_WORK, DIALOG_STYLE_INPUT, !""cBLUE"Выберите себе напарника", "Введите ID напарника:\n", !"Выбрать", !"Отмена");
	return true;
}

stock invite_for_bank_work(playerid, id)// Инвайт о совместной работе
{
	format(String256, sizeof(String256), "\n\
		"cWH"Игрок "cBLUE"%s "cWH"предложил Вам начать совместную работу инкассатором\n\
		"cWH"Вы действительно хотите начать совместную работу?\n\
		"cWH"Нажмите "cBLUE"'Принять' "cWH"для начала работы", pData[playerid][pNickname]);
	SPD(id, DIALOG_ACCEPT_BANK_WORK, DIALOG_STYLE_MSGBOX, !""cBLUE"Работа инкассатора", String256, !"Принять", !"Отмена");

	SetPVarIntNew(playerid, "invite_bank_work", id+1);
	SetPVarIntNew(id, "offer_bank_work", playerid+1);
	return true;
}

stock start_bank_work(playerid, id, type) // Начало работы
{
	new 
		pos = random(5);

	new 
		position = random(3);

	bank_work_vehicle[id] = CreateVehicle(BANK_WORK_VEHICLE, gBankWorkSpawnPos[type-1][pos][0], gBankWorkSpawnPos[type-1][pos][1], gBankWorkSpawnPos[type-1][pos][2], gBankWorkSpawnPos[type-1][pos][3], -1, -1, -1);
	

	vehicle[bank_work_vehicle[id]][cFuel] = 90.0;
	vehicle[bank_work_vehicle[id]][cHealth] = 1000.0;
	vehicle[bank_work_vehicle[id]][cIsCreated] = true;
	vehicle[bank_work_vehicle[id]][cOwnTo] = VEHICLE_BANK_WORK;
	vehicle[bank_work_vehicle[id]][cLock] = 1;
	vehicle[bank_work_vehicle[id]][consumables_oil] = 1000.0;

	vehicle_lock_status(bank_work_vehicle[id], false);

	vehicle[bank_work_vehicle[id]][cFuel] = 80;

	new
		v = GetPlayerVehicleID(id);	

	pTemp[id][rent_car] = bank_work_vehicle[id];

	if(pData[playerid][pSex] == 1)
	{
		SetPlayerSkin(playerid, SKIN_MALE_BANK_WORK);
	}
	else
	{
		SetPlayerSkin(playerid, SKIN_FEMALE_BANK_WORK);
	}

	if(pData[id][pSex] == 1)
	{
		SetPlayerSkin(id, SKIN_MALE_BANK_WORK);
	}
	else
	{
		SetPlayerSkin(id, SKIN_FEMALE_BANK_WORK);
	}

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_work_5", 5000);
	show_notify_gui(id, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_work_5", 5000);

	SetVehicleHealth(bank_work_vehicle[id], 3000.0);

	PutPlayerInVehicle(id, bank_work_vehicle[id], 0);
	PutPlayerInVehicle(playerid, bank_work_vehicle[id], 1);

	SetPlayerArmour(playerid, 100);
	SetPlayerArmour(id, 100);

	if(bank_work_text[bank_work_vehicle[id]] != Text3D:INVALID_3DTEXT_ID) DestroyDynamic3DTextLabelEx(bank_work_text[bank_work_vehicle[id]]);

	bank_work_text[bank_work_vehicle[id]] = CreateDynamic3DTextLabel("_",-1,0.0,0.0,0.0,10.0,INVALID_PLAYER_ID, bank_work_vehicle[id]);

	if(get_job_level(playerid, SKILL_BANK) < 5)
	{
		SFCM(playerid, COLOR_ORANGE, "[Навык] "cWH"Ваш навык инкассатора: "cGR"%d уровень"cWH"", get_job_level(playerid, SKILL_BANK));
		SFCM(playerid, COLOR_ORANGE, "[Навык] "cWH"Для повышения навыка необходимо совершить "cGR"%d"cWH" рейсов!", get_job_level_next(playerid, SKILL_BANK));
	}
	else
	{
		SFCM(playerid, COLOR_ORANGE, "[Навык] "cWH"Ваш навык инкассатора: "cGR"%d уровень", get_job_level(playerid, SKILL_BANK));
	}

	if(get_job_level(id, SKILL_BANK) < 5)
	{
		SFCM(id, COLOR_ORANGE, "[Навык] "cWH"Ваш навык инкассатора: "cGR"%d уровень"cWH"", get_job_level(id, SKILL_BANK));
		SFCM(id, COLOR_ORANGE, "[Навык] "cWH"Для повышения навыка необходимо совершить "cGR"%d"cWH" рейсов!", get_job_level_next(id, SKILL_BANK));
	}
	else
	{
		SFCM(id, COLOR_ORANGE, "[Навык] "cWH"Ваш навык инкассатора: "cGR"%d уровень", get_job_level(id, SKILL_BANK));
	}

	new
		string[128];

	format(string, sizeof(string), "Вы начали работу инкассатора совместно с "cGR"%s"cWH". Ваша роль: "cGR"Водитель", pData[playerid][pNickname]);
	SendSucc(id, string);

	format(string, sizeof(string), "Вы начали работу инкассатора совместно с "cGR"%s"cWH". Ваша роль: "cGR"Помощник", pData[id][pNickname]);
	SendSucc(playerid, string);

	SetPVarIntNew(playerid, "bank_work_partner", id+1);
	SetPVarIntNew(id, "bank_work_partner", playerid+1);

	SetPVarIntNew(id, "bank_work_role", 1);
	SetPVarIntNew(playerid, "bank_work_role", 2);


	panel_bank_work(playerid, TEXTDRAW_HIDE);
	panel_bank_work(id, TEXTDRAW_HIDE);

	new 
		type_work = random(2);

	if(type_work == 0)
	{
		bank_work_count[bank_work_vehicle[id]] = 10000000;
	}

	else
	{
		bank_work_count[bank_work_vehicle[id]] = 0;
	}

	update_text_bank_work_vehicle(bank_work_vehicle[id]);

	if(debug_mode)
	{
		format(String144, sizeof(String144), "[DEBUG] start_bank_work | driver %d | partner %d | city %d | type %d", id, playerid, type, type_work);
		SendClientMessage(playerid, -1, String144);
		SendClientMessage(id, -1, String144);
	}

	SetPVarIntNew(playerid, "bank_work_type", type_work + 1);
	SetPVarIntNew(id, "bank_work_type", type_work + 1);

	starting_bank_job(playerid, id);
	return true;
}

stock update_text_bank_work_vehicle(carid)
{
	format(String64, sizeof(String64), ""cGR"Денег в машине:\n\
		"cWH"%i рублей", bank_work_count[carid]);

	UpdateDynamic3DTextLabelText(bank_work_text[carid], CWHITE, String64);
	return true;
}

stock starting_bank_job(playerid, id)
{
	new 
		atm = random(ATM_COUNT);

	new 
		Float:x, 
		Float:y,
		Float:z;

	GetPlayerPos(playerid, x, y, z);

	new 
		price_bank_work = floatround(GetDistanceBetweenPoints(x, y, z, gATMC[atm][0], gATMC[atm][1], gATMC[atm][2]));

	SetPVarIntNew(playerid, "price_bank_work_dist", price_bank_work);
	SetPVarIntNew(id, "price_bank_work_dist", price_bank_work);

	SetPlayerCheckpoint(playerid, gATMC[atm][0], gATMC[atm][1], gATMC[atm][2], 8.0);
	SetPlayerCheckpoint(id, gATMC[atm][0], gATMC[atm][1], gATMC[atm][2], 8.0);

	bank_work_area_atm[id] = CreateDynamicSphere(gATMC[atm][0], gATMC[atm][1], gATMC[atm][2], 8.0, 0, 0);

	SetPVarIntNew(playerid, "bank_work_atm", atm+1);
	SetPVarIntNew(id, "bank_work_atm", atm+1);
	return true;
}

stock key_bank_work(playerid, newkeys)
{
	if (newkeys & KEY_WALK)
	{
		for(new i; i < MAX_VEHICLES; i++)
		{
			if(GetVehicleModel(i) != BANK_WORK_VEHICLE)
				continue;

			new Float:x, Float:y, Float:z, Float:a;
			GetVehiclePos(i, x, y, z);
			GetVehicleZAngle(i, a);

			x = x - (-3.0*floatsin(a, degrees));
			y = y -3.0*floatcos(a, degrees);

			if(IsPlayerInRangeOfPoint(playerid,1,x,y,z))
			{
				new 
					vehid = GetPVarIntNew(playerid, "bank_work_vehid");

				
				if(GetPVarIntNew(playerid, "bank_work_type") == 1 && GetPVarIntNew(playerid, "bank_work_take_money"))
				{
					return SendErr(playerid, "Отнесите деньги к банкомату");
				}
				else if(GetPVarIntNew(playerid, "bank_work_type") == 2 && !GetPVarIntNew(playerid, "bank_work_take_money"))
				{
					return SendErr(playerid, "Для начала возьмите деньги с банкомата");
				}

		        else if(GetPVarIntNew(playerid, "bank_work_type") == 1 && vehid == i)
		        {
		        	new 	
						money = RandomEx(50000,1000000);

					if(bank_work_count[i] < money)
					{
						money = bank_work_count[i];
						bank_work_count[i] = 0;
						SetPVarIntNew(playerid, "no_money_in_car", 1);
					}
					else 
					{
						bank_work_count[i] -= money;
					}
					update_text_bank_work_vehicle(i);
					SetPVarIntNew(playerid, "bank_work_take_money", money);

					format(String64, sizeof(String64), "Вы взяли "cGR"%i"cWH" рублей", money);
					SendSucc(playerid, String64);
					SendInf(playerid, "Отнесите их к банкомату");

					SetPlayerAttachedObject(playerid, 0, 18189, 5, 0.123000, -0.029000, -0.057999, 0.000000, -93.900001, 14.600000, 1.000000, 1.00, 1.000000);
					return true;
		        }
		        else if(GetPVarIntNew(playerid, "bank_work_type") == 2 && vehid == i)
		        {
		        	bank_work_count[i] += GetPVarIntNew(playerid, "bank_work_take_money");
					update_text_bank_work_vehicle(i);


					new 
						oldcount = GetPVarIntNew(playerid, "bank_money_take"),
						partner = GetPVarIntNew(playerid, "bank_work_partner")-1,
						salary = floatround(GetPVarIntNew(playerid, "bank_work_take_money")*0.002);


					SetPVarIntNew(playerid, "bank_money_take", oldcount + GetPVarIntNew(playerid, "bank_work_take_money"));
					SetPVarIntNew(partner, "bank_money_take", oldcount + GetPVarIntNew(playerid, "bank_work_take_money"));

					final_gruz_bank_people(playerid);
					final_gruz_bank_people(partner);

					format(String64, sizeof(String64), "Вы положили в инкассаторскую машину "cGR"%i"cWH" рублей", GetPVarIntNew(playerid, "bank_work_take_money"));
					SendSucc(playerid, String64);
					DeletePVarNew(playerid, "bank_work_take_money");

					RemovePlayerAttachedObject(playerid, 0);

					new 
						old_atm = GetPVarIntNew(playerid, "bank_work_atm")-1;

					DeletePVarNew(playerid, "bank_work_atm");
					DeletePVarNew(partner, "bank_work_atm");
					DeletePVarNew(playerid, "bank_work_vehid");

					if(bank_work_count[i] > 10000000)
					{
						return full_bank_work_count(playerid, partner, 1);
					}
					give_next_atm(playerid, partner, old_atm);
					return true;
		        }
		        break;
			}
		}
	}
	if(newkeys & KEY_CROUCH)
	{
		for(new i; i < 3; i++)
		{
			if(IsPlayerInDynamicArea(playerid, bankwork_area_load[i]))
			{
				if(!GetPVarIntNew(playerid, "bank_work_load"))
					return true;

				new
					carid = GetPlayerVehicleID(playerid);

				if(carid != bank_work_vehicle[playerid])
				{
					return SendErr(playerid, "Вы должны находиться в инкассаторском транспорте");
				}

				if(GetPVarIntNew(playerid, "bank_work_load") == 1)
				{
					bank_work_count[carid] = 0;
					update_text_bank_work_vehicle(carid);

					SendSucc(playerid, "Вы разгрузили инкассаторскую машину");
				}
				else if(GetPVarIntNew(playerid, "bank_work_load") == 2)
				{
					bank_work_count[carid] = 10000000;
					update_text_bank_work_vehicle(carid);
					
					SendSucc(playerid, "Вы загрузили инкассаторскую машину");
				}

				new 
					partner = GetPVarIntNew(playerid, "bank_work_partner")-1;

				give_next_atm(partner, playerid, 0);
				return true;
			}
		}
	}
	return true;
}

stock disconnect_player_bank_work(playerid)
{
	if(GetPVarIntNew(playerid, "bank_work"))
	{
		new
			partner = GetPVarIntNew(playerid, "bank_work_partner")-1;

		end_bank_work(playerid);
		end_bank_work(partner);
	}
	return true;
}

stock panel_bank_work(playerid, status)
{
	switch(status)
	{
		case TEXTDRAW_SHOW:
		{	

			create_work_panel_bank(playerid);

			PlayerTextDrawShow(playerid, work_bank_panel_p[0][playerid]);

			if(!GetPVarIntNew(playerid, "bank_work"))
			{
				PlayerTextDrawSetString(playerid, work_bank_panel_p[1][playerid], "brilliantother:work_bank_button_1");
				PlayerTextDrawShow(playerid, work_bank_panel_p[1][playerid]);
			}
			else
			{
				PlayerTextDrawSetString(playerid, work_bank_panel_p[1][playerid], "brilliantother:work_bank_button_2");
				PlayerTextDrawShow(playerid, work_bank_panel_p[1][playerid]);
			}
			PlayerTextDrawShow(playerid, work_bank_panel_p[2][playerid]);
			SelectTextDraw(playerid, COLOR_BLUE);

		}
		case TEXTDRAW_HIDE:
		{
			PlayerTextDrawHideEx(playerid, work_bank_panel_p[0][playerid]);
			PlayerTextDrawHideEx(playerid, work_bank_panel_p[1][playerid]);
			PlayerTextDrawHideEx(playerid, work_bank_panel_p[2][playerid]);

			CancelSelectTextDraw(playerid);
		}
	}


	return true;
}

stock click_button_bank_panel(playerid)
{
	if(!GetPVarIntNew(playerid, "bank_work"))
	{
		select_bank_work_partner(playerid);

	}
	else
	{
		if(pData[playerid][pLevel] < 6)
			return SendErr(playerid, "Работа инкассатора доступна с 6 уровня");

		if(!pData[playerid][pLicenses][LIC_DRIVING])
			return SendErr(playerid, "У Вас нет водительских прав");


		new 
			partner = GetPVarIntNew(playerid, "bank_work_partner")-1;

		end_bank_work(playerid);
		end_bank_work(partner);
	}
	return true;
}

callback:: spawn_rent_car_bank_work(i, v, time)
{

	if(IsPlayerConnected(i))
	{	
		time--;

		if(!time)
		{
			new 
				partner = GetPVarIntNew(i, "bank_work_partner")-1;

			end_bank_work(i);
			end_bank_work(partner);
			return true;
		}
		pTemp[i][rent_car_spawn_timer] = SetTimerEx("spawn_rent_car_bank_work", 1000, false, "iii", i, v, time);
	}
	return true; 
}

stock final_gruz_bank_people(playerid)
{

	add_player_job_skill(playerid, SKILL_BANK, RandomEx(1, 2));

	new 
		money_final = floatround(GetPVarIntNew(playerid, "price_bank_work_dist")/0.85),
		price;

	if(get_job_level(playerid, SKILL_BANK) == 1)
	{
		if(IsActionTrue4)  
		{
			price = money_final*2;
		}
		else if(!IsActionTrue4 && IsPlayerOnlineForBonusSalary(playerid))
		{
			price = money_final*2;
		}
		else
		{
			price = money_final;
		}
	}
	else if(get_job_level(playerid, SKILL_BANK) == 2)
	{
		if(IsActionTrue4)  
		{
		
			price = floatround(money_final*1.2)*2;
		}
		else if(!IsActionTrue4 && IsPlayerOnlineForBonusSalary(playerid))
		{
			price = floatround(money_final*1.2)*2;
		}
		else
		{
			price = floatround(money_final*1.2);
		}
	}
	else if(get_job_level(playerid, SKILL_BANK) == 3)
	{
		if(IsActionTrue4)  
		{
			price = floatround(money_final*1.4)*2;
		}
		else if(!IsActionTrue4 && IsPlayerOnlineForBonusSalary(playerid))
		{
			price = floatround(money_final*1.4)*2;
		}
		else
		{
			price = floatround(money_final*1.4);
		}
	}
	else if(get_job_level(playerid, SKILL_BANK) == 4)
	{
		if(IsActionTrue4)  
		{
			price = floatround(money_final*1.6)*2;
		}
		else if(!IsActionTrue4 && IsPlayerOnlineForBonusSalary(playerid))
		{
			price = floatround(money_final*1.6)*2;
		}
		else
		{
			price = floatround(money_final*1.6);
		}
	}
	else if(get_job_level(playerid, SKILL_BANK) == 5)
	{
		if(IsActionTrue4)  
		{
			price = floatround(money_final*1.8)*2;
		}
		else if(!IsActionTrue4 && IsPlayerOnlineForBonusSalary(playerid))
		{
			price = floatround(money_final*1.8)*2;
		}
		else
		{
			price = floatround(money_final*1.8);
		}
	}

    give_money(playerid, price, "Зарплата за работу инкассатором");

	format(String144, sizeof(String144), "Вы проехали %d метров и получили за это %d рублей! Благодарим за работу!", GetPVarIntNew(playerid, "price_bank_work_dist"), price);
	SendSucc(playerid, String144);
	return true;
}