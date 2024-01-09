#pragma once
#include <string>

class Movie
{
private:
	std::string name;
	std::string rating;
	int watched;
public:
	Movie();
	Movie(std::string name, std::string rating, int watched);

	// Getters and Setters -- will be done inline
	std::string get_name() const { return this->name; }
	void set_name(std::string name) { if (!name.empty()) this->name = name; }

	std::string get_rating() const { return this->rating; }
	void set_rating(std::string rating) { if (!rating.empty()) this->rating = rating; }

	int get_watched() const { return this->watched; }
	void set_watched(int watched) { if (watched >= 0) this->watched = watched; }

	// Member-wise methods
	void display() const;
	void increment_watched() { this->watched++; }

	// Operator overloading
	bool operator==(const Movie & m) const;
	bool operator<(const Movie& m) const;
};
