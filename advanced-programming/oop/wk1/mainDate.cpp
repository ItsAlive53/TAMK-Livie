#include <iostream>

#include "date.h"

int main() {
    Date today = Date(2020, 3, 4);
    Date tomorrow = Date(2020, 3, 5);

    std::cout << "Today: ";
    today.printDate();
    std::cout << '\n';

    std::cout << "Tomorrow: ";
    tomorrow.printDate();
    std::cout << std::endl;



    Date test = Date(1984, 1, 1);
    test.readDateFromInput();
    test.printDate();

    std::cout << std::endl;

    return 0;
}
