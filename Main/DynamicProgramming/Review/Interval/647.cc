#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int countSubstrings(string s) {
    int n = s.size();
    int count = 0;
    vector<vector<bool>> m(n, vector<bool>(n, false));

    // Single characters are palindromic
    for (int i = 0; i < n; i++) {
      m[i][i] = true;
      count++;
    }

    // Check for palindromes of length 2
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == s[i + 1]) {
        m[i][i + 1] = true;
        count++;
      }
    }

    // Check for palindromes of length greater than 2
    for (int len = 3; len <= n; len++) {
      for (int i = 0; i <= n - len; i++) {
        int j = i + len - 1;
        if (s[i] == s[j] && m[i + 1][j - 1]) {
          m[i][j] = true;
          count++;
        }
      }
    }

    return count;
  }
};