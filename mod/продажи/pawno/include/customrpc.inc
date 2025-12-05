#define PACKET_CUSTOMRPC 251

#define RPC_CUSTOM_SET_FUEL				0x23
#define RPC_CUSTOM_SET_MILEAGE		0x24
#define RPC_CUSTOM_SET_HUNGRY		0x25

stock UpdateFuel(playerid, Float:fuel)
{
    new BitStream:bitstream = BS_New();
	BS_WriteValue(bitstream, PR_UINT8, PACKET_CUSTOMRPC);
	BS_WriteValue(bitstream, PR_UINT32, RPC_CUSTOM_SET_FUEL);
	
	BS_WriteValue(bitstream, PR_FLOAT, fuel);
	
	BS_Send(bitstream, playerid);

	BS_Delete(bitstream);
}

stock UpdateMileage(playerid, Float:mileage)
{
    new BitStream:bitstream = BS_New();
	BS_WriteValue(bitstream, PR_UINT8, PACKET_CUSTOMRPC);
	BS_WriteValue(bitstream, PR_UINT32, RPC_CUSTOM_SET_MILEAGE);
	
	BS_WriteValue(bitstream, PR_FLOAT, mileage);
	
	BS_Send(bitstream, playerid);

	BS_Delete(bitstream);
}

stock UpdateHungry(playerid, Float:hungry)
{
	new BitStream:bitstream = BS_New();
	BS_WriteValue(bitstream, PR_UINT8, PACKET_CUSTOMRPC);
	BS_WriteValue(bitstream, PR_UINT32, RPC_CUSTOM_SET_HUNGRY);
	
	BS_WriteValue(bitstream, PR_FLOAT, hungry);
	
	BS_Send(bitstream, playerid);

	BS_Delete(bitstream);
}