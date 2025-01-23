#include "bits/stdc++.h";
// runtime: O(n) --> the while loop is amortized constant time
// the number of times it runs is bound by n
class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        int max_length = 0;
        unordered_set<int> u(nums.begin(), nums.end());

        for (int num : u) {
            if (u.count(num - 1) == 0) {
                int local = 1;

                while (u.count(num + 1)) {
                    local++;
                    num++;
                }
                max_length = max(max_length, local);
            }
        }

        return max_length;
    }
};