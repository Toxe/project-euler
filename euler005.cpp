#include <iostream>
#include <numeric>

int euler005()
{
    int n = 1;

    for (int i = 2; i <= 20; ++i)
        n = std::lcm(n, i);

    return n;
}

int main()
{
    std::cout << euler005() << std::endl;
}
