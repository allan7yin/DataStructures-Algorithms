#include <cmath>
#include <unordered_map>
using namespace std;
/*
 * This is a sliding window question. How will we approach this? Like so:
 * - keep moving the 2 pointers right. As long as we don't have all vowels 
 *   will need to keep moving right pointer. If we don't have all 5 and we land 
 *   on a consonant, we need to move left all the way until the right pointer 
 *
 *   We are trying to always maintain a window of minimum elements, but still all vowels
 *   - in this case, whenever we have EXCESS vowels, we move l forwards, and record
 *     the prefix of vowels, as we add this later to account for substrings 
 *     that we miss when moving left pointer forwards 
 */

class Solution {
public:
 int countVowelSubstrings(string word) {
    int count = 0;
    int prefix = 0;
    unordered_map<char, int> myMap;

    for (int l = 0, r = 0; r < word.size(); r++) {
      char ch = word[r];
      if (!isVowel(ch)) {
        l = r + 1;
        prefix = 0;
        myMap.clear();
      } else {
        myMap[ch]++;

        // move left pointer, incrementing the prefix 
        while (l <= r && myMap[word[l]] > 1) {
          myMap[word[l++]]--;
          prefix++;
        }

        if (myMap.size() == 5) {
          count += (1 + prefix);
        }
      }
    }
    return count;
  }

  bool isVowel(char ch) {
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
  }
};
