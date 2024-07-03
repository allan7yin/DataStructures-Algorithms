#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> solution;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        int r = n-1;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) { continue; }
            if (nums[i] > 0) { break; }
            int target = -nums[i];
            l = i + 1;
            r = n - 1;

            while (l < r) {
                if (nums[l] + nums[r] < target) {
                    l++;
                } else if (nums[l] + nums[r] > target) {
                    r--;
                } else if (nums[l] + nums[r] == target){
                    vector<int> asol;
                    asol.push_back(nums[i]);
                    asol.push_back(nums[l]);
                    asol.push_back(nums[r]);
                    solution.push_back(asol);
                    l++;
                    while (nums[l] == nums[l-1] && l < r) {
                        l++;
                    } 
                }
            }
        }
        return solution;
    }
};

int main() {}