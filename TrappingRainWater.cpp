#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;
        int l = 0, r = n - 1, maxLeft = height[0], maxRight = height[n-1];

        while (l < r) {
            if (maxLeft < maxRight) {
                l++;
                maxLeft = max(maxLeft, height[l]);
                water += (maxLeft - height[l]);
            } else {
                r--;
                maxRight = max(maxRight, height[r]);
                water += (maxRight - height[r]);
            }
        }
        return water;
    }
};

int main() {}