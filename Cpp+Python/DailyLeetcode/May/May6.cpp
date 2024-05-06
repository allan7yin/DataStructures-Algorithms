#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *removeNodes(ListNode *head) {
    // maintain size of the linkedlist
    int size = 1;
    ListNode *top = head;
    vector<ListNode *> monStack;
    ListNode *prev = nullptr;
    while (head) {
      while (!monStack.empty() && monStack.back()->val < head->val) {
        monStack.pop_back();
      }
      if (!monStack.empty()) {
        monStack.back()->next = head;
      } else {
        top = head;
      }
      monStack.push_back(head);
      head = head->next;
    }

    // now, we return head
    return top;
  }
};
