#include <iostream>
#include <iomanip>
#include <limits>

bool ReadValue(const std::string& string, int& value, int max_size);
bool GetArrayDimensions(int& rows, int& cols, int max_size);
bool ShowAttentionMessage(int rows, int cols, int warning_threshold);
int* CreateTwoDimArray(int rows, int cols);
void FillTwoDimArray(int* array, int rows, int cols);
void PrintTwoDimArray(const int* array, int rows, int cols);
void DeleteTwoDimArray(int*& array);


int main()
{
    const int   MAX_ARRAY_SIZE {46300},
                WARNING_THRESHOLD {100000000};

    int rows {0}, cols {0};

    if (!GetArrayDimensions(rows, cols, MAX_ARRAY_SIZE))
    {
        return EXIT_FAILURE;
    }

    if (!ShowAttentionMessage(rows, cols, WARNING_THRESHOLD))
    {
        return EXIT_FAILURE;
    }

    int* array {CreateTwoDimArray(rows, cols)};

    if (array == nullptr)
    {
        return EXIT_FAILURE;
    }

    FillTwoDimArray(array, rows, cols);
    std::cout << "\n";
    PrintTwoDimArray(array, rows, cols);

    DeleteTwoDimArray(array);

    return EXIT_SUCCESS;
}

bool ReadValue(const std::string& string, int& value, int max_size)
{
    std::cout << string;

    if (std::cin >> value && value > 0 && value <= max_size)
    {
        return true;
    }

    std::cout << "Error: Must be a positive integer greater than zero and less than or equal to " << max_size << ".\n";

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return false;
}

bool GetArrayDimensions(int& rows, int& cols, int max_size)
{
    return ReadValue("Enter number of columns: ", cols, max_size) &&
           ReadValue("Enter number of rows: ", rows, max_size);
}

bool ShowAttentionMessage(int rows, int cols, int warning_threshold)
{
    if (rows * cols > warning_threshold)
    {
        double total_bytes = static_cast<double>(rows * cols) * sizeof(int);
        char answer {'n'};

        std::cout   << "\nAttention: This may require ~ " << total_bytes / (1024 * 1024) << " MB of memory.\n\n"
                    << "Do you want to continue? (y/n): ";

        std::cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {
            return true;
        }

        std::cout << "Operation cancelled by user.\n";

        return false;
    }
    else 
    {
        return true;
    } 
}

int* CreateTwoDimArray(int rows, int cols)
{
    int* array {nullptr};

    try
    {
        array = new int[rows * cols];
    }
    catch (const std::bad_alloc& error)
    {
        std::cout << "Error: Memory allocation failed: " << error.what() << "\n";

        return nullptr;
    }

    return array;
}

void FillTwoDimArray(int* array, int rows, int cols)
{   
    for (int row {0}; row < rows; row ++)
    {
        for (int col {0}; col < cols; col ++)
        {
            array[row * cols + col] = (row + 1) * (col + 1);
        }
    }
}

void PrintTwoDimArray(const int* array, int rows, int cols)
{
    int cell_width = std::to_string(rows * cols).length() + 2;
    
    for (int row {0}; row < rows; row ++)
    {
        for (int col {0}; col < cols; col ++)
        {
            std::cout << std::setw(cell_width) << array[row * cols + col];
        }

        std::cout << "\n";
    }

    std::cout << "\n";
}

void DeleteTwoDimArray(int*& array)
{
    if (array != nullptr)
    {
        delete[] array;
        array = nullptr;
    }
}