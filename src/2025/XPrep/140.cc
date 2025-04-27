#include "bits/stdc++.h";
using namespace std;

// naive recursive solution is 2^n in terms of runtime complexity -> each index
// we take or don't take so, we have 2 options, then 2^2, then 2^8, ..., then
// 2^n

// with memoization, each index is only visited once in the string s. So, O(n x
// m x k)

class Solution {
  unordered_map<int, vector<string>> memo;

public:
  vector<string> wordBreak(string s, vector<string> &wordDict) {
    return f(s, wordDict, 0);
  }

  vector<string> f(string s, vector<string> &wordDict, int i) {
    if (i >= s.size())
      return {""};

    if (memo.find(i) != memo.end())
      return memo[i];

    vector<string> sentences;
    for (string &prefix : wordDict) { // O(m)
      int n = prefix.size();
      if (s.compare(i, n, prefix) == 0) { // O(k)
        // take and recurse
        vector<string> rest = f(s, wordDict, i + n);
        for (string &sentence : rest) {
          string newSentence =
              sentence.empty() ? prefix : prefix + " " + sentence;
          sentences.push_back(newSentence);
        }
      }
    }

    return memo[i] = sentences;
  }
};
