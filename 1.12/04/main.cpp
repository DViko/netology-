#include <iostream>
#include <fstream>
#include <string>

int main()
{
    int cols {0}, rows {0};
    int** buffer { nullptr };

    std::ifstream source ("in.txt");

    if (!source.is_open())
    {
        std::cerr << "Error: Could not open the file.\n";
        return EXIT_FAILURE;
    }

    source >> cols >> rows;
    buffer = new int*[rows]();

    for (int i {}; i < rows; i++)
    {
        buffer[i] = new int[cols]();
    }

    for (int k = 0; k < cols * rows; k++)
    {
        int i { k / rows };
        int j { k % rows };

        source >> buffer[i][j];
    }

    source.close();

    for (int k = 0; k < cols * rows; k++)
    {
        int i { k / rows };
        int j { rows - 1 - (k % rows) };

        std::cout << buffer[i][j] << (j == 0 ? "\n" : ", ");
    }

    delete[] buffer;
    buffer = nullptr;

    return EXIT_SUCCESS;
}