



stock show_eleveator_moscow_city(playerid)
{
	return SPD(playerid, DIALOG_ELEVATOR_MOSCOW_CITY, DIALOG_STYLE_INPUT, !""cBLUE"Лифт Москва Сити", !"\
	"cWH"Выберите этаж на который хотите подняться или опуститься\n\n\
	Этаж от 1 до 40", !"Далее", !"Назад");
}


stock exit_elevetor_moscow_city(playerid, level)
{

	SetPlayerVirtualWorld(playerid, level);
	SetPlayerPosEx(playerid, 501.7903,-376.4248,1201.9318,89.3965);
	SetCameraBehindPlayer(playerid);

	format(String144, sizeof(String144), "Вы приехали на лифте на %d этаж Москвы Сити!", level);
	SendSucc(playerid, String144);

	return true;
}