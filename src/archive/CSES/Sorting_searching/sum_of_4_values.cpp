#include <iostream>
#include <map>
#include <vector>

using namespace std;

// 4sum
/*
The idea is to maintain all possible sums between 2 values -> mapped to the indices that contribute to the sum
*/
int main() {
    int n, target;

    cin >> n >> target;
    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    map<long long, vector<pair<int, int>>> mp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long sum = values[i] + values[j];
            mp[sum].push_back({i, j});
        }
    }

    auto start = mp.begin();
    auto end = mp.end();

    end--;
    while (start != end && start != mp.end()) {
        long long current_sum = start->first + end->first;
        if (current_sum == target) {
            for (auto &p1 : start->second) {
                for (auto &p2 : end->second) {
                    if (p1.first != p2.first && p1.first != p2.second && p1.second != p2.first && p1.second != p2.second) {
                        cout << p1.first + 1 << " " << p1.second + 1 << " " << p2.first + 1 << " " << p2.second + 1 << endl;
                        return 0;
                    }
                }
            }
            start++;
            end--;
        } else if (current_sum < target) {
            start++;
        } else {
            end--;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}