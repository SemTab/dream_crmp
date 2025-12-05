

new hunter_object[] =
{
	18177, 18178, 18179, 18180
};


#define ACTOR_POS_SELLER_DEER		0.0, 0.0, 0.0
#define ACTOR_SKIN_SELLER_DEER		23
#define POS_SELLER_DEERS			0.0, 0.0, 0.0

#define HUNTER_TIME_UPDATE			600000
#define MAX_HUNTER_POSITION			80

#define PRICE_BUY_LIC_HUNTER_1		1500
#define PRICE_BUY_LIC_HUNTER_3		2500
#define PRICE_BUY_LIC_HUNTER_7		6000
#define PRICE_BUY_LIC_HUNTER_14		10000
#define PRICE_BUY_LIC_HUNTER_30		20000	

new 
	hunter_zone_damage[MAX_HUNTER_POSITION];

new 
	actor_seller_hunter,
	actor_seller_no_legal_h,
	pos_seller_deer;

new 
	price_seller_hunter_leg[5],
	price_seller_hunter_no_leg[5];


enum hunter_data 
{

	Float:hPosX,
	Float:hPosY,
	Float:hPosZ,

	bool:hSpawned,
	bool:hKilled,
	hObject,

	Text3D: hText,
	Text3D: hText_live,
	hKT,
	hunter_model,
	hunter_zone
};



enum hunter_position 
{
	Float:hpX,
	Float:hpY,
	Float:hpZ
};

new hunter[MAX_HUNTER_POSITION][hunter_data];
