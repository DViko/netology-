#include <iostream>
#include <string>

std::string numberToText(int n);

int main() {
    
    int a, b;

    std::cout << "Enter an integer between -100 and 100: "; std::cin >> a;
    std::cout << "Enter an integer between -100 and 100: "; std::cin >> b;

    std::string comp = (a < b) ? " less than " : (a > b) ? " greater than " : " equal to ";
    std::cout << numberToText(a) << comp << numberToText(b) << std::endl;

    return EXIT_SUCCESS;
}

std::string numberToText(int n) {

    if (n < -100 || n > 100)
        return "number out of range";
    if (n == -100)
        return "minus one hundred";
    if (n < 0)
        return "minus " + numberToText(-n);
    if (n == 0)
        return "zero";

    std::string units[] = {"", "one", "two", "three", "four", "five", 
                            "six", "seven", "eight", "nine"};

    std::string teens[] = {"ten", "eleven", "twelve", "thirteen", 
                            "fourteen", "fifteen", "sixteen", 
                            "seventeen", "eighteen", "nineteen"};

    std::string tens[] =  {"", "", "twenty", "thirty", "forty", "fifty", 
                            "sixty", "seventy", "eighty", "ninety"};

    if (n == 100)
        return "one hundred";
    if (n < 10)
        return units[n];
    if (n < 20)
        return teens[n - 10];
    if (n < 100)
        return tens[n / 10] + (n % 10 ? " " + units[n % 10] : "");

    return "";
}