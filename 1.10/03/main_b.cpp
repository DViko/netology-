#include <iostream>
#include <iomanip>
#include <limits>

int* CreateTwoDimArray(int cols, int rows);
void FillTwoDimArray(int* array, int cols, int rows);
void PrintTwoDimArray(const int* array, int cols, int rows);
void DeleteTwoDimArray(int*& array);


int main()
{
    int cols {0}, rows {0};
    int* array {nullptr};

    std::cout << "Inter number of columns: ";
    std::cin >> cols;
    std::cout << "Inter number of rows: ";
    std::cin >> rows;

    array = CreateTwoDimArray(cols, rows);

    if (array == nullptr)
    {
        return EXIT_FAILURE;
    }

    FillTwoDimArray(array, cols, rows);
    PrintTwoDimArray(array, cols, rows);

    DeleteTwoDimArray(array);

    return EXIT_SUCCESS;
}

int* CreateTwoDimArray(int cols, int rows)
{
    try
    {
        return new int[cols * rows];
    }
    catch (const std::bad_alloc& error)
    {
        std::cout << "Error: Memory allocation failed: " << error.what() << "\n";

        return nullptr;
    }
}

void FillTwoDimArray(int* array, int cols, int rows)
{   
    for (int col {0}; col < cols; col ++)
    {
        for (int row {0}; row < rows; row ++)
        {
            array[col * rows + row] = (col + 1) * (row + 1);
        }
    }
}

void PrintTwoDimArray(const int* array, int cols, int rows)
{
    int cell_width = std::to_string(cols * rows).length() + 2;
    
    for (int col {0}; col < cols; col ++)
    {
        for (int row {0}; row < rows; row ++)
        {
            std::cout << std::setw(cell_width) << array[col * rows + row];
        }

        std::cout << "\n";
    }

    std::cout << "\n";
}

void DeleteTwoDimArray(int*& array)
{
    delete[] array;
    array = nullptr;
}