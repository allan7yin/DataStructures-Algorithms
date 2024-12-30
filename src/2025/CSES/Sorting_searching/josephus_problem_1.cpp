#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// runtime is O(2n)
// first time we go through queue -> N operations
// next time is N/2, then N/4, ...
// so N + N/2 + N/4 + ... + 1 -> N(1 * 1/2 * 1/4 + ...) -> geometric series, which sums to (a / 1-r) -> a / 1 - (1/2) = 2
// so 2n
int main() {
    int n;

    cin >> n;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    bool skip = true;
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        if (!skip) {
            cout << front << " ";
        } else {
            q.push(front);
        }
        skip = !skip;
    }
}