
#define MAX_PROD_STOCK				5000

#define MAX_BUISNES					500

#define MAGAZIN_PRODUCTION_BUY_1	2490.5891,-721.8501,12.3003
#define MAGAZIN_PRODUCTION_BUY_2	2497.4570,-721.9276,12.3003 

#define MAGAZING_UNIVERMAG 			-904.3103,-2041.9266,25.7742

#define POSITION_FASTFOOD			249.4328,84.3802,1201.9316
#define POSITION_FOOD_HOUSE			-417.6508,906.9108,12.0046
#define POSITION_BAR				-417.6508,906.9108,12.0046	
#define POSITION_RESTORAN			249.4328,84.3802,1201.9316

#define BUISNES_PRODUCTION			1
#define BUISNES_BAR					2
#define BUISNES_AMMO_1				3
#define BUISNES_RESTORAN			4 
#define BUISNES_FASTFOOD			5
#define BUISNES_CLUB				6
#define BUISNES_AUTOSALON_1			7
#define BUISNES_AUTOSALON_2			8
#define BUISNES_AUTOSALON_3			9
#define BUISNES_AMMO_2				10
#define BUISNES_CLOTHES				11
#define BUISNES_ACCESSORIES			12
#define BUISNES_RIELTOR_AGENCY		13
#define BUISNES_PARKING				14

#define BUISNES_PRODUCTION_EXIT		-901.7760,-2028.8823,25.8054
#define BUISNES_PRODUCTION_ENTER	-901.2756,-2030.6083,25.8054,179.0607

#define MAGAZINE_CAR_1_EXIT			-177.5460,-15.4787,1201.9387
#define MAGAZINE_CAR_1_ENTER		-179.4926,-15.0414,1201.9387,74.7852

#define MAGAZINE_CAR_2_EXIT			-20.1775,367.8051,1601.7495
#define MAGAZINE_CAR_2_ENTER		-20.6119,365.2504,1601.7495,179.3607

#define MAGAZINE_CAR_3_EXIT			-22.4439,-723.5922,1201.9701
#define MAGAZINE_CAR_3_ENTER		-22.5820,-719.2978,1201.9474,0.2257

#define ENTER_FASTFOOD				249.4108,85.6173,1201.9316,0.9257

#define MAGAZING_CLOTHES_1_EXIT		-68.0257,944.4311,1597.9788	
#define MAGAZING_CLOTHES_1_ENTER	-68.1229,946.2680,1597.9788,359.3376

#define MAGAZIN_AKS_1_EXIT			-650.6499,-708.0483,1201.9475
#define MAGAZIN_AKS_1_ENTER			-650.9448,-710.1032,1201.9475,182.2171

#define MAX_RENT_CAR_AUTOSALON_1	75
#define MAX_RENT_CAR_AUTOSALON_2	75
#define MAX_RENT_CAR_AUTOSALON_3	75

#define PRICE_WATCH_INFO_REALTOR	100

new 
	autosalon_area_info_1[4],
	autosalon_area_info_2[8],
	autosalon_actor[5],
	ammunation_actor[2],
	clothes_actor,
	autosalon_id_buy_car[MAX_PLAYERS],
	autosalon_select_count[MAX_PLAYERS],

	clothes_id_buy[MAX_PLAYERS],
	clothes_select_count[MAX_PLAYERS],

	autosalon_count_rent_car[4];

new
	magazin_production[2];

new 
	magazing_univermag,
	fastfood_magazing[5],
	prod_house_magazin,
	bar_pickup;

new 
	realtor_agency_pickup;


new Select[MAX_PLAYERS];
new selectID[MAX_PLAYERS][20];
new zShowEstate[MAX_PLAYERS];
new zSelected[MAX_PLAYERS];

enum buisnes_data
{
	buisnes_id,
	buisnes_owned,
	buisnes_owner[32],
	Float:buisnes_enter_x,
	Float:buisnes_enter_y,
	Float:buisnes_enter_z,
	Float:buisnes_exit_x,
	Float:buisnes_exit_y,
	Float:buisnes_exit_z,
	buisnes_type,
	buisnes_name,
	buisnes_bank,
	buisnes_price,
	buisnes_lock,
	buisnes_takings,
	buisnes_days,
	buisnes_pickup,
	buisnes_mapicon,
	buisnes_upgrade_1,
	buisnes_upgrade_2,
	buisnes_upgrade_3,
	buisnes_upgrade_4,
	buisnes_upgrade_5,
	buisnes_upgrade_6,
	buisnes_enterprice,
	Text3D:buisnes_pickup_3d,
	buisnes_finka_ogran,
	buisnes_finka_day,
	buisnes_count_prod,
	buisnes_status_sell,
	buisnes_sell_day_payday,
	buisnes_mafia,
	buisnes_price_day_rent

};

new buisness[MAX_BUISNES][buisnes_data];


stock create_buisness_pickup()
{

	// Продуктовый магазин

	magazin_production[0] = create_circle_pickup(MAGAZIN_PRODUCTION_BUY_1, TRIGGER_LBLUE);
	magazin_production[1] = create_circle_pickup(MAGAZIN_PRODUCTION_BUY_2, TRIGGER_LBLUE);

	CreateDynamic3DTextLabel(""cWH"\
		"cBLUE"Продуктовый магазин\n\
		"cGREY"Касса для заказа продукции", CWHITE, MAGAZIN_PRODUCTION_BUY_1, 15.0,INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);

	CreateDynamic3DTextLabel(""cWH"\
		"cBLUE"Продуктовый магазин\n\
		"cGREY"Касса для заказа продукции", CWHITE, MAGAZIN_PRODUCTION_BUY_2, 15.0,INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);


	// Универмаги

	magazing_univermag = create_circle_pickup(MAGAZING_UNIVERMAG, TRIGGER_LBLUE);

	CreateDynamic3DTextLabel(""cWH"\
		"cBLUE"Универмаг\n\
		"cGREY"Касса для покупок", CWHITE, MAGAZING_UNIVERMAG, 15.0,INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1);

	// Закусочные

	fastfood_magazing[0] = create_circle_pickup(252.3709,102.3716,1201.9647, TRIGGER_LBLUE);
	fastfood_magazing[1] = create_circle_pickup(249.2895,102.3553,1201.9685, TRIGGER_LBLUE);
	fastfood_magazing[2] = create_circle_pickup(246.5500,102.3559,1201.9685, TRIGGER_LBLUE);
	fastfood_magazing[3] = create_circle_pickup(243.7241,102.3242,1201.9684, TRIGGER_LBLUE);
	fastfood_magazing[4] = create_circle_pickup(241.1117,102.3405,1201.9684, TRIGGER_LBLUE);


	CreateDynamic3DTextLabel(""cWH"\
		"cBLUE"Закусочная\n\
		"cGREY"Касса для покупок", CWHITE, 252.3709,102.3716,1201.9647, 5.0,INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 20, -1);

	CreateDynamic3DTextLabel(""cWH"\
		"cBLUE"Закусочная\n\
		"cGREY"Касса для покупок", CWHITE, 249.2895,102.3553,1201.9685, 5.0,INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 20, -1);

	CreateDynamic3DTextLabel(""cWH"\
		"cBLUE"Закусочная\n\
		"cGREY"Касса для покупок", CWHITE, 246.5500,102.3559,1201.9685, 5.0,INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 20, -1);

	CreateDynamic3DTextLabel(""cWH"\
		"cBLUE"Закусочная\n\
		"cGREY"Касса для покупок", CWHITE, 243.7241,102.3242,1201.9684, 5.0,INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 20, -1);

	CreateDynamic3DTextLabel(""cWH"\
		"cBLUE"Закусочная\n\
		"cGREY"Касса для покупок", CWHITE, 241.1117,102.3405,1201.9684, 5.0,INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 20, -1);

	return true;
}

