#include <stdio.h>
#include <string.h>

#include "input.h"
#include "lotto.h"

int main() {
    LottoMachine lm;
    LottoRow testRow;

    lm.printDebugString();
    testRow = lm.getUserRow();

    printf("Test row: {%i, %i, %i, %i, %i, %i, %i}\n", testRow.num1, testRow.num2, testRow.num3, testRow.num4, testRow.num5, testRow.num6, testRow.num7);
    printf("Test row extra: %i\n", testRow.numExtra);
    printf("Test row plus: %i\n", testRow.numPlus);

    char a[128];
    printf("Input something: ");
    if (fGetInput(stdin, a, 128) == 0) {
        printf("Input: %s\nLength: %i\n", a, strlen(a));
    } else {
        fprintf(stderr, "Error in input\n");
    }

    fflush(NULL);
    return 0;
}
