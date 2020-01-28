#include <stdint.h>     // uint32_t, uint16_t, uint8_t
#include <stdio.h>      // printf

/**
 * 
 * Takes a time in seconds from midnight, and converts it to human-readable hours, minutes and seconds
 * 
 * @param seconds The amount of seconds from midnight, to convert to a human-readable time
 * @param outHours Output - How many hours
 * @param outMinutes Output - How many minutes
 * @param outSeconds Output - How many seconds
 * 
 * @return Returns whether or not function ran successfully
 * 
 * */
bool timeFromSeconds(uint32_t seconds, uint8_t& outHours, uint8_t& outMinutes, uint8_t& outSeconds) {
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
    outSeconds = (uint8_t)(seconds % 60);

    // Remainder = how many minutes, under an hour
    outMinutes = (uint8_t)(tempMins % 60);

    // Calculate hours
    outHours = (uint8_t)(tempMins / 60);

    // Successful
    return true;
}

/**
 * 
 * Takes a human-readable timestamp format, and converts it to raw seconds
 * 
 * @param hours Hours to convert
 * @param minutes Minutes to convert
 * @param seconds Seconds to convert
 * 
 * @return Returns the amount of seconds the input time converts to, or 0 if inputs are invalid
 * 
 * */
uint32_t secondsFromTime(uint8_t hours, uint8_t minutes, uint8_t seconds) {
    if (hours > 23 || minutes > 59 || seconds > 59) {
        // Assuming seconds/minutes over 59 as invalid, as these should overflow into minutes/hours, respectively
        // Similar for hours over 23
        perror("Invalid input in secondsFromTime(uint8_t, uint8_t, uint8_t)\n");
    }

    uint32_t retSeconds;

    retSeconds = (uint32_t)(seconds);
    retSeconds += (uint32_t)(minutes * 60);
    retSeconds += (uint32_t)(hours * 60 * 60);

    return retSeconds;
}

int main() {
    const int TEST_INPUT_AMOUNT = 10;
    uint32_t testInputs[TEST_INPUT_AMOUNT] = {
        0U,
        1U,
        500U,
        2000U,
        10000U,
        86399U,
        86400U,
        921599U,
        921600U,
        ~(static_cast<uint32_t>(0U)) // NOT a 0 for max unsigned value, explicit cast in case implementation bit width varies
    };

    /**
     * Excepted outputs:
     * 
     * 00:00:00     0
     * 00:00:01     1
     * 00:08:20     500
     * 00:33:20     2000
     * 02:46:40     10000
     * 23:59:59     86399
     * ERROR
     * ERROR
     * ERROR
     * ERROR
     * 
     * */

    uint8_t hours, minutes, seconds;

    for (int i = 0; i < TEST_INPUT_AMOUNT; i++) {
        if (timeFromSeconds(testInputs[i], hours, minutes, seconds)) {
            printf("%u seconds is %u hours, %u minutes, and %u seconds", testInputs[i], hours, minutes, seconds);
            printf(", which converts back to %u seconds\n", secondsFromTime(hours, minutes, seconds));
        } else {
            printf("Couldn't convert %u, skipping\n", testInputs[i]);
        }
    }

    return 0;
}
