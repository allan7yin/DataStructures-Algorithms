#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7; // define the modulo constant

unordered_map<int, int> mem;
vector<int> sides = {1, 2, 3, 4, 5, 6};

int countDiceCombinations(int target) {
    if (target < 0) return 0;
    if (target == 0) return 1;
    if (mem.find(target) != mem.end()) return mem[target];

    int count = 0;
    for (int side : sides) {
        count = (count + countDiceCombinations(target - side)) % MOD; // apply modulo
    }

    mem[target] = count;
    return mem[target];
}

int main() {
    int target;
    cin >> target;
    cout << countDiceCombinations(target) << endl;
}