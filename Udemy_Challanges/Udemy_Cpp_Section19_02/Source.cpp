#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

static int _HEADER_LENGTH_ = 20;

int process_response(const string& response, const string& answer_key) 
{
	if (answer_key.length() != response.length()) return -1;
	int correct_answers{};

	for (size_t i{ 0 }; i < answer_key.length(); ++i)
		if (response[i] == answer_key[i])
			correct_answers++;
	return correct_answers;
}

void display_header()
{
	cout << setw(_HEADER_LENGTH_ / 2) << left << "Student"
		<< setw(_HEADER_LENGTH_ / 2) << right << "Score" << endl
		<< setfill('-') << setw(_HEADER_LENGTH_) << "" << endl << setfill('\0');
}

int main()
{
#pragma region Variables
	ifstream f;
	string answer_key{};
	string name{};
	string response{};
	int running_sum{};
	int total_students{};
	double average_score{};
#pragma endregion

	f.open("responses.txt");
	if (f.is_open())
	{
		f >> answer_key;
		display_header();
		while (f >> name >> response)
		{
			cout << setw(_HEADER_LENGTH_ / 2) << left << name
				<< setw(_HEADER_LENGTH_ / 2) << right << process_response(response, answer_key) << endl;
			running_sum += process_response(response, answer_key);
			total_students++;
		}

		average_score = total_students > 0 ? static_cast<double>(running_sum) / total_students : 0;
		cout << setfill('-') << setw(_HEADER_LENGTH_) << "" << setfill('\0') << endl;
		cout << "Average score" << setw(_HEADER_LENGTH_ - strlen("Average score")) << right << average_score << endl;
		
		f.close();
	}
}