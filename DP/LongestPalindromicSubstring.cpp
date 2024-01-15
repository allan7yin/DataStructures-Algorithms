#include <string>
#include <vector>
using namespace std;
/*
    - Maintain 2D Table of booleans 
    - i row x j col is boolean value -> whether or not substring from i to j is palindrome 
*/
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 1) {
            return s;
        }
        int maxLength = 0;
        int start = 0;
        int end = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        
        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = true;
            for (int j = 0; j < i; j++) {
                if (s[i] == s[j] && (i-j <= 2 || dp[j+1][i-1])) {
                    dp[j][i] = true;
                    if (i-j+1 > maxLength) {
                        maxLength = i-j+1;
                        start = j;
                        end = i;
                    }
                }
            }
        }
        return s.substr(start, end-start+1);
    }
};

int main() {}
