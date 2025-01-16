#include "bits/stdc++.h"

using namespace std;

int n;
const int MOD = 1e9 + 7;
unordered_map<int, int> mem;
vector<int> dice_sides = {1, 2, 3, 4, 5, 6};

int f(int sum) {
  if (sum > n)
    return 0;
  if (sum == n)
    return 1;
  if (mem.find(sum) != mem.end())
    return mem[sum];

  int count = 0;
  for (int side : dice_sides) {
    count = (count + f(sum + side)) % MOD;
  }

  mem[sum] = count % MOD;
  return mem[sum];
}

int main() {
  cin >> n;
  cout << f(0) << endl;
}
