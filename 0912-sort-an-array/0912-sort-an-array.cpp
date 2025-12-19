#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }

private:
    void heapSort(vector<int>& nums) {
        int n = nums.size();

        // Build max heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(nums, n, i);
        }

        // Extract elements from heap
        for (int i = n - 1; i > 0; i--) {
            swap(nums[0], nums[i]);        // Move current max to end
            heapify(nums, i, 0);           // Restore heap on reduced range
        }
    }

    void heapify(vector<int>& nums, int heapSize, int root) {
        int largest = root;
        int left = root * 2 + 1;
        int right = root * 2 + 2;

        if (left < heapSize && nums[left] > nums[largest])
            largest = left;

        if (right < heapSize && nums[right] > nums[largest])
            largest = right;

        if (largest != root) {
            swap(nums[root], nums[largest]);
            heapify(nums, heapSize, largest);
        }
    }
};
