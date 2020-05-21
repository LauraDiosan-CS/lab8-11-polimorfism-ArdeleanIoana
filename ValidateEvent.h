#pragma once
#include "ValidationException.h"
#include "event.h"
using namespace std;
class ValidateEvent {
public:
	ValidateEvent();
	~ValidateEvent();
	
	virtual void validate(Event* e);
	
};