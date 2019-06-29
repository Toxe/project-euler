#include "common.h"
#include <iostream>

long long euler003()
{
    const auto factors = prime_factorization(600851475143);
    return factors.back();
}

int main()
{
    std::cout << euler003() << std::endl;
}
