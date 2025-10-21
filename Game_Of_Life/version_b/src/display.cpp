#include "display.hpp"
#include <string>

namespace Display
{
    void Show(char** grid, int rows, int cols)
    {
        int offset = (120 - cols) / 2;
        for (int i {}; i < rows; i++)
        {
            std::cout << std::string(offset, ' ');
            for (int j {}; j < cols; j++)
                std::cout << (grid[i][j] ? '+' : ' ');
            std::cout << '\n';
        }
    }
}