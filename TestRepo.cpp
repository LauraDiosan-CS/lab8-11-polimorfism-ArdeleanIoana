#include <assert.h>
#include "TestRepo.h"
#include "RepoTXT.h"
#include "RepoCSV.h"
#include <iostream>
using namespace std;


void TestRepoFile::testGetSize()
{
	RepoFile* repoFile = new RepoFileTXT();
	assert(repoFile->getSize() == 0);
	repoFile->addEvent(new Event());
	assert(repoFile->getSize() == 1); 
}

void TestRepoFile::testGetAll()
{
	Date date(20, 10, 2000, 5);
	RepoFile* repoFile = new RepoFileTXT();
	Artist* p1 = new Artist("ana",date, "parc", 50, 50);
	vector <string> actors;
	actors.push_back("actor1");
	Movie* p2 = new Movie("film1",date, "loc1", 5, 10, actors);
	repoFile->addEvent(p1);
	repoFile->addEvent(p2);
	vector<Event*> events = repoFile->getAll();
	assert(*events[0] == *p1->clone());
	assert(*events[1] == *p2->clone()); 
}

void TestRepoFile::testGetEvent()
{
	Date date(20, 10, 2000, 5);
	RepoFile* repoFile = new RepoFileTXT();
	Artist* p = new Artist("ana",date, "parc", 50, 50);
	repoFile->addEvent(p);
	assert(*repoFile->getEvent(0) == *p->clone());
	assert(*repoFile->getEvent(-1) == *(new Event()));
	assert(*repoFile->getEvent(1) == *(new Event())); 
}

void TestRepoFile::testAddEvent()
{
	Date date(20, 10, 2000, 5);
	RepoFile* repoFile = new RepoFileTXT();
	Artist* p = new Artist("ana",date, "parc", 50, 50);
	repoFile->addEvent(p);
	assert(*repoFile->getEvent(0) == *p->clone()); 

}

void TestRepoFile::testUpdateEvent()
{
	Date date(20, 10, 2000, 5);
	RepoFile* repoFile = new RepoFileTXT();
	Artist* p1 = new Artist("ana",date, "parc", 50, 50);
	repoFile->addEvent(p1);
	Artist* p2 = new Artist("anda",date, "parc2", 54, 50);
	Artist* p3 = new Artist("annna",date, "parc3", 50, 50);
	repoFile->updateEvent(p3, p2);
	assert(*repoFile->getEvent(0) == *p1);
	repoFile->updateEvent(p1, p2);
	assert(*repoFile->getEvent(0) == *p2); 
}

void TestRepoFile::testDeleteEvent()
{
	Date date(20, 10, 2000, 5);
	RepoFile* repoFile = new RepoFileTXT();
	vector <string> actors;
	actors.push_back("actor1");
	Movie* p1 = new Movie("annna",date, "parc3", 50, 50, actors);
	repoFile->addEvent(p1);
	Movie* p2 = new Movie("ana",date, "parc", 50, 50, actors);
	repoFile->deleteEvent(p2);
	assert(repoFile->getSize() == 1);
	assert(*repoFile->getEvent(0) == *p1);
	repoFile->deleteEvent(p1);
	assert(repoFile->getSize() == 0);
	repoFile->emptyRepo();
	
}
void TestRepoFile::testTXT()
{
	Date date(20, 10, 2000, 5);
	RepoFile* repoFile = new RepoFileTXT(this->fileNameTXT);
	repoFile->loadFromFile();
	assert(repoFile->getSize() == 0);
	Artist* p1 = new Artist("ana",date, "parc", 50, 50);
	repoFile->addEvent(p1);
	assert(repoFile->getSize() == 1);
	Artist* p2 = new Artist("anam",date, "parc", 50, 50);
	assert(*repoFile->getEvent(0) == *p1);
	repoFile->updateEvent(p1, p2);
	assert(*repoFile->getEvent(0) == *p2);
	repoFile->deleteEvent(p2);
	assert(repoFile->getSize() == 0);


}
void TestRepoFile::testCSV()
{
	Date date(20, 10, 2000, 5);
	RepoFile* repoFile = new RepoCSV(this->fileNameCSV);
	repoFile->loadFromFile();
	assert(repoFile->getSize() == 0);
	Artist* p1 = new Artist("ana",date, "parc", 50, 50);
	repoFile->addEvent(p1);
	assert(repoFile->getSize() == 1);
	Artist* p2 = new Artist("anam",date, "parc", 50, 50);
	assert(*repoFile->getEvent(0) == *p1);
	repoFile->updateEvent(p1, p2);
	assert(*repoFile->getEvent(0) == *p2);
	repoFile->deleteEvent(p2);
	assert(repoFile->getSize() == 0); 
}
void TestRepoFile::TesteLive()
{
	Date date(20, 10, 2000, 5);
	cout << "teste live" << endl;
	RepoFile* repoFileTxt = new RepoFileTXT(this->fileNameTXT);
	repoFileTxt->loadFromFile();
	RepoFile* repoFileCsv = new RepoCSV(this->fileNameCSV);
	repoFileCsv->loadFromFile();
	if (repoFileCsv->getSize() == 0 && repoFileTxt->getSize() == 0)
	{
		vector <string> actors;
		actors.push_back("actor1");
		Movie* p1 = new Movie("numefilm",date, "locFILM", 50, 50, actors);
		Artist* p2 = new Artist("numeARTIST",date, "locartist", 20, 20);
		repoFileCsv->addEvent(p1);
		repoFileCsv->addEvent(p2);
		repoFileTxt->addEvent(p1);
		repoFileTxt->addEvent(p2);
	}
	else {
		Event* e1 = repoFileTxt->getEvent(0);
		Event* e2 = repoFileTxt->getEvent(1);
		Event* e3 = repoFileCsv->getEvent(0);
		Event* e4 = repoFileCsv->getEvent(1);
		cout << endl;
		cout << "repo txt" << endl;
		cout << e1->toString(" ") << endl;
		cout << e2->toString(" ") << endl;
		cout << "repo csv" << endl;
		cout << e3->toString(" ") << endl;
		cout << e4->toString(" ") << endl;
	}
}

TestRepoFile::TestRepoFile()
{

}

TestRepoFile::~TestRepoFile()
{
}

void TestRepoFile::testAll()
{
	this->testGetSize();
	this->testGetAll();
	this->testGetEvent();
	this->testAddEvent();
	this->testUpdateEvent();
	this->testDeleteEvent();
	this->testTXT(); 
	this->testCSV();
	//this->TesteLive();
}