#include <iostream>
#include <string>

#include "person.h"

int main() {
    std::string input;
    Person x, y;

    std::cout << "Enter name of person 1: ";
    std::getline(std::cin, input);
    x.setName(input);
    input.clear();

    std::cout << "Enter age of person 1: ";
    std::getline(std::cin, input);
    x.setAge(std::stoi(input));
    input.clear();

    std::cout << "Enter name of person 2: ";
    std::getline(std::cin, input);
    y.setName(input);
    input.clear();

    std::cout << "Enter age of person 2: ";
    std::getline(std::cin, input);
    y.setAge(std::stoi(input));

    std::cout << "\nPerson 1:\n";
    x.printInfo();

    std::cout << "\nPerson 2:\n";
    y.printInfo();

    return 0;
}
