#include "bits/stdc++.h"

using namespace std;

// nums.length <= 10^5 -> need <= nlogn solution, n^2 is too slow in this question
/*
- Something to think about -> if we are looking for subsequence -> we don't need to maintian order like this
-

hint 1: maintain 2 arrays, one for the odd numbers and one for the even numbers

Say we have example: [4,1,5,3,1], k = 3

odd = [1,5,3,1]
even = [4]
k = 3


*/
class Solution {
  public:
    long long largestEvenSum(vector<int> &nums, int k) {
        vector<int> odd;
        vector<int> even;

        for (int &num : nums) {
            if (num % 2 == 0) {
                even.push_back(num);
            } else {
                odd.push_back(num);
            }
        }

        // need even number of odd numbers to sum to even value
        for ()
    }
};