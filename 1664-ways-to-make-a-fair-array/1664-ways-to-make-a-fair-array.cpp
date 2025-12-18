#include <vector>
using namespace std;

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = (int)nums.size();
        
        long long totalEven = 0, totalOdd = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) totalEven += nums[i];
            else            totalOdd  += nums[i];
        }

        long long preEven = 0, preOdd = 0;
        int count = 0;

        for (int i = 0; i < n; ++i) {
            long long evenLeft = preEven;
            long long oddLeft  = preOdd;

            // compute right side after removing nums[i]
            long long evenRight = totalOdd  - oddLeft - (i % 2 == 1 ? nums[i] : 0);
            long long oddRight  = totalEven - evenLeft - (i % 2 == 0 ? nums[i] : 0);

            if (evenLeft + evenRight == oddLeft + oddRight) {
                count++;
            }

            // now add nums[i] to prefix for the next iteration
            if (i % 2 == 0) preEven += nums[i];
            else            preOdd  += nums[i];
        }

        return count;
    }
};
