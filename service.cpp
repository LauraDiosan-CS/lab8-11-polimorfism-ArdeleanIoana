#include "Service.h"
#include "RepoFile.h"
#include "ValidateEvent.h"
#include "ValidateMovie.h"
#include "ValidateArtist.h"
Service::Service()
{
	
}
Service::~Service()
{

}
void Service::set_repo_txt(string filename)
{
	this->repo = new RepoFileTXT(filename);
	this->repo->loadFromFile();
}
void Service::set_repo_csv(string filename)
{
	this->repo = new RepoCSV(filename);
	this->repo->loadFromFile();
}

bool Service::check_login(string user, string password)
{
	if (user == this->user && password == this->password)
		return true;
	return false;
}
bool Service::buy_artist(string name, int nr)
{
	vector<Event*> all = this->repo->getAll();
	for (int i = 0; i < this->repo->getSize(); i++)
		if (this->repo->getEvent(i)->get_name() == name)
		{
			if (this->repo->getEvent(i)->get_available() >= nr)
			{
				int newe = this->repo->getEvent(i)->get_available() - nr;
				int news = this->repo->getEvent(i)->get_sold() + nr;
				Event* e = this->repo->getEvent(i);
				e->set_available(newe);
				e->set_sold(news);
				this->repo->updateEvent(this->repo->getEvent(i), e);
			}
			else return false;
		}
	return true;
}
bool Service::buy_movie(string name, int nr)
{
	vector<Event*> all = this->repo->getAll();
	for (int i = 0; i < this->repo->getSize(); i++)
		if (this->repo->getEvent(i)->get_name() == name)
		{
			if (this->repo->getEvent(i)->get_available() >= nr)
			{
				int newe = this->repo->getEvent(i)->get_available() - nr;
				int news = this->repo->getEvent(i)->get_sold() + nr;
				Event* e = this->repo->getEvent(i);
				e->set_available(newe);
				e->set_sold(news);
				this->repo->updateEvent(this->repo->getEvent(i), e);
			}
			else return false;
		}
	return true;
}
void Service::add_movie(string name, Date date, string place, int available, int sold, vector<string> actors)
{
	ValidateMovie val;
	Movie* movie =  new Movie(name, date, place, available, sold, actors);
	val.validate(movie);
	this->repo->addEvent(movie);
	
}
void Service::add_artist(string name, Date date, string place, int available, int sold)
{
	ValidateArtist val;
	Artist* artist = new Artist(name, date, place, available, sold);
	val.validate(artist);
	this->repo->addEvent(artist);
}

void Service::delete_movie(string name)
{
	vector<Event*> all = this->repo->getAll();
	for(int i = 0; i<this->repo->getSize(); i++)
		if (this->repo->getEvent(i)->get_name() == name && this->repo->getEvent(i)->toString(" ").substr(0, 2) == "MO")
		{
			Event* m = this->repo->getEvent(i);
			this->repo->deleteEvent(m);
		}
}

void Service::delete_artist(string name)
{
	vector<Event*> all = this->repo->getAll();
	for (int i = 0; i < this->repo->getSize(); i++)
		if (this->repo->getEvent(i)->get_name() == name && this->repo->getEvent(i)->toString(" ").substr(0, 2) == "AR")
		{
			Event* a = this->repo->getEvent(i);
			this->repo->deleteEvent(a);
		}
}
void Service::update_artist(string old_name, string name, Date date, string place, int available, int sold)
{
	ValidateArtist val;
	vector<Event*> all = this->repo->getAll();
	for (int i = 0; i < this->repo->getSize(); i++)
		if (this->repo->getEvent(i)->get_name() == old_name )
		{
			Artist* a = new Artist(name, date, place, available, sold);
			val.validate(a);
			this->repo->updateEvent(this->repo->getEvent(i), a);
		}
}

void Service::update_movie(string old_name,string name, Date date, string place, int available, int sold, vector<string> actors)
{
	vector<Event*> all = this->repo->getAll();
	ValidateMovie val;
	for (int i = 0; i < this->repo->getSize(); i++)
		if (this->repo->getEvent(i)->get_name() == old_name)
		{
			Movie* m = new Movie(name, date, place, available, sold,actors);
			val.validate(m);
			this->repo->updateEvent(this->repo->getEvent(i), m);
		}
}
vector<Event*> Service::get_artists()
{
	vector<Event*> all = this->repo->getAll();
	vector<Event*> artists;
	for (int i = 0; i < this->repo->getSize(); i++)
		if ( this->repo->getEvent(i)->toString(" ").substr(0, 2) == "AR")
		{
			artists.push_back(this->repo->getEvent(i));
		}
	return artists;
}
vector<Event*> Service::get_movies()
{
	vector<Event*> all = this->repo->getAll();
	vector<Event*> movies;
	for (int i = 0; i < this->repo->getSize(); i++)
		if (this->repo->getEvent(i)->toString(" ").substr(0, 2) == "MO")
		{
			movies.push_back(this->repo->getEvent(i));
		}
	return movies;
}
vector<Event*> Service::getByDate(Date date)
{
	vector<Event*> all = this->repo->getAll();
	vector<Event*> ret;
	for (int i = 0; i < this->repo->getSize(); i++)
		if (date.same_day(this->repo->getEvent(i)->get_date()))
			ret.push_back(this->repo->getEvent(i));
	return ret;
}