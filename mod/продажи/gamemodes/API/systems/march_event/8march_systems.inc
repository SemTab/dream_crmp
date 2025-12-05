/*

case H_ENTER:
{
	if(newkeys == KEY_WALK)
	{
		if(GetPVarIntNew(playerid, "house_tulips"))
		{
			new 
				id = GetPVarIntNew(playerid, "house_tulips")-1;

			if(id == pTemp[playerid][area_item_id])	
			return tulips_house_accept(playerid);
		}
		ApplyAnimation(playerid, "PED", "ATM", 4.1, 0, 1, 1, 0, 1, 1);
		return house_info(playerid, pTemp[playerid][area_item_id]);
	}
}

*/
stock load_all_march()
{
	AddDynamicZone(QUEST_1_GPS, 0, 1, ENTER_QUEST_TEPLICA, 1.0);// Вход в теплицу
	create_circle_pickup_o(QUEST_1_GPS, TRIGGER_LBLUE);

	CreateDynamic3DTextLabel(""cBLUE"Общественная теплица\n\
	"cWH"Нажмите "cBLUE"ALT "cWH"для входа", -1, QUEST_1_GPS, 10.0);

	CreateActor(95, 1198.3492,-563.6592,41.2923,286.4673);
	CreateDynamic3DTextLabel(""cWH"Скупщик подснежников\n\
	"cBLUE"Владимир Сергеевич", -1, 1198.3492,-563.6592,41.2923, 10.0);
	sell_snowdrops_area = CreateDynamicSphere(1198.3492,-563.6592,41.2923, 1.5, 0, -1);

	CreateActor(34, -1372.2059,2653.7720,40.5538,136.8848);
	CreateDynamic3DTextLabel(""cWH"Шахтёр\n\
	"cBLUE"Евгений Федорович", -1, -1372.2059,2653.7720,40.5538, 10.0);
	take_brilliant_area = CreateDynamicSphere(-1372.2059,2653.7720,40.5538, 1.5, 0, -1);

	CreateActor(98, 2333.8721,-2596.8071,21.8168,149.3248);
	CreateDynamic3DTextLabel(""cWH"Ювелирщик\n\
	"cBLUE"Александр Владимирович", -1, 2333.8721,-2596.8071,21.8168, 10.0);
	sell_brilliant_area = CreateDynamicSphere(2333.8721,-2596.8071,21.8168, 1.5, 0, -1);


	CreateDynamicPickup(325, 21, 74.3814, -627.1414, 1208.0226, QUEST_TEPLICA_VW, -1);
	CreateDynamicPickup(325, 21, 78.4228,-627.2742,1208.0249, QUEST_TEPLICA_VW, -1);
	CreateDynamicPickup(325, 21, 78.4623,-619.5254,1208.0245, QUEST_TEPLICA_VW, -1);
	CreateDynamicPickup(325, 21, 74.4831,-619.2411,1208.0237, QUEST_TEPLICA_VW, -1);
	CreateDynamicPickup(325, 21, 74.4815,-611.8945,1208.0237, QUEST_TEPLICA_VW, -1);
	CreateDynamicPickup(325, 21, 78.4669,-612.1360,1208.0244, QUEST_TEPLICA_VW, -1);

	flower_area[0] = CreateDynamicSphere(74.3814, -627.1414, 1208.0226, 1.0, QUEST_TEPLICA_VW, -1);
	flower_area[1] = CreateDynamicSphere(78.4228,-627.2742,1208.0249, 1.0, QUEST_TEPLICA_VW, -1);
	flower_area[2] = CreateDynamicSphere(78.4623,-619.5254,1208.0245, 1.0, QUEST_TEPLICA_VW, -1);
	flower_area[3] = CreateDynamicSphere(74.4831,-619.2411,1208.0237, 1.0, QUEST_TEPLICA_VW, -1);
	flower_area[4] = CreateDynamicSphere(74.4815,-611.8945,1208.0237, 1.0, QUEST_TEPLICA_VW, -1);
	flower_area[5] = CreateDynamicSphere(78.4669,-612.1360,1208.0244, 1.0, QUEST_TEPLICA_VW, -1);

	for(new i; i < SNOWDROPS_COUNT; i++)
	{
		snowdrops_area[i] = CreateDynamicSphere(gSnowDrops[i][0], gSnowDrops[i][1], gSnowDrops[i][2], 1.0);
		snowdrops_pickup[i] = CreateDynamicPickup(325, 21, gSnowDrops[i][0], gSnowDrops[i][1], gSnowDrops[i][2]);
	}
 
	return true;
}

stock area_march_quest(playerid, areaid)
{
	if(areaid >= flower_area[0] && areaid <= flower_area[5])
	{
		if(pData[playerid][pQuestMarch1] >= 20)
			return true;

		format(String1024, sizeof(String1024), "\n\
			"cWH"Восьмое марта не только женский праздник, но и очередной повод для всех барыг подзаработать.\n\
			В этот раз вам не потребуется искать подходящие коробочки под шайбы,\n\
			чтобы порадовать бабушку, - всё что нужно сделать, это зайти в теплицу и успеть вырастить\n\
			как можно больше тюльпанов и доставить их заказчикам.\n\
			Порадуй дам цветами, ведь в начале весны их не так уж и просто достать.\n\n\
			"cBLUE"Задание:\n\
			"cWH"Вырастите 20 тюльпанов на продажу и развезите их заказчикам.\n\n\
			"cBLUE"Прогресс:\n\
			"cWH"Выращено тюлпанов: "cGREY"%i из 20\n\
			"cWH"Развезено тюльпанов: "cGREY"%i", 
			GetPVarIntNew(playerid, "march_tulips"), pData[playerid][pQuestMarch1]);

		return SPD(playerid, DIALOG_MARCH_QUEST_1, DIALOG_STYLE_MSGBOX, !""cBLUE"Тюльпаны-ландыши",  String1024, !"Вырастить", !"Закрыть");
	}
	else if(areaid == sell_snowdrops_area)
	{
		if(pData[playerid][pQuestMarch2] >= 20)
			return SCM(playerid, CBLUE, "Владимир Сергеевич: "cWH"Ты уже принёс мне нужное количество подснежников");

		if(!pData[playerid][pSnowdrops])
			return SCM(playerid, CBLUE, "Владимир Сергеевич: "cWH"И зачем ты пришёл? У тебя нет подснежников!");

		dialog_snowdrops(playerid);
	}
	else if(areaid == take_brilliant_area)
	{
		if(pData[playerid][pQuestMarch4] >= 1)
			return SCM(playerid, CBLUE, "Евгений Федорович: "cWH"У меня нет для тебя работы");

		if(GetPVarIntNew(playerid, "take_brilliants"))
		{
			SetPlayerQuestCheckpoint(playerid, -1372.2059,2653.7720,40.5538, 4.0);
			return SCM(playerid, CBLUE, "Евгений Федорович: "cWH"Ты уже взял бриллианты, доставь их ювелирщику");
		}

		return SPD(playerid, DIALOG_TAKE_BRILLIANTS, DIALOG_STYLE_MSGBOX, !""cBLUE"Евгений Федорович",  "\n\
			"cWH"Привет! У меня есть для тебя задание.\n\
			Необходимо доставить эту сумку одному известному ювелирщику.\n\
			Сможешь помочь с доставкой?", !"Помогу", !"Нет");
	}
	else if(areaid == sell_brilliant_area)
	{
		if(pData[playerid][pQuestMarch4] >= 1)
			return SCM(playerid, CBLUE, "Александр Владимирович: "cWH"Извини, я сейчас занят");

		if(GetPVarIntNew(playerid, "take_brilliants"))
		{
			pData[playerid][pQuestMarch4] = 1;
			UpdatePlayerData(playerid, "pQuestMarch4", pData[playerid][pQuestMarch4]);

			RemovePlayerAttachedObject(playerid, 0);
			DeletePVarNew(playerid, "take_brilliants");

			SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Александр Владимирович", !"\n\n\
				"cWH"Спасибо большое! Ты не представляешь насколько ты нас выручил!\n\n", !"Принять", "");

			SendSucc(playerid, "Вы выполнили квестовое задание "cBLUE"'Лучшие друзья девушек - это Бриллианты'");
			return true;
		}
		else
		{
			return SCM(playerid, CBLUE, "Александр Владимирович: "cWH"А где сумка с драгоценными камнями?");
		}
	}
	for(new i; i < SNOWDROPS_COUNT; i++)
	{
		if(areaid == snowdrops_area[i])
		{
			if(pData[playerid][pQuestMarch2] >= 20 || pData[playerid][pSnowdrops] >= 20)
				return true;

			DestroyDynamicArea(snowdrops_area[i]);
			DestroyDynamicPickup(snowdrops_pickup[i]);

			SetTimerEx("respawn_snowdrops", 600000, false, "i", i);

			pData[playerid][pSnowdrops]++;
			UpdatePlayerData(playerid, "pSnowdrops", pData[playerid][pSnowdrops]);

			ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.1, 0, 0, 0, 0, 0);

			format(String144, sizeof(String144), "Вы собрали подснежник! Всего: %i из 20", pData[playerid][pSnowdrops]);
			SendSucc(playerid, String144);

			format(String64, sizeof(String64), "~y~%i/20", pData[playerid][pSnowdrops]);

			GameTextForPlayer(playerid, String64, 2000, 5);

			if(pData[playerid][pSnowdrops] == 20)
			{
				SetPlayerQuestCheckpoint(playerid, 1198.3492,-563.6592,41.2923, 4.0);
				SendInf(playerid, "Продайте подснежники скупщику возле тепличного комплекса");
			}

		}
	}
	return true;
}

callback:: respawn_snowdrops(i)
{
	snowdrops_area[i] = CreateDynamicSphere(gSnowDrops[i][0], gSnowDrops[i][1], gSnowDrops[i][2], 1.0);
	snowdrops_pickup[i] = CreateDynamicPickup(325, 21, gSnowDrops[i][0], gSnowDrops[i][1], gSnowDrops[i][2]);
	return true;
}

stock dialog_snowdrops(playerid)
{
	format(String256, sizeof(String256), "\n\
		"cWH"Привет! Я готов купить подснежники!\n\n\
		Текущий курс продажи: "cBLUE"%i рублей за 1 шт.\n\n\
		"cWH"Вы можете продать: "cBLUE"%i шт.\n\
		"cWH"Введите количество, которое хотите продать:", PRICE_BUY_SNOWDROPS, pData[playerid][pSnowdrops]);

	SPD(playerid, DIALOG_SELL_SNOWDROPS, DIALOG_STYLE_INPUT, !""cBLUE"Владимир Сергеевич", String256, !"Продать", !"Отмена");
	return true;
}


stock enter_quest_teplica(playerid)
{
	SetPlayerPosEx(playerid, 76.5587,-608.7748,1207.7795,180.6907);
	SetPlayerVirtualWorld(playerid, QUEST_TEPLICA_VW);
	SetCameraBehindPlayer(playerid);
	return true;
}

stock show_march_quest(playerid)
{	
	format(String512, sizeof(String512), "\
		"cGREY"Квест\t"cGREY"Статус\n\
		"cBLUE"1. "cWH"Тюльпаны-ландыши\t%s\n\
		"cBLUE"2. "cWH"Вялый подснежник\t%s\n\
		"cBLUE"3. "cWH"Поздравление с 8 марта\t%s\n\
		"cBLUE"4. "cWH"Лучшие друзья девушек - это Бриллианты\t%s\n\
		"cBLUE"5. "cWH"Награда за работу\t%s", 
		pData[playerid][pQuestMarch1] >= 20 ? (""cGR"[Выполнено]") : (""cLRED"[Не выполнено]"),
		pData[playerid][pQuestMarch2] >= 20 ? (""cGR"[Выполнено]") : (""cLRED"[Не выполнено]"),
		pData[playerid][pQuestMarch3] >= 10 ? (""cGR"[Выполнено]") : (""cLRED"[Не выполнено]"),
		pData[playerid][pQuestMarch4] >= 1 ? (""cGR"[Выполнено]") : (""cLRED"[Не выполнено]"),
		pData[playerid][pQuestMarch5] >= 1 ? (""cGR"[Выполнено]") : (""cLRED"[Не выполнено]"));

	SPD(playerid, DIALOG_MARCH_QUEST_SELECT, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"8 марта", String512, !"Выбрать", !"Закрыть");
	return true;
}

stock SetPlayerQuestCheckpoint(playerid, Float:x, Float:y, Float:z, Float:size)
{
	DisablePlayerCheckpoint(playerid);
	pTemp[playerid][pGPS] = true;
	status_navigator_player(playerid, TEXTDRAW_SHOW);
	SendSucc(playerid, "Метка установлена у Вас на карте, чтобы убрать, используйте - /gps!");
	return SetPlayerCheckpoint(playerid, x, y, z, size);
}

stock dialog_march_quest_all(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{

		case DIALOG_SELL_SNOWDROPS:
		{
			if(!response)
				return true;

			if(!strlen(inputtext))
				return dialog_snowdrops(playerid);

			if(strval(inputtext) < 1 || strval(inputtext) > pData[playerid][pSnowdrops])
			{
				SendClientMessage(playerid, CBLUE, "Владимир Сергеевич: "cWH"Укажи корректное количество подснежников");
				return dialog_snowdrops(playerid);
			}

			pData[playerid][pSnowdrops] -= strval(inputtext);
			UpdatePlayerData(playerid, "pSnowdrops", pData[playerid][pSnowdrops]);

			format(String144, sizeof(String144), "Владимир Сергеевич: "cWH"Держи %i рублей за %i подснежников", strval(inputtext)*PRICE_BUY_SNOWDROPS, strval(inputtext));
			SendClientMessage(playerid, CBLUE, String144);

			pData[playerid][pQuestMarch2] += strval(inputtext);
			UpdatePlayerData(playerid, "pQuestMarch2", pData[playerid][pQuestMarch2]);

			if(pData[playerid][pQuestMarch2] >= 20)
			{
				SendClientMessage(playerid, CBLUE, "[Квест] "cWH"Вы выполнили квестовое задание "cBLUE"'Вялый подснежник'");
			}
			new 
				money = strval(inputtext) * PRICE_BUY_SNOWDROPS;

			give_money(playerid, money, "Продажа подснежников");

			format(String64, sizeof(String64), "%s подснежники", pData[playerid][pSex] == 1 ? ("продал") : ("продала"));
			MeAction(playerid, String64);

			return true;

		}

		case DIALOG_TAKE_BRILLIANTS:
		{
			if(!response)
				return SCM(playerid, CBLUE, "Евгений Федорович: Ладно, без тебя справлюсь");

			SetPVarIntNew(playerid, "take_brilliants", 1);
			SendSucc(playerid, "Вы взяли сумку с драгоценными камнями, доставьте их ювелирщику!");
			SetPlayerQuestCheckpoint(playerid, 2333.8721,-2596.8071,21.8168, 4.0);

			SetPlayerAttachedObject(playerid, 0, 18187, 5, 0.181000, 0.005999, -0.076999, 0.000000, -93.500022, 15.500000, 1.000000, 1.00, 1.000000);
		}
		case DIALOG_MARCH_QUEST_SELECT:
		{
			if(!response)
				return true;
			
			switch(listitem)
			{
				case 0:
				{
					if(pData[playerid][pQuestMarch1] >= 20)
						return SendErr(playerid, "Вы уже выполнили данное задание");

					SetPlayerQuestCheckpoint(playerid, QUEST_1_GPS, 4.0);

					return SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Тюльпаны-ландыши",  !"\n\
						"cWH"Для начала задания «Тюльпаны-ландыши» отправляйтесь к теплице\n\
						и встаньте на пикап в виде букета цветов для получения более подробной информации о задании.", !"Принять", "");
				}
				case 1:
				{
					if(pData[playerid][pQuestMarch2] >= 20)
						return SendErr(playerid, "Вы уже выполнили данное задание");

					format(String1024, sizeof(String1024), "\n\
						"cWH"В начале весны опавшие с неба снежинки неминуемо начинают таять,\n\
						превращаясь в красивые цветы - Подснежники. Вы должны помочь им освободиться\n\
						из под толщ снега, чтобы десятисантиметровые стебли вытянулись вверх,\n\
						а бутоны распустились, превратив леса, склоны, поля и утёсы в белые, цветочные, ковры.\n\n\
						"cWH"Начните своё путешествие по загородным просторам нашего региона и освободите\n\
						из под снега как можно больше Подснежников, чтобы они произросли и раскрылись,\n\
						приблизив тепло прихода настоящей весны.\n\n\
						"cBLUE"Задание:\n\
						"cWH"Найдите 20 подснежников и продайте их в тепличном холдинге.\n\n\
						"cBLUE"Прогресс:\n\
						"cWH"Собрано подснежников: "cGREY"%i из 20\n\
						"cWH"Продано подснежников: "cGREY"%i", 
						pData[playerid][pSnowdrops], pData[playerid][pQuestMarch2]);

					return SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Вялый подснежник",  String1024, 
						!"Принять", "");
				}
				case 2:
				{
					if(pData[playerid][pQuestMarch3] >= 10)
						return SendErr(playerid, "Вы уже выполнили данное задание");

					format(String512, sizeof(String512), "\n\
						"cWH"Для начала задания «Поздравление с 8 марта» отправь открытку с поздравлением\n\
						как можно большему количеству друзей с помощью команды "cGREY"/gift [Ник игрока]\n\n\
						"cBLUE"Задание:\n\
						"cWH"Отправить открытку с поздравлением как минимум 10 игрокам.\n\n\
						"cBLUE"Прогресс:\n\
						"cWH"Отправлено открыток: "cGREY"%i из 10", 
						pData[playerid][pQuestMarch3]);

					return SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Поздравление с 8 марта",  String512, 
						!"Принять", "");
				}
				case 3:
				{
					if(pData[playerid][pQuestMarch4] >= 1)
						return SendErr(playerid, "Вы уже выполнили данное задание");

					SetPlayerQuestCheckpoint(playerid, -1372.2059,2653.7720,40.5538, 4.0);

					return SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Лучшие друзья девушек - это Бриллианты",  "\n\
						"cWH"Ни для кого не секрет, что все представительницы прекрасного пола обожают драгоценные камни.\n\
						И в этот прекрасный день - 8 Марта, на Шахте произошли невероятные, можно даже сказать сказочные события...\n\
						Бриллиантовая лихорадка! Из рудных жил то и дело вываливаются одни лишь только неогранённые алмазы.\n\
						Мы собираем их в сумки, а вам лишь остаётся взять их и на любом транспорте доставить их\n\
						ювелирщику, чтобы те попали в руки дам почти за даром, ведь сегодня мы рушим привычные цены!\n\n\
						"cBLUE"Задание:\n\
						"cWH"Забрать с шахты сумку с драгоценными камнями и доставить её ювелирщику.", 
						!"Принять", "");
				}
				case 4:
				{
					if(pData[playerid][pQuestMarch1] < 20 || pData[playerid][pQuestMarch2] < 20 || pData[playerid][pQuestMarch3] < 10 || pData[playerid][pQuestMarch4] < 1)
						return SendInf(playerid, "Выполните все предыдущие задания");

					if(pData[playerid][pQuestMarch5] == 1)
						return SendErr(playerid, "Вы уже выполнили данное задание");

					give_money(playerid, MARCH_QUEST_MONEY, "Награда за квест 8 марта");

					pData[playerid][pDonate] += MARCH_QUEST_DONATE;
					UpdatePlayerData(playerid, "donate", pData[playerid][pDonate]);

					pData[playerid][pQuestMarch5] = 1;
					UpdatePlayerData(playerid, "pQuestMarch5", pData[playerid][pQuestMarch5]);

					pData[playerid][pExp] += MARCH_QUEST_EXP;
					UpdatePlayerData(playerid, "exp", pData[playerid][pExp]);
					if(pData[playerid][pExp] >= pData[playerid][pLevel]*6)
					{
						SendClientMessage(playerid, CGREEN, "Ваш игровой уровень и IC возраст повысился.");
					    pData[playerid][pExp] = pData[playerid][pExp] - (pData[playerid][pLevel]*6);
						pData[playerid][pLevel]++;
						pData[playerid][pAge]++;
						SetPlayerScore(playerid, pData[playerid][pLevel]);
						UpdatePlayerData(playerid, "exp", pData[playerid][pExp]);
						UpdatePlayerData(playerid, "level", pData[playerid][pLevel]);
						UpdatePlayerData(playerid, "age", pData[playerid][pAge]);
					}

					format(String256, sizeof(String256), "\n\
						"cWH"Ты выполнил всю квестовую линию, посвященную празднику 8 марта!\n\
						За свою работы ты получаешь:\n\
						"cBLUE"- "cWH"%i рублей\n\
						"cBLUE"- "cWH"%i EXP\n\
						"cBLUE"- "cWH"%i донат рублей", 
						MARCH_QUEST_MONEY, MARCH_QUEST_EXP, MARCH_QUEST_DONATE);

					SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Награда за работу", String256, !"Принять", "");

					SendClientMessage(playerid, CBLUE, "[Квест] "cWH"Вы выполнили всю квестовую линию, посвященную празднованию 8 марта");
					return true;
				}
			}
		}
		case DIALOG_MARCH_QUEST_1:
		{
			if(!response)
				return true;

			if(GetPVarIntNew(playerid, "march_tulips") == 20)
				return SendErr(playerid, "Вам необходимо развести оставшиеся тюльпаны");

			ClearAnimations(playerid);
			TogglePlayerControllable(playerid, 0);
			ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.1, 1, 0, 0, 0, 0);

			SetTimerEx("timer_tulips", 10000, false, "i", playerid);
			return true;
		}
		case DIALOG_INPUT_GIFT_MESSAGE:
		{
			if(!response)
				return true;

			new 
				id = GetPVarIntNew(playerid, "gift_recieveid");

			DeletePVarNew(playerid, "gift_recieveid");

			if(pData[playerid][pMysqlID] == id)
				return SendErr(playerid, "Вы не можете отправить открытку себе");

			if(!strlen(inputtext))
			{
				input_gift_message(playerid, id);
				return SendErr(playerid, "Ваше поздравление должно содержать текст");
			}

			if(isContainForribenSymbols(inputtext) || isContainSQLInjection(inputtext))
			{
				input_gift_message(playerid, id);
				return SendErr(playerid, "Ваш текст содержит запрещенные символы");
			}

			for(new i = 0, idx = strlen(inputtext); i < idx; i++)
			{
				if(inputtext[i] == '*')
				{
					input_gift_message(playerid, id);
					return SendErr(playerid, "Ваш текст содержит запрещенные символы");
				}
			}

			if(strlen(inputtext) < 10 || strlen(inputtext) > 128)
			{
				input_gift_message(playerid, id);
				return SendErr(playerid, "Длина поздравления от 10 до 128 символов");
			}

			format(String512, sizeof(String512), "INSERT INTO player_giftcard(userid, message, recieveid) VALUES ('%i','%s','%i')",
		    pData[playerid][pMysqlID], inputtext, id);
			sql_queryEx(zConn, String512, QUERY_CACHED);

			new 
				nick[24];

			GetPlayerNameByID(id, nick);

			format(String144, sizeof(String144), "Вы отправили поздравительную открытку "cGR"%s", nick);
			SendSucc(playerid, String144);

			if(GetPlayerID(nick) != -1)
			{
				SCM(GetPlayerID(nick), CBLUE, "[Информация] "cWH"Вам отправили новую открытку. Подробнее "cGREY"/mygift");
			}

			if(pData[playerid][pQuestMarch3] < 10)
			{
				pData[playerid][pQuestMarch3]++;
				UpdatePlayerData(playerid, "pQuestMarch3", pData[playerid][pQuestMarch3]);
			}

			if(pData[playerid][pQuestMarch3] == 10)
			{
				SendSucc(playerid, "Вы выполнили квестовое задание "cBLUE"'Поздравление с 8 марта'");
			}
			return true;
		}
	}
	return true;
}

callback:: timer_tulips(playerid)
{
	new 
		tulips = GetPVarIntNew(playerid, "march_tulips");

	SetPVarIntNew(playerid, "march_tulips", tulips + 1);


	format(String144, sizeof(String144), "Вы выраситили тюльпан! Всего: %i из 20", GetPVarIntNew(playerid, "march_tulips"));
	SendSucc(playerid, String144);

	TogglePlayerControllable(playerid, 1);
	ClearAnimations(playerid);

	GivePlayerWeaponEx(playerid, 14, 1);

	GameTextForPlayer(playerid, \
		"~y~Џ«ћ©Јa®\
		~n~~w~‹Ёpoc",1000, 1);

	if(GetPVarIntNew(playerid, "march_tulips") == 20)
	{
		new 
			rand = random(96);

		SetPVarIntNew(playerid, "house_tulips", rand+1);

		SetPlayerQuestCheckpoint(playerid, House[rand][house_enter_x], House[rand][house_enter_y], House[rand][house_enter_z], 4.0);

		format(String144, sizeof(String144), "Доставьте тюльпаны к дому "cGR"№%i", rand+1);
		SendInf(playerid, String144);
	}
	return true;
}

stock tulips_house_accept(playerid)
{
	pData[playerid][pQuestMarch1] ++;
	UpdatePlayerData(playerid, "pQuestMarch1", pData[playerid][pQuestMarch1]);

	format(String144, sizeof(String144), "Вы доставили тюльпаны заказчику. Всего: %i из 20", pData[playerid][pQuestMarch1]);
	SendSucc(playerid, String144);

	if(pData[playerid][pQuestMarch1] == 20)
	{
		SendSucc(playerid, "Вы выполнили квестовое задание "cGR"'Тюльпаны-ландыши'");

		DeletePVarNew(playerid, "house_tulips");
		DeletePVarNew(playerid, "march_tulips");
		return true;
	}

	new 
		rand = random(96);

	SetPVarIntNew(playerid, "house_tulips", rand+1);

	SetPlayerQuestCheckpoint(playerid, House[rand][house_enter_x], House[rand][house_enter_y], House[rand][house_enter_z], 4.0);

	format(String144, sizeof(String144), "Доставьте тюльпаны к дому "cGR"№%i", rand+1);
	SendInf(playerid, String144);
	return true;
}

stock disconnect_march_quest(playerid)
{
	DeletePVarNew(playerid, "gift_recieveid");
	DeletePVarNew(playerid, "march_tulips");
	DeletePVarNew(playerid, "house_tulips");
	DeletePVarNew(playerid, "snowdrops");
	DeletePVarNew(playerid, "take_brilliants");
	return true;
}

CMD:gift(playerid, params[])
{
	if(sscanf(params, "s[24]", params[0]))
		return SendInf(playerid, "/gift [Ник игрока]");

	format(String144,sizeof(String144),"SELECT * FROM `accounts` WHERE `nickname` = '%s'", params[0]);
	new Result:r = sql_queryEx(zConn, String144, QUERY_CACHED);

	if(!sql_num_rows(r)) 
	{
		sql_free_result(r);
		return SendErr(playerid, "Аккаунт не найден в базе данных");
	}
	new 
		id = sql_get_field_assoc_int_ex(r, 0, "id");
	sql_free_result(r);

	format(String144,sizeof(String144),"SELECT * FROM `player_giftcard` WHERE `userid` = '%i' AND `recieveid` = '%i'", pData[playerid][pMysqlID], id);
	new Result:result = sql_queryEx(zConn, String144, QUERY_CACHED);

	if(sql_num_rows(result)) 
	{
		sql_free_result(result);
		return SendErr(playerid, "Вы уже отправляли игроку открытку");
	}

	input_gift_message(playerid, id);
	return true;
}

CMD:mygift(playerid)
{
	format(String256,sizeof(String256),"SELECT * FROM `player_giftcard` WHERE `recieveid` = '%i' LIMIT 1", pData[playerid][pMysqlID]);
	new Result:r = sql_queryEx(zConn, String256, QUERY_CACHED);

	if(!sql_num_rows(r)) 
	{
		sql_free_result(r);
		return SendErr(playerid, "У Вас нет новых поздравительных открыток");
	}
	new 
		id = sql_get_field_assoc_int_ex(r, 0, "userid"),
		message[128],
		otpravnick[MAX_PLAYER_NAME];

	sql_get_field_assoc_ex(r, 0, "message", message);
	sql_free_result(r);

	GetPlayerNameByID(id, otpravnick);

	format(String256, sizeof(String256), "DELETE FROM `player_giftcard` WHERE `userid` = '%i' AND `recieveid` = '%i' LIMIT 1", id, pData[playerid][pMysqlID]);
	sql_queryEx(zConn, String256);

	format(String256, sizeof(String256), "\
		"cBLUE"Текст поздравления:\n\n\
		"cWH"%s\n\n\
		"cBLUE"Отправитель: "cWH"%s\n\
		"cBLUE"Получатель: "cWH"%s", message, otpravnick, pData[playerid][pNickname]);

	SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Поздравительная открытка", String256, !"Закрыть", "");
	return true;
}

stock input_gift_message(playerid, id)
{	
	SetPVarIntNew(playerid, "gift_recieveid", id);
	new 
		nick[24];

	GetPlayerNameByID(id, nick);

	format(String256, sizeof(String256), "\
		"cWH"Вы собираетесь отправить "cBLUE"%s "cWH"поздравительную открытку\n\
		Введите текст поздравления:\n\n\
		"cGREY"Примечание: длина сообщения от 10 до 128 символов", nick);

	SPD(playerid, DIALOG_INPUT_GIFT_MESSAGE, DIALOG_STYLE_INPUT, !""cBLUE"Поздравительная открытка", String256, !"Отправить", !"Отмена");
	return true;
}

stock get_player_gift(playerid)
{
	format(String144,sizeof(String144),"SELECT * FROM `player_giftcard` WHERE `recieveid` = '%i'", pData[playerid][pMysqlID]);
	new Result:r = sql_queryEx(zConn, String144, QUERY_CACHED);

	if(!sql_num_rows(r)) 
	{
		sql_free_result(r);
		return true;
	}

	format(String144, sizeof(String144), "[Информация] "cWH"У Вас есть "cGR"%i "cWH"новых поздравительных открыток. Подробнее "cGREY"/mygift", sql_num_rows(r));
	SendInf(playerid, String144);
	sql_free_result(r);
	return true;
}

stock march_event(playerid)
{
	SCM(playerid, COLOR_ORANGE, "На сервере проходит празднование "cWH"8 марта"cGR". "cORANGE"Доступна квестовая линия");
	SCM(playerid, COLOR_ORANGE, "Подробнее: "cWH"/march");
	return true;
}


CMD:march(playerid)
{

	if(GetPVarIntNew(playerid, "snow_work") == 1)
		return SendErr(playerid, "Невозможно использовать во время работы!");

	if(GetPVarIntNew(playerid, "bus_job_cp") == 1)
		return SendErr(playerid, "Невозможно использовать во время работы!");

	if(GetPVarIntNew(playerid, "active_player_house_newyear") == 1)
		return SendErr(playerid, "Невозможно использовать во время работы!");

	if(GetPVarIntNew(playerid, "trucker_job") == 1)
		return SendErr(playerid, "Невозможно использовать во время работы!");

	if(GetPVarIntNew(playerid, "active_player_gruz_taxi") == 1)
		return SendErr(playerid, "Невозможно использовать во время работы!");

	if(GetPVarIntNew(playerid, "active_player_gruz_taxi_p") == 1)
		return SendErr(playerid, "Невозможно использовать во время работы!");

	show_march_quest(playerid);

	return true;
}

stock progress_march_quest(playerid)
{
	if(pData[playerid][pQuestMarch1] > 0 && pData[playerid][pQuestMarch1] < 20)
	{
		SetPVarIntNew(playerid, "march_tulips", 20);
		new 
			rand = random(96);

		SetPVarIntNew(playerid, "house_tulips", rand+1);

		SetPlayerQuestCheckpoint(playerid, House[rand][house_enter_x], House[rand][house_enter_y], House[rand][house_enter_z], 4.0);

		format(String144, sizeof(String144), "Доставьте тюльпаны к дому "cGR"№%i", rand+1);
		SendInf(playerid, String144);
	}
	if(pData[playerid][pQuestMarch2] > 0 && pData[playerid][pQuestMarch2] < 20)
	{
		SetPlayerQuestCheckpoint(playerid, 1198.3492,-563.6592,41.2923, 4.0);
		SetPVarIntNew(playerid, "snowdrops", 20-pData[playerid][pQuestMarch2]);
		SendInf(playerid, "Продайте подснежники скупщику возле тепличного комплекса");
	}
	return true;
}