static const Float:parking_vehicle_position_spawn[][] = 
{
	{208.1463,767.3187,1204.8004,269.8221},
	{208.0674,762.2500,1204.8002,269.8317},
	{208.1684,757.3200,1204.7836,269.6949},
	{208.0060,752.3203,1204.8000,271.3058},
	{208.0905,747.5128,1204.8000,270.0843},
	{208.0782,742.2146,1204.8002,269.6762},
	{208.0898,737.2557,1204.8002,270.0638},
	{208.1334,732.2776,1204.8003,269.6395},
	{208.2562,727.4539,1204.8003,269.0322},
	{208.1987,722.2975,1204.8000,270.0293},
	{240.8778,709.6671,1204.8002,89.8134},
	{240.8877,714.4504,1204.8003,89.4785},
	{240.8555,719.4924,1204.8003,90.3186},
	{240.8822,724.6876,1204.8003,89.1618},
	{240.8223,729.6494,1204.8000,89.6815},
	{240.7738,734.6984,1204.8003,91.2178},
	{240.8063,739.6011,1204.8002,90.3948},
	{240.7807,744.7568,1204.8002,90.4129},
	{240.7022,749.4707,1204.8002,90.0582},
	{240.7961,754.4873,1204.8002,90.1997},
	{240.7989,759.6038,1204.8003,89.3280},
	{240.7894,764.6894,1204.8003,90.7201},
	{240.7663,769.6769,1204.8000,89.3579},
	{240.7767,774.6529,1204.8003,90.1525},
	{240.7327,779.5587,1204.8002,90.1709},
	{240.8601,779.6183,1212.8003,90.0541},
	{240.7843,774.6144,1212.8002,90.0269},
	{240.9629,769.5863,1212.8002,88.9664},
	{240.8376,764.5198,1212.8002,90.8002},
	{240.8466,759.6646,1212.8002,89.6542},
	{240.8517,754.4620,1212.8003,90.7574},
	{240.7602,749.5272,1212.8002,89.7687},
	{240.8082,744.4370,1212.8003,89.7652},
	{240.8243,739.4323,1212.8002,89.3501},
	{240.7713,734.7468,1212.8002,89.7971},
	{240.7958,729.5035,1212.8002,88.9875},
	{240.7852,724.4621,1212.8002,88.9933},
	{240.7892,719.7066,1212.8003,90.1957},
	{240.7954,714.6702,1212.8004,90.1557},
	{240.7787,709.7963,1212.8002,89.7108},
	{208.0964,767.4138,1212.8003,270.6634},
	{208.2009,762.3363,1212.8002,270.6519},
	{208.0899,757.3771,1212.8003,270.1420},
	{208.2273,752.3450,1212.8003,269.5930},
	{208.2118,747.4121,1212.8003,269.9326},
	{208.2913,742.4914,1212.8000,270.5745},
	{208.2066,737.3331,1212.8003,270.1451},
	{208.2365,732.4765,1212.8002,270.7051},
	{208.2548,727.6165,1212.8003,268.8885},
	{208.2413,722.2386,1212.8002,270.5078}
 	
};

stock IsPlayerOnlineForBonusSalary(playerid)
{
	switch(day_player_week)
	{
		case 1:
		{
			if(pData[playerid][pOnlineDay1] >= 10800)
				return true;
		}
		case 2:
		{
			if(pData[playerid][pOnlineDay2] >= 10800)
				return true;
		}
		case 3:
		{
			if(pData[playerid][pOnlineDay3] >= 10800)
				return true;
		}
		case 4:
		{
			if(pData[playerid][pOnlineDay4] >= 10800)
				return true;
		}
		case 5:
		{
			if(pData[playerid][pOnlineDay5] >= 10800)
				return true;
		}
		case 6:
		{
			if(pData[playerid][pOnlineDay6] >= 10800)
				return true;
		}
		case 7:
		{
			if(pData[playerid][pOnlineDay7] >= 10800)
				return true;
		}
	}
	return false;
}

callback:: donate_bonus_time()
{
	new h;
	gettime(h);

	foreach(new i : logged_players)
	{
		if(h >= 15)
		{
			if(!pData[i][pPlayOnlineDonateStatus])
			{
				pData[i][pPlayOnlineDonate] ++;
				UpdatePlayerData(i, "pPlayOnlineDonate", pData[i][pPlayOnlineDonate]);
				pData[i][pPlayOnlineDonateStatus] = 1;
				UpdatePlayerData(i, "pPlayOnlineDonateStatus", pData[i][pPlayOnlineDonateStatus]);
				if(pData[i][pPlayOnlineDonate] >= 18000)
				{
					format(String144, sizeof(String144), "[Акция] "cWH"Вы отыграли 5 часов в промежуток с 15:00 до 00:00 и получили "cBLUE"%i "cWH"донат рублей", DONATE_BONUS_5_HOUR_PLAY);
					SCM(i, COLOR_BLUE, String144);

					pData[i][pDonate] += DONATE_BONUS_5_HOUR_PLAY;
					UpdatePlayerData(i, "donate", pData[i][pDonate]);
				}
			}
		}
	}
	return true;
}

CMD:action_car(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8)
    	return NoCMD(playerid);	

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/action_car [time] (72000)");

	pData[playerid][pPlayrCarStatus] = 0;
	pData[playerid][pPlayCar] = params[0];

	return true;
}

CMD:action_donate(playerid, params[])
{
    if(pData[playerid][pAdmin] < 8)
    	return NoCMD(playerid);	

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/action_donate [time] (18000)");

	pData[playerid][pPlayOnlineDonateStatus] = 0;
	pData[playerid][pPlayOnlineDonate] = params[0];

	return true;
}


stock give_bonus_vehicle_player(playerid)
{
	new random_pos = gen_random_position_parking(playerid);

	new 
		vehicle_vw;

	if(pData[playerid][pParkingVehicle] == 1)
	{
		vehicle_vw = VIRTUAL_WORLD_PARKING_1;
	}
	else if(pData[playerid][pParkingVehicle] == 2)
	{
		vehicle_vw = VIRTUAL_WORLD_PARKING_2;
	}

	format(String1024,sizeof(String1024),"INSERT INTO `player_vehicles`(`userid`,`model`,`color_1`,`color_2`, `parking_x`,`parking_y`,`parking_z`,`parking_a`, `parking_vw`, `vehicle_prize`) VALUES ('%d','%d','%d','%d','%f','%f','%f','%f','%d', '1')", pData[playerid][pMysqlID], VEHICLE_ONLINE_BONUS_MODEL, 
	152, 152, parking_vehicle_position_spawn[random_pos][0], parking_vehicle_position_spawn[random_pos][1], parking_vehicle_position_spawn[random_pos][2], parking_vehicle_position_spawn[random_pos][3], vehicle_vw);
	sql_queryEx(zConn, String1024, QUERY_THREADED);		


	SCM(playerid, -1, "");
	SendSucc(playerid, "Автомобиль припаркован на паркинге, используйте - /cars, чтобы забрать его!");
	SendInf(playerid, "Чтобы перепарковать автомобиль, используйте - /park и автомобиль будет появляться на новом месте!");

	SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Акция на автомобиль", !"\
	"cWH"Поздравляем Вас автомобилем за отыгрыш 20 часов!\n\
	"cBLUE"-"cWH" Отпарковать автомобиль: /unpark\n\
	"cBLUE"-"cWH" Припарковать автомобиль: /park\
	"cBLUE"-"cWH" Найти автомобиль: /findcar\n\n\
	Автомобиль находится на парковке в паркинге!\n\
	Чтобы забрать его, используйте команду - /cars", !"Далее", "Нет");		


	return true;
}

callback::  update_day_donate_bonus_time()
{
	foreach(new i : logged_players)
	{
		pData[i][pPlayOnlineDonate] = 0;
		UpdatePlayerData(i, "pPlayOnlineDonate", pData[i][pPlayOnlineDonate]);
	}

	sql_queryEx(zConn, "UPDATE `accounts` SET pPlayOnlineDonate = 0", QUERY_THREADED);
	return true;
}


CMD:action(playerid)
{
	return show_menu_all_action_server(playerid);
}

stock show_menu_all_action_server(playerid)
{
	new 
		global_string[1024];
	
	if(!pData[playerid][pPlayrCarStatus])
	{
		strcat(global_string, ""cBLUE"- Акция: "cWH"Отыграйте 20 часов в сумме и получите автомобиль в подарок!\n");		
	}
	if(!pData[playerid][ActionStatusMoney])
	{
		strcat(global_string, ""cBLUE"- Акция: "cWH"Отыграйте 10 часов в сумме и получите 100.000 виртуальной валюты!\n");
	}
	strcat(global_string, ""cBLUE"- Акция: "cWH"Отыграйте 5 часов за день и получите 200 донат-рублей на свой счёт!\n");	
	strcat(global_string, ""cBLUE"- Акция: "cWH"Отыграйте 3 часа за день и получите Х2 заработную плату!\n\n");	

	if(IsActionTrue)
	{
		strcat(global_string, ""cBLUE"- Акция: "cWH"Х2 пополнение донат-счёта!\n");	
	}
	if(IsActionTrue2)
	{
		strcat(global_string, ""cBLUE"- Акция: "cWH"Х2 опыта за каждый PayDay!\n");	
	}
	if(IsActionTrue4)
	{
		strcat(global_string, ""cBLUE"- Акция: "cWH"Х2 зарплаты на работа и в организациях!\n");	
	}

	strcat(global_string, "\n"cBLUE"- "cWH"Следить за прогрессом по акциям можно с помощью команды /time!\n");

	return SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Доступные акции на сервере", global_string, !"Закрыть", "");	
}