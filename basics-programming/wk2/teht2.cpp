#include <iostream>

int main() {
    double loan, interest, time, result;

    std::cout << "Syota lainan maara (euroa): ";
    std::cin >> loan;

    std::cout << "Syota korkoprosentti: ";
    std::cin >> interest;

    std::cout << "Syota laina-aika (vuosia): ";
    std::cin >> time;

    // Percentage value, convert to multiplier
    interest /= 100;

    result = loan * interest * time;
    std::cout << "Lainan korot laina-ajalta ovat " << result << " euroa." << std::endl;

    return 0;
}

