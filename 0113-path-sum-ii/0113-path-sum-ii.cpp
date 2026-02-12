#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(root, (long long)targetSum, path, ans);
        return ans;
    }

private:
    void dfs(TreeNode* node, long long rem,
             vector<int>& path, vector<vector<int>>& ans) {
        if (!node) return;

        path.push_back(node->val);
        rem -= node->val;

        // leaf
        if (!node->left && !node->right) {
            if (rem == 0) ans.push_back(path);
        } else {
            dfs(node->left, rem, path, ans);
            dfs(node->right, rem, path, ans);
        }

        path.pop_back();
    }
};
