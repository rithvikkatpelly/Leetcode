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

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        // Map from value to its index in inorder
        unordered_map<int, int> inIndex;
        for (int i = 0; i < n; ++i) {
            inIndex[inorder[i]] = i;
        }

        int postIdx = n - 1; // start from the last element in postorder
        return build(inorder, postorder, inIndex, 0, n - 1, postIdx);
    }

private:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    unordered_map<int,int>& inIndex,
                    int inLeft, int inRight, int& postIdx) {
        if (inLeft > inRight) return nullptr;

        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);

        int idx = inIndex[rootVal]; // position in inorder

        // Important: build right subtree first (because of postorder's order)
        root->right = build(inorder, postorder, inIndex, idx + 1, inRight, postIdx);
        root->left  = build(inorder, postorder, inIndex, inLeft, idx - 1, postIdx);

        return root;
    }
};
