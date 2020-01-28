#include <iostream>

int main() {
    int x, y;
    std::cout << "Syota 1. luku: ";
    std::cin >> x;

    std::cout << "Syota 2. luku: ";
    std::cin >> y;

    int sub = x - y;
    int sum = x * y;

    std::cout << "Lukujen erotus on " << sub << ".\n";
    std::cout << "Lukujen tulo on " << sum << ".\n";

    return 0;
}
