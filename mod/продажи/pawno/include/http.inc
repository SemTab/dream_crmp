
#define MAX_PHP_LENGTH 256
 
forward OnServerTryingToRunPHP(index, response_code, data[]);
forward OnScriptResponse(scriptid, contents[]);
 
stock RunMySQLQuerySwitch(scriptid, const switch_case[])
{
        new string[MAX_PHP_LENGTH+5];
        format(string, sizeof(string), "?&message=%s", switch_case);
        HTTP(scriptid, HTTP_POST, "b-rp.ru/mybot/vk_sender.php", string, "OnServerTryingToRunPHP");
}
 
public OnServerTryingToRunPHP(index, response_code, data[])
{
        if(response_code != 200)
        {
                printf("Error: %d, trying to compile PHP on external server.", response_code);
                return 0;
        }
        CallLocalFunction("OnScriptResponse", "ds", index, data); // Возвращаем ответ в Pawn код
        return 1;
} 