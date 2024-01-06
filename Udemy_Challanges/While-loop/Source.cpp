#include <iostream>
#include <vector>

using namespace std;

int count_numbers(const vector<int>& vec)
{
	int index{};
	int count{};
	const int stop_value{ -99 };
	
	if (vec.empty()) return 0;

	//cout << vec.at(index) << endl;
	//cout << index << endl;
	//cout << stop_value << endl;
	//cout << vec.size() << endl;

	//vector<int>::const_iterator it = find(vec.begin(), vec.end(), 2);
	//cout << *it;

	cout << ((vec.at(index) != stop_value) && (index < vec.size())) << endl;

	// De intrebat pe denis a && b != b && a  ???!??!?
	while (vec.at(index++) != stop_value && index < vec.size())
	{
		++count;
	}

	return count;

}

int count_numbers2(const vector<int>& vec)
{
	int count{};
	const int stop_value{ -99 };

	if (vec.empty()) return 0;
	const auto it = find(vec.begin(), vec.end(), stop_value);
	if (it == vec.end())
		return vec.size();
	else
		count = distance(vec.begin(), it);

	return count;
}

int main()
{
	vector<int> v{ 1,2,3,-99,4,5 };

	auto element = v.begin();

	cout << "The number of elements untill -99 is: " << count_numbers2(v) << endl;
}