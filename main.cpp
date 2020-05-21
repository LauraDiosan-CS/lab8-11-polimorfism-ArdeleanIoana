#include <iostream>
#include "TestEntity.h"
#include "TestRepo.h"
#include "TestService.h"
#include "UI.h"
using namespace std;
int main()
{
	TestEntity t;
	TestRepoFile f;
	TestService s;
	t.TestAll();
	f.testAll();
	s.TestAll();
	UI ui;
	ui.run();

	return 0;
}