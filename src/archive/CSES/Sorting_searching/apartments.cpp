#include <iostream>
#include <vector>

using namespace std;

/*
Input:

4 3 5
60 45 80 60
30 60 75

Sort both?
- 45 60 60 80
- 80 60 60 45
- 75 60 30

*/
int main() {
    int n, m, d;
    cin >> n >> m >> d;

    vector<int> people;
    vector<int> sizes;

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        people.push_back(p);
    }

    for (int i = 0; i < m; i++) {
        int s;
        cin >> s;
        sizes.push_back(s);
    }

    sort(people.begin(), people.end(), greater<int>());
    sort(sizes.begin(), sizes.end(), greater<int>());
    int count = 0;

    int l = 0, r = 0;
    while (l < people.size() && r < sizes.size()) {
        if (abs(people[l] - sizes[r]) <= d) {
            count++;
            l++;
            r++;
        } else if (people[l] > sizes[r]) {
            l++;
        } else {
            r++;
        }
    }
    cout << count << endl;
}