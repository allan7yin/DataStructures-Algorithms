#include <vector>

class Solution {
public:
  void sortColors(std::vector<int> &nums) {
    int l = 0, r = nums.size() - 1, mid = 0;
    while (mid <= r) {
      if (nums[mid] == 0) {
        std::swap(nums[l], nums[mid]);
        mid++;
        l++;
      } else if (nums[mid] == 1) {
        mid++;
      } else {
        std::swap(nums[mid], nums[r]);
        r--;
      }
    }
  }
};