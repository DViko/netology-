#include <iostream>
#include <functional>

void bubbleSort(int array[], int size, std::function<bool(int, int)> comparator);
void printArray(int array[], int size);

int main() {

    int array[10]{64, 34, 25, 12, 22, 11, 90, 3, 1, 42};
    constexpr std::size_t SIZE{sizeof(array) / sizeof(array[0])};

    printArray(array, SIZE);

    bubbleSort(array, SIZE, [](int a, int b) { return a < b; });

    printArray(array, SIZE);

    return EXIT_SUCCESS;
}

void bubbleSort(int array[], int size, std::function<bool(int, int)> cmp) {

    for (std::size_t i = size - 1; i > 0; i --) {

        bool swapped{false};

        for (std::size_t j = i; j > 0; j --) {

            if (cmp(array[j], array[ j - 1 ])) {

                int buffer{array[j]};

                std::swap(array[j], array[ j - 1 ]);

                swapped = true;
            }
        }

        if (!swapped) break;
    }
}

void printArray(int array[], int size) {

    for (std::size_t i = 0; i < size; i ++) {

        std::cout << array[i];

        if (i < size - 1) std::cout << " ";
    }

    std::cout << "\n";
}