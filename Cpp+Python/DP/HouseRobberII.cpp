#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        // dp on 2 index ranges: 0 to n-2 and 1 to n-1
        if (nums.size() == 1) {
            return nums[0];
        }
        return max(find_amount(nums, 0, nums.size() -1), find_amount(nums, 1, nums.size()));
    }

    int find_amount(vector<int> &nums, int start, int end) {
        if (end - start == 1) {
            return nums[start];
        }
        int prev1 = max(nums[start], nums[start+1]);
        int prev2 = nums[start];
        int value = prev1;
        for (int i = start + 2; i < end; i++) {
            value = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = value;
        }
        return value;
    }
};

int main() {}