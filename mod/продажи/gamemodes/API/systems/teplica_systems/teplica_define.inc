


#define GREEN_HOUSE_CLASS_1		1
#define GREEN_HOUSE_CLASS_2		2
#define GREEN_HOUSE_CLASS_3		3


#define GREEN_HOUSE_1_ENTER		438.0474,-623.6015,1207.7876,0.1705
#define GREEN_HOUSE_2_ENTER		76.5170,-609.8890,1207.7720,179.9534
#define GREEN_HOUSE_3_ENTER		76.5657,-954.7094,1207.7563,178.8361

#define GREEN_HOUSE_PANEL_1		438.0197,-614.8859,1207.7876
#define GREEN_HOUSE_PANEL_2		76.3680,-631.2797,1207.7794
#define GREEN_HOUSE_PANEL_3		76.4600,-990.9720,1207.7563

#define GREEN_HOUSE_EXIT_1		438.0851,-625.0386,1207.7761
#define GREEN_HOUSE_EXIT_2		76.4778,-606.8804,1207.7798
#define GREEN_HOUSE_EXIT_3		76.3029,-950.1787,1207.7563

#define GREEN_HOUSE_GENERAL		1203.0043,-576.3433,41.2923

#define GREEN_HOUSE_PRICE_1		750000
#define GREEN_HOUSE_PRICE_2		1500000
#define GREEN_HOUSE_PRICE_3		3500000

#define GREEN_HOUSE_EXIT_COORD	1205.9481,-574.9528,41.2923,293.2068

#define MIN_COUNT_SEMENA		5
 
new 
	green_house_pickup_1,
	green_house_pickup_2,
	green_house_pickup_3;

new 
	green_house_exit_1,
	green_house_exit_2,
	green_house_exit_3;

new 
	green_house_pickup;



new 
	green_house_price_semena[8],
	green_house_price_prod[8];


new 
	timer_rice_plant[MAX_PLAYERS],
	timer_rice_temp_plant[MAX_PLAYERS],
	progress_rice_plant[MAX_PLAYERS],
	progress_rice_water[MAX_PLAYERS],
	progress_water_warning[MAX_PLAYERS];