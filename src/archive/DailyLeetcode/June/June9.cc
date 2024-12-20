#include <unordered_map>
#include <vector>

using namespace std;


/*
 * This is very similar to yesterdays problem, about how the difference of 2 arrays 
 * of the same mod k value, will mod k = 0
 *
 */ 

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mod_k;
        mod_k[0] = 1;
        
        int result = 0;
        int prefix = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            prefix %= k;
           
            // we want remainder from [0,k], so if negative, we add k to the prefix
            if (prefix < 0) {
                prefix += k;
            }
            
            if (mod_k.count(prefix)) {
                result += mod_k[prefix];
                mod_k[prefix]++;
            } else {
                mod_k[prefix] = 1;
            }
        }
        return result;
    }
};

