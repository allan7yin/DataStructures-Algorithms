#include <vector>

using namespace std;
/*
    - Instead of stack, can solve this with divide and conquer 
*/
/*
    - Instead of stack, can solve this with divide and conquer 
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        return dnc(heights, 0, heights.size()-1);
    }

    int dnc(vector<int> &heights, int start, int end) {
        if (start == end) {
            return heights[start];
        }

        int mid = (end+start)/2;
        int maxL = dnc(heights, start, mid);
        int maxR = dnc(heights, mid+1, end);
        int minHeight = heights[mid];
        int maxTempArea = minHeight;

        // max Area is either the one in the left half, one in the right half, or one spanning both
        int i = mid, j = mid + 1;
        while (i >= start && j <= end) {
            minHeight = min(min(heights[i], heights[j]), minHeight);
            maxTempArea = max(maxTempArea, (j-i+1)*minHeight);
            if (i == start) {
                j++;
            } else if (j == end) {
                i--;
            } else if (heights[j+1] > heights[i-1]){
                j++;
            } else {
                i--;
            }
        }

        return max(max(maxL, maxR), maxTempArea);
    }
};
int main() {
    Solution sol;
    vector<int> heights= {2,1,5,6,2,3};
    vector<int> h1 = {4,2,0,3,2,4,3,4};
    sol.largestRectangleArea(h1);
}