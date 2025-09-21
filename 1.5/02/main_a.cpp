#include <iostream>

int main() {

    int array[10]{65, 17, 42, 99, 23, 8, 76, 54, 31, 88};
    int array_size = sizeof(array) / sizeof(array[0]);
    int min{array[0]}, max{array[0]};

    std::cout << "Array: ";

    for (int i = 1; i < array_size; ++i) {

        std::cout << array[i];

        if (i != array_size - 1) std::cout << ", ";

        if (array[i] < min) min = array[i];
        
        if (array[i] > max) max = array[i];
    }

    std::cout << std::endl;
    std::cout << "Min: " << min << ", Max: " << max << std::endl;
    
    return EXIT_SUCCESS;
}