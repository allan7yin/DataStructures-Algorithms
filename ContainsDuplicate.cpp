#include <set>
#include <iostream>

using namespace std;

/*
Link: https://leetcode.com/problems/contains-duplicate/description/
How to solve:
    - push into set and compare length with original array 
    - keep in mind the iterator constructor used here 
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> mySet(nums.begin(), nums.end());
        return mySet.size() != nums.size();
    }
};

int main()
{
    Solution solution;
    vector<int> nums1 = {1,2,3,4,5,6,7,7};
    vector<int> nums2 = {1,2,3,4,5,6,7};
    cout << "first one is " << solution.containsDuplicate(nums1) << endl;
    cout << "second one is " << solution.containsDuplicate(nums2) << endl;
}