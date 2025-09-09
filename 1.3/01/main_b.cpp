#include <iostream>

int main() {
    std::cout << "operator: ||" << std::endl;

    bool a, b, result;

    for (int i = 0; i < 4; i++) {
         
        switch (i) {
            case 0: a = true;  b = true;  break;
            case 1: a = false; b = true;  break;
            case 2: a = true; b = false; break;
            case 3: a = false; b = false; break;
        }
        
        if (a || b)
            result = true;
        else
            result = false;
        
        std::cout << std::boolalpha << a << "\t" << b << "\t" << result << std::endl;
    }


    std::cout << std::endl;
    std::cout << "operator: &&" << std::endl;

    for (int i = 0; i < 4; i++) {
         
        switch (i) {
            case 0: a = true;  b = true;  break;
            case 1: a = false; b = true;  break;
            case 2: a = true; b = false; break;
            case 3: a = false; b = false; break;
        }

        if (a && b)
            result = true;
        else
            result = false;
        
        std::cout << std::boolalpha << a << "\t" << b << "\t" << result << std::endl;
    }
    
    return EXIT_SUCCESS;
}