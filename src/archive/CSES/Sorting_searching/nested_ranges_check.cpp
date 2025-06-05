#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> ranges(n);

    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        ranges[i] = {start, end, i};
    }

    sort(ranges.begin(), ranges.end(), [](auto &a, auto &b) {
        if (get<0>(a) == get<0>(b)) {
            return get<1>(a) > get<1>(b);
        }
        return get<0>(a) < get<0>(b);
    });

    vector<bool> isContained(n, false);
    vector<bool> containsAnother(n, false);

    int max_y = -1;
    for (int i = 0; i < n; i++) {
        if (get<1>(ranges[i]) <= max_y) {
            isContained[get<2>(ranges[i])] = true;
        }
        max_y = max(max_y, get<1>(ranges[i]));
    }

    int min_y = INT_MAX;
    for (int i = n - 1; i >= 0; i--) {
        if (get<1>(ranges[i]) >= min_y) {
            containsAnother[get<2>(ranges[i])] = true;
        }
        min_y = min(min_y, get<1>(ranges[i]));
    }

    for (bool x : containsAnother) {
        cout << x << " ";
    }
    cout << endl;

    for (bool x : isContained) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}