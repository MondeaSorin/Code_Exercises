#include "InsuficientFundsException.h"

const char* InsuficientFundsException::what() const noexcept
{
    return "Insuficient funds";
}
