
#define NUMBER_REGION_RU	1
#define NUMBER_REGION_KZ	2
#define NUMBER_REGION_BY	3
#define NUMBER_REGION_UA	4

#define CUSTOM_TUNE_VERSION	0x3

enum E_CUSTOM_COMPONENTS
{
	ccBumperF = 0,
	ccBumperR,
	ccFenderF,
	ccFenderR,
	ccSpoiler,
	ccExhaust,
	ccRoof,
	ccTaillights,
	ccHeadlights,
	ccDiffuser,
	ccSplitter,
	ccExtra,
	ccMax
};

enum E_HANDLING_PARAMS
{
	Float:hpMaxSpeed,
	Float:hpAcceleration,
	Float:hpGear,
	Float:hpEngineInertion,
	Float:hpMass,
	Float:hpMassTurn,
	 
	Float:hpBrakeDeceleration,
	Float:hpTractionMultiplier,
	Float:hpTractionLoss,
	Float:hpTractionBias,
	Float:hpSuspensionLowerLimit,
	Float:hpSuspensionBias,
	Float:hpWheelSize,	
	Float:hpMax
};

enum E_VISUALS_CAR
{
	vcToner[3],
	vcVinyls[2],
	
	vcPlateType,
	vcPlateText[30],
	vcPlateRegion[10],
	
	vcLightsColor[3],
	vcWheelAlignment[2],
	vcWheelOffsetX[2],
	vcWheelWidth,
	
	vcShadowColor[3],
	vcShadowSize[2],
	vcShadowTexName[30]
};

#define BIT_SET(%0,%1)   ((%0) |=  (1<<(%1)))
#define BIT_CLEAR(%0,%1) ((%0) &= ~(1<<(%1)))
#define BIT_CHECK(%0,%1) ((%0) &   (1<<(%1)))

#define PACKET_CUSTOMRPC    			251

#define RPC_CUSTOM_COMPONENT			0x10
#define RPC_CUSTOM_HANDLING				0x11
#define RPC_CUSTOM_VISUALS				0x13
#define RPC_CUSTOM_HANDLING_DEFAULTS				0x14

#define EXTRA_COMPONENT_BOOT			10
#define EXTRA_COMPONENT_BONNET			11
#define EXTRA_COMPONENT_BUMP_REAR		12
#define EXTRA_COMPONENT_DEFAULT_DOOR 	13
#define EXTRA_COMPONENT_WHEEL			14
#define EXTRA_COMPONENT_BUMP_FRONT		15

#define TONER_ID_REMOVE	0
#define VINYLS_ID_REMOVE	0

#define TONER_SLOT_FRONT 0
#define TONER_SLOT_MIDDLE 1
#define TONER_SLOT_REAR	2

static g_VehComponentsInfo[MAX_VEHICLES][ccMax];
static g_VehUsesCustomComponents[MAX_VEHICLES];

static g_VehUsesHandling[MAX_VEHICLES];
static Float:g_VehHandlingInfo[MAX_VEHICLES][hpMax];

static g_VehUsesVisuals[MAX_VEHICLES];
static g_VehVisualsInfo[MAX_VEHICLES][E_VISUALS_CAR];

stock InitializeVehComponents()
{
	for(new i = 0; i < MAX_VEHICLES; i++)
	{
		g_VehUsesCustomComponents[i] = false;
		for(new j = 0; j < _:ccMax; j++)
		{
			g_VehComponentsInfo[i][E_CUSTOM_COMPONENTS:j] = 0;
		}
	}
}

stock InitializeVehHandling()
{
	for(new i = 0; i < MAX_VEHICLES; i++)
	{
		g_VehUsesHandling[i] = false;
		for(new j = 0; j < _:hpMax; j++)
		{
			g_VehHandlingInfo[i][E_HANDLING_PARAMS:j] = 0.0;
		}
	}
}

stock ResetVehVisuals(veh)
{
	g_VehUsesVisuals[veh] = false;
	g_VehVisualsInfo[veh][vcToner][0] = 255;
	g_VehVisualsInfo[veh][vcToner][1] = 255;
	g_VehVisualsInfo[veh][vcToner][2] = 255;
	
	g_VehVisualsInfo[veh][vcVinyls][0] = 255;
	g_VehVisualsInfo[veh][vcVinyls][1] = 255;
	
	g_VehVisualsInfo[veh][vcPlateType] = 0;
	
	g_VehVisualsInfo[veh][vcLightsColor][0] = 0xFF;
	g_VehVisualsInfo[veh][vcLightsColor][1] = 0xFF;
	g_VehVisualsInfo[veh][vcLightsColor][2] = 0xFF;
	
	g_VehVisualsInfo[veh][vcWheelAlignment][0] = 0;
	g_VehVisualsInfo[veh][vcWheelAlignment][1] = 0;
	g_VehVisualsInfo[veh][vcWheelOffsetX][0] = 0;
	g_VehVisualsInfo[veh][vcWheelOffsetX][1] = 0;
	g_VehVisualsInfo[veh][vcWheelWidth] = 0;
	
	g_VehVisualsInfo[veh][vcShadowColor][0] = 0;
	g_VehVisualsInfo[veh][vcShadowColor][1] = 0;
	g_VehVisualsInfo[veh][vcShadowColor][2] = 0;
	g_VehVisualsInfo[veh][vcShadowSize][0] = 0;
	g_VehVisualsInfo[veh][vcShadowSize][1] = 0;
}

stock sc_CreateVehicle(veh)
{

	ResetHandlingAttributes(veh);
	ResetVehileComponentsDefault(veh);
	ResetVehVisuals(veh);
}

stock sc_RepairVehicle(veh)
{
	foreach(new i : streamed_players_in_veh[veh])
	{
		UpdateVehComponents(i, veh);
	}
}

stock sc_OnVehicleStreamIn(vehicleid, forplayerid)
{
	UpdateVehHandling(forplayerid, vehicleid);
	UpdateVehComponents(forplayerid, vehicleid);
	UpdateVehVisuals(forplayerid, vehicleid);
}

stock ResetHandlingAttributes(veh)
{
	g_VehUsesHandling[veh] = false;
	for(new j = 0; j < _:hpMax; j++)
	{
		g_VehHandlingInfo[veh][E_HANDLING_PARAMS:j] = 0.0;
	}
}

stock UpdateVehHandling(playerid, veh)
{
	if(!g_VehUsesHandling[veh])
	{
		return;
	}
	new BitStream:bitstream = BS_New();
	BS_WriteValue(bitstream, PR_UINT8, PACKET_CUSTOMRPC);
	BS_WriteValue(bitstream, PR_UINT32, RPC_CUSTOM_HANDLING);
	BS_WriteValue(bitstream, PR_UINT16, veh);
	new count = 0;
	
	for(new i = 0; i < _:hpMax; i++)
	{
		if(g_VehHandlingInfo[veh][E_HANDLING_PARAMS:i] != 0.0)
		{
			count++;
		}
	}
	BS_WriteValue(bitstream, PR_UINT8, count);
	for(new i = 0; i < _:hpMax; i++)
	{
		if(g_VehHandlingInfo[veh][E_HANDLING_PARAMS:i] != 0.0)
		{
			BS_WriteValue(bitstream, PR_UINT8, i);
			BS_WriteValue(bitstream, PR_FLOAT, g_VehHandlingInfo[veh][E_HANDLING_PARAMS:i]);
		}
	}
	BS_Send(bitstream, playerid, PR_HIGH_PRIORITY, PR_RELIABLE_ORDERED);
	BS_Delete(bitstream);
}

stock UpdateVehVisuals(playerid, veh)
{
	if(!g_VehUsesVisuals[veh])
	{
		return;
	}

	new BitStream:bitstream = BS_New();
	BS_WriteValue(bitstream, PR_UINT8, PACKET_CUSTOMRPC);
	BS_WriteValue(bitstream, PR_UINT32, RPC_CUSTOM_VISUALS);
	BS_WriteValue(bitstream, PR_UINT16, veh);
	
	BS_WriteValue(bitstream,
	PR_UINT8, g_VehVisualsInfo[veh][vcLightsColor][0],
	PR_UINT8, g_VehVisualsInfo[veh][vcLightsColor][1],
	PR_UINT8, g_VehVisualsInfo[veh][vcLightsColor][2],
	PR_UINT16, g_VehVisualsInfo[veh][vcWheelWidth],
	PR_INT8, g_VehVisualsInfo[veh][vcWheelAlignment][0],
	PR_INT8, g_VehVisualsInfo[veh][vcWheelAlignment][1],
	PR_INT16, g_VehVisualsInfo[veh][vcWheelOffsetX][0],
	PR_INT16, g_VehVisualsInfo[veh][vcWheelOffsetX][1],
	
	PR_UINT8, g_VehVisualsInfo[veh][vcToner][0],
	PR_UINT8, g_VehVisualsInfo[veh][vcToner][1],
	PR_UINT8, g_VehVisualsInfo[veh][vcToner][2],
	
	PR_UINT8, g_VehVisualsInfo[veh][vcVinyls][0],
	PR_UINT8, g_VehVisualsInfo[veh][vcVinyls][1],
	PR_UINT8, g_VehVisualsInfo[veh][vcPlateType]);
	
	if(g_VehVisualsInfo[veh][vcPlateType] == 1 || g_VehVisualsInfo[veh][vcPlateType] == 4 || g_VehVisualsInfo[veh][vcPlateType] == 5 || g_VehVisualsInfo[veh][vcPlateType] == 6
	|| g_VehVisualsInfo[veh][vcPlateType] == 7)
	{
		BS_WriteValue(bitstream,
		PR_UINT8, strlen(g_VehVisualsInfo[veh][vcPlateText]),
		PR_STRING, g_VehVisualsInfo[veh][vcPlateText]);
		
		BS_WriteValue(bitstream,
		PR_UINT8, strlen(g_VehVisualsInfo[veh][vcPlateRegion]),
		PR_STRING, g_VehVisualsInfo[veh][vcPlateRegion]);
	}
	if(g_VehVisualsInfo[veh][vcPlateType] == 2 || g_VehVisualsInfo[veh][vcPlateType] == 3)
	{
		BS_WriteValue(bitstream,
		PR_UINT8, strlen(g_VehVisualsInfo[veh][vcPlateText]),
		PR_STRING, g_VehVisualsInfo[veh][vcPlateText]);
	}

	BS_WriteValue(bitstream,
	PR_UINT8, g_VehVisualsInfo[veh][vcShadowColor][0],
	PR_UINT8, g_VehVisualsInfo[veh][vcShadowColor][1],
	PR_UINT8, g_VehVisualsInfo[veh][vcShadowColor][2],
	PR_UINT8, g_VehVisualsInfo[veh][vcShadowSize][0],
	PR_UINT8, g_VehVisualsInfo[veh][vcShadowSize][1],
	PR_UINT8, strlen(g_VehVisualsInfo[veh][vcShadowTexName]),
	PR_STRING, g_VehVisualsInfo[veh][vcShadowTexName]);

	BS_Send(bitstream, playerid, PR_HIGH_PRIORITY, PR_RELIABLE);
	BS_Delete(bitstream);

}

stock SetVehicleToner(veh, slot, id)
{
	g_VehUsesVisuals[veh] = true;
	g_VehVisualsInfo[veh][vcToner][slot] = id;
	
	foreach(new i : streamed_players_in_veh[veh])
	{
		UpdateVehVisuals(i, veh);
	}
}

stock SetVehicleWheelAngle(veh, wheel, angle)
{
	g_VehUsesVisuals[veh] = true;
	g_VehVisualsInfo[veh][vcWheelAlignment][wheel] = angle;
	
	foreach(new i : streamed_players_in_veh[veh])
	{
		UpdateVehVisuals(i, veh);
	}
}

// -100 to 100
stock SetVehicleWheelOffsetX(veh, wheel, offset)
{
	g_VehUsesVisuals[veh] = true;
	g_VehVisualsInfo[veh][vcWheelOffsetX][wheel] = offset;
	
	foreach(new i : streamed_players_in_veh[veh])
	{
		UpdateVehVisuals(i, veh);
	}
}
//0 - 2000, 100 = 1.0f, 101 = 1.01f
stock SetVehicleWidthWheel(veh, offset)
{
	g_VehUsesVisuals[veh] = true;
	g_VehVisualsInfo[veh][vcWheelWidth] = offset;
	
	foreach(new i : streamed_players_in_veh[veh])
	{
		UpdateVehVisuals(i, veh);
	}
}

stock SetVehicleShadowParams(veh, sizeX, sizeY, r, g, b, texName[])
{
	g_VehUsesVisuals[veh] = true;
	g_VehVisualsInfo[veh][vcShadowColor][0] = r;
	g_VehVisualsInfo[veh][vcShadowColor][1] = g;
	g_VehVisualsInfo[veh][vcShadowColor][2] = b;
	
	g_VehVisualsInfo[veh][vcShadowSize][0] = sizeX;
	g_VehVisualsInfo[veh][vcShadowSize][1] = sizeY;
	
	g_VehVisualsInfo[veh][vcShadowTexName][0] = EOS;
	strins(g_VehVisualsInfo[veh][vcShadowTexName], texName, 0);
	
	foreach(new i : streamed_players_in_veh[veh])
	{
		UpdateVehVisuals(i, veh);
	}
}

stock SetVehicleLightsColors(veh, r, g, b)
{
	g_VehUsesVisuals[veh] = true;
	g_VehVisualsInfo[veh][vcLightsColor][0] = r;
	g_VehVisualsInfo[veh][vcLightsColor][1] = g;
	g_VehVisualsInfo[veh][vcLightsColor][2] = b;
	
	foreach(new i : streamed_players_in_veh[veh])
	{
		UpdateVehVisuals(i, veh);
	}
}

stock SetVehicleVinyls(veh, slot1, slot2)
{
	g_VehUsesVisuals[veh] = true;
	g_VehVisualsInfo[veh][vcVinyls][0] = slot1;
	g_VehVisualsInfo[veh][vcVinyls][1] = slot2;
	
	foreach(new i : streamed_players_in_veh[veh])
	{
		UpdateVehVisuals(i, veh);
	}
}

stock SetVehicleRuNumberPlate(veh, const szText[], const szRegion[])
{
	g_VehUsesVisuals[veh] = true;
	g_VehVisualsInfo[veh][vcPlateType] = 1;
	
	g_VehVisualsInfo[veh][vcPlateText][0] = EOS;
	g_VehVisualsInfo[veh][vcPlateRegion][0] = EOS;
	
	strins(g_VehVisualsInfo[veh][vcPlateText], szText, 0);
	strins(g_VehVisualsInfo[veh][vcPlateRegion], szRegion, 0);
	
	foreach(new i : streamed_players_in_veh[veh])
	{
		UpdateVehVisuals(i, veh);
	}
}

stock SetVehicleUaNumberPlate(veh, const szText[])
{
	g_VehUsesVisuals[veh] = true;
	g_VehVisualsInfo[veh][vcPlateType] = 2;
	
	g_VehVisualsInfo[veh][vcPlateText][0] = EOS;
	g_VehVisualsInfo[veh][vcPlateRegion][0] = EOS;
	
	strins(g_VehVisualsInfo[veh][vcPlateText], szText, 0);
	
	foreach(new i : streamed_players_in_veh[veh])
	{
		UpdateVehVisuals(i, veh);
	}
}

stock SetVehicleBuNumberPlate(veh, const szText[])
{
	g_VehUsesVisuals[veh] = true;
	g_VehVisualsInfo[veh][vcPlateType] = 3;
	
	g_VehVisualsInfo[veh][vcPlateText][0] = EOS;
	g_VehVisualsInfo[veh][vcPlateRegion][0] = EOS;
	
	strins(g_VehVisualsInfo[veh][vcPlateText], szText, 0);
	
	foreach(new i : streamed_players_in_veh[veh])
	{
		UpdateVehVisuals(i, veh);
	}
}

stock SetVehicleKzNumberPlate(veh, const szText[], const szRegion[])
{
	g_VehUsesVisuals[veh] = true;
	g_VehVisualsInfo[veh][vcPlateType] = 4;
	
	g_VehVisualsInfo[veh][vcPlateText][0] = EOS;
	g_VehVisualsInfo[veh][vcPlateRegion][0] = EOS;
	
	strins(g_VehVisualsInfo[veh][vcPlateText], szText, 0);
	strins(g_VehVisualsInfo[veh][vcPlateRegion], szRegion, 0);
	
	foreach(new i : streamed_players_in_veh[veh])
	{
		UpdateVehVisuals(i, veh);
	}
}

stock SetVehicleRuPolNumberPlate(veh, const szText[], const szRegion[])
{
	g_VehUsesVisuals[veh] = true;
	g_VehVisualsInfo[veh][vcPlateType] = 5;
	
	g_VehVisualsInfo[veh][vcPlateText][0] = EOS;
	g_VehVisualsInfo[veh][vcPlateRegion][0] = EOS;
	
	strins(g_VehVisualsInfo[veh][vcPlateText], szText, 0);
	strins(g_VehVisualsInfo[veh][vcPlateRegion], szRegion, 0);
	
	foreach(new i : streamed_players_in_veh[veh])
	{
		UpdateVehVisuals(i, veh);
	}
}

stock SetVehicleTaxiNumberPlate(veh, const szText[], const szRegion[])
{
	g_VehUsesVisuals[veh] = true;
	g_VehVisualsInfo[veh][vcPlateType] = 6;
	
	g_VehVisualsInfo[veh][vcPlateText][0] = EOS;
	g_VehVisualsInfo[veh][vcPlateRegion][0] = EOS;
	
	strins(g_VehVisualsInfo[veh][vcPlateText], szText, 0);
	strins(g_VehVisualsInfo[veh][vcPlateRegion], szRegion, 0);
	
	foreach(new i : streamed_players_in_veh[veh])
	{
		UpdateVehVisuals(i, veh);
	}
}

stock SetVehicleGosNumberPlate(veh, const szText[], const szRegion[])
{
	g_VehUsesVisuals[veh] = true;
	g_VehVisualsInfo[veh][vcPlateType] = 7;
	
	g_VehVisualsInfo[veh][vcPlateText][0] = EOS;
	g_VehVisualsInfo[veh][vcPlateRegion][0] = EOS;
	
	strins(g_VehVisualsInfo[veh][vcPlateText], szText, 0);
	strins(g_VehVisualsInfo[veh][vcPlateRegion], szRegion, 0);
	
	foreach(new i : streamed_players_in_veh[veh])
	{
		UpdateVehVisuals(i, veh);
	}
}

stock SetVehicleNoPlateNumberPlate(veh, const szText[], const szRegion[])
{
	g_VehUsesVisuals[veh] = true;
	g_VehVisualsInfo[veh][vcPlateType] = 1;
	
	g_VehVisualsInfo[veh][vcPlateText][0] = EOS;
	g_VehVisualsInfo[veh][vcPlateRegion][0] = EOS;
	
	strins(g_VehVisualsInfo[veh][vcPlateText], szText, 0);
	strins(g_VehVisualsInfo[veh][vcPlateRegion], szRegion, 0);
	
	foreach(new i : streamed_players_in_veh[veh])
	{
		UpdateVehVisuals(i, veh);
	}
}



stock ResetVehicleHandling(veh)
{
	ResetHandlingAttributes(veh);
	
	new BitStream:bitstream = BS_New();
	BS_WriteValue(bitstream, PR_UINT8, PACKET_CUSTOMRPC);
	BS_WriteValue(bitstream, PR_UINT32, RPC_CUSTOM_HANDLING_DEFAULTS);
	BS_WriteValue(bitstream, PR_UINT16, veh);
	
	foreach(new i : streamed_players_in_veh[veh])
	{
		BS_Send(bitstream, i, PR_HIGH_PRIORITY, PR_RELIABLE);
	}
	
	BS_Delete(bitstream);
} 

stock SetVehicleEngInert(veh, Float:value)
{
	g_VehUsesHandling[veh] = true;
	g_VehHandlingInfo[veh][hpEngineInertion] = value;
	foreach(new i : streamed_players_in_veh[veh])
	{
		UpdateVehHandling(i, veh);
	}
}

stock SetVehicleMass(veh, Float:mass)
{
	g_VehUsesHandling[veh] = true;
	g_VehHandlingInfo[veh][hpMass] = mass;
	foreach(new i : streamed_players_in_veh[veh])
	{
		UpdateVehHandling(i, veh);
	}
	return true;
}

stock SetVehicleMassTurn(veh, Float:mass)
{
	g_VehUsesHandling[veh] = true;
	g_VehHandlingInfo[veh][hpMassTurn] = mass;
	foreach(new i : streamed_players_in_veh[veh])
	{
		UpdateVehHandling(i, veh);
	}
}

stock SetVehicleMaxSpeed(veh, Float:max)
{
	g_VehUsesHandling[veh] = true;
	g_VehHandlingInfo[veh][hpMaxSpeed] = max;
	foreach(new i : streamed_players_in_veh[veh])
	{
		UpdateVehHandling(i, veh);
	}
}

stock SetVehicleAcceleration(veh, Float:acc)
{
	g_VehUsesHandling[veh] = true;
	g_VehHandlingInfo[veh][hpAcceleration] = acc;
	foreach(new i : streamed_players_in_veh[veh])
	{
		UpdateVehHandling(i, veh);
	}
}

stock SetVehicleGear(veh, Float:gear)
{
	g_VehUsesHandling[veh] = true;
	g_VehHandlingInfo[veh][hpGear] = gear;
	foreach(new i : streamed_players_in_veh[veh])
	{
		UpdateVehHandling(i, veh);
	}
}

stock SetVehicleBrakeCoef(veh, Float:coef)
{
	g_VehUsesHandling[veh] = true;
	g_VehHandlingInfo[veh][hpBrakeDeceleration] = coef;
	foreach(new i : streamed_players_in_veh[veh])
	{
		UpdateVehHandling(i, veh);
	}
}

stock SetVehicleTractionCoef(veh, Float:coef)
{
	g_VehUsesHandling[veh] = true;
	g_VehHandlingInfo[veh][hpTractionMultiplier] = coef;
	foreach(new i : streamed_players_in_veh[veh])
	{
		UpdateVehHandling(i, veh);
	}
}

stock SetVehicleTractionLoss(veh, Float:coef)
{
	g_VehUsesHandling[veh] = true;
	g_VehHandlingInfo[veh][hpTractionLoss] = coef;
	foreach(new i : streamed_players_in_veh[veh])
	{
		UpdateVehHandling(i, veh);
	}
}

stock SetVehicleTractionBias(veh, Float:coef)
{
	g_VehUsesHandling[veh] = true;
	g_VehHandlingInfo[veh][hpTractionBias] = coef;
	foreach(new i : streamed_players_in_veh[veh])
	{
		UpdateVehHandling(i, veh);
	}
}

stock SetVehicleSuspensionBias(veh, Float:coef)
{
	g_VehUsesHandling[veh] = true;
	g_VehHandlingInfo[veh][hpSuspensionBias] = coef;
	foreach(new i : streamed_players_in_veh[veh])
	{
		UpdateVehHandling(i, veh);
	}
}

stock SetVehicleWheelSize(veh, Float:coef)
{
	g_VehUsesHandling[veh] = true;
	g_VehHandlingInfo[veh][hpWheelSize] = coef;
	foreach(new i : streamed_players_in_veh[veh])
	{
		UpdateVehHandling(i, veh);
	}
}

stock SetVehicleSuspensionLower(veh, Float:coef)
{
	g_VehUsesHandling[veh] = true;
	g_VehHandlingInfo[veh][hpSuspensionLowerLimit] = coef;
	foreach(new i : streamed_players_in_veh[veh])
	{
		UpdateVehHandling(i, veh);
	}
}

stock ResetVehileComponentsDefault(veh)
{
	g_VehUsesCustomComponents[veh] = true;
	for(new i = 0; i < _:ccMax; i++)
	{
		g_VehComponentsInfo[veh][E_CUSTOM_COMPONENTS:i] = 0;
		BIT_SET(g_VehComponentsInfo[veh][E_CUSTOM_COMPONENTS:i], 0);
	}
	g_VehComponentsInfo[veh][ccExtra] = 0;
	
	BIT_SET(g_VehComponentsInfo[veh][ccExtra], EXTRA_COMPONENT_BOOT);
	BIT_SET(g_VehComponentsInfo[veh][ccExtra], EXTRA_COMPONENT_BONNET);
	BIT_SET(g_VehComponentsInfo[veh][ccExtra], EXTRA_COMPONENT_BUMP_REAR);
	BIT_SET(g_VehComponentsInfo[veh][ccExtra], EXTRA_COMPONENT_BUMP_FRONT);
	BIT_SET(g_VehComponentsInfo[veh][ccExtra], EXTRA_COMPONENT_DEFAULT_DOOR);
	BIT_SET(g_VehComponentsInfo[veh][ccExtra], EXTRA_COMPONENT_WHEEL);
}

stock ShowVehicleComponent(veh, group, subgroup)
{
	if(group != _:ccExtra)
	{
		g_VehComponentsInfo[veh][E_CUSTOM_COMPONENTS:group] = 0;
	}
	BIT_SET(g_VehComponentsInfo[veh][E_CUSTOM_COMPONENTS:group], subgroup);
	foreach(new i : streamed_players_in_veh[veh])
	{
		UpdateVehComponents(i, veh);
	}
}

stock HideAllVehComponents(veh, group)
{
	g_VehComponentsInfo[veh][E_CUSTOM_COMPONENTS:group] = 0;
	foreach(new i : streamed_players_in_veh[veh])
	{
		UpdateVehComponents(i, veh);
	}
}

stock HideVehComponent(veh, group, subgroup)
{
	BIT_CLEAR(g_VehComponentsInfo[veh][E_CUSTOM_COMPONENTS:group], subgroup);
	
	foreach(new i : streamed_players_in_veh[veh])
	{
		UpdateVehComponents(i, veh);
	}
}

stock UpdateVehComponents(playerid, veh)
{
	if(!g_VehUsesCustomComponents[veh])
	{
		return;
	}
	new BitStream:bitstream = BS_New();
	BS_WriteValue(bitstream, PR_UINT8, PACKET_CUSTOMRPC);
	BS_WriteValue(bitstream, PR_UINT32, RPC_CUSTOM_COMPONENT);
	BS_WriteValue(bitstream, PR_UINT16, veh);
	for(new i = 0; i < _:ccMax; i++)
	{
	    if(i == _:ccExtra)
	    {
	        BS_WriteValue(bitstream, PR_UINT16, g_VehComponentsInfo[veh][E_CUSTOM_COMPONENTS:i]);
	    }
	    else
	    {
	        BS_WriteValue(bitstream, PR_UINT8, g_VehComponentsInfo[veh][E_CUSTOM_COMPONENTS:i]);
	    }
	}
	BS_Send(bitstream, playerid, PR_HIGH_PRIORITY, PR_RELIABLE_ORDERED);
	BS_Delete(bitstream);
}
