

stock show_info_gui(playerid, status)
{
	switch(status)
	{
		case TEXTDRAW_SHOW:
		{	
			if(!pData[playerid][pSettings][13])
				return true;

			TextDrawShowForPlayer(playerid, start_info_player_1[0]);
			TextDrawShowForPlayer(playerid, start_info_player_1[1]);
			TextDrawShowForPlayer(playerid, start_info_player_1[2]);
			TextDrawShowForPlayer(playerid, start_info_player_1[3]);
			TextDrawShowForPlayer(playerid, start_info_player_1[4]);
			TextDrawShowForPlayer(playerid, start_info_player_1[5]);
		}
		case TEXTDRAW_HIDE:
		{
			TextDrawHideForPlayer(playerid, start_info_player_1[0]);
			TextDrawHideForPlayer(playerid, start_info_player_1[1]);
			TextDrawHideForPlayer(playerid, start_info_player_1[2]);
			TextDrawHideForPlayer(playerid, start_info_player_1[3]);
			TextDrawHideForPlayer(playerid, start_info_player_1[4]);
			TextDrawHideForPlayer(playerid, start_info_player_1[5]);
		}
	}
	return true;
}