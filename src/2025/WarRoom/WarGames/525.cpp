#include "../bits/stdc++.h"

using namespace std;

/**
 * Here's how we'll treat this --> we will convert every 0 to a -1 in here
 *  - with this, we are accumulating the sun, and if there is a subarray with a sum, we record its index
 *
 * EXAMPLE: [0,1,1,1,1,1,0,0,0]
 * Post transformation: [-1,1,1,1,1,1,-1,-1,-1]   -> 8 has sum 1, -1 has index 0, -> 8 - 2 + 1
 */
class Solution {
  public:
    int findMaxLength(vector<int> &nums) {
        int result = 0;
        for (int &num : nums) {
            if (num == 0) num = -1;
        }

        unordered_map<int, int> prefix;
        prefix[0] = -1;

        int movingSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            movingSum += nums[i];
            int target = movingSum;
            if (prefix.find(target) != prefix.end()) {
                result = max(result, i - prefix[target]);
            }

            // add this prefix -> index into the map, if it does not exist
            if (prefix.find(movingSum) == prefix.end()) {
                prefix[movingSum] = i;
            }
        }

        return result;
    }
};

// [0,1,0]
// -1, 1, -1