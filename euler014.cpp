// Longest Collatz sequence

#include <iostream>

long long next_in_collatz_sequence(long long n)
{
    if (n <= 1)
        return 1;

    if (n % 2 != 0)
        return 3 * n + 1;

    return n / 2;
}

int calc_collatz_sequence_length(long long n)
{
    int sequence_length = 1;

    while (n > 1) {
        n = next_in_collatz_sequence(n);
        ++sequence_length;
    }

    return sequence_length;
}

int euler014()
{
    int longest_sequence = 0;
    int longest_sequence_number = 0;

    for (int i = 1; i < 1000000; ++i) {
        int length = calc_collatz_sequence_length(i);

        if (length > longest_sequence) {
            longest_sequence = length;
            longest_sequence_number = i;
        }
    }

    return longest_sequence_number;
}

int main()
{
    std::cout << euler014() << std::endl;
}
