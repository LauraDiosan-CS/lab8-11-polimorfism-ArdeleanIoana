#include "ValidateMovie.h"
#include "movie.h"
ValidateMovie::ValidateMovie()
{

}
ValidateMovie::~ValidateMovie()
{

}
void ValidateMovie::validate(Event* e)
{
	ValidateEvent::validate(e);
	Movie* m = (Movie*)e;
	if (m->get_actors().empty())
		throw ValidationException("the list of actors cannot be empty");
	vector<string> actors = m->get_actors();
	for (int i = 0; i < actors.size(); i++)
		if (actors[i].find(",") != -1 || actors[i].find(" ") != -1)
			throw ValidationException(" , and space ar illegal symbols");
}