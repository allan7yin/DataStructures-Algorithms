#include <string>
#include <unordered_map>
using namespace std;

/*
 * This question is remarkly similar to the subarry sum equals k question. This
 * questions, I have also made notes for in Obsidian, please review them
 *
 */
class Solution {
public:
  int findTheLongestSubstring(string s) {
    int parity = 0;
    int max_length = 0;
    unordered_map<int, int> prefix_freq{{0, -1}};
    unordered_map<char, int> dp{
        {'a', 4}, {'e', 3}, {'i', 2}, {'o', 1}, {'u', 0}};

    for (int i = 0; i < s.size(); i++) {
      if (dp.find(s[i]) != dp.end()) {
        // current character is vowel, adjust bitmap
        int shift_pos = dp[s[i]];
        parity ^= 1 << shift_pos;
      }

      if (prefix_freq.find(parity) != prefix_freq.end()) {
        max_length = max(max_length, i - prefix_freq[parity]);
      } else {
        prefix_freq[parity] = i;
      }
    }
    return max_length;
    if (int i  = 0; i < s.size(); i++) {

    }
  }
};
