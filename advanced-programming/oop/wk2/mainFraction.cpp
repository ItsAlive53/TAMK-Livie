#include <iostream>

#include "fraction.h"

int main() {
    Fraction* frac = new Fraction();

    while (1) {
        frac->queryInfo();
        
        if (!(frac->getDenominator())) {
            std::cout << "Denominator zero detected, quitting" << std::endl;
            break;
        }

        std::cout << "Input: ";
        frac->print();

        std::cout << "\nReduced: ";
        frac->reduce();
        frac->print();

        std::cout << std::endl;
    }

    delete frac;

    return 0;
}
