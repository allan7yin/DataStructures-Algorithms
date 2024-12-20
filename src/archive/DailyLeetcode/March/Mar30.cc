#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

/*
- Exactly K dstinct integer subarrays = Up to k distinct - Up to (k-1) distinct
- finding up to k is an O(n) operation

*/
class Solution {
public:
  int subarraysWithKDistinct(vector<int> &nums, int k) {
    return subarraysWithAtMostKDistinct(nums, k) - subarraysWithAtMostKDistinct(nums, k - 1);
  }

  int subarraysWithAtMostKDistinct(vector<int> &nums, int k) {
    unordered_map<int, int> myMap; // remove from map when count == 0;
    int count = 0;
    int l = 0;
    for (int r = 0; r < nums.size(); r++) {
      myMap[nums[r]]++;

      while (myMap.size() > k && l <= r) {
        if (--myMap[nums[l]] == 0) {
          myMap.erase(nums[l]);
        }
        l++;
      }
      count += (r - l + 1);
    }
    return count;
  }
};

int main() {
  Solution *sol = new Solution();
  vector<int> nums = {1, 2, 1, 2, 3};
  sol->subarraysWithKDistinct(nums, 2);
  delete sol;
}

/* TIME LIMIT EXCEEDED - O(n^2)
- Initial idea: using a set and checking its size to be k would work well
- window needs to be at least size of k
so:
- maintain window of size k
- then, move the right index as far right as possible, until we have > k distinct integers
- also need map to keep track of frequency to know if need to remove from map
*/

/*
class Solution {
public:
  int subarraysWithKDistinct(vector<int> &nums, int k) {
    // first, construct a k-sized window
    int l = 0;
    int count = 0;
    set<int> mySet;
    unordered_map<int, int> myMap;
    for (int i = 0; i < k - 1; i++) {
      mySet.insert(nums[i]);
      myMap[nums[i]]++;
    }

    // now, we have the first k-window, from index 0 to k-1. We now check -> if it has k distinct integers
    for (int r = k - 1; r < nums.size(); r++) {
      int rprev = r;
      mySet.insert(nums[r]);
      myMap[nums[r]]++;

      if (mySet.size() == k) {
        count++;
      }

      // keep a record of what we may need to remove from the set
      vector<int> debt;
      while (r < nums.size() - 1 && mySet.size() <= k) {
        r++;
        if (mySet.find(nums[r]) == mySet.end()) {
          // no in the set, add it
          debt.push_back(nums[r]);
          mySet.insert(nums[r]);
        }

        // check if == k, if yes, we count++
        if (mySet.size() == k) {
          count++;
        }
      }
      for (int j = 0; j < debt.size(); j++) {
        mySet.erase(debt[j]);
      }
      r = rprev;
      // inrcrement left pointer
      myMap[nums[l]]--;
      if (myMap[nums[l]] == 0) {
        mySet.erase(nums[l]);
      }
      l++;
    }
    return count;
  }
};

*/
