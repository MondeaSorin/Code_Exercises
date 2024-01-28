#pragma once
#include <iostream>
#include "life.h"

class cell
{
private:
	bool alive;
public:
	cell() : alive(false) {}

	void draw(int row, int col) const
	{
		std::cout << "\x1b[" << row + 1 << ";" << col + 1 << "H";
		std::cout << (alive ? liveCell : deadCell);
	}

	void create() { alive = true; }
	void erase() { alive = false; }

	bool is_alive() const { return alive; }
};

