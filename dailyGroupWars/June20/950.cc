/*
We take sorted array, and reverse these operations
*/
class Solution {
public:
  vector<int> deckRevealedIncreasing(vector<int> &deck) {
    std::deque<int> dq;
    std::vector<int> result;
    std::sort(deck.begin(), deck.end());

    for (int i = deck.size() - 1; i >= 0; i--) {
      int last_card = deck.back();
      deck.pop_back();
      dq.push_front(last_card);
      if (!dq.empty() && i != 0) {
        int last = dq.back();
        dq.pop_back();
        dq.push_front(last);
      }
    }

    while (!dq.empty()) {
      result.push_back(dq.front());
      dq.pop_front();
    }
    return result;
  }
};