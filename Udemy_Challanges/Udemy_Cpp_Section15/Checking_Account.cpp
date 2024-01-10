#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance)
    :Account(name, balance) { }

bool Checking_Account::withdraw(double amount) { return Account::withdraw(amount + _TRANSACTION_FEE); }

std::ostream& operator<<(std::ostream& os, const Checking_Account& account)
{
    os << "[Checking_Account: " << account.name << ": " << account.balance << ", TAX:$" << Checking_Account::_TRANSACTION_FEE << "]";
    return os;
}