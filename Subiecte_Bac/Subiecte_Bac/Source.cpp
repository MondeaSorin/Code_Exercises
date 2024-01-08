#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
	/*
	// Teoretic:
	// Subiectul 1: 1.b, 2.c 3.a 4.b 5.d
	// 
	// Subiectul 2:

	//int n{};
	//int c{};
	//int p{};
	//int x{};
	//cin >> n;

	//while (n > 0)
	//{
	//	int a{};
	//	int b{};

	//	cout << "Introduceti a si b: ";
	//	cin >> a >> b;

	//	c = a;
	//	p = 1;

	//	while (a > 9)
	//	{
	//		a /= 10;
	//		p *= 10;
	//	}

	//	a = a * p + b;
	//	if (a != c)
	//	{
	//		++x;
	//	}
	//	--n;
	//}

	//cout << "Valoarea lui x este: ";
	//cout << x;
	*/

	int m{};
	int n{};

	int* a{ nullptr };
	int* b{ nullptr };

	int fa[100]{ 0 };
	int fb[100]{ 0 };

	ifstream ifs;
	ifs.open("date.in");
	if (ifs.is_open())
	{
		ifs >> m;
		ifs >> n;

		a = new int[m];
		b = new int[n];

		for (int i = 0; i < m; ++i)
		{
			ifs >> a[i];
			fa[a[i]]++;
		}

		for (int i = 0; i < n; ++i)
		{
			ifs >> b[i];
			fb[b[i]]++;
		}

		ifs.close();
	}

	// Debugg
	cout << "m = " << m << endl
		<< "n = " << n << endl
		<< "a = [ ";
	for (int i = 0; i < m; i++)
	{
		cout << a[i] << " ";
	}

	cout << "]" << endl
		<< "b = [ ";
	for (int i = 0; i < n; i++)
	{
		cout << b[i] << " ";
	}
	cout << "]" << endl;

	int perechi{};
	for (int i = 0; i < 100; i++)
	{
		perechi += min(fa[i], fb[i]);
	}
	cout << "Numarul de perechi este: " << perechi << endl; 
	
}