#include <iostream>

int main() {
    float height1, height2;

    std::cout << "Input the height of the first person in cm: ";
    std::cin >> height1;

    std::cout << "Input the height of the second person in cm: ";
    std::cin >> height2;

    if (height1 == height2) {
        std::cout << "You're the same height" << std::endl;
    } else if (height1 > height2) {
        std::cout << "The first person is taller than the second" << std::endl;
    } else {
        std::cout << "The second person is taller than the first" << std::endl;
    }

    return 0;
}

