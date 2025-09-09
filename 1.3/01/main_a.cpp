#include <iostream>

int main() {
    bool values[] = {true, false};
    
    std::cout << "operator: ||" << std::endl;

    for (bool a: values) {
        for (bool b : values) {
            std::cout << std::boolalpha << b << "\t" << a << "\t" << (b || a) << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "operator: &&" << std::endl;

    for (bool a : values) {
        for (bool b : values) {
            std::cout << std::boolalpha << b << "\t" << a << "\t" << (b && a) << std::endl;
        }
    }

    return EXIT_SUCCESS;
}