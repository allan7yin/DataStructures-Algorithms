#include <vector>

using namespace std;

class Solution {
public:
  double minimumAverage(vector<int> &nums) {
    vector<double> averages;
    double minAvg = INT_MAX;
    sort(nums.begin(), nums.end());
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      double avg = (nums[l] + nums[r]) / 2;
      averages.push_back(avg);
      minAvg = min(minAvg, avg);
    }
    return minAvg;
  }
};
