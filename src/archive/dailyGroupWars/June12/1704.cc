class Solution {
public:
  bool halvesAreAlike(string s) {
    int first = 0;
    int second = 0;
    vector<int> v = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    set<int> mySet(v.begin(), v.end());

    int index2 = s.size() / 2;
    for (int i = 0; i < s.size(); i++) {
      if (i < index2 && mySet.find(s[i]) != mySet.end()) {
        first++;
      } else if (mySet.find(s[i]) != mySet.end()) {
        second++;
      }
    }
    return first == second;
  }
};