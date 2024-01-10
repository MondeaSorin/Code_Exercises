#include "Trust_Account.h"

int Trust_Account::max_withdrawal = 3;

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
	:Savings_Account(name, balance, int_rate) 
{
	this->withdrawals_left = max_withdrawal;
}

bool Trust_Account::deposit(double amount)
{
	if (amount >= bonus_threshold) return Savings_Account::deposit(amount + bonus_amount);
	return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount)
{
	if (withdrawals_left <= 0) return false;

	withdrawals_left--;
	return Account::withdraw(amount);
}

std::ostream& operator<<(std::ostream& os, const Trust_Account& account)
{
	os << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
	return os;
}
