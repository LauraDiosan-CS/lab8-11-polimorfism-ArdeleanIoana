#include "TestEntity.h"
#include <iostream>
#include <assert.h>
using namespace std;
void TestEntity::TestAll()
{
	this->testImplicitConstructor();
	this->testConstructorWithParameters();
	this->testCopyConstructor();
	this->testClone();
	this->testSetters();
	this->testOperators();
}
void TestEntity::testImplicitConstructor()
{
	Event e;
	assert(e.get_name().empty());
	assert(e.get_date().get_day() == 1);
	assert(e.get_date().get_month() == 1);
	assert(e.get_date().get_year() == 1900);
	assert(e.get_date().get_hour() == 0);
	assert(e.get_place().empty());
	assert(e.get_available() == 0);
	assert(e.get_sold() == 0);

	Artist a;
	assert(a.get_name().empty());
	assert(a.get_date().get_day()==1);
	assert(a.get_date().get_month() == 1);
	assert(a.get_date().get_year() == 1900);
	assert(a.get_date().get_hour() == 0);
	assert(a.get_place().empty());
	assert(a.get_available() == 0);
	assert(a.get_sold() == 0);

	Movie m;
	assert(m.get_name().empty());
	assert(m.get_date().get_day() == 1);
	assert(m.get_date().get_month() == 1);
	assert(m.get_date().get_year() == 1900);
	assert(m.get_date().get_hour() == 0);
	assert(m.get_place().empty());
	assert(m.get_available() == 0);
	assert(m.get_sold() == 0);
	assert(m.get_actors().empty()); 
}

void TestEntity::testConstructorWithParameters()
{
	Date date(20, 10, 2000, 5);
	Event e("name", date, "place", 5, 5);
	assert(e.get_name() == "name");
	assert(e.get_date().get_day()== 20);
	assert(e.get_date().get_month() == 10);
	assert(e.get_date().get_year() == 2000);
	assert(e.get_date().get_hour() == 5);
	assert(e.get_place() == "place");
	assert(e.get_available() == 5);
	assert(e.get_sold() == 5);

	Artist a("ana",date, "parc", 20, 400);
	assert(a.get_name() == "ana");
	assert(a.get_date().get_day() == 20);
	assert(a.get_date().get_month() == 10);
	assert(a.get_date().get_year() == 2000);
	assert(a.get_date().get_hour() == 5);
	assert(a.get_place() == "parc");
	assert(a.get_available() == 20);
	assert(a.get_sold() == 400);

	vector<string> actors;
	actors.push_back("diana");
	actors.push_back("florin");
	Movie m("x",date, "stadion", 240, 400, actors);
	assert(m.get_name() == "x");
	assert(m.get_date().get_day() == 20);
	assert(m.get_date().get_month() == 10);
	assert(m.get_date().get_year() == 2000);
	assert(m.get_date().get_hour() == 5);
	assert(m.get_place() == "stadion");
	assert(m.get_available() == 240);
	assert(m.get_sold() == 400);
	assert(m.get_actors()[0] == "diana");
	assert(m.get_actors()[1] == "florin"); 
	
}

void TestEntity::testCopyConstructor()
{
	Date date(20, 10, 2000, 5);
	Event e1("name", date, "place", 5, 5);
	Event e2(e1);
	assert(e1.get_name() == e2.get_name());
	assert(e1.get_date() == e2.get_date());
	assert(e1.get_place() == e2.get_place());
	assert(e1.get_available() == e2.get_available());
	assert(e1.get_sold() == e2.get_sold());

	Artist a1("ana", date, "parc1", 51, 51);
	Artist a2(a1);
	assert(a1.get_name() == a2.get_name());
	assert(a1.get_date() == a2.get_date());
	assert(a1.get_place() == a2.get_place());
	assert(a1.get_available() == a2.get_available());
	assert(a1.get_sold() == a2.get_sold());

	vector<string> actors;
	actors.push_back("samira");
	actors.push_back("andrada");
	Movie m1("saw",date, "parc2", 51, 51, actors);
	Movie m2(m1);
	assert(m1.get_name() == m2.get_name());
	assert(m1.get_date() == m2.get_date());
	assert(m1.get_place() == m2.get_place());
	assert(m1.get_available() == m2.get_available());
	assert(m1.get_sold() == m2.get_sold());
	assert(m1.get_actors()[0] == m2.get_actors()[0]);
	assert(m1.get_actors()[1] == m2.get_actors()[1]); 
}
void TestEntity::testClone()
{
	Date date(20, 10, 2000, 5);
	Event p("ana", date, "parc1", 51, 51);
	Event* pClone = (Event*)p.clone();
	assert(p == *pClone);
	assert(&p != pClone);

	Artist a("ana", date, "parc1", 51, 51);
	Artist* aClone = (Artist*)a.clone();
	assert(a == *aClone);
	assert(&a != aClone);

	vector<string> actors;
	actors.push_back("diana");
	actors.push_back("florin");
	Movie m("ana", date, "parc1", 51, 51, actors);
	Movie* mClone = (Movie*)m.clone();
	assert(m == *mClone);
	assert(&m != mClone); 
}

void TestEntity::testSetters()
{
	Date date(20, 10, 2000, 5);
	Event e;
	e.set_name("ana");
	assert(e.get_name() == "ana");
	e.set_date(date);
	assert(e.get_date() == date);
	e.set_place("place1");
	assert(e.get_place() == "place1");
	e.set_available(1);
	assert(e.get_available() == 1);
	e.set_sold(5);
	assert(e.get_sold() == 5);

	Artist a;
	a.set_name("ana");
	assert(a.get_name() == "ana");
	a.set_date(date);
	assert(a.get_date() == date);
	a.set_place("place1");
	assert(a.get_place() == "place1");
	a.set_available(1);
	assert(a.get_available() == 1);
	a.set_sold(5);
	assert(a.get_sold() == 5); 
}

void TestEntity::testOperators()
{
	Date date(20, 10, 2000, 5);
	Event e1("ana", date, "parc1", 51, 51);
	Event e2("2",date, "2", 0, 0);
	assert(!(e1 == e2));
	e1 = e2;
	assert(e1.get_name() == "2");
	assert(e1 == e2);

	vector<string> actors1;
	actors1.push_back("diana");
	vector<string> actors2;
	actors2.push_back("diana2");
	Movie m1("ana",date, "parc1", 51, 51, actors1);
	Movie m2("ana",date, "parc1", 51, 51, actors2);
	assert(!(m1 == m2));
	m1 = m2;
	assert(m1 == m2); 
}