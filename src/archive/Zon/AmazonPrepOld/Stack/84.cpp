#include <utility>
#include <vector>
using namespace std;

/*
Time Complexity:
- O(n) -> going throught the vector, we do 2 total loops
- Each item is pushed once, and popped once -> 2 * O(n) -> O(n)

Space Complexity:
- O(n) -> just a vector of pairs, stack is at most O(n)
*/
class Solution {
  public:
    int largestRectangleArea(vector<int> &heights) {
        vector<pair<int, int>> st;
        int n = heights.size();
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
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

        while (!st.empty()) {
            int h = st.back().second;
            int start = st.back().first;
            maxArea = max(maxArea, h * (n - start));
            st.pop_back();
        }

        return maxArea;
    }
};