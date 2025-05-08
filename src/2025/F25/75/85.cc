#include "../bits/stdc++.h"
using namespace std;

class Solution {
  public:
    int largestRectangleArea(vector<int> &heights) {
        int maxArea = 0;
        vector<pair<int, int>> st;

        for (int i = 0; i < heights.size(); i++) {
            int start = i;
            while (!st.empty() && heights[i] < st.back().second) {
                start = st.back().first;
                int h = st.back().second;
                int area = h * (i - start);
                maxArea = max(maxArea, area);
                st.pop_back();
            }

            st.push_back({start, heights[i]});
        }

        // now here, we may have monotonically increasing stack
        while (!st.empty()) {
            int start = st.back().first;
            int h = st.back().second;
            int area = h * (heights.size() - start);
            maxArea = max(maxArea, area);
            st.pop_back();
        }

        return maxArea;
    }
};