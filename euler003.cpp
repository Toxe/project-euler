#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

template <typename T>
std::vector<T> prime_factorization(const T number)
{
    std::vector<T> factors;
    T n = number;
    T f = 2;
    const T root = std::sqrtf(n);

    while (n > 1) {
        if (n % f == 0) {
            n = n / f;
            factors.push_back(f);
        } else {
            if (++f > root) {
                factors.push_back(n); // prime
                break;
            }
        }
    }

    return factors;
}

int euler003()
{
    const auto factors = prime_factorization(600851475143);
    return factors.back();
}

int main()
{
    std::cout << euler003() << std::endl;
}
