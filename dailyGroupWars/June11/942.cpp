class Solution {
public:
  vector<int> diStringMatch(string s) {
    int n = s.size();
    int low = 0, high = n;
    vector<int> permutations(n + 1);

    for (int k = 0; k < n; k++) {
      if (s[k] == 'I') {
        permutations[k] = low++;
      } else {
        permutations[k] = high--;
      }
    }

    // The last element is determined by the remaining value
    permutations[n] = low; // low and high should be equal here

    return permutations;
  }
};
