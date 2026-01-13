#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        const long long MOD = 1000000007LL;

        long long total = 0;
        for (int x : arr) total += x;

        // Kadane allowing empty subarray => answer at least 0
        long long best = 0, cur = 0;
        for (int x : arr) {
            cur = max(0LL, cur + x);
            best = max(best, cur);
        }

        if (k == 1) return (int)(best % MOD);

        // max prefix sum (allow empty)
        long long pref = 0, prefBest = 0;
        for (int x : arr) {
            pref += x;
            prefBest = max(prefBest, pref);
        }

        // max suffix sum (allow empty)
        long long suf = 0, sufBest = 0;
        for (int i = (int)arr.size() - 1; i >= 0; --i) {
            suf += arr[i];
            sufBest = max(sufBest, suf);
        }

        long long cross = sufBest + prefBest; // across 2 copies

        long long ans;
        if (total > 0) {
            ans = max(best, cross + (long long)(k - 2) * total);
        } else {
            ans = max(best, cross);
        }

        ans %= MOD;
        return (int)ans;
    }
};
