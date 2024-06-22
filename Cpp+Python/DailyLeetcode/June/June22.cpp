#include <vector>

// prefix count
class Solution {
public:
  int numberOfSubarrays(std::vector<int> &nums, int k) {
    int result = 0;
    int numOdd = 0;
    std::vector<int> freq(nums.size() + 1, 0);
    freq[0] = 1;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] % 2 == 1) {
        numOdd++;
      }
      if (numOdd >= k) {
        result += freq[numOdd - k];
      }
      freq[numOdd]++;
    }
    return result;
  }
};
