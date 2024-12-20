#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int n = nums.size();
        for (auto &num : nums) {
            map[num]++;
        }

        vector<vector<int>> buckets(n+1);
        for (auto &kv_pair : map) {
            buckets[kv_pair.second].push_back(kv_pair.first);
        }
        
        vector<int> solution;
        for (int i = n; i >= 0; i--) {
            if (solution.size() >= k) break;
            if (!buckets[i].empty()) {
                solution.insert(solution.end(), buckets[i].begin(), buckets[i].end());
            }
        }
        return solution;
    }
};

int main() {}