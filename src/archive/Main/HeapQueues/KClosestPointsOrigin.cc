#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>> pq;
        // insert everything in
        for (auto &xy:points) {
            double distance = sqrt(pow(xy[0], 2) + pow(xy[1], 2));
            pq.push({-distance, xy});
        }

        // want k most closest 
        vector<vector<int>> result;
        for (int i = 0; i < k; i++) {
          result.push_back(pq.top().second);
          pq.pop();
        }

        return result;
    }
};
