#include <vector>

using namespace std;
class Solution {
public:
  void reverseString(vector<char> &s) {
    // maintain 2 pointers and move inwards
    int l = 0, r = s.size() - 1;
    char temp = ' ';
    while (l <= r) {
      temp = s[l];
      s[l] = s[r];
      s[r] = temp;
      l++;
      r--;
    }
  }
};
