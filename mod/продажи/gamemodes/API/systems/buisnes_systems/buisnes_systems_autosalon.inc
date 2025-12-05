new EkonomVehicles[] =
{
	420, 438, 467, 474, 475, 517, 526, 527, 589
};
new MiddleVehicles[] =
{
	400, 401, 402, 404, 405, 412, 421, 426, 436, 458, 479, 492, 507, 516, 529, 549, 562, 604, 560, 496, 494, 502, 437, 422, 424, 498
};

new EliteVehicles[] =
{
	410, 415, 419, 429, 466, 470, 477, 480, 489, 505, 541, 543, 546, 547, 551, 559, 561, 566, 579, 587, 603, 534, 491, 542, 423, 439, 490

};

static const Float:position_spawn_hotel_1[][] =
{
	{-230.0717,89.2905,12.5087,355.6096},
	{-230.0808,82.3593,12.5105,0.2422},
	{-228.8895,74.2748,12.5043,10.7567},
	{-226.0399,65.9873,12.4989,22.6817},
	{-201.4961,36.9548,12.4812,53.2869},
	{-194.2692,32.9693,12.4796,64.7171},
	{-187.4384,30.0654,12.4763,68.5254},
	{-180.1900,28.1434,12.4810,77.2159},
	{-243.4106,73.3244,12.5049,191.7566},
	{-244.6625,81.5551,12.5050,186.4288},
	{-245.0915,89.5907,12.5064,180.2905},
	{-244.4870,97.6690,12.5050,173.5804},
	{-243.0440,106.3331,12.5055,169.3130},
	{-240.9400,114.2846,12.5112,162.3052},
	{-234.4421,49.9344,12.4658,214.0289},
	{-229.6848,42.9455,12.4627,216.1703}, 
	{-224.2319,36.5211,12.4626,222.6184},
	{-217.5043,30.2309,12.4674,229.2825},
	{-209.9534,24.6344,12.4697,235.0715},
	{-201.8890,20.0710,12.4746,243.0118},
	{-194.1309,16.9769,12.4688,252.4650},
	{-247.3340,65.0167,12.7438,127.5731},
	{-254.1765,59.5436,13.1122,129.4740},
	{-243.3407,52.5723,12.8797,317.1517},
	{-247.7376,46.4236,13.3237,329.6027},
	{-259.1083,52.7665,13.3982,151.6342},
	{-237.8337,121.4737,12.5082,156.2526},
	{-251.2709,39.1757,13.5721,335.8277},
	{-262.6420,45.1407,13.5843,157.8182},
	{-265.5314,36.2249,13.6243,162.3795}
};

static const Float:position_spawn_hotel_2[][] =
{
	{2215.0132,-2282.9568,21.5260,270.0554},
	{2215.0161,-2286.2012,21.5260,269.7479},
	{2215.1628,-2289.6257,21.5260,270.2110},
	{2215.2136,-2293.1565,21.5260,270.8683},
	{2215.1831,-2296.9304,21.5260,268.7608},
	{2215.1938,-2300.4668,21.5260,269.0645},
	{2215.2461,-2303.9333,21.5260,270.0558},
	{2215.2256,-2307.8271,21.5260,268.5901},
	{2215.2446,-2311.3506,21.5260,268.8033},
	{2215.2375,-2315.0525,21.5260,269.1438},
	{2215.1956,-2318.5259,21.5260,270.0210},
	{2215.2334,-2322.1946,21.5260,269.1056},
	{2215.2788,-2325.7844,21.5279,269.6885},
	{2228.4263,-2282.8445,21.5260,89.5720},
	{2228.3818,-2286.8018,21.5260,89.8887},
	{2228.4258,-2290.3962,21.5260,88.9216},
	{2228.4685,-2293.9109,21.5259,90.1095},
	{2228.3428,-2297.5137,21.5260,90.0254},
	{2228.3464,-2301.1194,21.5260,89.8365},
	{2228.3911,-2304.5002,21.5260,90.5893},
	{2228.2112,-2308.3057,21.5260,90.5432},
	{2228.2786,-2311.9243,21.5260,89.4490},
	{2228.4299,-2315.4719,21.5261,89.2522},
	{2228.4001,-2319.0305,21.5260,91.0338},
	{2228.5713,-2322.3423,21.5260,91.9502},
	{2228.5344,-2325.6631,21.5260,91.2690},
	{2086.2175,-2293.1187,21.6209,179.2933},
	{2086.3196,-2301.4250,21.6210,179.9781},
	{2086.3604,-2309.0916,21.6209,179.7034},
	{2086.3401,-2315.8801,21.6210,180.0823},
	{2086.5315,-2322.8018,21.6210,181.1430},
	{2080.5410,-2278.9158,21.6208,91.3118},
	{2074.9980,-2282.3328,21.6208,181.1181},
	{2074.9802,-2289.0803,21.6208,180.3019},
	{2075.1704,-2296.4907,21.6208,179.5679},
	{2075.2122,-2303.9878,21.6208,180.4557},
	{2075.1563,-2311.4722,21.6208,181.1664},
	{2075.1284,-2319.7876,21.6209,182.2039},
	{2075.2161,-2327.8796,21.6208,180.3154}
};



static const Float:position_spawn_hotel_3[][] =
{
	{191.2076,500.3234,11.8717,247.8553},
	{197.5945,497.7771,11.8717,248.1477},
	{203.7490,495.4520,11.8717,249.0448},
	{184.1700,503.0846,11.8717,248.7511},
	{176.9263,505.8669,11.8699,248.1389},
	{170.0425,508.5554,11.8700,246.5552},
	{164.1767,510.9141,11.8717,249.6462},
	{158.5411,513.0255,11.8699,248.6974},
	{209.6637,493.1266,11.8717,249.4677},
	{171.8290,526.6914,11.8672,68.7049},
	{178.6559,524.1323,11.8706,68.4314},
	{184.5683,521.7236,11.8707,68.1086},
	{190.6087,519.4404,11.8706,68.6499},
	{196.3912,517.2456,11.8672,68.3852},
	{202.6987,514.8961,11.8707,68.2542},
	{208.2604,512.5813,11.8707,66.5807},
	{213.9610,510.3634,11.8707,68.3689},
	{219.9343,508.1569,11.8705,67.9597},
	{225.7580,505.8807,11.8707,66.8104},
	{231.8346,503.4322,11.8707,65.6940},
	{245.1149,498.2345,11.8707,67.9587},
	{252.0371,495.6100,11.8707,67.0017},
	{216.3695,490.6667,11.8717,249.1651},
	{222.9037,488.0305,11.8717,248.7119},
	{229.3039,485.4414,11.8717,248.7751},
	{235.6978,482.9973,11.8717,250.2712},
	{242.4240,480.4376,11.8717,248.4178},
	{248.4366,478.1104,11.8717,249.2881},
	{254.8538,475.6500,11.8717,249.4423},
	{261.3827,473.0957,11.8716,249.0628},
	{258.0803,493.0765,11.8709,66.8520},
	{159.0810,531.4717,11.8706,69.5809},
	{153.4783,533.6116,11.8707,68.3854},
	{146.3296,536.5012,11.8706,68.1693},
	{152.6192,515.4965,11.8716,247.6607},
	{147.0686,517.6153,11.8716,247.7504}
};


static const Float:position_spawn_hotel_4[][] =
{
	{-2436.5696,2877.3613,37.4202,180.3326}, 
	{-2440.8582,2877.3394,37.4207,179.9470}, 
	{-2444.9373,2877.2344,37.4201,179.6185}, 
	{-2449.0625,2877.1853,37.4201,180.5685}, 
	{-2453.1714,2877.2043,37.4201,181.0937}, 
	{-2457.2400,2877.1045,37.4461,181.1922}, 
	{-2461.4695,2877.1631,37.4201,180.1046}, 
	{-2465.5872,2877.1897,37.4201,180.6664}, 
	{-2469.5859,2877.1423,37.4201,180.4981}, 
	{-2473.7617,2877.1284,37.4201,181.1985}, 
	{-2478.0081,2877.1921,37.4201,181.2273}, 
	{-2482.1833,2877.2610,37.4201,180.0424}, 
	{-2486.1721,2877.1775,37.4201,180.8166}, 
	{-2490.3008,2877.2104,37.4201,180.1701}, 
	{-2494.5933,2877.2910,37.4201,179.9508}, 
	{-2441.1709,2863.9658,37.4201,0.8604}, 
	{-2445.0149,2863.9109,37.4201,3.5451}, 
	{-2449.1238,2863.7712,37.4201,3.2447}, 
	{-2453.0085,2863.9226,37.4201,2.5600}, 
	{-2456.9063,2863.8313,37.4201,3.0053}, 
	{-2460.9563,2863.8247,37.4201,0.1993}, 
	{-2464.5088,2863.9353,37.4201,0.7417}, 
	{-2468.3254,2863.8745,37.4201,0.5375}, 
	{-2472.0425,2863.9458,37.4201,2.1673}, 
	{-2475.7183,2863.9268,37.4201,1.7875}, 
	{-2479.1555,2863.9175,37.4201,2.0229}, 
	{-2482.4609,2863.8816,37.4201,0.3956}, 
	{-2486.2571,2864.0479,37.4201,2.4954}, 
	{-2489.7781,2864.0186,37.4201,2.4243}, 
	{-2493.3665,2863.9585,37.4201,2.7214}, 
	{-2497.0017,2863.9063,37.4201,1.7275}, 
	{-2498.4548,2877.3433,37.4201,178.4858}, 
	{-2500.2185,2863.8438,37.4201,0.2538}, 
	{-2432.4187,2883.5054,37.4201,270.0222}, 
	{-2432.3862,2887.6436,37.4201,270.6782}, 
	{-2432.4509,2891.8650,37.4201,272.2850}
};


static const Float:position_spawn_autosalon_1[][] =
{
	{496.2794,2258.6084,11.7864,331.0653},
	{491.8055,2260.8484,11.7943,333.1315},
	{487.6313,2263.0676,11.7870,332.1187},
	{483.2168,2265.4224,11.7925,331.1891},
	{478.8703,2267.6929,11.7871,331.8698},
	{474.2588,2270.1711,11.7943,331.1767},
	{470.0360,2272.3164,11.7868,332.5841},
	{466.3938,2265.9226,11.7933,152.0414},
	{470.5729,2263.6736,11.7977,151.6321},
	{475.2416,2261.0933,11.7947,150.7318},
	{479.5886,2258.7644,11.7906,151.7838},
	{483.8151,2256.5693,11.7933,150.8328},
	{488.2624,2254.2073,11.8024,151.2056},
	{492.5320,2251.9468,11.7952,151.3631},
	{469.4779,2221.2761,11.7944,241.3948},
	{467.0840,2216.8945,11.7644,242.7202},
	{464.6563,2212.6619,11.7958,242.1745},
	{462.2459,2208.3589,11.7964,242.2830},
	{459.7108,2204.0781,11.7975,242.5645},
	{455.0215,2195.5059,11.7864,242.2542},
	{452.4126,2191.2402,11.7864,240.9978},
	{449.7714,2186.6980,11.7864,239.2763},
	{447.8629,2182.9465,11.7864,238.4752},
	{445.7681,2179.1194,11.7864,240.7978},
	{443.6452,2175.2559,11.7864,240.4670},
	{441.6716,2171.5596,11.7864,239.1345},
	{514.0989,2220.1553,11.7864,60.7677},
	{511.7332,2215.4675,11.7864,62.6130},
	{509.2346,2210.8789,11.7864,66.0163},
	{507.2883,2206.9934,11.7864,62.1058},
	{505.1971,2202.9958,11.7865,63.4612},
	{503.3098,2199.5581,11.7864,61.1279},
	{501.3806,2195.9980,11.7864,63.0541},
	{499.4225,2192.2856,11.7864,62.3072},
	{497.4278,2188.7566,11.7894,62.3845},
	{495.5235,2185.5264,11.7901,63.3694},
	{493.8061,2181.7629,11.7901,64.5969},
	{492.0435,2178.5032,11.7901,62.3581},
	{490.1856,2174.8914,11.7907,65.0223},
	{488.2598,2171.1973,11.7939,63.4360},
	{486.5660,2167.7698,11.7939,64.0308}
};


static const Float:position_spawn_autosalon_2[][] =
{

	{380.6900,1177.7367,11.7935,172.7438}, 
	{385.4481,1177.2823,11.7949,174.8792}, 
	{390.2355,1176.5898,11.7565,173.8725}, 
	{394.9669,1176.0437,11.7951,175.1601}, 
	{400.3021,1175.5378,11.7993,173.2160}, 
	{405.2024,1174.9717,11.8041,175.5949}, 
	{410.1048,1174.3781,11.7652,173.0680}, 
	{467.7547,1188.5150,11.8001,107.4910}, 
	{468.4418,1193.6125,11.7984,106.8416}, 
	{468.9195,1198.2668,11.7910,110.1615}, 
	{469.4240,1203.0293,11.7936,106.9170}, 
	{469.9277,1207.7444,11.7853,109.1439}, 
	{470.5145,1212.8412,11.7957,108.0892}, 
	{471.0170,1217.4010,11.7930,109.9504}, 
	{471.4844,1221.8967,11.7938,108.1658}, 
	{472.0905,1227.2556,11.7955,108.3309}, 
	{482.1700,1225.9025,11.7873,241.7924}, 
	{481.0402,1221.3430,11.7869,241.0511}, 
	{480.5654,1216.4344,11.7954,242.0085}, 
	{479.9747,1211.5996,11.7890,239.6285}, 
	{479.8539,1206.4852,11.7867,237.9536}, 
	{478.8396,1202.0044,11.7922,239.5164}, 
	{478.5540,1196.9325,11.7891,238.4947}, 
	{477.8500,1192.2758,11.8096,241.4728}, 
	{477.3080,1187.6195,11.7934,241.6218}, 
	{376.1007,1178.4440,11.7867,170.4783}, 
	{372.6907,1178.9144,11.7867,169.9064}, 
	{368.6861,1179.4312,11.7867,172.1201}, 
	{365.1637,1180.0615,11.7867,171.4183}, 
	{414.8974,1173.9054,11.7867,173.5495}, 
	{418.7257,1173.4817,11.7867,173.7868}, 
	{422.3372,1172.6443,11.7867,170.4599}, 
	{425.7744,1172.1738,11.7867,172.6976}, 
	{477.3758,1156.5631,11.7941,352.3879}, 
	{472.7816,1156.9834,11.7941,353.5074}, 
	{481.6537,1156.1432,11.7941,350.4911}, 
	{486.2602,1165.3025,11.7867,84.1105}, 
	{486.7402,1170.1731,11.7871,80.1178}, 
	{487.3462,1174.8884,11.7867,81.8251}, 
	{487.8867,1179.7104,11.7867,80.8227}, 
	{488.3831,1184.7267,11.7904,80.3654}, 
	{488.9688,1189.7856,11.7867,83.8756}, 
	{489.4388,1194.5118,11.7867,81.2696}, 
	{489.8197,1199.4983,11.7867,81.4708}, 
	{490.4339,1204.1997,11.7867,80.3679}, 
	{490.8952,1208.1069,11.7885,80.2290}, 
	{491.2442,1211.9246,11.7941,80.3287}, 
	{491.7475,1215.7720,11.7941,81.5872}, 
	{492.0589,1219.4895,11.7941,82.7720}, 
	{492.5717,1223.2975,11.7867,79.7500}, 
	{492.8978,1227.1815,11.7867,79.9174}, 
	{493.3974,1230.9520,11.7867,79.1682}, 
	{494.0511,1234.6603,11.7867,80.5265}, 
	{494.4919,1238.3969,11.7867,81.4349}, 
	{494.9529,1242.1337,11.7896,81.3011}
};

static const Float:position_spawn_autosalon_3[][] =
{
	{2326.8621,-1774.2043,22.2403,178.4040}, 
	{2322.7334,-1773.7244,22.2401,175.6906}, 
	{2318.8518,-1773.9888,22.2308,176.7179}, 
	{2315.0437,-1773.7633,22.2405,178.2931}, 
	{2303.1926,-1773.5618,22.2374,269.6504}, 
	{2303.4827,-1793.4949,22.2405,270.0779}, 
	{2303.5984,-1797.7451,22.2416,270.6537}, 
	{2303.5503,-1801.8530,22.2410,269.2414}, 
	{2303.5369,-1806.1462,22.2411,270.1697}, 
	{2303.6709,-1810.3698,22.2416,271.7611}, 
	{2303.5063,-1814.5708,22.2416,270.3318}, 
	{2303.4270,-1818.6343,22.2468,270.9342}, 
	{2303.5522,-1822.9083,22.2480,269.7396}, 
	{2303.6301,-1827.0454,22.2477,269.4792}, 
	{2303.5149,-1831.3396,22.2473,269.0689}, 
	{2303.3835,-1835.4126,22.2507,267.9197}, 
	{2303.4312,-1839.5883,22.1933,270.0990}, 
	{2303.3181,-1843.9039,22.1929,268.1325}, 
	{2303.1821,-1848.2350,22.2323,270.1707}, 
	{2303.0950,-1851.8551,22.2425,269.7779}, 
	{2303.3972,-1855.3268,22.2409,266.9919}, 
	{2326.0950,-1842.9030,22.2403,89.2963}, 
	{2326.1882,-1838.9823,22.2404,90.1441}, 
	{2326.0598,-1835.3872,22.2409,89.0193}, 
	{2326.0608,-1831.7274,22.2415,89.2931}, 
	{2326.1650,-1828.0920,22.2414,88.7059}, 
	{2326.4465,-1824.5192,22.2407,88.8433}, 
	{2326.4783,-1820.9380,22.2342,89.7179}, 
	{2326.3938,-1817.2279,22.2407,89.7957}, 
	{2326.2087,-1813.9678,22.2406,88.8524}, 
	{2326.2075,-1810.5461,22.2406,88.7775}, 
	{2326.2837,-1795.4303,22.2406,92.7056}, 
	{2326.3513,-1791.2495,22.2172,93.8619}, 
	{2326.3440,-1787.2102,22.2404,92.6020}, 
	{2326.4387,-1783.4854,22.2424,90.8887}, 
	{2326.5752,-1857.2689,22.2400,1.6328}, 
	{2322.7761,-1857.2316,22.2401,1.9171}, 
	{2319.1252,-1857.0933,22.2401,3.4200}, 
	{2315.7231,-1857.1791,22.2401,2.6714}, 
	{2311.9976,-1857.2349,22.2401,0.8407}, 
	{2326.0959,-1846.2876,22.2401,90.2655}, 
	{2303.4951,-1789.0165,22.2401,268.5251}

};

static const Float:parking_vehicle_position_spawn[][] = 
{
	{208.1463,767.3187,1204.8004,269.8221},
	{208.0674,762.2500,1204.8002,269.8317},
	{208.1684,757.3200,1204.7836,269.6949},
	{208.0060,752.3203,1204.8000,271.3058},
	{208.0905,747.5128,1204.8000,270.0843},
	{208.0782,742.2146,1204.8002,269.6762},
	{208.0898,737.2557,1204.8002,270.0638},
	{208.1334,732.2776,1204.8003,269.6395},
	{208.2562,727.4539,1204.8003,269.0322},
	{208.1987,722.2975,1204.8000,270.0293},
	{240.8778,709.6671,1204.8002,89.8134},
	{240.8877,714.4504,1204.8003,89.4785},
	{240.8555,719.4924,1204.8003,90.3186},
	{240.8822,724.6876,1204.8003,89.1618},
	{240.8223,729.6494,1204.8000,89.6815},
	{240.7738,734.6984,1204.8003,91.2178},
	{240.8063,739.6011,1204.8002,90.3948},
	{240.7807,744.7568,1204.8002,90.4129},
	{240.7022,749.4707,1204.8002,90.0582},
	{240.7961,754.4873,1204.8002,90.1997},
	{240.7989,759.6038,1204.8003,89.3280},
	{240.7894,764.6894,1204.8003,90.7201},
	{240.7663,769.6769,1204.8000,89.3579},
	{240.7767,774.6529,1204.8003,90.1525},
	{240.7327,779.5587,1204.8002,90.1709},
	{240.8601,779.6183,1212.8003,90.0541},
	{240.7843,774.6144,1212.8002,90.0269},
	{240.9629,769.5863,1212.8002,88.9664},
	{240.8376,764.5198,1212.8002,90.8002},
	{240.8466,759.6646,1212.8002,89.6542},
	{240.8517,754.4620,1212.8003,90.7574},
	{240.7602,749.5272,1212.8002,89.7687},
	{240.8082,744.4370,1212.8003,89.7652},
	{240.8243,739.4323,1212.8002,89.3501},
	{240.7713,734.7468,1212.8002,89.7971},
	{240.7958,729.5035,1212.8002,88.9875},
	{240.7852,724.4621,1212.8002,88.9933},
	{240.7892,719.7066,1212.8003,90.1957},
	{240.7954,714.6702,1212.8004,90.1557},
	{240.7787,709.7963,1212.8002,89.7108},
	{208.0964,767.4138,1212.8003,270.6634},
	{208.2009,762.3363,1212.8002,270.6519},
	{208.0899,757.3771,1212.8003,270.1420},
	{208.2273,752.3450,1212.8003,269.5930},
	{208.2118,747.4121,1212.8003,269.9326},
	{208.2913,742.4914,1212.8000,270.5745},
	{208.2066,737.3331,1212.8003,270.1451},
	{208.2365,732.4765,1212.8002,270.7051},
	{208.2548,727.6165,1212.8003,268.8885},
	{208.2413,722.2386,1212.8002,270.5078}
 	
};


callback:: load_all_config_autosalon()
{
	new Result:trans = sql_queryEx(zConn, "SELECT * FROM `transport_autosalon` ORDER BY `autosalon_config_id`", QUERY_CACHED);

	new all_transport_autosalon = sql_num_rows(trans);

	new time = GetTickCount();


 	for(new i; i < all_transport_autosalon; i++)
	{
		autosalon_transport_config[i][autosalon_config_id]  = sql_get_field_assoc_int_ex(trans, i, "autosalon_config_id"); 

		autosalon_transport_config[i][autosalon_car_count][0]  = sql_get_field_assoc_int_ex(trans, i, "autosalon_car_count_1"); 
		autosalon_transport_config[i][autosalon_car_count][1]  = sql_get_field_assoc_int_ex(trans, i, "autosalon_car_count_2"); 
		autosalon_transport_config[i][autosalon_car_count][2]  = sql_get_field_assoc_int_ex(trans, i, "autosalon_car_count_3"); 
		autosalon_transport_config[i][autosalon_car_count][3]  = sql_get_field_assoc_int_ex(trans, i, "autosalon_car_count_4"); 
		autosalon_transport_config[i][autosalon_car_count][4]  = sql_get_field_assoc_int_ex(trans, i, "autosalon_car_count_5"); 
		autosalon_transport_config[i][autosalon_car_count][5]  = sql_get_field_assoc_int_ex(trans, i, "autosalon_car_count_6"); 
		autosalon_transport_config[i][autosalon_car_count][6]  = sql_get_field_assoc_int_ex(trans, i, "autosalon_car_count_7"); 
		autosalon_transport_config[i][autosalon_car_count][7]  = sql_get_field_assoc_int_ex(trans, i, "autosalon_car_count_8"); 
		autosalon_transport_config[i][autosalon_car_count][8]  = sql_get_field_assoc_int_ex(trans, i, "autosalon_car_count_9"); 
		autosalon_transport_config[i][autosalon_car_count][9]  = sql_get_field_assoc_int_ex(trans, i, "autosalon_car_count_10"); 
		autosalon_transport_config[i][autosalon_car_count][10]  = sql_get_field_assoc_int_ex(trans, i, "autosalon_car_count_11"); 

		autosalon_transport_config[i][autosalon_car_count][11]  = sql_get_field_assoc_int_ex(trans, i, "autosalon_car_count_12"); 
		autosalon_transport_config[i][autosalon_car_count][12]  = sql_get_field_assoc_int_ex(trans, i, "autosalon_car_count_13"); 
		autosalon_transport_config[i][autosalon_car_count][13]  = sql_get_field_assoc_int_ex(trans, i, "autosalon_car_count_14"); 
		autosalon_transport_config[i][autosalon_car_count][14]  = sql_get_field_assoc_int_ex(trans, i, "autosalon_car_count_15"); 

		autosalon_transport_config[i][autosalon_car_count][15]  = sql_get_field_assoc_int_ex(trans, i, "autosalon_car_count_16"); 
		autosalon_transport_config[i][autosalon_car_count][16]  = sql_get_field_assoc_int_ex(trans, i, "autosalon_car_count_17"); 
		autosalon_transport_config[i][autosalon_car_count][17]  = sql_get_field_assoc_int_ex(trans, i, "autosalon_car_count_18"); 
		autosalon_transport_config[i][autosalon_car_count][18]  = sql_get_field_assoc_int_ex(trans, i, "autosalon_car_count_19"); 
		autosalon_transport_config[i][autosalon_car_count][19]  = sql_get_field_assoc_int_ex(trans, i, "autosalon_car_count_20"); 
		autosalon_transport_config[i][autosalon_car_count][20]  = sql_get_field_assoc_int_ex(trans, i, "autosalon_car_count_21"); 
		autosalon_transport_config[i][autosalon_car_count][21]  = sql_get_field_assoc_int_ex(trans, i, "autosalon_car_count_22"); 
		autosalon_transport_config[i][autosalon_car_count][22]  = sql_get_field_assoc_int_ex(trans, i, "autosalon_car_count_23"); 
		autosalon_transport_config[i][autosalon_car_count][23]  = sql_get_field_assoc_int_ex(trans, i, "autosalon_car_count_24"); 
		autosalon_transport_config[i][autosalon_car_count][24]  = sql_get_field_assoc_int_ex(trans, i, "autosalon_car_count_25"); 
		autosalon_transport_config[i][autosalon_car_count][25]  = sql_get_field_assoc_int_ex(trans, i, "autosalon_car_count_26"); 
		autosalon_transport_config[i][autosalon_car_count][26]  = sql_get_field_assoc_int_ex(trans, i, "autosalon_car_count_27"); 
		autosalon_transport_config[i][autosalon_car_count][27]  = sql_get_field_assoc_int_ex(trans, i, "autosalon_car_count_28"); 
		autosalon_transport_config[i][autosalon_car_count][28]  = sql_get_field_assoc_int_ex(trans, i, "autosalon_car_count_29"); 
		autosalon_transport_config[i][autosalon_car_count][29]  = sql_get_field_assoc_int_ex(trans, i, "autosalon_car_count_30"); 

		autosalon_transport_config[i][autosalon_car_payday_random] = sql_get_field_assoc_int_ex(trans, i, "autosalon_car_payday_random"); 

	}
	printf("[Конфиг Авто Автосалоны]: <%i из %i>. Времени затрачено: <%d мс>" , all_transport_autosalon, 3, GetTickCount() -  time);

	sql_free_result(trans);

	return true;
}

stock dialog_show_select_autosalon(playerid, type)
{


	switch(type)
	{
		case BUISNES_AUTOSALON_1:
		{
			SPD(playerid, DIALOG_START_SELECT_CAR_1, DIALOG_STYLE_MSGBOX, !""cBLUE"Автосалон «Арзамас Карс»", !"\
			"cBLUE"-"cWH" Добро пожаловать в Автосалон «Арзамас Карс»!\n\n\
			Мы поможет Вам подобрать автомобиль Вашей мечты, хотите ознакомиться с доступными\n\
			автомобилями в нашем автосалоне на текущий момент?", !"Да", !"Нет");			
		}
		case BUISNES_AUTOSALON_2:
		{
			SPD(playerid, DIALOG_START_SELECT_CAR_2, DIALOG_STYLE_MSGBOX, !""cBLUE"Автосалон «АвтоХаус»", !"\
			"cBLUE"-"cWH" Добро пожаловать в Автосалон «АвтоХаус»!\n\n\
			Мы поможет Вам подобрать автомобиль Вашей мечты, хотите ознакомиться с доступными\n\
			автомобилями в нашем автосалоне на текущий момент?", !"Да", !"Нет");	
		}
		case BUISNES_AUTOSALON_3:
		{
			SPD(playerid, DIALOG_START_SELECT_CAR_3, DIALOG_STYLE_MSGBOX, !""cBLUE"Автосалон «АвтоДвор»", !"\
			"cBLUE"-"cWH" Добро пожаловать в Автосалон «АвтоДвор»!\n\n\
			Мы поможет Вам подобрать автомобиль Вашей мечты, хотите ознакомиться с доступными\n\
			автомобилями в нашем автосалоне на текущий момент?", !"Да", !"Нет");	
		}
	}

	return true;
}

stock start_select_vehicle_shop(playerid, type_shop)
{
	switch(type_shop)
	{
		case BUISNES_AUTOSALON_1:
		{
			InterpolateCameraPos(playerid, -183.112747, -8.362843, 1202.406860, -202.424255, -11.551532, 1202.106201, 2000);
			InterpolateCameraLookAt(playerid, -187.675033, -10.373191, 1202.027343, -207.076553, -13.374571, 1201.925537, 2000);
			SetPlayerVirtualWorld(playerid, playerid+150);

			show_car_autosalon_start_1(playerid);

			TogglePlayerControllable(playerid, false);

			SetPVarIntNew(playerid, "type_autosalon_select_car", BUISNES_AUTOSALON_1);

			alt_info_player(playerid, TEXTDRAW_HIDE);
		}
		case BUISNES_AUTOSALON_2:
		{

			InterpolateCameraPos(playerid, -22.481674, 364.236206, 1602.682495, -19.545734, 352.704010, 1602.141723, 2000);
			InterpolateCameraLookAt(playerid, -22.287956, 359.247344, 1602.411010, -14.562236, 352.442504, 1601.831298, 2000);

			SetPlayerVirtualWorld(playerid, playerid+150);

			show_car_autosalon_start_2(playerid);

			TogglePlayerControllable(playerid, false);

			SetPVarIntNew(playerid, "type_autosalon_select_car", BUISNES_AUTOSALON_2);

			alt_info_player(playerid, TEXTDRAW_HIDE);
		}
		case BUISNES_AUTOSALON_3:
		{
			SetPlayerVirtualWorld(playerid, playerid+150);

			InterpolateCameraPos(playerid, -22.516603, -702.220031, 1202.529907, -28.539335, -710.452392, 1202.676635, 2000);
			InterpolateCameraLookAt(playerid, -22.461452, -697.226440, 1202.282470, -30.960269, -706.111145, 1202.135620, 2000);

			show_car_autosalon_start_3(playerid);

			TogglePlayerControllable(playerid, false);

			SetPVarIntNew(playerid, "type_autosalon_select_car", BUISNES_AUTOSALON_3);

			alt_info_player(playerid, TEXTDRAW_HIDE);

		}
	}

	return true;
}


stock show_car_autosalon_start_1(playerid)
{
	if(autosalon_id_buy_car[playerid] != 0)
	{
		DestroyVehicle(autosalon_id_buy_car[playerid]);
	}

	textdraw_autosalon_select(playerid, TEXTDRAW_SHOW, BUISNES_AUTOSALON_1);

	autosalon_id_buy_car[playerid] = CreateVehicle(MiddleVehicles[0], -208.7477,-13.5692,1201.8286,270.5706, 1, 1, 500000);

	SetVehicleRuNumberPlate(autosalon_id_buy_car[playerid], "x777am", "777");

	LinkVehicleToInterior(autosalon_id_buy_car[playerid],GetPlayerInterior(playerid));
	SetVehicleVirtualWorld(autosalon_id_buy_car[playerid], GetPlayerVirtualWorld(playerid));

	textdraw_autosalon_select(playerid, TEXTDRAW_UPDATE, BUISNES_AUTOSALON_1);

	autosalon_select_count[playerid] = 0;

	return true;
}

stock show_car_autosalon_start_2(playerid)
{
	if(autosalon_id_buy_car[playerid] != 0)
	{
		DestroyVehicle(autosalon_id_buy_car[playerid]);
	}

	textdraw_autosalon_select(playerid, TEXTDRAW_SHOW, BUISNES_AUTOSALON_2);

	autosalon_id_buy_car[playerid] = CreateVehicle(EliteVehicles[0], -13.0633,351.9801,1601.3119,61.1151, 1, 1, 500000);

	SetVehicleRuNumberPlate(autosalon_id_buy_car[playerid], "x777am", "777");

	LinkVehicleToInterior(autosalon_id_buy_car[playerid],GetPlayerInterior(playerid));
	SetVehicleVirtualWorld(autosalon_id_buy_car[playerid], GetPlayerVirtualWorld(playerid));

	textdraw_autosalon_select(playerid, TEXTDRAW_UPDATE, BUISNES_AUTOSALON_2);

	autosalon_select_count[playerid] = 0;

	return true;
}

stock show_car_autosalon_start_3(playerid)
{
	if(autosalon_id_buy_car[playerid] != 0)
	{
		DestroyVehicle(autosalon_id_buy_car[playerid]);
	}

	textdraw_autosalon_select(playerid, TEXTDRAW_SHOW, BUISNES_AUTOSALON_3);

	autosalon_id_buy_car[playerid] = CreateVehicle(EkonomVehicles[0], -31.5853,-705.9379,1201.7616,238.2043, 1, 1, 500000);

	SetVehicleRuNumberPlate(autosalon_id_buy_car[playerid], "x777am", "777");

	LinkVehicleToInterior(autosalon_id_buy_car[playerid],GetPlayerInterior(playerid));
	SetVehicleVirtualWorld(autosalon_id_buy_car[playerid], GetPlayerVirtualWorld(playerid));

	textdraw_autosalon_select(playerid, TEXTDRAW_UPDATE, BUISNES_AUTOSALON_3);

	autosalon_select_count[playerid] = 0;

	return true;
}

stock show_car_autosalon_next_1(playerid)
{
	if(autosalon_select_count[playerid] == 21)
		return true;

	autosalon_select_count[playerid]++;
	DestroyVehicle(autosalon_id_buy_car[playerid]);

	new 
		color_1 = GetPVarIntNew(playerid, "color_buy_car"),
		color_2 = GetPVarIntNew(playerid, "color_buy_car");

	autosalon_id_buy_car[playerid] = CreateVehicle(MiddleVehicles[autosalon_select_count[playerid]], -208.7477,-13.5692,1201.8286,270.5706, color_1, color_2, 500000);

	SetVehicleRuNumberPlate(autosalon_id_buy_car[playerid], "x777am", "777");

	LinkVehicleToInterior(autosalon_id_buy_car[playerid],GetPlayerInterior(playerid));
	SetVehicleVirtualWorld(autosalon_id_buy_car[playerid], GetPlayerVirtualWorld(playerid));

	textdraw_autosalon_select(playerid, TEXTDRAW_UPDATE, BUISNES_AUTOSALON_1);

	return true;
}

stock show_car_autosalon_next_2(playerid)
{
	if(autosalon_select_count[playerid] == 23)
		return true;

	autosalon_select_count[playerid]++;
	DestroyVehicle(autosalon_id_buy_car[playerid]);

	new 
		color_1 = GetPVarIntNew(playerid, "color_buy_car"),
		color_2 = GetPVarIntNew(playerid, "color_buy_car");

	autosalon_id_buy_car[playerid] = CreateVehicle(EliteVehicles[autosalon_select_count[playerid]], -13.0633,351.9801,1601.3119,61.1151, color_1, color_2, 500000);

	SetVehicleRuNumberPlate(autosalon_id_buy_car[playerid], "x777am", "777");

	LinkVehicleToInterior(autosalon_id_buy_car[playerid],GetPlayerInterior(playerid));
	SetVehicleVirtualWorld(autosalon_id_buy_car[playerid], GetPlayerVirtualWorld(playerid));

	textdraw_autosalon_select(playerid, TEXTDRAW_UPDATE, BUISNES_AUTOSALON_2);

	return true;
}

stock show_car_autosalon_next_3(playerid)
{
	if(autosalon_select_count[playerid] == 8)
		return true;

	autosalon_select_count[playerid]++;
	DestroyVehicle(autosalon_id_buy_car[playerid]);

	new 
		color_1 = GetPVarIntNew(playerid, "color_buy_car"),
		color_2 = GetPVarIntNew(playerid, "color_buy_car");

	autosalon_id_buy_car[playerid] = CreateVehicle(EkonomVehicles[autosalon_select_count[playerid]], -31.5853,-705.9379,1201.7616,238.2043, color_1, color_2, 500000);

	SetVehicleRuNumberPlate(autosalon_id_buy_car[playerid], "x777am", "777");

	LinkVehicleToInterior(autosalon_id_buy_car[playerid],GetPlayerInterior(playerid));
	SetVehicleVirtualWorld(autosalon_id_buy_car[playerid], GetPlayerVirtualWorld(playerid));

	textdraw_autosalon_select(playerid, TEXTDRAW_UPDATE, BUISNES_AUTOSALON_3);

	return true;
}

stock show_car_autosalon_prew_1(playerid)
{
	if(autosalon_select_count[playerid] == 0)
		return true;

	autosalon_select_count[playerid]--;
	DestroyVehicle(autosalon_id_buy_car[playerid]);

	new 
		color_1 = GetPVarIntNew(playerid, "color_buy_car"),
		color_2 = GetPVarIntNew(playerid, "color_buy_car");

	autosalon_id_buy_car[playerid] = CreateVehicle(MiddleVehicles[autosalon_select_count[playerid]], -208.7477,-13.5692,1201.8286,270.5706, color_1, color_2, 500000);

	SetVehicleRuNumberPlate(autosalon_id_buy_car[playerid], "x777am", "777");

	LinkVehicleToInterior(autosalon_id_buy_car[playerid],GetPlayerInterior(playerid));
	SetVehicleVirtualWorld(autosalon_id_buy_car[playerid], GetPlayerVirtualWorld(playerid));

	textdraw_autosalon_select(playerid, TEXTDRAW_UPDATE, BUISNES_AUTOSALON_1);

	return true;
}

stock show_car_autosalon_prew_2(playerid)
{
	if(autosalon_select_count[playerid] == 0)
		return true;

	autosalon_select_count[playerid]--;
	DestroyVehicle(autosalon_id_buy_car[playerid]);

	new 
		color_1 = GetPVarIntNew(playerid, "color_buy_car"),
		color_2 = GetPVarIntNew(playerid, "color_buy_car");

	autosalon_id_buy_car[playerid] = CreateVehicle(EliteVehicles[autosalon_select_count[playerid]], -13.0633,351.9801,1601.3119,61.1151, color_1, color_2, 500000);


	SetVehicleRuNumberPlate(autosalon_id_buy_car[playerid], "x777am", "777");

	LinkVehicleToInterior(autosalon_id_buy_car[playerid],GetPlayerInterior(playerid));
	SetVehicleVirtualWorld(autosalon_id_buy_car[playerid], GetPlayerVirtualWorld(playerid));

	textdraw_autosalon_select(playerid, TEXTDRAW_UPDATE, BUISNES_AUTOSALON_2);

	return true;
}

stock show_car_autosalon_prew_3(playerid)
{
	if(autosalon_select_count[playerid] == 0)
		return true;

	autosalon_select_count[playerid]--;
	DestroyVehicle(autosalon_id_buy_car[playerid]);

	new 
		color_1 = GetPVarIntNew(playerid, "color_buy_car"),
		color_2 = GetPVarIntNew(playerid, "color_buy_car");

	autosalon_id_buy_car[playerid] = CreateVehicle(EkonomVehicles[autosalon_select_count[playerid]], -31.5853,-705.9379,1201.7616,238.2043, color_1, color_2, 500000);


	SetVehicleRuNumberPlate(autosalon_id_buy_car[playerid], "x777am", "777");

	LinkVehicleToInterior(autosalon_id_buy_car[playerid],GetPlayerInterior(playerid));
	SetVehicleVirtualWorld(autosalon_id_buy_car[playerid], GetPlayerVirtualWorld(playerid));

	textdraw_autosalon_select(playerid, TEXTDRAW_UPDATE, BUISNES_AUTOSALON_3);

	return true;
}


stock move_camera_vehicle_shop_1(playerid)
{
	new 
		position_camera = GetPVarIntNew(playerid, "pos_camera_autosalon");

	switch(position_camera)
	{
		case 1:
		{
			InterpolateCameraPos(playerid, -202.423828, -11.551462, 1202.106201, -214.315475, -11.033710, 1202.249267, 2000);
			InterpolateCameraLookAt(playerid, -207.058166, -13.413929, 1201.873657, -209.962905, -13.482148, 1202.003662, 2000);	

			SetPVarIntNew(playerid, "pos_camera_autosalon", 2);		
		}
		case 2:
		{
			InterpolateCameraPos(playerid, -214.315475, -11.033710, 1202.249267, -213.119766, -16.021400, 1202.186035, 2000);
			InterpolateCameraLookAt(playerid, -210.025161, -13.580881, 1201.921508, -209.962905, -13.482148, 1202.003662, 2000);	

			SetPVarIntNew(playerid, "pos_camera_autosalon", 3);				
		}
		case 3:
		{
			InterpolateCameraPos(playerid, -212.946212, -15.802082, 1202.160522, -204.303192, -16.125339, 1202.080810, 2500);
			InterpolateCameraLookAt(playerid, -209.114837, -12.610500, 1201.793945, -208.335464, -13.182168, 1201.800659, 2500);	

			SetPVarIntNew(playerid, "pos_camera_autosalon", 4);				
		}
		case 4:
		{
			InterpolateCameraPos(playerid, -204.303192, -16.125339, 1202.080810, -213.752792, -11.002924, 1202.915405, 2500);
			InterpolateCameraLookAt(playerid, -208.192031, -12.997950, 1201.770385, -209.753768, -13.697750, 1201.594116, 2500);	

			SetPVarIntNew(playerid, "pos_camera_autosalon", 5);				
		}
		case 5:
		{
			InterpolateCameraPos(playerid, -213.752487, -11.003087, 1202.915405, -202.915176, -13.520561, 1203.246826, 2500);
			InterpolateCameraLookAt(playerid, -209.760696, -13.825801, 1201.867675, -207.592010, -13.613011, 1201.480834, 2500);

			SetPVarIntNew(playerid, "pos_camera_autosalon", 1);		
		}
	}
	return true;
}

stock move_camera_vehicle_shop_2(playerid)
{
	new 
		position_camera = GetPVarIntNew(playerid, "pos_camera_autosalon");

	switch(position_camera)
	{
		case 1:
		{
			InterpolateCameraPos(playerid, -19.545850, 352.704467, 1602.141723, -10.926927, 347.152923, 1602.077514, 2000);
			InterpolateCameraLookAt(playerid, -14.560022, 352.620117, 1601.775146, -12.943426, 351.718292, 1601.775756, 2000);

			SetPVarIntNew(playerid, "pos_camera_autosalon", 2);		
		}
		case 2:
		{
			InterpolateCameraPos(playerid, -10.926948, 347.152923, 1602.077514, -9.509331, 354.581695, 1602.078979, 2000);
			InterpolateCameraLookAt(playerid, -12.300991, 351.948333, 1601.736816, -12.675014, 350.732330, 1601.677856, 2000);

			SetPVarIntNew(playerid, "pos_camera_autosalon", 3);				
		}
		case 3:
		{
			InterpolateCameraPos(playerid, -9.509363, 354.581542, 1602.078979, -15.729630, 356.258087, 1602.093383, 2000);
			InterpolateCameraLookAt(playerid, -12.886532, 350.910217, 1601.738281, -13.623340, 351.738922, 1601.718139, 2000);

			SetPVarIntNew(playerid, "pos_camera_autosalon", 4);				
		}
		case 4:
		{
			InterpolateCameraPos(playerid, -15.729626, 356.258087, 1602.093383, -14.839109, 347.880584, 1602.511474, 2000);
			InterpolateCameraLookAt(playerid, -13.766250, 351.666748, 1601.839111, -12.914787, 352.394775, 1601.552734, 2000);

			SetPVarIntNew(playerid, "pos_camera_autosalon", 5);				
		}
		case 5:
		{
			InterpolateCameraPos(playerid, -14.839114, 347.880645, 1602.511474, -11.074625, 356.203308, 1602.391357, 2000);
			InterpolateCameraLookAt(playerid, -12.930963, 352.436737, 1601.736206, -13.129840, 351.682006, 1601.813476, 2000);
			SetPVarIntNew(playerid, "pos_camera_autosalon", 6);		
		}
		case 6:
		{
			InterpolateCameraPos(playerid, -11.074663, 356.203216, 1602.391357, -19.265886, 352.130249, 1602.469482, 2000);
			InterpolateCameraLookAt(playerid, -13.085812, 351.653900, 1601.882324, -14.327513, 352.199371, 1601.689941, 2000);
			SetPVarIntNew(playerid, "pos_camera_autosalon", 1);				
		}
	}
	return true;
}


stock move_camera_vehicle_shop_3(playerid)
{
	new 
		position_camera = GetPVarIntNew(playerid, "pos_camera_autosalon");

	switch(position_camera)
	{
		case 1:
		{
			InterpolateCameraPos(playerid, -28.465330, -710.395935, 1202.676635, -28.813112, -702.569885, 1202.849975, 2000);
			InterpolateCameraLookAt(playerid, -31.189477, -706.227722, 1202.223632, -31.922666, -706.365051, 1201.887084, 2000);

			SetPVarIntNew(playerid, "pos_camera_autosalon", 2);		
		}
		case 2:
		{
			InterpolateCameraPos(playerid, -28.813112, -702.569885, 1202.849975, -36.326015, -702.915405, 1202.888427, 2000);
			InterpolateCameraLookAt(playerid, -31.925148, -706.395080, 1202.023437, -32.074832, -705.415649, 1202.066162, 2000);

			SetPVarIntNew(playerid, "pos_camera_autosalon", 3);				
		}
		case 3:
		{
			InterpolateCameraPos(playerid, -36.325641, -702.915405, 1202.888427, -35.112934, -708.583679, 1202.736083, 2000);
			InterpolateCameraLookAt(playerid, -32.203628, -705.627197, 1202.078979, -31.375020, -705.344604, 1202.003662, 2000);

			SetPVarIntNew(playerid, "pos_camera_autosalon", 4);				
		}
		case 4:
		{
			InterpolateCameraPos(playerid, -35.112934, -708.583679, 1202.736083, -30.543958, -710.596496, 1202.762329, 2000);
			InterpolateCameraLookAt(playerid, -31.395765, -705.309692, 1202.055053, -31.140027, -705.679077, 1202.081298, 2000);

			SetPVarIntNew(playerid, "pos_camera_autosalon", 5);				
		}
		case 5:
		{
			InterpolateCameraPos(playerid, -35.112934, -708.583679, 1202.736083, -30.543958, -710.596496, 1202.762329, 2000);
			InterpolateCameraLookAt(playerid, -31.395765, -705.309692, 1202.055053, -31.140027, -705.679077, 1202.081298, 2000);

			SetPVarIntNew(playerid, "pos_camera_autosalon", 6);		
		}
		case 6:
		{
			InterpolateCameraPos(playerid, -33.579757, -702.086303, 1203.286865, -28.275392, -709.783752, 1202.885009, 2000);
			InterpolateCameraLookAt(playerid, -32.190025, -706.644958, 1201.774536, -30.966695, -705.681335, 1201.922119, 2000);
			SetPVarIntNew(playerid, "pos_camera_autosalon", 1);				
		}
	}
	return true;
}

stock textdraw_autosalon_select(playerid, status, type_salon)
{
	
	switch(status)
	{
		case TEXTDRAW_SHOW:
		{
			switch(type_salon)
			{
				case BUISNES_AUTOSALON_1:
				{
					hide_hud_element(playerid);
					TogglePlayerAllHudElements(playerid, HUD_ELEMENT_HIDE);

					TextDrawHideForPlayer(playerid, autosalon_elite_class[0]);
					TextDrawHideForPlayer(playerid, autosalon_elite_class[1]);
					TextDrawHideForPlayer(playerid, autosalon_elite_class[2]);
					TextDrawHideForPlayer(playerid, autosalon_elite_class[3]);
					TextDrawHideForPlayer(playerid, autosalon_elite_class[4]);
					TextDrawHideForPlayer(playerid, autosalon_elite_class[5]);
					TextDrawHideForPlayer(playerid, autosalon_elite_class[6]);
					TextDrawHideForPlayer(playerid, autosalon_elite_class[7]);
					TextDrawHideForPlayer(playerid, autosalon_elite_class[8]);


					TextDrawShowForPlayer(playerid, autosalon_middle_class[0]);
					TextDrawShowForPlayer(playerid, autosalon_middle_class[1]);
					TextDrawShowForPlayer(playerid, autosalon_middle_class[2]);
					TextDrawShowForPlayer(playerid, autosalon_middle_class[3]);
					TextDrawShowForPlayer(playerid, autosalon_middle_class[4]);
					TextDrawShowForPlayer(playerid, autosalon_middle_class[5]);
					TextDrawShowForPlayer(playerid, autosalon_middle_class[6]);
					TextDrawShowForPlayer(playerid, autosalon_middle_class[7]);
					TextDrawShowForPlayer(playerid, autosalon_middle_class[8]);

					create_autsalon_p(playerid);

					SetPVarIntNew(playerid, "page_color_autosalon", 1);
					SetPVarIntNew(playerid, "pos_camera_autosalon", 1);	
					textdraw_generate_color(playerid);

				}
				case BUISNES_AUTOSALON_2:
				{
					hide_hud_element(playerid);
					TogglePlayerAllHudElements(playerid, HUD_ELEMENT_HIDE);
					

					TextDrawHideForPlayer(playerid, autosalon_middle_class[0]);
					TextDrawHideForPlayer(playerid, autosalon_middle_class[1]);
					TextDrawHideForPlayer(playerid, autosalon_middle_class[2]);
					TextDrawHideForPlayer(playerid, autosalon_middle_class[3]);
					TextDrawHideForPlayer(playerid, autosalon_middle_class[4]);
					TextDrawHideForPlayer(playerid, autosalon_middle_class[5]);
					TextDrawHideForPlayer(playerid, autosalon_middle_class[6]);
					TextDrawHideForPlayer(playerid, autosalon_middle_class[7]);
					TextDrawHideForPlayer(playerid, autosalon_middle_class[8]);


					TextDrawShowForPlayer(playerid, autosalon_elite_class[0]);
					TextDrawShowForPlayer(playerid, autosalon_elite_class[1]);
					TextDrawShowForPlayer(playerid, autosalon_elite_class[2]);
					TextDrawShowForPlayer(playerid, autosalon_elite_class[3]);
					TextDrawShowForPlayer(playerid, autosalon_elite_class[4]);
					TextDrawShowForPlayer(playerid, autosalon_elite_class[5]);
					TextDrawShowForPlayer(playerid, autosalon_elite_class[6]);
					TextDrawShowForPlayer(playerid, autosalon_elite_class[7]);
					TextDrawShowForPlayer(playerid, autosalon_elite_class[8]);

					create_autsalon_p(playerid);

					SetPVarIntNew(playerid, "page_color_autosalon", 1);
					SetPVarIntNew(playerid, "pos_camera_autosalon", 1);	
					textdraw_generate_color(playerid);
				}
				case BUISNES_AUTOSALON_3:
				{
					hide_hud_element(playerid);
					TogglePlayerAllHudElements(playerid, HUD_ELEMENT_HIDE);

					TextDrawShowForPlayer(playerid, autosalon_low_class[0]);
					TextDrawShowForPlayer(playerid, autosalon_low_class[1]);
					TextDrawShowForPlayer(playerid, autosalon_low_class[2]);
					TextDrawShowForPlayer(playerid, autosalon_low_class[3]);
					TextDrawShowForPlayer(playerid, autosalon_low_class[4]);
					TextDrawShowForPlayer(playerid, autosalon_low_class[5]);
					TextDrawShowForPlayer(playerid, autosalon_low_class[6]);
					TextDrawShowForPlayer(playerid, autosalon_low_class[7]);
					TextDrawShowForPlayer(playerid, autosalon_low_class[8]);
	

					create_autsalon_p(playerid);

					SetPVarIntNew(playerid, "page_color_autosalon", 1);
					SetPVarIntNew(playerid, "pos_camera_autosalon", 1);	
					textdraw_generate_color(playerid);
				}
			}
			SelectTextDraw(playerid, COLOR_BLUE);


		}
		case TEXTDRAW_HIDE:
		{

			TogglePlayerAllHudElements(playerid, HUD_ELEMENT_SHOW);

			setting_hud_element_p(playerid);

			show_hud_element(playerid);	
			show_hud_hungry(playerid);

			TextDrawHideForPlayer(playerid, autosalon_middle_class[0]);
			TextDrawHideForPlayer(playerid, autosalon_middle_class[1]);
			TextDrawHideForPlayer(playerid, autosalon_middle_class[2]);
			TextDrawHideForPlayer(playerid, autosalon_middle_class[3]);
			TextDrawHideForPlayer(playerid, autosalon_middle_class[4]);
			TextDrawHideForPlayer(playerid, autosalon_middle_class[5]);
			TextDrawHideForPlayer(playerid, autosalon_middle_class[6]);
			TextDrawHideForPlayer(playerid, autosalon_middle_class[7]);
			TextDrawHideForPlayer(playerid, autosalon_middle_class[8]);

			TextDrawHideForPlayer(playerid, autosalon_elite_class[0]);
			TextDrawHideForPlayer(playerid, autosalon_elite_class[1]);
			TextDrawHideForPlayer(playerid, autosalon_elite_class[2]);
			TextDrawHideForPlayer(playerid, autosalon_elite_class[3]);
			TextDrawHideForPlayer(playerid, autosalon_elite_class[4]);
			TextDrawHideForPlayer(playerid, autosalon_elite_class[5]);
			TextDrawHideForPlayer(playerid, autosalon_elite_class[6]);
			TextDrawHideForPlayer(playerid, autosalon_elite_class[7]);
			TextDrawHideForPlayer(playerid, autosalon_elite_class[8]);

			TextDrawHideForPlayer(playerid, autosalon_low_class[0]);
			TextDrawHideForPlayer(playerid, autosalon_low_class[1]);
			TextDrawHideForPlayer(playerid, autosalon_low_class[2]);
			TextDrawHideForPlayer(playerid, autosalon_low_class[3]);
			TextDrawHideForPlayer(playerid, autosalon_low_class[4]);
			TextDrawHideForPlayer(playerid, autosalon_low_class[5]);
			TextDrawHideForPlayer(playerid, autosalon_low_class[6]);
			TextDrawHideForPlayer(playerid, autosalon_low_class[7]);
			TextDrawHideForPlayer(playerid, autosalon_low_class[8]);

			
			PlayerTextDrawHideEx(playerid, autosalon_info_td_p[0][playerid]);
			PlayerTextDrawHideEx(playerid, autosalon_info_td_p[1][playerid]);
			PlayerTextDrawHideEx(playerid, autosalon_info_td_p[2][playerid]);
			PlayerTextDrawHideEx(playerid, autosalon_info_td_p[3][playerid]);
			PlayerTextDrawHideEx(playerid, autosalon_info_td_p[4][playerid]);
			PlayerTextDrawHideEx(playerid, autosalon_info_td_p[5][playerid]);
			PlayerTextDrawHideEx(playerid, autosalon_info_td_p[6][playerid]);
			PlayerTextDrawHideEx(playerid, autosalon_info_td_p[7][playerid]);
			PlayerTextDrawHideEx(playerid, autosalon_info_td_p[8][playerid]);
			PlayerTextDrawHideEx(playerid, autosalon_info_td_p[9][playerid]);

			PlayerTextDrawHideEx(playerid, autosalon_info_td_p[10][playerid]);
			PlayerTextDrawHideEx(playerid, autosalon_info_td_p[11][playerid]);
			PlayerTextDrawHideEx(playerid, autosalon_info_td_p[12][playerid]);
			PlayerTextDrawHideEx(playerid, autosalon_info_td_p[13][playerid]);
			PlayerTextDrawHideEx(playerid, autosalon_info_td_p[14][playerid]);
			PlayerTextDrawHideEx(playerid, autosalon_info_td_p[15][playerid]);

			CancelSelectTextDraw(playerid);

		}
		case TEXTDRAW_UPDATE:
		{
			new 
				format_str[400];

			new 
				vehicle_id = autosalon_id_buy_car[playerid];


		 	format(format_str, sizeof(format_str),"%d_KM/H", transport_config[GetVehicleModel(vehicle_id)-400][transport_max_speed]);
		 	PlayerTextDrawSetString(playerid, autosalon_info_td_p[0][playerid], format_str);
		 	PlayerTextDrawShow(playerid, autosalon_info_td_p[0][playerid]);

		 	format(format_str, sizeof(format_str),"%d_L", transport_config[GetVehicleModel(vehicle_id)-400][transport_tank]);
		 	PlayerTextDrawSetString(playerid, autosalon_info_td_p[1][playerid], format_str);
		 	PlayerTextDrawShow(playerid, autosalon_info_td_p[1][playerid]);

		 	format(format_str, sizeof(format_str),"%d_L/_100KM", transport_config[GetVehicleModel(vehicle_id)-400][transport_fuel_count_km]);
		 	PlayerTextDrawSetString(playerid, autosalon_info_td_p[2][playerid], format_str);
		 	PlayerTextDrawShow(playerid, autosalon_info_td_p[2][playerid]);

		 	format(format_str, sizeof(format_str),"%d_KG", get_fuel_max_veh(vehicle_id));
		 	PlayerTextDrawSetString(playerid, autosalon_info_td_p[3][playerid], format_str);
		 	PlayerTextDrawShow(playerid, autosalon_info_td_p[3][playerid]);

		 	format(format_str, sizeof(format_str),"%d", transport_config[GetVehicleModel(vehicle_id)-400][transport_count_pass]);
		 	PlayerTextDrawSetString(playerid, autosalon_info_td_p[4][playerid], format_str);
		 	PlayerTextDrawShow(playerid, autosalon_info_td_p[4][playerid]);

		 	format(format_str, sizeof(format_str),"%s", transport_config[GetVehicleModel(vehicle_id)-400][transport_name]);
		 	PlayerTextDrawSetString(playerid, autosalon_info_td_p[6][playerid], format_str);
		 	PlayerTextDrawShow(playerid, autosalon_info_td_p[6][playerid]);

		 	format(format_str, sizeof(format_str),"%d_RUB", transport_config[GetVehicleModel(vehicle_id)-400][transport_price]);
		 	PlayerTextDrawSetString(playerid, autosalon_info_td_p[5][playerid], format_str);
		 	PlayerTextDrawShow(playerid, autosalon_info_td_p[5][playerid]);


		}
	}

	return true;
}


stock textdraw_generate_color(playerid)
{
	new 
		page = GetPVarIntNew(playerid, "page_color_autosalon");

	for(new i = 7; i < 14; i++)
	{
		if(autosalon_info_td_p[i][playerid] != PlayerText:INVALID_TEXT_DRAW)
		{
			PlayerTextDrawHideEx(playerid, autosalon_info_td_p[i][playerid]);
		}
	}
	switch(page)
	{
		case 1:
		{
			if(autosalon_info_td_p[7][playerid] == PlayerText:INVALID_TEXT_DRAW)
			{
				autosalon_info_td_p[7][playerid] = CreatePlayerTextDraw(playerid, 559.666503, 150.992614, "LD_BEAT:chit"); // Texture element
				PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[7][playerid], 0.000000, 0.000000);
				PlayerTextDrawTextSize(playerid, autosalon_info_td_p[7][playerid], 40.333301, 47.288799);
				PlayerTextDrawAlignment(playerid, autosalon_info_td_p[7][playerid], 2);
				PlayerTextDrawColor(playerid, autosalon_info_td_p[7][playerid], 0x020102FF);
				PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[7][playerid], 0);
				PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[7][playerid], 0);
				PlayerTextDrawFont(playerid, autosalon_info_td_p[7][playerid], 4);
				PlayerTextDrawSetSelectable(playerid, autosalon_info_td_p[7][playerid], true);
			}
			PlayerTextDrawShow(playerid, autosalon_info_td_p[7][playerid]);


			if(autosalon_info_td_p[8][playerid] == PlayerText:INVALID_TEXT_DRAW)
			{
				autosalon_info_td_p[8][playerid] = CreatePlayerTextDraw(playerid, 593.332824, 150.992599, "LD_BEAT:chit"); // Texture element
				PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[8][playerid], 0.000000, 0.000000);
				PlayerTextDrawTextSize(playerid, autosalon_info_td_p[8][playerid], 40.333301, 47.288879);
				PlayerTextDrawAlignment(playerid, autosalon_info_td_p[8][playerid], 2);
				PlayerTextDrawColor(playerid, autosalon_info_td_p[8][playerid], 0xFFFFFFF);
				PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[8][playerid], 0);
				PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[8][playerid], 0);
				PlayerTextDrawFont(playerid, autosalon_info_td_p[8][playerid], 4);
				PlayerTextDrawSetSelectable(playerid, autosalon_info_td_p[8][playerid], true);
			}
			PlayerTextDrawShow(playerid, autosalon_info_td_p[8][playerid]);

			if(autosalon_info_td_p[9][playerid] == PlayerText:INVALID_TEXT_DRAW)
			{
				autosalon_info_td_p[9][playerid] = CreatePlayerTextDraw(playerid, 593.999877, 187.081558, "LD_BEAT:chit"); // Texture element
				PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[9][playerid], 0.000000, 0.000000);
				PlayerTextDrawTextSize(playerid, autosalon_info_td_p[9][playerid], 40.333301, 47.288799);
				PlayerTextDrawAlignment(playerid, autosalon_info_td_p[9][playerid], 2);
				PlayerTextDrawColor(playerid, autosalon_info_td_p[9][playerid], 0x840510FF);
				PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[9][playerid], 0);
				PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[9][playerid], 0);
				PlayerTextDrawFont(playerid, autosalon_info_td_p[9][playerid], 4);
				PlayerTextDrawSetSelectable(playerid, autosalon_info_td_p[9][playerid], true);
			}
			PlayerTextDrawShow(playerid, autosalon_info_td_p[9][playerid]);

			if(autosalon_info_td_p[10][playerid] == PlayerText:INVALID_TEXT_DRAW)
			{
				autosalon_info_td_p[10][playerid] = CreatePlayerTextDraw(playerid, 559.666564, 187.081527, "LD_BEAT:chit"); // Texture element
				PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[10][playerid], 0.000000, 0.000000);
				PlayerTextDrawTextSize(playerid, autosalon_info_td_p[10][playerid], 40.333301, 47.288799);
				PlayerTextDrawAlignment(playerid, autosalon_info_td_p[10][playerid], 2);
				PlayerTextDrawColor(playerid, autosalon_info_td_p[10][playerid], 0x666A78FF);
				PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[10][playerid], 0);
				PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[10][playerid], 0);
				PlayerTextDrawFont(playerid, autosalon_info_td_p[10][playerid], 4);
				PlayerTextDrawSetSelectable(playerid, autosalon_info_td_p[10][playerid], true);
			}
			PlayerTextDrawShow(playerid, autosalon_info_td_p[10][playerid]);


			if(autosalon_info_td_p[11][playerid] == PlayerText:INVALID_TEXT_DRAW)
			{
				autosalon_info_td_p[11][playerid] = CreatePlayerTextDraw(playerid, 560.333190, 223.585205, "LD_BEAT:chit"); // Texture element
				PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[11][playerid], 0.000000, 0.000000);
				PlayerTextDrawTextSize(playerid, autosalon_info_td_p[11][playerid], 40.333301, 47.288799);
				PlayerTextDrawAlignment(playerid, autosalon_info_td_p[11][playerid], 2);
				PlayerTextDrawColor(playerid, autosalon_info_td_p[11][playerid], 0x4A76B5FF);
				PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[11][playerid], 0);
				PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[11][playerid], 0);
				PlayerTextDrawFont(playerid, autosalon_info_td_p[11][playerid], 4);
				PlayerTextDrawSetSelectable(playerid, autosalon_info_td_p[11][playerid], true);
			}
			PlayerTextDrawShow(playerid, autosalon_info_td_p[11][playerid]);

			if(autosalon_info_td_p[12][playerid] == PlayerText:INVALID_TEXT_DRAW)
			{
				autosalon_info_td_p[12][playerid] = CreatePlayerTextDraw(playerid, 594.000061, 222.755630, "LD_BEAT:chit"); // Texture element
				PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[12][playerid], 0.000000, 0.000000);
				PlayerTextDrawTextSize(playerid, autosalon_info_td_p[12][playerid], 40.333301, 47.288799);
				PlayerTextDrawAlignment(playerid, autosalon_info_td_p[12][playerid], 2);
				PlayerTextDrawColor(playerid, autosalon_info_td_p[12][playerid], 0xD1901BFF);
				PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[12][playerid], 0);
				PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[12][playerid], 0);
				PlayerTextDrawFont(playerid, autosalon_info_td_p[12][playerid], 4);
				PlayerTextDrawSetSelectable(playerid, autosalon_info_td_p[12][playerid], true);
			}
			PlayerTextDrawShow(playerid, autosalon_info_td_p[12][playerid]);

			if(autosalon_info_td_p[13][playerid] == PlayerText:INVALID_TEXT_DRAW)
			{
				autosalon_info_td_p[13][playerid] = CreatePlayerTextDraw(playerid, 561.000366, 261.333312, "LD_BEAT:chit"); // Texture element
				PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[13][playerid], 0.000000, 0.000000);
				PlayerTextDrawTextSize(playerid, autosalon_info_td_p[13][playerid], 40.333301, 47.288799);
				PlayerTextDrawAlignment(playerid, autosalon_info_td_p[13][playerid], 2);
				PlayerTextDrawColor(playerid, autosalon_info_td_p[13][playerid], 0xEC6BAEFF);
				PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[13][playerid], 0);
				PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[13][playerid], 0);
				PlayerTextDrawFont(playerid, autosalon_info_td_p[13][playerid], 4);
				PlayerTextDrawSetSelectable(playerid, autosalon_info_td_p[13][playerid], true);
			}
			PlayerTextDrawShow(playerid, autosalon_info_td_p[13][playerid]);

			if(autosalon_info_td_p[14][playerid] == PlayerText:INVALID_TEXT_DRAW)
			{
				autosalon_info_td_p[14][playerid] = CreatePlayerTextDraw(playerid, 594.667053, 260.918579, "LD_BEAT:chit"); // Texture element
				PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[14][playerid], 0.000000, 0.000000);
				PlayerTextDrawTextSize(playerid, autosalon_info_td_p[14][playerid], 40.333301, 47.288799);
				PlayerTextDrawAlignment(playerid, autosalon_info_td_p[14][playerid], 2);
				PlayerTextDrawColor(playerid, autosalon_info_td_p[14][playerid], 0x1A7415FF);
				PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[14][playerid], 0);
				PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[14][playerid], 0);
				PlayerTextDrawFont(playerid, autosalon_info_td_p[14][playerid], 4);
				PlayerTextDrawSetSelectable(playerid, autosalon_info_td_p[14][playerid], true);
			}		
			PlayerTextDrawShow(playerid, autosalon_info_td_p[14][playerid]);
		}
		case 2:
		{
			if(autosalon_info_td_p[7][playerid] == PlayerText:INVALID_TEXT_DRAW)
			{
				autosalon_info_td_p[7][playerid] = CreatePlayerTextDraw(playerid, 559.666503, 150.992614, "LD_BEAT:chit"); // Texture element
				PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[7][playerid], 0.000000, 0.000000);
				PlayerTextDrawTextSize(playerid, autosalon_info_td_p[7][playerid], 40.333301, 47.288799);
				PlayerTextDrawAlignment(playerid, autosalon_info_td_p[7][playerid], 2);
				PlayerTextDrawColor(playerid, autosalon_info_td_p[7][playerid], 0x593E68FF);
				PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[7][playerid], 0);
				PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[7][playerid], 0);
				PlayerTextDrawFont(playerid, autosalon_info_td_p[7][playerid], 4);
				PlayerTextDrawSetSelectable(playerid, autosalon_info_td_p[7][playerid], true);
			}
			PlayerTextDrawShow(playerid, autosalon_info_td_p[7][playerid]);


			if(autosalon_info_td_p[8][playerid] == PlayerText:INVALID_TEXT_DRAW)
			{
				autosalon_info_td_p[8][playerid] = CreatePlayerTextDraw(playerid, 593.332824, 150.992599, "LD_BEAT:chit"); // Texture element
				PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[8][playerid], 0.000000, 0.000000);
				PlayerTextDrawTextSize(playerid, autosalon_info_td_p[8][playerid], 40.333301, 47.288879);
				PlayerTextDrawAlignment(playerid, autosalon_info_td_p[8][playerid], 2);
				PlayerTextDrawColor(playerid, autosalon_info_td_p[8][playerid], 0x219996FF);
				PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[8][playerid], 0);
				PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[8][playerid], 0);
				PlayerTextDrawFont(playerid, autosalon_info_td_p[8][playerid], 4);
				PlayerTextDrawSetSelectable(playerid, autosalon_info_td_p[8][playerid], true);
			}
			PlayerTextDrawShow(playerid, autosalon_info_td_p[8][playerid]);

			if(autosalon_info_td_p[9][playerid] == PlayerText:INVALID_TEXT_DRAW)
			{
				autosalon_info_td_p[9][playerid] = CreatePlayerTextDraw(playerid, 593.999877, 187.081558, "LD_BEAT:chit"); // Texture element
				PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[9][playerid], 0.000000, 0.000000);
				PlayerTextDrawTextSize(playerid, autosalon_info_td_p[9][playerid], 40.333301, 47.288799);
				PlayerTextDrawAlignment(playerid, autosalon_info_td_p[9][playerid], 2);
				PlayerTextDrawColor(playerid, autosalon_info_td_p[9][playerid], 0x1D4D99FF);
				PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[9][playerid], 0);
				PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[9][playerid], 0);
				PlayerTextDrawFont(playerid, autosalon_info_td_p[9][playerid], 4);
				PlayerTextDrawSetSelectable(playerid, autosalon_info_td_p[9][playerid], true);
			}
			PlayerTextDrawShow(playerid, autosalon_info_td_p[9][playerid]);

			if(autosalon_info_td_p[10][playerid] == PlayerText:INVALID_TEXT_DRAW)
			{
				autosalon_info_td_p[10][playerid] = CreatePlayerTextDraw(playerid, 559.666564, 187.081527, "LD_BEAT:chit"); // Texture element
				PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[10][playerid], 0.000000, 0.000000);
				PlayerTextDrawTextSize(playerid, autosalon_info_td_p[10][playerid], 40.333301, 47.288799);
				PlayerTextDrawAlignment(playerid, autosalon_info_td_p[10][playerid], 2);
				PlayerTextDrawColor(playerid, autosalon_info_td_p[10][playerid], 0x8A794DFF);
				PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[10][playerid], 0);
				PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[10][playerid], 0);
				PlayerTextDrawFont(playerid, autosalon_info_td_p[10][playerid], 4);
				PlayerTextDrawSetSelectable(playerid, autosalon_info_td_p[10][playerid], true);
			}
			PlayerTextDrawShow(playerid, autosalon_info_td_p[10][playerid]);


			if(autosalon_info_td_p[11][playerid] == PlayerText:INVALID_TEXT_DRAW)
			{
				autosalon_info_td_p[11][playerid] = CreatePlayerTextDraw(playerid, 560.333190, 223.585205, "LD_BEAT:chit"); // Texture element
				PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[11][playerid], 0.000000, 0.000000);
				PlayerTextDrawTextSize(playerid, autosalon_info_td_p[11][playerid], 40.333301, 47.288799);
				PlayerTextDrawAlignment(playerid, autosalon_info_td_p[11][playerid], 2);
				PlayerTextDrawColor(playerid, autosalon_info_td_p[11][playerid], 0x358452FF);
				PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[11][playerid], 0);
				PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[11][playerid], 0);
				PlayerTextDrawFont(playerid, autosalon_info_td_p[11][playerid], 4);
				PlayerTextDrawSetSelectable(playerid, autosalon_info_td_p[11][playerid], true);
			}
			PlayerTextDrawShow(playerid, autosalon_info_td_p[11][playerid]);

			if(autosalon_info_td_p[12][playerid] == PlayerText:INVALID_TEXT_DRAW)
			{
				autosalon_info_td_p[12][playerid] = CreatePlayerTextDraw(playerid, 594.000061, 222.755630, "LD_BEAT:chit"); // Texture element
				PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[12][playerid], 0.000000, 0.000000);
				PlayerTextDrawTextSize(playerid, autosalon_info_td_p[12][playerid], 40.333301, 47.288799);
				PlayerTextDrawAlignment(playerid, autosalon_info_td_p[12][playerid], 2);
				PlayerTextDrawColor(playerid, autosalon_info_td_p[12][playerid], 0x7E994CFF);
				PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[12][playerid], 0);
				PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[12][playerid], 0);
				PlayerTextDrawFont(playerid, autosalon_info_td_p[12][playerid], 4);
				PlayerTextDrawSetSelectable(playerid, autosalon_info_td_p[12][playerid], true);
			}
			PlayerTextDrawShow(playerid, autosalon_info_td_p[12][playerid]);

			if(autosalon_info_td_p[13][playerid] == PlayerText:INVALID_TEXT_DRAW)
			{
				autosalon_info_td_p[13][playerid] = CreatePlayerTextDraw(playerid, 561.000366, 261.333312, "LD_BEAT:chit"); // Texture element
				PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[13][playerid], 0.000000, 0.000000);
				PlayerTextDrawTextSize(playerid, autosalon_info_td_p[13][playerid], 40.333301, 47.288799);
				PlayerTextDrawAlignment(playerid, autosalon_info_td_p[13][playerid], 2);
				PlayerTextDrawColor(playerid, autosalon_info_td_p[13][playerid], 0x9CA1A4FF);
				PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[13][playerid], 0);
				PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[13][playerid], 0);
				PlayerTextDrawFont(playerid, autosalon_info_td_p[13][playerid], 4);
				PlayerTextDrawSetSelectable(playerid, autosalon_info_td_p[13][playerid], true);
			}
			PlayerTextDrawShow(playerid, autosalon_info_td_p[13][playerid]);

			if(autosalon_info_td_p[14][playerid] == PlayerText:INVALID_TEXT_DRAW)
			{
				autosalon_info_td_p[14][playerid] = CreatePlayerTextDraw(playerid, 594.667053, 260.918579, "LD_BEAT:chit"); // Texture element
				PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[14][playerid], 0.000000, 0.000000);
				PlayerTextDrawTextSize(playerid, autosalon_info_td_p[14][playerid], 40.333301, 47.288799);
				PlayerTextDrawAlignment(playerid, autosalon_info_td_p[14][playerid], 2);
				PlayerTextDrawColor(playerid, autosalon_info_td_p[14][playerid], 0x57941DFF);
				PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[14][playerid], 0);
				PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[14][playerid], 0);
				PlayerTextDrawFont(playerid, autosalon_info_td_p[14][playerid], 4);
				PlayerTextDrawSetSelectable(playerid, autosalon_info_td_p[14][playerid], true);
			}		
			PlayerTextDrawShow(playerid, autosalon_info_td_p[14][playerid]);
		}
		case 3:
		{
			if(autosalon_info_td_p[7][playerid] == PlayerText:INVALID_TEXT_DRAW)
			{
				autosalon_info_td_p[7][playerid] = CreatePlayerTextDraw(playerid, 559.666503, 150.992614, "LD_BEAT:chit"); // Texture element
				PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[7][playerid], 0.000000, 0.000000);
				PlayerTextDrawTextSize(playerid, autosalon_info_td_p[7][playerid], 40.333301, 47.288799);
				PlayerTextDrawAlignment(playerid, autosalon_info_td_p[7][playerid], 2);
				PlayerTextDrawColor(playerid, autosalon_info_td_p[7][playerid], 0x319491FF);
				PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[7][playerid], 0);
				PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[7][playerid], 0);
				PlayerTextDrawFont(playerid, autosalon_info_td_p[7][playerid], 4);
				PlayerTextDrawSetSelectable(playerid, autosalon_info_td_p[7][playerid], true);
			}
			PlayerTextDrawShow(playerid, autosalon_info_td_p[7][playerid]);


			if(autosalon_info_td_p[8][playerid] == PlayerText:INVALID_TEXT_DRAW)
			{
				autosalon_info_td_p[8][playerid] = CreatePlayerTextDraw(playerid, 593.332824, 150.992599, "LD_BEAT:chit"); // Texture element
				PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[8][playerid], 0.000000, 0.000000);
				PlayerTextDrawTextSize(playerid, autosalon_info_td_p[8][playerid], 40.333301, 47.288879);
				PlayerTextDrawAlignment(playerid, autosalon_info_td_p[8][playerid], 2);
				PlayerTextDrawColor(playerid, autosalon_info_td_p[8][playerid], 0x8D573BFF);
				PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[8][playerid], 0);
				PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[8][playerid], 0);
				PlayerTextDrawFont(playerid, autosalon_info_td_p[8][playerid], 4);
				PlayerTextDrawSetSelectable(playerid, autosalon_info_td_p[8][playerid], true);
			}
			PlayerTextDrawShow(playerid, autosalon_info_td_p[8][playerid]);

			if(autosalon_info_td_p[9][playerid] == PlayerText:INVALID_TEXT_DRAW)
			{
				autosalon_info_td_p[9][playerid] = CreatePlayerTextDraw(playerid, 593.999877, 187.081558, "LD_BEAT:chit"); // Texture element
				PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[9][playerid], 0.000000, 0.000000);
				PlayerTextDrawTextSize(playerid, autosalon_info_td_p[9][playerid], 40.333301, 47.288799);
				PlayerTextDrawAlignment(playerid, autosalon_info_td_p[9][playerid], 2);
				PlayerTextDrawColor(playerid, autosalon_info_td_p[9][playerid], 0x851F2DFF);
				PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[9][playerid], 0);
				PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[9][playerid], 0);
				PlayerTextDrawFont(playerid, autosalon_info_td_p[9][playerid], 4);
				PlayerTextDrawSetSelectable(playerid, autosalon_info_td_p[9][playerid], true);
			}
			PlayerTextDrawShow(playerid, autosalon_info_td_p[9][playerid]);

			if(autosalon_info_td_p[10][playerid] == PlayerText:INVALID_TEXT_DRAW)
			{
				autosalon_info_td_p[10][playerid] = CreatePlayerTextDraw(playerid, 559.666564, 187.081527, "LD_BEAT:chit"); // Texture element
				PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[10][playerid], 0.000000, 0.000000);
				PlayerTextDrawTextSize(playerid, autosalon_info_td_p[10][playerid], 40.333301, 47.288799);
				PlayerTextDrawAlignment(playerid, autosalon_info_td_p[10][playerid], 2);
				PlayerTextDrawColor(playerid, autosalon_info_td_p[10][playerid], 0x893F8EFF);
				PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[10][playerid], 0);
				PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[10][playerid], 0);
				PlayerTextDrawFont(playerid, autosalon_info_td_p[10][playerid], 4);
				PlayerTextDrawSetSelectable(playerid, autosalon_info_td_p[10][playerid], true);
			}
			PlayerTextDrawShow(playerid, autosalon_info_td_p[10][playerid]);


			if(autosalon_info_td_p[11][playerid] == PlayerText:INVALID_TEXT_DRAW)
			{
				autosalon_info_td_p[11][playerid] = CreatePlayerTextDraw(playerid, 560.333190, 223.585205, "LD_BEAT:chit"); // Texture element
				PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[11][playerid], 0.000000, 0.000000);
				PlayerTextDrawTextSize(playerid, autosalon_info_td_p[11][playerid], 40.333301, 47.288799);
				PlayerTextDrawAlignment(playerid, autosalon_info_td_p[11][playerid], 2);
				PlayerTextDrawColor(playerid, autosalon_info_td_p[11][playerid], 0x526011FF);
				PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[11][playerid], 0);
				PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[11][playerid], 0);
				PlayerTextDrawFont(playerid, autosalon_info_td_p[11][playerid], 4);
				PlayerTextDrawSetSelectable(playerid, autosalon_info_td_p[11][playerid], true);
			}
			PlayerTextDrawShow(playerid, autosalon_info_td_p[11][playerid]);

			if(autosalon_info_td_p[12][playerid] == PlayerText:INVALID_TEXT_DRAW)
			{
				autosalon_info_td_p[12][playerid] = CreatePlayerTextDraw(playerid, 594.000061, 222.755630, "LD_BEAT:chit"); // Texture element
				PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[12][playerid], 0.000000, 0.000000);
				PlayerTextDrawTextSize(playerid, autosalon_info_td_p[12][playerid], 40.333301, 47.288799);
				PlayerTextDrawAlignment(playerid, autosalon_info_td_p[12][playerid], 2);
				PlayerTextDrawColor(playerid, autosalon_info_td_p[12][playerid], 0xAB9D83FF);
				PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[12][playerid], 0);
				PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[12][playerid], 0);
				PlayerTextDrawFont(playerid, autosalon_info_td_p[12][playerid], 4);
				PlayerTextDrawSetSelectable(playerid, autosalon_info_td_p[12][playerid], true);
			}
			PlayerTextDrawShow(playerid, autosalon_info_td_p[12][playerid]);

			if(autosalon_info_td_p[13][playerid] == PlayerText:INVALID_TEXT_DRAW)
			{
				autosalon_info_td_p[13][playerid] = CreatePlayerTextDraw(playerid, 561.000366, 261.333312, "LD_BEAT:chit"); // Texture element
				PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[13][playerid], 0.000000, 0.000000);
				PlayerTextDrawTextSize(playerid, autosalon_info_td_p[13][playerid], 40.333301, 47.288799);
				PlayerTextDrawAlignment(playerid, autosalon_info_td_p[13][playerid], 2);
				PlayerTextDrawColor(playerid, autosalon_info_td_p[13][playerid], 0x9A3E4BFF);
				PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[13][playerid], 0);
				PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[13][playerid], 0);
				PlayerTextDrawFont(playerid, autosalon_info_td_p[13][playerid], 4);
				PlayerTextDrawSetSelectable(playerid, autosalon_info_td_p[13][playerid], true);
			}
			PlayerTextDrawShow(playerid, autosalon_info_td_p[13][playerid]);

			if(autosalon_info_td_p[14][playerid] == PlayerText:INVALID_TEXT_DRAW)
			{
				autosalon_info_td_p[14][playerid] = CreatePlayerTextDraw(playerid, 594.667053, 260.918579, "LD_BEAT:chit"); // Texture element
				PlayerTextDrawLetterSize(playerid, autosalon_info_td_p[14][playerid], 0.000000, 0.000000);
				PlayerTextDrawTextSize(playerid, autosalon_info_td_p[14][playerid], 40.333301, 47.288799);
				PlayerTextDrawAlignment(playerid, autosalon_info_td_p[14][playerid], 2);
				PlayerTextDrawColor(playerid, autosalon_info_td_p[14][playerid], 0x2A3E57FF);
				PlayerTextDrawSetShadow(playerid, autosalon_info_td_p[14][playerid], 0);
				PlayerTextDrawSetOutline(playerid, autosalon_info_td_p[14][playerid], 0);
				PlayerTextDrawFont(playerid, autosalon_info_td_p[14][playerid], 4);
				PlayerTextDrawSetSelectable(playerid, autosalon_info_td_p[14][playerid], true);
			}		
			PlayerTextDrawShow(playerid, autosalon_info_td_p[14][playerid]);

		}
	}

	return true;
}


stock next_color_page_autosalon(playerid)
{
	if(GetPVarIntNew(playerid, "page_color_autosalon") == 3)
		return true;

	SetPVarIntNew(playerid, "page_color_autosalon", GetPVarIntNew(playerid, "page_color_autosalon")+1);

	textdraw_generate_color(playerid);
	return true;
}

stock prew_color_page_autosalon(playerid)
{
	if(GetPVarIntNew(playerid, "page_color_autosalon") == 1)
		return true;

	SetPVarIntNew(playerid, "page_color_autosalon", GetPVarIntNew(playerid, "page_color_autosalon")-1);

	textdraw_generate_color(playerid);	
	return true;
}

stock use_sellcar_color(playerid, color_number)
{
	new 
		page = GetPVarIntNew(playerid, "page_color_autosalon"),
		vehicle_id = autosalon_id_buy_car[playerid];

	switch(page)
	{
		case 1:
		{
			switch(color_number)
			{
				case 1: ChangeVehicleColor(vehicle_id, 0, 0),	SetPVarIntNew(playerid, "color_buy_car", 0);
				case 2: ChangeVehicleColor(vehicle_id, 1, 1),	SetPVarIntNew(playerid, "color_buy_car", 1);
				case 3: ChangeVehicleColor(vehicle_id, 3, 3),	SetPVarIntNew(playerid, "color_buy_car", 3);
				case 4: ChangeVehicleColor(vehicle_id, 11, 11),	SetPVarIntNew(playerid, "color_buy_car", 11);
				case 5: ChangeVehicleColor(vehicle_id, 7, 7),	SetPVarIntNew(playerid, "color_buy_car", 7);
				case 6: ChangeVehicleColor(vehicle_id, 6, 6),	SetPVarIntNew(playerid, "color_buy_car", 6);
				case 7: ChangeVehicleColor(vehicle_id, 126, 126),	SetPVarIntNew(playerid, "color_buy_car", 126);
				case 8: ChangeVehicleColor(vehicle_id, 128, 128),	SetPVarIntNew(playerid, "color_buy_car", 128);
			}
		}
		case 2:
		{
			switch(color_number)
			{
				case 1: ChangeVehicleColor(vehicle_id, 144, 144),	SetPVarIntNew(playerid, "color_buy_car", 144);
				case 2: ChangeVehicleColor(vehicle_id, 155, 155),	SetPVarIntNew(playerid, "color_buy_car", 155);
				case 3: ChangeVehicleColor(vehicle_id, 152, 152),	SetPVarIntNew(playerid, "color_buy_car", 152);
				case 4: ChangeVehicleColor(vehicle_id, 200, 200),	SetPVarIntNew(playerid, "color_buy_car", 200);
				case 5: ChangeVehicleColor(vehicle_id, 191, 191),	SetPVarIntNew(playerid, "color_buy_car", 191);
				case 6: ChangeVehicleColor(vehicle_id, 195, 195),	SetPVarIntNew(playerid, "color_buy_car", 195);
				case 7: ChangeVehicleColor(vehicle_id, 15, 15),	SetPVarIntNew(playerid, "color_buy_car", 15);
				case 8: ChangeVehicleColor(vehicle_id, 241, 241),	SetPVarIntNew(playerid, "color_buy_car", 241);	
			}
		}
		case 3:
		{
			switch(color_number)
			{
				case 1: ChangeVehicleColor(vehicle_id, 240, 240),	SetPVarIntNew(playerid, "color_buy_car", 240);	
				case 2: ChangeVehicleColor(vehicle_id, 216, 216),	SetPVarIntNew(playerid, "color_buy_car", 216);	
				case 3: ChangeVehicleColor(vehicle_id, 70, 70),		SetPVarIntNew(playerid, "color_buy_car", 70);	
				case 4: ChangeVehicleColor(vehicle_id, 232, 232),	SetPVarIntNew(playerid, "color_buy_car", 232);	
				case 5: ChangeVehicleColor(vehicle_id, 214, 214),	SetPVarIntNew(playerid, "color_buy_car", 214);	
				case 6: ChangeVehicleColor(vehicle_id, 77, 77),		SetPVarIntNew(playerid, "color_buy_car", 77);	
				case 7: ChangeVehicleColor(vehicle_id, 161, 161),	SetPVarIntNew(playerid, "color_buy_car", 161);	
				case 8: ChangeVehicleColor(vehicle_id, 95, 95),		SetPVarIntNew(playerid, "color_buy_car", 95);	
			}
		}
	}
	return true;
}

stock exit_select_car_autosalon(playerid)
{
	new 
		type = GetPVarIntNew(playerid, "type_autosalon_select_car");

	switch(type)
	{
		case BUISNES_AUTOSALON_1:
		{
			textdraw_autosalon_select(playerid, TEXTDRAW_HIDE, BUISNES_AUTOSALON_1);

			CancelSelectTextDraw(playerid);
			SetCameraBehindPlayer(playerid);

			SetPlayerVirtualWorld(playerid, 10);
			TogglePlayerControllable(playerid, true);
			SetPlayerPosEx(playerid, -188.7571,-6.3118,1202.0325,269.6579);
			ApplyAnimation(playerid,"ped","SEAT_up", 4, 0, 0, 0, 0, 0);
		}
		case BUISNES_AUTOSALON_2:
		{
			textdraw_autosalon_select(playerid, TEXTDRAW_HIDE, BUISNES_AUTOSALON_2);
			SetPlayerVirtualWorld(playerid, 10);

			CancelSelectTextDraw(playerid);
			SetCameraBehindPlayer(playerid);
			TogglePlayerControllable(playerid, true);
			SetPlayerPosEx(playerid, -11.9329,361.5773,1601.7964,182.2733);
			ApplyAnimation(playerid,"ped","SEAT_up", 4, 0, 0, 0, 0, 0);

		}
		case BUISNES_AUTOSALON_3:
		{
			textdraw_autosalon_select(playerid, TEXTDRAW_HIDE, BUISNES_AUTOSALON_3);
			SetPlayerVirtualWorld(playerid, 10);

			CancelSelectTextDraw(playerid);
			SetCameraBehindPlayer(playerid);
			TogglePlayerControllable(playerid, true);
			SetPlayerPosEx(playerid, -8.4212,-690.8147,1201.9474,220.4564);
			ApplyAnimation(playerid,"ped","SEAT_up", 4, 0, 0, 0, 0, 0);

		}
	}

	new 
		vehicle_id = autosalon_id_buy_car[playerid];
	DestroyVehicle(vehicle_id);	

	TogglePlayerAllHudElements(playerid, HUD_ELEMENT_SHOW);
	clear_pvar_select_auto(playerid);
	return true;
}


stock clear_pvar_select_auto(playerid)
{

	DeletePVarNew(playerid, "type_autosalon_select_car");
	DeletePVarNew(playerid, "pos_camera_autosalon");
	DeletePVarNew(playerid, "page_color_autosalon");
	DeletePVarNew(playerid, "color_buy_car");

	autosalon_id_buy_car[playerid] = 0;
	autosalon_select_count[playerid] = 0;

	return true;
}

stock select_buy_car_autosalon(playerid)
{
	if(pData[playerid][pFamily] != -1 && pData[playerid][pFamilyRank] == 7)
	{
		return SPD(playerid, DIALOG_SELECT_TYPE_BUY_CAR, DIALOG_STYLE_LIST, !""cBLUE"Выбор покупки авто", "\
		"cBLUE"1. "cWH"Покупка в личное владение\n\
		"cBLUE"2. "cWH"Покупка для семьи", !"Выбрать", !"Закрыть");
	}
	else
	{
		buy_car_autosalon(playerid);
	}

	return true;
}

stock buy_autosalon_family_car(playerid)
{
	new 
		color_car = GetPVarIntNew(playerid, "color_buy_car"),
		autosalon_car = GetPVarIntNew(playerid, "type_autosalon_select_car");

	new 
		vehicle_id = autosalon_id_buy_car[playerid];

	buy_family_car(playerid, autosalon_car, GetVehicleModel(vehicle_id), color_car, color_car, transport_config[GetVehicleModel(vehicle_id)-400][transport_price]);

	return true;
}

stock buy_car_autosalon(playerid)
{	
	static
		fmt_str[500];

	SetTimeoutChatDissappearTime(playerid, 500, 1500);
	
	if(pData[playerid][pHotelRoom] == -1 && pData[playerid][pFlate] == -1  && pData[playerid][pFlateRent] == -1 && pData[playerid][pHouse] == -1 && pData[playerid][pHouseRent] == -1)
	{
 		exit_select_car_autosalon(playerid);
		return SendErr(playerid, "У вас нету дома/квартиры!");
	}
	
	if(!pData[playerid][pLicenses][LIC_DRIVING])
 	{
	 	exit_select_car_autosalon(playerid);
		return SendErr(playerid, "У вас нет лицензии на управление транспортом!");
		
	}

	format(fmt_str, sizeof(fmt_str), "SELECT * FROM player_vehicles WHERE owner = '%s' LIMIT 8", GetNameEx(playerid));
	new Result:carfind = sql_queryEx(zConn, fmt_str, QUERY_CACHED);

	new all_vehicle_player = sql_num_rows(carfind);

	if(vehicle_player_max_user[playerid] == 1 && all_vehicle_player >= 1)
	{
	    exit_select_car_autosalon(playerid);
		return SendErr(playerid, "У Вас уже имеется автомобиль, рассширение количества слотов доступно только через гараж!");
	}
	if(vehicle_player_max_user[playerid] == 2 && all_vehicle_player >= 2)
	{
	    exit_select_car_autosalon(playerid);
		return SendErr(playerid, "У Вас уже имеется 2 автомобиля, рассширение количества слотов доступно только через гараж!");
	}
	if(vehicle_player_max_user[playerid] == 4 && all_vehicle_player >= 4)
	{
	    exit_select_car_autosalon(playerid);
		return SendErr(playerid, "У Вас уже имеется 4 автомобиля, рассширение количества слотов доступно только через гараж!");
	}
	if(vehicle_player_max_user[playerid] == 8 && all_vehicle_player >= 8)
  	{
  	    exit_select_car_autosalon(playerid);
		return SendErr(playerid, "У Вас уже имеется 8 автомобилей, рассширение количества слотов доступно только через гараж!");
	}

	sql_free_result(carfind);

	new b_id = GetPVarIntNew(playerid, "buisnes_enter_id"), b_type = GetPVarIntNew(playerid, "buisnes_enter_type");
	if(pData[playerid][pHouse] == -1 && pData[playerid][pFlate] == -1 && pData[playerid][pGarage] == -1 && pData[playerid][pHotelRoom] != -1
	|| pData[playerid][pHouse] == -1 && pData[playerid][pFlate] == -1 && pData[playerid][pGarage] != -1 && pData[playerid][pHotelRoom] == -1
	|| pData[playerid][pHouse] == -1 && pData[playerid][pFlate] != -1 && pData[playerid][pGarage] == -1 && pData[playerid][pHotelRoom] == -1
	|| pData[playerid][pHouse] != -1 && pData[playerid][pFlate] == -1 && pData[playerid][pGarage] == -1 && pData[playerid][pHotelRoom] == -1
	|| pData[playerid][pHouse] == -1 && pData[playerid][pFlate] == -1 && pData[playerid][pGarage] == -1 && pData[playerid][pHotelRoom] == -1 && pData[playerid][pFlateRent] == -1 && pData[playerid][pHouseRent] != -1
	|| pData[playerid][pHouse] == -1 && pData[playerid][pFlate] == -1 && pData[playerid][pGarage] == -1 && pData[playerid][pHotelRoom] == -1 && pData[playerid][pFlateRent] != -1 && pData[playerid][pHouseRent] == -1)
	{
		new 
			color_car = GetPVarIntNew(playerid, "color_buy_car"),
			autosalon_car = GetPVarIntNew(playerid, "type_autosalon_select_car"),
			fmt_str[200];

		new 
			vehicle_id = autosalon_id_buy_car[playerid];

		SetTimeoutChatDissappearTime(playerid, 500, 1500);

		if(GetPlayerMoneyEx(playerid) <  transport_config[GetVehicleModel(vehicle_id)-400][transport_price])
		{
			show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_21", 2500);
			return SendErr(playerid, "У вас недостаточно денежных средств для покупки данного транспорта!");
		}

		if(autosalon_car == BUISNES_AUTOSALON_1)
		{	
			SetTimeoutChatDissappearTime(playerid, 500, 1500);

			if(autosalon_transport_config[0][autosalon_car_count][autosalon_select_count[playerid]] == 0)
				return SendErr(playerid, "В данный момент, модель автомобиля отсутствует в автосалоне!");

			autosalon_transport_config[0][autosalon_car_count][autosalon_select_count[playerid]]--;

			give_money(playerid, -transport_config[GetVehicleModel(vehicle_id)-400][transport_price] ,"Приобретение автомобиля в Арзамас Карс");
			if(b_type == BUISNES_AUTOSALON_1) buisness_bank_update(b_id, floatround(transport_config[GetVehicleModel(vehicle_id)-400][transport_price]*0.6), "Приобретение автомобиля в Арзамас Карс");

			new 
				random_pos = random(5);

			if(pData[playerid][pHouse] != -1 && pData[playerid][pHotelRoom] == -1 && pData[playerid][pGarage] == -1)
			{

				new 
					id_house = pData[playerid][pHouse];

				new query[220];
				format(query,sizeof(query),"INSERT INTO `player_vehicles`(`owner`,`model`,`color_1`,`color_2`,`parking_x`,`parking_y`,`parking_z`,`parking_a`) VALUES ('%s','%d','%d','%d','%f','%f','%f','%f')", GetNameEx(playerid), GetVehicleModel(autosalon_id_buy_car[playerid]), 
				color_car, color_car, House[id_house][house_park_x], House[id_house][house_park_y], House[id_house][house_park_z], House[id_house][house_park_a]);
				sql_queryEx(zConn, query, QUERY_THREADED);

				SCM(playerid, -1, "");
				SendSucc(playerid, "Вы купили автомобиль в автосалоне «Арзамас Карс»");
				format(fmt_str, sizeof(fmt_str), "Вы приобрели %s за "cGR"%d рублей"cWH"! Поздравляем Вас с покупкой!", transport_config[GetVehicleModel(vehicle_id)-400][transport_name], transport_config[GetVehicleModel(vehicle_id)-400][transport_price]);
				SendInf(playerid, fmt_str);
				SendSucc(playerid, "Автомобиль припаркован возле автосалона используйте - /unpark, чтобы забрать его!");
				SendInf(playerid, "Чтобы перепарковать автомобиль, используйте - /park и автомобиль будет появляться на новом месте!");

				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_buy_car", 4000);

				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка автомобиля", !"\
				"cWH"Поздравляем Вас с приобретением автомобиля!\n\n\
				Автомобиль находится возле автосалона!\n\
				"cBLUE"-"cWH" Отпарковать автомобиль: /unpark\n\
				"cBLUE"-"cWH" Припарковать автомобиль: /park\
				"cBLUE"-"cWH" Найти автомобиль: /findcar\n\n\
				Автомобиль находится на парковке автосалона!\n\
				Чтобы забрать его, используйте команду - /cars", !"Далее", "Нет");	

			}
			
			else if(pData[playerid][pGarage] != -1 && pData[playerid][pHouse] == -1 && pData[playerid][pHotelRoom] == -1)
			{

				new 
					id_garage = pData[playerid][pGarage];

				new query[220];
				format(query,sizeof(query),"INSERT INTO `player_vehicles`(`owner`,`model`,`color_1`,`color_2`, `parking_x`,`parking_y`,`parking_z`,`parking_a`, `parking_vw`, `parking_garage`) VALUES ('%s','%d','%d','%d','%f','%f','%f','%f')", GetNameEx(playerid), GetVehicleModel(autosalon_id_buy_car[playerid]), 
				color_car, color_car, -1029.4253,-2615.9031,18.3268,359.1430, id_garage, 1);
				sql_queryEx(zConn, query, QUERY_THREADED);	

				SCM(playerid, -1, "");
				SendSucc(playerid, "Вы купили автомобиль в автосалоне «Арзамас Карс»");
				format(fmt_str, sizeof(fmt_str), "Вы приобрели %s за "cGR"%d рублей"cWH"! Поздравляем Вас с покупкой!", transport_config[GetVehicleModel(vehicle_id)-400][transport_name], transport_config[GetVehicleModel(vehicle_id)-400][transport_price]);
				SendInf(playerid, fmt_str);
				SendSucc(playerid, "Автомобиль припаркован в Вашем гараже, используйте - /unpark, чтобы забрать его!");
				SendInf(playerid, "Чтобы перепарковать автомобиль, используйте - /park и автомобиль будет появляться на новом месте!");

				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_buy_car", 4000);

				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка автомобиля", !"\
				"cWH"Поздравляем Вас с приобретением автомобиля!\n\n\
				Автомобиль находится в Вашем гараже!\n\
				"cBLUE"-"cWH" Отпарковать автомобиль: /unpark\n\
				"cBLUE"-"cWH" Припарковать автомобиль: /park\
				"cBLUE"-"cWH" Найти автомобиль: /findcar\n\n\
				Автомобиль находится на парковке автосалона!\n\
				Чтобы забрать его, используйте команду - /cars", !"Далее", "Нет");		


			}

			else if(pData[playerid][pGarage] == -1 && pData[playerid][pHouse] == -1 && pData[playerid][pHotelRoom] != -1)
			{
				new 
					hotel_room_id = pData[playerid][pHotelRoom];


				if(hotel_room[hotel_room_id][hotel_h_id] == 0)
				{
					random_pos = random(29);

					new query[220];
					format(query,sizeof(query),"INSERT INTO `player_vehicles`(`owner`,`model`,`color_1`,`color_2`,`parking_x`,`parking_y`,`parking_z`,`parking_a`) VALUES ('%s','%d','%d','%d','%f','%f','%f','%f')", GetNameEx(playerid), GetVehicleModel(autosalon_id_buy_car[playerid]), 
					color_car, color_car, position_spawn_hotel_1[random_pos][0], position_spawn_hotel_1[random_pos][1], position_spawn_hotel_1[random_pos][2], position_spawn_hotel_1[random_pos][3]);
					sql_queryEx(zConn, query, QUERY_THREADED);

				}
				else if(hotel_room[hotel_room_id][hotel_h_id] == 1)
				{

					random_pos = random(30);

					new query[220];
					format(query,sizeof(query),"INSERT INTO `player_vehicles`(`owner`,`model`,`color_1`,`color_2`,`parking_x`,`parking_y`,`parking_z`,`parking_a`) VALUES ('%s','%d','%d','%d','%f','%f','%f','%f')", GetNameEx(playerid), GetVehicleModel(autosalon_id_buy_car[playerid]), 
					color_car, color_car, position_spawn_hotel_2[random_pos][0], position_spawn_hotel_2[random_pos][1], position_spawn_hotel_2[random_pos][2], position_spawn_hotel_2[random_pos][3]);
					sql_queryEx(zConn, query, QUERY_THREADED);

				}
				else if(hotel_room[hotel_room_id][hotel_h_id] == 2)
				{

					random_pos = random(30);

					new query[220];
					format(query,sizeof(query),"INSERT INTO `player_vehicles`(`owner`,`model`,`color_1`,`color_2`,`parking_x`,`parking_y`,`parking_z`,`parking_a`) VALUES ('%s','%d','%d','%d','%f','%f','%f','%f')", GetNameEx(playerid), GetVehicleModel(autosalon_id_buy_car[playerid]), 
					color_car, color_car, position_spawn_hotel_3[random_pos][0], position_spawn_hotel_3[random_pos][1], position_spawn_hotel_3[random_pos][2], position_spawn_hotel_3[random_pos][3]);
					sql_queryEx(zConn, query, QUERY_THREADED);

				}
				else if(hotel_room[hotel_room_id][hotel_h_id] == 3)
				{
					random_pos = random(20);

					new query[220];
					format(query,sizeof(query),"INSERT INTO `player_vehicles`(`owner`,`model`,`color_1`,`color_2`,`parking_x`,`parking_y`,`parking_z`,`parking_a`) VALUES ('%s','%d','%d','%d','%f','%f','%f','%f')", GetNameEx(playerid), GetVehicleModel(autosalon_id_buy_car[playerid]), 
					color_car, color_car, position_spawn_hotel_4[random_pos][0], position_spawn_hotel_4[random_pos][1], position_spawn_hotel_4[random_pos][2], position_spawn_hotel_4[random_pos][3]);
					sql_queryEx(zConn, query, QUERY_THREADED);

				}

				SCM(playerid, -1, "");
				SendSucc(playerid, "Вы купили автомобиль в автосалоне «Арзамас Карс»");
				format(fmt_str, sizeof(fmt_str), "Вы приобрели %s за "cGR"%d рублей"cWH"! Поздравляем Вас с покупкой!", transport_config[GetVehicleModel(vehicle_id)-400][transport_name], transport_config[GetVehicleModel(vehicle_id)-400][transport_price]);
				SendInf(playerid, fmt_str);
				SendSucc(playerid, "Автомобиль припаркован на парковке отеля, используйте - /unpark, чтобы забрать его!");
				SendInf(playerid, "Чтобы перепарковать автомобиль, используйте - /park и автомобиль будет появляться на новом месте!");

				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_buy_car", 4000);

				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка автомобиля", !"\
				"cWH"Поздравляем Вас с приобретением автомобиля!\n\n\
				Автомобиль находится на парковке отеля!\n\
				"cBLUE"-"cWH" Отпарковать автомобиль: /unpark\n\
				"cBLUE"-"cWH" Припарковать автомобиль: /park\
				"cBLUE"-"cWH" Найти автомобиль: /findcar\n\n\
				Автомобиль находится на парковке автосалона!\n\
				Чтобы забрать его, используйте команду - /cars", !"Далее", "Нет");		

			}

			else 
			{
				random_pos = random(25);

				new query[220];
				format(query,sizeof(query),"INSERT INTO `player_vehicles`(`owner`,`model`,`color_1`,`color_2`,`parking_x`,`parking_y`,`parking_z`,`parking_a`) VALUES ('%s','%d','%d','%d','%f','%f','%f','%f')", GetNameEx(playerid), GetVehicleModel(autosalon_id_buy_car[playerid]), 
				color_car, color_car, position_spawn_autosalon_1[random_pos][0], position_spawn_autosalon_1[random_pos][1], position_spawn_autosalon_1[random_pos][2], position_spawn_autosalon_1[random_pos][3]);
				sql_queryEx(zConn, query, QUERY_THREADED);

				SCM(playerid, -1, "");
				SendSucc(playerid, "Вы купили автомобиль в автосалоне «Арзамас Карс»");
				format(fmt_str, sizeof(fmt_str), "Вы приобрели %s за "cGR"%d рублей"cWH"! Поздравляем Вас с покупкой!", transport_config[GetVehicleModel(vehicle_id)-400][transport_name], transport_config[GetVehicleModel(vehicle_id)-400][transport_price]);
				SendInf(playerid, fmt_str);
				SendSucc(playerid, "Автомобиль припаркован на парковке автосалона, используйте - /unpark, чтобы забрать его!");
				SendInf(playerid, "Чтобы перепарковать автомобиль, используйте - /park и автомобиль будет появляться на новом месте!");

				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_buy_car", 4000);

				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка автомобиля", !"\
				"cWH"Поздравляем Вас с приобретением автомобиля!\n\n\
				Автомобиль находится на парковке автосалона!\n\
				"cBLUE"-"cWH" Отпарковать автомобиль: /unpark\n\
				"cBLUE"-"cWH" Припарковать автомобиль: /park\
				"cBLUE"-"cWH" Найти автомобиль: /findcar\n\n\
				Автомобиль находится на парковке автосалона!\n\
				Чтобы забрать его, используйте команду - /cars", !"Далее", "Нет");
			}

			new query[256];
			format(query,sizeof(query),"UPDATE `transport_autosalon` SET autosalon_car_count_%d = '%d' WHERE `autosalon_config_id` = '0'", autosalon_select_count[playerid]+1, autosalon_transport_config[0][autosalon_car_count][autosalon_select_count[playerid]]);
			sql_queryEx(zConn, query, QUERY_THREADED);	

			DestroyVehicle(vehicle_id);		

		}
		else if(autosalon_car == BUISNES_AUTOSALON_2)
		{
			SetTimeoutChatDissappearTime(playerid, 500, 1500);
			if(autosalon_transport_config[1][autosalon_car_count][autosalon_select_count[playerid]] == 0)
				return SendErr(playerid, "В данный момент, модель автомобиля отсутствует в автосалоне!");

			autosalon_transport_config[1][autosalon_car_count][autosalon_select_count[playerid]]--;

			give_money(playerid, -transport_config[GetVehicleModel(vehicle_id)-400][transport_price] ,"Приобретение автомобиля в «АвтоХаус»");
			if(b_type == BUISNES_AUTOSALON_2) buisness_bank_update(b_id, floatround(transport_config[GetVehicleModel(vehicle_id)-400][transport_price]*0.6), "Приобретение автомобиля в «АвтоХаус»");

			new 
				random_pos = random(5);

			if(pData[playerid][pHouse] != -1 && pData[playerid][pHotelRoom] == -1 && pData[playerid][pGarage] == -1)
			{

				new 
					id_house = pData[playerid][pHouse];
				
				new query[220];
				format(query,sizeof(query),"INSERT INTO `player_vehicles`(`owner`,`model`,`color_1`,`color_2`,`parking_x`,`parking_y`,`parking_z`,`parking_a`) VALUES ('%s','%d','%d','%d','%f','%f','%f','%f')", GetNameEx(playerid), GetVehicleModel(autosalon_id_buy_car[playerid]), 
				color_car, color_car, House[id_house][house_park_x], House[id_house][house_park_y], House[id_house][house_park_z], House[id_house][house_park_a]);
				sql_queryEx(zConn, query, QUERY_THREADED);

				SCM(playerid, -1, "");
				SendSucc(playerid, "Вы купили автомобиль в автосалоне «Арзамас Карс»");
				format(fmt_str, sizeof(fmt_str), "Вы приобрели %s за "cGR"%d рублей"cWH"! Поздравляем Вас с покупкой!", transport_config[GetVehicleModel(vehicle_id)-400][transport_name], transport_config[GetVehicleModel(vehicle_id)-400][transport_price]);
				SendInf(playerid, fmt_str);
				SendSucc(playerid, "Автомобиль припаркован возле Вашего дома, используйте - /unpark, чтобы забрать его!");
				SendInf(playerid, "Чтобы перепарковать автомобиль, используйте - /park и автомобиль будет появляться на новом месте!");

				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_buy_car", 4000);

				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка автомобиля", !"\
				"cWH"Поздравляем Вас с приобретением автомобиля!\n\n\
				Автомобиль находится возле Вашего дома!\n\
				"cBLUE"-"cWH" Отпарковать автомобиль: /unpark\n\
				"cBLUE"-"cWH" Припарковать автомобиль: /park\
				"cBLUE"-"cWH" Найти автомобиль: /findcar\n\n\
				Автомобиль находится на парковке автосалона!\n\
				Чтобы забрать его, используйте команду - /cars", !"Далее", "Нет");	

			}
			
			else if(pData[playerid][pGarage] != -1 && pData[playerid][pHouse] == -1 && pData[playerid][pHotelRoom] == -1)
			{
				new 
					id_garage = pData[playerid][pGarage];
		
				new query[220];
				format(query,sizeof(query),"INSERT INTO `player_vehicles`(`owner`,`model`,`color_1`,`color_2`, `parking_x`,`parking_y`,`parking_z`,`parking_a`, `parking_vw`, `parking_garage`) VALUES ('%s','%d','%d','%d','%f','%f','%f','%f','%d','%d')", GetNameEx(playerid), GetVehicleModel(autosalon_id_buy_car[playerid]), 
				color_car, color_car, -1029.4253,-2615.9031,18.3268,359.1430, id_garage, 1);
				sql_queryEx(zConn, query, QUERY_THREADED);	

				SCM(playerid, -1, "");
				SendSucc(playerid, "Вы купили автомобиль в автосалоне «Арзамас Карс»");
				format(fmt_str, sizeof(fmt_str), "Вы приобрели %s за "cGR"%d рублей"cWH"! Поздравляем Вас с покупкой!", transport_config[GetVehicleModel(vehicle_id)-400][transport_name], transport_config[GetVehicleModel(vehicle_id)-400][transport_price]);
				SendInf(playerid, fmt_str);
				SendSucc(playerid, "Автомобиль припаркован в Вашем гараже, используйте - /unpark, чтобы забрать его!");
				SendInf(playerid, "Чтобы перепарковать автомобиль, используйте - /park и автомобиль будет появляться на новом месте!");

				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_buy_car", 4000);

				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка автомобиля", !"\
				"cWH"Поздравляем Вас с приобретением автомобиля!\n\n\
				Автомобиль находится в Вашем гараже!\n\
				"cBLUE"-"cWH" Отпарковать автомобиль: /unpark\n\
				"cBLUE"-"cWH" Припарковать автомобиль: /park\
				"cBLUE"-"cWH" Найти автомобиль: /findcar\n\n\
				Автомобиль находится на парковке автосалона!\n\
				Чтобы забрать его, используйте команду - /cars", !"Далее", "Нет");		


			}

			else if(pData[playerid][pGarage] != -1 && pData[playerid][pHouse] == -1 && pData[playerid][pHotelRoom] != -1)
			{
				new 
					hotel_room_id = pData[playerid][pHotelRoom];


				if(hotel_room[hotel_room_id][hotel_h_id] == 0)
				{
					random_pos = random(5);

					new query[220];
					format(String1024,sizeof(String1024),"INSERT INTO `player_vehicles`(`owner`,`model`,`color_1`,`color_2`,`parking_x`,`parking_y`,`parking_z`,`parking_a`) VALUES ('%s','%d','%d','%d','%f','%f','%f','%f')", GetNameEx(playerid), GetVehicleModel(autosalon_id_buy_car[playerid]), 
					color_car, color_car, position_spawn_hotel_1[random_pos][0], position_spawn_hotel_1[random_pos][1], position_spawn_hotel_1[random_pos][2], position_spawn_hotel_1[random_pos][3]);
					sql_queryEx(zConn, String1024, QUERY_THREADED);

				}
				else if(hotel_room[hotel_room_id][hotel_h_id] == 1)
				{

					random_pos = random(5);
					
					new query[220];
					format(query,sizeof(query),"INSERT INTO `player_vehicles`(`owner`,`model`,`color_1`,`color_2`,`parking_x`,`parking_y`,`parking_z`,`parking_a`) VALUES ('%s','%d','%d','%d','%f','%f','%f','%f')", GetNameEx(playerid), GetVehicleModel(autosalon_id_buy_car[playerid]), 
					color_car, color_car, position_spawn_hotel_2[random_pos][0], position_spawn_hotel_2[random_pos][1], position_spawn_hotel_2[random_pos][2], position_spawn_hotel_2[random_pos][3]);
					sql_queryEx(zConn, query, QUERY_THREADED);

				}
				else if(hotel_room[hotel_room_id][hotel_h_id] == 2)
				{

					random_pos = random(4);

					new query[220];
					format(query,sizeof(query),"INSERT INTO `player_vehicles`(`owner`,`model`,`color_1`,`color_2`,`parking_x`,`parking_y`,`parking_z`,`parking_a`) VALUES ('%s','%d','%d','%d','%f','%f','%f','%f')", GetNameEx(playerid), GetVehicleModel(autosalon_id_buy_car[playerid]), 
					color_car, color_car, position_spawn_hotel_3[random_pos][0], position_spawn_hotel_3[random_pos][1], position_spawn_hotel_3[random_pos][2], position_spawn_hotel_3[random_pos][3]);
					sql_queryEx(zConn, query, QUERY_THREADED);

				}
				else if(hotel_room[hotel_room_id][hotel_h_id] == 3)
				{
					random_pos = random(5);

					new query[220];
					format(query,sizeof(query),"INSERT INTO `player_vehicles`(`owner`,`model`,`color_1`,`color_2`,`parking_x`,`parking_y`,`parking_z`,`parking_a`) VALUES ('%s','%d','%d','%d','%f','%f','%f','%f')", GetNameEx(playerid), GetVehicleModel(autosalon_id_buy_car[playerid]), 
					color_car, color_car, position_spawn_hotel_4[random_pos][0], position_spawn_hotel_4[random_pos][1], position_spawn_hotel_4[random_pos][2], position_spawn_hotel_4[random_pos][3]);
					sql_queryEx(zConn, query, QUERY_THREADED);

				}

				SCM(playerid, -1, "");
				SendSucc(playerid, "Вы купили автомобиль в автосалоне «Арзамас Карс»");
				format(fmt_str, sizeof(fmt_str), "Вы приобрели %s за "cGR"%d рублей"cWH"! Поздравляем Вас с покупкой!", transport_config[GetVehicleModel(vehicle_id)-400][transport_name], transport_config[GetVehicleModel(vehicle_id)-400][transport_price]);
				SendInf(playerid, fmt_str);
				SendSucc(playerid, "Автомобиль припаркован на парковке отеля, используйте - /unpark, чтобы забрать его!");
				SendInf(playerid, "Чтобы перепарковать автомобиль, используйте - /park и автомобиль будет появляться на новом месте!");

				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_buy_car", 4000);

				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка автомобиля", !"\
				"cWH"Поздравляем Вас с приобретением автомобиля!\n\n\
				Автомобиль находится на парковке отеля!\n\
				"cBLUE"-"cWH" Отпарковать автомобиль: /unpark\n\
				"cBLUE"-"cWH" Припарковать автомобиль: /park\
				"cBLUE"-"cWH" Найти автомобиль: /findcar\n\n\
				Автомобиль находится на парковке автосалона!\n\
				Чтобы забрать его, используйте команду - /cars", !"Далее", "Нет");		

			}

			else
			{
				random_pos = random(30);

				new query[220];
				format(query,sizeof(query),"INSERT INTO `player_vehicles`(`owner`,`model`,`color_1`,`color_2`,`parking_x`,`parking_y`,`parking_z`,`parking_a`) VALUES ('%s','%d','%d','%d','%f','%f','%f','%f')", GetNameEx(playerid), GetVehicleModel(autosalon_id_buy_car[playerid]), 
				color_car, color_car, position_spawn_autosalon_2[random_pos][0], position_spawn_autosalon_2[random_pos][1], position_spawn_autosalon_2[random_pos][2], position_spawn_autosalon_2[random_pos][3]);
				sql_queryEx(zConn, query, QUERY_THREADED);		


				SCM(playerid, -1, "");
				SendSucc(playerid, "Вы купили автомобиль в автосалоне «Арзамас Карс»");
				format(fmt_str, sizeof(fmt_str), "Вы приобрели %s за "cGR"%d рублей"cWH"! Поздравляем Вас с покупкой!", transport_config[GetVehicleModel(vehicle_id)-400][transport_name], transport_config[GetVehicleModel(vehicle_id)-400][transport_price]);
				SendInf(playerid, fmt_str);
				SendSucc(playerid, "Автомобиль припаркован на парковке автосалона, используйте - /unpark, чтобы забрать его!");
				SendInf(playerid, "Чтобы перепарковать автомобиль, используйте - /park и автомобиль будет появляться на новом месте!");

				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_buy_car", 4000);

				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка автомобиля", !"\
				"cWH"Поздравляем Вас с приобретением автомобиля!\n\n\
				Автомобиль находится на парковке автосалона!\n\
				"cBLUE"-"cWH" Отпарковать автомобиль: /unpark\n\
				"cBLUE"-"cWH" Припарковать автомобиль: /park\
				"cBLUE"-"cWH" Найти автомобиль: /findcar\n\n\
				Автомобиль находится на парковке автосалона!\n\
				Чтобы забрать его, используйте команду - /cars", !"Далее", "Нет");		
				
			}

			new query[256];
			format(query,sizeof(query),"UPDATE `transport_autosalon` SET autosalon_car_count_%d = '%d' WHERE `autosalon_config_id` = '1'", autosalon_select_count[playerid]+1, autosalon_transport_config[1][autosalon_car_count][autosalon_select_count[playerid]]);
			sql_queryEx(zConn, query, QUERY_THREADED);	

			DestroyVehicle(vehicle_id);		

		}
		else if(autosalon_car == BUISNES_AUTOSALON_3)
		{
			SetTimeoutChatDissappearTime(playerid, 500, 1500);
			if(autosalon_transport_config[2][autosalon_car_count][autosalon_select_count[playerid]] == 0)
				return SendErr(playerid, "В данный момент, модель автомобиля отсутствует в автосалоне!");

			autosalon_transport_config[2][autosalon_car_count][autosalon_select_count[playerid]]--;

			give_money(playerid, -transport_config[GetVehicleModel(vehicle_id)-400][transport_price] ,"Приобретение автомобиля в «АвтодВОР»");
			if(b_type == BUISNES_AUTOSALON_3) buisness_bank_update(b_id, floatround(transport_config[GetVehicleModel(vehicle_id)-400][transport_price]*0.6), "Приобретение автомобиля в Арзамас Карс");

			new 
				random_pos = random(5);

			if(pData[playerid][pHouse] != -1 && pData[playerid][pHotelRoom] == -1 && pData[playerid][pGarage] == -1)
			{

				new 
					id_house = pData[playerid][pHouse];

				new query[220];
				format(query,sizeof(query),"INSERT INTO `player_vehicles`(`owner`,`model`,`color_1`,`color_2`,`parking_x`,`parking_y`,`parking_z`,`parking_a`) VALUES ('%s','%d','%d','%d','%f','%f','%f','%f')", GetNameEx(playerid), GetVehicleModel(autosalon_id_buy_car[playerid]), color_car, color_car, House[id_house][house_park_x], House[id_house][house_park_y], House[id_house][house_park_z], House[id_house][house_park_a]);
				sql_queryEx(zConn, query, QUERY_THREADED);

				SCM(playerid, -1, "");
				SendSucc(playerid, "Вы купили автомобиль в автосалоне «Арзамас Карс»");
				format(fmt_str, sizeof(fmt_str), "Вы приобрели %s за "cGR"%d рублей"cWH"! Поздравляем Вас с покупкой!", transport_config[GetVehicleModel(vehicle_id)-400][transport_name], transport_config[GetVehicleModel(vehicle_id)-400][transport_price]);
				SendInf(playerid, fmt_str);
				SendSucc(playerid, "Автомобиль припаркован возле Вашего дома, используйте - /unpark, чтобы забрать его!");
				SendInf(playerid, "Чтобы перепарковать автомобиль, используйте - /park и автомобиль будет появляться на новом месте!");

				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_buy_car", 4000);

				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка автомобиля", !"\
				"cWH"Поздравляем Вас с приобретением автомобиля!\n\n\
				Автомобиль находится возле Вашего дома!\n\
				"cBLUE"-"cWH" Отпарковать автомобиль: /unpark\n\
				"cBLUE"-"cWH" Припарковать автомобиль: /park\
				"cBLUE"-"cWH" Найти автомобиль: /findcar\n\n\
				Автомобиль находится на парковке автосалона!\n\
				Чтобы забрать его, используйте команду - /cars", !"Далее", "Нет");	

			}
			
			else if(pData[playerid][pGarage] != -1 && pData[playerid][pHouse] == -1 && pData[playerid][pHotelRoom] == -1)
			{

				new 
					id_garage = pData[playerid][pGarage];
				
				new query[220];
				format(query,sizeof(query),"INSERT INTO `player_vehicles`(`owner`,`model`,`color_1`,`color_2`,`parking_x`,`parking_y`,`parking_z`,`parking_a`,`parking_vw`,`parking_garage`) VALUES ('%s','%d','%d','%d','%f','%f','%f','%f')", GetNameEx(playerid), GetVehicleModel(autosalon_id_buy_car[playerid]), color_car, color_car, -1029.4253,-2615.9031,18.3268,359.1430, id_garage, 1);
				sql_queryEx(zConn, query, QUERY_THREADED);

				SCM(playerid, -1, "");
				SendSucc(playerid, "Вы купили автомобиль в автосалоне «Арзамас Карс»");
				format(fmt_str, sizeof(fmt_str), "Вы приобрели %s за "cGR"%d рублей"cWH"! Поздравляем Вас с покупкой!", transport_config[GetVehicleModel(vehicle_id)-400][transport_name], transport_config[GetVehicleModel(vehicle_id)-400][transport_price]);
				SendInf(playerid, fmt_str);
				SendSucc(playerid, "Автомобиль припаркован в Вашем гараже, используйте - /unpark, чтобы забрать его!");
				SendInf(playerid, "Чтобы перепарковать автомобиль, используйте - /park и автомобиль будет появляться на новом месте!");

				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_buy_car", 4000);

				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка автомобиля", !"\
				"cWH"Поздравляем Вас с приобретением автомобиля!\n\n\
				Автомобиль находится в Вашем гараже!\n\
				"cBLUE"-"cWH" Отпарковать автомобиль: /unpark\n\
				"cBLUE"-"cWH" Припарковать автомобиль: /park\
				"cBLUE"-"cWH" Найти автомобиль: /findcar\n\n\
				Автомобиль находится на парковке автосалона!\n\
				Чтобы забрать его, используйте команду - /cars", !"Далее", "Нет");		
			}

			else if(pData[playerid][pGarage] != -1 && pData[playerid][pHouse] == -1 && pData[playerid][pHotelRoom] != -1)
			{
				new 
					hotel_room_id = pData[playerid][pHotelRoom];

				if(hotel_room[hotel_room_id][hotel_h_id] == 0)
				{
					random_pos = random(5);

					new query[220];
					format(query,sizeof(query),"INSERT INTO `player_vehicles`(`owner`,`model`,`color_1`,`color_2`,`parking_x`,`parking_y`,`parking_z`,`parking_a`) VALUES ('%s','%d','%d','%d','%f','%f','%f','%f')", GetNameEx(playerid), GetVehicleModel(autosalon_id_buy_car[playerid]), color_car, color_car, position_spawn_hotel_1[random_pos][0], position_spawn_hotel_1[random_pos][1], position_spawn_hotel_1[random_pos][2], position_spawn_hotel_1[random_pos][3]);
					sql_queryEx(zConn, query, QUERY_THREADED);
				}
				else if(hotel_room[hotel_room_id][hotel_h_id] == 1)
				{

					random_pos = random(5);

					new query[220];
					format(query,sizeof(query),"INSERT INTO `player_vehicles`(`owner`,`model`,`color_1`,`color_2`,`parking_x`,`parking_y`,`parking_z`,`parking_a`) VALUES ('%s','%d','%d','%d','%f','%f','%f','%f')", GetNameEx(playerid), GetVehicleModel(autosalon_id_buy_car[playerid]), color_car, color_car, position_spawn_hotel_2[random_pos][0], position_spawn_hotel_2[random_pos][1], position_spawn_hotel_2[random_pos][2], position_spawn_hotel_2[random_pos][3]);
					sql_queryEx(zConn, query, QUERY_THREADED);

				}
				else if(hotel_room[hotel_room_id][hotel_h_id] == 2)
				{

					random_pos = random(4);

					new query[220];
					format(query,sizeof(query),"INSERT INTO `player_vehicles`(`owner`,`model`,`color_1`,`color_2`,`parking_x`,`parking_y`,`parking_z`,`parking_a`) VALUES ('%s','%d','%d','%d','%f','%f','%f','%f')", GetNameEx(playerid), GetVehicleModel(autosalon_id_buy_car[playerid]), color_car, color_car, position_spawn_hotel_3[random_pos][0], position_spawn_hotel_3[random_pos][1], position_spawn_hotel_3[random_pos][2], position_spawn_hotel_3[random_pos][3]);
					sql_queryEx(zConn, query, QUERY_THREADED);

				}
				else if(hotel_room[hotel_room_id][hotel_h_id] == 3)
				{
					random_pos = random(5);

					new query[220];
					format(query,sizeof(query),"INSERT INTO `player_vehicles`(`owner`,`model`,`color_1`,`color_2`,`parking_x`,`parking_y`,`parking_z`,`parking_a`) VALUES ('%s','%d','%d','%d','%f','%f','%f','%f')", GetNameEx(playerid), GetVehicleModel(autosalon_id_buy_car[playerid]), color_car, color_car, position_spawn_hotel_4[random_pos][0], position_spawn_hotel_4[random_pos][1], position_spawn_hotel_4[random_pos][2], position_spawn_hotel_4[random_pos][3]);
					sql_queryEx(zConn, query, QUERY_THREADED);
				}

				SCM(playerid, -1, "");
				SendSucc(playerid, "Вы купили автомобиль в автосалоне «Арзамас Карс»");
				format(fmt_str, sizeof(fmt_str), "Вы приобрели %s за "cGR"%d рублей"cWH"! Поздравляем Вас с покупкой!", transport_config[GetVehicleModel(vehicle_id)-400][transport_name], transport_config[GetVehicleModel(vehicle_id)-400][transport_price]);
				SendInf(playerid, fmt_str);
				SendSucc(playerid, "Автомобиль припаркован на парковке отеля, используйте - /unpark, чтобы забрать его!");
				SendInf(playerid, "Чтобы перепарковать автомобиль, используйте - /park и автомобиль будет появляться на новом месте!");

				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_buy_car", 4000);

				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка автомобиля", !"\
				"cWH"Поздравляем Вас с приобретением автомобиля!\n\n\
				Автомобиль находится на парковке отеля!\n\
				"cBLUE"-"cWH" Отпарковать автомобиль: /unpark\n\
				"cBLUE"-"cWH" Припарковать автомобиль: /park\
				"cBLUE"-"cWH" Найти автомобиль: /findcar\n\n\
				Автомобиль находится на парковке автосалона!\n\
				Чтобы забрать его, используйте команду - /cars", !"Далее", "Нет");		

			}

			else
			{

				random_pos = random(30);

				new query[220];
				format(query,sizeof(query),"INSERT INTO `player_vehicles`(`owner`,`model`,`color_1`,`color_2`,`parking_x`,`parking_y`,`parking_z`,`parking_a`) VALUES ('%s','%d','%d','%d','%f','%f','%f','%f')", GetNameEx(playerid), GetVehicleModel(autosalon_id_buy_car[playerid]), color_car, color_car, position_spawn_autosalon_3[random_pos][0], position_spawn_autosalon_3[random_pos][1], position_spawn_autosalon_3[random_pos][2], position_spawn_autosalon_3[random_pos][3]);
				sql_queryEx(zConn, query, QUERY_THREADED);

				SCM(playerid, -1, "");
				SendSucc(playerid, "Вы купили автомобиль в автосалоне «Арзамас Карс»");
				format(fmt_str, sizeof(fmt_str), "Вы приобрели %s за "cGR"%d рублей"cWH"! Поздравляем Вас с покупкой!", transport_config[GetVehicleModel(vehicle_id)-400][transport_name], transport_config[GetVehicleModel(vehicle_id)-400][transport_price]);
				SendInf(playerid, fmt_str);
				SendSucc(playerid, "Автомобиль припаркован на парковке автосалона, используйте - /unpark, чтобы забрать его!");
				SendInf(playerid, "Чтобы перепарковать автомобиль, используйте - /park и автомобиль будет появляться на новом месте!");

				show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_buy_car", 4000);

				SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Покупка автомобиля", !"\
				"cWH"Поздравляем Вас с приобретением автомобиля!\n\n\
				Автомобиль находится на парковке автосалона!\n\
				"cBLUE"-"cWH" Отпарковать автомобиль: /unpark\n\
				"cBLUE"-"cWH" Припарковать автомобиль: /park\
				"cBLUE"-"cWH" Найти автомобиль: /findcar\n\n\
				Автомобиль находится на парковке автосалона!\n\
				Чтобы забрать его, используйте команду - /cars", !"Далее", "Нет");		
			}	

			new query[256];
			format(query,sizeof(query),"UPDATE `transport_autosalon` SET autosalon_car_count_%d = '%d' WHERE `autosalon_config_id` = '2'", autosalon_select_count[playerid]+1, autosalon_transport_config[2][autosalon_car_count][autosalon_select_count[playerid]]);
			sql_queryEx(zConn, query, QUERY_THREADED);	

			DestroyVehicle(vehicle_id);	

		}
		exit_select_car_autosalon(playerid);	
	}
	else
	{
		new 
			color_car = GetPVarIntNew(playerid, "color_buy_car"),
			autosalon_car = GetPVarIntNew(playerid, "type_autosalon_select_car"),
			fmt_str[200];

		new 
			vehicle_id = autosalon_id_buy_car[playerid];

		SetTimeoutChatDissappearTime(playerid, 500, 1500);

		if(GetPlayerMoneyEx(playerid) <  transport_config[GetVehicleModel(vehicle_id)-400][transport_price])
		{
			show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_21", 2500);
			return SendErr(playerid, "У вас недостаточно денежных средств для покупки данного транспорта!");
		}

		if(autosalon_car == BUISNES_AUTOSALON_1)
		{	
			SetTimeoutChatDissappearTime(playerid, 500, 1500);

			if(autosalon_transport_config[0][autosalon_car_count][autosalon_select_count[playerid]] == 0)
				return SendErr(playerid, "В данный момент, модель автомобиля отсутствует в автосалоне!");

			autosalon_transport_config[0][autosalon_car_count][autosalon_select_count[playerid]]--;

			give_money(playerid, -transport_config[GetVehicleModel(vehicle_id)-400][transport_price] ,"Приобретение автомобиля в Арзамас Карс");
			if(b_type == BUISNES_AUTOSALON_1) buisness_bank_update(b_id, floatround(transport_config[GetVehicleModel(vehicle_id)-400][transport_price]*0.6), "Приобретение автомобиля в Арзамас Карс");

			SendClientMessage(playerid, -1, " ");
			SendSucc(playerid, "Вы купили автомобиль в автосалоне «Арзамас Карс»");

			new query[256];
			format(query,sizeof(query),"UPDATE `transport_autosalon` SET autosalon_car_count_%d = '%d' WHERE `autosalon_config_id` = '0'", autosalon_select_count[playerid]+1, autosalon_transport_config[0][autosalon_car_count][autosalon_select_count[playerid]]);
			sql_queryEx(zConn, query, QUERY_THREADED);
		}

		else if(autosalon_car == BUISNES_AUTOSALON_2)
		{
			SetTimeoutChatDissappearTime(playerid, 500, 1500);
			if(autosalon_transport_config[1][autosalon_car_count][autosalon_select_count[playerid]] == 0)
				return SendErr(playerid, "В данный момент, модель автомобиля отсутствует в автосалоне!");

			autosalon_transport_config[1][autosalon_car_count][autosalon_select_count[playerid]]--;

			give_money(playerid, -transport_config[GetVehicleModel(vehicle_id)-400][transport_price] ,"Приобретение автомобиля в «АвтоХаус»");
			if(b_type == BUISNES_AUTOSALON_2) buisness_bank_update(b_id, floatround(transport_config[GetVehicleModel(vehicle_id)-400][transport_price]*0.6), "Приобретение автомобиля в «АвтоХаус»");

			SendClientMessage(playerid, -1, " ");
			SendSucc(playerid, "Вы купили автомобиль в автосалоне «Арзамас Карс»");

			new query[256];
			format(query,sizeof(query),"UPDATE `transport_autosalon` SET autosalon_car_count_%d = '%d' WHERE `autosalon_config_id` = '1'", autosalon_select_count[playerid]+1, autosalon_transport_config[1][autosalon_car_count][autosalon_select_count[playerid]]);
			sql_queryEx(zConn, query, QUERY_THREADED);
		}
		else if(autosalon_car == BUISNES_AUTOSALON_3)
		{
			SetTimeoutChatDissappearTime(playerid, 500, 1500);
			if(autosalon_transport_config[2][autosalon_car_count][autosalon_select_count[playerid]] == 0)
				return SendErr(playerid, "В данный момент, модель автомобиля отсутствует в автосалоне!");

			autosalon_transport_config[2][autosalon_car_count][autosalon_select_count[playerid]]--;

			give_money(playerid, -transport_config[GetVehicleModel(vehicle_id)-400][transport_price] ,"Приобретение автомобиля в «АвтодВОР»");
			if(b_type == BUISNES_AUTOSALON_3) buisness_bank_update(b_id, floatround(transport_config[GetVehicleModel(vehicle_id)-400][transport_price]*0.6), "Приобретение автомобиля в Арзамас Карс");	

			SendClientMessage(playerid, -1, " ");
			SendSucc(playerid, "Вы купили автомобиль в автосалоне «Арзамас Карс»");

			new query[256];
			format(query,sizeof(query),"UPDATE `transport_autosalon` SET autosalon_car_count_%d = '%d' WHERE `autosalon_config_id` = '2'", autosalon_select_count[playerid]+1, autosalon_transport_config[2][autosalon_car_count][autosalon_select_count[playerid]]);
			sql_queryEx(zConn, query, QUERY_THREADED);
		}

		DestroyVehicle(vehicle_id);	

		new random_pos = gen_random_position_parking(playerid), vehicle_vw;

		if(pData[playerid][pParkingVehicle] == 1) vehicle_vw = VIRTUAL_WORLD_PARKING_1;
		else if(pData[playerid][pParkingVehicle] == 2) vehicle_vw = VIRTUAL_WORLD_PARKING_2;

		new query[250];
		format(query,sizeof query, "INSERT INTO `player_vehicles` \
				(`owner`,`model`,`color_1`,`color_2`, `parking_x`,`parking_y`,`parking_z`,`parking_a`, `parking_vw`) \
					VALUES \
				('%s','%d','%d','%d','%f','%f','%f','%f','%d')", 
			GetNameEx(playerid), GetVehicleModel(autosalon_id_buy_car[playerid]), color_car, color_car, 
			parking_vehicle_position_spawn[random_pos][0], parking_vehicle_position_spawn[random_pos][1], 
			parking_vehicle_position_spawn[random_pos][2], parking_vehicle_position_spawn[random_pos][3], 
			vehicle_vw
		);
		sql_queryEx(zConn, query, QUERY_THREADED);	

		format(fmt_str, sizeof(fmt_str), "Вы приобрели %s за "cGR"%d рублей"cWH"! Поздравляем Вас с покупкой!", transport_config[GetVehicleModel(vehicle_id)-400][transport_name], transport_config[GetVehicleModel(vehicle_id)-400][transport_price]);
		SendFInfoMessage(playerid, fmt_str);

		SendSucc(playerid, "Автомобиль припаркован на паркинге, используйте - /car, чтобы забрать его!");
		SendInf(playerid, "Чтобы перепарковать автомобиль, используйте - /park и автомобиль будет появляться на новом месте!");

		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_CENTER, "brilliantother:info_gui_buy_car", 4000);
		SPD(playerid, 0, DIALOG_STYLE_MSGBOX, ""cBLUE"Покупка автомобиля", "\n\
			"cWH"Автомобиль находится на паркинге.\n\
			Чтобы найти его, используйте команду "cBLUE"/car » Отметить паркинг автомобиля"cWH".\n\
			\n\
			Чтобы отпарковать автомобиль, используйте команду "cBLUE"/unpark"cWH".\n\
			Чтобы припарковать автомобиль в удобном для Вас месте, используйте команду "cBLUE"/park"cWH".", 
			"Закрыть", ""
		);
		exit_select_car_autosalon(playerid);
	}

	return true;
}




stock dialog_show_autosalon_rent(playerid, type)
{


	switch(type)
	{
		case BUISNES_AUTOSALON_1:
		{
			SPD(playerid, DIALOG_START_SELECT_RENT_CAR_1, DIALOG_STYLE_MSGBOX, !""cBLUE"Автосалон «Арзамас Карс»", !"\
			"cBLUE"-"cWH" Добро пожаловать в Автосалон «Арзамас Карс»!\n\n\
			Хотите прокатиться на крутых автомобилях? Тогда Вы по адресу!\n\
			Вы можете выбрать из общего списка марку автомобиля на которой хотите прокатиться!", !"Да", !"Нет");			
		}
		case BUISNES_AUTOSALON_2:
		{
			SPD(playerid, DIALOG_START_SELECT_RENT_CAR_2, DIALOG_STYLE_MSGBOX, !""cBLUE"Автосалон «АвтоХаус»", !"\
			"cBLUE"-"cWH" Добро пожаловать в Автосалон «АвтоХаус»!\n\n\
			Хотите прокатиться на крутых автомобилях? Тогда Вы по адресу!\n\
			Вы можете выбрать из общего списка марку автомобиля на которой хотите прокатиться!", !"Да", !"Нет");		
		}
		case BUISNES_AUTOSALON_3:
		{
			SPD(playerid, DIALOG_START_SELECT_RENT_CAR_3, DIALOG_STYLE_MSGBOX, !""cBLUE"Автосалон «АвтоДвор»", !"\
			"cBLUE"-"cWH" Добро пожаловать в Автосалон «АвтоДвор»!\n\n\
			Хотите прокатиться на крутых автомобилях? Тогда Вы по адресу!\n\
			Вы можете выбрать из общего списка марку автомобиля на которой хотите прокатиться!", !"Да", !"Нет");	
		}
	}

	return true;
}


stock select_vehicle_rent_autosalon(playerid, type)
{
	switch(type)
	{
		case BUISNES_AUTOSALON_1:
		{
		    format(String1024, sizeof(String1024), "\
		        "cGREY"Модель\t"cGREY"Стоимость аренды\n\
		        "cBLUE"- "cWH"%s\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"%s\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"%s\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"%s\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"%s\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"%s\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"%s\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"%s\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"%s\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"%s\t"cGR"%d рублей\n\
		        \t\n\
		        "cBLUE"- "cWH"Доступно для аренды\t"cBLUE"%d автомобилей", 
		        transport_config[MiddleVehicles[0]-400][transport_name], transport_config[MiddleVehicles[0]-400][transport_price_rent],
		        transport_config[MiddleVehicles[1]-400][transport_name], transport_config[MiddleVehicles[1]-400][transport_price_rent],
		        transport_config[MiddleVehicles[2]-400][transport_name], transport_config[MiddleVehicles[2]-400][transport_price_rent],
		        transport_config[MiddleVehicles[3]-400][transport_name], transport_config[MiddleVehicles[3]-400][transport_price_rent],
		        transport_config[MiddleVehicles[4]-400][transport_name], transport_config[MiddleVehicles[4]-400][transport_price_rent],
		        transport_config[MiddleVehicles[5]-400][transport_name], transport_config[MiddleVehicles[5]-400][transport_price_rent],
		        transport_config[MiddleVehicles[6]-400][transport_name], transport_config[MiddleVehicles[6]-400][transport_price_rent],
		        transport_config[MiddleVehicles[7]-400][transport_name], transport_config[MiddleVehicles[7]-400][transport_price_rent],
		        transport_config[MiddleVehicles[8]-400][transport_name], transport_config[MiddleVehicles[8]-400][transport_price_rent],
		        transport_config[MiddleVehicles[9]-400][transport_name], transport_config[MiddleVehicles[9]-400][transport_price_rent],
		        autosalon_count_rent_car[0]);
		    return SPD(playerid, DIALOG_SELECT_RENT_C_SALON_1, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Аренда «Арзамас Карс»", String1024, !"Выбрать", !"Закрыть"); 			
		}
		case BUISNES_AUTOSALON_2:
		{
		    format(String1024, sizeof(String1024), "\
		        "cGREY"Модель\t"cGREY"Стоимость аренды\n\
		        "cBLUE"- "cWH"%s\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"%s\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"%s\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"%s\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"%s\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"%s\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"%s\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"%s\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"%s\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"%s\t"cGR"%d рублей\n\
		        \t\n\
		        "cBLUE"- "cWH"Доступно для аренды\t"cBLUE"%d автомобилей", 
		        transport_config[EliteVehicles[0]-400][transport_name], transport_config[EliteVehicles[0]-400][transport_price_rent],
		        transport_config[EliteVehicles[1]-400][transport_name], transport_config[EliteVehicles[1]-400][transport_price_rent],
		        transport_config[EliteVehicles[2]-400][transport_name], transport_config[EliteVehicles[2]-400][transport_price_rent],
		        transport_config[EliteVehicles[3]-400][transport_name], transport_config[EliteVehicles[3]-400][transport_price_rent],
		        transport_config[EliteVehicles[4]-400][transport_name], transport_config[EliteVehicles[4]-400][transport_price_rent],
		        transport_config[EliteVehicles[5]-400][transport_name], transport_config[EliteVehicles[5]-400][transport_price_rent],
		        transport_config[EliteVehicles[6]-400][transport_name], transport_config[EliteVehicles[6]-400][transport_price_rent],
		        transport_config[EliteVehicles[7]-400][transport_name], transport_config[EliteVehicles[7]-400][transport_price_rent],
		        transport_config[EliteVehicles[8]-400][transport_name], transport_config[EliteVehicles[8]-400][transport_price_rent],
		        transport_config[EliteVehicles[9]-400][transport_name], transport_config[EliteVehicles[9]-400][transport_price_rent],
		        autosalon_count_rent_car[1]);
		    return SPD(playerid, DIALOG_SELECT_RENT_C_SALON_2, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Аренда «АвтоХаус»", String1024, !"Выбрать", !"Закрыть"); 			
		}
		case BUISNES_AUTOSALON_3:
		{
		    format(String1024, sizeof(String1024), "\
		        "cGREY"Модель\t"cGREY"Стоимость аренды\n\
		        "cBLUE"- "cWH"%s\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"%s\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"%s\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"%s\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"%s\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"%s\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"%s\t"cGR"%d рублей\n\
		        "cBLUE"- "cWH"%s\t"cGR"%d рублей\n\
		        \t\n\
		        "cBLUE"- "cWH"Доступно для аренды\t"cBLUE"%d автомобилей", 
		        transport_config[EkonomVehicles[0]-400][transport_name], transport_config[EkonomVehicles[0]-400][transport_price_rent],
		        transport_config[EkonomVehicles[1]-400][transport_name], transport_config[EkonomVehicles[1]-400][transport_price_rent],
		        transport_config[EkonomVehicles[2]-400][transport_name], transport_config[EkonomVehicles[2]-400][transport_price_rent],
		        transport_config[EkonomVehicles[3]-400][transport_name], transport_config[EkonomVehicles[3]-400][transport_price_rent],
		        transport_config[EkonomVehicles[4]-400][transport_name], transport_config[EkonomVehicles[4]-400][transport_price_rent],
		        transport_config[EkonomVehicles[5]-400][transport_name], transport_config[EkonomVehicles[5]-400][transport_price_rent],
		        transport_config[EkonomVehicles[6]-400][transport_name], transport_config[EkonomVehicles[6]-400][transport_price_rent],
		        transport_config[EkonomVehicles[7]-400][transport_name], transport_config[EkonomVehicles[7]-400][transport_price_rent],
		        transport_config[EkonomVehicles[8]-400][transport_name], transport_config[EkonomVehicles[8]-400][transport_price_rent],
		        autosalon_count_rent_car[2]);
		    return SPD(playerid, DIALOG_SELECT_RENT_C_SALON_3, DIALOG_STYLE_TABLIST_HEADERS, !""cBLUE"Аренда «АвтоДвор»", String1024, !"Выбрать", !"Закрыть"); 			
		}
	}
	return true;
}


stock rent_car_autosalon_1(playerid, model)
{
	if(!pData[playerid][pLicenses][LIC_DRIVING])
		return SendErr(playerid, "У вас нет лицензии на управление транспортом!");

	if(GetPlayerMoneyEx(playerid) <  transport_config[model-400][transport_price_rent])
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_21", 2500);
		return SendErr(playerid, "У вас недостаточно денежных средств для аренды данного транспорта!");
	}

	if(pTemp[playerid][rent_car] == GetPlayerVehicleID(playerid))
	{
		KillTimer(pTemp[playerid][rent_car_spawn_timer]);
		return true;
	}
	if(pTemp[playerid][rent_car] != INVALID_VEHICLE_ID)
	{
		SendErr(playerid, "Вы уже арендуете какой-либо транспорт");
		return RemovePlayerFromVehicleEx(playerid); 
	}

	if(autosalon_count_rent_car[0] == 0)
		return SendErr(playerid, "Все автомобили для аренды были разобраны!");

	autosalon_count_rent_car[0]--;

	new 
		c1 = random(250),
		c2 = random(250);

	new 
		random_pos = random(25);

	rent_car_salon_1[playerid] = CreateVehicle(model, position_spawn_autosalon_1[random_pos][0], position_spawn_autosalon_1[random_pos][1], position_spawn_autosalon_1[random_pos][2], position_spawn_autosalon_1[random_pos][3], c1, c2, 600);	


	SetVehicleRuNumberPlate(rent_car_salon_1[playerid], "р000рр", "77");

	vehicle[rent_car_salon_1[playerid]][cFuel] = transport_config[model-400][transport_tank];
	vehicle[rent_car_salon_1[playerid]][cHealth] = 1000.0;
	vehicle[rent_car_salon_1[playerid]][cIsCreated] = true;
	vehicle[rent_car_salon_1[playerid]][cOwnTo] = VEHICLE_AUTOSALON_1;
	vehicle[rent_car_salon_1[playerid]][cLock] = 1;
	vehicle[rent_car_salon_1[playerid]][consumables_oil] = 1000.0;

	vehicle_lock_status(rent_car_salon_1[playerid], false);


	pTemp[playerid][rent_car] = rent_car_salon_1[playerid];

	SetPVarIntNew(playerid, "rent_car_salon", VEHICLE_AUTOSALON_1);

	TogglePlayerControllable(playerid, true);	

	new 
		fmt_str[200];

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_RIGHT, "brilliantother:info_gui_vehicle_rent", 3500);

	SendSucc(playerid, "Вы арендовали транспортное средство у автосалона «Арзамас Карс»");
	format(fmt_str, sizeof(fmt_str), "Вы арендовали %s за "cGR"%d рублей"cWH"! Удачной поездки!", transport_config[GetVehicleModel(rent_car_salon_1[playerid])-400][transport_name], transport_config[GetVehicleModel(rent_car_salon_1[playerid])-400][transport_price_rent]);
	SendSucc(playerid, fmt_str);	 
	SendInf(playerid, "Для того, чтобы закрыть арендованное транспортное средство, используйте - /lock 2");
	SendInf(playerid, "Чтобы отменить аренду мопеда используйте команду - /unrent");

	give_money(playerid, -transport_config[model-400][transport_price_rent], "Аренда автомобиля АрзамасКарс");
	buisness_bank_update(6, floatround(transport_config[model-400][transport_price_rent]*0.8), "Аренда автомобиля АрзамасКарс");

	

	return true;
}

stock rent_car_autosalon_2(playerid, model)
{

	if(!pData[playerid][pLicenses][LIC_DRIVING])
		return SendErr(playerid, "У вас нет лицензии на управление транспортом!");

	if(GetPlayerMoneyEx(playerid) <  transport_config[model-400][transport_price_rent])
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_21", 2500);
		return SendErr(playerid, "У вас недостаточно денежных средств для аренды данного транспорта!");
	}


	if(pTemp[playerid][rent_car] == GetPlayerVehicleID(playerid))
	{
		KillTimer(pTemp[playerid][rent_car_spawn_timer]);
		return true;
	}
	if(pTemp[playerid][rent_car] != INVALID_VEHICLE_ID)
	{
		SendErr(playerid, "Вы уже арендуете какой-либо транспорт");
		return RemovePlayerFromVehicleEx(playerid); 
	}

	if(autosalon_count_rent_car[1] == 0)
		return SendErr(playerid, "Все автомобили для аренды были разобраны!");

	autosalon_count_rent_car[1]--;

	new 
		c1 = random(250),
		c2 = random(250);

	new 
		random_pos = random(35);

	rent_car_salon_2[playerid] = CreateVehicle(model, position_spawn_autosalon_2[random_pos][0], position_spawn_autosalon_2[random_pos][1], position_spawn_autosalon_2[random_pos][2], position_spawn_autosalon_2[random_pos][3], c1, c2, 600);	

	SetVehicleRuNumberPlate(rent_car_salon_2[playerid], "р111рр", "77");

	vehicle[rent_car_salon_2[playerid]][cFuel] = transport_config[model-400][transport_tank];
	vehicle[rent_car_salon_2[playerid]][cHealth] = 1000.0;
	vehicle[rent_car_salon_2[playerid]][cIsCreated] = true;
	vehicle[rent_car_salon_2[playerid]][cOwnTo] = VEHICLE_AUTOSALON_2;
	vehicle[rent_car_salon_2[playerid]][cLock] = 1;
	vehicle[rent_car_salon_2[playerid]][consumables_oil] = 1000.0;

	vehicle_lock_status(rent_car_salon_2[playerid], false);

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_RIGHT, "brilliantother:info_gui_vehicle_rent", 3500);

	new
		v = rent_car_salon_2[playerid];	

	pTemp[playerid][rent_car] = v;

	TogglePlayerControllable(playerid, true);	

	SetPVarIntNew(playerid, "rent_car_salon", VEHICLE_AUTOSALON_2);

	new 
		fmt_str[200];

	SendSucc(playerid, "Вы арендовали транспортное средство у автосалона «АвтоХаус»");
	format(fmt_str, sizeof(fmt_str), "Вы арендовали %s за "cGR"%d рублей"cWH"! Удачной поездки!", transport_config[GetVehicleModel(rent_car_salon_2[playerid])-400][transport_name], transport_config[GetVehicleModel(rent_car_salon_2[playerid])-400][transport_price_rent]);
	SendSucc(playerid, fmt_str);	
	SendInf(playerid, "Для того, чтобы закрыть арендованное транспортное средство, используйте - /lock 2");
	SendInf(playerid, "Чтобы отменить аренду мопеда используйте команду - /unrent");

	give_money(playerid, -transport_config[model-400][transport_price_rent], "Аренда автомобиля АвтоХаус");
	buisness_bank_update(7, floatround(transport_config[model-400][transport_price_rent]*0.8), "Аренда автомобиля АвтоХаус");

	return true;
}

stock rent_car_autosalon_3(playerid, model)
{

	if(!pData[playerid][pLicenses][LIC_DRIVING])
		return SendErr(playerid, "У вас нет лицензии на управление транспортом!");

	if(GetPlayerMoneyEx(playerid) <  transport_config[model-400][transport_price_rent])
	{
		show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_CENTER, "brilliantother:notify_player_21", 2500);
		return SendErr(playerid, "У вас недостаточно денежных средств для аренды данного транспорта!");
	}


	if(pTemp[playerid][rent_car] == GetPlayerVehicleID(playerid))
	{
		KillTimer(pTemp[playerid][rent_car_spawn_timer]);
		return true;
	}
	if(pTemp[playerid][rent_car] != INVALID_VEHICLE_ID)
	{
		SendErr(playerid, "Вы уже арендуете какой-либо транспорт");
		return RemovePlayerFromVehicleEx(playerid); 
	}

	if(autosalon_count_rent_car[2] == 0)
		return SendErr(playerid, "Все автомобили для аренды были разобраны!");

	autosalon_count_rent_car[2]--;

	new 
		c1 = random(250),
		c2 = random(250);

	new 
		random_pos = random(14);

	rent_car_salon_3[playerid] = CreateVehicle(model, position_spawn_autosalon_3[random_pos][0], position_spawn_autosalon_3[random_pos][1], position_spawn_autosalon_3[random_pos][2], position_spawn_autosalon_3[random_pos][3], c1, c2, 600);	

	SetVehicleRuNumberPlate(rent_car_salon_3[playerid], "р222рр", "77");

	vehicle[rent_car_salon_3[playerid]][cFuel] = transport_config[model-400][transport_tank];
	vehicle[rent_car_salon_3[playerid]][cHealth] = 1000.0;
	vehicle[rent_car_salon_3[playerid]][cIsCreated] = true;
	vehicle[rent_car_salon_3[playerid]][cOwnTo] = VEHICLE_AUTOSALON_2;
	vehicle[rent_car_salon_3[playerid]][cLock] = 1;
	vehicle[rent_car_salon_3[playerid]][consumables_oil] = 1000.0;

	vehicle_lock_status(rent_car_salon_3[playerid], false);


	new
		v = rent_car_salon_3[playerid];	

	pTemp[playerid][rent_car] = v;

	TogglePlayerControllable(playerid, true);	

	SetPVarIntNew(playerid, "rent_car_salon", VEHICLE_AUTOSALON_3);

	new 
		fmt_str[200];

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_128_RIGHT, "brilliantother:info_gui_vehicle_rent", 3500);

	SendSucc(playerid, "Вы арендовали транспортное средство у автосалона «АвтоДвор»");
	format(fmt_str, sizeof(fmt_str), "Вы арендовали %s за "cGR"%d рублей"cWH"! Удачной поездки!", transport_config[GetVehicleModel(rent_car_salon_3[playerid])-400][transport_name], transport_config[GetVehicleModel(rent_car_salon_3[playerid])-400][transport_price_rent]);
	SendSucc(playerid, fmt_str);	
	SendInf(playerid, "Для того, чтобы закрыть арендованное транспортное средство, используйте - /lock 2");
	SendInf(playerid, "Чтобы отменить аренду мопеда используйте команду - /unrent");

	give_money(playerid, -transport_config[model-400][transport_price_rent], "Аренда автомобиля АвтоДвор");
	buisness_bank_update(10, floatround(transport_config[model-400][transport_price_rent]*0.8), "Аренда автомобиля АвтоХаус");

	return true;
}

stock autosalon_unrent_car(playerid)
{
	new 
		v = pTemp[playerid][rent_car];

	if(v == INVALID_VEHICLE_ID) 
		return true;

	if(vehicle[v][cOwnTo] != GetPVarIntNew(playerid, "rent_car_salon")) 
		return true;

	if(rent_car_salon_1[playerid] != INVALID_VEHICLE_ID)
	{
		autosalon_count_rent_car[0]++;
		DestroyVehicle(rent_car_salon_1[playerid]);
	}
	if(rent_car_salon_2[playerid] != INVALID_VEHICLE_ID)
	{
		autosalon_count_rent_car[1]++;
		DestroyVehicle(rent_car_salon_2[playerid]);
	}
	if(rent_car_salon_3[playerid] != INVALID_VEHICLE_ID)
	{
		autosalon_count_rent_car[2]++;
		DestroyVehicle(rent_car_salon_3[playerid]);
	}

	rent_car_salon_1[playerid] = INVALID_VEHICLE_ID,
	rent_car_salon_2[playerid] = INVALID_VEHICLE_ID,
	rent_car_salon_3[playerid] = INVALID_VEHICLE_ID;

	pTemp[playerid][rent_car] = INVALID_VEHICLE_ID;
	pTemp[playerid][rent_car_spawn_timer] = INVALID_TIMER_ID;

	show_notify_gui(playerid, TEXTDRAW_SHOW, NOTIFY_GUI_256_RIGHT, "brilliantother:info_gui_vehicle_unrent", 3500);

	SendInf(playerid, "Ваше арендованное транспортное было доставлено обратно в автосалон!");

	return true;
}


callback:: spawn_rent_car_autosalon(i, v, time)
{

	if(IsPlayerConnected(i))
	{	
		time--;

		if(!time)
		{
			autosalon_unrent_car(i);
			return true;
		}
		pTemp[i][rent_car_spawn_timer] = SetTimerEx("spawn_rent_car_autosalon", 1000, false, "iii", i, v, time);
	}
	return true;
}


CMD:reload_autosalon_count(playerid)
{
	if(pData[playerid][pAdmin] < 8) 
		return true;

	load_all_config_autosalon();
	SendSucc(playerid, "Количество авто в автосалонах было успешно перезагружено!");
	return true;
}

stock info_car_autosalon_luxe(playerid, type)
{

	switch(type)
	{
		case 1:
		{
			SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Bentley Continental GT", !"\
			"cBLUE"Bentley Continental GT"cWH" — двухдверное 4-местное купе люкс класса, выпускаемое компанией Bentley Motors\n\n\
			"cBLUE"Общие сведения:\n\n\
			"cBLUE"-"cWH" Оснащён 12-цилиндровым W-образным двигателем объёмом 6 литров и мощностью 575 л.с.\n\
			Потребление топлива 26,5 л/100 км\n\n\
			"cBLUE"-"cWH" С 2012 года выпускается разработанная совместно с Audi более экономичная версия:\n\
			8-цилиндровым V-двигатель объёмом 4л,оснащенный двойным турбонаддувом, мощность которого составляет 509 л.с. \n\
			Потребление горючего 10,5 л/100 км. Ускорение 0-100 км/ч =4,8 сек\n\n\
			"cBLUE"-"cWH" Новинкой 8-цилиндровой версии также является 8-ступенчатая коробка передач, \n\
			которая в будущем будет устанавливаться также и на 12-цилиндровой версии автомобиля\n\n\
			"cBLUE"-"cWH" Несмотря на внушительные габариты, Bentley Continental GT четырёхместный автомобиль. \n\
			По заявлениям Bentley Motors, человек ростом 180 см с комфортом поместится как на передних, так и на задних сидениях. \n\
			На выбор клиента предоставляется огромное количество всевозможных цветов кожи и пород дерева для обивки салон\n\n\
			"cBLUE"-"cWH" Панель приборов вместе с центральной консолью выполнены симметрично и напоминают символику Bentley — крыло\n\
			Большинством самых часто используемых функций можно управлять с трёхспицевого рулевого колеса. \n\
			Базовые версии автомобиля оснащаются акустической системой BOSE и мультимедийным интерфейсом Logic by Pioneer, \n\
			премиальные 7.2-ми канальной Bang & Olufsen с интерфейсом Onkyo\n\n\
			"cBLUE"-"cWH" Автомобиль оснащается вентилируемыми тормозными дисками с АБС фирмы Bosch\n\
			Тормозная система дополнительно оснащена технологией Brake Assist и электронным распределением тормозного усилия\n\
			По желанию клиента Continental GT оснащается высокопроизводительными углеродными керамическими тормозными дисками", !"Закрыть", "");
		}
		case 2:
		{
			SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Nissan GT-R", !"\
			"cBLUE"Nissan GT-R"cWH" — спорткар, выпускаемый компанией Nissan Motor\n\
			Представлен в качестве серийной модели на Токийском автосалоне 24 октября 2007 года, \n\
			продажи начались в 2008 году в Японии, затем в США и Европе. \n\
			В отличие от предшественников, выпускавшихся только для JDM и ограниченным тиражом поставлявшихся\n\
			в Великобританию, имеется вариант с левым рулём\n\n\
			"cBLUE"Общие сведения:\n\n\
			"cBLUE"-"cWH" Двигатель: VR38DETT 6-цилиндровый V-образный, объемом 3,8 л, с двумя турбонаддувами IHI, расположен впереди\n\
			Мощность: 353 кВт (от 485 до 600 л. с. в зависимости от года выпуска и модификации) при 6400 об/мин. \n\
			Каждый двигатель собирается вручную\n\n\
			"cBLUE"-"cWH" Трансмиссия: полноприводная ATTESA E-TS с механически блокируемым дифференциалом\n\
			Трансмиссия включает два приводных вала, один передает мощность от двигателя к коробке передач, \n\
			расположенной в задней части автомобиля, для привода задних колес, второй — от коробки к передним колесам\n\n\
			"cBLUE"-"cWH" Коробка передач: 6-ступенчатая роботизированная BorgWarner с двойным сцеплением\n\
			Время переключения менее 0,15 с. Находится в задней части автомобиля\n\
			Кованые колесные диски из сверхлегкого алюминиевого сплава\n\n\
			"cBLUE"-"cWH" Тормозная система: дисковые 15 тормоза Brembo с 6-поршневыми суппортами спереди и 4-поршневыми сзади\n\
			Независимая подвеска: Bilstein DampTronic\n\n\
			"cBLUE"-"cWH" Сиденья и оплетка руля сделаны из замши и окрашены в черный и красный цвет", !"Закрыть", "");
		}
		case 3:
		{
			SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Audi RS7", !"\
			"cBLUE"Audi RS7"cWH" — спортивный пятидверный фастбэк класса Гран Туризмо выпускаемый\n\
			подразделением Audi Sport GmbH на платформе Audi A7\n\
			Автомобиль был представлен 16 января 2013 года на Североамериканском международном салоне в Детройте\n\n\
			"cBLUE"Общие сведения:\n\n\
			"cBLUE"-"cWH" RS7 оснащается би-турбированным бензиновым двигателем V8 объёмом 3993 см3\n\
			Мощность двигателя 560 л. с. (605 л. с. performance). Крутящий момент составляет 700 Нм при 1750 об/мин\n\n\
			"cBLUE"-"cWH" Автомобиль оснащён полным приводом quattro, на заднюю ось с активным дифференциалом\n\
			в обычных условиях передается 60 %% тяги, а на переднюю 40 %%\n\
			Именно сбалансированное распределение крутящего момента на оси придает автомобилю устойчивость и стабильность на дороге\n\
			Audi RS7 Sportback performance оснащен адаптивной пневматической подвеской с регулируемым на 20 мм клиренсом\n\
			"cBLUE"-"cWH" Разгон от 0 до 100 километров в час занимает 3.9 секунды, у версии 'performance 3.7 сек\n\
			Максимальная скорость в зависимости от опции варьируется от 250 до 280 и 305 км/ч\n\n\
			"cBLUE"-"cWH" Для обивки сидений и простора салона используется материалы из натуральной кожи и материалы из алькантары\n\
			В базовой комплектации RS7 применяются материалы из карбона\n\n\
			"cBLUE"-"cWH" Audi RS7 оснащается спортивной тормозной системой, может оснащаться керамическими тормозами, камерой заднего вида, \n\
			фронтальными подушками безопасности, контроль устойчивости на дороге, сенсоры переднего и заднего вида,\n\
			 камер оповещения заднего вида", !"Закрыть", "");
		}
		case 4:
		{
			SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Audi R8", !"\
			"cBLUE"Audi R8"cWH" — среднемоторный полноприводный спортивный автомобиль, \n\
			производимый немецким автопроизводителем Audi с 2007 года. Впервые представлен в 2006 году на Парижском автосалоне\n\n\
			"cBLUE"Общие сведения:\n\n\
			"cBLUE"-"cWH" Модель R8, как и ряд других моделей автоконцерна Audi производится исключительно на заводе Audi Sport GmbH\n\n\
			"cBLUE"-"cWH" В базовой комплектации Audi R8 оснащается атмосферным двигателем V8 объёмом 4,2 литра, использующим технологию FSI, \n\
			который вырабатывает максимальную мощность равную 420 лошадиным силам\n\
			Разгон от 0 до 100 км/ч составляет 4,6 секунды\n\
			Максимальная скорость в целях безопасности ограничена электроникой на отметке 301 км/ч\n\n\
			"cBLUE"-"cWH" Мотор расположен посередине. Соотношение усилия переднего и заднего привода составляет 15:85\n\
			Конструкторы обеспечили сохранность прямолинейности во время торможения, установив электронную систему управления на раздатку: \n\
			при торможении основное тормозное усилие сначала идёт на задний мост, в то время как задний привод выключается, \n\
			передний привод остается работать и получает тормозное усилие уже только при существенной потере скорости\n\
			Таким образом, при торможении машина сохраняет прямолинейность даже на сильном гололёде", !"Закрыть", "");
		}
		case 5:
		{
			SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Lamborghini Urus", !"\
			"cBLUE"Lamborghini Urus"cWH" — первый кроссовер (SSUV - Super Sport Utility Vehicle) от итальянского производителя автомобилей Lamborghini\n\
			Автомобиль был представлен 4 декабря 2017 года на заводе Lamborghini в Сант'Агата-Болоньезе\n\n\
			"cBLUE"Общие сведения:\n\n\
			"cBLUE"-"cWH" В отличие от привычных для Lamborghini атмосферных двигателей V10 и V12, \n\
			В Urus установлен 4.0 литровый V8 twin-turbo производства Audi, также этот двигатель используется\n\
			В некоторых моделях Audi серий S и RS, и Audi A8, Bentley Continental V8 и Flying Spur V8\n\n\
			"cBLUE"-"cWH" Urus намного легче чем построенные на одной платформе Audi Q7, Bentley Bentayga, Porsche Cayenne и Volkswagen Touareg\n\
			из-за применения в конструкции углеволокна\n\n\
			"cBLUE"-"cWH" Интерьер кроссовера от Lamborghini во многом напоминает интерьер Audi Q7\n\
			В оформлении используются элементы из углеволокна аналогично моделям Audi серий S и RS", !"Закрыть", "");
		}
		case 6:
		{
			SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Tesla Model S", !"\
			"cBLUE"Tesla Model S"cWH" — пятидверный электромобиль производства американской компании Tesla\n\
			Прототип был впервые показан на Франкфуртском автосалоне в 2009 году\n\
			Поставки автомобиля в США начались в июне 2012 года\n\n\
			"cBLUE"Общие сведения:\n\n\
			"cBLUE"-"cWH" Базовая модель S использует жидкостное охлаждение двигателя переменного тока,\n\
			который имеет мощность 362 лошадиные силы\n\
			Согласно US Environmental Protection Agency (EPA) заряда литий-ионного аккумулятора..\n\
			ёмкостью 85 кВт.ч хватает на 426 км\n\n\
			"cBLUE"-"cWH" Tesla Model S является одним из наиболее безопасных автомобилей на рынке, получившим 5 звёзд по результатам..\n\
			аварийных испытаний как по версии Euro NCAP, так и NHTSA", !"Закрыть", "");
		}
		case 7:
		{
			SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Mercedes-Benz C63S", !"\
			"cBLUE"Mercedes-Benz C63S"cWH" — C-Класс сочетает в себе спортивный характер с инновациями и технологиями\n\
			В результате получился привлекательный для многих клиентов комплекс, отвечающий самым разнообразным требованиям\n\n\
			"cBLUE"Общие сведения:\n\n\
			"cBLUE"-"cWH" Атмосфера автогонок для улицы и динамика в чистом виде. Благодаря впечатляющему ускорению, вдохновляющей поперечной динамике, \n\
			а также выдающемуся сцеплению с дорогой будут исполнены любые желания, относящиеся к темпераменту, маневренности и точности\n\
			Основой присущих AMG ходовых качеств по большей части является хорошо зарекомендовавший себя 4,0-литровый битурбированный двигатель V8\n\
			Другие высокопроизводительные и высокотехнологичные компоненты обеспечивают впечатляющую маневренность и курсовую устойчивость\n\n\
			"cBLUE"-"cWH" Экспрессивные элементы экстерьера подчеркивают мощный характер Mercedes-AMG C 63 S\n\
			Традиционный стиль AMG однозначно демонстрирует динамику автомобиля – благодаря ему модель C 63 S будет выделяться своей неповторимой \n\
			индивидуальностью с любой точки обзора. Высокотехнологичные компоненты образуют основу для впечатляюще динамичного стиля движения\n\n\
			"cBLUE"-"cWH" Интерьер автомобиля Mercedes-AMG обеспечивает для Вас аутентичную атмосферу спортивного автомобиля\n\
			Во всех гранях салона отражается философия динамики AMG. Любуйтесь идеально подходящими друг к другу элементами, характерными акцентами и салоном,\n\
			до мельчайших деталей ориентированным на спортивность", !"Закрыть", "");
		}
		case 8:
		{
			SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"Lexus LFA", !"\
			"cBLUE"Lexus LFA"cWH" — заднеприводный суперкар японской компании Lexus, первый автомобиль компании в подобном классе\n\
			Впервые был представлен как концепт-кар, гоночный прототип, а также как серийное транспортное средство\n\n\
			"cBLUE"Общие сведения:\n\n\
			"cBLUE"-"cWH" Двигатель LFA был сконструирован в сотрудничестве с Yamaha Motor Company, имеет 4,8-литровый V10 под углом 72°, \n\
			способный выдавать при 8700 об/мин мощность в 560 л.с и 480 Н•м крутящего момента; 90%%  момента доступны уже при 3700 об/мин, \n\
			а красная зона расположена на отметке 9000 об/мин. Максимальная мощность, передаваемая на колёса, была неофициально измерена \n\
			независимым тестом на стенде DynoJet, и составила 514 л.с\n\n\
			"cBLUE"-"cWH" Как утверждают инженеры Lexus, обороты с холостого уровня до красной зоны двигатель может набрать за 0.6 с\n\
			из-за этого аналоговый тахометр не мог точно отслеживать вращение коленчатого вала, и был установлен цифровой\n\n\
			"cBLUE"-"cWH" В интерьере сочетаются алькантара, кожа, металлические элементы и углеволокно\n\
			Два ковшеобразных сидений, мультимедийная система с навигатором, звуковая система \n\
			Mark Levinson из 12 динамиков, джойстик Lexus Remote Touch,цифровой тахометр меняет цвет\n\
			и положение в зависимости от выбранного режима VDIM\n\
			Все элементы интерьера сделаны на заказ, а затем собираются вручную", !"Закрыть", "");
		}		
	}
	return true;

}


stock info_car_autosalon_middle(playerid, type)
{

	switch(type)
	{
		case 1:
		{
			SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"BMW M5 F90", !"\
			"cBLUE"BMW M5 F90"cWH" — доработанная подразделением BMW Motorsport версия автомобиля BMW пятой серии\n\
			Первое поколение было представлено в 1986 году. Последующие поколения M5 сменялись совместно с каждым поколением\n\
			автомобилей пятой серии, включающей E34, E39, E60/61, F10. С началом производства модели G30, после поступления\n\
			первых заказов, с марта 2018 года началось также производство её M-версии\n\n\
			"cBLUE"Общие сведения:\n\n\
			"cBLUE"-"cWH" На M5 F90 установлен 600-сильный, V-образный, восьмицилиндровый агрегат, имеющий объем 4.4 л\n\
			У мотора BMW M5 F90 два турбонагнетателя и усиленный коленчатый вал\n\
			Воздушное охлаждение непрямое, система смазки оптимизированная, выпускная система усовершенствованная и облегченная\n\
			Отсюда и мощность в 600 «лошадей». Отметим еще, что тюнинг BMW M5 F90 и доработка двигателя до stage 2, увеличит его мощь до 750 л.с.\n\n\
			"cBLUE"-"cWH" Спортивность седана подчеркивает и интерьер автомобиля. В салоне BMWM5 F90 новый трехспицевый мультируль, имеющий рельефные очертания\n\
			На нем сразу бросаются в глаза клавиши красного цвета. Это М1 и М2\n\n\
			"cBLUE"-"cWH" На приборной панели – иная графика, при достижении предельных оборотов идет предупреждение от индикатора справа\n\
			Вставки выполнены из карбона, на педалях имеются накладки из металла. Изменены пороги дверей\n\
			Проекционный дисплей позволяет отображать на ветровом стекле данные навигационной системы. Его площадь на M5 F90 возросла на 70%%\n\n\
			"cBLUE"-"cWH" Сиденья плотно обиты кожей Merino. Они обладают некоторым набором электрорегулировок\n\
			За дополнительную плату можно получить в свое распоряжение многофункциональные кресла с полной электрификацией, \n\
			у которых боковая поддержка гораздо лучше и у них особая структурная оболочка\n\n\
			"cBLUE"-"cWH" Высокий уровень комфорта и на заднем диване. Трое взрослых пассажиров не будут чувствовать дискомфорт. \n\
			Достаточно места и для ног, и для головы", !"Закрыть", "");
		}
		case 2:
		{
			SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"BMW X5", !"\
			"cBLUE"BMW X5"cWH" — BMW X5 — среднеразмерный кроссовер от немецкого автопроизводителя BMW\n\
			Автомобиль был представлен в 1999 году на автосалоне в Детройте. Буква «Х» означает, что автомобиль имеет полный привод,\n\
			а цифра «5» — что базой послужила 5-я серия (BMW E39), однако X5 короче E39, но при этом выше и шире\n\
			Кузов Е53 напоминает BMW E46 Touring. Машина приспособлена для езды по всем типам дорожного покрытия, \n\
			этим она обязана большому клиренсу и постоянному приводу на все колёса\n\n\
			"cBLUE"Общие сведения:\n\n\
			"cBLUE"-"cWH" На рынок машина была выведена с двумя двигателями: \n\
			Рядный 6-цилиндровый объёмом 3 литра и мощностью 231 л. с. (170 кВт)\n\
			BMW X5 3.0i и V8 M62 объёмом 4,4 литра и мощностью 286 л. с. (210 кВт) — BMW X5 4.4i\n\n\
			"cBLUE"-"cWH" В 2001 к ним добавили ещё два мотора: 3-литровый дизель M57 \n\
			с системой Common Rail мощностью 184 л. с. (135 кВт) — BMW X5 3.0d и V8 объёмом 4,6 литра\n\
			и мощностью 347 л. с. (255 кВт) — BMW X5 4.6is\n\n\
			"cBLUE"-"cWH" В 2003 при проведении фейслифтинга были заменены моторы V8 4.4i и дизельный 3.0d\n\
			Мощность обновленного дизельного двигателя 218 л. с. (160 кВт) при том же объёме 3 литра\n\
			Бензиновый V8 N62 4,4 литра мощностью 320 л. с. (235 кВт)\n\n\
			"cBLUE"-"cWH" В 2004 году мотор 4.6is был заменён на 4.8is мощностью 360 л. с. (265 кВт) — BMW X5 4.8is", !"Закрыть", "");
		}
		case 3:
		{
			SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"BMW E39", !"\
			"cBLUE"BMW E39"cWH" — модификация кузова BMW «пятой» серии, который выпускался с 1995 по 2003 год включительно\n\
			Предшественником данного кузова был BMW E34, а ему на смену пришли BMW Е60 (в 2003 году) и BMW F10 (в 2010 году)\n\
			в совершенно новом стиле BMW. Базовой в семействе была модель 520i. Её двухлитровый двигатель выдавал 150 л.с.,\n\
			а после рестайлинга объем вырос до 2.2 литра, а мощность до 170 л.с. Версия M5 была выпущена в 1998 году\n\
			Она оснащалась двигателем V8 S62, который был сделан на базе M62B44. Все модификации, кроме 535 и M5 были доступны\n\
			в кузовах седан и универсал. 535 и M5 выпускалась только в кузове седан\n\n\
			"cBLUE"Общие сведения:\n\n\
			"cBLUE"-"cWH" В сентябре 2000 года BMW E39 претерпела рестайлинг\n\
			Внешне обновлённую пятёрку можно легко узнать по оригинальной светотехнике, выполненной по технологии CELIS, \n\
			бамперам и более округлым зеркалам.\n\
			Однако главные изменения скрыты внутри — здесь появились сразу три новых двигателя M54 для моделей BMW 520i, 525i и 530i.\n\
			Все они рядные, 6-цилиндровые, с системой Double-VANOS. Первый двигатель для BMW 520i, создан на базе старого 2-литрового агрегата.\n\
			Увеличение хода поршня с 66 до 72 мм, позволило увеличить рабочий объём с 1991 до 2171 см? и максимальную мощность\n\
			со 151 до 170 л.с. при 6250 об/мин\n\
			Второй двигатель — это прежний 2,5-литровый агрегат модели BMW 523i, но в модернизированном варианте развивающий уже не 170, а 192 л.с.\n\
			(индекс 523i заменили на правильный 525i)\n\
			Третий двигатель для BMW 530i, впервые, в середине 2000 года, появился на моделях 3-й серии — это 3-литровый двигатель с внушительной мощностью в 231 л.с.\n\
			К конструктивным особенностям модели относят гидронаполненные сайлентблоки, которые лучше гасят вибрации, но достаточно быстро изнашиваются\n\n\
			"cBLUE"-"cWH" Все следующие автомобили «пятой» серии в данном кузове выпускались в новом виде: \n\
			Габаритные (стояночные) огни передних фар получили округлую форму в виде «ангельских глаз»\n\
			Задние фонари имеют прозрачные указатели поворотов, а также светодиодные габаритные огни\n\
			Декоративная решетка радиатора обрела новый, более объемный вид. Немного изменен дизайн бампера, \n\
			новый стиль передних противотуманных фар. Новый дизайн руля в М-стиле", !"Закрыть", "");
		}
		case 4:
		{
			SPD(playerid, 0, DIALOG_STYLE_MSGBOX, !""cBLUE"BMW E30", !"\
			"cBLUE"BMW 3-й серии (E30)"cWH" — второе поколение легковых автомобилей 3-й серии немецкого автоконцерна BMW, выпускавшихся с 1982 по 1994 год\n\
			Серия комплектовалась небывалым ранее набором кузовов и двигателей. Уже через год после начала выпуска предлагался выбор между двух \n\
			и четырёхдверными седанами (нем. Limousine). Открытая версия первоначально производилась на фирме Baur, а в 1985 году компания представила\n\
			собственный кабриолет (нем. Cabrio). В этом же году была выпущена на рынок, ставшая легендарной, спортивная версия M3, в виде двухдверного седана\n\
			и множества различных его вариаций, предназначенных для покупателей с гоночными амбициями\n\
			В 1987 году появился вместительный универсал (нем. Touring), впервые в рамках 3-й серии\n\
			Всего было произведено 2,34 миллиона автомобилей, самая успешная на тот момент серия моделей компании\n\n\
			"cBLUE"Общие сведения:\n\n\
			"cBLUE"-"cWH" Автомобили оснащались рядными четырёх- и шестицилиндровыми бензиновыми и дизельными двигателями разного рабочего объёма и мощности\n\
			Двигатель был установлен спереди продольно и состыковывался с четырёх или пятиступенчатой механической, \n\
			либо с трёх или четырёхступенчатой автоматической коробкой передач\n\n\
			"cBLUE"-"cWH" Кузов был спроектирован в соответствии с требованиями пассивной безопасности, так при столкновении на скорости до 50 км/ч\n\
			передняя часть автомобиля сминалась, оставляя пассажирский салон практически целым\n\
			Специальная конструкция переднего и заднего бамперов защищала автомобиль при контактах на парковочной скорости до 4 км/ч\n\n\
			"cBLUE"-"cWH" В салоне панель приборов напоминала ту, что применялась на моделях предыдущего поколения, но она была переработана в более современном ключе\n\
			Так, появился ряд контрольных ламп, а модели с шестицилиндровыми двигателями получили индикатор расхода топлива и борткомпьютер\n\
			Больше комфорта добавила, также новая система отопления и вентиляции\n\
			Передние сиденья теперь стандартно имели регулировку по высоте, а на двухдверных моделях сдвигались вперёд, для удобства посадки задних пассажиров\n\
			Пространство для ног сзади было увеличено на 40 миллиметров, а задние сиденья стандартно оборудовались ремнями безопасности", !"Закрыть", "");
		}
	}
	return true;
}
