#include <iostream>
#include <string>
#include "mylib.h"

void examples() {
    tulostus();

    std::string input;
    double radius;

    std::cout << "Input circle radius: ";
    std::getline(std::cin, input);
    radius = std::stod(input);

    std::cout << "The area of the circle is " << circleArea(radius) << std::endl;
}

void first() {
    std::string input;
    int x;

    bool invalid = false;
    while (1) {
        std::cout << "Input whole number: ";
        std::getline(std::cin, input);

        try {
            x = std::stoi(input, nullptr, 10);
        } catch (std::invalid_argument) {
            std::cout << "Invalid input, try again" << std::endl;
            invalid = true;
        }

        if (invalid) invalid = false;
        else break;
    }

    std::cout << x << "^2 = " << square(x) << std::endl;
}

void second() {
    std::string input;
    int w, h;

    bool invalid = false;
    while (1) {
        std::cout << "Input rectangle width: ";
        std::getline(std::cin, input);

        try {
            w = std::stoi(input, nullptr, 10);
        } catch (std::invalid_argument) {
            std::cout << "Invalid input, try again" << std::endl;
            invalid = true;
        }

        if (invalid) invalid = false;
        else break;
    }

    while (1) {
        std::cout << "Input rectangle height: ";
        std::getline(std::cin, input);

        try {
            h = std::stoi(input, nullptr, 10);
        } catch (std::invalid_argument) {
            std::cout << "Invalid input, try again" << std::endl;
            invalid = true;
        }

        if (invalid) invalid = false;
        else break;
    }

    std::cout << "The rectangles area is " << rectArea(w, h) << std::endl;
}

void third() {
    std::string input;
    double km, usage, price;

    bool invalid = false;
    while (1) {
        std::cout << "Input distance in km: ";
        std::getline(std::cin, input);

        try {
            km = std::stod(input);
        } catch (std::invalid_argument) {
            std::cout << "Invalid input, try again" << std::endl;
            invalid = true;
        }

        if (invalid) invalid = false;
        else break;
    }

    while (1) {
        std::cout << "Input gas use l/100km: ";
        std::getline(std::cin, input);

        try {
            usage = std::stod(input);
        } catch (std::invalid_argument) {
            std::cout << "Invalid input, try again" << std::endl;
            invalid = true;
        }

        if (invalid) invalid = false;
        else break;
    }

    while (1) {
        std::cout << "Input current gas price €/l: ";
        std::getline(std::cin, input);

        try {
            price = std::stod(input);
        } catch (std::invalid_argument) {
            std::cout << "Invalid input, try again" << std::endl;
            invalid = true;
        }

        if (invalid) invalid = false;
        else break;
    }

    std::cout << "That trip would cost you " << tripPrice(km, usage, price) << " €" << std::endl;
}

void fourth() {
    std::string input;
    int hours;

    bool invalid = false;
    while (1) {
        std::cout << "Input hours worked: ";
        std::getline(std::cin, input);

        try {
            hours = std::stoi(input, nullptr, 10);
        } catch (std::invalid_argument) {
            std::cout << "Invalid input, try again" << std::endl;
            invalid = true;
        }

        if (invalid) invalid = false;
        else break;
    }

    std::cout << "Your wage before taxes would be " << wage(hours) << " €" << std::endl;
}

int main() {
    std::string input;
    char res = '\0';
    while (res != 'q') {
        std::cout << "Run through which exercise? (1-4, e for examples, q to quit)" << std::endl;

        std::getline(std::cin, input);
        res = input[0];

        std::cout << std::endl;
        switch (res) {
            case 'q':
                std::cout << "Quitting..." << std::endl;
                break;
            case '1':
                first();
                break;
            case '2':
                second();
                break;
            case '3':
                third();
                break;
            case '4':
                fourth();
                break;
            case 'e':
                examples();
                break;
            default:
                std::cout << "Invalid input, try again" << std::endl;
                break;
        }

        std::cout << "------------------------------\n" << std::endl;
    }

    return 0;
}

