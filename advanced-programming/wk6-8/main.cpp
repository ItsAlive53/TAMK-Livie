#include <stdio.h>

#include "lotto.h"

int main() {
    LottoMachine lm;
    LottoRow testRow;

    lm.printDebugString();
    testRow = lm.getUserRow();

    printf("Test row: {%i, %i, %i, %i, %i, %i, %i}\n", testRow.num1, testRow.num2, testRow.num3, testRow.num4, testRow.num5, testRow.num6, testRow.num7);
    printf("Test row extra: %i\n", testRow.numExtra);
    printf("Test row plus: %i\n", testRow.numPlus);

    lm.fReadUserRow(stdin);

    fflush(NULL);
    return 0;
}
