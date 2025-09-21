#include <iostream>
#include <string>

void printArray(const int array[], int size);


int main() {

    int array[10]{68, 12, 8, 43, 75, 90, 11, 23, 56, 34};
    int array_size = sizeof(array) / sizeof(array[0]);

    printArray(array, array_size);

    return EXIT_SUCCESS;
}

void printArray(const int array[], int size) {

    std::string string{""};

    for (int i = 0; i < size; ++i) {

        std::cout << string << array[i];

        string = ", ";
    }
    
    std::cout << std::endl;
}