class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;

        function<void(int,int)> dfs = [&](int start, int remain) {
            if (remain == 0) {
                res.push_back(path);
                return;
            }

            for (int i = start; i < (int)candidates.size(); i++) {
                if (i > start && candidates[i] == candidates[i - 1]) continue; // skip duplicates
                int x = candidates[i];
                if (x > remain) break;

                path.push_back(x);
                dfs(i + 1, remain - x); // i+1 because each number used once
                path.pop_back();
            }
        };

        dfs(0, target);
        return res;
    }
};
