#include "logic.hpp"
#include <cstdlib>

namespace Life
{
    void Prepare(char** grid, int rows, int cols, double density)
    {
        for (int i {}; i < rows; i++)
            for (int j {}; j < cols; j++)
                grid[i][j] = (static_cast<double>(std::rand()) / RAND_MAX < density) ? 1 : 0;
    }

    void Next(char** grid, char** buffer, int rows, int cols)
    {
        for (int i {}; i < rows; i++)
        {
            for (int j {}; j < cols; j++)
            {
                int total = Neighbors(grid, rows, cols, i, j);
                buffer[i][j] = grid[i][j] ? (total == 2 || total == 3) : (total == 3);
            }
        }
    }

    int Neighbors(char** grid, int rows, int cols, int r, int c)
    {
        int total {};
        static constexpr int dr[8] { -1, -1, -1, 0, 0, 1, 1, 1 };
        static constexpr int dc[8] { -1, 0, 1, -1, 1, -1, 0, 1 };

        for (int i {}; i < 8; i++)
            total += grid[(r + dr[i] + rows) % rows][(c + dc[i] + cols) % cols];

        return total;
    }
}