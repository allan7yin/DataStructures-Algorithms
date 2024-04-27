#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

// this is not TLE, but still not fast as we want -> for reference, it is faster
// 34% of solutions we an improve this by using DP instead
struct PairHash {
  size_t operator()(const pair<int, int> &p) const {
    // Combine the hash values of the two integers
    return hash<int>{}(p.first) ^ hash<int>{}(p.second);
  }
};

class Solution {
public:
  int findRotateSteps(string ring, string key) {
    unordered_map<pair<int, int>, int, PairHash> cache;
    return findRotateToNextChar(ring, key, 0, 0, cache);
  }

  int findRotateToNextChar(
      string &ring, string &key, int index, int key_index,
      unordered_map<pair<int, int>, int, PairHash> &cache) {
    if (key_index == key.size()) {
      return 0;
    }
    pair<int, int> item = make_pair(index, key_index);
    if (cache.find(item) != cache.end()) {
      return cache[item];
    }
    int result = INT_MAX;
    int min_moves = ring.size() + 10;
    for (int i = 0; i < ring.size(); i++) {
      if (ring[i] == key[key_index]) {
        min_moves = min(abs(index - i), (int)ring.size() - abs(index - i));
        result =
            min(min_moves + 1 +
                    findRotateToNextChar(ring, key, i, key_index + 1, cache),
                result);
      }
      cache[item] = result;
    }
    return result;
  }
};
