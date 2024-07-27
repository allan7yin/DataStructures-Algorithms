#include <vector>
using namespace std;

class Solution {
  public:
    long long minSum(vector<int> &nums1, vector<int> &nums2) {
        long sum1 = 0, sum2 = 0;
        int count1 = 0, count2 = 0;

        for (int &num : nums1) {
            if (num == 0)
                count1++;
            sum1 += num;
        }

        for (int &num : nums2) {
            if (num == 0)
                count2++;
            sum2 += num;
        }

        // just enumerate all the possible outcomes
        if (count1 == 0 && count2 == 0)
            return (sum1 == sum2) ? sum1 : -1;
        if (count1 == 0)
            return (sum1 >= sum2 + count2) ? sum1 : -1;
        if (count2 == 0)
            return (sum2 >= sum1 + count1) ? sum2 : -1;
        return max(sum1 + count1, sum2 + count2);
    }
};

// [3,2,0,1,0] -> 6
// [6,5,0] -> 11

// [3,2,0,1,0]
// [6,5,0]
