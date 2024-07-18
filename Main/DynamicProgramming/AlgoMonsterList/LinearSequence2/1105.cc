#include <vector>
using namespace std;

/*
We build this solution top-down
*/

int dp[1000];

class Solution {
  public:
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth) {
        memset(dp, -1, sizeof(dp));
        return f(0, books, shelfWidth);
    }

    int f(int i, vector<vector<int>> &books, int w) {
        if (dp[i] != -1) return dp[i];
        if (i >= books.size()) return 0;

        dp[i] = INT_MAX;
        int minh = 0;
        int ws = 0;
        for (int j = i; j < books.size(); j++) {
            ws += books[j][0];
            if (ws > w) break;
            minh = max(minh, books[j][1]);
            dp[i] = min(dp[i], minh + f(j + 1, books, w));
        }
        return dp[i];
    }

  private:
    int minHeightShelvesNaive(vector<vector<int>> &books, int shelfWidth) {
        return fnaive(0, books, shelfWidth);
    }

    int fnaive(int i, vector<vector<int>> &books, int w) {
        if (i >= books.size()) return 0;

        int mins = 1000;
        int minh = 0;
        int ws = 0;
        for (int j = i; j < books.size(); j++) {
            ws += books[j][0];
            if (ws > w) break;
            minh = max(minh, books[j][1]);
            mins = min(mins, minh + fnaive(j + 1, books, w));
        }
        return mins;
    }
};