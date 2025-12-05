#define MAX_TAXI_COMPANY		3
	
#define TARIF_TAXI_ECONOM		1
#define TARIF_TAXI_COMFORT		2
#define TARIF_TAXI_BUISNES		3

#define CLICK_SELECT_TARIF_ECONOM	1
#define CLICK_SELECT_TARIF_COMFORT	2
#define CLICK_SELECT_TARIF_BUISNES	3
#define CLICK_SELECT_TAXI_TEXT		4
#define CLICK_SELECT_TAXI_CALL		5
#define CLICK_SELECT_TAXI_WAIT		6

#define WORKING_TAXI_HOUSE_OTHER	1
#define WORKING_TAXI_PEOPLE_OTHER	2

#define UPDATE_COUNT_CLIENT_TAXI	1
#define UPDATE_COUNT_MONEY_TAXI		2

enum taxi_company_data
{
	taxi_company_id,
	taxi_company_owner_id,
	taxi_company_owner_name[MAX_PLAYER_NAME],

	taxi_company_price,
	taxi_company_closed,
	taxi_company_days,
	taxi_company_bank,

	taxi_company_percent_1, // На личном авто
	taxi_company_percent_2,	// Таксопарка

	Float:taxi_pos_x,
	Float:taxi_pos_y,
	Float:taxi_pos_z,

	taxi_company_finka_day,
	taxi_company_finka_ogran,

	taxi_company_price_econom,
	taxi_company_price_comfort,
	taxi_company_price_buisnes,

	taxi_company_count_car,
	taxi_company_count_working,

	Text3D:taxi_company_pick_info,
	Text3D:taxi_company_storage_info,

	taxi_company_icon,
	taxi_company_pickup,

	taxi_status_sell,

	taxi_finka_ogran,
	taxi_finka_ogran_day,
	taxi_sell_day_payday

}
new taxi_company[MAX_TAXI_COMPANY][taxi_company_data]; 

new 
	actor_taxi_company_yandex,
	actor_taxi_company_uber,
	actor_taxi_company_city;

new 
	area_taxi_work_yandex,
	area_taxi_work_uber,
	area_taxi_work_city;


new 
	taxi_client_timer[MAX_PLAYERS];

new 
	taxi_actor_dynamic[MAX_PLAYERS],
	Text3D:taxi_actor_text[MAX_PLAYERS];

new 
	taxi_count_truck[MAX_TAXI_COMPANY];