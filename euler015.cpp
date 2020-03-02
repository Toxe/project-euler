// Lattice paths

#include <iostream>

long long euler015(int grid_size)
{
    // create grid with one additional column and row
    const int grid_size_plus_one = grid_size + 1;
    std::unique_ptr<long long[]> grid{new long long[static_cast<std::size_t>(grid_size_plus_one * grid_size_plus_one)]};

    // fill an additional column and row with 1
    for (int i = 0; i < grid_size_plus_one; ++i) {
        grid[static_cast<std::size_t>(i * grid_size_plus_one + grid_size)] = 1;
        grid[static_cast<std::size_t>(grid_size * grid_size_plus_one + i)] = 1;
    }

    for (int y = grid_size - 1; y >= 0; --y) {
        for (int x = grid_size - 1; x >= 0; --x) {
            grid[static_cast<std::size_t>(y * grid_size_plus_one + x)] = grid[static_cast<std::size_t>(y * grid_size_plus_one + x + 1)] +
                                                                         grid[static_cast<std::size_t>((y + 1) * grid_size_plus_one + x)];
        }
    }

    return grid[0];
}

int main()
{
    std::cout << euler015(20) << std::endl;
}
