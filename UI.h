#pragma once
#include "Service.h"
#include "movie.h"
#include "event.h"
#include "artist.h"

class UI {
private:
	Service service;
public:
	UI();
	~UI();
	void showMenu1();
	void showMenu2();
	bool Login();
	void buy(string ch);
	void showByDay();
	void Add(string ch);
	void Update(string ch);
	void Remove(string ch);
	void Show(string ch);
	void run();
	Date read_date();
};