#include <iostream>

int main() {

    int input_number{0}, result{0};

    while (true) {
        std::cout << "Inter an integer or 0 for exit and get result: ";
        std::cin >> input_number;

        if (input_number == 0) break;

        result += input_number;
    }

    std::cout << "The result is: " << result << std::endl;

    return EXIT_SUCCESS;
}