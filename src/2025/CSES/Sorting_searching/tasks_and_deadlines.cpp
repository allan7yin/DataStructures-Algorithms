#include <iostream>
#include <vector>

using namespace std;

/*
Input:

3
6 10
8 15
5 12
Output:

2

How?
Sort in decreasing order of most time: 8 15, 5 12, 6 10
task1: start t = 0, 5 12 -> endtime is 5 -> +7
task2: start = 5, 6 10 -> endtime is 11 -> 10 - 11 = -1
task3: start t = 11, 8 15 ->endtime is 19 -> 15 - 19 = -4

Solution 2

Pattern?
Sort by duration. We want small duration done first, otherwise, larger ones will bottleneck them.
*/

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> tasks;
    for (int i = 0; i < n; i++) {
        int first, second;
        cin >> first >> second;
        tasks.push_back({first, second});
    }

    sort(tasks.begin(), tasks.end(), [](auto &a, auto &b) {
        return a.first < b.first || (a.first == b.first) && a.second > b.second;
    });

    long long count = 0LL;
    long long time = 0;
    for (auto &task : tasks) {
        time += task.first;
        count += (long long)(task.second - time);
    }

    cout << count << endl;
}