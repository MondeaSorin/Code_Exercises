#include "Account.h"

Account::Account(std::string name, double balance)
    : name{ name }, balance{ balance } { }

double Account::get_balance() const 
{
    return balance;
}

std::ostream& operator<<(std::ostream& os, const Account& account) 
{
    os << "[Account: " << account.name << ": " << account.balance << "]";
    return os;
}