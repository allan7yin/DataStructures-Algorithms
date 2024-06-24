#include <vector>
using namespace std;

class Solution {
public:
  int minimumDifference(vector<int> &nums, int k) {
    if (nums.size() < k) {
      return 0;
    }
    sort(nums.begin(), nums.end());
    int minDiff = INT_MAX;
    for (int i = 0; i <= nums.size() - k; i++) {
      minDiff = min(minDiff, nums[i + k - 1] - nums[i]);
    }
    return minDiff;
  }
};