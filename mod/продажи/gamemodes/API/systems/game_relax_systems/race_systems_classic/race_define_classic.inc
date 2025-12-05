new 
	race_time_start;

#define MAX_RACE_COUNT 	2


new 
	arRegisterArea,
	arRegistrInRace;


enum RACE_DATA
{
	race_status,
	race_type,
	race_count,
	race_maxcount,
	race_prizepool,
	race_car[MAX_PLAYERS] = INVALID_VEHICLE_ID,
	race_timer,
	race_lastplace,
	race_cars_select,
	end_timer
}
new race_info[RACE_DATA];

enum RACE_WINNER
{
	winner_name,
	winner_timer
}
new winner_info[22][RACE_WINNER];

new
	RaceTimer[MAX_PLAYERS];

