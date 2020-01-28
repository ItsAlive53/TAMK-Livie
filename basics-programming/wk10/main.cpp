#include <iostream>

// dependencies for mylib.h
#include <string>
#include <vector>
// END dependencies

#include "mylib.h"

void arvoLottonumerot(int* arr, size_t arrSize) {
    std::vector<int> rands = getUniqueRandomNumbers(arrSize, 1, 40); // amount, min-inclusive, max-inclusive
    rands = sortVectorInt(rands);

    for (size_t i = 0; i < arrSize; i++) {
        arr[i] = rands[i];
    }
}

void first() {
    std::string input;
    uint16_t sides, rolls;
    uint64_t total = 0;
    std::vector<int> results;
    size_t idx = 0;

    // loop to verify format and only break on valid
    while (1) {
        input = getString(std::cin, "Dice roll (XdY, X=rolls, Y=sides, d=d, 1d6, max 65535): ");

        try {
            rolls = (uint16_t)std::stoul(input, &idx, 10);
            
            // verify if format was XdY
            if (input[idx] != 'd') {
                std::cout << "Invalid input, try again" << std::endl;
                continue;
            }
            // delete rolls and delimiting 'd' from string for sides std::stoul
            input.erase((size_t)0, ++idx);

            // verify string didn't end on the delimiter
            if (input.size() <= (size_t)0) {
                std::cout << "Invalid input, try again" << std::endl;
                continue;
            }

            // reset idx to 0
            idx = (size_t)0;
            sides = (uint16_t)std::stoul(input, &idx, 10);

            // verify if std::stoul reached end of string
            if (idx != input.size()) {
                std::cout << "Invalid input, try again" << std::endl;
                continue;
            }            
        } catch (std::invalid_argument) { //std::stoul
            std::cout << "Invalid input, try again" << std::endl;
            continue;
        } catch (std::out_of_range) { //std::stoul
            std::cout << "One of numbers was too large, try again" << std::endl;
            continue;
        }

        if (sides <= 0) {
            std::cout << "Can't have 0 or negative sides, try again" << std::endl;
            continue;
        }
        break;
    }

    results = getRandomNumbers(rolls, 1, sides); // amount, min-inclusive, max-inclusive

    std::cout << "\nYou rolled with " << rolls << "d" << sides << ": " << std::endl;

    // print out all individual rolls
    for (uint32_t i = 0; i < rolls; i++) {
        if (i != 0) std::cout << ", ";
        std::cout << results[i];

        total += (uint64_t)results[i];
    }

    // sum of rolls
    std::cout << "\nTotal roll: " << total << std::endl;
}

void second() {
    const size_t nums_size = 7;
    int nums[nums_size];
    arvoLottonumerot(nums, nums_size);

    std::cout << "[";
    for (size_t i = 0; i < nums_size; i++) {
        if (i != 0) std::cout << ", ";
        std::cout << nums[i];
    }
    std::cout << "]" << std::endl;
}

void third() {
    const uint8_t throwAmount = 5;
    int throws[throwAmount];

    for (uint8_t i = 0; i < throwAmount; i++) {
        std::string prompt = "Input throw x: ";
        prompt[12] = (char)(i+49); // direct increment into char since i is assumed to always be under 9
        throws[i] = getInt(std::cin, prompt);
    }

    std::cout << "\nYour best throw was " << getMaxInt(throws, (size_t)throwAmount) << std::endl;
    std::cout << "From throws [";
    for (uint8_t i = 0; i < throwAmount; i++) {
        if (i != 0) std::cout << ", ";
        std::cout << throws[i];
    }
    std::cout << "]" << std::endl;
}

void fourth() {
    const size_t max_entries = 255;
    std::string phoneNums[max_entries];
    std::string names[max_entries];
    size_t contactAmount = 0;
    std::string number;
    std::string name;
    char op = '\0';
    bool quit = false;
    bool add = false;
    bool lookUp = false;

    while (!quit) {
        op = getChar(std::cin, "Operation (1. add contact, 2. look up contact, 3. quit): ");
        switch (op) {
            case '1':
                add = true;
                break;
            case '2':
                lookUp = true;
                break;
            case '3':
                std::cout << "Quitting..." << std::endl;
                quit = true;
                break;
            default:
                std::cout << "Invalid operation, try again";
                break;
        }

        if (add) {
            if (contactAmount >= max_entries) {
                std::cout << "Contact list full!" << std::endl;
                continue; // while
            }

            name = getString(std::cin, "Input name: ");
            number = getString(std::cin, "Input phone number: ");

            phoneNums[contactAmount] = number;
            names[contactAmount] = name;

            contactAmount++;
            add = false;
        }
        if (lookUp) {
            name = getString(std::cin, "Name? ");
            bool found = false;

            for (size_t i = 0; i < contactAmount; i++) {
                if (names[i] == name) {
                    number = phoneNums[i];
                    found = true;
                    break; // for
                }
            }

            if (found) {
                std::cout << "Found " << name << ", with phone number " << number << std::endl;
            } else {
                std::cout << "Couldn't find " << name << std::endl;
            }

            lookUp = false;
        }

        std::cout << std::endl;
    }
}

int main() {
    char res = '\0';
    while (res != 'q') {
        res = getChar(std::cin, "Run through which exercise? (1-4, q to quit): ");

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
            default:
                std::cout << "Invalid input, try again" << std::endl;
                break;
        }

        std::cout << "------------------------------\n" << std::endl;
    }

    return 0;
}
