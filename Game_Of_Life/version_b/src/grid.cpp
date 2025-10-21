#pragma once
#include "grid.hpp"

namespace Grid
{
    char** Create(int rows, int cols)
    {
        char** array { nullptr };

        try
        {
            array = new char*[rows] {};

            for (int i {}; i < rows; i++)
            {
                array[i] = new char[cols] {};
            }
        }
        catch (const std::bad_alloc& error)
        {
            Delete(array, rows);

            std::cerr << "Memory allocation failed: " << error.what() << '\n';
            return nullptr;
        }

        return array;
    }

    void Delete(char**& array, int rows)
    {
        for (int i {}; i < rows; i++)
        {
            delete[] array[i];
        }

        delete[] array;
        array = nullptr;
    }

    void Copy(char** dest, char** src, int rows, int cols)
    {
        for (int k {}; )
        /*for (int i {}; i < rows; i++)
        {
            for (int j {}; j < cols; j++)
            {
                dest[i][j] = src[i][j];
            }
        }*/
    }
}