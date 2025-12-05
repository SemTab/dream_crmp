


#define MAX_FUELLING_STATION			12

#define MAX_FILLING_BUNKER_STANDART		5000
#define MAX_FILLING_BUNKER_UPDATE_1		10000

#define PRICE_BUY_FUEL_DELIVERY			30

enum fuilling_data 
{
	filling_id,
	filling_owner_id,
	filling_type_name,
	filling_owner[MAX_PLAYER_NAME],

	Text3D:filling_text3d_general,
	Text3D:filling_text3d_electro,

	filling_pickup,
	filling_mapicon,

	filling_lock, 
	filling_bank, 
	filling_price,

	filling_takings,
	filling_day,

	filling_finka_max,
	filling_count_all_fill,
	filling_upgrade_1,
	filling_upgrade_2,
	filling_upgrade_3,
	filling_upgrade_4,
	filling_upgrade_electro,
	filling_electro_energy,
	filling_count_energy,

	fillings_finka_ogran,
	fillings_finka_day,

	filling_price_fuel_1,
	filling_price_fuel_2,
	filling_price_fuel_3,
	filling_price_fuel_4,

	Float:filling_info_enter_x,
	Float:filling_info_enter_y,
	Float:filling_info_enter_z,

	filling_buy_status,
	filling_sell_day_payday


}

new filling[MAX_FUELLING_STATION][fuilling_data];







































new 
	filling_trigger_1_fill[4],
	filling_trigger_2_fill[4],
	filling_trigger_3_fill[4],
	filling_trigger_4_fill[4],
	filling_trigger_5_fill[4],
	filling_trigger_6_fill[4],
	filling_trigger_7_fill[4],
	filling_trigger_8_fill[4],
	filling_trigger_9_fill[4],
	filling_trigger_10_fill[4],
	filling_trigger_11_fill[4],
	filling_trigger_12_fill[4];


new 
	filling_trigger_1_eng[4],
	filling_trigger_2_eng[4],
	filling_trigger_3_eng[4],
	filling_trigger_4_eng[4],
	filling_trigger_5_eng[4],
	filling_trigger_6_eng[4],
	filling_trigger_7_eng[4],
	filling_trigger_8_eng[4],
	filling_trigger_9_eng[4],
	filling_trigger_10_eng[4],
	filling_trigger_11_eng[4],
	filling_trigger_12_eng[4];


