#define MAX_GARAGE			1000

enum garage_general_data
{
	garage_id,
	garage_owner_id,
	garage_owner_name[32],
	garage_class,
	garage_price,
	garage_lock,
	garage_nalog,
	garage_day,
	garage_takings,
	garage_days,
	Float:garage_enter_x,
	Float:garage_enter_y,
	Float:garage_enter_z,
	Float:garage_exit_x,
	Float:garage_exit_y,
	Float:garage_exit_z,
	Float:garage_exit_x_car,
	Float:garage_exit_y_car,
	Float:garage_exit_z_car,
	Float:garage_exit_a_car,
	Text3D:garage_3dtext,
	garage_mapicon,
	garage_pickup,
	garage_sell_count_payday,
	garage_sell_status,
	garage_sphere_change
};
new garage[MAX_GARAGE][garage_general_data];
