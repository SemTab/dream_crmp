static const Float:position_spawn_car_hospital_1[][] =
{
	{478.4407,1695.9250,12.1467,69.5017},
	{480.0576,1699.6536,12.1464,68.3771},
	{481.4900,1703.8766,12.1464,68.3907},
	{482.9105,1707.2690,12.1464,69.5586},
	{484.1369,1710.8002,12.1463,68.1470},
	{485.6994,1714.8972,12.1464,68.8558},
	{487.1759,1718.6268,12.1467,69.2650},
	{488.4232,1722.2151,12.1465,69.7824},
	{489.9935,1726.2061,12.1467,70.0128},
	{491.2870,1729.8795,12.1464,69.0746},
	{492.6152,1733.4583,12.1464,71.0281},
	{494.1572,1737.4131,12.1461,69.3342},
	{495.4806,1741.0035,12.1464,69.0102},
	{496.8354,1744.6357,12.1466,69.7703},
	{498.3250,1748.6356,12.1466,68.8747},
	{499.7822,1752.2849,12.1464,68.8715},
	{501.1159,1755.9980,12.1465,70.2638},
	{502.6514,1760.0557,12.1463,69.7539},
	{516.4023,1791.5490,12.1464,160.0246},
	{512.4554,1793.2290,12.1466,158.9886},
	{508.4502,1794.6085,12.1468,159.2777},
	{504.6736,1795.9242,12.1464,158.7261},
	{499.2426,1786.8879,12.1504,250.2760},
	{497.6249,1782.8662,12.1505,247.8420},
	{496.2743,1779.1387,12.1489,249.1822},
	{494.9523,1775.6023,12.1485,249.1120},
	{493.5083,1771.6506,12.1503,247.9785},
	{492.0786,1768.0024,12.1504,249.9447},
	{490.6193,1764.3712,12.1462,249.4810},
	{489.1616,1760.3815,12.1466,249.2224},
	{487.8839,1756.7661,12.1465,249.9064},
	{486.5131,1753.1683,12.1464,249.3656},
	{485.0365,1749.2773,12.1470,249.2975},
	{483.6815,1745.4541,12.1504,248.8711},
	{482.3285,1741.7860,12.1504,249.6422},
	{480.8204,1737.8624,12.1504,249.9844},
	{479.3768,1734.2500,12.1505,249.3158},
	{478.1656,1730.7190,12.1502,249.6851},
	{476.5244,1726.7500,12.1502,247.7377},
	{475.6640,1722.8236,12.1465,248.8902}

};


static const Float:position_spawn_car_hospital_2[][] =
{
	{2098.8838,-2434.0264,22.0128,89.0699},
	{2098.5657,-2426.5940,22.0139,90.2394},
	{2098.6340,-2419.5762,22.0088,89.9829},
	{2098.6372,-2412.5906,22.0129,90.6095},
	{2084.1550,-2412.2493,21.8893,269.2996},
	{2084.1123,-2416.4868,21.8892,267.8875},
	{2084.0330,-2420.5659,21.8882,267.3420},
	{2083.9944,-2424.6057,21.8902,267.6958},
	{2083.9351,-2428.7720,21.8925,269.3396},
	{2083.9636,-2432.9927,21.8895,271.0980},
	{2084.0295,-2437.1887,21.8865,270.7602}
};

new hospital_car_model[] =
{
	416, 474,
};


stock create_hospital_other_element()
{

	pickup_spawn_car_hospital_1 = create_circle_pickup(472.9686,1721.1832,11.9973, TRIGGER_LRED);
	pickup_spawn_car_hospital_2 = create_circle_pickup(2096.6384,-2408.9875,21.8334, TRIGGER_LRED);

	CreateDynamic3DTextLabel(""cWH"Автопарк Больницы г.Арзамас\n\
		"cLRED"[Встаньте на пикап]", CWHITE, 472.9686,1721.1832,11.9973, 5.0,INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
	CreateDynamic3DTextLabel(""cWH"Автопарк Больницы г.Южный\n\
		"cLRED"[Встаньте на пикап]", CWHITE, 2096.6384,-2408.9875,21.8334, 5.0,INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);



	return true;
}


stock spawn_hospital_1_vehicle(playerid)
{
	format(String512, sizeof(String512), "\
    "cGREY"Автомобиль\t"cGREY"Действие\n\
    "cBLUE"1. "cWH"%s\t"cGR"Взять\n\
    "cBLUE"2. "cWH"%s\t"cGR"Взять\n\
    \t\n\
    "cWH"Доступно всего: \t"cBLUE"%d"cWH" автомобилей", 
    transport_config[hospital_car_model[0]-400][transport_name],
    transport_config[hospital_car_model[1]-400][transport_name],
    count_hospital_1_vehicle
    );
 	SPD(playerid, DIALOG_SELECT_CAR_HOSPITAL_1, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Выбор автомобиля", String512, !"Выбрать", !"Закрыть"); 

 	return true;
}

stock spawn_hospital_2_vehicle(playerid)
{
	format(String512, sizeof(String512), "\
    "cGREY"Автомобиль\t"cGREY"Действие\n\
    "cBLUE"1. "cWH"%s\t"cGR"Взять\n\
    "cBLUE"2. "cWH"%s\t"cGR"Взять\n\
    \t\n\
    "cWH"Доступно всего: \t"cBLUE"%d"cWH" автомобилей", 
    transport_config[hospital_car_model[0]-400][transport_name],
    transport_config[hospital_car_model[1]-400][transport_name],
    count_hospital_2_vehicle
    );
 	SPD(playerid, DIALOG_SELECT_CAR_HOSPITAL_2, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Выбор автомобиля", String512, !"Выбрать", !"Закрыть"); 

 	return true;
}

stock spawn_hospital_1_veh_start(playerid, type_car)
{
	switch(type_car)
	{
		case 0:
		{
			if(count_hospital_1_vehicle == 0)
			{
				spawn_hospital_1_vehicle(playerid);
				return SendErr(playerid, "Недостаточно госсударственных автомобилей!");
			}

			if(pData[playerid][pFraction] != 2 && pData[playerid][pSubfraction] != 2)
			{
				SendErr(playerid, "Доступно только сотрудникам Больницы!");
				return true;
			}	

			create_vehicle_hospital_1(playerid, 0);
		}
		case 1:
		{
			if(count_hospital_1_vehicle == 0)
			{
				spawn_hospital_1_vehicle(playerid);
				return SendErr(playerid, "Недостаточно госсударственных автомобилей!");
			}

			if(pData[playerid][pFraction] != 2 && pData[playerid][pSubfraction] != 2)
			{
				SendErr(playerid, "Доступно только сотрудникам Больницы!");
				return true;
			}	

			create_vehicle_hospital_1(playerid, 1);
		}
	}

	return true;
}

stock spawn_hospital_2_veh_start(playerid, type_car)
{
	switch(type_car)
	{
		case 0:
		{
			if(count_hospital_2_vehicle == 0)
			{
				spawn_hospital_2_vehicle(playerid);
				return SendErr(playerid, "Недостаточно госсударственных автомобилей!");
			}

			if(pData[playerid][pFraction] != 2 && pData[playerid][pSubfraction] != 1)
			{
				SendErr(playerid, "Доступно только сотрудникам Больницы!");
				return true;
			}	

			create_vehicle_hospital_2(playerid, 0);
		}
		case 1:
		{
			if(count_hospital_2_vehicle == 0)
			{
				spawn_hospital_2_vehicle(playerid);
				return SendErr(playerid, "Недостаточно госсударственных автомобилей!");
			}

			if(pData[playerid][pFraction] != 2 && pData[playerid][pSubfraction] != 1)
			{
				SendErr(playerid, "Доступно только сотрудникам Больницы!");
				return true;
			}	

			create_vehicle_hospital_2(playerid, 1);
		}
	}

	return true;
}

stock create_vehicle_hospital_1(playerid, veh_type)
{
	new 
		random_pos = random(40);

	new 
		c1 = 1,
		c2 = 3;	

	if(veh_type == 474)
	{
		c1 = 3;
		c2 = 3;
	}


	new 
		vehicle_hospital_1 = CreateVehicle(hospital_car_model[veh_type], position_spawn_car_hospital_1[random_pos][0], position_spawn_car_hospital_1[random_pos][1], position_spawn_car_hospital_1[random_pos][2], position_spawn_car_hospital_1[random_pos][3], c1, c2, 600);	

	format(vehicle[vehicle_hospital_1][cPlate], 20, "б0%dбб", count_hospital_1_vehicle);
	SetVehicleGosNumberPlate(vehicle_hospital_1, vehicle[vehicle_hospital_1][cPlate], "77");

	PutPlayerInVehicleEx(playerid, vehicle_hospital_1, 0);

	vehicle[vehicle_hospital_1][cFuel] = transport_config[GetVehicleModel(vehicle_hospital_1)-400][transport_tank];
	vehicle[vehicle_hospital_1][cHealth] = 1000.0;
	vehicle[vehicle_hospital_1][cIsCreated] = true;
	vehicle[vehicle_hospital_1][consumables_oil] = 1000.0;

	vehicle[vehicle_hospital_1][cOwnTo] = VEHICLE_HOSPITAL_1;

	vehicle[vehicle_hospital_1][cLock] = 2;

	vehicle_lock_status(vehicle_hospital_1, true);

	count_hospital_1_vehicle--;

	return true;
}

stock create_vehicle_hospital_2(playerid, veh_type)
{
	new 
		random_pos = random(10);

	new 
		c1 = 1,
		c2 = 3;	

	if(veh_type == 474)
	{
		c1 = 3;
		c2 = 3;
	}

	new 
		vehicle_hospital_2 = CreateVehicle(hospital_car_model[veh_type], position_spawn_car_hospital_2[random_pos][0], position_spawn_car_hospital_2[random_pos][1], position_spawn_car_hospital_2[random_pos][2], position_spawn_car_hospital_2[random_pos][3], c1, c2, 600);	

	format(vehicle[vehicle_hospital_2][cPlate], 20, "Больница");
	SetVehicleNumberPlate(vehicle_hospital_2, vehicle[vehicle_hospital_2][cPlate]);

	PutPlayerInVehicleEx(playerid, vehicle_hospital_2, 0);

	vehicle[vehicle_hospital_2][cFuel] = transport_config[GetVehicleModel(vehicle_hospital_2)-400][transport_tank];
	vehicle[vehicle_hospital_2][cHealth] = 1000.0;
	vehicle[vehicle_hospital_2][cIsCreated] = true;
	vehicle[vehicle_hospital_2][consumables_oil] = 1000.0;

	vehicle[vehicle_hospital_2][cOwnTo] = VEHICLE_HOSPITAL_2;

	vehicle[vehicle_hospital_2][cLock] = 2;

	vehicle_lock_status(vehicle_hospital_2, true);

	count_hospital_2_vehicle--;

	return true;
}

stock dialog_all_hospital(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
	    case DIALOG_SELECT_CAR_HOSPITAL_1: 
	    {
	    	if(!response)
	    		return true;

	    	switch(listitem)
	    	{
		    	case 0: return spawn_hospital_1_veh_start(playerid, 0);
		    	case 1: return spawn_hospital_1_veh_start(playerid, 1);
		    	case 2: return spawn_hospital_1_vehicle(playerid);
		    	case 3: return spawn_hospital_1_vehicle(playerid);
		    }
	    }
	    case DIALOG_SELECT_CAR_HOSPITAL_2: 
	    {
	    	if(!response)
	    		return true;
	    	
	    	switch(listitem)
	    	{
		    	case 0: return spawn_hospital_2_veh_start(playerid, 0);
		    	case 1: return spawn_hospital_2_veh_start(playerid, 1);
		    	case 2: return spawn_hospital_2_vehicle(playerid);
		    	case 3: return spawn_hospital_2_vehicle(playerid);
		    }
	    }
	}



	return true;
}