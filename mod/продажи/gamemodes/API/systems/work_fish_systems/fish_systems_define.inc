
#define MAX_POSITION_FISH_ACTIVE	5
#define MAX_FISH_OBJECT				15

// Частые рыбы

#define FISH_MODELS_LOSOS			1
#define FISH_MODELS_GORBUSHA		2
#define FISH_MODELS_SAZAN			3
#define FISH_MODELS_SOM				4
#define FISH_MODELS_TRESKA			5
	
// Средняя частота появления рыбы
	
#define FISH_MODELS_TUNEC			6
#define FISH_MODELS_SUDAK			7
#define FISH_MODELS_SEMGA			8
#define FISH_MODELS_SKUMBRIA		9
#define FISH_MODELS_LEH				10
	
// Редкие виды рыб	
		
#define FISH_MODELS_SHUKA			11
#define FISH_MODELS_FOREL			12
#define FISH_MODELS_PLOTVA			13
#define FISH_MODELS_LAKENDRA		14
#define FISH_MODELS_MAKREL			15

// Статус рыбалки игрока

#define FISH_STATUS_NO_START		1
#define FISH_STATUS_START_FISHING	2
#define FISH_STATUS_START_PREFINAL	3
#define FISH_STATUS_FINAL 			4

#define FISH_ACTOR_POSITION			-1118.5178,2308.0132,37.2906,189.3230
#define FISH_ACTOR_SKIN				51


new 
	fish_position_player[MAX_POSITION_FISH_ACTIVE],
	actor_fish_general;

new 
	fish_active_player[MAX_PLAYERS];

new 
	fish_price_player[15];