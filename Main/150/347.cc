#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        vector<int> result;
        // count in hashmap
        unordered_map<int, int> fmap;
        for (int &num : nums) {
            fmap[num]++;
        }

        priority_queue<pair<int, int>> maxheap;
        for (auto &kv : fmap) {
            maxheap.push({kv.second, kv.first});
        }

        for (int i = 0; i < k; i++) {
            if (!maxheap.empty()) {
                auto top = maxheap.top();
                result.push_back(top.second);
                maxheap.pop();
            }
        }
        return result;
    }
};