#pragma once
#include<exception>

class InsuficientFundsException :
    public std::exception
{
public:
    virtual ~InsuficientFundsException() = default;
    const char* what() const noexcept override;
};

