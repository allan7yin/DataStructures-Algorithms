#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    unordered_map<string, multiset<string>> adj;
    vector<string> result;

    void visit(const string &airport) {
        while (!adj[airport].empty()) {
            string next = *adj[airport].begin();
            adj[airport].erase(adj[airport].begin());
            visit(next);
        }
        result.push_back(airport);
    }

  public:
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        for (auto &ticket : tickets) {
            adj[ticket[0]].insert(ticket[1]);
        }

        visit("JFK");
        reverse(result.begin(), result.end());
        return result;
    }
};