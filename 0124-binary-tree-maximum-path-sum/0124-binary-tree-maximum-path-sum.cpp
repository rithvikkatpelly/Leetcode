#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        long long best = LLONG_MIN;
        dfs(root, best);
        return (int)best;
    }

private:
    long long dfs(TreeNode* node, long long &best) {
        if (!node) return 0;

        long long left = max(0LL, dfs(node->left, best));
        long long right = max(0LL, dfs(node->right, best));

        // Best path that uses this node as the "highest" point (can take both sides)
        best = max(best, left + right + (long long)node->val);

        // Return best gain to parent (must be a single branch)
        return (long long)node->val + max(left, right);
    }
};
