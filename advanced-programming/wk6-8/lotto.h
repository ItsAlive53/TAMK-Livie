#include <stdint.h>

enum class LottoResult: uint8_t {
    ERROR = 0,
    NONE = 1
    // TODO: Add other results
};

class LottoMachine {

private:
    int* correctRow;

public:
    LottoMachine();
    ~LottoMachine();

    void printDebugString();


};
