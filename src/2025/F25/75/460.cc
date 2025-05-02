#include "../bits/stdc++.h"
using namespace std;

/*
This is not part of the blind 75, but something good to practice for a couple of reasons:
- was asked in a interview before
- is a good practice for using C++ iterators

=> note, we want O(1) time complexity for both of the methods of the data structure


How to solve:
- maintain key-value list of current entries in the data structure
- put, if a new kv pair, then evict the least frequently used one
*/

class LFUCache {
    int capacity;
    int minF;                                     // keep track of the minimum frequency
    unordered_map<int, list<pair<int, int>>> fmp; // maps a frequency count : list of all kv pairs accessed that many times
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    unordered_map<int, int> freq; // maps a key to the frequency

  public:
    LFUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (freq.count(key) == 0) return -1;

        int f = freq[key];
        auto iter = mp[key];
        int val = iter->second;
        fmp[f].erase(iter);

        if (minF == f && fmp[f].empty()) {
            fmp.erase(f);
            minF++;
        }

        freq[key]++;
        fmp[freq[key]].push_back({key, val});
        mp[key] = --fmp[freq[key]].end();

        return val;
    }

    void put(int key, int value) {
        if (freq.count(key)) {
            mp[key]->second = value;
            get(key);
            return;
        }

        if (freq.size() == capacity) {
            // Evict the least frequently used key
            auto evicted = fmp[minF].front(); // Get the least recently used key in minF
            int evictKey = evicted.first;
            fmp[minF].pop_front(); // Remove it from the list
            if (fmp[minF].empty()) {
                fmp.erase(minF); // Remove empty frequency bucket
            }
            freq.erase(evictKey); // Remove the key from freq
            mp.erase(evictKey);   // Remove the iterator reference
        }

        minF = 1;
        fmp[minF].push_back({key, value});
        mp[key] = --fmp[1].end();
        freq[key] = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */