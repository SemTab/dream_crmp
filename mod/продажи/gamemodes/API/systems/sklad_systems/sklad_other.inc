callback:: load_sklad_server()
{

	new Result:load_sklad_servers = sql_queryEx(zConn, "SELECT * FROM `sklad` ORDER BY `sklad_id`", QUERY_CACHED);

	new all_sklad_server = sql_num_rows(load_sklad_servers);

	new time = GetTickCount();


 	for(new i; i < all_sklad_server; i++)
	{

		sklad[i][sklad_other_id]  = sql_get_field_assoc_int_ex(load_sklad_servers, i, "sklad_id"); 

		sklad[i][sklad_other_count_1]  = sql_get_field_assoc_int_ex(load_sklad_servers, i, "sklad_other_count_1"); 
		sklad[i][sklad_other_count_2]  = sql_get_field_assoc_int_ex(load_sklad_servers, i, "sklad_other_count_2"); 
		sklad[i][sklad_other_count_3]  = sql_get_field_assoc_int_ex(load_sklad_servers, i, "sklad_other_count_3"); 
		sklad[i][sklad_other_count_4]  = sql_get_field_assoc_int_ex(load_sklad_servers, i, "sklad_other_count_4"); 
		sklad[i][sklad_other_count_5]  = sql_get_field_assoc_int_ex(load_sklad_servers, i, "sklad_other_count_5"); 
		sklad[i][sklad_other_count_6]  = sql_get_field_assoc_int_ex(load_sklad_servers, i, "sklad_other_count_6"); 

		load_sklad_server_count++;

	}

	create_3d_text_sklad();

	printf("[Склады]: <%i из %i>. Времени затрачено: <%d мс>" , all_sklad_server, load_sklad_server_count, GetTickCount()-  time);
	sql_next_row(load_sklad_servers);

	return true;
}


stock save_sklad_all()
{
	for(new i; i < load_sklad_server_count; i++)
	{

		format(String1024, sizeof(String1024), "\
			UPDATE sklad SET \
			sklad_other_count_1 = '%d', \
			sklad_other_count_2 = '%d', \
			sklad_other_count_3 = '%d', \
			sklad_other_count_4 = '%d', \
			sklad_other_count_5 = '%d', \
			sklad_other_count_6 = '%d' \
			WHERE sklad_id = '%d'",

			sklad[i][sklad_other_count_1],
			sklad[i][sklad_other_count_2],
			sklad[i][sklad_other_count_3],
			sklad[i][sklad_other_count_4],
			sklad[i][sklad_other_count_5],
			sklad[i][sklad_other_count_6]
			,i);

		sql_queryEx(zConn, String1024, QUERY_THREADED);	
	}
	return true;

}

stock create_3d_text_sklad()
{

	format(String512, sizeof(String512), "\
		Склад "cLRED"«Шахты»\n\
		\t"cLRED"Остальная информация:\n\n\
		"cLRED"Объем склада:\n\n\
		"cWH"Уголь - "cLRED"%d кг\n\
		"cWH"Железо - "cLRED"%d кг\n\
		"cWH"Медь - "cLRED"%d кг\n\
		"cWH"Алмазов - "cLRED"%d кг\n\
		"cWH"Золота - "cLRED"%d кг\n\n\
		"cWH"Объем склада: "cLRED"%d кг",
		sklad[0][sklad_other_count_1],
		sklad[0][sklad_other_count_2],
		sklad[0][sklad_other_count_3],
		sklad[0][sklad_other_count_4],
		sklad[0][sklad_other_count_5],
		sklad[0][sklad_other_count_1]+sklad[0][sklad_other_count_2]+sklad[0][sklad_other_count_3]
		+ sklad[0][sklad_other_count_4] + sklad[0][sklad_other_count_5] + sklad[0][sklad_other_count_6]
		);

	sklad_pick_info_miner[0] = CreateDynamic3DTextLabel(String512, -1, -1422.9141,2576.1584,40.3924+1.0, 20.0);

	format(String512, sizeof(String512), "\
		Склад "cLRED"«Шахты»\n\
		\t"cLRED"Остальная информация:\n\n\
		"cLRED"Объем склада:\n\n\
		"cWH"Уголь - "cLRED"%d кг\n\
		"cWH"Железо - "cLRED"%d кг\n\
		"cWH"Медь - "cLRED"%d кг\n\
		"cWH"Алмазов - "cLRED"%d кг\n\
		"cWH"Золота - "cLRED"%d кг\n\n\
		"cWH"Объем склада: "cLRED"%d кг",
		sklad[0][sklad_other_count_1],
		sklad[0][sklad_other_count_2],
		sklad[0][sklad_other_count_3],
		sklad[0][sklad_other_count_4],
		sklad[0][sklad_other_count_5],
		sklad[0][sklad_other_count_1]+sklad[0][sklad_other_count_2]+sklad[0][sklad_other_count_3]
		+ sklad[0][sklad_other_count_4] + sklad[0][sklad_other_count_5] + sklad[0][sklad_other_count_6]
		);

	sklad_pick_info_miner[1] = CreateDynamic3DTextLabel(String512, -1, -1445.1978,2593.2583,41.0050+1.0, 20.0);


	format(String512, sizeof(String512), "\
		Склад "cLRED"«Шахты»\n\
		\t"cLRED"Остальная информация:\n\n\
		"cLRED"Объем склада:\n\n\
		"cWH"Уголь - "cLRED"%d кг\n\
		"cWH"Железо - "cLRED"%d кг\n\
		"cWH"Медь - "cLRED"%d кг\n\
		"cWH"Алмазов - "cLRED"%d кг\n\
		"cWH"Золота - "cLRED"%d кг\n\n\
		"cWH"Объем склада: "cLRED"%d кг",
		sklad[0][sklad_other_count_1],
		sklad[0][sklad_other_count_2],
		sklad[0][sklad_other_count_3],
		sklad[0][sklad_other_count_4],
		sklad[0][sklad_other_count_5],
		sklad[0][sklad_other_count_1]+sklad[0][sklad_other_count_2]+sklad[0][sklad_other_count_3]
		+ sklad[0][sklad_other_count_4] + sklad[0][sklad_other_count_5] + sklad[0][sklad_other_count_6]
		);

	sklad_pick_info_miner[2] = CreateDynamic3DTextLabel(String512, -1, -1435.8590,2559.5706,40.7999+1.0, 20.0);

	format(String512, sizeof(String512), "\
		Склад "cLRED"«Шахты»\n\
		\t"cLRED"Остальная информация:\n\n\
		"cLRED"Объем склада:\n\n\
		"cWH"Уголь - "cLRED"%d кг\n\
		"cWH"Железо - "cLRED"%d кг\n\
		"cWH"Медь - "cLRED"%d кг\n\
		"cWH"Алмазов - "cLRED"%d кг\n\
		"cWH"Золота - "cLRED"%d кг\n\n\
		"cWH"Объем склада: "cLRED"%d кг",
		sklad[0][sklad_other_count_1],
		sklad[0][sklad_other_count_2],
		sklad[0][sklad_other_count_3],
		sklad[0][sklad_other_count_4],
		sklad[0][sklad_other_count_5],
		sklad[0][sklad_other_count_1]+sklad[0][sklad_other_count_2]+sklad[0][sklad_other_count_3]
		+ sklad[0][sklad_other_count_4] + sklad[0][sklad_other_count_5] + sklad[0][sklad_other_count_6]
		);

	sklad_pick_info_miner[3] = CreateDynamic3DTextLabel(String512, -1, -1454.7086,2580.2617,40.7999+1.0, 20.0);



	format(String512, sizeof(String512), "\
		Склад "cLRED"«Лесопилки»\n\
		\t"cLRED"Остальная информация:\n\n\
		"cLRED"Объем склада:\n\n\
		"cWH"Дерева - "cLRED"%d кг\n\
		"cWH"Объем склада: "cLRED"%d кг",
		sklad[1][sklad_other_count_1], sklad[1][sklad_other_count_1]
		);

	sklad_pick_info_wood = CreateDynamic3DTextLabel(String512, -1, -1077.3804,-2483.7205,28.5368+1.0, 20.0);


	format(String512, sizeof(String512), "\
		Склад "cLRED"«Завод»\n\
		\t"cLRED"Остальная информация:\n\n\
		"cLRED"Объем склада:\n\n\
		"cWH"Товара - "cLRED"%d кг\n\
		"cWH"Объем склада: "cLRED"%d кг",
		sklad[2][sklad_other_count_1], sklad[2][sklad_other_count_1]
		);

	sklad_pick_info_factory[0] = CreateDynamic3DTextLabel(String512, -1, 2319.3545,2023.8629,15.9863+1.0, 20.0);


	format(String512, sizeof(String512), "\
		Склад "cLRED"«Завод»\n\
		\t"cLRED"Остальная информация:\n\n\
		"cLRED"Объем склада:\n\n\
		"cWH"Товара - "cLRED"%d кг\n\
		"cWH"Объем склада: "cLRED"%d кг",
		sklad[2][sklad_other_count_1], sklad[2][sklad_other_count_1]
		);

	sklad_pick_info_factory[1] = CreateDynamic3DTextLabel(String512, -1, 2303.3013,2008.4215,15.9863+1.0, 20.0);




	return true;
} 

stock update_sklad_3d_text()
{



	format(String512, sizeof(String512), "\
		Склад "cLRED"«Шахты»\n\
		\t"cLRED"Остальная информация:\n\n\
		"cLRED"Объем склада:\n\n\
		"cWH"Уголь - "cLRED"%d кг\n\
		"cWH"Железо - "cLRED"%d кг\n\
		"cWH"Медь - "cLRED"%d кг\n\
		"cWH"Алмазов - "cLRED"%d кг\n\
		"cWH"Золота - "cLRED"%d кг\n\n\
		"cWH"Объем склада: "cLRED"%d кг",
		sklad[0][sklad_other_count_1],
		sklad[0][sklad_other_count_2],
		sklad[0][sklad_other_count_3],
		sklad[0][sklad_other_count_4],
		sklad[0][sklad_other_count_5],
		sklad[0][sklad_other_count_1]+sklad[0][sklad_other_count_2]+sklad[0][sklad_other_count_3]
		+ sklad[0][sklad_other_count_4] + sklad[0][sklad_other_count_5] + sklad[0][sklad_other_count_6]
		);

	UpdateDynamic3DTextLabelText(sklad_pick_info_miner[0], -1, String512);	

	format(String512, sizeof(String512), "\
		Склад "cLRED"«Шахты»\n\
		\t"cLRED"Остальная информация:\n\n\
		"cLRED"Объем склада:\n\n\
		"cWH"Уголь - "cLRED"%d кг\n\
		"cWH"Железо - "cLRED"%d кг\n\
		"cWH"Медь - "cLRED"%d кг\n\
		"cWH"Алмазов - "cLRED"%d кг\n\
		"cWH"Золота - "cLRED"%d кг\n\n\
		"cWH"Объем склада: "cLRED"%d кг",
		sklad[0][sklad_other_count_1],
		sklad[0][sklad_other_count_2],
		sklad[0][sklad_other_count_3],
		sklad[0][sklad_other_count_4],
		sklad[0][sklad_other_count_5],
		sklad[0][sklad_other_count_1]+sklad[0][sklad_other_count_2]+sklad[0][sklad_other_count_3]
		+ sklad[0][sklad_other_count_4] + sklad[0][sklad_other_count_5] + sklad[0][sklad_other_count_6]
		);

	UpdateDynamic3DTextLabelText(sklad_pick_info_miner[1], -1, String512);	

	format(String512, sizeof(String512), "\
		Склад "cLRED"«Шахты»\n\
		\t"cLRED"Остальная информация:\n\n\
		"cLRED"Объем склада:\n\n\
		"cWH"Уголь - "cLRED"%d кг\n\
		"cWH"Железо - "cLRED"%d кг\n\
		"cWH"Медь - "cLRED"%d кг\n\
		"cWH"Алмазов - "cLRED"%d кг\n\
		"cWH"Золота - "cLRED"%d кг\n\n\
		"cWH"Объем склада: "cLRED"%d кг",
		sklad[0][sklad_other_count_1],
		sklad[0][sklad_other_count_2],
		sklad[0][sklad_other_count_3],
		sklad[0][sklad_other_count_4],
		sklad[0][sklad_other_count_5],
		sklad[0][sklad_other_count_1]+sklad[0][sklad_other_count_2]+sklad[0][sklad_other_count_3]
		+ sklad[0][sklad_other_count_4] + sklad[0][sklad_other_count_5] + sklad[0][sklad_other_count_6]
		);

	UpdateDynamic3DTextLabelText(sklad_pick_info_miner[2], -1, String512);	

	format(String512, sizeof(String512), "\
		Склад "cLRED"«Шахты»\n\
		\t"cLRED"Остальная информация:\n\n\
		"cLRED"Объем склада:\n\n\
		"cWH"Уголь - "cLRED"%d кг\n\
		"cWH"Железо - "cLRED"%d кг\n\
		"cWH"Медь - "cLRED"%d кг\n\
		"cWH"Алмазов - "cLRED"%d кг\n\
		"cWH"Золота - "cLRED"%d кг\n\n\
		"cWH"Объем склада: "cLRED"%d кг",
		sklad[0][sklad_other_count_1],
		sklad[0][sklad_other_count_2],
		sklad[0][sklad_other_count_3],
		sklad[0][sklad_other_count_4],
		sklad[0][sklad_other_count_5],
		sklad[0][sklad_other_count_1]+sklad[0][sklad_other_count_2]+sklad[0][sklad_other_count_3]
		+ sklad[0][sklad_other_count_4] + sklad[0][sklad_other_count_5] + sklad[0][sklad_other_count_6]
		);

	UpdateDynamic3DTextLabelText(sklad_pick_info_miner[3], -1, String512);	


	format(String512, sizeof(String512), "\
		Склад "cLRED"«Лесопилки»\n\
		\t"cLRED"Остальная информация:\n\n\
		"cLRED"Объем склада:\n\n\
		"cWH"Дерева - "cLRED"%d кг\n\
		"cWH"Объем склада: "cLRED"%d кг",
		sklad[1][sklad_other_count_1], sklad[1][sklad_other_count_1]
		);
	UpdateDynamic3DTextLabelText(sklad_pick_info_wood, -1, String512);	

	format(String512, sizeof(String512), "\
		Склад "cLRED"«Завод»\n\
		\t"cLRED"Остальная информация:\n\n\
		"cLRED"Объем склада:\n\n\
		"cWH"Товара - "cLRED"%d кг\n\
		"cWH"Объем склада: "cLRED"%d кг",
		sklad[2][sklad_other_count_1], sklad[2][sklad_other_count_1]
		);

	UpdateDynamic3DTextLabelText(sklad_pick_info_factory[0], -1, String512);	

	format(String512, sizeof(String512), "\
		Склад "cLRED"«Завод»\n\
		\t"cLRED"Остальная информация:\n\n\
		"cLRED"Объем склада:\n\n\
		"cWH"Товара - "cLRED"%d кг\n\
		"cWH"Объем склада: "cLRED"%d кг",
		sklad[2][sklad_other_count_1], sklad[2][sklad_other_count_1]
		);

	UpdateDynamic3DTextLabelText(sklad_pick_info_factory[1], -1, String512);	




	return true;
}
