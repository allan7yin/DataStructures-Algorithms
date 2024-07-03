class Solution {
public:
  char nextGreatestLetter(vector<char> &letters, char target) {
    char sol = letters[0];
    for (char &ch : letters) {
      if (ch > target) {
        if (sol <= target || ch < sol) {
          sol = ch;
        }
      }
    }
    return sol > target ? sol : letters[0];
  }
};
