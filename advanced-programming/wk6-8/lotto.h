#ifndef __INCLUDED_LOTTO_H__
#define __INCLUDED_LOTTO_H__

#include <stdint.h>

enum class LottoResult: uint8_t {
    ERROR = 0,
    NONE = 1
    // TODO: Add other results
};

struct LottoRow {
    uint8_t num1;
    uint8_t num2;
    uint8_t num3;
    uint8_t num4;
    uint8_t num5;
    uint8_t num6;
    uint8_t num7;

    uint8_t numExtra;

    uint8_t numPlus;
};

class LottoMachine {

private:
    LottoRow correctRow;

    LottoRow* userRows;
    int userRowCount;
    LottoResult result;

    int addUserRow(LottoRow);

public:
    LottoMachine();
    ~LottoMachine();

    LottoRow getUserRow(int = 0);

    void printDebugString();


};

#endif  // __INCLUDED_LOTTO_H__
