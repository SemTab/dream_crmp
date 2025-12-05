
static const Float:position_catok_newyear_1[][] =
{
	{975.6319,953.4263,12.2680},
	{981.3687,947.5742,12.3043},
	{989.1412,939.5292,12.3203},
	{999.0464,931.5051,12.3166},
	{1011.4417,930.1907,12.3203},
	{1025.6139,928.5055,12.3153},
	{1036.2950,924.6295,12.3148},
	{1046.8455,918.2263,12.3104},
	{1057.2996,912.5061,12.3021}
};

static const Float:position_catok_newyear_2[][] =
{
	{984.7210,968.6148,12.2693},
	{995.4222,965.6918,12.3158},
	{1006.4993,963.2040,12.3126},
	{1017.4883,959.6728,12.3126},
	{1027.5569,955.7930,12.3203},
	{1037.6821,950.4391,12.3203},
	{1050.4187,947.0470,12.3112},
	{1060.9722,944.3126,12.3065},
	{1068.7163,942.3935,12.7004}

};

static const Float:position_catok_newyear_3[][] =
{
	{1122.8602,955.5403,12.3071},
	{1121.5890,965.0917,12.3066},
	{1118.2301,972.2742,12.3131},
	{1125.8361,976.6636,12.3036},
	{1113.5624,980.5266,12.4893},
	{1112.8008,990.6758,12.3126},
	{1116.8679,1001.9639,12.3123},
	{1121.7611,1014.4874,12.6377},
	{1125.5820,1025.7844,12.3199},
	{1134.3998,1032.9073,12.3174},
	{1145.1514,1032.7657,12.3149},
	{1156.7125,1029.9355,12.3203},
	{1168.2738,1026.7313,12.3184},
	{1178.2427,1022.1840,12.3281},
	{1186.1741,1014.9503,12.3203},
	{1190.8383,1004.7246,12.3203},
	{1192.0938,993.4901,12.3203},
	{1191.2075,981.9523,12.3203},
	{1190.1395,970.3696,12.3203},
	{1187.8431,959.1688,12.3203},
	{1180.3333,951.3074,12.3126},
	{1173.8284,947.2721,12.3203},
	{1165.7412,941.4255,12.3203},
	{1157.4972,930.0933,12.3197}

};

static const Float:position_catok_newyear_4[][] =
{
	{1090.8453,841.6456,12.3042},
	{1092.5427,848.8870,12.4809},
	{1093.1497,860.2348,12.3074},
	{1094.1177,868.3666,12.3624},
	{1141.0101,852.3036,12.3118},
	{1136.1876,863.0198,12.3028},
	{1183.0248,895.3781,12.3203},
	{1173.1942,898.4695,12.3203},
	{1163.8325,901.3102,12.3126},
	{1152.9622,902.9539,12.2928}

};

static const Float:position_catok_newyear_5[][] =
{
	{784.2396,1033.9406,12.8204},
	{831.0820,994.2392,13.8077},
	{827.0423,924.6691,13.1375},
	{872.2930,920.3574,14.4682},
	{914.0843,869.7011,12.8659},
	{957.8905,901.4712,14.3554},
	{994.9250,867.8940,13.3057},
	{1028.3649,883.1067,12.3224},
	{1046.3835,823.2838,12.3896},
	{1077.5101,784.2876,12.0903},
	{1107.5796,819.1091,11.9982},
	{1110.0691,843.2078,11.9982},
	{1162.1888,794.3965,12.0813},
	{1178.0968,840.6520,11.9982},
	{1148.1227,884.5327,12.7061},
	{1195.2678,898.5424,12.3345},
	{1238.9126,824.4905,13.0807},
	{1252.6049,872.0632,14.3355},
	{1284.5454,893.8425,14.9636},
	{1243.2164,914.4600,14.6939},
	{1214.7714,945.8102,14.6680},
	{1178.1254,921.5818,12.4611},
	{1169.2607,966.9470,12.6135},
	{1131.5957,959.3932,12.8172},
	{1144.0845,1013.2074,11.9982},
	{1165.2454,1034.2021,11.9982},
	{1199.0989,1002.2654,12.2493},
	{1106.5288,995.7093,11.9982},
	{1090.3909,972.8427,13.9453},
	{1062.6986,976.8409,12.3968},
	{1061.6887,961.2692,13.0689},
	{1030.6079,974.7543,12.4324},
	{1000.2368,972.0794,12.1569},
	{981.6427,1000.3996,14.8240},
	{949.5709,997.7975,12.2309},
	{914.7719,1035.9446,13.0334},
	{887.3071,1016.1454,12.0000},
	{870.6807,1048.2679,12.0000},
	{833.9836,1050.8363,12.0000},
	{799.6107,1065.3052,12.0000},
	{756.6981,1066.5073,12.0000},
	{754.2665,1052.9019,12.0000},
	{1010.2755,954.0113,12.0247},
	{992.7863,948.8356,12.0783},
	{975.0945,964.2104,12.0381},
	{1058.5656,923.4658,11.9982},
	{1079.4371,842.5148,13.0153},
	{907.6746,832.3809,12.0321},
	{827.0757,905.4502,12.0803}
};


stock create_sound_newyear()
{
	/*DestroyStreamSource(sound_zone_stream[8]);
	DestroyStreamSource(sound_zone_stream[9]);

	new 
		sound_random = random(10);

	switch(sound_random)
	{
		case 0..7:
		{
			format(String64, sizeof(String64), "http://dl.b-rp.ru/sound_game/newyear_music_%d.mp3", sound_random+1);
			sound_zone_stream[8] = CreateStreamSource(1104.1387,909.9180,12.2500, 150.0, -1, -1, String64);	
			format(String64, sizeof(String64), "http://dl.b-rp.ru/sound_game/newyear_music_%d.mp3", sound_random+1);
			sound_zone_stream[9] = CreateStreamSource(-429.3383,744.0478,1214.5776, 50.0, -1, -1, String64);	
		}
		case 8:
		{
			format(String64, sizeof(String64), "http://dl.b-rp.ru/sound_game/newyear_music_avaria.mp3");
			sound_zone_stream[8] = CreateStreamSource(1104.1387,909.9180,12.2500, 150.0, -1, -1, String64);
			format(String64, sizeof(String64), "http://dl.b-rp.ru/sound_game/newyear_music_avaria.mp3");
			sound_zone_stream[9] = CreateStreamSource(-429.3383,744.0478,1214.5776, 50.0, -1, -1, String64);							
		}
		case 9..10:
		{
			format(String64, sizeof(String64), "http://dl.b-rp.ru/sound_game/newyear_music_verka.mp3");
			sound_zone_stream[8] = CreateStreamSource(1104.1387,909.9180,12.2500, 150.0, -1, -1, String64);	
			format(String64, sizeof(String64), "http://dl.b-rp.ru/sound_game/newyear_music_verka.mp3");
			sound_zone_stream[9] = CreateStreamSource(-429.3383,744.0478,1214.5776, 50.0, -1, -1, String64);	
		}
	}*/


	return true;
}

stock player_sound_newyear_login(playerid)
{

	/*PlayerPlayStream(playerid, "");

	new 
		sound_random = random(7);
	format(String64, sizeof(String64), "http://dl.b-rp.ru/sound_game/newyear_music_%d.mp3", sound_random+1);
	PlayerPlayStream(playerid, String64);
	*/

	return true;
}



stock create_other_element_newyear()
{

	for(new i; i < sizeof(position_catok_newyear_1); i++)
	{
		newyear_area_ice_1[i] = CreateDynamicSphere(position_catok_newyear_1[i][0], position_catok_newyear_1[i][1], position_catok_newyear_1[i][2], 5.0, -1, -1); 
	}

	for(new i; i < sizeof(position_catok_newyear_2); i++)
	{
		newyear_area_ice_2[i] = CreateDynamicSphere(position_catok_newyear_2[i][0], position_catok_newyear_2[i][1], position_catok_newyear_2[i][2], 5.0, -1, -1); 
	}

	for(new i; i < sizeof(position_catok_newyear_3); i++)
	{
		newyear_area_ice_3[i] = CreateDynamicSphere(position_catok_newyear_3[i][0], position_catok_newyear_3[i][1], position_catok_newyear_3[i][2], 5.0, -1, -1); 
	}

	for(new i; i < sizeof(position_catok_newyear_4); i++)
	{
		newyear_area_ice_4[i] = CreateDynamicSphere(position_catok_newyear_4[i][0], position_catok_newyear_4[i][1], position_catok_newyear_4[i][2], 5.0, -1, -1); 
	}

	newyear_area_ice_4[11] = CreateDynamicSphere(1107.6508,912.6760,12.2500, 55.0, -1, -1); 

	CreateDynamic3DTextLabel(""cWH"Аренда коньков\n\
		"cLRED"[Встаньте на пикап]", CWHITE, 1083.2651,829.7669,14.5350, 5.0,INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
	newyear_rent_katok = create_circle_pickup(1083.2651,829.7669,14.5350, TRIGGER_LRED);

	/*CreateDynamic3DTextLabel(""cWH"Задание у Ивана\n\
		"cLRED"[Встаньте на пикап]", CWHITE, -428.5379,755.9938,1206.0798, 5.0,INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
	newyear_quest_ivan = create_circle_pickup(-428.5379,755.9938,1206.0798, TRIGGER_LRED);*/

	CreateDynamic3DTextLabel(""cWH"Меню кафе\n\
		"cLRED"[Встаньте на пикап]", CWHITE, -201.8249,388.3821,1202.1244, 5.0,INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
	area_cafe_newyear = create_circle_pickup(-201.8249,388.3821,1202.1244, TRIGGER_LRED);

	/*CreateDynamic3DTextLabel(""cWH"Новогодние подарки под ёлкой\n\
		"cLRED"[Встаньте на пикап]", CWHITE, 1149.7314,884.9745,12.7395, 5.0,INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);
	CreateDynamicPickup(13741, 23, 1149.7314,884.9745,12.7395, -1);
	newyear_box = CreateDynamicSphere(1149.7314,884.9745,12.7395, 3.0, -1, -1); */

	cafe_newyear_actor[0] = CreateActor(165, -205.3942, 390.5302,1202.1244, 181.8760);
	cafe_newyear_actor[1] = CreateActor(165, -202.0167,391.1437,1202.1244,181.3707);

	SetActorVirtualWorld(cafe_newyear_actor[0], 1);
	SetActorVirtualWorld(cafe_newyear_actor[1], 1);

	cafe_newyear_actor[2] = CreateActor(121, -428.3674,738.5118,1202.1423,182.1817);
	cafe_newyear_actor[3] = CreateActor(40, -429.3771,738.6982,1201.9314,186.0034);

	cafe_newyear_actor[4] = CreateActor(141, -429.2714,756.7090,1206.0798,226.5574);
	SetActorVirtualWorld(cafe_newyear_actor[4], 1);

	SetActorVirtualWorld(cafe_newyear_actor[2], 1);
	SetActorVirtualWorld(cafe_newyear_actor[3], 1);

	ApplyActorAnimation(cafe_newyear_actor[2], "PED", "SEAT_down", 4.1, 0, 0, 0, 1, 0);
	ApplyActorAnimation(cafe_newyear_actor[3], "PED", "SEAT_down", 4.1, 0, 0, 0, 1, 0);

	return true;
}


stock active_animation_player_katok(playerid)
{
	if(GetPVarIntNew(playerid, "rent_katok_player") == 1)
	{
		SetPVarIntNew(playerid, "active_katok_player", 1);

		ApplyAnimation(playerid, "SKATE","skate_sprint",4.1,1,1,1,1,1,1);
	}
	return true;
}

stock no_animation_player_katok(playerid)
{	
	
	if(!IsPlayerInDynamicArea(playerid, newyear_area_ice_1[0]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_1[1])
	&& !IsPlayerInDynamicArea(playerid, newyear_area_ice_1[2]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_1[3]) &&  !IsPlayerInDynamicArea(playerid, newyear_area_ice_1[4])
    && !IsPlayerInDynamicArea(playerid, newyear_area_ice_1[5]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_1[6]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_1[7])
    && !IsPlayerInDynamicArea(playerid, newyear_area_ice_1[8]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_1[9]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_2[0])
    && !IsPlayerInDynamicArea(playerid, newyear_area_ice_2[1]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_2[2]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_2[3])
    && !IsPlayerInDynamicArea(playerid, newyear_area_ice_2[4]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_2[5]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_2[6])
    && !IsPlayerInDynamicArea(playerid, newyear_area_ice_2[7]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_2[8]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_2[9])
    && !IsPlayerInDynamicArea(playerid, newyear_area_ice_3[0]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_3[1]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_3[2]) 
    && !IsPlayerInDynamicArea(playerid, newyear_area_ice_3[3]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_3[4]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_3[5])
    && !IsPlayerInDynamicArea(playerid, newyear_area_ice_3[6]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_3[7]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_3[8])
    && !IsPlayerInDynamicArea(playerid, newyear_area_ice_3[9]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_3[10])  && !IsPlayerInDynamicArea(playerid, newyear_area_ice_3[11])
    && !IsPlayerInDynamicArea(playerid, newyear_area_ice_3[12]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_3[13]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_3[14])
    && !IsPlayerInDynamicArea(playerid, newyear_area_ice_3[15]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_3[16]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_3[17])
    && !IsPlayerInDynamicArea(playerid, newyear_area_ice_3[18]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_3[19]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_3[20]) 
    && !IsPlayerInDynamicArea(playerid, newyear_area_ice_3[21]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_3[22]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_3[23]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_3[24])
    && !IsPlayerInDynamicArea(playerid, newyear_area_ice_4[0]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_4[1]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_4[2]) 
    && !IsPlayerInDynamicArea(playerid, newyear_area_ice_4[3]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_4[4]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_4[5])
    && !IsPlayerInDynamicArea(playerid, newyear_area_ice_4[6]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_4[7]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_4[8])
    && !IsPlayerInDynamicArea(playerid, newyear_area_ice_4[9]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_4[10]) && !IsPlayerInDynamicArea(playerid, newyear_area_ice_4[11]))
	{

		DeletePVarNew(playerid, "active_katok_player");
		ApplyAnimation(playerid, "CARRY","null",0,0,0,0,0,0,0);
		ApplyAnimation(playerid, "SKATE","null",0,0,0,0,0,0,0);
		ApplyAnimation(playerid, "CARRY","crry_prtial",4.0,0,0,0,0,0);
	}
	else
	{
		if(GetPVarIntNew(playerid, "rent_katok_player") == 1)
		{
			ApplyAnimation(playerid, "SKATE","skate_sprint",4.1,1,1,1,1,1,1);			
		}
	}



	return true;
}


stock rent_katok_menus(playerid, type = TEXTDRAW_SHOW)
{
	switch(type)
	{
		case TEXTDRAW_SHOW:
		{
			if(GetPVarIntNew(playerid, "rent_katok_player") == 1)
			{
				TextDrawShowForPlayer(playerid, rent_katok_menu[0]);
				TextDrawShowForPlayer(playerid, rent_katok_menu[3]);
				TextDrawShowForPlayer(playerid, rent_katok_menu[2]);

				SelectTextDraw(playerid, COLOR_BLUE);
			}
			else
			{
				TextDrawShowForPlayer(playerid, rent_katok_menu[0]);
				TextDrawShowForPlayer(playerid, rent_katok_menu[1]);
				TextDrawShowForPlayer(playerid, rent_katok_menu[2]);


				SelectTextDraw(playerid, COLOR_BLUE);
			}
 		}
 		case TEXTDRAW_HIDE:
 		{
			TextDrawHideForPlayer(playerid, rent_katok_menu[0]);
			TextDrawHideForPlayer(playerid, rent_katok_menu[1]);
			TextDrawHideForPlayer(playerid, rent_katok_menu[2]);
			TextDrawHideForPlayer(playerid, rent_katok_menu[3]);

			CancelSelectTextDraw(playerid); 	 			
 		}
 	}

	return true;
}

stock rent_katok_menu_push(playerid)
{

	if(GetPVarIntNew(playerid, "rent_katok_player") == 1)
	{
		TextDrawShowForPlayer(playerid, rent_katok_menu[0]);
		TextDrawShowForPlayer(playerid, rent_katok_menu[3]);
		TextDrawShowForPlayer(playerid, rent_katok_menu[2]);

		TextDrawHideForPlayer(playerid, rent_katok_menu[1]);

		DeletePVarNew(playerid, "rent_katok_player");

		rent_katok_menus(playerid, TEXTDRAW_HIDE);
		rent_katok_menus(playerid, TEXTDRAW_SHOW);

		SendSucc(playerid, "Вы успешно отказались от аренды коньков и они были сняты с Вас!");

		set_player_skin(playerid,pData[playerid][pSkin]);
		



		SelectTextDraw(playerid, COLOR_BLUE);
	}
	else
	{
		SetPVarIntNew(playerid, "rent_katok_player", 1);
		TextDrawShowForPlayer(playerid, rent_katok_menu[0]);
		TextDrawShowForPlayer(playerid, rent_katok_menu[1]);
		TextDrawShowForPlayer(playerid, rent_katok_menu[2]);

		TextDrawHideForPlayer(playerid, rent_katok_menu[3]);

		rent_katok_menus(playerid, TEXTDRAW_HIDE);
		rent_katok_menus(playerid, TEXTDRAW_SHOW);

		if(pData[playerid][pSex] == 2)
		{
			set_player_skin(playerid, 201);
		}
		else 
		{
			set_player_skin(playerid, 128);
		}

		SendSucc(playerid, "Вы успешно взяли в аренду коньки! Хорошего Вам отдыха!");

		SelectTextDraw(playerid, COLOR_BLUE);
	}
	return true;
}


stock select_menu_cafe_newyear(playerid)
{
	SPD(playerid, DIALOG_BUY_MENU_NEWYEAR, DIALOG_STYLE_TABLIST_HEADERS, 
	!""cBLUE"Новогоднее меню", 
	!""cGREY"Название\t"cGREY"Действие\n\
	"cWH"Праздничные блюда\t"cGR"Открыть\n\
	"cWH"Алкогольные напитки\t"cGR"Открыть\n\
	"cWH"Безалкогольные напитки\t"cGR"Открыть", !"Купить", !"Отмена");

	return true;
}


stock select_menu_cafe_eat(playerid)
{
	SPD(playerid, DIALOG_BUY_MENU_NEWYEAR_EAT, DIALOG_STYLE_TABLIST_HEADERS, 
	!""cBLUE"Новогоднее меню", 
	!""cGREY"Название\t"cGREY"Цена\n\
	"cWH"Новогоднее салат «Оливье»\t"cGR"450 рублей\n\
	"cWH"Индейка «ФЛАМБЕ»\t"cGR"1150 рублей\n\
	"cWH"Десерт «Новогодняя иллюзия»\t"cGR"350 рублей\n\
	"cWH"Селедка под шубой\t"cGR"550 рублей\n\
	"cWH"Умбрийский цыпленок\t"cGR"820 рублей\n\
	"cWH"Рождественский гусь с яблоками\t"cGR"1820 рублей\n\
	"cWH"Салат зимний поцелуй\t"cGR"320 рублей\n\
	"cBLUE"Новогодняя пицца\t"cGR"150 рублей", !"Купить", !"Отмена");

	return true;
}

stock select_menu_cafe_buyhlo(playerid)
{
	SPD(playerid, DIALOG_BUY_MENU_NEWYEAR_BUHLO, DIALOG_STYLE_TABLIST_HEADERS, 
	!""cBLUE"Новогоднее меню", 
	!""cGREY"Название\t"cGREY"Цена\n\
	"cWH"Пунш Новогодний\t"cGR"400 рублей\n\
	"cWH"Напиток Логово Льва\t"cGR"355 рублей\n\
	"cWH"Шампанское «Cоветское»\t"cGR"350 рублей\n\
	"cWH"Водка «Свояк»\t"cGR"350 рублей\n\
	"cWH"Водка «Финляндия»\t"cGR"820 рублей", !"Купить", !"Отмена");

	return true;
}

stock select_menu_cafe_kids(playerid)
{
	SPD(playerid, DIALOG_BUY_MENU_NEWYEAR_KIDS, DIALOG_STYLE_TABLIST_HEADERS, 
	!""cBLUE"Новогоднее меню", 
	!""cGREY"Название\t"cGREY"Цена\n\
	"cWH"Сок\t"cGR"50 рублей\n\
	"cWH"Кока-кола\t"cGR"50 рублей\n\
	"cWH"Пепси-кола\t"cGR"50 рублей\n\
	"cWH"Шампанское «Детское»\t"cGR"150 рублей", !"Купить", !"Отмена");

	return true;
}


stock menu_select_prize_newyear(playerid, type)
{
	switch(type)
	{
		case TEXTDRAW_SHOW:
		{
			TextDrawShowForPlayer(playerid, prizenewyear_background[0]);
			TextDrawShowForPlayer(playerid, prizenewyear_background[1]);
			TextDrawShowForPlayer(playerid, prizenewyear_background[2]);

			SelectTextDraw(playerid, COLOR_BLUE);
		}
		case TEXTDRAW_HIDE:
		{
			TextDrawHideForPlayer(playerid, prizenewyear_background[0]);
			TextDrawHideForPlayer(playerid, prizenewyear_background[1]);
			TextDrawHideForPlayer(playerid, prizenewyear_background[2]);

			CancelSelectTextDraw(playerid);
		}
	}

	return true;	
}


CMD:sellsnow(playerid, params[])
{
	return SendErr(playerid, "Команда временно недоступна!");

/*	if(!pData[playerid][pCountSnow])
		return SendErr(playerid, "У вас снежинок");

	if(GetPVarInt(playerid, "OfferSnow") || GetPVarInt(playerid, "RecieveSnow"))
		return SendErr(playerid, "У вас уже есть активное предложение");

	if(sscanf(params, "ddd", params[0], params[1], params[2])) 
		return SendInf(playerid, "/sellsnow [ID игрока] [Кол-во снежинок] [Цена продажи]");

	if(!IsPlayerConnected(params[0]) || playerid == params[0])
		return SendErr(playerid, "Неверный ID");
	
	if(GetPlayerDistanceToPlayer(playerid, params[0]) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(params[0]))
		return SendErr(playerid, "Вы находитесь далеко друг от друга");	

	if(GetPlayerSnow(playerid) < params[1])
		return SendErr(playerid, "У вас нет столько снежинок");

	if(params[2] < 1000 || params[2] > 200000000)
		return SendErr(playerid, "Стоимость продажи должна быть от 1000 до 20млн. рублей");

	if(GetPlayerMoneyEx(params[0]) < params[2])
		return SendErr(playerid, "У игрока нет данной суммы на руках");

	new
		message[144];

	format(message, sizeof(message), "Вы предложили "cGR"%s "cWH"купить "cGR"%d "cWH"снежинок за "cGR"%d "cWH"рублей", pData[params[0]][pNickname], params[1], params[2]);
	SendSucc(playerid, message);

	SetPVarInt(playerid, "OfferSnow", params[0]+1);
	SetPVarInt(params[0], "RecieveSnow", playerid+1);
	SetPVarInt(params[0], "SnowCount", params[1]);
	SetPVarInt(params[0], "SnowPrice", params[2]);

	new 
		sell_snow_message[300];

	format(sell_snow_message, sizeof (sell_snow_message), "\n"cBLUE"%s "cWH"предлагает купить его снежинки\n\n\
		"cWH"Количество снежинок: "cBLUE"%d\n\
		"cWH"Стоимость: "cBLUE"%d рублей\n\n\
		"cWH"Вы действительно хотите купить снежинки?", pData[playerid][pNickname], params[1], params[2]);
	ShowPlayerDialog(params[0], DIALOG_SELL_SNOW, DIALOG_STYLE_MSGBOX, !""cBLUE"Предложение покупки снежинок", sell_snow_message, !"Купить", !"Отмена");*/		
}

stock dialog_selling_snow(playerid, dialogid, response)
{
	switch(dialogid)
	{
		case DIALOG_SELL_SNOW:
		{
			new 
				offerid = GetPVarInt(playerid, "RecieveSnow")-1,
				countsnow = GetPVarInt(playerid, "SnowCount"),
				price = GetPVarInt(playerid, "SnowPrice");

			if(GetPVarInt(offerid, "OfferSnow") != playerid+1)
				return SendErr(playerid, "Данное предложение неактивно");

			DeletePVar(offerid, "OfferSnow");
			DeletePVar(playerid, "RecieveSnow");
			DeletePVar(playerid, "SnowCount");
			DeletePVar(playerid, "SnowPrice");

			if(!response)
			{
				SendInf(playerid, "Вы отказались от покупки снежинок");
				SendInf(offerid, "Игрок отказался от покупки снежинок");
				return true;
			}

			if(GetPlayerSnow(offerid) < countsnow)
				return SendErr(playerid, "У игрока нет данного количества снежинок");

			if(GetPlayerMoneyEx(playerid) < price)
				return SendErr(playerid, "У Вас нет нужной суммы на руках");

			if(GetPlayerDistanceToPlayer(playerid, offerid) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(offerid))
				return SendErr(playerid, "Вы находитесь далеко друг от друга");	

			pData[playerid][pCountSnow] += countsnow;
			pData[offerid][pCountSnow] -= countsnow;

			UpdatePlayerData(playerid, "pCountSnow", pData[playerid][pCountSnow]);
			UpdatePlayerData(offerid, "pCountSnow", pData[offerid][pCountSnow]);

			give_money(playerid, -price, "Покупка снежинок у игрока");
			give_money(offerid, price, "Продажа снежинок игроку");

			new 
				message[144];

			format(message, sizeof(message), "Вы купили "cGR"%d снежинок "cWH"у игрока "cGR"%s "cWH"за "cGR"%d "cWH"рублей", countsnow, pData[offerid][pNickname], price);
			SendSucc(playerid, message);

			format(message, sizeof(message), "%s купил %d снежинок за %d рублей", pData[playerid][pNickname], countsnow, price);
			SendSucc(offerid, message);
			return true;
		}
	}
	return true;
}

stock show_notify_gui_newyear(playerid, status, type = 0, type_td[] = "None", time = 2000)
{


	switch(status)
	{
		case TEXTDRAW_SHOW:
		{
			switch(type)
			{	

				case NOTIFY_GUI_256_CENTER:
				{
					hide_global_notify_gui_newyear(playerid);
					create_player_newyear_info(playerid);
					PlayerTextDrawSetString(playerid, newyear_gui_info[0][playerid], type_td);
					PlayerTextDrawShow(playerid, newyear_gui_info[0][playerid]);	
				}
				case NOTIFY_GUI_256_RIGHT:
				{
					hide_global_notify_gui_newyear(playerid);
					create_player_newyear_info(playerid);
					PlayerTextDrawSetString(playerid, newyear_gui_info[1][playerid], type_td);
					PlayerTextDrawShow(playerid, newyear_gui_info[1][playerid]);			

				}	
			}
			SetTimerEx("hide_global_notify_gui_newyear", time, false, "i", playerid);
		}
		case TEXTDRAW_HIDE:
		{
			PlayerTextDrawHideEx(playerid, newyear_gui_info[0][playerid]);
			PlayerTextDrawHideEx(playerid, newyear_gui_info[1][playerid]);
		}
	}

	return true;
}

callback:: hide_global_notify_gui_newyear(playerid)
{

	show_notify_gui_newyear(playerid, TEXTDRAW_HIDE);

	return true;
}

stock quest_snow_random_accept(playerid)
{
	if(GetPVarIntNew(playerid, "count_prize_snow_quest") >= 10)
	{
		return check_accept_quest_newyear(playerid, 2);
	}

	new 
		i = random(40)+1;


	format(String64, sizeof(String64), "Вам осталось раскидать %d сугробов!", 10-GetPVarIntNew(playerid, "count_prize_snow_quest"));
	SendInf(playerid, String64);
	SetPlayerCheckpoint(playerid, position_catok_newyear_5[i][0], position_catok_newyear_5[i][1], position_catok_newyear_5[i][2], 3.0);

	SetPVarIntNew(playerid, "active_player_snow_newyear", 1);

	return true;
}



stock info_newyear_server(playerid)
{
	if(!GetPVarIntNew(playerid, "quest_info_show"))
	{
		SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Новый год", !"\
		"cWH"Дорогие друзья, поздравляем Вас с приближением самого радостного, доброго, волшебного праздника — Нового года! \n\
		Пусть этот год станет чередой счастливых и радостных дней, наполненных любовью, добром и верой в лучшее!\n\
		В честь праздника, мы приготовили для Вас несколько увлекательных обновлений:\n\n\
		"cBLUE"1. "cWH"Водитель снегоуборочной машины. Помогите городам справиться с наплывом снега и очистите дороги!\n\
		"cBLUE"(( /gps - Работы - Водитель снегоуборочной машины))"cWH"\n\n\
		"cBLUE"2. "cWH"Новая Новогодняя квестовая линия. Помогите справиться с задачами Деду Морозу и его внучке,\n\
		чтобы устроить праздничное настроение Всем в округе! \n\
		Количество выполнений - неограниченно! "cBLUE"(( /quest ))"cWH"\n\n\
		"cBLUE"3. "cWH"Снежинки. Зарабатывайте снежинки за прохождение квестовых заданий, за каждый час проведенный в игре \n\
		и обменивайте их на уникальные подарки под главной ёлкой на площади!\n\
		Продавайте снежинки игрокам "cBLUE"(( /sellsnow ))"cWH" или покупайте их у других игроков, чтобы стать более уникальным!\n\
		Вы можете выиграть деньги, уникальные акссесуары, автомобиль и главные призы - Снегоход и Сим-карта в формате 2021!\n\n\
		"cBLUE"4. "cWH"Любите экстремальный спорт? Приглашаем Вас на увлекательные гонки на снегоходах! \n\
		Только там Вы испытаете реальный драйв от вождения снегохода, прыжков на трамплинах, вкуса победы и прилива адреналина!\n\
		"cBLUE"(( /gps - Развлечения - Гонки на снегоходах ))"cWH"", !"Закрыть", "");

		SetPVarIntNew(playerid, "quest_info_show", 1);
	}

	return true;
}