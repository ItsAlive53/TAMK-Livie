#include <iostream>

int main() {
    float base, height, area;

    std::cout << "Anna kolmion kanta metreina: ";
    std::cin >> base;

    std::cout << "Anna kolmion korkeus metreina: ";
    std::cin >> height;

    area = base * height / 2;
    std::cout << "Kolmion pinta-ala on " << area << " m^2" << std::endl;

    return 0;
}

