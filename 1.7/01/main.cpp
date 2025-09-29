#include <iostream>
#include <cstdint>
#include <string>
#include <array>
#include <iomanip>

struct Human {
    std::string name;
    int age;
    float height;
};

void printHeader();

template<typename T>
void printVarType(std::string name, T& type);

int main() {
    short s {0}; int i {0};
    long l {0}; long long ll {0};
    float f {0.0f}; double d {0.0}; long double ld {0.0};
    bool b {false};
    Human h {}; std::array<int, 5> std_arr {}; short c_arr[5] {};

    printHeader();
    printVarType("short", s);
    printVarType("int", i);
    printVarType("long", l);
    printVarType("long long", ll);
    printVarType("float", f);
    printVarType("double", d);
    printVarType("long double", ld);
    printVarType("bool", b);
    printVarType("struct", h);
    printVarType("array", std_arr);
    printVarType("c_array", c_arr);
}

void printHeader() {
    std::cout << std::left << std::setw(12) << "Name"
              << std::right << std::setw(10) << "Address"
              << std::right << std::setw(10) << "Size"
              << "\n\n";
}

template<typename T>
void printVarType(std::string name, T& type) {

    std::cout << std::left << std::setw(12) << name
              << "0x" << std::right << std::setw(8) << std::setfill('0') 
              << std::hex << reinterpret_cast<uintptr_t>(&type)
              << std::dec << std::setw(5) << std::setfill(' ')
              << sizeof(type) << "\n";
}