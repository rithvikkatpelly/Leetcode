#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        // collect distinct word lengths to reduce checks
        unordered_set<int> lensSet;
        int maxLen = 0;
        for (auto &w : wordDict) {
            lensSet.insert((int)w.size());
            maxLen = max(maxLen, (int)w.size());
        }
        vector<int> lens(lensSet.begin(), lensSet.end());

        int n = (int)s.size();
        vector<char> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int L : lens) {
                if (i - L < 0) continue;
                if (!dp[i - L]) continue;
                if (dict.count(s.substr(i - L, L))) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n];
    }
};
