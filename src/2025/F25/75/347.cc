#include "../bits/stdc++.h"

using namespace std;

class Solution {
  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        int n = nums.size();
        unordered_map<int, int> fmp;
        for (int &num : nums) {
            fmp[num]++;
        }

        vector<vector<int>> buckets(n + 1);
        for (auto &[num, freq] : fmp) {
            buckets[freq].push_back(num);
        }

        vector<int> res;
        for (int i = n; i >= 0 && res.size() < k; --i) {
            for (int num : buckets[i]) {
                res.push_back(num);
                if (res.size() == k) break;
            }
        }
        return res;
    }
};