#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class TimeMap {
  unordered_map<string, vector<pair<int, string>>> mp;

public:
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    mp[key].push_back({timestamp, value});
  }

  string get(string key, int timestamp) {
    // binary search on this
    vector<pair<int, string>> &vals = mp[key];
    int l = 0, r = vals.size() - 1;
    int maxv = -1;
    while (l <= r) {
      int m = (l + r) / 2;
      if (vals[m].first == timestamp)
        return vals[m].second;

      if (vals[m].first <= timestamp) {
        maxv = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    return (maxv == -1) ? "" : vals[maxv].second;
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
