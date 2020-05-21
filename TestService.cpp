#include "TestService.h"
#include <assert.h>
#include <iostream>
using namespace std;
TestService::TestService()
{

}
TestService::~TestService()
{

}
void TestService::TestAll()
{
	this->TestCsv();
	this->TestTxt();
	this->TestLogin();
}
void TestService::TestCsv() {
	/*
	Service service;
	service.set_repo_csv("TestEvents.csv");
	vector<Event*> artists = service.get_artists();
	assert(artists.empty());
	vector<Event*> movies = service.get_movies();
	assert(movies.empty());
	
	//artist
	service.add_artist("artist1", "data1", "loc1", 5, 5);
	movies = service.get_movies();
	assert(movies.empty());
	artists = service.get_artists();
	assert(! artists.empty());
	Event* a = artists[0];
	assert(a->toShow() == "artist1 data1 loc1 5 5");
	service.update_artist("artist1", "artist2", "data1", "loc1", 5, 5);
	service.delete_artist("artist2");
	artists = service.get_artists();
	assert(artists.empty());

	//movie
	vector<string> actors;
	actors.push_back("marcel");
	actors.push_back("darius");
	service.add_movie("movie1", "data1", "loc1", 5, 5,actors);
	movies = service.get_movies();
	Event* m = movies[0];
	assert(m->toString(",") == "MO,movie1,data1,loc1,5,5,marcel,darius");
	service.update_movie("movie1", "movie2", "data1", "loc1", 5, 5, actors);
	service.delete_movie("movie2");
	movies = service.get_movies();
	assert(movies.empty());
	*/
}
void TestService::TestTxt() {
	/*
	Service service;
	service.set_repo_txt("TestEvents.txt");
	vector<Event*> artists = service.get_artists();
	assert(artists.empty());
	vector<Event*> movies = service.get_movies();
	assert(movies.empty());

	//artist
	service.add_artist("artist1", "data1", "loc1", 5, 5);
	movies = service.get_movies();
	assert(movies.empty());
	artists = service.get_artists();
	assert(!artists.empty());
	Event* a = artists[0];
	assert(a->toShow() == "artist1 data1 loc1 5 5");
	service.update_artist("artist1", "artist2", "data1", "loc1", 5, 5);
	service.delete_artist("artist2");
	artists = service.get_artists();
	assert(artists.empty());

	//movie
	vector<string> actors;
	actors.push_back("marcel");
	actors.push_back("darius");
	service.add_movie("movie1", "data1", "loc1", 5, 5, actors);
	movies = service.get_movies();
	Event* m = movies[0];
	assert(m->toString(",") == "MO,movie1,data1,loc1,5,5,marcel,darius");
	service.update_movie("movie1", "movie2", "data1", "loc1", 5, 5, actors);
	service.delete_movie("movie2");
	movies = service.get_movies();
	assert(movies.empty());
	*/

}
void TestService::TestLogin()
{
	Service s;
	assert(s.check_login("incorect", "incorect") == false);
	assert(s.check_login("user1", "incorect") == false);
	assert(s.check_login("incorect", "parola1") == false);
	assert(s.check_login("user1", "parola1") == true);
}
