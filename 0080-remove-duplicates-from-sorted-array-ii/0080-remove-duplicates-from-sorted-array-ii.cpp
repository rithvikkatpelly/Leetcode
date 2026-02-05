class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;  // write index

        for (int i = 0; i < nums.size(); i++) {
            // Allow first two elements freely,
            // afterward allow nums[i] only if it differs from nums[k-2]
            if (k < 2 || nums[i] != nums[k - 2]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};
