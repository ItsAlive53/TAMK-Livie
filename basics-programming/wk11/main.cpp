#include <iostream>

// dependencies for mylib.h
#include <string>
#include <vector>
// END dependencies

#include "mylib.h"

struct student {
    std::string firstname;
    std::string lastname;
    std::string studentNumber;
    unsigned int credits;
};

void first() {
    student s;

    s.firstname = getString(std::cin, "Input first name: ");
    s.lastname = getString(std::cin, "Input last name: ");
    s.studentNumber = getString(std::cin, "Input student number: ");
    s.credits = getInt(std::cin, "Input how many credits the student has: ");

    std::cout << '\n';

    std::cout << "First name: " << s.firstname << '\n';
    std::cout << "Last name: " << s.lastname << '\n';
    std::cout << "Student number: " << s.studentNumber << '\n';
    std::cout << "Total credits: " << s.credits << " cr" << std::endl;
}

struct nation {
    std::string name;
    unsigned long population;
    unsigned long area;
    std::string leader;
};

void second() {
    nation n1, n2;

    std::cout << "Nation 1:" << std::endl;
    n1.name = getString(std::cin, "Input nation's name: ");
    n1.population = getUnsignedLong(std::cin, "Input nation's population: ");
    n1.area = getUnsignedLong(std::cin, "Input nation's area in square meters: ");
    n1.leader = getString(std::cin, "Input the leader of the nation: ");

    std::cout << '\n';

    std::cout << "Nation 2:" << std::endl;
    n2.name = getString(std::cin, "Input nation's name: ");
    n2.population = getUnsignedLong(std::cin, "Input nation's population: ");
    n2.area = getUnsignedLong(std::cin, "Input nation's area in square meters: ");
    n2.leader = getString(std::cin, "Input the leader of the nation: ");

    std::cout << "Nation 1:" << '\n';
    std::cout << "\tName: " << n1.name << '\n';
    std::cout << "\tPopulation: " << n1.population << '\n';
    std::cout << "\tArea: " << n1.area << '\n';
    std::cout << "\tLed by " << n1.leader << '\n';

    std::cout << '\n';

    std::cout << "Nation 2:" << '\n';
    std::cout << "\tName: " << n2.name << '\n';
    std::cout << "\tPopulation: " << n2.population << '\n';
    std::cout << "\tArea: " << n2.area << '\n';
    std::cout << "\tLed by " << n2.leader << std::endl;
}

void third() {
    const int COUNT = 5;
    nation nations[COUNT];

    for (int i = 0; i < COUNT; i++) {
        std::cout << "Nation " << i+1 << ":\n";
        nations[i].name = getString(std::cin, "Input nation's name: ");
        nations[i].population = getUnsignedLong(std::cin, "Input nation's population: ");
        nations[i].area = getUnsignedLong(std::cin, "Input nation's area in square meters: ");
        nations[i].leader = getString(std::cin, "Input the leader of the nation: ");
    }

    std::cout << '\n';

    for (int i = 0; i < COUNT; i++) {
        std::cout << "Nation " << i+1 << ":" << '\n';
        std::cout << "\tName: " << nations[i].name << '\n';
        std::cout << "\tPopulation: " << nations[i].population << '\n';
        std::cout << "\tArea: " << nations[i].area << '\n';
        std::cout << "\tLed by " << nations[i].leader;

        if (i == COUNT-1) std::cout << std::endl;   // endl on last output only
        else std::cout << "\n\n";                   // double \n for clear separation
    }
}

void printStudentInfo(student& s) {     // Use reference to not need to copy the object for printing
    std::cout << "First name: " << s.firstname << '\n';
    std::cout << "Last name: " << s.lastname << '\n';
    std::cout << "Student number: " << s.studentNumber << '\n';
    std::cout << "Total credits: " << s.credits << " cr" << std::endl;
}

void fourth() {
    student s;

    s.firstname = getString(std::cin, "Input first name: ");
    s.lastname = getString(std::cin, "Input last name: ");
    s.studentNumber = getString(std::cin, "Input student number: ");
    s.credits = getInt(std::cin, "Input how many credits the student has: ");

    std::cout << '\n';

    printStudentInfo(s);
}

void createStudent(student& s) {
    s.firstname = getString(std::cin, "Input first name: ");
    s.lastname = getString(std::cin, "Input last name: ");
    s.studentNumber = getString(std::cin, "Input student number: ");
    s.credits = getInt(std::cin, "Input how many credits the student has: ");
}

void fifth() {
    student s;
    
    createStudent(s);
    std::cout << '\n';
    printStudentInfo(s);
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
