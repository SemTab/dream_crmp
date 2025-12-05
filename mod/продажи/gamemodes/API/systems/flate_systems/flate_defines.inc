#define MAX_FLATE 			800

#define MAX_RENT_FLAYT_DAY	30

new Float:flate_int_exit_coord[][] = 
{
	{0.0, 0.0, 0.0, 0.0},	// Всегда нулевой
	{-2394.0105,-449.2168,33.2104,269.5538},
	{479.3140,2297.5583,1601.7969,90.1189},
	{479.3140,2297.5583,1601.7969,90.1189},
	{479.3140,2297.5583,1601.7969,90.1189}
};

new Float:flate_int_coord[][] = 
{
	{0.0, 0.0, 0.0, 0.0},	// Всегда нулевой
	{-2394.6841, -448.7476, 33.2104, 358.2245},
	{481.0070,2296.7266,1601.7969,179.7868},
	{481.0070,2296.7266,1601.7969,179.7868},
	{481.0070,2296.7266,1601.7969,179.7868}
};


new Float:flate_int_spawn_coord[][] = 
{
	{0.0, 0.0, 0.0, 0.0},	// Всегда нулевой
	{-2390.9155,-440.4041,33.2339,90.5247},
	{503.1283,2309.9985,1604.6016,92.3274},
	{503.1283,2309.9985,1604.6016,92.3274},
	{503.1283,2309.9985,1604.6016,92.3274}
};


enum flate_data
{
	flate_id,
	flate_entrance_id,
	flate_id_in_entrance,
	flate_owned,
	flate_owner[32],
	Float:flate_enter_x,
	Float:flate_enter_y,
	Float:flate_enter_z,
	Float:flate_exit_x,
	Float:flate_exit_y,
	Float:flate_exit_z,
	Float:flate_veh_x,
	Float:flate_veh_y,
	Float:flate_veh_z,
	Float:flate_veh_a,
	flate_class,
	flate_price,
	flate_lock,
	flate_takings,
	flate_days,
	flate_pickup,
	flate_mapicon,
	flate_people_1_id,
	flate_people_1_day,
	flate_people_2_id,
	flate_people_2_day,
	flate_people_3_id,
	flate_people_3_day,
	flate_people_4_id,
	flate_people_4_day,
	safe_flate_status,
	safe_flate_pass,
	safe_flate_money,
	safe_flate_drugs,
	safe_flate_drugs_hard,
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
	flate_people_status,
	flate_people_price,
	flate_status_people,
	flate_subsidii_status,
	flate_sell_status,
	flate_sell_count_payday,
	wardrobe_aks_1,
	wardrobe_aks_2,
	wardrobe_aks_3
};
new flate[MAX_FLATE][flate_data];
