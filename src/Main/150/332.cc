#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

/*
- we construct the graph, then keep adding the members adjacent nodes to current node.
- once a node has been added, we remove that arc from the graph, and continue

Something important to note: a flight from a to b can have mutliple tickets -> so we need to return to a before we can go back to b when
using the second ticket
*/
class Solution {
    unordered_map<string, multiset<string>> adj;
    vector<string> result;

  public:
    void f(string current) {
        while (!adj[current].empty()) { // do it this way since removing elements while iterating is dangerous
            string next = *adj[current].begin();
            adj[current].erase(adj[current].begin());
            f(next);
        }
        result.push_back(current);
    }
    vector<string> findItinerary(vector<vector<string>> &tickets) {

        // fill this map in
        for (auto &ticket : tickets) {
            adj[ticket[0]].insert(ticket[1]);
        }

        // call this on starting city JFK
        f("JFK");
        reverse(result.begin(), result.end());
        return result;
    }
};