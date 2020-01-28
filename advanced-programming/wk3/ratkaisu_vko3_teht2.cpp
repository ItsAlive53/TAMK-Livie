#include <stdio.h>
#include <math.h>

double getDoubleInput(bool zeroAllowed = true) {
    char in[16];
    double dIn = 0;

    while (1) {
        if (fgets(in, 16, stdin) == NULL) {
            printf("Invalid input, try again: ");
            continue;
        }

        dIn = strtod(in, NULL);
        if (!zeroAllowed && dIn == 0) {
            printf("Invalid input, try again: ");
            continue;
        }
        break;
    }
    return dIn;
}

int main() {
    double input;
    
    printf("Input a number: ");
    input = getDoubleInput();

    printf("Number is within [ %i, %i ]\n", (int)floor(input), (int)ceil(input));
    return 0;
}
