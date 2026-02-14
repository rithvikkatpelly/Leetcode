class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        Node* curr = root;  // current level pointer

        while (curr) {
            Node dummy(0);      // dummy head for next level
            Node* tail = &dummy; // tail pointer for next level

            // Traverse current level
            while (curr) {
                if (curr->left) {
                    tail->next = curr->left;
                    tail = tail->next;
                }
                if (curr->right) {
                    tail->next = curr->right;
                    tail = tail->next;
                }

                curr = curr->next; // move across level
            }

            // Move to next level
            curr = dummy.next;
        }

        return root;
    }
};
