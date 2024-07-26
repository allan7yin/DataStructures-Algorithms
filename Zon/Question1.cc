#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int findMinClicks(string letters) {
    vector<int> fmap(26, 0);
    for (auto &ch : letters) {
        fmap[ch - 'a']++;
    }

    sort(fmap.begin(), fmap.end(), greater<int>());
    int i = 0, j = 1, total = 0;
    for (int k = 0; k < 26; k++) {
        i++;
        total += (j * fmap[k]);
        if (i % 9 == 0) {
            j++;
        }
    }
    return total;
}

int main() {
    string ex1 = "abacadefghibj";
    cout << findMinClicks(ex1) << endl;
    return 1;
}