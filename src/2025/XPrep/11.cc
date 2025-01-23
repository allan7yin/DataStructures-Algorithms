#include "bits/stdc++.h";

using namespace std;

class Solution {
  public:
    int maxArea(vector<int> &height) {
        int a = 0;
        int n = height.size();
        int l = 0, r = n - 1;

        while (l < r) {
            a = max(a, (r - l) * min(height[l], height[r]));
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }

        return a;
    }
};