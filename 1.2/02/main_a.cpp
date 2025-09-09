#include <iostream>
#include <string>

int main() {
    std::string input_str;

    std::cout << "What is your name ? : ";
    std::cin >> input_str;

    std::cout << "Hello : " << input_str << " !" << std::endl;

    return EXIT_SUCCESS;
}