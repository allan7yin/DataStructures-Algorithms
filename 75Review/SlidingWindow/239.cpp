#include <deque>
#include <vector>

using namespace std;

// this is O(n) time complexity -> smart use of deque to maintain a monotonically decreasing deque
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<pair<int, int>> dq;

        // push the first k onto it, only if larger than head
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[i] > dq.back().second) {
                dq.pop_back();
            }

            dq.push_back({i, nums[i]});
        }

        result.push_back(dq.front().second);

        for (int r = k; r < nums.size(); r++) {
            // pop if needed
            if (!dq.empty() && dq.front().first < r - k + 1) {
                dq.pop_front();
            }

            while (!dq.empty() && nums[r] > dq.back().second) {
                dq.pop_back();
            }
            dq.push_back({r, nums[r]});
            result.push_back(dq.front().second);
        }
        return result;
    }
};
