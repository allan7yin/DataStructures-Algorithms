#include "../bits/stdc++.h"

using namespace std;

/**
 * Things to note:
 *  - 1 <= m + n <= 2000
 *  - could choose a n^2 solution, and it would probably work
 *  - but the problem specifies the solution should:
 *      - The overall run time complexity should be O(log (m+n)).
 */
class Solution {
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if (n > m) return findMedianSortedArrays(nums2, nums1);

        // nums1 is the smaller array -> lets search for an index in nums1 that would be the cuttoff
        int middle = (n + m + 1) / 2;
        int l = 0, r = n;

        while (l < r) {
            middle = (n + m + 1) / 2;
            int i = l + (r - l) / 2;
            int j = middle - i - 1;

            // now that we have 2 splits -> ensure max of left < min of right --> combined for both partitions
            int left1_max = (i > 0) ? nums1[i - 1] : INT_MIN;
            int left2_max = (j > 0) ? nums2[j - 1] : INT_MIN;
            int right1_min = (i < n) ? nums1[i] : INT_MAX;
            int right2_min = (j < m) ? nums2[j] : INT_MAX;

            if (left1_max <= right2_min && left2_max <= right1_min) {
                // found solution
                if ((n + m) % 2 == 0) {
                    return (max(left1_max, left2_max) + min(right1_min, right2_min)) / 2.0;
                } else {
                    return max(left1_max, left2_max);
                }
            } else if (left1_max > right2_min) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }

        return -1;
    }
};