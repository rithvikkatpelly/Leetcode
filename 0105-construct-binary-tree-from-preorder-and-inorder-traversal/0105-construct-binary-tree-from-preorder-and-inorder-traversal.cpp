#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = (int)preorder.size();
        unordered_map<int,int> pos;
        pos.reserve(n * 2);
        for (int i = 0; i < n; i++) pos[inorder[i]] = i;

        int preIdx = 0;
        return build(preorder, 0, n - 1, preIdx, pos);
    }

private:
    TreeNode* build(const vector<int>& preorder, int inL, int inR,
                    int& preIdx, unordered_map<int,int>& pos) {
        if (inL > inR) return nullptr;

        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);

        int mid = pos[rootVal];              // root position in inorder
        root->left  = build(preorder, inL, mid - 1, preIdx, pos);
        root->right = build(preorder, mid + 1, inR, preIdx, pos);

        return root;
    }
};
