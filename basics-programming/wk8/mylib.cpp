#include <string>
#include <iostream>
#include <algorithm> // std::find
#include <random>
#include <chrono>
#include <vector>

#include "mylib.h"

std::string getString(std::istream& istream, std::string promptMessage) {
    std::string input;

    std::cout << promptMessage;
    std::getline(istream, input);

    return input;
}

char getChar(std::istream& istream, std::string promptMessage) {
    std::string input;

    std::cout << promptMessage;
    std::getline(istream, input);

    return input[0];
}

int getInt(std::istream& istream, std::string promptMessage) {
    std::string input;
    int ret;
    bool invalid = false;

    while (1) {
        std::cout << promptMessage << std::endl;
        std::getline(istream, input);

        try {
            ret = std::stoi(input, nullptr, 10);
        } catch (std::invalid_argument) {
            std::cout << "Invalid input, try again" << std::endl;
            invalid = true;
        }

        if (invalid) invalid = false;
        else return ret;
    }
}

float getFloat(std::istream& istream, std::string promptMessage) {
    std::string input;
    int ret;
    bool invalid = false;

    while (1) {
        std::cout << promptMessage;
        std::getline(istream, input);

        try {
            ret = std::stof(input, nullptr);
        } catch (std::invalid_argument) {
            std::cout << "Invalid input, try again" << std::endl;
            invalid = true;
        }

        if (invalid) invalid = false;
        else return ret;
    }
}

double getDouble(std::istream& istream, std::string promptMessage) {
    std::string input;
    int ret;
    bool invalid = false;

    while (1) {
        std::cout << promptMessage;
        std::getline(istream, input);

        try {
            ret = std::stod(input, nullptr);
        } catch (std::invalid_argument) {
            std::cout << "Invalid input, try again" << std::endl;
            invalid = true;
        }

        if (invalid) invalid = false;
        else return ret;
    }
}

std::vector<int> getRandomNumbers(int amount, int min, int max, bool unique) {
    std::vector<int> ret;

    uint32_t rdgen = 0;
    try {
        std::random_device rd;
        rdgen = rd();
    } catch (std::exception) {
        // implementation or device doesn't support random_device, fall back to current timestamp
        std::chrono::high_resolution_clock::time_point curTime = std::chrono::high_resolution_clock::now();
        rdgen = static_cast<uint32_t>(std::chrono::time_point_cast<std::chrono::microseconds>(curTime).time_since_epoch().count());
    }

    std::chrono::high_resolution_clock::time_point curTime = std::chrono::high_resolution_clock::now();
    uint32_t time = static_cast<uint32_t>(std::chrono::time_point_cast<std::chrono::nanoseconds>(curTime).time_since_epoch().count());

    uint64_t rngSeed = (uint64_t)rdgen << 32 | time; // add time-based entropy in case random_device implementation fails to give a true random number

    std::mt19937_64 prng(rngSeed);
    std::uniform_int_distribution<int> dist(min, max); // limits minimum-inclusive, maximum-inclusive, [min, max]

    for (int i = 0; i < amount; i++) {
        int gen = dist(prng);

        if (unique && std::find(ret.begin(), ret.end(), gen) != ret.end()) { // if (value is in vector)
            i--;
        } else {
            ret.push_back(gen);
        }
    }

    return ret;
}

std::vector<int> getUniqueRandomNumbers(int amount, int min, int max) {
    return getRandomNumbers(amount, min, max, true);
}

std::vector<int> sortVectorInt(std::vector<int> vec) {
    // very basic and inefficient sort function

    std::vector<int> sorted;
    int sz = (int)vec.size();

    for (int i = 0; i < sz; i++) {
        int min = vec[0];
        int pos = 0;

        for (int ii = 0; ii < vec.size(); ii++) {
            if (vec[ii] < min) {
                min = vec[ii];
                pos = ii;
            }
        }

        sorted.push_back(min);
        vec.erase(vec.begin() + pos);
    }

    return sorted;
}
