#include <vector>
using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int m = (l + r) / 2;
      if (nums[m] == target)
        return m;

      if (nums[l] <= nums[m] && nums[m] >= nums[r]) {
        // array state case 1
        if (nums[l] <= target && target <= nums[m]) {
          r = m - 1;
        } else {
          l = m + 1;
        }
      } else {
        if (nums[m] <= target && target <= nums[r]) {
          l = m + 1;
        } else {
          r = m - 1;
        }
      }
    }
    return -1;
  }
};

// [4,5,6,7,0,1,2] rotated 4 times
// [6,7,0,1,2,4,5] rotated 2 times
