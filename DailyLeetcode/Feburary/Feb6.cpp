#include <vector>
#include <string>

using namespace std;

/*
Feb 6th, 2024
    - Sort characters by frequency: https://leetcode.com/problems/sort-characters-by-frequency/description/?envType=daily-question&envId=2024-02-07
*/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        int maxFreq = 0;

        for (char &ch : s) {
            freq[ch]++;
            maxFreq = max(maxFreq, freq[ch]);
        }

        vector<vector<char>> buckets(maxFreq + 1);
        // now, we add these to respective bucket 
        for (auto &kv_pair : freq) {
            buckets[kv_pair.second].push_back(kv_pair.first);
        }

        // now, build result
        string result = "";
        for (int i = buckets.size() - 1; i >= 0; i--) {
            if (buckets[i].empty()) {
                continue;
            }

            for (char ch : buckets[i]) {
                result.append(i, ch);
            }
        }
        return result;
    }
};