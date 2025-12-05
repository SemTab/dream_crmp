#define MAX_MECHANIC_JOB	50
#define MAX_MECHANIC_BASE	3

#define MAX_MECHANIC_BOX	10

new 
	mechanic_repair_box_1[5],
	Text3D:mechanic_repair_box_1_t[4],
	Text3D:mechanic_repair_box_2_t[5],
	Text3D:mechanic_repair_box_3_t[4],
	mechanic_repair_box_2[6],
	mechanic_repair_box_3[4],
	mechanic_vehicle_rent[3];

new 
	mechanic_skin_pickup[MAX_MECHANIC_BASE],
	mechanic_count_car[5];

enum mechanic_data
{
	mechanic_base_id, 
	mechanic_base_name[20],
	mechanic_base_owner_id,
	mechanic_base_owner[MAX_PLAYER_NAME],

	mechanic_base_mechanic[MAX_MECHANIC_JOB],

	mechanic_base_price,
	mechanic_base_closed,
	mechanic_base_days,
	mechanic_base_bank,


	Float:mechanic_pos_x,
	Float:mechanic_pos_y,
	Float:mechanic_pos_z,

	Text3D:mechanic_base_pick_info,
	Text3D:mechanic_base_storage_info,

	mechanic_base_percent,
	mechanic_base_phone,

	mechanic_base_icon,
	mechanic_base_pickup,

	mechanic_price_remont,
	mechanic_price_fuel,
	mechanic_price_oil,
	mechanic_price_candles,
	mechanic_price_brake,
	mechanic_price_belt,
	mechanic_price_starter,
	mechanic_price_generator,
	mechanic_price_forsunki,
	mechanic_price_nasos,
	mechanic_base_finka_day,
	mechanic_base_finka_ogran,
	mechanic_status_sell,
	mechanic_sell_day_payday

}
new mechanic[MAX_MECHANIC_BASE][mechanic_data]; 


enum mechanic_box_data
{
	mechanic_base_id,
	mechanic_active_id,
	mechanic_box_status
};

new 
	mechanic_box[MAX_MECHANIC_BASE][MAX_MECHANIC_BOX][mechanic_box_data];