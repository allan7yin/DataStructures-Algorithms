#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(0,0,n,"",ans);
        return ans;
    }

    void backtrack(int lcount, int rcount, int n, string result, vector<string> &ans) {
        if (lcount == rcount && lcount == n) {
            ans.push_back(result);
            return;
        }

        if (lcount < n) {
            result += "(";
            backtrack(lcount + 1, rcount, n, result, ans);
            result.pop_back();
        }

        if (rcount < lcount) {
            result += ")";
            backtrack(lcount, rcount + 1, n, result, ans);
            result.pop_back();
        }
    }
};

int main() {}