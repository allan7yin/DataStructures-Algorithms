#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        f(n, n, "", result);
        return result;
    }

    void f(int l, int r, string s, vector<string> &result) {
        if (l == 0 && r == 0) {
            result.push_back(s);
        }

        if (l > 0) {
            s.push_back('(');
            f(l - 1, r, s, result);
            s.pop_back();
        }

        if (r > 0 && l < r) {
            s.push_back(')');
            f(l, r - 1, s, result);
            s.pop_back();
        }
    }
};