#include <iostream>
#include <map>
#include <vector>
using namespace std;

unordered_map<char, int> mp = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}};

int romanToInt(string numeral) {
    int n = numeral.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (i < n - 1 && mp[numeral[i]] < mp[numeral[i + 1]]) {
            sum -= mp[numeral[i]];
        } else {
            sum += mp[numeral[i]];
        }
    }
    return sum;
}

vector<string> sortRegnalNames(const vector<string> &names) {
    map<int, vector<string>> vers;
    vector<string> result;

    for (const string &name : names) {
        size_t pos = name.find(' ');
        string romanNumeral = name.substr(pos + 1);
        int val = romanToInt(romanNumeral);
        vers[val].push_back(name);
    }

    // collect everything back into a vector
    for (auto &kv : vers) {
        result.insert(result.end(), kv.second.begin(), kv.second.end());
    }
    return result;
}

int main() {
    vector<string> names = {"Louis IX", "Louis VIII", "Philippe II", "Charles V", "Charles IV"};
    vector<string> sortedNames = sortRegnalNames(names);

    for (const string &name : sortedNames) {
        cout << name << endl;
    }

    return 0;
}
