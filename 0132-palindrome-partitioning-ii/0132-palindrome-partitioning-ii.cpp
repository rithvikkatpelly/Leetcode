#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = (int)s.size();
        vector<vector<char>> pal(n, vector<char>(n, 0));

        // pal[i][j] for all i<=j
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j] && (j - i <= 2 || pal[i + 1][j - 1])) {
                    pal[i][j] = 1;
                }
            }
        }

        vector<int> dp(n, INT_MAX);

        for (int i = 0; i < n; ++i) {
            if (pal[0][i]) {
                dp[i] = 0;
            } else {
                for (int j = 1; j <= i; ++j) {
                    if (pal[j][i]) {
                        dp[i] = min(dp[i], dp[j - 1] + 1);
                    }
                }
            }
        }
        return dp[n - 1];
    }
};
