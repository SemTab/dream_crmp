#define STAP_JOB_MINER_NONE		0
#define STAP_JOB_MINER_MINING	1
#define STAP_JOB_MINER_KONVEER	2
#define STAP_JOB_MINER_SORT		3
#define STAP_JOB_MINER_SKLAD	4
#define STAP_JOB_MINER_LIFT		5


#define MINEJOB_NONE			-1
#define MINEJOB_COAL			1
#define MINEJOB_COPPER			2
#define MINEJOB_DIAMOND			3
#define MINEJOB_GOLD			4
#define MINEJOB_IRON			5
#define MINEJOB_METAL			6

#define STONE_IRON				1
#define STONE_MED				2
#define STONE_GOLD				3

#define ATTACH_HAND_MINER		1

#define MAX_MINER_KONVEER		13

new 
	area_sklad_miner_street[8],
	area_clothes_pickup_miner,
	area_enter_miner_1[2],
	actor_miner,
	area_exit_miner_1[2],
	area_enter_miner_2[2],
	area_exit_miner_2[2],
	area_miner_start[9],
	area_miner_1_count[10],
	area_miner_2_count[10],
	area_lift_load_miner[4],
	area_konveer_miner[MAX_MINER_KONVEER],
	area_complect_miner[4];

new 
	count_job_miner;

new 
	miner_select_material_mining[MAX_PLAYERS],
	mine_random_material_active[MAX_PLAYERS],
	mine_miner_progress_bar[MAX_PLAYERS],
	mine_player_pickup[MAX_PLAYERS][5];

new 
	mine_konveer_massive_object[MAX_PLAYERS][7],
	mine_konveer_all_object[MAX_PLAYERS],
	mine_position_td[MAX_PLAYERS];


new 
	mine_konveer_select_object[MAX_PLAYERS],
	mine_konveer_massive_object_td[MAX_PLAYERS];

new 
	miner_select_material_sort[MAX_PLAYERS][3],
	miner_select_material_sort_ch[MAX_PLAYERS][3],
	miner_select_material_sort_td[MAX_PLAYERS];

new 
	miner_chest_status[MAX_PLAYERS][3],
	mine_chest_progress[MAX_PLAYERS];

new 
	Float:progress_job_mine_miner[MAX_PLAYERS],
	Float:progress_job_mine_konveer[MAX_PLAYERS],
	Float:progress_job_mine_sort[MAX_PLAYERS];