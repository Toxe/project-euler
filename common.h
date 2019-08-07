#ifndef PROJECT_EULER_COMMON_H_
#define PROJECT_EULER_COMMON_H_

#include <cmath>
#include <vector>

int nth_prime(int n);

template <typename T>
bool is_prime(T number)
{
    if (number < 2)
        return false;

    const T root = static_cast<T>(std::sqrt(number));

    for (T i = 2; i <= root; ++i)
        if (number % i == 0)
            return false;

    return true;
}

template <typename T>
std::vector<T> prime_factorization(const T number)
{
    std::vector<T> factors;
    T n = number;
    T f = 2;
    const T root = static_cast<T>(std::sqrtf(static_cast<float>(n)));

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

template <typename T>
std::vector<T> integer_factorization(const T number)
{
    std::vector<T> factors;

    for (T i = 1; i <= number; ++i)
        if (number % i == 0)
            factors.push_back(i);

    return factors;
}

#endif // PROJECT_EULER_COMMON_H_
