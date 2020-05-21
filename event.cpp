#include "event.h"

Event::Event()
{
	this->available = 0;
	this->sold = 0;
}
Event::Event(string name, Date date, string place, int available, int sold)
{
	this->name = name;
	this->date = date;
	this->place = place;
	this->available = available;
	this->sold = sold;
}
Event::Event(const Event& e)
{
	this->name = e.name;
	this->date = e.date;
	this->place = e.place;
	this->available = e.available;
	this->sold = e.sold;
}
Event::~Event()
{

}
Event* Event::clone()
{
	return new Event(this->name, this->date, this->place, this->available, this->sold);
}
string Event::get_name()
{
	return this->name;
}
Date Event::get_date()
{
	return this->date;
}
string Event::get_place()
{
	return this->place;
}
int Event::get_available()
{
	return this->available;
}
int Event::get_sold()
{
	return this->sold;
}
void Event::set_name(string name)
{
	this->name = name;
}
void Event::set_date(Date& date)
{
	this->date = date;
}
void Event::set_place(string place)
{
	this->place = place;
}
void Event::set_available(int available)
{
	this->available = available;
}
void Event::set_sold(int sold)
{
	this->sold = sold;
}

string Event::toString(string delim)
{
	return this->name + delim + this->date.toString() + delim + this->place + delim + to_string(this->available) + delim + to_string(this->sold);
}
Event& Event::operator=(const Event& e)
{
	this->name = e.name;
	this->date = e.date;
	this->place = e.place;
	this->available = e.available;
	this->sold = e.sold;
	return *this;
}

bool Event::operator==(const Event& e)
{
	return this->name == e.name && this->date == e.date && this->place == e.place && this->available == e.available && this->sold == e.sold;
}
string Event::toShow()
{
	return this->toString(" ");
}