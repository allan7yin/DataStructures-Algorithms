class Solution {
public:
  int distanceBetweenBusStops(vector<int> &distance, int start, int destination) {
    // accumulate in both directions
    int forward = 0, backward = 0, n = distance.size();
    int startPosition = min(start, destination), endPosition = max(start, destination);

    for (int i = 0; i < n; i++) {
      if (i < endPosition && i >= startPosition) {
        forward += distance[i];
      } else {
        backward += distance[i];
      }
    }
    return min(forward, backward);
  }
};