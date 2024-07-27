#include <string>
#include <unordered_map>
using namespace std;

// dsu -> disjoint set union
class Solution {
public:
  unordered_map<char, char>
      mp; // maps each node to parent -> have groups of node have same parent,
          // same = char but smallest
  char findParent(char cur) {
    if (mp.find(cur) == mp.end() || mp[cur] == cur) {
      return cur;
    }
    mp[cur] = findParent(mp[cur]);
    return mp[cur];
  }
  string smallestEquivalentString(string s1, string s2, string baseStr) {
    int m = s1.size();
    string result = "";
    for (int i = 0; i < m; i++) {
      char a = s1[i];
      char b = s2[i];

      if (a != b) {
        a = findParent(a);
        b = findParent(b);
        if (a < b) {
          mp[b] = a;
        } else {
          mp[a] = b;
        }
      }
    }
    for (char &ch : baseStr) {
      result += findParent(ch);
    }
    return result;
  }
};
