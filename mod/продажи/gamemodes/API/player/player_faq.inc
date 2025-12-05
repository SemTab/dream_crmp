stock dialog_faq_all(playerid, dialogid, response, listitem)
{
	switch(dialogid)
	{
		case DIALOG_SELECT_FAQ_CATEGORY:
		{
			if(!response)
				return true;

			switch(listitem)
			{
				case 0: return show_dialog_faq_work(playerid);
				case 1: return show_dialog_faq_buy(playerid);
				case 2: return show_dialog_faq_other(playerid);
			}
		}
		case DIALOG_SELECT_FAQ_WORK:
		{
			if(!response)
				return show_dialog_faq(playerid);

			switch(listitem)
			{
				case 0:
				{
					return SPD(playerid, DIALOG_FAQ_WORK, DIALOG_STYLE_MSGBOX, !""cBLUE"Как добраиться до начальной работы?", "\
						"cWH"Используй команду "cBLUE"/gps "cWH"и перейди в раздел "cBLUE"«Работы».\n\
						"cWH"Выбери нужную работу и после следуй к красной отметке на карте.", !"Назад", "");
				}
				case 1:
				{
					return SPD(playerid, DIALOG_FAQ_WORK, DIALOG_STYLE_MSGBOX, !""cBLUE"Как начать работу в шахте, на заводе или лесопилке?", "\
						"cWH"Доберись до них, зайди внутрь и встань на похожий на рубашку пикап.\n\
						"cWH"Нажми пункт "cBLUE"«Начать работу» "cWH"и следуй к красной отметке на радаре.", !"Назад", "");
				}
				case 2:
				{
					return SPD(playerid, DIALOG_FAQ_WORK, DIALOG_STYLE_MSGBOX, !""cBLUE"Чем занимаются на шахте?", "\
						"cWH"Работа всегда происходит в три этапа. Сначала вы занимаетесь добычей руды,\n\
						"cWH"затем сортировкой, а после - укомплектовываете ящики и относите их на склад.\n\
						"cWH"Только после этого вам зачисляется заработная плата.", !"Назад", "");
				}
				case 3:
				{
					return SPD(playerid, DIALOG_FAQ_WORK, DIALOG_STYLE_MSGBOX, !""cBLUE"Чем занимаются на заводе?", "\
						"cWH"На заводе имеется два вида работы: сборка мебели и слесарное дело.\n\
						"cWH"В обоих случаях вы собираете «пазлы» и получаете за это заработную плату.", !"Назад", "");
				}
				case 4:
				{
					return SPD(playerid, DIALOG_FAQ_WORK, DIALOG_STYLE_MSGBOX, !""cBLUE"Чем занимаются на лесопилке?", "\
						"cWH"На лесопилке потребуется взобраться на дерево и кликать\n\
						"cWH"по крестикам, тем самым распиливая его бензопилой.", !"Назад", "");
				}
			}
		}
		case DIALOG_SELECT_FAQ_BUY:
		{
			if(!response)
				return show_dialog_faq_buy(playerid);

			switch(listitem)
			{
				case 0:
				{
					return SPD(playerid, DIALOG_FAQ_BUY, DIALOG_STYLE_MSGBOX, !""cBLUE"Как добраться до Школы Вождения?", "\
						"cWH"Используй команду "cBLUE"/gps "cWH"и нажми на "cBLUE"«Автошкола»"cWH".\n\
						"cWH"После следуй к красной отметке на карте.", !"Назад", "");
				}
				case 1:
				{
					return SPD(playerid, DIALOG_FAQ_BUY, DIALOG_STYLE_MSGBOX, !""cBLUE"Что я могу приобрести в Школе Вождения?", "\
						"cWH"В школе вождения вы можете приобрести лицензию на управление различным транспортом.\n\
						"cWH"Самая дешевая из них - водительские права. Потребуется всего "cGR"1000 рублей.\n\
						"cWH"Остальные цены узнайте на месте.", !"Назад", "");
				}
				case 2:
				{
					return SPD(playerid, DIALOG_FAQ_BUY, DIALOG_STYLE_MSGBOX, !""cBLUE"Что делать если я завалил экзамен?", "\
						"cWH"Попробуй ещё раз. Для этого потребуется снова заплатить,\n\
						"cWH"но при этом попытки ничем не ограничены.", !"Назад", "");
				}
				case 3:
				{
					return SPD(playerid, DIALOG_FAQ_BUY, DIALOG_STYLE_MSGBOX, !""cBLUE"Как купить телефон?", "\
						"cWH"Используй команду "cBLUE"/gps "cWH"и нажми на "cBLUE"«Ближайший магазин 24/7».\n\
						"cWH"После следуй к красной отметке на карте.", !"Назад", "");
				}
				case 4:
				{
					return SPD(playerid, DIALOG_FAQ_BUY, DIALOG_STYLE_MSGBOX, !""cBLUE"Как найти магазин одежды?", "\
						"cWH"Используй команду "cBLUE"/gps "cWH"и нажми на "cBLUE"«Ближайший магазин одежды».\n\
						"cWH"После следуй к красной отметке на карте.", !"Назад", "");
				}
				case 5:
				{
					return SPD(playerid, DIALOG_FAQ_BUY, DIALOG_STYLE_MSGBOX, !""cBLUE"Как купить скин?", "\
						"cWH"Зайди в магазин одежды и проследуй на пикап в примерочной.\n\
						"cWH"После используй интерфейс выбора и кнопку "cBLUE"«Купить».", !"Назад", "");
				}
				case 6:
				{
					return SPD(playerid, DIALOG_FAQ_BUY, DIALOG_STYLE_MSGBOX, !""cBLUE"Как найти магазин аксессуаров?", "\
						"cWH"Используй команду "cBLUE"/gps "cWH"и нажми на "cBLUE"«Ближайший магазин аксессуаров».\n\
						"cWH"После следуй к красной отметке на карте.", !"Назад", "");
				}
				case 7:
				{
					return SPD(playerid, DIALOG_FAQ_BUY, DIALOG_STYLE_MSGBOX, !""cBLUE"Как купить аксессуар?", "\
						"cWH"Зайди в магазин аксессуаров и проследуй на пикап в примерочной.\n\
						"cWH"После используй интерфейс выбора и кнопку "cBLUE"«Купить».", !"Назад", "");
				}
				case 8:
				{
					return SPD(playerid, DIALOG_FAQ_BUY, DIALOG_STYLE_MSGBOX, !""cBLUE"Что такое отель?", "\
						"cWH"Отель это временное место жительства, которое\n\
						"cWH"вы можете арендовать вместо дома или квартиры.", !"Назад", "");
				}
				case 9:
				{
					return SPD(playerid, DIALOG_FAQ_BUY, DIALOG_STYLE_MSGBOX, !""cBLUE"Как купить дом или квартиру?", "\
						"cWH"Ищите на карте зелёные иконки домов. Зелёная иконка обозначает,\n\
						"cWH"что дом "cGR"свободен "cWH"для покупки. Встаньте на пикап возле дома и нажмите "cBLUE"«Купить».", !"Назад", "");
				}
				case 10:
				{
					return SPD(playerid, DIALOG_FAQ_BUY, DIALOG_STYLE_MSGBOX, !""cBLUE"Что делать если все дома и квартиры заняты?", "\
						"cWH"Некоторые из них будут слетать в гос и освобождаться, если владельцы будут\n\
						"cWH"забывать их оплачивать. Чтобы узнать всё о слетевших домах проследуйте в "cBLUE"Риэлторское агенство"cWH".", !"Назад", "");
				}
				case 11:
				{
					return SPD(playerid, DIALOG_FAQ_BUY, DIALOG_STYLE_MSGBOX, !""cBLUE"Как добраться до Риэлторского агенства?", "\
						"cWH"Используй команду "cBLUE"/gps "cWH"и нажми на "cBLUE"«Общественные места > Риэлторское агенство»"cWH".\n\
						"cWH"После следуй к красной отметке на карте.", !"Назад", "");
				}
				case 12:
				{
					return SPD(playerid, DIALOG_FAQ_BUY, DIALOG_STYLE_MSGBOX, !""cBLUE"Как купить бизнес?", "\
						"cWH"Если бизнес ещё не куплен, то необходимо найти его на карте. Разновидностей достаточно много.\n\
						"cWH"Также вы можете купить бизнес с рук. Впрочем, как и любую недвижимость.", !"Назад", "");
				}
				case 13:
				{
					return SPD(playerid, DIALOG_FAQ_BUY, DIALOG_STYLE_MSGBOX, !""cBLUE"Могу ли я иметь машину без дома или квартиры?", "\
						"cWH"Да, для этого достаточно приобрести машину в любом автосалоне\n\
						"cWH"и припарковать её на специально отведенной для этого парковке.", !"Назад", "");
				}
				case 14:
				{
					return SPD(playerid, DIALOG_FAQ_BUY, DIALOG_STYLE_MSGBOX, !""cBLUE"Как купить машину?", "\
						"cWH"Проследуйте в один из трёх автосалонов на выбор: эконом, средний или премиум класс.\n\
						"cWH"В нём встаньте на пикап и выберите подходящий автомобиль.", !"Назад", "");
				}
				case 15:
				{
					return SPD(playerid, DIALOG_FAQ_BUY, DIALOG_STYLE_MSGBOX, !""cBLUE"Как найти автосалон?", "\
						"cWH"Используй команду "cBLUE"/gps "cWH"и нажми на "cBLUE"«Автосалоны»"cWH".\n\
						"cWH"Выбери нужный и после следуй к красной отметке на карте.", !"Назад", "");
				}
				case 16:
				{
					return SPD(playerid, DIALOG_FAQ_BUY, DIALOG_STYLE_MSGBOX, !""cBLUE"Сколько машин я могу купить?", "\
						"cWH"Без дома, квартиры или гаража - всего одну. С гаражом вы можете купить улучшение,\n\
						"cWH"которое позволит иметь 2, 4 или 8 машин. Также будет расширяться и интерьер вашего гаража!", !"Назад", "");
				}
			}
		}
		case DIALOG_SELECT_FAQ_OTHER:
		{
			if(!response)
				return show_dialog_faq(playerid);

			switch(listitem)
			{
				case 0:
				{
					return SPD(playerid, DIALOG_FAQ_OTHER, DIALOG_STYLE_MSGBOX, !""cBLUE"Как вступить во фракцию?", "\
						"cWH"Следить за новостями в чате и используя команду /vacancy.\n\
						"cWH"Вы можете вступить как в государственные фракции, так и в незаконные.\n\
						"cWH"Вариантов много, каждый найдёт своё.", !"Назад", "");
				}
				case 1:
				{
					return SPD(playerid, DIALOG_FAQ_OTHER, DIALOG_STYLE_MSGBOX, !""cBLUE"Как стать лидером?", "\
						"cWH"На нашем форуме часто открываются заявки на лидерские посты.\n\
						"cWH"Но, это далеко не единственный вариант. Продвигаясь по карьерной лестнице\n\
						"cWH"во фракции вы можете стать лидером и без заявки.", !"Назад", "");
				}
			}
		}
		case DIALOG_FAQ_WORK:
		{
			//return show_dialog_faq_work(playerid);
			return show_dialog_faq(playerid);
		}
		case DIALOG_FAQ_BUY:
		{
			//return show_dialog_faq_buy(playerid);
			return show_dialog_faq(playerid);
		}
		case DIALOG_FAQ_OTHER:
		{
			//return show_dialog_faq_other(playerid);
			return show_dialog_faq(playerid);
		}
	}

	return true;
}

stock show_dialog_faq(playerid)
{
	return SPD(playerid, DIALOG_SELECT_FAQ_CATEGORY, DIALOG_STYLE_LIST, !""cBLUE"Помощь по серверу", "\
		"cBLUE"- "cWH"Начальные работы\n\
		"cBLUE"- "cWH"Покупки\n\
		"cBLUE"- "cWH"Прочее", !"Выбрать", !"Закрыть");
}

stock show_dialog_faq_work(playerid)
{
	return SPD(playerid, DIALOG_SELECT_FAQ_WORK, DIALOG_STYLE_LIST, !""cBLUE"Начальные работы", "\
		"cBLUE"- "cWH"Как добраться до начальной работы?\n\
		"cBLUE"- "cWH"Как начать работу на шахте, на заводе или лесоплике?\n\
		"cBLUE"- "cWH"Чем занимаются на шахте?\n\
		"cBLUE"- "cWH"Чем занимаются на заводе?\n\
		"cBLUE"- "cWH"Чем занимаются на лесоплике?", !"Выбрать", !"Назад");
}

stock show_dialog_faq_buy(playerid)
{
	return SPD(playerid, DIALOG_SELECT_FAQ_BUY, DIALOG_STYLE_LIST, !""cBLUE"Покупки", "\
		"cBLUE"- "cWH"Как добраться до Школы Вождения?\n\
		"cBLUE"- "cWH"Что я могу приобрести в Школе Вождения?\n\
		"cBLUE"- "cWH"Что делать если я завалил экзамен?\n\
		"cBLUE"- "cWH"Как купить телефон?\n\
		"cBLUE"- "cWH"Как найти магазин одежды?\n\
		"cBLUE"- "cWH"Как купить скин?\n\
		"cBLUE"- "cWH"Как найти магазин аксессуаров?\n\
		"cBLUE"- "cWH"Как купить аксессуар?\n\
		"cBLUE"- "cWH"Что такое отель?\n\
		"cBLUE"- "cWH"Как купить дом или квартиру?\n\
		"cBLUE"- "cWH"Что делать если все дома и квартиры заняты?\n\
		"cBLUE"- "cWH"Как добраться до Риэлторского агенства?\n\
		"cBLUE"- "cWH"Как купить бизнес?\n\
		"cBLUE"- "cWH"Могу ли я иметь машину без дома или квартиры?\n\
		"cBLUE"- "cWH"Как купить машину?\n\
		"cBLUE"- "cWH"Как найти автосалон?\n\
		"cBLUE"- "cWH"Сколько машин я могу купить?", !"Выбрать", !"Назад");
}

stock show_dialog_faq_other(playerid)
{
	return SPD(playerid, DIALOG_SELECT_FAQ_OTHER, DIALOG_STYLE_LIST, !""cBLUE"Начальные работы", "\
		"cBLUE"- "cWH"Как вступить во фракцию?\n\
		"cBLUE"- "cWH"Как стать лидером?", !"Выбрать", !"Назад");
}

CMD:faq(playerid)
{
	return show_dialog_faq(playerid);
}

