#pragma once
#include <iostream>
#include "Account.h"

class Checking_Account :
    public Account
{
private:
    static constexpr double _TRANSACTION_FEE = 1.5;
    static constexpr const char* _DEFAULT_CHEKCING_ACCOUNT_NAME = "Unnamed checking account";
    static constexpr double _DEFALT_BALANCE = 0.0;
public:
    Checking_Account(std::string name = _DEFAULT_CHEKCING_ACCOUNT_NAME, double balance = _DEFALT_BALANCE);
    virtual bool withdraw(double amount) override;
    virtual bool deposit(double amount) override;
    virtual void print(std::ostream& out) const override;
};

