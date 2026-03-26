class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;

        reverse(nums.begin(), nums.end());           // step 1
        reverse(nums.begin(), nums.begin() + k);     // step 2
        reverse(nums.begin() + k, nums.end());       // step 3
    }
};