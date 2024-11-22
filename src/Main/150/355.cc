#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Twitter {
    unordered_map<int, vector<pair<int, int>>> mp; // this maps the userId, to the tweet they have made: time, id
    unordered_map<int, unordered_set<int>> fs;     // this maps a userId to the user they follow
    int timestamp = 0;

  public:
    Twitter() {
    }

    void postTweet(int userId, int tweetId) {
        mp[userId].push_back({timestamp, tweetId});
        fs[userId].insert(userId);
        timestamp++;
    }

    vector<int> getNewsFeed(int userId) {
        // create maxheap and push all tweets of each followee into this
        priority_queue<pair<int, int>> pq; // this is max heap of pairs: time, id
        for (auto &followee : fs[userId]) {
            for (auto &tweet : mp[followee]) {
                pq.push(tweet);
            }
        }

        vector<int> result;
        for (int i = 0; i < 10 && !pq.empty(); i++) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }

    void follow(int followerId, int followeeId) {
        fs[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            fs[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */