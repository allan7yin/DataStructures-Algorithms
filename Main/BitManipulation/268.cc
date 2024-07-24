#include <vector>
using namespace std;

// OHHHH
// so, in the nums array, and the array of numbers [0,n], the only one missing is the one that
// does not appear twice throughout these arrays -> we use the fact that x ^ x = 0
class Solution {
  public:
    int missingNumber(vector<int> &nums) {
        int val = 0;
        int n = nums.size();

        for (int &num : nums) {
            val ^= num;
        }

        for (int i = 0; i <= n; i++) {
            val ^= i;
        }
        return val;
    }
};

// 3 0 1
// [011, 000, 001] -> XOR of all of these -> 010
// XOR only == 1 when we have like 001 and 110 -> sum up to 111

// 3 6
// 011, 110 -> XOR = 101 -> 5