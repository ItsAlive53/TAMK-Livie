#include <iostream>
#include <string>
#include <cmath> // used in 4
#include <iomanip> // used in 5
#include <limits> // used in 5

double max(double a, double b) {
    return a > b ? a : b;
}

double min(double a, double b) {
    return a < b ? a : b;
}

void first() {
    for (int i = 1; i <= 10; i++) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    for (int i = 2; i <= 20; i+=2) {
        std::cout << i;
        if (i != 20) std::cout << ", ";
    }
    std::cout << std::endl;
}

void second() {
    double vel = 0; // m/s
    double accel = 9.81; // m/s²
    int stopAt; // s
    std::string input; // temporary container to filter out bad input
    bool invalid = false;

    while (1) {
        std::cout << "Input time in seconds: ";
        std::getline(std::cin, input);

        try {
            stopAt = std::stoi(input, nullptr, 10);
        } catch (std::invalid_argument) {
            std::cout << "Invalid input, try again" << std::endl;
            invalid = true;
        }

        if (invalid) invalid = false;
        else break;
    }

    // broken up for readability
    std::cout << "Time" << "\t" << "Velocity (km/h)" << std::endl;

    for (int sec = 0; sec <= stopAt; sec++) {
        vel = accel * sec; // v = gt
        std::cout << sec << "\t" << (vel * 3.6) << std::endl;
    }
}

void third() {
    std::string name, surname, street, zip, city;
    std::string input;

    // copypaste, refactor into separate function later

    while (1) {
        std::cout << "Input first name: ";
        std::getline(std::cin, input);

        if (input.size() <= (size_t) 0) // empty string
            std::cout << "Invalid input, try again" << std::endl;
        else {
            name = input;
            break;
        }
    }

    while (1) {
        std::cout << "Input last name: ";
        std::getline(std::cin, input);

        if (input.size() <= (size_t) 0)
            std::cout << "Invalid input, try again" << std::endl;
        else {
            surname = input;
            break;
        }
    }

    while (1) {
        std::cout << "Input street name: ";
        std::getline(std::cin, input);

        if (input.size() <= (size_t) 0)
            std::cout << "Invalid input, try again" << std::endl;
        else {
            street = input;
            break;
        }
    }

    while (1) {
        std::cout << "Input zip code: ";
        std::getline(std::cin, input);

        if (input.size() <= (size_t) 0)
            std::cout << "Invalid input, try again" << std::endl;
        else {
            zip = input;
            break;
        }
    }

    while (1) {
        std::cout << "Input city: ";
        std::getline(std::cin, input);

        if (input.size() <= (size_t) 0)
            std::cout << "Invalid input, try again" << std::endl;
        else {
            city = input;
            break;
        }
    }

    // END copypaste

    std::cout << "Your address is: "
        << name << ' '
        << surname << ' '
        << street << ' '
        << zip << ' '
        << city << ' '
        << std::endl;

    // 3b from here on

    int last = min(name.size(), surname.size());
    bool found = false;
    int cmp1, cmp2;

    // reinventing the wheel
    for (int i = 0; i < last; i++) {
        cmp1 = tolower(name[i]);
        cmp2 = tolower(surname[i]);

        if (cmp1 < cmp2) {
            std::cout << "Alphabetically your first name comes before your last name" << std::endl;
            found = true;
            break;
        } else if (cmp1 > cmp2) {
            std::cout << "Alphabetically your last name comes before your first name" << std::endl;
            found = true;
            break;
        }
    }

    if (!found) {
        if (name.size() > surname.size()) {
            std::cout << "Alphabetically your first name comes before your last name" << std::endl;
        } else if (surname.size() > name.size()) {
            std::cout << "Alphabetically your last name comes before your first name" << std::endl;
        } else {
            std::cout << "Alphabetically your first and last names are equal" << std::endl;
        }
    }
    /**
    *
    * Alternatively:
    * if (name > surname)
    *     output
    * else if (name < surname)
    *     different output
    * else
    *     theyre equal
    *
    **/

    if (name.size() > surname.size()) {
        std::cout << "Your first name is longer than your last name" << std::endl;
    } else if (name.size() < surname.size()) {
        std::cout << "Your last name is longer than your first name" << std::endl;
    } else if (name.size() == surname.size()) {
        std::cout << "Your first and last names are equally long" << std::endl;
    } else {
        std::cout << "Something broke somewhere, this should never happen" << std::endl;
    }
}

void fourth() {
    std::string input;
    char res = '\0';
    double num;

    while (res != 'q') {
        std::cout << "Choose operation (1=sqr, 2=log, 3=exp, 4=tan, q=quit): ";
        std::getline(std::cin, input);
        res = input[0];

        std::cout << std::endl;

        if ((int)res >= (int)'1' && (int)res <= (int)'4') { // res is a valid operator
            while (1) {
                bool invalid = false;

                std::cout << "Input number: ";
                std::getline(std::cin, input);

                try {
                    num = std::stod(input);
                } catch (std::invalid_argument) {
                    std::cout << "Invalid input, try again" << std::endl;
                    invalid = true;
                }

                if (invalid) invalid = false;
                else break;
            }

            switch (res) {
                case '1': // sqr
                    std::cout << "sqrt(" << num << ") = " << sqrt(num) << std::endl;
                    break;
                case '2': // log
                    std::cout << "log(" << num << ") = " << log(num) << std::endl;
                    break;
                case '3': // exp
                    std::cout << "exp(" << num << ") = " << exp(num) << std::endl;
                    break;
                case '4': // tan
                    std::cout << "tan(" << num << ") = " << tan(num) << std::endl;
                    break;
            }
        } else if (res == 'q') {
            std::cout << "Quitting..." << std::endl;
        } else {
            std::cout << "Invalid input, try again" << std::endl;
        }
    }
}

void fifth() {
    std::string input;
    int prec;
    double pi;
    bool invalid = false;

    while (1) {
        std::cout << "Pi at precision (positive numbers only): ";
        std::getline(std::cin, input);

        try {
            prec = std::stoi(input);
        } catch (std::invalid_argument) {
            std::cout << "Invalid input, try again" << std::endl;
            invalid = true;
        }

        if (invalid) invalid = false;
        else {
            if (prec <= 0) {
                std::cout << "Positive numbers only, try again" << std::endl;
            } else {
                break;
            }
        }
    }

    pi = 0.0;

    for (int i = 0; i < prec; i++) {
        if (i % 2 == 0) pi += 4.0 / (2.0*i+1.0);
        else pi -= 4.0 / (2.0*i+1.0);
    }

    std::cout << "Pi = "
        << std::setprecision(std::numeric_limits<double>::max_digits10)
        << pi << std::endl;
}

int main() {
    std::string input;
    char res = '\0';
    while (res != 'q') {
        std::cout << "Run through which exercise? (1-5, q to quit)" << std::endl;

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

