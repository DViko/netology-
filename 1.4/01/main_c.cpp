#include <iostream>

int main() {

    int input_number{0}, result{0};
    bool is_true{false};

    for( ; !is_true ; ) {
        
        std::cout << "Inter an integer or 0 for exit and get result: ";
        std::cin >> input_number;

        if (input_number == 0) is_true = true;
        else result += input_number;
    }
    
    std::cout << "The result is: " << result << std::endl;

    return EXIT_SUCCESS;
}