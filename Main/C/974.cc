#include <unordered_map>
#include <vector>
using namespace std;

/*
This seems like a prefix question
we can use a psa to compute


!!! important to remeber: a mod p = k, b mod p = k, a +- b mod p = 0;
*/
class Solution {
public:
  int subarraysDivByK(vector<int> &nums, int k) {
    int n = nums.size();
    int count = 0;
    unordered_map<int, int> mp; // remainder to count
    // construct the psa, and instead of making this a vector, we build this as
    // we go we know instead of checking psa[i] - psa[j] % k == 0, we store the
    // count of this remainder in a hashmap. So, if there is some value p, such
    // that psa[i] % k == p % k, then psa[i] + p %k == 0, increment count
    mp[0] = 1;
    int psa = 0;
    for (int i = 0; i < n; i++) {
      psa += nums[i];
      while (psa < 0)
        psa += k;
      int m = psa % k;
      if (mp.find(m) != mp.end())
        count += mp[m];
      mp[m]++;
    }
    return count;
  }
};

// [4,5,0,-2,-3,1]
// [0, 4, 9, 9, 7, 4, 5] psa
// 1, 2, 0, 3, 0
