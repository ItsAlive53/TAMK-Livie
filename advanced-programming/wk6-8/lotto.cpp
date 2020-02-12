#include <stdio.h>

#include "lotto.h"

LottoMachine::LottoMachine() {
    printf("LottoMachine constructor called\n");
    result = LottoResult::NONE;
    correctRow = {1, 2, 3, 4, 5, 6, 7};
    userRows = new LottoRow[2] {
        {
            1, 2, 3, 4, 5, 6, 7, 10, 21
        },
        {
            2, 4, 5, 7, 8, 10, 11, 21, 31
        }
    };
}

LottoMachine::~LottoMachine() {
    printf("LottoMachine destructor called\n");
    delete[] userRows;
}

void LottoMachine::printDebugString() {
    printf("LottoMachine v0.3.14159 running\n");
    printf("Correct row is {%i, %i, %i, %i, %i, %i, %i}\n", this->correctRow.num1, this->correctRow.num2, this->correctRow.num3, this->correctRow.num4, this->correctRow.num5, this->correctRow.num6, this->correctRow.num7);
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

void LottoMachine::fReadUserRow(FILE* fstr) {
    char in[128];

    printf("Input your numbers, separated by spaces: ");

    while (fgets(in, 128, fstr) == NULL) {
        fprintf(stderr, "No input received, try again: ");
    }

    printf("Your input: %s\n", in);
    // TODO: input handling
}

LottoRow LottoMachine::getUserRow(int index) {
    // TODO: fix inevitable segfaults
    return this->userRows[index];
}
