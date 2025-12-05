new selected_region[MAX_PLAYERS];
new selected_number[MAX_PLAYERS][30];
new selected_regionR[MAX_PLAYERS][30];

stock start_new_number_get(playerid)
{
    return SPD(playerid, 4495, DIALOG_STYLE_LIST, "Выберите тип номера", "1. Обычные - 5000 рублей\n2. Кастомные - 500.000 рублей\n", "Принять", "Отмена");
}

stock dialog_new_number(playerid, id, slotitem, response, inputtext[])
{
    switch(id) {
        case 4491: {
            if(pData[playerid][pMoney] < 500000)
                return SendErr(playerid, "У вас нехватает средств");
            if(pData[playerid][car_id] == INVALID_VEHICLE_ID)
                return SendErr(playerid, "У вас нету транспорта или он выгружен!");
            if(!response)
                return true;      
            return save_number(playerid, 0);
        }
        case 4492: {
            if(pData[playerid][pMoney] < 500000)
                return SendErr(playerid, "У вас нехватает средств");
            if(pData[playerid][car_id] == INVALID_VEHICLE_ID)
                return SendErr(playerid, "У вас нету транспорта или он выгружен!");
            if(!response)
                return true;
            if(!check_valid_region(playerid, inputtext)) {
                if(selected_region[playerid] == 0)
                    SPD(playerid, 4492, DIALOG_STYLE_INPUT, "Ввод региона", "Введите желаемый регион от 100 до 999", "Выбор", "Отмена");
                if(selected_region[playerid] == 3)
                    SPD(playerid, 4492, DIALOG_STYLE_INPUT, "Ввод региона", "Введите желаемый регион от 01 до 99", "Выбор", "Отмена");
                return SendErr(playerid, "Неправильный формат региона!");
            }
            new it[30];
            format(it, sizeof it, inputtext);
            selected_regionR[playerid] = it;
            new str[128];
            format(str, sizeof str, "Вы подтверждаете покупку номера - %s %s", selected_number[playerid], inputtext);
            return SPD(playerid, 4491, DIALOG_STYLE_MSGBOX, "Покупка", str, "Выбор", "Отмена");
        }
        case 4493: {
            if(pData[playerid][pMoney] < 500000)
                return SendErr(playerid, "У вас нехватает средств");
            if(pData[playerid][car_id] == INVALID_VEHICLE_ID)
                return SendErr(playerid, "У вас нету транспорта или он выгружен!");
            if(!response)
                return true;
            if(!check_valid_number(playerid, inputtext))
            {
                new str[24];
                switch(selected_region[playerid]) {
                    case 0: {
                       format(str, sizeof str, "A010AA");
                   }
                   case 1: {
                       format(str, sizeof str, "АА 1234 КК");
                   }
                   case 2: {
                       format(str, sizeof str, "1234AA-5");
                   }
                   case 3: {
                       format(str, sizeof str, "123AAA");
                   }
                }
                new str2[128];
                format(str2, sizeof str2, "Введите желаемый номер:\nПример: %s\nРазрешенные буквы - A B C E H K M O P T X(английская раскладка)", str);
                SPD(playerid, 4493, DIALOG_STYLE_INPUT, "Ввод номера", str2, "Выбор", "Отмена");
                return SendErr(playerid, "Неправильный формат номера!");
            }
            new it[30];
            format(it, sizeof it, inputtext);
            selected_number[playerid] = it;
            if(selected_region[playerid] == 0)
                return SPD(playerid, 4492, DIALOG_STYLE_INPUT, "Ввод региона", "Введите желаемый регион от 100 до 999", "Выбор", "Отмена");
            if(selected_region[playerid] == 3)
                 return SPD(playerid, 4492, DIALOG_STYLE_INPUT, "Ввод региона", "Введите желаемый регион от 01 до 99", "Выбор", "Отмена");    
           selected_regionR[playerid] = "";
           new str[128];
           format(str, sizeof str, "Вы подтверждаете покупку номера - %s", inputtext);
           return SPD(playerid, 4491, DIALOG_STYLE_MSGBOX, "Покупка", str, "Выбор", "Отмена");
        }
        case 4494: {
            if(!response)
                return true;
            if(pData[playerid][pMoney] < 500000)
                return SendErr(playerid, "У вас нехватает средств");
            if(pData[playerid][car_id] == INVALID_VEHICLE_ID)
                return SendErr(playerid, "У вас нету транспорта или он выгружен!");
            selected_region[playerid] = slotitem;
            new str[24];
            switch(slotitem) {
               case 0: {
                   format(str, sizeof str, "A010AA");
               }
               case 1: {
                   format(str, sizeof str, "АА 1234 КК");
               }
               case 2: {
                   format(str, sizeof str, "1234AA-5");
               }
               case 3: {
                   format(str, sizeof str, "123AAA");
               }
            }
            new str2[128];
            format(str2, sizeof str2, "Введите желаемый номер:\nПример: %s\nРазрешенные буквы - A B C E H K M O P T X(английская раскладка)", str);
            return SPD(playerid, 4493, DIALOG_STYLE_INPUT, "Ввод номера", str2, "Выбор", "Отмена");
        }
        case 4495: {
            if(!response)
                return true;
            switch(slotitem) {
                case 0: return SPD(playerid, 4498, DIALOG_STYLE_LIST, "Выбор региона", "1. Россия\n2. Украина\n3. Беларусь\n4. Казахстан", "Выбор", "Отмена");
                case 1: return SPD(playerid, 4494, DIALOG_STYLE_LIST, "Выбор региона", "1. Россия\n2. Украина\n3. Беларусь\n4. Казахстан", "Выбор", "Отмена");
            }     
            return true;
        }
        case 4497: {
            if(pData[playerid][pMoney] < 5000)
                return SendErr(playerid, "У вас нехватает средств");
            if(pData[playerid][car_id] == INVALID_VEHICLE_ID)
                return SendErr(playerid, "У вас нету транспорта или он выгружен!");        
             if(!response) {
                 give_money(playerid, -1500, "прокрут номера");
                 give_player_number(playerid, selected_region[playerid]);
                 return true;
             }
             
             return save_number(playerid, 1);
        }     
        case 4498: {
            if(!response)
               return true;
            if(pData[playerid][pMoney] < 5000)
                return SendErr(playerid, "У вас нехватает средств");
            if(pData[playerid][car_id] == INVALID_VEHICLE_ID)
                return SendErr(playerid, "У вас нету транспорта или он выгружен!");
                
            return give_player_number(playerid, slotitem);
        }
        case 4499: {
            if(!response)
                return true;
            if(pData[playerid][pMoney] < 5000)
                return SendErr(playerid, "У вас нехватает средств");
            if(pData[playerid][car_id] == INVALID_VEHICLE_ID)
                return SendErr(playerid, "У вас нету транспорта или он выгружен!");
            
            return SPD(playerid, 4498, DIALOG_STYLE_LIST, "Выбор региона", "1. Россия\n2. Украина\n3. Беларусь\n4. Казахстан", "Выбор", "Отмена");
        }
    }
    return true;
}

stock give_player_number(playerid, id)
{
    new string[512];
    static const chars[11] = {'A', 'B', 'C', 'E', 'H', 'K', 'M', 'O', 'P', 'T', 'X'};
    new number[30];
    new region[30];
    
    switch(id) {
        case 0: {
            format(number, sizeof number, "%c%d%d%d%c%c", chars[random(sizeof chars)], random(10), random(10), random(10), chars[random(sizeof chars)], chars[random(sizeof chars)]);
            format(region, sizeof region, "%d", random(900)+100);
        }
        case 1: {
            format(number, sizeof number, "%c%c %d%d%d%d %c%c", chars[random(sizeof chars)], chars[random(sizeof chars)], random(10), random(10), random(10), random(10), chars[random(sizeof chars)], chars[random(sizeof chars)]);
            region = "";
        }
        case 2: {
            format(number, sizeof number, "%d%d%d%d%c%c-%d", random(10), random(10), random(10), random(10), chars[random(sizeof chars)], chars[random(sizeof chars)], random(10));
            region = "";
        }
        case 3: {
            format(number, sizeof number, "%d%d%d%c%c%c", random(10), random(10), random(10), chars[random(sizeof chars)], chars[random(sizeof chars)], chars[random(sizeof chars)]);
            format(region, sizeof region, "%02d", random(100));
        }
    }
    
    selected_number[playerid] = number;
    selected_regionR[playerid] = region;
    selected_region[playerid] = id;
    
    format(string, sizeof string, "Вы хотите купить данный номер: %s\n\nПри прокруте с вас снимется 1500 рублей", number);
    return SPD(playerid, 4497, DIALOG_STYLE_MSGBOX, "Покупка номера",string, "Купить", "Прокрут");
}

stock save_number(playerid, type)
{
    new veh_id = pData[playerid][car_id];
    new sql_id = vehicle[veh_id][cOwnTo];
    
    vehicle[veh_id][cPlate] = selected_number[playerid];
    vehicle[veh_id][cPlateRegion] = selected_regionR[playerid];
    
    switch(selected_region[playerid]) {
        case 0: {
            vehicle[veh_id][cPlateType] = 1;
            SetVehicleRuNumberPlate(veh_id, vehicle[veh_id][cPlate], vehicle[veh_id][cPlateRegion]);
        }
        case 1: {
            vehicle[veh_id][cPlateType] = 4;
            SetVehicleUaNumberPlate(veh_id, vehicle[veh_id][cPlate]);
        }
        case 2: {
            vehicle[veh_id][cPlateType] = 3;
            SetVehicleBuNumberPlate(veh_id, vehicle[veh_id][cPlate]);
        }
        case 3: {
            vehicle[veh_id][cPlateType] = 2;
            SetVehicleKzNumberPlate(veh_id, vehicle[veh_id][cPlate], vehicle[veh_id][cPlateRegion]);
        }
    }
    
    format(String2048, sizeof(String2048), "UPDATE `player_vehicles` SET \
		    	number = '%s',\
		    	number_region = '%s',\
		    	number_type = '%d'\
		    	WHERE id = '%d' AND owner = '%s'",
		    	vehicle[veh_id][cPlate],
				vehicle[veh_id][cPlateRegion],
				vehicle[veh_id][cPlateType],
		    	sql_id, GetNameEx(playerid));

	sql_queryEx(zConn, String2048, QUERY_THREADED);
	
	if(type == 1)
	    give_money(playerid, -5000, "покупка номера");
    else 
        give_money(playerid, -500000, "покупка номера");
	
	return SendSucc(playerid, "Вы успешно купили номер!");
}

stock check_valid_number(playerid, number[])
{
    switch(selected_region[playerid]) {
        case 0: {
            if(strlen(number) != 6)
                return false;
            if(!is_allow_char(number[0]))
               return false;
            if(!is_allow_value(number[1]))
                return false;
            if(!is_allow_value(number[2]))
                return false;
            if(!is_allow_value(number[3]))
                return false;
            if(!is_allow_char(number[4]))
               return false;
            if(!is_allow_char(number[5]))
               return false;
        }
        case 1: {
            if(strlen(number) != 10)
                return false;
            if(!is_allow_char(number[0]))
               return false;
            if(!is_allow_char(number[1]))
               return false;
            if(number[2] != ' ' && number[7] != ' ')
                 return false;
            if(!is_allow_value(number[3]))
                return false;
            if(!is_allow_value(number[4]))
                return false;
            if(!is_allow_value(number[5]))
                return false;
            if(!is_allow_value(number[6]))
                return false;
            if(!is_allow_char(number[8]))
               return false;
            if(!is_allow_char(number[9]))
               return false;
        }
        case 2: {
            if(strlen(number) != 8)
                return false;
            if(number[6] != '-')
                return false;
            if(!is_allow_value(number[0]))
                return false;
            if(!is_allow_value(number[1]))
                return false;
            if(!is_allow_value(number[2]))
                return false;
           if(!is_allow_value(number[3]))
                return false;
           if(!is_allow_char(number[4]))
               return false;
           if(!is_allow_char(number[5]))
               return false;
           if(strval(number[7]) > 9)
               return false;
        }
        case 3: {
            if(strlen(number) != 6)
                return false;
            if(!is_allow_value(number[0]))
                return false;
            if(!is_allow_value(number[1]))
                return false;
            if(!is_allow_value(number[2]))
                return false;
           if(!is_allow_char(number[3]))
               return false;
           if(!is_allow_char(number[4]))
               return false;
           if(!is_allow_char(number[5]))
               return false;
        }
    }
    return true;
}

stock check_valid_region(playerid, region[])
{
    switch(selected_region[playerid]) {
        case 0: {
            if(strval(region) < 100 || strval(region) > 999)
                return false;
        }
        case 3: {
            if(strval(region) < 10 || strval(region) > 99)
                return false;
        }
    }
    return true;
}

stock is_allow_char(charr)
{
    static const chars[11] = {'A', 'B', 'C', 'E', 'H', 'K', 'M', 'O', 'P', 'T', 'X'};
    for(new i = 0; i < 11; i++) 
    {
        if(charr == chars[i])
            return true;
    }
    return false;
}

stock is_allow_value(vall)
{
    static const values[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for(new i = 0; i < 10; i++) 
    {
        if(vall == values[i])
            return true;
    }
    return false;
}