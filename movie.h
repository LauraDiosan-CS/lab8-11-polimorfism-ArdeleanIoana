#pragma once
#include "event.h"
#include <vector>
class Movie : public Event
{
private:
	vector<string> actors;
public:
	Movie();
	Movie(string name, Date date, string place, int available, int sold, vector<string> actors);
	Movie(const Movie& m);

	Event* clone();

	vector<string> get_actors();
	string vector_toString(vector<string> v, string delim);

	Movie& operator=(const Movie& m);
	bool operator==(const Movie& m);
	string toString(string delim);
	string toShow();
};
