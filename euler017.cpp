#include <iostream>
#include <string>
#include <vector>

const std::vector<std::string> num_tens{"twenty",
                                        "thirty",
                                        "forty",
                                        "fifty",
                                        "sixty",
                                        "seventy",
                                        "eighty",
                                        "ninety"};

const std::vector<std::string> num_one_to_nineteen{"one",
                                                   "two",
                                                   "three",
                                                   "four",
                                                   "five",
                                                   "six",
                                                   "seven",
                                                   "eight",
                                                   "nine",
                                                   "ten",
                                                   "eleven",
                                                   "twelve",
                                                   "thriteen",
                                                   "fourteen",
                                                   "fifteen",
                                                   "sixteen",
                                                   "seventeen",
                                                   "eighteen",
                                                   "nineteen"};

std::string tens(int n)
{
    std::string s{num_tens[static_cast<std::string::size_type>((n / 10) - 2)]};

    if (n % 10 > 0)
        s += " ";

    return s;
}

std::string one_to_nineteen(int n)
{
    return num_one_to_nineteen[static_cast<std::string::size_type>(n - 1)];
}

std::string hundreds(int n)
{
    std::string s{one_to_nineteen(n / 100) + " " + "hundred"};

    if (n % 100 > 0)
        s += " and ";

    return s;
}

std::string write(int n)
{
    std::string s;

    if (n == 1000)
        return "one thousand";

    if (n >= 100) {
        s += hundreds(n);
        n = n % 100;
    }

    if (n >= 20) {
        s += tens(n);
        n -= 10 * (n / 10);
    }

    if (n >= 1 && n <= 19)
        s += one_to_nineteen(n);

    return s;
}

int euler017()
{
    int sum = 0;

    for (int i = 1; i <= 1000; ++i) {
        std::string s{write(i)};
        sum += s.size() - static_cast<std::string::size_type>(std::count(s.begin(), s.end(), ' '));
    }

    return sum;
}

int main()
{
    std::cout << euler017() << std::endl;
}
