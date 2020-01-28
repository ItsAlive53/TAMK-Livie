#include <stdio.h>

const int MIN_NUM_TO_CHECK = 1;
const int MAX_NUM_TO_CHECK = 10000;

enum PRIME_METHOD: int {
    Efficient = 3,
    SquareRoot = 2,
    Half = 1,
    All = 0
};

bool isPrime(int x, PRIME_METHOD method = Efficient) {
    if (x < 2) {
        // Specification didn't mention whether or not we consider 1 to be a prime number
        // As this can vary depending on the person, this implementation
        // assumes 0 and 1 as non-prime. As the specification only mentioned
        // testing positive values, it ignores negative values.
        return false;
    }

    if (method == Efficient) {
        // Get common numbers quick-checked.
        if (x == 2 || x == 3 || x == 5) return true;
        if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0) return false;

        // Iterate up to square root, and skip even numbers.
        for (int i = 7; i*i <= x; i += 2) {
            if (x % i == 0) return false;
        }
    }

    if (method == SquareRoot) {
        // If we reach square root and it doesn't hit a divisible number,
        // it won't be divisible by a larger number.
        for (int i = 2; i*i <= x; i++) {
            if (x % i == 0) return false;
        }
    }

    if (method == Half) {
        // By the point of reaching half of the numbers size, we'll have reached
        // the largest numbers it could be divisible by.
        for (int i = 2; i <= x/2; i++) {
            if (x % i == 0) return false;
        }
    }

    if (method == All) {
        // Most inefficient implementation.
        for (int i = 2; i < x; i++) {
            if (x % i == 0) return false;
        }
    }

    // If we get to this point, the number has to be prime.
    return true;
}

int main() {
    int primesFound = 0;
    int totalChecked = 0;
    bool firstPrinted = false;

    printf("Initial set is [");
    for (int i = MIN_NUM_TO_CHECK; i <= MAX_NUM_TO_CHECK; i++) {
        totalChecked++;

        if (firstPrinted) printf(", ");
        else firstPrinted = true;
        printf("%i", i);
    }

    firstPrinted = false;

    printf("\nPrime numbers with efficient method:\n[");
    for (int i = MIN_NUM_TO_CHECK; i <= MAX_NUM_TO_CHECK; i++) {
        if (isPrime(i, PRIME_METHOD::Efficient)) {
            if (firstPrinted) printf(", ");
            else firstPrinted = true;
            printf("%i", i);

            primesFound++;
        }
    }
    printf("]\nTotal primes: %i (%.2f %)\n", primesFound, (double)primesFound / (double)totalChecked * 100.0);

    firstPrinted = false;
    primesFound = 0;

    printf("\nPrime numbers with check-until-square-root method:\n[");
    for (int i = MIN_NUM_TO_CHECK; i <= MAX_NUM_TO_CHECK; i++) {
        if (isPrime(i, PRIME_METHOD::SquareRoot)) {
            if (firstPrinted) printf(", ");
            else firstPrinted = true;
            printf("%i", i);

            primesFound++;
        }
    }
    printf("]\nTotal primes: %i (%.2f %)\n", primesFound, (double)primesFound / (double)totalChecked * 100.0);

    firstPrinted = false;
    primesFound = 0;

    printf("\nPrime numbers with check-half method:\n[");
    for (int i = MIN_NUM_TO_CHECK; i <= MAX_NUM_TO_CHECK; i++) {
        if (isPrime(i, PRIME_METHOD::Half)) {
            if (firstPrinted) printf(", ");
            else firstPrinted = true;
            printf("%i", i);

            primesFound++;
        }
    }
    printf("]\nTotal primes: %i (%.2f %)\n", primesFound, (double)primesFound / (double)totalChecked * 100.0);

    firstPrinted = false;
    primesFound = 0;

    printf("\nPrime numbers with check-all method:\n[");
    for (int i = MIN_NUM_TO_CHECK; i <= MAX_NUM_TO_CHECK; i++) {
        if (isPrime(i, PRIME_METHOD::All)) {
            if (firstPrinted) printf(", ");
            else firstPrinted = true;
            printf("%i", i);

            primesFound++;
        }
    }
    printf("]\nTotal primes: %i (%.2f %)\n", primesFound, (double)primesFound / (double)totalChecked * 100.0);

    return 0;
}
