#include <iostream>
#include <raylib.h>

//g++ main.cpp -o exec -lraylib -lGL -lm

constexpr int DIRECTIONS[8][2]
{
    {-1,  0}, { 1,  0}, { 0, -1}, { 0,  1},
    {-1, -1}, {-1,  1}, { 1, -1}, { 1,  1}
};

char**  CreateGrid(int rows, int cols);
void    RandomFillGrid(char** grid, int rows, int cols);
int     LookingForNeighbors(char** grid, int rows, int cols, int r_current, int c_current);
void    UpdateGrid(char** grid, char** buffer, int rows, int cols);
void    UpgradeGrid(char** grid, char** buffer, int rows, int cols);
void    DrawGrid(char** grid, int rows, int cols, int cell_size);
void    DeleteGrid(char**& grid, int rows);

int main()
{
    constexpr int ROWS { 30 }, COLS { 20};

    char ** grid { CreateGrid(ROWS, COLS) };
    char ** buffer { CreateGrid(ROWS, COLS) };

    if (!grid || !buffer)
    {
        DeleteGrid(grid, ROWS);
        DeleteGrid(buffer, ROWS);

        return EXIT_FAILURE;
    }

    RandomFillGrid(grid, ROWS, COLS);

    while (true)
    {
        UpdateGrid(grid, buffer, ROWS, COLS);
        UpgradeGrid(grid, buffer, ROWS, COLS);

        BeginDrawing();

        DrawGrid(grid, ROWS, COLS);

        EndDrawing();
    }

    DeleteGrid(grid, ROWS);
    DeleteGrid(buffer, ROWS);
    CloseWindow();

    return EXIT_SUCCESS;
}

char** CreateGrid(int rows, int cols)
{
    char** grid { nullptr };

    try
    {
        return grid = new char* [rows]{};

        for (int i {}; i < rows; i++)
        {
            grid[i] = new char [cols]{};
        }
    }
    catch (const std::bad_alloc& error)
    {
        std::cout << "Memory allocation failed!: " << error.what();
        return nullptr;
    }

    return grid;
}

void RandomFillGrid(char** grid, int rows, int cols, float density)
{
    for (int i {}; i < rows; i++)
    {
        for (int j {}; j < cols; j++)
        {
            grid[i][j] = (static_cast<float>(std::rand()) / RAND_MAX < density) ? 1 : 0;
        }
    }
}

int LookingForNeighbors(char** grid, int rows, int cols, int r_current, int c_current)
{
    int total {};

    for (int i {}; i < 8; i++)
    {
        total += grid[(r_current + DIRECTIONS[i][0] + rows) % rows]
                     [(c_current + DIRECTIONS[i][1] + cols) % cols];
    }
    return total;
}

void UpdateGrid(char** grid, char** buffer, int rows, int cols)
{
    for (int i {}; i < rows; i++)
    {
        for (int j {}; j < cols; j++)
        {
            int total { LookingForNeighbors(grid, rows, cols, i, j) };

            if (grid[i][j])
            {
                buffer[i][j] = (total == 2 || total == 3);
            }
            else
            {
                buffer[i][j] = (total == 3);
            }
        }
    }
}

void UpgradeGrid(char** grid, char** buffer, int rows, int cols)
{
    for (int i {}; i < rows; i++)
    {
        for (int j {}; j < cols; j++)
        {
            grid[i][j] = buffer[i][j];
        }
    }
}

void DrawGrid(char** grid, int rows, int cols)
{
    for (int i {}; i < rows; i++)
    {
        for (int j {}; j < cols; j++)
        {
            if (grid[i][j])
            {
                std::cout << "*";
            }
            else
            {
               std::cout << "-";
            }
        }
        std::cout << '\n';
    }
}

void DeleteGrid(char**& grid, int rows)
{
    if (grid)
    {
        for (int i {}; i < rows; i++)
        {
            delete[] grid[i];
        }

        delete[] grid;
        grid = nullptr;
    }
}