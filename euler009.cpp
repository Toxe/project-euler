// Special Pythagorean triplet

#include <iostream>

int euler009()
{
    for (int a = 1; a <= (1000/3); ++a) {
        for (int b = a + 1; b <= (999 - a) / 2; ++b) {
            int c = 1000 - (a + b);

            if ((a * a) + (b * b) == (c * c))
                return a * b * c;
        }
    }

    return 0;
}

int main()
{
    std::cout << euler009() << std::endl;
}
