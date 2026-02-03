#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        if (n > m) return 0;

        vector<long long> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = n; j >= 1; j--) {
                if (s[i] == t[j - 1]) {
                    dp[j] += dp[j - 1];

                    // cap to prevent signed overflow
                    if (dp[j] > INT_MAX) {
                        dp[j] = INT_MAX;
                    }
                }
            }
        }
        return (int)dp[n];
    }
};

