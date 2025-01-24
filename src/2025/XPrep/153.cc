#include "bits/stdc++.h";
using namespace std;

class Solution {
  public:
    int findMin(vector<int> &nums) {
        int minVal = INT_MAX;
        int n = nums.size();
        int l = 0, r = n - 1;

        if (nums[l] < nums[r]) return nums[l];

        while (l <= r) {
            int m = l + (r - l) / 2;
            minVal = min(minVal, nums[m]);
            // something like [4,5,6,7,0,1,2]
            if (nums[m] > nums[r]) {
                // min element is on the right
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return minVal;
    }
};

// 6 7 0 1 2 4 5