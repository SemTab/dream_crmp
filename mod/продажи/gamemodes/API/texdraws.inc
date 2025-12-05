
stock create_all_textdraws()
{
	create_phone_td();
	create_phone_general();
	create_fill_lukoil();
	create_alt_button_info();
	create_fill_gazprom();
	create_button_charge_tesla();
	create_alt_info();
	create_bus_timer_back();
	create_casino_p();
	create_miner_job_all();
	background_newyear();
	create_quest_newyear_td();
	create_hud_element();
	create_trucker_job_panel();
	create_autosalon_low();
	create_autosalon_middle();
	create_autosalon_elite();
	create_factory_job_1();
	create_factory_job_2();
	create_mechanic_background();
	create_clothes_shop();
	create_autoschool_select_auto(); 
	create_autoschool_select_vert();
	create_autoschool_select_aqua();
	create_autoschool_panel_general();
	create_inventory_global();
	create_load_screen_p();
	create_select_spawn();
	prize_newyear_td();
	create_aks_shop();
	create_voice_td();
	create_number_td();
	create_race_td();
	create_gui_other();
	create_rent_katok();
	create_mafia_timer();
	create_hospital_npc();

	create_fast_menu();
	create_start_info();

	create_teplica_td();

	create_fire_work_p();
	create_fire_work_back();
	create_fish_other_td();
	create_vehicle_key();
	create_vehicke_key_electro();
	return true;
}

stock create_teplica_td()
{

	menu_teplica_general_st[0] = TextDrawCreate(489.666595, 46.459259, "brilliantother:teplica_info_gui_8"); // Texture element
	TextDrawLetterSize(menu_teplica_general_st[0], 0.000000, 0.000000);
	TextDrawTextSize(menu_teplica_general_st[0], 79.666618, 99.555511);
	TextDrawAlignment(menu_teplica_general_st[0], 2);
	TextDrawColor(menu_teplica_general_st[0], -1);
	TextDrawSetShadow(menu_teplica_general_st[0], 0);
	TextDrawSetOutline(menu_teplica_general_st[0], 0);
	TextDrawFont(menu_teplica_general_st[0], 4);
	TextDrawSetSelectable(menu_teplica_general_st[0], true);

	menu_teplica_general_st[1] = TextDrawCreate(490.333343, 150.163040, "brilliantother:teplica_info_gui_9"); // Texture element
	TextDrawLetterSize(menu_teplica_general_st[1], 0.000000, 0.000000);
	TextDrawTextSize(menu_teplica_general_st[1], 79.999961, 102.459281);
	TextDrawAlignment(menu_teplica_general_st[1], 2);
	TextDrawColor(menu_teplica_general_st[1], -1);
	TextDrawSetShadow(menu_teplica_general_st[1], 0);
	TextDrawSetOutline(menu_teplica_general_st[1], 0);
	TextDrawFont(menu_teplica_general_st[1], 4);
	TextDrawSetSelectable(menu_teplica_general_st[1], true);

	menu_teplica_general_st[2] = TextDrawCreate(489.666534, 256.770294, "brilliantother:teplica_info_gui_10"); // Texture element
	TextDrawLetterSize(menu_teplica_general_st[2], 0.000000, 0.000000);
	TextDrawTextSize(menu_teplica_general_st[2], 81.333297, 104.118530);
	TextDrawAlignment(menu_teplica_general_st[2], 2);
	TextDrawColor(menu_teplica_general_st[2], -1);
	TextDrawSetShadow(menu_teplica_general_st[2], 0);
	TextDrawSetOutline(menu_teplica_general_st[2], 0);
	TextDrawFont(menu_teplica_general_st[2], 4);
	TextDrawSetSelectable(menu_teplica_general_st[2], true);

	menu_teplica_general_st[3] = TextDrawCreate(564.666687, 14.103702, "brilliantother:close_button_big"); // Texture element
	TextDrawLetterSize(menu_teplica_general_st[3], 0.000000, 0.000000);
	TextDrawTextSize(menu_teplica_general_st[3], 47.999973, 55.585163);
	TextDrawAlignment(menu_teplica_general_st[3], 1);
	TextDrawColor(menu_teplica_general_st[3], -1);
	TextDrawSetShadow(menu_teplica_general_st[3], 0);
	TextDrawSetOutline(menu_teplica_general_st[3], 0);
	TextDrawFont(menu_teplica_general_st[3], 4);
	TextDrawSetSelectable(menu_teplica_general_st[3], true);

	menu_teplica_general_st[4] = TextDrawCreate(142.333236, 49.777782, "brilliantother:teplica_buy_semena_1"); // Texture element
	TextDrawLetterSize(menu_teplica_general_st[4], 0.000000, 0.000000);
	TextDrawTextSize(menu_teplica_general_st[4], 81.999992, 102.044418);
	TextDrawAlignment(menu_teplica_general_st[4], 1);
	TextDrawColor(menu_teplica_general_st[4], -1);
	TextDrawSetShadow(menu_teplica_general_st[4], 0);
	TextDrawSetOutline(menu_teplica_general_st[4], 0);
	TextDrawFont(menu_teplica_general_st[4], 4);
	TextDrawSetSelectable(menu_teplica_general_st[4], true);

	menu_teplica_general_st[5] = TextDrawCreate(231.666580, 48.948158, "brilliantother:teplica_buy_semena_2"); // Texture element
	TextDrawLetterSize(menu_teplica_general_st[5], 0.000000, 0.000000);
	TextDrawTextSize(menu_teplica_general_st[5], 81.999992, 102.044418);
	TextDrawAlignment(menu_teplica_general_st[5], 1);
	TextDrawColor(menu_teplica_general_st[5], -1);
	TextDrawSetShadow(menu_teplica_general_st[5], 0);
	TextDrawSetOutline(menu_teplica_general_st[5], 0);
	TextDrawFont(menu_teplica_general_st[5], 4);
	TextDrawSetSelectable(menu_teplica_general_st[5], true);

	menu_teplica_general_st[6] = TextDrawCreate(320.999908, 49.777786, "brilliantother:teplica_buy_semena_3"); // Texture element
	TextDrawLetterSize(menu_teplica_general_st[6], 0.000000, 0.000000);
	TextDrawTextSize(menu_teplica_general_st[6], 81.999992, 102.044418);
	TextDrawAlignment(menu_teplica_general_st[6], 1);
	TextDrawColor(menu_teplica_general_st[6], -1);
	TextDrawSetShadow(menu_teplica_general_st[6], 0);
	TextDrawSetOutline(menu_teplica_general_st[6], 0);
	TextDrawFont(menu_teplica_general_st[6], 4);
	TextDrawSetSelectable(menu_teplica_general_st[6], true);

	menu_teplica_general_st[7] = TextDrawCreate(142.333404, 154.725952, "brilliantother:teplica_buy_semena_4"); // Texture element
	TextDrawLetterSize(menu_teplica_general_st[7], 0.000000, 0.000000);
	TextDrawTextSize(menu_teplica_general_st[7], 81.999992, 102.044418);
	TextDrawAlignment(menu_teplica_general_st[7], 1);
	TextDrawColor(menu_teplica_general_st[7], -1);
	TextDrawSetShadow(menu_teplica_general_st[7], 0);
	TextDrawSetOutline(menu_teplica_general_st[7], 0);
	TextDrawFont(menu_teplica_general_st[7], 4);
	TextDrawSetSelectable(menu_teplica_general_st[7], true);

	menu_teplica_general_st[8] = TextDrawCreate(231.666671, 153.481506, "brilliantother:teplica_buy_semena_5"); // Texture element
	TextDrawLetterSize(menu_teplica_general_st[8], 0.000000, 0.000000);
	TextDrawTextSize(menu_teplica_general_st[8], 81.999992, 102.044418);
	TextDrawAlignment(menu_teplica_general_st[8], 1);
	TextDrawColor(menu_teplica_general_st[8], -1);
	TextDrawSetShadow(menu_teplica_general_st[8], 0);
	TextDrawSetOutline(menu_teplica_general_st[8], 0);
	TextDrawFont(menu_teplica_general_st[8], 4);
	TextDrawSetSelectable(menu_teplica_general_st[8], true);

	menu_teplica_general_st[9] = TextDrawCreate(321.000091, 154.311157, "brilliantother:teplica_buy_semena_6"); // Texture element
	TextDrawLetterSize(menu_teplica_general_st[9], 0.000000, 0.000000);
	TextDrawTextSize(menu_teplica_general_st[9], 81.999992, 102.044418);
	TextDrawAlignment(menu_teplica_general_st[9], 1);
	TextDrawColor(menu_teplica_general_st[9], -1);
	TextDrawSetShadow(menu_teplica_general_st[9], 0);
	TextDrawSetOutline(menu_teplica_general_st[9], 0);
	TextDrawFont(menu_teplica_general_st[9], 4);
	TextDrawSetSelectable(menu_teplica_general_st[9], true);

	menu_teplica_general_st[10] = TextDrawCreate(140.666778, 259.259368, "brilliantother:teplica_buy_semena_7"); // Texture element
	TextDrawLetterSize(menu_teplica_general_st[10], 0.000000, 0.000000);
	TextDrawTextSize(menu_teplica_general_st[10], 81.999992, 102.044418);
	TextDrawAlignment(menu_teplica_general_st[10], 1);
	TextDrawColor(menu_teplica_general_st[10], -1);
	TextDrawSetShadow(menu_teplica_general_st[10], 0);
	TextDrawSetOutline(menu_teplica_general_st[10], 0);
	TextDrawFont(menu_teplica_general_st[10], 4);
	TextDrawSetSelectable(menu_teplica_general_st[10], true);

	menu_teplica_general_st[11] = TextDrawCreate(232.333435, 258.844573, "brilliantother:teplica_buy_semena_8"); // Texture element
	TextDrawLetterSize(menu_teplica_general_st[11], 0.000000, 0.000000);
	TextDrawTextSize(menu_teplica_general_st[11], 81.999992, 102.044418);
	TextDrawAlignment(menu_teplica_general_st[11], 1);
	TextDrawColor(menu_teplica_general_st[11], -1);
	TextDrawSetShadow(menu_teplica_general_st[11], 0);
	TextDrawSetOutline(menu_teplica_general_st[11], 0);
	TextDrawFont(menu_teplica_general_st[11], 4);
	TextDrawSetSelectable(menu_teplica_general_st[11], true);


	teplica_buy_menu[0] = TextDrawCreate(69.666732, 136.474044, "brilliantother:teplica_info_gui_4"); // Texture element
	TextDrawLetterSize(teplica_buy_menu[0], 0.000000, 0.000000);
	TextDrawTextSize(teplica_buy_menu[0], 157.666610, 202.844406);
	TextDrawAlignment(teplica_buy_menu[0], 1);
	TextDrawColor(teplica_buy_menu[0], -1);
	TextDrawSetShadow(teplica_buy_menu[0], 0);
	TextDrawSetOutline(teplica_buy_menu[0], 0);
	TextDrawFont(teplica_buy_menu[0], 4);

	teplica_buy_menu[1] = TextDrawCreate(238.666748, 137.718505, "brilliantother:teplica_info_gui_5"); // Texture element
	TextDrawLetterSize(teplica_buy_menu[1], 0.000000, 0.000000);
	TextDrawTextSize(teplica_buy_menu[1], 157.666610, 202.844406);
	TextDrawAlignment(teplica_buy_menu[1], 1);
	TextDrawColor(teplica_buy_menu[1], -1);
	TextDrawSetShadow(teplica_buy_menu[1], 0);
	TextDrawSetOutline(teplica_buy_menu[1], 0);
	TextDrawFont(teplica_buy_menu[1], 4);

	teplica_buy_menu[2] = TextDrawCreate(408.666778, 136.888885, "brilliantother:teplica_info_gui_6"); // Texture element
	TextDrawLetterSize(teplica_buy_menu[2], 0.000000, 0.000000);
	TextDrawTextSize(teplica_buy_menu[2], 157.666610, 202.844406);
	TextDrawAlignment(teplica_buy_menu[2], 1);
	TextDrawColor(teplica_buy_menu[2], -1);
	TextDrawSetShadow(teplica_buy_menu[2], 0);
	TextDrawSetOutline(teplica_buy_menu[2], 0);
	TextDrawFont(teplica_buy_menu[2], 4);

	teplica_buy_menu[3] = TextDrawCreate(95.999977, 293.688903, "brilliantother:teplica_button_buy"); // Texture element
	TextDrawLetterSize(teplica_buy_menu[3], 0.000000, 0.000000);
	TextDrawTextSize(teplica_buy_menu[3], 100.333312, 37.748176);
	TextDrawAlignment(teplica_buy_menu[3], 1);
	TextDrawColor(teplica_buy_menu[3], -1);
	TextDrawSetShadow(teplica_buy_menu[3], 0);
	TextDrawSetOutline(teplica_buy_menu[3], 0);
	TextDrawFont(teplica_buy_menu[3], 4);
	TextDrawSetSelectable(teplica_buy_menu[3], true);

	teplica_buy_menu[4] = TextDrawCreate(266.999908, 294.103698, "brilliantother:teplica_button_buy"); // Texture element
	TextDrawLetterSize(teplica_buy_menu[4], 0.000000, 0.000000);
	TextDrawTextSize(teplica_buy_menu[4], 100.333312, 37.748176);
	TextDrawAlignment(teplica_buy_menu[4], 1);
	TextDrawColor(teplica_buy_menu[4], -1);
	TextDrawSetShadow(teplica_buy_menu[4], 0);
	TextDrawSetOutline(teplica_buy_menu[4], 0);
	TextDrawFont(teplica_buy_menu[4], 4);
	TextDrawSetSelectable(teplica_buy_menu[4], true);

	teplica_buy_menu[5] = TextDrawCreate(435.666564, 293.688903, "brilliantother:teplica_button_buy"); // Texture element
	TextDrawLetterSize(teplica_buy_menu[5], 0.000000, 0.000000);
	TextDrawTextSize(teplica_buy_menu[5], 100.333312, 37.748176);
	TextDrawAlignment(teplica_buy_menu[5], 1);
	TextDrawColor(teplica_buy_menu[5], -1);
	TextDrawSetShadow(teplica_buy_menu[5], 0);
	TextDrawSetOutline(teplica_buy_menu[5], 0);
	TextDrawFont(teplica_buy_menu[5], 4);
	TextDrawSetSelectable(teplica_buy_menu[5], true);

	teplica_buy_menu[6] = TextDrawCreate(0.999997, 82.133346, "brilliantother:teplica_button_back"); // Texture element
	TextDrawLetterSize(teplica_buy_menu[6], 0.000000, 0.000000);
	TextDrawTextSize(teplica_buy_menu[6], 126.333351, 44.799999);
	TextDrawAlignment(teplica_buy_menu[6], 1);
	TextDrawColor(teplica_buy_menu[6], -1);
	TextDrawSetShadow(teplica_buy_menu[6], 0);
	TextDrawSetOutline(teplica_buy_menu[6], 0);
	TextDrawFont(teplica_buy_menu[6], 4);
	TextDrawSetSelectable(teplica_buy_menu[6], true);

	return true;
}


stock create_start_info()
{
	start_info_player_1[0] = TextDrawCreate(558.333374, 172.148162, "brilliantother:notify_general_panel_1"); // Texture element
	TextDrawLetterSize(start_info_player_1[0], 0.000000, 0.000000);
	TextDrawTextSize(start_info_player_1[0], 73.000000, 24.888895);
	TextDrawAlignment(start_info_player_1[0], 1);
	TextDrawColor(start_info_player_1[0], -1);
	TextDrawSetShadow(start_info_player_1[0], 0);
	TextDrawSetOutline(start_info_player_1[0], 0);
	TextDrawFont(start_info_player_1[0], 4);

	start_info_player_1[1] = TextDrawCreate(558.666687, 192.888946, "brilliantother:notify_general_panel_2"); // Texture element
	TextDrawLetterSize(start_info_player_1[1], 0.000000, 0.000000);
	TextDrawTextSize(start_info_player_1[1], 72.333320, 24.059263);
	TextDrawAlignment(start_info_player_1[1], 1);
	TextDrawColor(start_info_player_1[1], -1);
	TextDrawSetShadow(start_info_player_1[1], 0);
	TextDrawSetOutline(start_info_player_1[1], 0);
	TextDrawFont(start_info_player_1[1], 4);

	start_info_player_1[2] = TextDrawCreate(558.333435, 214.874130, "brilliantother:notify_general_panel_3"); // Texture element
	TextDrawLetterSize(start_info_player_1[2], 0.000000, 0.000000);
	TextDrawTextSize(start_info_player_1[2], 78.000022, 26.548152);
	TextDrawAlignment(start_info_player_1[2], 1);
	TextDrawColor(start_info_player_1[2], -1);
	TextDrawSetShadow(start_info_player_1[2], 0);
	TextDrawSetOutline(start_info_player_1[2], 0);
	TextDrawFont(start_info_player_1[2], 4);

	start_info_player_1[3] = TextDrawCreate(559.000061, 237.274185, "brilliantother:notify_general_panel_4"); // Texture element
	TextDrawLetterSize(start_info_player_1[3], 0.000000, 0.000000);
	TextDrawTextSize(start_info_player_1[3], 76.666641, 24.059265);
	TextDrawAlignment(start_info_player_1[3], 1);
	TextDrawColor(start_info_player_1[3], -1);
	TextDrawSetShadow(start_info_player_1[3], 0);
	TextDrawSetOutline(start_info_player_1[3], 0);
	TextDrawFont(start_info_player_1[3], 4);

	start_info_player_1[4] = TextDrawCreate(560.000000, 256.770507, "brilliantother:notify_general_panel_5"); // Texture element
	TextDrawLetterSize(start_info_player_1[4], 0.000000, 0.000000);
	TextDrawTextSize(start_info_player_1[4], 73.000000, 24.888895);
	TextDrawAlignment(start_info_player_1[4], 1);
	TextDrawColor(start_info_player_1[4], -1);
	TextDrawSetShadow(start_info_player_1[4], 0);
	TextDrawSetOutline(start_info_player_1[4], 0);
	TextDrawFont(start_info_player_1[4], 4);

	start_info_player_1[5] = TextDrawCreate(560.000061, 284.563201, "brilliantother:notify_general_panel_6"); // Texture element
	TextDrawLetterSize(start_info_player_1[5], 0.000000, 0.000000);
	TextDrawTextSize(start_info_player_1[5], 73.000000, 24.888895);
	TextDrawAlignment(start_info_player_1[5], 1);
	TextDrawColor(start_info_player_1[5], -1);
	TextDrawSetShadow(start_info_player_1[5], 0);
	TextDrawSetOutline(start_info_player_1[5], 0);
	TextDrawFont(start_info_player_1[5], 4);


	return true;
}

stock create_vehicle_key()
{
	player_veh_key_back[0] = TextDrawCreate(371.599975, 269.000000, "brckey:key_td_key");
	TextDrawTextSize(player_veh_key_back[0], 209.000000, 126.000000);
	TextDrawAlignment(player_veh_key_back[0], 1);
	TextDrawColor(player_veh_key_back[0], -1);
	TextDrawBackgroundColor(player_veh_key_back[0], 255);
	TextDrawFont(player_veh_key_back[0], 4);
	TextDrawSetProportional(player_veh_key_back[0], 0);

	player_veh_key_back[1] = TextDrawCreate(499.000000, 300.000000, "17:46");
	TextDrawLetterSize(player_veh_key_back[1], 0.488000, 1.890369);
	TextDrawTextSize(player_veh_key_back[1], 0.000000, 91.000000);
	TextDrawAlignment(player_veh_key_back[1], 2);
	TextDrawColor(player_veh_key_back[1], 606348543);
	TextDrawSetShadow(player_veh_key_back[1], 0);
	TextDrawBackgroundColor(player_veh_key_back[1], 255);
	TextDrawFont(player_veh_key_back[1], 1);
	TextDrawSetProportional(player_veh_key_back[1], 1);

	player_veh_key_back[2] = TextDrawCreate(545.000000, 262.000000, "brckey:white"); // ������. �� �������
	TextDrawTextSize(player_veh_key_back[2], 25.000000, 29.000000);
	TextDrawAlignment(player_veh_key_back[2], 1);
	TextDrawColor(player_veh_key_back[2], -1);
	TextDrawBackgroundColor(player_veh_key_back[2], 255);
	TextDrawFont(player_veh_key_back[2], 4);
	TextDrawSetProportional(player_veh_key_back[2], 0);
	TextDrawSetSelectable(player_veh_key_back[2], true);

	return true;
}

stock create_vehicke_key_electro()
{
	key_vehicle_electrog[0] = TextDrawCreate(477.000000, 196.000000, "brckey:key_td_e_key");
	TextDrawTextSize(key_vehicle_electrog[0], 91.000000, 206.710144);
	TextDrawAlignment(key_vehicle_electrog[0], 1);
	TextDrawColor(key_vehicle_electrog[0], -1);
	TextDrawBackgroundColor(key_vehicle_electrog[0], 255);
	TextDrawFont(key_vehicle_electrog[0], 4);
	TextDrawSetProportional(key_vehicle_electrog[0], 0);

	key_vehicle_electrog[1] = TextDrawCreate(497.000000, 211.000000, "brckey:white"); // ������. �� �����
	TextDrawTextSize(key_vehicle_electrog[1], 51.000000, 23.000000);
	TextDrawAlignment(key_vehicle_electrog[1], 1);
	TextDrawColor(key_vehicle_electrog[1], -1);
	TextDrawBackgroundColor(key_vehicle_electrog[1], 255);
	TextDrawFont(key_vehicle_electrog[1], 4);
	TextDrawSetProportional(key_vehicle_electrog[1], 0);
	TextDrawSetSelectable(key_vehicle_electrog[1], true);

	key_vehicle_electrog[2] = TextDrawCreate(497.000000, 236.000000, "brckey:white"); // ������. �� ��������
	TextDrawTextSize(key_vehicle_electrog[2], 51.000000, 23.000000);
	TextDrawAlignment(key_vehicle_electrog[2], 1);
	TextDrawColor(key_vehicle_electrog[2], -1);
	TextDrawBackgroundColor(key_vehicle_electrog[2], 255);
	TextDrawFont(key_vehicle_electrog[2], 4);
	TextDrawSetProportional(key_vehicle_electrog[2], 0);
	TextDrawSetSelectable(key_vehicle_electrog[2], true);

	key_vehicle_electrog[3] = TextDrawCreate(497.000000, 261.000000, "brckey:white"); // ������. �� �����
	TextDrawTextSize(key_vehicle_electrog[3], 51.000000, 23.000000);
	TextDrawAlignment(key_vehicle_electrog[3], 1);
	TextDrawColor(key_vehicle_electrog[3], -1);
	TextDrawBackgroundColor(key_vehicle_electrog[3], 255);
	TextDrawFont(key_vehicle_electrog[3], 4);
	TextDrawSetProportional(key_vehicle_electrog[3], 0);
	TextDrawSetSelectable(key_vehicle_electrog[3], true);

	key_vehicle_electrog[4] = TextDrawCreate(497.000000, 286.000000, "brckey:white"); // ������. �� ����
	TextDrawTextSize(key_vehicle_electrog[4], 51.000000, 23.000000);
	TextDrawAlignment(key_vehicle_electrog[4], 1);
	TextDrawColor(key_vehicle_electrog[4], -1);
	TextDrawBackgroundColor(key_vehicle_electrog[4], 255);
	TextDrawFont(key_vehicle_electrog[4], 4);
	TextDrawSetProportional(key_vehicle_electrog[4], 0);
	TextDrawSetSelectable(key_vehicle_electrog[4], true);

	key_vehicle_electrog[5] = TextDrawCreate(497.000000, 311.000000, "brckey:white"); // ������. �� ���������
	TextDrawTextSize(key_vehicle_electrog[5], 51.000000, 23.000000);
	TextDrawAlignment(key_vehicle_electrog[5], 1);
	TextDrawColor(key_vehicle_electrog[5], -1);
	TextDrawBackgroundColor(key_vehicle_electrog[5], 255);
	TextDrawFont(key_vehicle_electrog[5], 4);
	TextDrawSetProportional(key_vehicle_electrog[5], 0);
	TextDrawSetSelectable(key_vehicle_electrog[5], true);

	key_vehicle_electrog[6] = TextDrawCreate(510.000000, 344.000000, "brckey:white"); // ������. �� ���.
	TextDrawTextSize(key_vehicle_electrog[6], 25.000000, 44.000000);
	TextDrawAlignment(key_vehicle_electrog[6], 1);
	TextDrawColor(key_vehicle_electrog[6], -1);
	TextDrawBackgroundColor(key_vehicle_electrog[6], 255);
	TextDrawFont(key_vehicle_electrog[6], 4);
	TextDrawSetProportional(key_vehicle_electrog[6], 0);
	TextDrawSetSelectable(key_vehicle_electrog[6], true);

	return true;
}

stock create_vehicle_key_electro_p(playerid)
{
	if(key_vehicle_electro[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		key_vehicle_electro[0][playerid] = CreatePlayerTextDraw(playerid, 506.000000, 201.000000, "brckey:key_td_e_unlock");
		PlayerTextDrawTextSize(playerid, key_vehicle_electro[0][playerid], 35.000000, 41.000000);
		PlayerTextDrawAlignment(playerid, key_vehicle_electro[0][playerid], 1);
		PlayerTextDrawColor(playerid, key_vehicle_electro[0][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, key_vehicle_electro[0][playerid], 255);
		PlayerTextDrawFont(playerid, key_vehicle_electro[0][playerid], 4);
		PlayerTextDrawSetProportional(playerid, key_vehicle_electro[0][playerid], 0);
	}
	if(key_vehicle_electro[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		key_vehicle_electro[1][playerid] = CreatePlayerTextDraw(playerid, 506.000000, 226.000000, "brckey:key_td_e_trunkoff");
		PlayerTextDrawTextSize(playerid, key_vehicle_electro[1][playerid], 35.000000, 41.000000);
		PlayerTextDrawAlignment(playerid, key_vehicle_electro[1][playerid], 1);
		PlayerTextDrawColor(playerid, key_vehicle_electro[1][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, key_vehicle_electro[1][playerid], 255);
		PlayerTextDrawFont(playerid, key_vehicle_electro[1][playerid], 4);
		PlayerTextDrawSetProportional(playerid, key_vehicle_electro[1][playerid], 0);
	}
	if(key_vehicle_electro[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		key_vehicle_electro[2][playerid] = CreatePlayerTextDraw(playerid, 506.000000, 250.000000, "brckey:key_td_e_hoodoff");
		PlayerTextDrawTextSize(playerid, key_vehicle_electro[2][playerid], 35.000000, 41.000000);
		PlayerTextDrawAlignment(playerid, key_vehicle_electro[2][playerid], 1);
		PlayerTextDrawColor(playerid, key_vehicle_electro[2][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, key_vehicle_electro[2][playerid], 255);
		PlayerTextDrawFont(playerid, key_vehicle_electro[2][playerid], 4);
		PlayerTextDrawSetProportional(playerid, key_vehicle_electro[2][playerid], 0);
	}
	if(key_vehicle_electro[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		key_vehicle_electro[3][playerid] = CreatePlayerTextDraw(playerid, 506.000000, 275.000000, "brckey:key_td_e_lightoff");
		PlayerTextDrawTextSize(playerid, key_vehicle_electro[3][playerid], 35.000000, 41.000000);
		PlayerTextDrawAlignment(playerid, key_vehicle_electro[3][playerid], 1);
		PlayerTextDrawColor(playerid, key_vehicle_electro[3][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, key_vehicle_electro[3][playerid], 255);
		PlayerTextDrawFont(playerid, key_vehicle_electro[3][playerid], 4);
		PlayerTextDrawSetProportional(playerid, key_vehicle_electro[3][playerid], 0);
	}
	if(key_vehicle_electro[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		key_vehicle_electro[4][playerid] = CreatePlayerTextDraw(playerid, 506.000000, 300.000000, "brckey:key_td_e_engineon");
		PlayerTextDrawTextSize(playerid, key_vehicle_electro[4][playerid], 35.000000, 41.000000);
		PlayerTextDrawAlignment(playerid, key_vehicle_electro[4][playerid], 1);
		PlayerTextDrawColor(playerid, key_vehicle_electro[4][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, key_vehicle_electro[4][playerid], 255);
		PlayerTextDrawFont(playerid, key_vehicle_electro[4][playerid], 4);
		PlayerTextDrawSetProportional(playerid, key_vehicle_electro[4][playerid], 0);
	}
	return true;
}

stock create_vehicle_key_player(playerid)
{
	if(player_veh_key[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		player_veh_key[0][playerid] = CreatePlayerTextDraw(playerid, 453.000000, 344.000000, "brckey:key_td_unlock");
		PlayerTextDrawTextSize(playerid, player_veh_key[0][playerid], 16.000000, 19.000000);
		PlayerTextDrawAlignment(playerid, player_veh_key[0][playerid], 1);
		PlayerTextDrawColor(playerid, player_veh_key[0][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, player_veh_key[0][playerid], 255);
		PlayerTextDrawFont(playerid, player_veh_key[0][playerid], 4);
		PlayerTextDrawSetProportional(playerid, player_veh_key[0][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, player_veh_key[0][playerid], true);
	}
	if(player_veh_key[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		player_veh_key[1][playerid] = CreatePlayerTextDraw(playerid, 472.000000, 344.000000, "brckey:key_td_trunkoff");
		PlayerTextDrawTextSize(playerid, player_veh_key[1][playerid], 16.000000, 19.000000);
		PlayerTextDrawAlignment(playerid, player_veh_key[1][playerid], 1);
		PlayerTextDrawColor(playerid, player_veh_key[1][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, player_veh_key[1][playerid], 255);
		PlayerTextDrawFont(playerid, player_veh_key[1][playerid], 4);
		PlayerTextDrawSetProportional(playerid, player_veh_key[1][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, player_veh_key[1][playerid], true);
	}
	if(player_veh_key[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		player_veh_key[2][playerid] = CreatePlayerTextDraw(playerid, 491.000000, 344.000000, "brckey:key_td_hoodoff");
		PlayerTextDrawTextSize(playerid, player_veh_key[2][playerid], 16.000000, 19.000000);
		PlayerTextDrawAlignment(playerid, player_veh_key[2][playerid], 1);
		PlayerTextDrawColor(playerid, player_veh_key[2][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, player_veh_key[2][playerid], 255);
		PlayerTextDrawFont(playerid, player_veh_key[2][playerid], 4);
		PlayerTextDrawSetProportional(playerid, player_veh_key[2][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, player_veh_key[2][playerid], true);
	}
	if(player_veh_key[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		player_veh_key[3][playerid] = CreatePlayerTextDraw(playerid, 510.000000, 344.000000, "brckey:key_td_lightoff");
		PlayerTextDrawTextSize(playerid, player_veh_key[3][playerid], 16.000000, 19.000000);
		PlayerTextDrawAlignment(playerid, player_veh_key[3][playerid], 1);
		PlayerTextDrawColor(playerid, player_veh_key[3][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, player_veh_key[3][playerid], 255);
		PlayerTextDrawFont(playerid, player_veh_key[3][playerid], 4);
		PlayerTextDrawSetProportional(playerid, player_veh_key[3][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, player_veh_key[3][playerid], true);
	}
	if(player_veh_key[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		player_veh_key[4][playerid] = CreatePlayerTextDraw(playerid, 529.000000, 344.000000, "brckey:key_td_engineon");
		PlayerTextDrawTextSize(playerid, player_veh_key[4][playerid], 16.000000, 19.000000);
		PlayerTextDrawAlignment(playerid, player_veh_key[4][playerid], 1);
		PlayerTextDrawColor(playerid, player_veh_key[4][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, player_veh_key[4][playerid], 255);
		PlayerTextDrawFont(playerid, player_veh_key[4][playerid], 4);
		PlayerTextDrawSetProportional(playerid, player_veh_key[4][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, player_veh_key[4][playerid], true);
	}
	return true;
}

stock create_fast_menu()
{



	fast_menu_general_1[0] = TextDrawCreate(172.000000, 177.955551, "brilliantother:fast_menu_button_1"); // Texture element
	TextDrawLetterSize(fast_menu_general_1[0], 0.000000, 0.000000);
	TextDrawTextSize(fast_menu_general_1[0], 119.000000, 38.162963);
	TextDrawAlignment(fast_menu_general_1[0], 2);
	TextDrawColor(fast_menu_general_1[0], -1);
	TextDrawSetShadow(fast_menu_general_1[0], 0);
	TextDrawSetOutline(fast_menu_general_1[0], 0);
	TextDrawFont(fast_menu_general_1[0], 4);
	TextDrawSetSelectable(fast_menu_general_1[0], true);

	fast_menu_general_1[1] = TextDrawCreate(157.666641, 221.925933, "brilliantother:fast_menu_button_2"); // Texture element
	TextDrawLetterSize(fast_menu_general_1[1], 0.000000, 0.000000);
	TextDrawTextSize(fast_menu_general_1[1], 119.000000, 38.162963);
	TextDrawAlignment(fast_menu_general_1[1], 2);
	TextDrawColor(fast_menu_general_1[1], -1);
	TextDrawSetShadow(fast_menu_general_1[1], 0);
	TextDrawSetOutline(fast_menu_general_1[1], 0);
	TextDrawFont(fast_menu_general_1[1], 4);
	TextDrawSetSelectable(fast_menu_general_1[1], true);

	fast_menu_general_1[2] = TextDrawCreate(171.333206, 269.629669, "brilliantother:fast_menu_button_3"); // Texture element
	TextDrawLetterSize(fast_menu_general_1[2], 0.000000, 0.000000);
	TextDrawTextSize(fast_menu_general_1[2], 119.000000, 38.162963);
	TextDrawAlignment(fast_menu_general_1[2], 2);
	TextDrawColor(fast_menu_general_1[2], -1);
	TextDrawSetShadow(fast_menu_general_1[2], 0);
	TextDrawSetOutline(fast_menu_general_1[2], 0);
	TextDrawFont(fast_menu_general_1[2], 4);
	TextDrawSetSelectable(fast_menu_general_1[2], true);

	fast_menu_general_1[3] = TextDrawCreate(361.333190, 176.711135, "brilliantother:fast_menu_button_4"); // Texture element
	TextDrawLetterSize(fast_menu_general_1[3], 0.000000, 0.000000);
	TextDrawTextSize(fast_menu_general_1[3], 119.000000, 38.162963);
	TextDrawAlignment(fast_menu_general_1[3], 2);
	TextDrawColor(fast_menu_general_1[3], -1);
	TextDrawSetShadow(fast_menu_general_1[3], 0);
	TextDrawSetOutline(fast_menu_general_1[3], 0);
	TextDrawFont(fast_menu_general_1[3], 4);
	TextDrawSetSelectable(fast_menu_general_1[3], true);

	fast_menu_general_1[4] = TextDrawCreate(374.999877, 219.022232, "brilliantother:fast_menu_button_5"); // Texture element
	TextDrawLetterSize(fast_menu_general_1[4], 0.000000, 0.000000);
	TextDrawTextSize(fast_menu_general_1[4], 119.000000, 38.162963);
	TextDrawAlignment(fast_menu_general_1[4], 2);
	TextDrawColor(fast_menu_general_1[4], -1);
	TextDrawSetShadow(fast_menu_general_1[4], 0);
	TextDrawSetOutline(fast_menu_general_1[4], 0);
	TextDrawFont(fast_menu_general_1[4], 4);
	TextDrawSetSelectable(fast_menu_general_1[4], true);

	fast_menu_general_1[5] = TextDrawCreate(361.666564, 266.311157, "brilliantother:fast_menu_button_6"); // Texture element
	TextDrawLetterSize(fast_menu_general_1[5], 0.000000, 0.000000);
	TextDrawTextSize(fast_menu_general_1[5], 119.000000, 38.162963);
	TextDrawAlignment(fast_menu_general_1[5], 2);
	TextDrawColor(fast_menu_general_1[5], -1);
	TextDrawSetShadow(fast_menu_general_1[5], 0);
	TextDrawSetOutline(fast_menu_general_1[5], 0);
	TextDrawFont(fast_menu_general_1[5], 4);
	TextDrawSetSelectable(fast_menu_general_1[5], true);

	fast_menu_general_1[6] = TextDrawCreate(294.000000, 206.992584, "brilliantother:close_button_big"); // Texture element
	TextDrawLetterSize(fast_menu_general_1[6], 0.000000, 0.000000);
	TextDrawTextSize(fast_menu_general_1[6], 61.333370, 73.837043);
	TextDrawAlignment(fast_menu_general_1[6], 2);
	TextDrawColor(fast_menu_general_1[6], -1);
	TextDrawUseBox(fast_menu_general_1[6], true);
	TextDrawBoxColor(fast_menu_general_1[6], 0);
	TextDrawSetShadow(fast_menu_general_1[6], 0);
	TextDrawSetOutline(fast_menu_general_1[6], 0);
	TextDrawFont(fast_menu_general_1[6], 4);
	TextDrawSetSelectable(fast_menu_general_1[6], true);


	fast_menu_general_2[0] = TextDrawCreate(154.333358, 154.311065, "brilliantother:fast_menu_button_7"); // Texture element
	TextDrawLetterSize(fast_menu_general_2[0], 0.000000, 0.000000);
	TextDrawTextSize(fast_menu_general_2[0], 152.999984, 47.288898);
	TextDrawAlignment(fast_menu_general_2[0], 2);
	TextDrawColor(fast_menu_general_2[0], -1);
	TextDrawSetShadow(fast_menu_general_2[0], 0);
	TextDrawSetOutline(fast_menu_general_2[0], 0);
	TextDrawFont(fast_menu_general_2[0], 4);
	TextDrawSetSelectable(fast_menu_general_2[0], true);

	fast_menu_general_2[1] = TextDrawCreate(121.000038, 202.014770, "brilliantother:fast_menu_button_8"); // Texture element
	TextDrawLetterSize(fast_menu_general_2[1], 0.000000, 0.000000);
	TextDrawTextSize(fast_menu_general_2[1], 154.333312, 48.118526);
	TextDrawAlignment(fast_menu_general_2[1], 2);
	TextDrawColor(fast_menu_general_2[1], -1);
	TextDrawSetShadow(fast_menu_general_2[1], 0);
	TextDrawSetOutline(fast_menu_general_2[1], 0);
	TextDrawFont(fast_menu_general_2[1], 4);
	TextDrawSetSelectable(fast_menu_general_2[1], true);

	fast_menu_general_2[2] = TextDrawCreate(153.333328, 246.814773, "brilliantother:fast_menu_button_9"); // Texture element
	TextDrawLetterSize(fast_menu_general_2[2], 0.000000, 0.000000);
	TextDrawTextSize(fast_menu_general_2[2], 152.999984, 47.288898);
	TextDrawAlignment(fast_menu_general_2[2], 2);
	TextDrawColor(fast_menu_general_2[2], -1);
	TextDrawSetShadow(fast_menu_general_2[2], 0);
	TextDrawSetOutline(fast_menu_general_2[2], 0);
	TextDrawFont(fast_menu_general_2[2], 4);
	TextDrawSetSelectable(fast_menu_general_2[2], true);

	fast_menu_general_2[3] = TextDrawCreate(344.666625, 152.651855, "brilliantother:fast_menu_button_10"); // Texture element
	TextDrawLetterSize(fast_menu_general_2[3], 0.000000, 0.000000);
	TextDrawTextSize(fast_menu_general_2[3], 152.999984, 47.288898);
	TextDrawAlignment(fast_menu_general_2[3], 2);
	TextDrawColor(fast_menu_general_2[3], -1);
	TextDrawSetShadow(fast_menu_general_2[3], 0);
	TextDrawSetOutline(fast_menu_general_2[3], 0);
	TextDrawFont(fast_menu_general_2[3], 4);
	TextDrawSetSelectable(fast_menu_general_2[3], true);

	fast_menu_general_2[4] = TextDrawCreate(373.333526, 200.355484, "brilliantother:fast_menu_button_11"); // Texture element
	TextDrawLetterSize(fast_menu_general_2[4], 0.000000, 0.000000);
	TextDrawTextSize(fast_menu_general_2[4], 152.999984, 47.288898);
	TextDrawAlignment(fast_menu_general_2[4], 2);
	TextDrawColor(fast_menu_general_2[4], -1);
	TextDrawSetShadow(fast_menu_general_2[4], 0);
	TextDrawSetOutline(fast_menu_general_2[4], 0);
	TextDrawFont(fast_menu_general_2[4], 4);
	TextDrawSetSelectable(fast_menu_general_2[4], true);

	fast_menu_general_2[5] = TextDrawCreate(346.000274, 246.814758, "brilliantother:fast_menu_button_12"); // Texture element
	TextDrawLetterSize(fast_menu_general_2[5], 0.000000, 0.000000);
	TextDrawTextSize(fast_menu_general_2[5], 152.999984, 47.288898);
	TextDrawAlignment(fast_menu_general_2[5], 2);
	TextDrawColor(fast_menu_general_2[5], -1);
	TextDrawSetShadow(fast_menu_general_2[5], 0);
	TextDrawSetOutline(fast_menu_general_2[5], 0);
	TextDrawFont(fast_menu_general_2[5], 4);
	TextDrawSetSelectable(fast_menu_general_2[5], true);

	fast_menu_general_2[6] = TextDrawCreate(287.666625, 181.274093, "brilliantother:close_button_big"); // Texture element
	TextDrawLetterSize(fast_menu_general_2[6], 0.000000, 0.000000);
	TextDrawTextSize(fast_menu_general_2[6], 78.000030, 90.014770);
	TextDrawAlignment(fast_menu_general_2[6], 2);
	TextDrawColor(fast_menu_general_2[6], -1);
	TextDrawSetShadow(fast_menu_general_2[6], 0);
	TextDrawSetOutline(fast_menu_general_2[6], 0);
	TextDrawFont(fast_menu_general_2[6], 4);
	TextDrawSetSelectable(fast_menu_general_2[6], true);


	return true;
}

stock create_mafia_timer()// �������� ����������
{
	tdBizWar[0] = TextDrawCreate(200.333389, 343.881652, "brilliantother:opg_ui_timer"); // Texture element
	TextDrawLetterSize(tdBizWar[0], 0.000000, 0.000000);
	TextDrawTextSize(tdBizWar[0], 254.333190, 52.266632);
	TextDrawAlignment(tdBizWar[0], 1);
	TextDrawColor(tdBizWar[0], -1);
	TextDrawSetShadow(tdBizWar[0], 0);
	TextDrawSetOutline(tdBizWar[0], 0);
	TextDrawFont(tdBizWar[0], 4);

	tdBizWar[1] = TextDrawCreate(253.000061, 367.940765, "5000"); // Text element
	TextDrawLetterSize(tdBizWar[1], 0.352666, 1.765926);
	TextDrawAlignment(tdBizWar[1], 2);
	TextDrawColor(tdBizWar[1], -1);
	TextDrawSetShadow(tdBizWar[1], 1);
	TextDrawSetOutline(tdBizWar[1], 0);
	TextDrawBackgroundColor(tdBizWar[1], 51);
	TextDrawFont(tdBizWar[1], 2);
	TextDrawSetProportional(tdBizWar[1], 1);

	tdBizWar[2] = TextDrawCreate(400.333526, 367.940734, "5500"); // Text element
	TextDrawLetterSize(tdBizWar[2], 0.352666, 1.765926);
	TextDrawAlignment(tdBizWar[2], 2);
	TextDrawColor(tdBizWar[2], -1);
	TextDrawSetShadow(tdBizWar[2], 1);
	TextDrawSetOutline(tdBizWar[2], 0);
	TextDrawBackgroundColor(tdBizWar[2], 51);
	TextDrawFont(tdBizWar[2], 2);
	TextDrawSetProportional(tdBizWar[2], 1);

	tdBizWar[3] = TextDrawCreate(327.666809, 367.111145, "10:50"); // Text element
	TextDrawLetterSize(tdBizWar[3], 0.352666, 1.765926);
	TextDrawAlignment(tdBizWar[3], 2);
	TextDrawColor(tdBizWar[3], -1);
	TextDrawSetShadow(tdBizWar[3], 1);
	TextDrawSetOutline(tdBizWar[3], 0);
	TextDrawBackgroundColor(tdBizWar[3], 51);
	TextDrawFont(tdBizWar[3], 2);
	TextDrawSetProportional(tdBizWar[3], 1);

	tdBizWar[4] = TextDrawCreate(258.333526, 352.177764, "TAMBOVSKAYA"); // Text element
	TextDrawLetterSize(tdBizWar[4], 0.287666, 1.508741);
	TextDrawAlignment(tdBizWar[4], 2);
	TextDrawColor(tdBizWar[4], -1);
	TextDrawSetShadow(tdBizWar[4], 1);
	TextDrawSetOutline(tdBizWar[4], 0);
	TextDrawBackgroundColor(tdBizWar[4], 51);
	TextDrawFont(tdBizWar[4], 2);
	TextDrawSetProportional(tdBizWar[4], 1);

	tdBizWar[5] = TextDrawCreate(394.333557, 352.592620, "IZMAILOVSKAYA"); // Text element
	TextDrawLetterSize(tdBizWar[5], 0.287666, 1.508741);
	TextDrawAlignment(tdBizWar[5], 2);
	TextDrawColor(tdBizWar[5], -1);
	TextDrawSetShadow(tdBizWar[5], 1);
	TextDrawSetOutline(tdBizWar[5], 0);
	TextDrawBackgroundColor(tdBizWar[5], 51);
	TextDrawFont(tdBizWar[5], 2);
	TextDrawSetProportional(tdBizWar[5], 1);

	return 1;
}

stock create_gui_other()
{


	general_gui_player[0] = TextDrawCreate(14.999985, 217.777694, "brilliantother:gui_green_zone"); // Texture element
	TextDrawLetterSize(general_gui_player[0], 0.000000, 0.000000);
	TextDrawTextSize(general_gui_player[0], 77.499984, 36.503704);
	TextDrawAlignment(general_gui_player[0], 2);
	TextDrawColor(general_gui_player[0], -1);
	TextDrawSetShadow(general_gui_player[0], 0);
	TextDrawSetOutline(general_gui_player[0], 0);
	TextDrawFont(general_gui_player[0], 4);

	general_gui_player[1] = TextDrawCreate(15.999982, 260.503601, "brilliantother:gui_gps_active"); // Texture element
	TextDrawLetterSize(general_gui_player[1], 0.000000, 0.000000);
	TextDrawTextSize(general_gui_player[1], 86.166732, 33.600006);
	TextDrawAlignment(general_gui_player[1], 2);
	TextDrawColor(general_gui_player[1], -1);
	TextDrawSetShadow(general_gui_player[1], 0);
	TextDrawSetOutline(general_gui_player[1], 0);
	TextDrawFont(general_gui_player[1], 4);



	return true;
}

stock prize_newyear_td()
{

	prizenewyear_background[0] = TextDrawCreate(-9.666666, -1.244444, "brilliantother:newyear_prize_background"); // Texture element
	TextDrawLetterSize(prizenewyear_background[0], 0.000000, 0.000000);
	TextDrawTextSize(prizenewyear_background[0], 653.333129, 450.488922);
	TextDrawAlignment(prizenewyear_background[0], 2);
	TextDrawColor(prizenewyear_background[0], -1);
	TextDrawSetShadow(prizenewyear_background[0], 0);
	TextDrawSetOutline(prizenewyear_background[0], 0);
	TextDrawFont(prizenewyear_background[0], 4);

	prizenewyear_background[1] = TextDrawCreate(220.333312, 297.836975, "brilliantother:newyear_button_prize_1"); // Texture element
	TextDrawLetterSize(prizenewyear_background[1], 0.000000, 0.000000);
	TextDrawTextSize(prizenewyear_background[1], 193.999923, 97.896316);
	TextDrawAlignment(prizenewyear_background[1], 2);
	TextDrawColor(prizenewyear_background[1], -1);
	TextDrawSetShadow(prizenewyear_background[1], 0);
	TextDrawSetOutline(prizenewyear_background[1], 0);
	TextDrawFont(prizenewyear_background[1], 4);
	TextDrawSetSelectable(prizenewyear_background[1], true);

	prizenewyear_background[2] = TextDrawCreate(526.666687, 8.711111, "brilliantother:police_plater_close"); // Texture element
	TextDrawLetterSize(prizenewyear_background[2], 0.000000, 0.000000);
	TextDrawTextSize(prizenewyear_background[2], 40.333312, 29.037034);
	TextDrawAlignment(prizenewyear_background[2], 2);
	TextDrawColor(prizenewyear_background[2], -1);
	TextDrawSetShadow(prizenewyear_background[2], 0);
	TextDrawSetOutline(prizenewyear_background[2], 0);
	TextDrawFont(prizenewyear_background[2], 4);
	TextDrawSetSelectable(prizenewyear_background[2], true);


	return true;
}

stock create_rent_katok()
{

	rent_katok_menu[0] = TextDrawCreate(199.333328, 116.562942, "brilliantother:newyear_rent_katok"); // Texture element
	TextDrawLetterSize(rent_katok_menu[0], 0.000000, 0.000000);
	TextDrawTextSize(rent_katok_menu[0], 253.999938, 245.985198);
	TextDrawAlignment(rent_katok_menu[0], 2);
	TextDrawColor(rent_katok_menu[0], -1);
	TextDrawSetShadow(rent_katok_menu[0], 0);
	TextDrawSetOutline(rent_katok_menu[0], 0);
	TextDrawFont(rent_katok_menu[0], 4);

	rent_katok_menu[1] = TextDrawCreate(266.999938, 287.466522, "brilliantother:newyear_button_rent"); // Texture element
	TextDrawLetterSize(rent_katok_menu[1], 0.000000, 0.000000);
	TextDrawTextSize(rent_katok_menu[1], 119.666679, 74.666709);
	TextDrawAlignment(rent_katok_menu[1], 2);
	TextDrawColor(rent_katok_menu[1], -1);
	TextDrawSetShadow(rent_katok_menu[1], 0);
	TextDrawSetOutline(rent_katok_menu[1], 0);
	TextDrawFont(rent_katok_menu[1], 4);
	TextDrawSetSelectable(rent_katok_menu[1], true);

	rent_katok_menu[2] = TextDrawCreate(429.000000, 185.422210, "brilliantother:inventory_close"); // Texture element
	TextDrawLetterSize(rent_katok_menu[2], 0.000000, 0.000000);
	TextDrawTextSize(rent_katok_menu[2], 18.000000, 21.155548);
	TextDrawAlignment(rent_katok_menu[2], 2);
	TextDrawColor(rent_katok_menu[2], -1);
	TextDrawSetShadow(rent_katok_menu[2], 0);
	TextDrawSetOutline(rent_katok_menu[2], 0);
	TextDrawFont(rent_katok_menu[2], 4);
	TextDrawSetSelectable(rent_katok_menu[2], true);

	rent_katok_menu[3] = TextDrawCreate(287.333374, 314.014801, "brilliantother:newyear_button_unrent"); // Texture element
	TextDrawLetterSize(rent_katok_menu[3], 0.000000, 0.000000);
	TextDrawTextSize(rent_katok_menu[3], 78.333335, 27.377803);
	TextDrawAlignment(rent_katok_menu[3], 2);
	TextDrawColor(rent_katok_menu[3], -1);
	TextDrawSetShadow(rent_katok_menu[3], 0);
	TextDrawSetOutline(rent_katok_menu[3], 0);
	TextDrawFont(rent_katok_menu[3], 4);
	TextDrawSetSelectable(rent_katok_menu[3], true);


	return true;
}

stock create_race_td()
{

	race_interface_g_snow[0] = TextDrawCreate(139.333328, 133.155563, "brilliantother:race_background_2"); // Texture element
	TextDrawLetterSize(race_interface_g_snow[0], 0.000000, 0.000000);
	TextDrawTextSize(race_interface_g_snow[0], 342.000000, 240.592605);
	TextDrawAlignment(race_interface_g_snow[0], 1);
	TextDrawColor(race_interface_g_snow[0], -1);
	TextDrawSetShadow(race_interface_g_snow[0], 0);
	TextDrawSetOutline(race_interface_g_snow[0], 0);
	TextDrawFont(race_interface_g_snow[0], 4);

	race_interface_g_snow[1] = TextDrawCreate(163.000061, 193.303695, "brilliantother:race_gui_1"); // Texture element
	TextDrawLetterSize(race_interface_g_snow[1], 0.000000, 0.000000);
	TextDrawTextSize(race_interface_g_snow[1], 132.666732, 115.733306);
	TextDrawAlignment(race_interface_g_snow[1], 2);
	TextDrawColor(race_interface_g_snow[1], -1);
	TextDrawSetShadow(race_interface_g_snow[1], 0);
	TextDrawSetOutline(race_interface_g_snow[1], 0);
	TextDrawFont(race_interface_g_snow[1], 4);

	race_interface_g_snow[2] = TextDrawCreate(163.000061, 193.303695, "brilliantother:race_gui_1"); // Texture element
	TextDrawLetterSize(race_interface_g_snow[2], 0.000000, 0.000000);
	TextDrawTextSize(race_interface_g_snow[2], 132.666732, 115.733306);
	TextDrawAlignment(race_interface_g_snow[2], 2);
	TextDrawColor(race_interface_g_snow[2], -1);
	TextDrawSetShadow(race_interface_g_snow[2], 0);
	TextDrawSetOutline(race_interface_g_snow[2], 0);
	TextDrawFont(race_interface_g_snow[2], 4);

	race_interface_g_snow[3] = TextDrawCreate(208.000015, 219.851867, "10M"); // Text element
	TextDrawLetterSize(race_interface_g_snow[3], 0.257333, 1.479702);
	TextDrawAlignment(race_interface_g_snow[3], 2);
	TextDrawColor(race_interface_g_snow[3], -1);
	TextDrawSetShadow(race_interface_g_snow[3], 0);
	TextDrawSetOutline(race_interface_g_snow[3], 0); 
	TextDrawBackgroundColor(race_interface_g_snow[3], 51);
	TextDrawFont(race_interface_g_snow[3], 2);
	TextDrawSetProportional(race_interface_g_snow[3], 1);

	race_interface_g_snow[4] = TextDrawCreate(244.666671, 275.851898, "500000_RUB"); // Text element
	TextDrawLetterSize(race_interface_g_snow[4], 0.285665, 1.857185);
	TextDrawAlignment(race_interface_g_snow[4], 2);
	TextDrawColor(race_interface_g_snow[4], -1);
	TextDrawSetShadow(race_interface_g_snow[4], 0);
	TextDrawSetOutline(race_interface_g_snow[4], 0);
	TextDrawBackgroundColor(race_interface_g_snow[4], 51);
	TextDrawFont(race_interface_g_snow[4], 2);
	TextDrawSetProportional(race_interface_g_snow[4], 1);


	race_interface_g_snow[5] = TextDrawCreate(461.666748, 136.474075, "brilliantother:inventory_close"); // Texture element
	TextDrawLetterSize(race_interface_g_snow[5], 0.000000, 0.000000);
	TextDrawTextSize(race_interface_g_snow[5], 13.333329, 15.348150);
	TextDrawAlignment(race_interface_g_snow[5], 2);
	TextDrawColor(race_interface_g_snow[5], -1);
	TextDrawSetShadow(race_interface_g_snow[5], 0);
	TextDrawSetOutline(race_interface_g_snow[5], 0);
	TextDrawFont(race_interface_g_snow[5], 4);
	TextDrawSetSelectable(race_interface_g_snow[5], true);

	race_timer_snow[0] = TextDrawCreate(254.333343, 303.229797, "brilliantother:info_gui_snow_race_6"); // Texture element
	TextDrawLetterSize(race_timer_snow[0], 0.000000, 0.000000);
	TextDrawTextSize(race_timer_snow[0], 126.666671, 41.481498);
	TextDrawAlignment(race_timer_snow[0], 1);
	TextDrawColor(race_timer_snow[0], -1);
	TextDrawSetShadow(race_timer_snow[0], 0);
	TextDrawSetOutline(race_timer_snow[0], 0);
	TextDrawFont(race_timer_snow[0], 4);

	race_timer_snow[1] = TextDrawCreate(319.333496, 321.896331, "56"); // Text element
	TextDrawLetterSize(race_timer_snow[1], 0.418666, 2.189037);
	TextDrawAlignment(race_timer_snow[1], 2);
	TextDrawColor(race_timer_snow[1], -1);
	TextDrawUseBox(race_timer_snow[1], true);
	TextDrawBoxColor(race_timer_snow[1], 0);
	TextDrawSetShadow(race_timer_snow[1], 0);
	TextDrawSetOutline(race_timer_snow[1], 1);
	TextDrawBackgroundColor(race_timer_snow[1], 51);
	TextDrawFont(race_timer_snow[1], 2);
	TextDrawSetProportional(race_timer_snow[1], 1);	

	race_interface_g[0] = TextDrawCreate(139.333328, 133.155563, "brilliantother:race_background"); // Texture element
	TextDrawLetterSize(race_interface_g[0], 0.000000, 0.000000);
	TextDrawTextSize(race_interface_g[0], 342.000000, 240.592605);
	TextDrawAlignment(race_interface_g[0], 1);
	TextDrawColor(race_interface_g[0], -1);
	TextDrawSetShadow(race_interface_g[0], 0);
	TextDrawSetOutline(race_interface_g[0], 0);
	TextDrawFont(race_interface_g[0], 4);

	race_interface_g[1] = TextDrawCreate(163.000061, 193.303695, "brilliantother:race_gui_1"); // Texture element
	TextDrawLetterSize(race_interface_g[1], 0.000000, 0.000000);
	TextDrawTextSize(race_interface_g[1], 132.666732, 115.733306);
	TextDrawAlignment(race_interface_g[1], 2);
	TextDrawColor(race_interface_g[1], -1);
	TextDrawSetShadow(race_interface_g[1], 0);
	TextDrawSetOutline(race_interface_g[1], 0);
	TextDrawFont(race_interface_g[1], 4);

	race_interface_g[2] = TextDrawCreate(163.000061, 193.303695, "brilliantother:race_gui_1"); // Texture element
	TextDrawLetterSize(race_interface_g[2], 0.000000, 0.000000);
	TextDrawTextSize(race_interface_g[2], 132.666732, 115.733306);
	TextDrawAlignment(race_interface_g[2], 2);
	TextDrawColor(race_interface_g[2], -1);
	TextDrawSetShadow(race_interface_g[2], 0);
	TextDrawSetOutline(race_interface_g[2], 0);
	TextDrawFont(race_interface_g[2], 4);

	race_interface_g[3] = TextDrawCreate(208.000015, 219.851867, "10M"); // Text element
	TextDrawLetterSize(race_interface_g[3], 0.257333, 1.479702);
	TextDrawAlignment(race_interface_g[3], 2);
	TextDrawColor(race_interface_g[3], -1);
	TextDrawSetShadow(race_interface_g[3], 0);
	TextDrawSetOutline(race_interface_g[3], 0); 
	TextDrawBackgroundColor(race_interface_g[3], 51);
	TextDrawFont(race_interface_g[3], 2);
	TextDrawSetProportional(race_interface_g[3], 1);

	race_interface_g[4] = TextDrawCreate(244.666671, 275.851898, "500000_RUB"); // Text element
	TextDrawLetterSize(race_interface_g[4], 0.285665, 1.857185);
	TextDrawAlignment(race_interface_g[4], 2);
	TextDrawColor(race_interface_g[4], -1);
	TextDrawSetShadow(race_interface_g[4], 0);
	TextDrawSetOutline(race_interface_g[4], 0);
	TextDrawBackgroundColor(race_interface_g[4], 51);
	TextDrawFont(race_interface_g[4], 2);
	TextDrawSetProportional(race_interface_g[4], 1);


	race_interface_g[5] = TextDrawCreate(461.666748, 136.474075, "brilliantother:inventory_close"); // Texture element
	TextDrawLetterSize(race_interface_g[5], 0.000000, 0.000000);
	TextDrawTextSize(race_interface_g[5], 13.333329, 15.348150);
	TextDrawAlignment(race_interface_g[5], 2);
	TextDrawColor(race_interface_g[5], -1);
	TextDrawSetShadow(race_interface_g[5], 0);
	TextDrawSetOutline(race_interface_g[5], 0);
	TextDrawFont(race_interface_g[5], 4);
	TextDrawSetSelectable(race_interface_g[5], true);

	race_timer_global[0] = TextDrawCreate(254.333343, 303.229797, "brilliantother:info_gui_race_6"); // Texture element
	TextDrawLetterSize(race_timer_global[0], 0.000000, 0.000000);
	TextDrawTextSize(race_timer_global[0], 126.666671, 41.481498);
	TextDrawAlignment(race_timer_global[0], 1);
	TextDrawColor(race_timer_global[0], -1);
	TextDrawSetShadow(race_timer_global[0], 0);
	TextDrawSetOutline(race_timer_global[0], 0);
	TextDrawFont(race_timer_global[0], 4);

	race_timer_global[1] = TextDrawCreate(319.333496, 321.896331, "56"); // Text element
	TextDrawLetterSize(race_timer_global[1], 0.418666, 2.189037);
	TextDrawAlignment(race_timer_global[1], 2);
	TextDrawColor(race_timer_global[1], -1);
	TextDrawUseBox(race_timer_global[1], true);
	TextDrawBoxColor(race_timer_global[1], 0);
	TextDrawSetShadow(race_timer_global[1], 0);
	TextDrawSetOutline(race_timer_global[1], 1);
	TextDrawBackgroundColor(race_timer_global[1], 51);
	TextDrawFont(race_timer_global[1], 2);
	TextDrawSetProportional(race_timer_global[1], 1);	


	race_position_td[0] = TextDrawCreate(2.000000, 159.703704, "brilliantother:race_background_score"); // Texture element
	TextDrawLetterSize(race_position_td[0], 0.000000, 0.000000);
	TextDrawTextSize(race_position_td[0], 97.666709, 149.333221);
	TextDrawAlignment(race_position_td[0], 1);
	TextDrawColor(race_position_td[0], -1);
	TextDrawSetShadow(race_position_td[0], 0);
	TextDrawSetOutline(race_position_td[0], 0);
	TextDrawFont(race_position_td[0], 4);

	race_position_td[1] = TextDrawCreate(55.999973, 207.407470, "------------------"); // Text element
	TextDrawLetterSize(race_position_td[1], 0.187665, 1.156147);
	TextDrawAlignment(race_position_td[1], 2);
	TextDrawColor(race_position_td[1], -1);
	TextDrawSetShadow(race_position_td[1], 0);
	TextDrawSetOutline(race_position_td[1], 0);
	TextDrawBackgroundColor(race_position_td[1], 51);
	TextDrawFont(race_position_td[1], 2);
	TextDrawSetProportional(race_position_td[1], 1);

	race_position_td[2] = TextDrawCreate(56.333305, 228.148239, "------------------"); // Text element
	TextDrawLetterSize(race_position_td[2], 0.187665, 1.156147);
	TextDrawAlignment(race_position_td[2], 2);
	TextDrawColor(race_position_td[2], -1);
	TextDrawSetShadow(race_position_td[2], 0);
	TextDrawSetOutline(race_position_td[2], 0);
	TextDrawBackgroundColor(race_position_td[2], 51);
	TextDrawFont(race_position_td[2], 2);
	TextDrawSetProportional(race_position_td[2], 1);

	race_position_td[3] = TextDrawCreate(55.999969, 249.303817, "------------------"); // Text element
	TextDrawLetterSize(race_position_td[3], 0.187665, 1.156147);
	TextDrawAlignment(race_position_td[3], 2);
	TextDrawColor(race_position_td[3], -1);
	TextDrawSetShadow(race_position_td[3], 0);
	TextDrawSetOutline(race_position_td[3], 0);
	TextDrawBackgroundColor(race_position_td[3], 51);
	TextDrawFont(race_position_td[3], 2);
	TextDrawSetProportional(race_position_td[3], 1);

	race_position_td[4] = TextDrawCreate(56.333301, 271.289001, "------------------"); // Text element
	TextDrawLetterSize(race_position_td[4], 0.187665, 1.156147);
	TextDrawAlignment(race_position_td[4], 2);
	TextDrawColor(race_position_td[4], -1);
	TextDrawSetShadow(race_position_td[4], 0);
	TextDrawSetOutline(race_position_td[4], 0);
	TextDrawBackgroundColor(race_position_td[4], 51);
	TextDrawFont(race_position_td[4], 2);
	TextDrawSetProportional(race_position_td[4], 1);

	race_position_td[5] = TextDrawCreate(55.999973, 292.859313, "------------------"); // Text element
	TextDrawLetterSize(race_position_td[5], 0.187665, 1.156147);
	TextDrawAlignment(race_position_td[5], 2);
	TextDrawColor(race_position_td[5], -1);
	TextDrawSetShadow(race_position_td[5], 0);
	TextDrawSetOutline(race_position_td[5], 0);
	TextDrawBackgroundColor(race_position_td[5], 51);
	TextDrawFont(race_position_td[5], 2);
	TextDrawSetProportional(race_position_td[5], 1);


	race_car_in_box[0] = TextDrawCreate(-82.333328, -110.755607, "brilliantother:race_background"); // Texture element
	TextDrawLetterSize(race_car_in_box[0], 0.000000, 0.000000);
	TextDrawTextSize(race_car_in_box[0], 738.333129, 569.126220);
	TextDrawAlignment(race_car_in_box[0], 1);
	TextDrawColor(race_car_in_box[0], -144);
	TextDrawSetShadow(race_car_in_box[0], 0);
	TextDrawSetOutline(race_car_in_box[0], 0);
	TextDrawFont(race_car_in_box[0], 4);

	race_car_in_box[1] = TextDrawCreate(-8.000130, -110.340843, "brilliantother:race_background"); // Texture element
	TextDrawLetterSize(race_car_in_box[1], 0.000000, 0.000000);
	TextDrawTextSize(race_car_in_box[1], 1964.333007, 798.518554);
	TextDrawAlignment(race_car_in_box[1], 1);
	TextDrawColor(race_car_in_box[1], -141);
	TextDrawSetShadow(race_car_in_box[1], 0);
	TextDrawSetOutline(race_car_in_box[1], 0);
	TextDrawFont(race_car_in_box[1], 4);


	return true;
}

stock background_newyear()
{

	newyear_back[0] = TextDrawCreate(-1.666669, -5.392588, "brilliantother:newyear_background"); // Texture element
	TextDrawLetterSize(newyear_back[0], 0.000000, 0.000000);
	TextDrawTextSize(newyear_back[0], 737.999816, 458.370422);
	TextDrawAlignment(newyear_back[0], 2);
	TextDrawColor(newyear_back[0], -72);
	TextDrawSetShadow(newyear_back[0], 0);
	TextDrawSetOutline(newyear_back[0], 0);
	TextDrawBackgroundColor(newyear_back[0], 173);
	TextDrawFont(newyear_back[0], 4);

	newyear_back[1] = TextDrawCreate(318.666503, 0.829630, "brilliantother:newyear_background_2"); // Texture element
	TextDrawLetterSize(newyear_back[1], 0.000000, 0.000000);
	TextDrawTextSize(newyear_back[1], 471.333465, 454.637268);
	TextDrawAlignment(newyear_back[1], 1);
	TextDrawColor(newyear_back[1], -1);
	TextDrawSetShadow(newyear_back[1], 0);
	TextDrawSetOutline(newyear_back[1], 0);
	TextDrawFont(newyear_back[1], 4);


	return true;

}

stock create_number_td()
{
	buy_number_gai[0] = TextDrawCreate(222.000015, 90.429618, "brilliantother:number_pl_background_2"); // Texture element
	TextDrawLetterSize(buy_number_gai[0], 0.000000, 0.000000);
	TextDrawTextSize(buy_number_gai[0], 303.666809, 255.940628);
	TextDrawAlignment(buy_number_gai[0], 1);
	TextDrawColor(buy_number_gai[0], -1);
	TextDrawSetShadow(buy_number_gai[0], 0);
	TextDrawSetOutline(buy_number_gai[0], 0);
	TextDrawFont(buy_number_gai[0], 4);

	buy_number_gai[1] = TextDrawCreate(94.000000, 90.429634, "brilliantother:number_pl_background_3"); // Texture element
	TextDrawLetterSize(buy_number_gai[1], 0.000000, 0.000000);
	TextDrawTextSize(buy_number_gai[1], 116.666664, 255.525939);
	TextDrawAlignment(buy_number_gai[1], 1);
	TextDrawColor(buy_number_gai[1], -6619175);
	TextDrawSetShadow(buy_number_gai[1], 0);
	TextDrawSetOutline(buy_number_gai[1], 0);
	TextDrawFont(buy_number_gai[1], 4);

	buy_number_gai[2] = TextDrawCreate(108.000007, 104.118530, "brilliantother:number_pl_text_buy_1"); // Texture element
	TextDrawLetterSize(buy_number_gai[2], 0.000000, 0.000000);
	TextDrawTextSize(buy_number_gai[2], 83.333343, 14.933329);
	TextDrawAlignment(buy_number_gai[2], 1);
	TextDrawColor(buy_number_gai[2], -1);
	TextDrawSetShadow(buy_number_gai[2], 0);
	TextDrawSetOutline(buy_number_gai[2], 0);
	TextDrawFont(buy_number_gai[2], 4);

	buy_number_gai[3] = TextDrawCreate(228.000015, 104.118515, "brilliantother:number_pl_text_buy_2"); // Texture element
	TextDrawLetterSize(buy_number_gai[3], 0.000000, 0.000000);
	TextDrawTextSize(buy_number_gai[3], 126.000007, 30.696300);
	TextDrawAlignment(buy_number_gai[3], 1);
	TextDrawColor(buy_number_gai[3], -1);
	TextDrawSetShadow(buy_number_gai[3], 0);
	TextDrawSetOutline(buy_number_gai[3], 0);
	TextDrawFont(buy_number_gai[3], 4);

	buy_number_gai[4] = TextDrawCreate(227.666702, 138.962951, "brilliantother:number_pl_text_buy_3"); // Texture element
	TextDrawLetterSize(buy_number_gai[4], 0.000000, 0.000000);
	TextDrawTextSize(buy_number_gai[4], 121.666648, 9.540747);
	TextDrawAlignment(buy_number_gai[4], 1);
	TextDrawColor(buy_number_gai[4], -1);
	TextDrawSetShadow(buy_number_gai[4], 0);
	TextDrawSetOutline(buy_number_gai[4], 0);
	TextDrawFont(buy_number_gai[4], 4);

	buy_number_gai[5] = TextDrawCreate(272.000000, 171.733306, "brilliantother:number_pl_text_buy_4"); // Texture element
	TextDrawLetterSize(buy_number_gai[5], 0.000000, 0.000000);
	TextDrawTextSize(buy_number_gai[5], 64.000000, 9.955551);
	TextDrawAlignment(buy_number_gai[5], 1);
	TextDrawColor(buy_number_gai[5], -1);
	TextDrawSetShadow(buy_number_gai[5], 0);
	TextDrawSetOutline(buy_number_gai[5], 0);
	TextDrawFont(buy_number_gai[5], 4);

	buy_number_gai[6] = TextDrawCreate(220.333343, 182.103698, "brilliantother:number_pl_prew_button"); // Texture element
	TextDrawLetterSize(buy_number_gai[6], 0.000000, 0.000000);
	TextDrawTextSize(buy_number_gai[6], 47.999996, 60.977764);
	TextDrawAlignment(buy_number_gai[6], 2);
	TextDrawColor(buy_number_gai[6], -1);
	TextDrawSetShadow(buy_number_gai[6], 0);
	TextDrawSetOutline(buy_number_gai[6], 0);
	TextDrawFont(buy_number_gai[6], 4);
	TextDrawSetSelectable(buy_number_gai[6], true);

	buy_number_gai[7] = TextDrawCreate(477.333312, 182.103637, "brilliantother:number_pl_next_button"); // Texture element
	TextDrawLetterSize(buy_number_gai[7], 0.000000, 0.000000);
	TextDrawTextSize(buy_number_gai[7], 47.999996, 60.977764);
	TextDrawAlignment(buy_number_gai[7], 2);
	TextDrawColor(buy_number_gai[7], -1);
	TextDrawSetShadow(buy_number_gai[7], 0);
	TextDrawSetOutline(buy_number_gai[7], 0);
	TextDrawFont(buy_number_gai[7], 4);
	TextDrawSetSelectable(buy_number_gai[7], true);

	buy_number_gai[8] = TextDrawCreate(264.333312, 234.370346, "brilliantother:number_pl_prew_button_1"); // Texture element
	TextDrawLetterSize(buy_number_gai[8], 0.000000, 0.000000);
	TextDrawTextSize(buy_number_gai[8], 73.333381, 43.970355);
	TextDrawAlignment(buy_number_gai[8], 1);
	TextDrawColor(buy_number_gai[8], -1);
	TextDrawSetShadow(buy_number_gai[8], 0);
	TextDrawSetOutline(buy_number_gai[8], 0);
	TextDrawFont(buy_number_gai[8], 4);
	TextDrawSetSelectable(buy_number_gai[8], true);

	buy_number_gai[9] = TextDrawCreate(408.666687, 234.785140, "brilliantother:number_pl_next_button_1"); // Texture element
	TextDrawLetterSize(buy_number_gai[9], 0.000000, 0.000000);
	TextDrawTextSize(buy_number_gai[9], 73.333381, 43.970355);
	TextDrawAlignment(buy_number_gai[9], 1);
	TextDrawColor(buy_number_gai[9], -1);
	TextDrawSetShadow(buy_number_gai[9], 0);
	TextDrawSetOutline(buy_number_gai[9], 0);
	TextDrawFont(buy_number_gai[9], 4);
	TextDrawSetSelectable(buy_number_gai[9], true);

	buy_number_gai[10] = TextDrawCreate(412.333374, 293.688751, "brilliantother:number_pl_buy_number_button"); // Texture element
	TextDrawLetterSize(buy_number_gai[10], 0.000000, 0.000000);
	TextDrawTextSize(buy_number_gai[10], 106.000068, 39.822204);
	TextDrawAlignment(buy_number_gai[10], 1);
	TextDrawColor(buy_number_gai[10], -1);
	TextDrawSetShadow(buy_number_gai[10], 0);
	TextDrawSetOutline(buy_number_gai[10], 0);
	TextDrawFont(buy_number_gai[10], 4);
	TextDrawSetSelectable(buy_number_gai[10], true);

	buy_number_gai[11] = TextDrawCreate(267.000000, 187.081481, "brilliantother:number_pl_buy_background"); // Texture element
	TextDrawLetterSize(buy_number_gai[11], 0.000000, 0.000000);
	TextDrawTextSize(buy_number_gai[11], 214.000000, 44.385177);
	TextDrawAlignment(buy_number_gai[11], 1);
	TextDrawColor(buy_number_gai[11], -1);
	TextDrawSetShadow(buy_number_gai[11], 0);
	TextDrawSetOutline(buy_number_gai[11], 0);
	TextDrawFont(buy_number_gai[11], 4);

	buy_number_gai[12] = TextDrawCreate(488.000000, 95.822212, "brilliantother:number_pl_close_button"); // Texture element
	TextDrawLetterSize(buy_number_gai[12], 0.000000, 0.000000);
	TextDrawTextSize(buy_number_gai[12], 28.000000, 18.666664);
	TextDrawAlignment(buy_number_gai[12], 2);
	TextDrawColor(buy_number_gai[12], -1);
	TextDrawSetShadow(buy_number_gai[12], 0);
	TextDrawSetOutline(buy_number_gai[12], 0);
	TextDrawFont(buy_number_gai[12], 4);
	TextDrawSetSelectable(buy_number_gai[12], true);

	free_number_gai[0] = TextDrawCreate(127.666709, 80.888854, "brilliantother:number_pl_background_1"); // Texture element
	TextDrawLetterSize(free_number_gai[0], 0.000000, 0.000000);
	TextDrawTextSize(free_number_gai[0], 378.000122, 295.348236);
	TextDrawAlignment(free_number_gai[0], 1);
	TextDrawColor(free_number_gai[0], -1);
	TextDrawSetShadow(free_number_gai[0], 0);
	TextDrawSetOutline(free_number_gai[0], 0);
	TextDrawFont(free_number_gai[0], 4);

	free_number_gai[1] = TextDrawCreate(141.666671, 96.651863, "brilliantother:number_pl_text_free_1"); // Texture element
	TextDrawLetterSize(free_number_gai[1], 0.000000, 0.000000);
	TextDrawTextSize(free_number_gai[1], 139.333343, 34.844455);
	TextDrawAlignment(free_number_gai[1], 1);
	TextDrawColor(free_number_gai[1], -1);
	TextDrawSetShadow(free_number_gai[1], 0);
	TextDrawSetOutline(free_number_gai[1], 0);
	TextDrawFont(free_number_gai[1], 4);

	free_number_gai[2] = TextDrawCreate(142.000000, 136.474060, "brilliantother:number_pl_text_free_2"); // Texture element
	TextDrawLetterSize(free_number_gai[2], 0.000000, 1.033332);
	TextDrawTextSize(free_number_gai[2], 87.000000, 9.540736);
	TextDrawAlignment(free_number_gai[2], 1);
	TextDrawColor(free_number_gai[2], -1);
	TextDrawUseBox(free_number_gai[2], true);
	TextDrawBoxColor(free_number_gai[2], 0);
	TextDrawSetShadow(free_number_gai[2], 0);
	TextDrawSetOutline(free_number_gai[2], 0);
	TextDrawFont(free_number_gai[2], 4);

	free_number_gai[3] = TextDrawCreate(141.666687, 287.881408, "brilliantother:number_pl_text_buy_4"); // Texture element
	TextDrawLetterSize(free_number_gai[3], 0.000000, 0.000000);
	TextDrawTextSize(free_number_gai[3], 69.666679, 10.785169);
	TextDrawAlignment(free_number_gai[3], 1);
	TextDrawColor(free_number_gai[3], -1);
	TextDrawSetShadow(free_number_gai[3], 0);
	TextDrawSetOutline(free_number_gai[3], 0);
	TextDrawFont(free_number_gai[3], 4);

	free_number_gai[4] = TextDrawCreate(462.666656, 85.451850, "brilliantother:number_pl_close_button"); // Texture element
	TextDrawLetterSize(free_number_gai[4], 0.000000, 0.000000);
	TextDrawTextSize(free_number_gai[4], 25.333343, 18.666673);
	TextDrawAlignment(free_number_gai[4], 1);
	TextDrawColor(free_number_gai[4], -1);
	TextDrawSetShadow(free_number_gai[4], 0);
	TextDrawSetOutline(free_number_gai[4], 0);
	TextDrawFont(free_number_gai[4], 4);
	TextDrawSetSelectable(free_number_gai[4], 1);

	return true;

}

stock create_clothes_shop()
{

	clothes_select_td[0] = TextDrawCreate(77.333320, 154.725936, "brilliantother:left_button_clothes"); // Texture element
	TextDrawLetterSize(clothes_select_td[0], 0.000000, 0.000000);
	TextDrawTextSize(clothes_select_td[0], 64.666687, 129.836959);
	TextDrawAlignment(clothes_select_td[0], 2);
	TextDrawColor(clothes_select_td[0], -1);
	TextDrawSetShadow(clothes_select_td[0], 0);
	TextDrawSetOutline(clothes_select_td[0], 0);
	TextDrawFont(clothes_select_td[0], 4);
	TextDrawSetSelectable(clothes_select_td[0], true);

	clothes_select_td[1] = TextDrawCreate(484.000061, 152.237091, "brilliantother:right_button_clothes"); // Texture element
	TextDrawLetterSize(clothes_select_td[1], 0.000000, 0.000000);
	TextDrawTextSize(clothes_select_td[1], 64.666687, 129.836959);
	TextDrawAlignment(clothes_select_td[1], 2);
	TextDrawColor(clothes_select_td[1], -1);
	TextDrawSetShadow(clothes_select_td[1], 0);
	TextDrawSetOutline(clothes_select_td[1], 0);
	TextDrawFont(clothes_select_td[1], 4);
	TextDrawSetSelectable(clothes_select_td[1], true);

	clothes_select_td[2] = TextDrawCreate(250.000015, 333.925964, "brilliantother:money_icon_clothes"); // Texture element
	TextDrawLetterSize(clothes_select_td[2], 0.000000, 0.000000);
	TextDrawTextSize(clothes_select_td[2], 16.999998, 23.229660);
	TextDrawAlignment(clothes_select_td[2], 1);
	TextDrawColor(clothes_select_td[2], -1);
	TextDrawSetShadow(clothes_select_td[2], 0);
	TextDrawSetOutline(clothes_select_td[2], 0);
	TextDrawFont(clothes_select_td[2], 4);

	clothes_select_td[3] = TextDrawCreate(214.333297, 362.962951, "brilliantother:buy_button_clothes"); // Texture element
	TextDrawLetterSize(clothes_select_td[3], 0.000000, 0.000000);
	TextDrawTextSize(clothes_select_td[3], 95.999992, 38.577754);
	TextDrawAlignment(clothes_select_td[3], 2);
	TextDrawColor(clothes_select_td[3], -1);
	TextDrawSetShadow(clothes_select_td[3], 0);
	TextDrawSetOutline(clothes_select_td[3], 0);
	TextDrawFont(clothes_select_td[3], 4);
	TextDrawSetSelectable(clothes_select_td[3], true);

	clothes_select_td[4] = TextDrawCreate(324.666687, 360.888916, "brilliantother:exit_button_clothes"); // Texture element
	TextDrawLetterSize(clothes_select_td[4], 0.000000, 0.000000);
	TextDrawTextSize(clothes_select_td[4], 95.999992, 38.577754);
	TextDrawAlignment(clothes_select_td[4], 2);
	TextDrawColor(clothes_select_td[4], -1);
	TextDrawSetShadow(clothes_select_td[4], 0);
	TextDrawSetOutline(clothes_select_td[4], 0);
	TextDrawFont(clothes_select_td[4], 4);
	TextDrawSetSelectable(clothes_select_td[4], true);

	clothes_select_td[5] = TextDrawCreate(-1.000000, 379.140655, "brilliantother:background_clothes"); // Texture element
	TextDrawLetterSize(clothes_select_td[5], 0.000000, 0.000000);
	TextDrawTextSize(clothes_select_td[5], 646.333007, 94.992614);
	TextDrawAlignment(clothes_select_td[5], 1);
	TextDrawColor(clothes_select_td[5], -1);
	TextDrawSetShadow(clothes_select_td[5], 0);
	TextDrawSetOutline(clothes_select_td[5], 0);
	TextDrawFont(clothes_select_td[5], 4);


	return true;
}

stock create_inventory_global()
{

	inventory_gui_back[0] = TextDrawCreate(16.000000, 36.000000, "brillinv:inventory_main");
	TextDrawTextSize(inventory_gui_back[0], 610.000000, 370.000000);
	TextDrawAlignment(inventory_gui_back[0], 1);
	TextDrawColor(inventory_gui_back[0], -31);
	TextDrawBackgroundColor(inventory_gui_back[0], 255);
	TextDrawFont(inventory_gui_back[0], 4);
	TextDrawSetProportional(inventory_gui_back[0], 0);

	inventory_gui_back[1] = TextDrawCreate(46.066623, 126.081535, "brillinv:inventory_up");
	TextDrawTextSize(inventory_gui_back[1], 41.730213, 126.000000);
	TextDrawAlignment(inventory_gui_back[1], 1);
	TextDrawColor(inventory_gui_back[1], -1);
	TextDrawBackgroundColor(inventory_gui_back[1], 255);
	TextDrawFont(inventory_gui_back[1], 4);
	TextDrawSetProportional(inventory_gui_back[1], 0);
	TextDrawSetSelectable(inventory_gui_back[1], true);

	inventory_gui_back[2] = TextDrawCreate(46.066623, 267.081665, "brillinv:inventory_down");
	TextDrawTextSize(inventory_gui_back[2], 41.730213, 126.000000);
	TextDrawAlignment(inventory_gui_back[2], 1);
	TextDrawColor(inventory_gui_back[2], -1);
	TextDrawBackgroundColor(inventory_gui_back[2], 255);
	TextDrawFont(inventory_gui_back[2], 4);
	TextDrawSetProportional(inventory_gui_back[2], 0);
	TextDrawSetSelectable(inventory_gui_back[2], true);

	inventory_gui_back[3] = TextDrawCreate(590.999755, 48.059249, "brillinv:inventory_close");
	TextDrawTextSize(inventory_gui_back[3], 24.000000, 30.000000);
	TextDrawAlignment(inventory_gui_back[3], 1);
	TextDrawColor(inventory_gui_back[3], -1);
	TextDrawBackgroundColor(inventory_gui_back[3], 255);
	TextDrawFont(inventory_gui_back[3], 4);
	TextDrawSetProportional(inventory_gui_back[3], 0);
	TextDrawSetSelectable(inventory_gui_back[3], true);


	return true;
}

stock create_fire_work_p()
{
	fire_work_close = TextDrawCreate(414.000061, 136.888900, "brilliantother:close_button_big_2"); // Texture element
	TextDrawLetterSize(fire_work_close, 0.000000, 0.000000);
	TextDrawTextSize(fire_work_close, 25.666667, 34.014804);
	TextDrawAlignment(fire_work_close, 2);
	TextDrawColor(fire_work_close, -1);
	TextDrawSetShadow(fire_work_close, 0);
	TextDrawSetOutline(fire_work_close, 0);
	TextDrawFont(fire_work_close, 4);
	TextDrawSetSelectable(fire_work_close, true);

	return true;

}

stock create_fire_work_back()
{
	fire_panel_background = TextDrawCreate(18.333333, 206.577774, "brilliantother:fire_work_gui_4"); // Texture element
	TextDrawLetterSize(fire_panel_background, 0.000000, 0.000000);
	TextDrawTextSize(fire_panel_background, 146.666702, 141.036911);
	TextDrawAlignment(fire_panel_background, 2);
	TextDrawColor(fire_panel_background, -1);
	TextDrawSetShadow(fire_panel_background, 0);
	TextDrawSetOutline(fire_panel_background, 0);
	TextDrawFont(fire_panel_background, 4);

	fire_panel_close = TextDrawCreate(414.000061, 136.888900, "brilliantother:close_button_big_2"); // Texture element
	TextDrawLetterSize(fire_panel_close, 0.000000, 0.000000);
	TextDrawTextSize(fire_panel_close, 25.666667, 34.014804);
	TextDrawAlignment(fire_panel_close, 2);
	TextDrawColor(fire_panel_close, -1);
	TextDrawSetShadow(fire_panel_close, 0);
	TextDrawSetOutline(fire_panel_close, 0);
	TextDrawFont(fire_panel_close, 4);
	TextDrawSetSelectable(fire_panel_close, true);

	return true;

}

stock create_hospital_npc()
{
	hospital_npc[0] = TextDrawCreate(170.666671, 334.340728, "brilliantother:hospital_work_1"); // Texture element
	TextDrawLetterSize(hospital_npc[0], 0.000000, 0.000000);
	TextDrawTextSize(hospital_npc[0], 140.666656, 42.725975);
	TextDrawAlignment(hospital_npc[0], 2);
	TextDrawColor(hospital_npc[0], -1);
	TextDrawSetShadow(hospital_npc[0], 0);
	TextDrawSetOutline(hospital_npc[0], 0);
	TextDrawFont(hospital_npc[0], 4);
	TextDrawSetSelectable(hospital_npc[0], true);

	hospital_npc[1] = TextDrawCreate(282.666687, 310.696319, "brilliantother:hospital_work_2"); // Texture element
	TextDrawLetterSize(hospital_npc[1], 0.000000, 0.000000);
	TextDrawTextSize(hospital_npc[1], 78.666656, 88.770423);
	TextDrawAlignment(hospital_npc[1], 2);
	TextDrawColor(hospital_npc[1], -1);
	TextDrawSetShadow(hospital_npc[1], 0);
	TextDrawSetOutline(hospital_npc[1], 0);
	TextDrawFont(hospital_npc[1], 4);
	TextDrawSetSelectable(hospital_npc[1], true);

	hospital_npc[2] = TextDrawCreate(336.333343, 335.170349, "brilliantother:hospital_work_3"); // Texture element
	TextDrawLetterSize(hospital_npc[2], 0.000000, 0.000000);
	TextDrawTextSize(hospital_npc[2], 140.666656, 42.725975);
	TextDrawAlignment(hospital_npc[2], 2);
	TextDrawColor(hospital_npc[2], -1);
	TextDrawSetShadow(hospital_npc[2], 0);
	TextDrawSetOutline(hospital_npc[2], 0);
	TextDrawFont(hospital_npc[2], 4);
	TextDrawSetSelectable(hospital_npc[2], true);

	hospital_npc[3] = TextDrawCreate(150.666748, 377.066497, "brilliantother:hospital_work_4"); // Texture element
	TextDrawLetterSize(hospital_npc[3], 0.000000, 0.000000);
	TextDrawTextSize(hospital_npc[3], 140.666656, 42.725975);
	TextDrawAlignment(hospital_npc[3], 2);
	TextDrawColor(hospital_npc[3], -1);
	TextDrawSetShadow(hospital_npc[3], 0);
	TextDrawSetOutline(hospital_npc[3], 0);
	TextDrawFont(hospital_npc[3], 4);
	TextDrawSetSelectable(hospital_npc[3], true);

	hospital_npc[4] = TextDrawCreate(341.000061, 377.895965, "brilliantother:hospital_work_5"); // Texture element
	TextDrawLetterSize(hospital_npc[4], 0.000000, 0.000000);
	TextDrawTextSize(hospital_npc[4], 140.666656, 42.725975);
	TextDrawAlignment(hospital_npc[4], 2);
	TextDrawColor(hospital_npc[4], -1);
	TextDrawSetShadow(hospital_npc[4], 0);
	TextDrawSetOutline(hospital_npc[4], 0);
	TextDrawFont(hospital_npc[4], 4);
	TextDrawSetSelectable(hospital_npc[4], true);

	return true;
}

stock create_fish_other_td()
{
	fish_prefinal_panel[0] = TextDrawCreate(239.333328, 136.888900, "brilliantother:fish_button_card_gold"); // Texture element
	TextDrawLetterSize(fish_prefinal_panel[0], 0.000000, 0.000000);
	TextDrawTextSize(fish_prefinal_panel[0], 147.999984, 194.548141);
	TextDrawAlignment(fish_prefinal_panel[0], 1);
	TextDrawColor(fish_prefinal_panel[0], -1);
	TextDrawSetShadow(fish_prefinal_panel[0], 0);
	TextDrawSetOutline(fish_prefinal_panel[0], 0);
	TextDrawFont(fish_prefinal_panel[0], 4);
	TextDrawSetSelectable(fish_prefinal_panel[0], true);

	fish_prefinal_panel[1] = TextDrawCreate(239.000000, 341.392578, "brilliantother:fish_notify_1"); // Texture element
	TextDrawLetterSize(fish_prefinal_panel[1], 0.000000, 0.000000);
	TextDrawTextSize(fish_prefinal_panel[1], 150.666687, 46.044456);
	TextDrawAlignment(fish_prefinal_panel[1], 1);
	TextDrawColor(fish_prefinal_panel[1], -1);
	TextDrawSetShadow(fish_prefinal_panel[1], 0);
	TextDrawSetOutline(fish_prefinal_panel[1], 0);
	TextDrawFont(fish_prefinal_panel[1], 4);

	return true;
}

stock create_player_notify_work(playerid)
{
	if(work_notify_new[playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		work_notify_new[playerid] = CreatePlayerTextDraw(playerid, 256.000030, 130.666656, "brilliantother:fire_work_gui_5"); // Texture element
		PlayerTextDrawLetterSize(playerid, work_notify_new[playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, work_notify_new[playerid], 122.999961, 68.029640);
		PlayerTextDrawAlignment(playerid, work_notify_new[playerid], 2);
		PlayerTextDrawColor(playerid, work_notify_new[playerid], -1);
		PlayerTextDrawSetShadow(playerid, work_notify_new[playerid], 0);
		PlayerTextDrawSetOutline(playerid, work_notify_new[playerid], 0);
		PlayerTextDrawFont(playerid, work_notify_new[playerid], 4);
	}
	return true;
}

stock create_fish_final_player(playerid)
{
	if(fish_panel_final[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_final[0][playerid] = CreatePlayerTextDraw(playerid, 202.666732, 68.029586, "brilliantother:fish_background_effect_1"); // Texture element
		PlayerTextDrawLetterSize(playerid, fish_panel_final[0][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, fish_panel_final[0][playerid], 226.666702, 322.311096);
		PlayerTextDrawAlignment(playerid, fish_panel_final[0][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_final[0][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_final[0][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_final[0][playerid], 0);
		PlayerTextDrawFont(playerid, fish_panel_final[0][playerid], 4);
	}
	if(fish_panel_final[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_final[1][playerid] = CreatePlayerTextDraw(playerid, 243.666656, 133.155578, "brilliantother:fish_panel_final_1"); // Texture element
		PlayerTextDrawLetterSize(playerid, fish_panel_final[1][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, fish_panel_final[1][playerid], 131.666656, 189.985229);
		PlayerTextDrawAlignment(playerid, fish_panel_final[1][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_final[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_final[1][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_final[1][playerid], 0);
		PlayerTextDrawFont(playerid, fish_panel_final[1][playerid], 4);
	}
	if(fish_panel_final[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_final[2][playerid] = CreatePlayerTextDraw(playerid, 194.666671, 329.777770, "brilliantother:fish_button_final"); // Texture element
		PlayerTextDrawLetterSize(playerid, fish_panel_final[2][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, fish_panel_final[2][playerid], 113.000000, 39.407417);
		PlayerTextDrawAlignment(playerid, fish_panel_final[2][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_final[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_final[2][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_final[2][playerid], 0);
		PlayerTextDrawFont(playerid, fish_panel_final[2][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, fish_panel_final[2][playerid], true);
	}
	if(fish_panel_final[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_final[3][playerid] = CreatePlayerTextDraw(playerid, 308.333435, 329.362945, "brilliantother:fish_button_out"); // Texture element
		PlayerTextDrawLetterSize(playerid, fish_panel_final[3][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, fish_panel_final[3][playerid], 113.000000, 39.407417);
		PlayerTextDrawAlignment(playerid, fish_panel_final[3][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_final[3][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_final[3][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_final[3][playerid], 0);
		PlayerTextDrawFont(playerid, fish_panel_final[3][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, fish_panel_final[3][playerid], true);
	}
	if(fish_panel_final[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_final[4][playerid] = CreatePlayerTextDraw(playerid, 308.999938, 286.222198, "1"); // Text element
		PlayerTextDrawLetterSize(playerid, fish_panel_final[4][playerid], 0.378333, 1.923555);
		PlayerTextDrawAlignment(playerid, fish_panel_final[4][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_final[4][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_final[4][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_final[4][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, fish_panel_final[4][playerid], 51);
		PlayerTextDrawFont(playerid, fish_panel_final[4][playerid], 3);
		PlayerTextDrawSetProportional(playerid, fish_panel_final[4][playerid], 1);
	}
	return true;
}

stock create_fish_general_panel(playerid)
{

	if(fish_p_general[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_p_general[0][playerid] = CreatePlayerTextDraw(playerid, 218.666625, 37.333339, "brilliantother:fish_progress_bar_3"); // Texture element
		PlayerTextDrawLetterSize(playerid, fish_p_general[0][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, fish_p_general[0][playerid], 197.333343, 38.162960);
		PlayerTextDrawAlignment(playerid, fish_p_general[0][playerid], 1);
		PlayerTextDrawColor(playerid, fish_p_general[0][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_p_general[0][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_p_general[0][playerid], 0);
		PlayerTextDrawFont(playerid, fish_p_general[0][playerid], 4);
	}
	if(fish_p_general[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_p_general[1][playerid] = CreatePlayerTextDraw(playerid, 218.333358, 164.681488, "brilliantother:fish_object_3"); // Texture element
		PlayerTextDrawLetterSize(playerid, fish_p_general[1][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, fish_p_general[1][playerid], 119.333343, 90.429672);
		PlayerTextDrawAlignment(playerid, fish_p_general[1][playerid], 1);
		PlayerTextDrawColor(playerid, fish_p_general[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_p_general[1][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_p_general[1][playerid], 0);
		PlayerTextDrawFont(playerid, fish_p_general[1][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, fish_p_general[1][playerid], true);
	}
	if(fish_p_general[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_p_general[2][playerid] = CreatePlayerTextDraw(playerid, 243.333312, 338.488800, "brilliantother:fish_button_final"); // Texture element
		PlayerTextDrawLetterSize(playerid, fish_p_general[2][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, fish_p_general[2][playerid], 158.333312, 53.096313);
		PlayerTextDrawAlignment(playerid, fish_p_general[2][playerid], 1);
		PlayerTextDrawColor(playerid, fish_p_general[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_p_general[2][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_p_general[2][playerid], 0);
		PlayerTextDrawFont(playerid, fish_p_general[2][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, fish_p_general[2][playerid], true);
	}
	if(fish_p_general[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_p_general[3][playerid] = CreatePlayerTextDraw(playerid, 535.333435, 26.548149, "brilliantother:hospital_work_2"); // Texture element
		PlayerTextDrawLetterSize(playerid, fish_p_general[3][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, fish_p_general[3][playerid], 49.999961, 59.318527);
		PlayerTextDrawAlignment(playerid, fish_p_general[3][playerid], 2);
		PlayerTextDrawColor(playerid, fish_p_general[3][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_p_general[3][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_p_general[3][playerid], 0);
		PlayerTextDrawFont(playerid, fish_p_general[3][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, fish_p_general[3][playerid], true);
	}



	return true;
}


stock create_fish_panel_all(playerid)
{
	if(fish_panel_all[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_all[0][playerid] = CreatePlayerTextDraw(playerid, 0.000000, 0.000000, "brilliantother:fish_background_card"); // Texture element
		PlayerTextDrawLetterSize(playerid, fish_panel_all[0][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, fish_panel_all[0][playerid], 643.333312, 448.000000);
		PlayerTextDrawAlignment(playerid, fish_panel_all[0][playerid], 1);
		PlayerTextDrawColor(playerid, fish_panel_all[0][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_all[0][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_all[0][playerid], 0);
		PlayerTextDrawFont(playerid, fish_panel_all[0][playerid], 4);
	}
	if(fish_panel_all[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_all[1][playerid] = CreatePlayerTextDraw(playerid, 36.666664, 51.851852, "brilliantother:fish_panel_final_1"); // Texture element
		PlayerTextDrawLetterSize(playerid, fish_panel_all[1][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, fish_panel_all[1][playerid], 92.333297, 124.859252);
		PlayerTextDrawAlignment(playerid, fish_panel_all[1][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_all[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_all[1][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_all[1][playerid], 0);
		PlayerTextDrawFont(playerid, fish_panel_all[1][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, fish_panel_all[1][playerid], true);
	}
	if(fish_panel_all[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_all[2][playerid] = CreatePlayerTextDraw(playerid, 144.000000, 51.022224, "brilliantother:fish_panel_final_2"); // Texture element
		PlayerTextDrawLetterSize(playerid, fish_panel_all[2][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, fish_panel_all[2][playerid], 89.000038, 126.103569);
		PlayerTextDrawAlignment(playerid, fish_panel_all[2][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_all[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_all[2][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_all[2][playerid], 0);
		PlayerTextDrawFont(playerid, fish_panel_all[2][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, fish_panel_all[2][playerid], true);
	}
	if(fish_panel_all[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_all[3][playerid] = CreatePlayerTextDraw(playerid, 246.999923, 51.022224, "brilliantother:fish_panel_final_3"); // Texture element
		PlayerTextDrawLetterSize(playerid, fish_panel_all[3][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, fish_panel_all[3][playerid], 94.333320, 125.688766);
		PlayerTextDrawAlignment(playerid, fish_panel_all[3][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_all[3][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_all[3][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_all[3][playerid], 0);
		PlayerTextDrawFont(playerid, fish_panel_all[3][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, fish_panel_all[3][playerid], true);
	}
	if(fish_panel_all[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_all[4][playerid] = CreatePlayerTextDraw(playerid, 354.333099, 50.607410, "brilliantother:fish_panel_final_4"); // Texture element
		PlayerTextDrawLetterSize(playerid, fish_panel_all[4][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, fish_panel_all[4][playerid], 95.000000, 125.273910);
		PlayerTextDrawAlignment(playerid, fish_panel_all[4][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_all[4][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_all[4][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_all[4][playerid], 0);
		PlayerTextDrawFont(playerid, fish_panel_all[4][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, fish_panel_all[4][playerid], true);
	}
	if(fish_panel_all[5][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_all[5][playerid] = CreatePlayerTextDraw(playerid, 462.666656, 51.437038, "brilliantother:fish_panel_final_5"); // Texture element
		PlayerTextDrawLetterSize(playerid, fish_panel_all[5][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, fish_panel_all[5][playerid], 96.000000, 126.103591);
		PlayerTextDrawAlignment(playerid, fish_panel_all[5][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_all[5][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_all[5][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_all[5][playerid], 0);
		PlayerTextDrawFont(playerid, fish_panel_all[5][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, fish_panel_all[5][playerid], true);
	}
	if(fish_panel_all[6][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_all[6][playerid] = CreatePlayerTextDraw(playerid, 36.999931, 179.614868, "brilliantother:fish_panel_final_6"); // Texture element
		PlayerTextDrawLetterSize(playerid, fish_panel_all[6][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, fish_panel_all[6][playerid], 92.333328, 127.348045);
		PlayerTextDrawAlignment(playerid, fish_panel_all[6][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_all[6][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_all[6][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_all[6][playerid], 0);
		PlayerTextDrawFont(playerid, fish_panel_all[6][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, fish_panel_all[6][playerid], true);
	}
	if(fish_panel_all[7][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_all[7][playerid] = CreatePlayerTextDraw(playerid, 143.999954, 179.614837, "brilliantother:fish_panel_final_7"); // Texture element
		PlayerTextDrawLetterSize(playerid, fish_panel_all[7][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, fish_panel_all[7][playerid], 89.333358, 128.592483);
		PlayerTextDrawAlignment(playerid, fish_panel_all[7][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_all[7][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_all[7][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_all[7][playerid], 0);
		PlayerTextDrawFont(playerid, fish_panel_all[7][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, fish_panel_all[7][playerid], true);
	}
	if(fish_panel_all[8][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_all[8][playerid] = CreatePlayerTextDraw(playerid, 245.999938, 179.614791, "brilliantother:fish_panel_final_8"); // Texture element
		PlayerTextDrawLetterSize(playerid, fish_panel_all[8][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, fish_panel_all[8][playerid], 96.666702, 131.496215);
		PlayerTextDrawAlignment(playerid, fish_panel_all[8][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_all[8][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_all[8][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_all[8][playerid], 0);
		PlayerTextDrawFont(playerid, fish_panel_all[8][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, fish_panel_all[8][playerid], true);
	}
	if(fish_panel_all[9][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_all[9][playerid] = CreatePlayerTextDraw(playerid, 353.333160, 179.614883, "brilliantother:fish_panel_final_9"); // Texture element
		PlayerTextDrawLetterSize(playerid, fish_panel_all[9][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, fish_panel_all[9][playerid], 98.000045, 131.081329);
		PlayerTextDrawAlignment(playerid, fish_panel_all[9][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_all[9][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_all[9][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_all[9][playerid], 0);
		PlayerTextDrawFont(playerid, fish_panel_all[9][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, fish_panel_all[9][playerid], true);
	}
	if(fish_panel_all[10][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_all[10][playerid] = CreatePlayerTextDraw(playerid, 462.666564, 180.444519, "brilliantother:fish_panel_final_10"); // Texture element
		PlayerTextDrawLetterSize(playerid, fish_panel_all[10][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, fish_panel_all[10][playerid], 98.000068, 129.836944);
		PlayerTextDrawAlignment(playerid, fish_panel_all[10][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_all[10][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_all[10][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_all[10][playerid], 0);
		PlayerTextDrawFont(playerid, fish_panel_all[10][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, fish_panel_all[10][playerid], true);
	}
	if(fish_panel_all[11][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_all[11][playerid] = CreatePlayerTextDraw(playerid, 35.999893, 312.355468, "brilliantother:fish_panel_final_11"); // Texture element
		PlayerTextDrawLetterSize(playerid, fish_panel_all[11][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, fish_panel_all[11][playerid], 93.666740, 129.836944);
		PlayerTextDrawAlignment(playerid, fish_panel_all[11][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_all[11][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_all[11][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_all[11][playerid], 0);
		PlayerTextDrawFont(playerid, fish_panel_all[11][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, fish_panel_all[11][playerid], true);
	}
	if(fish_panel_all[12][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_all[12][playerid] = CreatePlayerTextDraw(playerid, 142.333282, 312.355438, "brilliantother:fish_panel_final_12"); // Texture element
		PlayerTextDrawLetterSize(playerid, fish_panel_all[12][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, fish_panel_all[12][playerid], 91.333404, 129.836944);
		PlayerTextDrawAlignment(playerid, fish_panel_all[12][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_all[12][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_all[12][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_all[12][playerid], 0);
		PlayerTextDrawFont(playerid, fish_panel_all[12][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, fish_panel_all[12][playerid], true);
	}
	if(fish_panel_all[13][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_all[13][playerid] = CreatePlayerTextDraw(playerid, 244.999908, 313.599914, "brilliantother:fish_panel_final_13"); // Texture element
		PlayerTextDrawLetterSize(playerid, fish_panel_all[13][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, fish_panel_all[13][playerid], 99.666740, 130.251754);
		PlayerTextDrawAlignment(playerid, fish_panel_all[13][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_all[13][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_all[13][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_all[13][playerid], 0);
		PlayerTextDrawFont(playerid, fish_panel_all[13][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, fish_panel_all[13][playerid], true);
	}
	if(fish_panel_all[14][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_all[14][playerid] = CreatePlayerTextDraw(playerid, 352.666595, 313.599914, "brilliantother:fish_panel_final_14"); // Texture element
		PlayerTextDrawLetterSize(playerid, fish_panel_all[14][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, fish_panel_all[14][playerid], 100.333427, 130.251754);
		PlayerTextDrawAlignment(playerid, fish_panel_all[14][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_all[14][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_all[14][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_all[14][playerid], 0);
		PlayerTextDrawFont(playerid, fish_panel_all[14][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, fish_panel_all[14][playerid], true);
	}
	if(fish_panel_all[15][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_all[15][playerid] = CreatePlayerTextDraw(playerid, 461.999908, 313.599914, "brilliantother:fish_panel_final_15"); // Texture element
		PlayerTextDrawLetterSize(playerid, fish_panel_all[15][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, fish_panel_all[15][playerid], 100.333435, 129.836944);
		PlayerTextDrawAlignment(playerid, fish_panel_all[15][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_all[15][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_all[15][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_all[15][playerid], 0);
		PlayerTextDrawFont(playerid, fish_panel_all[15][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, fish_panel_all[15][playerid], true);
	}
	if(fish_panel_all[16][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_all[16][playerid] = CreatePlayerTextDraw(playerid, 555.000000, 7.881480, "brilliantother:hospital_work_2"); // Texture element
		PlayerTextDrawLetterSize(playerid, fish_panel_all[16][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, fish_panel_all[16][playerid], 53.999980, 63.051849);
		PlayerTextDrawAlignment(playerid, fish_panel_all[16][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_all[16][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_all[16][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_all[16][playerid], 0);
		PlayerTextDrawFont(playerid, fish_panel_all[16][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, fish_panel_all[16][playerid], true);
	}
	if(fish_panel_all[17][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_all[17][playerid] = CreatePlayerTextDraw(playerid, 83.666664, 152.651809, "1"); // Text element
		PlayerTextDrawLetterSize(playerid, fish_panel_all[17][playerid], 0.367333, 1.803258);
		PlayerTextDrawAlignment(playerid, fish_panel_all[17][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_all[17][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_all[17][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_all[17][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, fish_panel_all[17][playerid], 51);
		PlayerTextDrawFont(playerid, fish_panel_all[17][playerid], 3);
		PlayerTextDrawSetProportional(playerid, fish_panel_all[17][playerid], 1);
	}
	if(fish_panel_all[18][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_all[18][playerid] = CreatePlayerTextDraw(playerid, 189.333328, 151.822189, "2"); // Text element
		PlayerTextDrawLetterSize(playerid, fish_panel_all[18][playerid], 0.367333, 1.803258);
		PlayerTextDrawAlignment(playerid, fish_panel_all[18][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_all[18][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_all[18][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_all[18][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, fish_panel_all[18][playerid], 51);
		PlayerTextDrawFont(playerid, fish_panel_all[18][playerid], 3);
		PlayerTextDrawSetProportional(playerid, fish_panel_all[18][playerid], 1);
	}
	if(fish_panel_all[19][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_all[19][playerid] = CreatePlayerTextDraw(playerid, 294.000030, 151.407379, "3"); // Text element
		PlayerTextDrawLetterSize(playerid, fish_panel_all[19][playerid], 0.367333, 1.803258);
		PlayerTextDrawAlignment(playerid, fish_panel_all[19][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_all[19][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_all[19][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_all[19][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, fish_panel_all[19][playerid], 51);
		PlayerTextDrawFont(playerid, fish_panel_all[19][playerid], 3);
		PlayerTextDrawSetProportional(playerid, fish_panel_all[19][playerid], 1);
	}
	if(fish_panel_all[20][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_all[20][playerid] = CreatePlayerTextDraw(playerid, 402.000030, 150.162933, "4"); // Text element
		PlayerTextDrawLetterSize(playerid, fish_panel_all[20][playerid], 0.367333, 1.803258);
		PlayerTextDrawAlignment(playerid, fish_panel_all[20][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_all[20][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_all[20][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_all[20][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, fish_panel_all[20][playerid], 51);
		PlayerTextDrawFont(playerid, fish_panel_all[20][playerid], 3);
		PlayerTextDrawSetProportional(playerid, fish_panel_all[20][playerid], 1);
	}
	if(fish_panel_all[21][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_all[21][playerid] = CreatePlayerTextDraw(playerid, 510.666748, 151.822189, "5"); // Text element
		PlayerTextDrawLetterSize(playerid, fish_panel_all[21][playerid], 0.367333, 1.803258);
		PlayerTextDrawAlignment(playerid, fish_panel_all[21][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_all[21][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_all[21][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_all[21][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, fish_panel_all[21][playerid], 51);
		PlayerTextDrawFont(playerid, fish_panel_all[21][playerid], 3);
		PlayerTextDrawSetProportional(playerid, fish_panel_all[21][playerid], 1);
	}
	if(fish_panel_all[22][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_all[22][playerid] = CreatePlayerTextDraw(playerid, 82.333358, 282.074066, "6"); // Text element
		PlayerTextDrawLetterSize(playerid, fish_panel_all[22][playerid], 0.367333, 1.803258);
		PlayerTextDrawAlignment(playerid, fish_panel_all[22][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_all[22][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_all[22][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_all[22][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, fish_panel_all[22][playerid], 51);
		PlayerTextDrawFont(playerid, fish_panel_all[22][playerid], 3);
		PlayerTextDrawSetProportional(playerid, fish_panel_all[22][playerid], 1);
	}
	if(fish_panel_all[23][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_all[23][playerid] = CreatePlayerTextDraw(playerid, 188.666641, 282.074066, "7"); // Text element
		PlayerTextDrawLetterSize(playerid, fish_panel_all[23][playerid], 0.367333, 1.803258);
		PlayerTextDrawAlignment(playerid, fish_panel_all[23][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_all[23][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_all[23][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_all[23][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, fish_panel_all[23][playerid], 51);
		PlayerTextDrawFont(playerid, fish_panel_all[23][playerid], 3);
		PlayerTextDrawSetProportional(playerid, fish_panel_all[23][playerid], 1);
	}
	if(fish_panel_all[24][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_all[24][playerid] = CreatePlayerTextDraw(playerid, 294.000000, 284.148162, "8"); // Text element
		PlayerTextDrawLetterSize(playerid, fish_panel_all[24][playerid], 0.367333, 1.803258);
		PlayerTextDrawAlignment(playerid, fish_panel_all[24][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_all[24][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_all[24][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_all[24][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, fish_panel_all[24][playerid], 51);
		PlayerTextDrawFont(playerid, fish_panel_all[24][playerid], 3);
		PlayerTextDrawSetProportional(playerid, fish_panel_all[24][playerid], 1);
	}
	if(fish_panel_all[25][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_all[25][playerid] = CreatePlayerTextDraw(playerid, 402.333251, 283.318420, "9"); // Text element
		PlayerTextDrawLetterSize(playerid, fish_panel_all[25][playerid], 0.367333, 1.803258);
		PlayerTextDrawAlignment(playerid, fish_panel_all[25][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_all[25][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_all[25][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_all[25][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, fish_panel_all[25][playerid], 51);
		PlayerTextDrawFont(playerid, fish_panel_all[25][playerid], 3);
		PlayerTextDrawSetProportional(playerid, fish_panel_all[25][playerid], 1);
	}
	if(fish_panel_all[26][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_all[26][playerid] = CreatePlayerTextDraw(playerid, 512.666625, 283.733215, "10"); // Text element
		PlayerTextDrawLetterSize(playerid, fish_panel_all[26][playerid], 0.367333, 1.803258);
		PlayerTextDrawAlignment(playerid, fish_panel_all[26][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_all[26][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_all[26][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_all[26][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, fish_panel_all[26][playerid], 51);
		PlayerTextDrawFont(playerid, fish_panel_all[26][playerid], 3);
		PlayerTextDrawSetProportional(playerid, fish_panel_all[26][playerid], 1);
	}
	if(fish_panel_all[27][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_all[27][playerid] = CreatePlayerTextDraw(playerid, 83.333206, 416.473968, "11"); // Text element
		PlayerTextDrawLetterSize(playerid, fish_panel_all[27][playerid], 0.367333, 1.803258);
		PlayerTextDrawAlignment(playerid, fish_panel_all[27][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_all[27][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_all[27][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_all[27][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, fish_panel_all[27][playerid], 51);
		PlayerTextDrawFont(playerid, fish_panel_all[27][playerid], 3);
		PlayerTextDrawSetProportional(playerid, fish_panel_all[27][playerid], 1);
	}
	if(fish_panel_all[28][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_all[28][playerid] = CreatePlayerTextDraw(playerid, 187.999801, 416.888824, "12"); // Text element
		PlayerTextDrawLetterSize(playerid, fish_panel_all[28][playerid], 0.367333, 1.803258);
		PlayerTextDrawAlignment(playerid, fish_panel_all[28][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_all[28][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_all[28][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_all[28][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, fish_panel_all[28][playerid], 51);
		PlayerTextDrawFont(playerid, fish_panel_all[28][playerid], 3);
		PlayerTextDrawSetProportional(playerid, fish_panel_all[28][playerid], 1);
	}
	if(fish_panel_all[29][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_all[29][playerid] = CreatePlayerTextDraw(playerid, 294.999816, 418.133209, "13"); // Text element
		PlayerTextDrawLetterSize(playerid, fish_panel_all[29][playerid], 0.367333, 1.803258);
		PlayerTextDrawAlignment(playerid, fish_panel_all[29][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_all[29][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_all[29][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_all[29][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, fish_panel_all[29][playerid], 51);
		PlayerTextDrawFont(playerid, fish_panel_all[29][playerid], 3);
		PlayerTextDrawSetProportional(playerid, fish_panel_all[29][playerid], 1);
	}
	if(fish_panel_all[30][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_all[30][playerid] = CreatePlayerTextDraw(playerid, 403.333068, 417.718414, "14"); // Text element
		PlayerTextDrawLetterSize(playerid, fish_panel_all[30][playerid], 0.367333, 1.803258);
		PlayerTextDrawAlignment(playerid, fish_panel_all[30][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_all[30][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_all[30][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_all[30][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, fish_panel_all[30][playerid], 51);
		PlayerTextDrawFont(playerid, fish_panel_all[30][playerid], 3);
		PlayerTextDrawSetProportional(playerid, fish_panel_all[30][playerid], 1);
	}
	if(fish_panel_all[31][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fish_panel_all[31][playerid] = CreatePlayerTextDraw(playerid, 513.333007, 418.548065, "15"); // Text element
		PlayerTextDrawLetterSize(playerid, fish_panel_all[31][playerid], 0.367333, 1.803258);
		PlayerTextDrawAlignment(playerid, fish_panel_all[31][playerid], 2);
		PlayerTextDrawColor(playerid, fish_panel_all[31][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fish_panel_all[31][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fish_panel_all[31][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, fish_panel_all[31][playerid], 51);
		PlayerTextDrawFont(playerid, fish_panel_all[31][playerid], 3);
		PlayerTextDrawSetProportional(playerid, fish_panel_all[31][playerid], 1);
	}
	return true;
}

stock create_taxi_work_dop(playerid)
{
	if(work_taxi_panel[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		work_taxi_panel[0][playerid] = CreatePlayerTextDraw(playerid, 149.666625, 133.985168, "brilliantother:tax_work_back_1"); // Texture element
		PlayerTextDrawLetterSize(playerid, work_taxi_panel[0][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, work_taxi_panel[0][playerid], 341.333251, 210.725952);
		PlayerTextDrawAlignment(playerid, work_taxi_panel[0][playerid], 2);
		PlayerTextDrawColor(playerid, work_taxi_panel[0][playerid], -1);
		PlayerTextDrawSetShadow(playerid, work_taxi_panel[0][playerid], 0);
		PlayerTextDrawSetOutline(playerid, work_taxi_panel[0][playerid], 0);
		PlayerTextDrawFont(playerid, work_taxi_panel[0][playerid], 4);
	}
	if(work_taxi_panel[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		work_taxi_panel[1][playerid] = CreatePlayerTextDraw(playerid, 301.000030, 186.666671, "brilliantother:tax_work_button_1"); // Texture element
		PlayerTextDrawLetterSize(playerid, work_taxi_panel[1][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, work_taxi_panel[1][playerid], 90.666725, 121.540809);
		PlayerTextDrawAlignment(playerid, work_taxi_panel[1][playerid], 2);
		PlayerTextDrawColor(playerid, work_taxi_panel[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, work_taxi_panel[1][playerid], 0);
		PlayerTextDrawSetOutline(playerid, work_taxi_panel[1][playerid], 0);
		PlayerTextDrawFont(playerid, work_taxi_panel[1][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, work_taxi_panel[1][playerid], true);
	}
	if(work_taxi_panel[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		work_taxi_panel[2][playerid] = CreatePlayerTextDraw(playerid, 395.666687, 185.837066, "brilliantother:tax_work_button_2"); // Texture element
		PlayerTextDrawLetterSize(playerid, work_taxi_panel[2][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, work_taxi_panel[2][playerid], 91.000045, 122.370429);
		PlayerTextDrawAlignment(playerid, work_taxi_panel[2][playerid], 2);
		PlayerTextDrawColor(playerid, work_taxi_panel[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, work_taxi_panel[2][playerid], 0);
		PlayerTextDrawSetOutline(playerid, work_taxi_panel[2][playerid], 0);
		PlayerTextDrawFont(playerid, work_taxi_panel[2][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, work_taxi_panel[2][playerid], true);
	}
	if(work_taxi_panel[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		work_taxi_panel[3][playerid] = CreatePlayerTextDraw(playerid, 452.999969, 129.007400, "brilliantother:close_button_big"); // Texture element
		PlayerTextDrawLetterSize(playerid, work_taxi_panel[3][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, work_taxi_panel[3][playerid], 41.000015, 48.948139);
		PlayerTextDrawAlignment(playerid, work_taxi_panel[3][playerid], 2);
		PlayerTextDrawColor(playerid, work_taxi_panel[3][playerid], -1);
		PlayerTextDrawSetShadow(playerid, work_taxi_panel[3][playerid], 0);
		PlayerTextDrawSetOutline(playerid, work_taxi_panel[3][playerid], 0);
		PlayerTextDrawFont(playerid, work_taxi_panel[3][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, work_taxi_panel[3][playerid], true);
	}
	return true;
}

stock create_other_info_tax(playerid)
{

	if(work_tax_info_p[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		work_tax_info_p[0][playerid] = CreatePlayerTextDraw(playerid, 12.333333, 191.229629, "brilliantother:work_info_taxi"); // Texture element
		PlayerTextDrawLetterSize(playerid, work_tax_info_p[0][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, work_tax_info_p[0][playerid], 78.333305, 107.437011);
		PlayerTextDrawAlignment(playerid, work_tax_info_p[0][playerid], 2);
		PlayerTextDrawColor(playerid, work_tax_info_p[0][playerid], -1);
		PlayerTextDrawSetShadow(playerid, work_tax_info_p[0][playerid], 0);
		PlayerTextDrawSetOutline(playerid, work_tax_info_p[0][playerid], 0);
		PlayerTextDrawFont(playerid, work_tax_info_p[0][playerid], 4);
	}
	if(work_tax_info_p[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		work_tax_info_p[1][playerid] = CreatePlayerTextDraw(playerid, 58.999977, 216.533340, "1000"); // Text element
		PlayerTextDrawLetterSize(playerid, work_tax_info_p[1][playerid], 0.208666, 1.405036);
		PlayerTextDrawAlignment(playerid, work_tax_info_p[1][playerid], 2);
		PlayerTextDrawColor(playerid, work_tax_info_p[1][playerid], -1);
		PlayerTextDrawUseBox(playerid, work_tax_info_p[1][playerid], true);
		PlayerTextDrawBoxColor(playerid, work_tax_info_p[1][playerid], 0);
		PlayerTextDrawSetShadow(playerid, work_tax_info_p[1][playerid], 0);
		PlayerTextDrawSetOutline(playerid, work_tax_info_p[1][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, work_tax_info_p[1][playerid], 51);
		PlayerTextDrawFont(playerid, work_tax_info_p[1][playerid], 2);
		PlayerTextDrawSetProportional(playerid, work_tax_info_p[1][playerid], 1);
	}
	if(work_tax_info_p[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		work_tax_info_p[2][playerid] = CreatePlayerTextDraw(playerid, 61.999973, 252.622177, "5000_RUB"); // Text element
		PlayerTextDrawLetterSize(playerid, work_tax_info_p[2][playerid], 0.216666, 1.417482);
		PlayerTextDrawAlignment(playerid, work_tax_info_p[2][playerid], 2);
		PlayerTextDrawColor(playerid, work_tax_info_p[2][playerid], -1);
		PlayerTextDrawUseBox(playerid, work_tax_info_p[2][playerid], true);
		PlayerTextDrawBoxColor(playerid, work_tax_info_p[2][playerid], 0);
		PlayerTextDrawSetShadow(playerid, work_tax_info_p[2][playerid], 0);
		PlayerTextDrawSetOutline(playerid, work_tax_info_p[2][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, work_tax_info_p[2][playerid], 51);
		PlayerTextDrawFont(playerid, work_tax_info_p[2][playerid], 2);
		PlayerTextDrawSetProportional(playerid, work_tax_info_p[2][playerid], 1);
	}
	return true;
}

stock create_work_panel_bank(playerid)
{
	if(work_bank_panel_p[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		work_bank_panel_p[0][playerid] = CreatePlayerTextDraw(playerid, 154.000015, 144.355545, "brilliantother:work_bank_background"); // Texture element
		PlayerTextDrawLetterSize(playerid, work_bank_panel_p[0][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, work_bank_panel_p[0][playerid], 325.000000, 203.674087);
		PlayerTextDrawAlignment(playerid, work_bank_panel_p[0][playerid], 2);
		PlayerTextDrawColor(playerid, work_bank_panel_p[0][playerid], -1);
		PlayerTextDrawSetShadow(playerid, work_bank_panel_p[0][playerid], 0);
		PlayerTextDrawSetOutline(playerid, work_bank_panel_p[0][playerid], 0);
		PlayerTextDrawFont(playerid, work_bank_panel_p[0][playerid], 4);
	}
	if(work_bank_panel_p[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		work_bank_panel_p[1][playerid] = CreatePlayerTextDraw(playerid, 352.666748, 197.451873, "brilliantother:work_bank_button_1"); // Texture element
		PlayerTextDrawLetterSize(playerid, work_bank_panel_p[1][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, work_bank_panel_p[1][playerid], 90.666664, 123.614761);
		PlayerTextDrawAlignment(playerid, work_bank_panel_p[1][playerid], 2);
		PlayerTextDrawColor(playerid, work_bank_panel_p[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, work_bank_panel_p[1][playerid], 0);
		PlayerTextDrawSetOutline(playerid, work_bank_panel_p[1][playerid], 0);
		PlayerTextDrawFont(playerid, work_bank_panel_p[1][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, work_bank_panel_p[1][playerid], true);
	}
	if(work_bank_panel_p[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		work_bank_panel_p[2][playerid] = CreatePlayerTextDraw(playerid, 451.000000, 146.844436, "brilliantother:close_button_big_2"); // Texture element
		PlayerTextDrawLetterSize(playerid, work_bank_panel_p[2][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, work_bank_panel_p[2][playerid], 24.666667, 32.770374);
		PlayerTextDrawAlignment(playerid, work_bank_panel_p[2][playerid], 2);
		PlayerTextDrawColor(playerid, work_bank_panel_p[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, work_bank_panel_p[2][playerid], 0);
		PlayerTextDrawSetOutline(playerid, work_bank_panel_p[2][playerid], 0);
		PlayerTextDrawFont(playerid, work_bank_panel_p[2][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, work_bank_panel_p[2][playerid], true);
	}
	return true;
}

stock create_work_panel_trash(playerid)
{
	if(work_trash_panel_p[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		work_trash_panel_p[0][playerid] = CreatePlayerTextDraw(playerid, 154.000015, 144.355545, "brilliantother:musor_work_gui"); // Texture element
		PlayerTextDrawLetterSize(playerid, work_trash_panel_p[0][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, work_trash_panel_p[0][playerid], 325.000000, 203.674087);
		PlayerTextDrawAlignment(playerid, work_trash_panel_p[0][playerid], 2);
		PlayerTextDrawColor(playerid, work_trash_panel_p[0][playerid], -1);
		PlayerTextDrawSetShadow(playerid, work_trash_panel_p[0][playerid], 0);
		PlayerTextDrawSetOutline(playerid, work_trash_panel_p[0][playerid], 0);
		PlayerTextDrawFont(playerid, work_trash_panel_p[0][playerid], 4);
	}
	if(work_trash_panel_p[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		work_trash_panel_p[1][playerid] = CreatePlayerTextDraw(playerid, 352.666748, 197.451873, "brilliantother:work_bank_button_1"); // Texture element
		PlayerTextDrawLetterSize(playerid, work_trash_panel_p[1][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, work_trash_panel_p[1][playerid], 90.666664, 123.614761);
		PlayerTextDrawAlignment(playerid, work_trash_panel_p[1][playerid], 2);
		PlayerTextDrawColor(playerid, work_trash_panel_p[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, work_trash_panel_p[1][playerid], 0);
		PlayerTextDrawSetOutline(playerid, work_trash_panel_p[1][playerid], 0);
		PlayerTextDrawFont(playerid, work_trash_panel_p[1][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, work_trash_panel_p[1][playerid], true);
	}
	if(work_trash_panel_p[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		work_trash_panel_p[2][playerid] = CreatePlayerTextDraw(playerid, 451.000000, 146.844436, "brilliantother:close_button_big_2"); // Texture element
		PlayerTextDrawLetterSize(playerid, work_trash_panel_p[2][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, work_trash_panel_p[2][playerid], 24.666667, 32.770374);
		PlayerTextDrawAlignment(playerid, work_trash_panel_p[2][playerid], 2);
		PlayerTextDrawColor(playerid, work_trash_panel_p[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, work_trash_panel_p[2][playerid], 0);
		PlayerTextDrawSetOutline(playerid, work_trash_panel_p[2][playerid], 0);
		PlayerTextDrawFont(playerid, work_trash_panel_p[2][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, work_trash_panel_p[2][playerid], true);
	}
	return true;
}

stock create_hospital_npc_p(playerid)
{
	if(hospital_npc_p[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		hospital_npc_p[0][playerid] = CreatePlayerTextDraw(playerid, 232.000030, 385.777801, "CHRISTIAN_BAGWELL"); // Text element
		PlayerTextDrawLetterSize(playerid, hospital_npc_p[0][playerid], 0.241333, 1.317926);
		PlayerTextDrawAlignment(playerid, hospital_npc_p[0][playerid], 2);
		PlayerTextDrawColor(playerid, hospital_npc_p[0][playerid], -1);
		PlayerTextDrawSetShadow(playerid, hospital_npc_p[0][playerid], 0);
		PlayerTextDrawSetOutline(playerid, hospital_npc_p[0][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, hospital_npc_p[0][playerid], 51);
		PlayerTextDrawFont(playerid, hospital_npc_p[0][playerid], 2);
		PlayerTextDrawSetProportional(playerid, hospital_npc_p[0][playerid], 1);
	}
	if(hospital_npc_p[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		hospital_npc_p[1][playerid] = CreatePlayerTextDraw(playerid, 390.333404, 387.022247, "65"); // Text element
		PlayerTextDrawLetterSize(playerid, hospital_npc_p[1][playerid], 0.286333, 1.554370);
		PlayerTextDrawAlignment(playerid, hospital_npc_p[1][playerid], 2);
		PlayerTextDrawColor(playerid, hospital_npc_p[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, hospital_npc_p[1][playerid], 0);
		PlayerTextDrawSetOutline(playerid, hospital_npc_p[1][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, hospital_npc_p[1][playerid], 51);
		PlayerTextDrawFont(playerid, hospital_npc_p[1][playerid], 2);
		PlayerTextDrawSetProportional(playerid, hospital_npc_p[1][playerid], 1);
	}
	if(hospital_npc_p[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		hospital_npc_p[2][playerid] = CreatePlayerTextDraw(playerid, 448.333435, 386.607360, "115"); // Text element
		PlayerTextDrawLetterSize(playerid, hospital_npc_p[2][playerid], 0.267666, 1.616593);
		PlayerTextDrawAlignment(playerid, hospital_npc_p[2][playerid], 2);
		PlayerTextDrawColor(playerid, hospital_npc_p[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, hospital_npc_p[2][playerid], 0);
		PlayerTextDrawSetOutline(playerid, hospital_npc_p[2][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, hospital_npc_p[2][playerid], 51);
		PlayerTextDrawFont(playerid, hospital_npc_p[2][playerid], 2);
		PlayerTextDrawSetProportional(playerid, hospital_npc_p[2][playerid], 1);
	}
	return true;
}

stock create_player_fire_work(playerid)
{
	if(fire_work_panel[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fire_work_panel[0][playerid] = CreatePlayerTextDraw(playerid, 190.666656, 134.814804, "brilliantother:fire_work_gui_3"); // Texture element
		PlayerTextDrawLetterSize(playerid, fire_work_panel[0][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, fire_work_panel[0][playerid], 253.666473, 181.274108);
		PlayerTextDrawAlignment(playerid, fire_work_panel[0][playerid], 2);
		PlayerTextDrawColor(playerid, fire_work_panel[0][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fire_work_panel[0][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fire_work_panel[0][playerid], 0);
		PlayerTextDrawFont(playerid, fire_work_panel[0][playerid], 4);
	}
	if(fire_work_panel[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fire_work_panel[1][playerid] = CreatePlayerTextDraw(playerid, 300.333312, 250.133316, "brilliantother:fire_work_gui_1"); // Texture element
		PlayerTextDrawLetterSize(playerid, fire_work_panel[1][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, fire_work_panel[1][playerid], 126.666656, 41.481479);
		PlayerTextDrawAlignment(playerid, fire_work_panel[1][playerid], 2);
		PlayerTextDrawColor(playerid, fire_work_panel[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fire_work_panel[1][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fire_work_panel[1][playerid], 0);
		PlayerTextDrawFont(playerid, fire_work_panel[1][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, fire_work_panel[1][playerid], true);
	}
	if(fire_work_panel[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fire_work_panel[2][playerid] = CreatePlayerTextDraw(playerid, 414.000061, 136.888900, "brilliantother:close_button_big_2"); // Texture element
		PlayerTextDrawLetterSize(playerid, fire_work_panel[2][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, fire_work_panel[2][playerid], 25.666667, 34.014804);
		PlayerTextDrawAlignment(playerid, fire_work_panel[2][playerid], 2);
		PlayerTextDrawColor(playerid, fire_work_panel[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fire_work_panel[2][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fire_work_panel[2][playerid], 0);
		PlayerTextDrawFont(playerid, fire_work_panel[2][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, fire_work_panel[2][playerid], true);
	}

	return true;
}

stock create_player_green_house(playerid)
{
	if(general_green_house[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[0][playerid] = CreatePlayerTextDraw(playerid, 224.666671, 138.548156, "brilliantother:teplica_info_gen_1"); // Texture element
		PlayerTextDrawLetterSize(playerid, general_green_house[0][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, general_green_house[0][playerid], 277.333312, 181.688842);
		PlayerTextDrawAlignment(playerid, general_green_house[0][playerid], 2);
		PlayerTextDrawColor(playerid, general_green_house[0][playerid], -1);
		PlayerTextDrawSetShadow(playerid, general_green_house[0][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[0][playerid], 0);
		PlayerTextDrawFont(playerid, general_green_house[0][playerid], 4);
	}
	if(general_green_house[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[1][playerid] = CreatePlayerTextDraw(playerid, 432.333404, 141.866699, "brilliantother:teplica_button_water"); // Texture element
		PlayerTextDrawLetterSize(playerid, general_green_house[1][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, general_green_house[1][playerid], 65.999992, 40.237022);
		PlayerTextDrawAlignment(playerid, general_green_house[1][playerid], 2);
		PlayerTextDrawColor(playerid, general_green_house[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, general_green_house[1][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[1][playerid], 0);
		PlayerTextDrawFont(playerid, general_green_house[1][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, general_green_house[1][playerid], true);
	}
	if(general_green_house[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[2][playerid] = CreatePlayerTextDraw(playerid, 361.000000, 142.696319, "brilliantother:teplica_button_semena"); // Texture element
		PlayerTextDrawLetterSize(playerid, general_green_house[2][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, general_green_house[2][playerid], 65.999992, 40.237022);
		PlayerTextDrawAlignment(playerid, general_green_house[2][playerid], 2);
		PlayerTextDrawColor(playerid, general_green_house[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, general_green_house[2][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[2][playerid], 0);
		PlayerTextDrawFont(playerid, general_green_house[2][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, general_green_house[2][playerid], true);
	}
	if(general_green_house[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[3][playerid] = CreatePlayerTextDraw(playerid, 288.000000, 268.799957, "brilliantother:teplica_button_final_2"); // Texture element
		PlayerTextDrawLetterSize(playerid, general_green_house[3][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, general_green_house[3][playerid], 156.666687, 47.703708);
		PlayerTextDrawAlignment(playerid, general_green_house[3][playerid], 2);
		PlayerTextDrawColor(playerid, general_green_house[3][playerid], -1);
		PlayerTextDrawSetShadow(playerid, general_green_house[3][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[3][playerid], 0);
		PlayerTextDrawFont(playerid, general_green_house[3][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, general_green_house[3][playerid], true);
	}
	if(general_green_house[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[4][playerid] = CreatePlayerTextDraw(playerid, 288.333374, 214.044433, "brilliantother:teplica_info_status_back_1"); // Texture element
		PlayerTextDrawLetterSize(playerid, general_green_house[4][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, general_green_house[4][playerid], 74.333328, 36.918533);
		PlayerTextDrawAlignment(playerid, general_green_house[4][playerid], 1);
		PlayerTextDrawColor(playerid, general_green_house[4][playerid], -1);
		PlayerTextDrawSetShadow(playerid, general_green_house[4][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[4][playerid], 0);
		PlayerTextDrawFont(playerid, general_green_house[4][playerid], 4);
	}
	if(general_green_house[5][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[5][playerid] = CreatePlayerTextDraw(playerid, 374.333343, 213.629608, "brilliantother:teplica_info_status_back_2"); // Texture element
		PlayerTextDrawLetterSize(playerid, general_green_house[5][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, general_green_house[5][playerid], 74.333328, 36.918533);
		PlayerTextDrawAlignment(playerid, general_green_house[5][playerid], 1);
		PlayerTextDrawColor(playerid, general_green_house[5][playerid], -1);
		PlayerTextDrawSetShadow(playerid, general_green_house[5][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[5][playerid], 0);
		PlayerTextDrawFont(playerid, general_green_house[5][playerid], 4);
	}
	if(general_green_house[6][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[6][playerid] = CreatePlayerTextDraw(playerid, 290.333343, 228.977783, "brilliantother:teplica_info_status_1"); // Texture element
		PlayerTextDrawLetterSize(playerid, general_green_house[6][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, general_green_house[6][playerid], 20.666633, 19.081474);
		PlayerTextDrawAlignment(playerid, general_green_house[6][playerid], 2);
		PlayerTextDrawColor(playerid, general_green_house[6][playerid], -1);
		PlayerTextDrawSetShadow(playerid, general_green_house[6][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[6][playerid], 0);
		PlayerTextDrawFont(playerid, general_green_house[6][playerid], 4);
	}
	if(general_green_house[7][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[7][playerid] = CreatePlayerTextDraw(playerid, 314.000030, 228.977752, "brilliantother:teplica_info_status_2"); // Texture element
		PlayerTextDrawLetterSize(playerid, general_green_house[7][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, general_green_house[7][playerid], 22.333293, 19.081474);
		PlayerTextDrawAlignment(playerid, general_green_house[7][playerid], 2);
		PlayerTextDrawColor(playerid, general_green_house[7][playerid], -1);
		PlayerTextDrawSetShadow(playerid, general_green_house[7][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[7][playerid], 0);
		PlayerTextDrawFont(playerid, general_green_house[7][playerid], 4);
	}
	if(general_green_house[8][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[8][playerid] = CreatePlayerTextDraw(playerid, 339.333496, 228.977737, "brilliantother:teplica_info_status_3"); // Texture element
		PlayerTextDrawLetterSize(playerid, general_green_house[8][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, general_green_house[8][playerid], 20.666633, 19.081474);
		PlayerTextDrawAlignment(playerid, general_green_house[8][playerid], 2);
		PlayerTextDrawColor(playerid, general_green_house[8][playerid], -1);
		PlayerTextDrawSetShadow(playerid, general_green_house[8][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[8][playerid], 0);
		PlayerTextDrawFont(playerid, general_green_house[8][playerid], 4);
	}
	if(general_green_house[9][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[9][playerid] = CreatePlayerTextDraw(playerid, 376.333312, 228.562973, "brilliantother:teplica_info_status_1"); // Texture element
		PlayerTextDrawLetterSize(playerid, general_green_house[9][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, general_green_house[9][playerid], 20.666633, 19.081474);
		PlayerTextDrawAlignment(playerid, general_green_house[9][playerid], 2);
		PlayerTextDrawColor(playerid, general_green_house[9][playerid], -1);
		PlayerTextDrawSetShadow(playerid, general_green_house[9][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[9][playerid], 0);
		PlayerTextDrawFont(playerid, general_green_house[9][playerid], 4);
	}
	if(general_green_house[10][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[10][playerid] = CreatePlayerTextDraw(playerid, 399.666778, 228.562942, "brilliantother:teplica_info_status_2"); // Texture element
		PlayerTextDrawLetterSize(playerid, general_green_house[10][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, general_green_house[10][playerid], 22.333293, 19.081474);
		PlayerTextDrawAlignment(playerid, general_green_house[10][playerid], 2);
		PlayerTextDrawColor(playerid, general_green_house[10][playerid], -1);
		PlayerTextDrawSetShadow(playerid, general_green_house[10][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[10][playerid], 0);
		PlayerTextDrawFont(playerid, general_green_house[10][playerid], 4);
	}
	if(general_green_house[11][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[11][playerid] = CreatePlayerTextDraw(playerid, 424.333496, 228.562942, "brilliantother:teplica_info_status_3"); // Texture element
		PlayerTextDrawLetterSize(playerid, general_green_house[11][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, general_green_house[11][playerid], 20.666633, 19.081474);
		PlayerTextDrawAlignment(playerid, general_green_house[11][playerid], 2);
		PlayerTextDrawColor(playerid, general_green_house[11][playerid], -1);
		PlayerTextDrawSetShadow(playerid, general_green_house[11][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[11][playerid], 0);
		PlayerTextDrawFont(playerid, general_green_house[11][playerid], 4);
	}
	if(general_green_house[12][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[12][playerid] = CreatePlayerTextDraw(playerid, 76.333358, 138.548171, "brilliantother:teplica_info_icon_1"); // Texture element
		PlayerTextDrawLetterSize(playerid, general_green_house[12][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, general_green_house[12][playerid], 31.333345, 39.407402);
		PlayerTextDrawAlignment(playerid, general_green_house[12][playerid], 1);
		PlayerTextDrawColor(playerid, general_green_house[12][playerid], -1);
		PlayerTextDrawSetShadow(playerid, general_green_house[12][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[12][playerid], 0);
		PlayerTextDrawFont(playerid, general_green_house[12][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, general_green_house[12][playerid], true);
	}
	if(general_green_house[13][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[13][playerid] = CreatePlayerTextDraw(playerid, 114.999992, 138.133285, "brilliantother:teplica_info_icon_2"); // Texture element
		PlayerTextDrawLetterSize(playerid, general_green_house[13][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, general_green_house[13][playerid], 31.333345, 39.407402);
		PlayerTextDrawAlignment(playerid, general_green_house[13][playerid], 2);
		PlayerTextDrawColor(playerid, general_green_house[13][playerid], -1);
		PlayerTextDrawSetShadow(playerid, general_green_house[13][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[13][playerid], 0);
		PlayerTextDrawFont(playerid, general_green_house[13][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, general_green_house[13][playerid], true);
	}
	if(general_green_house[14][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[14][playerid] = CreatePlayerTextDraw(playerid, 77.000000, 182.933349, "brilliantother:teplica_info_icon_3"); // Texture element
		PlayerTextDrawLetterSize(playerid, general_green_house[14][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, general_green_house[14][playerid], 31.333345, 39.407402);
		PlayerTextDrawAlignment(playerid, general_green_house[14][playerid], 2);
		PlayerTextDrawColor(playerid, general_green_house[14][playerid], -1);
		PlayerTextDrawSetShadow(playerid, general_green_house[14][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[14][playerid], 0);
		PlayerTextDrawFont(playerid, general_green_house[14][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, general_green_house[14][playerid], true);
	}
	if(general_green_house[15][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[15][playerid] = CreatePlayerTextDraw(playerid, 114.999977, 183.762969, "brilliantother:teplica_info_icon_4"); // Texture element
		PlayerTextDrawLetterSize(playerid, general_green_house[15][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, general_green_house[15][playerid], 31.333345, 39.407402);
		PlayerTextDrawAlignment(playerid, general_green_house[15][playerid], 2);
		PlayerTextDrawColor(playerid, general_green_house[15][playerid], -1);
		PlayerTextDrawSetShadow(playerid, general_green_house[15][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[15][playerid], 0);
		PlayerTextDrawFont(playerid, general_green_house[15][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, general_green_house[15][playerid], true);
	}
	if(general_green_house[16][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[16][playerid] = CreatePlayerTextDraw(playerid, 77.999954, 228.148178, "brilliantother:teplica_info_icon_5"); // Texture element
		PlayerTextDrawLetterSize(playerid, general_green_house[16][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, general_green_house[16][playerid], 31.333345, 39.407402);
		PlayerTextDrawAlignment(playerid, general_green_house[16][playerid], 2);
		PlayerTextDrawColor(playerid, general_green_house[16][playerid], -1);
		PlayerTextDrawSetShadow(playerid, general_green_house[16][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[16][playerid], 0);
		PlayerTextDrawFont(playerid, general_green_house[16][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, general_green_house[16][playerid], true);
	}
	if(general_green_house[17][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[17][playerid] = CreatePlayerTextDraw(playerid, 116.333274, 228.148178, "brilliantother:teplica_info_icon_6"); // Texture element
		PlayerTextDrawLetterSize(playerid, general_green_house[17][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, general_green_house[17][playerid], 31.333345, 39.407402);
		PlayerTextDrawAlignment(playerid, general_green_house[17][playerid], 2);
		PlayerTextDrawColor(playerid, general_green_house[17][playerid], -1);
		PlayerTextDrawSetShadow(playerid, general_green_house[17][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[17][playerid], 0);
		PlayerTextDrawFont(playerid, general_green_house[17][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, general_green_house[17][playerid], true);
	}
	if(general_green_house[18][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[18][playerid] = CreatePlayerTextDraw(playerid, 77.333290, 273.362976, "brilliantother:teplica_info_icon_7"); // Texture element
		PlayerTextDrawLetterSize(playerid, general_green_house[18][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, general_green_house[18][playerid], 31.333345, 39.407402);
		PlayerTextDrawAlignment(playerid, general_green_house[18][playerid], 2);
		PlayerTextDrawColor(playerid, general_green_house[18][playerid], -1);
		PlayerTextDrawSetShadow(playerid, general_green_house[18][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[18][playerid], 0);
		PlayerTextDrawFont(playerid, general_green_house[18][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, general_green_house[18][playerid], true);
	}
	if(general_green_house[19][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[19][playerid] = CreatePlayerTextDraw(playerid, 116.999938, 272.948211, "brilliantother:teplica_info_icon_8"); // Texture element
		PlayerTextDrawLetterSize(playerid, general_green_house[19][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, general_green_house[19][playerid], 31.333345, 39.407402);
		PlayerTextDrawAlignment(playerid, general_green_house[19][playerid], 2);
		PlayerTextDrawColor(playerid, general_green_house[19][playerid], -1);
		PlayerTextDrawSetShadow(playerid, general_green_house[19][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[19][playerid], 0);
		PlayerTextDrawFont(playerid, general_green_house[19][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, general_green_house[19][playerid], true);
	}
	if(general_green_house[20][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[20][playerid] = CreatePlayerTextDraw(playerid, 75.000015, 90.014816, "brilliantother:teplica_info_gui_2"); // Texture element
		PlayerTextDrawLetterSize(playerid, general_green_house[20][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, general_green_house[20][playerid], 71.333335, 43.140731);
		PlayerTextDrawAlignment(playerid, general_green_house[20][playerid], 1);
		PlayerTextDrawColor(playerid, general_green_house[20][playerid], -1);
		PlayerTextDrawSetShadow(playerid, general_green_house[20][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[20][playerid], 0);
		PlayerTextDrawFont(playerid, general_green_house[20][playerid], 4);
	}
	if(general_green_house[21][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[21][playerid] = CreatePlayerTextDraw(playerid, 154.333343, 89.185165, "brilliantother:teplica_info_gui_3"); // Texture element
		PlayerTextDrawLetterSize(playerid, general_green_house[21][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, general_green_house[21][playerid], 71.333351, 42.311111);
		PlayerTextDrawAlignment(playerid, general_green_house[21][playerid], 1);
		PlayerTextDrawColor(playerid, general_green_house[21][playerid], -1);
		PlayerTextDrawSetShadow(playerid, general_green_house[21][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[21][playerid], 0);
		PlayerTextDrawFont(playerid, general_green_house[21][playerid], 4);
	}
	if(general_green_house[22][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[22][playerid] = CreatePlayerTextDraw(playerid, 233.000045, 89.185142, "brilliantother:teplica_info_gui_7"); // Texture element
		PlayerTextDrawLetterSize(playerid, general_green_house[22][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, general_green_house[22][playerid], 129.333343, 41.896293);
		PlayerTextDrawAlignment(playerid, general_green_house[22][playerid], 1);
		PlayerTextDrawColor(playerid, general_green_house[22][playerid], -1);
		PlayerTextDrawSetShadow(playerid, general_green_house[22][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[22][playerid], 0);
		PlayerTextDrawFont(playerid, general_green_house[22][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, general_green_house[22][playerid], true);
	}
	if(general_green_house[23][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[23][playerid] = CreatePlayerTextDraw(playerid, 370.666748, 88.355522, "brilliantother:teplica_button_final"); // Texture element
		PlayerTextDrawLetterSize(playerid, general_green_house[23][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, general_green_house[23][playerid], 131.999984, 41.896297);
		PlayerTextDrawAlignment(playerid, general_green_house[23][playerid], 1);
		PlayerTextDrawColor(playerid, general_green_house[23][playerid], -1);
		PlayerTextDrawSetShadow(playerid, general_green_house[23][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[23][playerid], 0);
		PlayerTextDrawFont(playerid, general_green_house[23][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, general_green_house[23][playerid], true);
	}
	if(general_green_house[24][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[24][playerid] = CreatePlayerTextDraw(playerid, 109.333320, 109.096244, "50"); // Text element
		PlayerTextDrawLetterSize(playerid, general_green_house[24][playerid], 0.296665, 1.799111);
		PlayerTextDrawAlignment(playerid, general_green_house[24][playerid], 2);
		PlayerTextDrawColor(playerid, general_green_house[24][playerid], -1);
		PlayerTextDrawUseBox(playerid, general_green_house[24][playerid], true);
		PlayerTextDrawBoxColor(playerid, general_green_house[24][playerid], 0);
		PlayerTextDrawSetShadow(playerid, general_green_house[24][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[24][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, general_green_house[24][playerid], 51);
		PlayerTextDrawFont(playerid, general_green_house[24][playerid], 2);
		PlayerTextDrawSetProportional(playerid, general_green_house[24][playerid], 1);
	}
	if(general_green_house[25][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[25][playerid] = CreatePlayerTextDraw(playerid, 188.666656, 107.851791, "35"); // Text element
		PlayerTextDrawLetterSize(playerid, general_green_house[25][playerid], 0.296665, 1.799111);
		PlayerTextDrawAlignment(playerid, general_green_house[25][playerid], 2);
		PlayerTextDrawColor(playerid, general_green_house[25][playerid], -1);
		PlayerTextDrawUseBox(playerid, general_green_house[25][playerid], true);
		PlayerTextDrawBoxColor(playerid, general_green_house[25][playerid], 0);
		PlayerTextDrawSetShadow(playerid, general_green_house[25][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[25][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, general_green_house[25][playerid], 51);
		PlayerTextDrawFont(playerid, general_green_house[25][playerid], 2);
		PlayerTextDrawSetProportional(playerid, general_green_house[25][playerid], 1);
	}
	if(general_green_house[26][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[26][playerid] = CreatePlayerTextDraw(playerid, 503.666595, 80.474067, "brilliantother:close_button_big"); // Texture element
		PlayerTextDrawLetterSize(playerid, general_green_house[26][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, general_green_house[26][playerid], 50.333335, 59.733310);
		PlayerTextDrawAlignment(playerid, general_green_house[26][playerid], 1);
		PlayerTextDrawColor(playerid, general_green_house[26][playerid], -1);
		PlayerTextDrawSetShadow(playerid, general_green_house[26][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[26][playerid], 0);
		PlayerTextDrawFont(playerid, general_green_house[26][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, general_green_house[26][playerid], true);
	}
	if(general_green_house[27][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[27][playerid] = CreatePlayerTextDraw(playerid, 262.000000, 174.636978, "10"); // Text element
		PlayerTextDrawLetterSize(playerid, general_green_house[27][playerid], 0.296665, 1.799111);
		PlayerTextDrawAlignment(playerid, general_green_house[27][playerid], 2);
		PlayerTextDrawColor(playerid, general_green_house[27][playerid], -1);
		PlayerTextDrawUseBox(playerid, general_green_house[27][playerid], true);
		PlayerTextDrawBoxColor(playerid, general_green_house[27][playerid], 0);
		PlayerTextDrawSetShadow(playerid, general_green_house[27][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[27][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, general_green_house[27][playerid], 51);
		PlayerTextDrawFont(playerid, general_green_house[27][playerid], 2);
		PlayerTextDrawSetProportional(playerid, general_green_house[27][playerid], 1);	
	}
	return true;
}

stock create_player_green_house_2(playerid)
{
	if(general_green_house[6][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[6][playerid] = CreatePlayerTextDraw(playerid, 290.333343, 228.977783, "brilliantother:teplica_info_status_1"); // Texture element
		PlayerTextDrawLetterSize(playerid, general_green_house[6][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, general_green_house[6][playerid], 20.666633, 19.081474);
		PlayerTextDrawAlignment(playerid, general_green_house[6][playerid], 2);
		PlayerTextDrawColor(playerid, general_green_house[6][playerid], -1);
		PlayerTextDrawSetShadow(playerid, general_green_house[6][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[6][playerid], 0);
		PlayerTextDrawFont(playerid, general_green_house[6][playerid], 4);
	}
	if(general_green_house[7][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[7][playerid] = CreatePlayerTextDraw(playerid, 314.000030, 228.977752, "brilliantother:teplica_info_status_2"); // Texture element
		PlayerTextDrawLetterSize(playerid, general_green_house[7][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, general_green_house[7][playerid], 22.333293, 19.081474);
		PlayerTextDrawAlignment(playerid, general_green_house[7][playerid], 2);
		PlayerTextDrawColor(playerid, general_green_house[7][playerid], -1);
		PlayerTextDrawSetShadow(playerid, general_green_house[7][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[7][playerid], 0);
		PlayerTextDrawFont(playerid, general_green_house[7][playerid], 4);
	}
	if(general_green_house[8][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[8][playerid] = CreatePlayerTextDraw(playerid, 339.333496, 228.977737, "brilliantother:teplica_info_status_3"); // Texture element
		PlayerTextDrawLetterSize(playerid, general_green_house[8][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, general_green_house[8][playerid], 20.666633, 19.081474);
		PlayerTextDrawAlignment(playerid, general_green_house[8][playerid], 2);
		PlayerTextDrawColor(playerid, general_green_house[8][playerid], -1);
		PlayerTextDrawSetShadow(playerid, general_green_house[8][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[8][playerid], 0);
		PlayerTextDrawFont(playerid, general_green_house[8][playerid], 4);
	}
	if(general_green_house[9][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[9][playerid] = CreatePlayerTextDraw(playerid, 376.333312, 228.562973, "brilliantother:teplica_info_status_1"); // Texture element
		PlayerTextDrawLetterSize(playerid, general_green_house[9][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, general_green_house[9][playerid], 20.666633, 19.081474);
		PlayerTextDrawAlignment(playerid, general_green_house[9][playerid], 2);
		PlayerTextDrawColor(playerid, general_green_house[9][playerid], -1);
		PlayerTextDrawSetShadow(playerid, general_green_house[9][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[9][playerid], 0);
		PlayerTextDrawFont(playerid, general_green_house[9][playerid], 4);
	}
	if(general_green_house[10][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[10][playerid] = CreatePlayerTextDraw(playerid, 399.666778, 228.562942, "brilliantother:teplica_info_status_2"); // Texture element
		PlayerTextDrawLetterSize(playerid, general_green_house[10][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, general_green_house[10][playerid], 22.333293, 19.081474);
		PlayerTextDrawAlignment(playerid, general_green_house[10][playerid], 2);
		PlayerTextDrawColor(playerid, general_green_house[10][playerid], -1);
		PlayerTextDrawSetShadow(playerid, general_green_house[10][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[10][playerid], 0);
		PlayerTextDrawFont(playerid, general_green_house[10][playerid], 4);
	}
	if(general_green_house[11][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[11][playerid] = CreatePlayerTextDraw(playerid, 424.333496, 228.562942, "brilliantother:teplica_info_status_3"); // Texture element
		PlayerTextDrawLetterSize(playerid, general_green_house[11][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, general_green_house[11][playerid], 20.666633, 19.081474);
		PlayerTextDrawAlignment(playerid, general_green_house[11][playerid], 2);
		PlayerTextDrawColor(playerid, general_green_house[11][playerid], -1);
		PlayerTextDrawSetShadow(playerid, general_green_house[11][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[11][playerid], 0);
		PlayerTextDrawFont(playerid, general_green_house[11][playerid], 4);
	}
	if(general_green_house[24][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[24][playerid] = CreatePlayerTextDraw(playerid, 109.333320, 109.096244, "50"); // Text element
		PlayerTextDrawLetterSize(playerid, general_green_house[24][playerid], 0.296665, 1.799111);
		PlayerTextDrawAlignment(playerid, general_green_house[24][playerid], 2);
		PlayerTextDrawColor(playerid, general_green_house[24][playerid], -1);
		PlayerTextDrawUseBox(playerid, general_green_house[24][playerid], true);
		PlayerTextDrawBoxColor(playerid, general_green_house[24][playerid], 0);
		PlayerTextDrawSetShadow(playerid, general_green_house[24][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[24][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, general_green_house[24][playerid], 51);
		PlayerTextDrawFont(playerid, general_green_house[24][playerid], 2);
		PlayerTextDrawSetProportional(playerid, general_green_house[24][playerid], 1);
	}
	if(general_green_house[27][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		general_green_house[27][playerid] = CreatePlayerTextDraw(playerid, 262.000000, 174.636978, "10"); // Text element
		PlayerTextDrawLetterSize(playerid, general_green_house[27][playerid], 0.296665, 1.799111);
		PlayerTextDrawAlignment(playerid, general_green_house[27][playerid], 2);
		PlayerTextDrawColor(playerid, general_green_house[27][playerid], -1);
		PlayerTextDrawUseBox(playerid, general_green_house[27][playerid], true);
		PlayerTextDrawBoxColor(playerid, general_green_house[27][playerid], 0);
		PlayerTextDrawSetShadow(playerid, general_green_house[27][playerid], 0);
		PlayerTextDrawSetOutline(playerid, general_green_house[27][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, general_green_house[27][playerid], 51);
		PlayerTextDrawFont(playerid, general_green_house[27][playerid], 2);
		PlayerTextDrawSetProportional(playerid, general_green_house[27][playerid], 1);	
	}
	return true;
}


stock create_player_fire_panel(playerid)
{
	if(fire_panel[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fire_panel[0][playerid] = CreatePlayerTextDraw(playerid, 54.333305, 228.562911, "0"); // Text element
		PlayerTextDrawLetterSize(playerid, fire_panel[0][playerid], 0.219999, 1.421630);
		PlayerTextDrawAlignment(playerid, fire_panel[0][playerid], 2);
		PlayerTextDrawColor(playerid, fire_panel[0][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fire_panel[0][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fire_panel[0][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, fire_panel[0][playerid], 51);
		PlayerTextDrawFont(playerid, fire_panel[0][playerid], 2);
		PlayerTextDrawSetProportional(playerid, fire_panel[0][playerid], 1);
	}
	if(fire_panel[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fire_panel[1][playerid] = CreatePlayerTextDraw(playerid, 63.999996, 259.673980, "0_RUB"); // Text element
		PlayerTextDrawLetterSize(playerid, fire_panel[1][playerid], 0.185000, 1.342815);
		PlayerTextDrawAlignment(playerid, fire_panel[1][playerid], 2);
		PlayerTextDrawColor(playerid, fire_panel[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fire_panel[1][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fire_panel[1][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, fire_panel[1][playerid], 51);
		PlayerTextDrawFont(playerid, fire_panel[1][playerid], 2);
		PlayerTextDrawSetProportional(playerid, fire_panel[1][playerid], 1);
	}
	if(fire_panel[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		fire_panel[2][playerid] = CreatePlayerTextDraw(playerid, 54.333335, 288.710906, "100%"); // Text element
		PlayerTextDrawLetterSize(playerid, fire_panel[2][playerid], 0.185000, 1.342815);
		PlayerTextDrawAlignment(playerid, fire_panel[2][playerid], 2);
		PlayerTextDrawColor(playerid, fire_panel[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, fire_panel[2][playerid], 0);
		PlayerTextDrawSetOutline(playerid, fire_panel[2][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, fire_panel[2][playerid], 51);
		PlayerTextDrawFont(playerid, fire_panel[2][playerid], 2);
		PlayerTextDrawSetProportional(playerid, fire_panel[2][playerid], 1);
	}
	return true;
}

stock create_player_inventory(playerid)
{
	if(inventory_gui_p[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[0][playerid] = CreatePlayerTextDraw(playerid, 93.999992, 124.837142, "brillinv:inventory_slot");
		PlayerTextDrawTextSize(playerid, inventory_gui_p[0][playerid], 38.000000, 53.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[0][playerid], 1);
		PlayerTextDrawColor(playerid, inventory_gui_p[0][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[0][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[0][playerid], 4);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[0][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, inventory_gui_p[0][playerid], true);
	}
	if(inventory_gui_p[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[1][playerid] = CreatePlayerTextDraw(playerid, 142.000015, 124.837142, "brillinv:inventory_slot");
		PlayerTextDrawTextSize(playerid, inventory_gui_p[1][playerid], 38.000000, 53.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[1][playerid], 1);
		PlayerTextDrawColor(playerid, inventory_gui_p[1][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[1][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[1][playerid], 4);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[1][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, inventory_gui_p[1][playerid], true);
	}
	if(inventory_gui_p[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[2][playerid] = CreatePlayerTextDraw(playerid, 190.000015, 124.837142, "brillinv:inventory_slot");
		PlayerTextDrawTextSize(playerid, inventory_gui_p[2][playerid], 38.000000, 53.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[2][playerid], 1);
		PlayerTextDrawColor(playerid, inventory_gui_p[2][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[2][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[2][playerid], 4);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[2][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, inventory_gui_p[2][playerid], true);
	}
	if(inventory_gui_p[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[3][playerid] = CreatePlayerTextDraw(playerid, 238.000015, 124.837142, "brillinv:inventory_slot");
		PlayerTextDrawTextSize(playerid, inventory_gui_p[3][playerid], 38.000000, 53.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[3][playerid], 1);
		PlayerTextDrawColor(playerid, inventory_gui_p[3][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[3][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[3][playerid], 4);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[3][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, inventory_gui_p[3][playerid], true);
	}
	if(inventory_gui_p[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[4][playerid] = CreatePlayerTextDraw(playerid, 285.999969, 124.837142, "brillinv:inventory_slot");
		PlayerTextDrawTextSize(playerid, inventory_gui_p[4][playerid], 38.000000, 53.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[4][playerid], 1);
		PlayerTextDrawColor(playerid, inventory_gui_p[4][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[4][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[4][playerid], 4);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[4][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, inventory_gui_p[4][playerid], true);
	}
	if(inventory_gui_p[5][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[5][playerid] = CreatePlayerTextDraw(playerid, 333.999969, 124.837142, "brillinv:inventory_slot");
		PlayerTextDrawTextSize(playerid, inventory_gui_p[5][playerid], 38.000000, 53.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[5][playerid], 1);
		PlayerTextDrawColor(playerid, inventory_gui_p[5][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[5][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[5][playerid], 4);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[5][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, inventory_gui_p[5][playerid], true);
	}
	if(inventory_gui_p[6][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[6][playerid] = CreatePlayerTextDraw(playerid, 93.999992, 195.836883, "brillinv:inventory_slot");
		PlayerTextDrawTextSize(playerid, inventory_gui_p[6][playerid], 38.000000, 53.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[6][playerid], 1);
		PlayerTextDrawColor(playerid, inventory_gui_p[6][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[6][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[6][playerid], 4);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[6][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, inventory_gui_p[6][playerid], true);
	}
	if(inventory_gui_p[7][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[7][playerid] = CreatePlayerTextDraw(playerid, 142.000015, 195.836883, "brillinv:inventory_slot");
		PlayerTextDrawTextSize(playerid, inventory_gui_p[7][playerid], 38.000000, 53.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[7][playerid], 1);
		PlayerTextDrawColor(playerid, inventory_gui_p[7][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[7][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[7][playerid], 4);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[7][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, inventory_gui_p[7][playerid], true);
	}
	if(inventory_gui_p[8][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[8][playerid] = CreatePlayerTextDraw(playerid, 190.000015, 195.836883, "brillinv:inventory_slot");
		PlayerTextDrawTextSize(playerid, inventory_gui_p[8][playerid], 38.000000, 53.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[8][playerid], 1);
		PlayerTextDrawColor(playerid, inventory_gui_p[8][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[8][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[8][playerid], 4);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[8][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, inventory_gui_p[8][playerid], true);
	}
	if(inventory_gui_p[9][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[9][playerid] = CreatePlayerTextDraw(playerid, 238.000015, 195.836883, "brillinv:inventory_slot");
		PlayerTextDrawTextSize(playerid, inventory_gui_p[9][playerid], 38.000000, 53.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[9][playerid], 1);
		PlayerTextDrawColor(playerid, inventory_gui_p[9][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[9][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[9][playerid], 4);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[9][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, inventory_gui_p[9][playerid], true);
	}
	if(inventory_gui_p[10][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[10][playerid] = CreatePlayerTextDraw(playerid, 285.999969, 195.836883, "brillinv:inventory_slot");
		PlayerTextDrawTextSize(playerid, inventory_gui_p[10][playerid], 38.000000, 53.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[10][playerid], 1);
		PlayerTextDrawColor(playerid, inventory_gui_p[10][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[10][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[10][playerid], 4);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[10][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, inventory_gui_p[10][playerid], true);
	}
	if(inventory_gui_p[11][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[11][playerid] = CreatePlayerTextDraw(playerid, 333.999969, 195.836883, "brillinv:inventory_slot");
		PlayerTextDrawTextSize(playerid, inventory_gui_p[11][playerid], 38.000000, 53.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[11][playerid], 1);
		PlayerTextDrawColor(playerid, inventory_gui_p[11][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[11][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[11][playerid], 4);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[11][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, inventory_gui_p[11][playerid], true);
	}
	if(inventory_gui_p[12][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[12][playerid] = CreatePlayerTextDraw(playerid, 93.999992, 267.837219, "brillinv:inventory_slot");
		PlayerTextDrawTextSize(playerid, inventory_gui_p[12][playerid], 38.000000, 53.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[12][playerid], 1);
		PlayerTextDrawColor(playerid, inventory_gui_p[12][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[12][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[12][playerid], 4);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[12][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, inventory_gui_p[12][playerid], true);
	}
	if(inventory_gui_p[13][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[13][playerid] = CreatePlayerTextDraw(playerid, 142.000015, 267.837219, "brillinv:inventory_slot");
		PlayerTextDrawTextSize(playerid, inventory_gui_p[13][playerid], 38.000000, 53.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[13][playerid], 1);
		PlayerTextDrawColor(playerid, inventory_gui_p[13][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[13][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[13][playerid], 4);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[13][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, inventory_gui_p[13][playerid], true);
	}
	if(inventory_gui_p[14][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[14][playerid] = CreatePlayerTextDraw(playerid, 190.000015, 267.837219, "brillinv:inventory_slot");
		PlayerTextDrawTextSize(playerid, inventory_gui_p[14][playerid], 38.000000, 53.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[14][playerid], 1);
		PlayerTextDrawColor(playerid, inventory_gui_p[14][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[14][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[14][playerid], 4);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[14][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, inventory_gui_p[14][playerid], true);
	}
	if(inventory_gui_p[15][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[15][playerid] = CreatePlayerTextDraw(playerid, 238.000015, 267.837219, "brillinv:inventory_slot");
		PlayerTextDrawTextSize(playerid, inventory_gui_p[15][playerid], 38.000000, 53.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[15][playerid], 1);
		PlayerTextDrawColor(playerid, inventory_gui_p[15][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[15][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[15][playerid], 4);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[15][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, inventory_gui_p[15][playerid], true);
	}
	if(inventory_gui_p[16][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[16][playerid] = CreatePlayerTextDraw(playerid, 285.999969, 267.837219, "brillinv:inventory_slot");
		PlayerTextDrawTextSize(playerid, inventory_gui_p[16][playerid], 38.000000, 53.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[16][playerid], 1);
		PlayerTextDrawColor(playerid, inventory_gui_p[16][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[16][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[16][playerid], 4);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[16][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, inventory_gui_p[16][playerid], true);
	}
	if(inventory_gui_p[17][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[17][playerid] = CreatePlayerTextDraw(playerid, 333.999969, 267.837219, "brillinv:inventory_slot");
		PlayerTextDrawTextSize(playerid, inventory_gui_p[17][playerid], 38.000000, 53.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[17][playerid], 1);
		PlayerTextDrawColor(playerid, inventory_gui_p[17][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[17][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[17][playerid], 4);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[17][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, inventory_gui_p[17][playerid], true);
	}
	if(inventory_gui_p[18][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[18][playerid] = CreatePlayerTextDraw(playerid, 93.999992, 337.837402, "brillinv:inventory_slot");
		PlayerTextDrawTextSize(playerid, inventory_gui_p[18][playerid], 38.000000, 53.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[18][playerid], 1);
		PlayerTextDrawColor(playerid, inventory_gui_p[18][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[18][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[18][playerid], 4);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[18][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, inventory_gui_p[18][playerid], true);
	}
	if(inventory_gui_p[19][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[19][playerid] = CreatePlayerTextDraw(playerid, 142.000015, 337.837402, "brillinv:inventory_slot");
		PlayerTextDrawTextSize(playerid, inventory_gui_p[19][playerid], 38.000000, 53.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[19][playerid], 1);
		PlayerTextDrawColor(playerid, inventory_gui_p[19][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[19][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[19][playerid], 4);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[19][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, inventory_gui_p[19][playerid], true);
	}
	if(inventory_gui_p[20][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[20][playerid] = CreatePlayerTextDraw(playerid, 190.000015, 337.837402, "brillinv:inventory_slot");
		PlayerTextDrawTextSize(playerid, inventory_gui_p[20][playerid], 38.000000, 53.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[20][playerid], 1);
		PlayerTextDrawColor(playerid, inventory_gui_p[20][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[20][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[20][playerid], 4);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[20][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, inventory_gui_p[20][playerid], true);
	}
	if(inventory_gui_p[21][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[21][playerid] = CreatePlayerTextDraw(playerid, 238.000015, 337.837402, "brillinv:inventory_slot");
		PlayerTextDrawTextSize(playerid, inventory_gui_p[21][playerid], 38.000000, 53.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[21][playerid], 1);
		PlayerTextDrawColor(playerid, inventory_gui_p[21][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[21][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[21][playerid], 4);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[21][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, inventory_gui_p[21][playerid], true);
	}
	if(inventory_gui_p[22][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[22][playerid] = CreatePlayerTextDraw(playerid, 285.999969, 337.837402, "brillinv:inventory_slot");
		PlayerTextDrawTextSize(playerid, inventory_gui_p[22][playerid], 38.000000, 53.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[22][playerid], 1);
		PlayerTextDrawColor(playerid, inventory_gui_p[22][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[22][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[22][playerid], 4);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[22][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, inventory_gui_p[22][playerid], true);
	}
	if(inventory_gui_p[23][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[23][playerid] = CreatePlayerTextDraw(playerid, 333.999969, 337.837402, "brillinv:inventory_slot");
		PlayerTextDrawTextSize(playerid, inventory_gui_p[23][playerid], 38.000000, 53.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[23][playerid], 1);
		PlayerTextDrawColor(playerid, inventory_gui_p[23][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[23][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[23][playerid], 4);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[23][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, inventory_gui_p[23][playerid], true);
	}
	if(inventory_gui_p[24][playerid] == PlayerText:INVALID_TEXT_DRAW) 
	{
		inventory_gui_p[24][playerid] = CreatePlayerTextDraw(playerid, 455.999908, 82.585281, "brillinv:inventory_head_slot");
		PlayerTextDrawTextSize(playerid, inventory_gui_p[24][playerid], 38.000000, 53.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[24][playerid], 1);
		PlayerTextDrawColor(playerid, inventory_gui_p[24][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[24][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[24][playerid], 4);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[24][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, inventory_gui_p[24][playerid], true);
	}
	if(inventory_gui_p[25][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[25][playerid] = CreatePlayerTextDraw(playerid, 388.999908, 134.585021, "brillinv:inventory_glasses_slot");
		PlayerTextDrawTextSize(playerid, inventory_gui_p[25][playerid], 38.000000, 53.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[25][playerid], 1);
		PlayerTextDrawColor(playerid, inventory_gui_p[25][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[25][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[25][playerid], 4);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[25][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, inventory_gui_p[25][playerid], true);
	}
	if(inventory_gui_p[26][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[26][playerid] = CreatePlayerTextDraw(playerid, 388.999908, 195.585021, "brillinv:inventory_mask_slot");
		PlayerTextDrawTextSize(playerid, inventory_gui_p[26][playerid], 38.000000, 53.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[26][playerid], 1);
		PlayerTextDrawColor(playerid, inventory_gui_p[26][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[26][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[26][playerid], 4);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[26][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, inventory_gui_p[26][playerid], true);
	}
	if(inventory_gui_p[27][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[27][playerid] = CreatePlayerTextDraw(playerid, 388.999908, 255.585479, "brillinv:inventory_belt_slot");
		PlayerTextDrawTextSize(playerid, inventory_gui_p[27][playerid], 38.000000, 53.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[27][playerid], 1);
		PlayerTextDrawColor(playerid, inventory_gui_p[27][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[27][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[27][playerid], 4);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[27][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, inventory_gui_p[27][playerid], true);
	}
	if(inventory_gui_p[28][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[28][playerid] = CreatePlayerTextDraw(playerid, 434.999908, 310.585510, "brillinv:inventory_feet_slot");
		PlayerTextDrawTextSize(playerid, inventory_gui_p[28][playerid], 38.000000, 53.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[28][playerid], 1);
		PlayerTextDrawColor(playerid, inventory_gui_p[28][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[28][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[28][playerid], 4);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[28][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, inventory_gui_p[28][playerid], true);
	}
	if(inventory_gui_p[29][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[29][playerid] = CreatePlayerTextDraw(playerid, 477.999908, 310.585510, "brillinv:inventory_hand_slot");
		PlayerTextDrawTextSize(playerid, inventory_gui_p[29][playerid], 38.000000, 53.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[29][playerid], 1);
		PlayerTextDrawColor(playerid, inventory_gui_p[29][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[29][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[29][playerid], 4);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[29][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, inventory_gui_p[29][playerid], true);
	}
	if(inventory_gui_p[30][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[30][playerid] = CreatePlayerTextDraw(playerid, 525.000183, 255.585479, "brillinv:inventory_legs_slot");
		PlayerTextDrawTextSize(playerid, inventory_gui_p[30][playerid], 38.000000, 53.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[30][playerid], 1);
		PlayerTextDrawColor(playerid, inventory_gui_p[30][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[30][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[30][playerid], 4);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[30][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, inventory_gui_p[30][playerid], true);
	}
	if(inventory_gui_p[31][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[31][playerid] = CreatePlayerTextDraw(playerid, 525.000183, 195.585021, "brillinv:inventory_back_slot");
		PlayerTextDrawTextSize(playerid, inventory_gui_p[31][playerid], 38.000000, 53.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[31][playerid], 1);
		PlayerTextDrawColor(playerid, inventory_gui_p[31][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[31][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[31][playerid], 4);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[31][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, inventory_gui_p[31][playerid], true);
	}
	if(inventory_gui_p[32][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[32][playerid] = CreatePlayerTextDraw(playerid, 525.000183, 134.585021, "brillinv:inventory_chest_slot");
		PlayerTextDrawTextSize(playerid, inventory_gui_p[32][playerid], 38.000000, 53.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[32][playerid], 1);
		PlayerTextDrawColor(playerid, inventory_gui_p[32][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[32][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[32][playerid], 4);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[32][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, inventory_gui_p[32][playerid], true);
	}
	if(inventory_gui_p[33][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[33][playerid] = CreatePlayerTextDraw(playerid, 67.666671, 250.155532, "3/4");
		PlayerTextDrawLetterSize(playerid, inventory_gui_p[33][playerid], 0.484333, 2.110219);
		PlayerTextDrawTextSize(playerid, inventory_gui_p[33][playerid], 0.000000, 32.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[33][playerid], 2);
		PlayerTextDrawColor(playerid, inventory_gui_p[33][playerid], -1);
		PlayerTextDrawSetShadow(playerid, inventory_gui_p[33][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[33][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[33][playerid], 1);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[33][playerid], 1);
	}
	if(inventory_gui_p[34][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[34][playerid] = CreatePlayerTextDraw(playerid, 357.300567, 92.274101, "999_kg");
		PlayerTextDrawLetterSize(playerid, inventory_gui_p[34][playerid], 0.172332, 1.272296);
		PlayerTextDrawTextSize(playerid, inventory_gui_p[34][playerid], 0.000000, 32.000000);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[34][playerid], 2);
		PlayerTextDrawColor(playerid, inventory_gui_p[34][playerid], -1);
		PlayerTextDrawSetShadow(playerid, inventory_gui_p[34][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[34][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[34][playerid], 2);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[34][playerid], 1);
	}
	if(inventory_gui_p[35][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[35][playerid] = CreatePlayerTextDraw(playerid, 129.000015, 160.836883, "25");
		PlayerTextDrawLetterSize(playerid, inventory_gui_p[35][playerid], 0.297666, 1.525333);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[35][playerid], 3);
		PlayerTextDrawColor(playerid, inventory_gui_p[35][playerid], -1);
		PlayerTextDrawSetShadow(playerid, inventory_gui_p[35][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[35][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[35][playerid], 1);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[35][playerid], 1);
	}
	if(inventory_gui_p[36][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[36][playerid] = CreatePlayerTextDraw(playerid, 177.000015, 160.836883, "25");
		PlayerTextDrawLetterSize(playerid, inventory_gui_p[36][playerid], 0.297666, 1.525333);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[36][playerid], 3);
		PlayerTextDrawColor(playerid, inventory_gui_p[36][playerid], -1);
		PlayerTextDrawSetShadow(playerid, inventory_gui_p[36][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[36][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[36][playerid], 1);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[36][playerid], 1);
	}
	if(inventory_gui_p[37][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[37][playerid] = CreatePlayerTextDraw(playerid, 225.000015, 160.836883, "25");
		PlayerTextDrawLetterSize(playerid, inventory_gui_p[37][playerid], 0.297666, 1.525333);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[37][playerid], 3);
		PlayerTextDrawColor(playerid, inventory_gui_p[37][playerid], -1);
		PlayerTextDrawSetShadow(playerid, inventory_gui_p[37][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[37][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[37][playerid], 1);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[37][playerid], 1);
	}
	if(inventory_gui_p[38][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[38][playerid] = CreatePlayerTextDraw(playerid, 272.999969, 160.836883, "25");
		PlayerTextDrawLetterSize(playerid, inventory_gui_p[38][playerid], 0.297666, 1.525333);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[38][playerid], 3);
		PlayerTextDrawColor(playerid, inventory_gui_p[38][playerid], -1);
		PlayerTextDrawSetShadow(playerid, inventory_gui_p[38][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[38][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[38][playerid], 1);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[38][playerid], 1);
	}
	if(inventory_gui_p[39][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[39][playerid] = CreatePlayerTextDraw(playerid, 320.999969, 160.836883, "25");
		PlayerTextDrawLetterSize(playerid, inventory_gui_p[39][playerid], 0.297666, 1.525333);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[39][playerid], 3);
		PlayerTextDrawColor(playerid, inventory_gui_p[39][playerid], -1);
		PlayerTextDrawSetShadow(playerid, inventory_gui_p[39][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[39][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[39][playerid], 1);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[39][playerid], 1);
	}
	if(inventory_gui_p[40][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[40][playerid] = CreatePlayerTextDraw(playerid, 368.999969, 160.836883, "25");
		PlayerTextDrawLetterSize(playerid, inventory_gui_p[40][playerid], 0.297666, 1.525333);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[40][playerid], 3);
		PlayerTextDrawColor(playerid, inventory_gui_p[40][playerid], -1);
		PlayerTextDrawSetShadow(playerid, inventory_gui_p[40][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[40][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[40][playerid], 1);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[40][playerid], 1);
	}
	if(inventory_gui_p[41][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[41][playerid] = CreatePlayerTextDraw(playerid, 129.000015, 231.836883, "25");
		PlayerTextDrawLetterSize(playerid, inventory_gui_p[41][playerid], 0.297666, 1.525333);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[41][playerid], 3);
		PlayerTextDrawColor(playerid, inventory_gui_p[41][playerid], -1);
		PlayerTextDrawSetShadow(playerid, inventory_gui_p[41][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[41][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[41][playerid], 1);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[41][playerid], 1);
	}
	if(inventory_gui_p[42][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[42][playerid] = CreatePlayerTextDraw(playerid, 177.000015, 231.836883, "25");
		PlayerTextDrawLetterSize(playerid, inventory_gui_p[42][playerid], 0.297666, 1.525333);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[42][playerid], 3);
		PlayerTextDrawColor(playerid, inventory_gui_p[42][playerid], -1);
		PlayerTextDrawSetShadow(playerid, inventory_gui_p[42][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[42][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[42][playerid], 1);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[42][playerid], 1);
	}
	if(inventory_gui_p[43][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[43][playerid] = CreatePlayerTextDraw(playerid, 225.000015, 231.836883, "25");
		PlayerTextDrawLetterSize(playerid, inventory_gui_p[43][playerid], 0.297666, 1.525333);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[43][playerid], 3);
		PlayerTextDrawColor(playerid, inventory_gui_p[43][playerid], -1);
		PlayerTextDrawSetShadow(playerid, inventory_gui_p[43][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[43][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[43][playerid], 1);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[43][playerid], 1);
	}
	if(inventory_gui_p[44][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[44][playerid] = CreatePlayerTextDraw(playerid, 272.999969, 231.836883, "25");
		PlayerTextDrawLetterSize(playerid, inventory_gui_p[44][playerid], 0.297666, 1.525333);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[44][playerid], 3);
		PlayerTextDrawColor(playerid, inventory_gui_p[44][playerid], -1);
		PlayerTextDrawSetShadow(playerid, inventory_gui_p[44][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[44][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[44][playerid], 1);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[44][playerid], 1);
	}
	if(inventory_gui_p[45][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[45][playerid] = CreatePlayerTextDraw(playerid, 320.999969, 231.836883, "25");
		PlayerTextDrawLetterSize(playerid, inventory_gui_p[45][playerid], 0.297666, 1.525333);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[45][playerid], 3);
		PlayerTextDrawColor(playerid, inventory_gui_p[45][playerid], -1);
		PlayerTextDrawSetShadow(playerid, inventory_gui_p[45][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[45][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[45][playerid], 1);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[45][playerid], 1);
	}
	if(inventory_gui_p[46][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[46][playerid] = CreatePlayerTextDraw(playerid, 368.999969, 231.836883, "25");
		PlayerTextDrawLetterSize(playerid, inventory_gui_p[46][playerid], 0.297666, 1.525333);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[46][playerid], 3);
		PlayerTextDrawColor(playerid, inventory_gui_p[46][playerid], -1);
		PlayerTextDrawSetShadow(playerid, inventory_gui_p[46][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[46][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[46][playerid], 1);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[46][playerid], 1);
	}
	if(inventory_gui_p[47][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[47][playerid] = CreatePlayerTextDraw(playerid, 129.000015, 303.837402, "25");
		PlayerTextDrawLetterSize(playerid, inventory_gui_p[47][playerid], 0.297666, 1.525333);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[47][playerid], 3);
		PlayerTextDrawColor(playerid, inventory_gui_p[47][playerid], -1);
		PlayerTextDrawSetShadow(playerid, inventory_gui_p[47][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[47][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[47][playerid], 1);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[47][playerid], 1);
	}
	if(inventory_gui_p[48][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[48][playerid] = CreatePlayerTextDraw(playerid, 177.000015, 303.837402, "25");
		PlayerTextDrawLetterSize(playerid, inventory_gui_p[48][playerid], 0.297666, 1.525333);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[48][playerid], 3);
		PlayerTextDrawColor(playerid, inventory_gui_p[48][playerid], -1);
		PlayerTextDrawSetShadow(playerid, inventory_gui_p[48][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[48][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[48][playerid], 1);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[48][playerid], 1);
	}
	if(inventory_gui_p[49][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[49][playerid] = CreatePlayerTextDraw(playerid, 225.000015, 303.837402, "25");
		PlayerTextDrawLetterSize(playerid, inventory_gui_p[49][playerid], 0.297666, 1.525333);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[49][playerid], 3);
		PlayerTextDrawColor(playerid, inventory_gui_p[49][playerid], -1);
		PlayerTextDrawSetShadow(playerid, inventory_gui_p[49][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[49][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[49][playerid], 1);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[49][playerid], 1);
	}
	if(inventory_gui_p[50][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[50][playerid] = CreatePlayerTextDraw(playerid, 272.999969, 303.837402, "25");
		PlayerTextDrawLetterSize(playerid, inventory_gui_p[50][playerid], 0.297666, 1.525333);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[50][playerid], 3);
		PlayerTextDrawColor(playerid, inventory_gui_p[50][playerid], -1);
		PlayerTextDrawSetShadow(playerid, inventory_gui_p[50][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[50][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[50][playerid], 1);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[50][playerid], 1);
	}
	if(inventory_gui_p[51][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[51][playerid] = CreatePlayerTextDraw(playerid, 320.999969, 303.837402, "25");
		PlayerTextDrawLetterSize(playerid, inventory_gui_p[51][playerid], 0.297666, 1.525333);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[51][playerid], 3);
		PlayerTextDrawColor(playerid, inventory_gui_p[51][playerid], -1);
		PlayerTextDrawSetShadow(playerid, inventory_gui_p[51][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[51][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[51][playerid], 1);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[51][playerid], 1);
	}
	if(inventory_gui_p[52][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[52][playerid] = CreatePlayerTextDraw(playerid, 368.999969, 303.837402, "25");
		PlayerTextDrawLetterSize(playerid, inventory_gui_p[52][playerid], 0.297666, 1.525333);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[52][playerid], 3);
		PlayerTextDrawColor(playerid, inventory_gui_p[52][playerid], -1);
		PlayerTextDrawSetShadow(playerid, inventory_gui_p[52][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[52][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[52][playerid], 1);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[52][playerid], 1);
	}
	if(inventory_gui_p[53][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[53][playerid] = CreatePlayerTextDraw(playerid, 129.000015, 372.837402, "25");
		PlayerTextDrawLetterSize(playerid, inventory_gui_p[53][playerid], 0.297666, 1.525333);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[53][playerid], 3);
		PlayerTextDrawColor(playerid, inventory_gui_p[53][playerid], -1);
		PlayerTextDrawSetShadow(playerid, inventory_gui_p[53][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[53][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[53][playerid], 1);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[53][playerid], 1);
	}
	if(inventory_gui_p[54][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[54][playerid] = CreatePlayerTextDraw(playerid, 177.000015, 372.837402, "25");
		PlayerTextDrawLetterSize(playerid, inventory_gui_p[54][playerid], 0.297666, 1.525333);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[54][playerid], 3);
		PlayerTextDrawColor(playerid, inventory_gui_p[54][playerid], -1);
		PlayerTextDrawSetShadow(playerid, inventory_gui_p[54][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[54][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[54][playerid], 1);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[54][playerid], 1);
	}
	if(inventory_gui_p[55][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[55][playerid] = CreatePlayerTextDraw(playerid, 225.000015, 372.837402, "25");
		PlayerTextDrawLetterSize(playerid, inventory_gui_p[55][playerid], 0.297666, 1.525333);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[55][playerid], 3);
		PlayerTextDrawColor(playerid, inventory_gui_p[55][playerid], -1);
		PlayerTextDrawSetShadow(playerid, inventory_gui_p[55][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[55][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[55][playerid], 1);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[55][playerid], 1);
	}
	if(inventory_gui_p[56][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[56][playerid] = CreatePlayerTextDraw(playerid, 272.999969, 372.837402, "25");
		PlayerTextDrawLetterSize(playerid, inventory_gui_p[56][playerid], 0.297666, 1.525333);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[56][playerid], 3);
		PlayerTextDrawColor(playerid, inventory_gui_p[56][playerid], -1);
		PlayerTextDrawSetShadow(playerid, inventory_gui_p[56][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[56][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[56][playerid], 1);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[56][playerid], 1);
	}
	if(inventory_gui_p[57][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[57][playerid] = CreatePlayerTextDraw(playerid, 320.999969, 372.837402, "25");
		PlayerTextDrawLetterSize(playerid, inventory_gui_p[57][playerid], 0.297666, 1.525333);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[57][playerid], 3);
		PlayerTextDrawColor(playerid, inventory_gui_p[57][playerid], -1);
		PlayerTextDrawSetShadow(playerid, inventory_gui_p[57][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[57][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[57][playerid], 1);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[57][playerid], 1);
	}
	if(inventory_gui_p[58][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		inventory_gui_p[58][playerid] = CreatePlayerTextDraw(playerid, 368.999969, 372.837402, "25");
		PlayerTextDrawLetterSize(playerid, inventory_gui_p[58][playerid], 0.297666, 1.525333);
		PlayerTextDrawAlignment(playerid, inventory_gui_p[58][playerid], 3);
		PlayerTextDrawColor(playerid, inventory_gui_p[58][playerid], -1);
		PlayerTextDrawSetShadow(playerid, inventory_gui_p[58][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, inventory_gui_p[58][playerid], 255);
		PlayerTextDrawFont(playerid, inventory_gui_p[58][playerid], 1);
		PlayerTextDrawSetProportional(playerid, inventory_gui_p[58][playerid], 1);
	}

	return true;
}

stock create_clothes_shop_price(playerid)
{
	if(clothes_select_price[playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		clothes_select_price[playerid] = CreatePlayerTextDraw(playerid, 322.999877, 333.925933, "500000_RUB"); // Text element
		PlayerTextDrawLetterSize(playerid, clothes_select_price[playerid], 0.527666, 2.342518);
		PlayerTextDrawAlignment(playerid, clothes_select_price[playerid], 2);
		PlayerTextDrawColor(playerid, clothes_select_price[playerid], -1);
		PlayerTextDrawUseBox(playerid, clothes_select_price[playerid], true);
		PlayerTextDrawBoxColor(playerid, clothes_select_price[playerid], 0);
		PlayerTextDrawSetShadow(playerid, clothes_select_price[playerid], 0);
		PlayerTextDrawSetOutline(playerid, clothes_select_price[playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, clothes_select_price[playerid], 51);
		PlayerTextDrawFont(playerid, clothes_select_price[playerid], 1);
		PlayerTextDrawSetProportional(playerid, clothes_select_price[playerid], 1);
	}


	return true;
}

stock create_background_login(playerid)
{
	if(background_login[playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		background_login[playerid] = CreatePlayerTextDraw(playerid, -1.333333, -0.829629, "brilliantother:authback_1"); // Texture element
		PlayerTextDrawLetterSize(playerid, background_login[playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, background_login[playerid], 641.999938, 453.807495);
		PlayerTextDrawAlignment(playerid, background_login[playerid], 2);
		PlayerTextDrawColor(playerid, background_login[playerid], -1);
		PlayerTextDrawSetShadow(playerid, background_login[playerid], 0);
		PlayerTextDrawSetOutline(playerid, background_login[playerid], 0);
		PlayerTextDrawFont(playerid, background_login[playerid], 4);
	}
	return true;
}

stock create_player_position_race(playerid)
{

	if(race_position_player[playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		race_position_player[playerid] = CreatePlayerTextDraw(playerid, 49.000000, 168.414764, "1/20"); // Text element
		PlayerTextDrawLetterSize(playerid, race_position_player[playerid], 0.559000, 2.558222);
		PlayerTextDrawAlignment(playerid, race_position_player[playerid], 2);
		PlayerTextDrawColor(playerid, race_position_player[playerid], -1);
		PlayerTextDrawSetShadow(playerid, race_position_player[playerid], 0);
		PlayerTextDrawSetOutline(playerid, race_position_player[playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, race_position_player[playerid], 51);
		PlayerTextDrawFont(playerid, race_position_player[playerid], 3);
		PlayerTextDrawSetProportional(playerid, race_position_player[playerid], 1);
	}


	return true;
}

stock create_player_button_race(playerid)
{
	if(race_player_button[playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		race_player_button[playerid] = CreatePlayerTextDraw(playerid, 335.666656, 199.940689, "brilliantother:race_button_1"); // Texture element
		PlayerTextDrawLetterSize(playerid, race_player_button[playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, race_player_button[playerid], 119.000015, 92.088867);
		PlayerTextDrawAlignment(playerid, race_player_button[playerid], 2);
		PlayerTextDrawColor(playerid, race_player_button[playerid], -1);
		PlayerTextDrawSetShadow(playerid, race_player_button[playerid], 0);
		PlayerTextDrawSetOutline(playerid, race_player_button[playerid], 0);
		PlayerTextDrawFont(playerid, race_player_button[playerid], 4);
		PlayerTextDrawSetSelectable(playerid, race_player_button[playerid], true);
	}
	return true;
}

stock create_snow_bonus_player(playerid)
{
	if(snow_give_player_p[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		snow_give_player_p[0][playerid] = CreatePlayerTextDraw(playerid, 266.666534, 150.162948, "brilliantother:newyear_snow_gui"); // Texture element
		PlayerTextDrawLetterSize(playerid, snow_give_player_p[0][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, snow_give_player_p[0][playerid], 111.666732, 64.296295);
		PlayerTextDrawAlignment(playerid, snow_give_player_p[0][playerid], 1);
		PlayerTextDrawColor(playerid, snow_give_player_p[0][playerid], -1);
		PlayerTextDrawSetShadow(playerid, snow_give_player_p[0][playerid], 0);
		PlayerTextDrawSetOutline(playerid, snow_give_player_p[0][playerid], 0);
		PlayerTextDrawFont(playerid, snow_give_player_p[0][playerid], 4);
	}
	if(snow_give_player_p[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		snow_give_player_p[1][playerid] = CreatePlayerTextDraw(playerid, 286.999938, 172.148147, "1"); // Text element
		PlayerTextDrawLetterSize(playerid, snow_give_player_p[1][playerid], 0.440666, 1.960888);
		PlayerTextDrawAlignment(playerid, snow_give_player_p[1][playerid], 2);
		PlayerTextDrawColor(playerid, snow_give_player_p[1][playerid], -1);
		PlayerTextDrawUseBox(playerid, snow_give_player_p[1][playerid], true);
		PlayerTextDrawBoxColor(playerid, snow_give_player_p[1][playerid], 0);
		PlayerTextDrawSetShadow(playerid, snow_give_player_p[1][playerid], 0);
		PlayerTextDrawSetOutline(playerid, snow_give_player_p[1][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, snow_give_player_p[1][playerid], 51);
		PlayerTextDrawFont(playerid, snow_give_player_p[1][playerid], 1);
		PlayerTextDrawSetProportional(playerid, snow_give_player_p[1][playerid], 1);
	}
	return true;
}

stock create_player_newyear_info(playerid)
{
	if(newyear_gui_info[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		newyear_gui_info[0][playerid] = CreatePlayerTextDraw(playerid, 249.666748, 127.762992, "brilliantother:newyear_snow_quest_final"); // Texture element
		PlayerTextDrawLetterSize(playerid, newyear_gui_info[0][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, newyear_gui_info[0][playerid], 159.000015, 95.822227);
		PlayerTextDrawAlignment(playerid, newyear_gui_info[0][playerid], 2);
		PlayerTextDrawColor(playerid, newyear_gui_info[0][playerid], -1);
		PlayerTextDrawSetShadow(playerid, newyear_gui_info[0][playerid], 0);
		PlayerTextDrawSetOutline(playerid, newyear_gui_info[0][playerid], 0);
		PlayerTextDrawFont(playerid, newyear_gui_info[0][playerid], 4);
	}
	if(newyear_gui_info[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		newyear_gui_info[1][playerid] = CreatePlayerTextDraw(playerid, 268.333374, 226.488906, "brilliantother:newyear_snow_give_3"); // Texture element
		PlayerTextDrawLetterSize(playerid, newyear_gui_info[1][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, newyear_gui_info[1][playerid], 159.000015, 95.822227);
		PlayerTextDrawAlignment(playerid, newyear_gui_info[1][playerid], 2);
		PlayerTextDrawColor(playerid, newyear_gui_info[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, newyear_gui_info[1][playerid], 0);
		PlayerTextDrawSetOutline(playerid, newyear_gui_info[1][playerid], 0);
		PlayerTextDrawFont(playerid, newyear_gui_info[1][playerid], 4);
	}
	return true;
}

stock create_player_button_race_snow(playerid)
{
	if(race_player_button_snow[playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		race_player_button_snow[playerid] = CreatePlayerTextDraw(playerid, 335.666656, 199.940689, "brilliantother:race_button_1"); // Texture element
		PlayerTextDrawLetterSize(playerid, race_player_button_snow[playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, race_player_button_snow[playerid], 119.000015, 92.088867);
		PlayerTextDrawAlignment(playerid, race_player_button_snow[playerid], 2);
		PlayerTextDrawColor(playerid, race_player_button_snow[playerid], -1);
		PlayerTextDrawSetShadow(playerid, race_player_button_snow[playerid], 0);
		PlayerTextDrawSetOutline(playerid, race_player_button_snow[playerid], 0);
		PlayerTextDrawFont(playerid, race_player_button_snow[playerid], 4);
		PlayerTextDrawSetSelectable(playerid, race_player_button_snow[playerid], true);
	}
	return true;
}


stock create_aks_shop()
{

	aks_select_td[0] = TextDrawCreate(77.333320, 154.725936, "brilliantother:left_button_clothes"); // Texture element
	TextDrawLetterSize(aks_select_td[0], 0.000000, 0.000000);
	TextDrawTextSize(aks_select_td[0], 64.666687, 129.836959);
	TextDrawAlignment(aks_select_td[0], 2);
	TextDrawColor(aks_select_td[0], -1);
	TextDrawSetShadow(aks_select_td[0], 0);
	TextDrawSetOutline(aks_select_td[0], 0);
	TextDrawFont(aks_select_td[0], 4);
	TextDrawSetSelectable(aks_select_td[0], true);

	aks_select_td[1] = TextDrawCreate(484.000061, 152.237091, "brilliantother:right_button_clothes"); // Texture element
	TextDrawLetterSize(aks_select_td[1], 0.000000, 0.000000);
	TextDrawTextSize(aks_select_td[1], 64.666687, 129.836959);
	TextDrawAlignment(aks_select_td[1], 2);
	TextDrawColor(aks_select_td[1], -1);
	TextDrawSetShadow(aks_select_td[1], 0);
	TextDrawSetOutline(aks_select_td[1], 0);
	TextDrawFont(aks_select_td[1], 4);
	TextDrawSetSelectable(aks_select_td[1], true);

	aks_select_td[2] = TextDrawCreate(250.000015, 333.925964, "brilliantother:money_icon_clothes"); // Texture element
	TextDrawLetterSize(aks_select_td[2], 0.000000, 0.000000);
	TextDrawTextSize(aks_select_td[2], 16.999998, 23.229660);
	TextDrawAlignment(aks_select_td[2], 1);
	TextDrawColor(aks_select_td[2], -1);
	TextDrawSetShadow(aks_select_td[2], 0);
	TextDrawSetOutline(aks_select_td[2], 0);
	TextDrawFont(aks_select_td[2], 4);

	aks_select_td[3] = TextDrawCreate(214.333297, 362.962951, "brilliantother:buy_button_clothes"); // Texture element
	TextDrawLetterSize(aks_select_td[3], 0.000000, 0.000000);
	TextDrawTextSize(aks_select_td[3], 95.999992, 38.577754);
	TextDrawAlignment(aks_select_td[3], 2);
	TextDrawColor(aks_select_td[3], -1);
	TextDrawSetShadow(aks_select_td[3], 0);
	TextDrawSetOutline(aks_select_td[3], 0);
	TextDrawFont(aks_select_td[3], 4);
	TextDrawSetSelectable(aks_select_td[3], true);

	aks_select_td[4] = TextDrawCreate(324.666687, 360.888916, "brilliantother:exit_button_clothes"); // Texture element
	TextDrawLetterSize(aks_select_td[4], 0.000000, 0.000000);
	TextDrawTextSize(aks_select_td[4], 95.999992, 38.577754);
	TextDrawAlignment(aks_select_td[4], 2);
	TextDrawColor(aks_select_td[4], -1);
	TextDrawSetShadow(aks_select_td[4], 0);
	TextDrawSetOutline(aks_select_td[4], 0);
	TextDrawFont(aks_select_td[4], 4);
	TextDrawSetSelectable(aks_select_td[4], true);

	aks_select_td[5] = TextDrawCreate(-1.000000, 379.140655, "brilliantother:background_clothes"); // Texture element
	TextDrawLetterSize(aks_select_td[5], 0.000000, 0.000000);
	TextDrawTextSize(aks_select_td[5], 646.333007, 94.992614);
	TextDrawAlignment(aks_select_td[5], 1);
	TextDrawColor(aks_select_td[5], -1);
	TextDrawSetShadow(aks_select_td[5], 0);
	TextDrawSetOutline(aks_select_td[5], 0);
	TextDrawFont(aks_select_td[5], 4);


	return true;
}

stock create_aks_shop_price(playerid)
{
	if(aks_select_price[playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		aks_select_price[playerid] = CreatePlayerTextDraw(playerid, 322.999877, 333.925933, "500000_RUB"); // Text element
		PlayerTextDrawLetterSize(playerid, aks_select_price[playerid], 0.527666, 2.342518);
		PlayerTextDrawAlignment(playerid, aks_select_price[playerid], 2);
		PlayerTextDrawColor(playerid, aks_select_price[playerid], -1);
		PlayerTextDrawUseBox(playerid, aks_select_price[playerid], true);
		PlayerTextDrawBoxColor(playerid, aks_select_price[playerid], 0);
		PlayerTextDrawSetShadow(playerid, aks_select_price[playerid], 0);
		PlayerTextDrawSetOutline(playerid, aks_select_price[playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, aks_select_price[playerid], 51);
		PlayerTextDrawFont(playerid, aks_select_price[playerid], 1);
		PlayerTextDrawSetProportional(playerid, aks_select_price[playerid], 1);
	}


	return true;
}


stock create_info_player(playerid)
{
	if(player_info_td[playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		player_info_td[playerid] = CreatePlayerTextDraw(playerid, 263.000183, 389.511230, "brilliantother:notify_player_use_alt"); // Texture element
		PlayerTextDrawLetterSize(playerid, player_info_td[playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, player_info_td[playerid], 112.666671, 35.259262);
		PlayerTextDrawAlignment(playerid, player_info_td[playerid], 2);
		PlayerTextDrawColor(playerid, player_info_td[playerid], -1);
		PlayerTextDrawSetShadow(playerid, player_info_td[playerid], 0);
		PlayerTextDrawSetOutline(playerid, player_info_td[playerid], 0);
		PlayerTextDrawFont(playerid, player_info_td[playerid], 4);

	}

	return true;
}

stock create_quest_newyear_td()
{
	quest_newyear_td = TextDrawCreate(89.666679, 85.451843, "brp_quest:quest_newyear_snow_back"); // Texture element
	TextDrawLetterSize(quest_newyear_td, 0.000000, 0.000000);
	TextDrawTextSize(quest_newyear_td, 449.333404, 322.726165);
	TextDrawAlignment(quest_newyear_td, 2);
	TextDrawColor(quest_newyear_td, -1);
	TextDrawSetShadow(quest_newyear_td, 0);
	TextDrawSetOutline(quest_newyear_td, 0);
	TextDrawFont(quest_newyear_td, 4);


	quest_close_button_other = TextDrawCreate(460.666595, 116.148132, "brilliantother:police_plater_close"); // Texture element
	TextDrawLetterSize(quest_close_button_other, 0.000000, 0.000000);
	TextDrawTextSize(quest_close_button_other, 24.666656, 16.592607);
	TextDrawAlignment(quest_close_button_other, 2);
	TextDrawColor(quest_close_button_other, -1);
	TextDrawSetShadow(quest_close_button_other, 0);
	TextDrawSetOutline(quest_close_button_other, 0);
	TextDrawFont(quest_close_button_other, 4);
	TextDrawSetSelectable(quest_close_button_other, true);

	quest_newyear_start[0] = TextDrawCreate(-2.000000, -0.829629, "brp_quest:quest_newyear_2"); // Texture element
	TextDrawLetterSize(quest_newyear_start[0], 0.000000, 0.000000);
	TextDrawTextSize(quest_newyear_start[0], 660.999511, 449.659301);
	TextDrawAlignment(quest_newyear_start[0], 2);
	TextDrawColor(quest_newyear_start[0], -1);
	TextDrawSetShadow(quest_newyear_start[0], 0);
	TextDrawSetOutline(quest_newyear_start[0], 0);
	TextDrawFont(quest_newyear_start[0], 4);

	quest_newyear_start[1] = TextDrawCreate(125.333366, 89.600013, "brilliantother:quest_newyear_text"); // Texture element
	TextDrawLetterSize(quest_newyear_start[1], 0.000000, 0.000000);
	TextDrawTextSize(quest_newyear_start[1], 261.666687, 239.762878);
	TextDrawAlignment(quest_newyear_start[1], 2);
	TextDrawColor(quest_newyear_start[1], -1);
	TextDrawSetShadow(quest_newyear_start[1], 0);
	TextDrawSetOutline(quest_newyear_start[1], 0);
	TextDrawFont(quest_newyear_start[1], 4);

	quest_newyear_start[2] = TextDrawCreate(414.000061, 339.733337, "brilliantother:quest_newyear_1"); // Texture element
	TextDrawLetterSize(quest_newyear_start[2], 0.000000, 0.000000);
	TextDrawTextSize(quest_newyear_start[2], 159.000061, 97.481452);
	TextDrawAlignment(quest_newyear_start[2], 2);
	TextDrawColor(quest_newyear_start[2], -1);
	TextDrawSetShadow(quest_newyear_start[2], 0);
	TextDrawSetOutline(quest_newyear_start[2], 0);
	TextDrawFont(quest_newyear_start[2], 4);
	TextDrawSetSelectable(quest_newyear_start[2], true);

	quest_newyear_start[3] = TextDrawCreate(390.333435, 57.659263, "brilliantother:police_plater_close"); // Texture element
	TextDrawLetterSize(quest_newyear_start[3], 0.000000, 0.000000);
	TextDrawTextSize(quest_newyear_start[3], 22.666677, 16.592588);
	TextDrawAlignment(quest_newyear_start[3], 2);
	TextDrawColor(quest_newyear_start[3], -1);
	TextDrawSetShadow(quest_newyear_start[3], 0);
	TextDrawSetOutline(quest_newyear_start[3], 0);
	TextDrawFont(quest_newyear_start[3], 4);
	TextDrawSetSelectable(quest_newyear_start[3], true);

	return true;
}

stock create_quest_general_p(playerid)
{
	if(quest_general_panel_s[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		quest_general_panel_s[0][playerid] = CreatePlayerTextDraw(playerid, 90.000015, 86.696296, "brp_quest:quest_newyear_snow_back"); // Texture element
		PlayerTextDrawLetterSize(playerid, quest_general_panel_s[0][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, quest_general_panel_s[0][playerid], 449.333404, 322.726165);
		PlayerTextDrawAlignment(playerid, quest_general_panel_s[0][playerid], 1);
		PlayerTextDrawColor(playerid, quest_general_panel_s[0][playerid], -1);
		PlayerTextDrawSetShadow(playerid, quest_general_panel_s[0][playerid], 0);
		PlayerTextDrawSetOutline(playerid, quest_general_panel_s[0][playerid], 0);
		PlayerTextDrawFont(playerid, quest_general_panel_s[0][playerid], 4);
	}
	if(quest_general_panel_s[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		quest_general_panel_s[1][playerid] = CreatePlayerTextDraw(playerid, 149.666687, 114.074050, "brp_quest:quest_newyear_background_11"); // Texture element
		PlayerTextDrawLetterSize(playerid, quest_general_panel_s[1][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, quest_general_panel_s[1][playerid], 337.000061, 265.896240);
		PlayerTextDrawAlignment(playerid, quest_general_panel_s[1][playerid], 1);
		PlayerTextDrawColor(playerid, quest_general_panel_s[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, quest_general_panel_s[1][playerid], 0);
		PlayerTextDrawSetOutline(playerid, quest_general_panel_s[1][playerid], 0);
		PlayerTextDrawFont(playerid, quest_general_panel_s[1][playerid], 4);
	}
	if(quest_general_panel_s[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		quest_general_panel_s[2][playerid] = CreatePlayerTextDraw(playerid, 158.666687, 181.688934, "brp_quest:quest_button_l_active_1"); // Texture element
		PlayerTextDrawLetterSize(playerid, quest_general_panel_s[2][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, quest_general_panel_s[2][playerid], 130.000061, 32.770381);
		PlayerTextDrawAlignment(playerid, quest_general_panel_s[2][playerid], 2);
		PlayerTextDrawColor(playerid, quest_general_panel_s[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, quest_general_panel_s[2][playerid], 0);
		PlayerTextDrawSetOutline(playerid, quest_general_panel_s[2][playerid], 0);
		PlayerTextDrawFont(playerid, quest_general_panel_s[2][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, quest_general_panel_s[2][playerid], true);
	}
	if(quest_general_panel_s[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		quest_general_panel_s[3][playerid] = CreatePlayerTextDraw(playerid, 158.333358, 217.363052, "brp_quest:quest_button_l_active_2"); // Texture element
		PlayerTextDrawLetterSize(playerid, quest_general_panel_s[3][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, quest_general_panel_s[3][playerid], 130.333374, 31.940746);
		PlayerTextDrawAlignment(playerid, quest_general_panel_s[3][playerid], 2);
		PlayerTextDrawColor(playerid, quest_general_panel_s[3][playerid], -1);
		PlayerTextDrawSetShadow(playerid, quest_general_panel_s[3][playerid], 0);
		PlayerTextDrawSetOutline(playerid, quest_general_panel_s[3][playerid], 0);
		PlayerTextDrawFont(playerid, quest_general_panel_s[3][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, quest_general_panel_s[3][playerid], true);
	}
	if(quest_general_panel_s[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		quest_general_panel_s[4][playerid] = CreatePlayerTextDraw(playerid, 157.333328, 146.014831, "brp_quest:quest_newyear_other_quest"); // Texture element
		PlayerTextDrawLetterSize(playerid, quest_general_panel_s[4][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, quest_general_panel_s[4][playerid], 67.000000, 31.525943);
		PlayerTextDrawAlignment(playerid, quest_general_panel_s[4][playerid], 1);
		PlayerTextDrawColor(playerid, quest_general_panel_s[4][playerid], -1);
		PlayerTextDrawSetShadow(playerid, quest_general_panel_s[4][playerid], 0);
		PlayerTextDrawSetOutline(playerid, quest_general_panel_s[4][playerid], 0);
		PlayerTextDrawFont(playerid, quest_general_panel_s[4][playerid], 4);
	}
	if(quest_general_panel_s[5][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		quest_general_panel_s[5][playerid] = CreatePlayerTextDraw(playerid, 223.333358, 146.429641, "brp_quest:quest_newyear_other_quest_2"); // Texture element
		PlayerTextDrawLetterSize(playerid, quest_general_panel_s[5][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, quest_general_panel_s[5][playerid], 0.0, 0.0);
		PlayerTextDrawAlignment(playerid, quest_general_panel_s[5][playerid], 1);
		PlayerTextDrawColor(playerid, quest_general_panel_s[5][playerid], -1);
		PlayerTextDrawSetShadow(playerid, quest_general_panel_s[5][playerid], 0);
		PlayerTextDrawSetOutline(playerid, quest_general_panel_s[5][playerid], 0);
		PlayerTextDrawFont(playerid, quest_general_panel_s[5][playerid], 4);
	}
	return true;
}

stock create_traning_start_p(playerid)
{
	if(start_traning_player_td[playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		start_traning_player_td[playerid] = CreatePlayerTextDraw(playerid, 423.999908, 125.274101, "brilliantother:notify_start_player_1"); // Texture element
		PlayerTextDrawLetterSize(playerid, start_traning_player_td[playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, start_traning_player_td[playerid], 156.999984, 221.096267);
		PlayerTextDrawAlignment(playerid, start_traning_player_td[playerid], 2);
		PlayerTextDrawColor(playerid, start_traning_player_td[playerid], -1);
		PlayerTextDrawSetShadow(playerid, start_traning_player_td[playerid], -46);
		PlayerTextDrawSetOutline(playerid, start_traning_player_td[playerid], 0);
		PlayerTextDrawFont(playerid, start_traning_player_td[playerid], 4);
	}
	return true;
}

stock create_quest_newyear_p(playerid)
{
	if(quest_newyear_p[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		quest_newyear_p[0][playerid] = CreatePlayerTextDraw(playerid, 150.000015, 114.074050, "brp_quest:quest_newyear_background_10"); // Texture element
		PlayerTextDrawLetterSize(playerid, quest_newyear_p[0][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, quest_newyear_p[0][playerid], 337.000061, 265.896240);
		PlayerTextDrawAlignment(playerid, quest_newyear_p[0][playerid], 2);
		PlayerTextDrawColor(playerid, quest_newyear_p[0][playerid], -1);
		PlayerTextDrawSetShadow(playerid, quest_newyear_p[0][playerid], 0);
		PlayerTextDrawSetOutline(playerid, quest_newyear_p[0][playerid], 0);
		PlayerTextDrawFont(playerid, quest_newyear_p[0][playerid], 4);
	}
	if(quest_newyear_p[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		quest_newyear_p[1][playerid] = CreatePlayerTextDraw(playerid, 158.000030, 181.274124, "brp_quest:quest_button_l_active_1"); // Texture element
		PlayerTextDrawLetterSize(playerid, quest_newyear_p[1][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, quest_newyear_p[1][playerid], 130.000061, 35.674083);
		PlayerTextDrawAlignment(playerid, quest_newyear_p[1][playerid], 2);
		PlayerTextDrawColor(playerid, quest_newyear_p[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, quest_newyear_p[1][playerid], 0);
		PlayerTextDrawSetOutline(playerid, quest_newyear_p[1][playerid], 0);
		PlayerTextDrawFont(playerid, quest_newyear_p[1][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, quest_newyear_p[1][playerid], true);
	}
	if(quest_newyear_p[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		quest_newyear_p[2][playerid] = CreatePlayerTextDraw(playerid, 158.333358, 217.363052, "brp_quest:quest_button_l_active_2"); // Texture element
		PlayerTextDrawLetterSize(playerid, quest_newyear_p[2][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, quest_newyear_p[2][playerid], 130.333374, 34.844444);
		PlayerTextDrawAlignment(playerid, quest_newyear_p[2][playerid], 2);
		PlayerTextDrawColor(playerid, quest_newyear_p[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, quest_newyear_p[2][playerid], 0);
		PlayerTextDrawSetOutline(playerid, quest_newyear_p[2][playerid], 0);
		PlayerTextDrawFont(playerid, quest_newyear_p[2][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, quest_newyear_p[2][playerid], true);
	}
	if(quest_newyear_p[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		quest_newyear_p[3][playerid] = CreatePlayerTextDraw(playerid, 157.333328, 146.014831, "brp_quest:quest_newyear_other_quest"); // Texture element
		PlayerTextDrawLetterSize(playerid, quest_newyear_p[3][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, quest_newyear_p[3][playerid], 67.000000, 31.525943);
		PlayerTextDrawAlignment(playerid, quest_newyear_p[3][playerid], 1);
		PlayerTextDrawColor(playerid, quest_newyear_p[3][playerid], -1);
		PlayerTextDrawSetShadow(playerid, quest_newyear_p[3][playerid], 0);
		PlayerTextDrawSetOutline(playerid, quest_newyear_p[3][playerid], 0);
		PlayerTextDrawFont(playerid, quest_newyear_p[3][playerid], 4);
	}
	if(quest_newyear_p[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		quest_newyear_p[4][playerid] = CreatePlayerTextDraw(playerid, 223.000030, 146.844451, "brp_quest:quest_newyear_other_quest_2"); // Texture element
		PlayerTextDrawLetterSize(playerid, quest_newyear_p[4][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, quest_newyear_p[4][playerid], 65.999984, 30.281482);
		PlayerTextDrawAlignment(playerid, quest_newyear_p[4][playerid], 2);
		PlayerTextDrawColor(playerid, quest_newyear_p[4][playerid], -1);
		PlayerTextDrawSetShadow(playerid, quest_newyear_p[4][playerid], 0);
		PlayerTextDrawSetOutline(playerid, quest_newyear_p[4][playerid], 0);
		PlayerTextDrawFont(playerid, quest_newyear_p[4][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, quest_newyear_p[4][playerid], true);
	}
	if(quest_newyear_p[5][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		quest_newyear_p[5][playerid] = CreatePlayerTextDraw(playerid, 458.333129, 115.733322, "brilliantother:police_plater_close"); // Texture element
		PlayerTextDrawLetterSize(playerid, quest_newyear_p[5][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, quest_newyear_p[5][playerid], 24.666656, 16.592607);
		PlayerTextDrawAlignment(playerid, quest_newyear_p[5][playerid], 2);
		PlayerTextDrawColor(playerid, quest_newyear_p[5][playerid], -1);
		PlayerTextDrawSetShadow(playerid, quest_newyear_p[5][playerid], 0);
		PlayerTextDrawSetOutline(playerid, quest_newyear_p[5][playerid], 0);
		PlayerTextDrawFont(playerid, quest_newyear_p[5][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, quest_newyear_p[5][playerid], true);
	}
	if(quest_newyear_p[6][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		quest_newyear_p[6][playerid] = CreatePlayerTextDraw(playerid, 158.000030, 254.696350, "brp_quest:quest_button_l_active_2"); // Texture element
		PlayerTextDrawLetterSize(playerid, quest_newyear_p[6][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, quest_newyear_p[6][playerid], 130.333374, 34.844444);
		PlayerTextDrawAlignment(playerid, quest_newyear_p[6][playerid], 2);
		PlayerTextDrawColor(playerid, quest_newyear_p[6][playerid], -1);
		PlayerTextDrawSetShadow(playerid, quest_newyear_p[6][playerid], 0);
		PlayerTextDrawSetOutline(playerid, quest_newyear_p[6][playerid], 0);
		PlayerTextDrawFont(playerid, quest_newyear_p[6][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, quest_newyear_p[6][playerid], true);
	}
	if(quest_newyear_p[7][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		quest_newyear_p[7][playerid] = CreatePlayerTextDraw(playerid, 158.000045, 292.859405, "brp_quest:quest_button_l_active_2"); // Texture element
		PlayerTextDrawLetterSize(playerid, quest_newyear_p[7][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, quest_newyear_p[7][playerid], 130.333374, 34.844444);
		PlayerTextDrawAlignment(playerid, quest_newyear_p[7][playerid], 2);
		PlayerTextDrawColor(playerid, quest_newyear_p[7][playerid], -1);
		PlayerTextDrawSetShadow(playerid, quest_newyear_p[7][playerid], 0);
		PlayerTextDrawSetOutline(playerid, quest_newyear_p[7][playerid], 0);
		PlayerTextDrawFont(playerid, quest_newyear_p[7][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, quest_newyear_p[7][playerid], true);
	}
	if(quest_newyear_p[8][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		quest_newyear_p[8][playerid] = CreatePlayerTextDraw(playerid, 158.000015, 342.637023, "brp_quest:quest_newyear_left"); // Texture element
		PlayerTextDrawLetterSize(playerid, quest_newyear_p[8][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, quest_newyear_p[8][playerid], 41.666671, 27.377807);
		PlayerTextDrawAlignment(playerid, quest_newyear_p[8][playerid], 2);
		PlayerTextDrawColor(playerid, quest_newyear_p[8][playerid], -1);
		PlayerTextDrawSetShadow(playerid, quest_newyear_p[8][playerid], 0);
		PlayerTextDrawSetOutline(playerid, quest_newyear_p[8][playerid], 0);
		PlayerTextDrawFont(playerid, quest_newyear_p[8][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, quest_newyear_p[8][playerid], true);
	}
	if(quest_newyear_p[9][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		quest_newyear_p[9][playerid] = CreatePlayerTextDraw(playerid, 246.666610, 341.392517, "brp_quest:quest_newyear_right"); // Texture element
		PlayerTextDrawLetterSize(playerid, quest_newyear_p[9][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, quest_newyear_p[9][playerid], 41.666671, 27.377807);
		PlayerTextDrawAlignment(playerid, quest_newyear_p[9][playerid], 2);
		PlayerTextDrawColor(playerid, quest_newyear_p[9][playerid], -1);
		PlayerTextDrawSetShadow(playerid, quest_newyear_p[9][playerid], 0);
		PlayerTextDrawSetOutline(playerid, quest_newyear_p[9][playerid], 0);
		PlayerTextDrawFont(playerid, quest_newyear_p[9][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, quest_newyear_p[9][playerid], true);
	}
	if(quest_newyear_p[10][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		quest_newyear_p[10][playerid] = CreatePlayerTextDraw(playerid, 221.666610, 345.125854, "1/3"); // Text element
		PlayerTextDrawLetterSize(playerid, quest_newyear_p[10][playerid], 0.280333, 1.687111);
		PlayerTextDrawAlignment(playerid, quest_newyear_p[10][playerid], 2);
		PlayerTextDrawColor(playerid, quest_newyear_p[10][playerid], -1);
		PlayerTextDrawUseBox(playerid, quest_newyear_p[10][playerid], true);
		PlayerTextDrawBoxColor(playerid, quest_newyear_p[10][playerid], 0);
		PlayerTextDrawSetShadow(playerid, quest_newyear_p[10][playerid], 0);
		PlayerTextDrawSetOutline(playerid, quest_newyear_p[10][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, quest_newyear_p[10][playerid], 51);
		PlayerTextDrawFont(playerid, quest_newyear_p[10][playerid], 2);
		PlayerTextDrawSetProportional(playerid, quest_newyear_p[10][playerid], 1);
	}
	if(quest_newyear_p[11][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		quest_newyear_p[11][playerid] = CreatePlayerTextDraw(playerid, 318.999877, 338.903656, ":"); // Text element
		PlayerTextDrawLetterSize(playerid, quest_newyear_p[11][playerid], 0.207999, 1.342813);
		PlayerTextDrawAlignment(playerid, quest_newyear_p[11][playerid], 2);
		PlayerTextDrawColor(playerid, quest_newyear_p[11][playerid], -1);
		PlayerTextDrawSetShadow(playerid, quest_newyear_p[11][playerid], 0);
		PlayerTextDrawSetOutline(playerid, quest_newyear_p[11][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, quest_newyear_p[11][playerid], 51);
		PlayerTextDrawFont(playerid, quest_newyear_p[11][playerid], 2);
		PlayerTextDrawSetProportional(playerid, quest_newyear_p[11][playerid], 1);
	}
	if(quest_newyear_p[12][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		format(String64, sizeof(String64), "%s", ToRus("����:"));
		quest_newyear_p[12][playerid] = CreatePlayerTextDraw(playerid, 334.333221, 351.348175, String64); // Text element
		PlayerTextDrawLetterSize(playerid, quest_newyear_p[12][playerid], 0.207999, 1.342813);
		PlayerTextDrawAlignment(playerid, quest_newyear_p[12][playerid], 2);
		PlayerTextDrawColor(playerid, quest_newyear_p[12][playerid], -1744877825);
		PlayerTextDrawSetShadow(playerid, quest_newyear_p[12][playerid], 0);
		PlayerTextDrawSetOutline(playerid, quest_newyear_p[12][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, quest_newyear_p[12][playerid], 51);
		PlayerTextDrawFont(playerid, quest_newyear_p[12][playerid], 2);
		PlayerTextDrawSetProportional(playerid, quest_newyear_p[12][playerid], 1);
	}
	if(quest_newyear_p[13][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		quest_newyear_p[13][playerid] = CreatePlayerTextDraw(playerid, 366.999969, 308.207366, "brp_quest:quest_newyear_3"); // Texture element
		PlayerTextDrawLetterSize(playerid, quest_newyear_p[13][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, quest_newyear_p[13][playerid], 112.000030, 83.377769);
		PlayerTextDrawAlignment(playerid, quest_newyear_p[13][playerid], 2);
		PlayerTextDrawColor(playerid, quest_newyear_p[13][playerid], -1);
		PlayerTextDrawSetShadow(playerid, quest_newyear_p[13][playerid], 0);
		PlayerTextDrawSetOutline(playerid, quest_newyear_p[13][playerid], 0);
		PlayerTextDrawFont(playerid, quest_newyear_p[13][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, quest_newyear_p[13][playerid], true);
	}
	return true;
}

stock create_buy_number_gai_p(playerid)
{
	if(buy_number_gai_p[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		buy_number_gai_p[0][playerid] = CreatePlayerTextDraw(playerid, 110.333305, 124.029670, "brilliantother:number_pl_ru_select"); // Texture element
		PlayerTextDrawLetterSize(playerid, buy_number_gai_p[0][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, buy_number_gai_p[0][playerid], 83.999977, 66.370368);
		PlayerTextDrawAlignment(playerid, buy_number_gai_p[0][playerid], 2);
		PlayerTextDrawColor(playerid, buy_number_gai_p[0][playerid], -1);
		PlayerTextDrawSetShadow(playerid, buy_number_gai_p[0][playerid], 0);
		PlayerTextDrawSetOutline(playerid, buy_number_gai_p[0][playerid], 0);
		PlayerTextDrawFont(playerid, buy_number_gai_p[0][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, buy_number_gai_p[0][playerid], true);
	}
	if(buy_number_gai_p[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{	
		buy_number_gai_p[1][playerid] = CreatePlayerTextDraw(playerid, 110.333328, 176.296386, "brilliantother:number_pl_kz_no_select"); // Texture element
		PlayerTextDrawLetterSize(playerid, buy_number_gai_p[1][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, buy_number_gai_p[1][playerid], 83.999977, 66.370368);
		PlayerTextDrawAlignment(playerid, buy_number_gai_p[1][playerid], 2);
		PlayerTextDrawColor(playerid, buy_number_gai_p[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, buy_number_gai_p[1][playerid], 0);
		PlayerTextDrawSetOutline(playerid, buy_number_gai_p[1][playerid], 0);
		PlayerTextDrawFont(playerid, buy_number_gai_p[1][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, buy_number_gai_p[1][playerid], true);
	}
	if(buy_number_gai_p[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		buy_number_gai_p[2][playerid] = CreatePlayerTextDraw(playerid, 110.666664, 228.563095, "brilliantother:number_pl_by_no_select"); // Texture element
		PlayerTextDrawLetterSize(playerid, buy_number_gai_p[2][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, buy_number_gai_p[2][playerid], 83.999977, 66.370368);
		PlayerTextDrawAlignment(playerid, buy_number_gai_p[2][playerid], 2);
		PlayerTextDrawColor(playerid, buy_number_gai_p[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, buy_number_gai_p[2][playerid], 0);
		PlayerTextDrawSetOutline(playerid, buy_number_gai_p[2][playerid], 0);
		PlayerTextDrawFont(playerid, buy_number_gai_p[2][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, buy_number_gai_p[2][playerid], true);
	}
	if(buy_number_gai_p[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		buy_number_gai_p[3][playerid] = CreatePlayerTextDraw(playerid, 110.333312, 280.414886, "brilliantother:number_pl_ua_no_select"); // Texture element
		PlayerTextDrawLetterSize(playerid, buy_number_gai_p[3][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, buy_number_gai_p[3][playerid], 83.999977, 66.370368);
		PlayerTextDrawAlignment(playerid, buy_number_gai_p[3][playerid], 2);
		PlayerTextDrawColor(playerid, buy_number_gai_p[3][playerid], -1);
		PlayerTextDrawSetShadow(playerid, buy_number_gai_p[3][playerid], 0);
		PlayerTextDrawSetOutline(playerid, buy_number_gai_p[3][playerid], 0);
		PlayerTextDrawFont(playerid, buy_number_gai_p[3][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, buy_number_gai_p[3][playerid], true);
	}
	if(buy_number_gai_p[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		buy_number_gai_p[4][playerid] = CreatePlayerTextDraw(playerid, 277.999847, 305.303588, "0_RUB"); // Text element
		PlayerTextDrawLetterSize(playerid, buy_number_gai_p[4][playerid], 0.338333, 1.695405);
		PlayerTextDrawAlignment(playerid, buy_number_gai_p[4][playerid], 2);
		PlayerTextDrawColor(playerid, buy_number_gai_p[4][playerid], -1);
		PlayerTextDrawSetShadow(playerid, buy_number_gai_p[4][playerid], -1);
		PlayerTextDrawSetOutline(playerid, buy_number_gai_p[4][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, buy_number_gai_p[4][playerid], 51);
		PlayerTextDrawFont(playerid, buy_number_gai_p[4][playerid], 2);
		PlayerTextDrawSetProportional(playerid, buy_number_gai_p[4][playerid], 1);
	}
	if(buy_number_gai_p[5][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		buy_number_gai_p[5][playerid] = CreatePlayerTextDraw(playerid, 371.000030, 191.644454, ""); // Text element
		PlayerTextDrawLetterSize(playerid, buy_number_gai_p[5][playerid], 0.703666, 3.462519);
		PlayerTextDrawAlignment(playerid, buy_number_gai_p[5][playerid], 2);
		PlayerTextDrawColor(playerid, buy_number_gai_p[5][playerid], -1);
		PlayerTextDrawSetShadow(playerid, buy_number_gai_p[5][playerid], 1);
		PlayerTextDrawSetOutline(playerid, buy_number_gai_p[5][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, buy_number_gai_p[5][playerid], 51);
		PlayerTextDrawFont(playerid, buy_number_gai_p[5][playerid], 1);
		PlayerTextDrawSetProportional(playerid, buy_number_gai_p[5][playerid], 1);
	}

	return true;
}

stock create_free_number_gai_p(playerid)
{
	if(free_number_gai_p[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		free_number_gai_p[0][playerid] = CreatePlayerTextDraw(playerid, 134.000000, 154.311126, "brilliantother:number_pl_ru_no_select"); // Texture element
		PlayerTextDrawLetterSize(playerid, free_number_gai_p[0][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, free_number_gai_p[0][playerid], 102.333335, 72.592575);
		PlayerTextDrawAlignment(playerid, free_number_gai_p[0][playerid], 2);
		PlayerTextDrawColor(playerid, free_number_gai_p[0][playerid], -1);
		PlayerTextDrawUseBox(playerid, free_number_gai_p[0][playerid], true);
		PlayerTextDrawBoxColor(playerid, free_number_gai_p[0][playerid], 0);
		PlayerTextDrawSetShadow(playerid, free_number_gai_p[0][playerid], 0);
		PlayerTextDrawSetOutline(playerid, free_number_gai_p[0][playerid], 0);
		PlayerTextDrawFont(playerid, free_number_gai_p[0][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, free_number_gai_p[0][playerid], true);
	}
	if(free_number_gai_p[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		free_number_gai_p[1][playerid] = CreatePlayerTextDraw(playerid, 225.333312, 153.481475, "brilliantother:number_pl_kz_no_select"); // Texture element
		PlayerTextDrawLetterSize(playerid, free_number_gai_p[1][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, free_number_gai_p[1][playerid], 102.333335, 72.592575);
		PlayerTextDrawAlignment(playerid, free_number_gai_p[1][playerid], 2);
		PlayerTextDrawColor(playerid, free_number_gai_p[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, free_number_gai_p[1][playerid], 0);
		PlayerTextDrawSetOutline(playerid, free_number_gai_p[1][playerid], 0);
		PlayerTextDrawFont(playerid, free_number_gai_p[1][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, free_number_gai_p[1][playerid], true);
	}
	if(free_number_gai_p[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		free_number_gai_p[2][playerid] = CreatePlayerTextDraw(playerid, 134.000000, 212.385177, "brilliantother:number_pl_by_no_select"); // Texture element
		PlayerTextDrawLetterSize(playerid, free_number_gai_p[2][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, free_number_gai_p[2][playerid], 102.333335, 72.592575);
		PlayerTextDrawAlignment(playerid, free_number_gai_p[2][playerid], 2);
		PlayerTextDrawColor(playerid, free_number_gai_p[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, free_number_gai_p[2][playerid], 0);
		PlayerTextDrawSetOutline(playerid, free_number_gai_p[2][playerid], 0);
		PlayerTextDrawFont(playerid, free_number_gai_p[2][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, free_number_gai_p[2][playerid], true);
	}
	if(free_number_gai_p[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		free_number_gai_p[3][playerid] = CreatePlayerTextDraw(playerid, 225.666687, 211.970352, "brilliantother:number_pl_ua_no_select"); // Texture element
		PlayerTextDrawLetterSize(playerid, free_number_gai_p[3][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, free_number_gai_p[3][playerid], 102.333335, 72.592575);
		PlayerTextDrawAlignment(playerid, free_number_gai_p[3][playerid], 2);
		PlayerTextDrawColor(playerid, free_number_gai_p[3][playerid], -1);
		PlayerTextDrawSetShadow(playerid, free_number_gai_p[3][playerid], 0);
		PlayerTextDrawSetOutline(playerid, free_number_gai_p[3][playerid], 0);
		PlayerTextDrawFont(playerid, free_number_gai_p[3][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, free_number_gai_p[3][playerid], true);
	}
	if(free_number_gai_p[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		free_number_gai_p[4][playerid] = CreatePlayerTextDraw(playerid, 316.666687, 154.725936, "brilliantother:number_pl_button_start_free"); // Texture element
		PlayerTextDrawLetterSize(playerid, free_number_gai_p[4][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, free_number_gai_p[4][playerid], 180.000045, 127.348136);
		PlayerTextDrawAlignment(playerid, free_number_gai_p[4][playerid], 2);
		PlayerTextDrawColor(playerid, free_number_gai_p[4][playerid], -1);
		PlayerTextDrawSetShadow(playerid, free_number_gai_p[4][playerid], 0);
		PlayerTextDrawSetOutline(playerid, free_number_gai_p[4][playerid], 0);
		PlayerTextDrawFont(playerid, free_number_gai_p[4][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, free_number_gai_p[4][playerid], true);
	}
	if(free_number_gai_p[5][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		free_number_gai_p[5][playerid] = CreatePlayerTextDraw(playerid, 140.666671, 302.399993, "brilliantother:number_pl_text_free_ramka"); // Texture element
		PlayerTextDrawLetterSize(playerid, free_number_gai_p[5][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, free_number_gai_p[5][playerid], 358.666687, 54.755554);
		PlayerTextDrawAlignment(playerid, free_number_gai_p[5][playerid], 2);
		PlayerTextDrawColor(playerid, free_number_gai_p[5][playerid], -1);
		PlayerTextDrawSetShadow(playerid, free_number_gai_p[5][playerid], 0);
		PlayerTextDrawSetOutline(playerid, free_number_gai_p[5][playerid], 0);
		PlayerTextDrawFont(playerid, free_number_gai_p[5][playerid], 4);
	}
	if(free_number_gai_p[6][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		free_number_gai_p[6][playerid] = CreatePlayerTextDraw(playerid, 315.333251, 305.303619, "111111111"); // Text element
		PlayerTextDrawLetterSize(playerid, free_number_gai_p[6][playerid], 1.024999, 4.669631);
		PlayerTextDrawAlignment(playerid, free_number_gai_p[6][playerid], 2);
		PlayerTextDrawColor(playerid, free_number_gai_p[6][playerid], -1);
		PlayerTextDrawUseBox(playerid, free_number_gai_p[6][playerid], true);
		PlayerTextDrawBoxColor(playerid, free_number_gai_p[6][playerid], 0);
		PlayerTextDrawSetShadow(playerid, free_number_gai_p[6][playerid], 0);
		PlayerTextDrawSetOutline(playerid, free_number_gai_p[6][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, free_number_gai_p[6][playerid], 51);
		PlayerTextDrawFont(playerid, free_number_gai_p[6][playerid], 2);
		PlayerTextDrawSetProportional(playerid, free_number_gai_p[6][playerid], 1);
	}

	return true;

}

stock create_veh_circle_electro(playerid)
{
	if(circle_menu_veh_electro[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		circle_menu_veh_electro[0][playerid] = CreatePlayerTextDraw(playerid, 508.666564, 227.318511, "brp:circle_veh_general_electro"); // Texture element
		PlayerTextDrawLetterSize(playerid, circle_menu_veh_electro[0][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, circle_menu_veh_electro[0][playerid], 86.333297, 181.274002);
		PlayerTextDrawAlignment(playerid, circle_menu_veh_electro[0][playerid], 1);
		PlayerTextDrawColor(playerid, circle_menu_veh_electro[0][playerid], -1);
		PlayerTextDrawSetShadow(playerid, circle_menu_veh_electro[0][playerid], 0);
		PlayerTextDrawSetOutline(playerid, circle_menu_veh_electro[0][playerid], 0);
		PlayerTextDrawFont(playerid, circle_menu_veh_electro[0][playerid], 4);
	}
	if(circle_menu_veh_electro[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		circle_menu_veh_electro[1][playerid] = CreatePlayerTextDraw(playerid, 533.333312, 227.318496, "brp:circle_veh_door_open"); // Texture element
		PlayerTextDrawLetterSize(playerid, circle_menu_veh_electro[1][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, circle_menu_veh_electro[1][playerid], 36.333297, 38.992614);
		PlayerTextDrawAlignment(playerid, circle_menu_veh_electro[1][playerid], 2);
		PlayerTextDrawColor(playerid, circle_menu_veh_electro[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, circle_menu_veh_electro[1][playerid], 0);
		PlayerTextDrawSetOutline(playerid, circle_menu_veh_electro[1][playerid], 0);
		PlayerTextDrawFont(playerid, circle_menu_veh_electro[1][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, circle_menu_veh_electro[1][playerid], true);
	}
	if(circle_menu_veh_electro[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		circle_menu_veh_electro[2][playerid] = CreatePlayerTextDraw(playerid, 543.000061, 259.674072, "brp:circle_veh_capot_close"); // Texture element
		PlayerTextDrawLetterSize(playerid, circle_menu_veh_electro[2][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, circle_menu_veh_electro[2][playerid], 16.999969, 19.911140);
		PlayerTextDrawAlignment(playerid, circle_menu_veh_electro[2][playerid], 2);
		PlayerTextDrawColor(playerid, circle_menu_veh_electro[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, circle_menu_veh_electro[2][playerid], 0);
		PlayerTextDrawSetOutline(playerid, circle_menu_veh_electro[2][playerid], 0);
		PlayerTextDrawFont(playerid, circle_menu_veh_electro[2][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, circle_menu_veh_electro[2][playerid], true);
	}
	if(circle_menu_veh_electro[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		circle_menu_veh_electro[3][playerid] = CreatePlayerTextDraw(playerid, 543.333435, 285.807525, "brp:circle_veh_bagage_open"); // Texture element
		PlayerTextDrawLetterSize(playerid, circle_menu_veh_electro[3][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, circle_menu_veh_electro[3][playerid], 16.666635, 13.274107);
		PlayerTextDrawAlignment(playerid, circle_menu_veh_electro[3][playerid], 2);
		PlayerTextDrawColor(playerid, circle_menu_veh_electro[3][playerid], -1);
		PlayerTextDrawSetShadow(playerid, circle_menu_veh_electro[3][playerid], 0);
		PlayerTextDrawSetOutline(playerid, circle_menu_veh_electro[3][playerid], 0);
		PlayerTextDrawFont(playerid, circle_menu_veh_electro[3][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, circle_menu_veh_electro[3][playerid], true);
	}
	if(circle_menu_veh_electro[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		circle_menu_veh_electro[4][playerid] = CreatePlayerTextDraw(playerid, 533.333312, 296.592712, "brp:circle_veh_light_on"); // Texture element
		PlayerTextDrawLetterSize(playerid, circle_menu_veh_electro[4][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, circle_menu_veh_electro[4][playerid], 36.666637, 37.333366);
		PlayerTextDrawAlignment(playerid, circle_menu_veh_electro[4][playerid], 2);
		PlayerTextDrawColor(playerid, circle_menu_veh_electro[4][playerid], -1);
		PlayerTextDrawSetShadow(playerid, circle_menu_veh_electro[4][playerid], 0);
		PlayerTextDrawSetOutline(playerid, circle_menu_veh_electro[4][playerid], 0);
		PlayerTextDrawFont(playerid, circle_menu_veh_electro[4][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, circle_menu_veh_electro[4][playerid], true);
	}
	if(circle_menu_veh_electro[5][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		circle_menu_veh_electro[5][playerid] = CreatePlayerTextDraw(playerid, 543.333374, 328.533508, "brp:circle_veh_eng_off"); // Texture element
		PlayerTextDrawLetterSize(playerid, circle_menu_veh_electro[5][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, circle_menu_veh_electro[5][playerid], 17.666637, 18.666702);
		PlayerTextDrawAlignment(playerid, circle_menu_veh_electro[5][playerid], 2);
		PlayerTextDrawColor(playerid, circle_menu_veh_electro[5][playerid], -1);
		PlayerTextDrawSetShadow(playerid, circle_menu_veh_electro[5][playerid], 0);
		PlayerTextDrawSetOutline(playerid, circle_menu_veh_electro[5][playerid], 0);
		PlayerTextDrawFont(playerid, circle_menu_veh_electro[5][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, circle_menu_veh_electro[5][playerid], true);
	}
	if(circle_menu_veh_electro[6][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		circle_menu_veh_electro[6][playerid] = CreatePlayerTextDraw(playerid, 539.000000, 358.814697, "brp:circle_veh_button_off"); // Texture element
		PlayerTextDrawLetterSize(playerid, circle_menu_veh_electro[6][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, circle_menu_veh_electro[6][playerid], 25.333374, 39.407409);
		PlayerTextDrawAlignment(playerid, circle_menu_veh_electro[6][playerid], 2);
		PlayerTextDrawColor(playerid, circle_menu_veh_electro[6][playerid], -1);
		PlayerTextDrawSetShadow(playerid, circle_menu_veh_electro[6][playerid], 0);
		PlayerTextDrawSetOutline(playerid, circle_menu_veh_electro[6][playerid], 0);
		PlayerTextDrawFont(playerid, circle_menu_veh_electro[6][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, circle_menu_veh_electro[6][playerid], true);
	}	
	return true;
}

stock create_veh_circle_dvs(playerid)
{
	if(circle_menu_veh_dvs[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		circle_menu_veh_dvs[0][playerid] = CreatePlayerTextDraw(playerid, 408.333282, 273.777862, "brp:circle_veh_general_dvs"); // Texture element
		PlayerTextDrawLetterSize(playerid, circle_menu_veh_dvs[0][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, circle_menu_veh_dvs[0][playerid], 216.000015, 133.985214);
		PlayerTextDrawAlignment(playerid, circle_menu_veh_dvs[0][playerid], 1);
		PlayerTextDrawColor(playerid, circle_menu_veh_dvs[0][playerid], -1);
		PlayerTextDrawSetShadow(playerid, circle_menu_veh_dvs[0][playerid], 0);
		PlayerTextDrawSetOutline(playerid, circle_menu_veh_dvs[0][playerid], 0);
		PlayerTextDrawFont(playerid, circle_menu_veh_dvs[0][playerid], 4);
	}
	if(circle_menu_veh_dvs[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		circle_menu_veh_dvs[1][playerid] = CreatePlayerTextDraw(playerid, 490.333374, 348.444458, "brp:circle_veh1_door_close"); // Texture element
		PlayerTextDrawLetterSize(playerid, circle_menu_veh_dvs[1][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, circle_menu_veh_dvs[1][playerid], 17.666687, 21.155548);
		PlayerTextDrawAlignment(playerid, circle_menu_veh_dvs[1][playerid], 2);
		PlayerTextDrawColor(playerid, circle_menu_veh_dvs[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, circle_menu_veh_dvs[1][playerid], 0);
		PlayerTextDrawSetOutline(playerid, circle_menu_veh_dvs[1][playerid], 0);
		PlayerTextDrawFont(playerid, circle_menu_veh_dvs[1][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, circle_menu_veh_dvs[1][playerid], true);
	}
	if(circle_menu_veh_dvs[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		circle_menu_veh_dvs[2][playerid] = CreatePlayerTextDraw(playerid, 512.000061, 348.859313, "brp:circle_veh1_capot_open"); // Texture element
		PlayerTextDrawLetterSize(playerid, circle_menu_veh_dvs[2][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, circle_menu_veh_dvs[2][playerid], 17.666687, 21.155548);
		PlayerTextDrawAlignment(playerid, circle_menu_veh_dvs[2][playerid], 2);
		PlayerTextDrawColor(playerid, circle_menu_veh_dvs[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, circle_menu_veh_dvs[2][playerid], 0);
		PlayerTextDrawSetOutline(playerid, circle_menu_veh_dvs[2][playerid], 0);
		PlayerTextDrawFont(playerid, circle_menu_veh_dvs[2][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, circle_menu_veh_dvs[2][playerid], true);
	}
	if(circle_menu_veh_dvs[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		circle_menu_veh_dvs[3][playerid] = CreatePlayerTextDraw(playerid, 533.666748, 349.274139, "brp:circle_veh1_bagage_open"); // Texture element
		PlayerTextDrawLetterSize(playerid, circle_menu_veh_dvs[3][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, circle_menu_veh_dvs[3][playerid], 17.666687, 21.155548);
		PlayerTextDrawAlignment(playerid, circle_menu_veh_dvs[3][playerid], 2);
		PlayerTextDrawColor(playerid, circle_menu_veh_dvs[3][playerid], -1);
		PlayerTextDrawSetShadow(playerid, circle_menu_veh_dvs[3][playerid], 0);
		PlayerTextDrawSetOutline(playerid, circle_menu_veh_dvs[3][playerid], 0);
		PlayerTextDrawFont(playerid, circle_menu_veh_dvs[3][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, circle_menu_veh_dvs[3][playerid], true);
	}
	if(circle_menu_veh_dvs[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		circle_menu_veh_dvs[4][playerid] = CreatePlayerTextDraw(playerid, 555.333251, 348.859313, "brp:circle_veh1_light_off"); // Texture element
		PlayerTextDrawLetterSize(playerid, circle_menu_veh_dvs[4][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, circle_menu_veh_dvs[4][playerid], 17.666687, 21.155548);
		PlayerTextDrawAlignment(playerid, circle_menu_veh_dvs[4][playerid], 2);
		PlayerTextDrawColor(playerid, circle_menu_veh_dvs[4][playerid], -1);
		PlayerTextDrawSetShadow(playerid, circle_menu_veh_dvs[4][playerid], 0);
		PlayerTextDrawSetOutline(playerid, circle_menu_veh_dvs[4][playerid], 0);
		PlayerTextDrawFont(playerid, circle_menu_veh_dvs[4][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, circle_menu_veh_dvs[4][playerid], true);

	}
	return true;
}

stock create_autoschool_select_auto()
{
	autoschool_info_td_1[0] = TextDrawCreate(158.666717, 111.999977, "brilliantother:info_school_auto_1"); // Texture element
	TextDrawLetterSize(autoschool_info_td_1[0], 0.000000, 0.000000);
	TextDrawTextSize(autoschool_info_td_1[0], 320.000061, 258.844482);
	TextDrawAlignment(autoschool_info_td_1[0], 2);
	TextDrawColor(autoschool_info_td_1[0], -1);
	TextDrawSetShadow(autoschool_info_td_1[0], 0);
	TextDrawSetOutline(autoschool_info_td_1[0], 0);
	TextDrawFont(autoschool_info_td_1[0], 4);

	autoschool_info_td_1[1] = TextDrawCreate(444.000000, 122.785186, "brilliantother:info_school_close_2"); // Texture element
	TextDrawLetterSize(autoschool_info_td_1[1], 0.000000, 0.000000);
	TextDrawTextSize(autoschool_info_td_1[1], 18.666656, 22.399993);
	TextDrawAlignment(autoschool_info_td_1[1], 2);
	TextDrawColor(autoschool_info_td_1[1], -1);
	TextDrawSetShadow(autoschool_info_td_1[1], 0);
	TextDrawSetOutline(autoschool_info_td_1[1], 0);
	TextDrawFont(autoschool_info_td_1[1], 4);
	TextDrawSetSelectable(autoschool_info_td_1[1], true);

	return true;
}

stock create_load_screen_p()
{
	load_screen[0] = TextDrawCreate(-43.333351, -2.903701, "brilliantother:screen_load_texture_1"); // Texture element
	TextDrawLetterSize(load_screen[0], 0.000000, 0.000000);
	TextDrawTextSize(load_screen[0], 728.666381, 456.296386);
	TextDrawAlignment(load_screen[0], 1);
	TextDrawColor(load_screen[0], -1);
	TextDrawSetShadow(load_screen[0], 0);
	TextDrawSetOutline(load_screen[0], 0);
	TextDrawFont(load_screen[0], 4);

	load_screen[1] = TextDrawCreate(-43.333351, -2.903701, "brilliantother:screen_load_texture_2"); // Texture element
	TextDrawLetterSize(load_screen[1], 0.000000, 0.000000);
	TextDrawTextSize(load_screen[1], 728.666381, 456.296386);
	TextDrawAlignment(load_screen[1], 1);
	TextDrawColor(load_screen[1], -1);
	TextDrawSetShadow(load_screen[1], 0);
	TextDrawSetOutline(load_screen[1], 0);
	TextDrawFont(load_screen[1], 4);

	load_screen[2] = TextDrawCreate(-43.333351, -2.903701, "brilliantother:screen_load_texture_3"); // Texture element
	TextDrawLetterSize(load_screen[2], 0.000000, 0.000000);
	TextDrawTextSize(load_screen[2], 728.666381, 456.296386);
	TextDrawAlignment(load_screen[2], 1);
	TextDrawColor(load_screen[2], -1);
	TextDrawSetShadow(load_screen[2], 0);
	TextDrawSetOutline(load_screen[2], 0);
	TextDrawFont(load_screen[2], 4);

	return true;
}

stock create_autoschool_select_vert()
{
	autoschool_info_td_2[0] = TextDrawCreate(158.666717, 111.999977, "brilliantother:info_school_vert_1"); // Texture element
	TextDrawLetterSize(autoschool_info_td_2[0], 0.000000, 0.000000);
	TextDrawTextSize(autoschool_info_td_2[0], 320.000061, 258.844482);
	TextDrawAlignment(autoschool_info_td_2[0], 2);
	TextDrawColor(autoschool_info_td_2[0], -1);
	TextDrawSetShadow(autoschool_info_td_2[0], 0);
	TextDrawSetOutline(autoschool_info_td_2[0], 0);
	TextDrawFont(autoschool_info_td_2[0], 4);

	autoschool_info_td_2[1] = TextDrawCreate(444.000000, 122.785186, "brilliantother:info_school_close_2"); // Texture element
	TextDrawLetterSize(autoschool_info_td_2[1], 0.000000, 0.000000);
	TextDrawTextSize(autoschool_info_td_2[1], 18.666656, 22.399993);
	TextDrawAlignment(autoschool_info_td_2[1], 2);
	TextDrawColor(autoschool_info_td_2[1], -1);
	TextDrawSetShadow(autoschool_info_td_2[1], 0);
	TextDrawSetOutline(autoschool_info_td_2[1], 0);
	TextDrawFont(autoschool_info_td_2[1], 4);
	TextDrawSetSelectable(autoschool_info_td_2[1], true);

	return true;
}

stock create_autoschool_select_aqua()
{
	autoschool_info_td_3[0] = TextDrawCreate(158.666717, 111.999977, "brilliantother:info_school_aqua_1"); // Texture element
	TextDrawLetterSize(autoschool_info_td_3[0], 0.000000, 0.000000);
	TextDrawTextSize(autoschool_info_td_3[0], 320.000061, 258.844482);
	TextDrawAlignment(autoschool_info_td_3[0], 2);
	TextDrawColor(autoschool_info_td_3[0], -1);
	TextDrawSetShadow(autoschool_info_td_3[0], 0);
	TextDrawSetOutline(autoschool_info_td_3[0], 0);
	TextDrawFont(autoschool_info_td_3[0], 4);

	autoschool_info_td_3[1] = TextDrawCreate(444.000000, 122.785186, "brilliantother:info_school_close_2"); // Texture element
	TextDrawLetterSize(autoschool_info_td_3[1], 0.000000, 0.000000);
	TextDrawTextSize(autoschool_info_td_3[1], 18.666656, 22.399993);
	TextDrawAlignment(autoschool_info_td_3[1], 2);
	TextDrawColor(autoschool_info_td_3[1], -1);
	TextDrawSetShadow(autoschool_info_td_3[1], 0);
	TextDrawSetOutline(autoschool_info_td_3[1], 0);
	TextDrawFont(autoschool_info_td_3[1], 4);
	TextDrawSetSelectable(autoschool_info_td_3[1], true);

	return true;
}

stock create_autoschool_panel_general()
{
	autoschool_info_td[0] = TextDrawCreate(160.333206, 113.244407, "brilliantother:info_school_back"); // Texture element
	TextDrawLetterSize(autoschool_info_td[0], 0.000000, 0.000000);
	TextDrawTextSize(autoschool_info_td[0], 318.000305, 256.355529);
	TextDrawAlignment(autoschool_info_td[0], 1);
	TextDrawColor(autoschool_info_td[0], -1);
	TextDrawSetShadow(autoschool_info_td[0], 0);
	TextDrawSetOutline(autoschool_info_td[0], 0);
	TextDrawFont(autoschool_info_td[0], 4);

	autoschool_info_td[1] = TextDrawCreate(187.999954, 124.444442, "brilliantother:info_school_name"); // Texture element
	TextDrawLetterSize(autoschool_info_td[1], 0.000000, 0.000000);
	TextDrawTextSize(autoschool_info_td[1], 81.000045, 45.214790);
	TextDrawAlignment(autoschool_info_td[1], 1);
	TextDrawColor(autoschool_info_td[1], -1);
	TextDrawSetShadow(autoschool_info_td[1], 0);
	TextDrawSetOutline(autoschool_info_td[1], 0);
	TextDrawFont(autoschool_info_td[1], 4);

	autoschool_info_td[2] = TextDrawCreate(279.666656, 124.444450, "brilliantother:info_school"); // Texture element
	TextDrawLetterSize(autoschool_info_td[2], 0.000000, 0.000000);
	TextDrawTextSize(autoschool_info_td[2], 146.333282, 40.651840);
	TextDrawAlignment(autoschool_info_td[2], 1);
	TextDrawColor(autoschool_info_td[2], -1);
	TextDrawSetShadow(autoschool_info_td[2], 0);
	TextDrawSetOutline(autoschool_info_td[2], 0);
	TextDrawFont(autoschool_info_td[2], 4);

	autoschool_info_td[3] = TextDrawCreate(444.666656, 124.444473, "brilliantother:info_school_close"); // Texture element
	TextDrawLetterSize(autoschool_info_td[3], 0.000000, 0.000000);
	TextDrawTextSize(autoschool_info_td[3], 17.000026, 19.911127);
	TextDrawAlignment(autoschool_info_td[3], 2);
	TextDrawColor(autoschool_info_td[3], -1);
	TextDrawSetShadow(autoschool_info_td[3], 0);
	TextDrawSetOutline(autoschool_info_td[3], 0);
	TextDrawFont(autoschool_info_td[3], 4);
	TextDrawSetSelectable(autoschool_info_td[3], true);

	autoschool_info_td[4] = TextDrawCreate(183.333343, 188.740737, "brilliantother:info_school_auto"); // Texture element
	TextDrawLetterSize(autoschool_info_td[4], 0.000000, 0.000000);
	TextDrawTextSize(autoschool_info_td[4], 273.000000, 82.962959);
	TextDrawAlignment(autoschool_info_td[4], 2);
	TextDrawColor(autoschool_info_td[4], -1);
	TextDrawSetShadow(autoschool_info_td[4], 0);
	TextDrawSetOutline(autoschool_info_td[4], 0);
	TextDrawFont(autoschool_info_td[4], 4);
	TextDrawSetSelectable(autoschool_info_td[4], true);

	autoschool_info_td[5] = TextDrawCreate(187.999984, 271.288879, "brilliantother:info_school_vert"); // Texture element
	TextDrawLetterSize(autoschool_info_td[5], 0.000000, 0.000000);
	TextDrawTextSize(autoschool_info_td[5], 129.333343, 69.274078);
	TextDrawAlignment(autoschool_info_td[5], 2);
	TextDrawColor(autoschool_info_td[5], -1);
	TextDrawSetShadow(autoschool_info_td[5], 0);
	TextDrawSetOutline(autoschool_info_td[5], 0);
	TextDrawFont(autoschool_info_td[5], 4);
	TextDrawSetSelectable(autoschool_info_td[5], true);

	autoschool_info_td[6] = TextDrawCreate(321.000000, 271.288848, "brilliantother:info_school_aqua"); // Texture element
	TextDrawLetterSize(autoschool_info_td[6], 0.000000, 0.000000);
	TextDrawTextSize(autoschool_info_td[6], 129.333343, 69.274078);
	TextDrawAlignment(autoschool_info_td[6], 2);
	TextDrawColor(autoschool_info_td[6], -1);
	TextDrawSetShadow(autoschool_info_td[6], 0);
	TextDrawSetOutline(autoschool_info_td[6], 0);
	TextDrawFont(autoschool_info_td[6], 4);
	TextDrawSetSelectable(autoschool_info_td[6], true);

	return true;
}

stock create_phone_td()
{
	phone_general_player[0] = TextDrawCreate(352.000000, 65.000000, "brilliantphone:phone_td_samsung");
	TextDrawTextSize(phone_general_player[0], 337.000000, 375.000000);
	TextDrawAlignment(phone_general_player[0], 1);
	TextDrawColor(phone_general_player[0], -1);
	TextDrawBackgroundColor(phone_general_player[0], 255);
	TextDrawFont(phone_general_player[0], 4);
	TextDrawSetProportional(phone_general_player[0], 0);

	phone_general_player[1] = TextDrawCreate(468.000000, 123.000000, "brilliantphone:phone_td_appyandexgo");
	TextDrawTextSize(phone_general_player[1], 28.000000, 68.000000);
	TextDrawAlignment(phone_general_player[1], 1);
	TextDrawColor(phone_general_player[1], -1);
	TextDrawBackgroundColor(phone_general_player[1], 255);
	TextDrawFont(phone_general_player[1], 4);
	TextDrawSetProportional(phone_general_player[1], 0);
	TextDrawSetSelectable(phone_general_player[1], true);

	phone_general_player[2] = TextDrawCreate(504.000000, 123.000000, "brilliantphone:phone_td_appuber");
	TextDrawTextSize(phone_general_player[2], 28.000000, 68.000000);
	TextDrawAlignment(phone_general_player[2], 1);
	TextDrawColor(phone_general_player[2], -1);
	TextDrawBackgroundColor(phone_general_player[2], 255);
	TextDrawFont(phone_general_player[2], 4);
	TextDrawSetProportional(phone_general_player[2], 0);
	TextDrawSetSelectable(phone_general_player[2], true);

	phone_general_player[3] = TextDrawCreate(541.000000, 123.000000, "brilliantphone:phone_td_appcmobile");
	TextDrawTextSize(phone_general_player[3], 28.000000, 68.000000);
	TextDrawAlignment(phone_general_player[3], 1);
	TextDrawColor(phone_general_player[3], -1);
	TextDrawBackgroundColor(phone_general_player[3], 255);
	TextDrawFont(phone_general_player[3], 4);
	TextDrawSetProportional(phone_general_player[3], 0);
	TextDrawSetSelectable(phone_general_player[3], true);

	phone_general_player[4] = TextDrawCreate(468.000000, 203.000000, "brilliantphone:phone_td_appsberbank");
	TextDrawTextSize(phone_general_player[4], 28.000000, 68.000000);
	TextDrawAlignment(phone_general_player[4], 1);
	TextDrawColor(phone_general_player[4], -1);
	TextDrawBackgroundColor(phone_general_player[4], 255);
	TextDrawFont(phone_general_player[4], 4);
	TextDrawSetProportional(phone_general_player[4], 0);
	TextDrawSetSelectable(phone_general_player[4], true);

	phone_general_player[5] = TextDrawCreate(504.000000, 203.000000, "brilliantphone:phone_td_appcalendar");
	TextDrawTextSize(phone_general_player[5], 28.000000, 68.000000);
	TextDrawAlignment(phone_general_player[5], 1);
	TextDrawColor(phone_general_player[5], -1);
	TextDrawBackgroundColor(phone_general_player[5], 255);
	TextDrawFont(phone_general_player[5], 4);
	TextDrawSetProportional(phone_general_player[5], 0);
	TextDrawSetSelectable(phone_general_player[5], true);

	phone_general_player[6] = TextDrawCreate(541.000000, 203.000000, "brilliantphone:phone_td_appnotes");
	TextDrawTextSize(phone_general_player[6], 28.000000, 68.000000);
	TextDrawAlignment(phone_general_player[6], 1);
	TextDrawColor(phone_general_player[6], -1);
	TextDrawBackgroundColor(phone_general_player[6], 255);
	TextDrawFont(phone_general_player[6], 4);
	TextDrawSetProportional(phone_general_player[6], 0);
	TextDrawSetSelectable(phone_general_player[6], true);

	phone_general_player[7] = TextDrawCreate(468.000000, 273.000000, "brilliantphone:phone_td_appsettings");
	TextDrawTextSize(phone_general_player[7], 28.000000, 68.000000);
	TextDrawAlignment(phone_general_player[7], 1);
	TextDrawColor(phone_general_player[7], -1);
	TextDrawBackgroundColor(phone_general_player[7], 255);
	TextDrawFont(phone_general_player[7], 4);
	TextDrawSetProportional(phone_general_player[7], 0);
	TextDrawSetSelectable(phone_general_player[7], true);
	return true;
}

stock create_phone_general_p(playerid)
{
	if(phone_background_info[playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		phone_background_info[playerid] = CreatePlayerTextDraw(playerid, 352.000000, 65.000000, "brilliantphone:phone_td_bg1");
		PlayerTextDrawTextSize(playerid, phone_background_info[playerid], 337.000000, 373.000000);
		PlayerTextDrawAlignment(playerid, phone_background_info[playerid], 1);
		PlayerTextDrawColor(playerid, phone_background_info[playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, phone_background_info[playerid], 255);
		PlayerTextDrawFont(playerid, phone_background_info[playerid], 4);
		PlayerTextDrawSetProportional(playerid, phone_background_info[playerid], 0);

	}

	return true;
}

stock create_factory_job_1()
{
	factory_job_1[0] = TextDrawCreate(-1.000000, -1.000000, "furniturejob:fjui_bg");
	TextDrawTextSize(factory_job_1[0], 644.000000, 451.000000);
	TextDrawAlignment(factory_job_1[0], 1);
	TextDrawColor(factory_job_1[0], -1);
	TextDrawBackgroundColor(factory_job_1[0], 255);
	TextDrawFont(factory_job_1[0], 4);
	TextDrawSetProportional(factory_job_1[0], 0);

	factory_job_1[1] = TextDrawCreate(530.000000, 36.000000, "furniturejob:fjui_exit");
	TextDrawTextSize(factory_job_1[1], 34.000000, 25.000000);
	TextDrawAlignment(factory_job_1[1], 1);
	TextDrawColor(factory_job_1[1], -1);
	TextDrawBackgroundColor(factory_job_1[1], 255);
	TextDrawFont(factory_job_1[1], 4);
	TextDrawSetProportional(factory_job_1[1], 0);
	TextDrawSetSelectable(factory_job_1[1], true);

	return true;
}

stock create_factory_job_2()
{
	factory_job_2[0] = TextDrawCreate(-1.000000, -1.000000, "locksmithjob:lsui_bg");
	TextDrawTextSize(factory_job_2[0], 644.000000, 451.000000);
	TextDrawAlignment(factory_job_2[0], 1);
	TextDrawColor(factory_job_2[0], -1);
	TextDrawBackgroundColor(factory_job_2[0], 255);
	TextDrawFont(factory_job_2[0], 4);
	TextDrawSetProportional(factory_job_2[0], 0);

	factory_job_2[1] = TextDrawCreate(530.000000, 36.000000, "locksmithjob:lsui_exit");
	TextDrawTextSize(factory_job_2[1], 34.000000, 25.000000);
	TextDrawAlignment(factory_job_2[1], 1);
	TextDrawColor(factory_job_2[1], -1);
	TextDrawBackgroundColor(factory_job_2[1], 255);
	TextDrawFont(factory_job_2[1], 4);
	TextDrawSetProportional(factory_job_2[1], 0);
	TextDrawSetSelectable(factory_job_2[1], true);

	return true;

}

stock create_factory_mith_5_p(playerid)
{
	if(factory_job_two_5_p[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_5_p[0][playerid] = CreatePlayerTextDraw(playerid, 127.599990, 37.300010, "x1");
		PlayerTextDrawLetterSize(playerid, factory_job_two_5_p[0][playerid], 0.443666, 2.039700);
		PlayerTextDrawAlignment(playerid, factory_job_two_5_p[0][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_5_p[0][playerid], 1962902271);
		PlayerTextDrawSetShadow(playerid, factory_job_two_5_p[0][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_5_p[0][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_5_p[0][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_two_5_p[0][playerid], 1);
	}
	if(factory_job_two_5_p[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_5_p[1][playerid] = CreatePlayerTextDraw(playerid, 319.999938, 68.000015, "+_12312");
		PlayerTextDrawLetterSize(playerid, factory_job_two_5_p[1][playerid], 0.574998, 2.678518);
		PlayerTextDrawTextSize(playerid, factory_job_two_5_p[1][playerid], 0.000000, 513.360351);
		PlayerTextDrawAlignment(playerid, factory_job_two_5_p[1][playerid], 2);
		PlayerTextDrawColor(playerid, factory_job_two_5_p[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, factory_job_two_5_p[1][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_5_p[1][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_5_p[1][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_two_5_p[1][playerid], 1);
	}
	if(factory_job_two_5_p[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_5_p[2][playerid] = CreatePlayerTextDraw(playerid, 349.000000, 363.000000, "0000000");
		PlayerTextDrawLetterSize(playerid, factory_job_two_5_p[2][playerid], 0.554332, 2.309334);
		PlayerTextDrawAlignment(playerid, factory_job_two_5_p[2][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_5_p[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, factory_job_two_5_p[2][playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_5_p[2][playerid], 30);
		PlayerTextDrawFont(playerid, factory_job_two_5_p[2][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_two_5_p[2][playerid], 1);
	}
	if(factory_job_two_5_p[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_5_p[3][playerid] = CreatePlayerTextDraw(playerid, 230.299911, 137.000000, "locksmithjob:lsui_glock1");
		PlayerTextDrawTextSize(playerid, factory_job_two_5_p[3][playerid], 92.000000, 51.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_5_p[3][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_5_p[3][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_5_p[3][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_5_p[3][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_5_p[3][playerid], 0);
	}
	if(factory_job_two_5_p[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_5_p[4][playerid] = CreatePlayerTextDraw(playerid, 322.199798, 137.000000, "locksmithjob:lsui_glock2");
		PlayerTextDrawTextSize(playerid, factory_job_two_5_p[4][playerid], 92.000000, 51.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_5_p[4][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_5_p[4][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_5_p[4][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_5_p[4][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_5_p[4][playerid], 0);
	}
	if(factory_job_two_5_p[5][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_5_p[5][playerid] = CreatePlayerTextDraw(playerid, 230.299911, 187.999847, "locksmithjob:lsui_glock3");
		PlayerTextDrawTextSize(playerid, factory_job_two_5_p[5][playerid], 92.000000, 51.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_5_p[5][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_5_p[5][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_5_p[5][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_5_p[5][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_5_p[5][playerid], 0);
	}
	if(factory_job_two_5_p[6][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_5_p[6][playerid] = CreatePlayerTextDraw(playerid, 322.199798, 187.999847, "locksmithjob:lsui_glock4");
		PlayerTextDrawTextSize(playerid, factory_job_two_5_p[6][playerid], 92.000000, 51.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_5_p[6][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_5_p[6][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_5_p[6][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_5_p[6][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_5_p[6][playerid], 0);
	}
	if(factory_job_two_5_p[7][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_5_p[7][playerid] = CreatePlayerTextDraw(playerid, 230.299911, 239.000015, "locksmithjob:lsui_glock5");
		PlayerTextDrawTextSize(playerid, factory_job_two_5_p[7][playerid], 92.000000, 51.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_5_p[7][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_5_p[7][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_5_p[7][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_5_p[7][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_5_p[7][playerid], 0);
	}
	if(factory_job_two_5_p[8][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_5_p[8][playerid] = CreatePlayerTextDraw(playerid, 322.199798, 239.000015, "locksmithjob:lsui_glock6");
		PlayerTextDrawTextSize(playerid, factory_job_two_5_p[8][playerid], 92.000000, 51.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_5_p[8][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_5_p[8][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_5_p[8][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_5_p[8][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_5_p[8][playerid], 0);
	}
	if(factory_job_two_5_p[9][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_5_p[9][playerid] = CreatePlayerTextDraw(playerid, 102.299980, 122.000000, "locksmithjob:lsui_clock4");
		PlayerTextDrawTextSize(playerid, factory_job_two_5_p[9][playerid], 92.000000, 51.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_5_p[9][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_5_p[9][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_5_p[9][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_5_p[9][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_5_p[9][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_two_5_p[9][playerid], true);
	}
	if(factory_job_two_5_p[10][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_5_p[10][playerid] = CreatePlayerTextDraw(playerid, 102.299980, 194.699920, "locksmithjob:lsui_clock2");
		PlayerTextDrawTextSize(playerid, factory_job_two_5_p[10][playerid], 92.000000, 51.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_5_p[10][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_5_p[10][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_5_p[10][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_5_p[10][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_5_p[10][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_two_5_p[10][playerid], true);
	}
	if(factory_job_two_5_p[11][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_5_p[11][playerid] = CreatePlayerTextDraw(playerid, 102.299980, 265.699920, "locksmithjob:lsui_clock6");
		PlayerTextDrawTextSize(playerid, factory_job_two_5_p[11][playerid], 92.000000, 51.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_5_p[11][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_5_p[11][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_5_p[11][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_5_p[11][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_5_p[11][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_two_5_p[11][playerid], true);
	}
	if(factory_job_two_5_p[12][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_5_p[12][playerid] = CreatePlayerTextDraw(playerid, 447.800079, 122.000000, "locksmithjob:lsui_clock1");
		PlayerTextDrawTextSize(playerid, factory_job_two_5_p[12][playerid], 92.000000, 51.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_5_p[12][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_5_p[12][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_5_p[12][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_5_p[12][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_5_p[12][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_two_5_p[12][playerid], true);
	}
	if(factory_job_two_5_p[13][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_5_p[13][playerid] = CreatePlayerTextDraw(playerid, 447.800079, 194.699920, "locksmithjob:lsui_clock3");
		PlayerTextDrawTextSize(playerid, factory_job_two_5_p[13][playerid], 92.000000, 51.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_5_p[13][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_5_p[13][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_5_p[13][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_5_p[13][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_5_p[13][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_two_5_p[13][playerid], true);
	}
	if(factory_job_two_5_p[14][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_5_p[14][playerid] = CreatePlayerTextDraw(playerid, 447.800079, 265.699920, "locksmithjob:lsui_clock5");
		PlayerTextDrawTextSize(playerid, factory_job_two_5_p[14][playerid], 92.000000, 51.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_5_p[14][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_5_p[14][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_5_p[14][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_5_p[14][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_5_p[14][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_two_5_p[14][playerid], true);
	}
	if(factory_job_two_5_p[15][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_5_p[15][playerid] = CreatePlayerTextDraw(playerid, 208.300079, 361.199951, "furniturejob:fjui_p1");
		PlayerTextDrawTextSize(playerid, factory_job_two_5_p[15][playerid], 87.699928, 29.110000);
		PlayerTextDrawAlignment(playerid, factory_job_two_5_p[15][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_5_p[15][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_5_p[15][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_5_p[15][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_5_p[15][playerid], 0);
	}
	return true;
}

stock create_factory_mith_4_p(playerid)
{
	if(factory_job_two_4_p[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_4_p[0][playerid] = CreatePlayerTextDraw(playerid, 127.599990, 37.300010, "x1");
		PlayerTextDrawLetterSize(playerid, factory_job_two_4_p[0][playerid], 0.443666, 2.039700);
		PlayerTextDrawAlignment(playerid, factory_job_two_4_p[0][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_4_p[0][playerid], 1962902271);
		PlayerTextDrawSetShadow(playerid, factory_job_two_4_p[0][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_4_p[0][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_4_p[0][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_two_4_p[0][playerid], 1);
	}
	if(factory_job_two_4_p[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_4_p[1][playerid] = CreatePlayerTextDraw(playerid, 319.999938, 68.000015, "+_12312");
		PlayerTextDrawLetterSize(playerid, factory_job_two_4_p[1][playerid], 0.574998, 2.678518);
		PlayerTextDrawTextSize(playerid, factory_job_two_4_p[1][playerid], 0.000000, 513.360351);
		PlayerTextDrawAlignment(playerid, factory_job_two_4_p[1][playerid], 2);
		PlayerTextDrawColor(playerid, factory_job_two_4_p[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, factory_job_two_4_p[1][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_4_p[1][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_4_p[1][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_two_4_p[1][playerid], 1);
	}
	if(factory_job_two_4_p[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_4_p[2][playerid] = CreatePlayerTextDraw(playerid, 349.000000, 363.000000, "0000000");
		PlayerTextDrawLetterSize(playerid, factory_job_two_4_p[2][playerid], 0.554332, 2.309334);
		PlayerTextDrawAlignment(playerid, factory_job_two_4_p[2][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_4_p[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, factory_job_two_4_p[2][playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_4_p[2][playerid], 30);
		PlayerTextDrawFont(playerid, factory_job_two_4_p[2][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_two_4_p[2][playerid], 1);
	}
	if(factory_job_two_4_p[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_4_p[3][playerid] = CreatePlayerTextDraw(playerid, 287.000000, 119.000000, "locksmithjob:lsui_gsdoor1");
		PlayerTextDrawTextSize(playerid, factory_job_two_4_p[3][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_4_p[3][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_4_p[3][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_4_p[3][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_4_p[3][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_4_p[3][playerid], 0);
	}
	if(factory_job_two_4_p[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_4_p[4][playerid] = CreatePlayerTextDraw(playerid, 323.000000, 119.000000, "locksmithjob:lsui_gsdoor2");
		PlayerTextDrawTextSize(playerid, factory_job_two_4_p[4][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_4_p[4][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_4_p[4][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_4_p[4][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_4_p[4][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_4_p[4][playerid], 0);
	}
	if(factory_job_two_4_p[5][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_4_p[5][playerid] = CreatePlayerTextDraw(playerid, 287.000000, 179.000000, "locksmithjob:lsui_gsdoor3");
		PlayerTextDrawTextSize(playerid, factory_job_two_4_p[5][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_4_p[5][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_4_p[5][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_4_p[5][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_4_p[5][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_4_p[5][playerid], 0);
	}
	if(factory_job_two_4_p[6][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_4_p[6][playerid] = CreatePlayerTextDraw(playerid, 323.000000, 179.000000, "locksmithjob:lsui_gsdoor4");
		PlayerTextDrawTextSize(playerid, factory_job_two_4_p[6][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_4_p[6][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_4_p[6][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_4_p[6][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_4_p[6][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_4_p[6][playerid], 0);
	}
	if(factory_job_two_4_p[7][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_4_p[7][playerid] = CreatePlayerTextDraw(playerid, 287.000000, 239.000000, "locksmithjob:lsui_gsdoor5");
		PlayerTextDrawTextSize(playerid, factory_job_two_4_p[7][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_4_p[7][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_4_p[7][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_4_p[7][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_4_p[7][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_4_p[7][playerid], 0);
	}
	if(factory_job_two_4_p[8][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_4_p[8][playerid] = CreatePlayerTextDraw(playerid, 323.000000, 239.000000, "locksmithjob:lsui_gsdoor6");
		PlayerTextDrawTextSize(playerid, factory_job_two_4_p[8][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_4_p[8][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_4_p[8][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_4_p[8][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_4_p[8][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_4_p[8][playerid], 0);
	}
	if(factory_job_two_4_p[9][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_4_p[9][playerid] = CreatePlayerTextDraw(playerid, 287.000000, 193.000000, "locksmithjob:lsui_gsdoorlock");
		PlayerTextDrawTextSize(playerid, factory_job_two_4_p[9][playerid], 26.600002, 44.399993);
		PlayerTextDrawAlignment(playerid, factory_job_two_4_p[9][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_4_p[9][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_4_p[9][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_4_p[9][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_4_p[9][playerid], 0);
	}
	if(factory_job_two_4_p[10][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_4_p[10][playerid] = CreatePlayerTextDraw(playerid, 136.999984, 120.755554, "locksmithjob:lsui_csdoor4");
		PlayerTextDrawTextSize(playerid, factory_job_two_4_p[10][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_4_p[10][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_4_p[10][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_4_p[10][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_4_p[10][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_4_p[10][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_two_4_p[10][playerid], true);
	}
	if(factory_job_two_4_p[11][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_4_p[11][playerid] = CreatePlayerTextDraw(playerid, 136.999984, 193.455474, "locksmithjob:lsui_csdoor2");
		PlayerTextDrawTextSize(playerid, factory_job_two_4_p[11][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_4_p[11][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_4_p[11][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_4_p[11][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_4_p[11][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_4_p[11][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_two_4_p[11][playerid], true);
	}
	if(factory_job_two_4_p[12][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_4_p[12][playerid] = CreatePlayerTextDraw(playerid, 136.999984, 264.455474, "locksmithjob:lsui_csdoor6");
		PlayerTextDrawTextSize(playerid, factory_job_two_4_p[12][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_4_p[12][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_4_p[12][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_4_p[12][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_4_p[12][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_4_p[12][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_two_4_p[12][playerid], true);
	}
	if(factory_job_two_4_p[13][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_4_p[13][playerid] = CreatePlayerTextDraw(playerid, 452.299926, 120.755554, "locksmithjob:lsui_csdoor1");
		PlayerTextDrawTextSize(playerid, factory_job_two_4_p[13][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_4_p[13][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_4_p[13][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_4_p[13][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_4_p[13][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_4_p[13][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_two_4_p[13][playerid], true);
	}
	if(factory_job_two_4_p[14][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_4_p[14][playerid] = CreatePlayerTextDraw(playerid, 452.299926, 193.455474, "locksmithjob:lsui_csdoor3");
		PlayerTextDrawTextSize(playerid, factory_job_two_4_p[14][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_4_p[14][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_4_p[14][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_4_p[14][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_4_p[14][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_4_p[14][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_two_4_p[14][playerid], true);
	}
	if(factory_job_two_4_p[15][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_4_p[15][playerid] = CreatePlayerTextDraw(playerid, 452.299926, 264.455474, "locksmithjob:lsui_csdoor5");
		PlayerTextDrawTextSize(playerid, factory_job_two_4_p[15][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_4_p[15][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_4_p[15][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_4_p[15][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_4_p[15][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_4_p[15][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_two_4_p[15][playerid], true);
	}
	if(factory_job_two_4_p[16][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_4_p[16][playerid] = CreatePlayerTextDraw(playerid, 512.000000, 206.000000, "locksmithjob:lsui_csdoorlock");
		PlayerTextDrawTextSize(playerid, factory_job_two_4_p[16][playerid], 18.900014, 33.199996);
		PlayerTextDrawAlignment(playerid, factory_job_two_4_p[16][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_4_p[16][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_4_p[16][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_4_p[16][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_4_p[16][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_two_4_p[16][playerid], true);
	}
	if(factory_job_two_4_p[17][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_4_p[17][playerid] = CreatePlayerTextDraw(playerid, 208.300079, 361.199951, "furniturejob:fjui_p1");
		PlayerTextDrawTextSize(playerid, factory_job_two_4_p[17][playerid], 87.699928, 29.110000);
		PlayerTextDrawAlignment(playerid, factory_job_two_4_p[17][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_4_p[17][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_4_p[17][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_4_p[17][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_4_p[17][playerid], 0);
	}
	return true;
}

stock create_factory_mith_3_p(playerid)
{
	if(factory_job_two_2_p[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_3_p[0][playerid] = CreatePlayerTextDraw(playerid, 127.599990, 37.300010, "x1");
		PlayerTextDrawLetterSize(playerid, factory_job_two_3_p[0][playerid], 0.443666, 2.039700);
		PlayerTextDrawAlignment(playerid, factory_job_two_3_p[0][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_3_p[0][playerid], 1962902271);
		PlayerTextDrawSetShadow(playerid, factory_job_two_3_p[0][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_3_p[0][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_3_p[0][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_two_3_p[0][playerid], 1);
	}
	if(factory_job_two_3_p[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_3_p[1][playerid] = CreatePlayerTextDraw(playerid, 319.999938, 68.000015, "+_12312");
		PlayerTextDrawLetterSize(playerid, factory_job_two_3_p[1][playerid], 0.574998, 2.678518);
		PlayerTextDrawTextSize(playerid, factory_job_two_3_p[1][playerid], 0.000000, 513.360351);
		PlayerTextDrawAlignment(playerid, factory_job_two_3_p[1][playerid], 2);
		PlayerTextDrawColor(playerid, factory_job_two_3_p[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, factory_job_two_3_p[1][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_3_p[1][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_3_p[1][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_two_3_p[1][playerid], 1);
	}
	if(factory_job_two_3_p[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_3_p[2][playerid] = CreatePlayerTextDraw(playerid, 349.000000, 363.000000, "0000000");
		PlayerTextDrawLetterSize(playerid, factory_job_two_3_p[2][playerid], 0.554332, 2.309334);
		PlayerTextDrawAlignment(playerid, factory_job_two_3_p[2][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_3_p[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, factory_job_two_3_p[2][playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_3_p[2][playerid], 30);
		PlayerTextDrawFont(playerid, factory_job_two_3_p[2][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_two_3_p[2][playerid], 1);
	}
	if(factory_job_two_3_p[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_3_p[3][playerid] = CreatePlayerTextDraw(playerid, 287.000000, 119.000000, "locksmithjob:lsui_gbdoor1");
		PlayerTextDrawTextSize(playerid, factory_job_two_3_p[3][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_3_p[3][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_3_p[3][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_3_p[3][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_3_p[3][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_3_p[3][playerid], 0);
	}
	if(factory_job_two_3_p[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_3_p[4][playerid] = CreatePlayerTextDraw(playerid, 323.000000, 119.000000, "locksmithjob:lsui_gbdoor2");
		PlayerTextDrawTextSize(playerid, factory_job_two_3_p[4][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_3_p[4][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_3_p[4][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_3_p[4][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_3_p[4][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_3_p[4][playerid], 0);
	}
	if(factory_job_two_3_p[5][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_3_p[5][playerid] = CreatePlayerTextDraw(playerid, 287.000000, 179.000000, "locksmithjob:lsui_gbdoor3");
		PlayerTextDrawTextSize(playerid, factory_job_two_3_p[5][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_3_p[5][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_3_p[5][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_3_p[5][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_3_p[5][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_3_p[5][playerid], 0);
	}
	if(factory_job_two_3_p[6][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_3_p[6][playerid] = CreatePlayerTextDraw(playerid, 323.000000, 179.000000, "locksmithjob:lsui_gbdoor4");
		PlayerTextDrawTextSize(playerid, factory_job_two_3_p[6][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_3_p[6][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_3_p[6][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_3_p[6][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_3_p[6][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_3_p[6][playerid], 0);
	}
	if(factory_job_two_3_p[7][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_3_p[7][playerid] = CreatePlayerTextDraw(playerid, 287.000000, 239.000000, "locksmithjob:lsui_gbdoor5");
		PlayerTextDrawTextSize(playerid, factory_job_two_3_p[7][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_3_p[7][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_3_p[7][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_3_p[7][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_3_p[7][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_3_p[7][playerid], 0);
	}
	if(factory_job_two_3_p[8][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_3_p[8][playerid] = CreatePlayerTextDraw(playerid, 323.000000, 239.000000, "locksmithjob:lsui_gbdoor6");
		PlayerTextDrawTextSize(playerid, factory_job_two_3_p[8][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_3_p[8][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_3_p[8][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_3_p[8][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_3_p[8][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_3_p[8][playerid], 0);
	}
	if(factory_job_two_3_p[9][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_3_p[9][playerid] = CreatePlayerTextDraw(playerid, 294.199829, 200.899932, "locksmithjob:lsui_gbdoorlock");
		PlayerTextDrawTextSize(playerid, factory_job_two_3_p[9][playerid], 18.900014, 33.199996);
		PlayerTextDrawAlignment(playerid, factory_job_two_3_p[9][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_3_p[9][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_3_p[9][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_3_p[9][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_3_p[9][playerid], 0);
	}
	if(factory_job_two_3_p[10][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_3_p[10][playerid] = CreatePlayerTextDraw(playerid, 136.999984, 120.755554, "locksmithjob:lsui_cbdoor4");
		PlayerTextDrawTextSize(playerid, factory_job_two_3_p[10][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_3_p[10][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_3_p[10][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_3_p[10][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_3_p[10][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_3_p[10][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_two_3_p[10][playerid], true);
	}
	if(factory_job_two_3_p[11][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_3_p[11][playerid] = CreatePlayerTextDraw(playerid, 136.999984, 193.455474, "locksmithjob:lsui_cbdoor2");
		PlayerTextDrawTextSize(playerid, factory_job_two_3_p[11][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_3_p[11][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_3_p[11][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_3_p[11][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_3_p[11][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_3_p[11][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_two_3_p[11][playerid], true);
	}
	if(factory_job_two_3_p[12][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_3_p[12][playerid] = CreatePlayerTextDraw(playerid, 136.999984, 264.455474, "locksmithjob:lsui_cbdoor6");
		PlayerTextDrawTextSize(playerid, factory_job_two_3_p[12][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_3_p[12][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_3_p[12][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_3_p[12][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_3_p[12][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_3_p[12][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_two_3_p[12][playerid], true);
	}
	if(factory_job_two_3_p[13][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_3_p[13][playerid] = CreatePlayerTextDraw(playerid, 452.299926, 120.755554, "locksmithjob:lsui_cbdoor1");
		PlayerTextDrawTextSize(playerid, factory_job_two_3_p[13][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_3_p[13][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_3_p[13][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_3_p[13][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_3_p[13][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_3_p[13][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_two_3_p[13][playerid], true);
	}
	if(factory_job_two_3_p[14][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_3_p[14][playerid] = CreatePlayerTextDraw(playerid, 452.299926, 193.455474, "locksmithjob:lsui_cbdoor3");
		PlayerTextDrawTextSize(playerid, factory_job_two_3_p[14][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_3_p[14][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_3_p[14][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_3_p[14][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_3_p[14][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_3_p[14][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_two_3_p[14][playerid], true);
	}
	if(factory_job_two_3_p[15][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_3_p[15][playerid] = CreatePlayerTextDraw(playerid, 452.299926, 264.455474, "locksmithjob:lsui_cbdoor5");
		PlayerTextDrawTextSize(playerid, factory_job_two_3_p[15][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_3_p[15][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_3_p[15][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_3_p[15][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_3_p[15][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_3_p[15][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_two_3_p[15][playerid], true);
	}
	if(factory_job_two_3_p[16][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_3_p[16][playerid] = CreatePlayerTextDraw(playerid, 512.000000, 206.000000, "locksmithjob:lsui_cbdoorlock");
		PlayerTextDrawTextSize(playerid, factory_job_two_3_p[16][playerid], 18.900014, 33.199996);
		PlayerTextDrawAlignment(playerid, factory_job_two_3_p[16][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_3_p[16][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_3_p[16][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_3_p[16][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_3_p[16][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_two_3_p[16][playerid], true);
	}
	if(factory_job_two_3_p[17][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_3_p[17][playerid] = CreatePlayerTextDraw(playerid, 208.300079, 361.199951, "furniturejob:fjui_p1");
		PlayerTextDrawTextSize(playerid, factory_job_two_3_p[17][playerid], 87.699928, 29.110000);
		PlayerTextDrawAlignment(playerid, factory_job_two_3_p[17][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_3_p[17][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_3_p[17][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_3_p[17][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_3_p[17][playerid], 0);
    }
    return true;
}

stock create_factory_mith_2_p(playerid)
{
    if(factory_job_two_2_p[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_2_p[0][playerid] = CreatePlayerTextDraw(playerid, 127.599990, 37.300010, "x1");
		PlayerTextDrawLetterSize(playerid, factory_job_two_2_p[0][playerid], 0.443666, 2.039700);
		PlayerTextDrawAlignment(playerid, factory_job_two_2_p[0][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_2_p[0][playerid], 1962902271);
		PlayerTextDrawSetShadow(playerid, factory_job_two_2_p[0][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_2_p[0][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_2_p[0][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_two_2_p[0][playerid], 1);
	}
	if(factory_job_two_2_p[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_2_p[1][playerid] = CreatePlayerTextDraw(playerid, 319.999938, 68.000015, "+_12312");
		PlayerTextDrawLetterSize(playerid, factory_job_two_2_p[1][playerid], 0.574998, 2.678518);
		PlayerTextDrawTextSize(playerid, factory_job_two_2_p[1][playerid], 0.000000, 513.360351);
		PlayerTextDrawAlignment(playerid, factory_job_two_2_p[1][playerid], 2);
		PlayerTextDrawColor(playerid, factory_job_two_2_p[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, factory_job_two_2_p[1][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_2_p[1][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_2_p[1][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_two_2_p[1][playerid], 1);
	}
	if(factory_job_two_2_p[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_2_p[2][playerid] = CreatePlayerTextDraw(playerid, 349.000000, 363.000000, "0000000");
		PlayerTextDrawLetterSize(playerid, factory_job_two_2_p[2][playerid], 0.554332, 2.309334);
		PlayerTextDrawAlignment(playerid, factory_job_two_2_p[2][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_2_p[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, factory_job_two_2_p[2][playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_2_p[2][playerid], 30);
		PlayerTextDrawFont(playerid, factory_job_two_2_p[2][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_two_2_p[2][playerid], 1);
	}
	if(factory_job_two_2_p[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_2_p[3][playerid] = CreatePlayerTextDraw(playerid, 287.000000, 119.000000, "locksmithjob:lsui_gsuitcase1");
		PlayerTextDrawTextSize(playerid, factory_job_two_2_p[3][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_2_p[3][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_2_p[3][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_2_p[3][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_2_p[3][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_2_p[3][playerid], 0);
	}
	if(factory_job_two_2_p[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_2_p[4][playerid] = CreatePlayerTextDraw(playerid, 323.000000, 119.000000, "locksmithjob:lsui_gsuitcase2");
		PlayerTextDrawTextSize(playerid, factory_job_two_2_p[4][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_2_p[4][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_2_p[4][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_2_p[4][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_2_p[4][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_2_p[4][playerid], 0);
	}
	if(factory_job_two_2_p[5][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_2_p[5][playerid] = CreatePlayerTextDraw(playerid, 287.000000, 179.000000, "locksmithjob:lsui_gsuitcase3");
		PlayerTextDrawTextSize(playerid, factory_job_two_2_p[5][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_2_p[5][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_2_p[5][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_2_p[5][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_2_p[5][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_2_p[5][playerid], 0);
    }
	if(factory_job_two_2_p[6][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_2_p[6][playerid] = CreatePlayerTextDraw(playerid, 323.000000, 179.000000, "locksmithjob:lsui_gsuitcase4");
		PlayerTextDrawTextSize(playerid, factory_job_two_2_p[6][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_2_p[6][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_2_p[6][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_2_p[6][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_2_p[6][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_2_p[6][playerid], 0);
	}
	if(factory_job_two_2_p[7][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_2_p[7][playerid] = CreatePlayerTextDraw(playerid, 287.000000, 239.000000, "locksmithjob:lsui_gsuitcase5");
		PlayerTextDrawTextSize(playerid, factory_job_two_2_p[7][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_2_p[7][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_2_p[7][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_2_p[7][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_2_p[7][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_2_p[7][playerid], 0);
    }
	if(factory_job_two_2_p[8][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_2_p[8][playerid] = CreatePlayerTextDraw(playerid, 323.000000, 239.000000, "locksmithjob:lsui_gsuitcase6");
		PlayerTextDrawTextSize(playerid, factory_job_two_2_p[8][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_2_p[8][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_2_p[8][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_2_p[8][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_2_p[8][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_2_p[8][playerid], 0);
	}
	if(factory_job_two_2_p[9][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_2_p[9][playerid] = CreatePlayerTextDraw(playerid, 304.099945, 170.699981, "locksmithjob:lsui_gsuitcaselock");
		PlayerTextDrawTextSize(playerid, factory_job_two_2_p[9][playerid], 24.000000, 55.599990);
		PlayerTextDrawAlignment(playerid, factory_job_two_2_p[9][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_2_p[9][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_2_p[9][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_2_p[9][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_2_p[9][playerid], 0);
	}
	if(factory_job_two_2_p[10][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_2_p[10][playerid] = CreatePlayerTextDraw(playerid, 136.999984, 120.755554, "locksmithjob:lsui_csuitcase4");
		PlayerTextDrawTextSize(playerid, factory_job_two_2_p[10][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_2_p[10][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_2_p[10][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_2_p[10][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_2_p[10][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_2_p[10][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_two_2_p[10][playerid], true);
	}
	if(factory_job_two_2_p[11][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_2_p[11][playerid] = CreatePlayerTextDraw(playerid, 136.999984, 193.455474, "locksmithjob:lsui_csuitcase2");
		PlayerTextDrawTextSize(playerid, factory_job_two_2_p[11][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_2_p[11][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_2_p[11][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_2_p[11][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_2_p[11][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_2_p[11][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_two_2_p[11][playerid], true);
	}
	if(factory_job_two_2_p[12][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_2_p[12][playerid] = CreatePlayerTextDraw(playerid, 136.999984, 264.455474, "locksmithjob:lsui_csuitcase6");
		PlayerTextDrawTextSize(playerid, factory_job_two_2_p[12][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_2_p[12][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_2_p[12][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_2_p[12][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_2_p[12][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_2_p[12][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_two_2_p[12][playerid], true);
	}
	if(factory_job_two_2_p[13][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_2_p[13][playerid] = CreatePlayerTextDraw(playerid, 452.299926, 120.755554, "locksmithjob:lsui_csuitcase1");
		PlayerTextDrawTextSize(playerid, factory_job_two_2_p[13][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_2_p[13][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_2_p[13][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_2_p[13][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_2_p[13][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_2_p[13][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_two_2_p[13][playerid], true);
	}
	if(factory_job_two_2_p[14][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_2_p[14][playerid] = CreatePlayerTextDraw(playerid, 452.299926, 193.455474, "locksmithjob:lsui_csuitcase3");
		PlayerTextDrawTextSize(playerid, factory_job_two_2_p[14][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_2_p[14][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_2_p[14][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_2_p[14][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_2_p[14][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_2_p[14][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_two_2_p[14][playerid], true);
	}
	if(factory_job_two_2_p[15][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_2_p[15][playerid] = CreatePlayerTextDraw(playerid, 452.299926, 264.455474, "locksmithjob:lsui_csuitcase5");
		PlayerTextDrawTextSize(playerid, factory_job_two_2_p[15][playerid], 36.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_2_p[15][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_2_p[15][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_2_p[15][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_2_p[15][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_2_p[15][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_two_2_p[15][playerid], true);
	}
	if(factory_job_two_2_p[16][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_2_p[16][playerid] = CreatePlayerTextDraw(playerid, 522.000000, 188.000000, "locksmithjob:lsui_csuitcaselock");
		PlayerTextDrawTextSize(playerid, factory_job_two_2_p[16][playerid], 24.000000, 55.599990);
		PlayerTextDrawAlignment(playerid, factory_job_two_2_p[16][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_2_p[16][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_2_p[16][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_2_p[16][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_2_p[16][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_two_2_p[16][playerid], true);
	}
	if(factory_job_two_2_p[17][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_2_p[17][playerid] = CreatePlayerTextDraw(playerid, 208.300079, 361.199951, "furniturejob:fjui_p1");
		PlayerTextDrawTextSize(playerid, factory_job_two_2_p[17][playerid], 87.699928, 29.110000);
		PlayerTextDrawAlignment(playerid, factory_job_two_2_p[17][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_2_p[17][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_2_p[17][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_2_p[17][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_2_p[17][playerid], 0);
	}
	return true;
}

stock creator_factory_mith_1_p(playerid)
{
	if(factory_job_two_1_p[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_1_p[0][playerid] = CreatePlayerTextDraw(playerid, 127.599990, 37.300010, "x1");
		PlayerTextDrawLetterSize(playerid, factory_job_two_1_p[0][playerid], 0.443666, 2.039700);
		PlayerTextDrawAlignment(playerid, factory_job_two_1_p[0][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_1_p[0][playerid], 1962902271);
		PlayerTextDrawSetShadow(playerid, factory_job_two_1_p[0][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_1_p[0][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_1_p[0][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_two_1_p[0][playerid], 1);
	}
	if(factory_job_two_1_p[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_1_p[1][playerid] = CreatePlayerTextDraw(playerid, 319.999938, 68.000015, "+_12312");
		PlayerTextDrawLetterSize(playerid, factory_job_two_1_p[1][playerid], 0.574998, 2.678518);
		PlayerTextDrawTextSize(playerid, factory_job_two_1_p[1][playerid], 0.000000, 513.360351);
		PlayerTextDrawAlignment(playerid, factory_job_two_1_p[1][playerid], 2);
		PlayerTextDrawColor(playerid, factory_job_two_1_p[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, factory_job_two_1_p[1][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_1_p[1][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_1_p[1][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_two_1_p[1][playerid], 1);
	}
	if(factory_job_two_1_p[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_1_p[2][playerid] = CreatePlayerTextDraw(playerid, 349.000000, 363.000000, "0000000");
		PlayerTextDrawLetterSize(playerid, factory_job_two_1_p[2][playerid], 0.554332, 2.309334);
		PlayerTextDrawAlignment(playerid, factory_job_two_1_p[2][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_1_p[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, factory_job_two_1_p[2][playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_1_p[2][playerid], 30);
		PlayerTextDrawFont(playerid, factory_job_two_1_p[2][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_two_1_p[2][playerid], 1);
	}
    if(factory_job_two_1_p[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_1_p[3][playerid] = CreatePlayerTextDraw(playerid, 265.867004, 119.270370, "locksmithjob:lsui_glocker1");
		PlayerTextDrawTextSize(playerid, factory_job_two_1_p[3][playerid], 57.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_1_p[3][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_1_p[3][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_1_p[3][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_1_p[3][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_1_p[3][playerid], 0);
	}
	if(factory_job_two_1_p[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_1_p[4][playerid] = CreatePlayerTextDraw(playerid, 322.866699, 119.270370, "locksmithjob:lsui_glocker2");
		PlayerTextDrawTextSize(playerid, factory_job_two_1_p[4][playerid], 57.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_1_p[4][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_1_p[4][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_1_p[4][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_1_p[4][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_1_p[4][playerid], 0);
	}
	if(factory_job_two_1_p[5][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_1_p[5][playerid] = CreatePlayerTextDraw(playerid, 265.867004, 179.170928, "locksmithjob:lsui_glocker3");
		PlayerTextDrawTextSize(playerid, factory_job_two_1_p[5][playerid], 57.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_1_p[5][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_1_p[5][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_1_p[5][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_1_p[5][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_1_p[5][playerid], 0);
	}
	if(factory_job_two_1_p[6][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_1_p[6][playerid] = CreatePlayerTextDraw(playerid, 322.866699, 179.170928, "locksmithjob:lsui_glocker4");
		PlayerTextDrawTextSize(playerid, factory_job_two_1_p[6][playerid], 57.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_1_p[6][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_1_p[6][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_1_p[6][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_1_p[6][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_1_p[6][playerid], 0);
	}
	if(factory_job_two_1_p[7][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_1_p[7][playerid] = CreatePlayerTextDraw(playerid, 265.867004, 238.670852, "locksmithjob:lsui_glocker5");
		PlayerTextDrawTextSize(playerid, factory_job_two_1_p[7][playerid], 57.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_1_p[7][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_1_p[7][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_1_p[7][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_1_p[7][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_1_p[7][playerid], 0);
	}
	if(factory_job_two_1_p[8][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_1_p[8][playerid] = CreatePlayerTextDraw(playerid, 322.866699, 238.670852, "locksmithjob:lsui_glocker6");
		PlayerTextDrawTextSize(playerid, factory_job_two_1_p[8][playerid], 57.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_1_p[8][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_1_p[8][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_1_p[8][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_1_p[8][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_1_p[8][playerid], 0);
	}
	if(factory_job_two_1_p[9][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_1_p[9][playerid] = CreatePlayerTextDraw(playerid, 316.566467, 150.970031, "locksmithjob:lsui_glockerlock");
		PlayerTextDrawTextSize(playerid, factory_job_two_1_p[9][playerid], 24.770004, 40.749980);
		PlayerTextDrawAlignment(playerid, factory_job_two_1_p[9][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_1_p[9][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_1_p[9][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_1_p[9][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_1_p[9][playerid], 0);
	}
	if(factory_job_two_1_p[10][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_1_p[10][playerid] = CreatePlayerTextDraw(playerid, 136.999984, 120.755554, "locksmithjob:lsui_clocker4");
		PlayerTextDrawTextSize(playerid, factory_job_two_1_p[10][playerid], 57.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_1_p[10][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_1_p[10][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_1_p[10][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_1_p[10][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_1_p[10][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_two_1_p[10][playerid], true);
	}
	if(factory_job_two_1_p[11][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_1_p[11][playerid] = CreatePlayerTextDraw(playerid, 136.999984, 193.455474, "locksmithjob:lsui_clocker2");
		PlayerTextDrawTextSize(playerid, factory_job_two_1_p[11][playerid], 57.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_1_p[11][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_1_p[11][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_1_p[11][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_1_p[11][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_1_p[11][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_two_1_p[11][playerid], true);
	}
	if(factory_job_two_1_p[12][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_1_p[12][playerid] = CreatePlayerTextDraw(playerid, 136.999984, 264.455474, "locksmithjob:lsui_clocker6");
		PlayerTextDrawTextSize(playerid, factory_job_two_1_p[12][playerid], 57.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_1_p[12][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_1_p[12][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_1_p[12][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_1_p[12][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_1_p[12][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_two_1_p[12][playerid], true);
	}
	if(factory_job_two_1_p[13][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_1_p[13][playerid] = CreatePlayerTextDraw(playerid, 452.299926, 120.755554, "locksmithjob:lsui_clocker1");
		PlayerTextDrawTextSize(playerid, factory_job_two_1_p[13][playerid], 57.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_1_p[13][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_1_p[13][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_1_p[13][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_1_p[13][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_1_p[13][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_two_1_p[13][playerid], true);
	}
	if(factory_job_two_1_p[14][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_1_p[14][playerid] = CreatePlayerTextDraw(playerid, 452.299926, 193.455474, "locksmithjob:lsui_clocker3");
		PlayerTextDrawTextSize(playerid, factory_job_two_1_p[14][playerid], 57.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_1_p[14][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_1_p[14][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_1_p[14][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_1_p[14][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_1_p[14][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_two_1_p[14][playerid], true);
	}
	if(factory_job_two_1_p[15][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_1_p[15][playerid] = CreatePlayerTextDraw(playerid, 452.299926, 264.455474, "locksmithjob:lsui_clocker5");
		PlayerTextDrawTextSize(playerid, factory_job_two_1_p[15][playerid], 57.000000, 60.000000);
		PlayerTextDrawAlignment(playerid, factory_job_two_1_p[15][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_1_p[15][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_1_p[15][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_1_p[15][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_1_p[15][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_two_1_p[15][playerid], true);
	}
	if(factory_job_two_1_p[16][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_1_p[16][playerid] = CreatePlayerTextDraw(playerid, 470.000000, 47.000000, "locksmithjob:lsui_clockerlock");
		PlayerTextDrawTextSize(playerid, factory_job_two_1_p[16][playerid], 24.770004, 40.749980);
		PlayerTextDrawAlignment(playerid, factory_job_two_1_p[16][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_1_p[16][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_1_p[16][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_1_p[16][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_1_p[16][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_two_1_p[16][playerid], true);
	}
	if(factory_job_two_1_p[17][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_two_1_p[17][playerid] = CreatePlayerTextDraw(playerid, 208.300079, 361.199951, "furniturejob:fjui_p1");
		PlayerTextDrawTextSize(playerid, factory_job_two_1_p[17][playerid], 87.699928, 29.110000);
		PlayerTextDrawAlignment(playerid, factory_job_two_1_p[17][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_two_1_p[17][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_two_1_p[17][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_two_1_p[17][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_two_1_p[17][playerid], 0);
	}
	return true;
}

stock create_factory_job_9_p(playerid)
{

	if(factory_job_9_p[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_9_p[0][playerid] = CreatePlayerTextDraw(playerid, 127.599990, 37.300010, "x1");
		PlayerTextDrawLetterSize(playerid, factory_job_9_p[0][playerid], 0.443666, 2.039700);
		PlayerTextDrawAlignment(playerid, factory_job_9_p[0][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_9_p[0][playerid], 1962902271);
		PlayerTextDrawSetShadow(playerid, factory_job_9_p[0][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, factory_job_9_p[0][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_9_p[0][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_9_p[0][playerid], 1);
	}
	if(factory_job_9_p[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_9_p[1][playerid] = CreatePlayerTextDraw(playerid, 319.999938, 68.000015, "+_12312");
		PlayerTextDrawLetterSize(playerid, factory_job_9_p[1][playerid], 0.574998, 2.678518);
		PlayerTextDrawTextSize(playerid, factory_job_9_p[1][playerid], 0.000000, 513.360351);
		PlayerTextDrawAlignment(playerid, factory_job_9_p[1][playerid], 2);
		PlayerTextDrawColor(playerid, factory_job_9_p[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, factory_job_9_p[1][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, factory_job_9_p[1][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_9_p[1][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_9_p[1][playerid], 1);
	}
	if(factory_job_9_p[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_9_p[2][playerid] = CreatePlayerTextDraw(playerid, 349.000000, 363.000000, "0000000");
		PlayerTextDrawLetterSize(playerid, factory_job_9_p[2][playerid], 0.554332, 2.309334);
		PlayerTextDrawAlignment(playerid, factory_job_9_p[2][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_9_p[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, factory_job_9_p[2][playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_9_p[2][playerid], 30);
		PlayerTextDrawFont(playerid, factory_job_9_p[2][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_9_p[2][playerid], 1);
	}
	if(factory_job_9_p[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_9_p[3][playerid] = CreatePlayerTextDraw(playerid, 284.000000, 114.000000, "furniturejob:fjui_gchair1");
		PlayerTextDrawTextSize(playerid, factory_job_9_p[3][playerid], 26.000000, 80.000000);
		PlayerTextDrawAlignment(playerid, factory_job_9_p[3][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_9_p[3][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_9_p[3][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_9_p[3][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_9_p[3][playerid], 0);
	}
	if(factory_job_9_p[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_9_p[4][playerid] = CreatePlayerTextDraw(playerid, 284.000000, 194.000000, "furniturejob:fjui_gchair4");
		PlayerTextDrawTextSize(playerid, factory_job_9_p[4][playerid], 26.000000, 80.000000);
		PlayerTextDrawAlignment(playerid, factory_job_9_p[4][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_9_p[4][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_9_p[4][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_9_p[4][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_9_p[4][playerid], 0);
	}
	if(factory_job_9_p[5][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_9_p[5][playerid] = CreatePlayerTextDraw(playerid, 310.000000, 114.000000, "furniturejob:fjui_gchair2");
		PlayerTextDrawTextSize(playerid, factory_job_9_p[5][playerid], 26.000000, 80.000000);
		PlayerTextDrawAlignment(playerid, factory_job_9_p[5][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_9_p[5][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_9_p[5][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_9_p[5][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_9_p[5][playerid], 0);
	}
	if(factory_job_9_p[6][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_9_p[6][playerid] = CreatePlayerTextDraw(playerid, 310.000000, 194.000000, "furniturejob:fjui_gchair5");
		PlayerTextDrawTextSize(playerid, factory_job_9_p[6][playerid], 26.000000, 80.000000);
		PlayerTextDrawAlignment(playerid, factory_job_9_p[6][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_9_p[6][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_9_p[6][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_9_p[6][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_9_p[6][playerid], 0);
	}
	if(factory_job_9_p[7][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_9_p[7][playerid] = CreatePlayerTextDraw(playerid, 336.000000, 114.000000, "furniturejob:fjui_gchair3");
		PlayerTextDrawTextSize(playerid, factory_job_9_p[7][playerid], 26.000000, 80.000000);
		PlayerTextDrawAlignment(playerid, factory_job_9_p[7][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_9_p[7][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_9_p[7][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_9_p[7][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_9_p[7][playerid], 0);
	}
	if(factory_job_9_p[8][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_9_p[8][playerid] = CreatePlayerTextDraw(playerid, 336.000000, 194.000000, "furniturejob:fjui_gchair6");
		PlayerTextDrawTextSize(playerid, factory_job_9_p[8][playerid], 26.000000, 80.000000);
		PlayerTextDrawAlignment(playerid, factory_job_9_p[8][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_9_p[8][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_9_p[8][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_9_p[8][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_9_p[8][playerid], 0);
	}
	if(factory_job_9_p[9][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_9_p[9][playerid] = CreatePlayerTextDraw(playerid, 138.099822, 115.000000, "furniturejob:fjui_cchair4");
		PlayerTextDrawTextSize(playerid, factory_job_9_p[9][playerid], 26.000000, 80.000000);
		PlayerTextDrawAlignment(playerid, factory_job_9_p[9][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_9_p[9][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_9_p[9][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_9_p[9][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_9_p[9][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_9_p[9][playerid], true);
	}
	if(factory_job_9_p[10][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_9_p[10][playerid] = CreatePlayerTextDraw(playerid, 195.100097, 191.000000, "furniturejob:fjui_cchair2");
		PlayerTextDrawTextSize(playerid, factory_job_9_p[10][playerid], 26.000000, 80.000000);
		PlayerTextDrawAlignment(playerid, factory_job_9_p[10][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_9_p[10][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_9_p[10][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_9_p[10][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_9_p[10][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_9_p[10][playerid], true);
	}
	if(factory_job_9_p[11][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_9_p[11][playerid] = CreatePlayerTextDraw(playerid, 138.099822, 266.000000, "furniturejob:fjui_cchair6");
		PlayerTextDrawTextSize(playerid, factory_job_9_p[11][playerid], 26.000000, 80.000000);
		PlayerTextDrawAlignment(playerid, factory_job_9_p[11][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_9_p[11][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_9_p[11][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_9_p[11][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_9_p[11][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_9_p[11][playerid], true);
	}
	if(factory_job_9_p[12][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_9_p[12][playerid] = CreatePlayerTextDraw(playerid, 435.599182, 115.000000, "furniturejob:fjui_cchair1");
		PlayerTextDrawTextSize(playerid, factory_job_9_p[12][playerid], 26.000000, 80.000000);
		PlayerTextDrawAlignment(playerid, factory_job_9_p[12][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_9_p[12][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_9_p[12][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_9_p[12][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_9_p[12][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_9_p[12][playerid], true);
	}
	if(factory_job_9_p[13][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_9_p[13][playerid] = CreatePlayerTextDraw(playerid, 492.599182, 191.000000, "furniturejob:fjui_cchair3");
		PlayerTextDrawTextSize(playerid, factory_job_9_p[13][playerid], 26.000000, 80.000000);
		PlayerTextDrawAlignment(playerid, factory_job_9_p[13][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_9_p[13][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_9_p[13][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_9_p[13][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_9_p[13][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_9_p[13][playerid], true);
	}
	if(factory_job_9_p[14][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_9_p[14][playerid] = CreatePlayerTextDraw(playerid, 435.599182, 266.000000, "furniturejob:fjui_cchair5");
		PlayerTextDrawTextSize(playerid, factory_job_9_p[14][playerid], 26.000000, 80.000000);
		PlayerTextDrawAlignment(playerid, factory_job_9_p[14][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_9_p[14][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_9_p[14][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_9_p[14][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_9_p[14][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_9_p[14][playerid], true);
	}

	if(factory_job_9_p[15][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_9_p[15][playerid] = CreatePlayerTextDraw(playerid, 208.300079, 361.199951, "furniturejob:fjui_p1");
		PlayerTextDrawTextSize(playerid, factory_job_9_p[15][playerid], 87.699928, 29.110000);
		PlayerTextDrawAlignment(playerid, factory_job_9_p[15][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_9_p[15][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_9_p[15][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_9_p[15][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_9_p[15][playerid], 0);
	}


	return true;
}

stock create_factory_job_8_p(playerid)
{

	if(factory_job_8_p[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_8_p[0][playerid] = CreatePlayerTextDraw(playerid, 127.599990, 37.300010, "x1");
		PlayerTextDrawLetterSize(playerid, factory_job_8_p[0][playerid], 0.443666, 2.039700);
		PlayerTextDrawAlignment(playerid, factory_job_8_p[0][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_8_p[0][playerid], 1962902271);
		PlayerTextDrawSetShadow(playerid, factory_job_8_p[0][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, factory_job_8_p[0][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_8_p[0][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_8_p[0][playerid], 1);
	}
	if(factory_job_8_p[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_8_p[1][playerid] = CreatePlayerTextDraw(playerid, 319.999938, 68.000015, "+_12312");
		PlayerTextDrawLetterSize(playerid, factory_job_8_p[1][playerid], 0.574998, 2.678518);
		PlayerTextDrawTextSize(playerid, factory_job_8_p[1][playerid], 0.000000, 513.360351);
		PlayerTextDrawAlignment(playerid, factory_job_8_p[1][playerid], 2);
		PlayerTextDrawColor(playerid, factory_job_8_p[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, factory_job_8_p[1][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, factory_job_8_p[1][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_8_p[1][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_8_p[1][playerid], 1);
	}
	if(factory_job_8_p[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_8_p[2][playerid] = CreatePlayerTextDraw(playerid, 349.000000, 363.000000, "0000000");
		PlayerTextDrawLetterSize(playerid, factory_job_8_p[2][playerid], 0.554332, 2.309334);
		PlayerTextDrawAlignment(playerid, factory_job_8_p[2][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_8_p[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, factory_job_8_p[2][playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_8_p[2][playerid], 30);
		PlayerTextDrawFont(playerid, factory_job_8_p[2][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_8_p[2][playerid], 1);
	}
	if(factory_job_8_p[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_8_p[3][playerid] = CreatePlayerTextDraw(playerid, 272.000000, 97.000000, "furniturejob:fjui_gcupboard1");
		PlayerTextDrawTextSize(playerid, factory_job_8_p[3][playerid], 51.000000, 67.000000);
		PlayerTextDrawAlignment(playerid, factory_job_8_p[3][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_8_p[3][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_8_p[3][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_8_p[3][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_8_p[3][playerid], 0);
	}
	if(factory_job_8_p[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_8_p[4][playerid] = CreatePlayerTextDraw(playerid, 323.000000, 97.000000, "furniturejob:fjui_gcupboard2");
		PlayerTextDrawTextSize(playerid, factory_job_8_p[4][playerid], 51.000000, 67.000000);
		PlayerTextDrawAlignment(playerid, factory_job_8_p[4][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_8_p[4][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_8_p[4][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_8_p[4][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_8_p[4][playerid], 0);
	}
	if(factory_job_8_p[5][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_8_p[5][playerid] = CreatePlayerTextDraw(playerid, 272.000000, 164.200012, "furniturejob:fjui_gcupboard3");
		PlayerTextDrawTextSize(playerid, factory_job_8_p[5][playerid], 51.000000, 67.000000);
		PlayerTextDrawAlignment(playerid, factory_job_8_p[5][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_8_p[5][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_8_p[5][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_8_p[5][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_8_p[5][playerid], 0);
	}
	if(factory_job_8_p[6][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_8_p[6][playerid] = CreatePlayerTextDraw(playerid, 323.000000, 164.200012, "furniturejob:fjui_gcupboard4");
		PlayerTextDrawTextSize(playerid, factory_job_8_p[6][playerid], 51.000000, 67.000000);
		PlayerTextDrawAlignment(playerid, factory_job_8_p[6][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_8_p[6][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_8_p[6][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_8_p[6][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_8_p[6][playerid], 0);
	}
	if(factory_job_8_p[7][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_8_p[7][playerid] = CreatePlayerTextDraw(playerid, 272.000000, 231.200012, "furniturejob:fjui_gcupboard5");
		PlayerTextDrawTextSize(playerid, factory_job_8_p[7][playerid], 51.000000, 67.000000);
		PlayerTextDrawAlignment(playerid, factory_job_8_p[7][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_8_p[7][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_8_p[7][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_8_p[7][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_8_p[7][playerid], 0);
	}
	if(factory_job_8_p[8][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_8_p[8][playerid] = CreatePlayerTextDraw(playerid, 323.000000, 231.200012, "furniturejob:fjui_gcupboard6");
		PlayerTextDrawTextSize(playerid, factory_job_8_p[8][playerid], 51.000000, 67.000000);
		PlayerTextDrawAlignment(playerid, factory_job_8_p[8][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_8_p[8][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_8_p[8][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_8_p[8][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_8_p[8][playerid], 0);
	}
	if(factory_job_8_p[9][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_8_p[9][playerid] = CreatePlayerTextDraw(playerid, 114.999908, 115.000000, "furniturejob:fjui_ccupboard4");
		PlayerTextDrawTextSize(playerid, factory_job_8_p[9][playerid], 51.000000, 67.000000);
		PlayerTextDrawAlignment(playerid, factory_job_8_p[9][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_8_p[9][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_8_p[9][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_8_p[9][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_8_p[9][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_8_p[9][playerid], true);
	}
	if(factory_job_8_p[10][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_8_p[10][playerid] = CreatePlayerTextDraw(playerid, 114.999908, 190.699920, "furniturejob:fjui_ccupboard2");
		PlayerTextDrawTextSize(playerid, factory_job_8_p[10][playerid], 51.000000, 67.000000);
		PlayerTextDrawAlignment(playerid, factory_job_8_p[10][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_8_p[10][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_8_p[10][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_8_p[10][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_8_p[10][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_8_p[10][playerid], true);
	}
	if(factory_job_8_p[11][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_8_p[11][playerid] = CreatePlayerTextDraw(playerid, 114.999908, 265.699920, "furniturejob:fjui_ccupboard6");
		PlayerTextDrawTextSize(playerid, factory_job_8_p[11][playerid], 51.000000, 67.000000);
		PlayerTextDrawAlignment(playerid, factory_job_8_p[11][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_8_p[11][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_8_p[11][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_8_p[11][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_8_p[11][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_8_p[11][playerid], true);
	}
	if(factory_job_8_p[12][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_8_p[12][playerid] = CreatePlayerTextDraw(playerid, 444.999938, 115.000000, "furniturejob:fjui_ccupboard1");
		PlayerTextDrawTextSize(playerid, factory_job_8_p[12][playerid], 51.000000, 67.000000);
		PlayerTextDrawAlignment(playerid, factory_job_8_p[12][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_8_p[12][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_8_p[12][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_8_p[12][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_8_p[12][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_8_p[12][playerid], true);
	}
	if(factory_job_8_p[13][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_8_p[13][playerid] = CreatePlayerTextDraw(playerid, 444.999938, 190.699920, "furniturejob:fjui_ccupboard3");
		PlayerTextDrawTextSize(playerid, factory_job_8_p[13][playerid], 51.000000, 67.000000);
		PlayerTextDrawAlignment(playerid, factory_job_8_p[13][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_8_p[13][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_8_p[13][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_8_p[13][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_8_p[13][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_8_p[13][playerid], true);
	}
	if(factory_job_8_p[14][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_8_p[14][playerid] = CreatePlayerTextDraw(playerid, 444.999938, 265.699920, "furniturejob:fjui_ccupboard5");
		PlayerTextDrawTextSize(playerid, factory_job_8_p[14][playerid], 51.000000, 67.000000);
		PlayerTextDrawAlignment(playerid, factory_job_8_p[14][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_8_p[14][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_8_p[14][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_8_p[14][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_8_p[14][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_8_p[14][playerid], true);
	}

	if(factory_job_8_p[15][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_8_p[15][playerid] = CreatePlayerTextDraw(playerid, 208.300079, 361.199951, "furniturejob:fjui_p1");
		PlayerTextDrawTextSize(playerid, factory_job_8_p[15][playerid], 87.699928, 29.110000);
		PlayerTextDrawAlignment(playerid, factory_job_8_p[15][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_8_p[15][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_8_p[15][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_8_p[15][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_8_p[15][playerid], 0);
	}


	return true;
}

stock create_factory_job_7_p(playerid)
{
	if(factory_job_7_p[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_7_p[0][playerid] = CreatePlayerTextDraw(playerid, 127.599990, 37.300010, "x1");
		PlayerTextDrawLetterSize(playerid, factory_job_7_p[0][playerid], 0.443666, 2.039700);
		PlayerTextDrawAlignment(playerid, factory_job_7_p[0][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_7_p[0][playerid], 1962902271);
		PlayerTextDrawSetShadow(playerid, factory_job_7_p[0][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, factory_job_7_p[0][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_7_p[0][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_7_p[0][playerid], 1);
	}
	if(factory_job_7_p[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{	
		factory_job_7_p[1][playerid] = CreatePlayerTextDraw(playerid, 319.999938, 68.000015, "+_12312");
		PlayerTextDrawLetterSize(playerid, factory_job_7_p[1][playerid], 0.574998, 2.678518);
		PlayerTextDrawTextSize(playerid, factory_job_7_p[1][playerid], 0.000000, 513.360351);
		PlayerTextDrawAlignment(playerid, factory_job_7_p[1][playerid], 2);
		PlayerTextDrawColor(playerid, factory_job_7_p[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, factory_job_7_p[1][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, factory_job_7_p[1][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_7_p[1][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_7_p[1][playerid], 1);
	}
	if(factory_job_7_p[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_7_p[2][playerid] = CreatePlayerTextDraw(playerid, 349.000000, 363.000000, "0000000");
		PlayerTextDrawLetterSize(playerid, factory_job_7_p[2][playerid], 0.554332, 2.309334);
		PlayerTextDrawAlignment(playerid, factory_job_7_p[2][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_7_p[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, factory_job_7_p[2][playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_7_p[2][playerid], 30);
		PlayerTextDrawFont(playerid, factory_job_7_p[2][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_7_p[2][playerid], 1);
	}
	if(factory_job_7_p[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_7_p[3][playerid] = CreatePlayerTextDraw(playerid, 272.000000, 97.000000, "furniturejob:fjui_grack1");
		PlayerTextDrawTextSize(playerid, factory_job_7_p[3][playerid], 51.000000, 67.000000);
		PlayerTextDrawAlignment(playerid, factory_job_7_p[3][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_7_p[3][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_7_p[3][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_7_p[3][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_7_p[3][playerid], 0);
	}
	if(factory_job_7_p[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_7_p[4][playerid] = CreatePlayerTextDraw(playerid, 323.000000, 97.000000, "furniturejob:fjui_grack2");
		PlayerTextDrawTextSize(playerid, factory_job_7_p[4][playerid], 51.000000, 67.000000);
		PlayerTextDrawAlignment(playerid, factory_job_7_p[4][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_7_p[4][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_7_p[4][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_7_p[4][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_7_p[4][playerid], 0);
	}
	if(factory_job_7_p[5][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_7_p[5][playerid] = CreatePlayerTextDraw(playerid, 272.000000, 164.200012, "furniturejob:fjui_grack3");
		PlayerTextDrawTextSize(playerid, factory_job_7_p[5][playerid], 51.000000, 67.000000);
		PlayerTextDrawAlignment(playerid, factory_job_7_p[5][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_7_p[5][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_7_p[5][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_7_p[5][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_7_p[5][playerid], 0);
	}
	if(factory_job_7_p[6][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_7_p[6][playerid] = CreatePlayerTextDraw(playerid, 323.000000, 164.200012, "furniturejob:fjui_grack4");
		PlayerTextDrawTextSize(playerid, factory_job_7_p[6][playerid], 51.000000, 67.000000);
		PlayerTextDrawAlignment(playerid, factory_job_7_p[6][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_7_p[6][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_7_p[6][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_7_p[6][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_7_p[6][playerid], 0);
	}
	if(factory_job_7_p[7][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_7_p[7][playerid] = CreatePlayerTextDraw(playerid, 272.000000, 231.200012, "furniturejob:fjui_grack5");
		PlayerTextDrawTextSize(playerid, factory_job_7_p[7][playerid], 51.000000, 67.000000);
		PlayerTextDrawAlignment(playerid, factory_job_7_p[7][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_7_p[7][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_7_p[7][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_7_p[7][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_7_p[7][playerid], 0);
	}
	if(factory_job_7_p[8][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_7_p[8][playerid] = CreatePlayerTextDraw(playerid, 323.000000, 231.200012, "furniturejob:fjui_grack6");
		PlayerTextDrawTextSize(playerid, factory_job_7_p[8][playerid], 51.000000, 67.000000);
		PlayerTextDrawAlignment(playerid, factory_job_7_p[8][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_7_p[8][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_7_p[8][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_7_p[8][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_7_p[8][playerid], 0);
	}
	if(factory_job_7_p[9][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_7_p[9][playerid] = CreatePlayerTextDraw(playerid, 114.999908, 115.000000, "furniturejob:fjui_crack4");
		PlayerTextDrawTextSize(playerid, factory_job_7_p[9][playerid], 51.000000, 67.000000);
		PlayerTextDrawAlignment(playerid, factory_job_7_p[9][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_7_p[9][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_7_p[9][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_7_p[9][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_7_p[9][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_7_p[9][playerid], true);
	}
	if(factory_job_7_p[10][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_7_p[10][playerid] = CreatePlayerTextDraw(playerid, 114.999908, 190.699920, "furniturejob:fjui_crack2");
		PlayerTextDrawTextSize(playerid, factory_job_7_p[10][playerid], 51.000000, 67.000000);
		PlayerTextDrawAlignment(playerid, factory_job_7_p[10][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_7_p[10][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_7_p[10][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_7_p[10][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_7_p[10][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_7_p[10][playerid], true);
	}
	if(factory_job_7_p[11][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_7_p[11][playerid] = CreatePlayerTextDraw(playerid, 114.999908, 265.699920, "furniturejob:fjui_crack6");
		PlayerTextDrawTextSize(playerid, factory_job_7_p[11][playerid], 51.000000, 67.000000);
		PlayerTextDrawAlignment(playerid, factory_job_7_p[11][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_7_p[11][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_7_p[11][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_7_p[11][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_7_p[11][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_7_p[11][playerid], true);
	}
	if(factory_job_7_p[12][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_7_p[12][playerid] = CreatePlayerTextDraw(playerid, 444.999938, 115.000000, "furniturejob:fjui_crack1");
		PlayerTextDrawTextSize(playerid, factory_job_7_p[12][playerid], 51.000000, 67.000000);
		PlayerTextDrawAlignment(playerid, factory_job_7_p[12][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_7_p[12][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_7_p[12][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_7_p[12][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_7_p[12][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_7_p[12][playerid], true);
	}
	if(factory_job_7_p[13][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_7_p[13][playerid] = CreatePlayerTextDraw(playerid, 444.999938, 190.699920, "furniturejob:fjui_crack3");
		PlayerTextDrawTextSize(playerid, factory_job_7_p[13][playerid], 51.000000, 67.000000);
		PlayerTextDrawAlignment(playerid, factory_job_7_p[13][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_7_p[13][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_7_p[13][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_7_p[13][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_7_p[13][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_7_p[13][playerid], true);
	}
	if(factory_job_7_p[14][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_7_p[14][playerid] = CreatePlayerTextDraw(playerid, 444.999938, 265.699920, "furniturejob:fjui_crack5");
		PlayerTextDrawTextSize(playerid, factory_job_7_p[14][playerid], 51.000000, 67.000000);
		PlayerTextDrawAlignment(playerid, factory_job_7_p[14][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_7_p[14][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_7_p[14][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_7_p[14][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_7_p[14][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_7_p[14][playerid], true);
	}
	if(factory_job_7_p[15][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_7_p[15][playerid] = CreatePlayerTextDraw(playerid, 208.300079, 361.199951, "furniturejob:fjui_p1");
		PlayerTextDrawTextSize(playerid, factory_job_7_p[15][playerid], 87.699928, 29.110000);
		PlayerTextDrawAlignment(playerid, factory_job_7_p[15][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_7_p[15][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_7_p[15][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_7_p[15][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_7_p[15][playerid], 0);
	}
	return true;
}

stock create_factory_job_6_p(playerid)
{
	if(factory_job_6_p[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_6_p[0][playerid] = CreatePlayerTextDraw(playerid, 127.599990, 37.300010, "x1");
		PlayerTextDrawLetterSize(playerid, factory_job_6_p[0][playerid], 0.443666, 2.039700);
		PlayerTextDrawAlignment(playerid, factory_job_6_p[0][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_6_p[0][playerid], 1962902271);
		PlayerTextDrawSetShadow(playerid, factory_job_6_p[0][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, factory_job_6_p[0][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_6_p[0][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_6_p[0][playerid], 1);
	}
	if(factory_job_6_p[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_6_p[1][playerid] = CreatePlayerTextDraw(playerid, 319.999938, 68.000015, "+_12312");
		PlayerTextDrawLetterSize(playerid, factory_job_6_p[1][playerid], 0.574998, 2.678518);
		PlayerTextDrawTextSize(playerid, factory_job_6_p[1][playerid], 0.000000, 513.360351);
		PlayerTextDrawAlignment(playerid, factory_job_6_p[1][playerid], 2);
		PlayerTextDrawColor(playerid, factory_job_6_p[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, factory_job_6_p[1][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, factory_job_6_p[1][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_6_p[1][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_6_p[1][playerid], 1);
	}
	if(factory_job_6_p[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_6_p[2][playerid] = CreatePlayerTextDraw(playerid, 349.000000, 363.000000, "0000000");
		PlayerTextDrawLetterSize(playerid, factory_job_6_p[2][playerid], 0.554332, 2.309334);
		PlayerTextDrawAlignment(playerid, factory_job_6_p[2][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_6_p[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, factory_job_6_p[2][playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_6_p[2][playerid], 30);
		PlayerTextDrawFont(playerid, factory_job_6_p[2][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_6_p[2][playerid], 1);
	}
	if(factory_job_6_p[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_6_p[3][playerid] = CreatePlayerTextDraw(playerid, 261.900085, 119.600051, "furniturejob:fjui_gachair1");
		PlayerTextDrawTextSize(playerid, factory_job_6_p[3][playerid], 58.000000, 57.000000);
		PlayerTextDrawAlignment(playerid, factory_job_6_p[3][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_6_p[3][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_6_p[3][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_6_p[3][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_6_p[3][playerid], 0);
	}
	if(factory_job_6_p[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_6_p[4][playerid] = CreatePlayerTextDraw(playerid, 319.899627, 119.600051, "furniturejob:fjui_gachair2");
		PlayerTextDrawTextSize(playerid, factory_job_6_p[4][playerid], 58.000000, 57.000000);
		PlayerTextDrawAlignment(playerid, factory_job_6_p[4][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_6_p[4][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_6_p[4][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_6_p[4][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_6_p[4][playerid], 0);
	}
	if(factory_job_6_p[5][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_6_p[5][playerid] = CreatePlayerTextDraw(playerid, 261.900085, 176.599884, "furniturejob:fjui_gachair3");
		PlayerTextDrawTextSize(playerid, factory_job_6_p[5][playerid], 58.000000, 57.000000);
		PlayerTextDrawAlignment(playerid, factory_job_6_p[5][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_6_p[5][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_6_p[5][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_6_p[5][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_6_p[5][playerid], 0);
	}
	if(factory_job_6_p[6][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_6_p[6][playerid] = CreatePlayerTextDraw(playerid, 319.899627, 176.599884, "furniturejob:fjui_gachair4");
		PlayerTextDrawTextSize(playerid, factory_job_6_p[6][playerid], 58.000000, 57.000000);
		PlayerTextDrawAlignment(playerid, factory_job_6_p[6][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_6_p[6][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_6_p[6][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_6_p[6][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_6_p[6][playerid], 0);
	}
	if(factory_job_6_p[7][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_6_p[7][playerid] = CreatePlayerTextDraw(playerid, 261.900085, 233.949798, "furniturejob:fjui_gachair5");
		PlayerTextDrawTextSize(playerid, factory_job_6_p[7][playerid], 58.000000, 57.000000);
		PlayerTextDrawAlignment(playerid, factory_job_6_p[7][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_6_p[7][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_6_p[7][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_6_p[7][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_6_p[7][playerid], 0);
	}
	if(factory_job_6_p[8][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_6_p[8][playerid] = CreatePlayerTextDraw(playerid, 319.899627, 233.949798, "furniturejob:fjui_gachair6");
		PlayerTextDrawTextSize(playerid, factory_job_6_p[8][playerid], 58.000000, 57.000000);
		PlayerTextDrawAlignment(playerid, factory_job_6_p[8][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_6_p[8][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_6_p[8][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_6_p[8][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_6_p[8][playerid], 0);
	}
	if(factory_job_6_p[9][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_6_p[9][playerid] = CreatePlayerTextDraw(playerid, 114.999908, 122.000000, "furniturejob:fjui_cachair4");
		PlayerTextDrawTextSize(playerid, factory_job_6_p[9][playerid], 58.000000, 57.000000);
		PlayerTextDrawAlignment(playerid, factory_job_6_p[9][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_6_p[9][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_6_p[9][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_6_p[9][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_6_p[9][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_6_p[9][playerid], true);
	}
	if(factory_job_6_p[10][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_6_p[10][playerid] = CreatePlayerTextDraw(playerid, 114.999908, 194.699920, "furniturejob:fjui_cachair2");
		PlayerTextDrawTextSize(playerid, factory_job_6_p[10][playerid], 58.000000, 57.000000);
		PlayerTextDrawAlignment(playerid, factory_job_6_p[10][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_6_p[10][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_6_p[10][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_6_p[10][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_6_p[10][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_6_p[10][playerid], true);
	}
	if(factory_job_6_p[11][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_6_p[11][playerid] = CreatePlayerTextDraw(playerid, 114.999908, 265.699920, "furniturejob:fjui_cachair6");
		PlayerTextDrawTextSize(playerid, factory_job_6_p[11][playerid], 58.000000, 57.000000);
		PlayerTextDrawAlignment(playerid, factory_job_6_p[11][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_6_p[11][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_6_p[11][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_6_p[11][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_6_p[11][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_6_p[11][playerid], true);
	}
	if(factory_job_6_p[12][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_6_p[12][playerid] = CreatePlayerTextDraw(playerid, 444.999938, 122.000000, "furniturejob:fjui_cachair1");
		PlayerTextDrawTextSize(playerid, factory_job_6_p[12][playerid], 58.000000, 57.000000);
		PlayerTextDrawAlignment(playerid, factory_job_6_p[12][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_6_p[12][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_6_p[12][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_6_p[12][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_6_p[12][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_6_p[12][playerid], true);
	}
	if(factory_job_6_p[13][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_6_p[13][playerid] = CreatePlayerTextDraw(playerid, 444.999938, 194.699920, "furniturejob:fjui_cachair3");
		PlayerTextDrawTextSize(playerid, factory_job_6_p[13][playerid], 58.000000, 57.000000);
		PlayerTextDrawAlignment(playerid, factory_job_6_p[13][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_6_p[13][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_6_p[13][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_6_p[13][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_6_p[13][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_6_p[13][playerid], true);
	}
	if(factory_job_6_p[14][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_6_p[14][playerid] = CreatePlayerTextDraw(playerid, 444.999938, 265.699920, "furniturejob:fjui_cachair5");
		PlayerTextDrawTextSize(playerid, factory_job_6_p[14][playerid], 58.000000, 57.000000);
		PlayerTextDrawAlignment(playerid, factory_job_6_p[14][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_6_p[14][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_6_p[14][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_6_p[14][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_6_p[14][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_6_p[14][playerid], true);
	}
	if(factory_job_6_p[15][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_6_p[15][playerid] = CreatePlayerTextDraw(playerid, 208.300079, 361.199951, "furniturejob:fjui_p1");
		PlayerTextDrawTextSize(playerid, factory_job_6_p[15][playerid], 87.699928, 29.110000);
		PlayerTextDrawAlignment(playerid, factory_job_6_p[15][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_6_p[15][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_6_p[15][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_6_p[15][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_6_p[15][playerid], 0);
	}
	return true;
}

stock create_factory_job_5_p(playerid)
{
	if(factory_job_5_p[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_5_p[0][playerid] = CreatePlayerTextDraw(playerid, 127.599990, 37.300010, "x1");
		PlayerTextDrawLetterSize(playerid, factory_job_5_p[0][playerid], 0.443666, 2.039700);
		PlayerTextDrawAlignment(playerid, factory_job_5_p[0][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_5_p[0][playerid], 1962902271);
		PlayerTextDrawSetShadow(playerid, factory_job_5_p[0][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, factory_job_5_p[0][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_5_p[0][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_5_p[0][playerid], 1);
	}
	if(factory_job_5_p[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_5_p[1][playerid] = CreatePlayerTextDraw(playerid, 319.999938, 68.000015, "+_12312");
		PlayerTextDrawLetterSize(playerid, factory_job_5_p[1][playerid], 0.574998, 2.678518);
		PlayerTextDrawTextSize(playerid, factory_job_5_p[1][playerid], 0.000000, 513.360351);
		PlayerTextDrawAlignment(playerid, factory_job_5_p[1][playerid], 2);
		PlayerTextDrawColor(playerid, factory_job_5_p[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, factory_job_5_p[1][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, factory_job_5_p[1][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_5_p[1][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_5_p[1][playerid], 1);
	}
	if(factory_job_5_p[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_5_p[2][playerid] = CreatePlayerTextDraw(playerid, 349.000000, 363.000000, "0000000");
		PlayerTextDrawLetterSize(playerid, factory_job_5_p[2][playerid], 0.554332, 2.309334);
		PlayerTextDrawAlignment(playerid, factory_job_5_p[2][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_5_p[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, factory_job_5_p[2][playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_5_p[2][playerid], 30);
		PlayerTextDrawFont(playerid, factory_job_5_p[2][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_5_p[2][playerid], 1);
	}
	if(factory_job_5_p[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_5_p[3][playerid] = CreatePlayerTextDraw(playerid, 261.900085, 119.600051, "furniturejob:fjui_gwframe1");
		PlayerTextDrawTextSize(playerid, factory_job_5_p[3][playerid], 58.000000, 57.000000);
		PlayerTextDrawAlignment(playerid, factory_job_5_p[3][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_5_p[3][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_5_p[3][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_5_p[3][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_5_p[3][playerid], 0);
	}
	if(factory_job_5_p[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_5_p[4][playerid] = CreatePlayerTextDraw(playerid, 319.899627, 119.600051, "furniturejob:fjui_gwframe2");
		PlayerTextDrawTextSize(playerid, factory_job_5_p[4][playerid], 58.000000, 57.000000);
		PlayerTextDrawAlignment(playerid, factory_job_5_p[4][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_5_p[4][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_5_p[4][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_5_p[4][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_5_p[4][playerid], 0);
	}
	if(factory_job_5_p[5][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_5_p[5][playerid] = CreatePlayerTextDraw(playerid, 261.900085, 176.599884, "furniturejob:fjui_gwframe3");
		PlayerTextDrawTextSize(playerid, factory_job_5_p[5][playerid], 58.000000, 57.000000);
		PlayerTextDrawAlignment(playerid, factory_job_5_p[5][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_5_p[5][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_5_p[5][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_5_p[5][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_5_p[5][playerid], 0);
	}
	if(factory_job_5_p[6][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_5_p[6][playerid] = CreatePlayerTextDraw(playerid, 319.899627, 176.599884, "furniturejob:fjui_gwframe4");
		PlayerTextDrawTextSize(playerid, factory_job_5_p[6][playerid], 58.000000, 57.000000);
		PlayerTextDrawAlignment(playerid, factory_job_5_p[6][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_5_p[6][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_5_p[6][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_5_p[6][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_5_p[6][playerid], 0);
	}
	if(factory_job_5_p[7][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_5_p[7][playerid] = CreatePlayerTextDraw(playerid, 261.900085, 233.949798, "furniturejob:fjui_gwframe5");
		PlayerTextDrawTextSize(playerid, factory_job_5_p[7][playerid], 58.000000, 57.000000);
		PlayerTextDrawAlignment(playerid, factory_job_5_p[7][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_5_p[7][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_5_p[7][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_5_p[7][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_5_p[7][playerid], 0);
	}
	if(factory_job_5_p[8][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_5_p[8][playerid] = CreatePlayerTextDraw(playerid, 319.899627, 233.949798, "furniturejob:fjui_gwframe6");
		PlayerTextDrawTextSize(playerid, factory_job_5_p[8][playerid], 58.000000, 57.000000);
		PlayerTextDrawAlignment(playerid, factory_job_5_p[8][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_5_p[8][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_5_p[8][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_5_p[8][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_5_p[8][playerid], 0);
	}
	if(factory_job_5_p[9][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_5_p[9][playerid] = CreatePlayerTextDraw(playerid, 114.999908, 122.000000, "furniturejob:fjui_cwframe4");
		PlayerTextDrawTextSize(playerid, factory_job_5_p[9][playerid], 58.000000, 57.000000);
		PlayerTextDrawAlignment(playerid, factory_job_5_p[9][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_5_p[9][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_5_p[9][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_5_p[9][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_5_p[9][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_5_p[9][playerid], true);
	}
	if(factory_job_5_p[10][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_5_p[10][playerid] = CreatePlayerTextDraw(playerid, 114.999908, 194.699920, "furniturejob:fjui_cwframe2");
		PlayerTextDrawTextSize(playerid, factory_job_5_p[10][playerid], 58.000000, 57.000000);
		PlayerTextDrawAlignment(playerid, factory_job_5_p[10][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_5_p[10][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_5_p[10][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_5_p[10][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_5_p[10][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_5_p[10][playerid], true);
	}
	if(factory_job_5_p[11][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_5_p[11][playerid] = CreatePlayerTextDraw(playerid, 114.999908, 265.699920, "furniturejob:fjui_cwframe6");
		PlayerTextDrawTextSize(playerid, factory_job_5_p[11][playerid], 58.000000, 57.000000);
		PlayerTextDrawAlignment(playerid, factory_job_5_p[11][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_5_p[11][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_5_p[11][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_5_p[11][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_5_p[11][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_5_p[11][playerid], true);
	}
	if(factory_job_5_p[12][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_5_p[12][playerid] = CreatePlayerTextDraw(playerid, 444.999938, 122.000000, "furniturejob:fjui_cwframe1");
		PlayerTextDrawTextSize(playerid, factory_job_5_p[12][playerid], 58.000000, 57.000000);
		PlayerTextDrawAlignment(playerid, factory_job_5_p[12][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_5_p[12][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_5_p[12][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_5_p[12][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_5_p[12][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_5_p[12][playerid], true);
	}
	if(factory_job_5_p[13][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_5_p[13][playerid] = CreatePlayerTextDraw(playerid, 444.999938, 194.699920, "furniturejob:fjui_cwframe3");
		PlayerTextDrawTextSize(playerid, factory_job_5_p[13][playerid], 58.000000, 57.000000);
		PlayerTextDrawAlignment(playerid, factory_job_5_p[13][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_5_p[13][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_5_p[13][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_5_p[13][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_5_p[13][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_5_p[13][playerid], true);
	}
	if(factory_job_5_p[14][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_5_p[14][playerid] = CreatePlayerTextDraw(playerid, 444.999938, 265.699920, "furniturejob:fjui_cwframe5");
		PlayerTextDrawTextSize(playerid, factory_job_5_p[14][playerid], 58.000000, 57.000000);
		PlayerTextDrawAlignment(playerid, factory_job_5_p[14][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_5_p[14][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_5_p[14][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_5_p[14][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_5_p[14][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_5_p[14][playerid], true);
	}

	if(factory_job_5_p[15][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_5_p[15][playerid] = CreatePlayerTextDraw(playerid, 208.300079, 361.199951, "furniturejob:fjui_p1");
		PlayerTextDrawTextSize(playerid, factory_job_5_p[15][playerid], 87.699928, 29.110000);
		PlayerTextDrawAlignment(playerid, factory_job_5_p[15][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_5_p[15][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_5_p[15][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_5_p[15][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_5_p[15][playerid], 0);
	}
	return true;
}

stock create_factory_job_4_p(playerid)
{
	if(factory_job_4_p[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_4_p[0][playerid] = CreatePlayerTextDraw(playerid, 127.599990, 37.300010, "x1");
		PlayerTextDrawLetterSize(playerid, factory_job_4_p[0][playerid], 0.443666, 2.039700);
		PlayerTextDrawAlignment(playerid, factory_job_4_p[0][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_4_p[0][playerid], 1962902271);
		PlayerTextDrawSetShadow(playerid, factory_job_4_p[0][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, factory_job_4_p[0][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_4_p[0][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_4_p[0][playerid], 1);
	}
	if(factory_job_4_p[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{	
		factory_job_4_p[1][playerid] = CreatePlayerTextDraw(playerid, 319.999938, 68.000015, "+_12312");
		PlayerTextDrawLetterSize(playerid, factory_job_4_p[1][playerid], 0.574998, 2.678518);
		PlayerTextDrawTextSize(playerid, factory_job_4_p[1][playerid], 0.000000, 513.360351);
		PlayerTextDrawAlignment(playerid, factory_job_4_p[1][playerid], 2);
		PlayerTextDrawColor(playerid, factory_job_4_p[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, factory_job_4_p[1][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, factory_job_4_p[1][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_4_p[1][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_4_p[1][playerid], 1);
	}
	if(factory_job_4_p[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_4_p[2][playerid] = CreatePlayerTextDraw(playerid, 349.000000, 363.000000, "0000000");
		PlayerTextDrawLetterSize(playerid, factory_job_4_p[2][playerid], 0.554332, 2.309334);
		PlayerTextDrawAlignment(playerid, factory_job_4_p[2][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_4_p[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, factory_job_4_p[2][playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_4_p[2][playerid], 30);
		PlayerTextDrawFont(playerid, factory_job_4_p[2][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_4_p[2][playerid], 1);
	}
	if(factory_job_4_p[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_4_p[3][playerid] = CreatePlayerTextDraw(playerid, 244.800048, 119.600051, "furniturejob:fjui_gnightstand1");
		PlayerTextDrawTextSize(playerid, factory_job_4_p[3][playerid], 75.000000, 51.000000);
		PlayerTextDrawAlignment(playerid, factory_job_4_p[3][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_4_p[3][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_4_p[3][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_4_p[3][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_4_p[3][playerid], 0);
	}
	if(factory_job_4_p[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_4_p[4][playerid] = CreatePlayerTextDraw(playerid, 319.899841, 119.600051, "furniturejob:fjui_gnightstand2");
		PlayerTextDrawTextSize(playerid, factory_job_4_p[4][playerid], 75.000000, 51.000000);
		PlayerTextDrawAlignment(playerid, factory_job_4_p[4][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_4_p[4][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_4_p[4][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_4_p[4][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_4_p[4][playerid], 0);
	}
	if(factory_job_4_p[5][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_4_p[5][playerid] = CreatePlayerTextDraw(playerid, 244.800048, 170.700408, "furniturejob:fjui_gnightstand3");
		PlayerTextDrawTextSize(playerid, factory_job_4_p[5][playerid], 75.000000, 51.000000);
		PlayerTextDrawAlignment(playerid, factory_job_4_p[5][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_4_p[5][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_4_p[5][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_4_p[5][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_4_p[5][playerid], 0);
	}
	if(factory_job_4_p[6][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_4_p[6][playerid] = CreatePlayerTextDraw(playerid, 319.899841, 170.700408, "furniturejob:fjui_gnightstand4");
		PlayerTextDrawTextSize(playerid, factory_job_4_p[6][playerid], 75.000000, 51.000000);
		PlayerTextDrawAlignment(playerid, factory_job_4_p[6][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_4_p[6][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_4_p[6][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_4_p[6][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_4_p[6][playerid], 0);
	}
	if(factory_job_4_p[7][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_4_p[7][playerid] = CreatePlayerTextDraw(playerid, 244.800048, 221.800872, "furniturejob:fjui_gnightstand5");
		PlayerTextDrawTextSize(playerid, factory_job_4_p[7][playerid], 75.000000, 51.000000);
		PlayerTextDrawAlignment(playerid, factory_job_4_p[7][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_4_p[7][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_4_p[7][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_4_p[7][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_4_p[7][playerid], 0);
	}
	if(factory_job_4_p[8][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_4_p[8][playerid] = CreatePlayerTextDraw(playerid, 319.899841, 221.800872, "furniturejob:fjui_gnightstand6");
		PlayerTextDrawTextSize(playerid, factory_job_4_p[8][playerid], 75.000000, 51.000000);
		PlayerTextDrawAlignment(playerid, factory_job_4_p[8][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_4_p[8][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_4_p[8][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_4_p[8][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_4_p[8][playerid], 0);
	}
	if(factory_job_4_p[9][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_4_p[9][playerid] = CreatePlayerTextDraw(playerid, 114.999908, 122.000000, "furniturejob:fjui_cnightstand4");
		PlayerTextDrawTextSize(playerid, factory_job_4_p[9][playerid], 75.000000, 51.000000);
		PlayerTextDrawAlignment(playerid, factory_job_4_p[9][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_4_p[9][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_4_p[9][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_4_p[9][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_4_p[9][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_4_p[9][playerid], true);
	}
	if(factory_job_4_p[10][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_4_p[10][playerid] = CreatePlayerTextDraw(playerid, 114.999908, 194.699920, "furniturejob:fjui_cnightstand2");
		PlayerTextDrawTextSize(playerid, factory_job_4_p[10][playerid], 75.000000, 51.000000);
		PlayerTextDrawAlignment(playerid, factory_job_4_p[10][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_4_p[10][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_4_p[10][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_4_p[10][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_4_p[10][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_4_p[10][playerid], true);
	}
	if(factory_job_4_p[11][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_4_p[11][playerid] = CreatePlayerTextDraw(playerid, 114.999908, 265.699920, "furniturejob:fjui_cnightstand6");
		PlayerTextDrawTextSize(playerid, factory_job_4_p[11][playerid], 75.000000, 51.000000);
		PlayerTextDrawAlignment(playerid, factory_job_4_p[11][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_4_p[11][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_4_p[11][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_4_p[11][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_4_p[11][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_4_p[11][playerid], true);
	}
	if(factory_job_4_p[12][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_4_p[12][playerid] = CreatePlayerTextDraw(playerid, 444.999938, 122.000000, "furniturejob:fjui_cnightstand1");
		PlayerTextDrawTextSize(playerid, factory_job_4_p[12][playerid], 75.000000, 51.000000);
		PlayerTextDrawAlignment(playerid, factory_job_4_p[12][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_4_p[12][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_4_p[12][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_4_p[12][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_4_p[12][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_4_p[12][playerid], true);
	}
	if(factory_job_4_p[13][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_4_p[13][playerid] = CreatePlayerTextDraw(playerid, 444.999938, 194.699920, "furniturejob:fjui_cnightstand3");
		PlayerTextDrawTextSize(playerid, factory_job_4_p[13][playerid], 75.000000, 51.000000);
		PlayerTextDrawAlignment(playerid, factory_job_4_p[13][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_4_p[13][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_4_p[13][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_4_p[13][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_4_p[13][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_4_p[13][playerid], true);
	}
	if(factory_job_4_p[14][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_4_p[14][playerid] = CreatePlayerTextDraw(playerid, 444.999938, 265.699920, "furniturejob:fjui_cnightstand5");
		PlayerTextDrawTextSize(playerid, factory_job_4_p[14][playerid], 75.000000, 51.000000);
		PlayerTextDrawAlignment(playerid, factory_job_4_p[14][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_4_p[14][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_4_p[14][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_4_p[14][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_4_p[14][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_4_p[14][playerid], true);
	}

	if(factory_job_4_p[15][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_4_p[15][playerid] = CreatePlayerTextDraw(playerid, 208.300079, 361.199951, "furniturejob:fjui_p1");
		PlayerTextDrawTextSize(playerid, factory_job_4_p[15][playerid], 87.699928, 29.110000);
		PlayerTextDrawAlignment(playerid, factory_job_4_p[15][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_4_p[15][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_4_p[15][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_4_p[15][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_4_p[15][playerid], 0);
	}

	return true;
}

stock create_factory_job_3_p(playerid)
{
	if(factory_job_3_p[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_3_p[0][playerid] = CreatePlayerTextDraw(playerid, 127.599990, 37.300010, "x1");
		PlayerTextDrawLetterSize(playerid, factory_job_3_p[0][playerid], 0.443666, 2.039700);
		PlayerTextDrawAlignment(playerid, factory_job_3_p[0][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_3_p[0][playerid], 1962902271);
		PlayerTextDrawSetShadow(playerid, factory_job_3_p[0][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, factory_job_3_p[0][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_3_p[0][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_3_p[0][playerid], 1);
	}
	if(factory_job_3_p[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_3_p[1][playerid] = CreatePlayerTextDraw(playerid, 319.999938, 68.000015, "+_12312");
		PlayerTextDrawLetterSize(playerid, factory_job_3_p[1][playerid], 0.574998, 2.678518);
		PlayerTextDrawTextSize(playerid, factory_job_3_p[1][playerid], 0.000000, 513.360351);
		PlayerTextDrawAlignment(playerid, factory_job_3_p[1][playerid], 2);
		PlayerTextDrawColor(playerid, factory_job_3_p[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, factory_job_3_p[1][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, factory_job_3_p[1][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_3_p[1][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_3_p[1][playerid], 1);
	}
	if(factory_job_3_p[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_3_p[2][playerid] = CreatePlayerTextDraw(playerid, 349.000000, 363.000000, "0000000");
		PlayerTextDrawLetterSize(playerid, factory_job_3_p[2][playerid], 0.554332, 2.309334);
		PlayerTextDrawAlignment(playerid, factory_job_3_p[2][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_3_p[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, factory_job_3_p[2][playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_3_p[2][playerid], 30);
		PlayerTextDrawFont(playerid, factory_job_3_p[2][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_3_p[2][playerid], 1);
	}
	if(factory_job_3_p[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_3_p[3][playerid] = CreatePlayerTextDraw(playerid, 206.000000, 140.000000, "furniturejob:fjui_ctable1");
		PlayerTextDrawTextSize(playerid, factory_job_3_p[3][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_3_p[3][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_3_p[3][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_3_p[3][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_3_p[3][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_3_p[3][playerid], 0);
	}
	if(factory_job_3_p[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_3_p[4][playerid] = CreatePlayerTextDraw(playerid, 319.899932, 140.000000, "furniturejob:fjui_gtable2");
		PlayerTextDrawTextSize(playerid, factory_job_3_p[4][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_3_p[4][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_3_p[4][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_3_p[4][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_3_p[4][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_3_p[4][playerid], 0);
	}
	if(factory_job_3_p[5][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_3_p[5][playerid] = CreatePlayerTextDraw(playerid, 206.000000, 190.900192, "furniturejob:fjui_gtable3");
		PlayerTextDrawTextSize(playerid, factory_job_3_p[5][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_3_p[5][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_3_p[5][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_3_p[5][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_3_p[5][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_3_p[5][playerid], 0);
	}
	if(factory_job_3_p[6][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_3_p[6][playerid] = CreatePlayerTextDraw(playerid, 319.899932, 190.900192, "furniturejob:fjui_ctable4");
		PlayerTextDrawTextSize(playerid, factory_job_3_p[6][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_3_p[6][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_3_p[6][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_3_p[6][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_3_p[6][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_3_p[6][playerid], 0);
	}
	if(factory_job_3_p[7][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_3_p[7][playerid] = CreatePlayerTextDraw(playerid, 206.000000, 241.699645, "furniturejob:fjui_gtable5");
		PlayerTextDrawTextSize(playerid, factory_job_3_p[7][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_3_p[7][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_3_p[7][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_3_p[7][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_3_p[7][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_3_p[7][playerid], 0);
	}
	if(factory_job_3_p[8][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_3_p[8][playerid] = CreatePlayerTextDraw(playerid, 319.899932, 241.699645, "furniturejob:fjui_gtable6");
		PlayerTextDrawTextSize(playerid, factory_job_3_p[8][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_3_p[8][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_3_p[8][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_3_p[8][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_3_p[8][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_3_p[8][playerid], 0);
	}
	if(factory_job_3_p[9][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_3_p[9][playerid] = CreatePlayerTextDraw(playerid, 79.000000, 122.000000, "furniturejob:fjui_ctable4");
		PlayerTextDrawTextSize(playerid, factory_job_3_p[9][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_3_p[9][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_3_p[9][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_3_p[9][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_3_p[9][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_3_p[9][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_3_p[9][playerid], true);
	}
	if(factory_job_3_p[10][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_3_p[10][playerid] = CreatePlayerTextDraw(playerid, 79.000000, 194.699920, "furniturejob:fjui_ctable2");
		PlayerTextDrawTextSize(playerid, factory_job_3_p[10][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_3_p[10][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_3_p[10][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_3_p[10][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_3_p[10][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_3_p[10][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_3_p[10][playerid], true);
	}
	if(factory_job_3_p[11][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_3_p[11][playerid] = CreatePlayerTextDraw(playerid, 79.000000, 265.699920, "furniturejob:fjui_ctable6");
		PlayerTextDrawTextSize(playerid, factory_job_3_p[11][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_3_p[11][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_3_p[11][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_3_p[11][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_3_p[11][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_3_p[11][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_3_p[11][playerid], true);
	}
	if(factory_job_3_p[12][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_3_p[12][playerid] = CreatePlayerTextDraw(playerid, 451.000000, 122.000000, "furniturejob:fjui_ctable1");
		PlayerTextDrawTextSize(playerid, factory_job_3_p[12][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_3_p[12][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_3_p[12][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_3_p[12][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_3_p[12][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_3_p[12][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_3_p[12][playerid], true);
	}
	if(factory_job_3_p[13][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_3_p[13][playerid] = CreatePlayerTextDraw(playerid, 451.000000, 194.699920, "furniturejob:fjui_ctable3");
		PlayerTextDrawTextSize(playerid, factory_job_3_p[13][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_3_p[13][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_3_p[13][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_3_p[13][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_3_p[13][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_3_p[13][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_3_p[13][playerid], true);
	}
	if(factory_job_3_p[14][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_3_p[14][playerid] = CreatePlayerTextDraw(playerid, 451.000000, 265.699920, "furniturejob:fjui_ctable5");
		PlayerTextDrawTextSize(playerid, factory_job_3_p[14][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_3_p[14][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_3_p[14][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_3_p[14][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_3_p[14][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_3_p[14][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_3_p[14][playerid], true);
	}
	if(factory_job_3_p[15][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_3_p[15][playerid] = CreatePlayerTextDraw(playerid, 208.300079, 361.199951, "furniturejob:fjui_p1");
		PlayerTextDrawTextSize(playerid, factory_job_3_p[15][playerid], 87.699928, 29.110000);
		PlayerTextDrawAlignment(playerid, factory_job_3_p[15][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_3_p[15][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_3_p[15][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_3_p[15][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_3_p[15][playerid], 0);
	}
	return true;
}
stock create_factory_job_2_p(playerid)
{
	if(factory_job_2_p[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_2_p[0][playerid] = CreatePlayerTextDraw(playerid, 127.599990, 37.300010, "x1");
		PlayerTextDrawLetterSize(playerid, factory_job_2_p[0][playerid], 0.443666, 2.039700);
		PlayerTextDrawAlignment(playerid, factory_job_2_p[0][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_2_p[0][playerid], 1962902271);
		PlayerTextDrawSetShadow(playerid, factory_job_2_p[0][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, factory_job_2_p[0][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_2_p[0][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_2_p[0][playerid], 1);
	}
	if(factory_job_2_p[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_2_p[1][playerid] = CreatePlayerTextDraw(playerid, 319.999938, 68.000015, "+_12312");
		PlayerTextDrawLetterSize(playerid, factory_job_2_p[1][playerid], 0.574998, 2.678518);
		PlayerTextDrawTextSize(playerid, factory_job_2_p[1][playerid], 0.000000, 513.360351);
		PlayerTextDrawAlignment(playerid, factory_job_2_p[1][playerid], 2);
		PlayerTextDrawColor(playerid, factory_job_2_p[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, factory_job_2_p[1][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, factory_job_2_p[1][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_2_p[1][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_2_p[1][playerid], 1);
	}
	if(factory_job_2_p[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_2_p[2][playerid] = CreatePlayerTextDraw(playerid, 349.000000, 363.000000, "0000000");
		PlayerTextDrawLetterSize(playerid, factory_job_2_p[2][playerid], 0.554332, 2.309334);
		PlayerTextDrawAlignment(playerid, factory_job_2_p[2][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_2_p[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, factory_job_2_p[2][playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_2_p[2][playerid], 30);
		PlayerTextDrawFont(playerid, factory_job_2_p[2][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_2_p[2][playerid], 1);
	}
	if(factory_job_2_p[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_2_p[3][playerid] = CreatePlayerTextDraw(playerid, 206.000000, 140.000000, "furniturejob:fjui_cbed1");
		PlayerTextDrawTextSize(playerid, factory_job_2_p[3][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_2_p[3][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_2_p[3][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_2_p[3][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_2_p[3][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_2_p[3][playerid], 0);
	}
	if(factory_job_2_p[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_2_p[4][playerid] = CreatePlayerTextDraw(playerid, 319.899932, 140.000000, "furniturejob:fjui_gbed2");
		PlayerTextDrawTextSize(playerid, factory_job_2_p[4][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_2_p[4][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_2_p[4][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_2_p[4][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_2_p[4][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_2_p[4][playerid], 0);
	}
	if(factory_job_2_p[5][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_2_p[5][playerid] = CreatePlayerTextDraw(playerid, 206.000000, 190.900192, "furniturejob:fjui_gbed3");
		PlayerTextDrawTextSize(playerid, factory_job_2_p[5][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_2_p[5][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_2_p[5][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_2_p[5][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_2_p[5][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_2_p[5][playerid], 0);
	}
	if(factory_job_2_p[6][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_2_p[6][playerid] = CreatePlayerTextDraw(playerid, 319.899932, 190.900192, "furniturejob:fjui_cbed4");
		PlayerTextDrawTextSize(playerid, factory_job_2_p[6][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_2_p[6][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_2_p[6][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_2_p[6][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_2_p[6][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_2_p[6][playerid], 0);
	}
	if(factory_job_2_p[7][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_2_p[7][playerid] = CreatePlayerTextDraw(playerid, 206.000000, 241.699645, "furniturejob:fjui_gbed5");
		PlayerTextDrawTextSize(playerid, factory_job_2_p[7][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_2_p[7][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_2_p[7][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_2_p[7][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_2_p[7][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_2_p[7][playerid], 0);
	}
	if(factory_job_2_p[8][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_2_p[8][playerid] = CreatePlayerTextDraw(playerid, 319.899932, 241.699645, "furniturejob:fjui_gbed6");
		PlayerTextDrawTextSize(playerid, factory_job_2_p[8][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_2_p[8][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_2_p[8][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_2_p[8][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_2_p[8][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_2_p[8][playerid], 0);
	}
	if(factory_job_2_p[9][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_2_p[9][playerid] = CreatePlayerTextDraw(playerid, 79.000000, 122.000000, "furniturejob:fjui_cbed4");
		PlayerTextDrawTextSize(playerid, factory_job_2_p[9][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_2_p[9][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_2_p[9][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_2_p[9][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_2_p[9][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_2_p[9][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_2_p[9][playerid], true);
	}
	if(factory_job_2_p[10][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_2_p[10][playerid] = CreatePlayerTextDraw(playerid, 79.000000, 194.699920, "furniturejob:fjui_cbed2");
		PlayerTextDrawTextSize(playerid, factory_job_2_p[10][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_2_p[10][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_2_p[10][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_2_p[10][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_2_p[10][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_2_p[10][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_2_p[10][playerid], true);
	}
	if(factory_job_2_p[11][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_2_p[11][playerid] = CreatePlayerTextDraw(playerid, 79.000000, 265.699920, "furniturejob:fjui_cbed6");
		PlayerTextDrawTextSize(playerid, factory_job_2_p[11][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_2_p[11][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_2_p[11][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_2_p[11][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_2_p[11][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_2_p[11][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_2_p[11][playerid], true);
	}
	if(factory_job_2_p[12][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_2_p[12][playerid] = CreatePlayerTextDraw(playerid, 451.000000, 122.000000, "furniturejob:fjui_cbed1");
		PlayerTextDrawTextSize(playerid, factory_job_2_p[12][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_2_p[12][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_2_p[12][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_2_p[12][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_2_p[12][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_2_p[12][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_2_p[12][playerid], true);
	}
	if(factory_job_2_p[13][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_2_p[13][playerid] = CreatePlayerTextDraw(playerid, 451.000000, 194.699920, "furniturejob:fjui_cbed3");
		PlayerTextDrawTextSize(playerid, factory_job_2_p[13][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_2_p[13][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_2_p[13][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_2_p[13][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_2_p[13][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_2_p[13][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_2_p[13][playerid], true);
	}
	if(factory_job_2_p[14][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_2_p[14][playerid] = CreatePlayerTextDraw(playerid, 451.000000, 265.699920, "furniturejob:fjui_cbed5");
		PlayerTextDrawTextSize(playerid, factory_job_2_p[14][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_2_p[14][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_2_p[14][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_2_p[14][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_2_p[14][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_2_p[14][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_2_p[14][playerid], true);
	}
	if(factory_job_2_p[15][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_2_p[15][playerid] = CreatePlayerTextDraw(playerid, 208.300079, 361.199951, "furniturejob:fjui_p1");
		PlayerTextDrawTextSize(playerid, factory_job_2_p[15][playerid], 87.699928, 29.110000);
		PlayerTextDrawAlignment(playerid, factory_job_2_p[15][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_2_p[15][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_2_p[15][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_2_p[15][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_2_p[15][playerid], 0);
	}
	return true;
}

stock create_factory_job_1_p(playerid)
{

	if(factory_job_1_p[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_1_p[0][playerid] = CreatePlayerTextDraw(playerid, 127.599990, 37.300010, "x1");
		PlayerTextDrawLetterSize(playerid, factory_job_1_p[0][playerid], 0.443666, 2.039700);
		PlayerTextDrawAlignment(playerid, factory_job_1_p[0][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_1_p[0][playerid], 1962902271);
		PlayerTextDrawSetShadow(playerid, factory_job_1_p[0][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, factory_job_1_p[0][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_1_p[0][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_1_p[0][playerid], 1);
	}
	if(factory_job_1_p[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{	
		factory_job_1_p[1][playerid] = CreatePlayerTextDraw(playerid, 319.999938, 68.000015, "+_12312");
		PlayerTextDrawLetterSize(playerid, factory_job_1_p[1][playerid], 0.574998, 2.678518);
		PlayerTextDrawTextSize(playerid, factory_job_1_p[1][playerid], 0.000000, 513.360351);
		PlayerTextDrawAlignment(playerid, factory_job_1_p[1][playerid], 2);
		PlayerTextDrawColor(playerid, factory_job_1_p[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, factory_job_1_p[1][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, factory_job_1_p[1][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_1_p[1][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_1_p[1][playerid], 1);
	}
	if(factory_job_1_p[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_1_p[2][playerid] = CreatePlayerTextDraw(playerid, 349.000000, 363.000000, "0000000");
		PlayerTextDrawLetterSize(playerid, factory_job_1_p[2][playerid], 0.554332, 2.309334);
		PlayerTextDrawAlignment(playerid, factory_job_1_p[2][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_1_p[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, factory_job_1_p[2][playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_1_p[2][playerid], 30);
		PlayerTextDrawFont(playerid, factory_job_1_p[2][playerid], 1);
		PlayerTextDrawSetProportional(playerid, factory_job_1_p[2][playerid], 1);
	}
	if(factory_job_1_p[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_1_p[3][playerid] = CreatePlayerTextDraw(playerid, 206.000000, 140.000000, "furniturejob:fjui_csofa1");
		PlayerTextDrawTextSize(playerid, factory_job_1_p[3][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_1_p[3][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_1_p[3][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_1_p[3][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_1_p[3][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_1_p[3][playerid], 0);
	}
	if(factory_job_1_p[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_1_p[4][playerid] = CreatePlayerTextDraw(playerid, 319.899932, 140.000000, "furniturejob:fjui_gsofa2");
		PlayerTextDrawTextSize(playerid, factory_job_1_p[4][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_1_p[4][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_1_p[4][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_1_p[4][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_1_p[4][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_1_p[4][playerid], 0);
	}
	if(factory_job_1_p[5][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_1_p[5][playerid] = CreatePlayerTextDraw(playerid, 206.000000, 190.900192, "furniturejob:fjui_gsofa3");
		PlayerTextDrawTextSize(playerid, factory_job_1_p[5][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_1_p[5][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_1_p[5][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_1_p[5][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_1_p[5][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_1_p[5][playerid], 0);
	}
	if(factory_job_1_p[6][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_1_p[6][playerid] = CreatePlayerTextDraw(playerid, 319.899932, 190.900192, "furniturejob:fjui_csofa4");
		PlayerTextDrawTextSize(playerid, factory_job_1_p[6][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_1_p[6][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_1_p[6][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_1_p[6][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_1_p[6][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_1_p[6][playerid], 0);
	}
	if(factory_job_1_p[7][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_1_p[7][playerid] = CreatePlayerTextDraw(playerid, 206.000000, 241.699645, "furniturejob:fjui_gsofa5");
		PlayerTextDrawTextSize(playerid, factory_job_1_p[7][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_1_p[7][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_1_p[7][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_1_p[7][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_1_p[7][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_1_p[7][playerid], 0);
	}
	if(factory_job_1_p[8][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_1_p[8][playerid] = CreatePlayerTextDraw(playerid, 319.899932, 241.699645, "furniturejob:fjui_gsofa6");
		PlayerTextDrawTextSize(playerid, factory_job_1_p[8][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_1_p[8][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_1_p[8][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_1_p[8][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_1_p[8][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_1_p[8][playerid], 0);
	}
	if(factory_job_1_p[9][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_1_p[9][playerid] = CreatePlayerTextDraw(playerid, 79.000000, 122.000000, "furniturejob:fjui_csofa4");
		PlayerTextDrawTextSize(playerid, factory_job_1_p[9][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_1_p[9][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_1_p[9][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_1_p[9][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_1_p[9][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_1_p[9][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_1_p[9][playerid], true);
	}
	if(factory_job_1_p[10][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_1_p[10][playerid] = CreatePlayerTextDraw(playerid, 79.000000, 194.699920, "furniturejob:fjui_csofa2");
		PlayerTextDrawTextSize(playerid, factory_job_1_p[10][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_1_p[10][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_1_p[10][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_1_p[10][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_1_p[10][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_1_p[10][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_1_p[10][playerid], true);
	}
	if(factory_job_1_p[11][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_1_p[11][playerid] = CreatePlayerTextDraw(playerid, 79.000000, 265.699920, "furniturejob:fjui_csofa6");
		PlayerTextDrawTextSize(playerid, factory_job_1_p[11][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_1_p[11][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_1_p[11][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_1_p[11][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_1_p[11][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_1_p[11][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_1_p[11][playerid], true);
	}
	if(factory_job_1_p[12][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_1_p[12][playerid] = CreatePlayerTextDraw(playerid, 451.000000, 122.000000, "furniturejob:fjui_csofa1");
		PlayerTextDrawTextSize(playerid, factory_job_1_p[12][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_1_p[12][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_1_p[12][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_1_p[12][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_1_p[12][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_1_p[12][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_1_p[12][playerid], true);
	}
	if(factory_job_1_p[13][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_1_p[13][playerid] = CreatePlayerTextDraw(playerid, 451.000000, 194.699920, "furniturejob:fjui_csofa3");
		PlayerTextDrawTextSize(playerid, factory_job_1_p[13][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_1_p[13][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_1_p[13][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_1_p[13][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_1_p[13][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_1_p[13][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_1_p[13][playerid], true);
	}
	if(factory_job_1_p[14][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_1_p[14][playerid] = CreatePlayerTextDraw(playerid, 451.000000, 265.699920, "furniturejob:fjui_csofa5");
		PlayerTextDrawTextSize(playerid, factory_job_1_p[14][playerid], 114.000000, 50.829971);
		PlayerTextDrawAlignment(playerid, factory_job_1_p[14][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_1_p[14][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_1_p[14][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_1_p[14][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_1_p[14][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, factory_job_1_p[14][playerid], true);
	}
	if(factory_job_1_p[15][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		factory_job_1_p[15][playerid] = CreatePlayerTextDraw(playerid, 208.300079, 361.199951, "furniturejob:fjui_p1");
		PlayerTextDrawTextSize(playerid, factory_job_1_p[15][playerid], 87.699928, 29.110000);
		PlayerTextDrawAlignment(playerid, factory_job_1_p[15][playerid], 1);
		PlayerTextDrawColor(playerid, factory_job_1_p[15][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, factory_job_1_p[15][playerid], 255);
		PlayerTextDrawFont(playerid, factory_job_1_p[15][playerid], 4);
		PlayerTextDrawSetProportional(playerid, factory_job_1_p[15][playerid], 0);
	}
	return true;
}

stock create_autsalon_p(playerid)
{
	if(autosalon_info_td_p[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		autosalon_info_td_p[0][playerid] = CreatePlayerTextDraw(playerid, 33.000003, 110.755546, "250 KM/H"); // Text element
		PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[0][playerid], 0.263330, 1.620740);
		PlayerTextDrawAlignment(playerid, autosalon_info_td_p[0][playerid], 2);
		PlayerTextDrawColor(playerid, autosalon_info_td_p[0][playerid], -1);
		PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[0][playerid], 0);
		PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[0][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, autosalon_info_td_p[0][playerid], 51);
		PlayerTextDrawFont(playerid, autosalon_info_td_p[0][playerid], 2);
		PlayerTextDrawSetProportional(playerid, autosalon_info_td_p[0][playerid], 1);
	}
	if(autosalon_info_td_p[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{	
		autosalon_info_td_p[1][playerid] = CreatePlayerTextDraw(playerid, 18.999992, 143.525909, "35L"); // Text element
		PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[1][playerid], 0.273997, 1.550220);
		PlayerTextDrawAlignment(playerid, autosalon_info_td_p[1][playerid], 2);
		PlayerTextDrawColor(playerid, autosalon_info_td_p[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[1][playerid], 0);
		PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[1][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, autosalon_info_td_p[1][playerid], 51);
		PlayerTextDrawFont(playerid, autosalon_info_td_p[1][playerid], 2);
		PlayerTextDrawSetProportional(playerid, autosalon_info_td_p[1][playerid], 1);
	}
	if(autosalon_info_td_p[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		autosalon_info_td_p[2][playerid] = CreatePlayerTextDraw(playerid, 37.666660, 178.370330, "30L/ 100KM"); // Text element
		PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[2][playerid], 0.259997, 1.525333);
		PlayerTextDrawAlignment(playerid, autosalon_info_td_p[2][playerid], 2);
		PlayerTextDrawColor(playerid, autosalon_info_td_p[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[2][playerid], 0);
		PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[2][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, autosalon_info_td_p[2][playerid], 51);
		PlayerTextDrawFont(playerid, autosalon_info_td_p[2][playerid], 2);
		PlayerTextDrawSetProportional(playerid, autosalon_info_td_p[2][playerid], 1);
	}
	if(autosalon_info_td_p[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		autosalon_info_td_p[3][playerid] = CreatePlayerTextDraw(playerid, 24.999996, 212.800018, "35 KG"); // Text element
		PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[3][playerid], 0.283665, 1.517035);
		PlayerTextDrawAlignment(playerid, autosalon_info_td_p[3][playerid], 2);
		PlayerTextDrawColor(playerid, autosalon_info_td_p[3][playerid], -1);
		PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[3][playerid], 0);
		PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[3][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, autosalon_info_td_p[3][playerid], 51);
		PlayerTextDrawFont(playerid, autosalon_info_td_p[3][playerid], 2);
		PlayerTextDrawSetProportional(playerid, autosalon_info_td_p[3][playerid], 1);
	}
	if(autosalon_info_td_p[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		autosalon_info_td_p[4][playerid] = CreatePlayerTextDraw(playerid, 12.333324, 261.333312, "3"); // Text element
		PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[4][playerid], 0.309332, 1.620740);
		PlayerTextDrawAlignment(playerid, autosalon_info_td_p[4][playerid], 2);
		PlayerTextDrawColor(playerid, autosalon_info_td_p[4][playerid], -1);
		PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[4][playerid], 0);
		PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[4][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, autosalon_info_td_p[4][playerid], 51);
		PlayerTextDrawFont(playerid, autosalon_info_td_p[4][playerid], 2);
		PlayerTextDrawSetProportional(playerid, autosalon_info_td_p[4][playerid], 1);
	}
	if(autosalon_info_td_p[5][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		autosalon_info_td_p[5][playerid] = CreatePlayerTextDraw(playerid, 48.000007, 71.762916, "10000000_RUB"); // Text element
		PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[5][playerid], 0.279998, 1.624886);
		PlayerTextDrawAlignment(playerid, autosalon_info_td_p[5][playerid], 2);
		PlayerTextDrawColor(playerid, autosalon_info_td_p[5][playerid], 2113895167);
		PlayerTextDrawUseBox(playerid, autosalon_info_td_p[5][playerid], true);
		PlayerTextDrawBoxColor(playerid, autosalon_info_td_p[5][playerid], 0);
		PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[5][playerid], 0);
		PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[5][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, autosalon_info_td_p[5][playerid], 51);
		PlayerTextDrawFont(playerid, autosalon_info_td_p[5][playerid], 2);
		PlayerTextDrawSetProportional(playerid, autosalon_info_td_p[5][playerid], 1);
	}
	if(autosalon_info_td_p[6][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		autosalon_info_td_p[6][playerid] = CreatePlayerTextDraw(playerid, 9.333311, 56.414775, "BENTLY GTA CONTINENTAL"); // Text element
		PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[6][playerid], 0.274666, 1.736889);
		PlayerTextDrawAlignment(playerid, autosalon_info_td_p[6][playerid], 1);
		PlayerTextDrawColor(playerid, autosalon_info_td_p[6][playerid], -1);
		PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[6][playerid], 0);
		PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[6][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, autosalon_info_td_p[6][playerid], 51);
		PlayerTextDrawFont(playerid, autosalon_info_td_p[6][playerid], 2);
		PlayerTextDrawSetProportional(playerid, autosalon_info_td_p[6][playerid], 1);
	}

	return true;

}

stock create_autosalon_p_2(playerid)
{
	if(autosalon_info_td_p[7][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		autosalon_info_td_p[7][playerid] = CreatePlayerTextDraw(playerid, 559.666503, 150.992614, "LD_BEAT:chit"); // Texture element
		PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[7][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, autosalon_info_td_p[7][playerid], 40.333301, 47.288799);
		PlayerTextDrawAlignment(playerid, autosalon_info_td_p[7][playerid], 2);
		PlayerTextDrawColor(playerid, autosalon_info_td_p[7][playerid], -551788033);
		PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[7][playerid], 0);
		PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[7][playerid], 0);
		PlayerTextDrawFont(playerid, autosalon_info_td_p[7][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, autosalon_info_td_p[7][playerid], true);
	}
	if(autosalon_info_td_p[8][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		autosalon_info_td_p[8][playerid] = CreatePlayerTextDraw(playerid, 593.332824, 150.992599, "LD_BEAT:chit"); // Texture element
		PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[8][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, autosalon_info_td_p[8][playerid], 40.333301, 47.288879);
		PlayerTextDrawAlignment(playerid, autosalon_info_td_p[8][playerid], 2);
		PlayerTextDrawColor(playerid, autosalon_info_td_p[8][playerid], 16777215);
		PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[8][playerid], 0);
		PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[8][playerid], 0);
		PlayerTextDrawFont(playerid, autosalon_info_td_p[8][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, autosalon_info_td_p[8][playerid], true);
	}
	if(autosalon_info_td_p[9][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		autosalon_info_td_p[9][playerid] = CreatePlayerTextDraw(playerid, 593.999877, 187.081558, "LD_BEAT:chit"); // Texture element
		PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[9][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, autosalon_info_td_p[9][playerid], 40.333301, 47.288799);
		PlayerTextDrawAlignment(playerid, autosalon_info_td_p[9][playerid], 2);
		PlayerTextDrawColor(playerid, autosalon_info_td_p[9][playerid], -1276806657);
		PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[9][playerid], 0);
		PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[9][playerid], 0);
		PlayerTextDrawFont(playerid, autosalon_info_td_p[9][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, autosalon_info_td_p[9][playerid], true);
	}
	if(autosalon_info_td_p[10][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		autosalon_info_td_p[10][playerid] = CreatePlayerTextDraw(playerid, 559.666564, 187.081527, "LD_BEAT:chit"); // Texture element
		PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[10][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, autosalon_info_td_p[10][playerid], 40.333301, 47.288799);
		PlayerTextDrawAlignment(playerid, autosalon_info_td_p[10][playerid], 2);
		PlayerTextDrawColor(playerid, autosalon_info_td_p[10][playerid], -16776961);
		PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[10][playerid], 0);
		PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[10][playerid], 0);
		PlayerTextDrawFont(playerid, autosalon_info_td_p[10][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, autosalon_info_td_p[10][playerid], true);
	}
	if(autosalon_info_td_p[11][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		autosalon_info_td_p[11][playerid] = CreatePlayerTextDraw(playerid, 560.333190, 223.585205, "LD_BEAT:chit"); // Texture element
		PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[11][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, autosalon_info_td_p[11][playerid], 40.333301, 47.288799);
		PlayerTextDrawAlignment(playerid, autosalon_info_td_p[11][playerid], 2);
		PlayerTextDrawColor(playerid, autosalon_info_td_p[11][playerid], 623191551);
		PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[11][playerid], 0);
		PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[11][playerid], 0);
		PlayerTextDrawFont(playerid, autosalon_info_td_p[11][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, autosalon_info_td_p[11][playerid], true);
	}
	if(autosalon_info_td_p[12][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		autosalon_info_td_p[12][playerid] = CreatePlayerTextDraw(playerid, 594.000061, 222.755630, "LD_BEAT:chit"); // Texture element
		PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[12][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, autosalon_info_td_p[12][playerid], 40.333301, 47.288799);
		PlayerTextDrawAlignment(playerid, autosalon_info_td_p[12][playerid], 2);
		PlayerTextDrawColor(playerid, autosalon_info_td_p[12][playerid], -1);
		PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[12][playerid], 0);
		PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[12][playerid], 0);
		PlayerTextDrawFont(playerid, autosalon_info_td_p[12][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, autosalon_info_td_p[12][playerid], true);
	}
	if(autosalon_info_td_p[13][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		autosalon_info_td_p[13][playerid] = CreatePlayerTextDraw(playerid, 561.000366, 261.333312, "LD_BEAT:chit"); // Texture element
		PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[13][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, autosalon_info_td_p[13][playerid], 40.333301, 47.288799);
		PlayerTextDrawAlignment(playerid, autosalon_info_td_p[13][playerid], 2);
		PlayerTextDrawColor(playerid, autosalon_info_td_p[13][playerid], -65281);
		PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[13][playerid], 0);
		PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[13][playerid], 0);
		PlayerTextDrawFont(playerid, autosalon_info_td_p[13][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, autosalon_info_td_p[13][playerid], true);
	}
	if(autosalon_info_td_p[14][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		autosalon_info_td_p[14][playerid] = CreatePlayerTextDraw(playerid, 594.667053, 260.918579, "LD_BEAT:chit"); // Texture element
		PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[14][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, autosalon_info_td_p[14][playerid], 40.333301, 47.288799);
		PlayerTextDrawAlignment(playerid, autosalon_info_td_p[14][playerid], 2);
		PlayerTextDrawColor(playerid, autosalon_info_td_p[14][playerid], -2147450625);
		PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[14][playerid], 0);
		PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[14][playerid], 0);
		PlayerTextDrawFont(playerid, autosalon_info_td_p[14][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, autosalon_info_td_p[14][playerid], true);
	}
	return true;
}

stock create_autosalon_elite()
{
	autosalon_elite_class[0] = TextDrawCreate(-0.333341, 47.288879, "brilliantother:left_back_autosalon_elite"); // Texture element
	TextDrawLetterSize(autosalon_elite_class[0], 0.000000, 0.000000);
	TextDrawTextSize(autosalon_elite_class[0], 146.000869, 350.103424);
	TextDrawAlignment(autosalon_elite_class[0], 1);
	TextDrawColor(autosalon_elite_class[0], -1);
	TextDrawSetShadow(autosalon_elite_class[0], 0);
	TextDrawSetOutline(autosalon_elite_class[0], 0);
	TextDrawFont(autosalon_elite_class[0], 4);

	autosalon_elite_class[1] = TextDrawCreate(8.666666, 299.911224, "brilliantother:left_button_autosalon_elite"); // Texture element
	TextDrawLetterSize(autosalon_elite_class[1], 0.000000, 0.000000);
	TextDrawTextSize(autosalon_elite_class[1], 32.666664, 34.844467);
	TextDrawAlignment(autosalon_elite_class[1], 2);
	TextDrawColor(autosalon_elite_class[1], -1);
	TextDrawUseBox(autosalon_elite_class[1], true);
	TextDrawBoxColor(autosalon_elite_class[1], 0);
	TextDrawSetShadow(autosalon_elite_class[1], 0);
	TextDrawSetOutline(autosalon_elite_class[1], 0);
	TextDrawFont(autosalon_elite_class[1], 4);
	TextDrawSetSelectable(autosalon_elite_class[1], true);

	autosalon_elite_class[2] = TextDrawCreate(75.666656, 299.496276, "brilliantother:right_button_autosalon_elite"); // Texture element
	TextDrawLetterSize(autosalon_elite_class[2], 0.000000, 0.000000);
	TextDrawTextSize(autosalon_elite_class[2], 32.666660, 34.844444);
	TextDrawAlignment(autosalon_elite_class[2], 2);
	TextDrawColor(autosalon_elite_class[2], -1);
	TextDrawSetShadow(autosalon_elite_class[2], 0);
	TextDrawSetOutline(autosalon_elite_class[2], 0);
	TextDrawFont(autosalon_elite_class[2], 4);
	TextDrawSetSelectable(autosalon_elite_class[2], true);

	autosalon_elite_class[3] = TextDrawCreate(43.999992, 299.911132, "brilliantother:camera_button_autosalon_elite"); // Texture element
	TextDrawLetterSize(autosalon_elite_class[3], 0.000000, 0.000000);
	TextDrawTextSize(autosalon_elite_class[3], 29.666667, 34.844440);
	TextDrawAlignment(autosalon_elite_class[3], 2);
	TextDrawColor(autosalon_elite_class[3], -1);
	TextDrawSetShadow(autosalon_elite_class[3], 0);
	TextDrawSetOutline(autosalon_elite_class[3], 0);
	TextDrawFont(autosalon_elite_class[3], 4);
	TextDrawSetSelectable(autosalon_elite_class[3], true);

	autosalon_elite_class[4] = TextDrawCreate(8.333333, 342.222198, "brilliantother:buy_button_autosalon_elite"); // Texture element
	TextDrawLetterSize(autosalon_elite_class[4], 0.000000, 0.000000);
	TextDrawTextSize(autosalon_elite_class[4], 100.333381, 31.525941);
	TextDrawAlignment(autosalon_elite_class[4], 2);
	TextDrawColor(autosalon_elite_class[4], -1);
	TextDrawSetShadow(autosalon_elite_class[4], 0);
	TextDrawSetOutline(autosalon_elite_class[4], 0);
	TextDrawFont(autosalon_elite_class[4], 4);
	TextDrawSetSelectable(autosalon_elite_class[4], true);

	autosalon_elite_class[5] = TextDrawCreate(533.999877, 46.874279, "brilliantother:right_back_autosalon_elite"); // Texture element
	TextDrawLetterSize(autosalon_elite_class[5], 0.000000, 0.000000);
	TextDrawTextSize(autosalon_elite_class[5], 137.333282, 357.155731);
	TextDrawAlignment(autosalon_elite_class[5], 2);
	TextDrawColor(autosalon_elite_class[5], -1);
	TextDrawSetShadow(autosalon_elite_class[5], 0);
	TextDrawSetOutline(autosalon_elite_class[5], 0);
	TextDrawFont(autosalon_elite_class[5], 4);

	autosalon_elite_class[6] = TextDrawCreate(565.666748, 123.614776, "brilliantother:up_button_autosalon_elite"); // Texture element
	TextDrawLetterSize(autosalon_elite_class[6], 0.000000, 0.000000);
	TextDrawTextSize(autosalon_elite_class[6], 62.666629, 27.792596);
	TextDrawAlignment(autosalon_elite_class[6], 2);
	TextDrawColor(autosalon_elite_class[6], -1);
	TextDrawSetShadow(autosalon_elite_class[6], 0);
	TextDrawSetOutline(autosalon_elite_class[6], 0);
	TextDrawFont(autosalon_elite_class[6], 4);
	TextDrawSetSelectable(autosalon_elite_class[6], true);

	autosalon_elite_class[7] = TextDrawCreate(567.333801, 316.088653, "brilliantother:down_button_autosalon_elite"); // Texture element
	TextDrawLetterSize(autosalon_elite_class[7], 0.000000, -9.099997);
	TextDrawTextSize(autosalon_elite_class[7], 62.666599, 27.791999);
	TextDrawAlignment(autosalon_elite_class[7], 2);
	TextDrawColor(autosalon_elite_class[7], -1);
	TextDrawUseBox(autosalon_elite_class[7], true);
	TextDrawBoxColor(autosalon_elite_class[7], 0);
	TextDrawSetShadow(autosalon_elite_class[7], 0);
	TextDrawSetOutline(autosalon_elite_class[7], 0);
	TextDrawFont(autosalon_elite_class[7], 4);
	TextDrawSetSelectable(autosalon_elite_class[7], true);


	autosalon_elite_class[8] = TextDrawCreate(621.000000, 50.607505, "brilliantother:trucker_close"); // Texture element
	TextDrawLetterSize(autosalon_elite_class[8], 0.000000, 0.000000);
	TextDrawTextSize(autosalon_elite_class[8], 15.333333, 19.081489);
	TextDrawAlignment(autosalon_elite_class[8], 2);
	TextDrawColor(autosalon_elite_class[8], -1);
	TextDrawSetShadow(autosalon_elite_class[8], 0);
	TextDrawSetOutline(autosalon_elite_class[8], 0);
	TextDrawFont(autosalon_elite_class[8], 4);
	TextDrawSetSelectable(autosalon_elite_class[8], true);


	return true;
}

stock create_autosalon_middle()
{
	autosalon_middle_class[0] = TextDrawCreate(-0.333341, 47.288879, "brilliantother:left_back_autosalon_medium"); // Texture element
	TextDrawLetterSize(autosalon_middle_class[0], 0.000000, 0.000000);
	TextDrawTextSize(autosalon_middle_class[0], 146.000869, 350.103424);
	TextDrawAlignment(autosalon_middle_class[0], 1);
	TextDrawColor(autosalon_middle_class[0], -79);
	TextDrawSetShadow(autosalon_middle_class[0], 0);
	TextDrawSetOutline(autosalon_middle_class[0], 0);
	TextDrawFont(autosalon_middle_class[0], 4);

	autosalon_middle_class[1] = TextDrawCreate(8.666666, 299.911224, "brilliantother:left_button_autosalon_medium"); // Texture element
	TextDrawLetterSize(autosalon_middle_class[1], 0.000000, 0.000000);
	TextDrawTextSize(autosalon_middle_class[1], 32.666664, 34.844467);
	TextDrawAlignment(autosalon_middle_class[1], 2);
	TextDrawColor(autosalon_middle_class[1], -1);
	TextDrawUseBox(autosalon_middle_class[1], true);
	TextDrawBoxColor(autosalon_middle_class[1], 0);
	TextDrawSetShadow(autosalon_middle_class[1], 0);
	TextDrawSetOutline(autosalon_middle_class[1], 0);
	TextDrawFont(autosalon_middle_class[1], 4);
	TextDrawSetSelectable(autosalon_middle_class[1], true);

	autosalon_middle_class[2] = TextDrawCreate(75.666656, 299.496276, "brilliantother:right_button_autosalon_medium"); // Texture element
	TextDrawLetterSize(autosalon_middle_class[2], 0.000000, 0.000000);
	TextDrawTextSize(autosalon_middle_class[2], 32.666660, 34.844444);
	TextDrawAlignment(autosalon_middle_class[2], 2);
	TextDrawColor(autosalon_middle_class[2], -1);
	TextDrawSetShadow(autosalon_middle_class[2], 0);
	TextDrawSetOutline(autosalon_middle_class[2], 0);
	TextDrawFont(autosalon_middle_class[2], 4);
	TextDrawSetSelectable(autosalon_middle_class[2], true);

	autosalon_middle_class[3] = TextDrawCreate(43.999992, 299.911132, "brilliantother:camera_button_autosalon_medium"); // Texture element
	TextDrawLetterSize(autosalon_middle_class[3], 0.000000, 0.000000);
	TextDrawTextSize(autosalon_middle_class[3], 29.666667, 34.844440);
	TextDrawAlignment(autosalon_middle_class[3], 2);
	TextDrawColor(autosalon_middle_class[3], -1);
	TextDrawSetShadow(autosalon_middle_class[3], 0);
	TextDrawSetOutline(autosalon_middle_class[3], 0);
	TextDrawFont(autosalon_middle_class[3], 4);
	TextDrawSetSelectable(autosalon_middle_class[3], true);

	autosalon_middle_class[4] = TextDrawCreate(8.333333, 342.222198, "brilliantother:buy_button_autosalon_medium"); // Texture element
	TextDrawLetterSize(autosalon_middle_class[4], 0.000000, 0.000000);
	TextDrawTextSize(autosalon_middle_class[4], 100.333381, 31.525941);
	TextDrawAlignment(autosalon_middle_class[4], 2);
	TextDrawColor(autosalon_middle_class[4], -1);
	TextDrawSetShadow(autosalon_middle_class[4], 0);
	TextDrawSetOutline(autosalon_middle_class[4], 0);
	TextDrawFont(autosalon_middle_class[4], 4);
	TextDrawSetSelectable(autosalon_middle_class[4], true);

	autosalon_middle_class[5] = TextDrawCreate(533.999877, 46.874279, "brilliantother:right_back_autosalon_medium"); // Texture element
	TextDrawLetterSize(autosalon_middle_class[5], 0.000000, 0.000000);
	TextDrawTextSize(autosalon_middle_class[5], 137.333282, 357.155731);
	TextDrawAlignment(autosalon_middle_class[5], 2);
	TextDrawColor(autosalon_middle_class[5], -92);
	TextDrawSetShadow(autosalon_middle_class[5], 0);
	TextDrawSetOutline(autosalon_middle_class[5], 0);
	TextDrawFont(autosalon_middle_class[5], 4);

	autosalon_middle_class[6] = TextDrawCreate(565.999755, 118.222183, "brilliantother:up_button_autosalon_medium"); // Texture element
	TextDrawLetterSize(autosalon_middle_class[6], 0.000000, 0.000000);
	TextDrawTextSize(autosalon_middle_class[6], 62.666629, 27.792596);
	TextDrawAlignment(autosalon_middle_class[6], 2);
	TextDrawColor(autosalon_middle_class[6], -1);
	TextDrawSetShadow(autosalon_middle_class[6], 0);
	TextDrawSetOutline(autosalon_middle_class[6], 0);
	TextDrawFont(autosalon_middle_class[6], 4);
	TextDrawSetSelectable(autosalon_middle_class[6], true);

	autosalon_middle_class[7] = TextDrawCreate(567.333801, 316.088653, "brilliantother:down_button_autosalon_medium"); // Texture element
	TextDrawLetterSize(autosalon_middle_class[7], 0.000000, -9.099995);
	TextDrawTextSize(autosalon_middle_class[7], 62.666599, 27.791999);
	TextDrawAlignment(autosalon_middle_class[7], 2);
	TextDrawColor(autosalon_middle_class[7], -1);
	TextDrawUseBox(autosalon_middle_class[7], true);
	TextDrawBoxColor(autosalon_middle_class[7], 0);
	TextDrawSetShadow(autosalon_middle_class[7], 0);
	TextDrawSetOutline(autosalon_middle_class[7], 0);
	TextDrawFont(autosalon_middle_class[7], 4);
	TextDrawSetSelectable(autosalon_middle_class[7], true);

	autosalon_middle_class[8] = TextDrawCreate(621.000000, 50.607505, "brilliantother:trucker_close"); // Texture element
	TextDrawLetterSize(autosalon_middle_class[8], 0.000000, 0.000000);
	TextDrawTextSize(autosalon_middle_class[8], 15.333333, 19.081489);
	TextDrawAlignment(autosalon_middle_class[8], 2);
	TextDrawColor(autosalon_middle_class[8], -1);
	TextDrawSetShadow(autosalon_middle_class[8], 0);
	TextDrawSetOutline(autosalon_middle_class[8], 0);
	TextDrawFont(autosalon_middle_class[8], 4);
	TextDrawSetSelectable(autosalon_middle_class[8], true);


	return true;
}

stock create_autosalon_low()
{
	autosalon_low_class[0] = TextDrawCreate(-0.333341, 47.288879, "brilliantother:left_back_autosalon_low"); // Texture element
	TextDrawLetterSize(autosalon_low_class[0], 0.000000, 0.000000);
	TextDrawTextSize(autosalon_low_class[0], 146.000869, 350.103424);
	TextDrawAlignment(autosalon_low_class[0], 1);
	TextDrawColor(autosalon_low_class[0], -116);
	TextDrawSetShadow(autosalon_low_class[0], 0);
	TextDrawSetOutline(autosalon_low_class[0], 0);
	TextDrawFont(autosalon_low_class[0], 4);

	autosalon_low_class[1] = TextDrawCreate(8.666666, 299.911224, "brilliantother:left_button_autosalon_low"); // Texture element
	TextDrawLetterSize(autosalon_low_class[1], 0.000000, 0.000000);
	TextDrawTextSize(autosalon_low_class[1], 32.666664, 34.844467);
	TextDrawAlignment(autosalon_low_class[1], 2);
	TextDrawColor(autosalon_low_class[1], -1);
	TextDrawUseBox(autosalon_low_class[1], true);
	TextDrawBoxColor(autosalon_low_class[1], 0);
	TextDrawSetShadow(autosalon_low_class[1], 0);
	TextDrawSetOutline(autosalon_low_class[1], 0);
	TextDrawFont(autosalon_low_class[1], 4);
	TextDrawSetSelectable(autosalon_low_class[1], true);

	autosalon_low_class[2] = TextDrawCreate(75.666656, 299.496276, "brilliantother:right_button_autosalon_low"); // Texture element
	TextDrawLetterSize(autosalon_low_class[2], 0.000000, 0.000000);
	TextDrawTextSize(autosalon_low_class[2], 32.666660, 34.844444);
	TextDrawAlignment(autosalon_low_class[2], 2);
	TextDrawColor(autosalon_low_class[2], -1);
	TextDrawSetShadow(autosalon_low_class[2], 0);
	TextDrawSetOutline(autosalon_low_class[2], 0);
	TextDrawFont(autosalon_low_class[2], 4);
	TextDrawSetSelectable(autosalon_low_class[2], true);

	autosalon_low_class[3] = TextDrawCreate(43.999992, 299.911132, "brilliantother:camera_button_autosalon_low"); // Texture element
	TextDrawLetterSize(autosalon_low_class[3], 0.000000, 0.000000);
	TextDrawTextSize(autosalon_low_class[3], 29.666667, 34.844440);
	TextDrawAlignment(autosalon_low_class[3], 2);
	TextDrawColor(autosalon_low_class[3], -1);
	TextDrawSetShadow(autosalon_low_class[3], 0);
	TextDrawSetOutline(autosalon_low_class[3], 0);
	TextDrawFont(autosalon_low_class[3], 4);
	TextDrawSetSelectable(autosalon_low_class[3], true);

	autosalon_low_class[4] = TextDrawCreate(8.333333, 342.222198, "brilliantother:buy_button_autosalon_low"); // Texture element
	TextDrawLetterSize(autosalon_low_class[4], 0.000000, 0.000000);
	TextDrawTextSize(autosalon_low_class[4], 100.333381, 31.525941);
	TextDrawAlignment(autosalon_low_class[4], 2);
	TextDrawColor(autosalon_low_class[4], -1);
	TextDrawSetShadow(autosalon_low_class[4], 0);
	TextDrawSetOutline(autosalon_low_class[4], 0);
	TextDrawFont(autosalon_low_class[4], 4);
	TextDrawSetSelectable(autosalon_low_class[4], true);

	autosalon_low_class[5] = TextDrawCreate(533.999877, 46.874279, "brilliantother:right_back_autosalon_low"); // Texture element
	TextDrawLetterSize(autosalon_low_class[5], 0.000000, 0.000000);
	TextDrawTextSize(autosalon_low_class[5], 137.333282, 357.155731);
	TextDrawAlignment(autosalon_low_class[5], 2);
	TextDrawColor(autosalon_low_class[5], -92);
	TextDrawSetShadow(autosalon_low_class[5], 0);
	TextDrawSetOutline(autosalon_low_class[5], 0);
	TextDrawFont(autosalon_low_class[5], 4);

	autosalon_low_class[6] = TextDrawCreate(565.999755, 118.222183, "brilliantother:up_button_autosalon_low"); // Texture element
	TextDrawLetterSize(autosalon_low_class[6], 0.000000, 0.000000);
	TextDrawTextSize(autosalon_low_class[6], 62.666629, 27.792596);
	TextDrawAlignment(autosalon_low_class[6], 2);
	TextDrawColor(autosalon_low_class[6], -1);
	TextDrawSetShadow(autosalon_low_class[6], 0);
	TextDrawSetOutline(autosalon_low_class[6], 0);
	TextDrawFont(autosalon_low_class[6], 4);
	TextDrawSetSelectable(autosalon_low_class[6], true);

	autosalon_low_class[7] = TextDrawCreate(567.333801, 316.088653, "brilliantother:down_button_autosalon_low"); // Texture element
	TextDrawLetterSize(autosalon_low_class[7], 0.000000, -9.099994);
	TextDrawTextSize(autosalon_low_class[7], 62.666599, 27.791999);
	TextDrawAlignment(autosalon_low_class[7], 2);
	TextDrawColor(autosalon_low_class[7], -1);
	TextDrawUseBox(autosalon_low_class[7], true);
	TextDrawBoxColor(autosalon_low_class[7], 0);
	TextDrawSetShadow(autosalon_low_class[7], 0);
	TextDrawSetOutline(autosalon_low_class[7], 0);
	TextDrawFont(autosalon_low_class[7], 4);
	TextDrawSetSelectable(autosalon_low_class[7], true);


	autosalon_low_class[8] = TextDrawCreate(621.000000, 50.607505, "brilliantother:trucker_close"); // Texture element
	TextDrawLetterSize(autosalon_low_class[8], 0.000000, 0.000000);
	TextDrawTextSize(autosalon_low_class[8], 15.333333, 19.081489);
	TextDrawAlignment(autosalon_low_class[8], 2);
	TextDrawColor(autosalon_low_class[8], -1);
	TextDrawSetShadow(autosalon_low_class[8], 0);
	TextDrawSetOutline(autosalon_low_class[8], 0);
	TextDrawFont(autosalon_low_class[8], 4);
	TextDrawSetSelectable(autosalon_low_class[8], true);

	return true;
}
 
stock create_phone_yandex_taxi(playerid)
{


	if(yandex_taxi_td[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		yandex_taxi_td[0][playerid] = CreatePlayerTextDraw(playerid, 519.666687, 266.311218, "LD_SPAC:white"); // Texture element
		PlayerTextDrawLetterSize(playerid, yandex_taxi_td[0][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, yandex_taxi_td[0][playerid], 96.666687, 24.888885);
		PlayerTextDrawAlignment(playerid, yandex_taxi_td[0][playerid], 2);
		PlayerTextDrawColor(playerid, yandex_taxi_td[0][playerid], -1);
		PlayerTextDrawSetShadow(playerid, yandex_taxi_td[0][playerid], 0);
		PlayerTextDrawSetOutline(playerid, yandex_taxi_td[0][playerid], 0);
		PlayerTextDrawFont(playerid, yandex_taxi_td[0][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, yandex_taxi_td[0][playerid], true);
	}
	if(yandex_taxi_td[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{	
		yandex_taxi_td[1][playerid] = CreatePlayerTextDraw(playerid, 521.666748, 293.274230, "LD_SPAC:white"); // Texture element
		PlayerTextDrawLetterSize(playerid, yandex_taxi_td[1][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, yandex_taxi_td[1][playerid], 96.666687, 24.888885);
		PlayerTextDrawAlignment(playerid, yandex_taxi_td[1][playerid], 2);
		PlayerTextDrawColor(playerid, yandex_taxi_td[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, yandex_taxi_td[1][playerid], 0);
		PlayerTextDrawSetOutline(playerid, yandex_taxi_td[1][playerid], 0);
		PlayerTextDrawFont(playerid, yandex_taxi_td[1][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, yandex_taxi_td[1][playerid], true);
	}
	if(yandex_taxi_td[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		yandex_taxi_td[2][playerid] = CreatePlayerTextDraw(playerid, 519.666442, 325.629821, "LD_SPAC:white"); // Texture element
		PlayerTextDrawLetterSize(playerid, yandex_taxi_td[2][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, yandex_taxi_td[2][playerid], 91.666671, 21.985179);
		PlayerTextDrawAlignment(playerid, yandex_taxi_td[2][playerid], 2);
		PlayerTextDrawColor(playerid, yandex_taxi_td[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, yandex_taxi_td[2][playerid], 0);
		PlayerTextDrawSetOutline(playerid, yandex_taxi_td[2][playerid], 0);
		PlayerTextDrawFont(playerid, yandex_taxi_td[2][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, yandex_taxi_td[2][playerid], true);
	}
	if(yandex_taxi_td[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		yandex_taxi_td[3][playerid] = CreatePlayerTextDraw(playerid, 519.666442, 352.592712, "LD_SPAC:white"); // Texture element
		PlayerTextDrawLetterSize(playerid, yandex_taxi_td[3][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, yandex_taxi_td[3][playerid], 96.666687, 24.888885);
		PlayerTextDrawAlignment(playerid, yandex_taxi_td[3][playerid], 2);
		PlayerTextDrawColor(playerid, yandex_taxi_td[3][playerid], -1);
		PlayerTextDrawSetShadow(playerid, yandex_taxi_td[3][playerid], 0);
		PlayerTextDrawSetOutline(playerid, yandex_taxi_td[3][playerid], 0);
		PlayerTextDrawFont(playerid, yandex_taxi_td[3][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, yandex_taxi_td[3][playerid], true);
	}
	if(yandex_taxi_td[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		yandex_taxi_td[4][playerid] = CreatePlayerTextDraw(playerid, 520.666564, 379.555786, "LD_SPAC:white"); // Texture element
		PlayerTextDrawLetterSize(playerid, yandex_taxi_td[4][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, yandex_taxi_td[4][playerid], 96.666687, 24.888885);
		PlayerTextDrawAlignment(playerid, yandex_taxi_td[4][playerid], 2);
		PlayerTextDrawColor(playerid, yandex_taxi_td[4][playerid], -1);
		PlayerTextDrawSetShadow(playerid, yandex_taxi_td[4][playerid], 0);
		PlayerTextDrawSetOutline(playerid, yandex_taxi_td[4][playerid], 0);
		PlayerTextDrawFont(playerid, yandex_taxi_td[4][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, yandex_taxi_td[4][playerid], true);
	}


	return true;
}

stock create_phone_uber_taxi(playerid)
{

	if(uber_taxi_td[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		uber_taxi_td[0][playerid] = CreatePlayerTextDraw(playerid, 518.333312, 245.570373, "LD_SPAC:white"); // Texture element
		PlayerTextDrawLetterSize(playerid, uber_taxi_td[0][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, uber_taxi_td[0][playerid], 96.666687, 24.888885);
		PlayerTextDrawAlignment(playerid, uber_taxi_td[0][playerid], 2);
		PlayerTextDrawColor(playerid, uber_taxi_td[0][playerid], -1);
		PlayerTextDrawSetShadow(playerid, uber_taxi_td[0][playerid], 0);
		PlayerTextDrawSetOutline(playerid, uber_taxi_td[0][playerid], 0);
		PlayerTextDrawFont(playerid, uber_taxi_td[0][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, uber_taxi_td[0][playerid], true);
	}
	if(uber_taxi_td[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		uber_taxi_td[1][playerid] = CreatePlayerTextDraw(playerid, 518.666625, 271.703765, "LD_SPAC:white"); // Texture element
		PlayerTextDrawLetterSize(playerid, uber_taxi_td[1][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, uber_taxi_td[1][playerid], 96.666687, 24.888885);
		PlayerTextDrawAlignment(playerid, uber_taxi_td[1][playerid], 2);
		PlayerTextDrawColor(playerid, uber_taxi_td[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, uber_taxi_td[1][playerid], 0);
		PlayerTextDrawSetOutline(playerid, uber_taxi_td[1][playerid], 0);
		PlayerTextDrawFont(playerid, uber_taxi_td[1][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, uber_taxi_td[1][playerid], true);
	}
	if(uber_taxi_td[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		uber_taxi_td[2][playerid] = CreatePlayerTextDraw(playerid, 519.000000, 298.251953, "LD_SPAC:white"); // Texture element
		PlayerTextDrawLetterSize(playerid, uber_taxi_td[2][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, uber_taxi_td[2][playerid], 96.666687, 24.888885);
		PlayerTextDrawAlignment(playerid, uber_taxi_td[2][playerid], 2);
		PlayerTextDrawColor(playerid, uber_taxi_td[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, uber_taxi_td[2][playerid], 0);
		PlayerTextDrawSetOutline(playerid, uber_taxi_td[2][playerid], 0);
		PlayerTextDrawFont(playerid, uber_taxi_td[2][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, uber_taxi_td[2][playerid], true);
	}
	if(uber_taxi_td[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		uber_taxi_td[3][playerid] = CreatePlayerTextDraw(playerid, 519.999938, 353.007598, "LD_SPAC:white"); // Texture element
		PlayerTextDrawLetterSize(playerid, uber_taxi_td[3][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, uber_taxi_td[3][playerid], 96.666687, 24.888885);
		PlayerTextDrawAlignment(playerid, uber_taxi_td[3][playerid], 2);
		PlayerTextDrawColor(playerid, uber_taxi_td[3][playerid], -1);
		PlayerTextDrawSetShadow(playerid, uber_taxi_td[3][playerid], 0);
		PlayerTextDrawSetOutline(playerid, uber_taxi_td[3][playerid], 0);
		PlayerTextDrawFont(playerid, uber_taxi_td[3][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, uber_taxi_td[3][playerid], true);
	}
	if(uber_taxi_td[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		uber_taxi_td[4][playerid] = CreatePlayerTextDraw(playerid, 520.666564, 379.555786, "LD_SPAC:white"); // Texture element
		PlayerTextDrawLetterSize(playerid, uber_taxi_td[4][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, uber_taxi_td[4][playerid], 96.666687, 24.888885);
		PlayerTextDrawAlignment(playerid, uber_taxi_td[4][playerid], 2);
		PlayerTextDrawColor(playerid, uber_taxi_td[4][playerid], -1);
		PlayerTextDrawSetShadow(playerid, uber_taxi_td[4][playerid], 0);
		PlayerTextDrawSetOutline(playerid, uber_taxi_td[4][playerid], 0);
		PlayerTextDrawFont(playerid, uber_taxi_td[4][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, uber_taxi_td[4][playerid], true);
	}


	return true;
}

stock create_phone_sity_taxi(playerid)
{


	if(siti_taxi_select[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		siti_taxi_select[0][playerid] = CreatePlayerTextDraw(playerid, 520.333374, 233.126052, "LD_SPAC:white"); // Texture element
		PlayerTextDrawLetterSize(playerid, siti_taxi_select[0][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, siti_taxi_select[0][playerid], 95.000015, 36.088878);
		PlayerTextDrawAlignment(playerid, siti_taxi_select[0][playerid], 2);
		PlayerTextDrawColor(playerid, siti_taxi_select[0][playerid], -1);
		PlayerTextDrawSetShadow(playerid, siti_taxi_select[0][playerid], 0);
		PlayerTextDrawSetOutline(playerid, siti_taxi_select[0][playerid], 0);
		PlayerTextDrawFont(playerid, siti_taxi_select[0][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, siti_taxi_select[0][playerid], true);
	}
	if(siti_taxi_select[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		siti_taxi_select[1][playerid] = CreatePlayerTextDraw(playerid, 519.666748, 273.363037, "LD_SPAC:white"); // Texture element
		PlayerTextDrawLetterSize(playerid, siti_taxi_select[1][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, siti_taxi_select[1][playerid], 96.333343, 35.674068);
		PlayerTextDrawAlignment(playerid, siti_taxi_select[1][playerid], 2);
		PlayerTextDrawColor(playerid, siti_taxi_select[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, siti_taxi_select[1][playerid], 0);
		PlayerTextDrawSetOutline(playerid, siti_taxi_select[1][playerid], 0);
		PlayerTextDrawFont(playerid, siti_taxi_select[1][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, siti_taxi_select[1][playerid], true);
	}
	if(siti_taxi_select[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		siti_taxi_select[2][playerid] = CreatePlayerTextDraw(playerid, 519.333312, 313.185302, "LD_SPAC:white"); // Texture element
		PlayerTextDrawLetterSize(playerid, siti_taxi_select[2][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, siti_taxi_select[2][playerid], 97.333320, 35.674072);
		PlayerTextDrawAlignment(playerid, siti_taxi_select[2][playerid], 2);
		PlayerTextDrawColor(playerid, siti_taxi_select[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, siti_taxi_select[2][playerid], 0);
		PlayerTextDrawSetOutline(playerid, siti_taxi_select[2][playerid], 0);
		PlayerTextDrawFont(playerid, siti_taxi_select[2][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, siti_taxi_select[2][playerid], true);
	}
	if(siti_taxi_select[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		siti_taxi_select[3][playerid] = CreatePlayerTextDraw(playerid, 519.666442, 353.422302, "LD_SPAC:white"); // Texture element
		PlayerTextDrawLetterSize(playerid, siti_taxi_select[3][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, siti_taxi_select[3][playerid], 96.666687, 24.888885);
		PlayerTextDrawAlignment(playerid, siti_taxi_select[3][playerid], 2);
		PlayerTextDrawColor(playerid, siti_taxi_select[3][playerid], -1);
		PlayerTextDrawSetShadow(playerid, siti_taxi_select[3][playerid], 0);
		PlayerTextDrawSetOutline(playerid, siti_taxi_select[3][playerid], 0);
		PlayerTextDrawFont(playerid, siti_taxi_select[3][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, siti_taxi_select[3][playerid], true);
	}
	if(siti_taxi_select[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		siti_taxi_select[4][playerid] = CreatePlayerTextDraw(playerid, 519.666625, 382.044708, "LD_SPAC:white"); // Texture element
		PlayerTextDrawLetterSize(playerid, siti_taxi_select[4][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, siti_taxi_select[4][playerid], 96.666687, 24.888885);
		PlayerTextDrawAlignment(playerid, siti_taxi_select[4][playerid], 2);
		PlayerTextDrawColor(playerid, siti_taxi_select[4][playerid], -1);
		PlayerTextDrawSetShadow(playerid, siti_taxi_select[4][playerid], 0);
		PlayerTextDrawSetOutline(playerid, siti_taxi_select[4][playerid], 0);
		PlayerTextDrawFont(playerid, siti_taxi_select[4][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, siti_taxi_select[4][playerid], true);
	}


	return true;
}

stock create_trucker_job_panel()
{

	trucker_select_job[0] = TextDrawCreate(134.000015, 118.637054, "brilliantother:trucker_base_back"); // Texture element
	TextDrawLetterSize(trucker_select_job[0], 0.000000, 0.000000);
	TextDrawTextSize(trucker_select_job[0], 361.000183, 238.518478);
	TextDrawAlignment(trucker_select_job[0], 2);
	TextDrawColor(trucker_select_job[0], -1);
	TextDrawSetShadow(trucker_select_job[0], 0);
	TextDrawSetOutline(trucker_select_job[0], 0);
	TextDrawFont(trucker_select_job[0], 4);


	trucker_select_job[1] = TextDrawCreate(262.999969, 195.377777, "brilliantother:trucker_zavod_select"); // Texture element
	TextDrawLetterSize(trucker_select_job[1], 0.000000, 0.000000);
	TextDrawTextSize(trucker_select_job[1], 102.999984, 61.392608);
	TextDrawAlignment(trucker_select_job[1], 2);
	TextDrawColor(trucker_select_job[1], -1);
	TextDrawSetShadow(trucker_select_job[1], 0);
	TextDrawSetOutline(trucker_select_job[1], 0);
	TextDrawFont(trucker_select_job[1], 4);
	TextDrawSetSelectable(trucker_select_job[1], true);

	trucker_select_job[2] = TextDrawCreate(372.999969, 195.792602, "brilliantother:trucker_shop_select"); // Texture element
	TextDrawLetterSize(trucker_select_job[2], 0.000000, 0.000000);
	TextDrawTextSize(trucker_select_job[2], 102.999984, 61.392608);
	TextDrawAlignment(trucker_select_job[2], 2);
	TextDrawColor(trucker_select_job[2], -1);
	TextDrawSetShadow(trucker_select_job[2], 0);
	TextDrawSetOutline(trucker_select_job[2], 0);
	TextDrawFont(trucker_select_job[2], 4);
	TextDrawSetSelectable(trucker_select_job[2], true);

	trucker_select_job[3] = TextDrawCreate(153.333251, 265.481567, "brilliantother:trucker_fill_1_select"); // Texture element
	TextDrawLetterSize(trucker_select_job[3], 0.000000, 0.000000);
	TextDrawTextSize(trucker_select_job[3], 102.999984, 61.392608);
	TextDrawAlignment(trucker_select_job[3], 2);
	TextDrawColor(trucker_select_job[3], -1);
	TextDrawSetShadow(trucker_select_job[3], 0);
	TextDrawSetOutline(trucker_select_job[3], 0);
	TextDrawFont(trucker_select_job[3], 4);
	TextDrawSetSelectable(trucker_select_job[3], true);

	trucker_select_job[4] = TextDrawCreate(263.999908, 264.237091, "brilliantother:trucker_fill_2_select"); // Texture element
	TextDrawLetterSize(trucker_select_job[4], 0.000000, 0.000000);
	TextDrawTextSize(trucker_select_job[4], 102.999984, 61.392608);
	TextDrawAlignment(trucker_select_job[4], 2);
	TextDrawColor(trucker_select_job[4], -1);
	TextDrawUseBox(trucker_select_job[4], true);
	TextDrawBoxColor(trucker_select_job[4], 0);
	TextDrawSetShadow(trucker_select_job[4], 0);
	TextDrawSetOutline(trucker_select_job[4], 0);
	TextDrawFont(trucker_select_job[4], 4);
	TextDrawSetSelectable(trucker_select_job[4], true);

	trucker_select_job[5] = TextDrawCreate(374.666595, 265.896301, "brilliantother:trucker_samwill_select"); // Texture element
	TextDrawLetterSize(trucker_select_job[5], 0.000000, 0.000000);
	TextDrawTextSize(trucker_select_job[5], 102.999984, 61.392608);
	TextDrawAlignment(trucker_select_job[5], 2);
	TextDrawColor(trucker_select_job[5], -1);
	TextDrawSetShadow(trucker_select_job[5], 0);
	TextDrawSetOutline(trucker_select_job[5], 0);
	TextDrawFont(trucker_select_job[5], 4);
	TextDrawSetSelectable(trucker_select_job[5], true);

	trucker_select_job[6] = TextDrawCreate(296.333312, 132.325927, "brilliantother:trucker_info"); // Texture element
	TextDrawLetterSize(trucker_select_job[6], 0.000000, 0.000000);
	TextDrawTextSize(trucker_select_job[6], 157.333343, 48.533325);
	TextDrawAlignment(trucker_select_job[6], 2);
	TextDrawColor(trucker_select_job[6], -1);
	TextDrawSetShadow(trucker_select_job[6], 0);
	TextDrawSetOutline(trucker_select_job[6], 0);
	TextDrawFont(trucker_select_job[6], 4);

	trucker_select_job[7] = TextDrawCreate(469.000030, 125.274070, "brilliantother:trucker_close"); // Texture element
	TextDrawLetterSize(trucker_select_job[7], 0.000000, 0.000000);
	TextDrawTextSize(trucker_select_job[7], 16.000000, 20.325920);
	TextDrawAlignment(trucker_select_job[7], 2);
	TextDrawColor(trucker_select_job[7], -1);
	TextDrawSetShadow(trucker_select_job[7], 0);
	TextDrawSetOutline(trucker_select_job[7], 0);
	TextDrawFont(trucker_select_job[7], 4);
	TextDrawSetSelectable(trucker_select_job[7], true);

	trucker_select_job[8] = TextDrawCreate(153.333297, 196.207397, "brilliantother:trucker_mine_select"); // Texture element 
	TextDrawLetterSize(trucker_select_job[8], 0.000000, 0.000000);
	TextDrawTextSize(trucker_select_job[8], 102.999984, 61.392608);
	TextDrawAlignment(trucker_select_job[8], 2);
	TextDrawColor(trucker_select_job[8], -1);
	TextDrawSetShadow(trucker_select_job[8], 0);
	TextDrawSetOutline(trucker_select_job[8], 0);
	TextDrawFont(trucker_select_job[8], 4);
	TextDrawSetSelectable(trucker_select_job[8], true);

	return true;

}

stock create_phone_general()
{

	phone_general = TextDrawCreate(525.333435, 177.955612, "00:21"); // Text element
	TextDrawLetterSize(phone_general, 0.151333, 0.882370);
	TextDrawAlignment(phone_general, 1);
	TextDrawColor(phone_general, -1);
	TextDrawSetShadow(phone_general, 0);
	TextDrawSetOutline(phone_general, 0);
	TextDrawBackgroundColor(phone_general, 51);
	TextDrawFont(phone_general, 2);
	TextDrawSetProportional(phone_general, 1);


	return true;
}


stock create_alt_button_info()
{

	alt_menu = TextDrawCreate(263.000183, 389.511230, "brilliantother:notify_player_use_alt"); // Texture element
	TextDrawLetterSize(alt_menu, 0.000000, 0.000000);
	TextDrawTextSize(alt_menu, 112.666671, 35.259262);
	TextDrawAlignment(alt_menu, 1);
	TextDrawColor(alt_menu, -1);
	TextDrawSetShadow(alt_menu, 0);
	TextDrawSetOutline(alt_menu, 0);
	TextDrawFont(alt_menu, 4);


	return true;
}

stock create_bus_timer_back()
{
	bus_timer = TextDrawCreate(515.999938, 183.348098, "brilliantother:backround_job_bus_timer"); // Texture element
	TextDrawLetterSize(bus_timer, 0.000000, 0.000000);
	TextDrawTextSize(bus_timer, 117.000022, 65.540710);
	TextDrawAlignment(bus_timer, 2);
	TextDrawColor(bus_timer, -1);
	TextDrawSetShadow(bus_timer, 0);
	TextDrawSetOutline(bus_timer, 0);
	TextDrawFont(bus_timer, 4);

	return true;
}

stock create_button_charge_tesla()
{
	charge_tesla_button[0] = TextDrawCreate(343.000000, 155.555541, "LD_SPAC:white"); // Texture element
	TextDrawLetterSize(charge_tesla_button[0], 0.000000, 0.000000);
	TextDrawTextSize(charge_tesla_button[0], 105.000000, 94.992599);
	TextDrawAlignment(charge_tesla_button[0], 2);
	TextDrawColor(charge_tesla_button[0], -1);
	TextDrawSetShadow(charge_tesla_button[0], 0);
	TextDrawSetOutline(charge_tesla_button[0], 0);
	TextDrawFont(charge_tesla_button[0], 4);
	TextDrawSetSelectable(charge_tesla_button[0], true);

	charge_tesla_button[1] = TextDrawCreate(455.666656, 117.807411, "brilliantother:info_school_close"); // Texture element
	TextDrawLetterSize(charge_tesla_button[1], 0.000000, 0.000000);
	TextDrawTextSize(charge_tesla_button[1], 18.333345, 21.155542);
	TextDrawAlignment(charge_tesla_button[1], 2);
	TextDrawColor(charge_tesla_button[1], -1);
	TextDrawSetShadow(charge_tesla_button[1], 0);
	TextDrawSetOutline(charge_tesla_button[1], 0);
	TextDrawFont(charge_tesla_button[1], 4);
	TextDrawSetSelectable(charge_tesla_button[1], true);


	return true;

}


stock create_alt_info()
{
	alt_menu = TextDrawCreate(263.000183, 389.511230, "brilliantother:notify_player_use_alt"); // Texture element
	TextDrawLetterSize(alt_menu, 0.000000, 0.000000);
	TextDrawTextSize(alt_menu, 112.666671, 35.259262);
	TextDrawAlignment(alt_menu, 1);
	TextDrawColor(alt_menu, -1);
	TextDrawSetShadow(alt_menu, 0);
	TextDrawSetOutline(alt_menu, 0);
	TextDrawFont(alt_menu, 4);


	return true;
}

stock create_bus_timer_p(playerid)
{
	bus_timer_p[playerid] = CreatePlayerTextDraw(playerid, 555.000000, 215.288894, "10"); // Text element
	PlayerTextDrawLetterSize(playerid, bus_timer_p[playerid] , 0.607666, 2.541628);
	PlayerTextDrawAlignment(playerid, bus_timer_p[playerid] , 2);
	PlayerTextDrawColor(playerid, bus_timer_p[playerid] , 1304556543);
	PlayerTextDrawUseBox(playerid, bus_timer_p[playerid] , true);
	PlayerTextDrawBoxColor(playerid, bus_timer_p[playerid] , 0);
	PlayerTextDrawSetShadow(playerid, bus_timer_p[playerid] , 2);
	PlayerTextDrawSetOutline(playerid, bus_timer_p[playerid] , 0);
	PlayerTextDrawBackgroundColor(playerid, bus_timer_p[playerid] , 20);
	PlayerTextDrawFont(playerid, bus_timer_p[playerid] , 1);
	PlayerTextDrawSetProportional(playerid, bus_timer_p[playerid] , 1);

	return true;
}

stock create_casino_p()
{
	casino_panel[0] = TextDrawCreate(397.333343, 97.481521, "brilliantother:casino_panel_background"); // Texture element
	TextDrawLetterSize(casino_panel[0], 0.000000, 0.000000);
	TextDrawTextSize(casino_panel[0], 192.333221, 296.177856);
	TextDrawAlignment(casino_panel[0], 2);
	TextDrawColor(casino_panel[0], -1);
	TextDrawSetShadow(casino_panel[0], 0);
	TextDrawSetOutline(casino_panel[0], 0);
	TextDrawFont(casino_panel[0], 4);

	casino_panel[1] = TextDrawCreate(430.333343, 306.963043, "brilliantother:casino_panel_button_bet"); // Texture element
	TextDrawLetterSize(casino_panel[1], 0.000000, 0.000000);
	TextDrawTextSize(casino_panel[1], 64.000030, 63.881450);
	TextDrawAlignment(casino_panel[1], 2);
	TextDrawColor(casino_panel[1], -1);
	TextDrawSetShadow(casino_panel[1], 0);
	TextDrawSetOutline(casino_panel[1], 0);
	TextDrawFont(casino_panel[1], 4);
	TextDrawSetSelectable(casino_panel[1], true);

	casino_panel[2] = TextDrawCreate(505.666717, 306.963043, "brilliantother:casino_panel_button_close"); // Texture element
	TextDrawLetterSize(casino_panel[2], 0.000000, 0.000000);
	TextDrawTextSize(casino_panel[2], 64.000030, 63.881450);
	TextDrawAlignment(casino_panel[2], 2);
	TextDrawColor(casino_panel[2], -1);
	TextDrawSetShadow(casino_panel[2], 0);
	TextDrawSetOutline(casino_panel[2], 0);
	TextDrawFont(casino_panel[2], 4);
	TextDrawSetSelectable(casino_panel[2], true);


	casino_panel[3] = TextDrawCreate(430.333343, 306.963043, "brilliantother:casino_panel_button_start"); // Texture element
	TextDrawLetterSize(casino_panel[3], 0.000000, 0.000000);
	TextDrawTextSize(casino_panel[3], 64.000030, 63.881450);
	TextDrawAlignment(casino_panel[3], 2);
	TextDrawColor(casino_panel[3], -1);
	TextDrawSetShadow(casino_panel[3], 0);
	TextDrawSetOutline(casino_panel[3], 0);
	TextDrawFont(casino_panel[3], 4);
	TextDrawSetSelectable(casino_panel[3], true);

	return true;
}

stock create_miner_job_all()
{

	mine_job_1[0] = TextDrawCreate(-1.000000, -1.000000, "minejob:mui_bg1");
	TextDrawTextSize(mine_job_1[0], 644.000000, 451.000000);
	TextDrawAlignment(mine_job_1[0], 1);
	TextDrawColor(mine_job_1[0], -1);
	TextDrawBackgroundColor(mine_job_1[0], 255);
	TextDrawFont(mine_job_1[0], 4);
	TextDrawSetProportional(mine_job_1[0], 0);

	mine_job_1[1] = TextDrawCreate(530.000000, 36.000000, "minejob:mui_exit");
	TextDrawTextSize(mine_job_1[1], 34.000000, 25.000000);
	TextDrawAlignment(mine_job_1[1], 1);
	TextDrawColor(mine_job_1[1], -1);
	TextDrawBackgroundColor(mine_job_1[1], 255);
	TextDrawFont(mine_job_1[1], 4);
	TextDrawSetProportional(mine_job_1[1], 0);
	TextDrawSetSelectable(mine_job_1[1], true);



	mine_job_2[0] = TextDrawCreate(-1.000000, -1.000000, "minejob:mui_bg2");
	TextDrawTextSize(mine_job_2[0], 644.000000, 451.000000);
	TextDrawAlignment(mine_job_2[0], 1);
	TextDrawColor(mine_job_2[0], -1);
	TextDrawBackgroundColor(mine_job_2[0], 255);
	TextDrawFont(mine_job_2[0], 4);
	TextDrawSetProportional(mine_job_2[0], 0);

	mine_job_2[1] = TextDrawCreate(530.000000, 36.000000, "minejob:mui_exit");
	TextDrawTextSize(mine_job_2[1], 34.000000, 25.000000);
	TextDrawAlignment(mine_job_2[1], 1);
	TextDrawColor(mine_job_2[1], -1);
	TextDrawBackgroundColor(mine_job_2[1], 255);
	TextDrawFont(mine_job_2[1], 4);
	TextDrawSetProportional(mine_job_2[1], 0);
	TextDrawSetSelectable(mine_job_2[1], true);


	mine_job_3[0] = TextDrawCreate(-1.000000, -1.000000, "minejob:mui_bg3");
	TextDrawTextSize(mine_job_3[0], 644.000000, 451.000000);
	TextDrawAlignment(mine_job_3[0], 1);
	TextDrawColor(mine_job_3[0], -1);
	TextDrawBackgroundColor(mine_job_3[0], 255);
	TextDrawFont(mine_job_3[0], 4);
	TextDrawSetProportional(mine_job_3[0], 0);

	mine_job_3[1] = TextDrawCreate(530.000000, 36.000000, "minejob:mui_exit");
	TextDrawTextSize(mine_job_3[1], 34.000000, 25.000000);
	TextDrawAlignment(mine_job_3[1], 1);
	TextDrawColor(mine_job_3[1], -1);
	TextDrawBackgroundColor(mine_job_3[1], 255);
	TextDrawFont(mine_job_3[1], 4);
	TextDrawSetProportional(mine_job_3[1], 0);
	TextDrawSetSelectable(mine_job_3[1], true);

	mine_job_3[2] = TextDrawCreate(107.000000, 130.000000, "minejob:mui_white");
	TextDrawTextSize(mine_job_3[2], 60.000000, 53.000000);
	TextDrawAlignment(mine_job_3[2], 1);
	TextDrawColor(mine_job_3[2], -1);
	TextDrawBackgroundColor(mine_job_3[2], 255);
	TextDrawFont(mine_job_3[2], 4);
	TextDrawSetProportional(mine_job_3[2], 0);
	TextDrawSetSelectable(mine_job_3[2], true);

	mine_job_3[3] = TextDrawCreate(107.000000, 197.200256, "minejob:mui_white");
	TextDrawTextSize(mine_job_3[3], 60.000000, 53.000000);
	TextDrawAlignment(mine_job_3[3], 1);
	TextDrawColor(mine_job_3[3], -1);
	TextDrawBackgroundColor(mine_job_3[3], 255);
	TextDrawFont(mine_job_3[3], 4);
	TextDrawSetProportional(mine_job_3[3], 0);
	TextDrawSetSelectable(mine_job_3[3], true);

	mine_job_3[4] = TextDrawCreate(107.000000, 262.800506, "minejob:mui_white");
	TextDrawTextSize(mine_job_3[4], 60.000000, 53.000000);
	TextDrawAlignment(mine_job_3[4], 1);
	TextDrawColor(mine_job_3[4], -1);
	TextDrawBackgroundColor(mine_job_3[4], 255);
	TextDrawFont(mine_job_3[4], 4);
	TextDrawSetProportional(mine_job_3[4], 0);
	TextDrawSetSelectable(mine_job_3[4], true);

	mine_job_3[5] = TextDrawCreate(214.000000, 142.000000, "minejob:mui_white");
	TextDrawTextSize(mine_job_3[5], 80.000000, 121.000000);
	TextDrawAlignment(mine_job_3[5], 1);
	TextDrawColor(mine_job_3[5], -1);
	TextDrawBackgroundColor(mine_job_3[5], 255);
	TextDrawFont(mine_job_3[5], 4);
	TextDrawSetProportional(mine_job_3[5], 0);
	TextDrawSetSelectable(mine_job_3[5], true);

	mine_job_3[6] = TextDrawCreate(327.600433, 142.000000, "minejob:mui_white");
	TextDrawTextSize(mine_job_3[6], 80.000000, 121.000000);
	TextDrawAlignment(mine_job_3[6], 1);
	TextDrawColor(mine_job_3[6], -1);
	TextDrawBackgroundColor(mine_job_3[6], 255);
	TextDrawFont(mine_job_3[6], 4);
	TextDrawSetProportional(mine_job_3[6], 0);
	TextDrawSetSelectable(mine_job_3[6], true);

	mine_job_3[7] = TextDrawCreate(439.600860, 142.000000, "minejob:mui_white");
	TextDrawTextSize(mine_job_3[7], 80.000000, 121.000000);
	TextDrawAlignment(mine_job_3[7], 1);
	TextDrawColor(mine_job_3[7], -1);
	TextDrawBackgroundColor(mine_job_3[7], 255);
	TextDrawFont(mine_job_3[7], 4);
	TextDrawSetProportional(mine_job_3[7], 0);
	TextDrawSetSelectable(mine_job_3[7], true);

	return true;
}

stock create_miner_job_1(playerid)
{
	if(miner_job_1_p[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_1_p[0][playerid] = CreatePlayerTextDraw(playerid, 0.333496, 0.851852, "x1");
		PlayerTextDrawLetterSize(playerid, miner_job_1_p[0][playerid], 0.443666, 2.039700);
		PlayerTextDrawAlignment(playerid, miner_job_1_p[0][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_1_p[0][playerid], 255);
		PlayerTextDrawSetShadow(playerid, miner_job_1_p[0][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, miner_job_1_p[0][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_1_p[0][playerid], 1);
		PlayerTextDrawSetProportional(playerid, miner_job_1_p[0][playerid], 1);
	}
	if(miner_job_1_p[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_1_p[1][playerid] = CreatePlayerTextDraw(playerid, 319.999938, 68.000015, "+_12312");
		PlayerTextDrawLetterSize(playerid, miner_job_1_p[1][playerid], 0.574998, 2.678518);
		PlayerTextDrawTextSize(playerid, miner_job_1_p[1][playerid], 0.000000, 513.360351);
		PlayerTextDrawAlignment(playerid, miner_job_1_p[1][playerid], 2);
		PlayerTextDrawColor(playerid, miner_job_1_p[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, miner_job_1_p[1][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, miner_job_1_p[1][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_1_p[1][playerid], 1);
		PlayerTextDrawSetProportional(playerid, miner_job_1_p[1][playerid], 1);
	}
	if(miner_job_1_p[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_1_p[2][playerid] = CreatePlayerTextDraw(playerid, 349.000000, 363.000000, "0000000");
		PlayerTextDrawLetterSize(playerid, miner_job_1_p[2][playerid], 0.554332, 2.309334);
		PlayerTextDrawAlignment(playerid, miner_job_1_p[2][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_1_p[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, miner_job_1_p[2][playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_1_p[2][playerid], 30);
		PlayerTextDrawFont(playerid, miner_job_1_p[2][playerid], 1);
		PlayerTextDrawSetProportional(playerid, miner_job_1_p[2][playerid], 1);
	}
	if(miner_job_1_p[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{	

		miner_job_1_p[3][playerid] = CreatePlayerTextDraw(playerid, 77.333351, 116.422195, "minejob:mui_qcoal");
		PlayerTextDrawTextSize(playerid, miner_job_1_p[3][playerid], 53.000000, 78.000000);
		PlayerTextDrawAlignment(playerid, miner_job_1_p[3][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_1_p[3][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_1_p[3][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_1_p[3][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_1_p[3][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, miner_job_1_p[3][playerid], true);
	}
	if(miner_job_1_p[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_1_p[4][playerid] = CreatePlayerTextDraw(playerid, 77.666679, 235.059204, "minejob:mui_qcoal");
		PlayerTextDrawTextSize(playerid, miner_job_1_p[4][playerid], 53.000000, 78.000000);
		PlayerTextDrawAlignment(playerid, miner_job_1_p[4][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_1_p[4][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_1_p[4][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_1_p[4][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_1_p[4][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, miner_job_1_p[4][playerid], true);
	}
	if(miner_job_1_p[5][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_1_p[5][playerid] = CreatePlayerTextDraw(playerid, 133.333312, 171.592575, "minejob:mui_qcoal");
		PlayerTextDrawTextSize(playerid, miner_job_1_p[5][playerid], 53.000000, 78.000000);
		PlayerTextDrawAlignment(playerid, miner_job_1_p[5][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_1_p[5][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_1_p[5][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_1_p[5][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_1_p[5][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, miner_job_1_p[5][playerid], true);
	}
	if(miner_job_1_p[6][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{

		miner_job_1_p[6][playerid] = CreatePlayerTextDraw(playerid, 176.666610, 103.977760, "minejob:mui_qcoal");
		PlayerTextDrawTextSize(playerid, miner_job_1_p[6][playerid], 53.000000, 78.000000);
		PlayerTextDrawAlignment(playerid, miner_job_1_p[6][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_1_p[6][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_1_p[6][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_1_p[6][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_1_p[6][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, miner_job_1_p[6][playerid], true);
	}
	if(miner_job_1_p[7][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{

		miner_job_1_p[7][playerid] = CreatePlayerTextDraw(playerid, 183.333282, 238.377777, "minejob:mui_qcoal");
		PlayerTextDrawTextSize(playerid, miner_job_1_p[7][playerid], 53.000000, 78.000000);
		PlayerTextDrawAlignment(playerid, miner_job_1_p[7][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_1_p[7][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_1_p[7][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_1_p[7][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_1_p[7][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, miner_job_1_p[7][playerid], true);
	}
	if(miner_job_1_p[8][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{

		miner_job_1_p[8][playerid] = CreatePlayerTextDraw(playerid, 234.333297, 172.422241, "minejob:mui_qcoal");
		PlayerTextDrawTextSize(playerid, miner_job_1_p[8][playerid], 53.000000, 78.000000);
		PlayerTextDrawAlignment(playerid, miner_job_1_p[8][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_1_p[8][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_1_p[8][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_1_p[8][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_1_p[8][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, miner_job_1_p[8][playerid], true);
	}
	if(miner_job_1_p[9][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_1_p[9][playerid] = CreatePlayerTextDraw(playerid, 281.666564, 106.051887, "minejob:mui_qcoal");
		PlayerTextDrawTextSize(playerid, miner_job_1_p[9][playerid], 53.000000, 78.000000);
		PlayerTextDrawAlignment(playerid, miner_job_1_p[9][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_1_p[9][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_1_p[9][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_1_p[9][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_1_p[9][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, miner_job_1_p[9][playerid], true);
	}
	if(miner_job_1_p[10][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_1_p[10][playerid] = CreatePlayerTextDraw(playerid, 259.999847, 259.948150, "minejob:mui_qcoal");
		PlayerTextDrawTextSize(playerid, miner_job_1_p[10][playerid], 53.000000, 78.000000);
		PlayerTextDrawAlignment(playerid, miner_job_1_p[10][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_1_p[10][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_1_p[10][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_1_p[10][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_1_p[10][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, miner_job_1_p[10][playerid], true);
	}
	if(miner_job_1_p[11][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_1_p[11][playerid] = CreatePlayerTextDraw(playerid, 314.999938, 172.422210, "minejob:mui_qcoal");
		PlayerTextDrawTextSize(playerid, miner_job_1_p[11][playerid], 53.000000, 78.000000);
		PlayerTextDrawAlignment(playerid, miner_job_1_p[11][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_1_p[11][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_1_p[11][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_1_p[11][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_1_p[11][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, miner_job_1_p[11][playerid], true);
	}
	if(miner_job_1_p[12][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_1_p[12][playerid] = CreatePlayerTextDraw(playerid, 370.666625, 260.777770, "minejob:mui_qcoal");
		PlayerTextDrawTextSize(playerid, miner_job_1_p[12][playerid], 53.000000, 78.000000);
		PlayerTextDrawAlignment(playerid, miner_job_1_p[12][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_1_p[12][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_1_p[12][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_1_p[12][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_1_p[12][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, miner_job_1_p[12][playerid], true);
	}
	if(miner_job_1_p[13][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_1_p[13][playerid] = CreatePlayerTextDraw(playerid, 394.333343, 108.955566, "minejob:mui_qcoal");
		PlayerTextDrawTextSize(playerid, miner_job_1_p[13][playerid], 53.000000, 78.000000);
		PlayerTextDrawAlignment(playerid, miner_job_1_p[13][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_1_p[13][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_1_p[13][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_1_p[13][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_1_p[13][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, miner_job_1_p[13][playerid], true);
	}
	if(miner_job_1_p[14][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{

		miner_job_1_p[14][playerid] = CreatePlayerTextDraw(playerid, 413.999969, 193.577804, "minejob:mui_qcoal");
		PlayerTextDrawTextSize(playerid, miner_job_1_p[14][playerid], 53.000000, 78.000000);
		PlayerTextDrawAlignment(playerid, miner_job_1_p[14][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_1_p[14][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_1_p[14][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_1_p[14][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_1_p[14][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, miner_job_1_p[14][playerid], true);
	}
	if(miner_job_1_p[15][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_1_p[15][playerid] = CreatePlayerTextDraw(playerid, 464.666687, 71.622238, "minejob:mui_qcoal");
		PlayerTextDrawTextSize(playerid, miner_job_1_p[15][playerid], 53.000000, 78.000000);
		PlayerTextDrawAlignment(playerid, miner_job_1_p[15][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_1_p[15][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_1_p[15][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_1_p[15][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_1_p[15][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, miner_job_1_p[15][playerid], true);
	}
	if(miner_job_1_p[16][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{

		miner_job_1_p[16][playerid] = CreatePlayerTextDraw(playerid, 483.666687, 164.955551, "minejob:mui_qcoal");
		PlayerTextDrawTextSize(playerid, miner_job_1_p[16][playerid], 53.000000, 78.000000);
		PlayerTextDrawAlignment(playerid, miner_job_1_p[16][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_1_p[16][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_1_p[16][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_1_p[16][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_1_p[16][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, miner_job_1_p[16][playerid], true);
	}
	if(miner_job_1_p[17][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{

		miner_job_1_p[17][playerid] = CreatePlayerTextDraw(playerid, 455.333404, 274.466735, "minejob:mui_qcoal");
		PlayerTextDrawTextSize(playerid, miner_job_1_p[17][playerid], 53.000000, 78.000000);
		PlayerTextDrawAlignment(playerid, miner_job_1_p[17][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_1_p[17][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_1_p[17][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_1_p[17][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_1_p[17][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, miner_job_1_p[17][playerid], true);
	}
	if(miner_job_1_p[18][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{

		miner_job_1_p[18][playerid] = CreatePlayerTextDraw(playerid, 519.000061, 237.963027, "minejob:mui_qcoal");
		PlayerTextDrawTextSize(playerid, miner_job_1_p[18][playerid], 53.000000, 78.000000);
		PlayerTextDrawAlignment(playerid, miner_job_1_p[18][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_1_p[18][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_1_p[18][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_1_p[18][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_1_p[18][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, miner_job_1_p[18][playerid], true);
	}
	if(miner_job_1_p[19][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{

		miner_job_1_p[19][playerid] = CreatePlayerTextDraw(playerid, 274.000000, 294.377899, "minejob:mui_coal");
		PlayerTextDrawTextSize(playerid, miner_job_1_p[19][playerid], 95.000000, 96.000000);
		PlayerTextDrawAlignment(playerid, miner_job_1_p[19][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_1_p[19][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_1_p[19][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_1_p[19][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_1_p[19][playerid], 0);
	}
	if(miner_job_1_p[20][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{

		miner_job_1_p[20][playerid] = CreatePlayerTextDraw(playerid, 208.300079, 361.199951, "minejob:mui_p1");
		PlayerTextDrawTextSize(playerid, miner_job_1_p[20][playerid], 87.699928, 29.110000);
		PlayerTextDrawAlignment(playerid, miner_job_1_p[20][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_1_p[20][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_1_p[20][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_1_p[20][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_1_p[20][playerid], 0);
	}
	if(miner_job_1_p[21][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_1_p[21][playerid] = CreatePlayerTextDraw(playerid, 127.599990, 37.300010, "x1");
		PlayerTextDrawLetterSize(playerid, miner_job_1_p[21][playerid], 0.443666, 2.039700);
		PlayerTextDrawAlignment(playerid, miner_job_1_p[21][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_1_p[21][playerid], 1962902271);
		PlayerTextDrawSetShadow(playerid, miner_job_1_p[21][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, miner_job_1_p[21][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_1_p[21][playerid], 1);
		PlayerTextDrawSetProportional(playerid, miner_job_1_p[21][playerid], 1);
	}
	return true;
}

stock create_miner_job_2(playerid)
{
	if(miner_job_2_p[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_2_p[0][playerid] = CreatePlayerTextDraw(playerid, 0.333496, 0.851852, "x1");
		PlayerTextDrawLetterSize(playerid, miner_job_2_p[0][playerid], 0.443666, 2.039700);
		PlayerTextDrawAlignment(playerid, miner_job_2_p[0][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_2_p[0][playerid], 255);
		PlayerTextDrawSetShadow(playerid, miner_job_2_p[0][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, miner_job_2_p[0][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_2_p[0][playerid], 1);
		PlayerTextDrawSetProportional(playerid, miner_job_2_p[0][playerid], 1);
	}
	if(miner_job_2_p[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_2_p[1][playerid] = CreatePlayerTextDraw(playerid, 319.999938, 68.000015, "+_12312");
		PlayerTextDrawLetterSize(playerid, miner_job_2_p[1][playerid], 0.574998, 2.678518);
		PlayerTextDrawTextSize(playerid, miner_job_2_p[1][playerid], 0.000000, 513.360351);
		PlayerTextDrawAlignment(playerid, miner_job_2_p[1][playerid], 2);
		PlayerTextDrawColor(playerid, miner_job_2_p[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, miner_job_2_p[1][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, miner_job_2_p[1][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_2_p[1][playerid], 1);
		PlayerTextDrawSetProportional(playerid, miner_job_2_p[1][playerid], 1);
	}
	if(miner_job_2_p[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{

		miner_job_2_p[2][playerid] = CreatePlayerTextDraw(playerid, 349.000000, 363.000000, "0000000");
		PlayerTextDrawLetterSize(playerid, miner_job_2_p[2][playerid], 0.554332, 2.309334);
		PlayerTextDrawAlignment(playerid, miner_job_2_p[2][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_2_p[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, miner_job_2_p[2][playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_2_p[2][playerid], 30);
		PlayerTextDrawFont(playerid, miner_job_2_p[2][playerid], 1);
		PlayerTextDrawSetProportional(playerid, miner_job_2_p[2][playerid], 1);
	}
	if(miner_job_2_p[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{

		miner_job_2_p[3][playerid] = CreatePlayerTextDraw(playerid, 95.300010, 158.399963, "minejob:mui_qcoal");
		PlayerTextDrawTextSize(playerid, miner_job_2_p[3][playerid], 63.389976, 93.000000);
		PlayerTextDrawAlignment(playerid, miner_job_2_p[3][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_2_p[3][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_2_p[3][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_2_p[3][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_2_p[3][playerid], 0);
	}
	if(miner_job_2_p[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_2_p[4][playerid] = CreatePlayerTextDraw(playerid, 150.599990, 158.399963, "minejob:mui_qcoal");
		PlayerTextDrawTextSize(playerid, miner_job_2_p[4][playerid], 63.389976, 93.000000);
		PlayerTextDrawAlignment(playerid, miner_job_2_p[4][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_2_p[4][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_2_p[4][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_2_p[4][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_2_p[4][playerid], 0);
	}
	if(miner_job_2_p[5][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_2_p[5][playerid] = CreatePlayerTextDraw(playerid, 205.900039, 158.399963, "minejob:mui_qcoal");
		PlayerTextDrawTextSize(playerid, miner_job_2_p[5][playerid], 63.389976, 93.000000);
		PlayerTextDrawAlignment(playerid, miner_job_2_p[5][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_2_p[5][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_2_p[5][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_2_p[5][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_2_p[5][playerid], 0);
	}
	if(miner_job_2_p[6][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_2_p[6][playerid] = CreatePlayerTextDraw(playerid, 261.200012, 158.399963, "minejob:mui_qcoal");
		PlayerTextDrawTextSize(playerid, miner_job_2_p[6][playerid], 63.389976, 93.000000);
		PlayerTextDrawAlignment(playerid, miner_job_2_p[6][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_2_p[6][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_2_p[6][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_2_p[6][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_2_p[6][playerid], 0);
	}
	if(miner_job_2_p[7][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_2_p[7][playerid] = CreatePlayerTextDraw(playerid, 316.400054, 158.399963, "minejob:mui_qcoal");
		PlayerTextDrawTextSize(playerid, miner_job_2_p[7][playerid], 63.389976, 93.000000);
		PlayerTextDrawAlignment(playerid, miner_job_2_p[7][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_2_p[7][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_2_p[7][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_2_p[7][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_2_p[7][playerid], 0);
	}
	if(miner_job_2_p[8][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_2_p[8][playerid] = CreatePlayerTextDraw(playerid, 372.000335, 158.399963, "minejob:mui_qcoal");
		PlayerTextDrawTextSize(playerid, miner_job_2_p[8][playerid], 63.389976, 93.000000);
		PlayerTextDrawAlignment(playerid, miner_job_2_p[8][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_2_p[8][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_2_p[8][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_2_p[8][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_2_p[8][playerid], 0);
	}
	if(miner_job_2_p[9][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_2_p[9][playerid] = CreatePlayerTextDraw(playerid, 427.000152, 158.399963, "minejob:mui_qcoal");
		PlayerTextDrawTextSize(playerid, miner_job_2_p[9][playerid], 63.389976, 93.000000);
		PlayerTextDrawAlignment(playerid, miner_job_2_p[9][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_2_p[9][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_2_p[9][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_2_p[9][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_2_p[9][playerid], 0);
	}
	if(miner_job_2_p[10][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_2_p[10][playerid] = CreatePlayerTextDraw(playerid, 482.400085, 158.399963, "minejob:mui_qcoal");
		PlayerTextDrawTextSize(playerid, miner_job_2_p[10][playerid], 63.389976, 93.000000);
		PlayerTextDrawAlignment(playerid, miner_job_2_p[10][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_2_p[10][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_2_p[10][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_2_p[10][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_2_p[10][playerid], 0);
	}
	if(miner_job_2_p[11][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{	
		miner_job_2_p[11][playerid] = CreatePlayerTextDraw(playerid, 100.600006, 154.300079, "minejob:mui_frame");
		PlayerTextDrawTextSize(playerid, miner_job_2_p[11][playerid], 52.609996, 89.070007);
		PlayerTextDrawAlignment(playerid, miner_job_2_p[11][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_2_p[11][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_2_p[11][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_2_p[11][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_2_p[11][playerid], 0);
	}
	if(miner_job_2_p[12][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_2_p[12][playerid] = CreatePlayerTextDraw(playerid, 274.000000, 294.377899, "minejob:mui_coal");
		PlayerTextDrawTextSize(playerid, miner_job_2_p[12][playerid], 95.000000, 96.000000);
		PlayerTextDrawAlignment(playerid, miner_job_2_p[12][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_2_p[12][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_2_p[12][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_2_p[12][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_2_p[12][playerid], 0);
		PlayerTextDrawSetSelectable(playerid, miner_job_2_p[12][playerid], true);
	}
	if(miner_job_2_p[13][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_2_p[13][playerid] = CreatePlayerTextDraw(playerid, 208.300079, 361.199951, "minejob:mui_p1");
		PlayerTextDrawTextSize(playerid, miner_job_2_p[13][playerid], 87.699928, 29.110000);
		PlayerTextDrawAlignment(playerid, miner_job_2_p[13][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_2_p[13][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_2_p[13][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_2_p[13][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_2_p[13][playerid], 0);
	}
	if(miner_job_2_p[14][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_2_p[14][playerid] = CreatePlayerTextDraw(playerid, 127.599990, 37.300010, "x1");
		PlayerTextDrawLetterSize(playerid, miner_job_2_p[14][playerid], 0.443666, 2.039700);
		PlayerTextDrawAlignment(playerid, miner_job_2_p[14][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_2_p[14][playerid], 1962902271);
		PlayerTextDrawSetShadow(playerid, miner_job_2_p[14][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, miner_job_2_p[14][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_2_p[14][playerid], 1);
		PlayerTextDrawSetProportional(playerid, miner_job_2_p[14][playerid], 1);
	}
	return true;

}

stock create_miner_job_3(playerid)
{
	if(miner_job_3_p[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_3_p[0][playerid] = CreatePlayerTextDraw(playerid, 0.333496, 0.851852, "x1");
		PlayerTextDrawLetterSize(playerid, miner_job_3_p[0][playerid], 0.443666, 2.039700);
		PlayerTextDrawAlignment(playerid, miner_job_3_p[0][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_3_p[0][playerid], 255);
		PlayerTextDrawSetShadow(playerid, miner_job_3_p[0][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, miner_job_3_p[0][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_3_p[0][playerid], 1);
		PlayerTextDrawSetProportional(playerid, miner_job_3_p[0][playerid], 1);

	}
	if(miner_job_3_p[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_3_p[1][playerid] = CreatePlayerTextDraw(playerid, 319.999938, 68.000015, "+_12312");
		PlayerTextDrawLetterSize(playerid, miner_job_3_p[1][playerid], 0.574998, 2.678518);
		PlayerTextDrawTextSize(playerid, miner_job_3_p[1][playerid], 0.000000, 513.360351);
		PlayerTextDrawAlignment(playerid, miner_job_3_p[1][playerid], 2);
		PlayerTextDrawColor(playerid, miner_job_3_p[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, miner_job_3_p[1][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, miner_job_3_p[1][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_3_p[1][playerid], 1);
		PlayerTextDrawSetProportional(playerid, miner_job_3_p[1][playerid], 1);

	}
	if(miner_job_3_p[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_3_p[2][playerid] = CreatePlayerTextDraw(playerid, 349.000000, 363.000000, "0000000");
		PlayerTextDrawLetterSize(playerid, miner_job_3_p[2][playerid], 0.554332, 2.309334);
		PlayerTextDrawAlignment(playerid, miner_job_3_p[2][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_3_p[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, miner_job_3_p[2][playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_3_p[2][playerid], 30);
		PlayerTextDrawFont(playerid, miner_job_3_p[2][playerid], 1);
		PlayerTextDrawSetProportional(playerid, miner_job_3_p[2][playerid], 1);

	}
	if(miner_job_3_p[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_3_p[3][playerid] = CreatePlayerTextDraw(playerid, 175.000000, 106.000000, "minejob:mui_chestdiamond");
		PlayerTextDrawTextSize(playerid, miner_job_3_p[3][playerid], 158.000000, 194.000000);
		PlayerTextDrawAlignment(playerid, miner_job_3_p[3][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_3_p[3][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_3_p[3][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_3_p[3][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_3_p[3][playerid], 0);
		//PlayerTextDrawSetSelectable(playerid, miner_job_3_p[3][playerid], true);

	}
	if(miner_job_3_p[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_3_p[4][playerid] = CreatePlayerTextDraw(playerid, 288.600433, 106.000000, "minejob:mui_gchestfullmetal");
		PlayerTextDrawTextSize(playerid, miner_job_3_p[4][playerid], 158.000000, 194.000000);
		PlayerTextDrawAlignment(playerid, miner_job_3_p[4][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_3_p[4][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_3_p[4][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_3_p[4][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_3_p[4][playerid], 0);
		//PlayerTextDrawSetSelectable(playerid, miner_job_3_p[4][playerid], true);

	}
	if(miner_job_3_p[5][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_3_p[5][playerid] = CreatePlayerTextDraw(playerid, 400.600860, 106.000000, "minejob:mui_rchestcoal");
		PlayerTextDrawTextSize(playerid, miner_job_3_p[5][playerid], 158.000000, 194.000000);
		PlayerTextDrawAlignment(playerid, miner_job_3_p[5][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_3_p[5][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_3_p[5][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_3_p[5][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_3_p[5][playerid], 0);
		//PlayerTextDrawSetSelectable(playerid, miner_job_3_p[5][playerid], true);

	}
	if(miner_job_3_p[6][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_3_p[6][playerid] = CreatePlayerTextDraw(playerid, 78.400001, 94.200004, "minejob:mui_riron");
		PlayerTextDrawTextSize(playerid, miner_job_3_p[6][playerid], 118.000000, 125.000000);
		PlayerTextDrawAlignment(playerid, miner_job_3_p[6][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_3_p[6][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_3_p[6][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_3_p[6][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_3_p[6][playerid], 0);
		//PlayerTextDrawSetSelectable(playerid, miner_job_3_p[6][playerid], true);

	}
	if(miner_job_3_p[7][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_3_p[7][playerid] = CreatePlayerTextDraw(playerid, 78.400001, 159.800094, "minejob:mui_coal");
		PlayerTextDrawTextSize(playerid, miner_job_3_p[7][playerid], 118.000000, 125.000000);
		PlayerTextDrawAlignment(playerid, miner_job_3_p[7][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_3_p[7][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_3_p[7][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_3_p[7][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_3_p[7][playerid], 0);
		//PlayerTextDrawSetSelectable(playerid, miner_job_3_p[7][playerid], true);

	}
	if(miner_job_3_p[8][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_3_p[8][playerid] = CreatePlayerTextDraw(playerid, 78.400001, 225.400344, "minejob:mui_gmetal");
		PlayerTextDrawTextSize(playerid, miner_job_3_p[8][playerid], 118.000000, 125.000000);
		PlayerTextDrawAlignment(playerid, miner_job_3_p[8][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_3_p[8][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_3_p[8][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_3_p[8][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_3_p[8][playerid], 0);
		//PlayerTextDrawSetSelectable(playerid, miner_job_3_p[8][playerid], true);
	}
	if(miner_job_3_p[9][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_3_p[9][playerid] = CreatePlayerTextDraw(playerid, 274.000000, 294.377899, "minejob:mui_coal");
		PlayerTextDrawTextSize(playerid, miner_job_3_p[9][playerid], 95.000000, 96.000000);
		PlayerTextDrawAlignment(playerid, miner_job_3_p[9][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_3_p[9][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_3_p[9][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_3_p[9][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_3_p[9][playerid], 0);
	}
	if(miner_job_3_p[10][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_3_p[10][playerid] = CreatePlayerTextDraw(playerid, 208.300079, 361.199951, "minejob:mui_p1");
		PlayerTextDrawTextSize(playerid, miner_job_3_p[10][playerid], 87.699928, 29.110000);
		PlayerTextDrawAlignment(playerid, miner_job_3_p[10][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_3_p[10][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, miner_job_3_p[10][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_3_p[10][playerid], 4);
		PlayerTextDrawSetProportional(playerid, miner_job_3_p[10][playerid], 0);
	}
	if(miner_job_3_p[11][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		miner_job_3_p[11][playerid] = CreatePlayerTextDraw(playerid, 127.599990, 37.300010, "x1");
		PlayerTextDrawLetterSize(playerid, miner_job_3_p[11][playerid], 0.443666, 2.039700);
		PlayerTextDrawAlignment(playerid, miner_job_3_p[11][playerid], 1);
		PlayerTextDrawColor(playerid, miner_job_3_p[11][playerid], 1962902271);
		PlayerTextDrawSetShadow(playerid, miner_job_3_p[11][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, miner_job_3_p[11][playerid], 255);
		PlayerTextDrawFont(playerid, miner_job_3_p[11][playerid], 1);
		PlayerTextDrawSetProportional(playerid, miner_job_3_p[11][playerid], 1);

	}	
	return true;

}

stock create_select_spawn()
{
	select_spawn[0] = TextDrawCreate(0.000000, 0.000000, "brilliantother:spawn_select_background"); // Texture element
	TextDrawLetterSize(select_spawn[0], 0.000000, 0.000000);
	TextDrawTextSize(select_spawn[0], 642.333312, 413.984924);
	TextDrawAlignment(select_spawn[0], 1);
	TextDrawColor(select_spawn[0], -1);
	TextDrawSetShadow(select_spawn[0], 0);
	TextDrawSetOutline(select_spawn[0], 0);
	TextDrawFont(select_spawn[0], 4);

	select_spawn[1] = TextDrawCreate(40.666687, 112.829627, "brilliantother:spawn_select_window_1"); // Texture element
	TextDrawLetterSize(select_spawn[1], 0.000000, 0.000000);
	TextDrawTextSize(select_spawn[1], 126.666648, 211.970382);
	TextDrawAlignment(select_spawn[1], 2);
	TextDrawColor(select_spawn[1], -1);
	TextDrawSetShadow(select_spawn[1], 0);
	TextDrawSetOutline(select_spawn[1], 0);
	TextDrawFont(select_spawn[1], 4);
	TextDrawSetSelectable(select_spawn[1], true);

	select_spawn[2] = TextDrawCreate(184.000045, 113.244415, "brilliantother:spawn_select_window_2"); // Texture element
	TextDrawLetterSize(select_spawn[2], 0.000000, 0.000000);
	TextDrawTextSize(select_spawn[2], 126.999992, 211.970306);
	TextDrawAlignment(select_spawn[2], 2);
	TextDrawColor(select_spawn[2], -1);
	TextDrawSetShadow(select_spawn[2], 0);
	TextDrawSetOutline(select_spawn[2], 0);
	TextDrawFont(select_spawn[2], 4);
	TextDrawSetSelectable(select_spawn[2], true);

	select_spawn[3] = TextDrawCreate(473.000152, 112.414764, "brilliantother:spawn_select_window_4"); // Texture element
	TextDrawLetterSize(select_spawn[3], 0.000000, 0.000000);
	TextDrawTextSize(select_spawn[3], 128.333282, 211.970321);
	TextDrawAlignment(select_spawn[3], 2);
	TextDrawColor(select_spawn[3], -1);
	TextDrawSetShadow(select_spawn[3], 0);
	TextDrawSetOutline(select_spawn[3], 0);
	TextDrawFont(select_spawn[3], 4);
	TextDrawSetSelectable(select_spawn[3], true);

	select_spawn[4] = TextDrawCreate(327.666748, 112.829627, "brilliantother:spawn_select_window_3"); // Texture element
	TextDrawLetterSize(select_spawn[4], 0.000000, 0.000000);
	TextDrawTextSize(select_spawn[4], 127.000000, 211.970291);
	TextDrawAlignment(select_spawn[4], 2);
	TextDrawColor(select_spawn[4], -1);
	TextDrawSetShadow(select_spawn[4], 0);
	TextDrawSetOutline(select_spawn[4], 0);
	TextDrawFont(select_spawn[4], 4);
	TextDrawSetSelectable(select_spawn[4], true);

	select_spawn[5] = TextDrawCreate(-1.000017, 1008.830078, "brilliantother:spawn_select_background"); // Texture element
	TextDrawLetterSize(select_spawn[5], 0.000000, 0.000000);
	TextDrawTextSize(select_spawn[5], 651.332824, -596.089294);
	TextDrawAlignment(select_spawn[5], 1);
	TextDrawColor(select_spawn[5], -1);
	TextDrawSetShadow(select_spawn[5], 0);
	TextDrawSetOutline(select_spawn[5], 0);
	TextDrawFont(select_spawn[5], 4);

	return true;
}

stock create_quest_td_global()
{
	quest_panel_general[0] = TextDrawCreate(131.333343, 139.377761, "brp_quest:quest_button_quest"); // Texture element
	TextDrawLetterSize(quest_panel_general[0], 0.000000, 0.000000);
	TextDrawTextSize(quest_panel_general[0], 73.333312, 32.355564);
	TextDrawAlignment(quest_panel_general[0], 2);
	TextDrawColor(quest_panel_general[0], -1);
	TextDrawSetShadow(quest_panel_general[0], 0);
	TextDrawSetOutline(quest_panel_general[0], 0);
	TextDrawFont(quest_panel_general[0], 4);

	quest_panel_general[1] = TextDrawCreate(210.666625, 139.792556, "brp_quest:quest_button_other_quest"); // Texture element
	TextDrawLetterSize(quest_panel_general[1], 0.000000, 0.000000);
	TextDrawTextSize(quest_panel_general[1], 0.0, 0.0);
	TextDrawAlignment(quest_panel_general[1], 2);
	TextDrawColor(quest_panel_general[1], -1);
	TextDrawSetShadow(quest_panel_general[1], 0);
	TextDrawSetOutline(quest_panel_general[1], 0);
	TextDrawFont(quest_panel_general[1], 4);
	TextDrawSetSelectable(quest_panel_general[1], true);

	quest_panel_general[2] = TextDrawCreate(480.666656, 99.140747, "brp_quest:quest_button_close"); // Texture element
	TextDrawLetterSize(quest_panel_general[2], 0.000000, 0.000000);
	TextDrawTextSize(quest_panel_general[2], 15.999974, 18.666677);
	TextDrawAlignment(quest_panel_general[2], 2);
	TextDrawColor(quest_panel_general[2], -1);
	TextDrawSetShadow(quest_panel_general[2], 0);
	TextDrawSetOutline(quest_panel_general[2], 0);
	TextDrawFont(quest_panel_general[2], 4);
	TextDrawSetSelectable(quest_panel_general[2], true);

	quest_panel_general[3] = TextDrawCreate(133.999969, 337.659210, "brp_quest:quest_button_prew"); // Texture element
	TextDrawLetterSize(quest_panel_general[3], 0.000000, 0.000000);
	TextDrawTextSize(quest_panel_general[3], 43.999996, 28.622220);
	TextDrawAlignment(quest_panel_general[3], 2);
	TextDrawColor(quest_panel_general[3], -1);
	TextDrawSetShadow(quest_panel_general[3], 0);
	TextDrawSetOutline(quest_panel_general[3], 0);
	TextDrawFont(quest_panel_general[3], 4);
	TextDrawSetSelectable(quest_panel_general[3], true);

	quest_panel_general[4] = TextDrawCreate(239.666687, 337.659149, "brp_quest:quest_button_next"); // Texture element
	TextDrawLetterSize(quest_panel_general[4], 0.000000, 0.000000);
	TextDrawTextSize(quest_panel_general[4], 43.999996, 28.622220);
	TextDrawAlignment(quest_panel_general[4], 2);
	TextDrawColor(quest_panel_general[4], -1);
	TextDrawSetShadow(quest_panel_general[4], 0);
	TextDrawSetOutline(quest_panel_general[4], 0);
	TextDrawFont(quest_panel_general[4], 4);
	TextDrawSetSelectable(quest_panel_general[4], true);


	return true;
}

stock create_mechanic_background()
{

	mech_background_repair = TextDrawCreate(0.000000, 0.000000, "brilliantother:rapair_vehicle_gui"); // Texture element
	TextDrawLetterSize(mech_background_repair, 0.000000, 0.000000);
	TextDrawTextSize(mech_background_repair, 643.666442, 450.488952);
	TextDrawAlignment(mech_background_repair, 2);
	TextDrawColor(mech_background_repair, -1);
	TextDrawSetShadow(mech_background_repair, 0);
	TextDrawSetOutline(mech_background_repair, 0);
	TextDrawFont(mech_background_repair, 4);


	return true;
}

stock create_notify_p(playerid)
{

	if(notify_player_all[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		notify_player_all[0][playerid] = CreatePlayerTextDraw(playerid, 260.666656, 282.488922, "brilliantother:notify_player_38"); // Texture element
		PlayerTextDrawLetterSize(playerid, notify_player_all[0][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, notify_player_all[0][playerid], 121.999984, 38.162937);
		PlayerTextDrawAlignment(playerid, notify_player_all[0][playerid], 2);
		PlayerTextDrawColor(playerid, notify_player_all[0][playerid], -1);
		PlayerTextDrawSetShadow(playerid, notify_player_all[0][playerid], 0);
		PlayerTextDrawSetOutline(playerid, notify_player_all[0][playerid], 0);
		PlayerTextDrawFont(playerid, notify_player_all[0][playerid], 4);
	}
	if(notify_player_all[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		notify_player_all[1][playerid] = CreatePlayerTextDraw(playerid, 490.666717, 189.155639, "brilliantother:notify_player_25"); // Texture element
		PlayerTextDrawLetterSize(playerid, notify_player_all[1][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, notify_player_all[1][playerid], 121.999984, 38.162937);
		PlayerTextDrawAlignment(playerid, notify_player_all[1][playerid], 2);
		PlayerTextDrawColor(playerid, notify_player_all[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, notify_player_all[1][playerid], 0);
		PlayerTextDrawSetOutline(playerid, notify_player_all[1][playerid], 0);
		PlayerTextDrawFont(playerid, notify_player_all[1][playerid], 4);
	}


	return true;
}

stock create_quest_p(playerid)
{
	if(quest_panel_general_p[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		quest_panel_general_p[0][playerid] = CreatePlayerTextDraw(playerid, 119.333389, 91.674057, "brp_quest:quest_background_2"); // Texture element
		PlayerTextDrawLetterSize(playerid, quest_panel_general_p[0][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, quest_panel_general_p[0][playerid], 386.000244, 312.355712);
		PlayerTextDrawAlignment(playerid, quest_panel_general_p[0][playerid], 2);
		PlayerTextDrawColor(playerid, quest_panel_general_p[0][playerid], -1);
		PlayerTextDrawSetShadow(playerid, quest_panel_general_p[0][playerid], 0);
		PlayerTextDrawSetOutline(playerid, quest_panel_general_p[0][playerid], 0);
		PlayerTextDrawFont(playerid, quest_panel_general_p[0][playerid], 4);
	}
	if(quest_panel_general_p[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{	
		quest_panel_general_p[1][playerid] = CreatePlayerTextDraw(playerid, 131.333343, 139.377761, "brp_quest:quest_button_quest"); // Texture element
		PlayerTextDrawLetterSize(playerid, quest_panel_general_p[1][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, quest_panel_general_p[1][playerid], 73.333312, 32.355564);
		PlayerTextDrawAlignment(playerid, quest_panel_general_p[1][playerid], 2);
		PlayerTextDrawColor(playerid, quest_panel_general_p[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, quest_panel_general_p[1][playerid], 0);
		PlayerTextDrawSetOutline(playerid, quest_panel_general_p[1][playerid], 0);
		PlayerTextDrawFont(playerid, quest_panel_general_p[1][playerid], 4);
	}
	if(quest_panel_general_p[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{	
		quest_panel_general_p[2][playerid] = CreatePlayerTextDraw(playerid, 210.666625, 139.792556, "brp_quest:quest_button_other_quest"); // Texture element
		PlayerTextDrawLetterSize(playerid, quest_panel_general_p[2][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, quest_panel_general_p[2][playerid], 0.0, 0.0);
		PlayerTextDrawAlignment(playerid, quest_panel_general_p[2][playerid], 2);
		PlayerTextDrawColor(playerid, quest_panel_general_p[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, quest_panel_general_p[2][playerid], 0);
		PlayerTextDrawSetOutline(playerid, quest_panel_general_p[2][playerid], 0);
		PlayerTextDrawFont(playerid, quest_panel_general_p[2][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, quest_panel_general_p[2][playerid], true);
	}
	if(quest_panel_general_p[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{	
		quest_panel_general_p[3][playerid] = CreatePlayerTextDraw(playerid, 480.666656, 99.140747, "brp_quest:quest_button_close"); // Texture element
		PlayerTextDrawLetterSize(playerid, quest_panel_general_p[3][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, quest_panel_general_p[3][playerid], 15.999974, 18.666677);
		PlayerTextDrawAlignment(playerid, quest_panel_general_p[3][playerid], 2);
		PlayerTextDrawColor(playerid, quest_panel_general_p[3][playerid], -1);
		PlayerTextDrawSetShadow(playerid, quest_panel_general_p[3][playerid], 0);
		PlayerTextDrawSetOutline(playerid, quest_panel_general_p[3][playerid], 0);
		PlayerTextDrawFont(playerid, quest_panel_general_p[3][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, quest_panel_general_p[3][playerid], true);
	}
	if(quest_panel_general_p[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{	
		quest_panel_general_p[4][playerid] = CreatePlayerTextDraw(playerid, 131.666702, 182.518478, "brp_quest:quest_button_1_select"); // Texture element
		PlayerTextDrawLetterSize(playerid, quest_panel_general_p[4][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, quest_panel_general_p[4][playerid], 152.333358, 33.185199);
		PlayerTextDrawAlignment(playerid, quest_panel_general_p[4][playerid], 2);
		PlayerTextDrawColor(playerid, quest_panel_general_p[4][playerid], -1);
		PlayerTextDrawSetShadow(playerid, quest_panel_general_p[4][playerid], 0);
		PlayerTextDrawSetOutline(playerid, quest_panel_general_p[4][playerid], 0);
		PlayerTextDrawFont(playerid, quest_panel_general_p[4][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, quest_panel_general_p[4][playerid], true);
	}
	if(quest_panel_general_p[5][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{	
		quest_panel_general_p[5][playerid] = CreatePlayerTextDraw(playerid, 132.000045, 221.096282, "brp_quest:quest_button_2_no_select"); // Texture element
		PlayerTextDrawLetterSize(playerid, quest_panel_general_p[5][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, quest_panel_general_p[5][playerid], 152.333358, 33.185199);
		PlayerTextDrawAlignment(playerid, quest_panel_general_p[5][playerid], 2);
		PlayerTextDrawColor(playerid, quest_panel_general_p[5][playerid], -1);
		PlayerTextDrawSetShadow(playerid, quest_panel_general_p[5][playerid], 0);
		PlayerTextDrawSetOutline(playerid, quest_panel_general_p[5][playerid], 0);
		PlayerTextDrawFont(playerid, quest_panel_general_p[5][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, quest_panel_general_p[5][playerid], true);
	}
	if(quest_panel_general_p[6][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{	
		quest_panel_general_p[6][playerid] = CreatePlayerTextDraw(playerid, 131.666702, 259.259155, "brp_quest:quest_button_1_select"); // Texture element
		PlayerTextDrawLetterSize(playerid, quest_panel_general_p[6][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, quest_panel_general_p[6][playerid], 152.333358, 33.185199);
		PlayerTextDrawAlignment(playerid, quest_panel_general_p[6][playerid], 2);
		PlayerTextDrawColor(playerid, quest_panel_general_p[6][playerid], -1);
		PlayerTextDrawSetShadow(playerid, quest_panel_general_p[6][playerid], 0);
		PlayerTextDrawSetOutline(playerid, quest_panel_general_p[6][playerid], 0);
		PlayerTextDrawFont(playerid, quest_panel_general_p[6][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, quest_panel_general_p[6][playerid], true);
	}
	if(quest_panel_general_p[7][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{	
		quest_panel_general_p[7][playerid] = CreatePlayerTextDraw(playerid, 132.000030, 298.251953, "brp_quest:quest_button_1_select"); // Texture element
		PlayerTextDrawLetterSize(playerid, quest_panel_general_p[7][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, quest_panel_general_p[7][playerid], 152.333358, 33.185199);
		PlayerTextDrawAlignment(playerid, quest_panel_general_p[7][playerid], 2);
		PlayerTextDrawColor(playerid, quest_panel_general_p[7][playerid], -1);
		PlayerTextDrawSetShadow(playerid, quest_panel_general_p[7][playerid], 0);
		PlayerTextDrawSetOutline(playerid, quest_panel_general_p[7][playerid], 0);
		PlayerTextDrawFont(playerid, quest_panel_general_p[7][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, quest_panel_general_p[7][playerid], true);
	}
	if(quest_panel_general_p[8][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{	
		quest_panel_general_p[8][playerid] = CreatePlayerTextDraw(playerid, 133.999969, 337.659210, "brp_quest:quest_button_prew"); // Texture element
		PlayerTextDrawLetterSize(playerid, quest_panel_general_p[8][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, quest_panel_general_p[8][playerid], 43.999996, 28.622219);
		PlayerTextDrawAlignment(playerid, quest_panel_general_p[8][playerid], 2);
		PlayerTextDrawColor(playerid, quest_panel_general_p[8][playerid], -1);
		PlayerTextDrawSetShadow(playerid, quest_panel_general_p[8][playerid], 0);
		PlayerTextDrawSetOutline(playerid, quest_panel_general_p[8][playerid], 0);
		PlayerTextDrawFont(playerid, quest_panel_general_p[8][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, quest_panel_general_p[8][playerid], true);
	}
	if(quest_panel_general_p[9][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{	
		quest_panel_general_p[9][playerid] = CreatePlayerTextDraw(playerid, 239.666687, 337.659149, "brp_quest:quest_button_next"); // Texture element
		PlayerTextDrawLetterSize(playerid, quest_panel_general_p[9][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, quest_panel_general_p[9][playerid], 43.999996, 28.622219);
		PlayerTextDrawAlignment(playerid, quest_panel_general_p[9][playerid], 2);
		PlayerTextDrawColor(playerid, quest_panel_general_p[9][playerid], -1);
		PlayerTextDrawSetShadow(playerid, quest_panel_general_p[9][playerid], 0);
		PlayerTextDrawSetOutline(playerid, quest_panel_general_p[9][playerid], 0);
		PlayerTextDrawFont(playerid, quest_panel_general_p[9][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, quest_panel_general_p[9][playerid], true);
	}
	if(quest_panel_general_p[10][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{	
		quest_panel_general_p[10][playerid] = CreatePlayerTextDraw(playerid, 406.333251, 317.333221, "brp_quest:quest_button_start"); // Texture element
		PlayerTextDrawLetterSize(playerid, quest_panel_general_p[10][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, quest_panel_general_p[10][playerid], 97.333335, 70.933319);
		PlayerTextDrawAlignment(playerid, quest_panel_general_p[10][playerid], 2);
		PlayerTextDrawColor(playerid, quest_panel_general_p[10][playerid], -1);
		PlayerTextDrawSetShadow(playerid, quest_panel_general_p[10][playerid], 0);
		PlayerTextDrawSetOutline(playerid, quest_panel_general_p[10][playerid], 0);
		PlayerTextDrawFont(playerid, quest_panel_general_p[10][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, quest_panel_general_p[10][playerid], true);
	}
	if(quest_panel_general_p[11][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{	
		quest_panel_general_p[11][playerid] = CreatePlayerTextDraw(playerid, 342.333312, 348.029724, "1_EXP_3500_RUB"); // Text element
		PlayerTextDrawLetterSize(playerid, quest_panel_general_p[11][playerid], 0.215999, 1.380148);
		PlayerTextDrawAlignment(playerid, quest_panel_general_p[11][playerid], 2);
		PlayerTextDrawColor(playerid, quest_panel_general_p[11][playerid], 618805247);
		PlayerTextDrawSetShadow(playerid, quest_panel_general_p[11][playerid], 0);
		PlayerTextDrawSetOutline(playerid, quest_panel_general_p[11][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, quest_panel_general_p[11][playerid], 51);
		PlayerTextDrawFont(playerid, quest_panel_general_p[11][playerid], 2);
		PlayerTextDrawSetProportional(playerid, quest_panel_general_p[11][playerid], 1);
	}
	if(quest_panel_general_p[12][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{	
		quest_panel_general_p[12][playerid] = CreatePlayerTextDraw(playerid, 208.666580, 344.711120, "1/5"); // Text element
		PlayerTextDrawLetterSize(playerid, quest_panel_general_p[12][playerid], 0.249332, 1.529481);
		PlayerTextDrawAlignment(playerid, quest_panel_general_p[12][playerid], 2);
		PlayerTextDrawColor(playerid, quest_panel_general_p[12][playerid], -1);
		PlayerTextDrawSetShadow(playerid, quest_panel_general_p[12][playerid], 0);
		PlayerTextDrawSetOutline(playerid, quest_panel_general_p[12][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, quest_panel_general_p[12][playerid], 51);
		PlayerTextDrawFont(playerid, quest_panel_general_p[12][playerid], 2);
		PlayerTextDrawSetProportional(playerid, quest_panel_general_p[12][playerid], 1);

	}

	return true;
}

stock create_casino_panel_p(playerid) 
{

	if(casino_general_p[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		casino_general_p[0][playerid] = CreatePlayerTextDraw(playerid, 397.333343, 97.481521, "brilliantother:casino_background"); // Texture element
		PlayerTextDrawLetterSize(playerid, casino_general_p[0][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, casino_general_p[0][playerid], 192.333221, 296.177856);
		PlayerTextDrawAlignment(playerid, casino_general_p[0][playerid], 2);
		PlayerTextDrawColor(playerid, casino_general_p[0][playerid], -1);
		PlayerTextDrawSetShadow(playerid, casino_general_p[0][playerid], 0);
		PlayerTextDrawSetOutline(playerid, casino_general_p[0][playerid], 0);
		PlayerTextDrawFont(playerid, casino_general_p[0][playerid], 4);
	}
	if(casino_general_p[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		casino_general_p[1][playerid] = CreatePlayerTextDraw(playerid, 475.333343, 187.911148, "CHRISTIAN~n~BAGWELL"); // Text element
		PlayerTextDrawLetterSize(playerid, casino_general_p[1][playerid], 0.221332, 1.280593);
		PlayerTextDrawAlignment(playerid, casino_general_p[1][playerid], 2);
		PlayerTextDrawColor(playerid, casino_general_p[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, casino_general_p[1][playerid], 0);
		PlayerTextDrawSetOutline(playerid, casino_general_p[1][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, casino_general_p[1][playerid], 51);
		PlayerTextDrawFont(playerid, casino_general_p[1][playerid], 2);
		PlayerTextDrawSetProportional(playerid, casino_general_p[1][playerid], 1);
	}
	if(casino_general_p[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		casino_general_p[2][playerid] = CreatePlayerTextDraw(playerid, 544.000000, 187.911132, "CHRISTIAN~n~BAGWELL"); // Text element
		PlayerTextDrawLetterSize(playerid, casino_general_p[2][playerid], 0.221332, 1.280593);
		PlayerTextDrawAlignment(playerid, casino_general_p[2][playerid], 2);
		PlayerTextDrawColor(playerid, casino_general_p[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, casino_general_p[2][playerid], 0);
		PlayerTextDrawSetOutline(playerid, casino_general_p[2][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, casino_general_p[2][playerid], 51);
		PlayerTextDrawFont(playerid, casino_general_p[2][playerid], 2);
		PlayerTextDrawSetProportional(playerid, casino_general_p[2][playerid], 1);
	}
	if(casino_general_p[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		casino_general_p[3][playerid] = CreatePlayerTextDraw(playerid, 476.333374, 221.925994, "CHRISTIAN~n~BAGWELL"); // Text element
		PlayerTextDrawLetterSize(playerid, casino_general_p[3][playerid], 0.221332, 1.280593);
		PlayerTextDrawAlignment(playerid, casino_general_p[3][playerid], 2);
		PlayerTextDrawColor(playerid, casino_general_p[3][playerid], -1);
		PlayerTextDrawSetShadow(playerid, casino_general_p[3][playerid], 0);
		PlayerTextDrawSetOutline(playerid, casino_general_p[3][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, casino_general_p[3][playerid], 51);
		PlayerTextDrawFont(playerid, casino_general_p[3][playerid], 2);
		PlayerTextDrawSetProportional(playerid, casino_general_p[3][playerid], 1);
	}
	if(casino_general_p[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		casino_general_p[4][playerid] = CreatePlayerTextDraw(playerid, 544.000061, 222.340805, "CHRISTIAN~n~BAGWELL"); // Text element
		PlayerTextDrawLetterSize(playerid, casino_general_p[4][playerid], 0.221332, 1.280593);
		PlayerTextDrawAlignment(playerid, casino_general_p[4][playerid], 2);
		PlayerTextDrawColor(playerid, casino_general_p[4][playerid], -1);
		PlayerTextDrawSetShadow(playerid, casino_general_p[4][playerid], 0);
		PlayerTextDrawSetOutline(playerid, casino_general_p[4][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, casino_general_p[4][playerid], 51);
		PlayerTextDrawFont(playerid, casino_general_p[4][playerid], 2);
		PlayerTextDrawSetProportional(playerid, casino_general_p[4][playerid], 1);
	}
	if(casino_general_p[5][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		casino_general_p[5][playerid] = CreatePlayerTextDraw(playerid, 430.333343, 306.963043, "brilliantother:casino_button_bet"); // Texture element
		PlayerTextDrawLetterSize(playerid, casino_general_p[5][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, casino_general_p[5][playerid], 64.000030, 63.881450);
		PlayerTextDrawAlignment(playerid, casino_general_p[5][playerid], 2);
		PlayerTextDrawColor(playerid, casino_general_p[5][playerid], -1);
		PlayerTextDrawSetShadow(playerid, casino_general_p[5][playerid], 0);
		PlayerTextDrawSetOutline(playerid, casino_general_p[5][playerid], 0);
		PlayerTextDrawFont(playerid, casino_general_p[5][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, casino_general_p[5][playerid], true);
	}
	if(casino_general_p[6][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		casino_general_p[6][playerid] = CreatePlayerTextDraw(playerid, 505.666717, 306.963043, "brilliantother:casino_button_close"); // Texture element
		PlayerTextDrawLetterSize(playerid, casino_general_p[6][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, casino_general_p[6][playerid], 64.000030, 63.881450);
		PlayerTextDrawAlignment(playerid, casino_general_p[6][playerid], 2);
		PlayerTextDrawColor(playerid, casino_general_p[6][playerid], -1);
		PlayerTextDrawSetShadow(playerid, casino_general_p[6][playerid], 0);
		PlayerTextDrawSetOutline(playerid, casino_general_p[6][playerid], 0);
		PlayerTextDrawFont(playerid, casino_general_p[6][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, casino_general_p[6][playerid], true);
	}
	if(casino_general_p[7][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		casino_general_p[7][playerid] = CreatePlayerTextDraw(playerid, 474.000030, 275.851776, "150000000_RUB"); // Text element
		PlayerTextDrawLetterSize(playerid, casino_general_p[7][playerid], 0.264333, 1.566813);
		PlayerTextDrawAlignment(playerid, casino_general_p[7][playerid], 2);
		PlayerTextDrawColor(playerid, casino_general_p[7][playerid], -1);
		PlayerTextDrawSetShadow(playerid, casino_general_p[7][playerid], -1);
		PlayerTextDrawSetOutline(playerid, casino_general_p[7][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, casino_general_p[7][playerid], 51);
		PlayerTextDrawFont(playerid, casino_general_p[7][playerid], 2);
		PlayerTextDrawSetProportional(playerid, casino_general_p[7][playerid], 1);
	}
	if(casino_general_p[8][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		casino_general_p[8][playerid] = CreatePlayerTextDraw(playerid, 577.666564, 86.696266, "brilliantother:inventory_close"); // Texture element
		PlayerTextDrawLetterSize(playerid, casino_general_p[8][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, casino_general_p[8][playerid], 18.000000, 20.740737);
		PlayerTextDrawAlignment(playerid, casino_general_p[8][playerid], 2);
		PlayerTextDrawColor(playerid, casino_general_p[8][playerid], -1);
		PlayerTextDrawSetShadow(playerid, casino_general_p[8][playerid], 0);
		PlayerTextDrawSetOutline(playerid, casino_general_p[8][playerid], 0);
		PlayerTextDrawFont(playerid, casino_general_p[8][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, casino_general_p[8][playerid], true);
	}
	return true;
}

stock create_hud_element()
{
	hud_elements[0] = TextDrawCreate(482.450500, 26.400001, "brilliantother:golod");
	TextDrawTextSize(hud_elements[0], 98.179924, 16.180000);
	TextDrawAlignment(hud_elements[0], 1);
	TextDrawColor(hud_elements[0], -1);
	TextDrawBackgroundColor(hud_elements[0], 255);
	TextDrawFont(hud_elements[0], 4);
	TextDrawSetProportional(hud_elements[0], 0);

	hud_elements[1] = TextDrawCreate(482.450500, 59.100025, "brilliantother:heal");
	TextDrawTextSize(hud_elements[1], 98.179924, 16.180000);
	TextDrawAlignment(hud_elements[1], 1);
	TextDrawColor(hud_elements[1], -1);
	TextDrawBackgroundColor(hud_elements[1], 255);
	TextDrawFont(hud_elements[1], 4);
	TextDrawSetProportional(hud_elements[1], 0);

	hud_elements[2] = TextDrawCreate(482.450500, 74.699790, "brilliantother:armour");
	TextDrawTextSize(hud_elements[2], 98.179924, 16.180000);
	TextDrawAlignment(hud_elements[2], 1);
	TextDrawColor(hud_elements[2], -1);
	TextDrawBackgroundColor(hud_elements[2], 255);
	TextDrawFont(hud_elements[2], 4);
	TextDrawSetProportional(hud_elements[2], 0);

	return true;
}

stock create_ammo_menu_biz_p(playerid)
{
	if(ammo_panel_menu_biz[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		ammo_panel_menu_biz[0][playerid] = CreatePlayerTextDraw(playerid, -2.000000, -0.414814, "brilliantother:weapon_menu_background_4"); // Texture element
		PlayerTextDrawLetterSize(playerid, ammo_panel_menu_biz[0][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ammo_panel_menu_biz[0][playerid], 643.666564, 448.000000);
		PlayerTextDrawAlignment(playerid, ammo_panel_menu_biz[0][playerid], 2);
		PlayerTextDrawColor(playerid, ammo_panel_menu_biz[0][playerid], -1);
		PlayerTextDrawSetShadow(playerid, ammo_panel_menu_biz[0][playerid], 0);
		PlayerTextDrawSetOutline(playerid, ammo_panel_menu_biz[0][playerid], 0);
		PlayerTextDrawFont(playerid, ammo_panel_menu_biz[0][playerid], 4);
	}
	if(ammo_panel_menu_biz[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		ammo_panel_menu_biz[1][playerid] = CreatePlayerTextDraw(playerid, 57.666667, 77.985183, "brilliantother:weapon_menu_bita"); // Texture element
		PlayerTextDrawLetterSize(playerid, ammo_panel_menu_biz[1][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ammo_panel_menu_biz[1][playerid], 59.000003, 77.155563);
		PlayerTextDrawAlignment(playerid, ammo_panel_menu_biz[1][playerid], 2);
		PlayerTextDrawColor(playerid, ammo_panel_menu_biz[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, ammo_panel_menu_biz[1][playerid], 0);
		PlayerTextDrawSetOutline(playerid, ammo_panel_menu_biz[1][playerid], 0);
		PlayerTextDrawFont(playerid, ammo_panel_menu_biz[1][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, ammo_panel_menu_biz[1][playerid], true);
	}
	if(ammo_panel_menu_biz[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		ammo_panel_menu_biz[2][playerid] = CreatePlayerTextDraw(playerid, 124.333328, 78.400001, "brilliantother:weapon_menu_bita"); // Texture element
		PlayerTextDrawLetterSize(playerid, ammo_panel_menu_biz[2][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ammo_panel_menu_biz[2][playerid], 59.000003, 77.155563);
		PlayerTextDrawAlignment(playerid, ammo_panel_menu_biz[2][playerid], 2);
		PlayerTextDrawColor(playerid, ammo_panel_menu_biz[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, ammo_panel_menu_biz[2][playerid], 0);
		PlayerTextDrawSetOutline(playerid, ammo_panel_menu_biz[2][playerid], 0);
		PlayerTextDrawFont(playerid, ammo_panel_menu_biz[2][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, ammo_panel_menu_biz[2][playerid], true);
	}
	if(ammo_panel_menu_biz[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		ammo_panel_menu_biz[3][playerid] = CreatePlayerTextDraw(playerid, 190.666641, 78.400016, "brilliantother:weapon_menu_bita"); // Texture element
		PlayerTextDrawLetterSize(playerid, ammo_panel_menu_biz[3][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ammo_panel_menu_biz[3][playerid], 59.000003, 77.155563);
		PlayerTextDrawAlignment(playerid, ammo_panel_menu_biz[3][playerid], 2);
		PlayerTextDrawColor(playerid, ammo_panel_menu_biz[3][playerid], -1);
		PlayerTextDrawSetShadow(playerid, ammo_panel_menu_biz[3][playerid], 0);
		PlayerTextDrawSetOutline(playerid, ammo_panel_menu_biz[3][playerid], 0);
		PlayerTextDrawFont(playerid, ammo_panel_menu_biz[3][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, ammo_panel_menu_biz[3][playerid], true);
	}
	if(ammo_panel_menu_biz[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		ammo_panel_menu_biz[4][playerid] = CreatePlayerTextDraw(playerid, 259.000061, 78.400016, "brilliantother:weapon_menu_bita"); // Texture element
		PlayerTextDrawLetterSize(playerid, ammo_panel_menu_biz[4][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ammo_panel_menu_biz[4][playerid], 59.000003, 77.155563);
		PlayerTextDrawAlignment(playerid, ammo_panel_menu_biz[4][playerid], 2);
		PlayerTextDrawColor(playerid, ammo_panel_menu_biz[4][playerid], -1);
		PlayerTextDrawSetShadow(playerid, ammo_panel_menu_biz[4][playerid], 0);
		PlayerTextDrawSetOutline(playerid, ammo_panel_menu_biz[4][playerid], 0);
		PlayerTextDrawFont(playerid, ammo_panel_menu_biz[4][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, ammo_panel_menu_biz[4][playerid], true);
	}
	if(ammo_panel_menu_biz[5][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		ammo_panel_menu_biz[5][playerid] = CreatePlayerTextDraw(playerid, 366.333343, 77.570365, "brilliantother:weapon_menu_select_ak47"); // Texture element
		PlayerTextDrawLetterSize(playerid, ammo_panel_menu_biz[5][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ammo_panel_menu_biz[5][playerid], 187.666824, 248.888885);
		PlayerTextDrawAlignment(playerid, ammo_panel_menu_biz[5][playerid], 2);
		PlayerTextDrawColor(playerid, ammo_panel_menu_biz[5][playerid], -1);
		PlayerTextDrawSetShadow(playerid, ammo_panel_menu_biz[5][playerid], 0);
		PlayerTextDrawSetOutline(playerid, ammo_panel_menu_biz[5][playerid], 0);
		PlayerTextDrawFont(playerid, ammo_panel_menu_biz[5][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, ammo_panel_menu_biz[5][playerid], true);
	}
	
	ammo_panel_menu_biz[6][playerid] = CreatePlayerTextDraw(playerid, 414.666595, 274.607391, "brilliantother:weapon_buy_button"); // Texture element
	PlayerTextDrawLetterSize(playerid, ammo_panel_menu_biz[6][playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, ammo_panel_menu_biz[6][playerid], 96.0000007, 55.585189);
	PlayerTextDrawAlignment(playerid, ammo_panel_menu_biz[6][playerid], 2);
	PlayerTextDrawColor(playerid, ammo_panel_menu_biz[6][playerid], -1);
	PlayerTextDrawSetShadow(playerid, ammo_panel_menu_biz[6][playerid], 0);
	PlayerTextDrawSetOutline(playerid, ammo_panel_menu_biz[6][playerid], 0);
	PlayerTextDrawFont(playerid, ammo_panel_menu_biz[6][playerid], 4);
	PlayerTextDrawSetSelectable(playerid, ammo_panel_menu_biz[6][playerid], true);
		
	if(ammo_panel_menu_biz[7][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		ammo_panel_menu_biz[7][playerid] = CreatePlayerTextDraw(playerid, 57.999961, 163.851882, "brilliantother:weapon_menu_bita"); // Texture element
		PlayerTextDrawLetterSize(playerid, ammo_panel_menu_biz[7][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ammo_panel_menu_biz[7][playerid], 59.000003, 77.155563);
		PlayerTextDrawAlignment(playerid, ammo_panel_menu_biz[7][playerid], 2);
		PlayerTextDrawColor(playerid, ammo_panel_menu_biz[7][playerid], -1);
		PlayerTextDrawSetShadow(playerid, ammo_panel_menu_biz[7][playerid], 0);
		PlayerTextDrawSetOutline(playerid, ammo_panel_menu_biz[7][playerid], 0);
		PlayerTextDrawFont(playerid, ammo_panel_menu_biz[7][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, ammo_panel_menu_biz[7][playerid], true);
	}
	if(ammo_panel_menu_biz[8][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		ammo_panel_menu_biz[8][playerid] = CreatePlayerTextDraw(playerid, 123.999977, 163.022262, "brilliantother:weapon_menu_bita"); // Texture element
		PlayerTextDrawLetterSize(playerid, ammo_panel_menu_biz[8][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ammo_panel_menu_biz[8][playerid], 59.000003, 77.155563);
		PlayerTextDrawAlignment(playerid, ammo_panel_menu_biz[8][playerid], 2);
		PlayerTextDrawColor(playerid, ammo_panel_menu_biz[8][playerid], -1);
		PlayerTextDrawSetShadow(playerid, ammo_panel_menu_biz[8][playerid], 0);
		PlayerTextDrawSetOutline(playerid, ammo_panel_menu_biz[8][playerid], 0);
		PlayerTextDrawFont(playerid, ammo_panel_menu_biz[8][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, ammo_panel_menu_biz[8][playerid], true);
	}
	if(ammo_panel_menu_biz[9][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		ammo_panel_menu_biz[9][playerid] = CreatePlayerTextDraw(playerid, 190.999984, 162.607452, "brilliantother:weapon_menu_bita"); // Texture element
		PlayerTextDrawLetterSize(playerid, ammo_panel_menu_biz[9][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ammo_panel_menu_biz[9][playerid], 59.000003, 77.155563);
		PlayerTextDrawAlignment(playerid, ammo_panel_menu_biz[9][playerid], 2);
		PlayerTextDrawColor(playerid, ammo_panel_menu_biz[9][playerid], -1);
		PlayerTextDrawSetShadow(playerid, ammo_panel_menu_biz[9][playerid], 0);
		PlayerTextDrawSetOutline(playerid, ammo_panel_menu_biz[9][playerid], 0);
		PlayerTextDrawFont(playerid, ammo_panel_menu_biz[9][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, ammo_panel_menu_biz[9][playerid], true);
	}
	if(ammo_panel_menu_biz[10][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		ammo_panel_menu_biz[10][playerid] = CreatePlayerTextDraw(playerid, 258.666625, 162.192642, "brilliantother:weapon_menu_bita"); // Texture element
		PlayerTextDrawLetterSize(playerid, ammo_panel_menu_biz[10][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ammo_panel_menu_biz[10][playerid], 59.000003, 77.155563);
		PlayerTextDrawAlignment(playerid, ammo_panel_menu_biz[10][playerid], 2);
		PlayerTextDrawColor(playerid, ammo_panel_menu_biz[10][playerid], -1);
		PlayerTextDrawSetShadow(playerid, ammo_panel_menu_biz[10][playerid], 0);
		PlayerTextDrawSetOutline(playerid, ammo_panel_menu_biz[10][playerid], 0);
		PlayerTextDrawFont(playerid, ammo_panel_menu_biz[10][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, ammo_panel_menu_biz[10][playerid], true);
	}
	if(ammo_panel_menu_biz[11][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		ammo_panel_menu_biz[11][playerid] = CreatePlayerTextDraw(playerid, 57.999977, 249.303771, "brilliantother:weapon_menu_bita"); // Texture element
		PlayerTextDrawLetterSize(playerid, ammo_panel_menu_biz[11][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ammo_panel_menu_biz[11][playerid], 59.000003, 77.155563);
		PlayerTextDrawAlignment(playerid, ammo_panel_menu_biz[11][playerid], 2);
		PlayerTextDrawColor(playerid, ammo_panel_menu_biz[11][playerid], -1);
		PlayerTextDrawSetShadow(playerid, ammo_panel_menu_biz[11][playerid], 0);
		PlayerTextDrawSetOutline(playerid, ammo_panel_menu_biz[11][playerid], 0);
		PlayerTextDrawFont(playerid, ammo_panel_menu_biz[11][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, ammo_panel_menu_biz[11][playerid], true);
	}
	if(ammo_panel_menu_biz[12][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		ammo_panel_menu_biz[12][playerid] = CreatePlayerTextDraw(playerid, 124.000007, 248.888961, "brilliantother:weapon_menu_bita"); // Texture element
		PlayerTextDrawLetterSize(playerid, ammo_panel_menu_biz[12][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ammo_panel_menu_biz[12][playerid], 59.000003, 77.155563);
		PlayerTextDrawAlignment(playerid, ammo_panel_menu_biz[12][playerid], 2);
		PlayerTextDrawColor(playerid, ammo_panel_menu_biz[12][playerid], -1);
		PlayerTextDrawSetShadow(playerid, ammo_panel_menu_biz[12][playerid], 0);
		PlayerTextDrawSetOutline(playerid, ammo_panel_menu_biz[12][playerid], 0);
		PlayerTextDrawFont(playerid, ammo_panel_menu_biz[12][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, ammo_panel_menu_biz[12][playerid], true);
	}
	if(ammo_panel_menu_biz[13][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		ammo_panel_menu_biz[13][playerid] = CreatePlayerTextDraw(playerid, 191.333374, 248.474151, "brilliantother:weapon_menu_bita"); // Texture element
		PlayerTextDrawLetterSize(playerid, ammo_panel_menu_biz[13][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ammo_panel_menu_biz[13][playerid], 59.000003, 77.155563);
		PlayerTextDrawAlignment(playerid, ammo_panel_menu_biz[13][playerid], 2);
		PlayerTextDrawColor(playerid, ammo_panel_menu_biz[13][playerid], -1);
		PlayerTextDrawSetShadow(playerid, ammo_panel_menu_biz[13][playerid], 0);
		PlayerTextDrawSetOutline(playerid, ammo_panel_menu_biz[13][playerid], 0);
		PlayerTextDrawFont(playerid, ammo_panel_menu_biz[13][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, ammo_panel_menu_biz[13][playerid], true);
	}
	if(ammo_panel_menu_biz[14][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		ammo_panel_menu_biz[14][playerid] = CreatePlayerTextDraw(playerid, 259.666809, 248.059326, "brilliantother:weapon_menu_bita"); // Texture element
		PlayerTextDrawLetterSize(playerid, ammo_panel_menu_biz[14][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ammo_panel_menu_biz[14][playerid], 59.000003, 77.155563);
		PlayerTextDrawAlignment(playerid, ammo_panel_menu_biz[14][playerid], 2);
		PlayerTextDrawColor(playerid, ammo_panel_menu_biz[14][playerid], -1);
		PlayerTextDrawSetShadow(playerid, ammo_panel_menu_biz[14][playerid], 0);
		PlayerTextDrawSetOutline(playerid, ammo_panel_menu_biz[14][playerid], 0);
		PlayerTextDrawFont(playerid, ammo_panel_menu_biz[14][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, ammo_panel_menu_biz[14][playerid], true);
	}
	if(ammo_panel_menu_biz[15][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		ammo_panel_menu_biz[15][playerid] = CreatePlayerTextDraw(playerid, 574.333374, 21.570369, "brilliantother:close_button_big"); // Texture element
		PlayerTextDrawLetterSize(playerid, ammo_panel_menu_biz[15][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ammo_panel_menu_biz[15][playerid], 50.666664, 61.392578);
		PlayerTextDrawAlignment(playerid, ammo_panel_menu_biz[15][playerid], 2);
		PlayerTextDrawColor(playerid, ammo_panel_menu_biz[15][playerid], -1);
		PlayerTextDrawSetShadow(playerid, ammo_panel_menu_biz[15][playerid], 0);
		PlayerTextDrawSetOutline(playerid, ammo_panel_menu_biz[15][playerid], 0);
		PlayerTextDrawFont(playerid, ammo_panel_menu_biz[15][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, ammo_panel_menu_biz[15][playerid], true);
	}
	if(ammo_panel_menu_biz[16][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		ammo_panel_menu_biz[16][playerid] = CreatePlayerTextDraw(playerid, 59.333332, 47.703701, "brilliantother:weapon_menu_ammo_icon"); // Texture element
		PlayerTextDrawLetterSize(playerid, ammo_panel_menu_biz[16][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ammo_panel_menu_biz[16][playerid], 14.000008, 18.666673);
		PlayerTextDrawAlignment(playerid, ammo_panel_menu_biz[16][playerid], 2);
		PlayerTextDrawColor(playerid, ammo_panel_menu_biz[16][playerid], -1);
		PlayerTextDrawSetShadow(playerid, ammo_panel_menu_biz[16][playerid], 0);
		PlayerTextDrawSetOutline(playerid, ammo_panel_menu_biz[16][playerid], 0);
		PlayerTextDrawFont(playerid, ammo_panel_menu_biz[16][playerid], 4);
	}
	if(ammo_panel_menu_biz[17][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		ammo_panel_menu_biz[17][playerid] = CreatePlayerTextDraw(playerid, 77.333328, 52.681480, "brilliantother:weapon_menu_text_icon_2"); // Texture element
		PlayerTextDrawLetterSize(playerid, ammo_panel_menu_biz[17][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, ammo_panel_menu_biz[17][playerid], 70.999977, 12.859258);
		PlayerTextDrawAlignment(playerid, ammo_panel_menu_biz[17][playerid], 2);
		PlayerTextDrawColor(playerid, ammo_panel_menu_biz[17][playerid], -1);
		PlayerTextDrawSetShadow(playerid, ammo_panel_menu_biz[17][playerid], 0);
		PlayerTextDrawSetOutline(playerid, ammo_panel_menu_biz[17][playerid], 0);
		PlayerTextDrawFont(playerid, ammo_panel_menu_biz[17][playerid], 4);
	}
	if(ammo_panel_menu_biz[18][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		ammo_panel_menu_biz[18][playerid] = CreatePlayerTextDraw(playerid, 459.666717, 226.903717, "M4A1"); // Text element
		PlayerTextDrawLetterSize(playerid, ammo_panel_menu_biz[18][playerid], 0.592999, 3.922963);
		PlayerTextDrawAlignment(playerid, ammo_panel_menu_biz[18][playerid], 2);
		PlayerTextDrawColor(playerid, ammo_panel_menu_biz[18][playerid], -1);
		PlayerTextDrawSetShadow(playerid, ammo_panel_menu_biz[18][playerid], 1);
		PlayerTextDrawSetOutline(playerid, ammo_panel_menu_biz[18][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, ammo_panel_menu_biz[18][playerid], 51);
		PlayerTextDrawFont(playerid, ammo_panel_menu_biz[18][playerid], 2);
		PlayerTextDrawSetProportional(playerid, ammo_panel_menu_biz[18][playerid], 1);
	}
	
	ammo_panel_menu_biz[19][playerid] = CreatePlayerTextDraw(playerid, 110.666595, 354.607391, "brilliantother:weapon_buy_button"); // Texture element
	PlayerTextDrawLetterSize(playerid, ammo_panel_menu_biz[19][playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, ammo_panel_menu_biz[19][playerid], 100.0000007, 57.585189);
	PlayerTextDrawAlignment(playerid, ammo_panel_menu_biz[19][playerid], 2);
	PlayerTextDrawColor(playerid, ammo_panel_menu_biz[19][playerid], -1);
	PlayerTextDrawSetShadow(playerid, ammo_panel_menu_biz[19][playerid], 0);
	PlayerTextDrawSetOutline(playerid, ammo_panel_menu_biz[19][playerid], 0);
	PlayerTextDrawFont(playerid, ammo_panel_menu_biz[19][playerid], 4);
	PlayerTextDrawSetSelectable(playerid, ammo_panel_menu_biz[19][playerid], true);
	
	return true;
}

stock create_hud_element_p(playerid)
{
	if(hud_elements_p[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		hud_elements_p[0][playerid] = CreatePlayerTextDraw(playerid, 509.599975, 29.500001, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, hud_elements_p[0][playerid], 57.310001, 9.790008);
		PlayerTextDrawAlignment(playerid, hud_elements_p[0][playerid], 1);
		PlayerTextDrawColor(playerid, hud_elements_p[0][playerid], -3721217);
		PlayerTextDrawBackgroundColor(playerid, hud_elements_p[0][playerid], 255);
		PlayerTextDrawFont(playerid, hud_elements_p[0][playerid], 4);
		PlayerTextDrawSetProportional(playerid, hud_elements_p[0][playerid], 0);
	}
	if(hud_elements_p[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		hud_elements_p[1][playerid] =  CreatePlayerTextDraw(playerid, 509.599975, 62.299983, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, hud_elements_p[1][playerid], 57.310001, 9.790008);
		PlayerTextDrawAlignment(playerid, hud_elements_p[1][playerid], 1);
		PlayerTextDrawColor(playerid, hud_elements_p[1][playerid], -13158401);
		PlayerTextDrawBackgroundColor(playerid, hud_elements_p[1][playerid], 255);
		PlayerTextDrawFont(playerid, hud_elements_p[1][playerid], 4);
		PlayerTextDrawSetProportional(playerid, hud_elements_p[1][playerid], 0);
	}
	if(hud_elements_p[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		hud_elements_p[2][playerid] = CreatePlayerTextDraw(playerid, 509.599975, 77.799964, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, hud_elements_p[2][playerid], 57.310001, 9.790008);
		PlayerTextDrawAlignment(playerid, hud_elements_p[2][playerid], 1);
		PlayerTextDrawColor(playerid, hud_elements_p[2][playerid], -1);
		PlayerTextDrawBackgroundColor(playerid, hud_elements_p[2][playerid], 255);
		PlayerTextDrawFont(playerid, hud_elements_p[2][playerid], 4);
		PlayerTextDrawSetProportional(playerid, hud_elements_p[2][playerid], 0);
	}
	return true;
}

stock create_charge_tesla_p(playerid)
{
	charge_tesla_panel_p[0][playerid] = CreatePlayerTextDraw(playerid, 169.666641, 129.422256, "brilliantother:tesla_charge_0"); // Texture element
	PlayerTextDrawLetterSize(playerid, charge_tesla_panel_p[0][playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, charge_tesla_panel_p[0][playerid], 286.666778, 223.585128);
	PlayerTextDrawAlignment(playerid, charge_tesla_panel_p[0][playerid], 2);
	PlayerTextDrawColor(playerid, charge_tesla_panel_p[0][playerid], -1);
	PlayerTextDrawSetShadow(playerid, charge_tesla_panel_p[0][playerid], 0);
	PlayerTextDrawSetOutline(playerid, charge_tesla_panel_p[0][playerid], 0);
	PlayerTextDrawFont(playerid, charge_tesla_panel_p[0][playerid], 4);

	charge_tesla_panel_p[1][playerid] = CreatePlayerTextDraw(playerid, 179.666671, 316.088897, "LD_SPAC:white"); // Texture element
	PlayerTextDrawLetterSize(playerid, charge_tesla_panel_p[1][playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, charge_tesla_panel_p[1][playerid], 0.0, 20.740722); // 0.999988 - ������� // 265.333312 - ��������
	PlayerTextDrawAlignment(playerid, charge_tesla_panel_p[1][playerid], 1);
	PlayerTextDrawColor(playerid, charge_tesla_panel_p[1][playerid], 1171199487);
	PlayerTextDrawSetShadow(playerid, charge_tesla_panel_p[1][playerid], 0);
	PlayerTextDrawSetOutline(playerid, charge_tesla_panel_p[1][playerid], 0);
	PlayerTextDrawFont(playerid, charge_tesla_panel_p[1][playerid], 4);

	charge_tesla_panel_p[2][playerid] = CreatePlayerTextDraw(playerid, 211.000000, 291.614868, "35"); // Text element
	PlayerTextDrawLetterSize(playerid, charge_tesla_panel_p[2][playerid], 0.223666, 1.293037);
	PlayerTextDrawAlignment(playerid, charge_tesla_panel_p[2][playerid], 2);
	PlayerTextDrawColor(playerid, charge_tesla_panel_p[2][playerid], -1);
	PlayerTextDrawUseBox(playerid, charge_tesla_panel_p[2][playerid], true);
	PlayerTextDrawBoxColor(playerid, charge_tesla_panel_p[2][playerid], 0);
	PlayerTextDrawSetShadow(playerid, charge_tesla_panel_p[2][playerid], 0);
	PlayerTextDrawSetOutline(playerid, charge_tesla_panel_p[2][playerid], 0);
	PlayerTextDrawBackgroundColor(playerid, charge_tesla_panel_p[2][playerid], 51);
	PlayerTextDrawFont(playerid, charge_tesla_panel_p[2][playerid], 1);
	PlayerTextDrawSetProportional(playerid, charge_tesla_panel_p[2][playerid], 1);

	charge_tesla_panel_p[3][playerid] = CreatePlayerTextDraw(playerid, 306.333343, 290.370391, "65"); // Text element
	PlayerTextDrawLetterSize(playerid, charge_tesla_panel_p[3][playerid], 0.223666, 1.293037);
	PlayerTextDrawAlignment(playerid, charge_tesla_panel_p[3][playerid], 2);
	PlayerTextDrawColor(playerid, charge_tesla_panel_p[3][playerid], -1);
	PlayerTextDrawUseBox(playerid, charge_tesla_panel_p[3][playerid], true);
	PlayerTextDrawBoxColor(playerid, charge_tesla_panel_p[3][playerid], 0);
	PlayerTextDrawSetShadow(playerid, charge_tesla_panel_p[3][playerid], 0);
	PlayerTextDrawSetOutline(playerid, charge_tesla_panel_p[3][playerid], 0);
	PlayerTextDrawBackgroundColor(playerid, charge_tesla_panel_p[3][playerid], 51);
	PlayerTextDrawFont(playerid, charge_tesla_panel_p[3][playerid], 1);
	PlayerTextDrawSetProportional(playerid, charge_tesla_panel_p[3][playerid], 1);

	charge_tesla_panel_p[4][playerid] = CreatePlayerTextDraw(playerid, 395.000061, 290.370422, "100"); // Text element
	PlayerTextDrawLetterSize(playerid, charge_tesla_panel_p[4][playerid], 0.223666, 1.293037);
	PlayerTextDrawAlignment(playerid, charge_tesla_panel_p[4][playerid], 2);
	PlayerTextDrawColor(playerid, charge_tesla_panel_p[4][playerid], -1);
	PlayerTextDrawUseBox(playerid, charge_tesla_panel_p[4][playerid], true);
	PlayerTextDrawBoxColor(playerid, charge_tesla_panel_p[4][playerid], 0);
	PlayerTextDrawSetShadow(playerid, charge_tesla_panel_p[4][playerid], 0);
	PlayerTextDrawSetOutline(playerid, charge_tesla_panel_p[4][playerid], 0);
	PlayerTextDrawBackgroundColor(playerid, charge_tesla_panel_p[4][playerid], 51);
	PlayerTextDrawFont(playerid, charge_tesla_panel_p[4][playerid], 1);
	PlayerTextDrawSetProportional(playerid, charge_tesla_panel_p[4][playerid], 1);

	charge_tesla_panel_p[5][playerid] = CreatePlayerTextDraw(playerid, 225.000076, 259.259155, "100"); // Text element
	PlayerTextDrawLetterSize(playerid, charge_tesla_panel_p[5][playerid], 0.223666, 1.293037);
	PlayerTextDrawAlignment(playerid, charge_tesla_panel_p[5][playerid], 2);
	PlayerTextDrawColor(playerid, charge_tesla_panel_p[5][playerid], -1);
	PlayerTextDrawUseBox(playerid, charge_tesla_panel_p[5][playerid], true);
	PlayerTextDrawBoxColor(playerid, charge_tesla_panel_p[5][playerid], 0);
	PlayerTextDrawSetShadow(playerid, charge_tesla_panel_p[5][playerid], 0);
	PlayerTextDrawSetOutline(playerid, charge_tesla_panel_p[5][playerid], 0);
	PlayerTextDrawBackgroundColor(playerid, charge_tesla_panel_p[5][playerid], 51);
	PlayerTextDrawFont(playerid, charge_tesla_panel_p[5][playerid], 2);
	PlayerTextDrawSetProportional(playerid, charge_tesla_panel_p[5][playerid], 1);

	charge_tesla_panel_p[6][playerid] = CreatePlayerTextDraw(playerid, 314.666992, 318.992523, "100"); // Text element
	PlayerTextDrawLetterSize(playerid, charge_tesla_panel_p[6][playerid], 0.301999, 1.492148);
	PlayerTextDrawAlignment(playerid, charge_tesla_panel_p[6][playerid], 2);
	PlayerTextDrawColor(playerid, charge_tesla_panel_p[6][playerid], -1);
	PlayerTextDrawUseBox(playerid, charge_tesla_panel_p[6][playerid], true);
	PlayerTextDrawBoxColor(playerid, charge_tesla_panel_p[6][playerid], 0);
	PlayerTextDrawSetShadow(playerid, charge_tesla_panel_p[6][playerid], 0);
	PlayerTextDrawSetOutline(playerid, charge_tesla_panel_p[6][playerid], 0);
	PlayerTextDrawBackgroundColor(playerid, charge_tesla_panel_p[6][playerid], 51);
	PlayerTextDrawFont(playerid, charge_tesla_panel_p[6][playerid], 1);
	PlayerTextDrawSetProportional(playerid, charge_tesla_panel_p[6][playerid], 1);

}

stock create_fill_lukoil()
{

	fill_lukoil_panel[0] = TextDrawCreate(263.666656, 185.422225, "LD_SPAC:white"); // Texture element
	TextDrawLetterSize(fill_lukoil_panel[0], 0.000000, 0.000000);
	TextDrawTextSize(fill_lukoil_panel[0], 86.333343, 72.592605);
	TextDrawAlignment(fill_lukoil_panel[0], 2);
	TextDrawColor(fill_lukoil_panel[0], -1);
	TextDrawSetShadow(fill_lukoil_panel[0], 0);
	TextDrawSetOutline(fill_lukoil_panel[0], 0);
	TextDrawFont(fill_lukoil_panel[0], 4);
	TextDrawSetSelectable(fill_lukoil_panel[0], true);

	fill_lukoil_panel[1] = TextDrawCreate(263.666534, 260.918518, "bb:zp_buy"); // Texture element
	TextDrawLetterSize(fill_lukoil_panel[1], 0.000000, 0.000000);
	TextDrawTextSize(fill_lukoil_panel[1], 86.333343, 72.592605);
	TextDrawAlignment(fill_lukoil_panel[1], 2);
	TextDrawColor(fill_lukoil_panel[1], -1);
	TextDrawSetShadow(fill_lukoil_panel[1], 0);
	TextDrawSetOutline(fill_lukoil_panel[1], 0);
	TextDrawFont(fill_lukoil_panel[1], 4);
	TextDrawSetSelectable(fill_lukoil_panel[1], true);

	fill_lukoil_panel[2] = TextDrawCreate(167.666656, 187.911102, "LD_SPAC:white"); // Texture element
	TextDrawLetterSize(fill_lukoil_panel[2], 0.000000, 0.000000);
	TextDrawTextSize(fill_lukoil_panel[2], 83.666671, 32.770385);
	TextDrawAlignment(fill_lukoil_panel[2], 2);
	TextDrawColor(fill_lukoil_panel[2], -1);
	TextDrawSetShadow(fill_lukoil_panel[2], 0);
	TextDrawSetOutline(fill_lukoil_panel[2], 0);
	TextDrawFont(fill_lukoil_panel[2], 4);
	TextDrawSetSelectable(fill_lukoil_panel[2], true);

	fill_lukoil_panel[3] = TextDrawCreate(167.666641, 225.244445, "LD_SPAC:white"); // Texture element
	TextDrawLetterSize(fill_lukoil_panel[3], 0.000000, 0.000000);
	TextDrawTextSize(fill_lukoil_panel[3], 83.666671, 32.770385);
	TextDrawAlignment(fill_lukoil_panel[3], 2);
	TextDrawColor(fill_lukoil_panel[3], -1);
	TextDrawSetShadow(fill_lukoil_panel[3], 0);
	TextDrawSetOutline(fill_lukoil_panel[3], 0);
	TextDrawFont(fill_lukoil_panel[3], 4);
	TextDrawSetSelectable(fill_lukoil_panel[3], true);

	fill_lukoil_panel[4] = TextDrawCreate(167.666641, 261.333404, "LD_SPAC:white"); // Texture element
	TextDrawLetterSize(fill_lukoil_panel[4], 0.000000, 0.000000);
	TextDrawTextSize(fill_lukoil_panel[4], 83.666671, 32.770385);
	TextDrawAlignment(fill_lukoil_panel[4], 2);
	TextDrawColor(fill_lukoil_panel[4], -1);
	TextDrawSetShadow(fill_lukoil_panel[4], 0);
	TextDrawSetOutline(fill_lukoil_panel[4], 0);
	TextDrawFont(fill_lukoil_panel[4], 4);
	TextDrawSetSelectable(fill_lukoil_panel[4], true);

	fill_lukoil_panel[5] = TextDrawCreate(167.666641, 298.252044, "LD_SPAC:white"); // Texture element
	TextDrawLetterSize(fill_lukoil_panel[5], 0.000000, 0.000000);
	TextDrawTextSize(fill_lukoil_panel[5], 83.666671, 32.770385);
	TextDrawAlignment(fill_lukoil_panel[5], 2);
	TextDrawColor(fill_lukoil_panel[5], -1);
	TextDrawSetShadow(fill_lukoil_panel[5], 0);
	TextDrawSetOutline(fill_lukoil_panel[5], 0);
	TextDrawFont(fill_lukoil_panel[5], 4);
	TextDrawSetSelectable(fill_lukoil_panel[5], true);

	fill_lukoil_panel[6] = TextDrawCreate(473.000000, 114.488891, "brilliantother:info_school_close"); // Texture element
	TextDrawLetterSize(fill_lukoil_panel[6], 0.000000, 0.000000);
	TextDrawTextSize(fill_lukoil_panel[6], 14.666666, 17.422229);
	TextDrawAlignment(fill_lukoil_panel[6], 2);
	TextDrawColor(fill_lukoil_panel[6], -1);
	TextDrawSetShadow(fill_lukoil_panel[6], 0);
	TextDrawSetOutline(fill_lukoil_panel[6], 0);
	TextDrawFont(fill_lukoil_panel[6], 4);
	TextDrawSetSelectable(fill_lukoil_panel[6], true);

	return true;
}


stock create_fill_lukoil_p(playerid)
{
	fill_lukoil_panel_p[0][playerid] = CreatePlayerTextDraw(playerid, 144.666717, 105.362960, "brilliantother:fill_panel_2_0"); // Texture element
	PlayerTextDrawLetterSize(playerid, fill_lukoil_panel_p[0][playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, fill_lukoil_panel_p[0][playerid], 345.333618, 277.511230);
	PlayerTextDrawAlignment(playerid, fill_lukoil_panel_p[0][playerid], 2);
	PlayerTextDrawColor(playerid, fill_lukoil_panel_p[0][playerid], -1);
	PlayerTextDrawSetShadow(playerid, fill_lukoil_panel_p[0][playerid], 0);
	PlayerTextDrawSetOutline(playerid, fill_lukoil_panel_p[0][playerid], 0);
	PlayerTextDrawFont(playerid, fill_lukoil_panel_p[0][playerid], 4);

	fill_lukoil_panel_p[1][playerid] = CreatePlayerTextDraw(playerid, 397.333312, 220.266677, "0L"); // Text element
	PlayerTextDrawLetterSize(playerid, fill_lukoil_panel_p[1][playerid], 0.407333, 2.205629);
	PlayerTextDrawAlignment(playerid, fill_lukoil_panel_p[1][playerid], 2);
	PlayerTextDrawColor(playerid, fill_lukoil_panel_p[1][playerid], 724183551);
	PlayerTextDrawSetShadow(playerid, fill_lukoil_panel_p[1][playerid], 0);
	PlayerTextDrawSetOutline(playerid, fill_lukoil_panel_p[1][playerid], 0);
	PlayerTextDrawBackgroundColor(playerid, fill_lukoil_panel_p[1][playerid], 51);
	PlayerTextDrawFont(playerid, fill_lukoil_panel_p[1][playerid], 1);
	PlayerTextDrawSetProportional(playerid, fill_lukoil_panel_p[1][playerid], 1);

	fill_lukoil_panel_p[2][playerid] = CreatePlayerTextDraw(playerid, 398.333282, 293.688995, "0_RUB"); // Text element
	PlayerTextDrawLetterSize(playerid, fill_lukoil_panel_p[2][playerid], 0.407333, 2.205629);
	PlayerTextDrawAlignment(playerid, fill_lukoil_panel_p[2][playerid], 2);
	PlayerTextDrawColor(playerid, fill_lukoil_panel_p[2][playerid], 724183551);
	PlayerTextDrawSetShadow(playerid, fill_lukoil_panel_p[2][playerid], 0);
	PlayerTextDrawSetOutline(playerid, fill_lukoil_panel_p[2][playerid], 0);
	PlayerTextDrawBackgroundColor(playerid, fill_lukoil_panel_p[2][playerid], 51);
	PlayerTextDrawFont(playerid, fill_lukoil_panel_p[2][playerid], 1);
	PlayerTextDrawSetProportional(playerid, fill_lukoil_panel_p[2][playerid], 1);

	fill_lukoil_panel_p[3][playerid] = CreatePlayerTextDraw(playerid, 355.666564, 165.511169, "0L"); // Text element
	PlayerTextDrawLetterSize(playerid, fill_lukoil_panel_p[3][playerid], 0.218000, 1.168592);
	PlayerTextDrawAlignment(playerid, fill_lukoil_panel_p[3][playerid], 2);
	PlayerTextDrawColor(playerid, fill_lukoil_panel_p[3][playerid], 724183551);
	PlayerTextDrawUseBox(playerid, fill_lukoil_panel_p[3][playerid], true);
	PlayerTextDrawBoxColor(playerid, fill_lukoil_panel_p[3][playerid], 0);
	PlayerTextDrawSetShadow(playerid, fill_lukoil_panel_p[3][playerid], 0);
	PlayerTextDrawSetOutline(playerid, fill_lukoil_panel_p[3][playerid], 0);
	PlayerTextDrawBackgroundColor(playerid, fill_lukoil_panel_p[3][playerid], 51);
	PlayerTextDrawFont(playerid, fill_lukoil_panel_p[3][playerid], 1);
	PlayerTextDrawSetProportional(playerid, fill_lukoil_panel_p[3][playerid], 1);

	return true;
}

stock create_fill_gazprom()
{

	fill_gazprom_panel[0] = TextDrawCreate(180.666671, 165.925918, "LD_SPAC:white"); // Texture element
	TextDrawLetterSize(fill_gazprom_panel[0], 0.000000, 0.000000);
	TextDrawTextSize(fill_gazprom_panel[0], 66.999984, 56.000000);
	TextDrawAlignment(fill_gazprom_panel[0], 2);
	TextDrawColor(fill_gazprom_panel[0], -1);
	TextDrawSetShadow(fill_gazprom_panel[0], 0);
	TextDrawSetOutline(fill_gazprom_panel[0], 0);
	TextDrawFont(fill_gazprom_panel[0], 4);
	TextDrawSetSelectable(fill_gazprom_panel[0], true);

	fill_gazprom_panel[1] = TextDrawCreate(250.666702, 165.511108, "LD_SPAC:white"); // Texture element
	TextDrawLetterSize(fill_gazprom_panel[1], 0.000000, 0.000000);
	TextDrawTextSize(fill_gazprom_panel[1], 66.999984, 56.000000);
	TextDrawAlignment(fill_gazprom_panel[1], 2);
	TextDrawColor(fill_gazprom_panel[1], -1);
	TextDrawSetShadow(fill_gazprom_panel[1], 0);
	TextDrawSetOutline(fill_gazprom_panel[1], 0);
	TextDrawFont(fill_gazprom_panel[1], 4);
	TextDrawSetSelectable(fill_gazprom_panel[1], true);

	fill_gazprom_panel[2] = TextDrawCreate(181.000061, 225.244506, "LD_SPAC:white"); // Texture element
	TextDrawLetterSize(fill_gazprom_panel[2], 0.000000, 0.000000);
	TextDrawTextSize(fill_gazprom_panel[2], 66.999984, 56.000000);
	TextDrawAlignment(fill_gazprom_panel[2], 2);
	TextDrawColor(fill_gazprom_panel[2], -1);
	TextDrawSetShadow(fill_gazprom_panel[2], 0);
	TextDrawSetOutline(fill_gazprom_panel[2], 0);
	TextDrawFont(fill_gazprom_panel[2], 4);
	TextDrawSetSelectable(fill_gazprom_panel[2], true);

	fill_gazprom_panel[3] = TextDrawCreate(251.000061, 225.244506, "LD_SPAC:white"); // Texture element
	TextDrawLetterSize(fill_gazprom_panel[3], 0.000000, 0.000000);
	TextDrawTextSize(fill_gazprom_panel[3], 66.999984, 56.000000);
	TextDrawAlignment(fill_gazprom_panel[3], 2);
	TextDrawColor(fill_gazprom_panel[3], -1);
	TextDrawSetShadow(fill_gazprom_panel[3], 0);
	TextDrawSetOutline(fill_gazprom_panel[3], 0);
	TextDrawFont(fill_gazprom_panel[3], 4);
	TextDrawSetSelectable(fill_gazprom_panel[3], true);

	fill_gazprom_panel[4] = TextDrawCreate(323.666809, 202.429656, "LD_SPAC:white"); // Texture element
	TextDrawLetterSize(fill_gazprom_panel[4], 0.000000, 0.000000);
	TextDrawTextSize(fill_gazprom_panel[4], 123.666664, 37.748146);
	TextDrawAlignment(fill_gazprom_panel[4], 2);
	TextDrawColor(fill_gazprom_panel[4], -1);
	TextDrawSetShadow(fill_gazprom_panel[4], 0);
	TextDrawSetOutline(fill_gazprom_panel[4], 0);
	TextDrawFont(fill_gazprom_panel[4], 4);
	TextDrawSetSelectable(fill_gazprom_panel[4], true);

	fill_gazprom_panel[5] = TextDrawCreate(158.666641, 334.755523, "brilliantother:fill_car_button_start"); // Texture element
	TextDrawLetterSize(fill_gazprom_panel[5], 0.000000, 0.000000);
	TextDrawTextSize(fill_gazprom_panel[5], 315.000061, 70.933326);
	TextDrawAlignment(fill_gazprom_panel[5], 1);
	TextDrawColor(fill_gazprom_panel[5], -1);
	TextDrawSetShadow(fill_gazprom_panel[5], 0);
	TextDrawSetOutline(fill_gazprom_panel[5], 0);
	TextDrawFont(fill_gazprom_panel[5], 4);

	fill_gazprom_panel[6] = TextDrawCreate(169.000122, 333.096313, "bb:zp_buy"); // Texture element
	TextDrawLetterSize(fill_gazprom_panel[6], 0.000000, 0.000000);
	TextDrawTextSize(fill_gazprom_panel[6], 290.000000, 75.081497);
	TextDrawAlignment(fill_gazprom_panel[6], 2);
	TextDrawColor(fill_gazprom_panel[6], -1);
	TextDrawSetShadow(fill_gazprom_panel[6], 0);
	TextDrawSetOutline(fill_gazprom_panel[6], 0);
	TextDrawFont(fill_gazprom_panel[6], 4);
	TextDrawSetSelectable(fill_gazprom_panel[6], true);

	fill_gazprom_panel[7] = TextDrawCreate(454.666656, 120.296310, "brilliantother:info_school_close"); // Texture element
	TextDrawLetterSize(fill_gazprom_panel[7], 0.000000, 0.000000);
	TextDrawTextSize(fill_gazprom_panel[7], 14.666664, 17.422224);
	TextDrawAlignment(fill_gazprom_panel[7], 2);
	TextDrawColor(fill_gazprom_panel[7], -1);
	TextDrawSetShadow(fill_gazprom_panel[7], 0);
	TextDrawSetOutline(fill_gazprom_panel[7], 0);
	TextDrawFont(fill_gazprom_panel[7], 4);
	TextDrawSetSelectable(fill_gazprom_panel[7], true);

	return true;
}


stock create_fill_gazprom_p(playerid)
{
	filling_gazprom_p[0][playerid] = CreatePlayerTextDraw(playerid, 158.333389, 112.414772, "brilliantother:fill_panel_1_0"); // Texture element
	PlayerTextDrawLetterSize(playerid, filling_gazprom_p[0][playerid], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, filling_gazprom_p[0][playerid], 312.000091, 251.792572);
	PlayerTextDrawAlignment(playerid, filling_gazprom_p[0][playerid], 2);
	PlayerTextDrawColor(playerid, filling_gazprom_p[0][playerid], -1);
	PlayerTextDrawSetShadow(playerid, filling_gazprom_p[0][playerid], 0);
	PlayerTextDrawSetOutline(playerid, filling_gazprom_p[0][playerid], 0);
	PlayerTextDrawFont(playerid, filling_gazprom_p[0][playerid], 4);

	filling_gazprom_p[1][playerid] = CreatePlayerTextDraw(playerid, 353.333496, 172.148147, "0L"); // Text element
	PlayerTextDrawLetterSize(playerid, filling_gazprom_p[1][playerid], 0.237999, 1.546072);
	PlayerTextDrawAlignment(playerid, filling_gazprom_p[1][playerid], 2);
	PlayerTextDrawColor(playerid, filling_gazprom_p[1][playerid], -1);
	PlayerTextDrawUseBox(playerid, filling_gazprom_p[1][playerid], true);
	PlayerTextDrawBoxColor(playerid, filling_gazprom_p[1][playerid], 0);
	PlayerTextDrawSetShadow(playerid, filling_gazprom_p[1][playerid], 0);
	PlayerTextDrawSetOutline(playerid, filling_gazprom_p[1][playerid], 0);
	PlayerTextDrawBackgroundColor(playerid, filling_gazprom_p[1][playerid], 51);
	PlayerTextDrawFont(playerid, filling_gazprom_p[1][playerid], 2);
	PlayerTextDrawSetProportional(playerid, filling_gazprom_p[1][playerid], 1);

	filling_gazprom_p[2][playerid] = CreatePlayerTextDraw(playerid, 355.000122, 301.155548, "0_RUB"); // Text element
	PlayerTextDrawLetterSize(playerid, filling_gazprom_p[2][playerid], 0.237999, 1.546072);
	PlayerTextDrawAlignment(playerid, filling_gazprom_p[2][playerid], 2);
	PlayerTextDrawColor(playerid, filling_gazprom_p[2][playerid], -1);
	PlayerTextDrawUseBox(playerid, filling_gazprom_p[2][playerid], true);
	PlayerTextDrawBoxColor(playerid, filling_gazprom_p[2][playerid], 0);
	PlayerTextDrawSetShadow(playerid, filling_gazprom_p[2][playerid], 0);
	PlayerTextDrawSetOutline(playerid, filling_gazprom_p[2][playerid], 0);
	PlayerTextDrawBackgroundColor(playerid, filling_gazprom_p[2][playerid], 51);
	PlayerTextDrawFont(playerid, filling_gazprom_p[2][playerid], 2);
	PlayerTextDrawSetProportional(playerid, filling_gazprom_p[2][playerid], 1);

	filling_gazprom_p[3][playerid] = CreatePlayerTextDraw(playerid, 200.666824, 301.985198, "0L"); // Text element
	PlayerTextDrawLetterSize(playerid, filling_gazprom_p[3][playerid], 0.237999, 1.546072);
	PlayerTextDrawAlignment(playerid, filling_gazprom_p[3][playerid], 2);
	PlayerTextDrawColor(playerid, filling_gazprom_p[3][playerid], -1);
	PlayerTextDrawUseBox(playerid, filling_gazprom_p[3][playerid], true);
	PlayerTextDrawBoxColor(playerid, filling_gazprom_p[3][playerid], 0);
	PlayerTextDrawSetShadow(playerid, filling_gazprom_p[3][playerid], 0);
	PlayerTextDrawSetOutline(playerid, filling_gazprom_p[3][playerid], 0);
	PlayerTextDrawBackgroundColor(playerid, filling_gazprom_p[3][playerid], 51);
	PlayerTextDrawFont(playerid, filling_gazprom_p[3][playerid], 2);
	PlayerTextDrawSetProportional(playerid, filling_gazprom_p[3][playerid], 1);

	return true;
}


stock create_speed_background()
{

	speed_background = TextDrawCreate(240.333282, 299.614898, "brilliantspeed:main");
	TextDrawTextSize(speed_background, 160.000000, 195.000000);
	TextDrawAlignment(speed_background, 1);
	TextDrawColor(speed_background, -1);
	TextDrawBackgroundColor(speed_background, 255);
	TextDrawFont(speed_background, 4);
	TextDrawSetProportional(speed_background, 0);

	return true;
}

stock create_speec_td(playerid)
{
	admin_speec_p[0][playerid] = CreatePlayerTextDraw(playerid, 552.666381, 129.422210, "CHRISTIAN_BAGWELL (ID:50)"); // Text element
	PlayerTextDrawLetterSize(playerid, admin_speec_p[0][playerid], 0.165665, 1.060740);
	PlayerTextDrawAlignment(playerid, admin_speec_p[0][playerid], 2);
	PlayerTextDrawColor(playerid, admin_speec_p[0][playerid], -1);
	PlayerTextDrawSetShadow(playerid, admin_speec_p[0][playerid], 0);
	PlayerTextDrawSetOutline(playerid, admin_speec_p[0][playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, admin_speec_p[0][playerid], 51);
	PlayerTextDrawFont(playerid, admin_speec_p[0][playerid], 2);
	PlayerTextDrawSetProportional(playerid, admin_speec_p[0][playerid], 1);

	admin_speec_p[1][playerid] = CreatePlayerTextDraw(playerid, 493.332916, 146.014785, "LEVEL:_3~n~HEALTH:_50.0~n~ARMOUR:_1110.0~n~SKIN:_35ID~n~GREEN_ZONE:_0~n~VIRTUAL_WORLD:_1~n~WARN:_1"); // Text element
	PlayerTextDrawLetterSize(playerid, admin_speec_p[1][playerid], 0.165665, 1.060740);
	PlayerTextDrawAlignment(playerid, admin_speec_p[1][playerid], 1);
	PlayerTextDrawColor(playerid, admin_speec_p[1][playerid], -1);
	PlayerTextDrawSetShadow(playerid, admin_speec_p[1][playerid], 0);
	PlayerTextDrawSetOutline(playerid, admin_speec_p[1][playerid], 0);
	PlayerTextDrawBackgroundColor(playerid, admin_speec_p[1][playerid], 51);
	PlayerTextDrawFont(playerid, admin_speec_p[1][playerid], 2);
	PlayerTextDrawSetProportional(playerid, admin_speec_p[1][playerid], 1);

	admin_speec_p[2][playerid] = CreatePlayerTextDraw(playerid, 493.666229, 223.170318, "MONEY:_50000_RUB~n~BANK:_50000000_RUB~n~ORG:_0~n~RANK:_0~n~JOB:_0"); // Text element
	PlayerTextDrawLetterSize(playerid, admin_speec_p[2][playerid], 0.165665, 1.060740);
	PlayerTextDrawAlignment(playerid, admin_speec_p[2][playerid], 1);
	PlayerTextDrawColor(playerid, admin_speec_p[2][playerid], -1);
	PlayerTextDrawSetShadow(playerid, admin_speec_p[2][playerid], 0);
	PlayerTextDrawSetOutline(playerid, admin_speec_p[2][playerid], 0);
	PlayerTextDrawBackgroundColor(playerid, admin_speec_p[2][playerid], 51);
	PlayerTextDrawFont(playerid, admin_speec_p[2][playerid], 2);
	PlayerTextDrawSetProportional(playerid, admin_speec_p[2][playerid], 1);

	admin_speec_p[3][playerid] = CreatePlayerTextDraw(playerid, 492.999450, 280.414794, "SPEED:_0 KM/H~n~CAR_FUEL:_50L~n~CAR_ENG:_1"); // Text element
	PlayerTextDrawLetterSize(playerid, admin_speec_p[3][playerid], 0.165665, 1.060740);
	PlayerTextDrawAlignment(playerid, admin_speec_p[3][playerid], 1);
	PlayerTextDrawColor(playerid, admin_speec_p[3][playerid], -1);
	PlayerTextDrawSetShadow(playerid, admin_speec_p[3][playerid], 0);
	PlayerTextDrawSetOutline(playerid, admin_speec_p[3][playerid], 0);
	PlayerTextDrawBackgroundColor(playerid, admin_speec_p[3][playerid], 51);
	PlayerTextDrawFont(playerid, admin_speec_p[3][playerid], 2);
	PlayerTextDrawSetProportional(playerid, admin_speec_p[3][playerid], 1);

	admin_speec_p[4][playerid] = CreatePlayerTextDraw(playerid, 595.332885, 325.629455, "1 (0.0)~n~~n~56_MS~n~~n~50_S"); // Text element
	PlayerTextDrawLetterSize(playerid, admin_speec_p[4][playerid], 0.209665, 1.454815);
	PlayerTextDrawAlignment(playerid, admin_speec_p[4][playerid], 2);
	PlayerTextDrawColor(playerid, admin_speec_p[4][playerid], -1);
	PlayerTextDrawSetShadow(playerid, admin_speec_p[4][playerid], 0);
	PlayerTextDrawSetOutline(playerid, admin_speec_p[4][playerid], 0);
	PlayerTextDrawBackgroundColor(playerid, admin_speec_p[4][playerid], 51);
	PlayerTextDrawFont(playerid, admin_speec_p[4][playerid], 2);
	PlayerTextDrawSetProportional(playerid, admin_speec_p[4][playerid], 1);


}

stock create_adm_sp()
{
	speec_panel_admin[0] = TextDrawCreate(21.333335, 107.022239, "brp_admin:admin_panel_1"); // Texture element
	TextDrawLetterSize(speec_panel_admin[0], 0.000000, 0.000000);
	TextDrawTextSize(speec_panel_admin[0], 116.333305, 291.199951);
	TextDrawAlignment(speec_panel_admin[0], 1);
	TextDrawColor(speec_panel_admin[0], -1);
	TextDrawSetShadow(speec_panel_admin[0], 0);
	TextDrawSetOutline(speec_panel_admin[0], 0);
	TextDrawFont(speec_panel_admin[0], 4);

	speec_panel_admin[1] = TextDrawCreate(487.333404, 110.755584, "brp_admin:admin_panel_2"); // Texture element
	TextDrawLetterSize(speec_panel_admin[1], 0.000000, 0.000000);
	TextDrawTextSize(speec_panel_admin[1], 133.999984, 289.540679);
	TextDrawAlignment(speec_panel_admin[1], 1);
	TextDrawColor(speec_panel_admin[1], -1);
	TextDrawUseBox(speec_panel_admin[1], true);
	TextDrawBoxColor(speec_panel_admin[1], 0);
	TextDrawSetShadow(speec_panel_admin[1], 0);
	TextDrawSetOutline(speec_panel_admin[1], 0);
	TextDrawFont(speec_panel_admin[1], 4);

	speec_panel_admin[2] = TextDrawCreate(22.666666, 147.674072, "brp_admin:admin_button_1"); // Texture element
	TextDrawLetterSize(speec_panel_admin[2], 0.000000, 0.000000);
	TextDrawTextSize(speec_panel_admin[2], 115.666664, 19.911117);
	TextDrawAlignment(speec_panel_admin[2], 2);
	TextDrawColor(speec_panel_admin[2], -1);
	TextDrawSetShadow(speec_panel_admin[2], 0);
	TextDrawSetOutline(speec_panel_admin[2], 0);
	TextDrawFont(speec_panel_admin[2], 4);
	TextDrawSetSelectable(speec_panel_admin[2], true);

	speec_panel_admin[3] = TextDrawCreate(22.666669, 169.244461, "brp_admin:admin_button_2"); // Texture element
	TextDrawLetterSize(speec_panel_admin[3], 0.000000, 0.000000);
	TextDrawTextSize(speec_panel_admin[3], 115.666664, 19.911117);
	TextDrawAlignment(speec_panel_admin[3], 2);
	TextDrawColor(speec_panel_admin[3], -1);
	TextDrawSetShadow(speec_panel_admin[3], 0);
	TextDrawSetOutline(speec_panel_admin[3], 0);
	TextDrawFont(speec_panel_admin[3], 4);
	TextDrawSetSelectable(speec_panel_admin[3], true);

	speec_panel_admin[4] = TextDrawCreate(22.666671, 189.985229, "brp_admin:admin_button_3"); // Texture element
	TextDrawLetterSize(speec_panel_admin[4], 0.000000, 0.000000);
	TextDrawTextSize(speec_panel_admin[4], 115.666664, 19.911117);
	TextDrawAlignment(speec_panel_admin[4], 2);
	TextDrawColor(speec_panel_admin[4], -1);
	TextDrawSetShadow(speec_panel_admin[4], 0);
	TextDrawSetOutline(speec_panel_admin[4], 0);
	TextDrawFont(speec_panel_admin[4], 4);
	TextDrawSetSelectable(speec_panel_admin[4], true);

	speec_panel_admin[5] = TextDrawCreate(22.666671, 210.725952, "brp_admin:admin_button_5"); // Texture element
	TextDrawLetterSize(speec_panel_admin[5], 0.000000, 0.000000);
	TextDrawTextSize(speec_panel_admin[5], 115.666664, 19.911117);
	TextDrawAlignment(speec_panel_admin[5], 2);
	TextDrawColor(speec_panel_admin[5], -1);
	TextDrawSetShadow(speec_panel_admin[5], 0);
	TextDrawSetOutline(speec_panel_admin[5], 0);
	TextDrawFont(speec_panel_admin[5], 4);
	TextDrawSetSelectable(speec_panel_admin[5], true);

	speec_panel_admin[6] = TextDrawCreate(22.666673, 231.466766, "brp_admin:admin_button_6"); // Texture element
	TextDrawLetterSize(speec_panel_admin[6], 0.000000, 0.000000);
	TextDrawTextSize(speec_panel_admin[6], 115.666664, 19.911117);
	TextDrawAlignment(speec_panel_admin[6], 2);
	TextDrawColor(speec_panel_admin[6], -1);
	TextDrawSetShadow(speec_panel_admin[6], 0);
	TextDrawSetOutline(speec_panel_admin[6], 0);
	TextDrawFont(speec_panel_admin[6], 4);
	TextDrawSetSelectable(speec_panel_admin[6], true);

	speec_panel_admin[7] = TextDrawCreate(22.333339, 252.207550, "brp_admin:admin_button_7"); // Texture element
	TextDrawLetterSize(speec_panel_admin[7], 0.000000, 0.000000);
	TextDrawTextSize(speec_panel_admin[7], 115.666664, 19.911117);
	TextDrawAlignment(speec_panel_admin[7], 2);
	TextDrawColor(speec_panel_admin[7], -1);
	TextDrawSetShadow(speec_panel_admin[7], 0);
	TextDrawSetOutline(speec_panel_admin[7], 0);
	TextDrawFont(speec_panel_admin[7], 4);
	TextDrawSetSelectable(speec_panel_admin[7], true);

	speec_panel_admin[8] = TextDrawCreate(22.333339, 272.948364, "brp_admin:admin_button_8"); // Texture element
	TextDrawLetterSize(speec_panel_admin[8], 0.000000, 0.000000);
	TextDrawTextSize(speec_panel_admin[8], 115.666664, 19.911117);
	TextDrawAlignment(speec_panel_admin[8], 2);
	TextDrawColor(speec_panel_admin[8], -1);
	TextDrawSetShadow(speec_panel_admin[8], 0);
	TextDrawSetOutline(speec_panel_admin[8], 0);
	TextDrawFont(speec_panel_admin[8], 4);
	TextDrawSetSelectable(speec_panel_admin[8], true);

	speec_panel_admin[9] = TextDrawCreate(22.333339, 294.103973, "brp_admin:admin_button_9"); // Texture element
	TextDrawLetterSize(speec_panel_admin[9], 0.000000, 0.000000);
	TextDrawTextSize(speec_panel_admin[9], 115.666664, 19.911117);
	TextDrawAlignment(speec_panel_admin[9], 2);
	TextDrawColor(speec_panel_admin[9], -1);
	TextDrawSetShadow(speec_panel_admin[9], 0);
	TextDrawSetOutline(speec_panel_admin[9], 0);
	TextDrawFont(speec_panel_admin[9], 4);
	TextDrawSetSelectable(speec_panel_admin[9], true);

	speec_panel_admin[10] = TextDrawCreate(22.666673, 347.200378, "brp_admin:admin_button_10"); // Texture element
	TextDrawLetterSize(speec_panel_admin[10], 0.000000, 0.000000);
	TextDrawTextSize(speec_panel_admin[10], 66.666641, 20.740745);
	TextDrawAlignment(speec_panel_admin[10], 2);
	TextDrawColor(speec_panel_admin[10], -1);
	TextDrawSetShadow(speec_panel_admin[10], 0);
	TextDrawSetOutline(speec_panel_admin[10], 0);
	TextDrawFont(speec_panel_admin[10], 4);
	TextDrawSetSelectable(speec_panel_admin[10], true);

	speec_panel_admin[11] = TextDrawCreate(70.000015, 347.200317, "brp_admin:admin_button_11"); // Texture element
	TextDrawLetterSize(speec_panel_admin[11], 0.000000, 0.000000);
	TextDrawTextSize(speec_panel_admin[11], 66.666641, 20.740745);
	TextDrawAlignment(speec_panel_admin[11], 2);
	TextDrawColor(speec_panel_admin[11], -1);
	TextDrawSetShadow(speec_panel_admin[11], 0);
	TextDrawSetOutline(speec_panel_admin[11], 0);
	TextDrawFont(speec_panel_admin[11], 4);
	TextDrawSetSelectable(speec_panel_admin[11], true);

	speec_panel_admin[12] = TextDrawCreate(24.000019, 373.748443, "brp_admin:admin_button_12"); // Texture element
	TextDrawLetterSize(speec_panel_admin[12], 0.000000, 0.000000);
	TextDrawTextSize(speec_panel_admin[12], 66.666641, 20.740745);
	TextDrawAlignment(speec_panel_admin[12], 2);
	TextDrawColor(speec_panel_admin[12], -1);
	TextDrawSetShadow(speec_panel_admin[12], 0);
	TextDrawSetOutline(speec_panel_admin[12], 0);
	TextDrawFont(speec_panel_admin[12], 4);
	TextDrawSetSelectable(speec_panel_admin[12], true);

	speec_panel_admin[13] = TextDrawCreate(69.000007, 373.333618, "brp_admin:admin_button_13"); // Texture element
	TextDrawLetterSize(speec_panel_admin[13], 0.000000, 0.000000);
	TextDrawTextSize(speec_panel_admin[13], 66.666641, 20.740745);
	TextDrawAlignment(speec_panel_admin[13], 2);
	TextDrawColor(speec_panel_admin[13], -1);
	TextDrawSetShadow(speec_panel_admin[13], 0);
	TextDrawSetOutline(speec_panel_admin[13], 0);
	TextDrawFont(speec_panel_admin[13], 4);
	TextDrawSetSelectable(speec_panel_admin[13], true);
}

stock create_player_speed(playerid)
{

	player_speed_car[0][playerid] = CreatePlayerTextDraw(playerid, 239.133514, 300.314941, "brilliantspeed:s19");
	PlayerTextDrawTextSize(playerid, player_speed_car[0][playerid], 159.000000, 193.000000);
	PlayerTextDrawAlignment(playerid, player_speed_car[0][playerid], 1);
	PlayerTextDrawColor(playerid, player_speed_car[0][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, player_speed_car[0][playerid], 255);
	PlayerTextDrawFont(playerid, player_speed_car[0][playerid], 4);
	PlayerTextDrawSetProportional(playerid, player_speed_car[0][playerid], 0);

	player_speed_car[1][playerid] = CreatePlayerTextDraw(playerid, 245.699920, 344.899871, "brilliantspeed:f8");
	PlayerTextDrawTextSize(playerid, player_speed_car[1][playerid], 78.589927, 97.010017);
	PlayerTextDrawAlignment(playerid, player_speed_car[1][playerid], 1);
	PlayerTextDrawColor(playerid, player_speed_car[1][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, player_speed_car[1][playerid], 255);
	PlayerTextDrawFont(playerid, player_speed_car[1][playerid], 4);
	PlayerTextDrawSetProportional(playerid, player_speed_car[1][playerid], 0);

	player_speed_car[2][playerid] = CreatePlayerTextDraw(playerid, 319.832611, 344.714538, "brilliantspeed:h5");
	PlayerTextDrawTextSize(playerid, player_speed_car[2][playerid], 78.040039, 97.670059);
	PlayerTextDrawAlignment(playerid, player_speed_car[2][playerid], 1);
	PlayerTextDrawColor(playerid, player_speed_car[2][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, player_speed_car[2][playerid], 255);
	PlayerTextDrawFont(playerid, player_speed_car[2][playerid], 4);
	PlayerTextDrawSetProportional(playerid, player_speed_car[2][playerid], 0);

	player_speed_car[3][playerid] = CreatePlayerTextDraw(playerid, 319.299957, 414.500030, "000000");
	PlayerTextDrawLetterSize(playerid, player_speed_car[3][playerid], 0.273665, 1.181035);
	PlayerTextDrawTextSize(playerid, player_speed_car[3][playerid], 0.000000, 34.990005);
	PlayerTextDrawAlignment(playerid, player_speed_car[3][playerid], 2);
	PlayerTextDrawColor(playerid, player_speed_car[3][playerid], -1);
	PlayerTextDrawSetShadow(playerid, player_speed_car[3][playerid], 0);
	PlayerTextDrawBackgroundColor(playerid, player_speed_car[3][playerid], 255);
	PlayerTextDrawFont(playerid, player_speed_car[3][playerid], 1);
	PlayerTextDrawSetProportional(playerid, player_speed_car[3][playerid], 1);

	player_speed_car[4][playerid] = CreatePlayerTextDraw(playerid, 253.099945, 398.800048, "100");
	PlayerTextDrawLetterSize(playerid, player_speed_car[4][playerid], 0.228330, 0.998516);
	PlayerTextDrawTextSize(playerid, player_speed_car[4][playerid], 0.000000, 34.990005);
	PlayerTextDrawAlignment(playerid, player_speed_car[4][playerid], 2);
	PlayerTextDrawColor(playerid, player_speed_car[4][playerid], -1);
	PlayerTextDrawSetShadow(playerid, player_speed_car[4][playerid], 0);
	PlayerTextDrawBackgroundColor(playerid, player_speed_car[4][playerid], 255);
	PlayerTextDrawFont(playerid, player_speed_car[4][playerid], 1);
	PlayerTextDrawSetProportional(playerid, player_speed_car[4][playerid], 1);

	player_speed_car[5][playerid] = CreatePlayerTextDraw(playerid, 383.900146, 398.799865, "1000");
	PlayerTextDrawLetterSize(playerid, player_speed_car[5][playerid], 0.228330, 0.998516);
	PlayerTextDrawTextSize(playerid, player_speed_car[5][playerid], 0.000000, 8.000000);
	PlayerTextDrawAlignment(playerid, player_speed_car[5][playerid], 2);
	PlayerTextDrawColor(playerid, player_speed_car[5][playerid], -1);
	PlayerTextDrawSetShadow(playerid, player_speed_car[5][playerid], 0);
	PlayerTextDrawBackgroundColor(playerid, player_speed_car[5][playerid], 255);
	PlayerTextDrawFont(playerid, player_speed_car[5][playerid], 1);
	PlayerTextDrawSetProportional(playerid, player_speed_car[5][playerid], 1);

	player_speed_car[6][playerid] = CreatePlayerTextDraw(playerid, 320.000122, 370.200134, "000");
	PlayerTextDrawLetterSize(playerid, player_speed_car[6][playerid], 0.678664, 3.267554);
	PlayerTextDrawTextSize(playerid, player_speed_car[6][playerid], 0.000000, 20.040000);
	PlayerTextDrawAlignment(playerid, player_speed_car[6][playerid], 2);
	PlayerTextDrawColor(playerid, player_speed_car[6][playerid], -1);
	PlayerTextDrawSetShadow(playerid, player_speed_car[6][playerid], 0);
	PlayerTextDrawBackgroundColor(playerid, player_speed_car[6][playerid], 255);
	PlayerTextDrawFont(playerid, player_speed_car[6][playerid], 1);
	PlayerTextDrawSetProportional(playerid, player_speed_car[6][playerid], 1);

	player_speed_car[7][playerid] = CreatePlayerTextDraw(playerid, 290.999969, 428.899993, "brilliantspeed:engineoff");
	PlayerTextDrawTextSize(playerid, player_speed_car[7][playerid], 20.000000, 23.000000);
	PlayerTextDrawAlignment(playerid, player_speed_car[7][playerid], 1);
	PlayerTextDrawColor(playerid, player_speed_car[7][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, player_speed_car[7][playerid], 255);
	PlayerTextDrawFont(playerid, player_speed_car[7][playerid], 4);
	PlayerTextDrawSetProportional(playerid, player_speed_car[7][playerid], 0);

	player_speed_car[8][playerid] = CreatePlayerTextDraw(playerid, 309.500061, 428.999938, "brilliantspeed:lightons");
	PlayerTextDrawTextSize(playerid, player_speed_car[8][playerid], 20.000000, 23.000000);
	PlayerTextDrawAlignment(playerid, player_speed_car[8][playerid], 1);
	PlayerTextDrawColor(playerid, player_speed_car[8][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, player_speed_car[8][playerid], 255);
	PlayerTextDrawFont(playerid, player_speed_car[8][playerid], 4);
	PlayerTextDrawSetProportional(playerid, player_speed_car[8][playerid], 0);

	player_speed_car[9][playerid] = CreatePlayerTextDraw(playerid, 327.299987, 428.799926, "brilliantspeed:lock");
	PlayerTextDrawTextSize(playerid, player_speed_car[9][playerid], 20.000000, 23.000000);
	PlayerTextDrawAlignment(playerid, player_speed_car[9][playerid], 1);
	PlayerTextDrawColor(playerid, player_speed_car[9][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, player_speed_car[9][playerid], 255);
	PlayerTextDrawFont(playerid, player_speed_car[9][playerid], 4);
	PlayerTextDrawSetProportional(playerid, player_speed_car[9][playerid], 0);

	player_speed_car[10][playerid] = CreatePlayerTextDraw(playerid, 248.499969, 385.199951, "brilliantspeed:fuel");
	PlayerTextDrawTextSize(playerid, player_speed_car[10][playerid], 11.060007, 13.000000);
	PlayerTextDrawAlignment(playerid, player_speed_car[10][playerid], 1);
	PlayerTextDrawColor(playerid, player_speed_car[10][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, player_speed_car[10][playerid], 255);
	PlayerTextDrawFont(playerid, player_speed_car[10][playerid], 4);
	PlayerTextDrawSetProportional(playerid, player_speed_car[10][playerid], 0);

	return true;

}


stock show_player_green_zone(playerid, type)
{
	switch(type)
	{
		case TEXTDRAW_SHOW:
		{
			WN_showGreenZone(playerid, 1);
		}
		case TEXTDRAW_HIDE:
		{
			WN_showGreenZone(playerid, 2);
		}
	}

	return true;
}

stock show_player_gps(playerid, type)
{
	switch(type)
	{
		case TEXTDRAW_SHOW:
		{
			WN_showGPS(playerid, 1);
		}
		case TEXTDRAW_HIDE:
		{
			WN_showGPS(playerid, 2);
		}
	}	

	return true;
}

stock show_player_hungry(playerid)
{

	return true;
}

stock hide_player_hungry(playerid)
{
	TextDrawHideForPlayer(playerid, hungry_background);

	PlayerTextDrawHide(playerid, hungry_hud_p[0][playerid]);
	PlayerTextDrawHide(playerid, hungry_hud_p[1][playerid]);

	return true;
}

stock create_green_zone_td()
{
	green_zone_td = TextDrawCreate(-1.666680, 223.999908, "brilliantother:zz"); // Texture element
	TextDrawLetterSize(green_zone_td, 0.000000, 0.000000);
	TextDrawTextSize(green_zone_td, 130.833328, 85.037055);
	TextDrawAlignment(green_zone_td, 1);
	TextDrawColor(green_zone_td, -1);
	TextDrawSetShadow(green_zone_td, 0);
	TextDrawSetOutline(green_zone_td, 0);
	TextDrawFont(green_zone_td, 4);

	return true;
}


stock create_hungry_background()
{
	hungry_background = TextDrawCreate(390.000152, 0.688880, "brilliantother:golod");
	TextDrawTextSize(hungry_background, 160.899993, 25.949956);
	TextDrawAlignment(hungry_background, 1);
	TextDrawColor(hungry_background, -1);
	TextDrawBackgroundColor(hungry_background, 255);
	TextDrawFont(hungry_background, 4);
	TextDrawSetProportional(hungry_background, 0);

	return true;
}

stock create_hungry_player(playerid)
{

	hungry_hud_p[0][playerid] = CreatePlayerTextDraw(playerid, 431.432769, 6.255557, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, hungry_hud_p[0][playerid], 94.950057, 11.509919);
	PlayerTextDrawAlignment(playerid, hungry_hud_p[0][playerid], 1);
	PlayerTextDrawColor(playerid, hungry_hud_p[0][playerid], -259251201);
	PlayerTextDrawBackgroundColor(playerid, hungry_hud_p[0][playerid], 255);
	PlayerTextDrawFont(playerid, hungry_hud_p[0][playerid], 4);
	PlayerTextDrawSetProportional(playerid, hungry_hud_p[0][playerid], 0);

	hungry_hud_p[1][playerid] = CreatePlayerTextDraw(playerid, 478.833343, 7.196290, "85%");
	PlayerTextDrawLetterSize(playerid, hungry_hud_p[1][playerid], 0.176330, 0.998516);
	PlayerTextDrawTextSize(playerid, hungry_hud_p[1][playerid], 0.000000, 92.800048);
	PlayerTextDrawAlignment(playerid, hungry_hud_p[1][playerid], 2);
	PlayerTextDrawColor(playerid, hungry_hud_p[1][playerid], -1);
	PlayerTextDrawSetShadow(playerid, hungry_hud_p[1][playerid], 0);
	PlayerTextDrawBackgroundColor(playerid, hungry_hud_p[1][playerid], 255);
	PlayerTextDrawFont(playerid, hungry_hud_p[1][playerid], 1);
	PlayerTextDrawSetProportional(playerid, hungry_hud_p[1][playerid], 1);


	return true;


}

stock create_snow_work_player(playerid)
{
	if(snow_work_player[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		snow_work_player[0][playerid] = CreatePlayerTextDraw(playerid, 14.333333, 188.325927, "brilliantother:gui_snow_job"); // Texture element
		PlayerTextDrawLetterSize(playerid, snow_work_player[0][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, snow_work_player[0][playerid], 106.333351, 69.688911);
		PlayerTextDrawAlignment(playerid, snow_work_player[0][playerid], 2);
		PlayerTextDrawColor(playerid, snow_work_player[0][playerid], -1);
		PlayerTextDrawSetShadow(playerid, snow_work_player[0][playerid], 0);
		PlayerTextDrawSetOutline(playerid, snow_work_player[0][playerid], 0);
		PlayerTextDrawFont(playerid, snow_work_player[0][playerid], 4);
	}
	if(snow_work_player[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		snow_work_player[1][playerid] = CreatePlayerTextDraw(playerid, 67.666679, 189.570358, "10:25"); // Text element
		PlayerTextDrawLetterSize(playerid, snow_work_player[1][playerid], 0.344999, 1.707852);
		PlayerTextDrawAlignment(playerid, snow_work_player[1][playerid], 2);
		PlayerTextDrawColor(playerid, snow_work_player[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, snow_work_player[1][playerid], 0);
		PlayerTextDrawSetOutline(playerid, snow_work_player[1][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, snow_work_player[1][playerid], 51);
		PlayerTextDrawFont(playerid, snow_work_player[1][playerid], 2);
		PlayerTextDrawSetProportional(playerid, snow_work_player[1][playerid], 1);
	}
	if(snow_work_player[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		snow_work_player[2][playerid] = CreatePlayerTextDraw(playerid, 68.333351, 222.755615, "0/0"); // Text element
		PlayerTextDrawLetterSize(playerid, snow_work_player[2][playerid], 0.400666, 2.056295);
		PlayerTextDrawAlignment(playerid, snow_work_player[2][playerid], 2);
		PlayerTextDrawColor(playerid, snow_work_player[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, snow_work_player[2][playerid], 0);
		PlayerTextDrawSetOutline(playerid, snow_work_player[2][playerid], 0);
		PlayerTextDrawBackgroundColor(playerid, snow_work_player[2][playerid], 51);
		PlayerTextDrawFont(playerid, snow_work_player[2][playerid], 2);
		PlayerTextDrawSetProportional(playerid, snow_work_player[2][playerid], 1);
	}
	return true;
}

stock create_voice_td_player(playerid)
{
	if(voice_setting_player[0][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		voice_setting_player[0][playerid] = CreatePlayerTextDraw(playerid, 355.333343, 168.414810, "brilliantother:voice_setting_on"); // Texture element
		PlayerTextDrawLetterSize(playerid, voice_setting_player[0][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, voice_setting_player[0][playerid], 23.333337, 15.348150);
		PlayerTextDrawAlignment(playerid, voice_setting_player[0][playerid], 2);
		PlayerTextDrawColor(playerid, voice_setting_player[0][playerid], -1);
		PlayerTextDrawSetShadow(playerid, voice_setting_player[0][playerid], 0);
		PlayerTextDrawSetOutline(playerid, voice_setting_player[0][playerid], 0);
		PlayerTextDrawFont(playerid, voice_setting_player[0][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, voice_setting_player[0][playerid], true);
	}
	if(voice_setting_player[1][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		voice_setting_player[1][playerid] = CreatePlayerTextDraw(playerid, 260.333312, 214.044448, "brilliantother:voice_setting_25_select"); // Texture element
		PlayerTextDrawLetterSize(playerid, voice_setting_player[1][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, voice_setting_player[1][playerid], 35.000007, 20.325925);
		PlayerTextDrawAlignment(playerid, voice_setting_player[1][playerid], 2);
		PlayerTextDrawColor(playerid, voice_setting_player[1][playerid], -1);
		PlayerTextDrawSetShadow(playerid, voice_setting_player[1][playerid], 0);
		PlayerTextDrawSetOutline(playerid, voice_setting_player[1][playerid], 0);
		PlayerTextDrawFont(playerid, voice_setting_player[1][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, voice_setting_player[1][playerid], true);
	}
	if(voice_setting_player[2][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		voice_setting_player[2][playerid] = CreatePlayerTextDraw(playerid, 304.000061, 214.044464, "brilliantother:voice_setting_50_select"); // Texture element
		PlayerTextDrawLetterSize(playerid, voice_setting_player[2][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, voice_setting_player[2][playerid], 35.000007, 20.325925);
		PlayerTextDrawAlignment(playerid, voice_setting_player[2][playerid], 2);
		PlayerTextDrawColor(playerid, voice_setting_player[2][playerid], -1);
		PlayerTextDrawSetShadow(playerid, voice_setting_player[2][playerid], 0);
		PlayerTextDrawSetOutline(playerid, voice_setting_player[2][playerid], 0);
		PlayerTextDrawFont(playerid, voice_setting_player[2][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, voice_setting_player[2][playerid], true);
	}
	if(voice_setting_player[3][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		voice_setting_player[3][playerid] = CreatePlayerTextDraw(playerid, 345.666687, 214.044479, "brilliantother:voice_setting_75_select"); // Texture element
		PlayerTextDrawLetterSize(playerid, voice_setting_player[3][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, voice_setting_player[3][playerid], 33.333347, 19.911117);
		PlayerTextDrawAlignment(playerid, voice_setting_player[3][playerid], 2);
		PlayerTextDrawColor(playerid, voice_setting_player[3][playerid], -1);
		PlayerTextDrawSetShadow(playerid, voice_setting_player[3][playerid], 0);
		PlayerTextDrawSetOutline(playerid, voice_setting_player[3][playerid], 0);
		PlayerTextDrawFont(playerid, voice_setting_player[3][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, voice_setting_player[3][playerid], true);
	}
	if(voice_setting_player[4][playerid] == PlayerText:INVALID_TEXT_DRAW)
	{
		voice_setting_player[4][playerid] = CreatePlayerTextDraw(playerid, 260.333404, 239.762954, "brilliantother:voice_setting_100_select"); // Texture element
		PlayerTextDrawLetterSize(playerid, voice_setting_player[4][playerid], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, voice_setting_player[4][playerid], 119.666664, 24.474092);
		PlayerTextDrawAlignment(playerid, voice_setting_player[4][playerid], 2);
		PlayerTextDrawColor(playerid, voice_setting_player[4][playerid], -1);
		PlayerTextDrawSetShadow(playerid, voice_setting_player[4][playerid], 0);
		PlayerTextDrawSetOutline(playerid, voice_setting_player[4][playerid], 0);
		PlayerTextDrawFont(playerid, voice_setting_player[4][playerid], 4);
		PlayerTextDrawSetSelectable(playerid, voice_setting_player[4][playerid], true);
	}

	return true;
}

stock create_voice_td()
{
	voice_global_td[0] = TextDrawCreate(257.666534, 135.229660, "brilliantother:voice_setting_background"); // Texture element
	TextDrawLetterSize(voice_global_td[0], 0.000000, 0.000000);
	TextDrawTextSize(voice_global_td[0], 125.000007, 168.829605);
	TextDrawAlignment(voice_global_td[0], 2);
	TextDrawColor(voice_global_td[0], -1);
	TextDrawSetShadow(voice_global_td[0], 0);
	TextDrawSetOutline(voice_global_td[0], 0);
	TextDrawFont(voice_global_td[0], 4);

	voice_global_td[1] = TextDrawCreate(356.333343, 137.303710, "brilliantother:voice_close_button"); // Texture element
	TextDrawLetterSize(voice_global_td[1], 0.000000, 0.000000);
	TextDrawTextSize(voice_global_td[1], 24.999971, 18.251855);
	TextDrawAlignment(voice_global_td[1], 2);
	TextDrawColor(voice_global_td[1], -1);
	TextDrawSetShadow(voice_global_td[1], 0);
	TextDrawSetOutline(voice_global_td[1], 0);
	TextDrawFont(voice_global_td[1], 4);
	TextDrawSetSelectable(voice_global_td[1], true);

	voice_global_td[2] = TextDrawCreate(260.666595, 137.718521, "brilliantother:voice_setting_name"); // Texture element
	TextDrawLetterSize(voice_global_td[2], 0.000000, 0.000000);
	TextDrawTextSize(voice_global_td[2], 81.666610, 18.251867);
	TextDrawAlignment(voice_global_td[2], 2);
	TextDrawColor(voice_global_td[2], -1);
	TextDrawUseBox(voice_global_td[2], true);
	TextDrawBoxColor(voice_global_td[2], 0);
	TextDrawSetShadow(voice_global_td[2], 0);
	TextDrawSetOutline(voice_global_td[2], 0);
	TextDrawFont(voice_global_td[2], 4);

	voice_global_td[3] = TextDrawCreate(260.999969, 172.977752, "brilliantother:voice_setting_micro_text"); // Texture element
	TextDrawLetterSize(voice_global_td[3], 0.000000, 0.000000);
	TextDrawTextSize(voice_global_td[3], 37.666656, 9.125932);
	TextDrawAlignment(voice_global_td[3], 1);
	TextDrawColor(voice_global_td[3], -1);
	TextDrawSetShadow(voice_global_td[3], 0);
	TextDrawSetOutline(voice_global_td[3], 0);
	TextDrawFont(voice_global_td[3], 4);

	voice_global_td[4] = TextDrawCreate(261.666717, 196.622177, "brilliantother:voice_setting_volume_text"); // Texture element
	TextDrawLetterSize(voice_global_td[4], 0.000000, 0.000000);
	TextDrawTextSize(voice_global_td[4], 66.333290, 7.881487);
	TextDrawAlignment(voice_global_td[4], 1);
	TextDrawColor(voice_global_td[4], -1);
	TextDrawSetShadow(voice_global_td[4], 0);
	TextDrawSetOutline(voice_global_td[4], 0);
	TextDrawFont(voice_global_td[4], 4);

	voice_global_td[5] = TextDrawCreate(260.666687, 267.970367, "brilliantother:voice_setting_button_save"); // Texture element
	TextDrawLetterSize(voice_global_td[5], 0.000000, 0.000000);
	TextDrawTextSize(voice_global_td[5], 119.333297, 29.866661);
	TextDrawAlignment(voice_global_td[5], 2);
	TextDrawColor(voice_global_td[5], -1);
	TextDrawSetShadow(voice_global_td[5], 0);
	TextDrawSetOutline(voice_global_td[5], 0);
	TextDrawFont(voice_global_td[5], 4);
	TextDrawSetSelectable(voice_global_td[5], true);

	return true;

}

stock PlayerTextDrawHideEx(playerid, &PlayerText:id)
{
	if(id != PlayerText:INVALID_TEXT_DRAW)
	{	

		PlayerTextDrawHide(playerid, id);
		PlayerTextDrawDestroy(playerid, id);
		id = PlayerText:INVALID_TEXT_DRAW;
	}
	return true;
}