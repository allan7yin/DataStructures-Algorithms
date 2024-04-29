#include <algorithm>
#include <string>
using namespace std;

/*
 * We solve this problem with DFS. The idea is, the current character we are on
 * has 3 choices: be in subsequence 1, subsequence 2, or neither. If any of the
 * if 
 *
 *
 *
 */
class Solution {
public:
  int maxProd = 0;
  bool isPalindrome(string &s) {
    int l = 0, r = s.size() - 1;
    while (l <= r) {
      if (s[l] != s[r]) {
        return false;
      }
      l++;
      r--;
    }
    return true;
  }
  int maxProduct(string s) {
    string s1 = "";
    string s2 = "";
    dfs(s, s1, s2, 0);

    return maxProd;
  }

  void dfs(string &s, string &s1, string &s2, int index) {
    bool cond = false;
    if (index == s.size()) {
        cond = true;
    }

    if (isPalindrome(s1) && isPalindrome(s2)) {
        int prod = s1.size() * s2.size();
        maxProd = max(maxProd, prod);
    }

    if (!cond) {
        s1.push_back(s[index]);
        dfs(s, s1, s2, index + 1);
        s1.pop_back();

        s2.push_back(s[index]);
        dfs(s, s1, s2, index + 1);
        s2.pop_back();

        dfs(s, s1, s2, index + 1);
    }
  }
};
