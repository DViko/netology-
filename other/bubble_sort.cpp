#include <iostream>
#include <functional>

void arraySort(int array[], int size, std::function<bool(int, int)> comparator);
void printResult(int array[], int size);

int main() {

    int int_array[]{64, 34, 25, 12, 22, 11, 90};

    int array_size{sizeof(int_array)/sizeof(int_array[0])};

    arraySort(int_array, array_size, [](int a, int b) { return a > b; });

    printResult(int_array, array_size);

    return EXIT_SUCCESS;
}

void arraySort(int array[], int array_size, std::function<bool(int, int)> comparator) {

    bool is_swapped{false};
    int pass{0};

    do {

        is_swapped = false;

        for (int j = 0; j < array_size - pass -1; j ++) {

            if (comparator(array[j], array[ j + 1 ])) {

                is_swapped = true;

                std::swap(array[j], array[ j + 1 ]);
            }
        }

        pass ++;

    } while (is_swapped);
}

void printResult(int array[], int size) {

    std::cout << "Result: ";

    for (int i = 0; i < size; ++i) std::cout << array[i] << " ";

    std::cout << std::endl;
}