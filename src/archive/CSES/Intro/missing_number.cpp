#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums;
    vector<bool> seen(n + 1, false);
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
        seen[num] = true;
    }

    for (int i = 1; i <= n; i++) {
        if (!seen[i]) {
            cout << i << endl;
        }
    }
}