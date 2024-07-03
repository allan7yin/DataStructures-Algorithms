#include <string>
using namespace std;

class Solution {
public:
  int lengthOfLastWord(string s) {
    // trim ending zeros
    int lastIndex = s.size();
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] != 32) {
        lastIndex = i + 1;
        break;
      }
    }
    int count = 0;
    for (int i = 0; i < lastIndex; i++) {
      if (s[i] == 32) {
        count = 0;
      } else {
        count++;
      }
    }
    return count;
  }
};