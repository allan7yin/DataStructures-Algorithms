#include "../bits/stdc++.h"
using namespace std;

class Logger {
    int time = 0;
    unordered_map<string, int> mp; // map message to timestamp
  public:
    Logger() {
    }

    bool shouldPrintMessage(int timestamp, string message) {
        bool cond = true;
        if (mp.find(message) != mp.end() && timestamp - mp[message] < 10) {
            cond = false;
        } else {
            mp[message] = timestamp;
        }
        return cond;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */