#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> songs;
    map<int, int> seen;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        songs.push_back(num);
    }

    int l = 0;
    int maxVal = 0;

    for (int i = 0; i < n; i++) {
        int song = songs[i];

        if (seen.find(song) == seen.end()) {
            seen[song] = i;
        } else {
            if (seen[song] >= l) {
                l = seen[song] + 1;
            }

            seen[song] = i;
        }

        maxVal = max(maxVal, i - l + 1);
    }

    cout << maxVal << endl;
}