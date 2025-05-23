#include "../bits/stdc++.h"

using namespace std;

class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        int longest = 0;
        unordered_set<int> seen(nums.begin(), nums.end());

        for (auto &num : seen) {
            if (seen.count(num - 1) == 0) {
                // start of the sequence
                int copy = num;
                int length = 0;
                while (seen.count(copy) > 0) {
                    length++;
                    copy++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};