


#define WORK_FACTORY_SOFA			1
#define WORK_FACTORY_CHAIR			2
#define WORK_FACTORY_BED			3
#define WORK_FACTORY_FRAME			4
#define WORK_FACTORY_CRACK			5
#define WORK_FACTORY_TABLE			6
#define WORK_FACTORY_CHAIR_2		7
#define WORK_FACTORY_STAND			8
#define WORK_FACTORY_BOARD			9

#define WORK_FACTORY_CLOCKER		1
#define WORK_FACTORY_SUITCASE		2
#define WORK_FACTORY_DOOR			3
#define WORK_FACTORY_DOOR_2			4
#define WORK_FACTORY_CLOCK 			5


new 
	factory_job_furniture_count[MAX_PLAYERS],
	factory_job_mith_count[MAX_PLAYERS],
	Float:factory_job_count_point[MAX_PLAYERS],
	Float:factory_job_count_point_2[MAX_PLAYERS];


new 
	area_factory_mith[13],
	area_factory_furniture[16],
	area_factory_clothes,
	actor_factory,
	area_factory_mith_sklad,
	area_factory_mith_sklad2,
	area_factory_furniture_sklad,
	area_factory_furniture_sklad2;