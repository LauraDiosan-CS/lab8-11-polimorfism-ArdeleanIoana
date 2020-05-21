#pragma once
#pragma once
#include "ValidateEvent.h"

class ValidateMovie : public ValidateEvent {
public:
	ValidateMovie();
	~ValidateMovie();
	void validate(Event* e);
};