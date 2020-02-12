#ifndef __INCLUDED_LOTTO_H__
#define __INCLUDED_LOTTO_H__

#include <stdint.h>

enum class LottoResult: uint8_t {
    ERROR = 0,
    NONE = 1
    // TODO: Add other results
};

class LottoMachine {

private:
    int* correctRow;
    LottoResult result;

public:
    LottoMachine();
    ~LottoMachine();

    void printDebugString();


};

#endif  // __INCLUDED_LOTTO_H__
