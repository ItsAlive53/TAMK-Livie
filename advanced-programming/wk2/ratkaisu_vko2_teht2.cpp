#include <iostream>

void pSwap(int* x, int* y) {
    int swp = *x;
    *x = *y;
    *y = swp;
}

void rSwap(int& x, int& y) {
    int swp = x;
    x = y;
    y = swp;
}

int main() {
    int a = 0x80000000;
    int b = 0x7FFFFFFF;

    std::cout << "a: " << a << '\n';
    std::cout << "b: " << b << '\n';

    std::cout << "\npointer swap\n";
    pSwap(&a, &b);

    std::cout << "a: " << a << '\n';
    std::cout << "b: " << b << '\n';

    std::cout << "\nreference swap\n";
    rSwap(a, b);

    std::cout << "a: " << a << '\n';
    std::cout << "b: " << b << '\n';

    std::cout << std::endl;

    return 0;
}
