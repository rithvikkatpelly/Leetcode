class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // Base case: empty or single node
        if (!head || !head->next) {
            return head;
        }
        
        // 1. Split the list into two halves
        ListNode* mid = getMiddle(head);
        ListNode* right = mid->next;
        mid->next = nullptr;

        // 2. Recursively sort each half
        ListNode* leftSorted = sortList(head);
        ListNode* rightSorted = sortList(right);

        // 3. Merge the sorted halves
        return merge(leftSorted, rightSorted);
    }

private:
    // Function to find the middle of the list
    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next; // Important: fast starts at head->next to split correctly

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Function to merge two sorted lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        // Append remaining nodes
        tail->next = l1 ? l1 : l2;

        return dummy.next;
    }
};
