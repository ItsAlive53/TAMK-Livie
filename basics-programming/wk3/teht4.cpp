#include <iostream>

int main() {
    float x, y;
    char op;

    std::cout << "First number: ";
    std::cin >> x;

    std::cout << "Operation ( + - * / ): ";
    std::cin >> op;

    std::cout << "Second number: ";
    std::cin >> y;

    std::cout << x << " " << op << " " << y << " = ";

    switch (op) {
        case '+':
            std::cout << x + y;
            break;
        case '-':
            std::cout << x - y;
            break;
        case '*':
            std::cout << x * y;
            break;
        case '/':
            std::cout << x / y;
            break;
        default:
            std::cout << "Invalid operator";
            break;
    }

    std::cout << std::endl;
    return 0;
}

