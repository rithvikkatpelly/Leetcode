class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int S = 0;
        for (int x : nums) S += x;

        // impossible cases
        if (abs(target) > S) return 0;
        if ((S + target) % 2 != 0) return 0;

        int P = (S + target) / 2;

        // dp[s] = number of ways to get sum s
        vector<long long> dp(P + 1, 0);
        dp[0] = 1;

        for (int x : nums) {
            // go backwards for 0/1 knapsack
            for (int s = P; s >= x; s--) {
                dp[s] += dp[s - x];
            }
        }

        return (int)dp[P];
    }
};
