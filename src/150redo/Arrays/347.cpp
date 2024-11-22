#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

/*
Runtime Analysis:
- first loop is O(n)
- pushing into bucekt is also O(n)

Final runtime is O(n)
*/
class Solution {
  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> res;
        unordered_map<int, int> mp;
        for (auto &num : nums) {
            mp[num]++;
        }

        // use buckets for this
        vector<vector<int>> b(n + 1);
        for (auto &kv : mp) {
            b[kv.second].push_back(kv.first);
        }

        for (int i = n; i > 0; i--) {
            if (res.size() >= k) break;
            if (!b[i].empty()) res.insert(res.end(), b[i].begin(), b[i].end());
        }

        return res;
    }
};