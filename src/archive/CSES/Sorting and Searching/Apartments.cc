#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/*
https://cses.fi/problemset/task/1084
*/

int findMatches(vector<int> &desired_sizes, vector<int> &apartment_sizes, int k) {
    sort(desired_sizes.begin(), desired_sizes.end());
    sort(apartment_sizes.begin(), apartment_sizes.end());

    // iterate through both of them
    int i = 0, j = 0, count = 0;
    while (j < desired_sizes.size() && i < apartment_sizes.size()) {
        if (abs(apartment_sizes[i] - desired_sizes[j]) <= k) {
            count++;
            i++;
            j++;
        } else if (apartment_sizes[i] < desired_sizes[j] - k) {
            // too small
            i++;
        } else {
            j++;
        }
    }
    return count;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> desired_sizes(n);
    vector<int> apartment_sizes(m);

    for (int i = 0; i < n; ++i) {
        cin >> desired_sizes[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> apartment_sizes[i];
    }

    cout << findMatches(desired_sizes, apartment_sizes, k) << endl;
}
