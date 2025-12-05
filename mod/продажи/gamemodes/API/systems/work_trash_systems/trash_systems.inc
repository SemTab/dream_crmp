stock load_trash_work_systems()
{
	CreateActor(72, -2227.8123, 251.7092, 24.5337, 30.4119);

	CreateDynamic3DTextLabel(""cBLUE""TRASH_WORK_ACTOR"\n\
	"cWH"Устройство на работу", -1, -2227.8123,251.7092,24.5337+1.0,5.0);

	trash_work_area = create_circle_pickup(-2228.3188,252.3984,24.5337, TRIGGER_LBLUE);

	trash_unload_area = CreateDynamicSphere(1868.9348, -2018.6947, 31.7861, 4.0, 0, 0);

	for(new i; i < TRASH_CAN_COUNT; i++)
	{
		CreateDynamic3DTextLabel(""cBLUE"Мусор\n\
			"cWH"Нажмите ALT", -1, gTrashCanPos[i][0], gTrashCanPos[i][1], gTrashCanPos[i][2], 3.0);

		trash_can_area[i] = create_circle_pickup(gTrashCanPos[i][0], gTrashCanPos[i][1], gTrashCanPos[i][2], TRIGGER_LBLUE);
	}
	return true;
}

stock area_trash_work(playerid, areaid)
{	
	if(areaid == trash_work_area)
	{
		if(pData[playerid][pLevel] < 3)
			return SendErr(playerid, "Работа мусоровозчика доступна с 3 уровня");

		if(!pData[playerid][pLicenses][LIC_DRIVING])
			return SendErr(playerid, "Для работы необходима лицензия на вождение");

		panel_trash_work(playerid, TEXTDRAW_SHOW);


		return true;
	}
	if(areaid == trash_unload_area)
	{
		if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER && GetPVarIntNew(playerid, "trash_work"))
		{
			DisablePlayerCheckpoint(playerid);

			new 	
				vehid = GetPlayerVehicleID(playerid);
			
			if(trash_vehicle[playerid] != vehid)
				return true;

			if(trash_count[vehid] < 100)
				return true;

			SendInf(playerid, "Нажмите "cBLUE"гудок "cWH", чтобы разгрузить машину");
			return true;
		}
		return true;
	}
	return true;
}

stock trash_work_start(playerid)
{
	panel_trash_work(playerid, TEXTDRAW_HIDE);

	SetPVarIntNew(playerid, "trash_work", 1);
	SetPVarIntNew(playerid, "trash_salary", 0);
	SendSucc(playerid, "Вы начали рабочий день мусоровозчика");

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_work_6", 5000);

	if(get_job_level(playerid, SKILL_PICKER) < 5)
	{
		SFCM(playerid, COLOR_ORANGE, "[Навык] "cWH"Ваш навык водителя мусоровоза: "cGR"%d уровень"cWH"", get_job_level(playerid, SKILL_PICKER));
		SFCM(playerid, COLOR_ORANGE, "[Навык] "cWH"Для повышения навыка необходимо совершить "cGR"%d"cWH" рейсов!", get_job_level_next(playerid, SKILL_PICKER));
	}
	else
	{
		SFCM(playerid, COLOR_ORANGE, "[Навык] "cWH"Ваш навык водителя мусоровоза: "cGR"%d уровень", get_job_level(playerid, SKILL_PICKER));
	}

	if(pData[playerid][pSex] == 1)
	{
		SetPlayerSkin(playerid, TRASH_SKIN_MALE);
	}
	else
	{
		SetPlayerSkin(playerid, TRASH_SKIN_FEMALE);
	}

	new 
		position = random(3);

	trash_vehicle[playerid] = CreateVehicle(TRASH_VEHICLE_ID, gTrashWorkVehPos[position][0], gTrashWorkVehPos[position][1], gTrashWorkVehPos[position][2], gTrashWorkVehPos[position][3], -1, -1, -1);
	

	vehicle[trash_vehicle[playerid]][cFuel] = 50.0;
	vehicle[trash_vehicle[playerid]][cHealth] = 1000.0;
	vehicle[trash_vehicle[playerid]][cIsCreated] = true;
	vehicle[trash_vehicle[playerid]][cOwnTo] = VEHICLE_TRASH_WORK;
	vehicle[trash_vehicle[playerid]][cLock] = 1;
	vehicle[trash_vehicle[playerid]][consumables_oil] = 1000.0;

	vehicle_lock_status(trash_vehicle[playerid], false);

	vehicle[trash_vehicle[playerid]][cFuel] = 80;

	new
		v = GetPlayerVehicleID(playerid);	

	pTemp[playerid][rent_car] = trash_vehicle[playerid];


	PutPlayerInVehicle(playerid, trash_vehicle[playerid], 0);

	trash_work_give_next_cp(playerid);

	if(trash_text[trash_vehicle[playerid]] != Text3D:INVALID_3DTEXT_ID) 
	{
		DestroyDynamic3DTextLabelEx(trash_text[trash_vehicle[playerid]]);
	}

	trash_text[trash_vehicle[playerid]] = CreateDynamic3DTextLabel("_", -1, 0.0,0.0,0.0,10.0,INVALID_PLAYER_ID, trash_vehicle[playerid]);

	trash_count[trash_vehicle[playerid]] = 0;

	update_trash_text(trash_vehicle[playerid]);

	return true;
}

stock update_trash_text(carid)
{
	format(String64, sizeof(String64), "Загруженность мусоровоза\n\
		"cBLUE"[%i/100]", trash_count[carid]);

	UpdateDynamic3DTextLabelText(trash_text[carid], -1, String64);
	return true;
}

stock end_trash_work(playerid)
{

	panel_trash_work(playerid, TEXTDRAW_HIDE);

	if(trash_vehicle[playerid] != INVALID_VEHICLE_ID)
	{

		new 
			v = pTemp[playerid][rent_car];

		if(v == INVALID_VEHICLE_ID) 
			return true;

		DestroyVehicle(v);

		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:info_gui_vehicle_unrent", 3500);
		
		pTemp[playerid][rent_car] = INVALID_VEHICLE_ID;
		pTemp[playerid][rent_car_spawn_timer] = INVALID_TIMER_ID;
						

		trash_count[trash_vehicle[playerid]] = 0;
 
		if(trash_text[trash_vehicle[playerid]] != Text3D:INVALID_3DTEXT_ID) 
		{
			DestroyDynamic3DTextLabelEx(trash_text[trash_vehicle[playerid]]);
		}

		trash_text[trash_vehicle[playerid]] = Text3D:INVALID_3DTEXT_ID;
		trash_vehicle[playerid] = INVALID_VEHICLE_ID;
	}
	
	DeletePVarNew(playerid, "trash_can");
	DeletePVarNew(playerid, "take_trash");

	if(GetPVarIntNew(playerid, "trash_work"))
	{	
	    DeletePVarNew(playerid, "trash_work");
	
		DisablePlayerCheckpoint(playerid);

		format(String144, sizeof(String144), "Вы закончили работу мусоровозчика. Зарплата: "cGR"%i рублей", GetPVarIntNew(playerid, "trash_salary"));
		SendSucc(playerid, String144);

		DeletePVarNew(playerid, "trash_salary");

		RemovePlayerAttachedObject(playerid, 0);

		SetPlayerSkin(playerid,pData[playerid][pSkin]);

	}
	return true;
}

stock trash_work_give_next_cp(playerid)
{	
	new 
		pos = random(TRASH_CAN_COUNT);
		
	SetPlayerCheckpoint(playerid, gTrashCanPos[pos][0], gTrashCanPos[pos][1], gTrashCanPos[pos][2], 8.0);

	new 
		Float:x, 
		Float:y,
		Float:z;

	GetPlayerPos(playerid, x, y, z);

	new 
		price_bank_work = floatround(GetDistanceBetweenPoints(x, y, z, gTrashCanPos[pos][0], gTrashCanPos[pos][1], gTrashCanPos[pos][2]));

	SetPVarIntNew(playerid, "price_trash_work_dist", price_bank_work);

	SetPVarIntNew(playerid, "trash_can", pos + 1);
	SendInf(playerid, "Отправляйтесь на метку для того, чтобы забрать мусор");
	return true;
}

stock trash_work_enter_cp(playerid)
{
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		if(GetPVarIntNew(playerid, "trash_work") && GetPVarIntNew(playerid, "trash_can"))
		{
			new 	
				vehid = GetPlayerVehicleID(playerid);
		
			if(trash_vehicle[playerid] != vehid)
				return true;

			if(trash_count[vehid] >= 100)
				return true;

			DisablePlayerCheckpoint(playerid);

			SendInf(playerid, "Возьмите мусор");
			return true;
		}
	}
	return true;
}

stock key_trash_can(playerid, newkeys)
{
	if (newkeys & KEY_WALK)
	{
		for(new i; i < TRASH_CAN_COUNT; i++)
		{
			if(IsPlayerInDynamicArea(playerid, trash_can_area[i]))
			{
				if(GetPVarIntNew(playerid, "trash_work") && GetPVarIntNew(playerid, "trash_can")-1 == i && !GetPVarIntNew(playerid, "take_trash"))
				{
					SetPVarIntNew(playerid, "take_trash", 1);

					SetPlayerAttachedObject(playerid, 0, 1265, 6, 0.219999, -0.019999, 0.061999, 0.000000, -117.899917, 13.300000, 0.374000, 0.44, 0.684999);

					ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 2, 0, 0, 0, 0, 0);

					format(String64, sizeof(String64), "%s мусор", pData[playerid][pSex] == 1 ? ("взял") : ("взяла"));
					MeAction(playerid, String64);

					GameTextForPlayer(playerid, \
					"~y~‹Ё ўџ¬ћњ\
					~n~~w~Їycop",1000, 1);

					SendInf(playerid, "Выгрузите мусор в машину, для этого необходимо подойти к баку машины и нажать "cGR"ALT");
					return true;
				}
			}
		}
		for(new i; i < MAX_VEHICLES; i++)
		{
			if(GetVehicleModel(i) != TRASH_VEHICLE_ID)
				continue;

			new Float:x, Float:y, Float:z, Float:a;
			GetVehiclePos(i, x, y, z);
			GetVehicleZAngle(i, a);

			x = x - (-5.0*floatsin(a, degrees));
			y = y -5.0*floatcos(a, degrees);

			if(IsPlayerInRangeOfPoint(playerid,1,x,y,z))
			{
			        if(GetPVarIntNew(playerid, "take_trash") && trash_vehicle[playerid] == i)
			        {
			        	ApplyAnimation(playerid, "INT_HOUSE", "wash_up", 4.1, 0, 0, 0, 0, 0);

			        	RemovePlayerAttachedObject(playerid, 0);
			        	DeletePVarNew(playerid, "take_trash");
			        	DeletePVarNew(playerid, "trash_can");

			        	trash_count[i] += 5;

						update_trash_text(i);

			        	format(String64, sizeof(String64), "%s мусор", pData[playerid][pSex] == 1 ? ("загрузил") : ("загрузила"));
			        	MeAction(playerid, String64);

			        	add_player_job_skill(playerid, SKILL_PICKER, RandomEx(1, 2));

			        	final_gruz_trash_people(playerid);

			        	GameTextForPlayer(playerid, \
						"~y~‹Ё џa™pyџњћњ\
						~n~~w~Їycop",1000, 1);

						if(trash_count[i] >= 100)
						{
							give_cp_unload_trash(playerid);
						}
						else
						{
							trash_work_give_next_cp(playerid);
						}
			        }
			        break;
			}
		}
	}
	if(newkeys & KEY_CROUCH)
	{
		if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
		{
			if(IsPlayerInDynamicArea(playerid, trash_unload_area))
			{
				new 	
					vehid = GetPlayerVehicleID(playerid);
			
				if(trash_vehicle[playerid] != vehid)
					return true;

				if(trash_count[vehid] < 100)
					return true;

				trash_count[vehid] = 0;

				update_trash_text(vehid);

				final_gruz_trash_people(playerid);

				SendSucc(playerid, "Вы успешно разгрузили мусор!");

				trash_work_give_next_cp(playerid);
				return true;
			}
		}
	}
	return true;
}

stock give_cp_unload_trash(playerid)
{
	SetPlayerCheckpoint(playerid, 1868.9348, -2018.6947, 31.7861, 4.0);

	SendInf(playerid, "Машина полностью загружена, отправляйтесь на метку для разгрузки");
	return true;
}

stock disconnect_trash_work(playerid)
{
	end_trash_work(playerid);
	return true;
}

stock delete_pvar_trash_work(playerid)
{
	DeletePVarNew(playerid, "trash_work");
	DeletePVarNew(playerid, "trash_can");
	DeletePVarNew(playerid, "take_trash");
	DeletePVarNew(playerid, "trash_salary");
	return true;
}

callback:: spawn_rent_car_trash_work(i, v, time)
{

	if(IsPlayerConnected(i))
	{	
		time--;

		if(!time)
		{
			end_trash_work(i);
			return true;
		}
		pTemp[i][rent_car_spawn_timer] = SetTimerEx("spawn_rent_car_trash_work", 1000, false, "iii", i, v, time);
	}
	return true; 
}

stock panel_trash_work(playerid, status)
{
	switch(status)
	{
		case TEXTDRAW_SHOW:
		{	

			create_work_panel_trash(playerid);

			PlayerTextDrawShow(playerid, work_trash_panel_p[0][playerid]);

			if(!GetPVarIntNew(playerid, "trash_work"))
			{
				PlayerTextDrawSetString(playerid, work_trash_panel_p[1][playerid], "brilliantother:work_bank_button_1");
				PlayerTextDrawShow(playerid, work_trash_panel_p[1][playerid]);
			}
			else
			{
				PlayerTextDrawSetString(playerid, work_trash_panel_p[1][playerid], "brilliantother:work_bank_button_2");
				PlayerTextDrawShow(playerid, work_trash_panel_p[1][playerid]);
			}
			PlayerTextDrawShow(playerid, work_trash_panel_p[2][playerid]);
			SelectTextDraw(playerid, COLOR_BLUE);

		}
		case TEXTDRAW_HIDE:
		{
			PlayerTextDrawHideEx(playerid, work_trash_panel_p[0][playerid]);
			PlayerTextDrawHideEx(playerid, work_trash_panel_p[1][playerid]);
			PlayerTextDrawHideEx(playerid, work_trash_panel_p[2][playerid]);

			CancelSelectTextDraw(playerid);
		}
	}


	return true;
}

stock click_button_trash_panel(playerid)
{
	if(!GetPVarIntNew(playerid, "trash_work"))
	{
		trash_work_start(playerid);
	}
	else
	{
		end_trash_work(playerid);
	}
	return true;
}


stock final_gruz_trash_people(playerid)
{
	new 
		money_final = floatround(GetPVarIntNew(playerid, "price_trash_work_dist")/0.5),
		price;

	if(get_job_level(playerid, SKILL_PICKER) == 1)
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
	else if(get_job_level(playerid, SKILL_PICKER) == 2)
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
	else if(get_job_level(playerid, SKILL_PICKER) == 3)
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
	else if(get_job_level(playerid, SKILL_PICKER) == 4)
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
	else if(get_job_level(playerid, SKILL_PICKER) == 5)
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

	new 
		salary = GetPVarIntNew(playerid, "trash_salary") + price;

	SetPVarIntNew(playerid, "trash_salary", salary);

    give_money(playerid, price, "Зарплата за работу водителем мусоровоза");

	format(String144, sizeof(String144), "Вы проехали %d метров и получили за это %d рублей! Благодарим за работу!", GetPVarIntNew(playerid, "price_trash_work_dist"), price);
	SendSucc(playerid, String144);
	return true;
}