#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include "grid.hpp"
#include "logic.hpp"
#include "display.hpp"

int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    constexpr short ROWS { 20 }, COLS { 40 }, SLEEP_TIME { 150 };
    constexpr double DENSITY { 0.2 };

    char** grid { Grid::Create(ROWS, COLS) };
    char** buffer { Grid::Create(ROWS, COLS) };

    if (!grid || !buffer)
        return EXIT_FAILURE;

    Life::Prepare(grid, ROWS, COLS, DENSITY);

    while (true)
    {
        std::cout << "\x1B[2J\x1B[H";
        Display::Show(grid, ROWS, COLS);
        std::cout.flush();

        Life::Next(grid, buffer, ROWS, COLS);
        Grid::Copy(grid, buffer, ROWS, COLS);

        std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
    }

    Grid::Delete(grid, ROWS);
    Grid::Delete(buffer, ROWS);
    return EXIT_SUCCESS;
}