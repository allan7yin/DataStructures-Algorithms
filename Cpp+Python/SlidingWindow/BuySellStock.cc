#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 0;
        int maxP = 0;

        while (r < prices.size()) {
            if (prices[r] > prices[l]) {
                maxP = max(maxP, prices[r] - prices[l]);
            } else {
                l = r;
            }
            r++;
        }
        return maxP;
    }
};

int main() {}