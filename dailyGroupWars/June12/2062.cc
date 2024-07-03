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