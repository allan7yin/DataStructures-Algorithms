#include <vector>
using namespace std;

class Solution {
public:
  int minimumDifference(vector<int> &nums, int k) {
    if (nums.size() == 1) {
      return 0;
    }
    sort(nums.begin(), nums.end());
    // something like 1 4 7 9 // for k = 2, sliding window
    int minDiff = INT_MAX;
    int highest = -1;
    int lowest = INT_MAX;
    int l = 0;
    for (int r = 0; r < nums.size(); r++) {
      lowest = min(lowest, nums[r]);
      highest = max(highest, nums[r]);
      if (r - l < k) {
        if (r != 0) {
          minDiff = min(minDiff, highest - lowest);
        }
        if (r - l == (k - 1)) {
          l++;
        }
        continue;
      }

      // do this here since we k elements in the window now
      if (abs(nums[r] - nums[r - 1]) < minDiff) {
        minDiff = abs(nums[r] - nums[r - 1]);
        l = r;
        continue;
      }
      minDiff = min(minDiff, highest - lowest);
      l++;
    }
    return minDiff;
  }
};