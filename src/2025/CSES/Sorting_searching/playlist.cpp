#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> songs;
    unordered_map<long long, int> seen;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        songs.push_back(num);
    }

    int l = 0;
    long long maxVal = 0;

    for (int i = 0; i < n; i++) {
        long long song = songs[i];

        if (seen.find(song) == seen.end()) {
            seen[song] = i;
        } else {
            if (seen[song] >= l) {
                l = seen[song] + 1;
            }

            seen[song] = i;
        }

        maxVal = max(maxVal, (long long)i - l + 1);
    }

    cout << maxVal << endl;
}