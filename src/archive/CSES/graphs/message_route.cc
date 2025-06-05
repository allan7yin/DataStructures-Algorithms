#include "bits/stdc++.h"

using namespace std;

// Runtime -> O(V + E) -> we need to worst take traverse to every node and every edge
// so O(m + n)
// spacee complexity -> adjacenecy list: O(m + n) -> n entries O(n) and throughout the list, m edges so O(m) (technically 2m, but constants ignored in big o)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);

    // O(m)
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);
    vector<int> prev(n + 1, -1);

    queue<int> q;
    q.push(1);
    visited[1] = true;

    // loops through each node at most once -> due to the visited -> inner loop loops over all neighbours which  is at most number of all edges
    // so O(m + n)
    while (!q.empty()) {
        int front = q.front();
        q.pop();

        if (front == n) {
            break;
        }

        for (int next : adj[front]) {
            if (!visited[next]) {
                visited[next] = true; // important to do this inside, so that same node is not queue multiple times
                prev[next] = front;
                q.push(next);
            }
        }
    }

    if (prev[n] == -1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    vector<int> path;
    while (n != 1) {
        path.push_back(n);
        n = prev[n];
    }
    path.push_back(1);

    cout << path.size() << endl;
    reverse(path.begin(), path.end());
    for (int &stop : path) {
        cout << stop << " ";
    }
}