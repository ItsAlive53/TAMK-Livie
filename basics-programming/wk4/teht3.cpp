#include <iostream>
#include <string>

int main() {
    std::string input;
    float deg;
    char from;

    std::cout << "Input temperature (ex. 3.01 F, 2.03 C):" << std::endl;
    std::getline(std::cin, input);

    // format "0.00 (F/C)", decimal optional, case insensitive
    // no quotes, space optional

    if (input.size() <= 1 || !std::isdigit(input[0])) {
        // check string size, and whether or not it starts with a number
        // not = invalid input
        deg = 0;
        from = '0';
    } else {
        size_t strPos;
        deg = std::stof(input, &strPos);

        char strChar = input[strPos];
        if (strChar == ' ') {
            // get char after space and make sure it isnt null
            strChar = input[strPos + (size_t) 1];
            if (strChar != '\0') {
                from = strChar;
            }
        } else if (strChar != '\0') {
            // if last character isnt a space, or null, use it
            from = strChar;
        } else {
            from = '0'; // Default to avoid null references
        }
    }

    if (from == 'C' || from == 'c') {
        std::cout << deg << " Celsius = " << deg*1.8f+32.0f << " Fahrenheit";
    } else if (from == 'F' || from == 'f') {
        std::cout << deg << " Fahrenheit = " << (deg-32.0f)/1.8f << " Celsius";
    } else {
        std::cout << "Invalid input.";
    }

    std::cout << std::endl;
    return 0;
}

