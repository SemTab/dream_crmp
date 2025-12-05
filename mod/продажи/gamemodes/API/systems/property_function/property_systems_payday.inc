callback:: check_payday_all_property()
{
	for(new iis_payday, idx = all_garage; iis_payday < idx; iis_payday ++) 
	{
		if(garage[iis_payday][garage_days] > 0 && garage[iis_payday][garage_owner_id] != -1)
		{
			garage[iis_payday][garage_days] -= 1;

			format(String256, sizeof(String256), "Обновление гаражей по дням | Номер: %d | Количество дней: %d", iis_payday, garage[iis_payday][garage_days]);
			logs_payday_property(garage[iis_payday][garage_owner_id], String256);
			save_garage(iis_payday);

		}
		else if(garage[iis_payday][garage_days] == 0 && garage[iis_payday][garage_owner_id] != -1)
		{
			sell_garage_payday(iis_payday);
			format(String256, sizeof(String256), "Продажа гаража в PayDay | Номер: %d | Количество дней: %d", iis_payday, garage[iis_payday][garage_days]);
			logs_payday_property_sell(garage[iis_payday][garage_owner_id], String256);
			save_garage(iis_payday);

		}
		
	}



	for(new iis_payday, idx = all_buisness; iis_payday < idx; iis_payday ++) 
	{
		if(buisness[iis_payday][buisnes_days] > 0 && buisness[iis_payday][buisnes_owned] != -1)
		{
			buisness[iis_payday][buisnes_days] -= 1;
			format(String256, sizeof(String256), "Обновление бизнесов по дням | Номер: %d | Количество дней: %d", iis_payday, buisness[iis_payday][buisnes_days]);
			logs_payday_property(buisness[iis_payday][buisnes_owned], String256);
			save_biz(iis_payday);
		}
		else if(buisness[iis_payday][buisnes_days] == 0 && buisness[iis_payday][buisnes_owned] != -1)
		{
			sell_buisness_payday(iis_payday);
			format(String256, sizeof(String256), "Продажа гаража в PayDay | Номер: %d | Количество дней: %d", iis_payday, buisness[iis_payday][buisnes_days]);
			logs_payday_property_sell(buisness[iis_payday][buisnes_owned], String256);			
			save_biz(iis_payday);
			
		}
		
	}


	for(new iis_payday, idx = MAX_MECHANIC_BASE; iis_payday < idx; iis_payday ++) 
	{
		if(mechanic[iis_payday][mechanic_base_days] > 0 && mechanic[iis_payday][mechanic_base_owner_id] != -1)
		{
			mechanic[iis_payday][mechanic_base_days] -= 1;
			format(String256, sizeof(String256), "Обновление СТО по дням | Номер: %d | Количество дней: %d", iis_payday, mechanic[iis_payday][mechanic_base_days]);
			logs_payday_property(mechanic[iis_payday][mechanic_base_owner_id], String256);
			save_mechanic_base();

		}
		if(mechanic[iis_payday][mechanic_base_days] == 0 && mechanic[iis_payday][mechanic_base_owner_id] != -1)
		{
			sell_mechanic_payday(iis_payday);
			format(String256, sizeof(String256), "Продажа СТО на слёт | Номер: %d | Количество дней: %d", iis_payday, mechanic[iis_payday][mechanic_base_days]);
			logs_payday_property_sell(mechanic[iis_payday][mechanic_base_owner_id], String256);
			save_mechanic_base();
		}

	}



	for(new iis_payday, idx = all_casino; iis_payday < idx; iis_payday ++) 
	{
		if(casino[iis_payday][casino_day] > 0 && casino[iis_payday][casino_owner_id] != -1)
		{
			casino[iis_payday][casino_day] -= 1;
			format(String256, sizeof(String256), "Обновление казино по дням | Номер: %d | Количество дней: %d", iis_payday, casino[iis_payday][casino_day]);
			logs_payday_property(casino[iis_payday][casino_owner_id], String256);
			save_casino(iis_payday);
		}
		else if(casino[iis_payday][casino_day] == 0 && casino[iis_payday][casino_owner_id] != -1)
		{
			sell_casino_payday(iis_payday);
			format(String256, sizeof(String256), "Продажа казино на слёт | Номер: %d | Количество дней: %d", iis_payday, casino[iis_payday][casino_day]);
			logs_payday_property_sell(casino[iis_payday][casino_owner_id], String256);
			save_casino(iis_payday);
		}
	
	}




	for(new iis_payday, idx = all_hotels; iis_payday < idx; iis_payday ++) 
	{
		if(hotel[iis_payday][hotel_days] > 0 && hotel[iis_payday][hotel_owned] != -1)
		{
			hotel[iis_payday][hotel_days] -= 1;
			format(String256, sizeof(String256), "Обновление отеля по дням | Номер: %d | Количество дней: %d", iis_payday, hotel[iis_payday][hotel_days]);
			logs_payday_property(hotel[iis_payday][hotel_owned], String256);
			save_hotel(iis_payday);
		}
		else if(hotel[iis_payday][hotel_days] == 0 && hotel[iis_payday][hotel_owned] != -1)
		{
			sell_hotel_payday(iis_payday);
			format(String256, sizeof(String256), "Продажа казино на слёт | Номер: %d | Количество дней: %d", iis_payday, hotel[iis_payday][hotel_days]);
			logs_payday_property_sell(hotel[iis_payday][hotel_owned], String256);

			save_hotel(iis_payday);
		}
		
	}



	for(new iis_payday, idx = all_filling; iis_payday < idx; iis_payday ++) 
	{
		if(filling[iis_payday][filling_day] > 0 && filling[iis_payday][filling_owner_id] != -1)
		{
			filling[iis_payday][filling_day] -= 1;
			format(String256, sizeof(String256), "Обновление АЗС по дням | Номер: %d | Количество дней: %d", iis_payday, filling[iis_payday][filling_day]);
			logs_payday_property(filling[iis_payday][filling_owner_id], String256);
			save_fill(iis_payday);

		}
		else if(filling[iis_payday][filling_day] == 0 && filling[iis_payday][filling_owner_id] != -1)
		{
			sell_filling_payday(iis_payday);
			format(String256, sizeof(String256), "Продажа АЗС на слёт | Номер: %d | Количество дней: %d", iis_payday, filling[iis_payday][filling_day]);
			logs_payday_property_sell(filling[iis_payday][filling_owner_id], String256);
			save_fill(iis_payday);

		}
	}



	for(new iii_payday, idx = all_hotel_room; iii_payday < idx; iii_payday ++) 
	{
		if(hotel_room[iii_payday][hotel_room_day] > 0 && hotel_room[iii_payday][hotel_room_owned] != -1)
		{
			hotel_room[iii_payday][hotel_room_day] -= 1;
			save_hotel_room(iii_payday);

		}
		if(hotel_room[iii_payday][hotel_room_day] == 0 && hotel_room[iii_payday][hotel_room_owned] != -1)
		{
			hotel_unrent_room(iii_payday);

			save_hotel_room(iii_payday);		

		}	
		
	}


	for(new i_payday, idx = all_houses; i_payday < idx; i_payday ++) 
	{
		if(House[i_payday][house_days] > 0 && House[i_payday][house_owned] != -1)
		{
			House[i_payday][house_days] -= 1;
			format(String256, sizeof(String256), "Обновление дома по дням | Номер: %d | Количество дней: %d", i_payday, House[i_payday][house_days]);
			logs_payday_property(House[i_payday][house_owned], String256);
		
		}
		if(House[i_payday][house_days] == 0 && House[i_payday][house_owned] != -1)
		{
			house_sell_payday(i_payday);
			format(String256, sizeof(String256), "Продажа Дома на слёт | Номер: %d | Количество дней: %d", i_payday, House[i_payday][house_days]);
			logs_payday_property_sell(House[i_payday][house_owned], String256);		
		}

		if(House[i_payday][house_people_1_day] > 0 && House[i_payday][house_people_1_id] != -1)
		{
			House[i_payday][house_people_1_day] -= 1;
		}
		if(House[i_payday][house_people_2_day] > 0 && House[i_payday][house_people_2_id] != -1)
		{
			House[i_payday][house_people_2_day] -= 1;
		}
		if(House[i_payday][house_people_3_day] > 0 && House[i_payday][house_people_3_id] != -1)
		{
			House[i_payday][house_people_3_day] -= 1;
		}	
		if(House[i_payday][house_people_4_day] > 0 && House[i_payday][house_people_4_id] != -1)
		{
			House[i_payday][house_people_4_day] -= 1;
		}


		if(House[i_payday][house_people_1_day] == 0 && House[i_payday][house_people_1_id] != -1)
		{
			House[i_payday][house_people_1_day] = 3;
			House[i_payday][house_people_1_id] = -1;
			unrent_house_payday_1(i_payday);
		}
		if(House[i_payday][house_people_2_day] == 0 && House[i_payday][house_people_2_id] != -1)
		{
			House[i_payday][house_people_2_day] = 3;
			House[i_payday][house_people_2_id] = -1;
			unrent_house_payday_2(i_payday);
		}
		if(House[i_payday][house_people_3_day] == 0 && House[i_payday][house_people_3_id] != -1)
		{
			House[i_payday][house_people_3_day] = 3;
			House[i_payday][house_people_3_id] = -1;
			unrent_house_payday_3(i_payday);
		}	
		if(House[i_payday][house_people_4_day] == 0 && House[i_payday][house_people_4_id] != -1)
		{
			House[i_payday][house_people_4_day] = 3;
			House[i_payday][house_people_4_id] = -1;
			unrent_house_payday_4(i_payday);
		}
		save_house(i_payday);

	}


	for(new ii_payday, idx = all_flates; ii_payday < idx; ii_payday ++) 
	{
		if(flate[ii_payday][flate_days] > 0 && flate[ii_payday][flate_owned] != -1)
		{
			flate[ii_payday][flate_days] -= 1;
			format(String256, sizeof(String256), "Обновление квартиры по дням | Номер: %d | Количество дней: %d", ii_payday, flate[ii_payday][flate_days]);
			logs_payday_property(flate[ii_payday][flate_owned], String256);
		}

		if(flate[ii_payday][flate_days] == 0 && flate[ii_payday][flate_owned] != -1)
		{
			flate_sell_payday(ii_payday);
			format(String256, sizeof(String256), "Продажа квартиры на слёт | Номер: %d | Количество дней: %d", ii_payday, flate[ii_payday][flate_days]);
			logs_payday_property_sell(flate[ii_payday][flate_owned], String256);
		}

		if(flate[ii_payday][flate_people_1_day] > 0 && flate[ii_payday][flate_people_1_id] != -1)
		{
			flate[ii_payday][flate_people_1_day] -= 1;
		}
		if(flate[ii_payday][flate_people_2_day] > 0 && flate[ii_payday][flate_people_2_id] != -1)
		{
			flate[ii_payday][flate_people_2_day] -= 1;
		}
		if(flate[ii_payday][flate_people_3_day] > 0 && flate[ii_payday][flate_people_3_id] != -1)
		{
			flate[ii_payday][flate_people_3_day] -= 1;
		}	
		if(flate[ii_payday][flate_people_4_day] > 0 && flate[ii_payday][flate_people_4_id] != -1)
		{
			flate[ii_payday][flate_people_4_day] -= 1;
		}


		if(flate[ii_payday][flate_people_1_day] == 0 && flate[ii_payday][flate_people_1_id] != -1)
		{
			flate[ii_payday][flate_people_1_day] = 3;
			flate[ii_payday][flate_people_1_id] = -1;
			unrent_flate_payday_1(ii_payday);
		}
		if(flate[ii_payday][flate_people_2_day] == 0 && flate[ii_payday][flate_people_2_id] != -1)
		{
			flate[ii_payday][flate_people_2_day] = 3;
			flate[ii_payday][flate_people_2_id] = -1;
			unrent_flate_payday_2(ii_payday);
		}
		if(flate[ii_payday][flate_people_3_day] == 0 && flate[ii_payday][flate_people_3_id] != -1)
		{
			flate[ii_payday][flate_people_3_day] = 3;
			flate[ii_payday][flate_people_3_id] = -1;
			unrent_flate_payday_3(ii_payday); 
		}	
		if(flate[ii_payday][flate_people_4_day] == 0 && flate[ii_payday][flate_people_4_id] != -1)
		{
			flate[ii_payday][flate_people_4_day] = 3;
			flate[ii_payday][flate_people_4_id] = -1;
			unrent_flate_payday_4(ii_payday);

		}
		save_flate(ii_payday);	
 	}

	for(new iis_payday, idx = MAX_TAXI_COMPANY; iis_payday < idx; iis_payday ++) 
	{
		if(taxi_company[iis_payday][taxi_company_days] > 0 && taxi_company[iis_payday][taxi_company_owner_id] != -1)
		{
			taxi_company[iis_payday][taxi_company_days] -= 1;
			format(String256, sizeof(String256), "Обновление такси по дням | Номер: %d | Количество дней: %d", iis_payday, taxi_company[iis_payday][taxi_company_days]);
			logs_payday_property(taxi_company[iis_payday][taxi_company_owner_id], String256);

		}
		if(taxi_company[iis_payday][taxi_company_days] == 0 && taxi_company[iis_payday][taxi_company_owner_id] != -1)
		{
			sell_taxi_payday(iis_payday);
			format(String256, sizeof(String256), "Продажа такси на слёт | Номер: %d | Количество дней: %d", iis_payday, taxi_company[iis_payday][taxi_company_days]);
			logs_payday_property_sell(taxi_company[iis_payday][taxi_company_owner_id], String256);			
		}
		save_taxi_base();
	}

	for(new iis_payday, idx = MAX_TRUCKER_BASE; iis_payday < idx; iis_payday ++) 
	{
		if(trucker_station[iis_payday][trucker_base_days] > 0 && trucker_station[iis_payday][trucker_base_owner_id] != -1)
		{
			trucker_station[iis_payday][trucker_base_days] -= 1;
			format(String256, sizeof(String256), "Обновление ТК по дням | Номер: %d | Количество дней: %d", iis_payday, trucker_station[iis_payday][trucker_base_days]);
			logs_payday_property(trucker_station[iis_payday][trucker_base_owner_id], String256);
		}
		if(trucker_station[iis_payday][trucker_base_days] == 0 && trucker_station[iis_payday][trucker_base_owner_id] != -1)
		{
			sell_trucker_payday(iis_payday);
			format(String256, sizeof(String256), "Продажа ТК на слёт | Номер: %d | Количество дней: %d", iis_payday, trucker_station[iis_payday][trucker_base_days]);
			logs_payday_property_sell(trucker_station[iis_payday][trucker_base_owner_id], String256);	
		}
		save_trucker_base();
	}

	
	return true;
}

stock update_finka_all_property()
{


    sql_queryEx(zConn, "UPDATE `filling_station` SET `fillings_finka_day` = '0'", QUERY_THREADED);
    sql_queryEx(zConn, "UPDATE `hotel` SET `hotel_finka_day` = '0'", QUERY_THREADED);
    sql_queryEx(zConn, "UPDATE `mechanic` SET `mechanic_base_finka_day` = '0'", QUERY_THREADED);
    sql_queryEx(zConn, "UPDATE `casino` SET `casino_finka_day` = '0'", QUERY_THREADED);
    
    sql_queryEx(zConn, "UPDATE `buisnes` SET `buisnes_finka_day` = '0'", QUERY_THREADED);
    sql_queryEx(zConn, "UPDATE `taxi` SET `taxi_finka_ogran` = '0'", QUERY_THREADED);
    sql_queryEx(zConn, "UPDATE `trucker` SET `trucker_base_finka_day` = '0'", QUERY_THREADED);

    sql_queryEx(zConn, "UPDATE `trucker_personal` SET `user_money_day` = '0'", QUERY_THREADED);
    sql_queryEx(zConn, "UPDATE `mechanic_personal` SET `user_money_day` = '0'", QUERY_THREADED);

	for(new iis_payday, idx = all_buisness; iis_payday < idx; iis_payday ++) 
	{
    	buisness[iis_payday][buisnes_finka_day] = 0;
    }

	for(new iis_payday, idx = MAX_TRUCKER_BASE; iis_payday < idx; iis_payday ++) 
	{ 
		trucker_station[iis_payday][trucker_base_finka_day] = 0;

	}

	for(new iis_payday, idx = all_filling; iis_payday < idx; iis_payday ++) 
	{
		filling[iis_payday][fillings_finka_day] = 0;
	}


	casino[0][casino_finka_day] = 0;

	return true;
}


stock update_all_property_sell()
{


	for(new iis_payday, idx = all_buisness; iis_payday < idx; iis_payday ++) 
	{
		if(buisness[iis_payday][buisnes_sell_day_payday] > 0 && buisness[iis_payday][buisnes_owned] == -1)
		{
			buisness[iis_payday][buisnes_sell_day_payday] -= 1;
		}
		if(buisness[iis_payday][buisnes_sell_day_payday] == 0 && buisness[iis_payday][buisnes_owned] == -1)
		{
			buisness[iis_payday][buisnes_status_sell] = 0;
			buisness[iis_payday][buisnes_sell_day_payday] = -1;

			format(String256, sizeof(String256), "Финальная продажа бизнеса в PayDay | Номер: %d | Количество дней: %d", iis_payday, buisness[iis_payday][buisnes_days]);
			logs_payday_property_final(buisness[iis_payday][buisnes_owned], String256);	

		}
		save_biz(iis_payday);
		update_biz_text();
	}

	for(new iis_payday, idx = all_casino; iis_payday < idx; iis_payday ++) 
	{
		if(casino[iis_payday][casino_sell_day_payday] > 0 && casino[iis_payday][casino_owner_id] == -1)
		{
			casino[iis_payday][casino_sell_day_payday] -= 1;
		}
		if(casino[iis_payday][casino_sell_day_payday] == 0 && casino[iis_payday][casino_owner_id] == -1)
		{
			casino[iis_payday][casino_sell_day_payday] = -1;
			casino[iis_payday][casino_buy_status] = 0;

			format(String256, sizeof(String256), "Финальная продажа казино в PayDay | Номер: %d | Количество дней: %d", iis_payday, buisness[iis_payday][buisnes_days]);
			logs_payday_property_final(buisness[iis_payday][buisnes_owned], String256);	

		}
		update_casino_3d_text(iis_payday);
		save_casino(iis_payday);
	}

	for(new ii_payday, idx = all_flates; ii_payday < idx; ii_payday ++) 
	{
		if(flate[ii_payday][flate_sell_count_payday] > 0 && flate[ii_payday][flate_owned] == -1)
		{
			flate[ii_payday][flate_sell_count_payday] -= 1;
		}

		if(flate[ii_payday][flate_sell_count_payday] == 0 && flate[ii_payday][flate_owned] == -1)
		{
			flate[ii_payday][flate_sell_count_payday] = -1;
			flate[ii_payday][flate_sell_status] = 0;

			format(String256, sizeof(String256), "Финальная продажа Квартиры в PayDay | Номер: %d | Количество дней: %d", ii_payday, flate[ii_payday][flate_sell_count_payday]);
			logs_payday_property_final(flate[ii_payday][flate_owned], String256);	

		}
		save_flate(ii_payday);
	}

	for(new iis_payday, idx = all_garage; iis_payday < idx; iis_payday ++) 
	{
		if(garage[iis_payday][garage_sell_count_payday] > 0 && garage[iis_payday][garage_owner_id] == -1)
		{
			garage[iis_payday][garage_sell_count_payday] -= 1;
		}
		if(garage[iis_payday][garage_sell_count_payday] == 0 && garage[iis_payday][garage_owner_id] == -1)
		{
			garage[iis_payday][garage_sell_count_payday] = -1;
			garage[iis_payday][garage_sell_status] = 0;

			format(String256, sizeof(String256), "Финальная продажа Гаража в PayDay | Номер: %d | Количество дней: %d", iis_payday, garage[iis_payday][garage_sell_count_payday]);
			logs_payday_property_final(garage[iis_payday][garage_owner_id], String256);	

		}
		update_3d_text_garage(iis_payday);
		save_garage(iis_payday);
	}

	for(new iis_payday, idx = all_hotels; iis_payday < idx; iis_payday ++) 
	{
		if(hotel[iis_payday][hotel_sell_day_payday] > 0 && hotel[iis_payday][hotel_owned] == -1)
		{
			hotel[iis_payday][hotel_sell_day_payday] -= 1;
		}
		if(hotel[iis_payday][hotel_sell_day_payday] == 0 && hotel[iis_payday][hotel_owned] == -1)
		{
			hotel[iis_payday][hotel_sell_day_payday] = -1;
			hotel[iis_payday][hotel_status_sell] = 0;

			format(String256, sizeof(String256), "Финальная продажа Квартиры в PayDay | Номер: %d | Количество дней: %d", iis_payday, hotel[iis_payday][hotel_sell_day_payday]);
			logs_payday_property_final(hotel[iis_payday][hotel_owned], String256);	

		}
		update_hotel_text_3d(iis_payday);
		save_hotel(iis_payday);
	}


	for(new i_payday, idx = all_houses; i_payday < idx; i_payday ++) 
	{
		if(House[i_payday][house_sell_count_payday] > 0 && House[i_payday][house_owned] == -1)
		{
			House[i_payday][house_sell_count_payday] -= 1;
		}
		if(House[i_payday][house_sell_count_payday] == 0 && House[i_payday][house_owned] == -1)
		{
			House[i_payday][house_sell_count_payday] = -1;
			House[i_payday][house_sell_status] = 0;

			format(String256, sizeof(String256), "Финальная продажа Дома в PayDay | Номер: %d | Количество дней: %d", i_payday, House[i_payday][house_sell_count_payday]);
			logs_payday_property_final(House[i_payday][house_owned], String256);	

		}
		save_house(i_payday);
	}


	for(new iis_payday, idx = MAX_MECHANIC_BASE; iis_payday < idx; iis_payday ++) 
	{
		if(mechanic[iis_payday][mechanic_sell_day_payday] > 0 && mechanic[iis_payday][mechanic_base_owner_id] == -1)
		{
			mechanic[iis_payday][mechanic_sell_day_payday] -= 1;
		}
		if(mechanic[iis_payday][mechanic_sell_day_payday] == 0 && mechanic[iis_payday][mechanic_base_owner_id] == -1)
		{
			mechanic[iis_payday][mechanic_sell_day_payday] = -1;
			mechanic[iis_payday][mechanic_status_sell] = 0;

			format(String256, sizeof(String256), "Финальная продажа СТО в PayDay | Номер: %d | Количество дней: %d", iis_payday, mechanic[iis_payday][mechanic_sell_day_payday]);
			logs_payday_property_final(mechanic[iis_payday][mechanic_base_owner_id], String256);	

		}
 		update_mechanic_3d_text();
		save_mechanic_base();
	}


	for(new iis_payday, idx = all_filling; iis_payday < idx; iis_payday ++) 
	{
		if(filling[iis_payday][filling_sell_day_payday] > 0 && filling[iis_payday][filling_owner_id] == -1)
		{
			filling[iis_payday][filling_sell_day_payday] -= 1;
		}
		if(filling[iis_payday][filling_sell_day_payday] == 0 && filling[iis_payday][filling_owner_id] == -1)
		{
			filling[iis_payday][filling_buy_status] = 0;
			filling[iis_payday][filling_sell_day_payday] = -1;

			format(String256, sizeof(String256), "Финальная продажа АЗС в PayDay | Номер: %d | Количество дней: %d", iis_payday, filling[iis_payday][filling_sell_day_payday]);
			logs_payday_property_final(filling[iis_payday][filling_owner_id], String256);	

		}
		save_fill(iis_payday);
	}

	for(new iis_payday, idx = MAX_TAXI_COMPANY; iis_payday < idx; iis_payday ++) 
	{
		if(taxi_company[iis_payday][taxi_sell_day_payday] > 0 && taxi_company[iis_payday][taxi_company_owner_id] == -1)
		{
			taxi_company[iis_payday][taxi_sell_day_payday] -= 1;
		}
		if(taxi_company[iis_payday][taxi_sell_day_payday] == 0 && taxi_company[iis_payday][taxi_company_owner_id] == -1)
		{
			taxi_company[iis_payday][taxi_sell_day_payday] = -1; 
			taxi_company[iis_payday][taxi_status_sell] = 0;

			format(String256, sizeof(String256), "Финальная продажа такси в PayDay | Номер: %d | Количество дней: %d", iis_payday, taxi_company[iis_payday][taxi_sell_day_payday]);
			logs_payday_property_final(taxi_company[iis_payday][taxi_company_owner_id], String256);	

		} 
 		update_taxi_3d_text();
		save_taxi_base();
	}

	for(new iis_payday, idx = MAX_TRUCKER_BASE; iis_payday < idx; iis_payday ++) 
	{
		if(trucker_station[iis_payday][trucker_sell_day_payday] > 0 && trucker_station[iis_payday][trucker_base_owner_id] == -1)
		{
			trucker_station[iis_payday][trucker_sell_day_payday] -= 1;
		}
		if(trucker_station[iis_payday][trucker_sell_day_payday] == 0 && trucker_station[iis_payday][trucker_base_owner_id] == -1)
		{
			trucker_station[iis_payday][trucker_sell_day_payday] = -1;
			trucker_station[iis_payday][trucker_status_sell] = 0;

			format(String256, sizeof(String256), "Финальная продажа ТК в PayDay | Номер: %d | Количество дней: %d", iis_payday, trucker_station[iis_payday][trucker_sell_day_payday]);
			logs_payday_property_final(trucker_station[iis_payday][trucker_base_owner_id], String256);		

		}
 		update_trucker_3d_text();
		save_trucker_base();
	}

	return true;
}