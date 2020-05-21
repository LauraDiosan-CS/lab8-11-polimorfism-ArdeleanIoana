#pragma once
#include "Event.h"
#include <vector>
#include "ReadFromFileException.h"
using namespace std;

class RepoFile {
protected:
	vector<Event*> events;
	string fileName;
public:
	RepoFile();
	RepoFile(string fileName);
	~RepoFile();
	void setFileName(string fileName);

	vector<Event*> getAll();
	int getSize();
	Event* getEvent(int pos);
	void addEvent(Event* e);
	void updateEvent(Event* old_event, Event* new_event);
	void deleteEvent(Event* e);

	void emptyRepo();

	virtual void loadFromFile() = 0;
	virtual void saveToFile() = 0;
};