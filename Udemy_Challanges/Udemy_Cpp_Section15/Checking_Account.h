#pragma once
#include <iostream>
#include "Account.h"

class Checking_Account :
    public Account
{
    friend std::ostream& operator<<(std::ostream& os, const Checking_Account& rhs);
private:
    static constexpr double _TRANSACTION_FEE = 1.5;
    static constexpr const char* _DEFAULT_CHEKCING_ACCOUNT_NAME = "Unnamed checking account";
    static constexpr double _DEFALT_BALANCE = 0.0;
public:
    Checking_Account(std::string name = _DEFAULT_CHEKCING_ACCOUNT_NAME, double balance = _DEFALT_BALANCE);
    bool withdraw(double amount);
};

