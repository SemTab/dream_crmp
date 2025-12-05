


CMD:test_factory(playerid)
{
	change_work_factory_click(playerid);
	return generate_work_factory_furniture(playerid);
}

stock generate_work_factory_furniture(playerid)
{
	new 
		random_work_factory = RandomEx(1, 8);

	SetPVarIntNew(playerid, "factory_type_furniture", random_work_factory);

	SetPVarIntNew(playerid, "factory_furniture_active_td", 1);

	TextDrawShowForPlayer(playerid, factory_job_1[0]);
	TextDrawShowForPlayer(playerid, factory_job_1[1]);

	factory_job_furniture_count[playerid] = 0;

	hide_hud_element(playerid);

	switch(random_work_factory)
	{
		case WORK_FACTORY_SOFA:
		{
			TogglePlayerControllable(playerid, false);
			SelectTextDraw(playerid, COLOR_BLUE);

			create_factory_job_1_p(playerid);

			//9-14 кликабельныен

			PlayerTextDrawSetString(playerid, factory_job_1_p[3][playerid], "furniturejob:fjui_gsofa1");
			PlayerTextDrawSetString(playerid, factory_job_1_p[4][playerid], "furniturejob:fjui_gsofa2");
			PlayerTextDrawSetString(playerid, factory_job_1_p[5][playerid], "furniturejob:fjui_gsofa3");
			PlayerTextDrawSetString(playerid, factory_job_1_p[6][playerid], "furniturejob:fjui_gsofa4");
			PlayerTextDrawSetString(playerid, factory_job_1_p[7][playerid], "furniturejob:fjui_gsofa5");
			PlayerTextDrawSetString(playerid, factory_job_1_p[8][playerid], "furniturejob:fjui_gsofa6");

			PlayerTextDrawSetString(playerid, factory_job_1_p[9][playerid], "furniturejob:fjui_csofa4");
			PlayerTextDrawSetString(playerid, factory_job_1_p[10][playerid], "furniturejob:fjui_csofa2");
			PlayerTextDrawSetString(playerid, factory_job_1_p[11][playerid], "furniturejob:fjui_csofa6");
			PlayerTextDrawSetString(playerid, factory_job_1_p[12][playerid], "furniturejob:fjui_csofa1");
			PlayerTextDrawSetString(playerid, factory_job_1_p[13][playerid], "furniturejob:fjui_csofa3");
			PlayerTextDrawSetString(playerid, factory_job_1_p[14][playerid], "furniturejob:fjui_csofa5");

			PlayerTextDrawShow(playerid, factory_job_1_p[0][playerid]);

			PlayerTextDrawShow(playerid, factory_job_1_p[2][playerid]);

			PlayerTextDrawShow(playerid, factory_job_1_p[3][playerid]);
			PlayerTextDrawShow(playerid, factory_job_1_p[4][playerid]);
			PlayerTextDrawShow(playerid, factory_job_1_p[5][playerid]);
			PlayerTextDrawShow(playerid, factory_job_1_p[6][playerid]);
			PlayerTextDrawShow(playerid, factory_job_1_p[7][playerid]);
			PlayerTextDrawShow(playerid, factory_job_1_p[8][playerid]);
			PlayerTextDrawShow(playerid, factory_job_1_p[9][playerid]);
			PlayerTextDrawShow(playerid, factory_job_1_p[10][playerid]);
			PlayerTextDrawShow(playerid, factory_job_1_p[11][playerid]);
			PlayerTextDrawShow(playerid, factory_job_1_p[12][playerid]);
			PlayerTextDrawShow(playerid, factory_job_1_p[13][playerid]);
			PlayerTextDrawShow(playerid, factory_job_1_p[14][playerid]);
			PlayerTextDrawShow(playerid, factory_job_1_p[15][playerid]);

		}
		case WORK_FACTORY_CHAIR:
		{
			TogglePlayerControllable(playerid, false);
			SelectTextDraw(playerid, COLOR_BLUE);

			create_factory_job_2_p(playerid);

			PlayerTextDrawSetString(playerid, factory_job_2_p[3][playerid], "furniturejob:fjui_gbed1");
			PlayerTextDrawSetString(playerid, factory_job_2_p[4][playerid], "furniturejob:fjui_gbed2");
			PlayerTextDrawSetString(playerid, factory_job_2_p[5][playerid], "furniturejob:fjui_gbed3");
			PlayerTextDrawSetString(playerid, factory_job_2_p[6][playerid], "furniturejob:fjui_gbed4");
			PlayerTextDrawSetString(playerid, factory_job_2_p[7][playerid], "furniturejob:fjui_gbed5");
			PlayerTextDrawSetString(playerid, factory_job_2_p[8][playerid], "furniturejob:fjui_gbed6");

			PlayerTextDrawSetString(playerid, factory_job_2_p[9][playerid], "furniturejob:fjui_cbed4");
			PlayerTextDrawSetString(playerid, factory_job_2_p[10][playerid], "furniturejob:fjui_cbed2");
			PlayerTextDrawSetString(playerid, factory_job_2_p[11][playerid], "furniturejob:fjui_cbed6");
			PlayerTextDrawSetString(playerid, factory_job_2_p[12][playerid], "furniturejob:fjui_cbed1");
			PlayerTextDrawSetString(playerid, factory_job_2_p[13][playerid], "furniturejob:fjui_cbed3");
			PlayerTextDrawSetString(playerid, factory_job_2_p[14][playerid], "furniturejob:fjui_cbed5");

			PlayerTextDrawShow(playerid, factory_job_2_p[0][playerid]);

			PlayerTextDrawShow(playerid, factory_job_2_p[2][playerid]);

			PlayerTextDrawShow(playerid, factory_job_2_p[3][playerid]);
			PlayerTextDrawShow(playerid, factory_job_2_p[4][playerid]);
			PlayerTextDrawShow(playerid, factory_job_2_p[5][playerid]);
			PlayerTextDrawShow(playerid, factory_job_2_p[6][playerid]);
			PlayerTextDrawShow(playerid, factory_job_2_p[7][playerid]);
			PlayerTextDrawShow(playerid, factory_job_2_p[8][playerid]);
			PlayerTextDrawShow(playerid, factory_job_2_p[9][playerid]);
			PlayerTextDrawShow(playerid, factory_job_2_p[10][playerid]);
			PlayerTextDrawShow(playerid, factory_job_2_p[11][playerid]);
			PlayerTextDrawShow(playerid, factory_job_2_p[12][playerid]);
			PlayerTextDrawShow(playerid, factory_job_2_p[13][playerid]);
			PlayerTextDrawShow(playerid, factory_job_2_p[14][playerid]);
			PlayerTextDrawShow(playerid, factory_job_2_p[15][playerid]);

		}
		case WORK_FACTORY_BED:
		{
			TogglePlayerControllable(playerid, false);
			SelectTextDraw(playerid, COLOR_BLUE);

			create_factory_job_3_p(playerid);


			PlayerTextDrawSetString(playerid, factory_job_3_p[3][playerid], "furniturejob:fjui_gtable1");
			PlayerTextDrawSetString(playerid, factory_job_3_p[4][playerid], "furniturejob:fjui_gtable2");
			PlayerTextDrawSetString(playerid, factory_job_3_p[5][playerid], "furniturejob:fjui_gtable3");
			PlayerTextDrawSetString(playerid, factory_job_3_p[6][playerid], "furniturejob:fjui_gtable4");
			PlayerTextDrawSetString(playerid, factory_job_3_p[7][playerid], "furniturejob:fjui_gtable5");
			PlayerTextDrawSetString(playerid, factory_job_3_p[8][playerid], "furniturejob:fjui_gtable6");

			PlayerTextDrawSetString(playerid, factory_job_3_p[9][playerid], "furniturejob:fjui_ctable4");
			PlayerTextDrawSetString(playerid, factory_job_3_p[10][playerid], "furniturejob:fjui_ctable2");
			PlayerTextDrawSetString(playerid, factory_job_3_p[11][playerid], "furniturejob:fjui_ctable6");
			PlayerTextDrawSetString(playerid, factory_job_3_p[12][playerid], "furniturejob:fjui_ctable1");
			PlayerTextDrawSetString(playerid, factory_job_3_p[13][playerid], "furniturejob:fjui_ctable3");
			PlayerTextDrawSetString(playerid, factory_job_3_p[14][playerid], "furniturejob:fjui_ctable5");

			PlayerTextDrawShow(playerid, factory_job_3_p[0][playerid]);

			PlayerTextDrawShow(playerid, factory_job_3_p[2][playerid]);

			PlayerTextDrawShow(playerid, factory_job_3_p[3][playerid]);
			PlayerTextDrawShow(playerid, factory_job_3_p[4][playerid]);
			PlayerTextDrawShow(playerid, factory_job_3_p[5][playerid]);
			PlayerTextDrawShow(playerid, factory_job_3_p[6][playerid]);
			PlayerTextDrawShow(playerid, factory_job_3_p[7][playerid]);
			PlayerTextDrawShow(playerid, factory_job_3_p[8][playerid]);
			PlayerTextDrawShow(playerid, factory_job_3_p[9][playerid]);
			PlayerTextDrawShow(playerid, factory_job_3_p[10][playerid]);
			PlayerTextDrawShow(playerid, factory_job_3_p[11][playerid]);
			PlayerTextDrawShow(playerid, factory_job_3_p[12][playerid]);
			PlayerTextDrawShow(playerid, factory_job_3_p[13][playerid]);
			PlayerTextDrawShow(playerid, factory_job_3_p[14][playerid]);
			PlayerTextDrawShow(playerid, factory_job_3_p[15][playerid]);

		}
		case WORK_FACTORY_FRAME:
		{
			TogglePlayerControllable(playerid, false);
			SelectTextDraw(playerid, COLOR_BLUE);

			create_factory_job_4_p(playerid);

			PlayerTextDrawSetString(playerid, factory_job_4_p[3][playerid], "furniturejob:fjui_gnightstand1");
			PlayerTextDrawSetString(playerid, factory_job_4_p[4][playerid], "furniturejob:fjui_gnightstand2");
			PlayerTextDrawSetString(playerid, factory_job_4_p[5][playerid], "furniturejob:fjui_gnightstand3");
			PlayerTextDrawSetString(playerid, factory_job_4_p[6][playerid], "furniturejob:fjui_gnightstand4");
			PlayerTextDrawSetString(playerid, factory_job_4_p[7][playerid], "furniturejob:fjui_gnightstand5");
			PlayerTextDrawSetString(playerid, factory_job_4_p[8][playerid], "furniturejob:fjui_gnightstand6");

			PlayerTextDrawSetString(playerid, factory_job_4_p[9][playerid], "furniturejob:fjui_cnightstand4");
			PlayerTextDrawSetString(playerid, factory_job_4_p[10][playerid], "furniturejob:fjui_cnightstand2");
			PlayerTextDrawSetString(playerid, factory_job_4_p[11][playerid], "furniturejob:fjui_cnightstand6");
			PlayerTextDrawSetString(playerid, factory_job_4_p[12][playerid], "furniturejob:fjui_cnightstand1");
			PlayerTextDrawSetString(playerid, factory_job_4_p[13][playerid], "furniturejob:fjui_cnightstand3");
			PlayerTextDrawSetString(playerid, factory_job_4_p[14][playerid], "furniturejob:fjui_cnightstand5");

			PlayerTextDrawShow(playerid, factory_job_4_p[0][playerid]);

			PlayerTextDrawShow(playerid, factory_job_4_p[2][playerid]);

			PlayerTextDrawShow(playerid, factory_job_4_p[3][playerid]);
			PlayerTextDrawShow(playerid, factory_job_4_p[4][playerid]);
			PlayerTextDrawShow(playerid, factory_job_4_p[5][playerid]);
			PlayerTextDrawShow(playerid, factory_job_4_p[6][playerid]);
			PlayerTextDrawShow(playerid, factory_job_4_p[7][playerid]);
			PlayerTextDrawShow(playerid, factory_job_4_p[8][playerid]);
			PlayerTextDrawShow(playerid, factory_job_4_p[9][playerid]);
			PlayerTextDrawShow(playerid, factory_job_4_p[10][playerid]);
			PlayerTextDrawShow(playerid, factory_job_4_p[11][playerid]);
			PlayerTextDrawShow(playerid, factory_job_4_p[12][playerid]);
			PlayerTextDrawShow(playerid, factory_job_4_p[13][playerid]);
			PlayerTextDrawShow(playerid, factory_job_4_p[14][playerid]);
			PlayerTextDrawShow(playerid, factory_job_4_p[15][playerid]);

		}
		case WORK_FACTORY_CRACK:
		{
			TogglePlayerControllable(playerid, false);
			SelectTextDraw(playerid, COLOR_BLUE);

			create_factory_job_5_p(playerid);

			PlayerTextDrawSetString(playerid, factory_job_5_p[3][playerid], "furniturejob:fjui_gwframe1");
			PlayerTextDrawSetString(playerid, factory_job_5_p[4][playerid], "furniturejob:fjui_gwframe2");
			PlayerTextDrawSetString(playerid, factory_job_5_p[5][playerid], "furniturejob:fjui_gwframe3");
			PlayerTextDrawSetString(playerid, factory_job_5_p[6][playerid], "furniturejob:fjui_gwframe4");
			PlayerTextDrawSetString(playerid, factory_job_5_p[7][playerid], "furniturejob:fjui_gwframe5");
			PlayerTextDrawSetString(playerid, factory_job_5_p[8][playerid], "furniturejob:fjui_gwframe6");

			PlayerTextDrawSetString(playerid, factory_job_5_p[9][playerid], "furniturejob:fjui_cwframe4");
			PlayerTextDrawSetString(playerid, factory_job_5_p[10][playerid], "furniturejob:fjui_cwframe2");
			PlayerTextDrawSetString(playerid, factory_job_5_p[11][playerid], "furniturejob:fjui_cwframe6");
			PlayerTextDrawSetString(playerid, factory_job_5_p[12][playerid], "furniturejob:fjui_cwframe1");
			PlayerTextDrawSetString(playerid, factory_job_5_p[13][playerid], "furniturejob:fjui_cwframe3");
			PlayerTextDrawSetString(playerid, factory_job_5_p[14][playerid], "furniturejob:fjui_cwframe5");

			PlayerTextDrawShow(playerid, factory_job_5_p[0][playerid]);

			PlayerTextDrawShow(playerid, factory_job_5_p[2][playerid]);


			PlayerTextDrawShow(playerid, factory_job_5_p[3][playerid]);
			PlayerTextDrawShow(playerid, factory_job_5_p[4][playerid]);
			PlayerTextDrawShow(playerid, factory_job_5_p[5][playerid]);
			PlayerTextDrawShow(playerid, factory_job_5_p[6][playerid]);
			PlayerTextDrawShow(playerid, factory_job_5_p[7][playerid]);
			PlayerTextDrawShow(playerid, factory_job_5_p[8][playerid]);
			PlayerTextDrawShow(playerid, factory_job_5_p[9][playerid]);
			PlayerTextDrawShow(playerid, factory_job_5_p[10][playerid]);
			PlayerTextDrawShow(playerid, factory_job_5_p[11][playerid]);
			PlayerTextDrawShow(playerid, factory_job_5_p[12][playerid]);
			PlayerTextDrawShow(playerid, factory_job_5_p[13][playerid]);
			PlayerTextDrawShow(playerid, factory_job_5_p[14][playerid]);
			PlayerTextDrawShow(playerid, factory_job_5_p[15][playerid]);

		}
		case WORK_FACTORY_TABLE:
		{
			TogglePlayerControllable(playerid, false);
			SelectTextDraw(playerid, COLOR_BLUE);

			create_factory_job_6_p(playerid);

			PlayerTextDrawSetString(playerid, factory_job_6_p[3][playerid], "furniturejob:fjui_gachair1");
			PlayerTextDrawSetString(playerid, factory_job_6_p[4][playerid], "furniturejob:fjui_gachair2");
			PlayerTextDrawSetString(playerid, factory_job_6_p[5][playerid], "furniturejob:fjui_gachair3");
			PlayerTextDrawSetString(playerid, factory_job_6_p[6][playerid], "furniturejob:fjui_gachair4");
			PlayerTextDrawSetString(playerid, factory_job_6_p[7][playerid], "furniturejob:fjui_gachair5");
			PlayerTextDrawSetString(playerid, factory_job_6_p[8][playerid], "furniturejob:fjui_gachair6");

			PlayerTextDrawSetString(playerid, factory_job_6_p[9][playerid], "furniturejob:fjui_cachair4");
			PlayerTextDrawSetString(playerid, factory_job_6_p[10][playerid], "furniturejob:fjui_cachair2");
			PlayerTextDrawSetString(playerid, factory_job_6_p[11][playerid], "furniturejob:fjui_cachair6");
			PlayerTextDrawSetString(playerid, factory_job_6_p[12][playerid], "furniturejob:fjui_cachair1");
			PlayerTextDrawSetString(playerid, factory_job_6_p[13][playerid], "furniturejob:fjui_cachair3");
			PlayerTextDrawSetString(playerid, factory_job_6_p[14][playerid], "furniturejob:fjui_cachair5");

			PlayerTextDrawShow(playerid, factory_job_6_p[0][playerid]);
			
			PlayerTextDrawShow(playerid, factory_job_6_p[2][playerid]);

			PlayerTextDrawShow(playerid, factory_job_6_p[3][playerid]);
			PlayerTextDrawShow(playerid, factory_job_6_p[4][playerid]);
			PlayerTextDrawShow(playerid, factory_job_6_p[5][playerid]);
			PlayerTextDrawShow(playerid, factory_job_6_p[6][playerid]);
			PlayerTextDrawShow(playerid, factory_job_6_p[7][playerid]);
			PlayerTextDrawShow(playerid, factory_job_6_p[8][playerid]);
			PlayerTextDrawShow(playerid, factory_job_6_p[9][playerid]);
			PlayerTextDrawShow(playerid, factory_job_6_p[10][playerid]);
			PlayerTextDrawShow(playerid, factory_job_6_p[11][playerid]);
			PlayerTextDrawShow(playerid, factory_job_6_p[12][playerid]);
			PlayerTextDrawShow(playerid, factory_job_6_p[13][playerid]);
			PlayerTextDrawShow(playerid, factory_job_6_p[14][playerid]);
			PlayerTextDrawShow(playerid, factory_job_6_p[15][playerid]);

		}
		case WORK_FACTORY_CHAIR_2:
		{
			TogglePlayerControllable(playerid, false);
			SelectTextDraw(playerid, COLOR_BLUE);

			create_factory_job_7_p(playerid);

			PlayerTextDrawSetString(playerid, factory_job_7_p[3][playerid], "furniturejob:fjui_grack1");
			PlayerTextDrawSetString(playerid, factory_job_7_p[4][playerid], "furniturejob:fjui_grack2");
			PlayerTextDrawSetString(playerid, factory_job_7_p[5][playerid], "furniturejob:fjui_grack3");
			PlayerTextDrawSetString(playerid, factory_job_7_p[6][playerid], "furniturejob:fjui_grack4");
			PlayerTextDrawSetString(playerid, factory_job_7_p[7][playerid], "furniturejob:fjui_grack5");
			PlayerTextDrawSetString(playerid, factory_job_7_p[8][playerid], "furniturejob:fjui_grack6");

			PlayerTextDrawSetString(playerid, factory_job_7_p[9][playerid], "furniturejob:fjui_crack4");
			PlayerTextDrawSetString(playerid, factory_job_7_p[10][playerid], "furniturejob:fjui_crack2");
			PlayerTextDrawSetString(playerid, factory_job_7_p[11][playerid], "furniturejob:fjui_crack6");
			PlayerTextDrawSetString(playerid, factory_job_7_p[12][playerid], "furniturejob:fjui_crack1");
			PlayerTextDrawSetString(playerid, factory_job_7_p[13][playerid], "furniturejob:fjui_crack3");
			PlayerTextDrawSetString(playerid, factory_job_7_p[14][playerid], "furniturejob:fjui_crack5");

			PlayerTextDrawShow(playerid, factory_job_7_p[0][playerid]);

			PlayerTextDrawShow(playerid, factory_job_7_p[2][playerid]);

			PlayerTextDrawShow(playerid, factory_job_7_p[3][playerid]);
			PlayerTextDrawShow(playerid, factory_job_7_p[4][playerid]);
			PlayerTextDrawShow(playerid, factory_job_7_p[5][playerid]);
			PlayerTextDrawShow(playerid, factory_job_7_p[6][playerid]);
			PlayerTextDrawShow(playerid, factory_job_7_p[7][playerid]);
			PlayerTextDrawShow(playerid, factory_job_7_p[8][playerid]);
			PlayerTextDrawShow(playerid, factory_job_7_p[9][playerid]);
			PlayerTextDrawShow(playerid, factory_job_7_p[10][playerid]);
			PlayerTextDrawShow(playerid, factory_job_7_p[11][playerid]);
			PlayerTextDrawShow(playerid, factory_job_7_p[12][playerid]);
			PlayerTextDrawShow(playerid, factory_job_7_p[13][playerid]);
			PlayerTextDrawShow(playerid, factory_job_7_p[14][playerid]);
			PlayerTextDrawShow(playerid, factory_job_7_p[15][playerid]);

		}
		case WORK_FACTORY_STAND:
		{
			TogglePlayerControllable(playerid, false);
			SelectTextDraw(playerid, COLOR_BLUE);

			create_factory_job_8_p(playerid);

			PlayerTextDrawSetString(playerid, factory_job_8_p[3][playerid], "furniturejob:fjui_gcupboard1");
			PlayerTextDrawSetString(playerid, factory_job_8_p[4][playerid], "furniturejob:fjui_gcupboard2");
			PlayerTextDrawSetString(playerid, factory_job_8_p[5][playerid], "furniturejob:fjui_gcupboard3");
			PlayerTextDrawSetString(playerid, factory_job_8_p[6][playerid], "furniturejob:fjui_gcupboard4");
			PlayerTextDrawSetString(playerid, factory_job_8_p[7][playerid], "furniturejob:fjui_gcupboard5");
			PlayerTextDrawSetString(playerid, factory_job_8_p[8][playerid], "furniturejob:fjui_gcupboard6");

			PlayerTextDrawSetString(playerid, factory_job_8_p[9][playerid], "furniturejob:fjui_ccupboard4");
			PlayerTextDrawSetString(playerid, factory_job_8_p[10][playerid], "furniturejob:fjui_ccupboard2");
			PlayerTextDrawSetString(playerid, factory_job_8_p[11][playerid], "furniturejob:fjui_ccupboard6");
			PlayerTextDrawSetString(playerid, factory_job_8_p[12][playerid], "furniturejob:fjui_ccupboard1");
			PlayerTextDrawSetString(playerid, factory_job_8_p[13][playerid], "furniturejob:fjui_ccupboard3");
			PlayerTextDrawSetString(playerid, factory_job_8_p[14][playerid], "furniturejob:fjui_ccupboard5");

			PlayerTextDrawShow(playerid, factory_job_8_p[0][playerid]);

			PlayerTextDrawShow(playerid, factory_job_8_p[2][playerid]);

			PlayerTextDrawShow(playerid, factory_job_8_p[3][playerid]);
			PlayerTextDrawShow(playerid, factory_job_8_p[4][playerid]);
			PlayerTextDrawShow(playerid, factory_job_8_p[5][playerid]);
			PlayerTextDrawShow(playerid, factory_job_8_p[6][playerid]);
			PlayerTextDrawShow(playerid, factory_job_8_p[7][playerid]);
			PlayerTextDrawShow(playerid, factory_job_8_p[8][playerid]);
			PlayerTextDrawShow(playerid, factory_job_8_p[9][playerid]);
			PlayerTextDrawShow(playerid, factory_job_8_p[10][playerid]);
			PlayerTextDrawShow(playerid, factory_job_8_p[11][playerid]);
			PlayerTextDrawShow(playerid, factory_job_8_p[12][playerid]);
			PlayerTextDrawShow(playerid, factory_job_8_p[13][playerid]);
			PlayerTextDrawShow(playerid, factory_job_8_p[14][playerid]);
			PlayerTextDrawShow(playerid, factory_job_8_p[15][playerid]);

		}
		case WORK_FACTORY_BOARD:
		{
			TogglePlayerControllable(playerid, false);
			SelectTextDraw(playerid, COLOR_BLUE);

			create_factory_job_9_p(playerid);


			PlayerTextDrawSetString(playerid, factory_job_9_p[3][playerid], "furniturejob:fjui_gchair1");
			PlayerTextDrawSetString(playerid, factory_job_9_p[4][playerid], "furniturejob:fjui_gchair2");
			PlayerTextDrawSetString(playerid, factory_job_9_p[5][playerid], "furniturejob:fjui_gchair3");
			PlayerTextDrawSetString(playerid, factory_job_9_p[6][playerid], "furniturejob:fjui_gchair4");
			PlayerTextDrawSetString(playerid, factory_job_9_p[7][playerid], "furniturejob:fjui_gchair5");
			PlayerTextDrawSetString(playerid, factory_job_9_p[8][playerid], "furniturejob:fjui_gchair6");

			PlayerTextDrawSetString(playerid, factory_job_9_p[9][playerid], "furniturejob:fjui_cchair4");
			PlayerTextDrawSetString(playerid, factory_job_9_p[10][playerid], "furniturejob:fjui_cchair2");
			PlayerTextDrawSetString(playerid, factory_job_9_p[11][playerid], "furniturejob:fjui_cchair6");
			PlayerTextDrawSetString(playerid, factory_job_9_p[12][playerid], "furniturejob:fjui_cchair1");
			PlayerTextDrawSetString(playerid, factory_job_9_p[13][playerid], "furniturejob:fjui_cchair3");
			PlayerTextDrawSetString(playerid, factory_job_9_p[14][playerid], "furniturejob:fjui_cchair5");

			PlayerTextDrawShow(playerid, factory_job_9_p[0][playerid]);

			PlayerTextDrawShow(playerid, factory_job_9_p[2][playerid]);

			PlayerTextDrawShow(playerid, factory_job_9_p[3][playerid]);
			PlayerTextDrawShow(playerid, factory_job_9_p[4][playerid]);
			PlayerTextDrawShow(playerid, factory_job_9_p[5][playerid]);
			PlayerTextDrawShow(playerid, factory_job_9_p[6][playerid]);
			PlayerTextDrawShow(playerid, factory_job_9_p[7][playerid]);
			PlayerTextDrawShow(playerid, factory_job_9_p[8][playerid]);
			PlayerTextDrawShow(playerid, factory_job_9_p[9][playerid]);
			PlayerTextDrawShow(playerid, factory_job_9_p[10][playerid]);
			PlayerTextDrawShow(playerid, factory_job_9_p[11][playerid]);
			PlayerTextDrawShow(playerid, factory_job_9_p[12][playerid]);
			PlayerTextDrawShow(playerid, factory_job_9_p[13][playerid]);
			PlayerTextDrawShow(playerid, factory_job_9_p[14][playerid]);
			PlayerTextDrawShow(playerid, factory_job_9_p[15][playerid]);

		}
	}

	TogglePlayerAllHudElements(playerid, HUD_ELEMENT_HIDE);
	return true;
}

stock hide_work_factory_click(playerid)
{
	new 
		type_work_factory = GetPVarIntNew(playerid, "factory_type_furniture");

	TextDrawHideForPlayer(playerid, factory_job_1[0]);
	TextDrawHideForPlayer(playerid, factory_job_1[1]);

	DeletePVarNew(playerid, "active_sklad_factory");
	
	DisablePlayerCheckpoint(playerid);
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);

	factory_job_furniture_count[playerid] = 0;

	switch(type_work_factory)
	{
		case WORK_FACTORY_SOFA:
		{
			for(new i = 0; i < 16; i++)
			{
				if(factory_job_1_p[i][playerid] != PlayerText:INVALID_TEXT_DRAW)
				{
					PlayerTextDrawHideEx(playerid, factory_job_1_p[i][playerid]);
				}
			}
		}
		case WORK_FACTORY_CHAIR:
		{
			for(new i = 0; i < 16; i++)
			{
				if(factory_job_2_p[i][playerid] != PlayerText:INVALID_TEXT_DRAW)
				{
					PlayerTextDrawHideEx(playerid, factory_job_2_p[i][playerid]);
				}
			}
		}
		case WORK_FACTORY_BED:
		{
			for(new i = 0; i < 16; i++)
			{
				if(factory_job_3_p[i][playerid] != PlayerText:INVALID_TEXT_DRAW)
				{
					PlayerTextDrawHideEx(playerid, factory_job_3_p[i][playerid]);
				}
			}
		}
		case WORK_FACTORY_FRAME:
		{
			for(new i = 0; i < 16; i++)
			{
				if(factory_job_4_p[i][playerid] != PlayerText:INVALID_TEXT_DRAW)
				{
					PlayerTextDrawHideEx(playerid, factory_job_4_p[i][playerid]);
				}
			}
		}
		case WORK_FACTORY_CRACK:
		{
			for(new i = 0; i < 16; i++)
			{
				if(factory_job_5_p[i][playerid] != PlayerText:INVALID_TEXT_DRAW)
				{
					PlayerTextDrawHideEx(playerid, factory_job_5_p[i][playerid]);
				}
			}
		}
		case WORK_FACTORY_TABLE:
		{
			for(new i = 0; i < 16; i++)
			{
				if(factory_job_6_p[i][playerid] != PlayerText:INVALID_TEXT_DRAW)
				{
					PlayerTextDrawHideEx(playerid, factory_job_6_p[i][playerid]);
				}
			}
		}
		case WORK_FACTORY_CHAIR_2:
		{
			for(new i = 0; i < 16; i++)
			{
				if(factory_job_7_p[i][playerid] != PlayerText:INVALID_TEXT_DRAW)
				{
					PlayerTextDrawHideEx(playerid, factory_job_7_p[i][playerid]);
				}
			}
		}
		case WORK_FACTORY_STAND:
		{
			for(new i = 0; i < 16; i++)
			{
				if(factory_job_8_p[i][playerid] != PlayerText:INVALID_TEXT_DRAW)
				{
					PlayerTextDrawHideEx(playerid, factory_job_8_p[i][playerid]);
				}
			}
		}
		case WORK_FACTORY_BOARD:
		{
			for(new i = 0; i < 16; i++)
			{
				if(factory_job_9_p[i][playerid] != PlayerText:INVALID_TEXT_DRAW)
				{
					PlayerTextDrawHideEx(playerid, factory_job_9_p[i][playerid]);
				}
			}
		}
	}
	TogglePlayerAllHudElements(playerid, HUD_ELEMENT_SHOW);
	show_hud_element(playerid);
	show_hud_hungry(playerid);
	TogglePlayerControllable(playerid, true);
	CancelSelectTextDraw(playerid);
	DeletePVarNew(playerid, "factory_type_furniture");
	DeletePVarNew(playerid, "factory_furniture_active_td");
	return true;
}


stock change_work_factory_click(playerid)
{
	new 
		type_work_factory = GetPVarIntNew(playerid, "factory_type_furniture");

	show_hud_element(playerid);
	show_hud_hungry(playerid);
	TextDrawHideForPlayer(playerid, factory_job_1[0]);
	TextDrawHideForPlayer(playerid, factory_job_1[1]);

	switch(type_work_factory)
	{
		case WORK_FACTORY_SOFA:
		{
			for(new i = 0; i < 16; i++)
			{
				if(factory_job_1_p[i][playerid] != PlayerText:INVALID_TEXT_DRAW)
				{
					PlayerTextDrawHideEx(playerid, factory_job_1_p[i][playerid]);
				}
			}
			give_furniture_items_factory(playerid);
		}
		case WORK_FACTORY_CHAIR:
		{
			for(new i = 0; i < 16; i++)
			{
				if(factory_job_2_p[i][playerid] != PlayerText:INVALID_TEXT_DRAW)
				{
					PlayerTextDrawHideEx(playerid, factory_job_2_p[i][playerid]);
				}
			}
			give_furniture_items_factory(playerid);
		}
		case WORK_FACTORY_BED:
		{
			for(new i = 0; i < 16; i++)
			{
				if(factory_job_3_p[i][playerid] != PlayerText:INVALID_TEXT_DRAW)
				{
					PlayerTextDrawHideEx(playerid, factory_job_3_p[i][playerid]);
				}
			}
			give_furniture_items_factory(playerid);
		}
		case WORK_FACTORY_FRAME:
		{
			for(new i = 0; i < 16; i++)
			{
				if(factory_job_4_p[i][playerid] != PlayerText:INVALID_TEXT_DRAW)
				{
					PlayerTextDrawHideEx(playerid, factory_job_4_p[i][playerid]);
				}
			}
			give_furniture_items_factory(playerid);
		}
		case WORK_FACTORY_CRACK:
		{
			for(new i = 0; i < 16; i++)
			{
				if(factory_job_5_p[i][playerid] != PlayerText:INVALID_TEXT_DRAW)
				{
					PlayerTextDrawHideEx(playerid, factory_job_5_p[i][playerid]);
				}
			}
			give_furniture_items_factory(playerid);
		}
		case WORK_FACTORY_TABLE:
		{
			for(new i = 0; i < 16; i++)
			{
				if(factory_job_6_p[i][playerid] != PlayerText:INVALID_TEXT_DRAW)
				{
					PlayerTextDrawHideEx(playerid, factory_job_6_p[i][playerid]);
				}
			}
			give_furniture_items_factory(playerid);
		}
		case WORK_FACTORY_CHAIR_2:
		{
			for(new i = 0; i < 16; i++)
			{
				if(factory_job_7_p[i][playerid] != PlayerText:INVALID_TEXT_DRAW)
				{
					PlayerTextDrawHideEx(playerid, factory_job_7_p[i][playerid]);
				}
			}
			give_furniture_items_factory(playerid);
		}
		case WORK_FACTORY_STAND:
		{


			for(new i = 0; i < 16; i++)
			{
				if(factory_job_8_p[i][playerid] != PlayerText:INVALID_TEXT_DRAW)
				{
					PlayerTextDrawHideEx(playerid, factory_job_8_p[i][playerid]);
				}
			}
			give_furniture_items_factory(playerid);
		}
		case WORK_FACTORY_BOARD:
		{
			for(new i = 0; i < 15; i++)
			{
				if(factory_job_9_p[i][playerid] != PlayerText:INVALID_TEXT_DRAW)
				{
					PlayerTextDrawHideEx(playerid, factory_job_9_p[i][playerid]);
				}
			}
			give_furniture_items_factory(playerid);
		}
	}

	return true;
}

stock give_furniture_items_factory(playerid, type = -1)
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

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:info_gui_zavod", 4000);

	SendInf(playerid, "Перенесите собранную мебель на склад!");
	SendInf(playerid, "Склад отмечен у Вас на мини-карте!");

	SetPlayerCheckpoint(playerid, 642.2382,1289.3558,1746.4340, WOOD_CHECKPOINT_SIZE);

	return true;
}

stock unload_factory_job_furniture(playerid)
{
	if(!GetPVarIntNew(playerid, "active_sklad_factory"))
		return SendInf(playerid, "Вы должны сперва сделать мебель!");

	factory_job_furniture_count[playerid] = 0;

	DeletePVarNew(playerid, "active_sklad_factory");

	add_player_job_skill(playerid, SKILL_FACTORY);
	DisablePlayerCheckpoint(playerid);

	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);

	sklad[2][sklad_other_count_1]++;
	update_sklad_3d_text();
	save_sklad_all();

	if(pData[playerid][pQuestNewYear][5] == 2)
	{
		SetPVarIntNew(playerid, "furnitute_count_diamond", GetPVarIntNew(playerid, "furnitute_count_diamond")+1);

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

	SetPVarIntNew(playerid, "miner_job_count", GetPVarIntNew(playerid, "miner_job_count")+2);

	check_quest_prize_start(playerid, 5);
	check_quest_prize_start(playerid, 6);
	check_quest_prize_start(playerid, 3);
	
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

	RemovePlayerAttachedObject(playerid, 2);

	return true;
}


stock work_factory_click_furniture(playerid, textdraws)
{

	new 
		type_work_factory = GetPVarIntNew(playerid, "factory_type_furniture");

	switch(type_work_factory)
	{
		case WORK_FACTORY_SOFA:
		{
			switch(textdraws)
			{
				case 1:
				{
					
					PlayerTextDrawHideEx(playerid, factory_job_1_p[12][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_1_p[3][playerid], "furniturejob:fjui_csofa1");
					PlayerTextDrawShow(playerid, factory_job_1_p[3][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 2:
				{
					PlayerTextDrawHideEx(playerid, factory_job_1_p[10][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_1_p[4][playerid], "furniturejob:fjui_csofa2");
					PlayerTextDrawShow(playerid, factory_job_1_p[4][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 3:
				{
					PlayerTextDrawHideEx(playerid, factory_job_1_p[13][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_1_p[5][playerid], "furniturejob:fjui_csofa3");
					PlayerTextDrawShow(playerid, factory_job_1_p[5][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 4:
				{
					PlayerTextDrawHideEx(playerid, factory_job_1_p[9][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_1_p[6][playerid], "furniturejob:fjui_csofa4");
					PlayerTextDrawShow(playerid, factory_job_1_p[6][playerid]);


					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 5:
				{
					PlayerTextDrawHideEx(playerid, factory_job_1_p[14][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_1_p[7][playerid], "furniturejob:fjui_csofa5");
					PlayerTextDrawShow(playerid, factory_job_1_p[7][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);


				}
				case 6:
				{
					PlayerTextDrawHideEx(playerid, factory_job_1_p[11][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_1_p[8][playerid], "furniturejob:fjui_csofa6");
					PlayerTextDrawShow(playerid, factory_job_1_p[8][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
			}
		}
		case WORK_FACTORY_CHAIR:
		{
			switch(textdraws)
			{
				case 1:
				{
					PlayerTextDrawHideEx(playerid, factory_job_2_p[12][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_2_p[3][playerid], "furniturejob:fjui_cbed1");
					PlayerTextDrawShow(playerid, factory_job_2_p[3][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 2:
				{
					PlayerTextDrawHideEx(playerid, factory_job_2_p[10][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_2_p[4][playerid], "furniturejob:fjui_cbed2");
					PlayerTextDrawShow(playerid, factory_job_2_p[4][playerid]);


					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 3:
				{
					PlayerTextDrawHideEx(playerid, factory_job_2_p[13][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_2_p[5][playerid], "furniturejob:fjui_cbed3");
					PlayerTextDrawShow(playerid, factory_job_2_p[5][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);


				}
				case 4:
				{
					PlayerTextDrawHideEx(playerid, factory_job_2_p[9][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_2_p[6][playerid], "furniturejob:fjui_cbed4");
					PlayerTextDrawShow(playerid, factory_job_2_p[6][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);


				}
				case 5:
				{
					PlayerTextDrawHideEx(playerid, factory_job_2_p[14][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_2_p[7][playerid], "furniturejob:fjui_cbed5");
					PlayerTextDrawShow(playerid, factory_job_2_p[7][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);


				}
				case 6:
				{
					PlayerTextDrawHideEx(playerid, factory_job_2_p[11][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_2_p[8][playerid], "furniturejob:fjui_cbed6");
					PlayerTextDrawShow(playerid, factory_job_2_p[8][playerid]);


					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
			}
		}
		case WORK_FACTORY_BED:
		{
			switch(textdraws)
			{
				case 1:
				{
					PlayerTextDrawHideEx(playerid, factory_job_3_p[12][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_3_p[3][playerid], "furniturejob:fjui_ctable1");
					PlayerTextDrawShow(playerid, factory_job_3_p[3][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 2:
				{
					PlayerTextDrawHideEx(playerid, factory_job_3_p[10][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_3_p[4][playerid], "furniturejob:fjui_ctable2");
					PlayerTextDrawShow(playerid, factory_job_3_p[4][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 3:
				{
					PlayerTextDrawHideEx(playerid, factory_job_3_p[13][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_3_p[5][playerid], "furniturejob:fjui_ctable3");
					PlayerTextDrawShow(playerid, factory_job_3_p[5][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 4:
				{
					PlayerTextDrawHideEx(playerid, factory_job_3_p[9][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_3_p[6][playerid], "furniturejob:fjui_ctable4");
					PlayerTextDrawShow(playerid, factory_job_3_p[6][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 5:
				{
					PlayerTextDrawHideEx(playerid, factory_job_3_p[14][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_3_p[7][playerid], "furniturejob:fjui_ctable5");
					PlayerTextDrawShow(playerid, factory_job_3_p[7][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 6:
				{
					PlayerTextDrawHideEx(playerid, factory_job_3_p[11][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_3_p[8][playerid], "furniturejob:fjui_ctable6");
					PlayerTextDrawShow(playerid, factory_job_3_p[8][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
			}
		}
		case WORK_FACTORY_FRAME:
		{
			switch(textdraws)
			{
				case 1:
				{
					PlayerTextDrawHideEx(playerid, factory_job_4_p[12][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_4_p[3][playerid], "furniturejob:fjui_cnightstand1");
					PlayerTextDrawShow(playerid, factory_job_4_p[3][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 2:
				{
					PlayerTextDrawHideEx(playerid, factory_job_4_p[10][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_4_p[4][playerid], "furniturejob:fjui_cnightstand2");
					PlayerTextDrawShow(playerid, factory_job_4_p[4][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);


				}
				case 3:
				{
					PlayerTextDrawHideEx(playerid, factory_job_4_p[13][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_4_p[5][playerid], "furniturejob:fjui_cnightstand3");
					PlayerTextDrawShow(playerid, factory_job_4_p[5][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 4:
				{
					PlayerTextDrawHideEx(playerid, factory_job_4_p[9][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_4_p[6][playerid], "furniturejob:fjui_cnightstand4");
					PlayerTextDrawShow(playerid, factory_job_4_p[6][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);


				}
				case 5:
				{
					PlayerTextDrawHideEx(playerid, factory_job_4_p[14][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_4_p[7][playerid], "furniturejob:fjui_cnightstand5");
					PlayerTextDrawShow(playerid, factory_job_4_p[7][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);


				}
				case 6:
				{
					PlayerTextDrawHideEx(playerid, factory_job_4_p[11][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_4_p[8][playerid], "furniturejob:fjui_cnightstand6");
					PlayerTextDrawShow(playerid, factory_job_4_p[8][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
			}
		}
		case WORK_FACTORY_CRACK:
		{
			switch(textdraws)
			{
				case 1:
				{
					PlayerTextDrawHideEx(playerid, factory_job_5_p[12][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_5_p[3][playerid], "furniturejob:fjui_cwframe1");
					PlayerTextDrawShow(playerid, factory_job_5_p[3][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);


				}
				case 2:
				{
					PlayerTextDrawHideEx(playerid, factory_job_5_p[10][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_5_p[4][playerid], "furniturejob:fjui_cwframe2");
					PlayerTextDrawShow(playerid, factory_job_5_p[4][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 3:
				{
					PlayerTextDrawHideEx(playerid, factory_job_5_p[13][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_5_p[5][playerid], "furniturejob:fjui_cwframe3");
					PlayerTextDrawShow(playerid, factory_job_5_p[5][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 4:
				{
					PlayerTextDrawHideEx(playerid, factory_job_5_p[9][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_5_p[6][playerid], "furniturejob:fjui_cwframe4");
					PlayerTextDrawShow(playerid, factory_job_5_p[6][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 5:
				{
					PlayerTextDrawHideEx(playerid, factory_job_5_p[14][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_5_p[7][playerid], "furniturejob:fjui_cwframe5");
					PlayerTextDrawShow(playerid, factory_job_5_p[7][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 6:
				{
					PlayerTextDrawHideEx(playerid, factory_job_5_p[11][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_5_p[8][playerid], "furniturejob:fjui_cwframe6");
					PlayerTextDrawShow(playerid, factory_job_5_p[8][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
			}
		}
		case WORK_FACTORY_TABLE:
		{
			switch(textdraws)
			{
				case 1:
				{
					PlayerTextDrawHideEx(playerid, factory_job_6_p[12][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_6_p[3][playerid], "furniturejob:fjui_cachair1");
					PlayerTextDrawShow(playerid, factory_job_6_p[3][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 2:
				{
					PlayerTextDrawHideEx(playerid, factory_job_6_p[10][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_6_p[4][playerid], "furniturejob:fjui_cachair2");
					PlayerTextDrawShow(playerid, factory_job_6_p[4][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 3:
				{
					PlayerTextDrawHideEx(playerid, factory_job_6_p[13][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_6_p[5][playerid], "furniturejob:fjui_cachair3");
					PlayerTextDrawShow(playerid, factory_job_6_p[5][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 4:
				{
					PlayerTextDrawHideEx(playerid, factory_job_6_p[9][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_6_p[6][playerid], "furniturejob:fjui_cachair4");
					PlayerTextDrawShow(playerid, factory_job_6_p[6][playerid]);


					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 5:
				{
					PlayerTextDrawHideEx(playerid, factory_job_6_p[14][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_6_p[7][playerid], "furniturejob:fjui_cachair5");
					PlayerTextDrawShow(playerid, factory_job_6_p[7][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);


				}
				case 6:
				{
					PlayerTextDrawHideEx(playerid, factory_job_6_p[11][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_6_p[8][playerid], "furniturejob:fjui_cachair6");
					PlayerTextDrawShow(playerid, factory_job_6_p[8][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);


				}
			}
		}
		case WORK_FACTORY_CHAIR_2:
		{
			switch(textdraws)
			{
				case 1:
				{
					PlayerTextDrawHideEx(playerid, factory_job_7_p[12][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_7_p[3][playerid], "furniturejob:fjui_crack1");
					PlayerTextDrawShow(playerid, factory_job_7_p[3][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 2:
				{
					PlayerTextDrawHideEx(playerid, factory_job_7_p[10][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_7_p[4][playerid], "furniturejob:fjui_crack2");
					PlayerTextDrawShow(playerid, factory_job_7_p[4][playerid]);


					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 3:
				{
					PlayerTextDrawHideEx(playerid, factory_job_7_p[13][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_7_p[5][playerid], "furniturejob:fjui_crack3");
					PlayerTextDrawShow(playerid, factory_job_7_p[5][playerid]);


					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 4:
				{
					PlayerTextDrawHideEx(playerid, factory_job_7_p[9][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_7_p[6][playerid], "furniturejob:fjui_crack4");
					PlayerTextDrawShow(playerid, factory_job_7_p[6][playerid]);


					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 5:
				{
					PlayerTextDrawHideEx(playerid, factory_job_7_p[14][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_7_p[7][playerid], "furniturejob:fjui_crack5");
					PlayerTextDrawShow(playerid, factory_job_7_p[7][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 6:
				{
					PlayerTextDrawHideEx(playerid, factory_job_7_p[11][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_7_p[8][playerid], "furniturejob:fjui_crack6");
					PlayerTextDrawShow(playerid, factory_job_7_p[8][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
			}
		}
		case WORK_FACTORY_STAND:
		{
			switch(textdraws)
			{
				case 1:
				{
					PlayerTextDrawHideEx(playerid, factory_job_8_p[12][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_8_p[3][playerid], "furniturejob:fjui_ccupboard1");
					PlayerTextDrawShow(playerid, factory_job_8_p[3][playerid]);


					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 2:
				{
					PlayerTextDrawHideEx(playerid, factory_job_8_p[10][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_8_p[4][playerid], "furniturejob:fjui_ccupboard2");
					PlayerTextDrawShow(playerid, factory_job_8_p[4][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 3:
				{
					PlayerTextDrawHideEx(playerid, factory_job_8_p[13][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_8_p[5][playerid], "furniturejob:fjui_ccupboard3");
					PlayerTextDrawShow(playerid, factory_job_8_p[5][playerid]);


					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 4:
				{
					PlayerTextDrawHideEx(playerid, factory_job_8_p[9][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_8_p[6][playerid], "furniturejob:fjui_ccupboard4");
					PlayerTextDrawShow(playerid, factory_job_8_p[6][playerid]);


					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 5:
				{
					PlayerTextDrawHideEx(playerid, factory_job_8_p[14][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_8_p[7][playerid], "furniturejob:fjui_ccupboard5");
					PlayerTextDrawShow(playerid, factory_job_8_p[7][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 6:
				{
					PlayerTextDrawHideEx(playerid, factory_job_8_p[11][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_8_p[8][playerid], "furniturejob:fjui_ccupboard6");
					PlayerTextDrawShow(playerid, factory_job_8_p[8][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
			}
		}
		case WORK_FACTORY_BOARD:
		{
			switch(textdraws)
			{
				case 1:
				{
					PlayerTextDrawHideEx(playerid, factory_job_9_p[12][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_9_p[3][playerid], "furniturejob:fjui_cchair1");
					PlayerTextDrawShow(playerid, factory_job_9_p[3][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 2:
				{
					PlayerTextDrawHideEx(playerid, factory_job_9_p[10][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_9_p[4][playerid], "furniturejob:fjui_cchair2");
					PlayerTextDrawShow(playerid, factory_job_9_p[4][playerid]);


					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 3:
				{
					PlayerTextDrawHideEx(playerid, factory_job_9_p[13][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_9_p[5][playerid], "furniturejob:fjui_cchair3");
					PlayerTextDrawShow(playerid, factory_job_9_p[5][playerid]);

					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 4:
				{
					PlayerTextDrawHideEx(playerid, factory_job_9_p[9][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_9_p[6][playerid], "furniturejob:fjui_cchair4");
					PlayerTextDrawShow(playerid, factory_job_9_p[6][playerid]);


					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 5:
				{
					PlayerTextDrawHideEx(playerid, factory_job_9_p[14][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_9_p[7][playerid], "furniturejob:fjui_cchair5");
					PlayerTextDrawShow(playerid, factory_job_9_p[7][playerid]);


					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
				case 6:
				{
					PlayerTextDrawHideEx(playerid, factory_job_9_p[11][playerid]);
					PlayerTextDrawSetString(playerid, factory_job_9_p[8][playerid], "furniturejob:fjui_cchair6");
					PlayerTextDrawShow(playerid, factory_job_9_p[8][playerid]);


					factory_job_furniture_count[playerid]++;
					update_count_furniture_progress(playerid);
					update_count_furniture_progress(playerid);
					
					if(factory_job_furniture_count[playerid] >= 6)
						return change_work_factory_click(playerid);

				}
			}
		}
	}



	return true;
}



stock update_count_furniture_progress(playerid)
{
	new 
		type_work_factory = GetPVarIntNew(playerid, "factory_type_furniture");

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
	
	factory_job_count_point_2[playerid] +=count;

	switch(type_work_factory)
	{
		case WORK_FACTORY_SOFA:
		{
		 	format(fmt_str,sizeof(fmt_str),"+_%d", floatround(count, floatround_round));
			PlayerTextDrawSetString(playerid,factory_job_1_p[1][playerid], fmt_str);
			PlayerTextDrawShow(playerid, factory_job_1_p[1][playerid]);

			SetTimerEx("hide_work_factory_furniture", 1500, false, "i", playerid);


		 	format(fmt_str,sizeof(fmt_str),"%06.0f", factory_job_count_point_2[playerid]);
			PlayerTextDrawSetString(playerid,factory_job_1_p[2][playerid], fmt_str);
			PlayerTextDrawShow(playerid, factory_job_1_p[2][playerid]);

			switch(factory_job_furniture_count[playerid])
			{
				case 0..1:
				{
					PlayerTextDrawSetString(playerid,factory_job_1_p[15][playerid], "furniturejob:fjui_p1");
					PlayerTextDrawShow(playerid, factory_job_1_p[15][playerid]);	
				}
				case 2:
				{
					PlayerTextDrawSetString(playerid,factory_job_1_p[15][playerid], "furniturejob:fjui_p2");
					PlayerTextDrawShow(playerid, factory_job_1_p[15][playerid]);	
				}
				case 3:
				{
					PlayerTextDrawSetString(playerid,factory_job_1_p[15][playerid], "furniturejob:fjui_p4");
					PlayerTextDrawShow(playerid, factory_job_1_p[15][playerid]);	
				}
				case 4:
				{
					PlayerTextDrawSetString(playerid,factory_job_1_p[15][playerid], "furniturejob:fjui_p7");
					PlayerTextDrawShow(playerid, factory_job_1_p[15][playerid]);	
				}
				case 5:
				{
					PlayerTextDrawSetString(playerid,factory_job_1_p[15][playerid], "furniturejob:fjui_p9");
					PlayerTextDrawShow(playerid, factory_job_1_p[15][playerid]);	
				}
				case 6:
				{
					PlayerTextDrawSetString(playerid,factory_job_1_p[15][playerid], "furniturejob:fjui_p10");
					PlayerTextDrawShow(playerid, factory_job_1_p[15][playerid]);	
				}
			}

		}

		case WORK_FACTORY_CHAIR:
		{
		 	format(fmt_str,sizeof(fmt_str),"+_%d", floatround(count, floatround_round));
			PlayerTextDrawSetString(playerid,factory_job_2_p[1][playerid], fmt_str);
			PlayerTextDrawShow(playerid, factory_job_2_p[1][playerid]);

			SetTimerEx("hide_work_factory_furniture", 1500, false, "i", playerid);


		 	format(fmt_str,sizeof(fmt_str),"%06.0f", factory_job_count_point_2[playerid]);
			PlayerTextDrawSetString(playerid,factory_job_2_p[2][playerid], fmt_str);
			PlayerTextDrawShow(playerid, factory_job_2_p[2][playerid]);

			switch(factory_job_furniture_count[playerid])
			{
				case 0..1:
				{
					PlayerTextDrawSetString(playerid,factory_job_2_p[15][playerid], "furniturejob:fjui_p1");
					PlayerTextDrawShow(playerid, factory_job_2_p[15][playerid]);	
				}
				case 2:
				{
					PlayerTextDrawSetString(playerid,factory_job_2_p[15][playerid], "furniturejob:fjui_p2");
					PlayerTextDrawShow(playerid, factory_job_2_p[15][playerid]);	
				}
				case 3:
				{
					PlayerTextDrawSetString(playerid,factory_job_2_p[15][playerid], "furniturejob:fjui_p4");
					PlayerTextDrawShow(playerid, factory_job_2_p[15][playerid]);	
				}
				case 4:
				{
					PlayerTextDrawSetString(playerid,factory_job_2_p[15][playerid], "furniturejob:fjui_p7");
					PlayerTextDrawShow(playerid, factory_job_2_p[15][playerid]);	
				}
				case 5:
				{
					PlayerTextDrawSetString(playerid,factory_job_2_p[15][playerid], "furniturejob:fjui_p9");
					PlayerTextDrawShow(playerid, factory_job_2_p[15][playerid]);	
				}
				case 6:
				{
					PlayerTextDrawSetString(playerid,factory_job_2_p[15][playerid], "furniturejob:fjui_p10");
					PlayerTextDrawShow(playerid, factory_job_2_p[15][playerid]);	
				}
			}

		}
		case WORK_FACTORY_BED:
		{
		 	format(fmt_str,sizeof(fmt_str),"+_%d", floatround(count, floatround_round));
			PlayerTextDrawSetString(playerid,factory_job_3_p[1][playerid], fmt_str);
			PlayerTextDrawShow(playerid, factory_job_3_p[1][playerid]);

			SetTimerEx("hide_work_factory_furniture", 1500, false, "i", playerid);


		 	format(fmt_str,sizeof(fmt_str),"%06.0f", factory_job_count_point_2[playerid]);
			PlayerTextDrawSetString(playerid,factory_job_3_p[2][playerid], fmt_str);
			PlayerTextDrawShow(playerid, factory_job_3_p[2][playerid]);

			switch(factory_job_furniture_count[playerid])
			{
				case 0..1:
				{
					PlayerTextDrawSetString(playerid,factory_job_3_p[15][playerid], "furniturejob:fjui_p1");
					PlayerTextDrawShow(playerid, factory_job_3_p[15][playerid]);	
				}
				case 2:
				{
					PlayerTextDrawSetString(playerid,factory_job_3_p[15][playerid], "furniturejob:fjui_p2");
					PlayerTextDrawShow(playerid, factory_job_3_p[15][playerid]);	
				}
				case 3:
				{
					PlayerTextDrawSetString(playerid,factory_job_3_p[15][playerid], "furniturejob:fjui_p4");
					PlayerTextDrawShow(playerid, factory_job_3_p[15][playerid]);	
				}
				case 4:
				{
					PlayerTextDrawSetString(playerid,factory_job_3_p[15][playerid], "furniturejob:fjui_p7");
					PlayerTextDrawShow(playerid, factory_job_3_p[15][playerid]);	
				}
				case 5:
				{
					PlayerTextDrawSetString(playerid,factory_job_3_p[15][playerid], "furniturejob:fjui_p9");
					PlayerTextDrawShow(playerid, factory_job_3_p[15][playerid]);	
				}
				case 6:
				{
					PlayerTextDrawSetString(playerid,factory_job_3_p[15][playerid], "furniturejob:fjui_p10");
					PlayerTextDrawShow(playerid, factory_job_3_p[15][playerid]);	
				}
			}

		}
		case WORK_FACTORY_FRAME:
		{
		 	format(fmt_str,sizeof(fmt_str),"+_%d", floatround(count, floatround_round));
			PlayerTextDrawSetString(playerid,factory_job_4_p[1][playerid], fmt_str);
			PlayerTextDrawShow(playerid, factory_job_4_p[1][playerid]);

			SetTimerEx("hide_work_factory_furniture", 1500, false, "i", playerid);


		 	format(fmt_str,sizeof(fmt_str),"%06.0f", factory_job_count_point_2[playerid]);
			PlayerTextDrawSetString(playerid,factory_job_4_p[2][playerid], fmt_str);
			PlayerTextDrawShow(playerid, factory_job_4_p[2][playerid]);

			switch(factory_job_furniture_count[playerid])
			{
				case 0..1:
				{
					PlayerTextDrawSetString(playerid,factory_job_4_p[15][playerid], "furniturejob:fjui_p1");
					PlayerTextDrawShow(playerid, factory_job_4_p[15][playerid]);	
				}
				case 2:
				{
					PlayerTextDrawSetString(playerid,factory_job_4_p[15][playerid], "furniturejob:fjui_p2");
					PlayerTextDrawShow(playerid, factory_job_4_p[15][playerid]);	
				}
				case 3:
				{
					PlayerTextDrawSetString(playerid,factory_job_4_p[15][playerid], "furniturejob:fjui_p4");
					PlayerTextDrawShow(playerid, factory_job_4_p[15][playerid]);	
				}
				case 4:
				{
					PlayerTextDrawSetString(playerid,factory_job_4_p[15][playerid], "furniturejob:fjui_p7");
					PlayerTextDrawShow(playerid, factory_job_4_p[15][playerid]);	
				}
				case 5:
				{
					PlayerTextDrawSetString(playerid,factory_job_4_p[15][playerid], "furniturejob:fjui_p9");
					PlayerTextDrawShow(playerid, factory_job_4_p[15][playerid]);	
				}
				case 6:
				{
					PlayerTextDrawSetString(playerid,factory_job_4_p[15][playerid], "furniturejob:fjui_p10");
					PlayerTextDrawShow(playerid, factory_job_4_p[15][playerid]);	
				}
			}

		}
		case WORK_FACTORY_CRACK:
		{
		 	format(fmt_str,sizeof(fmt_str),"+_%d", floatround(count, floatround_round));
			PlayerTextDrawSetString(playerid,factory_job_5_p[1][playerid], fmt_str);
			PlayerTextDrawShow(playerid, factory_job_5_p[1][playerid]);

			SetTimerEx("hide_work_factory_furniture", 1500, false, "i", playerid);


		 	format(fmt_str,sizeof(fmt_str),"%06.0f", factory_job_count_point_2[playerid]);
			PlayerTextDrawSetString(playerid,factory_job_5_p[2][playerid], fmt_str);
			PlayerTextDrawShow(playerid, factory_job_5_p[2][playerid]);

			switch(factory_job_furniture_count[playerid])
			{
				case 0..1:
				{
					PlayerTextDrawSetString(playerid,factory_job_5_p[15][playerid], "furniturejob:fjui_p1");
					PlayerTextDrawShow(playerid, factory_job_5_p[15][playerid]);	
				}
				case 2:
				{
					PlayerTextDrawSetString(playerid,factory_job_5_p[15][playerid], "furniturejob:fjui_p2");
					PlayerTextDrawShow(playerid, factory_job_5_p[15][playerid]);	
				}
				case 3:
				{
					PlayerTextDrawSetString(playerid,factory_job_5_p[15][playerid], "furniturejob:fjui_p4");
					PlayerTextDrawShow(playerid, factory_job_5_p[15][playerid]);	
				}
				case 4:
				{
					PlayerTextDrawSetString(playerid,factory_job_5_p[15][playerid], "furniturejob:fjui_p7");
					PlayerTextDrawShow(playerid, factory_job_5_p[15][playerid]);	
				}
				case 5:
				{
					PlayerTextDrawSetString(playerid,factory_job_5_p[15][playerid], "furniturejob:fjui_p9");
					PlayerTextDrawShow(playerid, factory_job_5_p[15][playerid]);	
				}
				case 6:
				{
					PlayerTextDrawSetString(playerid,factory_job_5_p[15][playerid], "furniturejob:fjui_p10");
					PlayerTextDrawShow(playerid, factory_job_5_p[15][playerid]);	
				}
			}

		}
		case WORK_FACTORY_TABLE:
		{
		 	format(fmt_str,sizeof(fmt_str),"+_%d", floatround(count, floatround_round));
			PlayerTextDrawSetString(playerid,factory_job_6_p[1][playerid], fmt_str);
			PlayerTextDrawShow(playerid, factory_job_6_p[1][playerid]);

			SetTimerEx("hide_work_factory_furniture", 1500, false, "i", playerid);


		 	format(fmt_str,sizeof(fmt_str),"%06.0f", factory_job_count_point_2[playerid]);
			PlayerTextDrawSetString(playerid,factory_job_6_p[2][playerid], fmt_str);
			PlayerTextDrawShow(playerid, factory_job_6_p[2][playerid]);

			switch(factory_job_furniture_count[playerid])
			{
				case 0..1:
				{
					PlayerTextDrawSetString(playerid,factory_job_6_p[15][playerid], "furniturejob:fjui_p1");
					PlayerTextDrawShow(playerid, factory_job_6_p[15][playerid]);	
				}
				case 2:
				{
					PlayerTextDrawSetString(playerid,factory_job_6_p[15][playerid], "furniturejob:fjui_p2");
					PlayerTextDrawShow(playerid, factory_job_6_p[15][playerid]);	
				}
				case 3:
				{
					PlayerTextDrawSetString(playerid,factory_job_6_p[15][playerid], "furniturejob:fjui_p4");
					PlayerTextDrawShow(playerid, factory_job_6_p[15][playerid]);	
				}
				case 4:
				{
					PlayerTextDrawSetString(playerid,factory_job_6_p[15][playerid], "furniturejob:fjui_p7");
					PlayerTextDrawShow(playerid, factory_job_6_p[15][playerid]);	
				}
				case 5:
				{
					PlayerTextDrawSetString(playerid,factory_job_6_p[15][playerid], "furniturejob:fjui_p9");
					PlayerTextDrawShow(playerid, factory_job_6_p[15][playerid]);	
				}
				case 6:
				{
					PlayerTextDrawSetString(playerid,factory_job_6_p[15][playerid], "furniturejob:fjui_p10");
					PlayerTextDrawShow(playerid, factory_job_6_p[15][playerid]);	
				}
			}

		}
		case WORK_FACTORY_CHAIR_2:
		{
		 	format(fmt_str,sizeof(fmt_str),"+_%d", floatround(count, floatround_round));
			PlayerTextDrawSetString(playerid,factory_job_7_p[1][playerid], fmt_str);
			PlayerTextDrawShow(playerid, factory_job_7_p[1][playerid]);

			SetTimerEx("hide_work_factory_furniture", 1500, false, "i", playerid);


		 	format(fmt_str,sizeof(fmt_str),"%06.0f", factory_job_count_point_2[playerid]);
			PlayerTextDrawSetString(playerid,factory_job_7_p[2][playerid], fmt_str);
			PlayerTextDrawShow(playerid, factory_job_7_p[2][playerid]);

			switch(factory_job_furniture_count[playerid])
			{
				case 0..1:
				{
					PlayerTextDrawSetString(playerid,factory_job_7_p[15][playerid], "furniturejob:fjui_p1");
					PlayerTextDrawShow(playerid, factory_job_7_p[15][playerid]);	
				}
				case 2:
				{
					PlayerTextDrawSetString(playerid,factory_job_7_p[15][playerid], "furniturejob:fjui_p2");
					PlayerTextDrawShow(playerid, factory_job_7_p[15][playerid]);	
				}
				case 3:
				{
					PlayerTextDrawSetString(playerid,factory_job_7_p[15][playerid], "furniturejob:fjui_p4");
					PlayerTextDrawShow(playerid, factory_job_7_p[15][playerid]);	
				}
				case 4:
				{
					PlayerTextDrawSetString(playerid,factory_job_7_p[15][playerid], "furniturejob:fjui_p7");
					PlayerTextDrawShow(playerid, factory_job_7_p[15][playerid]);	
				}
				case 5:
				{
					PlayerTextDrawSetString(playerid,factory_job_7_p[15][playerid], "furniturejob:fjui_p9");
					PlayerTextDrawShow(playerid, factory_job_7_p[15][playerid]);	
				}
				case 6:
				{
					PlayerTextDrawSetString(playerid,factory_job_7_p[15][playerid], "furniturejob:fjui_p10");
					PlayerTextDrawShow(playerid, factory_job_7_p[15][playerid]);	
				}
			}

		}
		case WORK_FACTORY_STAND:
		{
		 	format(fmt_str,sizeof(fmt_str),"+_%d", floatround(count, floatround_round));
			PlayerTextDrawSetString(playerid,factory_job_8_p[1][playerid], fmt_str);
			PlayerTextDrawShow(playerid, factory_job_8_p[1][playerid]);

			SetTimerEx("hide_work_factory_furniture", 1500, false, "i", playerid);


		 	format(fmt_str,sizeof(fmt_str),"%06.0f", factory_job_count_point_2[playerid]);
			PlayerTextDrawSetString(playerid,factory_job_8_p[2][playerid], fmt_str);
			PlayerTextDrawShow(playerid, factory_job_8_p[2][playerid]);

			switch(factory_job_furniture_count[playerid])
			{
				case 0..1:
				{
					PlayerTextDrawSetString(playerid,factory_job_8_p[15][playerid], "furniturejob:fjui_p1");
					PlayerTextDrawShow(playerid, factory_job_8_p[15][playerid]);	
				}
				case 2:
				{
					PlayerTextDrawSetString(playerid,factory_job_8_p[15][playerid], "furniturejob:fjui_p2");
					PlayerTextDrawShow(playerid, factory_job_8_p[15][playerid]);	
				}
				case 3:
				{
					PlayerTextDrawSetString(playerid,factory_job_8_p[15][playerid], "furniturejob:fjui_p4");
					PlayerTextDrawShow(playerid, factory_job_8_p[15][playerid]);	
				}
				case 4:
				{
					PlayerTextDrawSetString(playerid,factory_job_8_p[15][playerid], "furniturejob:fjui_p7");
					PlayerTextDrawShow(playerid, factory_job_8_p[15][playerid]);	
				}
				case 5:
				{
					PlayerTextDrawSetString(playerid,factory_job_8_p[15][playerid], "furniturejob:fjui_p9");
					PlayerTextDrawShow(playerid, factory_job_8_p[15][playerid]);	
				}
				case 6:
				{
					PlayerTextDrawSetString(playerid,factory_job_8_p[15][playerid], "furniturejob:fjui_p10");
					PlayerTextDrawShow(playerid, factory_job_8_p[15][playerid]);	
				}
			}

		}
		case WORK_FACTORY_BOARD:
		{
		 	format(fmt_str,sizeof(fmt_str),"+_%d", floatround(count, floatround_round));
			PlayerTextDrawSetString(playerid,factory_job_9_p[1][playerid], fmt_str);
			PlayerTextDrawShow(playerid, factory_job_9_p[1][playerid]);

			SetTimerEx("hide_work_factory_furniture", 1500, false, "i", playerid);


		 	format(fmt_str,sizeof(fmt_str),"%06.0f", factory_job_count_point_2[playerid]);
			PlayerTextDrawSetString(playerid,factory_job_9_p[2][playerid], fmt_str);
			PlayerTextDrawShow(playerid, factory_job_9_p[2][playerid]);

			switch(factory_job_furniture_count[playerid])
			{
				case 0..1:
				{
					PlayerTextDrawSetString(playerid,factory_job_9_p[15][playerid], "furniturejob:fjui_p1");
					PlayerTextDrawShow(playerid, factory_job_9_p[15][playerid]);	
				}
				case 2:
				{
					PlayerTextDrawSetString(playerid,factory_job_9_p[15][playerid], "furniturejob:fjui_p2");
					PlayerTextDrawShow(playerid, factory_job_9_p[15][playerid]);	
				}
				case 3:
				{
					PlayerTextDrawSetString(playerid,factory_job_9_p[15][playerid], "furniturejob:fjui_p4");
					PlayerTextDrawShow(playerid, factory_job_9_p[15][playerid]);	
				}
				case 4:
				{
					PlayerTextDrawSetString(playerid,factory_job_9_p[15][playerid], "furniturejob:fjui_p7");
					PlayerTextDrawShow(playerid, factory_job_9_p[15][playerid]);	
				}
				case 5:
				{
					PlayerTextDrawSetString(playerid,factory_job_9_p[15][playerid], "furniturejob:fjui_p9");
					PlayerTextDrawShow(playerid, factory_job_9_p[15][playerid]);	
				}
				case 6:
				{
					PlayerTextDrawSetString(playerid,factory_job_9_p[15][playerid], "furniturejob:fjui_p10");
					PlayerTextDrawShow(playerid, factory_job_9_p[15][playerid]);	
				}
			}

		}			
	}


	return true;
}

callback:: hide_work_factory_furniture(playerid)
{
	new 
		type_work_factory = GetPVarIntNew(playerid, "factory_type_furniture");


	switch(type_work_factory)
	{
		case WORK_FACTORY_SOFA:
		{
			PlayerTextDrawHide(playerid, factory_job_1_p[1][playerid]);
		}
		case WORK_FACTORY_CHAIR:
		{		
			PlayerTextDrawHide(playerid, factory_job_2_p[1][playerid]);
		}
		case WORK_FACTORY_BED:
		{
			PlayerTextDrawHide(playerid, factory_job_3_p[1][playerid]);
		}
		case WORK_FACTORY_FRAME:
		{
			PlayerTextDrawHide(playerid, factory_job_4_p[1][playerid]);
		}
		case WORK_FACTORY_CRACK:
		{
			PlayerTextDrawHide(playerid, factory_job_5_p[1][playerid]);
		}
		case WORK_FACTORY_TABLE:
		{
			PlayerTextDrawHide(playerid, factory_job_6_p[1][playerid]);
		}
		case WORK_FACTORY_CHAIR_2:
		{
			PlayerTextDrawHide(playerid, factory_job_7_p[1][playerid]);
		}
		case WORK_FACTORY_STAND:
		{
			PlayerTextDrawHide(playerid, factory_job_8_p[1][playerid]);
		}
		case WORK_FACTORY_BOARD:
		{
			PlayerTextDrawHide(playerid, factory_job_9_p[1][playerid]);
		}
	}		
	//TogglePlayerAllHudElements(playerid, HUD_ELEMENT_SHOW);
	return true;
}