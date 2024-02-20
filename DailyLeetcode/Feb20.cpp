#include <vector>

using namespace std;
/*
https://leetcode.com/problems/missing-number/description/?envType=daily-question&envId=2024-02-20
    - compute the sum of the numbers, keep subtracting numbers in num, remaining number is the one not in there
    - this is O(n) runtime and O(1) space 
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int result = (n * (n+1)) / 2;
        for (int i = 0; i < n; i++) {
            result -= nums[i];
        }
        return result;
    }
};