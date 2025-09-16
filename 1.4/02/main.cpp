#include <iostream>


int main() {
    
    int input_integer{0}, mem_number{0}, result{0};

    std::cout << "Enter an integer: ";
    std::cin >> input_integer;

    mem_number = input_integer;

    if (input_integer < 0) input_integer = -input_integer;

    while (input_integer > 0) {
        result += input_integer % 10;
        input_integer /= 10;
    }

    std::cout << "Sum of number is: " << result << " because digits of number: " << mem_number << std::endl;

    return EXIT_SUCCESS;
}