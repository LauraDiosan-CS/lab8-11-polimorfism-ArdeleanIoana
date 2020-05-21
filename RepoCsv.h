#pragma once
#include "RepoFile.h"

class RepoCSV : public RepoFile {
public:
	RepoCSV();
	RepoCSV(string fileName);
	~RepoCSV();
	void loadFromFile();
	void saveToFile();
};
