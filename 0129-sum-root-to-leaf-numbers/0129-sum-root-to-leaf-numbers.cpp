class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* node, int cur) {
        if (!node) return 0;

        cur = cur * 10 + node->val;

        // leaf
        if (!node->left && !node->right) return cur;

        return dfs(node->left, cur) + dfs(node->right, cur);
    }
};
