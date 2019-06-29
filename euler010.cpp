#include <cmath>
#include <iostream>

template <typename T>
bool is_prime(T number)
{
    if (number < 2)
        return false;

    const T root = std::sqrt(number);

    for (T i = 2; i <= root; ++i)
        if (number % i == 0)
            return false;

    return true;
}

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
