// Арзамас


#define GENERAL_HOSPITAL_ADVERT					-1069.5731, -1467.5913, 23.4042	
#define GENERAL_HOSPITAL_EXIT					-1053.6581, -1468.8474, 23.4120
#define GENERAL_HOSPITAL_EXIT_STREER			417.3951, 1757.2437, 14.4013, 67.5056
#define GENERAL_HOSPITAL_ENTER					420.2466,1756.8010,14.4059
#define GENERAL_HOSPITAL_ENTER_INT				-1053.5129,-1465.9230,23.4042,354.8417

#define GENERAL_HOSPITAL_EXIT_KRISHA			445.5736,1745.9015,36.7942
#define GENERAL_HOSPITAL_EXIT_KRISHA_INT		-1077.2445,-1447.5093,23.4042,270.7514
#define GENERAL_HOSPITAL_ENTER_KRISHA			-1079.5548,-1447.7496,23.4116
#define GENERAL_HOSPITAL_ENTER_KRISHA_STREET	444.4634,1743.0697,36.7942,162.3182

#define GENERAL_HOSPITAL_EXIT_2					-1052.2251,-1440.9907,23.4042
#define GENERAL_HOSPITAL_EXIT_STREER_2			458.7354,1718.3386,14.4013,249.6215
#define GENERAL_HOSPITAL_ENTER_2				455.9554,1718.7946,14.4013
#define GENERAL_HOSPITAL_ENTER_INT_2			-1054.3804,-1441.1384,23.4042,89.6516

#define GENERAL_HOSPITAL_GLAV_MENU				-1067.3118,-1459.1903,23.4042


// Южный

#define GENERAL_HOSPITAL_2_ENTER				 2112.9355,-2392.8523,23.0883
#define GENERAL_HOSPITAL_2_EXIT					 -1053.6581, -1468.8474, 23.4120

#define GENERAL_HOSPITAL_2_ENTER_INT			-1053.5129,-1465.9230,23.4042,354.8417
#define GENERAL_HOSPITAL_2_EXIT_INT				2112.7271,-2389.8420,22.6821,2.7525

stock create_hospital_pickup()
{

	// Южный 

	CreateDynamicPickup(13702, 23, GENERAL_HOSPITAL_2_ENTER, -1, -1, -1, STREAM_DISTANCE_DYNAMIC_PICKUP);

	hospital_2_enter_pickup = CreateDynamicSphere(GENERAL_HOSPITAL_2_ENTER, 1.0, -1, -1); 
  	CreateDynamic3DTextLabel(""cWH"Больница г.Южный\n "cBLUE"Вход в здание",-1, \
  	GENERAL_HOSPITAL_2_ENTER, 6.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);

  	hospital_2_exit_pickup = CreateDynamicSphere(GENERAL_HOSPITAL_EXIT, 1.0, 1, -1); 

	// Арзамас

	hospital_advert = create_circle_pickup(GENERAL_HOSPITAL_ADVERT, TRIGGER_LRED);
	hospital_exit_pickup = CreateDynamicSphere(GENERAL_HOSPITAL_EXIT, 1.0, 0, -1); 
	hospital_enter_pickup = CreateDynamicSphere(GENERAL_HOSPITAL_ENTER, 1.0, -1, -1); 

	hospital_exit_pickup_2 = CreateDynamicSphere(GENERAL_HOSPITAL_EXIT_2, 1.0, 0, -1); 
	hospital_enter_pickup_2 = CreateDynamicSphere(GENERAL_HOSPITAL_ENTER_2, 1.0, -1, -1); 


	CreateDynamicPickup(13702, 23, GENERAL_HOSPITAL_EXIT, -1, -1, -1, STREAM_DISTANCE_DYNAMIC_PICKUP);
	CreateDynamicPickup(13702, 23, GENERAL_HOSPITAL_ENTER, -1, -1, -1, STREAM_DISTANCE_DYNAMIC_PICKUP);
	CreateDynamicPickup(13702, 23, GENERAL_HOSPITAL_EXIT_2, -1, -1, -1, STREAM_DISTANCE_DYNAMIC_PICKUP);
	CreateDynamicPickup(13702, 23, GENERAL_HOSPITAL_ENTER_2, -1, -1, -1, STREAM_DISTANCE_DYNAMIC_PICKUP);


  	CreateDynamic3DTextLabel(""cWH"Больница г.Арзамас\n "cBLUE"Вход в здание",-1, \
  		GENERAL_HOSPITAL_EXIT_KRISHA, 6.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);

  	CreateDynamic3DTextLabel(""cWH"Больница г.Арзамас\n"cBLUE"Выход на задний двор",-1, \
  		GENERAL_HOSPITAL_EXIT_2, 6.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);

  	CreateDynamic3DTextLabel(""cWH"Больница г.Арзамас\n"cBLUE"Задний вход",-1, \
  		GENERAL_HOSPITAL_ENTER_2, 6.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);

  	CreateDynamic3DTextLabel(""cWH"Больница г.Арзамас\n "cBLUE"Главный вход",-1, \
  		GENERAL_HOSPITAL_ENTER, 6.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);

  	CreateDynamic3DTextLabel(""cWH"Лучшие сотрудники\n"cLRED"больницы",-1, \
  		GENERAL_HOSPITAL_ADVERT, 6.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);


  	hospital_glav_menu = create_circle_pickup(GENERAL_HOSPITAL_GLAV_MENU, TRIGGER_LRED);


	return true;
}

stock enter_hospital_2_general(playerid)
{
	SetPlayerTime(playerid, 12, 0);

	SetPlayerPosEx(playerid, GENERAL_HOSPITAL_2_ENTER_INT);
	SetCameraBehindPlayer(playerid);
	SetPlayerVirtualWorld(playerid, 1);

	pTemp[playerid][pInHospital] = true;

	return true;
}

stock exit_hospital_2_general(playerid)
{
	new Float:hp;
	GetPlayerHealth(playerid, hp);

	if(hp < 80.0) 
		return SendInf(playerid, "Вы не можете выйти из больницы, пока не вылечитесь!");

	SetPlayerPosEx(playerid, GENERAL_HOSPITAL_2_EXIT_INT);
	SetCameraBehindPlayer(playerid);
	SetPlayerVirtualWorld(playerid, 0);

	pTemp[playerid][pInHospital] = false;

	new ho,mo,so;
	gettime(ho,mo,so);
	SetPlayerTime(playerid , ho,mo);	

	return true;
}

stock enter_hospital_pickup_krisha(playerid)
{


	return true;
}

stock exit_hospital_pickup_krisha(playerid)
{


	return true;	
}


stock enter_hospital_pickup_2(playerid)
{
	pTemp[playerid][pInHospital] = true;

	SetPlayerTime(playerid , 12, 0);

	SetPlayerPosEx(playerid, GENERAL_HOSPITAL_ENTER_INT_2);

	return true;
}

stock exit_hospital_pickup_2(playerid)
{
	new Float:hp;
	GetPlayerHealth(playerid, hp);

	if(hp < 80.0) 
		return SendInf(playerid, "Вы не можете выйти из больницы, пока не вылечитесь!");

	pTemp[playerid][pInHospital] = false;

	new ho,mo,so;
	gettime(ho,mo,so);
	SetPlayerTime(playerid , ho,mo);


	SetPlayerPosEx(playerid, GENERAL_HOSPITAL_EXIT_STREER_2);

	return true;
}

stock enter_hospital_pickup(playerid)
{
	pTemp[playerid][pInHospital] = true;

	SetPlayerTime(playerid , 12, 0);

	SetPlayerPosEx(playerid, GENERAL_HOSPITAL_ENTER_INT);

	return true;
}

stock exit_hospital_pickup(playerid)
{
	new Float:hp;
	GetPlayerHealth(playerid, hp);

	if(hp < 80.0) 
		return SendInf(playerid, "Вы не можете выйти из больницы, пока не вылечитесь!");

	pTemp[playerid][pInHospital] = false;

	new ho,mo,so;
	gettime(ho,mo,so);
	SetPlayerTime(playerid , ho,mo);


	SetPlayerPosEx(playerid, GENERAL_HOSPITAL_EXIT_STREER);

	return true;
}



CMD:medcard(playerid, params[])
{
	if(pData[playerid][pFraction] != 2)
		return SendErr(playerid, "Команда доступна только медикам");

	if(pData[playerid][pRank] < 5)
		return SendErr(playerid, "Команда доступна с 5 ранга");

	if(GetPVarIntNew(playerid, "offer_medcard") || GetPVarIntNew(playerid, "recieve_medcard"))
		return SendErr(playerid, "У вас уже имеется активное предложение");

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/medcard [ID игрока]");

	if(!IsPlayerConnected(params[0]) || IsKicked(params[0])) 
		return SendErr(playerid, "Неверный ID");

	if(!IsPlayerInRangeOfPoint(playerid, 80.0,-1058.5303,-1451.0730,23.4042)) 
		return SendErr(playerid, "Вы должны быть в больнице");

	if(GetPlayerDistanceToPlayer(playerid, params[0]) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(params[0])) 
		return SendErr(playerid, "Вы далеко друг от друга");

	if(pData[params[0]][pMedcard] > 0)
		return SendErr(playerid, "У игрока уже имеется мед. карта");

	if(GetPlayerMoneyEx(params[0]) < MEDCARD_PRICE)
		return SendErr(playerid, "У игрока недостаточно денег");

	format(String144, sizeof(String144), "Вы предложили "cGR"%s "cWH"получить мед карту за "cGR"%i рублей", pData[params[0]][pNickname], MEDCARD_PRICE);
	SendSucc(playerid, String144);

	SetPVarIntNew(playerid, "offer_medcard", params[0]+1);
	SetPVarIntNew(params[0], "recieve_medcard", playerid+1);

	format(String256, sizeof(String256), "\n\
		"cWH"Врач "cBLUE"%s "cWH"предлагает Вам получить мед. карту\n\n\
		"cWH"Стоимость получения: "cBLUE"%i рублей\n\
		"cWH"Срок действия мед. карты: "cBLUE"30 дней\n\n\
		"cWH"Вы действительно хотите получить медицинскую карту?", pData[playerid][pNickname], MEDCARD_PRICE);

	SPD(params[0], DIALOG_SELL_MEDCARD, DIALOG_STYLE_MSGBOX, !""cBLUE"Предложение получения мед.карты", String256, !"Принять", !"Отменить");

	return true;
}

CMD:med(playerid, params[])
{
	if(sscanf(params, "d", params[0])) 
	{
		show_medcard(playerid, playerid);

		SendInf(playerid, "/med [ID игрока]");
		return true;
	}

	if(!IsPlayerConnected(params[0]) || IsKicked(params[0])) 
		return SendErr(playerid, "Неверный ID");

	if(GetPlayerDistanceToPlayer(playerid, params[0]) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(params[0])) 
		return SendErr(playerid, "Вы далеко друг от друга");

	format(String144, sizeof(String144), "Вы предложили "cBLUE"%s "cWH"показать медицинскую карту", pData[params[0]][pNickname]);
	SendSucc(playerid, String144);

	format(String256, sizeof(String256), "\n\
		"cWH"Игрок "cBLUE"%s "cWH"предлагает Вам показать свою мед. карту\n\n\
		"cWH"Вы действительно хотите посмотреть медицинскую карту?", pData[playerid][pNickname]);

	SPD(params[0], DIALOG_ACCEPT_MEDCARD, DIALOG_STYLE_MSGBOX, !""cBLUE"Медицинская карта", String256, !"Принять", !"Отменить");


	SetPVarIntNew(playerid, "offer_show_medcard", params[0]+1);
	SetPVarIntNew(params[0], "recieve_show_medcard", playerid+1);

	return true;
}

stock dialog_medcard(playerid, dialogid, response)// OnDialogResponse
{
	switch(dialogid)
	{
		case DIALOG_SELL_MEDCARD:
		{
			new 
				offerid = GetPVarIntNew(playerid, "recieve_medcard")-1;

			if(!response)
			{
				DeletePVarNew(playerid, "recieve_medcard");

				SendInf(playerid, "Вы отказались от получения мед.карты");

				if(GetPVarIntNew(offerid, "offer_medcard")-1 == playerid)
				{
					DeletePVarNew(offerid, "offer_medcard");
					format(String64, sizeof(String64), "%s отказался от получения медкарты", pData[playerid][pNickname]);
					SendInf(offerid, String64);
				}
				return true;
			}

			if(GetPVarIntNew(offerid, "offer_medcard") != playerid+1)
				return SendErr(playerid, "Предложение неактивно");

			DeletePVarNew(playerid, "recieve_medcard");
			DeletePVarNew(offerid, "offer_medcard");

			if(GetPlayerDistanceToPlayer(playerid, offerid) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(offerid))
				return SendErr(playerid, "Вы находитесь далеко друг от друга");	

			if(GetPlayerMoneyEx(playerid) < MEDCARD_PRICE)
				return SendErr(playerid, "У Вас недостаточно денег");

			give_money(playerid, -MEDCARD_PRICE, "Получение медкарты");

			new 
				salary = floatround(MEDCARD_PRICE*0.25);

			give_money(offerid, salary, "Выдача медкарты");

			pData[playerid][pMedcard] = 30;
			UpdatePlayerData(playerid, "medkart", pData[playerid][pMedcard]);

			SendSucc(playerid, "Вы получили мед. карту на 30 дней");
			SendInf(playerid, "Чтобы посмотреть, используйте команду "cBLUE"/med");

			format(String64, sizeof(String64), "%s купил мед. карту", pData[playerid][pNickname]);
			SendSucc(offerid, String64);

			format(String64, sizeof(String64), "%s мед. карту %s", pData[offerid][pSex] == 1 ? ("выдал") : ("выдала"), pData[playerid][pNickname]);
			MeAction(offerid, String64);

			return true;
		}
		case DIALOG_ACCEPT_MEDCARD:
		{
			new 
				offerid = GetPVarIntNew(playerid, "recieve_show_medcard")-1;

			if(!response)
			{
				DeletePVarNew(playerid, "recieve_show_medcard");

				SendInf(playerid, "Вы отказались от просмотра мед.карты");

				if(GetPVarIntNew(offerid, "offer_show_medcard")-1 == playerid)
				{
					DeletePVarNew(offerid, "offer_show_medcard");
					format(String64, sizeof(String64), "%s отказался от просмотра медкарты", pData[playerid][pNickname]);
					SendInf(offerid, String64);
				}
				return true;
			}

			if(GetPVarIntNew(offerid, "offer_show_medcard") != playerid+1)
				return SendErr(playerid, "Предложение неактивно");

			DeletePVarNew(playerid, "recieve_show_medcard");
			DeletePVarNew(offerid, "offer_show_medcard");

			if(GetPlayerDistanceToPlayer(playerid, offerid) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(offerid))
				return SendErr(playerid, "Вы находитесь далеко друг от друга");	

			show_medcard(offerid, playerid);
			return true;
		}
		case DIALOG_EXPRESS_HEAL:
		{
			if(!response)
				return true;

			if(GetPlayerMoneyEx(playerid) < EXPRESS_HEAL_PRICE) 
				return SendErr(playerid, "У Вас недостаточно денег для оплаты услуги");

			SetPlayerHealth(playerid, 100.0);

			give_money(playerid, -EXPRESS_HEAL_PRICE, "Экспресс лечение");

			SendSucc(playerid, "Вы прошли экспресс лечение");
			return true;
		}
	}
	return true;
}

stock show_medcard(playerid, offerid)
{
	if(playerid == offerid)
	{
		format(String64, sizeof(String64), "%s мед. карту и рассматривает её", pData[playerid][pSex] == 1 ? ("достал") : ("достала"));
		MeAction(playerid, String64);
	}
	else
	{
		format(String64, sizeof(String64), "%s мед. карту и показал %s", pData[playerid][pSex] == 1 ? ("достал") : ("достала"), pData[offerid][pNickname]);
		MeAction(playerid, String64);
	}

	format(String256, sizeof(String256), "\n\
		"cWH"Имя: "cBLUE"%s\n\
		"cWH"Возраст: "cBLUE"%i\n\
		"cWH"Пол: "cBLUE"%s\n\
		"cWH"Медицинский осмотр: "cBLUE"%s", 
		pData[playerid][pNickname], 
		pData[playerid][pAge],
		pData[playerid][pSex] == 1 ? ("Мужской") : ("Женский"),
		pData[playerid][pMedcard] == 0 ? ("Не пройден") : ("Пройден"));

	if(pData[playerid][pMedcard] > 0)
	{
		format(String256, sizeof(String256), "%s\n\
			"cWH"Осталось дней: "cBLUE"%i", String256, pData[playerid][pMedcard]);
	}

	SPD(offerid, INVALID_DIALOG_ID, DIALOG_STYLE_MSGBOX, !""cBLUE"Медицинская карта", String256, !"Закрыть", "");
	return true;
}


stock load_express_heal() // OnGameModeInit
{
	CreateActor(70, -1062.7406,-1459.0540,23.4042,180.3443);
	express_heal = create_circle_pickup(-1062.5680,-1460.9358,23.4042, TRIGGER_LRED);
	CreateDynamic3DTextLabel(""cWH"Экспресс лечение\n"cLRED"[Встаньте на пикап]", -1,-1062.5680,-1460.9358,23.4042,5.0);
}

stock enter_area_express_heal(playerid, areaid) // OnPlayerEnterDynamicArea
{
	if(areaid == express_heal)
	{
		new 
			Float:health;
		GetPlayerHealth(playerid, health);

		new 
			string[200];

		if(get_medic_in_hospital(playerid) > 0)
		{
			format(string, sizeof(string), "\n\n\n\
				"cWH"Врачей в больнице: "cLRED"%i\n\
				"cWH"Экспресс лечение недоступно\n\n\n", get_medic_in_hospital(playerid));

			return SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Экспресс лечение", string, !"Закрыть", "");
		}

		if(health == 100)
			return SendErr(playerid, "Вы не нуждаетесь в лечении");

		format(string, sizeof(string), "\n\n\n\
			"cWH"Вы можете пройти автоматическое лечение\n\
			"cWH"Стоимость услуги: "cGR"%i рублей.\n\n\n", EXPRESS_HEAL_PRICE);

		SPD(playerid, DIALOG_EXPRESS_HEAL, DIALOG_STYLE_MSGBOX, 
		!""cBLUE"Экспресс лечение", string, !"Лечение", !"Закрыть");
	}
	return true;
}

stock get_medic_in_hospital(playerid)
{
	new 
		count;
	foreach(new i: logged_players)
	{
		if(GetPlayerDistanceToPlayer(playerid,i) < 75.0)
		{
			if(pData[i][pFraction] == 2 && pTemp[i][pAFK] < 60)
				count++;
		}
	}
	return count;
}