#include <vector>
#include <algorithm>
#include <numeric>
/*
Link: https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/?envType=daily-question&envId=2024-02-10
*/

using namespace std;

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // first find sum of everything
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        sum -= nums[nums.size()-1];
        // now move backwards 
        for (int i = nums.size()-1; i >= 0; i--) {
            if (sum > nums[i]) {
                return sum + nums[i];
            } else {
                if (i != 0) {
                    sum -= nums[i-1];
                }
            }
        }
        return -1;
    }
};