#include <vector>
using namespace std;

class Solution {
public:
    int countVowelStrings(int n) {
        int result = 0;
        vector<vector<int>> dp(5, vector<int>(n+1, 0));
        // set everything to 1 for 'a'
        for (int i = 1; i < n+1; i++) {
            dp[0][i] = 1;
        }
        
        for (int i = 1; i < n+1; i++) {
            for (int j = 1; j < 5; j++) {
                dp[j][i] = dp[j-1][i] + dp[j][i-1];
            }
        }

        // then, find sum of all values in the last column 
        for (int i = 0; i < 5; i++) {
            result += dp[i][n];
        }
        return result;
    }
};
