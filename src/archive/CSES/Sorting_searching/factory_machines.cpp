#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// binary search on k -> since 10^9 > 10^6, must be logn or constant time solution
// binary search over all possible values of finish time
int main() {
    int n, m;
    cin >> n >> m;

    vector<int> times;
    int minTime = INT_MAX;
    for (int i = 0; i < n; i++) {
        int time;
        cin >> time;
        minTime = min(minTime, time);
        times.push_back(time);
    }

    long long l = 1;
    long long r = (long long)minTime * m;

    long long result = -1;
    while (l <= r) {
        long long mid = l + (r - l) / 2;
        long long count = 0;

        for (int &time : times) {
            count += (mid / time);
        }

        if (count >= m) {
            result = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << result << endl;
}

// 1 2 3 4 5
// 1 2 3 4