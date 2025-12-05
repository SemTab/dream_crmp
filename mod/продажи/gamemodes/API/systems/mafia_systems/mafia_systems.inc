



static const Float:position_spawn_car_mafia_1[][] =
{
	{2428.0208,-1934.8246,21.7097,270.1226},
	{2427.9705,-1931.9768,21.7081,270.1541},
	{2427.8052,-1928.9147,21.7091,270.6714},
	{2427.6838,-1923.1276,21.7092,268.6787},
	{2427.7300,-1920.1437,21.7102,268.9345},
	{2427.7847,-1917.0272,21.7135,269.3381}
};

static const Float:position_spawn_car_mafia_2[][] =
{
	{-285.4834,517.2174,12.9995,262.1890},
	{-285.0332,520.3568,13.0051,262.4390},
	{-284.6597,523.8140,13.0151,263.4611},
	{-286.1556,512.0549,12.9934,262.8392},
	{-286.5175,508.9355,12.9933,263.1727}
};

static const Float:position_spawn_car_mafia_3[][] =
{
	{1808.6930,2198.0396,15.3085,179.5529},
	{1805.5542,2198.3567,15.3478,179.0321},
	{1802.4407,2198.4868,15.4134,178.0644},
	{1797.8246,2198.4124,15.4073,181.3261},
	{1794.6587,2198.2898,15.4169,180.9817}
};

new mafia_car_model[] =
{
	412, 529, 543
};


// 10 11 12

stock get_mafia_name(mafia_id)
{
	new 
		name[20];

	switch(mafia_id)
	{
	    case 13: format(name,sizeof(name),"Тамбовская ОПГ");
		case 14: format(name,sizeof(name),"Курганская ОПГ");
		case 15: format(name,sizeof(name),"Измайловская ОПГ");
		case 0: format(name,sizeof(name),"Отсутствует");
	}



	return name;
}

stock LoadMafiaPickupsWH()// OnGameModeInit
{
	MafiaStore_3DText[0] = CreateDynamic3DTextLabel("_", -1, 789.5297, -969.0723, 1205.9318, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 10);
	MafiaStoreArea[0] = CreateDynamicSphere(789.5297, -969.0723, 1205.9318, 2.0, 10, 0);

	MafiaStore_3DText[1] = CreateDynamic3DTextLabel("_", -1, 789.5297, -969.0723, 1205.9318, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 11);
	MafiaStoreArea[1] = CreateDynamicSphere(789.5297, -969.0723, 1205.9318, 2.0, 11, 0);

	MafiaStore_3DText[2] = CreateDynamic3DTextLabel("_", -1, 789.5297, -969.0723, 1205.9318, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 12);
	MafiaStoreArea[2] = CreateDynamicSphere(789.5297, -969.0723, 1205.9318, 2.0, 12, 0);

	CreateDynamicPickup(13719, 23, 789.5297, -969.0723, 1205.9318);

	mafia_create_other();

	return true;
}

stock mafia_create_other()
{

	CreateDynamic3DTextLabel(""cWH"Автопарк Тамбовской ОПГ\n\
		"cLRED"[Встаньте на пикап]", CWHITE, 2429.2251,-1938.7162,22.0043, 5.0,INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	CreateDynamic3DTextLabel(""cWH"Автопарк Курганской ОПГ\n\
		"cLRED"[Встаньте на пикап]", CWHITE, -288.6148,506.1500,13.2562, 5.0,INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	CreateDynamic3DTextLabel(""cWH"Автопарк Измайловская ОПГ\n\
		"cLRED"[Встаньте на пикап]", CWHITE, 1789.7452,2199.4119,15.6552, 5.0,INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	


	pickup_spawn_mafia[0] = create_circle_pickup(2429.2251,-1938.7162,22.0043, TRIGGER_LRED); // Тамбовская
	pickup_spawn_mafia[1] = create_circle_pickup(-288.6148,506.1500,13.2562, TRIGGER_LRED); // Курганская
	pickup_spawn_mafia[2] = create_circle_pickup(1789.7452,2199.4119,15.6552, TRIGGER_LRED); // Измайловская

	return true;
}

stock spawn_mafia_1_vehicle(playerid)
{
	format(String512, sizeof(String512), "\
    "cGREY"Автомобиль\t"cGREY"Действие\n\
    "cBLUE"1. "cWH"%s\t"cGR"Взять\n\
    "cBLUE"2. "cWH"%s\t"cGR"Взять\n\
    "cBLUE"3. "cWH"%s\t"cGR"Взять\n\
    \t\n\
    "cWH"Доступно всего: \t"cBLUE"%d"cWH" автомобилей", 
    transport_config[mafia_car_model[0]-400][transport_name],
    transport_config[mafia_car_model[1]-400][transport_name],
    transport_config[mafia_car_model[2]-400][transport_name],
    count_mafia_1_vehicle
    );
 	SPD(playerid, DIALOG_SELECT_CAR_MAFIA_1, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Выбор автомобиля", String512, !"Выбрать", !"Закрыть"); 

 	return true;
}

stock spawn_mafia_2_vehicle(playerid)
{
	format(String512, sizeof(String512), "\
    "cGREY"Автомобиль\t"cGREY"Действие\n\
    "cBLUE"1. "cWH"%s\t"cGR"Взять\n\
    "cBLUE"2. "cWH"%s\t"cGR"Взять\n\
    "cBLUE"3. "cWH"%s\t"cGR"Взять\n\
    \t\n\
    "cWH"Доступно всего: \t"cBLUE"%d"cWH" автомобилей", 
    transport_config[mafia_car_model[0]-400][transport_name],
    transport_config[mafia_car_model[1]-400][transport_name],
    transport_config[mafia_car_model[2]-400][transport_name],
    count_mafia_2_vehicle
    );
 	SPD(playerid, DIALOG_SELECT_CAR_MAFIA_2, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Выбор автомобиля", String512, !"Выбрать", !"Закрыть"); 

 	return true;
}

stock spawn_mafia_3_vehicle(playerid)
{
	format(String512, sizeof(String512), "\
    "cGREY"Автомобиль\t"cGREY"Действие\n\
    "cBLUE"1. "cWH"%s\t"cGR"Взять\n\
    "cBLUE"2. "cWH"%s\t"cGR"Взять\n\
    "cBLUE"3. "cWH"%s\t"cGR"Взять\n\
    \t\n\
    "cWH"Доступно всего: \t"cBLUE"%d"cWH" автомобилей", 
    transport_config[mafia_car_model[0]-400][transport_name],
    transport_config[mafia_car_model[1]-400][transport_name],
    transport_config[mafia_car_model[2]-400][transport_name],
    count_mafia_3_vehicle
    );
 	SPD(playerid, DIALOG_SELECT_CAR_MAFIA_3, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Выбор автомобиля", String512, !"Выбрать", !"Закрыть"); 

 	return true;
}

stock spawn_mafia_1_veh_start(playerid, type_car)
{
	switch(type_car)
	{
		case 0:
		{
			if(count_mafia_1_vehicle == 0)
			{
				spawn_mafia_1_vehicle(playerid);
				return SendErr(playerid, "Недостаточно автомобилей!");
			}

			if(pData[playerid][pFraction] != 13)
			{
				SendErr(playerid, "Доступно только ОПГ!");
				return true;
			}	

			create_vehicle_mafia_1(playerid, 0);
		}
		case 1:
		{
			if(count_mafia_1_vehicle == 0)
			{
				spawn_mafia_1_vehicle(playerid);
				return SendErr(playerid, "Недостаточно автомобилей!");
			}

			if(pData[playerid][pFraction] != 13)
			{
				SendErr(playerid, "Доступно только ОПГ!");
				return true;
			}	


			create_vehicle_mafia_1(playerid, 1);
		}
		case 2:
		{
			if(count_mafia_1_vehicle == 0)
			{
				spawn_mafia_1_vehicle(playerid);
				return SendErr(playerid, "Недостаточно автомобилей!");
			}

			if(pData[playerid][pFraction] != 13)
			{
				SendErr(playerid, "Доступно только ОПГ!");
				return true;
			}	


			create_vehicle_mafia_1(playerid, 2);
		}
	}

	return true;
}

stock spawn_mafia_2_veh_start(playerid, type_car)
{
	switch(type_car)
	{
		case 0:
		{
			if(count_mafia_2_vehicle == 0)
			{
				spawn_mafia_2_vehicle(playerid);
				return SendErr(playerid, "Недостаточно автомобилей!");
			}

			if(pData[playerid][pFraction] != 14)
			{
				SendErr(playerid, "Доступно только ОПГ!");
				return true;
			}	

			create_vehicle_mafia_2(playerid, 0);
		}
		case 1:
		{
			if(count_mafia_2_vehicle == 0)
			{
				spawn_mafia_2_vehicle(playerid);
				return SendErr(playerid, "Недостаточно автомобилей!");
			}

			if(pData[playerid][pFraction] != 14)
			{
				SendErr(playerid, "Доступно только ОПГ!");
				return true;
			}	


			create_vehicle_mafia_2(playerid, 1);
		}
		case 2:
		{
			if(count_mafia_2_vehicle == 0)
			{
				spawn_mafia_2_vehicle(playerid);
				return SendErr(playerid, "Недостаточно автомобилей!");
			}

			if(pData[playerid][pFraction] != 14)
			{
				SendErr(playerid, "Доступно только ОПГ!");
				return true;
			}	


			create_vehicle_mafia_2(playerid, 2);
		}
	}

	return true;
}

stock spawn_mafia_3_veh_start(playerid, type_car)
{
	switch(type_car)
	{
		case 0:
		{
			if(count_mafia_3_vehicle == 0)
			{
				spawn_mafia_3_vehicle(playerid);
				return SendErr(playerid, "Недостаточно автомобилей!");
			}

			if(pData[playerid][pFraction] != 15)
			{
				SendErr(playerid, "Доступно только ОПГ!");
				return true;
			}	

			create_vehicle_mafia_3(playerid, 0);
		}
		case 1:
		{
			if(count_mafia_3_vehicle == 0)
			{
				spawn_mafia_3_vehicle(playerid);
				return SendErr(playerid, "Недостаточно автомобилей!");
			}

			if(pData[playerid][pFraction] != 15)
			{
				SendErr(playerid, "Доступно только ОПГ!");
				return true;
			}	


			create_vehicle_mafia_3(playerid, 1);
		}
		case 2:
		{
			if(count_mafia_3_vehicle == 0)
			{
				spawn_mafia_3_vehicle(playerid);
				return SendErr(playerid, "Недостаточно автомобилей!");
			}

			if(pData[playerid][pFraction] != 15)
			{
				SendErr(playerid, "Доступно только ОПГ!");
				return true;
			}	


			create_vehicle_mafia_3(playerid, 2);
		}
	}

	return true;
}



stock create_vehicle_mafia_1(playerid, veh_type)
{
	new 
		random_pos = random(5);

	new 
		c1 = 0,
		c2 = 0;	

	new 
		vehicle_mafia_1 = CreateVehicle(mafia_car_model[veh_type], position_spawn_car_mafia_1[random_pos][0], position_spawn_car_mafia_1[random_pos][1], position_spawn_car_mafia_1[random_pos][2], position_spawn_car_mafia_1[random_pos][3], c1, c2, 600);	

	format(vehicle[vehicle_mafia_1][cPlate], 20, "б0%dбб", count_mafia_1_vehicle);
	SetVehicleGosNumberPlate(vehicle_mafia_1, vehicle[vehicle_mafia_1][cPlate], "77");

	PutPlayerInVehicleEx(playerid, vehicle_mafia_1, 0);

	vehicle[vehicle_mafia_1][cFuel] = transport_config[GetVehicleModel(vehicle_mafia_1)-400][transport_tank];
	vehicle[vehicle_mafia_1][cHealth] = 1000.0;
	vehicle[vehicle_mafia_1][cIsCreated] = true;
	vehicle[vehicle_mafia_1][consumables_oil] = 1000.0;

	vehicle[vehicle_mafia_1][cOwnTo] = VEHICLE_MAFIA_1;

	vehicle[vehicle_mafia_1][cLock] = 2;

	vehicle_lock_status(vehicle_mafia_1, true);

	count_mafia_1_vehicle--;

	return true;
}

stock create_vehicle_mafia_2(playerid, veh_type)
{
	new 
		random_pos = random(5);

	new 
		c1 = 0,
		c2 = 0;	

	new 
		vehicle_mafia_2 = CreateVehicle(mafia_car_model[veh_type], position_spawn_car_mafia_2[random_pos][0], position_spawn_car_mafia_2[random_pos][1], position_spawn_car_mafia_2[random_pos][2], position_spawn_car_mafia_2[random_pos][3], c1, c2, 600);	

	format(vehicle[vehicle_mafia_2][cPlate], 20, "б0%dбб", count_mafia_2_vehicle);
	SetVehicleGosNumberPlate(vehicle_mafia_2, vehicle[vehicle_mafia_2][cPlate], "77");

	PutPlayerInVehicleEx(playerid, vehicle_mafia_2, 0);

	vehicle[vehicle_mafia_2][cFuel] = transport_config[GetVehicleModel(vehicle_mafia_2)-400][transport_tank];
	vehicle[vehicle_mafia_2][cHealth] = 1000.0;
	vehicle[vehicle_mafia_2][cIsCreated] = true;
	vehicle[vehicle_mafia_2][consumables_oil] = 1000.0;

	vehicle[vehicle_mafia_2][cOwnTo] = VEHICLE_MAFIA_2;

	vehicle[vehicle_mafia_2][cLock] = 2;

	vehicle_lock_status(vehicle_mafia_2, true);

	count_mafia_2_vehicle--;

	return true;
}

stock create_vehicle_mafia_3(playerid, veh_type)
{
	new 
		random_pos = random(5);

	new 
		c1 = 0,
		c2 = 0;	

	new 
		vehicle_mafia_3 = CreateVehicle(mafia_car_model[veh_type], position_spawn_car_mafia_3[random_pos][0], position_spawn_car_mafia_3[random_pos][1], position_spawn_car_mafia_3[random_pos][2], position_spawn_car_mafia_3[random_pos][3], c1, c2, 600);	

	format(vehicle[vehicle_mafia_3][cPlate], 20, "б0%dбб", count_mafia_3_vehicle);
	SetVehicleGosNumberPlate(vehicle_mafia_3, vehicle[vehicle_mafia_3][cPlate], "77");

	PutPlayerInVehicleEx(playerid, vehicle_mafia_3, 0);

	vehicle[vehicle_mafia_3][cFuel] = transport_config[GetVehicleModel(vehicle_mafia_3)-400][transport_tank];
	vehicle[vehicle_mafia_3][cHealth] = 1000.0;
	vehicle[vehicle_mafia_3][cIsCreated] = true;
	vehicle[vehicle_mafia_3][consumables_oil] = 1000.0;

	vehicle[vehicle_mafia_3][cOwnTo] = VEHICLE_MAFIA_3;

	vehicle[vehicle_mafia_3][cLock] = 2;

	vehicle_lock_status(vehicle_mafia_3, true);

	count_mafia_3_vehicle--;

	return true;
}

stock MafiaFracMessage(fraction, color, string[])
{
	foreach(new i: logged_players)
	{
		if(!IsPlayerConnected(i))
			continue;

		if(pData[i][pFraction] == fraction) 
			return SendClientMessage(i, color, string);
	}
	return true;
}

stock ShowMafiaWHDialog(playerid, dialogid, response, listitem, inputtext[])// OnDialogResponse
{
	switch(dialogid)
	{

	    case DIALOG_SELECT_CAR_MAFIA_1: 
	    {
	    	if(!response)
	    		return true;

	    	switch(listitem)
	    	{
		    	case 0: return spawn_mafia_1_veh_start(playerid, 0);
		    	case 1: return spawn_mafia_1_veh_start(playerid, 1);
		    	case 2: return spawn_mafia_1_veh_start(playerid, 2);
		    	case 3: return spawn_mafia_1_vehicle(playerid);
		    	case 4: return spawn_mafia_1_vehicle(playerid);
		    }
	    }
	    case DIALOG_SELECT_CAR_MAFIA_2: 
	    {
	    	if(!response)
	    		return true;
	    	
	    	switch(listitem)
	    	{
		    	case 0: return spawn_mafia_2_veh_start(playerid, 0);
		    	case 1: return spawn_mafia_2_veh_start(playerid, 1);
		    	case 2: return spawn_mafia_2_veh_start(playerid, 2);
		    	case 3: return spawn_mafia_2_vehicle(playerid);
		    	case 4: return spawn_mafia_2_vehicle(playerid);
		    }
	    }
	    case DIALOG_SELECT_CAR_MAFIA_3: 
	    {
	    	if(!response)
	    		return true;
	    	
	    	switch(listitem)
	    	{
		    	case 0: return spawn_mafia_3_veh_start(playerid, 0);
		    	case 1: return spawn_mafia_3_veh_start(playerid, 1);
		    	case 2: return spawn_mafia_3_veh_start(playerid, 2);
		    	case 3: return spawn_mafia_3_vehicle(playerid);
		    	case 4: return spawn_mafia_3_vehicle(playerid);
		    }
	    }

		case DIALOG_LMENU_SELECT_MAFIA:
		{
			if(!response)
				return 1;

			new 
				fracid;

			switch(pData[playerid][pFraction])
			{
				case 13: fracid = 0;
				case 14: fracid = 1;
				case 15: fracid = 2;
			}

			if(!IsAMafia(playerid))
						return SendErr(playerid, "Данная команда доступна только ОПГ");

			if(pData[playerid][pRank] < 10)
				return SendErr(playerid, "Команда доступна только лидеру");	

			switch(listitem)
			{
				case 0:
				{

					if(MafiaInfo[fracid][mStatus] == 1)
					{
						MafiaInfo[fracid][mStatus] = 0;
						SendSucc(playerid, "Вы открыли склад ОПГ");
					}
					else
					{
						MafiaInfo[fracid][mStatus] = 1;
						SendSucc(playerid, "Вы закрыли склад ОПГ");
					}
					new 
						frac_mes[144];

					format(frac_mes, sizeof (frac_mes), "[ОПГ] "cWH"%s %s[%i] "cBLUE"%s "cWH"доступ к складу",
				   	gFractionRankName[pData[playerid][pFraction]-1][pData[playerid][pRank]-1],
					pData[playerid][pNickname], playerid, MafiaInfo[fracid][mStatus] == 1 ? ("закрыл") : ("открыл"));
					MafiaFracMessage(pData[playerid][pFraction], CBLUE, frac_mes);

					UpdateMafiaText();
					SaveMafiaWarehouse();
					return 1;
				}
				case 1:
				{
					ShowDialogEditRanksPermission(playerid, fracid);
				}
				case 2:
				{
					ShowDialogEditRankName(playerid, fracid);
				}
				case 3:
				{
					ShowDialogNotify(playerid);
				}
			}
		}
		case DIALOG_MSTORE_SELECT:
		{

			if(!response)
				return 1;

			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[0]) && pData[playerid][pFraction] != 13)
				return SendErr(playerid, "У вас нет доступа к складу ОПГ");	

			else if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[1]) && pData[playerid][pFraction] != 14)
				return SendErr(playerid, "У вас нет доступа к складу ОПГ");	

			else if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[2]) && pData[playerid][pFraction] != 15)
				return SendErr(playerid, "У вас нет доступа к складу ОПГ");	

			new
				mafID;

			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[0])) mafID = 0;
			else if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[1])) mafID = 1;
			else if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[2])) mafID = 2;
			else return true;

			switch(listitem)
			{
				case 0: ShowDialogPatronTake(playerid, mafID);
				case 1: ShowDialogGunsTake(playerid, mafID);
				case 2: ShowDialogDrugsTake(playerid, mafID);
				case 3: ShowDialogHardDrugsTake(playerid, mafID);
				case 4: ShowDialogMoneyTake(playerid, mafID);
				case 5: ShowDialogPatronGive(playerid, mafID);
				case 6: ShowDialogGunsGive(playerid, mafID);
				case 7: ShowDialogDrugsGive(playerid, mafID);
				case 8: ShowDialogHardDrugsGive(playerid, mafID);
				case 9: ShowDialogMoneyGive(playerid, mafID);
			}	
		}
		case DIALOG_MTAKE_PATRONS:
		{
			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[0]) && pData[playerid][pFraction] != 13)
				return SendErr(playerid, "У вас нет доступа к складу ОПГ");	

			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[1]) && pData[playerid][pFraction] != 14)
				return SendErr(playerid, "У вас нет доступа к складу ОПГ");	

			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[2]) && pData[playerid][pFraction] != 15)
				return SendErr(playerid, "У вас нет доступа к складу ОПГ");	

			new
				mafID;

			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[0])) mafID = 0;
			else if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[1])) mafID = 1;
			else if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[2])) mafID = 2;
			else return true;

			if(!response)
				return ShowDialogMafiaWH(playerid, mafID);

			if(pData[playerid][pRank] < MafiaInfo[mafID][mWHDostup][0])
				return SendErr(playerid, "У вас нет доступа к взятию патрон со склада");
				
			if(MafiaInfo[mafID][mStatus] == 1)
				return SendErr(playerid, "Склад закрыт");

			if(!strlen(inputtext) || !IsNumeric(inputtext))
			{
		   		ShowDialogPatronTake(playerid, mafID);
		   		SendErr(playerid, "Неверное значение");
		   		return 1;     
		   	}
				
			if(strval(inputtext) < 1 || strval(inputtext) > 1000)
		    {
		   		ShowDialogPatronTake(playerid, mafID);
		   		SendErr(playerid, "Допустимое значение патрон от 1 до 1000");
		   		return 1;     
		   	}

		   	if(MafiaInfo[mafID][mPatrons] < strval(inputtext))
		   	{
		   		ShowDialogPatronTake(playerid, mafID);
		   		SendErr(playerid, "На складе недостаточно патрон");
		   		return 1;     
		   	}
		   	if(GetPVarIntNew(playerid,"take_patron") > gettime())
		   		return SendErr(playerid, "Брать патроны можно раз в минуту");

		   	SetPVarIntNew(playerid, "take_patron", gettime()+60);

		   	pData[playerid][pAmmo] += strval(inputtext);
			UpdatePlayerData(playerid, "ammo", pData[playerid][pAmmo]);

			MafiaInfo[mafID][mPatrons] -= strval(inputtext);
			UpdateMafiaText();
			SaveMafiaWarehouse();
			new 
				frac_mes[144];

			format(frac_mes, sizeof (frac_mes), "[Склад ОПГ] "cWH"%s %s[%i] взял со склада "cBLUE"%i "cWH"патрон"
				,gFractionRankName[pData[playerid][pFraction]-1][pData[playerid][pRank]-1], pData[playerid][pNickname], playerid, strval(inputtext));
			MafiaFracMessage(pData[playerid][pFraction], CBLUE, frac_mes);
		}
		case DIALOG_MTAKE_GUNS:
		{
			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[0]) && pData[playerid][pFraction] != 13)
				return SendErr(playerid, "У вас нет доступа к складу ОПГ");	

			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[1]) && pData[playerid][pFraction] != 14)
				return SendErr(playerid, "У вас нет доступа к складу ОПГ");	

			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[2]) && pData[playerid][pFraction] != 15)
				return SendErr(playerid, "У вас нет доступа к складу ОПГ");	

			new
				mafID;

			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[0])) mafID = 0;
			else if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[1])) mafID = 1;
			else if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[2])) mafID = 2;
			else return true;

			if(pData[playerid][pRank] < MafiaInfo[mafID][mWHDostup][1])
				return SendErr(playerid, "У вас нет доступа к взятию ед. оружия со склада");

			if(!response)
				return ShowDialogMafiaWH(playerid, mafID);
				
			if(MafiaInfo[mafID][mStatus] == 1)
				return SendErr(playerid, "Склад закрыт");

			if(!strlen(inputtext) || !IsNumeric(inputtext))
			{
		   		ShowDialogGunsTake(playerid, mafID);
		   		SendErr(playerid, "Неверное значение");
		   		return 1;     
		   	}
				
			if(strval(inputtext) < 1 || strval(inputtext) > 1000)
		    {
		   		ShowDialogGunsTake(playerid, mafID);
		   		SendErr(playerid, "Допустимое значение ед. оружия от 1 до 1000");
		   		return 1;     
		   	}

		   	if(MafiaInfo[mafID][mGuns] < strval(inputtext))
		   	{
		   		ShowDialogGunsTake(playerid, mafID);
		   		SendErr(playerid, "На складе недостаточно ед. оружия");
		   		return 1;     
		   	}
		   	if(GetPVarIntNew(playerid,"take_guns") > gettime())
		   		return SendErr(playerid, "Брать ед. оружия можно раз в минуту");

		   	SetPVarIntNew(playerid, "take_guns", gettime()+60);

		   	pData[playerid][pGunAmount] += strval(inputtext);
			UpdatePlayerData(playerid, "gunamount", pData[playerid][pGunAmount]);

			MafiaInfo[mafID][mGuns] -= strval(inputtext);
			UpdateMafiaText();
			SaveMafiaWarehouse();

			new 
				frac_mes[144];

			format(frac_mes, sizeof (frac_mes), "[Склад ОПГ] "cWH"%s %s[%i] взял со склада "cBLUE"%i "cWH"ед. оружия"
				,gFractionRankName[pData[playerid][pFraction]-1][pData[playerid][pRank]-1], pData[playerid][pNickname], playerid, strval(inputtext));
			MafiaFracMessage(pData[playerid][pFraction], CBLUE, frac_mes);
		}
		case DIALOG_MTAKE_DRUGS:
		{
			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[0]) && pData[playerid][pFraction] != 13)
				return SendErr(playerid, "У вас нет доступа к складу ОПГ");	

			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[1]) && pData[playerid][pFraction] != 14)
				return SendErr(playerid, "У вас нет доступа к складу ОПГ");	

			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[2]) && pData[playerid][pFraction] != 15)
				return SendErr(playerid, "У вас нет доступа к складу ОПГ");	

			new
				mafID;

			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[0])) mafID = 0;
			else if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[1])) mafID = 1;
			else if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[2])) mafID = 2;
			else return true;

			if(!response)
				return ShowDialogMafiaWH(playerid, mafID);

			if(pData[playerid][pRank] < MafiaInfo[mafID][mWHDostup][2])
				return SendErr(playerid, "У вас нет доступа к взятию наркотиков со склада");
				
			if(MafiaInfo[mafID][mStatus] == 1)
				return SendErr(playerid, "Склад закрыт");

			if(!strlen(inputtext) || !IsNumeric(inputtext))
			{
		   		ShowDialogDrugsTake(playerid, mafID);
		   		SendErr(playerid, "Неверное значение");
		   		return 1;     
		   	}
				
			if(strval(inputtext) < 1 || strval(inputtext) > 1000)
		    {
		   		ShowDialogDrugsTake(playerid, mafID);
		   		SendErr(playerid, "Допустимое значение наркотиков от 1 до 1000");
		   		return 1;     
		   	}

		   	if(MafiaInfo[mafID][mDrugs] < strval(inputtext))
		   	{
		   		ShowDialogDrugsTake(playerid, mafID);
		   		SendErr(playerid, "На складе недостаточно наркотиков");
		   		return 1;     
		   	}
		   	if(GetPVarIntNew(playerid,"take_drugs") > gettime())
		   		return SendErr(playerid, "Брать наркотики можно раз в минуту");

		   	SetPVarIntNew(playerid, "take_drugs", gettime()+60);

		   	pData[playerid][pDrugs] += strval(inputtext);
			UpdatePlayerData(playerid, "drugs", pData[playerid][pDrugs]);

			MafiaInfo[mafID][mDrugs] -= strval(inputtext);
			UpdateMafiaText();
			SaveMafiaWarehouse();

			new 
				frac_mes[144];

			format(frac_mes, sizeof (frac_mes), "[Склад ОПГ] "cWH"%s %s[%i] взял со склада "cBLUE"%i "cWH"гр. наркотиков"
				,gFractionRankName[pData[playerid][pFraction]-1][pData[playerid][pRank]-1], pData[playerid][pNickname], playerid, strval(inputtext));
			MafiaFracMessage(pData[playerid][pFraction], CBLUE, frac_mes);
		}
		case DIALOG_MTAKE_HDDRUGS:
		{
			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[0]) && pData[playerid][pFraction] != 13)
				return SendErr(playerid, "У вас нет доступа к складу ОПГ");	

			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[1]) && pData[playerid][pFraction] != 14)
				return SendErr(playerid, "У вас нет доступа к складу ОПГ");	

			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[2]) && pData[playerid][pFraction] != 15)
				return SendErr(playerid, "У вас нет доступа к складу ОПГ");	

			new
				mafID;

			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[0])) mafID = 0;
			else if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[1])) mafID = 1;
			else if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[2])) mafID = 2;
			else return true;

			if(!response)
				return ShowDialogMafiaWH(playerid, mafID);

			if(pData[playerid][pRank] < MafiaInfo[mafID][mWHDostup][3])
				return SendErr(playerid, "У вас нет доступа к взятию тяжёлых наркотиков со склада");
				
			if(MafiaInfo[mafID][mStatus] == 1)
				return SendErr(playerid, "Склад закрыт");

			if(!strlen(inputtext) || !IsNumeric(inputtext))
			{
		   		ShowDialogHardDrugsTake(playerid, mafID);
		   		SendErr(playerid, "Неверное значение");
		   		return 1;     
		   	}
				
			if(strval(inputtext) < 1 || strval(inputtext) > 1000)
		    {
		   		ShowDialogHardDrugsTake(playerid, mafID);
		   		SendErr(playerid, "Допустимое значение тяжёлых наркотиков от 1 до 1000");
		   		return 1;     
		   	}

		   	if(MafiaInfo[mafID][mHdrugs] < strval(inputtext))
		   	{
		   		ShowDialogHardDrugsTake(playerid, mafID);
		   		SendErr(playerid, "На складе недостаточно тяжёлых наркотиков");
		   		return 1;     
		   	}

		   	if(GetPVarIntNew(playerid,"take_hdrugs") > gettime())
		   		return SendErr(playerid, "Брать тяжёлые наркотики можно раз в минуту");

		   	SetPVarIntNew(playerid, "take_hdrugs", gettime()+60);

		   	pData[playerid][pHDrugs] += strval(inputtext);
			UpdatePlayerData(playerid, "hdrugs", pData[playerid][pHDrugs]);

			MafiaInfo[mafID][mHdrugs] -= strval(inputtext);
			UpdateMafiaText();
			SaveMafiaWarehouse();

			new 
				frac_mes[144];

			format(frac_mes, sizeof (frac_mes), "[Склад ОПГ] "cWH"%s %s[%i] взял со склада "cBLUE"%i "cWH"гр. тяжёлых наркотиков"
				,gFractionRankName[pData[playerid][pFraction]-1][pData[playerid][pRank]-1], pData[playerid][pNickname], playerid, strval(inputtext));
			MafiaFracMessage(pData[playerid][pFraction], CBLUE, frac_mes);
		}
		case DIALOG_MTAKE_MONEY:
		{
			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[0]) && pData[playerid][pFraction] != 13)
				return SendErr(playerid, "У вас нет доступа к складу ОПГ");	

			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[1]) && pData[playerid][pFraction] != 14)
				return SendErr(playerid, "У вас нет доступа к складу ОПГ");	

			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[2]) && pData[playerid][pFraction] != 15)
				return SendErr(playerid, "У вас нет доступа к складу ОПГ");	

			new
				mafID;

			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[0])) mafID = 0;
			else if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[1])) mafID = 1;
			else if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[2])) mafID = 2;
			else return true;

			if(!response)
				return ShowDialogMafiaWH(playerid, mafID);
				
			if(MafiaInfo[mafID][mStatus] == 1)
				return SendErr(playerid, "Склад закрыт");

			if(pData[playerid][pRank] < 10)
				return SendErr(playerid, "Доступно только лидеру");

			if(!strlen(inputtext) || !IsNumeric(inputtext))
			{
		   		ShowDialogMoneyTake(playerid, mafID);
		   		SendErr(playerid, "Неверное значение");
		   		return 1;     
		   	}
				
			if(strval(inputtext) < 1 || strval(inputtext) > 250000)
		    {
		   		ShowDialogMoneyTake(playerid, mafID);
		   		SendErr(playerid, "Допустимое значение денег от 1 до 250000");
		   		return 1;     
		   	}

		   	if(MafiaInfo[mafID][mMoney] < strval(inputtext))
		   	{
		   		ShowDialogMoneyTake(playerid, mafID);
		   		SendErr(playerid, "На складе недостаточно денег");
		   		return 1;     
		   	}

		   	if(GetPVarIntNew(playerid,"take_money") > gettime())
		   		return SendErr(playerid, "Брать деньги можно раз в минуту");

		   	SetPVarIntNew(playerid, "take_money", gettime()+60);

		   	give_money(playerid, strval(inputtext), "Снятие со склада ОПГ");

			MafiaInfo[mafID][mMoney] -= strval(inputtext);
			UpdateMafiaText();
			SaveMafiaWarehouse();

			new 
				frac_mes[144];

			format(frac_mes, sizeof (frac_mes), "[Склад ОПГ] "cWH"%s %s[%i] взял со склада "cBLUE"%i "cWH"рублей"
				,gFractionRankName[pData[playerid][pFraction]-1][pData[playerid][pRank]-1], pData[playerid][pNickname], playerid, strval(inputtext));
			MafiaFracMessage(pData[playerid][pFraction], CBLUE, frac_mes);
		}
		case DIALOG_MGIVE_PATRONS:
		{
			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[0]) && pData[playerid][pFraction] != 13)
				return SendErr(playerid, "У вас нет доступа к складу ОПГ");	

			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[1]) && pData[playerid][pFraction] != 14)
				return SendErr(playerid, "У вас нет доступа к складу ОПГ");	

			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[2]) && pData[playerid][pFraction] != 15)
				return SendErr(playerid, "У вас нет доступа к складу ОПГ");	

			new
				mafID;

			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[0])) mafID = 0;
			else if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[1])) mafID = 1;
			else if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[2])) mafID = 2;
			else return true;

			if(!response)
				return ShowDialogMafiaWH(playerid, mafID);

			if(!strlen(inputtext) || !IsNumeric(inputtext))
			{
		   		ShowDialogPatronGive(playerid, mafID);
		   		SendErr(playerid, "Неверное значение");
		   		return 1;     
		   	}	

		   	if(pData[playerid][pAmmo] < strval(inputtext))
		   	{
		   		ShowDialogPatronGive(playerid, mafID);
		   		SendErr(playerid, "У Вас недостаточно патрон");
		   		return 1;     
		   	}

		   	pData[playerid][pAmmo] -= strval(inputtext);
			UpdatePlayerData(playerid, "ammo", pData[playerid][pAmmo]);

			MafiaInfo[mafID][mPatrons] += strval(inputtext);
			UpdateMafiaText();
			SaveMafiaWarehouse();

			new 
				frac_mes[144];

			format(frac_mes, sizeof (frac_mes), "[Склад ОПГ] "cWH"%s %s[%i] положил на склад "cBLUE"%i "cWH"патрон"
				,gFractionRankName[pData[playerid][pFraction]-1][pData[playerid][pRank]-1], pData[playerid][pNickname], playerid, strval(inputtext));
			MafiaFracMessage(pData[playerid][pFraction], CBLUE, frac_mes);
		}
		case DIALOG_MGIVE_GUNS:
		{
			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[0]) && pData[playerid][pFraction] != 13)
				return SendErr(playerid, "У вас нет доступа к складу ОПГ");	

			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[1]) && pData[playerid][pFraction] != 14)
				return SendErr(playerid, "У вас нет доступа к складу ОПГ");	

			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[2]) && pData[playerid][pFraction] != 15)
				return SendErr(playerid, "У вас нет доступа к складу ОПГ");	

			new
				mafID;

			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[0])) mafID = 0;
			else if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[1])) mafID = 1;
			else if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[2])) mafID = 2;
			else return true;

			if(!response)
				return ShowDialogMafiaWH(playerid, mafID);

			if(!strlen(inputtext) || !IsNumeric(inputtext))
			{
		   		ShowDialogGunsGive(playerid, mafID);
		   		SendErr(playerid, "Неверное значение");
		   		return 1;     
		   	}	

		   	if(pData[playerid][pGunAmount] < strval(inputtext))
		   	{
		   		ShowDialogGunsGive(playerid, mafID);
		   		SendErr(playerid, "У Вас недостаточно ед. оружия");
		   		return 1;     
		   	}

		   	pData[playerid][pGunAmount] -= strval(inputtext);
			UpdatePlayerData(playerid, "gunamount", pData[playerid][pGunAmount]);

			MafiaInfo[mafID][mGuns] += strval(inputtext);
			UpdateMafiaText();
			SaveMafiaWarehouse();

			new 
				frac_mes[144];

			format(frac_mes, sizeof (frac_mes), "[Склад ОПГ] "cWH"%s %s[%i] положил на склад "cBLUE"%i "cWH"ед. оружия"
				,gFractionRankName[pData[playerid][pFraction]-1][pData[playerid][pRank]-1], pData[playerid][pNickname], playerid, strval(inputtext));
			MafiaFracMessage(pData[playerid][pFraction], CBLUE, frac_mes);
		}
		case DIALOG_MGIVE_DRUGS:
		{
			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[0]) && pData[playerid][pFraction] != 13)
				return SendErr(playerid, "У вас нет доступа к складу ОПГ");	

			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[1]) && pData[playerid][pFraction] != 14)
				return SendErr(playerid, "У вас нет доступа к складу ОПГ");	

			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[2]) && pData[playerid][pFraction] != 15)
				return SendErr(playerid, "У вас нет доступа к складу ОПГ");	

			new
				mafID;

			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[0])) mafID = 0;
			else if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[1])) mafID = 1;
			else if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[2])) mafID = 2;
			else return true;

			if(!response)
				return ShowDialogMafiaWH(playerid, mafID);

			if(!strlen(inputtext) || !IsNumeric(inputtext))
			{
		   		ShowDialogDrugsGive(playerid, mafID);
		   		SendErr(playerid, "Неверное значение");
		   		return 1;     
		   	}	

		   	if(pData[playerid][pDrugs] < strval(inputtext))
		   	{
		   		ShowDialogDrugsGive(playerid, mafID);
		   		SendErr(playerid, "У Вас недостаточно грамм наркотиков");
		   		return 1;     
		   	}

		   	pData[playerid][pDrugs] -= strval(inputtext);
			UpdatePlayerData(playerid, "drugs", pData[playerid][pDrugs]);

			MafiaInfo[mafID][mDrugs] += strval(inputtext);
			UpdateMafiaText();
			SaveMafiaWarehouse();

			new 
				frac_mes[144];

			format(frac_mes, sizeof (frac_mes), "[Склад ОПГ] "cWH"%s %s[%i] положил на склад "cBLUE"%i "cWH"гр. наркотиков"
				,gFractionRankName[pData[playerid][pFraction]-1][pData[playerid][pRank]-1], pData[playerid][pNickname], playerid, strval(inputtext));
			MafiaFracMessage(pData[playerid][pFraction], CBLUE, frac_mes);
		}
		case DIALOG_MGIVE_HDDRUGS:
		{
			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[0]) && pData[playerid][pFraction] != 13)
				return SendErr(playerid, "У вас нет доступа к складу ОПГ");	

			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[1]) && pData[playerid][pFraction] != 14)
				return SendErr(playerid, "У вас нет доступа к складу ОПГ");	

			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[2]) && pData[playerid][pFraction] != 15)
				return SendErr(playerid, "У вас нет доступа к складу ОПГ");	

			new
				mafID;

			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[0])) mafID = 0;
			else if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[1])) mafID = 1;
			else if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[2])) mafID = 2;
			else return true;

			if(!response)
				return ShowDialogMafiaWH(playerid, mafID);

			if(!strlen(inputtext) || !IsNumeric(inputtext))
			{
		   		ShowDialogHardDrugsGive(playerid, mafID);
		   		SendErr(playerid, "Неверное значение");
		   		return 1;     
		   	}	

		   	if(pData[playerid][pHDrugs] < strval(inputtext))
		   	{
		   		ShowDialogHardDrugsGive(playerid, mafID);
		   		SendErr(playerid, "У Вас недостаточно грамм тяжёлых наркотиков");
		   		return 1;     
		   	}

		   	pData[playerid][pHDrugs] -= strval(inputtext);
			UpdatePlayerData(playerid, "hdrugs", pData[playerid][pHDrugs]);

			MafiaInfo[mafID][mHdrugs] += strval(inputtext);
			UpdateMafiaText();
			SaveMafiaWarehouse();

			new 
				frac_mes[144];

			format(frac_mes, sizeof (frac_mes), "[Склад ОПГ] "cWH"%s %s[%i] положил на склад "cBLUE"%i "cWH"гр. тяжёлых наркотиков"
				,gFractionRankName[pData[playerid][pFraction]-1][pData[playerid][pRank]-1], pData[playerid][pNickname], playerid, strval(inputtext));
			MafiaFracMessage(pData[playerid][pFraction], CBLUE, frac_mes);
		}
		case DIALOG_MGIVE_MONEY:
		{
			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[0]) && pData[playerid][pFraction] != 13)
				return SendErr(playerid, "У вас нет доступа к складу ОПГ");	

			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[1]) && pData[playerid][pFraction] != 14)
				return SendErr(playerid, "У вас нет доступа к складу ОПГ");	

			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[2]) && pData[playerid][pFraction] != 15)
				return SendErr(playerid, "У вас нет доступа к складу ОПГ");	

			new
				mafID;

			if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[0])) mafID = 0;
			else if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[1])) mafID = 1;
			else if(IsPlayerInDynamicArea(playerid, MafiaStoreArea[2])) mafID = 2;
			else return true;

			if(!response)
				return ShowDialogMafiaWH(playerid, mafID);

			if(!strlen(inputtext) || !IsNumeric(inputtext))
			{
		   		ShowDialogMoneyGive(playerid, mafID);
		   		SendErr(playerid, "Неверное значение");
		   		return 1;     
		   	}	

		   	if(GetPlayerMoneyEx(playerid) < strval(inputtext))
		   	{
		   		ShowDialogMoneyGive(playerid, mafID);
		   		SendErr(playerid, "У Вас недостаточно денег");
		   		return 1;     
		   	}

		   	give_money(playerid, -strval(inputtext), "Положил на склад ОПГ");

			MafiaInfo[mafID][mMoney] += strval(inputtext);
			UpdateMafiaText();
			SaveMafiaWarehouse();

			new 
				frac_mes[144];

			format(frac_mes, sizeof (frac_mes), "[Склад ОПГ] "cWH"%s %s[%i] положил на склад "cBLUE"%i "cWH"рублей"
				,gFractionRankName[pData[playerid][pFraction]-1][pData[playerid][pRank]-1], pData[playerid][pNickname], playerid, strval(inputtext));
			MafiaFracMessage(pData[playerid][pFraction], CBLUE, frac_mes);
		}
		case DIALOG_LMENU_EDITRANK:
		{
			if(!response)
				return 1;

			SetPVarIntNew(playerid, "EditPermissionRang", listitem);

			ShowDialogEditRanksDostup(playerid);
		}
		case DIALOG_LMENU_RANKLIST:
		{
			if(!response)
				return 1;

			SetPVarIntNew(playerid, "EditRangName", listitem);

			ShowDialogEditRang(playerid);
		}
		case DIALOG_CHANGE_PERMISSION:
		{
			if(!response)
			{
				DeletePVarNew(playerid, "EditPermissionRang");
				return 1;
			}
			if(!IsAMafia(playerid))
						return SendErr(playerid, "Данная команда доступна только ОПГ");

			if(pData[playerid][pRank] < 10)
				return SendErr(playerid, "Команда доступна только лидеру");

			if(!strlen(inputtext) || !IsNumeric(inputtext))
			{
		   		ShowDialogEditRanksDostup(playerid);
		   		SendErr(playerid, "Неверное значение");
		   		return 1;     
		   	}	

		   	if(strval(inputtext) < 1 || strval(inputtext) > 10)
		   	{
		   		ShowDialogEditRanksDostup(playerid);
		   		SendErr(playerid, "Допустимое значение ранга от 1 до 10");
		   		return 1;     
		   	}

		   	new	
		   		type = GetPVarIntNew(playerid, "EditPermissionRang"),
		   		mafID;

		   	DeletePVarNew(playerid, "EditPermissionRang");	
		   	switch(pData[playerid][pFraction])
		   	{
		   		case 13: mafID = 0;
		   		case 14: mafID = 1;
		   		case 15: mafID = 2;
		   		default: return SendErr(playerid, "Ошибка доступа");
		   	}

		   	new 
		   		typename[18],
		   		frac_mes[144];

		   	switch(type)
		   	{
		   		case 0: typename = "патроны";
		   		case 1: typename = "ед. оружия";
		   		case 2: typename = "наркотики";
		   		case 3: typename = "тяжёлые наркотики";
		   	}

		   	format(frac_mes, sizeof (frac_mes), "[ОПГ] "cWH"%s %s[%i] установил возможность брать "cBLUE"%s "cWH"с "cBLUE"%i "cWH"ранга",
		   	gFractionRankName[pData[playerid][pFraction]-1][pData[playerid][pRank]-1],
			pData[playerid][pNickname], playerid, typename, strval(inputtext));
			MafiaFracMessage(pData[playerid][pFraction], CBLUE, frac_mes);


		   	MafiaInfo[mafID][mWHDostup][type] = strval(inputtext);
		   	SaveMafiaSettings();
		   	SendSucc(playerid, "Вы изменили доступ");
		}
		case DIALOG_CHANGE_RANGNAME:
		{
			if(!response)
			{
				DeletePVarNew(playerid, "EditRangName");
				return 1;
			}
			if(!IsAMafia(playerid))
						return SendErr(playerid, "Данная команда доступна только ОПГ");

			if(pData[playerid][pRank] < 10)
				return SendErr(playerid, "Команда доступна только лидеру");

			if(!strlen(inputtext))
			{
		   		ShowDialogEditRang(playerid);
		   		SendErr(playerid, "Неверное значение");
		   		return 1;     
		   	}	

		   	if(strlen(inputtext) < 5 || strlen(inputtext) > 32)
		   	{
		   		ShowDialogEditRang(playerid);
		   		SendErr(playerid, "Допустимая длина ранга от 5 до 32 символов");
		   		return 1;     
		   	}

		   	new	
		   		rang = GetPVarIntNew(playerid, "EditRangName"),
		   		mafID;

		   	DeletePVarNew(playerid, "EditRangName");	
		   	switch(pData[playerid][pFraction])
		   	{
		   		case 13: mafID = 0;
		   		case 14: mafID = 1;
		   		case 15: mafID = 2;
		   		default: return SendErr(playerid, "Ошибка доступа");
		   	}

		   	new 
		   		frac_mes[144];

		   	format(frac_mes, sizeof (frac_mes), "[ОПГ] "cWH"%s[%i] изменил название "cBLUE"%i "cWH"ранга на "cBLUE"%s"
			,pData[playerid][pNickname], playerid, rang+1, inputtext);
			MafiaFracMessage(pData[playerid][pFraction], CBLUE, frac_mes);

		   	SetString(gFractionRankName[mafID+12][rang], inputtext);
		   	SaveMafiaSettings();

		   	SendSucc(playerid, "Вы изменили название ранга");
		}
		case DIALOG_NOTIFY_SELECT:
		{
			if(!response)
				return 1;

			if(!IsAMafia(playerid))
					return SendErr(playerid, "Вам недоступна данная функция");
			new 
				mafID;

			switch(pData[playerid][pFraction])
			{
				case 13: mafID = 0;
				case 14: mafID = 1;
				case 15: mafID = 2;
			}
			switch(listitem)
			{
				case 0:
				{
					ShowDialogCreateNotify(playerid);
				}
				case 1:
				{
					if(!strlen(MafiaInfo[mafID][mNotify]))
					    return SendErr(playerid, "Стартовое сообщение остутствует");


				    SetString(MafiaInfo[mafID][mNotify], "");
				    SaveMafiaSettings();

				    SendSucc(playerid, "Стартовое сообщение удалено");
				}
			}
		}
		case DIALOG_CREATE_MAFIA_NOTIFY:
		{
			if(!response)
				return 1;

			if(!IsAMafia(playerid))
						return SendErr(playerid, "Данная команда доступна только ОПГ");

			if(pData[playerid][pRank] < 10)
				return SendErr(playerid, "Команда доступна только лидеру");

			if(!strlen(inputtext))
			{
		   		ShowDialogCreateNotify(playerid);
		   		SendErr(playerid, "Неверное значение");
		   		return 1;     
		   	}	

		   	if(strlen(inputtext) < 10 || strlen(inputtext) > 126)
		   	{
		   		ShowDialogCreateNotify(playerid);
		   		SendErr(playerid, "Допустимая длина уведомления от 10 до 126 символов");
		   		return 1;     
		   	}

		   	new 
		   		mafID = pData[playerid][pFraction]-13;

		   	SetString(MafiaInfo[mafID][mNotify], inputtext);
		   	SaveMafiaSettings();

		   	SendSucc(playerid, "Вы создали уведомление для ОПГ");
		   	SendInf(playerid, "Оно будет показываться членам ОПГ при каждом заходе на сервер");

		   	new 
		   		frac_mes[144];

		   	format(frac_mes, sizeof (frac_mes), "[Уведомление ОПГ] "cWH"%s", inputtext);
			MafiaFracMessage(pData[playerid][pFraction], CBLUE, frac_mes);
		}
		case DIALOG_ACCEPT_DIPLOMACY:
		{
			new 
				offerid = GetPVarIntNew(playerid, "RecieveDiplomacy")-1,
				type = GetPVarIntNew(playerid, "TypeDiplomacy");

			if(!GetPVarIntNew(offerid, "OfferDiplomacy"))
				return SendErr(playerid, "Данное предложение неактивно");

			DeletePVarNew(offerid, "OfferDiplomacy");
			DeletePVarNew(playerid, "RecieveDiplomacy");
			DeletePVarNew(playerid, "TypeDiplomacy");

			if(!response)
			{
				SendInf(playerid, "Вы отказались от заключения дипломатии");
				SendInf(offerid, "Игрок отказался от заключения дипломатии");
				return true;
			}

			AcceptDiplomacy(offerid, playerid, type);
		}
	}
	return true;
}

stock ShowDialogMafiaWH(playerid, mafID)
{
	new
		wh_mes[600];

	strcat(wh_mes, ""cWH"Действие\t"cWH"Доступ\n");

	format(wh_mes, sizeof(wh_mes), 
	"%s\
	"cBLUE"- "cWH"Взять патроны\t"cBLUE"[%i ранг]\n\
	"cBLUE"- "cWH"Взять ед. оружия\t"cBLUE"[%i ранг]\n\
	"cBLUE"- "cWH"Взять легкие наркотики\t"cBLUE"[%i ранг]\n\
	"cBLUE"- "cWH"Взять тяжёлые наркотики\t"cBLUE"[%i ранг]\n\
	"cBLUE"- "cWH"Взять деньги\t"cBLUE"[10 ранг]\n\
	"cBLUE"- "cWH"Положить патроны\t"cBLUE"[1 ранг]\n\
	"cBLUE"- "cWH"Положить ед. оружия\t"cBLUE"[1 ранг]\n\
	"cBLUE"- "cWH"Положить легкие наркотики\t"cBLUE"[1 ранг]\n\
	"cBLUE"- "cWH"Положить тяжёлые наркотики\t"cBLUE"[1 ранг]\n\
	"cBLUE"- "cWH"Положить деньги\t"cBLUE"[1 ранг]",wh_mes, 
		MafiaInfo[mafID][mWHDostup][0], MafiaInfo[mafID][mWHDostup][1],
		MafiaInfo[mafID][mWHDostup][2], MafiaInfo[mafID][mWHDostup][3]);

	SPD(playerid, DIALOG_MSTORE_SELECT, DIALOG_STYLE_TABLIST_HEADERS, 
	!""cBLUE"Склад ОПГ", wh_mes, !"Выбрать", !"Отмена");
	return 1;
}

stock ShowDialogPatronTake(playerid, mafID)
{
	if(MafiaInfo[mafID][mStatus] == 1)
		return SendErr(playerid, "Склад закрыт");

	format(String256, sizeof (String256), "\n"cWH"Введите количество патрон, которое хотите взять со склада.\n\
		"cBLUE"Примечание: "cWH"сейчас на складе ОПГ "cBLUE"%i "cWH"ед. патрон", MafiaInfo[mafID][mPatrons]);

    SPD(playerid, DIALOG_MTAKE_PATRONS, DIALOG_STYLE_INPUT, !""cBLUE"Склад ОПГ", String256, !"Взять", !"Отмена");
    return 1;
}

stock ShowDialogGunsTake(playerid, mafID)
{
	if(MafiaInfo[mafID][mStatus] == 1)
		return SendErr(playerid, "Склад закрыт");

	format(String256, sizeof (String256), "\n"cWH"Введите количество ед. оружия, которое хотите взять со склада.\n\
		"cBLUE"Примечание: "cWH"сейчас на складе ОПГ "cBLUE"%i "cWH"ед. оружия", MafiaInfo[mafID][mGuns]);

    SPD(playerid, DIALOG_MTAKE_GUNS, DIALOG_STYLE_INPUT, !""cBLUE"Склад ОПГ", String256, !"Взять", !"Отмена");
	return 1;
}

stock ShowDialogDrugsTake(playerid, mafID)
{
	if(MafiaInfo[mafID][mStatus] == 1)
		return SendErr(playerid, "Склад закрыт");

	format(String256, sizeof (String256), "\n"cWH"Введите количество наркотиков, которое хотите взять со склада.\n\
		"cBLUE"Примечание: "cWH"сейчас на складе ОПГ "cBLUE"%i "cWH"гр. наркотиков", MafiaInfo[mafID][mDrugs]);

    SPD(playerid, DIALOG_MTAKE_DRUGS, DIALOG_STYLE_INPUT, !""cBLUE"Склад ОПГ", String256, !"Взять", !"Отмена");
	return 1;
}

stock ShowDialogHardDrugsTake(playerid, mafID)
{
	if(MafiaInfo[mafID][mStatus] == 1)
		return SendErr(playerid, "Склад закрыт");

	format(String256, sizeof (String256), "\n"cWH"Введите количество тяжёлых наркотиков, которое хотите взять со склада.\n\
		"cBLUE"Примечание: "cWH"сейчас на складе ОПГ "cBLUE"%i "cWH"гр. тяжёлых наркотиков", MafiaInfo[mafID][mHdrugs]);

    SPD(playerid, DIALOG_MTAKE_HDDRUGS, DIALOG_STYLE_INPUT, !""cBLUE"Склад ОПГ", String256, !"Взять", !"Отмена");
	return 1;
}

stock ShowDialogMoneyTake(playerid, mafID)
{
	if(MafiaInfo[mafID][mStatus] == 1)
		return SendErr(playerid, "Склад закрыт");

	if(pData[playerid][pRank] < 10)
		return SendErr(playerid, "Доступно только лидеру");

	format(String256, sizeof (String256), "\n"cWH"Введите количество денег, которое хотите взять со склада.\n\
		"cBLUE"Примечание: "cWH"сейчас на складе ОПГ "cBLUE"%i "cWH"рублей", MafiaInfo[mafID][mMoney]);
    SPD(playerid, DIALOG_MTAKE_MONEY, DIALOG_STYLE_INPUT, !""cBLUE"Склад ОПГ", String256, !"Взять", !"Отмена");
	return 1;
}

stock ShowDialogPatronGive(playerid, mafID)
{
	format(String256, sizeof (String256), "\n"cWH"Введите количество патрон, которое хотите положить на склад.\n\
		"cBLUE"Примечание: "cWH"сейчас на складе ОПГ "cBLUE"%i "cWH"ед. патрон", MafiaInfo[mafID][mPatrons]);
    SPD(playerid, DIALOG_MGIVE_PATRONS, DIALOG_STYLE_INPUT, !""cBLUE"Склад ОПГ", String256, !"Положить", !"Отмена");
    return 1;
}

stock ShowDialogGunsGive(playerid, mafID)
{
	format(String256, sizeof (String256), "\n"cWH"Введите количество ед. оружия, которое хотите положить на склад.\n\
		"cBLUE"Примечание: "cWH"сейчас на складе ОПГ "cBLUE"%i "cWH"ед. оружия", MafiaInfo[mafID][mGuns]);
    SPD(playerid, DIALOG_MGIVE_GUNS, DIALOG_STYLE_INPUT, !""cBLUE"Склад ОПГ", String256, !"Положить", !"Отмена");
    return 1;
}

stock ShowDialogDrugsGive(playerid, mafID)
{
	format(String256, sizeof (String256), "\n"cWH"Введите количество наркотиков, которое хотите положить на склад.\n\
		"cBLUE"Примечание: "cWH"сейчас на складе ОПГ "cBLUE"%i "cWH"гр. наркотиков", MafiaInfo[mafID][mDrugs]);
    SPD(playerid, DIALOG_MGIVE_DRUGS, DIALOG_STYLE_INPUT, !""cBLUE"Склад ОПГ", String256, !"Положить", !"Отмена");
    return 1;
}

stock ShowDialogHardDrugsGive(playerid, mafID)
{
	format(String256, sizeof (String256), "\n"cWH"Введите количество тяжёлых наркотиков, которое хотите положить на склад.\n\
		"cBLUE"Примечание: "cWH"сейчас на складе ОПГ "cBLUE"%i "cWH"гр. тяжёлых наркотиков", MafiaInfo[mafID][mHdrugs]);
    SPD(playerid, DIALOG_MGIVE_HDDRUGS, DIALOG_STYLE_INPUT, !""cBLUE"Склад ОПГ", String256, !"Положить", !"Отмена");
    return 1;
}

stock ShowDialogMoneyGive(playerid, mafID)
{
	format(String256, sizeof (String256), "\n"cWH"Введите количество денег, которое хотите положить на склад.\n\
		"cBLUE"Примечание: "cWH"сейчас на складе ОПГ "cBLUE"%i "cWH"рублей", MafiaInfo[mafID][mMoney]);
    SPD(playerid, DIALOG_MGIVE_MONEY, DIALOG_STYLE_INPUT, !""cBLUE"Склад ОПГ", String256, !"Положить", !"Отмена");
    return 1;
}

stock ShowDialogEditRanksPermission(playerid, mafID)
{
	new
		wh_mes[300];
		
	strcat(wh_mes, ""cWH"Действие\t"cWH"Доступ\n");

	format(wh_mes, sizeof(wh_mes), 
	"%s\
	"cBLUE"- "cWH"Доступ к патронам\t"cBLUE"[%i ранг]\n\
	"cBLUE"- "cWH"Доступ к ед. оружия\t"cBLUE"[%i ранг]\n\
	"cBLUE"- "cWH"Доступ к наркотикам\t"cBLUE"[%i ранг]\n\
	"cBLUE"- "cWH"Доступ к тяжёлым наркотикам\t"cBLUE"[%i ранг]",wh_mes, 
		MafiaInfo[mafID][mWHDostup][0], MafiaInfo[mafID][mWHDostup][1],
		MafiaInfo[mafID][mWHDostup][2], MafiaInfo[mafID][mWHDostup][3]);

	SPD(playerid, DIALOG_LMENU_EDITRANK, DIALOG_STYLE_TABLIST_HEADERS, 
	!""cBLUE"Управление ОПГ", wh_mes, !"Изменить", !"Назад");
	return 1;
}

stock ShowDialogEditRanksDostup(playerid)
{
	if(!IsAMafia(playerid))
		return SendErr(playerid, "Данная команда доступна только ОПГ");

	if(pData[playerid][pRank] < 10)
		return SendErr(playerid, "Команда доступна только лидеру");

    SPD(playerid, DIALOG_CHANGE_PERMISSION, DIALOG_STYLE_INPUT, !""cBLUE"Управление ОПГ", 
    	!"\n"cWH"Введите новое значение ранга для доступа\n", !"Изменить", !"Отмена");

    return 1;
}

stock ShowDialogEditRankName(playerid, mafID)
{
	new
		rank_mes[400];
		

	format(rank_mes, sizeof(rank_mes), 
	""cBLUE"- "cWH"%s\n\
	"cBLUE"- "cWH"%s\n\
	"cBLUE"- "cWH"%s\n\
	"cBLUE"- "cWH"%s\n\
	"cBLUE"- "cWH"%s\n\
	"cBLUE"- "cWH"%s\n\
	"cBLUE"- "cWH"%s\n\
	"cBLUE"- "cWH"%s\n\
	"cBLUE"- "cWH"%s\n\
	"cBLUE"- "cWH"%s",gFractionRankName[mafID+12][0],gFractionRankName[mafID+12][1],gFractionRankName[mafID+12][2],
		gFractionRankName[mafID+12][3],gFractionRankName[mafID+12][4],gFractionRankName[mafID+12][5],
		gFractionRankName[mafID+12][6],gFractionRankName[mafID+12][7],gFractionRankName[mafID+12][8],
		gFractionRankName[mafID+12][9]);

	SPD(playerid, DIALOG_LMENU_RANKLIST, DIALOG_STYLE_LIST, 
	!""cBLUE"Выберите ранг для изменения", rank_mes, !"Изменить", !"Назад");
	return 1;
}

stock ShowDialogEditRang(playerid)
{
	if(!IsAMafia(playerid))
		return SendErr(playerid, "Данная команда доступна только ОПГ");

	if(pData[playerid][pRank] < 10)
		return SendErr(playerid, "Команда доступна только лидеру");

	new 
		string_mes[120],
		rang = GetPVarIntNew(playerid, "EditRangName");

	format(string_mes, sizeof(string_mes), "\n"cWH"Введите новое значение для "cBLUE"%i "cWH"ранга\n", rang+1);

    SPD(playerid, DIALOG_CHANGE_RANGNAME, DIALOG_STYLE_INPUT, !""cBLUE"Управление ОПГ", string_mes, !"Изменить", !"Отмена");

    return 1;
}

stock ShowDialogNotify(playerid)
{
	SPD(playerid, DIALOG_NOTIFY_SELECT, DIALOG_STYLE_LIST, 
	!""cBLUE"Управление уведомлением ОПГ", 
	""cBLUE"1. "cWH"Создать уведомление\n\
	"cBLUE"2. "cWH"Удалить уведомление", 
	!"Выбрать", !"Отмена");
	return 1;
}

stock ShowDialogCreateNotify(playerid)
{
	if(!IsAMafia(playerid))
		return SendErr(playerid, "Данная команда доступна только ОПГ");

	if(pData[playerid][pRank] < 10)
		return SendErr(playerid, "Команда доступна только лидеру");

    SPD(playerid, DIALOG_CREATE_MAFIA_NOTIFY, DIALOG_STYLE_INPUT, !""cBLUE"Создание уведомления", 
    	!"\n"cWH"Введите текст уведомления, который будет показан при заходе\n"cBLUE"Примечание: "cWH"длина уведомления должна быть от 10 до 126 символов\n", !"Создать", !"Отмена");
	return 1;
}

stock SendMafiaNotify(playerid)// При загрузке игрока
{
	if(!IsAMafia(playerid))
		return 1;

	new 
		mafID = pData[playerid][pFraction]-13;

	if(!strlen(MafiaInfo[mafID][mNotify]))
		return 1;
	new 
		notify_mes[144];

	format(notify_mes, sizeof(notify_mes), "[Уведомление ОПГ] "cWH"%s", MafiaInfo[mafID][mNotify]);
	SendClientMessage(playerid, CBLUE, notify_mes);
	return 1;
}

stock AcceptDiplomacy(offerid, playerid, type)
{
	new 
		mafID_one = pData[offerid][pFraction]-13,
		mafID_two = pData[playerid][pFraction]-13;

	MafiaInfo[mafID_one][mDiplomacy][mafID_two] = type;
	MafiaInfo[mafID_two][mDiplomacy][mafID_one] = type;
	SaveMafiaSettings();

	new 
		succ_mes[144];

	format(succ_mes, sizeof(succ_mes), "Вы заключили дипломатию с %s", pData[offerid][pNickname]);
	SendSucc(playerid, succ_mes);

	format(succ_mes, sizeof(succ_mes), "%s принял предложение о дипломатии с вашей ОПГ", pData[playerid][pNickname]);
	SendSucc(offerid, succ_mes);

	new 
		frac_mes[144];


	format(frac_mes, sizeof (frac_mes), "[ОПГ] "cWH"Ваша ОПГ заключила %s "cWH"с "cBLUE"%s",
	 type == 1 ? ("нейтралитет") : ("мир"), gFractionName[pData[offerid][pFraction]-1]);
	MafiaFracMessage(pData[playerid][pFraction], CBLUE, frac_mes);

	format(frac_mes, sizeof (frac_mes), "[ОПГ] "cWH"Ваша ОПГ заключила %s "cWH"с "cBLUE"%s",
	 type == 1 ? ("нейтралитет") : ("мир"), gFractionName[pData[playerid][pFraction]-1]);
	MafiaFracMessage(pData[offerid][pFraction], CBLUE, frac_mes);
	return true;
}

callback:: LoadMafiaWarehouse() // ongamemodeinit
{
	new Result:mafia = sql_queryEx(zConn, "SELECT * FROM `mafia` ORDER BY `id`", QUERY_CACHED);

 	if(sql_num_rows(mafia) != 3)
 		print("Кол-во мафий в базе не совпадает с предопределным количеством");
 	else
	{
	    new zRes[512];
  		for(new i; i < sql_num_rows(mafia); i++)
		{
			sql_fetch_row(mafia,"|",zRes);
			sql_next_row(mafia);
			sscanf(zRes,"p<|>iiiiiii", MafiaInfo[i][mID], MafiaInfo[i][mPatrons], MafiaInfo[i][mGuns], 
			MafiaInfo[i][mDrugs], MafiaInfo[i][mHdrugs], MafiaInfo[i][mMoney], MafiaInfo[i][mStatus]);
		}
	}
 	sql_free_result(mafia);
	print("Мафии загружены");

	UpdateMafiaText();
	return true;
}


callback:: LoadMafiaSettings() // ongamemodeinit
{
	new Result:mafia = sql_queryEx(zConn, "SELECT * FROM `mafia_settings` ORDER BY `id`", QUERY_CACHED);

 	if(sql_num_rows(mafia) != 3)
 		print("Кол-во мафий в базе не совпадает с предопределным количеством");
 	else
	{
	    new zRes[512];
  		for(new i; i < sql_num_rows(mafia); i++)
		{
			sql_fetch_row(mafia,"|",zRes);
			sql_next_row(mafia);
			sscanf(zRes,"p<|>is[32]s[32]s[32]s[32]s[32]s[32]s[32]s[32]s[32]s[32]iiiis[126]iii", MafiaInfo[i][mID]
			, gFractionRankName[i+12][0], gFractionRankName[i+12][1], gFractionRankName[i+12][2]
			, gFractionRankName[i+12][3], gFractionRankName[i+12][4], gFractionRankName[i+12][5]
			, gFractionRankName[i+12][6], gFractionRankName[i+12][7], gFractionRankName[i+12][8], gFractionRankName[i+12][9],
			MafiaInfo[i][mWHDostup][0], MafiaInfo[i][mWHDostup][1], MafiaInfo[i][mWHDostup][2], MafiaInfo[i][mWHDostup][3]
			, MafiaInfo[i][mNotify], MafiaInfo[i][mDiplomacy][0], MafiaInfo[i][mDiplomacy][1], MafiaInfo[i][mDiplomacy][2]);
		}
	}
 	sql_free_result(mafia);
	print("Настройки мафий загружены");
	return  true;
}

stock SaveMafiaSettings()
{
	for(new i = 13; i < 16; i++)
	{
		new
			query[720];
			
		format(query,sizeof(query),"UPDATE `mafia_settings` SET `rankname1` = '%s', `rankname2` = '%s',\
		`rankname3` = '%s', `rankname4` = '%s', `rankname5` = '%s', `rankname6` = '%s', `rankname7` = '%s', `rankname8` = '%s',\
		`rankname9` = '%s', `rankname10` = '%s', `status1` = '%d', `status2` = '%d', `status3` = '%d', `status4` = '%d', `notify` = '%s',\
		 `diplomacy1` = %i, `diplomacy2` = %i, `diplomacy3` = %i WHERE `id` = '%i'",
		gFractionRankName[i-1][0],gFractionRankName[i-1][1],gFractionRankName[i-1][2],
		gFractionRankName[i-1][3],gFractionRankName[i-1][4],gFractionRankName[i-1][5],
		gFractionRankName[i-1][6],gFractionRankName[i-1][7],gFractionRankName[i-1][8],
		gFractionRankName[i-1][9],
		MafiaInfo[i-13][mWHDostup][0], 
		MafiaInfo[i-13][mWHDostup][1], 
		MafiaInfo[i-13][mWHDostup][2], 
		MafiaInfo[i-13][mWHDostup][3],
		MafiaInfo[i-13][mNotify],
		MafiaInfo[i-13][mDiplomacy][0],
		MafiaInfo[i-13][mDiplomacy][1],
		MafiaInfo[i-13][mDiplomacy][2],
		i);
		sql_queryEx(zConn, query);
	}
	return true;
}

stock get_count_mafia_biz(mafia_id)
{
	if(mafia_id == 0)
	{
		mafia_id = 13;
	}
	else if(mafia_id == 1)
	{
		mafia_id = 14;
	}
	else if(mafia_id == 2)
	{
		mafia_id = 15;
	}

	new 
		count_mafia_biz;

	for(new i, idx = all_buisness; i < idx; i ++)
	{
		if(buisness[i][buisnes_mafia] != mafia_id) 
			continue;

		count_mafia_biz++;
	}


	return count_mafia_biz;
}

stock UpdateMafiaText()
{
	for(new m; m < 3; m++)
	{
		new
			string_mes[400];

		format(string_mes, 400, 
		""cBLUE"Кол-во бизнесов: "cWH"%d\n\
		"cBLUE"Патронов: "cWH"%i шт.\n\
		"cBLUE"Ед. оружия: "cWH"%i шт.\n\
		"cBLUE"Лёгких наркотиков: "cWH"%i гр.\n\
		"cBLUE"Тяжёлых наркотиков: "cWH"%i гр.\n\
		"cBLUE"Денег: "cWH"%i рублей\n\n\
		"cBLUE"Статус склада: "cWH"%s", get_count_mafia_biz(m), MafiaInfo[m][mPatrons], MafiaInfo[m][mGuns], 
		MafiaInfo[m][mDrugs], MafiaInfo[m][mHdrugs], MafiaInfo[m][mMoney], MafiaInfo[m][mStatus] == 1 ? ("Закрыт") : ("Открыт"));

		UpdateDynamic3DTextLabelText(MafiaStore_3DText[m], -1, string_mes);
	}
}

stock SaveMafiaWarehouse()
{
	for(new i = 13; i < 16; i++)
	{
		new
			query[720];
			
		format(query,sizeof(query),"UPDATE `mafia` SET  `patrons` = '%i', `guns` = '%i', `drugs` = '%i',\
		 `hdrugs` = '%i', `money` = '%i', `status` = '%i' WHERE `id` = '%i'",
		MafiaInfo[i-13][mPatrons],
		MafiaInfo[i-13][mGuns],
		MafiaInfo[i-13][mDrugs],
		MafiaInfo[i-13][mHdrugs],
		MafiaInfo[i-13][mMoney],
		MafiaInfo[i-13][mStatus],
		i);
		sql_queryEx(zConn, query);
	}
	return true;
}

stock AreaMafiaStore(playerid, areaid)
{
	if(areaid == MafiaStoreArea[0])
	{
		if(pData[playerid][pFraction] != 13)
			return SendErr(playerid, "У вас нет доступа к складу ОПГ");
		ShowDialogMafiaWH(playerid, 0);
	}
	else if(areaid == MafiaStoreArea[1])
	{
		if(pData[playerid][pFraction] != 14)
			return SendErr(playerid, "У вас нет доступа к складу ОПГ");
		ShowDialogMafiaWH(playerid, 1);	
	}
	else if(areaid == MafiaStoreArea[2])
	{
		if(pData[playerid][pFraction] != 15)
			return SendErr(playerid, "У вас нет доступа к складу ОПГ");
		ShowDialogMafiaWH(playerid, 2);
	}
	return 1;
}

//========================[Команды]========================
CMD:lmenu(playerid)
{
	if(!IsAMafia(playerid))
		return SendErr(playerid, "Данная команда доступна только ОПГ");

	if(pData[playerid][pRank] < 10)
		return SendErr(playerid, "Команда доступна только лидеру");

	SPD(playerid, DIALOG_LMENU_SELECT_MAFIA, DIALOG_STYLE_LIST, 
	!""cBLUE"Меню лидера ОПГ", 
	""cBLUE"1. "cWH"Окрыть/закрыть склад ОПГ\n\
	"cBLUE"2. "cWH"Изменить доступ к складу\n\
	"cBLUE"3. "cWH"Изменить название рангов\n\
	"cBLUE"4. "cWH"Управление стартовым уведомлением", 
	!"Выбрать", !"Отмена");
	return true;
}

CMD:diplomacy(playerid, params[])
{
	if(!IsAMafia(playerid))
		return SendErr(playerid, "Данная команда доступна только ОПГ");

	if(pData[playerid][pRank] < 10)
		return SendErr(playerid, "Команда доступна только лидеру");

	if(GetPVarIntNew(playerid, "OfferDiplomacy"))
		return SendErr(playerid, "У вас уже имеется активное предложение");

	if(sscanf(params, "dd", params[0], params[1]))
	{
		SendInf(playerid, "/diplomacy [ID] [тип дипломатии]");
		SendInf(playerid, "1 - Нейтралитет 2 - Мир");
		return 1;
	}

	if(params[1] != 1 && params[1] != 2)
		return SendErr(playerid, "Неверный тип дипломатии");

	if(!IsPlayerConnected(params[0]))
		return SendErr(playerid, "Неверный ID");

	if(GetPlayerDistanceToPlayer(playerid, params[0]) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(params[0]))
		return SendErr(playerid, "Вы находитесь далеко друг от друга");

	if(!IsAMafia(playerid) && pData[playerid][pRank] != 10)
		return SendErr(playerid, "Игрок должен быть лидером ОПГ");

	
	if(pData[playerid][pFraction] == pData[params[0]][pFraction])
		return SendErr(playerid, "Игрок должен быть лидером другой ОПГ");

	new 
		diplomacy_mes[144];

	format(diplomacy_mes, sizeof(diplomacy_mes), "Вы предложили %s заключить дипломатию", pData[params[0]][pNickname]);
	SendSucc(playerid, diplomacy_mes);

	new 
		offer_diplomacy[230];

	SetPVarIntNew(playerid, "OfferDiplomacy", params[0]+1);
	SetPVarIntNew(params[0], "RecieveDiplomacy", playerid+1);
	SetPVarIntNew(params[0], "TypeDiplomacy", params[1]);

	format(offer_diplomacy, sizeof (offer_diplomacy), "\n"cBLUE"%s "cWH"предлагает заключить дипломатию\n\n\
		"cWH"Первая сторона: "cBLUE"%s\n\
		"cWH"Вторая сторона: "cBLUE"%s\n\n\
		"cWH"Тип дипломатии: "cBLUE"%s\n", pData[playerid][pNickname], gFractionName[pData[playerid][pFraction]-1], gFractionName[pData[params[0]][pFraction]-1], params[1] == 1 ? ("Нейтралитет") : ("Мир"));
	SPD(params[0], DIALOG_ACCEPT_DIPLOMACY, DIALOG_STYLE_MSGBOX, !""cBLUE"Предложение заключения дипломатии", offer_diplomacy, !"Согласиться", !"Отказаться");
	return true;
}

CMD:dinfo(playerid)
{
	if(!IsAMafia(playerid))
		return SendErr(playerid, "Данная команда доступна только ОПГ");

	new 
		diplomtext_one[20],
		diplomtext_two[20],
		string[300];

	strcat(string, ""cGREY"Название ОПГ\t"cGREY"Тип дипломатии\n");

	if(pData[playerid][pFraction] == 13)
	{
		switch(MafiaInfo[0][mDiplomacy][1])
		{
			case 0: diplomtext_one = ""cLRED"Война";
			case 1:	diplomtext_one = ""cGREY"Нейтралитет";
			case 2: diplomtext_one = ""cGR"Мир";
		}
		switch(MafiaInfo[0][mDiplomacy][2])
		{
			case 0: diplomtext_two = ""cLRED"Война";
			case 1:	diplomtext_two = ""cGREY"Нейтралитет";
			case 2: diplomtext_two = ""cGR"Мир";
		}
		format(string, sizeof(string), "%s"cBLUE"Измайловская ОПГ\t"cWH"%s\n"cBLUE"Курганская ОПГ\t"cWH"%s", string, diplomtext_one, diplomtext_two);
	}
	else if(pData[playerid][pFraction] == 14)
	{
		switch(MafiaInfo[1][mDiplomacy][0])
		{
			case 0: diplomtext_one = ""cLRED"Война";
			case 1:	diplomtext_one = ""cGREY"Нейтралитет";
			case 2: diplomtext_one = ""cGR"Мир";
		}
		switch(MafiaInfo[1][mDiplomacy][2])
		{
			case 0: diplomtext_two = ""cLRED"Война";
			case 1:	diplomtext_two = ""cGREY"Нейтралитет";
			case 2: diplomtext_two = ""cGR"Мир";
		}
		format(string, sizeof(string), "%s"cBLUE"Тамбовская ОПГ\t"cWH"%s\n"cBLUE"Курганская ОПГ\t"cWH"%s", string, diplomtext_one, diplomtext_two);
	}
	else if(pData[playerid][pFraction] == 15)
	{
		switch(MafiaInfo[1][mDiplomacy][0])
		{
			case 0: diplomtext_one = ""cLRED"Война";
			case 1:	diplomtext_one = ""cGREY"Нейтралитет";
			case 2: diplomtext_one = ""cGR"Мир";
		}
		switch(MafiaInfo[1][mDiplomacy][1])
		{
			case 0: diplomtext_two = ""cLRED"Война";
			case 1:	diplomtext_two = ""cGREY"Нейтралитет";
			case 2: diplomtext_two = ""cGR"Мир";
		}
		format(string, sizeof(string), "%s"cBLUE"Тамбовская ОПГ\t"cWH"%s\n"cBLUE"Измайловская ОПГ\t"cWH"%s", string, diplomtext_one, diplomtext_two);
	}

	SPD(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Дипломатия", string, !"Закрыть", "");
	return true;
}
/*
DIALOG_LMENU_SELECT_MAFIA
DIALOG_MSTORE_SELECT
DIALOG_MTAKE_PATRONS
DIALOG_MTAKE_GUNS
DIALOG_MTAKE_DRUGS
DIALOG_MTAKE_HDDRUGS
DIALOG_MTAKE_MONEY
DIALOG_MGIVE_PATRONS
DIALOG_MGIVE_GUNS
DIALOG_MGIVE_DRUGS
DIALOG_MGIVE_HDDRUGS
DIALOG_MGIVE_MONEY
DIALOG_LMENU_EDITRANK
DIALOG_CHANGE_PERMISSION
DIALOG_LMENU_RANKLIST
DIALOG_CHANGE_RANGNAME
DIALOG_NOTIFY_SELECT
DIALOG_ACCEPT_DIPLOMACY
*/























enum bizwar_info
{
	wStatus,
	wDefense,
	wAttack,
	wDScore,
	wAScore,
	wBizID,
	wTimer,
	wZone,
	wArea
}

new mafia_war[bizwar_info];

new Float:gWar_Zone[3][4] = 
{
	{-1864.0110, -2760.2649, -1695.9525, -2942.5950}, // Заброшенная тюрьма
	{-174.2974, 1508.1846, -13.2021, 1363.1201}, // Курятник
	{-1022.0498, 2231.3748, -1134.3915, 2156.7605} // Заброшенный завод
};

new Zone_Name[3][19] =
{
	{"Заброшенная тюрьма"},
	{"Гоночный трек"},
	{"Заброшенный завод"}
};


stock IsPlayerInMafia(mafiaid)
{
	new count;
  	foreach(new i: logged_players)
	{
		if(pData[i][pFraction] == mafiaid)
			count++;
	}
	return count;
}


stock ShowBizwarDialog(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{

		case DIALOG_MAKE_GUN_LIST:
		{
			if(!response)
				return true;

			if(pData[playerid][pGunAmount] < gGunAmount[listitem])
			{
				show_makegun_list(playerid);
				return SendErr(playerid, "Недостаточно ед. оружия для сборки");
			}

			SetPVarIntNew(playerid, "makegun_name", listitem);
			SPD(playerid, DIALOG_MAKE_GUN_INPUT, 1, !""cBLUE"Сборка оружия", !"\n"cWH"Сколько патронов вы хотите использовать для этого оружия?", !"Собрать", !"Отмена");
			return true;
		}
		case DIALOG_MAKE_GUN_INPUT:
		{
			if(!response)
				return show_makegun_list(playerid);

			if(!strlen(inputtext) || !IsNumeric(inputtext))
			{
		   		show_makegun_list(playerid);
		   		SendErr(playerid, "Неверное значение");
		   		return true;     
		   	}
				
			if(strval(inputtext) < 1 || strval(inputtext) > 250)
		    {
		   		show_makegun_list(playerid);
		   		SendErr(playerid, "Допустимое значение патрон от 1 до 250");
		   		return true;     
		   	}

			new 
				gunid = GetPVarIntNew(playerid,"makegun_name");

			if(pData[playerid][pAmmo] < strval(inputtext)) 
				return SendErr(playerid, "У вас недостаточно патронов");

			pData[playerid][pGunAmount] -= gGunAmount[gunid];
			pData[playerid][pAmmo] -= strval(inputtext);

			UpdatePlayerData(playerid, "ammo", pData[playerid][pAmmo]);
			UpdatePlayerData(playerid, "gunamount", pData[playerid][pGunAmount]);

			GivePlayerWeaponEx(playerid, gGunID[gunid], strval(inputtext));
			MeAction(playerid,"собрал оружие");
			DeletePVarNew(playerid, "makegun_name");
			return true;
		}

		case DIALOG_BIZWAR_ACCEPT:
		{
			if(!response)
				return SendInf(playerid, "Стрела отменена");

			if(!IsAMafia(playerid))
				return SendErr(playerid, "Данная команда доступна только ОПГ");

			if(pData[playerid][pRank] < 9)
				return SendErr(playerid, "Команда доступна только лидеру и его заместителям");

			new 
				hour;

			gettime(hour);
/*
			if(hour < 15 || hour > 22)
				return SendErr(playerid, "Использовать команду можно с 15:00 до 22:00");*/

			if(mafia_war[wStatus])
				return SendErr(playerid, "В данный момент уже идёт захват бизнеса");	

			new
				select_zone[150];

			for(new i; i < 3; i++) 
				format(select_zone, sizeof(select_zone), "%s"cBLUE"- "cWH"%s\n", select_zone, Zone_Name[i]);

			SPD(playerid, DIALOG_BIZWAR_SELECT, DIALOG_STYLE_LIST, !""cBLUE"Выберите место проведения стрелы:", select_zone, !"Выбрать", !"Отмена");
			return 1;
		}
		case DIALOG_BIZWAR_SELECT:
		{
			if(!response)
				return SendInf(playerid, "Стрела отменена");

			if(!IsAMafia(playerid))
				return SendErr(playerid, "Данная команда доступна только ОПГ");

			if(pData[playerid][pRank] < 9)
				return SendErr(playerid, "Команда доступна только лидеру и его заместителям");

			new 
				hour;

			gettime(hour);
/*
			if(hour < 15 || hour > 22)
				return SendErr(playerid, "Использовать команду можно с 15:00 до 22:00");*/

			if(mafia_war[wStatus])
				return SendErr(playerid, "В данный момент уже идёт захват бизнеса");

			for(new i; i < MAX_BUSINESS_COUNT; i++)
		    {
				if(IsPlayerInRangeOfPoint(playerid, 15.0, buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z]))
				{
					if(buisness[i][buisnes_mafia] == pData[playerid][pFraction])
						return SendErr(playerid, "Данный бизнес находится под контролем вашей ОПГ");

					if(!buisness[i][buisnes_mafia])
					{
						buisness[i][buisnes_mafia] = pData[playerid][pFraction];

						save_biz(i);
						update_biz_text();

						SendSucc(playerid, "Вы захватили данный бизнес");

						new 
							string[70];

						format(string, sizeof(string), "[F] Ваша ОПГ захватила бизнес №%i", i);
						MafiaFracMessage(pData[playerid][pFraction], 0x4682B4FF, string);
						return true;
					}
					/*
					if(IsPlayerInMafia(pData[playerid][pFraction]) < 3)
							return SendErr(playerid, "В вашей ОПГ недостаточный онлайн");

					if(IsPlayerInMafia(buisness[i][buisnes_mafia]) < 3)
							return SendErr(playerid, "В обороняющиеся ОПГ недостаточный онлайн");*/


					mafia_war[wZone] = GangZoneCreate(gWar_Zone[listitem][0], gWar_Zone[listitem][1], gWar_Zone[listitem][2], gWar_Zone[listitem][3]);
					mafia_war[wArea] = CreateDynamicRectangle(gWar_Zone[listitem][0], gWar_Zone[listitem][1], gWar_Zone[listitem][2], gWar_Zone[listitem][3]);

					foreach(new z : Player)
					{
						if(IsAMafia(z))
						{
							GangZoneShowForPlayer(z, mafia_war[wZone], 0xFF0000AA);

							for(new tds; tds < 6; tds++)
								TextDrawShowForPlayer(z, tdBizWar[tds]);	
						}
					}

					new 
						war_mes[120];

					format(war_mes, sizeof(war_mes), "[Стрела] "cWH"На бизнес вашей ОПГ напали! Место проведения стрелы: "cBLUE"%s", Zone_Name[listitem]);
					MafiaFracMessage(buisness[i][buisnes_mafia], CBLUE, war_mes);

					MafiaFracMessage(buisness[i][buisnes_mafia], CBLUE, "[Стрела] "cWH"У вас есть "cBLUE"10 минут"cWH", чтобы прибыть на место проведения стрелы");

					format(war_mes, sizeof(war_mes), "[Стрела] "cWH"Ваша ОПГ напала на бизнес! Место проведения стрелы: "cBLUE"%s", Zone_Name[listitem]);
					MafiaFracMessage(pData[playerid][pFraction], CBLUE, war_mes);

					MafiaFracMessage(pData[playerid][pFraction], CBLUE, "[Стрела] "cWH"У вас есть "cBLUE"10 минут"cWH", чтобы прибыть на место проведения стрелы");	

					mafia_war[wStatus] = 1;
					mafia_war[wDefense] = buisness[i][buisnes_mafia];
					mafia_war[wAttack] = pData[playerid][pFraction];
					mafia_war[wDScore] = 0;
					mafia_war[wAScore] = 0;
					mafia_war[wBizID] = i;
					mafia_war[wTimer] = 600;

					MafiaInfo[mafia_war[wDefense]-13][mDiplomacy][mafia_war[wAttack]-13] = 0;
					MafiaInfo[mafia_war[wAttack]-13][mDiplomacy][mafia_war[wDefense]-13] = 0;

					SaveMafiaSettings();

					TextDrawSetString(tdBizWar[1], "0");
		            TextDrawSetString(tdBizWar[2], "0");

		            new 
		            	str_mafia[20];

		            format(str_mafia, sizeof str_mafia, "%s", GetMafiaNameTD(mafia_war[wDefense]));
		            TextDrawSetString(tdBizWar[4], str_mafia);

		            format(str_mafia, sizeof str_mafia, "%s", GetMafiaNameTD(mafia_war[wAttack]));
		            TextDrawSetString(tdBizWar[5], str_mafia);
		            return 1;
				}
			}
			return SendErr(playerid, "Вы должны находиться у бизнеса");	
		}
		case DIALOG_SELL_DRUGS:
		{
			new 
				offerid = GetPVarIntNew(playerid, "recieve_drugs")-1;

			if(!response)
			{

				DeletePVarNew(playerid, "recieve_drugs");
				DeletePVarNew(playerid, "drugs_type");
				DeletePVarNew(playerid, "drugs_count");
				DeletePVarNew(playerid, "drugs_price");

				SendInf(playerid, "Вы отказались от покупки наркотиков");

				if(GetPVarIntNew(offerid, "offer_drugs")-1 == playerid)
				{
					DeletePVarNew(offerid, "offer_drugs");
					format(String144, sizeof(String144), "Игрок %s отказался от покупки наркотиков", pData[playerid][pNickname]);
					SendInf(offerid, String144);
				}
				return true;
			}

			if(GetPVarIntNew(offerid, "offer_drugs") != playerid+1)
				return SendErr(playerid, "Предложение неактивно");

			new 
				type_drugs = GetPVarIntNew(playerid, "drugs_type"),
				drugs_count = GetPVarIntNew(playerid, "drugs_count"),
				price = GetPVarIntNew(playerid, "drugs_price");

			DeletePVarNew(playerid, "recieve_drugs");
			DeletePVarNew(playerid, "drugs_type");
			DeletePVarNew(playerid, "drugs_count");
			DeletePVarNew(playerid, "drugs_price");
			DeletePVarNew(offerid, "offer_drugs");

			if(type_drugs == 1 && pData[offerid][pDrugs] < drugs_count)
				return SendErr(playerid, "У игрока нет данного количества наркотиков");

			if(type_drugs == 2 && pData[offerid][pHDrugs] < drugs_count)
				return SendErr(playerid, "У игрока нет данного количества наркотиков");

			if(type_drugs == 1 && pData[playerid][pDrugs]+drugs_count > 1000)
				return SendErr(playerid, "У вас нет места для наркотиков");

			if(type_drugs == 2 && pData[playerid][pHDrugs]+drugs_count > 1000)
				return SendErr(playerid, "У вас нет места для наркотиков");

			if(GetPlayerDistanceToPlayer(playerid, offerid) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(offerid))
				return SendErr(playerid, "Вы находитесь далеко друг от друга");	

			if(GetPlayerMoneyEx(playerid) < price)
				return SendErr(playerid, "У Вас нет нужной суммы на руках");

			switch(type_drugs)
			{
				case 1:
				{
					pData[playerid][pDrugs] += drugs_count;
					pData[offerid][pDrugs] -= drugs_count;

					UpdatePlayerData(playerid, "drugs", pData[playerid][pDrugs]);
					UpdatePlayerData(offerid, "drugs", pData[offerid][pDrugs]);
				}
				case 2:
				{
					pData[playerid][pHDrugs] += drugs_count;
					pData[offerid][pHDrugs] -= drugs_count;

					UpdatePlayerData(playerid, "hdrugs", pData[playerid][pHDrugs]);
					UpdatePlayerData(offerid, "hdrugs", pData[offerid][pHDrugs]);
				}
			}

			give_money(playerid, -price, "Покупка наркотиков у игрока");
			give_money(offerid, price, "Продажа наркотиков игроку");

			format(String144, sizeof(String144), "Вы купили "cGR"%i гр. "cWH"%s наркотиков у игрока "cGR"%s "cWH"за "cGR"%i рублей",
				drugs_count,
				type_drugs == 1 ? ("легких") : ("тяжелых"),
				pData[offerid][pNickname],
				price);
			SendSucc(playerid, String144);

			format(String144, sizeof(String144), "Игрок "cGR"%s "cWH"купил "cGR"%i гр. "cWH"%s наркотиков за "cGR"%i рублей",
				pData[playerid][pNickname],
				drugs_count,
				type_drugs == 1 ? ("легких") : ("тяжелых"),
				price);
			SendSucc(offerid, String144);

			format(String64, sizeof(String64), "продал наркотики %s", pData[playerid][pNickname]);
			MeAction(offerid, String64);

			return true;
		}
	}
	return 1;
}

callback:: update_mafia_time() // Секундный таймер
{
	

	if(mafia_war[wTimer] > 0 && mafia_war[wStatus] == 1)
    {
    	TextDrawSetString(tdBizWar[3], time_to_string(mafia_war[wTimer]));
        mafia_war[wTimer]--;
    }
    if(mafia_war[wTimer] == 0 && mafia_war[wStatus] == 1)
    {
        MafiaFracMessage(mafia_war[wDefense], CBLUE, "[Стрела] "cWH"Стрела началась!");
        MafiaFracMessage(mafia_war[wAttack], CBLUE, "[Стрела] "cWH"Стрела началась!");

        mafia_war[wStatus] = 2;
        mafia_war[wTimer] = 600;
    }
    else if(mafia_war[wTimer] > 0 && mafia_war[wStatus] == 2)
    {
    	TextDrawSetString(tdBizWar[3], time_to_string(mafia_war[wTimer]));
        mafia_war[wTimer]--;
    }

    else if(mafia_war[wTimer] == 0 && mafia_war[wStatus] == 2)
    {
    	GetMafiaWarWinner();
    }
	return 1;
}

stock GetMafiaWarWinner()
{
	if(mafia_war[wTimer] == 0 && mafia_war[wStatus] == 2)
	{
		new 
			war_mes[120];
		if(mafia_war[wDScore] > mafia_war[wAScore] || mafia_war[wAScore] == 0 && mafia_war[wDScore] == 0)
		{
			format(war_mes, sizeof(war_mes), "[Стрела] "cWH"Вы защитили право на крышевание бизнеса "cBLUE"№%d", buisness[mafia_war[wBizID]][buisnes_id]);
			MafiaFracMessage(mafia_war[wDefense], CBLUE, war_mes);
			format(war_mes, sizeof(war_mes), "[Стрела] "cWH"Вам не удалось захватить бизнес "cBLUE"№%d", buisness[mafia_war[wBizID]][buisnes_id]);
			MafiaFracMessage(mafia_war[wAttack], CBLUE, war_mes);
		}
		else if(mafia_war[wAScore] > mafia_war[wDScore] || mafia_war[wAScore] == mafia_war[wDScore])
		{
			// Передача биза Атакующей стороне mafia_war[wBizID]

			buisness[mafia_war[wBizID]][buisnes_mafia] = mafia_war[wAttack];

			save_biz(mafia_war[wBizID]);
			update_biz_text();

			UpdateMafiaText();
			format(war_mes, sizeof(war_mes), "[Стрела] "cWH"Вы выиграли стрелу за бизнес "cBLUE"№%d",  buisness[mafia_war[wBizID]][buisnes_id]);
			MafiaFracMessage(mafia_war[wAttack], CBLUE, war_mes);
			format(war_mes, sizeof(war_mes), "[Стрела] "cWH"Вы потеряли право на крышевание бизнеса "cBLUE"№%d", buisness[mafia_war[wBizID]][buisnes_id]);
			MafiaFracMessage(mafia_war[wDefense], CBLUE, war_mes);
		}

		foreach(new i: logged_players)
		{
			if(IsAMafia(i))	
			{
				for(new z; z < 6; z++)
					TextDrawHideForPlayer(i, tdBizWar[z]);
				GangZoneHideForPlayer(i, mafia_war[wZone]);
			}			
		}

		GangZoneDestroy(mafia_war[wZone]);
		DestroyDynamicArea(mafia_war[wArea]);

		mafia_war[wStatus] = 0;
		mafia_war[wDefense] = 0;
		mafia_war[wAttack] = 0;
		mafia_war[wDScore] = 0;
		mafia_war[wAScore] = 0;
		mafia_war[wBizID] = 0;
		mafia_war[wTimer] = 0;
	}
	return 1;
}

stock KillOnWar(playerid, killerid) // OnplayerDeath
{
	if(killerid != INVALID_PLAYER_ID)
	{
		if(IsAMafia(killerid) && IsAMafia(playerid) && mafia_war[wStatus] == 1)
		{
		    if(IsPlayerInDynamicArea(killerid, mafia_war[wArea]))
		    {
			    new
				    warning[144];

				format(warning, sizeof (warning), "[A] %s[%i] убил на метке до начала стрелы %s[%i]", pData[killerid][pNickname], killerid, pData[playerid][pNickname], playerid);
			    AdminChat(COLOR_GREY, warning);
			    return 1;
	    	}
		}
		else if(IsAMafia(killerid) && IsAMafia(playerid) && mafia_war[wStatus] == 2)
		{
		    if(IsPlayerInDynamicArea(killerid, mafia_war[wArea]))
		    {

			    if(pData[killerid][pFraction] != pData[playerid][pFraction] && pData[killerid][pFraction] == mafia_war[wAttack] && mafia_war[wStatus] == 2) mafia_war[wAScore] += 1;
			    else if(pData[killerid][pFraction] != pData[playerid][pFraction] && pData[killerid][pFraction] == mafia_war[wDefense] && mafia_war[wStatus] == 2) mafia_war[wDScore] += 1;
			    UpdateMafiaTextDraw();
	    	}
		}
	}
	return 1;
}

stock UpdateMafiaTextDraw()
{
	new
        str_mafia[25];

    format(str_mafia, sizeof str_mafia, "%i", mafia_war[wDScore]);
    TextDrawSetString(tdBizWar[1], str_mafia);

    format(str_mafia, sizeof str_mafia, "%i", mafia_war[wAScore]);
    TextDrawSetString(tdBizWar[2], str_mafia);

    return 1;
}

stock MafiaWarConnect(playerid)// При загрузке перса
{
	if(IsAMafia(playerid) && mafia_war[wStatus])
	{
		GangZoneShowForPlayer(playerid, mafia_war[wZone], 0xFF0000AA);
		for(new z; z < 6; z++)
			TextDrawShowForPlayer(playerid, tdBizWar[z]);
	}
	return 1;
}

stock GetMafiaNameTD(id)
{
	new string[14];
	switch(id)
	{
		case 13: format(string,sizeof(string),"Tambovskaya");
		case 14: format(string,sizeof(string),"Kurganskaya");
		case 15: format(string,sizeof(string),"Izmailovskaya");
	}
	return string;
}
//===================================[Команда]===================================
CMD:bizwar(playerid)
{
	if(!IsAMafia(playerid))
		return SendErr(playerid, "Данная команда доступна только ОПГ");

	if(pData[playerid][pRank] < 9)
		return SendErr(playerid, "Команда доступна только лидеру и его заместителям");
	new 
		hour;

	gettime(hour);
/*
	if(hour < 15 || hour > 22)
		return SendErr(playerid, "Использовать команду можно с 15:00 до 22:00");*/

	if(mafia_war[wStatus])
		return SendErr(playerid, "В данный момент уже идёт захват бизнеса");

	for(new i; i < MAX_BUSINESS_COUNT; i++)
    {
		if(IsPlayerInRangeOfPoint(playerid, 15.0, buisness[i][buisnes_enter_x], buisness[i][buisnes_enter_y], buisness[i][buisnes_enter_z]))
		{
			if(buisness[i][buisnes_mafia] == pData[playerid][pFraction])
				return SendErr(playerid, "Данный бизнес находится под контролем вашей ОПГ");

			if(!buisness[i][buisnes_mafia])
			{
				//Если на бизнесе нет крыши - передаем крышу ОПГ playerid

				buisness[i][buisnes_mafia] = pData[playerid][pFraction];

				save_biz(i);
				update_biz_text();

				SendSucc(playerid, "Вы захватили данный бизнес");

				new 
					string[70];

				format(string, sizeof(string), "[F] Ваша ОПГ захватила бизнес №%i", i);
				MafiaFracMessage(pData[playerid][pFraction], 0x4682B4FF, string);
				return true;
			}
			/*
			if(IsPlayerInMafia(pData[playerid][pFraction]) < 3)
					return SendErr(playerid, "В вашей ОПГ недостаточный онлайн");

			if(IsPlayerInMafia(buisness[i][buisnes_mafia]) < 3)
					return SendErr(playerid, "В обороняющиеся ОПГ недостаточный онлайн");*/
			new
				bizwar_mes[120];

			format(bizwar_mes, sizeof(bizwar_mes), "\n"cWH"Этот бизнес принадлежит "cBLUE"%s\n\n"cWH"Вы действительно хотите начать стрелу за бизнес?",  gFractionName[buisness[i][buisnes_mafia]-1]);
			return SPD(playerid, DIALOG_BIZWAR_ACCEPT, DIALOG_STYLE_MSGBOX, !""cBLUE"Захват бизнеса", bizwar_mes, !"Начать", !"Отмена");
		}
	}
	return SendErr(playerid, "Вы должны находиться у бизнеса");
}
//===================================[Команда]===================================
/*
DIALOG_BIZWAR_ACCEPT
DIALOG_BIZWAR_SELECT
*/


CMD:makegun(playerid)
{
	if(!IsAMafia(playerid))
		return SendErr(playerid, "Данная команда доступна только ОПГ");

	if(GetPlayerVirtualWorld(playerid) != 0)
		return SendErr(playerid, "Создавать оружие можно только на улице");

	if(!pData[playerid][pAmmo])
		return SendErr(playerid, "У Вас нет патрон");

	show_makegun_list(playerid);

	return true;
}

stock show_makegun_list(playerid)
{
	SPD(playerid, DIALOG_MAKE_GUN_LIST, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Сборка оружия", !"\
		"cGREY"Оружие\t"cGREY"Ед. оружия\n\
		"cBLUE"Desert Eagle\t"cWH"180\n\
		"cBLUE"MP5\t"cWH"200\n\
		"cBLUE"ShotGun\t"cWH"280\n\
		"cBLUE"Rifle\t"cWH"380\n\
		"cBLUE"AK-47\t"cWH"300\n\
		"cBLUE"M4\t"cWH"300", !"Далее", !"Отмена");
	return true;
}



stock enter_mafia_pickup(playerid, type)
{

	if(GetPVarIntNew(playerid, "take_army_box"))
	{
		RemovePlayerAttachedObject(playerid, 0);
		ApplyAnimation(playerid,"CARRY","liftup",1.0,0,1,1,0,0,1);
		DeletePVarNew(playerid, "take_army_box");

		MafiaInfo[type][mPatrons] += 500;
		MafiaInfo[type][mGuns] += 500;
		UpdateMafiaText();
		SaveMafiaWarehouse();

		new 
			frac_mes[144];

		format(frac_mes, sizeof (frac_mes), "[Склад ОПГ] "cWH"%s %s[%i] положил на склад ящик с "cBLUE"500 "cWH"патронами и ед. оружия",
		gFractionRankName[pData[playerid][pFraction]-1][pData[playerid][pRank]-1], pData[playerid][pNickname], playerid);
		MafiaFracMessage(type+13, CBLUE, frac_mes);
		return true;
	}
	return true;
}

CMD:gag(playerid, params[])
{
	if(!IsAMafia(playerid))
		return SendErr(playerid, "Данная команда доступна только ОПГ");

	if(pData[playerid][pRank] < 3) 
		return SendErr(playerid, "Функция доступна с 3 ранга");

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/gag [ID игрока]");

	if(!IsPlayerConnected(params[0]) || IsKicked(params[0]) || playerid == params[0]) 
		return SendErr(playerid, "Неверный ID");

	if(GetPlayerDistanceToPlayer(playerid, params[0]) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(params[0])) 
		return SendErr(playerid, "Вы далеко друг от друга");

	if(GetPVarIntNew(params[0], "gag")) 
		return SendErr(playerid, "У игрока уже есть кляп во рту");

	format(String64, sizeof(String64), "Вы заткнули рот %s", pData[params[0]][pNickname]);
	SendSucc(playerid, String64);

	format(String64, sizeof(String64), "заткнул рот %s", pData[params[0]][pNickname]);
	MeAction(playerid, String64);

	SetPVarIntNew(params[0], "gag", 1);
	return true;
}
// Если пвар "gag" активен - блокировать ему РП чат, /r /f /w /s /call if(GetPVarIntNew(playerid, "gag")) return SendErr(playerid, "Вы не можете говорить, пока у вас заткнут рот");

 CMD:ungag(playerid, params[])
 {
 	if(!IsAMafia(playerid) && pData[playerid][pFraction] != 9 && pData[playerid][pFraction] != 12)
 		return SendErr(playerid, "Доступно только ОПГ, полиции и ФСБ");

 	if(pData[playerid][pRank] < 3) 
		return SendErr(playerid, "Функция доступна с 3 ранга");

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/ungag [ID игрока]");

	if(!IsPlayerConnected(params[0]) || IsKicked(params[0])) 
		return SendErr(playerid, "Неверный ID");

	if(GetPlayerDistanceToPlayer(playerid, params[0]) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(params[0])) 
		return SendErr(playerid, "Вы далеко друг от друга");

	if(GetPVarIntNew(params[0], "gag")) 
	{
		format(String64, sizeof(String64), "Вы вытащили кляп у %s", pData[params[0]][pNickname]);
		SendSucc(playerid, String64);

		format(String64, sizeof(String64), "вытащил кляп у %s", pData[params[0]][pNickname]);
		MeAction(playerid, String64);

		DeletePVarNew(params[0], "gag");
	}
	else 
		SendErr(playerid, "У игрока нет кляпа во рту");
	return true;
 }

CMD:selldrugs(playerid, params[])
{
	if(!IsAMafia(playerid))
		return SendErr(playerid, "Команда доступна только ОПГ");

	if(GetPVarIntNew(playerid, "offer_drugs") || GetPVarIntNew(playerid, "recieve_drugs"))
		return SendErr(playerid, "У вас уже есть активное предложение");

	if(sscanf(params, "dddd", params[0], params[1], params[2], params[3])) 
		return SendInf(playerid, "/selldrugs [ID игрока] [1 - Легкие, 2 - Тяжелые] [Кол-во] [Цена продажи]");

	if(!IsPlayerConnected(params[0]) || playerid == params[0])
		return SendErr(playerid, "Неверный ID");
	
	if(GetPlayerDistanceToPlayer(playerid, params[0]) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(params[0]))
		return SendErr(playerid, "Вы находитесь далеко друг от друга");	

	if(params[1] < 1 || params[1] > 2)
		return SendInf(playerid, "1 - Легие нароктики 2 - Тяжелые наркотики");

	if(params[2] < 1 || params[2] > 1000)
		return SendErr(playerid, "Неверное количество наркотиков");

	if(params[1] == 1 && pData[playerid][pDrugs] < params[2])
		return SendErr(playerid, "У Вас нет такого количества легких наркотиков");

	if(params[1] == 2 && pData[playerid][pHDrugs] < params[2])
		return SendErr(playerid, "У Вас нет такого количества тяжелых наркотиков");

	if(params[1] == 1 && pData[params[0]][pDrugs]+params[2] > 1000)
		return SendErr(playerid, "Игрок не может принять такое количество наркотиков");

	if(params[1] == 2 && pData[params[0]][pHDrugs]+params[2] > 1000)
		return SendErr(playerid, "Игрок не может принять такое количество наркотиков");

	if(params[3] < 1 || params[3] > 50000)
		return SendErr(playerid, "Цена продажи не может быть больше 50 тыс. рублей");

	if(GetPlayerMoneyEx(params[0]) < params[3])
		return SendErr(playerid, "У игрока нет данной суммы на руках");

	format(String144, sizeof(String144), "Вы предложили "cGR"%s "cWH"купить %s наркотики за "cGR"%i "cWH"рублей", 
		pData[params[0]][pNickname],  
		params[1] == 1 ? ("легие") : ("тяжелые"),
		params[3]);
	SendSucc(playerid, String144);

	SetPVarIntNew(playerid, "offer_drugs", params[0]+1);
	SetPVarIntNew(params[0], "recieve_drugs", playerid+1);
	SetPVarIntNew(params[0], "drugs_type", params[1]);
	SetPVarIntNew(params[0], "drugs_count", params[2]);
	SetPVarIntNew(params[0], "drugs_price", params[3]);


	format(String512, sizeof(String512), "\n\
		"cWH"Игрок "cBLUE"%s "cWH"предлагает Вам купить %s наркотики\n\n\
		"cWH"Количество: "cBLUE"%i гр.\n\
		"cWH"Цена: "cBLUE"%i рублей\n\n\
		"cWH"Вы действительно хотите купить?", 
		pData[playerid][pNickname], 
		params[1] == 1 ? ("легкие") : ("тяжелые"), 
		params[2], 
		params[3]);

	SPD(params[0], DIALOG_SELL_DRUGS, DIALOG_STYLE_MSGBOX, !""cBLUE"Предложение покупки наркотиков", String512, !"Купить", !"Отмена");
	return true;
}



stock delete_pvar_drugs(playerid)
{
	DeletePVarNew(playerid, "recieve_drugs");
	DeletePVarNew(playerid, "drugs_type");
	DeletePVarNew(playerid, "drugs_count");
	DeletePVarNew(playerid, "drugs_price");
	DeletePVarNew(playerid, "offer_drugs");
	return true;
}