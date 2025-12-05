native VoiceChat_Start(port, maxPeers, addr[]); // use this to start voice chat server
native VoiceChat_MutePlayer(playerid); // mutes player(ignore all incoming packets from this player)
native VoiceChat_UnMutePlayer(playerid); // unmutes player
native VoiceChat_Disconnect(playerid); // disconnects player from voice server
native VoiceChat_Ignore(ignore);	// call this when you should ignore all incoming packets
native VoiceChat_SetVolume(playerid, volume);	// set client volume
native VoiceChat_PushInfo(playerid, Float:posX, Float:posY, Float:posZ, vw, ispectating);	// this should be called every 100-200 ms to update data
native VoiceChat_StartPushInfo(); // call this every time before starting push info
native VoiceChat_EndPushInfo(); // call this every time after ended push info
native VoiceChat_ResetPushInfo(); // call this when you have to break push info