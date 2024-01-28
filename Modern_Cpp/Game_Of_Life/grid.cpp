#include "grid.h"

void grid::create(int row, int column)
{
	cells[row][column].create();
}

void grid::draw()
{
	std::cout << "\x1b[2J";
	for (int row = 1; row < rowMax; row++)
	{
		for (int column = 1; column < colMax; column++)
		{
			cells[row][column].draw(row, column);
		}
	}
}

void grid::randomize()
{
	const int factor = 5;
	const int cutoff = RAND_MAX / factor;
	time_t now;
	time(&now);
	srand(now);

	for (int row = 1; row < rowMax; ++row)
	{
		for (int column = 1; column < colMax; column++)
		{
			if (rand() / cutoff == 0)
			{
				create(row, column);
			}
		}
	}
}

bool grid::will_survive(int row, int column) const
{
	if (!cells[row][column].is_alive()) return false;

	int neighbours = cells[row - 1][column - 1].is_alive() +
		cells[row - 1][column].is_alive() +
		cells[row - 1][column + 1].is_alive() +
		cells[row][column - 1].is_alive() +
		cells[row][column + 1].is_alive() +
		cells[row + 1][column - 1].is_alive() +
		cells[row + 1][column].is_alive() +
		cells[row + 1][column + 1].is_alive();

	if (neighbours < min_neighbors || neighbours > max_neighbors) return false;

	return true;
}

bool grid::will_create(int row, int column) const
{
	if (cells[row][column].is_alive()) return false;

	int parents = cells[row - 1][column - 1].is_alive() +
		cells[row - 1][column].is_alive() +
		cells[row - 1][column + 1].is_alive() +
		cells[row][column - 1].is_alive() +
		cells[row][column + 1].is_alive() +
		cells[row + 1][column - 1].is_alive() +
		cells[row + 1][column].is_alive() +
		cells[row + 1][column + 1].is_alive();

	if (parents < min_parents || parents > max_parents) return false;

	return true;
}

void grid::update(const grid& next)
{
	for (int row = 1; row < rowMax; row++)
	{
		for (int column = 1; column < colMax; column++)
		{
			cells[row][column] = next.cells[row][column];
		}
	}
}

void calculate(grid& old_generation, grid& new_generation)
{
	for (int row = 1; row < rowMax; row++)
	{
		for (int column = 1; column < colMax; column++)
		{
			if (old_generation.will_survive(row, column))
				new_generation.create(row, column);
			else if (old_generation.will_create(row,column))
				new_generation.create(row, column);
		}
	}
}