class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int v = 0;

        // want the max value of te point f
        vector<int> maxL(n, 0);
        vector<int> maxR(n, 0);

        for (int i = 1; i < n; i++) {
            maxL[i] = max(maxL[i-1], height[i-1]);
        }

        for (int i = n - 2; i >= 0; i--) {
            maxR[i] = max(maxR[i+1], height[i+1]);
        }

        for (int i = 1; i < n - 1; i++) {
            v += max(0, min(maxL[i], maxR[i]) - height[i]);
        }

        return v;
    }
};