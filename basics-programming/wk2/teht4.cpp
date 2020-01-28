#include <iostream>

int main() {
    // w = weight
    float wLimit, w1, w2, w3, w4, wTotal;

    std::cout << "Syota hissin painoraja (kg): ";
    std::cin >> wLimit;

    std::cout << "Syota ensimmäisen henkilön paino (kg): ";
    std::cin >> w1;

    std::cout << "Syota toisen henkilön paino (kg): ";
    std::cin >> w2;

    std::cout << "Syota kolmannen henkilön paino (kg): ";
    std::cin >> w3;

    std::cout << "Syota viimeisen henkilön paino (kg): ";
    std::cin >> w4;

    wTotal = w1 + w2 + w3 + w4;

    if (wTotal > wLimit) {
        std::cout << "Ylipainoa, hissia ei saa kayttaa!" << std::endl;
    } else {
        std::cout << "Hissi kaytettavissanne!" << std::endl;
    }

    return 0;
}

