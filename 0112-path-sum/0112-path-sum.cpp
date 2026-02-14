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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        // If it's a leaf, check if the remaining sum matches this node's value
        if (!root->left && !root->right) {
            return root->val == targetSum;
        }

        int remaining = targetSum - root->val;
        return hasPathSum(root->left, remaining) || hasPathSum(root->right, remaining);
    }
};
