#pragma once
#include "ValidateEvent.h"

class ValidateArtist : public ValidateEvent {
public:
	ValidateArtist();
	~ValidateArtist();
	void validate(Event* e);
};