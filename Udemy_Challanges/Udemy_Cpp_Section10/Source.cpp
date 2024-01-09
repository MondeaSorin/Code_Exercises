#include <iostream>
#include <string>

using namespace std;

int main()
{
	string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	string key{ "XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr" };

	string message;

	cout << "Eneter a message to encrypt: "; getline(cin, message);

	for (char& c : message) 
	{
		size_t pos = alphabet.find(c);

		if (pos != string::npos)
		{
			c = key.at(pos);
		}
	}

	cout << "Your encrypted message is: " << message << endl;

	for (char& c : message)
	{
		size_t pos = key.find(c);
		if (pos != string::npos)
		{
			c = alphabet.at(pos);
		}
	}

	cout << "The decrypted message is: " << message << endl;
}