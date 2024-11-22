#include <vector>

using namespace std;

/*
Link: https://leetcode.com/problems/rearrange-array-elements-by-sign/?envType=daily-question&envId=2024-02-14
*/
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // create 2 arrays that will contain the positive and negative numbers in 
        // order that they are found in nums
        vector<int> sol;
        vector<int> pos;
        vector<int> neg;
        for (int &num:nums) {
            if (num >= 0) {
                pos.push_back(num);
            } else {
                neg.push_back(num);
            }
        }

        int n = nums.size() / 2;
        for (int i = 0; i < n; i++) {
            sol.push_back(pos[i]);
            sol.push_back(neg[i]);
        }
        return sol;
    }
};