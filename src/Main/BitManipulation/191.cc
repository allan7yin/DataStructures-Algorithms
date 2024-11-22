/*
11 -> 1011 -> count nunmber of ones
      0001
    & 0001
so & with 1 -> tell us if last bit is 1 or not, then shift off for next iteration
*/
class Solution {
  public:
    int hammingWeight(int n) {
        int count = 0;
        int lb = 1;
        while (n != 0) {
            int l = n & 1;
            if (l == 1) {
                count++;
            }
            n = n >> 1;
        }
        return count;
    }
};