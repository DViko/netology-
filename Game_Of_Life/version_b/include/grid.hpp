#pragma once
#include <iostream>

namespace Grid
{
    char** Create(int rows, int cols);
    void Delete(char**& grid, int rows);
    void Copy(char** buffer, char** target, int rows, int cols);
}