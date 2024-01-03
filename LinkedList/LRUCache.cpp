#include <unordered_map>

using namespace std;

/*
    - To do this, we use a doubly linkedlist and a hashmap 
*/
class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class LRUCache {
public:
    LRUCache(int capacity) {
        available = capacity;
        limit = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        // getting also moves the respective node to the head 
        if (cache.find(key) != cache.end()) {
            put(key, cache[key]->val);
            return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // if the key already exists, we are simply deleting it, and re-inserting it with new value 
        if (cache.find(key) != cache.end()) {
            Node *victim = cache[key];
            Node *prev = victim->prev;
            Node *next = victim->next;
            prev->next = next;
            next->prev = prev;
            cache.erase(victim->key);
            available++;
            delete victim;
        }

        // if there is no capacity -> evict the farthest right one
        if (available == 0) {
            Node *victim = tail->prev;
            tail->prev = victim->prev;
            victim->prev->next = tail;
            cache.erase(victim->key);
            available++;
            delete victim;
        }


        // insert this kv pair into the LL and map
        Node *node = new Node(key,value);
        Node *h = head->next;
        node->next = h;
        h->prev = node;
        node->prev = head;
        head->next = node;
        cache[key] = node;
        available--;
    }
private:
    Node *head;
    Node *tail;
    unordered_map<int, Node *> cache;
    int available;
    int limit;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main () {
    LRUCache lRUCache = LRUCache(2);
    lRUCache.put(2, 6); // cache is {1=1}
    lRUCache.put(1, 5); // cache is {1=1, 2=2}
    lRUCache.get(1);    // return 1
    lRUCache.put(1, 2); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    int r = lRUCache.get(2);    // returns -1 (not found)
    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    lRUCache.get(1);    // return -1 (not found)
    lRUCache.get(3);    // return 3
    lRUCache.get(4);    // return 4


    // LRUCache lRUCache = LRUCache(2);
    // lRUCache.put(2, 1); // cache is {1=1}
    // lRUCache.put(2, 2); // cache is {1=1, 2=2}
    // lRUCache.get(2);    // return 1
    // lRUCache.put(1, 1); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    // // lRUCache.get(2);    // returns -1 (not found)
    // lRUCache.put(4, 1); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    // lRUCache.get(2);    // return -1 (not found)
    // lRUCache.get(3);    // return 3
    // lRUCache.get(4);    // return 4
}