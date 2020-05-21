#pragma once
#include "event.h"
class Artist : public Event {
public:
	Artist();
	Artist(string name, Date date, string place, int available, int sold);
	Artist(const Artist& a);
	~Artist();

	Event* clone();


	Artist& operator=(const Artist& a);
	bool operator==(const Artist& p);
	string toString(string delim);
	string toShow();
};