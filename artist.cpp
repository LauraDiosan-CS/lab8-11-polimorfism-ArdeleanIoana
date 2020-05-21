#include "artist.h"

Artist::Artist() : Event()
{
}

Artist::Artist(string name, Date date, string place, int available, int sold) : Event(name, date, place, available, sold)
{

}

Artist::Artist(const Artist& a) : Event(a)
{

}

Artist::~Artist()
{
}

Event* Artist::clone()
{
	return new Artist(this->name, this->date, this->place, this->available, this->sold);
}

Artist& Artist::operator=(const Artist& a)
{
	Event::operator=(a);
	return *this;
}

bool Artist::operator==(const Artist& a)
{
	return Event::operator==(a);
}

string Artist::toString(string delim)
{
	return "AR" + delim + Event::toString(delim);
}
string Artist::toShow()
{
	string a = this->toString(" ");
	a.erase(0, 3);
	if (this->available != 0)
		return a;
	else
		return "SOLD OUT  " + a;
}