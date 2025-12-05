new 
	snow_race_time_start;

#define MAX_LAP_SNOW_RACE	3



new 
	arSnowRaceRegister,
	arSnowRace;


enum SNOW_RACE_DATA
{
	snow_status,
	snow_count,
	snow_maxcount,
	snow_prizepool,
	snow_car[MAX_PLAYERS] = INVALID_VEHICLE_ID,
	snow_timer,
	snow_lastplace,
	snow_end_timer
}
new snow_race_info[SNOW_RACE_DATA];

enum SNOW_RACE_WINNER
{
	winner_name,
	winner_timer
}
new snow_winner_info[8][SNOW_RACE_WINNER];

new
	SnowRaceTimer[MAX_PLAYERS];

new
    Iterator:Player_In_Snow_Race<MAX_PLAYERS>;
