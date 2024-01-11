#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance)
    :Account(name, balance) { }

bool Checking_Account::withdraw(double amount)
{
    amount += _TRANSACTION_FEE;
    if (balance - amount >= 0)
    {
        balance -= amount;
        return true;
    }
    else
        return false;
}

bool Checking_Account::deposit(double amount)
{
    if (amount < 0) return false;

    balance += amount;
    return true;
}

void Checking_Account::print(std::ostream& out) const
{
    out << "[Checking_Account: " << name << ": " << balance << ", TAX:$" << Checking_Account::_TRANSACTION_FEE << "]";
}