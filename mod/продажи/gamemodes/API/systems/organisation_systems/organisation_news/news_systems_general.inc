static const Float:position_spawn_car_news_1[][] =
{
	{-302.7569,840.6776,12.6886,179.7452},
	{-300.3854,840.6359,12.6890,180.7171}

};

static const Float:position_spawn_car_news_2[][] =
{
	{2075.4175,-1924.7777,18.4448,269.7578},
	{2075.1846,-1922.0430,18.4445,270.4746}

};

new news_car_model[] =
{
	582
};


stock create_news_other_element()
{

	pickup_spawn_car_news_1 = create_circle_pickup(-307.7493,817.0411,13.0559, TRIGGER_LRED);
	pickup_spawn_car_news_2 = create_circle_pickup(2074.4709,-1929.2307,18.8125, TRIGGER_LRED);

	CreateDynamic3DTextLabel(""cWH"Автопарк Радиоцентра\n\
		"cLRED"[Встаньте на пикап]", CWHITE, -307.7493,817.0411,13.0559, 5.0,INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
	CreateDynamic3DTextLabel(""cWH"Автопарк ТРК\n\
		"cLRED"[Встаньте на пикап]", CWHITE, 2074.4709,-1929.2307,18.8125, 5.0,INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);



	return true;
}


stock spawn_news_1_vehicle(playerid)
{
	format(String512, sizeof(String512), "\
    "cGREY"Автомобиль\t"cGREY"Действие\n\
    "cBLUE"1. "cWH"%s\t"cGR"Взять\n\
    \t\n\
    "cWH"Доступно всего: \t"cBLUE"%d"cWH" автомобилей", 
    transport_config[news_car_model[0]-400][transport_name],
    count_news_1_vehicle
    );
 	SPD(playerid, DIALOG_SELECT_CAR_NEWS_1, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Выбор автомобиля", String512, !"Выбрать", !"Закрыть"); 

 	return true;
}

stock spawn_news_2_vehicle(playerid)
{
	format(String512, sizeof(String512), "\
    "cGREY"Автомобиль\t"cGREY"Действие\n\
    "cBLUE"1. "cWH"%s\t"cGR"Взять\n\
    \t\n\
    "cWH"Доступно всего: \t"cBLUE"%d"cWH" автомобилей", 
    transport_config[news_car_model[0]-400][transport_name],
    count_news_2_vehicle
    );
 	SPD(playerid, DIALOG_SELECT_CAR_NEWS_2, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Выбор автомобиля", String512, !"Выбрать", !"Закрыть"); 

 	return true;
}

stock spawn_news_1_veh_start(playerid, type_car)
{
	switch(type_car)
	{
		case 0:
		{
			if(count_news_1_vehicle == 0)
			{
				spawn_news_1_vehicle(playerid);
				return SendErr(playerid, "Недостаточно госсударственных автомобилей!");
			}

			if(pData[playerid][pFraction] != 10 || pData[playerid][pSubfraction] == 0)
			{ 
				SendErr(playerid, "Доступно только сотрудникам СМИ!");
				return true;
			}	

			create_vehicle_news_1(playerid, 0);
		}
		case 1:
		{
			if(count_news_1_vehicle == 0)
			{
				spawn_news_1_vehicle(playerid);
				return SendErr(playerid, "Недостаточно госсударственных автомобилей!");
			}

			if(pData[playerid][pFraction] != 10 || pData[playerid][pSubfraction] == 0)
			{
				SendErr(playerid, "Доступно только сотрудникам СМИ!");
				return true;
			}	

			create_vehicle_news_1(playerid, 1);
		}
		case 2:
		{
			if(count_news_1_vehicle == 0)
			{
				spawn_news_1_vehicle(playerid);
				return SendErr(playerid, "Недостаточно госсударственных автомобилей!");
			}

			if(pData[playerid][pFraction] != 10 || pData[playerid][pSubfraction] == 0)
			{
				SendErr(playerid, "Доступно только сотрудникам СМИ!");
				return true;
			}	

			create_vehicle_news_1(playerid, 2);
		}
	}

	return true;
}

stock spawn_news_2_veh_start(playerid, type_car)
{
	switch(type_car)
	{
		case 0:
		{
			if(count_news_2_vehicle == 0)
			{
				spawn_news_2_vehicle(playerid);
				return SendErr(playerid, "Недостаточно госсударственных автомобилей!");
			}

			if(pData[playerid][pFraction] != 10 || pData[playerid][pSubfraction] == 0)
			{
				SendErr(playerid, "Доступно только сотрудникам СМИ!");
				return true;
			}	

			create_vehicle_news_2(playerid, 0);
		}
		case 1:
		{
			if(count_news_2_vehicle == 0)
			{
				spawn_news_2_vehicle(playerid);
				return SendErr(playerid, "Недостаточно госсударственных автомобилей!");
			}

			if(pData[playerid][pFraction] != 10 || pData[playerid][pSubfraction] == 0)
			{
				SendErr(playerid, "Доступно только сотрудникам СМИ!");
				return true;
			}	

			create_vehicle_news_2(playerid, 1);
		}
		case 2:
		{
			if(count_news_2_vehicle == 0)
			{
				spawn_news_2_vehicle(playerid);
				return SendErr(playerid, "Недостаточно госсударственных автомобилей!");
			}

			if(pData[playerid][pFraction] != 10 || pData[playerid][pSubfraction] == 0)
			{
				SendErr(playerid, "Доступно только сотрудникам СМИ!");
				return true;
			}	

			create_vehicle_news_2(playerid, 2);
		}
	}

	return true;
}

stock create_vehicle_news_1(playerid, veh_type)
{
	new 
		random_pos = random(1);

	new 
		c1 = 7,
		c2 = 7;	

	new 
		vehicle_news_1 = CreateVehicle(news_car_model[veh_type], position_spawn_car_news_1[random_pos][0], position_spawn_car_news_1[random_pos][1], position_spawn_car_news_1[random_pos][2], position_spawn_car_news_1[random_pos][3], c1, c2, 600);	

	format(vehicle[vehicle_news_1][cPlate], 20, "н0%dнн", count_news_1_vehicle);
	SetVehicleGosNumberPlate(vehicle_news_1, vehicle[vehicle_news_1][cPlate], "77");

	PutPlayerInVehicleEx(playerid, vehicle_news_1, 0);

	vehicle[vehicle_news_1][cFuel] = transport_config[GetVehicleModel(vehicle_news_1)-400][transport_tank];
	vehicle[vehicle_news_1][cHealth] = 1000.0;
	vehicle[vehicle_news_1][cIsCreated] = true;
	vehicle[vehicle_news_1][consumables_oil] = 1000.0;

	vehicle[vehicle_news_1][cOwnTo] = VEHICLE_NEWS_1;

	vehicle[vehicle_news_1][cLock] = 2;

	vehicle_lock_status(vehicle_news_1, true);

	count_news_1_vehicle--;

	return true;
}

stock create_vehicle_news_2(playerid, veh_type)
{
	new 
		random_pos = random(1);

	new 
		c1 = 7,
		c2 = 7;	

	new 
		vehicle_news_2 = CreateVehicle(news_car_model[veh_type], position_spawn_car_news_2[random_pos][0], position_spawn_car_news_2[random_pos][1], position_spawn_car_news_2[random_pos][2], position_spawn_car_news_2[random_pos][3], c1, c2, 600);	

	format(vehicle[vehicle_news_2][cPlate], 20, "н0%dнн", count_news_2_vehicle);
	SetVehicleGosNumberPlate(vehicle_news_2, vehicle[vehicle_news_2][cPlate], "77");

	PutPlayerInVehicleEx(playerid, vehicle_news_2, 0);

	vehicle[vehicle_news_2][cFuel] = transport_config[GetVehicleModel(vehicle_news_2)-400][transport_tank];
	vehicle[vehicle_news_2][cHealth] = 1000.0;
	vehicle[vehicle_news_2][cIsCreated] = true;
	vehicle[vehicle_news_2][consumables_oil] = 1000.0;

	vehicle[vehicle_news_2][cOwnTo] = VEHICLE_NEWS_2;

	vehicle[vehicle_news_2][cLock] = 2;

	vehicle_lock_status(vehicle_news_2, true);

	count_news_2_vehicle--;

	return true;
}

stock dialog_all_news(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
	    case DIALOG_SELECT_CAR_NEWS_1: 
	    {
	    	if(!response)
	    		return true;

	    	switch(listitem)
	    	{
		    	case 0: return spawn_news_1_veh_start(playerid, 0);
		    	case 1: return spawn_news_1_vehicle(playerid);
		    	case 2: return spawn_news_1_vehicle(playerid);
		    }
	    }
	    case DIALOG_SELECT_CAR_NEWS_2: 
	    {
	    	if(!response)
	    		return true;
	    	
	    	switch(listitem)
	    	{
		    	case 0: return spawn_news_2_veh_start(playerid, 0);
		    	case 1: return spawn_news_2_vehicle(playerid);
		    	case 2: return spawn_news_2_vehicle(playerid);
		    }
	    }
	}



	return true;
}