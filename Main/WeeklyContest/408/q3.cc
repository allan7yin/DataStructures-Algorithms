#include <string>
#include <utility>
#include <vector>

using namespace std;
// yeah idk how to do < 0(n^2)
class Solution {
  public:
    int square(int x) { return x * x; }

    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<pair<int, int>> prefixSum(n + 1, {0, 0});

        // Build the prefix sum vector
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i];
            if (s[i] == '1') {
                prefixSum[i + 1].first++;
            } else {
                prefixSum[i + 1].second++;
            }
        }

        int count = 0;
        // Iterate over all possible substrings
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int ones = prefixSum[j].first - prefixSum[i].first;
                int zeroes = (prefixSum[j].second - prefixSum[i].second) * (prefixSum[j].second - prefixSum[i].second);

                if (ones >= zeroes) {
                    count++;
                }
            }
        }

        return count;
    }
};

// "101101"
// 001111