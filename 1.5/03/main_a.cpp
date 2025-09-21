#include <iostream>

int main() {

    int array[3][6]{
                    {9, 2, 3, 4, 12, 90},
                    {7, 50, 13, 10, 1, 12},
                    {13, -14, 40, 16, 17, 18}
    };

    int rows{sizeof(array) / sizeof(array[0])};
    int columns{sizeof(array[0]) / sizeof(array[0][0])};

    int min_value{array[0][0]}, max_value{array[0][0]};
    int min_row_col[2]{0, 0}, max_row_col[2]{0, 0};

    for (int row = 0; row < rows; row++) {

        for (int column = 0; column < columns; column++) {

            std::cout << array[row][column] << "\t";

            if (array[row][column] < min_value) {

                min_value = array[row][column];

                min_row_col[0] = row;
                min_row_col[1] = column;
            }

            if (array[row][column] > max_value) {

                max_value = array[row][column];

                max_row_col[0] = row;
                max_row_col[1] = column;
            }
        }
        std::cout << std::endl;
    }

    std::cout << "Min: " << "row: " << min_row_col[0] << " col: " << min_row_col[1] << " value: " << min_value << std::endl;
    std::cout << "Max: " << "row: " << max_row_col[0] << " col: " << max_row_col[1] << " value: " << max_value << std::endl;


    return EXIT_SUCCESS;
}