class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return {};

        // column -> list of values in order
        map<int, vector<int>> col_map;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto [node, col] = q.front(); q.pop();
                col_map[col].push_back(node->val);

                if (node->left) {
                    q.push({node->left, col - 1});
                }
                if (node->right) {
                    q.push({node->right, col + 1});
                }
            }
        }

        vector<vector<int>> res;
        for (auto& [col, vals] : col_map) {
            res.push_back(vals);
        }
        return res;
    }
};
