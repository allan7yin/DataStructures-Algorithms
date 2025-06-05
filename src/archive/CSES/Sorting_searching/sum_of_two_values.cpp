#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int n, target;
    cin >> n >> target;

    vector<pair<int, int>> nums;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back({num, i});
    }

    sort(nums.begin(), nums.end());
    bool found = false;
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int val = nums[l].first + nums[r].first;
        if (val == target) {
            cout << nums[l].second + 1 << " " << nums[r].second + 1;
            found = true;
            break;
        } else if (val > target) {
            r--;
        } else {
            l++;
        }
    }

    if (!found) {
        cout << "IMPOSSIBLE" << endl;
    }
}