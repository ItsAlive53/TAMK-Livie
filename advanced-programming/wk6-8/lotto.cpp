#include <stdio.h>

#include "lotto.h"

LottoMachine::LottoMachine() {
    printf("LottoMachine constructor called\n");
    this->result = LottoResult::NONE;
    this->correctRow = {1, 2, 3, 4, 5, 6, 7};
    this->userRows = new LottoRow[2] {
        {
            1, 2, 3, 4, 5, 6, 7, 10, 21
        },
        {
            2, 4, 5, 7, 8, 10, 11, 21, 31
        }
    };
    this->userRowCount = 2;
}

LottoMachine::~LottoMachine() {
    printf("LottoMachine destructor called\n");
    delete[] this->userRows;
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

int LottoMachine::addUserRow(LottoRow row) {
    if (userRowCount > 0) {
        LottoRow* rowCpy = new LottoRow[userRowCount];
        if (!rowCpy) {
            throw "Failed allocating space for user rows copy\n";
        }
        for (int i = 0; i < userRowCount; i++) {
            rowCpy[i] = userRows[i];
        }
        delete[] userRows;

        userRows = new LottoRow[userRowCount + 1];
        if (!userRows) {
            throw "Failed allocating space for user rows\n";
        }
        for (int i = 0; i < userRowCount; i++) {
            userRows[i] = rowCpy[i];
        }
        delete[] rowCpy;

        userRows[userRowCount] = row;
        userRowCount++;
    }
    return 0;
}

LottoRow LottoMachine::getUserRow(int index) {
    // TODO: fix inevitable segfaults
    return this->userRows[index];
}
