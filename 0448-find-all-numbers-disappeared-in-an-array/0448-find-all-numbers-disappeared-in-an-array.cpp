class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();

        // Mark numbers that appear
        for (int i = 0; i < n; i++) {
            int idx = abs(nums[i]) - 1; // convert value to index
            if (nums[idx] > 0)
                nums[idx] = -nums[idx]; // mark as seen
        }

        // Collect numbers that never got marked
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)   // still positive = never visited
                result.push_back(i + 1);
        }

        return result;
    }
};
