#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    multiset<int> nums;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.insert(num);
    }

    vector<int> customers;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        customers.push_back(num);
    }

    for (int &customer : customers) {
        auto it = nums.upper_bound(customer);
        if (it != nums.begin()) {
            // there is something smaller
            it--;
            cout << *it << endl;
            nums.erase(it);
        } else {
            cout << -1 << endl;
        }
    }
}