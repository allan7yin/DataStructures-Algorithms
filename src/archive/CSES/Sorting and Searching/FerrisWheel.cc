#include <iostream>
#include <vector>
/*
https://cses.fi/problemset/task/1090
*/

using namespace std;

int minGondolaCount(vector<int> &children, int w) {
    int count = 0;
    sort(children.begin(), children.end());

    int l = 0, r = children.size() - 1;
    while (l <= r) {
        if (children[l] + children[r] <= w) {
            l++;
        }
        r--;
        count++;
    }
    return count;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> children(n);
    for (int i = 0; i < n; i++) {
        cin >> children[i];
    }

    cout << minGondolaCount(children, k) << endl;
}

/*
10 15
9 8 8 9 10 8 5 8 7 10

5 7
8
8
8
8
9
9
10
10


*/