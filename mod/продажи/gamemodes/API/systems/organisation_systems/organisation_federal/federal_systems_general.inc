static const Float:position_spawn_car_federal[][] =
{
	{513.5136,295.6420,11.9883,89.1490},
	{513.2537,292.6111,11.9884,89.2300},
	{513.3312,289.7008,11.9884,89.2910},
	{513.2019,286.7521,11.9885,90.3049},
	{513.0244,283.6049,11.9884,90.4636},
	{518.1901,278.6401,11.9882,179.5237},
	{521.3685,278.6019,11.9883,179.9676},
	{524.2714,278.6495,11.9882,179.4834},
	{527.3516,278.5743,11.9882,180.1185},
	{530.2845,278.5813,11.9884,179.2961}

};

new fsv_car_model[] =
{
	528, 533, 552
};


stock create_fsm_other_element()
{

	pickup_spawn_car_federal = create_circle_pickup(533.1469,273.6696,12.3440, TRIGGER_LRED);

	CreateDynamic3DTextLabel(""cWH"Автопарк ФСБ\n\
		"cLRED"[Встаньте на пикап]", CWHITE, 533.1469,273.6696,12.3440, 5.0,INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);


	return true;
}


stock spawn_federal_vehicle(playerid)
{
	format(String512, sizeof(String512), "\
    "cGREY"Автомобиль\t"cGREY"Действие\n\
    "cBLUE"1. "cWH"%s\t"cGR"Взять\n\
    "cBLUE"2. "cWH"%s\t"cGR"Взять\n\
    "cBLUE"3. "cWH"%s\t"cGR"Взять\n\
    \t\n\
    "cWH"Доступно всего: \t"cBLUE"%d"cWH" автомобилей", 
    transport_config[fsv_car_model[0]-400][transport_name],
    transport_config[fsv_car_model[1]-400][transport_name],
    transport_config[fsv_car_model[2]-400][transport_name],
    count_federal_vehicle
    );
 	SPD(playerid, DIALOG_SELECT_CAR_FEDERAL, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Выбор автомобиля", String512, !"Выбрать", !"Закрыть"); 

 	return true;
}

stock spawn_federal_veh_start(playerid, type_car)
{
	switch(type_car)
	{
		case 0:
		{
			if(count_federal_vehicle == 0)
			{
				spawn_federal_vehicle(playerid);
				return SendErr(playerid, "Недостаточно госсударственных автомобилей!");
			}

			if(pData[playerid][pFraction] != 12)
			{
				SendErr(playerid, "Доступно только ФСБ!");
				return true;
			}	

			create_vehicle_federal(playerid, 0);
		}
		case 1:
		{
			if(count_federal_vehicle == 0)
			{
				spawn_federal_vehicle(playerid);
				return SendErr(playerid, "Недостаточно госсударственных автомобилей!");
			}

			if(pData[playerid][pFraction] != 12)
			{
				SendErr(playerid, "Доступно только ФСБ!");
				return true;
			}	

			create_vehicle_federal(playerid, 1);
		}
		case 2:
		{
			if(count_federal_vehicle == 0)
			{
				spawn_federal_vehicle(playerid);
				return SendErr(playerid, "Недостаточно госсударственных автомобилей!");
			}

			if(pData[playerid][pFraction] != 12)
			{
				SendErr(playerid, "Доступно только ФСБ!");
				return true;
			}	

			create_vehicle_federal(playerid, 2);
		}
		case 3:
		{
			if(count_federal_vehicle == 0)
			{
				spawn_federal_vehicle(playerid);
				return SendErr(playerid, "Недостаточно госсударственных автомобилей!");
			}

			if(pData[playerid][pFraction] != 12)
			{
				SendErr(playerid, "Доступно только ФСБ!");
				return true;
			}	

			create_vehicle_federal(playerid, 3);
		}
	}

	return true;
}

stock create_vehicle_federal(playerid, veh_type)
{
	new 
		random_pos = random(9);

	new 
		c1 = 133,
		c2 = 133;	

	new 
		vehicle_federal;

	if(fsv_car_model[veh_type] == 552)
	{
		vehicle_federal = CreateVehicle(fsv_car_model[veh_type], 514.7075,243.0430,12.5369,0.7764, c1, c2, 600);	
	}
	else
	{
		vehicle_federal = CreateVehicle(fsv_car_model[veh_type], position_spawn_car_federal[random_pos][0], position_spawn_car_federal[random_pos][1], position_spawn_car_federal[random_pos][2], position_spawn_car_federal[random_pos][3], c1, c2, 600);	
	}

	format(vehicle[vehicle_federal][cPlate], 20, "ф0%dфф", count_federal_vehicle);
	SetVehicleGosNumberPlate(vehicle_federal, vehicle[vehicle_federal][cPlate], "77");

	PutPlayerInVehicleEx(playerid, vehicle_federal, 0);

	vehicle[vehicle_federal][cFuel] = transport_config[GetVehicleModel(vehicle_federal)-400][transport_tank];
	vehicle[vehicle_federal][cHealth] = 1000.0;
	vehicle[vehicle_federal][cIsCreated] = true;
	vehicle[vehicle_federal][consumables_oil] = 1000.0;

	vehicle[vehicle_federal][cOwnTo] = VEHICLE_FEDERALS;

	vehicle[vehicle_federal][cLock] = 2;

	vehicle_lock_status(vehicle_federal, true);

	count_federal_vehicle--;

	return true;
}

stock dialog_all_federal(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
	    case DIALOG_SELECT_CAR_FEDERAL: 
	    {
	    	if(!response)
	    		return true;
	    			    	
	    	switch(listitem)
	    	{
		    	case 0: return spawn_federal_veh_start(playerid, 0);
		    	case 1: return spawn_federal_veh_start(playerid, 1);
		    	case 2: return spawn_federal_veh_start(playerid, 2);
		    	case 3: return spawn_federal_vehicle(playerid);
		    	case 4: return spawn_federal_vehicle(playerid);
		    }
	    }
	}



	return true;
}