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
    vector<Account> accounts;
    accounts.push_back(Account{});
    accounts.push_back(Account{ "Larry" });
    accounts.push_back(Account{ "Moe", 2000 });
    accounts.push_back(Account{ "Curly", 5000 });

    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);

    // Savings 
    vector<Savings_Account> sav_accounts;
    sav_accounts.push_back(Savings_Account{});
    sav_accounts.push_back(Savings_Account{ "Superman" });
    sav_accounts.push_back(Savings_Account{ "Batman", 2000 });
    sav_accounts.push_back(Savings_Account{ "Wonderwoman", 5000, 5.0 });

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 3000);

    // Checking
    vector<Checking_Account> ch_accounts;
    ch_accounts.push_back(Checking_Account{});
    ch_accounts.push_back(Checking_Account{ "Naruto" });
    ch_accounts.push_back(Checking_Account{ "Itachi", 2000 });

    display(ch_accounts);
    deposit(ch_accounts, 1000);
    withdraw(ch_accounts, 3000);

    // Trust
    vector<Trust_Account> tr_accounts;
    tr_accounts.push_back(Trust_Account{});
    tr_accounts.push_back(Trust_Account{ "Ronaldo" });
    tr_accounts.push_back(Trust_Account{ "Messi", 2000 });
    tr_accounts.push_back(Trust_Account{ "Mbappe", 5000, 5.0 });

    display(tr_accounts);
    deposit(tr_accounts, 1000);
    deposit(tr_accounts, 5000);
    withdraw(tr_accounts, 2000);
    withdraw(tr_accounts, 1000);
    withdraw(tr_accounts, 1000);
    withdraw(tr_accounts, 1000);
}