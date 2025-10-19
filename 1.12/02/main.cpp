#include <iostream>
#include <fstream>

void CleanMemory(int*& buffer);
void ExitWithError(const char* prompt);

int main()
{
    size_t capacity {0};
    std::ifstream source ("file.txt");

    if (!source.is_open())
    {
        ExitWithError("Error: cannot open input file.");
    }

    source >> capacity;

    if (capacity == 0)
    {
        ExitWithError("Error: invalid array size.");
    }

    int* buffer { new(std::nothrow) int[capacity] };

    if (!buffer)
    {
        ExitWithError("Error: memory allocation failed.");
    }

    for (size_t i {}; i < capacity; i++)
    {
        if (!(source >> buffer[i]))
        {
            CleanMemory(buffer);
            ExitWithError("Error: failed to read element.");
        }
    }

    source.close();

    for (size_t i { capacity }; i-- > 0;)
    {
        std::cout << buffer[i] << (i > 0 ? ", " : "\n");
    }

    CleanMemory(buffer);
    return EXIT_SUCCESS;
}

void CleanMemory(int*& pointer)
{
    delete[] pointer;
    pointer = nullptr;
}

void ExitWithError(const char* prompt)
{
    std::cerr << prompt << '\n';
    std::exit(EXIT_FAILURE);
}