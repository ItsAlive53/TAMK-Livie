#include <string>
#include <iostream>
#include <limits>

#include "mylib.h"

int getInt(std::istream& istream, std::string promptMessage) {
    std::string input;
    int ret;
    bool invalid = false;

    while (1) {
        if (!istream) {
            std::cerr << "Input reached EOF, terminating" << std::endl;
            throw "Input reached EOF";
        }

        std::cout << promptMessage;
        std::getline(istream, input);

        try {
            ret = std::stoi(input, nullptr, 10);
        } catch (std::invalid_argument) {
            std::cout << "Invalid input, try again" << std::endl;
            istream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            invalid = true;
        }

        if (invalid) invalid = false;
        else return ret;
    }
}
