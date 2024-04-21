#include <vector>
#include <iostream>
#include <string>
#include <map>

using namespace std;

/*
Link: https://leetcode.com/problems/two-sum/

How to solve:
    - Clever use: we have 2 numbers that sum to target 
    - iterate through the array, if the number needed to be added to this number to form target is in the array, we are done
    - otherwise, add this number to the map, where we map the integer to its index in the map 
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            auto it = map.find(complement);
            if (it != map.end()) {
                return {map[complement], i};
            }
            map[nums[i]] = i;
            
        }
        return {};
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1,2,3,4,5};
    cout << "First one is ";
    vector<int> r1 = solution.twoSum(nums, 3);
    if (r1.size() == 0) {
        cout << "no solution" << endl;
    } else {
        cout << r1[0] << "," << r1[1] << endl;
    }

    cout << "Second one is ";
    r1 = solution.twoSum(nums, 20);
    if (r1.size() == 0) {
        cout << "no solution" << endl;
    } else {
        cout << r1[0] << "," << r1[1] << endl;
    }
}