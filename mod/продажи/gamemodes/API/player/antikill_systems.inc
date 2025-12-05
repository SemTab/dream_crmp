
// Доработать

new 
	player_forward_damage[MAX_PLAYERS][3],
	player_defense_damage[MAX_PLAYERS][3];

stock disconnect_player_antikill(playerid)
{

	player_forward_damage[playerid][0] = INVALID_PLAYER_ID;
	player_forward_damage[playerid][1] = INVALID_PLAYER_ID;
	player_forward_damage[playerid][2] = INVALID_PLAYER_ID;

	player_defense_damage[playerid][0] = INVALID_PLAYER_ID;
	player_defense_damage[playerid][1] = INVALID_PLAYER_ID;
	player_defense_damage[playerid][2] = INVALID_PLAYER_ID;
	return true;
}

callback:: update_params_antikill(playerid, issuerid, Float:amount)
{

	if(issuerid != INVALID_PLAYER_ID)
	{
		if(amount > 7.5)
		{
			if(player_defense_damage[issuerid][0] == INVALID_PLAYER_ID)
			{
				if(player_defense_damage[issuerid][0] != playerid)
				{
					player_forward_damage[issuerid][0] = playerid;
					player_defense_damage[playerid][0] = issuerid;

					format(String144, sizeof(String144), "[ANTI-DM] Урон игрока %s[%d] была определен как нападение "cLRED"без самообороны"cGR" на %s[%d]!", pData[issuerid][pNickname], issuerid, pData[playerid][pNickname], playerid);
					SendClientMessageToAll(CGRAY,  String144);

				}
				else if(player_defense_damage[issuerid][0] == playerid)
				{
					format(String144, sizeof(String144), "[ANTI-DM] Урон игрока %s[%d] была определен как "cGR"самооборона"cGR" от %s[%d]!", pData[issuerid][pNickname], issuerid, pData[player_defense_damage[issuerid][0]][pNickname], playerid);
					SendClientMessageToAll(CGRAY,  String144);
				}
			}
			else if(player_defense_damage[issuerid][1] == INVALID_PLAYER_ID)
			{
				if(player_defense_damage[issuerid][1] != playerid)
				{
					player_forward_damage[issuerid][1] = playerid;
					player_defense_damage[playerid][1] = issuerid;

					format(String144, sizeof(String144), "[ANTI-DM] Урон игрока %s[%d] была определен как нападение "cLRED"без самообороны"cGR" на %s[%d]!", pData[issuerid][pNickname], issuerid, pData[playerid][pNickname], playerid);
					SendClientMessageToAll(CGRAY,  String144);

				}
				else if(player_defense_damage[issuerid][1] == playerid)
				{
					format(String144, sizeof(String144), "[ANTI-DM] Урон игрока %s[%d] была определен как "cGR"самооборона"cGR" от %s[%d]!", pData[issuerid][pNickname], issuerid, pData[player_defense_damage[issuerid][1]][pNickname], playerid);
					SendClientMessageToAll(CGRAY,  String144);
				}
			}
			else if(player_defense_damage[issuerid][2] == INVALID_PLAYER_ID)
			{
				if(player_defense_damage[issuerid][2] != playerid)
				{
					player_forward_damage[issuerid][2] = playerid;
					player_defense_damage[playerid][2] = issuerid;

					format(String144, sizeof(String144), "[ANTI-DM] Урон игрока %s[%d] была определен как нападение "cLRED"без самообороны"cGR" на %s[%d]!", pData[issuerid][pNickname], issuerid, pData[playerid][pNickname], playerid);
					SendClientMessageToAll(CGRAY,  String144);

				}
				else if(player_defense_damage[issuerid][2] == playerid)
				{
					format(String144, sizeof(String144), "[ANTI-DM] Урон игрока %s[%d] была определен как "cGR"самооборона"cGR" от %s[%d]!", pData[issuerid][pNickname], issuerid, pData[player_defense_damage[issuerid][2]][pNickname], playerid);
					SendClientMessageToAll(CGRAY,  String144);
				}
			}
		}

	}

	return true;
}

callback:: death_params_antikill(playerid, killerid)
{

	if(killerid != INVALID_PLAYER_ID)
	{

		if(player_defense_damage[killerid][0] == INVALID_PLAYER_ID)
		{
			if(player_defense_damage[killerid][0] != playerid)
			{
				player_forward_damage[killerid][0] = playerid;
				player_defense_damage[playerid][0] = killerid;

				format(String144, sizeof(String144), "[ANTI-DM] Убийством игроком %s[%d] была определен как нападение "cLRED"без самообороны"cGR" на %s[%d]!", pData[killerid][pNickname], killerid, pData[playerid][pNickname], playerid);
				SendClientMessageToAll(CGRAY,  String144);

			}
			else if(player_defense_damage[killerid][0] == playerid)
			{
				format(String144, sizeof(String144), "[ANTI-DM] Убийством игроком %s[%d] была определен как "cGR"самооборона"cGR" от %s[%d]!", pData[killerid][pNickname], killerid, pData[player_defense_damage[killerid][0]][pNickname], playerid);
				SendClientMessageToAll(CGRAY,  String144);
			}
		}
		else if(player_defense_damage[killerid][1] == INVALID_PLAYER_ID)
		{
			if(player_defense_damage[killerid][1] != playerid)
			{
				player_forward_damage[killerid][1] = playerid;
				player_defense_damage[playerid][1] = killerid;

				format(String144, sizeof(String144), "[ANTI-DM] Убийством игроком %s[%d] была определен как нападение "cLRED"без самообороны"cGR" на %s[%d]!", pData[killerid][pNickname], killerid, pData[playerid][pNickname], playerid);
				SendClientMessageToAll(CGRAY,  String144);

			}
			else if(player_defense_damage[killerid][1] == playerid)
			{
				format(String144, sizeof(String144), "[ANTI-DM] Убийством игроком %s[%d] была определен как "cGR"самооборона"cGR" от %s[%d]!", pData[killerid][pNickname], killerid, pData[player_defense_damage[killerid][1]][pNickname], playerid);
				SendClientMessageToAll(CGRAY,  String144);
			}
		}
		else if(player_defense_damage[killerid][2] == INVALID_PLAYER_ID)
		{
			if(player_defense_damage[killerid][2] != playerid)
			{
				player_forward_damage[killerid][2] = playerid;
				player_defense_damage[playerid][2] = killerid;

				format(String144, sizeof(String144), "[ANTI-DM] Убийством игроком %s[%d] была определен как нападение "cLRED"без самообороны"cGR" на %s[%d]!", pData[killerid][pNickname], killerid, pData[playerid][pNickname], playerid);
				SendClientMessageToAll(CGRAY,  String144);

			}
			else if(player_defense_damage[killerid][2] == playerid)
			{
				format(String144, sizeof(String144), "[ANTI-DM] Убийством игроком %s[%d] была определен как "cGR"самооборона"cGR" от %s[%d]!", pData[killerid][pNickname], killerid, pData[player_defense_damage[killerid][2]][pNickname], playerid);
				SendClientMessageToAll(CGRAY,  String144);
			}
		}

	}	


	return true;
}