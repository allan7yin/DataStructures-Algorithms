#include "../bits/stdc++.h"

using namespace std;

class Solution {
  public:
    vector<int> findWordsContaining(vector<string> &words, char x) {
        vector<int> result;
        for (int i = 0; i < words.size(); i++) {
            bool found = false;
            for (auto &ch : words[i]) {
                if (ch == x) found = true;
            }

            if (found) result.push_back(i);
        }

        return result;
    }
};