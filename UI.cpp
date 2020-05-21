#include "UI.h"
#include <iostream>
#include "ValidationException.h"
using namespace std;
UI::UI() {
}
UI::~UI()
{

}
void UI::showMenu1()
{
	cout << "1. login"<<endl;
	cout << "x. exit"<<endl;
}
void UI::showMenu2()
{
	cout << "1. add artist" << endl;
	cout << "2. add movie" << endl;
	cout << "3. remove artist" << endl;
	cout << "4. remove movie" << endl;
	cout << "5. update artist" << endl;
	cout << "6. update movie" << endl;
	cout << "7. show artists" << endl;
	cout << "8. show movies" << endl;
	cout << "9. buy concert ticket" << endl;
	cout << "10. buy movie ticket" << endl;
	cout << "11. show by date" << endl;
	cout << "--------------------" << endl;
	cout << "x. Logout"<<endl;
}
Date UI::read_date()
{
	try {
		string sday, smonth, syear, shour;
		int day, month, year, hour;
		cout << "day: ";
		cin >> sday;
		day = stoi(sday);
		cout << "month: ";
		cin >> smonth;
		month = stoi(smonth);
		cout << "year: ";
		cin >> syear;
		year = stoi(syear);
		cout << "hour: ";
		cin >> shour;
		hour = stoi(shour);
		return Date(day, month, year, hour);
	}
	catch (exception & oor)
	{
		cout << "must be a number" << endl;
	}
}
void UI::buy(string ch)
{
	try {
		string name, snr;
		int nr;
		cout << "name: ";
		cin >> name;
		cout << "how many: ";
		cin >> snr;
		nr = stoi(snr);
		if (nr < 0)
			cout << "must be a positive value" << endl;
		if (ch == "9")
			if (this->service.buy_artist(name, nr))
				cout << "tickets bought";
			else
				cout << "not enough tickets available";
		else
			if (this->service.buy_movie(name, nr))
				cout << "tickets bought";
			else
				cout << "not enough tickets available";
		cout << endl;
	}
	catch (exception & oor)
	{
		cout << "must be number" << endl;
	}
}
void UI::showByDay()
{
	try {
		string sday, smonth, syear;
		int day, month, year;
		cout << "day: ";
		cin >> sday;
		day = stoi(sday);
		cout << "month: ";
		cin >> smonth;
		month = stoi(smonth);
		cout << "year: ";
		cin >> syear;
		year = stoi(syear);
		Date date(day, month, year);
		cout << " on the date of: " << date << endl;
		vector<Event*> events = this->service.getByDate(date);

		for (int i = 0; i < events.size(); i++)
			cout << events[i]->toShow() << endl;
	}
	catch (exception & oor)
	{
		cout << "must be number" << endl;
	}
}
bool UI::Login()
{
	string user;
	string password;
	cout << "username: ";
	cin >> user;
	cout << "password: ";
	cin >> password;
	return this->service.check_login(user, password);
}
void UI::Add(string ch)
{
	try {
		string name, place, savailable, ssold;
		Date date;
		int available, sold;
		cout << "name: ";
		cin >> name;
		date = this->read_date();
		cout << "place: ";
		cin >> place;
		cout << "available: ";
		cin >> savailable;
		available = stoi(savailable);
		cout << "sold: ";
		cin >> ssold;
		sold = stoi(ssold);
		if (ch == "1")
		{
			this->service.add_artist(name, date, place, available, sold);
			cout << "artist added" << endl;

		}
		else
		{
			int size, i;
			vector<string> actors;
			string actor;
			cout << "how many actors? ";
			cin >> size;
			for (i = 0; i < size; i++)
			{
				cout << "actor " << i << " : ";
				cin >> actor;
				actors.push_back(actor);
			}
			this->service.add_movie(name, date, place, available, sold, actors);
			cout << "movie added" << endl;
		}
	}
	catch (ValidationException & e) {
		cout << e.what() << endl;
	}
	catch (exception & oor)
	{
		cout << " sold and available must be numbers" << endl;
	}
}
void UI::Remove(string ch)
{
	string name;
	cout << "name: ";
	cin >> name;
	if (ch == "3")
		this->service.delete_artist(name);
	else
		this->service.delete_movie(name);
}
void UI::Update(string ch)
{
	try {
		string old_name;
		string name, place;
		string ssold, savailable;
		Date date;
		int available, sold;
		cout << "old name: ";
		cin >> old_name;
		cout << "name: ";
		cin >> name;
		date = this->read_date();
		cout << "place: ";
		cin >> place;
		cout << "available: ";
		cin >> savailable;
		available = stoi(savailable);
		cout << "sold: ";
		cin >> ssold;
		sold = stoi(ssold);
		if (ch == "5")
		{
			this->service.update_artist(old_name, name, date, place, available, sold);

		}
		else
		{
			int size, i;
			vector<string> actors;
			string actor;
			cout << "how many actors? ";
			cin >> size;
			for (i = 0; i < size; i++)
			{
				cout << "actor " << i << " : ";
				cin >> actor;
				actors.push_back(actor);
			}
			this->service.update_movie(old_name, name, date, place, available, sold, actors);

		}
	}
	catch (ValidationException & e) {
		cout << e.what() << endl;
	}
	catch (exception & oor)
	{
		cout << "must be number" << endl;
	}
}
void UI::Show(string ch)
{
	if (ch == "7")
	{
		vector<Event*> artists = this->service.get_artists();
		cout << "Artists" << endl;
		for (int i = 0; i < artists.size(); i++)
			cout << artists[i]->toShow() << endl;
	}
	else {
		vector<Event*> movies = this->service.get_movies();
		cout << "Movies" << endl;
		for (int i = 0; i < movies.size(); i++)
			cout << movies[i]->toShow() << endl;
	}
}
void UI::run()
{
	bool logged = false;
	string ch;
	while (!logged)
	{
		this->showMenu1();
		cout << "option: ";
		cin >> ch;
		if (ch == "x")
			break;
		logged = this->Login();
	}
	if (logged)
	{
		cout << "file option: " << endl;
		cout << "1. csv"<<endl;
		cout << "2. txt" << endl;
		cin >> ch;
		if (ch == "1")
			this->service.set_repo_csv("Events.csv");
		if (ch == "2")
			this->service.set_repo_txt("Events.txt");
		if (ch == "2" || ch == "1")
		{
			while (true)
			{
				this->showMenu2();
				cin >> ch;
				if (ch == "1" || ch == "2")
					this->Add(ch);
				else if (ch == "3" || ch == "4")
					this->Remove(ch);
				else if (ch == "5" || ch == "6")
					this->Update(ch);
				else if (ch == "7" || ch == "8")
					this->Show(ch);
				else if (ch == "9" || ch == "10")
					this->buy(ch);
				else if (ch == "11")
					this->showByDay();
				else if (ch == "x")
					break;
				else
					cout << "invalid" << endl;
			}
		}
	}
}