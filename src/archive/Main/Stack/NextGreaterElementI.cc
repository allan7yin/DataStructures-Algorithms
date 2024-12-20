#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // first create a hashmap from number to index for num2
        vector<int> result(nums1.size(), -1);
        unordered_map<int, int> hmap;
        for (int i = 0; i < nums2.size(); i++) {
            hmap[nums2[i]] = i;
        }

        for (int i = 0; i < nums1.size(); i++) {
            for (int j = hmap[nums1[i]] + 1; j < nums2.size(); j++) {
                if (nums2[j] > nums1[i]) {
                    result[i] = nums2[j];
                    break;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    sol.nextGreaterElement(nums1, nums2);
}