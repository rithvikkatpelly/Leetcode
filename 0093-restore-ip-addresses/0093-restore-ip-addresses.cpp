#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<string> parts;
        int n = (int)s.size();

        function<void(int)> dfs = [&](int idx) {
            // If we have 4 parts, we must have used all characters
            if ((int)parts.size() == 4) {
                if (idx == n) {
                    ans.push_back(parts[0] + "." + parts[1] + "." + parts[2] + "." + parts[3]);
                }
                return;
            }

            // Prune: remaining chars must fit remaining parts (each 1..3 chars)
            int remainingParts = 4 - (int)parts.size();
            int remainingChars = n - idx;
            if (remainingChars < remainingParts || remainingChars > 3 * remainingParts) return;

            // Try part lengths 1..3
            int val = 0;
            for (int len = 1; len <= 3 && idx + len <= n; ++len) {
                // Leading zero check
                if (len > 1 && s[idx] == '0') break;

                val = val * 10 + (s[idx + len - 1] - '0');
                if (val > 255) break;

                parts.push_back(s.substr(idx, len));
                dfs(idx + len);
                parts.pop_back();
            }
        };

        dfs(0);
        return ans;
    }
};
