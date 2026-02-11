#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> levels;
        if (!root) return levels;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = (int)q.size();
            vector<int> level;
            level.reserve(sz);

            for (int i = 0; i < sz; i++) {
                TreeNode* cur = q.front(); q.pop();
                level.push_back(cur->val);

                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            levels.push_back(std::move(level));
        }

        reverse(levels.begin(), levels.end());
        return levels;
    }
};

