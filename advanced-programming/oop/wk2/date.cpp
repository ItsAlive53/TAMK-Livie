#include <iostream>
#include <string>

#include "mylib.h"
#include "date.h"

Date::Date() {
    std::cout << "Ctor-> Date()\n";

    this->init(0, 1, 1);
}

Date::Date(int year) {
    std::cout << "Ctor-> Date(int)\n";

    this->init(year, 1, 1);
}

Date::Date(int year, int month) {
    std::cout << "Ctor-> Date(int, int)\n";

    this->init(year, month, 1);
}

Date::Date(int year, int month, int day) {
    std::cout << "Ctor-> Date(int, int, int)\n";

    this->init(year, month, day);
}

Date::~Date() {
    std::cout << "Dtor-> ~Date()-> (" << this->year << "-" << this->month << "-" << this->day << ")\n";
}

void Date::setYear(int year) {
    if (year < 0) {
        std::cerr << "Invalid year set, defaulted to 0\n";
        this->year = 0;
    } else {
        this->year = year;
    }
}

void Date::setMonth(int month) {
    if (month < 1 || month > 12) {
        std::cerr << "Invalid month set, defaulted to 1\n";
        this->month = 1;
    } else {
        this->month = month;
    }
}

void Date::setDay(int day) {
    if (
        (day < 1)
        || (day > 31)
        // leap year
        || (this->month == 2 && day > 29)
        // non-leap feb
        || (this->month == 2 && this->year % 4 != 0 && day > 28)

        // 30-day months
        || (this->month > 7 && this->month % 2 != 0 && day > 30)
        || (this->month < 8 && this->month % 2 == 0 && day > 30)
    ) {
        std::cerr << "Invalid day set, defaulted to 1\n";
        this->day = 1;
    } else {
        this->day = day;
    }
}

int Date::getYear() {
    return this->year;
}

int Date::getMonth() {
    return this->month;
}

int Date::getDay() {
    return this->day;
}

void Date::printDate() {
    std::cout << day << "." << month << "." << year;
}

void Date::readDateFromInput() {
    int input;

    while (1) {
        input = getInt(std::cin, "Input year: ");

        if (input < 0) {
            std::cout << "Invalid year, try again\n";
        } else {
            break;
        }
    }
    this->setYear(input);

    while (1) {
        input = getInt(std::cin, "Input month: ");

        if (input < 1 || input > 12) {
            std::cout << "Invalid month, try again\n";
        } else {
            break;
        }
    }
    this->setMonth(input);

    while (1) {
        input = getInt(std::cin, "Input day: ");

        if (input < 1 || input > 31) {
            std::cout << "Invalid day, try again\n";
        } else if (
            // leap year
            (this->month == 2 && input > 29)
            // non-leap feb
            || (this->month == 2 && this->year % 4 != 0 && input > 28)

            // 30-day months
            || (this->month > 7 && this->month % 2 != 0 && input > 30)
            || (this->month < 8 && this->month % 2 == 0 && input > 30)
        ) {
            std::cout << "Invalid day, try again\n";
        } else {
            break;
        }
    }
    this->setDay(input);
}

void Date::incrementDay() {
    this->day++;

    if (this->month == 2 && this->day > 28) {
        // leap years
        if (this->year % 4 == 0 && this->day == 29) return;

        this->day = 1;
        this->month++;
    } else if ((this->month > 7 && this->month % 2 == 0) || (this-> month < 8 && this->month % 2 != 0)) {
        if (this->day > 31) {
            this->day = 1;
            this->month++;
        }
    } else if (this->day > 30) {
        this->day = 1;
        this->month++;
    }

    if (this->month > 12) {
        this->month = 1;
        this->year++;
    }
}

void Date::init(int year, int month, int day) {
    this->year = year;
    this->month = month;
    this->day = day;
}
