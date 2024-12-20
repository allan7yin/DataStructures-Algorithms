#include <unordered_set>
#include <vector>
using namespace std;

// something about checking if -1 element is in it, and ++
class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int result = 0;

        for (int &num : nums) {
            int copy = num;
            int l = 0;
            if (s.find(num + 1) == s.end()) {
                while (!s.empty() && s.find(copy) != s.end()) {
                    l++;
                    copy--;
                }
            }
            result = max(result, l);
        }
        return result;
    }
};