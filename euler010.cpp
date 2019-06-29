#include "common.h"
#include <iostream>

long long euler010()
{
    long long sum = 0;

    for (int i = 1; i < 2000000; ++i)
        if (is_prime(i))
            sum += i;

    return sum;
}

int main()
{
    std::cout << euler010() << std::endl;
}
