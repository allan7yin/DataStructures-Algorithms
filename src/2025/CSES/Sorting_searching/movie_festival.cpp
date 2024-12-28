#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// basically -> we want to find max span of
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> movies;

    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        movies.push_back({s, e});
    }

    sort(movies.begin(), movies.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.second < b.second || (a.second == b.second && a.first > b.first);
    });

    int prevTime = -1;
    int count = 0;
    for (auto &movie : movies) {
        if (movie.first >= prevTime) {
            prevTime = movie.second;
            count++;
        }
    }

    cout << count << endl;
}