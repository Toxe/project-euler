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

int nth_prime(int n)
{
    int i = 1;
    int number = 1;

    while (i <= n) {
        ++number;

        if (is_prime(number))
            ++i;
    }

    return number;
}

int euler007()
{
    return nth_prime(10001);
}

int main()
{
    std::cout << euler007() << std::endl;
}
