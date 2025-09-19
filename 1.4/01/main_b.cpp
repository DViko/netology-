#include <iostream>

int main() {

    int input_value{0}, result{0};

    while (true) {
        std::cout << "Inter an integer or 0 for exit and get result: ";
        std::cin >> input_value;

        if (input_value == 0) break;

        result += input_value;
    }

    std::cout << "The result is: " << result << std::endl;

    return EXIT_SUCCESS;
}