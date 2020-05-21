#include "movie.h"

Movie::Movie() : Event()
{

}
Movie::Movie(string name, Date date, string place, int available, int sold, vector<string> actors) : Event(name, date, place, available, sold)
{
	this->actors = actors;
}
Movie::Movie(const Movie& m) : Event(m)
{
	this->actors = m.actors;
}


Event* Movie::clone()
{
	return new Movie(this->name, this->date, this->place, this->available, this->sold, this->actors);
}
vector<string> Movie::get_actors()
{
	return this->actors;
}
string Movie::vector_toString(vector<string> v, string delim)
{
	string s = v[0];
	int i;

	for (i = 1; i < v.size(); i++)
		s = s + delim + v[i];
	return s;
}
Movie& Movie::operator=(const Movie& m)
{
	Event::operator=(m);
	this->actors = m.actors;
	return *this;
}
bool Movie::operator==(const Movie& m)
{
	if (!Event::operator==(m) || this->actors.size() != m.actors.size())
		return false;
	int i;
	for (i = 0; i < this->actors.size(); i++)
		if (this->actors[i] != m.actors[i])
			return false;
	return true;
}
string Movie::toString(string delim)
{
	return "MO" + delim + Event::toString(delim) + delim + this->vector_toString(this->actors, delim);
}
string Movie::toShow()
{
	string m = Event::toString(" ") + "\n" + "Actors: " + "\n" + this->vector_toString(this->actors, "\n");
	if (this->available != 0)
		return m;
	else
		return   "SOLD OUT  "+m;
}