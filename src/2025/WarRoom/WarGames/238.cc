#include "../bits/stdc++.h"
using namespace std;

class Solution {
  public:
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> fwd(nums.size(), 1);
        vector<int> bwd(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++) {
            fwd[i] = fwd[i - 1] * nums[i - 1];
        }

        for (int i = nums.size() - 2; i >= 0; i--) {
            bwd[i] = bwd[i + 1] * nums[i + 1];
        }

        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            result.push_back(fwd[i] * bwd[i]);
        }

        return result;
    }
};