#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x, n;
    cin >> x >> n;

    set<int> ordered_stops;
    multiset<int> distances;

    ordered_stops.insert(0);
    ordered_stops.insert(x);
    distances.insert(x);

    for (int i = 0; i < n; i++) {
        int stop;
        cin >> stop;

        auto upper = ordered_stops.upper_bound(stop);
        auto lower = upper;
        lower--;

        distances.erase(distances.find(*upper - *lower));

        distances.insert(stop - *lower);
        distances.insert(*upper - stop);

        ordered_stops.insert(stop);

        auto ans = distances.end();
        ans--;

        cout << *ans << endl;
    }
}