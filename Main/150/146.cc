#include <unordered_map>

using namespace std;

class Node {
public:
  int val;
  Node *next = nullptr;
  Node *prev = nullptr;
  Node(int val) : val(val) {}
};

class LRUCache {
  unordered_map<int, pair<int, Node *>> mp;
  Node *head = nullptr;
  Node *tail = nullptr;
  int size = 0;
  int capacity;

public:
  LRUCache(int capacity) : capacity(capacity) {}

  void move(Node *p) {
    if (p == tail) {
      return;
    }
    if (p == head) {
      head = head->next;
      if (head) {
        head->prev = nullptr;
      }
    } else {
      p->prev->next = p->next;
      if (p->next) {
        p->next->prev = p->prev;
      }
    }
    tail->next = p;
    p->prev = tail;
    p->next = nullptr;
    tail = p;
  }

  int get(int key) {
    if (mp.find(key) != mp.end()) {
      int val = mp[key].first;
      Node *p = mp[key].second;
      move(p);
      return val;
    }
    return -1;
  }

  void put(int key, int value) {
    if (mp.find(key) != mp.end()) {
      Node *p = mp[key].second;
      move(p);
      mp[key] = make_pair(value, p);
      return;
    }

    Node *v = new Node(key);
    if (size == 0) {
      head = v;
      tail = v;
    } else {
      tail->next = v;
      v->prev = tail;
      tail = v;
    }
    mp[key] = make_pair(value, v);
    size++;

    while (size > capacity) {
      int k = head->val;
      Node *p = head->next;
      if (p) {
        p->prev = nullptr;
      }
      delete head;
      head = p;
      size--;
      mp.erase(k);
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
