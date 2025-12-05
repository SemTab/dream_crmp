


stock show_bank_pay_property(playerid)
{
	return SPD(playerid, DIALOG_BANK_PROPERTY_PAY, 2, \
	""cBLUE"Меню банка", \
	"{FFD966}1. "cWH"Оплата дома\n\
	{FFD966}2. "cWH"Оплата квартиры\n\
	{FFD966}3. "cWH"Оплата АЗС\n\
	{FFD966}4. "cWH"Оплата отеля\n\
	{FFD966}5. "cWH"Оплата гаража\n\
	{FFD966}6. "cWH"Оплата СТО\n\
	{FFD966}7. "cWH"Оплата Транспортной Компании\n\
	{FFD966}8. "cWH"Оплата Таксопарка\n\
	{FFD966}9. "cWH"Оплата казино\n\
	{FFD966}10. "cWH"Оплата остального бизнеса", "Перейти", "Отмена");
}


stock dialog_all_property(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
		case DIALOG_BANK_PROPERTY_PAY:
		{
			if(!response) 
				return true;

			switch(listitem)
			{
				case 0: return payment_tax_house(playerid);
				case 1: return payment_tax_flate(playerid);
				case 2: return payment_tax_fill(playerid);
				case 3: return payment_tax_hotel(playerid);
				case 4: return payment_tax_garage(playerid);
				case 5: return payment_tax_sto(playerid);
				case 6: return payment_tax_tk(playerid);
				case 7: return payment_tax_taxi(playerid);
				case 8: return payment_tax_casino(playerid);
				case 9: return payment_tax_buisnes_all(playerid);
			}
		}

		case DIALOG_PAYMENT_HOUSE:
		{

			if(!response)
				return show_bank_pay_property(playerid);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное количество дней!");
				return payment_tax_house(playerid);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное количество дней!");
				return payment_tax_house(playerid);
			}

			new 
				house_id_pay,
				house_takings_price,
				house_day, 
				house_max_day;

			if(pData[playerid][pHouse] == -1)
			{
				show_bank_pay_property(playerid);
				return SendErr(playerid, "Вы не владете домом");		
			}

			if(pData[playerid][pHouse] != -1 && pData[playerid][pFlate] == -1)
			{
				house_id_pay = pData[playerid][pHouse];

				if(House[house_id_pay][house_subsidii_status])
				{
					house_takings_price = House[house_id_pay][house_takings]/2;
				}
				else
				{
					house_takings_price = House[house_id_pay][house_takings];
				}
				
				house_day = House[house_id_pay][house_days];

				house_max_day = 30-house_day;
			}

			new 
				count_day_rent = strval(inputtext);


			if(count_day_rent < 1 || count_day_rent > house_max_day)
			{
				format(String144, sizeof(String144), "От %d дней до %d дней!", 1, house_max_day);
				SendErr(playerid, String144);
				return payment_tax_house(playerid);
			}	

			if(GetPlayerMoneyEx(playerid) < count_day_rent*house_takings_price) 
			{
				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:info_gui_no_money", 3000);
			    SendErr(playerid,"Недостаточно денежных средств!");
				return payment_tax_house(playerid);
			}

			if(pData[playerid][pHouse] != -1 && pData[playerid][pFlate] == -1)
			{
				house_id_pay = pData[playerid][pHouse];
				House[house_id_pay][house_days] += count_day_rent;

				save_house(house_id_pay);
			}

			give_money(playerid, -count_day_rent*house_takings_price, "Оплата дома");

			format(String256, sizeof(String256), "Вы успешно оплатили жильё на %d дней!", count_day_rent);
			SendSucc(playerid, String256);				
			show_bank_pay_property(playerid);

		}
		case DIALOG_PAYMENT_FLATE:
		{

			if(!response)
				return show_bank_pay_property(playerid);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное количество дней!");
				return payment_tax_flate(playerid);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное количество дней!");
				return payment_tax_flate(playerid);
			}

			new 
				house_id_pay,
				house_takings_price,
				house_day, 
				house_max_day;

			if(pData[playerid][pFlate] == -1)
			{
				show_bank_pay_property(playerid);
				return SendErr(playerid, "Вы не владете квартирой");		
			}

			if(pData[playerid][pHouse] == -1 && pData[playerid][pFlate] != -1)
			{
				house_id_pay = pData[playerid][pFlate];

				if(flate[house_id_pay][flate_subsidii_status])
				{
					house_takings_price = flate[house_id_pay][flate_takings]/2;
				}
				else
				{
					house_takings_price = flate[house_id_pay][flate_takings];
				}

				
				house_day = flate[house_id_pay][flate_days];

				house_max_day = 30-house_day;
			}

			new 
				count_day_rent = strval(inputtext);


			if(count_day_rent < 1 || count_day_rent > house_max_day)
			{
				format(String144, sizeof(String144), "От %d дней до %d дней!", 1, house_max_day);
				SendErr(playerid, String144);
				return payment_tax_flate(playerid);
			}	

			if(GetPlayerMoneyEx(playerid) < count_day_rent*house_takings_price) 
			{
				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:info_gui_no_money", 3000);
			    SendErr(playerid,"Недостаточно денежных средств!");
				return payment_tax_flate(playerid);
			}

			if(pData[playerid][pHouse] == -1 && pData[playerid][pFlate] != -1)
			{
				house_id_pay = pData[playerid][pFlate];
				flate[house_id_pay][flate_days] += count_day_rent;

				save_flate(house_id_pay);
			}

			give_money(playerid,  -count_day_rent*house_takings_price, "Оплата квартиры");

			format(String256, sizeof(String256), "Вы успешно оплатили жильё на %d дней!", count_day_rent);
			SendSucc(playerid, String256);				
			show_bank_pay_property(playerid);

		}
		case DIALOG_PAYMENT_FILLING:
		{
			if(!response)
				return show_bank_pay_property(playerid);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное количество дней!");
				return payment_tax_fill(playerid);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное количество дней!");
				return payment_tax_fill(playerid);
			}	
			new 
				count_day_rent = strval(inputtext);


			new 
				f = pData[playerid][pFillStation];

			new 
				max_day = 30-filling[f][filling_day];


			if(count_day_rent < 1 || count_day_rent > max_day)
			{
				format(String144, sizeof(String144), "От %d дней до %d дней!", 1, max_day);
				SendErr(playerid, String144);
				return payment_tax_fill(playerid);
			}	

			if(GetPlayerMoneyEx(playerid) < count_day_rent*filling[f][filling_takings]) 
			{
				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:info_gui_no_money", 3000);
			    SendErr(playerid,"Недостаточно денежных средств!");
				return payment_tax_fill(playerid);
			}	

			give_money(playerid,  -count_day_rent*filling[f][filling_takings], "Оплата бизнеса");

			filling[f][filling_day] += count_day_rent;

			format(String256, sizeof(String256), "Вы успешно оплатили АЗС на %d дней. АЗС в сумме оплачено на %d дней!", count_day_rent, filling[f][filling_day]);
			SendSucc(playerid, String256);	

			show_bank_pay_property(playerid);	

		}
		case DIALOG_PAYMENT_HOTEL:
		{
			if(!response)
				return show_bank_pay_property(playerid);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное количество дней!");
				return payment_tax_hotel(playerid);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное количество дней!");
				return payment_tax_hotel(playerid);
			}	
			new 
				count_day_rent = strval(inputtext);


			new 
				f = pData[playerid][pHotelOwner];

			new 
				max_day = 30-hotel[f][hotel_days];


			if(count_day_rent < 1 || count_day_rent > max_day)
			{
				format(String144, sizeof(String144), "От %d дней до %d дней!", 1, max_day);
				SendErr(playerid, String144);
				return payment_tax_hotel(playerid);
			}	

			if(GetPlayerMoneyEx(playerid) < count_day_rent*hotel[f][hotel_takings]) 
			{
				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:info_gui_no_money", 3000);
			    SendErr(playerid,"Недостаточно денежных средств!");
				return payment_tax_hotel(playerid);
			}	

			give_money(playerid,  -count_day_rent*hotel[f][hotel_takings], "Оплата бизнеса");

			hotel[f][hotel_days] += count_day_rent;

			format(String256, sizeof(String256), "Вы успешно оплатили отель на %d дней. Отель в сумме оплачен на %d дней!", count_day_rent, hotel[f][hotel_days]);
			SendSucc(playerid, String256);

			save_hotel(f);
			show_bank_pay_property(playerid);

		}
		case DIALOG_PAYMENT_GARAGE:
		{
			if(!response)
				return show_bank_pay_property(playerid);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное количество дней!");
				return payment_tax_garage(playerid);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное количество дней!");
				return payment_tax_garage(playerid);
			}	
			new 
				count_day_rent = strval(inputtext);


			new 
				f = pData[playerid][pGarage];

			new 
				max_day = 30-garage[f][garage_days];


			if(count_day_rent < 1 || count_day_rent > max_day)
			{
				format(String144, sizeof(String144), "От %d дней до %d дней!", 1, max_day);
				SendErr(playerid, String144);
				return payment_tax_garage(playerid);
			}	

			if(GetPlayerMoneyEx(playerid) < count_day_rent*garage[f][garage_takings]) 
			{
				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:info_gui_no_money", 3000);
			    SendErr(playerid,"Недостаточно денежных средств!");
				return payment_tax_garage(playerid);
			}	

			give_money(playerid,  -count_day_rent*garage[f][garage_takings], "Оплата бизнеса");

			garage[f][garage_days] += count_day_rent;

			format(String256, sizeof(String256), "Вы успешно оплатили гараж на %d дней. Гараж в сумме оплачен на %d дней!", count_day_rent, garage[f][garage_days]);
			SendSucc(playerid, String256);

			save_garage(f);
			show_bank_pay_property(playerid);			
		}
		case DIALOG_PAYMENT_BIZ_ALL:
		{
			if(!response)
				return show_bank_pay_property(playerid);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное количество дней!");
				return payment_tax_buisnes_all(playerid);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное количество дней!");
				return payment_tax_buisnes_all(playerid);
			}	

			new 
				count_day_rent = strval(inputtext);


			new 
				f = pData[playerid][pBusiness];

			new 
				max_day = 30-buisness[f][buisnes_days];


			if(count_day_rent < 1 || count_day_rent > max_day)
			{
				format(String144, sizeof(String144), "От %d дней до %d дней!", 1, max_day);
				SendErr(playerid, String144);
				return payment_tax_buisnes_all(playerid);
			}	

			if(GetPlayerMoneyEx(playerid) < count_day_rent*buisness[f][buisnes_takings]) 
			{
				format(String144, sizeof(String144), "От %d дней до %d дней!", 1, max_day);
				SendErr(playerid, String144);
				return payment_tax_buisnes_all(playerid);
			}	

			give_money(playerid,  -count_day_rent*buisness[f][buisnes_takings], "Оплата бизнеса");

			buisness[f][buisnes_days] += count_day_rent;

			format(String256, sizeof(String256), "Вы успешно оплатили бизнес на %d дней. Бизнес в сумме оплачен на %d дней!", count_day_rent, buisness[f][buisnes_days]);
			SendSucc(playerid, String256);

			save_biz(f);
			show_bank_pay_property(playerid);				
		}
		case DIALOG_PAYMENT_CASINO:
		{

			if(!response)
				return show_bank_pay_property(playerid);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное количество дней!");
				return payment_tax_casino(playerid);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное количество дней!");
				return payment_tax_casino(playerid);
			}	

			new 
				count_day_rent = strval(inputtext);


			new 
				f = pData[playerid][pCasinoOwner];

			new 
				max_day = 30-casino[f][casino_day];

			if(count_day_rent < 1 || count_day_rent > max_day)
			{
				format(String144, sizeof(String144), "От %d дней до %d дней!", 1, max_day);
				SendErr(playerid, String144);
				return payment_tax_casino(playerid);
			}	

			if(GetPlayerMoneyEx(playerid) < count_day_rent*casino[f][casino_takings]) 
			{
				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:info_gui_no_money", 3000);
			    SendErr(playerid,"Недостаточно денежных средств!");
				return payment_tax_casino(playerid);
			}					

			give_money(playerid,  -count_day_rent*casino[f][casino_takings], "Оплата бизнеса");

			casino[f][casino_day] += count_day_rent;

			format(String256, sizeof(String256), "Вы успешно оплатили казино на %d дней. Казино в сумме оплачено на %d дней!", count_day_rent, casino[f][casino_day]);
			SendSucc(playerid, String256);


			save_casino(f);
			show_bank_pay_property(playerid);	

		}
		case DIALOG_PAYMENT_STO:
		{
			if(!response)
				return show_bank_pay_property(playerid);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное количество дней!");
				return payment_tax_sto(playerid);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное количество дней!");
				return payment_tax_sto(playerid);
			}	
			new 
				count_day_rent = strval(inputtext);


			new 
				f = pData[playerid][pMechOwnerID];

			new 
				max_day = 30-mechanic[f][mechanic_base_days];


			if(count_day_rent < 1 || count_day_rent > max_day)
			{
				format(String144, sizeof(String144), "От %d дней до %d дней!", 1, max_day);
				SendErr(playerid, String144);
				return payment_tax_sto(playerid);
			}	

			if(GetPlayerMoneyEx(playerid) < count_day_rent*1500) 
			{
				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:info_gui_no_money", 3000);
			    SendErr(playerid,"Недостаточно денежных средств!");
				return payment_tax_sto(playerid);
			}	

			give_money(playerid,  -count_day_rent*1500, "Оплата бизнеса");

			mechanic[f][mechanic_base_days] += count_day_rent;

			format(String256, sizeof(String256), "Вы успешно оплатили СТО на %d дней. СТО в сумме оплачено на %d дней!", count_day_rent, mechanic[f][mechanic_base_days]);
			SendSucc(playerid, String256);

			save_mechanic_base();
			show_bank_pay_property(playerid);				
		}
		case DIALOG_PAYMENT_TRUCKER:
		{
			if(!response)
				return show_bank_pay_property(playerid);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное количество дней!");
				return payment_tax_tk(playerid);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное количество дней!");
				return payment_tax_tk(playerid);
			}	
			new 
				count_day_rent = strval(inputtext);


			new 
				f = pData[playerid][pTruckerOwnerID];

			new 
				max_day = 30-trucker_station[f][trucker_base_days];


			if(count_day_rent < 1 || count_day_rent > max_day)
			{
				format(String144, sizeof(String144), "От %d дней до %d дней!", 1, max_day);
				SendErr(playerid, String144);
				return payment_tax_tk(playerid);
			}	

			if(GetPlayerMoneyEx(playerid) < count_day_rent*1500) 
			{
				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:info_gui_no_money", 3000);
			    SendErr(playerid,"Недостаточно денежных средств!");
				return payment_tax_tk(playerid);
			}	

			give_money(playerid,  -count_day_rent*1500, "Оплата бизнеса");

			trucker_station[f][trucker_base_days] += count_day_rent;

			format(String256, sizeof(String256), "Вы успешно оплатили ТК на %d дней. ТК в сумме оплачено на %d дней!", count_day_rent, trucker_station[f][trucker_base_days]);
			SendSucc(playerid, String256);

			save_trucker_base();
			show_bank_pay_property(playerid);				
		}
		case DIALOG_PAYMENT_TAXI:
		{
			if(!response)
				return show_bank_pay_property(playerid);

			if(!IsNumeric(inputtext)) 
			{
				SendErr(playerid,"Вы указали неверное количество дней!");
				return payment_tax_taxi(playerid);
			}

			if(!strlen(inputtext) || strlen(inputtext) == 0)
			{
				SendErr(playerid,"Вы указали неверное количество дней!");
				return payment_tax_taxi(playerid);
			}	
			new 
				count_day_rent = strval(inputtext);


			new 
				f = pData[playerid][pTaxiOwnerID];

			new 
				max_day = 30-taxi_company[f][taxi_company_days];


			if(count_day_rent < 1 || count_day_rent > max_day)
			{
				format(String144, sizeof(String144), "От %d дней до %d дней!", 1, max_day);
				SendErr(playerid, String144);
				return payment_tax_taxi(playerid);
			}	

			if(GetPlayerMoneyEx(playerid) < count_day_rent*1500) 
			{
				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:info_gui_no_money", 3000);
			    SendErr(playerid,"Недостаточно денежных средств!");
				return payment_tax_taxi(playerid);
			}	

			give_money(playerid,  -count_day_rent*1500, "Оплата бизнеса");

			taxi_company[f][taxi_company_days] += count_day_rent;

			format(String256, sizeof(String256), "Вы успешно оплатили Таксопарк на %d дней. Таксопарк в сумме оплачено на %d дней!", count_day_rent, taxi_company[f][taxi_company_days]);
			SendSucc(playerid, String256);

			save_trucker_base();
			show_bank_pay_property(playerid);					
		}

	}
	return true;
}

stock payment_tax_buisnes_all(playerid)
{

	if(pData[playerid][pBusiness] == -1)
	{
		show_bank_pay_property(playerid);
		return SendErr(playerid, "Вы не владете бизнесом!");		
	}

	new 
		biz_id_pay,
		biz_takings_price,
		biz_day, 
		biz_max_day;

	biz_id_pay = pData[playerid][pBusiness];
	biz_takings_price = buisness[biz_id_pay][buisnes_takings];
	biz_day = buisness[biz_id_pay][buisnes_days];

	biz_max_day = 30-biz_day;

	format(String512, sizeof(String512), "\
	"cWH"Текущая стоимость: "cGR"%d"cWH" рублей за 1 день\n\n\
	"cWH"Вы можете оплатить максимум на "cBLUE"%d"cWH" дней\n\n\
	"cWH"Насколько Вы хотите оплатить?", biz_takings_price, biz_max_day);

	return SPD(playerid, DIALOG_PAYMENT_BIZ_ALL, DIALOG_STYLE_INPUT, !""cBLUE"Оплата бизнеса", String512, !"Далее", !"Назад");
}

stock payment_tax_house(playerid)
{

	new 
		house_id_pay,
		house_takings_price,
		house_day, 
		house_max_day;

	if(pData[playerid][pHouse] == -1)
	{
		show_bank_pay_property(playerid);
		return SendErr(playerid, "Вы не владете домом!");		
	}

	if(pData[playerid][pHouse] != -1 && pData[playerid][pFlate] == -1)
	{
		house_id_pay = pData[playerid][pHouse];
		house_takings_price = House[house_id_pay][house_takings];
		house_day = House[house_id_pay][house_days];

		house_max_day = 30-house_day;
	}

	format(String512, sizeof(String512), "\
	"cWH"Текущая стоимость: "cGR"%d"cWH" рублей за 1 день\n\n\
	"cWH"Вы можете оплатить максимум на "cBLUE"%d"cWH" дней\n\n\
	"cWH"Насколько Вы хотите оплатить?", house_takings_price, house_max_day);

	return SPD(playerid, DIALOG_PAYMENT_HOUSE, DIALOG_STYLE_INPUT, !""cBLUE"Оплата дома/квартиры", String512, !"Далее", !"Назад");
}

stock payment_tax_flate(playerid)
{

	new 
		house_id_pay,
		house_takings_price,
		house_day, 
		house_max_day;

	if(pData[playerid][pFlate] == -1)
	{
		show_bank_pay_property(playerid);
		return SendErr(playerid, "Вы не владете квартирой!");		
	}

	if(pData[playerid][pHouse] == -1 && pData[playerid][pFlate] != -1)
	{
		house_id_pay = pData[playerid][pFlate];
		house_takings_price = flate[house_id_pay][flate_takings];
		house_day = flate[house_id_pay][flate_days];

		house_max_day = 30-house_day;
	}

	format(String512, sizeof(String512), "\
	"cWH"Текущая стоимость: "cGR"%d"cWH" рублей за 1 день\n\n\
	"cWH"Вы можете оплатить максимум на "cBLUE"%d"cWH" дней\n\n\
	"cWH"Насколько Вы хотите оплатить?", house_takings_price, house_max_day);

	return SPD(playerid, DIALOG_PAYMENT_FLATE, DIALOG_STYLE_INPUT, !""cBLUE"Оплата квартиры", String512, !"Далее", !"Назад");
}

stock payment_tax_fill(playerid)
{
	if(pData[playerid][pFillStation] == -1)
	{
		show_bank_pay_property(playerid);
		return SendErr(playerid, "Вы не владете АЗС!");				
	}

	new 
		f = pData[playerid][pFillStation];

	new 
		max_day = 30-filling[f][filling_day];

	format(String512, sizeof(String512), "\
	"cWH"Текущая стоимость: "cGR"%d"cWH" рублей за 1 день\n\n\
	"cWH"Вы можете оплатить максимум на "cBLUE"%d"cWH" дней\n\n\
	"cWH"Насколько Вы хотите оплатить?", filling[f][filling_takings], max_day);

	return SPD(playerid, DIALOG_PAYMENT_FILLING, DIALOG_STYLE_INPUT, !""cBLUE"Оплата АЗС", String512, !"Далее", !"Назад");
}


stock payment_tax_hotel(playerid)
{
	if(pData[playerid][pHotelOwner] == -1)
	{
		show_bank_pay_property(playerid);
		return SendErr(playerid, "Вы не владете отелем!");				
	}

	new 
		f = pData[playerid][pHotelOwner];

	new 
		max_day = 30-hotel[f][hotel_days];

	format(String512, sizeof(String512), "\
	"cWH"Текущая стоимость: "cGR"%d"cWH" рублей за 1 день\n\n\
	"cWH"Вы можете оплатить максимум на "cBLUE"%d"cWH" дней\n\n\
	"cWH"Насколько Вы хотите оплатить?", hotel[f][hotel_takings], max_day);

	return SPD(playerid, DIALOG_PAYMENT_HOTEL, DIALOG_STYLE_INPUT, !""cBLUE"Оплата отеля", String512, !"Далее", !"Назад");
}


stock payment_tax_garage(playerid)
{

	if(pData[playerid][pGarage] == -1)
	{
		show_bank_pay_property(playerid);
		return SendErr(playerid, "Вы не владете гаражом!");				
	}

	new 
		f = pData[playerid][pGarage];

	new 
		max_day = 30-garage[f][garage_days];

	format(String512, sizeof(String512), "\
	"cWH"Текущая стоимость: "cGR"%d"cWH" рублей за 1 день\n\n\
	"cWH"Вы можете оплатить максимум на "cBLUE"%d"cWH" дней\n\n\
	"cWH"Насколько Вы хотите оплатить?", garage[f][garage_takings], max_day);

	return SPD(playerid, DIALOG_PAYMENT_GARAGE, DIALOG_STYLE_INPUT, !""cBLUE"Оплата гаража", String512, !"Далее", !"Назад");
}


stock payment_tax_sto(playerid)
{
	if(pData[playerid][pMechOwnerID] == -1)
	{
		show_bank_pay_property(playerid);
		return SendErr(playerid, "Вы не владете СТО!");				
	}

	new 
		f = pData[playerid][pMechOwnerID];

	new 
		max_day = 30-mechanic[f][mechanic_base_days];

	format(String512, sizeof(String512), "\
	"cWH"Текущая стоимость: "cGR"%d"cWH" рублей за 1 день\n\n\
	"cWH"Вы можете оплатить максимум на "cBLUE"%d"cWH" дней\n\n\
	"cWH"Насколько Вы хотите оплатить?", 1500, max_day);

	return SPD(playerid, DIALOG_PAYMENT_STO, DIALOG_STYLE_INPUT, !""cBLUE"Оплата СТО", String512, !"Далее", !"Назад");
}


stock payment_tax_tk(playerid)
{
	if(pData[playerid][pTruckerOwnerID] == -1)
	{
		show_bank_pay_property(playerid);
		return SendErr(playerid, "Вы не владете Транспортной Компанией!");				
	}

	new 
		f = pData[playerid][pTruckerOwnerID];

	new 
		max_day = 30-trucker_station[f][trucker_base_days];

	format(String512, sizeof(String512), "\
	"cWH"Текущая стоимость: "cGR"%d"cWH" рублей за 1 день\n\n\
	"cWH"Вы можете оплатить максимум на "cBLUE"%d"cWH" дней\n\n\
	"cWH"Насколько Вы хотите оплатить?", 1500, max_day);

	return SPD(playerid, DIALOG_PAYMENT_TRUCKER, DIALOG_STYLE_INPUT, !""cBLUE"Оплата ТК", String512, !"Далее", !"Назад");
}


stock payment_tax_taxi(playerid)
{
	if(pData[playerid][pTaxiOwnerID] == -1)
	{
		show_bank_pay_property(playerid);
		return SendErr(playerid, "Вы не владете Таксопарком!");				
	}

	new 
		f = pData[playerid][pTaxiOwnerID];

	new 
		max_day = 30-taxi_company[f][taxi_company_days];

	format(String512, sizeof(String512), "\
	"cWH"Текущая стоимость: "cGR"%d"cWH" рублей за 1 день\n\n\
	"cWH"Вы можете оплатить максимум на "cBLUE"%d"cWH" дней\n\n\
	"cWH"Насколько Вы хотите оплатить?", 1500, max_day);

	return SPD(playerid, DIALOG_PAYMENT_TAXI, DIALOG_STYLE_INPUT, !""cBLUE"Оплата такси", String512, !"Далее", !"Назад");
}

stock payment_tax_casino(playerid)
{
	if(pData[playerid][pCasinoOwner] == -1)
	{
		show_bank_pay_property(playerid);
		return SendErr(playerid, "Вы не владете казино!");				
	}

	new 
		f = pData[playerid][pCasinoOwner];

	new 
		max_day = 30-casino[f][casino_day];

	format(String512, sizeof(String512), "\
	"cWH"Текущая стоимость: "cGR"%d"cWH" рублей за 1 день\n\n\
	"cWH"Вы можете оплатить максимум на "cBLUE"%d"cWH" дней\n\n\
	"cWH"Насколько Вы хотите оплатить?", casino[f][casino_takings], max_day);

	return SPD(playerid, DIALOG_PAYMENT_CASINO, DIALOG_STYLE_INPUT, !""cBLUE"Оплата казино", String512, !"Далее", !"Назад");
}