stock show_sell_fish_player(playerid)
{

	new 
		count_fish[15];


	count_fish[0] = get_inventory_items(playerid, 358);
	count_fish[1] = get_inventory_items(playerid, 359);
	count_fish[2] = get_inventory_items(playerid, 360);
	count_fish[3] = get_inventory_items(playerid, 361);
    count_fish[4] = get_inventory_items(playerid, 362);
    count_fish[5] = get_inventory_items(playerid, 363);
    count_fish[6] = get_inventory_items(playerid, 364);
    count_fish[7] = get_inventory_items(playerid, 365);
    count_fish[8] = get_inventory_items(playerid, 366);
    count_fish[9] = get_inventory_items(playerid, 367);
    count_fish[10] = get_inventory_items(playerid, 368);
    count_fish[11] = get_inventory_items(playerid, 369);
    count_fish[12] = get_inventory_items(playerid, 370);
    count_fish[13] = get_inventory_items(playerid, 371);
    count_fish[14] = get_inventory_items(playerid, 372);


    format(String2048, sizeof(String2048), "\
        "cGREY"Услуга\t"cGREY"Стоимость\t"cGREY"Остальное\n\
        "cBLUE"- "cWH"Продажа %s\t"cGR"%d рублей\t"cBLUE"%d рыбы\n\
        "cBLUE"- "cWH"Продажа %s\t"cGR"%d рублей\t"cBLUE"%d рыбы\n\
        "cBLUE"- "cWH"Продажа %s\t"cGR"%d рублей\t"cBLUE"%d рыбы\n\
        "cBLUE"- "cWH"Продажа %s\t"cGR"%d рублей\t"cBLUE"%d рыбы\n\
        "cBLUE"- "cWH"Продажа %s\t"cGR"%d рублей\t"cBLUE"%d рыбы\n\
        "cBLUE"- "cWH"Продажа %s\t"cGR"%d рублей\t"cBLUE"%d рыбы\n\
        "cBLUE"- "cWH"Продажа %s\t"cGR"%d рублей\t"cBLUE"%d рыбы\n\
        "cBLUE"- "cWH"Продажа %s\t"cGR"%d рублей\t"cBLUE"%d рыбы\n\
        "cBLUE"- "cWH"Продажа %s\t"cGR"%d рублей\t"cBLUE"%d рыбы\n\
        "cBLUE"- "cWH"Продажа %s\t"cGR"%d рублей\t"cBLUE"%d рыбы\n\
        "cBLUE"- "cWH"Продажа %s\t"cGR"%d рублей\t"cBLUE"%d рыбы\n\
        "cBLUE"- "cWH"Продажа %s\t"cGR"%d рублей\t"cBLUE"%d рыбы\n\
        "cBLUE"- "cWH"Продажа %s\t"cGR"%d рублей\t"cBLUE"%d рыбы\n\
        "cBLUE"- "cWH"Продажа %s\t"cGR"%d рублей\t"cBLUE"%d рыбы\n\
        "cBLUE"- "cWH"Продажа %s\t"cGR"%d рублей\t"cBLUE"%d рыбы\n\
        \t\n\
        "cBLUE"- "cWH"Что ты тут делаешь?\t"cGREY"Спросить\n\
        "cBLUE"- "cWH"Как ловить рыбу?\t"cGREY"Спросить\n\
        "cBLUE"- "cWH"Что с ценами?\t"cGREY"Спросить",

        get_fish_name(1), fish_price_player[0], count_fish[0], 
        get_fish_name(2), fish_price_player[1], count_fish[1], 
        get_fish_name(3), fish_price_player[2], count_fish[2], 
        get_fish_name(4), fish_price_player[3], count_fish[3], 
        get_fish_name(5), fish_price_player[4], count_fish[4], 
        get_fish_name(6), fish_price_player[5], count_fish[5], 
        get_fish_name(7), fish_price_player[6], count_fish[6], 
        get_fish_name(8), fish_price_player[7], count_fish[7], 
        get_fish_name(9), fish_price_player[8], count_fish[8], 
        get_fish_name(10), fish_price_player[9], count_fish[9], 
        get_fish_name(11), fish_price_player[10], count_fish[10],
        get_fish_name(12), fish_price_player[11], count_fish[11],
        get_fish_name(13), fish_price_player[12], count_fish[12],
        get_fish_name(14), fish_price_player[13], count_fish[13],
        get_fish_name(15), fish_price_player[14], count_fish[14]        
        

        );
    return SPD(playerid, DIALOG_SELLER_FISH, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Рыбак Василич", String2048, !"Выбрать", !"Закрыть"); 
}

stock sell_fish_player_final(playerid, type_fish)
{
    SetPVarIntNew(playerid, "type_sell_fish_player", type_fish);


    format(String256, sizeof(String256), "\
        "cWH"Сколько %s Вы хотите продать?\n\n\
        "cWH"Стоимость продажи: "cGR"%d"cWH" рублей\n\
        "cWH"В наличии у Вас: "cBLUE"%d"cWH" штук", 

        get_fish_name(type_fish), 
        fish_price_player[type_fish-1], 
        get_inventory_items(playerid, get_inventory_items_fish(playerid, type_fish)));

    return SPD(playerid, DIALOG_SELL_FISH_FINAL, DIALOG_STYLE_INPUT, !""cBLUE"Продажа рыбы", String256, !"Далее", !"Назад");     
}

stock get_inventory_items_fish(playerid, type)
{
    new 
        inventory_id;

    switch(type)
    {
        case 1: inventory_id = 358;
        case 2: inventory_id = 359;
        case 3: inventory_id = 360;
        case 4: inventory_id = 361;
        case 5: inventory_id = 362;
        case 6: inventory_id = 363;
        case 7: inventory_id = 364;
        case 8: inventory_id = 365;
        case 9: inventory_id = 366;
        case 10: inventory_id = 367;
        case 11: inventory_id = 368;
        case 12: inventory_id = 369;
        case 13: inventory_id = 370;
        case 14: inventory_id = 371;
        case 15: inventory_id = 372;
    }
    return inventory_id;
}

stock dialog_all_fish(playerid, dialogid, response, listitem, inputtext[])
{

    switch(dialogid)
    {

        case DIALOG_SELLER_FISH:
        {
            if(!response)
                return true;

            switch(listitem)
            {

                case 0: sell_fish_player_final(playerid, FISH_MODELS_LOSOS);
                case 1: sell_fish_player_final(playerid, FISH_MODELS_GORBUSHA);
                case 2: sell_fish_player_final(playerid, FISH_MODELS_SAZAN);
                case 3: sell_fish_player_final(playerid, FISH_MODELS_SOM);
                case 4: sell_fish_player_final(playerid, FISH_MODELS_TRESKA);
                case 5: sell_fish_player_final(playerid, FISH_MODELS_TUNEC);
                case 6: sell_fish_player_final(playerid, FISH_MODELS_SUDAK);
                case 7: sell_fish_player_final(playerid, FISH_MODELS_SEMGA);
                case 8: sell_fish_player_final(playerid, FISH_MODELS_SKUMBRIA);
                case 9: sell_fish_player_final(playerid, FISH_MODELS_LEH);
                case 10: sell_fish_player_final(playerid, FISH_MODELS_SHUKA);
                case 11: sell_fish_player_final(playerid, FISH_MODELS_FOREL);
                case 12: sell_fish_player_final(playerid, FISH_MODELS_PLOTVA);
                case 13: sell_fish_player_final(playerid, FISH_MODELS_LAKENDRA);
                case 14: sell_fish_player_final(playerid, FISH_MODELS_MAKREL);
                case 15: show_sell_hunter_legal(playerid);
                case 16: show_info_fish(playerid, 1);
                case 17: show_info_fish(playerid, 2);
                case 18: show_info_fish(playerid, 3);
            }
        }
        case DIALOG_SELL_FISH_FINAL:
        {
            if(!response)
                return show_sell_fish_player(playerid);

            new 
                type_fish = GetPVarIntNew(playerid, "type_sell_fish_player");

            if(!IsNumeric(inputtext) || !strlen(inputtext))
            {
                SendErr(playerid,"Вы указали неверное значение!");
                return sell_fish_player_final(playerid, type_fish);
            }

            new 
                count_meet_sell = strval(inputtext);

            if(count_meet_sell < 1)
            {
                SendErr(playerid,"У вас недостаточно рыбы для продажи!");
                return sell_fish_player_final(playerid, type_fish);     
            }

            if(get_inventory_items(playerid, get_inventory_items_fish(playerid, type_fish)) < count_meet_sell)
            {
                SendErr(playerid,"У вас недостаточно рыбы для продажи!");
                return sell_fish_player_final(playerid, type_fish);     
            }

            check_remove_inventory(playerid, get_inventory_items_fish(playerid, type_fish), get_inventory_items_slot(playerid, get_inventory_items_fish(playerid, type_fish)), -count_meet_sell);

            new     
                final_money = count_meet_sell*fish_price_player[type_fish-1];

            give_money(playerid, final_money, "Деньги за продажу Рыбы");                   
        }
        case DIALOG_BACK_FISH_ACTOR:
        {
            if(!response)
                return show_sell_fish_player(playerid);

            show_sell_fish_player(playerid);
        }
    }
    return true;
}

stock show_info_fish(playerid, type)
{
    switch(type)
    {
        case 1:
        {
            SPD(playerid, DIALOG_BACK_FISH_ACTOR, DIALOG_STYLE_MSGBOX, !""cBLUE"Что ты тут делаешь?", !"\
            "cBLUE"Рыбак Василич"cWH"\n\n\
            Да рыбу скупаю, слежу за озером, чтобы всякие идиоты с динамитом не приехали!\n\n\
            У нас дружное сообщество рыбаков! Так что присоединяйся и лови рыбу вместе с нами!", !"Закрыть", "");
        }
        case 2:
        {
            SPD(playerid, DIALOG_BACK_FISH_ACTOR, DIALOG_STYLE_MSGBOX, !""cBLUE"Как ловить рыбу?", !"\
            "cBLUE"Рыбак Василич"cWH"\n\n\
            Тебе нужна удочка, их всего 3 типа:\n\n\
            "cBLUE"-"cWH" Удочка Daiwa Morethan. Стоит около "cGR"10.000 рублей"cWH"\n\
            "cBLUE"-"cWH" Удочка Shimano Aspire Ultra. Стоит около "cGR"50.000 рублей"cWH"\n\
            "cBLUE"-"cWH" Удочка Sensas Power Pack Match. Стоит около "cGR"100.000 рублей"cWH"\n\n\
            Все стоят по разному и у каждой свои плюсы! Много выбора!\n\
            Плюс производители в подарок дают всё необходимое снаряжение!\n\
            Приобрести удочку можно в любом магазине 24/7\
            ", !"Закрыть", "");
        }
        case 3:
        {
            SPD(playerid, DIALOG_BACK_FISH_ACTOR, DIALOG_STYLE_MSGBOX, !""cBLUE"Как цены меняются?", !"\
            "cBLUE"Рыбак Василич"cWH"\n\n\
            Цены изменяются каждый час, так что нужно быть готовым к переменам!\n\n\
            Мне же конечно выгоднее, когда Вы приходите продавать по стоимости ниже *смеясь*", !"Закрыть", "");
        }
    }


    return true;
}