#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
    std::string gender, zodiac, prediction;
    int age;
    
    std::cout << "Your gender (m/f): ";
    std::cin >> gender;
    
    std::cout << "Your zodiac sign: ";
    std::cin >> zodiac;
    
    std::cout << "Your age: ";
    std::cin >> age;

    
    if (age < 0 || age > 120) {
        std::cout << "Incorrect age" << std::endl;
        return EXIT_FAILURE;
    }

    std::transform(gender.begin(), gender.end(), gender.begin(), [](unsigned char c){ return std::tolower(c); });
    std::transform(zodiac.begin(), zodiac.end(), zodiac.begin(), [](unsigned char c){ return std::tolower(c); });

    std::cout << gender << " " << zodiac << " " << age << std::endl;
    
    if (gender == "m") {
        if ((zodiac == "cancer" || zodiac == "scorpio" || zodiac == "pisces") && age < 40) {
            prediction = "Today is a very productive day. You will be able to achieve what previously seemed almost impossible.";
        } else {
            prediction = "Horoscope for you is under development. Come a little later ;)";
        }
    }
    else if (gender == "f") {
        if ((zodiac == "taurus" || zodiac == "virgo" || zodiac == "capricorn") && age >= 15 && age <= 30) {
            prediction = "This evening is suitable for socializing with friends, hosting home parties, and impromptu gatherings.";
        } else {
            prediction = "Horoscope for you is under development. Come a little later ;)";
        }
    }
    else {
        prediction = "Horoscope for you is under development. Come a little later ;)";
    }
    
    std::cout << "Your prediction:" << std::endl;
    std::cout << prediction << std::endl;
    
    return EXIT_SUCCESS;
}