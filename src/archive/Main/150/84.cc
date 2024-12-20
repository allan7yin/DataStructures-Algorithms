#include <stack>
#include <utility>
#include <vector>

using namespace std;

class Solution {
  public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        stack<pair<int, int>> st; // first = idx, second = height
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            int start = i;
            while (!st.empty() && heights[i] < st.top().second) {
                start = st.top().first;
                int h = st.top().second;
                maxArea = max(maxArea, h * (i - start));
                st.pop();
            }

            // now push_back
            st.push(make_pair(start, heights[i]));
        }

        while (!st.empty()) {
            // do the same as the above
            int h = st.top().second;
            int start = st.top().first;
            maxArea = max(maxArea, h * (n - start));
            st.pop();
        }
        return maxArea;
    }
};