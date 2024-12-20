#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> d(nums.begin(), nums.end());
        int maxlength = 0;

        for (int &num : nums) {
            if (!d.empty() && d.find(num + 1) == d.end()) {
                int temp = 0;
                while (d.find(num) != d.end()) {
                    temp++;
                    num--;
                }
                maxlength = max(maxlength, temp);
            }
        }
        return maxlength;
    }
};