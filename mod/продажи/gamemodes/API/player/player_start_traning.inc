

stock create_other_element_traning()
{

	// Батырево

	traning_start_player_actor[0] = CreateActor(105, 1815.9315,2527.0491,15.8682,271.5656);
	ApplyActorAnimation(traning_start_player_actor[0], "ON_LOOKERS", "wave_loop", 4.0, 0, 0, 0, 0, 0);

	traning_start_player_area[0] = create_circle_pickup(1816.7122,2527.0825,15.8682, TRIGGER_LBLUE);	
	CreateDynamic3DTextLabel(""cWH"Местный Волонтёр\nСтартовая информация\n"cBLUE"[Встаньте на пикап]",-1, \
	1815.9315,2527.0491,15.8682, 7.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	

	// Вокзал Южный

	traning_start_player_actor[1] = CreateActor(105, 2738.6931,-2450.5815,21.8921,69.4935);
	ApplyActorAnimation(traning_start_player_actor[1], "ON_LOOKERS", "wave_loop", 4.0, 0, 0, 0, 0, 0);

	traning_start_player_area[1] = create_circle_pickup(2737.5999,-2450.1968,21.8921, TRIGGER_LBLUE);	
	CreateDynamic3DTextLabel(""cWH"Местный Волонтёр\nСтартовая информация\n"cBLUE"[Встаньте на пикап]",-1, \
	2738.6931,-2450.5815,21.8921, 7.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	

	// Вокзал Арзамас

	traning_start_player_actor[2] = CreateActor(105, -495.2296,918.9842,12.1426,229.3219);
	ApplyActorAnimation(traning_start_player_actor[2], "ON_LOOKERS", "wave_loop", 4.0, 0, 0, 0, 0, 0);

	traning_start_player_area[2] = create_circle_pickup(-494.5088,918.4429,12.1426, TRIGGER_LBLUE);	
	CreateDynamic3DTextLabel(""cWH"Местный Волонтёр\nСтартовая информация\n"cBLUE"[Встаньте на пикап]",-1, \
	-495.2296,918.9842,12.1426, 7.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	

	// Вокзал Гарель

	traning_start_player_actor[3] = CreateActor(105, -2468.8193,2829.8801,37.7199,42.6337);
	ApplyActorAnimation(traning_start_player_actor[3], "ON_LOOKERS", "wave_loop", 4.0, 0, 0, 0, 0, 0);

	traning_start_player_area[3] = create_circle_pickup(-2469.6929,2830.6875,37.7199, TRIGGER_LBLUE);	
	CreateDynamic3DTextLabel(""cWH"Местный Волонтёр\nСтартовая информация\n\n"cBLUE"[Встаньте на пикап]",-1, \
	-2468.8193,2829.8801,37.7199, 7.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	

	// Вокзал Южный

	traning_start_player_actor[4] = CreateActor(105, 2502.7126,-2116.5525,23.4458,153.9747);
	ApplyActorAnimation(traning_start_player_actor[4], "ON_LOOKERS", "wave_loop", 4.0, 0, 0, 0, 0, 0);

	traning_start_player_area[4] = create_circle_pickup(2502.3606,-2117.3716,23.4458, TRIGGER_LBLUE);	
	CreateDynamic3DTextLabel(""cWH"Местный Волонтёр\nСтартовая информация\n"cBLUE"[Встаньте на пикап]",-1, \
	2502.7126,-2116.5525,23.4458, 7.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	


	return true;
}

stock show_message_traning_player(playerid)
{

	return SPD(playerid, DIALOG_START_TRANING_PLAYER, DIALOG_STYLE_MSGBOX, !""cBLUE"Местный Волонтёр", !"\
	"cWH" — Привет! Я помогу тебе с основными моментами, которые помогут быстрее развиться в области!\n\n\
	Хочешь я тебе покажу основные моменты? Только самое основное и полезное для твоего старта в области!", !"Да", !"Нет");

}

stock spawn_player_traning_p(playerid)
{
	switch(GetPVarIntNew(playerid, "traning_position_spawn"))
	{
		case 1:
		{
			SetPlayerVirtualWorld(playerid, 0);

			new 
				hour, minute;

			gettime(hour, minute);
			SetPlayerTime(playerid, hour, minute);

			SetPlayerPosEx(playerid, 1820.9003,2526.1885,15.8682,83.8470);
			SetCameraBehindPlayer(playerid);
		}
		case 2:
		{
			SetPlayerVirtualWorld(playerid, 0);

			new 
				hour, minute;

			gettime(hour, minute);
			SetPlayerTime(playerid, hour, minute);

			SetPlayerPosEx(playerid, 2733.8367,-2449.4565,21.8921,265.4957);
			SetCameraBehindPlayer(playerid);
		}
		case 3:
		{
			SetPlayerVirtualWorld(playerid, 0);

			new 
				hour, minute;

			gettime(hour, minute);
			SetPlayerTime(playerid, hour, minute);

			SetPlayerPosEx(playerid, -491.2591,917.1140,12.1426,56.3306);
			SetCameraBehindPlayer(playerid);
		}
		case 4:
		{
			SetPlayerVirtualWorld(playerid, 0);

			new 
				hour, minute;

			gettime(hour, minute);
			SetPlayerTime(playerid, hour, minute);

			SetPlayerPosEx(playerid, -2471.8901,2832.6204,37.7199,220.2811);
			SetCameraBehindPlayer(playerid);
		}
		case 5:
		{
			SetPlayerVirtualWorld(playerid, 0);

			new 
				hour, minute;

			gettime(hour, minute);
			SetPlayerTime(playerid, hour, minute);

			SetPlayerPosEx(playerid, 2500.1836,-2119.8208,23.4458,302.5978);
			SetCameraBehindPlayer(playerid);
		}
	}

	return true;
}


stock start_traning_player_new(playerid)
{

	/*SetPVarIntNew(playerid, "start_traning_new", 1);

	show_info_gui(playerid, TEXTDRAW_HIDE);
	TogglePlayerAllHudElements(playerid, HUD_ELEMENT_HIDE);

	hide_hud_element(playerid);
	show_player_green_zone(playerid, TEXTDRAW_HIDE);

	SetPlayerTime(playerid, 19, 0);


	if(GetPVarIntNew(playerid, "start_traning_new") == 1)
	{
		TogglePlayerControllable(playerid, false);
		{
			hide_hud_element(playerid);
			show_player_green_zone(playerid, TEXTDRAW_HIDE);


			SetPlayerVirtualWorld(playerid, playerid + 1);

			PlayerTextDrawHideEx(playerid, start_traning_player_td[playerid]);
			create_traning_start_p(playerid);
			PlayerTextDrawSetString(playerid, start_traning_player_td[playerid], "brilliantother:notify_start_player_1");
			PlayerTextDrawShow(playerid, start_traning_player_td[playerid]);

			SetPlayerPos(playerid, -207.4146,125.1758,12.9062);

			InterpolateCameraPos(playerid, -243.423614, 118.100036, 25.509658, -410.854278, -29.390085, 41.229286, 10000);
			InterpolateCameraLookAt(playerid, -240.989257, 114.288330, 27.641498, -406.688018, -28.478370, 43.839092, 10000);
			
		}
		wait_ms(15000);
		{
			hide_hud_element(playerid);
			show_player_green_zone(playerid, TEXTDRAW_HIDE);


			SetPlayerVirtualWorld(playerid, playerid + 1);

			PlayerTextDrawHideEx(playerid, start_traning_player_td[playerid]);
			create_traning_start_p(playerid);
			PlayerTextDrawSetString(playerid, start_traning_player_td[playerid], "brilliantother:notify_start_player_2");
			PlayerTextDrawShow(playerid, start_traning_player_td[playerid]);

			SetPlayerPos(playerid, -1361.9115,2651.0073,40.6163);

			InterpolateCameraPos(playerid, 	  -1439.668334, 2515.652343, 44.968540, -1383.169067, 2651.691162, 41.499298, 5000);
			InterpolateCameraLookAt(playerid, -1436.651855, 2519.637695, 44.837123, -1378.189697, 2651.298095, 41.273445, 5000);

			wait_ms(5000);

			SetPlayerPos(playerid, -734.9658,-2737.6292,-25.0555);

			InterpolateCameraPos(playerid, 	  -761.623291, -2733.792480, -21.262165, -759.953552, -2742.914794, -21.555133, 5000);
			InterpolateCameraLookAt(playerid, -756.924377, -2732.170654, -21.800525, -755.715454, -2745.527343, -22.017099, 5000);		

			wait_ms(5000);

			InterpolateCameraPos(playerid, 	  -755.572570, -2740.551025, -20.411281, -769.903808, -2732.197998, -20.411281, 5000);
			InterpolateCameraLookAt(playerid, -759.910644, -2742.898437, -21.230478, -768.270080, -2736.828857, -21.352569, 5000);		

			wait_ms(5000);

			InterpolateCameraPos(playerid, 	  -761.649047, -2769.778320, -17.724004, -756.662719, -2779.185546, -19.536123, 5000);
			InterpolateCameraLookAt(playerid, -757.557678, -2772.415283, -18.867454, -757.951965, -2774.373046, -19.956907, 5000);		

			wait_ms(5000);

			SetPlayerPos(playerid, -1430.9869,2547.3252,40.7999);

			InterpolateCameraPos(playerid, 	  -1366.693847, 2594.258789, 42.416496, -1479.359741, 2566.373779, 45.953201, 5000);
			InterpolateCameraLookAt(playerid, -1369.490966, 2590.121337, 42.177532, -1474.493164, 2566.022949, 44.860717, 5000);				
		}
		wait_ms(5000);
		{
			hide_hud_element(playerid);
			show_player_green_zone(playerid, TEXTDRAW_HIDE);


			SetPlayerVirtualWorld(playerid, playerid + 1);

			PlayerTextDrawHideEx(playerid, start_traning_player_td[playerid]);
			create_traning_start_p(playerid);
			PlayerTextDrawSetString(playerid, start_traning_player_td[playerid], "brilliantother:notify_start_player_3");
			PlayerTextDrawShow(playerid, start_traning_player_td[playerid]);

			SetPlayerPos(playerid, 2338.2559,1982.7424,15.9256);

			InterpolateCameraPos(playerid, 	  2336.101562, 1990.353393, 18.955106, 2329.887695, 2037.615356, 17.003801, 5000);
			InterpolateCameraLookAt(playerid, 2333.255371, 1994.446166, 18.569644, 2325.188476, 2035.910400, 16.901464, 5000);

			wait_ms(5000);

			SetPlayerPos(playerid, 694.8629,1270.7996,1746.3715);

			InterpolateCameraPos(playerid, 	  705.126342, 1286.084350, 1747.636718, 660.397460, 1255.950805, 1751.150756, 5000);
			InterpolateCameraLookAt(playerid, 700.519836, 1284.168701, 1747.304321, 658.487915, 1260.441040, 1750.059082, 5000);

		}
		wait_ms(7500);
		{
			hide_hud_element(playerid);
			show_player_green_zone(playerid, TEXTDRAW_HIDE);


			SetPlayerVirtualWorld(playerid, playerid + 1);

			PlayerTextDrawHideEx(playerid, start_traning_player_td[playerid]);
			create_traning_start_p(playerid);
			PlayerTextDrawSetString(playerid, start_traning_player_td[playerid], "brilliantother:notify_start_player_4");
			PlayerTextDrawShow(playerid, start_traning_player_td[playerid]);

			SetPlayerPos(playerid, -1023.3693,-2479.0676,28.5196);

			InterpolateCameraPos(playerid, 	  -1026.969726, -2463.823974, 29.221086, -1046.061767, -2507.982910, 29.473449, 5000);
			InterpolateCameraLookAt(playerid, -1030.223999, -2467.593261, 28.771883, -1049.803100, -2504.673095, 29.254055, 5000);

		}
		wait_ms(10000);
		{
			hide_hud_element(playerid);
			show_player_green_zone(playerid, TEXTDRAW_HIDE);


			SetPlayerVirtualWorld(playerid, playerid + 1);

			PlayerTextDrawHideEx(playerid, start_traning_player_td[playerid]);
			create_traning_start_p(playerid);
			PlayerTextDrawSetString(playerid, start_traning_player_td[playerid], "brilliantother:notify_start_player_5");
			PlayerTextDrawShow(playerid, start_traning_player_td[playerid]);

			SetPlayerPos(playerid, -513.8035,34.8461,13.7661);

			InterpolateCameraPos(playerid, 	  -583.155944, 11.695520, 19.312120, -498.665222, 10.764976, 15.126384, 5000);
			InterpolateCameraLookAt(playerid, -578.577880, 13.644605, 18.819648, -501.865386, 14.606686, 15.111518, 5000);

		}
		wait_ms(10000);
		{
			hide_hud_element(playerid);
			show_player_green_zone(playerid, TEXTDRAW_HIDE);


			SetPlayerVirtualWorld(playerid, playerid + 1);

			PlayerTextDrawHideEx(playerid, start_traning_player_td[playerid]);
			create_traning_start_p(playerid);
			PlayerTextDrawSetString(playerid, start_traning_player_td[playerid], "brilliantother:notify_start_player_6");
			PlayerTextDrawShow(playerid, start_traning_player_td[playerid]);

			SetPlayerPos(playerid, -82.8815,967.0071,1597.9788);

			InterpolateCameraPos(playerid, 	  -84.345375, 944.867004, 1599.052368, -64.597625, 950.470520, 1598.620849, 5000);
			InterpolateCameraLookAt(playerid, -80.609649, 948.190246, 1599.036376, -66.667602, 955.016723, 1598.404052, 5000);

		}	
		wait_ms(10000);
		{
			hide_hud_element(playerid);
			show_player_green_zone(playerid, TEXTDRAW_HIDE);


			SetPlayerVirtualWorld(playerid, playerid + 1);

			PlayerTextDrawHideEx(playerid, start_traning_player_td[playerid]);
			create_traning_start_p(playerid);
			PlayerTextDrawSetString(playerid, start_traning_player_td[playerid], "brilliantother:notify_start_player_7");
			PlayerTextDrawShow(playerid, start_traning_player_td[playerid]);

			SetPlayerPos(playerid, -655.1673,-708.0502,1201.9475);

			InterpolateCameraPos(playerid, 	  -647.430236, -710.997558, 1202.007568, -654.893737, -712.196289, 1202.766235, 5000);
			InterpolateCameraLookAt(playerid, -650.218200, -715.146911, 1201.906372, -652.470581, -716.464111, 1203.722167, 5000);

		}	
		wait_ms(10000);
		{
			hide_hud_element(playerid);
			show_player_green_zone(playerid, TEXTDRAW_HIDE);


			SetPlayerVirtualWorld(playerid, playerid + 1);

			PlayerTextDrawHideEx(playerid, start_traning_player_td[playerid]);
			create_traning_start_p(playerid);
			PlayerTextDrawSetString(playerid, start_traning_player_td[playerid], "brilliantother:notify_start_player_8");
			PlayerTextDrawShow(playerid, start_traning_player_td[playerid]);

			SetPlayerPos(playerid, 2335.1462,-1780.7656,22.4466);

			InterpolateCameraPos(playerid, 	  2309.299804, -1765.162719, 26.339733, 2322.760009, -1811.329345, 23.055465, 5000);
			InterpolateCameraLookAt(playerid, 2311.426513, -1769.660400, 25.842494, 2325.462158, -1807.125244, 22.899991, 5000);

		}	
		wait_ms(7500);
		{
			hide_hud_element(playerid);
			show_player_green_zone(playerid, TEXTDRAW_HIDE);


			SetPlayerVirtualWorld(playerid, playerid + 1);

			PlayerTextDrawHideEx(playerid, start_traning_player_td[playerid]);
			create_traning_start_p(playerid);
			PlayerTextDrawSetString(playerid, start_traning_player_td[playerid], "brilliantother:notify_start_player_8");
			PlayerTextDrawShow(playerid, start_traning_player_td[playerid]);

			SetPlayerPos(playerid, 430.9051,2210.5588,12.0003);

			InterpolateCameraPos(playerid, 	  458.005249, 2160.768310, 14.489968, 471.083923, 2211.601318, 12.928493, 5000);
			InterpolateCameraLookAt(playerid, 456.836608, 2165.617187, 14.139848, 466.230468, 2210.399902, 12.908837, 5000);

		}	
		wait_ms(7500);
		{
			hide_hud_element(playerid);
			show_player_green_zone(playerid, TEXTDRAW_HIDE);


			SetPlayerVirtualWorld(playerid, playerid + 1);

			PlayerTextDrawHideEx(playerid, start_traning_player_td[playerid]);
			create_traning_start_p(playerid);
			PlayerTextDrawSetString(playerid, start_traning_player_td[playerid], "brilliantother:notify_start_player_8");
			PlayerTextDrawShow(playerid, start_traning_player_td[playerid]);

			SetPlayerPos(playerid, 407.7907,1189.8398,12.0080);

			InterpolateCameraPos(playerid, 	  404.626220, 1174.457031, 17.000356, 465.553314, 1128.352539, 16.003871, 5000);
			InterpolateCameraLookAt(playerid, 409.082855, 1176.714233, 16.791761, 463.432586, 1132.879516, 15.907440, 5000);

		}	

		wait_ms(7500);
		{
			hide_hud_element(playerid);
			show_player_green_zone(playerid, TEXTDRAW_HIDE);


			SetPlayerVirtualWorld(playerid, playerid + 1);

			PlayerTextDrawHideEx(playerid, start_traning_player_td[playerid]);
			create_traning_start_p(playerid);
			PlayerTextDrawSetString(playerid, start_traning_player_td[playerid], "brilliantother:notify_start_player_9");
			PlayerTextDrawShow(playerid, start_traning_player_td[playerid]);

			SetPlayerPos(playerid, -425.6490,691.4042,12.1529);

			InterpolateCameraPos(playerid, 	  -389.075958, 652.122253, 13.867780, -459.128204, 657.316528, 14.757114, 5000);
			InterpolateCameraLookAt(playerid, -391.471252, 647.733459, 13.836312, -455.753326, 661.004455, 14.660682, 5000);

		}
		wait_ms(7500);
		{
			hide_hud_element(playerid);
			show_player_green_zone(playerid, TEXTDRAW_HIDE);


			SetPlayerVirtualWorld(playerid, playerid + 1);

			PlayerTextDrawHideEx(playerid, start_traning_player_td[playerid]);
			create_traning_start_p(playerid);
			PlayerTextDrawSetString(playerid, start_traning_player_td[playerid], "brilliantother:notify_start_player_9");
			PlayerTextDrawShow(playerid, start_traning_player_td[playerid]);

			SetPlayerPos(playerid, 795.1289,2372.7324,12.2500);

			InterpolateCameraPos(playerid, 	  754.791687, 2370.373779, 13.245414, 786.234313, 2347.273925, 12.952423, 5000);
			InterpolateCameraLookAt(playerid, 759.727722, 2369.618896, 12.989621, 787.486145, 2352.114013, 12.879613, 5000);

		}
		wait_ms(7500);
		{
			hide_hud_element(playerid);
			show_player_green_zone(playerid, TEXTDRAW_HIDE);


			SetPlayerVirtualWorld(playerid, playerid + 1);

			PlayerTextDrawHideEx(playerid, start_traning_player_td[playerid]);
			create_traning_start_p(playerid);
			PlayerTextDrawSetString(playerid, start_traning_player_td[playerid], "brilliantother:notify_start_player_10");
			PlayerTextDrawShow(playerid, start_traning_player_td[playerid]);

			SetPlayerPos(playerid, 554.7053,296.5608,12.3440);

			InterpolateCameraPos(playerid, 	  576.658081, 331.778900, 17.592596, 512.845520, 309.616729, 14.605122, 5000);
			InterpolateCameraLookAt(playerid, 572.716247, 328.706146, 17.451213, 516.782897, 306.537139, 14.490976, 5000);

		}
		wait_ms(7500);
		{
			hide_hud_element(playerid);
			show_player_green_zone(playerid, TEXTDRAW_HIDE);


			SetPlayerVirtualWorld(playerid, playerid + 1);

			PlayerTextDrawHideEx(playerid, start_traning_player_td[playerid]);
			create_traning_start_p(playerid);
			PlayerTextDrawSetString(playerid, start_traning_player_td[playerid], "brilliantother:notify_start_player_10");
			PlayerTextDrawShow(playerid, start_traning_player_td[playerid]);

			SetPlayerPos(playerid, 1889.2202,1736.1611,15.5142);

			InterpolateCameraPos(playerid, 	  1894.952636, 1720.367553, 17.117784, 1771.290771, 1729.294555, 19.545900, 5000);
			InterpolateCameraLookAt(playerid, 1891.247680, 1723.723388, 17.007276, 1774.921264, 1732.721435, 19.270149, 5000);

		}
		wait_ms(7500);
		{
			hide_hud_element(playerid);
			show_player_green_zone(playerid, TEXTDRAW_HIDE);


			SetPlayerVirtualWorld(playerid, playerid + 1);

			PlayerTextDrawHideEx(playerid, start_traning_player_td[playerid]);
			create_traning_start_p(playerid);
			PlayerTextDrawSetString(playerid, start_traning_player_td[playerid], "brilliantother:notify_start_player_11");
			PlayerTextDrawShow(playerid, start_traning_player_td[playerid]);

			SetPlayerPos(playerid, 158.1105,1272.3511,11.6780);

			InterpolateCameraPos(playerid, 	  132.042129, 1308.431518, 16.163982, 121.524902, 1247.071655, 15.641527, 5000);
			InterpolateCameraLookAt(playerid, 134.415023, 1304.032226, 16.039470, 125.607482, 1249.958129, 15.611502, 5000);

		}
		wait_ms(7500);
		{
			hide_hud_element(playerid);
			show_player_green_zone(playerid, TEXTDRAW_HIDE);


			SetPlayerVirtualWorld(playerid, playerid + 1);

			PlayerTextDrawHideEx(playerid, start_traning_player_td[playerid]);
			create_traning_start_p(playerid);
			PlayerTextDrawSetString(playerid, start_traning_player_td[playerid], "brilliantother:notify_start_player_11");
			PlayerTextDrawShow(playerid, start_traning_player_td[playerid]);

			SetPlayerPos(playerid, 76.5378,-994.0663,1207.7563);

			InterpolateCameraPos(playerid, 	  90.162742, -953.751586, 1208.775146, 67.692405, -955.502319, 1209.710815, 5000);
			InterpolateCameraLookAt(playerid, 87.858161, -958.120727, 1209.549560, 69.311019, -960.232788, 1209.761840, 5000);

		}
		wait_ms(5000);
		{

			show_player_green_zone(playerid, TEXTDRAW_SHOW);

			show_hud_element(playerid);
			show_hud_hungry(playerid);

			show_info_gui(playerid, TEXTDRAW_SHOW);

			TogglePlayerAllHudElements(playerid, HUD_ELEMENT_SHOW);

			PlayerTextDrawHideEx(playerid, start_traning_player_td[playerid]);
			spawn_player_traning_p(playerid);
		}
	}*/
	return true;

}