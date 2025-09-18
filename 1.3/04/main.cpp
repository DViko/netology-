#include <iostream>
#include <string>
#include <array>
#include <format>


struct IntegersInWords {

    std::array<std::string, 10> units   {"", "one", "two", "three", "four", "five", 
                                            "six", "seven", "eight", "nine"
                                        };

    std::array<std::string, 10> teens   {"ten", "eleven", "twelve", "thirteen", 
                                            "fourteen", "fifteen", "sixteen", 
                                            "seventeen", "eighteen", "nineteen"
                                        };

    std::array<std::string, 10> tens    {"", "", "twenty", "thirty", "forty", "fifty", 
                                            "sixty", "seventy", "eighty", "ninety"
                                        };

    std::string minus{"minus"};
    std::string hundred{"hundred"};
    std::string zero{"zero"};
};

std::string getConstructedString(int first_integer, int second_integer, const IntegersInWords& words);


int main() {

    IntegersInWords words;
    int first_integer{0}, second_integer{0};

    std::cout << "Enter an integer between -100 and 100: ";

    if (!(std::cin >> first_integer)) {

        std::cout << "Error: Invalid input." << std::endl;

        return EXIT_FAILURE;
    }

    std::cout << "Enter an integer between -100 and 100: ";

    if (!(std::cin >> second_integer)) {

        std::cout << "Error: Invalid input." << std::endl;

        return EXIT_FAILURE;
    }

    if (first_integer < -100 || first_integer > 100 || second_integer < -100 || second_integer > 100) {

        std::cout << "Error: Numbers must be between -100 and 100." << std::endl;

        return EXIT_FAILURE;
    }

    std::cout << getConstructedString(first_integer, second_integer, words) << std::endl;

    return EXIT_SUCCESS;
}

std::string convertIntegerToText(int integer, const IntegersInWords& words) {

    if (integer < 0)
        return std::format("{} {}", words.minus, convertIntegerToText(-integer, words));

    if (integer == 0)
        return words.zero;

    if (integer == 100)
        return std::format("{} {}", words.units[1], words.hundred);

    if (integer < 20)
        return integer < 10 ? words.units[integer] : words.teens[integer - 10];

    int tens_part = integer / 10;
    int units_part = integer % 10;

    return units_part == 0 ? words.tens[tens_part] 
                           : std::format("{} {}", words.tens[tens_part], words.units[units_part]);
}

std::string getConstructedString(int first_integer, int second_integer, const IntegersInWords& words) {

    std::string comp{

        (first_integer < second_integer)    ? " less than "
        : (first_integer > second_integer)  ? " greater than "
                                            : " equal to "
    };

    return std::format("{}{}{}", convertIntegerToText(first_integer, words), comp, convertIntegerToText(second_integer, words));
}


