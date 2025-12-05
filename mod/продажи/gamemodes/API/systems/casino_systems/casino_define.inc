
#define MAX_CASINO			1
#define MAX_TABLE			5

#define CASINO_EXIT_COORD	-18.1895,978.5392,1301.0000

#define SKIN_CRUPIE_FEMALE	172
#define SKIN_CRUPIE_MALE 	171

new 
	casino_total_crupie = 10,
	casino_table[5],
	casino_start_job,
	casino_info_all,
	casino_timer[5],
	casino_actor[7];

enum casino_data
{
	casino_id,
	casino_owner_id,
	casino_owner_name[MAX_PLAYER_NAME],

	casino_buy_price,
	casino_closed_status,
	casino_day,
	casino_bank,
	casino_takings,

	Float:casino_pos_x,
	Float:casino_pos_y,
	Float:casino_pos_z,

	Text3D:casino_pick_info,
	Text3D:casino_info,

	casino_finka_ogran,
	casino_icon,
	casino_pickup,
	casino_finka_day,
	step,

	casino_buy_status,
	casino_sell_day_payday
}
new casino[MAX_CASINO][casino_data]; 

enum casino_table_data
{
	casino_t_players[5],
	casino_t_bet,
	casito_t_crup,
	bool:casino_t_status,
	casino_step,
	casino_t_bank
};
new casino_tables[MAX_TABLE][casino_table_data];