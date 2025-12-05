enum mInfo
{
	mID,
	mPatrons,
	mGuns,
	mDrugs, 
	mHdrugs,
	mMoney,
	mStatus,
	mWHDostup[4],
	mNotify[144],
	mDiplomacy[3]
}
new MafiaInfo[3][mInfo];

new 
	MafiaStoreArea[3],
	Text3D:MafiaStore_3DText[3],
	pickup_spawn_mafia[4];


new gGunAmount[6] = {180,200,280,380,300,300};
new gGunID[6] = {24,29,25,33,30,31};
