#include <iostream>
#include <map>

// for setprecision to display prices properly
#include <iomanip>

int main() {
    int weight;

    // <upper weight limit, price>
    std::map<int, double> pricingLimits;
    pricingLimits[50] = 0.6;
    pricingLimits[100] = 0.9;
    pricingLimits[250] = 1.3;
    pricingLimits[500] = 2.1;
    pricingLimits[1000] = 3.5;
    pricingLimits[2000] = 5.5;

    std::cout << "Enter weight of first class letter (g): ";
    std::cin >> weight;

    std::map<int, double>::iterator i = pricingLimits.begin();
    while (i != pricingLimits.end()) {
        // key = upper weight limit
        int limit = i->first;
        // value = price
        double price = i-> second;

        if (weight <= limit) {
            // set fixed precision to display prices as 0.00
            std::cout << std::fixed << std::setprecision(2);

            std::cout << "With current pricings, your letter postage will be "
                      << price << " €" << std::endl;

            return 0;
        }

        i++;
    }

    // reach here = over all limits
    std::cout << "Weight over top limit, try again." << std::endl;
    return 0;
}

