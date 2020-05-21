#include "RepoFile.h"

RepoFile::RepoFile()
{
}

RepoFile::RepoFile(string fileName)
{
	this->fileName = fileName;
}

RepoFile::~RepoFile()
{
}

void RepoFile::setFileName(string fileName)
{
	this->fileName = fileName;
}

vector<Event*> RepoFile::getAll()
{
	return this->events;
}

int RepoFile::getSize()
{
	return this->events.size();
}

Event* RepoFile::getEvent(int pos)
{
	if (pos >= 0 && pos < this->getSize())
	{
		return this->events[pos]->clone();
	}
	return new Event();
}

void RepoFile::addEvent(Event* p)
{
	this->events.push_back(p->clone());
	this->saveToFile();
}

void RepoFile::updateEvent(Event* old_event, Event* new_event)
{
	for (int i = 0; i < this->events.size(); i++)
	{
		if (*(this->getEvent(i)) == *old_event)
		{
			delete this->events[i];
			this->events[i] = new_event->clone();
			this->saveToFile();
			//return;
		}
	}
}

void RepoFile::deleteEvent(Event* e)
{
	for (int i = 0; i < this->events.size(); i++)
	{

		if (*(this->events[i]) == *e)
		{
			delete this->events[i];
			this->events.erase(this->events.begin() + i);
			this->saveToFile();
			return;
		}
	}
}

void RepoFile::emptyRepo()
{
	for (int i = 0; i < this->getSize(); i++)
	{
		delete this->events[i];
	}
	this->events.clear();

}