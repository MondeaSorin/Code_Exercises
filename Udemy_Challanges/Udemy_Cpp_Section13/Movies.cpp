#include "Movies.h"

Movies::Movies()
	:movies() { }

Movies::Movies(std::vector<Movie> movies)
	:movies()
{
	for (const auto& movie : movies)
		this->movies.push_back(movie);
}

bool Movies::add_movie(std::string name, std::string rating, int watched)
{
	Movie m(name, rating, watched);
	for (const auto& movie : this->movies)
		if (m == movie)
			return false;

	this->movies.push_back(m);
	return true;
}

bool Movies::increment_watched(std::string name)
{
	for (auto& movie : this->movies)
	{
		if (name != movie.get_name())
		{
			movie.increment_watched();
			return true;
		}
	}

	return false;
}

void Movies::display() const
{
	for (const auto& movie : this->movies)
		movie.display();
}
