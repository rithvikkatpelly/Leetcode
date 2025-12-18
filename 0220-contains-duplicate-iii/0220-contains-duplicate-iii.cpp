class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long> window;  // use long long to avoid overflow
        for (int i = 0; i < nums.size(); ++i) {
            // Find the smallest number >= nums[i] - valueDiff
            auto it = window.lower_bound((long long)nums[i] - valueDiff);
            // Check if it's within valueDiff
            if (it != window.end() && *it <= (long long)nums[i] + valueDiff) {
                return true;
            }
            window.insert(nums[i]);
            // Keep window size <= indexDiff
            if (i >= indexDiff) {
                window.erase(nums[i - indexDiff]);
            }
        }
        return false;
    }
};

