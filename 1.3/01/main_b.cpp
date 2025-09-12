#include <iostream>

void get_bool_values(short i, bool &a, bool &b);
void print_bool_values(bool a, bool b, bool result);

int main() {

    std::cout << "operator: ||" << std::endl;

    bool a, b;

    for (short i = 0; i < 4; i++) {

        get_bool_values(i, a, b);

        print_bool_values(a, b, (a || b));
    }

    std::cout << std::endl;
    std::cout << "operator: &&" << std::endl;

    for (short i = 0; i < 4; i++) {

        get_bool_values(i, a, b);

        print_bool_values(a, b, (a && b));
    }
    
    return EXIT_SUCCESS;
}

void get_bool_values(short i, bool &a, bool &b) {
    
    switch (i) {
        case 0: a = true;  b = true;
            break;
        case 1: a = false; b = true;
            break;
        case 2: a = true; b = false;
            break;
        case 3: a = false; b = false;
            break;
    }
}

void print_bool_values(bool a, bool b, bool result) {
    std::cout << std::boolalpha << a << "\t" << b << "\t" << result << std::endl;
}