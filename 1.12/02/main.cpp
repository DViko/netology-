#include <iostream>
#include <fstream>

int main()
{
    std::ifstream file("file.txt");
    size_t length {0};

    if (!file.is_open())
    {

        std::cerr << "Error: cannot open input file.\n";
        return EXIT_FAILURE;
    }

    file >> length;

    if (length == 0) 
    {
        std::cerr << "Error: invalid array size.\n";

        return EXIT_FAILURE;
    }

    int* numbers { new(std::nothrow) int[length] };

    if (!numbers)
    {
        std::cerr << "Error: memory allocation failed.\n";
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < length; i++)
    {
        if (!(file >> numbers[i]))
        {
            delete[] numbers;

            std::cerr << "Error: failed to read array element.\n";
            return EXIT_FAILURE;
        }
    }

    for (size_t i = length; i-- > 0; )
    {
        std::cout << numbers[i] << (i ? ' ' : '\n');
    }

    delete[] numbers;

    return EXIT_SUCCESS;
}