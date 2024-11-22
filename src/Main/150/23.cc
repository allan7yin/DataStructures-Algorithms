#include <deque>
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
    ListNode *merge(ListNode *first, ListNode *second) {
        ListNode *dummy = new ListNode();
        auto cur = dummy;
        while (first && second) {
            if (first->val < second->val) {
                cur->next = first;
                first = first->next;
            } else {
                cur->next = second;
                second = second->next;
            }
            cur = cur->next;
        }

        while (first) {
            cur->next = first;
            first = first->next;
            cur = cur->next;
        }

        while (second) {
            cur->next = second;
            second = second->next;
            cur = cur->next;
        }
        return dummy->next;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) return nullptr;
        if (lists.size() == 1) return lists[0];
        deque<ListNode *> dq(lists.begin(), lists.end());
        while (dq.size() > 1) {
            auto first = dq.front();
            dq.pop_front();
            auto second = dq.front();
            dq.pop_front();
            dq.push_back(merge(first, second));
        }

        return dq.front();
    }
};