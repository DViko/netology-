#include <iostream>

int main() {

    int array[10]{68, 12, 8, 43, 75, 90, 11, 23, 56, 34};
    int array_size = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < array_size; ++i) {

        std::cout << array[i];

        if (i != array_size - 1)

            std::cout << ", ";
    }

    std::cout << std::endl;

    return EXIT_SUCCESS;
}