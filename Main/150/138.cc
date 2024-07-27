// Definition for a Node.
#include <unordered_set>
class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

class Solution {
  std::unordered_map<Node *, Node *> mp;

public:
  Node *copyRandomList(Node *head) { return f(head); }

  Node *f(Node *head) {
    if (!head)
      return nullptr;
    if (mp.find(head) != mp.end()) {
      return mp[head];
    }

    // not found, have not been here before -> dfs

    Node *copy = new Node(head->val);
    mp[head] = copy; // need to set this before visiting next node, to avoid
                     // stuck in cycle
    copy->next = f(head->next);
    copy->random = f(head->random);
    return copy;
  }
};
