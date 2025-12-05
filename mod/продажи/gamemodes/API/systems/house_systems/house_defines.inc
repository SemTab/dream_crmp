#define MAX_HOUSES 			500

#define MAX_RENT_HOUSE_DAY	30

#define PRICE_GARAGE_LOW		750000
#define PRICE_GARAGE_MEDIUM 	2000000
#define PRICE_GARAGE_HIGH		4500000

new Float:house_int_exit_coord[][] = 
{
	{0.0, 0.0, 0.0, 0.0},	// Всегда нулевой
	{-2572.4880,414.1172,1.8041,0.1948}, 
	{3.2793,208.8925,1201.9314,2.5863},
	{-1138.0643,-1097.2592,1231.2622,227.9650},
	{66.8376,436.0083,1201.9454,180.0402},
	{66.8376,436.0083,1201.9454,180.0402},
	{479.3148,2297.5681,1601.7969,89.8669},
	{157.4022,-251.7018,1201.9316,0.4276}
};

new Float:house_int_coord[][] = 
{
	{0.0, 0.0, 0.0, 0.0},	// Всегда нулевой
	{-2572.4836,412.3434,1.8041,178.1926},
	{3.2096,206.2449,1201.9314,182.4926},
	{-1137.4603,-1095.6177,1231.2622,314.0953},
	{66.9287,437.6659,1201.9380,1.6521},
	{66.9287,437.6659,1201.9380,1.6521},
	{480.7315,2295.9014,1601.7969,181.3666},
	{157.6996,-253.3982,1201.9316,183.1428}
};


new Float:house_int_spawn_coord[][] = 
{
	{0.0, 0.0, 0.0, 0.0},	// Всегда нулевой
	{-2566.4094,395.0383,1.8119,86.7853},
	{15.0343,203.5628,1201.9314,93.0120},
	{-1131.6891,-1087.1460,1231.2700,181.3150},
	{60.6859,445.3951,1201.9380,358.1776},
	{60.6859,445.3951,1201.9380,358.1776},
	{503.5526,2310.4114,1604.6016,180.1979},
	{155.7633,-257.9854,1201.9316,354.6793}
};

new Text3D:garage_text_house[MAX_HOUSES];

enum house_data
{
	house_id,
	house_owned,
	house_owner[32],
	Float:house_enter_x,
	Float:house_enter_y,
	Float:house_enter_z,
	Float:house_exit_x,
	Float:house_exit_y,
	Float:house_exit_z,
	Float:house_veh_x,
	Float:house_veh_y,
	Float:house_veh_z,
	Float:house_veh_a,
	Float:house_park_x,
	Float:house_park_y,
	Float:house_park_z,
	Float:house_park_a,
	house_class,
	house_price,
	house_lock,
	house_takings,
	house_days,
	house_pickup,
	house_mapicon,
	house_people_1_id,
	house_people_1_day,
	house_people_2_id,
	house_people_2_day,
	house_people_3_id,
	house_people_3_day,
	house_people_4_id,
	house_people_4_day,
	safe_house_status,
	safe_house_pass,
	safe_house_money,
	safe_house_drugs,
	safe_house_drugs_hard,
	wardrobe_gun_1,
	wardrobe_gun_2,
	wardrobe_gun_3,
	wardrobe_gun_ammo_1,
	wardrobe_gun_ammo_2,
	wardrobe_gun_ammo_3,
	wardrobe_skin_1,
	wardrobe_skin_2,
	wardrobe_skin_3,
	wardrobe_status,
	house_people_status,
	house_people_price,
	house_status_people,
	house_subsidii_status,
	house_sell_status,
	house_sell_count_payday,

	wardrobe_aks_1,
	wardrobe_aks_2,
	wardrobe_aks_3,
	house_virtualword,
	house_pickup_obj,

	house_garage_status,
	Float:house_park_garage_x,
	Float:house_park_garage_y,
	Float:house_park_garage_z,
	Float:house_park_garage_a,
	house_garage_class

};
new House[MAX_HOUSES][house_data];
