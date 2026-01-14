class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int d = 2; d * d <= x; d++) {
            if (x % d == 0) return false;
        }
        return true;
    }

    int maximumPrimeDifference(vector<int>& nums) {
        int n = (int)nums.size();
        int first = -1, last = -1;

        for (int i = 0; i < n; i++) {
            if (isPrime(nums[i])) {
                if (first == -1) first = i;
                last = i;
            }
        }
        return last - first; // guaranteed at least one prime exists
    }
};
