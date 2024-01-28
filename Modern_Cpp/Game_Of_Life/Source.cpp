#include <iostream>
#include "grid.h"

using namespace std;

int main()
{
	cout << "Conway's game of Life" << endl;
	cout << "Press the return key to display each generation" << endl;


	grid current_generation;
	current_generation.randomize();

	while (true)
	{
		current_generation.draw();
		cin.get();
		grid next_generation;
		calculate(current_generation, next_generation);
		current_generation.update(next_generation);
	}

}