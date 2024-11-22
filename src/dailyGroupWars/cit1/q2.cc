#include <algorithm>
#include <climits> // Include this header for INT_MAX
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Sliding window problem
int consistentLogs(vector<int> userEvent, int n) {
  unordered_map<int, int> freq;
  for (int &e : userEvent) {
    freq[e]++;
  }
  int minValue = INT_MAX;
  for (const auto &pair : freq) {
    if (pair.second < minValue) {
      minValue = pair.second;
    }
  }

  unordered_map<int, int> map;
  int l = 0;
  int maxLength = 0;

  for (int r = 0; r < n; r++) {
    map[userEvent[r]]++;
    bool cond = true;
    while (l < r) {
      int maxFreq = 0;
      for (const auto &pair : map) {
        maxFreq = max(maxFreq, pair.second);
      }
      if (maxFreq <= minValue) {
        if (maxFreq < minValue)
          cond = false;
        break;
      }
      map[userEvent[l]]--;
      if (map[userEvent[l]] == 0) {
        map.erase(userEvent[l]);
      }
      l++;
    }
    if (cond)
      maxLength = max(maxLength, r - l + 1);
  }

  return maxLength;
}

int main() {
  vector<int> test1 = {1, 2, 1, 3, 4, 2, 4, 3, 3, 4};
  vector<int> test2 = {9, 9, 9};
  int result = consistentLogs(test1, 10);
  cout << "Answer1 is " << result << endl;

  int result2 = consistentLogs(test2, 3);
  cout << "Answer1 is " << result2 << endl;
}