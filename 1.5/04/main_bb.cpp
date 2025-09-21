#include <iostream>
#include <cstddef>

template <typename T, typename Compare>
void reverseBubbleSort(T* array, std::size_t size, Compare cmp);

template <typename T>
void printArray(const T* array, std::size_t size);

int main() {

    int array[10]{45, 32, 11, 95, 81, 3, 54, 73, 5, 19};
    constexpr std::size_t SIZE = sizeof(array) / sizeof(array[0]);

    printArray(array, SIZE);

    reverseBubbleSort(array, SIZE, [](int a, int b){ return a < b; });

    printArray(array, SIZE);

    return EXIT_SUCCESS;
}

template <typename T, typename Compare>
void reverseBubbleSort(T* array, std::size_t size, Compare cmp) {

    for (std::size_t i = size - 1; i > 0; i --) {

        bool swapped{false};

        for (std::size_t j = i; j > 0; j --) {

            if (cmp(array[j], array[ j - 1 ])) {

                T buffer{array[j]};

                array[j] = array[ j - 1 ];
                array[ j - 1 ] = buffer;

                swapped = true;
            }
        }

        if (!swapped) break;
    }
}

template <typename T>
void printArray(const T* array, std::size_t size) {

    for (std::size_t i = 0; i < size; i ++) {

        std::cout << array[i];

        if (i < size - 1) std::cout << " ";
    }

    std::cout << "\n";
}