#include <vector>
using namespace std;

/*
Time spent: 10-15 min -> get this down to under 10
*/
class Solution {
  public:
    int trap(vector<int> &height) {
        int volume = 0;
        int n = height.size();
        vector<int> maxL(n, 0);
        vector<int> maxR(n, 0);

        for (int i = 0; i < n; i++) {
            if (i == 0) continue;
            maxL[i] = max(maxL[i - 1], height[i - 1]);
        }

        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) continue;
            maxR[i] = max(maxR[i + 1], height[i + 1]);
        }

        for (int i = 0; i < n; i++) {
            int h = min(maxL[i], maxR[i]);
            volume += max(0, h - height[i]);
        }
        return volume;
    }
};