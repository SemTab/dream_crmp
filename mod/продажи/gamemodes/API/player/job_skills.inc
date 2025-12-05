enum
{

	FOR_WOOD_SKILL_1			=	100,
	FOR_WOOD_SKILL_2			=	200,
	FOR_WOOD_SKILL_3			=	300,
	FOR_WOOD_SKILL_4			=	400,
	FOR_WOOD_SKILL_5			=	500,

	FOR_MINE_SKILL_1			=	50,
	FOR_MINE_SKILL_2			=	150,
	FOR_MINE_SKILL_3			=	250,
	FOR_MINE_SKILL_4			=	400,
	FOR_MINE_SKILL_5			=	500,

	FOR_BUS_SKILL_1				=	100, 
	FOR_BUS_SKILL_2				=	200,
	FOR_BUS_SKILL_3				=	300,
	FOR_BUS_SKILL_4				=	400,
	FOR_BUS_SKILL_5				=	500,

	FOR_TRUCKER_SKILL_1			=	100,
	FOR_TRUCKER_SKILL_2			=	200,
	FOR_TRUCKER_SKILL_3			=	300,
	FOR_TRUCKER_SKILL_4			=	400,
	FOR_TRUCKER_SKILL_5			=	500,

	FOR_FACTORY_SKILL_1			=	100,
	FOR_FACTORY_SKILL_2			=	200,
	FOR_FACTORY_SKILL_3			=	300,
	FOR_FACTORY_SKILL_4			=	400,
	FOR_FACTORY_SKILL_5			=	500,


	FOR_TAXI_SKILL_1			=	100,
	FOR_TAXI_SKILL_2			=	200,
	FOR_TAXI_SKILL_3			=	300,
	FOR_TAXI_SKILL_4			=	400,
	FOR_TAXI_SKILL_5			=	500,

	FOR_MECHANIC_SKILL_1		=	100,
	FOR_MECHANIC_SKILL_2		=	200,
	FOR_MECHANIC_SKILL_3		=	300,
	FOR_MECHANIC_SKILL_4		=	400,
	FOR_MECHANIC_SKILL_5		=	500,

	FOR_SNOW_DRIVER_SKILL_1		=	100,
	FOR_SNOW_DRIVER_SKILL_2		=	200,
	FOR_SNOW_DRIVER_SKILL_3		=	300,
	FOR_SNOW_DRIVER_SKILL_4		=	400,
	FOR_SNOW_DRIVER_SKILL_5		=	500,

	FOR_FIRE_SKILL_1			=	50,
	FOR_FIRE_SKILL_2			=	150,
	FOR_FIRE_SKILL_3			=	250,
	FOR_FIRE_SKILL_4			=	400,
	FOR_FIRE_SKILL_5			=	500,

	FOR_BANK_DRIVER_SKILL_1		=	100,
	FOR_BANK_DRIVER_SKILL_2		=	200,
	FOR_BANK_DRIVER_SKILL_3		=	300,
	FOR_BANK_DRIVER_SKILL_4		=	400,
	FOR_BANK_DRIVER_SKILL_5		=	500,

	FOR_TRASH_DRIVER_SKILL_1	=	100,
	FOR_TRASH_DRIVER_SKILL_2	=	200,
	FOR_TRASH_DRIVER_SKILL_3	=	300,
	FOR_TRASH_DRIVER_SKILL_4	=	400,
	FOR_TRASH_DRIVER_SKILL_5	=	500,

	FOR_FISH_WORK_SKILL_1		=	100,
	FOR_FISH_WORK_SKILL_2		=	200,
	FOR_FISH_WORK_SKILL_3		=	300,
	FOR_FISH_WORK_SKILL_4		=	400,
	FOR_FISH_WORK_SKILL_5		=	500

};


stock get_job_skill(playerid, type)
{
	return pData[playerid][job_skill][type];
}

stock get_job_level(playerid, type)
{
	new 
		skill = pData[playerid][job_skill][type];

	switch(type)
	{

		case SKILL_MINER:
		{
			switch(skill)
			{
				case 0 .. FOR_MINE_SKILL_1 - 1: return 1;
				case FOR_MINE_SKILL_1 .. FOR_MINE_SKILL_2 - 1: return 2;
				case FOR_MINE_SKILL_2 .. FOR_MINE_SKILL_3 - 1: return 3;
				case FOR_MINE_SKILL_3 .. FOR_MINE_SKILL_5 - 1: return 4;
				default: return 5;
			}
		}

		case SKILL_WOODCUTTER:
		{
			switch(skill)
			{
				case 0 .. FOR_WOOD_SKILL_1 - 1: return 1;
				case FOR_WOOD_SKILL_1 .. FOR_WOOD_SKILL_2 - 1: return 2;
				case FOR_WOOD_SKILL_2 .. FOR_WOOD_SKILL_3 - 1: return 3;
				case FOR_WOOD_SKILL_3 .. FOR_WOOD_SKILL_5 - 1: return 4;
				default: return 5;
			}
		}
		case SKILL_BUS_DRIVER:
		{
			switch(skill)
			{
				case 0 .. FOR_BUS_SKILL_1 - 1: return 1;
				case FOR_BUS_SKILL_1 .. FOR_BUS_SKILL_2 - 1: return 2;
				case FOR_BUS_SKILL_2 .. FOR_BUS_SKILL_3 - 1: return 3;
				case FOR_BUS_SKILL_3 .. FOR_BUS_SKILL_5 - 1: return 4;
				default: return 5;
			}
		}
		case SKILL_TRUCKER:
		{
			switch(skill)
			{
				case 0 .. FOR_TRUCKER_SKILL_1 - 1: return 1;
				case FOR_TRUCKER_SKILL_1 .. FOR_TRUCKER_SKILL_2 - 1: return 2;
				case FOR_TRUCKER_SKILL_2 .. FOR_TRUCKER_SKILL_3 - 1: return 3;
				case FOR_TRUCKER_SKILL_3 .. FOR_TRUCKER_SKILL_5 - 1: return 4;
				default: return 5;
			}			
		}
		case SKILL_FACTORY:
		{
			switch(skill)
			{
				case 0 .. FOR_FACTORY_SKILL_1 - 1: return 1;
				case FOR_FACTORY_SKILL_1 .. FOR_FACTORY_SKILL_2 - 1: return 2;
				case FOR_FACTORY_SKILL_2 .. FOR_FACTORY_SKILL_3 - 1: return 3;
				case FOR_FACTORY_SKILL_3 .. FOR_FACTORY_SKILL_5 - 1: return 4;
				default: return 5;
			}	
		}
		case SKILL_TAXI:
		{
			switch(skill)
			{
				case 0 .. FOR_TAXI_SKILL_1 - 1: return 1;
				case FOR_TAXI_SKILL_1 .. FOR_TAXI_SKILL_2 - 1: return 2;
				case FOR_TAXI_SKILL_2 .. FOR_TAXI_SKILL_3 - 1: return 3;
				case FOR_TAXI_SKILL_3 .. FOR_TAXI_SKILL_5 - 1: return 4;
				default: return 5;
			}	
		}
		case SKILL_MECHANIC:
		{
			switch(skill)
			{
				case 0 .. FOR_MECHANIC_SKILL_1 - 1: return 1;
				case FOR_MECHANIC_SKILL_1 .. FOR_MECHANIC_SKILL_2 - 1: return 2;
				case FOR_MECHANIC_SKILL_2 .. FOR_MECHANIC_SKILL_3 - 1: return 3;
				case FOR_MECHANIC_SKILL_3 .. FOR_MECHANIC_SKILL_5 - 1: return 4;
				default: return 5;
			}	
		}
		case SKILL_SNOWWORK:
		{
			switch(skill)
			{
				case 0 .. FOR_SNOW_DRIVER_SKILL_1 - 1: return 1;
				case FOR_SNOW_DRIVER_SKILL_1 .. FOR_SNOW_DRIVER_SKILL_2 - 1: return 2;
				case FOR_SNOW_DRIVER_SKILL_2 .. FOR_SNOW_DRIVER_SKILL_3 - 1: return 3;
				case FOR_SNOW_DRIVER_SKILL_3 .. FOR_SNOW_DRIVER_SKILL_5 - 1: return 4;
				default: return 5;
			}	
		}
		case SKILL_FIRE:
		{
			switch(skill)
			{
				case 0 .. FOR_FIRE_SKILL_1 - 1: return 1;
				case FOR_FIRE_SKILL_1 .. FOR_FIRE_SKILL_2 - 1: return 2;
				case FOR_FIRE_SKILL_2 .. FOR_FIRE_SKILL_3 - 1: return 3;
				case FOR_FIRE_SKILL_3 .. FOR_FIRE_SKILL_5 - 1: return 4;
				default: return 5;
			}	
		}
		case SKILL_BANK:
		{
			switch(skill)
			{
				case 0 .. FOR_BANK_DRIVER_SKILL_1 - 1: return 1;
				case FOR_BANK_DRIVER_SKILL_1 .. FOR_BANK_DRIVER_SKILL_2 - 1: return 2;
				case FOR_BANK_DRIVER_SKILL_2 .. FOR_BANK_DRIVER_SKILL_3 - 1: return 3;
				case FOR_BANK_DRIVER_SKILL_3 .. FOR_BANK_DRIVER_SKILL_5 - 1: return 4;
				default: return 5;
			}	

		}
		case SKILL_PICKER:
		{

			switch(skill)
			{
				case 0 .. FOR_TRASH_DRIVER_SKILL_1 - 1: return 1;
				case FOR_TRASH_DRIVER_SKILL_1 .. FOR_TRASH_DRIVER_SKILL_2 - 1: return 2;
				case FOR_TRASH_DRIVER_SKILL_2 .. FOR_TRASH_DRIVER_SKILL_3 - 1: return 3;
				case FOR_TRASH_DRIVER_SKILL_3 .. FOR_TRASH_DRIVER_SKILL_5 - 1: return 4;
				default: return 5;
			}	
			
		}
		case SKILL_FISHER:
		{
			switch(skill)
			{
				case 0 .. FOR_FISH_WORK_SKILL_1 - 1: return 1;
				case FOR_FISH_WORK_SKILL_1 .. FOR_FISH_WORK_SKILL_2 - 1: return 2;
				case FOR_FISH_WORK_SKILL_2 .. FOR_FISH_WORK_SKILL_3 - 1: return 3;
				case FOR_FISH_WORK_SKILL_3 .. FOR_FISH_WORK_SKILL_5 - 1: return 4;
				default: return 5;
			}	
		}
	}
	return true;
}

stock get_job_level_next(playerid, type)
{
	new 
		skill = pData[playerid][job_skill][type];

	switch(type)
	{

		case SKILL_MINER:
		{
			switch(skill)
			{
				case 0 .. FOR_MINE_SKILL_1 - 1: return FOR_MINE_SKILL_1 - skill;
				case FOR_MINE_SKILL_1 .. FOR_MINE_SKILL_2 - 1: return FOR_MINE_SKILL_2 - skill;
				case FOR_MINE_SKILL_2 .. FOR_MINE_SKILL_3 - 1: return FOR_MINE_SKILL_3 - skill;
				case FOR_MINE_SKILL_3 .. FOR_MINE_SKILL_4 - 1: return FOR_MINE_SKILL_4 - skill;
				case FOR_MINE_SKILL_4 .. FOR_MINE_SKILL_5 - 1: return FOR_MINE_SKILL_5 - skill;
				default: return 0;
			}
		}		

		case SKILL_WOODCUTTER:
		{
			switch(skill)
			{
				case 0 .. FOR_WOOD_SKILL_1 - 1: return FOR_WOOD_SKILL_1 - skill;
				case FOR_WOOD_SKILL_1 .. FOR_WOOD_SKILL_2 - 1: return FOR_WOOD_SKILL_2 - skill;
				case FOR_WOOD_SKILL_2 .. FOR_WOOD_SKILL_3 - 1: return FOR_WOOD_SKILL_3 - skill;
				case FOR_WOOD_SKILL_3 .. FOR_WOOD_SKILL_4 - 1: return FOR_WOOD_SKILL_4 - skill;
				case FOR_WOOD_SKILL_4 .. FOR_WOOD_SKILL_5 - 1: return FOR_WOOD_SKILL_5 - skill;
				default: return 0;
			}
		}
		case SKILL_BUS_DRIVER:
		{
			switch(skill)
			{
				case 0 .. FOR_BUS_SKILL_1 - 1: return FOR_BUS_SKILL_1 - skill;
				case FOR_BUS_SKILL_1 .. FOR_BUS_SKILL_2 - 1: return FOR_BUS_SKILL_2 - skill;
				case FOR_BUS_SKILL_2 .. FOR_BUS_SKILL_3 - 1: return FOR_BUS_SKILL_3 - skill;
				case FOR_BUS_SKILL_3 .. FOR_BUS_SKILL_4 - 1: return FOR_BUS_SKILL_4 - skill;
				case FOR_BUS_SKILL_4 .. FOR_BUS_SKILL_5 - 1: return FOR_BUS_SKILL_5 - skill;
				default: return 0;
			}			
		}
		case SKILL_TRUCKER:
		{
			switch(skill)
			{
				case 0 .. FOR_TRUCKER_SKILL_1 - 1: return FOR_TRUCKER_SKILL_1 - skill;
				case FOR_TRUCKER_SKILL_1 .. FOR_TRUCKER_SKILL_2 - 1: return FOR_TRUCKER_SKILL_2 - skill;
				case FOR_TRUCKER_SKILL_2 .. FOR_TRUCKER_SKILL_3 - 1: return FOR_TRUCKER_SKILL_3 - skill;
				case FOR_TRUCKER_SKILL_3 .. FOR_TRUCKER_SKILL_4 - 1: return FOR_TRUCKER_SKILL_4 - skill;
				case FOR_TRUCKER_SKILL_4 .. FOR_TRUCKER_SKILL_5 - 1: return FOR_TRUCKER_SKILL_5 - skill;
				default: return 0;
			}			
		}

		case SKILL_FACTORY:
		{
			switch(skill)
			{
				case 0 .. FOR_FACTORY_SKILL_1 - 1: return FOR_FACTORY_SKILL_1 - skill;
				case FOR_FACTORY_SKILL_1 .. FOR_FACTORY_SKILL_2 - 1: return FOR_FACTORY_SKILL_2 - skill;
				case FOR_FACTORY_SKILL_2 .. FOR_FACTORY_SKILL_3 - 1: return FOR_FACTORY_SKILL_3 - skill;
				case FOR_FACTORY_SKILL_3 .. FOR_FACTORY_SKILL_4 - 1: return FOR_FACTORY_SKILL_4 - skill;
				case FOR_FACTORY_SKILL_4 .. FOR_FACTORY_SKILL_5 - 1: return FOR_FACTORY_SKILL_5 - skill;
				default: return 0;
			}			
		}
		case SKILL_TAXI:
		{
			switch(skill)
			{
				case 0 .. FOR_TAXI_SKILL_1 - 1: return FOR_TAXI_SKILL_1 - skill;
				case FOR_TAXI_SKILL_1 .. FOR_TAXI_SKILL_2 - 1: return FOR_TAXI_SKILL_2 - skill;
				case FOR_TAXI_SKILL_2 .. FOR_TAXI_SKILL_3 - 1: return FOR_TAXI_SKILL_3 - skill;
				case FOR_TAXI_SKILL_3 .. FOR_TAXI_SKILL_4 - 1: return FOR_TAXI_SKILL_4 - skill;
				case FOR_TAXI_SKILL_4 .. FOR_TAXI_SKILL_5 - 1: return FOR_TAXI_SKILL_5 - skill;
				default: return 0;
			}			
		}
		case SKILL_MECHANIC:
		{
			switch(skill)
			{
				case 0 .. FOR_MECHANIC_SKILL_1 - 1: return FOR_MECHANIC_SKILL_1 - skill;
				case FOR_MECHANIC_SKILL_1 .. FOR_MECHANIC_SKILL_2 - 1: return FOR_MECHANIC_SKILL_2 - skill;
				case FOR_MECHANIC_SKILL_2 .. FOR_MECHANIC_SKILL_3 - 1: return FOR_MECHANIC_SKILL_3 - skill;
				case FOR_MECHANIC_SKILL_3 .. FOR_MECHANIC_SKILL_4 - 1: return FOR_MECHANIC_SKILL_4 - skill;
				case FOR_MECHANIC_SKILL_4 .. FOR_MECHANIC_SKILL_5 - 1: return FOR_MECHANIC_SKILL_5 - skill;
				default: return 0;
			}			
		}
		case SKILL_SNOWWORK:
		{
			switch(skill)
			{
				case 0 .. FOR_SNOW_DRIVER_SKILL_1 - 1: return FOR_SNOW_DRIVER_SKILL_1 - skill;
				case FOR_SNOW_DRIVER_SKILL_1 .. FOR_SNOW_DRIVER_SKILL_2 - 1: return FOR_SNOW_DRIVER_SKILL_2 - skill;
				case FOR_SNOW_DRIVER_SKILL_2 .. FOR_SNOW_DRIVER_SKILL_3 - 1: return FOR_SNOW_DRIVER_SKILL_3 - skill;
				case FOR_SNOW_DRIVER_SKILL_3 .. FOR_SNOW_DRIVER_SKILL_4 - 1: return FOR_SNOW_DRIVER_SKILL_4 - skill;
				case FOR_SNOW_DRIVER_SKILL_4 .. FOR_SNOW_DRIVER_SKILL_5 - 1: return FOR_SNOW_DRIVER_SKILL_5 - skill;
				default: return 0;
			}
		}
	
		case SKILL_FIRE:
		{
			switch(skill)
			{
				case 0 .. FOR_FIRE_SKILL_1 - 1: return FOR_FIRE_SKILL_1 - skill;
				case FOR_FIRE_SKILL_1 .. FOR_FIRE_SKILL_2 - 1: return FOR_FIRE_SKILL_2 - skill;
				case FOR_FIRE_SKILL_2 .. FOR_FIRE_SKILL_3 - 1: return FOR_FIRE_SKILL_3 - skill;
				case FOR_FIRE_SKILL_3 .. FOR_FIRE_SKILL_4 - 1: return FOR_FIRE_SKILL_4 - skill;
				case FOR_FIRE_SKILL_4 .. FOR_FIRE_SKILL_5 - 1: return FOR_FIRE_SKILL_5 - skill;
				default: return 0;
			}
		}
		case SKILL_BANK:
		{
			switch(skill)
			{
				case 0 .. FOR_BANK_DRIVER_SKILL_1 - 1: return FOR_BANK_DRIVER_SKILL_1 - skill;
				case FOR_BANK_DRIVER_SKILL_1 .. FOR_BANK_DRIVER_SKILL_2 - 1: return FOR_BANK_DRIVER_SKILL_2 - skill;
				case FOR_BANK_DRIVER_SKILL_2 .. FOR_BANK_DRIVER_SKILL_3 - 1: return FOR_BANK_DRIVER_SKILL_3 - skill;
				case FOR_BANK_DRIVER_SKILL_3 .. FOR_BANK_DRIVER_SKILL_4 - 1: return FOR_BANK_DRIVER_SKILL_4 - skill;
				case FOR_BANK_DRIVER_SKILL_4 .. FOR_BANK_DRIVER_SKILL_5 - 1: return FOR_BANK_DRIVER_SKILL_5 - skill;
				default: return 0;
			}
		}
		case SKILL_PICKER:
		{

			switch(skill)
			{
				case 0 .. FOR_TRASH_DRIVER_SKILL_1 - 1: return FOR_TRASH_DRIVER_SKILL_1 - skill;
				case FOR_TRASH_DRIVER_SKILL_1 .. FOR_TRASH_DRIVER_SKILL_2 - 1: return FOR_TRASH_DRIVER_SKILL_2 - skill;
				case FOR_TRASH_DRIVER_SKILL_2 .. FOR_TRASH_DRIVER_SKILL_3 - 1: return FOR_TRASH_DRIVER_SKILL_3 - skill;
				case FOR_TRASH_DRIVER_SKILL_3 .. FOR_TRASH_DRIVER_SKILL_4 - 1: return FOR_TRASH_DRIVER_SKILL_4 - skill;
				case FOR_TRASH_DRIVER_SKILL_4 .. FOR_TRASH_DRIVER_SKILL_5 - 1: return FOR_TRASH_DRIVER_SKILL_5 - skill;
				default: return 0;
			}
			
		}

		case SKILL_FISHER:
		{

			switch(skill)
			{
				case 0 .. FOR_FISH_WORK_SKILL_1 - 1: return FOR_FISH_WORK_SKILL_1 - skill;
				case FOR_FISH_WORK_SKILL_1 .. FOR_FISH_WORK_SKILL_2 - 1: return FOR_FISH_WORK_SKILL_2 - skill;
				case FOR_FISH_WORK_SKILL_2 .. FOR_FISH_WORK_SKILL_3 - 1: return FOR_FISH_WORK_SKILL_3 - skill;
				case FOR_FISH_WORK_SKILL_3 .. FOR_FISH_WORK_SKILL_4 - 1: return FOR_FISH_WORK_SKILL_4 - skill;
				case FOR_FISH_WORK_SKILL_4 .. FOR_FISH_WORK_SKILL_5 - 1: return FOR_FISH_WORK_SKILL_5 - skill;
				default: return 0;
			}
			
		}

	}

	return true;
}


stock add_player_job_skill(playerid, JOB, count = 1)
{
	pData[playerid][job_skill][JOB] += count;

	return true;
}

stock get_job_name(job_id)
{
	new 
		name[30];

	switch(job_id)
	{
		case SKILL_MINER: name = "Шахтер";
		case SKILL_BUS_DRIVER: name = "Водитель автобуса";
		case SKILL_TRUCKER: name = "Дальнобойщик";
		case SKILL_WOODCUTTER: name = "Лесоруб";
		case SKILL_FACTORY: name = "Рабочий завода";
		case SKILL_TAXI: name = "Таксист";
		case SKILL_MECHANIC: name = "Механик";
		case SKILL_SNOWWORK: name = "Снегоуборщик";
		case SKILL_FIRE: name = "Пожарный";
		case SKILL_BANK: name = "Инкассатор";
		case SKILL_PICKER: name = "Водитель мусоровоза";
		case SKILL_FISHER: name = "Рыболов";
	}
	return name;
}