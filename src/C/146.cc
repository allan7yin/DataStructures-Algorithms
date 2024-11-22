#include <unordered_map>
#include <utility>

using namespace std;

class Node {
  public:
    Node *next;
    Node *prev;
    pair<int, int> val; // lru -> key, value

    Node(Node *prev, Node *next, pair<int, int> val) : prev(prev), next(next), val(val) {}
};

class LRUCache {
    int size = 0;
    int capacity;
    Node *head;
    Node *tail;
    unordered_map<int, Node *> mp;

  public:
    LRUCache(int capacity) : capacity(capacity), head(nullptr), tail(nullptr) {}

    void removeNode(Node *node) {
        // Remove node from its current position in the doubly linked list
        if (node->prev) {
            node->prev->next = node->next;
        } else {
            // If there's no previous node, it means we're removing the head
            head = node->next;
        }

        if (node->next) {
            node->next->prev = node->prev;
        } else {
            // If there's no next node, we're removing the tail
            tail = node->prev;
        }

        size--;
    }

    void insertToEnd(Node *node) {
        node->next = nullptr;
        node->prev = tail;
        if (tail) tail->next = node;
        tail = node;
        if (!head) {
            head = node;
        }
        size++;
        return;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            auto node = mp[key];
            removeNode(node);
            insertToEnd(node);
            return mp[key]->val.second;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // update current value
            auto node = mp[key];
            node->val.second = value;
            removeNode(node);
            insertToEnd(node);
        } else {
            // insert new node
            if (size == capacity) {
                // evict first node in the LL
                mp.erase(head->val.first);
                removeNode(head);
            }
            auto node = new Node(nullptr, nullptr, make_pair(key, value));
            mp[key] = node;
            insertToEnd(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */