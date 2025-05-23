#include "../bits/stdc++.h"

using namespace std;

class LRUCache {
    int capacity;
    list<pair<int, int>> values;
    unordered_map<int, list<pair<int, int>>::iterator> mp;

  public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        auto result = *(mp[key]);
        values.erase(mp[key]);
        values.push_back(result);
        mp[key] = --values.end();
        return result.second;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            values.erase(mp[key]);
        } else if (capacity == values.size()) {
            // new element, check if capacity
            auto evict_pair = values.begin();
            mp.erase(evict_pair->first);
            values.pop_front();
        }

        // now, just insert into the end
        values.push_back({key, value});
        mp[key] = --values.end();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */