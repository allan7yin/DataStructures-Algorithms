#include "bits/stdc++.h"
using namespace std;

// time: nlogn
class Solution {
  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        vector<int> result;
        unordered_map<int, int> count;
        for (int &num : nums) {
            count[num]++;
        }

        priority_queue<pair<int, int>> pq;
        for (auto &kv : count) {
            pq.push({kv.second, kv.first});
        }

        for (int i = 0; i < k; i++) {
            auto top = pq.top();
            result.push_back(top.second);
            pq.pop();
        }

        return result;
    }
};