class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // 1) find pivot
        while (i >= 0 && nums[i] >= nums[i + 1]) i--;

        if (i >= 0) {
            // 2) find rightmost element greater than pivot
            int j = n - 1;
            while (nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);
        }

        // 3) reverse suffix
        reverse(nums.begin() + i + 1, nums.end());
    }
};
