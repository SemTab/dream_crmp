
new Carnn = 1;

new Iterator:player_vehicles[MAX_PLAYERS]<MAX_VEHICLES-1>;
new Iterator:player_vehicles_preload[MAX_PLAYERS]<MAX_VEHICLES-1>;

static const Float:parking_vehicle_position_spawn[][] = 
{
	{208.1463,767.3187,1204.8004,269.8221},
	{208.0674,762.2500,1204.8002,269.8317},
	{208.1684,757.3200,1204.7836,269.6949},
	{208.0060,752.3203,1204.8000,271.3058},
	{208.0905,747.5128,1204.8000,270.0843},
	{208.0782,742.2146,1204.8002,269.6762},
	{208.0898,737.2557,1204.8002,270.0638},
	{208.1334,732.2776,1204.8003,269.6395},
	{208.2562,727.4539,1204.8003,269.0322},
	{208.1987,722.2975,1204.8000,270.0293},
	{240.8778,709.6671,1204.8002,89.8134},
	{240.8877,714.4504,1204.8003,89.4785},
	{240.8555,719.4924,1204.8003,90.3186},
	{240.8822,724.6876,1204.8003,89.1618},
	{240.8223,729.6494,1204.8000,89.6815},
	{240.7738,734.6984,1204.8003,91.2178},
	{240.8063,739.6011,1204.8002,90.3948},
	{240.7807,744.7568,1204.8002,90.4129},
	{240.7022,749.4707,1204.8002,90.0582},
	{240.7961,754.4873,1204.8002,90.1997},
	{240.7989,759.6038,1204.8003,89.3280},
	{240.7894,764.6894,1204.8003,90.7201},
	{240.7663,769.6769,1204.8000,89.3579},
	{240.7767,774.6529,1204.8003,90.1525},
	{240.7327,779.5587,1204.8002,90.1709},
	{240.8601,779.6183,1212.8003,90.0541},
	{240.7843,774.6144,1212.8002,90.0269},
	{240.9629,769.5863,1212.8002,88.9664},
	{240.8376,764.5198,1212.8002,90.8002},
	{240.8466,759.6646,1212.8002,89.6542},
	{240.8517,754.4620,1212.8003,90.7574},
	{240.7602,749.5272,1212.8002,89.7687},
	{240.8082,744.4370,1212.8003,89.7652},
	{240.8243,739.4323,1212.8002,89.3501},
	{240.7713,734.7468,1212.8002,89.7971},
	{240.7958,729.5035,1212.8002,88.9875},
	{240.7852,724.4621,1212.8002,88.9933},
	{240.7892,719.7066,1212.8003,90.1957},
	{240.7954,714.6702,1212.8004,90.1557},
	{240.7787,709.7963,1212.8002,89.7108},
	{208.0964,767.4138,1212.8003,270.6634},
	{208.2009,762.3363,1212.8002,270.6519},
	{208.0899,757.3771,1212.8003,270.1420},
	{208.2273,752.3450,1212.8003,269.5930},
	{208.2118,747.4121,1212.8003,269.9326},
	{208.2913,742.4914,1212.8000,270.5745},
	{208.2066,737.3331,1212.8003,270.1451},
	{208.2365,732.4765,1212.8002,270.7051},
	{208.2548,727.6165,1212.8003,268.8885},
	{208.2413,722.2386,1212.8002,270.5078}
 	
};

callback:: vehicle_destroy(playerid)
{
	new v = pData[playerid][car_id];

	if(v == INVALID_VEHICLE_ID) return true;
	if(IsValidDynamic3DTextLabel(vehicle[v][cLabel])) DestroyDynamic3DTextLabel(vehicle[v][cLabel]);
	
	DestroyVehicle(v);
	return true;
}

stock check_engine_pos_car(playerid)
{
    
	new 
		vehicle_id = pData[playerid][car_id];

	if(vehicle_id == INVALID_VEHICLE_ID)
		return true;
    if(!IsValidVehicle(vehicle_id))
        return true;
	new 
		Float:x, Float:y, Float:z;


	GetCoordBonnetVehicle(pData[playerid][car_id], x, y, z);

    if(IsPlayerInRangeOfPoint(playerid, 1.5, x, y, z))
    {
        return show_engine_car(playerid);
    }
    return true;
}

stock check_bagage_pos_car(playerid)
{

	new 
		Float:x, Float:y, Float:z;


	GetCoordBootVehicle(pData[playerid][car_id], x, y, z);


    if(IsPlayerInRangeOfPoint(playerid, 2.5, x, y, z))
    {
        return show_bagage_car(playerid);
    }
    return true;
}


stock show_bagage_car(playerid)
{
	ApplyAnimation(playerid,"CRIB","CRIB_Use_Switch",4.0,0,0,0,0,0);


	new 
		vehicle_id = pData[playerid][car_id];

	new 
		engine, lights, alarm, doors, bonnet, boot, objective;

	GetVehicleParamsEx(vehicle_id,engine,lights,alarm,doors,bonnet,boot,objective);
	SetVehicleParamsEx(vehicle_id,engine,lights,alarm,doors,bonnet,true,objective);	

	return true;
}

stock show_engine_car(playerid)
{
	new 
		vehicle_id;

	if(GetVehicleModel(vehicle_id) == TYPE_TESLA_1)
		return show_electrocar_engine(playerid);

	ApplyAnimation(playerid,"CRIB","CRIB_Use_Switch",4.0,0,0,0,0,0);


	new 
		engine, lights, alarm, doors, bonnet, boot, objective;

	GetVehicleParamsEx(vehicle_id,engine,lights,alarm,doors,bonnet,boot,objective);
	SetVehicleParamsEx(vehicle_id,engine,lights,alarm,doors,true,boot,objective);


    format(GlobalString, sizeof(GlobalString), "\
        "cGREY"Запчасть\t"cGREY"Состояние\t"cGREY"Дата замены\n\
        "cBLUE"- "cWH"Количество масла\t"cGR"%d%%\t"cWH"%s\n\
        "cBLUE"- "cWH"Состояние свечей\t"cGR"%d%%\t"cWH"%s\n\
        "cBLUE"- "cWH"Состояние тормозов\t"cGR"%d%%\t"cWH"%s\n\
        "cBLUE"- "cWH"Состояние ремней\t"cGR"%d%%\t"cWH"%s\n\
        "cBLUE"- "cWH"Состояние стартера\t"cGR"%d%%\t"cWH"%s\n\
        "cBLUE"- "cWH"Состояние генератора\t"cGR"%d%%\t"cWH"%s\n\
        "cBLUE"- "cWH"Состояние форсунок\t"cGR"%d%%\t"cWH"%s\n\
        "cBLUE"- "cWH"Состояние насосов\t"cGR"%d%%\t"cWH"%s\n\
        "cBLUE"\t\n\
        "cBLUE"- "cWH"Пробег автомобиля\t"cGR"%d км", 
        floatround(vehicle[vehicle_id][consumables_oil], floatround_round),
        vehicle[vehicle_id][consumables_candles_date],
        floatround(vehicle[vehicle_id][consumables_candles], floatround_round),
        vehicle[vehicle_id][consumables_oil_date],
		floatround(vehicle[vehicle_id][consumables_brake], floatround_round),
		vehicle[vehicle_id][consumables_brake_date],
		floatround(vehicle[vehicle_id][consumables_belt], floatround_round),
		vehicle[vehicle_id][consumables_belt_date],
		floatround(vehicle[vehicle_id][consumables_starter], floatround_round),
		vehicle[vehicle_id][consumables_starter_date],
		floatround(vehicle[vehicle_id][consumables_generator], floatround_round),
		vehicle[vehicle_id][consumables_generator_date],
		floatround(vehicle[vehicle_id][consumables_forsunki], floatround_round),
		vehicle[vehicle_id][consumables_forsunki_date],
		floatround(vehicle[vehicle_id][consumables_fuel], floatround_round),
		vehicle[vehicle_id][consumables_fuel_date],
		floatround(vehicle[vehicle_id][cMileage], floatround_round));
    return SPD(playerid, DIALOG_ENGINE_STATUS, DIALOG_STYLE_TABLIST_HEADERS, ""cBLUE"Состояние автомобиля:", GlobalString, "Выбрать", "Закрыть"); 


}

stock show_electrocar_engine(playerid)
{
	ApplyAnimation(playerid,"CRIB","CRIB_Use_Switch",4.0,0,0,0,0,0);


	new 
		vehicle_id = pData[playerid][car_id];

	new 
		engine, lights, alarm, doors, bonnet, boot, objective;

	GetVehicleParamsEx(vehicle_id,engine,lights,alarm,doors,bonnet,boot,objective);
	SetVehicleParamsEx(vehicle_id,engine,lights,alarm,doors,true,boot,objective);


    format(GlobalString, sizeof(GlobalString), "\
        "cGREY"Запчасть\t"cGREY"Состояние\t"cGREY"Дата замены\n\
        "cBLUE"- "cWH"Состояние тормозов\t"cGR"%d%%\t"cWH"%s\n\
        "cBLUE"- "cWH"Состояние генератора\t"cGR"%d%%\t"cWH"%s\n\
        "cBLUE"- "cWH"Состояние батареи\t"cGR"%d%%\t"cWH"%s\n\
        "cBLUE"\t\n\
        "cBLUE"- "cWH"Пробег автомобиля\t"cGR"%d км", 
		floatround(vehicle[vehicle_id][consumables_brake], floatround_round),
		vehicle[vehicle_id][consumables_brake_date],
		floatround(vehicle[vehicle_id][cGeneratorEnergy], floatround_round),
		vehicle[vehicle_id][consumables_generator_date],
		floatround(vehicle[vehicle_id][cBatteryEnergy], floatround_round),
		vehicle[vehicle_id][consumables_fuel_date],
		floatround(vehicle[vehicle_id][cMileage], floatround_round));
    return SPD(playerid, DIALOG_ENGINE_STATUS_ELECTRO, DIALOG_STYLE_TABLIST_HEADERS, ""cBLUE"Состояние автомобиля:", GlobalString, "Выбрать", "Закрыть"); 

}

stock dialog_veh_engine_st(playerid, dialogid, response, listitem)
{
	switch(dialogid)
	{ 

		case DIALOG_ENGINE_STATUS_ELECTRO:
		{
			if(!response) 
			{

				new 
					vehicle_id = pData[playerid][car_id];

				new 
					engine, lights, alarm, doors, bonnet, boot, objective;

				GetVehicleParamsEx(vehicle_id,engine,lights,alarm,doors,bonnet,boot,objective);
				SetVehicleParamsEx(vehicle_id,engine,lights,alarm,doors,false,boot,objective);

				return true;
			}	
			
			switch(listitem)
			{
				case 0:
				{
					info_status_electro_veh(playerid, 0);
				}
				case 1:
				{
					info_status_electro_veh(playerid, 1);
				}
				case 2:
				{
					info_status_electro_veh(playerid, 2);
				}
				case 3:
				{
					show_electrocar_engine(playerid);	
				}
				case 4:
				{
					show_electrocar_engine(playerid);						
				}
			}

		}

		case DIALOG_ENGINE_STATUS:
		{
			if(!response) 
			{

				new 
					vehicle_id = pData[playerid][car_id];

				new 
					engine, lights, alarm, doors, bonnet, boot, objective;

				GetVehicleParamsEx(vehicle_id,engine,lights,alarm,doors,bonnet,boot,objective);
				SetVehicleParamsEx(vehicle_id,engine,lights,alarm,doors,false,boot,objective);

				return true;
			}

			switch(listitem)
			{
				case 0:
				{
					info_status_eng_veh(playerid, 0);
				}
				case 1:
				{
					info_status_eng_veh(playerid, 1);
				}
				case 2:
				{
					info_status_eng_veh(playerid, 2);
				}
				case 3:
				{
					info_status_eng_veh(playerid, 3);
				}
	  			case 4:
				{
					info_status_eng_veh(playerid, 4);
				}
	 			case 5:
				{
					info_status_eng_veh(playerid, 5);
				}
				case 6:
				{
					info_status_eng_veh(playerid, 6);
				}
	  			case 7:
				{	
					info_status_eng_veh(playerid, 7);
				}
			}
		}
		case DIALOG_ENGINE_INFO_1:
		{
			if(!response) 
				return show_engine_car(playerid);

			show_engine_car(playerid);		
		}
		case DIALOG_ENGINE_INFO_2:
		{
			if(!response) 
				return show_engine_car(playerid);

			show_engine_car(playerid);			
		}
		case DIALOG_ENGINE_INFO_3:
		{
			if(!response) 
				return show_engine_car(playerid);

			show_engine_car(playerid);		
		}
		case DIALOG_ENGINE_INFO_4:
		{
			if(!response) 
				return show_engine_car(playerid);

			show_engine_car(playerid);		
		}
		case DIALOG_ENGINE_INFO_5:
		{
			if(!response) 
				return show_engine_car(playerid);

			show_engine_car(playerid);		
		}
		case DIALOG_ENGINE_INFO_6:
		{
			if(!response) 
				return show_engine_car(playerid);

			show_engine_car(playerid);		
		}
		case DIALOG_ENGINE_INFO_7:
		{
			if(!response) 
				return show_engine_car(playerid);

			show_engine_car(playerid);		
		}
		case DIALOG_ENGINE_INFO_8:
		{
			if(!response) 
				return show_engine_car(playerid);

			show_engine_car(playerid);		
		}
		case DIALOG_ENG_ELECTRO_INFO_1:
		{
			if(!response) 
				return show_electrocar_engine(playerid);

			show_electrocar_engine(playerid);		
		}	
		case DIALOG_ENG_ELECTRO_INFO_2:
		{
			if(!response) 
				return show_electrocar_engine(playerid);

			show_electrocar_engine(playerid);	
		}	
		case DIALOG_ENG_ELECTRO_INFO_3:
		{
			if(!response) 
				return show_electrocar_engine(playerid);

			show_electrocar_engine(playerid);				
		}
	}
	return true;	
}

stock info_status_electro_veh(playerid, type)
{
	switch(type)
	{
		case 0:
		{
            format(GlobalString, sizeof(GlobalString), "\
                "cBLUE"Тормоза"cWH" — недаром говорят, что тормозная система авто \n\
                является практически настолько же важной, сколько система рулевого управления или двигатель. \n\
                Во многом от исправности и эффективности работы тормозов зависит безопасность \n\
                как водителя, так и его пассажиров\n\n\
                (( Произвести замену можно на любой станции Технического Обслуживания или в Гараже ))");
            SPD(playerid, DIALOG_ENG_ELECTRO_INFO_1, DIALOG_STYLE_MSGBOX, ""cBLUE"Тормоза:", GlobalString, "Понятно", "");

		}
		case 1:
		{
            format(GlobalString, sizeof(GlobalString), "\
                "cBLUE"Генератор"cWH" — источник питания для всех его приборов, узлов и агрегатов, \n\
                которые нуждаются в электропитании. \n\
                Именно генератор питает все световые и звуковые элементы, а на электромобилях производит\n\
                генерацию энергии и увеличивает запас хода автомобиля на несколько километров\n\n\
                "cBLUE"(( Произвести замену можно на любой станции Технического Обслуживания или в Гараже ))");
            SPD(playerid, DIALOG_ENG_ELECTRO_INFO_2, DIALOG_STYLE_MSGBOX, ""cBLUE"Генератор:", GlobalString, "Понятно", "");
		}	
		case 2:
		{
            format(GlobalString, sizeof(GlobalString), "\
                "cBLUE"Батарея"cWH" — источник питания для электромобиля, позволяет ему ехать! \n\n\
                Замена АКБ осуществляется исключительно мастером на специализированном сервисе технического обслуживания (СТО)\n\
                Во время переустановки необходимо правильно подключить все разъёмы и соединиться с бортовым компьютером\n\
                Только правильная настройка гарантирует хорошую работу электромашины\n\n\
                "cBLUE"(( Произвести замену можно на любой станции Технического Обслуживания или в Гараже ))");
            SPD(playerid, DIALOG_ENG_ELECTRO_INFO_3, DIALOG_STYLE_MSGBOX, ""cBLUE"Батарея:", GlobalString, "Понятно", "");
		}
	}	

	return true;
}

stock info_status_eng_veh(playerid, type)
{

	switch(type)
	{
		case 0:
		{
            format(GlobalString, sizeof(GlobalString), "\
                "cBLUE"Масло в двигателе"cWH" — в современных двигателях моторное масло фактически \n\
                является гидравлической жидкостью для всех узлов и механизмов внутри ДВС. \n\
                Ответить на вопрос, зачем двигателю моторное масло, можно достаточно просто. \n\
                Смазочная жидкость защищает детали и трущиеся поверхности от сухого трения, \n\
                формируя на них устойчивую масляную пленку. Однако и это еще не все. \n\
                Указанная пленка создает защиту от ржавчины, а также минимизирует воздействие на детали \n\
                различных химически активных компонентов, которые неизбежно образуются в процессе работы двигателя\n\n\
                (( Произвести замену можно на любой станции Технического Обслуживания или в Гараже ))");
            SPD(playerid, DIALOG_ENGINE_INFO_1, DIALOG_STYLE_MSGBOX, ""cBLUE"Масло:", GlobalString, "Понятно", "");
		}
		case 1:
		{
            format(GlobalString, sizeof(GlobalString), "\
                "cBLUE"Свечи"cWH" — они обеспечивают образование искры для воспламенения\n\
                бензина в камере сгорания мотора. Немного истории.\n\
				Первые двс оснащались трубками накала с открытым огнем. \n\
				В 1902 году Роберт Бош предложил Карлу Бенцу установить в его моторы свою разработку. \n\
				Деталь имела практически ту же конструкцию и работала по такому же принципу, что и современные аналоги. \n\
				На протяжении истории они претерпевали незначительные изменения, \n\
				которые касались материалов для проводника и диэлектрика\n\n\
                "cBLUE"(( Произвести замену можно на любой станции Технического Обслуживания или в Гараже ))");
            SPD(playerid, DIALOG_ENGINE_INFO_2, DIALOG_STYLE_MSGBOX, ""cBLUE"Свечи:", GlobalString, "Понятно", "");
		}
		case 2:
		{
            format(GlobalString, sizeof(GlobalString), "\
                "cBLUE"Тормоза"cWH" — недаром говорят, что тормозная система авто \n\
                является практически настолько же важной, сколько система рулевого управления или двигатель. \n\
                Во многом от исправности и эффективности работы тормозов зависит безопасность \n\
                как водителя, так и его пассажиров\n\n\
                (( Произвести замену можно на любой станции Технического Обслуживания или в Гараже ))");
            SPD(playerid, DIALOG_ENGINE_INFO_3, DIALOG_STYLE_MSGBOX, ""cBLUE"Тормоза:", GlobalString, "Понятно", "");
		}	
		case 3:
		{
            format(GlobalString, sizeof(GlobalString), "\
                "cBLUE"Ремни"cWH" — в современных моторах довольно много различного навесного оборудования, \n\
                которое требует наличия привода. Чтобы не ставить на каждый агрегат отдельный моторчик,\n\
                 все узлы такие как ГУР, генератор, кондиционер, водяная помпа и т. д. они приводятся в движение при помощи ремней\n\n\
                "cBLUE"(( Произвести замену можно на любой станции Технического Обслуживания или в Гараже ))");
            SPD(playerid, DIALOG_ENGINE_INFO_4, DIALOG_STYLE_MSGBOX, ""cBLUE"Ремни:", GlobalString, "Понятно", "");
		}	
		case 4:
		{
            format(GlobalString, sizeof(GlobalString), "\
                "cBLUE"Стартер"cWH" — механизм, назначение которого заключается в воздействии \n\
                на коленвал с целью его прокручивания, необходимого для запуска двигателя\n\n\
                (( Произвести замену можно на любой станции Технического Обслуживания или в Гараже ))");
            SPD(playerid, DIALOG_ENGINE_INFO_5, DIALOG_STYLE_MSGBOX, ""cBLUE"Стартер:", GlobalString, "Понятно", "");
		}
		case 5:
		{
            format(GlobalString, sizeof(GlobalString), "\
                "cBLUE"Генератор"cWH" — источник питания для всех его приборов, узлов и агрегатов, \n\
                которые нуждаются в электропитании. \n\
                Именно генератор питает все световые и звуковые элементы\n\n\
                "cBLUE"(( Произвести замену можно на любой станции Технического Обслуживания или в Гараже ))");
            SPD(playerid, DIALOG_ENGINE_INFO_6, DIALOG_STYLE_MSGBOX, ""cBLUE"Генератор:", GlobalString, "Понятно", "");
		}
		case 6:
		{
            format(GlobalString, sizeof(GlobalString), "\
                "cBLUE"Форсунки"cWH" — основная функция насос-форсунок — это создавать высокое давления \n\
                дизельного топлива для впрыска в камеру сгорания, \n\
                причем в определенный момент и четкое его количество, которые задаются ЭБУ\n\n\
                "cBLUE"(( Произвести замену можно на любой станции Технического Обслуживания или в Гараже ))");
            SPD(playerid, DIALOG_ENGINE_INFO_7, DIALOG_STYLE_MSGBOX, ""cBLUE"Форсунки:", GlobalString, "Понятно", "");
		}	
		case 7:
		{
            format(GlobalString, sizeof(GlobalString), "\
                "cBLUE"Насос"cWH" — любая циркуляция жидкости в автомобиле осуществляется принудительно. \n\
                Помпа или насос служит для обеспечения работы охлаждающей системы. \n\
                Помпой автомобилисты называют насос, работающий совместно с двигателем\n\n\
                "cBLUE"(( Произвести замену можно на любой станции Технического Обслуживания или в Гараже ))");
            SPD(playerid, DIALOG_ENGINE_INFO_8, DIALOG_STYLE_MSGBOX, ""cBLUE"Насос:", GlobalString, "Понятно", "");
		}	
	}
	return true;
}

stock show_circle_menu_veh(playerid)
{

	if(GetPVarIntNew(playerid, "circ_veh_menu_active") != 1)
	{

		new 
			vehicle_id = pData[playerid][car_id];

		GetVehiclePos(vehicle_id, ACVehInfo[vehicle_id][acPosX], ACVehInfo[vehicle_id][acPosY], ACVehInfo[vehicle_id][acPosZ]);

		if(!IsPlayerInRangeOfPoint(playerid, 5.0, ACVehInfo[vehicle_id][acPosX], ACVehInfo[vehicle_id][acPosY], ACVehInfo[vehicle_id][acPosZ]))
			return SCM(playerid, COLOR_BLUE, "Подсказка: "cWH"Вы слишком далеко от транспорта!");

		SetPVarIntNew(playerid, "circ_veh_menu_active", 1);

	    new engine, lights, alarm, doors, bonnet, boot, objective;
	    GetVehicleParamsEx(vehicle_id, engine, lights, alarm, doors, bonnet, boot, objective);

		if(GetVehicleModel(vehicle_id) == TYPE_TESLA_1)
		{
			create_veh_circle_electro(playerid);

			PlayerTextDrawShow(playerid, circle_menu_veh_electro[playerid][0]);

			if(lights)
			{
				PlayerTextDrawSetString(playerid, circle_menu_veh_electro[playerid][4], "brp:circle_veh_light_on");
			}
			else
			{
				PlayerTextDrawSetString(playerid, circle_menu_veh_electro[playerid][4], "brp:circle_veh_light_off");
			}
			PlayerTextDrawShow(playerid, circle_menu_veh_electro[playerid][4]);

			if(engine)
			{
				PlayerTextDrawSetString(playerid, circle_menu_veh_electro[playerid][5], "brp:circle_veh_eng_on");
			}
			else
			{
				PlayerTextDrawSetString(playerid, circle_menu_veh_electro[playerid][5], "brp:circle_veh_eng_off");			
			}
			PlayerTextDrawShow(playerid, circle_menu_veh_electro[playerid][5]);

			if(doors)
			{
				PlayerTextDrawSetString(playerid, circle_menu_veh_electro[playerid][1], "brp:circle_veh_door_open");
			}
			else
			{
				PlayerTextDrawSetString(playerid, circle_menu_veh_electro[playerid][1], "brp:circle_veh_door_close");			
			}
			PlayerTextDrawShow(playerid, circle_menu_veh_electro[playerid][1]);

			if(bonnet)
			{
				PlayerTextDrawSetString(playerid, circle_menu_veh_electro[playerid][2], "brp:circle_veh_capot_open");
			}
			else
			{
				PlayerTextDrawSetString(playerid, circle_menu_veh_electro[playerid][2], "brp:circle_veh_capot_close");			
			}
			PlayerTextDrawShow(playerid, circle_menu_veh_electro[playerid][2]);

			if(boot)
			{
				PlayerTextDrawSetString(playerid, circle_menu_veh_electro[playerid][3], "brp:circle_veh_bagage_open");
			}
			else
			{
				PlayerTextDrawSetString(playerid, circle_menu_veh_electro[playerid][3], "brp:circle_veh_bagage_close");			
			}

			PlayerTextDrawShow(playerid, circle_menu_veh_electro[playerid][3]);			

			PlayerTextDrawShow(playerid, circle_menu_veh_electro[playerid][6]);	

			SelectTextDraw(playerid, COLOR_BLUE);

			return true;
		}
	}
	else
	{
		CancelSelectTextDraw(playerid);
		DeletePVarNew(playerid, "circ_veh_menu_active");
		
		PlayerTextDrawHideEx(playerid, circle_menu_veh_electro[playerid][0]);
		PlayerTextDrawHideEx(playerid, circle_menu_veh_electro[playerid][1]);
		PlayerTextDrawHideEx(playerid, circle_menu_veh_electro[playerid][2]);
		PlayerTextDrawHideEx(playerid, circle_menu_veh_electro[playerid][3]);
		PlayerTextDrawHideEx(playerid, circle_menu_veh_electro[playerid][4]);
		PlayerTextDrawHideEx(playerid, circle_menu_veh_electro[playerid][5]);
		PlayerTextDrawHideEx(playerid, circle_menu_veh_electro[playerid][6]);	
	}
	return true;
}

stock circle_veh_textdraw_select(playerid, PlayerText:clickedid)
{
	new 
		vehicle_id;

	foreach(new v:vehicle_in_stream[playerid])
	{	

		new
			Float:pl_pos_x,
			Float:pl_pos_y,
			Float:pl_pos_z;

		GetPlayerPos(playerid, pl_pos_x, pl_pos_y, pl_pos_z);


		if(IsVehicleInRangeOfPoint(v, 7.0, pl_pos_x, pl_pos_y, pl_pos_z)) {}
			else continue;
		
		for(new i; i < 3; i++)
		{
			if(v == vehicle_player_max[playerid][i])
			{
				vehicle_id = vehicle_player_max[playerid][i];
				break;
			}
		}
	}

    new engine, lights, alarm, doors, bonnet, boot, objective;

	if(clickedid == player_veh_key[1][playerid])
	{

		GetVehicleParamsEx(vehicle_id, engine, lights, alarm, doors, bonnet, boot, objective);
	    if(boot)
	    {
	    	SetVehicleParamsEx(vehicle_id, engine, lights, alarm, doors, bonnet, false, objective);
	    	PlayerTextDrawSetString(playerid, player_veh_key[1][playerid], "brckey:key_td_trunkoff");
	    	PlayerTextDrawShow(playerid, player_veh_key[1][playerid]);    	
	    }
	    else
	    {
	    	SetVehicleParamsEx(vehicle_id, engine, lights, alarm, doors, bonnet, true, objective);
	    	PlayerTextDrawSetString(playerid, player_veh_key[1][playerid], "brckey:key_td_trunkon");
	    	PlayerTextDrawShow(playerid, player_veh_key[1][playerid]);
	    }
	}

	else if(clickedid == player_veh_key[2][playerid])
	{
		GetVehicleParamsEx(vehicle_id, engine, lights, alarm, doors, bonnet, boot, objective);

	    if(bonnet)
	    {
	    	SetVehicleParamsEx(vehicle_id, engine, lights, alarm, doors, false, boot, objective);
	    	PlayerTextDrawSetString(playerid, player_veh_key[2][playerid], "brckey:key_td_hoodoff");
	    	PlayerTextDrawShow(playerid, player_veh_key[2][playerid]);		    
	    }
	    else
	    {
	    	SetVehicleParamsEx(vehicle_id, engine, lights, alarm, doors, true, boot, objective);		
	    	PlayerTextDrawSetString(playerid, player_veh_key[2][playerid], "brckey:key_td_hoodon");
	    	PlayerTextDrawShow(playerid, player_veh_key[2][playerid]);
	    }
	}
	else if(clickedid ==  player_veh_key[3][playerid])
	{

	    GetVehicleParamsEx(vehicle_id, engine, lights, alarm, doors, bonnet, boot, objective);

	    if(lights)
	    {
	    	SetVehicleParamsEx(vehicle_id, engine, false, alarm, doors, bonnet, boot, objective);
	    	PlayerTextDrawSetString(playerid, player_veh_key[3][playerid], "brckey:key_td_lightoff");
	    	PlayerTextDrawShow(playerid, player_veh_key[3][playerid]);
	    }
	    else
	    {
	    	SetVehicleParamsEx(vehicle_id, engine, true, alarm, doors, bonnet, boot, objective);	
	    	PlayerTextDrawSetString(playerid, player_veh_key[3][playerid], "brckey:key_td_lighton");
	    	PlayerTextDrawShow(playerid, player_veh_key[3][playerid]);
	    }
	}
	else if(clickedid == player_veh_key[0][playerid])
	{
		PC_EmulateCommand(playerid, "/lock");

		GetVehicleParamsEx(vehicle_id, engine, lights, alarm, doors, bonnet, boot, objective);

		if(doors)
		{
	    	PlayerTextDrawSetString(playerid, player_veh_key[0][playerid], "brckey:key_td_lock");
	    	PlayerTextDrawShow(playerid, player_veh_key[0][playerid]);

    	}
    	else
    	{
	    	PlayerTextDrawSetString(playerid, player_veh_key[0][playerid], "brckey:key_td_unlock");
	    	PlayerTextDrawShow(playerid, player_veh_key[0][playerid]);
    	}	
	}

	else if(clickedid == player_veh_key[4][playerid])
	{
		PC_EmulateCommand(playerid, "/en");	


		GetVehicleParamsEx(vehicle_id, engine, lights, alarm, doors, bonnet, boot, objective);

		if(engine)
		{
    		PlayerTextDrawSetString(playerid, player_veh_key[4][playerid], "brckey:key_td_engineon");
    		PlayerTextDrawShow(playerid, player_veh_key[4][playerid]);	
    	}
    	else
    	{
    		PlayerTextDrawSetString(playerid, player_veh_key[4][playerid], "brckey:key_td_engineoff");		
    		PlayerTextDrawShow(playerid, player_veh_key[4][playerid]);	
    	}	

	}
	return true;
}

stock circle_veh_textdraw_select_el(playerid, Text:clickedid)
{
	new 
		vehicle_id;

	foreach(new v:vehicle_in_stream[playerid])
	{	

		new
			Float:pl_pos_x,
			Float:pl_pos_y,
			Float:pl_pos_z;

		GetPlayerPos(playerid, pl_pos_x, pl_pos_y, pl_pos_z);


		if(IsVehicleInRangeOfPoint(v, 7.0, pl_pos_x, pl_pos_y, pl_pos_z)) {}
			else continue;
		
		for(new i; i < 3; i++)
		{
			if(v == vehicle_player_max[playerid][i])
			{
				vehicle_id = vehicle_player_max[playerid][i];
				break;
			}
		}
	}

    new engine, lights, alarm, doors, bonnet, boot, objective;

	if(clickedid == key_vehicle_electrog[2])
	{

		GetVehicleParamsEx(vehicle_id, engine, lights, alarm, doors, bonnet, boot, objective);
	    if(boot)
	    {
	    	SetVehicleParamsEx(vehicle_id, engine, lights, alarm, doors, bonnet, false, objective);
	    	PlayerTextDrawSetString(playerid, key_vehicle_electro[1][playerid], "brckey:key_td_e_trunkoff");
	    	PlayerTextDrawShow(playerid, key_vehicle_electro[1][playerid]);    	
	    }
	    else
	    {
	    	SetVehicleParamsEx(vehicle_id, engine, lights, alarm, doors, bonnet, true, objective);
	    	PlayerTextDrawSetString(playerid, key_vehicle_electro[1][playerid], "brckey:key_td_e_trunkon");
	    	PlayerTextDrawShow(playerid, key_vehicle_electro[1][playerid]);
	    }
	}

	else if(clickedid == key_vehicle_electrog[3])
	{
		GetVehicleParamsEx(vehicle_id, engine, lights, alarm, doors, bonnet, boot, objective);

	    if(bonnet)
	    {
	    	SetVehicleParamsEx(vehicle_id, engine, lights, alarm, doors, false, boot, objective);
	    	PlayerTextDrawSetString(playerid, key_vehicle_electro[2][playerid], "brckey:key_td_e_hoodoff");
	    	PlayerTextDrawShow(playerid, key_vehicle_electro[2][playerid]);		    
	    }
	    else
	    {
	    	SetVehicleParamsEx(vehicle_id, engine, lights, alarm, doors, true, boot, objective);		
	    	PlayerTextDrawSetString(playerid, key_vehicle_electro[playerid][2], "brckey:key_td_e_hoodon");
	    	PlayerTextDrawShow(playerid, key_vehicle_electro[2][playerid]);
	    }
	}
	else if(clickedid ==  key_vehicle_electrog[4])
	{

	    GetVehicleParamsEx(vehicle_id, engine, lights, alarm, doors, bonnet, boot, objective);

	    if(lights)
	    {
	    	SetVehicleParamsEx(vehicle_id, engine, false, alarm, doors, bonnet, boot, objective);
	    	PlayerTextDrawSetString(playerid, key_vehicle_electro[3][playerid], "brckey:key_td_e_lightoff");
	    	PlayerTextDrawShow(playerid, key_vehicle_electro[3][playerid]);
	    }
	    else
	    {
	    	SetVehicleParamsEx(vehicle_id, engine, true, alarm, doors, bonnet, boot, objective);	
	    	PlayerTextDrawSetString(playerid, key_vehicle_electro[3][playerid], "brckey:key_td_e_lighton");
	    	PlayerTextDrawShow(playerid, key_vehicle_electro[3][playerid]);
	    }
	}
	else if(clickedid == key_vehicle_electrog[1])
	{
		PC_EmulateCommand(playerid, "/lock");

		GetVehicleParamsEx(vehicle_id, engine, lights, alarm, doors, bonnet, boot, objective);

		if(doors)
		{
	    	PlayerTextDrawSetString(playerid, key_vehicle_electro[0][playerid], "brckey:key_td_e_lock");
	    	PlayerTextDrawShow(playerid, key_vehicle_electro[0][playerid]);

    	}
    	else
    	{
	    	PlayerTextDrawSetString(playerid, key_vehicle_electro[0][playerid], "brckey:key_td_e_unlock");
	    	PlayerTextDrawShow(playerid, key_vehicle_electro[0][playerid]);
    	}	
	}

	else if(clickedid == key_vehicle_electrog[5])
	{
		PC_EmulateCommand(playerid, "/en");	


		GetVehicleParamsEx(vehicle_id, engine, lights, alarm, doors, bonnet, boot, objective);

		if(engine)
		{
			SetVehicleParamsEx(vehicle_id, true, lights, alarm, doors, bonnet, boot, objective);
    		PlayerTextDrawSetString(playerid, key_vehicle_electro[4][playerid], "brckey:key_td_e_engineon");
    		PlayerTextDrawShow(playerid, key_vehicle_electro[playerid][4]);	
    	}
    	else
    	{
    		SetVehicleParamsEx(vehicle_id, false, lights, alarm, doors, bonnet, boot, objective);
    		PlayerTextDrawSetString(playerid, key_vehicle_electro[4][playerid], "brckey:key_td_e_engineoff");		
    		PlayerTextDrawShow(playerid, key_vehicle_electro[playerid][4]);	
    	}	

	}
	return true;
}

CMD:pts(playerid)
{
	new 
		vehicle_id = pData[playerid][car_id];

	if(vehicle_id == INVALID_VEHICLE_ID)
		return true;

	if(GetVehicleModel(vehicle_id) != 466)
	{
		show_pts_player(playerid, playerid);
	}
	else
	{
		show_pts_player_electro(playerid, playerid);
	}

	return true;
}


stock show_pts_player(playerid, to_playerid)
{
	new 
		vehicle_id = pData[playerid][car_id];

	if(vehicle_id == INVALID_VEHICLE_ID)
		return true;

	new 
		car_owner[32];

	GetPlayerNameByID(pData[playerid][car_sql_owner], car_owner);


	format(GlobalString, sizeof(GlobalString),  "\
	"cBLUE"Тип: 		 	"cWH"\t\t%s\n\
	"cBLUE"Модель: 		 	"cWH"\t\t%s\n\
	"cBLUE"Владелец: 	 	"cWH"\t%s\n\
	"cBLUE"Гос.номер: 	 	"cWH"\t%s\n\n\
	"cBLUE"Дата покупки: 	"cWH"\t%s\n\n\
	"cBLUE"Тип топлива: 	"cWH"\t%s\n\
	"cBLUE"Объём бака: 		"cWH"\t%d л\n\
	"cBLUE"Маск.скорость: 	"cWH"\t%d КМ/Ч", GetVehicleTypes(vehicle_id), transport_config[GetVehicleModel(vehicle_id)-400][transport_name], 
	car_owner, vehicle[vehicle_id][cPlate], vehicle[vehicle_id][buy_date_car], get_fuel_type_veh(GetVehicleModel(vehicle_id)-400), transport_config[GetVehicleModel(vehicle_id)-400][transport_tank], transport_config[GetVehicleModel(vehicle_id)-400][transport_max_speed]);
	
	return SPD(playerid, 0, DIALOG_STYLE_MSGBOX, ""cBLUE"Документы на автомобиль", GlobalString, "Закрыть", "");
}

stock show_pts_player_electro(playerid, to_playerid)
{
	new 
		vehicle_id = pData[playerid][car_id];

	new 
		car_owner[32];

	GetPlayerNameByID(pData[playerid][car_sql_owner], car_owner);

	format(GlobalString, sizeof(GlobalString),  "\
	"cBLUE"Тип: 		 	"cWH"\t\t%s\n\
	"cBLUE"Модель: 		 	"cWH"\t\t%s\n\
	"cBLUE"Владелец: 	 	"cWH"\t%s\n\
	"cBLUE"Гос.номер: 	 	"cWH"\t%s\n\n\
	"cBLUE"Дата покупки: 	"cWH"\t%s\n\n\
	"cBLUE"Ёмкость батареи: "cWH"\t%d КВТ.ч\n\
	"cBLUE"Маск.скорость: 	"cWH"\t%d КМ/Ч", GetVehicleTypes(vehicle_id), transport_config[GetVehicleModel(vehicle_id)-400][transport_name], 
	car_owner, vehicle[vehicle_id][cPlate], vehicle[vehicle_id][buy_date_car], transport_config[GetVehicleModel(vehicle_id)-400][transport_tank], transport_config[GetVehicleModel(vehicle_id)-400][transport_max_speed]);
	
	return SPD(playerid, 0, DIALOG_STYLE_MSGBOX, ""cBLUE"Документы на автомобиль", GlobalString, "Закрыть", "");
}


stock create_circle_menu_veh()
{
	circle_menu[0] = TextDrawCreate(403.750183, 251.999908, "brp:brelok_car_background"); // Texture element
	TextDrawLetterSize(circle_menu[0], 0.000000, 0.000000);
	TextDrawTextSize(circle_menu[0], 281.249938, 178.370483);
	TextDrawAlignment(circle_menu[0], 1);
	TextDrawColor(circle_menu[0], -1);
	TextDrawSetShadow(circle_menu[0], 0);
	TextDrawSetOutline(circle_menu[0], 0);
	TextDrawFont(circle_menu[0], 4);

	circle_menu[1] = TextDrawCreate(490.833374, 353.110961, "brp:brelok_car_bagage"); // Texture element
	TextDrawLetterSize(circle_menu[1], 0.000000, 0.000000);
	TextDrawTextSize(circle_menu[1], 21.249990, 24.370378);
	TextDrawAlignment(circle_menu[1], 2);
	TextDrawColor(circle_menu[1], -1);
	TextDrawSetShadow(circle_menu[1], 0);
	TextDrawSetOutline(circle_menu[1], 0);
	TextDrawFont(circle_menu[1], 4);
	TextDrawSetSelectable(circle_menu[1], true);

	circle_menu[2] = TextDrawCreate(514.999816, 354.148010, "brp:brelok_car_capot"); // Texture element
	TextDrawLetterSize(circle_menu[2], 0.000000, 0.000000);
	TextDrawTextSize(circle_menu[2], 21.249990, 24.370378);
	TextDrawAlignment(circle_menu[2], 2);
	TextDrawColor(circle_menu[2], -1);
	TextDrawUseBox(circle_menu[2], true);
	TextDrawBoxColor(circle_menu[2], 0);
	TextDrawSetShadow(circle_menu[2], 0);
	TextDrawSetOutline(circle_menu[2], 0);
	TextDrawFont(circle_menu[2], 4);
	TextDrawSetSelectable(circle_menu[2], true);

	circle_menu[3] = TextDrawCreate(540.833007, 355.703582, "brp:brelok_car_door"); // Texture element
	TextDrawLetterSize(circle_menu[3], 0.000000, 0.000000);
	TextDrawTextSize(circle_menu[3], 20.416658, 23.333341);
	TextDrawAlignment(circle_menu[3], 2);
	TextDrawColor(circle_menu[3], -1);
	TextDrawSetShadow(circle_menu[3], 0);
	TextDrawSetOutline(circle_menu[3], 0);
	TextDrawFont(circle_menu[3], 4);
	TextDrawSetSelectable(circle_menu[3], true);

	circle_menu[4] = TextDrawCreate(565.832946, 355.703582, "brp:brelok_car_light"); // Texture element
	TextDrawLetterSize(circle_menu[4], 0.000000, 0.000000);
	TextDrawTextSize(circle_menu[4], 17.499990, 21.259267);
	TextDrawAlignment(circle_menu[4], 2);
	TextDrawColor(circle_menu[4], -1);
	TextDrawSetShadow(circle_menu[4], 0);
	TextDrawSetOutline(circle_menu[4], 0);
	TextDrawFont(circle_menu[4], 4);
	TextDrawSetSelectable(circle_menu[4], true);

	circle_menu[5] = TextDrawCreate(587.499328, 355.185058, "brp:brelok_car_eng"); // Texture element
	TextDrawLetterSize(circle_menu[5], 0.000000, 0.000000);
	TextDrawTextSize(circle_menu[5], 17.499990, 21.259267);
	TextDrawAlignment(circle_menu[5], 2);
	TextDrawColor(circle_menu[5], -1);
	TextDrawSetShadow(circle_menu[5], 0);
	TextDrawSetOutline(circle_menu[5], 0);
	TextDrawFont(circle_menu[5], 4);
	TextDrawSetSelectable(circle_menu[5], true);

	circle_menu[6] = TextDrawCreate(550.000122, 291.925994, "11:23"); // Text element
	TextDrawLetterSize(circle_menu[6], 0.582083, 2.087407);
	TextDrawAlignment(circle_menu[6], 2);
	TextDrawColor(circle_menu[6], 623191551);
	TextDrawUseBox(circle_menu[6], true);
	TextDrawBoxColor(circle_menu[6], 0);
	TextDrawSetShadow(circle_menu[6], 0);
	TextDrawSetOutline(circle_menu[6], 0);
	TextDrawBackgroundColor(circle_menu[6], 51);
	TextDrawFont(circle_menu[6], 1);
	TextDrawSetProportional(circle_menu[6], 1);

	return true;
}

callback:: load_all_config_vehSQL()
{
	new 
		all_transport_info 	= 0,
		time 				= GetTickCount();

	cache_get_row_count(all_transport_info);
 	for(new i = 0; i < all_transport_info; i++)
	{
		cache_get_value_name_int(i, "transport_id", transport_config[i][transport_id_sql]); 
		cache_get_value_name(i,"transport_name", transport_config[i][transport_name], 35);
		cache_get_value_name_int(i, "transport_model", transport_config[i][transport_model]); 	
		cache_get_value_name_int(i, "transport_price", transport_config[i][transport_price]); 	
		cache_get_value_name_int(i, "transport_tank", transport_config[i][transport_tank]);  	
		cache_get_value_name_int(i, "transport_class", transport_config[i][transport_class]); 
		cache_get_value_name_int(i, "transport_fuel_active", transport_config[i][transport_fuel_active]);  	
		cache_get_value_name_int(i, "transport_sell_active", transport_config[i][transport_sell_active]); 	
		cache_get_value_name_int(i, "transport_taxi_active", transport_config[i][transport_taxi_active]);  	
		cache_get_value_name_int(i, "transport_max_speed",transport_config[i][transport_max_speed]);  		
		cache_get_value_name_int(i, "transport_fuel_type",transport_config[i][transport_fuel_type]);  	 
		cache_get_value_name_int(i, "transport_fuel_count_km",transport_config[i][transport_fuel_count_km]); 
		cache_get_value_name_int(i, "transport_price_rent",transport_config[i][transport_price_rent]); 
		cache_get_value_name_int(i, "transport_count_pass",transport_config[i][transport_count_pass]); 
		cache_get_value_name_float(i, "transport_engine_inertion",transport_config[i][transport_engine_inertion]); 
		cache_get_value_name_float(i, "transport_handling_speed",transport_config[i][transport_handling_speed]); 
		cache_get_value_name_float(i, "transport_handling_mass",transport_config[i][transport_handling_mass]);  
		cache_get_value_name_float(i, "transport_handling_mass_turn",transport_config[i][transport_handling_mass_turn]); 
		cache_get_value_name_float(i, "transport_handling_acceleration",transport_config[i][transport_handling_acceleration]);  
		cache_get_value_name_float(i, "transport_handling_gear",transport_config[i][transport_handling_gear]); 
		cache_get_value_name_float(i, "transport_brake_deceleration",transport_config[i][transport_brake_deceleration]); 
		cache_get_value_name_float(i, "transport_traction_multiplier",transport_config[i][transport_traction_multiplier]); 
		cache_get_value_name_float(i, "transport_traction_loss",transport_config[i][transport_traction_loss]); 
		cache_get_value_name_float(i, "transport_traction_bias",transport_config[i][transport_traction_bias]); 
		cache_get_value_name_float(i, "transport_suspension_bias",transport_config[i][transport_suspension_bias]); 
		cache_get_value_name_float(i, "transport_wheel_size",transport_config[i][transport_wheel_size]); 
		cache_get_value_name_float(i, "transport_suspension_limit",transport_config[i][transport_suspension_limit]); 
		cache_get_value_name_int(i, "transport_wheel_angle",transport_config[i][transport_wheel_angle]); 
		cache_get_value_name_int(i, "transport_wheel_offset",transport_config[i][transport_wheel_offset]); 
		cache_get_value_name_int(i, "transport_wheel_width",transport_config[i][transport_wheel_width]); 
	}
	printf("[Конфиг Авто]: <%i из %i>. Времени затрачено: <%d мс>" ,all_transport_info, 611, GetTickCount() -  time);

	return 1;
}


stock load_all_config_veh()
{
	mysql_tquery(connect_main, "SELECT * FROM `transport` ORDER BY `transport_id`", "load_all_config_vehSQL", "");
}

callback:: create_all_config_veh()
{
	new 
		transport_models = 400,
		count = 0;

	new time = GetTickCount();
	
	for(new i; i < 212; i++)
	{
		mysql_format(connect_main, GlobalString, sizeof(GlobalString),"INSERT INTO `transport` (`transport_id`, `transport_model`) VALUES ('%d', '%d')", count, transport_models);
		mysql_tquery(connect_main, GlobalString, "", "");	

		count++;
		transport_models++;	
	}
	printf("[Авто были добавлены]: <%d из %d>. Времени затрачено: <%d мс>" , transport_models, 611, GetTickCount() -  time);

	return true;
}

CMD:insert_config_car(playerid)
{
	if(pData[playerid][pAdmin] < 8) 
		return true;

	return create_all_config_veh();
}

CMD:reload_config_car(playerid)
{
	if(pData[playerid][pAdmin] < 8) 
		return true;

	load_all_config_veh();
	return 1;
}

CMD:config_car(playerid, params[])
{
	if(pData[playerid][pAdmin] < 7) 
		return true;

	if(!strcmp(pData[playerid][pNickname], "Misha_Kravcov"))
		return SendInf(playerid, "Миша, ну его нахуй, иди поспи, сломаешь еще что-нибудь!");

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/config_car [Модель авто]");		

	if(params[0] > 211 || params[0] < 0) 
		return SendErr(playerid, "Ид транспорта от 0 (0 - ЭТО 1 В БД И 400 МОДЕЛЬ) до 211!");


	SetPVarIntNew(playerid, "select_model_car", params[0]);

	dialog_config_car(playerid);

	return true;
}

stock get_class_veh(h)
{
	new 
		name[20];

	new 
		class = transport_config[h][transport_class];	

	switch(class)
	{
		case 1: name = "Низкий";
		case 2: name = "Средний";
		case 3: name = "Высокий";
		case 4: name = "Элитный";
		default: name = "Заброшенный";
	}
	return name;
}

stock get_fuel_type_veh(h)
{
	new 
		name[20];

	new 
		class = transport_config[h][transport_fuel_type];	

	switch(class)
	{
		case 1: name = "АИ-92";
		case 2: name = "АИ-95";
		case 3: name = "АИ-98";
		case 4: name = "ДТ";
		default: name = "Неизвестно";
	}
	return name;
}



stock dialog_config_car(playerid)
{
	new 
		model_car = GetPVarIntNew(playerid, "select_model_car");

    format(GlobalString, sizeof(GlobalString), "\
        "cGREY"Пункт\t"cGREY"Информация\n\
        "cBLUE"- "cWH"Модель автомобиля\t"cBLUE"%d\n\
        "cBLUE"- "cWH"Наименование модели\t"cBLUE"%s\n\
        "cBLUE"- "cWH"Гос.цена автомобиля\t"cGR"%d рублей\n\
        "cBLUE"- "cWH"Объем бензобака автомобиля\t"cGR"%d литров\n\
        "cBLUE"- "cWH"Класс автомобиля\t"cBLUE"%s\n\
        "cBLUE"- "cWH"Возможность заправки\t"cBLUE"%s\n\
        "cBLUE"- "cWH"Возможность продажи\t"cBLUE"%s\n\
        "cBLUE"- "cWH"Возможность таксовать\t"cBLUE"%s\n\
        "cBLUE"- "cWH"Тип топлива\t"cBLUE"%s\n\
        "cBLUE"- "cWH"Максимальная скорость\t"cBLUE"%d KM/Ч\n\
        "cBLUE"- "cWH"Расход топлива\t"cBLUE"%dл на 100 км\n\
        "cBLUE"- "cWH"Стоимость аренды\t"cGR"%d рублей\n\
        "cBLUE"- "cWH"Количество мест в салоне\t"cBLUE"%d мест", 
        transport_config[model_car][transport_model],
        transport_config[model_car][transport_name],
        transport_config[model_car][transport_price],
        transport_config[model_car][transport_tank],
        get_class_veh(model_car),
        (transport_config[model_car][transport_fuel_active] == 1) ? (""cGR"Доступна") : (""cLRED"Отсутствует"),
        (transport_config[model_car][transport_sell_active] == 1) ? (""cGR"Доступна") : (""cLRED"Отсутствует"),
        (transport_config[model_car][transport_taxi_active] == 1) ? (""cGR"Доступна") : (""cLRED"Отсутствует"),
       	get_fuel_type_veh(model_car),
       	transport_config[model_car][transport_max_speed],
       	transport_config[model_car][transport_fuel_count_km],
       	transport_config[model_car][transport_price_rent],
       	transport_config[model_car][transport_count_pass]);
    return SPD(playerid, DIALOG_CONFIG_VEH_GENERAL, DIALOG_STYLE_TABLIST_HEADERS, ""cBLUE"Настройка автомобиля", GlobalString, "Выбрать", "Закрыть"); 
}

stock change_pass_count_config_car(playerid)
{
	return SPD(playerid, DIALOG_CONFIG_CAR_PASS, DIALOG_STYLE_INPUT, ""cBLUE"Изменение количества мест", "\
	"cWH"Введите новое количество мест в салоне автомобиля", "Далее", "Назад");		
}

stock change_name_config_car(playerid)
{
	return SPD(playerid, DIALOG_CONFIG_CAR_NAME, DIALOG_STYLE_INPUT, ""cBLUE"Изменение наименования", "\
	"cWH"Введите новое наименование автомобиля", "Далее", "Назад");		
}

stock change_price_config_car(playerid)
{
	return SPD(playerid, DIALOG_CONFIG_CAR_PRICE, DIALOG_STYLE_INPUT, ""cBLUE"Изменение цены", "\
	"cWH"Введите новую цену автомобиля", "Далее", "Назад");				
}

stock change_tank_config_car(playerid)
{
	return SPD(playerid, DIALOG_CONFIG_CAR_TANK, DIALOG_STYLE_INPUT, ""cBLUE"Изменение бензобака", "\
	"cWH"Введите новый объем бензобака", "Далее", "Назад");				
}

stock change_speed_config_car(playerid)
{
	return SPD(playerid, DIALOG_CONFIG_CAR_SPEED, DIALOG_STYLE_INPUT, ""cBLUE"Изменение скорости", "\
	"cWH"Введите максимальную скорость автомобиля", "Далее", "Назад");				
}

stock change_fuel_count_km(playerid)
{
	return SPD(playerid, DIALOG_CONFIG_CAR_FILL, DIALOG_STYLE_INPUT, ""cBLUE"Изменение расхода топлива", "\
	"cWH"Введите кол-во литров на 100 км", "Далее", "Назад");			
}

stock change_price_rent_autosalon(playerid)
{
	return SPD(playerid, DIALOG_CONFIG_CAR_RENT, DIALOG_STYLE_INPUT, ""cBLUE"Изменение стоимости аренды", "\
	"cWH"Введите новую стоимость аренды", "Далее", "Назад");			
}

stock change_class_config_car(playerid)
{
	return SPD(playerid, DIALOG_CONFIG_CAR_CLASS, DIALOG_STYLE_LIST, ""cBLUE"Изменение класса", "\
		"cBLUE"-"cWH" Низкий класс\n\
		"cBLUE"-"cWH" Средний класс\n\
		"cBLUE"-"cWH" Высокий класс\n\
		"cBLUE"-"cWH" Элитный класс","Выбор","Выход");
}

stock change_type_fill_config_car(playerid)
{
	return SPD(playerid, DIALOG_CONFIG_CAR_FUEL_TYPE, DIALOG_STYLE_LIST, ""cBLUE"Изменение типа топлива", "\
		"cBLUE"-"cWH" АИ-92\n\
		"cBLUE"-"cWH" АИ-95\n\
		"cBLUE"-"cWH" АИ-98\n\
		"cBLUE"-"cWH" ДТ","Выбор","Выход");
}


stock change_fuel_config_car(playerid)
{
	new 
		model_car = GetPVarIntNew(playerid, "select_model_car");


	if(transport_config[model_car][transport_fuel_active] == 1)
	{
		transport_config[model_car][transport_fuel_active] = 0;
		SendInf(playerid, "Вы запретили заправку данному типу автомобиля!");
	}
	else
	{
		transport_config[model_car][transport_fuel_active] = 1;
		SendInf(playerid, "Вы разрешили заправку данному типу автомобиля!");
	}
	mysql_format(connect_main, GlobalString,sizeof(GlobalString),"UPDATE `transport` SET transport_fuel_active = '%d' WHERE `transport_id` = '%d'", transport_config[model_car][transport_fuel_active], model_car);
	mysql_tquery(connect_main, GlobalString, "", "");	

	dialog_config_car(playerid);

	return true; 	
}

stock change_selling_config_car(playerid)
{
	new 
		model_car = GetPVarIntNew(playerid, "select_model_car");


	if(transport_config[model_car][transport_sell_active] == 1)
	{
		transport_config[model_car][transport_sell_active] = 0;
		SendInf(playerid, "Вы запретили продажу данному типу автомобиля!");
	}
	else
	{
		transport_config[model_car][transport_sell_active] = 1;
		SendInf(playerid, "Вы разрешили продажу данному типу автомобиля!");
	}
	mysql_format(connect_main, GlobalString,sizeof(GlobalString),"UPDATE `transport` SET transport_sell_active = '%d' WHERE `transport_id` = '%d'", transport_config[model_car][transport_sell_active], model_car);
	mysql_tquery(connect_main, GlobalString, "", "");		

	dialog_config_car(playerid);

	return true; 	
}

stock change_taxi_config_car(playerid)
{
	new 
		model_car = GetPVarIntNew(playerid, "select_model_car");


	if(transport_config[model_car][transport_taxi_active] == 1)
	{
		transport_config[model_car][transport_taxi_active] = 0;
		SendInf(playerid, "Вы запретили таксовать данному типу автомобиля!");
	}
	else
	{
		transport_config[model_car][transport_taxi_active] = 1;
		SendInf(playerid, "Вы разрешили таксовать данному типу автомобиля!");
	}
	mysql_format(connect_main, GlobalString,sizeof(GlobalString),"UPDATE `transport` SET transport_taxi_active = '%d' WHERE `transport_id` = '%d'", transport_config[model_car][transport_taxi_active], model_car);
	mysql_tquery(connect_main, GlobalString, "", "");			

	dialog_config_car(playerid);

	return true; 	
}


CMD:edit_handling(playerid, params[])
{
	if(pData[playerid][pAdmin] < 7) 
		return true;

	/*if(!strcmp(pData[playerid][pNickname], "Misha_Kravcov"))
		return SendInf(playerid, "Миша, ну его нахуй, иди поспи, сломаешь еще что-нибудь!");*/

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/edit_handling [Модель авто]");		

	if(params[0] > 211 || params[0] < 0) 
		return SendErr(playerid, "Ид транспорта от 0 (0 - ЭТО 1 В БД И 400 МОДЕЛЬ) до 211!");


	SetPVarIntNew(playerid, "select_model_car", params[0]);

	dialog_config_car_handling(playerid);

	return true;
}

stock dialog_config_car_handling(playerid)
{
	new 
		model_car = GetPVarIntNew(playerid, "select_model_car");

    format(GlobalString, sizeof(GlobalString), "\
        "cGREY"Пункт\t"cGREY"Информация\n\
        "cBLUE"- "cWH"Модель автомобиля\t"cBLUE"%d\n\
        "cBLUE"- "cWH"Наименование модели\t"cBLUE"%s\n\
        "cBLUE"- "cWH"Связано с тем, как будет заносить авто\t"cGR"%f%%\n\
        "cBLUE"- "cWH"Максимальная скорость\t"cGR"%f%%\n\
        "cBLUE"- "cWH"Максимальный вес\t"cGR"%f%%\n\
        "cBLUE"- "cWH"Максимальный вес 2\t"cGR"%f%%\n\
        "cBLUE"- "cWH"Ускорение авто\t"cGR"%f%%\n\
        "cBLUE"- "cWH"Какие-то передачи\t"cGR"%f%%\n\
        "cBLUE"- "cWH"Тоже непонятный\t"cGR"%f%%\n\
        "cBLUE"- "cWH"Тоже непонятный\t"cGR"%f%%\n\
        "cBLUE"- "cWH"Тоже непонятный\t"cGR"%f%%\n\
        "cBLUE"- "cWH"Тоже непонятный\t"cGR"%f%%\n\
        "cBLUE"- "cWH"Тоже непонятный\t"cGR"%f%%\n\
        "cBLUE"- "cWH"Размер колес\t"cGR"%f%%\n\
        "cBLUE"- "cWH"Тоже непонятный\t"cGR"%f%%\n\
        "cBLUE"- "cWH"Угол колес\t"cGR"%d\n\
        "cBLUE"- "cWH"Колеса 1\t"cGR"%d\n\
        "cBLUE"- "cWH"Колеса 2\t"cGR"%d", 
        transport_config[model_car][transport_model],
        transport_config[model_car][transport_name],

        transport_config[model_car][transport_engine_inertion],
        transport_config[model_car][transport_handling_speed],
        transport_config[model_car][transport_handling_mass],
        transport_config[model_car][transport_handling_mass_turn],
        transport_config[model_car][transport_handling_acceleration],
        transport_config[model_car][transport_handling_gear],
        transport_config[model_car][transport_brake_deceleration],


        transport_config[model_car][transport_traction_multiplier],
        transport_config[model_car][transport_traction_loss],
        transport_config[model_car][transport_traction_bias],
        transport_config[model_car][transport_suspension_bias],
        transport_config[model_car][transport_wheel_size],
        transport_config[model_car][transport_suspension_limit],

        transport_config[model_car][transport_wheel_angle],
        transport_config[model_car][transport_wheel_offset],
        transport_config[model_car][transport_wheel_width]);
    return SPD(playerid, DIALOG_CONFIG_VEH_HANDLING, DIALOG_STYLE_TABLIST_HEADERS, ""cBLUE"Настройка автомобиля (хэндлинг)", GlobalString, "Выбрать", "Закрыть"); 
}

stock change_handling_car(playerid, type)
{

	switch(type)
	{
		case 0:
		{
			return SPD(playerid, DIALOG_HANDLING_CONFIG_1, DIALOG_STYLE_INPUT, ""cBLUE"Изменение параметра хэндлинга", "\
			"cWH"Введите новый параметр. Пример: 10.0", "Далее", "Назад");					
		}
		case 1:
		{
			return SPD(playerid, DIALOG_HANDLING_CONFIG_2, DIALOG_STYLE_INPUT, ""cBLUE"Изменение параметра хэндлинга", "\
			"cWH"Введите новый параметр. Пример: 10.0", "Далее", "Назад");					
		}
		case 2:
		{
			return SPD(playerid, DIALOG_HANDLING_CONFIG_3, DIALOG_STYLE_INPUT, ""cBLUE"Изменение параметра хэндлинга", "\
			"cWH"Введите новый параметр. Пример: 10.0", "Далее", "Назад");					
		}
		case 3:
		{
			return SPD(playerid, DIALOG_HANDLING_CONFIG_4, DIALOG_STYLE_INPUT, ""cBLUE"Изменение параметра хэндлинга", "\
			"cWH"Введите новый параметр. Пример: 10.0", "Далее", "Назад");					
		}
		case 4:
		{
			return SPD(playerid, DIALOG_HANDLING_CONFIG_5, DIALOG_STYLE_INPUT, ""cBLUE"Изменение параметра хэндлинга", "\
			"cWH"Введите новый параметр. Пример: 10.0", "Далее", "Назад");					
		}
		case 5:
		{
			return SPD(playerid, DIALOG_HANDLING_CONFIG_6, DIALOG_STYLE_INPUT, ""cBLUE"Изменение параметра хэндлинга", "\
			"cWH"Введите новый параметр. Пример: 10.0", "Далее", "Назад");					
		}
		case 6:
		{
			return SPD(playerid, DIALOG_HANDLING_CONFIG_7, DIALOG_STYLE_INPUT, ""cBLUE"Изменение параметра хэндлинга", "\
			"cWH"Введите новый параметр. Пример: 10.0", "Далее", "Назад");					
		}
		case 7:
		{
			return SPD(playerid, DIALOG_HANDLING_CONFIG_8, DIALOG_STYLE_INPUT, ""cBLUE"Изменение параметра хэндлинга", "\
			"cWH"Введите новый параметр. Пример: 10.0", "Далее", "Назад");					
		}
		case 8:
		{
			return SPD(playerid, DIALOG_HANDLING_CONFIG_9, DIALOG_STYLE_INPUT, ""cBLUE"Изменение параметра хэндлинга", "\
			"cWH"Введите новый параметр. Пример: 10.0", "Далее", "Назад");					
		}

		case 9:
		{
			return SPD(playerid, DIALOG_HANDLING_CONFIG_10, DIALOG_STYLE_INPUT, ""cBLUE"Изменение параметра хэндлинга", "\
			"cWH"Введите новый параметр. Пример: 10.0", "Далее", "Назад");					
		}
		case 10:
		{
			return SPD(playerid, DIALOG_HANDLING_CONFIG_11, DIALOG_STYLE_INPUT, ""cBLUE"Изменение параметра хэндлинга", "\
			"cWH"Введите новый параметр. Пример: 10.0", "Далее", "Назад");					
		}
		case 11:
		{
			return SPD(playerid, DIALOG_HANDLING_CONFIG_12, DIALOG_STYLE_INPUT, ""cBLUE"Изменение параметра хэндлинга", "\
			"cWH"Введите новый параметр. Пример: 10.0", "Далее", "Назад");					
		}
		case 12:
		{
			return SPD(playerid, DIALOG_HANDLING_CONFIG_13, DIALOG_STYLE_INPUT, ""cBLUE"Изменение параметра хэндлинга", "\
			"cWH"Введите новый параметр. Пример: 10.0", "Далее", "Назад");					
		}
		case 13:
		{
			return SPD(playerid, DIALOG_HANDLING_CONFIG_14, DIALOG_STYLE_INPUT, ""cBLUE"Изменение параметра хэндлинга", "\
			"cWH"Введите новый параметр. Пример: 10.0", "Далее", "Назад");					
		}
		case 14:
		{
			return SPD(playerid, DIALOG_HANDLING_CONFIG_15, DIALOG_STYLE_INPUT, ""cBLUE"Изменение параметра хэндлинга", "\
			"cWH"Введите новый параметр. Пример: 10.0", "Далее", "Назад");					
		}
		case 15:
		{
			return SPD(playerid, DIALOG_HANDLING_CONFIG_16, DIALOG_STYLE_INPUT, ""cBLUE"Изменение параметра хэндлинга", "\
			"cWH"Введите новый параметр. Пример: 10.0", "Далее", "Назад");					
		}

	}
	return true;
}

stock dialog_all_vehicle_config(playerid, dialogid, response, listitem, inputtext[])
{

	switch(dialogid)
	{
		case DIALOG_HANDLING_CONFIG_1:
		{
			if(!response) 
				return dialog_config_car_handling(playerid);	

			if(check_no_valid_symbol_text(inputtext) || check_sql_injection_text(inputtext))
			{
				change_name_config_car(playerid);
				return SendErr(playerid,"Название содержит запрещенные символы!");
			}

			new 
				model_car = GetPVarIntNew(playerid, "select_model_car");

			transport_config[model_car][transport_engine_inertion] = floatstr(inputtext);

			mysql_format(connect_main, GlobalString,sizeof(GlobalString),"UPDATE `transport` SET transport_engine_inertion = '%f' WHERE `transport_id` = '%d'", transport_config[model_car][transport_engine_inertion], model_car);
			mysql_tquery(connect_main, GlobalString, "", "");	

			format(GlobalString, sizeof(GlobalString), "Новый параметр автомобиля - %f", transport_config[model_car][transport_engine_inertion]);
		    SendSucc(playerid, GlobalString);

			dialog_config_car_handling(playerid);
		}
		case DIALOG_HANDLING_CONFIG_2:
		{
			if(!response) 
				return dialog_config_car_handling(playerid);	

			if(check_no_valid_symbol_text(inputtext) || check_sql_injection_text(inputtext))
			{
				change_name_config_car(playerid);
				return SendErr(playerid,"Название содержит запрещенные символы!");
			}

			new 
				model_car = GetPVarIntNew(playerid, "select_model_car");

			transport_config[model_car][transport_handling_speed] = floatstr(inputtext);

			mysql_format(connect_main, GlobalString,sizeof(GlobalString),"UPDATE `transport` SET transport_handling_speed = '%f' WHERE `transport_id` = '%d'", transport_config[model_car][transport_handling_speed], model_car);
			mysql_tquery(connect_main, GlobalString, "", "");

			format(GlobalString, sizeof(GlobalString), "Новый параметр автомобиля - %f", transport_config[model_car][transport_handling_speed]);
		    SendSucc(playerid, GlobalString);

			dialog_config_car_handling(playerid);
		}
		case DIALOG_HANDLING_CONFIG_3:
		{
			if(!response) 
				return dialog_config_car_handling(playerid);	

			if(check_no_valid_symbol_text(inputtext) || check_sql_injection_text(inputtext))
			{
				change_name_config_car(playerid);
				return SendErr(playerid,"Название содержит запрещенные символы!");
			}

			new 
				model_car = GetPVarIntNew(playerid, "select_model_car");

			transport_config[model_car][transport_handling_mass] = floatstr(inputtext);

			mysql_format(connect_main, GlobalString,sizeof(GlobalString),"UPDATE `transport` SET transport_handling_mass = '%f' WHERE `transport_id` = '%d'", transport_config[model_car][transport_handling_mass], model_car);
			mysql_tquery(connect_main, GlobalString, "", "");	

			format(GlobalString, sizeof(GlobalString), "Новый параметр автомобиля - %f", transport_config[model_car][transport_handling_mass]);
		    SendSucc(playerid, GlobalString);

			dialog_config_car_handling(playerid);
		}
		case DIALOG_HANDLING_CONFIG_4:
		{
			if(!response) 
				return dialog_config_car_handling(playerid);	

			if(check_no_valid_symbol_text(inputtext) || check_sql_injection_text(inputtext))
			{
				change_name_config_car(playerid);
				return SendErr(playerid,"Название содержит запрещенные символы!");
			}

			new 
				model_car = GetPVarIntNew(playerid, "select_model_car");

			transport_config[model_car][transport_handling_mass_turn] = floatstr(inputtext);

			mysql_format(connect_main, GlobalString,sizeof(GlobalString),"UPDATE `transport` SET transport_handling_mass_turn = '%f' WHERE `transport_id` = '%d'", transport_config[model_car][transport_handling_mass_turn], model_car);
			mysql_tquery(connect_main, GlobalString, "", "");	

			format(GlobalString, sizeof(GlobalString), "Новый параметр автомобиля - %f", transport_config[model_car][transport_handling_mass_turn]);
		    SendSucc(playerid, GlobalString);

			dialog_config_car_handling(playerid);
		}
		case DIALOG_HANDLING_CONFIG_5:
		{
			if(!response) 
				return dialog_config_car_handling(playerid);	

			if(check_no_valid_symbol_text(inputtext) || check_sql_injection_text(inputtext))
			{
				change_name_config_car(playerid);
				return SendErr(playerid,"Название содержит запрещенные символы!");
			}

			new 
				model_car = GetPVarIntNew(playerid, "select_model_car");

			transport_config[model_car][transport_handling_acceleration] = floatstr(inputtext);

			mysql_format(connect_main, GlobalString,sizeof(GlobalString),"UPDATE `transport` SET transport_handling_acceleration = '%f' WHERE `transport_id` = '%d'", transport_config[model_car][transport_handling_acceleration], model_car);
			mysql_tquery(connect_main, GlobalString, "", "");

			format(GlobalString, sizeof(GlobalString), "Новый параметр автомобиля - %f", transport_config[model_car][transport_handling_acceleration]);
		    SendSucc(playerid, GlobalString); 

			dialog_config_car_handling(playerid);
		}
		case DIALOG_HANDLING_CONFIG_6:
		{
			if(!response) 
				return dialog_config_car_handling(playerid);	

			if(check_no_valid_symbol_text(inputtext) || check_sql_injection_text(inputtext))
			{
				change_name_config_car(playerid);
				return SendErr(playerid,"Название содержит запрещенные символы!");
			}

			new 
				model_car = GetPVarIntNew(playerid, "select_model_car");

			transport_config[model_car][transport_handling_gear] = floatstr(inputtext);

			mysql_format(connect_main, GlobalString,sizeof(GlobalString),"UPDATE `transport` SET transport_handling_gear = '%f' WHERE `transport_id` = '%d'", transport_config[model_car][transport_handling_gear], model_car);
			mysql_tquery(connect_main, GlobalString, "", "");	

			format(GlobalString, sizeof(GlobalString), "Новый параметр автомобиля - %f", transport_config[model_car][transport_handling_gear]);
		    SendSucc(playerid, GlobalString);

			dialog_config_car_handling(playerid);
		}
		case DIALOG_HANDLING_CONFIG_7:
		{
			if(!response) 
				return dialog_config_car_handling(playerid);	

			if(check_no_valid_symbol_text(inputtext) || check_sql_injection_text(inputtext))
			{
				change_name_config_car(playerid);
				return SendErr(playerid,"Название содержит запрещенные символы!");
			}

			new 
				model_car = GetPVarIntNew(playerid, "select_model_car");

			transport_config[model_car][transport_brake_deceleration] = floatstr(inputtext);

			mysql_format(connect_main, GlobalString,sizeof(GlobalString),"UPDATE `transport` SET transport_brake_deceleration = '%f' WHERE `transport_id` = '%d'", transport_config[model_car][transport_brake_deceleration], model_car);
			mysql_tquery(connect_main, GlobalString, "", "");

			format(GlobalString, sizeof(GlobalString), "Новый параметр автомобиля - %f", transport_config[model_car][transport_brake_deceleration]);
		    SendSucc(playerid, GlobalString);

			dialog_config_car_handling(playerid);
		}
		case DIALOG_HANDLING_CONFIG_8:
		{
			if(!response) 
				return dialog_config_car_handling(playerid);	

			if(check_no_valid_symbol_text(inputtext) || check_sql_injection_text(inputtext))
			{
				change_name_config_car(playerid);
				return SendErr(playerid,"Название содержит запрещенные символы!");
			}

			new 
				model_car = GetPVarIntNew(playerid, "select_model_car");

			transport_config[model_car][transport_traction_multiplier] = floatstr(inputtext);

			mysql_format(connect_main, GlobalString,sizeof(GlobalString),"UPDATE `transport` SET transport_traction_multiplier = '%f' WHERE `transport_id` = '%d'", transport_config[model_car][transport_traction_multiplier], model_car);
			mysql_tquery(connect_main, GlobalString, "", "");

			format(GlobalString, sizeof(GlobalString), "Новый параметр автомобиля - %f", transport_config[model_car][transport_traction_multiplier]);
		    SendSucc(playerid, GlobalString);

			dialog_config_car_handling(playerid);
		}
		case DIALOG_HANDLING_CONFIG_9:
		{
			if(!response) 
				return dialog_config_car_handling(playerid);	

			if(check_no_valid_symbol_text(inputtext) || check_sql_injection_text(inputtext))
			{
				change_name_config_car(playerid);
				return SendErr(playerid,"Название содержит запрещенные символы!");
			}

			new 
				model_car = GetPVarIntNew(playerid, "select_model_car");

			transport_config[model_car][transport_traction_loss] = floatstr(inputtext);

			mysql_format(connect_main, GlobalString,sizeof(GlobalString),"UPDATE `transport` SET transport_traction_loss = '%f' WHERE `transport_id` = '%d'", transport_config[model_car][transport_traction_loss], model_car);
			mysql_tquery(connect_main, GlobalString, "", "");	

			format(GlobalString, sizeof(GlobalString), "Новый параметр автомобиля - %f", transport_config[model_car][transport_traction_loss]);
		    SendSucc(playerid, GlobalString);

			dialog_config_car_handling(playerid);
		}
		case DIALOG_HANDLING_CONFIG_10:
		{
			if(!response) 
				return dialog_config_car_handling(playerid);	

			if(check_no_valid_symbol_text(inputtext) || check_sql_injection_text(inputtext))
			{
				change_name_config_car(playerid);
				return SendErr(playerid,"Название содержит запрещенные символы!");
			}

			new 
				model_car = GetPVarIntNew(playerid, "select_model_car");

			transport_config[model_car][transport_traction_bias] = floatstr(inputtext);

			mysql_format(connect_main, GlobalString,sizeof(GlobalString),"UPDATE `transport` SET transport_traction_bias = '%f' WHERE `transport_id` = '%d'", transport_config[model_car][transport_traction_bias], model_car);
			mysql_tquery(connect_main, GlobalString, "", "");	

			format(GlobalString, sizeof(GlobalString), "Новый параметр автомобиля - %f", transport_config[model_car][transport_traction_bias]);
		    SendSucc(playerid, GlobalString);

			dialog_config_car_handling(playerid);
		}
		case DIALOG_HANDLING_CONFIG_11:
		{
			if(!response) 
				return dialog_config_car_handling(playerid);	

			if(check_no_valid_symbol_text(inputtext) || check_sql_injection_text(inputtext))
			{
				change_name_config_car(playerid);
				return SendErr(playerid,"Название содержит запрещенные символы!");
			}

			new 
				model_car = GetPVarIntNew(playerid, "select_model_car");

			transport_config[model_car][transport_suspension_bias] = floatstr(inputtext);

			mysql_format(connect_main, GlobalString,sizeof(GlobalString),"UPDATE `transport` SET transport_suspension_bias = '%f' WHERE `transport_id` = '%d'", transport_config[model_car][transport_suspension_bias], model_car);
			mysql_tquery(connect_main, GlobalString, "", "");	

			format(GlobalString, sizeof(GlobalString), "Новый параметр автомобиля - %f", transport_config[model_car][transport_suspension_bias]);
		    SendSucc(playerid, GlobalString);

			dialog_config_car_handling(playerid);
		}
		case DIALOG_HANDLING_CONFIG_12:
		{
			if(!response) 
				return dialog_config_car_handling(playerid);	

			if(check_no_valid_symbol_text(inputtext) || check_sql_injection_text(inputtext))
			{
				change_name_config_car(playerid);
				return SendErr(playerid,"Название содержит запрещенные символы!");
			}

			new 
				model_car = GetPVarIntNew(playerid, "select_model_car");

			transport_config[model_car][transport_wheel_size] = floatstr(inputtext);

			mysql_format(connect_main, GlobalString,sizeof(GlobalString),"UPDATE `transport` SET transport_wheel_size = '%f' WHERE `transport_id` = '%d'", transport_config[model_car][transport_wheel_size], model_car);
			mysql_tquery(connect_main, GlobalString, "", "");

			format(GlobalString, sizeof(GlobalString), "Новый параметр автомобиля - %f", transport_config[model_car][transport_wheel_size]);
		    SendSucc(playerid, GlobalString);

			dialog_config_car_handling(playerid);
		}
		case DIALOG_HANDLING_CONFIG_13:
		{
			if(!response) 
				return dialog_config_car_handling(playerid);	

			if(check_no_valid_symbol_text(inputtext) || check_sql_injection_text(inputtext))
			{
				change_name_config_car(playerid);
				return SendErr(playerid,"Название содержит запрещенные символы!");
			}

			new 
				model_car = GetPVarIntNew(playerid, "select_model_car");

			transport_config[model_car][transport_suspension_limit] = floatstr(inputtext);

			mysql_format(connect_main, GlobalString,sizeof(GlobalString),"UPDATE `transport` SET transport_suspension_limit = '%f' WHERE `transport_id` = '%d'", transport_config[model_car][transport_suspension_limit], model_car);
			mysql_tquery(connect_main, GlobalString, "", "");

			format(GlobalString, sizeof(GlobalString), "Новый параметр автомобиля - %f", transport_config[model_car][transport_suspension_limit]);
		    SendSucc(playerid, GlobalString);

			dialog_config_car_handling(playerid);
		}
		case DIALOG_HANDLING_CONFIG_14:
		{
			if(!response) 
				return dialog_config_car_handling(playerid);	

			if(check_no_valid_symbol_text(inputtext) || check_sql_injection_text(inputtext))
			{
				change_name_config_car(playerid);
				return SendErr(playerid,"Название содержит запрещенные символы!");
			}

			new 
				model_car = GetPVarIntNew(playerid, "select_model_car");

			transport_config[model_car][transport_wheel_angle] = strval(inputtext);

			mysql_format(connect_main, GlobalString,sizeof(GlobalString),"UPDATE `transport` SET transport_wheel_angle = '%d' WHERE `transport_id` = '%d'", transport_config[model_car][transport_wheel_angle], model_car);
			mysql_tquery(connect_main, GlobalString, "", "");

			format(GlobalString, sizeof(GlobalString), "Новый параметр автомобиля - %d", transport_config[model_car][transport_wheel_angle]);
		    SendSucc(playerid, GlobalString);

			dialog_config_car_handling(playerid);
		}
		case DIALOG_HANDLING_CONFIG_15:
		{
			if(!response) 
				return dialog_config_car_handling(playerid);	

			if(check_no_valid_symbol_text(inputtext) || check_sql_injection_text(inputtext))
			{
				change_name_config_car(playerid);
				return SendErr(playerid,"Название содержит запрещенные символы!");
			}

			new 
				model_car = GetPVarIntNew(playerid, "select_model_car");

			transport_config[model_car][transport_wheel_offset] = strval(inputtext);

			mysql_format(connect_main, GlobalString,sizeof(GlobalString),"UPDATE `transport` SET transport_wheel_offset = '%d' WHERE `transport_id` = '%d'", transport_config[model_car][transport_wheel_offset], model_car);
			mysql_tquery(connect_main, GlobalString, "", "");

			format(GlobalString, sizeof(GlobalString), "Новый параметр автомобиля - %d", transport_config[model_car][transport_wheel_offset]);
		    SendSucc(playerid, GlobalString);

			dialog_config_car_handling(playerid);
		}
		case DIALOG_HANDLING_CONFIG_16:
		{
			if(!response) 
				return dialog_config_car_handling(playerid);	

			if(check_no_valid_symbol_text(inputtext) || check_sql_injection_text(inputtext))
			{
				change_name_config_car(playerid);
				return SendErr(playerid,"Название содержит запрещенные символы!");
			}

			new 
				model_car = GetPVarIntNew(playerid, "select_model_car");

			transport_config[model_car][transport_wheel_width] = strval(inputtext);

			mysql_format(connect_main, GlobalString,sizeof(GlobalString),"UPDATE `transport` SET transport_wheel_width = '%d' WHERE `transport_id` = '%d'", transport_config[model_car][transport_wheel_width], model_car);
			mysql_tquery(connect_main, GlobalString, "", "");

			format(GlobalString, sizeof(GlobalString), "Новый параметр автомобиля - %d", transport_config[model_car][transport_wheel_width]);
		    SendSucc(playerid, GlobalString);

			dialog_config_car_handling(playerid);
		}
		case DIALOG_CONFIG_VEH_HANDLING:
		{
			if(!response) 
				return true;	

	    	switch(listitem)
	    	{
	    		case 0: return dialog_config_car_handling(playerid);
	    		case 1: return dialog_config_car_handling(playerid);
	    		case 2: return change_handling_car(playerid, 0);
	    		case 3: return change_handling_car(playerid, 1);
	    		case 4: return change_handling_car(playerid, 2);
	    		case 5: return change_handling_car(playerid, 3);
	    		case 6: return change_handling_car(playerid, 4);
	    		case 7: return change_handling_car(playerid, 5);
	    		case 8: return change_handling_car(playerid, 6);
	    		case 9: return change_handling_car(playerid, 7);
	    		case 10: return change_handling_car(playerid, 8);
	    		case 11: return change_handling_car(playerid, 9);
	    		case 12: return change_handling_car(playerid, 10);
	    		case 13: return change_handling_car(playerid, 11);
	    		case 14: return change_handling_car(playerid, 12);
	    		case 15: return change_handling_car(playerid, 13);
	    		case 16: return change_handling_car(playerid, 14);
	    		case 17: return change_handling_car(playerid, 15);
	    	}			
		}
	    case DIALOG_CONFIG_VEH_GENERAL: 
	    {
			if(!response) 
				return true;	

	    	switch(listitem)
	    	{
	    		case 0: return dialog_config_car(playerid);
	    		case 1: return change_name_config_car(playerid);
	    		case 2: return change_price_config_car(playerid);
	    		case 3: return change_tank_config_car(playerid);
	    		case 4: return change_class_config_car(playerid);
	    		case 5: return change_fuel_config_car(playerid);
	    		case 6: return change_selling_config_car(playerid);
	    		case 7: return change_taxi_config_car(playerid);
	    		case 8: return change_type_fill_config_car(playerid);
	    		case 9: return change_speed_config_car(playerid);
	    		case 10: return change_fuel_count_km(playerid);
	    		case 11: return change_price_rent_autosalon(playerid);
	    		case 12: return change_pass_count_config_car(playerid);
	    	}
	    }

	    case DIALOG_CONFIG_CAR_FUEL_TYPE:
	    {
			if(!response) 
				return dialog_config_car(playerid);	

	    	switch(listitem)
	    	{
	    		case 0:
	    		{
					new 
						model_car = GetPVarIntNew(playerid, "select_model_car");

					transport_config[model_car][transport_fuel_type] = 1;	 
					SendSucc(playerid, "Теперь тип топлива автомобиля - АИ-92");    

					mysql_format(connect_main, GlobalString,sizeof(GlobalString),"UPDATE `transport` SET transport_fuel_type = '%d' WHERE `transport_id` = '%d'", transport_config[model_car][transport_fuel_type], model_car);
					mysql_tquery(connect_main, GlobalString, "", "");

					dialog_config_car(playerid);

	    		}
	    		case 1:
	    		{
					new 
						model_car = GetPVarIntNew(playerid, "select_model_car");

					transport_config[model_car][transport_fuel_type] = 2;	 
					SendSucc(playerid, "Теперь тип топлива автомобиля - АИ-95");    

					mysql_format(connect_main, GlobalString,sizeof(GlobalString),"UPDATE `transport` SET transport_fuel_type = '%d' WHERE `transport_id` = '%d'", transport_config[model_car][transport_fuel_type], model_car);
					mysql_tquery(connect_main, GlobalString, "", "");

					dialog_config_car(playerid);

	    		}
	    		case 2:
	    		{
					new 
						model_car = GetPVarIntNew(playerid, "select_model_car");

					transport_config[model_car][transport_fuel_type] = 3;	 
					SendSucc(playerid, "Теперь тип топлива автомобиля - АИ-98");    

					mysql_format(connect_main, GlobalString,sizeof(GlobalString),"UPDATE `transport` SET transport_fuel_type = '%d' WHERE `transport_id` = '%d'", transport_config[model_car][transport_fuel_type], model_car);
					mysql_tquery(connect_main, GlobalString, "", "");

					dialog_config_car(playerid);

	    		}
	    		case 3:
	    		{
					new 
						model_car = GetPVarIntNew(playerid, "select_model_car");

					transport_config[model_car][transport_fuel_type] = 4;	 
					SendSucc(playerid, "Теперь тип топлива автомобиля - ДТ");    

					mysql_format(connect_main, GlobalString,sizeof(GlobalString),"UPDATE `transport` SET transport_fuel_type = '%d' WHERE `transport_id` = '%d'", transport_config[model_car][transport_fuel_type], model_car);
					mysql_tquery(connect_main, GlobalString, "", "");

					dialog_config_car(playerid);

	    		}

	    	}	    	
	    }
	    case DIALOG_CONFIG_CAR_CLASS:
	    {
			if(!response) 
				return dialog_config_car(playerid);	

	    	switch(listitem)
	    	{
	    		case 0:
	    		{
					new 
						model_car = GetPVarIntNew(playerid, "select_model_car");

					transport_config[model_car][transport_class] = 1;	 
					SendSucc(playerid, "Класс автомобиля изменен на низкий!");    	

					mysql_format(connect_main, GlobalString,sizeof(GlobalString), "UPDATE `transport` SET transport_class = '%d' WHERE `transport_id` = '%d'", transport_config[model_car][transport_class], model_car);
					mysql_tquery(connect_main, GlobalString, "", "");

					dialog_config_car(playerid);

	    		}
	    		case 1:
	    		{
					new 
						model_car = GetPVarIntNew(playerid, "select_model_car");

					transport_config[model_car][transport_class] = 2;	 
					SendSucc(playerid, "Класс автомобиля изменен на средний!"); 

					mysql_format(connect_main, GlobalString,sizeof(GlobalString),"UPDATE `transport` SET transport_class = '%d' WHERE `transport_id` = '%d'", transport_config[model_car][transport_class], model_car);
					mysql_tquery(connect_main, GlobalString, "", "");

					dialog_config_car(playerid);

	    		}
	    		case 2:
	    		{
					new 
						model_car = GetPVarIntNew(playerid, "select_model_car");

					transport_config[model_car][transport_class] = 3;	 
					SendSucc(playerid, "Класс автомобиля изменен на высокий!"); 

					mysql_format(connect_main, GlobalString,sizeof(GlobalString),"UPDATE `transport` SET transport_class = '%d' WHERE `transport_id` = '%d'", transport_config[model_car][transport_class], model_car);
					mysql_tquery(connect_main, GlobalString, "", "");

					dialog_config_car(playerid);

	    		}
	    		case 3:
	    		{
					new 
						model_car = GetPVarIntNew(playerid, "select_model_car");

					transport_config[model_car][transport_class] = 4;	 
					SendSucc(playerid, "Класс автомобиля изменен на элитный!");   	

					mysql_format(connect_main, GlobalString,sizeof(GlobalString),"UPDATE `transport` SET transport_class = '%d' WHERE `transport_id` = '%d'", transport_config[model_car][transport_class], model_car);
					mysql_tquery(connect_main, GlobalString, "", "");

					dialog_config_car(playerid);


	    		}		
	    	}	    	
	    }
	    case DIALOG_CONFIG_CAR_NAME:
	    {

			if(!response) 
				return dialog_config_car(playerid);	

			if(check_no_valid_symbol_text(inputtext) || check_sql_injection_text(inputtext))
			{
				change_name_config_car(playerid);
				return SendErr(playerid,"Название содержит запрещенные символы!");
			}

			new 
				model_car = GetPVarIntNew(playerid, "select_model_car");

			format(transport_config[model_car][transport_name], 35, inputtext);

			mysql_format(connect_main, GlobalString,sizeof(GlobalString),"UPDATE `transport` SET transport_name = '%s' WHERE `transport_id` = '%d'", transport_config[model_car][transport_name], model_car);
			mysql_tquery(connect_main, GlobalString, "", "");	

			format(GlobalString, sizeof(GlobalString), "Новое наименование автомобиля - %s", transport_config[model_car][transport_name]);
		    SendSucc(playerid, GlobalString);

			dialog_config_car(playerid);

	    }
	    case DIALOG_CONFIG_CAR_PRICE:
	    {

			if(!response) 
				return dialog_config_car(playerid);	

			if(!IsNumeric(inputtext)) 
				return SendErr(playerid,"Вы указали неверные данные!");

			new 
				model_car = GetPVarIntNew(playerid, "select_model_car");

			transport_config[model_car][transport_price] = strval(inputtext);

			mysql_format(connect_main, GlobalString,sizeof(GlobalString),"UPDATE `transport` SET transport_price = '%d' WHERE `transport_id` = '%d'", transport_config[model_car][transport_price], model_car);
			mysql_tquery(connect_main, GlobalString, "", "");

			format(GlobalString, sizeof(GlobalString), "Новая цена автомобиля - %d рублей", transport_config[model_car][transport_price]);
		    SendSucc(playerid, GlobalString);

		    dialog_config_car(playerid);
	    }
	    case DIALOG_CONFIG_CAR_TANK:
	    {
			if(!response) 
				return dialog_config_car(playerid);	

			if(!IsNumeric(inputtext)) 
				return SendErr(playerid,"Вы указали неверные данные!");

			new 
				model_car = GetPVarIntNew(playerid, "select_model_car");

			transport_config[model_car][transport_tank] = strval(inputtext);

			mysql_format(connect_main, GlobalString,sizeof(GlobalString),"UPDATE `transport` SET transport_tank = '%d' WHERE `transport_id` = '%d'", transport_config[model_car][transport_tank], model_car);
			mysql_tquery(connect_main, GlobalString, "", "");

			format(GlobalString, sizeof(GlobalString), "Новый объем бензобака - %d литров", transport_config[model_car][transport_tank]);
		    SendSucc(playerid, GlobalString);

		    dialog_config_car(playerid);	    	
	    }
	    case DIALOG_CONFIG_CAR_SPEED:
	    {
			if(!response) 
				return dialog_config_car(playerid);	

			if(!IsNumeric(inputtext)) 
				return SendErr(playerid,"Вы указали неверные данные!");

			new 
				model_car = GetPVarIntNew(playerid, "select_model_car");

			transport_config[model_car][transport_max_speed] = strval(inputtext);

			mysql_format(connect_main, GlobalString,sizeof(GlobalString),"UPDATE `transport` SET transport_max_speed = '%d' WHERE `transport_id` = '%d'", transport_config[model_car][transport_max_speed], model_car);
			mysql_tquery(connect_main, GlobalString, "", "");

			format(GlobalString, sizeof(GlobalString), "Новая максимальная скорость - %d КМ/Ч", transport_config[model_car][transport_max_speed]);
		    SendSucc(playerid, GlobalString);

		    dialog_config_car(playerid);		    	
	    }
	    case DIALOG_CONFIG_CAR_FILL:
	    {
			if(!response) 
				return dialog_config_car(playerid);	

			if(!IsNumeric(inputtext)) 
				return SendErr(playerid,"Вы указали неверные данные!");

			new 
				model_car = GetPVarIntNew(playerid, "select_model_car");

			transport_config[model_car][transport_fuel_count_km] = strval(inputtext);

			mysql_format(connect_main, GlobalString,sizeof(GlobalString),"UPDATE `transport` SET transport_fuel_count_km = '%d' WHERE `transport_id` = '%d'", transport_config[model_car][transport_fuel_count_km], model_car);
			mysql_tquery(connect_main, GlobalString, "", "");

			format(GlobalString, sizeof(GlobalString), "Новый расход топлива у автомобиля - %dл на 100 км", transport_config[model_car][transport_fuel_count_km]);
		    SendSucc(playerid, GlobalString);

		    dialog_config_car(playerid);		    	
	    }
	    case DIALOG_CONFIG_CAR_RENT:
	    {
			if(!response) 
				return dialog_config_car(playerid);	

			if(!IsNumeric(inputtext)) 
				return SendErr(playerid,"Вы указали неверные данные!");

			new 
				model_car = GetPVarIntNew(playerid, "select_model_car");

			transport_config[model_car][transport_price_rent] = strval(inputtext);

			mysql_format(connect_main, GlobalString,sizeof(GlobalString),"UPDATE `transport` SET transport_price_rent = '%d' WHERE `transport_id` = '%d'", transport_config[model_car][transport_price_rent], model_car);
			mysql_tquery(connect_main, GlobalString, "", "");

			format(GlobalString, sizeof(GlobalString), "Новый расход топлива у автомобиля - %dл на 100 км", transport_config[model_car][transport_price_rent]);
		    SendSucc(playerid, GlobalString);

		    dialog_config_car(playerid);		    	
	    }

	    case DIALOG_CONFIG_CAR_PASS:
	    {


			if(!response) 
				return dialog_config_car(playerid);	

			if(!IsNumeric(inputtext)) 
				return SendErr(playerid,"Вы указали неверные данные!");

			new 
				model_car = GetPVarIntNew(playerid, "select_model_car");

			transport_config[model_car][transport_count_pass] = strval(inputtext);

			mysql_format(connect_main, GlobalString,sizeof(GlobalString),"UPDATE `transport` SET transport_count_pass = '%d' WHERE `transport_id` = '%d'", transport_config[model_car][transport_count_pass], model_car);
			mysql_tquery(connect_main, GlobalString, "", "");	

			format(GlobalString, sizeof(GlobalString), "Новое количество мест в салоне - %d мест", transport_config[model_car][transport_count_pass]);
		    SendSucc(playerid, GlobalString);

		    dialog_config_car(playerid);	

	    }

		case DIALOG_SELECT_NUMBER_VEH:	
		{
			if(!response)
				return true;

			new 
				i = pData[playerid][car_id];

			if(i == INVALID_VEHICLE_ID) 
				return SendErr(playerid, "Или Вы не имеете транспортное средство или Вы оно находиться на парковке!");


			new 
				id = dialog_listitem_values[playerid][listitem];

			return show_menu_change_number_car(playerid, id);
		}

		case DIALOG_CHANGE_NUMBER_CAR_PR:
		{
			if(!response)
				return all_number_veh_player(playerid);

			dialog_input_number_in_car(playerid);
 
		}
	    case DIALOG_ACCEPT_BUY_CAR_RINOK:
	    {
	    	if(!response) 
	    	{
	    		DeletePVarNew(playerid, "buy_car_id_player");
	    		return true;
	    	}

	    	sell_car_for_player(GetPVarIntNew(playerid,"buy_car_id_player"), playerid);
	    }
	}

	return true;
}

CMD:number_car(playerid)
{
	return all_number_veh_player(playerid);
}

stock all_number_veh_player(playerid)
{
	mysql_format(connect_main, GlobalString, sizeof(GlobalString), "SELECT * FROM vehicle_number_p WHERE player_id = '%d'", pData[playerid][pMysqlID]);
	mysql_tquery(connect_main, GlobalString, "AllNumberVehPlayer", "i", playerid);
	
	return true;
}

callback:: AllNumberVehPlayer(playerid)
{

	new row_count = 0;

	cache_get_row_count(row_count);
	if(row_count) 
	{
		new 
			number_veh_date_input[20],
			number_veh_number[50],
			number_region_veh[20],
			number_type_veh;

		format(GlobalString, sizeof(GlobalString), ""cGREY"№\t"cGREY"Номерной знак\t"cGREY"Дата\n");

	 	for(new i = 0; i < row_count; i++)
		{
			cache_get_value_name_int(i, "number_id", dialog_listitem_values[playerid][i]);
			cache_get_value_name(i,"date_input", number_veh_date_input, 20);
			cache_get_value_name(i,"number", number_veh_number, 50);
			cache_get_value_name(i,"number_region", number_region_veh, 20);

	    	format(GlobalString, sizeof(GlobalString), "%s"cBLUE"%d."cWH"\t"cWH"%s-%d\t"cBLUE"%s"cWH"\n",GlobalString, \
	    		i+1, number_veh_number, number_region_veh, number_veh_date_input);
		}

		SPD(playerid, DIALOG_SELECT_NUMBER_VEH, DIALOG_STYLE_TABLIST_HEADERS ,""cBLUE"Номерные знаки авто",GlobalString,"Открыть","Закрыть");
	}
	else
	{
		SendErr(playerid, "У вас отсутствуют номерные знаки в хранении!");
	}

	return true;
}

stock show_menu_change_number_car(playerid, id)
{
	SetPVarIntNew(playerid, "number_car_select", id);

	new 
		i = pData[playerid][car_id];

	if(i == INVALID_VEHICLE_ID) 
		return SendErr(playerid, "Или Вы не имеете транспортное средство или Вы оно находиться на парковке!");

	mysql_format(connect_main, GlobalString,sizeof(GlobalString),"SELECT * FROM vehicle_number_p WHERE number_id = '%d' AND player_id = '%d'", id, pData[playerid][pMysqlID]);
	mysql_tquery(connect_main, GlobalString, "ChangeNumberCar", "ii", playerid, i);

	return true;
}

callback:: ChangeNumberCar(playerid, i)
{

	new row_count 	= 0;

	cache_get_row_count(row_count);
	if(row_count) 
	{
		new 
			number[20],
			number_region[20],
			number_type;

		cache_get_value_name(0, "number", number, 20);
		cache_get_value_name(0, "number_region", number_region, 20);
		cache_get_value_name_int(0, "number_type", number_type);

		format(GlobalString, sizeof(GlobalString), "\
					"cWH"Вы желаете поставить данные номера на автомобиль?\n\n\
					Вы должны находиться в личном автомобиле, на который хотите их поставить!\n\n\
					Текущий номерной знак: %s | %s\n\
					После замены номерной знак: %s | %s\n\n\
					Старый номерной знак будет помещен в инвентарь и Вы сможете потом воспользоваться",
					vehicle[i][cPlate], vehicle[i][cPlateRegion], number, number_region);
		SPD(playerid, DIALOG_CHANGE_NUMBER_CAR_PR, DIALOG_STYLE_MSGBOX, ""cBLUE"Замена автомобильного номера", GlobalString, "Далее", "Назад");
	}

	return true;
}

stock dialog_input_number_in_car(playerid)
{
	new 
		id = GetPVarIntNew(playerid, "number_car_select");

	new 
		i = pData[playerid][car_id];

	if(i == INVALID_VEHICLE_ID) 
		return SendErr(playerid, "Или Вы не имеете транспортное средство или оно находится на парковке!");

	mysql_format(connect_main, GlobalString,sizeof(GlobalString), "SELECT * FROM vehicle_number_p WHERE number_id = '%d' AND player_id = '%d'", id, pData[playerid][pMysqlID]);
	mysql_tquery(connect_main, GlobalString, "InputNumberInCar", "iii", playerid, i, id);

	return true;
}

callback:: InputNumberInCar(playerid, i, id)
{

	new row_count 		= 0;

	cache_get_row_count(row_count);
	if(row_count) 
	{
		new 
			number[20],
			number_region[20],
			number_type;

		cache_get_value_name(0, "number", number, 20);
		cache_get_value_name(0, "number_region", number_region, 20);
		cache_get_value_name_int(0, "number_type", number_type);

		format(vehicle[i][cPlate], 20, number);
		format(vehicle[i][cPlateRegion], 20, number_region);

		switch(number_type)
		{
			case NUMBER_REGION_RU:
			{
				vehicle[i][cPlateType] = NUMBER_REGION_RU;
				SetVehicleRuNumberPlate(i, vehicle[i][cPlate], vehicle[i][cPlateRegion]);
			}
			case NUMBER_REGION_KZ:
			{
				vehicle[i][cPlateType] = NUMBER_REGION_KZ;	
				SetVehicleKzNumberPlate(i, vehicle[i][cPlate], vehicle[i][cPlateRegion]);
			}
			case NUMBER_REGION_BY:
			{
				vehicle[i][cPlateType] = NUMBER_REGION_BY;
				SetVehicleBuNumberPlate(i, vehicle[i][cPlate]);
			}
			case NUMBER_REGION_UA:
			{
				vehicle[i][cPlateType] = NUMBER_REGION_UA;
				SetVehicleUaNumberPlate(i, vehicle[i][cPlate]);
			}
		}

		mysql_format(connect_main, GlobalString,sizeof(GlobalString),"UPDATE `vehicle_number_p` SET `number` = '%s', `number_region` = '%s', `number_type` = '%d' WHERE `number_id` = '%d'", vehicle[i][cPlate], vehicle[i][cPlateRegion], vehicle[i][cPlateType], id);
		mysql_tquery(connect_main, GlobalString, "", "");

		format(GlobalString, sizeof(GlobalString), "На автомобиль установлен номерной знак - %s | %d", vehicle[i][cPlate], vehicle[i][cPlateRegion]);
		SendSucc(playerid, GlobalString);
	}

	return true;
}

alias:carpass("pts");
CMD:carpass(playerid, params[])
{
	if(!get_player_in_p_car(playerid))
		return SendErr(playerid, "Вы должны сидеть в личном транспорте!");

	if(sscanf(params, "d", params[0]))
	{
		SendCmd(playerid, "/carpass [playerid]");
		return show_player_carpass(playerid, playerid);
	}

	else 
		return offer_player(playerid, params[0], OFFER_CARPASS);
}

CMD:price(playerid, params[])
{
	if(!IsPlayerInDynamicArea(playerid, gAreas[arCarMk]))
		return SendErr(playerid, "Вы должны находиться на авторынке");

	if(GetPVarIntNew(playerid, "CarMarket"))
		return SendErr(playerid, "Ваше авто уже находится на продаже");

	if(!get_player_in_p_car(playerid))
		return SendErr(playerid, "Вы должны сидеть в личном транспорте!");

	new 
		carID = GetPlayerVehicleID(playerid);

	if(vehicle[carID][vehicle_prize] != -1)
		return SendErr(playerid, "Данный автомобиль запрещено продавать другим игрокам!");

	if(sscanf(params, "id", params[0]))
	    return SendInf(playerid, "/price [Цена]");

	if(params[0] < 10000 || params[0] > 100000000)
		return SendInf(playerid, "Цена продажи должна быть не меньше "cBLUE"10000"cWH"руб и более "cBLUE"100 млн. "cWH"руб");
	new 
		Float:x, Float:y, Float:z;
	GetCoordBonnetVehicle(GetPlayerVehicleID(playerid), x, y, z);

	CarMarketPickup[playerid] = CreateDynamicPickup(1239, 1, x, y, z-0.5);
	CarMarketArea[playerid] = CreateDynamicSphere(x, y, z, 2.0, 0,0, -1);

	CMarketInfo[playerid][mOwnerid] = playerid;
	CMarketInfo[playerid][mPrice] = params[0];
	CMarketInfo[playerid][mID] = GetPlayerVehicleID(playerid);
	RemovePlayerFromVehicleEx(playerid);
	SetPVarIntNew(playerid, "CarMarket", 1);

	SendSucc(playerid, "Вы выставили автомобиль на продажу!");
	SendInf(playerid, "Не покидайте авторынок, иначе Ваша продажа будет снята!");
	return true;
}

stock sell_car_for_player(seller_id, buyer_id)
{

	if(!pData[buyer_id][pLicenses][LIC_DRIVING])
		return SendErr(buyer_id, "У вас нет лицензии на управление транспортом!");

	for(new i; i < MAX_PLAYERS_VEHICLE_SL; i++)
	{
		if(CMarketInfo[seller_id][mID] == vehicle_player_max[buyer_id][i])
		{	
			return  SendErr(buyer_id, "Нельзя покупать собственный автомобиль!");
		}
	}

	mysql_format(connect_main, GlobalString, sizeof(GlobalString), "SELECT userid FROM player_vehicles WHERE userid = '%d' LIMIT 8", pData[buyer_id][pMysqlID]);
	mysql_tquery(connect_main, GlobalString, "SellCarForPlayer", "ii", seller_id, buyer_id);

	return true;
}

callback:: SellCarForPlayer(seller_id, buyer_id)
{

	new all_vehicle_player 		= 0;

	cache_get_row_count(all_vehicle_player);

	if(vehicle_player_max_user[buyer_id] == 1 && all_vehicle_player >= 1)
		return SendErr(buyer_id, "У Вас уже имеется автомобиль, рассширение количества слотов доступно только через гараж!");
	if(vehicle_player_max_user[buyer_id] == 2 && all_vehicle_player >= 2)
		return SendErr(buyer_id, "У Вас уже имеется 2 автомобиля, рассширение количества слотов доступно только через гараж!");
	if(vehicle_player_max_user[buyer_id] == 4 && all_vehicle_player >= 4)
		return SendErr(buyer_id, "У Вас уже имеется 4 автомобиля, рассширение количества слотов доступно только через гараж!");
	if(vehicle_player_max_user[buyer_id] == 8 && all_vehicle_player >= 8)
		return SendErr(buyer_id, "У Вас уже 8 имеется автомобилей!");

	if(GetPlayerMoneyEx(buyer_id) < CMarketInfo[seller_id][mPrice])
		return SendErr(buyer_id, "У вас недостаточно денежных средств для покупки данного автомобиля!");

	give_money(buyer_id, -CMarketInfo[seller_id][mPrice], "Покупка автомобиля");
	give_money(seller_id, CMarketInfo[seller_id][mPrice], "Продажа автомобиля");

	vehicle_player_count_car_load[seller_id]--;

	new 
		vehicle_sql;

	for(new i; i < MAX_PLAYERS_VEHICLE_SL; i++)
	{
		if(CMarketInfo[seller_id][mID] == vehicle_player_max[seller_id][i])
		{	
			vehicle_sql = vehicle_player_max_sql[seller_id][i];
			break;
		}
	}

    mysql_format(connect_main, GlobalString, sizeof(GlobalString), "UPDATE `player_vehicles` SET \
    	userid = '%d',\
    	number = '0',\
    	number_region = '0'\
    	WHERE id = '%d' AND userid = '%d'",
    	pData[buyer_id][pMysqlID], vehicle_sql, pData[seller_id][pMysqlID]);
	mysql_tquery(connect_main, GlobalString, "", "");	

	new 
		Float:x, Float:y, Float:z, Float:r;

	GetVehiclePos(CMarketInfo[seller_id][mID],x,y,z);
	GetVehicleZAngle(CMarketInfo[seller_id][mID],r);

	if(!IsPlayerHaveHouse(buyer_id) && !GetPlayerFlateCount(buyer_id) && pData[buyer_id][pGarage] == -1
	|| !IsPlayerHaveHouse(buyer_id) && !GetPlayerFlateCount(buyer_id) && pData[buyer_id][pGarage] != -1
	|| !IsPlayerHaveHouse(buyer_id) && GetPlayerFlateCount(buyer_id) && pData[buyer_id][pGarage] == -1
	|| IsPlayerHaveHouse(buyer_id) && !GetPlayerFlateCount(buyer_id) && pData[buyer_id][pGarage] == -1
	|| !IsPlayerHaveHouse(buyer_id) && !GetPlayerFlateCount(buyer_id) && pData[buyer_id][pGarage] == -1 && pData[buyer_id][pFlateRent] == -1 && pData[buyer_id][pHouseRent] != -1
	|| !IsPlayerHaveHouse(buyer_id) &&!GetPlayerFlateCount(buyer_id) && pData[buyer_id][pGarage] == -1 && pData[buyer_id][pFlateRent] != -1 && pData[buyer_id][pHouseRent] == -1)
	{		
		new 
			car_vw = GetVehicleVirtualWorld(CMarketInfo[seller_id][mID]);

	    mysql_format(connect_main, GlobalString, sizeof(GlobalString), "UPDATE `player_vehicles` SET \
	    	parking_x = '%.4f',\
	    	parking_y = '%.4f',\
	    	parking_z = '%.4f',\
	    	parking_a = '%.4f',\
	    	parking_vw = '%d'\
	    	WHERE id = '%d' AND userid = '%d'",
			x,
			y,
			z,
			r,
			car_vw,

	    	vehicle_sql, pData[buyer_id][pMysqlID]);
		mysql_tquery(connect_main, GlobalString, "", "");	

		SPD(buyer_id, 0, DIALOG_STYLE_MSGBOX, ""cBLUE"Покупка автомобиля", "\
		"cWH"Поздравляем Вас с приобретением автомобиля!\n\n\
		"cBLUE"-"cWH" Отпарковать автомобиль: /unpark\n\
		"cBLUE"-"cWH" Припарковать автомобиль: /park\
		"cBLUE"-"cWH" Найти автомобиль: /findcar\n\n\
		Автомобиль находится на авторынке!\n\
		Чтобы забрать его, используйте команду - /cars", "Далее", "");		

	}
	else
	{
		new random_pos = gen_random_position_parking(buyer_id);

		new 
			car_vw = VIRTUAL_WORLD_PARKING_1;

	    mysql_format(connect_main, GlobalString, sizeof(GlobalString), "UPDATE `player_vehicles` SET \
	    	parking_x = '%.4f',\
	    	parking_y = '%.4f',\
	    	parking_z = '%.4f',\
	    	parking_a = '%.4f',\
	    	parking_vw = '%d'\
	    	WHERE id = '%d' AND userid = '%d'",
			parking_vehicle_position_spawn[random_pos][0], parking_vehicle_position_spawn[random_pos][1], parking_vehicle_position_spawn[random_pos][2], parking_vehicle_position_spawn[random_pos][3],
			car_vw,
	    	vehicle_sql, pData[buyer_id][pMysqlID]);

		mysql_tquery(connect_main, GlobalString, "", "");	

		SPD(buyer_id, 0, DIALOG_STYLE_MSGBOX, ""cBLUE"Покупка автомобиля", "\
		"cWH"Поздравляем Вас с приобретением автомобиля!\n\n\
		"cBLUE"-"cWH" Отпарковать автомобиль: /unpark\n\
		"cBLUE"-"cWH" Припарковать автомобиль: /park\
		"cBLUE"-"cWH" Найти автомобиль: /findcar\n\n\
		Автомобиль находится на штрафстоянке!\n\
		Чтобы отметить его, используйте команду - /cars", "Далее", "Нет");		

	}	
	format(GlobalString, sizeof(GlobalString), "Продажа автомобиля на рынке игроку %s[%d] | SQL ID: %d | SERVER ID: %d | Марка: %s по цене в %d рублей", pData[buyer_id][pNickname], buyer_id, vehicle_sql, CMarketInfo[seller_id][mID], transport_config[GetVehicleModel(CMarketInfo[seller_id][mID])-400][transport_name], CMarketInfo[seller_id][mPrice]);
    logs_vehicle(seller_id, pData[seller_id][pMysqlID], GlobalString);
	format(GlobalString, sizeof(GlobalString), "Покупка автомобиля на рынке у %s[%d] | SQL ID: %d | SERVER ID: %d | Марка: %s по цене в %d рублей", pData[seller_id][pNickname], seller_id, vehicle_sql, CMarketInfo[seller_id][mID], transport_config[GetVehicleModel(CMarketInfo[seller_id][mID])-400][transport_name], CMarketInfo[seller_id][mPrice]);
    logs_vehicle(buyer_id, pData[buyer_id][pMysqlID], GlobalString);

	destroy_player_vehicle_id(seller_id, vehicle_sql);



	DestroyDynamicPickup(CarMarketPickup[seller_id]);
	DestroyDynamicArea(CarMarketArea[seller_id]);
	DeletePVarNew(seller_id, "CarMarket");
	CMarketInfo[seller_id][mOwnerid] = -1;
	CMarketInfo[seller_id][mPrice] = 0;
	CMarketInfo[seller_id][mID] = 0;	



	SendSucc(seller_id, "Вы успешно продали свой автомобиль!");
	SendSucc(buyer_id, "Вы успешно приобрели автомобиль!");

	return true;
}


stock stop_sell_car_player(playerid)
{
	if(GetPVarIntNew(playerid, "CarMarket"))
	{
		DestroyDynamicPickup(CarMarketPickup[playerid]);
		DestroyDynamicArea(CarMarketArea[playerid]);
		DeletePVarNew(playerid, "CarMarket");
		CMarketInfo[playerid][mOwnerid] = -1;
		CMarketInfo[playerid][mPrice] = 0;
		CMarketInfo[playerid][mID] = 0;
		SendInf(playerid, "Ваша машина была снята с продажи, так как Вы покинули авторынок!");
	}

	return true;
}


stock GetPlayerVehiclesCount(const playerid)
{
	mysql_format(connect_main, GlobalString, sizeof(GlobalString), "SELECT userid FROM player_vehicles WHERE userid = '%d' LIMIT 8", pData[playerid][pMysqlID]);
	mysql_tquery(connect_main, GlobalString, "GetPlayerVehCount", "i", playerid);

	return true;
}

callback:: GetPlayerVehCount(playerid)
{
	new all_vehicle_player 		= 0;

	cache_get_row_count(all_vehicle_player);
	
	player_cars_count[playerid] = all_vehicle_player;

	return true;
}

stock HasReachedLimitVehicles(const playerid)
{

	GetPlayerVehiclesCount(playerid);

	new
		vehicles = player_cars_count[playerid];

	if(vehicles >= vehicle_player_max_user[playerid])
		return 1;

	return 0;
}

/*
			vehicle_player_max_sql[playerid][i] = sql_id;
			vehicle_player_max[playerid][i] = veh_id;
*/

stock SellCarToPlayer(const seller, const buyer)
{
	new	
		vehicle_id = GetPlayerVehicleID(seller),
		price = pTemp[seller][pSellCarPrice];

	if(pTemp[seller][pSellCarOffer] == INVALID_PLAYER_ID ||
		pTemp[buyer][pSellCarOffer] == INVALID_PLAYER_ID)
		return 1;

	if(GetPlayerMoneyEx(buyer) < price)
	{
		SendErr(seller, "У игрока нет такой суммы");
		return SendErr(buyer, "У вас нет такой суммы");
	}

	if(HasReachedLimitVehicles(buyer))
	{
		SendErr(seller, "У игрока превышен лимит авто");
		return SendErr(buyer, "Вы превысили лимит авто");		
	}

	for(new i; i < MAX_PLAYERS_VEHICLE_SL; i++)
	{
		if(vehicle_player_max[seller][i] == vehicle_id)
		{
			vehicle_player_max_sql[seller][i] = 0;
			vehicle_player_max[seller][i] = 0;
			DestroyVehicle(vehicle_id);
			break;
		}
	}

	mysql_format(connect_main, GlobalString, sizeof(GlobalString), "UPDATE `player_vehicles` SET userid = '%d' WHERE id = '%d'",
		pData[buyer][pMysqlID], 
		pTemp[seller][pSellCarID]
	);

	mysql_tquery(connect_main, GlobalString, "", "");

	SendInf(seller, "Вы успешно продали авто");
	SendInf(buyer, "Поздравляем с покупкой авто");

	give_money(buyer, -price, "Покупка Т/С");
	give_money(seller, price, "Продажа Т/С");

	pTemp[seller][pSellCarID] 		=
	pTemp[seller][pSellCarPrice] 	= 0;
	            
	pTemp[seller][pSellCarOffer] 	=
	pTemp[buyer][pSellCarOffer] 	= INVALID_PLAYER_ID;

	return 1;
}

stock SendOfferToSellcar(const playerid, const buyer, const price)
{
	if(!get_player_in_p_car(playerid))
		return SendErr(playerid, "Вы должны сидеть в личном транспорте!");

	if(pTemp[buyer][pSellCarOffer]  != INVALID_PLAYER_ID)
		return SendErr(playerid, "Игроку уже предложили купить авто");

	new 
		transport = GetVehicleModel(GetPlayerVehicleID(playerid))-400;

	format(GlobalString, sizeof(GlobalString), 
		"\n"cWH"Игрок"cBLUE"%s"cWH" предлагает вам купить его автомобиль\n\n\
		"cWH"Автомобиль: "cBLUE"%s\n\
		"cWH"Класс автомобиля:" cBLUE"%s\n\
		"cWH"Макс. скорость: "cBLUE"%d КМ/Ч\n\
		"cWH"Тип топлива: "cBLUE"%s\n\
		"cWH"Объём бака: "cBLUE"%d литров\n\
		"cWH"Пробег: "cBLUE"%d км\n\n\
		"cWH"Цена: "cGR"%i\n\n\
		"cWH"Желаете ли Вы купить данное транспортное средство?", 
	pData[playerid][pNickname],
	transport_config[transport][transport_name],
	get_class_veh(transport),
	transport_config[transport][transport_max_speed],
	get_fuel_type_veh(transport),
	transport_config[transport][transport_tank],
	floatround(vehicle[GetPlayerVehicleID(playerid)][cMileage]),
	price);

	pTemp[playerid][pSellCarOffer] = buyer;
	pTemp[buyer][pSellCarOffer] = playerid;

	pTemp[playerid][pSellCarID] = GetPlayerVehicleID(playerid);
	pTemp[playerid][pSellCarPrice] = price;

	SendInf(playerid, "Предложение игроку было выслано.");
	
	SPD(buyer, D_SELLCAR, DIALOG_STYLE_MSGBOX, ""cBLUE"Покупка автомобиля", GlobalString, "Согласиться", "Отказаться");

	return 1;
}

CMD:sellmycar(playerid, params[])
{
	if(sscanf(params, "ud", params[0], params[1]))
	    return SendInf(playerid, "/sellmycar [playerid] [price]");

	//if(vehicle[GetPlayerVehicleID(playerid)][tempcar])
	//	return SendClientMessage(playerid, -1, "Вы не можете продать временный транспорт!");

	if(params[1] < 1000 || params[1] > 100000000)
		return SendInf(playerid, "Цена продажи должна быть не меньше "cBLUE"1000"cWH"руб и более "cBLUE"100 млн. "cWH"руб");

    if(!IsPlayerConnected(params[0]))
        return SendErr(playerid, "Данного игрока нет в сети");

	if(params[0] == playerid)
		return SendErr(playerid, "Нельзя предложить гонку себе");

	SendOfferToSellcar(playerid, params[0], params[1]);

	return 1;
}