#include <iostream>

int euler006()
{
    int sum = 0;
    int sum_of_squares = 0;

    for (int i = 1; i <= 100; ++i) {
        sum += i;
        sum_of_squares += i * i;
    }

    return sum * sum - sum_of_squares;
}

int main()
{
    std::cout << euler006() << std::endl;
}
