#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int target = -nums[i];
            int l = i + 1, r = n - 1;
            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    vector<int> temp = {-target, nums[l], nums[r]};
                    result.push_back(temp);
                    while (l < r && nums[l] == nums[l + 1])
                        l++;
                    while (r > l && nums[r] == nums[r - 1])
                        r--;
                    l++;
                    r--;
                } else if (nums[l] + nums[r] > target) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return result;
    }
};