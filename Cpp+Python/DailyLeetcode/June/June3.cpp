class Solution {
public:
  int longestPalindrome(string s) {
    // simple hashmap question
    int length = 0;
    int maxOdd = 0;
    unordered_map<char, int> fmap;
    for (int i = 0; i < s.size(); i++) {
      fmap[s[i]]++;
    }

    for (auto kv_pair : fmap) {
      if (kv_pair.second % 2 == 0) {
        length += kv_pair.second;
      } else {
        maxOdd = max(maxOdd, kv_pair.second);
      }
    }
    length += maxOdd;
    return length;
  }
};
