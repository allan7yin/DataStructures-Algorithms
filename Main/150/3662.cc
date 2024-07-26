#include <queue>
using namespace std;

// this was seen on a friend's recent Citadel interview first round
class HitCounter {
  queue<int> hits;

public:
  HitCounter() {}

  /**
   * @param timestamp: the timestamp
   * @return: nothing
   */
  void hit(int timestamp) { hits.push(timestamp); }

  /**
   * @param timestamp: the timestamp
   * @return: the count of hits in recent 300 seconds
   */
  int getHits(int timestamp) {
    while (!hits.empty() && hits.front() <= max(0, timestamp - 300)) {
      hits.pop();
    }
    return hits.size();
  }
};
