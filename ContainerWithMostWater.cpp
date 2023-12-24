#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int maxVolume = 0;
        while (l < r) {
            maxVolume = max(maxVolume, (r-l)*min(height[l],height[r]));
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return maxVolume;
    }
};

int main() {}