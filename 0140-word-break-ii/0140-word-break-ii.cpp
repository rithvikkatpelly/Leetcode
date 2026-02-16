#include <bits/stdc++.h>
using namespace std;

/**
 * Definition not needed for this problem; returns all sentences.
 */
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = (int)s.size();

        // Prune with word length bounds
        int minLen = INT_MAX, maxLen = 0;
        for (auto &w : wordDict) {
            minLen = min(minLen, (int)w.size());
            maxLen = max(maxLen, (int)w.size());
        }

        // canBreak[i] = can s[i:] be segmented at all?
        vector<char> canBreak(n + 1, false);
        canBreak[n] = true;
        for (int i = n - 1; i >= 0; --i) {
            for (int len = minLen; len <= maxLen && i + len <= n; ++len) {
                if (!canBreak[i + len]) continue;
                if (dict.count(s.substr(i, len))) {
                    canBreak[i] = true;
                    break;
                }
            }
        }
        if (!canBreak[0]) return {};

        unordered_map<int, vector<string>> memo;

        function<vector<string>(int)> dfs = [&](int i) -> vector<string> {
            if (memo.count(i)) return memo[i];
            vector<string> res;

            if (i == n) {
                res.push_back(""); // empty sentence tail
                return memo[i] = res;
            }

            // If suffix can't be broken, return empty early
            if (!canBreak[i]) return memo[i] = {};

            for (int len = minLen; len <= maxLen && i + len <= n; ++len) {
                if (!canBreak[i + len]) continue;

                string w = s.substr(i, len);
                if (!dict.count(w)) continue;

                vector<string> tails = dfs(i + len);
                for (const string& t : tails) {
                    if (t.empty()) res.push_back(w);
                    else res.push_back(w + " " + t);
                }
            }
            return memo[i] = res;
        };

        return dfs(0);
    }
};
