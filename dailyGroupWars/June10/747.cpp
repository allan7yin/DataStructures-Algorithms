class Solution {
public:
  int dominantIndex(vector<int> &nums) {
    int maxVal = 0;
    int maxIndex = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > maxVal) {
        maxVal = nums[i];
        maxIndex = i;
      }
    }

    for (int i = 0; i < nums.size(); i++) {
      if (i == maxIndex) {
        continue;
      }
      if (maxVal < 2 * nums[i]) {
        return -1;
      }
    }
    return maxIndex;
  }
};