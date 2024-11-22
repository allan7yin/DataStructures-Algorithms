#include <vector>
using namespace std;

class Solution {
public:
  int findMin(vector<int> &nums) {
    int minv = nums[0];
    // still sorted, can extract some information from this
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int m = (l + r) / 2;
      minv = min(minv, nums[m]);
      if (nums[l] <= nums[m] && nums[m] >= nums[r]) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    return minv;
  }
};

// [4,5,6,7,0,1,2] rotated 4 times
// [6,7,0,1,2,4,5] rotated 2 times
