#pragma once
#include "event.h"
#include "artist.h"
#include "movie.h"

class TestEntity {
private:
	void testImplicitConstructor();
	void testConstructorWithParameters();
	void testCopyConstructor();
	void testClone();
	void testSetters();
	void testOperators();

public:
	void TestAll();
};