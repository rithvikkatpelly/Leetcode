/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode lessDummy(0), greaterDummy(0);
        ListNode* lessTail = &lessDummy;
        ListNode* greaterTail = &greaterDummy;

        while (head) {
            ListNode* nxt = head->next;   // save next
            head->next = nullptr;         // detach (prevents cycles)

            if (head->val < x) {
                lessTail->next = head;
                lessTail = head;
            } else {
                greaterTail->next = head;
                greaterTail = head;
            }

            head = nxt;
        }

        // connect partitions
        lessTail->next = greaterDummy.next;
        return lessDummy.next;
    }
};
