#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int characterReplacement(string s, int k) {
    int l = 0;
    int maxLength = 1;
    int currentLength = 1;
    char prev = s[0];
    int mostFreq = 0;
    std::unordered_map<int, int> fmap;
    for (int r = 0; r < s.size(); r++) {
      fmap[s[r]]++;
      int window = r - l + 1;
      for (auto &kv : fmap) {
        mostFreq = max(mostFreq, kv.second);
      }
      if ((window - mostFreq) <= k) {
        maxLength = max(maxLength, window);
        // re-compute the most frequent
      } else {
        fmap[s[l]]--;
        l++;
      }
    }
    return maxLength;
  }
};
