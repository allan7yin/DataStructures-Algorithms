#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<long>> rows;

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);

        istringstream input_stream(line);
        vector<long> row;
        int num;

        while (input_stream >> num) {
            row.push_back(num);
        }

        rows.push_back(row);
    }

    // find the max value
    long dimensions = 0;
    for (auto &p : rows) {
        dimensions = max(dimensions, max(p[1], p[0]));
    }
}