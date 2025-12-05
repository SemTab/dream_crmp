
static const Float:position_miner_sklad_street[][] = 
{
	{-1444.9508,2562.8396,40.8068},
	{-1426.0107,2558.2993,40.7999},
	{-1423.7823,2563.1147,40.7999},
	{-1466.3666,2577.9658,40.7999},
	{-1448.3967,2575.3279,40.7999},
	{-1446.0856,2580.1858,40.7999}
};

static const Float:position_miner_miner[][] = 
{
	{-736.9471,-2713.6250,-24.9199},
	{-736.4311,-2716.4590,-25.0377},
	{-734.2178,-2717.8420,-24.9451},
	{-731.6727,-2737.5095,-25.1813},
	{-727.0529,-2738.8103,-24.9323},
	{-727.9414,-2741.5286,-25.0053},
	{-727.3435,-2743.2881,-24.9443},
	{-738.7495,-2763.4307,-25.0421},
	{-739.8450,-2765.4453,-24.9493}
};

static const Float:position_miner_lift_load[][] =
{
	{-737.4175,-2720.5295,-25.1735},
	{-731.5936,-2743.4490,-25.1735},
	{-742.9550,-2762.4954,-25.1735}

};

static const Float:position_miner_konveer[][] =
{
	{-761.6714,-2743.2786,-22.2516},
	{-762.5749,-2744.6230,-22.2516},
	{-763.8065,-2745.5740,-22.2516},
	{-765.4480,-2746.1179,-22.2516},
	{-767.2107,-2746.0449,-22.2516},
	{-765.7867,-2736.3303,-22.2516},
	{-767.2039,-2736.4363,-22.2516},
	{-768.8127,-2737.1040,-22.2516},
	{-769.9372,-2738.0923,-22.2516},
	{-770.8091,-2739.6377,-22.2516},
	{-771.0752,-2741.2256,-22.2516},
	{-770.7519,-2742.9868,-22.2516},
	{-769.9774,-2744.3325,-22.2516}

};

static const Float:position_miner_complect[][] =
{
	{-755.9485,-2775.0239,-19.9000},
	{-754.1071,-2776.4417,-19.9000},
	{-751.5536,-2778.7798,-19.9000},
	{-757.4738,-2772.8083,-19.9000}

};

stock create_other_pickup_samwill()
{
	actor_miner = CreateActor(27, -1366.4304,2648.7744,40.5476,216.2885);
	ApplyActorAnimation(actor_miner, "COP_AMBIENT", "coplook_loop", 4.1, 1, 1, 1, 0, 0);


	// Выбор одежды

	CreateDynamicPickup(13724, 23, -1365.8309,2647.9309,40.5409, -1, -1, -1, 45.0);
	area_clothes_pickup_miner = CreateDynamicSphere(-1365.8309,2647.9309,40.5409, 1.5, -1, -1);
	CreateDynamic3DTextLabel(""cWH"Шахтёр Григорий\n"cBLUE"Работа",-1, \
	-1365.8309,2647.9309,40.5409, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);		

	// Вход и выход - 1	
	CreateDynamicPickup(13702, 23, -1367.1261,2583.5620,40.3656, -1, -1, -1, 45.0);
	area_enter_miner_1[0] = CreateDynamicSphere(-1367.1261,2583.5620,40.3656, 1.5, -1, -1); 
	CreateDynamic3DTextLabel(""cWH"Вход в шахту\n"cBLUE"Рудник №1",-1, \
	-1367.1261,2583.5620,40.3656, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	

	CreateDynamicPickup(13702, 23, -1365.3413,2563.4783,40.3924, -1, -1, -1, 45.0);
	area_enter_miner_1[1] = CreateDynamicSphere(-1365.3413,2563.4783,40.3924, 1.5, -1, -1); 
	CreateDynamic3DTextLabel(""cWH"Вход в шахту\n"cBLUE"Рудник №1",-1, \
	-1365.3413,2563.4783,40.3924, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	


	CreateDynamicPickup(13702, 23, -756.8095,-2780.7559,-19.9000, -1, -1, -1, 45.0);
	area_exit_miner_1[0] = CreateDynamicSphere(-756.8095,-2780.7559,-19.9000, 1.0, -1, -1); 
	CreateDynamic3DTextLabel(""cWH"Выход из шахты\n"cBLUE"На поверхность",-1, \
	-756.8095,-2780.7559,-19.9000, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	

	CreateDynamicPickup(13702, 23, -774.5630,-2735.4355,-22.2516, -1, -1, -1, 45.0);
	area_exit_miner_1[1] = CreateDynamicSphere(-774.5630,-2735.4355,-22.2516, 1.0, -1, -1); 
	CreateDynamic3DTextLabel(""cWH"Выход из шахты\n"cBLUE"На поверхность",-1, \
	-774.5630,-2735.4355,-22.2516, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);		

	// Вход и выход - 2
	CreateDynamicPickup(13702, 23, -1392.2941,2550.6074,40.3924, -1, -1, -1, 45.0);
	area_enter_miner_2[0] = CreateDynamicSphere(-1392.2941,2550.6074,40.3924, 1.5, -1, -1); 
	CreateDynamic3DTextLabel(""cWH"Вход в шахту\n"cBLUE"Рудник №2",-1, \
	-1392.2941,2550.6074,40.3924, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	

	CreateDynamicPickup(13702, 23, -1390.5918,2530.5288,40.3924, -1, -1, -1, 45.0);	
	area_enter_miner_2[1] = CreateDynamicSphere(-1390.5918,2530.5288,40.3924, 1.5, -1, -1); 
	CreateDynamic3DTextLabel(""cWH"Вход в шахту\n"cBLUE"Рудник №2",-1, \
	-1390.5918,2530.5288,40.3924, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);		

	CreateDynamicMapIcon(-1392.2941,2550.6074,40.3924, 11, COLOR_WHITE, 0, -1, -1, 100.0);
	CreateDynamicMapIcon(-1390.5918,2530.5288,40.3924, 11, COLOR_WHITE, 0, -1, -1, 100.0);
	CreateDynamicMapIcon(-1367.1261,2583.5620,40.3656, 11, COLOR_WHITE, 0, -1, -1, 100.0);
	CreateDynamicMapIcon(-1365.3413,2563.4783,40.3924, 11, COLOR_WHITE, 0, -1, -1, 100.0);

	CreateDynamicMapIcon(-1418.1997,2582.6719,40.3924, 51, COLOR_WHITE, 0, -1, -1, 100.0);
	CreateDynamicMapIcon(-1440.1375,2599.7104,41.3535, 51, COLOR_WHITE, 0, -1, -1, 100.0);

	CreateDynamic3DTextLabel(""cWH"«Загрузка руды»\n"cBLUE"Бокс №1\n\n[Посигнальте]",-1, \
	-1418.1997,2582.6719,40.3924, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	

	CreateDynamic3DTextLabel(""cWH"«Загрузка руды»\n"cBLUE"Бокс №1\n\n[Посигнальте]",-1, \
	-1440.1375,2599.7104,41.3535, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	


	for(new i; i < sizeof(position_miner_sklad_street); i++)
	{
		area_sklad_miner_street[i] = create_circle_pickup(position_miner_sklad_street[i][0], position_miner_sklad_street[i][1], position_miner_sklad_street[i][2]+0.15, TRIGGER_LRED);

		format(String144, sizeof(String144), "\
		«Склад руды»\n\
		"cLRED"№%d", i+1);

		CreateDynamic3DTextLabel(String144, -1, position_miner_sklad_street[i][0], position_miner_sklad_street[i][1], position_miner_sklad_street[i][2], 15.0);

		CreateDynamicMapIcon(position_miner_sklad_street[i][0], position_miner_sklad_street[i][1], position_miner_sklad_street[i][2], 56, COLOR_WHITE, 0, -1, -1, 100.0);

	}

	for(new i; i < sizeof(position_miner_miner); i++)
	{
		//13720 - для мобайл

		area_miner_start[i] = CreateDynamicSphere(position_miner_miner[i][0], position_miner_miner[i][1], position_miner_miner[i][2], 2.0, -1, -1); 
		CreateDynamicPickup(13720, 23, position_miner_miner[i][0], position_miner_miner[i][1], position_miner_miner[i][2]-1.0, -1, -1, -1, 45.0);	
	}

	for(new i; i < sizeof(position_miner_lift_load); i++)
	{	
		//13703 - для мобайл
		CreateDynamic3DTextLabel("Грузовой Лифт\n"cLRED"[Отправка руды на конвеер]", -1, position_miner_lift_load[i][0], position_miner_lift_load[i][1], position_miner_lift_load[i][2], 5.0);
		CreateDynamicPickup(13703, 23, position_miner_lift_load[i][0], position_miner_lift_load[i][1], position_miner_lift_load[i][2], -1, -1, -1, 45.0);	
		area_lift_load_miner[i] = CreateDynamicSphere(position_miner_lift_load[i][0], position_miner_lift_load[i][1], position_miner_lift_load[i][2], 1.0, -1, -1);
	}

	for(new i; i < sizeof(position_miner_konveer); i++)
	{
		CreateDynamic3DTextLabel("Сортировка руды\n"cLRED"[Подготовка руды к укомплектовке]", -1, position_miner_konveer[i][0], position_miner_konveer[i][1], position_miner_konveer[i][2], 2.0);
		area_konveer_miner[i] = CreateDynamicSphere(position_miner_konveer[i][0], position_miner_konveer[i][1], position_miner_konveer[i][2], 1.0, -1, -1);
		create_circle_pickup_o(position_miner_konveer[i][0], position_miner_konveer[i][1], position_miner_konveer[i][2], TRIGGER_LRED);
	}
	for(new i; i < sizeof(position_miner_complect); i++)
	{
		CreateDynamic3DTextLabel("Укомплектовка руды\n"cLRED"[Подготовка руды к хранению]", -1, position_miner_complect[i][0], position_miner_complect[i][1], position_miner_complect[i][2], 2.0);
		area_complect_miner[i] = CreateDynamicSphere(position_miner_complect[i][0], position_miner_complect[i][1], position_miner_complect[i][2], 1.5, -1, -1);
		create_circle_pickup_o(position_miner_complect[i][0], position_miner_complect[i][1], position_miner_complect[i][2], TRIGGER_LRED);
	
	}
	return true;
}

stock dialog_miner_job(playerid)
{

    format(String256, sizeof(String256), "\
    "cGREY"№\t"cGREY"Шахтёров\n\
    "cBLUE"1. "cWH"Работа шахтёром\t"cBLUE"%d"cWH" работает\n\
    "cBLUE"2. "cWH"Информация о работе", count_job_miner);
    return SPD(playerid, DIALOG_SELECT_JOB_MINER, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Работа шахётером", String256, !"Выбрать", !"Закрыть"); 
}

stock start_miner_job(playerid)
{
	if(pData[playerid][pSex] == 2)
	{
		SetPlayerSkin(playerid, 13);	
	}
	else
	{
		SetPlayerSkin(playerid, 27);
	}	
	SCM(playerid, -1, "");

	if(get_job_level(playerid, SKILL_MINER) < 5)
	{
		SFCM(playerid, COLOR_ORANGE, "[Навык] "cWH"Ваш навык шахтера: "cGR"%d уровень"cWH"", get_job_level(playerid, SKILL_MINER), get_job_level_next(playerid, SKILL_MINER));
		SFCM(playerid, COLOR_ORANGE, "[Навык] "cWH"Для повышения навыка необходимо выполнить работу "cGR"%d"cWH" раз!", get_job_level_next(playerid, SKILL_MINER));
	}
	else
	{
		SFCM(playerid, COLOR_ORANGE, "[Навык] "cWH"Ваш навык шахтера: "cGR"%d уровень", get_job_level(playerid, SKILL_MINER));
	}

	SendSucc(playerid, "Вы успешно начали рабочий день шахтером!");
	SendInf(playerid, "Отправляйтесь к лифту и спускайте в один из 10 тоннелей!");
	SendInf(playerid, "Начинайте добывать руду в одной из 3-ех жил шахты!");

	SetPVarIntNew(playerid, "miner_job", 1);
	SetPVarIntNew(playerid, "miner_job_count", 0);
	SetPVarIntNew(playerid, "miner_type_work", STAP_JOB_MINER_MINING);

	DeletePVarNew(playerid, "mining_count_diamond");

	count_job_miner++;

	return true;
}
stock end_miner_job(playerid)
{
	if(!GetPVarIntNew(playerid, "miner_job")) return true;

	SCM(playerid, -1, "");
	SendSucc(playerid, "Вы успешно завершили рабочий день шахтёром!");


	SetPlayerSkin(playerid, pData[playerid][pSkin]);

	new
		price;

	price = (get_job_level(playerid, SKILL_WOODCUTTER) * 100) * (GetPVarInt(playerid,"miner_job_count")*50);

    format(String144, sizeof(String144), "Вы заработали "cGR"%d "cWH"рублей!", price);
    SendInf(playerid, String144);

	DeletePVarNew(playerid, "miner_job");
	DeletePVarNew(playerid, "miner_job_count");
	SetPVarIntNew(playerid, "miner_type_work", STAP_JOB_MINER_NONE);

	count_job_miner--;

	return true;
}

stock info_job_miner(playerid)
{

    format(String2048, sizeof(String2048), "\
        "cBLUE"-"cWH" Здравствуйте всем, привет всем, меня зовут Григорий\n\
        и мы рады приветствовать вас на горнодобывающем предприятии города Арзамас!\n\n\
		"cBLUE"-"cWH" Вам не нужно проходить кастинг, чтобы занять одно из мест в нашей шахте, \n\
		одевайте на себя костюм шахтёра и топайте к рудникам, накрытым металлическим куполом\n\
		"cBLUE"-"cWH" Спуститесь на лифте под землю и следуйте вниз по тоннелю, чтобы наконец \n\
		взяться за кирку и приступить к войне с камнями\n\
		"cBLUE"-"cWH" Добывайте полезные ископаемые до той самой поры, пока вас не отправят на их сортировку\n\
		"cBLUE"-"cWH" Чтобы избежать однообразия вам потребуется выполнять работу в шахте поэтапно\n\
		После того, как вы добудете достаточное количество руды и отнесёте её к отгрузочному лифту, \n\
		направляйтесь к конвейеру и отсортируйте то, что вам удалось добыть\n\
		"cBLUE"-"cWH" Закончив с сортировкой идите к нашему малому складу, который находится в конце конвейера\n\
		 и укомплектуйте ископаемые по ящикам с наименованиями, крепко-накрепко закройте их крышками и отнесите на\n\
		  основной склад, который располагается за мостом, на улице. Не заблудитесь!");
	return SPD(playerid, DIALOG_INFO_JOB_MINER_FINAL, DIALOG_STYLE_MSGBOX, !""cBLUE"Разговор с Григорием", String2048, !"Понятно", !"");

}

stock enter_area_miner_1(playerid)
{
    format(String1024, sizeof(String1024), "\
    "cGREY"№\t"cGREY"Количество шахтёров\n\
    "cWH"Тоннель "cBLUE"№1"cWH"\t"cBLUE"%d/25"cWH" шахтёров\n\
    "cWH"Тоннель "cBLUE"№2"cWH"\t"cBLUE"%d/25"cWH" шахтёров\n\
    "cWH"Тоннель "cBLUE"№3"cWH"\t"cBLUE"%d/25"cWH" шахтёров\n\
    "cWH"Тоннель "cBLUE"№4"cWH"\t"cBLUE"%d/25"cWH" шахтёров\n\
    "cWH"Тоннель "cBLUE"№5"cWH"\t"cBLUE"%d/25"cWH" шахтёров\n\
    "cWH"Тоннель "cBLUE"№6"cWH"\t"cBLUE"%d/25"cWH" шахтёров\n\
    "cWH"Тоннель "cBLUE"№7"cWH"\t"cBLUE"%d/25"cWH" шахтёров\n\
    "cWH"Тоннель "cBLUE"№8"cWH"\t"cBLUE"%d/25"cWH" шахтёров\n\
    "cWH"Тоннель "cBLUE"№9"cWH"\t"cBLUE"%d/25"cWH" шахтёров\n\
    "cWH"Тоннель "cBLUE"№10"cWH"\t"cBLUE"%d/25"cWH" шахтёров", 
    area_miner_1_count[0],
    area_miner_1_count[1],
    area_miner_1_count[2],
    area_miner_1_count[3],
    area_miner_1_count[4],
    area_miner_1_count[5],
    area_miner_1_count[6],
    area_miner_1_count[7],
    area_miner_1_count[8],
    area_miner_1_count[9]);
    return SPD(playerid, DIALOG_SELECT_TUNNEL_MINER_1, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Шахта", String1024, !"Выбрать", !"Закрыть"); 
}


stock enter_area_miner_2(playerid)
{
    format(String1024, sizeof(String1024), "\
    "cGREY"№\t"cGREY"Количество шахтёров\n\
    "cWH"Тоннель "cBLUE"№1"cWH"\t"cBLUE"%d/25"cWH" шахтёров\n\
    "cWH"Тоннель "cBLUE"№2"cWH"\t"cBLUE"%d/25"cWH" шахтёров\n\
    "cWH"Тоннель "cBLUE"№3"cWH"\t"cBLUE"%d/25"cWH" шахтёров\n\
    "cWH"Тоннель "cBLUE"№4"cWH"\t"cBLUE"%d/25"cWH" шахтёров\n\
    "cWH"Тоннель "cBLUE"№5"cWH"\t"cBLUE"%d/25"cWH" шахтёров\n\
    "cWH"Тоннель "cBLUE"№6"cWH"\t"cBLUE"%d/25"cWH" шахтёров\n\
    "cWH"Тоннель "cBLUE"№7"cWH"\t"cBLUE"%d/25"cWH" шахтёров\n\
    "cWH"Тоннель "cBLUE"№8"cWH"\t"cBLUE"%d/25"cWH" шахтёров\n\
    "cWH"Тоннель "cBLUE"№9"cWH"\t"cBLUE"%d/25"cWH" шахтёров\n\
    "cWH"Тоннель "cBLUE"№10"cWH"\t"cBLUE"%d/25"cWH" шахтёров", 
    area_miner_2_count[0],
    area_miner_2_count[1],
    area_miner_2_count[2],
    area_miner_2_count[3],
    area_miner_2_count[4],
    area_miner_2_count[5],
    area_miner_2_count[6],
    area_miner_2_count[7],
    area_miner_2_count[8],
    area_miner_2_count[9]);
    return SPD(playerid, DIALOG_SELECT_TUNNEL_MINER_2, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Шахта", String1024, !"Выбрать", !"Закрыть"); 
}

stock enter_miner_tonnel_1(playerid, level_tonnel)
{

	SetPlayerVirtualWorld(playerid, 100+level_tonnel);

	area_miner_1_count[level_tonnel+1]++;

	SetPVarIntNew(playerid, "level_tonnel_enter", level_tonnel+1);

	if(GetPVarIntNew(playerid, "miner_enter_type_1") != 2)
	{
		SetPlayerPosEx(playerid, -756.5771,-2778.7778,-19.8922,2.0747);
	}
	else
	{
		SetPlayerPosEx(playerid, -771.7273,-2735.6582,-22.2444,267.0453);
	}

	SetCameraBehindPlayer(playerid);

	DeletePVarNew(playerid, "miner_enter_type_1");

    format(String144, sizeof(String144), "Вы успешно спустились в тоннель №%d в руднике №1", level_tonnel+1);
    SendSucc(playerid, String144);

	return true;
}

stock exit_miner_tonnel_1(playerid)
{

	SetPlayerVirtualWorld(playerid, 0);

	if(area_miner_1_count[GetPVarIntNew(playerid, "level_tonnel_enter")] != 0)
	{
		area_miner_1_count[GetPVarIntNew(playerid, "level_tonnel_enter")]--;
	}
	if(GetPVarIntNew(playerid, "miner_enter_type_1") != 2)
	{
		SetPlayerPosEx(playerid, -1368.0619,2584.5730,40.3652,52.9311);
	}
	else
	{
		SetPlayerPosEx(playerid, -1366.6008,2562.7017,40.3924,116.3118);
	}

	SetCameraBehindPlayer(playerid);

	DeletePVarNew(playerid, "miner_enter_type_1");
	return true;
}


stock enter_miner_tonnel_2(playerid, level_tonnel)
{

	SetPlayerVirtualWorld(playerid, 200+level_tonnel);

	area_miner_2_count[level_tonnel+1]++;

	if(GetPVarIntNew(playerid, "miner_enter_type_1") != 2)
	{
		SetPlayerPosEx(playerid, -756.4721,-2776.8491,-19.9000,38.8201);
	}
	else
	{
		SetPlayerPosEx(playerid, -772.4585,-2736.8489,-22.2516,202.4413);
	}

	SetCameraBehindPlayer(playerid);

	DeletePVarNew(playerid, "miner_enter_type_1");

    format(String144, sizeof(String144), "Вы успешно спустились в тоннель №%d в руднике №2", level_tonnel+1);
    SendSucc(playerid, String144);

	return true;
}

stock exit_miner_tonnel_2(playerid)
{

	SetPlayerVirtualWorld(playerid, 0);

	if(area_miner_2_count[GetPVarIntNew(playerid, "level_tonnel_enter")] != 0)
	{
		area_miner_2_count[GetPVarIntNew(playerid, "level_tonnel_enter")]--;
	}
	if(GetPVarIntNew(playerid, "miner_enter_type_1") != 2)
	{
		SetPlayerPosEx(playerid, -1393.6300,2551.3000,40.3924,51.7896);
	}
	else
	{
		SetPlayerPosEx(playerid, -1392.0955,2529.8174,40.3924,97.6003);
	}

	SetCameraBehindPlayer(playerid);

	DeletePVarNew(playerid, "miner_enter_type_1");
	return true;
}

stock dialog_all_miner(playerid, dialogid, response, listitem, inputtext[])
{

	switch(dialogid)
	{
		case DIALOG_INFO_JOB_MINER_FINAL:
		{
			if(!response)
				return dialog_miner_job(playerid);

			return dialog_miner_job(playerid);


		}
		case DIALOG_SELECT_JOB_MINER:
		{
			if(!response)
				return true;

			switch(listitem)
			{
				case 0:
				{
					if(!GetPVarIntNew(playerid, "miner_job"))
						return start_miner_job(playerid);
					else
						return end_miner_job(playerid);
				}
				case 1: return info_job_miner(playerid);
			}			
		}
		case DIALOG_SELECT_TUNNEL_MINER_1:
		{
			if(!response)
				return true;

			switch(listitem)
			{
				case 0: return enter_miner_tonnel_1(playerid, 0);
				case 1: return enter_miner_tonnel_1(playerid, 1);
				case 2: return enter_miner_tonnel_1(playerid, 2);
				case 3: return enter_miner_tonnel_1(playerid, 3);
				case 4: return enter_miner_tonnel_1(playerid, 4);
				case 5: return enter_miner_tonnel_1(playerid, 5);
				case 6: return enter_miner_tonnel_1(playerid, 6);
				case 7: return enter_miner_tonnel_1(playerid, 7);
				case 8: return enter_miner_tonnel_1(playerid, 8);
				case 9: return enter_miner_tonnel_1(playerid, 9);
			}
		}
		case DIALOG_SELECT_TUNNEL_MINER_2:
		{
			if(!response)
				return true;

			switch(listitem)
			{
				case 0: return enter_miner_tonnel_2(playerid, 0);
				case 1: return enter_miner_tonnel_2(playerid, 1);
				case 2: return enter_miner_tonnel_2(playerid, 2);
				case 3: return enter_miner_tonnel_2(playerid, 3);
				case 4: return enter_miner_tonnel_2(playerid, 4);
				case 5: return enter_miner_tonnel_2(playerid, 5);
				case 6: return enter_miner_tonnel_2(playerid, 6);
				case 7: return enter_miner_tonnel_2(playerid, 7);
				case 8: return enter_miner_tonnel_2(playerid, 8);
				case 9: return enter_miner_tonnel_2(playerid, 9);
			}
		}
	}


	return true;
}

stock attach_miner_stone(playerid, type_stone, type_stone_bone) 
{

	switch(type_stone) 
	{
		case STONE_IRON: 
		{
			switch(type_stone_bone) 
			{
				case ATTACH_HAND_MINER: 
				{
					switch(random(3)) 
					{
						case 0: 
						{
							SetPlayerAttachedObject(playerid, 6, 906, 6,
								-0.158999, 0.158999, -0.167999, 
								-87.400009, 0.000000, 0.000000, 
								0.079000,0.140999, 0.113000);
						}
						case 1: 
						{
							SetPlayerAttachedObject(playerid, 6, 905, 6,
								-0.050000, 0.061000, -0.155000, 
								0.000000, -109.100036, 0.000000,
								1.158001, 0.462999, 0.644000);
						}
						case 2: 
						{
							SetPlayerAttachedObject(playerid, 6, 758, 6,
								0.102999, -0.142999, -0.385000, 
								-121.399940, -25.000074, 86.600006,
								0.358001, 0.113999, 0.216000);
						}
					}
				}
			}
		}
		case STONE_MED: 
		{
			switch(type_stone_bone) 
			{
				case ATTACH_HAND_MINER: 
				{
					switch(random(2)) 
					{
						case 0: 
						{
							SetPlayerAttachedObject(playerid, 6, 906, 6,
								-0.158999, 0.158999, -0.167999, 
								-87.400009, 0.000000, 0.000000, 
								0.079000,0.140999, 0.113000);
						}
						case 1: 
						{
							SetPlayerAttachedObject(playerid, 6, 905, 6,
								-0.050000, 0.061000, -0.155000, 
								0.000000, -109.100036, 0.000000, 
								1.158001, 0.462999, 0.644000);
						}						
					}
				}
			}
		}
		case STONE_GOLD: 
		{
			switch(type_stone_bone) 
			{
				case ATTACH_HAND_MINER: 
				{
					switch(random(2)) 
					{
						case 0: 
						{
							SetPlayerAttachedObject(playerid, 6, 906, 6,
								-0.158999, 0.158999, -0.167999, 
								-87.400009, 0.000000, 0.000000, 
								0.079000,0.140999, 0.113000);
						}
						case 1: 
						{
							SetPlayerAttachedObject(playerid, 6, 905, 6,
								-0.050000, 0.061000, -0.155000, 
								0.000000, -109.100036, 0.000000, 
								1.158001, 0.462999, 0.644000);
						}						
					}
				}
			}
		}		
	}

	return true;

}


#include <..\..\gamemodes\API\systems\miner_systems\miner_systems_sort.inc>
#include <..\..\gamemodes\API\systems\miner_systems\miner_systems_konveer.inc>
#include <..\..\gamemodes\API\systems\miner_systems\miner_systems_mining.inc>
#include <..\..\gamemodes\API\systems\miner_systems\miner_systems_sklad.inc>