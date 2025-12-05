
#define REG_LOGIN_FILMS_0		0	// Дальнобойщики
#define REG_LOGIN_FILMS_1		1	// Дальнобойщики
#define REG_LOGIN_FILMS_2		2	// ОПГ
#define REG_LOGIN_FILMS_3		3	// Обычные жители
#define REG_LOGIN_FILMS_4		4	// Гопники, бабка, менты
#define REG_LOGIN_FILMS_5		5	// 

#define REG_LOGIN_FILMS_6		6
#define REG_LOGIN_FILMS_7		7
#define REG_LOGIN_FILMS_8		8
#define REG_LOGIN_FILMS_9		9
#define REG_LOGIN_FILMS_10		10
#define REG_LOGIN_FILMS_11		11

new 
	actor_trucker_films[3],
	actor_gop_films[7],
	actor_newyear[2],
	actor_mafia_films[2];

stock random_reg_login_films(playerid)
{

	new 
		random_films_player;

	random_films_player = RandomEx(0,11);

	switch(random_films_player)
	{
		case REG_LOGIN_FILMS_0:
		{
			SetPVarIntNew(playerid, "camera_interactive_random", REG_LOGIN_FILMS_0);
		}
		case REG_LOGIN_FILMS_1:
		{
			SetPVarIntNew(playerid, "camera_interactive_random", REG_LOGIN_FILMS_1);
		}
		case REG_LOGIN_FILMS_2:
		{
			SetPVarIntNew(playerid, "camera_interactive_random", REG_LOGIN_FILMS_2);			
		}
		case REG_LOGIN_FILMS_3:
		{
			SetPVarIntNew(playerid, "camera_interactive_random", REG_LOGIN_FILMS_3);			
		}
		case REG_LOGIN_FILMS_4:
		{
			SetPVarIntNew(playerid, "camera_interactive_random", REG_LOGIN_FILMS_4);			
		}
		case REG_LOGIN_FILMS_5:
		{
			SetPVarIntNew(playerid, "camera_interactive_random", REG_LOGIN_FILMS_5);			
		}
		case REG_LOGIN_FILMS_6:
		{
			SetPVarIntNew(playerid, "camera_interactive_random", REG_LOGIN_FILMS_6);
		}
		case REG_LOGIN_FILMS_7:
		{
			SetPVarIntNew(playerid, "camera_interactive_random", REG_LOGIN_FILMS_7);
		}
		case REG_LOGIN_FILMS_8:
		{
			SetPVarIntNew(playerid, "camera_interactive_random", REG_LOGIN_FILMS_8);
		}
		case REG_LOGIN_FILMS_9:
		{
			SetPVarIntNew(playerid, "camera_interactive_random", REG_LOGIN_FILMS_9);
		}
		case REG_LOGIN_FILMS_10:
		{
			SetPVarIntNew(playerid, "camera_interactive_random", REG_LOGIN_FILMS_10);	
		}
		case REG_LOGIN_FILMS_11:
		{
			SetPVarIntNew(playerid, "camera_interactive_random", REG_LOGIN_FILMS_11);	
		}
	}
	return true;

}

stock load_reg_login_other()
{
	// Мафии
	AddPlayerClass(282,2430.0579,-1922.6992,22.0043,88.3143,0,0,0,0,0,0); // 
	AddPlayerClass(282,2427.5715,-1922.5254,22.0043,270.9912,0,0,0,0,0,0); // 


	// Мафии 2
	AddPlayerClass(264,-1557.3192,-1544.3556,52.9762,273.8287,0,0,0,0,0,0); // 
	AddPlayerClass(264,-1557.1825,-1539.8215,53.7389,228.4827,0,0,0,0,0,0); // 
	AddPlayerClass(264,-1554.7352,-1543.3408,53.1103,93.6257,0,0,0,0,0,0); // 



	actor_trucker_films[0] = CreateActor(32, 1877.5677,2896.1897,12.5645,218.8439);
	SetActorVirtualWorld(actor_trucker_films[0], 520);
	actor_trucker_films[1] = CreateActor(44, 1877.0070,2893.6230,12.5645,270.5281);
	SetActorVirtualWorld(actor_trucker_films[1], 520);
	actor_trucker_films[2] = CreateActor(58, 1879.3339,2893.9746,12.5721,40.6944);
	SetActorVirtualWorld(actor_trucker_films[2], 520);
	ApplyActorAnimation(actor_trucker_films[0],  "PED", "IDLE_CHAT", 4.1, 1, 1, 1, 0, 0);
	ApplyActorAnimation(actor_trucker_films[1],  "PED", "IDLE_CHAT", 4.1, 1, 1, 1, 0, 0);
	ApplyActorAnimation(actor_trucker_films[2],  "PED", "IDLE_HBHB", 4.1, 1, 1, 1, 0, 0);


	// Мафии
	actor_mafia_films[0] = CreateActor(32, 2430.0579,-1922.6992,22.0043,88.3143);
	SetActorVirtualWorld(actor_mafia_films[0], 520);
	actor_mafia_films[1] = CreateActor(44, 2427.5715,-1922.5254,22.0043,270.9912);
	SetActorVirtualWorld(actor_mafia_films[1], 520);

	ApplyActorAnimation(actor_mafia_films[0],  "PED", "IDLE_CHAT", 4.1, 1, 1, 1, 0, 0);
	ApplyActorAnimation(actor_mafia_films[1],  "PED", "IDLE_CHAT", 4.1, 1, 1, 1, 0, 0);


	actor_gop_films[0] = CreateActor(102,-1557.3192,-1544.3556,52.9762,273.8287);
	SetActorVirtualWorld(actor_gop_films[0], 521);
	actor_gop_films[1] = CreateActor(47,-1557.1825,-1539.8215,53.7389,228.4827);
	SetActorVirtualWorld(actor_gop_films[1], 521);
	actor_gop_films[2] = CreateActor(103,-1554.7352,-1543.3408,53.1103,93.6257);
	SetActorVirtualWorld(actor_gop_films[2], 521);
	ApplyActorAnimation(actor_gop_films[2],  "CRACK", "CRCKIDLE2", 4.1, 1, 1, 1, 0, 0);
	ApplyActorAnimation(actor_gop_films[0],  "PED", "IDLE_CHAT", 4.1, 1, 1, 1, 0, 0);
	ApplyActorAnimation(actor_gop_films[1],  "benchpress", "benchpress", 4.1, 1, 1, 1, 0, 0);


	return true;
}

stock login_films_people_trucker(playerid)
{
	PlayerTextDrawHideEx(playerid, background_login[playerid]);
	create_background_login(playerid);
	PlayerTextDrawSetString(playerid, background_login[playerid], "brilliantother:authback_1");	
	PlayerTextDrawShow(playerid, background_login[playerid]);			


	SetPlayerVirtualWorld(playerid, 520);


	SetPlayerPos(playerid, 1873.7264,2902.4497,12.5645);
	Streamer_Update(playerid);
 	Streamer_UpdateEx(playerid, 1873.7264,2902.4497,12.5645);

	return true;
}

stock login_films_people_trucker_cam(playerid)
{
	InterpolateCameraPos(playerid, 1841.014404, 2913.041992, 13.850955, 1874.873901, 2886.752441, 13.329283, 7500);
	InterpolateCameraLookAt(playerid, 1844.025634, 2909.055175, 13.657309, 1877.280761, 2891.133789, 13.226552, 7500);

	return true;
}


stock login_films_other_1(playerid)
{
	PlayerTextDrawHideEx(playerid, background_login[playerid]);
	create_background_login(playerid);
	PlayerTextDrawSetString(playerid, background_login[playerid], "brilliantother:authback_3");	
	PlayerTextDrawShow(playerid, background_login[playerid]);			


	SetPlayerPos(playerid, 2691.8599,-2534.6326,21.9675);
	Streamer_Update(playerid);
 	Streamer_UpdateEx(playerid, 2691.8599,-2534.6326,21.9675);	
 	return true;
}

stock login_films_other_1_cam(playerid)
{
	InterpolateCameraPos(playerid, 		2670.926513, -2556.123535, 32.987522, 2689.853515, -2512.552001, 32.408279, 10000);
	InterpolateCameraLookAt(playerid, 	2674.808837, -2552.980468, 32.764442, 2690.514404, -2517.035400, 34.520488, 10000);	
	return true;	
}

stock login_films_other_2(playerid)
{
	PlayerTextDrawHideEx(playerid, background_login[playerid]);
	create_background_login(playerid);
	PlayerTextDrawSetString(playerid, background_login[playerid], "brilliantother:authback_3");	
	PlayerTextDrawShow(playerid, background_login[playerid]);	

	SetPlayerPos(playerid, 1992.4248,1945.7023,15.5245);
	Streamer_Update(playerid);
 	Streamer_UpdateEx(playerid, 1992.4248,1945.7023,15.5245);	
 	return true;
}

stock login_films_other_2_cam(playerid)
{
	InterpolateCameraPos(playerid, 		1979.241455, 1908.938842, 19.276975, 1988.678588, 1945.092163, 20.858890, 10000);
	InterpolateCameraLookAt(playerid, 	1983.380981, 1911.736694, 19.086082, 1990.906127, 1940.642822, 20.367527, 10000);	
	return true;	
}

stock login_films_other_3(playerid)
{
	PlayerTextDrawHideEx(playerid, background_login[playerid]);
	create_background_login(playerid);
	PlayerTextDrawSetString(playerid, background_login[playerid], "brilliantother:authback_3");	
	PlayerTextDrawShow(playerid, background_login[playerid]);	

	SetPlayerPos(playerid, -522.2507,41.4307,13.7661);
	Streamer_Update(playerid);
 	Streamer_UpdateEx(playerid, -522.2507,41.4307,13.7661);	
 	return true;
}

stock login_films_other_3_cam(playerid)
{
	InterpolateCameraPos(playerid, 		-430.760528, -67.725921, 5.174968, -538.380920, 7.687363, 16.862585, 5000);
	InterpolateCameraLookAt(playerid, 	-434.692291, -70.808403, 5.373793, -533.968811, 10.038180, 16.777967, 5000);	
	return true;	
}


stock login_films_work_1(playerid)
{
	PlayerTextDrawHideEx(playerid, background_login[playerid]);
	create_background_login(playerid);
	PlayerTextDrawSetString(playerid, background_login[playerid], "brilliantother:authback_1");	
	PlayerTextDrawShow(playerid, background_login[playerid]);			


	SetPlayerPos(playerid, 2312.8035,2013.6139,15.9863);
	Streamer_Update(playerid);
 	Streamer_UpdateEx(playerid, 2312.8035,2013.6139,15.9863);	
 	return true;
}

stock login_films_work_1_cam(playerid)
{
	InterpolateCameraPos(playerid, 		2362.184326, 1936.886474, 18.776348, 2370.350341, 2127.006347, 28.839859, 5000);
	InterpolateCameraLookAt(playerid, 	2360.841552, 1941.699462, 18.597261, 2366.620117, 2123.749267, 28.149105, 5000);	
	return true;	
}

stock login_films_work_2(playerid)
{
	PlayerTextDrawHideEx(playerid, background_login[playerid]);
	create_background_login(playerid);
	PlayerTextDrawSetString(playerid, background_login[playerid], "brilliantother:authback_1");	
	PlayerTextDrawShow(playerid, background_login[playerid]);			


	SetPlayerPos(playerid, -2209.5840,-2690.8276,19.9134);
	Streamer_Update(playerid);
 	Streamer_UpdateEx(playerid, -2209.5840,-2690.8276,19.9134);	
 	return true;
}

stock login_films_work_2_cam(playerid)
{
	InterpolateCameraPos(playerid, 		-2185.270019, -2664.240966, 22.396242, -2101.961669, -2666.059570, 33.926906, 5000);
	InterpolateCameraLookAt(playerid, 	-2188.437011, -2668.107910, 22.264381, -2098.472167, -2669.639404, 34.013557, 5000);	
	return true;	
}



stock login_films_money_all_1(playerid)
{
	PlayerTextDrawHideEx(playerid, background_login[playerid]);
	create_background_login(playerid);
	PlayerTextDrawSetString(playerid, background_login[playerid], "brilliantother:authback_4");	
	PlayerTextDrawShow(playerid, background_login[playerid]);	

	SetPlayerPos(playerid, 1127.6895,2247.1016,12.1484);
	Streamer_Update(playerid);
 	Streamer_UpdateEx(playerid, 1127.6895,2247.1016,12.1484);	
 	return true;
}

stock login_films_money_all_1_cam(playerid)
{
	InterpolateCameraPos(playerid, 		1060.125610, 2210.946533, 15.930566, 1149.844726, 2350.618652, 15.648924, 5000);
	InterpolateCameraLookAt(playerid, 	1055.879882, 2213.586425, 15.993596, 1152.132202, 2346.174316, 15.528873, 5000);	
	return true;	
}

stock login_films_money_all_2(playerid)
{
	PlayerTextDrawHideEx(playerid, background_login[playerid]);
	create_background_login(playerid);
	PlayerTextDrawSetString(playerid, background_login[playerid], "brilliantother:authback_4");	
	PlayerTextDrawShow(playerid, background_login[playerid]);	

	SetPlayerPos(playerid, -314.2175,-64.9515,13.9821);
	Streamer_Update(playerid);
 	Streamer_UpdateEx(playerid, -314.2175,-64.9515,13.9821);	
 	return true;
}

stock login_films_money_all_2_cam(playerid)
{
	InterpolateCameraPos(playerid, 		-366.785491, -27.419353, 17.317237, -339.515808, -175.553497, 14.726824, 5000);
	InterpolateCameraLookAt(playerid, 	-362.337554, -25.148838, 17.563264, -336.081848, -172.056579, 15.716466, 5000);	
	return true;	
}


stock login_films_police_1(playerid)
{
	PlayerTextDrawHideEx(playerid, background_login[playerid]);
	create_background_login(playerid);
	PlayerTextDrawSetString(playerid, background_login[playerid], "brilliantother:authback_5");	
	PlayerTextDrawShow(playerid, background_login[playerid]);	

	SetPlayerPos(playerid, 530.0358,305.9001,13.6113);
	Streamer_Update(playerid);
 	Streamer_UpdateEx(playerid, 530.0358,305.9001,13.6113);	
 	return true;
}

stock login_films_police_1_cam(playerid)
{
	InterpolateCameraPos(playerid, 		490.945220, 307.426147, 14.459213, 567.549804, 335.958221, 15.310497, 5000);
	InterpolateCameraLookAt(playerid, 	494.290252, 303.712493, 14.599066, 563.858520, 332.587432, 15.420829, 5000);	
	return true;	
}

stock login_films_police_2(playerid)
{
	PlayerTextDrawHideEx(playerid, background_login[playerid]);
	create_background_login(playerid);
	PlayerTextDrawSetString(playerid, background_login[playerid], "brilliantother:authback_5");	
	PlayerTextDrawShow(playerid, background_login[playerid]);	

	SetPlayerPos(playerid, 160.8110,1265.8079,11.6848);
	Streamer_Update(playerid);
 	Streamer_UpdateEx(playerid, 160.8110,1265.8079,11.6848);	
 	return true;
}

stock login_films_police_2_cam(playerid)
{
	InterpolateCameraPos(playerid, 		130.693420, 1324.730957, 16.039289, 130.451293, 1254.997802, 13.790443, 5000);
	InterpolateCameraLookAt(playerid, 	131.791717, 1319.855590, 15.884084, 135.008438, 1256.881469, 14.617734, 5000);	
	return true;	
}



stock login_films_people_gop1(playerid)
{
	SetPlayerVirtualWorld(playerid, 520);
	PlayerTextDrawHideEx(playerid, background_login[playerid]);
	create_background_login(playerid);
	PlayerTextDrawSetString(playerid, background_login[playerid], "brilliantother:authback_2");	
	PlayerTextDrawShow(playerid, background_login[playerid]);	

	SetPlayerPos(playerid, 2413.7847,-1937.0017,22.0043);
	Streamer_Update(playerid);
 	Streamer_UpdateEx(playerid, 2413.7847,-1937.0017,22.0043);

 	return true;

}
stock login_films_people_gop_cam1(playerid)
{
	InterpolateCameraPos(playerid,    2436.504394, -1943.153320, 23.116815, 2431.630859, -1927.288085, 22.495494, 5000);
	InterpolateCameraLookAt(playerid, 2434.039306, -1938.820190, 22.732294, 2429.083496, -1922.989501, 22.311447, 5000);	

	return true;
}

stock login_films_people_gop(playerid)
{
	SetPlayerVirtualWorld(playerid, 521);
	PlayerTextDrawHideEx(playerid, background_login[playerid]);
	create_background_login(playerid);
	PlayerTextDrawSetString(playerid, background_login[playerid], "brilliantother:authback_2");	
	PlayerTextDrawShow(playerid, background_login[playerid]);	

	SetPlayerPos(playerid, -1562.5261,-1554.7915,62.0879);
	Streamer_Update(playerid);
 	Streamer_UpdateEx(playerid, -1562.5261,-1554.7915,62.0879);

 	return true;

}
stock login_films_people_gop_cam(playerid)
{
	InterpolateCameraPos(playerid,    -1552.524536, -1554.137695, 53.260154, -1550.850219, -1542.161132, 53.573680, 5000);
	InterpolateCameraLookAt(playerid, -1557.454101, -1553.366210, 52.936943, -1555.838378, -1541.839965, 53.451068, 5000);	

	return true;
}

stock get_player_situation_l_r_s(playerid)
{
	new 
		type = GetPVarIntNew(playerid, "camera_interactive_random");

	switch(type)
	{
		case REG_LOGIN_FILMS_0:
		{
			login_films_people_trucker(playerid);
		}
		case REG_LOGIN_FILMS_1:
		{
			login_films_people_gop(playerid);
		}
		case REG_LOGIN_FILMS_2:
		{
			login_films_people_gop1(playerid);
		}
		case REG_LOGIN_FILMS_3:
		{
			login_films_other_1(playerid);	
		}
		case REG_LOGIN_FILMS_4:
		{
			login_films_other_2(playerid);
		}
		case REG_LOGIN_FILMS_5:
		{
			login_films_other_3(playerid);
		}
		case REG_LOGIN_FILMS_6:
		{
			login_films_work_1(playerid);
		}
		case REG_LOGIN_FILMS_7:
		{
			login_films_work_2(playerid);
		}
		case REG_LOGIN_FILMS_8:
		{
			login_films_money_all_1(playerid);
		}
		case REG_LOGIN_FILMS_9:
		{
			login_films_money_all_2(playerid);
		}
		case REG_LOGIN_FILMS_10:
		{
			login_films_police_2(playerid);
		}
		case REG_LOGIN_FILMS_11:
		{
			login_films_police_1(playerid);
		}
	}
}

stock get_player_camera_l_r(playerid)
{

	new 
		type = GetPVarIntNew(playerid, "camera_interactive_random");


	switch(type)
	{
		case REG_LOGIN_FILMS_0:
		{
			login_films_people_trucker_cam(playerid);
		}
		case REG_LOGIN_FILMS_1:
		{
			login_films_other_1_cam(playerid);
		}
		case REG_LOGIN_FILMS_2:
		{
			login_films_other_1_cam(playerid);
		}
		case REG_LOGIN_FILMS_3:
		{
			login_films_other_1_cam(playerid);	
		}
		case REG_LOGIN_FILMS_4:
		{
			login_films_other_2_cam(playerid);
		}
		case REG_LOGIN_FILMS_5:
		{
			login_films_other_3_cam(playerid);
		}
		case REG_LOGIN_FILMS_6:
		{
			login_films_work_1_cam(playerid);
		}
		case REG_LOGIN_FILMS_7:
		{
			login_films_work_2_cam(playerid);
		}
		case REG_LOGIN_FILMS_8:
		{
			login_films_money_all_1_cam(playerid);
		}
		case REG_LOGIN_FILMS_9:
		{
			login_films_money_all_2_cam(playerid);
		}
		case REG_LOGIN_FILMS_10:
		{
			login_films_police_2_cam(playerid);
		}
		case REG_LOGIN_FILMS_11:
		{
			login_films_police_1_cam(playerid);
		}					
	}
	return true;
}



