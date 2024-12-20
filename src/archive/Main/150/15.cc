#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> result;

    for (int i = 0; i < n - 2; i++) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue; // skip duplicates
      int target = -nums[i];

      int l = i + 1, r = n - 1;
      while (l < r) {
        int u = nums[l] + nums[r];
        if (u == target) {
          result.push_back({nums[i], nums[l], nums[r]});
          while (l < r && nums[l] == nums[l + 1])
            l++;
          while (r > l && nums[r] == nums[r - 1])
            r--;
          l++;
          r--;
        } else if (u < target) {
          l++;
        } else {
          r--;
        }
      }
    }
    return result;
  }
};
