#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    // iterate through it, constructing a mapping
    unordered_map<char, char> st;
    unordered_map<char, char> ts;
    if (s.size() != t.size()) {
      return false;
    }

    bool cond = true;
    for (int i = 0; i < s.size(); i++) {
      if (st.find(s[i]) != st.end()) {
        if (st[s[i]] != t[i]) {
          cond = false;
          break;
        }
      } else if (ts.find(t[i]) != ts.end()) {
        if (ts[t[i]] != s[i]) {
          cond = false;
          break;
        }
      } else {
        st[s[i]] = t[i];
        ts[t[i]] = s[i];
      }
    }
    return cond;
  }
};