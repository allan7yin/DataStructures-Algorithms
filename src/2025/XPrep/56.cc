class Solution {
public:
    // time complexity -> nlogn from sort
    // space -> O(n)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) return intervals;

        int n = intervals.size();
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        int minL = intervals[0][0], minR = intervals[0][1];

        for (int i = 1; i < n; i++) {
            auto interval = intervals[i];
            if (interval[0] <= minR && interval[0] >= minL) {
                // same interval
                minL = min(minL, interval[0]);
                minR = max(minR, interval[1]);
            } else {
                result.push_back({minL, minR});
                minL = interval[0];
                minR = interval[1];
            }
            if (i == n - 1) {
                result.push_back({minL, minR});
            }
        }

        return result;
    }
};


// [[1,3],[2,6],[8,10],[15,18]]
// [1,6], [8,10]