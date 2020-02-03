#include <stdio.h>
#include <new>
#include <chrono>
#include <thread>

int main() {
    /**
     * 
     * Static memory-------
     * MAX COMPILE-TIME ALLOCATION ~5-8 MB,
     * 6 MB and above starts failing half of the time
     * 
     * 
     * Dynamic memory------
     * Allocated successfully at ~17 GB
     * Failed allocating at ~34 GB
     * 
     * 
     * Info----------------
     * Computer equipped with 8 GB RAM, as well as 16 GB swap
     * OS used was Arch Linux
     * 
     * */

    /**
     * 
     * Static memory tests:
     * 
     * unsigned int test = 0;
     * 
     * test = 0x007F0000;
     * char mTest[test];
     * printf("Could allocate array size %u\n", test);
     * 
     * */

    // Dynamic memory tests:

    unsigned long long test = 0;
    unsigned long long max;
    char *aTest;

    test = 131072;

    aTest = new char[1];

    while (1) {
        if (test == 0) break;
        delete[] aTest;

        test *= 2;

        aTest = new (std::nothrow) char[test];

        if (aTest == nullptr) {
            printf("Failed allocating at %llu\n", test);
            break;
        } else {
            printf("Allocated successfully at %llu\n", test);
            max = test;
        }
    }

    // For testing whether allocated space actually worked

    aTest = new char[max];

    for (unsigned long long i = 0; i < max; i++) {
        *(aTest + i) = 'a';
        //printf("Got to %llu\n", i);
    }

    *(aTest + max - 1) = '\0';

    while (1) {
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }

    return 0;
}
