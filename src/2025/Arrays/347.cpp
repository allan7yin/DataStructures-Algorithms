#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> mp;
        for (int &num : nums) {
            mp[num]++;
        }

        priority_queue<pair<int, int>> pq;
        for (auto &kv : mp) {
            pq.push({kv.second, kv.first});
        }

        vector<int> result;
        for (int i = 0; i < k; i++) {
            auto top = pq.top();
            result.push_back(top.second);
            pq.pop();
        }

        return result;
    }
};

// runtime is:
// pushing into pq is log(n) so -> nlog(K) where K is count, worst case n