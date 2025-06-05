#include <iostream>
#include <vector>

using namespace std;

// 3sum
/*
1 <= n <= 5000
1 <= x, a <= 10^9

So, RT: n^2 which is ok since n ~= 5000
*/
int main() {
    int n, target;
    cin >> n >> target;

    vector<pair<int, int>> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i].first;
        nums[i].second = i + 1;
    }

    sort(nums.begin(), nums.end()); // nlogn -> 5000 log 5000

    for (int i = 0; i < n; i++) { // n^2
        int sub_target = target - nums[i].first;
        int l = 0, r = n - 1;
        while (l < r) {
            if (l == i) {
                l++;
                continue;
            }
            if (r == i) {
                r--;
                continue;
            }
            int m = nums[l].first + nums[r].first;
            if (m == sub_target) {
                cout << nums[i].second << " " << nums[l].second << " " << nums[r].second << endl;
                return 0;
            } else if (m > sub_target) {
                r--;
            } else if (m < sub_target) {
                l++;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}