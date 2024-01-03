#include <vector>
using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // take 2 and merge, keep going until there is only one LL left     
        if (lists.size() == 0) {
            return nullptr;
        }
        while (lists.size() > 1) {
            ListNode *l1 = lists.back();
            lists.pop_back();
            ListNode *l2 = lists.back();
            lists.pop_back();

            lists.push_back(merge_two_lists(l1,l2));
        }
        return lists[0];
    }

    ListNode* merge_two_lists(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode();
        ListNode *curr = dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = (l1 ? l1:l2); 
        curr = dummy->next;
        delete dummy;
        return curr;
    }
};

int main() {
    // Hardcoding linked lists from the given arrays
    Solution sol;
    ListNode* list1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* list3 = new ListNode(2, new ListNode(6));
    vector<ListNode*> lists = {list1, list2, list3};
    sol.mergeKLists(lists);
}