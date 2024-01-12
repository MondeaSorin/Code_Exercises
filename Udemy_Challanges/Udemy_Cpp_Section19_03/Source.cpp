#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
#pragma region Variables
	string message;
	int word_count{};
	int total_words{};
	ifstream f;
	ofstream of;
	int row_crt{1};
#pragma endregion
	
	cout << "Enter the substring to search for: "; cin >> message;
	for (char& c : message)
		c = tolower(c);

	f.open("romeoandjuliet.txt");
	if (f.is_open())
	{
		string word;
		while (!f.eof())
		{
			f >> word;
			
			// case insensitive
			for (char& c : word)
				c = tolower(c);

			if (word.find(message) != string::npos)
				word_count++;
			total_words++;
		}
		f.close();
	}
	else
	{
		cerr << "Couldn't open the file" << endl;
	}

	cout << total_words << " words were searched..." << endl;
	cout << "The substring " << message << " was found " << word_count << " times" << endl;

	f.open("romeoandjuliet.txt");
	of.open("numberedfile.txt");

	if (f.is_open() && of.is_open())
	{
		string row;
		while (!f.eof()) 
		{
			getline(f, row);
			if (!row.empty())
				row.insert(0, (to_string(row_crt++) + "   "));
			row += "\n";
			of << row;
		}
		cout << "copy complete" << endl;
	}
	else
	{
		cerr << "Can't open the spcified file" << endl;
	}

}