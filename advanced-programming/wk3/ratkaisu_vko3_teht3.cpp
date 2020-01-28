#include <stdio.h>

int min(int x, int y) {
    return x < y ? x : y;
}

int min(int x, int y, int z) {
    return min(x, min(y, z));
}

int min(int x, int y, int z, int w) {
    return min(x, min(y, z, w));
}

int main() {
    const int TEST_INT_AMOUNT = 36;
    // Array generated using RNG method from another program
    int testArray[TEST_INT_AMOUNT] = {
        -91, -105, -482, 277,
        180, -210, -294, -345,
        -482, 480, -474, 102,
        190, 421, -118, 127,
        323, -274, 441, -319,
        -77, -102, 451, 233,
        415, -496, -328, 467,
        -415, 310, 278, -132,
        -335, 153, -492, 96/*,
        -165, 264, 52, 420,
        468, 216, 368, 408,
        388, -420, -425, -18
        */
    };

    printf("Fours:\n");
    
    for (int i = 0; i < TEST_INT_AMOUNT; i += 4) {
        printf("The smallest number in [");
        for (int j = 0; j < 4; j++) {
            if (j != 0) printf(", ");
            printf("%i", testArray[i+j]);
        }
        printf("] is %i\n", min(testArray[i], testArray[i+1], testArray[i+2], testArray[i+3]));
    }

    printf("\nThrees:\n");

    for (int i = 0; i < TEST_INT_AMOUNT; i += 3) {
        printf("The smallest number in [");
        for (int j = 0; j < 3; j++) {
            if (j != 0) printf(", ");
            printf("%i", testArray[i+j]);
        }
        printf("] is %i\n", min(testArray[i], testArray[i+1], testArray[i+2]));
    }

    printf("\nPairs:\n");

    for (int i = 0; i < TEST_INT_AMOUNT; i += 2) {
        printf("The smallest number in [");
        for (int j = 0; j < 2; j++) {
            if (j != 0) printf(", ");
            printf("%i", testArray[i+j]);
        }
        printf("] is %i\n", min(testArray[i], testArray[i+1]));
    }
    return 0;
}
