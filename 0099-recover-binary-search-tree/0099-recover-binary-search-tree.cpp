/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        first = second = prev = nullptr;
        inorder(root);
        if (first && second) std::swap(first->val, second->val);
    }

private:
    TreeNode *first, *second, *prev;

    void inorder(TreeNode* node) {
        if (!node) return;

        inorder(node->left);

        // Detect inversion: prev->val > node->val
        if (prev && prev->val > node->val) {
            if (!first) first = prev;   // first time: mark prev
            second = node;              // always update second to current
        }
        prev = node;

        inorder(node->right);
    }
};
