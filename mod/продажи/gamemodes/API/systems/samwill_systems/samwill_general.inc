
#define POSITION_TARGET_UNLOADING_WOOD	-1067.2480,-2482.0305,28.5368

#define WOOD_PRICE_PRODUCTION			5 //Долларов
#define WOOD_PRICE_FUELLING				1 //Доллар

#define WOOD_MAX_RANDOM_LOOKS			6
#define WOOD_CHECKPOINT_SIZE 			1.0  
#define WOOD_POINT_MAX_RANDOM			10

static const Float: cam_woods [][WOOD_MAX_RANDOM_LOOKS][] = 
{ 

	{
		{-1053.511352, -2503.314697, 29.255283,  -1049.255126, -2505.601806, 30.253700},
		{-1053.541137, -2508.667480, 30.258346,  -1050.510620, -2504.691162, 30.324527},
		{-1050.062377, -2509.020751, 30.279607,  -1052.651123, -2504.743164, 30.280818},
		{-1052.163208, -2503.474121, 31.339157,  -1051.336059, -2508.360595, 32.001102},
		{-1053.539062, -2505.984863, 32.485248,  -1048.568115, -2506.506591, 32.352207},
		{-1050.681396, -2507.340820, 34.456806,  -1053.834350, -2503.462158, 34.576618}	
	},

	{
		{-1020.815979, -2509.284912, 28.845268,  -1018.140808, -2512.507812, 31.496297},
		{-1021.357910, -2513.838623, 30.013046,  -1035.718383, 1515.425903, 38.895862},
		{-1018.547180, -2512.845703, 30.839212,  -1022.940307, -2510.458740, 30.888074},
		{-1019.048583, -2510.732910, 31.895471,  -1022.953125, -2513.848144, 32.117511},
		{-1022.111511, -2510.637207, 32.502300,  -1018.195495, -2513.481933, 33.756366},
		{-1022.111511, -2510.637207, 32.502300,  -1018.195495, -2513.481933, 33.756366}

	},

	{
		{-1058.371826, -2520.048828, 28.324422,  -1056.353393, -2519.193603, 28.388317},
		{-1055.791381, -2523.781738, 29.884611,  -1058.510986, -2519.587890, 30.011415},
		{-1055.060791, -2521.515625, 31.508073,  -1059.889404, -2522.785156, 31.777690},
		{-1056.553833, -2519.679931, 30.363059,  -1056.620971, -2524.679443, 30.381595},
		{-1055.791381, -2523.781738, 29.884611,  -1058.510986, -2519.587890, 30.011415},
		{-1055.060791, -2521.515625, 31.508073,  -1059.889404, -2522.785156, 31.777690}


	},

	{
		{-1079.569458, -2520.965576, 29.200340,  -1076.866821, -2525.211669, 31.650777},
		{-1077.360961, -2525.196044, 30.299779,  -1081.948486, -2523.277832, 29.775209},
		{-1077.891967, -2523.785888, 31.122537,  -1082.147094, -2526.394287, 30.822406},
		{-1077.662109, -2524.127197, 29.870676,  -1082.468505, -2525.297851, 29.144151},
		{-1077.360961, -2525.196044, 30.299779,  -1081.948486, -2523.277832, 29.775209},
		{-1077.891967, -2523.785888, 31.122537,  -1082.147094, -2526.394287, 30.822406}

	},

	{

		{-1039.485107, -2524.410644, 28.695678, -1035.747192, -2526.214843, 31.867109},
		{-1039.152954, -2528.331298, 31.471149, -1039.149291, -2523.333496, 31.320791},
		{-1038.384155, -2528.000000, 30.406509, -1041.792358, -2524.381591, 29.867366},
		{-1037.812011, -2526.664550, 30.206348, -1042.434082, -2528.074707, 28.922721},
		{-1038.886962, -2526.032714, 31.983781, -1039.856323, -2530.931396, 32.233436},
		{-1040.071777, -2526.387451, 31.983781, -1036.177124, -2529.480712, 32.496841}		
	},


	{

		{-1016.980468, -2527.025390, 28.688774, -1014.204467, -2530.056152, 31.259878},
		{-1018.314208, -2531.043945, 31.664951, -1014.695556, -2527.657226, 32.324253},
		{-1016.391906, -2531.320800, 33.109180, -1019.124206, -2527.147216, 33.449634},
		{-1015.892333, -2529.957763, 35.553340, -1020.850280, -2530.604736, 35.564880},
		{-1017.013488, -2528.870361, 36.625873, -1017.353210, -2533.857666, 36.737022},
		{-1017.299804, -2529.235595, 39.185298, -1016.363830, -2534.144775, 39.339744}	
	}

};

static const Float: wood_position_coord[][] = 
{
	{-1051.8711,-2504.4229,28.4950},
	{-1037.1250,-2505.8872,28.5907},
	{-1020.4387,-2510.4568,28.7774},
	{-1057.0896,-2520.7009,28.2165},
	{-1079.3314,-2523.0469,28.9570},
	{-1039.5156,-2525.6926,28.4710}
};

stock create_lesopilka_pickup()
{
	CreateDynamicPickup(19197, 23, -1067.2480,-2482.0305,28.5368, -1, -1, -1, 45.0);
	CreateDynamic3DTextLabel("«Склад бревен»", COLOR_BLUE, -1067.2480,-2482.0305,28.5368, 17.0);
	wood_unloading_job_area = CreateDynamicSphere(-1067.2480,-2482.0305,28.5368, 2.0);

	CreateDynamicPickup(1275, 23, -1025.8005,-2479.2400,28.5279, -1, -1, -1, 45.0);
	CreateDynamic3DTextLabel("Устройство лесорубом\n"cBLUE"Работа", -1, -1025.8005,-2479.2400,28.5279, 17.0);
	wood_job_invite_are = CreateDynamicSphere(-1025.8005,-2479.2400,28.5279, 2.0);

	wood_postion_area[0] = create_circle_pickup(wood_position_coord[0][0], wood_position_coord[0][1], wood_position_coord[0][2]+0.25, TRIGGER_LBLUE);		
	wood_postion_area[1] = create_circle_pickup(wood_position_coord[1][0], wood_position_coord[1][1], wood_position_coord[1][2]+0.25, TRIGGER_LBLUE);	
	wood_postion_area[2] = create_circle_pickup(wood_position_coord[2][0], wood_position_coord[2][1], wood_position_coord[2][2]+0.25, TRIGGER_LBLUE);	
	wood_postion_area[3] = create_circle_pickup(wood_position_coord[3][0], wood_position_coord[3][1], wood_position_coord[3][2]+0.25, TRIGGER_LBLUE);	
	wood_postion_area[4] = create_circle_pickup(wood_position_coord[4][0], wood_position_coord[4][1], wood_position_coord[4][2]+0.25, TRIGGER_LBLUE);	
	wood_postion_area[5] = create_circle_pickup(wood_position_coord[5][0], wood_position_coord[5][1], wood_position_coord[5][2]+0.25, TRIGGER_LBLUE);		



	return true;
}


stock dialog_wood_job(playerid)
{
	if(!GetPVarIntNew(playerid, "wood_job"))
	{
		return SPD(playerid, DIALOG_WOOD_JOB, DIALOG_STYLE_MSGBOX, !""cBLUE"Лесопилка", !"\
			"cWH"Вы хотите начать работать лесорубом?\n\n\
			"cBLUE"-"cWH" Вам нужно спиливать деревья\n\
			"cBLUE"-"cWH" Относить их на склад для дальнейшей переработки\n\n\
			Готовы приступить?", !"Да", !"Нет");
	}
	else
	{
		return SPD(playerid, DIALOG_WOOD_JOB, DIALOG_STYLE_MSGBOX, !""cBLUE"Лесопилка", !"\
			"cWH"Вы хотите закончить работу лесорубом?", !"Да", !"Нет");
	}
}

stock start_wood_job(playerid)
{
	if(!IsPlayerConnected(playerid)) 
		return true;


	SetPVarIntNew(playerid, "wood_job", playerid+1);
	SetPVarIntNew(playerid, "wood_chainsaw_count", 0);
	SetPVarIntNew(playerid, "wood_count_job", 0);
	SetPVarIntNew(playerid, "wood_select_oil", 0);
	SetPVarIntNew(playerid, "wood_select_fuel", 0);

	SetPVarIntNew(playerid, "wood_progress_job", 0);

	set_player_wood_skin(playerid);

	SetPlayerAttachedObject(playerid, 7, 341, 1,
		-0.400999, -0.196999, -0.055000,
		-10.299998, -0.400028, 1.300005,
		1.000000, 1.000000, 1.000000);

	SCM(playerid, -1, "");
	SendSucc(playerid, "Вы начали работу лесорубом");
	SendInf(playerid, "Спиливайте деревья и относите их на склад");

	if(get_job_level(playerid, SKILL_WOODCUTTER) < 5)
	{
		SFCM(playerid, COLOR_ORANGE, "[Навык] "cWH"Ваш навык лесоруба: "cGR"%d уровень"cWH"", get_job_level(playerid, SKILL_WOODCUTTER));
		SFCM(playerid, COLOR_ORANGE, "[Навык] "cWH"Для повышения навыка необходимо перенести "cGR"%d"cWH" дерева!", get_job_level_next(playerid, SKILL_WOODCUTTER));
	}
	else
	{
		SFCM(playerid, COLOR_ORANGE, "[Навык] "cWH"Ваш навык лесоруба: "cGR"%d уровень", get_job_level(playerid, SKILL_WOODCUTTER));
	}

	return true;
}


stock end_wood_job(playerid)
{
	if(!GetPVarIntNew(playerid, "wood_job")) 
		return true;

	new
		price;
	price = (get_job_level(playerid, SKILL_WOODCUTTER) * 100) * (GetPVarIntNew(playerid,"wood_count_job")*1000);


	DeletePVarNew(playerid, "wood_job");
	DeletePVarNew(playerid, "wood_chainsaw_count");
	DeletePVarNew(playerid, "wood_select_fuel");		
	DeletePVarNew(playerid, "wood_chainsaw_count");
	DeletePVarNew(playerid, "count_point_progress_wood");
	DeletePVarNew(playerid, "wood_active_work");
	DeletePVarNew(playerid, "wood_fuelling_zone");
	DeletePVarNew(playerid, "wood_select_fuel");		
	DeletePVarNew(playerid, "wood_select_oil");
	DeletePVarNew(playerid, "wood_fuelling_active");
	DeletePVarNew(playerid, "wood_hands_player");



    RemovePlayerAttachedObject(playerid, 7);

	SetPlayerSkin(playerid, pData[playerid][pSkin]);

	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);

	ResetPlayerWeapons(playerid);
	return true;
}

stock set_player_wood_skin(playerid)
{
	if(pData[playerid][pSex] == 1)
	{
		SetPlayerSkin(playerid, 34);
	}
	else
	{
		SetPlayerSkin(playerid, 63);	
	}

	return true;
}

stock samwill_unloadloadig_wood(playerid)
{
	if(!GetPVarIntNew(playerid, "wood_job")) 
		return true;
	if(!GetPVarIntNew(playerid, "wood_hands_player"))
		return true;

	DeletePVarNew(playerid, "wood_hands_player");
	PlayerPlaySound(playerid, 1083, 0.0, 0.0, 0.0);	
	RemovePlayerAttachedObject(playerid, 7);

	SetPVarIntNew(playerid,"wood_count_job",GetPVarIntNew(playerid,"wood_count_job")+1);

	add_player_job_skill(playerid, SKILL_WOODCUTTER);

	SetPlayerAttachedObject(playerid, 7, 341, 1,
		-0.400999, -0.196999, -0.055000,
		-10.299998, -0.400028, 1.300005,
		1.000000, 1.000000, 1.000000);

	SendSucc(playerid, "Вы успешно принесли дерево на склад! Продолжайте в том же духе!");

	DisablePlayerCheckpoint(playerid);

	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
	return true;
}


stock generate_player_points_wood(playerid){


	static const Float: point_wood_pos[][] =
	{
	    {266.6665, 197.3111},
	    {267.3332, 156.2444},
	    {224.6666, 153.3407},
	    {301.6665, 180.7185},
	    {266.6666, 117.2518},
	    {251.6666, 106.8814},
	    {288.9999, 130.5259},
	    {239.9999, 218.0518},
	    {262.6666, 254.1407}
	};

	new rand = random(sizeof point_wood_pos);

	if(wood_point_p[playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		wood_point_p[playerid] = CreatePlayerTextDraw(playerid, point_wood_pos[rand][0], point_wood_pos[rand][1], "brilliantother:wood_job_click"); // Texture element
		PlayerTextDrawLetterSize(playerid, wood_point_p[playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, wood_point_p[playerid], 18.000001, 21.570348);
		PlayerTextDrawAlignment(playerid, wood_point_p[playerid], 2);
		PlayerTextDrawColor(playerid, wood_point_p[playerid], -1);
		PlayerTextDrawSetShadow(playerid, wood_point_p[playerid], 0);
		PlayerTextDrawSetOutline(playerid, wood_point_p[playerid], 0);
		PlayerTextDrawFont(playerid, wood_point_p[playerid], 4);
		PlayerTextDrawSetSelectable(playerid, wood_point_p[playerid], true);

	}
	PlayerTextDrawShow(playerid, wood_point_p[playerid]);



	SetPlayerArmedWeapon(playerid, 9);

	return true;
}

stock click_random_point_wood(playerid)
{
	if(GetPVarIntNew(playerid, "wood_progress_job") < GetPVarIntNew(playerid, "count_point_progress_wood")) 
	{

		SetPVarIntNew(playerid,"wood_progress_job",GetPVarIntNew(playerid,"wood_progress_job")+1);

		ApplyAnimation(playerid, "CHAINSAW","WEAPON_csaw", 4.1,1,1,1,1,0,0);
		wood_point_textdraw(playerid, TEXTDRAW_HIDE);
		wood_point_textdraw(playerid, TEXTDRAW_SHOW);

		new 
			camera_wood = -1,
			rand = random(WOOD_MAX_RANDOM_LOOKS);

		for (new i; i < sizeof wood_position_coord; i++) 
		{

			if (IsPlayerInRangeOfPoint(playerid, 5.0, wood_position_coord[i][0], wood_position_coord[i][1], wood_position_coord[i][2])) 
			{

				camera_wood = i;
				break;

			}

		}

		SetPlayerCameraPos(playerid, cam_woods[camera_wood][rand][0], cam_woods[camera_wood][rand][1], cam_woods[camera_wood][rand][2]);
		SetPlayerCameraLookAt(playerid, cam_woods[camera_wood][rand][3], cam_woods[camera_wood][rand][4], cam_woods[camera_wood][rand][5]);


	}
	else 
	{

    	SetPVarIntNew(playerid, "wood_active_work", 0);

		if(!GetPVarIntNew(playerid, "wood_hands_player"))
		{
			SetPlayerSpecialAction(playerid, SPECIAL_ACTION_CARRY);

			SetPlayerAttachedObject(playerid, 7, 13746, 5,
				0.034000, 0.437000, -0.507000,
				98.400062, 165.000000, 19.499994,
				0.237999, 0.197000, 0.331000);
			SetPVarIntNew(playerid, "wood_hands_player", 1);
		}

		wood_point_textdraw(playerid, TEXTDRAW_HIDE);

		SendInf(playerid, "Отнесите дерево на склад и продолжайте работу!");

		SetPlayerCheckpoint(playerid, POSITION_TARGET_UNLOADING_WOOD, WOOD_CHECKPOINT_SIZE);

		PlayerPlaySound(playerid, 1083, 0.0, 0.0, 0.0);
		CancelSelectTextDraw(playerid);
		SetCameraBehindPlayer(playerid);
		TogglePlayerControllable(playerid, true);		

		DeletePVarNew(playerid, "wood_active_work");
		DeletePVarNew(playerid, "count_point_progress_wood");
	}

    return true;
}


stock wood_select_player(playerid)
{

	if(!GetPVarIntNew(playerid, "wood_job"))
		return true;


	if(GetPVarIntNew(playerid, "wood_hands_player"))
		return SendInf(playerid, "Отнесите дерево на склад!");

	new 
		camera_wood = -1,
		rand = random(WOOD_MAX_RANDOM_LOOKS);

	for (new i; i < sizeof wood_position_coord; i++) 
	{

		if (IsPlayerInRangeOfPoint(playerid, 5.0, wood_position_coord[i][0], wood_position_coord[i][1], wood_position_coord[i][2])) 
		{

			camera_wood = i;
			break;

		}

	}

	SetPlayerCameraPos(playerid, cam_woods[camera_wood][rand][0], cam_woods[camera_wood][rand][1], cam_woods[camera_wood][rand][2]);
	SetPlayerCameraLookAt(playerid, cam_woods[camera_wood][rand][3], cam_woods[camera_wood][rand][4], cam_woods[camera_wood][rand][5]);

	wood_point_textdraw(playerid, TEXTDRAW_SHOW);

	new 
		count_point;


	count_point = 5+random(15)-1;

	FormattedMessage(playerid, COLOR_BLUE, "[DEBUG] Выдали игроку %d позиций", count_point);

	SetPVarIntNew(playerid, "count_point_progress_wood", count_point);

	SetPVarIntNew(playerid, "wood_active_work", 1);
	SetPVarIntNew(playerid, "wood_progress_job", 0);

	TogglePlayerControllable(playerid, false);

	return true;
}

stock wood_point_textdraw(playerid, action)
{
	switch(action)
	{
		case TEXTDRAW_SHOW:
		{
			generate_player_points_wood(playerid);
			SelectTextDraw(playerid, COLOR_BLUE);		
		}
		case TEXTDRAW_HIDE:
		{
			if(wood_point_p[playerid] != PlayerText:INVALID_TEXT_DRAW)
				PlayerTextDrawHideEx(playerid, wood_point_p[playerid]);
		}
	}
	return true;
}

