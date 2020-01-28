#include <iostream>

int max(int x, int y) {
    return x > y ? x : y;
}

int main() {
    int x, y, z;
    std::cout << "Input 3 numbers: " << std::endl;
    std::cin >> x >> y >> z;
    std::cout << "x: " << x << "\ny: " << y << "\nz: " << z << std::endl;

    std::cout << "The largest number was " << max(max(x, y), z) << std::endl;

    return 0;
}

