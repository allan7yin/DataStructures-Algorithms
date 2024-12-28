#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> events;
    for (int i = 0; i < n; i++) {
        int first, second;
        cin >> first >> second;

        events.push_back({first, 1});
        events.push_back({second, -1});
    }

    sort(events.begin(), events.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.first < b.first || (a.first == b.first && a.second > b.second);
    });

    int maxCount = 0;
    int count = 0;
    for (auto &event : events) {
        if (event.second == 1) {
            count++;
            maxCount = max(count, maxCount);
        } else {
            count--;
        }
    }

    cout << maxCount << endl;
}