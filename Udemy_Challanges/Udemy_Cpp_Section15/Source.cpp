#include <iostream>
#include <vector>
#include "Trust_Account.h"
#include "Checking_Account.h"
#include "Account_Util.h"

using namespace std;

int main() 
{
    cout.precision(2);
    cout << fixed;

    // Accounts
    vector<Account*> accounts;

    try
    {
        accounts.push_back(new Savings_Account{ "Hero", -10 });
    }
    catch (const IllegalBalanceException& ex)
    {
        cerr << ex.what() << endl;
    }

    accounts.push_back(new Savings_Account{});
    accounts.push_back(new Savings_Account{ "Superman" });
    accounts.push_back(new Savings_Account{ "Batman", 2000 });
    accounts.push_back(new Savings_Account{ "Wonderwoman", 5000, 5.0 });

    accounts.push_back(new Checking_Account{});
    accounts.push_back(new Checking_Account{ "Naruto" });
    accounts.push_back(new Checking_Account{ "Itachi", 2000 });

    accounts.push_back(new Trust_Account{});
    accounts.push_back(new Trust_Account{ "Ronaldo" });
    accounts.push_back(new Trust_Account{ "Messi", 9000 });
    accounts.push_back(new Trust_Account{ "Mbappe", 5000, 5.0 });
    
    try
    {
        deposit(accounts, 1000);
        withdraw(accounts, 2000);
    }
    catch (const InsuficientFundsException& ex)
    {
        cerr << ex.what() << endl;
    }

}