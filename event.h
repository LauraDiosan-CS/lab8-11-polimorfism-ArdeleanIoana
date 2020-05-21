#pragma once
#include <string>
#include "date.h"
using namespace std;
class Event {
protected:
	string name;
	Date date;
	string place;
	int available;
	int sold;

public:
	Event();
	Event(string name, Date date, string place, int available, int sold);
	Event(const Event& e);
	~Event();

	virtual Event* clone();

	string get_name();
	Date get_date(); // ??
	string get_place();
	int get_available();
	int get_sold();
	void set_name(string name);
	void set_date(Date& date);
	void set_place(string place);
	void set_available(int availavle);
	void set_sold(int sold);
	Event& operator=(const Event& e);
	bool operator==(const Event& e);
	virtual string toString(string delim);
	virtual string toShow();
};