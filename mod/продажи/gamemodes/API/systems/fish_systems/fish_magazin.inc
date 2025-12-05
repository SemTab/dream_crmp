#define ACTOR_FISH_SELLER_POS		2110.2930,1903.3234,1222.8193,269.3090
#define ACTOR_FISH_SELLER_SKIN		32


#define ZONE_FISH_ACTIVE			2110.2852,1903.2502,1222.8193,268.1799


#define PRICE_WORM_FISH				1
#define PRICE_OPARISH_FISH			2
#define PRICE_BREAD_FISH			5
#define PRICE_CORN_FISH				3
#define PRICE_FRY_FISH 				6
#define PRICE_SHINE_FISH			10
#define PRICE_SUBSTITUE_FRY_FISH	4

#define ROD_ONE 					100
#define ROD_TWO						400
#define ROD_THREE 					1000

new 
	fish_magazin_area[3];


static const Float: magazin_fish_pos[][] = {
    {2116.7041,1905.3275,1222.8193},
    {2114.7844,1908.1000,1222.8193},
    {2112.0872,1903.4094,1222.8193}
};
 
static const fish_name[][] =
{
    "Белый осётр",
    "Пятнистая панцирная щука",
    "Светлопёрый мудак",
    "Тихоокеанская корюшка",
    "Ушастый окунь",
    "Чёрный сомик",
    "Язь",
    "Пятнистый Панцирник"
};

static const rod_fish_name[][] =
{
    "Salmo Taifun Pole 400",
    "Shimano CX TE 5-500",
    "Black Hole Hektor 213/5-28"
};

static const fish_other_name[][] = 
{

	"Червь",
	"Опарыш",
	"Хлеб",
	"Кукуруза",
	"Мальки",
	"Блесна",
	"Заменитель мальков"

};

stock create_fish_magazin() {


	fish_magazin_area[0] = CreateTrigger(magazin_fish_pos[0][0], magazin_fish_pos[0][1], magazin_fish_pos[0][2]+0.15, TRIGGER_FC);
	fish_magazin_area[1] = CreateTrigger(magazin_fish_pos[1][0], magazin_fish_pos[1][1], magazin_fish_pos[1][2]+0.15, TRIGGER_FC);
	fish_magazin_area[2] = CreateTrigger(magazin_fish_pos[2][0], magazin_fish_pos[2][1], magazin_fish_pos[2][2]+0.15, TRIGGER_FC);

	CreateDynamicActor(ACTOR_FISH_SELLER_SKIN,ACTOR_FISH_SELLER_SKIN, 1, 100.0, 11, 1);

	return true;
}

stock show_menu_fish_other(playerid) {

    static
        fmt_str[800];

    format(fmt_str, 800, "\
        "cGREY"Категория \t"cGREY"Цена \t"cGREY"Объемов\n\
        "cWH"%s  \t"cYELLOW"$%d \t"cBLUE"1 кг\n\
        "cWH"%s \t"cYELLOW"$%d \t"cBLUE"1 кг\n\
        "cWH"%s \t"cYELLOW"$%d \t"cBLUE" 500 грамм\n\
        "cWH"%s \t"cYELLOW"$%d \t"cBLUE"1 кг\n\
        "cWH"%s \t"cYELLOW"$%d \t"cBLUE"1 кг\n\
        "cWH"%s \t"cYELLOW"$%d \t"cBLUE"1 штука\n\
        "cWH"%s \t"cYELLOW"$%d \t"cBLUE"500 грамм", 
        fish_other_name[0],PRICE_WORM_FISH,
        fish_other_name[1],PRICE_OPARISH_FISH,
        fish_other_name[2],PRICE_BREAD_FISH,
        fish_other_name[3],PRICE_CORN_FISH,
        fish_other_name[4],PRICE_FRY_FISH,
        fish_other_name[5],PRICE_SHINE_FISH,
        fish_other_name[6],PRICE_SUBSTITUE_FRY_FISH);
    return SPD(playerid, DIALOG_SELECT_FISH_OTHER, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Рыболовный магазин", fmt_str, !"Выбрать", !"Закрыть");    
}

stock show_menu_fish_rod(playerid) {


    static
        fmt_str[400];

    format(fmt_str, 400, "\
        "cGREY"Категория \t"cGREY"Цена \t"cGREY"Требуемый скилл\n\
        "cWH"%s   \t"cYELLOW"$%d \t"cBLUE"1 скилл\n\
        "cWH"%s  \t"cYELLOW"$%d \t"cBLUE"3 скилл\n\
        "cWH"%s   \t"cYELLOW"$%d \t"cBLUE"5 скилл",
        rod_fish_name[0], ROD_ONE,
        rod_fish_name[1], ROD_TWO,
        rod_fish_name[2], ROD_THREE);
    return SPD(playerid, DIALOG_SELECT_FISH_ROD, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Рыболовный магазин", fmt_str, !"Выбрать", !"Закрыть"); 

}

stock show_menu_case(playerid) {

    static
        fmt_str[400];

    format(fmt_str, 400, "\
        "cGREY"Категория \t"cGREY"\n\
        "cWH"Продажа рыбы магазину\t"cBLUE"Перейти\n\
        "cWH"Оплата продукции\t"cBLUE"Перейти");
    return SPD(playerid, DIALOG_SELECT_FISH_CASA, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Рыболовный магазин", fmt_str, !"Выбрать", !"Закрыть"); 
}

stock buy_fish_magazin(playerid) 
{
    static
        fmt_str[1000];

    format(fmt_str, 1000, "\
        "cGREY"Товар \t"cGREY"Кол-во\n\
        "cWH"%s \t"cBLUE"%d\n\
        "cWH"%s \t"cBLUE"%d\n\
        "cWH"%s \t"cBLUE"%d\n\
        "cWH"%s \t"cBLUE"%d\n\
        "cWH"%s \t"cBLUE"%d\n\
        "cWH"%s \t"cBLUE"%d\n\
        "cWH"%s \t"cBLUE"%d\n\
        "cWH"%s \t"cBLUE"%d\n\
        "cWH"%s \t"cBLUE"%d\n\
        "cWH"%s \t"cBLUE"%d\n\
        "cWH"\t\n\
        "cWH"К оплате \t"cBLUE"$%d\n\
        "cWH"\t\n\
        "cWH"Оплатить продукцию\n\
        "cBLUE"Отказаться от продукции", 
        fish_other_name[0],GetPVarIntNew(playerid, "worm_fish_magazin"),
        fish_other_name[1],GetPVarIntNew(playerid, "oparysh_fish_magazin"),
        fish_other_name[2],GetPVarIntNew(playerid, "bread_fish_magazin"),
        fish_other_name[3],GetPVarIntNew(playerid, "corn_fish_magazin"),
        fish_other_name[4],GetPVarIntNew(playerid, "fry_fish_magazin"),
        fish_other_name[5],GetPVarIntNew(playerid, "shine_fish_magazin"),
        fish_other_name[6],GetPVarIntNew(playerid, "subfry_fish_magazin"),

        rod_fish_name[0], GetPVarIntNew(playerid,"rod_one"),
        rod_fish_name[1], GetPVarIntNew(playerid,"rod_two"),
        rod_fish_name[2], GetPVarIntNew(playerid,"rod_three"),
        GetPVarIntNew(playerid, "fish_count_money"));
    return SPD(playerid, DIALOG_SELECT_FISH_BUY, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Рыболовный магазин", fmt_str, !"Выбрать", !"Закрыть");    
}

stock sell_fish_player(playerid) 
{
    static
        fmt_str[800];

    format(fmt_str, 800, "\
        "cGREY"Рыба \t"cGREY"Цена продажи\t"cGREY"Кол-во\n\
        "cWH"%s \t"cBLUE"$%d \t"cBLUE"0 кг\n\
        "cWH"%s \t"cBLUE"$%d \t"cBLUE"0 кг\n\
        "cWH"%s \t"cBLUE"$%d \t"cBLUE"9 кг\n\
        "cWH"%s \t"cBLUE"$%d \t"cBLUE"0 кг\n\
        "cWH"%s \t"cBLUE"$%d \t"cBLUE"0 кг\n\
        "cWH"%s \t"cBLUE"$%d \t"cBLUE"0 кг\n\
        "cWH"%s \t"cBLUE"$%d \t"cBLUE"0 кг", 
        fish_name[0],PRICE_WORM_FISH,
        fish_name[1],PRICE_OPARISH_FISH,
        fish_name[2],PRICE_BREAD_FISH,
        fish_name[3],PRICE_CORN_FISH,
        fish_name[4],PRICE_FRY_FISH,
        fish_name[5],PRICE_SHINE_FISH,
        fish_name[6],PRICE_SUBSTITUE_FRY_FISH,
        fish_name[7],PRICE_SUBSTITUE_FRY_FISH);
    return SPD(playerid, DIALOG_SELECT_FISH_OTHER, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Рыболовный магазин", fmt_str, !"Выбрать", !"Закрыть");  
}

stock dialog_fish(playerid, dialogid, response, listitem) 
{

	switch(dialogid)
	{
		case DIALOG_SELECT_FISH_OTHER: {
			if(!response)
				return true;
			switch(listitem) {
				case 0: return select_fish_other(playerid, 0);
				case 1: return select_fish_other(playerid, 1);
				case 2: return select_fish_other(playerid, 2);
				case 3: return select_fish_other(playerid, 3);
				case 4: return select_fish_other(playerid, 4);
				case 5: return select_fish_other(playerid, 5);
				case 6: return select_fish_other(playerid, 6);
			}
		}

		case DIALOG_SELECT_FISH_ROD: {
			if(!response)
				return true;
			switch(listitem) {
				case 0: return select_fish_rod(playerid, 0);
				case 1: return select_fish_rod(playerid, 1);
				case 2: return select_fish_rod(playerid, 2);
			}
		}

		case DIALOG_SELECT_FISH_CASA: {
			if(!response)
				return true;
			switch(listitem) {
				case 0: return sell_fish_player(playerid);
				case 1: return buy_fish_magazin(playerid);
			}
		}
		case DIALOG_SELECT_FISH_BUY: {
			if(!response)
				return true;
			switch(listitem) {
				case 13: return accept_buy_fish_magazin(playerid);
				case 14: return false_buy_fish_magazin(playerid);
			}
		}
	}
	return true;

}

stock accept_buy_fish_magazin(playerid) {

	if(GetPlayerMoneyEx(playerid) < GetPVarIntNew(playerid, "fish_count_money")) 
		return true;


	give_money(playerid, -GetPVarIntNew(playerid, "fish_count_money"),"Покупка в рыболовном магазине");


	//СОХРАНЕНИЕ В ИНВЕНТАРЬ

	return true;
}

stock false_buy_fish_magazin(playerid) {

	if(GetPVarIntNew(playerid, "fish_count_money") < 0) 
		return true;

	clear_fish_magazin_data(playerid);


	return true;
}

stock clear_fish_magazin_data(playerid) {

	DeletePVarNew(playerid, "fish_count_money");
	DeletePVarNew(playerid, "worm_fish_magazin");
	DeletePVarNew(playerid, "oparysh_fish_magazin");
	DeletePVarNew(playerid, "bread_fish_magazin");
	DeletePVarNew(playerid, "corn_fish_magazin");
	DeletePVarNew(playerid, "fry_fish_magazin");
	DeletePVarNew(playerid, "shine_fish_magazin");
	DeletePVarNew(playerid, "subfry_fish_magazin");	

	DeletePVarNew(playerid,"rod_one");
	DeletePVarNew(playerid,"rod_two");
	DeletePVarNew(playerid,"rod_three");

	return true;
}

stock select_fish_other(playerid, type) {

	switch(type)
	{
		case 0: 
		{
			SetPVarIntNew(playerid, "fish_count_money", GetPVarIntNew(playerid, "fish_count_money")+PRICE_WORM_FISH);

			SetPVarIntNew(playerid, "worm_fish_magazin", GetPVarIntNew(playerid, "worm_fish_magazin")+1);

			FormattedMessage(playerid, COLOR_BLUE, "Рыболовный Магазин: \
				"cWH"Вы успешно выбрали к покупке "cBLUE"%s"cWH" на сумму "cBLUE"$%d"cWH". Общая сумма: "cBLUE"$%d", fish_other_name[0], PRICE_WORM_FISH, GetPVarIntNew(playerid, "fish_count_money"));
			
			show_menu_fish_other(playerid);

		}
		case 1: 
		{
			SetPVarIntNew(playerid, "fish_count_money", GetPVarIntNew(playerid, "fish_count_money")+PRICE_OPARISH_FISH);

			SetPVarIntNew(playerid, "oparysh_fish_magazin", GetPVarIntNew(playerid, "oparysh_fish_magazin")+1);

			FormattedMessage(playerid, COLOR_BLUE, "Рыболовный Магазин: \
				"cWH"Вы успешно выбрали к покупке "cBLUE"%s"cWH" на сумму "cBLUE"$%d"cWH". Общая сумма: "cBLUE"$%d", fish_other_name[1], PRICE_OPARISH_FISH, GetPVarIntNew(playerid, "fish_count_money"));
		

			show_menu_fish_other(playerid);
		}
		case 2: 
		{
			SetPVarIntNew(playerid, "fish_count_money", GetPVarIntNew(playerid, "fish_count_money")+PRICE_BREAD_FISH);

			SetPVarIntNew(playerid, "bread_fish_magazin", GetPVarIntNew(playerid, "bread_fish_magazin")+1);

			FormattedMessage(playerid, COLOR_BLUE, "Рыболовный Магазин: \
				"cWH"Вы успешно выбрали к покупке "cBLUE"%s"cWH" на сумму "cBLUE"$%d"cWH". Общая сумма: "cBLUE"$%d", fish_other_name[2], PRICE_BREAD_FISH, GetPVarIntNew(playerid, "fish_count_money"));
		
			show_menu_fish_other(playerid);

		}
		case 3: 
		{
			SetPVarIntNew(playerid, "fish_count_money", GetPVarIntNew(playerid, "fish_count_money")+PRICE_CORN_FISH);

			SetPVarIntNew(playerid, "corn_fish_magazin", GetPVarIntNew(playerid, "corn_fish_magazin")+1);

			FormattedMessage(playerid, COLOR_BLUE, "Рыболовный Магазин: \
				"cWH"Вы успешно выбрали к покупке "cBLUE"%s"cWH" на сумму "cBLUE"$%d"cWH". Общая сумма: "cBLUE"$%d", fish_other_name[3], PRICE_CORN_FISH, GetPVarIntNew(playerid, "fish_count_money"));
		
			show_menu_fish_other(playerid);

		}
		case 4: 
		{
			SetPVarIntNew(playerid, "fish_count_money", GetPVarIntNew(playerid, "fish_count_money")+PRICE_FRY_FISH);

			SetPVarIntNew(playerid, "fry_fish_magazin", GetPVarIntNew(playerid, "fry_fish_magazin")+1);

			FormattedMessage(playerid, COLOR_BLUE, "Рыболовный Магазин: \
				"cWH"Вы успешно выбрали к покупке "cBLUE"%s"cWH" на сумму "cBLUE"$%d"cWH". Общая сумма: "cBLUE"$%d", fish_other_name[4], PRICE_FRY_FISH, GetPVarIntNew(playerid, "fish_count_money"));
		
			show_menu_fish_other(playerid);

		}
		case 5: 
		{
			SetPVarIntNew(playerid, "fish_count_money", GetPVarIntNew(playerid, "fish_count_money")+PRICE_SHINE_FISH);

			SetPVarIntNew(playerid, "shine_fish_magazin", GetPVarIntNew(playerid, "shine_fish_magazin")+1);

			FormattedMessage(playerid, COLOR_BLUE, "Рыболовный Магазин: \
				"cWH"Вы успешно выбрали к покупке "cBLUE"%s"cWH" на сумму "cBLUE"$%d"cWH". Общая сумма: "cBLUE"$%d", fish_other_name[5], PRICE_SHINE_FISH, GetPVarIntNew(playerid, "fish_count_money"));
		
			show_menu_fish_other(playerid);
		}
		case 6: 
		{
			SetPVarIntNew(playerid, "fish_count_money", GetPVarIntNew(playerid, "fish_count_money")+PRICE_SUBSTITUE_FRY_FISH);

			SetPVarIntNew(playerid, "subfry_fish_magazin", GetPVarIntNew(playerid, "subfry_fish_magazin")+1);

			FormattedMessage(playerid, COLOR_BLUE, "Рыболовный Магазин: \
				"cWH"Вы успешно выбрали к покупке "cBLUE"%s"cWH" на сумму "cBLUE"$%d"cWH". Общая сумма: "cBLUE"$%d", fish_other_name[6], PRICE_SUBSTITUE_FRY_FISH, GetPVarIntNew(playerid, "fish_count_money"));
		
			show_menu_fish_other(playerid);

		}
	}
	return true;
}


stock select_fish_rod(playerid, type) {

	switch(type)
	{
		case 0: 
		{

			if(GetPVarIntNew(playerid, "rod_one") == 1) 
				return true;

			SetPVarIntNew(playerid, "fish_count_money", GetPVarIntNew(playerid, "fish_count_money")+ROD_ONE);

			SetPVarIntNew(playerid, "rod_one", 1);

			FormattedMessage(playerid, COLOR_BLUE, "Рыболовный Магазин: \
				"cWH"Вы успешно выбрали к покупке "cBLUE"%s"cWH" на сумму "cBLUE"$%d"cWH". Общая сумма: "cBLUE"$%d", rod_fish_name[0], ROD_ONE);

			show_menu_fish_rod(playerid);
		}
		case 1: 
		{

			if(GetPVarIntNew(playerid, "rod_two") == 1) 
				return true;

			SetPVarIntNew(playerid, "fish_count_money", GetPVarIntNew(playerid, "fish_count_money")+ROD_TWO);

			SetPVarIntNew(playerid, "rod_two", 1);

			FormattedMessage(playerid, COLOR_BLUE, "Рыболовный Магазин: \
				"cWH"Вы успешно выбрали к покупке "cBLUE"%s"cWH" на сумму "cBLUE"$%d"cWH". Общая сумма: "cBLUE"$%d", rod_fish_name[1], ROD_TWO);

			show_menu_fish_rod(playerid);
		}
		case 2: 
		{

			if(GetPVarIntNew(playerid, "rod_three") == 1) 
				return true;

			SetPVarIntNew(playerid, "fish_count_money", GetPVarIntNew(playerid, "fish_count_money")+ROD_THREE);

			SetPVarIntNew(playerid, "rod_three", 1);

			FormattedMessage(playerid, COLOR_BLUE, "Рыболовный Магазин: \
				"cWH"Вы успешно выбрали к покупке "cBLUE"%s"cWH" на сумму "cBLUE"$%d"cWH". Общая сумма: "cBLUE"$%d", rod_fish_name[2], ROD_THREE);

			show_menu_fish_rod(playerid);
		}
	}
	return true;
}