#include <stdlib.h>     // strtoul
#include <stdint.h>     // uint32_t, uint16_t, uint8_t
#include <stdio.h>      // printf, fgets

/**
 * 
 * All sanity checks omitted in the code, as the spec states to assume all inputs as sane
 * 
 * */

struct time_ty {
    uint8_t hours;
    uint8_t minutes;
    uint8_t seconds;
};

/**
 * 
 * Takes a time in seconds from midnight, and converts it to human-readable hours, minutes and seconds
 * 
 * @param seconds The amount of seconds from midnight, to convert to a human-readable time
 * @param outTime Converted output time
 * 
 * @return Returns whether or not function ran successfully
 * 
 * */
bool timeFromSeconds(uint32_t seconds, time_ty& outTime) {
    if (seconds > 86399) {
        // Using 23 hours as max limit,
        // as 24 would overflow to the next day
        // 23 hours in seconds = 82800,
        // with 59 minutes and 59 seconds, 23:59:59, 86399,
        // using that as upper limit
        return false;
    }

    // Set temporary variable for calculations
    uint16_t tempMins = seconds / 60;

    // Remainder = how many seconds, under a minute
    outTime.seconds = (uint8_t)(seconds % 60);

    // Remainder = how many minutes, under an hour
    outTime.minutes = (uint8_t)(tempMins % 60);

    // Calculate hours
    outTime.hours = (uint8_t)(tempMins / 60);

    // Successful
    return true;
}

/**
 * 
 * Takes a human-readable timestamp format, and converts it to raw seconds
 * 
 * @param time Time to convert
 * 
 * @return Returns the amount of seconds the input time converts to, or 0 if inputs are invalid
 * 
 * */
uint32_t secondsFromTime(time_ty& time) {
    if (time.hours > 23 || time.minutes > 59 || time.seconds > 59) {
        // Assuming seconds/minutes over 59 as invalid, as these should overflow into minutes/hours, respectively
        // Similar for hours over 23
        perror("Invalid input in secondsFromTime(time_ty)\n");
    }

    uint32_t retSeconds;

    retSeconds = (uint32_t)(time.seconds);
    retSeconds += (uint32_t)(time.minutes * 60);
    retSeconds += (uint32_t)(time.hours * 60 * 60);

    return retSeconds;
}

/**
 * 
 * Gets an unsigned integer from standard input
 * 
 * @param zeroAllowed Whether or not an input of 0 is considered valid, default = true
 * 
 * @return Returns the unsigned integer from standard input
 * 
 * */
unsigned long getUnsignedLongIntInput(bool zeroAllowed = true) {
    // Initialise input array and return variable
    char in[256];
    unsigned long ulIn = 0;

    // Loop until valid input
    while (1) {
        // Pull up to 256 (input array size) characters from standard input
        if (fgets(in, 256, stdin) == NULL) {
            // Verify if input was empty, error and return to loop start if it was
            printf("Invalid input, try again: ");
            continue;
        }

        // Convert input to unsigned integer, in base 10
        ulIn = strtoul(in, NULL, 10);

        // If zero is considered non-valid, check if input converted to zero
        if (!zeroAllowed && ulIn == 0) {
            printf("Invalid input, try again: ");
            continue;
        }

        // If no continues were hit, assume valid input and continue to return
        break;
    }
    return ulIn;
}

/**
 * 
 * Calculate difference from 2 timestamps
 * 
 * @param x Smaller timestamp
 * @param y Larger timestamp
 * 
 * @return Returns the difference, (y - x), or 0 if something fails
 * 
 * */
time_ty timeDifference(time_ty& x, time_ty& y) {
    time_ty ret;
    if (!timeFromSeconds(secondsFromTime(y) - secondsFromTime(x), ret)) {
        perror("Error in timeDifference(time_ty&, time_ty&)\n");
        return {0, 0, 0};
    } else {
        return ret;
    }
}

int main() {
    time_ty timeA, timeB, timeDiff;

    printf("Timestamp 1\n");
    printf("Input hours: ");
    timeA.hours = (uint8_t)getUnsignedLongIntInput();

    printf("Input minutes: ");
    timeA.minutes = (uint8_t)getUnsignedLongIntInput();

    printf("Input seconds: ");
    timeA.seconds = (uint8_t)getUnsignedLongIntInput();

    printf("\nTimestamp 2 (Should be larger)\n");
    printf("Input hours: ");
    timeB.hours = (uint8_t)getUnsignedLongIntInput();

    printf("Input minutes: ");
    timeB.minutes = (uint8_t)getUnsignedLongIntInput();

    printf("Input seconds: ");
    timeB.seconds = (uint8_t)getUnsignedLongIntInput();

    timeDiff = timeDifference(timeA, timeB);

    printf("\nTime 1: %02u:%02u:%02u\n\nTime 2: %02u:%02u:%02u\n", timeA.hours, timeA.minutes, timeA.seconds, timeB.hours, timeB.minutes, timeB.seconds);
    printf("\nTime difference: %02u:%02u:%02u\n", timeDiff.hours, timeDiff.minutes, timeDiff.seconds);
    
    return 0;
}
