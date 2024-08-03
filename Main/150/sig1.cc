#include <iostream>
#include <vector>
using namespace std;

vector<string> solution(vector<string> a) {
    int n = a.size();
    vector<string> result(n, "");
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            int m = a[0].size() - 1;
            result[i] += a[i][0];
            result[i] += a[0][m];
        } else {
            int m = a[i + 1].size() - 1;
            result[i] += a[i][0];
            result[i] += a[i + 1][m];
        }
    }
    return result;
}

int main() {
    // vector<string> ex = {"cat", "dog", "ferret", "scorpion"};
    vector<string> ex = {"singularity"};
    auto result = solution(ex);
    for (auto word : result) {
        cout << word << endl;
    }
}