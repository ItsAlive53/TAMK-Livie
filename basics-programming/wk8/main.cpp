#include <string>
#include <iostream>
#include <vector>

#include "mylib.h"
#include "eleclib.h"

void third() {
    float voltage = getFloat(std::cin, "Input circuit/resistor voltage: ");
    float resistance = getFloat(std::cin, "Input circuit/resistor resistance: ");

    std::cout << "The current drawn is " << getResistorCurrent(voltage, resistance) << " A." << std::endl;
}

void fourth() {
    float power = getFloat(std::cin, "Input the devices power rating: ");

    printRequiredFuse(power);
}

void fifth() {
    int rowLength = 7;
    std::vector<int> nums = getUniqueRandomNumbers(rowLength, 1, 40); // (amount, min, max) min-max both inclusive

    nums = sortVectorInt(nums);

    for (int i = 0; i < rowLength; i++) {
        std::cout << nums[i];
        if (i < rowLength - 1) {
             std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

int main() {
    char res = '\0';
    while (res != 'q') {
        res = getChar(std::cin, "Run through which exercise? (3-5, q to quit): ");

        std::cout << std::endl;
        switch (res) {
            case 'q':
                std::cout << "Quitting..." << std::endl;
                break;
            case '3':
                third();
                break;
            case '4':
                fourth();
                break;
            case '5':
                fifth();
                break;
            default:
                std::cout << "Invalid input, try again" << std::endl;
                break;
        }

        std::cout << "------------------------------\n" << std::endl;
    }

    return 0;
}
