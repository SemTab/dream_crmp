
#define CAR_TIME_SPAWN 				180

#define TYPE_CAR		1
#define TYPE_BOAT		2
#define TYPE_PLANE 		3
#define TYPE_MOTO		5
#define TYPE_BYCICLE	6
#define TYPE_RC 		TYPE_CAR | 9
#define TYPE_TRAILER	TYPE_CAR | 10
#define TYPE_TRAM 		TYPE_CAR | 14
#define TYPE_FUN 		TYPE_CAR | 12


#define TYPE_TESLA_1	466

new 
	Text3D:bank_work_text[MAX_VEHICLES] = Text3D:INVALID_3DTEXT_ID;

new 
	start_game_transports[12],
	arend_vehicle_high[5],
	arend_vehicle_medium[5],
	vehicle_bus[6],
	vehicle_hospital[3],
	vehicle_mechanic[17],
	vehicle_fims[30],
	vehicle_visual[18];

new 
	timer_strobocop[MAX_VEHICLES];
new 
	bool:status_strobocop[MAX_VEHICLES];
new 
	count_strobrscop[MAX_VEHICLES];

new 
	count_mafia_1_vehicle = 15,
	count_mafia_2_vehicle = 15,
	count_mafia_3_vehicle = 15;

enum
{
	MECHANIC_BASE_STATION_1 = 0,
	MECHANIC_BASE_STATION_2 = 1,
	MECHANIC_BASE_STATION_3 = 2
}

enum
{
	TRUCKER_BASE_STATION_1 = 0,
	TRUCKER_BASE_STATION_2 = 1,
	TRUCKER_BASE_STATION_3 = 2
}

enum
{
	TAXI_COMPANY_YANDEX = 0,
	TAXI_COMPANY_UBER = 1,
	TAXI_COMPANY_CITY = 2
}

enum
{
	VEHICLE_START_GAME = 30,
	VEHICLE_AREND_HIGH = 31,
	VEHICLE_AREND_MEDIUM = 32,
	VEHICLES_BUS = 33,
	VEHICLES_AUTOSCHOOL = 34,
	VEHICLE_HOSPITAL = 35,
	VEHICLE_MECHANIC_1 = 36,
	VEHICLE_MECHANIC_2 = 37,
	VEHICLE_MECHANIC_3 = 38,
	VEHICLE_AUTOSALON_1 = 39,
	VEHICLE_AUTOSALON_2 = 40,
	VEHICLE_AUTOSALON_3 = 41,
	VEHICLE_YANDEX = 42,
	VEHICLE_UBER = 43,
	VEHICLE_CITY = 44,
	VEHICLE_GOV = 45,
	VEHICLE_FEDERALS = 46,
	VEHICLE_POLICES = 47,
	VEHICLE_NEWS_1 = 48,
	VEHICLE_NEWS_2 = 49,
	VEHICLE_HOSPITAL_1 = 50,
	VEHICLE_HOSPITAL_2 = 51,
	VEHICLE_ARMY_1 = 52,
	VEHICLE_ARMY_VERT = 53,
	VEHICLE_TRUCKER_1 = 54,
	VEHICLE_TRUCKER_2 = 55,
	VEHICLE_TRUCKER_3 = 56,
	VEHICLE_SNOW_WORK = 57,
	VEHICLE_MAFIA_1 = 58,
	VEHICLE_MAFIA_2 = 59,
	VEHICLE_MAFIA_3 = 60,
	VEHICLE_FIRE = 61,
	VEHICLE_TRASH_WORK = 62,
	VEHICLE_BANK_WORK = 63
}

enum cVeh
{
	bool:cIsCreated,
	cAdvancedSpeed,
	cWear,
	cFuelType_native,
	cFuelType,
	cGydro,
	cPaintJob,
	cRenter,
	cSpeedLimit,
	cRentPrice,
	cOwnTo,
	bool:cIsRent,
	cRang,
	Text3D:cLabel,
	cPlate[30],
	cColor1,
	cColor2,
	Float:cHealth,
	Float:cFuel,
	Float:cEnergy,
	cEngine,
	cLock,
	cLight,
	Float:cMileage,
	cOwner,
	cPrice,

	Float:consumables_oil,
	Float:consumables_brake,
	Float:consumables_belt,
	Float:consumables_starter,
	Float:consumables_generator,
	Float:consumables_forsunki,
	Float:consumables_fuel,
	Float:consumables_candles,

	Float:parking_x,
	Float:parking_y,
	Float:parking_z,
	Float:parking_a,
	parking_garage,
	parking_hotel,
	parking_police,
	shtraf_car,
	consumables_candles_date[32],
	consumables_oil_date[32],
	consumables_brake_date[32],
	consumables_belt_date[32],
	consumables_starter_date[32],
	consumables_generator_date[32],
	consumables_forsunki_date[32],
	consumables_fuel_date[32],

	carMech,
	carMechFuel,
	Text3D:cMechText,
	car_attached,
	Float:cGeneratorEnergy,
	Float:cBatteryEnergy,
	buy_date_car[32],
	Text3D:cLabelTaxi,
	vehicle_sound_id,
	cPlateRegion[30],
	cPlateType,
	vehicle_rent_playerid,
	carMechOil,
	vehicle_driver,
	respawn_time,
	respawn_timer,
	cWater,
	v_vehicle,
	vehicle_prize,
	vehicle_world,
	cFamilyOwner
};

new vehicle[MAX_VEHICLES][cVeh];

new def_vehicle[cVeh] =
{
	false,								// bool:cIsCreated,
	0,									//	cAdvancedSpeed,
	100,								//	cWear,
	1,									//	cFuelType_native,
	1,									//	cFuelType,
	-1,									//	cGydro,
	3,									//	cPaintJob,
	INVALID_PLAYER_ID,					//	cRenter,
	0,									//	cSpeedLimit,
	999,								//	cRentPrice,
	0,									//	cOwnTo,
	false,								//	bool:cIsRent,
	0,									//	cRang,
	Text3D:INVALID_3DTEXT_ID,			//	Text3D:cLabel,
	"Plate",							//	cPlate[30],
	0,									//	cColor1,
	0,									//	cColor2,
	1000.0,								//  Float:cHealth,
	30.0,								//	Float:cFuel,
	1000.0,								//  Float:cEnergy,
	false,								//	bool:cEngine,
	false,								//	bool:cLock,
	false,								//	bool:cLight,
	0.0,								//	Float:cMileage,
	INVALID_PLAYER_ID,					//	cOwner,
	6000000,							//  cPrice

	100.0,								// Oil
	100.0,								// Brake
	100.0,								// Belt
	100.0,								// Starter
	100.0,								// Generator
	100.0,								// Forsunki
	100.0,								// Fuel
	100.0,	

	0.0,								// ParkingX
	0.0,								// ParkingY
	0.0,								// ParkingZ	
	0.0,								// ParkingA

	0,									//	parking_garage,
	0,									//	parking_hotel,
	0,									//	parking_police,
	0,									// 	shtraf_car

	"None",								// consumables_candles_date
	"None",								// consumables_candles_date
	"None",								// consumables_candles_date
	"None",								// consumables_candles_date
	"None",								// consumables_candles_date
	"None",								// consumables_candles_date
	"None",								// consumables_candles_date	
	"None",								// consumables_candles_date

	0,									// 	carMech
	0,									//  carMechFuel
	Text3D:INVALID_3DTEXT_ID,			//  cMechText
	-1,
	100.0,								// cGeneratorEnergy
	100.0,								// cBatteryEnergy
	"None",								// buy_date_car
	Text3D:INVALID_3DTEXT_ID,
	-1,
	"None",
	0,
	-1,
	0,
	INVALID_PLAYER_ID,
	0,
	INVALID_TIMER_ID,
	1500,
	INVALID_VEHICLE_ID,
	-1,
	0,
	-1

};

#define MODEL 	1

stock GetMaxSeat(vehicleid)
{
    new 
    	model = GetVehicleModel(vehicleid);

	switch(model)
	{
		case 596..598,427,490,560: return 4;
		case 599,497,528,541,603: return 2;
		case 409,413,551, 579, 580, 507, 405, 445, 411: return 4;
		case 426,482,487: return 4;

	}
	return -1;
}

stock get_fuel_max_veh(vehicleid)
{
    new 
    	model = GetVehicleModel(vehicleid);

    switch(model)
    {
        case 400:return 77;
        case 401:return 78;
        case 402:return 75;
        case 403:return 90;
        case 404:return 51;
        case 405:return 65;
        case 406..408:return 100;
        case 409:return 66;
        case 410:return 45;
        case 411:return 80;
        case 412:return 55;
        case 413:return 80;
        case 414:return 70;
        case 415:return 60;
        case 416:return 80;
        case 417:return 250;
        case 418:return 50;
        case 419:return 55;
        case 420:return 60;
        case 421:return 60;
        case 422:return 50;
        case 423:return 51;
        case 424:return 60;
        case 425:return 250;
        case 426:return 60;
        case 427..428:return 80;
        case 429:return 60;
        case 430:return 150;
        case 431:return 80;
        case 432:return 50;
        case 433:return 80;
        case 434:return 55;
        case 436:return 50;
        case 437:return 80;
        case 438:return 60;
        case 439:return 60;
        case 440:return 65;
        case 442:return 50;
        case 443:return 80;
        case 444:return 50;
        case 445:return 60;
        case 446:return 150;
        case 447:return 250;
        case 448:return 35;
        case 451:return 80;
        case 452..454:return 150;
        case 455..456:return 80;
        case 457:return 40;
        case 458:return 50;
        case 459:return 80;
        case 460:return 1;
        case 461..463:return 70;
        case 466: return 85;
        case 467: return 50;
        case 468:return 70;
        case 469:return 250;
        case 470:return 80;
        case 471:return 40;
        case 472..473:return 150;
        case 474..475:return 55;
        case 476:return 250;
        case 477:return 60;
        case 478:return 55;
        case 479:return 49;
        case 480:return 60;
        case 482..483:return 70;
        case 484:return 150;
        case 485:return 50;
        case 486:return 80;
        case 487..488:return 250;
        case 489..490:return 60;
        case 491..492:return 50;
        case 493:return 150;
        case 494..495:return 75;
        case 496:return 70;
        case 497:return 250;
        case 498..499:return 60;
        case 500:return 60;
        case 502..504:return 70;
        case 505:return 65;
        case 506:return 80;
        case 507:return 50;
        case 508:return 75;
	    case 511..513:return 250;
	    case 514..515:return 80;
	    case 516..518:return 50;
	    case 519..520:return 250;
	    case 521..523:return 60;
	    case 524:return 80;
	    case 525:return 80;
	    case 526..527:return 50;
	    case 528:return 72;
	    case 529:return 51;
	    case 530:return 45;
	    case 531:return 73;
	    case 532:return 93;
	    case 533:return 64;
	    case 534:return 55;
	    case 535..536:return 65;
	    case 539:return 51;
	    case 540:return 58;
	    case 541:return 78;
	    case 542:return 61;
	    case 543:return 54;
	    case 544:return 86;
	    case 545:return 75;
	    case 546:return 52;
	    case 547:return 52;
	    case 548:return 250;
	    case 549..551:return 50;
	    case 552:return 62;
	    case 553:return 250;
	    case 554:return 60;
	    case 555:return 72;
	    case 556..557:return 80;
	    case 558:return 50;
	    case 559..560:return 70;
	    case 561:return 53;
	    case 562:return 70;
	    case 563:return 250;
	    case 565:return 77;
	    case 566:return 45;
	    case 567:return 53;
	    case 568:return 62;
	    case 571:return 40;
	    case 572:return 55;
	    case 573:return 80;
	    case 574:return 43;
	    case 575:return 65;
	    case 576:return 51;
	    case 577:return 250;
	    case 578:return 75;
	    case 579:return 70;
	    case 580:return 65;
	    case 581:return 40;
	    case 582:return 55;
	    case 583:return 40;
	    case 585:return 50;
	    case 586:return 40;
	    case 587:return 66;
	    case 588:return 50;
	    case 589:return 50;
	    case 592..593:return 250;
	    case 595:return 150;
	    case 596..599:return 61;
	    case 600:return 43;
	    case 601:return 80;
	    case 602..603:return 60;
	    case 604..605:return 50;
	    case 609:return 65;
	    default:return 50;
	}
    return 0;
}

stock GetVehicleName(vehicleid, model = false)
{
	new
		car,
		string[15];

	car = (!model) ? (GetVehicleModel(vehicleid) - 400) : (vehicleid - 400);

    format(string, 15, "%s", veh_name[car]);

    return string;
}

stock GetVehicleTypes(vehicleid)
{
	new 
		name[21];

	switch(GetVehicleModel(vehicleid))
	{
		case TYPE_TESLA_1: name = "Электрический";
		default: name = "ДВС";
	}
	return name;
}


stock CreateVehicleEx(vehicletype, Float:x, Float:y, Float:z, Float:rotation, color1, color2, respawn_delay, addsiren = 0)
{



	new vehicleid = CreateVehicle(vehicletype, x, y, z, rotation, color1, color2, respawn_delay, addsiren);

	Iter_Add(Vehicles, vehicleid);
	ResetVehicleHandling(vehicleid);

	memcpy(vehicle[vehicleid], def_vehicle, 0, sizeof(def_vehicle)*4, sizeof(vehicle[]));

	ChangeVehiclePaintjob(vehicleid, vehicle[vehicleid][cPaintJob]);


    new engine, lights, alarm, doors, bonnet, boot, objective;
    GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
	SetVehicleParamsEx(vehicleid, false, false, alarm, false, bonnet, boot, objective);
	

	SetVehicleEngInert(vehicleid, transport_config[vehicletype-400][transport_engine_inertion]);
	SetVehicleMaxSpeed(vehicleid, transport_config[vehicletype-400][transport_handling_speed]);
	SetVehicleMass(vehicleid, transport_config[vehicletype-400][transport_handling_mass]);
	SetVehicleMassTurn(vehicleid, transport_config[vehicletype-400][transport_handling_mass_turn]);

	SetVehicleAcceleration(vehicleid, transport_config[vehicletype-400][transport_handling_acceleration]);
	SetVehicleGear(vehicleid, transport_config[vehicletype-400][transport_handling_gear]);
	SetVehicleBrakeCoef(vehicleid, transport_config[vehicletype-400][transport_brake_deceleration]);
	SetVehicleTractionCoef(vehicleid, transport_config[vehicletype-400][transport_traction_multiplier]);
	SetVehicleTractionLoss(vehicleid, transport_config[vehicletype-400][transport_traction_loss]);


	SetVehicleTractionBias(vehicleid, transport_config[vehicletype-400][transport_traction_bias]);
	SetVehicleSuspensionBias(vehicleid, transport_config[vehicletype-400][transport_suspension_bias]);
	SetVehicleWheelSize(vehicleid, transport_config[vehicletype-400][transport_wheel_size]);
	SetVehicleSuspensionLower(vehicleid, transport_config[vehicletype-400][transport_suspension_limit]);
	SetVehicleTractionLoss(vehicleid, transport_config[vehicletype-400][transport_wheel_angle]);


	if(transport_config[vehicletype-400][transport_class] == 1)
	{
		SetVehicleLightsColors(vehicleid, 251, 252, 146);
	}
	if(transport_config[vehicletype-400][transport_class] == 2)
	{
		SetVehicleLightsColors(vehicleid, 242, 242, 218);
	}
	if(transport_config[vehicletype-400][transport_class] == 3)
	{
		SetVehicleLightsColors(vehicleid, 255, 255, 255);
	}

	if(vehicle[vehicleid][cPlateType] == NUMBER_REGION_RU)
	{
		format(vehicle[vehicleid][cPlate], 12, vehicle[vehicleid][cPlate]);
		format(vehicle[vehicleid][cPlateRegion], 12, vehicle[vehicleid][cPlateRegion]);

		SetVehicleRuNumberPlate(vehicleid, vehicle[vehicleid][cPlate], vehicle[vehicleid][cPlateRegion]);
	}
	else if(vehicle[vehicleid][cPlateType] == NUMBER_REGION_KZ)
	{
		format(vehicle[vehicleid][cPlate], 12, vehicle[vehicleid][cPlate]);
		format(vehicle[vehicleid][cPlateRegion], 12, vehicle[vehicleid][cPlateRegion]);
		SetVehicleKzNumberPlate(vehicleid, vehicle[vehicleid][cPlate], vehicle[vehicleid][cPlateRegion]);
	}
	else if(vehicle[vehicleid][cPlateType] == NUMBER_REGION_BY)
	{
		format(vehicle[vehicleid][cPlate], 12, vehicle[vehicleid][cPlate]);
		format(vehicle[vehicleid][cPlateRegion], 12, vehicle[vehicleid][cPlateRegion]);
		SetVehicleBuNumberPlate(vehicleid, vehicle[vehicleid][cPlate]);
	}
	else if(vehicle[vehicleid][cPlateType] == NUMBER_REGION_UA)
	{
		format(vehicle[vehicleid][cPlate], 12, vehicle[vehicleid][cPlate]);
		format(vehicle[vehicleid][cPlateRegion], 12, vehicle[vehicleid][cPlateRegion]);
		SetVehicleUaNumberPlate(vehicleid, vehicle[vehicleid][cPlate]);
	}
	else if(vehicle[vehicleid][cPlateType] == 0)
	{
		SetVehicleNoPlateNumberPlate(vehicleid, "-----", "---");
	}

	return vehicleid;
}
#if defined _ALS_CreateVehicle
    #undef CreateVehicle
#else
    #define _ALS_CreateVehicle
#endif
#define CreateVehicle CreateVehicleEx

stock ExDestroyVehicle(vehicleid)
{
	new
		own = vehicle[vehicleid][cOwnTo];

	switch(own)
	{	
		case VEHICLE_GOV:
		{
			count_gov_vehicle++;
		}
		case VEHICLE_FEDERALS:
		{
			count_federal_vehicle++;
		}
		case VEHICLE_POLICES:
		{
			count_police_vehicle++;
		}
		case VEHICLE_MAFIA_1:
		{
			count_mafia_1_vehicle++;
		}	
		case VEHICLE_MAFIA_2:
		{
			count_mafia_2_vehicle++;
		}
		case VEHICLE_MAFIA_3:
		{	
			count_mafia_3_vehicle++;
		}
		case VEHICLE_NEWS_1:
		{
			count_news_1_vehicle++;
		}
		case VEHICLE_NEWS_2:
		{
			count_news_2_vehicle++;
		}
		case VEHICLE_HOSPITAL_1:
		{
			count_hospital_1_vehicle++;
		}
		case VEHICLE_HOSPITAL_2:
		{
			count_hospital_2_vehicle++;
		}
		case VEHICLE_AUTOSALON_1:
		{
			autosalon_count_rent_car[0]++;
		}
		case VEHICLE_AUTOSALON_2:
		{
			autosalon_count_rent_car[1]++;
		}
		case VEHICLE_AUTOSALON_3:
		{
			autosalon_count_rent_car[2]++;
		}
		case VEHICLE_ARMY_1:
		{
			count_army_vehicle++;
		}
		case VEHICLE_ARMY_VERT:
		{
			count_army_vert_active++;
		}
		case VEHICLE_YANDEX, VEHICLE_UBER, VEHICLE_CITY:
		{
			DestroyDynamic3DTextLabel(vehicle[vehicleid][cLabelTaxi]);
			vehicle[vehicleid][cLabelTaxi] = Text3D:INVALID_3DTEXT_ID;	
		}
		case VEHICLES_BUS:
		{
			DestroyDynamic3DTextLabel(vehicle[vehicleid][cLabelTaxi]);
			vehicle[vehicleid][cLabelTaxi] = Text3D:INVALID_3DTEXT_ID;				
		}
		case VEHICLE_MECHANIC_1:
		{
			DestroyDynamic3DTextLabel(vehicle[vehicleid][cMechText]); 
			vehicle[vehicleid][cMechText] = Text3D:INVALID_3DTEXT_ID;
		}
		case VEHICLE_MECHANIC_2:
		{
			DestroyDynamic3DTextLabel(vehicle[vehicleid][cMechText]); 
			vehicle[vehicleid][cMechText] = Text3D:INVALID_3DTEXT_ID;
		}
		case VEHICLE_MECHANIC_3:
		{
			DestroyDynamic3DTextLabel(vehicle[vehicleid][cMechText]); 
			vehicle[vehicleid][cMechText] = Text3D:INVALID_3DTEXT_ID;
		}
		case VEHICLE_FIRE:
		{
			DestroyDynamic3DTextLabel(vehicle[vehicleid][cMechText]);
			vehicle[vehicleid][cMechText] = Text3D:INVALID_3DTEXT_ID;				
		}
		case VEHICLE_TRUCKER_1:
		{

		}
		case VEHICLE_TRUCKER_2:
		{

		}
		case VEHICLE_TRUCKER_3:
		{

		}
		case VEHICLE_TRASH_WORK:
		{
			if(trash_text[vehicleid] != Text3D:INVALID_3DTEXT_ID) 
			{
				DestroyDynamic3DTextLabelEx(trash_text[vehicleid]);
			}
			DestroyDynamic3DTextLabelEx(trash_text[vehicleid]);
			trash_text[vehicleid] = Text3D:INVALID_3DTEXT_ID;
		}
	}	


	//destroy_family_veh(vehicleid);

	memcpy(vehicle[vehicleid], def_vehicle, 0, sizeof(def_vehicle)*4, sizeof(vehicle[]));
	
	delete_vehicle_load_info(vehicleid);

	DestroyDynamic3DTextLabel(bank_work_text[vehicleid]);
	DestroyDynamic3DTextLabel(vehicle[vehicleid][cLabelTaxi]);
	DestroyDynamic3DTextLabel(vehicle[vehicleid][cMechText]); 
	DestroyDynamic3DTextLabel(vehicle[vehicleid][cLabel]); 

	bank_work_text[vehicleid] = Text3D:INVALID_3DTEXT_ID;
	vehicle[vehicleid][cMechText] = Text3D:INVALID_3DTEXT_ID;
	vehicle[vehicleid][cLabel] = Text3D:INVALID_3DTEXT_ID;


	Iter_Remove(Vehicles, vehicleid);
	return DestroyVehicle(vehicleid);
}
#if defined _ALS_DestroyVehicle
    #undef DestroyVehicle
#else
    #define _ALS_DestroyVehicle
#endif
#define DestroyVehicle ExDestroyVehicle

stock vehicle_engine_status(carid, status)
{
	if(carid == INVALID_VEHICLE_ID) return true;

	vehicle[carid][cEngine] = status;
    new engine, lights, alarm, doors, bonnet, boot, objective;
    GetVehicleParamsEx(carid, engine, lights, alarm, doors, bonnet, boot, objective);
	SetVehicleParamsEx(carid, status, lights, alarm, doors, bonnet, boot, objective);

	foreach(new i: logged_players)
	{
		if(GetPlayerState(i) == PLAYER_STATE_DRIVER)
		{
			if(GetPlayerVehicleID(i) == carid)
			{
			    new 
			    	Float:car_health;
				GetVehicleHealth(carid, car_health);

			    if(car_health > 150.0)
			    {
					if(engine == 1)
					{

						new mese[90];
						format(mese,sizeof(mese),"заглушил(а) двигатель «%s»", transport_config[GetVehicleModel(carid)-400][transport_name]);
						MeAction(i ,mese);

					}
					else
					{
						new mese[90];
						format(mese,sizeof(mese),"завел(а) двигатель «%s»", transport_config[GetVehicleModel(carid)-400][transport_name]);
						MeAction(i ,mese);
					}
				}


				update_speed_engine_car(i, status);
			}
		}
	}

	if(GetVehicleModel(carid) == TYPE_TESLA_1)
	{
		vehicle_params_textdraw_update(vehicle[carid][vehicle_driver], vehicle[carid][cEnergy]);
	}
	else
	{
		vehicle_params_textdraw_update(vehicle[carid][vehicle_driver], vehicle[carid][cFuel]);

	}
	return true;
}

stock vehicle_light_status(carid, status)
{
	if(carid == INVALID_VEHICLE_ID) return true;
	vehicle[carid][cLight] = status;
    new engine, lights, alarm, doors, bonnet, boot, objective;
    GetVehicleParamsEx(carid, engine, lights, alarm, doors, bonnet, boot, objective);
	SetVehicleParamsEx(carid, engine, status, alarm, doors, bonnet, boot, objective);


	foreach(new i: logged_players)
	{
		if(GetPlayerState(i) == PLAYER_STATE_DRIVER)
		{
			if(GetPlayerVehicleID(i) == carid)
			{
				update_speed_light_car(i, status);
			}
		}
	}


	if(GetVehicleModel(carid) == TYPE_TESLA_1)
	{
		vehicle_params_textdraw_update(vehicle[carid][vehicle_driver], vehicle[carid][cEnergy]);
	}
	else
	{
		vehicle_params_textdraw_update(vehicle[carid][vehicle_driver], vehicle[carid][cFuel]);

	}
	return true;
}

stock vehicle_lock_status(carid, status)
{
	if(carid == INVALID_VEHICLE_ID) return true;
	vehicle[carid][cLock] = status;
    new engine, lights, alarm, doors, bonnet, boot, objective;
    GetVehicleParamsEx(carid, engine, lights, alarm, doors, bonnet, boot, objective);
	SetVehicleParamsEx(carid, engine, lights, alarm, status, bonnet, boot, objective);

	foreach(new i: logged_players)
	{
		if(GetPlayerState(i) == PLAYER_STATE_DRIVER)
		{
			if(GetPlayerVehicleID(i) == carid)
			{
				update_speed_lock_car(i, status);
			}
		}
	}


	if(GetVehicleModel(carid) == TYPE_TESLA_1)
	{
		vehicle_params_textdraw_update(vehicle[carid][vehicle_driver], vehicle[carid][cEnergy]);
	}
	else
	{
		vehicle_params_textdraw_update(vehicle[carid][vehicle_driver], vehicle[carid][cFuel]);

	}

	return true;
}


stock vehicle_params_textdraw_update(playerid, Float:benz)
{
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
  		update_fuel_speed_player(playerid, benz);
	}
	return true;
}

stock vehicle_speed_textdraw_update(i)
{
	new 	
		carid = GetPlayerVehicleID(i);

	update_speed_player(i, get_vehicle_speed(carid));

	return true;
}

forward player_vehicle_timer(i, carid);
public player_vehicle_timer(i, carid)
{

	new time = GetTickCount();

	KillTimer(pTemp[i][vehicle_speed_timer]);

	if(!IsPlayerConnected(i) || carid == INVALID_VEHICLE_ID) 
		return true;

	vehicle[carid][cMileage] += (float(get_vehicle_speed(carid))/25.0)/100;

	if(pData[i][pSettings][10] == 1)
	{

		update_dist_speed_player(i, vehicle[carid][cMileage]);
		update_speed_player(i, get_vehicle_speed(carid));


	    new 
	    	Float:health_vehicle_t;

	    GetVehicleHealth(carid, health_vehicle_t);
	    update_hp_speed_player(i, health_vehicle_t);

		new 
			speed_update_time;
		if(pData[i][pSettings][6] == 1)
		{
			speed_update_time = 850;
		}
		else
		{
			speed_update_time = 1050;
		}

	    pTemp[i][vehicle_speed_timer] = SetTimerEx("player_vehicle_timer", speed_update_time, false, "ii", i, carid);
	}

    return true;
}

stock player_vehicle_enter(i, carid)
{
	new time = GetTickCount();

	new engine, lights, alarm, doors, bonnet, boot, objective;


	SendInf(i,"Чтобы завести транспорт, нажмите "cORANGE"'L.CTRL'"cWH" или же введите команду: "cORANGE"/en");
	SendInf(i,"Для управления фарами транспорта используйте "cORANGE"клавишу 'N'");

	EROM(i, 4, (engine? "Заглушить автомобиль" : "Завести автомобиль"), 6, "/en", ">>");

	GetVehicleParamsEx(carid, engine, lights, alarm, doors, bonnet, boot, objective);

	if(doors == 1 && GetPVarIntNew(i, "first_enter_veh") == 0)
	{
		SendErr(i, "Транспортное средство закрыто! Открыть можно с помощью команды /lock!");
	    TogglePlayerControllable(i, false);
	    TogglePlayerControllable(i, true);
		return RemovePlayerFromVehicleEx(i);
	}

	DeletePVarNew(i, "first_enter_veh");

	player_vehicle[i] = carid;

	vehicle[carid][vehicle_driver] = i;

	new
		own = vehicle[carid][cOwnTo];


	if(!pData[i][pLicenses][LIC_DRIVING] && own != VEHICLE_START_GAME && !GetPVarIntNew(i, "autoschool_type"))
	{
		RemovePlayerFromVehicleEx(i);
		SendErr(i, "У вас отсутствует лицензия на управления транспортом!");
		SendErr(i, "Получить лицензию можно в автошколе: /gps - Общественные Места - Автошкола");
		return true;
	}

	if(pData[i][pSettings][10] == 1)
	{

		/*if(GetVehicleModel(carid) == 462)
			return SendErr(i, "Спидометр не будет отображаться на мопеде!");*/

		/*create_player_speed(i);	

		show_speed_player(i);

		PlayerTextDrawShow(i, player_speed_car[0][i]);
		PlayerTextDrawShow(i, player_speed_car[1][i]);
		PlayerTextDrawShow(i, player_speed_car[2][i]);
		PlayerTextDrawShow(i, player_speed_car[3][i]);
		PlayerTextDrawShow(i, player_speed_car[4][i]);
		PlayerTextDrawShow(i, player_speed_car[5][i]);
		PlayerTextDrawShow(i, player_speed_car[6][i]);
		PlayerTextDrawShow(i, player_speed_car[7][i]);
		PlayerTextDrawShow(i, player_speed_car[8][i]);
		PlayerTextDrawShow(i, player_speed_car[9][i]);
		PlayerTextDrawShow(i, player_speed_car[10][i]);

	    new 
	    	Float:health_vehicle_t;

	    GetVehicleHealth(carid, health_vehicle_t);

		if(GetVehicleModel(carid) == TYPE_TESLA_1)
		{
			PlayerTextDrawSetString(i, player_speed_car[10][i], "brilliantspeed:fuel_energy");
			PlayerTextDrawShow(i, player_speed_car[10][i]);
			vehicle_params_textdraw_update(i, vehicle[carid][cEnergy]);
		}
		else
		{
			PlayerTextDrawSetString(i, player_speed_car[10][i], "brilliantspeed:fuel");
			PlayerTextDrawShow(i, player_speed_car[10][i]);
			vehicle_params_textdraw_update(i, vehicle[carid][cFuel]);

		}*/

	    GetVehicleParamsEx(carid, engine, lights, alarm, doors, bonnet, boot, objective);

		update_speed_lock_car(i, doors);
		update_speed_light_car(i, lights);
		update_speed_engine_car(i, engine);


		vehicle_engine_status(i, engine);

		update_hp_speed_player(i, vehicle[carid][cHealth]);
		update_dist_speed_player(i, vehicle[carid][cMileage]);
		update_speed_player(i, get_vehicle_speed(carid));

		vehicle_params_textdraw_update(i, vehicle[carid][cFuel]);
	}

	/*switch(own)
	{
		case VEHICLE_START_GAME:
		{
			if(pTemp[i][rent_car] != carid)
			{
				vehicle_engine_status(carid, true);
				KillTimer(pTemp[i][vehicle_speed_timer]);
				
				hide_speed_player(i);

				PlayerTextDrawHide(i, player_speed_car[0][i]);
				PlayerTextDrawHide(i, player_speed_car[1][i]);
				PlayerTextDrawHide(i, player_speed_car[2][i]);
				PlayerTextDrawHide(i, player_speed_car[3][i]);
				PlayerTextDrawHide(i, player_speed_car[4][i]);
				PlayerTextDrawHide(i, player_speed_car[5][i]);		
				PlayerTextDrawHide(i, player_speed_car[6][i]);
				PlayerTextDrawHide(i, player_speed_car[7][i]);
				PlayerTextDrawHide(i, player_speed_car[8][i]);		
				PlayerTextDrawHide(i, player_speed_car[9][i]);
				PlayerTextDrawHide(i, player_speed_car[10][i]);

				PlayerTextDrawDestroy(i, player_speed_car[0][i]);
				PlayerTextDrawDestroy(i, player_speed_car[1][i]);
				PlayerTextDrawDestroy(i, player_speed_car[2][i]);
				PlayerTextDrawDestroy(i, player_speed_car[3][i]);
				PlayerTextDrawDestroy(i, player_speed_car[4][i]);
				PlayerTextDrawDestroy(i, player_speed_car[5][i]);
				PlayerTextDrawDestroy(i, player_speed_car[6][i]);
				PlayerTextDrawDestroy(i, player_speed_car[7][i]);
				PlayerTextDrawDestroy(i, player_speed_car[8][i]);
				PlayerTextDrawDestroy(i, player_speed_car[9][i]);
				PlayerTextDrawDestroy(i, player_speed_car[10][i]);

				SendErr(i,"Вы не арендуете данное транспортное средство!");
				return RemovePlayerFromVehicleEx(i);				
			}
			else
			{
				vehicle_engine_status(carid, true);
				KillTimer(pTemp[i][vehicle_speed_timer]);
				
				hide_speed_player(i);

				PlayerTextDrawHide(i, player_speed_car[0][i]);
				PlayerTextDrawHide(i, player_speed_car[1][i]);
				PlayerTextDrawHide(i, player_speed_car[2][i]);
				PlayerTextDrawHide(i, player_speed_car[3][i]);
				PlayerTextDrawHide(i, player_speed_car[4][i]);
				PlayerTextDrawHide(i, player_speed_car[5][i]);		
				PlayerTextDrawHide(i, player_speed_car[6][i]);
				PlayerTextDrawHide(i, player_speed_car[7][i]);
				PlayerTextDrawHide(i, player_speed_car[8][i]);		
				PlayerTextDrawHide(i, player_speed_car[9][i]);
				PlayerTextDrawHide(i, player_speed_car[10][i]);

				PlayerTextDrawDestroy(i, player_speed_car[0][i]);
				PlayerTextDrawDestroy(i, player_speed_car[1][i]);
				PlayerTextDrawDestroy(i, player_speed_car[2][i]);
				PlayerTextDrawDestroy(i, player_speed_car[3][i]);
				PlayerTextDrawDestroy(i, player_speed_car[4][i]);
				PlayerTextDrawDestroy(i, player_speed_car[5][i]);
				PlayerTextDrawDestroy(i, player_speed_car[6][i]);
				PlayerTextDrawDestroy(i, player_speed_car[7][i]);
				PlayerTextDrawDestroy(i, player_speed_car[8][i]);
				PlayerTextDrawDestroy(i, player_speed_car[9][i]);
				PlayerTextDrawDestroy(i, player_speed_car[10][i]);

				pTemp[i][rent_car_spawn_timer] = INVALID_TIMER_ID;
				rent_update_timer(i);

				return veh_timer_ex(i, carid);
			}

		}
		case VEHICLES_AUTOSCHOOL:
		{
			if(!GetPVarIntNew(i, "autoschool_type") || GetPVarIntNew(i, "autoschool_type") != get_vehicle_type(carid))
			{
				SendErr(i, "Данный транспорт предназначен для сдачи экзамена");
				return RemovePlayerFromVehicleEx(i);
			}
			SendInf(i, "Не выходите из транспорта, иначе Вам придется начинать всё с начала");
			DisablePlayerCheckpoint(i);
			autoschool_route(i, carid, 0);

			return veh_timer_ex(i, carid);
		}
		case VEHICLE_HOSPITAL:
		{
			if(pData[i][pFraction] != 2)
			{ 
				SendErr(i,"Вы не являетесь работником мед.персонала!");
				return RemovePlayerFromVehicleEx(i);
			}
			return veh_timer_ex(i, carid);

		}
		case VEHICLE_MECHANIC_1:
		{
			if(pData[i][pMech] != 0 || pData[i][pMechRank] == 0)
			{ 
				SendErr(i,"Вы не являетесь сотрудником СТО!");
				return RemovePlayerFromVehicleEx(i);
			}		
			else
			{
				SendInf(i,"Заправить машину клиента - /refill");
				SendInf(i,"Починить машину клиента - /repair");
				SendInf(i,"Взять транспорт на буксировку - /tow, аналогично и снять с буксировки");
					
				rent_update_timer(i);
				pTemp[i][rent_car_spawn_timer] = INVALID_TIMER_ID;

				return veh_timer_ex(i, carid);
			}

		}

		case VEHICLE_MECHANIC_2:
		{
			if(pData[i][pMech] != 1 || pData[i][pMechRank] == 0)
			{ 
				SendErr(i,"Вы не являетесь сотрудником СТО!");
				return RemovePlayerFromVehicleEx(i);
			}		
			else
			{
				SendInf(i,"Заправить машину клиента - /refill");
				SendInf(i,"Починить машину клиента - /repair");
				SendInf(i,"Взять транспорт на буксировку - /tow, аналогично и снять с буксировки");
					
				rent_update_timer(i);
				pTemp[i][rent_car_spawn_timer] = INVALID_TIMER_ID;
				return veh_timer_ex(i, carid);
			}

		}

		case VEHICLE_MECHANIC_3:
		{
			if(pData[i][pMech] != 2 || pData[i][pMechRank] == 0)
			{ 
				SendErr(i,"Вы не являетесь сотрудником СТО!");
				return RemovePlayerFromVehicleEx(i);
			}		
			else
			{
				SendInf(i,"Заправить машину клиента - /refill");
				SendInf(i,"Починить машину клиента - /repair");
				SendInf(i,"Взять транспорт на буксировку - /tow, аналогично и снять с буксировки");

				rent_update_timer(i);
				pTemp[i][rent_car_spawn_timer] = INVALID_TIMER_ID;
				return veh_timer_ex(i, carid);
			}


		}
		case VEHICLE_YANDEX:
		{
			if(pData[i][pTaxi] != TAXI_COMPANY_YANDEX)
			{ 
				SendErr(i,"Вы не являетесь сотрудником ЯндексGO!");
				return RemovePlayerFromVehicleEx(i);
			}
			else
			{
				rent_update_timer(i);
				pTemp[i][rent_car_spawn_timer] = INVALID_TIMER_ID;
				return veh_timer_ex(i, carid);
			}
		}
		case VEHICLE_UBER:
		{
			if(pData[i][pTaxi] != TAXI_COMPANY_UBER)
			{ 
				SendErr(i,"Вы не являетесь сотрудником UBER!");
				return RemovePlayerFromVehicleEx(i);
			}
			else
			{
				rent_update_timer(i);
				pTemp[i][rent_car_spawn_timer] = INVALID_TIMER_ID;
				return veh_timer_ex(i, carid);
			}
		}
		case VEHICLE_CITY:
		{
			if(pData[i][pTaxi] != TAXI_COMPANY_CITY)
			{ 
				SendErr(i,"Вы не являетесь сотрудником СитиМобил!");
				return RemovePlayerFromVehicleEx(i);	
			}
			else
			{
				rent_update_timer(i);
				pTemp[i][rent_car_spawn_timer] = INVALID_TIMER_ID;
				return veh_timer_ex(i, carid);		
			}
		}
		case VEHICLE_GOV:
		{
			if(pData[i][pFraction] != 11)
			{
				SendErr(i,"Вы не являетесь сотрудником Правительства!");
				return RemovePlayerFromVehicleEx(i);	
			}
			else
			{
				KillTimer(vehicle[carid][respawn_timer]);
				vehicle[carid][respawn_timer] = INVALID_TIMER_ID;	
				return veh_timer_ex(i, carid);		
			}
		}
		case VEHICLE_FEDERALS:
		{
			if(pData[i][pFraction] != 12)
			{
				SendErr(i,"Вы не являетесь сотрудником ФСБ!");
				return RemovePlayerFromVehicleEx(i);				
			}
			else
			{
				KillTimer(vehicle[carid][respawn_timer]);
				vehicle[carid][respawn_timer] = INVALID_TIMER_ID;	
				return veh_timer_ex(i, carid);	
			}
		}
		case VEHICLE_POLICES:
		{
			if(!IsACop(i))
			{
				SendErr(i,"Вы не являетесь сотрудником Полиции!");
				return RemovePlayerFromVehicleEx(i);	
			}
			else
			{
				KillTimer(vehicle[carid][respawn_timer]);
				vehicle[carid][respawn_timer] = INVALID_TIMER_ID;	
				return veh_timer_ex(i, carid);		
			}
		}
		case VEHICLE_MAFIA_1:
		{
			if(pData[i][pFraction] != 13)
			{
				SendErr(i,"Вы не состоите в ОПГ!");
				return RemovePlayerFromVehicleEx(i);		
			}
			else
			{
				KillTimer(vehicle[carid][respawn_timer]);
				vehicle[carid][respawn_timer] = INVALID_TIMER_ID;	
				return veh_timer_ex(i, carid);		
			}
		}
		case VEHICLE_MAFIA_2:
		{
			if(pData[i][pFraction] != 14)
			{
				SendErr(i,"Вы не состоите в ОПГ!");
				return RemovePlayerFromVehicleEx(i);		
			}
			else
			{
				KillTimer(vehicle[carid][respawn_timer]);
				vehicle[carid][respawn_timer] = INVALID_TIMER_ID;	
				return veh_timer_ex(i, carid);			
			}
		}
		case VEHICLE_MAFIA_3:
		{
			if(pData[i][pFraction] != 15)
			{
				SendErr(i,"Вы не состоите в ОПГ!");
				return RemovePlayerFromVehicleEx(i);				
			}
			else
			{
				KillTimer(vehicle[carid][respawn_timer]);
				vehicle[carid][respawn_timer] = INVALID_TIMER_ID;	
				return veh_timer_ex(i, carid);			
			}
		}
		case VEHICLE_FIRE:
		{
			if(pData[i][pJob] != SKILL_FIRE)
			{
				SendErr(i,"Вы не работаете пожарным!");
				return RemovePlayerFromVehicleEx(i);			
			}
			else
			{
				KillTimer(vehicle[carid][respawn_timer]);
				vehicle[carid][respawn_timer] = INVALID_TIMER_ID;	
				return veh_timer_ex(i, carid);		
			}			
		}
		case VEHICLE_NEWS_1:
		{
			if(pData[i][pFraction] != 10 || pData[i][pSubfraction] == 0)
			{ 
				SendErr(i,"Вы не являетесь сотрудником СМИ!"); 
				return RemovePlayerFromVehicleEx(i);
			}
			else
			{
				KillTimer(vehicle[carid][respawn_timer]);
				vehicle[carid][respawn_timer] = INVALID_TIMER_ID;	
				return veh_timer_ex(i, carid);	
			}
		}
		case VEHICLE_NEWS_2:
		{
			if(pData[i][pFraction] != 10 || pData[i][pSubfraction] == 0)
			{ 
				SendErr(i,"Вы не являетесь сотрудником СМИ!");
				return RemovePlayerFromVehicleEx(i);		
			}	
			else
			{
				KillTimer(vehicle[carid][respawn_timer]);
				vehicle[carid][respawn_timer] = INVALID_TIMER_ID;	
				return veh_timer_ex(i, carid);			
			}
		}
		case VEHICLE_HOSPITAL_1:
		{
			if(pData[i][pFraction] != 2 && pData[i][pSubfraction] != 2)
			{ 
				SendErr(i,"Вы не являетесь сотрудником Больницы г. Арзамас!");
				return RemovePlayerFromVehicleEx(i);
			}
			else
			{
				KillTimer(vehicle[carid][respawn_timer]);
				vehicle[carid][respawn_timer] = INVALID_TIMER_ID;	
				return veh_timer_ex(i, carid);			
			
			}
		}
		case VEHICLE_HOSPITAL_2:
		{
			if(pData[i][pFraction] != 2 && pData[i][pSubfraction] != 1)
			{ 
				SendErr(i,"Вы не являетесь сотрудником Больницы г. Южный!");
				return RemovePlayerFromVehicleEx(i);	
			}	
			else
			{
				KillTimer(vehicle[carid][respawn_timer]);
				vehicle[carid][respawn_timer] = INVALID_TIMER_ID;	
				return veh_timer_ex(i, carid);	
			}
		}
		case VEHICLE_ARMY_1:
		{
			if(pData[i][pFraction] != 8)
			{ 
				SendErr(i,"Вы не являетесь сотрудником Армии!");
				return RemovePlayerFromVehicleEx(i);				
			}
			else
			{
				KillTimer(vehicle[carid][respawn_timer]);
				vehicle[carid][respawn_timer] = INVALID_TIMER_ID;	
				return veh_timer_ex(i, carid);		
			}
		}
		case VEHICLE_ARMY_VERT:
		{
			if(pData[i][pFraction] != 8 && pData[i][pRank] < 5)
			{ 
				SendErr(i,"Вы не являетесь сотрудником Армии или ваше звание недостаточное!");
				return RemovePlayerFromVehicleEx(i);
			}	
			return veh_timer_ex(i, carid);			
		}
		case VEHICLE_AUTOSALON_1:
		{
			if(pTemp[i][rent_car] != carid)
			{
				SendErr(i,"Вы не арендуете данное транспортное средство!");
				return RemovePlayerFromVehicleEx(i);				
			}
			else
			{
				rent_update_timer(i);
				pTemp[i][rent_car_spawn_timer] = INVALID_TIMER_ID;
				return veh_timer_ex(i, carid);
			}
		}
		case VEHICLE_AUTOSALON_2:
		{
			if(pTemp[i][rent_car] != carid)
			{
				SendErr(i,"Вы не арендуете данное транспортное средство!");
				return RemovePlayerFromVehicleEx(i);				
			}
			else
			{
				rent_update_timer(i);
				pTemp[i][rent_car_spawn_timer] = INVALID_TIMER_ID;
				return veh_timer_ex(i, carid);
			}
		}
		case VEHICLE_AUTOSALON_3:
		{
			if(pTemp[i][rent_car] != carid)
			{
				SendErr(i,"Вы не арендуете данное транспортное средство!");
				return RemovePlayerFromVehicleEx(i);				
			}
			else
			{
				rent_update_timer(i);
				pTemp[i][rent_car_spawn_timer] = INVALID_TIMER_ID;
				return veh_timer_ex(i, carid);
			}
		}
		case VEHICLE_TRUCKER_1:
		{
			if(pTemp[i][rent_car] != carid)
			{
				SendErr(i,"Вы не арендуете данное транспортное средство!");
				return RemovePlayerFromVehicleEx(i);				
			}
			else
			{
				rent_update_timer(i);
				pTemp[i][rent_car_spawn_timer] = INVALID_TIMER_ID;
				return veh_timer_ex(i, carid);
			}
		}
		case VEHICLE_TRUCKER_2:
		{
			if(pTemp[i][rent_car] != carid)
			{
				SendErr(i,"Вы не арендуете данное транспортное средство!");
				return RemovePlayerFromVehicleEx(i);				
			}
			else
			{
				rent_update_timer(i);
				pTemp[i][rent_car_spawn_timer] = INVALID_TIMER_ID;
				return veh_timer_ex(i, carid);
			}
		}
		case VEHICLE_TRUCKER_3:
		{
			if(pTemp[i][rent_car] != carid)
			{
				SendErr(i,"Вы не арендуете данное транспортное средство!");
				return RemovePlayerFromVehicleEx(i);				
			}
			else
			{
				rent_update_timer(i);
				pTemp[i][rent_car_spawn_timer] = INVALID_TIMER_ID;
				return veh_timer_ex(i, carid);
			}
		}
		case VEHICLE_SNOW_WORK:
		{
			if(pTemp[i][rent_car] != carid)
			{
				SendErr(i,"Вы не арендуете данное транспортное средство!");
				return RemovePlayerFromVehicleEx(i);				
			}
			else
			{
				rent_update_timer(i);
				pTemp[i][rent_car_spawn_timer] = INVALID_TIMER_ID;
				return veh_timer_ex(i, carid);
			}
		}
		case VEHICLE_TRASH_WORK:
		{
			if(pTemp[i][rent_car] != carid)
			{
				SendErr(i,"Вы не арендуете данное транспортное средство!");
				return RemovePlayerFromVehicleEx(i);				
			}
			else
			{
				rent_update_timer(i);
				pTemp[i][rent_car_spawn_timer] = INVALID_TIMER_ID;
				return veh_timer_ex(i, carid);
			}			
		}
		case VEHICLE_BANK_WORK:
		{
			if(pTemp[i][rent_car] != carid)
			{
				SendErr(i,"Вы не арендуете данное транспортное средство!");
				return RemovePlayerFromVehicleEx(i);				
			}
			else
			{
				rent_update_timer(i);
				pTemp[i][rent_car_spawn_timer] = INVALID_TIMER_ID;
				return veh_timer_ex(i, carid);
			}			
		}
	}*/

	switch(get_vehicle_type(carid))
	{
		case TYPE_CAR:
		{
		}
		case TYPE_BOAT:
		{
		
		}
		case TYPE_PLANE:
		{
			
		}
		case TYPE_BYCICLE: 
		{
			vehicle_engine_status(carid, true);
			KillTimer(pTemp[i][vehicle_speed_timer]);
			
			hide_speed_player(i);

			PlayerTextDrawHide(i, player_speed_car[0][i]);
			PlayerTextDrawHide(i, player_speed_car[1][i]);
			PlayerTextDrawHide(i, player_speed_car[2][i]);
			PlayerTextDrawHide(i, player_speed_car[3][i]);
			PlayerTextDrawHide(i, player_speed_car[4][i]);
			PlayerTextDrawHide(i, player_speed_car[5][i]);		
			PlayerTextDrawHide(i, player_speed_car[6][i]);
			PlayerTextDrawHide(i, player_speed_car[7][i]);
			PlayerTextDrawHide(i, player_speed_car[8][i]);		
			PlayerTextDrawHide(i, player_speed_car[9][i]);
			PlayerTextDrawHide(i, player_speed_car[10][i]);

			PlayerTextDrawDestroy(i, player_speed_car[0][i]);
			PlayerTextDrawDestroy(i, player_speed_car[1][i]);
			PlayerTextDrawDestroy(i, player_speed_car[2][i]);
			PlayerTextDrawDestroy(i, player_speed_car[3][i]);
			PlayerTextDrawDestroy(i, player_speed_car[4][i]);
			PlayerTextDrawDestroy(i, player_speed_car[5][i]);
			PlayerTextDrawDestroy(i, player_speed_car[6][i]);
			PlayerTextDrawDestroy(i, player_speed_car[7][i]);
			PlayerTextDrawDestroy(i, player_speed_car[8][i]);
			PlayerTextDrawDestroy(i, player_speed_car[9][i]);
			PlayerTextDrawDestroy(i, player_speed_car[10][i]);


		}
	}

	if(debug_mode)
	{
		printf("[player_vehicle_enter]: Времени затрачено: <%d мс>" , GetTickCount() - time);
	}

	return veh_timer_ex(i, carid);
}

stock rent_update_timer(playerid)
{
	new 
		v = GetPlayerVehicleID(playerid);

	if(pTemp[playerid][rent_car] == v)
	{
		KillTimer(pTemp[playerid][rent_car_spawn_timer]);
		pTemp[playerid][rent_car_spawn_timer] = INVALID_TIMER_ID;
	}
	

	return true;
}

stock veh_timer_ex(i, carid)
{
	new 
		speed_update_time;

	if(pData[i][pSettings][6] == 1)
	{
		speed_update_time = 550;
	}
	else
	{
		speed_update_time = 1050;
	}

	return pTemp[i][vehicle_speed_timer] = SetTimerEx("player_vehicle_timer", speed_update_time, false, "ii", i, carid);
}

stock player_vehicle_exit(i, carid)
{
	new time = GetTickCount();


	vehicle[carid][vehicle_driver] = INVALID_PLAYER_ID;
	player_vehicle[i] = INVALID_VEHICLE_ID;

	KillTimer(pTemp[i][vehicle_speed_timer]);
	
	hide_speed_player(i);

	PlayerTextDrawHide(i, player_speed_car[0][i]);
	PlayerTextDrawHide(i, player_speed_car[1][i]);
	PlayerTextDrawHide(i, player_speed_car[2][i]);
	PlayerTextDrawHide(i, player_speed_car[3][i]);
	PlayerTextDrawHide(i, player_speed_car[4][i]);
	PlayerTextDrawHide(i, player_speed_car[5][i]);		
	PlayerTextDrawHide(i, player_speed_car[6][i]);
	PlayerTextDrawHide(i, player_speed_car[7][i]);
	PlayerTextDrawHide(i, player_speed_car[8][i]);		
	PlayerTextDrawHide(i, player_speed_car[9][i]);
	PlayerTextDrawHide(i, player_speed_car[10][i]);

	PlayerTextDrawDestroy(i, player_speed_car[0][i]);
	PlayerTextDrawDestroy(i, player_speed_car[1][i]);
	PlayerTextDrawDestroy(i, player_speed_car[2][i]);
	PlayerTextDrawDestroy(i, player_speed_car[3][i]);
	PlayerTextDrawDestroy(i, player_speed_car[4][i]);
	PlayerTextDrawDestroy(i, player_speed_car[5][i]);
	PlayerTextDrawDestroy(i, player_speed_car[6][i]);
	PlayerTextDrawDestroy(i, player_speed_car[7][i]);
	PlayerTextDrawDestroy(i, player_speed_car[8][i]);
	PlayerTextDrawDestroy(i, player_speed_car[9][i]);
	PlayerTextDrawDestroy(i, player_speed_car[10][i]);

	if(carid != INVALID_VEHICLE_ID)
	{
		new
			own = vehicle[carid][cOwnTo];

		switch(own)
		{
			case VEHICLE_START_GAME:
			{
				if(pTemp[i][rent_car] == carid)
				{
					SendInf(i, "Арендованное начальное транспортное средство будет отбуксировано через 5 минут, если Вы не вернетесь!");
					pTemp[i][rent_car_spawn_timer] = SetTimerEx("spawn_rent_transport_start", 1000, false, "iii", i, pTemp[i][rent_car], 300);

					vehicle_lock_status(carid, false);

					return true;
				}
			} 
			case VEHICLE_FIRE:
			{
				if(pTemp[i][rent_car] == carid)
				{
					pTemp[i][rent_car_spawn_timer] = SetTimerEx("spawn_rent_car_fire_work", 1000, false, "iii", i, pTemp[i][rent_car], 900);
					return true; 
				}				
			}
			case VEHICLE_SNOW_WORK:
			{

				if(pTemp[i][rent_car] == carid)
				{
					pTemp[i][rent_car_spawn_timer] = SetTimerEx("spawn_rent_car_snow_work", 1000, false, "iii", i, pTemp[i][rent_car], 15);
					return true;
				}
				
			}
			case VEHICLE_TRASH_WORK:
			{
				if(pTemp[i][rent_car] == carid)
				{
					pTemp[i][rent_car_spawn_timer] = SetTimerEx("spawn_rent_car_trash_work", 1000, false, "iii", i, pTemp[i][rent_car], 120);
					return true;
				}				
			}
			case VEHICLE_BANK_WORK:
			{
				if(pTemp[i][rent_car] == carid)
				{
					pTemp[i][rent_car_spawn_timer] = SetTimerEx("spawn_rent_car_bank_work", 1000, false, "iii", i, pTemp[i][rent_car], 120);
					return true;
				}					
			}
			case VEHICLES_BUS:
			{
				if(GetPVarInt(i, "bus_job_cp"))
				{
					if(pTemp[i][rent_car] == carid)
					{
						pTemp[i][rent_car_spawn_timer] = SetTimerEx("spawn_rent_car_bus", 1000, false, "iii", i, pTemp[i][rent_car], 15);
						return true;
					}
				}				
			}
			case VEHICLE_AUTOSALON_1:
			{
				if(pTemp[i][rent_car] == carid)
				{
					SendInf(i, "Арендованное транспортное средство автосалона будет отбуксировано через 5 минут, если Вы не вернетесь!");
					pTemp[i][rent_car_spawn_timer] = SetTimerEx("spawn_rent_car_autosalon", 1000, false, "iii", i, pTemp[i][rent_car], 300);
					return true;
				}
			}
			case VEHICLE_AUTOSALON_2:
			{
				if(pTemp[i][rent_car] == carid)
				{
					SendInf(i, "Арендованное транспортное средство автосалона будет отбуксировано через 5 минут, если Вы не вернетесь!");
					pTemp[i][rent_car_spawn_timer] = SetTimerEx("spawn_rent_car_autosalon", 1000, false, "iii", i, pTemp[i][rent_car], 300);
					return true;
				}
			}
			case VEHICLE_AUTOSALON_3:
			{
				if(pTemp[i][rent_car] == carid)
				{
					SendInf(i, "Арендованное транспортное средство автосалона будет отбуксировано через 5 минут, если Вы не вернетесь!");
					pTemp[i][rent_car_spawn_timer] = SetTimerEx("spawn_rent_car_autosalon", 1000, false, "iii", i, pTemp[i][rent_car], 300);
					return true;
				}
			}

			case VEHICLE_UBER:
			{
				if(pTemp[i][rent_car] == carid)
				{
					SendInf(i, "Арендованное транспортное средство автосалона будет отбуксировано через 5 минут, если Вы не вернетесь!");
					pTemp[i][rent_car_spawn_timer] = SetTimerEx("spawn_rent_car_taxi", 1000, false, "iii", i, pTemp[i][rent_car], 300);
					return true;
				}				
			}
			case VEHICLE_YANDEX:
			{
				if(pTemp[i][rent_car] == carid)
				{
					SendInf(i, "Арендованное транспортное средство автосалона будет отбуксировано через 5 минут, если Вы не вернетесь!");
					pTemp[i][rent_car_spawn_timer] = SetTimerEx("spawn_rent_car_taxi", 1000, false, "iii", i, pTemp[i][rent_car], 300);
					return true;
				}				
			}
			case VEHICLE_CITY:
			{
				if(pTemp[i][rent_car] == carid)
				{
					SendInf(i, "Арендованное транспортное средство автосалона будет отбуксировано через 5 минут, если Вы не вернетесь!");
					pTemp[i][rent_car_spawn_timer] = SetTimerEx("spawn_rent_car_taxi", 1000, false, "iii", i, pTemp[i][rent_car], 300);
					return true;
				}				
			}
			case VEHICLE_TRUCKER_1:
			{
				if(pTemp[i][rent_car] == carid)
				{
					SendInf(i, "Арендованное транспортное средство автосалона будет отбуксировано через 30 секунд, если Вы не вернетесь!");
					pTemp[i][rent_car_spawn_timer] = SetTimerEx("spawn_rent_car_trucker", 1000, false, "iii", i, pTemp[i][rent_car], 30);
					return true;
				}					
			}
			case VEHICLE_TRUCKER_2:
			{
				if(pTemp[i][rent_car] == carid)
				{
					SendInf(i, "Арендованное транспортное средство автосалона будет отбуксировано через 30 секунд, если Вы не вернетесь!");
					pTemp[i][rent_car_spawn_timer] = SetTimerEx("spawn_rent_car_trucker", 1000, false, "iii", i, pTemp[i][rent_car], 30);
					return true;
				}					
			}
			case VEHICLE_TRUCKER_3:
			{
				if(pTemp[i][rent_car] == carid)
				{
					SendInf(i, "Арендованное транспортное средство автосалона будет отбуксировано через 30 секунд, если Вы не вернетесь!");
					pTemp[i][rent_car_spawn_timer] = SetTimerEx("spawn_rent_car_trucker", 1000, false, "iii", i, pTemp[i][rent_car], 30);
					return true;
				}					
			}

			case VEHICLE_MECHANIC_1:
			{
				if(pTemp[i][rent_car] == carid)
				{
					SendInf(i, "Арендованное транспортное средство автосалона будет отбуксировано через 30 секунд, если Вы не вернетесь!");
					pTemp[i][rent_car_spawn_timer] = SetTimerEx("spawn_rent_car_mechanic", 1000, false, "iii", i, pTemp[i][rent_car], 30);
					return true;
				}				
			}
			case VEHICLE_MECHANIC_2:
			{
				if(pTemp[i][rent_car] == carid)
				{
					SendInf(i, "Арендованное транспортное средство автосалона будет отбуксировано через 30 секунд, если Вы не вернетесь!");
					pTemp[i][rent_car_spawn_timer] = SetTimerEx("spawn_rent_car_mechanic", 1000, false, "iii", i, pTemp[i][rent_car], 30);
					return true;
				}				
			}
			case VEHICLE_MECHANIC_3:
			{
				if(pTemp[i][rent_car] == carid)
				{
					SendInf(i, "Арендованное транспортное средство автосалона будет отбуксировано через 30 секунд, если Вы не вернетесь!");
					pTemp[i][rent_car_spawn_timer] = SetTimerEx("spawn_rent_car_mechanic", 1000, false, "iii", i, pTemp[i][rent_car], 30);
					return true;
				}				
			}

			case VEHICLE_GOV:
			{
				vehicle[carid][respawn_timer] = SetTimerEx("respawn_org_transport", 1000, false, "ii", carid, 600);
			}
			case VEHICLE_FEDERALS:
			{
				vehicle[carid][respawn_timer] = SetTimerEx("respawn_org_transport", 1000, false, "ii", carid, 600);
			}
			case VEHICLE_POLICES:
			{
				vehicle[carid][respawn_timer] = SetTimerEx("respawn_org_transport", 1000, false, "ii", carid, 600);
			}
			case VEHICLE_NEWS_1:
			{
				vehicle[carid][respawn_timer] = SetTimerEx("respawn_org_transport", 1000, false, "ii", carid, 600);
			}
			case VEHICLE_NEWS_2:
			{
				vehicle[carid][respawn_timer] = SetTimerEx("respawn_org_transport", 1000, false, "ii", carid, 600);
			}
			case VEHICLE_HOSPITAL_1:
			{
				vehicle[carid][respawn_timer] = SetTimerEx("respawn_org_transport", 1000, false, "ii", carid, 600);
			}
			case VEHICLE_HOSPITAL_2:
			{
				vehicle[carid][respawn_timer] = SetTimerEx("respawn_org_transport", 1000, false, "ii", carid, 600);
			}
			case VEHICLE_ARMY_1:
			{
				vehicle[carid][respawn_timer] = SetTimerEx("respawn_org_transport", 1000, false, "ii", carid, 600);
			}
			case VEHICLE_MAFIA_1:
			{
				vehicle[carid][respawn_timer] = SetTimerEx("respawn_org_transport", 1000, false, "ii", carid, 600);
			}
			case VEHICLE_MAFIA_2:
			{
				vehicle[carid][respawn_timer] = SetTimerEx("respawn_org_transport", 1000, false, "ii", carid, 600);
			}
			case VEHICLE_MAFIA_3:
			{
				vehicle[carid][respawn_timer] = SetTimerEx("respawn_org_transport", 1000, false, "ii", carid, 600);
			}
		}
	}
	pTemp[i][vehicle_speed_timer] = -1;

	if(debug_mode)
	{
		printf("[player_vehicle_exit]: Времени затрачено: <%d мс>" , GetTickCount() - time);
	}

	return true;
}


stock unrent_start_game_transport(playerid)
{
	new 
		v = pTemp[playerid][rent_car];

	if(v == INVALID_VEHICLE_ID) return true;
	if(vehicle[v][cOwnTo] != VEHICLE_START_GAME) return true;
	DestroyVehicle(v);
	//DisablePlayerRaceCheckpoint(playerid);

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:info_gui_vehicle_unrent", 3500);


	pTemp[playerid][rent_car] = INVALID_VEHICLE_ID;
	pTemp[playerid][rent_car_spawn_timer] = INVALID_TIMER_ID;

	KillTimer(pTemp[playerid][rent_car_spawn_timer]);

	SendSucc(playerid, "Аренда временного начального транспорта окончена!");

	return true;
}

callback:: respawn_org_transport(v, time)
{
	time--;

	if(!time)
	{
		DestroyVehicle(v);
		KillTimer(vehicle[v][respawn_timer]);
		vehicle[v][respawn_timer] = INVALID_TIMER_ID;

		return true;
	}
	vehicle[v][respawn_timer] = SetTimerEx("respawn_org_transport", 1000, false, "ii", v, time);
	return true; 
}

callback:: spawn_rent_transport_start(i, v, time)
{

	if(IsPlayerConnected(i))
	{	
		time--;

		if(!time)
		{
			unrent_start_game_transport(i);
			return true;
		}

		pTemp[i][rent_car_spawn_timer] = SetTimerEx("spawn_rent_transport_start", 1000, false, "iii", i, v, time);
	}
	return true;
}

stock GetPlayerVehicleModel(playerid)
{
	if(!IsPlayerInAnyVehicle(playerid)) return false;
	return GetVehicleModel(GetPlayerVehicleID(playerid));
}

stock get_vehicle_type_name(i)
{
	new name[30];
	switch(i){
		case TYPE_CAR: name = "Авто";
		case TYPE_HELI: name = "Вертолет";
		case TYPE_PLANE: name = "Самолет";
		case TYPE_BOAT: name = "Лодка";
		case TYPE_MOTO: name = "Мото";
		case TYPE_BYCICLE: name = "Велосипед";
		case TYPE_RC: name = "Радио-транспорт";
		case TYPE_TRAILER: name = "Фура";
		case TYPE_TRAM: name = "Поезд";
		case TYPE_FUN: name = "Для фана";
		default: name = "Неизвестно";
	}
	return name;
}

stock get_vehicle_type(i)
{
	new model = GetVehicleModel(i);

	switch(model)
	{
		case 548: return TYPE_PLANE;
		case 425: return TYPE_PLANE;
		case 417: return TYPE_PLANE;
		case 487: return TYPE_PLANE;
		case 488: return TYPE_PLANE;
		case 497: return TYPE_PLANE;
		case 563: return TYPE_PLANE;
		case 447: return TYPE_PLANE;
		case 469: return TYPE_PLANE;

		case 460: return TYPE_PLANE;
		case 476: return TYPE_PLANE;
		case 511: return TYPE_PLANE;
		case 512: return TYPE_PLANE;
		case 513: return TYPE_PLANE;
		case 519: return TYPE_PLANE;
		case 520: return TYPE_PLANE;
		case 553: return TYPE_PLANE;
		case 577: return TYPE_PLANE;
		case 592: return TYPE_PLANE;
		case 593: return TYPE_PLANE;

		case 472: return TYPE_BOAT;
		case 473: return TYPE_BOAT;
		case 493: return TYPE_BOAT;
		case 595: return TYPE_BOAT;
		case 484: return TYPE_BOAT;
		case 430: return TYPE_BOAT;
		case 453: return TYPE_BOAT;
		case 452: return TYPE_BOAT;
		case 446: return TYPE_BOAT;
		case 454: return TYPE_BOAT;

		case 509: return TYPE_BYCICLE;
		case 481: return TYPE_BYCICLE;
		case 510: return TYPE_BYCICLE;

		case 581: return TYPE_MOTO;
		case 462: return TYPE_MOTO;
		case 521: return TYPE_MOTO;
		case 463: return TYPE_MOTO;
		case 522: return TYPE_MOTO;
		case 461: return TYPE_MOTO;
		case 448: return TYPE_MOTO;
		case 468: return TYPE_MOTO;
		case 586: return TYPE_MOTO;

		case 441: return TYPE_RC;
		case 464: return TYPE_RC;
		case 594: return TYPE_RC;
		case 501: return TYPE_RC;
		case 465: return TYPE_RC;
		case 564: return TYPE_RC;

		case 606: return TYPE_TRAILER;
		case 607: return TYPE_TRAILER;
		case 610: return TYPE_TRAILER;
		case 584: return TYPE_TRAILER;
		case 611: return TYPE_TRAILER;
		case 608: return TYPE_TRAILER;
		case 435: return TYPE_TRAILER;
		case 450: return TYPE_TRAILER;
		case 591: return TYPE_TRAILER;

		case 590: return TYPE_TRAM;
		case 538: return TYPE_TRAM;
		case 570: return TYPE_TRAM;
		case 569: return TYPE_TRAM;
		case 537: return TYPE_TRAM;
		case 449: return TYPE_TRAM;

		case 568: return TYPE_FUN;
		case 424: return TYPE_FUN;
		case 504: return TYPE_FUN;
		case 457: return TYPE_FUN;
		case 483: return TYPE_FUN;
		case 508: return TYPE_FUN;
		case 571: return TYPE_FUN;
		case 500: return TYPE_FUN;
		case 444: return TYPE_FUN;
		case 556: return TYPE_FUN;
		case 557: return TYPE_FUN;
		case 471: return TYPE_FUN;
		case 495: return TYPE_FUN;
		case 539: return TYPE_FUN;

		default: return TYPE_CAR;
	}
	return true;
}

stock RemovePlayerFromVehicleEx(playerid)
{
	RemovePlayerFromVehicle(playerid);
	return true;
}

stock create_vehicles()
{

	vehicle_fims[0] = CreateVehicle(403,1885.2278,2905.0474,12.8619,180.5111,1,1, 600);
	vehicle_fims[1] = CreateVehicle(403,1889.4240,2905.4534,12.8640,180.7903,1,1, 600);
	vehicle_fims[2] = CreateVehicle(456,1893.4877,2905.4348,12.8647,179.5159,1,1, 600);
	vehicle_fims[3] = CreateVehicle(403,1906.5336,2905.5464,12.8646,180.5691,1,1, 600);
	vehicle_fims[4] = CreateVehicle(456,1910.7311,2905.5493,12.8616,179.7816,1,1, 600);

	vehicle_fims[5] = CreateVehicle(450,1862.1057,2848.7395,12.4189,2.3892,197,185, 600);
	vehicle_fims[6] = CreateVehicle(450,1883.8558,2848.7395,12.4189,0.000,166,247, 600);
	vehicle_fims[7] = CreateVehicle(450,1905.2860,2848.7395,12.4189,0.000,41,245, 600);

 	vehicle_fims[8] = CreateVehicle(597,2426.9124,-1918.0924,21.9723,180.5716,0,0, 600);
 	SetVehicleRuPolNumberPlate(vehicle_fims[8], "x777am", "777");
 	vehicle_fims[9] = CreateVehicle(597, -1557.5034,-1552.3914,52.1809,300.2603,0,0, 600);
 	SetVehicleRuPolNumberPlate(vehicle_fims[9], "x777am", "777");
 	vehicle_fims[10] = CreateVehicle(597, -1560.1665,-1537.2870,54.1033,231.2570,0,0, 600);
 	SetVehicleRuPolNumberPlate(vehicle_fims[10], "x777am", "777");

	vehicle_visual[0] = CreateVehicle(402,-0.0470,1000.2169,1300.7230,175.3842,1,1, 50);

	vehicle_visual[1] = CreateVehicle(551,-208.7477,-13.5692,1201.8286,270.5706,1,1, 50);
	vehicle_visual[2] = CreateVehicle(458,-226.2333,-13.3400,1201.2126,269.5290,1,1, 50);
	vehicle_visual[3] = CreateVehicle(401,-194.6372,11.2994,1201.2177,220.1238,1,1, 50);
	vehicle_visual[4] = CreateVehicle(445,-183.9161,11.2956,1201.2844,138.4212,1,1, 50);


	vehicle_visual[5] = CreateVehicle(419,-31.2337,366.4912,1601.4789,270.5635,random(256),random(256), 50);
	vehicle_visual[6] = CreateVehicle(410,-31.2383,359.9377,1600.9111,270.8040,random(256),random(256), 50);
	vehicle_visual[7] = CreateVehicle(547,-31.1889,349.5703,1601.5208,270.2085,random(256),random(256), 50);
	vehicle_visual[8] = CreateVehicle(415,-31.2953,332.7148,1601.3846,267.2896,random(256),random(256), 50);
	vehicle_visual[9] = CreateVehicle(579,-25.0101,323.8032,1601.6494,359.6447,random(256),random(256), 50);
	vehicle_visual[10] = CreateVehicle(566,-13.0633,351.9801,1601.3119,61.1151,random(256),random(256), 50);
	vehicle_visual[11] = CreateVehicle(466,3.6110,351.6901,1609.3286,191.7256,random(256),random(256), 50);
	vehicle_visual[12] = CreateVehicle(480,-31.0034,343.5474,1601.3125,270.2623,random(256),random(256), 50);

	vehicle_visual[13] = CreateVehicle(474,-13.3617,-717.1860,1201.8417,90.6541,random(256),random(256), 50);
	vehicle_visual[14] = CreateVehicle(438,-35.0758,-721.0457,1201.6171,316.3194,random(256),random(256), 50);
	vehicle_visual[15] = CreateVehicle(589,-12.8021,-698.0065,1201.2479,88.8959,random(256),random(256), 50);
	vehicle_visual[16] = CreateVehicle(527,-31.5853,-705.9379,1201.7616,238.2043,random(256),random(256), 50);
	vehicle_visual[17] = CreateVehicle(474,-13.3132,-707.3986,1201.8455,92.9363,random(256),random(256), 50);



	SetVehicleRuNumberPlate(vehicle_visual[0], "x777am", "777");

	SetVehicleVirtualWorld(vehicle_visual[13], 10);	
	SetVehicleVirtualWorld(vehicle_visual[14], 10);	
	SetVehicleVirtualWorld(vehicle_visual[15], 10);			
	SetVehicleVirtualWorld(vehicle_visual[16], 10);	
	SetVehicleVirtualWorld(vehicle_visual[17], 10);	

	SetVehicleVirtualWorld(vehicle_visual[0], 5);
	
	SetVehicleVirtualWorld(vehicle_visual[1], 10);			
	SetVehicleVirtualWorld(vehicle_visual[2], 10);	
	SetVehicleVirtualWorld(vehicle_visual[3], 10);	
	SetVehicleVirtualWorld(vehicle_visual[4], 10);	
	SetVehicleVirtualWorld(vehicle_visual[5], 10);			
	SetVehicleVirtualWorld(vehicle_visual[6], 10);	
	SetVehicleVirtualWorld(vehicle_visual[7], 10);	
	SetVehicleVirtualWorld(vehicle_visual[8], 10);	
	SetVehicleVirtualWorld(vehicle_visual[9], 10);			
	SetVehicleVirtualWorld(vehicle_visual[10], 10);	
	SetVehicleVirtualWorld(vehicle_visual[11], 10);	
	SetVehicleVirtualWorld(vehicle_visual[12], 10);	

	SetVehicleVirtualWorld(vehicle_fims[0], 520);
	SetVehicleVirtualWorld(vehicle_fims[1], 520);
	SetVehicleVirtualWorld(vehicle_fims[2], 520);
	SetVehicleVirtualWorld(vehicle_fims[3], 520);
	SetVehicleVirtualWorld(vehicle_fims[4], 520);
	SetVehicleVirtualWorld(vehicle_fims[5], 520);
	SetVehicleVirtualWorld(vehicle_fims[6], 520);
	SetVehicleVirtualWorld(vehicle_fims[7], 520);

	SetVehicleVirtualWorld(vehicle_fims[8], 520);
	SetVehicleVirtualWorld(vehicle_fims[9], 521);
	SetVehicleVirtualWorld(vehicle_fims[10], 521);

    new engine, lights, alarm, doors, bonnet, boot, objective;
    GetVehicleParamsEx(vehicle_fims[8], engine, lights, alarm, doors, bonnet, boot, objective);
    SetVehicleParamsEx(vehicle_fims[8], engine, 1, alarm, doors, bonnet, boot, objective);
    GetVehicleParamsEx(vehicle_fims[9], engine, lights, alarm, doors, bonnet, boot, objective);
    SetVehicleParamsEx(vehicle_fims[9], engine, 1, alarm, doors, bonnet, boot, objective);
    GetVehicleParamsEx(vehicle_fims[10], engine, lights, alarm, doors, bonnet, boot, objective);
    SetVehicleParamsEx(vehicle_fims[10], engine, 1, alarm, doors, bonnet, boot, objective);

	for(new i = vehicle_visual[0], car = vehicle_visual[17]; i <= car; i++)
	{

	    new engine, lights, alarm, doors, bonnet, boot, objective;
	    GetVehicleParamsEx(i, engine, lights, alarm, doors, bonnet, boot, objective);
		SetVehicleParamsEx(i, engine, lights, alarm, 1, bonnet, boot, objective);

		vehicle[i][cFuel] = 0.0;
		vehicle[i][cHealth] = 1000.0;
		vehicle[i][consumables_oil] = 0.0;
		vehicle[i][cLock] = 2;


		SetVehicleNoPlateNumberPlate(i,  "-----", "---");
	}



	return true;
}


CMD:police_siren(playerid)
{
    if(!IsPlayerInAnyVehicle(playerid)) 
    	return true;
    
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) 
    	return true;

	new 
		panels, doors, lights, tires;

    new vehicleid = GetPlayerVehicleID(playerid);

    count_strobrscop[vehicleid] = 0;

    if(!status_strobocop[vehicleid])
    {
        timer_strobocop[vehicleid] = SetTimerEx("function_strobocop",200,true,"i",vehicleid);
        status_strobocop[vehicleid] = true;
        return true;
    }
    KillTimer(timer_strobocop[vehicleid]);
    status_strobocop[vehicleid] = false;
    GetVehicleDamageStatus(vehicleid, panels, doors, lights, tires);
    UpdateVehicleDamageStatus(vehicleid, panels, doors, 0, tires);

    SetVehicleLightsColors(vehicleid, 247, 237, 239);

    return true;
}
 
forward function_strobocop(vehicleid);
public function_strobocop(vehicleid)
{
	new 
		panels, doors, lights, tires;


    GetVehicleDamageStatus(vehicleid, panels, doors, lights, tires);
    switch(count_strobrscop[vehicleid])
    {
        case 0:
        {
        	UpdateVehicleDamageStatus(vehicleid, panels, doors, 1, tires), count_strobrscop[vehicleid] = 1;
        	SetVehicleLightsColors(vehicleid, 0, 102, 255);
        }
        case 1: 
        {
        	UpdateVehicleDamageStatus(vehicleid, panels, doors, 4, tires), count_strobrscop[vehicleid] = 2;
        	SetVehicleLightsColors(vehicleid, 252, 15, 59);
        }
        case 2: 
        {
        	UpdateVehicleDamageStatus(vehicleid, panels, doors, 65,tires), count_strobrscop[vehicleid] = 3;
        	SetVehicleLightsColors(vehicleid, 0, 102, 255);

        }
        case 3: 
        {
        	UpdateVehicleDamageStatus(vehicleid, panels, doors, 68,tires), count_strobrscop[vehicleid] = 0;
        	SetVehicleLightsColors(vehicleid, 252, 15, 59);
        }
    }
}


CMD:boost_speed(playerid, params[])
{
	if(pData[playerid][pAdmin] < 8) 
		return NoCMD(playerid);

	new id;
	if(sscanf(params, "d", id)) 
		return SendInf(playerid, "/boost_speed [Скорость]");	

	new vehicleid = GetPlayerVehicleID(playerid);

	return SetVehicleSpeed(vehicleid, id);
}

stock SetVehicleSpeed(vehicleid, Float:speed)
{
	new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2, Float:a;
	GetVehicleVelocity(vehicleid, x1, y1, z1);
	GetVehiclePos(vehicleid, x2, y2, z2);
	GetVehicleZAngle(vehicleid, a); a = 360 - a;
	x1 = (floatsin(a, degrees) * (speed/100) + floatcos(a, degrees) * 0 + x2) - x2;
	y1 = (floatcos(a, degrees) * (speed/100) + floatsin(a, degrees) * 0 + y2) - y2;
	SetVehicleVelocity(vehicleid, x1, y1, z1);

	return true;
}


stock get_vehicle_speed(carid)
{
    new Float:X, Float:Y, Float:Z;
    GetVehicleVelocity(carid,X,Y,Z);
    return floatround( floatsqroot( X * X + Y * Y + Z * Z ) * 180.0 );
}


stock vehicle_is_rent(carid)
{
	if(vehicle[carid][vehicle_rent_playerid] != -1)
	{
		new 
			playerid = vehicle[carid][vehicle_rent_playerid];
			
		vehicle[carid][vehicle_rent_playerid] = -1;

		KillTimer(pTemp[playerid][rent_car_spawn_timer]);
		pTemp[playerid][rent_car] = INVALID_VEHICLE_ID;
		pTemp[playerid][rent_car_spawn_timer] = INVALID_TIMER_ID;

	}
	return true;
}




CMD:radio(playerid, params[])
{
    if(!IsPlayerInAnyVehicle(playerid)) 
    	return SendErr(playerid, "Вы должны находиться в транспорте");
    
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) 
    	return SendErr(playerid, "Вы на водитель");
    
    if(pData[playerid][pRadio])
	{
	    PlayerPlayStream(playerid, "");
		pData[playerid][pRadio] = 0;
		UpdatePlayerData(playerid, "radio", 0);
		return SCM(playerid,CDARKGREEN,"Радио выключено");
	}
	
	pData[playerid][pRadio] = 1;
	UpdatePlayerData(playerid, "radio", 1);
    
    new string[512];
    strcat(string, "1. Шансон\n");
    strcat(string, "2. Наше Радио\n");
    strcat(string, "3. Зайцев Релакс\n");
    strcat(string, "4. Зайцев Поп\n");
    strcat(string, "5. Наше радио 2.0\n");
    strcat(string, "6. Зайцев Клуб\n");
    strcat(string, "7. Наше Радио классик рок\n");
    strcat(string, "8. Наше Радио панки хой\n");
    strcat(string, "9. Плаза");
    return SPD(playerid, 4496, DIALOG_STYLE_LIST, "Выберите станцию", string, "Выбор", "Отмена");
}
