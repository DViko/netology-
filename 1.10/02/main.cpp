#include <iostream>

bool CheckInsert(int& value);
bool CreateAndFillArray(double* &array, int size);
void PrintArray(double* array, int size);

int main()
{
    double* array {nullptr};
    int size {0};

    std::cout << "Enter the size of the array: ";

    if (CheckInsert(size) && CreateAndFillArray(array, size))
    {
        PrintArray(array, size);

        delete[] array;
        array = nullptr;

        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}

bool CheckInsert(int& value)
{
    if (!(std::cin >> value) || value <= 0)
    {
        std::cout << "Error: Array size must be a positive integer and greater than zero.\n";

        return false;
    }

    return true;
}

bool CreateAndFillArray(double* &array, int size)
{
    try
    {
        array = new double[size]();
    }
    catch (const std::bad_alloc& error)
    {
        std::cout << "Error: Memory allocation failed: " << error.what() << "\n";

        return false;
    }

    return true;
}

void PrintArray(double* array, int size)
{
    std::cout << "Array elements: ";

    for (int i {0}; i < size; i ++)
    {
        std::cout << array[i] << (i < size - 1 ? ", " : "\n");
    }
}