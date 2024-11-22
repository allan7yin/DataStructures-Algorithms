#include <string>
#include <vector>
using namespace std;

// naive brute-force implementation
/*
Naive method: maintain a hashmap of s2 character count, same for s1
- move through s2, once >= all of s1, return true, else return false
- this is O(mn) time
*/
class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    vector<int> v1(26, 0);
    vector<int> v2(26, 0);
    int l = 0;

    for (auto &ch : s1)
      v1[ch - 'a']++;
    for (int r = 0; r < s2.size(); r++) {
      if (v1[s2[r] - 'a'] == 0) {
        // character is not even in s1
        while (l <= r) {
          v2[s2[l] - 'a']--;
          l++;
        }
      }

      v2[s2[r] - 'a']++;
      if (r - l + 1 == s1.size()) {
        bool found = true;
        for (int i = 0; i < 26; i++) {
          if (v1[i] != v2[i]) {
            found = false;
            break;
          }
        }
        if (found)
          return true;
        v2[s2[l] - 'a']--;
        l++;
      }
    }
    return false;
  }
};
