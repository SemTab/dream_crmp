
static const get_buisnes_autosalon_n[][] =
{	
	"Отсутствует",
    "АвтоХаус Премиум",
    "АрзамасКарс",
    "Авторынок",
    "АвтоДвор"
};
    
stock dialog_all_sell_property(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
		case DIALOG_SELECT_SELL_P_P:
		{
			if(!response)
				return true;

			switch(listitem)
			{
				case 0:
				{
					if(pData[playerid][pHouse] == -1)
						return SendErr(playerid, "У Вас нет дома");

					SPD(playerid, DIALOG_SELL_HOUSE_PLAYER, DIALOG_STYLE_INPUT, ""cBLUE"Продажа дома", "\n\
					"cWH"Введите "cBLUE"ID "cWH"и "cBLUE"сумму "cWH"через запятую\n\n\
					"cGR"Пример: 0,500000\n", !"Продать", !"Отмена");
				}
				case 1:
				{
					if(pData[playerid][pFlate] == -1)
						return SendErr(playerid, "У Вас нет квартиры");

					SPD(playerid, DIALOG_SELL_FLATE_PLAYER, DIALOG_STYLE_INPUT, ""cBLUE"Продажа квартиры", "\n\
					"cWH"Введите "cBLUE"ID "cWH"и "cBLUE"сумму "cWH"через запятую\n\n\
					"cGR"Пример: 0,500000\n", !"Продать", !"Отмена");
				}
				case 2:
				{
					if(pData[playerid][pGarage] == -1)
						return SendErr(playerid, "У Вас нет гаража");

					SPD(playerid, DIALOG_SELL_GARAGE_PLAYER, DIALOG_STYLE_INPUT, ""cBLUE"Продажа гаража", "\n\
					"cWH"Введите "cBLUE"ID "cWH"и "cBLUE"сумму "cWH"через запятую\n\n\
					"cGR"Пример: 0,150000\n", !"Продать", !"Отмена");
				}
				case 3:
				{
					if(pData[playerid][pFillStation] == -1)
						return SendErr(playerid, "У Вас нет АЗС");

					SPD(playerid, DIALOG_SELL_FILLING_PLAYER, DIALOG_STYLE_INPUT, ""cBLUE"Продажа АЗС", "\n\
					"cWH"Введите "cBLUE"ID "cWH"и "cBLUE"сумму "cWH"через запятую\n\n\
					"cGR"Пример: 0,15000000\n", !"Продать", !"Отмена");
				}
				case 4:
				{
					if(pData[playerid][pBusiness] == -1)
						return SendErr(playerid, "У Вас нет бизнеса");

					SPD(playerid, DIALOG_SELL_BIZ_PLAYER, DIALOG_STYLE_INPUT, ""cBLUE"Продажа бизнеса", "\n\
					"cWH"Введите "cBLUE"ID "cWH"и "cBLUE"сумму "cWH"через запятую\n\n\
					"cGR"Пример: 0,15000000\n", !"Продать", !"Отмена");
				}
				case 5:
				{
					if(pData[playerid][pHotelOwner] == -1)
						return SendErr(playerid, "У Вас нет отеля");

					SPD(playerid, DIALOG_SELL_HOTEL_PLAYER, DIALOG_STYLE_INPUT, ""cBLUE"Продажа отеля", "\n\
					"cWH"Введите "cBLUE"ID "cWH"и "cBLUE"сумму "cWH"через запятую\n\n\
					"cGR"Пример: 0,15000000\n", !"Продать", !"Отмена");
				}
				case 6:
				{
					if(pData[playerid][pCasinoOwner] == -1)
						return SendErr(playerid, "У Вас нет казино");

					SPD(playerid, DIALOG_SELL_CASINO_PLAYER, DIALOG_STYLE_INPUT, ""cBLUE"Продажа казино", "\n\
					"cWH"Введите "cBLUE"ID "cWH"и "cBLUE"сумму "cWH"через запятую\n\n\
					"cGR"Пример: 0,150000000\n", !"Продать", !"Отмена");
				}
				case 7:
				{
					if(pData[playerid][pTruckerOwnerID] == -1)
						return SendErr(playerid, "У Вас нет транспортной компании");

					SPD(playerid, DIALOG_SELL_TK_PLAYER, DIALOG_STYLE_INPUT, ""cBLUE"Продажа транспортной компании", "\n\
					"cWH"Введите "cBLUE"ID "cWH"и "cBLUE"сумму "cWH"через запятую\n\n\
					"cGR"Пример: 0,15000000\n", !"Продать", !"Отмена");
				}
				case 8:
				{
					if(pData[playerid][pMechOwnerID] == -1)
						return SendErr(playerid, "У Вас нет СТО");

					SPD(playerid, DIALOG_SELL_MECHANIC_PLAYER, DIALOG_STYLE_INPUT, ""cBLUE"Продажа СТО", "\n\
					"cWH"Введите "cBLUE"ID "cWH"и "cBLUE"сумму "cWH"через запятую\n\n\
					"cGR"Пример: 0,15000000\n", !"Продать", !"Отмена");
				}
				case 9:
				{
					if(pData[playerid][pTaxiOwnerID] == -1)
						return SendErr(playerid, "У Вас нет таксопарка");

					SPD(playerid, DIALOG_SELL_TAXI_PLAYER, DIALOG_STYLE_INPUT, ""cBLUE"Продажа таксопарка", "\n\
					"cWH"Введите "cBLUE"ID "cWH"и "cBLUE"сумму "cWH"через запятую\n\n\
					"cGR"Пример: 0,15000000\n", !"Продать", !"Отмена");
				}
			}
			return true;

		}
		case DIALOG_SELL_HOUSE_PLAYER:
		{
			if(!response)
				return true;

			if(!strlen(inputtext))
			{
				return SPD(playerid, DIALOG_SELL_HOUSE_PLAYER, DIALOG_STYLE_INPUT, ""cBLUE"Продажа дома", "\n\
					"cWH"Введите "cBLUE"ID "cWH"и "cBLUE"сумму "cWH"через запятую\n\n\
					"cGR"Пример: 0,500000\n", !"Продать", !"Отмена");
			}

			new 
				target,
				price;

			sscanf(inputtext, "p<,>dd", target, price);

			if(!IsPlayerConnected(target) || target == playerid)
				return SendErr(playerid, "Неверный ID");

			if(pTemp[target][offer_time]) 
				return SendInf(playerid, "Ошибка: "cWH"У игрока есть активные предложения");


			if(GetPlayerDistanceToPlayer(playerid, target) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(target))
				return SendErr(playerid, "Вы далеко друг от друга");

			new 
				id_house = pData[playerid][pHouse];

			if(price < House[id_house][house_price] || price > 100000000)
				return SendErr(playerid, "Цена не может быть больше 100 млн и меньше гос.стоимости!");

			if(pData[target][pHouse] != -1 || pData[target][pHouseRent] != -1)
				return SendErr(playerid, "У игрока имеется дом или он арендует комнату в доме!");
			if(pData[target][pFlate] != -1 || pData[target][pFlateRent] != -1)
				return SendErr(playerid, "У игрока имеется квартира или он арендует комнату в квартире!");


			if(pData[target][pGarage] != -1)
				return SendErr(playerid, "У игрока имеется гараж");


			if(GetPlayerMoneyEx(target) < price)
				return SendErr(playerid, "У игрока нет данной суммы");

			new 
				classname[11],
				sell_house_mes[230];
			switch(House[pData[playerid][pHouse]][house_class])
			{
				case 0:classname = "Эконом";
				case 1:classname = "Cредний";
				case 2:classname = "Элитный";
				case 3:classname = "Особняк";
				default: classname = "Неизвестно";
			}
			format(sell_house_mes, sizeof sell_house_mes, "\n"cBLUE"%s "cWH"предлагает купить его дом:\n\n\
				"cWH"Номер дома: "cBLUE"№%i\n\
				"cWH"Класс: "cBLUE"%s\n\
				"cWH"Государственная цена: "cGR"%i рублей\n\n\
				"cWH"Стоимость покупки: "cGR"%i рублей\n", pData[playerid][pNickname], pData[playerid][pHouse], classname, House[pData[playerid][pHouse]][house_price], price);

			pTemp[target][offer_playerid] = playerid;
			pTemp[target][offer_time] = 30;
			SetPVarIntNew(playerid, "BuyHousePrice", price);
			SPD(target, DIALOG_ACCEPT_BUY_HOUSE_P, DIALOG_STYLE_MSGBOX, ""cBLUE"Предложение покупки дома", sell_house_mes, !"Купить", !"Отмена");

			format(sell_house_mes, sizeof sell_house_mes, "Вы предложили "cBLUE"%s"cWH" купить дом за "cGR"%i рублей", pData[target][pNickname], price);
			SendSucc(playerid, sell_house_mes);
			return true;
		}
		case DIALOG_ACCEPT_BUY_HOUSE_P:
		{
			new 
				offerid = pTemp[playerid][offer_playerid],
				price = GetPVarIntNew(offerid, "BuyHousePrice");

			if(!response)
			{
				SendInf(playerid, "Вы отказались от покупки дома");
				SendInf(offerid, "Игрок отказался от покупки дома");
				DeletePVarNew(offerid, "BuyHousePrice");


				pTemp[playerid][offer_playerid] = INVALID_PLAYER_ID;
				pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
				pTemp[offerid][offer_playerid] = INVALID_PLAYER_ID;
				pTemp[offerid][offer_time] = pTemp[offerid][offer_action] = 0;				
				return true;
			}
			sell_house_to_player(offerid, playerid, price);
			return true;
		}
		case DIALOG_SELL_FLATE_PLAYER:
		{
			if(!response)
				return true;
			if(!strlen(inputtext))
				return SPD(playerid, DIALOG_SELL_FLATE_PLAYER, DIALOG_STYLE_INPUT, ""cBLUE"Продажа квартиры", "\n\
					"cWH"Введите "cBLUE"ID "cWH"и "cBLUE"сумму "cWH"через запятую\n\n\
					"cGR"Пример: 0,500000\n", !"Продать", !"Отмена");
			new 
				target,
				price;
			sscanf(inputtext, "p<,>dd", target, price);

			if(!IsPlayerConnected(target) || target == playerid)
				return SendErr(playerid, "Неверный ID");

			if(pTemp[target][offer_time]) 
				return SendInf(playerid, "Ошибка: "cWH"У игрока есть активные предложения");


			if(GetPlayerDistanceToPlayer(playerid, target) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(target))
				return SendErr(playerid, "Вы далеко друг от друга");

			new 
				id_house = pData[playerid][pFlate];

			if(price < flate[id_house][flate_price] || price > 100000000)
				return SendErr(playerid, "Цена не может быть больше 100 млн и меньше гос.стоимости!");

			if(pData[target][pFlate] != -1 || pData[target][pFlateRent] != -1)
				return SendErr(playerid, "У игрока имеется квартира или он арендует комнату в квартире!");


			if(pData[target][pGarage] != -1)
				return SendErr(playerid, "У игрока имеется гараж");
			if(pData[target][pHouse] != -1 || pData[target][pHouseRent] != -1)
				return SendErr(playerid, "У игрока имеется дом или он арендует комнату в доме!");



			if(GetPlayerMoneyEx(target) < price)
				return SendErr(playerid, "У игрока нет данной суммы");

			new 
				sell_kvart_mes[230];

			format(sell_kvart_mes, sizeof sell_kvart_mes, "\n"cBLUE"%s "cWH"предлагает купить его квартиру:\n\n\
				"cWH"Номер квартиры: "cBLUE"№%i\n\
				"cWH"Государственная цена: "cGR"%i рублей\n\n\
				"cWH"Стоимость покупки: "cGR"%i рублей\n", pData[playerid][pNickname], pData[playerid][pFlate], flate[pData[playerid][pFlate]][flate_price], price);

			pTemp[target][offer_playerid] = playerid;
			pTemp[target][offer_time] = 10;
			SetPVarIntNew(playerid, "KvartSellPrice", price);
			SPD(target, DIALOG_ACCEPT_BUY_FLATE_P, DIALOG_STYLE_MSGBOX, ""cBLUE"Предложение покупки квартиры", sell_kvart_mes, !"Купить", !"Отмена");

			format(sell_kvart_mes, sizeof sell_kvart_mes, "Вы предложили "cBLUE"%s"cWH" купить квартиру за "cGR"%i рублей", pData[target][pNickname], price);
			SendSucc(playerid, sell_kvart_mes);
			return true;
		}
		case DIALOG_ACCEPT_BUY_FLATE_P:
		{
			new 
				offerid = pTemp[playerid][offer_playerid],
				price = GetPVarIntNew(offerid, "KvartSellPrice");


			if(!response)
			{
				SendInf(playerid, "Вы отказались от покупки квартиры");
				SendInf(offerid, "Игрок отказался от покупки квартиры");
				DeletePVarNew(offerid, "KvartSellPrice");


				pTemp[playerid][offer_playerid] = INVALID_PLAYER_ID;
				pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
				pTemp[offerid][offer_playerid] = INVALID_PLAYER_ID;
				pTemp[offerid][offer_time] = pTemp[offerid][offer_action] = 0;				
				return true;
			}
			sell_flate_to_player(offerid, playerid, price);
			return true;
		}
		case DIALOG_SELL_GARAGE_PLAYER:
		{
			if(!response)
				return true;

			if(!strlen(inputtext))
			{
				return SPD(playerid, DIALOG_SELL_GARAGE_PLAYER, DIALOG_STYLE_INPUT, ""cBLUE"Продажа гаража", "\n\
					"cWH"Введите "cBLUE"ID "cWH"и "cBLUE"сумму "cWH"через запятую\n\n\
					"cGR"Пример: 0,150000\n", !"Продать", !"Отмена");
			}

			new 
				target,
				price;

			sscanf(inputtext, "p<,>dd", target, price);

			if(!IsPlayerConnected(target) || target == playerid)
				return SendErr(playerid, "Неверный ID");

			if(pTemp[target][offer_time]) 
				return SendInf(playerid, "Ошибка: "cWH"У игрока есть активные предложения");


			if(GetPlayerDistanceToPlayer(playerid, target) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(target))
				return SendErr(playerid, "Вы далеко друг от друга");

			new 
				id_house = pData[playerid][pGarage];

			if(price < garage[id_house][garage_price] || price > 100000000)
				return SendErr(playerid, "Цена не может быть больше 100 млн и меньше гос.стоимости!");


			if(pData[target][pGarage] != -1)
				return SendErr(playerid, "У игрока имеется гараж");

			if(pData[target][pFlate] != -1 || pData[target][pFlateRent] != -1)
				return SendErr(playerid, "У игрока имеется квартира или он арендует комнату в квартире!");
			if(pData[target][pHouse] != -1 || pData[target][pHouseRent] != -1)
				return SendErr(playerid, "У игрока имеется дом или он арендует комнату в доме!");


			if(GetPlayerMoneyEx(target) < price)
				return SendErr(playerid, "У игрока нет данной суммы");

			new 
				sell_garage_mes[230];

			format(sell_garage_mes, sizeof sell_garage_mes, "\n"cBLUE"%s "cWH"предлагает купить его гараж:\n\n\
				"cWH"Номер гаража: "cBLUE"№%i\n\
				"cWH"Государственная цена: "cGR"%i рублей\n\n\
				"cWH"Стоимость покупки: "cGR"%i рублей\n", pData[playerid][pNickname], pData[playerid][pGarage], garage[pData[playerid][pGarage]][garage_price], price);

			pTemp[target][offer_playerid] = playerid;
			pTemp[target][offer_time] = 10;
			SetPVarIntNew(playerid, "GarageSellPrice", price);
			SPD(target, DIALOG_ACCEPT_BUY_GARAGE_P, DIALOG_STYLE_MSGBOX, ""cBLUE"Предложение покупки гаража", sell_garage_mes, !"Купить", !"Отмена");

			format(sell_garage_mes, sizeof sell_garage_mes, "Вы предложили "cBLUE"%s"cWH" купить гараж за "cGR"%i рублей", pData[target][pNickname], price);
			SendSucc(playerid, sell_garage_mes);
			return true;
		}
		case DIALOG_ACCEPT_BUY_GARAGE_P:
		{
			new 
				offerid = pTemp[playerid][offer_playerid],
				price = GetPVarIntNew(offerid, "GarageSellPrice");

			if(!response)
			{
				SendInf(playerid, "Вы отказались от покупки гаража");
				SendInf(offerid, "Игрок отказался от покупки гаража");
				DeletePVarNew(offerid, "GarageSellPrice");


				pTemp[playerid][offer_playerid] = INVALID_PLAYER_ID;
				pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
				pTemp[offerid][offer_playerid] = INVALID_PLAYER_ID;
				pTemp[offerid][offer_time] = pTemp[offerid][offer_action] = 0;				
				return true;
			}
			sell_garage_to_player(offerid, playerid, price);
			return true;
		}
		case DIALOG_SELL_FILLING_PLAYER:
		{
			if(!response)
				return true;

			if(!strlen(inputtext))
			{
				return SPD(playerid, DIALOG_SELL_FILLING_PLAYER, DIALOG_STYLE_INPUT, ""cBLUE"Продажа АЗС", "\n\
					"cWH"Введите "cBLUE"ID "cWH"и "cBLUE"сумму "cWH"через запятую\n\n\
					"cGR"Пример: 0,15000000\n", !"Продать", !"Отмена");
			}

			new 
				target,
				price;

			sscanf(inputtext, "p<,>dd", target, price);

			if(!IsPlayerConnected(target) || target == playerid)
				return SendErr(playerid, "Неверный ID");

			if(pTemp[target][offer_time]) 
				return SendInf(playerid, "Ошибка: "cWH"У игрока есть активные предложения");


			if(GetPlayerDistanceToPlayer(playerid, target) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(target))
				return SendErr(playerid, "Вы далеко друг от друга");

			new 
				id_house = pData[playerid][pFillStation];

			if(price < filling[id_house][filling_price] || price > 100000000)
				return SendErr(playerid, "Цена не может быть больше 100 млн и меньше гос.стоимости!");


			if(pData[target][pBusiness] != -1)
				return SendErr(playerid, "У игрока уже имеется бизнес!");
			if(pData[target][pHotelOwner] != -1)
				return SendErr(playerid, "У игрока уже имеется бизнес!");
			if(pData[target][pMechOwnerID] != -1)
				return SendErr(playerid,  "У игрока уже имеется бизнес!");
			if(pData[target][pFillStation] != -1)
				return SendErr(playerid,  "У игрока уже имеется бизнес!");
			if(pData[target][pTaxiOwnerID] != -1)
				return SendErr(playerid,  "У игрока уже имеется бизнес!");
			if(pData[target][pTruckerOwnerID] != -1)
				return SendErr(playerid,  "У игрока уже имеется бизнес!");
			if(pData[target][pCasinoOwner] != -1)
				return SendErr(playerid, "У игрока уже имеется бизнес!");



			if(GetPlayerMoneyEx(target) < price)
				return SendErr(playerid, "У игрока нет данной суммы");

			new 
				sell_filling_mes[230];

			format(sell_filling_mes, sizeof sell_filling_mes, "\n"cBLUE"%s "cWH"предлагает купить его АЗС:\n\n\
				"cWH"Номер АЗС: "cBLUE"№%i\n\
				"cWH"Государственная цена: "cGR"%i рублей\n\n\
				"cWH"Стоимость покупки: "cGR"%i рублей\n", pData[playerid][pNickname], pData[playerid][pFillStation], filling[pData[playerid][pFillStation]][filling_price], price);

			pTemp[target][offer_playerid] = playerid;
			pTemp[target][offer_time] = 10;

			SetPVarIntNew(playerid, "FillingSellPrice", price);

			SPD(target, DIALOG_ACCEPT_BUY_FILL_P, DIALOG_STYLE_MSGBOX, ""cBLUE"Предложение покупки АЗС", sell_filling_mes, !"Купить", !"Отмена");

			format(sell_filling_mes, sizeof sell_filling_mes, "Вы предложили "cBLUE"%s"cWH" купить АЗС за "cGR"%i рублей", pData[target][pNickname], price);
			SendSucc(playerid, sell_filling_mes);
			return true;
		}
		case DIALOG_ACCEPT_BUY_FILL_P:
		{
			new 
				offerid = pTemp[playerid][offer_playerid],
				price = GetPVarIntNew(offerid, "FillingSellPrice");

			if(!response)
			{
				SendInf(playerid, "Вы отказались от покупки АЗС");
				SendInf(offerid, "Игрок отказался от покупки АЗС");
				DeletePVarNew(offerid, "FillingSellPrice");


				pTemp[playerid][offer_playerid] = INVALID_PLAYER_ID;
				pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
				pTemp[offerid][offer_playerid] = INVALID_PLAYER_ID;
				pTemp[offerid][offer_time] = pTemp[offerid][offer_action] = 0;				
				return true;
			}
			sell_filling_to_player(offerid, playerid, price);
			return true;
		}
		case DIALOG_SELL_BIZ_PLAYER:
		{
			if(!response)
				return true;
			if(!strlen(inputtext))
				return SPD(playerid, DIALOG_SELL_BIZ_PLAYER, DIALOG_STYLE_INPUT, ""cBLUE"Продажа бизнеса", "\n\
					"cWH"Введите "cBLUE"ID "cWH"и "cBLUE"сумму "cWH"через запятую\n\n\
					"cGR"Пример: 0,15000000\n", !"Продать", !"Отмена");
			new 
				target,
				price;

			sscanf(inputtext, "p<,>dd", target, price);

			if(!IsPlayerConnected(target) || target == playerid)
				return SendErr(playerid, "Неверный ID");

			if(pTemp[target][offer_time]) 
				return SendInf(playerid, "Ошибка: "cWH"У игрока есть активные предложения");


			if(GetPlayerDistanceToPlayer(playerid, target) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(target))
				return SendErr(playerid, "Вы далеко друг от друга");

			new 
				id_house = pData[playerid][pBusiness];

			if(price < buisness[id_house][buisnes_price] || price > 100000000)
				return SendErr(playerid, "Цена не может быть больше 100 млн и меньше гос.стоимости!");


			if(pData[target][pBusiness] != -1)
				return SendErr(playerid, "У игрока уже имеется бизнес!");
			if(pData[target][pHotelOwner] != -1)
				return SendErr(playerid, "У игрока уже имеется бизнес!");
			if(pData[target][pMechOwnerID] != -1)
				return SendErr(playerid,  "У игрока уже имеется бизнес!");
			if(pData[target][pFillStation] != -1)
				return SendErr(playerid,  "У игрока уже имеется бизнес!");
			if(pData[target][pTaxiOwnerID] != -1)
				return SendErr(playerid,  "У игрока уже имеется бизнес!");
			if(pData[target][pTruckerOwnerID] != -1)
				return SendErr(playerid,  "У игрока уже имеется бизнес!");
			if(pData[target][pCasinoOwner] != -1)
				return SendErr(playerid, "У игрока уже имеется бизнес!");


			if(GetPlayerMoneyEx(target) < price)
				return SendErr(playerid, "У игрока нет данной суммы");

			new 
				biz_id = pData[playerid][pBusiness];

			static 
				buisnes_names[24];

			if(buisness[biz_id][buisnes_type] == BUISNES_PRODUCTION)
			{
				format(buisnes_names, 24, "%s", get_buisnes_univermag_n(biz_id));
			}
			else if(buisness[biz_id][buisnes_type] == BUISNES_BAR)
			{
				format(buisnes_names, 24, "%s", get_buisnes_bar_n(biz_id));
			}
			else if(buisness[biz_id][buisnes_type] == BUISNES_AMMO_1)
			{
				format(buisnes_names, 24, "%s", get_buisnes_ammo_n(biz_id));
			}
			else if(buisness[biz_id][buisnes_type] == BUISNES_AMMO_2)
			{
				format(buisnes_names, 24, "%s", get_buisnes_ammo_n(biz_id));
			}
			else if(buisness[biz_id][buisnes_type] == BUISNES_RESTORAN)
			{
				format(buisnes_names, 24, "%s", get_buisnes_restoran_n(biz_id));
			}
			else if(buisness[biz_id][buisnes_type] == BUISNES_FASTFOOD)
			{
				format(buisnes_names, 24, "%s", get_buisnes_fastfood_n(biz_id));
			}
			else if(buisness[biz_id][buisnes_type] == BUISNES_CLUB)
			{
				format(buisnes_names, 24, "%s", get_buisnes_club_n(biz_id));
			}	
			else if(buisness[biz_id][buisnes_type] == BUISNES_AUTOSALON_1)
			{
				format(buisnes_names, 24, "%s", get_buisnes_autosalon_n[buisness[biz_id][buisnes_name]]);
			}	
			else if(buisness[biz_id][buisnes_type] == BUISNES_CLOTHES)
			{
				format(buisnes_names, 24, "%s", get_buisnes_clothes_n(biz_id));
			}
			else if(buisness[biz_id][buisnes_type] == BUISNES_AUTOSALON_2)
			{
				format(buisnes_names, 24, "%s", get_buisnes_autosalon_n[buisness[biz_id][buisnes_name]]);
			}	
			else if(buisness[biz_id][buisnes_type] == BUISNES_AUTOSALON_3)
			{
				format(buisnes_names, 24, "%s", get_buisnes_autosalon_n[buisness[biz_id][buisnes_name]]);
			}	
			else if(buisness[biz_id][buisnes_type] == BUISNES_CLOTHES)
			{
				format(buisnes_names, 24, "%s", get_buisnes_clothes_n(biz_id));
			}

			new 
				sell_biz_mes[230];

			format(sell_biz_mes, sizeof sell_biz_mes, "\n"cBLUE"%s "cWH"предлагает купить его бизнес:\n\n\
				"cWH"Номер бизнеса: "cBLUE"№%i\n\
				"cWH"Название: "cBLUE"%s\n\
				"cWH"Государственная цена: "cGR"%i рублей\n\n\
				"cWH"Стоимость покупки: "cGR"%i рублей\n", pData[playerid][pNickname], biz_id, buisnes_names, buisness[biz_id][buisnes_price], price);

			pTemp[target][offer_playerid] = playerid;
			pTemp[target][offer_time] = 10;
			SetPVarIntNew(playerid, "BizSellPrice", price);
			SPD(target, DIALOG_ACCEPT_BUY_BIZ_P, DIALOG_STYLE_MSGBOX, ""cBLUE"Предложение покупки бизнеса", sell_biz_mes, !"Купить", !"Отмена");

			format(sell_biz_mes, sizeof sell_biz_mes, "Вы предложили "cBLUE"%s"cWH" купить бизнес за "cGR"%i рублей", pData[target][pNickname], price);
			SendSucc(playerid, sell_biz_mes);
			return true;
		}
		case DIALOG_ACCEPT_BUY_BIZ_P:
		{
			new 
				offerid = pTemp[playerid][offer_playerid],
				price = GetPVarIntNew(offerid, "BizSellPrice");

			if(!response)
			{
				SendInf(playerid, "Вы отказались от покупки АЗС");
				SendInf(offerid, "Игрок отказался от покупки АЗС");
				DeletePVarNew(offerid, "BizSellPrice");


				pTemp[playerid][offer_playerid] = INVALID_PLAYER_ID;
				pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
				pTemp[offerid][offer_playerid] = INVALID_PLAYER_ID;
				pTemp[offerid][offer_time] = pTemp[offerid][offer_action] = 0;				
				return true;
			}
			sell_buisnes_to_player(offerid, playerid, price);
			return true;
		}
		case DIALOG_SELL_HOTEL_PLAYER:
		{
			if(!response)
				return true;
			if(!strlen(inputtext))
				return SPD(playerid, DIALOG_SELL_HOTEL_PLAYER, DIALOG_STYLE_INPUT, ""cBLUE"Продажа отеля", "\n\
					"cWH"Введите "cBLUE"ID "cWH"и "cBLUE"сумму "cWH"через запятую\n\n\
					"cGR"Пример: 0,15000000\n", !"Продать", !"Отмена");
			new 
				target,
				price;
			sscanf(inputtext, "p<,>dd", target, price);
			if(!IsPlayerConnected(target) || target == playerid)
				return SendErr(playerid, "Неверный ID");

			if(pTemp[target][offer_time]) 
				return SendInf(playerid, "Ошибка: "cWH"У игрока есть активные предложения");


			if(GetPlayerDistanceToPlayer(playerid, target) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(target))
				return SendErr(playerid, "Вы далеко друг от друга");

			new 
				id_house = pData[playerid][pHotelOwner];

			if(price < hotel[id_house][hotel_price] || price > 100000000)
				return SendErr(playerid, "Цена не может быть больше 100 млн и меньше гос.стоимости!");

			if(pData[target][pBusiness] != -1)
				return SendErr(playerid, "У игрока уже имеется бизнес!");
			if(pData[target][pHotelOwner] != -1)
				return SendErr(playerid, "У игрока уже имеется бизнес!");
			if(pData[target][pMechOwnerID] != -1)
				return SendErr(playerid,  "У игрока уже имеется бизнес!");
			if(pData[target][pFillStation] != -1)
				return SendErr(playerid,  "У игрока уже имеется бизнес!");
			if(pData[target][pTaxiOwnerID] != -1)
				return SendErr(playerid,  "У игрока уже имеется бизнес!");
			if(pData[target][pTruckerOwnerID] != -1)
				return SendErr(playerid,  "У игрока уже имеется бизнес!");
			if(pData[target][pCasinoOwner] != -1)
				return SendErr(playerid, "У игрока уже имеется бизнес!");




			if(GetPlayerMoneyEx(target) < price)
				return SendErr(playerid, "У игрока нет данной суммы");

			new 
				hotelname[10],
				sell_hotel_mes[230];

			switch(GetPVarIntNew(playerid, "Hotel"))
			{
				case 1: hotelname = "Диана";
				case 2: hotelname = "Brilliant";
				case 3: hotelname = "Женя Рак";
			}

			format(sell_hotel_mes, sizeof sell_hotel_mes, "\n"cBLUE"%s "cWH"предлагает купить его отель:\n\n\
				"cWH"Номер отеля: "cBLUE"№%i\n\
				"cWH"Название: "cBLUE"%s\n\
				"cWH"Государственная цена: "cGR"%i рублей\n\n\
				"cWH"Стоимость покупки: "cGR"%i рублей\n", pData[playerid][pNickname], pData[playerid][pHotelOwner], hotelname, hotel[pData[playerid][pHotelOwner]][hotel_price], price);

			pTemp[target][offer_playerid] = playerid;
			pTemp[target][offer_time] = 10;
			SetPVarIntNew(playerid, "HotelSellPrice", price);
			SPD(target, DIALOG_ACCEPT_BUY_HOTEL_P, DIALOG_STYLE_MSGBOX, ""cBLUE"Предложение покупки отеля", sell_hotel_mes, !"Купить", !"Отмена");

			format(sell_hotel_mes, sizeof sell_hotel_mes, "Вы предложили "cBLUE"%s"cWH" купить отель за "cGR"%i рублей", pData[target][pNickname], price);
			SendSucc(playerid, sell_hotel_mes);
			return true;
		}
		case DIALOG_ACCEPT_BUY_HOTEL_P:
		{
			new 
				offerid = pTemp[playerid][offer_playerid],
				price = GetPVarIntNew(offerid, "HotelSellPrice");

			if(!response)
			{
				SendInf(playerid, "Вы отказались от покупки отеля");
				SendInf(offerid, "Игрок отказался от покупки отеля");
				DeletePVarNew(offerid, "HotelSellPrice");


				pTemp[playerid][offer_playerid] = INVALID_PLAYER_ID;
				pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
				pTemp[offerid][offer_playerid] = INVALID_PLAYER_ID;
				pTemp[offerid][offer_time] = pTemp[offerid][offer_action] = 0;				
				return true;
			}
			sell_hotel_to_player(offerid, playerid, price);
			return true;
		}
		case DIALOG_SELL_CASINO_PLAYER:
		{
			if(!response)
				return true;
			if(!strlen(inputtext))
				return SPD(playerid, DIALOG_SELL_CASINO_PLAYER, DIALOG_STYLE_INPUT, ""cBLUE"Продажа казино", "\n\
					"cWH"Введите "cBLUE"ID "cWH"и "cBLUE"сумму "cWH"через запятую\n\n\
					"cGR"Пример: 0,150000000\n", !"Продать", !"Отмена");
			new 
				target,
				price;
			sscanf(inputtext, "p<,>dd", target, price);
			if(!IsPlayerConnected(target) || target == playerid)
				return SendErr(playerid, "Неверный ID");

			if(pTemp[target][offer_time]) 
				return SendInf(playerid, "Ошибка: "cWH"У игрока есть активные предложения");


			if(GetPlayerDistanceToPlayer(playerid, target) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(target))
				return SendErr(playerid, "Вы далеко друг от друга");
			if(price < 100000000 || price > 1000000000)
				return SendErr(playerid, "Цена не может быть больше 1 млрд и меньше 100 млн рублей");

			if(pData[target][pBusiness] != -1)
				return SendErr(playerid, "У игрока уже имеется бизнес!");
			if(pData[target][pHotelOwner] != -1)
				return SendErr(playerid, "У игрока уже имеется бизнес!");
			if(pData[target][pMechOwnerID] != -1)
				return SendErr(playerid,  "У игрока уже имеется бизнес!");
			if(pData[target][pFillStation] != -1)
				return SendErr(playerid,  "У игрока уже имеется бизнес!");
			if(pData[target][pTaxiOwnerID] != -1)
				return SendErr(playerid,  "У игрока уже имеется бизнес!");
			if(pData[target][pTruckerOwnerID] != -1)
				return SendErr(playerid,  "У игрока уже имеется бизнес!");
			if(pData[target][pCasinoOwner] != -1)
				return SendErr(playerid, "У игрока уже имеется бизнес!");



			if(GetPlayerMoneyEx(target) < price)
				return SendErr(playerid, "У игрока нет данной суммы");

			new 
				casinoname[12],
				sell_casino_mes[230];

			switch(pData[playerid][pCasinoOwner])
			{
				case 1: casinoname = "Diamond";
			}

			format(sell_casino_mes, sizeof sell_casino_mes, "\n"cBLUE"%s "cWH"предлагает купить его казино:\n\n\
				"cWH"Номер казино: "cBLUE"№%i\n\
				"cWH"Название: "cBLUE"%s\n\
				"cWH"Государственная цена: "cGR"%i рублей\n\n\
				"cWH"Стоимость покупки: "cGR"%i рублей\n", pData[playerid][pNickname], pData[playerid][pCasinoOwner], casinoname, casino[pData[playerid][pCasinoOwner]][casino_buy_price], price);

			pTemp[target][offer_playerid] = playerid;
			pTemp[target][offer_time] = 10;
			SetPVarIntNew(playerid, "CasinoSellPrice", price);
			SPD(target, DIALOG_ACCEPT_BUY_CASINO_P, DIALOG_STYLE_MSGBOX, ""cBLUE"Предложение покупки казино", sell_casino_mes, !"Купить", !"Отмена");

			format(sell_casino_mes, sizeof sell_casino_mes, "Вы предложили "cBLUE"%s"cWH" купить казино за "cGR"%i рублей", pData[target][pNickname], price);
			SendSucc(playerid, sell_casino_mes);
			return true;
		}
		case DIALOG_ACCEPT_BUY_CASINO_P:
		{
			new 
				offerid = pTemp[playerid][offer_playerid],
				price = GetPVarIntNew(offerid, "CasinoSellPrice");

			if(!response)
			{
				SendInf(playerid, "Вы отказались от покупки казино");
				SendInf(offerid, "Игрок отказался от покупки казино");
				DeletePVarNew(offerid, "CasinoSellPrice");


				pTemp[playerid][offer_playerid] = INVALID_PLAYER_ID;
				pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
				pTemp[offerid][offer_playerid] = INVALID_PLAYER_ID;
				pTemp[offerid][offer_time] = pTemp[offerid][offer_action] = 0;				
				return true;
			}
			sell_casino_to_player(offerid, playerid, price);
			return true;
		}
		case DIALOG_SELL_TK_PLAYER:
		{
			if(!response)
				return true;
			if(!strlen(inputtext))
				return SPD(playerid, DIALOG_SELL_TK_PLAYER, DIALOG_STYLE_INPUT, ""cBLUE"Продажа транспортной компании", "\n\
					"cWH"Введите "cBLUE"ID "cWH"и "cBLUE"сумму "cWH"через запятую\n\n\
					"cGR"Пример: 0,15000000\n", !"Продать", !"Отмена");
			new 
				target,
				price;
			sscanf(inputtext, "p<,>dd", target, price);
			if(!IsPlayerConnected(target) || target == playerid)
				return SendErr(playerid, "Неверный ID");

			if(pTemp[target][offer_time]) 
				return SendInf(playerid, "Ошибка: "cWH"У игрока есть активные предложения");


			if(GetPlayerDistanceToPlayer(playerid, target) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(target))
				return SendErr(playerid, "Вы далеко друг от друга");

			if(price < 1000 || price > 100000000)
				return SendErr(playerid, "Цена не может быть больше 100 млн и меньше 1000 рублей");

			new 
				id_house = pData[playerid][pTruckerOwnerID];

			if(price < trucker_station[id_house][trucker_base_price] || price > 100000000)
				return SendErr(playerid, "Цена не может быть больше 100 млн и меньше гос.стоимости!");


			if(pData[target][pBusiness] != -1)
				return SendErr(playerid, "У игрока уже имеется бизнес!");
			if(pData[target][pHotelOwner] != -1)
				return SendErr(playerid, "У игрока уже имеется бизнес!");
			if(pData[target][pMechOwnerID] != -1)
				return SendErr(playerid,  "У игрока уже имеется бизнес!");
			if(pData[target][pFillStation] != -1)
				return SendErr(playerid,  "У игрока уже имеется бизнес!");
			if(pData[target][pTaxiOwnerID] != -1)
				return SendErr(playerid,  "У игрока уже имеется бизнес!");
			if(pData[target][pTruckerOwnerID] != -1)
				return SendErr(playerid,  "У игрока уже имеется бизнес!");
			if(pData[target][pCasinoOwner] != -1)
				return SendErr(playerid, "У игрока уже имеется бизнес!");




			if(GetPlayerMoneyEx(target) < price)
				return SendErr(playerid, "У игрока нет данной суммы");

			new 
				tkname[32],
				sell_transport_mes[230];

			switch(pData[playerid][pTruckerOwnerID])
			{
				case 0: tkname = "ТК №1";
				case 1: tkname = "ТК №2";
				case 2: tkname = "ТК №3";
			}

			format(sell_transport_mes, sizeof sell_transport_mes, "\n"cBLUE"%s "cWH"предлагает купить его транспортную компанию:\n\n\
				"cWH"Номер компании: "cBLUE"№%i\n\
				"cWH"Название: "cBLUE"%s\n\
				"cWH"Государственная цена: "cGR"%i рублей\n\n\
				"cWH"Стоимость покупки: "cGR"%i рублей\n", pData[playerid][pNickname], pData[playerid][pTruckerOwnerID], tkname, trucker_station[pData[playerid][pTruckerOwnerID]][trucker_base_price], price);

			pTemp[target][offer_playerid] = playerid;
			pTemp[target][offer_time] = 10;
			SetPVarIntNew(playerid, "TkSellPrice", price);
			SPD(target, DIALOG_ACCEPT_BUY_TK_P, DIALOG_STYLE_MSGBOX, ""cBLUE"Предложение покупки транспортной компании", sell_transport_mes, !"Купить", !"Отмена");

			format(sell_transport_mes, sizeof sell_transport_mes, "Вы предложили "cBLUE"%s"cWH" купить транспортную компанию за "cGR"%i рублей", pData[target][pNickname], price);
			SendSucc(playerid, sell_transport_mes);
			return true;
		}
		case DIALOG_ACCEPT_BUY_TK_P:
		{
			new 
				offerid = pTemp[playerid][offer_playerid],
				price = GetPVarIntNew(offerid, "TkSellPrice");

			if(!response)
			{
				SendInf(playerid, "Вы отказались от покупки транспортной компании");
				SendInf(offerid, "Игрок отказался от покупки транспортной компании");
				DeletePVarNew(offerid, "TkSellPrice");


				pTemp[playerid][offer_playerid] = INVALID_PLAYER_ID;
				pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
				pTemp[offerid][offer_playerid] = INVALID_PLAYER_ID;
				pTemp[offerid][offer_time] = pTemp[offerid][offer_action] = 0;				
				return true;
			}
			sell_tk_to_player(offerid, playerid, price);
			return true;
		}
		case DIALOG_SELL_MECHANIC_PLAYER:
		{
			if(!response)
				return true;
			if(!strlen(inputtext))
				return SPD(playerid, DIALOG_SELL_MECHANIC_PLAYER, DIALOG_STYLE_INPUT, ""cBLUE"Продажа СТО", "\n\
					"cWH"Введите "cBLUE"ID "cWH"и "cBLUE"сумму "cWH"через запятую\n\n\
					"cGR"Пример: 0,15000000\n", !"Продать", !"Отмена");
			new 
				target,
				price;
			sscanf(inputtext, "p<,>dd", target, price);
			if(!IsPlayerConnected(target) || target == playerid)
				return SendErr(playerid, "Неверный ID");

			if(pTemp[target][offer_time]) 
				return SendInf(playerid, "Ошибка: "cWH"У игрока есть активные предложения");


			if(GetPlayerDistanceToPlayer(playerid, target) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(target))
				return SendErr(playerid, "Вы далеко друг от друга");


			new 
				id_house = pData[playerid][pMechOwnerID];

			if(price < mechanic[id_house][mechanic_base_price] || price > 100000000)
				return SendErr(playerid, "Цена не может быть больше 100 млн и меньше гос.стоимости!");

			if(pData[target][pBusiness] != -1)
				return SendErr(playerid, "У игрока уже имеется бизнес!");
			if(pData[target][pHotelOwner] != -1)
				return SendErr(playerid, "У игрока уже имеется бизнес!");
			if(pData[target][pMechOwnerID] != -1)
				return SendErr(playerid,  "У игрока уже имеется бизнес!");
			if(pData[target][pFillStation] != -1)
				return SendErr(playerid,  "У игрока уже имеется бизнес!");
			if(pData[target][pTaxiOwnerID] != -1)
				return SendErr(playerid,  "У игрока уже имеется бизнес!");
			if(pData[target][pTruckerOwnerID] != -1)
				return SendErr(playerid,  "У игрока уже имеется бизнес!");
			if(pData[target][pCasinoOwner] != -1)
				return SendErr(playerid, "У игрока уже имеется бизнес!");



			if(GetPlayerMoneyEx(target) < price)
				return SendErr(playerid, "У игрока нет данной суммы");

			new 
				mehname[32],
				sell_mehcomp_mes[230];

			switch(pData[playerid][pMechOwnerID])
			{
				case 1: mehname = "СТО №1";
				case 2: mehname = "СТО №2";
				case 3: mehname = "СТО №3";
			}

			format(sell_mehcomp_mes, sizeof sell_mehcomp_mes, "\n"cBLUE"%s "cWH"предлагает купить его СТО:\n\n\
				"cWH"Номер СТО: "cBLUE"№%i\n\
				"cWH"Название: "cBLUE"%s\n\
				"cWH"Государственная цена: "cGR"%i рублей\n\n\
				"cWH"Стоимость покупки: "cGR"%i рублей\n", pData[playerid][pNickname], pData[playerid][pMechOwnerID], mehname, mechanic[pData[playerid][pMechOwnerID]][mechanic_base_price], price);

			pTemp[target][offer_playerid] = playerid;
			pTemp[target][offer_time] = 10;
			SetPVarIntNew(playerid, "MehSellPrice", price);
			SPD(target, DIALOG_ACCEPT_BUY_MECH_P, DIALOG_STYLE_MSGBOX, ""cBLUE"Предложение покупки СТО", sell_mehcomp_mes, !"Купить", !"Отмена");

			format(sell_mehcomp_mes, sizeof sell_mehcomp_mes, "Вы предложили "cBLUE"%s"cWH" купить СТО за "cGR"%i рублей", pData[target][pNickname], price);
			SendSucc(playerid, sell_mehcomp_mes);
			return true;
		}
		case DIALOG_ACCEPT_BUY_MECH_P:
		{
			new 
				offerid = pTemp[playerid][offer_playerid],
				price = GetPVarIntNew(offerid, "MehSellPrice");


			if(!response)
			{
				SendInf(playerid, "Вы отказались от покупки СТО");
				SendInf(offerid, "Игрок отказался от покупки СТО");
				DeletePVarNew(offerid, "MehSellPrice");


				pTemp[playerid][offer_playerid] = INVALID_PLAYER_ID;
				pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
				pTemp[offerid][offer_playerid] = INVALID_PLAYER_ID;
				pTemp[offerid][offer_time] = pTemp[offerid][offer_action] = 0;				
				return true;
			}
			sell_mech_to_player(offerid, playerid, price);
			return true;
		}
		case DIALOG_SELL_TAXI_PLAYER:
		{
			if(!response)
				return true;
			if(!strlen(inputtext))
				return SPD(playerid, DIALOG_SELL_TAXI_PLAYER, DIALOG_STYLE_INPUT, ""cBLUE"Продажа таксопарка", "\n\
					"cWH"Введите "cBLUE"ID "cWH"и "cBLUE"сумму "cWH"через запятую\n\n\
					"cGR"Пример: 0,15000000\n", !"Продать", !"Отмена");
			new 
				target,
				price;

			sscanf(inputtext, "p<,>dd", target, price);

			if(!IsPlayerConnected(target) || target == playerid)
				return SendErr(playerid, "Неверный ID");

			if(pTemp[target][offer_time]) 
				return SendInf(playerid, "Ошибка: "cWH"У игрока есть активные предложения");


			if(GetPlayerDistanceToPlayer(playerid, target) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(target))
				return SendErr(playerid, "Вы далеко друг от друга");

			new 
				id_house = pData[playerid][pTaxiOwnerID];

			if(price < taxi_company[id_house][taxi_company_price] || price > 100000000)
				return SendErr(playerid, "Цена не может быть больше 100 млн и меньше гос.стоимости!");

			if(pData[target][pBusiness] != -1)
				return SendErr(playerid, "У игрока уже имеется бизнес!");
			if(pData[target][pHotelOwner] != -1)
				return SendErr(playerid, "У игрока уже имеется бизнес!");
			if(pData[target][pMechOwnerID] != -1)
				return SendErr(playerid,  "У игрока уже имеется бизнес!");
			if(pData[target][pFillStation] != -1)
				return SendErr(playerid,  "У игрока уже имеется бизнес!");
			if(pData[target][pTaxiOwnerID] != -1)
				return SendErr(playerid,  "У игрока уже имеется бизнес!");
			if(pData[target][pTruckerOwnerID] != -1)
				return SendErr(playerid,  "У игрока уже имеется бизнес!");
			if(pData[target][pCasinoOwner] != -1)
				return SendErr(playerid, "У игрока уже имеется бизнес!");



			if(GetPlayerMoneyEx(target) < price)
				return SendErr(playerid, "У игрока нет данной суммы");

			new 
				taxiname[32],
				sell_mehcomp_mes[230];

			switch(pData[playerid][pTaxiOwnerID])
			{
				case 1: taxiname = "YandexGO";
				case 2: taxiname = "Uber Taxi";
				case 3: taxiname = "Ситимобил";
			}

			format(sell_mehcomp_mes, sizeof sell_mehcomp_mes, "\n"cBLUE"%s "cWH"предлагает купить его таксопарк:\n\n\
				"cWH"Номер таксопарка: "cBLUE"№%i\n\
				"cWH"Название: "cBLUE"%s\n\
				"cWH"Государственная цена: "cGR"%i рублей\n\n\
				"cWH"Стоимость покупки: "cGR"%i рублей\n", pData[playerid][pNickname], pData[playerid][pTaxiOwnerID], taxiname, taxi_company[pData[playerid][pTaxiOwnerID]][taxi_company_price], price);

			pTemp[target][offer_playerid] = playerid;
			pTemp[target][offer_time] = 10;
			SetPVarIntNew(playerid, "TaxiSellPrice", price);

			SPD(target, DIALOG_ACCEPT_BUY_TAXI_P, DIALOG_STYLE_MSGBOX, ""cBLUE"Предложение покупки таксопарка", sell_mehcomp_mes, !"Купить", !"Отмена");

			format(sell_mehcomp_mes, sizeof sell_mehcomp_mes, "Вы предложили "cBLUE"%s"cWH" купить таксопарк за "cGR"%i рублей", pData[target][pNickname], price);
			SendSucc(playerid, sell_mehcomp_mes);
			return true;
		}
		case DIALOG_ACCEPT_BUY_TAXI_P:
		{
			new 
				offerid = pTemp[playerid][offer_playerid],
				price = GetPVarIntNew(offerid, "TaxiSellPrice");

			if(!response)
			{
				SendInf(playerid, "Вы отказались от покупки таксопарка");
				SendInf(offerid, "Игрок отказался от покупки таксопарка");
				DeletePVarNew(offerid, "TaxiSellPrice");


				pTemp[playerid][offer_playerid] = INVALID_PLAYER_ID;
				pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
				pTemp[offerid][offer_playerid] = INVALID_PLAYER_ID;
				pTemp[offerid][offer_time] = pTemp[offerid][offer_action] = 0;				
				return true;
			}
			sell_taxi_to_player(offerid, playerid, price);
			return true;
		}
	}
	return true;

}

stock sell_house_to_player(offerid, playerid, price)
{
	if(!IsPlayerConnected(offerid))
		return SendErr(playerid, "Данного игрока нет");

	if(GetPlayerDistanceToPlayer(playerid, offerid) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(offerid))
		return SendErr(playerid, "Вы далеко друг от друга");

	if(pData[offerid][pHouse] == -1)
		return SendErr(playerid, "У игрока нет дома для продажи!");

	if(pData[playerid][pHouse] != -1 || pData[playerid][pHouseRent] != -1)
		return SendErr(playerid, "У Вас уже есть дом или Вы арендуете комнату в доме!");

	if(GetPlayerMoneyEx(playerid) < price)
		return SendErr(playerid, "У Вас недостаточно денег для покупки");

	new 
		h = pData[offerid][pHouse];

	if(pData[offerid][pFamily] != -1 && pData[offerid][pFamilyRank] == 7)
	{
		new 
			fam_id = pData[offerid][pFamily];
			
		format(String256, sizeof(String256), "UPDATE `family` SET \
	    	family_house = '-1'\
	    	WHERE family_id = '%i'",
	    	fam_id);

		sql_queryEx(zConn, String256, QUERY_THREADED);
	}

	pData[offerid][pHouse] = -1;
	UpdatePlayerData(offerid,"house", pData[offerid][pHouse]);
	pData[offerid][pSpawn] = 0;
	UpdatePlayerData(offerid, "spawn", pData[offerid][pSpawn]);


	pData[playerid][pHouse] = h;
	UpdatePlayerData(playerid,"house", pData[playerid][pHouse]);

   	House[h][house_owned] = pData[playerid][pMysqlID];	
    House[h][house_lock] = 1;
    
    House[h][house_people_status] = 0;
    House[h][house_status_people] = 0;	

    House[h][safe_house_status] = 0;
    House[h][safe_house_pass] = 1111;
    House[h][safe_house_money] = 0;
    House[h][safe_house_drugs] = 0;	

	House[h][wardrobe_gun_1] = -1;	
	House[h][wardrobe_gun_2] = -1;	
	House[h][wardrobe_gun_3] = -1;	
	House[h][wardrobe_skin_1] = 0;
	House[h][wardrobe_skin_2] = 0;
	House[h][wardrobe_skin_3] = 0;

    House[h][wardrobe_status] = 0;		
    House[h][house_subsidii_status] = 0;		

    update_house_pickup(h);
    save_house(h);	

    give_money(playerid, -price, "Покупка дома у игрока");
    give_money(offerid, price, "Продажа дома игроку");

    format(String256f,sizeof(String256f),"Поздравляем Вас с покупкой дома у %s за "cGR"%d"cWH" рублей!", pData[offerid][pNickname], price);
    SendSucc(playerid, String256f);
    format(String256f,sizeof(String256f),"Поздравляем Вас с продажей дома игроку %s за "cGR"%d"cWH" рублей!", pData[playerid][pNickname], price);
    SendSucc(offerid, String256f);


	pTemp[playerid][offer_playerid] = INVALID_PLAYER_ID;
	pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
	pTemp[offerid][offer_playerid] = INVALID_PLAYER_ID;
	pTemp[offerid][offer_time] = pTemp[offerid][offer_action] = 0;		

	PlayerPlaySound(playerid, 30800, 0.0, 0.0, 0.0);
	return true;
}

stock sell_flate_to_player(offerid, playerid, price)
{
	if(!IsPlayerConnected(offerid))
		return SendErr(playerid, "Данного игрока нет");

	if(GetPlayerDistanceToPlayer(playerid, offerid) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(offerid))
		return SendErr(playerid, "Вы далеко друг от друга");

	if(pData[offerid][pFlate] == -1)
		return SendErr(playerid, "У игрока нет квартиры для продажи");

	if(pData[playerid][pFlate] != -1 || pData[offerid][pFlateRent] != -1)
		return SendErr(playerid, "У Вас уже есть квартира или Вы арендуете комнату в квартире");

	if(GetPlayerMoneyEx(playerid) < price)
		return SendErr(playerid, "У Вас недостаточно денег для покупки");

	new 
		h = pData[offerid][pFlate];

	pData[offerid][pFlate] = -1;
	UpdatePlayerData(offerid,"flate", pData[offerid][pFlate]);
	pData[offerid][pSpawn] = 0;
	UpdatePlayerData(offerid, "spawn", pData[offerid][pSpawn]);

	pData[playerid][pFlate] = h;
	UpdatePlayerData(playerid,"flate", pData[playerid][pFlate]);

   	flate[h][flate_owned] = pData[playerid][pMysqlID];	

    flate[h][flate_people_status] = 0;
    flate[h][flate_status_people] = 0;	

    flate[h][safe_flate_status] = 0;
    flate[h][safe_flate_pass] = 1111;
    flate[h][safe_flate_money] = 0;
    flate[h][safe_flate_drugs] = 0;	

	flate[h][wardrobe_gun_1] = -1;	
	flate[h][wardrobe_gun_2] = -1;	
	flate[h][wardrobe_gun_3] = -1;	
	flate[h][wardrobe_skin_1] = 0;
	flate[h][wardrobe_skin_2] = 0;
	flate[h][wardrobe_skin_3] = 0;

    flate[h][wardrobe_status] = 0;		
    flate[h][flate_subsidii_status] = 0;		

    update_flate_pickup(h);
    save_flate(h);	

    give_money(playerid, -price, "Покупка квартиры у игрока");
    give_money(offerid, price, "Продажа квартиры игроку");

    format(String256f,sizeof(String256f),"Поздравляем Вас с покупкой квартиры у %s за "cGR"%d"cWH" рублей!", pData[offerid][pNickname], price);
    SendSucc(playerid, String256f);
    format(String256f,sizeof(String256f),"Поздравляем Вас с продажей квартиры игроку %s за "cGR"%d"cWH" рублей!", pData[playerid][pNickname], price);
    SendSucc(offerid, String256f);


	pTemp[playerid][offer_playerid] = INVALID_PLAYER_ID;
	pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
	pTemp[offerid][offer_playerid] = INVALID_PLAYER_ID;
	pTemp[offerid][offer_time] = pTemp[offerid][offer_action] = 0;		

	PlayerPlaySound(playerid, 30800, 0.0, 0.0, 0.0);
	return true;
}

stock sell_garage_to_player(offerid, playerid, price)
{
	if(!IsPlayerConnected(offerid))
		return SendErr(playerid, "Данного игрока нет");

	if(GetPlayerDistanceToPlayer(playerid, offerid) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(offerid))
		return SendErr(playerid, "Вы далеко друг от друга");

	if(pData[offerid][pGarage] == -1)
		return SendErr(playerid, "У игрока нет гаража для продажи!");

	if(pData[playerid][pGarage] != -1)
		return SendErr(playerid, "У Вас уже есть гараж!");

	if(GetPlayerMoneyEx(playerid) < price)
		return SendErr(playerid, "У Вас недостаточно денег для покупки");

	new 
		g = pData[offerid][pGarage];

	pData[offerid][pGarage] = -1;
	UpdatePlayerData(offerid,"pGarage", pData[offerid][pGarage]);

	pData[playerid][pGarage] = g;
	UpdatePlayerData(playerid,"pGarage", pData[playerid][pGarage]);

	garage[g][garage_owner_id] = pData[playerid][pMysqlID];	

	update_3d_text_garage(g);
	save_garage(g);	

    give_money(playerid, -price, "Покупка гаража у игрока");
    give_money(offerid, price, "Продажа гаража игроку");

    format(String256f,sizeof(String256f),"Поздравляем Вас с покупкой гаража у %s за "cGR"%d"cWH" рублей!", pData[offerid][pNickname], price);
    SendSucc(playerid, String256f);
    format(String256f,sizeof(String256f),"Поздравляем Вас с продажей гаража игроку %s за "cGR"%d"cWH" рублей!", pData[playerid][pNickname], price);
    SendSucc(offerid, String256f);


	pTemp[playerid][offer_playerid] = INVALID_PLAYER_ID;
	pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
	pTemp[offerid][offer_playerid] = INVALID_PLAYER_ID;
	pTemp[offerid][offer_time] = pTemp[offerid][offer_action] = 0;		

	PlayerPlaySound(playerid, 30800, 0.0, 0.0, 0.0);
	return true;
}

stock sell_filling_to_player(offerid, playerid, price)
{
	if(!IsPlayerConnected(offerid))
		return SendErr(playerid, "Данного игрока нет");

	if(GetPlayerDistanceToPlayer(playerid, offerid) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(offerid))
		return SendErr(playerid, "Вы далеко друг от друга");

	if(pData[offerid][pFillStation] == -1)
		return SendErr(playerid, "У игрока нет АЗС для продажи!");

	if(pData[playerid][pFillStation] != -1)
		return SendErr(playerid, "У Вас уже есть АЗС");

	if(GetPlayerMoneyEx(playerid) < price)
		return SendErr(playerid, "У Вас недостаточно денег для покупки");


	new 
		f = pData[offerid][pFillStation];

	pData[offerid][pFillStation] = -1;
	UpdatePlayerData(offerid,"pFillStation", pData[offerid][pFillStation]);


	pData[playerid][pFillStation] = f;
	UpdatePlayerData(playerid,"pFillStation", pData[playerid][pFillStation]);


	filling[f][filling_owner_id] = pData[playerid][pMysqlID];	
	filling[f][filling_bank] = 0;

	filling[f][filling_upgrade_1] = 0;
	filling[f][filling_upgrade_2] = 0;
	filling[f][filling_upgrade_3] = 0;
	filling[f][filling_upgrade_4] = 0;
	filling[f][filling_upgrade_electro] = 0;

	update_filling_pickup(f);
	save_fill(f);	

    give_money(playerid, -price, "Покупка АЗС у игрока");
    give_money(offerid, price, "Продажа АЗС игроку");

    format(String256f,sizeof(String256f),"Поздравляем Вас с покупкой АЗС у %s за "cGR"%d"cWH" рублей!", pData[offerid][pNickname], price);
    SendSucc(playerid, String256f);
    format(String256f,sizeof(String256f),"Поздравляем Вас с продажей АЗС игроку %s за "cGR"%d"cWH" рублей!", pData[playerid][pNickname], price);
    SendSucc(offerid, String256f);


	pTemp[playerid][offer_playerid] = INVALID_PLAYER_ID;
	pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
	pTemp[offerid][offer_playerid] = INVALID_PLAYER_ID;
	pTemp[offerid][offer_time] = pTemp[offerid][offer_action] = 0;		

	PlayerPlaySound(playerid, 30800, 0.0, 0.0, 0.0);
	return true;
}

stock sell_buisnes_to_player(offerid, playerid, price)
{
	if(!IsPlayerConnected(offerid))
		return SendErr(playerid, "Данного игрока нет");

	if(GetPlayerDistanceToPlayer(playerid, offerid) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(offerid))
		return SendErr(playerid, "Вы далеко друг от друга");

	if(pData[offerid][pBusiness] == -1)
		return SendErr(playerid, "У игрока нет бизнеса для продажи!");

	if(pData[playerid][pBusiness] != -1)
		return SendErr(playerid, "У Вас уже есть бизнес");

	if(GetPlayerMoneyEx(playerid) < price)
		return SendErr(playerid, "У Вас недостаточно денег для покупки");

	new 
		f = pData[offerid][pBusiness];


	pData[offerid][pBusiness] = -1;
	UpdatePlayerData(offerid,"bussiness", pData[offerid][pBusiness]);

	pData[playerid][pBusiness] = f;
	UpdatePlayerData(playerid,"bussiness", pData[playerid][pBusiness]);

	buisness[f][buisnes_owned] = pData[playerid][pMysqlID];	
	buisness[f][buisnes_bank] = 0;

	new
		b_owner[24];

	if(buisness[f][buisnes_owned] != -1)
	{
		GetPlayerNameByID(buisness[f][buisnes_owned], buisness[f][buisnes_owner]);
		format(b_owner, 24, buisness[f][buisnes_owner]);
	}
	else
	{
		format(b_owner, 24, "Государство");	
	}

	update_biz_text(); 
	save_biz(f);

    give_money(playerid, -price, "Покупка бизнеса у игрока");
    give_money(offerid, price, "Продажа бизнеса игроку");

    format(String256f,sizeof(String256f),"Поздравляем Вас с покупкой бизнеса у %s за "cGR"%d"cWH" рублей!", pData[offerid][pNickname], price);
    SendSucc(playerid, String256f);
    format(String256f,sizeof(String256f),"Поздравляем Вас с продажей бизнеса игроку %s за "cGR"%d"cWH" рублей!", pData[playerid][pNickname], price);
    SendSucc(offerid, String256f);


	pTemp[playerid][offer_playerid] = INVALID_PLAYER_ID;
	pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
	pTemp[offerid][offer_playerid] = INVALID_PLAYER_ID;
	pTemp[offerid][offer_time] = pTemp[offerid][offer_action] = 0;		

	PlayerPlaySound(playerid, 30800, 0.0, 0.0, 0.0);
	return true;
}

stock sell_hotel_to_player(offerid, playerid, price)
{
	if(!IsPlayerConnected(offerid))
		return SendErr(playerid, "Данного игрока нет");

	if(GetPlayerDistanceToPlayer(playerid, offerid) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(offerid))
		return SendErr(playerid, "Вы далеко друг от друга");

	if(pData[offerid][pHotelOwner] == -1)
		return SendErr(playerid, "У игрока нет отеля для продажи!");

	if(pData[playerid][pHotelOwner] != -1)
		return SendErr(playerid, "У Вас уже есть отель");

	if(GetPlayerMoneyEx(playerid) < price)
		return SendErr(playerid, "У Вас недостаточно денег для покупки");

	new 
		f = pData[offerid][pHotelOwner];


	pData[offerid][pHotelOwner] = -1;
	UpdatePlayerData(offerid,"pHotelOwner", pData[offerid][pHotelOwner]);

	pData[playerid][pHotelOwner] = f;
	UpdatePlayerData(playerid,"pHotelOwner", pData[playerid][pHotelOwner]);


	hotel[f][hotel_owned] = pData[playerid][pMysqlID];	
	hotel[f][hotel_bank] = 0;

	update_hotel_text_3d(f);
	save_hotel(f);

    give_money(playerid, -price, "Покупка отеля у игрока");
    give_money(offerid, price, "Продажа отеля игроку");

    format(String256f,sizeof(String256f),"Поздравляем Вас с покупкой отеля у %s за "cGR"%d"cWH" рублей!", pData[offerid][pNickname], price);
    SendSucc(playerid, String256f);
    format(String256f,sizeof(String256f),"Поздравляем Вас с продажей отеля игроку %s за "cGR"%d"cWH" рублей!", pData[playerid][pNickname], price);
    SendSucc(offerid, String256f);



	pTemp[playerid][offer_playerid] = INVALID_PLAYER_ID;
	pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
	pTemp[offerid][offer_playerid] = INVALID_PLAYER_ID;
	pTemp[offerid][offer_time] = pTemp[offerid][offer_action] = 0;		

	PlayerPlaySound(playerid, 30800, 0.0, 0.0, 0.0);
	return true;
}

stock sell_casino_to_player(offerid, playerid, price)
{
	if(!IsPlayerConnected(offerid))
		return SendErr(playerid, "Данного игрока нет");

	if(GetPlayerDistanceToPlayer(playerid, offerid) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(offerid))
		return SendErr(playerid, "Вы далеко друг от друга");

	if(pData[offerid][pCasinoOwner] == -1)
		return SendErr(playerid, "У игрока нет казино для продажи!");

	if(pData[offerid][pCasinoOwner] != -1)
		return SendErr(playerid, "У Вас уже есть казино");

	if(GetPlayerMoneyEx(playerid) < price)
		return SendErr(playerid, "У Вас недостаточно денег для покупки");

	new 
		f = pData[offerid][pCasinoOwner];

	pData[offerid][pCasinoOwner] = -1;
	UpdatePlayerData(offerid,"pCasinoOwner", pData[offerid][pCasinoOwner]);

	pData[playerid][pCasinoOwner] = f;
	UpdatePlayerData(playerid,"pCasinoOwner", pData[playerid][pCasinoOwner]);


	casino[f][casino_owner_id] = pData[playerid][pMysqlID];	
	casino[f][casino_bank] = 0;

	update_casino_3d_text(f);
	save_casino(f);	

    give_money(playerid, -price, "Покупка казино у игрока");
    give_money(offerid, price, "Продажа казино игроку");


    format(String256f,sizeof(String256f),"Поздравляем Вас с покупкой казино у %s за "cGR"%d"cWH" рублей!", pData[offerid][pNickname], price);
    SendSucc(playerid, String256f);
    format(String256f,sizeof(String256f),"Поздравляем Вас с продажей казино игроку %s за "cGR"%d"cWH" рублей!", pData[playerid][pNickname], price);
    SendSucc(offerid, String256f);


	pTemp[playerid][offer_playerid] = INVALID_PLAYER_ID;
	pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
	pTemp[offerid][offer_playerid] = INVALID_PLAYER_ID;
	pTemp[offerid][offer_time] = pTemp[offerid][offer_action] = 0;		

	PlayerPlaySound(playerid, 30800, 0.0, 0.0, 0.0);
	return true;
}

stock sell_tk_to_player(offerid, playerid, price)
{
	if(!IsPlayerConnected(offerid))
		return SendErr(playerid, "Данного игрока нет");

	if(GetPlayerDistanceToPlayer(playerid, offerid) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(offerid))
		return SendErr(playerid, "Вы далеко друг от друга");

	if(pData[offerid][pTruckerOwnerID] == -1)
		return SendErr(playerid, "У игрока нет транспортной компании для продажи!");

	if(pData[playerid][pTruckerOwnerID] != -1)
		return SendErr(playerid, "У Вас уже есть транспортная компания!");

	if(GetPlayerMoneyEx(playerid) < price)
		return SendErr(playerid, "У Вас недостаточно денег для покупки");

	new 
		f = pData[offerid][pTruckerOwnerID];

	pData[offerid][pTruckerOwnerID] = -1;
	UpdatePlayerData(offerid,"pTruckerOwnerID", pData[offerid][pTruckerOwnerID]);

	pData[playerid][pTruckerOwnerID] = f;
	UpdatePlayerData(playerid,"pTruckerOwnerID", pData[playerid][pTruckerOwnerID]);

	pData[playerid][pTrucker] = f;
	UpdatePlayerData(playerid,"pTrucker", pData[playerid][pTrucker]);

	trucker_station[f][trucker_base_owner_id] = pData[playerid][pMysqlID];	
	trucker_station[f][trucker_base_bank] = 0;
	trucker_station[f][trucker_person_count] = 25;
	trucker_station[f][trucker_level_veh] = 1;
	trucker_station[f][trucker_veh_count] = 25;

	save_trucker_base();
	update_trucker_3d_text();

    give_money(playerid, -price, "Покупка ТК у игрока");
    give_money(offerid, price, "Продажа ТК игроку");

    format(String256f,sizeof(String256f),"Поздравляем Вас с покупкой ТК у %s за "cGR"%d"cWH" рублей!", pData[offerid][pNickname], price);
    SendSucc(playerid, String256f);
    format(String256f,sizeof(String256f),"Поздравляем Вас с продажей ТК игроку %s за "cGR"%d"cWH" рублей!", pData[playerid][pNickname], price);
    SendSucc(offerid, String256f);

	format(String1024,sizeof(String1024),"INSERT INTO `trucker_personal`(`id`,`owner`,`user_rank`) VALUES ('%d','%s','%d')", f, 
		GetName(playerid), 3);
	sql_queryEx(zConn, String1024, QUERY_THREADED);


	pData[offerid][pTrucker] = -1;
	pData[offerid][pTruckerOwnerLowID] = -1;
	pData[offerid][pTruckerRank] = 0;
	pData[offerid][pJob] = 0;

	UpdatePlayerData(playerid,"pTrucker", pData[offerid][pTrucker]);
	UpdatePlayerData(playerid,"pTruckerOwnerLowID", pData[offerid][pTruckerOwnerLowID]);
	UpdatePlayerData(playerid,"pTruckerRank", pData[offerid][pTruckerRank]);
	UpdatePlayerData(playerid, "job", pData[offerid][pJob]);

	format(String256,sizeof(String256),"DELETE FROM `trucker_personal` WHERE `owner` = '%s'", GetName(offerid));
	sql_queryEx(zConn, String256, QUERY_THREADED);    

	pTemp[playerid][offer_playerid] = INVALID_PLAYER_ID;
	pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
	pTemp[offerid][offer_playerid] = INVALID_PLAYER_ID;
	pTemp[offerid][offer_time] = pTemp[offerid][offer_action] = 0;		

	PlayerPlaySound(playerid, 30800, 0.0, 0.0, 0.0);
	return true;
}

stock sell_mech_to_player(offerid, playerid, price)
{
	if(!IsPlayerConnected(offerid))
		return SendErr(playerid, "Данного игрока нет");

	if(GetPlayerDistanceToPlayer(playerid, offerid) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(offerid))
		return SendErr(playerid, "Вы далеко друг от друга");

	if(pData[offerid][pMechOwnerID] == -1)
		return SendErr(playerid, "У игрока нет СТО для продажи!");

	if(pData[playerid][pMechOwnerID] != -1)
		return SendErr(playerid, "У Вас уже есть СТО");

	if(GetPlayerMoneyEx(playerid) < price)
		return SendErr(playerid, "У Вас недостаточно денег для покупки");

	new 
		f = pData[offerid][pMechOwnerID];

	new 
		mech_owner_str[64];

	format(mechanic[f][mechanic_base_owner], 32, "%s", pData[playerid][pNickname]);
	format(mech_owner_str, 32, "%s", pData[playerid][pNickname]);

	format(String256,sizeof(String256),"UPDATE `mechanic` SET `owner_name` = '%s' WHERE `id` = '%d'" , mech_owner_str, f);
	sql_queryEx(zConn, String256, QUERY_THREADED);	
	format(String256,sizeof(String256),"UPDATE `mechanic` SET `owner_id` = '%d' WHERE `id` = '%d'" , pData[playerid][pMysqlID], f);
	sql_queryEx(zConn, String256, QUERY_THREADED);	

	pData[offerid][pMechOwnerID] = -1;
	UpdatePlayerData(offerid,"pMechOwnerID", pData[offerid][pMechOwnerID]);

	pData[playerid][pMechOwnerID] = f;
	UpdatePlayerData(playerid,"pMechOwnerID", pData[playerid][pMechOwnerID]);

	mechanic[f][mechanic_base_owner_id] = pData[playerid][pMysqlID];	
	mechanic[f][mechanic_base_bank] = 0;

	save_mechanic_base();
	update_mechanic_3d_text();

    give_money(playerid, -price, "Покупка ТК у игрока");
    give_money(offerid, price, "Продажа ТК игроку");

    format(String256f,sizeof(String256f),"Поздравляем Вас с покупкой СТО у %s за "cGR"%d"cWH" рублей!", pData[offerid][pNickname], price);
    SendSucc(playerid, String256f);
    format(String256f,sizeof(String256f),"Поздравляем Вас с продажей СТО игроку %s за "cGR"%d"cWH" рублей!", pData[playerid][pNickname], price);
    SendSucc(offerid, String256f);


	pTemp[playerid][offer_playerid] = INVALID_PLAYER_ID;
	pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
	pTemp[offerid][offer_playerid] = INVALID_PLAYER_ID;
	pTemp[offerid][offer_time] = pTemp[offerid][offer_action] = 0;		

	PlayerPlaySound(playerid, 30800, 0.0, 0.0, 0.0);
	return true;
}

stock sell_taxi_to_player(offerid, playerid, price)
{
	if(!IsPlayerConnected(offerid))
		return SendErr(playerid, "Данного игрока нет");

	if(GetPlayerDistanceToPlayer(playerid, offerid) > 3.0 || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(offerid))
		return SendErr(playerid, "Вы далеко друг от друга");

	if(pData[offerid][pTaxiOwnerID] == -1)
		return SendErr(playerid, "У игрока нет таксопарка для продажи!");

	if(pData[playerid][pTaxiOwnerID] != -1)
		return SendErr(playerid, "У Вас уже есть таксопарк");

	if(GetPlayerMoneyEx(playerid) < price)
		return SendErr(playerid, "У Вас недостаточно денег для покупки");

	new 
		f = pData[offerid][pTaxiOwnerID];

	pData[offerid][pTaxiOwnerID] = -1;
	UpdatePlayerData(offerid,"pTaxiOwnerID", pData[offerid][pTaxiOwnerID]);

	pData[playerid][pTaxiOwnerID] = f;
	UpdatePlayerData(playerid,"pTaxiOwnerID", pData[playerid][pTaxiOwnerID]);

	taxi_company[f][taxi_company_owner_id] = pData[playerid][pMysqlID];		
	taxi_company[f][taxi_company_bank] = 0;

	save_taxi_base();
	update_taxi_3d_text();

    give_money(playerid, -price, "Покупка таксопарка у игрока");
    give_money(offerid, price, "Продажа таксопарка игроку");

    format(String256f,sizeof(String256f),"Поздравляем Вас с покупкой Таксопарка у %s за "cGR"%d"cWH" рублей!", pData[offerid][pNickname], price);
    SendSucc(playerid, String256f);
    format(String256f,sizeof(String256f),"Поздравляем Вас с продажей Таксопарка игроку %s за "cGR"%d"cWH" рублей!", pData[playerid][pNickname], price);
    SendSucc(offerid, String256f);


	pTemp[playerid][offer_playerid] = INVALID_PLAYER_ID;
	pTemp[playerid][offer_time] = pTemp[playerid][offer_action] = 0;
	pTemp[offerid][offer_playerid] = INVALID_PLAYER_ID;
	pTemp[offerid][offer_time] = pTemp[offerid][offer_action] = 0;		

	PlayerPlaySound(playerid, 30800, 0.0, 0.0, 0.0);
	return true;
}

//==================================[Команды]===========================================
CMD:sellproperty(playerid)
{
	SPD(playerid, DIALOG_SELECT_SELL_P_P, DIALOG_STYLE_LIST, ""cBLUE"Продажа имущества",
	 ""cBLUE"- "cWH"Продать дом\n\
	 "cBLUE"- "cWH"Продать квартиру\n\
	 "cBLUE"- "cWH"Продать гараж\n\
	 "cBLUE"- "cWH"Продать АЗС\n\
	 "cBLUE"- "cWH"Продать бизнес\n\
	 "cBLUE"- "cWH"Продать отель\n\
	 "cBLUE"- "cWH"Продать казино\n\
	 "cBLUE"- "cWH"Продать транспортную компанию\n\
	 "cBLUE"- "cWH"Продать СТО\n\
	 "cBLUE"- "cWH"Продать таксопарк", "Выбрать", "Отмена");
	return true;
}
//======================================================================================