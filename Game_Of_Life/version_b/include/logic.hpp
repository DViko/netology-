#pragma once

namespace Life
{
    void Prepare(char** grid, int rows, int cols, double density);
    void Next(char** grid, char** buffer, int rows, int cols);
    int  Neighbors(char** grid, int rows, int cols, int r, int c);
}