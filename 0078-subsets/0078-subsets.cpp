#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> curr;

    void backtrack(int index, vector<int>& nums) {
        // Add the current subset
        res.push_back(curr);

        for (int i = index; i < nums.size(); i++) {
            curr.push_back(nums[i]);      // choose
            backtrack(i + 1, nums);       // explore
            curr.pop_back();              // unchoose
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(0, nums);
        return res;
    }
};
