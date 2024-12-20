#include <vector>
using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> results;
    f(n, n, "", results);
    return results;
  }

  void f(int l, int r, string result, vector<string> &results) {
    if (l == 0 && r == 0) {
      results.push_back(result);
      return;
    }

    if (l > 0) {
      result.push_back('(');
      f(l - 1, r, result, results);
      result.pop_back();
    }

    if (r > 0 && l < r) {
      result.push_back(')');
      f(l, r - 1, result, results);
      result.pop_back();
    }
  }
};
