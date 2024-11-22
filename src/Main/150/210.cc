#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
    unordered_map<int, vector<int>> mp;
    unordered_set<int> recStack;
    unordered_set<int> visited;
    bool cond = true;
    vector<int> order;

  public:
    void f(int curr) {
        if (recStack.count(curr)) {
            cond = false;
            return;
        }
        if (visited.count(curr)) return;

        visited.insert(curr);
        recStack.insert(curr);
        for (auto &neighbour : mp[curr]) {
            if (!cond) return; // Stop further processing if a cycle is detected
            f(neighbour);
        }
        order.push_back(curr);
        recStack.erase(curr);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        // construct the map
        for (auto &p : prerequisites) {
            mp[p[0]].push_back(p[1]);
        }

        for (int i = 0; i < numCourses; ++i) {
            f(i);
            recStack.clear();
        }
        return cond ? order : vector<int>{};
    }
};