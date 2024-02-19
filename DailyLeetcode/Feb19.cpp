/*
https://leetcode.com/problems/power-of-two/description/
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 1) {
            return true;
        } else if (n < 1) {
            return false;
        }

        bool condition = false;
        int r = n % 2;
        if (r != 0) {
            condition = false;
        } else {
            condition = isPowerOfTwo(n/2);
        }

        return condition;
    }
};