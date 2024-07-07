#include <map>
#include <string>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freqMap;
        int n = s.size();
        int l = 0, mostFreq = 0;
        int maxLength = 0;

        for (int r = 0; r < n; r++) {
            freqMap[s[r]]++;
            int window = r - l + 1;
            for (auto &kv_pair : freqMap){
                mostFreq = max(mostFreq, kv_pair.second);
            }

            if ((window - mostFreq) <= k) {
                maxLength = max(maxLength, window);
                // re-compute the most frequent

            } else {
                freqMap[s[l]]--;
                l++;
            }
        }
        return maxLength;
    }
};

int main() {}