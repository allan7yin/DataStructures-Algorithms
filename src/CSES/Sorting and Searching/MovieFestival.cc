#include <climits>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// pairs of event: <time, departure or arrival> -> -1 for departure, 1 for arrival
int maxMovies(vector<pair<int, int>> movies) {
    int time = INT_MIN;
    int count = 0;
    sort(movies.begin(), movies.end(), [](const pair<int, int> a, const pair<int, int> b) {
        return a.second < b.second;
    });

    for (auto &kv : movies) {
        int s = kv.first, e = kv.second;

        if (s >= time) {
            // watch this movie
            count++;
            time = e;
        }
    }
    return count;
}

int main() {
    int num;
    cin >> num;

    vector<pair<int, int>> movies;

    for (int i = 0; i < num; i++) {
        int a, b;
        cin >> a >> b;
        movies.push_back(make_pair(a, b));
    }

    cout << maxMovies(movies) << endl;
}
