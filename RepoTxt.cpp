#include "RepoTXT.h"
#include <fstream>
#include "Movie.h"
#include "Artist.h"
#include <vector>
#include "ValidateArtist.h"
#include "ValidateMovie.h"
#include "iostream"
RepoFileTXT::RepoFileTXT() : RepoFile()
{
}

RepoFileTXT::RepoFileTXT(string fileName) : RepoFile(fileName)
{
}

RepoFileTXT::~RepoFileTXT()
{
}

void RepoFileTXT::loadFromFile()
{
	ifstream f(this->fileName);
	if (f.is_open())
	{
		this->emptyRepo();
		string line;
		string delim = " ";
		while (getline(f, line))
		{
			if (line.substr(0, 2) == "AR")
			{
				line = line.erase(0, 3);

				int pos = line.find(delim);
				string name = line.substr(0, pos);
				line = line.erase(0, pos + 1);
				
					pos = line.find(delim);
					string d = line.substr(0, pos);
					Date data;
					try {
					int p = d.find("/");
					int day = stoi(d.substr(0, p));
					d = d.erase(0, p + 1);
					p = d.find("/");
					int month = stoi(d.substr(0, p));
					d = d.erase(0, p + 1);
					p = d.find("-");
					int year = stoi(d.substr(0, p));
					d = d.erase(0, p + 1);
					int hour = stoi(d);
					data.set_day(day);
					data.set_month(month);
					data.set_year(year);
					data.set_hour(hour);
				}
				catch (exception & oor)
				{
				}

				line = line.erase(0, pos + 1);
				pos = line.find(delim);
				string place = line.substr(0, pos);
				line = line.erase(0, pos + 1);

				int available;
				pos = line.find(delim);
				try {	
					available = stoi(line.substr(0, pos));
				}
				catch (exception & oor)
				{
					available = 0;
				}
				line = line.erase(0, pos + 1);

				int sold;
				pos = line.find(delim);
				try {
					sold = stoi(line.substr(0, pos));
				}
				catch (exception & oor)
				{
					sold = 0;
				}
				line = line.erase(0, pos + 1);
				try {
					ValidateArtist val;
					Artist* ar = new Artist(name, data, place, available, sold);
					val.validate(ar);
					this->events.push_back(ar);
				}
				catch (ValidationException & e) {
				}
			}
			else if (line.substr(0, 2) == "MO")
			{
				line = line.erase(0, 3);

				int pos = line.find(delim);
				string name = line.substr(0, pos);
				line = line.erase(0, pos + 1);

				pos = line.find(delim);
				string d = line.substr(0, pos);
				Date data;
				try {
					int p = d.find("/");
					int day = stoi(d.substr(0, p));
					d = d.erase(0, p + 1);
					p = d.find("/");
					int month = stoi(d.substr(0, p));
					d = d.erase(0, p + 1);
					p = d.find("-");
					int year = stoi(d.substr(0, p));
					d = d.erase(0, p + 1);
					int hour = stoi(d);
					data.set_day(day);
					data.set_month(month);
					data.set_year(year);
					data.set_hour(hour);
				}
				catch (exception & oor)
				{

				}
				line = line.erase(0, pos + 1);

				pos = line.find(delim);
				string place = line.substr(0, pos);
				line = line.erase(0, pos + 1);

				int available;
				pos = line.find(delim);
				try {
					
					available = stoi(line.substr(0, pos));
					
				}
				catch (exception & oor)
				{
					available = 0;
				}
				line = line.erase(0, pos + 1);

				pos = line.find(delim);
				int sold;
				try {
					 sold = stoi(line.substr(0, pos));
				}
				catch (exception & oor)
				{
					sold = 0;
				}
				line = line.erase(0, pos + 1);

				vector<string> actors;
				do {
					pos = line.find(delim);
					string actor = line.substr(0, pos);
					line = line.erase(0, pos + 1);
					actors.push_back(actor);
				} while (pos != -1);
				try {
					ValidateMovie val;
					Movie* mo = new Movie(name, data, place, available, sold, actors);
					val.validate(mo);
					this->events.push_back(mo);

				}
				catch (ValidationException & e) {
				}
			}
		}
		f.close();
	}
}

void RepoFileTXT::saveToFile()
{
	ofstream f(this->fileName);
	if (f.is_open())
	{
		for (Event* elem : this->events)
		{
			f << elem->toString(" ") << endl;
		}
		this->loadFromFile();
	}

}