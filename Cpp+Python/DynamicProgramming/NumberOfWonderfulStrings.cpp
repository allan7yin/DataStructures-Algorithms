#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long wonderfulSubstrings(string word) {
      // only characters from 'a' to 'j'
      int parity = 0;
      long long count = 0;
      unordered_map<int, int> prefix_count {{0,1}};

      for (int i = 0; i < word.size(); i++) {
        int shift = word[i] - 'a';
        parity ^= 1<<shift;

        // this is for 0 odd-number occurrences
        count += prefix_count[parity]; // no need to check if exists, default is 0

        // this is for 1 odd-number occurrence 
        for (int j = 0; j < 10; j++) {
          int copy = parity ^ (1<<j);
          count += prefix_count[copy];
        }

        prefix_count[parity]++;
      }
      return count;
    }
};
