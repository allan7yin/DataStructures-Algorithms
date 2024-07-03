#include <string>

using namespace std;

class Solution {
public:
  int appendCharacters(string s, string t) {
    int count = t.size();
    int t_index = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == t[t_index]) {
        t_index++;
        count--;
      }
    }
    return count;
  }
};