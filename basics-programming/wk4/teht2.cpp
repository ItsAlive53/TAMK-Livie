#include <iostream>
#include <iomanip>

int main() {
    double income, tax;

    std::cout << "Input income (€): " << std::endl;
    std::cin >> income;

    tax = income * 0.1975; // 19.75% added

    if (income < 17600) {
        // do nothing
    } else if (income == 17600) {
        tax += 8;
    } else if (income < 26400) {
        tax += (income - 17600) * 0.06;
    } else if (income == 26400) {
        tax += 536;
    } else if (income < 43500) {
        tax += (income - 26400) * 0.1725;
    } else if (income == 43500) {
        tax += 3485.75f;
    } else if (income < 76100) {
        tax += (income - 43500) * 0.2125;
    } else if (income == 76100) {
        tax += 10413.25f;
    } else {
        tax += (income - 76100) * 0.3125;
    }

    std::cout << std::setprecision(2) << std::fixed;
    std::cout << "Your tax total is " << tax << " €." << std::endl;

    return 0;
}

