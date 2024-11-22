#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class TimeMap {
    unordered_map<string, vector<pair<int, string>>> mp;

  public:
    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        // binary search for this timestamp in the vector
        if (mp.find(key) == mp.end()) return "";
        int l = 0, r = mp[key].size() - 1;
        string result = "";

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (mp[key][m].first <= timestamp) {
                result = mp[key][m].second;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return result;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */