#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

char**  CreateArray(int rows, int cols);
void    PrepareCondition(char** grid, int rows, int cols, double density);
void    NextCondition(char** grid, char** buffer, int rows, int cols);
int     SearchNeighbors(char** grid, int rows, int cols, int r_current, int c_current);
void    ApplyCondition(char** grid, char** buffer, int rows, int cols);
void    ShowCondition(char** grid, int rows, int cols);
void    DeleteArray(char**& grid, int rows);


int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    constexpr short const ROWS { 20 }, COLS { 40 }, SLEEP_TIME { 150 };
    constexpr double DENSITY { 0.2 };

    char ** grid {  CreateArray(ROWS, COLS) },
         ** buffer {  CreateArray(ROWS, COLS) };

    if (!grid || !buffer)
    {
        return EXIT_FAILURE;
    }

    PrepareCondition(grid, ROWS, COLS, DENSITY);

    while (true)
    {
        std::cout << "\x1B[2J\x1B[H";
        ShowCondition(grid, ROWS, COLS);
        std::cout.flush();
        
        NextCondition(grid, buffer, ROWS, COLS);
        ApplyCondition(grid, buffer, ROWS, COLS);

        std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
    }

    DeleteArray(grid, ROWS);
    DeleteArray(buffer, ROWS);

    return EXIT_SUCCESS;
}


char** CreateArray(int rows, int cols)
{
    char** array { nullptr };

    try
    {
        array = new char* [rows] {};

        for (int i {}; i < rows; i ++)
        {
            array[i] = new char [cols] {};
        }
    }
    catch (const std::bad_alloc& error)
    {   
        DeleteArray(array, rows);

        std::cout << "Memory allocation failed!: " << error.what();

        return nullptr;
    }
    
    return array;
}

void PrepareCondition(char** grid, int rows, int cols, double density)
{
    for (int i {}; i < rows; i ++)
    {
        for (int j {}; j < cols; j ++)
        {
            grid[i][j] = (static_cast<double>(std::rand()) / RAND_MAX < density) ? 1 : 0;
        }
    }
}

void NextCondition(char** grid, char** buffer, int rows, int cols)
{
    for (int i {}; i < rows; i ++)
    {
        for (int j {}; j < cols; j ++)
        {
            int total { SearchNeighbors(grid, rows, cols, i, j) };

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

int SearchNeighbors(char** grid, int rows, int cols, int r_current, int c_current)
{
    int total {};

    static constexpr int dr[8] { -1, -1, -1, 0, 0, 1, 1, 1 };
    static constexpr int dc[8] { -1, 0, 1, -1, 1, -1, 0, 1 };

    for (int i {}; i < 8; i ++)
    {
        total += grid[(r_current + dr[i] + rows) % rows][(c_current + dc[i] + cols) % cols];
    }

    return total;
}

void ApplyCondition(char** grid, char** buffer, int rows, int cols)
{
    for (int i {}; i < rows; i ++)
    {
        for (int j {}; j < cols; j ++)
        {
            grid[i][j] = buffer[i][j];
        }
    }        
}

void ShowCondition(char** grid, int rows, int cols)
{
    int offset { (120 - cols) / 2 };

    for (int i {}; i < rows; i ++)
    {
        std::cout << std::string(offset, ' ');
        
        for (int j {}; j < cols; j ++)
        {
            std::cout << (grid[i][j] ? '+' : ' ');
        }

        std::cout << '\n';
    }
}

void DeleteArray(char**& array, int rows)
{
    if (array)
    {
        for (int i {}; i < rows; i ++)
        {
            delete[] array[i];
        }

        delete[] array;
        array = nullptr;
    }
}