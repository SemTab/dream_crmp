static const Float:position_factory_mith[][] = 
{
	{647.4645,1283.7314,1746.4340},
	{647.4784,1286.1592,1746.4340},
	{647.4973,1289.6500,1746.4340},
	{649.7369,1289.8032,1746.4340},
	{652.5825,1289.7700,1746.4340},
	{655.3286,1289.7388,1746.4340},
	{660.3822,1295.8153,1746.4340},
	{627.7635,1278.7330,1746.4340},
	{627.9053,1273.7544,1746.4340},
	{627.7972,1269.2329,1746.4340},
	{627.7292,1264.5356,1746.4340},
	{627.6339,1259.8167,1746.4340},
	{627.5391,1255.2953,1746.4340}
};


static const Float:position_factory_furniture[][] = 
{
	{653.6960,1297.3921,1746.4340},
	{650.4168,1297.5389,1746.4340},
	{647.8337,1297.5120,1746.4340},
	{644.5560,1302.5040,1746.4340},
	{644.5483,1305.3022,1746.4340},
	{644.5417,1307.7295,1746.4340},
	{644.5339,1310.5239,1746.4340},
	{644.5273,1312.9894,1746.4340},
	{647.5688,1313.0774,1746.4340},
	{647.5564,1310.4215,1746.4340},
	{647.5455,1308.0636,1746.4340},
	{647.5322,1305.2562,1746.4340},
	{647.5127,1301.1428,1746.4340},
	{649.4348,1300.6344,1746.4340},
	{651.8832,1300.6886,1746.4340},
	{654.7452,1300.7526,1746.4340}

};



stock create_factory_other()
{
	actor_factory = CreateActor(60, 695.1965,1280.1252,1746.4183,1.2702);
	ApplyActorAnimation(actor_factory, "COP_AMBIENT", "coplook_loop", 4.1, 1, 1, 1, 0, 0);
	SetActorVirtualWorld(actor_factory, 3);

	CreateDynamicPickup(13724, 23, 699.6809,1266.3995,1746.4071, -1, -1, -1, 45.0);
	area_factory_clothes = CreateDynamicSphere(699.6809,1266.3995,1746.4071, 1.5, -1, -1);


	for(new i; i < sizeof(position_factory_mith); i++)
	{
		CreateDynamic3DTextLabel("Работа слесарем\n"cLRED"[Встаньте на пикап]", -1, position_factory_mith[i][0], position_factory_mith[i][1], position_factory_mith[i][2], 2.0);
		area_factory_mith[i] = create_circle_pickup(position_factory_mith[i][0], position_factory_mith[i][1], position_factory_mith[i][2], TRIGGER_LRED);
	}

	for(new i; i < sizeof(position_factory_furniture); i++)
	{
		CreateDynamic3DTextLabel("Работа мебельщиком\n"cGR"[Встаньте на пикап]", -1, position_factory_furniture[i][0], position_factory_furniture[i][1], position_factory_furniture[i][2], 2.0);
		area_factory_furniture[i] = create_circle_pickup(position_factory_furniture[i][0], position_factory_furniture[i][1], position_factory_furniture[i][2], TRIGGER_GREEN);
	}

	CreateDynamic3DTextLabel("Мебельный склад\n"cLRED"[Встаньте на пикап]", -1, 642.2382,1289.3558,1746.4340, 2.0);
	
	CreateDynamic3DTextLabel("Склад\n"cGR"[Встаньте на пикап]", -1, 653.4014,1276.9858,1746.4340, 2.0);

	area_factory_mith_sklad = create_circle_pickup(653.4014,1276.9858,1746.4340+0.15, TRIGGER_LRED);
	area_factory_mith_sklad2 = create_circle_pickup(633.6762,1249.3519,1746.4340+0.15, TRIGGER_LRED);


	area_factory_furniture_sklad = create_circle_pickup(642.2382,1289.3558,1746.4340+0.15, TRIGGER_GREEN);
	area_factory_furniture_sklad2 = create_circle_pickup(660.4174,1312.7645,1746.4340+0.15, TRIGGER_GREEN);

	return true;
}

stock dialog_factory_job(playerid)
{
	if(!GetPVarIntNew(playerid, "factoryjob"))
	{
		WN_showCaptcha(playerid);
		return SPD(playerid, DIALOG_FACTORY_JOB, DIALOG_STYLE_MSGBOX, !""cBLUE"Мебельный завод", !"\
			"cWH"Вы хотите начать работать на заводе?\n\n\
			Вы можете работать сборщиком мебели или слесарем\n\n\
			Готовы приступить?", !"Да", !"Нет");
	}
	else
	{
		return SPD(playerid, DIALOG_FACTORY_JOB, DIALOG_STYLE_MSGBOX, !""cBLUE"Мебельный завод", !"\
			"cWH"Вы хотите закончить работу рабочим завода?", !"Да", !"Нет");
	}
}


stock start_factoryjob(playerid)
{
	if(!IsPlayerConnected(playerid)) 
		return true;

	end_all_work(playerid);

	SetPVarIntNew(playerid, "factoryjob", 1);

	set_player_factory_skin(playerid);

	SCM(playerid, -1, "");
	SendSucc(playerid, "Вы начали работу на заводе!");
	SendInf(playerid, "Отправляйтесь в один из цехов и приступайте к выполнению работы!");
	SendInf(playerid, "Вы можете работать сборщиком мебели или же слесарем!");

	if(get_job_level(playerid, SKILL_FACTORY) < 5)
	{
		SFCM(playerid, COLOR_ORANGE, "[Навык] "cWH"Ваш навык работника завода: "cGR"%d уровень"cWH"", get_job_level(playerid, SKILL_FACTORY));
		SFCM(playerid, COLOR_ORANGE, "[Навык] "cWH"Для повышения навыка необходимо сделать "cGR"%d"cWH" деталей!", get_job_level_next(playerid, SKILL_FACTORY));
	}
	else
	{
		SFCM(playerid, COLOR_ORANGE, "[Навык] "cWH"Ваш навык работника завода: "cGR"%d уровень", get_job_level(playerid, SKILL_FACTORY));
	}

	SetPVarIntNew(playerid, "miner_job_count", 0);

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:info_gui_zavod_1", 4000);

	return true;
}


stock end_factoryjob(playerid)
{
	if(!GetPVarIntNew(playerid, "factoryjob")) 
		return true;

	DeletePVarNew(playerid, "factoryjob");
	DeletePVarNew(playerid, "active_sklad_factory");
	DeletePVarNew(playerid, "active_sklad_factory");

    RemovePlayerAttachedObject(playerid, 7);
    
	SetPlayerSkin(playerid,pData[playerid][pSkin]);

	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
	ResetPlayerWeapons(playerid);

	new
		price;

	if(get_job_level(playerid, SKILL_FACTORY) == 1)
	{
		if(IsActionTrue4)  
		{
			price = (GetPVarIntNew(playerid,"miner_job_count")*40)*2;
		}
		else if(!IsActionTrue4 && IsPlayerOnlineForBonusSalary(playerid))
		{
			price = (GetPVarIntNew(playerid,"miner_job_count")*40)*2;
		}		
		else
		{
			price = GetPVarIntNew(playerid,"miner_job_count")*40;
		}
	}
	else if(get_job_level(playerid, SKILL_FACTORY) == 2)
	{
		if(IsActionTrue4)  
		{
			price = floatround((GetPVarIntNew(playerid,"miner_job_count")*40)*1.2)*2;
		}
		else if(!IsActionTrue4 && IsPlayerOnlineForBonusSalary(playerid))
		{
			price = floatround((GetPVarIntNew(playerid,"miner_job_count")*40)*1.2)*2;
		}	
		else
		{
			price = floatround((GetPVarIntNew(playerid,"miner_job_count")*40)*1.2);
		}
	}
	else if(get_job_level(playerid, SKILL_FACTORY) == 3)
	{
		if(IsActionTrue4)  
		{
			price = floatround((GetPVarIntNew(playerid,"miner_job_count")*40)*1.4)*2;
		}
		else if(!IsActionTrue4 && IsPlayerOnlineForBonusSalary(playerid))
		{
			price = floatround((GetPVarIntNew(playerid,"miner_job_count")*40)*1.4)*2;
		}	
		else
		{
			price = floatround((GetPVarIntNew(playerid,"miner_job_count")*40)*1.4);
		}
	}
	else if(get_job_level(playerid, SKILL_FACTORY) == 4)
	{
		if(IsActionTrue4)  
		{
			price = floatround((GetPVarIntNew(playerid,"miner_job_count")*40)*1.6)*2;
		}
		else if(!IsActionTrue4 && IsPlayerOnlineForBonusSalary(playerid))
		{
			price = floatround((GetPVarIntNew(playerid,"miner_job_count")*40)*1.6)*2;
		}	
		else
		{
			price = floatround((GetPVarIntNew(playerid,"miner_job_count")*40)*1.6);
		}
	}
	else if(get_job_level(playerid, SKILL_FACTORY) == 5)
	{
		if(IsActionTrue4)  
		{
			price = floatround((GetPVarIntNew(playerid,"miner_job_count")*40)*1.8)*2;
		}
		else if(!IsActionTrue4 && IsPlayerOnlineForBonusSalary(playerid))
		{
			price = floatround((GetPVarIntNew(playerid,"miner_job_count")*40)*1.8)*2;
		}	
		else
		{
			price = floatround((GetPVarIntNew(playerid,"miner_job_count")*40)*1.8);
		}
	}

    format(String144, sizeof(String144), "Вы заработали в сумме "cGR"%d "cWH"рублей!", price);
    SendInf(playerid, String144);

    if(price >= 1000)
    {
    	check_quest_prize_start(playerid, 1);
    }

    give_money(playerid, price, "Работа на заводе");

	DeletePVarNew(playerid, "miner_job_count");

	return true;
}

stock set_player_factory_skin(playerid)
{
	if(pData[playerid][pSex] == 1)
	{
		SetPlayerSkin(playerid, 60);
	}
	else
	{
		SetPlayerSkin(playerid, 54);	
	}

	return true;
}