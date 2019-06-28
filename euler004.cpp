#include <iostream>
#include <string>

template <typename T>
bool is_palindrome_number(const T number)
{
    const std::string s{std::to_string(number)};
    return std::equal(s.begin(), s.end(), s.rbegin());
}

int euler004()
{
    int max = 0;

    for (int i = 999; i >= 100; --i) {
        for (int j = i; j >= 100; --j) {
            const int n = i * j;

            if (n > max)
                if (is_palindrome_number(n))
                    max = n;
        }
    }

    return max;
}

int main()
{
    std::cout << euler004() << std::endl;
}
