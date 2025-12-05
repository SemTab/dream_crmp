 


stock update_phone_status_yandex(playerid, click_button)
{

	switch(click_button)
	{
		case CLICK_SELECT_TARIF_ECONOM:
		{

			PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantother:yandex_taxi_econom_select");
			PlayerTextDrawShow(playerid, phone_background_info[playerid]);	

			SetPVarIntNew(playerid, "taxi_client_tarif", TARIF_TAXI_ECONOM);
		}
		case CLICK_SELECT_TARIF_COMFORT:
		{
			PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantother:yandex_taxi_comfort_select");
			PlayerTextDrawShow(playerid, phone_background_info[playerid]);	

			SetPVarIntNew(playerid, "taxi_client_tarif", TARIF_TAXI_COMFORT);
		}
		case CLICK_SELECT_TARIF_BUISNES:
		{	
			PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantother:yandex_taxi_buisnes_select");
			PlayerTextDrawShow(playerid, phone_background_info[playerid]);	

			SetPVarIntNew(playerid, "taxi_client_tarif", TARIF_TAXI_BUISNES);
		}
		case CLICK_SELECT_TAXI_TEXT:
		{

		}
		case CLICK_SELECT_TAXI_CALL:
		{
			PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantother:yandex_taxi_wait");
			PlayerTextDrawShow(playerid, phone_background_info[playerid]);	

			if(taxi_company[TAXI_COMPANY_YANDEX][taxi_company_count_working] == 0)
			{
				PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantother:yandex_taxi_404");
				PlayerTextDrawShow(playerid, phone_background_info[playerid]);	

				SetPVarIntNew(playerid, "no_active_phone_screen", 1);

				return SendInf(playerid, "Нет свободных водителей!");				
			}

			SetPVarIntNew(playerid, "no_active_phone_screen", 1);

			SendSucc(playerid, "Такси вызвано, ожидайте!");

			SetPVarIntNew(playerid, "active_call_taxi", 1);

			call_driver_yandex_taxi(playerid);

			taxi_client_timer[playerid] = 300;

		}
		case CLICK_SELECT_TAXI_WAIT:
		{
			//PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantother:yandex_taxi_accept");
			//PlayerTextDrawShow(playerid, phone_background_info[playerid]);	

			new 
				taxi_driver_id = GetPVarIntNew(playerid, "wait_taxi_driver");

			new 
				vehicle_id = GetPlayerVehicleID(taxi_driver_id);

			SetPVarIntNew(playerid, "no_active_phone_screen", 1);

			format(String256, sizeof(String256), "\
				"cWH"Ваш заказ принят!\n\n\
				Водитель: "cYELLOW"%s[%d]"cWH"\n\
				Автомобиль: "cYELLOW"%s"cWH"\n\n\
				Если такси не приедет в течении 5 минут\n\
				заказ будет автоматически отменен!", pData[taxi_driver_id][pNickname], taxi_driver_id, transport_config[GetVehicleModel(vehicle_id)-400][transport_name]);
			SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cYELLOW"Заказ принят", String256, !"Понял", !"");

			SendSucc(playerid, "Водитель принял Ваш заказ! Оставайтесь на месте!");
		}
	}


	return true;
}

stock update_phone_status_uber(playerid, click_button)
{

	switch(click_button)
	{
		case CLICK_SELECT_TARIF_ECONOM:
		{

			PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantother:uber_select_econom");
			PlayerTextDrawShow(playerid, phone_background_info[playerid]);	

			SetPVarIntNew(playerid, "taxi_client_tarif", TARIF_TAXI_ECONOM);
		}
		case CLICK_SELECT_TARIF_COMFORT:
		{
			PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantother:uber_select_comfort");
			PlayerTextDrawShow(playerid, phone_background_info[playerid]);	

			SetPVarIntNew(playerid, "taxi_client_tarif", TARIF_TAXI_COMFORT);
		}
		case CLICK_SELECT_TARIF_BUISNES:
		{	
			PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantother:uber_select_buisness");
			PlayerTextDrawShow(playerid, phone_background_info[playerid]);	

			SetPVarIntNew(playerid, "taxi_client_tarif", TARIF_TAXI_BUISNES);
		}
		case CLICK_SELECT_TAXI_TEXT:
		{

		}
		case CLICK_SELECT_TAXI_CALL:
		{
			PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantother:uber_taxi_wait");
			PlayerTextDrawShow(playerid, phone_background_info[playerid]);	

			if(taxi_company[TAXI_COMPANY_UBER][taxi_company_count_working] == 0)
			{
				PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantother:uber_taxi_404");
				PlayerTextDrawShow(playerid, phone_background_info[playerid]);	

				SetPVarIntNew(playerid, "no_active_phone_screen", 1);

				return SendInf(playerid, "Нет свободных водителей!");			
			}

			SetPVarIntNew(playerid, "no_active_phone_screen", 1);

			SendSucc(playerid, "Такси вызвано, ожидайте!");

			SetPVarIntNew(playerid, "active_call_taxi", 1);

			call_driver_uber_taxi(playerid);

			taxi_client_timer[playerid] = 300;

		}
		case CLICK_SELECT_TAXI_WAIT:
		{
			//PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantother:uber_taxi_accept");
			//PlayerTextDrawShow(playerid, phone_background_info[playerid]);	

			SetPVarIntNew(playerid, "no_active_phone_screen", 1);

			new 
				taxi_driver_id = GetPVarIntNew(playerid, "wait_taxi_driver");

			new 
				vehicle_id = GetPlayerVehicleID(taxi_driver_id);

			format(String256, sizeof(String256), "\
				"cWH"Ваш заказ принят!\n\n\
				Водитель: "cUBER"%s[%d]"cWH"\n\
				Автомобиль: "cUBER"%s"cWH"\n\n\
				Если такси не приедет в течении 5 минут\n\
				заказ будет автоматически отменен!", pData[taxi_driver_id][pNickname], taxi_driver_id, transport_config[GetVehicleModel(vehicle_id)-400][transport_name]);
			SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cUBER"Заказ принят", String256, !"Понял", !"");

			SendSucc(playerid, "Водитель принял Ваш заказ! Оставайтесь на месте!");
		}
	}


	return true;
}

stock update_phone_status_city(playerid, click_button)
{

	switch(click_button)
	{
		case CLICK_SELECT_TARIF_ECONOM:
		{

			PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantother:siti_taxi_econom_select");
			PlayerTextDrawShow(playerid, phone_background_info[playerid]);	

			SetPVarIntNew(playerid, "taxi_client_tarif", TARIF_TAXI_ECONOM);
		}
		case CLICK_SELECT_TARIF_COMFORT:
		{
			PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantother:siti_taxi_comfort_select");
			PlayerTextDrawShow(playerid, phone_background_info[playerid]);	

			SetPVarIntNew(playerid, "taxi_client_tarif", TARIF_TAXI_COMFORT);
		}
		case CLICK_SELECT_TARIF_BUISNES:
		{	
			PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantother:siti_taxi_buisness_select");
			PlayerTextDrawShow(playerid, phone_background_info[playerid]);	

			SetPVarIntNew(playerid, "taxi_client_tarif", TARIF_TAXI_BUISNES);
		}
		case CLICK_SELECT_TAXI_TEXT:
		{

		}
		case CLICK_SELECT_TAXI_CALL:
		{
			PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantother:siti_taxi_wait");
			PlayerTextDrawShow(playerid, phone_background_info[playerid]);	

			if(taxi_company[TAXI_COMPANY_CITY][taxi_company_count_working] == 0)
			{
				PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantother:city_taxi_404");
				PlayerTextDrawShow(playerid, phone_background_info[playerid]);	

				return SendInf(playerid, "Нет свободных водителей!");						
			}

			SendSucc(playerid, "Такси вызвано, ожидайте!");

			SetPVarIntNew(playerid, "active_call_taxi", 1);

			call_driver_city_taxi(playerid);

			taxi_client_timer[playerid] = 300;

		}
		case CLICK_SELECT_TAXI_WAIT:
		{
			//PlayerTextDrawSetString(playerid, phone_background_info[playerid], "brilliantother:siti_taxi_accept");
			//PlayerTextDrawShow(playerid, phone_background_info[playerid]);	

			new 
				taxi_driver_id = GetPVarIntNew(playerid, "wait_taxi_driver");

			new 
				vehicle_id = GetPlayerVehicleID(taxi_driver_id);

			format(String256, sizeof(String256), "\
				"cWH"Ваш заказ принят!\n\n\
				Водитель: "cORANGE"%s[%d]"cWH"\n\
				Автомобиль: "cORANGE"%s"cWH"\n\n\
				Если такси не приедет в течении 5 минут\n\
				заказ будет автоматически отменен!", pData[taxi_driver_id][pNickname], taxi_driver_id, transport_config[GetVehicleModel(vehicle_id)-400][transport_name]);
			SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cORANGE"Заказ принят", String256, !"Понял", !"");

			SendSucc(playerid, "Водитель принял Ваш заказ! Оставайтесь на месте!");
		}
	}


	return true;
}

stock call_driver_yandex_taxi(playerid)
{
	new 
		tarif_id_client = GetPVarIntNew(playerid, "taxi_client_tarif");
		
	new	query[68+(-2+MAX_PLAYER_NAME)+(-2+16)+(-2+16)];
		
	foreach(new i : Player)
	{
		if(pData[i][pTaxi] == TAXI_COMPANY_YANDEX)
		{
			format(query, sizeof(query), "[Вызов TAXI YANDEX]"cWH" Клиент: %s[%d]. Принять вызов: /gotaxi %d", pData[playerid][pNickname], playerid, playerid);
			SCM(i, COLOR_YELLOW, query);
		}
	}

	return true;
}

stock call_driver_uber_taxi(playerid)
{
	new 
		tarif_id_client = GetPVarIntNew(playerid, "taxi_client_tarif");
		
	new	query[66+(-2+MAX_PLAYER_NAME)+(-2+16)+(-2+16)];
		
	foreach(new i : Player)
	{
		if(pData[i][pTaxi] == TAXI_COMPANY_UBER)
		{
			format(query, sizeof(query), "[Вызов TAXI UBER]"cWH" Клиент: %s[%d]. Принять вызов: /gotaxi %d", pData[playerid][pNickname], playerid, playerid);
			SCM(i, COLOR_YELLOW, query);
		}
	}

	return true;
}

stock call_driver_city_taxi(playerid)
{
	new 
		tarif_id_client = GetPVarIntNew(playerid, "taxi_client_tarif");
		
	new	query[66+(-2+MAX_PLAYER_NAME)+(-2+16)+(-2+16)];
		
	foreach(new i:Player)
	{
		//GetPVarIntNew(i, "taxi_work_tarif") == tarif_id_client && 
		if(pData[i][pTaxi] == TAXI_COMPANY_CITY)
		{
			format(query, sizeof(query), "[Вызов TAXI CITY]"cWH" Клиент: %s[%d]. Принять вызов: /gotaxi %d", pData[playerid][pNickname], playerid, playerid);
			SCM(i, COLOR_YELLOW, query);
		}
	}

	return true;
}

CMD:gotaxi(playerid, params[])
{

	if(GetPVarIntNew(playerid, "active_player_gruz_taxi") == 1)
		return SendErr(playerid, "Невозможно использовать во время работы!");

	if(GetPVarIntNew(playerid, "active_player_gruz_taxi_p") == 1)
		return SendErr(playerid, "Невозможно использовать во время работы!");

	if(sscanf(params, "d", params[0])) 
		return SendInf(playerid, "/gotaxi [ID игрока]");

	if(params[0] == playerid) 
		return SendErr(playerid, "Невозможно принимать вызов на себя!");

	if(!GetPVarIntNew(params[0], "active_call_taxi"))
		return SendErr(playerid, "Данный игрок не вызывал такси!");

	DeletePVarNew(params[0], "active_call_taxi");

	SetPVarIntNew(params[0], "wait_taxi_driver", playerid);
	SetPVarIntNew(playerid, "call_taxi_driver", params[0]);

	new 
		Float:x, Float:y, Float:z;

	GetPlayerPos(params[0], x, y, z);

	SetPlayerCheckpoint(playerid,x,y,z,4.0);
	pTemp[playerid][pGPS] = true;
	status_navigator_player(playerid, TEXTDRAW_SHOW);

	SendSucc(playerid, "Вызов успешно принят! Клиент отмечен в навигаторе!");
	SendInf(playerid, "У вас есть 5 минут, чтобы забрать клиента или заказ будет отменен!");

	taxi_client_timer[playerid] = 300;

	if(GetPVarIntNew(params[0], "taxi_select_phone") == TAXI_COMPANY_YANDEX)
		return update_phone_status_yandex(params[0], CLICK_SELECT_TAXI_WAIT);

	if(GetPVarIntNew(params[0], "taxi_select_phone") == TAXI_COMPANY_UBER)
		return update_phone_status_uber(params[0], CLICK_SELECT_TAXI_WAIT);

	if(GetPVarIntNew(params[0], "taxi_select_phone") == TAXI_COMPANY_CITY)
		return update_phone_status_city(params[0], CLICK_SELECT_TAXI_WAIT);

	return true;
}


stock taxi_cancel_call(playerid)
{
	new 
		taxi_driver_id = GetPVarIntNew(playerid, "wait_taxi_driver");


	if(taxi_driver_id != INVALID_PLAYER_ID)
	{
		SendInf(playerid, "Вызов такси был отменен! Попробуйте вызвать другое!");
		taxi_client_timer[playerid] = 0;

		SetPVarIntNew(playerid, "call_taxi_driver", INVALID_PLAYER_ID);
		DeletePVarNew(playerid, "taxi_select_phone");
		DeletePVarNew(playerid, "taxi_driver_id");

		if(GetPVarIntNew(playerid, "phone_td_status") == 1)
		{
			hide_phone_general(playerid);
			CancelSelectTextDraw(playerid);
		}


		pTemp[taxi_driver_id][pTaxiPass] = INVALID_PLAYER_ID;
		pTemp[taxi_driver_id][pTaxiStart] = 0.0;
		pTemp[taxi_driver_id][pTaxiGoing] = false;

		SetPVarIntNew(taxi_driver_id, "wait_taxi_driver", INVALID_PLAYER_ID);
		DisablePlayerCheckpoint(taxi_driver_id);
		SendInf(taxi_driver_id, "Вы не успели добраться до клиента и вызов был отменен!");	
	}

	return true;
}

stock taxi_driver_cancel_call(playerid)
{

	new 
		client_id = GetPVarIntNew(playerid, "call_taxi_driver");

	if(client_id != INVALID_PLAYER_ID)
	{
		SetPVarIntNew(playerid, "wait_taxi_driver", INVALID_PLAYER_ID);
		DeletePVarNew(playerid, "taxi_driver_id");
		DisablePlayerCheckpoint(playerid);	

		pTemp[playerid][pTaxiPass] = INVALID_PLAYER_ID;
		pTemp[playerid][pTaxiStart] = 0.0;
		pTemp[playerid][pTaxiGoing] = false;


		SendInf(client_id, "Вызов такси был отменен! Попробуйте вызвать другое!");
		taxi_client_timer[client_id] = 0;

		SetPVarIntNew(client_id, "call_taxi_driver", INVALID_PLAYER_ID);
		DeletePVarNew(client_id, "taxi_select_phone");

		if(GetPVarIntNew(client_id, "phone_td_status") == 1)
		{
			hide_phone_general(client_id);
			CancelSelectTextDraw(client_id);
		}
	}

	return true;
}

stock taxi_cancel_call_client(playerid)
{

	new 
		taxi_driver_id = GetPVarIntNew(playerid, "call_taxi_driver");

	if(taxi_driver_id != INVALID_PLAYER_ID)
	{
		taxi_client_timer[playerid] = 0;

		SetPVarIntNew(playerid, "call_taxi_driver", INVALID_PLAYER_ID);
		DeletePVarNew(playerid, "taxi_select_phone");
		DeletePVarNew(playerid, "taxi_driver_id");

		if(GetPVarIntNew(playerid, "phone_td_status") == 1)
		{
			hide_phone_general(playerid);
			CancelSelectTextDraw(playerid);
		}

		pTemp[taxi_driver_id][pTaxiPass] = INVALID_PLAYER_ID;
		pTemp[taxi_driver_id][pTaxiStart] = 0.0;
		pTemp[taxi_driver_id][pTaxiGoing] = false;

		SetPVarIntNew(taxi_driver_id, "wait_taxi_driver", INVALID_PLAYER_ID);
		DisablePlayerCheckpoint(taxi_driver_id);
		SendInf(taxi_driver_id, "Клиент не в зоне доступа! Заказ отменен!");	
	}

	return true;	
}

stock taxi_cancel_drive(taxi_driver_id, pass_id_client)
{



	SetPVarIntNew(pass_id_client, "call_taxi_driver", INVALID_PLAYER_ID);
	DeletePVarNew(pass_id_client, "taxi_select_phone");
	DeletePVarNew(pass_id_client, "taxi_driver_id");


	pTemp[taxi_driver_id][pTaxiPass] = INVALID_PLAYER_ID;
	pTemp[taxi_driver_id][pTaxiStart] = 0.0;
	pTemp[taxi_driver_id][pTaxiGoing] = false;


	SetPVarIntNew(taxi_driver_id, "wait_taxi_driver", INVALID_PLAYER_ID);
	DisablePlayerCheckpoint(taxi_driver_id);	
	return true;
}

stock taxi_clear_data(playerid)
{
	DeletePVarNew(playerid, "call_taxi_driver");
	DeletePVarNew(playerid, "taxi_select_phone");
	DeletePVarNew(playerid, "taxi_driver_id");


	pTemp[playerid][pTaxiPass] = INVALID_PLAYER_ID;
	pTemp[playerid][pTaxiStart] = 0.0;
	pTemp[playerid][pTaxiGoing] = false;

	SetPVarIntNew(playerid, "wait_taxi_driver", INVALID_PLAYER_ID);
	SetPVarIntNew(playerid, "call_taxi_driver", INVALID_PLAYER_ID);

	DisablePlayerCheckpoint(playerid);	

	return true;	
}