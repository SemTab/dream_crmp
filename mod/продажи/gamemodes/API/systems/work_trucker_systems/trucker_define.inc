#define MAX_TRUCKER_JOB				50
#define MAX_TRUCKER_BASE			3
		
#define MAX_trucker_BOX				10
		
#define TRUCKER_JOB_MINER			1
#define TRUCKER_JOB_ZAVOD			2
#define TRUCKER_JOB_SHOP			3
#define TRUCKER_JOB_FILL_1			4
#define TRUCKER_JOB_FILL_2			5
#define TRUCKER_JOB_SAMWILL			6


#define TRUCKER_MINER_LOAD			-1413.1733, 2585.8633, 40.3924
#define TRUCKER_ZAVOD_LOAD			2303.3110,2003.6044,15.9863
#define TRUCKER_SHOP_LOAD			2498.6448, -650.6407, 12.2334	
#define TRUCKER_FUEL_LOAD			-2188.4277,-2705.1270,19.9134
#define TRUCKER_SAMWILL_LOAD		-1074.3948,-2495.8887,28.5196


#define TRUCKER_MINER_UNLOAD		2768.8772, -2396.8340, 21.9269	
#define TRUCKER_ZAVOD_UNLOAD		2769.5520,-2376.7959,21.9683
#define TRUCKER_SAMWILL_UNLOAD		2321.0771,2023.5059,15.9863

new 
	trucker_repair_box_1[5],
	trucker_repair_box_2[6];


new 
	trucker_skin_pickup[MAX_TRUCKER_BASE];

new 
	actor_trucker[MAX_TRUCKER_BASE],
	trucker_count_truck[MAX_TRUCKER_BASE],
	no_collizion_zone_trucker[8];

new 
	count_truck_load_gruz[MAX_PLAYERS],
	checkpoint_truck_unload[MAX_PLAYERS];

enum trucker_data
{
	trucker_base_id,
	trucker_base_name[20],
	trucker_base_owner_id,
	trucker_base_owner[MAX_PLAYER_NAME],
	trucker_low_owner_id,
	trucker_low_owner[MAX_PLAYER_NAME],

	trucker_base_trucker_station[MAX_TRUCKER_JOB],

	trucker_base_price,
	trucker_base_closed,
	trucker_base_days,
	trucker_base_bank,


	Float:trucker_pos_x,
	Float:trucker_pos_y,
	Float:trucker_pos_z,

	trucker_base_finka_day,
	trucker_base_finka_ogran,

	Text3D:trucker_base_pick_info,
	Text3D:trucker_base_storage_info,

	trucker_base_percent,

	trucker_base_icon,
	trucker_base_pickup,

	trucker_sell_day_payday,
	trucker_status_sell,

	trucker_base_car_count,
	trucker_veh_count,
	trucker_block_percent,
	trucker_block_uninvite,
	trucker_block_bank,
	trucker_person_count,
	trucker_level_veh,
	trucker_car_color

}
new trucker_station[MAX_TRUCKER_BASE][trucker_data]; 

