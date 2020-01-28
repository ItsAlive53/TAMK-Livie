#include <iostream>

int main() {
    int number;

    int* numberPointer = &number;
    *numberPointer = 7;

    std::cout << "number: " << number << '\n';
    std::cout << "number address: " << &number << '\n';
    std::cout << "numberPointer: " << numberPointer << '\n';
    std::cout << "numberPointer address: " << &numberPointer << '\n';

    *&*&number = 2;

    std::cout << "size of number: " << sizeof(number) << '\n';
    std::cout << "size of numberPointer: " << sizeof(number) << '\n';

    int* secondPointer;
    // Segmentation fault (core dumped)
    //*secondPointer = 727;

    secondPointer = nullptr;
    // Segmentation fault (core dumped)
    //*secondPointer = 21;

    std::cout << std::endl;

    return 0;
}
