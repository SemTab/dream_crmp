
callback:: voice_timer_active()
{
	VoiceChat_StartPushInfo();

	new 
		Float:pos_p_x, Float:pos_p_y, Float:pos_p_z;

	foreach(new i : Player)
	{	
		if(pData[i][pLevel] > 3)
		{
			GetPlayerPos(i, pos_p_x, pos_p_y, pos_p_z);
			VoiceChat_PushInfo(i, pos_p_x, pos_p_y, pos_p_z, GetPlayerVirtualWorld(i), false);
		}
	}
	VoiceChat_EndPushInfo();

}

stock hide_setting_voice_player(playerid)
{

	if(GetPVarIntNew(playerid, "active_setting_voice_chat") != 1)
		return true;

	TextDrawHideForPlayer(playerid, voice_global_td[0]);
	TextDrawHideForPlayer(playerid, voice_global_td[1]);
	TextDrawHideForPlayer(playerid, voice_global_td[2]);
	TextDrawHideForPlayer(playerid, voice_global_td[3]);
	TextDrawHideForPlayer(playerid, voice_global_td[4]);
	TextDrawHideForPlayer(playerid, voice_global_td[5]);

	PlayerTextDrawHideEx(playerid, voice_setting_player[0][playerid]);
	PlayerTextDrawHideEx(playerid, voice_setting_player[1][playerid]);
	PlayerTextDrawHideEx(playerid, voice_setting_player[2][playerid]);
	PlayerTextDrawHideEx(playerid, voice_setting_player[3][playerid]);
	PlayerTextDrawHideEx(playerid, voice_setting_player[4][playerid]);

	CancelSelectTextDraw(playerid);


	return true;
}

stock update_voice_setting_active(playerid)
{

	if(!pData[playerid][pVoiceStatus])
	{
		pData[playerid][pVoiceStatus] = 1;
		UpdatePlayerData(playerid, "pVoiceStatus", pData[playerid][pVoiceStatus]);

		PlayerTextDrawSetString(playerid, voice_setting_player[0][playerid], "brilliantother:voice_setting_on");
		PlayerTextDrawShow(playerid, voice_setting_player[0][playerid]);			
	}
	else
	{
		pData[playerid][pVoiceStatus] = 0;
		UpdatePlayerData(playerid, "pVoiceStatus", pData[playerid][pVoiceStatus]);

		PlayerTextDrawSetString(playerid, voice_setting_player[0][playerid], "brilliantother:voice_setting_off");
		PlayerTextDrawShow(playerid, voice_setting_player[0][playerid]);			
	}

	return true;
}

stock load_setting_voice_player(playerid)
{

	if(!pData[playerid][pVoiceStatus])
	{
		VoiceChat_MutePlayer(playerid);
	}
	else
	{
		VoiceChat_UnMutePlayer(playerid);
	}

	if(pData[playerid][pVoiceVolume] >= 25)
	{
		VoiceChat_SetVolume(playerid, 50);
	}
	else if(pData[playerid][pVoiceVolume] > 25 && pData[playerid][pVoiceVolume] <= 50)
	{
		VoiceChat_SetVolume(playerid, 100);
	}
	else if(pData[playerid][pVoiceVolume] > 50 && pData[playerid][pVoiceVolume] <= 75)
	{
		VoiceChat_SetVolume(playerid, 150);
	}
	else if(pData[playerid][pVoiceVolume] > 75 && pData[playerid][pVoiceVolume] <= 100)
	{		
		VoiceChat_SetVolume(playerid, 200);
	}
	return true;
}

CMD:vsetting(playerid)
{
	return show_setting_voice_player(playerid);
}

stock show_setting_voice_player(playerid)
{

	hide_setting_voice_player(playerid);

	TextDrawShowForPlayer(playerid, voice_global_td[0]);
	TextDrawShowForPlayer(playerid, voice_global_td[1]);
	TextDrawShowForPlayer(playerid, voice_global_td[2]);
	TextDrawShowForPlayer(playerid, voice_global_td[3]);
	TextDrawShowForPlayer(playerid, voice_global_td[4]);
	TextDrawShowForPlayer(playerid, voice_global_td[5]);


	create_voice_td_player(playerid);


	if(!pData[playerid][pVoiceStatus])
	{
		PlayerTextDrawSetString(playerid, voice_setting_player[0][playerid], "brilliantother:voice_setting_off");
		PlayerTextDrawShow(playerid, voice_setting_player[0][playerid]);			
	}
	else
	{
		PlayerTextDrawSetString(playerid, voice_setting_player[0][playerid], "brilliantother:voice_setting_on");
		PlayerTextDrawShow(playerid, voice_setting_player[0][playerid]);			
	}

	if(pData[playerid][pVoiceVolume] == 25)
	{
		PlayerTextDrawSetString(playerid, voice_setting_player[1][playerid], "brilliantother:voice_setting_25_select");
		PlayerTextDrawShow(playerid, voice_setting_player[1][playerid]);		
		PlayerTextDrawSetString(playerid, voice_setting_player[2][playerid], "brilliantother:voice_setting_50_no_select");
		PlayerTextDrawShow(playerid, voice_setting_player[2][playerid]);	
		PlayerTextDrawSetString(playerid, voice_setting_player[3][playerid], "brilliantother:voice_setting_75_no_select");
		PlayerTextDrawShow(playerid, voice_setting_player[3][playerid]);	
		PlayerTextDrawSetString(playerid, voice_setting_player[4][playerid], "brilliantother:voice_setting_100_no_select");
		PlayerTextDrawShow(playerid, voice_setting_player[4][playerid]);
	}
	else if(pData[playerid][pVoiceVolume] == 50)
	{

		PlayerTextDrawSetString(playerid, voice_setting_player[1][playerid], "brilliantother:voice_setting_25_no_select");
		PlayerTextDrawShow(playerid, voice_setting_player[1][playerid]);		
		PlayerTextDrawSetString(playerid, voice_setting_player[2][playerid], "brilliantother:voice_setting_50_select");
		PlayerTextDrawShow(playerid, voice_setting_player[2][playerid]);	
		PlayerTextDrawSetString(playerid, voice_setting_player[3][playerid], "brilliantother:voice_setting_75_no_select");
		PlayerTextDrawShow(playerid, voice_setting_player[3][playerid]);	
		PlayerTextDrawSetString(playerid, voice_setting_player[4][playerid], "brilliantother:voice_setting_100_no_select");
		PlayerTextDrawShow(playerid, voice_setting_player[4][playerid]);	
	}
	else if(pData[playerid][pVoiceVolume] == 75)
	{

		PlayerTextDrawSetString(playerid, voice_setting_player[1][playerid], "brilliantother:voice_setting_25_no_select");
		PlayerTextDrawShow(playerid, voice_setting_player[1][playerid]);		
		PlayerTextDrawSetString(playerid, voice_setting_player[2][playerid], "brilliantother:voice_setting_50_no_select");
		PlayerTextDrawShow(playerid, voice_setting_player[2][playerid]);	
		PlayerTextDrawSetString(playerid, voice_setting_player[3][playerid], "brilliantother:voice_setting_75_select");
		PlayerTextDrawShow(playerid, voice_setting_player[3][playerid]);	
		PlayerTextDrawSetString(playerid, voice_setting_player[4][playerid], "brilliantother:voice_setting_100_no_select");
		PlayerTextDrawShow(playerid, voice_setting_player[4][playerid]);	
	}
	else if(pData[playerid][pVoiceVolume] <= 100)
	{

		PlayerTextDrawSetString(playerid, voice_setting_player[1][playerid], "brilliantother:voice_setting_25_no_select");
		PlayerTextDrawShow(playerid, voice_setting_player[1][playerid]);		
		PlayerTextDrawSetString(playerid, voice_setting_player[2][playerid], "brilliantother:voice_setting_50_no_select");
		PlayerTextDrawShow(playerid, voice_setting_player[2][playerid]);	
		PlayerTextDrawSetString(playerid, voice_setting_player[3][playerid], "brilliantother:voice_setting_75_no_select");
		PlayerTextDrawShow(playerid, voice_setting_player[3][playerid]);	
		PlayerTextDrawSetString(playerid, voice_setting_player[4][playerid], "brilliantother:voice_setting_100_select");
		PlayerTextDrawShow(playerid, voice_setting_player[4][playerid]);	
	}

	SetPVarIntNew(playerid, "active_setting_voice_chat", 1);
	load_setting_voice_player(playerid);
	SelectTextDraw(playerid, COLOR_BLUE);

	return true;
}