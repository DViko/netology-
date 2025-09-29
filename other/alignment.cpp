#include <iostream>

struct Bad {
    char c;   // 1
    int i;    // 4
    double d; // 8
};

struct Good {
    double d; // 8
    int i;    // 4
    char c;   // 1
};

int main() {
    
    std::cout << "Size of Bad: " << sizeof(Bad) << "\n";   // Likely 24 due to padding
    std::cout << "Size of Good: " << sizeof(Good) << "\n"; // Likely 16, more compact
}