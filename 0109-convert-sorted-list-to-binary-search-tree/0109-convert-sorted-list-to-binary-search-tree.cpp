#include <bits/stdc++.h>
using namespace std;

/**
 * LeetCode provides these:
 * struct ListNode { int val; ListNode *next; ... };
 * struct TreeNode { int val; TreeNode *left; TreeNode *right; ... };
 */

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        for (auto p = head; p != nullptr; p = p->next) n++;

        cur = head;
        return build(0, n - 1);
    }

private:
    ListNode* cur = nullptr;

    TreeNode* build(int l, int r) {
        if (l > r) return nullptr;

        int mid = l + (r - l) / 2;

        // Build left subtree first (inorder)
        TreeNode* left = build(l, mid - 1);

        // Current list node becomes root
        TreeNode* root = new TreeNode(cur->val);
        root->left = left;

        // Advance list pointer
        cur = cur->next;

        // Build right subtree
        root->right = build(mid + 1, r);

        return root;
    }
};
