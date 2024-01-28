#pragma once
#include "cell.h"
class grid
{
private:
	cell cells[rowMax + 2][colMax + 2];
public:
	void create(int row, int column);
	void draw();
	void randomize();
	bool will_survive(int row, int column) const;
	bool will_create(int row, int column) const;
	void update(const grid& next);
};

void calculate(grid& old_generation, grid& new_generation);

