#include <iostream>
#include "Account_Util.h"

// Displays Account objects in a  vector of Account objects 
void display(const std::vector<Account*>& accounts) 
{
    std::cout << "\n=== Accounts ==========================================" << std::endl;
    for (const auto& acc : accounts)
        acc->print(std::cout);
    std::cout << std::endl;
}

// Deposits supplied amount to each Account object in the vector
void deposit(std::vector<Account*>& accounts, double amount) 
{
    std::cout << "\n=== Depositing to Accounts =================================" << std::endl;
    for (auto& acc : accounts) 
    {
        if (acc->deposit(amount))
        {
            std::cout << "Deposited " << amount << " to "; acc->print(std::cout); std::cout << std::endl;
        }
        else
        {
            std::cout << "Failed Deposit of " << amount << " to "; acc->print(std::cout); std::cout << std::endl;
        }
    }
}

// Withdraw amount from each Account object in the vector
void withdraw(std::vector<Account*>& accounts, double amount) 
{
    std::cout << "\n=== Withdrawing from Accounts ==============================" << std::endl;
    for (auto& acc : accounts) 
    {
        if (acc->withdraw(amount))
        {
            std::cout << "Withdrew " << amount << " from "; acc->print(std::cout); std::cout << std::endl;
        }
        else
        {
            std::cout << "Failed Withdrawal of " << amount << " from "; acc->print(std::cout); std::cout << std::endl;
        }
    }
}