


CMD:test_factory2(playerid)
{
	change_work_factory_click_mith(playerid);
	return generate_work_factory_mith(playerid);
}

stock generate_work_factory_mith(playerid)
{
	new 
		random_work_factory = RandomEx(1, 5);

	SetPVarIntNew(playerid, "factory_type_mith", random_work_factory);

	SetPVarIntNew(playerid, "factory_mith_active_td", 1);

	TextDrawShowForPlayer(playerid, factory_job_2[0]);
	TextDrawShowForPlayer(playerid, factory_job_2[1]);

	factory_job_mith_count[playerid] = 0;

	hide_hud_element(playerid);

	new 
		fmt_str[50];

	switch(random_work_factory)
	{
		case WORK_FACTORY_CLOCKER:
		{
			TogglePlayerControllable(playerid, false);
			SelectTextDraw(playerid, COLOR_BLUE);

			creator_factory_mith_1_p(playerid);

			//9-14 кликабельныен

			PlayerTextDrawSetString(playerid, factory_job_two_1_p[3][playerid], "locksmithjob:lsui_glocker1");
			PlayerTextDrawSetString(playerid, factory_job_two_1_p[4][playerid], "locksmithjob:lsui_glocker2");
			PlayerTextDrawSetString(playerid, factory_job_two_1_p[5][playerid], "locksmithjob:lsui_glocker3");
			PlayerTextDrawSetString(playerid, factory_job_two_1_p[6][playerid], "locksmithjob:lsui_glocker4");
			PlayerTextDrawSetString(playerid, factory_job_two_1_p[7][playerid], "locksmithjob:lsui_glocker5");
			PlayerTextDrawSetString(playerid, factory_job_two_1_p[8][playerid], "locksmithjob:lsui_glocker6");
			PlayerTextDrawSetString(playerid, factory_job_two_1_p[9][playerid], "locksmithjob:lsui_glockerlock");

			PlayerTextDrawSetString(playerid, factory_job_two_1_p[10][playerid], "locksmithjob:lsui_clocker4");
			PlayerTextDrawSetString(playerid, factory_job_two_1_p[11][playerid], "locksmithjob:lsui_clocker2");
			PlayerTextDrawSetString(playerid, factory_job_two_1_p[12][playerid], "locksmithjob:lsui_clocker6");
			PlayerTextDrawSetString(playerid, factory_job_two_1_p[13][playerid], "locksmithjob:lsui_clocker1");
			PlayerTextDrawSetString(playerid, factory_job_two_1_p[14][playerid], "locksmithjob:lsui_clocker3");
			PlayerTextDrawSetString(playerid, factory_job_two_1_p[15][playerid], "locksmithjob:lsui_clocker5");
			PlayerTextDrawSetString(playerid, factory_job_two_1_p[16][playerid], "locksmithjob:lsui_clockerlock");

			PlayerTextDrawShow(playerid, factory_job_two_1_p[0][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_1_p[2][playerid]);

			PlayerTextDrawShow(playerid, factory_job_two_1_p[3][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_1_p[4][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_1_p[5][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_1_p[6][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_1_p[7][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_1_p[8][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_1_p[9][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_1_p[10][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_1_p[11][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_1_p[12][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_1_p[13][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_1_p[14][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_1_p[15][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_1_p[16][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_1_p[17][playerid]);


		 	format(fmt_str,sizeof(fmt_str),"%06.0f", factory_job_count_point[playerid]);
			PlayerTextDrawSetString(playerid,factory_job_two_1_p[2][playerid], fmt_str);
			PlayerTextDrawShow(playerid, factory_job_two_1_p[2][playerid]);

		}
		case WORK_FACTORY_SUITCASE:
		{
			TogglePlayerControllable(playerid, false);
			SelectTextDraw(playerid, COLOR_BLUE);

			create_factory_mith_2_p(playerid);

			PlayerTextDrawSetString(playerid, factory_job_two_2_p[3][playerid], "locksmithjob:lsui_gsuitcase1");
			PlayerTextDrawSetString(playerid, factory_job_two_2_p[4][playerid], "locksmithjob:lsui_gsuitcase2");
			PlayerTextDrawSetString(playerid, factory_job_two_2_p[5][playerid], "locksmithjob:lsui_gsuitcase3");
			PlayerTextDrawSetString(playerid, factory_job_two_2_p[6][playerid], "locksmithjob:lsui_gsuitcase4");
			PlayerTextDrawSetString(playerid, factory_job_two_2_p[7][playerid], "locksmithjob:lsui_gsuitcase5");
			PlayerTextDrawSetString(playerid, factory_job_two_2_p[8][playerid], "locksmithjob:lsui_gsuitcase6");
			PlayerTextDrawSetString(playerid, factory_job_two_2_p[9][playerid], "locksmithjob:lsui_gsuitcaselock");

			PlayerTextDrawSetString(playerid, factory_job_two_2_p[10][playerid], "locksmithjob:lsui_csuitcase4");
			PlayerTextDrawSetString(playerid, factory_job_two_2_p[11][playerid], "locksmithjob:lsui_csuitcase2");
			PlayerTextDrawSetString(playerid, factory_job_two_2_p[12][playerid], "locksmithjob:lsui_csuitcase6");
			PlayerTextDrawSetString(playerid, factory_job_two_2_p[13][playerid], "locksmithjob:lsui_csuitcase1");
			PlayerTextDrawSetString(playerid, factory_job_two_2_p[14][playerid], "locksmithjob:lsui_csuitcase3");
			PlayerTextDrawSetString(playerid, factory_job_two_2_p[15][playerid], "locksmithjob:lsui_csuitcase5");
			PlayerTextDrawSetString(playerid, factory_job_two_2_p[16][playerid], "locksmithjob:lsui_csuitcaselock");

			PlayerTextDrawShow(playerid, factory_job_two_2_p[0][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_2_p[2][playerid]);

			PlayerTextDrawShow(playerid, factory_job_two_2_p[3][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_2_p[4][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_2_p[5][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_2_p[6][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_2_p[7][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_2_p[8][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_2_p[9][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_2_p[10][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_2_p[11][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_2_p[12][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_2_p[13][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_2_p[14][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_2_p[15][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_2_p[16][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_2_p[17][playerid]);

		 	format(fmt_str,sizeof(fmt_str),"%06.0f", factory_job_count_point[playerid]);
			PlayerTextDrawSetString(playerid,factory_job_two_2_p[2][playerid], fmt_str);
			PlayerTextDrawShow(playerid, factory_job_two_2_p[2][playerid]);

		}
		case WORK_FACTORY_DOOR:
		{
			TogglePlayerControllable(playerid, false);
			SelectTextDraw(playerid, COLOR_BLUE);

			create_factory_mith_3_p(playerid);


			PlayerTextDrawSetString(playerid, factory_job_two_3_p[3][playerid], "locksmithjob:lsui_gbdoor1");
			PlayerTextDrawSetString(playerid, factory_job_two_3_p[4][playerid], "locksmithjob:lsui_gbdoor2");
			PlayerTextDrawSetString(playerid, factory_job_two_3_p[5][playerid], "locksmithjob:lsui_gbdoor3");
			PlayerTextDrawSetString(playerid, factory_job_two_3_p[6][playerid], "locksmithjob:lsui_gbdoor4");
			PlayerTextDrawSetString(playerid, factory_job_two_3_p[7][playerid], "locksmithjob:lsui_gbdoor5");
			PlayerTextDrawSetString(playerid, factory_job_two_3_p[8][playerid], "locksmithjob:lsui_gbdoor6");
			PlayerTextDrawSetString(playerid, factory_job_two_3_p[9][playerid], "locksmithjob:lsui_gbdoorlock");

			PlayerTextDrawSetString(playerid, factory_job_two_3_p[10][playerid], "locksmithjob:lsui_cbdoor4");
			PlayerTextDrawSetString(playerid, factory_job_two_3_p[11][playerid], "locksmithjob:lsui_cbdoor2");
			PlayerTextDrawSetString(playerid, factory_job_two_3_p[12][playerid], "locksmithjob:lsui_cbdoor6");
			PlayerTextDrawSetString(playerid, factory_job_two_3_p[13][playerid], "locksmithjob:lsui_cbdoor1");
			PlayerTextDrawSetString(playerid, factory_job_two_3_p[14][playerid], "locksmithjob:lsui_cbdoor3");
			PlayerTextDrawSetString(playerid, factory_job_two_3_p[15][playerid], "locksmithjob:lsui_cbdoor5");
			PlayerTextDrawSetString(playerid, factory_job_two_3_p[16][playerid], "locksmithjob:lsui_cbdoorlock");

			PlayerTextDrawShow(playerid, factory_job_two_3_p[0][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_3_p[2][playerid]);

			PlayerTextDrawShow(playerid, factory_job_two_3_p[3][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_3_p[4][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_3_p[5][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_3_p[6][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_3_p[7][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_3_p[8][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_3_p[9][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_3_p[10][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_3_p[11][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_3_p[12][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_3_p[13][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_3_p[14][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_3_p[15][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_3_p[16][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_3_p[17][playerid]);


		 	format(fmt_str,sizeof(fmt_str),"%06.0f", factory_job_count_point[playerid]);
			PlayerTextDrawSetString(playerid,factory_job_two_3_p[2][playerid], fmt_str);
			PlayerTextDrawShow(playerid, factory_job_two_3_p[2][playerid]);


		}
		case WORK_FACTORY_DOOR_2:
		{
			TogglePlayerControllable(playerid, false);
			SelectTextDraw(playerid, COLOR_BLUE);

			create_factory_mith_4_p(playerid);

			PlayerTextDrawSetString(playerid, factory_job_two_4_p[3][playerid], "locksmithjob:lsui_gsdoor1");
			PlayerTextDrawSetString(playerid, factory_job_two_4_p[4][playerid], "locksmithjob:lsui_gsdoor2");
			PlayerTextDrawSetString(playerid, factory_job_two_4_p[5][playerid], "locksmithjob:lsui_gsdoor3");
			PlayerTextDrawSetString(playerid, factory_job_two_4_p[6][playerid], "locksmithjob:lsui_gsdoor4");
			PlayerTextDrawSetString(playerid, factory_job_two_4_p[7][playerid], "locksmithjob:lsui_gsdoor5");
			PlayerTextDrawSetString(playerid, factory_job_two_4_p[8][playerid], "locksmithjob:lsui_gsdoor6");
			PlayerTextDrawSetString(playerid, factory_job_two_4_p[9][playerid], "locksmithjob:lsui_gsdoorlock");

			PlayerTextDrawSetString(playerid, factory_job_two_4_p[10][playerid], "locksmithjob:lsui_csdoor4");
			PlayerTextDrawSetString(playerid, factory_job_two_4_p[11][playerid], "locksmithjob:lsui_csdoor2");
			PlayerTextDrawSetString(playerid, factory_job_two_4_p[12][playerid], "locksmithjob:lsui_csdoor6");
			PlayerTextDrawSetString(playerid, factory_job_two_4_p[13][playerid], "locksmithjob:lsui_csdoor1");
			PlayerTextDrawSetString(playerid, factory_job_two_4_p[14][playerid], "locksmithjob:lsui_csdoor3");
			PlayerTextDrawSetString(playerid, factory_job_two_4_p[15][playerid], "locksmithjob:lsui_csdoor5");
			PlayerTextDrawSetString(playerid, factory_job_two_4_p[16][playerid], "locksmithjob:lsui_csdoorlock");

			PlayerTextDrawShow(playerid, factory_job_two_4_p[0][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_4_p[2][playerid]);

			PlayerTextDrawShow(playerid, factory_job_two_4_p[3][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_4_p[4][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_4_p[5][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_4_p[6][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_4_p[7][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_4_p[8][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_4_p[9][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_4_p[10][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_4_p[11][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_4_p[12][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_4_p[13][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_4_p[14][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_4_p[15][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_4_p[16][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_4_p[17][playerid]);

		 	format(fmt_str,sizeof(fmt_str),"%06.0f", factory_job_count_point[playerid]);
			PlayerTextDrawSetString(playerid,factory_job_two_4_p[2][playerid], fmt_str);
			PlayerTextDrawShow(playerid, factory_job_two_4_p[2][playerid]);

		}
		case WORK_FACTORY_CLOCK:
		{
			TogglePlayerControllable(playerid, false);
			SelectTextDraw(playerid, COLOR_BLUE);

			create_factory_mith_5_p(playerid);

			PlayerTextDrawSetString(playerid, factory_job_two_5_p[3][playerid], "locksmithjob:lsui_glock1");
			PlayerTextDrawSetString(playerid, factory_job_two_5_p[4][playerid], "locksmithjob:lsui_glock2");
			PlayerTextDrawSetString(playerid, factory_job_two_5_p[5][playerid], "locksmithjob:lsui_glock3");
			PlayerTextDrawSetString(playerid, factory_job_two_5_p[6][playerid], "locksmithjob:lsui_glock4");
			PlayerTextDrawSetString(playerid, factory_job_two_5_p[7][playerid], "locksmithjob:lsui_glock5");
			PlayerTextDrawSetString(playerid, factory_job_two_5_p[8][playerid], "locksmithjob:lsui_glock6");

			PlayerTextDrawSetString(playerid, factory_job_two_5_p[9][playerid], "locksmithjob:lsui_clock4");
			PlayerTextDrawSetString(playerid, factory_job_two_5_p[10][playerid], "locksmithjob:lsui_clock2");
			PlayerTextDrawSetString(playerid, factory_job_two_5_p[11][playerid], "locksmithjob:lsui_clock6");
			PlayerTextDrawSetString(playerid, factory_job_two_5_p[12][playerid], "locksmithjob:lsui_clock1");
			PlayerTextDrawSetString(playerid, factory_job_two_5_p[13][playerid], "locksmithjob:lsui_clock3");
			PlayerTextDrawSetString(playerid, factory_job_two_5_p[14][playerid], "locksmithjob:lsui_clock5");


			PlayerTextDrawShow(playerid, factory_job_two_5_p[0][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_5_p[2][playerid]);

			PlayerTextDrawShow(playerid, factory_job_two_5_p[3][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_5_p[4][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_5_p[5][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_5_p[6][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_5_p[7][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_5_p[8][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_5_p[9][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_5_p[10][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_5_p[11][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_5_p[12][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_5_p[13][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_5_p[14][playerid]);
			PlayerTextDrawShow(playerid, factory_job_two_5_p[15][playerid]);

		 	format(fmt_str,sizeof(fmt_str),"%06.0f", factory_job_count_point[playerid]);
			PlayerTextDrawSetString(playerid,factory_job_two_5_p[2][playerid], fmt_str);
			PlayerTextDrawShow(playerid, factory_job_two_5_p[2][playerid]);

		}

	}
	TogglePlayerAllHudElements(playerid, HUD_ELEMENT_HIDE);
	return true;
}

stock update_count_mith_progress(playerid)
{
	new 
		type_work_factory = GetPVarIntNew(playerid, "factory_type_mith");

	new 
		fmt_str[50];

	new 
		Float:count;

	if(get_job_level(playerid, SKILL_FACTORY) == 1)
	{
		switch(random(5))
		{
			case 0: count = 5.0;
			case 1: count = 7.5;
			case 2: count = 6.3;
			case 3: count = 8.0;
			case 4: count = 2.0;
			case 5: count = 2.5;
		}
	}
	if(get_job_level(playerid, SKILL_FACTORY) == 2)
	{
		switch(random(5))
		{
			case 0: count = 5.0;
			case 1: count = 7.5;
			case 2: count = 6.0;
			case 3: count = 1.5;
			case 4: count = 9.0;
			case 5: count = 5.0;
		}
	}
	if(get_job_level(playerid, SKILL_FACTORY) == 3)
	{
		switch(random(5))
		{
			case 0: count = 5.0;
			case 1: count = 7.5;
			case 2: count = 6.0;
			case 3: count = 0.0;
			case 4: count = 9.0;
			case 5: count = 5.0;
		}
	}
	if(get_job_level(playerid, SKILL_FACTORY) == 4)
	{
		switch(random(5))
		{
			case 0: count = 5.0;
			case 1: count = 7.5;
			case 2: count = 6.0;
			case 3: count = 5.0;
			case 4: count = 9.0;
			case 5: count = 5.0;
		}
	}
	if(get_job_level(playerid, SKILL_FACTORY) == 5)
	{
		switch(random(5))
		{
			case 0: count = 5.0;
			case 1: count = 7.5;
			case 2: count = 6.0;
			case 3: count = 7.0;
			case 4: count = 9.0;
			case 5: count = 5.0;
		}
	}
	
	factory_job_count_point[playerid] +=count;

	switch(type_work_factory)
	{
		case WORK_FACTORY_CLOCKER:
		{
		 	format(fmt_str,sizeof(fmt_str),"+_%d", floatround(count, floatround_round));
			PlayerTextDrawSetString(playerid,factory_job_two_1_p[1][playerid], fmt_str);
			PlayerTextDrawShow(playerid, factory_job_two_1_p[1][playerid]);

			SetTimerEx("hode_work_factory_mith_hide", 1500, false, "i", playerid);


		 	format(fmt_str,sizeof(fmt_str),"%06.0f", factory_job_count_point[playerid]);
			PlayerTextDrawSetString(playerid,factory_job_two_1_p[2][playerid], fmt_str);
			PlayerTextDrawShow(playerid, factory_job_two_1_p[2][playerid]);

			switch(factory_job_mith_count[playerid])
			{
				case 0..1:
				{
					PlayerTextDrawSetString(playerid,factory_job_two_1_p[17][playerid], "locksmithjob:lsui_p1");
					PlayerTextDrawShow(playerid, factory_job_two_1_p[17][playerid]);	
				}
				case 2:
				{
					PlayerTextDrawSetString(playerid,factory_job_two_1_p[17][playerid], "locksmithjob:lsui_p2");
					PlayerTextDrawShow(playerid, factory_job_two_1_p[17][playerid]);	
				}
				case 3:
				{
					PlayerTextDrawSetString(playerid,factory_job_two_1_p[17][playerid], "locksmithjob:lsui_p4");
					PlayerTextDrawShow(playerid, factory_job_two_1_p[17][playerid]);	
				}
				case 4:
				{
					PlayerTextDrawSetString(playerid,factory_job_two_1_p[17][playerid], "locksmithjob:lsui_p7");
					PlayerTextDrawShow(playerid, factory_job_two_1_p[17][playerid]);	
				}
				case 5..6:
				{
					PlayerTextDrawSetString(playerid,factory_job_two_1_p[17][playerid], "locksmithjob:lsui_p9");
					PlayerTextDrawShow(playerid, factory_job_two_1_p[17][playerid]);	
				}
				case 7:
				{
					PlayerTextDrawSetString(playerid,factory_job_two_1_p[17][playerid], "locksmithjob:lsui_p10");
					PlayerTextDrawShow(playerid, factory_job_two_1_p[17][playerid]);	
				}
			}

		}
		case WORK_FACTORY_SUITCASE:
		{
		 	format(fmt_str,sizeof(fmt_str),"+_%d", floatround(count, floatround_round));
			PlayerTextDrawSetString(playerid,factory_job_two_2_p[1][playerid], fmt_str);
			PlayerTextDrawShow(playerid, factory_job_two_2_p[1][playerid]);

			SetTimerEx("hode_work_factory_mith_hide", 1500, false, "i", playerid);


		 	format(fmt_str,sizeof(fmt_str),"%06.0f", factory_job_count_point[playerid]);
			PlayerTextDrawSetString(playerid,factory_job_two_2_p[2][playerid], fmt_str);
			PlayerTextDrawShow(playerid, factory_job_two_2_p[2][playerid]);

			switch(factory_job_mith_count[playerid])
			{
				case 0..1:
				{
					PlayerTextDrawSetString(playerid,factory_job_two_2_p[17][playerid], "locksmithjob:lsui_p1");
					PlayerTextDrawShow(playerid, factory_job_two_2_p[17][playerid]);	
				}
				case 2:
				{
					PlayerTextDrawSetString(playerid,factory_job_two_2_p[17][playerid], "locksmithjob:lsui_p2");
					PlayerTextDrawShow(playerid, factory_job_two_2_p[17][playerid]);	
				}
				case 3:
				{
					PlayerTextDrawSetString(playerid,factory_job_two_2_p[17][playerid], "locksmithjob:lsui_p4");
					PlayerTextDrawShow(playerid, factory_job_two_2_p[17][playerid]);	
				}
				case 4:
				{
					PlayerTextDrawSetString(playerid,factory_job_two_2_p[17][playerid], "locksmithjob:lsui_p7");
					PlayerTextDrawShow(playerid, factory_job_two_2_p[17][playerid]);	
				}
				case 5..6:
				{
					PlayerTextDrawSetString(playerid,factory_job_two_2_p[17][playerid], "locksmithjob:lsui_p9");
					PlayerTextDrawShow(playerid, factory_job_two_2_p[17][playerid]);	
				}
				case 7:
				{
					PlayerTextDrawSetString(playerid,factory_job_two_2_p[17][playerid], "locksmithjob:lsui_p10");
					PlayerTextDrawShow(playerid, factory_job_two_2_p[17][playerid]);	
				}
			}

		}
		case WORK_FACTORY_DOOR:
		{
		 	format(fmt_str,sizeof(fmt_str),"+_%d", floatround(count, floatround_round));
			PlayerTextDrawSetString(playerid,factory_job_two_3_p[1][playerid], fmt_str);
			PlayerTextDrawShow(playerid, factory_job_two_3_p[1][playerid]);

			SetTimerEx("hode_work_factory_mith_hide", 1500, false, "i", playerid);


		 	format(fmt_str,sizeof(fmt_str),"%06.0f", factory_job_count_point[playerid]);
			PlayerTextDrawSetString(playerid,factory_job_two_3_p[2][playerid], fmt_str);
			PlayerTextDrawShow(playerid, factory_job_two_3_p[2][playerid]);

			switch(factory_job_mith_count[playerid])
			{
				case 0..1:
				{
					PlayerTextDrawSetString(playerid,factory_job_two_3_p[17][playerid], "locksmithjob:lsui_p1");
					PlayerTextDrawShow(playerid, factory_job_two_3_p[17][playerid]);	
				}
				case 2:
				{
					PlayerTextDrawSetString(playerid,factory_job_two_3_p[17][playerid], "locksmithjob:lsui_p2");
					PlayerTextDrawShow(playerid, factory_job_two_3_p[17][playerid]);	
				}
				case 3:
				{
					PlayerTextDrawSetString(playerid,factory_job_two_3_p[17][playerid], "locksmithjob:lsui_p4");
					PlayerTextDrawShow(playerid, factory_job_two_3_p[17][playerid]);	
				}
				case 4:
				{
					PlayerTextDrawSetString(playerid,factory_job_two_3_p[17][playerid], "locksmithjob:lsui_p7");
					PlayerTextDrawShow(playerid, factory_job_two_3_p[17][playerid]);	
				}
				case 5..6:
				{
					PlayerTextDrawSetString(playerid,factory_job_two_3_p[17][playerid], "locksmithjob:lsui_p9");
					PlayerTextDrawShow(playerid, factory_job_two_3_p[17][playerid]);	
				}
				case 7:
				{
					PlayerTextDrawSetString(playerid,factory_job_two_3_p[17][playerid], "locksmithjob:lsui_p10");
					PlayerTextDrawShow(playerid, factory_job_two_3_p[17][playerid]);	
				}
			}

		}
		case WORK_FACTORY_DOOR_2:
		{
		 	format(fmt_str,sizeof(fmt_str),"+_%d", floatround(count, floatround_round));
			PlayerTextDrawSetString(playerid,factory_job_two_4_p[1][playerid], fmt_str);
			PlayerTextDrawShow(playerid, factory_job_two_4_p[1][playerid]);

			SetTimerEx("hode_work_factory_mith_hide", 1500, false, "i", playerid);


		 	format(fmt_str,sizeof(fmt_str),"%06.0f", factory_job_count_point[playerid]);
			PlayerTextDrawSetString(playerid,factory_job_two_4_p[2][playerid], fmt_str);
			PlayerTextDrawShow(playerid, factory_job_two_4_p[2][playerid]);


			switch(factory_job_mith_count[playerid])
			{
				case 0..1:
				{
					PlayerTextDrawSetString(playerid,factory_job_two_4_p[17][playerid], "locksmithjob:lsui_p1");
					PlayerTextDrawShow(playerid, factory_job_two_4_p[17][playerid]);	
				}
				case 2:
				{
					PlayerTextDrawSetString(playerid,factory_job_two_4_p[17][playerid], "locksmithjob:lsui_p2");
					PlayerTextDrawShow(playerid, factory_job_two_4_p[17][playerid]);	
				}
				case 3:
				{
					PlayerTextDrawSetString(playerid,factory_job_two_4_p[17][playerid], "locksmithjob:lsui_p4");
					PlayerTextDrawShow(playerid, factory_job_two_4_p[17][playerid]);	
				}
				case 4:
				{
					PlayerTextDrawSetString(playerid,factory_job_two_4_p[17][playerid], "locksmithjob:lsui_p7");
					PlayerTextDrawShow(playerid, factory_job_two_4_p[17][playerid]);	
				}
				case 5..6:
				{
					PlayerTextDrawSetString(playerid,factory_job_two_4_p[17][playerid], "locksmithjob:lsui_p9");
					PlayerTextDrawShow(playerid, factory_job_two_4_p[17][playerid]);	
				}
				case 7:
				{
					PlayerTextDrawSetString(playerid,factory_job_two_4_p[17][playerid], "locksmithjob:lsui_p10");
					PlayerTextDrawShow(playerid, factory_job_two_4_p[17][playerid]);	
				}
			}

		}
		case WORK_FACTORY_CLOCK:
		{
		 	format(fmt_str,sizeof(fmt_str),"+_%d", floatround(count, floatround_round));
			PlayerTextDrawSetString(playerid,factory_job_two_5_p[1][playerid], fmt_str);
			PlayerTextDrawShow(playerid, factory_job_two_5_p[1][playerid]);

			SetTimerEx("hode_work_factory_mith_hide", 1500, false, "i", playerid);

		 	format(fmt_str,sizeof(fmt_str),"%06.0f", factory_job_count_point[playerid]);
			PlayerTextDrawSetString(playerid,factory_job_two_5_p[2][playerid], fmt_str);
			PlayerTextDrawShow(playerid, factory_job_two_5_p[2][playerid]);


			switch(factory_job_mith_count[playerid])
			{
				case 0..1:
				{
					PlayerTextDrawSetString(playerid,factory_job_two_5_p[15][playerid], "locksmithjob:lsui_p1");
					PlayerTextDrawShow(playerid, factory_job_two_5_p[15][playerid]);	
				}
				case 2:
				{
					PlayerTextDrawSetString(playerid,factory_job_two_5_p[15][playerid], "locksmithjob:lsui_p2");
					PlayerTextDrawShow(playerid, factory_job_two_5_p[15][playerid]);	
				}
				case 3:
				{
					PlayerTextDrawSetString(playerid,factory_job_two_5_p[15][playerid], "locksmithjob:lsui_p4");
					PlayerTextDrawShow(playerid, factory_job_two_5_p[15][playerid]);	
				}
				case 4:
				{
					PlayerTextDrawSetString(playerid,factory_job_two_5_p[15][playerid], "locksmithjob:lsui_p7");
					PlayerTextDrawShow(playerid, factory_job_two_5_p[15][playerid]);	
				}
				case 5..6:
				{
					PlayerTextDrawSetString(playerid,factory_job_two_5_p[15][playerid], "locksmithjob:lsui_p9");
					PlayerTextDrawShow(playerid, factory_job_two_5_p[15][playerid]);	
				}
				case 7:
				{
					PlayerTextDrawSetString(playerid,factory_job_two_5_p[15][playerid], "locksmithjob:lsui_p10");
					PlayerTextDrawShow(playerid, factory_job_two_5_p[15][playerid]);	
				}
			}

		}	
	}


	return true;
}

callback:: hode_work_factory_mith_hide(playerid)
{
	new 
		type_work_factory = GetPVarIntNew(playerid, "factory_type_mith");


	switch(type_work_factory)
	{
		case WORK_FACTORY_CLOCKER:
		{
			PlayerTextDrawHide(playerid, factory_job_two_1_p[1][playerid]);
		}
		case WORK_FACTORY_SUITCASE:
		{		
			PlayerTextDrawHide(playerid, factory_job_two_2_p[1][playerid]);
		}
		case WORK_FACTORY_DOOR:
		{
			PlayerTextDrawHide(playerid, factory_job_two_3_p[1][playerid]);
		}
		case WORK_FACTORY_DOOR_2:
		{
			PlayerTextDrawHide(playerid, factory_job_two_4_p[1][playerid]);
		}
		case WORK_FACTORY_CLOCK:
		{
			PlayerTextDrawHide(playerid, factory_job_two_5_p[1][playerid]);
		}
	}		
	return true;
}

stock hide_work_factory_click_mith(playerid)
{
	new 
		type_work_factory = GetPVarIntNew(playerid, "factory_type_mith");

	DeletePVarNew(playerid, "active_sklad_factory");

	factory_job_mith_count[playerid] = 0;


	TextDrawHideForPlayer(playerid, factory_job_2[0]);
	TextDrawHideForPlayer(playerid, factory_job_2[1]);

	DisablePlayerCheckpoint(playerid);
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);

	switch(type_work_factory)
	{
		case WORK_FACTORY_CLOCKER:
		{
			for(new i = 0; i < 18; i++)
			{
				if(factory_job_two_1_p[i][playerid] != PlayerText:INVALID_TEXT_DRAW)
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_1_p[i][playerid]);
				}
			}
		}
		case WORK_FACTORY_SUITCASE:
		{
			for(new i = 0; i < 18; i++)
			{
				if(factory_job_two_2_p[i][playerid] != PlayerText:INVALID_TEXT_DRAW)
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_2_p[i][playerid]);
				}
			}
		}
		case WORK_FACTORY_DOOR:
		{
			for(new i = 0; i < 18; i++)
			{
				if(factory_job_two_3_p[i][playerid] != PlayerText:INVALID_TEXT_DRAW)
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_3_p[i][playerid]);
				}
			}
		}
		case WORK_FACTORY_DOOR_2:
		{
			for(new i = 0; i < 18; i++)
			{
				if(factory_job_two_4_p[i][playerid] != PlayerText:INVALID_TEXT_DRAW)
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_4_p[i][playerid]);
				}
			}
		}
		case WORK_FACTORY_CLOCK:
		{
			for(new i = 0; i < 16; i++)
			{
				if(factory_job_two_5_p[i][playerid] != PlayerText:INVALID_TEXT_DRAW)
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_5_p[i][playerid]);
				}
			}
		}
	}
	TogglePlayerAllHudElements(playerid, HUD_ELEMENT_SHOW);
	show_hud_element(playerid);
	show_hud_hungry(playerid);
	TogglePlayerControllable(playerid, true);
	CancelSelectTextDraw(playerid);
	DeletePVarNew(playerid, "factory_type_mith");
	DeletePVarNew(playerid, "factory_mith_active_td");
	RemovePlayerAttachedObject(playerid, 2);
	return true;
}


stock change_work_factory_click_mith(playerid)
{
	new 
		type_work_factory = GetPVarIntNew(playerid, "factory_type_mith");

	show_hud_element(playerid);
	show_hud_hungry(playerid);

	TextDrawHideForPlayer(playerid, factory_job_2[0]);
	TextDrawHideForPlayer(playerid, factory_job_2[1]);

	switch(type_work_factory)
	{
		case WORK_FACTORY_CLOCKER:
		{
			for(new i = 0; i < 18; i++)
			{
				if(factory_job_two_1_p[i][playerid] != PlayerText:INVALID_TEXT_DRAW)
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_1_p[i][playerid]);
				}
			}
			give_mith_items_factory(playerid);
		}
		case WORK_FACTORY_SUITCASE:
		{
			for(new i = 0; i < 18; i++)
			{
				if(factory_job_two_2_p[i][playerid] != PlayerText:INVALID_TEXT_DRAW)
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_2_p[i][playerid]);
				}
			}
			give_mith_items_factory(playerid);
		}
		case WORK_FACTORY_DOOR:
		{
			for(new i = 0; i < 18; i++)
			{
				if(factory_job_two_3_p[i][playerid] != PlayerText:INVALID_TEXT_DRAW)
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_3_p[i][playerid]);
				}
			}
			give_mith_items_factory(playerid);
		}
		case WORK_FACTORY_DOOR_2:
		{
			for(new i = 0; i < 18; i++)
			{
				if(factory_job_two_4_p[i][playerid] != PlayerText:INVALID_TEXT_DRAW)
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_4_p[i][playerid]);
				}
			}
			give_mith_items_factory(playerid);
		}
		case WORK_FACTORY_CLOCK:
		{
			for(new i = 0; i < 16; i++)
			{
				if(factory_job_two_5_p[i][playerid] != PlayerText:INVALID_TEXT_DRAW)
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_5_p[i][playerid]);
				}
			}
			give_mith_items_factory(playerid);
		}
	}

	return true;
}

stock give_mith_items_factory(playerid, type = -1)
{

	SetPVarIntNew(playerid, "active_sklad_factory", 1);

	PlayerPlaySound(playerid, 1083, 0.0, 0.0, 0.0);
	CancelSelectTextDraw(playerid);
	SetCameraBehindPlayer(playerid);
	TogglePlayerControllable(playerid, true);	
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_CARRY);


	switch(random(3))
	{
		case 0:
		{
			SetPlayerAttachedObject(playerid, 2, 13748, 6, 0.053999, -0.061000, -0.163000, -108.799957, 4.999986, 85.699928, 1.000000, 1.000000, 1.000000);
		}
		case 1:
		{
			SetPlayerAttachedObject(playerid, 2, 13747, 6, -0.086000, 0.270000, -0.261999, -19.199993, -6.799994, -91.000007, 1.000000, 1.000000, 1.000000);
		}
		case 2:
		{
			SetPlayerAttachedObject(playerid, 2, 13749, 6, 0.124000, 0.005999, -0.141999, -18.399995, -9.400010, -0.499996, 0.688000, 1.000000, 0.718000);
		}
	}

	TogglePlayerAllHudElements(playerid, HUD_ELEMENT_SHOW);

	SendInf(playerid, "Перенесите собранную мебель на склад!");
	SendInf(playerid, "Склад отмечен у Вас на мини-карте!");

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:info_gui_zavod", 4000);

	SetPlayerCheckpoint(playerid, 653.4014,1276.9858,1746.4340, WOOD_CHECKPOINT_SIZE);

	return true;
}

stock unload_factory_job_mith(playerid)
{
	if(!GetPVarIntNew(playerid, "active_sklad_factory"))
		return SendInf(playerid, "Вы должны сперва сделать мебель!");

	factory_job_mith_count[playerid] = 0;

	DeletePVarNew(playerid, "active_sklad_factory");

	add_player_job_skill(playerid, SKILL_FACTORY);
	DisablePlayerCheckpoint(playerid);

	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);

	sklad[2][sklad_other_count_1]++;
	update_sklad_3d_text();
	save_sklad_all();

	RemovePlayerAttachedObject(playerid, 2);

	SetPVarIntNew(playerid, "furnitute_count_diamond", GetPVarIntNew(playerid, "furnitute_count_diamond")+1);

	if(pData[playerid][pQuestNewYear][5] == 2)
	{
		if(GetPVarIntNew(playerid, "furnitute_count_diamond") >= 10)
		{
			SendSucc(playerid, "Вы успешно собрали мебель! Задание выполнено!");
			check_accept_quest_newyear(playerid, 5);
		}
	}

	SendSucc(playerid, "Вы успешно перенесли мебель на склад! Продолжайте в том же духе!");

	army_info[so_patrons] += 250;
	army_info[so_guns] += 250;
	save_army_warehouse();

	SCM(playerid, -1, "");
	if(get_job_level(playerid, SKILL_FACTORY) < 5)
	{
		SFCM(playerid, COLOR_ORANGE, "[Навык] "cWH"Ваш навык работника завода: "cGR"%d уровень"cWH"", get_job_level(playerid, SKILL_FACTORY));
		SFCM(playerid, COLOR_ORANGE, "[Навык] "cWH"Для повышения навыка необходимо сделать "cGR"%d"cWH" деталей!", get_job_level_next(playerid, SKILL_FACTORY));
	}
	else
	{
		SFCM(playerid, COLOR_ORANGE, "[Навык] "cWH"Ваш навык работника завода: "cGR"%d уровень", get_job_level(playerid, SKILL_FACTORY));
	}

	check_quest_prize_start(playerid, 5);
	check_quest_prize_start(playerid, 6);
	check_quest_prize_start(playerid, 3);

	SetPVarIntNew(playerid, "miner_job_count", GetPVarIntNew(playerid, "miner_job_count")+2);

	new
		price;

	if(get_job_level(playerid, SKILL_FACTORY) == 1)
	{
		price = GetPVarIntNew(playerid,"miner_job_count")*40;
	}
	else if(get_job_level(playerid, SKILL_FACTORY) == 2)
	{
		price = floatround((GetPVarIntNew(playerid,"miner_job_count")*40)*1.2);
	}
	else if(get_job_level(playerid, SKILL_FACTORY) == 3)
	{
		price = floatround((GetPVarIntNew(playerid,"miner_job_count")*40)*1.4);
	}
	else if(get_job_level(playerid, SKILL_FACTORY) == 4)
	{
		price = floatround((GetPVarIntNew(playerid,"miner_job_count")*40)*1.6);
	}
	else if(get_job_level(playerid, SKILL_FACTORY) == 5)
	{
		price = floatround((GetPVarIntNew(playerid,"miner_job_count")*40)*2);
	}
	
    format(String144, sizeof(String144), "Вы заработали "cGR"%d "cWH"рублей!", price);
    SendInf(playerid, String144);

	return true;
}

stock work_factory_click_mith(playerid, textdraws)
{

	new 
		type_work_factory = GetPVarIntNew(playerid, "factory_type_mith");

	switch(type_work_factory)
	{
		case WORK_FACTORY_CLOCKER:
		{
			switch(textdraws)
			{
				case 1:
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_1_p[13][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_two_1_p[3][playerid], "locksmithjob:lsui_clocker1");
					PlayerTextDrawShow(playerid, factory_job_two_1_p[3][playerid]);

					factory_job_mith_count[playerid]++;
					update_count_mith_progress(playerid);
					
					if(factory_job_mith_count[playerid] >= 7)
						return change_work_factory_click_mith(playerid);

				}
				case 2:
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_1_p[11][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_two_1_p[4][playerid], "locksmithjob:lsui_clocker2");
					PlayerTextDrawShow(playerid, factory_job_two_1_p[4][playerid]);

					factory_job_mith_count[playerid]++;
					update_count_mith_progress(playerid);
					
					if(factory_job_mith_count[playerid] >= 7)
						return change_work_factory_click_mith(playerid);

				}
				case 3:
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_1_p[14][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_two_1_p[5][playerid], "locksmithjob:lsui_clocker3");
					PlayerTextDrawShow(playerid, factory_job_two_1_p[5][playerid]);

					factory_job_mith_count[playerid]++;
					update_count_mith_progress(playerid);
					
					if(factory_job_mith_count[playerid] >= 7)
						return change_work_factory_click_mith(playerid);

				}
				case 4:
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_1_p[10][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_two_1_p[6][playerid], "locksmithjob:lsui_clocker4");
					PlayerTextDrawShow(playerid, factory_job_two_1_p[6][playerid]);


					factory_job_mith_count[playerid]++;
					update_count_mith_progress(playerid);
					
					if(factory_job_mith_count[playerid] >= 7)
						return change_work_factory_click_mith(playerid);

				}
				case 5:
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_1_p[15][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_two_1_p[7][playerid], "locksmithjob:lsui_clocker5");
					PlayerTextDrawShow(playerid, factory_job_two_1_p[7][playerid]);

					factory_job_mith_count[playerid]++;
					update_count_mith_progress(playerid);
					
					if(factory_job_mith_count[playerid] >= 7)
						return change_work_factory_click_mith(playerid);


				}
				case 6:
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_1_p[12][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_two_1_p[8][playerid], "locksmithjob:lsui_clocker6");
					PlayerTextDrawShow(playerid, factory_job_two_1_p[8][playerid]);

					factory_job_mith_count[playerid]++;
					update_count_mith_progress(playerid);
					
					if(factory_job_mith_count[playerid] >= 7)
						return change_work_factory_click_mith(playerid);

				}
				case 7:
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_1_p[16][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_two_1_p[9][playerid], "locksmithjob:lsui_clocker6");
					PlayerTextDrawShow(playerid, factory_job_two_1_p[9][playerid]);

					factory_job_mith_count[playerid]++;
					update_count_mith_progress(playerid);
					
					if(factory_job_mith_count[playerid] >= 7)
						return change_work_factory_click_mith(playerid);

				}
			}
		}
		case WORK_FACTORY_SUITCASE:
		{
			switch(textdraws)
			{
				case 1:
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_2_p[13][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_two_2_p[3][playerid], "locksmithjob:lsui_csuitcase1");
					PlayerTextDrawShow(playerid, factory_job_two_2_p[3][playerid]);

					factory_job_mith_count[playerid]++;
					update_count_mith_progress(playerid);
					
					if(factory_job_mith_count[playerid] >= 7)
						return change_work_factory_click_mith(playerid);

				}
				case 2:
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_2_p[11][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_two_2_p[4][playerid], "locksmithjob:lsui_csuitcase2");
					PlayerTextDrawShow(playerid, factory_job_two_2_p[4][playerid]);


					factory_job_mith_count[playerid]++;
					update_count_mith_progress(playerid);
					
					if(factory_job_mith_count[playerid] >= 7)
						return change_work_factory_click_mith(playerid);

				}
				case 3:
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_2_p[14][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_two_2_p[5][playerid], "locksmithjob:lsui_csuitcase3");
					PlayerTextDrawShow(playerid, factory_job_two_2_p[5][playerid]);

					factory_job_mith_count[playerid]++;
					update_count_mith_progress(playerid);
					
					if(factory_job_mith_count[playerid] >= 7)
						return change_work_factory_click_mith(playerid);


				}
				case 4:
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_2_p[10][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_two_2_p[6][playerid], "locksmithjob:lsui_csuitcase4");
					PlayerTextDrawShow(playerid, factory_job_two_2_p[6][playerid]);

					factory_job_mith_count[playerid]++;
					update_count_mith_progress(playerid);
					
					if(factory_job_mith_count[playerid] >= 7)
						return change_work_factory_click_mith(playerid);


				}
				case 5:
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_2_p[15][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_two_2_p[7][playerid], "locksmithjob:lsui_csuitcase5");
					PlayerTextDrawShow(playerid, factory_job_two_2_p[7][playerid]);

					factory_job_mith_count[playerid]++;
					update_count_mith_progress(playerid);
					
					if(factory_job_mith_count[playerid] >= 7)
						return change_work_factory_click_mith(playerid);


				}
				case 6:
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_2_p[12][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_two_2_p[8][playerid], "locksmithjob:lsui_csuitcase6");
					PlayerTextDrawShow(playerid, factory_job_two_2_p[8][playerid]);


					factory_job_mith_count[playerid]++;
					update_count_mith_progress(playerid);
					
					if(factory_job_mith_count[playerid] >= 7)
						return change_work_factory_click_mith(playerid);

				}
				case 7:
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_2_p[16][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_two_2_p[9][playerid], "locksmithjob:lsui_csuitcaselock");
					PlayerTextDrawShow(playerid, factory_job_two_2_p[9][playerid]);


					factory_job_mith_count[playerid]++;
					update_count_mith_progress(playerid);
					
					if(factory_job_mith_count[playerid] >= 7)
						return change_work_factory_click_mith(playerid);

				}
			}
		}
		case WORK_FACTORY_DOOR:
		{
			switch(textdraws)
			{
				case 1:
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_3_p[13][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_two_3_p[3][playerid], "locksmithjob:lsui_cbdoor1");
					PlayerTextDrawShow(playerid, factory_job_two_3_p[3][playerid]);

					factory_job_mith_count[playerid]++;
					update_count_mith_progress(playerid);
					
					if(factory_job_mith_count[playerid] >= 7)
						return change_work_factory_click_mith(playerid);

				}
				case 2:
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_3_p[11][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_two_3_p[4][playerid], "locksmithjob:lsui_cbdoor2");
					PlayerTextDrawShow(playerid, factory_job_two_3_p[4][playerid]);

					factory_job_mith_count[playerid]++;
					update_count_mith_progress(playerid);
					
					if(factory_job_mith_count[playerid] >= 7)
						return change_work_factory_click_mith(playerid);

				}
				case 3:
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_3_p[14][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_two_3_p[5][playerid], "locksmithjob:lsui_cbdoor3");
					PlayerTextDrawShow(playerid, factory_job_two_3_p[5][playerid]);

					factory_job_mith_count[playerid]++;
					update_count_mith_progress(playerid);
					
					if(factory_job_mith_count[playerid] >= 7)
						return change_work_factory_click_mith(playerid);

				}
				case 4:
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_3_p[10][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_two_3_p[6][playerid], "locksmithjob:lsui_cbdoor4");
					PlayerTextDrawShow(playerid, factory_job_two_3_p[6][playerid]);

					factory_job_mith_count[playerid]++;
					update_count_mith_progress(playerid);
					
					if(factory_job_mith_count[playerid] >= 7)
						return change_work_factory_click_mith(playerid);

				}
				case 5:
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_3_p[15][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_two_3_p[7][playerid], "locksmithjob:lsui_cbdoor5");
					PlayerTextDrawShow(playerid, factory_job_two_3_p[7][playerid]);

					factory_job_mith_count[playerid]++;
					update_count_mith_progress(playerid);
					
					if(factory_job_mith_count[playerid] >= 7)
						return change_work_factory_click_mith(playerid);

				}
				case 6:
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_3_p[12][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_two_3_p[8][playerid], "locksmithjob:lsui_cbdoor6");
					PlayerTextDrawShow(playerid, factory_job_two_3_p[8][playerid]);

					factory_job_mith_count[playerid]++;
					update_count_mith_progress(playerid);
					
					if(factory_job_mith_count[playerid] >= 7)
						return change_work_factory_click_mith(playerid);

				}
				case 7:
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_3_p[16][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_two_3_p[9][playerid], "locksmithjob:lsui_cbdoorlock");
					PlayerTextDrawShow(playerid, factory_job_two_3_p[9][playerid]);

					factory_job_mith_count[playerid]++;
					update_count_mith_progress(playerid);
					
					if(factory_job_mith_count[playerid] >= 7)
						return change_work_factory_click_mith(playerid);

				}
			}
		}
		case WORK_FACTORY_DOOR_2:
		{
			switch(textdraws)
			{
				case 1:
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_4_p[13][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_two_4_p[3][playerid], "locksmithjob:lsui_csdoor1");
					PlayerTextDrawShow(playerid, factory_job_two_4_p[3][playerid]);

					factory_job_mith_count[playerid]++;
					update_count_mith_progress(playerid);
					
					if(factory_job_mith_count[playerid] >= 7)
						return change_work_factory_click_mith(playerid);

				}
				case 2:
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_4_p[11][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_two_4_p[4][playerid], "locksmithjob:lsui_csdoor2");
					PlayerTextDrawShow(playerid, factory_job_two_4_p[4][playerid]);

					factory_job_mith_count[playerid]++;
					update_count_mith_progress(playerid);
					
					if(factory_job_mith_count[playerid] >= 7)
						return change_work_factory_click_mith(playerid);


				}
				case 3:
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_4_p[14][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_two_4_p[5][playerid], "locksmithjob:lsui_csdoor3");
					PlayerTextDrawShow(playerid, factory_job_two_4_p[5][playerid]);

					factory_job_mith_count[playerid]++;
					update_count_mith_progress(playerid);
					
					if(factory_job_mith_count[playerid] >= 7)
						return change_work_factory_click_mith(playerid);

				}
				case 4:
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_4_p[10][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_two_4_p[6][playerid], "locksmithjob:lsui_csdoor4");
					PlayerTextDrawShow(playerid, factory_job_two_4_p[6][playerid]);

					factory_job_mith_count[playerid]++;
					update_count_mith_progress(playerid);
					
					if(factory_job_mith_count[playerid] >= 7)
						return change_work_factory_click_mith(playerid);


				}
				case 5:
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_4_p[15][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_two_4_p[7][playerid], "locksmithjob:lsui_csdoor5");
					PlayerTextDrawShow(playerid, factory_job_two_4_p[7][playerid]);

					factory_job_mith_count[playerid]++;
					update_count_mith_progress(playerid);
					
					if(factory_job_mith_count[playerid] >= 7)
						return change_work_factory_click_mith(playerid);


				}
				case 6:
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_4_p[12][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_two_4_p[8][playerid], "locksmithjob:lsui_csdoor6");
					PlayerTextDrawShow(playerid, factory_job_two_4_p[8][playerid]);

					factory_job_mith_count[playerid]++;
					update_count_mith_progress(playerid);
					
					if(factory_job_mith_count[playerid] >= 7)
						return change_work_factory_click_mith(playerid);

				}
				case 7:
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_4_p[16][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_two_4_p[9][playerid], "locksmithjob:lsui_csdoorlock");
					PlayerTextDrawShow(playerid, factory_job_two_4_p[9][playerid]);

					factory_job_mith_count[playerid]++;
					update_count_mith_progress(playerid);
					
					if(factory_job_mith_count[playerid] >= 7)
						return change_work_factory_click_mith(playerid);

				}
			}
		}
		case WORK_FACTORY_CLOCK:
		{
			switch(textdraws)
			{
				case 1:
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_5_p[12][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_two_5_p[3][playerid], "locksmithjob:lsui_clock1");
					PlayerTextDrawShow(playerid, factory_job_two_5_p[3][playerid]);

					factory_job_mith_count[playerid]++;
					update_count_mith_progress(playerid);
					
					if(factory_job_mith_count[playerid] >= 6)
						return change_work_factory_click_mith(playerid);


				}
				case 2:
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_5_p[10][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_two_5_p[4][playerid], "locksmithjob:lsui_clock2");
					PlayerTextDrawShow(playerid, factory_job_two_5_p[4][playerid]);

					factory_job_mith_count[playerid]++;
					update_count_mith_progress(playerid);
					
					if(factory_job_mith_count[playerid] >= 6)
						return change_work_factory_click_mith(playerid);

				}
				case 3:
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_5_p[13][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_two_5_p[5][playerid], "locksmithjob:lsui_clock3");
					PlayerTextDrawShow(playerid, factory_job_two_5_p[5][playerid]);

					factory_job_mith_count[playerid]++;
					update_count_mith_progress(playerid);
					
					if(factory_job_mith_count[playerid] >= 6)
						return change_work_factory_click_mith(playerid);

				}
				case 4:
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_5_p[9][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_two_5_p[6][playerid], "locksmithjob:lsui_clock4");
					PlayerTextDrawShow(playerid, factory_job_two_5_p[6][playerid]);

					factory_job_mith_count[playerid]++;
					update_count_mith_progress(playerid);
					
					if(factory_job_mith_count[playerid] >= 6)
						return change_work_factory_click_mith(playerid);

				}
				case 5:
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_5_p[14][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_two_5_p[7][playerid], "locksmithjob:lsui_clock5");
					PlayerTextDrawShow(playerid, factory_job_two_5_p[7][playerid]);

					factory_job_mith_count[playerid]++;
					update_count_mith_progress(playerid);
					
					if(factory_job_mith_count[playerid] >= 6)
						return change_work_factory_click_mith(playerid);

				}
				case 6:
				{
					PlayerTextDrawHideEx(playerid, factory_job_two_5_p[11][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_two_5_p[8][playerid], "locksmithjob:lsui_clock6");
					PlayerTextDrawShow(playerid, factory_job_two_5_p[8][playerid]);

					factory_job_mith_count[playerid]++;
					update_count_mith_progress(playerid);
					
					if(factory_job_mith_count[playerid] >= 6)
						return change_work_factory_click_mith(playerid);

				}
			}
		}
	}



	return true;
}