#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Test {
private:
    int data;
public:
    Test() : data{ 0 } { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    Test(int data) : data{ data } { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    int get_data() const { return data; }
    ~Test() { std::cout << "\tTest destructor (" << data << ")" << std::endl; }
};

unique_ptr<vector<shared_ptr<Test>>> make();
void fill(vector<shared_ptr<Test>>& vec, int num);
void display(const vector<shared_ptr<Test>>& vec);


int main()
{
    unique_ptr<vector<shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();

    int num{};
    cout << "How many data points do you want to enter: "; cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);
}


unique_ptr<vector<shared_ptr<Test>>> make()
{
    return make_unique<vector<shared_ptr<Test>>>();
}

void fill(vector<shared_ptr<Test>>& vec, int num)
{
    int to_add{};
    for (int i = 0; i < num; i++)
    {
        cout << "Number to add: "; cin >> to_add;
        vec.push_back(make_shared<Test>(to_add));
    }
}

void display(const vector<shared_ptr<Test>>& vec)
{
    cout << "[ ";
    for (const auto& elem : vec)
        cout << elem->get_data() << " ";
    cout << "]" << endl;
}