#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string input;
    cin >> input;

    int maxLength = 0;
    int l = 0;
    for (int r = 0; r < input.size(); r++) {
        if (input[r] != input[l]) {
            maxLength = max(maxLength, r - l);
            l = r;
            continue;
        }

        if (r == input.size() - 1) {
            maxLength = max(maxLength, r - l + 1);
        }
    }
    cout << maxLength << endl;
}