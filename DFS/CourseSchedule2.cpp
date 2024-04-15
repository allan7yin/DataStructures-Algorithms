#include <filesystem>
#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
  unordered_set<int> visited;
  unordered_set<int> added;
  unordered_map<int, vector<int>> prereqs;
  vector<int> result;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      // lets first populate the prerequisites map 
      for (auto &kv:prerequisites) {
        prereqs[kv[0]].push_back(kv[1]);
      }

      // now dfs
      for (int i = 0; i < numCourses; i++) {
        if (!dfs(i)) {
          return {};
        }
      }

      return result;
    }

    bool dfs(int course) {
      if (visited.find(course) != visited.end()) {
        // cycle detected, retur false
        return false;
      }

      if (added.find(course) != added.end()) {
        // means we've beem here, don't add it to result vector again
        return true;
      }

      visited.insert(course);
      // dfs into all prereqs
      for (int &dependency: prereqs[course]) {
        if (!dfs(dependency)) {
          return false;
        }
      }
      visited.erase(course);
      added.insert(course);
      result.push_back(course);
      return true;
    }
};
