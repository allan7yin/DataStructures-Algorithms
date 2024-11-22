class Solution {
public:
  int minimizedMaximum(int n, vector<int> &quantities) {
    int l = 1;
    int r = 0;
    for (int &num : quantities) {
      r = max(r, num);
    }

    int result = -1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      int sum = 0;
      for (int &num : quantities) {
        sum += (int)ceil((float(num) / m));
      }

      if (sum <= n) {
        result = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return result;
  }
};
