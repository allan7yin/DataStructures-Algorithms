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
  ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
    int count = 1;
    ListNode *dummy = new ListNode();
    dummy->next = list1;
    // first find the node before the a'th node
    while (count < a) {
      list1 = list1->next;
      count++;
    }
    ListNode *preA = list1;
    while (count < b + 2) {
      list1 = list1->next;
      count++;
    }
    // one before list1 is one we don't want
    preA->next = list2;
    while (list2->next) {
      list2 = list2->next;
    }
    list2->next = list1;
    return dummy->next;
  }
};