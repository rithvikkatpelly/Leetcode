#include <vector>
#include <cstdlib>   // for rand
#include <ctime>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand((unsigned)time(nullptr)); // optional, for randomness

        int n = nums.size();
        int target = n - k; // index of kth largest in sorted ascending

        int left = 0, right = n - 1;
        while (true) {
            int pivotIndex = partition(nums, left, right);
            if (pivotIndex == target) {
                return nums[pivotIndex];
            } else if (pivotIndex < target) {
                left = pivotIndex + 1;
            } else {
                right = pivotIndex - 1;
            }
        }
    }

private:
    int partition(vector<int>& nums, int left, int right) {
        // Random pivot (better average performance)
        int pivotIndex = left + rand() % (right - left + 1);
        int pivotValue = nums[pivotIndex];
        swap(nums[pivotIndex], nums[right]); // move pivot to end

        int storeIndex = left;
        for (int i = left; i < right; ++i) {
            if (nums[i] < pivotValue) {      // partition by < pivot
                swap(nums[i], nums[storeIndex]);
                storeIndex++;
            }
        }
        swap(nums[storeIndex], nums[right]);  // move pivot to final place
        return storeIndex;
    }
};
