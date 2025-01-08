#include <iostream>
#include <vector>

using namespace std;

// naive solution to this O(n^2) -> but we want something else.
// fuck -> this is a monotonically increasing stack question
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<pair<int, int>> st;
    vector<int> result;

    for (int i = 0; i < n; i++) {
        if (st.empty()) {
            result.push_back(0);
        } else {
            while (!st.empty() && st.back().first >= nums[i]) {
                st.pop_back();
            }

            if (st.empty()) {
                result.push_back(0);
            } else {
                result.push_back(st.back().second);
            }
        }
        st.push_back({nums[i], i + 1});
    }

    for (int &num : result) {
        cout << num << " ";
    }
}