#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// pairs of event: <time, departure or arrival> -> -1 for departure, 1 for arrival
int maxCustomers(vector<pair<int, int>> events) {
    int maxVal = 0;
    int count = 0;
    sort(events.begin(), events.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        if (a.first < b.first) return true;
        if (a.first > b.first) return false;

        return a.second == -1;
    });

    for (auto &kv : events) {
        if (kv.second == -1) {
            count--;
        } else {
            count++;
            maxVal = max(maxVal, count);
        }
    }
    return maxVal;
}

int main() {
    int num;
    cin >> num;

    vector<pair<int, int>> events;

    for (int i = 0; i < num; i++) {
        int a, b;
        cin >> a >> b;
        events.push_back(make_pair(a, 1));
        events.push_back(make_pair(b, -1));
    }

    cout << maxCustomers(events) << endl;
}