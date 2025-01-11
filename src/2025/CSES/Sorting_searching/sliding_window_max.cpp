#include <set>
#include <vector>

using namespace std;

// n <= 10^5 -> we need < nlogn solution
// optimal linear (amortized) solution is to use monotonically decreasing deque
class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        multiset<int> window;
        vector<int> max_vals;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            window.insert(nums[i]);
            if (i < k - 1) continue;

            if (i >= k) {
                int evict = nums[i - k];
                auto it = window.find(evict);
                if (it != window.end()) {
                    window.erase(it);
                }
            }

            max_vals.push_back(*prev(window.end()));
        }

        return max_vals;
    }
};