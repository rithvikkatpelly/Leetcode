class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());

        int n = nums.size();
        int mid = (n + 1) / 2; // split point

        // Reverse to place larger numbers first in each group
        int j = mid - 1;   // end of first half (smaller half)
        int k = n - 1;     // end of second half (larger half)

        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                nums[i] = sorted[j--];
            } else {
                nums[i] = sorted[k--];
            }
        }
    }
};
