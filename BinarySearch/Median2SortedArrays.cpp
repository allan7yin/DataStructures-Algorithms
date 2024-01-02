#include <vector>

using namespace std;
/*
    - cannot simply join and do binary search, joining would be O(m) or O(n)
    - the idea is to build the first half of the combined array  
    - use binary search to look for this cuttof in the smaller sized array (doesn't really matter)
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // binary search nums1
        int l = 0, r = nums1.size() - 1;
        int total_size = nums1.size() + nums2.size();
        int half_size = total_size/2;
        double result = 0;

        while (l <= r) {
            int mid = l + (l-r)/2; // cutoff in nums1
            int cor_mid = half_size - 2 - mid; // cutoff in nums2
            int nums1_next = (mid + 1 < nums1.size()) ? nums1[mid+1] : INT_MAX;
            int nums2_next = (cor_mid + 1 < nums2.size()) ? nums2[cor_mid + 1] : INT_MAX;

            if ((nums1[mid] <= nums2_next) && (nums2[cor_mid] <= nums1_next)) {
                // check condition, if valid, return median 
                if (total_size % 2) {
                    result = (double) min(nums1_next, nums2_next);
                } else {
                    result = (max(nums1[mid], nums2[cor_mid]) + min(nums1_next, nums2_next)) / 2.0;
                }
                break;
            } else {
                // decide which direction to move mid for nums1 (opp for nums2)
                if (nums1[mid] > nums2[nums2_next]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        return result;
    }
};

int main () {}