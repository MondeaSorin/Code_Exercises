#pragma once
#include <exception>

class IllegalBalanceException :
    public std::exception
{
public:
    virtual ~IllegalBalanceException() = default;
    const char* what() const noexcept override;
};

