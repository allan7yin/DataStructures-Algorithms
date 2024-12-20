#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

/*
example 1:
t -> f
w -> e
r -> t
e -> r

// then topo sort this??
example 2:


*/
class Solution {
    string result;
    vector<unordered_set<char>> adj;
    vector<bool> visited;
    vector<bool> onPath;

  public:
    void f(char current) {

        for (auto &next : adj[current]) {
        }
    }
    string alienOrder(vector<string> &words) {
        // construct the adjacency list from this
        int n = words.size();
        adj = vector<unordered_set<char>>(26);
        vector<bool> exists(26, false);
        visited = vector<bool>(26, false);
        onPath = vector<bool>(26, false);

        for (const string &word : words) {
            for (char c : word) {
                exists[c - 'a'] = true;
            }
        }

        for (int i = 0; i < n - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];

            // compare the 2 consecutive words
            int length = min(s1.size(), s2.size());
            bool foundDifference = false;
            for (int j = 0; j < length; j++) {
                if (s1[j] != s2[j]) {
                    // means we have a new edge in the graph
                    int u = s1[j] - 'a';
                    int v = s2[j] - 'a';
                    adj[u].insert(v);
                    foundDifference = true;
                    break;
                }
            }

            if (!foundDifference && s1.size() != s2.size()) return "";
        }

        // now that the map is constructed, attempt to topo sort
        for (char i = 'a'; i <= 'z'; i++) {
            if (exists[i] && !visited[i]) {
                f(i);
                onPath.clear();
            }
        }
        return result;
    }
};
