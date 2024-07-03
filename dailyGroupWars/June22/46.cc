#include <algorithm>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> visited(nums.size(), false);
    recurse(nums, visited, current, result);
    return result;
  }

private:
  void recurse(vector<int> &nums, vector<bool> &visited, vector<int> &current,
               vector<vector<int>> &result) {
    if (current.size() == nums.size()) {
      result.push_back(current);
      return;
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (!visited[i]) {
        visited[i] = true;
        current.push_back(nums[i]);
        recurse(nums, visited, current, result);
        current.pop_back();
        visited[i] = false;
      }
    }
  }
};
