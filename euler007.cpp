#include "common.h"
#include <iostream>

int euler007()
{
    return nth_prime(10001);
}

int main()
{
    std::cout << euler007() << std::endl;
}
