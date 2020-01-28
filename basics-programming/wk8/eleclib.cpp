#include <iostream>

#include "eleclib.h"

float getResistorCurrent(float voltage, float resistance) {
    // U=RI <=> I = U/R
    return voltage / resistance;
}

void printRequiredFuse(float power) {
    // P=UI <=> I = P/U
    // Assuming 220V network
    const float current = power / 220.0f;

    if (current < 0) {
        std::cout << "Negative powers aren't supported at this time.";
    } else if (current < 10) {
        std::cout << "You'll need a fuse rated for 10 A.";
    } else if (current < 16) {
        std::cout << "You'll need a fuse rated for 16 A.";
    } else if (current < 20) {
        std::cout << "You'll need a fuse rated for 20 A.";
    } else {
        std::cout << "You'll need several fuses.";
    }

    std::cout << std::endl;
    return;
}
