#include <algorithm>
#include <iostream>
#include <vector>

void update_row_values(const int num_values_in_current_row,
                       std::vector<short>::iterator begin_of_current_row,
                       std::vector<short>::iterator begin_of_prev_row)
{
    for (int col = 0; col < num_values_in_current_row; ++col) {
        const auto prev_left = begin_of_prev_row + col - 1;
        const auto prev_right = begin_of_prev_row + col;

        const auto prev_row_left_value = (col > 0) ? *prev_left : 0;
        const auto prev_row_right_value = (col < num_values_in_current_row - 1) ? *prev_right : 0;

        *(begin_of_current_row + col) += std::max(prev_row_left_value, prev_row_right_value);
    }
}

short euler018()
{
    constexpr int num_rows = 15;
    std::vector<short> triangle{
        75,
        95, 64,
        17, 47, 82,
        18, 35, 87, 10,
        20,  4, 82, 47, 65,
        19,  1, 23, 75,  3, 34,
        88,  2, 77, 73,  7, 63, 67,
        99, 65,  4, 28,  6, 16, 70, 92,
        41, 41, 26, 56, 83, 40, 80, 70, 33,
        41, 48, 72, 33, 47, 32, 37, 16, 94, 29,
        53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14,
        70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57,
        91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48,
        63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31,
         4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23
    };

    int num_values_in_current_row = 2;  // begin at second row
    auto begin_of_prev_row = triangle.begin();
    auto begin_of_current_row = triangle.begin() + 1;

    for (int row = 1; row < num_rows; ++row) {
        update_row_values(num_values_in_current_row, begin_of_current_row, begin_of_prev_row);

        begin_of_prev_row = begin_of_current_row;
        begin_of_current_row += num_values_in_current_row;
        ++num_values_in_current_row;
    }

    return *std::max_element(begin_of_prev_row, triangle.end());
}

int main()
{
    std::cout << euler018() << std::endl;
}
