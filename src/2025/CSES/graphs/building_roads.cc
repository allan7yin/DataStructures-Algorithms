#include "bits/stdc++.h"

using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> size;

    // O(n)
    void init(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Each find operation takes O(\alpha(n)) -> so worst case is O(n * alpha(n))
    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (size[x] < size[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        return true;
    }
};

// just union-find algorithm
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    DSU dsu;
    // O(n)
    dsu.init(n + 1);

    // O(m * alpha(n)) -> alpha(n) can be treated as a small constant ~4, 5 -> so effectively O(m)
    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        dsu.unite(start, end);
    }

    vector<int> component_parents;
    for (int i = 1; i <= n; i++) {
        if (dsu.find(i) == i) {
            component_parents.push_back(i);
        }
    }

    cout << component_parents.size() - 1 << "\n";
    for (int i = 1; i < component_parents.size(); i++) {
        cout << component_parents[i - 1] << " " << component_parents[i] << "\n";
    }

    return 0;

    // final runtime -> O(n) + O(m)
}