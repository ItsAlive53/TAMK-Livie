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
    if (seconds > 921599) {
        // Specification had no specified upper limit,
        // assuming max 255 hours is fine,
        // 255 hours in seconds = 918000,
        // with 59 minutes and 59 seconds, 255:59:59, 921599,
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

int main() {
    const int TEST_INPUT_AMOUNT = 10;
    uint32_t testInputs[TEST_INPUT_AMOUNT] = {
        0U,
        1U,
        500U,
        2000U,
        10000U,
        918000U,
        918001U,
        921599U,
        921600U,
        ~(static_cast<uint32_t>(0U)) // NOT a 0 for max unsigned value, explicit cast in case implementation bit width varies
    };

    /**
     * Excepted outputs:
     * 
     * 000:00:00
     * 000:00:01
     * 000:08:20
     * 000:33:20
     * 002:46:40
     * 255:00:00
     * 255:00:01
     * 255:59:59
     * ERROR
     * ERROR
     * 
     * */

    uint8_t hours, minutes, seconds;

    for (int i = 0; i < TEST_INPUT_AMOUNT; i++) {
        if (timeFromSeconds(testInputs[i], hours, minutes, seconds)) {
            printf("%u seconds is %u hours, %u minutes, and %u seconds\n", testInputs[i], hours, minutes, seconds);
        } else {
            printf("Couldn't convert %u, skipping\n", testInputs[i]);
        }
    }

    return 0;
}
