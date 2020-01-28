#include <iostream>
#include <sstream>

// dependencies for mylib.h
#include <string>
#include <vector>
// END dependencies

#include "mylib.h"

void setAge(int& age) {
    age = getInt(std::cin, "Input age: ");
}

void first() {
    int results[10];

    for (int i = 0; i < 10; i++) {
        results[i] = getInt(std::cin, "Input grade: ");
    }
    std::cout << "\nGrades:" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << results[i] << "\t";
        if ((i+1) % 5 == 0) {
            std::cout << "\n";
        }
    }
    std::cout << std::endl;

    // calcAvgInt(array, array length)
    std::cout << "Average from grades is " << calcAvgInt(results, sizeof(results) / sizeof(results[0])) << std::endl;
}

void second() {
    // BEGIN constants
    const char dot_empty = ' ';
    const char dot_histogram = '*';
    const char line_vertical = '|';
    const char line_horizontal = '-';
    const char line_junction = '+';
    const uint16_t max_row_length = 64;
    const int months = 12; // Max 65535, positive, gets used as uint16_t
    // END constants

    bool overflowed = false;

    uint16_t rain[months];

    for (int i = 0; i < months; i++) {
        std::stringstream prompt;
        prompt << "Input rain amount for month " << i+1 << ": ";
        rain[i] = getUInt16(std::cin, prompt.str());
    }

    uint16_t max = getMaxUInt16(rain, months);

    // Clamp max to 64 to make sure the table fits on most console windows
    // Rows with over 64 get split up into several further down
    if (max > max_row_length) {
        max = max_row_length;
        overflowed = true;
    }

    // BEGIN table print

    /** Initial mockup for table layout:
    *       +------max-+
    *       |-01-|-***-|
    *       |-02-|-*---|
    *       |-03-|-***-|
    *       |----|-**--|
    *       +------max-+
    * */

    // Top row
    printChar(line_junction, 1);
    printChar(line_horizontal, max + 7);
    printChar(line_junction, 1, true);

    // Calendar rows
    for (int i = 0; i < 12; i++) {
        // Calc how many times the row overflows
        uint16_t fullRows = rain[i] / max;
        uint16_t remainder = rain[i] % max;

        if (rain[i] == max) {
            // avoid making empty rows when value = max
            fullRows = 0;
            remainder = max;
        }

        for (uint16_t j = 0; j < fullRows; j++) {
            // Print month number only for first row
            if (j == 0) {
                printChar(line_vertical, 1);
                printChar(dot_empty, 1);

                if (i < 9) std::cout << "0";
                std::cout << i+1;
                printChar(dot_empty, 1);
                printChar(line_vertical, 1);
                printChar(dot_empty, 1);
            } else {
                printChar(line_vertical, 1);
                printChar(dot_empty, 4);
                printChar(line_vertical, 1);
                printChar(dot_empty, 1);
            }

            // Full row, print out max amount
            printChar(dot_histogram, max);
            printChar(dot_empty, 1);
            printChar(line_vertical, 1, true);
        }

        if (fullRows > 0 && remainder > 0) {
            // Print last row for overflowed rows
            printChar(line_vertical, 1);
            printChar(dot_empty, 4);
            printChar(line_vertical, 1);
            printChar(dot_empty, 1);

            printChar(dot_histogram, remainder);
            printChar(dot_empty, max - remainder);

            printChar(dot_empty, 1);
            printChar(line_vertical, 1, true);
        } else if (fullRows == 0) {
            // If there is only one row, print the month number as well
            printChar(line_vertical, 1);
            printChar(dot_empty, 1);

            if (i < 9) std::cout << "0";
            std::cout << i+1;
            printChar(dot_empty, 1);
            printChar(line_vertical, 1);
            printChar(dot_empty, 1);

            printChar(dot_histogram, remainder);
            printChar(dot_empty, max - remainder);

            printChar(dot_empty, 1);
            printChar(line_vertical, 1, true);
        }

        if (i != months - 1 && overflowed) {
            // print on all except last, if overflowing rows are required
            printChar(line_junction, 1);
            printChar(line_horizontal, max + 7);
            printChar(line_junction, 1, true);
        }
    }

    // Closing row
    printChar(line_junction, 1);
    printChar(line_horizontal, max + 7);
    printChar(line_junction, 1, true);

    // END table print
}

void third() {
    char op = '\0';
    float lhs, rhs;

    lhs = getFloat(std::cin, "Input floating point number 1: ");
    rhs = getFloat(std::cin, "Input floating point number 2: ");
    op = getChar(std::cin, "Choose operand (1-add, 2-subtract, 3-multiply, 4-divide): ");

    switch (op) {
        case '1':
            std::cout << lhs << " + " << rhs << " = " << lhs+rhs;
            break;
        case '2':
            std::cout << lhs << " - " << rhs << " = " << lhs-rhs;
            break;
        case '3':
            std::cout << lhs << " * " << rhs << " = " << lhs*rhs;
            break;
        case '4':
            std::cout << lhs << " / " << rhs << " = " << lhs/rhs;
            break;
        default:
            std::cout << "Invalid operand";
            break;
    }

    std::cout << std::endl;
}

void fourth() {
    bool first = true;
    for (int i = 0; i < 1000; i++) {
        if (isPrimeNumberInt(i)) {
            if (first) {
                first = false;
                std::cout << i;
            } else {
                std::cout << ", " << i;
            }
        }
    }

    std::cout << std::endl;
}

void fifth() {
    int age = 0;
    std::cout << "age = " << age << std::endl;
    setAge(age);
    std::cout << "age = " << age << std::endl;
}

int main() {
    char res = '\0';
    while (res != 'q') {
        res = getChar(std::cin, "Run through which exercise? (1-5, q to quit): ");

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
