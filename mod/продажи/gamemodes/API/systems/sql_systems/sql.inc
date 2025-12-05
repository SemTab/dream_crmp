new SQL:zConn;
new SQL:zConnLog;

new TickMax = 10000;
new SQLS;
new String256qsl[356];

stock Result:sql_queryEx(SQL:zConnEx, zResEx[], flagEx = QUERY_NONE, callbackEX[] = "", formatEX[] = "" )
{
	SQLS ++;
	new TickSt = GetTickCount();
	new Result:SQLRE;
	SQLRE = sql_query(zConnEx, zResEx, flagEx, callbackEX, formatEX);
	if(GetTickCount() - TickSt > TickMax)  
	{
		format(String256qsl,sizeof(String256qsl),"[MYSQL] Задержка %dms : %s",GetTickCount() - TickSt, zResEx);
		AdminChatEx(0x007fffff,String256qsl,8);
	}
	return SQLRE;
}

#define sql_query_format(%0,%1,%2,%3,%5,%6) sql_query(%0,%1,%2,%3,%5,%6)

new MySQL:connect_main;
new MySQL:connect_logs;

stock set_charset(MySQL:connect_id)
{
	mysql_set_charset("cp1251", connect_id);
	mysql_pquery(connect_id, !"SET CHARACTER SET 'utf8'");
	mysql_pquery(connect_id, !"SET NAMES 'utf8'");
	mysql_pquery(connect_id, !"SET character_set_client = 'cp1251'");
	mysql_pquery(connect_id, !"SET character_set_connection = 'cp1251'");
	mysql_pquery(connect_id, !"SET character_set_results = 'cp1251'");
	mysql_pquery(connect_id, !"SET SESSION collation_connection = 'utf8_general_ci'");
	return true;
}
