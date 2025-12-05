

#define 	ACTOR_SNOW_WORK_1		"Анатолий Тимурович" // Дефайн названия актёра для работы (используется в диалогах также)
#define 	ACTOR_SNOW_WORK_2		"Олег Игоревич" // Дефайн названия актёра для работы (используется в диалогах также)
#define 	ACTOR_SNOW_WORK_3		"Алексей Артёмович" // Дефайн названия актёра для работы (используется в диалогах также)
#define 	ACTOR_SNOW_WORK_4		"Степан Денисович" // Дефайн названия актёра для работы (используется в диалогах также)
#define 	ACTOR_SNOW_WORK_5		"Дмитрий Максимович" // Дефайн названия актёра для работы (используется в диалогах также)

#define 	MAX_TYPE_SNOW_WORK		5 // Максимальное кол-во типов
	
#define 	TYPE_SNOW_WORK_1		1 // Арзамас
#define 	TYPE_SNOW_WORK_2		2 // Южный
#define 	TYPE_SNOW_WORK_3		3 // Батырево
#define 	TYPE_SNOW_WORK_4		4 // Эдово
#define 	TYPE_SNOW_WORK_5		5 // Лыткарино
	
#define 	RENT_SNOW_CAR_PRICE		500 // Цена аренды снегоуборочного транспорта

#define 	PRICE_SNOW_WORKING_1	100
#define 	PRICE_SNOW_WORKING_2	110
#define 	PRICE_SNOW_WORKING_3	120
#define 	PRICE_SNOW_WORKING_4	130
#define 	PRICE_SNOW_WORKING_5	135

new
	area_snow_work[5];
new
	swork_vehicle[MAX_PLAYERS] = INVALID_VEHICLE_ID;

new Float:gSnowWorkSpawn[MAX_TYPE_SNOW_WORK][5][4] =
{
	{
		{808.6328,814.4430,12.1219,159.4217},
		{813.5649,812.6904,12.1054,160.0962},
		{818.3130,811.1568,12.0869,159.8054},
		{822.4492,809.7084,12.0818,160.0449},
		{826.6353,808.3117,12.0669,159.9296}
	},
	{
		{2556.1753,-2077.1470,21.9840,271.0864},
		{2556.0288,-2073.5950,21.9912,271.8274},
		{2555.7537,-2070.2109,21.9957,272.0222},
		{2555.6421,-2066.5186,21.9966,271.0483},
		{2571.0283,-2069.3848,21.9925,268.8036}
	},
	{
		{1774.5848,2237.6782,15.8960,179.4963},
		{1767.0819,2237.8479,15.9021,179.0099},
		{1770.9445,2237.8525,15.9004,178.1626},
		{1766.6759,2225.7527,15.9525,181.0653},
		{1775.1549,2217.6885,15.9347,180.5367}
	},
	{
		{-2498.2039,2772.2529,37.6660,359.9724},
		{-2494.6150,2772.2566,37.6679,359.5931},
		{-2490.4634,2771.9915,37.6672,359.0753},
		{-2486.8135,2771.9700,37.6685,359.6290},
		{-2478.3870,2783.1116,37.6653,89.9519}
	},
	{
		{-2247.2776,268.2465,24.5594,261.8166},
		{-2246.8008,271.8542,24.5675,262.8520},
		{-2246.3389,275.8898,24.5651,263.3837},
		{-2246.1257,279.6929,24.5686,261.9137},
		{-2245.3428,283.6340,24.5647,261.5015}
	}
};

new Float:gSnowWorkCP[MAX_TYPE_SNOW_WORK][33][3] =
{
	{
		{785.6289,864.0201,11.5590},
		{616.1228,1111.4626,11.5618},
		{322.8548,1160.9210,11.5671},
		{313.2856,1340.9783,11.4681},
		{337.5495,1657.4380,11.5596},
		{228.3796,1695.7988,11.5661},
		{134.2549,1397.2332,11.5643},
		{73.4366,1096.0941,11.5646}, 
		{-32.9907,901.0699,11.5650},
		{-351.7192,978.2878,11.5629},
		{-385.4644,911.7903,11.5736},
		{-384.9956,676.0682,11.5589},
		{-338.2798,600.1649,11.5603},
		{-353.2253,381.4255,12.2070},
		{-480.2744,110.4923,13.2880},
		{-589.2592,82.5638,13.2810},
		{-550.3866,74.9925,13.2793},
		{-436.1095,102.3487,13.2877},
		{-393.9587,66.4634,13.3006},
		{-187.0065,-158.7475,12.2521},
		{364.6020,-43.4170,12.3894},
		{249.3003,36.8526,11.5625},
		{42.3957,30.6294,12.1035}, 
		{-225.1749,125.3747,12.1741},
		{105.0633,165.8354,12.1738}, 
		{46.2540,278.8258,13.6400}, 
		{-65.9746,361.0907,12.1070},
		{-50.4557,551.5485,11.5643},
		{52.6220,550.6733,11.5655},
		{355.8712,438.9881,11.5656},
		{678.8827,567.1865,11.5666},
		{769.4628,804.7249,11.5617}, 
		{0.0, 0.0, 0.0}
	},
	{
		{2587.7029,-2096.9912,21.3773},
		{2592.8459,-2134.6333,21.3835},
		{2681.4036,-2162.4126,21.3601},
		{2785.5403,-2380.3887,21.2523},
		{2733.6013,-2558.2571,21.1218},
		{2535.0193,-2677.4131,24.8057},
		{1974.7872,-2682.6978,10.6741},
		{1917.9893,-2541.7197,10.3907},
		{1810.0693,-2274.8887,10.3886},
		{2108.8188,-2257.9219,17.2818},
		{2241.5420,-2171.9500,21.3591},
		{2292.4080,-1963.7893,21.3906},
		{2292.5452,-1894.8203,21.3739},
		{2433.1541,-1877.0422,21.3787},
		{2471.4053,-1752.0148,21.3787},
		{2336.9958,-1687.8213,21.3786},
		{2277.9072,-1735.2795,21.3787},
		{2170.0713,-1746.7712,18.4129},
		{2097.5007,-1878.7067,18.3771},
		{2111.0374,-2009.5948,18.3762},
		{2173.1914,-1949.9634,18.3770},
		{2111.9167,-1802.7026,18.3755},
		{2247.2629,-1761.5222,21.3755},
		{2420.7000,-1761.3163,35.2689},
		{2597.0183,-1779.6835,35.2561},
		{2708.0774,-2138.8308,21.3881},
		{2612.7329,-2100.6204,21.3801},
		{2606.5710,-1730.1677,21.3802},
		{2601.1121,-1690.0828,22.6248},
		{2587.6118,-1941.7750,21.3878},
		{2587.6763,-2061.3879,21.3800},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0}
	},
	{
		{1770.7434,2166.3679,15.5994},
		{1811.9033,2052.2603,15.4354},
		{1859.3555,2053.1521,15.4466},
		{1961.9097,2000.9252,15.4670},
		{1963.2417,1934.7954,15.1447},
		{2102.5903,1905.3021,15.4803},
		{2360.3938,1902.4205,15.4465},
		{2499.7932,1894.9557,15.8265},
		{2717.3735,1895.9633,15.5409},
		{2760.2190,2028.9086,17.2850},
		{2729.3499,2516.4177,15.0927},
		{2493.4290,2938.4019,23.7987},
		{2132.9104,2963.3313,11.0363},
		{2054.8950,2871.5918,13.2501},
		{1896.1882,2657.9590,14.7946},
		{1752.7887,2508.4707,15.5277},
		{1787.8807,2520.7151,15.2179},
		{1815.3381,2501.5513,15.2261},
		{1785.9257,2467.4744,15.5212},
		{1834.4469,2384.7896,15.4837},
		{1885.7896,2301.5032,15.5206},
		{1843.1571,2229.0869,15.3843},
		{1778.9954,2228.8452,15.3778},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0}
	},
	{
		{-2491.6851,2809.6736,37.0112},
		{-2384.6433,2810.6812,36.9952},
		{-2379.1650,2704.1482,37.8699},
		{-2421.9963,2490.2517,42.5814},
		{-2603.8057,2373.0527,52.5594},
		{-2640.2437,2024.7264,52.5791},
		{-2521.0249,1844.2050,52.5793},
		{-2383.5818,1748.5164,52.5733},
		{-2331.8184,1774.1368,52.6153},
		{-2246.9541,1820.4525,52.4663},
		{-2245.0554,1828.0859,52.4639},
		{-2332.8660,1779.2976,52.6249},
		{-2413.9482,1795.1816,52.5798},
		{-2624.2549,2030.7205,52.5779},
		{-2610.8413,2285.2881,52.5593},
		{-2373.2400,2496.8232,42.4773},
		{-2374.0552,2719.9080,37.5733},
		{-2373.9802,2891.4919,36.9969},
		{-2434.5559,2929.9441,37.0033},
		{-2551.7417,2893.9968,36.9952},
		{-2525.4143,2836.8511,37.0032},
		{-2511.8442,2790.5164,37.0038},
		{-2658.7744,2758.1746,37.0496},
		{-2633.9565,2753.4521,36.9933},
		{-2506.4309,2791.7791,37.0031},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0}
	},
	{
		{-2217.9294,255.4567,24.1029},
		{-2158.2859,150.4687,24.9717},
		{-2093.0569,-24.3416,26.6440},
		{-2106.1248,-177.1436,25.4510},
		{-2161.5840,-381.2669,25.0222},
		{-2258.0020,-332.3629,21.0468},
		{-2261.7117,-244.0087,22.6137},
		{-2245.3921,-205.1390,23.9020},
		{-2281.9858,-162.4681,23.0465},
		{-2362.1050,-126.2428,21.4451},
		{-2409.2854,-133.2563,14.6446},
		{-2588.2395,-87.4544,13.4705},
		{-2653.4714,26.4384,10.5573},
		{-2657.5574,164.0224,10.5484},
		{-2592.9763,231.4126,11.6765},
		{-2543.3635,229.9595,12.7613},
		{-2508.8728,229.1918,13.7067},
		{-2258.8586,216.6307,24.0627},
		{-2217.3513,266.8406,24.0958},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0}
	}
};

stock snow_work_connecting()
{
	CreateActor(135, 780.4943, 752.0287, 12.9307, 253.1844);
	area_snow_work[0] = create_circle_pickup(781.3328,751.5971,12.9307, TRIGGER_LRED);
	CreateDynamic3DTextLabel(""cLRED""ACTOR_SNOW_WORK_1"\n\
	"cWH"Устройство на работу",CWHITE,780.4943, 752.0287, 12.9307+1.0,5.0);

	CreateActor(135, 2574.6716,-2081.0750,21.9640,37.7605);
	area_snow_work[1] = create_circle_pickup(2574.2786,-2080.2368,21.9640, TRIGGER_LRED);
	CreateDynamic3DTextLabel(""cLRED""ACTOR_SNOW_WORK_2"\n\
	"cWH"Устройство на работу",CWHITE,2574.6716,-2081.0750,21.9640+1.0,5.0);

	CreateActor(135, 1757.4318,2242.6582,15.8598,192.2688);
	area_snow_work[2] = create_circle_pickup(1757.6349,2241.9365,15.8610, TRIGGER_LRED);
	CreateDynamic3DTextLabel(""cLRED""ACTOR_SNOW_WORK_3"\n\
	"cWH"Устройство на работу",CWHITE,1757.4318,2242.6582,15.8598+1.0,5.0);

	CreateActor(135, -2483.2371,2787.2449,37.8606,89.0964);
	area_snow_work[3] = create_circle_pickup(-2484.2024,2787.1370,37.6340, TRIGGER_LRED);
	CreateDynamic3DTextLabel(""cLRED""ACTOR_SNOW_WORK_4"\n\
	"cWH"Устройство на работу",CWHITE,-2483.2371,2787.2449,37.8606+1.0,5.0);

	CreateActor(135, -2243.6160,263.2382,24.5337,355.8248);
	area_snow_work[4] = create_circle_pickup(-2243.4846,264.0609,24.5337, TRIGGER_LRED);
	CreateDynamic3DTextLabel(""cLRED""ACTOR_SNOW_WORK_5"\n\
	"cWH"Устройство на работу",CWHITE,-2243.6160,263.2382,24.5337+1.0,5.0);
}

stock area_snow_work_enter(playerid, areaid)
{
	for(new i; i < MAX_TYPE_SNOW_WORK; i++)
	{
		if(areaid == area_snow_work[i])
		{
			new 
				string[400];

			if(GetPVarIntNew(playerid, "snow_work"))
			{
				return SPD(playerid, DIALOG_CANCEL_SNOW_WORK, 0, !""cLRED"Работа снегоуборщика | "cWH"Окончание работы", !"\n\
				"cWH"Вы действительно хотите закончить работу "cLRED"снегоуборщика?", !"Закончить", !"Отмена");
			}
			if(areaid == area_snow_work[0])
			{
				format(string, sizeof(string), "\n\
				"cWH"Привет, я "ACTOR_SNOW_WORK_1" и у меня есть небольшая проблема.\n\
				"cWH"Как ты уже заметил, на улицах Арзамаса очень много снега, а убирать его некому.\n\
				"cWH"Не хочешь помочь с уборкой улиц города? Деньгами не обижу.\n\n\
				"cWH"Стоимость аренды снегоуборочного транспорта "cGR"%d рублей\n\
				"cWH"Вы действительно хотите начать работу "cLRED"снегоуборщика?", RENT_SNOW_CAR_PRICE);

				SPD(playerid, DIALOG_ACCEPT_SNOW_WORK, 0, !""cLRED"Работа снегоуборщика | "cWH"Начало работы", string, !"Начать", !"Отмена");
			}
			if(areaid == area_snow_work[1])
			{
				format(string, sizeof(string), "\n\
				"cWH"Привет, я "ACTOR_SNOW_WORK_2" и у меня есть небольшая проблема.\n\
				"cWH"Как ты уже заметил, на улицах Южного очень много снега, а убирать его некому.\n\
				"cWH"Не хочешь помочь с уборкой улиц города? Деньгами не обижу.\n\n\
				"cWH"Стоимость аренды снегоуборочного транспорта "cGR"%d рублей\n\
				"cWH"Вы действительно хотите начать работу "cLRED"снегоуборщика?", RENT_SNOW_CAR_PRICE);

				SPD(playerid, DIALOG_ACCEPT_SNOW_WORK, 0, !""cLRED"Работа снегоуборщика | "cWH"Начало работы", string, !"Начать", !"Отмена");
			}
			if(areaid == area_snow_work[2])
			{
				format(string, sizeof(string), "\n\
				"cWH"Привет, я "ACTOR_SNOW_WORK_3" и у меня есть небольшая проблема.\n\
				"cWH"Как ты уже заметил, на улицах Батырево очень много снега, а убирать его некому.\n\
				"cWH"Не хочешь помочь с уборкой улиц города? Деньгами не обижу.\n\n\
				"cWH"Стоимость аренды снегоуборочного транспорта "cGR"%d рублей\n\
				"cWH"Вы действительно хотите начать работу "cLRED"снегоуборщика?", RENT_SNOW_CAR_PRICE);

				SPD(playerid, DIALOG_ACCEPT_SNOW_WORK, 0, !""cLRED"Работа снегоуборщика | "cWH"Начало работы", string, !"Начать", !"Отмена");
			}
			if(areaid == area_snow_work[3])
			{
				format(string, sizeof(string), "\n\
				"cWH"Привет, я "ACTOR_SNOW_WORK_4" и у меня есть небольшая проблема.\n\
				"cWH"Как ты уже заметил, на улицах Эдово очень много снега, а убирать его некому.\n\
				"cWH"Не хочешь помочь с уборкой улиц города? Деньгами не обижу.\n\n\
				"cWH"Стоимость аренды снегоуборочного транспорта "cGR"%d рублей\n\
				"cWH"Вы действительно хотите начать работу "cLRED"снегоуборщика?", RENT_SNOW_CAR_PRICE);

				SPD(playerid, DIALOG_ACCEPT_SNOW_WORK, 0, !""cLRED"Работа снегоуборщика | "cWH"Начало работы", string, !"Начать", !"Отмена");
			}
			if(areaid == area_snow_work[4])
			{
				format(string, sizeof(string), "\n\
				"cWH"Привет, я "ACTOR_SNOW_WORK_5" и у меня есть небольшая проблема.\n\
				"cWH"Как ты уже заметил, на улицах Лыткарино очень много снега, а убирать его некому.\n\
				"cWH"Не хочешь помочь с уборкой улиц города? Деньгами не обижу.\n\n\
				"cWH"Стоимость аренды снегоуборочного транспорта "cGR"%d рублей\n\
				"cWH"Вы действительно хотите начать работу "cLRED"снегоуборщика?", RENT_SNOW_CAR_PRICE);

				SPD(playerid, DIALOG_ACCEPT_SNOW_WORK, 0, !""cLRED"Работа снегоуборщика | "cWH"Начало работы", string, !"Начать", !"Отмена");
			}
		}
	}
	return true;
}

stock dialog_snow_work(playerid, dialogid, response)
{
	switch(dialogid)
	{
		case DIALOG_ACCEPT_SNOW_WORK:
		{
			if(!response)
				return true;
			new
				type;

			if(IsPlayerInDynamicArea(playerid, area_snow_work[0]))
				type = 1;

			else if(IsPlayerInDynamicArea(playerid, area_snow_work[1]))
				type = 2;
				
			else if(IsPlayerInDynamicArea(playerid, area_snow_work[2]))
				type = 3;

			else if(IsPlayerInDynamicArea(playerid, area_snow_work[3]))
				type = 4;

			else if(IsPlayerInDynamicArea(playerid, area_snow_work[4]))
				type = 5;

			else
				return true;
						

			if(GetPlayerMoneyEx(playerid) < RENT_SNOW_CAR_PRICE)
			{
				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:info_gui_no_money", 3000);
				return SendErr(playerid, "У Вас недостаточно денег, чтобы начать работать");
			}

			start_snow_work(playerid, type);
			return true;
		}
		case DIALOG_CANCEL_SNOW_WORK:
		{
			if(!response)
				return true;

			end_snow_work(playerid);
			return true;
		}
		case DIALOG_SELECT_SNOW_WORK:
		{
			if(!response)
			{
				end_snow_work(playerid);
				return true;
			}

			new
				string_mes[144],
				count_cp = GetPVarIntNew(playerid, "snow_work_cp")-1,
				money;


			if(get_job_level(playerid, SKILL_SNOWWORK) == 1)
			{
				money = count_cp*PRICE_SNOW_WORKING_1;
			}
			else if(get_job_level(playerid, SKILL_SNOWWORK) == 2)
			{
				money = count_cp*PRICE_SNOW_WORKING_2;
			}
			else if(get_job_level(playerid, SKILL_SNOWWORK) == 3)
			{
				money = count_cp*PRICE_SNOW_WORKING_3;
			}
			else if(get_job_level(playerid, SKILL_SNOWWORK) == 4)
			{
				money = count_cp*PRICE_SNOW_WORKING_4;
			}
			else if(get_job_level(playerid, SKILL_SNOWWORK) == 5)
			{
				money = count_cp*PRICE_SNOW_WORKING_5;
			}

			format(string_mes, sizeof(string_mes), "Вы получили "cGR"%d рублей "cWH"за пройденный круг", money);
			SendSucc(playerid, string_mes);
			give_money(playerid, money, "Зарплата за круг(снегоуборщик)");
			SetPVarIntNew(playerid, "snow_work_cp", 1);

			new 
				type = GetPVarIntNew(playerid, "snow_work_type");

			SetPlayerRaceCheckpoint(playerid, 0, gSnowWorkCP[type-1][0][0], gSnowWorkCP[type-1][0][1], gSnowWorkCP[type-1][0][2], gSnowWorkCP[type-1][1][0], gSnowWorkCP[type-1][1][1], gSnowWorkCP[type-1][1][2], 4.0);
			return true;
		}
	}
	return true;
}

stock start_snow_work(playerid, type)
{

	if(pTemp[playerid][rent_car] != INVALID_VEHICLE_ID)
	{
		SendErr(playerid, "Вы уже арендуете какой-либо транспорт");
		return true;
	}

	if(pData[playerid][pLevel] < 3)
		return SendErr(playerid, "Работа снегоуборщика доступна с 3-го уровня!");

	if(!pData[playerid][pLicenses][LIC_DRIVING])
		return SendErr(playerid, "У вас отсутствует лицензия на управления транспортом!");

	if(get_job_level(playerid, SKILL_SNOWWORK) == 0)
	{
		add_player_job_skill(playerid, SKILL_SNOWWORK, 1);
	}


	give_money(playerid, -RENT_SNOW_CAR_PRICE, "Аренда снегоуборщика");

	SetPVarIntNew(playerid, "snow_work", 1); 
	SetPVarIntNew(playerid, "snow_work_cp", 1);
	SetPVarIntNew(playerid, "snow_work_type", type);

	SendSucc(playerid, "Вы устроились на работу снегоруборщика");
	SendInf(playerid, "Отправляйтесь убирать снег по улицам города");

	//check_accept_quest_newyear(playerid, 0);

	new 
		pos = random(5);
	swork_vehicle[playerid] = CreateVehicle(578, gSnowWorkSpawn[type-1][pos][0], gSnowWorkSpawn[type-1][pos][1], gSnowWorkSpawn[type-1][pos][2], gSnowWorkSpawn[type-1][pos][3], -1, -1, -1);


	vehicle[swork_vehicle[playerid]][cFuel] = 90.0;
	vehicle[swork_vehicle[playerid]][cHealth] = 1000.0;
	vehicle[swork_vehicle[playerid]][cIsCreated] = true;
	vehicle[swork_vehicle[playerid]][cOwnTo] = VEHICLE_SNOW_WORK;
	vehicle[swork_vehicle[playerid]][cLock] = 1;
	vehicle[swork_vehicle[playerid]][consumables_oil] = 1000.0;

	vehicle_lock_status(swork_vehicle[playerid], false);

	vehicle[swork_vehicle[playerid]][cFuel] = 80;

	new
		v = GetPlayerVehicleID(playerid);	

	pTemp[playerid][rent_car] = swork_vehicle[playerid];


	PutPlayerInVehicle(playerid, swork_vehicle[playerid], 0);

	SetPlayerRaceCheckpoint(playerid, 0, gSnowWorkCP[type-1][0][0], gSnowWorkCP[type-1][0][1], gSnowWorkCP[type-1][0][2], gSnowWorkCP[type-1][1][0], gSnowWorkCP[type-1][1][1], gSnowWorkCP[type-1][1][2], 4.0);

	return true;
}

stock end_snow_work(playerid)
{
	if(GetPVarIntNew(playerid, "snow_work"))
	{
		new
			count_cp = GetPVarIntNew(playerid, "snow_work_cp")-1,
			money;

		if(get_job_level(playerid, SKILL_SNOWWORK) == 1)
		{
			money = count_cp*PRICE_SNOW_WORKING_1;
		}
		else if(get_job_level(playerid, SKILL_SNOWWORK) == 2)
		{
			money = count_cp*PRICE_SNOW_WORKING_1;
		}
		else if(get_job_level(playerid, SKILL_SNOWWORK) == 3)
		{
			money = count_cp*PRICE_SNOW_WORKING_1;
		}
		else if(get_job_level(playerid, SKILL_SNOWWORK) == 4)
		{
			money = count_cp*PRICE_SNOW_WORKING_1;
		}
		else if(get_job_level(playerid, SKILL_SNOWWORK) == 5)
		{
			money = count_cp*PRICE_SNOW_WORKING_1;
		}

		DeletePVarNew(playerid, "snow_work");
		DeletePVarNew(playerid, "snow_work_cp");
		DeletePVarNew(playerid, "snow_work_type");
		DeletePVarNew(playerid, "left_snow_car");

		PlayerTextDrawHideEx(playerid, snow_work_player[0][playerid]);
		PlayerTextDrawHideEx(playerid, snow_work_player[1][playerid]);
		PlayerTextDrawHideEx(playerid, snow_work_player[2][playerid]);

		new 
			v = pTemp[playerid][rent_car];

		if(v == INVALID_VEHICLE_ID) 
			return true;

		if(vehicle[v][cOwnTo] != VEHICLE_SNOW_WORK) 
			return true;

		pTemp[playerid][rent_car] = INVALID_VEHICLE_ID;
		pTemp[playerid][rent_car_spawn_timer] = INVALID_TIMER_ID;

		DestroyVehicle(swork_vehicle[playerid]);
		swork_vehicle[playerid] = INVALID_VEHICLE_ID;

		DisablePlayerCheckpoint(playerid);
		DisablePlayerRaceCheckpoint(playerid);

		format(String144, sizeof(String144), "Вы закончили работу снегоуборщика и получили "cGR"%d рублей", money);
		SendSucc(playerid, String144);
		give_money(playerid, money, "Зарплата снегоуборщика");
	}
	return true;
}

stock snow_work_cp_enter(playerid)
{
	if(!GetPVarIntNew(playerid, "snow_work") && !GetPVarIntNew(playerid, "snow_work_cp"))
		return true;

	if(GetPlayerVehicleID(playerid) != swork_vehicle[playerid])
		return true;

	DisablePlayerRaceCheckpoint(playerid);
	SetPVarIntNew(playerid, "snow_work_cp", GetPVarIntNew(playerid, "snow_work_cp")+1);

	give_next_snow_work_cp(playerid, GetPVarIntNew(playerid, "snow_work_cp"));


	return true;
}

stock give_next_snow_work_cp(playerid, id)
{
	if(!GetPVarIntNew(playerid, "snow_work") && !GetPVarIntNew(playerid, "snow_work_cp"))
		return true;
 
	if(!GetPVarIntNew(playerid, "snow_work_type"))
		return true;

	new 
		type = GetPVarIntNew(playerid, "snow_work_type");

	if(gSnowWorkCP[type-1][id-1][0] == 0.0)
	{
		end_lap_snow_work(playerid);
	}
	else if(gSnowWorkCP[type-1][id][0] == 0.0)
	{
		SetPlayerRaceCheckpoint(playerid, 1, gSnowWorkCP[type-1][id-1][0], gSnowWorkCP[type-1][id-1][1], gSnowWorkCP[type-1][id-1][2], -1, -1, -1, 4.0);
	}
	else
	{
		SetPlayerRaceCheckpoint(playerid, 0, gSnowWorkCP[type-1][id-1][0], gSnowWorkCP[type-1][id-1][1], gSnowWorkCP[type-1][id-1][2], gSnowWorkCP[type-1][id][0], gSnowWorkCP[type-1][id][1], gSnowWorkCP[type-1][id][2], 4.0);
	}
	return true;
}

stock end_lap_snow_work(playerid)
{
	new
		string[256],

		count_cp = GetPVarIntNew(playerid, "snow_work_cp")-1,
		money;





	if(get_job_level(playerid, SKILL_SNOWWORK) == 1)
	{
		money = count_cp*PRICE_SNOW_WORKING_1;
	}
	else if(get_job_level(playerid, SKILL_SNOWWORK) == 2)
	{
		money = count_cp*PRICE_SNOW_WORKING_1;
	}
	else if(get_job_level(playerid, SKILL_SNOWWORK) == 3)
	{
		money = count_cp*PRICE_SNOW_WORKING_1;
	}
	else if(get_job_level(playerid, SKILL_SNOWWORK) == 4)
	{
		money = count_cp*PRICE_SNOW_WORKING_1;
	}
	else if(get_job_level(playerid, SKILL_SNOWWORK) == 5)
	{
		money = count_cp*PRICE_SNOW_WORKING_1;
	}

	add_player_job_skill(playerid, SKILL_SNOWWORK, 1);

	SetPVarIntNew(playerid, "count_working_snow", GetPVarIntNew(playerid, "count_working_snow")+1);
	check_accept_quest_newyear(playerid, 1);

	format(string, sizeof(string), "\n\
	"cWH"Вы проехали полный круг и заработали "cGR"%d рублей!\n\
	"cWH"Вы хотите продолжить работу "cLRED"снегоуборщика?", money);

	SPD(playerid, DIALOG_SELECT_SNOW_WORK, 0, !""cLRED"Работа снегоуборщика | "cWH"Информация", string, !"Продолжить", !"Закончить");

	return true;
}

callback:: spawn_rent_car_snow_work(i, v, time)
{

	if(IsPlayerConnected(i))
	{	
		time--;

		if(!time)
		{
			end_snow_work(i);
			return true;
		}
		pTemp[i][rent_car_spawn_timer] = SetTimerEx("spawn_rent_car_snow_work", 1000, false, "iii", i, v, time);
	}
	return true; 
}
