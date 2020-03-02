// Power digit sum

#include <iostream>
#include <numeric>
#include <vector>

int euler016(int exp)
{
    std::vector<char> digits{1};

    for (int i = 0; i < exp; ++i) {
        char carry_over = 0;

        for (auto& n : digits) {
            n = 2 * n + carry_over;

            if (n >= 10) {
                n -= 10;
                carry_over = 1;
            } else {
                carry_over = 0;
            }
        }

        if (carry_over > 0)
            digits.push_back(carry_over);
    }

    return std::accumulate(digits.begin(), digits.end(), 0);
}

int main()
{
    std::cout << euler016(1000) << std::endl;
}
