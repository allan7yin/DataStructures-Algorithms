#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
 * We solve this with DFS, which we will run on every course, checking if that
 * can result in us finishing everything or not 
 *
 * We will maintain a set of visited courses/nodes, and pop them when backtracking
 *
 * In a way, this shares something common with memoization. That is, when we make 
 * the course's prereq's an empty vector once verifying that we can successfully 
 * reach all prereqs from current course, we can return early the next time we reach
 * this node in dfs path of a ancestor nodei
 *
 * the next problem is course II, which we need to return order of courses.
 */
class Solution {
    unordered_map<int, vector<int>> prereqMap;
    unordered_set<int> visited;
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // First, we need to populate the map 
    for (auto &kv: prerequisites) {
      prereqMap[kv[0]].push_back(kv[1]);
    }

     // now return result of dfs
     for (int i = 0; i < numCourses; i++) {
       if (!dfs(i)) {
         return false;
       }
     }
     return true;
   }

   bool dfs(int course) {
     if (visited.find(course) != visited.end()) {
       // means we have visited, cycle detected, we can never finish this 
       return false;
     }

     // otherwise, we dfs onto all of the prerequite courses 
     if (prereqMap[course].size() == 0) {
       return true;
     }

     visited.insert(course);
     for (int &prereq: prereqMap[course]) {
       // dfs onto each 
       if (!dfs(prereq)) {
         return false;
       }
     }

     prereqMap[course].clear();
     visited.erase(course);
     return true;
   }
};







