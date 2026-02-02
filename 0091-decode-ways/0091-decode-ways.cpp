#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = (int)s.size();
        if (n == 0) return 0;

        // dp[0] = 1 (empty prefix), dp[1] depends on s[0]
        int prev2 = 1;
        int prev1 = (s[0] != '0') ? 1 : 0;

        for (int i = 2; i <= n; i++) {
            int cur = 0;

            // 1-digit decode: s[i-1] must not be '0'
            if (s[i - 1] != '0') {
                cur += prev1;
            }

            // 2-digit decode: s[i-2..i-1] must be between 10 and 26
            int two = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (two >= 10 && two <= 26) {
                cur += prev2;
            }

            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }
};
