
#define WEAP_LIC_PRICE			30000

#define STREAM_DISTANCE_DYNAMIC_PICKUP	30.0

#define POSITION_SPAWN_1_LVL_1 	1826.789794, 2526.783447, 15.812376, 129.811737
#define POSITION_SPAWN_1_LVL_2 	1826.789794, 2526.783447, 15.812376, 129.811737
#define POSITION_SPAWN_1_FIRST	1826.789794, 2526.783447, 15.812376, 129.811737

#define POSITION_SPAWN_3_LVL_1	1826.789794, 2526.783447, 15.812376, 129.811737


#define TOWN_1_CENTER_POS 		350.0, 1825.2239,2525.8062,15.6610
#define TOWN_2_CENTER_POS 		350.0, 2722.7747,-2447.0801,21.8921
#define TOWN_3_CENTER_POS 		350.0, -489.1782,910.8972,12.1426
#define TOWN_4_CENTER_POS 		350.0, -2459.5256,2839.0706,38.4074

#define TOWN_5_CENTER_POS		350.0,	2501.8269,-2126.1152,23.4458
#define TOWN_6_CENTER_POS		350.0,	-42.5737,923.3008,12.0039
#define TOWN_7_CENTER_POS		350.0,  -491.3420,917.4787,12.1426

#define SPAWN_NONE				0
#define SPAWN_HOSPITAL			1
#define SPAWN_JAIL				2
#define SPAWN_HOUSE				3
#define SPAWN_LAST_POS			4
#define SPAWN_ORG				5
#define SPAWN_DEFAULT			6

#define MAX_PLAYERS_VEHICLE_SL	8

#define NOTIFY_GUI_256_CENTER	1
#define NOTIFY_GUI_256_RIGHT	2
#define NOTIFY_GUI_128_CENTER	3
#define NOTIFY_GUI_128_RIGHT	4


#define TOWN_1_CENTER_POSS		0
#define TOWN_2_CENTER_POSS		1
#define TOWN_3_CENTER_POSS		2
#define TOWN_4_CENTER_POSS		3
#define TOWN_5_CENTER_POSS		4
#define TOWN_6_CENTER_POSS		5
#define TOWN_7_CENTER_POSS		6

#define POSITION_AMMO_1			9.9019,20.3810,1601.8240
#define POSITION_AMMO_2			9.9019,20.3810,1601.8240

#define POSITION_BUY_BOAT_1		2820.6484,-2549.9753,10.4971
#define POSITION_ADM_BOAT_1		2820.4399,-2545.3010,10.5130		

#define BUISNESS_TYPE_PROD		1
#define BUISNESS_TYPE_EAT		2
#define BUISNESS_TYPE_UNIVERGAM	3
#define BUISNESS_TYPE_BAR		4
#define BUISNESS_TYPE_CLUB		5
#define BUISNESS_TYPE_TRANING	6
#define BUISNESS_TYPE_CLOTHES	7
#define BUISNESS_TYPE_AMMO		9
#define BUISNESS_TYPE_FIRE		10 
#define BUISNESS_TYPE_REST		11
#define BUISNESS_TYPE_AKS		12

#define FAST_MENU_HOUSE			7
#define FAST_MENU_TYPE_MONEY	1
#define FAST_MENU_TYPE_SKILL	2
#define FAST_MENU_TYPE_MED		3
#define FAST_MENU_TYPE_HI		4
#define FAST_MENU_TYPE_PASS		5
#define FAST_MENU_TYPE_UDOST	6

#define FAST_MENU_GENERAL_MENU	 1
#define FAST_MENU_GENERAL_PLAYER 2

#define EXPRESS_HEAL_PRICE		1000
#define MEDCARD_PRICE			2000

#define BUISNESS_ID_TUNING		127
#define BUISNESS_ID_DELIVING_1	26
#define BUISNESS_ID_DELIVING_2	27

#define JOBLESS					0
#define FIRE_JOB				1
#define HOSPITAL_JOB			2

#define BUISNESS_FASTFOOD_1_PRICE	200
#define BUISNESS_FASTFOOD_2_PRICE	300
#define BUISNESS_FASTFOOD_3_PRICE	400
#define BUISNESS_FASTFOOD_4_PRICE	700

#define BUISNESS_MECHANIC_1			5000
#define BUISNESS_MECHANIC_2			5001
#define BUISNESS_MECHANIC_3			5002

#define LANG_NONE           "1000000"
#define LANG_ENGLISH		0
#define LANG_RUSSIAN        1
#define LANG_SPAIN          2
#define LANG_PORTUGAL       3
#define LANG_ITALIAN        4
#define LANG_JAPAN          5
#define LANG_FRENCH         6

#define OFFER_PASS						10
#define OFFER_LIC						11
#define OFFER_MECHANIC_INVITE			12
#define OFFER_MECHANIC_REPAIR			13
#define OFFER_MECHANIC_REFILL			14
#define OFFER_MECHANIC_REPAIR_ENGINE	15
#define OFFER_FAMILY_INVITE				16
#define OFFER_TRUCKER_INVITE			17
#define OFFER_SKILL						18
#define OFFER_TAXI_INVITE				19
#define OFFER_MECHANIC_REOIL			20
#define OFFER_UDOST						21

#define PRICE_BUY_SHKAF_HOUSE			65000
#define PRICE_BUY_SEIF_ONE				30000
#define PRICE_BUY_PEOPLE				100000
#define PRICE_BUY_SUBSIDII				120000


#define PRICE_BUY_SHKAF_FLATE			65000
#define PRICE_BUY_SEIF_ONE				30000
#define PRICE_BUY_PEOPLE				100000
#define PRICE_BUY_SUBSIDII				120000


#define INVALID_TIMER_ID 				0

#define GREEN_ZONE_HOSPITAL_1			-1057.5414,-1453.7413,23.4116

#define TEXTDRAW_HIDE					2
#define TEXTDRAW_SHOW					1
#define TEXTDRAW_UPDATE					3

#define KEY_VEHICLE_HORN 				2

#define MAX_JOB_SKILLS					14

#define SKILL_JOB_NONE					0
#define SKILL_MINER 					1
#define SKILL_WOODCUTTER 				2
#define SKILL_BUS_DRIVER				3
#define SKILL_TRUCKER					4
#define SKILL_FACTORY					5
#define SKILL_TAXI						6
#define SKILL_MECHANIC					7
#define SKILL_SNOWWORK					8
#define SKILL_FIRE						9
#define SKILL_BANK						10
#define SKILL_PICKER					11
#define SKILL_FISHER					12

#define INVALID_TIMER_ID 				0


#define PLAYER_IN_MOBILE_VERSION		1
#define PLAYER_IN_PC_VERSION			2

#define GivePVarInt(%1,%2,%3) 								SetPVarIntNew(%1,%2,GetPVarIntNew(%1,%2) + %3)

#define callback::%1(%2) 									forward %1(%2); public %1(%2)
#define RandomEx(%1,%2) 									(random(%2-%1)+%1)

#define MAX_AREAS 4000

#define BYTES_PER_CELL (cellbits / 8)
#define PRESSED(%0) (((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))

#define SFCM(%0,%1,%2) do{new _s[200];format(_s,200,%2);SendClientMessage(%0,%1,_s) ;}while(FALSE)

#define SPFD(%0,%1,%2,%3,%4,%5,%6) do{new _s[400];format(_s,400,%6);show_dialog(%0,%1,%2,%3,_s,%4,%5) ;}while(FALSE)

#define FailMessage(%0) SendClientMessage(%0,CGRAY,"Вам не доступна эта функция")

#define INVALID_HOUSE_ID INVALID_PLAYER_ID


new 
	debug_rpc_packet = 0,
	debug_packet_loss = 1;

new 
	CarMarketPickup[MAX_PLAYERS],
	CarMarketArea[MAX_PLAYERS],
	arCarMarket;

new ControllableTimer[MAX_PLAYERS] = { -1, ... };

enum CarMarket
{
    mOwnerid,
    mPrice,
    mID,
    mNumberCar
}
new CMarketInfo[MAX_PLAYERS][CarMarket];

enum E_AREAS_DATA
{
 	a_item_id,
	a_item_type,
	a_exist,
	a_press_alt
}
new area_info[MAX_AREAS][E_AREAS_DATA];

new 
	all_houses,
	all_flates,
	all_apartaments,
	all_hotels,
	all_hotel_room,
	all_garage,
	all_garage_add,
	all_filling,
	all_casino,
	all_family,
	all_buisness;

new 
	collizion_zone_spawn[3],
	rent_vehicle_n_spawn[6];

new 
	area_quest_npc[7];

new 
	hotel_lift[6],
	hotel_reception;

new 
	sound_zone_stream[15],
	vehicle_sound_car[MAX_PLAYERS];

new 
	timer_key_state_change[MAX_PLAYERS];

new 
	anti_flood_area[MAX_PLAYERS];

new 
	debug_mode;

new 
	load_sklad_server_count; 

#define DEBUG_MODE_ACTIVE	 1
#define DEBUG_MODE_NO_ACTIVE 0

#define DONATE_BONUS_5_HOUR_PLAY	200

#define VEHICLE_ONLINE_BONUS_MODEL	401

#define PICKUP_SIZE 		 3.0

#define H_ENTER		         1
#define H_EXIT		         2
#define B_ENTER		         3
#define B_EXIT		         4
#define LOCATION   	         5
#define GREENZONE      	     6
#define HOUSE_SAFE		     7
#define HOUSE_WARDROBE	     8
#define FLATE_ENTER			 9
#define FLATE_EXIT			 10
#define FLATE_SAFE			 11
#define FLATE_WARDROBE		 12
#define APARTAMENT_ENTER	 13
#define APARTAMENT_EXIT		 14	
#define HOTEL_ENTER			 15
#define HOTEL_EXIT			 16
#define RENT_START_GAME		 17
#define HOTEL_ROOM_ENTER	 18
#define HOTEL_ROOM_EXIT		 19
#define GARAGE_ENTER		 20
#define GARAGE_EXIT_P		 21
#define GARAGE_EXIT_C		 22
#define FILLING_ENTER		 23
#define CASINO_ENTER		 24
#define CASINO_EXIT			 25
#define BUY_CAR_ZONE		 26
#define RENT_CAR_ZONE		 27
#define BUY_CLOTHES_ZONE	 28
#define GARAGE_PANEL_CHANGE	 29
#define BUY_ACCESSORIES_ZONE 30
#define H_G_ENTER			 31
#define PARKING_EXIT		 32
#define PARKING_ENTER 		 33
#define H_G_EXIT 			 34
#define H_G_EXIT_V           35
#define ENTER_QUEST_TEPLICA	 36

#define HOUSE_SELL_PRICE  		(0.80)
#define BUSINESS_SELL_PRICE  	(0.80)

// ----------===== [Лицензии] =====----------
#define LIC_DRIVING 0
#define LIC_FLY 1
#define LIC_BOAT 2
#define LIC_WEAP 3
// ----------===== [Лицензии (конец)] =====----------

// ----------===== [Типы т/с] =====----------
#define VEHICLE_TYPE_CAR 0
#define VEHICLE_TYPE_BOAT 1
#define VEHICLE_TYPE_PLANE 2
#define VEHICLE_TYPE_TWOWEELS 3
// ----------===== [Типы т/с (конец)] =====----------


// ----------===== [Цвета ников] =====----------
#define pcDISABLED 0xFFFFFF00
#define pcWHITE 0xF2E8C9FF
// ----------===== [Цвета ников (конец)] =====----------


// ----------===== [Основные настройки] =====----------
#define MAX_LOGIN_ATTEMPTS 3 //Максимальное количество неудачных попыток ввода пароля
#define BUS_LEVEL_2 100 //К-во рейсов автобуса для перехода на 2 уровень
#define BUS_LEVEL_3 200 //К-во рейсов автобуса для перехода на 3 уровень
#define BUS_ROUTE_COUNT 4 //К-во маршрутов

#define TRUCK_LEVEL_2 30000
#define TRUCK_LEVEL_3 70000
#define TRUCK_LOAD_1 10000
#define TRUCK_LOAD_2 10000
#define TRUCK_LOAD_3 10000
#define MAX_HOUSE_COUNT 889//Макс. к-во домов 738       839         841
#define HINTS_COUNT 47//Точное к-во хинтов +4
#define FILLING_COUNT 9//Точное к-во заправок
#define SHOP_OBJECTS 15//Точное к-во предметов в 24/7
//#define REPAIR_OBJECTS 1//Точное к-во предметов в автомастерских
#define HOTEL_COUNT 7//Точно к-во отелей
#define FRACTION_COUNT 15 //К-во фракций
#define SUBFRACTION_COUNT 5 //К-во фракций
#define BINT_COUNT 19	 //Точное к-во интерьеров бизнесов
#define MAX_BUSINESS_COUNT 130 //Макс к-во бизнесов 116   122 до 10.09    125 до 19.03          126 дл 20.10  128 до 23.02.17
#define BUSINESS_TYPE_COUNT 12 //К-во типов бизнесов
#define MAX_ONFOOT_SPEED 15 //Макс скорость, с которой игрок может перемещаться не в транспорте
#define MAX_INCAR_SPEED 90 //Макс скорость, с которой игрок может перемещаться в транспорте
#define MAX_SPEED 190 //Общая максим. скорость
#define SHOP_COUNT 0//К-во 24/7
#define WANTED_TIME 40//Время исчезновения звезды в минутах
#define JAIL_QUATE 600 //Время заключения в секундах за каждую звезду
#define WARN_TIME 7 //К-во дней до снятия варна
#define SETTINGS_COUNT 4 //К-во настроек
#define CLIENT_TIMEOUT 180 //Таймаут клиента
#define MAX_ADVERT_COUNT 15 //Максимальное кол-во объявлений
#define FILLING_ID_OFFSET 1000 //Смещение ID для заправок в pData[][pBusiness]

#define TAXI_ID_OFFSET 300 //Смещение ID для заправок в pData[][pBusiness]
#define TRUCK_ID_OFFSET 400 //Смещение ID для заправок в pData[][pBusiness]
#define MECH_ID_OFFSET 500 //Смещение ID для заправок в pData[][pBusiness]

#define REPAIR_ID_OFFSET 49 //Стоимость починки
#define TELEPORTS_COUNT 67+8 // Количество обычных телепортов


#define CHAT_INTERVAL 2  	// Интервал антифлуда в чате (в секундах)

new 
	tmpobjid;

new Text:TD[9];

new String64[64];
new String32[32];

new String144[144];

new String128[128];
new String255[255];
new String256[256];
new String256f[256];

new String320[320];
new String512[512];
new String1024[1024];
new String2048[2048];

new String3096[4096+90];

new String4096[4096+90];

new String8096[8096+90];

enum
{
	
	TRIGGER_NONE,
	TRIGGER_BLACK,
	TRIGGER_BLUE,
	TRIGGER_GREEN,
	TRIGGER_GREY,
	TRIGGER_LBLUE,
	TRIGGER_ORANGE,
	TRIGGER_RED	,
	TRIGGER_LRED,
	TRIGGER_REDS,
	TRIGGER_WHITE,
	TRIGGER_YELLOW
};

enum TRANSPORT_CONFIG_DATA
{
	transport_id_sql,
	transport_model,
	transport_name[35],
	transport_price,
	transport_tank,
	transport_class,
	transport_fuel_active,
	transport_sell_active,
	transport_taxi_active,
	transport_max_speed,
	transport_fuel_type,
	transport_fuel_count_km,
	transport_price_rent,
	transport_count_pass,

	Float:transport_engine_inertion,
	Float:transport_handling_speed,
	Float:transport_handling_mass,
	Float:transport_handling_mass_turn,
	Float:transport_handling_acceleration,
	Float:transport_handling_gear,
	Float:transport_brake_deceleration,
	Float:transport_traction_multiplier,
	Float:transport_traction_loss,
	Float:transport_traction_bias,
	Float:transport_suspension_bias,
	Float:transport_wheel_size,
	Float:transport_suspension_limit,
	transport_wheel_angle,
	transport_wheel_offset,
	transport_wheel_width

}

new transport_config[MAX_VEHICLES][TRANSPORT_CONFIG_DATA];


enum TRANSPORT_CONFIG_DATA_SALON
{
	autosalon_config_id,
	autosalon_car_count[30],
	autosalon_car_payday_random
}

new autosalon_transport_config[MAX_VEHICLES][TRANSPORT_CONFIG_DATA_SALON];

enum player_data
{
	pMysqlID,
	pNickname[24],
	pPassword[65],
	pEmail[64],
	pRegIP[16],
	pRPhone[24],
	pMarried,
	pMask,
	pMasked,
	pDivorce[24],
	pWarn,
	pWarnc,
	pMut,
	pEConfirmed,
	pSex,
	pColor,
	pAge,
	pNation,
	pSkin,
	pFractionSkin,
	Float:pHealth,
	pHouse,
	pFlate,
	pHotel,
	pHotelRoom,
	pCar,
	pJob,
	pSalary,
	pMoney,
	pBank,
	pBusSkill,
	pTruckSkill,
	pAdminCode,
	pLevel,
	pExp,
	pPhone,
	pBook,
	pPhoneMoney,
	pWanted,
	pJail,
	pPrison,
	pDrugs,
	pAmmo,
	pGunAmount,
	pSpouse,
	pFraction,
	pSubfraction,
	pRank,
	pDivision,
	pBusiness,
	pWatch,
	pCode[32],
	pAdmin,
	pLicenses[4],
	pStatus,
	pSettings[14],
	pUnemployment,
	pDonate,
	pVehicleKey,
	pArmyTime,
	pArmyRank,
	pDrunk,
	pZakon,
	pPick,
	pSkills[80],
	pRadio,
	pSpawn,
	pJimmy,
	pBCTime,
	pReturnMoney,
	pUpgrade[2],
	pTextType,
	pMedCard,
 	pFight,
	pSkin2,
	pCodeIP,
	pFamily,
	pParty,
	pRation,
	pBiker,
	pBikerRank,
	pJailKey,
	pHDrugs,
	pSmoke,
	pFWarn,
	pKlist,
	pCC,
	pTempID,
	pMob[32],
	pHesh[64],
	pGauth[64],
	pGaON,
	pGaONEX,
	pGaOnTime,
	pCC2,
	pLmt,
	pBlack[80],
	pBlackList[5],
	pBlack2[150],
	pBlackListNew[15],
	pBilet,
	pBilet2,
	pJSkills[80],
	pJSkill[6],
 	pValentins[80],
  	pValentin[13],
 	pWantedinf[80],
  	pWantedi[6],
 	pVakinf[80],
  	pVak[4],
  	pAdver,
  	pAdver2,
  	pAdver3,
  	pGolos,
  	pBDamage,
  	pBWin,
  	pBLoose,
  	pTurma,
  	pTurmaraz,
  	pPvpStat[3],
  	pMobBonus,
  	pHospital,
  	pHospital2,
  	pRacket,
  	pRacketFr,
	pRacketDay,
  	pScoreGame[13],
  	pScoreNY[5],
	pGhettoGame[2],
	pCase,
	pGunSkins[20],
	pGunSkin[4],
	pTruck,
	pTruckRank,
	pTruckCount,
	pTruckCount2,
	pMech,
	pMechRank,
	pMechCount,
	pMechCount2,
	pBus,
	hungry,
	bind_command_1[128],
	bind_command_2[128],
	bind_command_3[128],
	bind_command_4[128],
	bind_command_5[128],
	bind_command_6[128],
	bind_command_7[128],
	bind_command_8[128],
	bind_command_9[128],
	bind_command_10[128],
	bind_command_11[128],
	bind_command_12[128],
	bind_command_13[128],
	bind_command_14[128],
	bind_command_15[128],
	bind_command_16[128],
	bind_command_17[128],
	bind_command_18[128],
	bind_command_19[128],
	bind_command_20[128],
	bind_command_type[21],
	pTester,
	car_sql_1,
	car_sql_2,
	car_sql_3,
	car_sql_4,
	car_sql_5,
	car_id,
	pMechOwnerID,
	pMechOwnerLowID,
	pHouseRent,
	pFlateRent,
	pHotelOwner,
	pGarage,
	pFillStation,
	pPromoFriendActive,
	pPromoFriend,
	pPromoActiveID,
	job_skill[MAX_JOB_SKILLS],
	pCasinoOwner,
	pFamilyRank,
	pTruckerOwnerID,
	pTruckerOwnerLowID,
	pTrucker,
	pTruckerRank,
	pSaltHash[15],
	pTaxi,
	pTaxiOwnerID,
	pTaxiOwnerLowID,
	pTaxiRank,
	pVoiceVolume,
	pVoiceStatus,
	pCarNumberStatus,
	pSlotItem[6],
	pQuestStandart[21],
	pFillCanistra,
	pOilCanistra,
	MD5,
	ActionTimeMoney,
	ActionStatusMoney,
	car_sql_owner,
	hour_played,
	main_timer,
	promocode_bonus_active,
	pRemComplect,
	pQuestNewYear[10],
	pQuestShow,
	pCountSnow,
	p_dialog,
	promocode_admin,
	promocode_admin_time,
	promocode_admin_time_player,
	election_status_p,
	pHunterLic,
	pGreenHouse,
	pFamilyKills,
	pFamilyDeaths,
	pSecurityCode,
	pParkingVehicle,
	pParkingVehicleDay,
	pOnlineDay1,
	pOnlineDay2,
	pOnlineDay3,
	pOnlineDay4,
	pOnlineDay5,
	pOnlineDay6,
	pOnlineDay7,
	pInventoryLevel,
	pMedcard,
	pPlayCar,
	pPlayrCarStatus,
	pPlayDonate,
	pPlayDonateStatus,
	Float:pFamilyKD,
	pBinderCommand_1[144],
	pBinderCommand_2[144],
	pBinderCommand_3[144],
	pBinderCommand_4[144],
	pBinderCommand_5[144],
	pBinderCommand_6[144],
	pBinderCommand_7[144],
	pBinderCommand_8[144],
	pBinderCommand_9[144],
	pBinderCommand_10[144],
	pBinderCommand_11[144],
	pBinderCommand_12[144],
	pBinderCommand_13[144],
	pBinderCommand_14[144],
	pBinderCommand_15[144],
	pBinderCommand_16[144],
	pBinderCommand_17[144],
	pBinderCommand_18[144],
	pBinderCommand_19[144],
	pBinderCommand_20[144],
	pPlayOnlineDonate,
	pPlayOnlineDonateStatus,
	pMutFamily,
	pMutTK,
	pMutTaxi, 
	pMutMech,
	pQuestMarch1,
	pQuestMarch2,
	pQuestMarch3,
	pQuestMarch4,
	pQuestMarch5,
	pSnowdrops
//	pDChat
};

new player_default[player_data] =
{
	0,						// MysqlID						
	"None",					// pNickname		
	"None",					// Password	
	"None",					// Email					
	"0.0.0.0",				// RegIP			
	"None",					// RPhone	
	0,						// ,rried
	0,						// Mask
	0,						// Masked
	"None",					// Divorce
	0,						// Warn
	0,						// Warnc
	0,						// Mute
	0,						//pEConfirmed
	1,						// pSex
	1,						// pColor
	0,						// pAge
	1, 						// pNation
	2,						// Skin
	0,						// FractionSkin
	100.0,					// Health
	-1,						// House
	-1,						// Flate
	-1,						// Hotel
	-1,						// HotelRoom
	-1,						// Car
	SKILL_JOB_NONE,			// Job
	0,						// Salary
	0,						// Money
	0,						// Bank
	0,						// BussSKill
	0,						// TruckSkill
	0,						// Level
	0,						// Exp
	0,						// Phone
	0, 						// pBook
	0, 						// PhoneMoney
	0,						// pWanted
	0,						// pJail
	0,						// pPrison
	0,						// pDrugs
	0,						// pAmmo
	0,						// GunAmount
	0,						// Spouse
	0,						// Fraction
	0,						// SubFraction
	0,						// Rank
	0, 						// Division
	-1,						// Business
	0,						// Watch
	"0",					// Code
	0,						// Admin
	0, 						// Licenses
	0,						// Status
	65535,					// Settings
	0,						// pUnemployment
	0,						// pDonate
	-1,						// pVehicleKey
	0,						// pArmyRank
	0,						// pArmyTime
	0,						// pDrunk
	0,						// pZakon
	0,						// pPick
	0,						// pSkills
	0,						// pRadio
	0,						// pSpawn
	0,						// pJimmy
	0,						// pBCTime
	0,						// pReturnMoney
	0,						// pUpgrade
	0,						// pTextType
	0,						// pMedCard
	0,						// pFight
	0,						// pSkin2
	0,						// pCodeIP
	-1,						// pFamily
	0,						// pParty
	0,						// pRation
	0,						// pBiker
	0,						// pBikerRank
	0,						// pJailKey
	0,						// pHDrugs
	0,						// pSmoke
	0,						// pFWarn
	0,						// pKlist
	0,						// pCC
	0,						// pTempID
	"",						// pMob
	"",						// pHesh
	"",						// Gauth
	0,						// pGaON
	0,						// pGaONEX
	0,						// pGaOnTime
	0,						// pCC2
	0,						// pLmt
	0,						// pBlack
	0,						// pBlackList
	0,						// pBlack2
	0,						// pBlackListNew
	0,						// pBilet
	0,						// pBilet2
	0,						// pJSkills
	0,						// pJSkill
	0,						// pValentins
	0,						// pValentin
	0,						// pWantedinf
	0,						// pWantedi
	0,						// pVakinf
	0,						// pVak
	0,						// pAdver
	0,						// pAdver2
	0,						// pAdver3
	0,						// pGolos
	0,						// pBDamage
	0,						// pBWin
	0,						// pBLoose
	0,						// pTurma
	0,						// pTurmaraz
	0,						// pPvpStat
	0,						// pMobBonus
	0,						// pHospital
	0,						// pHospital2
	0,						// pRacket
	0,						// pRacketFr
	0,						// pRacketDay
	0,						// pScoreGame
	0,						// pScoreNY
	0,						// pGhettoGame
	0,						// pCase
	0,						// pGunSkins
	0,						// pGunSkin
	0,						// pTruck
	0,						// pTruckRank
	0,						// pTruckCount
	0,						// pTruckCount2
	0,						// pMech
	0,						// pMechRank
	0,						// pMechCount
	0,						// pMechCount2
	0,						// pBus
	0,						// hungry
	0,						// bind_command_1
	0,						// bind_command_2
	0,						// bind_command_3
	0,						// bind_command_4
	0,						// bind_command_5
	0,						// bind_command_6
	0,						// bind_command_7
	0,						// bind_command_8
	0,						// bind_command_9
	0,						// bind_command_10
	0,						// bind_command_11
	0,						// bind_command_12
	0,						// bind_command_13
	0,						// bind_command_14
	0,						// bind_command_15
	0,						// bind_command_16
	0,						// bind_command_17
	0,						// bind_command_18
	0,						// bind_command_19
	0,						// bind_command_20
	0,						// bind_command_type
	0,
	INVALID_VEHICLE_ID,		// car_sql
	INVALID_VEHICLE_ID,		// car_sql
	INVALID_VEHICLE_ID,		// car_sql
	INVALID_VEHICLE_ID,		// car_sql
	INVALID_VEHICLE_ID,		// car_sql
	INVALID_VEHICLE_ID,		// car_id
	-1,						// pMechOwnerID
	-1,						// pMechOwnerLowID
	-1,						// pHouseRent
	-1,						// pFlateRent
	-1,						// pHotelOwner
	-1,						// pGarage
	-1,						// pFillStation
	0,
	0,
	-1,
	0,
	-1,
	0,
	-1,
	-1,
	-1,
	0,
	"",
	-1,
	-1,
	0,
	0,
	0,
	-1,
	0,
	1,
	0,
	0,
	0,
	-1,
	-1,
	0,
	0,
	0,
	-1,
	0,
	0,
	0,
	0,
	-1,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	1,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0.0,
	0, // Binder1
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0, //pOnlineDonate
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0
};


enum GZINFO
{
 	idm,
 	Float:gCoords[4],
 	gFrak,
 	gNapad
};

enum PTEMP
{
	bool:pJoined,
	bool:pLogined,
	pLoginAttempt,
	bool:pChoosingSkin,
	pOldVehicleid,
	AntiCrack,
	PlayerStoned,
	FBISkip,
	PDSkip,
	pWork,
	Text3D:pDozerText,
	pDozerID,
	pWorkSalary,
	bool:pJustTP,
	pCarInfoTimer,
	pBusID,
	pCarDriver,
	pBusRoute,
	pBusPos,
	pBusPrice,
	pShowLicpl,
	pShowSkillpl,
	pShowPasspl,
	pShowPassact,

	pShowListpl,
	pShowListact,

	pShowUdpl,
	pShowUdact,

	pShowPtspl,
	pShowPtsact,


	pShowMedpl,
	pShowMedact,

	pShowInv,
	pShowInvact,
	pJaht,
	pJaht2,

	pFampl,
	pFamInv,
	pFamact,

	pPampl,
	pPamInv,
	pPamact,


	pFampl2,
	pFamInv2,
	pFamact2,


	pTruckpl2,
	pTruckInv2,
	pTruckact2,

	pMechpl2,
	pMechInv2,
	pMechact2,

	pShowHipl,
	pShowHiact,

	pShowLicact,
	pShowSkillact,
	Text3D:pBusText,
	pBusSpawnTimer,
	pTruckSpawnTimer,
	Float:pBusDemage,
	pTruckID,
	pTruckWagonID,
	Text3D:pTruckWagonText,
	pTruckWagonTime,
	pTruckWeight,
	pTruckWeight2,
	pTruckLoadID,

	pSellPhoneOffer,
	pSellPhoneNomer,
	pSellPhoneNomerEx,

	pSellPhoneOffee,
	pSellPhonePrice,
	pSellPhonePrice2,

	pSellBiletOffer,
	pSellBiletOffee,
	pSellBiletPrice,

	pSellEggOffer,
	pSellEggOffee,


	bool:pIsInHouse,
	pIsInHouseID,
	pSelectedHouseID,
	pSelectedDomID,
	pSellHouseOffer,
	pSellHouseOffee,
	pSellHousePrice,
	pSellHouseID,
	pSettleHouseOffer,
	pSettleHouseOffee,
	pSettleHouseID,
	bool:pSellCarSelect,
	bool:pSellVertSelect,
	bool:pSellCarSelectTrue,
	PlayerText:pSellCarText,
	pSellCarOffer,
	pSellCarOffee,
	pSellCarPrice,
	pSellCarNum,

	pSellCarID,

	pSellVertOffer,
	pSellVertOffee,
	pSellVertPrice,
	pSellVertID,


	pSellBoatOffer,
	pSellBoatOffee,
	pSellBoatPrice,
	pSellBoatID,

	pSellBusinessOffer,
	pSellBusinessOffee,
	pSellBusinessPrice,
	pSellBusinessID,
	pActPlayer,
	pGiveExp,
	pPayDays,
	pAdminExp,
	pAFK,
	bool:pIsAFK,
	Text3D:pAFKText,
	bool:pShowNicknames,
	PlayerText:pFillingBar[7],
	pFillingBarEx[7],
	bool:pFilling,
	Float:pFillingAmount,
	Float:pFillingSpeed,
	Float:pFillingAccel,
	pFillingID,
 	pFillingPrice,
	pSellFillingOffer,
	pSellFillingOffee,
	pSellFillingPrice,
	bool:pFillGoing,
	bool:pSelectStoreGun,
	bool:pSelectStoreGunEx,
	pMafStoreGun,
	bool:pSelectMafStoreGun,
	pStoreGun,
	Float:pHealth,
	bool:pChangingSkin,
	pCarryProducts,
	pEat,
	bool:pGPS,
	bool:Marked,
	bool:MarkedEx,
	bool:pUseButton,
	pOfferFraction,
	pOfferFractionid,
	pTestQNumber,
	bool:pWaitingExam,
	pExamType,
	pExamSam,
	pExamSamWar,
	bool:pOnExam,
	pExamCandidate,
	bool:pCheat,
	Float:pX,
	Float:pY,
	Float:pZ,

	Float:LASTpX,
	Float:LASTpY,
	Float:LastSpeeds,
	Float:LASTpZ,
	Dritang,
	ModShop,
	WarningFuel,
	WarningFuel2,
	LastSKey,
	LastLRKey,
    Surfid,
    voentime,

	bool:pAbletoTP,
	pAbletoGun,
	bool:pAbletoHP,
	pOff,
	bool:pSpectating,
	pSpectator,
	pSpectatee,
	pCamFly,
	pNotReport,
	pNotReportP,
	pNotRadio,
	pNotReportR,
	pNotReportG,
	pDOS2,
	pLoginTime,
	pShaxTime,
	bool:pAntiDM,
	pHealing,
	pCaller,
	pCallee,
	bool:pCall,
	pIP[16],
	pDM,
	pDarkAFK,
	bool:pDead,
	bool:pInHospital,
	pGangKey,
	pEnterVehicle,
	Float:pAngle,
	pKick,
	pKick2,
	pKick3,
	pCleoFail,
	pTakeGun,
	bool:pDetonator,
	pTazer,
	pCuffer,
	pCuffee,
	pHolder,
	pTied,

	pTROFF,

	pControllable,
	pWorld,
	pKick5,
	pKick6,
	pKick7,
	pKick8,
	pKick9,
	pKick10,

	pinformed,
	pmaskedf,
	odetcol,
	coalamount,
	coalkeys,
	coalkeysW,
	pAnimation,
	pAnimationTime,
	pWarninggun,
	pWarningkey,
	pGun16,
	pGun16Ex,
	pDrugTimes,
	pKickAmmo,
	pKick8Time,
	pOpenMenu,
	pShotTime,
	pShotTimeEx,
	pShots,
	pCoalmanTime,
	bool:pTPhone,
	pCSkin,
	pBangam,
	pSLimit,
	bool:pEconomicLog,
	pSelectedBusinessID,
	bool:pEther,
	pAdvertTime,
	pAntiCleoWood,
	pAntiCleoWoodKick,
	bool:pPresentOn,

	Float:pAcceleration,
	bool:pDialog,
	pDialogID,
	bool:pTazerGun,
	pAbleToStart,
	pWantedListIndex,
	pLastTick,
	pLastTick2,
	pSpecOn,
	bool:pREGISKL,
	bool:pDebtor,
	bool:pLogin4,
	pInviteLeader1,
	pGunSkill[6],
 	bool:BizWar,
	hotelEnter,
	Friend,
	radioTime,
	pFuel,
	pFuel2,
	bankID[5],
	bankCode[5],
	pDFTID,
	pDFTLOAD,
	pDFTLOAD2,
	pDFTLOADEX,
	pDFTMenu,
    pDFTCarMenu,
    pDFTSelected,
	pDFTBiz,
	bool:pDeliving,
	pDeliveryid,
	pDeliveryNumber,
	zSteals,
	pDChat,
	pFChat,
	pEars,
	pEarsD,
	pEarsT,
	pEarsM,
	pBoxing,
	pBoxingPr,
	pBoxingTr,
	pBoxingBot,

	pLastPay,
	pSkinMenu,
	pListall,
	pListwanted,
	pListwanted2,
	pListwantedex[12],
	pFrags,
	pAcceptFree,
	pAcceptFreeact,
	pCasino,
	pSetName,
	pInCasino,
	pInPrez,
	pInMer,
	pInCasino2,
	pCasinoBet[4],
	pBJBet[4],
	pLastTickVH,
	pLastCarVH,
	pStealMenu,
	pBikerMenu,
 	pLastSpeedo,
	pLastIP[16],
	pInTime,
	pWater,
	pStroi,
	pWash,
	pVod,
	pVodPr,
	pWashProc,
	pWashProcOk,
	Float:pWashPos[3],
	Float:pWashCP[3],
	pFarmTime,

 	pAqa,
 	pWMax,

 	pAqaC,
 	pAqaPred[3],
 	pAqaPredType[3],

	pBagSelect[10],
	pBagSelect2[62],

 	pMeshok,
 	pFishOn,
 	pFish,
 	pFish2,
 	pFish3,
 	pTakeShots,
 	pDamage,
 	Float:pDamage2,
 	pCarDamage,
 	pWantedSu,
 	pSmokeUp,
 	pSmokeUpTime,
 	pPTS,
 	pSBilet,
	pCarJob,
	pVESCOP,
	pArmarea,
	pSUD,
	pPOST,
	pReave,
	pMutM,
 	pMafBag,
 	pMafBag2,

 	rent_car_spawn_timer,

 	pPlayer,
 	bind_command_text[128],
 	rent_car,
 	Float:tp_map_x,
 	Float:tp_map_y,
 	Float:tp_map_z,
 	vehicle_speed_timer,
	offer_action,
	offer_playerid,
	offer_time,
	area_item_id,
	area_type,
	spec_playerid,
	speec_id,
	pTaxiPrice,
	Float:pTaxiStart,
	pTaxiPass,
	pTaxiGoing,
	spawn_id,
	Float:crash_pos_x,
	Float:crash_pos_y,
	Float:crash_pos_z,
	Float:crash_pos_r,
	crast_time_clear,
	crash_virtual_world,
	timer_mechanic_call,
	fire_count
};


enum ARs
{

	arGunWork,
	arGunWorkLoad[4],
	arGunWorkLoad2[4],
	arGunWorkWork[6],
	arGunWorkWork2[6],
	arGunWorkWork3[6],
	arGunWorkUnload,
	arGunWorkUnloadEx,

	arKiosk,
	arGreenZone[60],
	arGang[5],
	arGangExit[5],
	arDorm,
	arGangBuyCar,
 	arBank,
	arHire,
	arBarrier[3],
	arArmyAmmo,
	arArmyAmmo2,
 	arArrest[4],
	arKioskPay,
	arKioskPays,
	arDrugDelivery[3],
	arDeliLoad[3],
	arGunFraction[5],
	arBronArmy,
	arBronArmy2,
 	arMaskirovka,
	DrugsPick,
	arEdaArmy,
	arEdaCops,
	arNoobHelp[6],
	arSV[5],
	arVoen,
	arMer[4],
	arFSB[5],
	arVMF[4],
	arVVS[2],
	arCOP[4],
	arMAF[3],

	arPOST[12],

	arPOSTEX[3],

	arPOSTEX2[3],
	arDynamite,
	arDelas,

    arFBR[3],
    arASH,
    arASH1,
    arASH2,
	arMafStore,
	arKazinoJob,
	arSkinVoen,
	arSkinVoen2,
	arFoto,
	arSvadba,
	arDrugsp[8],
	arBuyStrah,
	arShtraf,
	arSdacha,
	arWanteds,
	arSmi,


	arCarBaza[3],
	arHBtp[2],
	arHBhp,
	arHBhp2,
	arHBhp3,
	arHBRadio,
	arNYex,
	arBolka[3],
	arBase,
	arTrack,

	arCarMk,

	arBaseSi[2],
	arBaseJob,
	arJump,
	arParash,
	arJwin,
	arGAI,
	arGAI2,
	TPVIP[2],
	TPMB[2],
	EATMB[2],
	Hellow[6],
	arSdoor[2],
	arSnowZone[25],
	arPole,
	arPole2,
	arMUSIC,
	arHInfo,
	arAshText,
	arMedText,
	arMerText,
	arFSBText,

	arPrezText,
	arPrezText2,
	arPrezText3,
	arPrezText4,
	arEbola,
	arEbola2,
	arMinMO,
	arMinMO2,
	arMinMVD,
	arMinMVD2,
	arMinMZ,
	arMinMZ2,
	arMinSMI,
	arMinSMI2,
	
	arPrezInfo,
	arPrezInfo2,

	arAshGlav,
	arHospitalGlav,
	arLoadMed[2],
	arUnLoadMed[3],
	arCPole[3],
	arHMask[2],
	arAdvTop,
	arAdv2Top
}

new pData[MAX_PLAYERS][player_data];
new pTemp[MAX_PLAYERS][PTEMP];

enum //Диалоги
{
	dMes,// 0
	dLogin, // 1
	dLoginGG, // 1
	dDelGG, // 1
	dDelGG2,
	dLogin2, // 2
	dLogin3,// 3
	dLogin23,// 4
	dRegMenu,// 5
	dRegister,// 6
	dRegister2,// 7
	dRegister22,//8
	dRegisterPhone,// 9
	dRegisterPhone2,// 10
	dRegister3,// 11
	dRegister4,// 12
	dRegister5,//13
	dRegister6,// 14
	dRegister7,// 15
	dPlayerMenu,// 16
	dEmplHistory,//17
	dPlayerMenuSecurity,// 18
	dPlayerMenuSecurityEConfirm,// 1
	dPlayerMenuSecurityEConfirm2,// 20
	dPlayerMenuSettingsAction,
	dDozerwork,
	dCoalwork,
	dWoodwork,
	dWoodwork2,
	dGunWork,//25
	dHire,
	dBusRent,
	dBusRoute,
	dBusPrice,
	dBusEnd,// 30
	dBonnet,
	dBagOpen,
	dBagOpen2,
	dBagOpen3,
	dBagOpen4,
	dBagOpen5,
	dBagOpen6,
	dBagOpen7,
	dBagOpen14,
	dBagOpen15,
	dBagOpen16,
	dBagOpen17,
    dBagOpen66,
	dBagOpen69,
	dBagOpen79,
	dFuelList,
	dTruckWEnd,
	dTaxiWEnd,
	dTruckRent,
	dTruckLoad,
	dTruckLoadR,
	dTruckLoadR2,
	dTaxiRent,
	dLoginAdmins,
	dCreatehouse1,
	dCreatehouse2, //40
	dCreatehouse3,
	dHints,
	dDomInfo,
	dFish,
	dHouseInfo,
	dHouseInfoAr,
	dHouseInfoAr2,
	dHouseInfoAr3,
	dSetRadio,
	dSetSpawn,
	dHouseBuy,
	dHouseMenu, // 50
	dHouseRent,
	dHouseImprove,
	dHouseImprove2,
	dHouseStat,
	dSellHouse,
	dSellHouse2,
	dSellHouseG,
	dSellGarage,
	dSellSim,
	dSellCar2,
	dBuyCarSalon,
	dBuyCar,
 	dTuning, // 60
	dTuning2,
	dBuyCarC1,
	dBuyCarC1Edit,
	dBuyCarC2,
	dBuyCarC2Edit,
	dSellCar,
	dFixCar,
	dSignCar,
	dSignCarEx,
	dSignCarEx2,
	dSignCarEx22, //70
	dSignCarEx3,
	dSignCarEx33,
	dGarage,
	dGarageEx,
	dHotelLift,
	dHotelLift9,
	dHotelLift10,
	dFBILIFT,
 	dHotelGetMoney,
 	dHotelSetCar,
 	dHotelSetEnter,
 	dHotelSell,
 	dHotelOwnMenu, // 80
 	dHotelEnter,
 	dHotelBuy2,
 	dHotelBuy,
 	dHotelReject,
 	dHotelRentEx, // 85
 	dHotelExtend,
 	dHotelRent2,
 	dHotelRent,
 	dHotel,
 	dHotel2,
 	dHotelEx, // 90
 	dHotelEx2,
 	dHotelEx3,
 	dHotel2Ex, // 90
 	dHotel2Ex2,
 	dHotel2Ex3,
	dEbolas,
	dVakMed,
	dVakMed2,
	dAshText,
	dMedText,
	dMerText,
	dFSBText,
	dPrezText,
	dAdmText,
	dMinMO,
	dMinMO2,
	dMinMO3,
	dMinMO4,
	dMinMO5,
	dMinMO6,
	dMinMO7,
	dMinMO8,
	dMinMO9,
	dMinMOEX,
	dMinMOEX2,
    dMinMOEX3,
	dMinMVD,
	dMinMVD2,
	dMinMVD3,
	dMinMVD4,
	dMinMVD5,
	dMinMVD6,
	dMinMVD7,
	dMinMVD8,
	dMinMVDEX,
	dMinMVDEX2,
    dMinMVDEX3,
	dMinMVDPay,
	dMinMVDPayEx,
	dMinMZ,
	dMinMZ2,
	dMinMZ3,
	dMinMZ4,
	dMinMZ5,
	dMinMZ6,
	dMinMZ7,
	dMinMZ8,
	dMinMZEX,
	dMinMZEX2,
    dMinMZEX3,
	dMinMZPay,
	dMinMZPayEx,
	dPrezInfo,
	dPrezInfo2,
	dPrezInfo3,
	dMinSMI,
	dMinSMI2,
	dMinSMI3,
	dMinSMI4,
	dMinSMI5,
	dMinSMI6,
	dMinSMI7,
	dMinSMI8,
	dMinSMIEX,
	dMinSMIEX2,
    dMinSMIEX3,
	dMinSMIPay,
	dMinSMIPayEx,
	dGlavAsh,
	dGlavAsh3,
	dGlavAsh4,
	dGlavAsh5,
	dGlavMed,
	dGlavMed2,
	dGlavMed3,
	dGlavMed4,
	dGlavMed5,
 	dHotelOwner,
 	dHotelOwner2,
 	dReception, // 95
 	dActPlayerMenu,
	dActPlayerMenuMoney,
	dChangePassCode,
	dChangePassPass,
	dChangePass1, //100
	dChangePass2,
	dCodeIP,
	dCodeIPMes,
	dCodeIPSet,
	dCodeIPSet1, //105
	dCodeIPSet2,
	dCode,
	dCodeMes,
	dCodeSet,
	dCodeSet1, // 110
	dCodeSet2,
	dMaskirovka,
	dMafStore,
	dMafStorePut,
	dMafStorePut1, //130
	dMafStoreGet,
 	dStore,
	dStorePut,
	dStorePut1,
	dStoreGet1, //135
	dStoreGet, //135
	dStoreDress,
	dDelSkin,
	dStoreSkin,
	dStoreSkin2,
	dSafe,// 140
	dSafeCode,
	dSafeCodeChange,
	dSafeCodeChange2,
	dSafeAction,
	dSafePutMoney, //145
	dSafeGetMoney,
	dSafePutDrug,
	dSafeGetDrug,
	dSafePutDrug2,
	dSafeGetDrug2,
	dFreez,
	dBuySkin, //150
	dBuySkin2,
	dGrocer,
	dGrocer2,
	dGPS,
	dGPSTaxi,
	dGPSAir, //155
	dGPSWork,
	dGPSWork2,
	dGPSMain,
	dGPSAuto,
	dGPSTruck,
	dGPSMech,
	dGPSMafiiBandi, //160
	dGPSGosOrg,
	dGPSBanki,
	dGPSLotto,
	dGPSBizz, // 163
	dMAFBizz,
	dMAFCONT,

	dMAFCONT2,
	dMAFCONT3,
	dMAFCONT4,
	dMAFCONT5,

	dGPSOteli,
	dBuyFood,// 165
	dLeaderskin,
	dMakeleader,
	dInvite,
	dInviteSkin,
	dSetRank,// 170
	dSetDivision,
	dFractionSkin,

	dHeal,//195
	dHealVak,//195
	dReport,
	dReportRadio,
	dNameChange,
	dUpgrades,//200
	dUpgrades2,
	dUpgrades3,
	dKiosk,
	dATM,
	dATMWatch,
	dATMGet,
	dShop,
	dRestoran,
	dRestoranMenu1,
	dRestoranMenu2,//210
	dRestoranMenu3,
	dRestoranMenu4,
	dMOLeader,
	dSVLeader,
	dSVLeader2,
	dVMFLeader,

	dMafLeader,

	dGangLeader,
	dGangRank,
	dGangRank2,
	dSellGangCar,//220
	dSellGangCar2,
	dCredentials,
	dCredentials2,
	dMakeGun,
	dMakeGun2,
	dBuyGangCar,
	dATMPut,
	dATMPhone,
	dCommandList,
	dCommandShow,//230
	dCommandMain,
	dBank,
	dSelveh,
	dCreaterace,
	dSelrace,
	dAnimliber,
	
	dAnimliberNew,
	dAnimliberNew2,

    dBuyBusinessentpr,
	dBuyShop,
	dBuyShop2,
	dEnterShop,//240
	dSubleader,
	dStopLoad,
	dService,
	dServicePrez,
	dEmergencyCall,
	dMechRent,
	dTow,
	dUnfill,
	dGobGun,
	dGobAmmo,
	dDissolution,
	dEmergencyPolice1,
	dEmergencyMedic1,
	dEmergencyMechanic1,
	dLotto,
	dLotto2,

	dGaiMenu,

	dBuyBusiness1,
	dBuyBusiness2,
	dBusiness,
	dBusinessUpg,
	dBusinessStat,
	dBusinessBank,
	dBusinessGet,
	dBusinessPut,
	dBusinessSell,
    dBusinessEnter,
	dBusinessOrder1,
	dBusinessOrder2,
	dBusinessOrder3,
	dBusinessOrder4,
	dBusinessPrice,
	dBusinessBuyProd1,
	dBusinessBuyProd2,
	dBusinessJob,
	dBusinessJobI,
	dBusinessJobD,
	dBusinessJ,
	dBusinessOrder1J,
	dBusinessOrder2J,
	dBusinessPriceJ,
	dBusinessEnterJ,
	dBints,
	dBar,
	dBarEx,
	dBarEx2,
	dAdvertSend,
	dAdvertList,
	dAdvertAction,
	dAdvertAction1,
	dAdvertCancel,
	dAdvertEdit,
	dNewsDial,
	dNumberPhone,
	dPresentPhone,
	dUnemplyment,
	dPrize,
	dPrizeEx,
    dPrizeEXES,
	dDonate,
	dDonatePhone1,

	dDonateSex,
	dDonateWarn,
	dDonateZak,
	dDonateLot,
	dDonateInfo,
	dDonateMoney1,
	dDonateMoney2,
	dDonateNickname1,
	dDonateNickname2,
	dDonateNation1,
	dDonateNation2,
	dDonateNation3,
	dDonateAge1,
	dDonateAge2,
	dPhoneConfirm1,
	dPhoneConfirm2,
	dRecolor,
	dWeather,
	dSellZone,
	dSellZone2,
	dZaxvat,
 	dDutyGun,
	dDutyGunFbi,
	dObshakEd,
	dObshakPt,
	dObshakMn,
	dObshakPttake,
	dObshakPtput,
	dObshakEdput,
	dObshakEdtake,
	dObshakMntake,
	dObshakMnput,
	dObshak,
	dObshakNark,
	dObshakNarkput,
	dObshakNarktake,
	dObshakNarkput2,
	dObshakNarktake2,
	dNoobHelp0,
	dNoobHelp1,
	dNoobHelp2,
	dNoobHelp3,
	dNoobHelp4,
    dNoobHelp5,
	dOBankMenu,
	dOBankMenu2,
	dOBankMenu3,
	dOBankMenu4,
	dOBankMenu5,
	dOBankMenu6,
	dBankMenu, // 340
	dBankMenuATM,
     dFerma,
    dFerma2,
    dFerma3,
     dGun,
    dGun1,
    dGun2,
    dGun3,
    dGun4,
	dGun5,
	dGun6,
 	dRentCar,
 	dDebtor,
 	dDebtorHouse,
 	dDebtorHouse1,
 	dDebtorHouse2,
 	dDebtorHouse3,
 	dVibori,
 	dVibori1,
 	dVibori2,
 	dVibori3,
 	dVibori4,
 	dRadio,
 	dRadioPlay,
 	dRadioEx,
	dMEGAPHONE_MENU,
 	dRegisterPovtor,
 	dInviteLeader,
 	dInviteSkinLeader,

 	dBikeGun,
 	dBikeGun1,
 	dBikeGun2,
 	dBikeGun3,
 	dBikeGun4,

 	dMafiaGun,
 	dMafiaGun1,
 	dMafiaGun2,
 	dMafiaGun3,
 	dMafiaGun4,
 	dMafiaBomb,

 	dMafia1,
 	dMafia,
 	dMafiaEx,
 	dMafia2,
 	dMafia3,
 	dMafia4,
 	dMafia5,
 	dMafia6,
 	dMafia7,
 	dMafia8,
 	dBizWar,
 	dBBizWar,
 	dBBizWar2,
 	dAzsWar,
 	dCopTake,
 	dShowHouse,

 	dMAPMenu,
 	dMAPCreate,

	dMAPCreate2,
	dMAPCreate3,
	dMAPCreate4,
	dMAPCreate5,

 	dSoeMenu,
 	dAntiCheats,
 	dSoeCreate,
 	dSoeSelect,
 	dSoeSelect2,
 	dSoeTutorial,
 	dSoeDel,
 	dSoeSave_1,
 	dSoeSave_2,
 	dHippy,
	dHippyFree,
 	dBuyFuel,
 	dCreateBank, // 390
	dBankSetName,
	dBankSetCode,
	dBankSetCode1,
	dBankSetCode2,
	dBankTransfer,
	dBankTransfer1,
	dBankDeposit,
	dBankWithdraw,
	dBankShow, // 399
	dBankShow1,
	dBankCode,
 	dDFTRent,
 	dDeliveryOpen,
	dDeliveryOpen2,

	dDeliveryList,
	dDeliveryMenu,

	dBusinessDelivery1,
	dBusinessDelivery2,


	dSkinDel,
	dFBRmusic,

	dHBShow,
	dFreeHouses,
	dFreeBusiness,
	dHouseInfos,
	dHouseInfos2,
	dBusiInfos,
	dBusiInfos2,
	dMesEx,
	dMesEx2,
	dMesEx3,
	dDelas,
	dDelas2,
	dMesFa,
	dMesPa,
	dMesMaf,
	dMesMaf2,

	dCasinoMenu,
	dVskinMenu,
	dSvadbaMenu,
	dShtrafMenu,
	dSdachaMenu,
	dKaznaMenu,
	dKaznaMenuGos,
	dKaznaMenuGos1,
	dKaznaMenuGos2,
	dKaznaMenuGos3,
	dKaznaMenuGos4,
	dKaznaMenuGos5,
	
	dKaznaMenu6,
	dKaznaMenu66,
	dKaznaMenu7,
	dKaznaMenu77,

	dKaznaMenu8,
	dKaznaMenu88,

	dKaznaMenu9,
	dKaznaMenu99,
	dKaznaMenu10,
	dKaznaMenu100,

	dKaznaMenu2,
	dKaznaMenu3,
	dKaznaMenu4,
	dKaznaMenu5,
	dKaznaMenuNal,
	dKaznaMenuPen,
	dKaznaMenuPen2,
	
	dKaznaMenuVic,
	dKaznaMenuVic2,
	
	dBetDeal,
	dBetDeal2,
	dBetEnd,
	dBetEnd2,
	dInvMenu,
	dInvMenu2,
	dDropInv,
	dDropInv2,
	dShopAcc,
	dShopDance,
	dShopDance2,
	dShowBook,
	dShowBookAdd,
	dShowBookAdd2,
	dShowBookMenu,
	dShowBookSms,		

	INVALID_DIALOG_ID,

	dDonateSnowNew,

	DIALOG_SELL_SNOWDROPS,
	DIALOG_TAKE_BRILLIANTS,
	DIALOG_MARCH_QUEST_SELECT,
	DIALOG_MARCH_QUEST_1,
	DIALOG_INPUT_GIFT_MESSAGE,

	DIALOG_GENERAL_ATM,
	DIALOG_ATM_GET,
	DIALOG_ATM_PUT,
	DIALOG_ATM_PHONE,

	SELECT_TYPE_BINDER_PLAYER,
	DIALOG_SELECT_FAQ_CATEGORY,
	DIALOG_SELECT_FAQ_WORK,
	DIALOG_SELECT_FAQ_BUY,
	DIALOG_SELECT_FAQ_OTHER,
	DIALOG_FAQ_WORK,
	DIALOG_FAQ_BUY,
	DIALOG_FAQ_OTHER,
	DIALOG_SELECT_BINDER,
	DIALOG_NEW_COMMAND_BINDER,
	DIALOG_FASTMENU_PAY,
	DIALOG_EXPRESS_HEAL,
	DIALOG_SELECT_FAST_MENU_P,
	DIALOG_SELL_MEDCARD,
	DIALOG_ACCEPT_MEDCARD,
	DIALOG_CHANGE_PANEL_BIZ_P,
	DIALOG_BUY_PARKING,
	DIALOG_SELECT_PARKING_ENTER,
	DIALOG_CHANGE_BIZ_RENT_PRICE,
	DIALOG_SECURITY_SELECT,
	DIALOG_CHANGE_PASS_CODE,
	DIALOG_CHANGE_PASS_OLD,
	DIALOG_CHANGE_PASS_NEW,
	DIALOG_CHANGE_PASS_REPEAT,
	DIALOG_SELECT_CODE,
	DIALOG_CHANGE_CODE_OLD,
	DIALOG_CHANGE_CODE_NEW,
	DIALOG_ADD_CODE,
	DIALOG_REMOVE_SECURITY_CODE,
	DIALOG_INPUT_SECURITY_CODE,
	
	D_ALOGIN,

	DIALOG_SELECT_TYPE_HOUSE,
	DIALOG_CHANGE_RANK_FAM_P,
	DIALOG_CHANGE_FAMILY_NAME_RANK,
	DIALOG_CHANGE_FAMILE_RANK_INPUT,
	DIALOG_CHANGE_FAM_RANK_INV,
	DIALOG_CHANGE_FAM_RANK_UNINV,
	DIALOG_CHANGE_FAMILY_GIVE_RANK,
	DIALOG_SELECT_TYPE_BUY_CAR,

	DIALOG_SELECT_VEH_TK_C,
	DIALOG_BUY_TRUCKER_PERSON,
	DIALOG_BUY_TRUCKER_LEVEL,
	DIALOG_SELECT_BANK_WORK,
	DIALOG_ACCEPT_BANK_WORK,
	DIALOG_TRASH_WORK_START,
	DIALOG_TRASH_WORK_END,
	DIALOG_START_TRANING_PLAYER,
	DIALOG_PLAYER_VEHICLE_LIST,
	DIALOG_GENERAL_REALTOR_AGENCY,
	DIALOG_REALTOR_FREE_HOUSE,
	DIALOG_REALTOR_FREE_FLATE,
	DIALOG_REALTOR_FREE_FILL,
	DIALOG_REALTOR_FREE_HOTEL,
	DIALOG_REALTOR_FREE_GARAGE,
	DIALOG_REALTOR_FREE_MECH,
	DIALOG_REALTOR_FREE_TK,
	DIALOG_REALTOR_FREE_TAXI,
	DIALOG_REALTOR_FREE_BIZ,
	DIALOG_REALTOR_INFO_HOUSE,
	DIALOG_REALTOR_INFO_FLATE,
	DIALOG_REALTOR_INFO_FILL,
	DIALOG_REALTOR_INFO_HOTEL,
	DIALOG_REALTOR_INFO_GARAGE,
	DIALOG_REALTOR_INFO_TK,
	DIALOG_REALTOR_INFO_TAXI,
	DIALOG_REALTOR_INFO_BIZ,
	DIALOG_REALTOR_INFO_HOUSE_2,
	DIALOG_REALTOR_INFO_FLATE_2,
	DIALOG_REALTOR_INFO_FILL_2,
	DIALOG_REALTOR_INFO_HOTEL_2,
	DIALOG_REALTOR_INFO_GARAGE_2,
	DIALOG_REALTOR_INFO_MECH_2,
	DIALOG_REALTOR_INFO_TK_2,
	DIALOG_REALTOR_INFO_TAXI_2,
	DIALOG_REALTOR_INFO_CASINO_2,
	DIALOG_REALTOR_INFO_BIZ_2,
	DIALOG_REALTOR_INFO_MECH,


	DIALOG_CHANGE_PANEL_BIZ_R,
	DIALOG_CHANGE_BIZ_ENTER_PRICE,
	DIALOG_BACK_FISH_ACTOR,
	DIALOG_SELLER_FISH,
	DIALOG_SELL_FISH_FINAL,
	DIALOG_ACTION_INV_ITEMS_AKS,
	DIALOG_SELECT_BUY_SEMENA,
	DIALOG_SELECT_GREEN_HOUSE,
	DIALOG_SELL_SEMENA_GREEN_H,
	DIALOG_BUY_TEPLICA,
	DIALOG_BUY_SEMENA_GREEN_H,
	DIALOG_REPORT_SEND,
	DIALOG_BREAK_SELECT,
	DIALOG_REPORT_ANSWER,
	DIALOG_BACK_HUNTER_NO_LEGAL,
	DIALOG_SELL_LEG_MEET_1_N,
	DIALOG_SELL_LEG_MEET_2_N,
	DIALOG_SELL_LEG_MEET_3_N,
	DIALOG_SELL_LEG_MEET_4_N,
	DIALOG_SELL_LEG_MEET_1,
	DIALOG_SELL_LEG_MEET_2,
	DIALOG_SELL_LEG_MEET_3,
	DIALOG_SELL_LEG_MEET_4,
	DIALOG_SELLER_HUNT_LEGAL,
	DIALOG_SELLER_HUNT_NO_LEGAL,
	DIALOG_BACK_HUNTER_LEGAL,


	DIALOG_ACTION_INVENTORY_ITEMS,
	DIALOG_BUY_REALTOR,
	DIALOG_INFO_REALTOR,
	DIALOG_SELECT_ENTER_REALTOR,
	DIALOG_UNPARK_VEHICLE,
	DIALOG_CAR_CHANGE,
	DIALOG_FIRE_PANEL,
	DIALOG_FIRE_WATER_BUY,
	DIALOG_MENU_ELECTION_ADMIN,
	DIALOG_MENU_ELECTION_PERSON,
	DIALOG_MENU_ELECTION_PERSS,
	DIALOG_MENU_ELECTION_PLAYER,
	DIALOG_CHANGE_PROMOCODE_ADMIN,
	DIALOG_CHANGE_PROMOCODE_FINAL,
	DIALOG_ACTIVATE_PROMO_ADMIN,
	DIALOG_FINAL_CREATE_DYNAMIC_P,
	DIALOG_CREATE_PROMO_A_Y,
	DIALOG_SELECT_PROMO_A_Y,
	DIALOG_SELECT_PROMO_DYNAMIC,
	DIALOG_PROMO_DYNAMIC_LEVEL_MIN,
	DIALOG_PROMO_DYNAMIC_LEVEL_MAX,
	DIALOG_PROMO_DYNAMIC_PLAY,
	DIALOG_PROMO_DYNAMIC_ACTIVE,
	DIALOG_PROMO_DYNAMIC_MONEY,
	DIALOG_PROMO_DYNAMIC_EXP,
	DIALOG_PROMO_DYNAMIC_SKIN,
	DIALOG_PROMO_DYNAMIC_DONATE,
	DIALOG_PROMO_DYNAMIC_VEHICLE,
	DIALOG_PROMO_DYNAMIC_WEAPON_1,
	DIALOG_PROMO_DYNAMIC_WEAPON_2,
	DIALOG_PROMO_DYNAMIC_WEAPON_3,
	DIALOG_PROMO_DYNAMIC_WEAPON_4,
	DIALOG_PROMO_DYNAMIC_WEAPON_5,
	DIALOG_PROMO_DYNAMIC_WEAPON_6,
	DIALOG_CREATE_PROMO_A_Y_1,
	DIALOG_SELECT_PROMO_START_P,

	DIALOG_SELECT_CAR_MAFIA_1,
	DIALOG_SELECT_CAR_MAFIA_2,
	DIALOG_SELECT_CAR_MAFIA_3,
	DIALOG_SELL_DRUGS,
	DIALOG_CHANGE_PERCENT_MECHANIC,
	DIALOG_SELECT_CHARITY,	
	DIALOG_CHARITY_INPUT,
	DIALOG_MAKE_GUN_LIST,
	DIALOG_MAKE_GUN_INPUT,
	DIALOG_REPAIR_VEHICLE_ACCEPT,
	DIALOG_FILLING_VEHICLE_ACCEPT,
	DIALOG_FILL_OIL_VEHICLE_ACCEPT,
	DIALOG_BUY_TRUCKER_VEHICLE,
	DIALOG_ARMY_KITCHEN,
	DIALOG_ARMY_SELECT_GUN,
	DIALOG_CANCEL_ARMY_LOAD,
	DIALOG_LMENU_SELECT_MAFIA,
	DIALOG_MSTORE_SELECT,
	DIALOG_MTAKE_PATRONS,
	DIALOG_MTAKE_GUNS,
	DIALOG_MTAKE_DRUGS,
	DIALOG_MTAKE_HDDRUGS,
	DIALOG_MTAKE_MONEY,
	DIALOG_MGIVE_PATRONS,
	DIALOG_MGIVE_GUNS,
	DIALOG_MGIVE_DRUGS,
	DIALOG_MGIVE_HDDRUGS,
	DIALOG_MGIVE_MONEY,
	DIALOG_LMENU_EDITRANK,
	DIALOG_CHANGE_PERMISSION,
	DIALOG_LMENU_RANKLIST,
	DIALOG_CHANGE_RANGNAME,
	DIALOG_NOTIFY_SELECT,
	DIALOG_ACCEPT_DIPLOMACY,

	DIALOG_BIZWAR_ACCEPT,
	DIALOG_BIZWAR_SELECT,
	DIALOG_CREATE_MAFIA_NOTIFY,

	DIALOG_SELL_SNOW,

	DIALOG_OPEN_NEW_YEAR_PRIZE,
	DIALOG_SELECT_PRIZE_CAR,
	DIALOG_SELECT_PRIZE_ACS,

	DIALOG_BUY_MENU_NEWYEAR,
	DIALOG_BUY_MENU_NEWYEAR_EAT,
	DIALOG_BUY_MENU_NEWYEAR_BUHLO,
	DIALOG_BUY_MENU_NEWYEAR_KIDS,

	DIALOG_GPS_NEWYEAR,
	DIALOG_GPS_NEWYEAR_ADMIN,

	DIALOG_ACCEPT_SNOW_WORK,
	DIALOG_CANCEL_SNOW_WORK,
	DIALOG_SELECT_SNOW_WORK,

	DIALOG_SELL_SIM,
	DIALOG_TRADE_SIM,
	DIALOG_ACCEPT_SELL_AZS_GOS,
	DIALOG_SELECT_QUEST_START,
	DIALOG_SELECT_QUEST_INFO,
	DIALOG_RENT_VEHICLE_MECH,

	DIALOG_ACCEPT_MECH,
	DIALOG_BUY_WEAP_LIC,

	DIALOG_RELAX_GPS,
	DIALOG_RELAX_GPS_ADMIN,

	DIALOG_INVITE_FAMILY_ACCEPT,
	DIALOG_NEW_PASS_MD5,
	DIALOG_CLUB_BUY_MENU_BAR,
	DIALOG_FILLING_SELECT_MENU,
	DIALOG_ELEVATOR_MOSCOW_CITY,
	DIALOG_WARDROBE_POLKA_AKS_1_F,
	DIALOG_WARDROBE_POLKA_AKS_2_F,
	DIALOG_WARDROBE_POLKA_AKS_3_F,
	DIALOG_SELECT_WARDROBE_F_P_1_1,
	DIALOG_SELECT_WARDROBE_F_P_1_2,
	DIALOG_SELECT_WARDROBE_F_P_1_3,
	DIALOG_WARDROBE_POLKA_AKS_1,
	DIALOG_WARDROBE_POLKA_AKS_2,
	DIALOG_WARDROBE_POLKA_AKS_3,
	DIALOG_SELECT_WARDROBE_P_1_1,
	DIALOG_SELECT_WARDROBE_P_1_2,
	DIALOG_SELECT_WARDROBE_P_1_3,
	DIALOG_BUY_AKS_SHOP,
	DIALOG_INFO_AKS_SHOP,
	DIALOG_SELECT_ENTER_AKS,
	DIALOG_BUY_AKS_FINAL,
	DIALOG_SELECT_AKS,
	DIALOG_BUY_AKS_PREW,

	DIALOG_SITE_MENU_P,
	DIALOG_SELECT_ANIM,
	DIALOG_CONFIG_CAR_PASS,

	DIALOG_CAR_CHANGE_PANEL,
	DIALOG_ACCEPT_CAR_FINAL,

	DIALOG_ACCEPT_BUY_CAR_RINOK,

	DIALOG_AUTORISATION_PC_VERSION,

	DIALOG_INVITE_P_ACCEPT,
	DIALOG_INVITE_M_P_ACCEPT,

	DIALOG_SELECT_NUMBER_VEH,
	DIALOG_CHANGE_NUMBER_CAR_PR,

	DIALOG_ACCEPT_SELL_TAXI_GOS,
	DIALOG_ACCEPT_SELL_TRUCKER_GOS,

	DIALOG_SELECT_REGION_1,
	DIALOG_SELECT_REGION_2,
	DIALOG_SELECT_REGION_3,
	DIALOG_SELECT_REGION_4,

	DIALOG_SELECT_REGION_1_BUY,
	DIALOG_SELECT_REGION_2_BUY,
	DIALOG_SELECT_REGION_3_BUY,
	DIALOG_SELECT_REGION_4_BUY,

	DIALOG_SELECT_SELL_P_P,
	DIALOG_SELL_HOUSE_PLAYER,
	DIALOG_SELL_FLATE_PLAYER,
	DIALOG_SELL_GARAGE_PLAYER,
	DIALOG_SELL_FILLING_PLAYER,
	DIALOG_SELL_BIZ_PLAYER,
	DIALOG_SELL_HOTEL_PLAYER,
	DIALOG_SELL_CASINO_PLAYER,
	DIALOG_SELL_TK_PLAYER,
	DIALOG_SELL_MECHANIC_PLAYER,
	DIALOG_SELL_TAXI_PLAYER,
	DIALOG_ACCEPT_BUY_HOUSE_P,
	DIALOG_ACCEPT_BUY_FLATE_P,
	DIALOG_ACCEPT_BUY_GARAGE_P,
	DIALOG_ACCEPT_BUY_FILL_P,
	DIALOG_ACCEPT_BUY_BIZ_P,
	DIALOG_ACCEPT_BUY_HOTEL_P,
	DIALOG_ACCEPT_BUY_CASINO_P,
	DIALOG_ACCEPT_BUY_TK_P,
	DIALOG_ACCEPT_BUY_MECH_P,
	DIALOG_ACCEPT_BUY_TAXI_P,


	DIALOG_START_TRUCKER_JOB_1,
	DIALOG_START_TRUCKER_JOB,

	DIALOG_HANDLING_CONFIG_1,
	DIALOG_HANDLING_CONFIG_2,
	DIALOG_HANDLING_CONFIG_3,
	DIALOG_HANDLING_CONFIG_4,
	DIALOG_HANDLING_CONFIG_5,
	DIALOG_HANDLING_CONFIG_6,
	DIALOG_HANDLING_CONFIG_7,
	DIALOG_HANDLING_CONFIG_8,
	DIALOG_HANDLING_CONFIG_9,
	DIALOG_HANDLING_CONFIG_10,
	DIALOG_HANDLING_CONFIG_11,
	DIALOG_HANDLING_CONFIG_12,
	DIALOG_HANDLING_CONFIG_13,
	DIALOG_HANDLING_CONFIG_14,
	DIALOG_HANDLING_CONFIG_15,
	DIALOG_HANDLING_CONFIG_16,
	DIALOG_CONFIG_VEH_HANDLING,

	DIALOG_SELECT_CAR_GOV,
	DIALOG_SELECT_CAR_FEDERAL,
	DIALOG_SELECT_CAR_POLICE,
	DIALOG_SELECT_CAR_NEWS_1,
	DIALOG_SELECT_CAR_NEWS_2,
	DIALOG_SELECT_CAR_HOSPITAL_1,
	DIALOG_SELECT_CAR_HOSPITAL_2,
	DIALOG_SELECT_CAR_ARMY_1,
	DIALOG_SELECT_CAR_ARMY_2,
	DIALOG_SELECT_CAR_ARMY_3,

	DIALOG_ACCEPT_SELL_HOTEL,
	DIALOG_ACCEPT_SELL_HOUSE,
	DIALOG_ACCEPT_SELL_GARAGE,
	DIALOG_ACCEPT_SELL_CASINO,
	DIALOG_ACCEPT_SELL_BUISNES,
	DIALOG_ACCEPT_SELL_FLATE,
	DIALOG_ACCEPT_SELL_MECHANIC,


	DIALOG_BUY_PROD_ORDER,
	DIALOG_PANEL_BUISNES_CONTROL,

	DIALOG_GPS_SHOW,
	DIALOG_GPS_JOB,
	DIALOG_GPS_OTHER,
	DIALOG_GPS_CAR,
	DIALOG_GPS_GOS,
	DIALOG_GPS_CRIME,
	DIALOG_GPS_HOTEL,
	DIALOG_GPS_TAXI,
	DIALOG_GPS_TRUCKER,
	DIALOG_GPS_STO,

	DIALOG_GPS_SHOW_ADMIN,
	DIALOG_GPS_JOB_ADMIN,
	DIALOG_GPS_OTHER_ADMIN,
	DIALOG_GPS_CAR_ADMIN,
	DIALOG_GPS_GOS_ADMIN,
	DIALOG_GPS_CRIME_ADMIN,
	DIALOG_GPS_HOTEL_ADMIN,
	DIALOG_GPS_TAXI_ADMIN,
	DIALOG_GPS_TRUCKER_ADMIN,
	DIALOG_GPS_STO_ADMIN,

	DIALOG_BUY_FASTFOOD_PRODUCT,

	DIALOG_BUS_START,
	DIALOG_BUS_CONTINUE,
	DIALOG_SELECT_ROUTE,

	DIALOG_SELECT_FISH_OTHER,
	DIALOG_SELECT_FISH_ROD,
	DIALOG_SELECT_FISH_CASA,
	DIALOG_SELECT_FISH_BUY,

	DIALOG_BUY_MECHANIC,
	DIALOG_CHANGE_MECHANIC,
	DIALOG_CHANGE_MECHANIC_BANK,
	DIALOG_MECHANIC_INPUT_MONEY,
	DIALOG_MECHANIC_PUT_MONEY,
	DIALOG_CHANGE_TARIF_MECHANIC,
	DIALOG_CHG_TARIF_MECH_1,
	DIALOG_CHG_TARIF_MECH_2,
	DIALOG_CHG_TARIF_MECH_3,
	DIALOG_CHG_TARIF_MECH_4,
	DIALOG_CHG_TARIF_MECH_5,
	DIALOG_CHG_TARIF_MECH_6,
	DIALOG_CHG_TARIF_MECH_7,
	DIALOG_CHG_TARIF_MECH_8,
	DIALOG_CHG_TARIF_MECH_9,
	DIALOG_CHG_TARIF_MECH_10,
	DIALOG_CHANGE_PERCENT,
	DIALOG_CHANGE_MECH_PHONE,
	DIALOG_CHANGE_MECH_NAME,
	DIALOG_MECHANIC_CHANGE_PERS,
	DIALOG_MECHANIC_CHANGE_PERS_2,
	DIALOG_START_MECH_JOB,
	DIALOG_START_MECH_JOB_1,
	DIALOG_PERSONAL_CLOSE,
	DIALOG_SELECT_ENGINE_MECH,
	SHOW_CHANGE_MENU_HOUSE_4,
	DIALOG_RENT_HOUSE_P,

	DIALOG_BUY_HOUSE,
	DIALOG_INFO_HOUSE,
	DIALOG_INFO_RENT_HOUSE,
	SHOW_CHANGE_MENU_HOUSE_PEOP_ALL,
	SHOW_CHANGE_MENU_HOUSE_2,
	SHOW_CHANGE_MENU_HOUSE_UPGRADE,
	SHOW_CHANGE_MENU_HOUSE_1,
	SHOW_CHANGE_MENU_HOUSE_3,
	DIALOG_CHANGE_PRICE_PEOPLE,
	DIALOG_CHANGE_MANAGE_MENU,
	DIALOG_SELECT_DAY_RENT,
	DIALOG_END_RENT_HOUSE,
	DIALOG_CONTINUT_RENT_HOUSE,
	DIALOG_CODE_SAFE_INPUT,
	DIALOG_CHANGE_PASS_SAFE,
	DIALOG_SAFE_GENERAL,
	DIALOG_CHANGE_SAFE_SELECT,
	DIALOG_GENERAL_MENU_DRUGS,
	DIALOG_INPUT_MENU_DRUGS,
	DIALOG_PUT_MENU_DRUGS,
	DIALOG_INPUT_MENU_DRUGS_HARD,
	DIALOG_PUT_MENU_DRUGS_HARD,
	DIALOG_GENERAL_MENU_DRUGS_HARD,
	DIALOG_INFO_DRUGS_ALL,
	DIALOG_GENERAL_MENU_MONEY,
	DIALOG_INPUT_MENU_MONEY,
	DIALOG_PUT_MENU_MONEY,

	DIALOG_GENERAL_WARDROBE,
	DIALOG_WARDROBE_POLKA_1,
	DIALOG_WARDROBE_POLKA_2,
	DIALOG_WARDROBE_POLKA_3,

	DIALOG_WARDROBE_GUN_1,
	DIALOG_WARDROBE_GUN_2,
	DIALOG_WARDROBE_GUN_3,


	DIALOG_BUY_FLATE,
	DIALOG_INFO_FLATE,
	DIALOG_INFO_RENT_FLATE,
	SHOW_CHANGE_MENU_FLATE_1,
	SHOW_CHANGE_MENU_FLATE_2,
	SHOW_CHANGE_MENU_FLATE_3,
	SHOW_CHANGE_MENU_FLATE_4,
	DIALOG_CHANGE_PRICE_P_F,
	DIALOG_FLATE_RENT_P,
	DIALOG_CONTINUE_RENT_FLATE,
	DIALOG_ENG_RENT_FLATE,
	SHOW_CHANGE_MENU_FLATE_PEOP_ALL,
	DIALOG_CHANGE_MENU_FLATE,
	SHOW_CHANGE_MENU_FLATE_UPGRADE,
	DIALOG_SELECT_FLATE_DAY_R,

	DIALOG_FLATE_D_GENERAL,
	DIALOG_FLATE_D_GENERAL_HARD,
	DIALOG_FLATE_INPUT_DRUGS,
	DIALOG_FLATE_PUT_DRUGS,
	DIALOG_FLATE_INPUT_DRUGS_HARD,
	DIALOG_FLATE_PUT_DRUGS_HARD,
 
	DIALOG_FLATE_G_F_M,
	DIALOG_FLATE_INPUT_MONEY_S,
	DIALOG_PUT_MONEY_F_S,
	DIALOG_FLATE_CODE_SAFE_INPUT,
	DIALOG_CHANGE_FLATE_S_P,
	DIALOG_FLATE_D_INFO_ALL,
	DIALOG_FLATE_GENERAL_SAFE,
	DIALOG_CHANGE_FLATE_S_C,

	DIALOG_GENERAL_WARDROBE_FLATE,
	DIALOG_WADROBE_1_FLATE,
	DIALOG_WARDROBE_2_FLATE,
	DIALOG_WARDROBE_3_FLATE,
	DIALOG_WARDROBE_G_1_FLATE,
	DIALOG_WARDROBE_G_2_FLATE,
	DIALOG_WARDROBE_G_3_FLATE,


	DIALOG_BUY_HOTEL,
	DIALOG_INFO_HOTEL,
	DIALOG_CHANGE_HOTEL,
	DIALOG_MENU_RENT_RENT,
	DIALOG_MENU_RENT_NEW,
	DIALOG_MENU_INFO_RECEP,

	DIALOG_BUY_UNIVERMAG,
	DIALOG_INFO_UNIVERMAG,

	DIALOG_CHANGE_PRICE_NUMBER_H,
	DIALOG_CHANGE_PRICE_ENTER_HOTEL,
	DIALOG_SELECT_ENTER_HOTELL,
	DIALOG_SELECT_ENTER_HOTEL,


	DIALOG_LIFT_HOTEL_1,
	DIALOG_LIFT_HOTEL_2,
	DIALOG_LIFT_HOTEL_3,
	DIALOG_LIFT_HOTEL_4,

	DIALOG_ENTER_HOTEL_ROOM,

	DIALOG_RENT_ROOM_FINAL,

	DIALOG_CONTINUE_RENT_ROOM,
	DIALOG_CANCEL_RENT_ROOM,


	DIALOG_BANK_HOTEL,
	DIALOG_INPUT_MONEY_BANK_HOTEL,
	DIALOG_PUT_MONEY_BANK_HOTEL,


	DIALOG_BUY_GARAGE,
	DIALOG_INFO_ENTER,


	DIALOG_INFO_ENTER_GARAGE,
	DIALOG_CHANGE_GARAGE,


	DIALOG_AUTOSCHOOL_CAR_EXAM,
	DIALOG_AUTOSCHOOL_CAR_ACTOR_HI,
	DIALOG_AUTOSCHOOL_THEORY_1,
	DIALOG_AUTOSCHOOL_THEORY_2,
	DIALOG_AUTOSCHOOL_THEORY_3,
	DIALOG_AUTOSCHOOL_THEORY_4,
	DIALOG_AUTOSCHOOL_THEORY_5,
	DIALOG_AUTOSCHOOL_THEORY_6,
	DIALOG_AUTOSCHOOL_THEORY_7,
	DIALOG_AUTOSCHOOL_THEORY_8,
	DIALOG_AUTOSCHOOL_BOAT,
	DIALOG_AUTOSCHOOL_FLY,
	DIALOG_AUTOSCHOOL_CAR_START,




	DIALOG_BUY_FILLING,
	DIALOG_CHANGE_FILLING,
	DIALOG_FINAL_BUY_CHARGE,
	DIALOG_FINAL_BUY_FILL_PLUS,
	DIALOG_CHANGE_FILL_PRICE_1,
	DIALOG_CHANGE_FILL_PRICE_2,
	DIALOG_CHANGE_FILL_PRICE_3,
	DIALOG_BUY_FILL_ORDER,
	DIALOG_INFO_FUEL_ST,
	DIALOG_CHANGE_FILL_PRICE_4,

	DIALOG_ENGINE_STATUS_ELECTRO,
	DIALOG_ENG_ELECTRO_INFO_1,
	DIALOG_ENG_ELECTRO_INFO_2,
	DIALOG_ENG_ELECTRO_INFO_3,


	DIALOG_STATS_PROMO_CLOSE,
	DIALOG_CREATE_PROMO_NAME,
	DIALOG_CREATE_PROMOCODE_FRIEND,
	DIALOG_INFO_PROMO_FRIEND,
	DIALOG_MENU_PROMOCODE,
	DIALOG_ACTIVE_PROMO_FRIEND,
	DIALOG_CLOSE_ACTIVE_PROMO,

	DIALOG_INPUT_COUNT_FUEL,
	DIALOG_FILLING_INPUT_MONEY,
	DIALOG_FILLING_PUT_MONEY,
	DIALOG_SELECT_BANK_FILLING,


	DIALOG_CRUPIE_MENU,
	DIALOG_CRUPIE_UPDATE_BET,
	DIALOG_CRUPIE_JOB,
	DIALOG_CASINO_JOB_CLOSE,

	DIALOG_BANK_PROPERTY_PAY,
	DIALOG_PAYMENT_HOUSE,
	DIALOG_PAYMENT_FLATE,
	DIALOG_PAYMENT_FILLING,
	DIALOG_PAYMENT_HOTEL,
	DIALOG_PAYMENT_GARAGE,
	DIALOG_PAYMENT_STO,

	DIALOG_PAYMENT_TRUCKER,
	DIALOG_PAYMENT_TAXI,

	DIALOG_SELECT_OFF_MES,
	DIALOG_LEARN_OFF_MES,

	DIALOG_BUY_CASINO,
	DIALOG_CHANGE_PANEL_CASINO,
	DIALOG_CHANGE_BANK_CASINO,
	DIALOG_INPUT_MONEY_BANK_CASINO,
	DIALOG_PUT_MONEY_BANK_CASINO,
	DIALOG_CHANGE_CASINO_CLOSE,
	DIALOG_PAYMENT_BIZ_ALL,
	DIALOG_PAYMENT_CASINO,

	DIALOG_INFO_BIZ_PANEL,
	DIALOG_CHANGE_PANEL_BIZ,
	DIALOG_CHANGE_CASSA_BIZ,
	DIALOG_INPUT_MONEY_BANK_BIZ,
	DIALOG_PUT_MONEY_BANK_BIZ,

	DIALOG_SELECT_ENTER_BIZ_TYPE_1,
	DIALOG_SELECT_ENTER_BIZ_TYPE_2,
	DIALOG_SELECT_ENTER_BIZ_TYPE_3,
	DIALOG_SELECT_ENTER_BIZ_TYPE_4,
	DIALOG_SELECT_ENTER_BIZ_TYPE_5,
	DIALOG_SELECT_ENTER_BIZ_TYPE_6,

	DIALOG_BUY_BAR,
	DIALOG_INFO_BAR,
	DIALOG_BUY_AMMO,
	DIALOG_INFO_AMMO,
	DIALOG_BUY_RESTORAN,
	DIALOG_INFO_RESTORAN,
	DIALOG_BUY_FASTFOOD,
	DIALOG_INFO_FASTFOOD,
	DIALOG_BUY_CLUB,
	DIALOG_INFO_CLUB,

	DIALOG_ACCEPT_FAMILY_PASS,
	DIALOG_FAM_MENU_PICKUP,
	DIALOG_CLOSE_FAMILY,
	DIALOG_FAMILY_OFFLINE,
	DIALOG_CHANGE_FAMILE_MES_INPUT,
	DIALOG_CHANGE_FAMILY_NAME,
	DIALOG_CHANGE_FAMILY_OTHER,
	DIALOG_LEAVE_FAMILY_FINAL,
	DIALOG_CHANGE_FAMILY_OWNER,
	DIALOG_CREATE_FAMILY_START,
	DIALOG_CREATE_FAMILY_NAME,
	DIALOG_CREATE_FAMILY_COLOR,
	DIALOG_FAMILY_CHANGE_COLOR,
	DIALOG_FAMILY_WAR_INFO,
	DIALOG_FAMILY_WAR_ACCEPT,
	DIALOG_FAMILY_WAR_SELECT_MAP,
	DIALOG_FAMILY_INFO,
	DIALOG_UPGRADE_FAMILY,
	DIALOG_FAMILY_VEHICLES_LIST,
	DIALOG_FAMILY_VEHICLE,
	DIALOG_FAMILY_WAREHOUSE_LIST,
	DIALOG_FAMILY_PUT_MONEY,
	DIALOG_FAMILY_PUT_DRUGS,
	DIALOG_FAMILY_PUT_HDRUGS,
	DIALOG_FAMILY_TAKE_MONEY,
	DIALOG_FAMILY_TAKE_DRUGS,
	DIALOG_FAMILY_TAKE_HDRUGS,
	

	DIALOG_SELECT_TUNNEL_MINER_1,
	DIALOG_SELECT_TUNNEL_MINER_2,

	DIALOG_SELECT_JOB_MINER,
	DIALOG_INFO_JOB_MINER_FINAL,

	DIALOG_CHANGE_TRUCKER,
	DIALOG_CHANGE_TRUCKER_BANK,
	DIALOG_TRUCKER_INPUT_MONEY, 
	DIALOG_TRUCKER_CHANGE_PERS,
	DIALOG_TRUCKER_CHANGE_PERS_2,
	DIALOG_BUY_TRUCKER,
	DIALOG_TRUCKER_PUT_MONEY,
	DIALOG_START_JOB_TRUCKER,

	DIALOG_TRUCKER_LOAD_MINER,
	DIALOG_TRUCKER_LOAD_ZAVOD,
	DIALOG_TRUCKER_LOAD_SHOP,
	DIALOG_TRUCKER_LOAD_FILL_1,
	DIALOG_TRUCKER_LOAD_FILL_2,
	DIALOG_TRUCKER_LOAD_SAMWILLS,

	DIALOG_INPUT_TRUCKER_1,
	DIALOG_INPUT_TRUCKER_2,

	DIALOG_START_SELECT_RENT_CAR_1,
	DIALOG_START_SELECT_RENT_CAR_2,
	DIALOG_SELECT_RENT_C_SALON_1,
	DIALOG_SELECT_RENT_C_SALON_2,
	DIALOG_SELECT_RENT_C_SALON_3,
	DIALOG_CONFIG_CAR_RENT,

	DIALOG_START_SELECT_CAR_1,
	DIALOG_START_SELECT_CAR_2,
	DIALOG_START_SELECT_CAR_3,

	DIALOG_FACTORY_JOB,

	DIALOG_BUY_TAXI_COMPANY,
	DIALOG_CHANGE_TAXI,
	DIALOG_CHANGE_TAXI_BANK,
	DIALOG_TAXI_INPUT_MONEY,
	DIALOG_TAXI_PUT_MONEY,
	DIALOG_CHANGE_TAXI_PERCENT_1,
	DIALOG_CHANGE_TAXI_PERCENT_2,
	DIALOG_TAXI_PERS,
	DIALOG_TAXI_PERS_2,
	DIALOG_TAXI_PERSONAL_CLOSE,

	DIALOG_SELECT_MENU_YANDEX,
	DIALOG_SELECT_MENU_CITY,
	DIALOG_SELECT_MENU_UBER,
	DIALOG_SELECT_YANDEX_WORK,
	DIALOG_SELECT_CITY_WORK,
	DIALOG_SELECT_UBER_WORK,
	DIALOG_SELECT_YANDEX_ST_WORK,
	DIALOG_SELECT_CITY_ST_WORK,
	DIALOG_SELECT_UBER_ST_WORK,
	DIALOG_INFO_TAXI,

	DIALOG_SELECT_YANDEX_TARIF_WORK,
	DIALOG_SELECT_CITY_TARIF_WORK,
	DIALOG_SELECT_UBER_TARIF_WORK,

	DIALOG_CHANGE_TAXI_TARIF_1,
	DIALOG_CHANGE_TAXI_TARIF_2,
	DIALOG_CHANGE_TAXI_TARIF_3,

	DIALOG_START_SELECT_RENT_CAR_3,

	dFerm,
	dFermEx,


	dAdvInf,
	dAdvInf2,

	dShopRadio,
	dShopSpray,

	dZal,
	dZal2,
	dZal3,
	dTeleport,
	dTeleportNew,
	dTeleportPos,
	dTeleportPos1,
	dTeleportPos2,
	dTeleportPos3,
	dTeleportPos4,
	dTeleportPos5,
	dTeleportPos6,
	dTeleportPos7,
	dTeleportPos8,
	dTeleportPos9,

	dMakeBat,

	dWaterMenu,
	dSadMenu,
	dSadMenu2,
	dAqaMenu,

	dStroiMenu,
	dStroiMenu2,
	dStroiMenu3,
	dStroiMenu4,
	dStroiMenu5,

    dCarBaza,

    dCarBaza2,
    dCarBaza3,
    dCarBaza4,
    dCarBaza5,

	dCarJob,
	dCarJobMenu,

	dHelplist,
	dMobSet,
	dMobAccept,
	dMobDell,
	dMobDell2,
	dBaseMenu,
	dJumpMenu,
	CARREG,
	dHellow,
	CARREG2,
	dMesVoen,
	dMesVoen2,
	dMesVoen3,
	HAPPYNY,

	dSTO1,
	dSTO11,
	dSTO2,
	dSTO22,
	dSTO3,
	dSTO33,
	dSTO4,
	dSTO44,

	dSTO55,
	dSTO66,

	dSu,
	dSu2,

    dLowRegMenu,
    dLowRegMenu2,

	dAddSobes,
	dAddSobes2,
	dDelSobes,
	dShowSobes,
	dShowSobes2,

	dAcceptDel,
	dLeave,
	dNY,
	dNY2,
	dNewYear,
	dNYSkin,
	dNYSkin2,
	HEDITOR_DIALOG_ID,
	HEDITOR_DIALOG_ID2,

	DIALOG_BIND_COMMAND_W,
	DIALOG_BIND_COMMAND_T,
	DIALOG_BIND_COMMAND_G,

	DIALOG_ENGINE_STATUS,
	DIALOG_ENGINE_INFO_1,
	DIALOG_ENGINE_INFO_2,
	DIALOG_ENGINE_INFO_3,
	DIALOG_ENGINE_INFO_4,
	DIALOG_ENGINE_INFO_5,
	DIALOG_ENGINE_INFO_6,
	DIALOG_ENGINE_INFO_7,
	DIALOG_ENGINE_INFO_8,

	DIALOG_CONFIG_VEH_GENERAL,
	DIALOG_CONFIG_CAR_FUEL_TYPE,
	DIALOG_CONFIG_CAR_CLASS,
	DIALOG_CONFIG_CAR_NAME,
	DIALOG_CONFIG_CAR_PRICE,
	DIALOG_CONFIG_CAR_TANK,
	DIALOG_CONFIG_CAR_SPEED,
	DIALOG_CONFIG_CAR_FILL,

	DIALOG_SELECT_ENTER_AUTOSALON,
	DIALOG_BUY_AUTOSALON,
	DIALOG_INFO_AUTOSALON,
	DIALOG_SELECT_ENTER_CASINO,
	
	DIALOG_WOOD_JOB,

	DIALOG_PHONE_NOTE_LEARN,
	DIALOG_SELECT_NOTE_PHONE,
	DIALOG_PHONE_NOTE_MENU,
	DIALOG_CREATE_NOTE,
	DIALOG_SETTING_PHONE_1,
	DIALOG_PHONE_CALENDAR,

	DIALOG_SELECT_ENTER_CLOTHES,
	DIALOG_BUY_CLOTHES,
	DIALOG_INFO_CLOTHES,
	DIALOG_START_SELECT_CLOTHES_1,
	DIALOG_BUY_CLOTHES_FINAL,
	DIALOG_BUY_CLOTHES_PREW,
	DIALOG_APANEL
}

new GFREEZE = 0;

new 
	test_bonus_active = 0,
	donate_active_command = 1;

new 
	rent_car_salon_1[MAX_PLAYERS] = INVALID_VEHICLE_ID,
	rent_car_salon_2[MAX_PLAYERS] = INVALID_VEHICLE_ID,
	rent_car_salon_3[MAX_PLAYERS] = INVALID_VEHICLE_ID;

new spec_ad[MAX_PLAYERS];

new admloged[MAX_PLAYERS];


new 
	PlayerText:casino_general_p[9][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},

	PlayerText:miner_job_1_p[22][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},
	PlayerText:miner_job_2_p[15][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},
	PlayerText:miner_job_3_p[12][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},

	PlayerText:fire_panel[3][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},
	PlayerText:fire_work_panel[3][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},

	PlayerText:autosalon_info_td_p[16][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},

	PlayerText:ammo_panel_menu_biz[20][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},

	PlayerText:hud_elements_p[6][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},

	PlayerText:hospital_npc_p[3][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},

	PlayerText:work_taxi_panel[4][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},
	PlayerText:work_tax_info_p[3][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},

	PlayerText:work_trash_panel_p[3][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},
	PlayerText:work_bank_panel_p[3][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},

	PlayerText:fish_p_general[4][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},
	PlayerText:fish_panel_all[32][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},
	PlayerText:fish_panel_final[5][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},

	PlayerText:factory_job_9_p[16][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},
	PlayerText:factory_job_8_p[16][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},
	PlayerText:factory_job_7_p[16][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},
	PlayerText:factory_job_6_p[16][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},
	PlayerText:factory_job_5_p[16][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},
	PlayerText:factory_job_4_p[16][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},
	PlayerText:factory_job_3_p[16][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},
	PlayerText:factory_job_2_p[16][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},
	PlayerText:factory_job_1_p[16][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},

	PlayerText:inventory_gui_p[59][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},

	PlayerText:free_number_gai_p[7][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},
	PlayerText:buy_number_gai_p[6][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},

	PlayerText:player_veh_key[5][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},
	PlayerText:key_vehicle_electro[5][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},

	PlayerText:factory_job_two_5_p[16][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},
	PlayerText:factory_job_two_4_p[18][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},
	PlayerText:factory_job_two_3_p[18][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},
	PlayerText:factory_job_two_2_p[18][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},
	PlayerText:factory_job_two_1_p[18][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},

	PlayerText:general_green_house[28][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},

	PlayerText:yandex_taxi_td[5][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},
	PlayerText:uber_taxi_td[5][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},
	PlayerText:siti_taxi_select[5][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},

	PlayerText:circle_menu_veh_electro[7][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},
	PlayerText:circle_menu_veh_dvs[5][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},

	PlayerText:quest_panel_general_p[13][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},

	PlayerText:voice_setting_player[5][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},
	PlayerText:notify_player_all[4][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},

	PlayerText:quest_general_panel_s[6][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},
	PlayerText:quest_newyear_p[14][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},

	PlayerText:snow_work_player[3][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...},

	PlayerText:newyear_gui_info[2][MAX_PLAYERS] = {{PlayerText:INVALID_TEXT_DRAW, ...}, ...}, 

	Text:factory_job_1[2] = {Text:INVALID_TEXT_DRAW, ...},
	Text:factory_job_2[2] = {Text:INVALID_TEXT_DRAW, ...},

	Text:player_veh_key_back[3] = {Text:INVALID_TEXT_DRAW, ...},
	Text:key_vehicle_electrog[7] = {Text:INVALID_TEXT_DRAW, ...},

	Text:buy_number_gai[13] = {Text:INVALID_TEXT_DRAW, ...},
	Text:free_number_gai[5] = {Text:INVALID_TEXT_DRAW, ...},

	Text:autosalon_elite_class[9] = {Text:INVALID_TEXT_DRAW, ...},
	Text:autosalon_middle_class[9] = {Text:INVALID_TEXT_DRAW, ...},
	Text:autosalon_low_class[9] = {Text:INVALID_TEXT_DRAW, ...},

	Text:fish_prefinal_panel[2] = {Text:INVALID_TEXT_DRAW, ...},

	Text:hospital_npc[5] = {Text:INVALID_TEXT_DRAW, ...},

	PlayerText:wood_point_p[MAX_PLAYERS] = {PlayerText:INVALID_TEXT_DRAW, ...},

	PlayerText:start_traning_player_td[MAX_PLAYERS] = {PlayerText:INVALID_TEXT_DRAW, ...},

	PlayerText:player_info_td[MAX_PLAYERS] = {PlayerText:INVALID_TEXT_DRAW, ...},
	PlayerText:clothes_select_price[MAX_PLAYERS] = {PlayerText:INVALID_TEXT_DRAW, ...},
	PlayerText:aks_select_price[MAX_PLAYERS] = {PlayerText:INVALID_TEXT_DRAW, ...},

	PlayerText:work_notify_new[MAX_PLAYERS] = {PlayerText:INVALID_TEXT_DRAW, ...},

	PlayerText:race_player_button_snow[MAX_PLAYERS] = {PlayerText:INVALID_TEXT_DRAW, ...},

	PlayerText:race_position_player[MAX_PLAYERS] = {PlayerText:INVALID_TEXT_DRAW, ...},
	PlayerText:race_player_button[MAX_PLAYERS] = {PlayerText:INVALID_TEXT_DRAW, ...},

	PlayerText:phone_background_info[MAX_PLAYERS] = {PlayerText:INVALID_TEXT_DRAW, ...},

	PlayerText:background_login[MAX_PLAYERS] = {PlayerText:INVALID_TEXT_DRAW, ...},

	Text:mine_job_1[2] = {Text:INVALID_TEXT_DRAW, ...},
	Text:mine_job_2[2] = {Text:INVALID_TEXT_DRAW, ...},
	Text:mine_job_3[8] = {Text:INVALID_TEXT_DRAW, ...},

	Text:quest_panel_general[5] = {Text:INVALID_TEXT_DRAW, ...},

	Text:clothes_select_td[6] = {Text:INVALID_TEXT_DRAW, ...},
	Text:aks_select_td[6] = {Text:INVALID_TEXT_DRAW, ...},


	Text:general_gui_player[2] = {Text:INVALID_TEXT_DRAW, ...},


	Text:inventory_gui_back[4] = {Text:INVALID_TEXT_DRAW, ...},

	Text:autoschool_info_td_1[2] = {Text:INVALID_TEXT_DRAW, ...},
	Text:autoschool_info_td_2[2] = {Text:INVALID_TEXT_DRAW, ...},
	Text:autoschool_info_td_3[2] = {Text:INVALID_TEXT_DRAW, ...},
	Text:autoschool_info_td[7] = {Text:INVALID_TEXT_DRAW, ...},


	Text:fast_menu_general_1[7] = {Text:INVALID_TEXT_DRAW, ...},
	Text:fast_menu_general_2[7] = {Text:INVALID_TEXT_DRAW, ...},
	Text:start_info_player_1[6] = {Text:INVALID_TEXT_DRAW, ...},


	Text:phone_general_player[8] = {Text:INVALID_TEXT_DRAW, ...},

	Text:mech_background_repair = Text:INVALID_TEXT_DRAW,

	Text:phone_general = Text:INVALID_TEXT_DRAW,

	Text:fire_work_close = Text:INVALID_TEXT_DRAW,
	Text:fire_panel_background = Text:INVALID_TEXT_DRAW,

	Text:fire_panel_close = Text:INVALID_TEXT_DRAW,

	Text:prizenewyear_background[3] = {Text:INVALID_TEXT_DRAW, ...},

	Text:hud_elements[3] = {Text:INVALID_TEXT_DRAW, ...},

	Text:rent_katok_menu[4] = {Text:INVALID_TEXT_DRAW, ...},

	Text:race_timer_snow[2] = {Text:INVALID_TEXT_DRAW, ...},
	Text:race_interface_g_snow[6] = {Text:INVALID_TEXT_DRAW, ...},

	Text:newyear_back[2] = {Text:INVALID_TEXT_DRAW, ...},

	Text:quest_newyear_td = Text:INVALID_TEXT_DRAW,
	Text:quest_newyear_start[4] = {Text:INVALID_TEXT_DRAW, ...},
	Text:quest_close_button_other = Text:INVALID_TEXT_DRAW,

	Text:trucker_select_job[9] = {Text:INVALID_TEXT_DRAW, ...},

	Text:circle_menu[7] = {Text:INVALID_TEXT_DRAW, ...},
	Text:fill_lukoil_panel[7] = {Text:INVALID_TEXT_DRAW, ...},
	Text:fill_gazprom_panel[8] = {Text:INVALID_TEXT_DRAW, ...},
	Text:casino_panel[4] = {Text:INVALID_TEXT_DRAW, ...},
	Text:voice_global_td[6] = {Text:INVALID_TEXT_DRAW, ...},
	Text:load_screen[3] = {Text:INVALID_TEXT_DRAW, ...},

	Text:select_spawn[6] = {Text:INVALID_TEXT_DRAW, ...},

	Text:race_interface_g[6] = {Text:INVALID_TEXT_DRAW, ...},
	Text:race_timer_global[2] = {Text:INVALID_TEXT_DRAW, ...},
	Text:race_position_td[6] = {Text:INVALID_TEXT_DRAW, ...},

	Text:race_car_in_box[2] = {Text:INVALID_TEXT_DRAW, ...}, 

	Text:teplica_buy_menu[7] = {Text:INVALID_TEXT_DRAW, ...}, 
	Text:menu_teplica_general_st[12] = {Text:INVALID_TEXT_DRAW, ...}, 


	Text:tdBizWar[6] = {Text:INVALID_TEXT_DRAW, ...}, 


	Text:speec_panel_admin[14] = {Text:INVALID_TEXT_DRAW, ...};

new 
	Text:alt_menu,
	Text:bus_timer,
	Text:charge_tesla_button[2];


new Text:speed_background;

new Text:hungry_background;

new PlayerText:hungry_hud_p[2][MAX_PLAYERS];
new Text:green_zone_td;


new PlayerText:player_speed_car[11][MAX_PLAYERS];
new PlayerText:admin_speec_p[5][MAX_PLAYERS];

new PlayerText:charge_tesla_panel_p[7][MAX_PLAYERS];
new PlayerText:fill_lukoil_panel_p[4][MAX_PLAYERS];
new PlayerText:filling_gazprom_p[4][MAX_PLAYERS];

new PlayerText:bus_timer_p[MAX_PLAYERS];


#define SFCM(%0,%1,%2) do{new _s[200];format(_s,200,%2);SendClientMessage(%0,%1,_s) ;}while(FALSE)

#define SPFD(%0,%1,%2,%3,%4,%5,%6) do{new _s[400];format(_s,400,%6);show_dialog(%0,%1,%2,%3,_s,%4,%5) ;}while(FALSE)

new format_string[144];
#define FormattedMessage(%0,%1,%2,%3)	format(format_string, sizeof(format_string),%2,%3) && SCM(%0, %1, format_string)


#define SPD 					show_dialog
#define SCM 					SendClientMessage


stock NoPlayer(playerid) return EROM(playerid, 0, "Такого игрока нет на сервере", 7, "", ""); //SendErr(playerid,"Такого игрока нет на сервере");
stock NoMoney(playerid) return EROM(playerid, 0, "У Вас нет столько денег", 7, "", ""); //SendErr(playerid,"У Вас нет столько денег");
stock TooFar(playerid) return EROM(playerid, 0, "Вы слишком далеко от игрока", 7, "", ""); //SendErr(playerid,"Вы слишком далеко от игрока");
stock NoAccess(playerid) return EROM(playerid, 0, "У Вас нет доступа", 7, "", ""); //SendErr(playerid,"У Вас нет доступа");
stock NoCMD(playerid) return EROM(playerid, 0, "Данная команда не существует. Используйте {FFC800}/mn - Список команд"cWH", чтобы узнать список команд сервера.", 7, "", "");//SendInf(playerid, "Данная команда не существует. Используйте {FFC800}/mn - Список команд"cWH", чтобы узнать список команд сервера.");
stock Muted(playerid) return EROM(playerid, 4, "Вам заблокирован доступ в чат! Узнать время до разблокировки ->", 7, "/t", ">>"); //SendErr(playerid,"Вам заблокирован доступ в чат! Узнать время до разблокировки: "cWH"/t");
stock NoMyCar(playerid) return EROM(playerid, 0, "У Вас нет личного трансопрта", 7, "", ""); //SendErr(playerid,"У Вас нет личного транспорта");

new 
	params_gamemode_change = 2;

new 
	restart_time_hour,
	restart_time_minute,
	restart_time_second;

new 
	hospital_advert,
	hospital_exit_pickup,
	hospital_enter_pickup,
	hospital_exit_pickup_2,
	hospital_enter_pickup_2,
	hospital_exit_pickup_3,
	hospital_glav_menu,
	hospital_enter_pickup_3,
	hospital_2_enter_pickup,
	hospital_2_exit_pickup;


new 
	opcode;


new 
	mechanic_no_collizion[3];


new dialog_listitem_values[MAX_PLAYERS][150];
new dialog_listitem_valuess[MAX_PLAYERS];

new 
	timer_povorot[MAX_PLAYERS];

new 
	safe_int_house[4];


new 
	count_iter_restimit,
	count_iter_restimit_1;


//Фракции
new gFractionSobes[FRACTION_COUNT][4];
new gFractionSobesTime[FRACTION_COUNT][4];
new gFractionSobesTimeM[FRACTION_COUNT][4];
new gFractionSobesMesto1[256];
new gFractionSobesMesto2[4][256];
new gFractionSobesMesto8[4][256];
new gFractionSobesMesto9[4][256];
new gFractionSobesMesto10[4][256];
new gFractionSobesMesto11[4][256];
new gFractionSobesMesto12[256];

new gFractionName[FRACTION_COUNT][32] = 
{
	"-",
	"Минздрав",
	"-",
	"-",
	"-",
	"-",
	"-",
	"Министерство обороны",
	"Министерство внутренних дел",
	"Новостная сеть",
	"Администрация Президента",
	"ФСБ",
	"Тамбовская ОПГ",
	"Курганская ОПГ",
	"Измайловская ОПГ"
};

new gFractionRankCount[FRACTION_COUNT] = {8,11,10,10,10,10,10,11,11,11,11,10,10,10,10};
new gFractionRankName[FRACTION_COUNT][18][32] = {
	{"Стажер","Консультант","Экзаменатор","Мл. Инструктор","Инструктор","Менеджер","Зам. Директора","Директор Автошколы","","","","","","","","","",""},//Инструкторы
	{"Интерн","Лаборант","Фельдшер","Участковый врач","Терапевт","Окулист","Хирург","Зав. отделением","Зам. Глав. врача","Глав. врач","Министр Здравоохранения","","","","","","",""},//Медики
	{"","","","","","","","","","","","","","","","","",""},
	{"","","","","","","","","","","","","","","","","",""},
	{"","","","","","","","","","","","","","","","","",""},
	{"","","","","","","","","","","","","","","","","",""},
	{"","","","","","","","","","","","","","","","","",""},
	{"Рядовой","Ефрейтор","Сержант","Прапорщик","Лейтенант","Капитан","Майор","Подполковник","Полковник","Генерал","Министр Обороны","","","","","","",""},
//	{"Курсант","Офицер","Детектив-Специалист","Детектив-Следователь","Сержант","Лейтенант","Капитан","Заместитель инспектора","Инспектор","Заместитель комиссара","Комиссар полиции","Шериф","Министр Внутренних Дел","","","","",""},
	{"Мл.Сержант","Сержант","Старшина","Мл.Лейтенант","Лейтенант","Капитан","Майор","Подполковник","Полковник","Генерал","Министр Внутренних Дел","","","","","","",""},
	{"Начинающий работник","Помощник редакции","Светотехник","Репортер","Оператор","Ведущий","Режиссер","Редактор","Главный редактор","Директор","Управляющий СМИ","","","","","","",""},
	{"Водитель","Охранник","Нач. Охраны","Пресс-секретарь","Секретарь","Адвокат","Прокурор","Депутат","Заместитель Мэра","Мэр","Президент","","","","","","",""},
	{"Агент ФСБ","Сотрудник гр.Вымпел","Сотрудник гр.Альфа","Оперативный сотрудник","Зам.командира гр.Вымпел","Зам.командира гр.Альфа","Командир группы Вымпел","Командир группы Альфа","Зам.Директора","Директор ФСБ","-","-","-","-","-","-","",""},
    {"Бык","Босяк","Фраер","Блатной","Бригадир","Смотрящий","Пахан","Положенец","Авторитет","Вор в законе","","","","","","","",""},
    {"Бык","Босяк","Фраер","Блатной","Бригадир","Смотрящий","Пахан","Положенец","Авторитет","Вор в законе","","","","","","","",""},
    {"Бык","Босяк","Фраер","Блатной","Бригадир","Смотрящий","Пахан","Положенец","Авторитет","Вор в законе","","","","","","","",""}
};

new gPrezRankName[9][32] = {"Водитель","Охранник","Начальник охраны","Секретарь","Генеральный Прокурор","Советник по Нац. Безопасности","Пресс-секретарь","Советник по МЗ","Премьер-Министр"};

new gVmfRankName[12][32] = {"Матрос","Старшина","Мичман","Мл. Лейтенант","Лейтенант","Старший Лейтенант","Капитан-Лейтенант","Капитан 3-го ранга","Капитан 2-го ранга","Капитан 1-го ранга","Вице-Адмирал","Адмирал"};

#define F_COL  15
#define F_MEX  14
#define F_YAK  13

new gFractionSkin[FRACTION_COUNT][12+5+3] = {
	{172, 58, 98, 141,189,190 ,0,0,0,0,0,0,0,0,0,0,0}, //Инструкторы
	{148, 133, 274, 275, 276, 70, 275,0,0,0,0,0,0,0,0,0,0}, //Медики LS
	{48,102,103,104,0,0,0,0,0,0,0,0,0,0,0,0,0}, //Ballas Орех
	{139,105,106,107,0,0,0,0,0,0,0,0,0,0,0,0,0}, //Groove тамбов
	{145,114,115,116,0,0,0,0,0,0,0,0,0,0,0,0,0}, //Aztecaz Медвед
	{176,173,174,175,0,0,0,0,0,0,0,0,0,0,0,0,0}, //Vagos Курган
	{138,108,109,110,0,0,0,0,0,0,0,0,0,0,0,0,0}, //Rifa Измайлов
	{287,191, 73, 255, 255, 61,0,0,0,0,0,0,0,0,0,0,0}, //Армия ,287
	{283,280,284,282,266,285,265,285,0,0,0,0,0, 0, 0,0,0,0, 0, 0}, //Полиция
	{202, 186, 188, 84, 84, 84,0,0,0,0,0,0,0,0,0,0,0}, //СМИ
	{17,59,141, 187,165, 164,164,164, 164,0,0,0,0,0,0,0,0}, // Админ. Президента
	{163,173,174,175,172,211,211,0,0,0,0,0,0,0,0,0,0}, //FBI
	{46,111,112,125,126,0,0,0,0,0,0,0,0,0,0,0,0}, //Yakuza
	{46,111,112,125,126,0,0,0,0,0,0,0,0,0,0,0,0}, //Mexico
	{46,111,112,125,126,0,0,0,0,0,0,0,0,0,0,0,0} //Columbian
};
new Float:gFractionSpawnC[FRACTION_COUNT][4] = 
{
	{0.0, 0.0, 0.0, 0.0}, 						// Инструкторы
	{-1072.5852,-1462.1990,23.4042,269.6447},	//  //Медики (обновлен)
	{799.7349,-979.8914,1205.9318,0.4728}, 		//Balls  (обновлен)
	{799.7349,-979.8914,1205.9318,0.4728}, 		//Groove  (обновлен)
	{799.7349,-979.8914,1205.9318,0.4728}, 		//Aztecaz  (обновлен)
	{799.7349,-979.8914,1205.9318,0.4728}, 		//Vagos  (обновлен)
	{799.7349,-979.8914,1205.9318,0.4728}, 		//Rifa  (обновлен)
	{-1825.1588,-1987.8336,-0.5234,91.4117}, 	// mo  (обновлен)
	{-953.7605,23.8708,1205.0167,91.4829}, 		//Полиция  (обновлен)
	{-2642.4487,-1826.9067,4.1045,89.8107},	 	//Новости (обновлен)
	{708.0253,-13.5308,1201.8580,91.7381},	//Администрация Президента (обновлен)
	{1301.3049,-194.5610,1201.9819,181.5235},	//ФСБ (обновлен)
	{802.4788,-975.9878,1205.9318,1.3053},		//Yakuza  (обновлен)
	{802.4788,-975.9878,1205.9318,1.3053},		//Mexico  (обновлен)
	{802.4788,-975.9878,1205.9318,1.3053}		//Columbian  (обновлен)
};
new gFractionSpawnData[FRACTION_COUNT][2] = // Интерьер и Виртуальный МИР
{ 
	{0,0}, // Инструкторы
	{0,0}, // Медики
	{0,1}, // Ballas
	{0,2}, // Грув
	{0,3}, // Ацтеки
	{0,4}, // Вагос
	{0,5}, // Рифа
	{0,3}, // МО
	{0,1}, // Полиция
	{0,3}, // Новости
	{0,3}, // Администрация
	{0,3}, // ФСБ
	{0,10}, // Якудза
	{0,11}, // Мексиканская
	{0,12}
};
new gFunctionColorFract[FRACTION_COUNT] = {0xFFE7BA00,0xff52a400,0xCC00FF00 ,0x00990000,0x00EEEE00,0xFBD40000,0x6666FF00,0x70421400,0x1060AC00,0xff4f0000,0xe6fb0100,0x000cff00,0xff000000, 0x9eff4f00, 0x6300f800};
new gFractionColor[FRACTION_COUNT] = {0xFFE7BAAA,0xff52a4AA,0xCC00FFAA ,0x009900AA,0x00EEEEAA,0xFBD400AA,0x6666FFAA,0x704214AA,0x1060ACAA,0xff4f00AA,0xe6fb01AA,0x000cff00,0xff0000AA, 0x9eff4fAA, 0x6300f8AA};

new Float:gSubfractionSpawnC[SUBFRACTION_COUNT][3][5] = {
{
	{-1072.5852,-1462.1990,23.4042,269.6447},
	{-1072.5852,-1462.1990,23.4042,269.6447},
	{-1072.5852,-1462.1990,23.4042,269.6447}
},
{
	{-1825.1588,-1987.8336,-0.5234,91.4117},
	{-1825.1588,-1987.8336,-0.5234,91.4117},
	{-1825.1588,-1987.8336,-0.5234,91.4117}
},
{
	{-953.7605,23.8708,1205.0167,91.4829},
	{-953.7605,23.8708,1205.0167,91.4829},
	{-953.7605,23.8708,1205.0167,91.4829}
},
{
    {708.0253,-13.5308,1201.8580,91.7381},
    {708.0253,-13.5308,1201.8580,91.7381},
    {708.0253,-13.5308,1201.8580,91.7381}
},
{//Радиоцентры
    {-2642.4487,-1826.9067,4.1045,89.8107},
    {-2642.4487,-1826.9067,4.1045,89.8107},
    {-2642.4487,-1826.9067,4.1045,89.8107}
}
};
new gSubfractionSpawnData[SUBFRACTION_COUNT][3][5] = {//Инт Вирт мир
{
	{0,1},
	{0,0},
	{0,0}
},
{
	{0,3},
	{0,3},
	{0,3}
},
{
	{0,2},
	{0,1},
	{0,1}
},
{
    {0,3},
    {0,3},
	{0,3}
},
{
	{0,4},
	{0,4},
	{0,3}
}
};
new gSubfractionName[SUBFRACTION_COUNT][3][24] = 
{
	{"Больница г.Южный","Больница г.Арзамас","-"},
	{"Военно-Воздушные Силы","Сухопутные Войска","Военно-Морской Флот"},
	{"МВД г.Южный","МВД г.Арзамас","-"},
	{"-", "Мэрия г.Арзамас", "-"},
	{"Радиоцентр г.Южный", "-", "Радиоцентр г.Арзамас"}
};

new gFractionSalary[FRACTION_COUNT][16] = 
{
	{ 0000, 0000, 0000, 0000, 0000, 4740, 5500, 6000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000 }, // Инструкторы
	{ 1100, 1500, 1880, 2200, 2780, 3100, 3740, 4130, 4500, 4950, 5000, 0000, 0000, 0000, 0000, 0000 }, // Минздрав
	{ 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000 },
	{ 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000 },
	{ 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000 },
	{ 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000 },
	{ 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000 },
	{ 1000, 1300, 1600, 1930, 2220, 2600, 2940, 3380, 3800, 4300, 4800, 5300, 6000, 0000, 0000, 0000 }, // Министерство обороны
	{ 1000, 1300, 1790, 2200, 2570, 2900, 3200, 3530, 3800, 4200, 4450, 4800, 5150, 0000, 0000, 0000 }, // Министерство внутренних дел
	{ 1100, 1500, 1880, 2200, 2780, 3100, 3740, 4130, 4500, 4950, 5590, 0000, 0000, 0000, 0000, 0000 }, // Новостная сеть
	{ 1200, 2000, 2100, 4000, 4000, 4000, 4000, 4000, 7000, 7000, 7700, 0000, 0000, 0000, 0000, 0000 }, // 4400 вместо 7000  АП
	{ 0850, 1000, 1400, 1800, 2250, 2700, 3100, 3450, 3800, 4150, 4500, 4850, 5200, 5600, 6000, 6500 }, // ФБР
	{ 1100, 1500, 1880, 2200, 2780, 3100, 3740, 4130, 4500, 4950, 0000, 0000, 0000, 0000, 0000, 0000 },
	{ 1100, 1500, 1880, 2200, 2780, 3100, 3740, 4130, 4500, 4950, 0000, 0000, 0000, 0000, 0000, 0000 },
	{ 1100, 1500, 1880, 2200, 2780, 3100, 3740, 4130, 4500, 4950, 0000, 0000, 0000, 0000, 0000, 0000 }
};
new FracMO[16] = { 1200, 2000, 2100, 2500, 2800, 3200, 3400, 3800, 4400, 7000, 7700, 0000, 0000, 0000, 0000, 0000 };

new FracMONew[16] = { 1200, 2000, 2100, 2500, 2800, 3200, 3400, 3800, 4400, 7000, 7700, 0000, 0000, 0000, 0000, 0000 };

new gFractionSalaryNew[FRACTION_COUNT][16] = {
	{ 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000 }, // Инструкторы
	{ 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000 }, // Минздрав
	{ 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000 },
	{ 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000 },
	{ 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000 },
	{ 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000 },
	{ 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000 },
	{ 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000 }, // Министерство обороны
	{ 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000 }, // Министерство внутренних дел
	{ 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000 }, // Новостная сеть
	{ 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000}, // 4400 вместо 7000  АП
	{ 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000 }, // ФБР
	{ 1100, 1500, 1880, 2200, 2780, 3100, 3740, 4130, 4500, 4950, 0000, 0000, 0000, 0000, 0000, 0000 },
	{ 1100, 1500, 1880, 2200, 2780, 3100, 3740, 4130, 4500, 4950, 0000, 0000, 0000, 0000, 0000, 0000 },
	{ 1100, 1500, 1880, 2200, 2780, 3100, 3740, 4130, 4500, 4950, 0000, 0000, 0000, 0000, 0000, 0000 }
};


new zSkill;
new Skillsz[MAX_PLAYERS][6];
new weaponupd = 0, ammoupd = 0;
new pState;
new pWeapon;
new OPTICK;
new AntiGun = 1;
new newkeysU,udU,lrU;

new iPlayerAmmo[MAX_PLAYERS];
new iPlayerGun[MAX_PLAYERS];
new iNewPlayerAmmo[MAX_PLAYERS];
#define Ammo_SDPISTOL           12
#define Ammo_DEAGLE             14
#define Ammo_SHOTGUN            8
#define Ammo_MP5                25
#define Ammo_AK47               30
#define Ammo_M4A1				30


new 
	bank_area_general,
	bank_area_biz;

new 
	CountFloodForPlayer[MAX_PLAYERS],
	CountFloodDynamicArea[MAX_PLAYERS];

new Carnb[12][2] = {"A","B","C","E","H","M","P","T","O","X","K","Y"};

new 
	car_number_ru,
	car_number_kz,
	car_number_by,
	car_number_ua;

new 
	PlayerPlateNumber[MAX_PLAYERS][6];

new 
	Float:spec_admin_x[MAX_PLAYERS],
	Float:spec_admin_y[MAX_PLAYERS],
	Float:spec_admin_z[MAX_PLAYERS],
	spec_admin_vw[MAX_PLAYERS],
	spec_admin_vi[MAX_PLAYERS];

new 
	hospital_area_heal,
	player_in_meria;

new 
	aks_select_count[MAX_PLAYERS],
	aks_id_buy[MAX_PLAYERS];

new 
	arClubBar;


new pay_day = 0;


new 
	online_player = 0;

new 
	snow_work_active[MAX_PLAYERS];

new 
	new_year_sim;// Не забудь добавить выгрузку параметра из бд Serverdata!!!



enum acInfo
{
	fix_speed,
	Float:acPosX,
	Float:acPosY,
	Float:acPosZ,
	Float:acDropJpX,
	Float:acDropJpY,
	Float:acDropJpZ,
	Float:acSpawnPosX,
	Float:acSpawnPosY,
	Float:acSpawnPosZ,
	Float:acSetVehHealth,
	Float:acSetPosX,
	Float:acSetPosY,
	Float:acSetPosZ,
	acSpeed,
	acHealth,
	acArmour,
	acMoney,
	acLastShot,
	acLastWeapon,
	acEnterVeh,
	acLastVeh,
	acKickVeh,
	acVeh,
	acSeat,
	acDialog,
	acNextDialog,
	acInt,
	acAnim,
	acDmgRes,
	acSpecAct,
	acNextSpecAct,
	acLastSpecAct,
	acLastPickup,
	acReloadTime,
	acShotTime,
	acSpawnTime,
	acSetPosTime,
	acUpdateTime,
	acEnterVehTime,
	acSpawnWeapon1,
	acSpawnWeapon2,
	acSpawnWeapon3,
	acSpawnAmmo1,
	acSpawnAmmo2,
	acSpawnAmmo3,
	acSpawnRes,
	acTimerID,
	acKickTimerID,
	acParachute,
	acIntRet,
	acKicked,
	acIp[16],
	acSet[13],
	acGtc[18],
	acWeapon[13],
	acAmmo[13],
	acSetWeapon[13],
	acGiveAmmo[13],
	acGtcSetWeapon[13],
	acGtcGiveAmmo[13],
	acNOPCount[12],
	acCheatCount[20],
	bool:acStuntBonus,
	bool:acModShop,
	bool:acUnFrozen,
	bool:acOnline,
	bool:acDeathRes,
	bool:acVehDmgRes,
	bool:acSpawned,
	bool:acDead,
	bool:acTpToZ,
	bool:acIntEnterExits,
	bool:acSpec
}

enum acVehInfo
{
	Float:acVelX,
	Float:acVelY,
	Float:acVelZ,
	Float:acPosX,
	Float:acPosY,
	Float:acPosZ,
	Float:acSpawnPosX,
	Float:acSpawnPosY,
	Float:acSpawnPosZ,
	Float:acSpawnZAngle,
	Float:acPosDiff,
	Float:acZAngle,
	Float:acHealth,
	acSpeedDiff,
	acDriver,
	acInt,
	acPaintJob,
	bool:acSpawned
}

new
	ACInfo[MAX_PLAYERS][acInfo],
	ACVehInfo[MAX_VEHICLES][acVehInfo];


new 
	player_vehicle[MAX_PLAYERS];

new 
	count_iteration_loss = 0;

new 
	CountFloodForpData[MAX_PLAYERS];

new 
	fish_count_player[MAX_PLAYERS][15];

new 
	vehicle_player_max[MAX_PLAYERS][9],
	vehicle_player_max_sql[MAX_PLAYERS][9];

new 
	vehicle_player_max_user[MAX_PLAYERS],
	vehicle_player_count_car_load[MAX_PLAYERS];

new 
	traning_start_player_area[5],
	traning_start_player_actor[5];

new 
	express_heal;

new 
	trash_vehicle[MAX_PLAYERS] = INVALID_VEHICLE_ID,
	trash_count[MAX_VEHICLES] = 0,
	Text3D:trash_text[MAX_VEHICLES] = Text3D:INVALID_3DTEXT_ID;

#define VK_BOT_ACTIVE   1
#define VK_BOT_WAIT     2
new 
    vk_bot_status_server;

new 
	statistic_player_play_hour,
	statistic_player_play_day;
