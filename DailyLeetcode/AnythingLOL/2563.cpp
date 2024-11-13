class Solution {
public:
  long long countFairPairs(vector<int> &nums, int lower, int upper) {
    long long result = 0;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
      int l = findLowerBound(nums, i + 1, n - 1, lower - nums[i]);
      int r = findUpperBound(nums, i + 1, n - 1, upper - nums[i]);

      if (l != -1 && r != -1 && l <= r) {
        result += (r - l + 1);
      }
    }
    return result;
  }

private:
  int findLowerBound(const vector<int> &nums, int left, int right, int target) {
    int result = -1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] >= target) {
        result = mid;
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return result;
  }

  int findUpperBound(const vector<int> &nums, int left, int right, int target) {
    int result = -1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] <= target) {
        result = mid;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return result;
  }
};
