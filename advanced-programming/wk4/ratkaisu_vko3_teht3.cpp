#include <stdlib.h>     // strtoul
#include <stdint.h>     // uint8_t
#include <stdio.h>      // printf, fgets

unsigned long getUnsignedLongIntInput(bool zeroAllowed = true) {
    char in[256];
    unsigned long ulIn = 0;

    while (1) {
        if (fgets(in, 256, stdin) == NULL) {
            printf("Invalid input, try again: ");
            continue;
        }

        ulIn = strtoul(in, NULL, 10);
        if (!zeroAllowed && ulIn == 0) {
            printf("Invalid input, try again: ");
            continue;
        }
        break;
    }
    return ulIn;
}

struct time_ty {
    uint8_t hours;
    uint8_t minutes;
    uint8_t seconds;
};

int main() {
    time_ty tm;

    printf("Input hours: ");
    tm.hours = (uint8_t)getUnsignedLongIntInput();

    printf("Input minutes: ");
    tm.minutes = (uint8_t)getUnsignedLongIntInput();

    printf("Input seconds: ");
    tm.seconds = (uint8_t)getUnsignedLongIntInput();

    if (tm.hours > 23 || tm.minutes > 59 || tm.seconds > 59) {
        perror("Invalid inputs for time\n");
        return 0;
    }

    printf("%02u:%02u:%02u\n", tm.hours, tm.minutes, tm.seconds);

    time_ty *pTm = &tm;
    printf("%02u:%02u:%02u\n", pTm->hours, pTm->minutes, pTm->seconds);

    time_ty testTimeA, testTimeB;
    testTimeB = {12U, 34U, 53U};
    testTimeA = testTimeB;

    if (
        testTimeA.hours == testTimeB.hours &&
        testTimeA.minutes == testTimeB.minutes &&
        testTimeA.seconds == testTimeB.seconds
    ) {
        printf("Contents are equal\n");
    } else {
        printf("Contents are NOT equal\n");
    }

    return 0;
}
