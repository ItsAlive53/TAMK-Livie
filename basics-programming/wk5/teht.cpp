#include <iostream>
#include <string>

double max(double a, double b) {
    return a > b ? a : b;
}

double min(double a, double b) {
    return a < b ? a : b;
}

void first() {
    int i = 5;
    while (i >= -5) {
        std::cout << i << " ";
        i--;
    }
    std::cout << std::endl;

    i = 0;
    while (i < 50) {
        i += 2;
        std::cout << i << " ";
        /**
        *
        * Alternately,
        * i++;
        * if (i%2 == 0) std::cout << i;
        *
        **/
    }
    std::cout << std::endl;
}

void second() {
    int in;
    int sum = 0;

    std::cout << "Input numbers, one at a time, end with 0" << std::endl;
    while (1) {
        std::cin >> in; // breaks the entire program flow if input isnt a number
        sum += in;

        if (in == 0) break;
    }
    std::cout << "The sum of your numbers is " << sum << std::endl;
}

void third() {
    std::string opInput;
    char op = '0';
    int in;
    int balance = 0;

    std::cout << "Welcome to our bank." << std::endl;

    while (op != '3') {
        std::cout << "Your current balance is " << balance << " €" << std::endl;

        std::cout << "Choose operation (1. Deposit, 2. Withdraw, 3. Quit): ";
        std::cin >> opInput;
        op = opInput[0];

        switch (op) {
            case '1':
                std::cout << "Enter the sum to deposit: ";
                std::cin >> in;
                balance += in;
                break;
            case '2':
                std::cout << "Enter the sum to withdraw: ";
                std::cin >> in;
                balance -= in;
                break;
            case '3':
                std::cout << "See you later.";
                break;
            default:
                std::cout << "Invalid operation, try again...";
                break;
        }

        std::cout << std::endl;
    }
}

void fourth(bool bonus) {
    double points[5];
    double len;
    int j = 0;
    double in;
    double total = 0;

    std::cout << "Jump length: ";
    std::cin >> len;

    while (j < 5) {
        std::cout << "Points given by judge " << j+1 << ": ";
        std::cin >> in;
        points[j] = in;
        total += in;

        j++;
    }

    std::cout << "Points for jump: ";

    if (bonus) {
        total -= min(min(min(min(points[0], points[1]), points[2]), points[3]), points[4]);
        total -= max(max(max(max(points[0], points[1]), points[2]), points[3]), points[4]);
    }
    total += 0.9 * len;
    std::cout << total;

    std::cout << std::endl;
}

int main() {
    std::string input;
    char res = '\0';
    while (res != 'q') {
        std::cout << "Run through which exercise? (1-4, b for bonus version of 4, q to quit)" << std::endl;

        std::cin >> input;
        res = input[0];

        std::cout << std::endl;
        switch (res) {
            case 'q':
                std::cout << "Quitting..." << std::endl;
                break;
            case '1':
                first();
                break;
            case '2':
                second();
                break;
            case '3':
                third();
                break;
            case '4':
                fourth(false);
                break;
            case 'b':
                fourth(true);
                break;
            default:
                std::cout << "Invalid input, try again" << std::endl;
                break;
        }

        std::cout << "------------------------------\n" << std::endl;
    }

    return 0;
}

