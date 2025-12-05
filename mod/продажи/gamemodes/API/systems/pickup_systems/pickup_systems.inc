
stock create_int_pickup()
{	
	// ОПГ

	CreateDynamicPickup(13702, 23, 2416.6763,-1926.1644,22.0043, -1); // Тамбовская
	CreateDynamicPickup(13702, 23, -288.6724,514.6025,13.2384, -1); // Курганская
	CreateDynamicPickup(13702, 23, 1800.2272,2201.6426,15.6253, -1); // Измайловская


	CreateDynamic3DTextLabel(""cWH"Тамбовская ОПГ\n"cBLUE"[Встаньте на пикап]",-1, \
	2416.6763,-1926.1644,22.0043, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	
	CreateDynamic3DTextLabel(""cWH"Курганская ОПГ\n"cBLUE"[Встаньте на пикап]",-1, \
	-288.6724,514.6025,13.2384, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	
	CreateDynamic3DTextLabel(""cWH"Измайловская ОПГ\n"cBLUE"[Встаньте на пикап]",-1, \
	1800.2272,2201.6426,15.6253, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	

	CreateDynamic3DTextLabel(""cWH"Выход из дома\n"cBLUE"[Встаньте на пикап]",-1, \
	801.4581,-961.9263,1205.9318, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, -1);	
	CreateDynamicPickup(13702, 23, 801.4581,-961.9263,1205.9318, -1);

	// На улице

  	pickup_mafia_ext[0] = CreateDynamicSphere(2416.6763,-1926.1644,22.0043, 1.5, -1);
  	pickup_mafia_ext[1] = CreateDynamicSphere(-288.6724,514.6025,13.2384, 1.5, -1);
  	pickup_mafia_ext[2] = CreateDynamicSphere(1800.2272,2201.6426,15.6253, 1.5, -1);

  	// В инте

  	pickup_mafia_ext[3] = CreateDynamicSphere(801.4581,-961.9263,1205.9318, 1.5, 10);
  	pickup_mafia_ext[4] = CreateDynamicSphere(801.4581,-961.9263,1205.9318, 1.5, 11);
  	pickup_mafia_ext[5] = CreateDynamicSphere(801.4581,-961.9263,1205.9318, 1.5, 12);


	// Москоу Сити

	CreateDynamicPickup(13702, 23, 503.1559,-376.5434,1201.9318, -1);
	CreateDynamicPickup(13702, 23, -116.8536,-136.5693,12.9284, -1);
	CreateDynamicPickup(13702, 23, 501.3041,-364.3341,1201.9318, 1);

	CreateDynamic3DTextLabel(""cWH"Апартаменты Москва-Сити\n"cBLUE"[Встаньте на пикап]",-1, \
	-116.8536,-136.5693,12.9284, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	

	CreateDynamic3DTextLabel(""cWH"Выход из апартаментов\n"cBLUE"[Встаньте на пикап]",-1, \
	501.3041,-364.3341,1201.9318, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, -1);	

	CreateDynamic3DTextLabel(""cWH"Лифт\n"cBLUE"[Встаньте на пикап]",-1, \
	503.1559,-376.5434,1201.9318, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	

  	pickup_int_apartament[0] = CreateDynamicSphere(-116.8536,-136.5693,12.9284, 1.0, -1);
  	pickup_int_apartament[1] = CreateDynamicSphere(501.3041,-364.3341,1201.9318, 1.0, 1);
  	pickup_int_apartament[2] = CreateDynamicSphere(503.1559,-376.5434,1201.9318, 0.5, -1);

	// Завод

	CreateDynamicPickup(13702, 23, 2318.6421,2031.7903,15.9863, -1);
	CreateDynamicPickup(13702, 23, 695.0161,1290.7266,1746.4340, -1);

	CreateDynamic3DTextLabel(""cWH"Завод\n"cBLUE"[Встаньте на пикап]",-1, \
	2318.6421,2031.7903,15.9863, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	

	CreateDynamic3DTextLabel(""cWH"Выход с завода\n"cBLUE"[Встаньте на пикап]",-1, \
	695.0161,1290.7266,1746.4340, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 3, -1);	


  	pickup_int_zavod[0] = CreateDynamicSphere(2318.6421,2031.7903,15.9863, 1.0, -1);
  	pickup_int_zavod[1] = CreateDynamicSphere(695.0161,1290.7266,1746.4340, 1.0, 3);

	// Армия


	CreateDynamicPickup(13702, 23, 1816.7385,1783.7101,15.6181, -1);
	CreateDynamicPickup(13702, 23, -1834.5908,-1980.8821,-0.5234, -1);

	CreateDynamic3DTextLabel(""cWH"Казарма\n"cBLUE"[Встаньте на пикап]",-1, \
	1816.7385,1783.7101,15.6181, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	

	CreateDynamic3DTextLabel(""cWH"Выход из казармы\n"cBLUE"[Встаньте на пикап]",-1, \
	-1834.5908,-1980.8821,-0.5234, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 3, -1);	


  	pickup_int_army[0] = CreateDynamicSphere(1816.7385,1783.7101,15.6181, 1.0, -1);
  	pickup_int_army[1] = CreateDynamicSphere(-1834.5908,-1980.8821,-0.5234, 1.0, 3);
	

  	// Новогодняя аллея

	CreateDynamicPickup(13702, 23, 1203.5774,886.9219,16.0000, -1); // Вход из резиданции
	CreateDynamicPickup(13702, 23, -428.1120,732.6202,1201.9314, -1);  // Внутри резиденции
	CreateDynamicPickup(13702, 23, 1138.2224,812.9908,12.2500, -1);
	CreateDynamicPickup(13702, 23, -204.1012,371.8457,1202.1244, -1);

	CreateDynamic3DTextLabel(""cWH"Вход в резиденцию\n"cBLUE"[Встаньте на пикап]",-1, \
	1203.5774,886.9219,16.0000, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	 // Вход из резиданции
	CreateDynamic3DTextLabel(""cWH"Выход в резиденции\n"cBLUE"[Встаньте на пикап]",-1, \
	-428.1120,732.6202,1201.9314, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	

	CreateDynamic3DTextLabel(""cWH"Вход в кафе\n"cBLUE"[Встаньте на пикап]",-1, \
	1138.2224,812.9908,12.2500, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	
	CreateDynamic3DTextLabel(""cWH"Выход в кафе\n"cBLUE"[Встаньте на пикап]",-1, \
	-204.1012,371.8457,1202.1244, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	


  	pickup_in_newyear[0] = CreateDynamicSphere(1203.5774,886.9219,16.0000, 1.0, -1); // Вход из резиданции
  	pickup_in_newyear[1] = CreateDynamicSphere(-428.1120,732.6202,1201.9314, 1.0, -1); // Внутри резиденции
  	pickup_in_newyear[2] = CreateDynamicSphere(1138.2224,812.9908,12.2500, 1.0, -1);
  	pickup_in_newyear[3] = CreateDynamicSphere(-204.1012,371.8457,1202.1244, 1.0, -1);

  	// Армия КПП

	CreateDynamicPickup(13702, 23, 1886.6792,1730.6407,15.5142, -1);
	CreateDynamicPickup(13702, 23, 1892.2473,1732.1053,15.6192, -1);

	CreateDynamic3DTextLabel(""cWH"КПП Армии\n"cBLUE"[Встаньте на пикап]",-1, \
	1886.6792,1730.6407,15.5142, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	
	CreateDynamic3DTextLabel(""cWH"КПП Армии\n"cBLUE"[Встаньте на пикап]",-1, \
	1892.2473,1732.1053,15.6192, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	

  	pickup_int_army[2] = CreateDynamicSphere(1886.6792,1730.6407,15.5142, 1.0, -1);
  	pickup_int_army[3] = CreateDynamicSphere(1892.2473,1732.1053,15.6192, 1.0, -1);
	
  	// Склад

	CreateDynamicPickup(13702, 23, 1746.5321,1735.8169,15.6126, -1);
	CreateDynamicPickup(13702, 23, -1579.0813,467.1398,43.3883, -1);

	CreateDynamic3DTextLabel(""cWH"Склад Армии\n"cBLUE"[Встаньте на пикап]",-1, \
	1746.5321,1735.8169,15.6126, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	
	CreateDynamic3DTextLabel(""cWH"Выход со склада\n"cBLUE"[Встаньте на пикап]",-1, \
	-1579.0813,467.1398,43.3883, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	

  	pickup_int_army[4] = CreateDynamicSphere(1746.5321,1735.8169,15.6126, 1.0, -1);
  	pickup_int_army[5] = CreateDynamicSphere(-1579.0813,467.1398,43.3883, 1.0, -1);
	


	// Радиоцентр РИТМ


	CreateDynamicPickup(13702, 23, -317.8804,816.2248,13.0635, -1);
	CreateDynamicPickup(13702, 23, -2672.5315,-1821.2360,4.1045, -1);

	CreateDynamic3DTextLabel(""cWH"Радиоцентр Ритм\n"cBLUE"[Встаньте на пикап]",-1, \
	-317.8804,816.2248,13.0635, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	

	CreateDynamic3DTextLabel(""cWH"Выход из Радиоцентра\n"cBLUE"[Встаньте на пикап]",-1, \
	-2672.5315,-1821.2360,4.1045, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 3, -1);	


  	pickup_int_news[0] = CreateDynamicSphere(-317.8804,816.2248,13.0635, 1.0, -1);
  	pickup_int_news[1] = CreateDynamicSphere(-2672.5315,-1821.2360,4.1045, 1.0, 3);
	

	// Радиоцентр Останкино


	CreateDynamicPickup(13702, 23, 2126.6147,-1962.8440,20.3229, -1);

	CreateDynamic3DTextLabel(""cWH"ТРК Останкино\n"cBLUE"[Встаньте на пикап]",-1, \
	2126.6147,-1962.8440,20.3229, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	

	CreateDynamic3DTextLabel(""cWH"Выход из Радиоцентра\n"cBLUE"[Встаньте на пикап]",-1, \
	-2672.5315,-1821.2360,4.1045, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 4, -1);	


  	pickup_int_news[2] = CreateDynamicSphere(2126.6147,-1962.8440,20.3229, 1.0, -1);
  	pickup_int_news[3] = CreateDynamicSphere(-2672.5315,-1821.2360,4.1045, 1.0, 4);
	


	// ФСБ


	CreateDynamicPickup(13702, 23, 522.5934,300.6388,13.6113, -1);
	CreateDynamicPickup(13702, 23, 1262.9530,-212.1752,1201.9819, -1);


	CreateDynamicPickup(13702, 23, 1325.4434,-191.6701,1201.9819, -1);
	CreateDynamicPickup(13702, 23, 536.1949,270.6898,13.6056, -1);

	CreateDynamic3DTextLabel(""cWH"ФСБ г.Арзамас\n"cBLUE"[Встаньте на пикап]",-1, \
	522.5934,300.6388,13.6113, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	
	CreateDynamic3DTextLabel(""cWH"ФСБ г.Арзамас\n"cBLUE"[Встаньте на пикап]",-1, \
	536.1949,270.6898,13.6056, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	

	CreateDynamic3DTextLabel(""cWH"Выход из ФСБ\n"cBLUE"[Встаньте на пикап]",-1, \
	1262.9530,-212.1752,1201.9819, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 3, -1);	

	CreateDynamic3DTextLabel(""cWH"Выход из ФСБ\n"cBLUE"[Встаньте на пикап]",-1, \
	1325.4434,-191.6701,1201.9819, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 3, -1);	


  	pickup_int_federal[0] = CreateDynamicSphere(522.5934,300.6388,13.6113, 1.0, -1);
  	pickup_int_federal[1] = CreateDynamicSphere(1262.9530,-212.1752,1201.9819, 1.0, 3);
	pickup_int_federal[2] = CreateDynamicSphere(1325.4434,-191.6701,1201.9819, 1.0, 3);
	pickup_int_federal[3] = CreateDynamicSphere(536.1949,270.6898,13.6056, 1.0, -1);

	// Администрация


	CreateDynamicPickup(13702, 23, -73.8339,855.6837,12.5978, -1);
	CreateDynamicPickup(13702, 23, 688.8303,-30.5752,1201.8580, -1);

	CreateDynamic3DTextLabel(""cWH"Мэрия г.Арзамас\n"cBLUE"[Встаньте на пикап]",-1, \
	-73.8339,855.6837,12.5978, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	

	CreateDynamic3DTextLabel(""cWH"Выход из мэрии\n"cBLUE"[Встаньте на пикап]",-1, \
	688.8303,-30.5752,1201.8580, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 3, -1);	


  	pickup_int_meria[0] = CreateDynamicSphere(-73.8339,855.6837,12.5978, 1.0, -1);
  	pickup_int_meria[1] = CreateDynamicSphere(688.8303,-30.5752,1201.8580, 1.0, 3);
	

	// ПОЛИЦИЯ (АРЗАМАС)

	// Выход/Вход первый этаж

  	pickup_int_pd[0] = CreateDynamicSphere(150.8439,1263.3525,13.2951, 1.0, -1);
  	pickup_int_pd[1] = CreateDynamicSphere(541.3398,311.5468,1201.8594, 1.0, 1);
	
	// Вход второй этаж

  	pickup_int_pd[2] = CreateDynamicSphere(546.1693,348.4496,1205.6250, 0.5, 1);
  	pickup_int_pd[3] = CreateDynamicSphere(536.1170,348.4497,1205.6250, 0.5, 1);

  	// Выход второй этаж

  	pickup_int_pd[4] = CreateDynamicSphere(-958.1960,27.0175,1205.0167, 0.5, 1);
  	pickup_int_pd[5] = CreateDynamicSphere(-968.4746,27.0180,1205.0167, 0.5, 1);


	CreateDynamicPickup(13702, 23, 150.8439,1263.3525,13.2951, -1);
	CreateDynamicPickup(13702, 23, 541.3398,311.5468,1201.8594, -1);	
	CreateDynamicPickup(13702, 23, 546.1693,348.4496,1205.6250, -1);
	CreateDynamicPickup(13702, 23, 536.1170,348.4497,1205.6250, -1);

	CreateDynamicPickup(13702, 23, -958.1960,27.0175,1205.0167, -1);
	CreateDynamicPickup(13702, 23, -968.4746,27.0180,1205.0167, -1);


	CreateDynamic3DTextLabel(""cWH"Полицейский Участок\n"cBLUE"[Встаньте на пикап]",-1, \
	150.8439,1263.3525,13.2951, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	CreateDynamic3DTextLabel(""cWH"Выход из участка\n"cBLUE"[Встаньте на пикап]",-1, \
	541.3398,311.5468,1201.8594, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, -1, -1);	


	// ПОЛИЦИЯ (ЮЖНЫЙ)

	// Выход/Вход первый этаж

  	pickup_int_pd_2[0] = CreateDynamicSphere(2575.9224,-2416.0825,22.4946, 1.0, -1);
  	pickup_int_pd_2[1] = CreateDynamicSphere(541.3398,311.5468,1201.8594, 1.0, 2);
	
	// Вход второй этаж

  	pickup_int_pd_2[2] = CreateDynamicSphere(546.1693,348.4496,1205.6250, 0.5, 2);
  	pickup_int_pd_2[3] = CreateDynamicSphere(536.1170,348.4497,1205.6250, 0.5, 2);

  	// Выход второй этаж

  	pickup_int_pd_2[4] = CreateDynamicSphere(-958.1960,27.0175,1205.0167, 0.5, 2);
  	pickup_int_pd_2[5] = CreateDynamicSphere(-968.4746,27.0180,1205.0167, 0.5, 2);


	CreateDynamicPickup(13702, 23, 2575.9224,-2416.0825,22.4946, -1);

	CreateDynamic3DTextLabel(""cWH"Полицейский Участок\n"cBLUE"[Встаньте на пикап]",-1, \
	2575.9224,-2416.0825,22.4946, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	



	// БАНКИ

	CreateDynamicPickup(13702, 23, 1850.4344,2035.0087,16.9742, -1); // Банк Батырево
	CreateDynamicPickup(13702, 23, 2376.6692,-2139.2595,22.0776, -1); // Банк Южный
	CreateDynamicPickup(13702, 23, 363.4449,1366.9894,11.8959, -1); // Банк Арзамас

	CreateDynamicPickup(13702, 23, -89.0847,722.9745,1600.1958, -1); // В интерьере банка

	CreateDynamic3DTextLabel(""cWH"Банк пгт.Батырево\n"cBLUE"[Встаньте на пикап]",-1, \
	1850.4344,2035.0087,16.9742, 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	CreateDynamic3DTextLabel(""cWH"Банк г.Южный\n"cBLUE"[Встаньте на пикап]",-1, \
	2376.6692,-2139.2595,22.0776, 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	CreateDynamic3DTextLabel(""cWH"Банк г.Арзамас\n"cBLUE"[Встаньте на пикап]",-1, \
	363.4449,1366.9894,11.8959, 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	

	CreateDynamic3DTextLabel(""cWH"Выход из банка\n"cBLUE"[Встаньте на пикап]",-1, \
	-89.0847,722.9745,1600.1958, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	

  	pickup_int_bank_1[0] = CreateDynamicSphere(1850.4344,2035.0087,16.9742, 1.0, -1);
  	pickup_int_bank_1[1] = CreateDynamicSphere(-89.0847,722.9745,1600.1958, 1.0, VIRTUAL_WORLD_BANK_1);

  	pickup_int_bank_2[0] = CreateDynamicSphere(2376.6692,-2139.2595,22.0776, 1.0, -1);
  	pickup_int_bank_2[1] = CreateDynamicSphere(-89.0847,722.9745,1600.1958, 1.0, VIRTUAL_WORLD_BANK_2);

  	pickup_int_bank_3[0] = CreateDynamicSphere(363.4449,1366.9894,11.8959, 1.0, -1);
  	pickup_int_bank_3[1] = CreateDynamicSphere(-89.0847,722.9745,1600.1958, 1.0, VIRTUAL_WORLD_BANK_3);


  	// Автошкола

	CreateDynamic3DTextLabel(""cWH"Автошкола г.Арзамас\n"cBLUE"[Встаньте на пикап]",-1, \
	-507.6881,26.4686,13.7661, 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	
	CreateDynamic3DTextLabel(""cWH"Выход из автошколы\n"cBLUE"[Встаньте на пикап]",-1, \
	-2.1278,-18.6403,1730.9814, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	

  	CreateDynamicPickup(13702, 23, -507.6881,26.4686,13.7661, -1); 
  	CreateDynamicPickup(13702, 23, -2.1278,-18.6403,1730.9814, -1); // Выход

  	pickup_int_school[0] = CreateDynamicSphere(-507.6881,26.4686,13.7661, 1.0, 0); // Вход
  	pickup_int_school[1] = CreateDynamicSphere(-2.1278,-18.6403,1730.9814, 1.0, 10); // Выход

  	// Военкомат

	CreateDynamic3DTextLabel(""cWH"Военкомат п.Батырево\n"cBLUE"[Встаньте на пикап]",-1, \
	1919.4532,2304.0400,15.5697, 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	

	CreateDynamic3DTextLabel(""cWH"Выход из военкомата\n"cBLUE"[Встаньте на пикап]",-1, \
	-213.4224,694.6388,1201.9315, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);	

  	CreateDynamicPickup(13702, 23, 1919.4532,2304.0400,15.5697, -1); 
  	CreateDynamicPickup(13702, 23, -213.4224,694.6388,1201.9315, -1); // Выход

  	pickup_int_voenkomat[0] = CreateDynamicSphere(1919.4532,2304.0400,15.5697, 1.0, 0); // Вход
  	pickup_int_voenkomat[1] = CreateDynamicSphere(-213.4224,694.6388,1201.9315, 1.0, 10); // Выход

	return true;
}

stock enter_voenkomat(playerid)
{
	SetPlayerPosEx(playerid, -213.3033,696.9980,1201.9315,359.7153);
	SetPlayerVirtualWorld(playerid, 10);
	SetCameraBehindPlayer(playerid);	
	return true;
}

stock exit_voenkomat(playerid)
{
	SetPlayerPosEx(playerid, 1917.2585,2302.5381,15.5697,117.9299);
	SetPlayerVirtualWorld(playerid, 0);
	SetCameraBehindPlayer(playerid);	
	return true;
}

stock exit_mafia_apart_1(playerid)
{
	SetPlayerPosEx(playerid, 2420.0825,-1926.1267,22.0043,271.3839);
	SetPlayerVirtualWorld(playerid, 0);
	SetCameraBehindPlayer(playerid);	
	return true;
}

stock exit_mafia_apart_2(playerid)
{
	SetPlayerPosEx(playerid, -285.7581,513.9383,13.2911,259.9610);
	SetPlayerVirtualWorld(playerid, 0);
	SetCameraBehindPlayer(playerid);	
	return true;
}

stock exit_mafia_apart_3(playerid)
{
	SetPlayerPosEx(playerid, 1800.2732,2199.1455,15.6613,184.9610);
	SetPlayerVirtualWorld(playerid, 0);
	SetCameraBehindPlayer(playerid);	
	return true;
}


stock enter_mafia_apart_1(playerid)
{
	if(!IsAMafia(playerid))
		return SCM(playerid, COLOR_GREEN, "Браток: Эй, иди отсюда, пока кости не начали пересчитывать!");

	SetPlayerPosEx(playerid, 801.4438,-963.9598,1205.9318,180.0413);
	SetPlayerVirtualWorld(playerid, 10);
	SetCameraBehindPlayer(playerid);	

	enter_mafia_pickup(playerid, 0);

	return true;
}

stock enter_mafia_apart_2(playerid)
{
	if(!IsAMafia(playerid))
		return SCM(playerid, COLOR_GREEN, "Браток: А ты смелый, я тебе щас покажу, что такой бита или макаров, стреляющий в колени!");


	SetPlayerPosEx(playerid, 801.4438,-963.9598,1205.9318,180.0413);
	SetPlayerVirtualWorld(playerid, 11);
	SetCameraBehindPlayer(playerid);	

	enter_mafia_pickup(playerid, 1);

	return true;
}

stock enter_mafia_apart_3(playerid)
{
	if(!IsAMafia(playerid))
		return SCM(playerid, COLOR_GREEN, "Браток: Чё ты сюда пришел?! Пошёл вон, пока ноги не оторвал!");


	SetPlayerPosEx(playerid, 801.4438,-963.9598,1205.9318,180.0413);
	SetPlayerVirtualWorld(playerid, 12);
	SetCameraBehindPlayer(playerid);	

	enter_mafia_pickup(playerid, 2);

	return true;
}

stock enter_kafe_neywear(playerid)
{
	SetPlayerPosEx(playerid, -205.0638,373.9714,1202.1244,2.9533);
	SetPlayerVirtualWorld(playerid, 1);
	SetCameraBehindPlayer(playerid);	

	return true;
}

stock exit_kafe_neywear(playerid)
{
	SetPlayerPosEx(playerid, 1137.4211,815.2403,12.2500,27.7360);
	SetPlayerVirtualWorld(playerid, 0);
	SetCameraBehindPlayer(playerid);	

	return true;
}

stock enter_ded_moroz_int(playerid)
{

	SetPlayerPosEx(playerid, -428.7710,734.7642,1201.9314,359.1812);
	SetPlayerVirtualWorld(playerid, 1);
	SetCameraBehindPlayer(playerid);
	return true;
}

stock exit_ded_moroz_int(playerid)
{
	SetPlayerPosEx(playerid, 1202.0323,887.5723,16.0000,67.6549);
	SetPlayerVirtualWorld(playerid, 0);
	SetCameraBehindPlayer(playerid);

	return true;
}

stock enter_apartament_1(playerid)
{
	SetPlayerPosEx(playerid, 501.2044,-366.6733,1201.9318,180.5804);
	SetPlayerVirtualWorld(playerid, 1);
	SetCameraBehindPlayer(playerid);

	return true;
}

stock exit_apartament_1(playerid)
{

	SetPlayerPosEx(playerid, -116.8996,-139.1889,12.9026,183.2334);
	SetPlayerVirtualWorld(playerid, 0);
	SetCameraBehindPlayer(playerid);
	return true;
}

stock enter_zavod(playerid)
{

	SetPlayerPosEx(playerid, 695.0466,1288.5157,1746.4379,180.3215);
	SetPlayerVirtualWorld(playerid, 3);
	SetCameraBehindPlayer(playerid);

	return true;
}

stock exit_zavod(playerid)
{
	SetPlayerPosEx(playerid, 2321.0027,2031.8478,15.9863,270.3040);
	SetPlayerVirtualWorld(playerid, 0);
	SetCameraBehindPlayer(playerid);
	end_factoryjob(playerid);

	return true;

}

stock enter_army_3(playerid)
{

	SetPlayerPosEx(playerid, -1580.9247,467.2259,43.3883,89.0253);
	SetPlayerVirtualWorld(playerid, 3);
	SetCameraBehindPlayer(playerid);


	return true;	


}

stock exit_army_3(playerid)
{

	SetPlayerPosEx(playerid, 1748.5515,1735.4395,15.5160,269.3581);
	SetPlayerVirtualWorld(playerid, 0);
	SetCameraBehindPlayer(playerid);


	return true;	


}

stock enter_army_2(playerid)
{
	SetPlayerPosEx(playerid, 1894.0824,1732.0486,15.5981,269.6130);
	SetPlayerVirtualWorld(playerid, 0);
	SetCameraBehindPlayer(playerid);


	return true;	
}

stock exit_army_2(playerid)
{

	SetPlayerPosEx(playerid, 1884.8878,1731.1735,15.5142,90.0225);
	SetPlayerVirtualWorld(playerid, 0);
	SetCameraBehindPlayer(playerid);

	return true;
}

stock enter_army_1(playerid)
{
	SetPlayerPosEx(playerid, -1832.5804,-1981.0989,-0.5234,269.4599);
	SetPlayerVirtualWorld(playerid, 3);
	SetCameraBehindPlayer(playerid);
	return true;
}

stock exit_army_1(playerid)
{

	SetPlayerPosEx(playerid, 1816.6987,1781.1243,15.5142,179.9974);
	SetPlayerVirtualWorld(playerid, 0);
	SetCameraBehindPlayer(playerid);

	return true;
}

stock enter_news_1(playerid)
{

	SetPlayerPosEx(playerid, -2669.8083,-1821.0388,4.1045,270.3148);
	SetPlayerVirtualWorld(playerid, 3);
	SetCameraBehindPlayer(playerid);	


	return true;	
}

stock enter_news_2(playerid)
{

	SetPlayerPosEx(playerid, -2669.8083,-1821.0388,4.1045,270.3148);
	SetPlayerVirtualWorld(playerid, 4);
	SetCameraBehindPlayer(playerid);	


	return true;	
}

stock exit_news_1(playerid)
{

	SetPlayerPosEx(playerid, -317.9020,819.4528,13.0635, 90.0);
	SetPlayerVirtualWorld(playerid, 0);
	SetCameraBehindPlayer(playerid);	
	return true;	
}

stock exit_news_2(playerid)
{

	SetPlayerPosEx(playerid, 2126.7471,-1959.4966,20.2422, 90.0);
	SetPlayerVirtualWorld(playerid, 0);
	SetCameraBehindPlayer(playerid);	
	return true;	
}


stock enter_federal_arzamas(playerid)
{
	if(pTemp[playerid][pWantedSu] != 0)
	{
		SendErr(playerid, "За вами ведется погоня!");
		return 1;
	}	
	SetPlayerPosEx(playerid, 1267.7883,-212.3063,1201.9819,274.7632);
	SetPlayerVirtualWorld(playerid, 3);
	SetCameraBehindPlayer(playerid);	


	return true;	
}

stock enter_federal_arzamas_2(playerid)
{
	if(pTemp[playerid][pWantedSu] != 0)
	{
		SendErr(playerid, "За вами ведется погоня!");
		return 1;
	}	
	SetPlayerPosEx(playerid, 1323.4305,-191.6199,1201.9890, 90.0);
	SetPlayerVirtualWorld(playerid, 3);
	SetCameraBehindPlayer(playerid);	


	return true;	
}

stock exit_federal_arzamas(playerid)
{
	SetPlayerPosEx(playerid, 522.8873,303.8983,13.6113,359.3354);
	SetPlayerVirtualWorld(playerid, 0);
	SetCameraBehindPlayer(playerid);	

	return true;
}

stock exit_federal_arzamas_2(playerid)
{
	SetPlayerPosEx(playerid, 533.3607,270.8882,12.9728,91.7262);
	SetPlayerVirtualWorld(playerid, 0);
	SetCameraBehindPlayer(playerid);	

	return true;
}

stock enter_meria_arzamas(playerid)
{
	if(pTemp[playerid][pWantedSu] != 0)
	{
		SendErr(playerid, "За вами ведется погоня!");
		return 1;
	}


	SetPlayerPosEx(playerid, 689.2463,-26.6244,1201.8580,356.8197);
	SetPlayerVirtualWorld(playerid, 3);
	SetCameraBehindPlayer(playerid);	
	return true;
}	

stock exit_meria_arzamas(playerid)
{
	SetPlayerPosEx(playerid, -71.7504,858.3260,12.5978,339.3453);
	SetPlayerVirtualWorld(playerid, 0);
	SetCameraBehindPlayer(playerid);	
	return true;
}	


stock enter_autoschool(playerid)
{
	if(pTemp[playerid][pWantedSu] != 0)
	{
		SendErr(playerid, "За вами ведется погоня!");
		return 1;
	}

	SetPlayerPosEx(playerid, -1.7393,-15.9433,1730.9971,349.7349);
	SetPlayerVirtualWorld(playerid, 10);
	SetCameraBehindPlayer(playerid);
	return true;
}

stock exit_autoschool(playerid)
{
	SetPlayerPosEx(playerid, -507.8719,23.6675,13.7661,179.7280);
	SetPlayerVirtualWorld(playerid, 0);
	SetCameraBehindPlayer(playerid);
	return true;	
}

stock enter_bank(playerid, type)
{	
	switch(type)
	{
		case INTERIOR_BANK_1:
		{
			SetPlayerPosEx(playerid, -88.8670,721.2244,1600.1958,179.8413);
			SetCameraBehindPlayer(playerid);
			SetPlayerVirtualWorld(playerid, VIRTUAL_WORLD_BANK_1);

		}
		case INTERIOR_BANK_2:
		{
			SetPlayerPosEx(playerid, -88.8670,721.2244,1600.1958,179.8413);
			SetCameraBehindPlayer(playerid);
			SetPlayerVirtualWorld(playerid, VIRTUAL_WORLD_BANK_2);
		}
		case INTERIOR_BANK_3:
		{
			SetPlayerPosEx(playerid, -88.8670,721.2244,1600.1958,179.8413);
			SetCameraBehindPlayer(playerid);
			SetPlayerVirtualWorld(playerid, VIRTUAL_WORLD_BANK_3);
		}
	}
	return true;
}

stock exit_bank(playerid, type)
{
	switch(type)
	{
		case INTERIOR_BANK_1:
		{
			SetPlayerPosEx(playerid, 1850.6522,2037.6697,16.9742,1.9924);
			SetCameraBehindPlayer(playerid);
			SetPlayerVirtualWorld(playerid, 0);

		}
		case INTERIOR_BANK_2:
		{
			SetPlayerPosEx(playerid, 2376.2285,-2140.8540,21.9605,181.6123);
			SetCameraBehindPlayer(playerid);
			SetPlayerVirtualWorld(playerid, 0);
		}
		case INTERIOR_BANK_3:
		{
			SetPlayerPosEx(playerid, 361.6311,1366.9980,11.8959,85.7224);
			SetCameraBehindPlayer(playerid);
			SetPlayerVirtualWorld(playerid, 0);
		}
	}
	return true;
}


// Полиция Южный

stock enter_police_dep_2_1(playerid)
{
	if(pTemp[playerid][pWantedSu] != 0)
	{
		SendErr(playerid, "За вами ведется погоня!");
		return 1;
	}

	SetPlayerPosEx(playerid, 541.7828,313.5267,1201.8690,1.5148);
	SetCameraBehindPlayer(playerid);
	SetPlayerVirtualWorld(playerid, 2);

	return true;
}

stock enter_police_dep_2_2(playerid)
{
	if(pTemp[playerid][pWantedSu] != 0)
	{
		SendErr(playerid, "За вами ведется погоня!");
		return 1;
	}

	SetPlayerPosEx(playerid, -968.4707,27.8794,1205.0167,3.7510);
	SetCameraBehindPlayer(playerid);
	SetPlayerVirtualWorld(playerid, 2);

	return true;
}

stock enter_police_dep_3_2(playerid)
{
	if(pTemp[playerid][pWantedSu] != 0)
	{
		SendErr(playerid, "За вами ведется погоня!");
		return 1;
	}
	SetPlayerPosEx(playerid, -958.0988,27.7560,1205.0167,5.0417);
	SetCameraBehindPlayer(playerid);
	SetPlayerVirtualWorld(playerid, 2);

	return true;
}

stock exit_police_dep_2_22(playerid)
{
	if(pTemp[playerid][pCuffee] == playerid) 
		return SendErr(playerid, "Вы не можете выйти из участка в наручниках!");
	
	SetPlayerPosEx(playerid, 2578.4463,-2415.9973,21.9900,269.9205);
	SetCameraBehindPlayer(playerid);
	SetPlayerVirtualWorld(playerid, 0);

	return true;
}

stock exit_police_dep_2_2(playerid)
{
	if(pTemp[playerid][pCuffee] == playerid) 
		return SendErr(playerid, "Вы не можете выйти из участка в наручниках!");

	SetPlayerPosEx(playerid, 546.1758,347.3913,1205.3906,178.2094);
	SetCameraBehindPlayer(playerid);
	SetPlayerVirtualWorld(playerid, 2);

	return true;
}

stock exit_police_dep_3_2(playerid)
{
	if(pTemp[playerid][pCuffee] == playerid) 
		return SendErr(playerid, "Вы не можете выйти из участка в наручниках!");

	SetPlayerPosEx(playerid, 536.1292,347.3729,1205.3906,180.1948);
	SetCameraBehindPlayer(playerid);
	SetPlayerVirtualWorld(playerid, 2);

	return true;
}


// Полиция Арзамас

stock enter_police_dep(playerid)
{
	if(pTemp[playerid][pWantedSu] != 0)
	{
		SendErr(playerid, "За вами ведется погоня!");
		return 1;
	}

	SetPlayerPosEx(playerid, 541.7828,313.5267,1201.8690,1.5148);
	SetCameraBehindPlayer(playerid);
	SetPlayerVirtualWorld(playerid, 1);

	return true;
}

stock enter_police_dep_2(playerid)
{
	if(pTemp[playerid][pWantedSu] != 0)
	{
		SendErr(playerid, "За вами ведется погоня!");
		return 1;
	}

	SetPlayerPosEx(playerid, -968.4707,27.8794,1205.0167,3.7510);
	SetCameraBehindPlayer(playerid);
	SetPlayerVirtualWorld(playerid, 1);

	return true;
}

stock enter_police_dep_3(playerid)
{
	if(pTemp[playerid][pWantedSu] != 0)
	{
		SendErr(playerid, "За вами ведется погоня!");
		return 1;
	}

	SetPlayerPosEx(playerid, -958.0988,27.7560,1205.0167,5.0417);
	SetCameraBehindPlayer(playerid);
	SetPlayerVirtualWorld(playerid, 1);

	return true;
}

stock exit_police_dep(playerid)
{
	if(pTemp[playerid][pCuffee] == playerid) 
		return SendErr(playerid, "Вы не можете выйти из участка в наручниках!");

	SetPlayerPosEx(playerid, 149.1269,1263.6951,13.2951,78.1972);
	SetCameraBehindPlayer(playerid);
	SetPlayerVirtualWorld(playerid, 0);

	return true;
}

stock exit_police_dep_2(playerid)
{
	if(pTemp[playerid][pCuffee] == playerid) 
		return SendErr(playerid, "Вы не можете выйти из участка в наручниках!");

	SetPlayerPosEx(playerid, 546.1758,347.3913,1205.3906,178.2094);
	SetCameraBehindPlayer(playerid);
	SetPlayerVirtualWorld(playerid, 1);

	return true;
}

stock exit_police_dep_3(playerid)
{
	if(pTemp[playerid][pCuffee] == playerid) 
		return SendErr(playerid, "Вы не можете выйти из участка в наручниках!");

	SetPlayerPosEx(playerid, 536.1292,347.3729,1205.3906,180.1948);
	SetCameraBehindPlayer(playerid);
	SetPlayerVirtualWorld(playerid, 1);

	return true;
}