#include <vector>
using namespace std;

/*
This is a DP question
•	0 - 0000 - 0
•	1 - 0001 - 1 + dp[n-1]
•	2 - 0010 - 1 + dp[n-2]
•	3 - 0011 - 1 + dp[n-2]

notice that for 4, we have a new 1 -> then the rest is the above repeated. This is the case for all powers of 2
so, to count the number of 1's in that, we check our solution in the subproblem, hence dp

•	4 - 0100 - 1 + dp[n-4]
•	5 - 0101 - 1 + dp[n-4]
•	6 - 0110 - 2
•	7 - 0111 - 3
•	8 - 1000 - 1 + dp[n-8]
*/
class Solution {
  public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        int m = 1;

        for (int i = 1; i <= n; i++) {
            if (m * 2 == i) m = i;
            dp[i] = 1 + dp[i - m];
        }
        return dp;
    }
};