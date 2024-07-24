// constant space in this numeric questions, usually entails the use of bitwise operations

// this is 32 bit integers
#include <cstdint>
class Solution {
  public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t sol = 0;
        for (int i = 0; i < 32; i++) {
            // remeber this, to get last bit of n, we just do bitwise AND with 000001, etc.
            // this removes all other bits due to AND with 0, and only the last bit is kept
            sol = (sol << 1) | (n & 1);
            n >>= 1;
        }
        return sol;
    }
};