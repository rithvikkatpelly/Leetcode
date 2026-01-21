class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        
        int left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (left == n || nums[left] != target) return {-1, -1};
        
        int right = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        return {left, right};
    }
};
