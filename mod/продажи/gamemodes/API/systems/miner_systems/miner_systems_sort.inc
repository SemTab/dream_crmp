static const Float:position_miner_sklad_street[][] = 
{
	{-1444.9508,2562.8396,40.8068},
	{-1426.0107,2558.2993,40.7999},
	{-1423.7823,2563.1147,40.7999},
	{-1466.3666,2577.9658,40.7999},
	{-1448.3967,2575.3279,40.7999},
	{-1446.0856,2580.1858,40.7999}
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


stock panel_miner_sortirovka(playerid, type)
{
	switch(type)
	{
		case TEXTDRAW_SHOW:
		{
			TextDrawShowForPlayer(playerid, mine_job_3[0]);
			TextDrawShowForPlayer(playerid, mine_job_3[1]);	
			TextDrawShowForPlayer(playerid, mine_job_3[2]);
			TextDrawShowForPlayer(playerid, mine_job_3[3]);	
			TextDrawShowForPlayer(playerid, mine_job_3[4]);
			TextDrawShowForPlayer(playerid, mine_job_3[5]);
			TextDrawShowForPlayer(playerid, mine_job_3[6]);
			TextDrawShowForPlayer(playerid, mine_job_3[7]);		

			create_miner_job_3(playerid);

			generate_all_position(playerid);

		}
		case TEXTDRAW_HIDE:
		{
			TextDrawHideForPlayer(playerid, mine_job_3[0]);
			TextDrawHideForPlayer(playerid, mine_job_3[1]);	
			TextDrawHideForPlayer(playerid, mine_job_3[2]);
			TextDrawHideForPlayer(playerid, mine_job_3[3]);	
			TextDrawHideForPlayer(playerid, mine_job_3[4]);
			TextDrawHideForPlayer(playerid, mine_job_3[5]);
			TextDrawHideForPlayer(playerid, mine_job_3[6]);
			TextDrawHideForPlayer(playerid, mine_job_3[7]);		

			for(new i = 0; i < 12; i++)
			{
				if(miner_job_3_p[playerid][i] != PlayerText:INVALID_TEXT_DRAW)
				{
					PlayerTextDrawHideEx(playerid, miner_job_3_p[playerid][i]);
				}
			}			
		}
	}

	return true;
}

stock generate_all_position(playerid)
{
	new 
		random_select_minig = RandomEx(0, 5);

	switch(random_select_minig)
	{
		case 0: 
		{

			mine_konveer_massive_object_td[playerid] = 1;

			// Генерация позиции руды на сортировке для выбора

			miner_select_material_sort[playerid][0] = MINEJOB_COAL;

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:coal");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	

			miner_select_material_sort[playerid][1] = MINEJOB_COPPER;

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:copper");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);

			miner_select_material_sort[playerid][2] = MINEJOB_GOLD;

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:gold");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);

			// Генерация контейнера в зависимости от типа выбранной руды		

			miner_select_material_sort_ch[playerid][0] = MINEJOB_COAL;

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][5], "minejob:chestcoal");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][5]);	

			miner_select_material_sort_ch[playerid][1] = MINEJOB_COPPER;

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][4], "minejob:chestcopper");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][4]);

			miner_select_material_sort_ch[playerid][2] = MINEJOB_GOLD;

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][3], "minejob:chestgold");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][3]);	

		}
		case 1: 
		{

			mine_konveer_massive_object_td[playerid] = 2;

			// Генерация позиции руды на сортировке для выбора

			miner_select_material_sort[playerid][0] = MINEJOB_IRON;

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:iron");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	

			miner_select_material_sort[playerid][1] = MINEJOB_COPPER;

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:copper");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);

			miner_select_material_sort[playerid][2] = MINEJOB_METAL;

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:metal");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	

			// Генерация контейнера в зависимости от типа выбранной руды		

			miner_select_material_sort_ch[playerid][0] = MINEJOB_IRON;

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][3], "minejob:chestiron");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][3]);	

			miner_select_material_sort_ch[playerid][1] = MINEJOB_COPPER;

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][4], "minejob:chestcopper");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][4]);

			miner_select_material_sort_ch[playerid][2] = MINEJOB_METAL;

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][5], "minejob:chestmetal");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][5]);	


		}
		case 2: 
		{

			mine_konveer_massive_object_td[playerid] = 3;

			// Генерация позиции руды на сортировке для выбора

			miner_select_material_sort[playerid][0] = MINEJOB_COAL;

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:coal");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	

			miner_select_material_sort[playerid][1] = MINEJOB_DIAMOND;

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:diamond");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);

			miner_select_material_sort[playerid][2] = MINEJOB_METAL;

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:metal");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	

			// Генерация контейнера в зависимости от типа выбранной руды		


			miner_select_material_sort_ch[playerid][0] = MINEJOB_COAL;

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][4], "minejob:chestcoal");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][4]);	

			miner_select_material_sort_ch[playerid][1] = MINEJOB_DIAMOND;

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][3], "minejob:chestdiamond");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][3]);

			miner_select_material_sort_ch[playerid][2] = MINEJOB_METAL;

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][5], "minejob:chestmetal");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][5]);	

		}
		case 3: 
		{
			mine_konveer_massive_object_td[playerid] = 4;

			// Генерация позиции руды на сортировке для выбора

			miner_select_material_sort[playerid][0] = MINEJOB_GOLD;

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:gold");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	

			miner_select_material_sort[playerid][1] = MINEJOB_DIAMOND;

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:diamond");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);

			miner_select_material_sort[playerid][2] = MINEJOB_COPPER;

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:copper");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	


			// Генерация контейнера в зависимости от типа выбранной руды		


			miner_select_material_sort_ch[playerid][0] = MINEJOB_GOLD;

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][4], "minejob:chestgold");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][4]);	

			miner_select_material_sort_ch[playerid][1] = MINEJOB_DIAMOND;

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][3], "minejob:chestdiamond");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][3]);

			miner_select_material_sort_ch[playerid][2] = MINEJOB_COPPER;

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][5], "minejob:chestcopper");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][5]);	


		}
	}	

	return true;
}

stock panel_progress_miner_sort(playerid)
{
	switch(mine_miner_progress_bar[playerid])
	{
		case 0: 
		{
			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][10], "minejob:p1");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][10]);				
		}
		case 3:
		{
			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][10], "minejob:p4");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][10]);	
		}
		case 6:
		{
			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][10], "minejob:p7");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][10]);				
		}
		case 9:
		{
			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][10], "minejob:p10");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][10]);				
		}

	}
	PlayerTextDrawShow(playerid, miner_job_3_p[playerid][10]);	
	return true;
}


CMD:mine_sort(playerid)
{
	return start_player_miner_sort(playerid);
}

stock start_player_miner_sort(playerid)
{


	if(!GetPVarIntNew(playerid, "miner_type_work"))
	{
		return SendInf(playerid, "Вам недоступен данный этап работы!");
	}
	if(GetPVarIntNew(playerid, "miner_type_work") != STAP_JOB_MINER_SORT)
	{
		return SendInf(playerid, "Вам недоступен данный этап работы!");
	}	
	if(GetPVarIntNew(playerid, "miner_type_work") == STAP_JOB_MINER_KONVEER)
	{
		SendInf(playerid, "Вам недоступен данный этап работы!");
		return SendInf(playerid, "Ваша задача: сортировка руды на конвеере!");
	}
	if(GetPVarIntNew(playerid, "miner_type_work") == STAP_JOB_MINER_MINING)
	{
		SendInf(playerid, "Вам недоступен данный этап работы!");
		return SendInf(playerid, "Ваша задача: добыча руды в жилах шахты!");
	}
	if(GetPVarIntNew(playerid, "miner_type_work") == STAP_JOB_MINER_LIFT)
	{
		SendInf(playerid, "Вам недоступен данный этап работы!");
		return SendInf(playerid, "Ваша задача: отнести руду в грузовой лифт!");
	}
	if(GetPVarIntNew(playerid, "miner_type_work") == STAP_JOB_MINER_SKLAD)
	{
		SendInf(playerid, "Вам недоступен данный этап работы!");
		return SendInf(playerid, "Ваша задача: отнести контейнери с рудой на склад!");
	}


	miner_chest_status[playerid][0] = 0;
	miner_chest_status[playerid][1] = 0; 
	miner_chest_status[playerid][2] = 0;
	mine_chest_progress[playerid] = 0;
	mine_miner_progress_bar[playerid] = 0;

	close_player_miner_sort(playerid);
	panel_miner_sortirovka(playerid, TEXTDRAW_SHOW);
	close_player_miner_sort(playerid);
	panel_miner_sortirovka(playerid, TEXTDRAW_SHOW);



	PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][2], "000000");
	PlayerTextDrawShow(playerid, miner_job_3_p[playerid][2]);		

	format(String64, 32, "X1");
	PlayerTextDrawSetString(playerid, miner_job_3_p[playerid][0], String64);
	PlayerTextDrawShow(playerid, miner_job_3_p[playerid][0]);	

	panel_progress_miner_sort(playerid);
	SelectTextDraw(playerid, COLOR_BLUE);
	SetPVarIntNew(playerid, "panel_mine_active", 1);
	SetPVarIntNew(playerid, "miner_type_work", STAP_JOB_MINER_SORT);

	miner_select_material_sort_td[playerid] = MINEJOB_NONE;


	TogglePlayerControllable(playerid, false);

	return true;
}

stock reload_player_miner_sort(playerid)
{
	close_player_miner_sort(playerid);
	panel_miner_sortirovka(playerid, TEXTDRAW_SHOW);
	close_player_miner_sort(playerid);
	panel_miner_sortirovka(playerid, TEXTDRAW_SHOW);

	PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][2], "000000");
	PlayerTextDrawShow(playerid, miner_job_3_p[playerid][2]);		

	format(String64, 32, "X1");
	PlayerTextDrawSetString(playerid, miner_job_3_p[playerid][11], String64);
	PlayerTextDrawShow(playerid, miner_job_3_p[playerid][11]);	

	panel_progress_miner_sort(playerid);
	SelectTextDraw(playerid, COLOR_BLUE);
	SetPVarIntNew(playerid, "panel_mine_active", 1);
	SetPVarIntNew(playerid, "miner_type_work", STAP_JOB_MINER_SORT);

	miner_select_material_sort_td[playerid] = MINEJOB_NONE;


	return true;
}

stock final_player_miner_sort(playerid)
{
	panel_miner_sortirovka(playerid, TEXTDRAW_HIDE);
 	CancelSelectTextDraw(playerid);

 	DeletePVarNew(playerid, "panel_mine_active");

 	return true;
}

stock close_player_miner_sort(playerid)
{

	miner_chest_status[playerid][0] = 0;
	miner_chest_status[playerid][1] = 0;
	miner_chest_status[playerid][2] = 0;
	mine_chest_progress[playerid] = 0;
	mine_miner_progress_bar[playerid] = 0;


	mine_konveer_massive_object[playerid][0] = 0;
	mine_konveer_massive_object[playerid][1] = 0;
	mine_konveer_massive_object[playerid][2] = 0;

	panel_miner_sortirovka(playerid, TEXTDRAW_HIDE);
 	CancelSelectTextDraw(playerid);


 	DeletePVarNew(playerid, "panel_mine_active");

	return true;
}

stock change_type_job_sort(playerid)
{
	panel_miner_sortirovka(playerid, TEXTDRAW_HIDE);
 	CancelSelectTextDraw(playerid);

 	DeletePVarNew(playerid, "panel_mine_active");

 	next_stap_miner_lift(playerid);

	return true;
}


stock next_stap_miner_sklad(playerid)
{
	close_player_miner_sort(playerid);

	SetPVarIntNew(playerid, "miner_type_work", STAP_JOB_MINER_SKLAD);

	miner_select_material_sort_td[playerid] = MINEJOB_NONE;

	DestroyDynamicPickup(mine_player_pickup[playerid][2]);
	Streamer_Update(playerid);
	
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
	RemovePlayerAttachedObject(playerid, 6);

 	SCM(playerid, -1, "");
 	SendInf(playerid, "Вы успешно произвели распределение руды по контейнерам!");
 	SendInf(playerid, "Отправляйтесь на склад, который находится на улице шахты и положить готовый контейнер на склад!");

 	SetPVarIntNew(playerid, "miner_job_count", GetPVarIntNew(playerid, "miner_job_count")+5);

	attach_miner_box(playerid, STONE_IRON, ATTACH_HAND_MINER);
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_CARRY);
	SetCameraBehindPlayer(playerid);
	TogglePlayerControllable(playerid, true);		

	new 
		random_pos_sklad = random(6);

	SetPlayerCheckpoint(playerid, position_miner_sklad_street[random_pos_sklad][0], position_miner_sklad_street[random_pos_sklad][1], position_miner_sklad_street[random_pos_sklad][2], 7.5);

	return true;
}

stock selectable_material_konveer(playerid, Text:playertextid)
{

	// Проверка на клик по руде для выбора


	if(mine_konveer_massive_object_td[playerid] == 1)
	{
		if(playertextid == mine_job_3[2])
		{
			if(mine_konveer_massive_object[playerid][0] == MINEJOB_NONE)
			{
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
				return SendErr(playerid, "Вы уже распределили данный материал");
			}

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:copper");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);	
			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:gold");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	

			miner_select_material_sort_td[playerid] = MINEJOB_COAL;
			SendInf(playerid, "Перенесите Уголь в нужный контейнер!");

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:gcoal");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	

		}
		if(playertextid == mine_job_3[3])
		{
			if(mine_konveer_massive_object[playerid][1] == MINEJOB_NONE)
			{
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
				return SendErr(playerid, "Вы уже распределили данный материал");
			}

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:gold");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	
			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:coal");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	

			miner_select_material_sort_td[playerid] = MINEJOB_COPPER;
			SendInf(playerid, "Перенесите Медь в нужный контейнер!");
			
			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:gcopper");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);	

		}
		if(playertextid == mine_job_3[4])
		{
			if(mine_konveer_massive_object[playerid][2] == MINEJOB_NONE)
			{
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
				return SendErr(playerid, "Вы уже распределили данный материал");
			}

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:coal");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	
			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:copper");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);

			miner_select_material_sort_td[playerid] = MINEJOB_GOLD;
			SendInf(playerid, "Перенесите Золото в нужный контейнер!");

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:ggold");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	

		}
	}


	if(mine_konveer_massive_object_td[playerid] == 2)
	{
		if(playertextid == mine_job_3[2])
		{
			if(miner_select_material_sort[playerid][0] == MINEJOB_NONE)
			{
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
				return SendErr(playerid, "Вы уже распределили данный материал");
			}

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:copper");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);	
			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:metal");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	

			miner_select_material_sort_td[playerid] = MINEJOB_IRON;
			SendInf(playerid, "Перенесите Железо в нужный контейнер!");

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:giron");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	

		}
		if(playertextid == mine_job_3[3])
		{
			if(miner_select_material_sort[playerid][1] == MINEJOB_NONE)
			{
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
				return SendErr(playerid, "Вы уже распределили данный материал");
			}

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:iron");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	
			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:metal");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	


			miner_select_material_sort_td[playerid] = MINEJOB_COPPER;
			SendInf(playerid, "Перенесите Медь в нужный контейнер!");

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:gcopper");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);	

			
		}
		if(playertextid == mine_job_3[4])
		{
			if(miner_select_material_sort[playerid][2] == MINEJOB_NONE)
			{
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
				return SendErr(playerid, "Вы уже распределили данный материал");
			}

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:iron");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	
			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:copper");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);	


			miner_select_material_sort_td[playerid] = MINEJOB_METAL;
			SendInf(playerid, "Перенесите Металл в нужный контейнер!");

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:gmetal");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	
		}
	}

	if(mine_konveer_massive_object_td[playerid] == 3)
	{
		if(playertextid == mine_job_3[2])
		{
			if(miner_select_material_sort[playerid][0] == MINEJOB_NONE)
			{
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
				return SendErr(playerid, "Вы уже распределили данный материал");
			}

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:diamond");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);	
			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:metal");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	

			miner_select_material_sort_td[playerid] = MINEJOB_COAL;
			SendInf(playerid, "Перенесите Уголь в нужный контейнер!");

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:gcoal");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	

		}
		if(playertextid == mine_job_3[3])
		{
			if(miner_select_material_sort[playerid][1] == MINEJOB_NONE)
			{
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
				return SendErr(playerid, "Вы уже распределили данный материал");
			}

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:coal");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	
			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:metal");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	

			miner_select_material_sort_td[playerid] = MINEJOB_DIAMOND;
			SendInf(playerid, "Перенесите Алмазы в нужный контейнер!");

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:gdiamond");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);				
		}
		if(playertextid == mine_job_3[4])
		{
			if(miner_select_material_sort[playerid][2] == MINEJOB_NONE)
			{
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
				return SendErr(playerid, "Вы уже распределили данный материал");
			}

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:diamond");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);	
			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:coal");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	

			miner_select_material_sort_td[playerid] = MINEJOB_METAL;
			SendInf(playerid, "Перенесите Металл в нужный контейнер!");

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:gmetal");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	
		}
	}


	if(mine_konveer_massive_object_td[playerid] == 4)
	{
		if(playertextid == mine_job_3[2])
		{
			if(miner_select_material_sort[playerid][0] == MINEJOB_NONE)
			{
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
				return SendErr(playerid, "Вы уже распределили данный материал");
			}

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:diamond");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);	
			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:copper");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	

			miner_select_material_sort_td[playerid] = MINEJOB_GOLD;
			SendInf(playerid, "Перенесите Золото в нужный контейнер!");

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:ggold");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	

		}
		if(playertextid == mine_job_3[3])
		{
			if(miner_select_material_sort[playerid][1] == MINEJOB_NONE)
			{
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
				return SendErr(playerid, "Вы уже распределили данный материал");
			}

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:gold");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	
			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:copper");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	


			miner_select_material_sort_td[playerid] = MINEJOB_DIAMOND;
			SendInf(playerid, "Перенесите Алмазы в нужный контейнер!");

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:gdiamond");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);	
	
		}
		if(playertextid == mine_job_3[4])
		{
			if(miner_select_material_sort[playerid][2] == MINEJOB_NONE)
			{
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
				return SendErr(playerid, "Вы уже распределили данный материал");
			}

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:gold");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	
			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:diamond");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);	

			miner_select_material_sort_td[playerid] = MINEJOB_COPPER;
			SendInf(playerid, "Перенесите Медь в нужный контейнер!");

			PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:gcopper");
			PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	
		}
	}







	// Проверка на клик по контейнеру



	if(mine_konveer_massive_object_td[playerid] == 1)
	{
		if(playertextid == mine_job_3[7])
		{
			if(miner_select_material_sort_td[playerid] == MINEJOB_NONE)
			{
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
				return SendErr(playerid, "Сперва выберите материал, который хотите переместить в контейнер");
			}

			if(miner_select_material_sort_td[playerid] == MINEJOB_COAL && miner_chest_status[playerid][0] != 1)
			{
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][5], "minejob:gchestfullcoal");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][5]);					
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
				miner_chest_status[playerid][0] = 1;

				PlayerPlaySound(playerid, 11200, 0.0, 0.0, 0.0);

				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:copper");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);	
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:gold");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:coal");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	

				mine_konveer_massive_object[playerid][0] = MINEJOB_NONE;

				mine_chest_progress[playerid]++;
				update_bonus_mine_sort(playerid);

				mine_miner_progress_bar[playerid] += 3;
				panel_progress_miner_sort(playerid);

				if(mine_chest_progress[playerid] >= 3)
					return next_stap_miner_sklad(playerid);

			}
			else
			{
				SendErr(playerid, "Вы выбрали неверный контейнер!");

				if(miner_chest_status[playerid][0] != 1)
				{
					PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][5], "minejob:rchestcoal");
					PlayerTextDrawShow(playerid, miner_job_3_p[playerid][5]);	
				}

				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:copper");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);	
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:gold");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:coal");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	

				PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);

				if(mine_miner_progress_bar[playerid] > 3)
				{
					mine_miner_progress_bar[playerid] -= 3;
					panel_progress_miner_sort(playerid);
					reload_player_miner_sort(playerid);
					return true;
				}
				if(mine_miner_progress_bar[playerid] <= 3)
				{
					mine_miner_progress_bar[playerid] = 0;
					mine_chest_progress[playerid] = 0;
					panel_progress_miner_sort(playerid);
					reload_player_miner_sort(playerid);
					return true;					
				}


				miner_select_material_sort_td[playerid] = MINEJOB_NONE;				
			}

		}
		if(playertextid == mine_job_3[6]) // 4
		{
			if(miner_select_material_sort_td[playerid] == MINEJOB_NONE)
			{
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
				return SendErr(playerid, "Сперва выберите материал, который хотите переместить в контейнер");
			}

			if(miner_select_material_sort_td[playerid] == MINEJOB_COPPER && miner_chest_status[playerid][1] != 1)
			{
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][4], "minejob:gchestfullcopper");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][4]);					
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;

				miner_chest_status[playerid][1] = 1;

				PlayerPlaySound(playerid, 11200, 0.0, 0.0, 0.0);

				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:copper");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);	
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:gold");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:coal");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	

				mine_konveer_massive_object[playerid][1] = MINEJOB_NONE;

				mine_chest_progress[playerid]++;
				update_bonus_mine_sort(playerid);
				mine_miner_progress_bar[playerid] += 3;
				panel_progress_miner_sort(playerid);


				if(mine_chest_progress[playerid] >= 3)
					return next_stap_miner_sklad(playerid);

			}
			else
			{
				SendErr(playerid, "Вы выбрали неверный контейнер!");

				if(miner_chest_status[playerid][1] != 1)
				{
					PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][4], "minejob:rchestcopper");
					PlayerTextDrawShow(playerid, miner_job_3_p[playerid][4]);	
				}

				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:copper");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);	
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:gold");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:coal");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	

				PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);

				if(mine_miner_progress_bar[playerid] > 3)
				{
					mine_miner_progress_bar[playerid] -= 3;
					panel_progress_miner_sort(playerid);
					reload_player_miner_sort(playerid);
					return true;
				}
				if(mine_miner_progress_bar[playerid] <= 3)
				{
					mine_miner_progress_bar[playerid] = 0;
					mine_chest_progress[playerid] = 0;
					panel_progress_miner_sort(playerid);
					reload_player_miner_sort(playerid);
					return true;					
				}

				miner_select_material_sort_td[playerid] = MINEJOB_NONE;		
			}			
		} 
		if(playertextid == mine_job_3[5]) // 3
		{
			if(miner_select_material_sort_td[playerid] == MINEJOB_NONE)
			{
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
				return SendErr(playerid, "Сперва выберите материал, который хотите переместить в контейнер");
			}

			if(miner_select_material_sort_td[playerid] == MINEJOB_GOLD && miner_chest_status[playerid][2] != 1)
			{
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][3], "minejob:gchestfullgold");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][3]);					
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;

				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:copper");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);	
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:gold");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:coal");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	

				mine_konveer_massive_object[playerid][2] = MINEJOB_NONE;

				miner_chest_status[playerid][2] = 1;

				PlayerPlaySound(playerid, 11200, 0.0, 0.0, 0.0);

				mine_chest_progress[playerid]++;
				update_bonus_mine_sort(playerid);
				mine_miner_progress_bar[playerid] += 3;
				panel_progress_miner_sort(playerid);


				if(mine_chest_progress[playerid] >= 3)
					return next_stap_miner_sklad(playerid);

			}
			else
			{
				SendErr(playerid, "Вы выбрали неверный контейнер!");

				if(miner_chest_status[playerid][2] != 1)
				{
					PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][3], "minejob:rchestgold");
					PlayerTextDrawShow(playerid, miner_job_3_p[playerid][3]);	
				}
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:copper");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);	
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:gold");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:coal");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	

				PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
				
				if(mine_miner_progress_bar[playerid] > 3)
				{
					mine_miner_progress_bar[playerid] -= 3;
					panel_progress_miner_sort(playerid);
					reload_player_miner_sort(playerid);
					return true;
				}
				if(mine_miner_progress_bar[playerid] <= 3)
				{
					mine_miner_progress_bar[playerid] = 0;
					mine_chest_progress[playerid] = 0;
					panel_progress_miner_sort(playerid);
					reload_player_miner_sort(playerid);
					return true;					
				}

				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
			}	
		}
	}





	if(mine_konveer_massive_object_td[playerid] == 2)
	{
		if(playertextid == mine_job_3[5])
		{
			if(miner_select_material_sort_td[playerid] == MINEJOB_NONE)
			{
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
				return SendErr(playerid, "Сперва выберите материал, который хотите переместить в контейнер");
			}

			if(miner_select_material_sort_td[playerid] == MINEJOB_IRON && miner_chest_status[playerid][0] != 1)
			{
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][3], "minejob:gchestfulliron");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][3]);					
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;

				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:copper");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);	
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:metal");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	

				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:iron");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	

				miner_chest_status[playerid][0] = 1;

				mine_konveer_massive_object[playerid][0] = MINEJOB_NONE;

				PlayerPlaySound(playerid, 11200, 0.0, 0.0, 0.0);

				mine_chest_progress[playerid]++;
				update_bonus_mine_sort(playerid);
				mine_miner_progress_bar[playerid] += 3;
				panel_progress_miner_sort(playerid);


				if(mine_chest_progress[playerid] >= 3)
					return next_stap_miner_sklad(playerid);

			}
			else
			{
				SendErr(playerid, "Вы выбрали неверный контейнер!");

				if(miner_chest_status[playerid][0] != 1)
				{
					PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][3], "minejob:rchestiron");
					PlayerTextDrawShow(playerid, miner_job_3_p[playerid][3]);		
				}

				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:copper");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);	
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:metal");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	

				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:iron");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	

				PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
				
				if(mine_miner_progress_bar[playerid] > 3)
				{
					mine_miner_progress_bar[playerid] -= 3;
					panel_progress_miner_sort(playerid);
					reload_player_miner_sort(playerid);
					return true;
				}
				if(mine_miner_progress_bar[playerid] <= 3)
				{
					mine_miner_progress_bar[playerid] = 0;
					mine_chest_progress[playerid] = 0;
					panel_progress_miner_sort(playerid);
					reload_player_miner_sort(playerid);
					return true;					
				}

				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
			}	

		}
		if(playertextid == mine_job_3[7])
		{
			if(miner_select_material_sort_td[playerid] == MINEJOB_NONE)
			{
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
				return SendErr(playerid, "Сперва выберите материал, который хотите переместить в контейнер");
			}

			if(miner_select_material_sort_td[playerid] == MINEJOB_METAL && miner_chest_status[playerid][1] != 1)
			{
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][5], "minejob:gchestfullmetal");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][5]);					
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;

				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:copper");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);	
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:gmetal");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	

				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:giron");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	

				mine_konveer_massive_object[playerid][2] = MINEJOB_NONE;

				miner_chest_status[playerid][1] = 1;

				PlayerPlaySound(playerid, 11200, 0.0, 0.0, 0.0);

				mine_chest_progress[playerid]++;
				update_bonus_mine_sort(playerid);
				mine_miner_progress_bar[playerid] += 3;
				panel_progress_miner_sort(playerid);


				if(mine_chest_progress[playerid] >= 3)
					return next_stap_miner_sklad(playerid);

			}
			else
			{
				SendErr(playerid, "Вы выбрали неверный контейнер!");

				if(miner_chest_status[playerid][1] != 1)
				{
					PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][5], "minejob:rchestmetal");
					PlayerTextDrawShow(playerid, miner_job_3_p[playerid][5]);	
				}

				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:copper");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);	
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:metal");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	

				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:iron");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	

				PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
				
				if(mine_miner_progress_bar[playerid] > 3)
				{
					mine_miner_progress_bar[playerid] -= 3;
					panel_progress_miner_sort(playerid);
					reload_player_miner_sort(playerid);
					return true;
				}
				if(mine_miner_progress_bar[playerid] <= 3)
				{
					mine_miner_progress_bar[playerid] = 0;
					mine_chest_progress[playerid] = 0;
					panel_progress_miner_sort(playerid);
					reload_player_miner_sort(playerid);
					return true;					
				}

				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
			}			
		}
		if(playertextid == mine_job_3[6])
		{
			if(miner_select_material_sort_td[playerid] == MINEJOB_NONE)
			{
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
				return SendErr(playerid, "Сперва выберите материал, который хотите переместить в контейнер");
			}

			if(miner_select_material_sort_td[playerid] == MINEJOB_COPPER && miner_chest_status[playerid][2] != 1)
			{
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][4], "minejob:gchestfullcopper");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][4]);					
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;

				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:copper");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);	
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:metal");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	

				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:iron");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	

				miner_chest_status[playerid][2] = 1;

				mine_konveer_massive_object[playerid][1] = MINEJOB_NONE;

				PlayerPlaySound(playerid, 11200, 0.0, 0.0, 0.0);

				mine_chest_progress[playerid]++;
				update_bonus_mine_sort(playerid);
				mine_miner_progress_bar[playerid] += 3;
				panel_progress_miner_sort(playerid);


				if(mine_chest_progress[playerid] >= 3)
					return next_stap_miner_sklad(playerid);

			}
			else
			{
				SendErr(playerid, "Вы выбрали неверный контейнер!");

				if(miner_chest_status[playerid][2] != 1)
				{
					PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][4], "minejob:rchestcopper");
					PlayerTextDrawShow(playerid, miner_job_3_p[playerid][4]);					
				}

				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:copper");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);	
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:metal");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	

				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:iron");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	

				PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
				
				if(mine_miner_progress_bar[playerid] > 3)
				{
					mine_miner_progress_bar[playerid] -= 3;
					panel_progress_miner_sort(playerid);
					reload_player_miner_sort(playerid);
					return true;
				}
				if(mine_miner_progress_bar[playerid] <= 3)
				{
					mine_miner_progress_bar[playerid] = 0;
					mine_chest_progress[playerid] = 0;
					panel_progress_miner_sort(playerid);
					reload_player_miner_sort(playerid);
					return true;					
				}

				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
			}
		}
	}


	if(mine_konveer_massive_object_td[playerid] == 3)
	{
		if(playertextid == mine_job_3[5])
		{
			if(miner_select_material_sort_td[playerid] == MINEJOB_NONE)
			{
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
				return SendErr(playerid, "Сперва выберите материал, который хотите переместить в контейнер");
			}

			if(miner_select_material_sort_td[playerid] == MINEJOB_DIAMOND && miner_chest_status[playerid][0] != 1)
			{
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][3], "minejob:gchestfulldiamond");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][3]);					
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;

				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:diamond");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);	
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:metal");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	

				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:coal");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	

				miner_chest_status[playerid][0] = 1;

				mine_konveer_massive_object[playerid][1] = MINEJOB_NONE;

				PlayerPlaySound(playerid, 11200, 0.0, 0.0, 0.0);
				
				mine_chest_progress[playerid]++;
				update_bonus_mine_sort(playerid);
				mine_miner_progress_bar[playerid] += 3;
				panel_progress_miner_sort(playerid);


				if(mine_chest_progress[playerid] >= 3)
					return next_stap_miner_sklad(playerid);


			}
			else
			{
				SendErr(playerid, "Вы выбрали неверный контейнер!");

				if(miner_chest_status[playerid][0] != 1)
				{
					PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][3], "minejob:rchestdiamond");
					PlayerTextDrawShow(playerid, miner_job_3_p[playerid][3]);	
				}

				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:diamond");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);	
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:metal");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	

				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:coal");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	

				PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
				
				if(mine_miner_progress_bar[playerid] > 3)
				{
					mine_miner_progress_bar[playerid] -= 3;
					panel_progress_miner_sort(playerid);
					reload_player_miner_sort(playerid);
					return true;
				}
				if(mine_miner_progress_bar[playerid] <= 3)
				{
					mine_miner_progress_bar[playerid] = 0;
					mine_chest_progress[playerid] = 0;
					panel_progress_miner_sort(playerid);
					reload_player_miner_sort(playerid);
					return true;					
				}

				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
			}

		}
		if(playertextid == mine_job_3[6])
		{
			if(miner_select_material_sort_td[playerid] == MINEJOB_NONE)
			{
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
				return SendErr(playerid, "Сперва выберите материал, который хотите переместить в контейнер");
			}

			if(miner_select_material_sort_td[playerid] == MINEJOB_COAL && miner_chest_status[playerid][1] != 1)
			{
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][4], "minejob:gchestfullcoal");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][4]);					
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;

				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:diamond");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);	
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:metal");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	

				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:coal");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	

				miner_chest_status[playerid][1] = 1;

				mine_konveer_massive_object[playerid][0] = MINEJOB_NONE;

				PlayerPlaySound(playerid, 11200, 0.0, 0.0, 0.0);

				mine_chest_progress[playerid]++;
				update_bonus_mine_sort(playerid);
				mine_miner_progress_bar[playerid] += 3;
				panel_progress_miner_sort(playerid);


				if(mine_chest_progress[playerid] >= 3)
					return next_stap_miner_sklad(playerid);

			}
			else
			{
				SendErr(playerid, "Вы выбрали неверный контейнер!");

				if(miner_chest_status[playerid][1])
				{
					PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][4], "minejob:rchestcoal");
					PlayerTextDrawShow(playerid, miner_job_3_p[playerid][4]);
				}

				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:diamond");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);	
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:metal");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	

				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:coal");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	

				PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
				
				if(mine_miner_progress_bar[playerid] > 3)
				{
					mine_miner_progress_bar[playerid] -= 3;
					panel_progress_miner_sort(playerid);
					reload_player_miner_sort(playerid);
					return true;
				}
				if(mine_miner_progress_bar[playerid] <= 3)
				{
					mine_miner_progress_bar[playerid] = 0;
					mine_chest_progress[playerid] = 0;
					panel_progress_miner_sort(playerid);
					reload_player_miner_sort(playerid);
					return true;					
				}

				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
			}			
		}
		if(playertextid == mine_job_3[7])
		{
			if(miner_select_material_sort_td[playerid] == MINEJOB_NONE)
			{
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
				return SendErr(playerid, "Сперва выберите материал, который хотите переместить в контейнер");
			}

			if(miner_select_material_sort_td[playerid] == MINEJOB_METAL && miner_chest_status[playerid][2] != 1)
			{
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][5], "minejob:gchestfullmetal");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][5]);					
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;

				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:diamond");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);	
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:metal");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	

				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:coal");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	

				miner_chest_status[playerid][2] = 1;

				mine_konveer_massive_object[playerid][2] = MINEJOB_NONE;

				PlayerPlaySound(playerid, 11200, 0.0, 0.0, 0.0);

				mine_chest_progress[playerid]++;
				update_bonus_mine_sort(playerid);
				mine_miner_progress_bar[playerid] += 3;
				panel_progress_miner_sort(playerid);


				if(mine_chest_progress[playerid] >= 3)
					return next_stap_miner_sklad(playerid);

			}
			else
			{
				SendErr(playerid, "Вы выбрали неверный контейнер!");

				if(miner_chest_status[playerid][2] != 1)
				{
					PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][5], "minejob:rchestmetal");
					PlayerTextDrawShow(playerid, miner_job_3_p[playerid][5]);	
				}

				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:diamond");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);	
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:metal");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	

				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:coal");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	

				PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
				
				if(mine_miner_progress_bar[playerid] > 3)
				{
					mine_miner_progress_bar[playerid] -= 3;
					panel_progress_miner_sort(playerid);
					reload_player_miner_sort(playerid);
					return true;
				}
				if(mine_miner_progress_bar[playerid] <= 3)
				{
					mine_miner_progress_bar[playerid] = 0;
					mine_chest_progress[playerid] = 0;
					panel_progress_miner_sort(playerid);
					reload_player_miner_sort(playerid);
					return true;					
				}

				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
			}
		}
	}



	if(mine_konveer_massive_object_td[playerid] == 4) // РАБОЧИЙ
	{
		if(playertextid == mine_job_3[5])
		{
			if(miner_select_material_sort_td[playerid] == MINEJOB_NONE)
			{
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
				return SendErr(playerid, "Сперва выберите материал, который хотите переместить в контейнер");
			}

			if(miner_select_material_sort_td[playerid] == MINEJOB_DIAMOND && miner_chest_status[playerid][0] != 1)
			{
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][3], "minejob:gchestfulldiamond");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][3]);					
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;

				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:diamond");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);	
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:copper");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	


				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:gold");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	

				miner_chest_status[playerid][0] = 1;

				mine_konveer_massive_object[playerid][1] = MINEJOB_NONE;

				PlayerPlaySound(playerid, 11200, 0.0, 0.0, 0.0);

				mine_chest_progress[playerid]++;
				update_bonus_mine_sort(playerid);
				mine_miner_progress_bar[playerid] += 3;
				panel_progress_miner_sort(playerid);


				if(mine_chest_progress[playerid] >= 3)
					return next_stap_miner_sklad(playerid);

			}
			else
			{
				SendErr(playerid, "Вы выбрали неверный контейнер!");
				if(miner_chest_status[playerid][0] != 1)
				{
					PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][3], "minejob:rchestdiamond");
					PlayerTextDrawShow(playerid, miner_job_3_p[playerid][3]);		
				}	


				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:diamond");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);	
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:copper");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	


				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:gold");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	

				PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
				
				if(mine_miner_progress_bar[playerid] > 3)
				{
					mine_miner_progress_bar[playerid] -= 3;
					panel_progress_miner_sort(playerid);
					reload_player_miner_sort(playerid);
					return true;
				}
				if(mine_miner_progress_bar[playerid] <= 3)
				{
					mine_miner_progress_bar[playerid] = 0;
					mine_chest_progress[playerid] = 0;
					panel_progress_miner_sort(playerid);
					reload_player_miner_sort(playerid);
					return true;					
				}

				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
			}
		}
		if(playertextid == mine_job_3[6])
		{
			if(miner_select_material_sort_td[playerid] == MINEJOB_NONE)
			{
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
				return SendErr(playerid, "Сперва выберите материал, который хотите переместить в контейнер");
			}

			if(miner_select_material_sort_td[playerid] == MINEJOB_GOLD && miner_chest_status[playerid][1] != 1)
			{
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][4], "minejob:gchestfullgold");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][4]);					
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;


				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:diamond");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);	
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:copper");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	


				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:gold");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	

				miner_chest_status[playerid][1] = 1;

				mine_konveer_massive_object[playerid][0] = MINEJOB_NONE;

				PlayerPlaySound(playerid, 11200, 0.0, 0.0, 0.0);

				mine_chest_progress[playerid]++;
				update_bonus_mine_sort(playerid);
				mine_miner_progress_bar[playerid] += 3;
				panel_progress_miner_sort(playerid);


				if(mine_chest_progress[playerid] >= 3)
					return next_stap_miner_sklad(playerid);

			}
			else
			{
				SendErr(playerid, "Вы выбрали неверный контейнер!");

				if(miner_chest_status[playerid][1] != 1)
				{
					PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][4], "minejob:rchestgold");
					PlayerTextDrawShow(playerid, miner_job_3_p[playerid][4]);	
				}


				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:diamond");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);	
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:copper");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	


				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:gold");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	

				PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
				
				if(mine_miner_progress_bar[playerid] > 3)
				{
					mine_miner_progress_bar[playerid] -= 3;
					panel_progress_miner_sort(playerid);
					reload_player_miner_sort(playerid);
					return true;
				}
				if(mine_miner_progress_bar[playerid] <= 3)
				{
					mine_miner_progress_bar[playerid] = 0;
					mine_chest_progress[playerid] = 0;
					panel_progress_miner_sort(playerid);
					reload_player_miner_sort(playerid);
					return true;					
				}

				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
			}			
		}
		if(playertextid == mine_job_3[7])
		{
			if(miner_select_material_sort_td[playerid] == MINEJOB_NONE)
			{
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
				return SendErr(playerid, "Сперва выберите материал, который хотите переместить в контейнер");
			}

			if(miner_select_material_sort_td[playerid] == MINEJOB_COPPER && miner_chest_status[playerid][2] != 1)
			{
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][5], "minejob:gchestfullcopper");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][5]);					
				miner_select_material_sort_td[playerid] = MINEJOB_NONE;

				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:diamond");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);	
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:copper");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	


				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:gold");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	

				miner_chest_status[playerid][2] = 1;

				mine_konveer_massive_object[playerid][2] = MINEJOB_NONE;

				PlayerPlaySound(playerid, 11200, 0.0, 0.0, 0.0);

				mine_chest_progress[playerid]++;
				update_bonus_mine_sort(playerid);

				if(mine_chest_progress[playerid] >= 3)
					return next_stap_miner_sklad(playerid);

				mine_miner_progress_bar[playerid] += 3;
				panel_progress_miner_sort(playerid);

			}
			else
			{
				SendErr(playerid, "Вы выбрали неверный контейнер!");
				if(miner_chest_status[playerid][2] != 1)
				{
					PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][5], "minejob:rchestcopper");
					PlayerTextDrawShow(playerid, miner_job_3_p[playerid][5]);		
				}			

				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][7], "minejob:diamond");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][7]);	
				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][8], "minejob:copper");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][8]);	


				PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][6], "minejob:gold");
				PlayerTextDrawShow(playerid, miner_job_3_p[playerid][6]);	

				PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
				
				if(mine_miner_progress_bar[playerid] > 3)
				{
					mine_miner_progress_bar[playerid] -= 3;
					panel_progress_miner_sort(playerid);
					reload_player_miner_sort(playerid);
					return true;
				}
				if(mine_miner_progress_bar[playerid] <= 3)
				{
					mine_miner_progress_bar[playerid] = 0;
					mine_chest_progress[playerid] = 0;
					panel_progress_miner_sort(playerid);
					reload_player_miner_sort(playerid);
					return true;					
				}

				miner_select_material_sort_td[playerid] = MINEJOB_NONE;
			}	
		}
	}


	return true;
}



stock attach_miner_box(playerid, type_stone, type_stone_bone) 
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
							SetPlayerAttachedObject(playerid, 6, 13743, 6,
								0.000000, 0.183999, -0.261999, 
								-108.400001, -6.399997, 80.200004, 
								1.217000, 1.085000, 1.120999);
						}
						case 1: 
						{
							SetPlayerAttachedObject(playerid, 6, 13744, 6,
								0.000000, 0.183999, -0.261999, 
								-108.400001, -6.399997, 80.200004, 
								1.217000, 1.085000, 1.120999);
						}
						case 2: 
						{
							SetPlayerAttachedObject(playerid, 6, 13745, 6,
								0.000000, 0.183999, -0.261999, 
								-108.400001, -6.399997, 80.200004, 
								1.217000, 1.085000, 1.120999);
						}
					}
				}
			}
		}	
	}

	return true;

}


stock update_bonus_mine_sort(playerid)
{
	new 
		Float:count;

	if(get_job_level(playerid, SKILL_MINER) == 1)
	{
		switch(random(5))
		{
			case 0: count = 25.0;
			case 1: count = 27.5;
			case 2: count = 26.3;
			case 3: count = 38.0;
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
	
	new 
		Float:update = progress_job_mine_sort[playerid]+count;

	new 
		fmt_str[50];

	if(miner_job_3_p[playerid][1] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_3_p[playerid][1] = CreatePlayerTextDraw(playerid, 319.999938, 68.000015, "+_11");
		PlayerTextDrawLetterSize(playerid, miner_job_3_p[playerid][1], 0.574998, 2.678518);
		PlayerTextDrawTextSize(playerid, miner_job_3_p[playerid][1], 0.000000, 513.360351);
		PlayerTextDrawAlignment(playerid, miner_job_3_p[playerid][1], 2);
		PlayerTextDrawColor(playerid, miner_job_3_p[playerid][1], -1);
		PlayerTextDrawSetShadow(playerid, miner_job_3_p[playerid][1], 0);
		PlayerTextDrawBackgroundColor(playerid, miner_job_3_p[playerid][1], 255);
		PlayerTextDrawFont(playerid, miner_job_3_p[playerid][1], 1);
		PlayerTextDrawSetProportional(playerid, miner_job_3_p[playerid][1], 1);
	}

 	format(fmt_str,sizeof(fmt_str),"+_%d", floatround(count, floatround_round));
	PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][1], fmt_str);
	PlayerTextDrawShow(playerid, miner_job_3_p[playerid][1]);

	SetTimerEx("hide_mine_notify_sort", 2000, false, "i", playerid);

 	format(fmt_str,sizeof(fmt_str),"%06.0f", update);
	PlayerTextDrawSetString(playerid,miner_job_3_p[playerid][2], fmt_str);
	PlayerTextDrawShow(playerid, miner_job_3_p[playerid][2]);

	return true;
}


callback:: hide_mine_notify_sort(playerid)
{

	PlayerTextDrawHideEx(playerid, miner_job_3_p[playerid][1]);

	return true;
}
