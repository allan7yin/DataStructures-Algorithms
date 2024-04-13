#include <vector>
using namespace std;

/*
 * This problem, we can solve with Greedy Solution
 * 
 *
 * To see how, consider this sample problem:
 * - we have nums = [1,5,10] and n = 20
 * - miss is variable that represents the next number we need to ensure we 
 *   have numbers that can sum to namespace  
 * - For `nums` above, miss = 1 in the beginning. But we have one, so we now 
 *   need miss += nums[i] = 2. So, we move onto next i 
 * - So, is 5 == 2? No, so currently, we can't create a sum of 2, so we need
 *   to patch it. After patching it, the next thing we need is a 1 + 2 = 3, so 
 *   4, which just so happens to be miss + miss. We also increment counter for this
  
 };
  
 };
*/
class Solution {
public:
int minPatches(vector<int>& nums, int n) {
    int numPatches = 0;
    int miss = 1;
    int i = 0;

    while (miss <= n) {
        if (i < nums.size() && nums[i] <= miss) {
            miss += nums[i++];
        } else {
            // insert one here 
            miss += miss;
            numPatches++;
        }
    }
    return numPatches;
  } 
};
