

#include <..\..\gamemodes\API\systems\organisation_systems\organisation_army\army_systems_general.inc>
#include <..\..\gamemodes\API\systems\organisation_systems\organisation_federal\federal_systems_general.inc>
#include <..\..\gamemodes\API\systems\organisation_systems\organisation_gov\gov_systems_general.inc>
#include <..\..\gamemodes\API\systems\organisation_systems\organisation_hospital\hospital_systems_general.inc>
#include <..\..\gamemodes\API\systems\organisation_systems\organisation_news\news_systems_general.inc>
#include <..\..\gamemodes\API\systems\organisation_systems\organisation_police\police_systems_general.inc>

#include <..\..\gamemodes\API\systems\organisation_systems\organisation_gov\gov_systems_elections.inc>

stock create_organisation_element()
{

	create_gov_other_element();
	create_fsm_other_element();
	create_police_other_element();
	create_news_other_element();
	create_hospital_other_element();
	create_army_other_element();
	
	return true;
}