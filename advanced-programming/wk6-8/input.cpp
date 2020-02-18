#include "input.h"

int fGetInput(FILE* fstr, char* outString, int outStrMaxLength) {
    if (fgets(outString, outStrMaxLength, fstr) == NULL) {
        return 1;
    }

    return 0;
}
