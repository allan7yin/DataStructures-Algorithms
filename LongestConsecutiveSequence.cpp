#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mySet(nums.begin(), nums.end());
        int maxLength = 0;
        int length = 1;
        for (int &num : nums) {
            int copy = num;
            if (mySet.count(num + 1) <= 0) {
               while (mySet.count(copy - 1) > 0) {
                   length += 1;
                   copy -= 1;
               }
               maxLength = max(length,maxLength);
               length = 1;
            }
        }
        return maxLength;
    }
};

int main() {}