#include <vector>

using namespace std;

class Solution {
  public:
    // first iterate through this and make "max-right" array for each index
    // then, iterate pointer left to right, where the water at each place is min(maxHeightR, maxHeightL) - currentHeight
    int trap(vector<int> &height) {
        int n = height.size();
        int waterTrapped = 0;
        vector<int> maxR(n, -1);
        maxR[n - 1] = height[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            maxR[i] = max(height[i], maxR[i + 1]);
        }

        // now, iterate left to right
        int maxL = -1;
        for (int i = 0; i < n; i++) {
            maxL = max(maxL, height[i]);
            waterTrapped += (min(maxL, maxR[i]) - height[i]);
        }

        return waterTrapped;
    }
};

// guess i was right