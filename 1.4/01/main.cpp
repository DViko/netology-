#include <iostream>


int main() {
    
    int input_number{0}, result{0};
    bool is_true{false};

    do {
        std::cout << "Inter a positive integer or 0 for exit and get result: ";
        std::cin >> input_number;

        if (input_number != 0)
            result += input_number; 
        else
            is_true = true;

    } while (!is_true);

    std::cout << "The result is: " << result << std::endl;

    return EXIT_SUCCESS;
}