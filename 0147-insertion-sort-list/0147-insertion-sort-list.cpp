class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        // Dummy node to simplify insertion at head
        ListNode* dummy = new ListNode(0);
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* prev = dummy;
            // Find where to insert curr
            while (prev->next != nullptr && prev->next->val < curr->val) {
                prev = prev->next;
            }
            // Save next node to process
            ListNode* nextTemp = curr->next;

            // Insert curr between prev and prev->next
            curr->next = prev->next;
            prev->next = curr;

            // Move to next node
            curr = nextTemp;
        }

        return dummy->next;
    }
};
