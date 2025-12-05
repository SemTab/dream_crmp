#define MAX_HOTEL 				4

#define MAX_RENT_HOTEL_DAY		30

#define MAX_HOTEL_NUMBER		1100

#define HOTEL_LOW_INT_RESEPTION	-2727.3716,-1758.1273,2.3055

#define HOTEL_LOW_INT_LIFT_1	-2736.6938,-1766.7065,2.3055
#define HOTEL_LOW_INT_LIFT_2	-2739.1641,-1766.7078,2.3055

#define HOTEL_LOW_INT_LIFT_3	-1888.1168,1987.1466,1165.4636
#define HOTEL_LOW_INT_LIFT_4	-1885.6477,1987.1520,1165.4636

#define HOTEL_1 				0
#define HOTEL_2 				1
#define HOTEL_3 				2
#define HOTEL_4 				3



new Float:hotel_int_exit_coord[][] = 
{
	{-2721.5579,-1765.6908,2.3055,270.7287},	// Всегда нулевой
	{-2721.5579,-1765.6908,2.3055,270.7287},
	{-2721.5579,-1765.6908,2.3055,270.7287},
	{-2721.5579,-1765.6908,2.3055,270.7287},
	{-2721.5579,-1765.6908,2.3055,270.7287}
};

new Float:hotel_int_coord[][] = 
{
	{-2722.6604,-1761.4967,2.3055,89.4755},	// Всегда нулевой
	{-2722.6604,-1761.4967,2.3055,89.4755},
	{-2722.6604,-1761.4967,2.3055,89.4755},
	{-2722.6604,-1761.4967,2.3055,89.4755},
	{-2722.6604,-1761.4967,2.3055,89.4755}
};

new Float:hotel_room_int_exit_coord[][] = 
{
	{0.0, 0.0, 0.0, 0.0},	// Всегда нулевой
	{-2030.6720,1973.6426,1164.0964},
	{-2030.6720,1973.6426,1164.0964},
	{-2030.6720,1973.6426,1164.0964},
	{-2030.6720,1973.6426,1164.0964}
};

new Float:hotel_room_int_coord[][] = 
{
	{0.0, 0.0, 0.0, 0.0},	// Всегда нулевой
	{-2030.3046,1974.7252,1164.0964,1.6431},
	{-2030.3046,1974.7252,1164.0964,1.6431},
	{-2030.3046,1974.7252,1164.0964,1.6431},
	{-2030.3046,1974.7252,1164.0964,1.6431}
};


new Float:hotel_int_spawn_coord[][] = 
{
	{0.0, 0.0, 0.0, 0.0},	// Всегда нулевой
	{-2033.8782,1978.9119,1164.0964,183.5011},
	{-2033.3964,1978.3640,1164.0964,178.6978},
	{-2033.3964,1978.3640,1164.0964,178.6978},
	{-2033.3964,1978.3640,1164.0964,178.6978}
};



enum hotel_general_data
{
	hotel_id,
	hotel_owned,
	hotel_bank,
	hotel_owner[32],
	hotel_name[32],
	Float:hotel_enter_x,
	Float:hotel_enter_y,
	Float:hotel_enter_z,
	Float:hotel_exit_x,
	Float:hotel_exit_y,
	Float:hotel_exit_z,
	Text3D:hotel_pickup_text,
	hotel_class,
	hotel_price_rent,
	hotel_enter_price,
	hotel_takings,
	hotel_price,
	hotel_lock,
	hotel_days,
	hotel_pickup,
	hotel_mapicon,
	hotel_finka_ogran,
	hotel_finka_day,

	hotel_sell_day_payday,
	hotel_status_sell
};
new hotel[MAX_HOTEL][hotel_general_data];


enum hotel_room_data
{	
	hotel_room_owned,
	hotel_room_owner[32],
	hotel_room_id,
	hotel_room_level,
	hotel_room_class,
	hotel_h_id,
	hotel_room_lock,
	hotel_room_day,
	Text3D:hotel_room_pickup_text,
	Float:hotel_room_enter_x,
	Float:hotel_room_enter_y,
	Float:hotel_room_enter_z,
	Float:hotel_room_exit_x,
	Float:hotel_room_exit_y,
	Float:hotel_room_exit_z,
	hotel_room_pickup
};
new hotel_room[MAX_HOTEL_NUMBER][hotel_room_data];
