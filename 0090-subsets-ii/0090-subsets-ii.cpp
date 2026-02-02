#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path;

        function<void(int)> dfs = [&](int start) {
            res.push_back(path);

            for (int i = start; i < (int)nums.size(); i++) {
                // skip duplicates at the same recursion level
                if (i > start && nums[i] == nums[i - 1]) continue;

                path.push_back(nums[i]);
                dfs(i + 1);
                path.pop_back();
            }
        };

        dfs(0);
        return res;
    }
};

