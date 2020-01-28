#include <iostream>

int main() {
    int n;

    std::cout << "Input number: ";
    std::cin >> n;

    while (n > 0) {
        std::cout << "Hello World!" << std::endl;
        n--;
    }

    int i = 0;
    while (i < 15) {
        std::cout << i+1 << " ";
        i++;
    }
    std::cout << std::endl;

    return 0;
}

