#include <iostream>

using namespace std;

// Section 6
// Challenge

/*
    Frank's Carpet Cleaning Service
    Charges:
        $25 per small room
        $35 per large room
    Sales tax rate is 6%
    Estimates are valid for 30 days

    Prompt the user for the number of small and large rooms they would like cleaned
    and provide an estimate such as:

Estimate for carpet cleaning service
Number of small rooms: 3
Number of large rooms: 1
Price per small room: $25
Price per large room: $35
Cost : $110
Tax: $6.6
===============================
Total estimate: $116.6
This estimate is valid for 30 days
*/

int main()
{
    #pragma region Constants
    const int small_room_price{ 25 };
    const int large_room_price{ 35 };
    const double sales_tax{ 0.06 };
    #pragma endregion

    #pragma region Variables
    int number_of_small_rooms{ 0 };
    int number_of_large_rooms{ 0 };
    int cost{ 0 };
    double tax{ 0.0 };
    double total_estimate{ 0.0 };
    #pragma endregion

    cout << "Hello, welcome to Frank's Carpet Cleaning Service" << endl;
    cout << "\nHow many small rooms would you like cleaned? "; cin >> number_of_small_rooms;
    cout << "How many large rooms would you like cleaned? "; cin >> number_of_large_rooms;

    cost = (number_of_small_rooms * small_room_price) + (number_of_large_rooms * large_room_price);
    tax = cost * sales_tax;
    total_estimate = cost + tax;

    cout << "\nEstimate for carpet cleaning service" << endl;
    cout << "Number of small rooms: " << number_of_small_rooms << endl;
    cout << "Number of large rooms: " << number_of_large_rooms << endl;
    cout << "Price per small room: $" << small_room_price << endl;
    cout << "Price per large room: $" << large_room_price << endl;
    cout << "Cost: $" << cost << endl;
    cout << "Tax: $" << tax << endl;
    cout << "====================================" << endl;
    cout << "Total estimate: $" << total_estimate << endl;
    cout << "This estimate is valid for 30 days" << endl;
}