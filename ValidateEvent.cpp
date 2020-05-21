#include "ValidateEvent.h"

ValidateEvent::ValidateEvent()
{

}
ValidateEvent::~ValidateEvent()
{

}
void ValidateEvent::validate(Event* e)
{
	if (e->get_name().empty())
	{
		throw ValidationException("name cannot be empty!");
	}
	if(e->get_name().find(",")!=-1 || e->get_name().find(" ")!=-1)
		throw ValidationException(" , and space ar illegal symbols");
	if (e->get_place().empty())
		throw ValidationException("place cannot be empty!");
	if (e->get_place().find(",") != -1 || e->get_place().find(" ") != -1)
		throw ValidationException(" , and space ar illegal symbols");
	if (e->get_available()<0)
		throw ValidationException(" number of available tickets must be a positive number!");
	
	if (e->get_sold() < 0)
		throw ValidationException(" number of available tickets must be a positive number!");
	
	if (e->get_date().get_day() < 1 || e->get_date().get_day() > 31)
		throw ValidationException("day of the date must be from 1 to 31");

	if (e->get_date().get_month() < 1 || e->get_date().get_month() > 12)
		throw ValidationException("month of the date must be from 1 to 12");

	if (e->get_date().get_year() < 1900 || e->get_date().get_year() > 2020)
		throw ValidationException("year of the date must be from 1900 to 2020");

	if (e->get_date().get_hour() < 0 || e->get_date().get_day() > 24)
		throw ValidationException("hour of the date must be from 0 to 24");
}