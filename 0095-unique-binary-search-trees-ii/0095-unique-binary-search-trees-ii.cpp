#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
 * };
 */
class Solution {
    // Key for memo: (l,r) packed into int
    unordered_map<long long, vector<TreeNode*>> memo;

    long long key(int l, int r) {
        return ((long long)l << 32) | (unsigned long long)r;
    }

    vector<TreeNode*> build(int l, int r) {
        long long k = key(l, r);
        if (memo.count(k)) return memo[k];

        vector<TreeNode*> res;

        if (l > r) {
            res.push_back(nullptr); // empty tree
            return memo[k] = res;
        }

        for (int root = l; root <= r; root++) {
            vector<TreeNode*> leftTrees = build(l, root - 1);
            vector<TreeNode*> rightTrees = build(root + 1, r);

            for (TreeNode* L : leftTrees) {
                for (TreeNode* R : rightTrees) {
                    TreeNode* node = new TreeNode(root);
                    node->left = L;
                    node->right = R;
                    res.push_back(node);
                }
            }
        }

        return memo[k] = res;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        memo.clear();
        return build(1, n);
    }
};
