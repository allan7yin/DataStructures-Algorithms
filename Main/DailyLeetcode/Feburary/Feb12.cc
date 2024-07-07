/*
Link: https://leetcode.com/problems/majority-element/?envType=daily-question&envId=2024-02-10
*/
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // we solve this with Boyer-Moore Majority Voting Algorithm
        // first pass through 
        int count = 0;
        int candidate = -1;

        for (int &num:nums) {
            if (count == 0) {
                candidate = num;
                count = 1;
            } else {
                if (num == candidate) {
                    count++;
                } else {
                    count--;
                }
            }
        }

        // now, check if it is > floor(n/2)
        int freq = 0;
        for (int &num:nums) {
            if (num == candidate) {
                freq++;
            }
        }
        int result = (freq > (nums.size() / 2)) ? candidate : -1;
        return result;
    }
};
