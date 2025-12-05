#define MAX_APART 500

new Float:apartaments_exit_coord[][] = 
{
	{0.0, 0.0, 0.0, 0.0},	// Всегда нулевой
	{-1459.1659,-800.9946,14.0578,91.2173},
	{501.3225,-364.3347,1201.9318,0.7700},
	{501.3225,-364.3347,1201.9318,0.7700},
	{501.3225,-364.3347,1201.9318,0.7700}
};

enum apartament_data
{
	apartament_id,
	Float:apartament_enter_x,
	Float:apartament_enter_y,
	Float:apartament_enter_z,
	Float:apartament_exit_x,
	Float:apartament_exit_y,
	Float:apartament_exit_z,	
	apartament_class,
	Text3D:apartament_3dtext,
	apartament_lock,
	apartament_pickup,
	apartament_map_icon,
	Text3D:apartament_pick_info,

};

new 
	apartament[MAX_APART][apartament_data];
