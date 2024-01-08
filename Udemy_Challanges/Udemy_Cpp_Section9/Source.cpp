#include <iostream>
#include <vector>

using namespace std;

// Section 9
// Challenge
/*
    This challenge is about using a collection (list) of integers and allowing the user
    to select options from a menu to perform operations on the list.

    Your program should display a menu options to the user as follows:

    P - Print numbers
    A - Add a number
    M - Display mean of the numbers
    S - Display the smallest number
    L - Display the largest number
    Q - Quit

    Enter your choice:

The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be
displayed again.


If the user enters 'P' or 'p', you should display all of the elements (ints) in the list.
If the list is empty you should display "[] - the list is empty"
If the list is not empty then all the list element should be displayed inside square brackets separated by a space.
For example, [ 1 2 3 4 5 ]

If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list
which you will add to the list and then display it was added. For example, if the user enters 5
You should display, "5 added".
Duplicate list entries are OK

If the user enters 'M' or 'm'  you should calculate the mean or average of the elements in the list and display it.
If the list is empty you should display, "Unable to calculate the mean - no data"

If the user enters 'S' or 's' you should display the smallest element in the list.
For example, if the list contains [2 4 5 1],  you should display, "The smallest number is 1"
If the list is empty you should display, "Unable to determine the smallest number - list is empty"

If the user enters 'L' or 'l' you should display the largest element in the list
For example, if the list contains [2 4 5 1], you should display, "The largest number is 5"
If the list is empty you should display, "Unable to determine the largest number - list is empty"

If the user enters 'Q' or 'q' then you should display 'Goodbye" and the program should terminate.

Before you begin. Write out the steps you need to take and decide in what order they should be done.
Think about what loops you should use as well as what you will use for your selection logic.

This exercise can be challenging! It may likely take a few attempts before you complete it -- that's OK!

Finally, be sure to test your program as you go and at the end.

Hint: Use a vector!

Additional functionality if you wish to extend this program.

- search for a number in the list and if found display the number of times it occurs in the list
- clearing out the list (make it empty again) (Hint: the vector class has a .clear() method)
- don't allow duplicate entries
- come up with your own ideas!

Good luck!

*/

void print_menu()
{
    cout << "P - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "C - Clear vector" << endl;
    cout << "F - Find a number" << endl;
    cout << "Q - Quit" << endl << endl;
}

void print_numbers(const vector<int>& vec)
{
    if (vec.empty())
    {
        cout << "[] - the list is empty" << endl;
        return;
    }

    cout << "[ ";
    for (const auto& element : vec)
    {
        cout << element << " ";
    }
    cout << "]" << endl;
}

void add_number(vector<int>& vec)
{
    int number{};
    cout << "Number to add: "; cin >> number;
    const auto it = find(vec.begin(), vec.end(), number);
    if (it == vec.end())
    {
        vec.push_back(number);
    }
}

double mean(vector<int>& vec)
{
    if (vec.empty())
    {
        // Note: Indicated approach would be to throw a new exception and handle it inside main
        cout << "Unable to calculate the mean - no data" << endl;
        return 0.0;
    }

    double mean{};
    
    for (size_t i = 0; i < vec.size(); i++)
    {
        mean += vec.at(i);
    }

    mean /= vec.size();
    return mean;
}

void smallest_number(const vector<int>& vec)
{
    if (vec.empty())
    {
        cout << "Unable to determine the smallest number - list is empty" << endl;
        return;
    }

    int smallest = vec.at(0);
    for (const auto& element : vec)
    {
        if (smallest > element)
        {
            smallest = element;
        }
    }

    cout << "The smallest element is: " << smallest << endl;
}

void largest_number(const vector<int>& vec)
{
    if (vec.empty())
    {
        cout << "Unable to determine the largest number - list is empty" << endl;
        return;
    }

    int largest = vec.at(0);
    for (const auto& element : vec)
    {
        if (largest < element)
        {
            largest = element;
        }
    }

    cout << "The largest element is: " << largest << endl;
}

void find_number(const vector<int>& vec)
{
    int number{};
    cout << "Enter the number you wish to find: "; cin >> number;

    // Method 1: without std::find

    //for (size_t i = 0; i < vec.size(); ++i)
    //{
    //    if (vec.at(i) == number)
    //    {
    //        cout << "Number found! It's index is: " << i << endl;
    //        return;
    //    }
    //}


    // Method 2: using std::find
    const auto it = find(vec.begin(), vec.end(), number);
    if (it != vec.end())
    {
        cout << "Number found! It's index is: " << distance(vec.begin(), it) << endl;
        return;
    }

    //
    cout << "Number doesn't exist inside the vector" << endl;
}

int main()
{
#pragma region Variables
    char selection{};
    vector<int> vec;
#pragma endregion

    do
    {
        print_menu();
        cout << "Enter your choice: "; cin >> selection;
        selection = toupper(selection);

        switch (selection)
        {
        case 'P':
            print_numbers(vec);
            break;
        case 'A':
            add_number(vec);
            break;
        case 'M':
            cout << "The mean of the numbers is: " << mean(vec) << endl;
            break;
        case 'S':
            smallest_number(vec);
            break;
        case 'L':
            largest_number(vec);
            break;
        case 'C':
            vec.clear();
            break;
        case 'F':
            find_number(vec);
            break;
        case 'Q':
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Unknown selection, please try again" << endl;
            break;
        }
    } while (selection != 'q' && selection != 'Q'); // comparing to both q and Q is no longer necesary because of the toupper function

    // Note: if we didn't use toupper, we should have duplicated each case inside 
    // the switch without emplacing the break statement in order to slip towards the 
    // next case which is the upper case version
}