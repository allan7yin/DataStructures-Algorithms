#include "../bits/stdc++.h"
using namespace std;

// return all triplets of terms that sum to 0
class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1;
            int r = nums.size() - 1;
            int target = -nums[i];

            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    result.push_back({nums[l], nums[r], nums[i]});
                    while (l < r && nums[r] == nums[r - 1]) {
                        r--;
                    }
                    r--;

                    while (l < r && nums[l] == nums[l + 1]) {
                        l++;
                    }
                    l++;
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