#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

// same as the CSES one I just finished
class Solution {
  public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        int n = nums.size();
        multiset<int> upper; // Stores the larger half
        multiset<int> lower; // Stores the smaller half
        vector<double> medians;

        auto rebalance = [&]() {
            while (lower.size() > upper.size() + 1) {
                auto it = prev(lower.end());
                upper.insert(*it);
                lower.erase(it);
            }
            while (upper.size() > lower.size()) {
                auto it = upper.begin();
                lower.insert(*it);
                upper.erase(it);
            }
        };

        auto get_median = [&]() -> double {
            rebalance();
            if (lower.size() == upper.size()) {
                return ((double)(*prev(lower.end())) + *upper.begin()) / 2.0;
            }
            return *prev(lower.end());
        };

        for (int i = 0; i < n; i++) {
            if (lower.empty() || nums[i] <= *prev(lower.end())) {
                lower.insert(nums[i]);
            } else {
                upper.insert(nums[i]);
            }

            if (i >= k) {
                int evict = nums[i - k];
                if (lower.count(evict)) {
                    lower.erase(lower.find(evict));
                } else {
                    upper.erase(upper.find(evict));
                }
            }

            if (i >= k - 1) {
                medians.push_back(get_median());
            }
        }

        return medians;
    }
};