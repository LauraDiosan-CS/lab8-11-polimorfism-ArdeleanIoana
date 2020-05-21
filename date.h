#pragma once
#include <string>
#include <ostream>
using namespace std;

class Date {
private:
	int day;
	int month;
	int year;
	int hour;
public:

	Date();
	Date(int day, int month, int year, int hour);
	Date(int day, int month, int year);

	Date(const Date& d);
	~Date();

	int get_day();
	int get_month();
	int get_year();
	int get_hour();

	void set_day(int d);
	void set_month(int m);
	void set_year(int y);
	void set_hour(int h);

	string toString();
	bool same_day(const Date& d);
	Date& operator=(const Date& d);
	bool operator==(const Date& d);
	bool operator>(const Date& d);
	bool operator<(const Date& d);

	friend ostream& operator<<(ostream& os, const Date& d);
};