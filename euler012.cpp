#include "common.h"
#include <algorithm>
#include <iostream>

int nth_triangular_number(int n)
{
    return (n * (n + 1)) / 2;
}

int euler012()
{
    std::size_t max = 0;
    int n = 1;

    while (true) {
        int triangular_number = nth_triangular_number(n);
        auto factors{integer_factorization(triangular_number)};

        if ((max = std::max(max, factors.size())) > 500)
            return triangular_number;

        ++n;
    }

    return 0;
}

int main()
{
    std::cout << euler012() << std::endl;
}
