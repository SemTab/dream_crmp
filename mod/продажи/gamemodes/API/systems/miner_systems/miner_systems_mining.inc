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


stock panel_miner_minig(playerid, type)
{
	switch(type)
	{
		case TEXTDRAW_SHOW:
		{
			TextDrawShowForPlayer(playerid, mine_job_1[0]);
			TextDrawShowForPlayer(playerid, mine_job_1[1]);	

			create_miner_job_1(playerid);

			generate_all_position_mining(playerid);

		}
		case TEXTDRAW_HIDE:
		{
			TextDrawHideForPlayer(playerid, mine_job_1[0]);
			TextDrawHideForPlayer(playerid, mine_job_1[1]);	

			for(new i = 0; i < 22; i++)
			{
				if(miner_job_1_p[playerid][i] != PlayerText:INVALID_TEXT_DRAW)
				{
					PlayerTextDrawHideEx(playerid, miner_job_1_p[playerid][i]);
				}
			}			
		}
	}

	return true;
}

stock generate_all_position_mining(playerid)
{
	new 
		random_select_minig = RandomEx(0, 5);

	switch(random_select_minig)
	{
		case 0: 
		{
			miner_select_material_mining[playerid] = MINEJOB_COAL;

			PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][19], "minejob:coal");
			PlayerTextDrawShow(playerid, miner_job_1_p[playerid][19]);				
		}
		case 1: 
		{
			miner_select_material_mining[playerid] = MINEJOB_COPPER;

			PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][19], "minejob:copper");
			PlayerTextDrawShow(playerid, miner_job_1_p[playerid][19]);				
		}
		case 2: 
		{
			miner_select_material_mining[playerid] = MINEJOB_DIAMOND;


			PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][19], "minejob:diamond");
			PlayerTextDrawShow(playerid, miner_job_1_p[playerid][19]);				
		}
		case 3: 
		{
			miner_select_material_mining[playerid] = MINEJOB_GOLD;

			PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][19], "minejob:gold");
			PlayerTextDrawShow(playerid, miner_job_1_p[playerid][19]);				
		}
		case 4: 
		{
			miner_select_material_mining[playerid] = MINEJOB_IRON;

			PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][19], "minejob:iron");
			PlayerTextDrawShow(playerid, miner_job_1_p[playerid][19]);				
		}
		case 5: 
		{
			miner_select_material_mining[playerid] = MINEJOB_METAL;

			PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][19], "minejob:metal");
			PlayerTextDrawShow(playerid, miner_job_1_p[playerid][19]);				
		}
		case 6:
		{
			miner_select_material_mining[playerid] = MINEJOB_METAL;

			PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][19], "minejob:metal");
			PlayerTextDrawShow(playerid, miner_job_1_p[playerid][19]);				
		}
	}
	PlayerTextDrawShow(playerid, miner_job_1_p[playerid][19]);		


	new 
		random_td_mat_yes = RandomEx(3, 18);

	mine_random_material_active[playerid] = random_td_mat_yes;

	switch(miner_select_material_mining[playerid])
	{
		case MINEJOB_COAL:
		{
			PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][random_td_mat_yes], "minejob:qcoal");
			PlayerTextDrawShow(playerid, miner_job_1_p[playerid][random_td_mat_yes]);	
		}
		case MINEJOB_COPPER:
		{
			PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][random_td_mat_yes], "minejob:qcopper");
			PlayerTextDrawShow(playerid, miner_job_1_p[playerid][random_td_mat_yes]);	
		}
		case MINEJOB_DIAMOND:
		{

			PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][random_td_mat_yes], "minejob:qdiamond");
			PlayerTextDrawShow(playerid, miner_job_1_p[playerid][random_td_mat_yes]);				
		}
		case MINEJOB_GOLD:
		{
			PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][random_td_mat_yes], "minejob:qgold");
			PlayerTextDrawShow(playerid, miner_job_1_p[playerid][random_td_mat_yes]);				
		}
		case MINEJOB_IRON:
		{
			PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][random_td_mat_yes], "minejob:qiron");
			PlayerTextDrawShow(playerid, miner_job_1_p[playerid][random_td_mat_yes]);				
		}
		case MINEJOB_METAL:
		{
			PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][random_td_mat_yes], "minejob:qmetal");
			PlayerTextDrawShow(playerid, miner_job_1_p[playerid][random_td_mat_yes]);				
		}		
	}
	PlayerTextDrawShow(playerid, miner_job_1_p[playerid][random_td_mat_yes]);	

	for(new i = 3; i < 18; i++)
	{
		new 
			random_materials = RandomEx(0, 85);

		if(i == mine_random_material_active[playerid])
		{	
			i++;
		}

		if(miner_select_material_mining[playerid] == MINEJOB_COAL)
		{
			switch(random_materials)
			{
				case 0..5:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qmetal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 6..10:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcopper");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 11..15:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcopper");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 16..20:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qmetal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}
				case 21..25:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qiron");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}
				case 26..30:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qiron");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}
				case 31..35:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qmetal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}
				case 36..40:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcopper");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 41..50:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qiron");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}
				case 51..60:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcopper");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}	
				case 81..85:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qmetal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}	
				case 61..65:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcopper");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 66..70:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qiron");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 71..74:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qmetal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}	
				case 76..80:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qiron");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}	
			}								
		}	
		else if(miner_select_material_mining[playerid] == MINEJOB_COPPER)
		{
			switch(random_materials)
			{
				case 0..5:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qmetal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 6..10:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcoal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 11..15:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qiron");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 16..20:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qmetal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}
				case 21..25:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qiron");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}
				case 26..30:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qiron");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}
				case 31..35:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qmetal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}
				case 36..40:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcoal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 41..50:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qiron");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}
				case 51..60:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qiron");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}	
				case 81..85:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qiron");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}	
				case 61..65:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcoal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 66..70:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qiron");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 71..75:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qmetal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}	
				case 76..80:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qiron");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}	
			}	
		}
		else if(miner_select_material_mining[playerid] == MINEJOB_DIAMOND)
		{
			switch(random_materials)
			{
				case 0..5:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qmetal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 6..10:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcoal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 11..15:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qgold");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 16..20:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qmetal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}
				case 21..25:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qgold");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}
				case 26..30:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qiron");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}
				case 31..35:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qmetal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}
				case 36..40:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcoal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 41..50:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qmetal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}
				case 51..60:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qgold");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}	
				case 81..85:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qgold");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}	
				case 61..65:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcoal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 66..70:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qiron");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 71..75:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qmetal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}	
				case 76..80:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcopper");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}	
			}
		}		
		else if(miner_select_material_mining[playerid] == MINEJOB_GOLD)
		{
			switch(random_materials)
			{
				case 0..5:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qmetal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 6..10:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcoal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 11..15:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qmetal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 16..20:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qmetal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}
				case 21..25:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcopper");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}
				case 26..30:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qiron");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}
				case 31..35:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qmetal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}
				case 36..40:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcoal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 41..50:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qmetal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}
				case 51..60:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcopper");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}	
				case 81..85:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcopper");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}	
				case 61..65:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcoal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 66..70:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qiron");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 71..75:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qmetal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}	
				case 76..80:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qiron");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}	
			}																		
		}	
		else if(miner_select_material_mining[playerid] == MINEJOB_IRON)
		{
			switch(random_materials)
			{
				case 0..5:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qmetal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 6..10:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcoal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 11..15:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qmetal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 16..20:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qmetal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}
				case 21..25:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcopper");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}
				case 26..30:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qmetal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}
				case 31..35:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qmetal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}
				case 36..40:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcoal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 41..50:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qmetal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}
				case 51..60:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcopper");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}	
				case 81..85:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcopper");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}	
				case 61..65:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcoal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 66..70:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcopper");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 71..75:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qmetal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}	
				case 76..80:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcopper");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}	
			}																		
		}	
		else if(miner_select_material_mining[playerid] == MINEJOB_METAL)
		{
			switch(random_materials)
			{
				case 0..5:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qiron");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 6..10:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcoal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 11..15:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qiron");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 16..20:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcopper");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}
				case 21..25:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcopper");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}
				case 26..30:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcoal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}
				case 31..35:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qiron");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}
				case 36..40:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcoal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 41..50:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qiron");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}
				case 51..60:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcopper");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}	
				case 81..85:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcopper");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}	
				case 61..65:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcoal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 66..70:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qiron");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
				}
				case 71..75:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qiron");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}	
				case 76..80:
				{
					PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][i], "minejob:qcoal");
					PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);				
				}	
			}																		
		}		
		PlayerTextDrawShow(playerid, miner_job_1_p[playerid][i]);	
	}
	return true;
}

stock panel_progress_mine_miner(playerid)
{
	switch(mine_miner_progress_bar[playerid])
	{
		case 0:
		{
			PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][20], "minejob:p1");
			PlayerTextDrawShow(playerid, miner_job_1_p[playerid][20]);	
		}
		case 1:
		{
			PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][20], "minejob:p2");
			PlayerTextDrawShow(playerid, miner_job_1_p[playerid][20]);				
		}
		case 2:
		{
			PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][20], "minejob:p3");
			PlayerTextDrawShow(playerid, miner_job_1_p[playerid][20]);				
		}
		case 3:
		{
			PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][20], "minejob:p4");
			PlayerTextDrawShow(playerid, miner_job_1_p[playerid][20]);				
		}
		case 4:
		{
			PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][20], "minejob:p5");
			PlayerTextDrawShow(playerid, miner_job_1_p[playerid][20]);				
		}
		case 5:
		{
			PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][20], "minejob:p6");
			PlayerTextDrawShow(playerid, miner_job_1_p[playerid][20]);				
		}
		case 6:
		{
			PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][20], "minejob:p7");
			PlayerTextDrawShow(playerid, miner_job_1_p[playerid][20]);				
		}
		case 7:
		{
			PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][20], "minejob:p8");
			PlayerTextDrawShow(playerid, miner_job_1_p[playerid][20]);			
		}
		case 8:
		{
			PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][20], "minejob:p9");
			PlayerTextDrawShow(playerid, miner_job_1_p[playerid][20]);			
		}
		case 9:
		{
			PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][20], "minejob:p9");
			PlayerTextDrawShow(playerid, miner_job_1_p[playerid][20]);
		}
		case 10..11:
		{
			PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][20], "minejob:p10");
			PlayerTextDrawShow(playerid, miner_job_1_p[playerid][20]);			
		}
	}
	PlayerTextDrawShow(playerid, miner_job_1_p[playerid][20]);	
	return true;
}

cmd:panel_mine(playerid)
{
	return start_player_miner_mining(playerid);
}

cmd:panel_mine_close(playerid)
{
	return final_player_miner_mining(playerid);
}

stock start_player_miner_mining(playerid)
{
	if(GetPVarIntNew(playerid, "panel_mine_active") == 1)
		return true;
	
	if(!GetPVarIntNew(playerid, "miner_type_work"))
	{
		return SendInf(playerid, "Вам недоступен данный этап работы!");
	}
	if(GetPVarIntNew(playerid, "miner_type_work") != STAP_JOB_MINER_MINING)
	{
		return SendInf(playerid, "Вам недоступен данный этап работы!");
	}
	if(GetPVarIntNew(playerid, "miner_type_work") == STAP_JOB_MINER_SORT)
	{
		SendInf(playerid, "Вам недоступен данный этап работы!");
		return SendInf(playerid, "Ваша задача: сортировка руды на конвеере!");
	}
	if(GetPVarIntNew(playerid, "miner_type_work") == STAP_JOB_MINER_LIFT)
	{
		SendInf(playerid, "Вам недоступен данный этап работы!");
		return SendInf(playerid, "Сперва Вам нужно отнести руду на склад!");
	}
	if(GetPVarIntNew(playerid, "miner_type_work") == STAP_JOB_MINER_SKLAD)
	{
		SendInf(playerid, "Вам недоступен данный этап работы!");
		return SendInf(playerid, "Вы уже сортировали руду на конвеере!");
	}

	final_player_miner_mining(TEXTDRAW_HIDE);

	panel_miner_minig(playerid, TEXTDRAW_SHOW);


	PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][2], "000000");
	PlayerTextDrawShow(playerid, miner_job_1_p[playerid][2]);		

	format(String64, 32, "X1");
	PlayerTextDrawSetString(playerid, miner_job_1_p[playerid][21], String64);
	PlayerTextDrawShow(playerid, miner_job_1_p[playerid][21]);	

	panel_progress_mine_miner(playerid);

	SelectTextDraw(playerid, COLOR_BLUE);

	SetPVarIntNew(playerid, "panel_mine_active", 1);

	SetPVarIntNew(playerid, "miner_type_work", STAP_JOB_MINER_MINING);

	TogglePlayerControllable(playerid, false);

	return true;
}

stock final_player_miner_mining(playerid)
{
	panel_miner_minig(playerid, TEXTDRAW_HIDE);
 	CancelSelectTextDraw(playerid);

 	miner_select_material_mining[playerid] = MINEJOB_NONE;
 	mine_random_material_active[playerid] = -1;

 	DeletePVarNew(playerid, "panel_mine_active");

 	return true;
}

stock close_player_miner_mining(playerid)
{
	panel_miner_minig(playerid, TEXTDRAW_HIDE);
 	CancelSelectTextDraw(playerid);

 	miner_select_material_mining[playerid] = MINEJOB_NONE;
 	mine_random_material_active[playerid] = -1;
 	mine_miner_progress_bar[playerid] = 0;

 	DeletePVarNew(playerid, "panel_mine_active");

	return true;
}

stock change_type_job_miner(playerid)
{
	panel_miner_minig(playerid, TEXTDRAW_HIDE);
 	CancelSelectTextDraw(playerid);

 	PlayerTextDrawHideEx(playerid, miner_job_1_p[playerid][1]);

 	miner_select_material_mining[playerid] = MINEJOB_NONE;
 	mine_random_material_active[playerid] = -1;
 	mine_miner_progress_bar[playerid] = 0;

 	DeletePVarNew(playerid, "panel_mine_active");

 	next_stap_miner_lift(playerid);

	return true;
}

stock next_stap_miner_lift(playerid)
{
	PlayerTextDrawHideEx(playerid, miner_job_1_p[playerid][1]);


	switch(random(3))
	{
		case 0: attach_miner_stone(playerid, STONE_IRON, ATTACH_HAND_MINER);
		case 1: attach_miner_stone(playerid, STONE_MED, ATTACH_HAND_MINER);
		case 2: attach_miner_stone(playerid, STONE_GOLD, ATTACH_HAND_MINER);
	}
	for(new is; is < sizeof(position_miner_lift_load); is++)
	{
		//13720 - для мобайл

		mine_player_pickup[playerid][0] = CreateDynamicPickup(13720, 8, position_miner_lift_load[is][0], position_miner_lift_load[is][1], position_miner_lift_load[is][2]+1.8, -1, -1, playerid);
	}


	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_CARRY);
	PlayerPlaySound(playerid, 1083, 0.0, 0.0, 0.0);
	SetCameraBehindPlayer(playerid);
	TogglePlayerControllable(playerid, true);		

 	SCM(playerid, -1, "");
 	SendInf(playerid, "Вы успешно произвели добычу руды, погрузите её в лифт!");
 	SendInf(playerid, "После этого Вы получите дополнительные инструкции по работе!");

 	SetPVarIntNew(playerid, "miner_job_count", GetPVarIntNew(playerid, "miner_job_count")+5);

 	SetPVarIntNew(playerid, "miner_type_work", STAP_JOB_MINER_LIFT);


	return true;
}

stock next_stap_miner_konveer(playerid)
{

	if(GetPVarIntNew(playerid, "miner_type_work") != STAP_JOB_MINER_LIFT)
		return true;


 	SCM(playerid, -1, "");
 	SendInf(playerid, "Вы успешно погрузили добытую руду в лифт!");
 	SendInf(playerid, "Отправляйтесь к конвееру и начните сортировку руды!");

 	SetPVarIntNew(playerid, "miner_job_count", GetPVarIntNew(playerid, "miner_job_count")+5);

 	SetPVarIntNew(playerid, "miner_type_work", STAP_JOB_MINER_KONVEER);

	DestroyDynamicPickup(mine_player_pickup[playerid][0]);
	Streamer_Update(playerid);
	
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
	RemovePlayerAttachedObject(playerid, 6);

	new 
		rand = random(MAX_MINER_KONVEER);

	mine_player_pickup[playerid][1] = CreateDynamicPickup(13720, 8, position_miner_konveer[rand][0], position_miner_konveer[rand][1], position_miner_konveer[rand][2]+1.0, -1, -1, playerid);

	return true;
}

stock reload_mine_panel_mining(playerid)
{
	if(mine_miner_progress_bar[playerid] < 12)
	{
		if(GetPVarIntNew(playerid, "mining_count_diamond") >= 10)
		{
			if(pData[playerid][pQuestNewYear][6] == 2)
			{
				check_status_quest_newyear(playerid, 6);
			}
		}

		mine_miner_progress_bar[playerid]++;
		panel_progress_mine_miner(playerid);
		generate_all_position_mining(playerid);
		update_bonus_mine_mining(playerid);
	}
	if(mine_miner_progress_bar[playerid] >= 12)
	{
		panel_progress_mine_miner(playerid);
		change_type_job_miner(playerid);
		//update_bonus_mine_mining(playerid);
	}

	return true;
}

stock realod_mine_panel_mining_faily(playerid)
{
	if(mine_miner_progress_bar[playerid] > 0)
	{
		if(GetPVarIntNew(playerid, "mining_count_diamond") >= 10)
		{
			if(pData[playerid][pQuestNewYear][6] == 2)
			{
				check_status_quest_newyear(playerid, 6);
			}
		}

		mine_miner_progress_bar[playerid]--;
		panel_progress_mine_miner(playerid);
		generate_all_position_mining(playerid);
	}
	generate_all_position_mining(playerid);
	return true;	
}

stock update_bonus_mine_mining(playerid)
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
			case 5: count = 30.0;
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
	
	progress_job_mine_miner[playerid] +=count;

	new 
		fmt_str[50];

	if(miner_job_1_p[playerid][1] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_1_p[playerid][1] = CreatePlayerTextDraw(playerid, 319.999938, 68.000015, "+_11");
		PlayerTextDrawLetterSize(playerid, miner_job_1_p[playerid][1], 0.574998, 2.678518);
		PlayerTextDrawTextSize(playerid, miner_job_1_p[playerid][1], 0.000000, 513.360351);
		PlayerTextDrawAlignment(playerid, miner_job_1_p[playerid][1], 2);
		PlayerTextDrawColor(playerid, miner_job_1_p[playerid][1], -1);
		PlayerTextDrawSetShadow(playerid, miner_job_1_p[playerid][1], 0);
		PlayerTextDrawBackgroundColor(playerid, miner_job_1_p[playerid][1], 255);
		PlayerTextDrawFont(playerid, miner_job_1_p[playerid][1], 1);
		PlayerTextDrawSetProportional(playerid, miner_job_1_p[playerid][1], 1);
	}

 	format(fmt_str,sizeof(fmt_str),"+_%d", floatround(count, floatround_round));
	PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][1], fmt_str);
	PlayerTextDrawShow(playerid, miner_job_1_p[playerid][1]);

	SetTimerEx("hide_mine_notify_mining", 1000, false, "i", playerid);


 	format(fmt_str,sizeof(fmt_str),"%06.0f", progress_job_mine_miner[playerid]);
	PlayerTextDrawSetString(playerid,miner_job_1_p[playerid][2], fmt_str);
	PlayerTextDrawShow(playerid, miner_job_1_p[playerid][2]);

	return true;
}


callback:: hide_mine_notify_mining(playerid)
{

	PlayerTextDrawHideEx(playerid, miner_job_1_p[playerid][1]);

	return true;
}
