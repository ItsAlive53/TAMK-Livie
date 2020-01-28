#include <iostream>

int main() {
    int inc = 50; // increment

    std::cout << "Anna ikasi? ";

    int age;
    std::cin >> age;

    age += inc;

    std::cout << inc << " vuoden kuluttua olet " << age << " vuotias\n";
    return 0;
}
