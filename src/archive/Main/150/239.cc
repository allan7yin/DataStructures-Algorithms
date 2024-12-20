#include <queue>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // increasing deque question
        vector<int> result;
        deque<int> dq;
        int l = 0;

        for (int i = 0; i < nums.size(); i++) {
            while (!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);

            if (dq.front() < l) {
                dq.pop_front();
            }

            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
                l++;
            }
        }
        return result;
    }
};