#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> s;
        for (auto &num : nums) {
            if (s.count(num) > 0) return true;
            s.insert(num);
        }
        return false;
    }
};