#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
    
    std::string gender{"def"}, zodiac{"def"}, prediction{"def"};
    int age{0}, male_max_age{40}, female_min_age{15}, female_max_age{30};
    int age_limit[2] = {0, 120};

    std::string zodiac_signs[12] = {
        "aries", "taurus", "gemini", "cancer", "leo", "virgo",
        "libra", "scorpio", "sagittarius", "capricorn", "aquarius", "pisces"
    };

    std::string predictions[2] = {
        "Today is a very productive day. You will be able to achieve what previously seemed almost impossible.",
        "This evening is suitable for socializing with friends, hosting home parties, and impromptu gatherings.",  
    };

    std::string notifications[2] = {
        "Horoscope for you is under development. Come a little later ;)",
        "Incorrect age",
    };
    
    std::cout << "Your gender (m/f): ";
    std::cin >> gender;
    
    std::cout << "Your zodiac sign: ";
    std::cin >> zodiac;
    
    std::cout << "Your age: ";
    std::cin >> age;

    if (age < age_limit[0] || age > age_limit[1]) {
        
        std::cout << notifications[1] << std::endl;

        return EXIT_FAILURE;
    }

    std::transform(gender.begin(), gender.end(), gender.begin(), [](unsigned char c){ return std::tolower(c); });
    std::transform(zodiac.begin(), zodiac.end(), zodiac.begin(), [](unsigned char c){ return std::tolower(c); });

    //Of course I can use some cycles but theme of the lesson is a conditional operators

    if (gender == "m")
        if (zodiac == zodiac_signs[3] || zodiac == zodiac_signs[6] || zodiac == zodiac_signs[11])
            if (age < male_max_age)
                prediction = predictions[1];
            else 
                prediction = notifications[0];
        else
            prediction = notifications[0];

    else if (gender == "f")
        if (zodiac == zodiac_signs[1] || zodiac == zodiac_signs[5] || zodiac == zodiac_signs[10])
            if (age >= female_min_age && age <= female_max_age)
                prediction = predictions[0];
            else
                prediction = notifications[0];
        else
            prediction = notifications[0];
    else
        prediction = notifications[0];

    std::cout << prediction << std::endl;

    return EXIT_SUCCESS;
}