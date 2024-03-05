#include <string>
using namespace std;

class Solution {
public:
  int minimumLength(string s) {
    int l = 0, r = s.size() - 1;

    while (l < r) {
      if (s[l] != s[r]) {
        return (r - l + 1);
      }

      char val = s[r];
      while (l <= r && s[l] == val) {
        l++;
      }
      while (r >= l && s[r] == val) {
        r--;
      }
    }
    if (l > r) {
      return 0;
    } else {
      return 1;
    }
  }
};
