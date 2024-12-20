// some kind of binary search?

class Solution {
  public:
    int findKthPositive(vector<int> &arr, int k) {
        // we realize that if every thing was there, val - index = 1
        // [2,3,4,7,11] -> 11 - 4 = 7 -> 6 numbers missing up to 11
        int l = 0, r = arr.size();
        while (l < r) {
            int m = (l + r) / 2;
            if (arr[m] - m - 1 < k) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l + k;
    }
};