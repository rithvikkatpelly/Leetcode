/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        Node* levelStart = root;

        // While there is another level below
        while (levelStart->left) {
            Node* cur = levelStart;

            while (cur) {
                // Connect left -> right
                cur->left->next = cur->right;

                // Connect right -> next node's left (if exists)
                if (cur->next) {
                    cur->right->next = cur->next->left;
                } else {
                    cur->right->next = nullptr;
                }

                cur = cur->next; // move across current level
            }

            levelStart = levelStart->left; // move down to next level
        }

        return root;
    }
};
