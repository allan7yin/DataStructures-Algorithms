#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // iterate forward direction, then iterate in the backward direction 
        int n = nums.size();
        vector<int> prods(n,1);

        int forward = 1;
        for (int i = 1; i < n; i++) {
            forward *= nums[i-1];
            prods[i] *= forward;
        }

        int backward = 1;
        for (int i = n-2; i >= 0; i--) {
            backward *= nums[i+1];
            prods[i] *= backward;
        }

        return prods;
    }
};

int main() {}