#include "date.h"

Date::Date()
{
	this->day = 1;
	this->month = 1;
	this->year = 1900;
	this->hour = 0;
}
Date::Date(int day, int month, int year, int hour)
{
	this->day = day;
	this->month = month;
	this->year = year;
	this->hour = hour;
}
Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
	this->hour = 0;
}
Date::Date(const Date& d)
{
	this->day = d.day;
	this->month = d.month;
	this->year = d.year;
	this->hour = d.hour;
}
Date::~Date()
{

}
int Date::get_day()
{
	return this->day;
}
int Date::get_month()
{
	return this->month;
}
int Date::get_year()
{
	return this->year;
}
int Date::get_hour()
{
	return this->hour;
}
void Date::set_day(int d)
{
	this->day = d;
}
void Date::set_month(int m)
{
	this->month = m;
}
void Date::set_year(int y)
{
	this->year = y;
}
void Date::set_hour(int h)
{
	this->hour = h;
}

string Date::toString()
{
	return to_string(this->day) + "/" + to_string(this->month) + "/" + to_string(this->year) + "-" + to_string(this->hour);
}
Date& Date::operator=(const Date& d)
{
	this->set_day(d.day);
	this->set_hour(d.hour);
	this->set_month(d.month);
	this->set_year(d.year);
	return *this;
}
bool Date::same_day(const Date& d)
{
	return (this->day == d.day && this->month == d.month && this->year == d.year);
}
bool Date::operator==(const Date& d)
{
	return (this->hour ==d.hour && this->day == d.day && this->month == d.month && this->year == d.year);
}
bool Date::operator<(const Date& d)
{
	if (this->year < d.year)
		return true;
	if (this->year > d.year)
		return false;
	if (this->month < d.month)
		return true;
	if (this->month > d.month)
		return false;
	if (this->day < d.day)
		return true;
	if (this->day > d.day)
		return false;
	if (this->hour < d.hour)
		return true;
	if (this->hour > d.hour)
		return false;
	return false;
}

bool Date::operator>(const Date& d) 
{
	if (this->year < d.year)
		return false;
	if (this->year > d.year)
		return true;
	if (this->month < d.month)
		return false;
	if (this->month > d.month)
		return true;
	if (this->day < d.day)
		return false;
	if (this->day > d.day)
		return true;
	if (this->hour < d.hour)
		return false;
	if (this->hour > d.hour)
		return true;
	return false;
}


ostream& operator<<(ostream& os, const Date& d)
{
	os << d.day << "/" << d.month << "/" << d.year << "-" << d.hour;
	
	return os;
}