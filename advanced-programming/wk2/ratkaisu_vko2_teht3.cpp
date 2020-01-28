#include <iostream>

void iIncrement(int* arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        arr[i]++;
    }
}

void pIncrement(int* arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        (*(arr + i))++;
    }
}

int main() {
    int array[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    std::cout << '[' << array[0];
    for (int i = 1; i < 10; i++) {
        std::cout << ", " << array[i];
    }
    std::cout << "]\n";

    std::cout << "\nindexed increment\n";
    iIncrement(array, 10);

    std::cout << '[' << array[0];
    for (int i = 1; i < 10; i++) {
        std::cout << ", " << array[i];
    }
    std::cout << "]\n";

    std::cout << "\npointer increment\n";
    pIncrement(array, 10);

    std::cout << '[' << array[0];
    for (int i = 1; i < 10; i++) {
        std::cout << ", " << array[i];
    }
    std::cout << "]\n";

    std::cout << std::endl;

    return 0;
}
