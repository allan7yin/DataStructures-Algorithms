#include "../bits/stdc++.h"
using namespace std;

/*
This is linear time solution, 2 * 10 ^ 4 -> need between o(n) and o(nlogn)
*/

class Solution {
  public:
    int trap(vector<int> &height) {
        int result = 0;
        vector<int> maxR(height.size());
        vector<int> maxL(height.size());

        for (int i = 0; i < height.size(); i++) {
            if (i == 0) {
                maxL[i] = height[i];
            } else {
                maxL[i] = max(maxL[i - 1], height[i - 1]);
            }
        }

        for (int i = height.size() - 1; i >= 0; i--) {
            if (i == height.size() - 1) {
                maxR[i] = height[i];
            } else {
                maxR[i] = max(maxR[i + 1], height[i + 1]);
            }
        }

        for (int i = 0; i < height.size(); i++) {
            result += max(0, min(maxL[i], maxR[i]) - height[i]);
        }

        return result;
    }
};