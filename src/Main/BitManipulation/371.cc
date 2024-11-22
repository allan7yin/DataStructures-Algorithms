// 9 + 11 -> 1001 + 1011
class Solution {
  public:
    int getSum(int a, int b) {
        while (b != 0) {
            int carry = a & b; // will shift this left by 1
            a ^= b;            // sum without carries

            b = carry << 1;
        }
        return a;
    }
};

// a = 2, b = 3
// 010
// 011
// ---
// 101

// 1000, 500, 250, 125, 62.5 / 62, 31, 16.5 / 16, 8, 4, 2, 1

// at most like 2^10 = 1024