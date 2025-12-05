#define POLICE_CLOSE_DOOR_TIME	5000


new 
	number_gai_free;



new 
	pickup_spawn_car_police[2],
	door_police_object[10] = INVALID_OBJECT_ID,
	count_police_vehicle = 30,
	area_buy_weapon_lic; 


#define MAX_BREAK_COUNT	3

new
	police_object[3][MAX_PLAYERS],
	police_ships[3][MAX_PLAYERS],
	Text3D:police_text[3][MAX_PLAYERS];