#define PACKET_CUSTOMRPC    			251
#define RPC_SHOW_NOTIFICATION      0x32

stock EROM(playerid, type, const text[], duration, const actionforBtn[], const textBtn[])
{
    new BitStream:bitstream = BS_New();
    BS_WriteValue(bitstream, PR_UINT8, PACKET_CUSTOMRPC);
    BS_WriteValue(bitstream, PR_UINT32, RPC_SHOW_NOTIFICATION);
    
    BS_WriteValue(bitstream, PR_INT32, type);
    
    BS_WriteValue(bitstream, PR_UINT16, strlen(text));
    BS_WriteValue(bitstream, PR_STRING, text);
    
    BS_WriteValue(bitstream, PR_INT32, duration);
    
    BS_WriteValue(bitstream, PR_UINT16, strlen(actionforBtn));
    BS_WriteValue(bitstream, PR_STRING, actionforBtn);
    
    BS_WriteValue(bitstream, PR_UINT16, strlen(textBtn));
    BS_WriteValue(bitstream, PR_STRING, textBtn);
    
    BS_Send(bitstream, playerid, PR_HIGH_PRIORITY, PR_RELIABLE);

    BS_Delete(bitstream);

	return true;
}