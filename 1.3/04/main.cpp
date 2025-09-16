#include <iostream>
#include <string>
#include <array>


struct NumberWords{
    std::array<std::string, 10> units{"", "one", "two", "three", "four", "five", 
                                            "six", "seven", "eight", "nine"};

    std::array<std::string, 10> teens{"ten", "eleven", "twelve", "thirteen", 
                                            "fourteen", "fifteen", "sixteen", 
                                            "seventeen", "eighteen", "nineteen"};

    std::array<std::string, 10> tens{"", "", "twenty", "thirty", "forty", "fifty", 
                                            "sixty", "seventy", "eighty", "ninety"};
};

std::string numberToText(int number, const NumberWords& words);
void        compareNumbers(int first_number, int second_number, const NumberWords& words);

int main() {

    NumberWords words;
    int first_number{0}, second_number{0};

    std::cout << "Enter an integer between -100 and 100: ";
    std::cin >> first_number;

    std::cout << "Enter an integer between -100 and 100: ";
    std::cin >> second_number;

    compareNumbers(first_number, second_number, words);

    return EXIT_SUCCESS;
}

void compareNumbers(int first_number, int second_number, const NumberWords& words) {

    std::string comp 
    {
        (first_number < second_number) ? " less than "
        : (first_number > second_number) ? " greater than "
        : " equal to "
    };

    std::cout << numberToText(first_number, words) << comp << numberToText(second_number, words) << std::endl;
}

std::string numberToText(int number, const NumberWords& words) {

    // ToDo: Clean up this function

    if (number < 100)
        return std::string(words.tens[number / 10]) + (number % 10 ? " " + std::string(words.units[number % 10]) : "");

    else if (number < 20)
        return std::string(words.teens[number - 10]);

    else if (number < 10)
        return std::string(words.units[number]);

    else if (number < 0)
        return "minus " + numberToText(-number, words);

    else if (number == 0)
        return "zero";

    else if (number == -100)
        return "minus one hundred";

    else if (number == 100)
        return "one hundred";

    else if (number < -100 || number > 100)
        return "number out of range";
    else 
        return "";
}