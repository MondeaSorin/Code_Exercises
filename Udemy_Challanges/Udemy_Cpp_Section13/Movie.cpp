#include <iostream>
#include "Movie.h"

Movie::Movie()
	: Movie("Unknown", "Unknown", 0) { }

Movie::Movie(std::string name, std::string rating, int watched)
	:name(name), rating(rating), watched(watched) { }

void Movie::display() const
{
	std::cout << "---------- MOVIE ----------" << std::endl
		<< "Name     : " << this->name << std::endl
		<< "Rating   : " << this->rating << std::endl
		<< "Watched  : " << this->watched << std::endl
		<< "----------------------------" << std::endl;
}

bool Movie::operator==(const Movie& m) const
{
	return this->name == m.name && this->rating == m.rating && this->watched == m.watched;
}

bool Movie::operator<(const Movie& m) const
{
	return this->watched < m.watched;
}
