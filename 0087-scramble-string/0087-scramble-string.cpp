#include <string>
#include <unordered_map>
#include <array>
using namespace std;

class Solution {
    unordered_map<long long, bool> memo; // key = (i1, i2, len) packed

    static long long key(int i1, int i2, int len) {
        // pack into 64-bit (fits since indices <= 29, len <= 30)
        return ((long long)i1 << 40) | ((long long)i2 << 20) | (long long)len;
    }

    bool sameCounts(const string& s1, int i1, const string& s2, int i2, int len) {
        array<int, 26> cnt{};
        for (int k = 0; k < len; k++) {
            cnt[s1[i1 + k] - 'a']++;
            cnt[s2[i2 + k] - 'a']--;
        }
        for (int v : cnt) if (v != 0) return false;
        return true;
    }

    bool dfs(const string& s1, int i1, const string& s2, int i2, int len) {
        long long k = key(i1, i2, len);
        auto it = memo.find(k);
        if (it != memo.end()) return it->second;

        // Exact match
        bool identical = true;
        for (int t = 0; t < len; t++) {
            if (s1[i1 + t] != s2[i2 + t]) { identical = false; break; }
        }
        if (identical) return memo[k] = true;

        // Prune by character multiset
        if (!sameCounts(s1, i1, s2, i2, len)) return memo[k] = false;

        // Try splits
        for (int split = 1; split < len; split++) {
            // no swap
            if (dfs(s1, i1, s2, i2, split) &&
                dfs(s1, i1 + split, s2, i2 + split, len - split)) {
                return memo[k] = true;
            }
            // swap
            if (dfs(s1, i1, s2, i2 + (len - split), split) &&
                dfs(s1, i1 + split, s2, i2, len - split)) {
                return memo[k] = true;
            }
        }

        return memo[k] = false;
    }

public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        memo.clear();
        return dfs(s1, 0, s2, 0, (int)s1.size());
    }
};
