#include <iostream>

void classicSwap(int& x, int& y);


int main(int argc, char* argv[]) {

    int a{10}, b{4};

    std::cout << "a = " << a << ", b = " << b << "\n";

    classicSwap(a, b);

    std::cout << "a = " << a << ", b = " << b << "\n";

    return EXIT_SUCCESS;
}

void classicSwap(int& x, int& y) {

    int temp = x;
    x = y;
    y = temp;
}
