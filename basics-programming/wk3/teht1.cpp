#include <iostream>

int main() {
    float km, priceGas, priceDiesel, usageGas, usageDiesel, taxDiesel;
    float totalGas, totalDiesel;

    std::cout << "Total km/year? ";
    std::cin >> km;

    std::cout << "Gas price (/l)? ";
    std::cin >> priceGas;

    std::cout << "Diesel price (/l)? ";
    std::cin >> priceDiesel;

    std::cout << "Gas usage l/100km? ";
    std::cin >> usageGas;

    std::cout << "Diesel usage l/100km? ";
    std::cin >> usageDiesel;

    std::cout << "Diesel tax (€/year)? ";
    std::cin >> taxDiesel;

    totalGas = km * usageGas * priceGas;
    totalDiesel = km * usageDiesel * priceDiesel + taxDiesel;

    float sub;
    if (totalGas < totalDiesel) {
        sub = totalDiesel - totalGas;
        std::cout << "Using gas would be cheaper by " << sub << " €" << std::endl;
    } else if (totalGas > totalDiesel) {
        sub = totalGas - totalDiesel;
        std::cout << "Using diesel would be cheaper by " << sub << " €" << std::endl;
    } else {
        std::cout << "Both are equally cheap, or an error happened somewhere" << std::endl;
    }

    return 0;
}

