#include <iostream>

void rSwap(int& x, int& y) {
    int swp = x;
    x = y;
    y = swp;
}

int main() {
    int array[10];

    for (int i = 0; i < 10; i++) {
        array[i] = i+1;
    }

    // print array
    std::cout << '[' << array[0];
    for (int i = 1; i < 10; i++) {
        std::cout << ", " << array[i];
    }
    std::cout << "]\n";

    std::cout << "\nswap\n";

    int* startP = array;
    int* endP = array + 9;

    while (startP < endP) {
        rSwap(*startP, *endP);
        startP++;
        endP--;
    }

    // print array
    std::cout << '[' << array[0];
    for (int i = 1; i < 10; i++) {
        std::cout << ", " << array[i];
    }
    std::cout << "]\n";

    std::cout << std::endl;

    return 0;
}
