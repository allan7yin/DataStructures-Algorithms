#include <vector>
#include <unordered_map>
/*
Link: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/?envType=daily-question&envId=2024-02-16
*/

using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // first, create a frequencty map of the numbers 
        int n = arr.size();
        unordered_map<int, int> fmap;
        for (int &num:arr) {
            fmap[num]++;
        }

        // now create buckets for this
        vector<vector<int>> buckets(n+1);
        for (auto &kv:fmap) {
            buckets[kv.second].push_back(kv.first);
        }

        int count = 0;
        // minus k starting from the least frequent numbers
        for (int i = 1; i < buckets.size(); i++) {
            if (buckets[i].empty()) {
                continue;
            }

            // buckets[i] is the number of numbers that occur i times
            if (k > (i * buckets[i].size())) {
                count += buckets[i].size();
                k -= (i * buckets[i].size());
            } else {
                int rem = ceil(((i * buckets[i].size()) - k) / i);
                count += k/i;
                break;
            }
        }
        return fmap.size() - count;
    }
};

