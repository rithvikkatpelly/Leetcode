class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact(n + 1, 1);
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;

        vector<int> nums;
        for (int i = 1; i <= n; i++) nums.push_back(i);

        k--; // make k 0-indexed
        string ans;

        for (int i = n; i >= 1; i--) {
            int block = fact[i - 1];
            int idx = k / block;
            k %= block;

            ans += char('0' + nums[idx]);
            nums.erase(nums.begin() + idx);
        }

        return ans;
    }
};
