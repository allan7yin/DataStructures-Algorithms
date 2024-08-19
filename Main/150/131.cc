#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<string>> result;

    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l <= r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<string> sum;
        f(s, sum, 0);
        return result;
    }

    void f(string s, vector<string> sum, int i) {
        if (i >= s.size()) {
            result.push_back(sum);
            return;
        }

        for (int j = i; j < s.size(); j++) {
            if (isPalindrome(s.substr(i, j - i + 1))) {
                sum.push_back(s.substr(i, j - i + 1));
                f(s, sum, j + 1);
                sum.pop_back();
            }
        }
    }
};