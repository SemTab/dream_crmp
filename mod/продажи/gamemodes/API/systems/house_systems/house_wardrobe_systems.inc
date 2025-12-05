
#define POSITION_WARDROBE_INT_LOW		-2568.9121,396.5476,1.8119
#define POSITION_WARDROBE_INT_MEDIUM	1427.4343,-1888.9698,1117.8174
#define POSITION_WARDROBE_INT_HARD		15.1608,202.4514,1201.9314
#define POSITION_WARDROBE_INT_LUXE		-1130.5331,-1093.3226,1231.2622
#define POSITION_WARDROBE_INT_LUXE1		492.1710,2310.0166,1604.6016
#define POSITION_WARDROBE_INT_LUXE2		64.2172,444.2830,1201.9380

#define POSITION_WARDROBE_INT_POSELOK	153.7324,-252.8502,1201.9316


#define WARDROBE_SKIN_FIRST		1
#define WARDROBE_SKIN_TWO		2
#define WARDROBE_SKIN_THREE		3

#define WARDROBE_GUN_FIRST		1
#define WARDROBE_GUN_TWO		2
#define WARDROBE_GUN_THREE		3

#define WARDROBE_AKS_FIRST		1
#define WARDROBE_AKS_TWO		2
#define WARDROBE_AKS_THREE		3

#define WARDROBE_SKIN_PUT		1
#define WARDROBE_SKIN_INPUT		2

#define WARDROBE_GUN_PUT		1
#define WARDROBE_GUN_INPUT		2

#define WARDROBE_AKS_PUT 		1
#define WARDROBE_AKS_INPUT		2

stock create_wardrobe_position()
{
	CreateDynamic3DTextLabel(""cWH"Домашний Шкаф",-1, \
  		POSITION_WARDROBE_INT_LOW, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	create_circle_pickup_o(POSITION_WARDROBE_INT_LOW, TRIGGER_LBLUE);
	create_dynamic_area(POSITION_WARDROBE_INT_LOW, -1, 1, HOUSE_WARDROBE, 1.5);

	CreateDynamic3DTextLabel(""cWH"Домашний Шкаф",-1, \
  		POSITION_WARDROBE_INT_MEDIUM, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	create_circle_pickup_o(POSITION_WARDROBE_INT_MEDIUM, TRIGGER_LBLUE);
	create_dynamic_area(POSITION_WARDROBE_INT_MEDIUM, -1, 1, HOUSE_WARDROBE, 1.5);


	CreateDynamic3DTextLabel(""cWH"Домашний Шкаф",-1, \
  		POSITION_WARDROBE_INT_HARD, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	create_circle_pickup_o(POSITION_WARDROBE_INT_HARD, TRIGGER_LBLUE);
	create_dynamic_area(POSITION_WARDROBE_INT_HARD, -1, 1, HOUSE_WARDROBE, 1.5);

	CreateDynamic3DTextLabel(""cWH"Домашний Шкаф",-1, \
  		POSITION_WARDROBE_INT_LUXE, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	create_circle_pickup_o(POSITION_WARDROBE_INT_LUXE, TRIGGER_LBLUE);
	create_dynamic_area(POSITION_WARDROBE_INT_LUXE, -1, 1, HOUSE_WARDROBE, 1.5);

	CreateDynamic3DTextLabel(""cWH"Домашний Шкаф",-1, \
  		POSITION_WARDROBE_INT_LUXE1, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	create_circle_pickup_o(POSITION_WARDROBE_INT_LUXE1, TRIGGER_LBLUE);
	create_dynamic_area(POSITION_WARDROBE_INT_LUXE1, -1, 1, HOUSE_WARDROBE, 1.5);

	CreateDynamic3DTextLabel(""cWH"Домашний Шкаф",-1, \
  		POSITION_WARDROBE_INT_LUXE2, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	create_circle_pickup_o(POSITION_WARDROBE_INT_LUXE2, TRIGGER_LBLUE);
	create_dynamic_area(POSITION_WARDROBE_INT_LUXE2, -1, 1, HOUSE_WARDROBE, 1.5);

	CreateDynamic3DTextLabel(""cWH"Домашний Шкаф",-1, \
  		POSITION_WARDROBE_INT_POSELOK, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	create_circle_pickup_o(POSITION_WARDROBE_INT_POSELOK, TRIGGER_LBLUE);
	create_dynamic_area(POSITION_WARDROBE_INT_POSELOK, -1, 1, HOUSE_WARDROBE, 1.5);

	return true;
}

stock get_skin_wardrobe(playerid, type, h)
{
	new 
		skin[32];

	switch(type)
	{
		case WARDROBE_SKIN_FIRST:
		{
			if(House[h][wardrobe_skin_1] == -1 || House[h][wardrobe_skin_1] == 0)
			{
				skin = "Отсутствует";
			}
			else
			{
				format(skin,sizeof(skin),"%d",House[h][wardrobe_skin_1]);
			}
		}
		case WARDROBE_SKIN_TWO:
		{
			if(House[h][wardrobe_skin_2] == -1 || House[h][wardrobe_skin_2] == 0)
			{
				skin = "Отсутствует";
			}
			else
			{
				format(skin,sizeof(skin),"%d",House[h][wardrobe_skin_2]);
			}			
		}
		case WARDROBE_SKIN_THREE:
		{
			if(House[h][wardrobe_skin_3] == -1 || House[h][wardrobe_skin_3] == 0)
			{
				skin = "Отсутствует";
			}
			else
			{
				format(skin,sizeof(skin),"%d",House[h][wardrobe_skin_3]);
			}			
		}
	}
	return skin;
}

stock get_aks_wardrobe(playerid, type, h)
{
	new 
		skin[32];

	switch(type)
	{
		case WARDROBE_AKS_FIRST:
		{
			if(House[h][wardrobe_aks_1] == -1)
			{
				skin = "Отсутствует";
			}
			else
			{
				format(skin,sizeof(skin),"%d",House[h][wardrobe_aks_1]);
			}
		}
		case WARDROBE_AKS_TWO:
		{
			if(House[h][wardrobe_aks_2] == -1)
			{
				skin = "Отсутствует";
			}
			else
			{
				format(skin,sizeof(skin),"%d",House[h][wardrobe_aks_2]);
			}			
		}
		case WARDROBE_AKS_THREE:
		{
			if(House[h][wardrobe_aks_3] == -1)
			{
				skin = "Отсутствует";
			}
			else
			{
				format(skin,sizeof(skin),"%d",House[h][wardrobe_aks_3]);
			}			
		}
	}
	return skin;
}


stock get_weapon_wardrobe(playerid, type, h)
{
	new 
		weapon[32];

	switch(type)
	{
		case WARDROBE_GUN_FIRST:
		{
			if(House[h][wardrobe_gun_1] == -1)
			{
				weapon = "Отсутствует";
			}
			else
			{
				GetWeaponName(House[h][wardrobe_gun_1], weapon, 30);
			}
		}
		case WARDROBE_GUN_TWO:
		{
			if(House[h][wardrobe_gun_2] == -1)
			{
				weapon = "Отсутствует";
			}
			else
			{
				GetWeaponName(House[h][wardrobe_gun_2], weapon, 30);
			}			
		}
		case WARDROBE_GUN_THREE:
		{
			if(House[h][wardrobe_gun_3] == -1)
			{
				weapon = "Отсутствует";
			}
			else
			{
				GetWeaponName(House[h][wardrobe_gun_3], weapon, 30);
			}			
		}
	}
	return weapon;
}


stock show_wardrobe_menu(playerid)
{
	new 
		h = pData[playerid][pHouse];

	if(pData[playerid][pHouse] == -1)
		return SendErr(playerid, "У вас нет доступа к данному шкафу!");	

	if(GetPlayerVirtualWorld(playerid) != h)
		return SendErr(playerid, "Вы находитесь не в своем доме!");

	if(!House[h][wardrobe_status])
		return SendErr(playerid, "В доме нет шкафа!");




	static
		fmt_str[800],
		gunname[90];

    format(fmt_str, 800, "\
    "cGREY""cGREY"№\t"cGREY"Информация\t"cGREY"Количество\n\
    "cBLUE"- "cWH"Первая вешалка\t"cBLUE"%s одежда\n\
   	"cBLUE"- "cWH"Вторая вешалка\t"cBLUE"%s одежда\n\
   	"cBLUE"- "cWH"Третья вешалка\t"cBLUE"%s одежда\n\
   	"cBLUE"\t\n\
    "cBLUE"- "cWH"Первая полка\t"cBLUE"%s\t"cBLUE"%d патронов\n\
    "cBLUE"- "cWH"Вторая полка\t"cBLUE"%s\t"cBLUE"%d патронов\n\
    "cBLUE"- "cWH"Третья полка\t"cBLUE"%s\t"cBLUE"%d патронов\n\
    "cBLUE"\t\n\
    "cBLUE"- "cWH"Первая полка\t"cBLUE"%s аксессуар\n\
    "cBLUE"- "cWH"Вторая полка\t"cBLUE"%s аксессуар\n\
    "cBLUE"- "cWH"Третья полка\t"cBLUE"%s аксессуар\n\
    "cBLUE"\t\n\
    "cBLUE"- "cWH"Организационная одежда\t"cBLUE"Переодеться/Одеться\n\
    ", 
	get_skin_wardrobe(playerid, WARDROBE_SKIN_FIRST, h),
	get_skin_wardrobe(playerid, WARDROBE_SKIN_TWO, h),
	get_skin_wardrobe(playerid, WARDROBE_SKIN_THREE, h),
	get_weapon_wardrobe(playerid, WARDROBE_GUN_FIRST, h),
	House[h][wardrobe_gun_ammo_1],
	get_weapon_wardrobe(playerid, WARDROBE_GUN_TWO, h),
	House[h][wardrobe_gun_ammo_2],
	get_weapon_wardrobe(playerid, WARDROBE_GUN_THREE, h), House[h][wardrobe_gun_ammo_3]),

    get_aks_wardrobe(playerid, WARDROBE_AKS_FIRST, h),
    get_aks_wardrobe(playerid, WARDROBE_AKS_TWO, h),
    get_aks_wardrobe(playerid, WARDROBE_AKS_THREE, h);
    SPD(playerid, DIALOG_GENERAL_WARDROBE, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Шкаф дома", fmt_str, !"Выбрать", !"Закрыть"); 

    fmt_str[0] = EOS;


    return true;
}

stock show_skin_wardrobe_menu(playerid, id_house, type)
{

	switch(type)
	{
		case WARDROBE_SKIN_FIRST:
		{	
			show_skin_wadrobe_select(playerid, id_house, WARDROBE_SKIN_FIRST);

		}
		case WARDROBE_SKIN_TWO:
		{
			show_skin_wadrobe_select(playerid, id_house, WARDROBE_SKIN_TWO);	
		}
		case WARDROBE_SKIN_THREE:
		{
			show_skin_wadrobe_select(playerid, id_house, WARDROBE_SKIN_THREE);
		}
	}


	return true;
}

stock show_aks_wardrobe_menu(playerid, id_house, type)
{

	switch(type)
	{
		case WARDROBE_AKS_FIRST:
		{	
			show_aks_wadrobe_select(playerid, id_house, WARDROBE_AKS_FIRST);

		}
		case WARDROBE_AKS_TWO:
		{
			show_aks_wadrobe_select(playerid, id_house, WARDROBE_AKS_TWO);	
		}
		case WARDROBE_AKS_THREE:
		{
			show_aks_wadrobe_select(playerid, id_house, WARDROBE_AKS_THREE);
		}
	}


	return true;
}

stock show_aks_wadrobe_select(playerid, id_house, type)
{
	new 
		fmt_str[400];

	switch(type)
	{
		case WARDROBE_AKS_FIRST:
		{	
		    format(fmt_str, 400, "\
		    "cGREY"Тип\t"cGREY"Информация\n\
		    "cBLUE"- "cWH"Положить аксессуар в шкаф\t"cBLUE"Повесить\n\
		    "cBLUE"- "cWH"Забрать аксессуар с первой полки\t"cBLUE"%s аксессуар\n\
		    "cBLUE"- "cWH"Выкинуть аксессуар\t"cBLUE"Выкинуть", get_aks_wardrobe(playerid, WARDROBE_AKS_FIRST, id_house));
		    SPD(playerid, DIALOG_WARDROBE_POLKA_AKS_1, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Шкаф", fmt_str, !"Выбрать", !"Закрыть"); 	

		}
		case WARDROBE_AKS_TWO:
		{
		    format(fmt_str, 400, "\
		    "cGREY"Тип\t"cGREY"Информация\n\
		    "cBLUE"- "cWH"Положить аксессуар в шкаф\t"cBLUE"Повесить\n\
		    "cBLUE"- "cWH"Забрать аксессуар со второй полки\t"cBLUE"%s аксессуар\n\
		    "cBLUE"- "cWH"Выкинуть аксессуар\t"cBLUE"Выкинуть", get_aks_wardrobe(playerid, WARDROBE_AKS_TWO, id_house));
		    SPD(playerid, DIALOG_WARDROBE_POLKA_AKS_2, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Шкаф", fmt_str, !"Выбрать", !"Закрыть"); 	
		}
		case WARDROBE_AKS_THREE:
		{
		    format(fmt_str, 400, "\
		    "cGREY"Тип\t"cGREY"Информация\n\
		    "cBLUE"- "cWH"Положить аксессуар в шкаф\t"cBLUE"Повесить\n\
		    "cBLUE"- "cWH"Забрать аксессуар с третьей полки\t"cBLUE"%s аксессуар\n\
		    "cBLUE"- "cWH"Выкинуть аксессуар\t"cBLUE"Выкинуть", get_aks_wardrobe(playerid, WARDROBE_AKS_THREE, id_house));

		    SPD(playerid, DIALOG_WARDROBE_POLKA_AKS_3, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Шкаф", fmt_str, !"Выбрать", !"Закрыть"); 	
		}
	}
	return true;

}


stock show_skin_wadrobe_select(playerid, id_house, type)
{
	new 
		fmt_str[400];

	switch(type)
	{
		case WARDROBE_SKIN_FIRST:
		{	
		    format(fmt_str, 400, "\
		    "cGREY"Тип\t"cGREY"Информация\n\
		    "cBLUE"- "cWH"Повесить одежду в шкаф\t"cBLUE"Повесить\n\
		    "cBLUE"- "cWH"Забрать одежду с первой вешалки\t"cBLUE"%s одежда\n\
		    "cBLUE"- "cWH"Выкинуть одежду\t"cBLUE"Выкинуть", get_skin_wardrobe(playerid, WARDROBE_SKIN_FIRST, id_house));
		    SPD(playerid, DIALOG_WARDROBE_POLKA_1, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Шкаф", fmt_str, !"Выбрать", !"Закрыть"); 	

		}
		case WARDROBE_SKIN_TWO:
		{
		    format(fmt_str, 400, "\
		    "cGREY"Тип\t"cGREY"Информация\n\
		    "cBLUE"- "cWH"Повесить одежду в шкаф\t"cBLUE"Повесить\n\
		    "cBLUE"- "cWH"Забрать одежду со второй вешалки\t"cBLUE"%s одежда\n\
		    "cBLUE"- "cWH"Выкинуть одежду\t"cBLUE"Выкинуть", get_skin_wardrobe(playerid, WARDROBE_SKIN_TWO, id_house));
		    SPD(playerid, DIALOG_WARDROBE_POLKA_2, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Шкаф", fmt_str, !"Выбрать", !"Закрыть"); 	
		}
		case WARDROBE_SKIN_THREE:
		{
		    format(fmt_str, 400, "\
		    "cGREY"Тип\t"cGREY"Информация\n\
		    "cBLUE"- "cWH"Повесить одежду в шкаф\t"cBLUE"Повесить\n\
		    "cBLUE"- "cWH"Забрать одежду с третье вешалки\t"cBLUE"%s одежда\n\
		    "cBLUE"- "cWH"Выкинуть одежду\t"cBLUE"Выкинуть", get_skin_wardrobe(playerid, WARDROBE_SKIN_THREE, id_house));

		    SPD(playerid, DIALOG_WARDROBE_POLKA_3, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Шкаф", fmt_str, !"Выбрать", !"Закрыть"); 	
		}
	}
	return true;

}

stock select_aks_player(playerid, type)
{
	switch(type)
	{
		case WARDROBE_AKS_FIRST:
		{
			SPD(playerid, DIALOG_SELECT_WARDROBE_P_1_1, DIALOG_STYLE_LIST, ""cBLUE"Шкаф", \
			""cBLUE"1."cWH" Положить кепку\n\
			"cBLUE"2."cWH" Положить маску\n\
			"cBLUE"3."cWH" Положить рюкзак", !"Выбрать", !"Закрыть");
		}
		case WARDROBE_AKS_TWO:
		{
			SPD(playerid, DIALOG_SELECT_WARDROBE_P_1_2, DIALOG_STYLE_LIST, ""cBLUE"Шкаф", \
			""cBLUE"1."cWH" Положить кепку\n\
			"cBLUE"2."cWH" Положить маску\n\
			"cBLUE"3."cWH" Положить рюкзак", !"Выбрать", !"Закрыть");
		}	
		case WARDROBE_AKS_THREE:
		{
			SPD(playerid, DIALOG_SELECT_WARDROBE_P_1_3, DIALOG_STYLE_LIST, ""cBLUE"Шкаф", \
			""cBLUE"1."cWH" Положить кепку\n\
			"cBLUE"2."cWH" Положить маску\n\
			"cBLUE"3."cWH" Положить рюкзак", !"Выбрать", !"Закрыть");
		}		
	}

	return true;
}

stock skin_aks_1(playerid, id_house, type)
{

	switch(type)
	{
		case WARDROBE_AKS_PUT:
		{
			if(House[id_house][wardrobe_aks_1] != -1)
			{
				show_aks_wadrobe_select(playerid, id_house, WARDROBE_AKS_FIRST);
				return SendErr(playerid, "Полка уже занята, Вы не можете положить аксессуар на полку!");
			}

			new 
				id_skin = GetPVarIntNew(playerid, "type_select_aks");

			House[id_house][wardrobe_aks_1] = id_skin;

			if(!GetPVarIntNew(playerid, "type_select_aks_id"))
			{
				pData[playerid][pSlotItem][0] = -1;
				RemovePlayerAttachedObject(playerid, 1);
			}
			else if(GetPVarIntNew(playerid, "type_select_aks_id") == 2)
			{
				pData[playerid][pSlotItem][2] = -1;
				RemovePlayerAttachedObject(playerid, 3);
			}
			else if(GetPVarIntNew(playerid, "type_select_aks_id") == 3)
			{
				pData[playerid][pSlotItem][3] = -1;
				RemovePlayerAttachedObject(playerid, 4);
			}

			SendSucc(playerid, "Вы положили аксессуар в шкаф!");

		}
		case WARDROBE_AKS_INPUT:
		{
			if(House[id_house][wardrobe_aks_1] == -1)
			{
				show_aks_wadrobe_select(playerid, id_house, WARDROBE_SKIN_FIRST);
				return SendErr(playerid, "На полке ничего нет!");
			}

			
			if(House[id_house][wardrobe_aks_1] == 10998 || House[id_house][wardrobe_aks_1] == 10999 || House[id_house][wardrobe_aks_1] == 11000 || House[id_house][wardrobe_aks_1] == 11001
			|| House[id_house][wardrobe_aks_1] == 18156 || House[id_house][wardrobe_aks_1] == 18157)
			{
				if(pData[playerid][pSlotItem][0] != -1)
				{
					SetPVarIntNew(playerid, "id_aks_home", pData[playerid][pSlotItem][0]);

					pData[playerid][pSlotItem][0] = House[id_house][wardrobe_aks_1];
					House[id_house][wardrobe_aks_1] = GetPVarIntNew(playerid, "id_aks_home");

					DeletePVarNew(playerid, "id_aks_home");
				}
				else
				{
					pData[playerid][pSlotItem][0] = House[id_house][wardrobe_aks_1];
					House[id_house][wardrobe_aks_1] = -1;
				}
			}	
			else if(House[id_house][wardrobe_aks_1] == 10971 || House[id_house][wardrobe_aks_1] == 10973 || House[id_house][wardrobe_aks_1] == 10974 || House[id_house][wardrobe_aks_1] == 10975
			|| House[id_house][wardrobe_aks_1] == 10976 || House[id_house][wardrobe_aks_1] == 10977 || House[id_house][wardrobe_aks_1] == 10978 || House[id_house][wardrobe_aks_1] == 10979 
			|| House[id_house][wardrobe_aks_1] == 10980 || House[id_house][wardrobe_aks_1] == 10981 || House[id_house][wardrobe_aks_1] == 10982
			|| House[id_house][wardrobe_aks_1] == 18158 || House[id_house][wardrobe_aks_1] == 18159 || House[id_house][wardrobe_aks_1] == 18160)
			{
				if(pData[playerid][pSlotItem][2] != -1)
				{
					SetPVarIntNew(playerid, "id_aks_home", pData[playerid][pSlotItem][2]);

					pData[playerid][pSlotItem][2] = House[id_house][wardrobe_aks_1];
					House[id_house][wardrobe_aks_1] = GetPVarIntNew(playerid, "id_aks_home");

					DeletePVarNew(playerid, "id_aks_home");
				}
				else
				{
					pData[playerid][pSlotItem][2] = House[id_house][wardrobe_aks_1];
					House[id_house][wardrobe_aks_1] = -1;
				}
			}	
			else if(House[id_house][wardrobe_aks_1] == 11002 || House[id_house][wardrobe_aks_1] == 11003 || House[id_house][wardrobe_aks_1] == 11004 || House[id_house][wardrobe_aks_1] == 11005
			|| House[id_house][wardrobe_aks_1] == 11006 || House[id_house][wardrobe_aks_1] == 11007)
			{
				if(pData[playerid][pSlotItem][3] != -1)
				{
					SetPVarIntNew(playerid, "id_aks_home", pData[playerid][pSlotItem][3]);

					pData[playerid][pSlotItem][3] = House[id_house][wardrobe_aks_1];
					House[id_house][wardrobe_aks_1] = GetPVarIntNew(playerid, "id_aks_home");

					DeletePVarNew(playerid, "id_aks_home");
				}
				else
				{
					pData[playerid][pSlotItem][3] = House[id_house][wardrobe_aks_1];
					House[id_house][wardrobe_aks_1] = -1;
				}
			}	

			AttachAcsToPlayer(playerid, GetPlayerSkin(playerid));
			SendSucc(playerid, "Вы взяли аксессуар со шкафа!");	
			
		}

	}
	ApplyAnimation(playerid, "PED", "ROADCROSS", 4.1, 0, 0, 0, 0, 0);
	save_house(id_house);
	show_wardrobe_menu(playerid);
	return true;
}

stock skin_aks_2(playerid, id_house, type)
{

	switch(type)
	{
		case WARDROBE_AKS_PUT:
		{
			if(House[id_house][wardrobe_aks_2] != -1)
			{
				show_aks_wadrobe_select(playerid, id_house, WARDROBE_AKS_FIRST);
				return SendErr(playerid, "Полка уже занята, Вы не можете положить аксессуар на полку!");
			}

			new 
				id_skin = GetPVarIntNew(playerid, "type_select_aks");

			House[id_house][wardrobe_aks_2] = id_skin;

			if(!GetPVarIntNew(playerid, "type_select_aks_id"))
			{
				pData[playerid][pSlotItem][0] = -1;
				RemovePlayerAttachedObject(playerid, 1);
			}
			else if(GetPVarIntNew(playerid, "type_select_aks_id") == 2)
			{
				pData[playerid][pSlotItem][2] = -1;
				RemovePlayerAttachedObject(playerid, 3);
			}
			else if(GetPVarIntNew(playerid, "type_select_aks_id") == 3)
			{
				pData[playerid][pSlotItem][3] = -1;
				RemovePlayerAttachedObject(playerid, 4);
			}

			SendSucc(playerid, "Вы положили аксессуар в шкаф!");

		}
		case WARDROBE_AKS_INPUT:
		{
			if(House[id_house][wardrobe_aks_2] == -1)
			{
				show_aks_wadrobe_select(playerid, id_house, WARDROBE_SKIN_FIRST);
				return SendErr(playerid, "На полке ничего нет!");
			}

			
			if(House[id_house][wardrobe_aks_2] == 10998 || House[id_house][wardrobe_aks_2] == 10999 || House[id_house][wardrobe_aks_2] == 11000 || House[id_house][wardrobe_aks_2] == 11001
			|| House[id_house][wardrobe_aks_2] == 18156 || House[id_house][wardrobe_aks_2] == 18157)
			{
				if(pData[playerid][pSlotItem][0] != -1)
				{
					SetPVarIntNew(playerid, "id_aks_home", pData[playerid][pSlotItem][0]);

					pData[playerid][pSlotItem][0] = House[id_house][wardrobe_aks_2];
					House[id_house][wardrobe_aks_2] = GetPVarIntNew(playerid, "id_aks_home");

					DeletePVarNew(playerid, "id_aks_home");
				}
				else
				{
					pData[playerid][pSlotItem][0] = House[id_house][wardrobe_aks_2];
					House[id_house][wardrobe_aks_2] = -1;
				}
			}	
			else if(House[id_house][wardrobe_aks_2] == 10971 || House[id_house][wardrobe_aks_2] == 10973 || House[id_house][wardrobe_aks_2] == 10974 || House[id_house][wardrobe_aks_2] == 10975
			|| House[id_house][wardrobe_aks_2] == 10976 || House[id_house][wardrobe_aks_2] == 10977 || House[id_house][wardrobe_aks_2] == 10978 || House[id_house][wardrobe_aks_2] == 10979 
			|| House[id_house][wardrobe_aks_2] == 10980 || House[id_house][wardrobe_aks_2] == 10981 || House[id_house][wardrobe_aks_2] == 10982
			|| House[id_house][wardrobe_aks_2] == 18158 || House[id_house][wardrobe_aks_2] == 18159 || House[id_house][wardrobe_aks_2] == 18160)
			{
				if(pData[playerid][pSlotItem][2] != -1)
				{
					SetPVarIntNew(playerid, "id_aks_home", pData[playerid][pSlotItem][2]);

					pData[playerid][pSlotItem][2] = House[id_house][wardrobe_aks_2];
					House[id_house][wardrobe_aks_2] = GetPVarIntNew(playerid, "id_aks_home");

					DeletePVarNew(playerid, "id_aks_home");
				}
				else
				{
					pData[playerid][pSlotItem][2] = House[id_house][wardrobe_aks_2];
					House[id_house][wardrobe_aks_2] = -1;
				}
			}	
			else if(House[id_house][wardrobe_aks_2] == 11002 || House[id_house][wardrobe_aks_2] == 11003 || House[id_house][wardrobe_aks_2] == 11004 || House[id_house][wardrobe_aks_2] == 11005
			|| House[id_house][wardrobe_aks_2] == 11006 || House[id_house][wardrobe_aks_2] == 11007)
			{
				if(pData[playerid][pSlotItem][3] != -1)
				{
					SetPVarIntNew(playerid, "id_aks_home", pData[playerid][pSlotItem][3]);

					pData[playerid][pSlotItem][3] = House[id_house][wardrobe_aks_2];
					House[id_house][wardrobe_aks_2] = GetPVarIntNew(playerid, "id_aks_home");

					DeletePVarNew(playerid, "id_aks_home");
				}
				else
				{
					pData[playerid][pSlotItem][3] = House[id_house][wardrobe_aks_2];
					House[id_house][wardrobe_aks_2] = -1;
				}
			}	

			AttachAcsToPlayer(playerid, GetPlayerSkin(playerid));
			SendSucc(playerid, "Вы взяли аксессуар со шкафа!");	
			
		}

	}
	ApplyAnimation(playerid, "PED", "ROADCROSS", 4.1, 0, 0, 0, 0, 0);
	save_house(id_house);
	show_wardrobe_menu(playerid);
	return true;
}

stock skin_aks_3(playerid, id_house, type)
{

	switch(type)
	{
		case WARDROBE_AKS_PUT:
		{
			if(House[id_house][wardrobe_aks_3] != -1)
			{
				show_aks_wadrobe_select(playerid, id_house, WARDROBE_AKS_FIRST);
				return SendErr(playerid, "Полка уже занята, Вы не можете положить аксессуар на полку!");
			}

			new 
				id_skin = GetPVarIntNew(playerid, "type_select_aks");

			House[id_house][wardrobe_aks_3] = id_skin;

			if(!GetPVarIntNew(playerid, "type_select_aks_id"))
			{
				pData[playerid][pSlotItem][0] = -1;
				RemovePlayerAttachedObject(playerid, 1);
			}
			else if(GetPVarIntNew(playerid, "type_select_aks_id") == 2)
			{
				pData[playerid][pSlotItem][2] = -1;
				RemovePlayerAttachedObject(playerid, 3);
			}
			else if(GetPVarIntNew(playerid, "type_select_aks_id") == 3)
			{
				pData[playerid][pSlotItem][3] = -1;
				RemovePlayerAttachedObject(playerid, 4);
			}

			SendSucc(playerid, "Вы положили аксессуар в шкаф!");

		}
		case WARDROBE_AKS_INPUT:
		{
			if(House[id_house][wardrobe_aks_3] == -1)
			{
				show_aks_wadrobe_select(playerid, id_house, WARDROBE_SKIN_FIRST);
				return SendErr(playerid, "На полке ничего нет!");
			}

			
			if(House[id_house][wardrobe_aks_3] == 10998 || House[id_house][wardrobe_aks_3] == 10999 || House[id_house][wardrobe_aks_3] == 11000 || House[id_house][wardrobe_aks_3] == 11001
			|| House[id_house][wardrobe_aks_3] == 18156 || House[id_house][wardrobe_aks_3] == 18157)
			{
				if(pData[playerid][pSlotItem][0] != -1)
				{
					SetPVarIntNew(playerid, "id_aks_home", pData[playerid][pSlotItem][0]);

					pData[playerid][pSlotItem][0] = House[id_house][wardrobe_aks_3];
					House[id_house][wardrobe_aks_3] = GetPVarIntNew(playerid, "id_aks_home");

					DeletePVarNew(playerid, "id_aks_home");
				}
				else
				{
					pData[playerid][pSlotItem][0] = House[id_house][wardrobe_aks_3];
					House[id_house][wardrobe_aks_3] = -1;
				}
			}	
			else if(House[id_house][wardrobe_aks_3] == 10971 || House[id_house][wardrobe_aks_3] == 10973 || House[id_house][wardrobe_aks_3] == 10974 || House[id_house][wardrobe_aks_3] == 10975
			|| House[id_house][wardrobe_aks_3] == 10976 || House[id_house][wardrobe_aks_3] == 10977 || House[id_house][wardrobe_aks_3] == 10978 || House[id_house][wardrobe_aks_3] == 10979 
			|| House[id_house][wardrobe_aks_3] == 10980 || House[id_house][wardrobe_aks_3] == 10981 || House[id_house][wardrobe_aks_3] == 10982
			|| House[id_house][wardrobe_aks_3] == 18158 || House[id_house][wardrobe_aks_3] == 18159 || House[id_house][wardrobe_aks_3] == 18160)
			{
				if(pData[playerid][pSlotItem][2] != -1)
				{
					SetPVarIntNew(playerid, "id_aks_home", pData[playerid][pSlotItem][2]);

					pData[playerid][pSlotItem][2] = House[id_house][wardrobe_aks_3];
					House[id_house][wardrobe_aks_3] = GetPVarIntNew(playerid, "id_aks_home");

					DeletePVarNew(playerid, "id_aks_home");
				}
				else
				{
					pData[playerid][pSlotItem][2] = House[id_house][wardrobe_aks_3];
					House[id_house][wardrobe_aks_3] = -1;
				}
			}	
			else if(House[id_house][wardrobe_aks_3] == 11002 || House[id_house][wardrobe_aks_3] == 11003 || House[id_house][wardrobe_aks_3] == 11004 || House[id_house][wardrobe_aks_3] == 11005
			|| House[id_house][wardrobe_aks_3] == 11006 || House[id_house][wardrobe_aks_3] == 11007)
			{
				if(pData[playerid][pSlotItem][3] != -1)
				{
					SetPVarIntNew(playerid, "id_aks_home", pData[playerid][pSlotItem][3]);

					pData[playerid][pSlotItem][3] = House[id_house][wardrobe_aks_3];
					House[id_house][wardrobe_aks_3] = GetPVarIntNew(playerid, "id_aks_home");

					DeletePVarNew(playerid, "id_aks_home");
				}
				else
				{
					pData[playerid][pSlotItem][3] = House[id_house][wardrobe_aks_3];
					House[id_house][wardrobe_aks_3] = -1;
				}
			}	

			AttachAcsToPlayer(playerid, GetPlayerSkin(playerid));
			SendSucc(playerid, "Вы взяли аксессуар со шкафа!");	
			
		}

	}
	ApplyAnimation(playerid, "PED", "ROADCROSS", 4.1, 0, 0, 0, 0, 0);
	save_house(id_house);
	show_wardrobe_menu(playerid);
	return true;
}

stock aks_drop_wardrobe(playerid, id_house, type)
{
	switch(type)
	{
		case WARDROBE_AKS_FIRST:
		{
			if(House[id_house][wardrobe_aks_1] == -1)
				return SendErr(playerid, "На полке нет аксессуара, чтобы его выкидывать!");

			House[id_house][wardrobe_aks_1] = -1;
		}
		case WARDROBE_AKS_TWO:
		{
			if(House[id_house][wardrobe_aks_2] == -1)
				return SendErr(playerid, "На полке нет аксессуара, чтобы его выкидывать!");

			House[id_house][wardrobe_aks_2] = -1;
		}
		case WARDROBE_AKS_THREE:
		{
			if(House[id_house][wardrobe_aks_3] == -1)
				return SendErr(playerid, "На полке нет аксессуара, чтобы его выкидывать!");

			House[id_house][wardrobe_aks_3] = -1;
		}
	}
	SendSucc(playerid, "Вы успешно выкинули аксессуар с полки!");	
	save_house(id_house);
	show_wardrobe_menu(playerid);
	return true;
}

stock skin_wardrobe_1(playerid, id_house, type)
{

	switch(type)
	{
		case WARDROBE_SKIN_PUT:
		{
			if(House[id_house][wardrobe_skin_1] != -1 && House[id_house][wardrobe_skin_1] != 0)
			{
				show_skin_wadrobe_select(playerid, id_house, WARDROBE_SKIN_FIRST);
				return SendErr(playerid, "Вешалка уже занята, Вы не можете повесить туда одежду");
			}

			new 
				id_skin = GetPlayerSkin(playerid);

			House[id_house][wardrobe_skin_1] = id_skin;

			if(pData[playerid][pSex] == 2)
			{
				if(pData[playerid][pSkin] == 140)
				{
					show_skin_wadrobe_select(playerid, id_house, WARDROBE_SKIN_FIRST);
					return SendErr(playerid, "На вас нет одежды, чтобы повесить её!");
				}
				if(GetPVarIntNew(playerid, "askin"))
				{
					show_skin_wadrobe_select(playerid, id_house, WARDROBE_SKIN_FIRST);
					return SendErr(playerid, "Данную одежду нельзя повесить на вешалку!");
				}

				if(pData[playerid][pFractionSkin] == id_skin)
				{
					show_skin_wadrobe_select(playerid, id_house, WARDROBE_SKIN_FIRST);
					return SendErr(playerid, "Данную одежду нельзя повесить на вешалку!");					
				}

				pData[playerid][pSkin] = 140;
				UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);
				SetPlayerSkin(playerid, 140);	
			}
			else
			{
				if(pData[playerid][pSkin] == 97)
				{
					show_skin_wadrobe_select(playerid, id_house, WARDROBE_SKIN_FIRST);
					return SendErr(playerid, "На вас нет одежды, чтобы повесить её!");
				}
				if(GetPVarIntNew(playerid, "askin"))
				{
					show_skin_wadrobe_select(playerid, id_house, WARDROBE_SKIN_FIRST);
					return SendErr(playerid, "Данную одежду нельзя повесить на вешалку!");
				}

				if(pData[playerid][pFractionSkin] == id_skin)
				{
					show_skin_wadrobe_select(playerid, id_house, WARDROBE_SKIN_FIRST);
					return SendErr(playerid, "Данную одежду нельзя повесить на вешалку!");				
				}

				pData[playerid][pSkin] = 97;
				UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);

				SetPlayerSkin(playerid, 97);
			}

			SendSucc(playerid, "Вы повесили свою одежду в шкаф!");

		}
		case WARDROBE_SKIN_INPUT:
		{
			if(House[id_house][wardrobe_skin_1] == -1 || House[id_house][wardrobe_skin_1] == 0)
			{
				show_skin_wadrobe_select(playerid, id_house, WARDROBE_SKIN_FIRST);
				return SendErr(playerid, "На вешалке ничего нет!");
			}

			new 
				id_skin = GetPlayerSkin(playerid);

			if(pData[playerid][pSex] == 2)
			{
				if(pData[playerid][pSkin] == 140)
				{
					pData[playerid][pSkin] = House[id_house][wardrobe_skin_1];
					UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);
					SetPlayerSkin(playerid, pData[playerid][pSkin]);	

					House[id_house][wardrobe_skin_1] = -1;				
				}
				else
				{
					pData[playerid][pSkin] = House[id_house][wardrobe_skin_1];

					House[id_house][wardrobe_skin_1] = id_skin;

					UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);
					SetPlayerSkin(playerid, pData[playerid][pSkin]);	

					SendSucc(playerid, "Вы поменяли одежду!");					
				}
			}
			else
			{
				if(pData[playerid][pSkin] == 97)
				{
					pData[playerid][pSkin] = House[id_house][wardrobe_skin_1];
					UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);
					SetPlayerSkin(playerid, pData[playerid][pSkin]);		

					House[id_house][wardrobe_skin_1] = -1;				
				}
				else
				{
					pData[playerid][pSkin] = House[id_house][wardrobe_skin_1];

					House[id_house][wardrobe_skin_1] = id_skin;

					UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);
					SetPlayerSkin(playerid, pData[playerid][pSkin]);	

					SendSucc(playerid, "Вы поменяли одежду!");					
				}
			}			

		}
	}
	ApplyAnimation(playerid, "PED", "ROADCROSS", 4.1, 0, 0, 0, 0, 0);
	save_house(id_house);
	show_wardrobe_menu(playerid);
	return true;
}

stock skin_wardrobe_2(playerid, id_house, type)
{

	switch(type)
	{
		case WARDROBE_SKIN_PUT:
		{
			if(House[id_house][wardrobe_skin_2] != -1 && House[id_house][wardrobe_skin_2] != 0)
			{
				show_skin_wadrobe_select(playerid, id_house, WARDROBE_SKIN_TWO);
				return SendErr(playerid, "Вешалка уже занята, Вы не можете повесить туда одежду");
			}

			new 
				id_skin = GetPlayerSkin(playerid);

			House[id_house][wardrobe_skin_2] = id_skin;

			if(pData[playerid][pSex] == 2)
			{
				if(pData[playerid][pSkin] == 140)
				{
					show_skin_wadrobe_select(playerid, id_house, WARDROBE_SKIN_TWO);
					return SendErr(playerid, "На вас нет одежды, чтобы повесить её!");
				}
				if(GetPVarIntNew(playerid, "askin"))
				{
					show_skin_wadrobe_select(playerid, id_house, WARDROBE_SKIN_TWO);
					return SendErr(playerid, "Данную одежду нельзя повесить на вешалку!");
				}

				if(pData[playerid][pFractionSkin] == id_skin)
				{
					show_skin_wadrobe_select(playerid, id_house, WARDROBE_SKIN_TWO);
					return SendErr(playerid, "Данную одежду нельзя повесить на вешалку!");			
				}

				pData[playerid][pSkin] = 140;
				UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);
				SetPlayerSkin(playerid, 140);	
			}
			else
			{
				if(pData[playerid][pSkin] == 97)
				{
					show_skin_wadrobe_select(playerid, id_house, WARDROBE_SKIN_TWO);
					return SendErr(playerid, "На вас нет одежды, чтобы повесить её!");
				}
				if(GetPVarIntNew(playerid, "askin"))
				{
					show_skin_wadrobe_select(playerid, id_house, WARDROBE_SKIN_TWO);
					return SendErr(playerid, "Данную одежду нельзя повесить на вешалку!");
				}

				if(pData[playerid][pFractionSkin] == id_skin)
				{
					show_skin_wadrobe_select(playerid, id_house, WARDROBE_SKIN_TWO);
					return SendErr(playerid, "Данную одежду нельзя повесить на вешалку!");		
				}

				pData[playerid][pSkin] = 97;
				UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);

				SetPlayerSkin(playerid, 97);
			}

			SendSucc(playerid, "Вы повесили свою одежду в шкаф!");

		}
		case WARDROBE_SKIN_INPUT:
		{
			if(House[id_house][wardrobe_skin_2] == -1 || House[id_house][wardrobe_skin_2] == 0)
			{
				show_skin_wadrobe_select(playerid, id_house, WARDROBE_SKIN_TWO);
				return SendErr(playerid, "На вешалке ничего нет!");
			}

			new 
				id_skin = GetPlayerSkin(playerid);

			if(pData[playerid][pSex] == 2)
			{
				if(pData[playerid][pSkin] == 140)
				{
					pData[playerid][pSkin] = House[id_house][wardrobe_skin_2];
					UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);
					SetPlayerSkin(playerid, pData[playerid][pSkin]);	

					House[id_house][wardrobe_skin_2] = -1;					
				}
				else
				{
					pData[playerid][pSkin] = House[id_house][wardrobe_skin_2];

					House[id_house][wardrobe_skin_2] = id_skin;

					UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);
					SetPlayerSkin(playerid, pData[playerid][pSkin]);	

					SendSucc(playerid, "Вы поменяли одежду!");					
				}
			}
			else
			{
				if(pData[playerid][pSkin] == 97)
				{
					pData[playerid][pSkin] = House[id_house][wardrobe_skin_2];
					UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);
					SetPlayerSkin(playerid, pData[playerid][pSkin]);

					House[id_house][wardrobe_skin_2] = -1;						
				}
				else
				{
					pData[playerid][pSkin] = House[id_house][wardrobe_skin_2];

					House[id_house][wardrobe_skin_2] = id_skin;

					UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);
					SetPlayerSkin(playerid, pData[playerid][pSkin]);	

					SendSucc(playerid, "Вы поменяли одежду!");					
				}
			}			

		}
	}
	ApplyAnimation(playerid, "PED", "ROADCROSS", 4.1, 0, 0, 0, 0, 0);
	save_house(id_house);
	show_wardrobe_menu(playerid);
	return true;
}

stock skin_wardrobe_3(playerid, id_house, type)
{

	switch(type)
	{
		case WARDROBE_SKIN_PUT:
		{
			if(House[id_house][wardrobe_skin_3] != -1 && House[id_house][wardrobe_skin_3] != 0)
			{
				show_skin_wadrobe_select(playerid, id_house, WARDROBE_SKIN_THREE);
				return SendErr(playerid, "Вешалка уже занята, Вы не можете повесить туда одежду");
			}

			new 
				id_skin = GetPlayerSkin(playerid);

			House[id_house][wardrobe_skin_3] = id_skin;

			if(pData[playerid][pSex] == 2)
			{
				if(pData[playerid][pSkin] == 140)
				{
					show_skin_wadrobe_select(playerid, id_house, WARDROBE_SKIN_THREE);
					return SendErr(playerid, "На вас нет одежды, чтобы повесить её!");
				}
				if(GetPVarIntNew(playerid, "askin"))
				{
					show_skin_wadrobe_select(playerid, id_house, WARDROBE_SKIN_THREE);
					return SendErr(playerid, "Данную одежду нельзя повесить на вешалку!");
				}

				if(pData[playerid][pFractionSkin] == id_skin)
				{
					show_skin_wadrobe_select(playerid, id_house, WARDROBE_SKIN_THREE);
					return SendErr(playerid, "Данную одежду нельзя повесить на вешалку!");	
				}

				pData[playerid][pSkin] = 140;
				UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);
				SetPlayerSkin(playerid, 140);	
			}
			else
			{
				if(pData[playerid][pSkin] == 97)
				{
					show_skin_wadrobe_select(playerid, id_house, WARDROBE_SKIN_THREE);
					return SendErr(playerid, "На вас нет одежды, чтобы повесить её!");
				}
				if(GetPVarIntNew(playerid, "askin"))
				{
					show_skin_wadrobe_select(playerid, id_house, WARDROBE_SKIN_THREE);
					return SendErr(playerid, "Данную одежду нельзя повесить на вешалку!");
				}

				if(pData[playerid][pFractionSkin] == id_skin)
				{
					show_skin_wadrobe_select(playerid, id_house, WARDROBE_SKIN_THREE);
					return SendErr(playerid, "Данную одежду нельзя повесить на вешалку!");
				}

				pData[playerid][pSkin] = 97;
				UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);

				SetPlayerSkin(playerid, 97);
			}

			SendSucc(playerid, "Вы повесили свою одежду в шкаф!");

		}
		case WARDROBE_SKIN_INPUT:
		{
			if(House[id_house][wardrobe_skin_3] == -1 || House[id_house][wardrobe_skin_3] == 0)
			{
				show_skin_wadrobe_select(playerid, id_house, WARDROBE_SKIN_THREE);
				return SendErr(playerid, "На вешалке ничего нет!");
			}

			new 
				id_skin = GetPlayerSkin(playerid);

			if(pData[playerid][pSex] == 2)
			{
				if(pData[playerid][pSkin] == 140)
				{
					pData[playerid][pSkin] = House[id_house][wardrobe_skin_3];
					UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);
					SetPlayerSkin(playerid, pData[playerid][pSkin]);

					House[id_house][wardrobe_skin_3] = -1;						
				}
				else
				{
					pData[playerid][pSkin] = House[id_house][wardrobe_skin_3];

					House[id_house][wardrobe_skin_3] = id_skin;

					UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);
					SetPlayerSkin(playerid, pData[playerid][pSkin]);	

					SendSucc(playerid, "Вы поменяли одежду!");					
				}
			}
			else
			{
				if(pData[playerid][pSkin] == 97)
				{
					pData[playerid][pSkin] = House[id_house][wardrobe_skin_3];
					UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);
					SetPlayerSkin(playerid, pData[playerid][pSkin]);	

					House[id_house][wardrobe_skin_3] = -1;					
				}
				else
				{
					pData[playerid][pSkin] = House[id_house][wardrobe_skin_3];

					House[id_house][wardrobe_skin_3] = id_skin;

					UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);
					SetPlayerSkin(playerid, pData[playerid][pSkin]);	

					SendSucc(playerid, "Вы поменяли одежду!");					
				}
			}			

		}
	}
	ApplyAnimation(playerid, "PED", "ROADCROSS", 4.1, 0, 0, 0, 0, 0);
	save_house(id_house);
	show_wardrobe_menu(playerid);
	return true;
}


stock skin_drop_wardrobe(playerid, id_house, type)
{
	switch(type)
	{
		case WARDROBE_SKIN_FIRST:
		{
			if(House[id_house][wardrobe_skin_1] == -1 || House[id_house][wardrobe_skin_1] == 0)
				return SendErr(playerid, "На вешалке нет одежды, чтобы её выкидывать!");

			House[id_house][wardrobe_skin_1] = -1;
		}
		case WARDROBE_SKIN_TWO:
		{
			if(House[id_house][wardrobe_skin_2] == -1 || House[id_house][wardrobe_skin_2] == 0)
				return SendErr(playerid, "На вешалке нет одежды, чтобы её выкидывать!");

			House[id_house][wardrobe_skin_2] = -1;
		}
		case WARDROBE_SKIN_THREE:
		{
			if(House[id_house][wardrobe_skin_3] == -1 || House[id_house][wardrobe_skin_3] == 0)
				return SendErr(playerid, "На вешалке нет одежды, чтобы её выкидывать!");

			House[id_house][wardrobe_skin_3] = -1;
		}
	}
	SendSucc(playerid, "Вы успешно выкинули одежду с полки!");	
	save_house(id_house);
	show_wardrobe_menu(playerid);
	return true;
}

stock show_weapon_wadrobe_select(playerid, id_house, type)
{
	new 
		fmt_str[400];

	switch(type)
	{
		case WARDROBE_GUN_FIRST:
		{	
		    format(fmt_str, 400, "\
		    "cGREY"Тип\t"cGREY"Информация\n\
		    "cBLUE"- "cWH"Положить оружие в шкаф\t"cBLUE"Положить\n\
		    "cBLUE"- "cWH"Забрать оружие с первой полки\t"cBLUE"%s\n\
		    "cBLUE"- "cWH"Выкинуть оружие\t"cBLUE"Выкинуть", get_weapon_wardrobe(playerid, WARDROBE_GUN_FIRST, id_house));
		    SPD(playerid, DIALOG_WARDROBE_GUN_1, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Шкаф", fmt_str, !"Выбрать", !"Закрыть"); 	

		}
		case WARDROBE_GUN_TWO:
		{
		    format(fmt_str, 400, "\
		    "cGREY"Тип\t"cGREY"Информация\n\
		    "cBLUE"- "cWH"Положить оружие в шкаф\t"cBLUE"Положить\n\
		    "cBLUE"- "cWH"Забрать оружие со второй полки\t"cBLUE"%s\n\
		    "cBLUE"- "cWH"Выкинуть оружие\t"cBLUE"Выкинуть", get_weapon_wardrobe(playerid, WARDROBE_GUN_TWO, id_house));
		    SPD(playerid, DIALOG_WARDROBE_GUN_2, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Шкаф", fmt_str, !"Выбрать", !"Закрыть"); 	
		}
		case WARDROBE_GUN_THREE:
		{
		    format(fmt_str, 400, "\
		    "cGREY"Тип\t"cGREY"Информация\n\
		    "cBLUE"- "cWH"Положить оружие в шкаф\t"cBLUE"Положить\n\
		    "cBLUE"- "cWH"Забрать оружие с третьей полки\t"cBLUE"%s\n\
		    "cBLUE"- "cWH"Выкинуть оружие\t"cBLUE"Выкинуть", get_weapon_wardrobe(playerid, WARDROBE_GUN_THREE, id_house));

		    SPD(playerid, DIALOG_WARDROBE_GUN_3, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Шкаф", fmt_str, !"Выбрать", !"Закрыть"); 	
		}
	}
	return true;

}

stock show_weapon_wardrobe_menus(playerid, id_house, type)
{


	switch(type)
	{
		case WARDROBE_GUN_FIRST:
		{
			show_weapon_wadrobe_select(playerid, id_house, WARDROBE_GUN_FIRST);
		}
		case WARDROBE_GUN_TWO:
		{
			show_weapon_wadrobe_select(playerid, id_house, WARDROBE_GUN_TWO);	
		}
		case WARDROBE_GUN_THREE:
		{
			show_weapon_wadrobe_select(playerid, id_house, WARDROBE_GUN_THREE);	
		}
	}


	return true;
}

stock gun_wardrobe_1(playerid, id_house, type)
{
	new 
		weap_name[30];

	switch(type)
	{
		case WARDROBE_GUN_PUT:
		{
			if(House[id_house][wardrobe_gun_1] == -1)
			{
				new 
					gun_id = GetPlayerWeapon(playerid);

				new 
					ammo = GetPlayerAmmo(playerid);	

				if(gun_id == 0)
				{
					SendErr(playerid, "Сперва выберите оружие, которое хотите положить на полку в шкафу!");
					return show_weapon_wadrobe_select(playerid, id_house, WARDROBE_GUN_FIRST);
				}

				RemovePlayerWeapon(playerid, gun_id);

				House[id_house][wardrobe_gun_1] = gun_id;
				House[id_house][wardrobe_gun_ammo_1] = ammo;

				GetWeaponName(gun_id, weap_name, 30);

				SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы положили в шкаф %s с %d патронами", weap_name, ammo);
			}
			else
			{
				show_weapon_wadrobe_select(playerid, id_house, WARDROBE_GUN_FIRST);
				return SendErr(playerid, "В полке уже лежит оружие, Вы не можете положить новое!");
			}
		}
		case WARDROBE_GUN_INPUT:
		{
			if(House[id_house][wardrobe_gun_1] == -1)
			{
				SendErr(playerid, "Полка в шкафу пустая!");
				return show_weapon_wadrobe_select(playerid, id_house, WARDROBE_GUN_FIRST);
			}			
			else
			{	new 
					gun_input = House[id_house][wardrobe_gun_1],
					ammo_input = House[id_house][wardrobe_gun_ammo_1];


				GivePlayerWeaponEx(playerid, gun_input, ammo_input);

				House[id_house][wardrobe_gun_1] = -1;
				House[id_house][wardrobe_gun_ammo_1] = 0;

				GetWeaponName(gun_input, weap_name, 30);

				SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы достали из шкафа %s с %d патронами", weap_name, ammo_input);
			}
		}
	}
	save_house(id_house);
	ApplyAnimation(playerid, "UZI", "UZI_RELOAD", 4.1, 0, 0, 0, 0, 0);
	return true;
}

stock gun_wardrobe_2(playerid, id_house, type)
{
	new 
		weap_name[30];
		
	switch(type)
	{
		case WARDROBE_GUN_PUT:
		{
			if(House[id_house][wardrobe_gun_2] == -1)
			{
				new 
					gun_id = GetPlayerWeapon(playerid);

				new 
					ammo = GetPlayerAmmo(playerid);	

				if(gun_id == 0)
				{
					SendErr(playerid, "Сперва выберите оружие, которое хотите положить на полку в шкафу!");
					return show_weapon_wadrobe_select(playerid, id_house, WARDROBE_GUN_TWO);
				}

				RemovePlayerWeapon(playerid, gun_id);

				House[id_house][wardrobe_gun_2] = gun_id;
				House[id_house][wardrobe_gun_ammo_2] = ammo;

				GetWeaponName(gun_id, weap_name, 30);

				SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы положили в шкаф %s с %d патронами", weap_name, ammo);
			}
			else
			{
				show_weapon_wadrobe_select(playerid, id_house, WARDROBE_GUN_TWO);
				return SendErr(playerid, "В полке уже лежит оружие, Вы не можете положить новое!");
			}
		}
		case WARDROBE_GUN_INPUT:
		{
			if(House[id_house][wardrobe_gun_2] == -1)
			{
				SendErr(playerid, "Полка в шкафу пустая!");
				return show_weapon_wadrobe_select(playerid, id_house, WARDROBE_GUN_TWO);
			}			
			else
			{	new 
					gun_input = House[id_house][wardrobe_gun_2],
					ammo_input = House[id_house][wardrobe_gun_ammo_2];


				GivePlayerWeaponEx(playerid, gun_input, ammo_input);

				House[id_house][wardrobe_gun_2] = -1;
				House[id_house][wardrobe_gun_ammo_2] = 0;

				GetWeaponName(gun_input, weap_name, 30);

				SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы достали из шкафа %s с %d патронами", weap_name, ammo_input);
			}
		}
	}
	save_house(id_house);
	ApplyAnimation(playerid, "UZI", "UZI_RELOAD", 4.1, 0, 0, 0, 0, 0);
	return true;
}

stock gun_wardrobe_3(playerid, id_house, type)
{
	new 
		weap_name[30];
		
	switch(type)
	{
		case WARDROBE_GUN_PUT:
		{
			if(House[id_house][wardrobe_gun_3] == -1)
			{
				new 
					gun_id = GetPlayerWeapon(playerid);

				new 
					ammo = GetPlayerAmmo(playerid);	

				if(gun_id == 0)
				{
					SendErr(playerid, "Сперва выберите оружие, которое хотите положить на полку в шкафу!");
					return show_weapon_wadrobe_select(playerid, id_house, WARDROBE_GUN_THREE);
				}

				RemovePlayerWeapon(playerid, gun_id);

				House[id_house][wardrobe_gun_3] = gun_id;
				House[id_house][wardrobe_gun_ammo_3] = ammo;

				GetWeaponName(gun_id, weap_name, 30);

				SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы положили в шкаф %s с %d патронами", weap_name, ammo);
			}
			else
			{
				show_weapon_wadrobe_select(playerid, id_house, WARDROBE_GUN_THREE);
				return SendErr(playerid, "В полке уже лежит оружие, Вы не можете положить новое!");
			}
		}
		case WARDROBE_GUN_INPUT:
		{
			if(House[id_house][wardrobe_gun_3] == -1)
			{
				SendErr(playerid, "Полка в шкафу пустая!");
				return show_weapon_wadrobe_select(playerid, id_house, WARDROBE_GUN_THREE);
			}			
			else
			{	new 
					gun_input = House[id_house][wardrobe_gun_3],
					ammo_input = House[id_house][wardrobe_gun_ammo_3];


				GivePlayerWeaponEx(playerid, gun_input, ammo_input);

				House[id_house][wardrobe_gun_3] = -1;
				House[id_house][wardrobe_gun_ammo_3] = 0;

				GetWeaponName(gun_input, weap_name, 30);

				SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы достали из шкафа %s с %d патронами", weap_name, ammo_input);
			}
		}
	}
	save_house(id_house);
	ApplyAnimation(playerid, "UZI", "UZI_RELOAD", 4.1, 0, 0, 0, 0, 0);
	return true;
}


stock gun_drop_wardrobe(playerid, id_house, type)
{
	switch(type)
	{
		case WARDROBE_GUN_FIRST:
		{	
			if(House[id_house][wardrobe_gun_1] == -1 || House[id_house][wardrobe_gun_ammo_1] > 0)
				return SendErr(playerid, "На полке нет оружия, чтобы его выкидывать!");

			House[id_house][wardrobe_gun_1] = -1;
			House[id_house][wardrobe_gun_ammo_1] = 0;
		}
		case WARDROBE_GUN_TWO:
		{
			if(House[id_house][wardrobe_gun_2] == -1 || House[id_house][wardrobe_gun_ammo_2] > 0)
				return SendErr(playerid, "На полке нет оружия, чтобы его выкидывать!");

			House[id_house][wardrobe_gun_2] = -1;
			House[id_house][wardrobe_gun_ammo_2] = 0;
		}
		case WARDROBE_GUN_THREE:
		{
			if(House[id_house][wardrobe_gun_3] == -1 || House[id_house][wardrobe_gun_ammo_3] > 0)
				return SendErr(playerid, "На полке нет оружия, чтобы его выкидывать!");

			House[id_house][wardrobe_gun_3] = -1;
			House[id_house][wardrobe_gun_ammo_3] = 0;
		}
	}
	SendSucc(playerid, "Вы успешно выкинули одежду с полки!");	
	save_house(id_house);
	show_wardrobe_menu(playerid);
	return true;
}

stock change_skin_wardrobe_menu(playerid)
{
	if(pData[playerid][pFraction] && pData[playerid][pFractionSkin] != GetPlayerSkin(playerid))
	{
		set_player_skin(playerid,pData[playerid][pFractionSkin]);
	}
	else 
	{
		set_player_skin(playerid,pData[playerid][pSkin]);
	}                    
	show_wardrobe_menu(playerid);	
	return true;
}


stock dialog_house_wardrobe(playerid, dialogid, response, listitem, inputtext[])
{

	switch(dialogid)
	{
		case DIALOG_GENERAL_WARDROBE:
		{
			new 
				id_house = pData[playerid][pHouse];

			if(!response)
				return true;

			switch(listitem)
			{
				case 0: return show_skin_wardrobe_menu(playerid, id_house, WARDROBE_SKIN_FIRST);
				case 1: return show_skin_wardrobe_menu(playerid, id_house, WARDROBE_SKIN_TWO);
				case 2: return show_skin_wardrobe_menu(playerid, id_house, WARDROBE_SKIN_THREE);
				case 3:	return show_wardrobe_menu(playerid);
				case 4: return show_weapon_wardrobe_menus(playerid, id_house, WARDROBE_GUN_FIRST);
				case 5: return show_weapon_wardrobe_menus(playerid, id_house, WARDROBE_GUN_TWO);
				case 6: return show_weapon_wardrobe_menus(playerid, id_house, WARDROBE_GUN_THREE);
				case 7:	return show_wardrobe_menu(playerid);
				case 8: return show_aks_wardrobe_menu(playerid, id_house, WARDROBE_AKS_FIRST); 
				case 9: return show_aks_wardrobe_menu(playerid, id_house, WARDROBE_AKS_TWO); 
				case 10: return show_aks_wardrobe_menu(playerid, id_house, WARDROBE_AKS_THREE); 
				case 11: return show_wardrobe_menu(playerid);
				case 12: return change_skin_wardrobe_menu(playerid);
			
			}	
		}
		case DIALOG_WARDROBE_POLKA_AKS_1:
		{
			new 
				id_house = pData[playerid][pHouse];

			if(!response)
				return show_wardrobe_menu(playerid);

			switch(listitem)
			{
				case 0:
				{
					select_aks_player(playerid, WARDROBE_AKS_FIRST);
				}
				case 1:
				{
					skin_aks_1(playerid, id_house, WARDROBE_AKS_INPUT);
				}
				case 2:
				{
					aks_drop_wardrobe(playerid, id_house, WARDROBE_AKS_FIRST);
				}
			}		
		}
		case DIALOG_WARDROBE_POLKA_AKS_2:
		{
			new 
				id_house = pData[playerid][pHouse];

			if(!response)
				return show_wardrobe_menu(playerid);

			switch(listitem)
			{
				case 0:
				{
					select_aks_player(playerid, WARDROBE_AKS_TWO);
				}
				case 1:
				{
					skin_aks_2(playerid, id_house, WARDROBE_AKS_INPUT);
				}
				case 2:
				{
					aks_drop_wardrobe(playerid, id_house, WARDROBE_AKS_TWO);
				}
			}

		}
		case DIALOG_WARDROBE_POLKA_AKS_3:
		{
			new 
				id_house = pData[playerid][pHouse];

			if(!response)
				return show_wardrobe_menu(playerid);

			switch(listitem)
			{
				case 0:
				{
					select_aks_player(playerid, WARDROBE_AKS_THREE);
				}
				case 1:
				{
					skin_aks_3(playerid, id_house, WARDROBE_AKS_INPUT);
				}
				case 2:
				{
					aks_drop_wardrobe(playerid, id_house, WARDROBE_AKS_THREE);
				}
			}	
		}
		case DIALOG_SELECT_WARDROBE_P_1_1:
		{
			new 
				id_house = pData[playerid][pHouse];

			if(!response)
				return show_wardrobe_menu(playerid);

			switch(listitem)
			{
				case 0:
				{
					if(pData[playerid][pSlotItem][0] == -1)
					{	
						SendErr(playerid, "У вас отсутствует кепка!");
						return show_wardrobe_menu(playerid);
					}

					SetPVarIntNew(playerid, "type_select_aks", pData[playerid][pSlotItem][0]);
					SetPVarIntNew(playerid, "type_select_aks_id", 0);
					skin_aks_1(playerid, id_house, WARDROBE_AKS_PUT);
				}
				case 1:
				{

					if(pData[playerid][pSlotItem][2] == -1)
					{	
						SendErr(playerid, "У вас отсутствует маска!");
						return show_wardrobe_menu(playerid);
					}

					SetPVarIntNew(playerid, "type_select_aks", pData[playerid][pSlotItem][2]);
					SetPVarIntNew(playerid, "type_select_aks_id", 2);
					skin_aks_1(playerid, id_house, WARDROBE_AKS_PUT);
				}
				case 2:
				{

					if(pData[playerid][pSlotItem][3] == -1)
					{	
						SendErr(playerid, "У вас отсутствует рюкзак!");
						return show_wardrobe_menu(playerid);
					}

					SetPVarIntNew(playerid, "type_select_aks", pData[playerid][pSlotItem][3]);
					SetPVarIntNew(playerid, "type_select_aks_id", 3);
					skin_aks_1(playerid, id_house, WARDROBE_AKS_PUT);
				}
			}			
		}
		case DIALOG_SELECT_WARDROBE_P_1_2:
		{
			new 
				id_house = pData[playerid][pHouse];

			if(!response)
				return show_wardrobe_menu(playerid);

			switch(listitem)
			{
				case 0:
				{
					if(pData[playerid][pSlotItem][0] == -1)
					{	
						SendErr(playerid, "У вас отсутствует кепка!");
						return show_wardrobe_menu(playerid);
					}

					SetPVarIntNew(playerid, "type_select_aks", pData[playerid][pSlotItem][0]);
					SetPVarIntNew(playerid, "type_select_aks_id", 0);
					skin_aks_2(playerid, id_house, WARDROBE_AKS_PUT);
				}
				case 1:
				{

					if(pData[playerid][pSlotItem][2] == -1)
					{	
						SendErr(playerid, "У вас отсутствует маска!");
						return show_wardrobe_menu(playerid);
					}

					SetPVarIntNew(playerid, "type_select_aks", pData[playerid][pSlotItem][2]);
					SetPVarIntNew(playerid, "type_select_aks_id", 2);
					skin_aks_2(playerid, id_house, WARDROBE_AKS_PUT);
				}
				case 2:
				{

					if(pData[playerid][pSlotItem][3] == -1)
					{	
						SendErr(playerid, "У вас отсутствует рюкзак!");
						return show_wardrobe_menu(playerid);
					}

					SetPVarIntNew(playerid, "type_select_aks", pData[playerid][pSlotItem][3]);
					SetPVarIntNew(playerid, "type_select_aks_id", 3);
					skin_aks_2(playerid, id_house, WARDROBE_AKS_PUT);
				}
			}			
		}
		case DIALOG_SELECT_WARDROBE_P_1_3:
		{
			new 
				id_house = pData[playerid][pHouse];

			if(!response)
				return show_wardrobe_menu(playerid);

			switch(listitem)
			{
				case 0:
				{
					if(pData[playerid][pSlotItem][0] == -1)
					{	
						SendErr(playerid, "У вас отсутствует кепка!");
						return show_wardrobe_menu(playerid);
					}

					SetPVarIntNew(playerid, "type_select_aks", pData[playerid][pSlotItem][0]);
					SetPVarIntNew(playerid, "type_select_aks_id", 0);
					skin_aks_3(playerid, id_house, WARDROBE_AKS_PUT);
				}
				case 1:
				{

					if(pData[playerid][pSlotItem][2] == -1)
					{	
						SendErr(playerid, "У вас отсутствует маска!");
						return show_wardrobe_menu(playerid);
					}

					SetPVarIntNew(playerid, "type_select_aks", pData[playerid][pSlotItem][2]);
					SetPVarIntNew(playerid, "type_select_aks_id", 2);
					skin_aks_3(playerid, id_house, WARDROBE_AKS_PUT);
				}
				case 2:
				{

					if(pData[playerid][pSlotItem][3] == -1)
					{	
						SendErr(playerid, "У вас отсутствует рюкзак!");
						return show_wardrobe_menu(playerid);
					}

					SetPVarIntNew(playerid, "type_select_aks", pData[playerid][pSlotItem][3]);
					SetPVarIntNew(playerid, "type_select_aks_id", 3);
					skin_aks_3(playerid, id_house, WARDROBE_AKS_PUT);
				}
			}			
		}
		case DIALOG_WARDROBE_POLKA_1:
		{
			new 
				id_house = pData[playerid][pHouse];

			if(!response)
				return show_wardrobe_menu(playerid);

			switch(listitem)
			{
				case 0: return skin_wardrobe_1(playerid, id_house, WARDROBE_SKIN_PUT);
				case 1: return skin_wardrobe_1(playerid, id_house, WARDROBE_SKIN_INPUT);
				case 2: return skin_drop_wardrobe(playerid, id_house, WARDROBE_SKIN_FIRST);
			}

		}
		case DIALOG_WARDROBE_POLKA_2:
		{
			new 
				id_house = pData[playerid][pHouse];

			if(!response)
				return show_wardrobe_menu(playerid);

			switch(listitem)
			{
				case 0: return skin_wardrobe_2(playerid, id_house, WARDROBE_SKIN_PUT);
				case 1: return skin_wardrobe_2(playerid, id_house, WARDROBE_SKIN_INPUT);
				case 2: return skin_drop_wardrobe(playerid, id_house, WARDROBE_SKIN_TWO);
			}

			
		}
		case DIALOG_WARDROBE_POLKA_3:
		{
			new 
				id_house = pData[playerid][pHouse];

			if(!response)
				return show_wardrobe_menu(playerid);

			switch(listitem)
			{
				case 0: return skin_wardrobe_3(playerid, id_house, WARDROBE_SKIN_PUT);
				case 1: return skin_wardrobe_3(playerid, id_house, WARDROBE_SKIN_INPUT);
				case 2: return skin_drop_wardrobe(playerid, id_house, WARDROBE_SKIN_THREE);
			}
		}
		case DIALOG_WARDROBE_GUN_1:
		{
			new 
				id_house = pData[playerid][pHouse];

			if(!response)
				return show_wardrobe_menu(playerid);

			switch(listitem)
			{
				case 0: return gun_wardrobe_1(playerid, id_house, WARDROBE_GUN_PUT);
				case 1: return gun_wardrobe_1(playerid, id_house, WARDROBE_GUN_INPUT);
				case 2: return gun_drop_wardrobe(playerid, id_house, WARDROBE_GUN_FIRST);
			}
		}
		case DIALOG_WARDROBE_GUN_2:
		{
			new 
				id_house = pData[playerid][pHouse];

			if(!response)
				return show_wardrobe_menu(playerid);

			switch(listitem)
			{
				case 0: return gun_wardrobe_2(playerid, id_house, WARDROBE_GUN_PUT);
				case 1: return gun_wardrobe_2(playerid, id_house, WARDROBE_GUN_INPUT);
				case 2: return gun_drop_wardrobe(playerid, id_house, WARDROBE_GUN_TWO);
			}
		}
		case DIALOG_WARDROBE_GUN_3:
		{
			new 
				id_house = pData[playerid][pHouse];

			if(!response)
				return show_wardrobe_menu(playerid);

			switch(listitem)
			{
				case 0: return gun_wardrobe_3(playerid, id_house, WARDROBE_GUN_PUT);
				case 1: return gun_wardrobe_3(playerid, id_house, WARDROBE_GUN_INPUT);
				case 2: return gun_drop_wardrobe(playerid, id_house, WARDROBE_GUN_THREE);
			}
		}
	}
	return true;
}