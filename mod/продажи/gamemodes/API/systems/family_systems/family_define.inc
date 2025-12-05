#define FAMILY_COUNT_MAX 				500
#define PRICE_CREATE_FAMILY				2500000
#define PRICE_CHANGE_FAMILY_NAME		150 
#define FAMILY_POINT_COEFFCIENT 		50

#define PRICE_FAMILY_UPGRADE_CORP		350000
#define PRICE_FAMILY_UPGRADE_SYNDICATE	500000
#define PRICE_FAMILY_UPGRADE_BRIGADE	1000000
#define PRICE_FAMILY_UPGRADE_CAPACITY 	1000000
#define PRICE_FAMILY_UPGRADE_VEHICLE	2000000

#define MAX_FAMILY_VEHICLES_1			4
#define MAX_FAMILY_VEHICLES_2			8

#define MAX_FAMILY_WAREHOUSE			10000
#define FAMILY_WAR_WIN_MONEY			100000
#define FAMILY_WAR_WIN_EXP				50

#define FAMILY_PICKUP 		691.9303,-13.3944,1201.8580

new 
	Text3D:fam_lable[MAX_PLAYERS] = {Text3D:-1, ...};

new 
	family_create_name[MAX_PLAYERS][32],
	family_create_color[MAX_PLAYERS];

new 
	part_family_offline[MAX_PLAYERS];

new 
	family_pickup;

new family_vehicle_sql[FAMILY_COUNT_MAX][MAX_FAMILY_VEHICLES_2];
new family_vehicle[FAMILY_COUNT_MAX][MAX_FAMILY_VEHICLES_2];

enum fam_war_info
{
	wStatus,
	wDefense,
	wAttack,
	wDScore,
	wAScore,
	wTimer,
	wZone,
	wArea
}

new family_war[fam_war_info];