#include <iostream>
#include "URL.h"

using namespace std;

void processURL(string protocol, string resource)
{
	try
	{
		URL* url = new URL(protocol, resource);
		url->displayURL();
	}
	catch (const std::runtime_error& ex)
	{
		cerr << "Error: " << ex.what() << endl;
	}
}

std::string exclaim(std::string str)
{
	for (char& c : str)
	{
		if (!std::isalnum(c) && c != ' ') c = '!';
	}

	return str;
}
int main()
{
	string str = "To be, or not to be, that is the question : ";
	cout << exclaim(str);

	processURL("hppt:/", "google.com/");
	processURL("http:/", "google.com/");
	processURL("http:/", "www.google.com/");
	processURL("http://", "www.google.com/");
	processURL("https://", "www.google.com/");
}
