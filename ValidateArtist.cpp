#include "ValidateEvent.h"
#include "Artist.h"
#include "ValidationException.h"
#include "ValidateArtist.h"
#include "ValidateEvent.h"

ValidateArtist::ValidateArtist()
{
}
ValidateArtist::~ValidateArtist(){
}

void ValidateArtist::validate(Event* e)
{
	ValidateEvent::validate(e);
	
}