new 
	pickup_spawn_car_army_1,
	pickup_spawn_car_army_2,
	pickup_spawn_car_army_3,
	count_army_vert_active = 2,
	count_army_vehicle = 15;

enum ARMY_DATA
{
	so_patrons,
	so_guns,
	army_patrons,
	army_guns
}
new army_info[ARMY_DATA];

new
	vehicle_load[MAX_VEHICLES],
	vehicle_load_pickup[MAX_VEHICLES],
	vehicle_load_sphere[MAX_VEHICLES],
	Text3D:vehicle_load_text[MAX_VEHICLES],
	vehicle_load_count[MAX_VEHICLES];

new
	army_area,
	Text3D:army_3dtext,
	army_so_area[4],
	Text3D:army_so_3dtext[4];

new
	arArmyKitchen;

new
	arArmyMakegun;
