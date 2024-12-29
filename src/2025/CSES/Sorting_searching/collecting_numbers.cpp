#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n + 1, 0);

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums[num] = i;
    }

    int count = 1;
    for (int i = 2; i <= n; i++) {
        if (nums[i] < nums[i - 1]) {
            count++;
        }
    }

    cout << count << endl;
}
