
#define CALL_MEDIC 		  			1
#define MAX_HOSPITAL_HELP			5

#define TYPE_MED_ADRENALIN			1
#define TYPE_MED_DEF				2


new
	hospital_actor,
	pickup_start_job_hospital,
	call_hospital_progress = 10,
	hospital_timer = 300,
	call_hospital_id = -1,
	use_adrenalin_actor,
	use_def_actor,
	timer_puls_actor[MAX_PLAYERS],
	time_user_med[MAX_PLAYERS],
	hospital_name_actor,
	use_pills_actor,
	Text3D:hospital_actor_text;


enum enum_hospital_call
{
	Float:actor_hospital_x,
	Float:actor_hospital_y,
	Float:actor_hospital_z,
	Float:actor_hospital_r,

	hospital_help_name[50]
};

new hospital_help[MAX_HOSPITAL_HELP][enum_hospital_call] = 
{
	{320.0384,1339.1812,11.8957,85.7805, "Банк г.Арзамас"},
	{124.8382,1254.3696,12.1977,155.2221, "МВД г.Арзамас"},
	{427.0169,1177.0435,12.0006,266.4814, "Автосалон"},
	{310.2986,783.3690,12.0010,68.5222, "Арзамас"},
	{166.6907,786.7928,12.1491,251.1245, "Арзамас"}
};

stock get_help_med_n(h)
{
	new 
		name[40];

	switch(h)
	{
		case 0: name = "Rostislav_Rakowskin";
		case 1: name = "Viktor_Bardin";
		case 2: name = "Nikolay_Abramov";
		case 3: name = "Vladislav_Elin";
		case 4: name = "Konstantin_Kazanov";
		case 5: name = "Gerasim_Sokolin";
		case 6: name = "Spartak_Gurkin";
		case 7: name = "Abram_Levitin";
		case 8: name = "Arkady_Belkin";
		case 9: name = "Vladimir_Poleskin";
		case 10: name = "Spartak_Burdin";
		case 11: name = "Timur_Kotov";
		case 12: name = "Konstantin_Markowkin";
		case 13: name = "Boris_Golubev";
		default: name = "None";
	}
	return name;
}
