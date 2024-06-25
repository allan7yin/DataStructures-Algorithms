#include <unordered_map>

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
public:
  Node *copyRandomList(Node *head) {
    std::unordered_map<Node *, Node *> visited;
    return dfs(head, visited);
  }

  Node *dfs(Node *current, std::unordered_map<Node *, Node *> &visited) {
    if (!current) {
      return nullptr;
    }
    if (visited.find(current) != visited.end()) {
      return visited[current];
    }
    Node *curr = new Node(current->val);
    visited[current] = curr;
    curr->next = dfs(current->next, visited);
    curr->random = dfs(current->random, visited);
    return curr;
  }
};