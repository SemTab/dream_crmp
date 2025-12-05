static const Float:position_frame_konveer[][] =
{
	{100.600006, 154.300079},
	{155.899795, 154.300079},
	{211.200103, 154.300079},
	{266.800292, 154.300079},
	{322.000213, 154.300079},
	{377.200378, 154.300079},
	{432.601348, 154.300079},
	{487.901123, 154.300079}
};




stock panel_miner_konveer(playerid, type)
{
	switch(type)
	{
		case TEXTDRAW_SHOW:
		{
			TextDrawShowForPlayer(playerid, mine_job_2[0]);
			TextDrawShowForPlayer(playerid, mine_job_2[1]);	

			create_miner_job_2(playerid);

			generate_position_all_konveer(playerid);

		}
		case TEXTDRAW_HIDE:
		{
			TextDrawHideForPlayer(playerid, mine_job_2[0]);
			TextDrawHideForPlayer(playerid, mine_job_2[1]);	

			for(new i = 0; i < 15; i++)
			{
				if(miner_job_2_p[playerid][i] != PlayerText:INVALID_TEXT_DRAW)
				{
					PlayerTextDrawHideEx(playerid, miner_job_2_p[playerid][i]);
				}
			}			
		}
	}

	return true;
}

stock generate_position_all_konveer(playerid)
{

	switch(RandomEx(1, 5))
	{
		case 1:
		{
			mine_konveer_massive_object_td[playerid] = 1;

			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][4], "minejob:qcoal"); // 6
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][5], "minejob:qcopper");
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][6], "minejob:qdiamond");
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][7], "minejob:qgold");
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][8], "minejob:qiron");
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][9], "minejob:qmetal"); //1

		}
		case 2:
		{
			mine_konveer_massive_object_td[playerid] = 2;

			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][4], "minejob:qcopper"); // 6
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][5], "minejob:qdiamond");
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][6], "minejob:qiron");
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][7], "minejob:qgold");
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][8], "minejob:qmetal");
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][9], "minejob:qcoal"); //1

		}
		case 3:
		{
			mine_konveer_massive_object_td[playerid] = 3;

			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][4], "minejob:qdiamond"); // 6
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][5], "minejob:qgold");
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][6], "minejob:qiron");
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][7], "minejob:qcoal");
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][8], "minejob:qcopper");
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][9], "minejob:qmetal"); //1

		}
		case 4:
		{
			mine_konveer_massive_object_td[playerid] = 4;

			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][4], "minejob:qgold"); // 6
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][5], "minejob:qmetal");
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][6], "minejob:qdiamond");
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][7], "minejob:qcopper");
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][8], "minejob:qiron");
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][9], "minejob:qcoal"); //1
		}
		case 5:
		{
			mine_konveer_massive_object_td[playerid] = 5;

			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][4], "minejob:qmetal"); // 6
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][5], "minejob:qcopper");
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][6], "minejob:qiron");
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][7], "minejob:qgold");
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][8], "minejob:qdiamond");
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][9], "minejob:qcoal"); //1
		}
	}

	PlayerTextDrawShow(playerid, miner_job_2_p[playerid][4]);	
	PlayerTextDrawShow(playerid, miner_job_2_p[playerid][5]);
	PlayerTextDrawShow(playerid, miner_job_2_p[playerid][6]);
	PlayerTextDrawShow(playerid, miner_job_2_p[playerid][7]);
	PlayerTextDrawShow(playerid, miner_job_2_p[playerid][8]);
	PlayerTextDrawShow(playerid, miner_job_2_p[playerid][9]);

	mine_konveer_all_object[playerid] = 7;
	mine_konveer_select_object[playerid] = 6;
	return true;
}

stock generate_selectable_obj_konveer(playerid)
{
	new 
		selectable_generate = mine_konveer_all_object[playerid]-mine_konveer_select_object[playerid];

	if(selectable_generate >= 7)
		return next_stap_konveer_mine(playerid);

	switch(selectable_generate)
	{
		case 1: 
		{
			miner_select_material_mining[playerid] = MINEJOB_COAL;

			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][12], "minejob:coal");
			PlayerTextDrawShow(playerid, miner_job_2_p[playerid][12]);				
		}
		case 2: 
		{
			miner_select_material_mining[playerid] = MINEJOB_DIAMOND;

			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][12], "minejob:diamond");
			PlayerTextDrawShow(playerid, miner_job_2_p[playerid][12]);				
		}
		case 3: 
		{

			miner_select_material_mining[playerid] = MINEJOB_COPPER;

			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][12], "minejob:copper");
			PlayerTextDrawShow(playerid, miner_job_2_p[playerid][12]);		
		
		}
		case 4: 
		{
			miner_select_material_mining[playerid] = MINEJOB_METAL;

			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][12], "minejob:metal");
			PlayerTextDrawShow(playerid, miner_job_2_p[playerid][12]);	

		}
		case 5: 
		{
			miner_select_material_mining[playerid] = MINEJOB_IRON;

			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][12], "minejob:iron");
			PlayerTextDrawShow(playerid, miner_job_2_p[playerid][12]);				
		}
		case 6: 
		{
			miner_select_material_mining[playerid] = MINEJOB_GOLD;

			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][12], "minejob:gold");
			PlayerTextDrawShow(playerid, miner_job_2_p[playerid][12]);				
		}
		
	}
	PlayerTextDrawShow(playerid, miner_job_2_p[playerid][12]);		



	return true;
}

stock panel_progress_mine_konveer(playerid)
{
	switch(mine_miner_progress_bar[playerid])
	{
		case 0:
		{
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][13], "minejob:p1");
			PlayerTextDrawShow(playerid, miner_job_2_p[playerid][13]);	
		}
		case 1:
		{
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][13], "minejob:p2");
			PlayerTextDrawShow(playerid, miner_job_2_p[playerid][13]);				
		}
		case 2:
		{
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][13], "minejob:p3");
			PlayerTextDrawShow(playerid, miner_job_2_p[playerid][13]);				
		}
		case 3:
		{
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][13], "minejob:p4");
			PlayerTextDrawShow(playerid, miner_job_2_p[playerid][13]);				
		}
		case 4:
		{
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][13], "minejob:p5");
			PlayerTextDrawShow(playerid, miner_job_2_p[playerid][13]);				
		}
		case 5:
		{
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][13], "minejob:p6");
			PlayerTextDrawShow(playerid, miner_job_2_p[playerid][13]);				
		}
		case 6:
		{
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][13], "minejob:p7");
			PlayerTextDrawShow(playerid, miner_job_2_p[playerid][13]);				
		}
		case 7:
		{
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][13], "minejob:p8");
			PlayerTextDrawShow(playerid, miner_job_2_p[playerid][13]);			
		}
		case 8:
		{
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][13], "minejob:p9");
			PlayerTextDrawShow(playerid, miner_job_2_p[playerid][13]);			
		}
		case 9:
		{
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][13], "minejob:p9");
			PlayerTextDrawShow(playerid, miner_job_2_p[playerid][13]);
		}
		case 10..11:
		{
			PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][13], "minejob:p10");
			PlayerTextDrawShow(playerid, miner_job_2_p[playerid][13]);			
		}
	}
	PlayerTextDrawShow(playerid, miner_job_2_p[playerid][13]);	
	return true;
}

cmd:generate_panel(playerid)
{
	return start_player_miner_konveer(playerid);
}

stock next_position_konveer_mine(playerid)
{

	if(mine_position_td[playerid] == 0)
	{
		mine_position_td[playerid] = 7;
	}
	else
	{
		mine_position_td[playerid]--;
	}

	check_pos_td_konveer(playerid);

	new 
		next_position = 7-mine_position_td[playerid];

	PlayerTextDrawHideEx(playerid, miner_job_2_p[playerid][11]);

	if(miner_job_2_p[playerid][11] == PlayerText:INVALID_TEXT_DRAW)
	{	
		miner_job_2_p[playerid][11] = CreatePlayerTextDraw(playerid, position_frame_konveer[next_position][0], position_frame_konveer[next_position][1], "minejob:frame");
		PlayerTextDrawTextSize(playerid, miner_job_2_p[playerid][11], 52.609996, 89.070007);
		PlayerTextDrawAlignment(playerid, miner_job_2_p[playerid][11], 1);
		PlayerTextDrawColor(playerid, miner_job_2_p[playerid][11], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_2_p[playerid][11], 255);
		PlayerTextDrawFont(playerid, miner_job_2_p[playerid][11], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_2_p[playerid][11], 0);
	}

	PlayerTextDrawShow(playerid, miner_job_2_p[playerid][11]);

	return true;
}

stock start_player_miner_konveer(playerid)
{
	if(!GetPVarIntNew(playerid, "miner_type_work"))
	{
		return SendInf(playerid, "¬ам недоступен данный этап работы!");
	}
	if(GetPVarIntNew(playerid, "miner_type_work") != STAP_JOB_MINER_KONVEER)
	{
		return SendInf(playerid, "¬ам недоступен данный этап работы!");
	}
	if(GetPVarIntNew(playerid, "miner_type_work") == STAP_JOB_MINER_MINING)
	{
		SendInf(playerid, "¬ам недоступен данный этап работы!");
		return SendInf(playerid, "¬аша задача: добыча руды в жилах шахты!");
	}
	if(GetPVarIntNew(playerid, "miner_type_work") == STAP_JOB_MINER_LIFT)
	{
		SendInf(playerid, "¬ам недоступен данный этап работы!");
		return SendInf(playerid, "¬аша задача: отнести руду в грузовой лифт!");
	}
	if(GetPVarIntNew(playerid, "miner_type_work") == STAP_JOB_MINER_SKLAD)
	{
		SendInf(playerid, "¬ам недоступен данный этап работы!");
		return SendInf(playerid, "¬аша задача: отнести €щики с рудой на склад!");
	}

 	miner_select_material_mining[playerid] = MINEJOB_NONE;
 	mine_random_material_active[playerid] = -1;
 	mine_miner_progress_bar[playerid] = 0;

	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);

	panel_miner_konveer(playerid, TEXTDRAW_SHOW);

	generate_position_all_konveer(playerid);
	generate_selectable_obj_konveer(playerid);

	PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][2], "000000");
	PlayerTextDrawShow(playerid, miner_job_2_p[playerid][2]);		

	format(String64, 32, "X1");
	PlayerTextDrawSetString(playerid, miner_job_2_p[playerid][14], String64);
	PlayerTextDrawShow(playerid, miner_job_2_p[playerid][14]);	

	panel_progress_mine_konveer(playerid);

	mine_position_td[playerid] = 7;

	SelectTextDraw(playerid, COLOR_BLUE);

	SetPVarIntNew(playerid, "panel_mine_active", 1);

	TogglePlayerControllable(playerid, false);

	if(miner_job_2_p[playerid][11] == PlayerText:INVALID_TEXT_DRAW)
	{	
		miner_job_2_p[playerid][11] = CreatePlayerTextDraw(playerid, position_frame_konveer[7][0], position_frame_konveer[7][1], "minejob:frame");
		PlayerTextDrawTextSize(playerid, miner_job_2_p[playerid][11], 52.609996, 89.070007);
		PlayerTextDrawAlignment(playerid, miner_job_2_p[playerid][11], 1);
		PlayerTextDrawColor(playerid, miner_job_2_p[playerid][11], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_2_p[playerid][11], 255);
		PlayerTextDrawFont(playerid, miner_job_2_p[playerid][11], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_2_p[playerid][11], 0);
	}

	PlayerTextDrawShow(playerid, miner_job_2_p[playerid][11]);
	return true;
}

stock update_bonus_mine_konveer(playerid)
{
	new 
		Float:count;

	if(get_job_level(playerid, SKILL_MINER) == 1)
	{
		switch(random(5))
		{
			case 0: count = 15.0;
			case 1: count = 17.5;
			case 2: count = 16.3;
			case 3: count = 18.0;
			case 4: count = 20.0;
			case 5: count = 25.0;
		}
	}
	if(get_job_level(playerid, SKILL_MINER) == 2)
	{
		switch(random(5))
		{
			case 0: count = 15.0;
			case 1: count = 17.5;
			case 2: count = 16.0;
			case 3: count = 20.0;
			case 4: count = 19.0;
			case 5: count = 15.0;
		}
	}
	if(get_job_level(playerid, SKILL_MINER) == 3)
	{
		switch(random(5))
		{
			case 0: count = 25.0;
			case 1: count = 27.5;
			case 2: count = 26.0;
			case 3: count = 30.0;
			case 4: count = 29.0;
			case 5: count = 25.0;
		}
	}
	if(get_job_level(playerid, SKILL_MINER) == 4)
	{
		switch(random(5))
		{
			case 0: count = 35.0;
			case 1: count = 37.5;
			case 2: count = 36.0;
			case 3: count = 40.0;
			case 4: count = 39.0;
			case 5: count = 35.0;
		}
	}
	if(get_job_level(playerid, SKILL_MINER) == 5)
	{
		switch(random(5))
		{
			case 0: count = 45.0;
			case 1: count = 47.5;
			case 2: count = 46.0;
			case 3: count = 50.0;
			case 4: count = 49.0;
			case 5: count = 45.0;
		}
	}

	progress_job_mine_konveer[playerid] +=count;

	new 
		fmt_str[50];

	if(miner_job_2_p[playerid][1] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_2_p[playerid][1] = CreatePlayerTextDraw(playerid, 319.999938, 68.000015, "+_11");
		PlayerTextDrawLetterSize(playerid, miner_job_2_p[playerid][1], 0.574998, 2.678518);
		PlayerTextDrawTextSize(playerid, miner_job_2_p[playerid][1], 0.000000, 513.360351);
		PlayerTextDrawAlignment(playerid, miner_job_2_p[playerid][1], 2);
		PlayerTextDrawColor(playerid, miner_job_2_p[playerid][1], -1);
		PlayerTextDrawSetShadow(playerid, miner_job_2_p[playerid][1], 0);
		PlayerTextDrawBackgroundColor(playerid, miner_job_2_p[playerid][1], 255);
		PlayerTextDrawFont(playerid, miner_job_2_p[playerid][1], 1);
		PlayerTextDrawSetProportional(playerid, miner_job_2_p[playerid][1], 1);
	}

 	format(fmt_str,sizeof(fmt_str),"+_%d", floatround(count, floatround_round));
	PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][1], fmt_str);
	PlayerTextDrawShow(playerid, miner_job_2_p[playerid][1]);

	SetTimerEx("hide_mine_notify_konveer", 2000, false, "i", playerid);

 	format(fmt_str,sizeof(fmt_str),"%06.0f", progress_job_mine_konveer[playerid]);
	PlayerTextDrawSetString(playerid,miner_job_2_p[playerid][2], fmt_str);
	PlayerTextDrawShow(playerid, miner_job_2_p[playerid][2]);

	return true;
}

callback:: hide_mine_notify_konveer(playerid)
{

	PlayerTextDrawHideEx(playerid, miner_job_2_p[playerid][1]);

	return true;
}


stock final_player_miner_konveer(playerid)
{
	PlayerTextDrawHide(playerid, miner_job_2_p[playerid][11]);
	PlayerTextDrawDestroy(playerid, miner_job_2_p[playerid][11]);

	panel_miner_konveer(playerid, TEXTDRAW_HIDE);
 	CancelSelectTextDraw(playerid);

 	miner_select_material_mining[playerid] = MINEJOB_NONE;
 	mine_random_material_active[playerid] = -1;

 	DeletePVarNew(playerid, "panel_mine_active");

 	return true;
}

stock close_player_miner_konveer(playerid)
{
	panel_miner_konveer(playerid, TEXTDRAW_HIDE);
 	CancelSelectTextDraw(playerid);

	PlayerTextDrawHide(playerid, miner_job_2_p[playerid][11]);
	PlayerTextDrawDestroy(playerid, miner_job_2_p[playerid][11]);
	
 	miner_select_material_mining[playerid] = MINEJOB_NONE;
 	mine_random_material_active[playerid] = -1;
 	mine_miner_progress_bar[playerid] = 0;
 	mine_konveer_massive_object_td[playerid] = 0;
 	miner_select_material_mining[playerid] = 0;
 	mine_position_td[playerid] = 0;
	mine_konveer_all_object[playerid] = 0;
	mine_konveer_select_object[playerid] = 0;

 	DeletePVarNew(playerid, "panel_mine_active");

	return true;
}

stock change_type_job_konveer(playerid)
{
	panel_miner_konveer(playerid, TEXTDRAW_HIDE);
 	CancelSelectTextDraw(playerid);


 	miner_select_material_mining[playerid] = MINEJOB_NONE;
 	mine_random_material_active[playerid] = -1;
 	mine_miner_progress_bar[playerid] = 0;
 	mine_konveer_massive_object_td[playerid] = 0;
 	miner_select_material_mining[playerid] = 0;
 	mine_position_td[playerid] = 0;
	mine_konveer_all_object[playerid] = 0;
	mine_konveer_select_object[playerid] = 0;

 	DeletePVarNew(playerid, "panel_mine_active");


	return true;
}

stock next_stap_konveer_mine(playerid)
{
	PlayerTextDrawHide(playerid, miner_job_2_p[playerid][11]);
	PlayerTextDrawDestroy(playerid, miner_job_2_p[playerid][11]);

	SCM(playerid, -1, "");
	SendInf(playerid, "ќтправл€йтесь на укомплектовку руды по контейнерам!");

	mine_player_pickup[playerid][2] = CreateDynamicPickup(13720, 8, -755.9485,-2775.0239,-19.9000, -1, -1, playerid);

	SetPVarIntNew(playerid, "miner_type_work", STAP_JOB_MINER_SORT);

	SetPVarIntNew(playerid, "miner_job_count", GetPVarIntNew(playerid, "miner_job_count")+5);

	change_type_job_konveer(playerid);

	ClearAnimations(playerid);

	TogglePlayerControllable(playerid, true);

	return true;
}

stock check_pos_td_konveer(playerid)
{

	if(mine_konveer_massive_object_td[playerid] == 1)
	{
		if(mine_konveer_massive_object_td[playerid] == 1 && miner_select_material_mining[playerid] == MINEJOB_COAL && mine_position_td[playerid] == 6)
		{
			PlayerTextDrawHideEx(playerid, miner_job_2_p[playerid][4]);
			mine_konveer_select_object[playerid]--;
			update_bonus_mine_konveer(playerid);
		}
		if(mine_konveer_massive_object_td[playerid] == 1 && miner_select_material_mining[playerid] == MINEJOB_COPPER && mine_position_td[playerid] == 5)
		{
			PlayerTextDrawHideEx(playerid, miner_job_2_p[playerid][5]);
			mine_konveer_select_object[playerid]--;
			update_bonus_mine_konveer(playerid);
			
		}
		if(mine_konveer_massive_object_td[playerid] == 1 && miner_select_material_mining[playerid] == MINEJOB_DIAMOND && mine_position_td[playerid] == 4)
		{
			PlayerTextDrawHideEx(playerid, miner_job_2_p[playerid][6]);
			mine_konveer_select_object[playerid]--;
			update_bonus_mine_konveer(playerid);
		}
		if(mine_konveer_massive_object_td[playerid] == 1 && miner_select_material_mining[playerid] == MINEJOB_GOLD && mine_position_td[playerid] == 3)
		{
			PlayerTextDrawHideEx(playerid, miner_job_2_p[playerid][7]);
			mine_konveer_select_object[playerid]--;
			update_bonus_mine_konveer(playerid);
		}
		if(mine_konveer_massive_object_td[playerid] == 1 && miner_select_material_mining[playerid] == MINEJOB_IRON && mine_position_td[playerid] == 2)
		{
			PlayerTextDrawHideEx(playerid, miner_job_2_p[playerid][8]);
			mine_konveer_select_object[playerid]--;
			update_bonus_mine_konveer(playerid);
		}
		if(mine_konveer_massive_object_td[playerid] == 1 && miner_select_material_mining[playerid] == MINEJOB_METAL && mine_position_td[playerid] == 1)
		{
			PlayerTextDrawHideEx(playerid, miner_job_2_p[playerid][9]);
			mine_konveer_select_object[playerid]--;
			update_bonus_mine_konveer(playerid);
		}
	}
	if(mine_konveer_massive_object_td[playerid] == 2)
	{
		if(mine_konveer_massive_object_td[playerid] == 2 && miner_select_material_mining[playerid] == MINEJOB_COAL && mine_position_td[playerid] == 1)
		{
			PlayerTextDrawHideEx(playerid, miner_job_2_p[playerid][9]);
			mine_konveer_select_object[playerid]--;
			update_bonus_mine_konveer(playerid);
		}
		if(mine_konveer_massive_object_td[playerid] == 2 && miner_select_material_mining[playerid] == MINEJOB_COPPER && mine_position_td[playerid] == 6)
		{
			PlayerTextDrawHideEx(playerid, miner_job_2_p[playerid][4]);
			mine_konveer_select_object[playerid]--;
			update_bonus_mine_konveer(playerid);
		}
		if(mine_konveer_massive_object_td[playerid] == 2 && miner_select_material_mining[playerid] == MINEJOB_DIAMOND && mine_position_td[playerid] == 5)
		{
			PlayerTextDrawHideEx(playerid, miner_job_2_p[playerid][5]);
			mine_konveer_select_object[playerid]--;
			update_bonus_mine_konveer(playerid);
		}
		if(mine_konveer_massive_object_td[playerid] == 2 && miner_select_material_mining[playerid] == MINEJOB_GOLD && mine_position_td[playerid] == 3)
		{
			PlayerTextDrawHideEx(playerid, miner_job_2_p[playerid][7]);
			mine_konveer_select_object[playerid]--;
			update_bonus_mine_konveer(playerid);
		}
		if(mine_konveer_massive_object_td[playerid] == 2 && miner_select_material_mining[playerid] == MINEJOB_IRON && mine_position_td[playerid] == 4)
		{
			PlayerTextDrawHideEx(playerid, miner_job_2_p[playerid][6]);
			mine_konveer_select_object[playerid]--;
			update_bonus_mine_konveer(playerid);
		}
		if(mine_konveer_massive_object_td[playerid] == 2 && miner_select_material_mining[playerid] == MINEJOB_METAL && mine_position_td[playerid] == 2)
		{
			PlayerTextDrawHideEx(playerid, miner_job_2_p[playerid][8]);
			mine_konveer_select_object[playerid]--;
			update_bonus_mine_konveer(playerid);
		}		
	}
	if(mine_konveer_massive_object_td[playerid] == 3)
	{
		if(mine_konveer_massive_object_td[playerid] == 3 && miner_select_material_mining[playerid] == MINEJOB_COAL && mine_position_td[playerid] == 3)
		{
			PlayerTextDrawHideEx(playerid, miner_job_2_p[playerid][7]);
			mine_konveer_select_object[playerid]--;
			update_bonus_mine_konveer(playerid);
		}
		if(mine_konveer_massive_object_td[playerid] == 3 && miner_select_material_mining[playerid] == MINEJOB_COPPER && mine_position_td[playerid] == 2)
		{
			PlayerTextDrawHideEx(playerid, miner_job_2_p[playerid][8]);
			mine_konveer_select_object[playerid]--;
			update_bonus_mine_konveer(playerid);
		}
		if(mine_konveer_massive_object_td[playerid] == 3 && miner_select_material_mining[playerid] == MINEJOB_DIAMOND && mine_position_td[playerid] == 6)
		{
			PlayerTextDrawHideEx(playerid, miner_job_2_p[playerid][4]);
			mine_konveer_select_object[playerid]--;
			update_bonus_mine_konveer(playerid);
		}
		if(mine_konveer_massive_object_td[playerid] == 3 && miner_select_material_mining[playerid] == MINEJOB_GOLD && mine_position_td[playerid] == 5)
		{
			PlayerTextDrawHideEx(playerid, miner_job_2_p[playerid][5]);
			mine_konveer_select_object[playerid]--;
			update_bonus_mine_konveer(playerid);
		}
		if(mine_konveer_massive_object_td[playerid] == 3 && miner_select_material_mining[playerid] == MINEJOB_IRON && mine_position_td[playerid] == 4)
		{
			PlayerTextDrawHideEx(playerid, miner_job_2_p[playerid][6]);
			mine_konveer_select_object[playerid]--;
			update_bonus_mine_konveer(playerid);
		}
		if(mine_konveer_massive_object_td[playerid] == 3 && miner_select_material_mining[playerid] == MINEJOB_METAL && mine_position_td[playerid] == 1)
		{
			PlayerTextDrawHideEx(playerid, miner_job_2_p[playerid][9]);
			mine_konveer_select_object[playerid]--;
			update_bonus_mine_konveer(playerid);
		}		
	}
	if(mine_konveer_massive_object_td[playerid] == 4)
	{
		if(mine_konveer_massive_object_td[playerid] == 4 && miner_select_material_mining[playerid] == MINEJOB_COAL && mine_position_td[playerid] == 1)
		{
			PlayerTextDrawHideEx(playerid, miner_job_2_p[playerid][9]);
			mine_konveer_select_object[playerid]--;
			update_bonus_mine_konveer(playerid);
		}
		if(mine_konveer_massive_object_td[playerid] == 4 && miner_select_material_mining[playerid] == MINEJOB_COPPER && mine_position_td[playerid] == 3)
		{
			PlayerTextDrawHideEx(playerid, miner_job_2_p[playerid][7]);
			mine_konveer_select_object[playerid]--;
			update_bonus_mine_konveer(playerid);
		}
		if(mine_konveer_massive_object_td[playerid] == 4 && miner_select_material_mining[playerid] == MINEJOB_DIAMOND && mine_position_td[playerid] == 4)
		{
			PlayerTextDrawHideEx(playerid, miner_job_2_p[playerid][6]);
			mine_konveer_select_object[playerid]--;
			update_bonus_mine_konveer(playerid);
		}
		if(mine_konveer_massive_object_td[playerid] == 4 && miner_select_material_mining[playerid] == MINEJOB_GOLD && mine_position_td[playerid] == 6)
		{
			PlayerTextDrawHideEx(playerid, miner_job_2_p[playerid][4]);
			mine_konveer_select_object[playerid]--;
			update_bonus_mine_konveer(playerid);
		}
		if(mine_konveer_massive_object_td[playerid] == 4 && miner_select_material_mining[playerid] == MINEJOB_IRON && mine_position_td[playerid] == 2)
		{
			PlayerTextDrawHideEx(playerid, miner_job_2_p[playerid][8]);
			mine_konveer_select_object[playerid]--;
			update_bonus_mine_konveer(playerid);
		}
		if(mine_konveer_massive_object_td[playerid] == 4 && miner_select_material_mining[playerid] == MINEJOB_METAL && mine_position_td[playerid] == 5)
		{
			PlayerTextDrawHideEx(playerid, miner_job_2_p[playerid][5]);
			mine_konveer_select_object[playerid]--;
			update_bonus_mine_konveer(playerid);
		}		
	}
	if(mine_konveer_massive_object_td[playerid] == 5)
	{
		if(mine_konveer_massive_object_td[playerid] == 5 && miner_select_material_mining[playerid] == MINEJOB_COAL && mine_position_td[playerid] == 1)
		{
			PlayerTextDrawHideEx(playerid, miner_job_2_p[playerid][9]);
			mine_konveer_select_object[playerid]--;
			update_bonus_mine_konveer(playerid);
		}
		if(mine_konveer_massive_object_td[playerid] == 5 && miner_select_material_mining[playerid] == MINEJOB_COPPER && mine_position_td[playerid] == 5)
		{
			PlayerTextDrawHideEx(playerid, miner_job_2_p[playerid][5]);
			mine_konveer_select_object[playerid]--;
			update_bonus_mine_konveer(playerid);
		}
		if(mine_konveer_massive_object_td[playerid] == 5 && miner_select_material_mining[playerid] == MINEJOB_DIAMOND && mine_position_td[playerid] == 2)
		{
			PlayerTextDrawHideEx(playerid, miner_job_2_p[playerid][8]);
			mine_konveer_select_object[playerid]--;
			update_bonus_mine_konveer(playerid);
		}
		if(mine_konveer_massive_object_td[playerid] == 5 && miner_select_material_mining[playerid] == MINEJOB_GOLD && mine_position_td[playerid] == 3)
		{
			PlayerTextDrawHideEx(playerid, miner_job_2_p[playerid][7]);
			mine_konveer_select_object[playerid]--;
			update_bonus_mine_konveer(playerid);
		}
		if(mine_konveer_massive_object_td[playerid] == 5 && miner_select_material_mining[playerid] == MINEJOB_IRON && mine_position_td[playerid] == 4)
		{
			PlayerTextDrawHideEx(playerid, miner_job_2_p[playerid][6]);
			mine_konveer_select_object[playerid]--;
			update_bonus_mine_konveer(playerid);
		}
		if(mine_konveer_massive_object_td[playerid] == 5 && miner_select_material_mining[playerid] == MINEJOB_METAL && mine_position_td[playerid] == 6)
		{
			PlayerTextDrawHideEx(playerid, miner_job_2_p[playerid][4]);
			mine_konveer_select_object[playerid]--;
			update_bonus_mine_konveer(playerid);
		}		
	}
	generate_selectable_obj_konveer(playerid);

	return true;
}