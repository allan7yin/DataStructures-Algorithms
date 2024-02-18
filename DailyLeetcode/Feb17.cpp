#include <vector>
#include <queue>

using namespace std;
/*
    - We can solve this with DP -> slower than maxHeap approach 
    - we can solve this with maxHeap
*/
class Solution {
public:
    int furthestBuilding1(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> maxHeap;
        int result = 0;
        int n = heights.size();
        for (int i = 1; i < n; i++) {
            if (heights[i] > heights[i-1]) {
                int diff = heights[i] - heights[i-1];
                maxHeap.push(diff);
                bricks -= diff;
                if (bricks < 0) {
                    ladders -= 1;
                    bricks += maxHeap.top();
                    maxHeap.pop();
                }
                if (ladders < 0) {
                    result = i - 1;
                    break;
                }
            }
            result = i;
        }
        return result;
    }

    int furthestBuilding2(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> maxHeap;
        int result = 0;
        int n = heights.size();
        for (int i = 1; i < n; i++) {
            if (heights[i] > heights[i-1]) {
                int diff = heights[i] - heights[i-1];
                maxHeap.push(diff);
                bricks -= diff;
                if (bricks < 0) {
                    ladders -= 1;
                    bricks += maxHeap.top();
                    maxHeap.pop();
                }
                if (ladders < 0) {
                    result = i - 1;
                    break;
                }
            }
            result = i;
        }
        return result;
    }
};