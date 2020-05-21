#pragma once
#include "artist.h";
#include "movie.h";
#include "RepoCsv.h"
#include "RepoTxt.h"
class Service {
private:
	RepoFile* repo;
	const string user = "user1";
	const string password = "parola1";
	
public:
	Service();
	~Service();

	void set_repo_txt(string filename);
	void set_repo_csv(string filename);


	bool check_login(string user, string password);
	bool buy_artist(string name, int nr);
	bool buy_movie(string name, int nr);

	void add_movie(string name, Date date, string place, int available, int sold, vector<string> actors);
	void add_artist(string name, Date date, string place, int available, int sold);
	void delete_movie(string name);
	void delete_artist(string name);
	void update_artist(string old_name, string name, Date date, string place, int available, int sold);
	void update_movie(string old_name,string name, Date date, string place, int available, int sold, vector<string> actors);
	
	vector<Event*> get_artists();
	vector<Event*> get_movies();
	vector<Event*> getByDate(Date date);
};
