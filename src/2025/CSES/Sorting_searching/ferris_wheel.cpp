#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());

    int l = 0, r = nums.size() - 1;
    int count = 0;
    while (l <= r) {
        if (nums[l] + nums[r] <= m) {
            l++;
            r--;
        } else {
            r--;
        }
        count++;
    }

    cout << count << endl;
}