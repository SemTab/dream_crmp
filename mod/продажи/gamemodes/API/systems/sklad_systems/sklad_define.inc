#define MAX_SKLAD_PLAYERS		10


enum sklad_other_data
{
	sklad_other_id,
	sklad_other_count_1,
	sklad_other_count_2,
	sklad_other_count_3,
	sklad_other_count_4,
	sklad_other_count_5,
	sklad_other_count_6,

	Text3D:sklad_pick_info
}
new sklad[MAX_SKLAD_PLAYERS][sklad_other_data]; 

new 
	Text3D:sklad_pick_info_miner[4],
	Text3D:sklad_pick_info_wood,
	Text3D:sklad_pick_info_factory[2];