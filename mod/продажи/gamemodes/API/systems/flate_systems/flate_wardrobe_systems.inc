
#define POSITION_WARDROBE_INT_FLATE_LOW			-2398.7944, -444.4781, 33.2104
#define POSITION_WARDROBE_INT_FLATE_MEDIUM		492.1710,2310.0166,1604.6016
#define POSITION_WARDROBE_INT_FLATE_HARD		-2398.7944, -444.4781, 33.2104
#define POSITION_WARDROBE_INT_FLATE_LUXE		-2398.7944, -444.4781, 33.2104

#define WADROBE_FLATE_SKIN_1			1
#define WARDROBE_FLATE_SKIN_2			2
#define WARDROBE_FLATE_SKIN_3			3

#define WARDROBE_GUN_1					1
#define WADROBE_GUN_2					2
#define WARDROBE_GUN_3					3

#define WARDROBE_FLATE_SKIN_PUT			1
#define WARDROBE_FLATE_SKIN_INPUT		2

#define WARDROBE_GUN_FLATE_PUT			1
#define WARDROBE_GUN_FLATE_INPUT		2

stock create_flate_wardrobe_position()
{
	CreateDynamic3DTextLabel(""cWH"Домашний Шкаф",-1, \
  		POSITION_WARDROBE_INT_FLATE_LOW, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1, -1);	
	create_circle_pickup_o(POSITION_WARDROBE_INT_FLATE_LOW, TRIGGER_LBLUE);
	create_dynamic_area(POSITION_WARDROBE_INT_FLATE_LOW, -1, 1, FLATE_WARDROBE, 1.5);


	return true;
}

stock get_skin_flate_wardrobe(playerid, type, h)
{
	new 
		skin[32];

	switch(type)
	{
		case WADROBE_FLATE_SKIN_1:
		{
			if(flate[h][wardrobe_skin_1] == -1 || flate[h][wardrobe_skin_1] == 0)
			{
				skin = "Отсутствует";
			}
			else
			{
				format(skin,sizeof(skin),"%d",flate[h][wardrobe_skin_1]);
			}
		}
		case WARDROBE_FLATE_SKIN_2:
		{
			if(flate[h][wardrobe_skin_2] == -1 || flate[h][wardrobe_skin_2] == 0)
			{
				skin = "Отсутствует";
			}
			else
			{
				format(skin,sizeof(skin),"%d",flate[h][wardrobe_skin_2]);
			}			
		}
		case WARDROBE_FLATE_SKIN_3:
		{
			if(flate[h][wardrobe_skin_3] == -1 || flate[h][wardrobe_skin_3] == 0)
			{
				skin = "Отсутствует";
			}
			else
			{
				format(skin,sizeof(skin),"%d",flate[h][wardrobe_skin_3]);
			}			
		}
	}
	return skin;
}

stock get_aks_wardrobe_flate(playerid, type, h)
{
	new 
		skin[32];

	switch(type)
	{
		case WARDROBE_AKS_FIRST:
		{
			if(flate[h][wardrobe_aks_1] == -1)
			{
				skin = "Отсутствует";
			}
			else
			{
				format(skin,sizeof(skin),"%d",flate[h][wardrobe_aks_1]);
			}
		}
		case WARDROBE_AKS_TWO:
		{
			if(flate[h][wardrobe_aks_2] == -1)
			{
				skin = "Отсутствует";
			}
			else
			{
				format(skin,sizeof(skin),"%d",flate[h][wardrobe_aks_2]);
			}			
		}
		case WARDROBE_AKS_THREE:
		{
			if(flate[h][wardrobe_aks_3] == -1)
			{
				skin = "Отсутствует";
			}
			else
			{
				format(skin,sizeof(skin),"%d",flate[h][wardrobe_aks_3]);
			}			
		}
	}
	return skin;
}

stock get_weapon_wardrobe_flate(playerid, type, h)
{
	new 
		weapon[32];

	switch(type)
	{
		case WARDROBE_GUN_1:
		{
			if(flate[h][wardrobe_gun_1] == -1)
			{
				weapon = "Отсутствует";
			}
			else
			{
				GetWeaponName(flate[h][wardrobe_gun_1], weapon, 30);
			}
		}
		case WADROBE_GUN_2:
		{
			if(flate[h][wardrobe_gun_2] == -1)
			{
				weapon = "Отсутствует";
			}
			else
			{
				GetWeaponName(flate[h][wardrobe_gun_2], weapon, 30);
			}			
		}
		case WARDROBE_GUN_3:
		{
			if(flate[h][wardrobe_gun_3] == -1)
			{
				weapon = "Отсутствует";
			}
			else
			{
				GetWeaponName(flate[h][wardrobe_gun_3], weapon, 30);
			}			
		}
	}
	return weapon;
}


stock show_wardrobe_menu_flate(playerid)
{
	new 
		h = pData[playerid][pFlate];

	if(pData[playerid][pFlate] == -1)
		return SendErr(playerid, "У вас нет доступа к данному шкафу!");	


	if(GetPlayerVirtualWorld(playerid) != h)
		return SendErr(playerid, "Вы находитесь не в своей квартире!");

	if(!flate[h][wardrobe_status])
		return SendErr(playerid, "В квартире нет шкафа!");



	static
		fmt_str[800];

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
    "cBLUE"- "cWH"Организационная одежда\t"cBLUE"Снять/Одеть\n\
    ", 
	get_skin_flate_wardrobe(playerid, WADROBE_FLATE_SKIN_1, h),
	get_skin_flate_wardrobe(playerid, WARDROBE_FLATE_SKIN_2, h),
	get_skin_flate_wardrobe(playerid, WARDROBE_FLATE_SKIN_3, h),
	get_weapon_wardrobe_flate(playerid, WARDROBE_GUN_1, h),
	flate[h][wardrobe_gun_ammo_1],
	get_weapon_wardrobe_flate(playerid, WADROBE_GUN_2, h),
	flate[h][wardrobe_gun_ammo_2],
	get_weapon_wardrobe_flate(playerid, WARDROBE_GUN_3, h), flate[h][wardrobe_gun_ammo_3],

    get_aks_wardrobe_flate(playerid, WARDROBE_AKS_FIRST, h),
    get_aks_wardrobe_flate(playerid, WARDROBE_AKS_TWO, h),
    get_aks_wardrobe_flate(playerid, WARDROBE_AKS_THREE, h));
    SPD(playerid, DIALOG_GENERAL_WARDROBE_FLATE, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Шкаф дома", fmt_str, !"Выбрать", !"Закрыть"); 

    fmt_str[0] = EOS;


    return true;
}

stock show_skin_wadrobe_fl_menu(playerid, id_flate, type)
{

	switch(type)
	{
		case WADROBE_FLATE_SKIN_1:
		{	
			show_skin_wardrobe_fl_select(playerid, id_flate, WADROBE_FLATE_SKIN_1);

		}
		case WARDROBE_FLATE_SKIN_2:
		{
			show_skin_wardrobe_fl_select(playerid, id_flate, WARDROBE_FLATE_SKIN_2);	
		}
		case WARDROBE_FLATE_SKIN_3:
		{
			show_skin_wardrobe_fl_select(playerid, id_flate, WARDROBE_FLATE_SKIN_3);
		}
	}


	return true;
}

stock show_skin_wardrobe_fl_select(playerid, id_flate, type)
{
	new 
		fmt_str[400];

	switch(type)
	{
		case WADROBE_FLATE_SKIN_1:
		{	
		    format(fmt_str, 400, "\
		    "cGREY"Тип\t"cGREY"Информация\n\
		    "cBLUE"- "cWH"Повесить одежду в шкаф\t"cBLUE"Повесить\n\
		    "cBLUE"- "cWH"Забрать одежду с первой вешалки\t"cBLUE"%s одежда\n\
		    "cBLUE"- "cWH"Выкинуть одежду\t"cBLUE"Выкинуть", get_skin_flate_wardrobe(playerid, WADROBE_FLATE_SKIN_1, id_flate));
		    SPD(playerid, DIALOG_WADROBE_1_FLATE, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Шкаф", fmt_str, !"Выбрать", !"Закрыть"); 	

		}
		case WARDROBE_FLATE_SKIN_2:
		{
		    format(fmt_str, 400, "\
		    "cGREY"Тип\t"cGREY"Информация\n\
		    "cBLUE"- "cWH"Повесить одежду в шкаф\t"cBLUE"Повесить\n\
		    "cBLUE"- "cWH"Забрать одежду со второй вешалки\t"cBLUE"%s одежда\n\
		    "cBLUE"- "cWH"Выкинуть одежду\t"cBLUE"Выкинуть", get_skin_flate_wardrobe(playerid, WARDROBE_FLATE_SKIN_2, id_flate));
		    SPD(playerid, DIALOG_WARDROBE_2_FLATE, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Шкаф", fmt_str, !"Выбрать", !"Закрыть"); 	
		}
		case WARDROBE_FLATE_SKIN_3:
		{
		    format(fmt_str, 400, "\
		    "cGREY"Тип\t"cGREY"Информация\n\
		    "cBLUE"- "cWH"Повесить одежду в шкаф\t"cBLUE"Повесить\n\
		    "cBLUE"- "cWH"Забрать одежду с третье вешалки\t"cBLUE"%s одежда\n\
		    "cBLUE"- "cWH"Выкинуть одежду\t"cBLUE"Выкинуть", get_skin_flate_wardrobe(playerid, WARDROBE_FLATE_SKIN_3, id_flate));

		    SPD(playerid, DIALOG_WARDROBE_3_FLATE, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Шкаф", fmt_str, !"Выбрать", !"Закрыть"); 	
		}
	}
	return true;

}

stock skin_wardrobe_flate_1(playerid, id_flate, type)
{

	switch(type)
	{
		case WARDROBE_FLATE_SKIN_PUT:
		{
			if(flate[id_flate][wardrobe_skin_1] != -1 && flate[id_flate][wardrobe_skin_1] != 0)
			{
				show_skin_wardrobe_fl_select(playerid, id_flate, WADROBE_FLATE_SKIN_1);
				return SendErr(playerid, "Вешалка уже занята, Вы не можете повесить туда одежду");
			}

			new 
				id_skin = GetPlayerSkin(playerid);

			flate[id_flate][wardrobe_skin_1] = id_skin;

			if(pData[playerid][pSex] == 2)
			{
				if(pData[playerid][pSkin] == 140)
				{
					show_skin_wardrobe_fl_select(playerid, id_flate, WADROBE_FLATE_SKIN_1);
					return SendErr(playerid, "На вас нет одежды, чтобы повесить её!");
				}
				if(GetPVarIntNew(playerid, "askin"))
				{
					show_skin_wardrobe_fl_select(playerid, id_flate, WADROBE_FLATE_SKIN_1);
					return SendErr(playerid, "Данную одежду нельзя повесить на вешалку!");
				}
				if(pData[playerid][pFractionSkin] == id_skin)
				{
					show_skin_wardrobe_fl_select(playerid, id_flate, WADROBE_FLATE_SKIN_1);
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
					show_skin_wardrobe_fl_select(playerid, id_flate, WADROBE_FLATE_SKIN_1);
					return SendErr(playerid, "На вас нет одежды, чтобы повесить её!");
				}
				if(GetPVarIntNew(playerid, "askin"))
				{
					show_skin_wardrobe_fl_select(playerid, id_flate, WADROBE_FLATE_SKIN_1);
					return SendErr(playerid, "Данную одежду нельзя повесить на вешалку!");
				}
				if(pData[playerid][pFractionSkin] == id_skin)
				{
					show_skin_wardrobe_fl_select(playerid, id_flate, WADROBE_FLATE_SKIN_1);
					return SendErr(playerid, "Данную одежду нельзя повесить на вешалку!");		
				}
				pData[playerid][pSkin] = 97;
				UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);

				SetPlayerSkin(playerid, 97);
			}

			SendSucc(playerid, "Вы повесили свою одежду в шкаф!");

		}
		case WARDROBE_FLATE_SKIN_INPUT:
		{
			if(flate[id_flate][wardrobe_skin_1] == -1 || !flate[id_flate][wardrobe_skin_1])
			{
				show_skin_wardrobe_fl_select(playerid, id_flate, WADROBE_FLATE_SKIN_1);
				return SendErr(playerid, "На вешалке ничего нет!");
			}

			new 
				id_skin = GetPlayerSkin(playerid);

			if(pData[playerid][pSex] == 2)
			{
				if(pData[playerid][pSkin] == 140)
				{
					pData[playerid][pSkin] = flate[id_flate][wardrobe_skin_1];
					UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);
					SetPlayerSkin(playerid, pData[playerid][pSkin]);	

					flate[id_flate][wardrobe_skin_1] = -1;				
				}
				else
				{
					pData[playerid][pSkin] = flate[id_flate][wardrobe_skin_1];

					flate[id_flate][wardrobe_skin_1] = id_skin;

					UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);
					SetPlayerSkin(playerid, pData[playerid][pSkin]);	

					SendSucc(playerid, "Вы поменяли одежду!");					
				}
			}
			else
			{
				if(pData[playerid][pSkin] == 97)
				{
					pData[playerid][pSkin] = flate[id_flate][wardrobe_skin_1];
					UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);
					SetPlayerSkin(playerid, pData[playerid][pSkin]);		

					flate[id_flate][wardrobe_skin_1] = -1;				
				}
				else
				{
					pData[playerid][pSkin] = flate[id_flate][wardrobe_skin_1];

					flate[id_flate][wardrobe_skin_1] = id_skin;

					UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);
					SetPlayerSkin(playerid, pData[playerid][pSkin]);	

					SendSucc(playerid, "Вы поменяли одежду!");					
				}
			}			

		}
	}
	ApplyAnimation(playerid, "PED", "ROADCROSS", 4.1, 0, 0, 0, 0, 0);
	save_flate(id_flate);
	show_wardrobe_menu_flate(playerid);
	return true;
}

stock skin_wardrobe_flate_2(playerid, id_flate, type)
{

	switch(type)
	{
		case WARDROBE_FLATE_SKIN_PUT:
		{
			if(flate[id_flate][wardrobe_skin_2] != -1 && flate[id_flate][wardrobe_skin_2] != 0)
			{
				show_skin_wardrobe_fl_select(playerid, id_flate, WARDROBE_FLATE_SKIN_2);
				return SendErr(playerid, "Вешалка уже занята, Вы не можете повесить туда одежду");
			}

			new 
				id_skin = GetPlayerSkin(playerid);

			flate[id_flate][wardrobe_skin_2] = id_skin;

			if(pData[playerid][pSex] == 2)
			{
				if(pData[playerid][pSkin] == 140)
				{
					show_skin_wardrobe_fl_select(playerid, id_flate, WARDROBE_FLATE_SKIN_2);
					return SendErr(playerid, "На вас нет одежды, чтобы повесить её!");
				}
				if(GetPVarIntNew(playerid, "askin"))
				{
					show_skin_wardrobe_fl_select(playerid, id_flate, WARDROBE_FLATE_SKIN_2);
					return SendErr(playerid, "Данную одежду нельзя повесить на вешалку!");
				}
				if(pData[playerid][pFractionSkin] == id_skin)
				{
					show_skin_wardrobe_fl_select(playerid, id_flate, WARDROBE_FLATE_SKIN_2);
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
					show_skin_wardrobe_fl_select(playerid, id_flate, WARDROBE_FLATE_SKIN_2);
					return SendErr(playerid, "На вас нет одежды, чтобы повесить её!");
				}
				if(GetPVarIntNew(playerid, "askin"))
				{
					show_skin_wardrobe_fl_select(playerid, id_flate, WARDROBE_FLATE_SKIN_2);
					return SendErr(playerid, "Данную одежду нельзя повесить на вешалку!");
				}
				if(pData[playerid][pFractionSkin] == id_skin)
				{
					show_skin_wardrobe_fl_select(playerid, id_flate, WARDROBE_FLATE_SKIN_2);
					return SendErr(playerid, "Данную одежду нельзя повесить на вешалку!");		
				}
				pData[playerid][pSkin] = 97;
				UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);

				SetPlayerSkin(playerid, 97);
			}

			SendSucc(playerid, "Вы повесили свою одежду в шкаф!");

		}
		case WARDROBE_FLATE_SKIN_INPUT:
		{
			if(flate[id_flate][wardrobe_skin_2] == -1 || !flate[id_flate][wardrobe_skin_2])
			{
				show_skin_wardrobe_fl_select(playerid, id_flate, WARDROBE_FLATE_SKIN_2);
				return SendErr(playerid, "На вешалке ничего нет!");
			}

			new 
				id_skin = GetPlayerSkin(playerid);

			if(pData[playerid][pSex] == 2)
			{
				if(pData[playerid][pSkin] == 140)
				{
					pData[playerid][pSkin] = flate[id_flate][wardrobe_skin_2];
					UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);
					SetPlayerSkin(playerid, pData[playerid][pSkin]);	

					flate[id_flate][wardrobe_skin_2] = -1;					
				}
				else
				{
					pData[playerid][pSkin] = flate[id_flate][wardrobe_skin_2];

					flate[id_flate][wardrobe_skin_2] = id_skin;

					UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);
					SetPlayerSkin(playerid, pData[playerid][pSkin]);	

					SendSucc(playerid, "Вы поменяли одежду!");					
				}
			}
			else
			{
				if(pData[playerid][pSkin] == 97)
				{
					pData[playerid][pSkin] = flate[id_flate][wardrobe_skin_2];
					UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);
					SetPlayerSkin(playerid, pData[playerid][pSkin]);

					flate[id_flate][wardrobe_skin_2] = -1;						
				}
				else
				{
					pData[playerid][pSkin] = flate[id_flate][wardrobe_skin_2];

					flate[id_flate][wardrobe_skin_2] = id_skin;

					UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);
					SetPlayerSkin(playerid, pData[playerid][pSkin]);	

					SendSucc(playerid, "Вы поменяли одежду!");					
				}
			}			

		}
	}
	ApplyAnimation(playerid, "PED", "ROADCROSS", 4.1, 0, 0, 0, 0, 0);
	save_flate(id_flate);
	show_wardrobe_menu_flate(playerid);
	return true;
}

stock skin_wardrobe_flate_3(playerid, id_flate, type)
{

	switch(type)
	{
		case WARDROBE_FLATE_SKIN_PUT:
		{
			if(flate[id_flate][wardrobe_skin_3] != -1 && flate[id_flate][wardrobe_skin_3] != 0)
			{
				show_skin_wardrobe_fl_select(playerid, id_flate, WARDROBE_FLATE_SKIN_3);
				return SendErr(playerid, "Вешалка уже занята, Вы не можете повесить туда одежду");
			}

			new 
				id_skin = GetPlayerSkin(playerid);

			flate[id_flate][wardrobe_skin_3] = id_skin;

			if(pData[playerid][pSex] == 2)
			{
				if(pData[playerid][pSkin] == 140)
				{
					show_skin_wardrobe_fl_select(playerid, id_flate, WARDROBE_FLATE_SKIN_3);
					return SendErr(playerid, "На вас нет одежды, чтобы повесить её!");
				}
				if(GetPVarIntNew(playerid, "askin"))
				{
					show_skin_wardrobe_fl_select(playerid, id_flate, WARDROBE_FLATE_SKIN_3);
					return SendErr(playerid, "Данную одежду нельзя повесить на вешалку!");
				}
				if(pData[playerid][pFractionSkin] == id_skin)
				{
					show_skin_wardrobe_fl_select(playerid, id_flate, WARDROBE_FLATE_SKIN_3);
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
					show_skin_wardrobe_fl_select(playerid, id_flate, WARDROBE_FLATE_SKIN_3);
					return SendErr(playerid, "На вас нет одежды, чтобы повесить её!");
				}
				if(GetPVarIntNew(playerid, "askin"))
				{
					show_skin_wardrobe_fl_select(playerid, id_flate, WARDROBE_FLATE_SKIN_3);
					return SendErr(playerid, "Данную одежду нельзя повесить на вешалку!");
				}
				if(pData[playerid][pFractionSkin] == id_skin)
				{
					show_skin_wardrobe_fl_select(playerid, id_flate, WARDROBE_FLATE_SKIN_3);
					return SendErr(playerid, "Данную одежду нельзя повесить на вешалку!");		
				}
				pData[playerid][pSkin] = 97;
				UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);

				SetPlayerSkin(playerid, 97);
			}

			SendSucc(playerid, "Вы повесили свою одежду в шкаф!");

		}
		case WARDROBE_FLATE_SKIN_INPUT:
		{
			if(flate[id_flate][wardrobe_skin_3] == -1 || !flate[id_flate][wardrobe_skin_3])
			{
				show_skin_wardrobe_fl_select(playerid, id_flate, WARDROBE_FLATE_SKIN_3);
				return SendErr(playerid, "На вешалке ничего нет!");
			}

			new 
				id_skin = GetPlayerSkin(playerid);

			if(pData[playerid][pSex] == 2)
			{
				if(pData[playerid][pSkin] == 140)
				{
					pData[playerid][pSkin] = flate[id_flate][wardrobe_skin_3];
					UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);
					SetPlayerSkin(playerid, pData[playerid][pSkin]);

					flate[id_flate][wardrobe_skin_3] = -1;						
				}
				else
				{
					pData[playerid][pSkin] = flate[id_flate][wardrobe_skin_3];

					flate[id_flate][wardrobe_skin_3] = id_skin;

					UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);
					SetPlayerSkin(playerid, pData[playerid][pSkin]);	

					SendSucc(playerid, "Вы поменяли одежду!");					
				}
			}
			else
			{
				if(pData[playerid][pSkin] == 97)
				{
					pData[playerid][pSkin] = flate[id_flate][wardrobe_skin_3];
					UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);
					SetPlayerSkin(playerid, pData[playerid][pSkin]);	

					flate[id_flate][wardrobe_skin_3] = -1;					
				}
				else
				{
					pData[playerid][pSkin] = flate[id_flate][wardrobe_skin_3];

					flate[id_flate][wardrobe_skin_3] = id_skin;

					UpdatePlayerData(playerid,"skin",pData[playerid][pSkin]);
					SetPlayerSkin(playerid, pData[playerid][pSkin]);	

					SendSucc(playerid, "Вы поменяли одежду!");					
				}
			}			

		}
	}
	ApplyAnimation(playerid, "PED", "ROADCROSS", 4.1, 0, 0, 0, 0, 0);
	save_flate(id_flate);
	show_wardrobe_menu_flate(playerid);
	return true;
}


stock skin_drop_flate_wardrobe(playerid, id_flate, type)
{
	switch(type)
	{
		case WADROBE_FLATE_SKIN_1:
		{
			if(flate[id_flate][wardrobe_skin_1] == -1 || flate[id_flate][wardrobe_skin_1] == 0)
				return SendErr(playerid, "На вешалке нет одежды, чтобы её выкидывать!");

			flate[id_flate][wardrobe_skin_1] = -1;
		}
		case WARDROBE_FLATE_SKIN_2:
		{
			if(flate[id_flate][wardrobe_skin_2] == -1 || flate[id_flate][wardrobe_skin_2] == 0)
				return SendErr(playerid, "На вешалке нет одежды, чтобы её выкидывать!");

			flate[id_flate][wardrobe_skin_2] = -1;
		}
		case WARDROBE_FLATE_SKIN_3:
		{
			if(flate[id_flate][wardrobe_skin_3] == -1 || flate[id_flate][wardrobe_skin_3] == 0)
				return SendErr(playerid, "На вешалке нет одежды, чтобы её выкидывать!");

			flate[id_flate][wardrobe_skin_3] = -1;
		}
	}
	SendSucc(playerid, "Вы успешно выкинули одежду с полки!");	
	save_flate(id_flate);
	show_wardrobe_menu_flate(playerid);
	return true;
}

stock show_aks_wardrobe_menu_flate(playerid, id_flate, type)
{

	switch(type)
	{
		case WARDROBE_AKS_FIRST:
		{	
			show_wardrobe_aks_select(playerid, id_flate, WARDROBE_AKS_FIRST);

		}
		case WARDROBE_AKS_TWO:
		{
			show_wardrobe_aks_select(playerid, id_flate, WARDROBE_AKS_TWO);	
		}
		case WARDROBE_AKS_THREE:
		{
			show_wardrobe_aks_select(playerid, id_flate, WARDROBE_AKS_THREE);
		}
	}


	return true;
}

stock show_wardrobe_aks_select(playerid, id_flate, type)
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
		    "cBLUE"- "cWH"Выкинуть аксессуар\t"cBLUE"Выкинуть", get_aks_wardrobe_flate(playerid, WARDROBE_AKS_FIRST, id_flate));
		    SPD(playerid, DIALOG_WARDROBE_POLKA_AKS_1_F, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Шкаф", fmt_str, !"Выбрать", !"Закрыть"); 	

		}
		case WARDROBE_AKS_TWO:
		{
		    format(fmt_str, 400, "\
		    "cGREY"Тип\t"cGREY"Информация\n\
		    "cBLUE"- "cWH"Положить аксессуар в шкаф\t"cBLUE"Повесить\n\
		    "cBLUE"- "cWH"Забрать аксессуар со второй полки\t"cBLUE"%s аксессуар\n\
		    "cBLUE"- "cWH"Выкинуть аксессуар\t"cBLUE"Выкинуть", get_aks_wardrobe_flate(playerid, WARDROBE_AKS_TWO, id_flate));
		    SPD(playerid, DIALOG_WARDROBE_POLKA_AKS_2_F, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Шкаф", fmt_str, !"Выбрать", !"Закрыть"); 	
		}
		case WARDROBE_AKS_THREE:
		{
		    format(fmt_str, 400, "\
		    "cGREY"Тип\t"cGREY"Информация\n\
		    "cBLUE"- "cWH"Положить аксессуар в шкаф\t"cBLUE"Повесить\n\
		    "cBLUE"- "cWH"Забрать аксессуар с третьей полки\t"cBLUE"%s аксессуар\n\
		    "cBLUE"- "cWH"Выкинуть аксессуар\t"cBLUE"Выкинуть", get_aks_wardrobe_flate(playerid, WARDROBE_AKS_THREE, id_flate));

		    SPD(playerid, DIALOG_WARDROBE_POLKA_AKS_3_F, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Шкаф", fmt_str, !"Выбрать", !"Закрыть"); 	
		}
	}
	return true;

}
stock select_aks_flate_wardrobe(playerid, type)
{
	switch(type)
	{
		case WARDROBE_AKS_FIRST:
		{
			SPD(playerid, DIALOG_SELECT_WARDROBE_F_P_1_1, DIALOG_STYLE_LIST, ""cBLUE"Шкаф", \
			""cBLUE"1."cWH" Положить кепку\n\
			"cBLUE"2."cWH" Положить маску\n\
			"cBLUE"3."cWH" Положить рюкзак", !"Выбрать", !"Закрыть");
		}
		case WARDROBE_AKS_TWO:
		{
			SPD(playerid, DIALOG_SELECT_WARDROBE_F_P_1_2, DIALOG_STYLE_LIST, ""cBLUE"Шкаф", \
			""cBLUE"1."cWH" Положить кепку\n\
			"cBLUE"2."cWH" Положить маску\n\
			"cBLUE"3."cWH" Положить рюкзак", !"Выбрать", !"Закрыть");
		}	
		case WARDROBE_AKS_THREE:
		{
			SPD(playerid, DIALOG_SELECT_WARDROBE_F_P_1_3, DIALOG_STYLE_LIST, ""cBLUE"Шкаф", \
			""cBLUE"1."cWH" Положить кепку\n\
			"cBLUE"2."cWH" Положить маску\n\
			"cBLUE"3."cWH" Положить рюкзак", !"Выбрать", !"Закрыть");
		}		
	}

	return true;
}

stock skin_aks_1_flate(playerid, id_flate, type)
{

	switch(type)
	{
		case WARDROBE_AKS_PUT:
		{
			if(flate[id_flate][wardrobe_aks_1] != -1)
			{
				show_wardrobe_aks_select(playerid, id_flate, WARDROBE_AKS_FIRST);
				return SendErr(playerid, "Полка уже занята, Вы не можете положить аксессуар на полку!");
			}

			new 
				id_skin = GetPVarIntNew(playerid, "type_select_aks");

			flate[id_flate][wardrobe_aks_1] = id_skin;

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
			if(flate[id_flate][wardrobe_aks_1] == -1)
			{
				show_wardrobe_aks_select(playerid, id_flate, WARDROBE_SKIN_FIRST);
				return SendErr(playerid, "На полке ничего нет!");
			}

			
			if(flate[id_flate][wardrobe_aks_1] == 10998 || flate[id_flate][wardrobe_aks_1] == 10999 || flate[id_flate][wardrobe_aks_1] == 11000 || flate[id_flate][wardrobe_aks_1] == 11001
			|| flate[id_flate][wardrobe_aks_1] == 18156 || flate[id_flate][wardrobe_aks_1] == 18157)
			{
				if(pData[playerid][pSlotItem][0] != -1)
				{
					SetPVarIntNew(playerid, "id_aks_home", pData[playerid][pSlotItem][0]);

					pData[playerid][pSlotItem][0] = flate[id_flate][wardrobe_aks_1];
					flate[id_flate][wardrobe_aks_1] = GetPVarIntNew(playerid, "id_aks_home");

					DeletePVarNew(playerid, "id_aks_home");
				}
				else
				{
					pData[playerid][pSlotItem][0] = flate[id_flate][wardrobe_aks_1];
					flate[id_flate][wardrobe_aks_1] = -1;
				}
			}	
			else if(flate[id_flate][wardrobe_aks_1] == 10971 || flate[id_flate][wardrobe_aks_1] == 10973 || flate[id_flate][wardrobe_aks_1] == 10974 || flate[id_flate][wardrobe_aks_1] == 10975
			|| flate[id_flate][wardrobe_aks_1] == 10976 || flate[id_flate][wardrobe_aks_1] == 10977 || flate[id_flate][wardrobe_aks_1] == 10978 || flate[id_flate][wardrobe_aks_1] == 10979 
			|| flate[id_flate][wardrobe_aks_1] == 10980 || flate[id_flate][wardrobe_aks_1] == 10981 || flate[id_flate][wardrobe_aks_1] == 10982
			|| flate[id_flate][wardrobe_aks_1] == 18158 || flate[id_flate][wardrobe_aks_1] == 18159 || flate[id_flate][wardrobe_aks_1] == 18160)
			{
				if(pData[playerid][pSlotItem][2] != -1)
				{
					SetPVarIntNew(playerid, "id_aks_home", pData[playerid][pSlotItem][2]);

					pData[playerid][pSlotItem][2] = flate[id_flate][wardrobe_aks_1];
					flate[id_flate][wardrobe_aks_1] = GetPVarIntNew(playerid, "id_aks_home");

					DeletePVarNew(playerid, "id_aks_home");
				}
				else
				{
					pData[playerid][pSlotItem][2] = flate[id_flate][wardrobe_aks_1];
					flate[id_flate][wardrobe_aks_1] = -1;
				}
			}	
			else if(flate[id_flate][wardrobe_aks_1] == 11002 || flate[id_flate][wardrobe_aks_1] == 11003 || flate[id_flate][wardrobe_aks_1] == 11004 || flate[id_flate][wardrobe_aks_1] == 11005
			|| flate[id_flate][wardrobe_aks_1] == 11006 || flate[id_flate][wardrobe_aks_1] == 11007)
			{
				if(pData[playerid][pSlotItem][3] != -1)
				{
					SetPVarIntNew(playerid, "id_aks_home", pData[playerid][pSlotItem][3]);

					pData[playerid][pSlotItem][3] = flate[id_flate][wardrobe_aks_1];
					flate[id_flate][wardrobe_aks_1] = GetPVarIntNew(playerid, "id_aks_home");

					DeletePVarNew(playerid, "id_aks_home");
				}
				else
				{
					pData[playerid][pSlotItem][3] = flate[id_flate][wardrobe_aks_1];
					flate[id_flate][wardrobe_aks_1] = -1;
				}
			}	
 
			AttachAcsToPlayer(playerid, GetPlayerSkin(playerid));
			SendSucc(playerid, "Вы взяли аксессуар со шкафа!");	
			
		}

	}
	ApplyAnimation(playerid, "PED", "ROADCROSS", 4.1, 0, 0, 0, 0, 0);
	save_flate(id_flate);
	show_wardrobe_menu(playerid);
	return true;
}

stock skin_aks_2_flate(playerid, id_flate, type)
{

	switch(type)
	{
		case WARDROBE_AKS_PUT:
		{
			if(flate[id_flate][wardrobe_aks_2] != -1)
			{
				show_wardrobe_aks_select(playerid, id_flate, WARDROBE_AKS_FIRST);
				return SendErr(playerid, "Полка уже занята, Вы не можете положить аксессуар на полку!");
			}

			new 
				id_skin = GetPVarIntNew(playerid, "type_select_aks");

			flate[id_flate][wardrobe_aks_2] = id_skin;

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
			if(flate[id_flate][wardrobe_aks_2] == -1)
			{
				show_wardrobe_aks_select(playerid, id_flate, WARDROBE_SKIN_FIRST);
				return SendErr(playerid, "На полке ничего нет!");
			}

			
			if(flate[id_flate][wardrobe_aks_2] == 10998 || flate[id_flate][wardrobe_aks_2] == 10999 || flate[id_flate][wardrobe_aks_2] == 11000 || flate[id_flate][wardrobe_aks_2] == 11001
			|| flate[id_flate][wardrobe_aks_2] == 18156 || flate[id_flate][wardrobe_aks_2] == 18157)
			{
				if(pData[playerid][pSlotItem][0] != -1)
				{
					SetPVarIntNew(playerid, "id_aks_home", pData[playerid][pSlotItem][0]);

					pData[playerid][pSlotItem][0] = flate[id_flate][wardrobe_aks_2];
					flate[id_flate][wardrobe_aks_2] = GetPVarIntNew(playerid, "id_aks_home");

					DeletePVarNew(playerid, "id_aks_home");
				}
				else
				{
					pData[playerid][pSlotItem][0] = flate[id_flate][wardrobe_aks_2];
					flate[id_flate][wardrobe_aks_2] = -1;
				}
			}	
			else if(flate[id_flate][wardrobe_aks_2] == 10971 || flate[id_flate][wardrobe_aks_2] == 10973 || flate[id_flate][wardrobe_aks_2] == 10974 || flate[id_flate][wardrobe_aks_2] == 10975
			|| flate[id_flate][wardrobe_aks_2] == 10976 || flate[id_flate][wardrobe_aks_2] == 10977 || flate[id_flate][wardrobe_aks_2] == 10978 || flate[id_flate][wardrobe_aks_2] == 10979 
			|| flate[id_flate][wardrobe_aks_2] == 10980 || flate[id_flate][wardrobe_aks_2] == 10981 || flate[id_flate][wardrobe_aks_2] == 10982
			|| flate[id_flate][wardrobe_aks_2] == 18158 || flate[id_flate][wardrobe_aks_2] == 18159 || flate[id_flate][wardrobe_aks_2] == 18160)
			{
				if(pData[playerid][pSlotItem][2] != -1)
				{
					SetPVarIntNew(playerid, "id_aks_home", pData[playerid][pSlotItem][2]);

					pData[playerid][pSlotItem][2] = flate[id_flate][wardrobe_aks_2];
					flate[id_flate][wardrobe_aks_2] = GetPVarIntNew(playerid, "id_aks_home");

					DeletePVarNew(playerid, "id_aks_home");
				}
				else
				{
					pData[playerid][pSlotItem][2] = flate[id_flate][wardrobe_aks_2];
					flate[id_flate][wardrobe_aks_2] = -1;
				}
			}	
			else if(flate[id_flate][wardrobe_aks_2] == 11002 || flate[id_flate][wardrobe_aks_2] == 11003 || flate[id_flate][wardrobe_aks_2] == 11004 || flate[id_flate][wardrobe_aks_2] == 11005
			|| flate[id_flate][wardrobe_aks_2] == 11006 || flate[id_flate][wardrobe_aks_2] == 11007)
			{
				if(pData[playerid][pSlotItem][3] != -1)
				{
					SetPVarIntNew(playerid, "id_aks_home", pData[playerid][pSlotItem][3]);

					pData[playerid][pSlotItem][3] = flate[id_flate][wardrobe_aks_2];
					flate[id_flate][wardrobe_aks_2] = GetPVarIntNew(playerid, "id_aks_home");

					DeletePVarNew(playerid, "id_aks_home");
				}
				else
				{
					pData[playerid][pSlotItem][3] = flate[id_flate][wardrobe_aks_2];
					flate[id_flate][wardrobe_aks_2] = -1;
				}
			}	

			AttachAcsToPlayer(playerid, GetPlayerSkin(playerid));
			SendSucc(playerid, "Вы взяли аксессуар со шкафа!");	
			
		}

	}
	ApplyAnimation(playerid, "PED", "ROADCROSS", 4.1, 0, 0, 0, 0, 0);
	save_flate(id_flate);
	show_wardrobe_menu(playerid);
	return true;
}

stock skin_aks_3_flate(playerid, id_flate, type)
{

	switch(type)
	{
		case WARDROBE_AKS_PUT:
		{
			if(flate[id_flate][wardrobe_aks_3] != -1)
			{
				show_wardrobe_aks_select(playerid, id_flate, WARDROBE_AKS_FIRST);
				return SendErr(playerid, "Полка уже занята, Вы не можете положить аксессуар на полку!");
			}

			new 
				id_skin = GetPVarIntNew(playerid, "type_select_aks");

			flate[id_flate][wardrobe_aks_3] = id_skin;

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
			if(flate[id_flate][wardrobe_aks_3] == -1)
			{
				show_wardrobe_aks_select(playerid, id_flate, WARDROBE_SKIN_FIRST);
				return SendErr(playerid, "На полке ничего нет!");
			}

			
			if(flate[id_flate][wardrobe_aks_3] == 10998 || flate[id_flate][wardrobe_aks_3] == 10999 || flate[id_flate][wardrobe_aks_3] == 11000 || flate[id_flate][wardrobe_aks_3] == 11001
			|| flate[id_flate][wardrobe_aks_3] == 18156 || flate[id_flate][wardrobe_aks_3] == 18157)
			{
				if(pData[playerid][pSlotItem][0] != -1)
				{
					SetPVarIntNew(playerid, "id_aks_home", pData[playerid][pSlotItem][0]);

					pData[playerid][pSlotItem][0] = flate[id_flate][wardrobe_aks_3];
					flate[id_flate][wardrobe_aks_3] = GetPVarIntNew(playerid, "id_aks_home");

					DeletePVarNew(playerid, "id_aks_home");
				}
				else
				{
					pData[playerid][pSlotItem][0] = flate[id_flate][wardrobe_aks_3];
					flate[id_flate][wardrobe_aks_3] = -1;
				}
			}	
			else if(flate[id_flate][wardrobe_aks_3] == 10971 || flate[id_flate][wardrobe_aks_3] == 10973 || flate[id_flate][wardrobe_aks_3] == 10974 || flate[id_flate][wardrobe_aks_3] == 10975
			|| flate[id_flate][wardrobe_aks_3] == 10976 || flate[id_flate][wardrobe_aks_3] == 10977 || flate[id_flate][wardrobe_aks_3] == 10978 || flate[id_flate][wardrobe_aks_3] == 10979 
			|| flate[id_flate][wardrobe_aks_3] == 10980 || flate[id_flate][wardrobe_aks_3] == 10981 || flate[id_flate][wardrobe_aks_3] == 10982
			|| flate[id_flate][wardrobe_aks_3] == 18158 || flate[id_flate][wardrobe_aks_3] == 18159 || flate[id_flate][wardrobe_aks_3] == 18160)
			{
				if(pData[playerid][pSlotItem][2] != -1)
				{
					SetPVarIntNew(playerid, "id_aks_home", pData[playerid][pSlotItem][2]);

					pData[playerid][pSlotItem][2] = flate[id_flate][wardrobe_aks_3];
					flate[id_flate][wardrobe_aks_3] = GetPVarIntNew(playerid, "id_aks_home");

					DeletePVarNew(playerid, "id_aks_home");
				}
				else
				{
					pData[playerid][pSlotItem][2] = flate[id_flate][wardrobe_aks_3];
					flate[id_flate][wardrobe_aks_3] = -1;
				}
			}	
			else if(flate[id_flate][wardrobe_aks_3] == 11002 || flate[id_flate][wardrobe_aks_3] == 11003 || flate[id_flate][wardrobe_aks_3] == 11004 || flate[id_flate][wardrobe_aks_3] == 11005
			|| flate[id_flate][wardrobe_aks_3] == 11006 || flate[id_flate][wardrobe_aks_3] == 11007)
			{
				if(pData[playerid][pSlotItem][3] != -1)
				{
					SetPVarIntNew(playerid, "id_aks_home", pData[playerid][pSlotItem][3]);

					pData[playerid][pSlotItem][3] = flate[id_flate][wardrobe_aks_3];
					flate[id_flate][wardrobe_aks_3] = GetPVarIntNew(playerid, "id_aks_home");

					DeletePVarNew(playerid, "id_aks_home");
				}
				else
				{
					pData[playerid][pSlotItem][3] = flate[id_flate][wardrobe_aks_3];
					flate[id_flate][wardrobe_aks_3] = -1;
				}
			}	

			AttachAcsToPlayer(playerid, GetPlayerSkin(playerid));
			SendSucc(playerid, "Вы взяли аксессуар со шкафа!");	
			
		}

	}
	ApplyAnimation(playerid, "PED", "ROADCROSS", 4.1, 0, 0, 0, 0, 0);
	save_flate(id_flate);
	show_wardrobe_menu(playerid);
	return true;
}

stock aks_drop_wardrobe_flate(playerid, id_flate, type)
{
	switch(type)
	{
		case WARDROBE_AKS_FIRST:
		{
			if(flate[id_flate][wardrobe_aks_1] == -1)
				return SendErr(playerid, "На полке нет аксессуара, чтобы его выкидывать!");

			flate[id_flate][wardrobe_aks_1] = -1;
		}
		case WARDROBE_AKS_TWO:
		{
			if(flate[id_flate][wardrobe_aks_2] == -1)
				return SendErr(playerid, "На полке нет аксессуара, чтобы его выкидывать!");

			flate[id_flate][wardrobe_aks_2] = -1;
		}
		case WARDROBE_AKS_THREE:
		{
			if(flate[id_flate][wardrobe_aks_3] == -1)
				return SendErr(playerid, "На полке нет аксессуара, чтобы его выкидывать!");

			flate[id_flate][wardrobe_aks_3] = -1;
		}
	}
	SendSucc(playerid, "Вы успешно выкинули аксессуар с полки!");	
	save_flate(id_flate);
	show_wardrobe_menu(playerid);
	return true;
}

stock weapon_flate_wardrobe_select(playerid, id_flate, type)
{
	new 
		fmt_str[400];

	switch(type)
	{
		case WARDROBE_GUN_1:
		{	
		    format(fmt_str, 400, "\
		    "cGREY"Тип\t"cGREY"Информация\n\
		    "cBLUE"- "cWH"Положить оружие в шкаф\t"cBLUE"Положить\n\
		    "cBLUE"- "cWH"Забрать оружие с первой полки\t"cBLUE"%s\n\
		    "cBLUE"- "cWH"Выкинуть оружие\t"cBLUE"Выкинуть", get_weapon_wardrobe_flate(playerid, WARDROBE_GUN_1, id_flate));
		    SPD(playerid, DIALOG_WARDROBE_G_1_FLATE, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Шкаф", fmt_str, !"Выбрать", !"Закрыть"); 	

		}
		case WADROBE_GUN_2:
		{
		    format(fmt_str, 400, "\
		    "cGREY"Тип\t"cGREY"Информация\n\
		    "cBLUE"- "cWH"Положить оружие в шкаф\t"cBLUE"Положить\n\
		    "cBLUE"- "cWH"Забрать оружие со второй полки\t"cBLUE"%s\n\
		    "cBLUE"- "cWH"Выкинуть оружие\t"cBLUE"Выкинуть", get_weapon_wardrobe_flate(playerid, WADROBE_GUN_2, id_flate));
		    SPD(playerid, DIALOG_WARDROBE_G_2_FLATE, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Шкаф", fmt_str, !"Выбрать", !"Закрыть"); 	
		}
		case WARDROBE_GUN_3:
		{
		    format(fmt_str, 400, "\
		    "cGREY"Тип\t"cGREY"Информация\n\
		    "cBLUE"- "cWH"Положить оружие в шкаф\t"cBLUE"Положить\n\
		    "cBLUE"- "cWH"Забрать оружие с третьей полки\t"cBLUE"%s\n\
		    "cBLUE"- "cWH"Выкинуть оружие\t"cBLUE"Выкинуть", get_weapon_wardrobe_flate(playerid, WARDROBE_GUN_3, id_flate));

		    SPD(playerid, DIALOG_WARDROBE_G_3_FLATE, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Шкаф", fmt_str, !"Выбрать", !"Закрыть"); 	
		}
	}
	return true;

}

stock weapon_menu_wardrobe_flate(playerid, id_flate, type)
{


	switch(type)
	{
		case WARDROBE_GUN_1:
		{
			weapon_flate_wardrobe_select(playerid, id_flate, WARDROBE_GUN_1);
		}
		case WADROBE_GUN_2:
		{
			weapon_flate_wardrobe_select(playerid, id_flate, WADROBE_GUN_2);	
		}
		case WARDROBE_GUN_3:
		{
			weapon_flate_wardrobe_select(playerid, id_flate, WARDROBE_GUN_3);	
		}
	}


	return true;
}

stock gun_wardrobe_flate_1(playerid, id_flate, type)
{
	new 
		weap_name[30];

	switch(type)
	{
		case WARDROBE_GUN_FLATE_PUT:
		{
			if(flate[id_flate][wardrobe_gun_1] == -1)
			{
				new 
					gun_id = GetPlayerWeapon(playerid);

				new 
					ammo = GetPlayerAmmo(playerid);	

				if(gun_id == 0)
				{
					SendErr(playerid, "Сперва выберите оружие, которое хотите положить на полку в шкафу!");
					return weapon_flate_wardrobe_select(playerid, id_flate, WARDROBE_GUN_1);
				}

				RemovePlayerWeapon(playerid, gun_id);

				flate[id_flate][wardrobe_gun_1] = gun_id;
				flate[id_flate][wardrobe_gun_ammo_1] = ammo;

				GetWeaponName(gun_id, weap_name, 30);

				SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы положили в шкаф %s с %d патронами", weap_name, ammo);
			}
			else
			{
				weapon_flate_wardrobe_select(playerid, id_flate, WARDROBE_GUN_1);
				return SendErr(playerid, "В полке уже лежит оружие, Вы не можете положить новое!");
			}
		}
		case WARDROBE_GUN_FLATE_INPUT:
		{
			if(flate[id_flate][wardrobe_gun_1] == -1)
			{
				SendErr(playerid, "Полка в шкафу пустая!");
				return weapon_flate_wardrobe_select(playerid, id_flate, WARDROBE_GUN_1);
			}			
			else
			{	new 
					gun_input = flate[id_flate][wardrobe_gun_1],
					ammo_input = flate[id_flate][wardrobe_gun_ammo_1];


				GivePlayerWeaponEx(playerid, gun_input, ammo_input);

				flate[id_flate][wardrobe_gun_1] = -1;
				flate[id_flate][wardrobe_gun_ammo_1] = 0;

				GetWeaponName(gun_input, weap_name, 30);

				SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы достали из шкафа %s с %d патронами", weap_name, ammo_input);
			}
		}
	}
	save_flate(id_flate);
	ApplyAnimation(playerid, "UZI", "UZI_RELOAD", 4.1, 0, 0, 0, 0, 0);
	return true;
}

stock gun_wardrobe_flate_2(playerid, id_flate, type)
{
	new 
		weap_name[30];
		
	switch(type)
	{
		case WARDROBE_GUN_FLATE_PUT:
		{
			if(flate[id_flate][wardrobe_gun_2] == -1)
			{
				new 
					gun_id = GetPlayerWeapon(playerid);

				new 
					ammo = GetPlayerAmmo(playerid);	

				if(gun_id == 0)
				{
					SendErr(playerid, "Сперва выберите оружие, которое хотите положить на полку в шкафу!");
					return weapon_flate_wardrobe_select(playerid, id_flate, WADROBE_GUN_2);
				}

				RemovePlayerWeapon(playerid, gun_id);

				flate[id_flate][wardrobe_gun_2] = gun_id;
				flate[id_flate][wardrobe_gun_ammo_2] = ammo;

				GetWeaponName(gun_id, weap_name, 30);

				SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы положили в шкаф %s с %d патронами", weap_name, ammo);
			}
			else
			{
				weapon_flate_wardrobe_select(playerid, id_flate, WADROBE_GUN_2);
				return SendErr(playerid, "В полке уже лежит оружие, Вы не можете положить новое!");
			}
		}
		case WARDROBE_GUN_FLATE_INPUT:
		{
			if(flate[id_flate][wardrobe_gun_2] == -1)
			{
				SendErr(playerid, "Полка в шкафу пустая!");
				return weapon_flate_wardrobe_select(playerid, id_flate, WADROBE_GUN_2);
			}			
			else
			{	new 
					gun_input = flate[id_flate][wardrobe_gun_2],
					ammo_input = flate[id_flate][wardrobe_gun_ammo_2];


				GivePlayerWeaponEx(playerid, gun_input, ammo_input);

				flate[id_flate][wardrobe_gun_2] = -1;
				flate[id_flate][wardrobe_gun_ammo_2] = 0;

				GetWeaponName(gun_input, weap_name, 30);

				SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы достали из шкафа %s с %d патронами", weap_name, ammo_input);
			}
		}
	}
	save_flate(id_flate);
	ApplyAnimation(playerid, "UZI", "UZI_RELOAD", 4.1, 0, 0, 0, 0, 0);
	return true;
}

stock gun_wardrobe_flate_3(playerid, id_flate, type)
{
	new 
		weap_name[30];
		
	switch(type)
	{
		case WARDROBE_GUN_FLATE_PUT:
		{
			if(flate[id_flate][wardrobe_gun_3] == -1)
			{
				new 
					gun_id = GetPlayerWeapon(playerid);

				new 
					ammo = GetPlayerAmmo(playerid);	

				if(gun_id == 0)
				{
					SendErr(playerid, "Сперва выберите оружие, которое хотите положить на полку в шкафу!");
					return weapon_flate_wardrobe_select(playerid, id_flate, WARDROBE_GUN_3);
				}

				RemovePlayerWeapon(playerid, gun_id);

				flate[id_flate][wardrobe_gun_3] = gun_id;
				flate[id_flate][wardrobe_gun_ammo_3] = ammo;

				GetWeaponName(gun_id, weap_name, 30);

				SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы положили в шкаф %s с %d патронами", weap_name, ammo);
			}
			else
			{
				weapon_flate_wardrobe_select(playerid, id_flate, WARDROBE_GUN_3);
				return SendErr(playerid, "В полке уже лежит оружие, Вы не можете положить новое!");
			}
		}
		case WARDROBE_GUN_FLATE_INPUT:
		{
			if(flate[id_flate][wardrobe_gun_3] == -1)
			{
				SendErr(playerid, "Полка в шкафу пустая!");
				return weapon_flate_wardrobe_select(playerid, id_flate, WARDROBE_GUN_3);
			}			
			else
			{	new 
					gun_input = flate[id_flate][wardrobe_gun_3],
					ammo_input = flate[id_flate][wardrobe_gun_ammo_3];


				GivePlayerWeaponEx(playerid, gun_input, ammo_input);

				flate[id_flate][wardrobe_gun_3] = -1;
				flate[id_flate][wardrobe_gun_ammo_3] = 0;

				GetWeaponName(gun_input, weap_name, 30);

				SFCM(playerid,0xFFFFFFFF,"• {FFC800}[Подсказка] "cWH"Вы достали из шкафа %s с %d патронами", weap_name, ammo_input);
			}
		}
	}
	save_flate(id_flate);
	ApplyAnimation(playerid, "UZI", "UZI_RELOAD", 4.1, 0, 0, 0, 0, 0);
	return true;
}


stock gun_drop_wardrobe_flate(playerid, id_flate, type)
{
	switch(type)
	{
		case WARDROBE_GUN_1:
		{	
			if(flate[id_flate][wardrobe_gun_1] == -1 || flate[id_flate][wardrobe_gun_ammo_1] > 0)
				return SendErr(playerid, "На полке нет оружия, чтобы его выкидывать!");

			flate[id_flate][wardrobe_gun_1] = -1;
			flate[id_flate][wardrobe_gun_ammo_1] = 0;
		}
		case WADROBE_GUN_2:
		{
			if(flate[id_flate][wardrobe_gun_2] == -1 || flate[id_flate][wardrobe_gun_ammo_2] > 0)
				return SendErr(playerid, "На полке нет оружия, чтобы его выкидывать!");

			flate[id_flate][wardrobe_gun_2] = -1;
			flate[id_flate][wardrobe_gun_ammo_2] = 0;
		}
		case WARDROBE_GUN_3:
		{
			if(flate[id_flate][wardrobe_gun_3] == -1 || flate[id_flate][wardrobe_gun_ammo_3] > 0)
				return SendErr(playerid, "На полке нет оружия, чтобы его выкидывать!");

			flate[id_flate][wardrobe_gun_3] = -1;
			flate[id_flate][wardrobe_gun_ammo_3] = 0;
		}
	}
	SendSucc(playerid, "Вы успешно выкинули одежду с полки!");	
	save_flate(id_flate);
	show_wardrobe_menu_flate(playerid);
	return true;
}

stock change_skin_wardrobe_menu_f(playerid)
{
	if(pData[playerid][pFraction] && pData[playerid][pFractionSkin] != GetPlayerSkin(playerid))
	{
		set_player_skin(playerid,pData[playerid][pFractionSkin]);
	}
	else 
	{
		set_player_skin(playerid,pData[playerid][pSkin]);
	}                    
	show_wardrobe_menu_flate(playerid);	
	return true;
}


stock dialog_flate_wardrobe(playerid, dialogid, response, listitem)
{

	switch(dialogid)
	{
		case DIALOG_GENERAL_WARDROBE_FLATE:
		{
			new 
				id_flate = pData[playerid][pFlate];

			if(!response)
				return true;

			switch(listitem)
			{
				case 0: return show_skin_wadrobe_fl_menu(playerid, id_flate, WADROBE_FLATE_SKIN_1);
				case 1: return show_skin_wadrobe_fl_menu(playerid, id_flate, WARDROBE_FLATE_SKIN_2);
				case 2: return show_skin_wadrobe_fl_menu(playerid, id_flate, WARDROBE_FLATE_SKIN_3);
				case 3:	return show_wardrobe_menu_flate(playerid);
				case 4: return weapon_menu_wardrobe_flate(playerid, id_flate, WARDROBE_GUN_1);
				case 5: return weapon_menu_wardrobe_flate(playerid, id_flate, WADROBE_GUN_2);
				case 6: return weapon_menu_wardrobe_flate(playerid, id_flate, WARDROBE_GUN_3);
				case 7:	return show_wardrobe_menu_flate(playerid);
				case 8: return show_aks_wardrobe_menu_flate(playerid, id_flate, WARDROBE_AKS_FIRST); 
				case 9: return show_aks_wardrobe_menu_flate(playerid, id_flate, WARDROBE_AKS_TWO); 
				case 10: return show_aks_wardrobe_menu_flate(playerid, id_flate, WARDROBE_AKS_THREE); 	
				case 11: return show_wardrobe_menu_flate(playerid);
				case 12: return change_skin_wardrobe_menu_f(playerid);		
			}	
		}
		case DIALOG_WARDROBE_POLKA_AKS_1_F:
		{
			new 
				id_flate = pData[playerid][pFlate];

			if(!response)
				return show_wardrobe_menu(playerid);

			switch(listitem)
			{
				case 0:
				{
					select_aks_flate_wardrobe(playerid, WARDROBE_AKS_FIRST);
				}
				case 1:
				{
					skin_aks_1_flate(playerid, id_flate, WARDROBE_AKS_INPUT);
				}
				case 2:
				{
					aks_drop_wardrobe_flate(playerid, id_flate, WARDROBE_AKS_FIRST);
				}
			}		
		}
		case DIALOG_WARDROBE_POLKA_AKS_2_F:
		{
			new 
				id_flate = pData[playerid][pFlate];

			if(!response)
				return show_wardrobe_menu(playerid);

			switch(listitem)
			{
				case 0:
				{
					select_aks_flate_wardrobe(playerid, WARDROBE_AKS_TWO);
				}
				case 1:
				{
					skin_aks_2_flate(playerid, id_flate, WARDROBE_AKS_INPUT);
				}
				case 2:
				{
					aks_drop_wardrobe_flate(playerid, id_flate, WARDROBE_AKS_TWO);
				}
			}

		}
		case DIALOG_WARDROBE_POLKA_AKS_3_F:
		{
			new 
				id_flate = pData[playerid][pFlate];

			if(!response)
				return show_wardrobe_menu(playerid);

			switch(listitem)
			{
				case 0:
				{
					select_aks_flate_wardrobe(playerid, WARDROBE_AKS_THREE);
				}
				case 1:
				{
					skin_aks_3_flate(playerid, id_flate, WARDROBE_AKS_INPUT);
				}
				case 2:
				{
					aks_drop_wardrobe_flate(playerid, id_flate, WARDROBE_AKS_THREE);
				}
			}	
		}
		case DIALOG_SELECT_WARDROBE_F_P_1_1:
		{
			new 
				id_flate = pData[playerid][pFlate];

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
					skin_aks_1_flate(playerid, id_flate, WARDROBE_AKS_PUT);
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
					skin_aks_1_flate(playerid, id_flate, WARDROBE_AKS_PUT);
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
					skin_aks_1_flate(playerid, id_flate, WARDROBE_AKS_PUT);
				}
			}			
		}
		case DIALOG_SELECT_WARDROBE_F_P_1_2:
		{
			new 
				id_flate = pData[playerid][pFlate];

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
					skin_aks_2_flate(playerid, id_flate, WARDROBE_AKS_PUT);
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
					skin_aks_2_flate(playerid, id_flate, WARDROBE_AKS_PUT);
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
					skin_aks_2_flate(playerid, id_flate, WARDROBE_AKS_PUT);
				}
			}			
		}
		case DIALOG_SELECT_WARDROBE_F_P_1_3:
		{
			new 
				id_flate = pData[playerid][pFlate];

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
					skin_aks_3_flate(playerid, id_flate, WARDROBE_AKS_PUT);
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
					skin_aks_3_flate(playerid, id_flate, WARDROBE_AKS_PUT);
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
					skin_aks_3_flate(playerid, id_flate, WARDROBE_AKS_PUT);
				}
			}			
		}
		case DIALOG_WADROBE_1_FLATE:
		{
			new 
				id_flate = pData[playerid][pFlate];

			if(!response)
				return show_wardrobe_menu_flate(playerid);

			switch(listitem)
			{
				case 0: return skin_wardrobe_flate_1(playerid, id_flate, WARDROBE_FLATE_SKIN_PUT);
				case 1: return skin_wardrobe_flate_1(playerid, id_flate, WARDROBE_FLATE_SKIN_INPUT);
				case 2: return skin_drop_flate_wardrobe(playerid, id_flate, WADROBE_FLATE_SKIN_1);
			}

		}
		case DIALOG_WARDROBE_2_FLATE:
		{
			new 
				id_flate = pData[playerid][pFlate];

			if(!response)
				return show_wardrobe_menu_flate(playerid);

			switch(listitem)
			{
				case 0: return skin_wardrobe_flate_2(playerid, id_flate, WARDROBE_FLATE_SKIN_PUT);
				case 1: return skin_wardrobe_flate_2(playerid, id_flate, WARDROBE_FLATE_SKIN_INPUT);
				case 2: return skin_drop_flate_wardrobe(playerid, id_flate, WARDROBE_FLATE_SKIN_2);
			}

			
		}
		case DIALOG_WARDROBE_3_FLATE:
		{
			new 
				id_flate = pData[playerid][pFlate];

			if(!response)
				return show_wardrobe_menu_flate(playerid);

			switch(listitem)
			{
				case 0: return skin_wardrobe_flate_3(playerid, id_flate, WARDROBE_FLATE_SKIN_PUT);
				case 1: return skin_wardrobe_flate_3(playerid, id_flate, WARDROBE_FLATE_SKIN_INPUT);
				case 2: return skin_drop_flate_wardrobe(playerid, id_flate, WARDROBE_FLATE_SKIN_3);
			}
		}
		case DIALOG_WARDROBE_G_1_FLATE:
		{
			new 
				id_flate = pData[playerid][pFlate];

			if(!response)
				return show_wardrobe_menu_flate(playerid);

			switch(listitem)
			{
				case 0: return gun_wardrobe_flate_1(playerid, id_flate, WARDROBE_GUN_FLATE_PUT);
				case 1: return gun_wardrobe_flate_1(playerid, id_flate, WARDROBE_GUN_FLATE_INPUT);
				case 2: return gun_drop_wardrobe_flate(playerid, id_flate, WARDROBE_GUN_1);
			}
		}
		case DIALOG_WARDROBE_G_2_FLATE:
		{
			new 
				id_flate = pData[playerid][pFlate];

			if(!response)
				return show_wardrobe_menu_flate(playerid);

			switch(listitem)
			{
				case 0: return gun_wardrobe_flate_2(playerid, id_flate, WARDROBE_GUN_FLATE_PUT);
				case 1: return gun_wardrobe_flate_2(playerid, id_flate, WARDROBE_GUN_FLATE_INPUT);
				case 2: return gun_drop_wardrobe_flate(playerid, id_flate, WADROBE_GUN_2);
			}
		}
		case DIALOG_WARDROBE_G_3_FLATE:
		{
			new 
				id_flate = pData[playerid][pFlate];

			if(!response)
				return show_wardrobe_menu_flate(playerid);

			switch(listitem)
			{
				case 0: return gun_wardrobe_flate_3(playerid, id_flate, WARDROBE_GUN_FLATE_PUT);
				case 1: return gun_wardrobe_flate_3(playerid, id_flate, WARDROBE_GUN_FLATE_INPUT);
				case 2: return gun_drop_wardrobe_flate(playerid, id_flate, WARDROBE_GUN_3);
			}
		}
	}
	return true;
}