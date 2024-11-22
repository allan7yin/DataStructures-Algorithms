#include <iostream>
#include <vector>

using namespace std;

int countStableSegments(vector<int> capacity) {
  int n = capacity.size();
  int ans = 0;

  for (int l = 0; l < n - 2; ++l) {
    int sum = 0;
    for (int r = l + 1; r < n - 1; ++r) {
      sum += capacity[r];
      if (capacity[l] == capacity[r + 1] && capacity[l] == sum) {
        ++ans;
      }
    }
  }

  return ans;
}

int main() {
  //   vector<int> capacity = {9, 3, 3, 3, 9};
  vector<int> capacity = {2, 2, 2, 2, 2};
  int result = countStableSegments(capacity);
  cout << "Number of stable sub-segments: " << result << endl;
  return 0;
}