#include <queue>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        // this is a simple min heap question
        vector<vector<int>> result;
        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, greater<pair<double, vector<int>>>> mh;
        for (auto &point : points) {
            int ed = euclid_dist(point);
            mh.push({ed, point});
        }

        while (k > 0) {
            auto top = mh.top();
            result.push_back(top.second);
            mh.pop();
            k--;
        }
        return result;
    }

    double euclid_dist(vector<int> &a) {
        return sqrt(a[0] * a[0] + a[1] * a[1]);
    }
};