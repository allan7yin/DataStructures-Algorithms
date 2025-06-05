#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// bounds -> 1 <= n <= 2 * 10^5 -> O(n) or O(nlogn) -> sort
int main() {
    int n;
    vector<int> nums;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    int count = 1;
    sort(nums.begin(), nums.end());

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i - 1]) {
            count++;
        }
    }

    cout << count << endl;
}