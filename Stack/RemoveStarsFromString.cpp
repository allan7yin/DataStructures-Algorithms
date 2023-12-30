#include <string>

using namespace std;

class Solution {
public:
    string removeStars(string s) {
        string st = "";
        int i = 0;
        while (i < s.size()) {
            if (s[i] != '*') {
                st += s[i];
            } else {
                st.pop_back();
            }
            i++;
        }
        return st;
    }
};

int main() {
    Solution sol;
    string s = "leet**cod*e";
    sol.removeStars(s);
}
