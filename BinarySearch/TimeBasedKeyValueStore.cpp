#include <unordered_map>
#include <vector>
#include <string>

using namespace std;
/*
    - Idea: hash_map -> key, value is another hashmap -> timestamp to value 
    - when getting a particular key with timestamp, will perform binary search for the next available timestamp value in the hashmap 

    - look into upper_bound function is from STL -> works on any sorted ranfe, including sets and hashmaps -> searches for this upperbound with binary search 
*/
class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        // binary search for the largest timestamp that is <= timestamp 
        int l = 0, r = store[key].size() - 1;
        pair<int,string> result = {-1, ""};
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (store[key][mid].first == timestamp) {
                result = {mid, store[key][mid].second};
                break;
            } else if (store[key][mid].first > timestamp) {
                r = mid - 1;
            } else {
                // could be a possible candidate solution
                if (store[key][mid].first > result.first) {
                    result = store[key][mid];
                }
                l = mid + 1;
            }
        }

        return result.second;
    }
private: 
    unordered_map<string, vector<pair<int, string>>> store;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main() {}