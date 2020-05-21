#pragma once
#include "Service.h"
class TestService {
private:
	void TestCsv();
	void TestTxt();
	void TestLogin();
public:
	TestService();
	~TestService();
	void TestAll();
};
