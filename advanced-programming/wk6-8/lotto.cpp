#include <stdio.h>

#include "lotto.h"

LottoMachine::LottoMachine() {
    printf("LottoMachine constructor called\n");
    result = LottoResult::NONE;
    correctRow = new int[7] {1, 2, 3, 4, 5, 6, 7};
}

LottoMachine::~LottoMachine() {
    printf("LottoMachine destructor called\n");
    delete[] correctRow;
}

void LottoMachine::printDebugString() {
    printf("LottoMachine v0.3.14159 running\n");
    printf("Correct row is {%i, %i, %i, %i, %i, %i, %i}\n", *correctRow, *(correctRow + 1), *(correctRow + 2), *(correctRow + 3), *(correctRow + 4), *(correctRow + 5), *(correctRow + 6));
    printf("Result is ");
    switch (this->result) {
        case LottoResult::NONE:
            printf("NONE");
            break;
        case LottoResult::ERROR:
            printf("ERROR");
            break;
        default:
            printf("UNDEFINED");
            break;
    }
    printf("\n");
    fflush(stdin);
}
