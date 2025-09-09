#include <iostream>

int main() {
    int num;
    bool valid = false;

    while (!valid) {
        std::cout << "Enter an integer: ";

        if (std::cin >> num) {
            std::cout << "You entered: " << num << std::endl;
            
            valid = true;
        } else {
            std::cout << "Invalid input. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    }
    
    return EXIT_SUCCESS;
}