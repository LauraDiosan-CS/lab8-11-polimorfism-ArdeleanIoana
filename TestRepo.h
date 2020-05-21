#pragma once
#include "RepoFile.h"
#include "event.h"
#include "artist.h"
#include "movie.h"
class TestRepoFile {
private:
    const string fileNameTXT = "TestEvents.txt";
    const string fileNameCSV = "TestEvents.csv";

    void testGetSize();
    void testGetAll();
    void testGetEvent();
    void testAddEvent();
    void testUpdateEvent();
    void testDeleteEvent();
    void testTXT();
    void testCSV();
    void TesteLive();
public:
    TestRepoFile();
    ~TestRepoFile();
    void testAll();
};