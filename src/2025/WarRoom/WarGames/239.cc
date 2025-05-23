#include "../bits/stdc++.h"
using namespace std;

/*
maintain a monotonically decreasing queue?

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

*/
class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> result;
        int t = 0;
        deque<pair<int, int>> dq;

        for (int i = 0; i < nums.size(); i++) {
            // if top element has fallen of window
            if (!dq.empty() && dq.front().second < i - k + 1) {
                dq.pop_front();
            }

            while (!dq.empty() && dq.back().first < nums[i]) {
                dq.pop_back();
            }

            dq.push_back({nums[i], i});

            if (i >= k - 1) {
                result.push_back(dq.front().first);
            }
        }

        return result;
    }
};