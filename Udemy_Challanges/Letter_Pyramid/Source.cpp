#include <iostream>
#include <string>

using namespace std;

void print_pyramid(string first_half, int spaces = 0)
{
	if (first_half.empty()) return;
	string second_half{ first_half };
	string base = first_half;
	second_half.pop_back();
	reverse(second_half.begin(), second_half.end());
	base += second_half;

	int counter = spaces;
	while (counter > 0)
	{
		base.insert(0, " ");
		counter--;
	}

	spaces++;
	first_half.pop_back();

	cout << base << endl;
	print_pyramid(first_half, spaces);
}

int add_number(int a, int b)
{
	return a + b;
}

int main()
{
	//string initial_string{};
	//cout << "Enter a string to form a pyramid with: "; cin >> initial_string;

	//// string pyramid_base{ initial_string };
	//// initial_string.pop_back();
	//// reverse(initial_string.begin(), initial_string.end());
	//// pyramid_base += initial_string;
	//// Debugg
	//// cout << initial_string << endl;
	//// cout << pyramid_base;

	//print_pyramid(initial_string);


	// 2nd approach

	// testing pointers to functions -- not related to current problem
	//int (*ptr)(int, int);
	//ptr = &add_number;

	//int result = ptr(1, 2);

	cout << "Welcome to my Letter Pyramid!\nPlease enter a string!" << endl;

	string pyramid_base{}; getline(cin, pyramid_base);
	string new_row{ pyramid_base };
	string pyramid{};
	int j{};

	while (pyramid_base.size() != 0)
	{
		new_row.pop_back();
		new_row.insert(0, pyramid_base);
		reverse(new_row.begin() + pyramid_base.length(), new_row.end());
		pyramid.insert(j, new_row);

		pyramid.insert(0, "\n");

		for (int t{ j + 1 }; t > 0; t--) 
		{
			pyramid.insert(0, " ");
		}

		pyramid_base.pop_back();
		new_row = pyramid_base;

		j++;
	}

	cout << pyramid;
}